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
    for(int e=0;e<8;e++){
        data[e]=idata[e];
    }
}

int hamming::getParityData(int loc){
    return parity_data[loc];
}

int hamming::getError(){
    return error;
}

void hamming::setErrorValue(int errorarray[4]){
    if (errorarray[0]==1){error+=1;}
    if (errorarray[1]==1){error+=2;}
    if (errorarray[2]==1){error+=4;}
    if (errorarray[3]==1){error+=8;}
    if (error>0)
        error-=1;
}
void hamming::addRandError(){
    srand(int(time(NULL)));
    int num=rand()%12;
    insertedError = num;
    if(parity_data[num]==0){
        parity_data[num]=1;
    }
    else{
        parity_data[num]=0;
    }
}

void hamming::calcParity(){
    
    parity_data[2]=data[0];
    parity_data[4]=data[1];
    parity_data[5]=data[2];
    parity_data[6]=data[3];
    parity_data[8]=data[4];
    parity_data[9]=data[5];
    parity_data[10]=data[6];
    parity_data[11]=data[7];
    
    parity_data[0]=(parity_data[2]+parity_data[4]+parity_data[6]+parity_data[8]+parity_data[10]) % 2;
   
    parity_data[1]=(parity_data[2]+parity_data[5]+parity_data[6]+parity_data[9]+parity_data[10]) % 2;
    
    parity_data[3]=(parity_data[4]+parity_data[5]+parity_data[6]) % 2;
   
    parity_data[7]=(parity_data[8]+parity_data[9]+parity_data[10]+parity_data[11]) % 2;

}

void hamming::checkParity(){
    
    int errorarray[4]{0};

    //check parity one
    errorarray[0] = (parity_data[0]+parity_data[2]+parity_data[4]+parity_data[6]+parity_data[8]+parity_data[10]) % 2;

    //check parity two
    errorarray[1] = (parity_data[1]+parity_data[2]+parity_data[5]+parity_data[6]+parity_data[9]+parity_data[10]) % 2;
    
    //check parity three
    errorarray[2] = (parity_data[3]+parity_data[4]+parity_data[5]+parity_data[6]) % 2;
    
    //check parity four
    errorarray[3] = (parity_data[7]+parity_data[8]+parity_data[9]+parity_data[10]+parity_data[11]) % 2;
    
    //set error value
    setErrorValue(errorarray);
    
}

bool hamming::correctData(){
    bool corrected = false;
    
    if (error < 12 and error >= 0){
        if(parity_data[error] == 1){
            parity_data[error] = 0;
        }
        else{
             parity_data[error] = 1;
        }
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
