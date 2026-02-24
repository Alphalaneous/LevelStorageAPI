#include "LevelInfoLayer.hpp"
#include "GJGameLevel.hpp"

bool LSLevelInfoLayer::init(GJGameLevel* level, bool challenge) {
    bool hasLevel = !level->m_levelString.empty();
    if (hasLevel) {
        auto lsLevel = static_cast<LSGJGameLevel*>(level);
        lsLevel->extractFromString();
    }

    if (!LevelInfoLayer::init(level, challenge)) return false;

    if (hasLevel) {
        auto fields = m_fields.self();
        for (const auto& callback : fields->m_waitForLevelCallbacks) {
            callback();
        }
    }

    return true;
}

void LSLevelInfoLayer::levelDownloadFinished(GJGameLevel* level) {
    auto fields = m_fields.self();

    auto lsLevel = static_cast<LSGJGameLevel*>(level);
    lsLevel->extractFromString();

    LevelInfoLayer::levelDownloadFinished(level);

    for (const auto& callback : fields->m_waitForLevelCallbacks) {
        callback();
    }
}

void LSLevelInfoLayer::addCallback(std::function<void()>&& callback) {
    auto fields = m_fields.self();
    
    fields->m_waitForLevelCallbacks.push_back(std::move(callback));
}