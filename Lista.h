#ifndef LISTA_H
#define LISTA_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Node.h"

using namespace std;

template <class T>

class Lista
{

	private:
		Node<T> *m_head;
		int m_num_nodes;
	public:
		Lista();
		int getNum();
		void add_head(T);
		void add_end(T);
		void add_sort(T);
		void del_all();
		void del_by_position(int);
		T pop();
		void print();
		void save_file(string);
		void load_file(string);


};

#endif
