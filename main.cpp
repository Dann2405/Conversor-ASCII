#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// prototipo da função para ler o arquivo e separar os bits em grupos de 8 bits
vector<string> separarBits(const string& arquivo);

// Função para converter um grupo de 8 bits em número decimal
int binarioParaDecimal(const string &binario);

// Função que fará a conversão de decimal para ASCII
void conversaoDecimalASCII(const string& arquivo);

int main()
{
    string arquivo = "../input.txt"; // nome do arquivo
    vector<string> grupos = separarBits(arquivo); // chama a função para separar os bits

    for(const string& grupo : grupos) // loop para imprimir os grupos de 8 bits
    {
        cout << grupo << endl; // imprime os grupos de bits
    }

    // Chama a função de conversão para binário -> decimal -> ASCII
    conversaoDecimalASCII(arquivo); 

    return 0;
}

vector<string> separarBits(const string& arquivo)
{
    vector<string> gruposBits; // vetor para armazenar os grupos de bits
    ifstream infile(arquivo); // ler o arquivo

    if(!infile.is_open()) // verifica se o arquivo foi não aberto
    {
        cout << "Erro ao abrir o arquivo" << endl;
        return gruposBits; // retorna o vetor vazio
    }

    string bits; // string para armazenar os bits
    infile >> bits; // ler os bits do arquivo

    for(size_t i = 0; i < bits.size(); i += 8) // loop para separar os bits em grupos de 8 bits
    {
        if (i + 8 <= bits.size()) // verifica se o grupo de bits tem 8 bits
        {
            gruposBits.push_back(bits.substr(i, 8)); // separa os bits em grupos de 8 bits.
        }
        else // caso contrario, imprime uma mensagem de erro
        {
            cerr << "Erro: O arquivo nao possui um numero inteiro de bytes, ignorando os ultimos bits" << endl;
        }
    }

    return gruposBits; // retorna os grupos de bits
}

// Função que converte de binário para decimal 
int binarioParaDecimal(const string &binario) {
    int decimal = 0;
    for (int i = 0; i < 8; ++i) {
        if (binario[i] == '1') {
            decimal += (1 << (7 - i)); // Calcula a potência de 2 para cada bit '1'
        }
    }
    return decimal;
}

// Função que converte de decimal para ASCII
void conversaoDecimalASCII(const string& arquivo) {
    vector<string> grupos = separarBits(arquivo); // Chama a função separarBits para obter os grupos de 8 bits

    stack<int> pilhaDecimal; // Pilha para armazenar os números decimais

    // Para cada grupo de 8 bits, converte para decimal e para ASCII
    for (const string& grupo : grupos) {
        // Converte o grupo binário para decimal
        int decimal = binarioParaDecimal(grupo);

        // Converte o valor decimal para o caractere ASCII correspondente
        char caractere = static_cast<char>(decimal);

        // Exibe o valor binário, o decimal e o caractere ASCII correspondente
        cout << "Binario: " << grupo << " -> Decimal: " << decimal << " -> Caractere ASCII: " << caractere << endl; // a nível de entendimento

        pilhaDecimal.push(decimal); // Empilha o valor decimal
    }
}
