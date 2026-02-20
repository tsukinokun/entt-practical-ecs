# 06_SystemManager
このプロジェクトでは、複数の``System``をまとめて管理し、**更新順序を制御するためのSystemManager** を実装します。  

``ECS``では``System``が増えるほど、**どの順番で実行するべきか**/**どう管理するか**が重要になります。  
``SystemManager``はその問題を解決するための仕組みです。

## 📘 学べること
- ``SystemManager``の基本的な設計と実装方法
- ``System``の``登録（Register）``と保持 
- ``ISystem``インターフェースによる共通化  
- すべての``System``を順番に実行する``Update``処理  
- ``GameLoop``をシンプルに保つ設計手法  