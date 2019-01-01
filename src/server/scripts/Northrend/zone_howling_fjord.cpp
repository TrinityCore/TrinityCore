/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
SDName: Sholazar_Basin
SD%Complete: 100
SDComment: Quest support: 11253, 11241.
SDCategory: howling_fjord
EndScriptData */

/* ContentData
npc_plaguehound_tracker
npc_apothecary_hanes
EndContentData */

#include "ScriptMgr.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

/*######
## npc_apothecary_hanes
######*/
enum Entries
{
    NPC_APOTHECARY_HANES = 23784,
    FACTION_ESCORTEE_H   = 775,
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

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_TRAIL_OF_FIRE)
        {
            ENSURE_AI(npc_Apothecary_HanesAI, (creature->AI()))->StartEscort(player);
        }
        return true;
    }

    struct npc_Apothecary_HanesAI : public npc_escortAI
    {
        npc_Apothecary_HanesAI(Creature* creature) : npc_escortAI(creature)
        {
            Initialize();
        }

        void StartEscort(Player* player)
        {
            events.ScheduleEvent(EVENT_BEGIN, Seconds(2));
            events.ScheduleEvent(EVENT_START_ESCORT, Seconds(6));
            _player = player->GetGUID();
        }

        void Initialize()
        {
            PotTimer = 10000; //10 sec cooldown on potion
            events.Reset();
            events.ScheduleEvent(EVENT_EMOTE_BEG, Seconds(2));
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

            if (GetAttack() && UpdateVictim())
                DoMeleeAttackIfReady();

            npc_escortAI::UpdateAI(diff);

            if (me->IsInCombat())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_EMOTE_BEG:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_BEG);
                        events.ScheduleEvent(EVENT_EMOTE_BEG, Seconds(25));
                        break;
                    case EVENT_BEGIN:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _player))
                            Talk(TALK_0, player);
                        break;
                    case EVENT_START_ESCORT:
                        events.Reset();
                        me->setFaction(FACTION_ESCORTEE_H);
                        me->SetReactState(REACT_AGGRESSIVE);
                        ENSURE_AI(npc_escortAI, (me->AI()))->Start(true, true, _player);
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

        void WaypointReached(uint32 waypointId) override
        {
            if (!GetPlayerForEscort())
                return;

            switch (waypointId)
            {
                case 1:
                    events.ScheduleEvent(EVENT_TALK_1, Seconds(3));
                    events.ScheduleEvent(EVENT_KNEEL, Seconds(5));
                    events.ScheduleEvent(EVENT_TALK_2, Seconds(6));
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    break;
                case 12:
                    events.ScheduleEvent(EVENT_BURN_CRATES, Seconds(1));
                    events.ScheduleEvent(EVENT_TALK_3, Seconds(3));
                    break;
                case 20:
                    events.ScheduleEvent(EVENT_BURN_CRATES, 0);
                    break;
                case 21:
                    events.ScheduleEvent(EVENT_BURN_CRATES, 0);
                    events.ScheduleEvent(EVENT_TALK_4, Seconds(3));
                    break;
                case 28:
                    events.ScheduleEvent(EVENT_BURN_CRATES, 0);
                    events.ScheduleEvent(EVENT_LAUGH, Seconds(7));
                    events.ScheduleEvent(EVENT_TALK_5, Seconds(9));
                    events.ScheduleEvent(EVENT_TALK_6, Seconds(17));
                    break;
                case 35:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _player))
                        Talk(TALK_7, player);
                    break;
                case 40:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _player))
                        player->GroupEventHappens(QUEST_TRAIL_OF_FIRE, me);
                    events.ScheduleEvent(EVENT_TALK_8, Seconds(4));
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_Apothecary_HanesAI(creature);
    }
};

/*######
## npc_plaguehound_tracker
######*/

enum Plaguehound
{
    QUEST_SNIFF_OUT_ENEMY        = 11253
};

