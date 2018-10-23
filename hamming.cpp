//
//  hamming.cpp
//  hamming code
//
//  Created by tom garside on 14/4/16.
//  Copyright © 2016 tom garside. All rights reserved.
//

#include "hamming.hpp"
#include <cstdlib>
#include<iostream>

hamming::hamming(int idata[8]){
    parity_data[2]=idata[0];
    parity_data[4]=idata[1];
    parity_data[5]=idata[2];
    parity_data[6]=idata[3];
    parity_data[8]=idata[4];
    parity_data[9]=idata[5];
    parity_data[10]=idata[6];
    parity_data[11]=idata[7];
    
    parity_data[0]=(parity_data[2]+parity_data[4]+parity_data[6]+parity_data[8]+parity_data[10]) % 2;
    parity_data[1]=(parity_data[2]+parity_data[5]+parity_data[6]+parity_data[9]+parity_data[10]) % 2;
    parity_data[3]=(parity_data[4]+parity_data[5]+parity_data[6]+parity_data[11]) % 2;
    parity_data[7]=(parity_data[8]+parity_data[9]+parity_data[10]+parity_data[11]) % 2;
    
}

int hamming::getParityData(int loc){
    return parity_data[loc];
}

void hamming::addRandError(){
    srand(int(time(NULL)));
    insertedError = rand()%12;
    parity_data[insertedError] = 1 - parity_data[insertedError];
}

void hamming::checkParity(){

    //check parity one
    if ((parity_data[0]+parity_data[2]+parity_data[4]+parity_data[6]+parity_data[8]+parity_data[10]) % 2)
        error+=1;

    //check parity two
    if ((parity_data[1]+parity_data[2]+parity_data[5]+parity_data[6]+parity_data[9]+parity_data[10]) % 2)
        error+=2;
    
    //check parity three
    if ((parity_data[3]+parity_data[4]+parity_data[5]+parity_data[6]+parity_data[11]) % 2)
        error+=4;
    
    //check parity four
    if ((parity_data[7]+parity_data[8]+parity_data[9]+parity_data[10]+parity_data[11]) % 2)
        error+=8;
    //for 0 indexed array
    error-=1;
    
}

bool hamming::correctData(){
    
    bool corrected = false;
    
    if (error < 12 and error >= 0){
        parity_data[error] = 1 - parity_data[error];
        corrected=true;
    }
    return corrected;
}

void hamming::binRep(int num,int output[8],int depth=0){
    if(num>1){
        binRep(num/2,output,depth+1);
    }
    output[depth] = num%2;
}
