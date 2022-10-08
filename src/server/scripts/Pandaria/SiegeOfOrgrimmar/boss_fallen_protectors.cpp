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

#include "siege_of_orgrimmar.hpp"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"

enum ScriptedTextRookStonetoe
{
    SAY_ROOK_AGGRO       = 0,
    SAY_ROOK_DEATH       = 1,
    SAY_ROOK_INTRO_1     = 2,
    SAY_ROOK_INTRO_2     = 3,
    SAY_ROOK_INTRO_3     = 4,
    SAY_ROOK_KILL        = 5,
    SAY_ROOK_KICK        = 6,
    SAY_ROOK_MEASURES    = 7,
    SAY_ROOK_LOTUS       = 8,
};

enum ScriptedTextHeSoftfoot
{
    SAY_HE_AGGRO       = 0,
    SAY_HE_MEASURES    = 1,
    SAY_HE_LOTUS       = 2,
};

enum ScriptedTextSunTenderHeart
{
    SAY_SUN_AGGRO       = 0,
    SAY_SUN_DEATH       = 1,
    SAY_SUN_INTRO_1     = 2,
    SAY_SUN_KILL        = 3,
    SAY_SUN_RESET       = 4,
    SAY_SUN_CALAMITY    = 5,
    SAY_SUN_MEASURES    = 6,
    SAY_SUN_LOTUS       = 7,
};

enum Spells
{
    SPELL_ZERO_POWER                    = 96301,
    SPELL_BOND_OF_THE_GOLDEN_LOTUS      = 143497,
    SPELL_BERSERK                       = 26662,

    // Rook Stonetoe
    SPELL_VENGEFUL_STRIKES              = 144396,
    SPELL_VENGEFUL_STRIKES_DMG          = 144397,

    SPELL_CORRUPTED_BREW_AOE            = 143019,
    SPELL_CORRUPTED_BREW_MISSILE_1      = 143021,
    SPELL_CORRUPTED_BREW_MISSILE_2      = 145608,
    SPELL_CORRUPTED_BREW_MISSILE_3      = 145609,
    SPELL_CORRUPTED_BREW_MISSILE_4      = 145610,
    SPELL_CORRUPTED_BREW_MISSILE_5      = 145611,
    SPELL_CORRUPTED_BREW_MISSILE_6      = 145612,
    SPELL_CORRUPTED_BREW_MISSILE_7      = 145615,
    SPELL_CORRUPTED_BREW_MISSILE_8      = 145617,
    SPELL_CORRUPTED_BREW_DMG            = 143023,
    SPELL_CORRUPTED_BREW_DUMMY          = 145605, // ?

    SPELL_CLASH_AOE                     = 143027,
    SPELL_CLASH_JUMP                    = 143028, // creature
    SPELL_CLASH_CHARGE                  = 143030, // player

    SPELL_CORRUPTION_KICK               = 143007,
    SPELL_CORRUPTION_DMG                = 143009,
    SPELL_CORRUPTION_PERIODIC           = 143010,

    SPELL_MISERY_SORROW_AND_GLOOM       = 143955,
    SPELL_MISERY_SORROW_AND_GLOOM_JUMP_1    = 143946,
    SPELL_MISERY_SORROW_AND_GLOOM_JUMP_2    = 143948,
    SPELL_MISERY_SORROW_AND_GLOOM_JUMP_3    = 143949,

    SPELL_SHARED_TORMENT                = 145655,

    SPELL_DEFILED_GROUND                = 143961,
    SPELL_DEFILED_GROUND_AREATRIGGER    = 143960,
    SPELL_DEFILED_GROUND_AURA           = 143959,

    SPELL_INFERNO_STRIKE                = 143962,
    SPELL_RESIDUAL_BURN                 = 144007,

    SPELL_CORRUPTION_SHOCK_AOE          = 143958,
    SPELL_CORRUPTION_SHOCK_DMG          = 144018,

    // He StoneFoot
    SPELL_SHADOWSTEP_DUMMY              = 143262,
    SPELL_SHADOWSTEP                    = 143048,
    SPELL_SHADOWSTEP_BACK               = 143267,
    SPELL_GARROTE                       = 143198,

    SPELL_GOUGE                         = 143330,
    SPELL_GOUGE_DMG                     = 143301,
    SPELL_GOUGE_KNOCKBACK               = 143331,

    SPELL_NOXIOUS_POISON                = 143225,
    SPELL_NOXIOUS_POISON_AREATRIGGER    = 143235,
    SPELL_NOXIOUS_POISON_MISSILE_1      = 143245,
    SPELL_NOXIOUS_POISON_MISSILE_2      = 143276,
    SPELL_NOXIOUS_POISON_AURA           = 143239, // dmg
    SPELL_NOXIOUS_POISON_DMG            = 144367,

    SPELL_INSTANT_POISON                = 143210,
    SPELL_INSTANT_POISON_DMG            = 143224,

    SPELL_MARK_OF_ANGUISH_JUMP          = 143808,
    SPELL_MARK_OF_ANGUISH_AURA_1        = 143812, // on boss, visual
    SPELL_MARK_OF_ANGUISH_AOE           = 143822, // targetting, is used to set next target for embodied anguish
    SPELL_MARK_OF_ANGUISH_AURA_2        = 143840, // on players, main aura (root, override spells)
    SPELL_MARK_OF_ANGUISH_DUMMY         = 143842, // casted by a player to send the mark to another player
    SPELL_MARK_OF_ANGUISH_DMG           = 144365, // is triggered by 143840 periodically, it damages the owner
    SPELL_SHADOW_WEAKNESS               = 144079, // ?
    SPELL_SHADOW_WEAKNESS_AOE           = 144081, // targetting to apply 144176 on players
    SPELL_SHADOW_WEAKNESS_DEBUFF        = 144176,
    SPELL_DEBILITATION                  = 147383,

    // Sun TenderHeart
    SPELL_SHA_SEAR                      = 143423,
    SPELL_SHA_SEAR_DMG                  = 143424,

    SPELL_SHADOW_WORD_BANE              = 143446, ///< Boss cast this
    SPELL_SHADOW_WORD_BANE_AOE          = 143438, ///< Jump spell
    SPELL_SHADOW_WORD_BANE_DMG          = 143434, ///< Damage aura

    SPELL_CALAMITY                      = 143491,
    SPELL_CALAMITY_DMG                  = 143493,
    SPELL_CALAMITY_DUMMY                = 143544, // ?

    SPELL_DARK_MEDITATION_AREATRIGGER   = 143546,
    SPELL_MEDITATIVE_FIELD              = 143564,
    SPELL_DARK_MEDITATION_DUMMY_1       = 143649, // ? no visual
    SPELL_DARK_MEDITATION_JUMP_1        = 143728, // ? for adds ?
    SPELL_DARK_MEDITATION_JUMP_2        = 143730, // ? for adds ?
    SPELL_DARK_MEDITATION_PERIODIC      = 143745,
    SPELL_DARK_MEDITATION_DUMMY_2       = 143843, // for boss
    SPELL_DARK_MEDITATION_DMG           = 143559,

    SPELL_MANIFEST_DESPAIR              = 143746,
    SPELL_MANIFEST_DESPERATION          = 144504,

    SPELL_SPIRIT_BOUND                  = 143724,
};

enum Adds
{
    NPC_EMBODIED_MISERY         = 71476,
    NPC_EMBODIED_SORROW         = 71481,
    NPC_EMBODIED_GLOOM          = 71477,

    NPC_EMBODIED_ANGUISH        = 71478,

    NPC_EMBODIED_DESPAIR        = 71474,
    NPC_EMBODIED_DESPERATION    = 71482,
    NPC_DESPAIR_SPAWN           = 71712,
    NPC_DESPERATION_SPAWN       = 71993,
};

enum Events
{
    EVENT_BOND_OF_GOLDEN_LOTUS_END  = 1,
    EVENT_BERSERK,

    EVENT_VENGEFUL_STRIKES,
    EVENT_CORRUPTED_BREW,
    EVENT_CLASH,

    EVENT_AGGRO,
    EVENT_DEFILED_GROUND,
    EVENT_INFERNO_STRIKE,
    EVENT_CORRUPTION_SHOCK,

    EVENT_GOUGE,
    EVENT_SHADOWSTEP,
    EVENT_SHADOWSTEP_BACK,
    EVENT_RESET_REACT_STATE,
    EVENT_POISON,

    EVENT_MARK_OF_ANGUISH,
    EVENT_MARK_OF_ANGUISH_TARGET_CHANGED,
    EVENT_CHECK_MARK_OF_ANGUISH_TARGET,

    EVENT_SHA_SEAR,
    EVENT_CALAMITY,
    EVENT_SHADOW_WORD_BANE,
    EVENT_DARK_MEDITATION,
    EVENT_DARK_MEDITATION_DMG,
    EVENT_MANIFEST,
};

enum Timers
{
    TIMER_BERSERK = 10 * MINUTE * IN_MILLISECONDS,
    TIMER_EVADE_CHECK = 5 * IN_MILLISECONDS,
};

enum Actions
{
    DATA_CASTING_LOW_HEALTH = 1,
    GUID_MARK_OF_ANGUISH,
    ACTION_OTHER_BOSS_BEGINS_MEASURES,
    ACTION_OTHER_BOSS_ENDS_MEASURES,
    DATA_ABILITY_COUNT,
    ACTION_PREPARE_SHADOWSTEP_BACK,

