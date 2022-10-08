/*
 * Copyright (C) 2022 BfaCore Reforged
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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
#include "ScriptedEscortAI.h"
#include "Player.h"
#include "Unit.h"
#include "UnitAI.h"
#include "GameObject.h"
#include "ObjectAccessor.h"
#include "Object.h"
#include "QuestDef.h"

enum UnexpectedResults
{
    // Quest
    QUEST_UNEXPECTED_RESULT         = 8488,
    QUEST_SECOND_TRIAL              = 9686,
    OFFSET_NEXT_ATTACK              = 750,

    // Creatures
    NPC_GHARZUL                     = 15958,
    NPC_ANGERSHADE                  = 15656,
    CHAMPION_BLOODWRATH             = 17809,
    CHAMPION_LIGHTREND              = 17810,
    CHAMPION_SWIFTBLADE             = 17811,
    CHAMPION_SUNSTRIKER             = 17812,
    MASTER_KELERUN_BLOODMOURN       = 17807
};

enum eFaction
{
    FACTION_HOSTILE = 45,
    FACTION_FRIENDLY = 7,
};

enum eSays
{
    TEXT_SECOND_TRIAL_1 = 0,
    TEXT_SECOND_TRIAL_2 = 1,
    TEXT_SECOND_TRIAL_3 = 2,
    TEXT_SECOND_TRIAL_4 = 3,
};

enum eSpells
{
    SPELL_FLASH_OF_LIGHT     = 19939,
    SPELL_SEAL_OF_JUSTICE    = 20164,
    SPELL_JUDGEMENT_OF_LIGHT = 20271,
    SPELL_SEAL_OF_COMMAND    = 20375,
};

struct Locations
{
    float x, y, z, o;
};

static Locations SpawnPosition[] =
{
    {5.3f, -11.8f, 0.361f, 4.2f},
    {11.2f, -29.17f, 0.361f, 2.7f},
    {-5.7f, -34.85f, 0.361f, 1.09f},
    {-11.9f, -18, 0.361f, 5.87f}
};

// 15402
struct npc_apprentice_mirveda : public ScriptedAI
{
    npc_apprentice_mirveda(Creature* creature) : ScriptedAI(creature) { }

    uint32 KillCount;
    ObjectGuid PlayerGUID;

    void Reset() override
    {
        KillCount = 0;
        PlayerGUID = ObjectGuid::Empty;
        summons.DespawnAll();
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_UNEXPECTED_RESULT)
        {
            PlayerGUID = player->GetGUID();

            me->SummonCreature(NPC_GHARZUL, 8745, -7134.32f, 35.22f, 0, TEMPSUMMON_CORPSE_DESPAWN, 4000);
            me->SummonCreature(NPC_ANGERSHADE, 8745, -7134.32f, 35.22f, 0, TEMPSUMMON_CORPSE_DESPAWN, 4000);
            me->SummonCreature(NPC_ANGERSHADE, 8745, -7134.32f, 35.22f, 0, TEMPSUMMON_CORPSE_DESPAWN, 4000);
        }
    }

    void EnterCombat(Unit* /*who*/) override { }

    void JustSummoned(Creature* summoned) override
    {
        summoned->AI()->AttackStart(me);
        summons.Summon(summoned);
    }

    void SummonedCreatureDespawn(Creature* summoned) override
    {
        summons.Despawn(summoned);

        if (++KillCount >= 3 && !PlayerGUID.IsEmpty())
            if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                player->CompleteQuest(QUEST_UNEXPECTED_RESULT);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (!PlayerGUID.IsEmpty())
            if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                player->FailQuest(QUEST_UNEXPECTED_RESULT);
    }
};

/*######
## npc_infused_crystal
######*/

enum InfusedCrystal
{
    // Quest
    QUEST_POWERING_OUR_DEFENSES     = 8490,

    // Says
    EMOTE                           = 0,

    // Creatures
    NPC_ENRAGED_WRAITH              = 17086
};

struct Location
{
    float x, y, z;
};

static Location SpawnLocations[] =
{
    {8270.68f, -7188.53f, 139.619f},
    {8284.27f, -7187.78f, 139.603f},
    {8297.43f, -7193.53f, 139.603f},
    {8303.5f,  -7201.96f, 139.577f},
    {8273.22f, -7241.82f, 139.382f},
    {8254.89f, -7222.12f, 139.603f},
    {8278.51f, -7242.13f, 139.162f},
    {8267.97f, -7239.17f, 139.517f}
};

