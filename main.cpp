#include <iostream>
#include <stdio.h>
#include <stdlib.h> // atoi
#include <string>
#include <cstdlib> // exit(0) 
#include <vector>
#include "Functions.h"

using namespace std;

struct combinations_vector
{
    vector <int> coins_combination;
    int coins_value; //value of all coins in combination
    int number_of_coin;
};

int main(int argc, char* argv[])
{
	//checking if any parameter was used, if not program returns information about it and closing itself
	if (argc==1)
	{
		cout << "Some number needed to run this program. Please enter it when running the program. " << endl;
		exit(0);
	}


	int V = atoi(((string)argv[1]).c_str()); //chosen number
	int cv = 0; //current value

	vector <int> single_Comb; // vector to store single combination

	vector <combinations_vector> CombVec; // vector witch will contain all proper combinations

	int min = V; //number which monitors the size of smallest proper combination

	int depth = 0; // initial depth

	//exploring the space of combination, reduced to radius of the smallest combination size
	propagate_function(V, &cv, &CombVec, &single_Comb, &depth, &min);



	/////////////////////////////////////
	//printing the shortest saved combinations 

	cout << "The shortest combination(s): " << endl;
	int x = CombVec.size(); //number of all saved combinations
	for(int j =0; j < x; j++)
	{	
		int y = (CombVec.at(j)).coins_combination.size();
		if(y == min) //without this limit all saved combinations would be printed, not only the shortest ones
		{
			cout << "Combination " << j+1 << ": {";
			for(int k =0; k < y; k++)
			{
				if (k==0) 
				{	
					cout << (CombVec.at(j)).coins_combination.at(0);
				}
				else if((k > 0)&(k != y-1)) 
				{
					cout << ", " << (CombVec.at(j)).coins_combination.at(k);
				}
				else cout << " ," << (CombVec.at(j)).coins_combination.at(y-1);
			}
			cout << '}' << endl;
		}
	}
}