    /// Rook Stonetoe
    ACTION_VENGEFUL_STRIKES_FAILED,

    ACTION_SPAWNS_SYNC_HP,
};

enum Guids
{
    GUID_FIXATE_TARGET = 1
};

const Position embodiedStonetoePos[6] =
{
    { 1201.225f, 1018.279f, 452.1667f, 0.04791985f }, // Embodied Misery in air
    { 1201.64f, 1009.629f, 452.1667f, 0.04791985f },  // Embodied Sorrow in air
    { 1208.924f, 1014.313f, 452.1667f, 0.04791985f }, // Embodied Gloom in air
    { 1203.12f, 1011.185f, 418.1869f, 1.138274f },    // Embodied Misery on ground
    { 1228.698f, 1038.337f, 418.0633f, 3.502512f },   // Embodied Sorrowon ground
    { 1195.622f, 1037.929f, 418.0638f, 5.916756f }    // Embodied Gloom on ground
};

const Position embodiedDespairPos = { 1205.122f, 1007.743f, 418.0642f, 1.267296f };
const Position embodiedDesperationPos = { 1220.946f, 1055.802f, 417.523224f, 4.353518f };

struct fallen_protectorAI : public BossAI
{
    fallen_protectorAI(Creature* creature) : BossAI(creature, DATA_FALLEN_PROTECTORS)
    {
        //ApplyAllImmunities(true);

        me->setActive(true);
    }

    void Reset() override
    {
        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));
        me->SetReactState(REACT_DEFENSIVE);

        m_IsCastingLowHealth = false;
        m_SummonedNpcsForMeasures.clear();
        m_Phase = 0;
        m_IsInMeasure = false;
        m_AbilityCount = 0;
        m_evadeTimer = TIMER_EVADE_CHECK;
    }

    void EnterCombat(Unit* who) override
    {
        bool isFirstAggro = true;

        std::list<Creature*> otherBosses;
        //GetOtherBosses(otherBosses);

        for (Creature* pBoss : otherBosses)
        {
            if (pBoss && !pBoss->IsInCombat())
            {
                DoZoneInCombat(pBoss);
            }
            else
            {
                isFirstAggro = false;
            }
        }

        if (isFirstAggro)
        {
            DoFirstAggro();
        }

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_CASTING_LOW_HEALTH)
        {
            return m_IsCastingLowHealth ? 1 : 0;
        }
        else if (type == DATA_ABILITY_COUNT)
        {
            return m_AbilityCount;
        }

        return 0;
    }

    void DamageTaken(Unit* who, uint32 & damage) override
    {
        if (me->GetHealth() <= damage)
        {
            if (IsCastingLowHealth())
            {
                damage = me->GetHealth() - 1;
            }
            else
            {
                if (!IsOthersCastingLowHealth())
                {
                    DoBoundOfGoldenLotus();

                    SetCastingLowHealth(true);

                    damage = me->GetHealth() - 1;

                    me->CastStop();

                    DoCast(me, SPELL_BOND_OF_THE_GOLDEN_LOTUS);

                    events.ScheduleEvent(EVENT_BOND_OF_GOLDEN_LOTUS_END, 15000);
                }
                else
                {
                    KillOthers();
                }
            }
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        if (IsInMeasures())
        {
            RemoveMeasureNpc(summon->GetEntry());

            if (!IsAnyMeasureNpc())
                EndMeasures();
        }
    }

    void DoAction(const int32 action) override
    {
        if (action == ACTION_OTHER_BOSS_BEGINS_MEASURES)
        {
            OtherBossBeginsMeasures();
        }
        else if (action == ACTION_OTHER_BOSS_ENDS_MEASURES)
        {
            OtherBossEndsMeasures();
        }
    }

    void JustDied(Unit* who) override
    {
        _JustDied();
    }

    bool CheckPhase()
    {
        if ((m_Phase == 0 && me->GetHealthPct() < 66.0f) ||
            (m_Phase == 2 && me->GetHealthPct() < 33.0f))
        {
            ++m_Phase;

            //BeginMeasures();

            return true;
        }

        return false;
    }

    void UpdateAI(const uint32 diff) override
    {
        if (m_evadeTimer <= diff)
        {
            m_evadeTimer = TIMER_EVADE_CHECK;

            if (me->GetExactDist(&me->GetHomePosition()) >= 65.0f)
            {
                EnterEvadeMode(EVADE_REASON_BOUNDARY);

                std::list<Creature*> otherBosses;
                //GetOtherBosses(otherBosses);

                for (Creature* other : otherBosses)
                    other->AI()->EnterEvadeMode();
                return;
            }
        }
        else
            m_evadeTimer -= diff;

        _Update(diff);
    }

protected:

    virtual void _Update(uint32 diff) = 0;
    virtual void DoFirstAggro() = 0;
    virtual void DoBoundOfGoldenLotus() = 0;
    virtual void DoBeginMeasures() = 0;
    virtual void DoEndMeasures() = 0;
    virtual void OtherBossBeginsMeasures() = 0;
    virtual void OtherBossEndsMeasures() = 0;

    bool IsCastingLowHealth() const { return m_IsCastingLowHealth; }
    void SetCastingLowHealth(bool value) { m_IsCastingLowHealth = value; }

    void AddMeasureNpc(uint32 entry) { m_SummonedNpcsForMeasures.insert(entry); }
    void RemoveMeasureNpc(uint32 entry) { m_SummonedNpcsForMeasures.erase(entry); }
    bool IsAnyMeasureNpc() const { return !m_SummonedNpcsForMeasures.empty(); }

    bool IsInMeasures() const { return m_IsInMeasure; }
    void SetInMeasures(bool value) { m_IsInMeasure = value; }

    void IncreaseAbilityCount() { ++m_AbilityCount; }

    void ApplyBerserkToAll()
    {
        if (Creature* pRook = GetRookStoneToe())
            pRook->AddAura(SPELL_BERSERK, pRook);

        if (Creature* pHe = GetHeSoftFoot())
            pHe->AddAura(SPELL_BERSERK, pHe);

        if (Creature* pSun = GetSunTenderHeart())
            pSun->AddAura(SPELL_BERSERK, pSun);
    }

private:

    Creature* GetRookStoneToe()
    {
        return instance->instance->GetCreature(instance->GetObjectGuid(DATA_ROOK_STONETOE));
    }

    Creature* GetHeSoftFoot()
    {
        return instance->instance->GetCreature(instance->GetObjectGuid(DATA_HE_SOFTFOOT));
    }

    Creature* GetSunTenderHeart()
    {
        return instance->instance->GetCreature(instance->GetObjectGuid(DATA_SUN_TENDERHEART));
    }

    /*void GetOtherBosses(std::list<Creature*>& creatures)
    {
        Creature* pRook = GetRookStoneToe();
        Creature* pHe = GetHeSoftFoot();
        Creature* pSun = GetSunTenderHeart();

        if (pRook && pRook->GetEntry() != me->GetEntry())
            creatures.push_back(pRook);

        if (pHe && pHe->GetEntry() != me->GetEntry())
            creatures.push_back(pHe);

        if (pSun && pSun->GetEntry() != me->GetEntry())
            creatures.push_back(pSun);
    }*/

    bool IsOthersCastingLowHealth()
    {
        std::list<Creature*> otherBosses;
        //GetOtherBosses(otherBosses);

        for (Creature* pBoss : otherBosses)
        {
            if (pBoss)
            {
                if (pBoss->AI()->GetData(DATA_CASTING_LOW_HEALTH) == 0)
                {
                    return false;
                }
            }
        }

        return true;
    }

    void KillOthers()
    {
        std::list<Creature*> otherBosses;
        //GetOtherBosses(otherBosses);

        for (Creature* pBoss : otherBosses)
        {
            if (pBoss)
            {
                if (Unit* victim = pBoss->GetVictim())
                {
                    victim->Kill(pBoss);
                }
            }
        }
    }

    void BeginMeasures()
    {
        SetInMeasures(true);
        NotifyOtherBossesForMeasures(true);

        m_AbilityCount = 0;

        me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));
        me->AttackStop();
        me->StopMoving();
        me->InterruptNonMeleeSpells(true);
        me->SetReactState(REACT_PASSIVE);

        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        DoBeginMeasures();
    }

    void EndMeasures()
    {
        SetInMeasures(false);
        NotifyOtherBossesForMeasures(false);

        ++m_Phase;
        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));
        me->SetReactState(REACT_AGGRESSIVE);

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        DoEndMeasures();
    }

    void NotifyOtherBossesForMeasures(bool isInMeasure)
    {
        std::list<Creature*> otherBosses;
        //GetOtherBosses(otherBosses);

        for (Creature* pBoss : otherBosses)
        {
            if (pBoss)
            {
                pBoss->AI()->DoAction(isInMeasure ? ACTION_OTHER_BOSS_BEGINS_MEASURES : ACTION_OTHER_BOSS_ENDS_MEASURES);
            }
        }
    }

private:

    bool m_IsCastingLowHealth;
    std::set<uint32 /*entry*/> m_SummonedNpcsForMeasures;
    uint8 m_Phase;
    bool m_IsInMeasure;
    uint32 m_AbilityCount;
    uint32 m_evadeTimer;
};

