#pragma once
#include<iostream>
#include<cstring>
#include<fstream>
#include "Matrix.h"

class Image : protected Matrix {
public:
	/**
	* Big four
	*/
	Image(const char* _nameImage = "unnamed", const char* _typeOfImage = "unnamed", const char* _MagicNumber = "unnamed", const char* direction = "unnamed", const char* _collageName = "unnamed", int _ColorValue = 0);
	Image(const Image& other);
	Image& operator=(const Image& other);
	~Image();

	/**
	* Function for changing image
	*/
	virtual void GrayScale();
	/**
	* Function for changing image
	*/
	virtual void Monochrome();
	/**
	* Function for changing image
	*/
	virtual void Negative(const char* nameImage, const char* typeOfImage);
	/**
	* Function for changing image
	*/
	virtual void Rotate(const char* direction, const char* nameImage, const char* typeOfImage);
	/**
	* Function for changing image
	*/
	virtual void Add(const char* nameImage, const char* typeOfImage);
	/**
	* Function for changing image
	*/
	virtual void Collage(const char* direction, const char* collageName, const char* typeOfImage);

private:
	/**
	* Copy method is used in big four
	*/
	void copy(const Image& other);
	/**
	* Clear method is used in big four
	*/
	void clear();

protected:
	Matrix m_mat;
	/**
	* nameImage - use for name of image
	*/
	char* nameImage;
	/**
	* typeOfImage - use fo type of image(pbm or pgm)
	*/
	char* typeOfImage;
	/**
	*MagicNumber - P1 for PBM or P2 for PGM - with magic number we can recognize the image
	*/
	char* MagicNumber;
	/**
	* m_direction - for some functions left or right and for others vertical or horizontal
	*/
	char* m_direction;
	/**
	* collageName - use for name of collage of images
	*/
	char* collageName;
	/**
	* colorValue - use for color
	*/
	int ColorValue;
};
