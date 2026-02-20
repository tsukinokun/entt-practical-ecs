//--------------------------------------------------------
//! @file	MovementSystem.cpp
//! @brief	座標を更新するSystemのクラス定義
//! @author つきの
//--------------------------------------------------------
#include <Systems/MovementSystem.hpp>
#include <Components/Position.hpp>
#include <Components/Velocity.hpp>
//--------------------------------------------------------
//! @brief 移動処理の更新
//--------------------------------------------------------
void MovementSystem::Update(entt::registry& registry, float deltaTime) {
	// PositionとVelocityを持つEntity を取得
	const auto view = registry.view<Position, Velocity>();

	// 各Entityの位置を速度分だけ更新
	view.each([deltaTime](auto entity, Position& pos, const Velocity& vel) {
		pos.x += vel.x * deltaTime;
		pos.y += vel.y * deltaTime;
		});
}