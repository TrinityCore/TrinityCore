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
#include "icecrown_citadel.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuras.h"
#include "SpellScript.h"

enum ScriptTexts
{
    // Deathbringer Saurfang
    SAY_INTRO_ALLIANCE_2            = 0,
    SAY_INTRO_ALLIANCE_3            = 1,
    SAY_INTRO_ALLIANCE_6            = 2,
    SAY_INTRO_ALLIANCE_7            = 3,
    SAY_INTRO_HORDE_2               = 4,
    SAY_INTRO_HORDE_4               = 5,
    SAY_INTRO_HORDE_9               = 6,
    SAY_AGGRO                       = 7,
    SAY_MARK_OF_THE_FALLEN_CHAMPION = 8,
    SAY_BLOOD_BEASTS                = 9,
    SAY_KILL                        = 10,
    SAY_FRENZY                      = 11,
    SAY_BERSERK                     = 12,
    SAY_DEATH                       = 13,
    EMOTE_SCENT_OF_BLOOD            = 14,

    // High Overlord Saurfang
    SAY_INTRO_HORDE_1               = 0,
    SAY_INTRO_HORDE_3               = 1,
    SAY_INTRO_HORDE_5               = 2,
    SAY_INTRO_HORDE_6               = 3,
    SAY_INTRO_HORDE_7               = 4,
    SAY_INTRO_HORDE_8               = 5,
    SAY_OUTRO_ALLIANCE_8            = 6,
    SAY_OUTRO_ALLIANCE_12           = 7, // kneel after WP reached
    SAY_OUTRO_ALLIANCE_13           = 8,
    SAY_OUTRO_ALLIANCE_14           = 9,
    SAY_OUTRO_ALLIANCE_15           = 10,
    SAY_OUTRO_HORDE_1               = 11,
    SAY_OUTRO_HORDE_2               = 12,
    SAY_OUTRO_HORDE_3               = 13,
    SAY_OUTRO_HORDE_4               = 14,

    // Muradin Bronzebeard
    SAY_INTRO_ALLIANCE_1            = 0,
    SAY_INTRO_ALLIANCE_4            = 1,
    SAY_INTRO_ALLIANCE_5            = 2,
    SAY_OUTRO_ALLIANCE_1            = 3, /// @todo ALLIANCE OUTRO
    SAY_OUTRO_ALLIANCE_2            = 4,
    SAY_OUTRO_ALLIANCE_3            = 5,
    SAY_OUTRO_ALLIANCE_4            = 6,
    SAY_OUTRO_ALLIANCE_5            = 7,
    SAY_OUTRO_ALLIANCE_6            = 8,
    SAY_OUTRO_ALLIANCE_7            = 9,
    SAY_OUTRO_ALLIANCE_9            = 10,
    SAY_OUTRO_ALLIANCE_10           = 11,
    SAY_OUTRO_ALLIANCE_21           = 12,

    // Lady Jaina Proudmoore
    SAY_OUTRO_ALLIANCE_17           = 0,
    SAY_OUTRO_ALLIANCE_19           = 1,

    // King Varian Wrynn
    SAY_OUTRO_ALLIANCE_11           = 0,
    SAY_OUTRO_ALLIANCE_16           = 1,
    SAY_OUTRO_ALLIANCE_18           = 2,
    SAY_OUTRO_ALLIANCE_20           = 3,
};

enum Spells
{
    // Deathbringer Saurfang
    SPELL_ZERO_POWER                          = 72242,
    SPELL_GRIP_OF_AGONY                       = 70572, // Intro
    SPELL_BLOOD_LINK                          = 72178,
    SPELL_MARK_OF_THE_FALLEN_CHAMPION_S       = 72256,
    SPELL_RUNE_OF_BLOOD_S                     = 72408,

    SPELL_SUMMON_BLOOD_BEAST                  = 72172,
    SPELL_SUMMON_BLOOD_BEAST_25_MAN           = 72356, // Additional cast, does not replace
    SPELL_FRENZY                              = 72737,
    SPELL_BLOOD_NOVA_TRIGGER                  = 72378,
    SPELL_BLOOD_NOVA                          = 72380,
    SPELL_BLOOD_POWER                         = 72371,
    SPELL_BLOOD_LINK_POWER                    = 72195,
    SPELL_BLOOD_LINK_DUMMY                    = 72202,
    SPELL_MARK_OF_THE_FALLEN_CHAMPION         = 72293,
    SPELL_BOILING_BLOOD                       = 72385,
    SPELL_RUNE_OF_BLOOD                       = 72410,

    // Blood Beast
    SPELL_BLOOD_LINK_BEAST                    = 72176,
    SPELL_RESISTANT_SKIN                      = 72723,
    SPELL_SCENT_OF_BLOOD                      = 72769, // Heroic only

    SPELL_RIDE_VEHICLE                        = 70640, // Outro
    SPELL_ACHIEVEMENT                         = 72928,
    SPELL_REMOVE_MARKS_OF_THE_FALLEN_CHAMPION = 72257,
    SPELL_PERMANENT_FEIGN_DEATH               = 70628
};

// Helper to get id of the aura on different modes (HasAura(baseId) wont work)
#define BOILING_BLOOD_HELPER RAID_MODE<int32>(72385, 72441, 72442, 72443)

