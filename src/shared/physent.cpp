#include "cube.h"

// ORIGINAL SETTINGS.
//physent() : deltapos(0, 0, 0), newpos(0, 0, 0), yaw(0), pitch(0), roll(0), maxspeed(20),
//           radius(4.1f), eyeheight(18), maxheight(18), aboveeye(2), xradius(4.1f), yradius(4.1f), zmargin(0),

// ATTEMPT #1.
//physent::physent() : deltapos(0, 0, 0), newpos(0, 0, 0), yaw(0), pitch(0), roll(0), maxspeed(30),
//           radius(3.15), eyeheight(7), maxheight(8), aboveeye(2), xradius(1.6768999999999998), yradius(1.6768999999999998), zmargin(0),

// FINAL ATTEMPT FOR NOW.
physent::physent() : deltapos(0, 0, 0), newpos(0, 0, 0), yaw(0), pitch(0), roll(0), maxspeed(25),
           radius(2.4), eyeheight(7), maxheight(8), aboveeye(2), xradius(1.67), yradius(1.67), zmargin(0),
           state(CS_ALIVE), editstate(CS_ALIVE),
           collidetype(COLLIDE_ELLIPSE),
           blocked(false)
{
    ent_type = ENT_PLAYER; reset();
}

void physent::resetinterp() {
    newpos = o;
    deltapos = vec(0, 0, 0);
}

void physent::reset() {
    inwater = 0;
    timeinair = 0;
    eyeheight = maxheight;
    jumping = false;
    strafe = move = crouching = 0;
    physstate = PHYS_FALL;
    vel = falling = vec(0, 0, 0);
    floor = vec(0, 0, 1);
}

vec physent::feetpos(float offset = 0) const {
    return vec(o).addz(offset - eyeheight);
}
vec physent::headpos(float offset = 0) const {
    return vec(o).addz(offset);
}

bool physent::crouched() const {
    return fabs(eyeheight - maxheight*CROUCHHEIGHT) < 1e-4f;
}

