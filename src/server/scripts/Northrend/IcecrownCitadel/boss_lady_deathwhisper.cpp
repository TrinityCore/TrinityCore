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
#include "Group.h"
#include "icecrown_citadel.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "QuestPools.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

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
    SPELL_MANA_BARRIER                = 70842,
    SPELL_SHADOW_BOLT                 = 71254,
    SPELL_DEATH_AND_DECAY             = 71001,
    SPELL_DOMINATE_MIND               = 71289,
    SPELL_DOMINATE_MIND_SCALE         = 71290,
    SPELL_FROSTBOLT                   = 71420,
    SPELL_FROSTBOLT_VOLLEY            = 72905,
    SPELL_TOUCH_OF_INSIGNIFICANCE     = 71204,
    SPELL_SUMMON_SHADE                = 71363,
    SPELL_SHADOW_CHANNELING           = 43897,
    SPELL_DARK_TRANSFORMATION_T       = 70895,
    SPELL_DARK_EMPOWERMENT_T          = 70896,
    SPELL_DARK_MARTYRDOM_T            = 70897,
    SPELL_SUMMON_SPIRITS              = 72478,

    // Achievement
    SPELL_FULL_HOUSE                  = 72827, // does not exist in dbc but still can be used for criteria check

    // Both Adds
    SPELL_TELEPORT_VISUAL             = 41236,
    SPELL_CLEAR_ALL_DEBUFFS           = 34098,
    SPELL_FULL_HEAL                   = 17683,
    SPELL_PERMANENT_FEIGN_DEATH       = 70628,

    // Fanatics
    SPELL_DARK_TRANSFORMATION         = 70900,
    SPELL_NECROTIC_STRIKE             = 70659,
    SPELL_SHADOW_CLEAVE               = 70670,
    SPELL_VAMPIRIC_MIGHT              = 70674,
    SPELL_VAMPIRIC_MIGHT_PROC         = 70677,
    SPELL_FANATIC_S_DETERMINATION     = 71235,
    SPELL_DARK_MARTYRDOM_FANATIC      = 71236,
    SPELL_DARK_MARTYRDOM_FANATIC_25N  = 72495,
    SPELL_DARK_MARTYRDOM_FANATIC_10H  = 72496,
    SPELL_DARK_MARTYRDOM_FANATIC_25H  = 72497,

    //  Adherents
    SPELL_DARK_EMPOWERMENT            = 70901,
    SPELL_FROST_FEVER                 = 67767,
    SPELL_DEATHCHILL_BOLT             = 70594,
    SPELL_DEATHCHILL_BLAST            = 70906,
    SPELL_CURSE_OF_TORPOR             = 71237,
    SPELL_SHROUD_OF_THE_OCCULT        = 70768,
    SPELL_ADHERENT_S_DETERMINATION    = 71234,
    SPELL_DARK_MARTYRDOM_ADHERENT     = 70903,
    SPELL_DARK_MARTYRDOM_ADHERENT_25N = 72498,
    SPELL_DARK_MARTYRDOM_ADHERENT_10H = 72499,
    SPELL_DARK_MARTYRDOM_ADHERENT_25H = 72500,

    // Vengeful Shade
    SPELL_VENGEFUL_BLAST              = 71544,
    SPELL_VENGEFUL_BLAST_PASSIVE      = 71494,
    SPELL_VENGEFUL_BLAST_25N          = 72010,
    SPELL_VENGEFUL_BLAST_10H          = 72011,
    SPELL_VENGEFUL_BLAST_25H          = 72012,

    // Darnavan
    SPELL_BLADESTORM                  = 65947,
    SPELL_CHARGE                      = 65927,
    SPELL_INTIMIDATING_SHOUT          = 65930,
    SPELL_MORTAL_STRIKE               = 65926,
    SPELL_SHATTERING_THROW            = 65940,
    SPELL_SUNDER_ARMOR                = 65936,
};

