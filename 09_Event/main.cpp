//--------------------------------------------------------
//! @file   main.cpp
//! @brief  EventBusを使ったイベント駆動ECSのサンプルコード
//! @author つきの
//--------------------------------------------------------
#include <entt/entt.hpp>
#include <Core/SystemManager.hpp>
#include <Core/GameLoop.hpp>

#include <Events/EventBus.hpp>
#include <Core/EventSystem.hpp>

#include <Systems/DamageSystem.hpp>

#include <Systems/CollisionSystem.hpp>
#include <Systems/LogSystem.hpp>

#include <Components/Health.hpp>

// エントリポイント
int main() {
	// EnTT のレジストリ
	entt::registry registry;

	// Health を持つ Entity を 1 つ作成
	auto e = registry.create();
	registry.emplace<Health>(e, 10);   // HP = 10

	// EventBus
	EventBus eventBus;

	// DamageSystem（イベント受信）
	DamageSystem damageSystem;
	damageSystem.Register(eventBus, registry); // DamageEvent を受信して HP を減らすコールバックを登録

	// CollisionSystem（イベント発行）
	CollisionSystem collisionSystem(eventBus);
	// HPをログ出力するSystem（イベントとは関係ない）
	LogSystem logSystem;

	// EventSystem（dispatch 専用）
	EventSystem eventSystem(eventBus);

	// SystemManager（優先度順に実行）
	SystemManager systemManager;
	systemManager.AddSystem(&collisionSystem, 0); // まず衝突 → DamageEvent 発行
	systemManager.AddSystem(&logSystem, 1);		// 次にイベントを配信

	// GameLoop 実行
	GameLoop loop;

	// ゲームループを実行
	loop.Run(registry, systemManager, eventSystem);

	return 0;
}
