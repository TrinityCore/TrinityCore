/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
SDName: Blades_Edge_Mountains
SD%Complete: 90
SDComment: Quest support: 10503, 10504, 10556, 10594, 10609, 10821. Ogri'la->Skettis Flight. (npc_daranelle needs bit more work before consider complete)
SDCategory: Blade's Edge Mountains
EndScriptData */

/* ContentData
npc_bloodmaul_brutebane
npc_bloodmaul_brute
npc_nether_drake
npc_daranelle
go_legion_obelisk
go_thunderspike
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Cell.h"
#include "CellImpl.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"

/*######
## npc_bloodmaul_brutebane
######*/

enum Bloodmaul
{
    NPC_OGRE_BRUTE                              = 19995,
    NPC_QUEST_CREDIT                            = 21241,
    GO_KEG                                      = 184315,
    QUEST_GETTING_THE_BLADESPIRE_TANKED         = 10512,
    QUEST_BLADESPIRE_KEGGER                     = 10545
};

class npc_bloodmaul_brutebane : public CreatureScript
{
public:
    npc_bloodmaul_brutebane() : CreatureScript("npc_bloodmaul_brutebane") { }

    struct npc_bloodmaul_brutebaneAI : public ScriptedAI
    {
        npc_bloodmaul_brutebaneAI(Creature* creature) : ScriptedAI(creature)
        {
           if (Creature* Ogre = me->FindNearestCreature(NPC_OGRE_BRUTE, 50, true))
           {
               Ogre->SetReactState(REACT_DEFENSIVE);
               Ogre->GetMotionMaster()->MovePoint(1, me->GetPositionX()-1, me->GetPositionY()+1, me->GetPositionZ());
           }
        }

        void UpdateAI(uint32 /*diff*/) override { }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bloodmaul_brutebaneAI(creature);
    }
};

/*######
## npc_bloodmaul_brute
######*/

enum BloodmaulBrute
{
    EVENT_CLEAVE                                = 1,
    EVENT_DEBILITATING_STRIKE                   = 2,
    SAY_AGGRO                                   = 0,
    SAY_DEATH                                   = 1,
    SAY_ENRAGE                                  = 2,
    SPELL_CLEAVE                                = 15496,
    SPELL_DEBILITATING_STRIKE                   = 37577,
    SPELL_ENRAGE                                = 8599,
    QUEST_INTO_THE_SOULGRINDER                  = 11000
};

class npc_bloodmaul_brute : public CreatureScript
{
public:
    npc_bloodmaul_brute() : CreatureScript("npc_bloodmaul_brute") { }

    struct npc_bloodmaul_bruteAI : public ScriptedAI
    {
        npc_bloodmaul_bruteAI(Creature* creature) : ScriptedAI(creature)
        {
            hp30 = false;
        }

        void Reset() override
        {
            PlayerGUID.Clear();
            hp30 = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (urand (0, 100) < 35)
                Talk(SAY_AGGRO);

            events.ScheduleEvent(EVENT_CLEAVE, urand(9000,12000));
            events.ScheduleEvent(EVENT_DEBILITATING_STRIKE, 15000);
        }

        void JustDied(Unit* killer) override
        {
            if (killer->GetTypeId() == TYPEID_PLAYER)
                if (killer->ToPlayer()->GetQuestRewardStatus(QUEST_INTO_THE_SOULGRINDER))
                    Talk(SAY_DEATH);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who || (!who->IsAlive()))
                return;

            if (me->IsWithinDistInMap(who, 50.0f))
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    if (who->ToPlayer()->GetQuestStatus(QUEST_GETTING_THE_BLADESPIRE_TANKED) == QUEST_STATUS_INCOMPLETE
                        || who->ToPlayer()->GetQuestStatus(QUEST_BLADESPIRE_KEGGER) == QUEST_STATUS_INCOMPLETE)
                        PlayerGUID = who->GetGUID();
            }
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 1)
            {
                if (GameObject* Keg = me->FindNearestGameObject(GO_KEG, 20))
                    Keg->Delete();

                me->HandleEmoteCommand(7);
                me->SetReactState(REACT_AGGRESSIVE);
                me->GetMotionMaster()->MoveTargetedHome();

                Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID);
                Creature* Credit = me->FindNearestCreature(NPC_QUEST_CREDIT, 50, true);
                if (player && Credit)
                    player->KilledMonster(Credit->GetCreatureTemplate(), Credit->GetGUID());
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CLEAVE:
                        DoCast(me, SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, urand(9000,12000));
                        break;
                    case EVENT_DEBILITATING_STRIKE:
                        DoCastVictim(SPELL_DEBILITATING_STRIKE);
                        events.ScheduleEvent(EVENT_DEBILITATING_STRIKE, urand(18000,22000));
                        break;
                }
            }

            if (!hp30 && HealthBelowPct(30))
            {
                hp30 = true;
                Talk(SAY_ENRAGE);
                DoCast(me, SPELL_ENRAGE);
            }

            DoMeleeAttackIfReady();
        }

        private:
            EventMap events;
            ObjectGuid PlayerGUID;
            bool hp30;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bloodmaul_bruteAI(creature);
    }
};

