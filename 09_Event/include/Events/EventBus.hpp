//--------------------------------------------------------
//! @file   EventBus.hpp
//! @brief  シンプルなイベントバス（publish / subscribe / dispatch）
//! @author つきの
//--------------------------------------------------------
#pragma once
#include <unordered_map>
#include <vector>
#include <functional>
#include <typeindex>
#include <any>
//--------------------------------------------------------
//! @class EventBus
//! @brief シンプルなイベントバス（publish / subscribe / dispatch）
//--------------------------------------------------------
class EventBus {
public:
	//--------------------------------------------------------
	//! @brief  Event を発行（キューに積む）
	//! @tparam Event 発行するイベントの型
	//! @param  event [in] 発行するイベントのインスタンス
	//--------------------------------------------------------
	template<typename Event>
	void publish(const Event event) {
		// イベントを std::any に変換してキューに積む
		events_[typeid(Event)].push_back(event);
	}

	//--------------------------------------------------------
	//! @brief Event を購読（コールバック登録）
	//! @tparam Event 購読するイベントの型
	//! @param  callback [in] イベントを受け取るコールバック関数（引数は const Event&）
	//--------------------------------------------------------
	template<typename Event>
	void subscribe(std::function<void(const Event&)> callback) {
		// コールバックを std::function<void(const std::any&)> に変換して登録
		auto& vec = subscribers_[typeid(Event)];

		// 登録されたコールバックは std::anyをEventにキャストして呼び出す
		vec.push_back([callback](const std::any& e) {
			callback(std::any_cast<const Event&>(e));
			});
	}

	//--------------------------------------------------------
	//! @brief 1フレーム分のEventを配信
	//--------------------------------------------------------
	void dispatch() {
		//--------------------------------------------------------
		// イベントキューを走査して、登録されたコールバックを呼び出す
		//--------------------------------------------------------
		for (auto& [type, eventList] : events_) {
			// イベントの型に対応する購読者リストを取得
			auto subIt = subscribers_.find(type);
			// 購読者がいない場合はスキップ
			if (subIt == subscribers_.end()) continue;
			// 各イベントに対して、登録されたコールバックを呼び出す
			for (auto& e : eventList) {
				// 登録されたコールバックを呼び出す
				for (auto& callback : subIt->second) {
					callback(e);
				}
			}
		}
		// 配信後はイベントキューをクリア
		events_.clear();
	}

private:
	// Event キュー
	std::unordered_map<std::type_index, std::vector<std::any>> events_;

	// 購読者リスト
	std::unordered_map<std::type_index,
		std::vector<std::function<void(const std::any&)>>> subscribers_;
};
