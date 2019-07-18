/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "CreatureAIImpl.h"
#include "GameObject.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QuestDef.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "WorldSession.h"

/*######
## npc_sinkhole_kill_credit
######*/

enum Sinkhole
{
    GO_EXPLOSIVES_CART            = 188160,
    NPC_SCOURGED_BURROWER         = 26250,
    QUEST_PLUG_THE_SINKHOLES      = 11897,
    SPELL_SET_CART                = 46797,
    SPELL_EXPLODE_CART            = 46799,
    SPELL_SUMMON_CART             = 46798,
    SPELL_SUMMON_WORM             = 46800
};

class npc_sinkhole_kill_credit : public CreatureScript
{
public:
    npc_sinkhole_kill_credit() : CreatureScript("npc_sinkhole_kill_credit") { }

    struct npc_sinkhole_kill_creditAI : public ScriptedAI
    {
        npc_sinkhole_kill_creditAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            phaseTimer = 500;
            phase = 0;
            casterGuid.Clear();
        }

        uint32 phaseTimer;
        uint8  phase;
        ObjectGuid casterGuid;

        void Reset() override
        {
            Initialize();
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            if (phase || spell->Id != SPELL_SET_CART)
                return;

            Player* player = caster->ToPlayer();
            if (player && player->GetQuestStatus(QUEST_PLUG_THE_SINKHOLES) == QUEST_STATUS_INCOMPLETE)
            {
                phase = 1;
                casterGuid = caster->GetGUID();
            }
        }

        void JustEngagedWith(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (!phase)
                return;

            if (phaseTimer <= diff)
            {
                switch (phase)
                {
                    case 1:
                        DoCast(me, SPELL_EXPLODE_CART, true);
                        DoCast(me, SPELL_SUMMON_CART, true);
                        if (GameObject* cart = me->FindNearestGameObject(GO_EXPLOSIVES_CART, 3.0f))
                            cart->SetFaction(FACTION_MONSTER);
                        phaseTimer = 3000;
                        phase = 2;
                        break;
                    case 2:
                        if (GameObject* cart = me->FindNearestGameObject(GO_EXPLOSIVES_CART, 3.0f))
                            cart->UseDoorOrButton();
                        DoCast(me, SPELL_EXPLODE_CART, true);
                        phaseTimer = 3000;
                        phase = 3;
                        break;
                    case 3:
                        DoCast(me, SPELL_EXPLODE_CART, true);
                        phaseTimer = 2000;
                        phase = 5; // @fixme: phase 4 is missing...
                        break;
                    case 5:
                        DoCast(me, SPELL_SUMMON_WORM, true);
                        if (Unit* worm = me->FindNearestCreature(NPC_SCOURGED_BURROWER, 3.0f))
                        {
                            worm->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            worm->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
                        }
                        phaseTimer = 1000;
                        phase = 6;
                        break;
                    case 6:
                        DoCast(me, SPELL_EXPLODE_CART, true);
                        if (Unit* worm = me->FindNearestCreature(NPC_SCOURGED_BURROWER, 3.0f))
                        {
                            Unit::Kill(me, worm);
                            worm->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                        }
                        phaseTimer = 2000;
                        phase = 7;
                        break;
                    case 7:
                        DoCast(me, SPELL_EXPLODE_CART, true);
                        if (Player* caster = ObjectAccessor::GetPlayer(*me, casterGuid))
                            caster->KilledMonster(me->GetCreatureTemplate(), me->GetGUID());
                        phaseTimer = 5000;
                        phase = 8;
                        break;
                    case 8:
                        EnterEvadeMode();
                        break;
                }
            } else phaseTimer -= diff;

        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sinkhole_kill_creditAI(creature);
    }
};

/*######
## npc_khunok_the_behemoth
######*/

enum Khunok
{
    NPC_ORPHANED_MAMMOTH_CALF        = 25861,
    SPELL_MAMMOTH_CALF_ESCORT_CREDIT = 46231
};

class npc_khunok_the_behemoth : public CreatureScript
{
public:
    npc_khunok_the_behemoth() : CreatureScript("npc_khunok_the_behemoth") { }

    struct npc_khunok_the_behemothAI : public ScriptedAI
    {
        npc_khunok_the_behemothAI(Creature* creature) : ScriptedAI(creature) { }

        void MoveInLineOfSight(Unit* who) override

