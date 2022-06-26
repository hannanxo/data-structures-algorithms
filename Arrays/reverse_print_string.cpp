#include <iostream>
#include <string>
using namespace std;

void reverse(string word, int i)
{
    if ((word[i] + 1) == '\0')
    {
        return;
    }
    i++;
    reverse(word, i);
    cout << word[i];
}

int main()
{
    int i = 0;
    string word = "It is raining";
    reverse(word, i);
    return 0;
}
