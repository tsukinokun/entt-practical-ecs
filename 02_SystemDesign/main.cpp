//--------------------------------------------------------
//! @file   main.cpp
//! @brief  EnTTでSystemを設計する最小サンプル
//! @author つきの
//--------------------------------------------------------
#include <iostream>
#include <entt/entt.hpp>

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
//! @brief  速度を表すコンポーネント
//--------------------------------------------------------
struct Velocity {
	float x;
	float y;
};

//--------------------------------------------------------
//! @brief	 位置更新システム
//! @param	 registry [in,out] EnTTのレジストリ
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

// エントリポイント
int main() {
	// Registry を作成
	entt::registry registry;

	// Entity を作成
	entt::entity entity = registry.create();
	
	// Component を付与
	registry.emplace<Position>(entity, 0.0f, 0.0f);
	registry.emplace<Velocity>(entity, 1.0f, 0.5f);

	// 位置更新システムを実行
	UpdatePositionSystem(registry);

	// プログラムの終了
	return 0;
}

