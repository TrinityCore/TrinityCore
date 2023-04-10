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

 /* ScriptData
 SDName: Ashenvale
 SD%Complete: 70
 SDComment: Quest support: 6544, 6482
 SDCategory: Ashenvale Forest
 EndScriptData */

 /* ContentData
 npc_ruul_snowhoof
 EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "SpellInfo.h"
#include "SpellScript.h"

 /*####
 # npc_ruul_snowhoof
 ####*/

enum ashenvale
{
    QUEST_OF_THEIR_OWN_DESIGN = 13595,
    NPC_BATHRANS_CORPSE = 33183,

    QUEST_BATHED_IN_LIGHT = 13642,
    GO_LIGHT_OF_ELUNE_AT_LAKE_FALATHIM = 194651,
    ITEM_UNBATHED_CONCOCTION = 45065,
    ITEM_BATHED_CONCOCTION = 45066,

    QUEST_RESPECT_FOR_THE_FALLEN = 13626,
    SPELL_CREATE_FEEROS_HOLY_HAMMER_COVER = 62837,
    ITEM_FEEROS_HOLY_HAMMER = 45042,
    SPELL_CREATE_THE_PURIFIERS_PRAYER_BOOK_COVER = 62839,
    ITEM_PURIFIERS_PRAYER_BOOK = 45043,

    QUEST_TREE_FRIENDS_OF_THE_FOREST = 13976,
    QUEST_IN_A_BIND = 13982,
    SPELL_BOLYUN_SEE_INVISIBILITY_1 = 65714,
    SPELL_BOLYUN_SEE_INVISIBILITY_2 = 65715,

    QUEST_CLEAR_THE_SHRINE = 13985,
    QUEST_THE_LAST_STAND = 13987,
    NPC_DEMONIC_INVADER = 34609,
    NPC_BIG_BAOBOB = 34604,

    QUEST_ASTRANAARS_BURNING = 13849,
    NPC_ASTRANAARS_BURNING_FIRE_BUNNY = 34123,
    SPELL_ASTRANAARS_BURNING_SEE_INVISIBLE_01 = 64572,
    SPELL_ASTRANAARS_BURNING_SEE_INVISIBLE_02 = 64574,
    SPELL_ASTRANAARS_BURNING_SMOKE = 64565,
    SPELL_THROW_BUCKET_OF_WATER = 64558,
    SPELL_BATHRANS_CORPSE_FIRE = 62511,
};

/*####
# npc_torek
####*/

enum Torek
{
    SAY_READY = 0,
    SAY_MOVE = 1,
    SAY_PREPARE = 2,
    SAY_WIN = 3,
    SAY_END = 4,
    SPELL_REND = 11977,
    SPELL_THUNDERCLAP = 8078,
    QUEST_TOREK_ASSULT = 6544,
    NPC_SPLINTERTREE_RAIDER = 12859,
    NPC_DURIEL = 12860,
    NPC_SILVERWING_SENTINEL = 12896,
    NPC_SILVERWING_WARRIOR = 12897,
    FACTION_QUEST = 113
};

