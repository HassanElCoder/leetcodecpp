#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int search_for_local_maximum(const vector<int>& vec,vector<int>& max_indexes)
{
  max_indexes.clear();
  if ( vec[0] > vec[1] ) max_indexes.push_back(0);
  for(int i=1;i < vec.size()-1;i++) 
     if( (vec[i] > vec[i-1]) && (vec[i] > vec[i+1]) ) max_indexes.push_back(i) ;
  if ( vec[vec.size()-1] > vec[vec.size()-2] ) max_indexes.push_back(vec[vec.size()-1]);
  return max_indexes.size();
}

int sum_traped_water(const vector<int>& vec,vector<int>& max_indexes)
{
  if (max_indexes.size() <= 1) return 0;
  int total_trapped_water=0;
  int total_water_in_bin=0;
  for(int i=0;i < max_indexes.size()-1;i++)
  {
    int deltax= max_indexes[i+1] - max_indexes[i] - 1 ;
    int deltay =  min(vec[max_indexes[i+1]],vec[max_indexes[i]]);
    total_water_in_bin= deltax*deltay;
    for(int j=max_indexes[i]+1;j < max_indexes[i+1];j++)
          total_water_in_bin -= vec[j];
    total_trapped_water +=  total_water_in_bin;
  }
  return  total_trapped_water;
}

      


int main()
{ 
  
  vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
  vector<int> max_indexes{}; 
  search_for_local_maximum(vec,max_indexes);
  
  int total_trapped_water = sum_traped_water(vec,max_indexes);
  cout << "Total Trapped water: " << total_trapped_water << endl ;

  return 0;
      

}



