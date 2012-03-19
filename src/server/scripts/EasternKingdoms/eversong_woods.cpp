/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
## Quest 9686 Second Trial
######*/

enum SeconTrial
{
    QUEST_SECOND_TRIAL                = 9686,
    OFFSET_NEXT_ATTACK                = 750,
};

enum eSpells
{
    SPELL_FLASH_OF_LIGHT              = 19939,
    SPELL_SEAL_OF_JUSTICE             = 20164,
    SPELL_JUDGEMENT_OF_LIGHT          = 20271,
    SPELL_SEAL_OF_COMMAND             = 20375,
};

enum eNpc
{
    MASTER_KELERUN_BLOODMOURN         = 17807,
    CHAMPION_BLOODWRATH               = 17809,
    CHAMPION_LIGHTREND                = 17810,
    CHAMPION_SWIFTBLADE               = 17811,
    CHAMPION_SUNSTRIKER               = 17812,
};

enum eFaction
{
    FACTION_HOSTILE                   = 45,
    FACTION_FRIENDLY                  = 7,
};

enum eSays
{
    TEXT_SECOND_TRIAL_1               = 0,
    TEXT_SECOND_TRIAL_2               = 1,
    TEXT_SECOND_TRIAL_3               = 2,
    TEXT_SECOND_TRIAL_4               = 3,
};

struct Locations
{
    float x, y, z, o;
};

static Locations SpawnPosition[]=
{
    {5.3f, -11.8f, 0.361f, 4.2f},
    {11.2f, -29.17f, 0.361f, 2.7f},
    {-5.7f, -34.85f, 0.361f, 1.09f},
    {-11.9f, -18, 0.361f, 5.87f}
};

static uint32 PaladinEntry[] = {CHAMPION_BLOODWRATH, CHAMPION_LIGHTREND, CHAMPION_SWIFTBLADE, CHAMPION_SUNSTRIKER};

/*######
## npc_second_trial_paladin
######*/

class npc_second_trial_paladin : public CreatureScript
{
public:
    npc_second_trial_paladin() : CreatureScript("npc_second_trial_paladin") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_secondTrialAI (creature);
    }

    struct npc_secondTrialAI : public ScriptedAI
    {
        npc_secondTrialAI(Creature* creature) : ScriptedAI(creature) {}

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

          switch (me->GetEntry())
          {
              case CHAMPION_BLOODWRATH:
                  spellFlashLight = true;
                  timerFlashLight = 3225;
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
                  timerFlashLight = 3225;
                  timerJudLight   = 500;
                  timerCommand    = 1500;
              break;
          }
        }

        void EnterCombat(Unit* /*who*/) {}

        void UpdateAI(const uint32 diff)
        {
            if (questPhase == 1)
            {
                if (timer <= diff)
                {
                    me->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_STAND);
                    me->setFaction(FACTION_HOSTILE);
                    questPhase = 0;

                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        me->AddThreat(target, 5000000.0f);
                        AttackStart(target);
                    }
                }
                else
                    timer -= diff;
            }

            if (!UpdateVictim())
              return;

            // healer
            if (spellFlashLight && HealthBelowPct(70))
            {
                if (timerFlashLight <= diff)
                {
                    DoCast(me, SPELL_FLASH_OF_LIGHT);
                    timerFlashLight = 3225 +  rand()%3225;
                }
                else
                    timerFlashLight -= diff;
            }

            if (spellJustice)
            {
                if (timerJustice <= diff)
                {
                    DoCast(me, SPELL_SEAL_OF_JUSTICE);
                    timerJustice = urand(10000, 20000);
                }
                else
                    timerJustice -= diff;
            }

            if (spellJudLight)
            {
                if (timerJudLight <= diff)
                {
                    DoCast(me, SPELL_JUDGEMENT_OF_LIGHT);
                    timerJudLight = urand(10000, 20000);
                }
                else
                    timerJudLight -= diff;
            }

            if (spellCommand)
            {
                  if (timerCommand <= diff)
                  {
                      DoCast(me, SPELL_SEAL_OF_COMMAND);
                      timerCommand = urand(20000, 40000);
                  }
                  else
                      timerCommand -= diff;
            }

            DoMeleeAttackIfReady();
        }

        void Activate(uint64 summonerguid)
        {
            questPhase = 1;
            summonerGuid = summonerguid;
        }

        void KilledUnit(Unit* Killed)
        {
            if (Killed->GetTypeId() == TYPEID_PLAYER)
                if (CAST_PLR(Killed)->GetQuestStatus(QUEST_SECOND_TRIAL) == QUEST_STATUS_INCOMPLETE)
                    CAST_PLR(Killed)->FailQuest(QUEST_SECOND_TRIAL);
        }

        void JustDied(Unit* Killer);
    };
};

