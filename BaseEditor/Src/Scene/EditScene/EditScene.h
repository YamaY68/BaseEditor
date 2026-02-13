#pragma once
#include<vector>
#include<string>

#include "../SceneBase.h"
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
	//Actor下のオブジェクトのファイル名を取得
	void RegisterActorFileNames(void);

	
private:
	std::vector<std::string>actorFileNames_;
	std::vector<std::string>componentFileNames_;

};