//class npc_torek : public CreatureScript
//{
//public:
//    npc_torek() : CreatureScript("npc_torek") { }
//
//    struct npc_torekAI : public npc_escortAI
//    {
//        npc_torekAI(Creature* creature) : npc_escortAI(creature) { }
//
//        void Reset() override
//        {
//            rend_Timer = 5000;
//            thunderclap_Timer = 8000;
//            _completed = false;
//        }
//
//        void EnterCombat(Unit* /*who*/) override { }
//
//        void JustSummoned(Creature* summoned) override
//        {
//            summoned->AI()->AttackStart(me);
//        }
//
//        bool sQuestAccept(Player* player, Quest const* quest)
//        {
//            if (quest->GetQuestId() == QUEST_TOREK_ASSULT)
//            {
//                /// @todo find companions, make them follow Torek, at any time (possibly done by core/database in future?)
//                Talk(SAY_READY, player);
//                me->setFaction(FACTION_QUEST);
//                npc_escortAI::Start(true, true, player->GetGUID());
//            }
//            return false;
//        }
//
//        void WaypointReached(uint32 waypointId) override
//        {
//            if (Player* player = GetPlayerForEscort())
//            {
//                switch (waypointId)
//                {
//                case 1:
//                    Talk(SAY_MOVE, player);
//                    break;
//                case 8:
//                    Talk(SAY_PREPARE, player);
//                    break;
//                case 19:
//                    /// @todo verify location and creatures amount.
//                    me->SummonCreature(NPC_DURIEL, 1776.73f, -2049.06f, 109.83f, 1.54f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
//                    me->SummonCreature(NPC_SILVERWING_SENTINEL, 1774.64f, -2049.41f, 109.83f, 1.40f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
//                    me->SummonCreature(NPC_SILVERWING_WARRIOR, 1778.73f, -2049.50f, 109.83f, 1.67f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
//                    break;
//                case 20:
//                    Talk(SAY_WIN, player);
//                    _completed = true;
//                    player->GroupEventHappens(QUEST_TOREK_ASSULT, me);
//                    break;
//                case 21:
//                    Talk(SAY_END, player);
//                    break;
//                }
//            }
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            npc_escortAI::UpdateAI(diff);
//
//            if (!UpdateVictim())
//                return;
//
//            if (rend_Timer <= diff)
//            {
//                DoCastVictim(SPELL_REND);
//                rend_Timer = 20000;
//            }
//            else rend_Timer -= diff;
//
//            if (thunderclap_Timer <= diff)
//            {
//                DoCast(me, SPELL_THUNDERCLAP);
//                thunderclap_Timer = 30000;
//            }
//            else thunderclap_Timer -= diff;
//        }
//
//    private:
//        uint32 rend_Timer;
//        uint32 thunderclap_Timer;
//        bool   _completed;
//
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_torekAI(creature);
//    }
//};
//
///*####
//# npc_ruul_snowhoof
//####*/
//
//enum RuulSnowhoof
//{
//    NPC_THISTLEFUR_URSA = 3921,
//    NPC_THISTLEFUR_TOTEMIC = 3922,
//    NPC_THISTLEFUR_PATHFINDER = 3926,
//    QUEST_FREEDOM_TO_RUUL = 6482,
//    GO_CAGE = 178147
//};
//
//Position const RuulSnowhoofSummonsCoord[6] =
//{
//    { 3449.218018f, -587.825073f, 174.978867f, 4.714445f },
//    { 3446.384521f, -587.830872f, 175.186279f, 4.714445f },
//    { 3444.218994f, -587.835327f, 175.380600f, 4.714445f },
//    { 3508.344482f, -492.024261f, 186.929031f, 4.145029f },
//    { 3506.265625f, -490.531006f, 186.740128f, 4.239277f },
//    { 3503.682373f, -489.393799f, 186.629684f, 4.349232f }
//};
//
//class npc_ruul_snowhoof : public CreatureScript
//{
//public:
//    npc_ruul_snowhoof() : CreatureScript("npc_ruul_snowhoof") { }
//
//    struct npc_ruul_snowhoofAI : public npc_escortAI
//    {
//        npc_ruul_snowhoofAI(Creature* creature) : npc_escortAI(creature) { }
//
//        void Reset() override
//        {
//            if (GameObject* Cage = me->FindNearestGameObject(GO_CAGE, 20))
//                Cage->SetGoState(GO_STATE_READY);
//        }
//
//        void EnterCombat(Unit* /*who*/) override { }
//
//        void JustSummoned(Creature* summoned) override
//        {
//            summoned->AI()->AttackStart(me);
//        }
//
//        bool sQuestAccept(Player* player, Quest const* quest)
//        {
//            if (quest->GetQuestId() == QUEST_FREEDOM_TO_RUUL)
//            {
//                me->setFaction(FACTION_QUEST);
//                npc_escortAI::Start(true, false, player->GetGUID());
//            }
//            return false;
//        }
//
//        void WaypointReached(uint32 waypointId) override
//        {
//            Player* player = GetPlayerForEscort();
//            if (!player)
//                return;
//
//            switch (waypointId)
//            {
//            case 0:
//                me->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
//                if (GameObject* Cage = me->FindNearestGameObject(GO_CAGE, 20))
//                    Cage->SetGoState(GO_STATE_ACTIVE);
//                break;
//            case 13:
//                me->SummonCreature(NPC_THISTLEFUR_TOTEMIC, RuulSnowhoofSummonsCoord[0], TEMPSUMMON_DEAD_DESPAWN, 60000);
//                me->SummonCreature(NPC_THISTLEFUR_URSA, RuulSnowhoofSummonsCoord[1], TEMPSUMMON_DEAD_DESPAWN, 60000);
//                me->SummonCreature(NPC_THISTLEFUR_PATHFINDER, RuulSnowhoofSummonsCoord[2], TEMPSUMMON_DEAD_DESPAWN, 60000);
//                break;
//            case 19:
//                me->SummonCreature(NPC_THISTLEFUR_TOTEMIC, RuulSnowhoofSummonsCoord[3], TEMPSUMMON_DEAD_DESPAWN, 60000);
//                me->SummonCreature(NPC_THISTLEFUR_URSA, RuulSnowhoofSummonsCoord[4], TEMPSUMMON_DEAD_DESPAWN, 60000);
//                me->SummonCreature(NPC_THISTLEFUR_PATHFINDER, RuulSnowhoofSummonsCoord[5], TEMPSUMMON_DEAD_DESPAWN, 60000);
//                break;
//            case 21:
//                player->GroupEventHappens(QUEST_FREEDOM_TO_RUUL, me);
//                break;
//            }
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            npc_escortAI::UpdateAI(diff);
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_ruul_snowhoofAI(creature);
//    }
//};
//

