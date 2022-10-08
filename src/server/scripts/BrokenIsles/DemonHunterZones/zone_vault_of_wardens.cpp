/*
* Copyright (C) 2021 BfaCore Reforged
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


/************************************TODO**************************************
-boss ash'golm script - npc 96681
    NOTE: donot use the instance VoW script, cannot be used for 1 player!
    -he should be "frozen", and non attackable.
    -animations for countermeasures.

-boss glazer script   - npc 96680
    NOTE: donot use the instance VoW script, cannot be used for 1 player!
    -"laser" animations for mirrors.
    -he should be stunned and nonattackable.

-add missing creature texts and waypoints

-khadgar crow animation

-add check to quests for vengeance and havoc talents,
 and choose quests by talent spec.


******************************************************************************/


#include "ScriptedEscortAI.h"
#include "CreatureTextMgr.h"
#include "MapManager.h"
#include "ScriptMgr.h"
#include "GameObjectAI.h"
#include "Conversation.h"
#include "UpdateData.h"
#include "GameObject.h"
#include "ObjectMgr.h"


// npc 92782 92776 quest 38689 (savage felstalker, Fel Shocktrooper)
class npc_q38689 : public CreatureScript
{
public:
    npc_q38689() : CreatureScript("npc_q38689") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_q38689AI(creature);
    }

    struct npc_q38689AI : public ScriptedAI
    {

        npc_q38689AI(Creature* creature) : ScriptedAI(creature)
        {
            creature->SetCorpseDelay(30);
            creature->SetRespawnDelay(15);
        }

        EventMap events;

        enum data
        {
            QUEST = 38689,
            SPELL_CREDIT = 133511,
            SPELL_CREDIT2 = 133509,
        };

        void Reset() override
        {
            events.Reset();
            if (me->GetVictim() || me->IsInEvadeMode())
                return;

            std::list<Unit*> list;
            me->GetAttackableUnitListInRange(list, 70.0f);
            for (auto enemy : list)
            {
                if (enemy->ToPlayer())
                    continue;
                me->AI()->AttackStart(enemy);
                break;
            }
        }

        void EnterCombat(Unit* who) override
        {
            if (me->GetEntry() == 92782)
                events.RescheduleEvent(1, 15000);

            if (me->GetEntry() == 92776)
            {
                //Talk(urand(0, 10));
                events.RescheduleEvent(2, 14000);
                events.RescheduleEvent(3, 20000);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            std::list<Player*> lList;
            me->GetPlayerListInGrid(lList, 5.0f);
            for (auto player : lList)
            {
                if (player->GetQuestStatus(QUEST) == QUEST_STATUS_INCOMPLETE)
                {
                    uint32 ra = urand(2, 10);
                    for (uint8 i = 0; i < ra; i++)
                    {
                        player->CastSpell(player, SPELL_CREDIT, true);
                        player->CastSpell(player, SPELL_CREDIT2, true);
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);
            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case 1:
                        DoCast(200992);
                        events.RescheduleEvent(1, 15000);
                        break;
                    case 2:
                        DoCast(200930);
                        events.RescheduleEvent(2, 14000);
                        break;
                    case 3:
                        DoCast(200963);
                        events.RescheduleEvent(3, 20000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

// npc 92990 97632 quest 38723 (sledge, crusher)
class npc_q38723 : public CreatureScript
{
public:
    npc_q38723() : CreatureScript("npc_q38723") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_q38723AI(creature);
    }

    struct npc_q38723AI : public ScriptedAI
    {

        npc_q38723AI(Creature* creature) : ScriptedAI(creature)
        {
            creature->SetCorpseDelay(30);
            creature->SetRespawnDelay(15);
        }

        EventMap events;

        enum data
        {
            QUEST = 38723,
            SPELL_CREDIT = 210461,
            SPELL_CREDIT2 = 195327,
        };

        void Reset() override
        {
            events.Reset();

            if (me->GetVictim() || me->IsInEvadeMode())
                return;

            std::list<Unit*> list;
            me->GetAttackableUnitListInRange(list, 70.0f);
            for (auto enemy : list)
            {
                if (enemy->ToPlayer())
                    continue;
                me->AI()->AttackStart(enemy);
                break;
            }
        }

        void EnterCombat(Unit* who) override
        {
            if (me->GetEntry() == 92990)
                events.RescheduleEvent(1, 20000);

            if (me->GetEntry() == 97632)
                events.RescheduleEvent(2, 16000);

            events.RescheduleEvent(3, 42000);
        }

        void DamageTaken(Unit* attacker, uint32 &damage) override
        {
            if (Creature* oAdd = GetOtherAdd())
            {
                if (damage >= me->GetHealth())
                    oAdd->Kill(oAdd, true);
                else
                    oAdd->SetHealth(oAdd->GetHealth() - damage);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            std::list<Player*> lList;
            me->GetPlayerListInGrid(lList, 200.0f);
            for (auto player : lList)
            {
                if (player->GetQuestStatus(QUEST) == QUEST_STATUS_INCOMPLETE)
                {
                    me->CastSpell(player, SPELL_CREDIT, true);
                    player->KilledMonsterCredit(106241);

                    player->CastSpell(player, SPELL_CREDIT2, true);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case 1:
                        DoCast(199602);
                        events.RescheduleEvent(1, 20000);
                        break;
                    case 2:
                        DoCast(199645);
                        events.RescheduleEvent(2, 16000);
                        break;
                    case 3:
                        DoCast(199556);
                        events.RescheduleEvent(3, 42000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        Creature* GetOtherAdd()
        {
            if (Creature* oAdd = me->FindNearestCreature((me->GetEntry() == 92990 ? 92990 : 97632), 100.0f, true))
                if (oAdd->IsAlive())
                    return oAdd;

            return NULL;
        }
    };
};

// npc 99443 (vampiric felbat)
class npc_99443 : public CreatureScript
{
public:
    npc_99443() : CreatureScript("npc_99443") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_99443AI(creature);
    }

    struct npc_99443AI : public npc_escortAI
    {
        npc_99443AI(Creature* creature) : npc_escortAI(creature)
        {
            me->SetCanFly(true);
            me->SetSpeed(MOVE_FLIGHT, 26);
            me->SetReactState(REACT_PASSIVE);
            me->SetMovementAnimKitId(3);
            me->SetSpeed(MOVE_FLIGHT, 75);
        }

        void OnCharmed(bool /*apply*/) override
        {
            if (me->NeedChangeAI)
                me->NeedChangeAI = false;
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool /*apply*/) override
        {
            who->ToPlayer()->KilledMonsterCredit(96659);
            Start(false, true, who->GetGUID());
        }
    };
};

// npc 99709 99731 99732 - quest 39685 (Countermeasures)
class npc_q39685 : public CreatureScript
{
public:
    npc_q39685() : CreatureScript("npc_q39685") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_q39685AI(creature);
    }

    enum data
    {
        SPELL_ID = 0,
        SPELL_AURA = 195189,
    };

    struct npc_q39685AI : public ScriptedAI
    {
        npc_q39685AI(Creature* creature) : ScriptedAI(creature), cooldown(0) {}

        uint32 cooldown;

        void Reset() override
        {
            cooldown = 0;
            me->SetNpcFlags(UNIT_NPC_FLAG_SPELLCLICK);
            me->RemoveAurasDueToSpell(SPELL_AURA);
            me->CastSpell(me, SPELL_AURA, true);
        }

        void OnSpellClick(Unit* Clicker, bool& /*result*/) override
        {
            if (cooldown)
                return;

            Clicker->ToPlayer()->KilledMonsterCredit(me->GetEntry());

            cooldown = 5000;
            me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            return;
        }

        void UpdateAI(uint32 diff) override
        {
            if (cooldown)
            {
                if (cooldown <= diff)
                {
                    me->SetNpcFlags(UNIT_NPC_FLAG_SPELLCLICK);
                    cooldown = 0;
                }
                else
                    cooldown -= diff;
            }
        }
    };
};

// npc 96675 (Allari the Souleater)
class npc_96675 : public CreatureScript
{
public:
    npc_96675() : CreatureScript("npc_96675") {}

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        // quest 39683 - forged in fire
        if (quest->GetQuestId() == 39683)
            if (const Quest* quest = sObjectMgr->GetQuestTemplate(40254))
                player->AddQuest(quest, nullptr); // add quest "40254 forged in fire" also

        // quest 39684 - beam me up
        if (quest->GetQuestId() == 39686)
        {
            WorldLocation location(1468, 4317.87f, -451.61f, 259.36f, player->GetOrientation());
            player->SetHomebind(location, 7866);
            player->SendBindPointUpdate();

            player->KilledMonsterCredit(96814);
            //creature->AI()->Talk(0);
        }

        return true;
    }
};

// gob 244455 - quest 40373 (pool of judgements)
class go_244455 : public GameObjectScript
{
public:
    go_244455() : GameObjectScript("go_244455") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->IsActiveQuest(40373))
        {
            player->KilledMonsterCredit(100166);
            player->SendMovieStart(478);
        }
        return true;
    }
};

// npc 97644 (Kor'vas Bloodthorn)
class npc_97644 : public CreatureScript
{
public:
    npc_97644() : CreatureScript("npc_97644") {}

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == 40373)
            player->CastSpell(player, 196650, true); // cast player choice window

        return true;
    }
};

// spell 196650 (follower choice)
class PlayerScript_follower_choice : public PlayerScript
{
public:
    PlayerScript_follower_choice() : PlayerScript("PlayerScript_follower_choice") {}

    enum data
    {
        PLAYER_CHOICE_DH_FOLLOWER_SELECTION         = 234,
        PLAYER_CHOICE_DH_FOLLOWER_SELECTION_KAYN    = 486,
        PLAYER_CHOICE_DH_FOLLOWER_SELECTION_ALTRUIS = 487,

        SPELL_NEW_DIRECTION_CHOSE_ALTRUIS = 196662,
        SPELL_NEW_DIRECTION_CHOSE_KAYN    = 196661,

        CREDIT = 99278,
    };

    void OnPlayerChoiceResponse(Player* player, uint32 choiceID, uint32 responseID)
    {
        if (choiceID != PLAYER_CHOICE_DH_FOLLOWER_SELECTION)
            return;

        switch (responseID)
        {
            case PLAYER_CHOICE_DH_FOLLOWER_SELECTION_KAYN:
                player->CastSpell(player, SPELL_NEW_DIRECTION_CHOSE_KAYN, true);
                break;
            case PLAYER_CHOICE_DH_FOLLOWER_SELECTION_ALTRUIS:
                player->CastSpell(player, SPELL_NEW_DIRECTION_CHOSE_ALTRUIS, true);
                break;
            default:
                break;
        }

        player->KilledMonsterCredit(CREDIT); // Credit: Choose Kayn or Altruis
    }
};

// npc 92718 (Maiev Shadowsong)
class npc_92718 : public CreatureScript
{
public:
    npc_92718() : CreatureScript("npc_92718") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        //if (quest->GetQuestId() == 38672)
            //creature->AI()->Talk(1);

        //quest 38723 - Stop gul'dan!
        if (quest->GetQuestId() == 38723)
        {
            player->AddQuest(sObjectMgr->GetQuestTemplate(40253), nullptr);    // add quest "40253 stop gul'dan!" also
            player->TeleportTo(1468, 4084.27f, -298.11f, -282.07f, 3.118031f); // teleport inside chamber
            player->CastSpell(player, 187864, true);                           // gul'dan stealing illidan scene
            player->KilledMonsterCredit(99303);                                // enter the chamber credit
        }

        return true;
    }
};

// npc 103658 103655 (Kayn's Cell, Altruis's Cell)
class npc_q38672 : public CreatureScript
{
public:
    npc_q38672() : CreatureScript("npc_q38672") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_q38672AI(creature);
    }

    struct npc_q38672AI : public Scripted_NoMovementAI
    {
        npc_q38672AI(Creature* creature) : Scripted_NoMovementAI(creature) {}

        void OnSpellClick(Unit* Clicker, bool& /*result*/) override
        {
            if (Clicker->GetTypeId() == TYPEID_PLAYER)
            {
                Player* player = Clicker->ToPlayer();
                if (player->IsActiveQuest(38672))
                {
                    // alturius
                    if (me->GetEntry() == 103655)
                    {
                        std::list<Creature*> alturius;
                        me->GetCreatureListWithEntryInGrid(alturius, 99632, 10.0f);
                        for (Creature* cre : alturius)
                            cre->Respawn();

                        Clicker->ToPlayer()->KilledMonsterCredit(92849);
                        me->DestroyForPlayer(player);
                    }

                    // kayn
                    if (me->GetEntry() == 103658)
                    {
                        std::list<Creature*> kayn;
                        me->GetCreatureListWithEntryInGrid(kayn, 99631, 10.0f);
                        for (Creature* cre : kayn)
                            cre->Respawn();

                        Clicker->ToPlayer()->KilledMonsterCredit(92848);
                        me->DestroyForPlayer(player);
                    }
                }
            }
        }
    };
};

// gob 244923 (lever)
class go_244923 : public GameObjectScript
{
public:
    go_244923() : GameObjectScript("go_244923") { }

    bool OnQuestReward(Player* player, GameObject* go, Quest const* quest, uint32) override
    {
        if (quest->GetQuestId() == 38672)
        {
            /* vaultdoors "animation" */
            if (GameObject* vaultdoors = player->SummonGameObject(399999, 4325.98f, -578.061f, -281.808f, 1.62673f, QuaternionData(-0.0f, -0.0f, -0.726604f, -0.687056f), 0, true))
            {
                vaultdoors->GetScheduler()
                    .Schedule(0s, [](TaskContext context)
                        {
                            GetContextGameObject()->SetLootState(GO_READY);
                            GetContextGameObject()->UseDoorOrButton(10000);
                        })
                    .Schedule(4s, [](TaskContext context)
                        {
                            GetContextGameObject()->Delete();
                        });
            }

            // this needs a tempsummmon and a phase!
            /*if (Creature* cre = player->FindNearestCreature(92718, 25.0f, true))
                cre->GetMotionMaster()->MovePoint(0, 4325.57f, -562.81f, -281.74f);*/

            if (Creature* cre = player->FindNearestCreature(99631, 25.0f, true))
            {
                cre->GetMotionMaster()->MovePoint(0, 4330.08f, -548.28f, -281.75f);
                cre->DespawnOrUnsummon(5000);
            }

            if (Creature* cre = player->FindNearestCreature(99632, 25.0f, true))
            {
                cre->GetMotionMaster()->MovePoint(0, 4321.75f, -548.86f, -281.75f);
                cre->DespawnOrUnsummon(5000);
            }
        }

        return true;
    }
};

// spell 199760 (Burning Fel)
class spell_199760 : public SpellScriptLoader
{
public:
    spell_199760() : SpellScriptLoader("spell_199760") { }

    SpellScript* GetSpellScript() const override
    {
        return new spell_199760_SpellScript();
    }

    class spell_199760_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_199760_SpellScript);

        void HandleDummy(SpellEffIndex )
        {
            PreventHitDefaultEffect(EFFECT_0);

            if (!GetCaster())
                return;

            Position pos;
            GetCaster()->GetRandomNearPosition(20.0f);
            WorldLocation* dest = const_cast<WorldLocation*>(GetExplTargetDest());
            dest->Relocate(pos);
        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_199760_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
        }
    };
};