class boss_rook_stonetoe : public CreatureScript
{
    public:
        boss_rook_stonetoe() : CreatureScript("boss_rook_stonetoe") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_rook_stonetoeAI(creature);
        }

        struct boss_rook_stonetoeAI : public fallen_protectorAI
        {
            boss_rook_stonetoeAI(Creature* creature) : fallen_protectorAI(creature) { }

            void Reset() override
            {
                fallen_protectorAI::Reset();
            }

            void EnterCombat(Unit* attacker) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_VENGEFUL_STRIKES, 8000);
                events.ScheduleEvent(EVENT_CORRUPTED_BREW, 18000);
                events.ScheduleEvent(EVENT_CLASH, 45000);
                events.ScheduleEvent(EVENT_BERSERK, TIMER_BERSERK);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->IsPlayer())
                {
                    Talk(SAY_ROOK_KILL);
                }
            }

            void DoAction(const int32 p_Action) override
            {
                if (p_Action == Actions::ACTION_VENGEFUL_STRIKES_FAILED)
                    events.RescheduleEvent(EVENT_VENGEFUL_STRIKES, urand(3000, 5000));
            }

            void JustDied(Unit* who) override
            {
                _JustDied();
                Talk(SAY_ROOK_DEATH);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (id == EVENT_JUMP)
                {
                    Talk(SAY_ROOK_KICK);

                    me->GetMotionMaster()->MovementExpired(false);
                    DoCast(me, SPELL_CORRUPTION_KICK);

                    // reenable moving to the target
                    me->ClearUnitState(UNIT_STATE_MELEE_ATTACKING);
                }
            }

            void _Update(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (CheckPhase())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            ApplyBerserkToAll();
                            break;
                        case EVENT_BOND_OF_GOLDEN_LOTUS_END:
                            SetCastingLowHealth(false);
                            break;
                        case EVENT_VENGEFUL_STRIKES:
                            if (auto l_Victim = me->GetVictim())
                            {
                                if (me->GetDistance(l_Victim) < 5.f)
                                {
                                    DoCastVictim(SPELL_VENGEFUL_STRIKES);
                                    events.ScheduleEvent(EVENT_VENGEFUL_STRIKES, 20000);
                                }
                                else
                                    events.ScheduleEvent(EVENT_VENGEFUL_STRIKES, 3000);
                            }
                            break;
                        case EVENT_CORRUPTED_BREW:
                            DoCorruptedBrew();
                            events.ScheduleEvent(EVENT_CORRUPTED_BREW, 11000);
                            break;
                        case EVENT_CLASH:
                            DoCastAOE(SPELL_CLASH_AOE);
                            events.ScheduleEvent(EVENT_CLASH, 46000);
                            break;
                        case EVENT_AGGRO:
                            me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                            events.ScheduleEvent(EVENT_VENGEFUL_STRIKES, 7500);
                            events.ScheduleEvent(EVENT_CORRUPTED_BREW, 17000);
                            events.ScheduleEvent(EVENT_CLASH, 45000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        protected:

            void DoCorruptedBrew()
            {
                IncreaseAbilityCount();

                me->CastCustomSpell(Spells::SPELL_CORRUPTED_BREW_AOE, SpellValueMod::SPELLVALUE_MAX_TARGETS, Is25ManRaid() ? 3 : 1, nullptr, true);
            }

            virtual void DoFirstAggro() override
            {
                Talk(SAY_ROOK_AGGRO);
            }

            virtual void DoBoundOfGoldenLotus() override
            {
                Talk(SAY_ROOK_LOTUS);
            }

            virtual void DoBeginMeasures() override
            {
                Talk(SAY_ROOK_MEASURES);

                events.CancelEvent(EVENT_VENGEFUL_STRIKES);
                events.CancelEvent(EVENT_CORRUPTED_BREW);
                events.CancelEvent(EVENT_CLASH);

                me->CastSpell(me, SPELL_MISERY_SORROW_AND_GLOOM, true);

                if (Creature* pMisery = me->SummonCreature(NPC_EMBODIED_MISERY, embodiedStonetoePos[0]))
                {
                    AddMeasureNpc(pMisery->GetEntry());
                    pMisery->GetMotionMaster()->MoveJump(embodiedStonetoePos[3].GetPositionX(), embodiedStonetoePos[3].GetPositionY(), embodiedStonetoePos[3].GetPositionZ() + 0.1f, 40.0f, 20.0f, embodiedStonetoePos[3].GetOrientation());
                }
                if (Creature* pSorrow = me->SummonCreature(NPC_EMBODIED_SORROW, embodiedStonetoePos[1]))
                {
                    AddMeasureNpc(pSorrow->GetEntry());
                    pSorrow->GetMotionMaster()->MoveJump(embodiedStonetoePos[4].GetPositionX(), embodiedStonetoePos[4].GetPositionY(), embodiedStonetoePos[4].GetPositionZ() + 0.1f, 40.0f, 20.0f, embodiedStonetoePos[4].GetOrientation());
                }
                if (Creature* pGloom = me->SummonCreature(NPC_EMBODIED_GLOOM, embodiedStonetoePos[2]))
                {
                    AddMeasureNpc(pGloom->GetEntry());
                    pGloom->GetMotionMaster()->MoveJump(embodiedStonetoePos[5].GetPositionX(), embodiedStonetoePos[5].GetPositionY(), embodiedStonetoePos[5].GetPositionZ() + 0.1f, 40.0f, 20.0f, embodiedStonetoePos[5].GetOrientation());
                }
            }

            virtual void DoEndMeasures() override
            {
                me->RemoveAura(SPELL_MISERY_SORROW_AND_GLOOM);

                me->SetReactState(ReactStates::REACT_PASSIVE);
                events.ScheduleEvent(Events::EVENT_AGGRO, 5000);
            }

            virtual void OtherBossBeginsMeasures() override
            {
                if (!IsHeroic())
                {
                    events.PauseEvent(EVENT_CLASH);
                }
            }

            virtual void OtherBossEndsMeasures() override
            {
                if (!IsHeroic())
                {
                    events.ContinueEvent(EVENT_CLASH);
                }
            }
        };
};

class boss_he_softfoot : public CreatureScript
{
    public:
        boss_he_softfoot() : CreatureScript("boss_he_softfoot") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_he_softfootAI(creature);
        }

        struct boss_he_softfootAI : public fallen_protectorAI
        {
            boss_he_softfootAI(Creature* creature) : fallen_protectorAI(creature) { }

            ObjectGuid m_MainTargetGUID = ObjectGuid::Empty;
            ObjectGuid m_FixateTargetGUID = ObjectGuid::Empty;

            void Reset() override
            {
                fallen_protectorAI::Reset();
                me->RemoveAllAreaTriggers();
            }

            void EnterCombat(Unit* attacker) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_GOUGE, 25000);
                events.ScheduleEvent(EVENT_SHADOWSTEP, 9000);
                events.ScheduleEvent(EVENT_POISON, urand(5000, 15000));
            }

            void AttackStart(Unit* p_Victim) override
            {
                if (m_FixateTargetGUID != ObjectGuid::Empty && p_Victim->GetGUID() != m_FixateTargetGUID)
                {
                    m_FixateTargetGUID = ObjectGuid::Empty;
                    me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                }

                ScriptedAI::AttackStart(p_Victim);
            }

            void SetGUID(ObjectGuid p_Guid, int32 p_Id) override
            {
                if (p_Id == Guids::GUID_FIXATE_TARGET)
                    m_FixateTargetGUID = p_Guid;
            }

            void JustDied(Unit* who) override
            {
                _JustDied();
            }

            void DoAction(const int32 p_Action) override
            {
                if (p_Action == Actions::ACTION_PREPARE_SHADOWSTEP_BACK)
                    events.ScheduleEvent(EVENT_SHADOWSTEP_BACK, 1000);
            }

            void _Update(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (CheckPhase())
                {
                    return;
                }

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BOND_OF_GOLDEN_LOTUS_END:
                            SetCastingLowHealth(false);
                            break;
                        case EVENT_GOUGE:
                            DoCastVictim(SPELL_GOUGE);
                            events.ScheduleEvent(EVENT_GOUGE, 30000);
                            break;
                        case EVENT_SHADOWSTEP:
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, [&](Unit const* p_Target) -> bool
                            {
                                return p_Target->IsPlayer() && p_Target != me->GetVictim() && !p_Target->HasAura(Spells::SPELL_GARROTE);
                            }), SPELL_SHADOWSTEP_DUMMY);
                            events.ScheduleEvent(EVENT_SHADOWSTEP, 30000);
                            break;
                        case EVENT_SHADOWSTEP_BACK:
                            if (auto l_Victim = me->GetVictim())
                            {
                                m_MainTargetGUID = l_Victim->GetGUID();
                                DoCast(l_Victim, Spells::SPELL_SHADOWSTEP_BACK, true);
                                me->SetReactState(ReactStates::REACT_PASSIVE);
                                me->AttackStop();

                                events.ScheduleEvent(EVENT_RESET_REACT_STATE, 3000);
                            }
                            break;
                        case EVENT_RESET_REACT_STATE:
                            me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                            if (auto l_OldVictim = ObjectAccessor::GetUnit(*me, m_MainTargetGUID))
                                AttackStart(l_OldVictim);

                            m_MainTargetGUID = ObjectGuid::Empty;
                            break;
                        case EVENT_POISON:
                            UsePoisons();
                            break;
                        case EVENT_AGGRO:
                            me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                            events.ScheduleEvent(EVENT_SHADOWSTEP, 800);
                            events.ScheduleEvent(EVENT_GOUGE, 23000);
                            events.ScheduleEvent(EVENT_POISON, urand(5000, 15000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        protected:

            virtual void DoFirstAggro() override
            {
                Talk(SAY_HE_AGGRO);
            }

            virtual void DoBoundOfGoldenLotus() override
            {
                Talk(SAY_HE_LOTUS);
            }

            virtual void DoBeginMeasures() override
            {
                Talk(SAY_HE_MEASURES);

                me->RemoveAreaTrigger(SPELL_NOXIOUS_POISON_AREATRIGGER);

                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GARROTE);

                me->RemoveAura(SPELL_NOXIOUS_POISON);
                me->RemoveAura(SPELL_INSTANT_POISON);

                events.CancelEvent(EVENT_GOUGE);
                events.CancelEvent(EVENT_SHADOWSTEP);
                events.CancelEvent(EVENT_POISON);

                me->CastSpell(me, SPELL_MARK_OF_ANGUISH_AURA_1, true);

                if (Creature* pAnguish = me->SummonCreature(NPC_EMBODIED_ANGUISH, embodiedStonetoePos[0]))
                {
                    AddMeasureNpc(pAnguish->GetEntry());
                    pAnguish->GetMotionMaster()->MoveJump(embodiedStonetoePos[3].GetPositionX(), embodiedStonetoePos[3].GetPositionY(), embodiedStonetoePos[3].GetPositionZ() + 0.1f, 40.0f, 20.0f, embodiedStonetoePos[3].GetOrientation());
                }
            }

            virtual void DoEndMeasures() override
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MARK_OF_ANGUISH_AURA_2);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SHADOW_WEAKNESS_DEBUFF);

                me->RemoveAura(SPELL_MARK_OF_ANGUISH_AURA_1);

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));
                me->SetReactState(ReactStates::REACT_PASSIVE);
                events.ScheduleEvent(Events::EVENT_AGGRO, 5000);
            }

            virtual void OtherBossBeginsMeasures() override
            {
                if (!IsHeroic())
                {
                    me->RemoveAura(SPELL_NOXIOUS_POISON);
                    me->RemoveAura(SPELL_INSTANT_POISON);
                }
            }

            virtual void OtherBossEndsMeasures() override
            {
                if (!IsHeroic())
                {
                    UsePoisons();
                }
            }

        private:

            void UsePoisons()
            {
                uint32 nextPoisonSpell = urand(0, 1) ? SPELL_INSTANT_POISON : SPELL_NOXIOUS_POISON;
                uint32 previousPoisonSpell = nextPoisonSpell == SPELL_INSTANT_POISON ? SPELL_NOXIOUS_POISON : SPELL_INSTANT_POISON;

                DoCast(me, nextPoisonSpell);
                me->RemoveAura(previousPoisonSpell);
            }
        };
};