enum EventTypes
{
    EVENT_INTRO_ALLIANCE_1      = 1,
    EVENT_INTRO_ALLIANCE_2      = 2,
    EVENT_INTRO_ALLIANCE_3      = 3,
    EVENT_INTRO_ALLIANCE_4      = 4,
    EVENT_INTRO_ALLIANCE_5      = 5,
    EVENT_INTRO_ALLIANCE_6      = 6,
    EVENT_INTRO_ALLIANCE_7      = 7,

    EVENT_INTRO_HORDE_1         = 8,
    EVENT_INTRO_HORDE_2         = 9,
    EVENT_INTRO_HORDE_3         = 10,
    EVENT_INTRO_HORDE_4         = 11,
    EVENT_INTRO_HORDE_5         = 12,
    EVENT_INTRO_HORDE_6         = 13,
    EVENT_INTRO_HORDE_7         = 14,
    EVENT_INTRO_HORDE_8         = 15,
    EVENT_INTRO_HORDE_9         = 16,

    EVENT_INTRO_FINISH          = 17,

    EVENT_BERSERK               = 18,
    EVENT_SUMMON_BLOOD_BEAST    = 19,
    EVENT_BOILING_BLOOD         = 20,
    EVENT_BLOOD_NOVA            = 21,
    EVENT_RUNE_OF_BLOOD         = 22,
    EVENT_SCENT_OF_BLOOD        = 52,

    EVENT_OUTRO_ALLIANCE_1      = 23,
    EVENT_OUTRO_ALLIANCE_2      = 24,
    EVENT_OUTRO_ALLIANCE_3      = 25,
    EVENT_OUTRO_ALLIANCE_4      = 26,
    EVENT_OUTRO_ALLIANCE_5      = 27,
    EVENT_OUTRO_ALLIANCE_6      = 28,
    EVENT_OUTRO_ALLIANCE_7      = 29,
    EVENT_OUTRO_ALLIANCE_8      = 30,
    EVENT_OUTRO_ALLIANCE_9      = 31,
    EVENT_OUTRO_ALLIANCE_10     = 32,
    EVENT_OUTRO_ALLIANCE_11     = 33,
    EVENT_OUTRO_ALLIANCE_12     = 34,
    EVENT_OUTRO_ALLIANCE_13     = 35,
    EVENT_OUTRO_ALLIANCE_14     = 36,
    EVENT_OUTRO_ALLIANCE_15     = 37,
    EVENT_OUTRO_ALLIANCE_16     = 38,
    EVENT_OUTRO_ALLIANCE_17     = 39,
    EVENT_OUTRO_ALLIANCE_18     = 40,
    EVENT_OUTRO_ALLIANCE_19     = 41,
    EVENT_OUTRO_ALLIANCE_20     = 42,
    EVENT_OUTRO_ALLIANCE_21     = 43,

    EVENT_OUTRO_HORDE_1         = 44,
    EVENT_OUTRO_HORDE_2         = 45,
    EVENT_OUTRO_HORDE_3         = 46,
    EVENT_OUTRO_HORDE_4         = 47,
    EVENT_OUTRO_HORDE_5         = 48,
    EVENT_OUTRO_HORDE_6         = 49,
    EVENT_OUTRO_HORDE_7         = 50,
    EVENT_OUTRO_HORDE_8         = 51,
};

enum Phases
{
    PHASE_INTRO_A       = 1,
    PHASE_INTRO_H       = 2,
    PHASE_COMBAT        = 3
};

enum Actions
{
    ACTION_START_EVENT                  = -3781300,
    ACTION_CONTINUE_INTRO               = -3781301,
    ACTION_CHARGE                       = -3781302,
    ACTION_START_OUTRO                  = -3781303,
    ACTION_DESPAWN                      = -3781304,
    ACTION_INTERRUPT_INTRO              = -3781305,
    ACTION_MARK_OF_THE_FALLEN_CHAMPION  = -72293,
};

enum Misc
{
    DATA_MADE_A_MESS                    = 45374613, // 4537, 4613 are achievement IDs

    GOSSIP_MENU_MURADIN_BRONZEBEARD     = 10934,
    GOSSIP_MENU_HIGH_OVERLORD_SAURFANG  = 10952
};

enum MovePoints
{
    POINT_SAURFANG          = 3781300,
    POINT_FIRST_STEP        = 3781301,
    POINT_CHARGE            = 3781302,
    POINT_CHOKE             = 3781303,
    POINT_CORPSE            = 3781304,
    POINT_FINAL             = 3781305,
    POINT_EXIT              = 5,        // waypoint id
};

Position const deathbringerPos = {-496.3542f, 2211.33f, 541.1138f, 0.0f};
Position const firstStepPos = {-541.3177f, 2211.365f, 539.2921f, 0.0f};

Position const chargePos[6] =
{
    {-509.6505f, 2211.377f, 539.2872f, 0.0f}, // High Overlord Saurfang/Muradin Bronzebeard
    {-508.7480f, 2211.897f, 539.2870f, 0.0f}, // front left
    {-509.2929f, 2211.411f, 539.2870f, 0.0f}, // front right
    {-506.6607f, 2211.367f, 539.2870f, 0.0f}, // back middle
    {-506.1137f, 2213.306f, 539.2870f, 0.0f}, // back left
    {-509.0040f, 2211.743f, 539.2870f, 0.0f}  // back right
};

