#include "FIELD.h"


namespace {
	static const int size = 40;	//ボールの直径(40ドット)
	static const int left = 60;	//盤面の左の位置
	static const int top = 80;	//盤面の上の位置
	const float wGap = 0.06;
	const float hGap = 0.115;

};

//ドット座標から、3D座標に変換する関数
XMFLOAT3 FIELD::ConvDrawPos(float x, float y)
{
	XMFLOAT3 p;
	p.x = x / size * wGap;
	p.y = -y / size * hGap;
	p.z = 0;
	return p;
}

//コンストラクタ
FIELD::FIELD(GameObject* parent)
	: GameObject(parent, "FIELD")
{
	//Fieldの配列をすべて"RED"にする
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			Field[h][w] = (COLOR)(rand() % COLOR::NUM);
			int m = size;
			selectX = -1;
			selectY = -1;
		}
	}
}

//初期化
void FIELD::Initialize()
{
	//ファイルのロード
	std::string filename[NUM] = { "ball/ball0.png","ball/ball1.png", "ball/ball2.png", "ball/ball3.png",
		"ball/ball4.png","ball/ball5.png" };

	for (int n = 0; n < NUM; n++) {
		hPict_[n] = Image::Load(filename[n]);
	}
}

//更新
void FIELD::Update()
{
	//現在のマウスカーソルの座標を取得
	MousePos = Input::GetMousePosition();

	//ドット座標に合わせるための計算↓
	MousePos.x -= 608;
	MousePos.y -= 330;

	//SelectX,Yに代入
	if(MousePos.x >= 0)selectX = (int)(MousePos.x /40);
	else selectX = -1;
	if (MousePos.y >= 0)selectY = (int)(MousePos.y / 40);
	else selectY = -1;

	if (selectX >= 0 && selectX < WIDTH &&
			selectY >= 0 && selectY < HEIGHT && Input::IsMouseButton(0)) {
		selectColor = Field[selectY][selectX];
	}
}

//描画
void FIELD::Draw()
{
	//マウスの座標を画面上に表示
	{
		//テキストの表示
		Text* pText = new Text;
		pText->Initialize();
		std::string str = "Mouse" + std::to_string(MousePos.x) + " " + std::to_string(MousePos.y);
		pText->Draw(20, 20, str.c_str());
	}

	//画像の描画
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			int color = Field[h][w];
			Transform t;
			t.position_ = ConvDrawPos(w*size,h*size);
			if (w == selectX && h == selectY ){
				//画像サイズ×1.2
				t.scale_ = XMFLOAT3(1.2f, 1.2f, 0);
			}
			else {
				//画像サイズ×1.0
				t.scale_ = XMFLOAT3(1.0f, 1.0f, 0);
			}
			Image::SetTransform(hPict_[color], t);
			Image::Draw(hPict_[color]);
		}
	}

	//カーソルについてくるball画像を描画
	Transform t;
	t.position_ = ConvDrawPos(MousePos.x - 20, MousePos.y - 20);
	Image::SetTransform(hPict_[selectColor], t);
	Image::Draw(selectColor);

}

//開放
void FIELD::Release()
{
}






FIELD::COLOR FIELD::isField(float _x, float _y)
{
	return (this->Field[(int)_x][(int)_y]);
}

