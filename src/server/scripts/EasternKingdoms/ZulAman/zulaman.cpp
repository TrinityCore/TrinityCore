/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Zulaman
SD%Complete: 90
SDComment: Forest Frog will turn into different NPC's. Workaround to prevent new entry from running this script
SDCategory: Zul'Aman
EndScriptData */

/* ContentData
npc_forest_frog
EndContentData */

#include "ScriptPCH.h"
#include "zulaman.h"

float GauntletWaypoints[8][3] =
{
    {227.510f, 1459.576f, 25.920f},// Gauntled -- Point 1 Start
    {227.684f, 1438.195f, 26.271f},// Gauntled -- Point 2 RampStart
    {229.847f, 1380.534f, 45.460f},// Gauntled -- Point 3 RampEnd
    {248.919f, 1370.393f, 49.322f},// Gauntled -- Point 4 secound flor
    {282.367f, 1379.441f, 49.323f},// Gauntled -- Point 5 Stares begin
    {301.168f, 1385.222f, 57.678f},// Gauntled -- Point 6 Stares middle 1
    {313.466f, 1388.549f, 57.401f},// Gauntled -- Point 7 Stares middle 2
    {335.775f, 1395.879f, 74.581f} // Gauntled -- Point 8 Stares end
};

float WarriorSpawnPos[3] = {247.396f, 1464.760f, 26.266f};
float EagleSpawnPos[3] = {301.168f, 1385.222f, 57.678f};

const float DrumPositions[4][3] =
{
    {-195.533f, 1357.579f, 0.4279f},
    {-185.469f, 1292.650f, 1.9637f},
    {-173.463f, 1212.119f, 0.1743f},
    {-127.524f, 1167.949f, 0.7608f}
};

const float ReinforcementPositions[4][3] = 
{
    {-178.348f, 1350.270f, -0.107f},
    {-177.929f, 1274.980f, 1.5715f},
    {-166.024f, 1191.630f, 0.9356f},
    {-112.116f, 1159.570f, 0.0933f}
};

/*######
## npc_forest_frog
######*/

#define SPELL_REMOVE_AMANI_CURSE    43732
#define SPELL_PUSH_MOJO             43923
#define ENTRY_FOREST_FROG           24396

class npc_forest_frog : public CreatureScript
{
    public:

        npc_forest_frog() : CreatureScript("npc_forest_frog") { }

        struct npc_forest_frogAI : public ScriptedAI
        {
            npc_forest_frogAI(Creature* c) : ScriptedAI(c)
            {
                pInstance = c->GetInstanceScript();
            }

            InstanceScript *pInstance;

            void Reset() {}

            void EnterCombat(Unit* /*who*/) {}

            void DoSpawnRandom()
            {
                if (pInstance)
                {
                    uint32 cEntry = 0;
                    switch(rand()%10)
                    {
                        case 0: cEntry = 24397; break;          //Mannuth
                        case 1: cEntry = 24403; break;          //Deez
                        case 2: cEntry = 24404; break;          //Galathryn
                        case 3: cEntry = 24405; break;          //Adarrah
                        case 4: cEntry = 24406; break;          //Fudgerick
                        case 5: cEntry = 24407; break;          //Darwen
                        case 6: cEntry = 24445; break;          //Mitzi
                        case 7: cEntry = 24448; break;          //Christian
                        case 8: cEntry = 24453; break;          //Brennan
                        case 9: cEntry = 24455; break;          //Hollee
                    }

                    if (!pInstance->GetData(TYPE_RAND_VENDOR_1))
                        if (rand()%10 == 1) cEntry = 24408;      //Gunter
                    if (!pInstance->GetData(TYPE_RAND_VENDOR_2))
                        if (rand()%10 == 1) cEntry = 24409;      //Kyren

                    if (cEntry) me->UpdateEntry(cEntry);

                    if (cEntry == 24408) pInstance->SetData(TYPE_RAND_VENDOR_1, DONE);
                    if (cEntry == 24409) pInstance->SetData(TYPE_RAND_VENDOR_2, DONE);
                }
            }

            void SpellHit(Unit *caster, const SpellEntry *spell)
            {
                if (spell->Id == SPELL_REMOVE_AMANI_CURSE && caster->GetTypeId() == TYPEID_PLAYER && me->GetEntry() == ENTRY_FOREST_FROG)
                {
                    //increase or decrease chance of mojo?
                    if (rand()%99 == 50) DoCast(caster, SPELL_PUSH_MOJO, true);
                    else DoSpawnRandom();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_forest_frogAI(creature);
        }
};

/*######
## npc_zulaman_hostage
######*/

#define GOSSIP_HOSTAGE1        "I am glad to help you."

static uint32 HostageEntry[] = {23790, 23999, 24024, 24001};
static uint32 ChestEntry[] = {186648, 187021, 186672, 186667};

class npc_zulaman_hostage : public CreatureScript
{
    public:

        npc_zulaman_hostage()
            : CreatureScript("npc_zulaman_hostage")
        {
        }

        struct npc_zulaman_hostageAI : public ScriptedAI
        {
            npc_zulaman_hostageAI(Creature *c) : ScriptedAI(c) {IsLoot = false;}
            bool IsLoot;
            uint64 PlayerGUID;
            void Reset() {}
            void EnterCombat(Unit* /*who*/) {}
            void JustDied(Unit* /*who*/)
            {
                Player* pPlayer = Unit::GetPlayer(*me, PlayerGUID);
                if (pPlayer) pPlayer->SendLoot(me->GetGUID(), LOOT_CORPSE);
            }
            void UpdateAI(const uint32 /*diff*/)
            {
                if (IsLoot)
                    DoCast(me, 7, false);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_zulaman_hostageAI(creature);
        }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HOSTAGE1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
        {
            pPlayer->PlayerTalkClass->ClearMenus();
            if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
                pPlayer->CLOSE_GOSSIP_MENU();

            if (!pCreature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
                return true;
            pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            InstanceScript* pInstance = pCreature->GetInstanceScript();
            if (pInstance)
            {
                //uint8 progress = pInstance->GetData(DATA_CHESTLOOTED);
                pInstance->SetData(DATA_CHESTLOOTED, 0);
                float x, y, z;
                pCreature->GetPosition(x, y, z);
                uint32 entry = pCreature->GetEntry();
                for (uint8 i = 0; i < 4; ++i)
                {
                    if (HostageEntry[i] == entry)
                    {
                        pCreature->SummonGameObject(ChestEntry[i], x-2, y, z, 0, 0, 0, 0, 0, 0);
                        break;
                    }
                }
            }
            return true;
        }
};

/*######
## npc_harrison_jones
######*/

#define GOSSIP_JONES "Oeffne die Tore nach Zul'Aman [PH]"

class npc_zulaman_harrison_jones : public CreatureScript
{
public:

    npc_zulaman_harrison_jones() : CreatureScript("npc_zulaman_harrison_jones") {}

