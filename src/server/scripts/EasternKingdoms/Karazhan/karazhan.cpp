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

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "karazhan.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum BarnesTexts
{
    SAY_BEGIN                        = 0,
    SAY_HOOD_1                       = 1,
    SAY_HOOD_2                       = 2,
    SAY_HOOD_3                       = 3,
    SAY_HOOD_4                       = 4,
    SAY_OZ_1                         = 5,
    SAY_OZ_2                         = 6,
    SAY_OZ_3                         = 7,
    SAY_OZ_4                         = 8,
    SAY_RAJ_1                        = 9,
    SAY_RAJ_2                        = 10,
    SAY_RAJ_3                        = 11,
    SAY_RAJ_4                        = 12
};

enum BarnesMisc
{
    SPELL_TUXEDO                     = 32616,

    GOSSIP_MENU_MAIN                 = 7421,
    GOSSIP_MENU_MAIN_2               = 7422,

    GOSSIP_TEXT_MOROES_ALIVE         = 8969,
    GOSSIP_TEXT_MAIN_1               = 8970,
    GOSSIP_TEXT_MAIN_2               = 8971,
    GOSSIP_TEXT_FAIL_HOOD            = 8975,
    GOSSIP_TEXT_FAIL_OZ              = 8981,
    GOSSIP_TEXT_FAIL_RAJ             = 8982,
    GOSSIP_TEXT_DONE                 = 10471,

    GOSSIP_OPTION_MAIN               = 0,
    GOSSIP_OPTION_FAIL_HOOD          = 1,
    GOSSIP_OPTION_FAIL_OZ            = 2,
    GOSSIP_OPTION_FAIL_RAJ           = 3,

    PATH_ANNOUNCE_1                  = 1358230,
    PATH_ANNOUNCE_2                  = 1358231,

    ACTION_START_ANNOUNCE            = 0,

    NPC_CROWD_HELPER                 = 18654
};

enum BarnesSounds
{
    SOUND_APPLAUSE                   = 9332,      // NYI
    SOUND_AMBIENCE_HOOD              = 9357,
    SOUND_AMBIENCE_OZ                = 9358,
    SOUND_AMBIENCE_RAJ               = 9359
};

enum BarnesCreatureSpawnGroups
{
    SPAWN_GROUP_SPOTLIGHT            = 386,
    SPAWN_GROUP_GRANDMOTHER          = 387,
    SPAWN_GROUP_TINHEAD              = 388,
    SPAWN_GROUP_STRAWMAN             = 389,
    SPAWN_GROUP_ROAR                 = 390,
    SPAWN_GROUP_DOROTHEE             = 391,
    SPAWN_GROUP_JULIANNE             = 392
};

enum BarnesObjectSpawnGroups
{
    SPAWN_GROUP_DECORATIONS_HOOD     = 396,
    SPAWN_GROUP_DECORATIONS_OZ       = 397,
    SPAWN_GROUP_DECORATIONS_RAJ      = 398
};

static constexpr const char* GOSSIP_OPTION_GM_1 = "[GM] Change event to EVENT_OZ";
static constexpr const char* GOSSIP_OPTION_GM_2 = "[GM] Change event to EVENT_HOOD";
static constexpr const char* GOSSIP_OPTION_GM_3 = "[GM] Change event to EVENT_RAJ";