Position const chokePos[6] =
{
    {-514.4834f, 2211.334f, 549.2887f, 0.0f}, // High Overlord Saurfang/Muradin Bronzebeard
    {-510.1081f, 2211.592f, 546.3773f, 0.0f}, // front left
    {-513.3210f, 2211.396f, 551.2882f, 0.0f}, // front right
    {-507.3684f, 2210.353f, 545.7497f, 0.0f}, // back middle
    {-507.0486f, 2212.999f, 545.5512f, 0.0f}, // back left
    {-510.7041f, 2211.069f, 546.5298f, 0.0f}  // back right
};

Position const finalPos = {-563.7552f, 2211.328f, 538.7848f, 0.0f};

struct boss_deathbringer_saurfang : public BossAI
{
    boss_deathbringer_saurfang(Creature* creature) : BossAI(creature, DATA_DEATHBRINGER_SAURFANG), _introDone(false), _frenzied(false), _dead(false)
    {
        ASSERT(creature->GetVehicleKit()); // we dont actually use it, just check if exists
        _fallenChampionCastCount = 0;
    }

    void Reset() override
    {
        if (_dead)
            return;
        _Reset();
        events.SetPhase(PHASE_COMBAT);
        _frenzied = false;
        _dead = false;
        me->SetPower(POWER_ENERGY, 0);
        DoCastSelf(SPELL_ZERO_POWER, true);
        DoCastSelf(SPELL_BLOOD_LINK, true);
        DoCastSelf(SPELL_BLOOD_POWER, true);
        DoCastSelf(SPELL_MARK_OF_THE_FALLEN_CHAMPION_S, true);
        DoCastSelf(SPELL_RUNE_OF_BLOOD_S, true);
        me->RemoveAurasDueToSpell(SPELL_BERSERK);
        me->RemoveAurasDueToSpell(SPELL_FRENZY);
    }