/*######
## npc_nether_drake
######*/

enum Netherdrake
{
    //Used by 20021, 21817, 21820, 21821, 21823 but not existing in database
    SAY_NIHIL_1                 = 0,
    SAY_NIHIL_2                 = 1,
    SAY_NIHIL_3                 = 2,
    SAY_NIHIL_4                 = 3,
    SAY_NIHIL_INTERRUPT         = 4,

    ENTRY_WHELP                 = 20021,
    ENTRY_PROTO                 = 21821,
    ENTRY_ADOLE                 = 21817,
    ENTRY_MATUR                 = 21820,
    ENTRY_NIHIL                 = 21823,

    SPELL_T_PHASE_MODULATOR     = 37573,

    SPELL_ARCANE_BLAST          = 38881,
    SPELL_MANA_BURN             = 38884,
    SPELL_INTANGIBLE_PRESENCE   = 36513
};

class npc_nether_drake : public CreatureScript
{
public:
    npc_nether_drake() : CreatureScript("npc_nether_drake") { }

    struct npc_nether_drakeAI : public ScriptedAI
    {
        npc_nether_drakeAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            IsNihil = false;
            NihilSpeech_Timer = 3000;
            NihilSpeech_Phase = 0;

            ArcaneBlast_Timer = 7500;
            ManaBurn_Timer = 10000;
            IntangiblePresence_Timer = 15000;
        }

        bool IsNihil;
        uint32 NihilSpeech_Timer;
        uint32 NihilSpeech_Phase;

        uint32 ArcaneBlast_Timer;
        uint32 ManaBurn_Timer;
        uint32 IntangiblePresence_Timer;

        void Reset() override
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override { }

        void MoveInLineOfSight(Unit* who) override

        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            ScriptedAI::MoveInLineOfSight(who);
        }

        //in case Creature was not summoned (not expected)
        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 0)
            {
                me->setDeathState(JUST_DIED);
                me->RemoveCorpse();
                me->SetHealth(0);
            }
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_T_PHASE_MODULATOR && caster->GetTypeId() == TYPEID_PLAYER)
            {
                const uint32 entry_list[4] = {ENTRY_PROTO, ENTRY_ADOLE, ENTRY_MATUR, ENTRY_NIHIL};
                int cid = rand32() % (4 - 1);

                if (entry_list[cid] == me->GetEntry())
                    ++cid;

                //we are nihil, so say before transform
                if (me->GetEntry() == ENTRY_NIHIL)
                {
                    Talk(SAY_NIHIL_INTERRUPT);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    IsNihil = false;
                }

                if (me->UpdateEntry(entry_list[cid]))
                {
                    if (entry_list[cid] == ENTRY_NIHIL)
                    {
                        EnterEvadeMode();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        IsNihil = true;
                    }else
                        AttackStart(caster);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (IsNihil)
            {
                if (NihilSpeech_Timer <= diff)
                {
                    switch (NihilSpeech_Phase)
                    {
                        case 0:
                            Talk(SAY_NIHIL_1);
                            ++NihilSpeech_Phase;
                            break;
                        case 1:
                            Talk(SAY_NIHIL_2);
                            ++NihilSpeech_Phase;
                            break;
                        case 2:
                            Talk(SAY_NIHIL_3);
                            ++NihilSpeech_Phase;
                            break;
                        case 3:
                            Talk(SAY_NIHIL_4);
                            ++NihilSpeech_Phase;
                            break;
                        case 4:
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            //take off to location above
                            me->GetMotionMaster()->MovePoint(0, me->GetPositionX()+50.0f, me->GetPositionY(), me->GetPositionZ()+50.0f);
                            ++NihilSpeech_Phase;
                            break;
                    }
                    NihilSpeech_Timer = 5000;
                } else NihilSpeech_Timer -=diff;

                //anything below here is not interesting for Nihil, so skip it
                return;
            }

            if (!UpdateVictim())
                return;

            if (IntangiblePresence_Timer <= diff)
            {
                DoCastVictim(SPELL_INTANGIBLE_PRESENCE);
                IntangiblePresence_Timer = 15000 + rand32() % 15000;
            } else IntangiblePresence_Timer -= diff;

            if (ManaBurn_Timer <= diff)
            {
                Unit* target = me->GetVictim();
                if (target && target->getPowerType() == POWER_MANA)
                    DoCast(target, SPELL_MANA_BURN);
                ManaBurn_Timer = 8000 + rand32() % 8000;
            } else ManaBurn_Timer -= diff;

            if (ArcaneBlast_Timer <= diff)
            {
                DoCastVictim(SPELL_ARCANE_BLAST);
                ArcaneBlast_Timer = 2500 + rand32() % 5000;
            } else ArcaneBlast_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_nether_drakeAI(creature);
    }
};

