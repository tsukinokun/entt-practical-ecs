//--------------------------------------------------------
//! @file   TransformSystem.hpp
//! @brief  TransformのworldTransformを更新するSystemのクラス定義
//! @author つきの
//--------------------------------------------------------
#pragma once
#include "ISystem.hpp"
//--------------------------------------------------------
//! @class   TransformSystem
//! @brief	 TransformのworldTransformを更新するSystem
//! @details Transformのdirtyフラグを見て、必要なときだけワールド変換を更新する
//--------------------------------------------------------
class TransformSystem : public ISystem {
public:
	//--------------------------------------------------------
	// TransformSystemの更新処理
	//! @param registry [in,out] EnTT のレジストリ
	//--------------------------------------------------------
	void Update(entt::registry& registry, float deltaTime) override;
};