    void JustEngagedWith(Unit* who) override
    {
        if (_dead)
            return;

        if (!instance->CheckRequiredBosses(DATA_DEATHBRINGER_SAURFANG, who->ToPlayer()))
        {
            EnterEvadeMode(EVADE_REASON_OTHER);
            instance->DoCastSpellOnPlayers(LIGHT_S_HAMMER_TELEPORT);
            return;
        }

        // oh just screw intro, enter combat - no exploits please
        me->setActive(true);
        DoZoneInCombat();

        events.Reset();
        events.SetPhase(PHASE_COMBAT);
        me->SetImmuneToPC(false);
        if (!_introDone)
        {
            DoCastSelf(SPELL_GRIP_OF_AGONY);
            if (Creature* creature = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SAURFANG_EVENT_NPC)))
                creature->AI()->DoAction(ACTION_INTERRUPT_INTRO);
        }

        _introDone = true;

        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_SUMMON_BLOOD_BEAST, 30s, 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_BERSERK, IsHeroic() ? 360s : 480s, 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_BOILING_BLOOD, 15500ms, 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_BLOOD_NOVA, 17s, 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_RUNE_OF_BLOOD, 20s, 0, PHASE_COMBAT);

        _fallenChampionCastCount = 0;
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MARK_OF_THE_FALLEN_CHAMPION);
        instance->SetBossState(DATA_DEATHBRINGER_SAURFANG, IN_PROGRESS);
    }

    void JustDied(Unit* /*killer*/) override
    {
    }

    void AttackStart(Unit* victim) override
    {
        if (me->IsImmuneToPC())
            return;

        ScriptedAI::AttackStart(victim);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);
        if (_introDone)
            me->SetImmuneToPC(false);
    }

    void JustReachedHome() override
    {
        if (_dead)
            return;
        _JustReachedHome();
        Reset();
        instance->SetBossState(DATA_DEATHBRINGER_SAURFANG, FAIL);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MARK_OF_THE_FALLEN_CHAMPION);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
            damage = me->GetHealth() - 1;

        if (!_frenzied && HealthBelowPct(31)) // AT 30%, not below
        {
            _frenzied = true;
            DoCastSelf(SPELL_FRENZY, true);
            Talk(SAY_FRENZY);
        }

        if (!_dead && me->GetHealth()-damage < FightWonValue)
        {
            _dead = true;
            _JustDied();
            _EnterEvadeMode();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
            me->SetImmuneToPC(true);
            me->RemoveAurasOnEvade();
            DoCastAOE(SPELL_REMOVE_MARKS_OF_THE_FALLEN_CHAMPION);
            DoCastSelf(SPELL_ACHIEVEMENT, true);
            Talk(SAY_DEATH);
            DoCastSelf(SPELL_REPUTATION_BOSS_KILL, true);
            DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH);
            if (Creature* creature = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SAURFANG_EVENT_NPC)))
                creature->AI()->DoAction(ACTION_START_OUTRO);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true))
        {
            if (target->GetTransport())
            {
                summon->DespawnOrUnsummon(1ms);
                EnterEvadeMode(EVADE_REASON_OTHER);
                return;
            }

            summon->AI()->AttackStart(target);
        }

        summon->CastSpell(summon, SPELL_BLOOD_LINK_BEAST, true);
        summon->CastSpell(summon, SPELL_RESISTANT_SKIN, true);
        summons.Summon(summon);
        DoZoneInCombat(summon);
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        summons.Despawn(summon);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE && id != POINT_SAURFANG)
            return;

        instance->HandleGameObject(instance->GetGuidData(GO_SAURFANG_S_DOOR), false);
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (target->GetTransport())
        {
            EnterEvadeMode(EVADE_REASON_OTHER);
            return;
        }

        switch (spellInfo->Id)
        {
            case SPELL_MARK_OF_THE_FALLEN_CHAMPION:
                Talk(SAY_MARK_OF_THE_FALLEN_CHAMPION);
                break;
            case 72255: // Mark of the Fallen Champion, triggered id
            case 72444:
            case 72445:
            case 72446:
                if (me->GetPower(POWER_ENERGY) != me->GetMaxPower(POWER_ENERGY))
                {
                    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                    args.AddSpellBP0(1);
                    target->CastSpell(nullptr, SPELL_BLOOD_LINK_DUMMY, args);
                }
                break;
            default:
                break;
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_BLOOD_LINK_POWER)
            if (Aura* bloodPower = me->GetAura(SPELL_BLOOD_POWER))
                bloodPower->RecalculateAmountOfEffects();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !(events.IsInPhase(PHASE_INTRO_A) || events.IsInPhase(PHASE_INTRO_H)))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_ALLIANCE_2:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                    me->SetFaction(FACTION_UNDEAD_SCOURGE);
                    Talk(SAY_INTRO_ALLIANCE_2);
                    break;
                case EVENT_INTRO_ALLIANCE_3:
                    Talk(SAY_INTRO_ALLIANCE_3);
                    break;
                case EVENT_INTRO_ALLIANCE_6:
                    Talk(SAY_INTRO_ALLIANCE_6);
                    Talk(SAY_INTRO_ALLIANCE_7);
                    DoCastSelf(SPELL_GRIP_OF_AGONY);
                    break;
                case EVENT_INTRO_HORDE_2:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                    me->SetFaction(FACTION_UNDEAD_SCOURGE);
                    Talk(SAY_INTRO_HORDE_2);
                    break;
                case EVENT_INTRO_HORDE_4:
                    Talk(SAY_INTRO_HORDE_4);
                    break;
                case EVENT_INTRO_HORDE_9:
                    DoCastSelf(SPELL_GRIP_OF_AGONY);
                    Talk(SAY_INTRO_HORDE_9);
                    break;
                case EVENT_INTRO_FINISH:
                    events.SetPhase(PHASE_COMBAT);
                    _introDone = true;
                    me->SetImmuneToPC(false);
                    break;
                case EVENT_SUMMON_BLOOD_BEAST:
                    for (uint32 i10 = 0; i10 < 2; ++i10)
                        DoCastSelf(SPELL_SUMMON_BLOOD_BEAST+i10);
                    if (Is25ManRaid())
                        for (uint32 i25 = 0; i25 < 3; ++i25)
                            DoCastSelf(SPELL_SUMMON_BLOOD_BEAST_25_MAN+i25);
                    Talk(SAY_BLOOD_BEASTS);
                    events.ScheduleEvent(EVENT_SUMMON_BLOOD_BEAST, 40s, 0, PHASE_COMBAT);
                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_SCENT_OF_BLOOD, 10s, 0, PHASE_COMBAT);
                    break;
                case EVENT_BLOOD_NOVA:
                    DoCastAOE(SPELL_BLOOD_NOVA_TRIGGER);
                    events.ScheduleEvent(EVENT_BLOOD_NOVA, 20s, 25s, 0, PHASE_COMBAT);
                    break;
                case EVENT_RUNE_OF_BLOOD:
                    DoCastVictim(SPELL_RUNE_OF_BLOOD);
                    events.ScheduleEvent(EVENT_RUNE_OF_BLOOD, 20s, 25s, 0, PHASE_COMBAT);
                    break;
                case EVENT_BOILING_BLOOD:
                    DoCastSelf(SPELL_BOILING_BLOOD);
                    events.ScheduleEvent(EVENT_BOILING_BLOOD, 15s, 20s, 0, PHASE_COMBAT);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    Talk(SAY_BERSERK);
                    break;
                case EVENT_SCENT_OF_BLOOD:
                    if (!summons.empty())
                    {
                        Talk(EMOTE_SCENT_OF_BLOOD);
                        DoCastAOE(SPELL_SCENT_OF_BLOOD);
                    }
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_MADE_A_MESS)
            if (_fallenChampionCastCount < RAID_MODE<uint32>(3, 5, 3, 5))
                return 1;

        return 0;
    }

    // intro setup
    void DoAction(int32 action) override
    {
        switch (action)
        {
            case PHASE_INTRO_A:
            case PHASE_INTRO_H:
            {
                // controls what events will execute
                events.SetPhase(uint32(action));

                me->SetHomePosition(deathbringerPos.GetPositionX(), deathbringerPos.GetPositionY(), deathbringerPos.GetPositionZ(), me->GetOrientation());
                me->GetMotionMaster()->MovePoint(POINT_SAURFANG, deathbringerPos.GetPositionX(), deathbringerPos.GetPositionY(), deathbringerPos.GetPositionZ());

                events.ScheduleEvent(EVENT_INTRO_ALLIANCE_2, 2500ms, 0, PHASE_INTRO_A);
                events.ScheduleEvent(EVENT_INTRO_ALLIANCE_3, 20s, 0, PHASE_INTRO_A);

                events.ScheduleEvent(EVENT_INTRO_HORDE_2, 5s, 0, PHASE_INTRO_H);
                break;
            }
            case ACTION_CONTINUE_INTRO:
            {
                if (_introDone)
                    return;

                events.ScheduleEvent(EVENT_INTRO_ALLIANCE_6, 7s, 0, PHASE_INTRO_A);
                events.ScheduleEvent(EVENT_INTRO_FINISH, 8s, 0, PHASE_INTRO_A);

                events.ScheduleEvent(EVENT_INTRO_HORDE_4, 6500ms, 0, PHASE_INTRO_H);
                events.ScheduleEvent(EVENT_INTRO_HORDE_9, 48200ms, 0, PHASE_INTRO_H);
                events.ScheduleEvent(EVENT_INTRO_FINISH,  55700ms, 0, PHASE_INTRO_H);
                break;
            }
            case ACTION_MARK_OF_THE_FALLEN_CHAMPION:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true, true, -SPELL_MARK_OF_THE_FALLEN_CHAMPION))
                {
                    ++_fallenChampionCastCount;
                    DoCast(target, SPELL_MARK_OF_THE_FALLEN_CHAMPION);
                    me->SetPower(POWER_ENERGY, 0);
                    if (Aura* bloodPower = me->GetAura(SPELL_BLOOD_POWER))
                        bloodPower->RecalculateAmountOfEffects();
                }
                break;
            }
            default:
                break;
        }
    }

    bool CanAIAttack(Unit const* target) const override
    {
        if (target->GetTransport())
            return false;

        return BossAI::CanAIAttack(target);
    }

    static uint32 const FightWonValue;

