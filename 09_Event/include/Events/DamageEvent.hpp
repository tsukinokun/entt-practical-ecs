//--------------------------------------------------------
//! @file   DamageEvent.hpp
//! @brief  ダメージイベント（例）
//--------------------------------------------------------
#pragma once
#include <entt/entt.hpp>
//--------------------------------------------------------
//! @struct  DamageEvent
//! @brief   ダメージイベントの構造体
//--------------------------------------------------------
struct DamageEvent {
	//--------------------------------------------------------
	//! @brief コンストラクタ
	//! @param target [in] ダメージを受けるEntity
	//! @param amount [in] ダメージ量
	//--------------------------------------------------------
	DamageEvent(entt::entity target, int amount) 
		: target(target), amount(amount) {}

	entt::entity target;	// ダメージを受けるEntity
	int amount;				// ダメージ量
};