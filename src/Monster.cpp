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

        // ������ ������, ȭ�� ���� �����ߴٸ�
        if (m_objRightW >= SCREEN_WIDTH)
            isRight = false;
    }
    else {
        m_x -= obj_Speed;

        // ���� ������, ȭ�� ���� �����ߴٸ�
        if (m_x <= 0)
            isRight = true;
    }

}