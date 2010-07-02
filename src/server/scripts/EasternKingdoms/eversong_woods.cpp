/* Copyright (C) 2008 - 2010 Trinity <http://www.trinitycore.org/>
 * Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Eversong_Woods
SD%Complete: 100
SDComment: Quest support: 8483, 8488, 8490, 9686
SDCategory: Eversong Woods
EndScriptData */

/* ContentData
npc_prospector_anvilward
npc_apprentice_mirveda
npc_infused_crystal
npc_kelerun_bloodmourn
go_harbinger_second_trial
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*######
## npc_prospector_anvilward
######*/

#define GOSSIP_HELLO    "I need a moment of your time, sir."
#define GOSSIP_SELECT   "Why... yes, of course. I've something to show you right inside this building, Mr. Anvilward."

enum eProspectorAnvilward
{
    SAY_ANVIL1                                  = -1000209,
    SAY_ANVIL2                                  = -1000210,
    QUEST_THE_DWARVEN_SPY                       = 8483,
};

struct npc_prospector_anvilwardAI : public npc_escortAI
{
    // CreatureAI functions
    npc_prospector_anvilwardAI(Creature *c) : npc_escortAI(c) {}

    // Pure Virtual Functions
    void WaypointReached(uint32 i)
    {
        Player* pPlayer = GetPlayerForEscort();

        if (!pPlayer)
            return;

        switch (i)
        {
            case 0: DoScriptText(SAY_ANVIL1, me, pPlayer); break;
            case 5: DoScriptText(SAY_ANVIL2, me, pPlayer); break;
            case 6: me->setFaction(24); break;
        }
    }

    void Reset()
    {
        me->RestoreFaction();
    }

    void JustDied(Unit* /*killer*/)
    {
        me->RestoreFaction();
    }
};

CreatureAI* GetAI_npc_prospector_anvilward(Creature* pCreature)
{
    return new npc_prospector_anvilwardAI(pCreature);
}

