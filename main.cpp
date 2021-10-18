#include "mainwindow.h"

#include <QApplication>

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

#include "huffmancode.h"
HuffmanCode *code = nullptr;

using namespace std;

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
