/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Hydromancer_Thespia
SD%Complete: 80
SDComment: Needs additional adjustments (when instance script is adjusted)
SDCategory: Coilfang Resevoir, The Steamvault
EndScriptData */

/* ContentData
boss_hydromancer_thespia
npc_coilfang_waterelemental
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "steam_vault.h"

enum HydromancerThespia
{
    SAY_SUMMON                  = 0,
    SAY_AGGRO                   = 1,
    SAY_SLAY                    = 2,
    SAY_DEAD                    = 3,

    SPELL_LIGHTNING_CLOUD       = 25033,
    SPELL_LUNG_BURST            = 31481,
    SPELL_ENVELOPING_WINDS      = 31718,

    SPELL_WATER_BOLT_VOLLEY     = 34449,
    H_SPELL_WATER_BOLT_VOLLEY   = 37924
};

class boss_hydromancer_thespia : public CreatureScript
{
public:
    boss_hydromancer_thespia() : CreatureScript("boss_hydromancer_thespia") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_thespiaAI (creature);
    }

    struct boss_thespiaAI : public ScriptedAI
    {
        boss_thespiaAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 LightningCloud_Timer;
        uint32 LungBurst_Timer;
        uint32 EnvelopingWinds_Timer;

        void Reset() OVERRIDE
        {
            LightningCloud_Timer = 15000;
            LungBurst_Timer = 7000;
            EnvelopingWinds_Timer = 9000;

            if (instance)
                instance->SetData(TYPE_HYDROMANCER_THESPIA, NOT_STARTED);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEAD);

            if (instance)
                instance->SetData(TYPE_HYDROMANCER_THESPIA, DONE);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_SLAY);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);

            if (instance)
                instance->SetData(TYPE_HYDROMANCER_THESPIA, IN_PROGRESS);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            //LightningCloud_Timer
            if (LightningCloud_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_LIGHTNING_CLOUD);

                //cast twice in Heroic mode
                if (IsHeroic())
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_LIGHTNING_CLOUD);

                LightningCloud_Timer = 15000+rand()%10000;
            } else LightningCloud_Timer -=diff;

            //LungBurst_Timer
            if (LungBurst_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_LUNG_BURST);
                LungBurst_Timer = 7000+rand()%5000;
            } else LungBurst_Timer -=diff;

            //EnvelopingWinds_Timer
            if (EnvelopingWinds_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_ENVELOPING_WINDS);

                //cast twice in Heroic mode
                if (IsHeroic())
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_ENVELOPING_WINDS);
                EnvelopingWinds_Timer = 10000+rand()%5000;
            } else EnvelopingWinds_Timer -=diff;

            DoMeleeAttackIfReady();
        }
    };

};

class npc_coilfang_waterelemental : public CreatureScript
{
public:
    npc_coilfang_waterelemental() : CreatureScript("npc_coilfang_waterelemental") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_coilfang_waterelementalAI (creature);
    }

    struct npc_coilfang_waterelementalAI : public ScriptedAI
    {
        npc_coilfang_waterelementalAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 WaterBoltVolley_Timer;

        void Reset() OVERRIDE
        {
            WaterBoltVolley_Timer = 3000+rand()%3000;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE {}

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (WaterBoltVolley_Timer <= diff)
            {
                DoCast(me, SPELL_WATER_BOLT_VOLLEY);
                WaterBoltVolley_Timer = 7000+rand()%5000;
            } else WaterBoltVolley_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_hydromancer_thespia()
{
    new boss_hydromancer_thespia();
    new npc_coilfang_waterelemental();
}
