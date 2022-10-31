#include "Monster.h"

void Monster::update(const int Screen_RW, int objSpeed)
{
    suttleRun(Screen_RW, objSpeed);
}

void Monster::suttleRun(const int Screen_RW, int objSpeed)
{
    m_objRightW = m_width + m_x;

    if (isRight) {
        m_x += objSpeed;

        // 오른쪽 진행중, 화면 끝에 도달했다면
        if (m_objRightW >= Screen_RW)
            isRight = false;
    }
    else {
        m_x -= objSpeed;

        // 왼쪽 진행중, 화면 끝에 도닥했다면
        if (m_x <= m_cScreen_LW)
            isRight = true;
    }

}