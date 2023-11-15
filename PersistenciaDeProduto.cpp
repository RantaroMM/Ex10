#include "PersistenciaDeProduto.h"
#include "Pedido.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;

PersistenciaDeProduto::PersistenciaDeProduto(string arquivo){
    this->arquivo = arquivo;
}

void PersistenciaDeProduto::inserir(Produto *Produto){
    ofstream output;

    output.open(arquivo, ios_base::app);

    output << Produto->getNome() << endl << Produto->getPreco() << endl;

    output.close();
}

Pedido* PersistenciaDeProduto::obter(){
    int quantidade = 0;
    double price;
    string name;
    Pedido* Ped = new Pedido(10);
    
    ifstream entrada;
    entrada.open ("teste2.txt");

    if(entrada.fail()) {
        throw new invalid_argument ("Erro de leitura");
    }

    entrada >> name >> price;
    while(entrada){
        quantidade++;
        Produto* P = new Produto(name, price);
        Ped->adicionar(P);
        entrada >> name >> price;
    }

    if(!entrada.eof()){
        throw new logic_error ("Arquivo com formatacao inesperada");
    }

    if(quantidade == 0){
        cout << "Arquivo vazio" << endl;
        return NULL;
    }

    
    return Ped;
}

PersistenciaDeProduto::~PersistenciaDeProduto(){

}