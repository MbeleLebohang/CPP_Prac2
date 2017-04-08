/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VolImage.cpp
 * Author: sponono
 * 
 * Created on 05 April 2017, 9:42 AM
 */

#include "VolImage.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace MBLLEB006;
using namespace std;

VolImage::VolImage() {
}

VolImage::~VolImage() {
}

bool VolImage::readImages(const string baseName){
	/*
	 *	read the .data file
	 * 	get the height, width and the slice_count
	 */
	ifstream data_file (baseName + ".data");
	string line;

    if(data_file.is_open()){
        data_file >> width; 
        data_file >> height;
        data_file >> slice_count;
    }

    data_file.close();


    /*
     * Read each slice and save it to the slice<vector>
     */
    for(int slice = 0; slice < slice_count; slice++){
        /* All the slices with the baseName. */
        ifstream binary_file (baseName + to_string(slice) + ".raw", ios::in|ios::binary);

        u_char** image_height_array = new u_char*[height];     //column - place to put all rows
        for(int h = 0; h < height; h++){
            /* All the height levels(row) in the image. */

            image_height_array[h] = new u_char[width];        // row - place to put all chars

            char* image_width_array = new char[width];
            binary_file.read(image_width_array, width);     //read the whole width of bytes.

            for(int w = 0; w < width; w++){
                /* Each column (width piece). */
                image_height_array[h][w] = image_width_array[w];
            } 
            
            delete[] image_width_array;
            slices.push_back(image_height_array);
            binary_file.close();
            return 0;      
        }
    }

	return 0;

}
/*

    const char* fileName = "MRI0.raw";
    //char buffer[255];
    ifstream fin(fileName, ios::in|ios::binary|ios::ate);
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
    return 0;

    *************************************/

