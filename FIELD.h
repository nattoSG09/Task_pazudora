#pragma once
#include "Engine/GameObject.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Text.h"

#include <string>

class FIELD : public GameObject
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
	XMFLOAT3 MousePos;

	//２次元の固定長配列としてFieldを用意
	static const int WIDTH = 6;
	static const int HEIGHT = 5;
	COLOR Field[HEIGHT][WIDTH];
	int selectX, selectY;	//せんたくされた場所
	COLOR selectColor;


	//ドット座標から、3D座標に変換する関数
	XMFLOAT3 ConvDrawPos(float x, float y);

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	FIELD(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	COLOR isField(float _x, float _y);
};