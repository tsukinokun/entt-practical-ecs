//--------------------------------------------------------
//! @file	LogSystem.cpp
//! @brief	Positionを使って位置をログ出力するSystemの実装
//! @author つきの
//--------------------------------------------------------
#include <Systems/LogSystem.hpp>
#include <Components/Transform.hpp>
#include <iostream>
//--------------------------------------------------------
//! @brief ログ出力処理の更新
//--------------------------------------------------------
void LogSystem::Update(entt::registry& registry, float deltaTime) {
	// Positionを持つEntity を取得
	const auto view = registry.view<Transform>();

	// 各Entityの位置をログ出力
	view.each([](auto entity, const Transform& pos) {
		// ワールド座標をログ出力
		printf("Entity %d Local Position : (%f, %f)\n", (int)entity, pos.x, pos.y);
		printf("Entity %d World Position : (%f, %f)\n", (int)entity, pos.worldX, pos.worldY);
		});
}