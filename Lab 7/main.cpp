#include <iostream>
#include <fstream>
using namespace std;

/**
 * @brief writes sample_size number of integers
 * Example output: if n = 3 and arr = [1,2,3]
 * 1
 * 2
 * 3
 * 
 * @param filename 
 * @param arr 
 * @param sample_size 
 */
void writeToFile(string filename, int * arr, int sample_size){
    ofstream file(filename);
    int val;

    for (int i = 0; i < sample_size; i++){
        file << arr[i];
        file << "\n";
    }
    file.close();
    printf("Wrote to %s\n", filename.c_str());
}

/**
 * @brief writes sample_size number of strings
 * Example output: if n = 2 and arr = ["cat", "dog"]
 * cat
 * dog
 * 
 * @param filename 
 * @param arr 
 * @param sample_size 
 */
void writeToFile(string filename, string * arr, int sample_size){
    ofstream file(filename);

    for(int i = 0; i < sample_size; i++){
        file << arr[i];
        file << "\n";
    }
    file.close();
    printf("Wrote to %s\n", filename.c_str());
}

/**
 * @brief write sample_size number of char
 * Example output: if n = 2 and arr = ["c", "d"]
 * c
 * d
 * 
 * @param filename 
 * @param arr 
 * @param sample_size 
 */
void writeToFile(string filename, char * arr, int sample_size){
    ofstream file(filename);

    for(int i = 0; i < sample_size; i++){
        file << arr[i];
        file << "\n";
    }
    file.close();
    printf("Wrote to %s\n", filename.c_str());
}

/**
 * @brief reads the content of any file
 * 
 * @param filename 
 */
void readFile(string filename){
    ifstream file(filename);
    string line;

    cout << "The content in this file is: ";
    while(file>>line){
        cout << line << " ";
    }
    cout << endl;

    file.close();
}

int main(){
    const int SAMPLE_SIZE = 10;
    int array_int[SAMPLE_SIZE] = {1,2,3,4,5,6,7,8,9,10}; 
    string array_str[SAMPLE_SIZE] = {"This", "is", "a", "sentence.", "This", "is", "another", "sentence.", "The", "end."};

    char array_char[SAMPLE_SIZE] = {'a','b','c','d','e','0','1', '2', '3', '4'};

    string int_file = "array_int.csv";
    writeToFile(int_file, array_int, SAMPLE_SIZE);

    // Do the same for the other arrays

    // CREATE a string variable as the filename and assign
    // it the value "array_str.cvs"
    string str_file = "array_str.csv";

    // CALL writeToFile using the string variable above, array.str, and SAMPLESIZE as
    // Parameters
    writeToFile(str_file, array_str, SAMPLE_SIZE);

    // CREATE a string variable as the filename and assign
    // it the value "array_char.cvs"
    string char_file = "array_char.csv";

    // CALL writeToFile using the string above, array_char, and SAMPLESIZE as 
    // Parameters
    writeToFile(char_file, array_char, SAMPLE_SIZE);
    
    // CALL readFile() on all three generated files.
    readFile(int_file);
    readFile(str_file);
    readFile(char_file);

    return 0;
}