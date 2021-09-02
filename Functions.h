#include <iostream>
#include <vector>

using namespace std;

struct combinations_vector;
int value_of_combination(vector <int> combination); //this function returns the sum of all coins in considered combination
void print_single_combination(vector <int> *single_combination_Pointer);

//This functions could be considered as operators, which can explore the abstract space of all coins combinations,
// also they represents adding and taking back one coin
void propagate_forward_function(int added_coin, int *Value_pointer, vector <int> *single_combination_Pointer, int *depthPointer); // adding one coin
void propagate_back_function(int added_coin, int *Value_pointer, vector <int> *single_combination_Pointer, int *depthPointer); // taking one coin back

//This function is the core of recurension in algorithm used in this program, it uses propagation forward and backward functions from above
void propagate_function(int end_value, int *Value_pointer, vector <combinations_vector> *combinations_vector_Pointer, vector <int> *single_combination_Pointer, int *depthPointer, int *minPointer);


