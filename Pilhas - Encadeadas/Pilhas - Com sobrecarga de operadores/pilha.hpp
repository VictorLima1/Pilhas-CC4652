#ifndef PILHA_HPP
#define PILHA_HPP
#include <cstring>

template<typename T>
class Pilha{
	private:
		T *v;
		int topo;
		int max;
		
		bool realoca(){
			T* vTemp = new T[max*2];
			if(vTemp==NULL)
				return false;
				
			memcpy(vTemp, v, sizeof(T)*max);
			max *= 2;
			delete[] v;
			v = vTemp;
			return true;
		}
		
		//void operator(const Pilha<T>&){};
		//A linha acima é só pra caso você não queira que o operador = seja usado por outras funções. É útil em casos como o desse programa, onde, no main, q=p dá problema. Por ser private, outras funções ficam impedidas de utilizar o operador.
	public:
		Pilha(): v(new T[10]), topo(0), max(10){
		}
		
		virtual ~Pilha(){
			delete[] v;
		}

		bool empilha(T valor){
			if(topo == max){
				if(!realoca()){
					return false;
				}
			}
			
			v[topo++] = valor;
			return true;
		}
		
		bool desempilha(T* des=NULL){
			if(topo == 0)
				return false;
			if(des)
				*des = v[--topo];
			return true;
		}
		
		void operator=(const Pilha<T> &outra){
			if(this->v){
				delete[] this->v;
			}
			
			/*
			Uma alternativa de código para facilitar:
			
			memcpy(this, &outra, sizeof(Pilha<T>));
			
			Usando essa linha, você pode não utilizar as duas próximas (this->max, this->topo) pois ele copia a estrututa inteira para a &outra.
			A linha this->v é necessária pois aqui ALOCAMOS outro espaço, diferentemente das linhas anteriores, onde simplesmentes apontamos para o mesmo lugar as duas pilhas.
			*/
			
			this->max = outra.max;
			this->topo = outra.topo;
			this->v = new T[this->max];
			memcpy(this->v, outra.v, sizeof(T)*this->max);
		}
		
		//Esses abaixo são para evitar um "p.empilha(x)" ou "p.desempilha(x)", fazendo simplesmente "p >> x" e "p << x"
		void operator<<(T valor){
			empilha(valor);
		}
		
		
		//O retorno de pilha<t> aqui é pra poder fazer vários encadeados, tipo "p << x << y << z", se não tivesse o pilha não ia dar.
		//Também o & é para que eu possa fazer isso, sem ele eu teria um erro na hora de compilar pois funciona como recursão.
		Pilha<T>& operator>>(T& des){
			desempilha(&des);
			return *this;
		}
		
		bool empty(){
			return topo == 0;
		}
};

#endif