    bool OnGossipHello (Player* pPlayer, Creature* pCreature)
    {
        InstanceScript* pInstance = pCreature->GetInstanceScript();
        if(pInstance)
        {
            if(pInstance->GetData(DATA_TIMERSTART) == 0)
            {
                pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_JONES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
            }
        }
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
    {
        if(uiAction == GOSSIP_ACTION_INFO_DEF + 1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        
            InstanceScript* pInstance = pCreature->GetInstanceScript();
            if(pInstance)
            {
                if(pCreature->GetMap()->IsDungeon())   
                    ((InstanceMap*)pCreature->GetMap())->PermBindAllPlayers(pPlayer);
                pInstance->SetData(DATA_TIMERSTART,IN_PROGRESS);
            }
        }
        return true;
    }
};
/*#################################
## Zul'Aman Trashmobs
#################################*/

#define SPELL_INVISIBLE_DETECTION               41634

struct mob_zulaman_trashAI : public ScriptedAI
{
    mob_zulaman_trashAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceScript();
    }

    InstanceScript *pInstance;

    uint32 AreaInCombat_Timer;
    bool CanDetectVisibility;

    void Reset()
    {
        AreaInCombat_Timer = 5000;

        SetVisibilityDetection(CanDetectVisibility);
    }

    void SetVisibilityDetection(bool canDetect)
    {
        if(canDetect)
        {
            me->CastSpell(me,SPELL_INVISIBLE_DETECTION,true);
        }
    }

    void SendAttacker(Unit* target) // Exploit Fix
    {
        std::list<Creature*> templist;
        float x, y, z;
        me->GetPosition(x, y, z);

        {
            CellPair pair(Trinity::ComputeCellPair(x, y));
            Cell cell(pair);
            cell.data.Part.reserved = ALL_DISTRICT;
            cell.SetNoCreate();

            Trinity::AllFriendlyCreaturesInGrid check(me);
            Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid> searcher(me, templist, check);

            TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid>, GridTypeMapContainer> cSearcher(searcher);

            cell.Visit(pair, cSearcher, *(me->GetMap()));
        }

        if(!templist.size())
            return;

        for(std::list<Creature*>::iterator i = templist.begin(); i != templist.end(); ++i)
        {
            if((*i) && me->IsWithinDistInMap((*i),10))
            {
                if(!(*i)->isInCombat() && !me->getVictim())
                    (*i)->AI()->AttackStart(target);
            }
        }
    }

    //void DoAttackerAreaInCombat(Unit* attacker, float range, Unit* pUnit = NULL)
    //{
    //    if(!attacker)
    //        attacker = me;

    //    if (!pUnit)
    //        pUnit = me;

    //    Map *map = pUnit->GetMap();

    //    if (!map->IsDungeon())
    //        return;

    //    if (!pUnit->CanHaveThreatList() || pUnit->getThreatManager().isThreatListEmpty())
    //        return;

    //    Map::PlayerList const &PlayerList = map->GetPlayers();
    //    for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
    //    {
    //        if (Player* i_pl = i->getSource())
    //            if (i_pl->isAlive() && attacker && attacker->GetDistance(i_pl) <= range )
    //            {
    //                pUnit->SetInCombatWith(i_pl);
    //                i_pl->SetInCombatWith(pUnit);
    //                pUnit->AddThreat(i_pl, 0.0f);
    //            }
    //    }
    //}

    void CheckBugusing()
    {
        if(pInstance)
            if(pInstance->GetData(DATA_TIMERSTART) != 1)
            {
                pInstance->SetData(DATA_TIMERDELETE,1);
            }
    }

    void EnterCombat(Unit *who)
    {
        DoAttackerAreaInCombat(who, 100);
        Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
        if(ptarget)
            SendAttacker(ptarget);

        CheckBugusing();
    }
    void KilledUnit(Unit *victim){}
    void JustDied(Unit *victim){}

    Creature* FindNearestCreature(uint32 entry, float range)
    {
        Creature *creature = NULL;
        Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck checker(*me, entry, true, range);
        Trinity::CreatureLastSearcher<Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck> searcher(me, creature, checker);
        me->VisitNearbyObject(range, searcher);
        return creature;
    }

    void DoAggroPuls(const uint32 diff)
    {
        if(AreaInCombat_Timer <= diff)
        {
            DoAttackerAreaInCombat(me->getVictim(), 100);
            AreaInCombat_Timer = 5000;
        }else AreaInCombat_Timer -= diff;
    }

    bool TryDoCast(Unit *victim, uint32 spellId, bool triggered = false)
    {
        if(me->IsNonMeleeSpellCasted(false)) return false;

        DoCast(victim,spellId,triggered);
        return true;
    }

    bool TryDoCastAOE(uint32 spellId, bool triggered = false)
    {
        if(me->IsNonMeleeSpellCasted(false)) return false;

        DoCastAOE(spellId,triggered);
        return true;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim() )
            return;

        DoAggroPuls(diff);

        DoMeleeAttackIfReady();
    }
};
/* Basis End */

/*#################################
## Akilzon Trashmobs
#################################*/

#define SPELL_AG_REND                           43246
#define SPELL_AG_STARTLING_ROAR                 43249

class mob_amanishi_guardian : public CreatureScript
{
public:

    mob_amanishi_guardian() : CreatureScript("mob_amanishi_guardian") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_amanishi_guardianAI(creature);
    }

    struct mob_amanishi_guardianAI : public mob_zulaman_trashAI
    {
        mob_amanishi_guardianAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = true;
        }

        uint32 Rend_Timer;
        uint32 StartlingRoar_Timer;

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Rend_Timer = urand(10000,15000);
            StartlingRoar_Timer = urand(15000,20000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Rend_Timer <= diff)
            {
                DoCast(me->getVictim(),SPELL_AG_REND);
                Rend_Timer = urand(10000,15000);
            }else Rend_Timer -= diff;

            if(StartlingRoar_Timer <= diff)
            {
                if(TryDoCastAOE(SPELL_AG_STARTLING_ROAR))
                    StartlingRoar_Timer = urand(10000,20000);
            }else StartlingRoar_Timer -= diff;

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

#define SPELL_AWW_CHAIN_HEAL                    43527
#define SPELL_AWW_FROST_SHOCK                   43524
#define SPELL_AWW_LIGHTNING_BOLT                43526

class mob_amanishi_wind_walker : public CreatureScript
{
public:

    mob_amanishi_wind_walker() : CreatureScript("mob_amanishi_wind_walker") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_amanishi_wind_walkerAI(creature);
    }

    struct mob_amanishi_wind_walkerAI : public mob_zulaman_trashAI
    {
        mob_amanishi_wind_walkerAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = true;
        }
        uint32 ChainHeal_Timer;
        uint32 FrostShock_Timer;
        uint32 LightningBolt_Timer;

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            ChainHeal_Timer = urand(15000,20000);
            FrostShock_Timer = urand(5000,10000);
            LightningBolt_Timer = urand(5000,10000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(ChainHeal_Timer <= diff)
            {
                Unit *target = DoSelectLowestHpFriendly(40);
                if(!target) target = me;

                if(TryDoCast(target,SPELL_AWW_CHAIN_HEAL))
                    ChainHeal_Timer = urand(15000,20000);
            }else ChainHeal_Timer -= diff;

            if(FrostShock_Timer <= diff)
            {
                Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,20,true);
                if(!target) target = me->getVictim();

                if(TryDoCast(target, SPELL_AWW_FROST_SHOCK))
                    FrostShock_Timer = urand(5000,10000);
            }else FrostShock_Timer -= diff;

