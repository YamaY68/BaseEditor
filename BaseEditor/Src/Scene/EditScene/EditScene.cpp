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
    std::string rootPath = "Src/Object/Actor";

    for (const auto& entry : std::filesystem::recursive_directory_iterator(rootPath)) {

        if (entry.is_regular_file() && entry.path().extension() == ".cpp") {

            std::string actorName = entry.path().stem().string();

            std::string fullPath = entry.path().string();
            
            //
            //nposÇÕå©Ç¬Ç©ÇÁÇ»Ç©Ç¡ÇΩÇ∆Ç´ÇÃíl
            //å©Ç¬Ç©ÇÁÇ»Ç©Ç¡ÇΩÇÃÇ≈ÇÕÇ»Ç¢ÅÅå©Ç¬Ç©Ç¡ÇΩ
			if (fullPath.find("Base") != std::string::npos) {
                continue;
            }

			if (fullPath.find("Component") != std::string::npos) {
				componentFileNames_.push_back(actorName);
            }
            else
            {
			actorFileNames_.push_back(actorName);
            }
        }
    }
}
