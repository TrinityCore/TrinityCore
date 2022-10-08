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

#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "ScriptedEscortAI.h"

#include "Creature.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "CreatureAI.h"
#include "ScriptedGossip.h"
#include "Pet.h"
#include "PetAI.h"
#include "Log.h"

enum ZuldazarQuests
{
    QUEST_WELCOME_ZULDAZAR      = 46957,
    QUEST_RASTAKHAN             = 46930,
    QUEST_SPEAKER_OF_THE_HORDE  = 46931,
    OBJECTIVE_SUMMON_THE_HORDE  = 291969,
    QUEST_NEED_EACH_OTHER       = 52131,
    QUEST_SEND_THE_FLEET_HORDE = 56044,
    QUEST_RIDE_OF_THE_ZANDALARI = 54140,
};

enum ZuldazarSpells
{
    SPELL_TALANJI_EXPOSITION_CONVERSATION_1 = 261541,
    SPELL_TALANJI_EXPOSITION_CONVERSATION_2 = 261549,
    SPELL_TALANJI_EXPOSITION_KILL_CREDIT    = 265711,

    SPELL_RASTAKHAN_GREETINGS_SCENE         = 244534,

    SPELL_PREVIEW_TO_ZANDALAR               = 273387,
};

enum ZuldazarNpcs
{
    NPC_ZOLANI                      = 135441,
    NPC_FOLLOW_ZOLANI_KILL_CREDIT   = 120169,
};

// 132332
struct npc_talanji_arrival : public ScriptedAI
{
    npc_talanji_arrival(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->ID == QUEST_WELCOME_ZULDAZAR)
        {
            me->DestroyForPlayer(player);
            player->SummonCreature(132661, me->GetPosition());
        }
    }
};

// 132661
struct npc_talanji_arrival_escort : public npc_escortAI
{
    npc_talanji_arrival_escort(Creature* creature) : npc_escortAI(creature) { }

    void Reset() override
    {
        if (Player* player = me->ToPlayer())
        {
            if (!player->HasQuest(QUEST_WELCOME_ZULDAZAR))
            {
                if (player->HasAura(261486))
                    player->RemoveAura(261486);

                me->DespawnOrUnsummon();
            }            
        }
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (Player* player = summoner->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_WELCOME_ZULDAZAR) == QUEST_STATUS_INCOMPLETE)
            {
                me->Mount(80358);
                Start(false, true, summoner->GetGUID());
                SetDespawnAtEnd(false);
                summoner->CastSpell(summoner, SPELL_TALANJI_EXPOSITION_CONVERSATION_1, true);
                summoner->GetScheduler().Schedule(50s, [this, summoner] (TaskContext context)
                {
                    if (Player* player = summoner->ToPlayer())
                    {
                        player->KilledMonsterCredit(132661);
                    }
                });
                me->DespawnOrUnsummon(55s);
            }
        }
    }
};


// 138912
struct npc_enforcer_pterrordax : public npc_escortAI
{
    npc_enforcer_pterrordax(Creature* creature) : npc_escortAI(creature) { }

    void IsSummonedBy(Unit* summoner) override
    {
        Player* player = summoner->ToPlayer();
        if (!player || player->GetQuestStatus(QUEST_RASTAKHAN) != QUEST_STATUS_INCOMPLETE)
        {
            me->ForcedDespawn();
            return;
        }
        me->SetSpeed(MOVE_RUN, 21.f);
        player->EnterVehicle(me);
        player->KilledMonsterCredit(135438);
        Start(false, true, player->GetGUID());
    }
};

struct npc_talanji_135440 : public ScriptedAI
{
    npc_talanji_135440(Creature* c) : ScriptedAI(c) { }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        if (player->GetQuestStatus(QUEST_RASTAKHAN) == QUEST_STATUS_INCOMPLETE)
        {            
            player->KilledMonsterCredit(135440);
            player->GetSceneMgr().PlaySceneByPackageId(1895);
        }
    }
};

// 120740
struct npc_rastakhan_zuldazar_arrival : public ScriptedAI
{
    npc_rastakhan_zuldazar_arrival(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->ID == QUEST_SPEAKER_OF_THE_HORDE)
            player->SummonCreature(NPC_ZOLANI, -1100.689941f, 817.934021f, 497.243011f, 6.062160f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000, true);
    }
};

struct npc_soth_zolani : public npc_escortAI
{
    npc_soth_zolani(Creature* creature) : npc_escortAI(creature) { }

