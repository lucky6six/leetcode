#include <iostream>
#include <mutex>
#include <thread>
// #include <syncstream>
#include <string>
using namespace std;

// 多线程同时访问cout会导致输出混乱，如：
//  thread running test 1
//  thread running thread running thread running test 4test 3

void threadFunction_0(string message) {
  cout << "thread running " << message << endl;
  return;
}

// 法一：加锁
void threadFunction(string message) {
  //static的作用是保证mtx在多线程中只会被创建一次，也可以直接使用全局锁，区别是
  // 全局锁会在main函数结束后被销毁，而static锁会在main函数结束后仍然存在
  static mutex mtx;
  // mtx.lock();
  // cout << "thread running " << message << endl;
  // mtx.unlock();
  // 优化，自动加锁
  lock_guard<mutex> lock(mtx);
  cout << "thread running " << message << endl;
  return;
}

// // 法二：osyncstream（c++20的自动同步输出流）
// void threadFunction(string message) {
//   std::osyncstream(std::cout) << "thread running " << message << std::endl;
//   return;
// }


int main() {
  // create thread : content , args
  std::thread t(threadFunction, "test 1");
  std::thread t2(threadFunction, "test 2");
  std::thread t3(threadFunction, "test 3");
  std::thread t4(threadFunction, "test 4");
  t.join();  // wait for thread t end;
  t2.join(); // wait for thread t2 end;
  t3.join(); // wait for thread t3 end;
  t4.join(); // wait for thread t4 end;
  // t.detach(); // detach thread t,main can finish
  return 0;
}