class boss_sun_tenderheart : public CreatureScript
{
    public:
        boss_sun_tenderheart() : CreatureScript("boss_sun_tenderheart") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_sun_tenderheartAI(creature);
        }

        struct boss_sun_tenderheartAI : public fallen_protectorAI
        {
            boss_sun_tenderheartAI(Creature* creature) : fallen_protectorAI(creature)
            {
                // Enable to interrupt Sha Sear
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);
            }

            void Reset() override
            {
                fallen_protectorAI::Reset();

                DespawnCreaturesInArea(NPC_DESPAIR_SPAWN, me);
                DespawnCreaturesInArea(NPC_DESPERATION_SPAWN, me);

                me->RemoveAllAreaTriggers();
            }

            void DespawnCreaturesInArea(int entry, Unit* unit)
            {
                std::list<Creature*> creatureList = me->FindNearestCreatures(entry, 200);
                for (Creature* creature : creatureList)
                {
                    if (me->GetAreaId() == creature->GetAreaId())
                        creature->ForcedDespawn();
                }
            }

            void EnterCombat(Unit* attacker) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_SHA_SEAR, urand(500, 2000));
                events.ScheduleEvent(EVENT_SHADOW_WORD_BANE, 15000);
                events.ScheduleEvent(EVENT_CALAMITY, 31000);
            }

            void AttackStart(Unit* who) override
            {
                if (me->Attack(who, true))
                    DoStartNoMovement(who);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->IsPlayer())
                    Talk(SAY_SUN_KILL);
            }

            void JustDied(Unit* who) override
            {
                _JustDied();
                Talk(SAY_SUN_DEATH);
                DespawnCreaturesInArea(NPC_DESPAIR_SPAWN, me);
                DespawnCreaturesInArea(NPC_DESPERATION_SPAWN, me);
                me->RemoveAllAreaTriggers();
            }

            void _Update(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (CheckPhase())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BOND_OF_GOLDEN_LOTUS_END:
                            SetCastingLowHealth(false);
                            break;
                        case EVENT_SHA_SEAR:
                            DoCastAOE(SPELL_SHA_SEAR);
                            events.ScheduleEvent(EVENT_SHA_SEAR, urand(5000, 7000));
                            break;
                        case EVENT_SHADOW_WORD_BANE:
                            DoCastAOE(SPELL_SHADOW_WORD_BANE);
                            events.ScheduleEvent(EVENT_SHADOW_WORD_BANE, 25000);
                            break;
                        case EVENT_CALAMITY:
                            DoCalamity();
                            events.ScheduleEvent(EVENT_CALAMITY, 39000);
                            break;
                        case EVENT_DARK_MEDITATION:
                            DarkMeditation();
                            break;
                        case EVENT_DARK_MEDITATION_DMG:
                            DoCastAOE(SPELL_DARK_MEDITATION_DMG, true);
                            events.ScheduleEvent(EVENT_DARK_MEDITATION_DMG, 500);
                            break;
                        case EVENT_AGGRO:
                            me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                            events.ScheduleEvent(EVENT_SHA_SEAR, urand(1000, 3000));
                            events.ScheduleEvent(EVENT_SHADOW_WORD_BANE, 10000);
                            events.ScheduleEvent(EVENT_CALAMITY, urand(2000, 39000));
                            break;
                        default:
                            break;
                    }
                }
            }

        protected:

            void DoCalamity()
            {
                Talk(SAY_SUN_CALAMITY);

                 DoCastAOE(SPELL_CALAMITY);

                 IncreaseAbilityCount();
            }

            virtual void DoFirstAggro() override
            {
                Talk(SAY_SUN_AGGRO);
            }

            virtual void DoBoundOfGoldenLotus() override
            {
                Talk(SAY_SUN_LOTUS);
            }

            virtual void DoBeginMeasures() override
            {
                events.CancelEvent(EVENT_SHA_SEAR);
                events.CancelEvent(EVENT_CALAMITY);
                events.CancelEvent(EVENT_SHADOW_WORD_BANE);

                events.ScheduleEvent(EVENT_DARK_MEDITATION, 1);
            }

            virtual void DoEndMeasures() override
            {
                events.CancelEvent(EVENT_DARK_MEDITATION_DMG);

                me->RemoveAura(SPELL_DARK_MEDITATION_DUMMY_2);
                me->RemoveAura(SPELL_DARK_MEDITATION_AREATRIGGER);
                me->RemoveAreaTrigger(SPELL_DARK_MEDITATION_AREATRIGGER);

                me->SetReactState(ReactStates::REACT_PASSIVE);
                events.ScheduleEvent(Events::EVENT_AGGRO, 5000);
            }

            virtual void OtherBossBeginsMeasures() override
            {
                if (!IsHeroic())
                    events.PauseEvent(EVENT_CALAMITY);
            }

            virtual void OtherBossEndsMeasures() override
            {
                if (!IsHeroic())
                    events.ContinueEvent(EVENT_CALAMITY);
            }

            void DarkMeditation()
            {
                Talk(SAY_SUN_MEASURES);

                me->AddAura(SPELL_DARK_MEDITATION_DUMMY_2, me);
                DoCast(me, SPELL_DARK_MEDITATION_AREATRIGGER);

                if (Creature* pDespair = me->SummonCreature(NPC_EMBODIED_DESPAIR, embodiedDespairPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000))
                    AddMeasureNpc(pDespair->GetEntry());

                if (Creature* pDesperation = me->SummonCreature(NPC_EMBODIED_DESPERATION, embodiedDesperationPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000))
                    AddMeasureNpc(pDesperation->GetEntry());

                events.ScheduleEvent(EVENT_DARK_MEDITATION_DMG, 500);
            }
        };
};

/// Embodied Misery - 71476, Embodied Sorrow - 71481, Embodied Gloom - 71477
struct rook_stonetoe_embodiedAI : public ScriptedAI
{
    rook_stonetoe_embodiedAI(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        //ApplyAllImmunities(true);
        me->SetReactState(REACT_PASSIVE);

        m_Instance = p_Creature->GetInstanceScript();
    }

    InstanceScript* m_Instance = nullptr;

    void Reset() override
    {
        events.Reset();
    }

