#include <QCoreApplication>
#include <bits/stdc++.h>
#include <algorithm> // for sort()

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {
    sort(arr.begin(), arr.end());
    long minSum=0, maxSum=0;

    for(int i=0; i<4; i++){
        minSum += arr[i];
        maxSum += arr[(arr.size() - (i+1))];
    }
    cout<<minSum<<"  "<<maxSum;



}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string arr_temp_temp = "1 2 3 4 5 8 9 7 6";
    //getline(cin, arr_temp_temp);
    int numbers = 9;
    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(numbers);

    for (int i = 0; i < numbers; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

    cout<<"\n\n out of Function in Main \n\n";

    return a.exec();
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
