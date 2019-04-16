#define MEM_DEBUG  0
#if MEM_DEBUG == 1

// debug_new.cpp
// compile by using: cl /EHsc /W4 /D_DEBUG /MDd debug_new.cpp
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif
#endif


#include <iostream>
#include <fstream>
#include <string>
#include "graph.h"
#include "node.h"
#include "package.h"



int main()
{
    #if MEM_DEBUG == 1
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	}
	#endif
	/*
	int szomszedok[5]  = { 1, 2, 4, 30, 9};
	Node x(0, 5, szomszedok);
	x.add_connection(5);
	x.print_node();
	std::cout<<std::endl;
	x.delete_connection(30);
	x.print_node();
	std::cout<<std::endl;
 */
	//Graph g(7);
	//g.add_edge(1, 3);
	//g.add_edge(-3, 1);
	//g.add_edge(2, 0);
	//for( int i= 0; i<4;i++)
	//{
	//	g.graph[i].print_node();
	//}
	//Node nodes[5];
	/*
		std::ifstream file("Read.txt");
		std::string str;
		std::string file_contents;
		while (std::getline(file, str))
		{
		file_contents += str;
		file_contents.push_back('\n');
		}
		std::cout<<file_contents<<std::endl;

	*/

	//g.load_graph("Read.txt");
	//std::cout << std::endl;
    Graph g("Read.txt");
	g.add_edge(6, 0);
	g.print_graph();

	Graph x(7);
	//g.add_edge(0, 1);
	g.add_edge("Warehouse_23", "Center");
	x.print_graph();
	char name_1[15] = "Center";
	char name_2[15] = "Point_1";
	char name_3[15] = "Warehouse_2";
    char* tomb[3] = { name_1, name_2, name_3 };

	g.add_node("Customs", tomb, 3);
	g.print_graph();


	Small_box ab((char*)"Center", (char*)"Warehouse_1", 1223141);
	Luggage bb((char*)"Point_1", (char*)"Point_2", 12313, 20);
	New_arrival cb((char*)"Warehouse_2", 235463);

	Package* my_warehouse[3] = {&ab, &bb, &cb};

	Warehouse w(my_warehouse, 3);








	return 0;
}
