# OS_COURSE_PROJECT

# Problem Statement: 

Implement the following algorithms in C or C++ without using existing/predefined classes. 

i. LRU - Counter Method
ii. LRU - Stack Method
iii. LRU - Aging Register Method
iv. Apprx. LRU - Clock Method

Compare the contrast the results by testing the algorithms with different corner cases. 

Draw the graph for the number of frames vs. the number of page faults. 

Draw the graph for the average time taken to execute the algorithms for different corner cases. 

Perform the complexity analysis.

Write your comments/critical analysis/study report on your results and complexity. 

# How to run:

TO run

1.	g++ <filename>.cpp -o <executable_file_name>
2.	./<executable_file_name> number_of_frames \directory\<input_file>.txt

Example: 
	1. 	g++ LRU_counter.cpp -o LRU_counter
	2. 	./LRU_counter 4 TEST_CASES\test2.txt

# Time complexities of each algo:

LRU_counter.cpp 	-> 	time complexity= O(Total number of frames * size of page stream ) i.e. O(f*p)
LRU_Stack.cpp 		-> 	time complexity= O(Total number of frames * Page Faults ) i.e. O(f*p_f) (conisdering unordered_map performance ot be O(1))
App_LRU_Clock_Algo.cpp	->	time complexity= O((frames + additional_cost) * size of page stream ) i.e. O((f+s_c)*p) (additional cot for maintaing the clock and giving 2nd chance