/*######
## npc_daranelle
######*/

enum Daranelle
{
    SAY_SPELL_INFLUENCE       = 0,
    SPELL_LASHHAN_CHANNEL     = 36904,
    SPELL_DISPELLING_ANALYSIS = 37028
};

class npc_daranelle : public CreatureScript
{
public:
    npc_daranelle() : CreatureScript("npc_daranelle") { }

    struct npc_daranelleAI : public ScriptedAI
    {
        npc_daranelleAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override { }

        void EnterCombat(Unit* /*who*/) override { }

        void MoveInLineOfSight(Unit* who) override

        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->HasAura(SPELL_LASHHAN_CHANNEL) && me->IsWithinDistInMap(who, 10.0f))
                {
                    Talk(SAY_SPELL_INFLUENCE, who);
                    /// @todo Move the below to updateAI and run if this statement == true
                    DoCast(who, SPELL_DISPELLING_ANALYSIS, true);
                }
            }

            ScriptedAI::MoveInLineOfSight(who);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_daranelleAI(creature);
    }
};

//Support for quest: You're Fired! (10821)
bool     obelisk_one, obelisk_two, obelisk_three, obelisk_four, obelisk_five;

enum LegionObelisk
{
    GO_LEGION_OBELISK_ONE           = 185193,
    GO_LEGION_OBELISK_TWO           = 185195,
    GO_LEGION_OBELISK_THREE         = 185196,
    GO_LEGION_OBELISK_FOUR          = 185197,
    GO_LEGION_OBELISK_FIVE          = 185198,
    NPC_DOOMCRYER                   = 19963,
    QUEST_YOURE_FIRED               = 10821
};

/*######
## go_legion_obelisk
######*/

class go_legion_obelisk : public GameObjectScript
{
public:
    go_legion_obelisk() : GameObjectScript("go_legion_obelisk") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->GetQuestStatus(QUEST_YOURE_FIRED) == QUEST_STATUS_INCOMPLETE)
        {
            switch (go->GetEntry())
            {
                case GO_LEGION_OBELISK_ONE:
                      obelisk_one = true;
                     break;
                case GO_LEGION_OBELISK_TWO:
                      obelisk_two = true;
                     break;
                case GO_LEGION_OBELISK_THREE:
                      obelisk_three = true;
                     break;
                case GO_LEGION_OBELISK_FOUR:
                      obelisk_four = true;
                     break;
                case GO_LEGION_OBELISK_FIVE:
                      obelisk_five = true;
                     break;
            }

            if (obelisk_one == true && obelisk_two == true && obelisk_three == true && obelisk_four == true && obelisk_five == true)
            {
                go->SummonCreature(NPC_DOOMCRYER, 2943.40f, 4778.20f, 284.49f, 0.94f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                //reset global var
                obelisk_one = false;
                obelisk_two = false;
                obelisk_three = false;
                obelisk_four = false;
                obelisk_five = false;
            }
        }

        return true;
    }
};

/*######
## go_thunderspike
######*/

enum TheThunderspike
{
    NPC_GOR_GRIMGUT     = 21319,
    QUEST_THUNDERSPIKE  = 10526,
};

class go_thunderspike : public GameObjectScript
{
    public:
        go_thunderspike() : GameObjectScript("go_thunderspike") { }

        bool OnGossipHello(Player* player, GameObject* go) override
        {
            if (player->GetQuestStatus(QUEST_THUNDERSPIKE) == QUEST_STATUS_INCOMPLETE && !go->FindNearestCreature(NPC_GOR_GRIMGUT, 25.0f, true))
                if (Creature* gorGrimgut = go->SummonCreature(NPC_GOR_GRIMGUT, -2413.4f, 6914.48f, 25.01f, 3.67f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 300000))
                    gorGrimgut->AI()->AttackStart(player);

            return true;
        }
};

enum SimonGame
{
    NPC_SIMON_BUNNY                 = 22923,
    NPC_APEXIS_GUARDIAN             = 22275,

    GO_APEXIS_RELIC                 = 185890,
    GO_APEXIS_MONUMENT              = 185944,
    GO_AURA_BLUE                    = 185872,
    GO_AURA_GREEN                   = 185873,
    GO_AURA_RED                     = 185874,
    GO_AURA_YELLOW                  = 185875,

    GO_BLUE_CLUSTER_DISPLAY         = 7369,
    GO_GREEN_CLUSTER_DISPLAY        = 7371,
    GO_RED_CLUSTER_DISPLAY          = 7373,
    GO_YELLOW_CLUSTER_DISPLAY       = 7375,
    GO_BLUE_CLUSTER_DISPLAY_LARGE   = 7364,
    GO_GREEN_CLUSTER_DISPLAY_LARGE  = 7365,
    GO_RED_CLUSTER_DISPLAY_LARGE    = 7366,
    GO_YELLOW_CLUSTER_DISPLAY_LARGE = 7367,

