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

void radixSort() {

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
            Lista = new ArrayList<int>(sizeLista);
            srand(time(0)); 
            for (int i = 0; i < sizeLista ; i++) {
                int numeroRandom = rand() % 10000;
                Lista->append(numeroRandom);
            }
            cout << "Lista Random desordenada: ";
            Lista->print();
        }
    }
    catch (const runtime_error& e) {
        cout << "ERROR: " << e.what() << endl;
    }

}