    void sGossipHello(Player* player) override
    {        
        if (player->HasQuest(QUEST_SPEAKER_OF_THE_HORDE))
        {            
            CloseGossipMenuFor(player);
            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            me->SetWalk(true);
            Talk(0);
            me->GetMotionMaster()->MovePoint(1, -1129.335f, 845.836f, 487.865f, true);            
            player->GetScheduler().Schedule(27s, [this, player] (TaskContext context)
            {
                player->KilledMonsterCredit(120169);
                Talk(1);
                me->ForcedDespawn(10000);
            });
        }
    }
};

//121000
struct npc_horde_banner : public ScriptedAI
{
    npc_horde_banner(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->IsPlayer() && unit->GetDistance2d(me) <= 3.0f)
        {
            Player* player = unit->ToPlayer();

            if (player->GetQuestStatus(QUEST_SPEAKER_OF_THE_HORDE) == QUEST_STATUS_INCOMPLETE)
            {
                if (!player->GetQuestObjectiveData(QUEST_SPEAKER_OF_THE_HORDE, 0))
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                    player->AddAura(241211);
                    player->KilledMonsterCredit(121000);
                    me->ForcedDespawn(0, 3s);
                }
            }
        }
    }
};

// 122690
struct npc_brillin_the_beauty : public ScriptedAI
{
    npc_brillin_the_beauty(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
            if (player->GetDistance(me) < 10.f)
                if (player->GetQuestStatus(QUEST_SPEAKER_OF_THE_HORDE) == QUEST_STATUS_INCOMPLETE)
                    if (player->GetQuestObjectiveCounter(OBJECTIVE_SUMMON_THE_HORDE) != 0)
                        KillCreditMe(player);
    }
};

// 130984
struct npc_natal_hakata : public ScriptedAI
{
    npc_natal_hakata(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
            if (player->GetDistance(me) < 10.f)
                if (player->GetQuestStatus(QUEST_SPEAKER_OF_THE_HORDE) == QUEST_STATUS_INCOMPLETE)
                    if (player->GetQuestObjectiveCounter(OBJECTIVE_SUMMON_THE_HORDE) != 0)
                        KillCreditMe(player);
    }
};

// 131443
struct npc_telemancer_oculeth_zuldazar : public ScriptedAI
{
    npc_telemancer_oculeth_zuldazar(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
            if (player->GetDistance(me) < 10.f)
                if (player->GetQuestStatus(QUEST_SPEAKER_OF_THE_HORDE) == QUEST_STATUS_INCOMPLETE)
                    if (player->GetQuestObjectiveCounter(OBJECTIVE_SUMMON_THE_HORDE) != 0)
                        player->KilledMonsterCredit(135435);
    }
};

// 133050
struct npc_talanji_great_seal : public ScriptedAI
{
    npc_talanji_great_seal(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->ID == QUEST_NEED_EACH_OTHER)
            player->CastSpell(player, SPELL_PREVIEW_TO_ZANDALAR, true);
    }
};

//
class npc_ata_the_winglord_offensively_defence : public npc_escortAI
{
public:
    npc_ata_the_winglord_offensively_defence(Creature* creature) : npc_escortAI(creature)
    {
        me->SetCanFly(true);
        me->SetSpeed(MOVE_FLIGHT, 26);
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
        me->SetReactState(REACT_PASSIVE);
    }

    void OnCharmed(bool /*apply*/) override
    {
        // Make sure the basic cleanup of OnCharmed is done to avoid looping problems
        if (me->NeedChangeAI)
            me->NeedChangeAI = false;
    }

    void EnterEvadeMode(EvadeReason /*why*/) override { }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner)
        {
           // me->GetScheduler().Schedule(1s, [this, summoner](TaskContext /*context*/)
           summoner->CastSpell(me, 46598);
        }
    }
    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool /*apply*/) override
    {
        if (Player* player = who->ToPlayer())
            player->KilledMonsterCredit(126822);
        Start(false, true, who->GetGUID());
    }
};

class npc_ata_the_winglord_paku_master_of_winds : public npc_escortAI
{
public:
    npc_ata_the_winglord_paku_master_of_winds(Creature* creature) : npc_escortAI(creature)
    {
        me->SetCanFly(true);
        me->SetSpeed(MOVE_FLIGHT, 26);
        me->SetReactState(REACT_PASSIVE);
    }

    void OnCharmed(bool /*apply*/) override
    {
        // Make sure the basic cleanup of OnCharmed is done to avoid looping problems
        if (me->NeedChangeAI)
            me->NeedChangeAI = false;
    }

