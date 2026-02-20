//--------------------------------------------------------
//! @file   CollisionSystem.hpp
//! @brief  衝突Copmonentのクラス定義
//! @author つきの
//--------------------------------------------------------
#pragma once
#include <Events/EventBus.hpp>
#include <Systems/ISystem.hpp>
//--------------------------------------------------------
//! @class CollisionSystem
//! @brief 衝突を検出してDamageEventを発行する例
//--------------------------------------------------------
class CollisionSystem : public ISystem {
public:
	//--------------------------------------------------------
	// コンストラクタ
	//! @param bus [in] EventBusのインスタンスへの参照
	//--------------------------------------------------------
	CollisionSystem(EventBus& bus);

	//--------------------------------------------------------
	// 衝突を検出してDamageEventを発行する例
	//! @param registry [in,out] EnTT のレジストリ
	//! @param deltaTime [in] 前フレームからの経過時間
	//--------------------------------------------------------
	void Update(entt::registry& registry, float deltaTime) override;

private:
	EventBus& bus_;	// EventBusへの参照
};
