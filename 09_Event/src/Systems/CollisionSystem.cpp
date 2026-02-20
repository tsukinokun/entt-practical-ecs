//--------------------------------------------------------
//! @file	CollisionSystem.cpp
//! @brief	衝突コンポーネントの実装
//! @author つきの
//--------------------------------------------------------
#include <Events/DamageEvent.hpp>
#include <Systems/CollisionSystem.hpp>
#include <Components/Health.hpp>
//--------------------------------------------------------
//! @brief コンストラクタ
//--------------------------------------------------------
CollisionSystem::CollisionSystem(EventBus& bus) :
	bus_(bus) {	// EventBusへの参照を保存
}

//--------------------------------------------------------
//! @brief 衝突を検出してDamageEventを発行する例
//--------------------------------------------------------
void CollisionSystem::Update(entt::registry& registry, float deltaTime) {
	const auto view = registry.view<Health>();	// Healthコンポーネントを持つEntityを取得

	// 各Entityに対してDamageEventを発行
	view.each([&](entt::entity entity, const Health&) {
		// ここでは単純に全てのEntityに1ダメージを与える例
		DamageEvent evt(entity, 1);
		bus_.publish(evt);	// DamageEventを発行
		});
}