/* 
 * File:   VolImage.h
 * Author: Mbele Lebohang
 *
 * Created on 05 April 2017, 9:42 AM
 */

#ifndef VOLIMAGE_H
#define VOLIMAGE_H

using namespace std;

class VolImage {
public:
    VolImage();
    VolImage(const VolImage& orig);
    virtual ~VolImage();
    
    /**
     * 
     * @param baseName
     * @return 
     */
    bool readImages(const string baseName);
    
    /**
     * 
     * @param sliceI
     * @param sliceJ
     * @param output_prefix
     */
    void diffmap(int sliceI, int sliceJ, string output_prefix);
    
    /**
     * 
     * @param sliceId
     * @param output_prefix
     */
    void extract(int sliceId, string output_prefix);
    
    /**
     * 
     * @return 
     */
    int VolImageSize(void);
private:
	int width, height; // width and height of image stack
	std::vector<unsigned char**> slices; // data for each slice, in order
};

#endif /* VOLIMAGE_H */

