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
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "QuestDef.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

/*######
## npc_apothecary_hanes
######*/
enum Entries
{
    NPC_APOTHECARY_HANES = 23784,
    QUEST_TRAIL_OF_FIRE  = 11241,

    SPELL_HEALING_POTION = 17534,
    SPELL_BURN           = 42685,

    EVENT_EMOTE_BEG    = 1,
    EVENT_BEGIN        = 2,
    EVENT_START_ESCORT = 3,
    EVENT_TALK_1       = 4,
    EVENT_KNEEL        = 5,
    EVENT_TALK_2       = 6,
    EVENT_BURN_CRATES  = 7,
    EVENT_TALK_3       = 8,
    EVENT_TALK_4       = 9,
    EVENT_LAUGH        = 10,
    EVENT_TALK_5       = 11,
    EVENT_TALK_6       = 12,
    EVENT_TALK_8       = 13,

    TALK_0 = 0,
    TALK_1 = 1,
    TALK_2 = 2,
    TALK_3 = 3,
    TALK_4 = 4,
    TALK_5 = 5,
    TALK_6 = 6,
    TALK_7 = 7,
    TALK_8 = 8,

    EQUIP_TORCH = 2
};

class npc_apothecary_hanes : public CreatureScript
{
public:
    npc_apothecary_hanes() : CreatureScript("npc_apothecary_hanes") { }

    struct npc_Apothecary_HanesAI : public EscortAI
    {
        npc_Apothecary_HanesAI(Creature* creature) : EscortAI(creature)
        {
            Initialize();
        }

        void StartEscort(Player* player)
        {
            events.ScheduleEvent(EVENT_BEGIN, 2s);
            events.ScheduleEvent(EVENT_START_ESCORT, 6s);
            _player = player->GetGUID();
        }

        void Initialize()
        {
            PotTimer = 10000; //10 sec cooldown on potion
            events.Reset();
            events.ScheduleEvent(EVENT_EMOTE_BEG, 2s);
            me->SetStandState(UNIT_STAND_STATE_KNEEL);
            _player = ObjectGuid();
        }

        uint32 PotTimer;
        EventMap events;
        ObjectGuid _player;

        void Reset() override
        {
            SetDespawnAtFar(false);
            Initialize();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Player* player = GetPlayerForEscort())
                player->FailQuest(QUEST_TRAIL_OF_FIRE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (HealthBelowPct(75))
            {
                if (PotTimer <= diff)
                {
                    DoCast(me, SPELL_HEALING_POTION, true);
                    PotTimer = 10000;
                } else PotTimer -= diff;
            }

            if (IsActiveAttacker() && UpdateVictim())
                DoMeleeAttackIfReady();

            EscortAI::UpdateAI(diff);

            if (me->IsInCombat())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_EMOTE_BEG:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_BEG);
                        events.ScheduleEvent(EVENT_EMOTE_BEG, 25s);
                        break;
                    case EVENT_BEGIN:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _player))
                            Talk(TALK_0, player);
                        break;
                    case EVENT_START_ESCORT:
                        events.Reset();
                        me->SetFaction(FACTION_ESCORTEE_H_PASSIVE);
                        me->SetReactState(REACT_AGGRESSIVE);
                        ENSURE_AI(EscortAI, (me->AI()))->Start(true, true, _player);
                        break;
                    case EVENT_TALK_1:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _player))
                            Talk(TALK_1, player);
                        break;
                    case EVENT_KNEEL:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
                        break;
                    case EVENT_TALK_2:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _player))
                            Talk(TALK_2, player);
                        me->LoadEquipment(EQUIP_TORCH);
                        me->SetSheath(SHEATH_STATE_MELEE);
                        break;
                    case EVENT_BURN_CRATES:
                        DoCastAOE(SPELL_BURN, true);
                        break;
                    case EVENT_TALK_3:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _player))
                            Talk(TALK_3, player);
                        break;
                    case EVENT_TALK_4:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _player))
                            Talk(TALK_4, player);
                        break;
                    case EVENT_LAUGH:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
                        break;
                    case EVENT_TALK_5:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _player))
                            Talk(TALK_5, player);
                        me->HandleEmoteCommand(EMOTE_ONESHOT_RUDE);
                        break;
                    case EVENT_TALK_6:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _player))
                            Talk(TALK_6, player);
                        break;
                    case EVENT_TALK_8:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _player))
                            Talk(TALK_8, player);
                        break;
                }
            }
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 1:
                    events.ScheduleEvent(EVENT_TALK_1, Seconds(3));
                    events.ScheduleEvent(EVENT_KNEEL, 5s);
                    events.ScheduleEvent(EVENT_TALK_2, Seconds(6));
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    break;
                case 12:
                    events.ScheduleEvent(EVENT_BURN_CRATES, 1s);
                    events.ScheduleEvent(EVENT_TALK_3, Seconds(3));
                    break;
                case 20:
                    events.ScheduleEvent(EVENT_BURN_CRATES, 0s);
                    break;
                case 21:
                    events.ScheduleEvent(EVENT_BURN_CRATES, 0s);
                    events.ScheduleEvent(EVENT_TALK_4, Seconds(3));
                    break;
                case 28:
                    events.ScheduleEvent(EVENT_BURN_CRATES, 0s);
                    events.ScheduleEvent(EVENT_LAUGH, 7s);
                    events.ScheduleEvent(EVENT_TALK_5, Seconds(9));
                    events.ScheduleEvent(EVENT_TALK_6, Seconds(17));
                    break;
                case 35:
                    if (Player* pl = ObjectAccessor::GetPlayer(*me, _player))
                        Talk(TALK_7, pl);
                    break;
                case 40:
                    if (Player* pl = ObjectAccessor::GetPlayer(*me, _player))
                        pl->GroupEventHappens(QUEST_TRAIL_OF_FIRE, me);
                    events.ScheduleEvent(EVENT_TALK_8, Seconds(4));
                    break;
            }
        }

        void OnQuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_TRAIL_OF_FIRE)
                StartEscort(player);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_Apothecary_HanesAI(creature);
    }
};

