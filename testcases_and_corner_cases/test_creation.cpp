#include<bits/stdc++.h>
#include<stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	int r=rand()%5 * 10 + 50;
	string line ;
	ofstream page_stream ;
	page_stream.open("test6.txt");
	   int p=rand()%(rand()%10 + 5);
		page_stream<<to_string(p);
	   for(int i=0;i<r;i++)            
	    {
	    	  int p=rand()%(rand()%10 + 5);
		      page_stream<<"\n"<<to_string(p);
		}
		page_stream.close();                 
  
}