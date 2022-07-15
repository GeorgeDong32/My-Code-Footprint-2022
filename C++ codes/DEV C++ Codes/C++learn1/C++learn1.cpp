#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<int> vec;
  for(int i = 0; i < 5 ; i ++){
  	vec.push_back((i+1));
  }

  auto vec2 = vec;
  //sort(vec.begin(), vec.end());
  sort(vec2.begin(), vec2.end(), [](auto a, auto b){return a > b;});

    for (int i = 0; i < 5; i ++){
        cout << vec[i] << " " ;
    }
    cout << endl;

    for (int i = 0; i < 5; i ++){
        cout << vec2[i] << " " ;
    }
    cout << endl;

}
