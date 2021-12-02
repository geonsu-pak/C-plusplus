## number to string
<pre>
#include < stream>
#include < string>

int num = 100;
ostringstream str1;
str1 << num;
string strno = str1.str();
</pre>
<pre>
#include < string>
int inum = 20;
float fnum = 20.2;

string stri = to_string(inum);
string strf = to_string(fnum);
</pre>

## string to number
<pre>
#include < sstream>

string str = "123";
stringstream ss(str);
// stringstream ss;
// ss << str; // or int, float, double

int x = 0;
ss >> x;
</pre>
<pre>
#include < stdio.h >

const char *str = "123";
int x;
sscanf(str, "%d", &x)
</pre>
<pre>
#include < string >

string str = "123";
int num = stoi(str)
</pre>
<pre>
#include < cstdlib >

const char *str = "123";
int num = atoi(str);
</pre>
