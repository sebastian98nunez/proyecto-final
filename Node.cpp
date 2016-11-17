#include "Node.h"

template<typename T>

Node<T>::Node()
{
	data = NULL;
	next = NULL;
}


template<typename T>
Node<T>::Node(T data_)
{
	data = data_;
	next = NULL;
}

// Eliminar todos los Nodos
template<typename T>
void Node<T>::delete_all()
{
	if (next)
	{
		next->delete_all();
	}
	delete this;
}

// Imprimir un Nodo
template<typename T>
void Node<T>::print()
{
	cout << data <<"\n";
}

template<typename T>
Node<T>::~Node() {}