enum EventTypes
{
    // Darnavan
    EVENT_DARNAVAN_BLADESTORM           = 27,
    EVENT_DARNAVAN_CHARGE               = 28,
    EVENT_DARNAVAN_INTIMIDATING_SHOUT   = 29,
    EVENT_DARNAVAN_MORTAL_STRIKE        = 30,
    EVENT_DARNAVAN_SHATTERING_THROW     = 31,
    EVENT_DARNAVAN_SUNDER_ARMOR         = 32,
};

enum Phases
{
    PHASE_ALL       = 0,
    PHASE_INTRO     = 1,
    PHASE_ONE       = 2,
    PHASE_TWO       = 3
};

enum Groups
{
    GROUP_INTRO              = 0,
    GROUP_ONE                = 1,
    GROUP_TWO                = 2
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

enum Actions
{
    ACTION_START_INTRO
};

#define NPC_DARNAVAN        RAID_MODE<uint32>(NPC_DARNAVAN_10, NPC_DARNAVAN_25, NPC_DARNAVAN_10, NPC_DARNAVAN_25)
#define NPC_DARNAVAN_CREDIT RAID_MODE<uint32>(NPC_DARNAVAN_CREDIT_10, NPC_DARNAVAN_CREDIT_25, NPC_DARNAVAN_CREDIT_10, NPC_DARNAVAN_CREDIT_25)
#define QUEST_DEPROGRAMMING RAID_MODE<uint32>(QUEST_DEPROGRAMMING_10, QUEST_DEPROGRAMMING_25, QUEST_DEPROGRAMMING_10, QUEST_DEPROGRAMMING_25)

uint32 const SummonEntries[2] = {NPC_CULT_FANATIC, NPC_CULT_ADHERENT};

Position const SummonPositions[7] =
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
        DaranavanMoveEvent(Creature& darnavan) : _darnavan(darnavan) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _darnavan.GetMotionMaster()->MovePoint(POINT_DESPAWN, SummonPositions[6]);
            return true;
        }

    private:
        Creature& _darnavan;
};

struct boss_lady_deathwhisper : public BossAI
{
    boss_lady_deathwhisper(Creature* creature) : BossAI(creature, DATA_LADY_DEATHWHISPER),
        _dominateMindCount(RAID_MODE<uint8>(0, 1, 1, 3))
    {
        Initialize();
    }

    void Initialize()
    {
        _waveCounter = 0;
        _nextVengefulShadeTargetGUID.clear();
        _cultistQueue.clear();
        _darnavanGUID.Clear();
        _phase = PHASE_ALL;
        scheduler.SetValidator([this]
        {
            return !(me->HasUnitState(UNIT_STATE_CASTING) && _phase != PHASE_INTRO);
        });
    }

    void Reset() override
    {
        _Reset();
        Initialize();
        _phase = PHASE_ONE;
        DoCastSelf(SPELL_SHADOW_CHANNELING);
        me->SetPower(POWER_MANA, me->GetMaxPower(POWER_MANA));
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
    }

    void DoAction(int32 action) override
    {
        if (action != ACTION_START_INTRO)
            return;

        Talk(SAY_INTRO_1);
        _phase = PHASE_INTRO;
        scheduler.Schedule(Seconds(10), GROUP_INTRO, [this](TaskContext context)
        {
            switch (context.GetRepeatCounter())
            {
                case 0:
                    Talk(SAY_INTRO_2);
                    context.Repeat(Seconds(21));
                    break;
                case 1:
                    Talk(SAY_INTRO_3);
                    context.Repeat(Seconds(11));
                    break;
                case 2:
                    Talk(SAY_INTRO_4);
                    context.Repeat(Seconds(9));
                    break;
                case 3:
                    Talk(SAY_INTRO_5);
                    context.Repeat(Seconds(21));
                    break;
                case 4:
                    Talk(SAY_INTRO_6);
                    context.Repeat(Seconds(10));
                    break;
                case 5:
                    Talk(SAY_INTRO_7);
                    return;
                default:
                    break;
            }
        });
    }

    void AttackStart(Unit* victim) override
    {
        if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (victim && me->Attack(victim, true) && _phase != PHASE_ONE)
            me->GetMotionMaster()->MoveChase(victim);
    }

