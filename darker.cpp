#include<iostream>
#include<fstream>
#include<chrono>
using namespace std;

int n = 75000;
int arr[75000];

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
// A function to implement bubble sort  
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}

void optimizedBubbleSort(int arr[], int n) 
{ 
   int i, j; 
   bool swapped; 
   for (i = 0; i < n-1; i++) 
   { 
     swapped = false; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j] > arr[j+1]) 
        { 
           swap(&arr[j], &arr[j+1]); 
           swapped = true; 
        } 
     } 
  
     // IF no two elements were swapped by inner loop, then break 
     if (swapped == false) 
        break; 
   } 
} 

void timeBubbleSort(string inputFilePath){
    ifstream infile;
    infile.open(inputFilePath);
    
    for(int i=0;i<n;i++){
        infile>>arr[i];
       
    }

    auto start = chrono :: steady_clock :: now();

    
    bubbleSort(arr,n);
    

    auto end = chrono :: steady_clock :: now();

    
    cout << "Time taken to sort "<<inputFilePath<<" using unoptimized bubble sort is "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " milliseconds"<<endl;
    
}

void timeoptimizedBubbleSort(string inputFilePath){
    ifstream infile;
    infile.open(inputFilePath);
    
    for(int i=0;i<n;i++){
        infile>>arr[i];
    }

    auto start = chrono :: steady_clock :: now();

    
    optimizedBubbleSort(arr,n);
    

    auto end = chrono :: steady_clock :: now();

    
    cout << "Time taken to sort "<<inputFilePath<<" using optimized bubble sort is "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " milliseconds"<<endl;
    
}



int main(){
    
    
    timeBubbleSort("ascending.dat");
    timeBubbleSort("descending.dat");
    timeBubbleSort("random.dat");
    timeoptimizedBubbleSort("ascending.dat");
    timeoptimizedBubbleSort("descending.dat");
    timeoptimizedBubbleSort("random.dat");
    

    return 0;
}