        {
            ScriptedAI::MoveInLineOfSight(who);

            if (who->GetTypeId() != TYPEID_UNIT)
                return;

            if (who->GetEntry() == NPC_ORPHANED_MAMMOTH_CALF && me->IsWithinDistInMap(who, 10.0f))
            {
                if (Unit* owner = who->GetOwner())
                {
                    if (owner->GetTypeId() == TYPEID_PLAYER)
                    {
                        owner->CastSpell(owner, SPELL_MAMMOTH_CALF_ESCORT_CREDIT, true);
                        who->ToCreature()->DespawnOrUnsummon();
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_khunok_the_behemothAI(creature);
    }
};

/*######
## npc_corastrasza
######*/

enum Corastrasza
{
    GOSSIP_MENU_ID_CORASTRASZA            = 10204,
    GOSSIP_MENU_ITEM_ID_I_I_THINK_SO      = 0,
    GOSSIP_MENU_ITEM_ID_I_AM_READY        = 1,

    NPC_TEXT_MOST_DRAGONS_WOULD_FEAR_TO   = 14168,
    NPC_TEXT_DO_YOU_POSSESS_THE_COURAGE   = 14169,
    NPC_TEXT_EAGERLY_AWAITING_YOUR_RETURN = 14170,

    QUEST_ACES_HIGH                       = 13413,
    QUEST_ACES_HIGH_DAILY                 = 13414,

    SPELL_SUMMON_WYRMREST_SKYTALON        = 61240,
    SPELL_WYRMREST_SKYTALON_RIDE_PERIODIC = 61244
};

class npc_corastrasza : public CreatureScript
{
public:
    npc_corastrasza() : CreatureScript("npc_corastrasza") { }

    struct npc_corastraszaAI : public ScriptedAI
    {
        npc_corastraszaAI(Creature* creature) : ScriptedAI(creature) { }

        bool GossipHello(Player* player) override
        {
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            if (player->GetQuestStatus(QUEST_ACES_HIGH) == QUEST_STATUS_INCOMPLETE)
            {
                AddGossipItemFor(player, GOSSIP_MENU_ID_CORASTRASZA, GOSSIP_MENU_ITEM_ID_I_I_THINK_SO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, NPC_TEXT_DO_YOU_POSSESS_THE_COURAGE, me->GetGUID());
            }
            else if (player->GetQuestStatus(QUEST_ACES_HIGH_DAILY) == QUEST_STATUS_INCOMPLETE)
            {
                AddGossipItemFor(player, GOSSIP_MENU_ID_CORASTRASZA, GOSSIP_MENU_ITEM_ID_I_AM_READY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, NPC_TEXT_EAGERLY_AWAITING_YOUR_RETURN, me->GetGUID());
            }
            SendGossipMenuFor(player, NPC_TEXT_MOST_DRAGONS_WOULD_FEAR_TO, me->GetGUID());

            return true;
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);
                player->CastSpell(player, SPELL_SUMMON_WYRMREST_SKYTALON, true);
                player->CastSpell(player, SPELL_WYRMREST_SKYTALON_RIDE_PERIODIC, true);
            }

            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_corastraszaAI(creature);
    }
};

/*######
## npc_iruk
######*/

enum Iruk
{
    GOSSIP_MENU_ID_NPC_IRUK        = 9280,
    GOSSIP_OPTION_SEARCH_CORPSE    = 0,
    NPC_TEXT_THIS_YOUNG_TUSKARR    = 12585,

    QUEST_SPIRITS_WATCH_OVER_US    = 11961,

    SPELL_CREATE_TOTEM_OF_ISSLIRUK = 46816
};

class npc_iruk : public CreatureScript
{
public:
    npc_iruk() : CreatureScript("npc_iruk") { }

    struct npc_irukAI : public ScriptedAI
    {
        npc_irukAI(Creature* creature) : ScriptedAI(creature) { }

        bool GossipHello(Player* player) override
        {
            if (player->GetQuestStatus(QUEST_SPIRITS_WATCH_OVER_US) == QUEST_STATUS_INCOMPLETE)
                AddGossipItemFor(player, GOSSIP_MENU_ID_NPC_IRUK, GOSSIP_OPTION_SEARCH_CORPSE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            SendGossipMenuFor(player, NPC_TEXT_THIS_YOUNG_TUSKARR, me->GetGUID());
            return true;
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                player->CastSpell(player, SPELL_CREATE_TOTEM_OF_ISSLIRUK, true);
                CloseGossipMenuFor(player);
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_irukAI(creature);
    }
};

/*######
## npc_nerubar_victim
######*/

enum Nerubar
{
    NPC_WARSONG_PEON                        = 25270,
    QUEST_TAKEN_BY_THE_SCOURGE              = 11611,
    SPELL_FREED_WARSONG_MAGE                = 45526,
    SPELL_FREED_WARSONG_SHAMAN              = 45527,
    SPELL_FREED_WARSONG_WARRIOR             = 45514,
    SPELL_FREED_WARSONG_PEON                = 45532
};

const uint32 nerubarVictims[3] =
{
    SPELL_FREED_WARSONG_MAGE, SPELL_FREED_WARSONG_SHAMAN, SPELL_FREED_WARSONG_WARRIOR
};

class npc_nerubar_victim : public CreatureScript
{
public:
    npc_nerubar_victim() : CreatureScript("npc_nerubar_victim") { }

    struct npc_nerubar_victimAI : public ScriptedAI
    {
        npc_nerubar_victimAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override { }
        void JustEngagedWith(Unit* /*who*/) override { }
        void MoveInLineOfSight(Unit* /*who*/) override { }


        void JustDied(Unit* killer) override
        {
            if (!killer || killer->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = killer->ToPlayer();

            if (player->GetQuestStatus(QUEST_TAKEN_BY_THE_SCOURGE) == QUEST_STATUS_INCOMPLETE)
            {
                uint8 uiRand = urand(0, 99);
                if (uiRand < 25)
                {
                    player->CastSpell(me, SPELL_FREED_WARSONG_PEON, true);
                    player->KilledMonsterCredit(NPC_WARSONG_PEON);
                }
                else if (uiRand < 75)
                    player->CastSpell(me, nerubarVictims[urand(0, 2)], true);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_nerubar_victimAI(creature);
    }
};

enum NesingwaryTrapper
{
    NPC_NESINGWARY_TRAPPER = 25835,

    GO_HIGH_QUALITY_FUR = 187983,

    GO_CARIBOU_TRAP_1   = 187982,
    GO_CARIBOU_TRAP_2   = 187995,
    GO_CARIBOU_TRAP_3   = 187996,
    GO_CARIBOU_TRAP_4   = 187997,
    GO_CARIBOU_TRAP_5   = 187998,
    GO_CARIBOU_TRAP_6   = 187999,
    GO_CARIBOU_TRAP_7   = 188000,
    GO_CARIBOU_TRAP_8   = 188001,
    GO_CARIBOU_TRAP_9   = 188002,
    GO_CARIBOU_TRAP_10  = 188003,
    GO_CARIBOU_TRAP_11  = 188004,
    GO_CARIBOU_TRAP_12  = 188005,
    GO_CARIBOU_TRAP_13  = 188006,
    GO_CARIBOU_TRAP_14  = 188007,
    GO_CARIBOU_TRAP_15  = 188008,

    SPELL_TRAPPED       = 46104,

    // Texts
    SAY_NESINGWARY_1    = 0
};

#define CaribouTrapsNum 15
const uint32 CaribouTraps[CaribouTrapsNum] =
{
    GO_CARIBOU_TRAP_1, GO_CARIBOU_TRAP_2, GO_CARIBOU_TRAP_3, GO_CARIBOU_TRAP_4, GO_CARIBOU_TRAP_5,
    GO_CARIBOU_TRAP_6, GO_CARIBOU_TRAP_7, GO_CARIBOU_TRAP_8, GO_CARIBOU_TRAP_9, GO_CARIBOU_TRAP_10,
    GO_CARIBOU_TRAP_11, GO_CARIBOU_TRAP_12, GO_CARIBOU_TRAP_13, GO_CARIBOU_TRAP_14, GO_CARIBOU_TRAP_15,
};

class spell_q11865_place_fake_fur : public SpellScript
{
    PrepareSpellScript(spell_q11865_place_fake_fur);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void ActivateGameObject(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GameObject* go = GetHitGObj();
        Player* player = GetCaster()->ToPlayer();

        if (go->FindNearestCreature(NPC_NESINGWARY_TRAPPER, 10.0f, true) || go->FindNearestCreature(NPC_NESINGWARY_TRAPPER, 10.0f, false) || go->FindNearestGameObject(GO_HIGH_QUALITY_FUR, 2.0f))
            return;

        float x, y, z;
        go->GetClosePoint(x, y, z, go->GetCombatReach() / 3, 7.0f);

        go->SummonGameObject(GO_HIGH_QUALITY_FUR, go->GetPosition(), QuaternionData(), 20);
        if (TempSummon* summon = player->SummonCreature(NPC_NESINGWARY_TRAPPER, x, y, z, go->GetOrientation(), TEMPSUMMON_DEAD_DESPAWN, 1000))
        {
            summon->SetVisible(false);
            summon->SetReactState(REACT_PASSIVE);
            summon->SetImmuneToPC(true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q11865_place_fake_fur::ActivateGameObject, EFFECT_0, SPELL_EFFECT_ACTIVATE_OBJECT);
    }
};

class npc_nesingwary_trapper : public CreatureScript
{
public:
    npc_nesingwary_trapper() : CreatureScript("npc_nesingwary_trapper") { }

    struct npc_nesingwary_trapperAI : public ScriptedAI
    {
        npc_nesingwary_trapperAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            me->SetVisible(false);
            phaseTimer = 2500;
            phase = 1;
            go_caribouGUID.Clear();
        }

        ObjectGuid go_caribouGUID;
        uint8  phase;
        uint32 phaseTimer;

        void Reset() override
        {
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override { }
        void MoveInLineOfSight(Unit* /*who*/) override { }


        void JustDied(Unit* /*killer*/) override
        {
            if (GameObject* go_caribou = ObjectAccessor::GetGameObject(*me, go_caribouGUID))
                go_caribou->SetLootState(GO_JUST_DEACTIVATED);

            if (TempSummon* summon = me->ToTempSummon())
                if (summon->IsSummon())
                    if (Unit* temp = summon->GetSummonerUnit())
                        if (Player* player = temp->ToPlayer())
                            player->KilledMonsterCredit(me->GetEntry());

            if (GameObject* go_caribou = ObjectAccessor::GetGameObject(*me, go_caribouGUID))
                go_caribou->SetGoState(GO_STATE_READY);
        }

        void UpdateAI(uint32 diff) override
        {
            if (phaseTimer <= diff)
            {
                switch (phase)
                {
                    case 1:
                        me->SetVisible(true);
                        phaseTimer = 2000;
                        phase = 2;
                        break;
                    case 2:
                        if (GameObject* go_fur = me->FindNearestGameObject(GO_HIGH_QUALITY_FUR, 11.0f))
                            me->GetMotionMaster()->MovePoint(0, go_fur->GetPositionX(), go_fur->GetPositionY(), go_fur->GetPositionZ());
                        phaseTimer = 1500;
                        phase = 3;
                        break;
                    case 3:
                        Talk(SAY_NESINGWARY_1);
                        phaseTimer = 2000;
                        phase = 4;
                        break;
                    case 4:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LOOT);
                        phaseTimer = 1000;
                        phase = 5;
                        break;
                    case 5:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
                        phaseTimer = 500;
                        phase = 6;
                        break;
                    case 6:
                        if (GameObject* go_fur = me->FindNearestGameObject(GO_HIGH_QUALITY_FUR, 11.0f))
                            go_fur->Delete();
                        phaseTimer = 500;
                        phase = 7;
                        break;
                    case 7:
                    {
                        GameObject* go_caribou = nullptr;
                        for (uint8 i = 0; i < CaribouTrapsNum; ++i)
                        {
                            go_caribou = me->FindNearestGameObject(CaribouTraps[i], 5.0f);
                            if (go_caribou)
                            {
                                go_caribou->SetGoState(GO_STATE_ACTIVE);
                                go_caribouGUID = go_caribou->GetGUID();
                                break;
                            }
                        }
                        phase = 8;
                        phaseTimer = 1000;
                    }
                    break;
                    case 8:
                        DoCast(me, SPELL_TRAPPED, true);
                        phase = 0;
                        break;
                }
            } else phaseTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_nesingwary_trapperAI(creature);
    }
};

/*######
## npc_lurgglbr
######*/

enum Lurgglbr
{
    QUEST_ESCAPE_WINTERFIN_CAVERNS      = 11570,

    GO_CAGE                             = 187369,

    SAY_START_1                         = 0,
    SAY_START_2                         = 1,
    SAY_END_1                           = 2,
    SAY_END_2                           = 3
};

class npc_lurgglbr : public CreatureScript
{
public:
    npc_lurgglbr() : CreatureScript("npc_lurgglbr") { }

    struct npc_lurgglbrAI : public EscortAI
    {
        npc_lurgglbrAI(Creature* creature) : EscortAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            IntroTimer = 0;
            IntroPhase = 0;
        }

        uint32 IntroTimer;
        uint32 IntroPhase;

        void Reset() override
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
                Initialize();
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            switch (waypointId)
            {
                case 0:
                    IntroPhase = 1;
                    IntroTimer = 2000;
                    break;
                case 41:
                    SetEscortPaused(true);
                    IntroPhase = 4;
                    IntroTimer = 2000;
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (IntroPhase)
            {
                if (IntroTimer <= diff)
                {
                    switch (IntroPhase)
                    {
                        case 1:
                            if (Player* player = GetPlayerForEscort())
                                Talk(SAY_START_1, player);
                            IntroPhase = 2;
                            IntroTimer = 7500;
                            break;
                        case 2:
                            Talk(SAY_START_2);
                            IntroPhase = 3;
                            IntroTimer = 7500;
                            break;
                        case 3:
                            me->SetReactState(REACT_DEFENSIVE);
                            IntroPhase = 0;
                            IntroTimer = 0;
                            break;
                        case 4:
                            Talk(SAY_END_1);
                            IntroPhase = 5;
                            IntroTimer = 8000;
                            break;
                        case 5:
                            if (Player* player = GetPlayerForEscort())
                                Talk(SAY_END_2, player);
                            IntroPhase = 6;
                            IntroTimer = 2500;
                            break;
                        case 6:
                            if (Player* player = GetPlayerForEscort())
                                player->AreaExploredOrEventHappens(QUEST_ESCAPE_WINTERFIN_CAVERNS);
                            IntroPhase = 7;
                            IntroTimer = 2500;
                            break;
                        case 7:
                            me->DespawnOrUnsummon();
                            IntroPhase = 0;
                            IntroTimer = 0;
                            break;
                    }
                } else IntroTimer -= diff;
            }
            EscortAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_ESCAPE_WINTERFIN_CAVERNS)
            {
                if (GameObject* go = me->FindNearestGameObject(GO_CAGE, 5.0f))
                {
                    go->SetRespawnTime(0);
                    go->UseDoorOrButton(20000);
                }

                Start(true, false, player->GetGUID());

                switch (player->GetTeam())
                {
                    case ALLIANCE:
                        me->SetFaction(FACTION_ESCORTEE_A_PASSIVE);
                        break;
                    default:
                    case HORDE:
                        me->SetFaction(FACTION_ESCORTEE_H_PASSIVE);
                        break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lurgglbrAI(creature);
    }
};

enum red_dragonblood
{
    SPELL_DRAKE_HATCHLING_SUBDUED = 46691,
    SPELL_SUBDUED = 46675
};

class spell_red_dragonblood : public SpellScriptLoader
{
public:
    spell_red_dragonblood() : SpellScriptLoader("spell_red_dragonblood") { }

    class spell_red_dragonblood_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_red_dragonblood_AuraScript);

        void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE || !GetCaster())
                return;

            Creature* owner = GetOwner()->ToCreature();
            owner->RemoveAllAurasExceptType(SPELL_AURA_DUMMY);
            owner->CombatStop(true);
            owner->GetThreatManager().NotifyDisengaged();
            owner->GetMotionMaster()->Clear();
            owner->GetMotionMaster()->MoveFollow(GetCaster(), 4.0f, 0.0f);
            owner->CastSpell(owner, SPELL_SUBDUED, true);
            GetCaster()->CastSpell(GetCaster(), SPELL_DRAKE_HATCHLING_SUBDUED, true);
            owner->SetFaction(35);
            owner->SetImmuneToAll(true);
            owner->DespawnOrUnsummon(3 * MINUTE*IN_MILLISECONDS);
        }

        void Register()
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_red_dragonblood_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_red_dragonblood_AuraScript();
    }
};

/*######
## npc_thassarian
######*/

enum Thassarian
{
    QUEST_LAST_RITES        = 12019,

    SPELL_TRANSFORM_VALANAR = 46753,
    SPELL_STUN              = 46957,
    SPELL_SHADOW_BOLT       = 15537,

    NPC_IMAGE_LICH_KING     = 26203,
    NPC_COUNSELOR_TALBOT    = 25301,
    NPC_PRINCE_VALANAR      = 28189,
    NPC_GENERAL_ARLOS       = 25250,
    NPC_LERYSSA             = 25251,

    SAY_THASSARIAN_1        = 0,
    SAY_THASSARIAN_2        = 1,
    SAY_THASSARIAN_3        = 2,
    SAY_THASSARIAN_4        = 3,
    SAY_THASSARIAN_5        = 4,
    SAY_THASSARIAN_6        = 5,
    SAY_THASSARIAN_7        = 6,

    SAY_TALBOT_1            = 0,
    SAY_TALBOT_2            = 1,
    SAY_TALBOT_3            = 2,
    SAY_TALBOT_4            = 3,

    SAY_LICH_1              = 0,
    SAY_LICH_2              = 1,
    SAY_LICH_3              = 2,

    SAY_ARLOS_1             = 0,
    SAY_ARLOS_2             = 1,

    SAY_LERYSSA_1           = 0,
    SAY_LERYSSA_2           = 1,
    SAY_LERYSSA_3           = 2,
    SAY_LERYSSA_4           = 3
};

#define GOSSIP_ITEM_T   "Let's do this, Thassarian. It's now or never."

class npc_thassarian : public CreatureScript
{
public:
    npc_thassarian() : CreatureScript("npc_thassarian") { }

    struct npc_thassarianAI : public EscortAI
    {
        npc_thassarianAI(Creature* creature) : EscortAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            arthasGUID.Clear();
            talbotGUID.Clear();
            leryssaGUID.Clear();
            arlosGUID.Clear();

            arthasInPosition = false;
            arlosInPosition = false;
            leryssaInPosition = false;
            talbotInPosition = false;

            phase = 0;
            phaseTimer = 0;
        }

        ObjectGuid arthasGUID;
        ObjectGuid talbotGUID;
        ObjectGuid leryssaGUID;
        ObjectGuid arlosGUID;

        bool arthasInPosition;
        bool arlosInPosition;
        bool leryssaInPosition;
        bool talbotInPosition;

        uint32 phase;
        uint32 phaseTimer;

        void Reset() override
        {
            me->RestoreFaction();
            me->RemoveStandFlags(UNIT_STAND_STATE_SIT);

            Initialize();
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 3:
                    SetEscortPaused(true);
                    if (Creature* arthas = me->SummonCreature(NPC_IMAGE_LICH_KING, 3730.313f, 3518.689f, 473.324f, 1.562f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000))
                    {
                        arthasGUID = arthas->GetGUID();
                        arthas->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        arthas->SetReactState(REACT_PASSIVE);
                        arthas->SetWalk(true);
                        arthas->GetMotionMaster()->MovePoint(0, 3737.374756f, 3564.841309f, 477.433014f);
                    }
                    if (Creature* talbot = me->SummonCreature(NPC_COUNSELOR_TALBOT, 3747.23f, 3614.936f, 473.321f, 4.462012f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000))
                    {
                        talbotGUID = talbot->GetGUID();
                        talbot->SetWalk(true);
                        talbot->GetMotionMaster()->MovePoint(0, 3738.000977f, 3568.882080f, 477.433014f);
                    }
                    me->SetWalk(false);
                    break;
                case 4:
                    SetEscortPaused(true);
                    phase = 7;
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            EscortAI::UpdateAI(diff);

            if (arthasInPosition && talbotInPosition)
            {
                phase = 1;
                arthasInPosition = false;
                talbotInPosition = false;
            }

            if (arlosInPosition && leryssaInPosition)
            {
                arlosInPosition   = false;
                leryssaInPosition = false;
                Talk(SAY_THASSARIAN_1);
                SetEscortPaused(false);
            }

            if (phaseTimer <= diff)
            {
                Creature* talbot = ObjectAccessor::GetCreature(*me, talbotGUID);
                Creature* arthas = ObjectAccessor::GetCreature(*me, arthasGUID);
                switch (phase)
                {
                    case 1:
                        if (talbot)
                            talbot->SetStandState(UNIT_STAND_STATE_KNEEL);
                        phaseTimer = 3000;
                        ++phase;
                        break;

                    case 2:
                        if (talbot)
                        {
                            talbot->UpdateEntry(NPC_PRINCE_VALANAR);
                            talbot->SetFaction(14);
                            talbot->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            talbot->SetReactState(REACT_PASSIVE);
                        }
                        phaseTimer = 5000;
                        ++phase;
                        break;

                    case 3:
                        if (talbot)
                            talbot->AI()->Talk(SAY_TALBOT_1);
                        phaseTimer = 5000;
                        ++phase;
                        break;

                    case 4:
                        if (arthas)
                            arthas->AI()->Talk(SAY_LICH_1);
                        phaseTimer = 5000;
                        ++phase;
                        break;

                    case 5:
                        if (talbot)
                            talbot->AI()->Talk(SAY_TALBOT_2);
                        phaseTimer = 5000;
                        ++phase;
                        break;

                    case 6:
                        if (Creature* arlos = me->SummonCreature(NPC_GENERAL_ARLOS, 3745.527100f, 3615.655029f, 473.321533f, 4.447805f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000))
                        {
                            arlosGUID = arlos->GetGUID();
                            arlos->SetWalk(true);
                            arlos->GetMotionMaster()->MovePoint(0, 3735.570068f, 3572.419922f, 477.441010f);
                        }
                        if (Creature* leryssa = me->SummonCreature(NPC_LERYSSA, 3749.654541f, 3614.959717f, 473.323486f, 4.524959f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000))
                        {
                            leryssaGUID = leryssa->GetGUID();
                            leryssa->SetWalk(false);
                            leryssa->SetReactState(REACT_PASSIVE);
                            leryssa->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            leryssa->GetMotionMaster()->MovePoint(0, 3741.969971f, 3571.439941f, 477.441010f);
                        }
                        phaseTimer = 2000;
                        phase = 0;
                        break;

                    case 7:
                        Talk(SAY_THASSARIAN_2);
                        phaseTimer = 5000;
                        ++phase;
                        break;

                    case 8:
                        if (arthas && talbot)
                        {
                            arthas->SetInFront(me); //The client doesen't update with the new orientation :l
                            talbot->SetStandState(UNIT_STAND_STATE_STAND);
                            arthas->AI()->Talk(SAY_LICH_2);
                        }
                        phaseTimer = 5000;
                        phase = 9;
                        break;

                   case 9:
                        Talk(SAY_THASSARIAN_3);
                        phaseTimer = 5000;
                        phase = 10;
                        break;

                   case 10:
                        if (talbot)
                            talbot->AI()->Talk(SAY_TALBOT_3);
                        phaseTimer = 5000;
                        phase = 11;
                        break;

                   case 11:
                        if (arthas)
                            arthas->AI()->Talk(SAY_LICH_3);
                        phaseTimer = 5000;
                        phase = 12;
                        break;

                    case 12:
                        if (talbot)
                            talbot->AI()->Talk(SAY_TALBOT_4);
                        phaseTimer = 2000;
                        phase = 13;
                        break;

                    case 13:
                        if (arthas)
                            arthas->RemoveFromWorld();
                        ++phase;
                        break;

                    case 14:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        if (talbot)
                        {
                            talbot->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            talbot->SetReactState(REACT_AGGRESSIVE);
                            talbot->CastSpell(me, SPELL_SHADOW_BOLT, false);
                        }
                        phaseTimer = 1500;
                        ++phase;
                        break;

                    case 15:
                        me->SetReactState(REACT_AGGRESSIVE);
                        AttackStart(talbot);
                        phase = 0;
                        break;

                    case 16:
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        phaseTimer = 20000;
                        ++phase;
                        break;

                   case 17:
                        if (Creature* leryssa = ObjectAccessor::GetCreature(*me, leryssaGUID))
                            leryssa->RemoveFromWorld();
                        if (Creature* arlos= ObjectAccessor::GetCreature(*me, arlosGUID))
                            arlos->RemoveFromWorld();
                        if (talbot)
                            talbot->RemoveFromWorld();
                        me->RemoveStandFlags(UNIT_STAND_STATE_SIT);
                        SetEscortPaused(false);
                        phaseTimer = 0;
                        phase = 0;
                }
            } else phaseTimer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* talbot = ObjectAccessor::GetCreature(*me, talbotGUID))
                talbot->RemoveFromWorld();

            if (Creature* leryssa = ObjectAccessor::GetCreature(*me, leryssaGUID))
                leryssa->RemoveFromWorld();

            if (Creature* arlos = ObjectAccessor::GetCreature(*me, arlosGUID))
                arlos->RemoveFromWorld();

            if (Creature* arthas = ObjectAccessor::GetCreature(*me, arthasGUID))
                arthas->RemoveFromWorld();
        }

        bool GossipHello(Player* player) override
        {
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            if (player->GetQuestStatus(QUEST_LAST_RITES) == QUEST_STATUS_INCOMPLETE && me->GetAreaId() == 4128)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_T, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            return true;
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    Start(true, false, player->GetGUID());
                    SetMaxPlayerDistance(200.0f);
                    break;
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_thassarianAI(creature);
    }
};

/*######
## npc_image_lich_king
######*/

class npc_image_lich_king : public CreatureScript
{
public:
    npc_image_lich_king() : CreatureScript("npc_image_lich_king") { }

    struct npc_image_lich_kingAI : public ScriptedAI
    {
        npc_image_lich_kingAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->RestoreFaction();
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/) override
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            if (me->IsSummon())
                if (Unit* summoner = me->ToTempSummon()->GetSummonerUnit())
                    ENSURE_AI(npc_thassarian::npc_thassarianAI, summoner->ToCreature()->AI())->arthasInPosition = true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_image_lich_kingAI(creature);
    }
};

/*######
## npc_general_arlos
######*/

class npc_general_arlos : public CreatureScript
{
public:
    npc_general_arlos() : CreatureScript("npc_general_arlos") { }

    struct npc_general_arlosAI : public ScriptedAI
    {
        npc_general_arlosAI(Creature* creature) : ScriptedAI(creature) { }

        void MovementInform(uint32 uiType, uint32 /*uiId*/) override
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            me->AddUnitState(UNIT_STATE_STUNNED);
            me->CastSpell(me, SPELL_STUN, true);
            if (me->IsSummon())
                if (Unit* summoner = me->ToTempSummon()->GetSummonerUnit())
                    ENSURE_AI(npc_thassarian::npc_thassarianAI, summoner->ToCreature()->AI())->arlosInPosition = true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_general_arlosAI(creature);
    }
};

/*######
## npc_counselor_talbot
######*/

enum CounselorTalbot
{
    SPELL_DEFLECTION    = 51009,
    SPELL_SOUL_BLAST    = 50992,
};

class npc_counselor_talbot : public CreatureScript
{
public:
    npc_counselor_talbot() : CreatureScript("npc_counselor_talbot") { }

    struct npc_counselor_talbotAI : public ScriptedAI
    {
        npc_counselor_talbotAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            leryssaGUID.Clear();
            arlosGUID.Clear();
            bCheck = false;
            shadowBoltTimer = urand(5000, 12000);
            deflectionTimer = urand(20000, 25000);
            soulBlastTimer = urand(12000, 18000);
        }

        ObjectGuid leryssaGUID;
        ObjectGuid arlosGUID;

        bool bCheck;

        uint32 shadowBoltTimer;
        uint32 deflectionTimer;
        uint32 soulBlastTimer;

        void Reset() override
        {
            Initialize();
        }
        void MovementInform(uint32 uiType, uint32 /*uiId*/) override
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            if (me->IsSummon())
                if (Unit* summoner = me->ToTempSummon()->GetSummonerUnit())
                    ENSURE_AI(npc_thassarian::npc_thassarianAI, summoner->ToCreature()->AI())->talbotInPosition = true;
        }

        void UpdateAI(uint32 diff) override
        {
            if (bCheck)
            {
                if (Creature* leryssa = me->FindNearestCreature(NPC_LERYSSA, 50.0f, true))
                    leryssaGUID = leryssa->GetGUID();
                if (Creature* arlos = me->FindNearestCreature(NPC_GENERAL_ARLOS, 50.0f, true))
                    arlosGUID = arlos->GetGUID();
                bCheck = false;
            }

            if (!UpdateVictim())
                return;

            if (me->GetAreaId() == 4125)
            {
                if (shadowBoltTimer <= diff)
                {
                    DoCastVictim(SPELL_SHADOW_BOLT);
                    shadowBoltTimer = urand(5000, 12000);
                }
                else
                    shadowBoltTimer -= diff;

                if (deflectionTimer <= diff)
                {
                    DoCastVictim(SPELL_DEFLECTION);
                    deflectionTimer = urand(20000, 25000);
                }
                else
                    deflectionTimer -= diff;

                if (soulBlastTimer <= diff)
                {
                    DoCastVictim(SPELL_SOUL_BLAST);
                    soulBlastTimer = urand(12000, 18000);
                }
                else
                    soulBlastTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* killer) override
        {
            if (!leryssaGUID || !arlosGUID)
                return;

            Creature* leryssa = ObjectAccessor::GetCreature(*me, leryssaGUID);
            Creature* arlos = ObjectAccessor::GetCreature(*me, arlosGUID);
            if (!leryssa || !arlos)
                return;

            arlos->AI()->Talk(SAY_ARLOS_1);
            arlos->AI()->Talk(SAY_ARLOS_2);
            leryssa->AI()->Talk(SAY_LERYSSA_1);
            arlos->KillSelf(false);
            leryssa->RemoveAura(SPELL_STUN);
            leryssa->ClearUnitState(UNIT_STATE_STUNNED);
            leryssa->SetWalk(false);
            leryssa->GetMotionMaster()->MovePoint(0, 3722.114502f, 3564.201660f, 477.441437f);

            if (killer && killer->GetTypeId() == TYPEID_PLAYER)
                killer->ToPlayer()->RewardPlayerAndGroupAtEvent(NPC_PRINCE_VALANAR, 0);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_counselor_talbotAI(creature);
    }
};

/*######
## npc_leryssa
######*/

class npc_leryssa : public CreatureScript
{
public:
    npc_leryssa() : CreatureScript("npc_leryssa") { }

    struct npc_leryssaAI : public ScriptedAI
    {
        npc_leryssaAI(Creature* creature) : ScriptedAI(creature)
        {
            bDone = false;
            phase = 0;
            phaseTimer = 0;

            creature->RemoveStandFlags(UNIT_STAND_STATE_SIT);
        }

        bool bDone;

        uint32 phase;
        uint32 phaseTimer;

        void MovementInform(uint32 type, uint32 /*uiId*/) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (!bDone)
            {
                if (Creature* talbot = me->FindNearestCreature(NPC_PRINCE_VALANAR, 50.0f, true))
                    ENSURE_AI(npc_counselor_talbot::npc_counselor_talbotAI, talbot->GetAI())->bCheck = true;

                me->AddUnitState(UNIT_STATE_STUNNED);
                me->CastSpell(me, SPELL_STUN, true);

                if (me->IsSummon())
                    if (Unit* summoner = me->ToTempSummon()->GetSummonerUnit())
                        ENSURE_AI(npc_thassarian::npc_thassarianAI, summoner->GetAI())->leryssaInPosition = true;
                bDone = true;
            }
            else
            {
                me->SetStandState(UNIT_STAND_STATE_SIT);
                if (me->IsSummon())
                    if (Unit* summoner = me->ToTempSummon()->GetSummonerUnit())
                    summoner->SetStandState(UNIT_STAND_STATE_SIT);
                phaseTimer = 1500;
                phase = 1;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            ScriptedAI::UpdateAI(diff);

            if (phaseTimer <= diff)
            {
                switch (phase)
                {
                    case 1:
                        if (me->IsSummon())
                            if (Unit* summoner = me->ToTempSummon()->GetSummonerUnit())
                                if (Creature* thassarian = summoner->ToCreature())
                                    thassarian->AI()->Talk(SAY_THASSARIAN_4);
                        phaseTimer = 5000;
                        ++phase;
                        break;
                    case 2:
                        Talk(SAY_LERYSSA_2);
                        phaseTimer = 5000;
                        ++phase;
                        break;
                    case 3:
                        if (me->IsSummon())
                            if (Unit* summoner = me->ToTempSummon()->GetSummonerUnit())
                                if (Creature* thassarian = summoner->ToCreature())
                                    thassarian->AI()->Talk(SAY_THASSARIAN_5);
                        phaseTimer = 5000;
                        ++phase;
                        break;
                    case 4:
                        Talk(SAY_LERYSSA_3);
                        phaseTimer = 5000;
                        ++phase;
                        break;
                    case 5:
                        if (me->IsSummon())
                            if (Unit* summoner = me->ToTempSummon()->GetSummonerUnit())
                                if (Creature* thassarian = summoner->ToCreature())
                                    thassarian->AI()->Talk(SAY_THASSARIAN_6);
                        phaseTimer = 5000;
                        ++phase;
                        break;

                    case 6:
                        Talk(SAY_LERYSSA_4);
                        phaseTimer = 5000;
                        ++phase;
                        break;
                    case 7:
                        if (me->IsSummon())
                            if (Unit* summoner = me->ToTempSummon()->GetSummonerUnit())
                                if (Creature* thassarian = summoner->ToCreature())
                                {
                                    thassarian->AI()->Talk(SAY_THASSARIAN_7);
                                    ENSURE_AI(npc_thassarian::npc_thassarianAI, thassarian->GetAI())->phase = 16;
                                }
                        phaseTimer = 5000;
                        phase = 0;
                        break;
                }
            } else phaseTimer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_leryssaAI(creature);
    }
};

/*######
## npc_beryl_sorcerer
######*/

enum BerylSorcerer
{
    NPC_CAPTURED_BERLY_SORCERER         = 25474,
    NPC_LIBRARIAN_DONATHAN              = 25262,

    SPELL_ARCANE_CHAINS                 = 45611,
    SPELL_COSMETIC_CHAINS               = 54324,
    SPELL_COSMETIC_ENSLAVE_CHAINS_SELF  = 45631
};

class npc_beryl_sorcerer : public CreatureScript
{
public:
    npc_beryl_sorcerer() : CreatureScript("npc_beryl_sorcerer") { }

    struct npc_beryl_sorcererAI : public FollowerAI
    {
        npc_beryl_sorcererAI(Creature* creature) : FollowerAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            bEnslaved = false;
        }

        bool bEnslaved;

        void Reset() override
        {
            me->SetReactState(REACT_AGGRESSIVE);
            Initialize();
        }

        void JustEngagedWith(Unit* who) override
        {
            if (me->IsValidAttackTarget(who))
                AttackStart(who);
        }

        void SpellHit(Unit* pCaster, SpellInfo const* pSpell) override
        {
            if (pSpell->Id == SPELL_ARCANE_CHAINS && pCaster->GetTypeId() == TYPEID_PLAYER && !HealthAbovePct(50) && !bEnslaved)
            {
                EnterEvadeMode(); //We make sure that the npc is not attacking the player!
                me->SetReactState(REACT_PASSIVE);
                StartFollow(pCaster->ToPlayer());
                me->UpdateEntry(NPC_CAPTURED_BERLY_SORCERER);
                DoCast(me, SPELL_COSMETIC_ENSLAVE_CHAINS_SELF, true);

                if (Player* player = pCaster->ToPlayer())
                    player->KilledMonsterCredit(NPC_CAPTURED_BERLY_SORCERER);

                bEnslaved = true;
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            FollowerAI::MoveInLineOfSight(who);

            if (who->GetEntry() == NPC_LIBRARIAN_DONATHAN && me->IsWithinDistInMap(who, INTERACTION_DISTANCE))
            {
                SetFollowComplete();
                me->DisappearAndDie();
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_beryl_sorcererAI(creature);
    }
};

/*######
## npc_imprisoned_beryl_sorcerer
######*/
enum ImprisionedBerylSorcerer
{
    SPELL_NEURAL_NEEDLE                  = 45634,
    SPELL_PROTOTYPE_NEURAL_NEEDLE        = 48252,
    SPELL_NEURAL_NEEDLE_IMPACT           = 45702,
    SPELL_PROTOTYPE_NEURAL_NEEDLE_IMPACT = 48254,

    NPC_IMPRISONED_BERYL_SORCERER = 25478,

    QUEST_THE_ART_OF_PERSUASION   = 11648
};

class npc_imprisoned_beryl_sorcerer : public CreatureScript
{
public:
    npc_imprisoned_beryl_sorcerer() : CreatureScript("npc_imprisoned_beryl_sorcerer") { }

    struct npc_imprisoned_beryl_sorcererAI : public ScriptedAI
    {
        npc_imprisoned_beryl_sorcererAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            rebuff = 0;
        }

        uint32 rebuff;

        void Reset() override
        {
            if (me->GetReactState() != REACT_PASSIVE)
                me->SetReactState(REACT_PASSIVE);

            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            UpdateVictim();

            if (rebuff <= diff)
            {
                if (!me->HasAura(SPELL_COSMETIC_ENSLAVE_CHAINS_SELF))
                    DoCast(me, SPELL_COSMETIC_ENSLAVE_CHAINS_SELF);
                rebuff = 180000;
            }
            else
                rebuff -= diff;

            DoMeleeAttackIfReady();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
        }

        void SpellHit(Unit* unit, SpellInfo const* spell) override
        {
            if ((spell->Id == SPELL_NEURAL_NEEDLE || spell->Id == SPELL_PROTOTYPE_NEURAL_NEEDLE) && unit->GetTypeId() == TYPEID_PLAYER)
                GotStinged(unit->ToPlayer(), spell->Id);
        }

        void GotStinged(Player* caster, uint32 spellId)
        {
            DoCastSelf(spellId == SPELL_NEURAL_NEEDLE ? SPELL_NEURAL_NEEDLE_IMPACT : SPELL_PROTOTYPE_NEURAL_NEEDLE_IMPACT);

            // Event cannot happen if quest is not accepted/completed/rewarded
            if (caster->GetQuestStatus(QUEST_THE_ART_OF_PERSUASION) == QUEST_STATUS_NONE)
                return;

            uint32 step = 0;

            if (spellId == SPELL_NEURAL_NEEDLE)
                step = caster->GetAuraCount(SPELL_NEURAL_NEEDLE); // Text IDs 0-6
            else
                step = caster->GetAuraCount(SPELL_PROTOTYPE_NEURAL_NEEDLE) + 7; // Text IDs 7-18

            if (spellId == SPELL_NEURAL_NEEDLE && step == 4)
                caster->KilledMonsterCredit(NPC_IMPRISONED_BERYL_SORCERER);

            Talk(step, caster);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_imprisoned_beryl_sorcererAI(creature);
    }
};

/*######
## npc_mootoo_the_younger
######*/
enum MootooTheYounger
{
    SAY_1                       = 0,
    SAY_2                       = 1,
    SAY_3                       = 2,
    SAY_4                       = 3,
    SAY_5                       = 4,

    NPC_MOOTOO_THE_YOUNGER      = 25504,
    QUEST_ESCAPING_THE_MIST     = 11664
};

class npc_mootoo_the_younger : public CreatureScript
{
public:
    npc_mootoo_the_younger() : CreatureScript("npc_mootoo_the_younger") { }

    struct npc_mootoo_the_youngerAI : public EscortAI
    {
        npc_mootoo_the_youngerAI(Creature* creature) : EscortAI(creature) { }

        void Reset() override
        {
            SetDespawnAtFar(false);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Player* player = GetPlayerForEscort())
                player->FailQuest(QUEST_ESCAPING_THE_MIST);
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 10:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                    Talk(SAY_2);
                    break;
                case 12:
                    Talk(SAY_3);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_LOOT);
                    break;
                case 16:
                    Talk(SAY_4);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                    break;
                case 20:
                    me->SetPhaseMask(1, true);
                    Talk(SAY_5);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                    player->GroupEventHappens(QUEST_ESCAPING_THE_MIST, me);
                    SetRun(true);
                    break;
            }
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_ESCAPING_THE_MIST)
            {
                switch (player->GetTeam())
                {
                    case ALLIANCE:
                        me->SetFaction(FACTION_ESCORTEE_A_PASSIVE);
                        break;
                    case HORDE:
                        me->SetFaction(FACTION_ESCORTEE_H_PASSIVE);
                        break;
                }
                me->SetStandState(UNIT_STAND_STATE_STAND);
                Talk(SAY_1, player);
                Start(true, false, player->GetGUID());
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mootoo_the_youngerAI(creature);
    }
};

/*######
## npc_bonker_togglevolt
######*/

enum BonkerTogglevolt
{
    NPC_BONKER_TOGGLEVOLT  = 25589,
    GO_BALL_AND_CHAIN      = 182531,
    QUEST_GET_ME_OUTA_HERE = 11673,

    EVENT_OOC_TALK         = 1,
    EVENT_TALK_1           = 2,
    EVENT_TALK_2           = 3,

    SAY_BONKER_0           = 0,
    SAY_BONKER_1           = 1,
    SAY_BONKER_2           = 2,
    SAY_BONKER_3           = 3,
    SAY_BONKER_4           = 4,
    SAY_BONKER_5           = 5
};

class npc_bonker_togglevolt : public CreatureScript
{
public:
    npc_bonker_togglevolt() : CreatureScript("npc_bonker_togglevolt") { }

    struct npc_bonker_togglevoltAI : public EscortAI
    {
        npc_bonker_togglevoltAI(Creature* creature) : EscortAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            _events.ScheduleEvent(EVENT_OOC_TALK, 10s, 20s);
        }

        void Reset() override
        {
            SetDespawnAtFar(false);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Player* player = GetPlayerForEscort())
                player->FailQuest(QUEST_GET_ME_OUTA_HERE);
        }

        void JustEngagedWith(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
            {
                if (roll_chance_i(20))
                    Talk(SAY_BONKER_5);
            }
        }

        void UpdateEscortAI(uint32 diff) override
        {
            _events.Update(diff);

            if (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_OOC_TALK:
                        Talk(SAY_BONKER_0);
                        _events.ScheduleEvent(EVENT_OOC_TALK, 5min, 10min);
                        break;
                    case EVENT_TALK_1:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _player))
                            Talk(SAY_BONKER_1, player);
                        if (GameObject* go = me->FindNearestGameObject(GO_BALL_AND_CHAIN, 20.0f))
                            go->SetLootState(GO_JUST_DEACTIVATED);
                        _events.ScheduleEvent(EVENT_TALK_2, 11s);
                        break;
                    case EVENT_TALK_2:
                        Talk(SAY_BONKER_2);
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 1:
                    Talk(SAY_BONKER_3);
                    break;
                case 29:
                    player->GroupEventHappens(QUEST_GET_ME_OUTA_HERE, me);
                    Talk(SAY_BONKER_4, player);
                    break;
            }
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_GET_ME_OUTA_HERE)
            {
                _player = player->GetGUID();
                me->SetStandState(UNIT_STAND_STATE_STAND);
                _events.ScheduleEvent(EVENT_TALK_1, Seconds(2));
                _events.CancelEvent(EVENT_OOC_TALK);
                Start(true, true, player->GetGUID());
                SetPauseTimer(12 * IN_MILLISECONDS);
            }
        }

