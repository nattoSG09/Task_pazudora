#pragma once

//�ۊǂ��Ȃ���ړ�����N���X
//�l��float�̒l

class Move
{
private:
	float begin;		//�J�n���̒l
	float end;			//�I�����̒l
	float moveTime;		//�ړ�������
	float currentTime;	//���̌o�ߎ���
	float currentValue;	//���̒l
public:
	Move();
	~Move();

	void Update();	//�ۊǂ���v�Z�����镔��

	/// <summary>
	/// �ړ����J�n������
	/// </summary>
	/// <param name="from">�X�^�[�g�̒l</param>
	/// <param name="target">�I���̒l</param>
	/// <param name="sec">�ω������鎞��</param>
	void Start(float from, float target, float sec);

	/// <summary>
	/// ���̒l����ړ�������
	/// </summary>
	/// <param name="target">�I���̒l</param>
	/// <param name="sec">�ω������鎞��</param>
	void MoveTo(float target, float sec);

	/// <summary>
	/// ���̒l��Ԃ�
	/// </summary>
	/// <returns>���̒l</returns>
	float GetCurrent() { return currentValue; }

	/// <summary>
	/// �⊮�ړ����I����������ׂ�
	/// </summary>
	/// <returns>�I�������true</returns>
	bool IsFinishd() { return currentTime >= moveTime; }

};

