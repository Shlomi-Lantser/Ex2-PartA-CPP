#include <iostream>
#include <vector>
#include <string>
#include "Direction.hpp"

using namespace std;
using ariel::Direction;

namespace ariel{
    class Notebook{
        private: 
        vector<vector<string>> pages;
        public:
        Notebook(){

        }
        ~Notebook(){

        }
        void write(unsigned int page , unsigned int row , unsigned int col , ariel::Direction dir , string const &input);
        string read(unsigned int page , unsigned int row , unsigned int col , ariel::Direction dir , int len);
        void erase(unsigned int page , unsigned int row , unsigned int col , ariel::Direction dir , int len);
        void show(unsigned int page);
    };
}
