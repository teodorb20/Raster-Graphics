#pragma once
#include "Image.h"

class PGMImage : protected Image {
public:

	/**
	* Cannot use function monochrome and grayscale for PGM image
	*/
	/**
	* Function used for PGM
	*/
	virtual void Negative(const char* nameImage, const char* typeOfImage) override;
	/**
	* Function used for PGM
	*/
	virtual void Rotate(const char* direction, const char* nameImage, const char* typeOfImage) override;
	/**
	* Function used for PGM
	*/
	virtual void Add(const char* nameImage, const char* typeOfImage) override;
	/**
	* Function used for PGM
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
