#include <iostream>
#include "mystring.h"
using namespace std;
int main()
{
  String s1("hello "); //构造函数
  String s2("world");  //构造函数
  String s3(s2);       //拷贝函数
  cout << s3 << endl;  //输出符号重载
  s3 = s1;             //实现"="的重载
  cout << s3 << endl;
  cout << s1 + s2 << endl; //实现"+"的重载 效果为字符串拼接
  return 0;
}