    private:
        EventMap _events;
        ObjectGuid _player;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bonker_togglevoltAI(creature);
    }
};

/*######
## Help Those That Cannot Help Themselves, Quest 11876
######*/

enum HelpThemselves
{
    QUEST_CANNOT_HELP_THEMSELVES                  =  11876,
    GO_MAMMOTH_TRAP_1                             = 188022,
    GO_MAMMOTH_TRAP_2                             = 188024,
    GO_MAMMOTH_TRAP_3                             = 188025,
    GO_MAMMOTH_TRAP_4                             = 188026,
    GO_MAMMOTH_TRAP_5                             = 188027,
    GO_MAMMOTH_TRAP_6                             = 188028,
    GO_MAMMOTH_TRAP_7                             = 188029,
    GO_MAMMOTH_TRAP_8                             = 188030,
    GO_MAMMOTH_TRAP_9                             = 188031,
    GO_MAMMOTH_TRAP_10                            = 188032,
    GO_MAMMOTH_TRAP_11                            = 188033,
    GO_MAMMOTH_TRAP_12                            = 188034,
    GO_MAMMOTH_TRAP_13                            = 188035,
    GO_MAMMOTH_TRAP_14                            = 188036,
    GO_MAMMOTH_TRAP_15                            = 188037,
    GO_MAMMOTH_TRAP_16                            = 188038,
    GO_MAMMOTH_TRAP_17                            = 188039,
    GO_MAMMOTH_TRAP_18                            = 188040,
    GO_MAMMOTH_TRAP_19                            = 188041,
    GO_MAMMOTH_TRAP_20                            = 188042,
    GO_MAMMOTH_TRAP_21                            = 188043,
    GO_MAMMOTH_TRAP_22                            = 188044,
};

