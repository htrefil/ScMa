#include "cube.h"

// WatIsDeze: TODO: Maybe remove the physent constructor from here.
dynent::dynent() : physent(), ragdoll(NULL), query(NULL), lastrendered(0)
{
    reset();
}

dynent::~dynent()
{
    #ifndef STANDALONE
        extern void cleanragdoll(dynent *d);
        if(ragdoll) cleanragdoll(this);
    #endif
}

void dynent::stopmoving()
{
    k_left = k_right = k_up = k_down = jumping = false;
    move = strafe = crouching = 0;
}

void dynent::reset()
{
    physent::reset();
    stopmoving();
    loopi(MAXANIMPARTS) animinterp[i].reset();
}

vec dynent::abovehead() {
    // WatIsDeze: Seems to determine to which lengths the camera and the character are allowed to go when jumping or crouching through a tunnel etc.
    return vec(o).addz(aboveeye+4);
}
