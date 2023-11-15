#include <iostream>
#include "Produto.h"
#include "Pedido.h"
#include "PersistenciaDeProduto.h"
using namespace std;

void teste1() {
    Produto* P1 = new Produto("Lasanha", 20);
    Produto* P2 = new Produto("Batata", 5);
    PersistenciaDeProduto* test = new PersistenciaDeProduto("teste1.txt");
    
    test->inserir(P1);
    test->inserir(P2);

    delete P1;
    delete P2;
}

void teste2() {
    PersistenciaDeProduto* newTest = new PersistenciaDeProduto("teste2.txt");

    try{
        Pedido* newPed = new Pedido(10);
        newPed = newTest->obter();
        
        if(newPed != NULL){
            newPed->imprimir();
        }
        delete newPed;
    }catch(invalid_argument *e){
        cout << e->what() << endl;
        delete e;
    }catch(logic_error *e){
        cout << e->what() << endl;
        delete e;
    }
    delete newTest;
}