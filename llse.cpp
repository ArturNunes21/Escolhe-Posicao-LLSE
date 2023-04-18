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




int LLSE::getAux() const
{
    return aux;
}

int LLSE::getPrimeiro() const
{
    if(aux==0){
        throw QString ("A lista está vazia - getPrimeiro");
    }
    return primeiro;
}

void LLSE::setPrimeiro(int newPrimeiro)
{
    primeiro = newPrimeiro;
}

void LLSE::setAux(int newAux)
{
    aux = newAux;
}

LLSE::LLSE():
    quantidadeElementos(0),
    inicio(0),
    aux(0),
    primeiro(0)
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
            throw QString ("Valor inválido - inserirPosicao");
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

QString LLSE::obterMaiorEMenor() {
    if (estaVazia()) {
        throw QString("Lista vazia - obterMaiorEMenor");
    }

    QString res="";
    if(quantidadeElementos==1){
        res=QString::number(inicio->getDado());
        return res;
    }
    No* menor = inicio;
    No* maior = inicio;

    for (No* no = inicio; no != nullptr; no = no->getProximo()) {
        if (no->getDado() < menor->getDado()) {
            menor = no;
        }
        if (no->getDado() > maior->getDado()) {
            maior = no;
        }
    }
    res= QString::number(menor->getDado()) + "-" + QString::number(maior->getDado());
    return res;
}

int LLSE::calcularMmc(int a, int b){
    int maior= (a>b) ? a : b;
    while(true){
        if(maior%a==0 && maior%b==0){
            return maior;
        }
        maior++;
    }
}

int LLSE::calcularMmcLLSE(){
    if(estaVazia() || quantidadeElementos==1){
        throw QString ("Impossível calcular mmc - calcularMmcLLSE");
    }
    int res=calcularMmc(inicio->getDado(), inicio->proximo->getDado());
    No *atual=inicio->proximo->proximo;
    while(atual!=nullptr){
        if(atual->getDado()==0){
            throw QString ("Impossível calcular MMC com valor 0 - calcularMmcLLSE");
        }
        res=calcularMmc(res,atual->getDado());
        atual=atual->proximo;
    }
    return res;
}

QString LLSE::obterPosicoes(int valor){
    if(estaVazia()){
        throw QString ("Lista vazia - obterPosicoes");
    }
    QString res="";
    int i=0;

    for(No *no=inicio; no!=nullptr;no=no->getProximo()){
        if(no->getDado()==valor){
            res+= QString::number(i++) + " ";
        }
    }
    return res;
}

}   //namespace


