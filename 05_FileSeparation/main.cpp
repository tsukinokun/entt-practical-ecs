//--------------------------------------------------------
//! @file   main.cpp
//! @brief  ファイル分割したECSサンプル
//! @author つきの
//--------------------------------------------------------
#include <entt/entt.hpp>
#include <Core/GameLoop.hpp>
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

	// GameLoop と System の準備
	GameLoop loop;
	MovementSystem movement;
	LogSystem render;

	// System を GameLoop に追加
	loop.AddSystem(&movement);
	loop.AddSystem(&render);

	// GameLoop を実行
	loop.Run(registry);

	// プログラムの終了
	return 0;
}