class npc_plaguehound_tracker : public CreatureScript
{
public:
    npc_plaguehound_tracker() : CreatureScript("npc_plaguehound_tracker") { }

    struct npc_plaguehound_trackerAI : public npc_escortAI
    {
        npc_plaguehound_trackerAI(Creature* creature) : npc_escortAI(creature) { }

        void Reset() override
        {
            ObjectGuid summonerGUID;

            if (me->IsSummon())
                if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                    if (summoner->GetTypeId() == TYPEID_PLAYER)
                        summonerGUID = summoner->GetGUID();

            if (!summonerGUID)
                return;

            me->SetWalk(true);
            Start(false, false, summonerGUID);
        }

        void WaypointReached(uint32 waypointId) override
        {
            if (waypointId != 26)
                return;

            me->DespawnOrUnsummon();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_plaguehound_trackerAI(creature);
    }
};

/*######
## npc_razael_and_lyana
######*/

#define GOSSIP_RAZAEL_REPORT "High Executor Anselm wants a report on the situation."
#define GOSSIP_LYANA_REPORT "High Executor Anselm requests your report."

enum Razael
{
    QUEST_REPORTS_FROM_THE_FIELD = 11221,
    NPC_RAZAEL = 23998,
    NPC_LYANA = 23778,
    GOSSIP_TEXTID_RAZAEL1 = 11562,
    GOSSIP_TEXTID_RAZAEL2 = 11564,
    GOSSIP_TEXTID_LYANA1 = 11586,
    GOSSIP_TEXTID_LYANA2 = 11588
};

class npc_razael_and_lyana : public CreatureScript
{
public:
    npc_razael_and_lyana() : CreatureScript("npc_razael_and_lyana") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_REPORTS_FROM_THE_FIELD) == QUEST_STATUS_INCOMPLETE)
            switch (creature->GetEntry())
            {
                case NPC_RAZAEL:
                    if (!player->GetReqKillOrCastCurrentCount(QUEST_REPORTS_FROM_THE_FIELD, NPC_RAZAEL))
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_RAZAEL_REPORT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        SendGossipMenuFor(player, GOSSIP_TEXTID_RAZAEL1, creature->GetGUID());
                        return true;
                    }
                break;
                case NPC_LYANA:
                    if (!player->GetReqKillOrCastCurrentCount(QUEST_REPORTS_FROM_THE_FIELD, NPC_LYANA))
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_LYANA_REPORT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        SendGossipMenuFor(player, GOSSIP_TEXTID_LYANA1, creature->GetGUID());
                        return true;
                    }
                break;
            }
        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF + 1:
                SendGossipMenuFor(player, GOSSIP_TEXTID_RAZAEL2, creature->GetGUID());
                player->TalkedToCreature(NPC_RAZAEL, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                SendGossipMenuFor(player, GOSSIP_TEXTID_LYANA2, creature->GetGUID());
                player->TalkedToCreature(NPC_LYANA, creature->GetGUID());
                break;
        }
        return true;
    }
};

/*######
## npc_daegarn
######*/

enum Daegarnn
{
    QUEST_DEFEAT_AT_RING            = 11300,

    NPC_FIRJUS                      = 24213,
    NPC_JLARBORN                    = 24215,
    NPC_YOROS                       = 24214,
    NPC_OLUF                        = 23931,

    NPC_PRISONER_1                  = 24253,  // looks the same but has different abilities
    NPC_PRISONER_2                  = 24254,
    NPC_PRISONER_3                  = 24255,
};

static float afSummon[] = {838.81f, -4678.06f, -94.182f};
static float afCenter[] = {801.88f, -4721.87f, -96.143f};

