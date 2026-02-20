//--------------------------------------------------------
//! @file   main.cpp
//! @brief  優先度付きシステムマネージャーの作成例
//! @author つきの
//--------------------------------------------------------
#include <entt/entt.hpp>
#include <Core/GameLoop.hpp>
#include <Core/SystemManager.hpp>
#include <Systems/MovementSystem.hpp>
#include <Systems/LogSystem.hpp>
#include <Components/Position.hpp>
#include <Components/Velocity.hpp>
// エントリポイント
int main() {
	// EnTT のレジストリを作成
	entt::registry registry;

	// Entity 作成
	auto entity = registry.create();
	registry.emplace<Position>(entity, 0.0f, 0.0f);
	registry.emplace<Velocity>(entity, 1.0f, 0.5f);

	// システムマネージャーとゲームループの準備
	SystemManager systemManager;
	GameLoop loop;

	// Systemの準備
	MovementSystem movement;
	LogSystem log;

	// 優先度付きで登録（小さいほど先に実行）
	systemManager.AddSystem(&log, 1);
	systemManager.AddSystem(&movement, 0);

	// GameLoop を実行
	loop.Run(registry, systemManager);

	// プログラムの終了
	return 0;
}
