/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>.sourceforge.net/>
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

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"

/*######
## npc_prospector_anvilward
######*/

#define GOSSIP_HELLO    "I need a moment of your time, sir."
#define GOSSIP_SELECT   "Why... yes, of course. I've something to show you right inside this building, Mr. Anvilward."

#define SAY_PR_1 -1000281
#define SAY_PR_2 -1000282

#define QUEST_THE_DWARVEN_SPY 8483

struct TRINITY_DLL_DECL npc_prospector_anvilwardAI : public npc_escortAI
{
    // CreatureAI functions
    npc_prospector_anvilwardAI(Creature *c) : npc_escortAI(c) {}

    // Pure Virtual Functions
    void WaypointReached(uint32 i)
    {
        Player* player = Unit::GetPlayer(PlayerGUID);

        if(!player)
            return;

        switch (i)
        {
            case 0: DoScriptText(SAY_PR_1, m_creature, player); break;
            case 5: DoScriptText(SAY_PR_2, m_creature, player); break;
            case 6: m_creature->setFaction(24); break;
        }
    }

    void EnterCombat(Unit* who) { }

    void Reset()
    {
        m_creature->setFaction(35);
    }

    void JustDied(Unit* killer)
    {
        m_creature->setFaction(35);
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
    }
};

CreatureAI* GetAI_npc_prospector_anvilward(Creature* pCreature)
{
    npc_prospector_anvilwardAI* thisAI = new npc_prospector_anvilwardAI(pCreature);

    thisAI->FillPointMovementListForCreature();

    return (CreatureAI*)thisAI;
}

bool GossipHello_npc_prospector_anvilward(Player *player, Creature *_Creature)
{
    if( player->GetQuestStatus(QUEST_THE_DWARVEN_SPY) == QUEST_STATUS_INCOMPLETE )
        player->ADD_GOSSIP_ITEM(0, GOSSIP_HELLO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(8239, _Creature->GetGUID());
    return true;
}

bool GossipSelect_npc_prospector_anvilward(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch(action)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_SELECT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            player->SEND_GOSSIP_MENU(8240, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->CLOSE_GOSSIP_MENU();
            ((npc_escortAI*)(_Creature->AI()))->Start(true, true, false, player->GetGUID());
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

static uint32 PaladinEntry[]= {CHAMPION_BLOODWRATH, CHAMPION_LIGHTREND, CHAMPION_SWIFTBLADE, CHAMPION_SUNSTRIKER};

/*######
## npc_second_trial_paladin
######*/

struct TRINITY_DLL_DECL npc_secondTrialAI : public ScriptedAI
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


    void Reset() {

      timer = 2000;
      questPhase = 0;
      summonerGuid = 0;

      m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_KNEEL);
      m_creature->setFaction(FACTION_FRIENDLY);

      spellFlashLight = false;
      spellJustice    = false;
      spellJudLight   = false;
      spellCommand    = false;

      switch(m_creature->GetEntry() ) {
        case CHAMPION_BLOODWRATH :
          spellFlashLight = true;
          timerFlashLight = TIMER_FLASH_OF_LIGHT;
        break;
        case CHAMPION_LIGHTREND :
          spellJustice    = true;
          timerJustice    = 500;
        break;
        case CHAMPION_SWIFTBLADE :
          spellJudLight   = false;  // Misses Script Effect // http://www.wowhead.com/?spell=20271
          timerJudLight   = 500;
        break;
        case CHAMPION_SUNSTRIKER :
          spellFlashLight = true;
          spellJudLight   = false;  // Misses Script Effect // http://www.wowhead.com/?spell=20271
          spellCommand    = false;  // Misses Dummy // http://www.wowhead.com/?spell=20375
          timerFlashLight = TIMER_FLASH_OF_LIGHT;
          timerJudLight   = 500;
          timerCommand    = 1500;
        break;
      }
    }

    void EnterCombat(Unit *who) { }

    void UpdateAI(const uint32 diff)
    {
      if ( questPhase == 1 ) {

        if ( timer < diff ) {
              m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_STAND);
              m_creature->setFaction(FACTION_HOSTILE);
              questPhase = 0;

              Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 0);
              if(target && target->GetTypeId() == TYPEID_PLAYER) // only on players.
              {
                m_creature->AddThreat(target, 5000000.0f);
                AttackStart(target);
              }
         }
         else timer -= diff;
      }

      if (!UpdateVictim())
          return;

      // healer
      if ( spellFlashLight ) {
        if ( m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 70 ){
          if ( timerFlashLight < diff ) {
            DoCast(m_creature, SPELL_FLASH_OF_LIGHT);
            timerFlashLight = TIMER_FLASH_OF_LIGHT +  rand()%( TIMER_FLASH_OF_LIGHT );
          }
          else
            timerFlashLight -= diff;
        }
      }

      if ( spellJustice ) {
          if ( timerJustice < diff )
            {
            DoCast(m_creature, SPELL_SEAL_OF_JUSTICE);
            timerJustice = TIMER_SEAL_OF_JUSTICE +  rand()%( TIMER_SEAL_OF_JUSTICE );
          }
          else
            timerJustice -= diff;
      }

      if ( spellJudLight ) {
          if ( timerJudLight < diff ) {
            DoCast(m_creature,  SPELL_JUDGEMENT_OF_LIGHT);
            timerJudLight = TIMER_JUDGEMENT_OF_LIGHT +  rand()%( TIMER_JUDGEMENT_OF_LIGHT );
          }
          else
            timerJudLight -= diff;
      }

      if ( spellCommand ) {
          if ( timerCommand < diff ) {
            DoCast(m_creature,  TIMER_SEAL_OF_COMMAND);
            timerCommand = TIMER_SEAL_OF_COMMAND +  rand()%( TIMER_SEAL_OF_COMMAND );
          }
          else
            timerCommand -= diff;
      }

      DoMeleeAttackIfReady();
    }

    void Activate(uint64 summonerguid);
    void KilledUnit(Unit* Killed);
    void JustDied(Unit* Killer);

};

