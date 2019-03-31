#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

class Grafo
{
    public:
        Grafo();
        ~Grafo();
        int getOrdem();
        void setOrdem(int val);
        int getGrau();
        void setGrau(int val);
        bool getNoPonderado();
        void setNoPonderado(int val);


    private:
       int ordem;
       int grau;
       bool noPonderado;
       No listaNos;

};


#endif // GRAFO_H_INCLUDED