//Position const FirstNagaCoord[3] =
//{
//    { 3603.504150f, 1122.631104f,  1.635f, 0.0f },        // rider
//    { 3589.293945f, 1148.664063f,  5.565f, 0.0f },        // sorceress
//    { 3609.925537f, 1168.759521f, -1.168f, 0.0f }         // razortail
//};
//
//Position const SecondNagaCoord[3] =
//{
//    { 3609.925537f, 1168.759521f, -1.168f, 0.0f },        // witch
//    { 3645.652100f, 1139.425415f, 1.322f,  0.0f },        // priest
//    { 3583.602051f, 1128.405762f, 2.347f,  0.0f }         // myrmidon
//};
//
//Position const VorshaCoord = { 3633.056885f, 1172.924072f, -5.388f, 0.0f };
//
//class npc_muglash : public CreatureScript
//{
//public:
//    npc_muglash() : CreatureScript("npc_muglash") { }
//
//    struct npc_muglashAI : public npc_escortAI
//    {
//        npc_muglashAI(Creature* creature) : npc_escortAI(creature) { }
//
//        void Reset() override
//        {
//            eventTimer = 10000;
//            waveId = 0;
//            _isBrazierExtinguished = false;
//        }
//
//        void EnterCombat(Unit* /*who*/) override
//        {
//            if (Player* player = GetPlayerForEscort())
//                if (HasEscortState(STATE_ESCORT_PAUSED))
//                {
//                    if (urand(0, 1))
//                        Talk(SAY_MUG_ON_GUARD, player);
//                    return;
//                }
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            if (HasEscortState(STATE_ESCORT_ESCORTING))
//                if (Player* player = GetPlayerForEscort())
//                    player->FailQuest(QUEST_VORSHA);
//        }
//
//        void JustSummoned(Creature* summoned) override
//        {
//            summoned->AI()->AttackStart(me);
//        }
//
//        bool sQuestAccept(Player* player, Quest const* quest)
//        {
//            if (quest->GetQuestId() == QUEST_VORSHA)
//            {
//                Talk(SAY_MUG_START1);
//                me->setFaction(FACTION_QUEST);
//                npc_escortAI::Start(true, false, player->GetGUID());
//            }
//            return false;
//        }
//
//        void WaypointReached(uint32 waypointId) override
//        {
//            if (Player* player = GetPlayerForEscort())
//            {
//                switch (waypointId)
//                {
//                case 0:
//                    Talk(SAY_MUG_START2, player);
//                    break;
//                case 24:
//                    Talk(SAY_MUG_BRAZIER, player);
//
//                    if (GameObject* go = GetClosestGameObjectWithEntry(me, GO_NAGA_BRAZIER, INTERACTION_DISTANCE * 2))
//                    {
//                        go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
//                        SetEscortPaused(true);
//                    }
//                    break;
//                case 25:
//                    Talk(SAY_MUG_GRATITUDE);
//                    player->GroupEventHappens(QUEST_VORSHA, me);
//                    break;
//                case 26:
//                    Talk(SAY_MUG_PATROL);
//                    break;
//                case 27:
//                    Talk(SAY_MUG_RETURN);
//                    break;
//                }
//            }
//        }
//
//        void DoWaveSummon()
//        {
//            switch (waveId)
//            {
//            case 1:
//                me->SummonCreature(NPC_WRATH_RIDER, FirstNagaCoord[0], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
//                me->SummonCreature(NPC_WRATH_SORCERESS, FirstNagaCoord[1], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
//                me->SummonCreature(NPC_WRATH_RAZORTAIL, FirstNagaCoord[2], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
//                break;
//            case 2:
//                me->SummonCreature(NPC_WRATH_PRIESTESS, SecondNagaCoord[0], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
//                me->SummonCreature(NPC_WRATH_MYRMIDON, SecondNagaCoord[1], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
//                me->SummonCreature(NPC_WRATH_SEAWITCH, SecondNagaCoord[2], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
//                break;
//            case 3:
//                me->SummonCreature(NPC_VORSHA, VorshaCoord, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
//                break;
//            case 4:
//                SetEscortPaused(false);
//                Talk(SAY_MUG_DONE);
//                break;
//            }
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            npc_escortAI::UpdateAI(diff);
//
//            if (!me->GetVictim())
//            {
//                if (HasEscortState(STATE_ESCORT_PAUSED) && _isBrazierExtinguished)
//                {
//                    if (eventTimer < diff)
//                    {
//                        ++waveId;
//                        DoWaveSummon();
//                        eventTimer = 10000;
//                    }
//                    else
//                        eventTimer -= diff;
//                }
//                return;
//            }
//            DoMeleeAttackIfReady();
//        }
//
//    private:
//        uint32 eventTimer;
//        uint8  waveId;
//    public:
//        bool   _isBrazierExtinguished;
//
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_muglashAI(creature);
//    }
//};
//
//class go_naga_brazier : public GameObjectScript
//{
//public:
//    go_naga_brazier() : GameObjectScript("go_naga_brazier") { }
//
//    bool OnGossipHello(Player* /*player*/, GameObject* go) override
//    {
//        if (Creature* creature = GetClosestCreatureWithEntry(go, NPC_MUGLASH, INTERACTION_DISTANCE * 2))
//        {
//            if (npc_muglash::npc_muglashAI* EscortAI = CAST_AI(npc_muglash::npc_muglashAI, creature->AI()))
//            {
//                creature->AI()->Talk(SAY_MUG_BRAZIER_WAIT);
//
//                EscortAI->_isBrazierExtinguished = true;
//                return false;
//            }
//        }
//
//        return true;
//    }
//};
//
//
///*####
//# spell_potion_of_wildfire
//####*/
//
//class spell_potion_of_wildfire : public SpellScriptLoader
//{
//public:
//    spell_potion_of_wildfire() : SpellScriptLoader("spell_potion_of_wildfire") { }
//
//    class spell_potion_of_wildfire_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_potion_of_wildfire_SpellScript);
//
//        void HandleOnHit()
//        {
//            Player* player = GetCaster()->ToPlayer();
//            if (!player) return;
//
//            if (player->GetQuestStatus(QUEST_OF_THEIR_OWN_DESIGN) == QUEST_STATUS_INCOMPLETE)
//            {
//                if (Creature* creature = player->FindNearestCreature(NPC_BATHRANS_CORPSE, 10.0f, true))
//                {
//                    player->KilledMonsterCredit(NPC_BATHRANS_CORPSE);
//                }
//            }
//        }
//
//        void Register()
//        {
//            OnHit += SpellHitFn(spell_potion_of_wildfire_SpellScript::HandleOnHit);
//        }
//
//
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_potion_of_wildfire_SpellScript();
//    }
//};
//
///*####
//# spell_unbathed_concoction
//####*/
//
//class spell_unbathed_concoction : public SpellScriptLoader
//{
//public:
//    spell_unbathed_concoction() : SpellScriptLoader("spell_unbathed_concoction") { }
//
//    class spell_unbathed_concoction_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_unbathed_concoction_SpellScript);
//
//
//        void Unload()
//        {
//            Player* player = GetCaster()->ToPlayer();
//            if (!player) return;
//
//            if (player->GetQuestStatus(QUEST_BATHED_IN_LIGHT) == QUEST_STATUS_INCOMPLETE)
//            {
//                if (GameObject* go = player->FindNearestGameObject(GO_LIGHT_OF_ELUNE_AT_LAKE_FALATHIM, 10.0f))
//                {
//                    if (player->HasItemCount(ITEM_UNBATHED_CONCOCTION, 1))
//                    {
//                        player->DestroyItemCount(ITEM_UNBATHED_CONCOCTION, 1, true);
//                        player->AddItem(ITEM_BATHED_CONCOCTION, 1);
//                    }
//                }
//            }
//        }
//
//
//        void Register() {}
//
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_unbathed_concoction_SpellScript();
//    }
//};
//
///*####
//# npc_feero_ironhand
//####*/
//
//class npc_feero_ironhand : public CreatureScript
//{
//public:
//    npc_feero_ironhand() : CreatureScript("npc_feero_ironhand") { }
//
//    bool OnGossipHello(Player* player, Creature* creature)
//    {
//        if (!player) return true;
//
//        player->PlayerTalkClass->SendCloseGossip();
//
//        if (!creature) return true;
//
//        if (player->GetQuestStatus(QUEST_RESPECT_FOR_THE_FALLEN) == QUEST_STATUS_INCOMPLETE)
//        {
//            if (!player->HasItemCount(ITEM_FEEROS_HOLY_HAMMER, 1))
//            {
//                player->CastSpell(creature, SPELL_CREATE_FEEROS_HOLY_HAMMER_COVER);
//                player->AddItem(ITEM_FEEROS_HOLY_HAMMER, 1);
//            }
//        }
//        return true;
//    }
//};
//
///*####
//# npc_delgren_the_purifier
//####*/
//
//class npc_delgren_the_purifier : public CreatureScript
//{
//public:
//    npc_delgren_the_purifier() : CreatureScript("npc_delgren_the_purifier") { }
//
//    bool OnGossipHello(Player* player, Creature* creature)
//    {
//        if (!player) return true;
//
//        player->PlayerTalkClass->SendCloseGossip();
//
//        if (!creature) return true;
//
//        if (player->GetQuestStatus(QUEST_RESPECT_FOR_THE_FALLEN) == QUEST_STATUS_INCOMPLETE)
//        {
//            if (!player->HasItemCount(ITEM_PURIFIERS_PRAYER_BOOK, 1))
//            {
//                player->CastSpell(creature, SPELL_CREATE_THE_PURIFIERS_PRAYER_BOOK_COVER);
//                player->AddItem(ITEM_PURIFIERS_PRAYER_BOOK, 1);
//            }
//        }
//        return true;
//    }
//};
//
///*######
//## quest 13976 Three Friends of the Forest
//######*/
//
///*######
//## npc_bolyun_1
//######*/
//
//class npc_bolyun_1 : public CreatureScript
//{
//public:
//    npc_bolyun_1() : CreatureScript("npc_bolyun_1") { }
//
//    struct npc_bolyun_1AI : public ScriptedAI
//    {
//        npc_bolyun_1AI(Creature* creature) : ScriptedAI(creature) {}
//
//        uint32 VisibleStatus; // 0=unknown 1=visible 2=invisible
//
//        void ShowCreature(Player* player)
//        {
//            if (VisibleStatus != 1)
//            {
//                me->AddAura(SPELL_BOLYUN_SEE_INVISIBILITY_1, player);
//                VisibleStatus = 1;
//            }
//        }
//
//        void HideCreature(Player* player)
//        {
//            if (VisibleStatus != 2)
//            {
//                player->RemoveAura(SPELL_BOLYUN_SEE_INVISIBILITY_1);
//                player->RemoveAuraFromStack(SPELL_BOLYUN_SEE_INVISIBILITY_1);
//                VisibleStatus = 2;
//            }
//        }
//
//        void Reset()
//        {
//            VisibleStatus = 0;
//        }
//
//        void MoveInLineOfSight(Unit* who)
//        {
//            if (Player* player = who->ToPlayer())
//            {
//                if (player->GetQuestStatus(QUEST_IN_A_BIND) != QUEST_STATUS_REWARDED)
//                {
//                    ShowCreature(player);
//                    return;
//                }
//                HideCreature(player);
//            }
//        }
//
//        bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 opt)
//        {
//            if (quest->GetQuestId() == QUEST_IN_A_BIND)
//                HideCreature(player);
//            return true;
//        }
//
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new npc_bolyun_1AI(creature);
//    }
//};
//
///*######
//## npc_bolyun_2
//######*/
//
//class npc_bolyun_2 : public CreatureScript
//{
//public:
//    npc_bolyun_2() : CreatureScript("npc_bolyun_2") { }
//
//    struct npc_bolyun_2AI : public ScriptedAI
//    {
//        npc_bolyun_2AI(Creature* creature) : ScriptedAI(creature) {}
//
//        uint32 VisibleStatus; // 0=unknown 1=visible 2=invisible
//
//        void ShowCreature(Player* player)
//        {
//            if (VisibleStatus != 1)
//            {
//                me->AddAura(SPELL_BOLYUN_SEE_INVISIBILITY_2, player);
//                VisibleStatus = 1;
//            }
//        }
//
//        void HideCreature(Player* player)
//        {
//            if (VisibleStatus != 2)
//            {
//                player->RemoveAura(SPELL_BOLYUN_SEE_INVISIBILITY_2);
//                player->RemoveAuraFromStack(SPELL_BOLYUN_SEE_INVISIBILITY_2);
//                VisibleStatus = 2;
//            }
//        }
//
//        void Reset()
//        {
//            VisibleStatus = 0;
//        }
//
//        void MoveInLineOfSight(Unit* who)
//        {
//            if (Player* player = who->ToPlayer())
//            {
//                if (player->GetQuestStatus(QUEST_IN_A_BIND) == QUEST_STATUS_REWARDED)
//                    ShowCreature(player);
//                else
//                    HideCreature(player);
//            }
//        }
//
//        bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 opt)
//        {
//            if (quest->GetQuestId() == QUEST_IN_A_BIND)
//                ShowCreature(player);
//            return true;
//        }
//
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new npc_bolyun_2AI(creature);
//    }
//};
//
///*######
//## npc_big_baobob
//######*/
//
//class npc_big_baobob : public CreatureScript
//{
//public:
//    npc_big_baobob() : CreatureScript("npc_big_baobob") { }
//
//    struct npc_big_baobobAI : public ScriptedAI
//    {
//        npc_big_baobobAI(Creature* creature) : ScriptedAI(creature) {}
//
//        uint32  _timer_check_for_player;
//        uint32  _timer_for_spawn_invaders;
//        bool    _IsPlayerNear;
//
//        void Reset()
//        {
//            _timer_check_for_player = 2000; _timer_for_spawn_invaders = 0; _IsPlayerNear = false;
//        }
//
//        void UpdateAI(uint32 diff)
//        {
//            if (_timer_check_for_player <= diff)
//            {
//                _IsPlayerNear = DoCheckForPlayer();
//                _timer_check_for_player = 10000;
//                if (_IsPlayerNear)
//                    _timer_for_spawn_invaders = 1000;
//            }
//            else
//                _timer_check_for_player -= diff;
//
//            if (_IsPlayerNear)
//            {
//                if (_timer_for_spawn_invaders <= diff)
//                {
//                    DoSpawnInvaders();
//                    _timer_for_spawn_invaders = 1000;
//                }
//                else
//                    _timer_for_spawn_invaders -= diff;
//
//            }
//
//            if (!UpdateVictim())
//                return;
//            else
//                DoMeleeAttackIfReady();
//        }
//
//        bool DoCheckForPlayer()
//        {
//            std::list<Player*> PlayerList;
//            Trinity::AnyPlayerInObjectRangeCheck checker(me, 50.0f);
//            Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, PlayerList, checker);
//            me->VisitNearbyWorldObject(50.0, searcher);
//            if (PlayerList.empty()) return false;
//            for (std::list<Player*>::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
//            {
//                if (Player* player = *itr)
//                {
//                    if (!player->GetQuestRewardStatus(QUEST_THE_LAST_STAND))
//                    {
//                        if (player->GetQuestStatus(QUEST_CLEAR_THE_SHRINE) == QUEST_STATUS_INCOMPLETE) return true;
//                        if (player->GetQuestStatus(QUEST_THE_LAST_STAND) == QUEST_STATUS_INCOMPLETE) return true;
//                        if (player->GetQuestRewardStatus(QUEST_CLEAR_THE_SHRINE)) return true;
//                    }
//                }
//            }
//
//            return false;
//        }
//
//        void DoSpawnInvaders()
//        {
//            if (GetCountOfLivingInvaders() >= 4) return;
//            Position pos;
//            me->GetPosition();
//            me->GetRandomNearPosition(30.0f);
//            if (Creature* creature = me->SummonCreature(NPC_DEMONIC_INVADER, pos))
//            {
//                creature->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
//            }
//        }
//
//        uint32 GetCountOfLivingInvaders()
//        {
//            uint32 count = 0;
//            std::list<Creature*> InvadersList;
//            me->GetCreatureListWithEntryInGrid(InvadersList, NPC_DEMONIC_INVADER, 30.0f);
//            if (!InvadersList.empty())
//            {
//                for (std::list<Creature*>::const_iterator itr = InvadersList.begin(); itr != InvadersList.end(); ++itr)
//                {
//                    if (Creature* invader = *itr)
//                    {
//                        if (invader->IsAlive()) count++;
//                    }
//                }
//            }
//            return count;
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new npc_big_baobobAI(creature);
//    }
//};
//
///*######
//## npc_astranaar_burning_fire_bunny
//######*/
//
//class npc_astranaar_burning_fire_bunny : public CreatureScript
//{
//public:
//    npc_astranaar_burning_fire_bunny() : CreatureScript("npc_astranaar_burning_fire_bunny") { }
//
//    struct npc_astranaar_burning_fire_bunnyAI : public ScriptedAI
//    {
//        npc_astranaar_burning_fire_bunnyAI(Creature* creature) : ScriptedAI(creature) {}
//
//        uint32  _timer_check_for_player;
//        uint32  _timer;
//        uint32  _phase;
//        Player* _player;
//
//        void Reset()
//        {
//            _timer_check_for_player = 2000; _phase = 0; _timer = 0;
//            me->AddAura(SPELL_BATHRANS_CORPSE_FIRE, me);
//        }
//
//        void SpellHit(Unit* Hitter, SpellInfo const* spell)
//        {
//            _phase = 1; _player = Hitter->ToPlayer();
//        }
//
//        void UpdateAI(uint32 diff)
//        {
//            if (_timer_check_for_player <= diff)
//            {
//                DoCheckForNearPlayerWithQuest();
//                _timer_check_for_player = 10000;
//            }
//            else
//                _timer_check_for_player -= diff;
//
//            if (_timer <= diff)
//                DoWork();
//            else
//                _timer -= diff;
//
//            if (!UpdateVictim())
//                return;
//            else
//                DoMeleeAttackIfReady();
//        }
//
//        void DoCheckForNearPlayerWithQuest()
//        {
//            std::list<Player*> PlayerList;
//            Trinity::AnyPlayerInObjectRangeCheck checker(me, 50.0f);
//            Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, PlayerList, checker);
//            me->VisitNearbyWorldObject(50.0, searcher);
//            if (PlayerList.empty()) return;
//            for (std::list<Player*>::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
//            {
//                if (Player* player = *itr)
//                {
//                    switch (player->GetQuestStatus(QUEST_ASTRANAARS_BURNING))
//                    {
//                    case QUEST_STATUS_INCOMPLETE:
//                    {
//                        if (!player->HasAura(SPELL_ASTRANAARS_BURNING_SEE_INVISIBLE_01))
//                        {
//                            player->AddAura(SPELL_ASTRANAARS_BURNING_SEE_INVISIBLE_01, player);
//                        }
//                        break;
//                    }
//                    case QUEST_STATUS_COMPLETE:
//                    {
//                        if (player->HasAura(SPELL_ASTRANAARS_BURNING_SEE_INVISIBLE_01))
//                        {
//                            player->RemoveAura(SPELL_ASTRANAARS_BURNING_SEE_INVISIBLE_01);
//                            player->RemoveAuraFromStack(SPELL_ASTRANAARS_BURNING_SEE_INVISIBLE_01, player->GetGUID());
//                        }
//                        break;
//                    }
//                    }
//                }
//            }
//        }
//
//        void DoWork()
//        {
//            switch (_phase)
//            {
//            case 1:
//            {
//                me->RemoveAura(SPELL_BATHRANS_CORPSE_FIRE);
//                me->AddAura(SPELL_ASTRANAARS_BURNING_SMOKE, me);
//                if (_player) _player->KilledMonsterCredit(NPC_ASTRANAARS_BURNING_FIRE_BUNNY);
//                _timer = 60000; _phase = 2;
//                break;
//            }
//            case 2:
//            {
//                me->DespawnOrUnsummon();
//                _timer = 0; _phase = 0;
//                break;
//            }
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new npc_astranaar_burning_fire_bunnyAI(creature);
//    }
//};