// gob 244582 quest 38669 (Demon Hunter Weapon Rack)
class go_244582 : public GameObjectScript
{
public:
    go_244582() : GameObjectScript("go_244582") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if(player->IsActiveQuest(38669))
            player->ForceCompleteQuest(38669); // add new warglaives

        return false;
    }
};

// gob 244925 (doors - ward of the hunters)
class go_244925 : public GameObjectScript
{
public:
    go_244925() : GameObjectScript("go_244925") { }

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_244925AI(go);
    }

    struct go_244925AI : public GameObjectAI
    {
        go_244925AI(GameObject* go) : GameObjectAI(go) {}

        void UpdateAI(uint32 diff) override
        {
            std::list<Player*> list;
            list.clear();
            go->GetPlayerListInGrid(list, 50.0f);
            if (!list.empty())
            {
                for (std::list<Player*>::const_iterator itr = list.begin(); itr != list.end(); ++itr)
                {
                    if ((*itr)->IsQuestRewarded(38672))
                        go->DestroyForPlayer(*itr);
                }
            }
        }
    };
};

// gob 244588 quest 38690 (Warden Cell)
class go_244588 : public GameObjectScript
{
public:
    go_244588() : GameObjectScript("go_244588") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->IsActiveQuest(38690))
            go->DestroyForPlayer(player);

        return false;
    }
};

