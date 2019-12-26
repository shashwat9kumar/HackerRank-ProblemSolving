/*


Given a sequence of  integers,  where each element is distinct and satisfies . For each  where , find any integer  such that  and print the value of  on a new line.

For example, assume the sequence . Each value of  between  and , the length of the sequence, is analyzed as follows:

, so 
, so 
, so 
, so 
, so 
The values for  are .

Function Description

Complete the permutationEquation function in the editor below. It should return an array of integers that represent the values of .

permutationEquation has the following parameter(s):

p: an array of integers
Input Format

The first line contains an integer , the number of elements in the sequence.
The second line contains  space-separated integers  where .

Constraints

, where .
Each element in the sequence is distinct.
Output Format

For each  from  to , print an integer denoting any valid  satisfying the equation  on a new line.

Sample Input 0

3
2 3 1
Sample Output 0

2
3
1
Explanation 0

Given the values of , , and , we calculate and print the following values for each  from  to :

, so we print the value of  on a new line.
, so we print the value of  on a new line.
, so we print the value of  on a new line.
Sample Input 1

5
4 3 5 1 2
Sample Output 1

1
3
5
4
2


*/








#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int index(vector<int> p, int ele)
{
    int n=p.size();
    for(int i=0;i<n;i++)
    {
        if(p[i]==ele)
        return (i+1);
    }
    return -1;
}

// Complete the permutationEquation function below.
vector<int> permutationEquation(vector<int> p) {
    int n=p.size();
    vector<int> arr;
    for(int i=1;i<=n;i++)
    {
        int loc1=index(p,i);
        int loc2=index(p,loc1);
        arr.push_back(loc2);
    }
    return arr;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    vector<int> result = permutationEquation(p);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
