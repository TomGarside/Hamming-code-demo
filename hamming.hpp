//
//  hamming.hpp
//  hamming code
//
//  Created by tom garside on 14/4/16.
//  Copyright © 2016 tom garside. All rights reserved.
//

#ifndef hamming_h
#define hamming_h

class hamming{
              
private:
    int data[8];
    int parity_data[12];
    int error=0;
    
public:
     int insertedError=0;
    //constructor takes data as input
    hamming(int data[8]);
              
    //uses check parity to identify eronious elements and then corrects them
    //if elements cannot be corrected ie there are too many errors returns false
    //if errors are repaired or there are no errors returns true
    bool correctData();
    
    // calculates the parity from data and stores it in parity_data
    void calcParity();
    
    //checks the parity of the data string and returns the position of any errors
    //if no errors are found returns -1
    void checkParity();
    
    //randomly flips a bit to introduce an error
    void addRandError();
    
    //returns a specified value from the parity_data array
    int getParityData(int);
    
    //returns the error value
    int getError();
  
    //calculates error position
    void setErrorValue(int[]);
    
    //fills array with bin representation (0-255)
    static void binRep(int num,int output[8],int depth);
    
    
    //destructor
    ~hamming(){}
    
    
    
              


};

#endif /* hamming_h */
