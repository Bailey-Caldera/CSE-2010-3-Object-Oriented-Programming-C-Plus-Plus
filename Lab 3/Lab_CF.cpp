// Lab_CF.cpp
/*
* The program iterates, displaying x and add 3 to x until x is great than or equal to y.
* Then display if x is even or odd at the end of the iteration
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    
    //Initialize condition value
    int x = 0;
    int y = 5;

    //Display x and ddd 3 to x to each iteration until x is greater or equal to y
    while (x < y){
        printf("%i\n", x);
        x = x + 3;
    }

    //Check if x is an even or odd number and display the result
    if (x % 2){
        printf("x is even\n");
    }
    else {
        printf("x is odd\n");
    }

    return 0;
}