enum RuulSnowhoof
{
    NPC_THISTLEFUR_URSA = 3921,
    NPC_THISTLEFUR_TOTEMIC = 3922,
    NPC_THISTLEFUR_PATHFINDER = 3926,
    QUEST_FREEDOM_TO_RUUL = 6482,
    GO_CAGE = 178147,
    RUUL_SHAPECHANGE = 20514,
    SAY_FINISH = 0,
    PATH_ESCORT_RUUL_SNOWHOOF = 102546,
};

Position const RuulSnowhoofSummonsCoord[6] =
{
    { 3449.218018f, -587.825073f, 174.978867f, 4.714445f },
    { 3446.384521f, -587.830872f, 175.186279f, 4.714445f },
    { 3444.218994f, -587.835327f, 175.380600f, 4.714445f },
    { 3508.344482f, -492.024261f, 186.929031f, 4.145029f },
    { 3506.265625f, -490.531006f, 186.740128f, 4.239277f },
    { 3503.682373f, -489.393799f, 186.629684f, 4.349232f }
};

class npc_ruul_snowhoof : public CreatureScript
{
public:
    npc_ruul_snowhoof() : CreatureScript("npc_ruul_snowhoof") { }

    struct npc_ruul_snowhoofAI : public EscortAI
    {
        npc_ruul_snowhoofAI(Creature* creature) : EscortAI(creature) { }

