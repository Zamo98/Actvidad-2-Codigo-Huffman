#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "huffmancode.h"
#include <QString>

HuffmanCode coder;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Código Huffman");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Comprimir_clicked()
{
    QString qtexto;
    qtexto = ui->entrada->toPlainText();
    std::string text = qtexto.toUtf8().constData();

    std::string codedText = coder.getCoded(text);

    qtexto = QString::fromStdString(codedText);
    ui->salida->setPlainText("Mensaje comprimido: "+qtexto);
}
