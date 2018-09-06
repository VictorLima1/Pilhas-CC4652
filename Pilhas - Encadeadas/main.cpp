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
	
	int x;
	while(p.desempilha(&x)){
		cout << x << endl;
	}
}
