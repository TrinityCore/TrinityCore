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
SDName: Boss_Broggok
SD%Complete: 70
SDComment: pre-event not made
SDCategory: Hellfire Citadel, Blood Furnace
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "blood_furnace.h"

enum Yells
{
    SAY_AGGRO               = 0
};

enum Spells
{
    SPELL_SLIME_SPRAY       = 30913,
    SPELL_POISON_CLOUD      = 30916,
    SPELL_POISON_BOLT       = 30917,

    SPELL_POISON            = 30914
};

class boss_broggok : public CreatureScript
{
    public:

        boss_broggok()
            : CreatureScript("boss_broggok")
        {
        }

        struct boss_broggokAI : public BossAI
        {
            boss_broggokAI(Creature* creature) : BossAI(creature, DATA_BROGGOK)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            uint32 AcidSpray_Timer;
            uint32 PoisonSpawn_Timer;
            uint32 PoisonBolt_Timer;
            bool canAttack;

            void Reset() OVERRIDE
            {
                _Reset();
                AcidSpray_Timer = 10000;
                PoisonSpawn_Timer = 5000;
                PoisonBolt_Timer = 7000;
                DoAction(ACTION_RESET_BROGGOK);
                instance->SetData(TYPE_BROGGOK_EVENT, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                Talk(SAY_AGGRO);
            }

            void JustSummoned(Creature* summoned) OVERRIDE
            {
                summoned->setFaction(16);
                summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                summoned->CastSpell(summoned, SPELL_POISON, false, 0, 0, me->GetGUID());
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;
                if (!canAttack)
                    return;
                if (AcidSpray_Timer <= diff)
                {
                    DoCastVictim(SPELL_SLIME_SPRAY);
                    AcidSpray_Timer = 4000+rand()%8000;
                }
                else
                    AcidSpray_Timer -=diff;

                if (PoisonBolt_Timer <= diff)
                {
                    DoCastVictim(SPELL_POISON_BOLT);
                    PoisonBolt_Timer = 4000+rand()%8000;
                }
                else
                    PoisonBolt_Timer -=diff;

                if (PoisonSpawn_Timer <= diff)
                {
                    DoCast(me, SPELL_POISON_CLOUD);
                    PoisonSpawn_Timer = 20000;
                }
                else
                    PoisonSpawn_Timer -=diff;

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                if (instance)
                {
                    instance->HandleGameObject(instance->GetData64(DATA_DOOR4), true);
                    instance->HandleGameObject(instance->GetData64(DATA_DOOR5), true);
                    instance->SetData(TYPE_BROGGOK_EVENT, DONE);
                }
            }

            void DoAction(int32 action) OVERRIDE
            {
                switch (action)
                {
                    case ACTION_PREPARE_BROGGOK:
                        me->SetInCombatWithZone();
                        break;
                    case ACTION_ACTIVATE_BROGGOK:
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE);
                        canAttack = true;
                        break;
                    case ACTION_RESET_BROGGOK:
                        me->SetReactState(REACT_PASSIVE);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE);
                        canAttack = false;
                        break;
                }
            }

        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_broggokAI(creature);
        }
};

class go_broggok_lever : public GameObjectScript
{
    public:
        go_broggok_lever() : GameObjectScript("go_broggok_lever") {}

        bool OnGossipHello(Player* /*player*/, GameObject* go) OVERRIDE
        {
            if (InstanceScript* instance = go->GetInstanceScript())
                if (instance->GetData(TYPE_BROGGOK_EVENT) != DONE && instance->GetData(TYPE_BROGGOK_EVENT) != IN_PROGRESS)
                {
                    instance->SetData(TYPE_BROGGOK_EVENT, IN_PROGRESS);
                    if (Creature* broggok = Creature::GetCreature(*go, instance->GetData64(DATA_BROGGOK)))
                        broggok->AI()->DoAction(ACTION_PREPARE_BROGGOK);
                }
            go->UseDoorOrButton();
            return false;
        }
};

void AddSC_boss_broggok()
{
    new boss_broggok();
    new go_broggok_lever();
}
