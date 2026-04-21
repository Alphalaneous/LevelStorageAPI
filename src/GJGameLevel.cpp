#include "GJGameLevel.hpp"
#include <Geode/utils/base64.hpp>
#include <matjson.hpp>

void LSGJGameLevel::extractFromString() {
    const std::string str = ZipUtils::decompressString(m_levelString, false, 0);
    const char* data = str.data();
    const char* end = data + str.size();

    auto nextToken = [end](const char*& ptr) -> std::string_view {
        const char* comma = static_cast<const char*>(memchr(ptr, ',', end - ptr));
        if (!comma) comma = end;
        std::string_view token(ptr, comma - ptr);
        ptr = comma + 1;
        return token;
    };

    while (data < end) {
        std::string_view key = nextToken(data);
        if (data >= end) break;
        std::string_view value = nextToken(data);

        if (key == "kA14") {
            const char* pipe = static_cast<const char*>(memchr(value.data(), '|', value.size()));
            if (!pipe) continue;
            const char* tilde = static_cast<const char*>(memchr(pipe + 1, '~', value.data() + value.size() - (pipe + 1)));
            if (!tilde) continue;

            parseData({pipe + 1, static_cast<size_t>(tilde - (pipe + 1))});
            return; 
        }
    }
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