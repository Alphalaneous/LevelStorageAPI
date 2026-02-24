#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/GJGameLevel.hpp>

using namespace geode::prelude;

class $modify(LSGJGameLevel, GJGameLevel) {
    struct Fields {
		matjson::Value m_data;
	};

	void extractFromString();
	std::string_view extract(std::string_view guidelines);
	matjson::Value& getDataContainer(Mod* mod);
	const matjson::Value& getData();
	void parseData(std::string_view data);

    static matjson::Value& getEmptyData();
};