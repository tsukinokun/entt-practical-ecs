//--------------------------------------------------------
//! @file	LogSystem.cpp
//! @brief	Healthを持つEntityのHPをログ出力するSystemの実装
//! @author つきの
//--------------------------------------------------------
#include <Systems/LogSystem.hpp>
#include <Components/Health.hpp>
#include <iostream>
//--------------------------------------------------------
//! @brief ログ出力処理の更新
//--------------------------------------------------------
void LogSystem::Update(entt::registry& registry, float deltaTime) {
	// Positionを持つEntity を取得
	const auto view = registry.view<Health>();

	// 各Entityの位置をログ出力
	view.each([](auto entity, const Health& hp) {
		// Entity ID と HP をログ出力
		printf("Entity %d HP : %d\n", (int)entity, hp.value);
		});
}