    void JustEngagedWith(Unit* who) override
    {
        if (!instance->CheckRequiredBosses(DATA_LADY_DEATHWHISPER, who->ToPlayer()))
        {
            EnterEvadeMode(EVADE_REASON_SEQUENCE_BREAK);
            instance->DoCastSpellOnPlayers(LIGHT_S_HAMMER_TELEPORT);
            return;
        }

        _phase = PHASE_ONE;
        me->SetCombatPulseDelay(5);
        me->setActive(true);
        DoZoneInCombat();
        scheduler.CancelGroup(GROUP_INTRO);
        // phase-independent events
        scheduler
            .Schedule(Minutes(10), [this](TaskContext /*context*/)
            {
                DoCastSelf(SPELL_BERSERK);
                Talk(SAY_BERSERK);
            })
            .Schedule(Seconds(17), [this](TaskContext death_and_decay)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random))
                    DoCast(target, SPELL_DEATH_AND_DECAY);
                death_and_decay.Repeat(Seconds(22), Seconds(30));
            });
            if (GetDifficulty() != RAID_DIFFICULTY_10MAN_NORMAL)
                scheduler.Schedule(Seconds(27), [this](TaskContext dominate_mind)
                {
                    Talk(SAY_DOMINATE_MIND);
                    std::list<Unit*> targets;
                    SelectTargetList(targets, _dominateMindCount, SelectTargetMethod::Random, 0, 0.0f, true, false, -SPELL_DOMINATE_MIND);
                    for (Unit* target : targets)
                      DoCast(target, SPELL_DOMINATE_MIND);
                    dominate_mind.Repeat(Seconds(40), Seconds(45));
                });
        // phase one only
        scheduler
            .Schedule(Seconds(5), GROUP_ONE, [this](TaskContext wave)
            {
                SummonWaveP1();
                wave.Repeat(Seconds(IsHeroic() ? 45 : 60));
            })
            .Schedule(Seconds(2), GROUP_ONE, [this](TaskContext shadow_bolt)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random))
                    DoCast(target, SPELL_SHADOW_BOLT);
                shadow_bolt.Repeat(Milliseconds(2450), Milliseconds(3600));
            })
            .Schedule(Seconds(15), GROUP_ONE, [this](TaskContext context)
            {
                DoImproveCultist();
                context.Repeat(Seconds(25));
            });

        Talk(SAY_AGGRO);
        DoStartNoMovement(who);
        me->RemoveAurasDueToSpell(SPELL_SHADOW_CHANNELING);
        DoCastSelf(SPELL_MANA_BARRIER, true);
        instance->SetBossState(DATA_LADY_DEATHWHISPER, IN_PROGRESS);
    }

    void JustDied(Unit* killer) override
    {
        Talk(SAY_DEATH);

        std::set<uint32> livingAddEntries;
        // Full House achievement
        for (SummonList::iterator itr = summons.begin(); itr != summons.end(); ++itr)
            if (Unit* unit = ObjectAccessor::GetUnit(*me, *itr))
                if (unit->IsAlive() && unit->GetEntry() != NPC_VENGEFUL_SHADE)
                    livingAddEntries.insert(unit->GetEntry());

        if (livingAddEntries.size() >= 5)
            instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_FULL_HOUSE, 0, me);

        if (Creature* darnavan = ObjectAccessor::GetCreature(*me, _darnavanGUID))
        {
            if (darnavan->IsAlive())
            {
                darnavan->SetFaction(FACTION_FRIENDLY);
                darnavan->CombatStop(true);
                darnavan->GetMotionMaster()->MoveIdle();
                darnavan->SetReactState(REACT_PASSIVE);
                darnavan->m_Events.AddEvent(new DaranavanMoveEvent(*darnavan), darnavan->m_Events.CalculateTime(10s));
                darnavan->AI()->Talk(SAY_DARNAVAN_RESCUED);

                if (!killer)
                    return;

                if (Player* owner = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
                {
                    if (Group* group = owner->GetGroup())
                    {
                        for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                            if (Player* member = itr->GetSource())
                                if (member->IsInMap(owner))
                                    member->KilledMonsterCredit(NPC_DARNAVAN_CREDIT);
                    }
                    else
                        owner->KilledMonsterCredit(NPC_DARNAVAN_CREDIT);
                }
            }
        }

        _JustDied();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        scheduler.CancelAll();
        summons.DespawnAll();
        if (Creature* darnavan = ObjectAccessor::GetCreature(*me, _darnavanGUID))
            darnavan->DespawnOrUnsummon();

        _DespawnAtEvade();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL);
    }

    void DamageTaken(Unit* /*damageDealer*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        // phase transition
        if (_phase == PHASE_ONE && damage > me->GetPower(POWER_MANA))
        {
            _phase = PHASE_TWO;
            Talk(SAY_PHASE_2);
            Talk(EMOTE_PHASE_2);
            DoStartMovement(me->GetVictim());
            ResetThreatList();
            damage -= me->GetPower(POWER_MANA);
            me->SetPower(POWER_MANA, 0);
            me->RemoveAurasDueToSpell(SPELL_MANA_BARRIER);
            scheduler.CancelGroup(GROUP_ONE);

            scheduler
                .Schedule(Seconds(12), GROUP_TWO, [this](TaskContext frostbolt)
                {
                    DoCastVictim(SPELL_FROSTBOLT);
                    frostbolt.Repeat();
                })
                .Schedule(Seconds(20), GROUP_TWO, [this](TaskContext frostboldVolley)
                {
                    DoCastAOE(SPELL_FROSTBOLT_VOLLEY);
                    frostboldVolley.Repeat();
                })
                .Schedule(Seconds(6), Seconds(9), GROUP_TWO, [this](TaskContext touch)
                {
                    if (me->GetVictim())
                        me->AddAura(SPELL_TOUCH_OF_INSIGNIFICANCE, me->EnsureVictim());
                    touch.Repeat();
                })
                .Schedule(Seconds(12), GROUP_TWO, [this](TaskContext summonShade)
                {
                    CastSpellExtraArgs args;
                    args.AddSpellMod(SPELLVALUE_MAX_TARGETS, Is25ManRaid() ? 2 : 1);
                    me->CastSpell(nullptr, SPELL_SUMMON_SPIRITS, args);
                    summonShade.Repeat();
                });

            // on heroic mode Lady Deathwhisper is immune to taunt effects in phase 2 and continues summoning adds
            if (IsHeroic())
            {
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                scheduler.Schedule(Seconds(), GROUP_TWO, [this](TaskContext context)
                {
                    SummonWaveP2();
                    context.Repeat(Seconds(45));
                });
            }
        }
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_SUMMON_SPIRITS)
            _nextVengefulShadeTargetGUID.push_back(target->GetGUID());
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_DARNAVAN_10:
            case NPC_DARNAVAN_25:
                _darnavanGUID = summon->GetGUID();
                summon->AI()->AttackStart(SelectTarget(SelectTargetMethod::Random));
                return;
            case NPC_VENGEFUL_SHADE:
                if (_nextVengefulShadeTargetGUID.empty())
                    break;
                summon->AI()->SetGUID(_nextVengefulShadeTargetGUID.front());
                _nextVengefulShadeTargetGUID.pop_front();
                break;
            case NPC_CULT_ADHERENT:
            case NPC_CULT_FANATIC:
                _cultistQueue.push_back(summon->GetGUID());
                summon->AI()->AttackStart(SelectTarget(SelectTargetMethod::Random));
                break;
            default:
                break;
        }
        summons.Summon(summon);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && _phase != PHASE_INTRO)
            return;

        scheduler.Update(diff, [this]
        {
            // We should not melee attack when barrier is up
            if (!me->HasAura(SPELL_MANA_BARRIER))
                DoMeleeAttackIfReady();
        });
    }

    // summoning function for first phase
    void SummonWaveP1()
    {
        uint8 addIndex = _waveCounter & 1;
        uint8 addIndexOther = uint8(addIndex ^ 1);

        // Summon first add, replace it with Darnavan if weekly quest is active
        if (_waveCounter || !sQuestPoolMgr->IsQuestActive(QUEST_DEPROGRAMMING))
            Summon(SummonEntries[addIndex], SummonPositions[addIndex * 3]);
        else
            Summon(NPC_DARNAVAN, SummonPositions[addIndex * 3]);

        Summon(SummonEntries[addIndexOther], SummonPositions[addIndex * 3 + 1]);
        Summon(SummonEntries[addIndex], SummonPositions[addIndex * 3 + 2]);
        if (Is25ManRaid())
        {
            Summon(SummonEntries[addIndexOther], SummonPositions[addIndexOther * 3]);
            Summon(SummonEntries[addIndex], SummonPositions[addIndexOther * 3 + 1]);
            Summon(SummonEntries[addIndexOther], SummonPositions[addIndexOther * 3 + 2]);
            Summon(SummonEntries[urand(0, 1)], SummonPositions[6]);
        }

        ++_waveCounter;
    }

    // summoning function for second phase
    void SummonWaveP2()
    {
        if (Is25ManRaid())
        {
            uint8 addIndex = _waveCounter & 1;
            Summon(SummonEntries[addIndex], SummonPositions[addIndex * 3]);
            Summon(SummonEntries[addIndex ^ 1], SummonPositions[addIndex * 3 + 1]);
            Summon(SummonEntries[addIndex], SummonPositions[addIndex * 3+ 2]);
        }
        else
            Summon(SummonEntries[urand(0, 1)], SummonPositions[6]);

        ++_waveCounter;
    }

    // helper for summoning wave mobs
    void Summon(uint32 entry, Position const& pos)
    {
        if (TempSummon* summon = me->SummonCreature(entry, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10s))
            summon->CastSpell(summon, SPELL_TELEPORT_VISUAL);
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        if (summon->GetEntry() == NPC_CULT_ADHERENT || summon->GetEntry() == NPC_CULT_FANATIC)
            _cultistQueue.remove(summon->GetGUID());
    }

    void DoImproveCultist()
    {
        if (_cultistQueue.empty())
            return;

        _cultistGUID = Trinity::Containers::SelectRandomContainerElement(_cultistQueue);
        _cultistQueue.remove(_cultistGUID);
        Creature* cultist = ObjectAccessor::GetCreature(*me, _cultistGUID);
        if (!cultist)
            return;

        if (RAND(0,1))
            me->CastSpell(cultist, SPELL_DARK_MARTYRDOM_T);
        else
        {
            me->CastSpell(cultist, cultist->GetEntry() == NPC_CULT_FANATIC ? SPELL_DARK_TRANSFORMATION_T : SPELL_DARK_EMPOWERMENT_T, true);
            Talk(uint8(cultist->GetEntry() == NPC_CULT_FANATIC ? SAY_DARK_TRANSFORMATION : SAY_DARK_EMPOWERMENT));
        }
    }

private:
    ObjectGuid _darnavanGUID;
    ObjectGuid _cultistGUID;
    GuidList _cultistQueue;
    GuidList _nextVengefulShadeTargetGUID;
    uint32 _waveCounter;
    uint8 const _dominateMindCount;
    uint8 _phase;
};

struct npc_cult_fanatic : public ScriptedAI
{
    npc_cult_fanatic(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _scheduler.CancelAll();
        _scheduler
            .SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            })
            .Schedule(Seconds(17), [this](TaskContext vampiric_might)
            {
                DoCastSelf(SPELL_VAMPIRIC_MIGHT);
                vampiric_might.Repeat(Seconds(25));
            })
            .Schedule(Seconds(12), [this](TaskContext shadow_cleave)
            {
                DoCastVictim(SPELL_SHADOW_CLEAVE);
                shadow_cleave.Repeat(Seconds(14));
            })
            .Schedule(Seconds(10), [this](TaskContext necrotic_strike)
            {
                DoCastVictim(SPELL_NECROTIC_STRIKE);
                necrotic_strike.Repeat(Seconds(17));
            });
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_DARK_TRANSFORMATION_T:
                me->InterruptNonMeleeSpells(true);
                DoCastSelf(SPELL_DARK_TRANSFORMATION);
                break;
            case SPELL_DARK_TRANSFORMATION:
                DoCastSelf(SPELL_FULL_HEAL);
                me->UpdateEntry(NPC_DEFORMED_FANATIC);
                break;
            case SPELL_DARK_MARTYRDOM_T:
                me->SetReactState(REACT_PASSIVE);
                me->InterruptNonMeleeSpells(true);
                me->AttackStop();
                DoCastSelf(SPELL_DARK_MARTYRDOM_FANATIC);
                break;
            case SPELL_DARK_MARTYRDOM_FANATIC:
            case SPELL_DARK_MARTYRDOM_FANATIC_25N:
            case SPELL_DARK_MARTYRDOM_FANATIC_10H:
            case SPELL_DARK_MARTYRDOM_FANATIC_25H:
                _scheduler
                    .Schedule(Seconds(2), [this](TaskContext /*context*/)
                    {
                        me->UpdateEntry(NPC_REANIMATED_FANATIC);
                        DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH);
                        DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS);
                        DoCastSelf(SPELL_FULL_HEAL, true);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                    })
                    .Schedule(Seconds(6), [this](TaskContext /*context*/)
                    {
                        me->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                        me->SetReactState(REACT_AGGRESSIVE);
                        DoZoneInCombat(me);

                        if (Creature* ladyDeathwhisper = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_LADY_DEATHWHISPER)))
                            ladyDeathwhisper->AI()->Talk(SAY_ANIMATE_DEAD);
                    });
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !me->HasAura(SPELL_PERMANENT_FEIGN_DEATH))
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

