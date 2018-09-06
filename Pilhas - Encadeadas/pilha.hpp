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
};

#endif
