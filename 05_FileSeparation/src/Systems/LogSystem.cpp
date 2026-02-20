//--------------------------------------------------------
//! @file	LogSystem.cpp
//! @brief	Positionを使って位置をログ出力するSystemの実装
//! @author つきの
//--------------------------------------------------------
#include <Systems/LogSystem.hpp>
#include <Components/Position.hpp>
#include <iostream>
//--------------------------------------------------------
//! @brief ログ出力処理の更新
//! @param registry [in,out] EnTT のレジストリ
//--------------------------------------------------------
void LogSystem::Update(entt::registry& registry) {
	// Positionを持つEntity を取得
	const auto view = registry.view<Position>();

	// 各Entityの位置をログ出力
	view.each([](auto entity, const Position& pos) {
		std::cout << "Entity " << static_cast<int>(entity)
			<< " Render Position : (" << pos.x << ", " << pos.y << ")\n";
		});
}