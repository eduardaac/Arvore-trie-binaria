#include <iostream>
using namespace std;
#include "trie.h"

int main()
{

    Trie t;
    cout << "Inserindo valores..." << endl;
    t.insert("0101");
    t.insert("1101");
    t.insert("1010");
    cout << endl;
    cout << "O valor '1101' encontra-se na arvore ? " << t.search("1101") << endl;
    cout << "O valor '1100' encontra-se na arvore ? " << t.search("1100") << endl;
    cout << endl;
    cout << "Removendo valores..." << endl;
    t.remove("1101");
    cout << "O valor '1101' encontra-se na arvore ? " << t.search("1101") << endl;

    return 0;
}