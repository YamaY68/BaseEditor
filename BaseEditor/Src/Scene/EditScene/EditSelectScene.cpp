#include "EditSelectScene.h"
#include <filesystem>
#include<DxLib.h>
#include"../../Manager/SceneManager.h"

EditSelectScene::EditSelectScene(void)
{
}

EditSelectScene::~EditSelectScene(void)
{
}

void EditSelectScene::Load(void)
{
    std::string currentDir = ".";
    gameFilePaths_.clear();

    for (const auto& entry : std::filesystem::directory_iterator(currentDir))
    {
        // フォルダ（ディレクトリ）のみを取得
        if (entry.is_directory())
        {
            // フォルダ名を取得
            std::string dirName = entry.path().filename().string();
            gameFilePaths_.push_back(dirName);
        }
    }
}

void EditSelectScene::Init(void)
{
}

void EditSelectScene::Update(void)
{
    if (gameFilePaths_.empty()) return;

    // 下キーで次へ
    if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
        selectIndex_++;
        if (selectIndex_ >= (int)gameFilePaths_.size()) selectIndex_ = 0; // ループ
        WaitKey(); // 連続移動防止（簡易版）
    }

    // 上キーで前へ
    if (CheckHitKey(KEY_INPUT_UP) == 1) {
        selectIndex_--;
        if (selectIndex_ < 0) selectIndex_ = (int)gameFilePaths_.size() - 1; // ループ
        WaitKey(); // 連続移動防止（簡易版）
    }

    // Enterで決定
    if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
        SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::EDIT,gameFilePaths_[selectIndex_]);
    }
}

void EditSelectScene::Draw(void)
{
    int x = 50;
    int y = 50;
    unsigned int white = GetColor(255, 255, 255);
    unsigned int yellow = GetColor(255, 255, 0);

    DrawString(x, y, "--- 編集するファイルを選択 (上下キーで移動 / Enterで決定) ---", white);
    y += 40;

    if (gameFilePaths_.empty()) {
        DrawString(x, y, "ファイルが見つかりません（エグゼと同じ階層に置いてください）", GetColor(255, 100, 100));
        return;
    }

    for (int i = 0; i < (int)gameFilePaths_.size(); ++i) {
        if (i == selectIndex_) {
            // 選択中の行：黄色＋カーソル
            std::string text = "> " + gameFilePaths_[i];
            DrawString(x - 20, y, text.c_str(), yellow);
        }
        else {
            // 非選択行：白
            std::string text = "  " + gameFilePaths_[i];
            DrawString(x - 20, y, text.c_str(), white);
        }
        y += 25;
    }
}
void EditSelectScene::Release(void)
{
}
