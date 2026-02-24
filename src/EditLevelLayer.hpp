#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp>

using namespace geode::prelude;

class $modify(LSEditLevelLayer, EditLevelLayer) {
    bool init(GJGameLevel* level);
};