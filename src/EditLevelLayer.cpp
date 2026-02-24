#include "EditLevelLayer.hpp"
#include "GJGameLevel.hpp"

bool LSEditLevelLayer::init(GJGameLevel* level) {
    auto lsLevel = static_cast<LSGJGameLevel*>(level);
    lsLevel->extractFromString();
    return EditLevelLayer::init(level);
}