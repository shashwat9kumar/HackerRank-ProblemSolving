/*



When you select a contiguous block of text in a PDF viewer, the selection is highlighted with a blue rectangle. In this PDF viewer, each word is highlighted independently. For example:

PDF-highighting.png

In this challenge, you will be given a list of letter heights in the alphabet and a string. Using the letter heights given, determine the area of the rectangle highlight in  assuming all letters are  wide.

For example, the highlighted . Assume the heights of the letters are  and . The tallest letter is  high and there are  letters. The hightlighted area will be  so the answer is .

Function Description

Complete the designerPdfViewer function in the editor below. It should return an integer representing the size of the highlighted area.

designerPdfViewer has the following parameter(s):

h: an array of integers representing the heights of each letter
word: a string
Input Format

The first line contains  space-separated integers describing the respective heights of each consecutive lowercase English letter, ascii[a-z].
The second line contains a single word, consisting of lowercase English alphabetic letters.

Constraints

, where  is an English lowercase letter.
 contains no more than  letters.
Output Format

Print a single integer denoting the area in  of highlighted rectangle when the given word is selected. Do not print units of measure.

Sample Input 0

1 3 1 3 1 4 1 3 2 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
abc
Sample Output 0

9
Explanation 0

We are highlighting the word abc:

Letter heights are ,  and . The tallest letter, b, is  high. The selection area for this word is .

Note: Recall that the width of each character is .

Sample Input 1

1 3 1 3 1 4 1 3 2 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 7
zaba
Sample Output 1

28
Explanation 1

The tallest letter in  is  at . The selection area for this word is .



*/






#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the designerPdfViewer function below.
int designerPdfViewer(vector<int> h, string word) {
    int max=0;
    int n=word.length();
    for(int i=0;i<n;i++)
    {
        int x=(int)(word[i]) -97;
        if(max<h[x])
        {
            max=h[x];
        }
    }
    int area=max*n;
    return area;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(26);

    for (int i = 0; i < 26; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    string word;
    getline(cin, word);

    int result = designerPdfViewer(h, word);

    fout << result << "\n";

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
