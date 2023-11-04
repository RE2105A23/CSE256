/*
Given a string, , we define some operations on the string as follows:

a. reverse(A)  denotes the string obtained by reversing string A. Example: reverese("abc") = "cba"


b. shuffle(A)  denotes any string that's a permutation of string A. Example: 
shuffle("god") = ['god','gdo','ogd','odg','dgo','dog']


c. merge(A1,A2) denotes any string that's obtained by interspersing the two strings A1 & A2, maintaining the order of characters in both. For example, A1="abc"  & A2="def", one possible result of merge(A1,A2) could be "abcdef", another could be "abcecf", another could be "abdecf" and so on.

Given a string s such that s = merge(reverse(A),shuffle(A)) for some string A, find the lexicographically smallest A.

For example, s=abab. We can split it into two strings of ab. The reverse is ba and we need to find a string to shuffle in to get abab. The middle two characters match our reverse string, leaving the a and b at the ends. Our shuffle string needs to be ab. Lexicographically ab<ba, so our answer is ab.

Function Description

Complete the reverseShuffleMerge function in the editor below. It must return the lexicographically smallest string fitting the criteria.

reverseShuffleMerge has the following parameter(s):

s: a string
Input Format

A single line containing the string .

Constraints

s contains only lower-case English letters, ascii[a-z]
a<=|s|<=1000

Output Format

Find and return the string which is the lexicographically smallest valid A.

Sample Input 0

eggegg
Sample Output 0

egg
Explanation 0

Split "eggegg" into strings of like character counts: "egg", "egg"
reverse("egg") = "gge"
shuffle("egg") can be "egg"
"eggegg" belongs to the merge of ("gge", "egg")

The merge is: eggegg.

'egg' < 'gge'

Sample Input 1

abcdefgabcdefg
Sample Output 1

agfedcb
Explanation 1

Split the string into two strings with like characters: abcdefg and abcdefg.
Reverse abcdefg = abcdefg
Shuffle gfedcba can be bcdefga
Merge to abcdefgabcdefg

Sample Input 2

aeiouuoiea
Sample Output 2

aeiou
Explanation 2

Split the string into groups of like characters: aeiou
Reverse aeiou = uoiea
These merge to aeiouuoiea
*/

/*
#include <bits/stdc++.h>

using namespace std;

static int wrd_count[26]={};
static int rem_count[26]={};
static int sol_count[26]={};
static char sol[10001];

// Hackerrank Reverse shuffle merge Solution
// Runs in O( n ^ 2) 
// ======== SOLUTION =========
string reverseShuffleMerge(string s){
    int n = s.size();
    int j = 0;
    const char* s_chars = s.c_str();
    
    for(int i = 0; i < n ; i++)
        wrd_count[s[i]-'a']++;
    
    memcpy(rem_count, wrd_count,26*(sizeof(int)) );
    
    for(int i = 0; i < 26 ; i++)
        wrd_count[i]/=2;
    
    char l_char;
    int  l_char_indx;
    
    for(int i = n-1; i >= 0; i--){
        
        l_char = s_chars[i];
        l_char_indx = l_char - 'a';
        if(i == n-1){
            sol[j] = l_char;
            j++;
            rem_count[l_char_indx]--;
            sol_count[l_char_indx]++;
            continue;
        }
        
        if(sol_count[ l_char_indx ] < wrd_count[l_char_indx]){
            
            if( l_char >= sol[j-1] ){
                sol[j] = l_char;
                j++;
                rem_count[l_char_indx]--;
                sol_count[l_char_indx]++;
            }else{
                while( j>0 && (l_char < sol[j-1]) && sol_count[sol[j-1]-'a']-1+ rem_count[sol[j-1]-'a'] >= (wrd_count[sol[j-1]-'a'])){
                    sol_count[sol[--j]-'a']--;
                }
                sol[j] = l_char;
                j++;
                rem_count[l_char_indx]--;
                sol_count[l_char_indx]++;
            }
            
        }else{
            rem_count[l_char_indx]--;
        }
        
        
    }
    
    sol[j] = '\0';

    string sol_str(sol);
    
    return sol_str;
    
}

// ======== HACKERRANK's Template =========

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
*/


#include <bits/stdc++.h>
using namespace std;

string reverseShuffleMerge(string s) {
    int n = s.size();
    vector<int> wrd_count(26, 0);
    vector<int> rem_count(26, 0);
    vector<int> sol_count(26, 0);
    string sol;

    // Count the frequency of each character in s
    for (char c : s) {
        wrd_count[c - 'a']++;
    }

    // Initialize rem_count and halve wrd_count for our needs
    rem_count = wrd_count;
    for (int &count : wrd_count) {
        count /= 2;
    }

    // Iterate through the string in reverse
    for (int i = n - 1; i >= 0; --i) {
        char l_char = s[i];
        int l_char_indx = l_char - 'a';

        // If we still need this character, attempt to add it to the solution string
        if (sol_count[l_char_indx] < wrd_count[l_char_indx]) {
            // Remove any characters that are larger and can be moved to a later position
            while (!sol.empty() && l_char < sol.back() &&
                   sol_count[sol.back() - 'a'] + rem_count[sol.back() - 'a'] > wrd_count[sol.back() - 'a']) {
                sol_count[sol.back() - 'a']--;
                sol.pop_back();
            }
            sol.push_back(l_char);
            sol_count[l_char_indx]++;
        }
        // Decrement the remaining count for this character
        rem_count[l_char_indx]--;
    }

    return sol;
}

int main() {
    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    cout << result << "\n";

    return 0;
}