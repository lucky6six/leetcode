#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

int main() {
  for (int i = 0; i < 10; ++i) {
    int j = 1;
    
    std::cout << "Hello World!" << std::endl;
  }
}