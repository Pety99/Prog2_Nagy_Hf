

#include "graph.h"
#include <fstream>
#include <string>

#include <sstream>






Graph::Graph(const char* file_name)
{
	std::ifstream file(file_name);
	std::string str;
	std::string file_contents;

	if (file.is_open()) {
		int max = 0;

		while (std::getline(file, str))
		{
			int x;
			int y;
			std::stringstream numbers(str);
			numbers >> x >> y;

			if (x > max || y > max)
				max = x > y ? x : y;
		}

		file.clear(); // Kiüríti a streamet
		file.seekg(0); // A stream elejére ugrik

		//Beállítja az új gráf méretét, és lefoglalja azt

		*this = Graph(max + 1);
		//this->size = max+1;
		//this->graph = new Node[this->size];

		//Beolvassa a gárfot a fileból
		int i = 0;
		while (std::getline(file, str))
		{
			int x;
			int y;
			std::string s;
			std::stringstream numbers(str);
			numbers >> x >> y >> s;

			this->add_edge(x, y);
			this->graph[i].set_name(s);
			i++;
		}
	}
	else
	{
		std::cout << "Hiba a fajl megnyitasa soran" << std::endl;
	}
}

void Graph::add_edge(int x, int y)
{
	if (x == y)
	{
		std::cout << "Hurokelek nem engedelyzettek! x:" << x << " y:" << y << std::endl;
	}
	else if (x < this->size && y < this->size && x >= 0 && y >= 0)
	{
		this->graph[x].add_connection(y);
		this->graph[y].add_connection(x);

	}
	else
	{
		std::cout << "Valamelyik pont nem resze a grafnak, nem lehet letrehozni az elt" << std::endl;
	}
}

void Graph::add_edge(const char* x, const char* y)
{
	int a = 0 , b = 0;
	std::string str_x = x;
	std::string str_y = y;
	for (int i = 0; i < this->size; i++)
	{
		if (this->graph[i].get_name() == str_x)
			a = i;
		if (this->graph[i].get_name() == str_y)
			b = i;
	}
	if( a != b)
        add_edge(a, b);
    else
    {
        std::cout<<"Nem kotheto ossze: "<< str_x<< " - "<<str_y<<std::endl;
    }
}

void Graph::delete_edge(int x, int y)
{
	//Azért ellenörzi a hibát mert pontosabb hiba uzenetet ad
	int lim = this->graph[x].get_size();

	for (int i = 0; i < lim; i++)
	{
		if (this->graph[x].get_neighbour(i) == y)
		{
			this->graph[x].delete_connection(y);
			this->graph[y].delete_connection(x);
			return;
		}
	}
	std::cout << "Nem szomszedos x:" << x << " es y:" << y << " ezert nem torolheto" << std::endl;
}


/////////////////MÉG KELL BELE ÍRNI EGY LÉTZÕ E A SZOSZÉDOK CSÚCS ELLENÕRZÉST
void Graph::add_node(const char* name, const int* nei_idx, int db)
{
	//Szomszédos csúcs ellenõrzõ
	for (int i = 0; i < db; i++)
	{
		if (nei_idx[i] >= this->size)
		{
			std::cout << "Nincs ilyen indexu szomszed, nem lesz hozzadva az uj csomopont.";

			return;
		}
	}
	//hogy ne legynek ugyan olyan csucsok
	for (int i = 0; i < this->size; i++)
	{
		if (this->graph[i].get_name() == name)
		{
			std::cout << "Nem lehet ket ugyan olyan nevu csucs, nem lesz hozzadva az uj csomopont.";
			return;
		}
	}
	Node* new_nodes = new Node[size + 1];
	for (int i = 0; i < this->size; i++)
	{
		new_nodes[i] = this->graph[i];
	}
	new_nodes[size] = Node(name, db, nei_idx);
	delete[] this->graph;
	this->size += 1;
	this->graph = new_nodes;
	//A meglévő csucsokhoz is be kell irni szomszedosnak az ujat
	for ( int i = 0; i < db; i++)
    {
        this->graph[this->graph[size-1].get_neighbour(i)].add_connection(this->size-1);

    }
}

void Graph::add_node(const char* name, char** nei_name, int db)
{
    int* nei_idx = new int[db];
    int count = 0;
    for ( int i = 0; i < this->size; i++)
    {
        for ( int j = 0; j < db; j++)
        {
            if(this->graph[i].get_name() == nei_name[j])
            {
                nei_idx[count] = i;
                count++;
            }
        }
    }
    this->add_node(name, nei_idx, db);
	delete[] nei_idx;
}



void Graph::print_graph()
{
	char dec;
	std::cout << "Indexekkel/ Nevekkel jelenitse meg? (i/n)" << std::endl;
	std::cin >> dec;
	if (dec == 'n' || dec == 'N')
	{
		for (int i = 0; i < this->size; i++)
		{
			std::cout << this->graph[i].get_name() << ":  ";
			//új kod
			for (int j = 0; j < this->graph[i].get_size(); j++)
			{

				std::cout << this->graph[this->graph[i].get_neighbour(j)].get_name() << ", ";
			}
			std::cout << std::endl;
		}
	}
	else if (dec == 'i' || dec == 'I')
	{

		for (int i = 0; i < this->size; i++)
		{
			std::cout << i << ".node: ";
			this->graph[i].print_node();
		}

	}
	else
		std::cout << "Nem megfelelo input" << std::endl;
}
