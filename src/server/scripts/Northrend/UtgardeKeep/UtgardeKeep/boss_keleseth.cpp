/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Prince_Keleseth
SD%Complete: 100
SDComment:
SDCategory: Utgarde Keep
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "utgarde_keep.h"

enum KelsethEncounter
{
    SPELL_SHADOWBOLT                         = 43667,
    SPELL_FROST_TOMB                         = 48400,
    SPELL_FROST_TOMB_STUN                    = 42672,
    SPELL_FROST_TOMB_SUMMON                  = 42714,

    SPELL_SHADOW_FISSURE                     = 50657,
    SPELL_FULL_HEAL                          = 17683,
    SPELL_DECREPIFY                          = 42702,
    SPELL_BONE_ARMOR                         = 59386,

    NPC_FROSTTOMB                            = 23965,
    NPC_SKELETON                             = 23970,

    NPC_RUNEMAGE                             = 23960,
    NPC_STRATEGIST                           = 23956,

    SAY_START_COMBAT = 1,
    SAY_SUMMON_SKELETONS,
    SAY_FROST_TOMB,
    SAY_FROST_TOMB_EMOTE,
    SAY_DEATH,

    EVENT_SHADOWBOLT = 1,
    EVENT_FROST_TOMB,
    EVENT_SUMMON_SKELETONS,

    EVENT_DECREPIFY,
    EVENT_FULL_HEAL,
    EVENT_SHADOW_FISSURE,
    EVENT_RESURRECT,

    DATA_ON_THE_ROCKS
};

#define SKELETONSPAWN_Z                          42.8668f

float const SkeletonSpawnPoint[1][2] =
{
    {156.2559f, 259.2093f},
};

float AttackLoc[3]= {197.636f, 194.046f, 40.8164f};

class npc_frost_tomb : public CreatureScript
{
public:
    npc_frost_tomb() : CreatureScript("npc_frost_tomb") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_frost_tombAI(creature);
    }

    struct npc_frost_tombAI : public ScriptedAI
    {
        npc_frost_tombAI(Creature* creature) : ScriptedAI(creature)
        {
            if (me->isSummon())
                if (Unit* summon = me->ToTempSummon()->GetSummoner())
                    DoCast(summon, SPELL_FROST_TOMB, true);

            instance = creature->GetInstanceScript();
        }

        void UpdateAI(const uint32 /*diff*/) {}

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
                if (Unit* boss = me->GetUnit(*me, instance->GetData64(DATA_PRINCEKELESETH)))
                    if (boss->ToCreature() && boss->ToCreature()->AI())
                        boss->ToCreature()->AI()->SetData(DATA_ON_THE_ROCKS, false);
        }

    private:
        InstanceScript* instance;
    };
};

class boss_keleseth : public CreatureScript
{
public:
    boss_keleseth() : CreatureScript("boss_keleseth") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_kelesethAI (creature);
    }

    struct boss_kelesethAI : public BossAI
    {
        boss_kelesethAI(Creature* creature) : BossAI(creature, DATA_PRINCEKELESETH_EVENT){}

        void Reset()
        {
            if (instance)
                instance->SetData(DATA_PRINCEKELESETH_EVENT, NOT_STARTED);

            events.Reset();
            events.ScheduleEvent(EVENT_SHADOWBOLT, urand(2,3)*IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_FROST_TOMB, urand(14,19)*IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SUMMON_SKELETONS, 6*IN_MILLISECONDS);

            summons.DespawnAll();

            onTheRocks = true;
        }

        void EnterCombat(Unit* who)
        {
            me->SetInCombatWithZone();
            if (instance)
                instance->SetData(DATA_PRINCEKELESETH_EVENT, IN_PROGRESS);
            Talk(SAY_START_COMBAT);

            if (!who)
                return;

            std::list<Creature*> runemages;
            me->GetCreatureListWithEntryInGrid(runemages, NPC_RUNEMAGE, 60.0f);
            if (!runemages.empty())
            {
                for (std::list<Creature*>::iterator itr = runemages.begin(); itr != runemages.end(); ++itr)
                {
                    if ((*itr)->isAlive() && (*itr)->IsWithinLOSInMap(me))
                        (*itr)->AI()->AttackStart(who);
                }
            }

            std::list<Creature*> strategists;
            me->GetCreatureListWithEntryInGrid(strategists, NPC_STRATEGIST, 60.0f);
            if (!strategists.empty())
            {
                for (std::list<Creature*>::iterator itr = strategists.begin(); itr != strategists.end(); ++itr)
                {
                    if ((*itr)->isAlive() && (*itr)->IsWithinLOSInMap(me))
                        (*itr)->AI()->AttackStart(who);
                }
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
                instance->SetData(DATA_PRINCEKELESETH_EVENT, DONE);
            summons.DespawnAll();
            Talk(SAY_DEATH);
        }

        void SetData(uint32 data, uint32 value)
        {
            if (data == DATA_ON_THE_ROCKS)
                onTheRocks = value;
        }

        uint32 GetData(uint32 data) const
        {
            if (data == DATA_ON_THE_ROCKS)
                return onTheRocks;

            return 0;
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SUMMON_SKELETONS:
                    Talk(SAY_SUMMON_SKELETONS);
                    SummonSkeletons();
                    break;
                case EVENT_SHADOWBOLT:
                    DoCastVictim(SPELL_SHADOWBOLT);
                    events.ScheduleEvent(EVENT_SHADOWBOLT, urand(2,3)*IN_MILLISECONDS);
                    break;
                case EVENT_FROST_TOMB:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true, -SPELL_FROST_TOMB))
                    {
                        Talk(SAY_FROST_TOMB);
                        Talk(SAY_FROST_TOMB_EMOTE, target->GetGUID());

                        DoCast(target, SPELL_FROST_TOMB_STUN, true);
                        // checked from sniffs - the player casts the spell
                        target->CastSpell(target, SPELL_FROST_TOMB_SUMMON, true);
                    }
                    events.ScheduleEvent(EVENT_FROST_TOMB, urand(14,19)*IN_MILLISECONDS);
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void SummonSkeletons()
        {
            // I could not found any spell casted for this
            for (uint8 i = 0; i < 4; ++i)
                me->SummonCreature(NPC_SKELETON, SkeletonSpawnPoint[0][0], SkeletonSpawnPoint[0][1], SKELETONSPAWN_Z, 0);
        }
    private:
        bool onTheRocks;
    };
};

