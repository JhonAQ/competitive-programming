#include<iostream>

using namespace std;

int main(){
  for(int i = 0; i < 1000000000; i++){
    (i & 1);
  }
}
