#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define COLORREF unsigned int // 32 bits 

class Fliper {
    public:
        png_structp png_ptr;
        png_infop info_ptr;
        png_uint_32 width, height;
        png_color_16p pBackground;
        int bit_depth, color_type;
        png_bytepp ppLinePtrs;

        Fliper();
        ~Fliper(); 
        bool read_file(string file_name);
        void close_file();
    private:
};