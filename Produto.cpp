#include "Produto.h"

#include <iostream>

Produto::Produto(string nome, double preco) : nome(nome), preco(preco) {
}

Produto::~Produto() {
}

string Produto::getNome() {
    return this->nome;
}

double Produto::getPreco() {
    return this->preco;
}

void Produto::imprimir() {
    cout << this->nome << " - " << this->preco << " reais" << endl;
}