/*######
## npc_second_trial_controller
######*/

struct TRINITY_DLL_DECL master_kelerun_bloodmournAI : public ScriptedAI
{
    master_kelerun_bloodmournAI(Creature *c) : ScriptedAI(c) {}

    uint8  questPhase;
    uint8  paladinPhase;
    uint32 timer;

    uint64 paladinGuid[4];

    void Reset() {

      questPhase = 0;
      timer = 60000;
      paladinPhase = 0;
      uint64 paladinGuid[] = {0,0,0,0};

    }

    void EnterCombat(Unit *who) {}

    void UpdateAI(const uint32 diff)
    {
      // Quest accepted but object not activated, object despawned (if in sync 1 minute! )
      if ( questPhase == 1 ) {
         if ( timer < diff ) Reset();
         else timer -= diff;
      }
      // fight the 4 paladin mobs phase
      else if ( questPhase == 2 ) {

        if ( timer < diff ) {

          Creature* paladinSpawn;
          paladinSpawn = (Unit::GetCreature((*m_creature), paladinGuid[paladinPhase]));
            if ( paladinSpawn ) {
               ((npc_secondTrialAI*)paladinSpawn->AI())->Activate(m_creature->GetGUID());

               switch(paladinPhase) {
                 case 0:
                  DoScriptText(TEXT_SECOND_TRIAL_1,m_creature);
                 break;
                 case 1:
                   DoScriptText(TEXT_SECOND_TRIAL_2,m_creature);
                 break;
                 case 2:
                  DoScriptText(TEXT_SECOND_TRIAL_3,m_creature);
                 break;
                 case 3:
                  DoScriptText(TEXT_SECOND_TRIAL_4,m_creature);
                 break;
               }
            }
            else
              Reset();

            questPhase=4;
            timer = OFFSET_NEXT_ATTACK;
        }
         else timer -= diff;
      }

      if (!UpdateVictim())
          return;

      DoMeleeAttackIfReady();
    }

    void StartEvent()
    {

      if ( questPhase == 1 ) { // no player check, quest can be finished as group, so no complex playerguid/group search code

        for (int i = 0; i<4; i++) {
          Creature* Summoned;
          Summoned = DoSpawnCreature(PaladinEntry[i], SpawnPosition[i].x, SpawnPosition[i].y, SpawnPosition[i].z, SpawnPosition[i].o, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 180000);

          if(Summoned)
            paladinGuid[i] = Summoned->GetGUID();
        }

        timer = OFFSET_NEXT_ATTACK;
        questPhase = 2;
        }
    }

    void SecondTrialKill();
    void SummonedCreatureDespawn(Creature* c) {}
};


bool GossipHello_master_kelerun_bloodmourn(Player *player, Creature *_Creature)
{
    // quest only available if not already started
    // Quest_template flag is set to : QUEST_FLAGS_EVENT
    // Escort quests or any other event-driven quests. If player in party, all players that can accept this quest will receive confirmation box to accept quest.
    // !not sure if this really works!

    if ( ((master_kelerun_bloodmournAI*)_Creature->AI())->questPhase == 0 ) {
        player->PrepareQuestMenu(_Creature->GetGUID());
        player->SendPreparedQuest(_Creature->GetGUID());
    }

    player->SEND_GOSSIP_MENU(_Creature->GetEntry(), _Creature->GetGUID());
    return true;
}

