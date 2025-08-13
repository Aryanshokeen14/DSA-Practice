#include <iostream>
#include <vector>
using namespace std;

void translate(const vector<int>& digits, int index, string current, vector<string>& result,
               const vector<string>& alpha)
{
    if (index == digits.size()) {
        result.push_back(current);
        return;
    }

    int number = digits[index];
    if (number < 2 || number > 9) return; // skip if digit has no mapping

    string letters = alpha[number];
    for (char ch : letters) {
        translate(digits, index + 1, current + ch, result, alpha);
    }
}

int main()
{
    int a = 23;
    vector<int> digits;
    int temp = a;

    // extract digits
    while (temp != 0) {
        digits.push_back(temp % 10);
        temp /= 10;
    }
    reverse(digits.begin(), digits.end());

    // digit to letter mapping
    vector<string> alpha = {
        "",     "",     "abc", "def", "ghi", 
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> result;
    translate(digits, 0, "", result, alpha);

    // print result
    for (const string& s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
} 
