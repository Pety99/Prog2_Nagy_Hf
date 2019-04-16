#include "graph.h"
#include <fstream>
#include <string>

#include <sstream>

Node::Node(const char* name, int size, const int* nei) : name(name)
{
	this->size = size;
	this->neighbours = new int[size];
	for (int i = 0; i < this->size; i++)
		this->neighbours[i] = nei[i];
}

Node::Node(const Node& n)
{
	this->name = n.name;
	this->size = n.size;
	this->neighbours = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->neighbours[i] = n.neighbours[i];
	}
}

Node& Node::operator=(const Node& n)
{
	if (this->neighbours != n.neighbours)
	{
		delete this->neighbours;
		this->name = n.name;
		this->size = n.size;
		this->neighbours = new int[this->size];
		for (int i = 0; i < this->size; i++)
		{
			this->neighbours[i] = n.neighbours[i];
		}
	}
	return *this;
}


void Node::add_connection(const int x)
{
	// Ellenõrizzük nincs e már benne az elem
	for (int i = 0; i < this->size; i++)
	{
		if (this->get_neighbour(i) == x)
		{

			std::cout << "Mar van ilyen szomszed: " << x << std::endl;
			return;
		}
	}
	this->size += 1;
	int* new_neighbours = new int[this->size];
	for (int i = 0; i < this->size - 1; i++)
	{
		new_neighbours[i] = this->neighbours[i];
	}
	new_neighbours[this->size - 1] = x;

	delete[] this->neighbours;
	this->neighbours = new_neighbours;
}

void Node::delete_connection(int x)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->neighbours[i] == x)
		{
			this->size -= 1;
			int* new_neighbours = new int[this->size];
			for (int j = 0; j < i; j++)
			{
				new_neighbours[j] = this->neighbours[j];
			}
			for (int j = i; j < this->size; j++)
			{
				new_neighbours[j] = this->neighbours[j + 1];
			}
			delete[] this->neighbours;
			this->neighbours = new_neighbours;
			return;
		}
	}
	std::cout << "Nincs ilyen torlendo elem: " << x << std::endl;
}

int Node::get_neighbour(int x)
{
	if (x >= 0 && x < this->size)
		return(this->neighbours[x]);
	else
	{
		std::cout << "Nem letezik ilyen indexu elem: " << x << std::endl;
		return -1;
	}
}

//átmeneti függvény
void Node::print_node()
{
	for (int i = 0; i < this->size; i++)
	{
		//std::cout<<this->name<<":";
		std::cout << this->neighbours[i] << " ";
	}
	std::cout << std::endl;
}

