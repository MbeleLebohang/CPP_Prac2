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
			bool readImages (const std::string base_name);
                        
			/** compute difference map and write out. */
			void diffmap(int sliceI, int sliceJ, std::string output_prefix);

			/** extract slice sliceId and write to output. */
			void extract(int sliceId, std::string output_prefix);

			/** number of bytes uses to store image data bytes. */
			int volImageSize(void); 

			/**
                         * extracts an image along rowIndex of the volume, 
                         * across all slices, and write this to output.
                         * @param rowIndex
                         * @param output_prefix
                         */
                        void extraCredit(int rowIndex, std::string output_prefix);
                        
                        int getSliceCount(void);

		protected:

	 	private:
			int width, height, slice_count; // width and height of image stack
			std::vector<unsigned char**> slices; // data for each slice, in order

	};
}

#endif /* VOLIMAGE_H */
