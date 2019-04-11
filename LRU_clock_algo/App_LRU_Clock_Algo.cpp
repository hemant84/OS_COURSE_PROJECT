#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;   

int page_faults=0;

int LRU_Page_Replace(int target, int f, int frames[][2]){

   for (int i = 0; i < f; ++i){
        if (*frames[i] == target)
            return i;
   }

  return -1;

}

void LRU_Policy(int &pointer,int f, vector<int> pages,int frames[][2], int i )
{
    int pos = LRU_Page_Replace(pages[i], f, frames);

        if (pos == -1)
        {
            bool replaced = false;
            while(!replaced){
                if (frames[pointer][1] == 0)
                {
                    frames[pointer][0] = pages[i];
                    frames[pointer][1] = 1;
                    replaced = true;
                    page_faults++;
                }

                else
                    frames[pointer][1]--;

                pointer=(pointer+1)%f;
            }
        }

        else {
            frames[pos][1] = 1;
        }

// COMMENT THESE LINES 
        for(int k=0;k<f;k++)
        {
            printf("%d ", frames[k][0]);
        }
        printf("\t -> \t");
        for(int k=0;k<f;k++)
        {
            printf("%d ",frames[k][1]);
        }

        printf("\n");

//UPTO HERE
}

int main(int argc, char *argv[])
{

    auto start = high_resolution_clock::now(); 

    int f = atoi(argv[1]);
    vector<int> pages ;

    int frames[f][2];
    string line;
    int pointer=0;

    for (int i = 0; i < f; ++i){
        frames[i][0] = -1;
        frames[i][1] = 0;
    }

    ifstream page_stream(argv[2]);
     if (page_stream.fail()){
        fprintf(stderr, "Error Reading File.\n");
        return -1;
    }

    if (page_stream.is_open())                    
    {
    
        while (!page_stream.eof() )                
        {
        
              getline(page_stream,line);            //relative_time++;
              pages.push_back(stoi(line));
        }
        //pages.push_back(stoi(line));

        page_stream.close();                 
    }

    printf("Contents of Frame: \n");

    for(int i=0;i<pages.size();i++)
    {

        LRU_Policy(pointer,f,pages,frames,i);

    }


    printf("Total Page Faults: %d\n", page_faults);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    printf("Time taken : %d microseconds \n", duration.count());

    return 0;

}