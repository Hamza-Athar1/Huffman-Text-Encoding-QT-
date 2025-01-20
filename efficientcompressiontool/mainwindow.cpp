#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0); // Initialize progress bar
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::readFileContents(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Failed to open file: " + file.errorString());
        return QString();
    }

    QTextStream in(&file);
    QString contents = in.readAll();
    file.close();
    return contents;
}

bool MainWindow::writeFileContents(const QString &filePath, const QByteArray &data) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Error", "Failed to save file: " + file.errorString());
        return false;
    }
    file.write(data);
    file.close();
    return true;
}

HuffmanNode* MainWindow::buildHuffmanTree(const QMap<QChar, int> &frequencies) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNodes> pq;

    for (auto it = frequencies.begin(); it != frequencies.end(); ++it) {
        pq.push(new HuffmanNode(it.key(), it.value()));
    }

    while (pq.size() > 1) {
        HuffmanNode *left = pq.top(); pq.pop();
        HuffmanNode *right = pq.top(); pq.pop();
        HuffmanNode *merged = new HuffmanNode(QChar(), left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    return pq.top();
}

void MainWindow::generateHuffmanCodes(HuffmanNode *node, const QString &code, QMap<QChar, QString> &huffmanCodes) {
    if (!node) return;

    if (!node->left && !node->right) { // Leaf node
        huffmanCodes[node->character] = code;
    }

    generateHuffmanCodes(node->left, code + "0", huffmanCodes);
    generateHuffmanCodes(node->right, code + "1", huffmanCodes);
}

void MainWindow::freeHuffmanTree(HuffmanNode *node) {
    if (!node) return;
    freeHuffmanTree(node->left);
    freeHuffmanTree(node->right);
    delete node;
}

QByteArray MainWindow::huffmanCompress(const QString &text, QMap<QChar, QString> &huffmanCodes, QProgressBar *progressBar) {
    QMap<QChar, int> frequencies;
    for (QChar ch : text) {
        frequencies[ch]++;
    }

    HuffmanNode *root = buildHuffmanTree(frequencies);

    generateHuffmanCodes(root, "", huffmanCodes);

    QByteArray compressedData;
    QString encodedString;
    for (QChar ch : text) {
        encodedString += huffmanCodes[ch];
    }

    while (encodedString.size() % 8 != 0) {
        encodedString += '0'; // Padding to make it byte-aligned
    }

    for (int i = 0; i < encodedString.size(); i += 8) {
        QString byteStr = encodedString.mid(i, 8);
        char byte = static_cast<char>(byteStr.toUInt(nullptr, 2));
        compressedData.append(byte);
        progressBar->setValue((i + 8) * 100 / encodedString.size());
        QCoreApplication::processEvents();
    }

    QByteArray serializedTree;
    for (auto it = huffmanCodes.begin(); it != huffmanCodes.end(); ++it) {
        serializedTree.append(it.key().toLatin1()); // Convert QChar to QByteArray
        serializedTree.append(':');
        serializedTree.append(it.value().toUtf8()); // Convert QString to QByteArray
        serializedTree.append(';');
    }

    compressedData.prepend(serializedTree);
    freeHuffmanTree(root);
    return compressedData;
}


QString MainWindow::huffmanDecompress(const QByteArray &data, QProgressBar *progressBar) {
    QMap<QChar, QString> huffmanCodes;
    QString serializedTree = QString::fromUtf8(data.left(data.indexOf('\0')));
    QByteArray compressedData = data.mid(data.indexOf('\0') + 1);

    for (const QString &entry : serializedTree.split(";")) {
        if (entry.isEmpty()) continue;
        QChar ch = entry[0];
        QString code = entry.mid(2);
        huffmanCodes[ch] = code;
    }

    QString encodedString;
    for (unsigned char byte : compressedData) {
        encodedString += QString::number(byte, 2).rightJustified(8, '0');
    }

    QString decodedString;
    QString currentCode;
    for (QChar ch : encodedString) {
        currentCode += ch;
        for (auto it = huffmanCodes.begin(); it != huffmanCodes.end(); ++it) {
            if (currentCode == it.value()) {
                decodedString += it.key();
                currentCode.clear();
                break;
            }
        }
    }

    return decodedString;
}

void MainWindow::on_browseButton_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "Select a File", "", "Text Files (*.txt);;All Files (*)");
    if (filePath.isEmpty()) return;

    QString contents = readFileContents(filePath);
    if (!contents.isEmpty()) {
        ui->textBrowser->setPlainText(contents);
    }
}

void MainWindow::on_compressButton_clicked() {
    QString text = ui->textBrowser->toPlainText();
    if (text.isEmpty()) {
        QMessageBox::warning(this, "Error", "No text to compress.");
        return;
    }

    // Get the original size
    qint64 originalSize = text.toUtf8().size();

    QMap<QChar, QString> huffmanCodes;
    QByteArray compressedData = huffmanCompress(text, huffmanCodes, ui->progressBar);

    // Get the compressed size
    qint64 compressedSize = compressedData.size();

    // Calculate the compression ratio
    double compressionRatio = (double)originalSize / compressedSize;

    // Display the compression ratio
    QString ratioText = QString("Compression Ratio: %1").arg(compressionRatio, 0, 'f', 2);
    ui->compressionRatioLabel->setText(ratioText);  // Assuming you have a QLabel named compressionRatioLabel

    QString savePath = QFileDialog::getSaveFileName(this, "Save Compressed File", "", "Binary Files (*.bin)");
    if (savePath.isEmpty()) return;

    if (writeFileContents(savePath, compressedData)) {
        QMessageBox::information(this, "Success", "File compressed successfully.");
    }
}

void MainWindow::on_decompressButton_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "Select a File", "", "Binary Files (*.bin);;All Files (*)");
    if (filePath.isEmpty()) return;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Failed to open file.");
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QString decompressedText = huffmanDecompress(data, ui->progressBar);

    QString savePath = QFileDialog::getSaveFileName(this, "Save Decompressed File", "", "Text Files (*.txt)");
    if (savePath.isEmpty()) return;

    if (writeFileContents(savePath, decompressedText.toUtf8())) {
        QMessageBox::information(this, "Success", "File decompressed successfully.");
    }
}

