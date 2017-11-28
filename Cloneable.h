#ifndef REVERSI_CLONEABLE_H
#define REVERSI_CLONEABLE_H


struct Cloneable {
public:
    virtual Cloneable *clone() const = 0;

    virtual ~Cloneable() {};
};

#endif //REVERSI_CLONEABLE_H
