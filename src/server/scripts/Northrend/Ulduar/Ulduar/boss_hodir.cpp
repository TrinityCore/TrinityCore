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

/*
 * Spell 64540 is used in sniffs but the exact purpose and how to use it is unknown
 * Combat timers requires to be revisited
 * What does spell 64547?
 * What does periodic of spells 61969 & 61990?
 * Priest's Dispel Magic should work on both players and creatures
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "GameObject.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "ulduar.h"

enum HodirTexts
{
    SAY_AGGRO                                    = 0,
    SAY_SLAY                                     = 1,
    SAY_FLASH_FREEZE                             = 2,
    SAY_DEATH                                    = 4,
    SAY_BERSERK                                  = 5,
    EMOTE_SHATTER                                = 6,
    EMOTE_FREEZE                                 = 7,
    EMOTE_BLOWS                                  = 8
};

enum HodirSpells
{
    // Hodir - Initial
    SPELL_SHATTER_CHEST                          = 65272,
    SPELL_BITING_COLD                            = 62038,
    SPELL_ICICLE_PERIODIC                        = 62227,

    // Hodir - Combat
    SPELL_FREEZE                                 = 62469,
    SPELL_FROZEN_BLOWS                           = 62478,
    SPELL_FLASH_FREEZE                           = 61968,
    SPELL_BERSERK                                = 26662,

    // Hodir - Combat - Misc
    SPELL_ICICLE_FORCE_CAST                      = 62476,
    SPELL_ICICLE_FORCE_CAST_H                    = 62477,

    // Hodir - Outro
    SPELL_CHECK_FOR_PLAYERS                      = 64547,
    SPELL_KILL_CREDIT                            = 64899,
    SPELL_TELEPORT                               = 62940,

    // Generic
    SPELL_ICE_SHARDS_DAMAGE_1                    = 62457,
    SPELL_ICE_SHARDS_DAMAGE_2                    = 65370,
    SPELL_FLASH_FREEZE_SUMMON_INIT               = 61989,

    // Invisible Stalker (Float, Uninteractible, LargeAOI)
    SPELL_FLASH_FREEZE_VISUAL                    = 62148,

    // Snowpacked Icicle Target
    SPELL_SAFE_AREA                              = 65705,
    SPELL_BIRTH_NO_VISUAL                        = 40031,

    // Icicle
    // Snowpacked Icicle
    SPELL_ICICLE_PERIODIC_1                      = 62236,
    SPELL_ICICLE_PERIODIC_2                      = 62460,
    SPELL_ICICLE_DUMMY                           = 62453,

    // Priests
    SPELL_SMITE                                  = 61923,
    SPELL_GREATER_HEAL                           = 62809,
    SPELL_DISPEL_MAGIC                           = 63499,

    // Shamans
    SPELL_LAVA_BURST                             = 61924,
    SPELL_STORM_CLOUD                            = 62797,

    // Druids
    SPELL_MOONKIN_FORM_SHAPESHIFT                = 62795,
    SPELL_WRATH                                  = 62793,
    SPELL_STARLIGHT                              = 62807,

    // Mages
    SPELL_FIREBALL                               = 61909,
    SPELL_CONJURE_TOASTY_FIRE                    = 62823,
    SPELL_MELT_ICE                               = 64543,

    // Toasty Fire
    SPELL_TOASTY_FIRE_AREA_AURA                  = 62821,

    // Flash Freeze (Init)
    SPELL_FLASH_FREEZE_INITIAL_AGGRO             = 62878,
    SPELL_FLASH_FREEZE_STUN_INIT                 = 61990,

    // Flash Freeze (Combat)
    SPELL_FLASH_FREEZE_STUN_COMBAT               = 61969,

    // Scripts
    SPELL_SAFE_AREA_AURA                         = 62464,
    SPELL_FLASH_FREEZE_KILL                      = 62226,
    SPELL_FLASH_FREEZE_SUMMON_COMBAT             = 61970,

    SPELL_SHATTER_CHEST_MISSILE                  = 62501,

    SPELL_BITING_COLD_PERIODIC                   = 62039,
    SPELL_BITING_COLD_DAMAGE                     = 62188,

    SPELL_STORM_CLOUD_EFFECT                     = 65123,
    SPELL_STORM_CLOUD_EFFECT_H                   = 65133,

    // Misc
    SPELL_STORM_POWER                            = 63711,
    SPELL_STORM_POWER_H                          = 65134
};

enum HodirEvents
{
    EVENT_FREEZE                                 = 1,
    EVENT_FROZEN_BLOWS,
    EVENT_FLASH_FREEZE,
    EVENT_BERSERK,

    EVENT_FLASH_FREEZE_FINISHED_1,
    EVENT_FLASH_FREEZE_FINISHED_2,
    EVENT_FLASH_FREEZE_FINISHED_3,

    EVENT_EPILOGUE_1,
    EVENT_EPILOGUE_2,
    EVENT_EPILOGUE_3,
    EVENT_EPILOGUE_4,
    EVENT_EPILOGUE_5
};

enum HodirCreatures
{
    NPC_ICICLE                                   = 33169,
    NPC_SNOWPACKED_ICICLE                        = 33173,
    NPC_FLASH_FREEZE_INIT                        = 32938,
    NPC_FLASH_FREEZE_COMBAT                      = 32926,
    NPC_TOASTY_FIRE                              = 33342,
    NPC_INVISIBLE_STALKER                        = 30298
};

enum HodirGameObjects
{
    GO_TOASTY_FIRE                               = 194300
};

enum HodirActions
{
    ACTION_COOLEST_FRIEND_PREPARE                = 0,
    ACTION_COOLEST_FRIEND_VICTORY                = 1,
    ACTION_COOLEST_FRIEND_DIES                   = 2,
    ACTION_BITING_COLD_TOO_MUCH_STACKS           = 3,
    ACTION_PLAYER_IS_FROZEN                      = 4
};

enum HodirDataTypes
{
    DATA_CHEESE_THE_FREEZE                       = 29612962,
    DATA_GETTING_COLD_IN_HERE                    = 29672968,
    DATA_THIS_CACHE_WAS_RARE                     = 31823184,
    DATA_I_HAVE_THE_COOLEST_FRIENDS              = 29632965
};

Position const SummonPositions[8] =
{
    { 1983.75f, -243.36f, 432.767f, 1.57f }, // Field Medic Penny    &&  Battle-Priest Eliza
    { 1999.90f, -230.49f, 432.767f, 1.57f }, // Eivi Nightfeather    &&  Tor Greycloud
    { 2010.06f, -243.45f, 432.767f, 1.57f }, // Elementalist Mahfuun &&  Spiritwalker Tara
    { 2021.12f, -236.65f, 432.767f, 1.57f }, // Missy Flamecuffs     &&  Amira Blazeweaver
    { 2028.10f, -244.66f, 432.767f, 1.57f }, // Field Medic Jessi    &&  Battle-Priest Gina
    { 2014.18f, -232.80f, 432.767f, 1.57f }, // Ellie Nightfeather   &&  Kar Greycloud
    { 1992.90f, -237.54f, 432.767f, 1.57f }, // Elementalist Avuun   &&  Spiritwalker Yona
    { 1976.60f, -233.53f, 432.767f, 1.57f }  // Sissy Flamecuffs     &&  Veesha Blazeweaver
};

static constexpr std::array<uint32, 8> CoolestFriendsEntries =
{
    NPC_FIELD_MEDIC_PENNY,
    NPC_EIVI_NIGHTFEATHER,
    NPC_ELEMENTALIST_MAHFUUN,
    NPC_MISSY_FLAMECUFFS,
    NPC_FIELD_MEDIC_JESSI,
    NPC_ELLIE_NIGHTFEATHER,
    NPC_ELEMENTALIST_AVUUN,
    NPC_SISSY_FLAMECUFFS
};

// 32845 - Hodir
struct boss_hodir : public BossAI
{
    boss_hodir(Creature* creature) : BossAI(creature, DATA_HODIR)
    {
        _isDefeated = false;
        _gettingColdInHere = true;
        _cheeseTheFreeze = true;
        _iHaveTheCoolestFriends = true;
        _thisCacheWasRare = true;
    }

    void JustAppeared() override
    {
        for (uint8 i = 0; i < RAID_MODE(4, 8); ++i)
            me->SummonCreature(CoolestFriendsEntries[i], SummonPositions[i], TEMPSUMMON_MANUAL_DESPAWN);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        DoCastSelf(SPELL_SHATTER_CHEST);
        DoCastSelf(SPELL_BITING_COLD);
        DoCastSelf(SPELL_ICICLE_PERIODIC);

        events.ScheduleEvent(EVENT_FREEZE, 10s, 20s);
        events.ScheduleEvent(EVENT_FROZEN_BLOWS, 60s, 65s);
        events.ScheduleEvent(EVENT_FLASH_FREEZE, 45s, 60s);
        events.ScheduleEvent(EVENT_BERSERK, 8min);

        std::vector<Creature*> coolestFriends;
        GetCreatureListWithOptionsInGrid(coolestFriends, me, 100.0f, { .StringId = "HodirCoolestFriend" });
        for (Creature* coolestFriend : coolestFriends)
                coolestFriend->AI()->DoAction(ACTION_COOLEST_FRIEND_PREPARE);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_INITIAL_AGGRO_HODIR:
                if (!me->IsInCombat())
                    DoZoneInCombat();
                break;
            case ACTION_COOLEST_FRIEND_DIES:
                _iHaveTheCoolestFriends = false;
                break;
            case ACTION_BITING_COLD_TOO_MUCH_STACKS:
                _gettingColdInHere = false;
                break;
            case ACTION_PLAYER_IS_FROZEN:
                _cheeseTheFreeze = false;
                break;
            case ACTION_CACHE_SHATTERED:
                Talk(EMOTE_SHATTER);
                _thisCacheWasRare = false;
                break;
            case ACTION_FLASH_FREEZE_FINISHED:
                events.ScheduleEvent(EVENT_FLASH_FREEZE_FINISHED_1, 0s);
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case DATA_CHEESE_THE_FREEZE:
                return _cheeseTheFreeze ? 1 : 0;
            case DATA_GETTING_COLD_IN_HERE:
                return _gettingColdInHere ? 1 : 0;
            case DATA_THIS_CACHE_WAS_RARE:
                return _thisCacheWasRare ? 1 : 0;
            case DATA_I_HAVE_THE_COOLEST_FRIENDS:
                return _iHaveTheCoolestFriends ? 1 : 0;
        }

        return 0;
    }

    void OnSpellStart(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_FLASH_FREEZE)
        {
            Talk(SAY_FLASH_FREEZE);
            Talk(EMOTE_FREEZE);
            me->RemoveAurasDueToSpell(SPELL_ICICLE_PERIODIC);
            DoCastSelf(GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL ? SPELL_ICICLE_FORCE_CAST : SPELL_ICICLE_FORCE_CAST_H, true);
        }
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == sSpellMgr->GetSpellIdForDifficulty(SPELL_FROZEN_BLOWS, me))
            Talk(EMOTE_BLOWS);

        if (spellInfo->Id == SPELL_BERSERK)
            Talk(SAY_BERSERK);
    }

    void DamageTaken(Unit* /*who*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
        {
            damage = me->GetHealth() - 1;

            if (_isDefeated)
                return;

            _isDefeated = true;

            _epilogueEvents.ScheduleEvent(EVENT_EPILOGUE_1, 0s);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (!_isDefeated)
        {
            summons.DespawnAll();
            _DespawnAtEvade();
        }
        else
        {
            me->RemoveAurasOnEvade();
            me->CombatStop(true);
        }
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void UpdateAI(uint32 diff) override
    {
        _epilogueEvents.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _epilogueEvents.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_EPILOGUE_1:
                {
                    std::vector<Creature*> coolestFriends;
                    GetCreatureListWithOptionsInGrid(coolestFriends, me, 100.0f, { .StringId = "HodirCoolestFriend" });
                    for (Creature* coolestFriend : coolestFriends)
                        if (coolestFriend->IsAlive())
                            coolestFriend->AI()->DoAction(ACTION_COOLEST_FRIEND_VICTORY);

                    // This is not correct, they don't despawn, we just want to prevent combat stuck
                    summons.DespawnEntry(NPC_FLASH_FREEZE_INIT);
                    summons.DespawnEntry(NPC_FLASH_FREEZE_COMBAT);

                    DoCastAOE(SPELL_CHECK_FOR_PLAYERS, true);
                    DoCastAOE(SPELL_KILL_CREDIT, true);
                    me->RemoveAurasDueToSpell(SPELL_ICICLE_PERIODIC);
                    me->AttackStop();
                    me->RemoveAllAttackers();
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFaction(FACTION_FRIENDLY);
                    me->SetImmuneToNPC(true);
                    me->SetHomePosition(me->GetPosition());

                    events.Reset();

                    instance->SetBossState(DATA_HODIR, DONE);

                    _epilogueEvents.ScheduleEvent(EVENT_EPILOGUE_2, 1s);
                    break;
                }
                case EVENT_EPILOGUE_2:
                    EnterEvadeMode(EVADE_REASON_OTHER);
                    _epilogueEvents.ScheduleEvent(EVENT_EPILOGUE_3, 6s);
                    break;
                case EVENT_EPILOGUE_3:
                    Talk(SAY_DEATH);
                    _epilogueEvents.ScheduleEvent(EVENT_EPILOGUE_4, 10s);
                    break;
                case EVENT_EPILOGUE_4:
                    DoCastSelf(SPELL_TELEPORT);
                    _epilogueEvents.ScheduleEvent(EVENT_EPILOGUE_5, 1s);
                    break;
                case EVENT_EPILOGUE_5:
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FREEZE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 55.0f, true))
                        DoCast(target, SPELL_FREEZE);
                    events.Repeat(10s, 25s);
                    break;
                case EVENT_FROZEN_BLOWS:
                    DoCastSelf(SPELL_FROZEN_BLOWS);
                    events.Repeat(60s, 65s);
                    break;
                case EVENT_FLASH_FREEZE:
                    DoCastSelf(SPELL_FLASH_FREEZE);
                    events.Repeat(60s, 90s);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    break;

                case EVENT_FLASH_FREEZE_FINISHED_1:
                    if (Creature* trigger = GetClosestCreatureWithEntry(me, NPC_INVISIBLE_STALKER, 100.0f))
                        trigger->CastSpell(trigger, SPELL_FLASH_FREEZE_VISUAL);

                    events.ScheduleEvent(EVENT_FLASH_FREEZE_FINISHED_2, 1s);
                    break;
                case EVENT_FLASH_FREEZE_FINISHED_2:
                {
                    std::vector<Creature*> firesCreatures;
                    GetCreatureListWithEntryInGrid(firesCreatures, me, NPC_TOASTY_FIRE, 100.0f);
                    for (Creature* fire : firesCreatures)
                        fire->DespawnOrUnsummon();

                    std::vector<GameObject*> firesObjects;
                    GetGameObjectListWithEntryInGrid(firesObjects, me, GO_TOASTY_FIRE, 100.0f);
                    for (GameObject* fire : firesObjects)
                        fire->ActivateObject(GameObjectActions(GameObjectActions::Despawn));

                    events.ScheduleEvent(EVENT_FLASH_FREEZE_FINISHED_3, 1s);
                    break;
                }
                case EVENT_FLASH_FREEZE_FINISHED_3:
                    DoCastSelf(SPELL_ICICLE_PERIODIC, true);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _isDefeated;
    bool _gettingColdInHere;
    bool _cheeseTheFreeze;
    bool _iHaveTheCoolestFriends;
    bool _thisCacheWasRare;
    EventMap _epilogueEvents;
};

struct CoolestFriendBaseAI : public ScriptedAI
{
    CoolestFriendBaseAI(Creature* creature) : ScriptedAI(creature), Instance(creature->GetInstanceScript()) { }

    void InitializeAI() override
    {
        Scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_FLASH_FREEZE_SUMMON_INIT);
    }

    void Reset() override
    {
        Scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        ScheduleEvents();
    }

    virtual void ScheduleEvents() = 0;

    void AttackStart(Unit* who) override
    {
        ScriptedAI::AttackStartCaster(who, 20.0f);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_COOLEST_FRIEND_PREPARE:
            {
                me->SetImmuneToNPC(false);

                // Not sure if below is correct approach, we just want friends to help
                std::vector<Creature*> flashes;
                GetCreatureListWithEntryInGrid(flashes, me, NPC_FLASH_FREEZE_INIT, 100.0f);
                for (Creature* flash : flashes)
                    me->EngageWithTarget(flash);

                if (Creature* hodir = Instance->GetCreature(DATA_HODIR))
                    me->EngageWithTarget(hodir);

                break;
            }
            case ACTION_COOLEST_FRIEND_VICTORY:
                EpilogueScheduler.Schedule(3s, [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            me->SetImmuneToNPC(true);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_CHEER_NO_SHEATHE);
                            task.Repeat(5s);
                            break;
                        case 1:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_CHEER_NO_SHEATHE);
                            task.Repeat(5s);
                            break;
                        case 2:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_CHEER_NO_SHEATHE);
                            task.Repeat(5s);
                            break;
                        case 3:
                            me->SetEmoteState(EMOTE_ONESHOT_DANCE);
                            task.Repeat(randtime(15s, 30s));
                            break;
                        case 4:
                            me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                });
                break;
            default:
                break;
        }
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        me->SetHomePosition(me->GetPosition());
        ScriptedAI::EnterEvadeMode(why);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* hodir = Instance->GetCreature(DATA_HODIR))
            hodir->AI()->DoAction(ACTION_COOLEST_FRIEND_DIES);
    }

    void UpdateAI(uint32 diff) override
    {
        EpilogueScheduler.Update(diff);

        if (!UpdateVictim() || me->HasAura(SPELL_FLASH_FREEZE_STUN_COMBAT) || me->HasAura(SPELL_FLASH_FREEZE_STUN_INIT))
            return;

        Scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

protected:
    TaskScheduler Scheduler;
    TaskScheduler EpilogueScheduler;
    InstanceScript* Instance;
};

// 32897 - Field Medic Penny
// 32948 - Battle-Priest Eliza
// 33326 - Field Medic Jessi
// 33330 - Battle-Priest Gina
struct npc_hodir_priest : public CoolestFriendBaseAI
{
    npc_hodir_priest(Creature* creature) : CoolestFriendBaseAI(creature) { }

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(0s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_SMITE);
                task.Repeat(2400ms);
            })
            .Schedule(0s, 5s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_GREATER_HEAL);
                task.Repeat(7s, 9s);
            })
            .Schedule(0s, [this](TaskContext task)
            {
                std::list<Creature*> targets = DoFindFriendlyCC(40.0f);
                if (!targets.empty())
                {
                    DoCastSelf(SPELL_DISPEL_MAGIC);
                    task.Repeat(2400ms);
                }
                else
                    task.Repeat(1200ms);
            });
    }
};

// 32900 - Elementalist Avuun
// 32950 - Spiritwalker Yona
// 33328 - Elementalist Mahfuun
// 33332 - Spiritwalker Tara
struct npc_hodir_shaman : public CoolestFriendBaseAI
{
    npc_hodir_shaman(Creature* creature) : CoolestFriendBaseAI(creature) { }

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(0s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_LAVA_BURST);
                task.Repeat(3600ms);
            })
            .Schedule(0s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_STORM_CLOUD);
                task.Repeat(30s);
            });
    }
};

// 32901 - Ellie Nightfeather
// 32941 - Tor Greycloud
// 33325 - Eivi Nightfeather
// 33333 - Kar Greycloud
struct npc_hodir_druid : public CoolestFriendBaseAI
{
    npc_hodir_druid(Creature* creature) : CoolestFriendBaseAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_MOONKIN_FORM_SHAPESHIFT);
        CoolestFriendBaseAI::JustAppeared();
    }

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(0s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_WRATH);
                task.Repeat(2400ms);
            })
            .Schedule(0s, 5s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_STARLIGHT);
                task.Repeat(15s);
            });
    }
};

// 32893 - Missy Flamecuffs
// 32946 - Veesha Blazeweaver
// 33327 - Sissy Flamecuffs
// 33331 - Amira Blazeweaver
struct npc_hodir_mage : public CoolestFriendBaseAI
{
    npc_hodir_mage(Creature* creature) : CoolestFriendBaseAI(creature) { }

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(0s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_FIREBALL);
                task.Repeat(3600ms);
            })
            .Schedule(5s, 10s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_CONJURE_TOASTY_FIRE);
                task.Repeat(10s, 20s);
            })
            .Schedule(0s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_MELT_ICE);
                task.Repeat(1200ms);
            });
    }
};

// 33342 - Toasty Fire
struct npc_toasty_fire : public ScriptedAI
{
    npc_toasty_fire(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_TOASTY_FIRE_AREA_AURA);
        DoCastSelf(SPELL_BIRTH_NO_VISUAL);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        // Actually this does not happen in sniffs or videos. Initially wrong behavior or something is missing?
        if (spellInfo->Id == SPELL_ICE_SHARDS_DAMAGE_1 || spellInfo->Id == SPELL_ICE_SHARDS_DAMAGE_2)
        {
            if (GameObject* fire = me->FindNearestGameObject(GO_TOASTY_FIRE, 1.0f))
                fire->ActivateObject(GameObjectActions(GameObjectActions::Despawn));

            me->DespawnOrUnsummon();
        }
    }
};

// 33169 - Icicle
// 33173 - Snowpacked Icicle
struct npc_icicle : public ScriptedAI
{
    npc_icicle(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetDisplayId(me->GetCreatureTemplate()->Modelid1);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        _scheduler.Schedule(3500ms, [this](TaskContext /*task*/)
        {
            switch (me->GetEntry())
            {
                case NPC_ICICLE:
                    DoCastSelf(SPELL_ICICLE_PERIODIC_1);
                    DoCastSelf(SPELL_ICICLE_DUMMY);
                    break;
                case NPC_SNOWPACKED_ICICLE:
                    DoCastSelf(SPELL_ICICLE_PERIODIC_2);
                    DoCastSelf(SPELL_ICICLE_DUMMY);
                    break;
                default:
                    break;
            }
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 33174 - Snowpacked Icicle Target
struct npc_snowpacked_icicle_target : public ScriptedAI
{
    npc_snowpacked_icicle_target(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SAFE_AREA);
        DoCastSelf(SPELL_BIRTH_NO_VISUAL);
    }
};

