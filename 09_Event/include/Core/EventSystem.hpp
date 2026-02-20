//--------------------------------------------------------
//! @file   EventSystem.hpp
//! @brief  EventBus.dispatch() を呼ぶだけの System
//! @author つきの
//--------------------------------------------------------
#pragma once
#include <Events/EventBus.hpp>
//--------------------------------------------------------
//! @class EventSystem
//! @brief EventBus.dispatch() を呼ぶだけの System
//--------------------------------------------------------
class EventSystem {
public:
	//--------------------------------------------------------
	//! @brief コンストラクタ
	//! @param bus [in] EventBusのインスタンスへの参照
	//--------------------------------------------------------
	EventSystem(EventBus& bus) : bus_(bus) {}

	//--------------------------------------------------------
	//! @brief EventBus.dispatch() を呼ぶだけの更新処理
	//! @param registry [in,out] EnTT のレジストリ（使用しない）
	//--------------------------------------------------------
	void Update() {
		bus_.dispatch();
	}

private:
	EventBus& bus_;
};