// 16364
struct npc_infused_crystal : public ScriptedAI
{
    npc_infused_crystal(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
    }

    uint32 EndTimer;
    uint32 WaveTimer;
    bool Completed;
    bool Progress;
    ObjectGuid PlayerGUID;

    void Reset() override
    {
        EndTimer = 0;
        Completed = false;
        Progress = false;
        PlayerGUID = ObjectGuid::Empty;
        WaveTimer = 0;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!Progress && who->IsPlayer() && me->IsWithinDistInMap(who, 10.0f))
        {
            if (who->ToPlayer()->GetQuestStatus(QUEST_POWERING_OUR_DEFENSES) == QUEST_STATUS_INCOMPLETE)
            {
                PlayerGUID = who->GetGUID();
                WaveTimer = 1000;
                EndTimer = 60000;
                Progress = true;
            }
        }
    }

    void JustSummoned(Creature* summoned) override
    {
        summoned->AI()->AttackStart(me);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (!PlayerGUID.IsEmpty() && !Completed)
            if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                player->FailQuest(QUEST_POWERING_OUR_DEFENSES);
    }

    void UpdateAI(uint32 diff) override
    {
        if (EndTimer < diff && Progress)
        {
            Talk(EMOTE);
            Completed = true;
            if (!PlayerGUID.IsEmpty())
                if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                    player->CompleteQuest(QUEST_POWERING_OUR_DEFENSES);

            me->DisappearAndDie();

        } else EndTimer -= diff;

        if (WaveTimer < diff && !Completed && Progress)
        {
            for (uint8 i = 0; i < 3; ++i)
            {
                uint32 randLocation = urand(0, 7);
                me->SummonCreature(NPC_ENRAGED_WRAITH, SpawnLocations[randLocation].x, SpawnLocations[randLocation].y, SpawnLocations[randLocation].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
            }

            WaveTimer = 30000;
        } else WaveTimer -= diff;
    }
};


static uint32 PaladinEntry[] = { CHAMPION_BLOODWRATH, CHAMPION_LIGHTREND, CHAMPION_SWIFTBLADE, CHAMPION_SUNSTRIKER };

/*######
## npc_second_trial_paladin
######*/

class npc_second_trial_paladin : public CreatureScript
{
public:
    npc_second_trial_paladin() : CreatureScript("npc_second_trial_paladin") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_secondTrialAI(creature);
    }

    struct npc_secondTrialAI : public ScriptedAI
    {
        npc_secondTrialAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 timer;
        uint8  questPhase;
        ObjectGuid summonerGuid;

        bool spellFlashLight;
        bool spellJustice;
        bool spellJudLight;
        bool spellCommand;

        uint32 timerFlashLight;
        uint32 timerJustice;
        uint32 timerJudLight;
        uint32 timerCommand;

        void Reset() override
        {
            timer = 2000;
            questPhase = 0;
            summonerGuid.Clear();

            me->SetStandState(UNIT_STAND_STATE_KNEEL);
            me->SetFaction(FACTION_FRIENDLY);

            spellFlashLight = false;
            spellJustice = false;
            spellJudLight = false;
            spellCommand = false;

            switch (me->GetEntry())
            {
            case CHAMPION_BLOODWRATH:
                spellFlashLight = true;
                timerFlashLight = 3225;
                break;
            case CHAMPION_LIGHTREND:
                spellJustice = true;
                timerJustice = 500;
                break;
            case CHAMPION_SWIFTBLADE:
                spellJudLight = false;  // Misses Script Effect // http://www.wowhead.com/?spell=20271
                timerJudLight = 500;
                break;
            case CHAMPION_SUNSTRIKER:
                spellFlashLight = true;
                spellJudLight = false;  // Misses Script Effect // http://www.wowhead.com/?spell=20271
                spellCommand = false;  // Misses Dummy // http://www.wowhead.com/?spell=20375
                timerFlashLight = 3225;
                timerJudLight = 500;
                timerCommand = 1500;
                break;
            }
        }

        void EnterCombat(Unit* /*who*/) override {}

        void UpdateAI(uint32 diff) override
        {
            if (questPhase == 1)
            {
                if (timer <= diff)
                {
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    me->SetFaction(FACTION_HOSTILE);
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
                    DoCast(me, SPELL_FLASH_OF_LIGHT, false);
                    timerFlashLight = 3225 + rand() % 3225;
                }
                else
                    timerFlashLight -= diff;
            }

            if (spellJustice)
            {
                if (timerJustice <= diff)
                {
                    DoCast(me, SPELL_SEAL_OF_JUSTICE, false);
                    timerJustice = urand(10000, 20000);
                }
                else
                    timerJustice -= diff;
            }

            if (spellJudLight)
            {
                if (timerJudLight <= diff)
                {
                    DoCast(me, SPELL_JUDGEMENT_OF_LIGHT, false);
                    timerJudLight = urand(10000, 20000);
                }
                else
                    timerJudLight -= diff;
            }

            if (spellCommand)
            {
                if (timerCommand <= diff)
                {
                    DoCast(me, SPELL_SEAL_OF_COMMAND, false);
                    timerCommand = urand(20000, 40000);
                }
                else
                    timerCommand -= diff;
            }

            DoMeleeAttackIfReady();
        }

        void Activate(ObjectGuid summonerguid)
        {
            questPhase = 1;
            summonerGuid = summonerguid;
        }

       // void KilledUnit(Unit* Killed) override
     //   {
           // if (Killed->IsPlayer())
               // if (CAST_PLR(Killed)->GetQuestStatus(QUEST_SECOND_TRIAL) == QUEST_STATUS_INCOMPLETE)
                  //  CAST_PLR(Killed)->FailQuest(QUEST_SECOND_TRIAL);
      //  }

        void JustDied(Unit* killer);
    };
};