    void EnterEvadeMode(EvadeReason /*why*/) override { }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner)
        {
            // me->GetScheduler().Schedule(1s, [this, summoner](TaskContext /*context*/)
            summoner->CastSpell(me, 46598);
        }
    }
    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool /*apply*/) override
    {
        if (Player* player = who->ToPlayer())
            player->KilledMonsterCredit(127414);
        Start(false, true, who->GetGUID());
    }
};

class npc_pterrordax_paku_master_of_winds : public npc_escortAI
{
public:
    npc_pterrordax_paku_master_of_winds(Creature* creature) : npc_escortAI(creature)
    {
        me->SetCanFly(true);
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
    }

    void OnCharmed(bool /*apply*/) override
    {
        // Make sure the basic cleanup of OnCharmed is done to avoid looping problems
        if (me->NeedChangeAI)
            me->NeedChangeAI = false;
    }

    void EnterEvadeMode(EvadeReason /*why*/) override { }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner)
        {
            // me->GetScheduler().Schedule(1s, [this, summoner](TaskContext /*context*/)
            summoner->CastSpell(me, 46598);
            me->SetSpeed(MOVE_RUN, 26);
        }
    }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool /*apply*/) override
    {
        if (Player* player = who->ToPlayer())
            player->KilledMonsterCredit(127512);
        Start(false, true, who->GetGUID());
    }


};

enum Spells
{
    SPELL_CALL_PTERRORDAX = 281048
};

//127377
struct npc_paku : public ScriptedAI
{
    npc_paku(Creature* pCreature) : ScriptedAI(pCreature)
    {
    }

    void sGossipHello(Player* player) override
    {
        player->KilledMonsterCredit(127377);
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        std::list<Player*> players;
        me->GetPlayerListInGrid(players, 75.0f);

        for (Player* player : players)
        {
            if (player->GetPositionZ() <= 400 && !player->IsMounted() && !player->IsOnVehicle() && player->HasQuest(47440))
            {
                Talk(0);
                player->CastSpell(player, SPELL_CALL_PTERRORDAX);
            }
        }
    }
};
//263018
class spell_rastari_skull_whistle : public SpellScript
{
	PrepareSpellScript(spell_rastari_skull_whistle);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;
        Player* player = caster->ToPlayer();
        if (!player)
            return;

        if (Creature* creatureTarget = GetHitCreature())
        {
            int entry = creatureTarget->GetEntry();
            if (entry == 129204 || entry == 129205 || entry == 129203 || entry == 128963)
            {
                player->KilledMonsterCredit(128963);
                creatureTarget->AI()->Talk(0);
                creatureTarget->HandleEmoteCommand(113);
                creatureTarget->ForcedDespawn(2000);
            }
        }
    }

	void Register() override
	{
		OnEffectHitTarget += SpellEffectFn(spell_rastari_skull_whistle::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
	}
};

// 254904 - Revitalize Spirit Obelisk
class spell_quest_revitalize_spirit_obelisk : public SpellScript
{
    PrepareSpellScript(spell_quest_revitalize_spirit_obelisk);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;
        Player* player = caster->ToPlayer();
        if (!player)
            return;

