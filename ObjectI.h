#ifndef OBJECT_I_
#define OBJECT_I_

//Object interface for controlling the location/visual representation of objects

class ObjectI {
    public:
        // Setters and getters for coordinates within the playing field
        virtual int getX() = 0;
        virtual int getY() = 0;
        virtual void setX(int) = 0;
        virtual void setY(int) = 0;

        //Setters and getters for graphical representation
        virtual void setColor(COLORREF) = 0;
        virtual COLORREF getColor() = 0;

        /*
        * Getter fr the object's ID.
        * Legacy code: 1 = player, 2 = collected point, 3 = uncollected point
        */
        virtual int getID() = 0;

        virtual ~ObjectI() {}
};

#endif