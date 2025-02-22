#include "../game.h"
// #include "baseentity.h"
#include "dynamiclight.h"

namespace entities {
namespace classes {

DynamicLight::DynamicLight() : BaseEntity() {
    et_type = ET_LIGHT;
}

DynamicLight::~DynamicLight() {

}

void DynamicLight::preload() {
    //conoutf("%s", "Preloading dynamiclight entity");
}

void DynamicLight::think() {

}

void DynamicLight::render() {
    vec color;
    if (attributes.find("r") != attributes.end()) {
        color[0] = std::atof(attributes["r"].c_str());
    }
    if (attributes.find("g") != attributes.end()) {
        color[1] = std::atof(attributes["g"].c_str());
    }
    if (attributes.find("b") != attributes.end()) {
        color[2] = std::atof(attributes["b"].c_str());
    }
    adddynlight(o, 90, color, 2, 50);
}

// TODO: Add other optional arguments, so all can be done in 1 command. Kindly using other method functions such as fade time or flicker style, or even interval speeds.
void DynamicLight::setState(const DYNAMIC_LIGHT_STATE &state) {
    // Change the state.
    lightState = state;
}

} // classes
} // entities
