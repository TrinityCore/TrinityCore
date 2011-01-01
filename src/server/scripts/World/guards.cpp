/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
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

class guard_generic : public CreatureScript
{
public:
    guard_generic() : CreatureScript("guard_generic") { }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new guardAI(creature);
    }
};

/*******************************************************
 * guard_orgrimmar
 *******************************************************/

class guard_orgrimmar : public CreatureScript
{
public:
    guard_orgrimmar() : CreatureScript("guard_orgrimmar") { }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new guardAI_orgrimmar(creature);
    }
};

/*******************************************************
 * guard_shattrath_aldor
 *******************************************************/

#define SPELL_BANISHED_SHATTRATH_A  36642
#define SPELL_BANISHED_SHATTRATH_S  36671
#define SPELL_BANISH_TELEPORT       36643
#define SPELL_EXILE                 39533

class guard_shattrath_aldor : public CreatureScript
{
public:
    guard_shattrath_aldor() : CreatureScript("guard_shattrath_aldor") { }

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

    CreatureAI *GetAI(Creature *creature) const
    {
        return new guard_shattrath_aldorAI(creature);
    }
};

/*******************************************************
 * guard_shattrath_scryer
 *******************************************************/

class guard_shattrath_scryer : public CreatureScript
{
public:
    guard_shattrath_scryer() : CreatureScript("guard_shattrath_scryer") { }

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

    CreatureAI *GetAI(Creature *creature) const
    {
        return new guard_shattrath_scryerAI(creature);
    }
};

/*******************************************************
 * guard_stormwind
 *******************************************************/

class guard_stormwind : public CreatureScript
{
public:
    guard_stormwind() : CreatureScript("guard_stormwind") { }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new guardAI_stormwind(creature);
    }
};

/*******************************************************
 * AddSC
 *******************************************************/

void AddSC_guards()
{
    new guard_generic;
    new guard_orgrimmar;
    new guard_shattrath_aldor;
    new guard_shattrath_scryer;
    new guard_stormwind;
}
