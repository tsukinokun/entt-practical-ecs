//--------------------------------------------------------
//! @file   GameLoop.cpp
//! @brief  Systemをまとめて実行するループの実装
//! @author つきの
//--------------------------------------------------------
#include <Core/GameLoop.hpp>
#include <Systems/ISystem.hpp>
#include <chrono>
#include <thread>
#include <iostream>
//--------------------------------------------------------
//! @brief Systemを追加
//--------------------------------------------------------
void GameLoop::AddSystem(ISystem* system) {
	// System のリストに追加
	systems_.push_back(system);
}

//--------------------------------------------------------
//! @brief GameLoopの実行
//--------------------------------------------------------
void GameLoop::Run(entt::registry& registry) {
	// 時間リテラルを使用するためのusing宣言
	using namespace std::chrono_literals;

	// 簡単なループでSystemを更新
	for (int frame = 0; frame < 5; ++frame) {
		// フレームの開始を表示
		std::cout << "---- Frame " << frame << " ----\n";

		// 各Systemを更新
		for (auto* system : systems_) {
			system->Update(registry);
		}

		// フレームレートを制限するために少し待つ
		std::this_thread::sleep_for(16ms);
	}
}