            if(LightningBolt_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_AWW_LIGHTNING_BOLT))
                    LightningBolt_Timer = urand(5000,10000);
            }else LightningBolt_Timer -= diff;

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

#define SPELL_AP_CLEAVE                     15496
#define SPELL_AP_MORTAL_STRIKE              43529
#define SPELL_AP_PIERCING_HOWL              43530

class mob_amanishi_protector : public CreatureScript
{
public:

    mob_amanishi_protector() : CreatureScript("mob_amanishi_protector") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_amanishi_protectorAI(creature);
    }

    struct mob_amanishi_protectorAI : public mob_zulaman_trashAI
    {
        mob_amanishi_protectorAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = false;
        }

        uint32 Cleave_Timer;
        uint32 MortalStrike_Timer;
        uint32 PiercingHowl_Timer;

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Cleave_Timer = 5000;
            MortalStrike_Timer = urand(5000,10000);
            PiercingHowl_Timer = urand(15000,20000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Cleave_Timer <= diff)
            {
                DoCast(me->getVictim(),SPELL_AP_CLEAVE);
                Cleave_Timer = 5000;
            }else Cleave_Timer -= diff;

            if(MortalStrike_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_AP_MORTAL_STRIKE);
                MortalStrike_Timer = urand(5000,10000);
            }else MortalStrike_Timer -= diff;

            if(PiercingHowl_Timer <= diff)
            {
                if(TryDoCastAOE(SPELL_AP_PIERCING_HOWL))
                    PiercingHowl_Timer = urand(10000,20000);
            }else PiercingHowl_Timer -= diff;

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

#define SPELL_AMM_CHAIN_HEAL                    42477
#define SPELL_AMM_LIGHTNING_BOLT                45075
#define SPELL_AMM_HEALING_WARD                  42376
#define SPELL_AMM_PROTECTIVE_WARD               42478

class mob_amanishi_medicine_man : public CreatureScript
{
public:

    mob_amanishi_medicine_man() : CreatureScript("mob_amanishi_medicine_man") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_amanishi_medicine_manAI(creature);
    }

    struct mob_amanishi_medicine_manAI : public mob_zulaman_trashAI
    {
        mob_amanishi_medicine_manAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = false;
        }

        uint32 Totem_Timer;
        uint32 ChainHeal_Timer;
        uint32 LightningBolt_Timer;

        uint32 totem_count;

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Totem_Timer = 5000;
            ChainHeal_Timer = urand(5000,10000);
            LightningBolt_Timer = urand(15000,20000);

            totem_count = 0;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Totem_Timer <= diff)
            {
                if(TryDoCastAOE(totem_count == 0 ? SPELL_AMM_PROTECTIVE_WARD : SPELL_AMM_HEALING_WARD))
                {
                    Totem_Timer = 15000;
                    totem_count = totem_count == 0 ? 1 : 0;
                }
            }else Totem_Timer -= diff;

            if(ChainHeal_Timer <= diff)
            {
                Unit *target = DoSelectLowestHpFriendly(40);
                if(!target) target = me;

                if(TryDoCast(target,SPELL_AMM_CHAIN_HEAL))
                    ChainHeal_Timer = urand(15000,20000);
            }else ChainHeal_Timer -= diff;

            if(LightningBolt_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_AMM_LIGHTNING_BOLT))
                    LightningBolt_Timer = urand(5000,10000);
            }else LightningBolt_Timer -= diff;

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

#define SPELL_AMANI_PROTECTIVE_WARD_PASSIVE_1 42479
#define SPELL_AMANI_PROTECTIVE_WARD_PASSIVE_2 42481

class mob_amani_protective_ward : public CreatureScript
{
public:

    mob_amani_protective_ward() : CreatureScript("mob_amani_protective_ward") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_amani_protective_wardAI(creature);
    }

    struct mob_amani_protective_wardAI : public NullCreatureAI
    {
        mob_amani_protective_wardAI(Creature *c) : NullCreatureAI(c) {Reset();}
        void Reset()
        {
            DoCast(me,SPELL_AMANI_PROTECTIVE_WARD_PASSIVE_2); 
        }
        void UpdateAI(const uint32 diff)
        {
            me->RemoveAurasDueToSpell(SPELL_AMANI_PROTECTIVE_WARD_PASSIVE_1);
        }
    };
};

/*#################################
## Akilzon Gaundlet
###################################
    // Point 1 -- Scout
    208.711 1475.133 25.915231
###################################
###############
#Involved Adds:
###############
    Amani'shi Warrior - 24225   // spawns from start
    Amani'shi Lookout - 24175   // start gauntlet
    Amani'shi Tempest - 24549   // end gauntlet
    Amani Eagle       - 24159   // spawns from end
###################################
#SQL:
#####
    update creature_template set scriptname = 'mob_amanishi_lookout' where entry = 24175;
    update creature_template set scriptname = 'mob_amanishi_warrior' where entry = 24225
    update creature_template set scriptname = 'mob_amanishi_tempest' where entry = 24549
    update creature_template set scriptname = 'mob_amani_eagle'      where entry = 24159
#################################*/

/*######
## Amani'shi Lookout
######*/

#define YELL_START              "Akil'zon, the invaders approach!"

