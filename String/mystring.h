#pragma warning(disable:4996)
#ifndef MYSTRING
#define MYSTRING
#include<cstring>
#include<iostream>
using namespace std;
class String
{
public:
	String(const char* str = 0);
	String(const String& str);
	String& operator= (const String& str);
	char* get_pstr() const { return mstr; };
	~String()
	{
		delete[] mstr;
	}
private:
	char* mstr;
	friend String operator+(const String& str1, const String& str2);
};
inline String::String(const char* str)
{
	if (str)
	{
		mstr = new char[strlen(str) + 1];
		strcpy(mstr, str);
	}
	else
	{
		mstr = new char[1];
		*mstr = '\0';
	}
}
inline String::String(const String& str)
{
	mstr = new char[strlen(str.mstr) + 1];
	strcpy(mstr, str.mstr);
}
inline String& String::operator=(const String& str)
{
	if (this == &str)
		return *this;
	delete[] mstr;
	mstr = new char[strlen(str.mstr) + 1];
	strcpy(mstr, str.mstr);
	return *this;
}
ostream& operator<<(ostream& os, const String& str)
{
	os << str.get_pstr();
	return os;
}
String operator+(const String& str1, const String& str2)
{
	String str;
	str.mstr = new char[strlen(str1.mstr) + strlen(str2.mstr) + 1];
	char* current = str.mstr, *current1=str1.mstr,*current2=str2.mstr;
	while (*current1 != '\0')
	{
		*current = *current1;
		current++;
		current1++;
	}
	while (*current2!='\0')
	{
		*current = *current2;
		current++;
		current2++;
	}
	*current = '\0';
	return str;
}
#endif