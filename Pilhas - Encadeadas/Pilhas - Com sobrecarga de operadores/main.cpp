#include <iostream>
#include <cstdlib>
#include "pilha.hpp"

using namespace std;

int main(){
	Pilha<int> p;
	p.empilha(4);
	p.empilha(5);
	p.empilha(6);
	p.empilha(7);
	
	Pilha<int> q;
	q=p;
	
	q.desempilha();
	//q.empilha(4);
	
	int x;
	
	while(!p.empty()){
		p >> x;
		cout << x << endl;
	}
	cout << "desempilhei o p, agora é o q" << endl;
	while(q.desempilha(&x)){
		cout << x << endl;
	}
}
