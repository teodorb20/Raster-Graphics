#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "Image.h"
#include "PBMImage.h"
#include "PGMImage.h"

/*
** Setting maximum value
*/
int const MAX_INPUT_COMMAND = 14;
/*
** Setting maximum value
*/
int const MAX_NAME_SIZE = 128;
/*
** Setting maximum value
*/
int const MAX_TYPEIMAGE = 4;
/*
** Setting maximum value
*/
int const MAX_DIRECTION_SIZE = 20;
/*
** Setting maximum value
*/
int const MAX_MAGIC_SIZE = 3;

class System : public PBMImage, public PGMImage {
public:
    /*
    ** Constructor
    */
    System();
    /*
    ** Print help menu
    */
    void Help();
    /*
    ** This function does not allow a new copy of the system to be made
    */
    static System& i();
    /*
    ** Function "run" is used to write all other functions and run the program
    */
    void run();

private:
    /*
    ** Use static function because id is unique
    */
    static unsigned getID();
    /**
    * Set initial value in System.cpp = 0
    */
    static unsigned currID;
private:
    /*
    ** m_id - use for id
    */
    unsigned m_id;


};