#define MammothTrapsNum 22
const uint32 MammothTraps[MammothTrapsNum] =
{
    GO_MAMMOTH_TRAP_1, GO_MAMMOTH_TRAP_2, GO_MAMMOTH_TRAP_3, GO_MAMMOTH_TRAP_4, GO_MAMMOTH_TRAP_5,
    GO_MAMMOTH_TRAP_6, GO_MAMMOTH_TRAP_7, GO_MAMMOTH_TRAP_8, GO_MAMMOTH_TRAP_9, GO_MAMMOTH_TRAP_10,
    GO_MAMMOTH_TRAP_11, GO_MAMMOTH_TRAP_12, GO_MAMMOTH_TRAP_13, GO_MAMMOTH_TRAP_14, GO_MAMMOTH_TRAP_15,
    GO_MAMMOTH_TRAP_16, GO_MAMMOTH_TRAP_17, GO_MAMMOTH_TRAP_18, GO_MAMMOTH_TRAP_19, GO_MAMMOTH_TRAP_20,
    GO_MAMMOTH_TRAP_21, GO_MAMMOTH_TRAP_22
};

class npc_trapped_mammoth_calf : public CreatureScript
{
public:
    npc_trapped_mammoth_calf() : CreatureScript("npc_trapped_mammoth_calf") { }

