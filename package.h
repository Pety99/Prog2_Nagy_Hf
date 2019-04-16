#ifndef PACKAGE_H_INCLUDED
#define PACKAGE_H_INCLUDED

#include <string>

class Package
{
    std::string destination;
    std::string location;
    int id;

public:
    Package():destination("default"), location("default"), id(0){}
    Package(char* destination, char* location, int id): destination(destination), location(location), id(id){}
    Package(Package& p)
    {
        this->destination = p.destination;
        this->location = p.location;
        this->id = p.id;
    }
    virtual ~Package(){}
    std::string get_location() const
    {
        return this->location;
    }
    void set_location(char* location)
    {
        this->location = location;
    }
    int get_id() const
    {
        return this->id;
    }
};

class Luggage: public Package
{
    double weight;

public:

    Luggage(char* destination, char* location, int id, int weight): Package(destination, location, id), weight(weight) {}

};

class Small_box: public Package
{

public:

    Small_box(char* destination, char* location, int id): Package(destination, location, id){}

};

class New_arrival: public Package
{
    public:
        New_arrival(char* destination, int id): Package(destination, (char*)"Customs", id){}
};

class Warehouse
{
    Package** packages;
    int db;
public:

    Warehouse(Package** p, int db): db(db)
    {
        this->packages = new Package*[db];
        for ( int i = 0; i < this->db; i++)
        {
            //csak a pointereket másoljuk
            (packages[i]) = (p[i]);
        }
    }

    Package& operator[](int i)
    {
        return *(packages[i]);
    }

};



#endif // PACKAGE_H_INCLUDED
