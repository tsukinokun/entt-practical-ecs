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
void GameLoop::Run(entt::registry& registry, SystemManager& systemManager,EventSystem& eventSystem) {
	// 時間リテラルを使用するための名前空間
	using namespace std::chrono_literals;

	// 長いので型エイリアスを使用して簡略化
	using clock = std::chrono::steady_clock;
	// ゲームループ開始前の時間を記録
	auto last = clock::now();

	// 簡単なゲームループ(5フレーム分だけ)
	for (int frame = 0; frame < 5; ++frame) {
		//--------------------------------------------------------
		// ここで deltaTime を計算する
		//--------------------------------------------------------
		auto now = clock::now();	// 現在の時間を取得
		float deltaTime = std::chrono::duration<float>(now - last).count();
		last = now;	// 現在の時間を last に保存

		// デバッグ用に deltaTime を表示
		std::cout << "---- Frame " << frame << " (dt=" << deltaTime << ") ----\n";

		// SystemManager に実行を委譲
		systemManager.UpdateAll(registry, deltaTime);
		eventSystem.Update(); // dispatch

		// フレームレートを制限するために少し待つ（例: 60 FPS なら約16ms）
		std::this_thread::sleep_for(16ms);
	}
}