    SPELL_PRE_GAME_BLUE             = 40176,
    SPELL_PRE_GAME_GREEN            = 40177,
    SPELL_PRE_GAME_RED              = 40178,
    SPELL_PRE_GAME_YELLOW           = 40179,
    SPELL_VISUAL_BLUE               = 40244,
    SPELL_VISUAL_GREEN              = 40245,
    SPELL_VISUAL_RED                = 40246,
    SPELL_VISUAL_YELLOW             = 40247,

    SOUND_BLUE                      = 11588,
    SOUND_GREEN                     = 11589,
    SOUND_RED                       = 11590,
    SOUND_YELLOW                    = 11591,
    SOUND_DISABLE_NODE              = 11758,

    SPELL_AUDIBLE_GAME_TICK         = 40391,
    SPELL_VISUAL_START_PLAYER_LEVEL = 40436,
    SPELL_VISUAL_START_AI_LEVEL     = 40387,

    SPELL_BAD_PRESS_TRIGGER         = 41241,
    SPELL_BAD_PRESS_DAMAGE          = 40065,
    SPELL_REWARD_BUFF_1             = 40310,
    SPELL_REWARD_BUFF_2             = 40311,
    SPELL_REWARD_BUFF_3             = 40312,
};

enum SimonEvents
{
    EVENT_SIMON_SETUP_PRE_GAME         = 1,
    EVENT_SIMON_PLAY_SEQUENCE          = 2,
    EVENT_SIMON_RESET_CLUSTERS         = 3,
    EVENT_SIMON_PERIODIC_PLAYER_CHECK  = 4,
    EVENT_SIMON_TOO_LONG_TIME          = 5,
    EVENT_SIMON_GAME_TICK              = 6,
    EVENT_SIMON_ROUND_FINISHED         = 7,

    ACTION_SIMON_CORRECT_FULL_SEQUENCE = 8,
    ACTION_SIMON_WRONG_SEQUENCE        = 9,
    ACTION_SIMON_ROUND_FINISHED        = 10,
};

enum SimonColors
{
    SIMON_BLUE          = 0,
    SIMON_RED           = 1,
    SIMON_GREEN         = 2,
    SIMON_YELLOW        = 3,
    SIMON_MAX_COLORS    = 4,
};

class npc_simon_bunny : public CreatureScript
{
    public:
        npc_simon_bunny() : CreatureScript("npc_simon_bunny") { }

        struct npc_simon_bunnyAI : public ScriptedAI
        {
            npc_simon_bunnyAI(Creature* creature) : ScriptedAI(creature)
            {
                large = false;
                listening = false;
                gameLevel = 0;
                fails = 0;
                gameTicks = 0;
                memset(clusterIds, 0, sizeof(clusterIds));
                zCoordCorrection = 0.f;
                searchDistance = 0.f;
            }

