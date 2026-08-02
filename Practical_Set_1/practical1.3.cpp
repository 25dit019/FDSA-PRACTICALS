#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence;

    cout << "Enter a sentence:\n";
    getline(cin, sentence);

    string word = "";
    string longest = "";

    for(int i=0; i<=sentence.length(); i++)
    {
        if(i == sentence.length() || sentence[i] == ' ')
        {
            if(word.length() > longest.length())
            {
                longest = word;
            }

            word = "";
        }
        else
        {
            word += sentence[i];
        }
    }

    cout << "Longest Word: " << longest << endl;
    cout << "Length: " << longest.length();

    return 0;
}
