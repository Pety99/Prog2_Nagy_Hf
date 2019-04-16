#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <string>
#include "node.h"

class Graph
{
public:
	Node* graph;
	int size;
public:
	/**
	 *Egy n elemû üres gráf konstruktora.
	 */
	Graph(int x) :size(x)
	{
		this->graph = new Node[x];
		for (int i = 0; i < x; i++)
		{
			//Indexeket tesz az alapértelmezett nevek után, hogy elkülöníthetőek legyenek
			this->graph[i].set_name(this->graph[i].get_name() + " " + std::to_string(i));
		}
	}

	/**
	 * Másoló Konstruktor
	 */
	Graph(const Graph& g)
	{
		this->size = g.size;
		this->graph = new Node[this->size];
		for (int i = 0; i < this->size; i++)
			this->graph[i] = g.graph[i];
	}
    /**
	 * Operator =
	 */
	Graph& operator =(const Graph& g)
	{
		if (this->graph != g.graph)
		{
			this->size = g.size;
			this-> graph = new Node[this->size];
			for (int i = 0; i < this->size; i++)
			{
				this->graph[i] = g.graph[i];
			}
		}
		return *this;
	}
	~Graph()
	{
		delete[] this->graph;
	}

	/**
	 * Betölt egy gráfot egy txt fájlból
	 * Egy sor 2 szomszédos csúcsot jelöl,
	 * erre hívódik meg az add_edge.
	 */
	Graph(const char*file_name);

	/**
	 * 2 létező csúcs közé betesz egy élt.
	 */
	void add_edge(int x, int y);

	void add_edge(const char* x, const char* y);

	/**
	 * Új csúcsot ad hozzá a gráfhoz a szomszédaival együtt.
	 */
	void add_node(const char* name, const int* nei_idx, int db);

	void add_node(const char* name, char** nei_name, int db);

	/**
	 * 2 létező csúcs közül kitöröl egy élt.
	 */
	void delete_edge(int x, int y);

	void print_graph();


};


#endif // GRAPH_H_INCLUDED
