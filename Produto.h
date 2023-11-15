#ifndef PROD_H
#define PROD_H

#include <string>

using namespace std;

class Produto {
private:
    string nome;
    double preco;

public:
    Produto(string nome, double preco);
    ~Produto();

    string getNome();
    double getPreco();

    void imprimir();
};

#endif // PROD_H