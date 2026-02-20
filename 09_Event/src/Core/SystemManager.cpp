//--------------------------------------------------------
//! @file   SystemManager.cpp
//! @brief  SystemManagerクラスの実装
//! @author つきの
//--------------------------------------------------------
#include <Core/SystemManager.hpp>
#include <Systems/ISystem.hpp>
//--------------------------------------------------------
//! @brief Systemを追加し、優先度順にソートする
//--------------------------------------------------------
void SystemManager::AddSystem(ISystem* system, int priority) {
	// System と優先度をリストに追加
	systems_.push_back({ priority, system });

	// 優先度の昇順でソート
	std::sort(systems_.begin(), systems_.end(),
		[](const SystemEntry& a, const SystemEntry& b) {
			return a.priority < b.priority;
		});
}

//--------------------------------------------------------
//! @brief 登録されたSystemを優先度順に実行
//--------------------------------------------------------
void SystemManager::UpdateAll(entt::registry& registry, float deltaTime) {
	// 優先度順に System を実行
	for (auto& entry : systems_) {
		entry.system->Update(registry, deltaTime);
	}
}