    struct npc_trapped_mammoth_calfAI : public ScriptedAI
    {
        npc_trapped_mammoth_calfAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            uiTimer = 1500;
            bStarted = false;
        }

        uint32 uiTimer;
        bool bStarted;

        void Reset() override
        {
            Initialize();

            GameObject* pTrap = nullptr;
            for (uint8 i = 0; i < MammothTrapsNum; ++i)
            {
                pTrap = me->FindNearestGameObject(MammothTraps[i], 11.0f);
                if (pTrap)
                {
                    pTrap->SetGoState(GO_STATE_ACTIVE);
                    return;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (bStarted)
            {
                if (uiTimer <= diff)
                {
                    Position pos = me->GetRandomNearPosition(10.0f);
                    me->GetMotionMaster()->MovePoint(0, pos);
                    bStarted = false;
                }
                else uiTimer -= diff;
            }
        }

        void DoAction(int32 param) override
        {
            if (param == 1)
                bStarted = true;
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/) override
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            me->DisappearAndDie();

            GameObject* pTrap = nullptr;
            for (uint8 i = 0; i < MammothTrapsNum; ++i)
            {
                pTrap = me->FindNearestGameObject(MammothTraps[i], 11.0f);
                if (pTrap)
                {
                    pTrap->SetLootState(GO_JUST_DEACTIVATED);
                    return;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_trapped_mammoth_calfAI(creature);
    }
};

/*######
## Help Those That Cannot Help Themselves, Quest 11876
######*/

enum Valiancekeepcannons
{
    GO_VALIANCE_KEEP_CANNON_1                     = 187560,
    GO_VALIANCE_KEEP_CANNON_2                     = 188692
};

class npc_valiance_keep_cannoneer : public CreatureScript
{
public:
    npc_valiance_keep_cannoneer() : CreatureScript("npc_valiance_keep_cannoneer") { }

    struct npc_valiance_keep_cannoneerAI : public ScriptedAI
    {
        npc_valiance_keep_cannoneerAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            uiTimer = urand(13000, 18000);
        }

        uint32 uiTimer;

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            if (uiTimer <= diff)
            {
                me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
                GameObject* pCannon = me->FindNearestGameObject(GO_VALIANCE_KEEP_CANNON_1, 10);
                if (!pCannon)
                    pCannon = me->FindNearestGameObject(GO_VALIANCE_KEEP_CANNON_2, 10);
                if (pCannon)
                    pCannon->Use(me);
                uiTimer = urand(13000, 18000);
            }
            else uiTimer -= diff;

            if (!UpdateVictim())
                return;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_valiance_keep_cannoneerAI(creature);
    }
};

/*******************************************************
 * npc_warmage_coldarra
 *******************************************************/

enum Spells
{
    SPELL_TRANSITUS_SHIELD_BEAM = 48310
};

enum NPCs
{
    NPC_TRANSITUS_SHIELD_DUMMY   = 27306,
    NPC_WARMAGE_HOLLISTER        = 27906,
    NPC_WARMAGE_CALANDRA         = 27173,
    NPC_WARMAGE_WATKINS          = 27904
};

class npc_warmage_coldarra : public CreatureScript
{
public:
    npc_warmage_coldarra() : CreatureScript("npc_warmage_coldarra") { }

    struct npc_warmage_coldarraAI : public ScriptedAI
    {
        npc_warmage_coldarraAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            m_uiTimer = 0;
        }

        uint32 m_uiTimer;                 //Timer until recast

        void Reset() override
        {
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override { }

        void AttackStart(Unit* /*who*/) override { }

        void UpdateAI(uint32 uiDiff) override
        {
            if (m_uiTimer <= uiDiff)
            {
                std::list<Creature*> orbList;
                GetCreatureListWithEntryInGrid(orbList, me, NPC_TRANSITUS_SHIELD_DUMMY, 32.0f);

                switch (me->GetEntry())
                {
                    case NPC_WARMAGE_HOLLISTER:
                    {
                        if (!orbList.empty())
                        {
                            for (std::list<Creature*>::const_iterator itr = orbList.begin(); itr != orbList.end(); ++itr)
                            {
                                if (Creature* pOrb = *itr)
                                    if (pOrb->GetPositionY() > 6680)
                                        DoCast(pOrb, SPELL_TRANSITUS_SHIELD_BEAM);
                            }
                        }
                        m_uiTimer = urand(90000, 120000);
                    }
                        break;
                    case NPC_WARMAGE_CALANDRA:
                    {
                        if (!orbList.empty())
                        {
                            for (std::list<Creature*>::const_iterator itr = orbList.begin(); itr != orbList.end(); ++itr)
                            {
                                if (Creature* pOrb = *itr)
                                    if ((pOrb->GetPositionY() < 6680) && (pOrb->GetPositionY() > 6630))
                                        DoCast(pOrb, SPELL_TRANSITUS_SHIELD_BEAM);
                            }
                        }
                        m_uiTimer = urand(90000, 120000);
                    }
                        break;
                    case NPC_WARMAGE_WATKINS:
                    {
                        if (!orbList.empty())
                        {
                            for (std::list<Creature*>::const_iterator itr = orbList.begin(); itr != orbList.end(); ++itr)
                            {
                                if (Creature* pOrb = *itr)
                                    if (pOrb->GetPositionY() < 6630)
                                        DoCast(pOrb, SPELL_TRANSITUS_SHIELD_BEAM);
                            }
                        }
                        m_uiTimer = urand(90000, 120000);
                    }
                        break;
                }
            }
            else m_uiTimer -= uiDiff;

            ScriptedAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_warmage_coldarraAI(creature);
    }
};

/*######
## npc_hidden_cultist
######*/

enum HiddenCultist
{
    SPELL_SHROUD_OF_THE_DEATH_CULTIST           = 46077, //not working
    SPELL_RIGHTEOUS_VISION                      = 46078, //player aura

    QUEST_THE_HUNT_IS_ON                        = 11794,

    GOSSIP_TEXT_SALTY_JOHN_THORPE               = 12529,
    GOSSIP_TEXT_GUARD_MITCHELSS                 = 12530,
    GOSSIP_TEXT_TOM_HEGGER                      = 12528,

    NPC_TOM_HEGGER                              = 25827,
    NPC_SALTY_JOHN_THORPE                       = 25248,
    NPC_GUARD_MITCHELLS                         = 25828,

    SAY_HIDDEN_CULTIST_1                        = 0,
    SAY_HIDDEN_CULTIST_2                        = 1,
    SAY_HIDDEN_CULTIST_3                        = 2,
    SAY_HIDDEN_CULTIST_4                        = 3
};

char const* GOSSIP_ITEM_TOM_HEGGER = "What do you know about the Cult of the Damned?";
char const* GOSSIP_ITEM_GUARD_MITCHELLS = "How long have you worked for the Cult of the Damned?";
char const* GOSSIP_ITEM_SALTY_JOHN_THORPE = "I have a reason to believe you're involved in the cultist activity";

class npc_hidden_cultist : public CreatureScript
{
public:
    npc_hidden_cultist() : CreatureScript("npc_hidden_cultist") { }

    struct npc_hidden_cultistAI : public ScriptedAI
    {
        npc_hidden_cultistAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            uiEmoteState = creature->GetUInt32Value(UNIT_NPC_EMOTESTATE);
            uiNpcFlags = creature->GetUInt32Value(UNIT_NPC_FLAGS);
        }

        void Initialize()
        {
            uiEventTimer = 0;
            uiEventPhase = 0;

            uiPlayerGUID.Clear();
        }

        uint32 uiEmoteState;
        uint32 uiNpcFlags;

        uint32 uiEventTimer;
        uint8 uiEventPhase;

        ObjectGuid uiPlayerGUID;

        void Reset() override
        {
            if (uiEmoteState)
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, uiEmoteState);

            if (uiNpcFlags)
                me->SetUInt32Value(UNIT_NPC_FLAGS, uiNpcFlags);

            Initialize();

            DoCast(SPELL_SHROUD_OF_THE_DEATH_CULTIST);

            me->RestoreFaction();
        }

        void DoAction(int32 /*iParam*/) override
        {
            me->StopMoving();
            me->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
            if (Player* player = ObjectAccessor::GetPlayer(*me, uiPlayerGUID))
                me->SetFacingToObject(player);
            uiEventTimer = 3000;
            uiEventPhase = 1;
        }

        void AttackPlayer()
        {
            me->SetFaction(14);
            if (Player* player = ObjectAccessor::GetPlayer(*me, uiPlayerGUID))
                AttackStart(player);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (uiEventTimer && uiEventTimer <= uiDiff)
            {
                switch (uiEventPhase)
                {
                    case 1:
                        switch (me->GetEntry())
                        {
                            case NPC_SALTY_JOHN_THORPE:
                                Talk(SAY_HIDDEN_CULTIST_1);
                                uiEventTimer = 5000;
                                uiEventPhase = 2;
                                break;
                            case NPC_GUARD_MITCHELLS:
                                Talk(SAY_HIDDEN_CULTIST_2);
                                uiEventTimer = 5000;
                                uiEventPhase = 2;
                                break;
                            case NPC_TOM_HEGGER:
                                if (Player* player = ObjectAccessor::GetPlayer(*me, uiPlayerGUID))
                                    Talk(SAY_HIDDEN_CULTIST_3, player);
                                uiEventTimer = 5000;
                                uiEventPhase = 2;
                                break;
                        }
                        break;
                    case 2:
                        switch (me->GetEntry())
                        {
                            case NPC_SALTY_JOHN_THORPE:
                                Talk(SAY_HIDDEN_CULTIST_4);
                                if (Player* player = ObjectAccessor::GetPlayer(*me, uiPlayerGUID))
                                    me->SetFacingToObject(player);
                                uiEventTimer = 3000;
                                uiEventPhase = 3;
                                break;
                            case NPC_GUARD_MITCHELLS:
                            case NPC_TOM_HEGGER:
                                AttackPlayer();
                                uiEventPhase = 0;
                                break;
                        }
                        break;
                    case 3:
                        if (me->GetEntry() == NPC_SALTY_JOHN_THORPE)
                        {
                            AttackPlayer();
                            uiEventPhase = 0;
                        }
                        break;
                }
            }else uiEventTimer -= uiDiff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        bool GossipHello(Player* player) override
        {
            uint32 uiGossipText = 0;
            char const* charGossipItem;

            switch (me->GetEntry())
            {
                case NPC_TOM_HEGGER:
                    uiGossipText = GOSSIP_TEXT_TOM_HEGGER;
                    charGossipItem = GOSSIP_ITEM_TOM_HEGGER;
                    break;
                case NPC_SALTY_JOHN_THORPE:
                    uiGossipText = GOSSIP_TEXT_SALTY_JOHN_THORPE;
                    charGossipItem = GOSSIP_ITEM_SALTY_JOHN_THORPE;
                    break;
                case NPC_GUARD_MITCHELLS:
                    uiGossipText = GOSSIP_TEXT_GUARD_MITCHELSS;
                    charGossipItem = GOSSIP_ITEM_GUARD_MITCHELLS;
                    break;
                default:
                    return false;
            }

            if (player->HasAura(SPELL_RIGHTEOUS_VISION) && player->GetQuestStatus(QUEST_THE_HUNT_IS_ON) == QUEST_STATUS_INCOMPLETE)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, charGossipItem, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            if (me->IsVendor())
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

            SendGossipMenuFor(player, uiGossipText, me->GetGUID());

            return true;
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);
                uiPlayerGUID = player->GetGUID();
                DoAction(1);
            }

            if (action == GOSSIP_ACTION_TRADE)
                player->GetSession()->SendListInventory(me->GetGUID());

            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_hidden_cultistAI(creature);
    }
};

enum WindsoulTotemAura
{
    SPELL_WINDSOUL_CREDT = 46378
};

class spell_windsoul_totem_aura : public SpellScriptLoader
{
public:
    spell_windsoul_totem_aura() : SpellScriptLoader("spell_windsoul_totem_aura") { }

