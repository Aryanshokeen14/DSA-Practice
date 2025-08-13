#include<iostream>
using namespace std;

// Recursive function to count substrings starting from index 'start'
int countSubstrings(string str, int start, int end) {
    // Base case: if start has crossed the last index
    if (start == str.size()) return 0;

    int count = 0;

    // Check all substrings starting at 'start' and ending at 'end'
    for (int i = start; i < str.size(); i++) {
        if (str[start] == str[i]) {
            count++;
        }
    }

    // Recursive call to move to next starting index
    return count + countSubstrings(str, start + 1, end);
}

int main() {
    string str = "abacsdcs";
    int count = countSubstrings(str, 0, str.size() - 1);
    cout << "Total substrings starting and ending with same character: " << count << endl;
    return 0;
}
