/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "PoolMgr.h"
#include "Group.h"
#include "icecrown_citadel.h"

enum ScriptTexts
{
    // Lady Deathwhisper
    SAY_INTRO_1                 = 0,
    SAY_INTRO_2                 = 1,
    SAY_INTRO_3                 = 2,
    SAY_INTRO_4                 = 3,
    SAY_INTRO_5                 = 4,
    SAY_INTRO_6                 = 5,
    SAY_INTRO_7                 = 6,
    SAY_AGGRO                   = 7,
    SAY_PHASE_2                 = 8,
    EMOTE_PHASE_2               = 9,
    SAY_DOMINATE_MIND           = 10,
    SAY_DARK_EMPOWERMENT        = 11,
    SAY_DARK_TRANSFORMATION     = 12,
    SAY_ANIMATE_DEAD            = 13,
    SAY_KILL                    = 14,
    SAY_BERSERK                 = 15,
    SAY_DEATH                   = 16,

    // Darnavan
    SAY_DARNAVAN_AGGRO          = 0,
    SAY_DARNAVAN_RESCUED        = 1,
};

enum Spells
{
    // Lady Deathwhisper
    SPELL_MANA_BARRIER              = 70842,
    SPELL_SHADOW_BOLT               = 71254,
    SPELL_DEATH_AND_DECAY           = 71001,
    SPELL_DOMINATE_MIND_H           = 71289,
    SPELL_FROSTBOLT                 = 71420,
    SPELL_FROSTBOLT_VOLLEY          = 72905,
    SPELL_TOUCH_OF_INSIGNIFICANCE   = 71204,
    SPELL_SUMMON_SHADE              = 71363,
    SPELL_SHADOW_CHANNELING         = 43897, // Prefight, during intro
    SPELL_DARK_TRANSFORMATION_T     = 70895,
    SPELL_DARK_EMPOWERMENT_T        = 70896,
    SPELL_DARK_MARTYRDOM_T          = 70897,

    // Achievement
    SPELL_FULL_HOUSE                = 72827, // does not exist in dbc but still can be used for criteria check

    // Both Adds
    SPELL_TELEPORT_VISUAL           = 41236,

    // Fanatics
    SPELL_DARK_TRANSFORMATION       = 70900,
    SPELL_NECROTIC_STRIKE           = 70659,
    SPELL_SHADOW_CLEAVE             = 70670,
    SPELL_VAMPIRIC_MIGHT            = 70674,
    SPELL_FANATIC_S_DETERMINATION   = 71235,
    SPELL_DARK_MARTYRDOM_FANATIC    = 71236,

    //  Adherents
    SPELL_DARK_EMPOWERMENT          = 70901,
    SPELL_FROST_FEVER               = 67767,
    SPELL_DEATHCHILL_BOLT           = 70594,
    SPELL_DEATHCHILL_BLAST          = 70906,
    SPELL_CURSE_OF_TORPOR           = 71237,
    SPELL_SHORUD_OF_THE_OCCULT      = 70768,
    SPELL_ADHERENT_S_DETERMINATION  = 71234,
    SPELL_DARK_MARTYRDOM_ADHERENT   = 70903,

    // Vengeful Shade
    SPELL_VENGEFUL_BLAST            = 71544,
    SPELL_VENGEFUL_BLAST_PASSIVE    = 71494,
    SPELL_VENGEFUL_BLAST_25N        = 72010,
    SPELL_VENGEFUL_BLAST_10H        = 72011,
    SPELL_VENGEFUL_BLAST_25H        = 72012,

    // Darnavan
    SPELL_BLADESTORM                = 65947,
    SPELL_CHARGE                    = 65927,
    SPELL_INTIMIDATING_SHOUT        = 65930,
    SPELL_MORTAL_STRIKE             = 65926,
    SPELL_SHATTERING_THROW          = 65940,
    SPELL_SUNDER_ARMOR              = 65936,
};

enum Events
{
    // Lady Deathwhisper
    EVENT_INTRO_2                       = 1,
    EVENT_INTRO_3                       = 2,
    EVENT_INTRO_4                       = 3,
    EVENT_INTRO_5                       = 4,
    EVENT_INTRO_6                       = 5,
    EVENT_INTRO_7                       = 6,
    EVENT_INTRO_FINISH                  = 7,
    EVENT_BERSERK                       = 8,
    EVENT_DEATH_AND_DECAY               = 9,
    EVENT_DOMINATE_MIND_H               = 10,

    // Phase 1 only
    EVENT_P1_SUMMON_WAVE                = 11,
    EVENT_P1_SHADOW_BOLT                = 12,
    EVENT_P1_EMPOWER_CULTIST            = 13,
    EVENT_P1_REANIMATE_CULTIST          = 14,

