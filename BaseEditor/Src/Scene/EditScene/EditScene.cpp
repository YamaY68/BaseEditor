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
	RegisterActorClassInfo();
    int a = 0;
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

void EditScene::RegisterActorClassInfo(void)
{
    //探索するファイルの親ディレクトリ
    std::string rootPath = "Src/Object/Actor";

    //再帰的にディレクトリを探索
    for (const auto& entry : std::filesystem::recursive_directory_iterator(rootPath)) {

        //拡張子が.cppを持つ.hファイルのみ
        if (entry.path().extension() == ".cpp") {

            std::filesystem::path headerPath = entry.path().string();
			headerPath.replace_extension(".h");
            
			if (!std::filesystem::exists(headerPath))
			{
				continue;
			}

            //ディレクトリと拡張子を除いたファイル名
			std::string actorName = headerPath.stem().string();
            //フルパス
			std::string fullPath = headerPath.string();

            //nposは見つからなかったときの値
            //見つからなかったのではない＝見つかった
			//基底クラスは除外
            if (fullPath.find("Base") != std::string::npos) {
                continue;
            }
            //Componentクラスかどうかで分ける
            if (fullPath.find("Component") != std::string::npos) {
				componentFullPaths_.push_back(fullPath);
            }
            //Actorクラス
            else
            {
				actorFullPaths_.push_back(fullPath);
            }
        }

        for (const auto& filePath : actorFullPaths_) {
            auto results = AsoUtility::ScanHeader(filePath);
         // 登録処理
            for (const auto& info : results) {
                classDatabase_[info.className] = info.variables;
            }
        }

        //componentFullPaths_ のスキャン部分
        for (const auto& filePath : componentFullPaths_) {
            auto results = AsoUtility::ScanHeader(filePath);
            // 登録処理
            for (const auto& info : results) {
                classDatabase_[info.className] = info.variables;
            }
        }


    }
}
