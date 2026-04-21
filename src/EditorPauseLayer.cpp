#include "EditorPauseLayer.hpp"
#include "GJGameLevel.hpp"
#include <Geode/utils/base64.hpp>

void LSEditorPauseLayer::saveLevel() {
    std::string str = "";
    if (!m_editorLayer->m_levelSettings->m_guidelineString.empty()) {
        auto split = utils::string::split(m_editorLayer->m_levelSettings->m_guidelineString, "~|");
        str = split[0];
    }
    
    auto lsLevel = static_cast<LSGJGameLevel*>(m_editorLayer->m_level);
    auto& data = lsLevel->getData();

    auto dataStr = data.dump(0);
    auto base64 = utils::base64::encode(dataStr);

    auto extraSeparator = "";

    if (str[str.size()-1] != '~') {
        extraSeparator = "~";
    }

    m_editorLayer->m_levelSettings->m_guidelineString = fmt::format("{}{}|{}~0.1~", str, extraSeparator, base64);

    EditorPauseLayer::saveLevel();
}