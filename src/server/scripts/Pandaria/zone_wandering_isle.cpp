/*
 * Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "SpellInfo.h"




// npc_first_quest_pandaren
class npc_first_quest_pandaren : public CreatureScript
{
public:
    npc_first_quest_pandaren() : CreatureScript("npc_first_quest_pandaren") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_first_quest_pandarenAI (pCreature);
    }

    struct npc_first_quest_pandarenAI : public ScriptedAI
    {
        npc_first_quest_pandarenAI(Creature *c) : ScriptedAI(c)
        {
        }

        uint32 timer;

        void Reset()
        {
            timer = 0;
        }


        void UpdateAI(const uint32 diff)
        {
            if (timer < diff)
            {
                Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                if (!PlayerList.isEmpty())
                {
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        Player *p = i->getSource();
                        if (p)
                        {
                            if (me->GetExactDist(p) < 40)
								if(p->getRace() == RACE_PANDAREN)
								{
									uint32 questId = 0;

									switch(p->getClass())
									{
									case CLASS_MONK:
										questId = 30039;
										break;
									case CLASS_MAGE:
										questId = 30040;
										break;
									case CLASS_HUNTER:
										questId = 30041;
										break;
									case CLASS_PRIEST:
										questId = 30042;
										break;
									case CLASS_ROGUE:
										questId = 30043;
										break;
									case CLASS_SHAMAN:
										questId = 30044;
										break;
									case CLASS_WARRIOR:
										questId = 30045;
										break;
									default: // Not supposed to happen but in case of
										questId = 30044;
										break;
									}

									Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
									if (quest && !p->hasQuest(questId) && p->CanAddQuest(quest, true) && (p->GetQuestStatus(questId) != QUEST_STATUS_COMPLETE) && (p->GetQuestStatus(questId) != QUEST_STATUS_REWARDED))
									{
										p->AddQuest(quest, NULL);
										p->CompleteQuest(questId);
									}
								}
                        }
                    }
                }

                timer = 2000;
            }
            else
                timer -=diff;
        }
    };
};

/*******************************/
/**The Lesson of Stifled Pride**/
/*******************************/

class npc_trainee_stifled_pride : public CreatureScript
{
public :
    npc_trainee_stifled_pride() : CreatureScript("npc_trainee_stifled_pride")
    {
        m_gossipHelloMessage = "Null gossip option" ;
    }

    bool OnGossipHello(Player *p, Creature *c)
    {
        if(p && p->hasQuest(QUEST_THE_LESSON_OF_STIFLED_PRIDE) && !p->isInCombat() && p->GetQuestStatus(QUEST_THE_LESSON_OF_STIFLED_PRIDE) == QUEST_STATUS_INCOMPLETE)
        {
            m_gossipHelloMessage = "Je vous defie !";
            p->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, m_gossipHelloMessage, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            p->PlayerTalkClass->SendGossipMenu(NPC_QUEST_REWARD, c->GetGUID());

            return true ;
        }
        else if(p && (!p->hasQuest(QUEST_THE_LESSON_OF_STIFLED_PRIDE) || p->GetQuestStatus(QUEST_THE_LESSON_OF_STIFLED_PRIDE) != QUEST_STATUS_INCOMPLETE))
        {
            m_gossipHelloMessage = "Il y a erreur... je vous prie de m'excuser" ;
            p->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, m_gossipHelloMessage, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

            p->PlayerTalkClass->SendGossipMenu(NPC_QUEST_REWARD, c->GetGUID());
            return true ;
        }
        else if(!p)
            return false;

		return false ;
    }

    bool OnGossipSelect(Player *p, Creature *c, uint32 sender, uint32 action)
    {
        p->PlayerTalkClass->ClearMenus();

        if(action == GOSSIP_ACTION_INFO_DEF + 1)
            StartQuestEvent(c, p);

        p->CLOSE_GOSSIP_MENU();

		return true ;
    }

    struct npc_trainee_stifled_prideAI : public ScriptedAI
    {
    public :
        npc_trainee_stifled_prideAI(Creature* c) : ScriptedAI(c)
        {

        }

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit *who)
        {
            ScheduleTraineeEvents();
        }

