#ifndef LISTA
#define LISTA

class Lista {
protected:
    typedef struct sNo {
        int Info;
        struct sNo* Prox;
    } sNo;

    typedef sNo* pNo;
    protected:
        static char Erro;
        char Valida;
        pNo Inicio;

    void DescarteTudo();

public:
    static char DeuErro();
    char eValida() const;

    Lista();
    ~Lista();

    bool Vazia() const;
    void Insira(int I);
    int Contem(int I) const;
    void Descarte(int I);
    char* NaFormaDeString() const;
};

#endif
