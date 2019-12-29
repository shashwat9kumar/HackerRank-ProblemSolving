/*


The previous challenges covered Insertion Sort, which is a simple and intuitive sorting algorithm with a running time of . In these next few challenges, we're covering a divide-and-conquer algorithm called Quicksort (also known as Partition Sort). This challenge is a modified version of the algorithm that only addresses partitioning. It is implemented as follows:

Step 1: Divide
Choose some pivot element, , and partition your unsorted array, , into three smaller arrays: , , and , where each element in , each element in , and each element in .

For example: Assume 
The pivot is at 
 is divided into , , and .
Putting them all together, you get . Another valid solution is .

Given  and , partition  into , , and  using the Divide instructions above. Then print each element in  followed by each element in , followed by each element in  on a single line. Your output should be space-separated and does not have to maintain ordering of the elements within the three categories.

Function Description

Complete the quickSort function in the editor below. It should return an array of integers as described above.

quickSort has the following parameter(s):

arr: an array of integers where  is the pivot element
Input Format

The first line contains , the size of the array .
The second line contains  space-separated integers describing  (the unsorted array). The first integer (corresponding to ) is your pivot element, .

Constraints

 where 
All elements will be unique.
Output Format

On a single line, print the partitioned numbers (i.e.: the elements in , then the elements in , and then the elements in ). Each integer should be separated by a single space.

Sample Input

5
4 5 3 7 2
Sample Output

3 2 4 5 7
Explanation

 Pivot: .
; ; 

, so it's added to .
; ; 

, so it's added to .
; ; 

, so it's added to .
; ; 

, so it's added to .
; ; 

We then print the elements of , followed by , followed by , we get: 3 2 4 5 7.

You don't need to maintain ordering, so another valid solution would be 2 3 4 5 7.



*/










#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the quickSort function below.
vector<int> quickSort(vector<int> arr)
{
    vector<int> left;
    vector<int> right;
    int n=arr.size();
    int pivot=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]<pivot)
        {
            left.push_back(arr[i]);
        }
        else if(arr[i]>pivot)
        {
            right.push_back(arr[i]);
        }
    }
    int nl=left.size();
    int nr=right.size();
    vector<int> arraypart;
    for(int i=0;i<nl;i++)
    {
        arraypart.push_back(left[i]);
    }
    arraypart.push_back(pivot);
    for(int i=0;i<nr;i++)
    {
        arraypart.push_back(right[i]);
    }
    return arraypart;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = quickSort(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
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