            bool large;
            bool listening;
            uint8 gameLevel;
            uint8 fails;
            uint8 gameTicks;
            ObjectGuid playerGUID;
            uint32 clusterIds[SIMON_MAX_COLORS];
            float zCoordCorrection;
            float searchDistance;
            EventMap _events;
            std::list<uint8> colorSequence, playableSequence, playerSequence;

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                switch (_events.ExecuteEvent())
                {
                    case EVENT_SIMON_PERIODIC_PLAYER_CHECK:
                        if (!CheckPlayer())
                            ResetNode();
                        else
                            _events.ScheduleEvent(EVENT_SIMON_PERIODIC_PLAYER_CHECK, 2000);
                        break;
                    case EVENT_SIMON_SETUP_PRE_GAME:
                        SetUpPreGame();
                        _events.CancelEvent(EVENT_SIMON_GAME_TICK);
                        _events.ScheduleEvent(EVENT_SIMON_PLAY_SEQUENCE, 1000);
                        break;
                    case EVENT_SIMON_PLAY_SEQUENCE:
                        if (!playableSequence.empty())
                        {
                            PlayNextColor();
                            _events.ScheduleEvent(EVENT_SIMON_PLAY_SEQUENCE, 1500);
                        }
                        else
                        {
                            listening = true;
                            DoCast(SPELL_VISUAL_START_PLAYER_LEVEL);
                            playerSequence.clear();
                            PrepareClusters();
                            gameTicks = 0;
                            _events.ScheduleEvent(EVENT_SIMON_GAME_TICK, 3000);
                        }
                        break;
                    case EVENT_SIMON_GAME_TICK:
                        DoCast(SPELL_AUDIBLE_GAME_TICK);

                        if (gameTicks > gameLevel)
                            _events.ScheduleEvent(EVENT_SIMON_TOO_LONG_TIME, 500);
                        else
                            _events.ScheduleEvent(EVENT_SIMON_GAME_TICK, 3000);
                        gameTicks++;
                        break;
                    case EVENT_SIMON_RESET_CLUSTERS:
                        PrepareClusters(true);
                        break;
                    case EVENT_SIMON_TOO_LONG_TIME:
                        DoAction(ACTION_SIMON_WRONG_SEQUENCE);
                        break;
                    case EVENT_SIMON_ROUND_FINISHED:
                        DoAction(ACTION_SIMON_ROUND_FINISHED);
                        break;
                }
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_SIMON_ROUND_FINISHED:
                        listening = false;
                        DoCast(SPELL_VISUAL_START_AI_LEVEL);
                        GiveRewardForLevel(gameLevel);
                        _events.CancelEventGroup(0);
                        if (gameLevel == 10)
                            ResetNode();
                        else
                            _events.ScheduleEvent(EVENT_SIMON_SETUP_PRE_GAME, 1000);
                        break;
                    case ACTION_SIMON_CORRECT_FULL_SEQUENCE:
                        gameLevel++;
                        DoAction(ACTION_SIMON_ROUND_FINISHED);
                        break;
                    case ACTION_SIMON_WRONG_SEQUENCE:
                        GivePunishment();
                        DoAction(ACTION_SIMON_ROUND_FINISHED);
                        break;
                }
            }

            // Called by color clusters script (go_simon_cluster) and used for knowing the button pressed by player
            void SetData(uint32 type, uint32 /*data*/) override
            {
                if (!listening)
                    return;

                uint8 pressedColor = SIMON_MAX_COLORS;

                if (type == clusterIds[SIMON_RED])
                    pressedColor = SIMON_RED;
                else if (type == clusterIds[SIMON_BLUE])
                    pressedColor = SIMON_BLUE;
                else if (type == clusterIds[SIMON_GREEN])
                    pressedColor = SIMON_GREEN;
                else if (type == clusterIds[SIMON_YELLOW])
                    pressedColor = SIMON_YELLOW;

                PlayColor(pressedColor);
                playerSequence.push_back(pressedColor);
                _events.ScheduleEvent(EVENT_SIMON_RESET_CLUSTERS, 500);
                CheckPlayerSequence();
            }

            // Used for getting involved player guid. Parameter id is used for defining if is a large(Monument) or small(Relic) node
            void SetGUID(ObjectGuid guid, int32 id) override
            {
                me->SetCanFly(true);

                large = id != 0;
                playerGUID = guid;
                StartGame();
            }

            /*
            Resets all variables and also find the ids of the four closests color clusters, since every simon
            node have diferent ids for clusters this is absolutely NECESSARY.
            */
            void StartGame()
            {
                listening = false;
                gameLevel = 0;
                fails = 0;
                gameTicks = 0;
                zCoordCorrection = large ? 8.0f : 2.75f;
                searchDistance = large ? 13.0f : 5.0f;
                colorSequence.clear();
                playableSequence.clear();
                playerSequence.clear();
                me->SetObjectScale(large ? 2.0f : 1.0f);

                std::list<WorldObject*> ClusterList;
                Trinity::AllWorldObjectsInRange objects(me, searchDistance);
                Trinity::WorldObjectListSearcher<Trinity::AllWorldObjectsInRange> searcher(me, ClusterList, objects);
                me->VisitNearbyObject(searchDistance, searcher);

                for (std::list<WorldObject*>::const_iterator i = ClusterList.begin(); i != ClusterList.end(); ++i)
                {
                    if (GameObject* go = (*i)->ToGameObject())
                    {
                        // We are checking for displayid because all simon nodes have 4 clusters with different entries
                        if (large)
                        {
                            switch (go->GetGOInfo()->displayId)
                            {
                                case GO_BLUE_CLUSTER_DISPLAY_LARGE:
                                    clusterIds[SIMON_BLUE] = go->GetEntry();
                                    break;

                                case GO_RED_CLUSTER_DISPLAY_LARGE:
                                    clusterIds[SIMON_RED] = go->GetEntry();
                                    break;

                                case GO_GREEN_CLUSTER_DISPLAY_LARGE:
                                    clusterIds[SIMON_GREEN] = go->GetEntry();
                                    break;

                                case GO_YELLOW_CLUSTER_DISPLAY_LARGE:
                                    clusterIds[SIMON_YELLOW] = go->GetEntry();
                                    break;
                            }
                        }
                        else
                        {
                            switch (go->GetGOInfo()->displayId)
                            {
                                case GO_BLUE_CLUSTER_DISPLAY:
                                    clusterIds[SIMON_BLUE] = go->GetEntry();
                                    break;

                                case GO_RED_CLUSTER_DISPLAY:
                                    clusterIds[SIMON_RED] = go->GetEntry();
                                    break;

                                case GO_GREEN_CLUSTER_DISPLAY:
                                    clusterIds[SIMON_GREEN] = go->GetEntry();
                                    break;

                                case GO_YELLOW_CLUSTER_DISPLAY:
                                    clusterIds[SIMON_YELLOW] = go->GetEntry();
                                    break;
                            }
                        }
                    }
                }

                _events.Reset();
                _events.ScheduleEvent(EVENT_SIMON_ROUND_FINISHED, 1000);
                _events.ScheduleEvent(EVENT_SIMON_PERIODIC_PLAYER_CHECK, 2000);

                if (GameObject* relic = me->FindNearestGameObject(large ? GO_APEXIS_MONUMENT : GO_APEXIS_RELIC, searchDistance))
                    relic->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            }

            // Called when despawning the bunny. Sets all the node GOs to their default states.
            void ResetNode()
            {
                DoPlaySoundToSet(me, SOUND_DISABLE_NODE);

                for (uint32 clusterId = SIMON_BLUE; clusterId < SIMON_MAX_COLORS; clusterId++)
                    if (GameObject* cluster = me->FindNearestGameObject(clusterIds[clusterId], searchDistance))
                        cluster->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                for (uint32 auraId = GO_AURA_BLUE; auraId <= GO_AURA_YELLOW; auraId++)
                    if (GameObject* auraGo = me->FindNearestGameObject(auraId, searchDistance))
                        auraGo->RemoveFromWorld();

                if (GameObject* relic = me->FindNearestGameObject(large ? GO_APEXIS_MONUMENT : GO_APEXIS_RELIC, searchDistance))
                    relic->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                me->DespawnOrUnsummon(1000);
            }

            /*
            Called on every button click of player. Adds the clicked color to the player created sequence and
            checks if it corresponds to the AI created sequence. If so, incremente gameLevel and start a new
            round, if not, give punishment and restart current level.
            */
            void CheckPlayerSequence()
            {
                bool correct = true;
                if (playerSequence.size() <= colorSequence.size())
                    for (std::list<uint8>::const_iterator i = playerSequence.begin(), j = colorSequence.begin(); i != playerSequence.end(); ++i, ++j)
                        if ((*i) != (*j))
                            correct = false;

                if (correct && (playerSequence.size() == colorSequence.size()))
                    DoAction(ACTION_SIMON_CORRECT_FULL_SEQUENCE);
                else if (!correct)
                    DoAction(ACTION_SIMON_WRONG_SEQUENCE);
            }

            /*
            Generates a random sequence of colors depending on the gameLevel. We also copy this sequence to
            the playableSequence wich will be used when playing the sequence to the player.
            */
            void GenerateColorSequence()
            {
                colorSequence.clear();
                for (uint8 i = 0; i <= gameLevel; i++)
                    colorSequence.push_back(RAND(SIMON_BLUE, SIMON_RED, SIMON_GREEN, SIMON_YELLOW));

                for (std::list<uint8>::const_iterator i = colorSequence.begin(); i != colorSequence.end(); ++i)
                    playableSequence.push_back(*i);
            }


            // Remove any existant glowing auras over clusters and set clusters ready for interating with them.
            void PrepareClusters(bool clustersOnly = false)
            {
                for (uint32 clusterId = SIMON_BLUE; clusterId < SIMON_MAX_COLORS; clusterId++)
                    if (GameObject* cluster = me->FindNearestGameObject(clusterIds[clusterId], searchDistance))
                        cluster->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                if (clustersOnly)
                    return;

                for (uint32 auraId = GO_AURA_BLUE; auraId <= GO_AURA_YELLOW; auraId++)
                    if (GameObject* auraGo = me->FindNearestGameObject(auraId, searchDistance))
                        auraGo->RemoveFromWorld();
            }

            /*
            Called when AI is playing the sequence for player. We cast the visual spell and then remove the
            cast color from the casting sequence.
            */
            void PlayNextColor()
            {
                PlayColor(*playableSequence.begin());
                playableSequence.erase(playableSequence.begin());
            }

            // Casts a spell and plays a sound depending on parameter color.
            void PlayColor(uint8 color)
            {
                switch (color)
                {
                    case SIMON_BLUE:
                        DoCast(SPELL_VISUAL_BLUE);
                        DoPlaySoundToSet(me, SOUND_BLUE);
                        break;
                    case SIMON_GREEN:
                        DoCast(SPELL_VISUAL_GREEN);
                        DoPlaySoundToSet(me, SOUND_GREEN);
                        break;
                    case SIMON_RED:
                        DoCast(SPELL_VISUAL_RED);
                        DoPlaySoundToSet(me, SOUND_RED);
                        break;
                    case SIMON_YELLOW:
                        DoCast(SPELL_VISUAL_YELLOW);
                        DoPlaySoundToSet(me, SOUND_YELLOW);
                        break;
                }
            }

            /*
            Creates the transparent glowing auras on every cluster of this node.
            After calling this function bunny is teleported to the center of the node.
            */
            void SetUpPreGame()
            {
                for (uint32 clusterId = SIMON_BLUE; clusterId < SIMON_MAX_COLORS; clusterId++)
                {
                    if (GameObject* cluster = me->FindNearestGameObject(clusterIds[clusterId], 2.0f*searchDistance))
                    {
                        cluster->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                        // break since we don't need glowing auras for large clusters
                        if (large)
                            break;

                        float x, y, z, o;
                        cluster->GetPosition(x, y, z, o);
                        me->NearTeleportTo(x, y, z, o);

                        uint32 preGameSpellId;
                        if (cluster->GetEntry() == clusterIds[SIMON_RED])
                            preGameSpellId = SPELL_PRE_GAME_RED;
                        else if (cluster->GetEntry() == clusterIds[SIMON_BLUE])
                            preGameSpellId = SPELL_PRE_GAME_BLUE;
                        else if (cluster->GetEntry() == clusterIds[SIMON_GREEN])
                            preGameSpellId = SPELL_PRE_GAME_GREEN;
                        else if (cluster->GetEntry() == clusterIds[SIMON_YELLOW])
                            preGameSpellId = SPELL_PRE_GAME_YELLOW;
                        else break;

                        me->CastSpell(cluster, preGameSpellId, true);
                    }
                }

                if (GameObject* relic = me->FindNearestGameObject(large ? GO_APEXIS_MONUMENT : GO_APEXIS_RELIC, searchDistance))
                {
                    float x, y, z, o;
                    relic->GetPosition(x, y, z, o);
                    me->NearTeleportTo(x, y, z + zCoordCorrection, o);
                }

                GenerateColorSequence();
            }

            // Handles the spell rewards. The spells also have the QuestCompleteEffect, so quests credits are working.
            void GiveRewardForLevel(uint8 level)
            {
                uint32 rewSpell = 0;
                switch (level)
                {
                    case 6:
                        if (large)
                            GivePunishment();
                        else
                            rewSpell = SPELL_REWARD_BUFF_1;
                        break;
                    case 8:
                        rewSpell = SPELL_REWARD_BUFF_2;
                        break;
                    case 10:
                        rewSpell = SPELL_REWARD_BUFF_3;
                        break;
                }

                if (rewSpell)
                    if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                        DoCast(player, rewSpell, true);
            }

            /*
            Depending on the number of failed pushes for player the damage of the spell scales, so we first
            cast the spell on the target that hits for 50 and shows the visual and then forces the player
            to cast the damaging spell on it self with the modified basepoints.
            4 fails = death.
            On large nodes punishment and reward are the same, summoning the Apexis Guardian.
            */
            void GivePunishment()
            {
                if (large)
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                        if (Creature* guardian = me->SummonCreature(NPC_APEXIS_GUARDIAN, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() - zCoordCorrection, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 20000))
                            guardian->AI()->AttackStart(player);

                    ResetNode();
                }
                else
                {
                    fails++;

                    if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                        DoCast(player, SPELL_BAD_PRESS_TRIGGER, true);

                    if (fails >= 4)
                        ResetNode();
                }
            }

            void SpellHitTarget(Unit* target, const SpellInfo* spell) override
            {
                // Cast SPELL_BAD_PRESS_DAMAGE with scaled basepoints when the visual hits the target.
                // Need Fix: When SPELL_BAD_PRESS_TRIGGER hits target it triggers spell SPELL_BAD_PRESS_DAMAGE by itself
                // so player gets damage equal to calculated damage  dbc basepoints for SPELL_BAD_PRESS_DAMAGE (~50)
                if (spell->Id == SPELL_BAD_PRESS_TRIGGER)
                {
                    int32 bp = (int32)((float)(fails)*0.33f*target->GetMaxHealth());
                    target->CastCustomSpell(target, SPELL_BAD_PRESS_DAMAGE, &bp, NULL, NULL, true);
                }
            }

            // Checks if player has already die or has get too far from the current node
            bool CheckPlayer()
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                {
                    if (player->isDead())
                        return false;
                    if (player->GetDistance2d(me) >= 2.0f*searchDistance)
                    {
                        GivePunishment();
                        return false;
                    }
                }
                else
                    return false;

                return true;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_simon_bunnyAI(creature);
        }
};

