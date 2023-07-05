/**
 * @author: hong
 * @date: 2022/5/31 07:42
 * @description:
 */

#include "file_factory.h"

#include <iostream>
using namespace std;


void BinaryFileReader::read() {
    cout << "BinaryFileReader" << endl;
}


void TextFileReader::read(){
        cout << "TextFileReader" << endl;
}



FileReader* BinaryFileReaderFactory::create(){
        return new BinaryFileReader();
}

FileReader* TextFileReaderFactory::create(){
        return new TextFileReader();
}