#include "GJGameLevel.hpp"
#include <Geode/utils/base64.hpp>
#include <matjson.hpp>

void LSGJGameLevel::extractFromString() {
    const std::string str = ZipUtils::decompressString(m_levelString, false, 0);

    size_t start = 0;
    size_t end = str.find(';');
    if (end == std::string::npos) end = str.size();

    bool isKey = true;
    std::string key;

    while (start < end) {
        size_t comma = str.find(',', start);
        if (comma == std::string::npos || comma > end)
            comma = end;

        std::string_view token(&str[start], comma - start);

        if (isKey) {
            key = token;
        } 
        else if (key == "kA14") {
            parseData(extract(token));
            return;
        }

        isKey = !isKey;
        start = comma + 1;
    }
}

std::string_view LSGJGameLevel::extract(std::string_view guidelines) {
    const size_t pipePos = guidelines.find('|');
    if (pipePos == std::string_view::npos) return {};

    const size_t start = pipePos + 1;
    const size_t tildePos = guidelines.find('~', start);

    if (tildePos == std::string_view::npos) return {};

    return guidelines.substr(start, tildePos - start);
}

matjson::Value& LSGJGameLevel::getDataContainer(Mod* mod) {
    auto fields = m_fields.self();
    return fields->m_data[mod->getID()];
}

const matjson::Value& LSGJGameLevel::getData() {
    auto fields = m_fields.self();
    return fields->m_data;
}

void LSGJGameLevel::parseData(std::string_view data) {
    auto fields = m_fields.self();

    auto decodeRes = utils::base64::decodeString(data);
    auto res = matjson::parse(decodeRes.unwrapOrDefault());
    fields->m_data = res.unwrapOrDefault();
}

matjson::Value& LSGJGameLevel::getEmptyData() {
    static matjson::Value empty;
    empty.clear();
    return empty;
}