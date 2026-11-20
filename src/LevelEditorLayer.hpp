#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>

using namespace geode::prelude;

class $modify(LSLevelEditorLayer, LevelEditorLayer) {

    static void onModify(auto& self) {
        (void) self.setHookPriorityPre("LevelEditorLayer::saveLevel", Priority::Last);
    }

    bool init(GJGameLevel* level, bool noUI);

    bool saveLevel();
};