bool GossipHello_npc_prospector_anvilward(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_THE_DWARVEN_SPY) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(8239, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_prospector_anvilward(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(8240, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->CLOSE_GOSSIP_MENU();
            if (npc_escortAI* pEscortAI = CAST_AI(npc_prospector_anvilwardAI, pCreature->AI()))
                pEscortAI->Start(true, false, pPlayer->GetGUID());
            break;
    }
    return true;
}

/*######
## Quest 9686 Second Trial
######*/

#define QUEST_SECOND_TRIAL 9686

#define MASTER_KELERUN_BLOODMOURN 17807

#define CHAMPION_BLOODWRATH 17809
#define CHAMPION_LIGHTREND  17810
#define CHAMPION_SWIFTBLADE 17811
#define CHAMPION_SUNSTRIKER 17812

#define HARBINGER_OF_THE_SECOND_TRIAL 182052

#define SPELL_FLASH_OF_LIGHT 19939
#define TIMER_FLASH_OF_LIGHT 3225

#define SPELL_SEAL_OF_JUSTICE 20164
#define TIMER_SEAL_OF_JUSTICE 10000

#define SPELL_JUDGEMENT_OF_LIGHT 20271
#define TIMER_JUDGEMENT_OF_LIGHT 10000

#define SPELL_SEAL_OF_COMMAND 20375
#define TIMER_SEAL_OF_COMMAND 20000

#define OFFSET_NEXT_ATTACK 750

#define FACTION_HOSTILE    45
#define FACTION_FRIENDLY   7

// missing from db
#define TEXT_SECOND_TRIAL_1 -1645006
#define TEXT_SECOND_TRIAL_2 -1645007
#define TEXT_SECOND_TRIAL_3 -1645008
#define TEXT_SECOND_TRIAL_4 -1645009

struct Locations
{
    float x, y, z, o;
};

static Locations SpawnPosition[]=
{
    {5.3, -11.8, 0.361, 4.2},
    {11.2, -29.17, 0.361, 2.7},
    {-5.7, -34.85, 0.361, 1.09},
    {-11.9, -18, 0.361, 5.87}
};

static uint32 PaladinEntry[] = {CHAMPION_BLOODWRATH, CHAMPION_LIGHTREND, CHAMPION_SWIFTBLADE, CHAMPION_SUNSTRIKER};

/*######
## npc_second_trial_paladin
######*/

struct npc_secondTrialAI : public ScriptedAI
{
    npc_secondTrialAI(Creature *c) : ScriptedAI(c) {}

    uint32 timer;
    uint8  questPhase;
    uint64 summonerGuid;

    bool spellFlashLight;
    bool spellJustice;
    bool spellJudLight;
    bool spellCommand;

    uint32 timerFlashLight;
    uint32 timerJustice;
    uint32 timerJudLight;
    uint32 timerCommand;

    void Reset()
    {

      timer = 2000;
      questPhase = 0;
      summonerGuid = 0;

      me->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_KNEEL);
      me->setFaction(FACTION_FRIENDLY);

      spellFlashLight = false;
      spellJustice    = false;
      spellJudLight   = false;
      spellCommand    = false;

      switch(me->GetEntry())
      {
          case CHAMPION_BLOODWRATH:
              spellFlashLight = true;
              timerFlashLight = TIMER_FLASH_OF_LIGHT;
          break;
          case CHAMPION_LIGHTREND:
              spellJustice    = true;
              timerJustice    = 500;
          break;
          case CHAMPION_SWIFTBLADE:
              spellJudLight   = false;  // Misses Script Effect // http://www.wowhead.com/?spell=20271
              timerJudLight   = 500;
          break;
          case CHAMPION_SUNSTRIKER:
              spellFlashLight = true;
              spellJudLight   = false;  // Misses Script Effect // http://www.wowhead.com/?spell=20271
              spellCommand    = false;  // Misses Dummy // http://www.wowhead.com/?spell=20375
              timerFlashLight = TIMER_FLASH_OF_LIGHT;
              timerJudLight   = 500;
              timerCommand    = 1500;
          break;
      }
    }

    void EnterCombat(Unit * /*who*/) {}

    void UpdateAI(const uint32 diff)
    {
        if (questPhase == 1)
            if (timer <= diff)
            {
                me->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_STAND);
                me->setFaction(FACTION_HOSTILE);
                questPhase = 0;

                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                {
                    me->AddThreat(pTarget, 5000000.0f);
                    AttackStart(pTarget);
                }
            }
            else
                timer -= diff;

        if (!UpdateVictim())
          return;

        // healer
        if (spellFlashLight)
            if (me->GetHealth()*100 / me->GetMaxHealth() < 70)
                if (timerFlashLight <= diff)
                {
                    DoCast(me, SPELL_FLASH_OF_LIGHT);
                    timerFlashLight = TIMER_FLASH_OF_LIGHT +  rand()%TIMER_FLASH_OF_LIGHT;
                }
                else
                    timerFlashLight -= diff;

        if (spellJustice)
            if (timerJustice <= diff)
            {
                DoCast(me, SPELL_SEAL_OF_JUSTICE);
                timerJustice = TIMER_SEAL_OF_JUSTICE + rand()%TIMER_SEAL_OF_JUSTICE;
            }
            else
                timerJustice -= diff;

        if (spellJudLight)
            if (timerJudLight <= diff)
            {
                DoCast(me, SPELL_JUDGEMENT_OF_LIGHT);
                timerJudLight = TIMER_JUDGEMENT_OF_LIGHT + rand()%TIMER_JUDGEMENT_OF_LIGHT;
            }
            else
                timerJudLight -= diff;

          if (spellCommand)
              if (timerCommand <= diff)
              {
                  DoCast(me, TIMER_SEAL_OF_COMMAND);
                  timerCommand = TIMER_SEAL_OF_COMMAND + rand()%TIMER_SEAL_OF_COMMAND;
              }
              else
                  timerCommand -= diff;

          DoMeleeAttackIfReady();
    }

    void Activate(uint64 summonerguid);
    void KilledUnit(Unit* Killed);
    void JustDied(Unit* Killer);

};

/*######
## npc_second_trial_controller
######*/

struct master_kelerun_bloodmournAI : public ScriptedAI
{
    master_kelerun_bloodmournAI(Creature *c) : ScriptedAI(c) {}

    uint8  questPhase;
    uint8  paladinPhase;
    uint32 timer;

    uint64 paladinGuid[4];

    void Reset()
    {
        questPhase = 0;
        timer = 60000;
        paladinPhase = 0;
        for (uint8 i = 0; i < 4; ++i)
            paladinGuid[i] = 0;
    }

    void EnterCombat(Unit * /*who*/) {}

