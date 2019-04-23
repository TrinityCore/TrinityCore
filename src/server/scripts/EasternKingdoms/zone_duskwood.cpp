/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
SDName: Duskwood
SD%Complete: 100
SDComment: Quest Support:8735
SDCategory: Duskwood
EndScriptData */

#include "MotionMaster.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum TwilightCorrupter
{
    NPC_TWILIGHT_CORRUPTER = 15625,
    YELL_TWILIGHT_CORRUPTOR_RESPAWN = 0,
    YELL_TWILIGHT_CORRUPTOR_AGGRO = 1,
    YELL_TWILIGHT_CORRUPTOR_KILL = 2,

    SPELL_SOUL_CORRUPTION = 25805,
    SPELL_CREATURE_OF_NIGHTMARE = 25806,
    SPELL_LEVEL_UP = 24312,

    EVENT_SOUL_CORRUPTION = 1,
    EVENT_CREATURE_OF_NIGHTMARE = 2,

    QUEST_NIGHTMARES_CORRUPTION = 8735
};

/*######
# boss_twilight_corrupter
######*/

struct boss_twilight_corrupter : public ScriptedAI
{
    boss_twilight_corrupter(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        KillCount = 0;
    }

    void Reset() override
    {
        _events.Reset();
        Initialize();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        Talk(YELL_TWILIGHT_CORRUPTOR_AGGRO);
        _events.ScheduleEvent(EVENT_SOUL_CORRUPTION, 15000);
        _events.ScheduleEvent(EVENT_CREATURE_OF_NIGHTMARE, 30000);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
        {
            ++KillCount;
            Talk(YELL_TWILIGHT_CORRUPTOR_KILL, victim);

            if (KillCount == 3)
            {
                DoCast(me, SPELL_LEVEL_UP, true);
                KillCount = 0;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_SOUL_CORRUPTION:
                DoCastAOE(SPELL_SOUL_CORRUPTION);
                _events.ScheduleEvent(EVENT_SOUL_CORRUPTION, urand(15000, 19000));
                break;
            case EVENT_CREATURE_OF_NIGHTMARE:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    DoCast(target, SPELL_CREATURE_OF_NIGHTMARE);
                _events.ScheduleEvent(EVENT_CREATURE_OF_NIGHTMARE, 45000);
                break;
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    uint8 KillCount;
};

/*######
# at_twilight_grove
######*/

Position const TwillightCorrupter = { -10328.16f, -489.57f, 49.95f, 0.0f };

class at_twilight_grove : public AreaTriggerScript
{
public:
    at_twilight_grove() : AreaTriggerScript("at_twilight_grove") { }

    bool OnTrigger(Player* player, const AreaTriggerEntry* /*areaTrigger*/, bool /*entered*/) override
    {
        if (player->GetQuestStatus(QUEST_NIGHTMARES_CORRUPTION) == QUEST_STATUS_INCOMPLETE)
            if (!player->FindNearestCreature(NPC_TWILIGHT_CORRUPTER, 500.0f, true))
                if (Creature* corrupter = player->SummonCreature(NPC_TWILIGHT_CORRUPTER, TwillightCorrupter, TEMPSUMMON_MANUAL_DESPAWN, 60000))
                    corrupter->AI()->Talk(YELL_TWILIGHT_CORRUPTOR_RESPAWN, player);

        return false;
    };
};

enum SpellSummonStalvanData
{
    NPC_STALVAN = 315,
    NPC_TOBIAS = 43453,
    NPC_WORGEN_TOBIAS = 43797,

    DISPLAYID_WORGEN_TOBIAS = 33508,
    QUEST_MISTMANTLES_REVENGE = 26674,
};

const Position stalvanPosition      = { -10371.72f, -1251.92f, 35.99339f };
const Position stalvanDestination   = { -10369.932617f, -1253.7677f, 35.909294f };
const float stalvanOrientation      = 5.532694f;

const uint8 tobiasPositionsCount = 4;
const Position tobiasPositions[tobiasPositionsCount] =
{
    { -10351.5f, -1256.7f, 34.8566f },
    { -10357.5f, -1256.8f, 35.3863f },
    { -10363.5f, -1257.0f, 35.9107f },
    { -10365.8f, -1255.7f, 35.9098f }
};

enum StalvanData
{
    SPELL_WORGEN_TRANSFORMATION = 81908,

    EVENT_STALVAN_STEP_1 = 1,
    EVENT_STALVAN_STEP_2 = 2,
    EVENT_STALVAN_STEP_3 = 3,
    EVENT_STALVAN_STEP_4 = 4,
    EVENT_STALVAN_STEP_5 = 5,
    EVENT_STALVAN_STEP_6 = 6,

    EVENT_TOBIAS_STEP_1 = 7,
    EVENT_TOBIAS_STEP_2 = 8,
    EVENT_TOBIAS_STEP_3 = 9,
    EVENT_TOBIAS_STEP_4 = 10,

    SAY_00 = 0,
    SAY_01 = 1,
    SAY_02 = 2,
    SAY_03 = 3,
    SAY_04 = 4,
    SAY_05 = 5,
    SAY_06 = 6,
};

struct npc_stalvan : public ScriptedAI
{
    npc_stalvan(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_STALVAN_STEP_1, 3000);
        _events.ScheduleEvent(EVENT_STALVAN_STEP_2, 8000);
        _events.ScheduleEvent(EVENT_STALVAN_STEP_3, 15000);
        _events.ScheduleEvent(EVENT_STALVAN_STEP_4, 23000);
        _events.ScheduleEvent(EVENT_STALVAN_STEP_5, 26000);
        _events.ScheduleEvent(EVENT_STALVAN_STEP_6, 32000);

        _events.ScheduleEvent(EVENT_TOBIAS_STEP_1, 5000);
        _events.ScheduleEvent(EVENT_TOBIAS_STEP_2, 9000);
        _events.ScheduleEvent(EVENT_TOBIAS_STEP_3, 16000);
        _events.ScheduleEvent(EVENT_TOBIAS_STEP_4, 27000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* tobias = GetTobias())
        {
            Talk(SAY_06, tobias);
            tobias->AI()->Talk(SAY_04);
            tobias->DespawnOrUnsummon(4000);
        }
    }

    Creature* GetTobias()
    {
        if (Creature* tobias = me->FindNearestCreature(NPC_TOBIAS, 30, true))
            return tobias;

        return me->FindNearestCreature(NPC_WORGEN_TOBIAS, 30, true);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_STALVAN_STEP_1:
                    me->SetWalk(true);
                    me->SetSpeed(MOVE_WALK, 2.5);
                    me->GetMotionMaster()->MovePoint(0, stalvanDestination, true);
                    Talk(SAY_00, GetTobias());
                    break;

                case EVENT_STALVAN_STEP_2:
                    Talk(SAY_01, GetTobias());
                    break;

                case EVENT_STALVAN_STEP_3:
                    Talk(SAY_02, GetTobias());
                    break;

                case EVENT_STALVAN_STEP_4:
                    Talk(SAY_03, GetTobias());
                    break;

                case EVENT_STALVAN_STEP_5:
                    Talk(SAY_04, GetTobias());
                    break;

                case EVENT_STALVAN_STEP_6:
                    Talk(SAY_05, GetTobias());
                    break;

                case EVENT_TOBIAS_STEP_1:
                    if (Creature* tobias = GetTobias())
                    {
                        tobias->SetFacingToObject(me, true);
                        me->SetFacingToObject(tobias, true);
                        tobias->AI()->Talk(SAY_00, me);
                    }
                    break;

                case EVENT_TOBIAS_STEP_2:
                    if (Creature* tobias = GetTobias())
                        tobias->AI()->Talk(SAY_01, me);
                    break;

                case EVENT_TOBIAS_STEP_3:
                    if (Creature* tobias = GetTobias())
                        tobias->AI()->Talk(SAY_02, me);
                    break;

                case EVENT_TOBIAS_STEP_4:
                    if (Creature* tobias = GetTobias())
                    {
                        tobias->CastSpell(tobias, SPELL_WORGEN_TRANSFORMATION, true);
                        tobias->SetReactState(REACT_AGGRESSIVE);

                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC);
                        me->AddThreat(tobias, 10.f);
                        tobias->AddThreat(me, 10.f);
                        tobias->SetInCombatWith(me);

                        if (me->Attack(tobias, true))
                            me->GetMotionMaster()->MoveChase(tobias);

                        if (tobias->Attack(me, true))
                            tobias->GetMotionMaster()->MoveChase(me);

                        me->SetReactState(REACT_AGGRESSIVE);

                        tobias->AI()->Talk(SAY_03, tobias->GetOwner());
                    }
                    break;

                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

enum SoothingIncenseCloudData
{
    EVENT_SELECT_TARGET = 1,
    NPC_FORLORN_SPIRIT = 43923,
    NPC_FORLORN_SPIRIT_KILLCREDIT = 43930,
};

struct npc_soothing_incense_cloud : public ScriptedAI
{
    npc_soothing_incense_cloud(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_SELECT_TARGET, 500);
    }

    Player* GetOwner()
    {
        return me->ToTempSummon()->GetSummoner()->ToPlayer();
    }

    void SelectTargets()
    {
        me->GetCreatureListWithEntryInGrid(_selectedTargets, NPC_FORLORN_SPIRIT, 5.f);
    }

    void KillSelectedCreaturesAndRewardPlayer()
    {
        for (auto creature : _selectedTargets)
        {
            if (!creature->IsAlive())
                continue;

            GetOwner()->RewardPlayerAndGroupAtEvent(NPC_FORLORN_SPIRIT_KILLCREDIT, GetOwner());
            creature->DisappearAndDie();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_SELECT_TARGET:
                SelectTargets();
                KillSelectedCreaturesAndRewardPlayer();
                break;
            }
        }
    }

private:
    EventMap _events;
    std::list<Creature*> _selectedTargets;
};

enum MorbentFel
{
    SPELL_SACRED_CLEANSING   = 82130,
    NPC_WEAKENED_MORBENT_FEL = 43762,
    NPC_MORBENT_FEL          = 43761
};

class spell_sacred_cleansing : public SpellScript
{
    PrepareSpellScript(spell_sacred_cleansing);