    void MovementInform(uint32 p_Type, uint32 p_Id) override
    {
        if (p_Type == MovementGeneratorType::EFFECT_MOTION_TYPE && p_Id == EventId::EVENT_JUMP)
        {
            events.ScheduleEvent(EVENT_AGGRO, 4000);

            if (IsHeroic())
                DoCastAOE(Spells::SPELL_SHARED_TORMENT, true);
        }
    }

    void EnterCombat(Unit* p_Who) override
    {
        if (m_Instance)
            m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);

        ScriptedAI::EnterCombat(p_Who);
    }

    void JustDied(Unit* /*p_Killer*/) override
    {
        events.Reset();
        me->DespawnOrUnsummon(1000);

        if (m_Instance)
            m_Instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void UpdateAI(const uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        _Update(p_Diff);
    }

protected:
    virtual void _Update(uint32 p_Diff) { }
};

/// Embodied Misery - 71476
struct npc_rook_stonetoe_embodied_misery : public rook_stonetoe_embodiedAI
{
    npc_rook_stonetoe_embodied_misery(Creature* p_Creature) : rook_stonetoe_embodiedAI(p_Creature) { }

    void _Update(uint32 p_Diff) override
    {
        if (uint32 l_EventId = events.ExecuteEvent())
        {
            switch (l_EventId)
            {
                case EVENT_AGGRO:
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                    events.ScheduleEvent(Events::EVENT_DEFILED_GROUND, 3000);
                    break;
                case EVENT_DEFILED_GROUND:
                    DoCastVictim(Spells::SPELL_DEFILED_GROUND);
                    events.ScheduleEvent(Events::EVENT_DEFILED_GROUND, 10500);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

/// Embodied Sorrow - 71481
struct npc_rook_stonetoe_embodied_sorrow : public rook_stonetoe_embodiedAI
{
    npc_rook_stonetoe_embodied_sorrow(Creature* p_Creature) : rook_stonetoe_embodiedAI(p_Creature) { }

    void _Update(uint32 p_Diff) override
    {
        if (uint32 l_EventId = events.ExecuteEvent())
        {
            switch (l_EventId)
            {
                case EVENT_AGGRO:
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                    events.ScheduleEvent(Events::EVENT_INFERNO_STRIKE, 2000);
                    break;
                case EVENT_INFERNO_STRIKE:
                    if (auto l_Target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(l_Target, Spells::SPELL_INFERNO_STRIKE);

                    events.ScheduleEvent(Events::EVENT_INFERNO_STRIKE, 10000);
                    break;
            }
        }
    }
};

/// Embodied Gloom - 71477
struct npc_rook_stonetoe_embodied_gloom : public rook_stonetoe_embodiedAI
{
    npc_rook_stonetoe_embodied_gloom(Creature* p_Creature) : rook_stonetoe_embodiedAI(p_Creature)
    {
        p_Creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);
    }

    void _Update(uint32 p_Diff) override
    {
        if (uint32 l_EventId = events.ExecuteEvent())
        {
            switch (l_EventId)
            {
                case EVENT_AGGRO:
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                    events.ScheduleEvent(Events::EVENT_CORRUPTION_SHOCK, 1000);
                    break;
                case EVENT_CORRUPTION_SHOCK:
                    me->CastCustomSpell(Spells::SPELL_CORRUPTION_SHOCK_AOE, SpellValueMod::SPELLVALUE_MAX_TARGETS, Is25ManRaid() ? 5 : 2, nullptr, true);
                    events.ScheduleEvent(Events::EVENT_CORRUPTION_SHOCK, urand(3000, 5000));
                    break;
            }
        }
    }
};

/// Embodied Anguish - 71478
struct npc_he_softfoot_embodied_anguish : public ScriptedAI
{
    npc_he_softfoot_embodied_anguish(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
       //ApplyAllImmunities(true);

        me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_STATE, AuraType::SPELL_AURA_MOD_TAUNT, true);
        me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);

        me->AddAura(Spells::SPELL_SHADOW_WEAKNESS, me);

        m_Instance = p_Creature->GetInstanceScript();
        p_Creature->SetReactState(ReactStates::REACT_PASSIVE);
    }

    InstanceScript* m_Instance = nullptr;
    ObjectGuid m_TargetGUID = ObjectGuid::Empty;
    bool m_IsCasting = false;

    void Reset() override
    {
        events.Reset();
        m_TargetGUID = ObjectGuid::Empty;
    }

    void EnterCombat(Unit* /*p_Who*/) override
    {
        events.ScheduleEvent(Events::EVENT_AGGRO, 3000);
        events.ScheduleEvent(Events::EVENT_MARK_OF_ANGUISH, 0);

        if (m_Instance)
            m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);
    }

    void SetGUID(ObjectGuid p_Guid, int32 p_Id) override
    {
        if (p_Id == Actions::GUID_MARK_OF_ANGUISH)
        {
            // if it is not first targetting
            if (m_TargetGUID != ObjectGuid::Empty)
                DoCastAOE(Spells::SPELL_SHADOW_WEAKNESS_AOE, true);

            m_TargetGUID = p_Guid;

            events.CancelEvent(Events::EVENT_CHECK_MARK_OF_ANGUISH_TARGET);
            events.ScheduleEvent(Events::EVENT_MARK_OF_ANGUISH_TARGET_CHANGED, 500);
        }
    }

    void JustDied(Unit* /*p_Killer*/) override
    {
        events.Reset();
        me->DespawnOrUnsummon(1000);

        if (m_Instance)
            m_Instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void UpdateAI(const uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        if (uint32 l_EventId = events.ExecuteEvent())
        {
            switch (l_EventId)
            {
                case Events::EVENT_AGGRO:
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                    if (Player* l_Target = ObjectAccessor::GetPlayer(*me, m_TargetGUID))
                    {
                        me->AddThreat(l_Target, 10000000.0f);
                        me->GetMotionMaster()->MoveChase(l_Target);
                    }
                    break;
                case Events::EVENT_MARK_OF_ANGUISH:
                    DoCastAOE(Spells::SPELL_MARK_OF_ANGUISH_AOE);
                    break;
                case Events::EVENT_MARK_OF_ANGUISH_TARGET_CHANGED:
                {
                    me->CastStop();
                    DoResetThreat();
                    m_IsCasting = false;

                    if (me->GetReactState() != ReactStates::REACT_PASSIVE)
                    {
                        if (Player* l_Target = ObjectAccessor::GetPlayer(*me, m_TargetGUID))
                        {
                            me->AddThreat(l_Target, 10000000.0f);
                            me->GetMotionMaster()->MoveChase(l_Target);
                        }
                    }

                    events.ScheduleEvent(Events::EVENT_CHECK_MARK_OF_ANGUISH_TARGET, 1000);
                    break;
                }
                case Events::EVENT_CHECK_MARK_OF_ANGUISH_TARGET:
                {
                    Player* l_Target = ObjectAccessor::GetPlayer(*me, m_TargetGUID);
                    if (l_Target == nullptr || !l_Target->IsAlive())
                    {
                        m_IsCasting = false;
                        m_TargetGUID = ObjectGuid::Empty;

                        me->CastStop();
                        DoResetThreat();

                        events.ScheduleEvent(Events::EVENT_MARK_OF_ANGUISH, 1000);
                        return;
                    }

                    if (!m_IsCasting)
                    {
                        DoCast(l_Target, Spells::SPELL_MARK_OF_ANGUISH_AURA_2);
                        me->ClearUnitState(UnitState::UNIT_STATE_CASTING);
                        m_IsCasting = true;
                    }

                    events.ScheduleEvent(Events::EVENT_CHECK_MARK_OF_ANGUISH_TARGET, 1000);
                    break;
                }
            }
        }

        DoMeleeAttackIfReady();
    }
};

/// Embodied Despair - 71474, Embodied Desperation - 71482
struct npc_sun_tenderheart_embodied_AI : public Scripted_NoMovementAI
{
    npc_sun_tenderheart_embodied_AI(Creature* p_Creature, uint32 p_SpellId) : Scripted_NoMovementAI(p_Creature), m_Spell(p_SpellId)
    {
        //ApplyAllImmunities(true);

        p_Creature->SetReactState(REACT_PASSIVE);
        m_Instance = p_Creature->GetInstanceScript();
    }

    uint32 m_Spell = 0;
    InstanceScript* m_Instance = nullptr;

    void Reset() override
    {
        events.Reset();
        summons.DespawnAll();
    }

    void IsSummonedBy(Unit* /*p_Owner*/) override
    {
        events.ScheduleEvent(EVENT_MANIFEST, 1000);
        DoCast(me, m_Spell, true);
        me->AddAura(Spells::SPELL_SPIRIT_BOUND, me);
    }

    void JustSummoned(Creature* p_Summon) override
    {
        summons.Summon(p_Summon);

        if (me->IsInCombat())
            DoZoneInCombat(p_Summon);
    }

    void EnterCombat(Unit* /*p_Who*/) override
    {
        if (m_Instance)
            m_Instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
    }

    void DoAction(const int32 p_Action) override
    {
        if (p_Action == Actions::ACTION_SPAWNS_SYNC_HP)
        {
            for (auto l_Guid : summons)
                if (auto l_Summon = ObjectAccessor::GetUnit(*me, l_Guid))
                    l_Summon->SetHealth(me->GetHealth());
        }
    }

    void SummonedCreatureDespawn(Creature* p_Summon) override
    {
        summons.Despawn(p_Summon);
    }

    void JustDied(Unit* /*p_Who*/) override
    {
        events.Reset();
        summons.DespawnAll();

        if (m_Instance)
            m_Instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        me->DespawnOrUnsummon(3000);
    }

    void UpdateAI(const uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MANIFEST:
                    DoCast(me, m_Spell);
                    events.ScheduleEvent(EVENT_MANIFEST, 9000);
                    break;
            }
        }
    }
};

