#include <QCoreApplication>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {


    int positiveNumberCount = 0, negativeNumberCount = 0, zeroNumberCount = 0;
    for (int i = 0; i < arr.size(); i++) {
        if(arr[i]>0){
            positiveNumberCount++;
        }
        else if(arr[i]<0){
            negativeNumberCount++;
        }
        else {
            zeroNumberCount++;
        }
    }

    cout<<setprecision(6)<<(float)(positiveNumberCount/(float)arr.size())<<endl;
    cout<<setprecision(6)<<(negativeNumberCount/(float)arr.size())<<endl;
    cout<<setprecision(6)<<(zeroNumberCount/(float)arr.size())<<endl;

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string n_temp = "6";
    //getline(cin, n_temp);

    int n = std::stoi(ltrim(rtrim(n_temp)));
    string arr_temp_temp = "-4 3 -9 0 4 1";
    //getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < arr_temp.size(); i++) {
        int arr_item = std::stoi(arr_temp[i]);
        //cout<<i<<" -> "<<arr_item<<endl;
        arr[i] = arr_item;
    }

    plusMinus(arr);


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
    cout<<"Split:: "<<str<<endl;
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
