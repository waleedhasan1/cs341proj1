//
// Project 1
// CS 341 Spring 2021
// << Your Name Here >>
//
// Populate this file with the function definitions for the acronymIterator class
#include <ctype.h>
#include "acronymIterator.h"

characterParser::acronymIterator::acronymIterator(char* arr)
{
    curr = arr;
}

char& characterParser::acronymIterator::operator*()
{
    //std::cout << "acroiter operator * is called" << std::endl;
    if (!isalpha(*curr))
    {
        while (*curr != '\0' && !isalpha(*curr))
        {
            //std::cout << *curr << std::endl;
            curr++;
        }
    }
    
    if (*curr >= 96 && *curr <= 122) //if letter is lowercase make it uppercase
    {
        *curr -= 32;
        return *curr;  //return uppercase values
    }
    

    return *curr; //should only get here if on an Uppercase letter;
}




characterParser::acronymIterator& characterParser::acronymIterator::operator++()
{
    /*
    bool flag;  //true if curr is on a letter false if not
    if (*curr >= 65 && *curr <= 90 || *curr >= 97 && *curr <= 122)
    {
        flag = true;
    }
    else {flag = false;}   */

    if (isalpha(*curr))
    {
        while (*curr != '\0' && isalpha(*curr))
        {
            //std::cout << *curr << std::endl;
            curr++;
        }
    }

    if (!isalpha(*curr))
    {
        while (*curr != '\0' && !isalpha(*curr))
        {
            //std::cout << *curr << std::endl;
            curr++;
        }
    }

    return *this;
}

bool characterParser::acronymIterator::operator!=(const characterParser::acronymIterator& other)
{
    return (curr != other.curr);
}

bool characterParser::acronymIterator::operator==(const characterParser::acronymIterator& other)
{
    return (curr != other.curr);
}