#pragma once

#include "Resource.hpp"

class ResourceManager
{
    public:
        ResourceManager()   //konstruktor domyślny, który inicjalizuje zarządzany obiekt przy pomocy domyślnego 
                            //konstruktora klasy Resource
        {
            resource = new Resource{};
        }
        ResourceManager(const ResourceManager& resource2)   //konstruktor kopiujący
        {
            resource = new Resource(*resource2.resource);
        }
        ResourceManager& operator=(const ResourceManager resource2)    //kopiujący operator przypisania
        {
            if (this != &resource2)
            {
                delete resource;
                resource = new Resource{*resource2.resource};
            }
            return *this;
        }
        ~ResourceManager()  //destruktor
        {
            delete resource;
        }
        double get()    //metoda double get(), która zwraca wynik zawołania metody get obiektu, którym zarządza
        { 
            return resource->get(); 
        }
    private:
        Resource* resource;
};
