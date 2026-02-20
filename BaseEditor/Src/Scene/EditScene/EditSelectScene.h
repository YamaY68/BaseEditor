#pragma once
#include<string>
#include<vector>
#include "../SceneBase.h"
class EditSelectScene :
    public SceneBase
{
public:
	EditSelectScene(void);
	~EditSelectScene(void)override;
	// 読み込み
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
	//編集するゲームのファイルパス
	std::vector<std::string> gameFilePaths_;
	//選択中のゲームのインデックス
	int selectIndex_ = 0;
};

