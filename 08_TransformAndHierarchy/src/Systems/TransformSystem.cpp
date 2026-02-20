//--------------------------------------------------------
//! @file   TransformSystem.cpp
//! @brief  TransformのworldTransformを更新するSystemの実装
//! @author つきの
//--------------------------------------------------------
#include <Components/Transform.hpp>
#include <Systems/TransformSystem.hpp>
//--------------------------------------------------------
//! @brief TransformSystemの更新処理
//--------------------------------------------------------
void TransformSystem::Update(entt::registry& registry, float deltaTime) {
	// Transformを持つEntity を取得
	auto view = registry.view<Transform>();

	// 各Entityのワールド変換を更新
	view.each([deltaTime](auto entity, Transform& pos) {
		// dirty のときだけ更新
		if (pos.dirty) {
			// ワールド変換を更新
			pos.UpdateWorldTransform();
		}
		});
}