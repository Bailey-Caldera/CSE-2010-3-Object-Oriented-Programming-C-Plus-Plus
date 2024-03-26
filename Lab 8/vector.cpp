#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief prints the elements in the array and their memory locations
 * 
 * @param arr - array of integers
 * @param size - the number of elements in the array
 */
void printMemArray(const int * arr, int size){ // void printMemArray(int arr[], int size)
    printf("Array - Each int is worth %lu bytes\n", sizeof(arr[0]));
    for(int i = 0; i < size; i++){
        printf("Value :%i at Memory Location: %p\n", arr[i], arr + i);
    }
}

/**
 * @brief Increments all of elements in arr by 10
 * 
 * @param arr - array of integers
 * @param size - the number of elements in the array
 */
void incArrBy10(int * arr, int size){ // void incArrBy10(int arr[], int size)
    for(int i = 0; i < size; i++){
        arr[i] += 10;
    }
}

/**
 * @brief prints the elements in the vector and their memeory locations
 * 
 * @param vec - vector of integers
 */
void printMemVec(vector<int> vec){
    printf("Vector - Each int is worth %lu bytes\n", sizeof(vec[0]));
    for(int i = 0; i < vec.size(); i++){
        printf("Value :%i at Memory Location: %p\n", vec[i], &vec + i);
    }
}

/**
 * @brief increments all of the elements in vec by 10
 * 
 * @param vec - address to a vector of integers
 */
void incVecBy10(vector<int> &vec){
    for(int i = 0; i < vec.size(); i++){
        vec[i] += 10;
    }
}

int main(){
    // create a constant integer called SIZE that is of value 5
    const int SIZE = 5;

    // Add the array main function for the vector.cpp translation part
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++){
        arr[i] = 100 + i;
    }
    printf("Before------------------------\n");
    printMemArray(arr, SIZE);
    incArrBy10(arr, SIZE);
    printf("After------------------------\n");
    printMemArray(arr, SIZE);

    // create a vector of integer called vec that can hold up to 5 elements
    vector<int> vec;

    // use a for loop to populate vec with the values 100 to 104
    for(int i = 0; i < SIZE; i++){
        vec.push_back(100 + i);
    }

    printf("Before Increment-----------------------------\n");
    //call printMemVec(...) on vec
    printMemVec(vec);

    //call incBy10(...) on vec
    incVecBy10(vec);

    printf("After Increment------------------------------\n");
    //call printMemVec(...) on vec again to view the changes
    printMemVec(vec);

    //remove last element of vec
    // (refer to docs https://cplusplus.com/reference/vector/vector/#google_vignette)
    vec.pop_back();

    printf("After Pop------------------------------\n");
    //call printMemVec(...) on vec again to view the changes
    printMemVec(vec);

    // append 101 and 102 at the end of vec
    // (refer to docs https://cplusplus.com/reference/vector/vector/#google_vignette)
    vec.push_back(101);
    vec.push_back(102);

    printf("After Push------------------------------\n");
    //call printMemVec(...) on vec again to view the changes
    printMemVec(vec);

    return 0;
}