/*
 * Super Entity Game Server Project
 * https://github.com/Segs/Segs
 * Copyright (c) 2006 - 2018 Super Entity Game Server Team (see Authors.txt)
 * This software is licensed! (See License.txt for details)
 *
 */

#include "WindowState.h"

void WindowState::serializeto(BitStream &bs) const
{
    bs.StorePackedBits(1,14); // opcode
}

void WindowState::serializefrom(BitStream &bs)
{
    wnd.m_idx = (WindowIDX)bs.GetPackedBits(1);

    wnd.m_posx = bs.GetPackedBits(1);
    wnd.m_posy = bs.GetPackedBits(1);
    wnd.m_mode = (WindowVisibility)bs.GetPackedBits(1);
    wnd.m_locked = bs.GetPackedBits(1);
    wnd.m_color = bs.GetPackedBits(1);
    wnd.m_alpha = bs.GetPackedBits(1);

    if((wnd.m_draggable_frame = bs.GetBits(1))) {
        wnd.m_width = bs.GetPackedBits(1);
        wnd.m_height = bs.GetPackedBits(1);
    }
}