// 32938 - Flash Freeze
struct npc_flash_freeze_init : public ScriptedAI
{
    npc_flash_freeze_init(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _isShattered(false) { }

    void InitializeAI() override
    {
        me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_FLASH_FREEZE_INITIAL_AGGRO);
        DoCastSelf(SPELL_FLASH_FREEZE_STUN_INIT);

        if (Creature* hodir = _instance->GetCreature(DATA_HODIR))
            hodir->AI()->JustSummoned(me);

        // This part requires sniff verification
        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            if (TempSummon* summon = me->ToTempSummon())
                if (Unit* summoner = summon->GetSummonerUnit())
                    if (!summoner->IsAlive())
                        me->DespawnOrUnsummon();

            task.Repeat(1s);
        });
    }

    void DamageTaken(Unit* /*who*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
        {
            damage = me->GetHealth() - 1;

            if (_isShattered)
                return;

            _isShattered = true;

            _scheduler.Schedule(1s, [this](TaskContext task)
            {
                switch (task.GetRepeatCounter())
                {
                    case 0:
                        me->InterruptNonMeleeSpells(false);
                        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                        task.Repeat(1s);
                        break;
                    case 1:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _scheduler.Update(diff);
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
    bool _isShattered;
};

// 32926 - Flash Freeze
struct npc_flash_freeze_combat : public ScriptedAI
{
    npc_flash_freeze_combat(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _isShattered(false) { }

    void InitializeAI() override
    {
        me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_FLASH_FREEZE_STUN_COMBAT);

        if (Creature* hodir = _instance->GetCreature(DATA_HODIR))
            hodir->AI()->JustSummoned(me);

        // This part requires sniff verification
        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            if (TempSummon* summon = me->ToTempSummon())
                if (Unit* summoner = summon->GetSummonerUnit())
                    if (!summoner->IsAlive())
                        me->DespawnOrUnsummon();

            task.Repeat(1s);
        });
    }

    void DamageTaken(Unit* /*who*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
        {
            damage = me->GetHealth() - 1;

            if (_isShattered)
                return;

            _isShattered = true;

            _scheduler.Schedule(1s, [this](TaskContext task)
            {
                switch (task.GetRepeatCounter())
                {
                    case 0:
                        me->InterruptNonMeleeSpells(false);
                        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                        task.Repeat(1s);
                        break;
                    case 1:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _scheduler.Update(diff);
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
    bool _isShattered;
};

// 62469 - Freeze
class spell_hodir_freeze : public SpellScript
{
    PrepareSpellScript(spell_hodir_freeze);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_1).CalcValue()) });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(Trinity::UnitAuraCheck(true, uint32(GetEffectInfo(EFFECT_1).CalcValue())));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hodir_freeze::FilterTargets, EFFECT_ALL, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

// 61968 - Flash Freeze
class spell_hodir_flash_freeze : public AuraScript
{
    PrepareAuraScript(spell_hodir_flash_freeze);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SAFE_AREA_AURA,
            SPELL_FLASH_FREEZE_STUN_INIT,
            SPELL_FLASH_FREEZE_STUN_COMBAT,
            SPELL_FLASH_FREEZE_KILL,
            SPELL_FLASH_FREEZE_SUMMON_COMBAT
        });
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();

        if (aurEff->GetTickNumber() == 1 && !target->HasAura(SPELL_SAFE_AREA_AURA))
        {
            if (target->HasAura(SPELL_FLASH_FREEZE_STUN_INIT) || target->HasAura(SPELL_FLASH_FREEZE_STUN_COMBAT))
            {
                // This part requires sniff verification
                if (Unit* caster = GetCaster())
                    caster->CastSpell(target, SPELL_FLASH_FREEZE_KILL, true);
            }
            else
            {
                target->CastSpell(target, SPELL_FLASH_FREEZE_SUMMON_COMBAT, true);

                if (target->IsPlayer())
                    if (Unit* caster = GetCaster())
                        if (Creature* creatureCaster = caster->ToCreature())
                            if (CreatureAI* ai = creatureCaster->AI())
                                ai->DoAction(ACTION_PLAYER_IS_FROZEN);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hodir_flash_freeze::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 65272 - Shatter Chest
class spell_hodir_shatter_chest : public AuraScript
{
    PrepareAuraScript(spell_hodir_shatter_chest);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHATTER_CHEST_MISSILE });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_SHATTER_CHEST_MISSILE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hodir_shatter_chest::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 63545 - Icicle
class spell_hodir_icicle : public SpellScript
{
    PrepareSpellScript(spell_hodir_icicle);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectInfo(EFFECT_0).CalcValue()), true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hodir_icicle::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_hodir_icicle::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 62476 - Icicle
// 62477 - Icicle
class spell_hodir_icicle_force_cast : public SpellScript
{
    PrepareSpellScript(spell_hodir_icicle_force_cast);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL ? 2 : 3);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hodir_icicle_force_cast::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 62038 - Biting Cold
class spell_hodir_biting_cold_area_aura : public AuraScript
{
    PrepareAuraScript(spell_hodir_biting_cold_area_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TOASTY_FIRE_AREA_AURA, SPELL_BITING_COLD_PERIODIC });
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();

        if (target->isMoving() || target->HasAura(SPELL_TOASTY_FIRE_AREA_AURA))
        {
            target->RemoveAuraFromStack(SPELL_BITING_COLD_PERIODIC);
            const_cast<AuraEffect*>(aurEff)->ResetTicks();
        }
        else if (!(aurEff->GetTickNumber() % 4) && !target->HasAura(SPELL_TOASTY_FIRE_AREA_AURA))
            target->CastSpell(target, SPELL_BITING_COLD_PERIODIC, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hodir_biting_cold_area_aura::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 62039 - Biting Cold
class spell_hodir_biting_cold_periodic : public AuraScript
{
    PrepareAuraScript(spell_hodir_biting_cold_periodic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BITING_COLD_DAMAGE });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_BITING_COLD_DAMAGE, CastSpellExtraArgs()
            .SetTriggerFlags(TRIGGERED_FULL_MASK)
            .AddSpellMod(SPELLVALUE_BASE_POINT0, int32(200 * std::pow(2.0f, GetStackAmount()))));

        if (GetStackAmount() > 2)
            if (InstanceScript* instance = GetTarget()->GetInstanceScript())
                if (Creature* hodir = instance->GetCreature(DATA_HODIR))
                    hodir->AI()->DoAction(ACTION_BITING_COLD_TOO_MUCH_STACKS);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hodir_biting_cold_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 63499 - Dispel Magic
class spell_hodir_dispel_magic : public SpellScript
{
    PrepareSpellScript(spell_hodir_dispel_magic);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_1).CalcValue()) });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(Trinity::UnitAuraCheck(false, uint32(GetEffectInfo(EFFECT_1).CalcValue())));
        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hodir_dispel_magic::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// 62797 - Storm Cloud
class spell_hodir_storm_cloud_primer : public SpellScript
{
    PrepareSpellScript(spell_hodir_storm_cloud_primer);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_STORM_CLOUD_EFFECT, SPELL_STORM_CLOUD_EFFECT_H });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetCaster()->GetMap()->GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL ?
		    SPELL_STORM_CLOUD_EFFECT : SPELL_STORM_CLOUD_EFFECT_H);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hodir_storm_cloud_primer::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_hodir_storm_cloud_primer::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 64543 - Melt Ice
class spell_hodir_melt_ice : public SpellScript
{
    PrepareSpellScript(spell_hodir_melt_ice);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(Trinity::UnitAuraCheck(true, uint32(GetEffectInfo(EFFECT_0).CalcValue())));
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectInfo(EFFECT_0).CalcValue()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hodir_melt_ice::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_hodir_melt_ice::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class achievement_cheese_the_freeze : public AchievementCriteriaScript
{
public:
    achievement_cheese_the_freeze() : AchievementCriteriaScript("achievement_cheese_the_freeze") { }

    bool OnCheck(Player* /*player*/, Unit* target) override
    {
        return target && target->GetAI() && target->GetAI()->GetData(DATA_CHEESE_THE_FREEZE);
    }
};

