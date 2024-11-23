#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;



int minimum_candy(vector<int>& rating)
{
  
  // sort children according to rating from low to high rating
  sort(rating.begin(),rating.end());
  int candy_gift=1,total_candy=1,current_max=rating[0];
  for(int i=1; i < rating.size();i++)
     if (rating[i] > current_max)
     { 
       candy_gift += 1;
       total_candy += candy_gift;
       current_max=rating[i];

     }
     else  total_candy += candy_gift;  
  return total_candy;
}
      


int main() {
  
    
    vector<int> ratings = {4, 6, 4, 5, 6, 2};
    cout << "Test Input: ";
    for (int r : ratings) cout << r << " ";
    cout << "\n";
    int result = minimum_candy(ratings);
    cout << "Output: " << result << "\n\n";

    return 0;
}





