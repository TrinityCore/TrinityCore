/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "siege_of_the_niuzao_temple.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"
#include "SpellInfo.h"
#include "ScriptedCreature.h"
#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "Spell.h"
#include "Vehicle.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CreatureTextMgr.h"
#include "MoveSplineInit.h"
#include "Weather.h"
#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "Spell.h"
#include "Vehicle.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CreatureTextMgr.h"
#include "Weather.h"
#include <Instances/InstanceScript.h>
#include <Movement/MotionMaster.h>
#include "SpellInfo.h"
#include "Player.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Vehicle.h"
#include "GameObject.h"
#include <Instances/InstanceScript.h>
#include "TemporarySummon.h"
#include "Position.h"
#include <Globals/ObjectAccessor.h>
#include <Maps/Map.cpp>
#include "MapInstanced.h"
#include <Instances/InstanceScript.h>
#include <DungeonFinding/LFGMgr.h>
#include "LFG.h"
#include "InstanceScript.h"
#include "EventMap.h"
#include <Instances/InstanceScript.h>

enum eSpells
{
    SPELL_SUMMON_GLOBULE         = 119990,
    SPELL_SAPPLING_SUMMON_VISUAL = 120071,
    SPELL_DETONATE               = 120001,

    SPELL_SAP_PUDDLE        = 119939,
    SPELL_VISUAL_SHIELD     = 131628,
    SPELL_SAP_RESIDUE       = 119941, // DOT
    SPELL_GROW              = 120865
};

enum eEvents
{
    EVENT_GROW              = 1
};

class boss_jinbak : public CreatureScript
{
    public:
        boss_jinbak() : CreatureScript("boss_jinbak") {}

        struct boss_jinbakAI : public BossAI
        {
            boss_jinbakAI(Creature* creature) : BossAI(creature, DATA_JINBAK)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            void Reset() override
            {
                _Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
            }

            void JustReachedHome() override
            {
                instance->SetBossState(DATA_JINBAK, FAIL);
                summons.DespawnAll();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override {}

            void JustSummoned(Creature* summoned) override
            {
                summons.Summon(summoned);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_jinbakAI(creature);
        }
};

class npc_sap_puddle : public CreatureScript
{
    public:
        npc_sap_puddle() : CreatureScript("npc_sap_puddle") {}

        struct npc_sap_puddleAI : public Scripted_NoMovementAI
        {
            npc_sap_puddleAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap _events;

            void Reset() 
            {
                me->SetReactState(REACT_PASSIVE);
                me->CastSpell(me, SPELL_SAP_PUDDLE, true);

                _events.ScheduleEvent(EVENT_GROW, 1000);
            }

            void UpdateAI(uint32 /*diff*/) 
            {
                switch(_events.ExecuteEvent())
                {
                    case EVENT_GROW:
                        me->AddAura(SPELL_GROW, me);
                        _events.ScheduleEvent(EVENT_GROW, 1000);
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_sap_puddleAI(creature);
        }
};

class npc_sap_globule : public CreatureScript
{
    enum Spells
    {
        SPELL_SAP_RESIDUE = 120070,

    };

    struct npc_sap_globuleAI : public ScriptedAI
    {
        npc_sap_globuleAI(Creature * creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            done = false;
        }

        void IsSummonedBy(Unit* summoner)
        {
            if (Creature * jinbak = me->FindNearestCreature(NPC_JINBAK, 500.0f))
                jinbak->AI()->JustSummoned(me);
        }

        void SpellHit(Unit * caster, SpellInfo const* spell) override
        {
            if (!done && spell->Id == SPELL_SAP_RESIDUE)
            {
                done = true;
                caster->ToCreature()->AI()->DoAction(1);
                DoCast(me, SPELL_SAPPLING_SUMMON_VISUAL, true);
                me->DespawnOrUnsummon(500);
            }
        }

        void UpdateAI(uint32 const diff) override
        {
        }
    private:
        bool done;
    };

public:
    npc_sap_globule() : CreatureScript("npc_sap_globule") {}

    CreatureAI * GetAI(Creature * creature) const override
    {
        return new npc_sap_globuleAI(creature);
    }
};

void AddSC_boss_jinbak()
{
    new boss_jinbak();
    new npc_sap_puddle();
    new npc_sap_globule();
}