        void UpdateAI(uint32 diff)
        {
            if(!UpdateVictim())
            {
                switch(me->getFaction())
                {
                case 14 :
                    ResetToNormal(NULL);
                    break ;
                case 35 :
                    return ;
                }
            }

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return ;

            if(events.ExecuteEvent() == EVENT_TRAINEE_SPELL)
            {
                switch(me->GetEntry())
                {
                case HUOJIN_TRAINEE_1 :
                case HUOJIN_TRAINEE_2 :
                    if(me->getVictim())
                        DoCast(me->getVictim(), SPELL_JAB, true);
                    break ;

                case TUSHUI_TRAINEE_1 :
                case TUSHUI_TRAINEE_2 :
                    if(me->getVictim())
                        DoCast(me->getVictim(), SPELL_BLACKOUT_KICK, true);
                    break ;

                }
                ScheduleTraineeEvents();
            }
        }

        void DamageTaken(Unit *attacker, uint32 &amount)
        {
            float tenPercent = me->GetMaxHealth() / 10 ;
            if((me->GetHealth() - amount) <= tenPercent)
            {
                amount = 0 ;
                me->SetHealth(uint32(tenPercent));
                ResetToNormal(attacker);
            }
        }

    private :
        EventMap events;

        inline void ScheduleTraineeEvents()
        {
            events.ScheduleEvent(EVENT_TRAINEE_SPELL, urand(3500, 5500));
        }

        void ResetToNormal(Unit* attacker)
        {
            switch(me->GetEntry())
            {
            case HUOJIN_TRAINEE_1 :
            case HUOJIN_TRAINEE_2 :
                if(attacker)
                    me->Say(irand(SAY_HUOJIN_DEFEAT_1, SAY_HUOJIN_DEFEAT_8), LANG_COMMON, attacker->GetGUID());
                break ;
            case TUSHUI_TRAINEE_1 :
            case TUSHUI_TRAINEE_2 :
                if(attacker)
                    me->Say(irand(SAY_TUSHUI_DEFEAT_1, SAY_TUSHUI_DEFEAT_8), LANG_COMMON, attacker->GetGUID());
                break ;
            }
            events.Reset();
            me->setFaction(35);
            me->SetFullHealth();
            me->DisappearAndDie();
        }
    };

    CreatureAI* GetAI(Creature *c) const
    {
        return new npc_trainee_stifled_prideAI(c);
    }