class npc_vrykul_skeleton : public CreatureScript
{
public:
    npc_vrykul_skeleton() : CreatureScript("npc_vrykul_skeleton") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_vrykul_skeletonAI (creature);
    }

    struct npc_vrykul_skeletonAI : public ScriptedAI
    {
        npc_vrykul_skeletonAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset()
        {
            events.Reset();
            events.ScheduleEvent(EVENT_DECREPIFY, urand(4,6)*IN_MILLISECONDS);

        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage)
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;

                // There are some issues with pets
                // they will still attack. I would say it is a PetAI bug
                if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                {
                    // from sniffs
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetFlag(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_DEAD);

                    events.Reset();
                    events.ScheduleEvent(EVENT_RESURRECT, urand(18,22)*IN_MILLISECONDS);

                    me->GetMotionMaster()->MovementExpired(false);
                    me->GetMotionMaster()->MoveIdle();
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DECREPIFY:
                        DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_DECREPIFY), SPELL_DECREPIFY);
                        events.ScheduleEvent(EVENT_DECREPIFY, urand(1,5)*IN_MILLISECONDS);
                        break;
                    case EVENT_RESURRECT:
                        events.ScheduleEvent(EVENT_FULL_HEAL, 1*IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_SHADOW_FISSURE, 1*IN_MILLISECONDS);
                        break;
                    case EVENT_FULL_HEAL:
                        DoCast(me, SPELL_FULL_HEAL, true);
                        break;
                    case EVENT_SHADOW_FISSURE:
                        DoCast(me, SPELL_SHADOW_FISSURE, true);
                        if (TempSummon* temp = me->ToTempSummon())
                        {
                            if (Unit* summoner = temp->GetSummoner())
                            {
                                DoCast(summoner, SPELL_BONE_ARMOR);
                            }
                        }
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->RemoveFlag(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_DEAD);
                        me->GetMotionMaster()->MoveChase(me->getVictim());
                        events.ScheduleEvent(EVENT_DECREPIFY, urand(4,6)*IN_MILLISECONDS);
                        break;
                }
            }

            if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };
};

class spell_frost_tomb : public SpellScriptLoader
{
    public:
        spell_frost_tomb() : SpellScriptLoader("spell_frost_tomb") {}

        class spell_frost_tomb_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_frost_tomb_AuraScript);
            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
                    if (Unit* caster = GetCaster())
                        if (caster->ToCreature() && caster->isAlive())
                            caster->ToCreature()->DespawnOrUnsummon(1000);
            }

            void Register()
            {
                 AfterEffectRemove += AuraEffectRemoveFn(spell_frost_tomb_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_frost_tomb_AuraScript();
        }
};


class achievement_on_the_rocks : public AchievementCriteriaScript
{
    public:
        achievement_on_the_rocks() : AchievementCriteriaScript("achievement_on_the_rocks") {}

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            return target && target->IsAIEnabled && target->GetAI()->GetData(DATA_ON_THE_ROCKS);
        }
};

void AddSC_boss_keleseth()
{
    new boss_keleseth();
    new npc_frost_tomb();
    new npc_vrykul_skeleton();
    new spell_frost_tomb();
    new achievement_on_the_rocks();
}