/*######
## npc_daegarn
######*/

enum Daegarnn
{
    QUEST_DEFEAT_AT_RING = 11300,
    NPC_FIRJUS = 24213,
    NPC_JLARBORN = 24215,
    NPC_YOROS = 24214,
    NPC_OLUF = 23931,
    NPC_PRISONER_1 = 24253, // looks the same but has different abilities
    NPC_PRISONER_2 = 24254,
    NPC_PRISONER_3 = 24255,
    SAY_TEXT = 0
};

static Position const daegarnSummonPosition = { 838.81f, -4678.06f, -94.182f, 0.0f };
static Position const daegarnCenterPosition = { 801.88f, -4721.87f, -96.143f, 0.0f };

/// @todo make prisoners help (unclear if summoned or using npc's from surrounding cages (summon inside small cages?))
struct npc_daegarn : public ScriptedAI
{
    npc_daegarn(Creature* creature) : ScriptedAI(creature), _eventInProgress(false), _summons(creature)
    {
    }

    void Reset() override
    {
        _eventInProgress = false;
        _playerGUID.Clear();
        _scheduler.CancelAll();
        _summons.DespawnAll();

        _scheduler.Schedule(40s, [this](TaskContext context)
        {
            Talk(SAY_TEXT);
            context.Repeat(40s);
        });
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (!_EnterEvadeMode(why))
            return;

        if (!me->GetVehicle())
        {
            if (Unit* owner = me->GetCharmerOrOwner())
            {
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, me->GetFollowAngle());
            }
            else
            {
                me->AddUnitState(UNIT_STATE_EVADE);
                me->GetMotionMaster()->MoveTargetedHome();
            }
        }

        if (me->IsVehicle())
            me->GetVehicleKit()->Reset(true);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);

        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
        {
            if (player->IsAlive())
            {
                summon->SetWalk(false);
                summon->SetHomePosition(daegarnCenterPosition);
                summon->GetMotionMaster()->MovePoint(0, daegarnCenterPosition);
                return;
            }
        }

        Reset();
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        _summons.Despawn(summon);
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        uint32 entry = 0;

        _summons.Despawn(summon);

        // will eventually reset the event if something goes wrong
        switch (summon->GetEntry())
        {
            case NPC_FIRJUS:
                entry = NPC_JLARBORN;
                break;
            case NPC_JLARBORN:
                entry = NPC_YOROS;
                break;
            case NPC_YOROS:
                entry = NPC_OLUF;
                break;
            case NPC_OLUF:
                Reset();
                return;
        }

        SummonGladiator(entry);
    }

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_DEFEAT_AT_RING)
        {
            if (_eventInProgress)
                return;

            _eventInProgress = true;
            _playerGUID = player->GetGUID();
            _scheduler.CancelAll();
            _summons.DespawnAll();

            _scheduler.Schedule(20s, [this](TaskContext context)
            {
                bool reset = true;
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                {
                    if (player->IsAlive() && player->IsEngaged())
                    {
                        for (auto itr = _summons.begin(); reset && itr != _summons.end(); ++itr)
                        {
                            Creature* summon = ObjectAccessor::GetCreature(*me, *_summons.begin());
                            if (summon && player->IsEngagedBy(summon))
                            {
                                context.Repeat(5s);
                                reset = false;
                            }
                        }
                    }
                }

                if (reset)
                    Reset();
            });

            SummonGladiator(NPC_FIRJUS);
        }
    }

private:
    void SummonGladiator(uint32 entry)
    {
        me->SummonCreature(entry, daegarnSummonPosition, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30s);
    }

    bool _eventInProgress;
    ObjectGuid _playerGUID;
    TaskScheduler _scheduler;
    SummonList _summons;
};

enum MindlessAbomination
{
    EVENT_CHECK_CHARMED                = 1
};

class npc_mindless_abomination : public CreatureScript
{
public:
    npc_mindless_abomination() : CreatureScript("npc_mindless_abomination") { }