class mob_amanishi_lookout : public CreatureScript
{
public:
    mob_amanishi_lookout() : CreatureScript("mob_amanishi_lookout") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amanishi_lookoutAI (pCreature);
    }

    struct mob_amanishi_lookoutAI : public ScriptedAI
    {
        mob_amanishi_lookoutAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            Reset();
        }

        InstanceScript *pInstance;
        uint32 MoveWait_Timer;
        uint32 NextWaypoint;
        bool GauntletStarted;

    
        void AttackStart(Unit* who)
        {
            if(!who || who == me)
                return;

            if(!me->isAlive() || !who->isAlive())
                return;
        
            if(who->GetTypeId()==TYPEID_PLAYER )
            {
                if(((Player*)who)->isGameMaster())
                    return;

                 EnterCombat(who);
            }
        }

        void MoveInLineOfSight(Unit *who)
        {
            if(me->getVictim() || !me->IsHostileTo(who) || !who->isInAccessiblePlaceFor(me))
                return;

            if(!me->canFly() && me->GetDistanceZ(who) > 20)
                return;

            if(!me->IsWithinDistInMap(who, me->GetAttackDistance(who)) || !me->IsWithinLOSInMap(who))
                return;

            //if(me->canAttack(who))
            EnterCombat(who);
        }

        void Reset()
        {
            if(pInstance)
            {
                GauntletStarted = pInstance->GetData(DATA_AKILZONEVENT) == DONE;
                pInstance->SetData(DATA_GAUNTLET,NOT_STARTED);
            }

            me->SetSpeed(MOVE_RUN,2);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);

            MoveWait_Timer = 0;

            me->CastSpell(me,SPELL_INVISIBLE_DETECTION,true);
        }
        void EnterCombat(Unit *who)
        {
            if(GauntletStarted)
                return;

            me->MonsterYell(YELL_START,LANG_UNIVERSAL, NULL);
            if(pInstance)
                pInstance->SetData(DATA_GAUNTLET,IN_PROGRESS);

            NextWaypoint = 0;
            MoveWait_Timer = 2000;
            GauntletStarted = true;
        }
        void MovementInform(uint32 type, uint32 id)
        {
            if(id < 0)
                return;

            if(type != POINT_MOTION_TYPE)
                return;

            if(!GauntletStarted)
                return;

            if( id < 7)
            {
                MoveWait_Timer = 1;
                NextWaypoint++;
            }
            else
            {
                me->SetVisible(false);
                //me->DealDamage(me,me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                //me->RemoveCorpse();
            }
        }
        void UpdateAI(const uint32 diff)
        {
            if(!GauntletStarted)
                return;

            if(pInstance)
                if(pInstance->GetData(DATA_GAUNTLET) == DONE)
                {
                    me->DealDamage(me,me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                    me->RemoveCorpse();
                }

            if(MoveWait_Timer)
                if(MoveWait_Timer < diff)
                {
                    (*me).GetMotionMaster()->MovePoint(NextWaypoint,GauntletWaypoints[NextWaypoint][0],GauntletWaypoints[NextWaypoint][1],GauntletWaypoints[NextWaypoint][2]);
                    MoveWait_Timer = 0;
                }else MoveWait_Timer -= diff;
        }
    };
};

/*######
## Amani'shi Warrior
######*/

#define SPELL_ANANISHI_WARRIOR_KICK                 43518
#define SPELL_ANANISHI_WARRIOR_CHARGE               43519

class mob_amanishi_warrior : public CreatureScript
{
public:
    mob_amanishi_warrior() : CreatureScript("mob_amanishi_warrior") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amanishi_warriorAI (pCreature);
    }

    struct mob_amanishi_warriorAI : public ScriptedAI
    {
        mob_amanishi_warriorAI(Creature *c) : ScriptedAI(c)
        {
            NextWaypoint = 0;
            Reset();
        }

        uint32 MoveWait_Timer;
        uint32 NextWaypoint;

        uint32 Charge_Timer;
        uint32 Kick_Timer;

        void Reset()
        {
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
            MoveWait_Timer = 1;

            Charge_Timer = 1;
            Kick_Timer = 10000;
        }
        void EnterCombat(Unit *who){}
        void MovementInform(uint32 type, uint32 id)
        {
            if(id < 0)
                return;

            if(type != POINT_MOTION_TYPE)
                return;

            if( id < 7)
            {
                MoveWait_Timer = 1;
                NextWaypoint++;
            }
        }
        void UpdateAI(const uint32 diff)
        {
            if(!UpdateVictim())
            {
                if(MoveWait_Timer)
                    if(MoveWait_Timer < diff)
                    {
                        (*me).GetMotionMaster()->MovePoint(NextWaypoint,GauntletWaypoints[NextWaypoint][0],GauntletWaypoints[NextWaypoint][1],GauntletWaypoints[NextWaypoint][2]);
                        MoveWait_Timer = 0;
                    }else MoveWait_Timer -= diff;
                return;
            }
            else
            {
                if(Charge_Timer < diff)
                {
                    DoCast(me->getVictim(),SPELL_ANANISHI_WARRIOR_CHARGE);
                    Charge_Timer = 20000;
                }else Charge_Timer -= diff;

                if(Kick_Timer < diff)
                {
                    DoCast(me->getVictim(),SPELL_ANANISHI_WARRIOR_KICK);
                    Charge_Timer = 20000;
                }else Charge_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        }
    };
};

/*######
## Amani Eagle
######*/

#define SPELL_ANANI_EAGLE_TALON             43517

class mob_amani_eagle : public CreatureScript
{
public:
    mob_amani_eagle() : CreatureScript("mob_amani_eagle") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amani_eagleAI (pCreature);
    }

    struct mob_amani_eagleAI : public ScriptedAI
    {
        mob_amani_eagleAI(Creature *c) : ScriptedAI(c)
        {
            NextWaypoint = 5;
            Reset();
        }

        uint32 MoveWait_Timer;
        uint32 NextWaypoint;

        uint32 Talon_Timer;

        void Reset()
        {
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
            MoveWait_Timer = 1;
            Talon_Timer = 10000;
        }
        void EnterCombat(Unit *who){}
        void MovementInform(uint32 type, uint32 id)
        {
            if(id < 0)
                return;

            if(type != POINT_MOTION_TYPE)
                return;

            if( id > 0)
            {
                MoveWait_Timer = 1;
                NextWaypoint--;
            }
        }
        void UpdateAI(const uint32 diff)
        {
        
            if(!UpdateVictim())
            {
                if(MoveWait_Timer)
                    if(MoveWait_Timer < diff)
                    {
                        (*me).GetMotionMaster()->MovePoint(NextWaypoint,GauntletWaypoints[NextWaypoint][0],GauntletWaypoints[NextWaypoint][1],GauntletWaypoints[NextWaypoint][2]);
                        MoveWait_Timer = 0;
                    }else MoveWait_Timer -= diff;
                return;
            }
            else
            {
                if(Talon_Timer < diff)
                {
                    DoCast(me->getVictim(),SPELL_ANANI_EAGLE_TALON);
                    Talon_Timer = 20000;
                }else Talon_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        }
    };
};

/*######
## Amani'shi Tempest
######*/

#define SPELL_AMANISHI_TEMPEST_THUNDERCLAP              44033
#define MOB_AMANISHI_WARRIOR                            24225
#define MOB_AMANI_EAGLE                                 24159

