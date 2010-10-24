/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "icecrown_citadel.h"

enum eScriptTexts
{
    SAY_INTRO_1                 = -1631011,
    SAY_INTRO_2                 = -1631012,
    SAY_INTRO_3                 = -1631013,
    SAY_INTRO_4                 = -1631014,
    SAY_INTRO_5                 = -1631015,
    SAY_INTRO_6                 = -1631016,
    SAY_INTRO_7                 = -1631017,
    SAY_AGGRO                   = -1631018,
    SAY_PHASE_2                 = -1631019,
    SAY_PHASE_2_EMOTE           = -1631020,
    SAY_DOMINATE_MIND           = -1631021,
    SAY_DARK_EMPOWERMENT        = -1631022,
    SAY_DARK_TRANSFORMATION     = -1631023,
    SAY_ANIMATE_DEAD            = -1631024,
    SAY_KILL_1                  = -1631025,
    SAY_KILL_2                  = -1631026,
    SAY_BERSERK                 = -1631027,
    SAY_DEATH                   = -1631028
};

enum eSpells
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
    SPELL_VENGEFUL_BLAST_PASSIVE    = 71494
};

enum eEvents
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
    EVENT_ADHERENT_SHORUD_OF_THE_OCCULT = 27
};

enum ePhases
{
    PHASE_ALL       = 0,
    PHASE_INTRO     = 1,
    PHASE_ONE       = 2,
    PHASE_TWO       = 3,

    PHASE_INTRO_MASK    = 1 << PHASE_INTRO,
    PHASE_ONE_MASK      = 1 << PHASE_ONE,
};

static const uint32 uiAddEntries[2] = {NPC_CULT_FANATIC, NPC_CULT_ADHERENT};

static const Position addSpawnPos[7] =
{
    {-578.7066f, 2154.167f, 51.01529f, 1.692969f}, // 1 Left Door 1 (Cult Fanatic)
    {-598.9028f, 2155.005f, 51.01530f, 1.692969f}, // 2 Left Door 2 (Cult Adherent)
    {-619.2864f, 2154.460f, 51.01530f, 1.692969f}, // 3 Left Door 3 (Cult Fanatic)
    {-578.6996f, 2269.856f, 51.01529f, 4.590216f}, // 4 Right Door 1 (Cult Adherent)
    {-598.9688f, 2269.264f, 51.01529f, 4.590216f}, // 5 Right Door 2 (Cult Fanatic)
    {-619.4323f, 2268.523f, 51.01530f, 4.590216f}, // 6 Right Door 3 (Cult Adherent)
    {-524.2480f, 2211.920f, 62.90960f, 3.141592f}  // 7 Upper (Random Cultist)
};

class boss_lady_deathwhisper : public CreatureScript
{
    public:
        boss_lady_deathwhisper() : CreatureScript("boss_lady_deathwhisper") { }

        struct boss_lady_deathwhisperAI : public BossAI
        {
            boss_lady_deathwhisperAI(Creature* pCreature) : BossAI(pCreature, DATA_LADY_DEATHWHISPER)
            {
                bIntroDone = false;
                uiDominateMindCount = RAID_MODE(0,1,1,3);
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
                me->SetPower(POWER_MANA, me->GetMaxPower(POWER_MANA));
                me->SetLastManaUse(0xFFFFFFFF); // hacky, but no other way atm to prevent mana regen
                events.Reset();
                events.SetPhase(PHASE_ONE);
                uiAddWaveCounter = 0;
                uiNextVengefulShadeTarget = 0;
                DoCast(me, SPELL_SHADOW_CHANNELING);
                me->RemoveAurasDueToSpell(SPELL_BERSERK);
                me->RemoveAurasDueToSpell(SPELL_MANA_BARRIER);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
                instance->SetBossState(DATA_LADY_DEATHWHISPER, NOT_STARTED);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!bIntroDone && me->IsWithinDistInMap(who, 100.0f))
                {
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    bIntroDone = true;
                    DoScriptText(SAY_INTRO_1, me);
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
                if (getDifficulty() != RAID_DIFFICULTY_10MAN_NORMAL)
                    events.ScheduleEvent(EVENT_DOMINATE_MIND_H, 27000);

                DoScriptText(SAY_AGGRO, me);
                DoStartNoMovement(who);
                me->RemoveAurasDueToSpell(SPELL_SHADOW_CHANNELING);
                DoCast(me, SPELL_MANA_BARRIER, true);

                instance->SetBossState(DATA_LADY_DEATHWHISPER, IN_PROGRESS);
            }

