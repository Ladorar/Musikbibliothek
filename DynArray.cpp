

#include "DynArray.h"

DynArray::DynArray () {
    m_data = new lied[10];
    m_size = 0;
    m_capacity = 10;
}

DynArray::DynArray (const DynArray& orig) {}

DynArray::~DynArray () {
    delete[] m_data;
    m_size = 0;
    m_capacity = 0;
}

DynArray::DynArray (int newCapacity) {
    m_data = new lied[newCapacity];
    m_size = 0;
    m_capacity = newCapacity;
}

lied& DynArray::at (int index) const{
    return *(m_data + index);
}

int DynArray::size () const {
    return m_size;
}

int DynArray::capacity () const {
    return m_capacity;
}

void DynArray::push_back (lied elem) {
    if (m_size >= m_capacity - 5) {
        resize (m_capacity + 5);
    }
    *(m_data + m_size) = elem;
    m_size++;
}

void DynArray::pop_back () {
    if (m_size + 10 < m_capacity) {
        resize (m_capacity - 5);
    }
    delete (m_data + (m_capacity-1));
    m_capacity--;
}

void DynArray::erase (int index) {
    if (index < m_size && index >= 0) {
        for (int i = index; i < m_size; i++) {
            *(m_data + i) = *(m_data +1 + i);
        }
        m_size--;
        pop_back ();
    }
}

void DynArray::print () const {
    for (int i = 0; i < m_size; i++) {
        (m_data + i)->print();
    }
}

void DynArray::resize (int newCapacity) {
    lied* temp_data = new lied[newCapacity];
    for (int i = 0; i < m_size; i++) {
        *(temp_data + i) = *(m_data + i);
    } 
    delete[] m_data;
    m_data = temp_data;
    m_capacity = newCapacity;
}