protected:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

struct npc_cult_adherent : public ScriptedAI
{
    npc_cult_adherent(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
       _scheduler.CancelAll();
       _scheduler
           .SetValidator([this]
           {
               return !me->HasUnitState(UNIT_STATE_CASTING);
           })
           .Schedule(Seconds(5), [this](TaskContext deathchill)
           {
               if (me->GetEntry() == NPC_EMPOWERED_ADHERENT)
                   DoCastVictim(SPELL_DEATHCHILL_BLAST);
               else
                   DoCastVictim(SPELL_DEATHCHILL_BOLT);
               deathchill.Repeat(Milliseconds(2500));
           })
           .Schedule(Seconds(15), [this](TaskContext shroud_of_the_occult)
           {
               DoCastSelf(SPELL_SHROUD_OF_THE_OCCULT);
               shroud_of_the_occult.Repeat(Seconds(10));
           })
           .Schedule(Seconds(15), [this](TaskContext curse_of_torpor)
           {
               if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1))
                   DoCast(target, SPELL_CURSE_OF_TORPOR);
               curse_of_torpor.Repeat(Seconds(18));
           });
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_DARK_EMPOWERMENT_T:
                me->UpdateEntry(NPC_EMPOWERED_ADHERENT);
                break;
            case SPELL_DARK_MARTYRDOM_T:
                me->SetReactState(REACT_PASSIVE);
                me->InterruptNonMeleeSpells(true);
                me->AttackStop();
                DoCastSelf(SPELL_DARK_MARTYRDOM_ADHERENT);
                break;
            case SPELL_DARK_MARTYRDOM_ADHERENT:
            case SPELL_DARK_MARTYRDOM_ADHERENT_25N:
            case SPELL_DARK_MARTYRDOM_ADHERENT_10H:
            case SPELL_DARK_MARTYRDOM_ADHERENT_25H:
                _scheduler
                    .Schedule(Seconds(2), [this](TaskContext /*context*/)
                    {
                        me->UpdateEntry(NPC_REANIMATED_ADHERENT);
                        DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH);
                        DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS);
                        DoCastSelf(SPELL_FULL_HEAL, true);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                    })
                    .Schedule(Seconds(6), [this](TaskContext /*context*/)
                    {
                        me->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                        me->SetReactState(REACT_AGGRESSIVE);
                        DoCastSelf(SPELL_SHROUD_OF_THE_OCCULT);
                        DoZoneInCombat(me);

                        if (Creature* ladyDeathwhisper = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_LADY_DEATHWHISPER)))
                            ladyDeathwhisper->AI()->Talk(SAY_ANIMATE_DEAD);
                    });
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !me->HasAura(SPELL_PERMANENT_FEIGN_DEATH))
            return;

        _scheduler.Update(diff);
    }

