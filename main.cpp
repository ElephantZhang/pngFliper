#include <iostream>
#include <cstring>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <png.h>


using namespace std;

void GetFileNames(string path,vector<string>& filenames)
{
    DIR *pDir;
    struct dirent* ptr;
    if(!(pDir = opendir(path.c_str()))){
        cout<<"Folder doesn't Exist!"<<endl;
        return;
    }
    while((ptr = readdir(pDir))!=0) {
        if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0){
            filenames.push_back(path + "/" + ptr->d_name);
    }
    }
    closedir(pDir);
}

int main(){
    vector<string> vec;
    GetFileNames("./imgs", vec);
    for(int i=0; i<vec.size(); i++) {

    }
    return 0;
}