    class spell_windsoul_totem_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_windsoul_totem_aura_AuraScript);

        void OnRemove(AuraEffect const*, AuraEffectHandleModes)
        {
            if (GetTarget()->isDead())
                if (Unit* caster = GetCaster())
                    caster->CastSpell(nullptr, SPELL_WINDSOUL_CREDT);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_windsoul_totem_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_windsoul_totem_aura_AuraScript();
    }
};

enum BloodsporeRuination
{
    NPC_BLOODMAGE_LAURITH   = 25381,
    SAY_BLOODMAGE_LAURITH   = 0,
    EVENT_TALK              = 1,
    EVENT_RESET_ORIENTATION
};

class spell_q11719_bloodspore_ruination_45997 : public SpellScriptLoader
{
public:
    spell_q11719_bloodspore_ruination_45997() : SpellScriptLoader("spell_q11719_bloodspore_ruination_45997") { }

    class spell_q11719_bloodspore_ruination_45997_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_q11719_bloodspore_ruination_45997_SpellScript);

        void HandleEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Creature* laurith = caster->FindNearestCreature(NPC_BLOODMAGE_LAURITH, 100.0f))
                    laurith->AI()->SetGUID(caster->GetGUID());
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_q11719_bloodspore_ruination_45997_SpellScript::HandleEffect, EFFECT_1, SPELL_EFFECT_SEND_EVENT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_q11719_bloodspore_ruination_45997_SpellScript();
    }
};

