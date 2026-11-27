#include "LevelEditorLayer.hpp"
#include "GJGameLevel.hpp"
#include <Geode/utils/base64.hpp>

bool LSLevelEditorLayer::init(GJGameLevel* level, bool noUI) {
    static_cast<LSGJGameLevel*>(level)->extractFromString();
    return LevelEditorLayer::init(level, noUI);
}

std::string LSLevelEditorLayer::getLevelString() {
    std::string str = "";
    if (!m_levelSettings->m_guidelineString.empty()) {
        auto split = utils::string::split(m_levelSettings->m_guidelineString, "~|");
        if (split.size() > 0 && !split[0].empty() && split[0][0] != '|') {
            str = split[0];
        }
    }
    
    auto& data = static_cast<LSGJGameLevel*>(m_level)->getData();

    auto extraSeparator = "";

    if (str.size() != 0 && str[str.size()-1] != '~') {
        extraSeparator = "~";
    }

    m_levelSettings->m_guidelineString = fmt::format("{}{}|{}~0.1~", str, extraSeparator, base64::encode(data.dump(0)));

    return LevelEditorLayer::getLevelString();
}
