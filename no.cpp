#include "no.h"
namespace Artur{

No::No():
    dado(0),
    proximo(nullptr)
{
}
No::No(int dado):
    dado(dado),
    proximo(nullptr)

{

}
int No::getDado() const
{
    return dado;
}
void No::setDado(int newDado)
{
    dado = newDado;
}
No *No::getProximo() const
{
    return proximo;
}
void No::setProximo(No *newProximo)
{
    proximo = newProximo;
}
}
