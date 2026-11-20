#include "PlayLayer.hpp"
#include "GJGameLevel.hpp"

bool LSPlayLayer::init(GJGameLevel* level, bool dontCreateObjects) {
    static_cast<LSGJGameLevel*>(level)->extractFromString();

    return PlayLayer::init(level, dontCreateObjects);
}