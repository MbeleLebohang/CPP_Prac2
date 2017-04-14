/*
 * File:   VolImage.h
 * Author: Mbele Lebohang
 *
 * CSC3022H Assignment 2017 - VolImage
 * VolImage class declaration
 */

// Standard includes
#include <cstdlib>
#include <iostream>
#include <vector>

// Join the std namespace
using namespace std;

#ifndef VOLIMAGE_H
#define VOLIMAGE_H

namespace MBLLEB006{
	class VolImage {
		public:
	  		/** Default constructor for VolImage class */
	  		VolImage ();

	  		/** Default deconstructor for VolImage class */
			~VolImage ();

			/** Load slice from a with the basename files.
			    Returns true if loaded.
			    Returns false not found. */
			bool readImages (const string base_name);
                        
                        /**
                         * Read the loader slices from memory and write them
                         * to output file.
                         * @param output_name
                         * @return 
                         */
                        bool writeImage(const string output_name);

			/** compute difference map and write out. */
			void diffmap(int sliceI, int sliceJ, string output_prefix);

			/** extract slice sliceId and write to output. */
			void extract(int sliceId, string output_prefix);

			/** number of bytes uses to store image data bytes. */
			int volImageSize(void); 

			// TODO: add other methods for processing the VolImage

		protected:

	 	private:
			int width, height, slice_count; // width and height of image stack
			std::vector<unsigned char**> slices; // data for each slice, in order

	};
}

#endif /* VOLIMAGE_H */
