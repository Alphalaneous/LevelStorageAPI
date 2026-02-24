#include "PlayLayer.hpp"
#include "GJGameLevel.hpp"

bool LSPlayLayer::init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
    auto lsLevel = static_cast<LSGJGameLevel*>(level);
    lsLevel->extractFromString();

    return PlayLayer::init(level, useReplay, dontCreateObjects);

    // alpha::level_storage::getSavedValue<int>(this, "test");
    // alpha::level_storage::setSavedValue(this, "test", 1);

    /* 	
        alpha::level_storage::waitForLevel(this, [] {

        });
    */
}