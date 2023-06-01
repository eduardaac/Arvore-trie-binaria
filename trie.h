
#include <iostream>
using namespace std;

struct Node
{
    Node *bitZero; // ponteiro para o bit zero
    Node *bitUm;   // ponteiro para o bit um
    bool ehFinal;  // indica se o nó representa o final de uma chave

    Node()
    {
        bitZero = nullptr;
        bitUm = nullptr;
        ehFinal = false;
    }
};

class Trie
{
private:
    Node *root;

    void auxRemove(Node *atual, string key, int profundidade)
    {
        int tam = key.size();
        if (profundidade == tam)
        {
            atual->ehFinal = false;
            return;
        }

        char c = key[profundidade];
        if (c == '0')
        {
            if (atual->bitZero == nullptr)
                return;
            auxRemove(atual->bitZero, key, profundidade + 1);

            // Remove o nó se não tiver filhos e não for o final de outra chave
            if (!atual->bitZero->ehFinal && atual->bitZero->bitZero == nullptr && atual->bitZero->bitUm == nullptr)
            {
                delete atual->bitZero;
                atual->bitZero = nullptr;
            }
        }
        else if (c == '1')
        {
            if (atual->bitUm == nullptr)
                return;
            auxRemove(atual->bitUm, key, profundidade + 1);

            // Remove o nó se não tiver filhos e não for o final de outra chave
            if (!atual->bitUm->ehFinal && atual->bitUm->bitZero == nullptr && atual->bitUm->bitUm == nullptr)
            {
                delete atual->bitUm;
                atual->bitUm = nullptr;
            }
        }
    }

public:
    Trie()
    {
        root = new Node();
    }

    void remove(string key)
    {
        auxRemove(root, key, 0);
    }

    void insert(string key)
    {
        Node *atual = root;
        for (char c : key)
        {
            if (c == '0')
            {
                if (atual->bitZero == nullptr)
                    atual->bitZero = new Node();
                atual = atual->bitZero;
            }
            else if (c == '1')
            {
                if (atual->bitUm == nullptr)
                    atual->bitUm = new Node();
                atual = atual->bitUm;
            }
        }
        atual->ehFinal = true;
    }

    bool search(string key)
    {
        Node *atual = root;
        for (char c : key)
        {
            if (c == '0')
            {
                if (atual->bitZero == nullptr)
                    return false;
                atual = atual->bitZero;
            }
            else if (c == '1')
            {
                if (atual->bitUm == nullptr)
                    return false;
                atual = atual->bitUm;
            }
        }
        return atual->ehFinal;
    }
};