class mob_amanishi_tempest : public CreatureScript
{
public:
    mob_amanishi_tempest() : CreatureScript("mob_amanishi_tempest") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amanishi_tempestAI (pCreature);
    }

    struct mob_amanishi_tempestAI : public ScriptedAI
    {
        mob_amanishi_tempestAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            Reset();
        }

        InstanceScript *pInstance;
        uint32 Thunderclap_Timer;

        uint32 phase;
        uint32 EagleSpawn_Timer;
        uint32 EagleCounter;
        uint32 WarriorSpawn_Timer;
        uint32 WarriorCounter;

        void Reset()
        {
            EagleCounter = 5;
            WarriorCounter = 2;
            EagleSpawn_Timer = 30000;
            WarriorSpawn_Timer = 30000;
            Thunderclap_Timer = 10000;
        }
        void EnterCombat(Unit *who)
        {
            if(pInstance)
                pInstance->SetData(DATA_GAUNTLET,DONE);
        }
   
        void UpdateAI(const uint32 diff)
        {
            if(pInstance && pInstance->GetData(DATA_GAUNTLET) == IN_PROGRESS)
            {
                if(me->isDead())
                {
                    pInstance->SetData(DATA_GAUNTLET,DONE);
                }
            
                if(WarriorSpawn_Timer < diff)
                {
                    if(WarriorCounter > 0)
                    {
                        me->SummonCreature(MOB_AMANISHI_WARRIOR,WarriorSpawnPos[0],WarriorSpawnPos[1],WarriorSpawnPos[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,60000);
                        WarriorSpawn_Timer = 500;
                        WarriorCounter--;
                    }
                    else
                    {
                        WarriorCounter = 2;
                        WarriorSpawn_Timer = 59000;
                    }
                }else WarriorSpawn_Timer -= diff;

                if(EagleSpawn_Timer < diff)
                {
                    if(EagleCounter > 0)
                    {
                        me->SummonCreature(MOB_AMANI_EAGLE,EagleSpawnPos[0],EagleSpawnPos[1],EagleSpawnPos[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,60000);
                        EagleSpawn_Timer = 500;
                        EagleCounter--;
                    }
                    else
                    {
                        EagleCounter = 5;
                        EagleSpawn_Timer = 27500;
                    }
                }else EagleSpawn_Timer -= diff;
            }

            if(!UpdateVictim())
                return;
      
            if(Thunderclap_Timer < diff)
            {
                DoCast(me->getVictim(),SPELL_AMANISHI_TEMPEST_THUNDERCLAP);
                Thunderclap_Timer = 20000;
            }else Thunderclap_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

/*#################################
## Nalorakk Trashmobs
#################################*/

#define SPELL_ATM_KICK                  36033
#define SPELL_ATM_CYCLONE_STRIKE        42495

class mob_amanishi_tribesman : public CreatureScript
{
public:
    mob_amanishi_tribesman() : CreatureScript("mob_amanishi_tribesman") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amanishi_tribesmanAI (pCreature);
    }

    struct mob_amanishi_tribesmanAI : public mob_zulaman_trashAI
    {
        mob_amanishi_tribesmanAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = false;
        }

        uint32 Kick_Timer;
        uint32 Strike_Timer;

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Kick_Timer = urand(5000,10000);
            Strike_Timer = urand(5000,10000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Kick_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_ATM_KICK))
                    Kick_Timer = urand(5000,10000);
            }else Kick_Timer -= diff;

            if(Strike_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_ATM_CYCLONE_STRIKE))
                    Strike_Timer = urand(5000,10000);
            }else Strike_Timer -= diff;

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

#define SPELL_AWB_CLEAVE                43273
#define SPELL_AWB_DISMOUNT              43274
#define SPELL_AWB_FRENZY                40743
#define SPELL_AWB_FURIOUS_ROAR          42496

class mob_amanishi_warbringer : public CreatureScript
{
public:
    mob_amanishi_warbringer() : CreatureScript("mob_amanishi_warbringer") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amanishi_warbringerAI (pCreature);
    }

    struct mob_amanishi_warbringerAI : public mob_zulaman_trashAI
    {
        mob_amanishi_warbringerAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = false;
            mounted = true;
            me->Mount(22467);
        }

        uint32 Cleave_Timer;
        uint32 Roar_Timer;

        bool mounted;

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Cleave_Timer = urand(5000,10000);
            Roar_Timer = urand(15000,20000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Cleave_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_AWB_CLEAVE))
                    Cleave_Timer = urand(5000,10000);
            }else Cleave_Timer -= diff;

            if(Roar_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_AWB_FURIOUS_ROAR))
                    Roar_Timer = urand(15000,20000);
            }else Roar_Timer -= diff;

            if(mounted)
            {
                if((me->GetHealth() * 100 / me->GetMaxHealth()) <= 25)
                {
                    mounted = false;
                    me->InterruptNonMeleeSpells(false);
                    me->CastSpell(me,SPELL_AWB_DISMOUNT,false);
                    me->Unmount();
                }
            }

            if(!me->HasAuraEffect(SPELL_AWB_FRENZY,0))
            {
                if((me->GetHealth() * 100 / me->GetMaxHealth()) <= 10)
                {
                    me->InterruptNonMeleeSpells(false);
                    me->CastSpell(me,SPELL_AWB_FRENZY,false);
                }
            }

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

#define SPELL_AAT_AXE_VOLLEY                42359
#define SPELL_AAT_KNOCKDOWN                 35011
#define SPELL_AAT_RAPTOR_STRIKE             31566

class mob_amanishi_axe_thrower : public CreatureScript
{
public:
    mob_amanishi_axe_thrower() : CreatureScript("mob_amanishi_axe_thrower") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amanishi_axe_throwerAI (pCreature);
    }

    struct mob_amanishi_axe_throwerAI : public mob_zulaman_trashAI
    {
        mob_amanishi_axe_throwerAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = false;
        }

        uint32 Volley_Timer;
        uint32 Knockdown_Timer;
        uint32 Strike_Timer;

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Knockdown_Timer = urand(10000,15000);
            Strike_Timer = urand(5000,10000);
            Volley_Timer = urand(15000,20000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Volley_Timer <= diff)
            {
                if(TryDoCastAOE(SPELL_AAT_AXE_VOLLEY))
                    Volley_Timer = urand(45000,60000);
            }else Volley_Timer -= diff;

            if(Strike_Timer <= diff)
            {
                me->CastSpell(me->getVictim(),SPELL_AAT_RAPTOR_STRIKE,false);
                Strike_Timer = urand(5000,10000);
            }else Strike_Timer -= diff;

            if(Knockdown_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_AAT_KNOCKDOWN))
                    Knockdown_Timer = urand(15000,20000);
            }else Knockdown_Timer -= diff;



            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

#define SPELL_AB_CRUNCH_ARMOR               42747
#define SPELL_AB_ENRAGE                     42745

class mob_amani_bear : public CreatureScript
{
public:
    mob_amani_bear() : CreatureScript("mob_amani_bear") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amani_bearAI (pCreature);
    }

    struct mob_amani_bearAI : public mob_zulaman_trashAI
    {
        mob_amani_bearAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = false;
        }

        uint32 Crunch_Timer;
        uint32 Enrage_Timer;
 

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Crunch_Timer = urand(5000,10000);
            Enrage_Timer = urand(20000,30000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Enrage_Timer <= diff)
            {
                if(TryDoCastAOE(SPELL_AB_ENRAGE))
                    Enrage_Timer = urand(20000,30000);
            }else Enrage_Timer -= diff;

            if(Crunch_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(),SPELL_AB_CRUNCH_ARMOR))
                    Crunch_Timer = urand(10000,20000);
            }else Crunch_Timer -= diff;

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

/*#################################
## Janalai Trashmobs
#################################*/

#define SPELL_ALERT_DRUMS                   42177
#define SPELL_MULTI_SHOT                    43205
#define SPELL_SHOOT                         16496
#define MOB_AMANISHI_REINFORCEMENTS         23587