    void SelectTarget(WorldObject*& target)
    {
        target = GetCaster()->FindNearestCreature(NPC_MORBENT_FEL, 15.0f, true);
    }

    SpellCastResult CheckRequirement()
    {
        if (Creature* fel = GetCaster()->FindNearestCreature(NPC_MORBENT_FEL, 15.0f, true))
            return SPELL_CAST_OK;

        return SPELL_FAILED_INCORRECT_AREA;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* hitUnit = GetHitUnit();
        if (!hitUnit || !GetCaster()->IsPlayer())
            return;

        if (Creature* target = hitUnit->ToCreature())
        {
            if (target->GetEntry() == NPC_MORBENT_FEL)
            {
                GetCaster()->SummonCreature(NPC_WEAKENED_MORBENT_FEL, target->GetPosition());
                target->DespawnOrUnsummon();
            }
        }
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_sacred_cleansing::SelectTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_sacred_cleansing::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnCheckCast += SpellCheckCastFn(spell_sacred_cleansing::CheckRequirement);
    }
};

class spell_summon_stalvan : public SpellScript
{
    PrepareSpellScript(spell_summon_stalvan);

    bool IsEventRunning()
    {
        return GetCaster()->FindNearestCreature(NPC_STALVAN, 20, true) != nullptr;
    }