    // Phase 2 only
    EVENT_P2_SUMMON_WAVE                = 15,
    EVENT_P2_FROSTBOLT                  = 16,
    EVENT_P2_FROSTBOLT_VOLLEY           = 17,
    EVENT_P2_TOUCH_OF_INSIGNIFICANCE    = 18,
    EVENT_P2_SUMMON_SHADE               = 19,

    // Shared adds events
    EVENT_CULTIST_DARK_MARTYRDOM        = 20,

    // Cult Fanatic
    EVENT_FANATIC_NECROTIC_STRIKE       = 21,
    EVENT_FANATIC_SHADOW_CLEAVE         = 22,
    EVENT_FANATIC_VAMPIRIC_MIGHT        = 23,

    // Cult Adherent
    EVENT_ADHERENT_FROST_FEVER          = 24,
    EVENT_ADHERENT_DEATHCHILL           = 25,
    EVENT_ADHERENT_CURSE_OF_TORPOR      = 26,
    EVENT_ADHERENT_SHORUD_OF_THE_OCCULT = 27,

    // Darnavan
    EVENT_DARNAVAN_BLADESTORM           = 28,
    EVENT_DARNAVAN_CHARGE               = 29,
    EVENT_DARNAVAN_INTIMIDATING_SHOUT   = 30,
    EVENT_DARNAVAN_MORTAL_STRIKE        = 31,
    EVENT_DARNAVAN_SHATTERING_THROW     = 32,
    EVENT_DARNAVAN_SUNDER_ARMOR         = 33,
};

enum Phases
{
    PHASE_ALL       = 0,
    PHASE_INTRO     = 1,
    PHASE_ONE       = 2,
    PHASE_TWO       = 3,

    PHASE_INTRO_MASK    = 1 << PHASE_INTRO,
    PHASE_ONE_MASK      = 1 << PHASE_ONE,
};

enum DeprogrammingData
{
    NPC_DARNAVAN_10         = 38472,
    NPC_DARNAVAN_25         = 38485,
    NPC_DARNAVAN_CREDIT_10  = 39091,
    NPC_DARNAVAN_CREDIT_25  = 39092,

    ACTION_COMPLETE_QUEST   = -384720,
    POINT_DESPAWN           = 384721,
};

#define NPC_DARNAVAN RAID_MODE<uint32>(NPC_DARNAVAN_10,NPC_DARNAVAN_25,NPC_DARNAVAN_10,NPC_DARNAVAN_25)
#define NPC_DARNAVAN_CREDIT RAID_MODE<uint32>(NPC_DARNAVAN_CREDIT_10,NPC_DARNAVAN_CREDIT_25,NPC_DARNAVAN_CREDIT_10,NPC_DARNAVAN_CREDIT_25)
#define QUEST_DEPROGRAMMING RAID_MODE<uint32>(QUEST_DEPROGRAMMING_10,QUEST_DEPROGRAMMING_25,QUEST_DEPROGRAMMING_10,QUEST_DEPROGRAMMING_25)

static const uint32 addEntries[2] = {NPC_CULT_FANATIC, NPC_CULT_ADHERENT};

static const Position addSpawnPos[7] =
{
    {-578.7066f, 2154.167f, 51.01529f, 1.692969f}, // 1 Left Door 1 (Cult Fanatic)
    {-598.9028f, 2155.005f, 51.01530f, 1.692969f}, // 2 Left Door 2 (Cult Adherent)
    {-619.2864f, 2154.460f, 51.01530f, 1.692969f}, // 3 Left Door 3 (Cult Fanatic)
    {-578.6996f, 2269.856f, 51.01529f, 4.590216f}, // 4 Right Door 1 (Cult Adherent)
    {-598.9688f, 2269.264f, 51.01529f, 4.590216f}, // 5 Right Door 2 (Cult Fanatic)
    {-619.4323f, 2268.523f, 51.01530f, 4.590216f}, // 6 Right Door 3 (Cult Adherent)
    {-524.2480f, 2211.920f, 62.90960f, 3.141592f}, // 7 Upper (Random Cultist)
};

class DaranavanMoveEvent : public BasicEvent
{
    public:
        DaranavanMoveEvent(Creature& _darnavan) : darnavan(_darnavan) { }

        bool Execute(uint64 , uint32 )
        {
            darnavan.GetMotionMaster()->MovePoint(POINT_DESPAWN, addSpawnPos[6]);
            return true;
        }

        Creature& darnavan;
};

class boss_lady_deathwhisper : public CreatureScript
{
    public:
        boss_lady_deathwhisper() : CreatureScript("boss_lady_deathwhisper") { }

        struct boss_lady_deathwhisperAI : public BossAI
        {
            boss_lady_deathwhisperAI(Creature* creature) : BossAI(creature, DATA_DEATHWHISPER_EVENT)
            {
                introDone = false;
                dominateMindCount = RAID_MODE<uint8>(0, 1, 1, 3);
            }

