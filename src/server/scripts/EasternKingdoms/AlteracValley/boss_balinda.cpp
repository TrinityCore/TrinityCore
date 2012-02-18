/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"

enum Spells
{
    SPELL_ARCANE_EXPLOSION                        = 46608,
    SPELL_CONE_OF_COLD                            = 38384,
    SPELL_FIREBALL                                = 46988,
    SPELL_FROSTBOLT                               = 46987
};

enum Yells
{
    YELL_AGGRO                                   = 0,
    YELL_EVADE                                   = 1,
    YELL_SALVATION                               = 2,
};

enum Creatures
{
    NPC_WATER_ELEMENTAL                           = 25040
};

enum WaterElementalSpells
{
    SPELL_WATERBOLT                               = 46983
};

class mob_water_elemental : public CreatureScript
{
public:
    mob_water_elemental() : CreatureScript("mob_water_elemental") { }

    struct mob_water_elementalAI : public ScriptedAI
    {
        mob_water_elementalAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 waterBoltTimer;
        uint64 balindaGUID;
        uint32 resetTimer;

        void Reset()
        {
            waterBoltTimer            = 3 * IN_MILLISECONDS;
            resetTimer                = 5 * IN_MILLISECONDS;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (waterBoltTimer < diff)
            {
                DoCast(me->getVictim(), SPELL_WATERBOLT);
                waterBoltTimer = 5 * IN_MILLISECONDS;
            } else waterBoltTimer -= diff;

            // check if creature is not outside of building
            if (resetTimer < diff)
            {
                if (Creature* pBalinda = Unit::GetCreature(*me, balindaGUID))
                    if (me->GetDistance2d(pBalinda->GetHomePosition().GetPositionX(), pBalinda->GetHomePosition().GetPositionY()) > 50)
                        EnterEvadeMode();
                    resetTimer = 5 * IN_MILLISECONDS;
            } else resetTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_water_elementalAI(creature);
    }
};

class boss_balinda : public CreatureScript
{
public:
    boss_balinda() : CreatureScript("boss_balinda") { }

    struct boss_balindaAI : public ScriptedAI
    {
        boss_balindaAI(Creature* creature) : ScriptedAI(creature), summons(me) {}

        uint32 arcaneExplosionTimer;
        uint32 coneOfColdTimer;
        uint32 fireBoltTimer;
        uint32 frostboltTimer;
        uint32 resetTimer;
        uint32 waterElementalTimer;

        SummonList summons;

        void Reset()
        {
            arcaneExplosionTimer      = urand(5 * IN_MILLISECONDS, 15 * IN_MILLISECONDS);
            coneOfColdTimer           = 8 * IN_MILLISECONDS;
            fireBoltTimer             = 1 * IN_MILLISECONDS;
            frostboltTimer            = 4 * IN_MILLISECONDS;
            resetTimer                = 5 * IN_MILLISECONDS;
            waterElementalTimer       = 0;

            summons.DespawnAll();
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(YELL_AGGRO);
        }

        void JustRespawned()
        {
            Reset();
        }

        void JustSummoned(Creature* summoned)
        {
            CAST_AI(mob_water_elemental::mob_water_elementalAI, summoned->AI())->balindaGUID = me->GetGUID();
            summoned->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true));
            summoned->setFaction(me->getFaction());
            summons.Summon(summoned);
        }

        void JustDied(Unit* /*Killer*/)
        {
            summons.DespawnAll();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (waterElementalTimer < diff)
            {
                if (summons.empty())
                    me->SummonCreature(NPC_WATER_ELEMENTAL, 0, 0, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 45 * IN_MILLISECONDS);
                waterElementalTimer = 50 * IN_MILLISECONDS;
            } else waterElementalTimer -= diff;

            if (arcaneExplosionTimer < diff)
            {
                DoCast(me->getVictim(), SPELL_ARCANE_EXPLOSION);
                arcaneExplosionTimer =  urand(5 * IN_MILLISECONDS, 15 * IN_MILLISECONDS);
            } else arcaneExplosionTimer -= diff;

            if (coneOfColdTimer < diff)
            {
                DoCast(me->getVictim(), SPELL_CONE_OF_COLD);
                coneOfColdTimer = urand(10 * IN_MILLISECONDS, 20 * IN_MILLISECONDS);
            } else coneOfColdTimer -= diff;

            if (fireBoltTimer < diff)
            {
                DoCast(me->getVictim(), SPELL_FIREBALL);
                fireBoltTimer = urand(5 * IN_MILLISECONDS, 9 * IN_MILLISECONDS);
            } else fireBoltTimer -= diff;

            if (frostboltTimer < diff)
            {
                DoCast(me->getVictim(), SPELL_FROSTBOLT);
                frostboltTimer = urand(4 * IN_MILLISECONDS, 12 * IN_MILLISECONDS);
            } else frostboltTimer -= diff;

            // check if creature is not outside of building
            if (resetTimer < diff)
            {
                if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 50)
                {
                    EnterEvadeMode();
                    Talk(YELL_EVADE);
                }
                resetTimer = 5 * IN_MILLISECONDS;
            } else resetTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_balindaAI(creature);
    }
};

void AddSC_boss_balinda()
{
    new boss_balinda;
    new mob_water_elemental;
};
