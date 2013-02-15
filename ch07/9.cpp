#include<iostream>
#include <cstring>


using namespace std;



void enc(char *text, char *key)
{
    int text_len = strlen(text);
    int key_len = strlen(key);

    for (int i = 0; i < text_len; i++)
    {
        text[i] = text[i] ^ key[i % key_len];
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "command argument with key string" << endl;
        return 1;
    }

    char *key = argv[1];

    cout << "key:" << key << endl;

    char text[100];
    
    while (1)
    {
        cin >> text;

        enc(text, key);

        cout << "enc=" << text << endl;

        enc(text, key);
        cout << "dec=" << text << endl;
    }
}

