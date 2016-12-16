

#ifndef DYNARRAY_H
#define	DYNARRAY_H
#include "lied.h"



class DynArray
{
public:
	DynArray(); //Standardkonstruktor
	DynArray(int newCapacity); //Weiterer Konstruktor
	~DynArray(); //Destruktor, muss implementiert werden

	lied& at(int index) const;

	void push_back(lied elem);
	void pop_back();
	void erase(int index);

	int size() const;
	int capacity () const;

	void print () const;

private:
	void resize(int newCapacity);
	DynArray(const DynArray& other); //Kopierkonstruktor soll explizit *nicht* aufgerufen werden
	lied* m_data;
	int m_size;
	int m_capacity;
};

#endif	/* DYNARRAY_H */





