#include<iostream>
using namespace std;

int lengthOfLastWord(string s) 
{
	int c = 0;
	int length = s.length();
	for (int i = 0; i < length; i++)
	{
		if (s[(s.length() - 1) - i] != ' ')
		{
			c++;
		}
		else if (length > 0 && c > 0)
		{
			return c;
		}
	}
	
	return c;;
}

void main()
{
	string s = "qwe req qewrfasdf ";
	cout << lengthOfLastWord (s);
}