/// Embodied Despair - 71474
struct npc_sun_tenderheart_embodied_despair : public npc_sun_tenderheart_embodied_AI
{
    npc_sun_tenderheart_embodied_despair(Creature* p_Creature) : npc_sun_tenderheart_embodied_AI(p_Creature, Spells::SPELL_MANIFEST_DESPAIR) { }
};

/// Embodied Desperation - 71482
struct npc_sun_tenderheart_embodied_desperation : public npc_sun_tenderheart_embodied_AI
{
    npc_sun_tenderheart_embodied_desperation(Creature* p_Creature) : npc_sun_tenderheart_embodied_AI(p_Creature, Spells::SPELL_MANIFEST_DESPERATION) { }
};

/// Despair Spawn - 71712, Desperation Spawn - 71993
struct npc_sun_tenderheart_spawn : public ScriptedAI
{
    npc_sun_tenderheart_spawn(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        //ApplyAllImmunities(true);
        p_Creature->SetReactState(ReactStates::REACT_PASSIVE);
    }

    enum eSpells
    {
        SpiritBound = 143723
    };

    void Reset()
    {
        events.Reset();
    }

    void IsSummonedBy(Unit* p_Owner) override
    {
        me->SetHealth(p_Owner->GetHealth());
        p_Owner->CastSpell(me, eSpells::SpiritBound, true);
        events.ScheduleEvent(Events::EVENT_AGGRO, 2000);
    }

    void JustDied(Unit* /*p_Who*/)
    {
        events.Reset();
        summons.DespawnAll();

        me->DespawnOrUnsummon(3000);
    }

