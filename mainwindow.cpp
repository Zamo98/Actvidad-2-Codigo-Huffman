#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "huffmancode.h"
#include <QString>

//QString texto;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Código Huffman");
    //texto = ui->entrada->toPlainText();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Comprimir_clicked()
{
    texto = ui->entrada->toPlainText();
    //code->crearArbol()
    ui->salida->setPlainText("Mensaje comprimido: "+texto);
}