private:
    uint32 _fallenChampionCastCount;
    bool _introDone;
    bool _frenzied;   // faster than iterating all auras to find Frenzy
    bool _dead;
};

uint32 const boss_deathbringer_saurfang::FightWonValue = 100000;

struct npc_high_overlord_saurfang_icc : public ScriptedAI
{
    npc_high_overlord_saurfang_icc(Creature* creature) : ScriptedAI(creature)
    {
        ASSERT(creature->GetVehicleKit());
        _instance = me->GetInstanceScript();
    }

    void Reset() override
    {
        _events.Reset();
    }

    bool OnGossipSelect(Player* player, uint32 menuId, uint32 /*gossipListId*/) override
    {
        if (menuId == GOSSIP_MENU_HIGH_OVERLORD_SAURFANG)
        {
            CloseGossipMenuFor(player);
            DoAction(ACTION_START_EVENT);
        }
        return false;
    }

    void GuardBroadcast(std::function<void(Creature*)>&& action) const
    {
        std::vector<Creature*> guardList;
        GetCreatureListWithEntryInGrid(guardList, me, NPC_SE_KOR_KRON_REAVER, 100.0f);
        for (Creature* guard : guardList)
            action(guard);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_EVENT:
            {
                // Prevent crashes
                if (_events.IsInPhase(PHASE_INTRO_A) || _events.IsInPhase(PHASE_INTRO_H))
                    return;

                std::list<Creature*> guardList;
                GetCreatureListWithEntryInGrid(guardList, me, NPC_SE_KOR_KRON_REAVER, 20.0f);
                guardList.sort(Trinity::ObjectDistanceOrderPred(me));
                uint32 x = 1;
                for (auto itr = guardList.begin(); itr != guardList.end(); ++x, ++itr)
                    (*itr)->AI()->SetData(0, x);

                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                Talk(SAY_INTRO_HORDE_1);
                _events.SetPhase(PHASE_INTRO_H);
                _events.ScheduleEvent(EVENT_INTRO_HORDE_3, 18500ms, 0, PHASE_INTRO_H);
                _instance->HandleGameObject(_instance->GetGuidData(GO_SAURFANG_S_DOOR), true);
                if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_DEATHBRINGER_SAURFANG)))
                    deathbringer->AI()->DoAction(PHASE_INTRO_H);
                break;
            }
            case ACTION_START_OUTRO:
            {
                me->RemoveAurasDueToSpell(SPELL_GRIP_OF_AGONY);
                Talk(SAY_OUTRO_HORDE_1);
                _events.ScheduleEvent(EVENT_OUTRO_HORDE_2, 10s);   // say
                _events.ScheduleEvent(EVENT_OUTRO_HORDE_3, 18s);   // say
                _events.ScheduleEvent(EVENT_OUTRO_HORDE_4, 24s);   // cast
                _events.ScheduleEvent(EVENT_OUTRO_HORDE_5, 30s);   // move
                me->SetDisableGravity(false);
                me->GetMotionMaster()->MoveFall();
                GuardBroadcast([](Creature* guard)
                {
                    guard->AI()->DoAction(ACTION_DESPAWN);
                });
                break;
            }
            case ACTION_INTERRUPT_INTRO:
            {
                _events.Reset();
                GuardBroadcast([](Creature* guard)
                {
                    guard->AI()->DoAction(ACTION_DESPAWN);
                });
                break;
            }
            default:
                break;
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_GRIP_OF_AGONY)
        {
            me->SetDisableGravity(true);
            me->GetMotionMaster()->MovePoint(POINT_CHOKE, chokePos[0]);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE)
        {
            switch (id)
            {
                case POINT_FIRST_STEP:
                    me->SetWalk(false);
                    Talk(SAY_INTRO_HORDE_3);
                    _events.ScheduleEvent(EVENT_INTRO_HORDE_5, 15500ms, 0, PHASE_INTRO_H);
                    _events.ScheduleEvent(EVENT_INTRO_HORDE_6, 29500ms, 0, PHASE_INTRO_H);
                    _events.ScheduleEvent(EVENT_INTRO_HORDE_7, 43800ms, 0, PHASE_INTRO_H);
                    _events.ScheduleEvent(EVENT_INTRO_HORDE_8, 47000ms, 0, PHASE_INTRO_H);
                    if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_DEATHBRINGER_SAURFANG)))
                        deathbringer->AI()->DoAction(ACTION_CONTINUE_INTRO);
                    break;
                case POINT_CORPSE:
                    if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_DEATHBRINGER_SAURFANG)))
                    {
                        deathbringer->CastSpell(me, SPELL_RIDE_VEHICLE, true);  // for the packet logs.
                        deathbringer->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                        deathbringer->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_DROWNED);
                    }
                    _events.ScheduleEvent(EVENT_OUTRO_HORDE_5, 1s);    // move
                    _events.ScheduleEvent(EVENT_OUTRO_HORDE_6, 4s);    // say
                    break;
                case POINT_FINAL:
                    if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_DEATHBRINGER_SAURFANG)))
                        deathbringer->DespawnOrUnsummon();
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }
        else if (type == WAYPOINT_MOTION_TYPE && id == POINT_EXIT)
        {
            std::list<Creature*> guards;
            GetCreatureListWithEntryInGrid(guards, me, NPC_KOR_KRON_GENERAL, 50.0f);
            for (std::list<Creature*>::iterator itr = guards.begin(); itr != guards.end(); ++itr)
                (*itr)->DespawnOrUnsummon();
            me->DespawnOrUnsummon();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_HORDE_3:
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(POINT_FIRST_STEP, firstStepPos.GetPositionX(), firstStepPos.GetPositionY(), firstStepPos.GetPositionZ());
                    break;
                case EVENT_INTRO_HORDE_5:
                    Talk(SAY_INTRO_HORDE_5);
                    break;
                case EVENT_INTRO_HORDE_6:
                    Talk(SAY_INTRO_HORDE_6);
                    break;
                case EVENT_INTRO_HORDE_7:
                    Talk(SAY_INTRO_HORDE_7);
                    break;
                case EVENT_INTRO_HORDE_8:
                    Talk(SAY_INTRO_HORDE_8);
                    GuardBroadcast([](Creature* guard)
                    {
                        guard->AI()->DoAction(ACTION_CHARGE);
                    });
                    me->GetMotionMaster()->MoveCharge(chargePos[0].GetPositionX(), chargePos[0].GetPositionY(), chargePos[0].GetPositionZ(), 8.5f, POINT_CHARGE);
                    break;
                case EVENT_OUTRO_HORDE_2:   // say
                    if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_DEATHBRINGER_SAURFANG)))
                        me->SetFacingToObject(deathbringer);
                    Talk(SAY_OUTRO_HORDE_2);
                    break;
                case EVENT_OUTRO_HORDE_3:   // say
                    Talk(SAY_OUTRO_HORDE_3);
                    break;
                case EVENT_OUTRO_HORDE_4:   // move
                    if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_DEATHBRINGER_SAURFANG)))
                    {
                        float x, y, z;
                        deathbringer->GetClosePoint(x, y, z, deathbringer->GetCombatReach());
                        me->SetWalk(true);
                        me->GetMotionMaster()->MovePoint(POINT_CORPSE, x, y, z);
                    }
                    break;
                case EVENT_OUTRO_HORDE_5:   // move
                    me->GetMotionMaster()->MovePoint(POINT_FINAL, finalPos);
                    break;
                case EVENT_OUTRO_HORDE_6:   // say
                    Talk(SAY_OUTRO_HORDE_4);
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_muradin_bronzebeard_icc : public ScriptedAI
{
    npc_muradin_bronzebeard_icc(Creature* creature) : ScriptedAI(creature)
    {
        _instance = me->GetInstanceScript();
    }

    void Reset() override
    {
        _events.Reset();
    }

    bool OnGossipSelect(Player* player, uint32 menuId, uint32 /*gossipListId*/) override
    {
        if (menuId == GOSSIP_MENU_MURADIN_BRONZEBEARD)
        {
            CloseGossipMenuFor(player);
            DoAction(ACTION_START_EVENT);
        }
        return false;
    }

    void GuardBroadcast(std::function<void(Creature*)>&& action) const
    {
        std::vector<Creature*> guardList;
        GetCreatureListWithEntryInGrid(guardList, me, NPC_SE_SKYBREAKER_MARINE, 100.0f);
        for (Creature* guard : guardList)
            action(guard);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_EVENT:
            {
                // Prevent crashes
                if (_events.IsInPhase(PHASE_INTRO_A) || _events.IsInPhase(PHASE_INTRO_H))
                    return;

                _events.SetPhase(PHASE_INTRO_A);
                std::list<Creature*> guardList;
                GetCreatureListWithEntryInGrid(guardList, me, NPC_SE_SKYBREAKER_MARINE, 20.0f);
                guardList.sort(Trinity::ObjectDistanceOrderPred(me));
                uint32 x = 1;
                for (auto itr = guardList.begin(); itr != guardList.end(); ++x, ++itr)
                    (*itr)->AI()->SetData(0, x);

                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                Talk(SAY_INTRO_ALLIANCE_1);
                _events.ScheduleEvent(EVENT_INTRO_ALLIANCE_4, 29500ms, 0, PHASE_INTRO_A);
                _instance->HandleGameObject(_instance->GetGuidData(GO_SAURFANG_S_DOOR), true);
                if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_DEATHBRINGER_SAURFANG)))
                    deathbringer->AI()->DoAction(PHASE_INTRO_A);
                break;
            }
            case ACTION_START_OUTRO:
            {
                me->RemoveAurasDueToSpell(SPELL_GRIP_OF_AGONY);
                Talk(SAY_OUTRO_ALLIANCE_1);
                me->SetDisableGravity(false);
                me->GetMotionMaster()->MoveFall();
                GuardBroadcast([](Creature* guard)
                {
                    guard->AI()->DoAction(ACTION_DESPAWN);
                });

                // temp until outro fully done - to put deathbringer on respawn timer (until next reset)
                if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_DEATHBRINGER_SAURFANG)))
                    deathbringer->DespawnOrUnsummon(5s);
                break;
            }
            case ACTION_INTERRUPT_INTRO:
                _events.Reset();
                GuardBroadcast([](Creature* guard)
                {
                    guard->AI()->DoAction(ACTION_DESPAWN);
                });
                break;
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_GRIP_OF_AGONY)
        {
            me->SetDisableGravity(true);
            me->GetMotionMaster()->MovePoint(POINT_CHOKE, chokePos[0]);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == POINT_FIRST_STEP)
        {
            me->SetWalk(false);
            Talk(SAY_INTRO_ALLIANCE_4);
            _events.ScheduleEvent(EVENT_INTRO_ALLIANCE_5, 5s, 0, PHASE_INTRO_A);
            if (Creature* deathbringer = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_DEATHBRINGER_SAURFANG)))
                deathbringer->AI()->DoAction(ACTION_CONTINUE_INTRO);
        }
        else if (type == WAYPOINT_MOTION_TYPE && id == POINT_EXIT)
        {
            std::list<Creature*> guards;
            GetCreatureListWithEntryInGrid(guards, me, NPC_ALLIANCE_COMMANDER, 50.0f);
            for (std::list<Creature*>::iterator itr = guards.begin(); itr != guards.end(); ++itr)
                (*itr)->DespawnOrUnsummon();
            me->DespawnOrUnsummon();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_ALLIANCE_4:
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(POINT_FIRST_STEP, firstStepPos.GetPositionX(), firstStepPos.GetPositionY(), firstStepPos.GetPositionZ());
                    break;
                case EVENT_INTRO_ALLIANCE_5:
                    Talk(SAY_INTRO_ALLIANCE_5);
                    GuardBroadcast([](Creature* guard)
                    {
                        guard->AI()->DoAction(ACTION_CHARGE);
                    });
                    me->GetMotionMaster()->MoveCharge(chargePos[0].GetPositionX(), chargePos[0].GetPositionY(), chargePos[0].GetPositionZ(), 8.5f, POINT_CHARGE);
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_saurfang_event : public ScriptedAI
{
    npc_saurfang_event(Creature* creature) : ScriptedAI(creature)
    {
        _index = 0;
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (!(!type && data && data < 6))
            return;
        _index = data;
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_GRIP_OF_AGONY)
        {
            me->SetDisableGravity(true);
            me->GetMotionMaster()->MovePoint(POINT_CHOKE, chokePos[_index]);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_CHARGE && _index)
            me->GetMotionMaster()->MoveCharge(chargePos[_index].GetPositionX(), chargePos[_index].GetPositionY(), chargePos[_index].GetPositionZ(), 13.0f, POINT_CHARGE);
        else if (action == ACTION_DESPAWN)
            me->DespawnOrUnsummon();
    }

private:
    uint32 _index;
};

