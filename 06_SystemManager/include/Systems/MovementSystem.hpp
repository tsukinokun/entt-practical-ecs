//--------------------------------------------------------
//! @file	MovementSystem.hpp
//! @brief	座標を更新するSystemのクラス定義
//! @author つきの
//--------------------------------------------------------
#pragma once
#include "ISystem.hpp"
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
	void Update(entt::registry& registry) override;
};
