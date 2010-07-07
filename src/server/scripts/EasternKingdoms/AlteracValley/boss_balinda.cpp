/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
    YELL_AGGRO                                    = -2100019,
    YELL_EVADE                                    = -2100020
};

enum Creatures
{
    NPC_WATER_ELEMENTAL                           = 25040
};

enum WaterElementalSpells
{
    SPELL_WATERBOLT                               = 46983
};

struct mob_water_elementalAI : public ScriptedAI
{
    mob_water_elementalAI(Creature *c) : ScriptedAI(c) {}

    uint32 uiWaterBoltTimer;
    uint64 uiBalindaGUID;
    uint32 uiResetTimer;

    void Reset()
    {
        uiWaterBoltTimer            = 3*IN_MILISECONDS;
        uiResetTimer                = 5*IN_MILISECONDS;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (uiWaterBoltTimer < diff)
        {
            DoCast(me->getVictim(), SPELL_WATERBOLT);
            uiWaterBoltTimer = 5*IN_MILISECONDS;
        } else uiWaterBoltTimer -= diff;

        // check if creature is not outside of building
        if (uiResetTimer < diff)
        {
            if (Creature *pBalinda = Unit::GetCreature(*me, uiBalindaGUID))
                if (me->GetDistance2d(pBalinda->GetHomePosition().GetPositionX(), pBalinda->GetHomePosition().GetPositionY()) > 50)
                    EnterEvadeMode();
                uiResetTimer = 5*IN_MILISECONDS;
        } else uiResetTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct boss_balindaAI : public ScriptedAI
{
    boss_balindaAI(Creature *c) : ScriptedAI(c), Summons(me) {}

    uint32 uiArcaneExplosionTimer;
    uint32 uiConeOfColdTimer;
    uint32 uiFireBoltTimer;
    uint32 uiFrostboltTimer;
    uint32 uiResetTimer;
    uint32 uiWaterElementalTimer;

    SummonList Summons;

    void Reset()
    {
        uiArcaneExplosionTimer      = urand(5*IN_MILISECONDS,15*IN_MILISECONDS);
        uiConeOfColdTimer           = 8*IN_MILISECONDS;
        uiFireBoltTimer             = 1*IN_MILISECONDS;
        uiFrostboltTimer            = 4*IN_MILISECONDS;
        uiResetTimer                = 5*IN_MILISECONDS;
        uiWaterElementalTimer       = 0;

        Summons.DespawnAll();
    }

    void EnterCombat(Unit * /*who*/)
    {
        DoScriptText(YELL_AGGRO, me);
    }

    void JustRespawned()
    {
        Reset();
    }

    void JustSummoned(Creature* summoned)
    {
        ((mob_water_elementalAI*)summoned->AI())->uiBalindaGUID = me->GetGUID();
        summoned->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM,0, 50, true));
        summoned->setFaction(me->getFaction());
        Summons.Summon(summoned);
    }

    void JustDied(Unit* /*Killer*/)
    {
        Summons.DespawnAll();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (uiWaterElementalTimer < diff)
        {
            if (Summons.empty())
                me->SummonCreature(NPC_WATER_ELEMENTAL, 0, 0, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 45*IN_MILISECONDS);
            uiWaterElementalTimer = 50*IN_MILISECONDS;
        } else uiWaterElementalTimer -= diff;

        if (uiArcaneExplosionTimer < diff)
        {
            DoCast(me->getVictim(), SPELL_ARCANE_EXPLOSION);
            uiArcaneExplosionTimer =  urand(5*IN_MILISECONDS,15*IN_MILISECONDS);
        } else uiArcaneExplosionTimer -= diff;

        if (uiConeOfColdTimer < diff)
        {
            DoCast(me->getVictim(), SPELL_CONE_OF_COLD);
            uiConeOfColdTimer = urand(10*IN_MILISECONDS,20*IN_MILISECONDS);
        } else uiConeOfColdTimer -= diff;

        if (uiFireBoltTimer < diff)
        {
            DoCast(me->getVictim(), SPELL_FIREBALL);
            uiFireBoltTimer = urand(5*IN_MILISECONDS,9*IN_MILISECONDS);
        } else uiFireBoltTimer -= diff;

        if (uiFrostboltTimer < diff)
        {
            DoCast(me->getVictim(), SPELL_FROSTBOLT);
            uiFrostboltTimer = urand(4*IN_MILISECONDS,12*IN_MILISECONDS);
        } else uiFrostboltTimer -= diff;


        // check if creature is not outside of building
        if (uiResetTimer < diff)
        {
            if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 50)
            {
                EnterEvadeMode();
                DoScriptText(YELL_EVADE, me);
            }
            uiResetTimer = 5*IN_MILISECONDS;
        } else uiResetTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_balinda(Creature *_Creature)
{
    return new boss_balindaAI (_Creature);
}

CreatureAI* GetAI_mob_water_elemental(Creature *_Creature)
{
    return new mob_water_elementalAI (_Creature);
}

void AddSC_boss_balinda()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_balinda";
    newscript->GetAI = &GetAI_boss_balinda;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_water_elemental";
    newscript->GetAI = &GetAI_mob_water_elemental;
    newscript->RegisterSelf();
};