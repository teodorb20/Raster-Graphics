#include "PGMImage.h"

void PGMImage::Negative(const char* nameImage, const char* typeOfImage)
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			m_mat[i][j] = ColorValue - m_mat[i][j];
		}
	}
	std::cout << "Image " << '"' << nameImage << "." << typeOfImage << '"' << " is negative!" << std::endl;
}

void PGMImage::Rotate(const char* direction, const char* nameImage, const char* typeOfImage)
{
	if (strcmp(direction, "left") == 0) {
		rotateLeft();
		std::cout << "Image " << '"' << nameImage << "." << typeOfImage << '"' << " rotate left!" << std::endl;
	}

	else if (strcmp(direction, "right") == 0) {
		rotateRight();
		std::cout << "Image " << '"' << nameImage << "." << typeOfImage << '"' << " rotate right!" << std::endl;
	}
	else {
		std::cout << "Invalid input!" << std::endl;
	}
}

void PGMImage::Add(const char* nameImage, const char* typeOfImage)
{
	std::cout << "Image " << '"' << nameImage << "." << typeOfImage << '"' << " added." << std::endl;
}

void PGMImage::Collage(const char* direction, const char* collageName, const char* typeOfImage)
{
	if (strcmp(direction, "horizontal") == 0) {
		if (strcmp(typeOfImage, "pgm") == 0) {
			collageHorizontal();
		}
		std::cout << "New horizontal collage " << "'" << collageName << "." << typeOfImage << "'" << " created!" << std::endl;
	}
	else if (strcmp(direction, "vertical") == 0) {
		if (strcmp(typeOfImage, "pgm") == 0) {
			collageVertical();
		}
		std::cout << "New vertical collage " << "'" << collageName << "." << typeOfImage << "'" << " created!" << std::endl;
	}
	else {
		std::cout << "Invalid input!";
	}
}

void PGMImage::rotateRight()
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			m_mat[i][j] = m_mat[j][i];
		}
	}
}

void PGMImage::rotateLeft()
{
	for (int i = m_rows - 1; i >= 0; i--) {
		for (int j = m_cols - 1; j >= 0; j--) {
			m_mat[i][j] = m_mat[j][i];
		}
	}
}

void PGMImage::collageHorizontal()
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			m_mat[i][j] = m_mat[i + i][j];
		}
	}
}

void PGMImage::collageVertical()
{
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			m_mat[i][j] = m_mat[i][j + j];
		}
	}
}