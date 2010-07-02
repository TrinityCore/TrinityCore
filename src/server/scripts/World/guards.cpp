/* Copyright (C) 2006 - 2010 Trinity <http://www.trinitycore.org/>
 * Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Guards
SD%Complete: 100
SDComment: All Guard gossip data, quite some npc_text-id's still missing, adding constantly as new id's are known. CombatAI should be organized better for future.
SDCategory: Guards
EndScriptData */

/* ContentData
guard_generic
guard_orgrimmar
guard_shattrath_aldor
guard_shattrath_scryer
guard_stormwind
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedGuardAI.h"

/*******************************************************
 * guard_generic
 *******************************************************/

CreatureAI* GetAI_guard_generic(Creature* pCreature)
{
    return new guardAI (pCreature);
}

/*******************************************************
 * guard_orgrimmar
 *******************************************************/

CreatureAI* GetAI_guard_orgrimmar(Creature* pCreature)
{
    return new guardAI_orgrimmar (pCreature);
}

/*******************************************************
 * guard_shattrath_aldor
 *******************************************************/

#define SPELL_BANISHED_SHATTRATH_A  36642
#define SPELL_BANISHED_SHATTRATH_S  36671
#define SPELL_BANISH_TELEPORT       36643
#define SPELL_EXILE                 39533

struct guard_shattrath_aldorAI : public guardAI
{
    guard_shattrath_aldorAI(Creature *c) : guardAI(c) {}

    uint32 Exile_Timer;
    uint32 Banish_Timer;
    uint64 PlayerGUID;
    bool CanTeleport;

    void Reset()
    {
        Banish_Timer = 5000;
        Exile_Timer = 8500;
        PlayerGUID = 0;
        CanTeleport = false;
    }

    void EnterCombat(Unit * /*who*/) {}

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (CanTeleport)
        {
            if (Exile_Timer <= diff)
            {
                if (Unit* temp = Unit::GetUnit(*me,PlayerGUID))
                {
                    temp->CastSpell(temp,SPELL_EXILE,true);
                    temp->CastSpell(temp,SPELL_BANISH_TELEPORT,true);
                }
                PlayerGUID = 0;
                Exile_Timer = 8500;
                CanTeleport = false;
            } else Exile_Timer -= diff;
        }
        else if (Banish_Timer <= diff)
        {
            Unit* temp = me->getVictim();
            if (temp && temp->GetTypeId() == TYPEID_PLAYER)
            {
                DoCast(temp, SPELL_BANISHED_SHATTRATH_A);
                Banish_Timer = 9000;
                PlayerGUID = temp->GetGUID();
                if (PlayerGUID)
                    CanTeleport = true;
            }
        } else Banish_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_guard_shattrath_aldor(Creature* pCreature)
{
    return new guard_shattrath_aldorAI (pCreature);
}

/*******************************************************
 * guard_shattrath_scryer
 *******************************************************/

struct guard_shattrath_scryerAI : public guardAI
{
    guard_shattrath_scryerAI(Creature *c) : guardAI(c) {}

    uint32 Exile_Timer;
    uint32 Banish_Timer;
    uint64 PlayerGUID;
    bool CanTeleport;

    void Reset()
    {
        Banish_Timer = 5000;
        Exile_Timer = 8500;
        PlayerGUID = 0;
        CanTeleport = false;
    }

    void EnterCombat(Unit * /*who*/) {}

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (CanTeleport)
        {
            if (Exile_Timer <= diff)
            {
                if (Unit* temp = Unit::GetUnit(*me,PlayerGUID))
                {
                    temp->CastSpell(temp,SPELL_EXILE,true);
                    temp->CastSpell(temp,SPELL_BANISH_TELEPORT,true);
                }
                PlayerGUID = 0;
                Exile_Timer = 8500;
                CanTeleport = false;
            } else Exile_Timer -= diff;
        }
        else if (Banish_Timer <= diff)
        {
            Unit* temp = me->getVictim();
            if (temp && temp->GetTypeId() == TYPEID_PLAYER)
            {
                DoCast(temp, SPELL_BANISHED_SHATTRATH_S);
                Banish_Timer = 9000;
                PlayerGUID = temp->GetGUID();
                if (PlayerGUID)
                    CanTeleport = true;
            }
        } else Banish_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_guard_shattrath_scryer(Creature* pCreature)
{
    return new guard_shattrath_scryerAI (pCreature);
}

/*******************************************************
 * guard_stormwind
 *******************************************************/

CreatureAI* GetAI_guard_stormwind(Creature* pCreature)
{
    return new guardAI_stormwind (pCreature);
}

/*******************************************************
 * AddSC
 *******************************************************/

void AddSC_guards()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "guard_generic";
    newscript->GetAI = &GetAI_guard_generic;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "guard_orgrimmar";
    newscript->GetAI = &GetAI_guard_orgrimmar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "guard_shattrath_aldor";
    newscript->GetAI = &GetAI_guard_shattrath_aldor;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "guard_shattrath_scryer";
    newscript->GetAI = &GetAI_guard_shattrath_scryer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "guard_stormwind";
    newscript->GetAI = &GetAI_guard_stormwind;
    newscript->RegisterSelf();
}
