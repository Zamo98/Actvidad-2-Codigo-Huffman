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



void MainWindow::on_pushButton_2_clicked()
{
    QString qtexto;
    qtexto = ui->entrada->toPlainText();
    std::string text = qtexto.toUtf8().constData();

    std::string decodedText = coder.getDecoded(coder.root, coder.indice, coder.tamano, coder.coded);

    qtexto = QString::fromStdString(decodedText);
    ui->salida->setPlainText("Mensaje descomprimido: "+qtexto);
}