        void Reset() override
        {
            if (GameObject* Cage = me->FindNearestGameObject(GO_CAGE, 20))
                Cage->SetGoState(GO_STATE_READY);
        }

        void JustEngagedWith(Unit* /*who*/) override { }

        void JustSummoned(Creature* summoned) override
        {
            summoned->AI()->AttackStart(me);
        }

        void OnQuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_FREEDOM_TO_RUUL)
            {
                me->SetFaction(FACTION_ESCORTEE_N_NEUTRAL_PASSIVE);
                LoadPath(PATH_ESCORT_RUUL_SNOWHOOF);
                EscortAI::Start(true, player->GetGUID());
            }
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
            case 0:
                me->SetStandState(UNIT_STAND_STATE_STAND);
                if (GameObject* Cage = me->FindNearestGameObject(GO_CAGE, 20))
                    Cage->SetGoState(GO_STATE_ACTIVE);
                break;
            case 13:
                me->SummonCreature(NPC_THISTLEFUR_TOTEMIC, RuulSnowhoofSummonsCoord[0], TEMPSUMMON_DEAD_DESPAWN, 1min);
                me->SummonCreature(NPC_THISTLEFUR_URSA, RuulSnowhoofSummonsCoord[1], TEMPSUMMON_DEAD_DESPAWN, 1min);
                me->SummonCreature(NPC_THISTLEFUR_PATHFINDER, RuulSnowhoofSummonsCoord[2], TEMPSUMMON_DEAD_DESPAWN, 1min);
                break;
            case 19:
                me->SummonCreature(NPC_THISTLEFUR_TOTEMIC, RuulSnowhoofSummonsCoord[3], TEMPSUMMON_DEAD_DESPAWN, 1min);
                me->SummonCreature(NPC_THISTLEFUR_URSA, RuulSnowhoofSummonsCoord[4], TEMPSUMMON_DEAD_DESPAWN, 1min);
                me->SummonCreature(NPC_THISTLEFUR_PATHFINDER, RuulSnowhoofSummonsCoord[5], TEMPSUMMON_DEAD_DESPAWN, 1min);
                break;
            case 27:
                me->SetFaction(me->GetCreatureTemplate()->faction);
                me->RemoveAurasDueToSpell(RUUL_SHAPECHANGE);
                Talk(SAY_FINISH, player);
                player->GroupEventHappens(QUEST_FREEDOM_TO_RUUL, me);
                break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            EscortAI::UpdateAI(diff);
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            if (!me->HasAura(RUUL_SHAPECHANGE))
                me->AddAura(RUUL_SHAPECHANGE, me);
            ScriptedAI::EnterEvadeMode(why);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ruul_snowhoofAI(creature);
    }
};

