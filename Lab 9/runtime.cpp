#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

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
int binarySearch(vector<int> & v, int start, int end, int elem){
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

/**
 * @brief write to file the time it took to search with respect to the 
 * size of the vector n
 * Number of Element(n)     Time(micro sec)
 * XXXX                     X.XXXXX
 * XXXX                     X.XXXXX
 * 
 * @param filename (string) : filename (e.g. output_1000_numbers.cvs)
 * @param time (vector<double>) : average time
 * @param n (vector<int>) : size of vectors
 */
void writeTime(string filename, const vector<double> times, const vector<int>n){
    ofstream myFile(filename);

    myFile << "Number of Elements (n)\t Time (micro sec) " << endl;
    for(int i = 0; i < times.size(); i++){
        myFile << n[i] << "\t" << times[i] << "\n";
    }
    myFile.close();
    cout << "Wrote to " << filename << endl;
}

/**
 * @brief computes the average of the elements in vector, a
 * 
 * @param a vector of double
 * @return double 
 */
double average(const vector<double> a){
    double total = 0;

    for(int i = 0; i < a.size(); i++){
        total += a[i];
    }

    double average = total / a.size();
    return average;
}

int main(){
    // test elements to search for
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);
    // size (n) of all tests
    vector<int> file_size;
    vecGen("sizes.csv", file_size);

    // n list of numbers
    vector<int> v;

    // result of times
    vector<double> times;

    // result of average time
    vector<double> avg;
    
    // crate a for loop to iterate through the file size
    for(int i = 0; i < file_size.size(); i++){
        // get the name/size of the file and assign it to string called filename
        string filename = to_string(file_size[i]) + "_numbers.csv";
        // call vecGen on filename and v
        vecGen(filename, v);

        // print filename (this will be good for debugging)
        cout << filename << endl;

        // call time.clear() //this ensures that we reset times everytime we read a new file
        times.clear();
        
        // create another for loop to iterate through all the element from elem_to_find.
        for(int i = 0; i < elem_to_find.size(); i++){
            // the code here should be nearly identical to the code from the previous lab
            int elem = elem_to_find[i];

            auto start = high_resolution_clock::now();
            int index_if_found = iterativeSearch(v, elem);
            auto end = high_resolution_clock::now(); 

            auto elapsed_time_in_sec = duration_cast<microseconds>(end - start);
            
            // append the elapsed_time_in_sec to the vector, times (hint: push_back())
            // This code should be within the for loop that iterates
            //through all the elements from elem_to_find
            times.push_back(elapsed_time_in_sec.count());
        }
        
        // outside the for loop that iterate through all the elements from elem_to_find
        // but within the for loop that iterate through the file sizes
        // call average on the vector, times, and save it as a double. This code should be
        // outside the for loop that iterates through all the elements from elem_to_find
        // but within the for loop that iterate the file sizes
        double avg_time = average(times);
        
        // append the double to avg. (hint: push_back())
        // This code should be outside the for loop that iterate through 
        // all elements from elem_to_find
        // but  within the for loop that iterates through the file sizes
        avg.push_back(avg_time);
    }

    // outside both for loops calls witeTimes with the appropriate parameters
    // the first parameter should be "iterativeSearch_times.csv"
    // read the function briefto complete the rest of the parameters
    writeTime("iterativeSearch_times.csv", avg, file_size);

    // call avg.clear() to reset avg, so we can use it for binarySearch
    avg.clear();

    // repeat the nested for loops used iterativeSearch, but call binarySearch instead
    // create another for loop to iterate through all the element from elem_to_find.
    for(int i = 0; i < file_size.size(); i++){
        // get the name/size of the file and assign it to string called filename
        string filename = to_string(file_size[i]) + "_numbers.csv";
        // call vecGen on filename and v
        vecGen(filename, v);

        // print filename (this will be good for debugging)
        cout << filename << endl;

        // call time.clear() //this ensures that we reset times everytime we read a new file
        times.clear();
        
        // create another for loop to iterate through all the element from elem_to_find.
        for(int i = 0; i < elem_to_find.size(); i++){
            // the code here should be nearly identical to the code from the previous lab
            int elem = elem_to_find[i];

            // measure run time
            auto start = high_resolution_clock::now();
            int index_if_found = binarySearch(v, 0, v.size()-1, elem);
            auto end = high_resolution_clock::now(); 

            // get elapsed time in sec
            auto elapsed_time_in_sec = duration_cast<microseconds>(end - start);

            // append time to the vector times
            times.push_back(elapsed_time_in_sec.count());
        }
        
        // outside the for loop that iterate through all the elements from elem_to_find
        // but within the for loop that iterate through the file sizes
        // call average on the vector, times, and save it as a double. This code should be
        // outside the for loop that iterates through all the elements from elem_to_find
        // but within the for loop that iterate the file sizes
        double avg_time = average(times);
        
        // append the double to avg. (hint: push_back())
        // This code should be outside the for loop that iterate through 
        // all elements from elem_to_find
        // but  within the for loop that iterates through the file sizes
        avg.push_back(avg_time);
    }

    // outside both for loops call writeTimes with the appropriate parameters
    // the first parameter should be "binarySearch_time.csv"
    // read the function brief to complete the rest of the parameters
    writeTime("binarySearch_time.csv", avg, file_size);

    return 0;
}