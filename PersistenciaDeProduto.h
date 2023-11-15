#ifndef PERSISTENCIA_DE_PRODUTO_H
#define PERSISTENCIA_DE_PRODUTO_H

#include "Produto.h"
#include "Pedido.h"
#include <string>
using namespace std;

class PersistenciaDeProduto {

protected:
    string arquivo;
public:
    PersistenciaDeProduto(string arquivo);
    virtual ~PersistenciaDeProduto();

    void inserir(Produto *produto);
    Pedido* obter();
};
#endif