/*######
## npc_second_trial_controller
######*/

class npc_second_trial_controller : public CreatureScript
{
public:
    npc_second_trial_controller() : CreatureScript("npc_second_trial_controller") {}

    bool OnQuestAccept(Player* /*player*/, Creature* creature, Quest const* quest) override
    {
        // One Player exclusive quest, wait for user go activation
        if (quest->GetQuestId() == QUEST_SECOND_TRIAL)
            CAST_AI(npc_second_trial_controller::master_kelerun_bloodmournAI, creature->AI())->questPhase = 1;

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        // quest only available if not already started
        // Quest_template flag is set to : QUEST_FLAGS_EVENT
        // Escort quests or any other event-driven quests. If player in party, all players that can accept this quest will receive confirmation box to accept quest.
        // !not sure if this really works!

        if (CAST_AI(npc_second_trial_controller::master_kelerun_bloodmournAI, creature->AI())->questPhase == 0)
        {
            player->PrepareQuestMenu(creature->GetGUID());
        }

        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new master_kelerun_bloodmournAI(creature);
    }

    struct master_kelerun_bloodmournAI : public ScriptedAI
    {
        master_kelerun_bloodmournAI(Creature* creature) : ScriptedAI(creature) {}

        uint8  questPhase;
        uint8  paladinPhase;
        uint32 timer;

        ObjectGuid paladinGuid[4];

        void Reset() override
        {
            questPhase = 0;
            timer = 60000;
            paladinPhase = 0;
            for (uint8 i = 0; i < 4; ++i)
                paladinGuid[i].Clear();
        }

        void EnterCombat(Unit* /*who*/) override {}

        void UpdateAI(uint32 diff) override
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
                    if (Creature* paladinSpawn = ObjectAccessor::GetCreature((*me), paladinGuid[paladinPhase]))
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

        void SummonedCreatureDespawn(Creature* /*c*/) override {}
    };
};

void npc_second_trial_paladin::npc_secondTrialAI::JustDied(Unit* Killer)
{
    if (Killer->IsPlayer())
    {
        if (Creature* summoner = ObjectAccessor::GetCreature((*me), summonerGuid))
            CAST_AI(npc_second_trial_controller::master_kelerun_bloodmournAI, summoner->AI())->SecondTrialKill();

        // last kill quest complete for group
        if (me->GetEntry() == CHAMPION_SUNSTRIKER)
        {
            if (Killer->IsPlayer())
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
    go_second_trial() : GameObjectScript("go_second_trial") {}

    bool OnGossipHello(Player* /*player*/, GameObject* go) override
    {
        // find spawn :: master_kelerun_bloodmourn
        if (Creature* creature = go->FindNearestCreature(MASTER_KELERUN_BLOODMOURN, 30.0f))
            CAST_AI(npc_second_trial_controller::master_kelerun_bloodmournAI, creature->AI())->StartEvent();

        return true;
    }
};

void AddSC_eversong_woods()
{
    RegisterCreatureAI(npc_apprentice_mirveda);
    RegisterCreatureAI(npc_infused_crystal);
    new go_second_trial();
    new npc_second_trial_controller();
    new npc_second_trial_paladin();
}