            void JustDied(Unit* killer)
            {
                DoScriptText(SAY_DEATH, me);

                instance->SetBossState(DATA_LADY_DEATHWHISPER, DONE);

                std::set<uint32> livingAddEntries;
                // Full House achievement
                for (SummonList::iterator itr = summons.begin(); itr != summons.end(); ++itr)
                    if (Unit* unit = ObjectAccessor::GetUnit(*me, *itr))
                        if (unit->isAlive() && unit->GetEntry() != NPC_VENGEFUL_SHADE)
                            livingAddEntries.insert(unit->GetEntry());

                if (livingAddEntries.size() >= 5)
                {
                    if (Player *player = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
                    {
                        if (Group* group = player->GetGroup())
                        {
                            for (GroupReference *itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
                            {
                                Player* member = itr->getSource();
                                if (!member || !member->IsAtGroupRewardDistance(me))
                                    continue;

                                if (member->isAlive()|| !member->GetCorpse())
                                    member->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_FULL_HOUSE, 0, me);
                            }
                        }
                        else
                            player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_FULL_HOUSE, 0, me);
                    }
                }

                summons.DespawnAll();
            }

            void JustReachedHome()
            {
                instance->SetBossState(DATA_LADY_DEATHWHISPER, FAIL);

                summons.DespawnAll();
            }

