#include "LevelEditorLayer.hpp"
#include "GJGameLevel.hpp"

bool LSLevelEditorLayer::init(GJGameLevel* level, bool noUI) {
    auto lsLevel = static_cast<LSGJGameLevel*>(level);
    lsLevel->extractFromString();
    return LevelEditorLayer::init(level, noUI);
}