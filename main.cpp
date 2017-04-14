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
    const string image_base = "brain_mri_raws/MRI";
    VolImage v;
    v.readImages(image_base);
    
    cout << "Files read into memory correctly."<<endl;
    
    cout << "Extract slice I and write to extract.raw..."<<endl;
    v.extract(10,"extract");
    cout << "Done."<<endl;
    
    cout << "Find difference in a file..."<<endl;
    v.diffmap(9,9, "diff_outfile");
    cout << "Done."<<endl;
    
    cout << "extra credit..."<<endl;
    v.extraCredit(99, "extra_outfile");
    cout << "Done."<<endl;
    return 0;
    // check if a parameter was given for the name of the log file to use
    /*if(argc == 6){
        cout << "compute a difference map between images " 
        << argv[3] << " and " << argv[4] << 
        " and write this out to " << argv[5] << " file." << endl;
    }
    else if (argc == 5) {
        image_base = argv[1];
        
        if(image_base.substr(0,1) != "-"){
            cout << "extract and write the slice with number " << argv[3] << " and write this out to " << argv[4] << " file." << endl;
        }
        else{
            cout << "Unknown flag " << argv[1] << ". Please read README.md file." << endl;
        }
    }
    else if (argc == 1)
    {
        cout << "Number of images: " << 122 <<endl;
        cout << "Number of bytes required: " << 122*8 <<endl;
    }
    else{
        cout << "Invalid number of arguments. Please read README.md file." <<endl;
    }*/
}

