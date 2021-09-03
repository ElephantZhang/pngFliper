#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <png.h>
#include "fliper.hpp"

Fliper::Fliper() {
    png_ptr = NULL;
    info_ptr = NULL; 
}

bool Fliper::read_file(string file_name) {
    FILE *fp = fopen(file_name.c_str(), "wb");
    if(!fp) {
        fprintf(stderr, "file %s open fail\n", file_name.c_str());
    }
    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, 
            NULL, NULL, NULL);
    if(!png_ptr) {
        fprintf(stderr, "png_ptr get fail\n");
        return false;
    }   
    info_ptr = png_create_info_struct(png_ptr);
    if(!info_ptr) {
        fprintf(stderr, "info_ptr get fail\n");
        return false;
    }

    png_init_io(png_ptr, fp);
    png_read_info(png_ptr, info_ptr);
    png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type,
                    NULL, NULL, NULL);
    png_get_bKGD(png_ptr,info_ptr,&pBackground);
    if(color_type==PNG_COLOR_TYPE_PALETTE)
        png_set_palette_to_rgb(png_ptr);//要求转换索引颜色到RGB
    if(color_type==PNG_COLOR_TYPE_GRAY && bit_depth<8)
        png_set_expand_gray_1_2_4_to_8(png_ptr);//要求位深度强制8bit
    if(bit_depth==16)
        png_set_strip_16(png_ptr);//要求位深度强制8bit
    if(png_get_valid(png_ptr,info_ptr,PNG_INFO_tRNS))
        png_set_tRNS_to_alpha(png_ptr);
    if(color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
    png_set_gray_to_rgb(png_ptr);//灰度必须转换成RGB    
    
    ppLinePtrs = (COLORREF**) malloc(g_dwHei)
    return true;
}




void Fliper::close_file() {
    png_destroy_write_struct(&png_ptr, &info_ptr);
}