class npc_bloodmage_laurith : public CreatureScript
{
public:
    npc_bloodmage_laurith() : CreatureScript("npc_bloodmage_laurith") { }

    struct npc_bloodmage_laurithAI : public ScriptedAI
    {
        npc_bloodmage_laurithAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _events.Reset();
            _playerGUID.Clear();
        }

        void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
        {
            if (!_playerGUID.IsEmpty())
                return;

            _playerGUID = guid;

            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                me->SetFacingToObject(player);

            _events.ScheduleEvent(EVENT_TALK, 1s);
        }

        void UpdateAI(uint32 diff) override
        {
            if (UpdateVictim())
            {
                DoMeleeAttackIfReady();
                return;
            }

            _events.Update(diff);

            if (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TALK:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                            Talk(SAY_BLOODMAGE_LAURITH, player);
                        _playerGUID.Clear();
                        _events.ScheduleEvent(EVENT_RESET_ORIENTATION, 5s);
                        break;
                    case EVENT_RESET_ORIENTATION:
                        me->SetFacingTo(me->GetHomePosition().GetOrientation());
                        break;
                }
            }
        }

        private:
            EventMap _events;
            ObjectGuid _playerGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bloodmage_laurithAI(creature);
    }
};

enum OrabusTheHelmsman
{
    NPC_ORABUS            = 32576,
    NPC_KVALDIR_CREWMAN_1 = 32577,
    NPC_KVALDIR_CREWMAN_2 = 32578,
    NPC_KVALDIR_CREWMAN_3 = 32579,
    NPC_KVALDIR_CREWMAN_4 = 32580
};

