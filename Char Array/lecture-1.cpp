#include <iostream>
#include <cstring>
using namespace std;
int getLength(char name[])
{
    int length = 0;
    int i = 0;

    while (name[i] != '\0')
    {
        length++;
        i++;
    }

    return length;
}

int reverseCharArray(char name[])
{
    int i = 0;
    int n = getLength(name);

    int j = n - 1;
    while (i <= j)
    {
        swap(name[i], name[j]);
        i++;
        j--;
    }

    return 0;
}

void replaceSpaces(char sentence[])
{
    int i = 0;
    int n = strlen(sentence);

    for (int i = 0; i < n; i++)
    {
        if (sentence[i] == ' ')
        {
            sentence[i] = '@';
        }
    }
}

bool checkPalindrome(char word[])
{
    int i = 0;
    int n = strlen(word);
    int j = n - 1;

    while (i <= j)
    {
        if (word[i] != word[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }

    return true;
}

int main()
{
    char name[100];

    cin >> name;

    // 	cout << " length is : "<< getLength(name) << endl;
    // 	cout << " length is : "<< strlen(name) << endl;

    // 	cout << "Initially : "<< name << endl;
    // 	reverseCharArray(name);

    // 	cout << "After reverse aaray  : "<< name << endl;

    char sentence[100];

    cin.getline(sentence, 100);
    replaceSpaces(sentence);

    cout << " printing sentence " << endl
         << sentence << endl;
    return 0;
}