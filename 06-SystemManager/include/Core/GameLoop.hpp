//--------------------------------------------------------
//! @file   GameLoop.hpp
//! @brief  Systemをまとめて実行するループのクラス定義
//! @author つきの
//--------------------------------------------------------
#pragma once
#include <entt/entt.hpp>
#include <Core/SystemManager.hpp>
//--------------------------------------------------------
//! @class GameLoop
//! @brief System をまとめて実行するループ
//--------------------------------------------------------
class GameLoop {
public:
	//--------------------------------------------------------
	// ゲームループの実行を行う関数
	//! @param registry [in,out] EnTT のレジストリ
	//! @param systemManager [in] SystemManager
	//--------------------------------------------------------
	void Run(entt::registry& registry, SystemManager& systemManager);
};
