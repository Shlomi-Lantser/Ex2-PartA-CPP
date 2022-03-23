#include "doctest.h"
#include <iostream>
#include "Direction.hpp"
#include "Notebook.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("write"){
    Notebook notebook;
    string check;
    unsigned int k= rand()%50;
    for (unsigned int i = 0; i < 14000; i++)
    {
        if (i%100 ==0) check ="";
        if (sizeof(check) + k <= 100){
            check+= (char)('a' + rand()%26);
             CHECK_NOTHROW(notebook.write(i , i%5000 , k , ariel::Direction::Horizontal , check));
            k = rand()%100;
        }else {
            CHECK_THROWS(notebook.write(i , i%5000 , k , ariel::Direction::Horizontal , check));
            check ="";
        }
    }
}

TEST_CASE("read"){
    Notebook notebook;
    string check;
    unsigned int k= rand()%50;
    for (unsigned int i = 0; i < 14000; i++)
    {
        if (i%100 ==0) check ="";
        if (sizeof(check) + k <= 100){
            check+=(char)('a' + rand()%26);
            notebook.write(i , i%5000 , k , ariel::Direction::Horizontal , check);
            CHECK(notebook.read(i , i%5000 , k , ariel::Direction::Horizontal , check.length()) == check);
            k = rand()%50;
        }else {
            check ="";
        }
    }
}

TEST_CASE("earse"){
    Notebook notebook;
    string check;
    unsigned int k= rand()%50;
    for (unsigned int i = 0; i < 14000; i++)
    {
        if (i%100 ==0) check ="";
        if (sizeof(check) + k <= 100){
            check+= (char)('a' + rand()%26);
            notebook.write(i , i%5000 , k , ariel::Direction::Horizontal , check);
            notebook.erase(i , i%5000 , k , ariel::Direction::Horizontal , check.length());
            CHECK(notebook.read(i , i%5000 , k , ariel::Direction::Horizontal , check.length()) == "~");
            k = rand()%50;
        }else {
            check ="";
        }
    }
}