enum Muglash
{
    SAY_MUG_START1 = 0,
    SAY_MUG_START2 = 1,
    SAY_MUG_BRAZIER = 2,
    SAY_MUG_BRAZIER_WAIT = 3,
    SAY_MUG_ON_GUARD = 4,
    SAY_MUG_REST = 5,
    SAY_MUG_DONE = 6,
    SAY_MUG_GRATITUDE = 7,
    SAY_MUG_PATROL = 8,
    SAY_MUG_RETURN = 9,

    QUEST_VORSHA = 6641,

    GO_NAGA_BRAZIER = 178247,

    NPC_WRATH_RIDER = 3713,
    NPC_WRATH_SORCERESS = 3717,
    NPC_WRATH_RAZORTAIL = 3712,

    NPC_WRATH_PRIESTESS = 3944,
    NPC_WRATH_MYRMIDON = 3711,
    NPC_WRATH_SEAWITCH = 3715,

    NPC_VORSHA = 12940,
    NPC_MUGLASH = 12717,

    PATH_ESCORT_MUGLASH = 101738,
};

//enum Muglash  //duplicate
//{
//    SAY_MUG_START1 = 0,
//    SAY_MUG_START2 = 1,
//    SAY_MUG_BRAZIER = 2,
//    SAY_MUG_BRAZIER_WAIT = 3,
//    SAY_MUG_ON_GUARD = 4,
//    SAY_MUG_REST = 5,
//    SAY_MUG_DONE = 6,
//    SAY_MUG_GRATITUDE = 7,
//    SAY_MUG_PATROL = 8,
//    SAY_MUG_RETURN = 9,
//
//    QUEST_VORSHA = 6641,
//
//    GO_NAGA_BRAZIER = 178247,
//
//    NPC_WRATH_RIDER = 3713,
//    NPC_WRATH_SORCERESS = 3717,
//    NPC_WRATH_RAZORTAIL = 3712,
//
//    NPC_WRATH_PRIESTESS = 3944,
//    NPC_WRATH_MYRMIDON = 3711,
//    NPC_WRATH_SEAWITCH = 3715,
//
//    NPC_VORSHA = 12940,
//    NPC_MUGLASH = 12717
//};
//

