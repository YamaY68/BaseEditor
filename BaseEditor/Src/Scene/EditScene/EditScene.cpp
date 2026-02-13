#include<DxLib.h>
#include "EditScene.h"

#include"../../Manager/SceneManager.h"
#include"../../Manager/ResourceManager.h"

#include"../../Object/Actor/Component/ComponentBase.h"
#include"../../Object/Actor/Component/RigidBodyComponent/RigidBody.h"
#include"../../Object/Actor/Component/PlayerInputComponent/PlayerInputComponent.h"

#include"../../Object/Actor/ActorBase.h"

#include"../../Object/Actor/Shape/ShapeBase.h"
#include"../../Object/Actor/Shape/Box.h"
#include"../../Object/Actor/Shape/Sphere.h"
#include"../../Object/Actor/Shape/Capsule.h"

#include"../../Object/Actor/Camera/Camera.h"

EditScene::EditScene(void)
{

}

EditScene::~EditScene(void)
{

}

void EditScene::Load(void)
{
	RegisterActorFileNames();
}

void EditScene::Init(void)
{

}

void EditScene::Update(void)
{

}

void EditScene::Draw(void)
{

}

void EditScene::Release(void)
{

}

void EditScene::RegisterActorFileNames(void) {
	//探索するファイルの親ディレクトリ
    std::string rootPath = "Src/Object/Actor";

	//再帰的にディレクトリを探索
    for (const auto& entry : std::filesystem::recursive_directory_iterator(rootPath)) {

		//拡張子が.cppのものだけ
        if (entry.path().extension() == ".cpp") {

			//ディレクトリと拡張子を除いたファイル名
            std::string actorName = entry.path().stem().string();
			//フルパス
            std::string fullPath = entry.path().string();
            
            //nposは見つからなかったときの値
            //見つからなかったのではない＝見つかった
			if (fullPath.find("Base") != std::string::npos) {
                continue;
            }
			//Componentクラスかどうかで分ける
			if (fullPath.find("Component") != std::string::npos) {
				componentFileNames_.push_back(actorName);
            }
			//Actorクラス
            else
            {
                actorFileNames_.push_back(actorName);
            }
        }
    }
}
