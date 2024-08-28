#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
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

void find_sum_in_sorted_array(vector<int>& vec,int sum,int& index1,int& index2)
{
  index1=0;
  index2=vec.size()-1;
  while (index1 < index2)  
  {
    if ( vec[index1] + vec[index2] == sum) 
       return;
    if ( vec[index1] + vec[index2] > sum )
       index2--;
    if ( vec[index1] + vec[index2] < sum )
       index1++;
  }
  index1=index2=-1;
  return;
}

int search_for_value(const vector<int>& vec,int value)
{
  for(int i=0;i < vec.size();i++) 
     if( vec[i] == value) return i;
  return -1;
}



int main()
{ 
  
  vector<int> myvector = {10,2,5,1,-10,1,30};
  vector<int> myvector_copy{myvector}; // O(n) space complexity and O(n) runtime complexity
  int sum=32;
  cout << "The array before: ";
  print_pretty_array(myvector);
  cout << " Sum: " << sum << "\n";
  // O(nlog(n)) run time complexity
  sort(myvector.begin(),myvector.end());
  cout << "The array after sort: ";
  print_pretty_array(myvector);
  cout << "\n";
  int index1,index2;
  find_sum_in_sorted_array(myvector,sum,index1,index2);
  if (index1 == -1 && index2 == -1) 
     cout << "The array after does not include two number the sum up to  " << sum << endl;
  else
  {
    int orig_index1 = search_for_value(myvector_copy,myvector[index1]); // O(n) run time complexity
    int orig_index2 = search_for_value(myvector_copy,myvector[index2]); // O(n) run time complexity
    
    cout << myvector[index1]  << " + " << myvector[index2] << "= " << sum << "\n";
    cout << "index1: " << orig_index1 +1 << " index2: " << orig_index2 +1 << endl;
  }
  // total run time complexity O(nlog(n))+O(n)+O(n)+O(n) = O(nlog(n))
  // space complexity O(n) 
  return 0;
      

}



