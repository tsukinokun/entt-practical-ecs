//--------------------------------------------------------
//! @file   DamageSystem.hpp
//! @brief  DamageEvent を購読して HP を減らす System
//--------------------------------------------------------
#pragma once
#include <Events/EventBus.hpp>
#include <entt/entt.hpp>
//--------------------------------------------------------
//! @class DamageSystem
//! @brief DamageEventを購読してHPを減らすSystem
//--------------------------------------------------------
class DamageSystem {
public:
	//--------------------------------------------------------
	// DamageEventを購読してHPを減らすコールバックを登録
	//! @param bus      [in,out] EventBusのインスタンス
	//! @param registry [in,out] EnTTのレジストリ
	//--------------------------------------------------------
	void Register(EventBus& bus, entt::registry& registry);
};