class mob_amanishi_scout : public CreatureScript
{
public:
    mob_amanishi_scout() : CreatureScript("mob_amanishi_scout") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amanishi_scoutAI (pCreature);
    }

    struct mob_amanishi_scoutAI : public ScriptedAI
    {
        mob_amanishi_scoutAI(Creature *c) : ScriptedAI(c)
        {
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
            ReinforcementPhase = 0;
            Reset();
        }

        uint32 shoot_timer;
        uint32 multi_shoot_timer;
        uint32 wait_timer;
        uint32 summon_timer;
        uint32 summons;
        uint32 ReinforcementPhase; // 0 - never moved, 1 - moving,2 - reinformcment called
        uint64 trigger_guid;
        uint32 point;

        void Reset()
        {
            ReinforcementPhase = 0;
            trigger_guid = 0;

            shoot_timer = 1000;
            multi_shoot_timer = 15000;
            wait_timer = 0;
            point = 0;
        }

        uint32 GetNextDrumPos()
        {
            uint32 next;
            float distance = 99999999.9f;

            for(int i = 0; i < 4; i++)
            {
                float t_distance = me->GetDistance(DrumPositions[i][0],DrumPositions[i][1],DrumPositions[i][2]);
                if(distance > t_distance)
                {
                    next = (uint32)i;
                    distance = t_distance;
                }
            }
            return next;
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if(type != POINT_MOTION_TYPE)
                return;

            if(id == 1 && ReinforcementPhase == 1)
            {
                wait_timer = 5000;
                summons = 2;
                summon_timer = 500;
                (*me).GetMotionMaster()->MoveIdle();
                ReinforcementPhase = 2;
            }
        }
       
        void AttackStart(Unit* who)
        {
            if(ReinforcementPhase == 0)
            {
                if(!who || who == me)
                return;

                if(!me->isAlive() || !who->isAlive())
                    return;
            
                if(who->GetTypeId()==TYPEID_PLAYER )
                {
                    if(((Player*)who)->isGameMaster())
                        return;

                     CallReinforcements(who);
                }
            }
            else if(ReinforcementPhase == 3)
            {
                ScriptedAI::AttackStart(who);
            }
        }

        void MoveInLineOfSight(Unit *who)
        {
            if(ReinforcementPhase == 0)
            {
                if(me->getVictim() || !me->IsHostileTo(who) || !who->isInAccessiblePlaceFor(me))
                    return;

                if(!me->canFly() && me->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                    return;

                if(!me->IsWithinDistInMap(who, me->GetAttackDistance(who)) || !me->IsWithinLOSInMap(who))
                    return;
        
                if(me->canAttack(who))
                    CallReinforcements(who);
            }
            else if(ReinforcementPhase == 3)
            {
                ScriptedAI::MoveInLineOfSight(who);
            }
        }

        void CallReinforcements(Unit *who)
        {
            trigger_guid = who->GetGUID();
            me->MonsterYell("Invaders! Sound the Alarm!",LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(me,12104);
            ReinforcementPhase = 1;
            point = GetNextDrumPos();
            (*me).GetMotionMaster()->Clear();
            (*me).GetMotionMaster()->MovePoint(1,DrumPositions[point][0],DrumPositions[point][1],DrumPositions[point][2]);
        }

        void EnterCombat(Unit *who){}
        void UpdateAI(const uint32 diff)
        {
            if(ReinforcementPhase == 2)
            {
                if(summons > 0)
                {
                    if(summon_timer < diff)
                    {
                        Unit* target = Unit::GetUnit((*me),trigger_guid);
                        if(target)
                        {
                            Creature* summon = me->SummonCreature(MOB_AMANISHI_REINFORCEMENTS,ReinforcementPositions[point][0],ReinforcementPositions[point][1],ReinforcementPositions[point][2], 0, TEMPSUMMON_DEAD_DESPAWN,60000);
                            summon->SetNoCallAssistance(true);
                            summon->AI()->AttackStart(target);
                        }
                        DoCast(me,SPELL_ALERT_DRUMS);
                        summons--;
                        summon_timer = 500;
                    }else summon_timer -= diff;
                }

                if(wait_timer > 0)
                    if(wait_timer < diff)
                    {
                        me->InterruptNonMeleeSpells(false);
                        ReinforcementPhase = 3;
                        (*me).GetMotionMaster()->Clear();

                        Unit* target = Unit::GetUnit((*me),trigger_guid);
                        if(target)
                        {
                            AttackStart(target);
                        }

                        wait_timer = 0;
                    }else wait_timer -= diff;
            }

            if (!UpdateVictim())
                return;

            if(multi_shoot_timer < diff)
            {
                DoCast(me->getVictim(),SPELL_MULTI_SHOT);
                multi_shoot_timer = 15000;
            }else multi_shoot_timer -= diff;

            if((*me).GetMotionMaster()->GetCurrentMovementGeneratorType() == TARGETED_MOTION_TYPE)
            {
                if(me->IsWithinDistInMap(me->getVictim(), 7))
                {
                    DoMeleeAttackIfReady();
                }
                else
                {
                    if(me->IsWithinDistInMap(me->getVictim(), 20))
                    {
                        (*me).GetMotionMaster()->Clear();
                        (*me).GetMotionMaster()->MoveIdle();
                    }
                }
            }
            else if((*me).GetMotionMaster()->GetCurrentMovementGeneratorType() == IDLE_MOTION_TYPE)
            {
                if(!me->IsWithinDistInMap(me->getVictim(), 5) && me->IsWithinDistInMap(me->getVictim(), 20))
                {
                    if(shoot_timer < diff)
                    {
                        DoCast(SelectTarget(SELECT_TARGET_RANDOM,0),SPELL_SHOOT);
                        shoot_timer = 2000;
                    }else shoot_timer -= diff;
                }
                else
                {
                    (*me).GetMotionMaster()->Clear();
                    (*me).GetMotionMaster()->MoveChase(me->getVictim());
                }
            }
        }
    };
};

#define SPELL_AFC_CONFLAGRATION                 42220
#define SPELL_AFC_FIRE_BLAST                    43245
#define SPELL_AFC_FIREBALL_VOLLEY               43240
#define SPELL_AFC_HASTE                         43242

class mob_amanishi_flame_caster : public CreatureScript
{
public:
    mob_amanishi_flame_caster() : CreatureScript("mob_amanishi_flame_caster") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amanishi_flame_casterAI (pCreature);
    }

    struct mob_amanishi_flame_casterAI : public mob_zulaman_trashAI
    {
        mob_amanishi_flame_casterAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = true;
        }

        uint32 Conflagration_Timer;
        uint32 FireBlast_Timer;
        uint32 Volley_Timer;
        uint32 Haste_Timer;

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Conflagration_Timer = urand(10000,15000);
            FireBlast_Timer = urand(10000,15000);
            Volley_Timer = urand(15000,20000);
            Haste_Timer = urand(10000,15000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Haste_Timer <= diff)
            {
                if(TryDoCastAOE(SPELL_AFC_HASTE))
                    Haste_Timer = urand(20000,30000);
            }else Haste_Timer -= diff;

            if(Volley_Timer <= diff)
            {
                if(TryDoCastAOE(SPELL_AFC_FIREBALL_VOLLEY))
                    Volley_Timer = urand(15000,20000);
            }else Volley_Timer -= diff;

            if(FireBlast_Timer <= diff)
            {
                me->CastSpell(me->getVictim(),SPELL_AFC_FIRE_BLAST,false);
                FireBlast_Timer = urand(7000,10000);
            }else FireBlast_Timer -= diff;

            if(Conflagration_Timer <= diff)
            {

                Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,30,true);
                if(!target) target = me->getVictim();

                if(TryDoCast(target, SPELL_AFC_CONFLAGRATION))
                    Conflagration_Timer = urand(10000,15000);

            }else Conflagration_Timer -= diff;

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

