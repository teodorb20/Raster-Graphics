#pragma once
#include "Image.h"

class PBMImage : protected Image {
public:

	/**
	* Cannot use function monochrome and grayscale for PBM image
	*/
	/**
	* Function used for PBM image
	*/
	virtual void Negative(const char* nameImage, const char* typeOfImage) override;
	/**
	* Function used for PBM image
	*/
	virtual void Rotate(const char* direction, const char* nameImage, const char* typeOfImage) override;
	/**
	* Function used for PBM image
	*/
	virtual void Add(const char* nameImage, const char* typeOfImage) override;
	/**
	* Function used for PBM image
	*/
	virtual void Collage(const char* direction, const char* collageName, const char* typeOfImage) override;
private:
	/*
	** Function for rotate right
	*/
	void rotateRight();
	/*
	** Function for rotate left
	*/
	void rotateLeft();
	/*
	** function for collage horizontal
	*/
	void collageHorizontal();
	/*
	** function for collage vertical
	*/
	void collageVertical();
};