    void UpdateAI(const uint32 p_Diff)
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (uint32 l_EventId = events.ExecuteEvent())
        {
            switch (l_EventId)
            {
                case Events::EVENT_AGGRO:
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

class spell_sun_tenderheart_calamity : public SpellScriptLoader
{
    public:
        spell_sun_tenderheart_calamity() : SpellScriptLoader("spell_sun_tenderheart_calamity") { }

        class spell_sun_tenderheart_calamity_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sun_tenderheart_calamity_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetHitUnit()->RemoveAura(SPELL_SHADOW_WORD_BANE_DMG);

                if (int32 dmg = GetCalamityDmg(GetCaster()))
                {
                    GetCaster()->CastCustomSpell(GetHitUnit(), SPELL_CALAMITY_DMG, &dmg, NULL, NULL, true);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_sun_tenderheart_calamity_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

        private:

            int32 GetCalamityDmg(Unit* caster)
            {
                int32 damage = 30;

                if (Creature* pCreature = caster->ToCreature())
                {
                    if (pCreature->GetMap()->IsHeroic())
                    {
                        uint32 calamityCount = pCreature->AI()->GetData(DATA_ABILITY_COUNT);

                        // first ability should be with 30 dmg
                        if (calamityCount > 0)
                            calamityCount -= 1;

                        damage += 10 * calamityCount;
                    }
                }

                return damage;
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sun_tenderheart_calamity_SpellScript();
        }
};

/// Shadow Word: Bane - 143446
class spell_sun_tenderheart_shadow_word_bane : public SpellScript
{
    PrepareSpellScript(spell_sun_tenderheart_shadow_word_bane);

    void HandleDummy(SpellEffIndex /*p_EffIndex*/)
    {
        if (auto l_Target = GetHitUnit())
            GetCaster()->CastSpell(l_Target, SPELL_SHADOW_WORD_BANE_DMG, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sun_tenderheart_shadow_word_bane::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

/// Shadow Word: Bane - 143438
class spell_sun_tenderheart_shadow_word_bane_aoe : public SpellScript
{
    PrepareSpellScript(spell_sun_tenderheart_shadow_word_bane_aoe);

    void CheckTarget(std::list<WorldObject*>& p_Targets)
    {
        Unit* l_Target = GetExplTargetUnit();
        if (l_Target == nullptr)
            return;

        p_Targets.remove(l_Target);
        p_Targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SHADOW_WORD_BANE_DMG));

        if (!p_Targets.empty())
        {
            if (auto l_Aura = l_Target->GetAura(SPELL_SHADOW_WORD_BANE_DMG))
                l_Aura->SetCharges(1);

            //GetSpell()->SetSpellValue(SpellValueMod::SPELLVALUE_BASE_POINT0, GetSpell()->GetSpellValue(SpellValueMod::SPELLVALUE_BASE_POINT0) - 1);
            GetSpell()->SetSpellValue(SpellValueMod::SPELLVALUE_BASE_POINT0, GetSpellValue()->EffectBasePoints[0] - 1);
        }
    }

    void HandleDummy(SpellEffIndex /*p_EffIndex*/)
    {
        if (auto l_Target = GetHitUnit())
            GetCaster()->CastCustomSpell(SPELL_SHADOW_WORD_BANE_DMG, SpellValueMod::SPELLVALUE_BASE_POINT0, GetSpellValue()->EffectBasePoints[0], l_Target);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sun_tenderheart_shadow_word_bane_aoe::CheckTarget, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_sun_tenderheart_shadow_word_bane_aoe::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

/// Shadow Word: Bane (Main target spell) - 143434
class spell_sun_tenderheart_shadow_word_bane_dmg : public AuraScript
{
    PrepareAuraScript(spell_sun_tenderheart_shadow_word_bane_dmg);

    void OnApply(AuraEffect const* p_AurEff, AuraEffectHandleModes /*p_Mode*/)
    {
        GetAura()->SetCharges(p_AurEff->GetAmount());
    }

    void HandlePeriodic(AuraEffect const* p_AurEff)
    {
        if (GetAura()->GetCharges() > 1)
            if (auto l_Caster = GetCaster())
                if (auto l_AuraOwner = GetUnitOwner())
                    l_Caster->CastCustomSpell(SPELL_SHADOW_WORD_BANE_AOE, SpellValueMod::SPELLVALUE_BASE_POINT0, GetAura()->GetCharges(), l_AuraOwner);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sun_tenderheart_shadow_word_bane_dmg::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sun_tenderheart_shadow_word_bane_dmg::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

/// Sha Sear - 143424
class spell_sun_sha_shear : public SpellScript
{
    PrepareSpellScript(spell_sun_sha_shear);

    void CalculateDamage(SpellEffIndex /*p_EffIndex*/)
    {
        if (Unit* l_Target = GetHitUnit())
        {
            if (AuraEffect* l_ShaShear = l_Target->GetAuraEffect(Spells::SPELL_SHA_SEAR, SpellEffIndex::EFFECT_0))
            {
                int32 l_Damage = GetHitDamage();
                AddPct(l_Damage, l_ShaShear->GetTickNumber() * 25);
                SetHitDamage(l_Damage);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sun_sha_shear::CalculateDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

/// Corrupted Brew - 143019
class spell_rook_stonetoe_corrupted_brew_aoe : public SpellScript
{
    PrepareSpellScript(spell_rook_stonetoe_corrupted_brew_aoe);

    bool Load() override
    {
        return GetCaster()->IsCreature();
    }

    void HandleDummy(SpellEffIndex /*p_EffIndex*/)
    {
        if (auto l_Target = GetHitUnit())
            GetCaster()->CastSpell(l_Target, GetCorruptedBrewSpellId(GetCaster()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rook_stonetoe_corrupted_brew_aoe::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:

    uint32 GetCorruptedBrewSpellId(Unit* p_Caster)
    {
        uint32 l_SpellId = SPELL_CORRUPTED_BREW_MISSILE_1;

        if (p_Caster->GetMap()->IsHeroic())
        {
            uint32 l_BrewCount = p_Caster->ToCreature()->AI()->GetData(DATA_ABILITY_COUNT);

            if (l_BrewCount < 3)
                l_SpellId = SPELL_CORRUPTED_BREW_MISSILE_1;
            else if (l_BrewCount < 5)
                l_SpellId = SPELL_CORRUPTED_BREW_MISSILE_2;
            else if (l_BrewCount < 7)
                l_SpellId = SPELL_CORRUPTED_BREW_MISSILE_3;
            else if (l_BrewCount < 9)
                l_SpellId = SPELL_CORRUPTED_BREW_MISSILE_4;
            else if (l_BrewCount < 11)
                l_SpellId = SPELL_CORRUPTED_BREW_MISSILE_5;
            else if (l_BrewCount < 13)
                l_SpellId = SPELL_CORRUPTED_BREW_MISSILE_6;
            else if (l_BrewCount < 15)
                l_SpellId = SPELL_CORRUPTED_BREW_MISSILE_7;
            else if (l_BrewCount < 17)
                l_SpellId = SPELL_CORRUPTED_BREW_MISSILE_8;
        }

        return l_SpellId;
    }
};

class spell_rook_stonetoe_inferno_strike : public SpellScriptLoader
{
    public:
        spell_rook_stonetoe_inferno_strike() : SpellScriptLoader("spell_rook_stonetoe_inferno_strike") { }

        class spell_rook_stonetoe_inferno_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rook_stonetoe_inferno_strike_SpellScript);

            void HandleDamage(SpellEffIndex effIndex)
            {
                //int32 multiplier = GetSpellInfo()->Effects[EFFECT_0].BasePoints;
                int32 multiplier = GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints;

                SetHitDamage(GetHitDamage() * multiplier);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_rook_stonetoe_inferno_strike_SpellScript::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_rook_stonetoe_inferno_strike_SpellScript();
        }
};

/// Gouge - 143330
class spell_he_stonefoot_gouge : public SpellScript
{
    PrepareSpellScript(spell_he_stonefoot_gouge);

    enum eSpells
    {
        Shadowstep = 143285
    };

    bool Load() override
    {
        return GetCaster()->IsCreature();
    }

    void HandleDummy(SpellEffIndex /*p_EffIndex*/)
    {
        Unit* l_HeStoneFoot = GetCaster();

        if (Unit* l_Target = GetHitUnit())
        {
            if (l_Target->isInBack(l_HeStoneFoot))
                l_HeStoneFoot->CastSpell(l_Target, Spells::SPELL_GOUGE_KNOCKBACK, true);
            else
            {
                l_HeStoneFoot->CastSpell(l_Target, SPELL_GOUGE_DMG, true);

                if (Unit* l_NewTarget = l_HeStoneFoot->ToCreature()->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, [l_Target](Unit const* p_Target) -> bool
                {
                    return p_Target->IsPlayer() && p_Target != l_Target;
                }))
                {
                    l_HeStoneFoot->getThreatManager().resetAllAggro();
                    l_HeStoneFoot->AddThreat(l_NewTarget, 10000000.0f);
                    l_HeStoneFoot->ToCreature()->AI()->AttackStart(l_NewTarget);

                    l_HeStoneFoot->CastSpell(l_NewTarget, eSpells::Shadowstep, true);
                    l_HeStoneFoot->ClearUnitState(UNIT_STATE_CASTING);

                    l_HeStoneFoot->ToCreature()->AI()->SetGUID(l_NewTarget->GetGUID(), Guids::GUID_FIXATE_TARGET);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_he_stonefoot_gouge::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_rook_stonetoe_clash_aoe : public SpellScriptLoader
{
    public:
        spell_rook_stonetoe_clash_aoe() : SpellScriptLoader("spell_rook_stonetoe_clash_aoe") { }

        class spell_rook_stonetoe_clash_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rook_stonetoe_clash_aoe_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                float distance = GetCaster()->GetDistance(GetHitUnit());
                Position centerPos;
                GetCaster()->GetNearPoint(GetCaster(), centerPos.m_positionX, centerPos.m_positionY, centerPos.m_positionZ, 0.0f, distance / 2.0f, GetCaster()->GetAngle(GetHitUnit()));
                centerPos.m_positionZ += 0.1f;

                GetCaster()->CastSpell(centerPos.GetPositionX(), centerPos.GetPositionY(), centerPos.GetPositionZ(), SPELL_CLASH_JUMP, true);
                GetHitUnit()->CastSpell(centerPos.GetPositionX(), centerPos.GetPositionY(), centerPos.GetPositionZ(), SPELL_CLASH_CHARGE, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_rook_stonetoe_clash_aoe_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_rook_stonetoe_clash_aoe_SpellScript();
        }
};

/// Corruption Shock - 143958
class spell_rook_stonetoe_corruption_shock_aoe : public SpellScript
{
    PrepareSpellScript(spell_rook_stonetoe_corruption_shock_aoe);

    void HandleDummy(SpellEffIndex p_EffIndex)
    {
        if (auto l_Target = GetHitUnit())
            GetCaster()->CastSpell(l_Target, GetSpellValue()->EffectBasePoints[0], true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rook_stonetoe_corruption_shock_aoe::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_he_softfoot_mark_of_anguish_aoe : public SpellScriptLoader
{
    public:
        spell_he_softfoot_mark_of_anguish_aoe() : SpellScriptLoader("spell_he_softfoot_mark_of_anguish_aoe") { }

        class spell_he_softfoot_mark_of_anguish_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_he_softfoot_mark_of_anguish_aoe_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (SpellInfo const* l_SpellInfo = sSpellMgr->GetSpellInfo(Spells::SPELL_DEBILITATION))
                    GetCaster()->AddAura(l_SpellInfo, MAX_EFFECT_MASK, GetHitUnit());

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    pCreature->AI()->SetGUID(GetHitUnit()->GetGUID(), GUID_MARK_OF_ANGUISH);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_he_softfoot_mark_of_anguish_aoe_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_he_softfoot_mark_of_anguish_aoe_SpellScript();
        }
};

/// Mark of Anguish - 143842
class spell_he_softfoot_mark_of_anguish_dummy : public SpellScript
{
    PrepareSpellScript(spell_he_softfoot_mark_of_anguish_dummy);

    void HandleDummy()
    {
        if (auto l_Target = GetHitUnit())
        {
            if (auto l_Aura = GetCaster()->GetAura(Spells::SPELL_MARK_OF_ANGUISH_AURA_2))
            {
                if (SpellInfo const* l_SpellInfo = sSpellMgr->GetSpellInfo(Spells::SPELL_DEBILITATION))
                    GetCaster()->AddAura(l_SpellInfo, MAX_EFFECT_MASK, l_Target);

                if (auto l_AuraCaster = l_Aura->GetCaster()) ///< Anguish
                    if (l_AuraCaster->IsCreature() && l_AuraCaster->ToCreature()->AI())
                        l_AuraCaster->ToCreature()->AI()->SetGUID(l_Target->GetGUID(), GUID_MARK_OF_ANGUISH);

                l_Aura->Remove();
            }
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_he_softfoot_mark_of_anguish_dummy::HandleDummy);
    }
};

class spell_he_softfoot_shadow_weakness_aoe : public SpellScriptLoader
{
    public:
        spell_he_softfoot_shadow_weakness_aoe() : SpellScriptLoader("spell_he_softfoot_shadow_weakness_aoe") { }

        class spell_he_softfoot_shadow_weakness_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_he_softfoot_shadow_weakness_aoe_SpellScript);

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->AddAura(SPELL_SHADOW_WEAKNESS_DEBUFF, GetHitUnit());
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_he_softfoot_shadow_weakness_aoe_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_he_softfoot_shadow_weakness_aoe_SpellScript();
        }
};

/// Mark of Anguish - 143840
class spell_he_softfoot_mark_of_anguish_aura_2 : public AuraScript
{
    PrepareAuraScript(spell_he_softfoot_mark_of_anguish_aura_2);

    void HandlePeriodic(AuraEffect const* /*p_AurEff*/)
    {
        if (auto l_Onwer = GetUnitOwner())
            l_Onwer->CastSpell(l_Onwer, Spells::SPELL_MARK_OF_ANGUISH_DMG, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_he_softfoot_mark_of_anguish_aura_2::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_he_softfoot_instant_poison : public SpellScriptLoader
{
    public:
        spell_he_softfoot_instant_poison() : SpellScriptLoader("spell_he_softfoot_instant_poison") { }

        class spell_he_softfoot_instant_poison_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_he_softfoot_instant_poison_AuraScript);

            void OnProc(AuraEffect const* /*p_AurEff*/, ProcEventInfo & p_EventInfo)
            {
                PreventDefaultAction();

                if (!GetCaster())
                    return;
                // todo: readd commented part
                if (Creature* pHe = GetCaster()->ToCreature())
                /*{
                    if (pHe->HasSpellCooldown(SPELL_INSTANT_POISON_DMG))
                        return;

                    */if (Unit* target = pHe->GetVictim())/*
                    {*/
                        pHe->CastSpell(target, SPELL_INSTANT_POISON_DMG, true);
                /*        pHe->_AddCreatureSpellCooldown(SPELL_INSTANT_POISON_DMG, time(NULL) + 3);
                    }
                }*/
            }

            void Register()
            {
                OnEffectProc += AuraEffectProcFn(spell_he_softfoot_instant_poison_AuraScript::OnProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_he_softfoot_instant_poison_AuraScript();
        }
};

class spell_he_softfoot_noxious_poison : public SpellScriptLoader
{
    public:
        spell_he_softfoot_noxious_poison() : SpellScriptLoader("spell_he_softfoot_noxious_poison") { }

        class spell_he_softfoot_noxious_poison_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_he_softfoot_noxious_poison_AuraScript);

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* actor = eventInfo.GetActor();

                Unit* target = eventInfo.GetActionTarget();

                if (!actor || !target)
                    return;

                actor->CastSpell(target, SPELL_NOXIOUS_POISON_MISSILE_1, true);
            }

            void Register()
            {
                OnEffectProc += AuraEffectProcFn(spell_he_softfoot_noxious_poison_AuraScript::OnProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_he_softfoot_noxious_poison_AuraScript();
        }
};

/// Mark of Anguish - 144365
class spell_he_softfoot_mark_of_anguish_dmg : public SpellScript
{
    PrepareSpellScript(spell_he_softfoot_mark_of_anguish_dmg);

    void HandleDamage(SpellEffIndex /*p_EffIndex*/)
    {
        // This spell has SPELL_ATTR3_NO_DONE_BONUS and SPELL_ATTR6_NO_DONE_PCT_DAMAGE_MODS.
        // So calclate damage manually.
        auto l_Damage = GetHitDamage();

        if (auto l_Target = GetHitUnit())
            if (auto l_Aura = l_Target->GetAura(Spells::SPELL_SHADOW_WEAKNESS_DEBUFF))
                SetHitDamage(AddPct(l_Damage, l_Aura->GetEffect(SpellEffIndex::EFFECT_0)->GetAmount()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_he_softfoot_mark_of_anguish_dmg::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

/// Called by Shadow Weakness - 144079
class spell_he_softfoot_shadow_weakness : public SpellScriptLoader
{
    public:
        spell_he_softfoot_shadow_weakness() : SpellScriptLoader("spell_he_softfoot_shadow_weakness") { }

        class spell_he_softfoot_shadow_weakness_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_he_softfoot_shadow_weakness_AuraScript);

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* l_Caster = eventInfo.GetActor();
                Unit* l_Target = eventInfo.GetActionTarget();

                if (!l_Caster || !l_Target)
                    return;

                l_Caster->CastSpell(l_Target, Spells::SPELL_SHADOW_WEAKNESS_DEBUFF, true);
            }

            void Register()
            {
                OnEffectProc += AuraEffectProcFn(spell_he_softfoot_shadow_weakness_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }

        };

        AuraScript* GetAuraScript() const
        {
            return new spell_he_softfoot_shadow_weakness_AuraScript();
        }
};

struct spell_area_sun_tenderheart_dark_meditation : public AreaTriggerAI
{
    spell_area_sun_tenderheart_dark_meditation(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }


    void OnUnitEnter(Unit* unit)
    {
        if (!at->GetCaster())
            return;

        at->GetCaster()->AddAura(SPELL_MEDITATIVE_FIELD, unit);
    }

    void OnUnitExit(Unit* unit)
    {
        unit->RemoveAura(SPELL_MEDITATIVE_FIELD);
    }
};

struct spell_area_he_softfoot_noxious_poison : public AreaTriggerAI
{
    spell_area_he_softfoot_noxious_poison(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (!at->GetCaster())
            return;

        at->GetCaster()->AddAura(SPELL_NOXIOUS_POISON_AURA, unit);
    }

    void OnUnitExit(Unit* unit)
    {
        unit->RemoveAura(SPELL_NOXIOUS_POISON_AURA);
    }
};

/// Defiled Ground - 143959
class spell_rook_stonetoe_defiled_ground : public AuraScript
{
    PrepareAuraScript(spell_rook_stonetoe_defiled_ground);

    ObjectGuid m_TriggerGuid = ObjectGuid::Empty;

    // todo: readd
    /*void SetGUID(ObjectGuid guid, int32 id) override
    {
        m_TriggerGuid = guid;
    }

    ObjectGuid GetGUID(int32 id) const override
    {
        return m_TriggerGuid;
    }*/

    void Register() override { }
};

/// Defiled Ground - 143960 (not existing in dbc)
struct spell_area_rook_stonetoe_defiled_ground : public AreaTriggerAI
{
    spell_area_rook_stonetoe_defiled_ground(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    bool OnAddTarget(Unit* p_Target)
    {
        return p_Target->IsPlayer();
    }

    void OnUnitEnter(Unit* target)
    {
        if (!target->IsPlayer())
            return;

        Aura* l_DefiledGround = target->GetAura(Spells::SPELL_DEFILED_GROUND_AURA);
        bool l_HasInArc = at->HasInArc(float(M_PI) / 2, target);

        if (l_DefiledGround /*&& l_DefiledGround->GetScriptGuid(0) == trigger->GetGUID() */ && !l_HasInArc)
            l_DefiledGround->Remove();
        else if (l_HasInArc && l_DefiledGround == nullptr)
            if (auto l_Aura = target->AddAura(Spells::SPELL_DEFILED_GROUND_AURA, target))
                //l_Aura->SetScriptGuid(0, at->GetGUID());
                return;
    }

    void OnUnitExit(Unit* unit)
    {
        Aura* l_DefiledGround = unit->GetAura(Spells::SPELL_DEFILED_GROUND_AURA);

        if (l_DefiledGround /*&& l_DefiledGround->GetScriptGuid(0) == at->GetGUID()*/)
            l_DefiledGround->Remove();
    }
};

/// Shadowstep - 143262
class spell_he_stonefoot_shadowstep : public SpellScript
{
    PrepareSpellScript(spell_he_stonefoot_shadowstep);

    bool Load() override
    {
        return GetCaster()->IsCreature();
    }

    void HandleDummy(SpellEffIndex /*p_EffIndex*/)
    {
        if (Unit* l_Target = GetHitUnit())
            GetCaster()->CastSpell(l_Target, Spells::SPELL_SHADOWSTEP, true);

        GetCaster()->ToCreature()->AI()->DoAction(Actions::ACTION_PREPARE_SHADOWSTEP_BACK);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_he_stonefoot_shadowstep::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/// Vengeful Strikes - 144396
class spell_rook_stonetoe_vengeful_strikes : public AuraScript
{
    PrepareAuraScript(spell_rook_stonetoe_vengeful_strikes);

    bool Load() override
    {
        return GetCaster()->IsCreature();
    }

    void OnRemove(AuraEffect const* p_AurEff, AuraEffectHandleModes /*p_Mode*/)
    {
        if (auto l_Caster = GetCaster())
            if (GetTargetApplication()->GetRemoveMode() != AuraRemoveMode::AURA_REMOVE_BY_EXPIRE)
                l_Caster->ToCreature()->AI()->DoAction(Actions::ACTION_VENGEFUL_STRIKES_FAILED);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_rook_stonetoe_vengeful_strikes::OnRemove, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

/// Spirit Bound - 143724
class spell_sun_tenderheart_spawn_spirit_bound : public AuraScript
{
    PrepareAuraScript(spell_sun_tenderheart_spawn_spirit_bound);

    bool Load() override
    {
        return GetCaster()->IsCreature();
    }

    void OnPeriodic(AuraEffect const* /*p_AurEff*/)
    {
        if (auto l_Caster = GetCaster())
            l_Caster->ToCreature()->AI()->DoAction(Actions::ACTION_SPAWNS_SYNC_HP);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sun_tenderheart_spawn_spirit_bound::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_boss_fallen_protectors()
{
    new boss_rook_stonetoe();                               // 71475
    new boss_he_softfoot();                                 // 71479
    new boss_sun_tenderheart();                             // 71480

    RegisterCreatureAI(npc_rook_stonetoe_embodied_misery);          // 71476
    RegisterCreatureAI(npc_rook_stonetoe_embodied_sorrow);          // 71481
    RegisterCreatureAI(npc_rook_stonetoe_embodied_gloom);           // 71477

    RegisterCreatureAI(npc_he_softfoot_embodied_anguish);           // 71478

    RegisterCreatureAI(npc_sun_tenderheart_embodied_despair);       // 71474
    RegisterCreatureAI(npc_sun_tenderheart_embodied_desperation);   // 71482
    RegisterCreatureAI(npc_sun_tenderheart_spawn);                  // 71712, 71993

    new spell_sun_tenderheart_calamity();                   // 143491

    RegisterSpellScript(spell_sun_tenderheart_shadow_word_bane);        // 143446
    RegisterSpellScript(spell_sun_tenderheart_shadow_word_bane_aoe);    // 143438
    RegisterAuraScript(spell_sun_tenderheart_shadow_word_bane_dmg);     // 143434

    RegisterSpellScript(spell_sun_sha_shear);               // 143424
    RegisterSpellScript(spell_rook_stonetoe_corrupted_brew_aoe);        // 143019
    new spell_rook_stonetoe_clash_aoe();                    // 143027
    new spell_rook_stonetoe_inferno_strike();               // 143962
    RegisterSpellScript(spell_rook_stonetoe_corruption_shock_aoe);           // 143958
    RegisterSpellScript(spell_he_stonefoot_gouge);          // 143330
    new spell_he_softfoot_mark_of_anguish_aoe();            // 143822
    RegisterSpellScript(spell_he_softfoot_mark_of_anguish_dummy);            // 143842
    new spell_he_softfoot_shadow_weakness_aoe();            // 144081
    RegisterAuraScript(spell_he_softfoot_mark_of_anguish_aura_2);            // 143840
    new spell_he_softfoot_instant_poison();                 // 143210
    new spell_he_softfoot_noxious_poison();                 // 143225
    RegisterSpellScript(spell_he_softfoot_mark_of_anguish_dmg);              // 144365
    new spell_he_softfoot_shadow_weakness();                // 144079

    RegisterAreaTriggerAI(spell_area_sun_tenderheart_dark_meditation);       // 143546
    RegisterAreaTriggerAI(spell_area_he_softfoot_noxious_poison);            // 143235

    RegisterAuraScript(spell_rook_stonetoe_defiled_ground);                  // 143959
    RegisterAreaTriggerAI(spell_area_rook_stonetoe_defiled_ground);          // 143960

    RegisterSpellScript(spell_he_stonefoot_shadowstep);                      // 143262
    RegisterAuraScript(spell_rook_stonetoe_vengeful_strikes);                // 144396

    RegisterAuraScript(spell_sun_tenderheart_spawn_spirit_bound);            // 143724
}