class npc_orabus_the_helmsman_ship_exit_pos : public UnitScript
{
public:
    npc_orabus_the_helmsman_ship_exit_pos() : UnitScript("npc_orabus_the_helmsman_ship_exit_pos") { }

    void ModifyVehiclePassengerExitPos(Unit* passenger, Vehicle* /*vehicle*/, Position& pos)
    {
        if (passenger->GetTypeId() == TYPEID_UNIT)
        {
            switch (passenger->GetEntry())
            {
                case NPC_ORABUS:
                    pos.Relocate(2807.858f, 7038.571f, 7.075813f, 4.73481f);
                    break;
                case NPC_KVALDIR_CREWMAN_1:
                    pos.Relocate(2801.168f, 7046.468f, 5.362013f, 4.73481f);
                    break;
                case NPC_KVALDIR_CREWMAN_2:
                    pos.Relocate(2803.729f, 7046.516f, 5.362013f, 4.73481f);
                    break;
                case NPC_KVALDIR_CREWMAN_3:
                    pos.Relocate(2801.48f, 7051.379f, 5.362913f, 4.73481f);
                    break;
                case NPC_KVALDIR_CREWMAN_4:
                    pos.Relocate(2803.319f, 7051.411f, 5.362913f, 4.73481f);
                    break;
            }
        }
    }
};

// 45668 - Ultra-Advanced Proto-Typical Shortening Blaster
enum ShorteningBlaster
{
    SPELL_SHORTENING_BLASTER_BIGGER1    = 45674,
    SPELL_SHORTENING_BLASTER_SHRUNK1    = 45675,
    SPELL_SHORTENING_BLASTER_YELLOW1    = 45678,
    SPELL_SHORTENING_BLASTER_GHOST1     = 45682,
    SPELL_SHORTENING_BLASTER_POLYMORPH1 = 45684,

    SPELL_SHORTENING_BLASTER_BIGGER2    = 45673,
    SPELL_SHORTENING_BLASTER_SHRUNK2    = 45672,
    SPELL_SHORTENING_BLASTER_YELLOW2    = 45677,
    SPELL_SHORTENING_BLASTER_GHOST2     = 45682,
    SPELL_SHORTENING_BLASTER_POLYMORPH2 = 45683
};

class spell_q11653_shortening_blaster : public SpellScript
{
    PrepareSpellScript(spell_q11653_shortening_blaster);

    void HandleScript(SpellEffIndex /* effIndex */)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        uint32 spellId = RAND(SPELL_SHORTENING_BLASTER_BIGGER1, SPELL_SHORTENING_BLASTER_SHRUNK1, SPELL_SHORTENING_BLASTER_YELLOW1,
            SPELL_SHORTENING_BLASTER_GHOST1, SPELL_SHORTENING_BLASTER_POLYMORPH1);
        uint32 spellId2 = RAND(SPELL_SHORTENING_BLASTER_BIGGER2, SPELL_SHORTENING_BLASTER_SHRUNK2, SPELL_SHORTENING_BLASTER_YELLOW2,
            SPELL_SHORTENING_BLASTER_GHOST2, SPELL_SHORTENING_BLASTER_POLYMORPH2);

        caster->CastSpell(caster, spellId, true);
        target->CastSpell(target, spellId2, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q11653_shortening_blaster::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_borean_tundra()
{
    new npc_sinkhole_kill_credit();
    new npc_khunok_the_behemoth();
    new npc_corastrasza();
    new npc_iruk();
    new npc_nerubar_victim();
    RegisterSpellScript(spell_q11865_place_fake_fur);
    new npc_nesingwary_trapper();
    new npc_lurgglbr();
    new spell_red_dragonblood();
    new npc_thassarian();
    new npc_image_lich_king();
    new npc_counselor_talbot();
    new npc_leryssa();
    new npc_general_arlos();
    new npc_beryl_sorcerer();
    new npc_imprisoned_beryl_sorcerer();
    new npc_mootoo_the_younger();
    new npc_bonker_togglevolt();
    new npc_trapped_mammoth_calf();
    new npc_valiance_keep_cannoneer();
    new npc_warmage_coldarra();
    new npc_hidden_cultist();
    new spell_windsoul_totem_aura();
    new spell_q11719_bloodspore_ruination_45997();
    new npc_bloodmage_laurith();
    new npc_orabus_the_helmsman_ship_exit_pos();
    RegisterSpellScript(spell_q11653_shortening_blaster);
}
