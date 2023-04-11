#ifndef NO_H
#define NO_H
namespace Artur{

class No
{
private:
    int dado;
public:
    No* proximo;
    No();
    No(int dado);
    int getDado() const;
    void setDado(int newDado);
    No *getProximo() const;
    void setProximo(No *newProximo);
};
}
#endif // NO_H
