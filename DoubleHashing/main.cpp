//METHOD 2


#include <iostream>
#include <fstream>
#include<ctime>
using namespace std;


const int arraySize = 4000037;
long long arrayMain[arraySize];

long checkNum(long num){
    
    num = abs(num % arraySize);
    
    return num;
}

long firstCol(long num, int j){

    num = checkNum(num) + j*( 4000035 - (num %  4000035));
    
    return num;
    }

int main() {
    long long temporary = 0;
    long long position;
    int counter = 0;
    ifstream in;
    
    in.open("progr3-data-set.txt");
    
    clock_t begin = clock();
    for (int i=0; i<arraySize; i++) {
        arrayMain[i] = 0;
    }
    
    for (int i = 0; i < 1000000; i++) {
        in >> temporary;
        
        position = checkNum(temporary);
        
        if (arrayMain[position] == 0)
        {
        
            arrayMain[position] = temporary;
        }
        else if (arrayMain[position] != 0)
        {
            int j = 1;
            while (arrayMain[position] != 0) {
                position = firstCol(temporary,j)%arraySize;
                j++;

            }
            arrayMain[position] = temporary;
            
            }
        
        
        }
    
    for (int i=0; i<arraySize; i++) {
        if (arrayMain[i] != 0)
        {
            counter ++;
        }
      
        
       
    }
    for (int i=0; i<arraySize; i++) {
        cout <<arrayMain[i]<<endl;
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout <<"Time Taken: " << elapsed_secs << " Seconds" <<endl;
    cout << counter << " values stored" << endl;
    
    in.close();
    
    return 0;
}
