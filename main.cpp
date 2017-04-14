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
#include "VolImage.h"

using namespace std;
using namespace MBLLEB006;

/*
 * 
 */
int main(int argc, char** argv) {
    const string image_base = argv[1];
    VolImage volume;
    volume.readImages(image_base);
    
    if(image_base.substr(0,1) == "-"){
        /* Check if the first argument is not a flag.*/
        cout << "Unknown flag. Please read README.md file." << endl;
        exit(0);
    }
    
    // check if a parameter was given for the name of the log file to use
    if(argc == 6){
        if(string(argv[2]) == "-d"){
            
            cout << "Computing the difference in image " << argv[3] << " and "<< argv[4] << endl;
            volume.diffmap(stoi(argv[3]), stoi(argv[4]), argv[5]);
            cout << "Done. Open " << argv[5] << ".raw using viewer.py to see the results."<<endl; 
        }
        else{
            cout << "Unknown flag " << argv[2] << ". Please read README.md file." << endl;
        }
    }
    else if (argc == 5) {
        
        if(string(argv[2]) == "-i"){
            
            cout << "Extracting slice number... " << argv[3] << endl;
            volume.extract(stoi(argv[3]), argv[4]);
            cout << "Done. Open " << argv[4] << ".raw using viewer.py to see the results."<<endl; 
        }
        else if(string(argv[2]) == "-g"){
            
            cout << "Extracting row " << argv[3] << " of all slices..."<< endl;
            volume.extraCredit(stoi(argv[3]), argv[4]);
            cout << "Done. Open " << argv[4] << ".raw using viewer.py to see the results."<<endl; 
        }
        else{
            cout << "Unknown flag " << argv[2] << ". Please read README.md file." << endl;
        }
    }
    else if (argc == 2)
    {
        cout << "Number of images: " << volume.getSliceCount() <<endl;
        cout << "Number of bytes required: " << volume.volImageSize() <<endl;
    }
    else{
        cout << "Invalid number of arguments. Please read README.md file." <<endl;
    }
}