class go_simon_cluster : public GameObjectScript
{
    public:
        go_simon_cluster() : GameObjectScript("go_simon_cluster") { }

        bool OnGossipHello(Player* player, GameObject* go) override
        {
            if (Creature* bunny = go->FindNearestCreature(NPC_SIMON_BUNNY, 12.0f, true))
                bunny->AI()->SetData(go->GetEntry(), 0);

            player->CastSpell(player, go->GetGOInfo()->goober.spellId, true);
            go->AddUse();
            return true;
        }
};

enum ApexisRelic
{
    QUEST_CRYSTALS            = 11025,
    GOSSIP_TEXT_ID            = 10948,

    ITEM_APEXIS_SHARD         = 32569,
    SPELL_TAKE_REAGENTS_SOLO  = 41145,
    SPELL_TAKE_REAGENTS_GROUP = 41146,
};

class go_apexis_relic : public GameObjectScript
{
    public:
        go_apexis_relic() : GameObjectScript("go_apexis_relic") { }

        bool OnGossipHello(Player* player, GameObject* go) override
        {
            player->PrepareGossipMenu(go, go->GetGOInfo()->questgiver.gossipID);
            player->SendPreparedGossip(go);
            return true;
        }

        bool OnGossipSelect(Player* player, GameObject* go, uint32 /*sender*/, uint32 /*action*/) override
        {
            player->CLOSE_GOSSIP_MENU();

            bool large = (go->GetEntry() == GO_APEXIS_MONUMENT);
            if (player->HasItemCount(ITEM_APEXIS_SHARD, large ? 35 : 1))
            {
                player->CastSpell(player, large ? SPELL_TAKE_REAGENTS_GROUP : SPELL_TAKE_REAGENTS_SOLO, false);

                if (Creature* bunny = player->SummonCreature(NPC_SIMON_BUNNY, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ()))
                    bunny->AI()->SetGUID(player->GetGUID(), large);
            }

            return true;
        }
};

