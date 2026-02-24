#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>

using namespace geode::prelude;

class $modify(LSLevelEditorLayer, LevelEditorLayer) {
    bool init(GJGameLevel* level, bool noUI);
};