// gob 245467 (doors - vault of betrayer)
class go_245467 : public GameObjectScript
{
public:
    go_245467() : GameObjectScript("go_245467") { }

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_245467AI(go);
    }

    struct go_245467AI : public GameObjectAI
    {
        go_245467AI(GameObject* go) : GameObjectAI(go) {}

        void UpdateAI(uint32 diff) override
        {
            std::list<Player*> list;
            list.clear();
            go->GetPlayerListInGrid(list, 50.0f);
            if (!list.empty())
            {
                for (std::list<Player*>::const_iterator itr = list.begin(); itr != list.end(); ++itr)
                {
                    if ((*itr)->IsActiveQuest(38723) || (*itr)->IsQuestRewarded(38723))
                        go->DestroyForPlayer(*itr);
                }
            }
        }
    };
};

// npc 97978 (Archmage Khadgar)
class npc_97978 : public CreatureScript
{
public:
    npc_97978() : CreatureScript("npc_97978") { }
    enum eKhadgar
    {
        QUEST_ILLIDARI_LEAVING_A = 39689,
        QUEST_ILLIDARI_LEAVING_H = 39690,
        SPELL_TELEPORT_TO_STORMWIND = 258310,
        SPELL_TELEPORT_TO_ORGRIMMAR = 192758,
    };
    bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 /*opt*/) override
    {
        if (quest->GetQuestId() == QUEST_ILLIDARI_LEAVING_H)
        {
            /* ogrimmar */
            WorldLocation location(1, 1463.209961f, -4421.189941f, 25.450001f, player->GetOrientation());
            player->SetHomebind(location, 1637);
            player->SendBindPointUpdate();

            player->CastSpell(player, SPELL_TELEPORT_TO_ORGRIMMAR, true);
        }
        else if (quest->GetQuestId() == QUEST_ILLIDARI_LEAVING_A)
        {
            /* stormwind */
            WorldLocation location(0, -8166.649902f, 784.719971f, 76.356918f, player->GetOrientation());
            player->SetHomebind(location, 9171);
            player->SendBindPointUpdate();

            player->CastSpell(player, SPELL_TELEPORT_TO_STORMWIND, true);
        }

        return true;
    }
};