bool QuestAccept_master_kelerun_bloodmourn(Player *player, Creature *creature, Quest const *quest )
{
    // One Player exclusive quest, wait for user go activation
    if(quest->GetQuestId() == QUEST_SECOND_TRIAL )
        ((master_kelerun_bloodmournAI*)creature->AI())->questPhase = 1;

    return true;
}

void master_kelerun_bloodmournAI::SecondTrialKill() {

      if ( questPhase > 0 ) {

        ++paladinPhase;

        if ( paladinPhase < 4 )
          questPhase=2;
        else
          Reset();  // Quest Complete, QuestComplete handler is in npc_secondTrialAI::JustDied
      }
  }

void npc_secondTrialAI::JustDied(Unit* Killer) {

      if (Killer->GetTypeId() == TYPEID_PLAYER)
      {
          Creature* Summoner;
          Summoner = (Unit::GetCreature((*m_creature), summonerGuid));

          if ( Summoner )
            ((master_kelerun_bloodmournAI*)Summoner->AI())->SecondTrialKill();

          // last kill quest complete for group
          if ( m_creature->GetEntry() == CHAMPION_SUNSTRIKER ) {

            if( Group *pGroup = ((Player*)Killer)->GetGroup() )
            {
               for(GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
               {
                 Player *pGroupGuy = itr->getSource();

                 // for any leave or dead (with not released body) group member at appropriate distance
                 if( pGroupGuy && pGroupGuy->IsAtGroupRewardDistance(m_creature) && !pGroupGuy->GetCorpse() && pGroupGuy->GetQuestStatus( QUEST_SECOND_TRIAL ) == QUEST_STATUS_INCOMPLETE )
                   pGroupGuy->CompleteQuest( QUEST_SECOND_TRIAL );
                }
            }
            else {
               if ( ((Player*)Killer)->GetQuestStatus( QUEST_SECOND_TRIAL ) == QUEST_STATUS_INCOMPLETE )
                   ((Player*)Killer)->CompleteQuest( QUEST_SECOND_TRIAL );
            }
          }
      }
  }

void npc_secondTrialAI::KilledUnit(Unit* Killed) {

  if ( Killed->GetTypeId() == TYPEID_PLAYER ) {

      if ( ((Player*)Killed)->GetQuestStatus(QUEST_SECOND_TRIAL) == QUEST_STATUS_INCOMPLETE )
        ((Player*)Killed)->FailQuest(QUEST_SECOND_TRIAL);
  }
}

void npc_secondTrialAI::Activate(uint64 summonerguid) {

      questPhase=1;
      summonerGuid = summonerguid;
    }

CreatureAI* GetAI_master_kelerun_bloodmourn(Creature *_Creature)
{
    return new master_kelerun_bloodmournAI (_Creature);
}

CreatureAI* GetAI_npc_secondTrial(Creature *_Creature)
{
    return new npc_secondTrialAI (_Creature);
}

/*######
## go_second_trial
######*/

bool GOHello_go_second_trial(Player *player, GameObject* _GO)
{
    // find spawn :: master_kelerun_bloodmourn
    CellPair p(Trinity::ComputeCellPair(_GO->GetPositionX(), _GO->GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();
    CellLock<GridReadGuard> cell_lock(cell, p);

    Creature* event_controller = NULL;
    Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck u_check(*_GO, MASTER_KELERUN_BLOODMOURN, true, 30);
    Trinity::CreatureLastSearcher<Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck> searcher(player, event_controller, u_check);
    TypeContainerVisitor<Trinity::CreatureLastSearcher<Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);
    //cell_lock->Visit(cell_lock, grid_unit_searcher, *MapManager::Instance().GetMap(_GO->GetMap(), _GO));
    cell_lock->Visit(cell_lock, grid_unit_searcher, *(_GO->GetMap()));

    if ( event_controller )
       ((master_kelerun_bloodmournAI*)event_controller->AI())->StartEvent();

    return true;
}

/*######
## npc_apprentice_mirveda
######*/

#define QUEST_UNEXPECTED_RESULT 8488
#define MOB_GHARZUL     15958
#define MOB_ANGERSHADE  15656

struct TRINITY_DLL_DECL npc_apprentice_mirvedaAI : public ScriptedAI
{
    npc_apprentice_mirvedaAI(Creature* c) : ScriptedAI(c), Summons(m_creature) {}

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

    void EnterCombat(Unit* who){}

    void JustSummoned(Creature *summoned)
    {
        summoned->AI()->AttackStart(m_creature);
        Summons.Summon(summoned);
    }

    void SummonedCreatureDespawn(Creature* summoned)
    {
        Summons.Despawn(summoned);
        ++KillCount;
    }

    void JustDied(Unit* killer)
    {
        if (PlayerGUID)
        {
            Player* player = Unit::GetPlayer(PlayerGUID);
            if (player)
                ((Player*)player)->FailQuest(QUEST_UNEXPECTED_RESULT);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(KillCount >= 3)
        {
            if (PlayerGUID)
            {
                Player* player = Unit::GetPlayer(PlayerGUID);
                if(player)
                    ((Player*)player)->CompleteQuest(QUEST_UNEXPECTED_RESULT);
            }
        }

        if(Summon)
        {
            m_creature->SummonCreature(MOB_GHARZUL, 8745, -7134.32, 35.22, 0, TEMPSUMMON_CORPSE_DESPAWN, 4000);
            m_creature->SummonCreature(MOB_ANGERSHADE, 8745, -7134.32, 35.22, 0, TEMPSUMMON_CORPSE_DESPAWN, 4000);
            m_creature->SummonCreature(MOB_ANGERSHADE, 8745, -7134.32, 35.22, 0, TEMPSUMMON_CORPSE_DESPAWN, 4000);
            Summon = false;
        }
    }
};

bool QuestAccept_npc_apprentice_mirveda(Player* player, Creature* creature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_UNEXPECTED_RESULT)
    {
        ((npc_apprentice_mirvedaAI*)creature->AI())->Summon = true;
        ((npc_apprentice_mirvedaAI*)creature->AI())->PlayerGUID = player->GetGUID();
    }
    return true;
}

CreatureAI* GetAI_npc_apprentice_mirvedaAI(Creature *_Creature)
{
    return new npc_apprentice_mirvedaAI (_Creature);
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

static Location SpawnLocations[]=
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

struct TRINITY_DLL_DECL npc_infused_crystalAI : public Scripted_NoMovementAI
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

    void EnterCombat(Unit* who){}

    void MoveInLineOfSight(Unit* who)
    {
        if( who->GetTypeId() == TYPEID_PLAYER && !m_creature->canStartAttack(who) && !Progress)
        {
            if( ((Player*)who)->GetQuestStatus(QUEST_POWERING_OUR_DEFENSES) == QUEST_STATUS_INCOMPLETE )
            {
                float Radius = 10.0;
                if( m_creature->IsWithinDistInMap(who, Radius) )
                {
                    PlayerGUID = who->GetGUID();
                    WaveTimer = 1000;
                    EndTimer = 60000;
                    Progress = true;
                }
            }
        }
    }

    void JustSummoned(Creature *summoned)
    {
        summoned->AI()->AttackStart(m_creature);
    }

    void JustDied(Unit* killer)
    {
        if (PlayerGUID && !Completed)
        {
            Player* player = Unit::GetPlayer(PlayerGUID);
            if (player)
                ((Player*)player)->FailQuest(QUEST_POWERING_OUR_DEFENSES);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(EndTimer < diff && Progress)
        {
            DoScriptText(EMOTE, m_creature);
            Completed = true;
            if (PlayerGUID)
            {
                Player* player = Unit::GetPlayer(PlayerGUID);
                if(player)
                    ((Player*)player)->CompleteQuest(QUEST_POWERING_OUR_DEFENSES);
            }
            m_creature->DealDamage(m_creature,m_creature->GetHealth(),NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            m_creature->RemoveCorpse();
        }else EndTimer -= diff;

        if(WaveTimer < diff && !Completed && Progress)
        {
            uint32 ran1 = rand()%8;
            uint32 ran2 = rand()%8;
            uint32 ran3 = rand()%8;
            m_creature->SummonCreature(MOB_ENRAGED_WRAITH, SpawnLocations[ran1].x, SpawnLocations[ran1].y, SpawnLocations[ran1].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
            m_creature->SummonCreature(MOB_ENRAGED_WRAITH, SpawnLocations[ran2].x, SpawnLocations[ran2].y, SpawnLocations[ran2].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
            m_creature->SummonCreature(MOB_ENRAGED_WRAITH, SpawnLocations[ran3].x, SpawnLocations[ran3].y, SpawnLocations[ran3].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
            WaveTimer = 30000;
        }else WaveTimer -= diff;
    }
};

CreatureAI* GetAI_npc_infused_crystalAI(Creature *_Creature)
{
    return new npc_infused_crystalAI (_Creature);
}

void AddSC_eversong_woods()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name= "npc_prospector_anvilward";
    newscript->GetAI = &GetAI_npc_prospector_anvilward;
    newscript->pGossipHello =  &GossipHello_npc_prospector_anvilward;
    newscript->pGossipSelect = &GossipSelect_npc_prospector_anvilward;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_second_trial_controller";
    newscript->GetAI = &GetAI_master_kelerun_bloodmourn;
    newscript->pGossipHello = &GossipHello_master_kelerun_bloodmourn;
    newscript->pQuestAccept = &QuestAccept_master_kelerun_bloodmourn;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_second_trial_paladin";
    newscript->GetAI = &GetAI_npc_secondTrial;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_second_trial";
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

