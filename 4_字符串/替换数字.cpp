#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
//将输入字符串中的数字替换为number
int main() {
  string s;
  while (cin >> s) {
    int count = 0; // 统计数字的个数
    int sOldSize = s.size();
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        count++;
      }
    }
    // 扩充字符串s的大小，也就是每个空格替换成"number"之后的大小，resize函数
    s.resize(s.size() + count * 5);
    int sNewSize = s.size();
    // 从后先前将空格替换为"number"
    //从后向前替换，可以in-place实现，不额外占用空间。（因为从前向后会覆盖未判定的char）
    for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
      if (s[j] > '9' || s[j] < '0') {
        s[i] = s[j];
      } else {
        s[i] = 'r';
        s[i - 1] = 'e';
        s[i - 2] = 'b';
        s[i - 3] = 'm';
        s[i - 4] = 'u';
        s[i - 5] = 'n';
        i -= 5;
      }
    }
    cout << s << endl;
  }
}