            void KilledUnit(Unit *victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2), me);
            }

            void DamageTaken(Unit* /*damageDealer*/, uint32& uiDamage)
            {
                // phase transition
                if (events.GetPhaseMask() & PHASE_ONE_MASK && uiDamage > me->GetPower(POWER_MANA))
                {
                    DoScriptText(SAY_PHASE_2, me);
                    DoScriptText(SAY_PHASE_2_EMOTE, me);
                    DoStartMovement(me->getVictim());
                    me->SetPower(POWER_MANA, 0);
                    uiDamage -= me->GetPower(POWER_MANA);
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
                summons.push_back(summon->GetGUID());
                Unit* target = NULL;
                if (summon->GetEntry() == NPC_VENGEFUL_SHADE)
                {
                    target = ObjectAccessor::GetUnit(*me, uiNextVengefulShadeTarget);   // Vengeful Shade
                    uiNextVengefulShadeTarget = 0;
                }
                else
                    target = SelectTarget(SELECT_TARGET_RANDOM);                        // Wave adds

                summon->AI()->AttackStart(target);                                      // CAN be NULL
                if (summon->GetEntry() == NPC_REANIMATED_FANATIC)
                    summon->AI()->DoCast(summon, SPELL_FANATIC_S_DETERMINATION);
                else if (summon->GetEntry() == NPC_REANIMATED_ADHERENT)
                    summon->AI()->DoCast(summon, SPELL_ADHERENT_S_DETERMINATION);
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                summons.remove(summon->GetGUID());
            }

            void UpdateAI(const uint32 diff)
            {
                if ((!UpdateVictim() && !(events.GetPhaseMask() & PHASE_INTRO_MASK)) || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->hasUnitState(UNIT_STAT_CASTING) && !(events.GetPhaseMask() & PHASE_INTRO_MASK))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INTRO_2:
                            DoScriptText(SAY_INTRO_2, me);
                            break;
                        case EVENT_INTRO_3:
                            DoScriptText(SAY_INTRO_3, me);
                            break;
                        case EVENT_INTRO_4:
                            DoScriptText(SAY_INTRO_4, me);
                            break;
                        case EVENT_INTRO_5:
                            DoScriptText(SAY_INTRO_5, me);
                            break;
                        case EVENT_INTRO_6:
                            DoScriptText(SAY_INTRO_6, me);
                            break;
                        case EVENT_INTRO_7:
                            DoScriptText(SAY_INTRO_7, me);
                            break;
                        case EVENT_INTRO_FINISH:
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            break;
                        case EVENT_DEATH_AND_DECAY:
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(pTarget, SPELL_DEATH_AND_DECAY);
                            events.ScheduleEvent(EVENT_DEATH_AND_DECAY, urand(10000, 12000));
                            break;
                        case EVENT_DOMINATE_MIND_H:
                            DoScriptText(SAY_DOMINATE_MIND, me);
                            for (uint8 i = 0; i < uiDominateMindCount; i++)
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_DOMINATE_MIND_H))
                                    DoCast(target, SPELL_DOMINATE_MIND_H);
                            events.ScheduleEvent(EVENT_DOMINATE_MIND_H, urand(18000, 22000));
                            break;
                        case EVENT_P1_SUMMON_WAVE:
                            SummonWaveP1();
                            events.ScheduleEvent(EVENT_P1_SUMMON_WAVE, 60000, 0, PHASE_ONE);
                            break;
                        case EVENT_P1_SHADOW_BOLT:
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(pTarget, SPELL_SHADOW_BOLT);
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
                            if (Unit* pShadeTarget = SelectUnit(SELECT_TARGET_RANDOM, 1))
                            {
                                uiNextVengefulShadeTarget = pShadeTarget->GetGUID();
                                DoCast(pShadeTarget, SPELL_SUMMON_SHADE);
                            }
                            events.ScheduleEvent(EVENT_P2_SUMMON_SHADE, urand(18000, 23000), 0, PHASE_TWO);
                            break;
                        case EVENT_P2_SUMMON_WAVE:
                            SummonWaveP2();
                            events.ScheduleEvent(EVENT_P2_SUMMON_WAVE, 60000, 0, PHASE_TWO);
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            DoScriptText(SAY_BERSERK, me);
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
                uint8 addIndex = uiAddWaveCounter & 1;
                uint8 addIndexOther = addIndex ^ 1;
                _SummonAdd(uiAddEntries[addIndex], addSpawnPos[addIndex*3]);
                _SummonAdd(uiAddEntries[addIndexOther], addSpawnPos[addIndex*3+1]);
                _SummonAdd(uiAddEntries[addIndex], addSpawnPos[addIndex*3+2]);
                if (getDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL || getDifficulty() == RAID_DIFFICULTY_25MAN_HEROIC)
                {
                    _SummonAdd(uiAddEntries[addIndexOther], addSpawnPos[addIndexOther*3]);
                    _SummonAdd(uiAddEntries[addIndex], addSpawnPos[addIndexOther*3+1]);
                    _SummonAdd(uiAddEntries[addIndexOther], addSpawnPos[addIndexOther*3+2]);
                    _SummonAdd(uiAddEntries[urand(0,1)], addSpawnPos[6]);
                }
                ++uiAddWaveCounter;
            }

            // summoning function for second phase
            void SummonWaveP2()
            {
                if (getDifficulty() == RAID_DIFFICULTY_25MAN_HEROIC)
                {
                    uint8 addIndex = uiAddWaveCounter & 1;
                    _SummonAdd(uiAddEntries[addIndex], addSpawnPos[addIndex*3]);
                    _SummonAdd(uiAddEntries[addIndex ^ 1], addSpawnPos[addIndex*3+1]);
                    _SummonAdd(uiAddEntries[addIndex], addSpawnPos[addIndex*3+2]);
                }
                else
                    _SummonAdd(uiAddEntries[urand(0,1)], addSpawnPos[6]);
                ++uiAddWaveCounter;
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

                DoScriptText(SAY_ANIMATE_DEAD, me);
                DoCast(cultist, SPELL_DARK_MARTYRDOM_T);
            }

            void SpellHitTarget(Unit * target, const SpellEntry * spell)
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
                DoScriptText(cultist->GetEntry() == NPC_CULT_FANATIC ? SAY_DARK_TRANSFORMATION : SAY_DARK_EMPOWERMENT, me);
            }

        private:
            bool bIntroDone;
            uint32 uiAddWaveCounter;
            uint64 uiNextVengefulShadeTarget;
            std::deque<uint64> reanimationQueue;
            uint8 uiDominateMindCount;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_lady_deathwhisperAI(pCreature);
        }
};

