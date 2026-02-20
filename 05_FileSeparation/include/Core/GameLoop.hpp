//--------------------------------------------------------
//! @file   GameLoop.hpp
//! @brief  Systemをまとめて実行するループのクラス定義
//! @author つきの
//--------------------------------------------------------
#pragma once
#include <vector>
#include <entt/entt.hpp>
class ISystem; // 前方宣言
//--------------------------------------------------------
//! @class GameLoop
//! @brief System をまとめて実行するループ
//--------------------------------------------------------
class GameLoop {
public:
	//--------------------------------------------------------
	// System を追加
	//! @param system [in] 追加する System のポインタ
	//--------------------------------------------------------
	void AddSystem(ISystem* system);

	//--------------------------------------------------------
	// GameLoop の実行
	//! @param registry [in,out] EnTT のレジストリ
	//--------------------------------------------------------
	void Run(entt::registry& registry);

private:
	std::vector<ISystem*> systems_; // System のリスト
};