    void UpdateAI(const uint32 diff)
    {
        // Quest accepted but object not activated, object despawned (if in sync 1 minute!)
        if (questPhase == 1)
        {
            if (timer <= diff)
            Reset();
            else
            timer -= diff;
        }
        // fight the 4 paladin mobs phase
        else if (questPhase == 2)
        {
            if (timer <= diff)
            {
                if (Creature* paladinSpawn = Unit::GetCreature((*me), paladinGuid[paladinPhase]))
                {
                    CAST_AI(npc_secondTrialAI, paladinSpawn->AI())->Activate(me->GetGUID());

                    switch(paladinPhase)
                    {
                    case 0:
                        DoScriptText(TEXT_SECOND_TRIAL_1,me);
                        break;
                    case 1:
                        DoScriptText(TEXT_SECOND_TRIAL_2,me);
                        break;
                    case 2:
                        DoScriptText(TEXT_SECOND_TRIAL_3,me);
                        break;
                    case 3:
                        DoScriptText(TEXT_SECOND_TRIAL_4,me);
                        break;
                    }
                }
                else
                Reset();

                questPhase = 4;
                timer = OFFSET_NEXT_ATTACK;
            }
            else
            timer -= diff;
        }

        if (!UpdateVictim())
        return;

        DoMeleeAttackIfReady();
    }

    void StartEvent()
    {

        if (questPhase == 1)
        { // no player check, quest can be finished as group, so no complex PlayerGUID/group search code

            for (uint8 i = 0; i < 4; ++i)
            if (Creature *pSummoned = DoSpawnCreature(PaladinEntry[i], SpawnPosition[i].x, SpawnPosition[i].y, SpawnPosition[i].z, SpawnPosition[i].o, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 180000))
                paladinGuid[i] = pSummoned->GetGUID();

            timer = OFFSET_NEXT_ATTACK;
            questPhase = 2;
        }
    }

    void SecondTrialKill();
    void SummonedCreatureDespawn(Creature* /*c*/) {}
};

bool GossipHello_master_kelerun_bloodmourn(Player* pPlayer, Creature* pCreature)
{
    // quest only available if not already started
    // Quest_template flag is set to : QUEST_FLAGS_EVENT
    // Escort quests or any other event-driven quests. If player in party, all players that can accept this quest will receive confirmation box to accept quest.
    // !not sure if this really works!

    if (CAST_AI(master_kelerun_bloodmournAI, pCreature->AI())->questPhase == 0)
    {
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());
        pPlayer->SendPreparedQuest(pCreature->GetGUID());
    }

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetEntry(), pCreature->GetGUID());
    return true;
}

bool QuestAccept_master_kelerun_bloodmourn(Player* /*pPlayer*/, Creature* pCreature, Quest const *quest)
{
    // One Player exclusive quest, wait for user go activation
    if (quest->GetQuestId() == QUEST_SECOND_TRIAL)
        CAST_AI(master_kelerun_bloodmournAI, pCreature->AI())->questPhase = 1;

    return true;
}

void master_kelerun_bloodmournAI::SecondTrialKill()
{
    if (questPhase > 0)
    {
      ++paladinPhase;

      if (paladinPhase < 4)
          questPhase = 2;
      else
          Reset();  // Quest Complete, QuestComplete handler is in npc_secondTrialAI::JustDied
    }
}