private :

    // Enums
    enum Quests
    {
        QUEST_THE_LESSON_OF_STIFLED_PRIDE = 29524
    };

    enum Npcs
    {
        HUOJIN_TRAINEE_1 = 54586,
        HUOJIN_TRAINEE_2 = 65470,
        TUSHUI_TRAINEE_1 = 54587,
        TUSHUI_TRAINEE_2 = 65471,
        NPC_QUEST_REWARD = 54789 // Spell 102384
    };

    enum Spells
    {
        SPELL_JAB               = 109079, // Huojin
        SPELL_BLACKOUT_KICK     = 109080, // Tushui
        SPELL_QUEST_KILL_CREDIT = 102384
    };

    enum Says
    {
        SAY_HUOJIN_DEFEAT_1 = -5458607,
        SAY_HUOJIN_DEFEAT_2,
        SAY_HUOJIN_DEFEAT_3,
        SAY_HUOJIN_DEFEAT_4,
        SAY_HUOJIN_DEFEAT_5,
        SAY_HUOJIN_DEFEAT_6,
        SAY_HUOJIN_DEFEAT_7,
        SAY_HUOJIN_DEFEAT_8,

        SAY_TUSHUI_DEFEAT_1 = -5458707,
        SAY_TUSHUI_DEFEAT_2,
        SAY_TUSHUI_DEFEAT_3,
        SAY_TUSHUI_DEFEAT_4,
        SAY_TUSHUI_DEFEAT_5,
        SAY_TUSHUI_DEFEAT_6,
        SAY_TUSHUI_DEFEAT_7,
        SAY_TUSHUI_DEFEAT_8
    };

    enum Events
    {
        EVENT_TRAINEE_SPELL = 1
    };

    // Functions
    void StartQuestEvent(Creature* me, Player* quester)
    {
        if(!me || !quester)
            return ;

        if(me->isInCombat())
            return ;

        me->setFaction(14);
        if(me->GetAI())
        {
            me->SetInCombatWith(quester);
            me->GetAI()->AttackStart(quester);
        }
    }

    // Variables
    const char* m_gossipHelloMessage;

    // SQL
    /* UPDATE creature_template SET npcflag = npcflag | 1, gossip_menu_id = 1, ScriptName = "npc_trainee_stifled_pride" WHERE entry IN (54586, 54587, 65470, 65471) ;
     *
     * INSERT INTO script_texts (npc_entry, entry, content_default, content_loc2, type, language, comment) VALUES
     * (54586, -5458607, "I have never seen a trainee with skills such as yours. I must tell the others.", "Je n'ai jamais vu une recrue avant autant d'adresse que vous. Je dois prévenir les autres.", 1, 7, "Trainee of stifled pride - defeat"),
     * (54586, -5458606, "My skills are no match for yours. I admit defeat.", "Mes capacites n'egalent pas les votres. J'admets ma defaite.", 1, 7, "Trainee of stifled pride - defeat"),
     * (54586, -5458605, "Thank you for reminding me that I must train more diligently.", "Merci de m'avoir rappele que je dois m'entraîner avec discernement.", 1, 7, "Trainee of stifled pride - defeat"),
     * (54586, -5458604, "That was a good match. Thank you.", "C'etait un bon combat. Merci a vous.", 1, 7, "Trainee of stifled pride - defeat"),
     * (54586, -5458603, "You are an honorable opponent.", "Vous êtes un adversaire honorable.", 1, 7, "Trainee of stifled pride - defeat"),
     * (54586, -5458602, "You fight honorably, friend.", "Vous avez combattu honorablement mon ami.", 1, 7, "Trainee of stifled pride - defeat"),
     * (54586, -5458601, "You fought well. I must learn more from you in the future.", "Vous vous êtes bien battu. Je dois apprendre plus de vous dans l'avenir.", 1, 7, "Trainee of stifled pride - defeat"),
     * (54586, -5458600, "Your skills are too great. I yield.", "Vos capacites sont impressionnantes. Je m'incline.", 1, 7, "Trainee of stifled pride - defeat"),
     * (54587, -5458707, "I have never seen a trainee with skills such as yours. I must tell the others.", "Je n'ai jamais vu une recrue avant autant d'adresse que vous. Je dois prévenir les autres.", 1, 7, "Trainee of stifled pride - defeat"),
     * (54587, -5458706, "My skills are no match for yours. I admit defeat.", "Mes capacites n'egalent pas les votres. J'admets ma defaite.", 1, 7, "Trainee of stifled pride - defeat"),
     * (54587, -5458705, "Thank you for reminding me that I must train more diligently.", "Merci de m'avoir rappele que je dois m'entraîner avec discernement.", 1, 7, "Trainee of stifled pride - defeat"),
     * (54587, -5458704, "That was a good match. Thank you.", "C'etait un bon combat. Merci a vous.", 1, 7, "Trainee of stifled pride - defeat"),
     * (54587, -5458703, "You are an honorable opponent.", "Vous êtes un adversaire honorable.", 1, 7, "Trainee of stifled pride - defeat"),
     * (54587, -5458702, "You fight honorably, friend.", "Vous avez combattu honorablement mon ami.", 1, 7, "Trainee of stifled pride - defeat"),
     * (54587, -5458701, "You fought well. I must learn more from you in the future.", "Vous vous êtes bien battu. Je dois apprendre plus de vous dans l'avenir.", 1, 7, "Trainee of stifled pride - defeat"),
     * (54587, -5458700, "Your skills are too great. I yield.", "Vos capacites sont impressionnantes. Je m'incline.", 1, 7, "Trainee of stifled pride - defeat") ;
     */
};


/*************************************/
/********The Way of the Tushui********/
/*************************************/

class CheckAysaQuestPredicate
{
public :
    CheckAysaQuestPredicate(uint32 questId, uint32 spellId) : id(questId) { }

    bool operator()(Player* p)
    {
        if(p)
            return (p->HasAura(spell) && p->hasQuest(id)) ;
        return false ;
    }

private:
    uint32 id;
    uint32 spell;
};

const Position SummonPositions[] =
{
    {0.0f, 0.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.0f, 0.0f}
};

const Position MeditationPosition = {0.0f, 0.0f, 0.0f, 0.0f} ;
const Position ShangXiPosition = {0.0f, 0.0f, 0.0f, 0.0f} ;

const Position LiFeiPosition[2] =
{
    {0.0f, 0.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.0f, 0.0f}
};

class npc_aysa_cloudsinger_quest29414 : public CreatureScript
{
public :
    npc_aysa_cloudsinger_quest29414() : CreatureScript("npc_aysa_cloudsinger_29414") {    }

