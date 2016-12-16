/* 
 * File:   Lied.h
 * Author: fs
 *
 * Created on 15. Dezember 2016, 22:01
 */

#ifndef LIED_H
#define	LIED_H
#include <string>


class lied {
public:
    
    enum stil {
    Pop = 1, Rock = 2, Klassik = 3, HardRock = 4, Metal = 5
};

    std::string titel;
    std::string interpret;
    int erscheinungsjahr;
    int laenge;
    stil genre;
    
    lied();
    lied(std::string t, std::string i, int e, int l, enum lied::stil st);

    void print() const;
};

#endif	/* LIED_H */

