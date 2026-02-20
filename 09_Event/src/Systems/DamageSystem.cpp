//--------------------------------------------------------
//! @file	DamageSystem.cpp
//! @brief	DamageEventを購読してHPを減らすSystemのクラス定義
//! @author つきの
//--------------------------------------------------------
#include <Systems/DamageSystem.hpp>
#include <Components/Health.hpp>
#include <Events/DamageEvent.hpp>
//--------------------------------------------------------
//! @brief DamageEventを購読してHPを減らすコールバックを登録
//--------------------------------------------------------
void DamageSystem::Register(EventBus& bus, entt::registry& registry) {
	// DamageEventを受け取るコールバック関数を定義
	auto callback = [&registry](const DamageEvent& e) {
		// ダメージイベントの対象EntityがHealthコンポーネントを持っているか確認
		if (registry.all_of<Health>(e.target)) {
			// Healthコンポーネントを取得してHPを減らす
			auto& hp = registry.get<Health>(e.target);
			// HPを減らす（0未満にならないように）
			hp.value -= e.amount;
		}
		};

	// DamageEventを購読してHPを減らすコールバックを登録
	bus.subscribe<DamageEvent>(callback);
}