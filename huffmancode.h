#ifndef HUFFMANCODE_H
#define HUFFMANCODE_H

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

#include <QString>

using namespace std;


struct Node{
    char simbolo;
    int frecuencia;
    Node *izq, *der;

};

class HuffmanCode
{
public:

    HuffmanCode();
    string coded;
    string decoded;
    Node *root;
    int indice;
    int tamano;
    void principal();
    Node *getNode(char simbolo, int frecuencia, Node *izq, Node *der){
        Node *nodo = new Node();

        nodo->simbolo = simbolo;
        nodo->frecuencia = frecuencia;
        nodo->der = der;
        nodo->izq = izq;

        return nodo;
    }

    //objeto de comparacion para ordenar la pila
    struct comp{
        bool operator()(Node *i, Node *d){
            return i->frecuencia > d->frecuencia;
        }
    };

    //revisa el arbol huffman y guarda los códigos
    void encode(Node *raiz, string str, unordered_map<char, string> &CodigoHuffman){
        if(raiz == nullptr)
            return;
        if(!raiz->izq && !raiz->der){
            CodigoHuffman[raiz->simbolo] = str;
        }
        encode(raiz->izq, str + "0", CodigoHuffman);
        encode(raiz->der, str + "1", CodigoHuffman);
    }

    //revisa el codigo y decodifica
    void decode(Node *raiz, int &index, string str){
        if(raiz == nullptr){
            return;
        }
        if(!raiz->izq && !raiz->der){
            decoded+=(raiz->simbolo);
            return;
        }
        index ++;
        if(str[index] == '0')
            decode(raiz->izq, index, str);
        else
            decode(raiz->der, index, str);
    }

    //crea el arbol huffmany decodifica
    void crearArbol(string text){
        //cuenta la frecuencia
        unordered_map<char, int> frecuencia;
        for(char simbolo: text){
            frecuencia[simbolo]++;
        }
        //crea una cola de prioridad para guardar los nodos del arbol
        priority_queue<Node *, vector<Node *>, comp> pq;
        //Agrega a la cola los nodos de cada simbolo
        for(auto pair: frecuencia){
            pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
        }
        //Hace todo el proceso hasta que haya mas de 1 nodo en la cola
        while(pq.size() != 1){
            Node *izq = pq.top(); pq.pop();
            Node *der = pq.top(); pq.pop();
            int sum = izq->frecuencia + der->frecuencia;
            pq.push(getNode('\0', sum, izq, der));
        }
        Node *raiz = pq.top();
        //imprime los codigos de cada simbolo
        unordered_map<char, string> CodigoHuffman;
        encode(raiz, "", CodigoHuffman);
        cout << "\nLos códigos de Huffman son:\n" << '\n';
        for(auto pair: CodigoHuffman){
            cout << pair.first << " " << pair.second << '\n';
        }
        //Imprime el mensaje original, el codificado y el decodificado
        cout << "\nEL mensaje original es:\n" << text << '\n';
        string str = "";
        for(char simbolo: text){
            str += CodigoHuffman[simbolo];
        }
        coded = str;
        cout << "\nEl texto codificado es:\n" << str << '\n';
        int index = -1;
        cout << "\nEl texto decodificado es:\n";
        root = raiz;
        indice = index;
        tamano = (int)str.size();
        while(index < (int)str.size() - 2){
            decode(raiz, index, str);
        }
        cout << "\n\n\n";
    }
    string getCoded(string text){
        crearArbol(text);
        return coded;
    }
    string getDecoded(Node *root, int i, int size, string mensaje){
        while (i < size-2){
            decode(root, i, mensaje);
        }
        return decoded;
    }
};

#endif // HUFFMANCODE_H
