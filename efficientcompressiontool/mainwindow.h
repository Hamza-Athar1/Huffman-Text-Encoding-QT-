#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QProgressBar>
#include <QString>
#include <QMap>
#include <QByteArray>
#include <queue>
#include <vector>

struct HuffmanNode {
    QChar character;
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(QChar ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}
};

// Custom comparator for priority queue
struct CompareNodes {
    bool operator()(HuffmanNode *a, HuffmanNode *b) {
        return a->frequency > b->frequency;
    }
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_browseButton_clicked();
    void on_compressButton_clicked();
    void on_decompressButton_clicked();

private:
    Ui::MainWindow *ui;

    QString readFileContents(const QString &filePath);
    bool writeFileContents(const QString &filePath, const QByteArray &data);

    QByteArray huffmanCompress(const QString &text, QMap<QChar, QString> &huffmanCodes, QProgressBar *progressBar);
    QString huffmanDecompress(const QByteArray &data, QProgressBar *progressBar);

    HuffmanNode* buildHuffmanTree(const QMap<QChar, int> &frequencies);
    void generateHuffmanCodes(HuffmanNode *node, const QString &code, QMap<QChar, QString> &huffmanCodes);
    void freeHuffmanTree(HuffmanNode *node);
};

#endif // MAINWINDOW_H