// 16812 - Barnes
struct npc_barnes : public ScriptedAI
{
    npc_barnes(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_ANNOUNCE:
                _scheduler.Schedule(0s, [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            Talk(SAY_BEGIN);
                            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                            _instance->SetBossState(DATA_OPERA_PERFORMANCE, IN_PROGRESS);
                            _instance->HandleGameObject(ObjectGuid::Empty, true, _instance->GetGameObject(DATA_GO_STAGE_DOOR_LEFT));
                            task.Repeat(3400ms);
                            break;
                        case 1:
                            DoCastSelf(SPELL_TUXEDO);
                            me->GetMotionMaster()->MovePath(PATH_ANNOUNCE_1, false);
                            break;
                        default:
                            break;
                    }
                });
                break;
            case ACTION_OPERA_FINISHED:
                me->RemoveAurasDueToSpell(SPELL_TUXEDO);
                me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                break;
            default:
                break;
        }
    }

    void WaypointPathEnded(uint32 /*waypointId*/, uint32 pathId) override
    {
        if (pathId == PATH_ANNOUNCE_1)
        {
            switch (_instance->GetData(DATA_OPERA_VARIATION))
            {
                case EVENT_HOOD:
                    _scheduler.Schedule(0s, [this](TaskContext task)
                    {
                        switch (task.GetRepeatCounter())
                        {
                            case 0:
                                me->SetFacingTo(4.590215682983398437f);
                                me->SetEmoteState(EMOTE_STATE_TALK);
                                Talk(SAY_HOOD_1);

                                if (Creature* helper = me->FindNearestCreature(NPC_CROWD_HELPER, 100.0f))
                                    helper->PlayDirectSound(SOUND_AMBIENCE_HOOD);

                                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_SPOTLIGHT, true);

                                task.Repeat(7s);
                                break;
                            case 1:
                                Talk(SAY_HOOD_2);
                                task.Repeat(7s);
                                break;
                            case 2:
                                me->SetEmoteState(EMOTE_ONESHOT_NONE);
                                task.Repeat(3600ms);
                                break;
                            case 3:
                                Talk(SAY_HOOD_3);
                                me->SetEmoteState(EMOTE_STATE_TALK);
                                task.Repeat(10s);
                                break;
                            case 4:
                                Talk(SAY_HOOD_4);
                                task.Repeat(10s);
                                break;
                            case 5:
                                me->SetEmoteState(EMOTE_ONESHOT_NONE);
                                task.Repeat(1200ms);
                                break;
                            case 6:
                                me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                                task.Repeat(3600ms);
                                break;
                            case 7:
                                me->GetMotionMaster()->MovePath(PATH_ANNOUNCE_2, false);
                                me->GetMap()->SpawnGroupDespawn(SPAWN_GROUP_SPOTLIGHT);
                                break;
                            default:
                                break;
                        }
                    });
                    break;
                case EVENT_OZ:
                    _scheduler.Schedule(0s, [this](TaskContext task)
                    {
                        switch (task.GetRepeatCounter())
                        {
                            case 0:
                                me->SetFacingTo(4.590215682983398437f);
                                me->SetEmoteState(EMOTE_STATE_TALK);
                                Talk(SAY_OZ_1);

                                if (Creature* helper = me->FindNearestCreature(NPC_CROWD_HELPER, 100.0f))
                                    helper->PlayDirectSound(SOUND_AMBIENCE_OZ);

                                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_SPOTLIGHT, true);

                                task.Repeat(7s);
                                break;
                            case 1:
                                Talk(SAY_OZ_2);
                                task.Repeat(15s);
                                break;
                            case 2:
                                me->SetEmoteState(EMOTE_ONESHOT_NONE);
                                task.Repeat(3600ms);
                                break;
                            case 3:
                                Talk(SAY_OZ_3);
                                me->SetEmoteState(EMOTE_STATE_TALK);
                                task.Repeat(6s);
                                break;
                            case 4:
                                me->SetEmoteState(EMOTE_ONESHOT_NONE);
                                task.Repeat(3600ms);
                                break;
                            case 5:
                                Talk(SAY_OZ_4);
                                me->SetEmoteState(EMOTE_STATE_TALK);
                                task.Repeat(7s);
                                break;
                            case 6:
                                me->SetEmoteState(EMOTE_ONESHOT_NONE);
                                task.Repeat(1200ms);
                                break;
                            case 7:
                                me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                                task.Repeat(3600ms);
                                break;
                            case 8:
                                me->GetMotionMaster()->MovePath(PATH_ANNOUNCE_2, false);
                                me->GetMap()->SpawnGroupDespawn(SPAWN_GROUP_SPOTLIGHT);
                                break;
                            default:
                                break;
                        }
                    });
                    break;
                case EVENT_RAJ:
                    _scheduler.Schedule(0s, [this](TaskContext task)
                    {
                        switch (task.GetRepeatCounter())
                        {
                            case 0:
                                me->SetFacingTo(4.590215682983398437f);
                                me->SetEmoteState(EMOTE_STATE_TALK);
                                Talk(SAY_RAJ_1);

                                if (Creature* helper = me->FindNearestCreature(NPC_CROWD_HELPER, 100.0f))
                                    helper->PlayDirectSound(SOUND_AMBIENCE_RAJ);

                                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_SPOTLIGHT, true);

                                task.Repeat(6s);
                                break;
                            case 1:
                                Talk(SAY_RAJ_2);
                                task.Repeat(4800ms);
                                break;
                            case 2:
                                me->SetEmoteState(EMOTE_ONESHOT_NONE);
                                task.Repeat(3600ms);
                                break;
                            case 3:
                                Talk(SAY_RAJ_3);
                                me->SetEmoteState(EMOTE_STATE_TALK);
                                task.Repeat(11s);
                                break;
                            case 4:
                                me->SetEmoteState(EMOTE_ONESHOT_NONE);
                                task.Repeat(3600ms);
                                break;
                            case 5:
                                Talk(SAY_RAJ_4);
                                me->SetEmoteState(EMOTE_STATE_TALK);
                                task.Repeat(8400ms);
                                break;
                            case 6:
                                me->SetEmoteState(EMOTE_ONESHOT_NONE);
                                task.Repeat(1200ms);
                                break;
                            case 7:
                                me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                                task.Repeat(3600ms);
                                break;
                            case 8:
                                me->GetMotionMaster()->MovePath(PATH_ANNOUNCE_2, false);
                                me->GetMap()->SpawnGroupDespawn(SPAWN_GROUP_SPOTLIGHT);
                                break;
                            default:
                                break;
                        }
                    });
                    break;
                default:
                    break;
            }
        }
        else if (pathId == PATH_ANNOUNCE_2)
        {
            switch (_instance->GetData(DATA_OPERA_VARIATION))
            {
                case EVENT_HOOD:
                    _scheduler.Schedule(0s, [this](TaskContext task)
                    {
                        switch (task.GetRepeatCounter())
                        {
                            case 0:
                                me->SetFacingTo(1.448623299598693847f);
                                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_DECORATIONS_HOOD);
                                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_GRANDMOTHER, true);
                                task.Repeat(7s);
                                break;
                            case 1:
                                _instance->HandleGameObject(ObjectGuid::Empty, true, _instance->GetGameObject(DATA_GO_STAGE_CURTAIN));
                                break;
                            default:
                                break;
                        }
                    });
                    break;
                case EVENT_OZ:
                    _scheduler.Schedule(0s, [this](TaskContext task)
                    {
                        switch (task.GetRepeatCounter())
                        {
                            case 0:
                                me->SetFacingTo(1.448623299598693847f);
                                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_DECORATIONS_OZ);
                                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_TINHEAD, true);
                                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_STRAWMAN, true);
                                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_ROAR, true);
                                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_DOROTHEE, true);
                                task.Repeat(1200ms);
                                break;
                            case 1:
                                _instance->HandleGameObject(ObjectGuid::Empty, true, _instance->GetGameObject(DATA_GO_STAGE_CURTAIN));
                                break;
                            default:
                                break;
                        }
                    });
                    break;
                case EVENT_RAJ:
                    _scheduler.Schedule(0s, [this](TaskContext task)
                    {
                        switch (task.GetRepeatCounter())
                        {
                            case 0:
                                me->SetFacingTo(1.448623299598693847f);
                                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_DECORATIONS_RAJ);
                                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_JULIANNE, true);
                                task.Repeat(4s);
                                break;
                            case 1:
                                _instance->HandleGameObject(ObjectGuid::Empty, true, _instance->GetGameObject(DATA_GO_STAGE_CURTAIN));
                                break;
                            default:
                                break;
                        }
                    });
                    break;
                default:
                    break;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    bool OnGossipHello(Player* player) override
    {
        if (_instance->GetBossState(DATA_MOROES) != DONE)
        {
            InitGossipMenuFor(player, GOSSIP_MENU_MAIN);
            SendGossipMenuFor(player, GOSSIP_TEXT_MOROES_ALIVE, me->GetGUID());
            return true;
        }
        else
        {
            switch (_instance->GetBossState(DATA_OPERA_PERFORMANCE))
            {
                case NOT_STARTED:
                    InitGossipMenuFor(player, GOSSIP_MENU_MAIN);

                    AddGossipItemFor(player, GOSSIP_MENU_MAIN, GOSSIP_OPTION_MAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

                    if (player->IsGameMaster())
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_DOT, GOSSIP_OPTION_GM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
                        AddGossipItemFor(player, GOSSIP_ICON_DOT, GOSSIP_OPTION_GM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                        AddGossipItemFor(player, GOSSIP_ICON_DOT, GOSSIP_OPTION_GM_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
                    }

                    SendGossipMenuFor(player, GOSSIP_TEXT_MAIN_1, me->GetGUID());
                    break;
                case FAIL:
                    InitGossipMenuFor(player, GOSSIP_MENU_MAIN);

                    if (player->IsGameMaster())
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_DOT, GOSSIP_OPTION_GM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
                        AddGossipItemFor(player, GOSSIP_ICON_DOT, GOSSIP_OPTION_GM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                        AddGossipItemFor(player, GOSSIP_ICON_DOT, GOSSIP_OPTION_GM_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
                    }

                    switch (_instance->GetData(DATA_OPERA_VARIATION))
                    {
                        case EVENT_HOOD:
                            AddGossipItemFor(player, GOSSIP_MENU_MAIN, GOSSIP_OPTION_FAIL_HOOD, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                            SendGossipMenuFor(player, GOSSIP_TEXT_FAIL_HOOD, me->GetGUID());
                            break;
                        case EVENT_OZ:
                            AddGossipItemFor(player, GOSSIP_MENU_MAIN, GOSSIP_OPTION_FAIL_OZ, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                            SendGossipMenuFor(player, GOSSIP_TEXT_FAIL_OZ, me->GetGUID());
                            break;
                        case EVENT_RAJ:
                            AddGossipItemFor(player, GOSSIP_MENU_MAIN, GOSSIP_OPTION_FAIL_RAJ, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                            SendGossipMenuFor(player, GOSSIP_TEXT_FAIL_RAJ, me->GetGUID());
                            break;
                        default:
                            break;
                    }
                    break;
                case DONE:
                    InitGossipMenuFor(player, GOSSIP_MENU_MAIN);
                    SendGossipMenuFor(player, GOSSIP_TEXT_DONE, me->GetGUID());
                    break;
                default:
                    break;
            }

            return true;
        }
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
        ClearGossipMenuFor(player);

        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF + 1:
                InitGossipMenuFor(player, GOSSIP_MENU_MAIN_2);
                AddGossipItemFor(player, GOSSIP_MENU_MAIN_2, GOSSIP_OPTION_MAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                SendGossipMenuFor(player, GOSSIP_TEXT_MAIN_2, me->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                CloseGossipMenuFor(player);
                DoAction(ACTION_START_ANNOUNCE);
                break;
            case GOSSIP_ACTION_INFO_DEF + 10:
                CloseGossipMenuFor(player);
                _instance->SetData(DATA_OPERA_VARIATION, EVENT_OZ);
                break;
            case GOSSIP_ACTION_INFO_DEF + 11:
                CloseGossipMenuFor(player);
                _instance->SetData(DATA_OPERA_VARIATION, EVENT_HOOD);
                break;
            case GOSSIP_ACTION_INFO_DEF + 12:
                CloseGossipMenuFor(player);
                _instance->SetData(DATA_OPERA_VARIATION, EVENT_RAJ);
                break;
        }

        return true;
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

enum ImageOfMedivhTexts
{
    SAY_DIALOG_MEDIVH_1             = 0,
    SAY_DIALOG_ARCANAGOS_2          = 0,
    SAY_DIALOG_MEDIVH_3             = 1,
    SAY_DIALOG_ARCANAGOS_4          = 1,
    SAY_DIALOG_MEDIVH_5             = 2,
    SAY_DIALOG_ARCANAGOS_6          = 2,
    EMOTE_DIALOG_MEDIVH_7           = 3,
    SAY_DIALOG_ARCANAGOS_8          = 3,
    SAY_DIALOG_MEDIVH_9             = 4
};

enum ImageOfMedivhMisc
{
    SPELL_FIRE_BALL             = 30967,
    SPELL_UBER_FIREBALL         = 30971,
    SPELL_CONFLAGRATION_BLAST   = 30977,
    SPELL_MANA_SHIELD           = 31635,

    NPC_ARCANAGOS               = 17652
};

static float MedivPos[4] = {-11161.49f, -1902.24f, 91.48f, 1.94f};
static float ArcanagosPos[4] = {-11169.75f, -1881.48f, 95.39f, 4.83f};

class npc_image_of_medivh : public CreatureScript
{
public:
    npc_image_of_medivh() : CreatureScript("npc_image_of_medivh") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetKarazhanAI<npc_image_of_medivhAI>(creature);
    }

    struct npc_image_of_medivhAI : public ScriptedAI
    {
        npc_image_of_medivhAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            Step = 0;
            FireArcanagosTimer = 0;
            FireMedivhTimer = 0;
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            ArcanagosGUID.Clear();
            EventStarted = false;
            YellTimer = 0;
        }

        InstanceScript* instance;

        ObjectGuid ArcanagosGUID;

        uint32 YellTimer;
        uint32 Step;
        uint32 FireMedivhTimer;
        uint32 FireArcanagosTimer;

        bool EventStarted;

        void Reset() override
        {
            Initialize();
            me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);

            if (instance->GetGuidData(DATA_IMAGE_OF_MEDIVH).IsEmpty())
            {
                instance->SetGuidData(DATA_IMAGE_OF_MEDIVH, me->GetGUID());
                (*me).GetMotionMaster()->MovePoint(1, MedivPos[0], MedivPos[1], MedivPos[2]);
                Step = 0;
            }
            else
            {
                me->DespawnOrUnsummon();
            }
        }
        void JustEngagedWith(Unit* /*who*/) override { }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;
            if (id == 1)
            {
                StartEvent();
                me->SetOrientation(MedivPos[3]);
                me->SetOrientation(MedivPos[3]);
            }
        }

        void StartEvent()
        {
            Step = 1;
            EventStarted = true;
            Creature* Arcanagos = me->SummonCreature(NPC_ARCANAGOS, ArcanagosPos[0], ArcanagosPos[1], ArcanagosPos[2], 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20s);
            if (!Arcanagos)
                return;
            ArcanagosGUID = Arcanagos->GetGUID();
            Arcanagos->SetDisableGravity(true);
            Arcanagos->GetMotionMaster()->MovePoint(0, ArcanagosPos[0], ArcanagosPos[1], ArcanagosPos[2]);
            Arcanagos->SetOrientation(ArcanagosPos[3]);
            me->SetOrientation(MedivPos[3]);
            YellTimer = 10000;
        }

        uint32 NextStep(uint32 step)
        {
            switch (step)
            {
            case 0: return 9999999;
            case 1:
                Talk(SAY_DIALOG_MEDIVH_1);
                return 10000;
            case 2:
                if (Creature* arca = ObjectAccessor::GetCreature(*me, ArcanagosGUID))
                    arca->AI()->Talk(SAY_DIALOG_ARCANAGOS_2);
                return 20000;
            case 3:
                Talk(SAY_DIALOG_MEDIVH_3);
                return 10000;
            case 4:
                if (Creature* arca = ObjectAccessor::GetCreature(*me, ArcanagosGUID))
                    arca->AI()->Talk(SAY_DIALOG_ARCANAGOS_4);
                return 20000;
            case 5:
                Talk(SAY_DIALOG_MEDIVH_5);
                return 20000;
            case 6:
                if (Creature* arca = ObjectAccessor::GetCreature(*me, ArcanagosGUID))
                    arca->AI()->Talk(SAY_DIALOG_ARCANAGOS_6);
                return 10000;
            case 7:
                FireArcanagosTimer = 500;
                return 5000;
            case 8:
                FireMedivhTimer = 500;
                DoCast(me, SPELL_MANA_SHIELD);
                return 10000;
            case 9:
                Talk(EMOTE_DIALOG_MEDIVH_7);
                return 10000;
            case 10:
                if (Creature* arca = ObjectAccessor::GetCreature(*me, ArcanagosGUID))
                    DoCast(arca, SPELL_CONFLAGRATION_BLAST, false);
                return 1000;
            case 11:
                if (Creature* arca = ObjectAccessor::GetCreature(*me, ArcanagosGUID))
                    arca->AI()->Talk(SAY_DIALOG_ARCANAGOS_8);
                return 5000;
            case 12:
                if (Creature* arca = ObjectAccessor::GetCreature(*me, ArcanagosGUID))
                {
                    arca->GetMotionMaster()->MovePoint(0, -11010.82f, -1761.18f, 156.47f);
                    arca->setActive(true);
                    arca->SetFarVisible(true);
                    arca->InterruptNonMeleeSpells(true);
                    arca->SetSpeedRate(MOVE_FLIGHT, 2.0f);
                }
                return 10000;
            case 13:
                Talk(SAY_DIALOG_MEDIVH_9);
                return 10000;
            case 14:
            {
                me->SetVisible(false);
                me->ClearInCombat();

                InstanceMap::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
                for (InstanceMap::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (i->GetSource()->IsAlive())
                    {
                        if (i->GetSource()->GetQuestStatus(9645) == QUEST_STATUS_INCOMPLETE)
                            i->GetSource()->CompleteQuest(9645);
                    }
                }
                return 50000;
            }
            case 15:
                if (Creature* arca = ObjectAccessor::GetCreature(*me, ArcanagosGUID))
                    arca->KillSelf();
                return 5000;
            default:
                return 9999999;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (YellTimer <= diff)
            {
                if (EventStarted)
                    YellTimer = NextStep(Step++);
            } else YellTimer -= diff;

            if (Step >= 7 && Step <= 12)
            {
                Unit* arca = ObjectAccessor::GetUnit(*me, ArcanagosGUID);

                if (FireArcanagosTimer <= diff)
                {
                    if (arca)
                        arca->CastSpell(me, SPELL_FIRE_BALL, false);
                    FireArcanagosTimer = 6000;
                } else FireArcanagosTimer -= diff;

                if (FireMedivhTimer <= diff)
                {
                    if (arca)
                        DoCast(arca, SPELL_FIRE_BALL);
                    FireMedivhTimer = 5000;
                } else FireMedivhTimer -= diff;
            }
        }
    };
};

enum KarazhanCharge
{
    SPELL_FEAR      = 29321
};

// 29320 - Charge
class spell_karazhan_charge : public SpellScript
{
    PrepareSpellScript(spell_karazhan_charge);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FEAR });
    }

    void HandleAfterHit()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_FEAR);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_karazhan_charge::HandleAfterHit);
    }
};

void AddSC_karazhan()
{
    RegisterKarazhanCreatureAI(npc_barnes);
    new npc_image_of_medivh();
    RegisterSpellScript(spell_karazhan_charge);
}