void npc_secondTrialAI::JustDied(Unit* Killer)
{
    if (Killer->GetTypeId() == TYPEID_PLAYER)
    {
        if (Creature *pSummoner = Unit::GetCreature((*me), summonerGuid))
            CAST_AI(master_kelerun_bloodmournAI, pSummoner->AI())->SecondTrialKill();

        // last kill quest complete for group
        if (me->GetEntry() == CHAMPION_SUNSTRIKER)
        {
            if (Group *pGroup = CAST_PLR(Killer)->GetGroup())
            {
                for (GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                {
                    Player *pGroupGuy = itr->getSource();

                    // for any leave or dead (with not released body) group member at appropriate distance
                    if (pGroupGuy && pGroupGuy->IsAtGroupRewardDistance(me) && !pGroupGuy->GetCorpse() && pGroupGuy->GetQuestStatus(QUEST_SECOND_TRIAL) == QUEST_STATUS_INCOMPLETE)
                        pGroupGuy->CompleteQuest(QUEST_SECOND_TRIAL);
                }
            }
            else if (CAST_PLR(Killer)->GetQuestStatus(QUEST_SECOND_TRIAL) == QUEST_STATUS_INCOMPLETE)
                CAST_PLR(Killer)->CompleteQuest(QUEST_SECOND_TRIAL);
        }
    }
}

void npc_secondTrialAI::KilledUnit(Unit* Killed)
{
    if (Killed->GetTypeId() == TYPEID_PLAYER)
        if (CAST_PLR(Killed)->GetQuestStatus(QUEST_SECOND_TRIAL) == QUEST_STATUS_INCOMPLETE)
            CAST_PLR(Killed)->FailQuest(QUEST_SECOND_TRIAL);
}

void npc_secondTrialAI::Activate(uint64 summonerguid)
{
      questPhase = 1;
      summonerGuid = summonerguid;
}

CreatureAI* GetAI_master_kelerun_bloodmourn(Creature* pCreature)
{
    return new master_kelerun_bloodmournAI (pCreature);
}

CreatureAI* GetAI_npc_secondTrial(Creature* pCreature)
{
    return new npc_secondTrialAI (pCreature);
}

/*######
## go_second_trial
######*/

bool GOHello_go_second_trial(Player* /*pPlayer*/, GameObject* pGO)
{
    // find spawn :: master_kelerun_bloodmourn
    if (Creature *pCreature = pGO->FindNearestCreature(MASTER_KELERUN_BLOODMOURN, 30.0f))
       CAST_AI(master_kelerun_bloodmournAI, pCreature->AI())->StartEvent();

    return true;
}

/*######
## npc_apprentice_mirveda
######*/

#define QUEST_UNEXPECTED_RESULT 8488
#define MOB_GHARZUL     15958
#define MOB_ANGERSHADE  15656

struct npc_apprentice_mirvedaAI : public ScriptedAI
{
    npc_apprentice_mirvedaAI(Creature* c) : ScriptedAI(c), Summons(me) {}

    uint32 KillCount;
    uint64 PlayerGUID;
    bool Summon;
    SummonList Summons;

    void Reset()
    {
        KillCount = 0;
        PlayerGUID = 0;
        Summons.DespawnAll();
        Summon = false;
    }

    void EnterCombat(Unit* /*who*/){}

    void JustSummoned(Creature *summoned)
    {
        summoned->AI()->AttackStart(me);
        Summons.Summon(summoned);
    }

    void SummonedCreatureDespawn(Creature* summoned)
    {
        Summons.Despawn(summoned);
        ++KillCount;
    }

    void JustDied(Unit* /*killer*/)
    {
        if (PlayerGUID)
            if (Player* pPlayer = Unit::GetPlayer(PlayerGUID))
                CAST_PLR(pPlayer)->FailQuest(QUEST_UNEXPECTED_RESULT);
    }

    void UpdateAI(const uint32 /*diff*/)
    {
        if (KillCount >= 3 && PlayerGUID)
            if (Player* pPlayer = Unit::GetPlayer(PlayerGUID))
                CAST_PLR(pPlayer)->CompleteQuest(QUEST_UNEXPECTED_RESULT);

        if (Summon)
        {
            me->SummonCreature(MOB_GHARZUL, 8745, -7134.32, 35.22, 0, TEMPSUMMON_CORPSE_DESPAWN, 4000);
            me->SummonCreature(MOB_ANGERSHADE, 8745, -7134.32, 35.22, 0, TEMPSUMMON_CORPSE_DESPAWN, 4000);
            me->SummonCreature(MOB_ANGERSHADE, 8745, -7134.32, 35.22, 0, TEMPSUMMON_CORPSE_DESPAWN, 4000);
            Summon = false;
        }
    }
};

bool QuestAccept_npc_apprentice_mirveda(Player* pPlayer, Creature* pCreature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_UNEXPECTED_RESULT)
    {
        CAST_AI(npc_apprentice_mirvedaAI, pCreature->AI())->Summon = true;
        CAST_AI(npc_apprentice_mirvedaAI, pCreature->AI())->PlayerGUID = pPlayer->GetGUID();
    }
    return true;
}

CreatureAI* GetAI_npc_apprentice_mirvedaAI(Creature* pCreature)
{
    return new npc_apprentice_mirvedaAI (pCreature);
}

/*######
## npc_infused_crystal
######*/

#define MOB_ENRAGED_WRAITH  17086
#define EMOTE   -1000283
#define QUEST_POWERING_OUR_DEFENSES 8490

