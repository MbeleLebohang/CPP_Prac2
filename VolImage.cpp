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
#include <cmath>

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

            unsigned char* image_width_array = new unsigned char[width];
            binary_file.read((char*)image_width_array, width);     //read the whole width of bytes.

            for(int w = 0; w < width; w++){
                /* Each column (width piece). */
                image_height_array[h][w] = image_width_array[w];
            } 
            delete[] image_width_array;
        }   
        slices.push_back(image_height_array);
        binary_file.close();      
    }
    return 0;
}

void VolImage::extract(int sliceId, string output_prefix){
    
    if(sliceId >= slice_count){
        cout << "slice Id out of range. Max slice index is " << slice_count - 1<<endl;
    }
    else{
        ofstream file_out;
        file_out.open(output_prefix + ".raw", ios::out | ios::binary);

        u_char** slice = slices[sliceId];

        for(int h = 0; h < height; h++){
            /* All the height levels(row) in the image. */
            u_char* image_width_array = slice[h];        // row - place to put all chars

            //read the whole width of bytes.
            char* temp = new char[width];
            for(int w = 0; w < width; w++){
                /* Each column (width piece). */
                temp[w] = image_width_array[w];
            } 
            file_out.write(temp, width);
            delete[] temp;
        }   
        file_out.close();
        
        /* Create a .data file for this results */
        ofstream data_file;
        data_file.open(output_prefix + ".data", ios::out);
        if(data_file.is_open()){
            data_file << width << " " << height << " " << 1;
            data_file.close();
        }
        else{
            cout << output_prefix + ".data could not be opened. Error occurred." << endl;
        }
    }
}

void VolImage::diffmap(int sliceI, int sliceJ, string output_prefix){
    
    if((sliceI >= slice_count) || (sliceJ >= slice_count)){
        cout << "slice Id out of range. Max slice index is " << slice_count - 1<<endl;
    }
    else{
        /* 2D raw files*/
        ofstream file_out;
        file_out.open(output_prefix + ".raw", ios::out | ios::binary);

        for(int h = 0; h < height; h++){
            /* All the height levels(row) in the image. */

            //read the whole width of bytes.
            char* temp = new char[width];
            for(int w = 0; w < width; w++){
                /* Each column (width piece). */
                temp[w] = (unsigned char)(abs((float)slices[sliceI][h][w] - (float)slices[sliceJ][h][w])/2);
            } 
            file_out.write(temp, width);
            delete[] temp;
        }   
        file_out.close();
    }

}

