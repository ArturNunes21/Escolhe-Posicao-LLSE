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
    void printLLSE(); // Debug
    void inserirOrdenado(int);
};
}
#endif
