/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
SDName: boss_archaedas
SD%Complete: 100
SDComment: Archaedas is activated when 1 person (was 3, changed in 3.0.8) clicks on his altar.
Every 10 seconds he will awaken one of his minions along the wall.
At 66%, he will awaken the 6 Guardians.
At 33%, he will awaken the Vault Walkers
On his death the vault door opens.
EndScriptData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "uldaman.h"

enum Says
{
    SAY_AGGRO                   = 0,
    SAY_SUMMON_GUARDIANS        = 1,
    SAY_SUMMON_VAULT_WALKERS    = 2,
    SAY_KILL                    = 3
};

enum Spells
{
    SPELL_GROUND_TREMOR                = 6524,
    SPELL_ARCHAEDAS_AWAKEN             = 10347,
    SPELL_BOSS_OBJECT_VISUAL           = 11206,
    SPELL_BOSS_AGGRO                   = 10340,
    SPELL_SUB_BOSS_AGGRO               = 11568,
    SPELL_AWAKEN_VAULT_WALKER          = 10258,
    SPELL_AWAKEN_EARTHEN_GUARDIAN      = 10252,
    SPELL_SELF_DESTRUCT                = 9874,
    SPELL_FREEZE_ANIM                  = 16245,
    SPELL_MINION_FREEZE_ANIM           = 10255

};

class boss_archaedas : public CreatureScript
{
    public:

        boss_archaedas()
            : CreatureScript("boss_archaedas")
        {
        }

        struct boss_archaedasAI : public ScriptedAI
        {
            boss_archaedasAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                instance = me->GetInstanceScript();
            }

            void Initialize()
            {
                uiTremorTimer = 60000;
                iAwakenTimer = 0;
                uiWallMinionTimer = 10000;

                bWakingUp = false;
                bGuardiansAwake = false;
                bVaultWalkersAwake = false;
            }

            uint32 uiTremorTimer;
            int32  iAwakenTimer;
            uint32 uiWallMinionTimer;
            bool bWakingUp;

            bool bGuardiansAwake;
            bool bVaultWalkersAwake;
            InstanceScript* instance;

            void Reset() override
            {
                Initialize();

                instance->SetData(0, 5);    // respawn any dead minions
                me->SetFaction(FACTION_FRIENDLY);
                me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                me->SetControlled(true, UNIT_STATE_ROOT);
                me->AddAura(SPELL_FREEZE_ANIM, me);
            }

            void ActivateMinion(ObjectGuid uiGuid, bool flag)
            {
                Unit* minion = ObjectAccessor::GetUnit(*me, uiGuid);

                if (minion && minion->IsAlive())
                {
                    DoCast(minion, SPELL_AWAKEN_VAULT_WALKER, flag);
                    minion->CastSpell(minion, SPELL_ARCHAEDAS_AWAKEN, true);
                    minion->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    minion->SetControlled(false, UNIT_STATE_ROOT);
                    minion->SetFaction(FACTION_MONSTER);
                    minion->RemoveAura(SPELL_MINION_FREEZE_ANIM);
                }
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                me->SetFaction(FACTION_MONSTER);
                me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                me->SetControlled(false, UNIT_STATE_ROOT);
            }

            void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
            {
                // Being woken up from the altar, start the awaken sequence
                if (spellInfo->Id == SPELL_ARCHAEDAS_AWAKEN)
                {
                    Talk(SAY_AGGRO);
                    iAwakenTimer = 4000;
                    bWakingUp = true;
                }
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_KILL);
            }

            void UpdateAI(uint32 uiDiff) override
            {
                // we're still doing awaken animation
                if (bWakingUp && iAwakenTimer >= 0)
                {
                    iAwakenTimer -= uiDiff;
                    return;        // dont do anything until we are done
                } else if (bWakingUp && iAwakenTimer <= 0)
                {
                    bWakingUp = false;
                    AttackStart(ObjectAccessor::GetUnit(*me, instance->GetGuidData(0)));
                    return;     // dont want to continue until we finish the AttackStart method
                }

                //Return since we have no target
                if (!UpdateVictim())
                    return;

                // wake a wall minion
                if (uiWallMinionTimer <= uiDiff)
                {
                    instance->SetData(DATA_MINIONS, IN_PROGRESS);

                    uiWallMinionTimer = 10000;
                } else uiWallMinionTimer -= uiDiff;

                //If we are <66 summon the guardians
                if (!bGuardiansAwake && !HealthAbovePct(66))
                {
                    ActivateMinion(instance->GetGuidData(5), true);   // EarthenGuardian1
                    ActivateMinion(instance->GetGuidData(6), true);   // EarthenGuardian2
                    ActivateMinion(instance->GetGuidData(7), true);   // EarthenGuardian3
                    ActivateMinion(instance->GetGuidData(8), true);   // EarthenGuardian4
                    ActivateMinion(instance->GetGuidData(9), true);   // EarthenGuardian5
                    ActivateMinion(instance->GetGuidData(10), false); // EarthenGuardian6
                    Talk(SAY_SUMMON_GUARDIANS);
                    bGuardiansAwake = true;
                }

                //If we are <33 summon the vault walkers
                if (!bVaultWalkersAwake && !HealthAbovePct(33))
                {
                    ActivateMinion(instance->GetGuidData(1), true);    // VaultWalker1
                    ActivateMinion(instance->GetGuidData(2), true);    // VaultWalker2
                    ActivateMinion(instance->GetGuidData(3), true);    // VaultWalker3
                    ActivateMinion(instance->GetGuidData(4), false);    // VaultWalker4
                    Talk(SAY_SUMMON_VAULT_WALKERS);
                    bVaultWalkersAwake = true;
                }

                if (uiTremorTimer <= uiDiff)
                {
                    //Cast
                    DoCastVictim(SPELL_GROUND_TREMOR);

                    //45 seconds until we should cast this agian
                    uiTremorTimer  = 45000;
                } else uiTremorTimer  -= uiDiff;

                DoMeleeAttackIfReady();
            }

            void JustDied (Unit* /*killer*/) override
            {
                instance->SetData(DATA_ANCIENT_DOOR, DONE);      // open the vault door
                instance->SetData(DATA_MINIONS, SPECIAL);        // deactivate his minions
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUldamanAI<boss_archaedasAI>(creature);
        }
};