class achievement_getting_cold_in_here : public AchievementCriteriaScript
{
public:
    achievement_getting_cold_in_here() : AchievementCriteriaScript("achievement_getting_cold_in_here") { }

    bool OnCheck(Player* /*player*/, Unit* target) override
    {
        return target && target->GetAI() && target->GetAI()->GetData(DATA_GETTING_COLD_IN_HERE);
    }
};

class achievement_this_cache_was_rare : public AchievementCriteriaScript
{
public:
    achievement_this_cache_was_rare() : AchievementCriteriaScript("achievement_this_cache_was_rare") { }

    bool OnCheck(Player* /*player*/, Unit* target) override
    {
        return target && target->GetAI() && target->GetAI()->GetData(DATA_THIS_CACHE_WAS_RARE);
    }
};

class achievement_i_have_the_coolest_friends : public AchievementCriteriaScript
{
public:
    achievement_i_have_the_coolest_friends() : AchievementCriteriaScript("achievement_i_have_the_coolest_friends") { }

    bool OnCheck(Player* /*player*/, Unit* target) override
    {
        return target && target->GetAI() && target->GetAI()->GetData(DATA_I_HAVE_THE_COOLEST_FRIENDS);
    }
};

class achievement_staying_buffed_all_winter : public AchievementCriteriaScript
{
public:
    achievement_staying_buffed_all_winter() : AchievementCriteriaScript("achievement_staying_buffed_all_winter") { }

