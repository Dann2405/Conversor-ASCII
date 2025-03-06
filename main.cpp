#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// função para ler o arquivo e separar os bits em grupos de 8 bits
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

int main()
{
    string arquivo = "input.txt"; // nome do arquivo
    vector<string> grupos = separarBits(arquivo); // chama a função para separar os bits

    for(const string& grupo : grupos) // loop para imprimir os grupos de 8 bits
    {
        cout << grupo << endl; // imprime os grupos de bits
    }

    return 0;
}