![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
# entt-practical-ecs
本リポジトリは、``EnTT``を用いて実務で使用できるレベルの``ECS``を段階的に理解することを目的に作成しました。

各章(各プロジェクト)は独立したサンプルとして動作します。

## 📘 目的
- ``ECS``の基本概念を**段階的**に理解する
- ``Transform``/``親子関係``/``SystemManager``/``GameLoop``/``EventBus``などの基礎アーキテクチャを学ぶ
- 実務で使用できるレベルの``ECS``を構築するための知識を得る

## 📂 プロジェクト構成

### 01_BasicEntt
-  ``EnTT``の最小サンプル
- ライブラリの基本的な使い方を理解するためのプロジェクト

### 02_SystemDesign
- ``System``の設計と実装サンプル

### 03_GameLoop
- 基本的なゲームループの実装サンプル

### 04_SystemClass
- ``System``をクラスとして実装するサンプル

### 05_FileSeparation
- ``System``をファイル分割して実装するサンプル

### 06_SystemManager
- ``SystemManager``を実装して、システムの管理と実行を行うサンプル

### 07_DeltaTime
- ``DeltaTime``を使用して、フレームレートに依存しないゲームループを実装するサンプル
- ``std::chrono``を使用して、時間の管理を行う方法を学ぶ

### 08_TransformAndHierarchy
- ``Transform``コンポーネントの実装サンプル
- 親子関係の管理方法を学ぶためのプロジェクト

### 09_EventBus
- ``EventBus``の実装サンプル
- ``イベント駆動``と``ECS``を組み合わせたシステム設計を学ぶためのプロジェクト
- イベントの発行と購読の基本的な仕組みを紹介

## 📄 License 
このプロジェクトは``MIT License``の下で公開されています。詳細は[MIT License](./LICENSE)を参照してください。

## ✨ 作者  
**山﨑 愛** 
- [Qiita: tsukino_](https://qiita.com/tsukino_) 
- [GitHub: tsukino](https://github.com/tsukinokun)