    struct npc_aysa_cloudsinger_quest29414_AI : public ScriptedAI
    {
    public :
        npc_aysa_cloudsinger_quest29414_AI(Creature* c) : ScriptedAI(c)
        {

        }

        void Reset()
        {
            isStarted = false ;
        }

        void DamageTaken(Unit *doneby, uint32 &/*amount*/)
        {
            if(doneby->GetTypeId() != TYPEID_PLAYER)
            {
                events.RescheduleEvent(EVENT_ADD_POWER, 1300);
                events.RescheduleEvent(EVENT_SUMMON_NPCS, 1500);
            }
        }

        void UpdateAI(uint32 diff)
        {
            if(!isStarted)
            {
                if(isAPlayerWithQuestInDist())
                {
                    StartEvent();
                    isStarted = true ;
                }
                else
                    return ;
            }

            events.Update(diff);

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_INTRO :
                    DoIntro();
                    break ;

                case EVENT_ADD_POWER :
                    AddPowerToPlayersOnMap();
                    events.ScheduleEvent(EVENT_ADD_POWER, 1300);
                    break ;

                case EVENT_SUMMON_NPCS :
                    SummonNpcs();
                    events.ScheduleEvent(EVENT_SUMMON_NPCS, 3500);
                    break ;

                case EVENT_LOOK_PLAYERS :
                    if(isAPlayerWithQuestInDist())
                        events.ScheduleEvent(EVENT_LOOK_PLAYERS, 1000);
                    else
                        EndEvent();
                    break ;

                default :
                    break ;
                }
            }

        }

    private :
        // Functions
        inline void StartEvent()
        {
            events.ScheduleEvent(EVENT_INTRO, 3000);
            events.ScheduleEvent(EVENT_ADD_POWER, 1300);
            events.ScheduleEvent(EVENT_SUMMON_NPCS, 5000);
            events.ScheduleEvent(EVENT_LOOK_PLAYERS, 1000);
        }

        void EndEvent()
        {
            events.CancelEvent(EVENT_ADD_POWER);
            events.CancelEvent(EVENT_INTRO);
            events.CancelEvent(EVENT_SUMMON_NPCS);
            events.CancelEvent(EVENT_LOOK_PLAYERS);
            isStarted = false ;
            if(LiFei)
                LiFei->DespawnOrUnsummon();
            Reset();
        }

        bool isAPlayerWithQuestInDist()
        {
            Map* map = me->GetMap();
            if(map)
            {
                Map::PlayerList const& players = map->GetPlayers();

                if(players.isEmpty()) return false ;

                CheckAysaQuestPredicate predicate((uint32)QUEST_THE_WAY_OF_THE_TUSHUI, (uint32)SPELL_PHASE);
                for(Map::PlayerList::const_iterator iter = players.begin() ; iter != players.end() ; ++iter)
                {
                    if(Player* p = iter->getSource())
                    {
                        if(predicate(p))
                            return true ;
                    }
                }
            }

            return false ;
        }

        void AddPowerToPlayersOnMap()
        {
            if(Map* map = me->GetMap())
            {
                Map::PlayerList const& pl = map->GetPlayers();

                if(pl.isEmpty()) return ;

                CheckAysaQuestPredicate predi((uint32)QUEST_THE_WAY_OF_THE_TUSHUI, (uint32)SPELL_PHASE);

                for(Map::PlayerList::const_iterator iter = pl.begin() ; iter != pl.end() ; ++iter)
                    if(predi(iter->getSource()))
                        AddPower(iter->getSource());
            }
        }

        void AddPower(Player* p)
        {
            if(p)
            {
                p->ModifyPower(POWER_ALTERNATE_POWER, 1);
                switch(p->GetPower(POWER_ALTERNATE_POWER))
                {
                case 20 :
                    LiFeiSpeech(LI_FEI_SPEECH_1, p);
                    break;
                case 40 :
                    LiFeiSpeech(LI_FEI_SPEECH_2, p);
                    break ;
                case 60 :
                    LiFeiSpeech(LI_FEI_SPEECH_3, p);
                    break ;
                case 70 :
                    LiFeiSpeech(LI_FEI_SPEECH_4, p);
                    break;
                case 80 :
                    LiFeiSpeech(LI_FEI_SPEECH_5, p);
                    break ;
                case 90 :
                    LiFeiSpeech(LI_FEI_SPEECH_6, p);
                    break ;
                case 100 :
                    p->KilledMonsterCredit(NPC_MASTER_LI_FEI);
                    p->RemoveAura(SPELL_MEDITATION_BAR_2);
                    me->PlayDirectSound(SOUND_END_CAVE, p);
                    me->Say(AYSA_SAY_OUTRO, LANG_COMMON, p->GetGUID());
                    p->RemoveAura(SPELL_PHASE);
                    me->SummonCreature(NPC_MASTER_SHANG_XI, ShangXiPosition);
                    break ;

                default :
                    break ;
                }
            }
        }

        void LiFeiSpeech(int32 id, Player* target)
        {
            if(LiFei && target)
                LiFei->MonsterSay(id, LANG_COMMON, target->GetGUID());
        }

        void SummonNpcs()
        {
            uint8 number = (1 + (rand() % 4));

            for(uint8 i = 0 ; i < number ; ++i)
            {
                Creature * scamp = me->SummonCreature(MOB_SCAMP, SummonPositions[i]);
                if(scamp)
                    scamp->AI()->AttackStart(me);
            }
        }

        void DoIntro()
        {
            LiFei = me->SummonCreature(NPC_MASTER_LI_FEI, LiFeiPosition[0]);
            if(LiFei)
            {
                LiFei->GetMotionMaster()->MovePoint(0, LiFeiPosition[1]);
                LiFei->SetOrientation(me->GetOrientation() - M_PI);
            }
        }

        // Vars
        bool isStarted ;
        EventMap events ;
        Creature* LiFei;
    };

    CreatureAI* GetAI(Creature *c) const
    {
        return new npc_aysa_cloudsinger_quest29414_AI(c);
    }

