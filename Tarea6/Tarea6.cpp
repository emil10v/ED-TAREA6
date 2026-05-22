#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib> 
#include <ctime> 
#include "ArrayList.h"
#include "LinkedList.h"
#include <chrono>

using namespace std::chrono;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::runtime_error;
using std::getline;
using std::ws;

int getCantDigitos(List<int>* lista, int base) {
    int mayor = -1;
    for (lista->goToStart(); !lista->atEnd(); lista->next()) {
        int num = lista->getElement();
        if (num > mayor)
            mayor = num;
    }
    int digits = 0;
    while (mayor) {
        mayor /= base;
        digits++;
    }
    return digits;
}


void radixSort(List<int>* lista, int base, int sizeLista) {
    ArrayList<LinkedList<int>*>* buckets = new ArrayList<LinkedList<int>*>(base);
    int digitos = getCantDigitos(lista, base);
    for (int i = 0; i < base; i++) {
        buckets->append(new LinkedList<int>()); 
    }
    int divisor = 1;
    for (int i = 0; i < digitos; i++) {
        for (lista->goToStart(); !lista->atEnd(); lista->next()) {
            int numero = lista->getElement();
            int digito = (numero / divisor) % base;
            buckets->goToPos(digito);
            List<int>* bucket = buckets->getElement();
            bucket->append(numero);
        }
		lista->clear();
        buckets->goToStart();
        for (buckets->goToStart(); !buckets->atEnd(); buckets->next()) {
            LinkedList<int>* bucket = buckets->getElement();
            bucket->goToStart();
            int sizeBucket = bucket->getSize();
            for (int i = 0; i < sizeBucket; i++) {
                int numero = bucket->remove();
                lista->append(numero);
            }
        }
        divisor *= base;
    }
    buckets->goToStart();
    for (int i = 0; i < base; i++) {
        LinkedList<int>* bucket = buckets->getElement();
        delete bucket;
        buckets->next();
    }
    delete buckets;
}


int main() {
    ArrayList<int>* Lista;
    int base;
    int sizeLista;
    string temp;
    string repetir = "s";
    try {
        while (repetir == "s" || repetir == "S") {
            cout << "Tamano de la nueva lista: ";
            getline(cin >> ws, temp);
            sizeLista = stoi(temp);
            if (sizeLista < 1)
                throw runtime_error("Tamano debe ser mayor o igual 1.");
            cout << "Base numerica: ";
            getline(cin >> ws, temp);
            base = stoi(temp);
            if (base < 2)
                throw runtime_error("La base debe ser mayor o igual a 2.");
            Lista = new ArrayList<int>(sizeLista);
            srand(time(0)); 
            for (int i = 0; i < sizeLista ; i++) {
                int numeroRandom = rand() % 100000;
                Lista->append(numeroRandom);
            }
            cout << "Lista Random desordenada: ";
            Lista->print();
            auto inicio = high_resolution_clock::now();
            radixSort(Lista, base, sizeLista);
            auto fin = high_resolution_clock::now();
            auto duracion = duration_cast<milliseconds>(fin - inicio);
            cout << "\nLista ordenada: \\n";
            Lista->print();
            cout << "Tiempo: " << duracion.count() << " ms\n";
            delete Lista;
            cout << "\nDesea repetir? (s/n) ";
            getline(cin >> ws, repetir);
        }
    }
    catch (const runtime_error& e) {
        cout << "ERROR: " << e.what() << endl;
    }
    cout << "Gracias por usar el programa :)" << endl;
    return 0;
}
