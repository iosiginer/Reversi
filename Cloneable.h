/**
 * Josef Ginerman 332494830
 * Barak Talmor 308146240
 */

#ifndef REVERSI_CLONEABLE_H
#define REVERSI_CLONEABLE_H


struct Cloneable {
public:
    virtual Cloneable *clone() const = 0;

    virtual ~Cloneable() {};
};

#endif //REVERSI_CLONEABLE_H