/*######
## npc_oscillating_frequency_scanner_master_bunny used for quest 10594 "Gauging the Resonant Frequency"
######*/

enum ScannerMasterBunny
{
    NPC_OSCILLATING_FREQUENCY_SCANNER_TOP_BUNNY = 21759,
    GO_OSCILLATING_FREQUENCY_SCANNER            = 184926,
    SPELL_OSCILLATION_FIELD                     = 37408,
    QUEST_GAUGING_THE_RESONANT_FREQUENCY        = 10594
};

class npc_oscillating_frequency_scanner_master_bunny : public CreatureScript
{
public:
    npc_oscillating_frequency_scanner_master_bunny() : CreatureScript("npc_oscillating_frequency_scanner_master_bunny") { }

    struct npc_oscillating_frequency_scanner_master_bunnyAI : public ScriptedAI
    {
        npc_oscillating_frequency_scanner_master_bunnyAI(Creature* creature) : ScriptedAI(creature)
        {
            timer = 500;
        }

        void Reset() override
        {
            if (GetClosestCreatureWithEntry(me, NPC_OSCILLATING_FREQUENCY_SCANNER_TOP_BUNNY, 25.0f))
                me->DespawnOrUnsummon();
            else
            {
                // Spell 37392 does not exist in dbc, manually spawning
                me->SummonCreature(NPC_OSCILLATING_FREQUENCY_SCANNER_TOP_BUNNY, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 0.5f, me->GetOrientation(), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 50000);
                me->SummonGameObject(GO_OSCILLATING_FREQUENCY_SCANNER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), 0, 0, 0, 0, 50);
                me->DespawnOrUnsummon(50000);
            }

