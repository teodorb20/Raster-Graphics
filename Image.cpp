#include "Image.h"

Image::Image(const char* _nameImage, const char* _typeOfImage, const char* _MagicNumber, const char* direction, const char* _collageName, int _ColorValue)
	: nameImage(new char[strlen(_nameImage) + 1])
	, typeOfImage(new char[strlen(_typeOfImage) + 1])
	, MagicNumber(new char[strlen(_MagicNumber) + 1])
	, m_direction(new char[strlen(direction) + 1])
	, collageName(new char[strlen(_collageName) + 1])
	, ColorValue(_ColorValue)
{
	strcpy(this->nameImage, _nameImage);
	strcpy(this->typeOfImage, _typeOfImage);
	strcpy(this->MagicNumber, _MagicNumber);
	strcpy(this->m_direction, direction);
	strcpy(this->collageName, _collageName);
}

Image::Image(const Image& other)
{
	copy(other);
}

Image& Image::operator=(const Image& other)
{
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}

Image::~Image()
{
	clear();
}

void Image::GrayScale()
{
}

void Image::Monochrome()
{
}

void Image::Negative(const char* nameImage, const char* typeOfImage)
{
}

void Image::Rotate(const char* direction, const char* nameImage, const char* typeOfImage)
{
}

void Image::Add(const char* nameImage, const char* typeOfImage)
{
}

void Image::Collage(const char* direction, const char* collageName, const char* typeOfImage)
{
}

void Image::copy(const Image& other)
{
	this->nameImage = new char[strlen(other.nameImage) + 1];
	strcpy(this->nameImage, other.nameImage);
	this->typeOfImage = new char[strlen(other.typeOfImage) + 1];
	strcpy(this->typeOfImage, other.typeOfImage);
	this->MagicNumber = new char[strlen(other.MagicNumber) + 1];
	strcpy(this->MagicNumber, other.MagicNumber);
	this->m_direction = new char[strlen(other.m_direction) + 1];
	strcpy(this->m_direction, other.m_direction);
	this->collageName = new char[strlen(other.collageName) + 1];
	strcpy(this->collageName, other.collageName);
	this->ColorValue = other.ColorValue;
}

void Image::clear()
{
	delete[] nameImage;
	nameImage = nullptr;
	delete[] typeOfImage;
	typeOfImage = nullptr;
	delete[] MagicNumber;
	MagicNumber = nullptr;
	delete[] m_direction;
	m_direction = nullptr;
}
