#ifndef REVERSI_CLONEABLE_H
#define REVERSI_CLONEABLE_H

/**
 * Cloneable class. Let's an instance of an object be cloneable.
 */
class Cloneable {
public:
    /**
     * Returns a new instance of the Object with the same content.
     * @return Cloneable - an equal instance.
     */
    virtual Cloneable *clone() const = 0;

    /**
     * Destructor.
     */
    virtual ~Cloneable() {};
};

#endif //REVERSI_CLONEABLE_H
