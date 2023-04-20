#include "llse.h"
namespace Artur{

int LLSE::acessarFim(){
    if(estaVazia()){
        throw QString ("A lista está vazia");
    }
    int aux=0;
    No *ultimo;
    ultimo = inicio;
    while(ultimo->proximo != nullptr){
        ultimo = ultimo->proximo;
    }
    aux=ultimo->getDado();
    return aux;
}

void LLSE::inserirFim(int elemento){
    try{
        No *aux = new No(elemento);
        //cria um novo nó com o valor inserido
        No *ultimo;
        if (estaVazia())
            inicio = aux;
            //se lista vazia, insere na primeira posição
        else{
            ultimo = inicio;
            while(ultimo->proximo != nullptr){
                ultimo = ultimo->proximo;
            }
            ultimo->proximo = aux;
        }
        quantidadeElementos += 1;
    }
    catch (std::bad_alloc &erro){
        throw QString ("Não foi possível criar o no - inserirInicio");
    }
}

int LLSE::retirarFim() {
    if (estaVazia()) {
        throw QString("A lista está vazia - retirarFim");
    }
    int valor;
    No* atual = inicio;
    No* anterior = nullptr;
    while (atual->proximo != nullptr) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (anterior == nullptr) {
        // só há um elemento na lista
        inicio = nullptr;
    } else {
        anterior->proximo = nullptr;
    }
    valor = atual->getDado();
    delete atual;
    quantidadeElementos--;
    return valor;
}




LLSE::LLSE():
    quantidadeElementos(0),
    inicio(new No(0))
{
}
bool LLSE::estaVazia()const{
    return (quantidadeElementos == 0);
}
int LLSE::getQuantidadeElementos() const{
    return quantidadeElementos;
}
void LLSE::inserirInicio(int elemento){
    try{
        No *aux = new No(elemento);
        //Aloca um novo nó e armazena em aux

        aux->setProximo(inicio);
        //Armazena o endereço do próximo nó da lista

        inicio = aux;
        //inicio recebe o endereço do antigo primeiro nó

        quantidadeElementos++;
        //Incrementa a qtde. de elementos
    }
    catch (std::bad_alloc &erro){
        throw QString ("Não foi possível criar o no - inserirInicio");
    }
}
int LLSE::retirarInicio(){
    if(estaVazia()){
        throw QString ("A lista está vazia - retirarInicio");
    }
    No* aux= inicio;
    inicio = aux->getProximo();
    int valor = aux->getDado();
    delete aux;
    quantidadeElementos -= 1;
    return valor;
}

int LLSE::acessarInicio(){
    if(estaVazia()){
        throw QString ("A lista está vazia - acessarInicio");
    }
    int aux=0;
    aux=inicio->getDado();
    return aux;
}

int LLSE::acessarPosicao(int posicao){
    if(estaVazia()){
        throw QString ("A lista está vazia - acessarInicio");
    }
    if(posicao >=quantidadeElementos || posicao <0){
        throw QString ("Valor inválido - acessarPosicao");
    }
    No *aux=inicio;
    for(int i=0; i<posicao;i++){
        aux=aux->getProximo();
    }
    return aux->getDado();

}

void LLSE::inserirPosicao(int valor,int posicao){
    try{
        if(posicao<0 || posicao > quantidadeElementos){
            throw QString ("Valor inválido - retirarPosicao");
        }
        No *novoNo=new No(valor);
        if (estaVazia()) { // se lista vazia
          inicio = novoNo;
          quantidadeElementos++;
          return;
        }
        No *noAnterior=inicio;
        No *proximoNo=inicio;
        for(int i=0; i<posicao;i++){
            if(i==posicao-1){
                noAnterior=proximoNo;
            }
            proximoNo=proximoNo->getProximo();
        }
        noAnterior->setProximo(novoNo);
        novoNo->setProximo(proximoNo);
        quantidadeElementos++;
    }
    catch (std::bad_alloc &erro){
        throw ("Não foi possível criar nó - inserirPosicao");
    }
}

QString LLSE::obterDadosLLSE()const{
    if(estaVazia()){
        return "Lista vazia";
    }
    QString resultado = "";
    No* aux=inicio;
    while(aux != 0)
    {
        resultado += "|" + QString::number(aux->getDado()) +"|";
        if(aux->getProximo()!= 0)
        {
            resultado += "->";
        }
        aux = aux->getProximo();
    }
    return resultado;
}

int LLSE::retirarPosicao(int posicao){
    try{
        if(estaVazia()){
            throw QString ("Lista vazia - retirarPosicao");
        }
        if(posicao<0 || posicao >=quantidadeElementos){
            throw QString ("Valor inválido - retirarPosicao");
        }
        if(posicao==0){
            return retirarInicio();
        }
        if(posicao==quantidadeElementos-1){
            return retirarFim();
        }
        No *anterior=inicio;
        No *atual=inicio;
        for(int i=0; i<posicao-1;i++){
            anterior=anterior->getProximo();
        }
        atual=anterior->getProximo();
        anterior->setProximo(atual->getProximo());
        int valor = atual->getDado();
        delete atual;
        quantidadeElementos--;
        return valor;
    }
    catch (std::bad_alloc &erro){
        throw ("Não foi possível retirar nó - retirarPosicao");
    }
}

void LLSE::inserirOrdenado(int valor){
    try{
        No *novoNo=new No(valor);
        No *atual=inicio;
        No *proximo=inicio->getProximo();
        if(estaVazia()){
            novoNo->setProximo(nullptr);
            inicio=novoNo;
            quantidadeElementos++;
        }
        else if(valor<inicio->getDado()){
            novoNo->setProximo(inicio);
            inicio=novoNo;
            quantidadeElementos++;
        }
        else{
            while(atual!=nullptr){
                if(proximo==nullptr){
                    atual->setProximo(novoNo);
                    quantidadeElementos++;
                    break;
                }
                else if(valor<proximo->getDado()){
                        novoNo->setProximo(proximo);
                        atual->setProximo(novoNo);
                        quantidadeElementos++;
                        break;
                    }
                atual=proximo;
                proximo=proximo->getProximo();
            }
        }

    }
    catch (std::bad_alloc &erro){
        throw ("Não foi possível inserir nó - inserirOrdenado");
    }
    catch (std::exception &erro){
        throw (erro);
    }
}

}   //namespace


