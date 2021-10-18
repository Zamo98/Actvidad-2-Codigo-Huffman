#include "huffmancode.h"

#include "mainwindow.h"
#include <QString>

//MainWindow *w = nullptr;
HuffmanCode::HuffmanCode(){}

void HuffmanCode::principal(){
    //w = new MainWindow();
    //string txt = w->texto;
   // crearArbol(w->texto);
    cout << "\n\n\n------------------------------------------";
    cout << "\n    Compresión y decompresión de Huffman";
    cout << "\n----------------------------------------------";
    string text;
    cout << "\nIngrese el texto que desea comprimir: ";
    getline(cin, text);
    crearArbol(text);
    cout << "\n";
}