private :

    // Enums
    enum Quests
    {
        QUEST_THE_WAY_OF_THE_TUSHUI = 29414
    };

    enum Events
    {
        EVENT_ADD_POWER = 1,
        EVENT_SUMMON_NPCS,
        EVENT_INTRO,
        EVENT_LOOK_PLAYERS
    };

    enum Sounds
    {
        SOUND_QUEST_ACCEPT = 0,
        SOUND_START_CAVE = 0,
        SOUND_END_CAVE = 0
    };

    enum Spells
    {
        SPELL_MEDITATION_BAR_2 = 105274,
        SPELL_PHASE = 68243
    };

    enum Npcs
    {
        NPC_MASTER_LI_FEI = 54856,
        NPC_MASTER_SHANG_XI = 54608,
        MOB_SCAMP = 59637,
        NPC_AYSA_QUESTENDER = 0
    };

    enum Areas
    {
        AREA_CAVERN_OF_MEDITATION = 5848
    };

    enum Says
    {
        LI_FEI_SPEECH_1 = -5485605,
        LI_FEI_SPEECH_2,
        LI_FEI_SPEECH_3,
        LI_FEI_SPEECH_4,
        LI_FEI_SPEECH_5,
        LI_FEI_SPEECH_6,

        AYSA_SAY_INTRO = -5964201,
        AYSA_SAY_OUTRO = -5964200
    };

    // Functions

    // Variables
};

/********************************/
/**The Lesson of the Iron Bough**/
/********************************/

class EquippedItemCheckPredicate
{
public :
    EquippedItemCheckPredicate(uint32 questId, uint32 itemId, uint32 itemId2) : item1(itemId), item2(itemId2), quest(questId)
    {
        if(itemId2) twice = true ;
    }

    bool operator()(Player* p)
    {
        if(!p) return false ;

        if(!twice)
        {
            if(p->hasQuest(quest) && p->GetQuestStatus(quest) == QUEST_STATUS_INCOMPLETE && p->GetItemByEntry(item1))
                return(p->GetItemByEntry(item1)->IsEquipped());
        }
        else
        {
            if(p->hasQuest(quest) && p->GetQuestStatus(quest) == QUEST_STATUS_INCOMPLETE && p->GetItemByEntry(item1) && p->GetItemByEntry(item2))
                return(p->GetItemByEntry(item1)->IsEquipped() && p->GetItemByEntry(item2)->IsEquipped());
        }

		return false ;
    }

    bool isTwiced()
    {
        return twice;
    }

private :
    uint32 item1, item2, quest ;
    bool twice ;
};

struct QuestAndItems
{
    uint8 playerClass;
    uint32 quest;
    uint32 questItems[2];
};

