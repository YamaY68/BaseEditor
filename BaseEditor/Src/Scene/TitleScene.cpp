#include "TitleScene.h"
#include <DxLib.h>
#include <iostream>
#include <filesystem>

#include "../Utility/AsoUtility.h"
#include "../Manager/InputManager.h"
#include "../Manager/SceneManager.h"
#include"../Manager/ResourceManager.h"
#include"../Manager/Resource.h"
#include "../Object/Actor/Camera/Camera.h"
#include"../Common/Quaternion.h"
#include"../Object/Common/AnimationController.h"

TitleScene::TitleScene(void)
	:
	imgTitle_(-1),
	SceneBase()
{
}

TitleScene::~TitleScene(void)
{
}

void TitleScene::Load(void)  
{  
}

void TitleScene::Init(void)
{
	std::string name=std::filesystem::path(__FILE__).stem().string();

}

void TitleScene::Update(void)
{
	// ÉVÅ[ÉìëJà⁄
	auto const& ins = InputManager::GetInstance();
	if (ins.IsTrgDown(KEY_INPUT_SPACE))
	{
		sceMng_.ChangeScene(SceneManager::SCENE_ID::GAME);
	}
}

void TitleScene::Draw(void)
{

}

void TitleScene::Release(void)
{
}