    struct npc_mindless_abominationAI : public ScriptedAI
    {
        npc_mindless_abominationAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            events.ScheduleEvent(EVENT_CHECK_CHARMED, 1s);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHECK_CHARMED:
                        if (!me->IsCharmedOwnedByPlayerOrPlayer())
                            me->DespawnOrUnsummon();
                        else
                            events.ScheduleEvent(EVENT_CHECK_CHARMED, 1s);
                        break;
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mindless_abominationAI(creature);
    }
};

// 42268 - Quest - Mindless Abomination Explosion FX Master
class spell_mindless_abomination_explosion_fx_master : public SpellScriptLoader
{
    enum Spells
    {
        SPELL_RANDOM_CIRCUMFERENCE_POINT_POISON = 42266,
        SPELL_COSMETIC_BLOOD_EXPLOSION_GREEN_LARGE = 43401
    };

    public:
        spell_mindless_abomination_explosion_fx_master() : SpellScriptLoader("spell_mindless_abomination_explosion_fx_master") { }

        class spell_mindless_abomination_explosion_fx_master_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mindless_abomination_explosion_fx_master_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_RANDOM_CIRCUMFERENCE_POINT_POISON, SPELL_COSMETIC_BLOOD_EXPLOSION_GREEN_LARGE });
            }

            void HandleScript(SpellEffIndex /*eff*/)
            {
                Creature* caster = GetCaster()->ToCreature();
                if (!caster)
                    return;

                caster->CastSpell(caster, SPELL_COSMETIC_BLOOD_EXPLOSION_GREEN_LARGE);

                for (uint8 i = 0; i < 10; ++i)
                    caster->CastSpell(caster, SPELL_RANDOM_CIRCUMFERENCE_POINT_POISON);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mindless_abomination_explosion_fx_master_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mindless_abomination_explosion_fx_master_SpellScript();
        }
};

/*######
## Quest 11296: Rivenwood Captives
######*/

enum RivenwoodCaptives
{
    SPELL_SUMMON_BABY_RIVEN_WIDOWS        = 43275,
    SPELL_SUMMON_DARKCLAW_BAT             = 43276,
    SPELL_SUMMON_FANGGORE_WORG            = 43277,
    SPELL_SUMMON_GJALERBRON_RUNECASTER    = 43278,
    SPELL_SUMMON_GJALERBRON_SLEEPWATCHER  = 43279,
    SPELL_SUMMON_GJALERBRON_WARRIOR       = 43280,
    SPELL_SUMMON_PUTRID_HORROR            = 43281,
    SPELL_SUMMON_WINTERSKORN_BERSERKER    = 43282,
    SPELL_SUMMON_WINTERSKORN_WOODSMAN     = 43283,
    SPELL_SUMMON_WINTERSKORN_TRIBESMAN    = 43284,
    SPELL_SUMMON_WINTERSKORN_ORACLE       = 43285,
    SPELL_SUMMON_FREED_MIST_WHISPER_SCOUT = 43289
};

uint32 const CocoonSummonSpells[11] =
{
    SPELL_SUMMON_BABY_RIVEN_WIDOWS,
    SPELL_SUMMON_DARKCLAW_BAT,
    SPELL_SUMMON_FANGGORE_WORG,
    SPELL_SUMMON_GJALERBRON_RUNECASTER,
    SPELL_SUMMON_GJALERBRON_SLEEPWATCHER,
    SPELL_SUMMON_GJALERBRON_WARRIOR,
    SPELL_SUMMON_PUTRID_HORROR,
    SPELL_SUMMON_WINTERSKORN_BERSERKER,
    SPELL_SUMMON_WINTERSKORN_WOODSMAN,
    SPELL_SUMMON_WINTERSKORN_TRIBESMAN,
    SPELL_SUMMON_WINTERSKORN_ORACLE
};

// 43288 - Rivenwood Captives: Player Not On Quest
class spell_rivenwood_captives_not_on_quest : public SpellScript
{
    PrepareSpellScript(spell_rivenwood_captives_not_on_quest);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(CocoonSummonSpells);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), Trinity::Containers::SelectRandomContainerElement(CocoonSummonSpells), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rivenwood_captives_not_on_quest::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 43287 - Rivenwood Captives: Player On Quest
class spell_rivenwood_captives_on_quest : public SpellScript
{
    PrepareSpellScript(spell_rivenwood_captives_on_quest);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(CocoonSummonSpells) && ValidateSpellInfo({ SPELL_SUMMON_FREED_MIST_WHISPER_SCOUT });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (roll_chance_i(80))
            target->CastSpell(caster, Trinity::Containers::SelectRandomContainerElement(CocoonSummonSpells), true);
        else
            target->CastSpell(caster, SPELL_SUMMON_FREED_MIST_WHISPER_SCOUT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rivenwood_captives_on_quest::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_howling_fjord()
{
    new npc_apothecary_hanes();
    RegisterCreatureAI(npc_daegarn);
    new npc_mindless_abomination();
    new spell_mindless_abomination_explosion_fx_master();
    RegisterSpellScript(spell_rivenwood_captives_not_on_quest);
    RegisterSpellScript(spell_rivenwood_captives_on_quest);
 }
