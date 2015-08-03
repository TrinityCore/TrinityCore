/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Player.h"
#include "SpellInfo.h"
#include "SpellScript.h"

/*######
## npc_apothecary_hanes
######*/
enum Entries
{
    NPC_APOTHECARY_HANES         = 23784,
    FACTION_ESCORTEE_A           = 774,
    FACTION_ESCORTEE_H           = 775,
    NPC_HANES_FIRE_TRIGGER       = 23968,
    QUEST_TRAIL_OF_FIRE          = 11241,
    SPELL_COSMETIC_LOW_POLY_FIRE = 56274,
    SPELL_HEALING_POTION         = 17534
};

class npc_apothecary_hanes : public CreatureScript
{
public:
    npc_apothecary_hanes() : CreatureScript("npc_apothecary_hanes") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_TRAIL_OF_FIRE)
        {
            switch (player->GetTeam())
            {
                case ALLIANCE:
                    creature->setFaction(FACTION_ESCORTEE_A);
                    break;
                case HORDE:
                    creature->setFaction(FACTION_ESCORTEE_H);
                    break;
            }
            ENSURE_AI(npc_escortAI, (creature->AI()))->Start(true, false, player->GetGUID());
        }
        return true;
    }

    struct npc_Apothecary_HanesAI : public npc_escortAI
    {
        npc_Apothecary_HanesAI(Creature* creature) : npc_escortAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            PotTimer = 10000; //10 sec cooldown on potion
        }

        uint32 PotTimer;

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

        void UpdateEscortAI(const uint32 diff) override
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
        }

        void WaypointReached(uint32 waypointId) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 1:
                    me->SetReactState(REACT_AGGRESSIVE);
                    SetRun(true);
                    break;
                case 23:
                    player->GroupEventHappens(QUEST_TRAIL_OF_FIRE, me);
                    me->DespawnOrUnsummon();
                    break;
                case 5:
                    if (Unit* Trigger = me->FindNearestCreature(NPC_HANES_FIRE_TRIGGER, 10.0f))
                        Trigger->CastSpell(Trigger, SPELL_COSMETIC_LOW_POLY_FIRE, false);
                    SetRun(false);
                    break;
                case 6:
                    if (Unit* Trigger = me->FindNearestCreature(NPC_HANES_FIRE_TRIGGER, 10.0f))
                        Trigger->CastSpell(Trigger, SPELL_COSMETIC_LOW_POLY_FIRE, false);
                    SetRun(true);
                    break;
                case 8:
                    if (Unit* Trigger = me->FindNearestCreature(NPC_HANES_FIRE_TRIGGER, 10.0f))
                        Trigger->CastSpell(Trigger, SPELL_COSMETIC_LOW_POLY_FIRE, false);
                    SetRun(false);
                    break;
                case 9:
                    if (Unit* Trigger = me->FindNearestCreature(NPC_HANES_FIRE_TRIGGER, 10.0f))
                        Trigger->CastSpell(Trigger, SPELL_COSMETIC_LOW_POLY_FIRE, false);
                    break;
                case 10:
                    SetRun(true);
                    break;
                case 13:
                    SetRun(false);
                    break;
                case 14:
                    if (Unit* Trigger = me->FindNearestCreature(NPC_HANES_FIRE_TRIGGER, 10.0f))
                        Trigger->CastSpell(Trigger, SPELL_COSMETIC_LOW_POLY_FIRE, false);
                    SetRun(true);
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
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_RAZAEL_REPORT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_RAZAEL1, creature->GetGUID());
                        return true;
                    }
                break;
                case NPC_LYANA:
                    if (!player->GetReqKillOrCastCurrentCount(QUEST_REPORTS_FROM_THE_FIELD, NPC_LYANA))
                    {
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LYANA_REPORT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_LYANA1, creature->GetGUID());
                        return true;
                    }
                break;
            }
        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF + 1:
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_RAZAEL2, creature->GetGUID());
                player->TalkedToCreature(NPC_RAZAEL, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_LYANA2, creature->GetGUID());
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
                if (!sSpellMgr->GetSpellInfo(SPELL_RANDOM_CIRCUMFERENCE_POINT_POISON) || !sSpellMgr->GetSpellInfo(SPELL_COSMETIC_BLOOD_EXPLOSION_GREEN_LARGE))
                    return false;
                return true;
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

void AddSC_howling_fjord()
{
    new npc_apothecary_hanes();
    new npc_plaguehound_tracker();
    new npc_razael_and_lyana();
    new npc_daegarn();
    new npc_mindless_abomination();
    new spell_mindless_abomination_explosion_fx_master();
 }