/*######
## npc_second_trial_controller
######*/

class npc_second_trial_controller : public CreatureScript
{
public:
    npc_second_trial_controller() : CreatureScript("npc_second_trial_controller") { }

    bool OnQuestAccept(Player* /*player*/, Creature* creature, Quest const* quest)
    {
        // One Player exclusive quest, wait for user go activation
        if (quest->GetQuestId() == QUEST_SECOND_TRIAL)
            CAST_AI(npc_second_trial_controller::master_kelerun_bloodmournAI, creature->AI())->questPhase = 1;

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        // quest only available if not already started
        // Quest_template flag is set to : QUEST_FLAGS_EVENT
        // Escort quests or any other event-driven quests. If player in party, all players that can accept this quest will receive confirmation box to accept quest.
        // !not sure if this really works!

        if (CAST_AI(npc_second_trial_controller::master_kelerun_bloodmournAI, creature->AI())->questPhase == 0)
        {
            player->PrepareQuestMenu(creature->GetGUID());
            player->SendPreparedQuest(creature->GetGUID());
        }

        player->SEND_GOSSIP_MENU(creature->GetEntry(), creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new master_kelerun_bloodmournAI (creature);
    }

    struct master_kelerun_bloodmournAI : public ScriptedAI
    {
        master_kelerun_bloodmournAI(Creature* creature) : ScriptedAI(creature) {}

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

        void EnterCombat(Unit* /*who*/) {}

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
                        CAST_AI(npc_second_trial_paladin::npc_secondTrialAI, paladinSpawn->AI())->Activate(me->GetGUID());

                        switch (paladinPhase)
                        {
                        case 0:
                            Talk(TEXT_SECOND_TRIAL_1);
                            break;
                        case 1:
                            Talk(TEXT_SECOND_TRIAL_2);
                            break;
                        case 2:
                            Talk(TEXT_SECOND_TRIAL_3);
                            break;
                        case 3:
                            Talk(TEXT_SECOND_TRIAL_4);
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
                if (Creature* summoned = DoSpawnCreature(PaladinEntry[i], SpawnPosition[i].x, SpawnPosition[i].y, SpawnPosition[i].z, SpawnPosition[i].o, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 180000))
                    paladinGuid[i] = summoned->GetGUID();

                timer = OFFSET_NEXT_ATTACK;
                questPhase = 2;
            }
        }

        void SecondTrialKill()
        {
            if (questPhase > 0)
            {
              ++paladinPhase;

              if (paladinPhase < 4)
                  questPhase = 2;
              else
                  Reset();  // Quest Complete, QuestComplete handler is
            }
        }

        void SummonedCreatureDespawn(Creature* /*c*/) {}
    };
};

void npc_second_trial_paladin::npc_secondTrialAI::JustDied(Unit* Killer)
{
    if (Killer->GetTypeId() == TYPEID_PLAYER)
    {
        if (Creature* summoner = Unit::GetCreature((*me), summonerGuid))
            CAST_AI(npc_second_trial_controller::master_kelerun_bloodmournAI, summoner->AI())->SecondTrialKill();

        // last kill quest complete for group
        if (me->GetEntry() == CHAMPION_SUNSTRIKER)
        {
            if (Killer->GetTypeId() == TYPEID_PLAYER)
                Killer->ToPlayer()->GroupEventHappens(QUEST_SECOND_TRIAL, Killer);
        }
    }
}

