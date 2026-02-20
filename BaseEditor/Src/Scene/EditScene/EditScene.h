#pragma once
#include<vector>
#include<string>
#include<map>
#include "../SceneBase.h"
#include"../../Utility/AsoUtility.h"
class EditScene :
    public SceneBase
{
public:
	EditScene(void);
	~EditScene(void)override;
	void Load(void)override;

	// 初期化
	void Init(void) override;
	// 更新
	void Update(void) override;
	// 描画
	void Draw(void) override;
	// 解放
	void Release(void) override;

private:
	//Actor下のオブジェクトのファイルのクラス名と変数名を取得
	void RegisterActorClassInfo(void);

private:
	// ファイルパス管理（これは今まで通りでOK）
	std::vector<std::string> actorFullPaths_;
	std::vector<std::string> componentFullPaths_;

	// key: クラス名, value: VariableInfo(型と名前)のリスト
	std::map<std::string, std::vector<VariableInfo>> classDatabase_;

};