#define SPELL_AT_INCITE_RAGE                43292
#define SPELL_AT_SLEEP                      20989
#define ENTRY_AMANI_DRAGONHAWK              23834

class mob_amanishi_trainer : public CreatureScript
{
public:
    mob_amanishi_trainer() : CreatureScript("mob_amanishi_trainer") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amanishi_trainerAI (pCreature);
    }

    struct mob_amanishi_trainerAI : public mob_zulaman_trashAI
    {
        mob_amanishi_trainerAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = true;
        }

        uint32 Rage_Timer;
        uint32 Sleep_Timer;

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Rage_Timer = urand(10000,15000);
            Sleep_Timer = urand(10000,15000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Rage_Timer <= diff)
            {

                Unit *target = me->FindNearestCreature(ENTRY_AMANI_DRAGONHAWK,100,true);
                if(!target) target = me;

                if(TryDoCast(target, SPELL_AT_INCITE_RAGE))
                    Rage_Timer = urand(10000,15000);

            }else Rage_Timer -= diff;

            if(Sleep_Timer <= diff)
            {

                Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,30,true);
                if(!target) target = me->getVictim();

                if(TryDoCast(target, SPELL_AT_SLEEP))
                    Sleep_Timer = urand(10000,15000);

            }else Sleep_Timer -= diff;

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

#define SPELL_ADH_FLAME_BREATH              43294

class mob_amani_dragonhawk : public CreatureScript
{
public:
    mob_amani_dragonhawk() : CreatureScript("mob_amani_dragonhawk") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amani_dragonhawkAI (pCreature);
    }

    struct mob_amani_dragonhawkAI : public mob_zulaman_trashAI
    {
        mob_amani_dragonhawkAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = false;
        }

        uint32 Breath_Timer;

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Breath_Timer = urand(10000,15000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Breath_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(), SPELL_ADH_FLAME_BREATH))
                    Breath_Timer = urand(15000,20000);
            }else Breath_Timer -= diff;

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

/*#################################
## Halazzi Trashmobs
#################################*/

#define SPELL_AMH_TRANQUILIZING_POISON                  43364
#define SPELL_AMH_ELECTRIFIED_NET                       43362

class mob_amanishi_handler : public CreatureScript
{
public:
    mob_amanishi_handler() : CreatureScript("mob_amanishi_handler") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amanishi_handlerAI (pCreature);
    }

    struct mob_amanishi_handlerAI : public mob_zulaman_trashAI
    {
        mob_amanishi_handlerAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = true;
        }

        uint32 Poison_Timer;
        uint32 Net_Timer;

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Poison_Timer = urand(10000,15000);
            Net_Timer = urand(10000,15000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Poison_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(), SPELL_AMH_TRANQUILIZING_POISON))
                    Poison_Timer = urand(10000,15000);
            }else Poison_Timer -= diff;

            if(Net_Timer <= diff)
            {

                Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,30,true);
                if(!target) target = me->getVictim();

                if(TryDoCast(target, SPELL_AMH_ELECTRIFIED_NET))
                    Net_Timer = urand(10000,15000);

            }else Net_Timer -= diff;

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

#define SPELL_ABT_CALL_OF_THE_BEAST                 43359
#define SPELL_ABT_DOMESTICATE                       43361
#define ENTRY_AMANI_LYNX                                24043

class mob_amanishi_beast_tamer : public CreatureScript
{
public:
    mob_amanishi_beast_tamer() : CreatureScript("mob_amanishi_beast_tamer") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amanishi_beast_tamerAI (pCreature);
    }

    struct mob_amanishi_beast_tamerAI : public mob_zulaman_trashAI
    {
        mob_amanishi_beast_tamerAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = true;
        }

        uint32 Domesticate_Timer;
        uint32 Call_Timer;

        void KillCharmedPlayer()
        {
            if(!me->GetMap()->IsDungeon())
                return;

            InstanceMap::PlayerList const &playerliste = ((InstanceMap*)me->GetMap())->GetPlayers();
            InstanceMap::PlayerList::const_iterator it;

            Map::PlayerList const &PlayerList = ((InstanceMap*)me->GetMap())->GetPlayers();
            for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            {
                Player* i_pl = i->getSource();
                if(i_pl && i_pl->isAlive() && i_pl->HasAuraEffect(SPELL_ABT_DOMESTICATE,0))
                    i_pl->DealDamage(i_pl,i_pl->GetHealth(),0,DIRECT_DAMAGE,SPELL_SCHOOL_MASK_NORMAL,0,false);
            }
        }

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Call_Timer = urand(20000,30000);
            Domesticate_Timer = urand(10000,30000);

            KillCharmedPlayer();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Call_Timer <= diff)
            {

                Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,30,true);
                if(!target) target = me->getVictim();

                if(TryDoCast(target, SPELL_ABT_CALL_OF_THE_BEAST))
                    Call_Timer = urand(20000,30000);

            }else Call_Timer -= diff;

            if(Domesticate_Timer <= diff)
            {

                Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,30,true);
                if(!target) target = me->getVictim();

                if(TryDoCast(target, SPELL_ABT_DOMESTICATE))
                    Domesticate_Timer = urand(15000,25000);

            }else Domesticate_Timer -= diff;

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

#define SPELL_AEL_FERAL_SWIPE               43357
#define SPELL_AEL_FRENZY                    34970
#define SPELL_AEL_POUNCE                    43356

class mob_amani_elder_lynx : public CreatureScript
{
public:
    mob_amani_elder_lynx() : CreatureScript("mob_amani_elder_lynx") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amani_elder_lynxAI (pCreature);
    }

    struct mob_amani_elder_lynxAI : public mob_zulaman_trashAI
    {
        mob_amani_elder_lynxAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = true;
        }

        uint32 Swipe_Timer;
        uint32 Frenzy_Timer;
        uint32 Pounce_Timer;

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Swipe_Timer = urand(10000,15000);
            Frenzy_Timer = urand(20000,30000);
            Pounce_Timer = urand(10000,15000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Swipe_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(), SPELL_AEL_FERAL_SWIPE))
                    Swipe_Timer = urand(5000,15000);
            }else Swipe_Timer -= diff;

            if(Frenzy_Timer <= diff)
            {
                if(TryDoCast(me, SPELL_AEL_FRENZY))
                    Frenzy_Timer = urand(20000,30000);
            }else Frenzy_Timer -= diff;

            if(Pounce_Timer <= diff)
            {
                Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,10,true);
                if(!target) target = me->getVictim();

                if(TryDoCast(target, SPELL_AEL_POUNCE))
                    Pounce_Timer = urand(15000,20000);
            }else Pounce_Timer -= diff;

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

