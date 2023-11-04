/*
We define super digit of an integer  using the following rules:

Given an integer, we need to find the super digit of the integer.

If  has only  digit, then its super digit is .
Otherwise, the super digit of  is equal to the super digit of the sum of the digits of .
For example, the super digit of  will be calculated as:

	super_digit(9875)   	9+8+7+5 = 29 
	super_digit(29) 	2 + 9 = 11
	super_digit(11)		1 + 1 = 2
	super_digit(2)		= 2  
Example


The number  is created by concatenating the string   times so the initial .

    superDigit(p) = superDigit(9875987598759875)
                  9+8+7+5+9+8+7+5+9+8+7+5+9+8+7+5 = 116
    superDigit(p) = superDigit(116)
                  1+1+6 = 8
    superDigit(p) = superDigit(8)
All of the digits of  sum to . The digits of  sum to .  is only one digit, so it is the super digit.

Function Description

Complete the function superDigit in the editor below. It must return the calculated super digit as an integer.

superDigit has the following parameter(s):

string n: a string representation of an integer
int k: the times to concatenate  to make 
Returns

int: the super digit of  repeated  times
Input Format

The first line contains two space separated integers,  and .

Constraints

Sample Input 0

148 3
Sample Output 0

3
Explanation 0

Here  and , so .

super_digit(P) = super_digit(148148148) 
               = super_digit(1+4+8+1+4+8+1+4+8)
               = super_digit(39)
               = super_digit(3+9)
               = super_digit(12)
               = super_digit(1+2)
               = super_digit(3)
               = 3
Sample Input 1

9875 4
Sample Output 1

8
Sample Input 2

123 3
Sample Output 2

9
Explanation 2

Here  and , so .

super_digit(P) = super_digit(123123123) 
               = super_digit(1+2+3+1+2+3+1+2+3)
               = super_digit(18)
               = super_digit(1+8)
               = super_digit(9)
               = 9
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

int superDigit(string n, int k) {

        long long int initialSum = 0;
    for(char c : n) {
        initialSum += (c - '0');
    }

    // Initial sum for the number n repeated k times
    initialSum *= k;

    // Now find the super digit of initialSum
    while(initialSum >= 10) {
        long long int sum = 0;
        while(initialSum > 0) {
            sum += initialSum % 10;
            initialSum /= 10;
        }
        initialSum = sum;
    }

    return initialSum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    string n = first_multiple_input[0];

    int k = stoi(first_multiple_input[1]);

    int result = superDigit(n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}