class npc_daegarn : public CreatureScript
{
public:
    npc_daegarn() : CreatureScript("npc_daegarn") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest) override
    {
        if (quest->GetQuestId() == QUEST_DEFEAT_AT_RING)
        {
            if (npc_daegarnAI* pDaegarnAI = CAST_AI(npc_daegarn::npc_daegarnAI, creature->AI()))
                pDaegarnAI->StartEvent(player->GetGUID());
        }

        return true;
    }

    /// @todo make prisoners help (unclear if summoned or using npc's from surrounding cages (summon inside small cages?))
    struct npc_daegarnAI : public ScriptedAI
    {
        npc_daegarnAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            bEventInProgress = false;
            uiPlayerGUID.Clear();
        }

        bool bEventInProgress;
        ObjectGuid uiPlayerGUID;

        void Reset() override
        {
            Initialize();
        }

        void StartEvent(ObjectGuid uiGUID)
        {
            if (bEventInProgress)
                return;

            uiPlayerGUID = uiGUID;

            SummonGladiator(NPC_FIRJUS);
        }

        void JustSummoned(Creature* summon) override
        {
            if (Player* player = ObjectAccessor::GetPlayer(*me, uiPlayerGUID))
            {
                if (player->IsAlive())
                {
                    summon->SetWalk(false);
                    summon->GetMotionMaster()->MovePoint(0, afCenter[0], afCenter[1], afCenter[2]);
                    summon->AI()->AttackStart(player);
                    return;
                }
            }

            Reset();
        }

        void SummonGladiator(uint32 uiEntry)
        {
            me->SummonCreature(uiEntry, afSummon[0], afSummon[1], afSummon[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30*IN_MILLISECONDS);
        }

        void SummonedCreatureDies(Creature* summoned, Unit* /*killer*/) override
        {
            uint32 uiEntry = 0;

            // will eventually reset the event if something goes wrong
            switch (summoned->GetEntry())
            {
                case NPC_FIRJUS:    uiEntry = NPC_JLARBORN; break;
                case NPC_JLARBORN:  uiEntry = NPC_YOROS;    break;
                case NPC_YOROS:     uiEntry = NPC_OLUF;     break;
                case NPC_OLUF:      Reset();                return;
            }

            SummonGladiator(uiEntry);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_daegarnAI(creature);
    }
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
            events.ScheduleEvent(EVENT_CHECK_CHARMED, 1000);
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
                            events.ScheduleEvent(EVENT_CHECK_CHARMED, 1000);
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

                caster->DespawnOrUnsummon(4000);
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

enum SummonSpells
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
    SPELL_SUMMON_FREED_MIST_WHISPER_SCOUT = 43289,
    NPC_MIST_WHISPER_SCOUT                = 24211
};

const uint32 rivenWidowCocoonVictims[11] =
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

class npc_riven_widow_cocoon : public CreatureScript
{
public:
    npc_riven_widow_cocoon() : CreatureScript("npc_riven_widow_cocoon") { }

    struct npc_riven_widow_cocoonAI : public ScriptedAI
    {
        npc_riven_widow_cocoonAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override { }
        void EnterCombat(Unit* /*who*/) override { }
        void MoveInLineOfSight(Unit* /*who*/) override { }

        void JustDied(Unit* killer) override
        {
            Player* player = killer->ToPlayer();

            if (!player)
                return;

            if (roll_chance_i(20))
            {
                player->CastSpell(me, SPELL_SUMMON_FREED_MIST_WHISPER_SCOUT, true);
                player->KilledMonsterCredit(NPC_MIST_WHISPER_SCOUT);
            }
            else
                player->CastSpell(me, rivenWidowCocoonVictims[urand(0, 10)], true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_riven_widow_cocoonAI(creature);
    }
};

void AddSC_howling_fjord()
{
    new npc_apothecary_hanes();
    new npc_plaguehound_tracker();
    new npc_razael_and_lyana();
    new npc_daegarn();
    new npc_mindless_abomination();
    new spell_mindless_abomination_explosion_fx_master();
    new npc_riven_widow_cocoon();
 }
