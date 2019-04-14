// In case of tie for registers we are giving prioritity to the order in pages arrived in a particular clock cycle

#include<bits/stdc++.h>
#include<stdio.h>
#include <iostream>
#include <cstdlib>
#include <chrono> 
#include <set>
#include<utility>
#include<time.h>

using namespace std;
using namespace std::chrono; 
									
int page_faults=0;


int LRU_Page_Replace(int f,int Register[], int frames[])
{	
	int min=Register[frames[0]];
	int position=0;
	int position2=0;
	//printf(" %d ", min);
	for(int i=1;i<f;i++)							
	{
		//printf(" %d ", Register[frames[i]]);
		if(Register[frames[i]]<min)
		{
			min=Register[frames[i]];							//relative_time++;
			position=frames[i];	
			position2=i;							
		}
	}
	//printf("\t");
	for(int i=0;i<f;i++)	
	//printf(" %d ",frames[i]);
	//printf("\t i= %d\n", position2);
	//printf("pos : %d\n",position);
	return position2;								
}	
	
void shift(int Register[], int reg)
{
	for (int i = 1; i <= reg; ++i) {
        Register[i] = (Register[i] >> 1);
    }
}

void LRU_Policy(int frames[], int f,int Register[],int reg,int pages[], int p, int hit_t, int miss_t,int clock, int reg_len)
{
	int new_page=1,replace=1,pos=0;				
	int hit_time = hit_t;
	int miss_time = hit_t + miss_t ;
	for(int i=0;i<f;i++)
	{
		frames[i]=-1;								//relative_time++;
	}

	for(int i=0;i<reg;i++)
	{
		Register[i]=0; //This is the aging register value associated to the frames
	}

	int time = 0;

	for(int page_c = 0; page_c < p ; page_c++)
	{
		if(time >= clock)
		{
			time = time - clock ;
			shift(Register, reg) ;
		}
// COMMENT THESE LINES
			for(int k=0;k<f;k++)
			{
				if(frames[k]!=-1)
				{
					printf("%d ",frames[k]);			//relative_time++;
				}
				
			}
			printf("\n");
// UPTO HERE	
			
			new_page=1;									
			replace=1;									

			for(int j=0;j<f;j++)
			{

				if(frames[j]==pages[page_c])		//ie. if the input is already there in the buffer
				{	
					time = time + hit_time ;
					//Register[frames[j]]=Register[frames[j]]+1024;
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
						time = time + miss_time;
						page_faults++;
						//printf("%d \n",pages[page_c]);
						frames[j]=pages[page_c];
						//Register[frames[j]]+=1024;
						replace=0;
							break;

						}
					}
				}

				if(replace==1)
				{
					pos=LRU_Page_Replace(f,Register,frames);
					time = time + miss_time ;		
					page_faults++;
					//printf("%d \n",pages[page_c]);
					frames[pos]=pages[page_c];
					//Register[frames[pos]]+=1024;
				}

				Register[pages[page_c]] |= (1 << (reg_len - 1));

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
	int hit_t = 1;
	int miss_t = 3;
	int reg_len = 5;
	int clock = 9;
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
  	p=pages_v.size();

  	int h=0;
		set<int> no_of_distinct_pages;
	//set set.size-> number of registers
  	for(int i=0; i<p;i++)
  	{
  		pages[i]=pages_v[i];						//relative_time++;
			no_of_distinct_pages.insert(pages[i]);
  	}
	
	int Register[no_of_distinct_pages.size()+1]={0};
  	printf("Contents of Frame: \n");
  	LRU_Policy(frames,f,Register,no_of_distinct_pages.size()+1,pages,p,hit_t,miss_t,clock,reg_len);

  	

 	auto stop = high_resolution_clock::now(); 
  	auto duration = duration_cast<microseconds>(stop - start); 
 	printf("Time taken : %d microseconds \n", duration.count());
  	//printf("Time Relative taken (number of times inside for loop ) : %d \n", relative_time);



}
