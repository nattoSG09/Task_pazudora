#include "FIELD.h"


namespace {
	static const int size = 40;	//�{�[���̒��a(40�h�b�g)
	static const int left = 60;	//�Ֆʂ̍��̈ʒu
	static const int top = 80;	//�Ֆʂ̏�̈ʒu
	const float wGap = 0.06;
	const float hGap = 0.115;

};

//�h�b�g���W����A3D���W�ɕϊ�����֐�
XMFLOAT3 FIELD::ConvDrawPos(float x, float y)
{
	XMFLOAT3 p;
	p.x = x / size * wGap;
	p.y = -y / size * hGap;
	p.z = 0;
	return p;
}

//�R���X�g���N�^
FIELD::FIELD(GameObject* parent)
	: GameObject(parent, "FIELD")
{
	//Field�̔z������ׂ�"RED"�ɂ���
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			Field[h][w] = (COLOR)(rand() % COLOR::NUM);
			int m = size;
			selectX = -1;
			selectY = -1;
		}
	}
}

//������
void FIELD::Initialize()
{
	//�t�@�C���̃��[�h
	std::string filename[NUM] = { "ball/ball0.png","ball/ball1.png", "ball/ball2.png", "ball/ball3.png",
		"ball/ball4.png","ball/ball5.png" };

	for (int n = 0; n < NUM; n++) {
		hPict_[n] = Image::Load(filename[n]);
	}
}

//�X�V
void FIELD::Update()
{
	//���݂̃}�E�X�J�[�\���̍��W���擾
	MousePos = Input::GetMousePosition();

	//�h�b�g���W�ɍ��킹�邽�߂̌v�Z��
	MousePos.x -= 608;
	MousePos.y -= 330;

	//SelectX,Y�ɑ��
	if(MousePos.x >= 0)selectX = (int)(MousePos.x /40);
	else selectX = -1;
	if (MousePos.y >= 0)selectY = (int)(MousePos.y / 40);
	else selectY = -1;

	if (selectX >= 0 && selectX < WIDTH &&
			selectY >= 0 && selectY < HEIGHT && Input::IsMouseButton(0)) {
		selectColor = Field[selectY][selectX];
	}
}

//�`��
void FIELD::Draw()
{
	//�}�E�X�̍��W����ʏ�ɕ\��
	{
		//�e�L�X�g�̕\��
		Text* pText = new Text;
		pText->Initialize();
		std::string str = "Mouse" + std::to_string(MousePos.x) + " " + std::to_string(MousePos.y);
		pText->Draw(20, 20, str.c_str());
	}

	//�摜�̕`��
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			int color = Field[h][w];
			Transform t;
			t.position_ = ConvDrawPos(w*size,h*size);
			if (w == selectX && h == selectY ){
				//�摜�T�C�Y�~1.2
				t.scale_ = XMFLOAT3(1.2f, 1.2f, 0);
			}
			else {
				//�摜�T�C�Y�~1.0
				t.scale_ = XMFLOAT3(1.0f, 1.0f, 0);
			}
			Image::SetTransform(hPict_[color], t);
			Image::Draw(hPict_[color]);
		}
	}

	//�J�[�\���ɂ��Ă���ball�摜��`��
	Transform t;
	t.position_ = ConvDrawPos(MousePos.x - 20, MousePos.y - 20);
	Image::SetTransform(hPict_[selectColor], t);
	Image::Draw(selectColor);

}

//�J��
void FIELD::Release()
{
}






FIELD::COLOR FIELD::isField(float _x, float _y)
{
	return (this->Field[(int)_x][(int)_y]);
}

