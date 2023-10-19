#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;
string lectura();



int main() {
    string inputFileName = "input.txt"; // Archivo de entrada
    string outputFileName = "output.txt"; // Archivo de salida

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

    cout << "Texto convertido a binario y guardado en " << outputFileName << std::endl;


    string texto2 = lectura();


   int semilla ;
   cout << "Ingrese el valor de la semilla de codificación: " << endl;
   cin >> semilla;


   int blockSize = semilla;  // Se asigna el tamaño de cada bloque

   int numBlocks = texto2.size() / blockSize;//Numero de bloques

   vector<string> bloques;//String vector bloques

   for (int i = 0; i < numBlocks; i++) {
       string bloque = texto2.substr(i * blockSize, blockSize);//Cadenas de caracteres tamaño bloque en la posición i*tamañobloque
       bloques.push_back(bloque);//Bloque generado en el string anterior a la ultima posición
   }


   for(int i=0;i<bloques.size();i++)//Ciclo para imprimir los bloques.
       cout<<"Bloque en la posicion "<<i<<"= "<<bloques[i]<<endl;

   for(int i=0;i<bloques.size();i++)
   {
        string operador = bloques[i];
        for(int j = 0; j<blockSize;j++)
        {
         int contadorceros = 0;
         int contadorunos = 0;
         if(operador[j]==0)
             contadorceros++;
         if(operador[j]==1)
             contadorunos++;

        }
   }
       //Ciclo para recorrer los bloques

   // Ahora, en el vector "bloques" tienes todos los bloques de tamaño "semilla"

 /*  for (const string& bloque : bloques) {
       cout << "Bloque: " << bloque << endl;
   }
   for(int i=0;i<texto2.size()/numBlocks;i++){
   cout<<"Bloque # "<<i<<bloques[i]<<endl;
   }
*/
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
