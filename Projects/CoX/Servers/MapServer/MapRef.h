/*
 * Super Entity Game Server Project
 * http://segs.sf.net/
 * Copyright (c) 2006 - 2016 Super Entity Game Server Team (see Authors.txt)
 * This software is licensed! (See License.txt for details)
 *
 */
#pragma once
#include "CommonNetStructures.h"

#include <QtCore/QString>
#include <string>

class MapRef
{
public:
    int         m_idx;
    bool        reduced_transform;
    glm::mat4x3 m_matrix;
    TransformStruct m_transforms;
    QString m_name;
    MapRef(int idx,const glm::mat4x3 &mat,const QString &name) :
        m_idx(idx),
        m_matrix(mat),
        m_name(name)
    {
        reduced_transform=false;
    }
    MapRef(int idx,const QString &name,glm::vec3 &pos,glm::vec3 &rot) : m_idx(idx),m_name(name)
    {
        reduced_transform=true;
        m_transforms=TransformStruct(pos,rot,glm::vec3(),true,true,false);
    }
    MapRef(): m_idx(0),m_name(""){}
    void serializefrom(BitStream &src)
    {
        m_idx = src.GetPackedBits(1);
        if(m_idx<0) return;
        src.GetString(m_name);
        getTransformMatrix(src,m_matrix);
    }
    void serializeto(BitStream &tgt) const
    {
        tgt.StorePackedBits(16,m_idx); //def_id
        //tgt.StoreString(m_name);
        if(reduced_transform)
        {
            storeTransformMatrix(tgt,m_transforms);
        }
        else
        {
            storeTransformMatrix(tgt,m_matrix);
        }

    }

};
