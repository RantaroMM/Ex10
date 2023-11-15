#include "Pedido.h"

#include <iostream>

Pedido::Pedido(int quantidadeMaxima) : quantidadeMaxima(quantidadeMaxima), quantidade(0)
{
    this->produtos = new Produto *[quantidadeMaxima];
}

Pedido::~Pedido()
{
    for (int i = 0; i < quantidade; i++)
        delete this->produtos[i];

    delete this->produtos;
}

Produto **Pedido::getProdutos()
{
    return this->produtos;
}

int Pedido::getQuantidadeDeProdutos()
{
    return this->quantidade;
}

int Pedido::getQuantidadeMaximaDeProdutos()
{
    return this->quantidadeMaxima;
}

double Pedido::getPrecoTotal()
{
    double total = 0;
    for (int i = 0; i < this->quantidade; i++)
        total += this->produtos[i]->getPreco();

    return total;
}

bool Pedido::adicionar(Produto *prod)
{
    if (this->quantidade >= this->quantidadeMaxima)
        return false;

    this->produtos[this->quantidade++] = prod;
    return true;
}

void Pedido::imprimir()
{
    cout << "Pedido com " << this->quantidade << " produto(s) - " << this->getPrecoTotal() << " reais no total" << endl;
    for (int i = 0; i < this->quantidade; i++)
        this->produtos[i]->imprimir();
}