QuestAndItems items[] =
{
    {1, 30037, 76391, 72313},
    {2, 30038, 73210, 0},
    {3, 30034, 73211, 0},
    {4, 30036, 73208, 73212},
    {5, 30035, 73207, 76393},
    {8, 30033, 76390, 76392},
    {10, 30027, 73209, 0}
};

class stalker_item_equiped : public CreatureScript
{
public :
    stalker_item_equiped() : CreatureScript("stalker_item_equipped")
    {

    }

    struct stalker_item_equipedAI : public ScriptedAI
    {
    public :
        stalker_item_equipedAI(Creature* c) : ScriptedAI(c)
        {

        }

        void Reset()
        {
            checkTimer = 1000 ;
        }

        void UpdateAI(uint32 diff)
        {
            if(checkTimer <= diff)
            {
                Check();
                checkTimer = 1000 ;
            }
            else checkTimer -= diff ;
        }

    private :
        uint32 checkTimer;

        void Check()
        {
            Map* map = me->GetMap();
            if(!map) return ;

            Map::PlayerList const& pl = map->GetPlayers();

            if(pl.isEmpty()) return ;


            for(Map::PlayerList::const_iterator iter = pl.begin() ; iter != pl.end() ; ++iter)
            {
                if(Player* p = iter->getSource())
                {
                    uint8 pClass = p->getClass();
                    uint8 i = 0 ;
                    for(; i < 7 ; ++i)
                    {
                        if(pClass = items[i].playerClass)
                        {
                            EquippedItemCheckPredicate predicate(items[i].quest, items[i].questItems[0], items[i].questItems[1]);
                            if(predicate(p))
                            {
                                p->KilledMonsterCredit(REWARD_1);
                                if(predicate.isTwiced())
                                        p->KilledMonsterCredit(REWARD_2);
                            }
                            break ;
                        }
                    }
                }
            }
        }

        enum NPCS
        {
            REWARD_1 = 0,
            REWARD_2 = 0
        };
    };

    CreatureAI* GetAI(Creature *c) const
    {
        return new stalker_item_equipedAI(c);
    }
};

/**********************************/
/*****The Disciple's Challenge*****/
/**********************************/

class mob_jaomin_ro : public CreatureScript
{
public :
    mob_jaomin_ro() : CreatureScript("mob_jaomin_ro")
    {

    }

    struct mob_jaomin_roAI : public ScriptedAI
    {
    public :
        mob_jaomin_roAI(Creature* c) : ScriptedAI(c)
        {

        }

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit *pWho)
        {
            if(pWho->GetTypeId() != TYPEID_PLAYER)
            {
                me->Kill(pWho, false);
                EnterEvadeMode();
            }

            ScheduleEvents();
        }

        void DamageTaken(Unit *attacker, uint32 &amount)
        {
            if(me->GetHealth() < amount)
            {
                amount = 0 ;
                me->SetHealth(me->GetMaxHealth()/10);
                me->CombatStop(true);
                EnterEvadeMode();
                if(attacker->ToPlayer())
                    attacker->ToPlayer()->KilledMonsterCredit(me->GetEntry(), 0);
                me->Say(irand(SAY_DEFEAT_1, SAY_DEFEAT_7), LANG_COMMON, attacker->GetGUID());
            }
        }

        void UpdateAI(uint32 diff)
        {
            if(!UpdateVictim())
                return ;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return ;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_HAWK :
                    if(me->getVictim())
                        DoCast(me->getVictim(), SPELL_HAWK, false);
                    events.ScheduleEvent(EVENT_ELEPHANT, 3000);;
                    break ;

                case EVENT_ELEPHANT :
                    if(me->getVictim())
                        DoCast(me->getVictim(), SPELL_ELEPHANT, false);
                    events.ScheduleEvent(EVENT_HAWK, 3000);
                    break;

                case EVENT_ROUNDHOUSE :
                    DoCastAOE(SPELL_ROUNDHOUSE, false);
                    events.ScheduleEvent(EVENT_ROUNDHOUSE, 5000);
                    break;

                default :
                    break ;
                }
            }
            DoMeleeAttackIfReady();
        }

    private :
        EventMap events ;

        inline void ScheduleEvents()
        {
            events.ScheduleEvent(RAND(EVENT_HAWK, EVENT_ELEPHANT), 3000);
            events.ScheduleEvent(EVENT_ROUNDHOUSE, 5000);
        }

        enum Events
        {
            EVENT_HAWK = 1,
            EVENT_ELEPHANT,
            EVENT_ROUNDHOUSE
        };

        enum Spells
        {
            SPELL_HAWK = 108955,
            SPELL_ELEPHANT = 108938,
            SPELL_ROUNDHOUSE = 119301
        };

        enum Says
        {
            SAY_DEFEAT_1 = -5461106,
            SAY_DEFEAT_2,
            SAY_DEFEAT_3,
            SAY_DEFEAT_4,
            SAY_DEFEAT_5,
            SAY_DEFEAT_6,
            SAY_DEFEAT_7
        };
    };

    CreatureAI* GetAI(Creature *c) const
    {
        return new mob_jaomin_roAI(c);
    }

