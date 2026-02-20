//--------------------------------------------------------
//! @file   main.cpp
//! @brief  EnTTでGameLoopを構築する最小サンプル
//! @author つきの
//--------------------------------------------------------
#include <iostream>
#include <entt/entt.hpp>
#include <chrono>
#include <thread>

//--------------------------------------------------------
//! @struct Position
//! @brief 位置を表すコンポーネント
//--------------------------------------------------------
struct Position {
	float x;
	float y;
};

//--------------------------------------------------------
//! @struct Velocity
//! @brief 速度を表すコンポーネント
//--------------------------------------------------------
struct Velocity {
	float x;
	float y;
};

//--------------------------------------------------------
//! @brief   位置更新システム
//! @param   registry [in,out] EnTTのレジストリ
//! @details Position と Velocity を持つ Entity の位置を更新する
//--------------------------------------------------------
void UpdatePositionSystem(entt::registry& registry) {
	// Position と Velocity を持つ Entity を走査
	const auto view = registry.view<Position, Velocity>();
	// Entity を更新
	view.each([](auto entity, Position& pos, const Velocity& vel) {
		pos.x += vel.x;
		pos.y += vel.y;
		// 更新後の位置を表示
		std::cout << "Entity " << static_cast<int>(entity)
			<< " Position : (" << pos.x << ", " << pos.y << ")\n";
		});
}

//--------------------------------------------------------
//! @brief GameLoop
//! @param registry [in,out] EnTTのレジストリ
//! @details 毎フレームSystemを実行する
//--------------------------------------------------------
void GameLoop(entt::registry& registry) {
	// この関数内でのみ時間リテラルを有効にする
	using namespace std::chrono_literals;
	// 簡易的なゲームループ（5フレーム分）
	for (int frame = 0; frame < 5; ++frame) {
		std::cout << "---- Frame " << frame << " ----\n";

		// System を実行
		UpdatePositionSystem(registry);

		// 簡易的なフレーム待機（60fps 相当）
		std::this_thread::sleep_for(16ms);
	}
}

// エントリポイント
int main() {
	// Registry を作成
	entt::registry registry;

	// Entity を作成
	entt::entity entity = registry.create();
	registry.emplace<Position>(entity, 0.0f, 0.0f);
	registry.emplace<Velocity>(entity, 1.0f, 0.5f);

	// GameLoopを疑似的に行う
	GameLoop(registry);

	// プログラムの終了
	return 0;
}