Position const FirstNagaCoord[3] =
{
    { 3603.504150f, 1122.631104f,  1.635f, 0.0f },        // rider
    { 3589.293945f, 1148.664063f,  5.565f, 0.0f },        // sorceress
    { 3609.925537f, 1168.759521f, -1.168f, 0.0f }         // razortail
};

Position const SecondNagaCoord[3] =
{
    { 3609.925537f, 1168.759521f, -1.168f, 0.0f },        // witch
    { 3645.652100f, 1139.425415f, 1.322f,  0.0f },        // priest
    { 3583.602051f, 1128.405762f, 2.347f,  0.0f }         // myrmidon
};

Position const VorshaCoord = { 3633.056885f, 1172.924072f, -5.388f, 0.0f };

class npc_muglash : public CreatureScript
{
public:
    npc_muglash() : CreatureScript("npc_muglash") { }

    struct npc_muglashAI : public EscortAI
    {
        npc_muglashAI(Creature* creature) : EscortAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            eventTimer = 10000;
            waveId = 0;
            _isBrazierExtinguished = false;
        }

        void Reset() override
        {
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            if (Player* player = GetPlayerForEscort())
                if (HasEscortState(STATE_ESCORT_PAUSED))
                {
                    if (urand(0, 1))
                        Talk(SAY_MUG_ON_GUARD, player);
                    return;
                }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
                if (Player* player = GetPlayerForEscort())
                    player->FailQuest(QUEST_VORSHA);
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->AI()->AttackStart(me);
        }

