/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Mbele Lebohang
 *
 * Created on 05 April 2017, 9:40 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    const char* fileName = "MRI.raw";
    //char buffer[255];
    ifstream fin(fileName);
    unsigned char ch;
    int i = 0;
    while (fin >> ch){
        cout << (unsigned int)ch << " ";
        i++;
    }
    cout << endl;
    cout << "i = " << i;
    fin.close();
    cin >> ch;
}

