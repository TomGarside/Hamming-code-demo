//
//  main.cpp
//  hamming code
//
//  Created by tom garside on 14/4/16.
//  Copyright © 2016 tom garside. All rights reserved.
//

#include <iostream>
#include "hamming.hpp"

int main(int argc, const char * argv[]) {
    int initdata[8]{0,0,0,0,0,0,0,0};
    
    if(argv[1]){
        int number = atoi(argv[1]);
        if (number >=0 and number<256)
            hamming::binRep(number,initdata,0);
        else
            std::cout<<"Input must be between 0 and 256\n";
    }
    
    //initialize
    hamming hamcode(initdata);
    //calculate the parity data
    hamcode.calcParity();
    std::string lineBar = "                        -------------------------------------\n";

    std::cout<<"Bit                      0  1  2  3  4  5  6  7  8  9  10 11 \n"<<lineBar;
    std::cout<<"Initial                 ";
    for(int e=0;e<12;e++){
        if(e!=0 and e!=1 and e!=3 and e!=7)
            std::cout<<"| "<<hamcode.getParityData(e);
        else
            std::cout<<"| "<<"*";
    }
    std::cout<<"|\n"<<lineBar;
    std::cout<<"Parity bits calculated  ";
    for(int e=0;e<12;e++){
        std::cout<<"| "<<hamcode.getParityData(e);
    }
    std::cout<<"|\n"<<lineBar;
    
    //flip a random bit to cause error
    hamcode.addRandError();
    std::cout<<"Random error added  :"<<hamcode.insertedError;
    if (hamcode.insertedError<10)
        std::cout<<"  ";
    else
        std::cout<<" ";
    for(int e=0;e<12;e++){
        std::cout<<"| "<<hamcode.getParityData(e);
    }
    std::cout<<"|\n"<<lineBar;
    
    //find error
    hamcode.checkParity();
    
    //correct error
    hamcode.correctData();

    std::cout<<"Error Corected          ";
    for(int e=0;e<12;e++){
        std::cout<<"| "<<hamcode.getParityData(e);
    }
    std::cout<<"|\n"<<lineBar;
    std::cout<<"Error calculated at :"<<hamcode.getError()<<"\n\n";
    
    return 0;
}



