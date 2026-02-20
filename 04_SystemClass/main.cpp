//--------------------------------------------------------
//! @file   main.cpp
//! @brief  System をクラス化した最小 ECS サンプル（複数 System 版）
//! @author つきの
//--------------------------------------------------------
#include <iostream>
#include <vector>
#include <entt/entt.hpp>
#include <chrono>
#include <thread>

//--------------------------------------------------------
//! @struct Position
//! @brief  位置を表すコンポーネント
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
//! @class ISystem
//! @brief 全ての System の基底クラス
//--------------------------------------------------------
class ISystem {
public:
	//--------------------------------------------------------
	//! @brief デストラクタ
	//--------------------------------------------------------
	virtual ~ISystem() = default;

	//--------------------------------------------------------
	//! @brief System の更新処理
	//! @param registry [in,out] EnTT のレジストリ
	//--------------------------------------------------------
	virtual void Update(entt::registry& registry) = 0;
};

//--------------------------------------------------------
//! @class MovementSystem
//! @brief Position と Velocity を使って位置を更新する System
//--------------------------------------------------------
class MovementSystem : public ISystem {
public:
	//--------------------------------------------------------
	//! @brief 移動処理の更新
	//! @param registry [in,out] EnTT のレジストリ
	//--------------------------------------------------------
	void Update(entt::registry& registry) override {
		// PositionとVelocityを持つEntity を取得
		const auto view = registry.view<Position, Velocity>();

		// 各Entityの位置を速度分だけ更新
		view.each([](auto entity, Position& pos, const Velocity& vel) {
			pos.x += vel.x;
			pos.y += vel.y;
			});
	}
};

//--------------------------------------------------------
//! @class LogSystem
//! @brief Position を使って位置をログ出力する System
//--------------------------------------------------------
class LogSystem : public ISystem {
public:
	//--------------------------------------------------------
	//! @brief ログ出力処理の更新
	//! @param registry [in,out] EnTT のレジストリ
	//--------------------------------------------------------
	void Update(entt::registry& registry) override {
		// Positionを持つEntity を取得
		const auto view = registry.view<Position>();

		// 各Entityの位置をログ出力
		view.each([](auto entity, const Position& pos) {
			std::cout << "Entity " << static_cast<int>(entity)
				<< " Render Position : (" << pos.x << ", " << pos.y << ")\n";
			});
	}
};

//--------------------------------------------------------
//! @class GameLoop
//! @brief System をまとめて実行するループ
//--------------------------------------------------------
class GameLoop {
public:
	//--------------------------------------------------------
	//! @brief System を追加
	//! @param system [in] 追加する System のポインタ
	//--------------------------------------------------------
	void AddSystem(ISystem* system) {
		systems_.push_back(system);
	}

	//--------------------------------------------------------
	//! @brief GameLoop の実行
	//! @param registry [in,out] EnTT のレジストリ
	//--------------------------------------------------------
	void Run(entt::registry& registry) {
		// 時間リテラルを使用するためのusing宣言
		using namespace std::chrono_literals;

		// 簡単なループでSystemを更新
		for (int frame = 0; frame < 5; ++frame) {
			std::cout << "---- Frame " << frame << " ----\n";

			// 各Systemを更新
			for (auto* system : systems_) {
				system->Update(registry);
			}

			// フレームレートを制限するために少し待つ
			std::this_thread::sleep_for(16ms);
		}
	}

private:
	std::vector<ISystem*> systems_; // System のリスト
};

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

	// SystemをGameLoopに追加
	loop.AddSystem(&movement);
	loop.AddSystem(&render);

	// 実行
	loop.Run(registry);

	//プログラムの終了
	return 0;
}
