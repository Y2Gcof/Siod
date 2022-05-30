#include <iostream>
#include <fstream>
#include <string>
using namespace std;
# define NO_OF_CHARS 256
void badC(string str, int size, int bad_char[NO_OF_CHARS])
{
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
        bad_char[i] = -1;
    for (i = 0; i < size; i++)
        bad_char[(int) str[i]] = i;
}
void search( string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int bad_char[NO_OF_CHARS];

    badC(pat, m, bad_char);

    int s = 0;
    while(s <= (n - m))
    {
        int j = m - 1;
        while(j >= 0 and pat[j] == txt[s + j])
            j--;
        if (j < 0)
        {
            cout << "element = " <<  s << endl;
            break;
        }
        else
            s += max(1, j - bad_char[txt[s + j]]);
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    string sf;
    ifstream file("book.txt");
    if(!file.is_open()) {
        cout<<"Er";
        return 0;
    }
    string txt;
    while(getline(file,txt)){
        sf+=txt;
    }
    cin>>txt;
    search(sf,txt);
    return 0;
}