private :
};

/****************************/
/*****The Missing Driver*****/
/****************************/

class MissingDriverCheckPredicate
{
public :
    MissingDriverCheckPredicate(uint32 questId) : quest(questId)
    {

    }

    bool operator()(Player* p)
    {
        if(!p) return false ;

        return(p->hasQuest(quest) && p->GetQuestStatus(quest) == QUEST_STATUS_INCOMPLETE);
    }

private :
    uint32 quest;
};

class mob_amberleaf_scamp29419 : public CreatureScript
{
public :
    mob_amberleaf_scamp29419() : CreatureScript("mob_amberleaf_scamp29419")
    {

    }

    struct mob_amberleaf_scamp29419_AI : public ScriptedAI
    {
    public :
        mob_amberleaf_scamp29419_AI(Creature* c) : ScriptedAI(c)
        {

        }

        void EnterCombat(Unit* who)
        {
            me->GetPosition(&homePosition);
            MissingDriverCheckPredicate predicate(29419);
            if(who->ToPlayer() && predicate(who->ToPlayer()))
            {
                me->GetMotionMaster()->MoveFleeing(who, 0);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                me->Yell(RAND(YELL_FLEE_1, YELL_FLEE_2), LANG_COMMON, who->GetGUID());
                canAttack = false ;
                who->ToPlayer()->KilledMonsterCredit(me->GetEntry(), 0);
            }
            else
                me->AI()->AttackStart(who);
        }

        void Reset()
        {
            canAttack = true ;
            takeThisTimer = 3500 ;
            returnTimer = 7500 ;
        }

        void UpdateAI(uint32 diff)
        {
            if(!UpdateVictim() && canAttack) return ;

            if(!canAttack)
            {
                if(returnTimer <= diff)
                {
                    me->GetMotionMaster()->MovePoint(0, homePosition);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    canAttack = true ;
                    returnTimer = 7500 ;
                }
                else returnTimer -= diff ;
            }
            else
            {
                if(takeThisTimer <= diff)
                {
                    if(me->getVictim())
                        DoCast(me->getVictim(), 109081, false);
                    takeThisTimer = 3000;
                }
                else takeThisTimer -= diff ;
            }
        }

    private :
        uint32 takeThisTimer;
        uint32 returnTimer;
        Position homePosition;
        bool canAttack;

        enum Yells
        {
            YELL_FLEE_1 = -5413001,
            YELL_FLEE_2
        };
    };

    CreatureAI* GetAI(Creature *c) const
    {
        return new mob_amberleaf_scamp29419_AI(c);
    }
};

/****************************/
/*****Fanning the Flames*****/
/****************************/

class spell_summon_living_air : public SpellScriptLoader
{
public :
    spell_summon_living_air() : SpellScriptLoader("spell_quest29523_summon_living_air")
    {

    }

    class spell_summon_living_airSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_summon_living_airSpellScript)

        bool Validate(const SpellInfo *spellInfo)
        {
            if(!sSpellMgr->GetSpellInfo(106999) || !sSpellMgr->GetSpellInfo(102207))
                return false ;

            return true ;
        }

        void HandleDummy(SpellEffIndex effIndex)
        {
            if(Unit* caster = GetCaster())
            {
                caster->CastSpell((Unit*)NULL, 102207, true);
            }
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(spell_summon_living_airSpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_summon_living_airSpellScript();
    }
};

/********************************/
/*****The Challenger's Fires*****/
/********************************/

class TorchEquippedPredicate
{
public :
    TorchEquippedPredicate(uint32 questId, uint32 itemId) : quest(questId), item(itemId)
    {

    }