    bool OnCheck(Player* player, Unit* /*target*/) override
    {
        return player->HasAura(SPELL_TOASTY_FIRE_AREA_AURA) && player->HasAura(SPELL_STARLIGHT) && player->HasAura(SPELL_STORM_POWER);
    }
};

class achievement_staying_buffed_all_winter_25 : public AchievementCriteriaScript
{
public:
    achievement_staying_buffed_all_winter_25() : AchievementCriteriaScript("achievement_staying_buffed_all_winter_25") { }

    bool OnCheck(Player* player, Unit* /*target*/) override
    {
        return player->HasAura(SPELL_TOASTY_FIRE_AREA_AURA) && player->HasAura(SPELL_STARLIGHT) && player->HasAura(SPELL_STORM_POWER_H);
    }
};

void AddSC_boss_hodir()
{
    RegisterUlduarCreatureAI(boss_hodir);
    RegisterUlduarCreatureAI(npc_hodir_priest);
    RegisterUlduarCreatureAI(npc_hodir_shaman);
    RegisterUlduarCreatureAI(npc_hodir_druid);
    RegisterUlduarCreatureAI(npc_hodir_mage);
    RegisterUlduarCreatureAI(npc_toasty_fire);
    RegisterUlduarCreatureAI(npc_icicle);
    RegisterUlduarCreatureAI(npc_snowpacked_icicle_target);
    RegisterUlduarCreatureAI(npc_flash_freeze_init);
    RegisterUlduarCreatureAI(npc_flash_freeze_combat);
    RegisterSpellScript(spell_hodir_freeze);
    RegisterSpellScript(spell_hodir_flash_freeze);
    RegisterSpellScript(spell_hodir_shatter_chest);
    RegisterSpellScript(spell_hodir_icicle);
    RegisterSpellScript(spell_hodir_icicle_force_cast);
    RegisterSpellScript(spell_hodir_biting_cold_area_aura);
    RegisterSpellScript(spell_hodir_biting_cold_periodic);
    RegisterSpellScript(spell_hodir_dispel_magic);
    RegisterSpellScript(spell_hodir_storm_cloud_primer);
    RegisterSpellScript(spell_hodir_melt_ice);
    new achievement_cheese_the_freeze();
    new achievement_getting_cold_in_here();
    new achievement_this_cache_was_rare();
    new achievement_i_have_the_coolest_friends();
    new achievement_staying_buffed_all_winter();
    new achievement_staying_buffed_all_winter_25();
}
