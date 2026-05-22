#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib> 
#include <ctime> 
#include "ArrayList.h"
#include "LinkedList.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::runtime_error;
using std::getline;
using std::ws;

void radixSort(ArrayList<int>* lista, int base) {
    ArrayList<LinkedList<int>*>* buckets;
    int digitos = getCantDigitos(lista, base);
    for (int i = 0; i < base i++) {
        buckets->append(new LinkedList<int>()); 
    }
    for (int i = 0; i < digitos; i++) {
        for (lista->goToStart(); !lista->atEnd(); lista->next()) {
            int numero = lista->getElement();
            int digito = numero % base;
            buckets[digito].append(numero);
        }
    }
    for (int i = 0; i < base; i++) delete buckets->getAt(i);
    delete buckets;
}

int getCantDigitos(ArrayList<int>* lista, int base) {
    int res = 0;
    for (lista->goToStart(); !lista->atEnd(); lista->next()) {
        int num = lista->getElement();
        if (num > res)
            res = num;
    }
    int digits = 1;
    while (res) {
        res /= base;
        digits++;
    }
    return digits;
}

int main() {
    ArrayList<int>* Lista;
    int base;
    int sizeLista;
    string temp;
    string repetir = "s";
    try {
        while (repetir == "s" || repetir == "S") {
            cout << "Tamano de la lista: ";
            getline(cin, temp);
            sizeLista = stoi(temp);
            cout << "Base numerica: ";
            getline(cin, temp);
            base = stoi(temp);
            Lista = new ArrayList<int>(sizeLista);
            srand(time(0)); 
            for (int i = 0; i < sizeLista ; i++) {
                int numeroRandom = rand() % 10000;
                Lista->append(numeroRandom);
            }
            cout << "Lista Random desordenada: ";
            Lista->print();
            radixSort(Lista, base);
        }
    }
    catch (const runtime_error& e) {
        cout << "ERROR: " << e.what() << endl;
    }

}
