#include "Ball.h"

//コンストラクタ
Ball::Ball(GameObject* parent)
	: GameObject(parent, "Ball")
{
}

//初期化
void Ball::Initialize()
{
	
}

//更新
void Ball::Update()
{
}

//描画
void Ball::Draw()
{
	/*Transform pt;
	Image::Draw(hPict_[NUM]);
	Image::SetTransform(hPict_[NUM],transform_);*/
}

//開放
void Ball::Release()
{
}