protected:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

struct npc_vengeful_shade : public ScriptedAI
{
    npc_vengeful_shade(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->AddAura(SPELL_VENGEFUL_BLAST_PASSIVE, me);

        _scheduler
            .Schedule(Seconds(2), [this](TaskContext /*context*/)
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->AI()->AttackStart(ObjectAccessor::GetUnit(*me, _targetGUID));
            })
            .Schedule(Seconds(7), [this](TaskContext /*context*/)
            {
                me->KillSelf();
            });
    }

    void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
    {
        _targetGUID = guid;
    }

    void SpellHitTarget(WorldObject* /*target*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_VENGEFUL_BLAST:
            case SPELL_VENGEFUL_BLAST_25N:
            case SPELL_VENGEFUL_BLAST_10H:
            case SPELL_VENGEFUL_BLAST_25H:
                me->KillSelf();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    TaskScheduler _scheduler;
    ObjectGuid _targetGUID;
};

struct npc_darnavan : public ScriptedAI
{
    npc_darnavan(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _canCharge = true;
        _canShatter = true;
    }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_DARNAVAN_BLADESTORM, 10s);
        _events.ScheduleEvent(EVENT_DARNAVAN_INTIMIDATING_SHOUT, 20s, 25s);
        _events.ScheduleEvent(EVENT_DARNAVAN_MORTAL_STRIKE, 25s, 30s);
        _events.ScheduleEvent(EVENT_DARNAVAN_SUNDER_ARMOR, 5s, 8s);
        Initialize();
    }

    void JustDied(Unit* killer) override
    {
        _events.Reset();

        if (!killer)
            return;

        if (Player* owner = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
        {
            if (Group* group = owner->GetGroup())
            {
                for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                    if (Player* member = itr->GetSource())
                        if (member->IsInMap(owner))
                            member->FailQuest(QUEST_DEPROGRAMMING);
            }
            else
                owner->FailQuest(QUEST_DEPROGRAMMING);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE || id != POINT_DESPAWN)
            return;

        me->DespawnOrUnsummon();
    }

    void JustEngagedWith(Unit* /*victim*/) override
    {
        Talk(SAY_DARNAVAN_AGGRO);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (_canShatter && me->GetVictim() && me->EnsureVictim()->IsImmunedToDamage(SPELL_SCHOOL_MASK_NORMAL))
        {
            DoCastVictim(SPELL_SHATTERING_THROW);
            _canShatter = false;
            _events.ScheduleEvent(EVENT_DARNAVAN_SHATTERING_THROW, 30s);
            return;
        }

        if (_canCharge && !me->IsWithinMeleeRange(me->GetVictim()))
        {
            DoCastVictim(SPELL_CHARGE);
            _canCharge = false;
            _events.ScheduleEvent(EVENT_DARNAVAN_CHARGE, 20s);
            return;
        }

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DARNAVAN_BLADESTORM:
                    DoCast(SPELL_BLADESTORM);
                    _events.ScheduleEvent(EVENT_DARNAVAN_BLADESTORM, 90s, 100s);
                    break;
                case EVENT_DARNAVAN_CHARGE:
                    _canCharge = true;
                    break;
                case EVENT_DARNAVAN_INTIMIDATING_SHOUT:
                    DoCast(SPELL_INTIMIDATING_SHOUT);
                    _events.ScheduleEvent(EVENT_DARNAVAN_INTIMIDATING_SHOUT, Seconds(90), Minutes(2));
                    break;
                case EVENT_DARNAVAN_MORTAL_STRIKE:
                    DoCastVictim(SPELL_MORTAL_STRIKE);
                    _events.ScheduleEvent(EVENT_DARNAVAN_MORTAL_STRIKE, 15s, 30s);
                    break;
                case EVENT_DARNAVAN_SHATTERING_THROW:
                    _canShatter = true;
                    break;
                case EVENT_DARNAVAN_SUNDER_ARMOR:
                    DoCastVictim(SPELL_SUNDER_ARMOR);
                    _events.ScheduleEvent(EVENT_DARNAVAN_SUNDER_ARMOR, 3s, 7s);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    bool _canCharge;
    bool _canShatter;
};

