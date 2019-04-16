#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>
#include <string>

class Node
{
private:
	std::string name; ///A csomópont neve
	int size; ///A szomszédok száma
	int* neighbours; ///A szomszédok töbmje
public:

	/**
	 * Default konstruktor
	 */
	Node() : name("default"), size(0), neighbours(nullptr) {}

	/**
	 * Másoló konstruktor
	 */
	Node(const Node& n);

	/**
	 * Értékadás operator
	 */
	Node& operator=(const Node& n);

	/**
	 * A konstruktora a csomópontnak.
	 * @param number A csomópont neve / száma.
	 * @param size A szomszéd tömb mérete.
	 * @param nei A szomszéd csomópontok tömbje.
	 */
	Node(const char* name, int size, const int* nei);

	/**
	 * Destruktor.
	 */
	~Node() { delete[] this->neighbours; }

	/**
	 * Új szomszédokat ad hozzá a csomóponthoz.
	 * A szomszédok számát is megvéltoztatja. (size)
	 * @param x Az új szomszédja a csomópontnak.
	 */
	void add_connection(const int x);

	/**
	 * Kitörli egy szomszédját a csomópontnak.
	 * A szomszédok számát is megvéltoztatja. (size)
	 * @param x A kitörlendõ szomszédja a csomópontnak.
	 */
	void delete_connection(int x);

	/**
	* Visszadja az n edik elemet a szomszédok tömbjébõl.
	*/
	int get_neighbour(int x);

	/**
	* Visszadja a szomszédos csomópontok számát.
	*/
	int get_size() { return this->size; };

	/**
	* Visszadja a csomópont nevét.
	*/
	std::string get_name() { return this->name; };

	void set_name(std::string s) { this->name = s; };

	void print_node();
};

#endif // NODE_H_INCLUDED