            void InitializeAI()
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != GetScriptId(ICCScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void Reset()
            {
                _Reset();
                me->SetPower(POWER_MANA, me->GetMaxPower(POWER_MANA));
                me->SetLastManaUse(0xFFFFFFFF); // hacky, but no other way atm to prevent mana regen
                events.SetPhase(PHASE_ONE);
                addWaveCounter = 0;
                nextVengefulShadeTarget = 0;
                darnavanGUID = 0;
                DoCast(me, SPELL_SHADOW_CHANNELING);
                me->RemoveAurasDueToSpell(SPELL_BERSERK);
                me->RemoveAurasDueToSpell(SPELL_MANA_BARRIER);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!introDone && me->IsWithinDistInMap(who, 100.0f))
                {
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    introDone = true;
                    Talk(SAY_INTRO_1);
                    events.SetPhase(PHASE_INTRO);
                    events.ScheduleEvent(EVENT_INTRO_2, 11000, 0, PHASE_INTRO);
                    events.ScheduleEvent(EVENT_INTRO_3, 21000, 0, PHASE_INTRO);
                    events.ScheduleEvent(EVENT_INTRO_4, 31500, 0, PHASE_INTRO);
                    events.ScheduleEvent(EVENT_INTRO_5, 39500, 0, PHASE_INTRO);
                    events.ScheduleEvent(EVENT_INTRO_6, 48500, 0, PHASE_INTRO);
                    events.ScheduleEvent(EVENT_INTRO_7, 58000, 0, PHASE_INTRO);
                    events.ScheduleEvent(EVENT_INTRO_FINISH, 76000, 0, PHASE_INTRO);
                }
            }

            void AttackStart(Unit* victim)
            {
                if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                    return;

                if (victim && me->Attack(victim, true) && !(events.GetPhaseMask() & PHASE_ONE_MASK))
                    me->GetMotionMaster()->MoveChase(victim);
            }

            void EnterCombat(Unit* who)
            {
                events.Reset();
                events.SetPhase(PHASE_ONE);
                // phase-independent events
                events.ScheduleEvent(EVENT_BERSERK, 600000);
                events.ScheduleEvent(EVENT_DEATH_AND_DECAY, 10000);
                // phase one only
                events.ScheduleEvent(EVENT_P1_SUMMON_WAVE, 5000, 0, PHASE_ONE);
                events.ScheduleEvent(EVENT_P1_SHADOW_BOLT, urand(5500, 6000), 0, PHASE_ONE);
                events.ScheduleEvent(EVENT_P1_EMPOWER_CULTIST, urand(20000, 30000), 0, PHASE_ONE);
                if (GetDifficulty() != RAID_DIFFICULTY_10MAN_NORMAL)
                    events.ScheduleEvent(EVENT_DOMINATE_MIND_H, 27000);

                Talk(SAY_AGGRO);
                DoStartNoMovement(who);
                me->RemoveAurasDueToSpell(SPELL_SHADOW_CHANNELING);
                DoCast(me, SPELL_MANA_BARRIER, true);

                instance->SetBossState(DATA_DEATHWHISPER_EVENT, IN_PROGRESS);
                instance->SetData(DATA_DEATHWHISPER_EVENT, IN_PROGRESS);            }

            void JustDied(Unit* killer)
            {
                Talk(SAY_DEATH);

                instance->SetBossState(DATA_DEATHWHISPER_EVENT, DONE);                
                instance->SetData(DATA_DEATHWHISPER_EVENT, DONE);                
                std::set<uint32> livingAddEntries;                // Full House achievement
                for (SummonList::iterator itr = summons.begin(); itr != summons.end(); ++itr)
                    if (Unit* unit = ObjectAccessor::GetUnit(*me, *itr))
                        if (unit->isAlive() && unit->GetEntry() != NPC_VENGEFUL_SHADE)
                            livingAddEntries.insert(unit->GetEntry());

                if (livingAddEntries.size() >= 5)
                    instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_FULL_HOUSE, 0, me);

