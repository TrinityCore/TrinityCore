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

#include "ScriptMgr.h"
#include "hyjal.h"
#include "hyjal_trash.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_CARRION_SWARM         = 31306,
    SPELL_SLEEP                 = 31298,
    SPELL_VAMPIRIC_AURA         = 38196,
    SPELL_VAMPIRIC_AURA_HEAL    = 31285,
    SPELL_INFERNO               = 31299,
    SPELL_IMMOLATION            = 31303,
    SPELL_INFERNO_EFFECT        = 31302
};

enum Texts
{
    SAY_ONDEATH         = 0,
    SAY_ONSLAY          = 1,
    SAY_SWARM           = 2,
    SAY_SLEEP           = 3,
    SAY_INFERNO         = 4,
    SAY_ONAGGRO         = 5,
};

class boss_anetheron : public CreatureScript
{
public:
    boss_anetheron() : CreatureScript("boss_anetheron") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHyjalAI<boss_anetheronAI>(creature);
    }

    struct boss_anetheronAI : public hyjal_trashAI
    {
        boss_anetheronAI(Creature* creature) : hyjal_trashAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
            go = false;
        }

        void Initialize()
        {
            SwarmTimer = 45000;
            SleepTimer = 60000;
            AuraTimer = 5000;
            InfernoTimer = 45000;
            damageTaken = 0;
        }

        uint32 SwarmTimer;
        uint32 SleepTimer;
        uint32 AuraTimer;
        uint32 InfernoTimer;
        bool go;

        void Reset() override
        {
            Initialize();

            if (IsEvent)
                instance->SetData(DATA_ANETHERONEVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (IsEvent)
                instance->SetData(DATA_ANETHERONEVENT, IN_PROGRESS);

            Talk(SAY_ONAGGRO);
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_ONSLAY);
        }

        void WaypointReached(uint32 waypointId) override
        {
            if (waypointId == 7)
            {
                Unit* target = ObjectAccessor::GetUnit(*me, instance->GetGuidData(DATA_JAINAPROUDMOORE));
                if (target && target->IsAlive())
                    me->AddThreat(target, 0.0f);
            }
        }

        void JustDied(Unit* killer) override
        {
            hyjal_trashAI::JustDied(killer);
            if (IsEvent)
                instance->SetData(DATA_ANETHERONEVENT, DONE);
            Talk(SAY_ONDEATH);
        }

        void UpdateAI(uint32 diff) override
        {
            if (IsEvent)
            {
                //Must update npc_escortAI
                npc_escortAI::UpdateAI(diff);
                if (!go)
                {
                    go = true;
                    AddWaypoint(0, 4896.08f,    -1576.35f,    1333.65f);
                    AddWaypoint(1, 4898.68f,    -1615.02f,    1329.48f);
                    AddWaypoint(2, 4907.12f,    -1667.08f,    1321.00f);
                    AddWaypoint(3, 4963.18f,    -1699.35f,    1340.51f);
                    AddWaypoint(4, 4989.16f,    -1716.67f,    1335.74f);
                    AddWaypoint(5, 5026.27f,    -1736.89f,    1323.02f);
                    AddWaypoint(6, 5037.77f,    -1770.56f,    1324.36f);
                    AddWaypoint(7, 5067.23f,    -1789.95f,    1321.17f);
                    Start(false, true);
                    SetDespawnAtEnd(false);
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (SwarmTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_CARRION_SWARM);

                SwarmTimer = urand(45000, 60000);
                Talk(SAY_SWARM);
            } else SwarmTimer -= diff;

            if (SleepTimer <= diff)
            {
                for (uint8 i = 0; i < 3; ++i)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        target->CastSpell(target, SPELL_SLEEP, true);
                }
                SleepTimer = 60000;
                Talk(SAY_SLEEP);
            } else SleepTimer -= diff;
            if (AuraTimer <= diff)
            {
                DoCast(me, SPELL_VAMPIRIC_AURA, true);
                AuraTimer = urand(10000, 20000);
            } else AuraTimer -= diff;
            if (InfernoTimer <= diff)
            {
                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_INFERNO);
                InfernoTimer = 45000;
                Talk(SAY_INFERNO);
            } else InfernoTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class npc_towering_infernal : public CreatureScript
{
public:
    npc_towering_infernal() : CreatureScript("npc_towering_infernal") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHyjalAI<npc_towering_infernalAI>(creature);
    }

    struct npc_towering_infernalAI : public ScriptedAI
    {
        npc_towering_infernalAI(Creature* creature) : ScriptedAI(creature)
        {
            ImmolationTimer = 5000;
            CheckTimer = 5000;
            instance = creature->GetInstanceScript();
            AnetheronGUID = instance->GetGuidData(DATA_ANETHERON);
        }

        uint32 ImmolationTimer;
        uint32 CheckTimer;
        ObjectGuid AnetheronGUID;
        InstanceScript* instance;

        void Reset() override
        {
            DoCast(me, SPELL_INFERNO_EFFECT);
            ImmolationTimer = 5000;
            CheckTimer = 5000;
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void KilledUnit(Unit* /*victim*/) override
        {
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void MoveInLineOfSight(Unit* who) override

        {
            if (me->IsWithinDist(who, 50) && !me->IsInCombat() && me->IsValidAttackTarget(who))
                AttackStart(who);
        }

        void UpdateAI(uint32 diff) override
        {
            if (CheckTimer <= diff)
            {
                if (!AnetheronGUID.IsEmpty())
                {
                    Creature* boss = ObjectAccessor::GetCreature(*me, AnetheronGUID);
                    if (!boss || boss->isDead())
                    {
                        me->DespawnOrUnsummon();
                        return;
                    }
                }
                CheckTimer = 5000;
            } else CheckTimer -= diff;

            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (ImmolationTimer <= diff)
            {
                DoCast(me, SPELL_IMMOLATION);
                ImmolationTimer = 5000;
            } else ImmolationTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class spell_anetheron_vampiric_aura : public SpellScriptLoader
{
    public:
        spell_anetheron_vampiric_aura() : SpellScriptLoader("spell_anetheron_vampiric_aura") { }

        class spell_anetheron_vampiric_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_anetheron_vampiric_aura_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_VAMPIRIC_AURA_HEAL });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                int32 bp = damageInfo->GetDamage() * 3;
                eventInfo.GetActor()->CastCustomSpell(SPELL_VAMPIRIC_AURA_HEAL, SPELLVALUE_BASE_POINT0, bp, eventInfo.GetActor(), true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_anetheron_vampiric_aura_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_anetheron_vampiric_aura_AuraScript();
        }
};

void AddSC_boss_anetheron()
{
    new boss_anetheron();
    new npc_towering_infernal();
    new spell_anetheron_vampiric_aura();
}
