#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/**
 * @brief returns the first indext of the elem, otherwise return -1
 * iterativeSearch starts at the first index and iterates sequntially to the next until it either
 * finds the element or until it reaches the end (i.e. element does not exit)
 * 
 * @param v 
 * @param elem 
 * @return int 
 */
int iterativeSearch(vector<int> v, int elem){
    // use a for loop where the index, i goes from 0 to the size of v
    for(int i = 0; i < v.size(); i++){
        // inside the for loop, use an if statment to check whether the element at i (e.g. v[i]) equal elem
        // inside the if statment return i
        if (v[i] == elem){
            return i;
        }
    }
    
    // outside of the for loop return -1
    return -1;
}

/**
 * @brief returns the index of elem, if it exists in v. Otherwise it return -1.
 * binarySearch is recursive (i.e. function call itself).
 * It utilizes the fact that v is increasing order (e.g. values go up and
 * duplicates are not allowed)
 * 
 * It calculates the mid from the start and the end index. It compare v[mid] (i.e. value
 * at min) with elem and decides whether to search the left half (lower values)
 * or right half (upper values).
 * 
 * @param v : vector of element
 * @param start : leftmost index (starting value is 0)
 * @param end : rightmost index (starting value is v.size())
 * @param elem : integer to look for
 * @return int 
 */
int binarySearch(vector<int> v, int start, int end, int elem){
    // write an if statment that check the terminating case
    // inside the if statement return -1
    if (start > end){
        return -1;
    }

    // instantiate the mid point
    int mid = (start + end) / 2;

    // Use if/else statements to do the following:
    
    if (v[mid] > elem){ // 1) update end (search left half)
        end = mid - 1;
    }
    else if (v[mid] < elem){ // 2) update start (search right half)
        start = mid + 1;
    }
    else{ // 3) return mid (found the elem)
        return mid;
    }

    //return a recursive call to binarySearch(..) 
    return binarySearch(v, start, end, elem);
}

/**
 * @brief update v to contain the values from filename (leave as is)
 * 
 * It is expected that the files contain values ranging from one to
 * one hundred million in ascending order (no duplicates).
 * 
 * @param filename : string
 * @param v : vector
 */
void vecGen(string filename, vector<int> &v){
    ifstream file(filename);
    int num;
    v.clear();
    while(file.is_open() && file >> num){
        v.push_back(num);
    }
    file.close();
}

int main(){
    // populate v with 1000 sorted number (leave as is)
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    // test elements to search for (leave as is)
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    cout << "Iterative Search" << endl;
    // read through all 10 of the test_elem values and calls iterative search
    // and record how long each search took (leave as is)
    for(int i = 0; i < elem_to_find.size(); i++){
        //gets the elem to search for
        int elem = elem_to_find[i];

        // stopwatches the time
        clock_t start = clock(); // start time
        int index_if_found = iterativeSearch(v, elem); // call search
        clock_t end = clock(); // end time

        // calculate the total time it took in seconds
        double elasp_time_in_sec = (double(end - start)/CLOCKS_PER_SEC);

        //print the index and how long it took to find it
        cout << index_if_found << ": " << elasp_time_in_sec << endl;
    }

    cout << endl << "Binary Search" << endl;

    // repeat the for loop above so that it records the time
    // it takes for binarySearch to do the same operation
    for(int i = 0; i < elem_to_find.size(); i++){
        //gets the elem to search for
        int elem = elem_to_find[i];

        // stopwatches the time
        clock_t start = clock(); // start time
        int index_if_found = binarySearch(v, 0, v.size()-1, elem); // call search
        clock_t end = clock(); // end time

        // calculate the total time it took in seconds
        double elasp_time_in_sec = (double(end - start)/CLOCKS_PER_SEC);

        //print the index and how long it took to find it
        cout << index_if_found << ": " << elasp_time_in_sec << endl;
    }
}