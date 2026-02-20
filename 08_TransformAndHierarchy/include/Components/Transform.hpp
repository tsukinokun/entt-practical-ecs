//--------------------------------------------------------
//! @file	Transform.hpp
//! @brief	2DTransform（位置・回転・スケール + 親子関係）
//! @author つきの
//--------------------------------------------------------
#pragma once
#include <vector>
//--------------------------------------------------------
//! @struct Transform
//! @brief 2DTransform（位置・回転・スケール + 親子関係）
//--------------------------------------------------------
struct Transform {
	// ローカル座標系 
	float x = 0.0f;		   // ローカルx座標
	float y = 0.0f;		   // ローカルy座標
	float rotation = 0.0f; // ラジアン
	float scaleX = 1.0f;   // ローカルxスケール
	float scaleY = 1.0f;   // ローカルyスケール

	// 親子関係 
	Transform* parent = nullptr;		// 親Transformへのポインタ
	std::vector<Transform*> children;	// 子Transformへのポインタリスト

	// ワールド変換キャッシュ
	bool dirty = true;			// ワールド変換が最新かどうかのフラグ
	float worldX = 0.0f;		// ワールドx座標
	float worldY = 0.0f;		// ワールドy座標
	float worldRotation = 0.0f;	// ワールド回転
	float worldScaleX = 1.0f;	// ワールドxスケール
	float worldScaleY = 1.0f;	// ワールドyスケール

	//--------------------------------------------------------
	//! @brief 親を設定する（子リストへの登録も行う）
	//! @param newParent 新しい親Transformへのポインタ
	//--------------------------------------------------------
	void SetParent(Transform* newParent) {
		// 既存の親から子リストを削除
		parent = newParent;

		// 新しい親の子リストに自身を追加
		if (parent) {
			parent->children.push_back(this);
		}

		// ワールド変換を更新する必要がある
		dirty = true;
	}

	//--------------------------------------------------------
	//! @brief 自身と子の worldTransform を更新する（再帰）
	//--------------------------------------------------------
	void UpdateWorldTransform() {
		if (parent) {
			// 親の world を継承
			worldX = parent->worldX + x;
			worldY = parent->worldY + y;
			worldRotation = parent->worldRotation + rotation;
			worldScaleX = parent->worldScaleX * scaleX;
			worldScaleY = parent->worldScaleY * scaleY;
		}
		else {
			// 親がいない場合は local = world
			worldX = x;
			worldY = y;
			worldRotation = rotation;
			worldScaleX = scaleX;
			worldScaleY = scaleY;
		}

		dirty = false;

		// 子も再帰的に更新
		for (auto* child : children) {
			// 子のワールド変換も更新する必要がある
			child->dirty = true;
			// 子のワールド変換を更新
			child->UpdateWorldTransform();
		}
	}
};