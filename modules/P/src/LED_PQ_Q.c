#include "../lib/LED_PQ_Q.h"

longNumberQ *led(longNumberP *a)
{
    return a->coefficient[a->degree];
}