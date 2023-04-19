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
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Ball(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};