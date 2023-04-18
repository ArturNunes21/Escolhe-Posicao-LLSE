#ifndef LLSE_H
#define LLSE_H
#include <no.h>
#include <QString>
#include <QDebug> // Somente para debugar
namespace Artur{
class LLSE
{
private:
    int quantidadeElementos;
    No* inicio;
    int aux;
    int primeiro;

public:
    LLSE();
    bool estaVazia()const;
    void inserirInicio(int elemento);
    int retirarInicio();
    int getQuantidadeElementos() const;
    int acessarInicio();
    int acessarPosicao(int);
    int acessarFim();
    void inserirPosicao(int, int);
    int retirarPosicao(int);
    void inserirFim(int elemento);
    int retirarFim();
    QString obterDadosLLSE()const;
    QString obterMaiorEMenor();
    void printLLSE(); // Debug
    int getAux() const;
    int getPrimeiro() const;
    QString obterPrimeiro();
    void setPrimeiro(int newPrimeiro);
    void setAux(int newAux);
    int calcularMmc(int, int);
    int calcularMmcLLSE();
    QString obterPosicoes(int);
};
}
#endif