#define SPELL_AL_STEALTH                        42866

class mob_amani_lynx : public CreatureScript
{
public:
    mob_amani_lynx() : CreatureScript("mob_amani_lynx") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amani_lynxAI (pCreature);
    }

    struct mob_amani_lynxAI : public mob_zulaman_trashAI
    {
        mob_amani_lynxAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = true;
        }

        uint32 Swipe_Timer;

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Swipe_Timer = urand(10000,15000);
            DoCast(me,SPELL_AL_STEALTH);
        }

        void EnterCombat(Unit *who)
        {
            me->RemoveAurasDueToSpell(SPELL_AL_STEALTH);
            mob_zulaman_trashAI::EnterCombat(who);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Swipe_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(), SPELL_AEL_FERAL_SWIPE))
                    Swipe_Timer = urand(5000,15000);
            }else Swipe_Timer -= diff;

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

#define SPELL_ALC_STEALTH                           42943
#define SPELL_ALC_DASH                              43317
#define SPELL_ALC_GUT_RIP                           43358

class mob_amani_lynx_cub : public CreatureScript
{
public:
    mob_amani_lynx_cub() : CreatureScript("mob_amani_lynx_cub") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amani_lynx_cubAI (pCreature);
    }

    struct mob_amani_lynx_cubAI : public mob_zulaman_trashAI
    {
        mob_amani_lynx_cubAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = false;
        }

        uint32 Rip_Timer;

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Rip_Timer = urand(10000,15000);
            DoCast(me,SPELL_ALC_STEALTH);
        }

        void EnterCombat(Unit *who)
        {
            me->RemoveAurasDueToSpell(SPELL_ALC_STEALTH);
            DoCast(me,SPELL_ALC_DASH);
            mob_zulaman_trashAI::EnterCombat(who);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Rip_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(), SPELL_ALC_GUT_RIP))
                    Rip_Timer = urand(5000,10000);
            }else Rip_Timer -= diff;

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

#define SPELL_ACC_INFECTED_BITE                 43353
#define SPELL_ACC_TAIL_SWIPE                    43352

class mob_amani_crocolist : public CreatureScript
{
public:
    mob_amani_crocolist() : CreatureScript("mob_amani_crocolist") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_amani_crocolistAI (pCreature);
    }

    struct mob_amani_crocolistAI : public mob_zulaman_trashAI
    {
        mob_amani_crocolistAI(Creature *c) : mob_zulaman_trashAI(c)
        {
            mob_zulaman_trashAI::CanDetectVisibility = false;
        }

        uint32 Tail_Timer;
        uint32 Bite_Timer;

        void Reset()
        {
            mob_zulaman_trashAI::Reset();

            Tail_Timer = urand(10000,15000);
            Bite_Timer = urand(10000,15000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() )
                return;

            if(Bite_Timer <= diff)
            {
                if(TryDoCast(me->getVictim(), SPELL_ACC_INFECTED_BITE))
                    Bite_Timer = urand(5000,15000);
            }else Bite_Timer -= diff;

            if(Tail_Timer <= diff)
            {
                if(TryDoCastAOE(SPELL_ACC_TAIL_SWIPE))
                    Tail_Timer = urand(15000,20000);
            }else Tail_Timer -= diff;

            mob_zulaman_trashAI::UpdateAI(diff);
        }
    };
};

void AddSC_zulaman()
{
    new npc_forest_frog();
    new npc_zulaman_hostage();
    new npc_zulaman_harrison_jones(); //UPDATE creature_template SET scriptname = 'npc_zulaman_harrison_jones' WHERE entry = 24358;
    new mob_amanishi_guardian(); //UPDATE creature_template SET scriptname = 'mob_amanishi_guardian' WHERE entry =23597;
    new mob_amanishi_wind_walker(); //UPDATE creature_template SET scriptname = 'mob_amanishi_wind_walker' WHERE entry =24179;
    new mob_amanishi_protector(); //UPDATE creature_template SET scriptname = 'mob_amanishi_protector' WHERE entry =24180;
    new mob_amanishi_medicine_man(); //UPDATE creature_template SET scriptname = 'mob_amanishi_medicine_man' WHERE entry =23581;
    new mob_amani_protective_ward(); //UPDATE creature_template SET scriptname = 'mob_amani_protective_ward' WHERE entry =23822;
    new mob_amanishi_lookout(); //UPDATE creature_template SET scriptname = 'mob_amanishi_lookout' WHERE entry =24175;
    new mob_amanishi_warrior(); //UPDATE creature_template SET scriptname = 'mob_amanishi_warrior' WHERE entry =24225;
    new mob_amani_eagle(); //UPDATE creature_template SET scriptname = 'mob_amani_eagle' WHERE entry =24159;
    new mob_amanishi_tempest(); //UPDATE creature_template SET scriptname = 'mob_amanishi_tempest' WHERE entry =24549;
    new mob_amanishi_tribesman(); //UPDATE creature_template SET scriptname = 'mob_amanishi_tribesman' WHERE entry =23582;
    new mob_amanishi_axe_thrower(); //UPDATE creature_template SET scriptname = 'mob_amanishi_axe_thrower' WHERE entry =23542;
    new mob_amanishi_warbringer(); //UPDATE creature_template SET scriptname = 'mob_amanishi_warbringer' WHERE entry =23580;
    new mob_amani_bear(); //UPDATE creature_template SET scriptname = 'mob_amani_bear' WHERE entry =23584;
    new mob_amanishi_scout(); //UPDATE creature_template SET scriptname = 'mob_amanishi_scout' WHERE entry =23586;
    new mob_amanishi_flame_caster(); //UPDATE creature_template SET scriptname = 'mob_amanishi_flame_caster' WHERE entry =23596;
    new mob_amanishi_trainer(); //UPDATE creature_template SET scriptname = 'mob_amanishi_trainer' WHERE entry =23774;
    new mob_amani_dragonhawk(); //UPDATE creature_template SET scriptname = 'mob_amani_dragonhawk' WHERE entry =23834;
    new mob_amanishi_handler(); //UPDATE creature_template SET scriptname = 'mob_amanishi_handler' WHERE entry =24065;
    new mob_amanishi_beast_tamer(); //UPDATE creature_template SET scriptname = 'mob_amanishi_beast_tamer' WHERE entry =24059;
    new mob_amani_elder_lynx(); //UPDATE creature_template SET scriptname = 'mob_amani_elder_lynx' WHERE entry =24530;
    new mob_amani_lynx(); //UPDATE creature_template SET scriptname = 'mob_amani_lynx' WHERE entry =24043;
    new mob_amani_lynx_cub(); //UPDATE creature_template SET scriptname = 'mob_amani_lynx_cub' WHERE entry =24064;
    new mob_amani_crocolist(); //UPDATE creature_template SET scriptname = 'mob_amani_crocolist' WHERE entry in (24138,24047);
}
