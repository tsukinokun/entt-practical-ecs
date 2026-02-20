//--------------------------------------------------------
//! @file   main.cpp
//! @brief  Transformと親子関係のサンプルコード
//! @author つきの
//--------------------------------------------------------
#include <entt/entt.hpp>
#include <Core/GameLoop.hpp>
#include <Core/SystemManager.hpp>
#include <Systems/MovementSystem.hpp>
#include <Systems/TransformSystem.hpp>
#include <Systems/LogSystem.hpp>
#include <Components/Transform.hpp>
#include <Components/Velocity.hpp>
// エントリポイント
int main() {
	// EnTT のレジストリを作成
	entt::registry registry;

	// 親Entity作成
	auto parent = registry.create();					// 親Entityを作成
	auto& tParent = registry.emplace<Transform>(parent);// Transformコンポーネントを親Entityに追加して参照を取得
	tParent.x = 1.0f;									// 親Entityのローカルx座標を設定
	tParent.y = 1.0f;									// 親Entityのローカルy座標を設定
	registry.emplace<Velocity>(parent, 1.0f, 0.5f);		// 親EntityにVelocityコンポーネントを追加

	// 子Entity作成
	auto child = registry.create();						// 子Entityを作成
	auto& tChild = registry.emplace<Transform>(child);	// Transformコンポーネントを子Entityに追加して参照を取得
	tChild.x = 0.5f;									// 子Entityのローカルx座標を設定
	tChild.y = 0.0f;									// 子Entityのローカルy座標を設定
	tChild.SetParent(&tParent);							// 子Entityの親を設定（親Entityの子リストにも自動で登録される）

	// システムマネージャーとゲームループの準備
	SystemManager systemManager;
	GameLoop loop;

	// Systemの準備
	MovementSystem movement;
	LogSystem log;
	TransformSystem transformSystem;

	// 優先度付きで登録（小さいほど先に実行）
	systemManager.AddSystem(&movement, 0);
	systemManager.AddSystem(&transformSystem, 1);
	systemManager.AddSystem(&log, 2);

	// GameLoop を実行
	loop.Run(registry, systemManager);

	// プログラムの終了
	return 0;
}
