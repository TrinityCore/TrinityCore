/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef SPELLMETHODS_H
#define SPELLMETHODS_H

namespace LuaSpell
{
    /* BOOLEAN */
    int IsAutoRepeat(lua_State* L, Spell* spell)
    {
        sEluna->Push(L, spell->IsAutoRepeat());
        return 1;
    }

    /* GETTERS */
    int GetCaster(lua_State* L, Spell* spell)
    {
        sEluna->Push(L, spell->GetCaster());
        return 1;
    }

    int GetCastTime(lua_State* L, Spell* spell)
    {
        sEluna->Push(L, spell->GetCastTime());
        return 1;
    }

    int GetId(lua_State* L, Spell* spell)
    {
        sEluna->Push(L, spell->m_spellInfo->Id);
        return 1;
    }

    int GetPowerCost(lua_State* L, Spell* spell)
    {
        sEluna->Push(L, spell->GetPowerCost());
        return 1;
    }

    int GetDuration(lua_State* L, Spell* spell)
    {
#ifdef MANGOS
        sEluna->Push(L, GetSpellDuration(spell->m_spellInfo));
#else
        sEluna->Push(L, spell->GetSpellInfo()->GetDuration());
#endif
        return 1;
    }

    int GetTargetDest(lua_State* L, Spell* spell)
    {
#ifdef MANGOS
        if (!(spell->m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION))
            return 0;
        float x, y, z;
        spell->m_targets.getDestination(x, y, z);
#else
        if (!spell->m_targets.HasDst())
            return 0;
        float x, y, z;
        spell->m_targets.GetDstPos()->GetPosition(x, y, z);
#endif
        sEluna->Push(L, x);
        sEluna->Push(L, y);
        sEluna->Push(L, z);
        return 3;
    }

    int GetTarget(lua_State* L, Spell* spell)
    {
#ifdef MANGOS
        if (GameObject* target = spell->m_targets.getGOTarget())
            sEluna->Push(sEluna->L, target);
        else if (Item* target = spell->m_targets.getItemTarget())
            sEluna->Push(sEluna->L, target);
        else if (Corpse* target = spell->GetCaster()->GetMap()->GetCorpse(spell->m_targets.getCorpseTargetGuid()))
            sEluna->Push(sEluna->L, target);
        else if (Unit* target = spell->m_targets.getUnitTarget())
            sEluna->Push(sEluna->L, target);
        else
            sEluna->Push(sEluna->L);
#else
        if (GameObject* target = spell->m_targets.GetGOTarget())
            sEluna->Push(L, target);
        else if (Item* target = spell->m_targets.GetItemTarget())
            sEluna->Push(L, target);
        else if (Corpse* target = spell->m_targets.GetCorpseTarget())
            sEluna->Push(L, target);
        else if (Unit* target = spell->m_targets.GetUnitTarget())
            sEluna->Push(L, target);
        else if (WorldObject* target = spell->m_targets.GetObjectTarget())
            sEluna->Push(L, target);
        else
            sEluna->Push(L);
#endif
        return 1;
    }

    /* SETTERS */
    int SetAutoRepeat(lua_State* L, Spell* spell)
    {
        bool repeat = sEluna->CHECKVAL<bool>(L, 2);
        spell->SetAutoRepeat(repeat);
        return 0;
    }

    /* OTHER */
    int Cast(lua_State* L, Spell* spell)
    {
        bool skipCheck = sEluna->CHECKVAL<bool>(L, 2);
        spell->cast(skipCheck);
        return 0;
    }

    int cancel(lua_State* L, Spell* spell)
    {
        spell->cancel();
        return 0;
    }

    int Finish(lua_State* L, Spell* spell)
    {
        spell->finish();
        return 0;
    }
};
#endif
