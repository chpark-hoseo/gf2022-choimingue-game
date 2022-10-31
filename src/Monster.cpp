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

        // ������ ������, ȭ�� ���� �����ߴٸ�
        if (m_objRightW >= Screen_RW)
            isRight = false;
    }
    else {
        m_x -= objSpeed;

        // ���� ������, ȭ�� ���� �����ߴٸ�
        if (m_x <= m_cScreen_LW)
            isRight = true;
    }

}