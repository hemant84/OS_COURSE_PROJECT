#include<bits/stdc++.h>
#include<stdio.h>
#include <iostream>
#include <cstdlib>
#include <chrono> 

int relative_time =0 ;

using namespace std;
using namespace std::chrono; 

int page_time=0;										
int page_faults=0;									

int LRU_Page_Replace( int counter[], int c)
{
	int min=counter[0];								
	int position=0;									

	for(int i=0;i<c;i++)							
	{
		if(counter[i]<min)
		{
			min=counter[i];							//relative_time++;
			position=i;								
		}
	}

	return position;								
}

void LRU_Policy(int frames[], int f, int counter[], int c,int pages[], int p)
{

	int new_page=1,replace=1,pos=0;					

	for(int i=0;i<f;i++)
	{
		frames[i]=-1;								//relative_time++;
	}

	for(int i=0;i<f;i++)
	{
		counter[i]=0;								//relative_time++;
	}

	for(int i=0;i<p;i++)
	{

// COMMENT THESE LINES 
		for(int k=0;k<f;k++)
		{
			if(frames[k]!=-1)
			{
				printf("%d ",frames[k]);			//relative_time++;
			}
			
		}
		printf("\n");

//UPTO HERE
		// for(int i=0;i<f;i++)
		// {
		// 	printf("%d ",counter[i] );
		// }
		// printf("\n");
		new_page=1;									
		replace=1;									

		for(int j=0;j<f;j++)
		{
			if(frames[j]==pages[i])
			{
				page_time++;						//relative_time++;
				counter[j]=page_time;
				new_page=0;
				replace=0;
				break;	
			}
		}

		if(new_page==1)
		{
			for(int j=0;j<f;j++)
			{
				if(frames[j]==-1)
				{
					page_time++;					//relative_time++;
					page_faults++;
					frames[j]=pages[i];
					counter[j]=page_time;
					replace=0;
					break;

				}
			}
		}

		if(replace==1)
		{
			pos=LRU_Page_Replace(counter,c);		
			page_time++;
			page_faults++;
			frames[pos]=pages[i];
			counter[pos]=page_time;
		}
	}

	printf("\nTotal Page Faults: %d\n", page_faults);

}

int main(int argc, char *argv[])
{
// To measure time:
	auto start = high_resolution_clock::now(); 

	//printf("A\n");
	
	int f=atoi(argv[1]);
	int p=0;
	vector<int> pages_v;
	string line ;
	
	//printf("B\n");
	
	ifstream page_stream(argv[2]);
	if (page_stream.fail()){
        fprintf(stderr, "Error Reading File.\n");
        return -1;
    }

  	if (page_stream.is_open())                    
  	{
  	
	    while (!page_stream.eof() )                
	    {
	    
		      getline(page_stream,line);        	//relative_time++;
		      pages_v.push_back(stoi(line));
		}
		pages_v.push_back(stoi(line));

		page_stream.close();                 
  	}


  	int pages[pages_v.size()];
  	int frames[f];
  	int counter[f];
  	int c=f;
  	p=pages_v.size();

  	int h=0;

  	for(int i=0; i<p;i++)
  	{
  		pages[i]=pages_v[i];						//relative_time++;
  	}
  	printf("Contents of Frame: \n");
  	LRU_Policy(frames,f,counter,c,pages,p);

  	

  	auto stop = high_resolution_clock::now(); 
  	auto duration = duration_cast<microseconds>(stop - start); 
  	printf("Time taken : %d microseconds \n", duration.count());
  	//printf("Time Relative taken (number of times inside for loop ) : %d \n", relative_time);



}