        void OnQuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_VORSHA)
            {
                Talk(SAY_MUG_START1);
                me->SetFaction(FACTION_ESCORTEE_N_NEUTRAL_PASSIVE);
                LoadPath(PATH_ESCORT_MUGLASH);
                EscortAI::Start(true, player->GetGUID());
            }
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            if (Player* player = GetPlayerForEscort())
            {
                switch (waypointId)
                {
                case 0:
                    Talk(SAY_MUG_START2, player);
                    break;
                case 24:
                    Talk(SAY_MUG_BRAZIER, player);

                    if (GameObject* go = GetClosestGameObjectWithEntry(me, GO_NAGA_BRAZIER, INTERACTION_DISTANCE * 2))
                    {
                        go->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                        SetEscortPaused(true);
                    }
                    break;
                case 25:
                    Talk(SAY_MUG_GRATITUDE);
                    player->GroupEventHappens(QUEST_VORSHA, me);
                    break;
                case 26:
                    Talk(SAY_MUG_PATROL);
                    break;
                case 27:
                    Talk(SAY_MUG_RETURN);
                    break;
                }
            }
        }

        void DoWaveSummon()
        {
            switch (waveId)
            {
            case 1:
                me->SummonCreature(NPC_WRATH_RIDER, FirstNagaCoord[0], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1min);
                me->SummonCreature(NPC_WRATH_SORCERESS, FirstNagaCoord[1], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1min);
                me->SummonCreature(NPC_WRATH_RAZORTAIL, FirstNagaCoord[2], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1min);
                break;
            case 2:
                me->SummonCreature(NPC_WRATH_PRIESTESS, SecondNagaCoord[0], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1min);
                me->SummonCreature(NPC_WRATH_MYRMIDON, SecondNagaCoord[1], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1min);
                me->SummonCreature(NPC_WRATH_SEAWITCH, SecondNagaCoord[2], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1min);
                break;
            case 3:
                me->SummonCreature(NPC_VORSHA, VorshaCoord, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1min);
                break;
            case 4:
                SetEscortPaused(false);
                Talk(SAY_MUG_DONE);
                break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            EscortAI::UpdateAI(diff);

            if (!me->GetVictim())
            {
                if (HasEscortState(STATE_ESCORT_PAUSED) && _isBrazierExtinguished)
                {
                    if (eventTimer < diff)
                    {
                        ++waveId;
                        DoWaveSummon();
                        eventTimer = 10000;
                    }
                    else
                        eventTimer -= diff;
                }
                return;
            }
            DoMeleeAttackIfReady();
        }

    private:
        uint32 eventTimer;
        uint8  waveId;
    public:
        bool   _isBrazierExtinguished;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_muglashAI(creature);
    }
};

class go_naga_brazier : public GameObjectScript
{
public:
    go_naga_brazier() : GameObjectScript("go_naga_brazier") { }

    struct go_naga_brazierAI : public GameObjectAI
    {
        go_naga_brazierAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipHello(Player* /*player*/) override
        {
            if (Creature* creature = GetClosestCreatureWithEntry(me, NPC_MUGLASH, INTERACTION_DISTANCE * 2))
            {
                if (npc_muglash::npc_muglashAI* pEscortAI = CAST_AI(npc_muglash::npc_muglashAI, creature->AI()))
                {
                    creature->AI()->Talk(SAY_MUG_BRAZIER_WAIT);

                    pEscortAI->_isBrazierExtinguished = true;
                    return false;
                }
            }

            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_naga_brazierAI(go);
    }
};

enum KingoftheFoulwealdMisc
{
    GO_BANNER = 178205
};

// 20783 - Destroy Karang's Banner
class spell_destroy_karangs_banner : public SpellScriptLoader
{
public:
    spell_destroy_karangs_banner() : SpellScriptLoader("spell_destroy_karangs_banner") { }

    class spell_destroy_karangs_banner_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_destroy_karangs_banner_SpellScript);

        void HandleAfterCast()
        {
            if (GameObject* banner = GetCaster()->FindNearestGameObject(GO_BANNER, GetSpellInfo()->GetMaxRange(true)))
                banner->Delete();
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_destroy_karangs_banner_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_destroy_karangs_banner_SpellScript();
    }
};

void AddSC_ashenvale()
{
    new npc_ruul_snowhoof();
    new npc_muglash();
    new go_naga_brazier();
    new spell_destroy_karangs_banner();

    //new npc_torek();
    //new spell_potion_of_wildfire();
    //new spell_unbathed_concoction();
    //new npc_feero_ironhand();
    //new npc_delgren_the_purifier();
    //new npc_bolyun_1();
    //new npc_bolyun_2();
    //new npc_big_baobob();
    //new npc_astranaar_burning_fire_bunny();
}
