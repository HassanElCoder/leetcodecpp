#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


void print_code(const vector<string>& vec)
{
  for (auto e : vec)
  {
    cout << e << "\n";
  }
  return;
}

void get_gray_code(int n,vector<string>& vec)
{
  if ( n == 0) 
  {  
    vec.clear();
    return;
  }
  if (n == 1)
  {
    vec.push_back(string("0"));
    vec.push_back(string("1"));
    return;
  }
  // solve the problem for gray code of length n-1
  get_gray_code(n-1,vec);
  int vec_size= vec.size();
  // go over all gray codes of size n-1 and create a gray code of size n
  // by adding 0 as first bit. Add them to the end of the vector
  for(int i=0; i < vec_size ;i++)
    vec.push_back(string("0")+vec[i]);
  // go over the gray code of size n-1 backward and add 1 as first bit 
  // add them to the end of the vector
  for(int i=vec_size-1; i >=0; i--)
    vec.push_back(string("1")+vec[i]);
  // now remove the n-1 gray code from the front of the vector
  vec.erase(vec.begin(),vec.begin()+vec_size);
  return;  
}
      


int main()
{ 
  vector<string> vec;
  get_gray_code(4,vec);
  print_code(vec);
  return 0;

}