class npc_cult_fanatic : public CreatureScript
{
    public:
        npc_cult_fanatic() : CreatureScript("npc_cult_fanatic") { }

        struct npc_cult_fanaticAI : public ScriptedAI
        {
            npc_cult_fanaticAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_FANATIC_NECROTIC_STRIKE, urand(10000, 12000));
                events.ScheduleEvent(EVENT_FANATIC_SHADOW_CLEAVE, urand(14000, 16000));
                events.ScheduleEvent(EVENT_FANATIC_VAMPIRIC_MIGHT, urand(20000, 27000));
                if (me->GetEntry() == NPC_CULT_FANATIC)
                    events.ScheduleEvent(EVENT_CULTIST_DARK_MARTYRDOM, urand(18000, 32000));
            }

            void SpellHit(Unit* /*caster*/, const SpellEntry * spell)
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

                if (me->hasUnitState(UNIT_STAT_CASTING))
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

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_cult_fanaticAI(pCreature);
        }
};

class npc_cult_adherent : public CreatureScript
{
    public:
        npc_cult_adherent() : CreatureScript("npc_cult_adherent") { }

        struct npc_cult_adherentAI : public ScriptedAI
        {
            npc_cult_adherentAI(Creature* pCreature) : ScriptedAI(pCreature) {}

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

            void SpellHit(Unit* /*caster*/, const SpellEntry * spell)
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

                if (me->hasUnitState(UNIT_STAT_CASTING))
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
                            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1))
                                DoCast(pTarget, SPELL_CURSE_OF_TORPOR);
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
            npc_vengeful_shadeAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            void Reset()
            {
                me->AddAura(SPELL_VENGEFUL_BLAST_PASSIVE, me);
            }

            void SpellHitTarget(Unit * /*pTarget*/, const SpellEntry * spell)
            {
                if (spell->Id == SPELL_VENGEFUL_BLAST)
                    me->Kill(me);
            }
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_vengeful_shadeAI(pCreature);
        }
};

class spell_deathwhisper_mana_barrier : public SpellScriptLoader
{
    public:
        spell_deathwhisper_mana_barrier() : SpellScriptLoader("spell_deathwhisper_mana_barrier") { }

        class spell_deathwhisper_mana_barrier_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_deathwhisper_mana_barrier_AuraScript)
            void HandlePeriodicTick(AuraEffect const * /*aurEff*/, AuraApplication const * /*aurApp*/)
            {
                Unit* caster = GetCaster();
                int32 missingHealth = caster->GetMaxHealth() - caster->GetHealth();
                caster->ModifyHealth(missingHealth);
                caster->ModifyPower(POWER_MANA, -missingHealth);
                PreventDefaultAction();
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
            PrepareSpellScript(spell_cultist_dark_martyrdom_SpellScript)
            bool Validate(SpellEntry const* /*spellEntry*/)
            {
                if (uint32 scriptId = sObjectMgr.GetScriptId("boss_lady_deathwhisper"))
                    if (CreatureInfo const* creInfo = ObjectMgr::GetCreatureTemplate(NPC_LADY_DEATHWHISPER))
                        if (creInfo->ScriptID == scriptId)
                            return true;

                return false;
            }

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                if (GetCaster()->isSummon())
                    if (Unit* owner = GetCaster()->ToTempSummon()->GetSummoner())
                        if (owner->GetEntry() == NPC_LADY_DEATHWHISPER)
                            CAST_AI(boss_lady_deathwhisper::boss_lady_deathwhisperAI, owner->ToCreature()->AI())->AddToReanimationQueue(GetCaster());

                GetCaster()->Kill(GetCaster());
                GetCaster()->SetDisplayId(GetCaster()->GetEntry() == NPC_CULT_FANATIC ? 38009 : 38010);
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
    new spell_deathwhisper_mana_barrier();
    new spell_cultist_dark_martyrdom();
}
