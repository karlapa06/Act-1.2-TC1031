// =================================================================
//
// File: main.cpp
// Author: Karla Alejandra Padilla González
// Date: 6/09/2022
//
// =================================================================
#include <iostream>
#include <vector>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"
#include "fstream"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream inputFile;
        ofstream outputFile;
        int n, search, number;
        if (argc!=3) {
            cout<<"usage: "<<argv[0]<<"input_file output_file"<<endl;
            return -1;
        }
        inputFile.open(argv[1]);
        if (!inputFile.is_open()) {
            cout<<argv[0]<<" File \""<<argv[1]<<"\" No se pudo abrir el archivo de entrada"<<endl;
            return -1;
        }
        outputFile.open(argv[2]);
        if (outputFile.fail()){
            cout << "No se pudo abrir el archivo de salida." << endl;
            return -1;
        }
        
        outputFile.open(argv[2]);
        inputFile>>n;
        vector<int>numbers(n);
        for (int i=0; i<n; i++) {
            inputFile>>number;
            numbers[i]=number;
        }
        int bubble, selection, insertion;
        vector<int>og=numbers;
        bubble=bubbleSort(og);
        og=numbers;
        selection=selectionSort(og);
        og=numbers;
        insertion=insertionSort(og);
        outputFile<<bubble<<" "<<selection<<" "<<insertion<<endl;
        inputFile>>search;
        pair<int, int>solution;
        for (int i=0; i<search; i++) {
            inputFile>>number;
            solution=sequentialSearch(og, number);
            outputFile<<solution.first<<" "<<solution.second<<" ";
            solution=binarySearch(og, number);
            outputFile<<solution.second<<endl;
        }
        inputFile.close();
        outputFile.close();
        return 0;
}
