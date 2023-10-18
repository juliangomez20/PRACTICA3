#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;
string lectura();



int main() {
    string inputFileName = "input.txt"; // Cambia esto al nombre de tu archivo de entrada
    string outputFileName = "output.txt"; // Cambia esto al nombre del archivo de salida

    ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Error al abrir el archivo de entrada: " << inputFileName << std::endl;
        return 1;
    }

    std::ofstream outputFile(outputFileName, std::ios::binary);
    if (!outputFile) {
        std::cerr << "Error al abrir el archivo de salida: " << outputFileName << std::endl;
        return 1;
    }

    char c;
    while (inputFile.get(c)) {
        std::bitset<8> binaryChar(c);
        outputFile << binaryChar.to_string();
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Texto convertido a binario y guardado en " << outputFileName << std::endl;
    int semilla = 0;
    cout<<"Ingrese el valor de la semilla de codificacion: "<<endl;
    cin>>semilla;

string texto2 = lectura();



   cout << "Ingrese el valor de la semilla de codificación: " << endl;
   cin >> semilla;


   int blockSize = semilla;  // Tamaño de cada bloque

   int numBlocks = texto2.size() / blockSize;

   vector<string> bloques;

   for (int i = 0; i < numBlocks; i++) {
       string bloque = texto2.substr(i * blockSize, blockSize);
       bloques.push_back(bloque);
   }

   // Ahora, en el vector "bloques" tienes todos los bloques de tamaño "semilla"
   // Puedes realizar operaciones en cada bloque según tus necesidades.

   for (const string& bloque : bloques) {
       cout << "Bloque: " << bloque << endl;
   }
   for(int i=0;i<texto2.size()/numBlocks;i++){
   cout<<"Bloque # "<<i<<bloques[i]<<endl;
   }

    return 0;
}

string lectura(){
    string texto;
    ifstream archivo;
    archivo.open("output.txt",ios::in);//se abre en modo lectura
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    while(!archivo.eof()){//Mientras no sea el final del archivo
        getline(archivo,texto);
        cout<<texto<<endl;

    }
   archivo.close();//Cerrar el archivo
   return texto;
}
