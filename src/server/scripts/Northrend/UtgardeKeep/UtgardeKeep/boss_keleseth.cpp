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
SDName: Boss_Prince_Keleseth
SD%Complete: 100
SDComment:
SDCategory: Utgarde Keep
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
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

struct npc_frost_tomb : public ScriptedAI
{
    npc_frost_tomb(Creature* creature) : ScriptedAI(creature)
    {
        _instance = creature->GetInstanceScript();
    }

    void IsSummonedBy(WorldObject* summonerWO) override
    {
        Unit* summoner = summonerWO->ToUnit();
        if (!summoner)
            return;
        DoCast(summoner, SPELL_FROST_TOMB, true);
    }

    void UpdateAI(uint32 /*diff*/) override { }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* keleseth = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_PRINCE_KELESETH)))
            keleseth->AI()->SetData(DATA_ON_THE_ROCKS, false);
    }

private:
    InstanceScript* _instance;
};

struct boss_keleseth : public BossAI
{
    boss_keleseth(Creature* creature) : BossAI(creature, DATA_PRINCE_KELESETH)
    {
        Initialize();
    }

    void Initialize()
    {
        onTheRocks = true;
    }

    void Reset() override
    {
        _Reset();
        events.ScheduleEvent(EVENT_SHADOWBOLT, 2s, 3s);
        events.ScheduleEvent(EVENT_FROST_TOMB, 14s, 19s);
        events.ScheduleEvent(EVENT_SUMMON_SKELETONS, 6s);

        Initialize();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_START_COMBAT);

        if (!who)
            return;

        std::list<Creature*> guards;
        me->GetCreatureListWithEntryInGrid(guards, NPC_RUNEMAGE, 60.0f);
        me->GetCreatureListWithEntryInGrid(guards, NPC_STRATEGIST, 60.0f);
        if (!guards.empty())
        {
            for (std::list<Creature*>::iterator itr = guards.begin(); itr != guards.end(); ++itr)
            {
                if ((*itr)->IsAlive() && (*itr)->IsWithinLOSInMap(me))
                    (*itr)->AI()->AttackStart(who);
            }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void SetData(uint32 data, uint32 value) override
    {
        if (data == DATA_ON_THE_ROCKS)
            onTheRocks = value != 0;
    }

    uint32 GetData(uint32 data) const override
    {
        if (data == DATA_ON_THE_ROCKS)
            return onTheRocks;

        return 0;
    }

    void UpdateAI(uint32 diff) override
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
                    events.ScheduleEvent(EVENT_SHADOWBOLT, 2s, 3s);
                    break;
                case EVENT_FROST_TOMB:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true, true, -SPELL_FROST_TOMB))
                    {
                        Talk(SAY_FROST_TOMB);
                        Talk(SAY_FROST_TOMB_EMOTE, target);

                        DoCast(target, SPELL_FROST_TOMB_STUN, true);
                        // checked from sniffs - the player casts the spell
                        target->CastSpell(target, SPELL_FROST_TOMB_SUMMON, true);
                    }
                    events.ScheduleEvent(EVENT_FROST_TOMB, 14s, 19s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    void SummonSkeletons()
    {
        // I could not found any spell cast for this
        for (uint8 i = 0; i < 4; ++i)
            me->SummonCreature(NPC_SKELETON, SkeletonSpawnPoint[0][0], SkeletonSpawnPoint[0][1], SKELETONSPAWN_Z, 0);
    }

private:
    bool onTheRocks;
};

struct npc_vrykul_skeleton : public ScriptedAI
{
    npc_vrykul_skeleton(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        events.Reset();
        events.ScheduleEvent(EVENT_DECREPIFY, 4s, 6s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
        {
            damage = 0;

            // There are some issues with pets
            // they will still attack. I would say it is a PetAI bug
            if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE))
            {
                // from sniffs
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                me->SetStandState(UNIT_STAND_STATE_DEAD);

                events.Reset();
                events.ScheduleEvent(EVENT_RESURRECT, 18s, 22s);

                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveIdle();
            }
        }
    }

    void UpdateAI(uint32 diff) override
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
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true, true, -SPELL_DECREPIFY))
                        DoCast(target, SPELL_DECREPIFY);
                    events.ScheduleEvent(EVENT_DECREPIFY, 1s, 5s);
                    break;
                case EVENT_RESURRECT:
                    events.ScheduleEvent(EVENT_FULL_HEAL, 1s);
                    events.ScheduleEvent(EVENT_SHADOW_FISSURE, 1s);
                    break;
                case EVENT_FULL_HEAL:
                    DoCast(me, SPELL_FULL_HEAL, true);
                    break;
                case EVENT_SHADOW_FISSURE:
                    DoCast(me, SPELL_SHADOW_FISSURE, true);
                    DoCastAOE(SPELL_BONE_ARMOR, true);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    me->GetMotionMaster()->MoveChase(me->GetVictim());
                    events.ScheduleEvent(EVENT_DECREPIFY, 4s, 6s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE))
            DoMeleeAttackIfReady();
    }

private:
    EventMap events;
};

// 48400 - Frost Tomb
class spell_frost_tomb : public AuraScript
{
    PrepareAuraScript(spell_frost_tomb);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
            if (Unit* caster = GetCaster())
                if (caster->IsAlive())
                    if (Creature* creature = caster->ToCreature())
                        creature->DespawnOrUnsummon(1s);
    }

    void Register() override
    {
         AfterEffectRemove += AuraEffectRemoveFn(spell_frost_tomb::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

class achievement_on_the_rocks : public AchievementCriteriaScript
{
    public:
        achievement_on_the_rocks() : AchievementCriteriaScript("achievement_on_the_rocks") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            return target && target->GetAI() && target->GetAI()->GetData(DATA_ON_THE_ROCKS);
        }
};

void AddSC_boss_keleseth()
{
    RegisterUtgardeKeepCreatureAI(boss_keleseth);
    RegisterUtgardeKeepCreatureAI(npc_frost_tomb);
    RegisterUtgardeKeepCreatureAI(npc_vrykul_skeleton);
    RegisterSpellScript(spell_frost_tomb);
    new achievement_on_the_rocks();
}
