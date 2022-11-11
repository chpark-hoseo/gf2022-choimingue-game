#pragma once
#include "LoaderParams.h"

class GameObject {

public:
	// 스프라이트의 데이터를 가져오는 함수

	virtual void draw() = 0;									// 그림을 그려주는 함수
	virtual void update() = 0;									// 변경사항을 적용해줌, 오른쪽 이동
	virtual void clean() = 0;									// 그림 데이터를 삭제하는 함수

protected:
	GameObject(const LoaderParams* pParms){}
};