// world bonus quest 39742
class PlayerScript_bonus_objective : public PlayerScript
{
public:
    PlayerScript_bonus_objective() : PlayerScript("PlayerScript_bonus_objective") {}

    uint32 QUEST_BREAKING_OUT         = 38672;
    uint32 QUEST_VAULT_OF_THE_WARDENS = 39742;

    uint32 checkTimer = 1000;

        void OnUpdate(Player * player, uint32 diff) override
        {
        if (checkTimer <= diff)
        {
            if (player->getClass() == CLASS_DEMON_HUNTER && player->GetAreaId() == 7873 && player->GetQuestStatus(QUEST_BREAKING_OUT) == QUEST_STATUS_REWARDED)
            {
                if (player->GetQuestStatus(QUEST_VAULT_OF_THE_WARDENS) == QUEST_STATUS_NONE)
                {
                    if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_VAULT_OF_THE_WARDENS))
                        player->AddQuest(quest, nullptr);
                }
            }

            checkTimer = 1000;
        }
        else checkTimer -= diff;
    }
};

// npc 96682 (immolanth)
class npc_96682 : public CreatureScript
{
public:
    npc_96682() : CreatureScript("npc_96682") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_96682AI(creature);
    }

    struct npc_96682AI : public ScriptedAI
    {
        npc_96682AI(Creature* creature) : ScriptedAI(creature)
        {
            creature->SetCorpseDelay(30);
            creature->SetRespawnDelay(15);
        }

        enum data
        {
            QUEST1 = 39683,
            QUEST2 = 40254,

            CREDIT1 = 97970,
            CREDIT2 = 106254,

            REWARD_SPELL1 = 210486,
            REWARD_SPELL2 = 195440,

            SPELL_1 = 199828,
            SPELL_2 = 199758,
        };

        void Reset() override
        {
            // adjust starting health
            me->SetHealth(me->CountPctFromMaxHealth(21));
            me->setRegeneratingHealth(false);

            events.Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            //Talk(0);
            events.RescheduleEvent(1, 15000);
            events.RescheduleEvent(2, 20000);
        }


        void JustDied(Unit* killer) override
        {
            Player* player = killer->ToPlayer();
            if (!player)
                return;

            //Talk(3);

            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 60.0f);
            for (auto plr : playerList)
            {
                if (plr->GetQuestStatus(QUEST1) == QUEST_STATUS_INCOMPLETE ||
                    plr->GetQuestStatus(QUEST2) == QUEST_STATUS_INCOMPLETE)
                {
                    plr->KilledMonsterCredit(CREDIT1);
                    plr->KilledMonsterCredit(CREDIT2);
                    plr->CastSpell(plr, REWARD_SPELL1, true);
                    plr->CastSpell(plr, REWARD_SPELL2, true);
                }

                me->DestroyForPlayer(plr);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCast(SPELL_1);
                    events.RescheduleEvent(1, 31000);
                    break;
                case 2:
                    DoCast(SPELL_2);
                    events.RescheduleEvent(2, 40000);
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

// npc 96783 (Bastillax)
class npc_96783 : public CreatureScript
{
public:
    npc_96783() : CreatureScript("npc_96783") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_96783AI(creature);
    }

    struct npc_96783AI : public ScriptedAI
    {
        npc_96783AI(Creature* creature) : ScriptedAI(creature)
        {
            creature->SetCorpseDelay(30);
            creature->SetRespawnDelay(15);
        }

        enum data
        {
            QUEST1 = 39694,
            QUEST2 = 40256,
            QUEST3 = 39688,
            QUEST4 = 40255,

            CREDIT1 = 106255,
            CREDIT2 = 113812,

            REWARD_SPELL1 = 210500,
            REWARD_SPELL2 = 195450,

            SPELL1 = 200027,
            SPELL2 = 200007,
            SPELL3 = 200353,
            SPELL4 = 200002,
        };

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            //Talk(0);
            events.RescheduleEvent(1, 45000);
            events.RescheduleEvent(2, 5000);
            events.RescheduleEvent(3, 15000);
            events.RescheduleEvent(4, 23000);
        }


        void JustDied(Unit* killer) override
        {
            Player* player = killer->ToPlayer();
            if (!player)
                return;

            //Talk(2);

            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 60.0f);
            for (auto plr : playerList)
            {
                if (plr->GetQuestStatus(QUEST1) == QUEST_STATUS_INCOMPLETE ||
                    plr->GetQuestStatus(QUEST2) == QUEST_STATUS_INCOMPLETE ||
                    plr->GetQuestStatus(QUEST3) == QUEST_STATUS_INCOMPLETE ||
                    plr->GetQuestStatus(QUEST4) == QUEST_STATUS_INCOMPLETE)
                {
                    plr->KilledMonsterCredit(CREDIT1);
                    plr->KilledMonsterCredit(CREDIT2);
                    plr->CastSpell(plr, REWARD_SPELL1, true);
                    plr->CastSpell(plr, REWARD_SPELL2, true);
                }

                me->DestroyForPlayer(plr);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCast(SPELL1);
                    events.RescheduleEvent(1, 45000);
                    break;
                case 2:
                    DoCast(SPELL2);
                    events.RescheduleEvent(2, 35000);
                    break;
                case 3:
                    DoCast(SPELL3);
                    //Talk(1);
                    events.RescheduleEvent(3, 50000);
                    break;
                case 4:
                    DoCast(SPELL4);
                    events.RescheduleEvent(4, 23000);
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_zone_vault_of_wardens()
{
    new npc_q38689();                   // npc 92782 92776 quest 38689 (savage felstalker, Fel Shocktrooper)
    new npc_q38723();                   // npc 92990 97632 quest 38723 (sledge, crusher)
    new npc_99443();                    // npc 99443 (vampiric felbat)
    new npc_q39685();                   // npc 99709 99731 99732 - quest 39685 (Countermeasures)
    new npc_96675();                    // npc 96675 (Allari the Souleater)
    new go_244455();                    // gob 244455 - quest 40373 (pool of judgements)
    new npc_97644();                    // npc 97644 (Kor'vas Bloodthorn)
    new PlayerScript_follower_choice(); // spell 196650 (follower choice)
    new npc_92718();                    // npc 92718 (Maiev Shadowsong)
    new npc_q38672();                   // npc 103658 103655 (Kayn's Cell, Altruis's Cell)
    new go_244923();                    // gob 244923 (lever)
    new spell_199760();                 // spell 199760 (Burning Fel)
    new go_244582();                    // gob 244582 quest 38669 (Demon Hunter Weapon Rack)
    new go_244925();                    // gob 244925 (doors - ward of the hunters)
    new go_244588();                    // gob 244588 quest 38690 (Warden Cell)
    new go_245467();                    // gob 245467 (doors - vault of betrayer)
    new npc_97978();                    // npc 97978 (Archmage Khadgar)
    new PlayerScript_bonus_objective(); // world bonus quest 39742
    new npc_96682();                    // npc 96682 (immolanth)
    new npc_96783();                    // npc 96783 (Bastillax)
}
