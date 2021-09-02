#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Functions.h"

using namespace std;

struct combinations_vector
{
    vector <int> coins_combination;
    int coins_value; //value of all coins in combination
    int number_of_coin;
};

void print_single_combination(vector <int> *single_combination_Pointer)
{
    
    int l = (*single_combination_Pointer).size();
    if(l != 0)
    {
        cout << '{' << (*single_combination_Pointer).at(0);
        for(int u = 1; u < l; u++)
        {
            cout << " ," << (*single_combination_Pointer).at(u);
        }
        cout << '}' << endl;
    }
    else return;
}

int value_of_combination(vector <int> combination)
{
    int v = 0;
    int combination_size = combination.size();
    for(int j = 0; j < combination_size; j++)
    {
        v = v + combination.at(j);
    }
    return v;
}
// this function could be considered as adding one coin to the combination
void propagate_forward_function(int added_coin, int *Value_pointer, vector <int> *single_combination_Pointer, int *depthPointer)
{
    (*Value_pointer) = (*Value_pointer) + added_coin;
    (*single_combination_Pointer).push_back(added_coin);
    (*depthPointer) = (*depthPointer) + 1;
}

// this function could be considered as taking one coin back from the combination
void propagate_back_function(int added_coin, int *Value_pointer, vector <int> *single_combination_Pointer, int *depthPointer)
{
    (*depthPointer) = (*depthPointer) - 1;
    (*Value_pointer) = (*Value_pointer) - added_coin;
    (*single_combination_Pointer).pop_back();
}

//This function is the core of recurension in algorithm used in this program, it uses propagation forward and backward functions from above
void propagate_function(int end_value, int *Value_pointer, vector <combinations_vector> *combinations_vector_Pointer, vector <int> *single_combination_Pointer, int *depthPointer, int *minPointer)
{
    //case in which coins combination is ok
    if((*Value_pointer) == end_value) 
    {
        int x = value_of_combination(*single_combination_Pointer);
        int y = (*single_combination_Pointer).size();
        (*combinations_vector_Pointer).push_back({(*single_combination_Pointer), x, y}); //adding the proper combination
        if((*minPointer) > (*depthPointer)) 
        {
            (*minPointer) = (*depthPointer);
        }
        else return;
    }

    //case in which size of considered combination is bigger or equal than size of the shortest proper combination which was already found
    // this reduces combination space to radius of the smallest found combinations
    if(  (*depthPointer) >= (*minPointer) ) 
    {
        return;
    }

    //case in which combination value is smaller than chosen value
    //in this case additional coin is added and propagate_function explore the next step in combination space
    if(  (*Value_pointer) < end_value )
    {
        // coin with value 4
        propagate_forward_function(4, Value_pointer, single_combination_Pointer, depthPointer);
        propagate_function(end_value, Value_pointer, combinations_vector_Pointer, single_combination_Pointer, depthPointer, minPointer);
        propagate_back_function(4, Value_pointer, single_combination_Pointer, depthPointer);
        // coin with value 3
        propagate_forward_function(3, Value_pointer, single_combination_Pointer, depthPointer);
        propagate_function(end_value, Value_pointer, combinations_vector_Pointer, single_combination_Pointer, depthPointer, minPointer);
        propagate_back_function(3, Value_pointer, single_combination_Pointer, depthPointer);
        // coin with value 1
        propagate_forward_function(1, Value_pointer, single_combination_Pointer, depthPointer);
        propagate_function(end_value, Value_pointer, combinations_vector_Pointer, single_combination_Pointer, depthPointer, minPointer);
        propagate_back_function(1, Value_pointer, single_combination_Pointer, depthPointer);
    }

    //case in which combination value is bigger than chosen value, propagation is going backwards
    if((*Value_pointer) > end_value)
    {
        return;
    }
}
