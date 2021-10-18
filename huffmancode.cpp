#include "huffmancode.h"

#include "mainwindow.h"

HuffmanCode::HuffmanCode(){}

void HuffmanCode::principal(){

    cout << "\n\n\n------------------------------------------";
    cout << "\n    Compresión y decompresión de Huffman";
    cout << "\n----------------------------------------------";
    string text;
    cout << "\nIngrese el texto que desea comprimir: ";
    getline(cin, text);
    crearArbol(text);
    cout << "\n";
}
