#include <vector>
#include <iostream>

using namespace std;


int DeleteDuplicates(vector<int>& sorted_array)
{    
  if (sorted_array.empty()) return 0;
  int index=0;
  for(int i=0; i < sorted_array.size();i++)
	if(sorted_array[i] != sorted_array[index])
	{
	  index++;
	  sorted_array[index]= sorted_array[i];
	}	
  //optional remove all to the right of index in the vector
  if (index < sorted_array.size()-1)
      sorted_array.erase (sorted_array.begin()+index+1,sorted_array.end());
  
  // return the new number of elements after deletion
  return sorted_array.size();
}

void print_pretty_array(const vector<int>& vec)
{
  if (vec.empty())
  {   
   cout << "{}";
   return;
  }
   
  cout << "{";
  for (int i=0; i < vec.size()-1;i++)
      cout << vec[i] << "," ;

  cout <<  vec[vec.size()-1] << "}";
  return;
}
    


int main()
{  
  vector<int> myvector = {1,1,1,6,7,8,8,8,9};
  cout << "The array before: ";
  print_pretty_array(myvector);

  int newsize = DeleteDuplicates(myvector);
  cout << "\n";
  cout << "The array after: ";
  print_pretty_array(myvector);
  cout << " length= " << newsize << endl;
  return 0;
}