            timer = 500;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (summoner->isType(TYPEMASK_PLAYER))
                playerGuid = summoner->GetGUID();
        }

        void UpdateAI(uint32 diff) override
        {
            if (timer <= diff)
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, playerGuid))
                    DoCast(player, SPELL_OSCILLATION_FIELD);

                timer = 3000;
            }
            else
                timer -= diff;
        }

        private:
            ObjectGuid playerGuid;
            uint32 timer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_oscillating_frequency_scanner_master_bunnyAI(creature);
    }
};

class spell_oscillating_field : public SpellScriptLoader
{
    public:
        spell_oscillating_field() : SpellScriptLoader("spell_oscillating_field") { }

        class spell_oscillating_field_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_oscillating_field_SpellScript);

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                if (Player* player = GetHitPlayer())
                    if (player->GetAuraCount(SPELL_OSCILLATION_FIELD) == 5 && player->GetQuestStatus(QUEST_GAUGING_THE_RESONANT_FREQUENCY) == QUEST_STATUS_INCOMPLETE)
                        player->CompleteQuest(QUEST_GAUGING_THE_RESONANT_FREQUENCY);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_oscillating_field_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_oscillating_field_SpellScript();
        }
};

void AddSC_blades_edge_mountains()
{
    new npc_bloodmaul_brutebane();
    new npc_bloodmaul_brute();
    new npc_nether_drake();
    new npc_daranelle();
    new go_legion_obelisk();
    new go_thunderspike();
    new npc_simon_bunny();
    new go_simon_cluster();
    new go_apexis_relic();
    new npc_oscillating_frequency_scanner_master_bunny();
    new spell_oscillating_field();
}
