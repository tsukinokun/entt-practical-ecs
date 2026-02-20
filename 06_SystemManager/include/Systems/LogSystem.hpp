//--------------------------------------------------------
//! @file	LogSystem.hpp
//! @brief	Positionを使って位置をログ出力するSystemのクラス定義
//! @author つきの
//--------------------------------------------------------
#pragma once
#include "ISystem.hpp"
//--------------------------------------------------------
//! @class LogSystem
//! @brief Positionを使って位置をログ出力するSystem
//--------------------------------------------------------
class LogSystem : public ISystem {
public:
	//--------------------------------------------------------
	//! @brief ログ出力処理の更新
	//! @param registry [in,out] EnTT のレジストリ
	//--------------------------------------------------------
	void Update(entt::registry& registry) override;
};