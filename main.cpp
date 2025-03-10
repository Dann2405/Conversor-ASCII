#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Protótipo da função para ler o arquivo e separar os bits em grupos de 8 bits
vector<string> separarBits(const string& arquivo);

// Função para converter um grupo de 8 bits em número decimal
int binarioParaDecimal(const string &binario);

// Função que fará a conversão de decimal para ASCII utilizando pilha
void conversaoDecimalASCII(const string& arquivo);

int main()
{
    string arquivo = "input.txt"; // Nome do arquivo
    
    // Chama a função de conversão para binário -> decimal -> ASCII e inverter
    conversaoDecimalASCII(arquivo); 

    return 0;
}

vector<string> separarBits(const string& arquivo)
{
    vector<string> gruposBits; // Vetor para armazenar grupos de bits
    ifstream file(arquivo);
    string bits;
    
    if (file.is_open()) {
        file >> bits;
        file.close();
    }

    for (size_t i = 0; i < bits.length(); i += 8) {
        gruposBits.push_back(bits.substr(i, 8));
    }
    
    return gruposBits;
}

int binarioParaDecimal(const string &binario)
{
    int decimal = 0;
    for (char bit : binario)
    {
        decimal = decimal * 2 + (bit - '0');
    }
    return decimal;
}

void conversaoDecimalASCII(const string& arquivo)
{
    vector<string> grupos = separarBits(arquivo);
    stack<char> pilha1, pilha2; // Duas pilhas para inverter a ordem corretamente
    string resultado; // String para armazenar o resultado final

    for (const string& grupo : grupos)
    {
        char caractere = static_cast<char>(binarioParaDecimal(grupo));
        pilha1.push(caractere); // Empilha o caractere convertido
    }
    
    // Desempilha da primeira pilha e empilha na segunda para inverter
    while (!pilha1.empty())/*  */
    {
        pilha2.push(pilha1.top());
        pilha1.pop();
    }
    
    // Agora desempilha da segunda pilha para formar a string correta
    while (!pilha2.empty())
    {
        resultado += pilha2.top();
        pilha2.pop();
    }
    
    cout << "Texto convertido: " << resultado << endl;
}