                if (Creature* darnavan = ObjectAccessor::GetCreature(*me, darnavanGUID))
                {
                    if (darnavan->isAlive())
                    {
                        darnavan->setFaction(35);
                        darnavan->CombatStop(true);
                        darnavan->GetMotionMaster()->MoveIdle();
                        darnavan->SetReactState(REACT_PASSIVE);
                        darnavan->m_Events.AddEvent(new DaranavanMoveEvent(*darnavan), darnavan->m_Events.CalculateTime(10000));
                        darnavan->AI()->Talk(SAY_DARNAVAN_RESCUED);
                        if (Player* owner = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
                        {
                            if (Group* group = owner->GetGroup())
                            {
                                for (GroupReference *itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
                                    if (Player* member = itr->getSource())
                                        member->KilledMonsterCredit(NPC_DARNAVAN_CREDIT, 0);
                            }
                            else
                                owner->KilledMonsterCredit(NPC_DARNAVAN_CREDIT, 0);
                        }
                    }
                }

                _JustDied();
                summons.DespawnAll();
            }

            void JustReachedHome()
            {
                _JustReachedHome();
                 instance->SetBossState(DATA_DEATHWHISPER_EVENT, FAIL);
                 instance->SetData(DATA_DEATHWHISPER_EVENT, FAIL);

                summons.DespawnAll();
                if (Creature* darnavan = ObjectAccessor::GetCreature(*me, darnavanGUID))
                {
                    darnavan->DespawnOrUnsummon();
                    darnavanGUID = 0;
                }
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void DamageTaken(Unit* /*damageDealer*/, uint32& uiDamage)
            {
                // phase transition
                if (events.GetPhaseMask() & PHASE_ONE_MASK && uiDamage > me->GetPower(POWER_MANA))
                {
                    Talk(SAY_PHASE_2);
                    Talk(EMOTE_PHASE_2);
                    DoStartMovement(me->getVictim());
                    uiDamage -= me->GetPower(POWER_MANA);
                    me->SetPower(POWER_MANA, 0);
                    me->RemoveAurasDueToSpell(SPELL_MANA_BARRIER);
                    events.SetPhase(PHASE_TWO);
                    events.ScheduleEvent(EVENT_P2_FROSTBOLT, urand(10000, 12000), 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_P2_FROSTBOLT_VOLLEY, urand(19000, 21000), 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_P2_TOUCH_OF_INSIGNIFICANCE, urand(6000, 9000), 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_P2_SUMMON_SHADE, urand(12000, 15000), 0, PHASE_TWO);
                    // on heroic mode Lady Deathwhisper is immune to taunt effects in phase 2 and continues summoning adds
                    if (IsHeroic())
                    {
                        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                        events.ScheduleEvent(EVENT_P2_SUMMON_WAVE, urand(30000, 60000), 0, PHASE_TWO);
                    }
                }
            }

            void JustSummoned(Creature* summon)
            {
                if (summon->GetEntry() == NPC_DARNAVAN)
                    darnavanGUID = summon->GetGUID();
                else
                    summons.push_back(summon->GetGUID());

                Unit* target = NULL;
                if (summon->GetEntry() == NPC_VENGEFUL_SHADE)
                {
                    target = ObjectAccessor::GetUnit(*me, nextVengefulShadeTarget);   // Vengeful Shade
                    nextVengefulShadeTarget = 0;
                }
                else
                    target = SelectTarget(SELECT_TARGET_RANDOM);                        // Wave adds

                summon->AI()->AttackStart(target);                                      // CAN be NULL
                if (summon->GetEntry() == NPC_REANIMATED_FANATIC)
                    summon->AI()->DoCast(summon, SPELL_FANATIC_S_DETERMINATION);
                else if (summon->GetEntry() == NPC_REANIMATED_ADHERENT)
                    summon->AI()->DoCast(summon, SPELL_ADHERENT_S_DETERMINATION);
            }

            void UpdateAI(const uint32 diff)
            {
                if ((!UpdateVictim() && !(events.GetPhaseMask() & PHASE_INTRO_MASK)) || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING) && !(events.GetPhaseMask() & PHASE_INTRO_MASK))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INTRO_2:
                            Talk(SAY_INTRO_2);
                            break;
                        case EVENT_INTRO_3:
                            Talk(SAY_INTRO_3);
                            break;
                        case EVENT_INTRO_4:
                            Talk(SAY_INTRO_4);
                            break;
                        case EVENT_INTRO_5:
                            Talk(SAY_INTRO_5);
                            break;
                        case EVENT_INTRO_6:
                            Talk(SAY_INTRO_6);
                            break;
                        case EVENT_INTRO_7:
                            Talk(SAY_INTRO_7);
                            break;
                        case EVENT_INTRO_FINISH:
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            break;
                        case EVENT_DEATH_AND_DECAY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_DEATH_AND_DECAY);
                            events.ScheduleEvent(EVENT_DEATH_AND_DECAY, urand(10000, 12000));
                            break;
                        case EVENT_DOMINATE_MIND_H:
                            Talk(SAY_DOMINATE_MIND);
                            for (uint8 i = 0; i < dominateMindCount; i++)
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_DOMINATE_MIND_H))
                                    DoCast(target, SPELL_DOMINATE_MIND_H);
                            events.ScheduleEvent(EVENT_DOMINATE_MIND_H, urand(40000, 45000));
                            break;
                        case EVENT_P1_SUMMON_WAVE:
                            SummonWaveP1();
                            events.ScheduleEvent(EVENT_P1_SUMMON_WAVE, 60000, 0, PHASE_ONE);
                            break;
                        case EVENT_P1_SHADOW_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_SHADOW_BOLT);
                            events.ScheduleEvent(EVENT_P1_SHADOW_BOLT, urand(5000, 8000), 0, PHASE_ONE);
                            break;
                        case EVENT_P1_REANIMATE_CULTIST:
                            ReanimateCultist();
                            break;
                        case EVENT_P1_EMPOWER_CULTIST:
                            EmpowerCultist();
                            events.ScheduleEvent(EVENT_P1_EMPOWER_CULTIST, urand(18000, 25000));
                            break;
                        case EVENT_P2_FROSTBOLT:
                            DoCastVictim(SPELL_FROSTBOLT);
                            events.ScheduleEvent(EVENT_P2_FROSTBOLT, urand(10000, 11000), 0, PHASE_TWO);
                            break;
                        case EVENT_P2_FROSTBOLT_VOLLEY:
                            DoCastAOE(SPELL_FROSTBOLT_VOLLEY);
                            events.ScheduleEvent(EVENT_P2_FROSTBOLT_VOLLEY, urand(13000, 15000), 0, PHASE_TWO);
                            break;
                        case EVENT_P2_TOUCH_OF_INSIGNIFICANCE:
                            DoCastVictim(SPELL_TOUCH_OF_INSIGNIFICANCE);
                            events.ScheduleEvent(EVENT_P2_TOUCH_OF_INSIGNIFICANCE, urand(9000, 13000), 0, PHASE_TWO);
                            break;
                        case EVENT_P2_SUMMON_SHADE:
                            if (Unit* shadeTarget = SelectTarget(SELECT_TARGET_RANDOM, 1))
                            {
                                nextVengefulShadeTarget = shadeTarget->GetGUID();
                                DoCast(shadeTarget, SPELL_SUMMON_SHADE);
                            }
                            events.ScheduleEvent(EVENT_P2_SUMMON_SHADE, urand(18000, 23000), 0, PHASE_TWO);
                            break;
                        case EVENT_P2_SUMMON_WAVE:
                            SummonWaveP2();
                            events.ScheduleEvent(EVENT_P2_SUMMON_WAVE, 60000, 0, PHASE_TWO);
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            Talk(SAY_BERSERK);
                            break;
                    }
                }

                // We should not melee attack when barrier is up
                if (me->HasAura(SPELL_MANA_BARRIER))
                    return;

                DoMeleeAttackIfReady();
            }

            // summoning function for first phase
            void SummonWaveP1()
            {
                uint8 addIndex = addWaveCounter & 1;
                uint8 addIndexOther = uint8(addIndex ^ 1);
                if (addWaveCounter || !sPoolMgr->IsSpawnedObject<Quest>(QUEST_DEPROGRAMMING))
                    _SummonAdd(addEntries[addIndex], addSpawnPos[addIndex*3]);
                else
                    _SummonAdd(NPC_DARNAVAN, addSpawnPos[addIndex*3]);
                _SummonAdd(addEntries[addIndexOther], addSpawnPos[addIndex*3+1]);
                _SummonAdd(addEntries[addIndex], addSpawnPos[addIndex*3+2]);
                if (Is25ManRaid())
                {
                    _SummonAdd(addEntries[addIndexOther], addSpawnPos[addIndexOther*3]);
                    _SummonAdd(addEntries[addIndex], addSpawnPos[addIndexOther*3+1]);
                    _SummonAdd(addEntries[addIndexOther], addSpawnPos[addIndexOther*3+2]);
                    _SummonAdd(addEntries[urand(0,1)], addSpawnPos[6]);
                }
                ++addWaveCounter;
            }

            // summoning function for second phase
            void SummonWaveP2()
            {
                if (Is25ManRaid())
                {
                    uint8 addIndex = addWaveCounter & 1;
                    _SummonAdd(addEntries[addIndex], addSpawnPos[addIndex*3]);
                    _SummonAdd(addEntries[addIndex ^ 1], addSpawnPos[addIndex*3+1]);
                    _SummonAdd(addEntries[addIndex], addSpawnPos[addIndex*3+2]);
                }
                else
                    _SummonAdd(addEntries[urand(0,1)], addSpawnPos[6]);
                ++addWaveCounter;
            }

            // helper for summoning wave mobs
            void _SummonAdd(uint32 entry, const Position& pos)
            {
                if (TempSummon* summon = me->SummonCreature(entry, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
                    summon->AI()->DoCast(summon, SPELL_TELEPORT_VISUAL);
            }

            void AddToReanimationQueue(Unit* summon)
            {
                reanimationQueue.push_back(summon->GetGUID());
                events.ScheduleEvent(EVENT_P1_REANIMATE_CULTIST, 3000, 0, PHASE_ONE);
            }

            void ReanimateCultist()
            {
                if (reanimationQueue.empty())
                    return;

                uint64 cultistGUID = reanimationQueue.front();
                Creature* cultist = ObjectAccessor::GetCreature(*me, cultistGUID);
                reanimationQueue.pop_front();
                if (!cultist)
                    return;

                Talk(SAY_ANIMATE_DEAD);
                DoCast(cultist, SPELL_DARK_MARTYRDOM_T);
            }

            void SpellHitTarget(Unit* target, SpellEntry const* spell)
            {
                if (spell->Id == SPELL_DARK_MARTYRDOM_T)
                {
                    Position pos;
                    target->GetPosition(&pos);
                    if (target->GetEntry() == NPC_CULT_FANATIC)
                        me->SummonCreature(NPC_REANIMATED_FANATIC, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    else
                        me->SummonCreature(NPC_REANIMATED_ADHERENT, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);

                    if (TempSummon* summon = target->ToTempSummon())
                        summon->UnSummon();
                }
            }

            void EmpowerCultist()
            {
                if (summons.empty())
                    return;

                std::list<Creature*> tmpList;
                for (SummonList::iterator itr = summons.begin(); itr != summons.end(); ++itr)
                    if (Creature* cre = ObjectAccessor::GetCreature(*me, *itr))
                        if (cre->isAlive() && (cre->GetEntry() == NPC_CULT_FANATIC || cre->GetEntry() == NPC_CULT_ADHERENT))
                            tmpList.push_back(cre);

                // noone to empower
                if (tmpList.empty())
                    return;

                // select random cultist
                std::list<Creature*>::iterator cultistItr = tmpList.begin();
                std::advance(cultistItr, urand(0, tmpList.size()-1));

                Creature* cultist = *cultistItr;
                DoCast(cultist, cultist->GetEntry() == NPC_CULT_FANATIC ? SPELL_DARK_TRANSFORMATION_T : SPELL_DARK_EMPOWERMENT_T, true);
                Talk(uint8(cultist->GetEntry() == NPC_CULT_FANATIC ? SAY_DARK_TRANSFORMATION : SAY_DARK_EMPOWERMENT));
            }

        private:
            uint64 nextVengefulShadeTarget;
            uint64 darnavanGUID;
            std::deque<uint64> reanimationQueue;
            uint32 addWaveCounter;
            uint8 dominateMindCount;
            bool introDone;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_lady_deathwhisperAI(creature);
        }
};

typedef boss_lady_deathwhisper::boss_lady_deathwhisperAI DeathwisperAI;

class npc_cult_fanatic : public CreatureScript
{
    public:
        npc_cult_fanatic() : CreatureScript("npc_cult_fanatic") { }

        struct npc_cult_fanaticAI : public ScriptedAI
        {
            npc_cult_fanaticAI(Creature* creature) : ScriptedAI(creature) {}

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_FANATIC_NECROTIC_STRIKE, urand(10000, 12000));
                events.ScheduleEvent(EVENT_FANATIC_SHADOW_CLEAVE, urand(14000, 16000));
                events.ScheduleEvent(EVENT_FANATIC_VAMPIRIC_MIGHT, urand(20000, 27000));
                if (me->GetEntry() == NPC_CULT_FANATIC)
                    events.ScheduleEvent(EVENT_CULTIST_DARK_MARTYRDOM, urand(18000, 32000));
            }

            void SpellHit(Unit* /*caster*/, SpellEntry const* spell)
            {
                if (spell->Id == SPELL_DARK_TRANSFORMATION)
                    me->UpdateEntry(NPC_DEFORMED_FANATIC);
                else if (spell->Id == SPELL_DARK_TRANSFORMATION_T)
                {
                    events.CancelEvent(EVENT_CULTIST_DARK_MARTYRDOM);
                    me->InterruptNonMeleeSpells(true);
                    DoCast(me, SPELL_DARK_TRANSFORMATION);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FANATIC_NECROTIC_STRIKE:
                            DoCastVictim(SPELL_NECROTIC_STRIKE);
                            events.ScheduleEvent(SPELL_NECROTIC_STRIKE, urand(11000, 13000));
                            break;
                        case EVENT_FANATIC_SHADOW_CLEAVE:
                            DoCastVictim(SPELL_SHADOW_CLEAVE);
                            events.ScheduleEvent(EVENT_FANATIC_SHADOW_CLEAVE, urand(9500, 11000));
                            break;
                        case EVENT_FANATIC_VAMPIRIC_MIGHT:
                            DoCast(me, SPELL_VAMPIRIC_MIGHT);
                            events.ScheduleEvent(EVENT_FANATIC_VAMPIRIC_MIGHT, urand(20000, 27000));
                            break;
                        case EVENT_CULTIST_DARK_MARTYRDOM:
                            DoCast(me, SPELL_DARK_MARTYRDOM_FANATIC);
                            events.ScheduleEvent(EVENT_CULTIST_DARK_MARTYRDOM, urand(16000, 21000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_cult_fanaticAI(creature);
        }
};

class npc_cult_adherent : public CreatureScript
{
    public:
        npc_cult_adherent() : CreatureScript("npc_cult_adherent") { }

        struct npc_cult_adherentAI : public ScriptedAI
        {
            npc_cult_adherentAI(Creature* creature) : ScriptedAI(creature) {}

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_ADHERENT_FROST_FEVER, urand(10000, 12000));
                events.ScheduleEvent(EVENT_ADHERENT_DEATHCHILL, urand(14000, 16000));
                events.ScheduleEvent(EVENT_ADHERENT_CURSE_OF_TORPOR, urand(14000, 16000));
                events.ScheduleEvent(EVENT_ADHERENT_SHORUD_OF_THE_OCCULT, urand(32000, 39000));
                if (me->GetEntry() == NPC_CULT_ADHERENT)
                    events.ScheduleEvent(EVENT_CULTIST_DARK_MARTYRDOM, urand(18000, 32000));
            }

            void SpellHit(Unit* /*caster*/, SpellEntry const* spell)
            {
                if (spell->Id == SPELL_DARK_EMPOWERMENT)
                    me->UpdateEntry(NPC_EMPOWERED_ADHERENT);
                else if (spell->Id == SPELL_DARK_EMPOWERMENT_T)
                {
                    events.CancelEvent(EVENT_CULTIST_DARK_MARTYRDOM);
                    me->InterruptNonMeleeSpells(true);
                    DoCast(me, SPELL_DARK_EMPOWERMENT);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ADHERENT_FROST_FEVER:
                            DoCastVictim(SPELL_FROST_FEVER);
                            events.ScheduleEvent(EVENT_ADHERENT_FROST_FEVER, urand(9000, 13000));
                            break;
                        case EVENT_ADHERENT_DEATHCHILL:
                            if (me->GetEntry() == NPC_EMPOWERED_ADHERENT)
                                DoCastVictim(SPELL_DEATHCHILL_BLAST);
                            else
                                DoCastVictim(SPELL_DEATHCHILL_BOLT);
                            events.ScheduleEvent(EVENT_ADHERENT_DEATHCHILL, urand(9000, 13000));
                            break;
                        case EVENT_ADHERENT_CURSE_OF_TORPOR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                                DoCast(target, SPELL_CURSE_OF_TORPOR);
                            events.ScheduleEvent(EVENT_ADHERENT_CURSE_OF_TORPOR, urand(9000, 13000));
                            break;
                        case EVENT_ADHERENT_SHORUD_OF_THE_OCCULT:
                            DoCast(me, SPELL_SHORUD_OF_THE_OCCULT);
                            events.ScheduleEvent(EVENT_ADHERENT_SHORUD_OF_THE_OCCULT, urand(27000, 32000));
                            break;
                        case EVENT_CULTIST_DARK_MARTYRDOM:
                            DoCast(me, SPELL_DARK_MARTYRDOM_ADHERENT);
                            events.ScheduleEvent(EVENT_CULTIST_DARK_MARTYRDOM, urand(16000, 21000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_cult_adherentAI(pCreature);
        }
};

class npc_vengeful_shade : public CreatureScript
{
    public:
        npc_vengeful_shade() : CreatureScript("npc_vengeful_shade") { }

        struct npc_vengeful_shadeAI : public ScriptedAI
        {
            npc_vengeful_shadeAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            void Reset()
            {
                me->AddAura(SPELL_VENGEFUL_BLAST_PASSIVE, me);
            }

            void SpellHitTarget(Unit* /*target*/, SpellEntry const* spell)
            {
                switch (spell->Id)
                {
                    case SPELL_VENGEFUL_BLAST:
                    case SPELL_VENGEFUL_BLAST_25N:
                    case SPELL_VENGEFUL_BLAST_10H:
                    case SPELL_VENGEFUL_BLAST_25H:
                        me->Kill(me);
                        break;
                    default:
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_vengeful_shadeAI(creature);
        }
};

class npc_darnavan : public CreatureScript
{
    public:
        npc_darnavan() : CreatureScript("npc_darnavan") { }

        struct npc_darnavanAI : public ScriptedAI
        {
            npc_darnavanAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_DARNAVAN_BLADESTORM, 10000);
                events.ScheduleEvent(EVENT_DARNAVAN_INTIMIDATING_SHOUT, urand(20000, 25000));
                events.ScheduleEvent(EVENT_DARNAVAN_MORTAL_STRIKE, urand(25000, 30000));
                events.ScheduleEvent(EVENT_DARNAVAN_SUNDER_ARMOR, urand(5000, 8000));
                canCharge = true;
                canShatter = true;
            }

            void JustDied(Unit* killer)
            {
                events.Reset();
                if (Player* owner = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
                {
                    if (Group* group = owner->GetGroup())
                    {
                        for (GroupReference *itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
                            if (Player* member = itr->getSource())
                                member->FailQuest(QUEST_DEPROGRAMMING);
                    }
                    else
                        owner->FailQuest(QUEST_DEPROGRAMMING);
                }
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE || id != POINT_DESPAWN)
                    return;
                me->DespawnOrUnsummon();
            }

            void EnterCombat(Unit* /*victim*/)
            {
                Talk(SAY_DARNAVAN_AGGRO);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                if (canShatter && me->getVictim()->IsImmunedToDamage(SPELL_SCHOOL_MASK_NORMAL))
                {
                    DoCastVictim(SPELL_SHATTERING_THROW);
                    canShatter = false;
                    events.ScheduleEvent(EVENT_DARNAVAN_SHATTERING_THROW, 30000);
                    return;
                }

                if (canCharge && !me->IsWithinMeleeRange(me->getVictim()))
                {
                    DoCastVictim(SPELL_CHARGE);
                    canCharge = false;
                    events.ScheduleEvent(EVENT_DARNAVAN_CHARGE, 20000);
                    return;
                }

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DARNAVAN_BLADESTORM:
                            DoCast(SPELL_BLADESTORM);
                            events.ScheduleEvent(EVENT_DARNAVAN_BLADESTORM, urand(90000, 100000));
                            break;
                        case EVENT_DARNAVAN_CHARGE:
                            canCharge = true;
                            break;
                        case EVENT_DARNAVAN_INTIMIDATING_SHOUT:
                            DoCast(SPELL_INTIMIDATING_SHOUT);
                            events.ScheduleEvent(EVENT_DARNAVAN_INTIMIDATING_SHOUT, urand(90000, 120000));
                            break;
                        case EVENT_DARNAVAN_MORTAL_STRIKE:
                            DoCastVictim(SPELL_MORTAL_STRIKE);
                            events.ScheduleEvent(EVENT_DARNAVAN_MORTAL_STRIKE, urand(15000, 30000));
                            break;
                        case EVENT_DARNAVAN_SHATTERING_THROW:
                            canShatter = true;
                            break;
                        case EVENT_DARNAVAN_SUNDER_ARMOR:
                            DoCastVictim(SPELL_SUNDER_ARMOR);
                            events.ScheduleEvent(EVENT_DARNAVAN_SUNDER_ARMOR, urand(3000, 7000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
            bool canCharge;
            bool canShatter;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_darnavanAI(creature);
        }
};

class spell_deathwhisper_mana_barrier : public SpellScriptLoader
{
    public:
        spell_deathwhisper_mana_barrier() : SpellScriptLoader("spell_deathwhisper_mana_barrier") { }

        class spell_deathwhisper_mana_barrier_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_deathwhisper_mana_barrier_AuraScript);

            void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                Unit* caster = GetCaster();
                int32 missingHealth = int32(caster->GetMaxHealth() - caster->GetHealth());
                caster->ModifyHealth(missingHealth);
                caster->ModifyPower(POWER_MANA, -missingHealth);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_deathwhisper_mana_barrier_AuraScript::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_deathwhisper_mana_barrier_AuraScript();
        }
};

class spell_cultist_dark_martyrdom : public SpellScriptLoader
{
    public:
        spell_cultist_dark_martyrdom() : SpellScriptLoader("spell_cultist_dark_martyrdom") { }

        class spell_cultist_dark_martyrdom_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_cultist_dark_martyrdom_SpellScript);

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                if (GetCaster()->isSummon())
                    if (Unit* owner = GetCaster()->ToTempSummon()->GetSummoner())
                        if (owner->GetEntry() == NPC_LADY_DEATHWHISPER)
                            CAST_AI(boss_lady_deathwhisper::boss_lady_deathwhisperAI, owner->ToCreature()->AI())->AddToReanimationQueue(GetCaster());

                GetCaster()->Kill(GetCaster());
                GetCaster()->SetDisplayId(uint32(GetCaster()->GetEntry() == NPC_CULT_FANATIC ? 38009 : 38010));
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_cultist_dark_martyrdom_SpellScript::HandleEffect, EFFECT_2, SPELL_EFFECT_FORCE_DESELECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_cultist_dark_martyrdom_SpellScript();
        }
};

void AddSC_boss_lady_deathwhisper()
{
    new boss_lady_deathwhisper();
    new npc_cult_fanatic();
    new npc_cult_adherent();
    new npc_vengeful_shade();
    new npc_darnavan();
    new spell_deathwhisper_mana_barrier();
    new spell_cultist_dark_martyrdom();
}
