#include<bits/stdc++.h>
#include<stdio.h>
#include <iostream>
#include <cstdlib>
#include <chrono> 

#define st list<int>::iterator
#define u_m unordered_map

using namespace std;
using namespace std::chrono;   
                                        
int page_faults=0;  

class LRUCache 
{ 
     
    list<int> stac; 
    u_m <int, st > info; 
    int frames; 
  
public: 
    LRUCache(int); 
    void policy(int); 
    void display(); 
}; 
  
LRUCache::LRUCache(int n) 
{ 
    frames = n; 
} 
  
void LRUCache::policy(int x) 
{
    if (info.find(x) == info.end()) 
    { 
        page_faults++; 
        if (stac.size() == frames) 
        {

            int last = stac.back(); 
            stac.pop_back(); 
            info.erase(last); 
        } 
    } 
 
    else
        stac.erase(info[x]); 

    stac.push_front(x); 
    info[x] = stac.begin();


// COMMENT THESE LINES 
    for(auto i=stac.begin();i!=stac.end();i++)
    {
        printf("%d ",(*i) );
    }
    printf("\n");

//UPTO HERE
    
} 

int main(int argc, char *argv[]) 
{   
    auto start = high_resolution_clock::now(); 

    //printf("A\n");
    
    int f=atoi(argv[1]);
    LRUCache frames_1(f);
    string line ;
    
    //printf("B\n");
    
    ifstream page_stream(argv[2]);
    if (page_stream.fail()){
        fprintf(stderr, "Error Reading File.\n");
        return -1;
    }
    printf("Contents of Frame: \n");
    if (page_stream.is_open())                    
    {
    
        while (!page_stream.eof() )                
        {
        
              getline(page_stream,line);            //relative_time++;
              frames_1.policy(stoi(line));
        }
        //frames_1.policy(stoi(line));

        page_stream.close();                 
    }
    

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    printf("Time taken : %d microseconds \n", duration.count());
    printf("Total Page Faults: %d\n", page_faults);
    //printf("Time Relative taken (number of times inside for loop ) : %d \n", relative_time);


    return 0; 
} 