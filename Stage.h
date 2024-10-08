#pragma once
#include "Engine/GameObject.h"
#include <string>
using std::string;

class Stage : public GameObject {
public:
	Stage(GameObject* scene);
	~Stage();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;


	//t4 p1 g 2
private:
	enum COLOR {
		NOCOLOR = -1,
		RED = 0,
		BLUE,
		YELLOW,
		GREEN,
		PURPLE,
		HEART,
		NUM
	};
	struct BALLINFO {
		COLOR color;
		float x, y; // 玉の表示座標
#if 0
		int counter; // 移動するフレーム数
#else
		float bx, by;
		float rate;
#endif
		int doErase; // 消す対象
	};
	static const int WIDTH = 6;
	static const int HEIGHT = 5;
	BALLINFO field[HEIGHT][WIDTH];
	int hImage[COLOR::NUM];
	XMFLOAT3 mousePos;
	int selectX, selectY; // 選ばれた場所
	COLOR selectColor;

	int eraseTime;//消える演出タイマー

	// dottozahyou kara 3dzahyou ni hennkann
	XMFLOAT3 ConvDrawPos(float x, float y);

	// 状態（State）遷移
	//�@玉を捕まえるのを待つ
	// 	玉を捕まえたら�AMOVEへ
	//�A移動・入れ替え(MOVE)
	//	離したら�Bへ
	//�B消えるのがなかったら�Dへ
	//	３つ並んでるのが消える表示をする
	//	消え終わったら�Cへ
	//�C空いたところに玉が落ちる演出
	//	落ちたら、�Bへ
	//�D攻撃（プレイヤーから、敵から）演出
	//	攻撃終わったら�@へ
	enum STATE {
		S_IDLE,
		S_MOVE,
		S_ERASE,
		S_FALL,
		S_ATTACK,
	};
	STATE state;
	void UpdateIdle();
	void UpdateMove();
	void UpdateErase();
	void UpdateFall();
	void UpdateAttack();

	void CalcMouseSelect();

	/// <summary>
	/// 始点と終点の間の値を求める
	/// </summary>
	/// <param name="begin">始点</param>
	/// <param name="end">終点</param>
	/// <param name="rate">割合</param>
	/// <returns>求める値</returns>
	float GetRateValue(float begin, float end, float rate);

	/// <summary>
	/// ３つ並んだものを探して、doEraseを1にする
	/// </summary>
	/// <returns>消えるのがあったらtrue</returns>
	bool CheckErase();

	/// <summary>
	/// 落ちるための準備をする
	/// </summary>
	void PreparaFell();
};
