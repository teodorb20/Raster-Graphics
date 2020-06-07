#include "System.h"

unsigned System::currID = 0;

unsigned System::getID()
{
	return currID++;
}

System::System()
	: m_id(getID())
{
}

void System::Help()
{
	std::cout << "load <nameOfImage> <typeOfImage> - start a new session" << std::endl
		<< "add <nameOfImage> <typeOfImage> - add a new image to the current session" << std::endl
		<< "monochrome <nameOfImage> <typeOfImage> - image which is composed of one color" << std::endl
		<< "grayscale <nameOfImage> <typeOfImage> - image which is distinct from one-bit bi-tonal black-and-white" << std::endl
		<< "rotate <direction> <nameImage> <typeOfImage> - rotate image left or right" << std::endl
		<< "collage <direction> <nameImage> <typeOfImage> <nameImage> <typeOfImage> <collageName> <typeOfImage> - collage images from one type" << std::endl
		<< "save <nameImage> <typeOfImage> <MagicNumber> - save image to a file" << std::endl
		<< "open - open image from file" << std::endl;
}

System& System::i()
{
	static System image;
	return image;
}

void System::run()
{
	std::vector<Image> vec;
	char input[MAX_INPUT_COMMAND];
	char nameImage[MAX_NAME_SIZE];
	char collageName[MAX_NAME_SIZE];
	char typeOfImage[MAX_TYPEIMAGE];
	char m_direction[MAX_DIRECTION_SIZE];
	char MagicNumber[MAX_MAGIC_SIZE];
	const char* FILENAME = "image.txt";

	do {

		std::cout << ">>";
		std::cin >> input;
		/**
		* Load new session with unique ID
		*/
		if (strcmp(input, "load") == 0) {
			std::cin.getline(nameImage, MAX_NAME_SIZE, '.');
			std::cin >> typeOfImage;
			if (strcmp(typeOfImage, "pbm") == 0) {
				vec.push_back({ nameImage, typeOfImage });
				std::cout << "Session with ID " << getID() << " started." << std::endl;
				std::cout << "Image " << '"' << nameImage << "." << typeOfImage << '"' << " added." << std::endl;
			}
			else if (strcmp(typeOfImage, "pgm") == 0) {
				vec.push_back({ nameImage, typeOfImage });
				std::cout << "Session with ID " << getID() << " started." << std::endl;
				std::cout << "Image " << '"' << nameImage << "." << typeOfImage << '"' << " added." << std::endl;
			}
			else {
				std::cout << "Unknown!" << std::endl;
				std::cout << "Please enter pbm or pgm!" << std::endl;
			}
		}
		/**
		* Add images to the current session
		*/
		else if (strcmp(input, "add") == 0) {
			std::cin.getline(nameImage, MAX_NAME_SIZE, '.');
			std::cin >> typeOfImage;
			if (strcmp(typeOfImage, "pbm") == 0) {
				vec.push_back({ nameImage, typeOfImage });
				PBMImage::Add(nameImage, typeOfImage);
			}
			else if (strcmp(typeOfImage, "pgm") == 0) {
				vec.push_back({ nameImage, typeOfImage });
				PGMImage::Add(nameImage, typeOfImage);
			}
			else {
				std::cout << "Unknown!" << std::endl;
				std::cout << "Please enter pbm or pgm!" << std::endl;
			}
		}
		/**
		* This function works on color images
		*/
		else if (strcmp(input, "monochrome") == 0) {
			std::cin.getline(nameImage, MAX_NAME_SIZE, '.');
			std::cin >> typeOfImage;
			if (strcmp(typeOfImage, "pbm") == 0) {
				std::cout << "PBM cannot be monochrome!" << std::endl;
			}
			else if (strcmp(typeOfImage, "pgm") == 0) {
				std::cout << "PGM cannot be monochrome!" << std::endl;
			}
			else {
				std::cout << "Unknown!" << std::endl;
			}
		}
		/**
		* This function works on color images
		*/
		else if (strcmp(input, "grayscale") == 0) {
			std::cin.getline(nameImage, MAX_NAME_SIZE, '.');
			std::cin >> typeOfImage;
			if (strcmp(typeOfImage, "pbm") == 0) {
				std::cout << "PBM cannot be grayscale!" << std::endl;
			}
			else if (strcmp(typeOfImage, "pgm") == 0) {
				std::cout << "PBM cannot be grayscale!" << std::endl;
			}
			else {
				std::cout << "Unknown!" << std::endl;
			}
		}
		/**
		* This function is a total color inversion
		*/
		else if (strcmp(input, "negative") == 0) {
			std::cin.getline(nameImage, MAX_NAME_SIZE, '.');
			std::cin >> typeOfImage;
			if (strcmp(typeOfImage, "pbm") == 0) {
				PBMImage::Negative(nameImage, typeOfImage);
			}
			else if (strcmp(typeOfImage, "pgm") == 0) {
				PGMImage::Negative(nameImage, typeOfImage);
			}
			else {
				std::cout << "Unknown!" << std::endl;
				std::cout << "Please enter pbm or pgm!" << std::endl;
			}
		}
		/**
		* Rotate left or right
		*/
		else if (strcmp(input, "rotate") == 0) {
			std::cin >> m_direction;
			std::cin.getline(nameImage, MAX_NAME_SIZE, '.');
			std::cin >> typeOfImage;
			if (strcmp(typeOfImage, "pbm") == 0) {
				PBMImage::Rotate(m_direction, nameImage, typeOfImage);
			}
			else if (strcmp(typeOfImage, "pgm") == 0) {
				PGMImage::Rotate(m_direction, nameImage, typeOfImage);
			}
			else {
				std::cout << "Unknown command!" << std::endl;
			}
		}
		/**
		* Make a collage from one type of images
		*/
		else if (strcmp(input, "collage") == 0) {
			std::cin >> m_direction;
			std::cin.getline(nameImage, MAX_NAME_SIZE, '.');
			std::cin >> typeOfImage;
			std::cin.getline(nameImage, MAX_NAME_SIZE, '.');
			std::cin >> typeOfImage;
			std::cin.getline(collageName, MAX_NAME_SIZE, '.');
			std::cin >> typeOfImage;
			if (strcmp(typeOfImage, "pbm") == 0) {
				PBMImage::Collage(m_direction, collageName, typeOfImage);
			}
			else if (strcmp(typeOfImage, "pgm") == 0) {
				PGMImage::Collage(m_direction, collageName, typeOfImage);
			}
		}
		/**
		* Save to a file
		*/
		else if (strcmp(input, "save") == 0) {
			std::cin.getline(nameImage, MAX_NAME_SIZE, '.');
			std::cin >> typeOfImage;
			std::cin >> MagicNumber;

			std::ofstream out(FILENAME, std::ios::out);
			if (!out) {
				std::cout << "Cannot open file!" << std::endl;
			}
			else {
				std::cout << "Save image to " << FILENAME << std::endl;
				out << MagicNumber;
				out << nameImage;
				out << typeOfImage;
				std::cout << "Successfully saved!" << std::endl;
			}
			out.close();
		}
		/**
		* Open from file
		*/
		else if (strcmp(input, "open") == 0) {
			std::ifstream in(FILENAME, std::ios::in);
			if (!in) {
				std::cout << "Cannot open file!" << std::endl;
			}
			else {
				std::cout << "Open image from " << FILENAME << std::endl;
				in >> MagicNumber;
				in >> nameImage;
				in >> typeOfImage;
				std::cout << "Successful opened!" << std::endl;
			}
			in.close();
		}
		else if (strcmp(input, "help") == 0) {
			Help();
		}
		else {
			std::cout << "Unknown command!" << std::endl;
		}
	} while (strcmp(input, "exit") != 0);
	std::cout << "Bye!" << std::endl;
}