struct Location
{
    float x, y, z;
};

static Location SpawnLocations[] =
{
    {8270.68, -7188.53, 139.619},
    {8284.27, -7187.78, 139.603},
    {8297.43, -7193.53, 139.603},
    {8303.5, -7201.96, 139.577},
    {8273.22, -7241.82, 139.382},
    {8254.89, -7222.12, 139.603},
    {8278.51, -7242.13, 139.162},
    {8267.97, -7239.17, 139.517}
};

struct npc_infused_crystalAI : public Scripted_NoMovementAI
{
    npc_infused_crystalAI(Creature* c) : Scripted_NoMovementAI(c) {}

    uint32 EndTimer;
    uint32 WaveTimer;
    bool Completed;
    bool Progress;
    uint64 PlayerGUID;

    void Reset()
    {
        EndTimer = 0;
        Completed = false;
        Progress = false;
        PlayerGUID = 0;
        WaveTimer = 0;
    }

    void MoveInLineOfSight(Unit* who)
    {
        if (!Progress && who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 10.0f))
        {
            if (CAST_PLR(who)->GetQuestStatus(QUEST_POWERING_OUR_DEFENSES) == QUEST_STATUS_INCOMPLETE)
            {
                PlayerGUID = who->GetGUID();
                WaveTimer = 1000;
                EndTimer = 60000;
                Progress = true;
            }
        }
    }

    void JustSummoned(Creature *summoned)
    {
        summoned->AI()->AttackStart(me);
    }

    void JustDied(Unit* /*killer*/)
    {
        if (PlayerGUID && !Completed)
            if (Player* pPlayer = Unit::GetPlayer(PlayerGUID))
                CAST_PLR(pPlayer)->FailQuest(QUEST_POWERING_OUR_DEFENSES);
    }

    void UpdateAI(const uint32 diff)
    {
        if (EndTimer < diff && Progress)
        {
            DoScriptText(EMOTE, me);
            Completed = true;
            if (PlayerGUID)
                if (Player* pPlayer = Unit::GetPlayer(PlayerGUID))
                    CAST_PLR(pPlayer)->CompleteQuest(QUEST_POWERING_OUR_DEFENSES);

            me->DealDamage(me,me->GetHealth(),NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            me->RemoveCorpse();
        } else EndTimer -= diff;

        if (WaveTimer < diff && !Completed && Progress)
        {
            uint32 ran1 = rand()%8;
            uint32 ran2 = rand()%8;
            uint32 ran3 = rand()%8;
            me->SummonCreature(MOB_ENRAGED_WRAITH, SpawnLocations[ran1].x, SpawnLocations[ran1].y, SpawnLocations[ran1].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
            me->SummonCreature(MOB_ENRAGED_WRAITH, SpawnLocations[ran2].x, SpawnLocations[ran2].y, SpawnLocations[ran2].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
            me->SummonCreature(MOB_ENRAGED_WRAITH, SpawnLocations[ran3].x, SpawnLocations[ran3].y, SpawnLocations[ran3].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
            WaveTimer = 30000;
        } else WaveTimer -= diff;
    }
};

CreatureAI* GetAI_npc_infused_crystalAI(Creature* pCreature)
{
    return new npc_infused_crystalAI (pCreature);
}

void AddSC_eversong_woods()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_prospector_anvilward";
    newscript->GetAI = &GetAI_npc_prospector_anvilward;
    newscript->pGossipHello =  &GossipHello_npc_prospector_anvilward;
    newscript->pGossipSelect = &GossipSelect_npc_prospector_anvilward;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_second_trial_controller";
    newscript->GetAI = &GetAI_master_kelerun_bloodmourn;
    newscript->pGossipHello = &GossipHello_master_kelerun_bloodmourn;
    newscript->pQuestAccept = &QuestAccept_master_kelerun_bloodmourn;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_second_trial_paladin";
    newscript->GetAI = &GetAI_npc_secondTrial;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_second_trial";
    newscript->pGOHello =  &GOHello_go_second_trial;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_apprentice_mirveda";
    newscript->GetAI = &GetAI_npc_apprentice_mirvedaAI;
    newscript->pQuestAccept = &QuestAccept_npc_apprentice_mirveda;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_infused_crystal";
    newscript->GetAI = &GetAI_npc_infused_crystalAI;
    newscript->RegisterSelf();
}