    SpellCastResult CheckRequirement()
    {
        return SPELL_CAST_OK;
    }

    void HandleSendEvent(SpellEffIndex /*effIndex*/)
    {
        if (!GetCaster()->IsPlayer())
            return;

        if (GetCaster()->ToPlayer()->GetQuestStatus(QUEST_MISTMANTLES_REVENGE) != QUEST_STATUS_INCOMPLETE)
            return;

        if (IsEventRunning())
            return;

        SummonStalvan();
        SummonTobias();
    }

    void SummonStalvan()
    {
        if (TempSummon* stalvan = GetCaster()->SummonCreature(NPC_STALVAN, stalvanPosition))
        {
            stalvan->SetFacingTo(stalvanOrientation, true);
            stalvan->SetReactState(REACT_PASSIVE);
        }
    }

    void SummonTobias()
    {
        if (TempSummon* tobias = GetCaster()->SummonCreature(NPC_TOBIAS, tobiasPositions[0]))
        {
            tobias->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER | UNIT_NPC_FLAG_GOSSIP);
            tobias->SetWalk(true);
            tobias->SetSpeed(MOVE_WALK, 3.5);
            tobias->GetMotionMaster()->MovePoint(0, tobiasPositions[3], true);
            tobias->SetReactState(REACT_PASSIVE);
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_summon_stalvan::HandleSendEvent, EFFECT_0, SPELL_EFFECT_SEND_EVENT);
        OnCheckCast += SpellCheckCastFn(spell_summon_stalvan::CheckRequirement);
    }

};

struct npc_ebenlocke : public ScriptedAI
{
    enum Data
    {
        QUEST_EMBALMERS_REVENGE    = 26727,
        NPC_STITCHES               = 43862
    };
    
    npc_ebenlocke(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* /*player*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_EMBALMERS_REVENGE)
        {
            me->GetScheduler().Schedule(2s, [this](TaskContext /*context*/)
            {
                me->SummonCreature(NPC_STITCHES, -10553.90f, -1171.27f, 27.8604f, 1.48514f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90000, true);
            });
        }
    }
};

void AddSC_duskwood()
{
    RegisterCreatureAI(boss_twilight_corrupter);
    new at_twilight_grove();
    RegisterSpellScript(spell_summon_stalvan);
    RegisterCreatureAI(npc_stalvan);
    RegisterCreatureAI(npc_soothing_incense_cloud);
    RegisterSpellScript(spell_sacred_cleansing);
    RegisterCreatureAI(npc_ebenlocke);
}
