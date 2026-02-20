//--------------------------------------------------------
//! @file   SystemManager.hpp
//! @brief  Systemの登録・実行を管理するクラス定義
//! @author つきの
//--------------------------------------------------------
#pragma once
#include <vector>
#include <algorithm>
#include <entt/entt.hpp>
class ISystem;	// 前方宣言
//--------------------------------------------------------
//! @class SystemManager
//! @brief System の登録と実行順序（優先度）を管理するクラス
//--------------------------------------------------------
class SystemManager {
public:
	//--------------------------------------------------------
	// System を登録する
	//! @param system   [in] 登録する System
	//! @param priority [in] 実行優先度（小さいほど先に実行）
	//--------------------------------------------------------
	void AddSystem(ISystem* system, int priority);

	//--------------------------------------------------------
	// 登録された System を優先度順に実行する
	//! @param registry [in,out] EnTT のレジストリ
	//--------------------------------------------------------
	void UpdateAll(entt::registry& registry);

private:
	//--------------------------------------------------------
	//! @struct Systemと優先度をまとめた構造体
	//--------------------------------------------------------
	struct SystemEntry {
		int priority;		// 実行優先度
		ISystem* system;	// System のポインタ
	};

	std::vector<SystemEntry> systems_;	// 登録された System とその優先度のリスト
};