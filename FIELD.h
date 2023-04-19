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

	//�Q�����̌Œ蒷�z��Ƃ���Field��p��
	static const int WIDTH = 6;
	static const int HEIGHT = 5;
	COLOR Field[HEIGHT][WIDTH];
	int selectX, selectY;	//���񂽂����ꂽ�ꏊ
	COLOR selectColor;


	//�h�b�g���W����A3D���W�ɕϊ�����֐�
	XMFLOAT3 ConvDrawPos(float x, float y);

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	FIELD(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	COLOR isField(float _x, float _y);
};