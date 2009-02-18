/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TRINITYCORE_DYNAMICOBJECT_H
#define TRINITYCORE_DYNAMICOBJECT_H

#include "Object.h"

class Unit;
struct SpellEntry;

class DynamicObject : public WorldObject
{
    public:
        typedef std::set<Unit*> AffectedSet;
        explicit DynamicObject();

        void AddToWorld();
        void RemoveFromWorld();

        bool Create(uint32 guidlow, Unit *caster, uint32 spellId, uint32 effIndex, float x, float y, float z, int32 duration, float radius);
        void Update(uint32 p_time);
        void Delete();
        uint32 GetSpellId() const { return m_spellId; }
        uint32 GetEffIndex() const { return m_effIndex; }
        uint32 GetDuration() const { return m_aliveDuration; }
        uint64 GetCasterGUID() const { return m_casterGuid; }
        Unit* GetCaster() const;
        float GetRadius() const { return m_radius; }
        bool IsAffecting(Unit *unit) const { return m_affected.find(unit) != m_affected.end(); }
        void AddAffected(Unit *unit) { m_affected.insert(unit); }
        void RemoveAffected(Unit *unit) { m_affected.erase(unit); }
        void Delay(int32 delaytime);
        bool isVisibleForInState(Player const* u, bool inVisibleList) const;

        void Say(const char* text, uint32 language, uint64 TargetGuid) { MonsterSay(text,language,TargetGuid); }
        void Yell(const char* text, uint32 language, uint64 TargetGuid) { MonsterYell(text,language,TargetGuid); }
        void TextEmote(const char* text, uint64 TargetGuid) { MonsterTextEmote(text,TargetGuid); }
        void Whisper(const char* text, uint64 receiver) { MonsterWhisper(text,receiver); }
        void Say(int32 textId, uint32 language, uint64 TargetGuid) { MonsterSay(textId,language,TargetGuid); }
        void Yell(int32 textId, uint32 language, uint64 TargetGuid) { MonsterYell(textId,language,TargetGuid); }
        void TextEmote(int32 textId, uint64 TargetGuid) { MonsterTextEmote(textId,TargetGuid); }
        void Whisper(int32 textId,uint64 receiver) { MonsterWhisper(textId,receiver); }

        GridReference<DynamicObject> &GetGridRef() { return m_gridRef; }
    protected:
        uint64 m_casterGuid;
        uint32 m_spellId;
        uint32 m_effIndex;
        int32 m_aliveDuration;
        uint32 m_updateTimer;
        time_t m_nextThinkTime;
        float m_radius;
        AffectedSet m_affected;
    private:
        GridReference<DynamicObject> m_gridRef;
};
#endif

