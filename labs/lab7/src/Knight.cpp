#include "../headers/Knight.h"
#include "../headers/Squirrel.h"
#include "../headers/Pegasus.h"

Knight::Knight(const std::string& name, double x, double y)
    : NPC(name, x, y) {}

void Knight::interact(NPC& other) {
    if (!other.isAlive()) return;
    other.interactWith(*this);
}

void Knight::interactWith(Knight& knight) {
}

void Knight::interactWith(Squirrel& squirrel) {
}

void Knight::interactWith(Pegasus& pegasus) {
}

std::string Knight::getType() const {
    return "Knight";
}
