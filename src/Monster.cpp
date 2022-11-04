#include "Monster.h"

void Monster::update()
{
    suttleRun();
}

void Monster::suttleRun()
{
    m_objRightW = m_width + m_x;

    if (isRight) {
        m_x += obj_Speed;

        // 오른쪽 진행중, 화면 끝에 도달했다면
        if (m_objRightW >= SCREEN_WIDTH)
            isRight = false;
    }
    else {
        m_x -= obj_Speed;

        // 왼쪽 진행중, 화면 끝에 도닥했다면
        if (m_x <= 0)
            isRight = true;
    }

}