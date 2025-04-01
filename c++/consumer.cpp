#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

// 生产者-消费者模型，unique_lock和condition_variable实现线程间同步

// void producer(int *queue, int &head, int &tail, int &count, int size,
//               std::mutex &mtx, std::condition_variable &cv) {
//   for (int i = 0; i < 100; ++i) {                                //
//   增加循环次数
//     std::this_thread::sleep_for(std::chrono::milliseconds(100)); //
//     模拟生产时间 std::unique_lock<std::mutex> lock(mtx); cv.wait(lock, [&]()
//     { return count < size; }); // 等待队列不满 queue[tail] = i; tail = (tail
//     + 1) % size;
//     ++count;
//     cout << "Produced: " << i << " | Queue size: " << count << endl;
//     cv.notify_all(); // 通知消费者
//   }
// }

// void consumer(int *queue, int &head, int &tail, int &count, int size,
//               std::mutex &mtx, std::condition_variable &cv) {
//   for (int i = 0; i < 100; ++i) {                                //
//   增加循环次数
//     std::this_thread::sleep_for(std::chrono::milliseconds(200)); //
//     模拟消费时间 std::unique_lock<std::mutex> lock(mtx); cv.wait(lock, [&]()
//     { return count > 0; }); // 等待队列不空 int item = queue[head]; head =
//     (head + 1) % size;
//     --count;
//     cout << "Consumed: " << item << " | Queue size: " << count << endl;
//     cv.notify_all(); // 通知生产者
//   }
// }

// 自适应调节生产和消费速度
void producer(int *queue, int &head, int &tail, int &count, int size,
              std::mutex &mtx, std::condition_variable &cv) {
  for (int i = 0; i < 100; ++i) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [&]() { return count < size; }); // 等待队列不满

    queue[tail] = i;
    tail = (tail + 1) % size;
    ++count;
    cout << "Produced: " << i << " | Queue size: " << count << endl;

    // 根据队列状态动态调整生产速度
    int sleep_time = 100 + (count * 50); // 队列越满，生产越慢
    lock.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));

    cv.notify_all(); // 通知消费者
  }
}

void consumer(int *queue, int &head, int &tail, int &count, int size,
              std::mutex &mtx, std::condition_variable &cv) {
  for (int i = 0; i < 100; ++i) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [&]() { return count > 0; }); // 等待队列不空

    int item = queue[head];
    head = (head + 1) % size;
    --count;
    cout << "Consumed: " << item << " | Queue size: " << count << endl;

    // 根据队列状态动态调整消费速度
    int sleep_time = 200 - (count * 30); // 队列越空，消费越慢
    lock.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(max(50, sleep_time)));

    cv.notify_all(); // 通知生产者
  }
}

// // 只使用lock_guard实现生产者-消费者模型,会导致大量空转
// void producer(int *queue, int &head, int &tail, int &count, int size,
//               std::mutex &mtx, std::condition_variable &cv) {
//   for (int i = 0; i < 100; ++i) {                                //
//   增加循环次数
//     std::this_thread::sleep_for(std::chrono::milliseconds(100)); //
//     模拟生产时间 while (true) {
//       // std::this_thread::sleep_for(
//       //     std::chrono::milliseconds(50)); // 等待队列不空
//       if (count < size) {
//         std::lock_guard<std::mutex> lock(mtx);
//         // cv.wait(lock, [&]() { return count < size; }); // 等待队列不满
//         queue[tail] = i;
//         tail = (tail + 1) % size;
//         ++count;
//         cout << "Produced: " << i << " | Queue size: " << count << endl;
//         break;
//         // cv.notify_all(); // 通知消费者
//       }
//     }
//   }
// }
// void consumer(int *queue, int &head, int &tail, int &count, int size,
//               std::mutex &mtx, std::condition_variable &cv) {
//   for (int i = 0; i < 100; ++i) {                                //
//   增加循环次数
//     std::this_thread::sleep_for(std::chrono::milliseconds(200)); //
//     模拟消费时间 while (true) {
//       // std::this_thread::sleep_for(
//       //     std::chrono::milliseconds(50)); // 等待队列不空
//       if (count > 0) {
//         std::lock_guard<std::mutex> lock(mtx);
//         // cv.wait(lock, [&]() { return count > 0; }); // 等待队列不空
//         int item = queue[head];
//         head = (head + 1) % size;
//         --count;
//         cout << "Consumed: " << item << " | Queue size: " << count << endl;
//         break;
//         // cv.notify_all(); // 通知生产者
//       }
//     }
//   }
// }

int main() {
  const int size = 5; // 队列大小
  int queue[size];
  int head = 0;
  int tail = 0;
  int count = 0;

  std::mutex mtx;
  std::condition_variable cv;

  std::thread prod(producer, queue, std::ref(head), std::ref(tail),
                   std::ref(count), size, std::ref(mtx), std::ref(cv));
  std::thread cons(consumer, queue, std::ref(head), std::ref(tail),
                   std::ref(count), size, std::ref(mtx), std::ref(cv));

  prod.join();
  cons.join();

  return 0;
}
