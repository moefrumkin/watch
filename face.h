
/* Clear the watch face */
void clear();

/* Represents one of the twelve directions on the watch face */
class Direction {
    private:
        unsigned char dir;
    public:
        explicit Direction(unsigned char dir): dir (dir) {};

        /* Advance to the next tick */
        Direction next() {
            return Direction ((dir + 1) % 12);
        }

        Direction previous() {
            return Direction ((dir - 1) % 12);
        }
};

class Time {
    private:
        Direction hour;
        Direction minute;
    public:
        /* Convert second count to time to be displayed */
        explicit Time(long nanos);
};

/* Represents something to be displayed on the face.
 * Handles interrupts for time-based multiplexing */
class Display {
    public:
        /* Clear the display, and cancel the interrupts */
        void clear();

        /* Show a given direction */
        void show (Direction);

        /* Show the time, setting up interrupts for time multiplexing */
        void show(Time);
};