// 70842 - Mana Barrier
class spell_deathwhisper_mana_barrier : public AuraScript
{
    PrepareAuraScript(spell_deathwhisper_mana_barrier);

    void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
        {
            int32 missingHealth = int32(caster->GetMaxHealth() - caster->GetHealth());
            caster->ModifyHealth(missingHealth);
            caster->ModifyPower(POWER_MANA, -missingHealth);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_deathwhisper_mana_barrier::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 71289 - Dominate Mind
class spell_deathwhisper_dominated_mind : public AuraScript
{
    PrepareAuraScript(spell_deathwhisper_dominated_mind);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DOMINATE_MIND_SCALE });
    }

    void HandleApply(AuraEffect const* /*eff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_DOMINATE_MIND_SCALE, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_deathwhisper_dominated_mind::HandleApply, EFFECT_0, SPELL_AURA_AOE_CHARM, AURA_EFFECT_HANDLE_REAL);
    }
};

// 72478 - Summon Spirits
class spell_deathwhisper_summon_spirits : public SpellScript
{
    PrepareSpellScript(spell_deathwhisper_summon_spirits);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_SHADE });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SUMMON_SHADE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_deathwhisper_summon_spirits::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 70674 - Vampiric Might
class spell_deathwhisper_vampiric_might : public AuraScript
{
    PrepareAuraScript(spell_deathwhisper_vampiric_might);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_VAMPIRIC_MIGHT_PROC });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        Unit* target = GetTarget();
        uint32 damage = damageInfo->GetDamage();
        ApplyPct(damage, aurEff->GetAmount());
        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(damage);
        target->CastSpell(target, SPELL_VAMPIRIC_MIGHT_PROC, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_deathwhisper_vampiric_might::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 69483 - Dark Reckoning
class spell_deathwhisper_dark_reckoning : public AuraScript
{
    PrepareAuraScript(spell_deathwhisper_dark_reckoning);

    bool Validate(SpellInfo const* spell) override
    {
        return ValidateSpellInfo({ spell->GetEffect(EFFECT_0).TriggerSpell });
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
        {
            uint32 spellId = GetSpellInfo()->GetEffect(EFFECT_0).TriggerSpell;
            caster->CastSpell(GetTarget(), spellId, aurEff);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_deathwhisper_dark_reckoning::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class at_lady_deathwhisper_entrance : public OnlyOnceAreaTriggerScript
{
    public:
        at_lady_deathwhisper_entrance() : OnlyOnceAreaTriggerScript("at_lady_deathwhisper_entrance") { }

        bool TryHandleOnce(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetBossState(DATA_LADY_DEATHWHISPER) != DONE)
                    if (Creature* ladyDeathwhisper = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_LADY_DEATHWHISPER)))
                        ladyDeathwhisper->AI()->DoAction(ACTION_START_INTRO);

            return true;
        }
};

void AddSC_boss_lady_deathwhisper()
{
    // Creatures
    RegisterIcecrownCitadelCreatureAI(boss_lady_deathwhisper);
    RegisterIcecrownCitadelCreatureAI(npc_cult_fanatic);
    RegisterIcecrownCitadelCreatureAI(npc_cult_adherent);
    RegisterIcecrownCitadelCreatureAI(npc_vengeful_shade);
    RegisterIcecrownCitadelCreatureAI(npc_darnavan);

    // Spells
    RegisterSpellScript(spell_deathwhisper_mana_barrier);
    RegisterSpellScript(spell_deathwhisper_dominated_mind);
    RegisterSpellScript(spell_deathwhisper_summon_spirits);
    RegisterSpellScript(spell_deathwhisper_vampiric_might);
    RegisterSpellScript(spell_deathwhisper_dark_reckoning);

    // AreaTriggers
    new at_lady_deathwhisper_entrance();
}
