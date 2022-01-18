#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

bool emptyLine(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
			return false;
	}
	return true;

}

int characterCheck(string a)
{
	int x = 0,y=0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != ' '&&i+3<a.length())
		{
			string S;
			S = S + a[i];
			S = S + a[i+1];
			S = S + a[i+2];
			S = S + a[i+3];
			if (S == "char")
				x++;
		}
		if (x && a[i] == ',')
			y++;
	}
	if (x)
		y++;
	return y;
}

int bodycheck(string a)
{
	int i = 0;
	for (; i < a.length(); i++)
	{
		if (a[i] == ' ')
			break;
	}
	i--;
	if(i>0)
	return int(a[i]) - 48;
}

int floatCheck(string a)
{
	int x = 0, y = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != ' ' && i + 4 < a.length())
		{
			string S;
			S = S + a[i];
			S = S + a[i + 1];
			S = S + a[i + 2];
			S = S + a[i + 3];
			S = S + a[i + 4];
			if (S == "float")
				x++;
		}
		if (x && a[i] == ',')
			y++;
	}
	if (x)
		y++;
	return y;
}

int integerCheck(string a)
{
	int x = 0, y = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != ' ' && i + 2 < a.length())
		{
			string S;
			S = S + a[i];
			S = S + a[i + 1];
			S = S + a[i + 2];
			if (S == "int")
				x++;
		}
		if (x && a[i] == ',')
			y++;
	}
	if (x)
		y++;
	return y;

}


bool openBrackCheck(string A)
{
	for (int i = 0; i < A.length(); i++)
	{
		if (A[i] == '{')
			return true;
	}
	return false;
}
bool closeBrackCheck(string A)
{
	for (int i = 0; i < A.length(); i++)
	{
		if (A[i] == '}')
			return true;
	}
	return false;
}
string inttostring(int N)
{
	stringstream s1;
	s1 << N;
	string str = s1.str();
	return str;
}
int main()
{
	string a;
	string linebyline[200];
	int I = -1;
	cout << "Enter the name of file you want to read:";
	cin >> a;
	fstream read;
	read.open(a, ios::in);
	if (!read)
		cout << "Error opening File:\n";
	else
	{
		while(!read.eof())
		{
			I++;
			string A;
 		    getline(read, A);
		    linebyline[I] = A;
		}
	}
	//read.close();
	int LINE = -1,IN=0;



	for (int i = 0; i <= I; i++)
	{
		LINE++;
		stringstream s1,s2;
		s1 << LINE;
		string str = s1.str();
		s2 << IN;
		str=str+ s2.str();
		str = str + "  ";
		str = str + linebyline[i];
		linebyline[i] = str;
		linebyline[i] = linebyline[i] + '\n';
		if (openBrackCheck(linebyline[i]))
			IN++;
		if (closeBrackCheck(linebyline[i+1]))
			IN--;
	}



	string b;
	for (int i = 0; i < a.length()-3; i++)
	{
		b = b + a[i];
	}
	b = b + "out";
	cout << b;
	read.close();
	fstream ptr;
	ptr.open(b, ios::out);
	if (!ptr)
		cout << "Error opening File:\n";
	else
	{
		string Lines[5];
		Lines[0] = "Lines              =";
		Lines[1] = "Blank Lines        =";
		Lines[2] = "chars declared     =";
		Lines[3] = "ints declared      =";
		Lines[4] = "floats declared    =";

		int Chr = 0, In = 0, Fl = 0,BL=0;
		int chr = 0, in = 0, fl = 0,bl=0,li=0;
		int fuc = 0;
		for (int i = 0; i <= I; i++)
		{
			cout<< linebyline[i];
			ptr << linebyline[i];
			if (bodycheck(linebyline[i + 2])==1&&fuc==0)
			{
				fuc++;
				li++;
			}
			if (fuc == 3)
			{
				chr = chr + characterCheck(linebyline[i]);
				chr = chr + characterCheck(linebyline[i]);
				in = in + integerCheck(linebyline[i]);
				in = in + integerCheck(linebyline[i]);
				fl = fl + floatCheck(linebyline[i]);
				fl = fl + floatCheck(linebyline[i]);
				if (emptyLine(linebyline[i]))
				{
					BL++;
					bl++;
				}
			}
			else if(fuc<3&&fuc>0)
			{
				fuc++;
				li++;
			}
			if (fuc==3)
			{
				if (!bodycheck(linebyline[i]))
				{
					li++;
					cout << Lines[0] << inttostring(li) << endl;
					ptr << Lines[0] << inttostring(li) << endl;
					cout << Lines[1] << inttostring(bl) << endl;
					ptr << Lines[1] << inttostring(bl) << endl;
					cout << Lines[2] << inttostring(chr) << endl;
					ptr << Lines[2] << inttostring(chr) << endl;
					cout << Lines[3] << inttostring(in) << endl;
					ptr << Lines[3] << inttostring(in) << endl;
					cout << Lines[4] << inttostring(fl) << endl;
					ptr << Lines[4] << inttostring(fl) << endl;

					li = 0;
					chr = 0;
					bl = 0;
					in = 0;
					fl = 0;
					fuc = 0;
				}
			}

		}
	
		cout << Lines[0] << inttostring(I) << endl;
		ptr << Lines[0] << inttostring(I) << endl;
		cout << Lines[1] << inttostring(BL) << endl;
		ptr << Lines[1] << inttostring(BL) << endl;
		cout << Lines[2] << inttostring(Chr) << endl;
		ptr << Lines[2] << inttostring(Chr) << endl;
		cout << Lines[3] << inttostring(In) << endl;
		ptr << Lines[3] << inttostring(In) << endl;
		cout << Lines[4] << inttostring(Fl) << endl;
		ptr << Lines[4] << inttostring(Fl) << endl;

	
	}






	ptr.close();
	return 0;
}