        if (Creature* creatureTarget = GetHitCreature())
        {
            if (creatureTarget->GetEntry() == 128468 && creatureTarget->IsAlive())
            {
                player->KilledMonsterCredit(128468);
                player->CastSpell(nullptr, 254931, true);
                creatureTarget->KillSelf();
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_quest_revitalize_spirit_obelisk::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// todo fix the positions and amount of spells 224839
class spell_call_the_storm : public SpellScript
{
    PrepareSpellScript(spell_call_the_storm);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, 224842, TRIGGERED_CAN_CAST_WHILE_CASTING_MASK);
        caster->CastSpell(caster->GetPositionWithDistInOrientation(5, 1.6f), 224846, TRIGGERED_CAN_CAST_WHILE_CASTING_MASK);
        caster->CastSpell(caster->GetPositionWithDistInOrientation(5, 0.5f), 224842, TRIGGERED_CAN_CAST_WHILE_CASTING_MASK);
        caster->CastSpell(caster->GetPositionWithDistInOrientation(5, 0), 224842, TRIGGERED_CAN_CAST_WHILE_CASTING_MASK);
        caster->CastSpell(caster->GetPositionWithDistInOrientation(5, 3), 224842, TRIGGERED_CAN_CAST_WHILE_CASTING_MASK);

    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_call_the_storm::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 260075
class spell_lightning_rod : public SpellScriptLoader
{
public:
    spell_lightning_rod() : SpellScriptLoader("spell_lightning_rod") { }

    class spell_lightning_rod_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_lightning_rod_AuraScript);

        void HandlePeriodicDummy(AuraEffect const* /*auraEff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            Unit* target = GetTarget();
            if (!target)
                return;

            caster->CastSpell(target, 260073, TRIGGERED_CAN_CAST_WHILE_CASTING_MASK);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_lightning_rod_AuraScript::HandlePeriodicDummy, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_lightning_rod_AuraScript();
    }

};

enum PlotTwist {
    SPELL_CHANNEL = 259228,
    EVENT_SOUL_BLAST = 1,
    SPEll_SOUL_BLAST = 260572,
    EVENT_SUMMON_MASK = 2,
    SPELL_SUMMON_MASKS = 260577,
    EVENT_SOUL_JAUNT = 3,
    SPELL_SOUL_JAUNT = 264007,
    EVENT_GONG = 4,
    //SPELL_GONK = ,
    EVENT_POTION = 5,
    SPELL_POTION = 272315,
    EVENT_URN = 6,
};

struct npc_voljamba : public ScriptedAI
{
    npc_voljamba(Creature* pCreature) : ScriptedAI(pCreature)
    {
    }

    void Reset() override
    {
        me->CastSpell(nullptr, SPELL_CHANNEL);
        gong = false;
        potion = false;
        final = false;
    }


    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_SOUL_BLAST, 2000);
        events.ScheduleEvent(EVENT_SUMMON_MASK, 9000);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

       // if (me->HasUnitState(UNIT_STATE_CASTING))
       //     return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_SOUL_BLAST:
                DoCastVictim(SPEll_SOUL_BLAST);
                events.ScheduleEvent(EVENT_SOUL_BLAST, urand(4000, 9000));
                break;
            case EVENT_SUMMON_MASK:
                DoCast(SPELL_SUMMON_MASKS);
                events.ScheduleEvent(EVENT_SUMMON_MASK, urand(15000, 20000));
                break;
            case EVENT_GONG:
                Talk(1);
                break;
            case EVENT_POTION:
                Talk(3);
                break;
            default:
                break;
            }
        }
        DoMeleeAttackIfReady();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->GetHealthPct() <= 80 && !gong)
        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                me->InterruptNonMeleeSpells(false);
            DoCast(SPELL_SOUL_JAUNT);
            gong = true;
        }

        if (me->GetHealthPct() <= 60 && !potion)
        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                me->InterruptNonMeleeSpells(false);
            DoCast(SPELL_SOUL_JAUNT);
            potion = true;
        }

        if (damage >= me->GetHealth())
        {
            damage = 0;
            if (!final)
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    me->InterruptNonMeleeSpells(false);
                Talk(4);
                DoCast(SPELL_SOUL_JAUNT);
                final = true;
            }
        }
    }

    void DoAction(int32 param) override
    {
        if (param == 1)
        {
            if (gong && !potion && !final)
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    me->InterruptNonMeleeSpells(false);
                me->NearTeleportTo(-372.1f, 133.543f, 257.2f, 3.481f);
                Talk(0);
            }
            if (gong && potion && !final)
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    me->InterruptNonMeleeSpells(false);
                me->NearTeleportTo(-384.489f, 161.891f, 257.51f, 3.4f);
                Talk(2);
                DoCast(SPELL_POTION);
                events.ScheduleEvent(EVENT_POTION, 1500);
            }
            if (gong && potion && final)
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    me->InterruptNonMeleeSpells(false);
                me->NearTeleportTo(-351.645f, 136.92f, 257.11f, 5.31f);
                me->KillSelf();

                std::list<Player*> players;
                me->GetPlayerListInGrid(players, 50.0f);

                for (Player* player : players)
                {
                    player->KilledMonsterCredit(131241);
                }
            }
        }
    }


private:
    bool gong;
    bool potion;
    bool final;
};

//264007
class spell_soul_jaunt : public SpellScript
{
    PrepareSpellScript(spell_soul_jaunt);

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Creature* creature = caster->ToCreature())
            creature->AI()->DoAction(1);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_soul_jaunt::HandleAfterCast);
    }
};

class scene_warpack : public SceneScript
{
public:
    scene_warpack() : SceneScript("scene_warpack") { }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName)
    {
        if (triggerName == "Charge")
        {
            if (Creature* loti = player->FindNearestCreature(134132, 5))
            {
                loti->AI()->SetData(0, 1);
            }
        }
    }
};

//123000
class npc_captain_rezokon_123000 : public CreatureScript
{
public:
    npc_captain_rezokon_123000() : CreatureScript("npc_captain_rezokon_123000") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Let's go.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 0);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "The Kul Tiran fleet is off the coast of Nazmir, get the fleet mobilized and attack them", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        SendGossipMenuFor(player, 22557, creature->GetGUID());

        player->PrepareQuestMenu(creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action) override
    {
        if (action == GOSSIP_ACTION_INFO_DEF + 0 && player->HasQuest(QUEST_SEND_THE_FLEET_HORDE))  //Let's go.
        {
            player->SendMovieStart(919);
            player->TeleportTo(1718, 107.0f, 29.0f, -30.0f, 0.33f);
        }
        if (action == GOSSIP_ACTION_INFO_DEF + 1 && !player->GetQuestObjectiveData(QUEST_RIDE_OF_THE_ZANDALARI, 0))
        {
            player->KilledMonsterCredit(146830);
        }
        return true;
    }
};

//146812
struct npc_rakera_146812 : public ScriptedAI
{
    npc_rakera_146812(Creature* c) : ScriptedAI(c) { }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        if (!player->GetQuestObjectiveData(QUEST_RIDE_OF_THE_ZANDALARI, 1))
            player->KilledMonsterCredit(146812);
    }
};

//146851
struct npc_hexlord_146851 : public ScriptedAI
{
    npc_hexlord_146851(Creature* c) : ScriptedAI(c) { }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        if (!player->GetQuestObjectiveData(QUEST_RIDE_OF_THE_ZANDALARI, 2))
        {
            player->KilledMonsterCredit(146851);
            me->AI()->Talk(0);
        }
    }
};

//135690
class npc_dread_admiral_tattersail_135690 : public CreatureScript
{
public:
    npc_dread_admiral_tattersail_135690() : CreatureScript("npc_dread_admiral_tattersail_135690") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {       
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Set sail for Drustvar.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 0);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Set sail for Stormsong Valley.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Set sail for Tiragarde Sound.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        SendGossipMenuFor(player, 34711, creature->GetGUID());

        player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetAreaId() == 9699)
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Take us back to Zuldazar.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            SendGossipMenuFor(player, 34711, creature->GetGUID());
            player->PrepareQuestMenu(creature->GetGUID());
        }

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action) override
    {
        if (action == GOSSIP_ACTION_INFO_DEF + 0)   //Set sail for Drustvar.
        {
            player->TeleportTo(1643, -406.0f, 4122.0f, 4.08f, 4.24f);
        }
        if (action == GOSSIP_ACTION_INFO_DEF + 1)   //Set sail for Stormsong Valley.
        {            
            player->TeleportTo(1643, 4246.0f, 406.0f, 0.58f, 2.51f);
        }
        if (action == GOSSIP_ACTION_INFO_DEF + 2)   //Set sail for Tiragarde Sound.
        {            
            player->TeleportTo(1643, -218.0f, -1554.0f, 2.83f, 0.76f);
        }
        if (action == GOSSIP_ACTION_INFO_DEF + 3)   //Take us back to Zuldazar.
        {
            player->TeleportTo(1642, -2141.0f, 775.0f, 9.0f, 1.59f);
        }
        return true;
    }
};

void AddSC_zone_zuldazar()
{
    RegisterCreatureAI(npc_talanji_arrival);
    RegisterCreatureAI(npc_talanji_arrival_escort);
    RegisterCreatureAI(npc_enforcer_pterrordax);
    RegisterCreatureAI(npc_talanji_135440);
    RegisterCreatureAI(npc_rastakhan_zuldazar_arrival);
    RegisterCreatureAI(npc_soth_zolani);
    RegisterCreatureAI(npc_brillin_the_beauty);
    RegisterCreatureAI(npc_horde_banner);
    RegisterCreatureAI(npc_natal_hakata);
    RegisterCreatureAI(npc_telemancer_oculeth_zuldazar);
    RegisterCreatureAI(npc_talanji_great_seal);
    RegisterCreatureAI(npc_ata_the_winglord_offensively_defence);
    RegisterCreatureAI(npc_ata_the_winglord_paku_master_of_winds);
    RegisterCreatureAI(npc_pterrordax_paku_master_of_winds);
    RegisterCreatureAI(npc_paku);
    RegisterSpellScript(spell_rastari_skull_whistle);
    RegisterSpellScript(spell_quest_revitalize_spirit_obelisk);
    RegisterSpellScript(spell_call_the_storm);
    new spell_lightning_rod();
    RegisterCreatureAI(npc_voljamba);
    RegisterSpellScript(spell_soul_jaunt);
    new scene_warpack();
    new npc_captain_rezokon_123000();
    RegisterCreatureAI(npc_rakera_146812);
    RegisterCreatureAI(npc_hexlord_146851);
    new npc_dread_admiral_tattersail_135690();
}