// 72202 - Blood Link
class spell_deathbringer_blood_link : public SpellScript
{
    PrepareSpellScript(spell_deathbringer_blood_link);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLOOD_LINK_POWER, SPELL_BLOOD_POWER });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellBP0(GetEffectValue());
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_BLOOD_LINK_POWER, args);
        PreventHitDefaultEffect(EFFECT_0);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_deathbringer_blood_link::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 72178 - Blood Link
class spell_deathbringer_blood_link_aura : public AuraScript
{
    PrepareAuraScript(spell_deathbringer_blood_link_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MARK_OF_THE_FALLEN_CHAMPION });
    }

    void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (GetUnitOwner()->GetPowerType() == POWER_ENERGY && GetUnitOwner()->GetPower(POWER_ENERGY) == GetUnitOwner()->GetMaxPower(POWER_ENERGY))
            if (Creature* saurfang = GetUnitOwner()->ToCreature())
                saurfang->AI()->DoAction(ACTION_MARK_OF_THE_FALLEN_CHAMPION);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_deathbringer_blood_link_aura::HandlePeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 72371 - Blood Power
class spell_deathbringer_blood_power : public SpellScript
{
    PrepareSpellScript(spell_deathbringer_blood_power);

    void ModAuraValue()
    {
        if (Aura* aura = GetHitAura())
            aura->RecalculateAmountOfEffects();
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_deathbringer_blood_power::ModAuraValue);
    }
};

