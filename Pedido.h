#ifndef Pedido_H
#define Pedido_H

#include "Produto.h"

class Pedido
{
private:
    Produto **produtos;
    int quantidadeMaxima;
    int quantidade;

public:
    Pedido(int quantidadeMaxima);
    ~Pedido();

    Produto **getProdutos();
    int getQuantidadeDeProdutos();
    int getQuantidadeMaximaDeProdutos();
    double getPrecoTotal();

    bool adicionar(Produto *produto);

    void imprimir();
};

#endif // Pedido_H
