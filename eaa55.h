/*****
PURPOSE:
Created by: Edward Aryee
On 02/23/2014
Version Number: 1.0
Last Revised on: 02/23/2014
*****/

using namespace std;

static string promptForString(string prompt);
void delay(double seconds);
template <class T>
void exchange(T & x, T & y);
string findReplace(string input, string delimiter, string fillIn);

static string promptForString(string prompt)
{
	string answer;
	cout << prompt << endl;
	cin >> answer;

	return answer;
}

void delay(double seconds)
{
	clock_t time1 = clock();
	clock_t time2 = clock();

	while(time2-time1 < seconds*1000)
	{
		time2 = clock();
	}
}

template <class T>
void exchange(T & x, T & y)
{
	T temp = x;
	x = y;
	y = temp;
}

string findBetweenReplace(string input, string delimiter, string fillIn)
{
	int delimiterStart = input.find(delimiter);
	int delimiterEnd = input.find(delimiter, delimiter+1);
	string beforeDelimiter, afterDelimiter, newString;
	bool fillingIn = true;
	int replacedCount;
	``	
	while(delimiterStart != -1)
	{	
	beforeDelimiter = input.substr(0, delimiterStart);
	afterDelimiter = input.substr(delimiterEnd+delimiter.length(), (input.length()-delimiterEnd+delimiter.length()));

	newString = beforeDelimiter + " " + fillIn + " " + afterDelimiter;
	
	delimiterStart = input.find(delimiter);
	delimiterEnd = input.find(delimiter, delimiterStart+1);
	replacedCount ++;
	}

	return newString;
}
string findReplace(string input, string delimiters, string fillIn)
{
	int position, count;

	while(position > -1)
	{
	position = input.find_first_of(delimiters);
	input.replace(position, delimiters.length(), fillin);
	}

	return input;
}

int countDelimiter(string input, string delimiters)
{
}