class spell_deathbringer_blood_power_aura : public AuraScript
{
    PrepareAuraScript(spell_deathbringer_blood_power_aura);

    void RecalculateHook(AuraEffect const* /*aurEffect*/, int32& amount, bool& canBeRecalculated)
    {
        amount = int32(GetUnitOwner()->GetPower(POWER_ENERGY));
        canBeRecalculated = true;
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_deathbringer_blood_power_aura::RecalculateHook, EFFECT_0, SPELL_AURA_MOD_SCALE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_deathbringer_blood_power_aura::RecalculateHook, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
    }
};

// 72409, 72447, 72448, 72449 - Rune of Blood
class spell_deathbringer_rune_of_blood : public SpellScript
{
    PrepareSpellScript(spell_deathbringer_rune_of_blood);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLOOD_LINK_DUMMY });
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);  // make this the default handler
        GetHitUnit()->CastSpell(nullptr, SPELL_BLOOD_LINK_DUMMY, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellBP0(1));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_deathbringer_rune_of_blood::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 72176 - Blood Beast's Blood Link
class spell_deathbringer_blood_beast_blood_link : public AuraScript
{
    PrepareAuraScript(spell_deathbringer_blood_beast_blood_link);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLOOD_LINK_DUMMY });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        eventInfo.GetProcTarget()->CastSpell(nullptr, SPELL_BLOOD_LINK_DUMMY, CastSpellExtraArgs(aurEff).AddSpellBP0(3));
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_deathbringer_blood_beast_blood_link::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 72380, 72438, 72439, 72440 - Blood Nova
class spell_deathbringer_blood_nova : public SpellScript
{
    PrepareSpellScript(spell_deathbringer_blood_nova);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLOOD_LINK_DUMMY });
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);  // make this the default handler
        GetHitUnit()->CastSpell(nullptr, SPELL_BLOOD_LINK_DUMMY, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellBP0(2));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_deathbringer_blood_nova::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 72378, 73058 - Blood Nova