/* ScriptData
SDName: npc_archaedas_minions
SD%Complete: 100
SDComment: These mobs are initially frozen until Archaedas awakens them
one at a time.
EndScriptData */

class npc_archaedas_minions : public CreatureScript
{
    public:

        npc_archaedas_minions()
            : CreatureScript("npc_archaedas_minions")
        {
        }

        struct npc_archaedas_minionsAI : public ScriptedAI
        {
            npc_archaedas_minionsAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                instance = me->GetInstanceScript();
            }

            void Initialize()
            {
                uiArcing_Timer = 3000;
                iAwakenTimer = 0;

                bWakingUp = false;
                bAmIAwake = false;
            }

            uint32 uiArcing_Timer;
            int32 iAwakenTimer;
            bool bWakingUp;

            bool bAmIAwake;
            InstanceScript* instance;

            void Reset() override
            {
                Initialize();

                me->SetFaction(FACTION_FRIENDLY);
                me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                me->SetControlled(true, UNIT_STATE_ROOT);
                me->RemoveAllAuras();
                me->AddAura(SPELL_MINION_FREEZE_ANIM, me);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                me->SetFaction(FACTION_MONSTER);
                me->RemoveAllAuras();
                me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                me->SetControlled(false, UNIT_STATE_ROOT);
                bAmIAwake = true;
            }

            void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
            {
                // time to wake up, start animation
                if (spellInfo->Id == SPELL_ARCHAEDAS_AWAKEN)
                {
                    iAwakenTimer = 5000;
                    bWakingUp = true;
                }
            }

            void MoveInLineOfSight(Unit* who) override

            {
                if (bAmIAwake)
                    ScriptedAI::MoveInLineOfSight(who);
            }

            void UpdateAI(uint32 uiDiff) override
            {
                // we're still in the awaken animation
                if (bWakingUp && iAwakenTimer >= 0)
                {
                    iAwakenTimer -= uiDiff;
                    return;        // dont do anything until we are done
                } else if (bWakingUp && iAwakenTimer <= 0)
                {
                    bWakingUp = false;
                    bAmIAwake = true;
                    AttackStart(ObjectAccessor::GetUnit(*me, instance->GetGuidData(0))); // whoWokeArchaedasGUID
                    return;     // dont want to continue until we finish the AttackStart method
                }

                //Return since we have no target
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUldamanAI<npc_archaedas_minionsAI>(creature);
        }
};

/* ScriptData
SDName: npc_stonekeepers
SD%Complete: 100
SDComment: After activating the altar of the keepers, the stone keepers will
wake up one by one.
EndScriptData */

class npc_stonekeepers : public CreatureScript
{
    public:

        npc_stonekeepers()
            : CreatureScript("npc_stonekeepers")
        {
        }

        struct npc_stonekeepersAI : public ScriptedAI
        {
            npc_stonekeepersAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;

            void Reset() override
            {
                me->SetFaction(FACTION_FRIENDLY);
                me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                me->SetControlled(true, UNIT_STATE_ROOT);
                me->RemoveAllAuras();
                me->AddAura(SPELL_MINION_FREEZE_ANIM, me);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                me->SetFaction(FACTION_MONSTER);
                me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                me->SetControlled(false, UNIT_STATE_ROOT);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/) override
            {
                DoCast (me, SPELL_SELF_DESTRUCT, true);
                instance->SetData(DATA_STONE_KEEPERS, IN_PROGRESS);    // activate next stonekeeper
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUldamanAI<npc_stonekeepersAI>(creature);
        }
};

/* ScriptData
SDName: go_altar_archaedas
SD%Complete: 100
SDComment: Needs 1 person to activate the Archaedas script
SDCategory: Uldaman
EndScriptData */

class go_altar_of_archaedas : public GameObjectScript
{
    public:
        go_altar_of_archaedas() : GameObjectScript("go_altar_of_archaedas") { }

        struct go_altar_of_archaedasAI : public GameObjectAI
        {
            go_altar_of_archaedasAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

            InstanceScript* instance;

            bool OnGossipHello(Player* player) override
            {
                player->CastSpell(player, SPELL_BOSS_OBJECT_VISUAL, false);

                instance->SetGuidData(0, player->GetGUID());     // activate archaedas
                return false;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetUldamanAI<go_altar_of_archaedasAI>(go);
        }
};

//This is the actual function called only once durring InitScripts()
//It must define all handled functions that are to be run in this script
void AddSC_boss_archaedas()
{
    new boss_archaedas();
    new npc_archaedas_minions();
    new npc_stonekeepers();
    new go_altar_of_archaedas();
}
