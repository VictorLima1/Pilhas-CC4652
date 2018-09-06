#ifndef PILHA_HPP
#define PILHA_HPP

#define MAX 100

template<typename T>
class Pilha{
	private:
		T v[MAX];
		int topo;
	public:
		Pilha(): topo(0){
		}
		bool empilha(T valor){
			if(topo == MAX){
				return false;
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
