/*字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。给定一个字符串
s 和一个正整数 k， 请编写一个函数，将字符串中的后面 k
个字符移到字符串的前面，实现字符串的右旋转操作。
例如，对于输入字符串 "abcdefg" 和整数 2，函数应该将其转换为 "fgabcde"。*/

//增加难度，不可额外申请空间，只能在原串上操作。O（1）不算
#include <algorithm>
#include <iostream>
//图示https://camo.githubusercontent.com/8616fd570a8e52f2abef0272ed732542cca0df7d4effdbe235fbd4c1798afe84/68747470733a2f2f636f64652d7468696e6b696e672d313235333835353039332e66696c652e6d7971636c6f75642e636f6d2f706963732f32303233313130363137323035382e706e67
using namespace std;
int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int len = s.size();          //获取长度
                               //左旋场景的话n换位len-n
  reverse(s.begin(), s.end()); // 整体反转，注意reverse函数的用法
  reverse(s.begin(), s.begin() + n); // 先反转前一段，长度n
  reverse(s.begin() + n, s.end());   // 再反转后一段

  cout << s << endl;
}