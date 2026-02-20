//--------------------------------------------------------
//! @file   GameLoop.cpp
//! @brief  GameLoop クラスの実装
//! @author つきの
//--------------------------------------------------------
#include <Core/GameLoop.hpp>
#include <chrono>
#include <thread>
#include <iostream>
//--------------------------------------------------------
//! @brief ゲームループの実行を行う関数
//--------------------------------------------------------
void GameLoop::Run(entt::registry& registry, SystemManager& systemManager) {
	// 時間リテラルを使用するための名前空間
	using namespace std::chrono_literals;

	// 簡単なゲームループ(5フレーム分だけ)
	for (int frame = 0; frame < 5; ++frame) {
		std::cout << "---- Frame " << frame << " ----\n";

		// SystemManager に実行を委譲
		systemManager.UpdateAll(registry);

		// フレームレートを制限するために少し待つ（例: 60 FPS なら約16ms）
		std::this_thread::sleep_for(16ms);
	}
}