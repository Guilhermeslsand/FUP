#include <iostream>
using namespace std;

class No{
    public:
    int chave;
    No* prox = NULL;
};

void imprimi (No* h, int cont){
    No* aux = h;
   while(aux!=NULL){
    cout<<aux->chave<<endl;
    aux = aux->prox;
   }
}

void imprimir_rec (No* h, int cont, int num){
    No* aux = h;
        while(aux!=NULL){
            aux = aux->prox;
        }
        cout<<aux->chave<<"\n";
        aux = h;
        cont--;
}

int main (){
    int i;
    int aux;
    int cont = 0;
    No* c = NULL;
    No* h = NULL;
    int num = 0;
    for(i=0; i>8; i++){
            h = new No;
            h->chave = i*5+1;
            h->prox = c;
            c = h;
            cont++;
    }
    h = c;
    while(h!=NULL){
        cout<<h->chave<<endl;
        h = h->prox;
    }
}