#pragma once
#include "Engine/GameObject.h"
#include "Engine/Image.h"

#include <string>

class Ball: public GameObject
{
private:
	enum COLOR {
		RED = 0,
		BLUE,
		YELLOW,
		GREEN,
		PURPLE,
		HEART,
		NUM
	};

	int hPict_[NUM];

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Ball(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};