    bool operator()(Player* p)
    {
        if(!p || !p->GetItemByEntry(item) || !p->hasQuest(quest) || p->GetQuestStatus(quest) != QUEST_STATUS_INCOMPLETE)
            return false ;

        return(p->GetItemByEntry(item)->IsInBag());
    }

private:
    uint32 quest, item;
};

class go_brazier_of_flickering_flames : public GameObjectScript
{
public :
    go_brazier_of_flickering_flames() : GameObjectScript("go_brazier_of_flickering_flames")
    {

    }

    bool OnGossipHello(Player *p, GameObject *go)
    {
        if(!p->hasQuest(29664) || p->GetQuestStatus(29664) != QUEST_STATUS_INCOMPLETE)
            return false ;
        else if(p->hasQuest(29664) && p->GetQuestStatus(29664) == QUEST_STATUS_INCOMPLETE)
        {
            go->CastSpell(p, 105151);
            return true;
        }

		return false ;
    }
};


class npc_shang_xi_the_lesson_of_the_burning_scroll : public CreatureScript
{
public:
    npc_shang_xi_the_lesson_of_the_burning_scroll() : CreatureScript("npc_shang_xi_the_lesson_of_the_burning_scroll") { }
    
    bool OnGossipHello(Player *p, Creature *c)
    {
        if(p->hasQuest(QUEST_THE_LESSON_OF_THE_BURNING_SCROLL))
		{
			if(!p->HasItemCount(FLAMME, 1))
			{
				p->CastSpell(p, SPELL_ANIM_TAKE_FLAME, true);
				p->CastSpell(p, SPELL_CREATE_THE_FLAMME, true);
				p->KilledMonsterCredit(KILL_CREDIT_FLAMME, 0);
				c->MonsterSay(SHANG_XI_TALK, 0, p->GetGUID());
			}

		} else if(p->GetQuestStatus(QUEST_THE_LESSON_OF_THE_BURNING_SCROLL) == QUEST_STATUS_COMPLETE) {
			if (c->isQuestGiver())
				p->PrepareQuestMenu(c->GetGUID());
				p->PlayerTalkClass->SendGossipMenu(1,  c->GetGUID());
		}

		return true;
    }
private: 
	enum enums
	{
		QUEST_THE_LESSON_OF_THE_BURNING_SCROLL = 29408,
		SPELL_ANIM_TAKE_FLAME = 114746,
		FLAMME = 80212,
		SPELL_CREATE_THE_FLAMME = 114611,
		SHANG_XI_TALK = 0,
		KILL_CREDIT_FLAMME = 59591
	};
};

class gob_edict_of_temperance_the_lesson_of_the_burning_scroll : public GameObjectScript
{
public:
	gob_edict_of_temperance_the_lesson_of_the_burning_scroll() : GameObjectScript("gob_edict_of_temperance_the_lesson_of_the_burning_scroll") { }

	bool OnGossipHello(Player* p, GameObject* gob)
	{
		if(p->HasItemCount(FLAMME, 1))
		{
			p->KilledMonsterCredit(KILL_CREDIT_BURN, 0);
			p->CastSpell(p, SPELL_NEW_PHASE, true);
			p->RemoveAura(p->GetAura(59073)); // Enlève la phase 2

			p->DestroyItemCount(FLAMME, 1, true);
			if(GameObject* go = ObjectAccessor::GetGameObject(*p, 400014))
				if(Creature* npc = go->FindNearestCreature(TRACKER, 10, true))
					npc->CastSpell(npc, SPELL_BURN, true);
		}

		return true;
	}
private:
	enum enums
	{
		TRACKER = 65490,
		FLAMME = 80212,
		SPELL_BURN = 88579,
		SPELL_NEW_PHASE = 59074, // Tester si le changement de phase marche bien
		KILL_CREDIT_BURN = 59570
	};
};


void AddSC_wandering_isle()
{
    new npc_first_quest_pandaren();
	
	new npc_trainee_stifled_pride();
    new npc_aysa_cloudsinger_quest29414();
    new stalker_item_equiped();
    new mob_jaomin_ro();
    new mob_amberleaf_scamp29419();
    new spell_summon_living_air();
    new go_brazier_of_flickering_flames();
	
	new npc_shang_xi_the_lesson_of_the_burning_scroll();
	new gob_edict_of_temperance_the_lesson_of_the_burning_scroll();
}
