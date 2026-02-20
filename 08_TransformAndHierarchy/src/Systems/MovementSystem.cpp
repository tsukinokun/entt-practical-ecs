//--------------------------------------------------------
//! @file	MovementSystem.cpp
//! @brief	座標を更新するSystemのクラス定義
//! @author つきの
//--------------------------------------------------------
#include <Systems/MovementSystem.hpp>
#include <Components/Transform.hpp>
#include <Components/Velocity.hpp>
//--------------------------------------------------------
//! @brief 移動処理の更新
//--------------------------------------------------------
void MovementSystem::Update(entt::registry& registry, float deltaTime) {
	// PositionとVelocityを持つEntity を取得
	const auto view = registry.view<Transform, Velocity>();

	// 各Entityの位置を速度分だけ更新
	view.each([deltaTime](auto entity, Transform& pos, const Velocity& vel) {
		// ローカル座標を更新
		pos.x += vel.x * deltaTime;
		pos.y += vel.y * deltaTime;

		// ワールド変換も更新する必要があるので、状態が最新ではないフラグを立てる
		pos.dirty = true;
		});
}