class spell_deathbringer_blood_nova_targeting : public SpellScript
{
    PrepareSpellScript(spell_deathbringer_blood_nova_targeting);

public:
    spell_deathbringer_blood_nova_targeting()
    {
        target = nullptr;
    }

private:
    void FilterTargetsInitial(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        // select one random target, preferring ranged targets
        uint32 targetsAtRange = 0;
        uint32 const minTargets = uint32(GetCaster()->GetMap()->Is25ManRaid() ? 10 : 4);
        targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster(), false));

        // get target count at range
        for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end(); ++itr, ++targetsAtRange)
            if ((*itr)->GetDistance(GetCaster()) < 12.0f)
                break;

        // If not enough ranged targets are present just select anyone
        if (targetsAtRange < minTargets)
            targetsAtRange = uint32(targets.size());

        std::list<WorldObject*>::const_iterator itr = targets.begin();
        std::advance(itr, urand(0, targetsAtRange - 1));
        target = *itr;
        targets.clear();
        targets.push_back(target);
    }

    // use the same target for first and second effect
    void FilterTargetsSubsequent(std::list<WorldObject*>& unitList)
    {
        unitList.clear();
        if (!target)
            return;

        unitList.push_back(target);
    }

    void HandleForceCast(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()), TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_deathbringer_blood_nova_targeting::FilterTargetsInitial, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_deathbringer_blood_nova_targeting::FilterTargetsSubsequent, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_deathbringer_blood_nova_targeting::HandleForceCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
    }

    WorldObject* target;
};

// 72385, 72441, 72442, 72443 - Boiling Blood
class spell_deathbringer_boiling_blood : public SpellScript
{
    PrepareSpellScript(spell_deathbringer_boiling_blood);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetCaster()->GetVictim());
        if (targets.empty())
            return;

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_deathbringer_boiling_blood::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 72257 - Remove Marks of the Fallen Champion
class spell_deathbringer_remove_marks : public SpellScript
{
    PrepareSpellScript(spell_deathbringer_remove_marks);

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetHitUnit()->RemoveAurasDueToSpell(uint32(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_deathbringer_remove_marks::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class achievement_ive_gone_and_made_a_mess : public AchievementCriteriaScript
{
    public:
        achievement_ive_gone_and_made_a_mess() : AchievementCriteriaScript("achievement_ive_gone_and_made_a_mess") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (target)
                if (Creature* saurfang = target->ToCreature())
                    if (saurfang->AI()->GetData(DATA_MADE_A_MESS))
                        return true;

            return false;
        }
};

void AddSC_boss_deathbringer_saurfang()
{
    // Creatures
    RegisterIcecrownCitadelCreatureAI(boss_deathbringer_saurfang);
    RegisterIcecrownCitadelCreatureAI(npc_high_overlord_saurfang_icc);
    RegisterIcecrownCitadelCreatureAI(npc_muradin_bronzebeard_icc);
    RegisterIcecrownCitadelCreatureAI(npc_saurfang_event);

    // Spells
    RegisterSpellScript(spell_deathbringer_blood_link);
    RegisterSpellScript(spell_deathbringer_blood_link_aura);
    RegisterSpellAndAuraScriptPair(spell_deathbringer_blood_power, spell_deathbringer_blood_power_aura);
    RegisterSpellScript(spell_deathbringer_rune_of_blood);
    RegisterSpellScript(spell_deathbringer_blood_beast_blood_link);
    RegisterSpellScript(spell_deathbringer_blood_nova);
    RegisterSpellScript(spell_deathbringer_blood_nova_targeting);
    RegisterSpellScript(spell_deathbringer_boiling_blood);
    RegisterSpellScript(spell_deathbringer_remove_marks);

    // Achievements
    new achievement_ive_gone_and_made_a_mess();
}