/*######
## go_second_trial
######*/
class go_second_trial : public GameObjectScript
{
public:
    go_second_trial() : GameObjectScript("go_second_trial") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go)
    {
        // find spawn :: master_kelerun_bloodmourn
        if (Creature* creature = go->FindNearestCreature(MASTER_KELERUN_BLOODMOURN, 30.0f))
           CAST_AI(npc_second_trial_controller::master_kelerun_bloodmournAI, creature->AI())->StartEvent();

        return true;
    }
};

/*######
## npc_apprentice_mirveda
######*/

#define QUEST_UNEXPECTED_RESULT 8488
#define MOB_GHARZUL     15958
#define MOB_ANGERSHADE  15656

class npc_apprentice_mirveda : public CreatureScript
{
public:
    npc_apprentice_mirveda() : CreatureScript("npc_apprentice_mirveda") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_UNEXPECTED_RESULT)
        {
            CAST_AI(npc_apprentice_mirveda::npc_apprentice_mirvedaAI, creature->AI())->Summon = true;
            CAST_AI(npc_apprentice_mirveda::npc_apprentice_mirvedaAI, creature->AI())->PlayerGUID = player->GetGUID();
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_apprentice_mirvedaAI (creature);
    }

    struct npc_apprentice_mirvedaAI : public ScriptedAI
    {
        npc_apprentice_mirvedaAI(Creature* creature) : ScriptedAI(creature), Summons(me) {}

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

        void JustSummoned(Creature* summoned)
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
                if (Player* player = Unit::GetPlayer(*me, PlayerGUID))
                    CAST_PLR(player)->FailQuest(QUEST_UNEXPECTED_RESULT);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (KillCount >= 3 && PlayerGUID)
                if (Player* player = Unit::GetPlayer(*me, PlayerGUID))
                    CAST_PLR(player)->CompleteQuest(QUEST_UNEXPECTED_RESULT);

            if (Summon)
            {
                me->SummonCreature(MOB_GHARZUL, 8745, -7134.32f, 35.22f, 0, TEMPSUMMON_CORPSE_DESPAWN, 4000);
                me->SummonCreature(MOB_ANGERSHADE, 8745, -7134.32f, 35.22f, 0, TEMPSUMMON_CORPSE_DESPAWN, 4000);
                me->SummonCreature(MOB_ANGERSHADE, 8745, -7134.32f, 35.22f, 0, TEMPSUMMON_CORPSE_DESPAWN, 4000);
                Summon = false;
            }
        }
    };
};

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
    {8270.68f, -7188.53f, 139.619f},
    {8284.27f, -7187.78f, 139.603f},
    {8297.43f, -7193.53f, 139.603f},
    {8303.5f, -7201.96f, 139.577f},
    {8273.22f, -7241.82f, 139.382f},
    {8254.89f, -7222.12f, 139.603f},
    {8278.51f, -7242.13f, 139.162f},
    {8267.97f, -7239.17f, 139.517f}
};

class npc_infused_crystal : public CreatureScript
{
public:
    npc_infused_crystal() : CreatureScript("npc_infused_crystal") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_infused_crystalAI (creature);
    }

    struct npc_infused_crystalAI : public Scripted_NoMovementAI
    {
        npc_infused_crystalAI(Creature* creature) : Scripted_NoMovementAI(creature) {}

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

        void JustSummoned(Creature* summoned)
        {
            summoned->AI()->AttackStart(me);
        }

        void JustDied(Unit* /*killer*/)
        {
            if (PlayerGUID && !Completed)
                if (Player* player = Unit::GetPlayer(*me, PlayerGUID))
                    CAST_PLR(player)->FailQuest(QUEST_POWERING_OUR_DEFENSES);
        }

        void UpdateAI(const uint32 diff)
        {
            if (EndTimer < diff && Progress)
            {
                DoScriptText(EMOTE, me);
                Completed = true;
                if (PlayerGUID)
                    if (Player* player = Unit::GetPlayer(*me, PlayerGUID))
                        CAST_PLR(player)->CompleteQuest(QUEST_POWERING_OUR_DEFENSES);

                me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
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
};

void AddSC_eversong_woods()
{
    new npc_second_trial_controller();
    new npc_second_trial_paladin();
    new go_second_trial();
    new npc_apprentice_mirveda();
    new npc_infused_crystal();
}
