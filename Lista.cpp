#include "Lista.h"
#include "Node.h"
#include "Node.cpp"

using namespace std;

//Constructor por defecto
template<typename T>
Lista<T>::Lista()
{
	m_num_nodes = 0;
	m_head = NULL;
}



// Modificador de dominio
template<typename T>
int Lista<T>::getNum()
{
	return m_num_nodes;
}



// Insertar al inicio
template<typename T>
void Lista<T>::add_head(T data_)
{
	Node<T> *new_node = new Node<T> (data_);
	m_head = new_node;
	m_num_nodes++;
}



// Insertar al final
template<typename T>
void Lista<T>::add_end(T data_)
{
	Node<T> *new_node = new Node<T> (data_);
	Node<T> *temp = m_head;

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;
	m_num_nodes++;
}



// Insertar de manera ordenada
template<typename T>
void Lista<T>::add_sort(T data_)
{
	Node<T> *new_node = new Node<T> (data_);
	Node<T> *temp = m_head;

	if (m_head->data < data_)
	{
		new_node->next = m_head;
		m_head = new_node;
    }
	else
	{
		while ((temp->next != NULL) && (temp->next->data > data_))
		{
			temp = temp->next;
		}
		new_node->next = temp->next;
		temp->next = new_node;
	}
	m_num_nodes++;
}



// Eliminar todos los nodos
template<typename T>
void Lista<T>::del_all()
{
	m_head->delete_all();
	m_head = 0;
}




// Eliminar por posición del nodo
template<typename T>
void Lista<T>::del_by_position(int pos)
{
	Node<T> *temp = m_head;
	Node<T> *temp1 = temp->next;
	if (pos < 1 || pos > m_num_nodes)
	{
		cout << "Fuera de rango " << endl;
		return;
	}
	else if (pos == 1)
	   m_head = temp->next;
	else
	{
		for (int i = 2; i <= pos; i++)
		{
			if (i == pos)
			{
				temp->next = temp1->next;
				delete temp1;
				m_num_nodes--;
				return;
			}
			temp = temp->next;
			temp1 = temp1->next;
		}
	}
}



//Función que hibrida con stack y que retorna el último nodo, a la vez que lo borra
template<class T>
T Lista<T>::pop()
{
	Node<T> *temp;
	T dat;      // variable auxiliar para retorno
	if(!m_head)
	{
		return 0; // Si no hay nodos en la lista retornamos 0
	}
	// Nodo apunta al primer elemento de la lista
	temp = m_head;
	// Asignamos toda la lista menos el primer elemento
	m_head = temp->next;
	// Guardamos el valor de retorno
	dat = temp->data;
	// Borrar el nodo
	delete temp;
	return dat;
}



// Imprimir la Lista
template<typename T>
void Lista<T>::print()
{
	Node<T> *temp = m_head;
	if (!m_head)
	{
		cout << "La Lista está vacía " << endl;
	}
	else
	{
		while (temp)
		{
			temp->print();
			temp = temp->next;
		}
	}
	cout << endl << endl;
}



// Guardar una lista en un archivo
template<typename T>
void Lista<T>::save_file(string file)
{
	Node<T> *temp = m_head;
	ofstream out;
	out.open(file.c_str());
	if (!out.is_open())
	{
		cout << "No se puede guardar el archivo " << endl;
	}
	else
	{
		while (temp)
		{
			out << temp->data;
			out << " ";
			temp = temp->next;
		}
	}
	out.close();
}



// Cargar una lista desde un archivo
template<typename T>
void Lista<T>::load_file(string file)
{
	T line;
	ifstream in;
	in.open(file.c_str());
	if(!in.is_open())
	{
		cout << "No se puede abrir el archivo: " << file << endl << endl;
	}
	else
	{
		while(in >> line)
		{
		add_end(line);
		}
	}
	in.close();
}
