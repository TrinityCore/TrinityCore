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
SDName: Orgrimmar
SD%Complete: 100
SDComment: Quest support: 2460, 6566
SDCategory: Orgrimmar
EndScriptData */

/* ContentData
npc_shenthul
npc_thrall_warchief
EndContentData */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "TemporarySummon.h"

/*######
## npc_shenthul
######*/

enum Shenthul
{
    QUEST_SHATTERED_SALUTE  = 2460
};

class npc_shenthul : public CreatureScript
{
public:
    npc_shenthul() : CreatureScript("npc_shenthul") { }

    struct npc_shenthulAI : public ScriptedAI
    {
        npc_shenthulAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            CanTalk = false;
            CanEmote = false;
            SaluteTimer = 6000;
            ResetTimer = 0;
            PlayerGUID.Clear();
        }

        bool CanTalk;
        bool CanEmote;
        uint32 SaluteTimer;
        uint32 ResetTimer;
        ObjectGuid PlayerGUID;

        void Reset() override
        {
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (CanEmote)
            {
                if (ResetTimer <= diff)
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                    {
                        if (player->GetTypeId() == TYPEID_PLAYER && player->GetQuestStatus(QUEST_SHATTERED_SALUTE) == QUEST_STATUS_INCOMPLETE)
                            player->FailQuest(QUEST_SHATTERED_SALUTE);
                    }
                    Reset();
                } else ResetTimer -= diff;
            }

            if (CanTalk && !CanEmote)
            {
                if (SaluteTimer <= diff)
                {
                    me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                    CanEmote = true;
                    ResetTimer = 60000;
                } else SaluteTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void ReceiveEmote(Player* player, uint32 emote) override
        {
            if (emote == TEXT_EMOTE_SALUTE && player->GetQuestStatus(QUEST_SHATTERED_SALUTE) == QUEST_STATUS_INCOMPLETE)
            {
                if (CanEmote)
                {
                    player->AreaExploredOrEventHappens(QUEST_SHATTERED_SALUTE);
                    Reset();
                }
            }
        }

        void OnQuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_SHATTERED_SALUTE)
            {
                CanTalk = true;
                PlayerGUID = player->GetGUID();
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shenthulAI(creature);
    }
};

/*######
## npc_thrall_warchief
######*/

enum ThrallWarchief
{
    GOSSIP_MENU_OPTION_ID_ALL   = 0,

    OPTION_PLEASE_SHARE_YOUR    = 3664,
    OPTION_WHAT_DISCOVERIES     = 3665,
    OPTION_USURPER              = 3666,
    OPTION_WITH_ALL_DUE_RESPECT = 3667,
    OPTION_I_I_DID_NOT_THINK_OF = 3668,
    OPTION_I_LIVE_ONLY_TO_SERVE = 3669,
    OPTION_OF_COURSE_WARCHIEF   = 3670,

    GOSSIP_MEMBERS_OF_THE_HORDE = 4477,
    GOSSIP_THE_SHATTERED_HAND   = 5733,
    GOSSIP_IT_WOULD_APPEAR_AS   = 5734,
    GOSSIP_THE_BROOD_MOTHER     = 5735,
    GOSSIP_SO_MUCH_TO_LEARN     = 5736,
    GOSSIP_I_DO_NOT_FAULT_YOU   = 5737,
    GOSSIP_NOW_PAY_ATTENTION    = 5738,

    QUEST_WHAT_THE_WIND_CARRIES = 6566,

    SPELL_CHAIN_LIGHTNING       = 16033,
    SPELL_SHOCK                 = 16034
};

enum Sounds
{
    SOUND_AGGRO                 = 5880
};

/// @todo verify abilities/timers
class npc_thrall_warchief : public CreatureScript
{
public:
    npc_thrall_warchief() : CreatureScript("npc_thrall_warchief") { }

    struct npc_thrall_warchiefAI : public ScriptedAI
    {
        npc_thrall_warchiefAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            ChainLightningTimer = 2000;
            ShockTimer = 8000;
        }

        uint32 ChainLightningTimer;
        uint32 ShockTimer;

        void Reset() override
        {
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            DoPlaySoundToSet(me, SOUND_AGGRO);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (ChainLightningTimer <= diff)
            {
                DoCastVictim(SPELL_CHAIN_LIGHTNING);
                ChainLightningTimer = 9000;
            } else ChainLightningTimer -= diff;

            if (ShockTimer <= diff)
            {
                DoCastVictim(SPELL_SHOCK);
                ShockTimer = 15000;
            } else ShockTimer -= diff;

            DoMeleeAttackIfReady();
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    InitGossipMenuFor(player, OPTION_WHAT_DISCOVERIES);
                    AddGossipItemFor(player, OPTION_WHAT_DISCOVERIES, GOSSIP_MENU_OPTION_ID_ALL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                    SendGossipMenuFor(player, GOSSIP_THE_SHATTERED_HAND, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 2:
                    InitGossipMenuFor(player, OPTION_USURPER);
                    AddGossipItemFor(player, OPTION_USURPER, GOSSIP_MENU_OPTION_ID_ALL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                    SendGossipMenuFor(player, GOSSIP_IT_WOULD_APPEAR_AS, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 3:
                    InitGossipMenuFor(player, OPTION_WITH_ALL_DUE_RESPECT);
                    AddGossipItemFor(player, OPTION_WITH_ALL_DUE_RESPECT, GOSSIP_MENU_OPTION_ID_ALL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                    SendGossipMenuFor(player, GOSSIP_THE_BROOD_MOTHER, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 4:
                    InitGossipMenuFor(player, OPTION_I_I_DID_NOT_THINK_OF);
                    AddGossipItemFor(player, OPTION_I_I_DID_NOT_THINK_OF, GOSSIP_MENU_OPTION_ID_ALL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
                    SendGossipMenuFor(player, GOSSIP_SO_MUCH_TO_LEARN, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 5:
                    InitGossipMenuFor(player, OPTION_I_LIVE_ONLY_TO_SERVE);
                    AddGossipItemFor(player, OPTION_I_LIVE_ONLY_TO_SERVE, GOSSIP_MENU_OPTION_ID_ALL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
                    SendGossipMenuFor(player, GOSSIP_I_DO_NOT_FAULT_YOU, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 6:
                    InitGossipMenuFor(player, OPTION_OF_COURSE_WARCHIEF);
                    AddGossipItemFor(player, OPTION_OF_COURSE_WARCHIEF, GOSSIP_MENU_OPTION_ID_ALL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
                    SendGossipMenuFor(player, GOSSIP_NOW_PAY_ATTENTION, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 7:
                    CloseGossipMenuFor(player);
                    player->AreaExploredOrEventHappens(QUEST_WHAT_THE_WIND_CARRIES);
                    break;
            }
            return true;
        }

        bool OnGossipHello(Player* player) override
        {
            InitGossipMenuFor(player, OPTION_PLEASE_SHARE_YOUR);
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            if (player->GetQuestStatus(QUEST_WHAT_THE_WIND_CARRIES) == QUEST_STATUS_INCOMPLETE)
                AddGossipItemFor(player, OPTION_PLEASE_SHARE_YOUR, GOSSIP_MENU_OPTION_ID_ALL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            SendGossipMenuFor(player, GOSSIP_MEMBERS_OF_THE_HORDE, me->GetGUID());
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_thrall_warchiefAI(creature);
    }
};

/* --------- Herald of War ------------- */
enum CitizenEntries
{
    NPC_GRYSHKA         = 31433,
    NPC_OLVIA           = 31425,
    NPC_SANA            = 31429,
    NPC_FELIKA          = 31427,
    NPC_THATHUNG        = 31430,
    NPC_KAJA            = 31423
};

enum SceneEvents
{
    EVENT_SCENE_1       = 1,
    EVENT_SCENE_2       = 2,
    EVENT_SCENE_3       = 3,
    EVENT_SCENE_4       = 4,
    EVENT_SCENE_5       = 5,
    EVENT_SCENE_6       = 6,
    EVENT_SCENE_7       = 7,
    EVENT_SCENE_8       = 8,
    EVENT_SCENE_9       = 9,
    EVENT_SCENE_10      = 10,
    EVENT_SCENE_11      = 11,
    EVENT_SCENE_12      = 12,
    EVENT_SCENE_13      = 13,
    EVENT_RESET         = 14
};

enum CitizenTalk
{
    SAY_GRYSHKA_1       = 0, // When can we reopen our shops? I'm losing gold here!
    SAY_GRYSHKA_2       = 1, // "This is an outrage!"
    SAY_OLVIA_1         = 0, // Where is the Warchief?
    SAY_OLVIA_2         = 1, // What are all these Forsaken doing here?
    SAY_FELIKA_1        = 0, // What is going on?
    SAY_FELIKA_2        = 1, // This is an outrage!
    SAY_THATHUNG        = 0, // What is going on?
    SAY_KAJA            = 0, // Why is Thrall allowing this to happen to our city?
    SAY_SANA            = 0, // We demand answers!
    SAY_RUNTHAK_1       = 0, // SILENCE!
    SAY_RUNTHAK_2       = 1, // We are on the brink of all out war with the Alliance!
    SAY_RUNTHAK_3       = 2, // Tragic events have unfolded in Northrend. The Warchief is doing all that he can to keep us safe.
    SAY_RUNTHAK_4       = 3  // All services and shops are to remain closed until further notice! That is all!
};

class npc_overlord_runthak_orgrimmar : public CreatureScript
{
public:
    npc_overlord_runthak_orgrimmar() : CreatureScript("npc_overlord_runthak_orgrimmar") { }

    struct npc_overlord_runthak_orgrimmarAI : public ScriptedAI
    {
        npc_overlord_runthak_orgrimmarAI(Creature* creature) : ScriptedAI(creature)
        {
            inProgress = false;
        }

        void Reset() override
        {
            inProgress = false;
            me->GetMotionMaster()->MovePath(me->GetSpawnId() * 10, true);
            events.Reset();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER && who->IsWithinDist(me, 20.0f) && !inProgress)
            {
                inProgress = true;
                events.ScheduleEvent(EVENT_SCENE_1, 2s);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventID = events.ExecuteEvent())
            {
                switch (eventID)
                {
                    case EVENT_SCENE_1:
                        GetCitizenGuids();
                        me->GetMotionMaster()->MoveIdle();
                        if (Creature* gryshka = ObjectAccessor::GetCreature(*me, gryshkaGUID))
                        {
                            me->SetFacingToObject(gryshka);
                            gryshka->AI()->Talk(SAY_GRYSHKA_1);
                        }
                        events.ScheduleEvent(EVENT_SCENE_2, 4500ms);
                        break;
                    case EVENT_SCENE_2:
                        if (Creature* olvia = ObjectAccessor::GetCreature(*me, olviaGUID))
                            olvia->AI()->Talk(SAY_OLVIA_1);
                        events.ScheduleEvent(EVENT_SCENE_3, 4500ms);
                        break;
                    case EVENT_SCENE_3:
                        if (Creature* felika = ObjectAccessor::GetCreature(*me, felikaGUID))
                            felika->AI()->Talk(SAY_FELIKA_1);
                        events.ScheduleEvent(EVENT_SCENE_4, 4500ms);
                        break;
                    case EVENT_SCENE_4:
                        if (Creature* thathung = ObjectAccessor::GetCreature(*me, thungGUID))
                            thathung->AI()->Talk(SAY_THATHUNG);
                        events.ScheduleEvent(EVENT_SCENE_5, 4500ms);
                        break;
                    case EVENT_SCENE_5:
                        if (Creature* sana = ObjectAccessor::GetCreature(*me, sanaGUID))
                            sana->AI()->Talk(SAY_SANA);
                        events.ScheduleEvent(EVENT_SCENE_6, 4500ms);
                        break;
                    case EVENT_SCENE_6:
                        if (Creature* gryshka = ObjectAccessor::GetCreature(*me, gryshkaGUID))
                            gryshka->AI()->Talk(SAY_GRYSHKA_2);
                        events.ScheduleEvent(EVENT_SCENE_7, 4500ms);
                        break;
                    case EVENT_SCENE_7:
                        if (Creature* kaja = ObjectAccessor::GetCreature(*me, kajaGUID))
                            kaja->AI()->Talk(SAY_KAJA);
                        events.ScheduleEvent(EVENT_SCENE_8, 4500ms);
                        break;
                    case EVENT_SCENE_8:
                        if (Creature* felika = ObjectAccessor::GetCreature(*me, felikaGUID))
                            felika->AI()->Talk(SAY_FELIKA_2);
                        events.ScheduleEvent(EVENT_SCENE_9, 4500ms);
                        break;
                    case EVENT_SCENE_9:
                        if (Creature* olvia = ObjectAccessor::GetCreature(*me, olviaGUID))
                            olvia->AI()->Talk(SAY_OLVIA_2);
                        events.ScheduleEvent(EVENT_SCENE_10, 4500ms);
                        break;
                    case EVENT_SCENE_10:
                        Talk(SAY_RUNTHAK_1);
                        events.ScheduleEvent(EVENT_SCENE_11, 1500ms);
                        break;
                    case EVENT_SCENE_11:
                        Talk(SAY_RUNTHAK_2);
                        events.ScheduleEvent(EVENT_SCENE_12, 4500ms);
                        break;
                    case EVENT_SCENE_12:
                        Talk(SAY_RUNTHAK_3);
                        events.ScheduleEvent(EVENT_SCENE_13, 4500ms);
                        break;
                    case EVENT_SCENE_13:
                        Talk(SAY_RUNTHAK_4);
                        events.ScheduleEvent(EVENT_RESET, 25s);
                        break;
                    case EVENT_RESET:
                        Reset();
                        break;
                    default:
                        break;
                }
            }
        }

        void GetCitizenGuids()
        {
            // if one GUID is empty it means all the others are empty as well so we should store them
            // otherwise do not call for grid search since someone else already activated event once before and guids are stored
            if (gryshkaGUID.IsEmpty())
            {
                std::list<Unit*> citizenList;
                Trinity::AnyFriendlyUnitInObjectRangeCheck checker(me, me, 25.0f);
                Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(me, citizenList, checker);
                Cell::VisitGridObjects(me, searcher, 20.0f);
                for (Unit* target : citizenList)
                {
                    switch (target->GetEntry())
                    {
                        case NPC_GRYSHKA:
                            gryshkaGUID = target->GetGUID();
                            break;
                        case NPC_OLVIA:
                            olviaGUID = target->GetGUID();
                            break;
                        case NPC_SANA:
                            sanaGUID = target->GetGUID();
                            break;
                        case NPC_FELIKA:
                            felikaGUID = target->GetGUID();
                            break;
                        case NPC_THATHUNG:
                            thungGUID = target->GetGUID();
                            break;
                        case NPC_KAJA:
                            kajaGUID = target->GetGUID();
                            break;
                        default:
                            break;
                    }
                }
            }
        }

    private:
        EventMap events;
        bool inProgress;
        ObjectGuid gryshkaGUID;
        ObjectGuid olviaGUID;
        ObjectGuid sanaGUID;
        ObjectGuid felikaGUID;
        ObjectGuid thungGUID;
        ObjectGuid kajaGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_overlord_runthak_orgrimmarAI(creature);
    }
};

// Phased out thrall during herald of war chain quest
enum HeraldEntries
{
    NPC_PORTAL_STORMWIND        = 31640,
    NPC_JAINA_PROUDMOORE        = 31418,
    NPC_BANSHEE_SYLVANAS        = 31419,
    NPC_KORKRON_GUARD           = 31417,
    NPC_THRALL_HERALD           = 31412,

    GO_PORTAL_UNDERCITY         = 193425
};

enum HeraldMisc
{
    QUEST_HERALD_OF_WAR         = 13257,
    GUARDS_SIZE                 = 4
};

enum HeraldActions
{
    ACTION_START_SCENE          = 0
};

enum HeraldSpell
{
    SPELL_JAINA_SPAWNIN         = 55761
};

enum HeraldTalk
{
    SAY_THRALL_0                = 0, // Kor'kron, stand down!
    SAY_THRALL_1                = 1, // Jaina...
    SAY_THRALL_2                = 2, // Jaina, what happened at the Wrathgate. It was a betrayal from within...
    SAY_THRALL_3                = 3, // The Horde has lost the Undercity.
    SAY_THRALL_4                = 4, // We now prepare to lay siege to the city and bring the perpetrators of this unforgivable crime to justice.
    SAY_THRALL_5                = 5, // If we are forced into a conflict, the Lich King will destroy our divided forces in Northrend.
    SAY_THRALL_6                = 6, // We will make this right, Jaina. Tell your king all that you have learned here.
    SAY_THRALL_7                = 7, // Kor'kron, prepare transport to the Undercity.

    SAY_SYLVANAS_0              = 0, // Lady Proudmoore, the Warchief speaks the truth. This subterfuge was set in motion by Varimathras and Grand Apothecary Putress. It was not the Horde's doing.
    SAY_SYLVANAS_1              = 1, // As the combined Horde and Alliance forces began their assault upon the Wrath Gate, an uprising broke out in the Undercity. Varimathras and hordes of his demonic brethren attacked. Hundreds of my people were slain in the coup. I barely managed to escape with my life.

    SAY_JAINA_0                 = 0, // Thrall, what has happened? The King is preparing for war...
    SAY_JAINA_1                 = 1, // I will deliver this information to King Wrynn, Thrall, but...
    SAY_JAINA_2                 = 2, // Bolvar was like a brother to him. In the King's absence, Bolvar kept the Alliance united. He found strength for our people in our darkest hours. He watched over Anduin, raising him as his own.
    SAY_JAINA_3                 = 3, // I fear that the rage will consume him, Thrall. I remain hopeful that reason will prevail, but we must prepare for the worst... for war.
    SAY_JAINA_4                 = 4 // Farewell, Warchief. I pray that the next time we meet it will be as allies.
};

enum HeraldEvents
{
    EVENT_HERALD_SCENE1         = 1,
    EVENT_HERALD_SCENE2         = 2,
    EVENT_HERALD_SCENE3         = 3,
    EVENT_HERALD_SCENE4         = 4,
    EVENT_HERALD_SCENE5         = 5,
    EVENT_HERALD_SCENE6         = 6,
    EVENT_HERALD_SCENE7         = 7,
    EVENT_HERALD_SCENE8         = 8,
    EVENT_HERALD_SCENE9         = 9,
    EVENT_HERALD_SCENE10        = 10,
    EVENT_HERALD_SCENE11        = 11,
    EVENT_HERALD_SCENE12        = 12,
    EVENT_HERALD_SCENE13        = 13,
    EVENT_HERALD_SCENE14        = 14,
    EVENT_HERALD_SCENE15        = 15,
    EVENT_HERALD_RESET          = 16
};

Position const GuardsSpawnPosition[GUARDS_SIZE] =
{
    { 1909.39f, -4144.21f, 40.6368f, 0.042239f },
    { 1910.73f, -4155.26f, 40.6316f, 0.615577f },
    { 1934.01f, -4141.40f, 40.6375f, 3.61109f },
    { 1931.11f, -4156.38f, 40.6130f, 2.19737f }
};

Position const GuardsMovePosition[GUARDS_SIZE] =
{
    { 1917.461670f, -4147.514160f, 40.636799f, 5.89346f },
    { 1916.181274f, -4152.295898f, 40.629120f, 0.497757f },
    { 1926.435425f, -4146.397461f, 40.618534f, 3.846709f },
    { 1926.519165f, -4153.216797f, 40.614975f, 2.570434f }
};

Position const MiscMovePositions[3] =
{
    { 1921.719604f, -4143.051270f, 40.623356f, 1.657789f }, // jaina move
    { 1921.151855f, -4139.343750f, 40.583084f, 4.732627f }, // thrall move
    { 1918.732422f, -4139.619629f, 40.607685f, 4.803311f } // sylvanas move
};

Position const PortalSpawnPosition = { 1921.752441f, -4151.148438f, 40.623848f, 1.714324f };

class npc_thrall_herald_of_war : public CreatureScript
{
public:
    npc_thrall_herald_of_war() : CreatureScript("npc_thrall_herald_of_war") { }

    struct npc_thrall_herald_of_warAI : public ScriptedAI
    {
        npc_thrall_herald_of_warAI(Creature* creature) : ScriptedAI(creature)
        {
            spawnedGuards = false;
            sceneInProgress = false;
        }

        void Reset() override
        {
            events.Reset();
            me->GetMotionMaster()->MovePath(me->GetSpawnId() * 10, true);
            sceneInProgress = false;

            if (!spawnedGuards)
            {
                spawnedGuards = true;
                for (uint8 i = 0; i < GUARDS_SIZE; i++)
                {
                    if (Creature* korkronGuard = me->SummonCreature(NPC_KORKRON_GUARD, GuardsSpawnPosition[i]))
                        guardsGUIDs[i] = korkronGuard->GetGUID();
                }
            }
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (pointId == 2)
                me->GetMotionMaster()->MovePath(me->GetSpawnId() * 10, true);
        }

        void DoAction(int32 actionId) override
        {
            if (actionId == ACTION_START_SCENE && !sceneInProgress)
            {
                me->GetMotionMaster()->MoveIdle();
                sceneInProgress = true;

                if (Creature* jaina = me->SummonCreature(NPC_JAINA_PROUDMOORE, PortalSpawnPosition))
                {
                    me->SetFacingToObject(jaina);
                    jainaGUID = jaina->GetGUID();
                    jaina->CastSpell(jaina, SPELL_JAINA_SPAWNIN);
                }

                if (Creature* stormwindPortal = me->SummonCreature(NPC_PORTAL_STORMWIND, PortalSpawnPosition))
                {
                    stormwindPortal->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    stormwindPortalGUID = stormwindPortal->GetGUID();
                }

                for (uint8 i = 0; i < GUARDS_SIZE; i++)
                {
                    if (Creature* guards = ObjectAccessor::GetCreature(*me, guardsGUIDs[i]))
                    {
                        guards->SetWalk(false);
                        guards->SetEmoteState(EMOTE_STATE_READY2H);
                        guards->GetMotionMaster()->MovePoint(1, GuardsMovePosition[i]);
                    }
                }

                if (Creature* sylvanas = me->FindNearestCreature(NPC_BANSHEE_SYLVANAS, 25.0f))
                    sylvanasGUID = sylvanas->GetGUID();

                events.ScheduleEvent(EVENT_HERALD_SCENE1, 4s);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventID = events.ExecuteEvent())
            {
                switch (eventID)
                {
                    case EVENT_HERALD_SCENE1:
                        Talk(SAY_THRALL_0);
                        me->GetMotionMaster()->MovePoint(1, MiscMovePositions[1]);
                        if (Creature* jaina = ObjectAccessor::GetCreature(*me, jainaGUID))
                        {
                            jaina->SetWalk(true);
                            jaina->GetMotionMaster()->MovePoint(1, MiscMovePositions[0]);
                        }

                        for (uint8 i = 0; i < GUARDS_SIZE; i++)
                        {
                            if (Creature* guard = ObjectAccessor::GetCreature(*me, guardsGUIDs[i]))
                            {
                                guard->GetMotionMaster()->MoveTargetedHome();
                                guard->SetEmoteState(EMOTE_STATE_NONE);
                            }
                        }
                        events.ScheduleEvent(EVENT_HERALD_SCENE2, 3s);
                        break;
                    case EVENT_HERALD_SCENE2:
                        Talk(SAY_THRALL_1);
                        if (Creature* jaina = ObjectAccessor::GetCreature(*me, jainaGUID))
                            me->SetFacingToObject(jaina);
                        events.ScheduleEvent(EVENT_HERALD_SCENE3, 3500ms);
                        break;
                    case EVENT_HERALD_SCENE3:
                        if (Creature* jaina = ObjectAccessor::GetCreature(*me, jainaGUID))
                            jaina->AI()->Talk(SAY_JAINA_0);
                        events.ScheduleEvent(EVENT_HERALD_SCENE4, 5500ms);
                        break;
                    case EVENT_HERALD_SCENE4:
                        Talk(SAY_THRALL_2);
                        if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, sylvanasGUID))
                        {
                            sylvanas->SetStandState(UNIT_STAND_STATE_STAND);
                            sylvanas->SetWalk(true);
                            sylvanas->GetMotionMaster()->MovePoint(1, MiscMovePositions[2]);
                        }
                        events.ScheduleEvent(EVENT_HERALD_SCENE5, 6500ms);
                        break;
                    case EVENT_HERALD_SCENE5:
                        if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, sylvanasGUID))
                            sylvanas->AI()->Talk(SAY_SYLVANAS_0);
                        events.ScheduleEvent(EVENT_HERALD_SCENE6, 10s);
                        break;
                    case EVENT_HERALD_SCENE6:
                        if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, sylvanasGUID))
                            sylvanas->AI()->Talk(SAY_SYLVANAS_1);
                        events.ScheduleEvent(EVENT_HERALD_SCENE7, 20s);
                        break;
                    case EVENT_HERALD_SCENE7:
                        Talk(SAY_THRALL_3);
                        events.ScheduleEvent(EVENT_HERALD_SCENE8, 4500ms);
                        break;
                    case EVENT_HERALD_SCENE8:
                        Talk(SAY_THRALL_4);
                        events.ScheduleEvent(EVENT_HERALD_SCENE9, 10s);
                        break;
                    case EVENT_HERALD_SCENE9:
                        Talk(SAY_THRALL_5);
                        events.ScheduleEvent(EVENT_HERALD_SCENE10, 8s);
                        break;
                    case EVENT_HERALD_SCENE10:
                        Talk(SAY_THRALL_6);
                        events.ScheduleEvent(EVENT_HERALD_SCENE11, 9s);
                        break;
                    case EVENT_HERALD_SCENE11:
                        if (Creature* jaina = ObjectAccessor::GetCreature(*me, jainaGUID))
                            jaina->AI()->Talk(SAY_JAINA_1);
                        events.ScheduleEvent(EVENT_HERALD_SCENE12, 6s);
                        break;
                    case EVENT_HERALD_SCENE12:
                        if (Creature* jaina = ObjectAccessor::GetCreature(*me, jainaGUID))
                            jaina->AI()->Talk(SAY_JAINA_2);
                        events.ScheduleEvent(EVENT_HERALD_SCENE13, 14s);
                        break;
                    case EVENT_HERALD_SCENE13:
                        if (Creature* jaina = ObjectAccessor::GetCreature(*me, jainaGUID))
                            jaina->AI()->Talk(SAY_JAINA_3);
                        events.ScheduleEvent(EVENT_HERALD_SCENE14, 10s);
                        break;
                    case EVENT_HERALD_SCENE14:
                        if (Creature* jaina = ObjectAccessor::GetCreature(*me, jainaGUID))
                        {
                            jaina->AI()->Talk(SAY_JAINA_4);
                            jaina->SetWalk(true);
                            jaina->GetMotionMaster()->MovePoint(2, jaina->GetHomePosition());
                            jaina->DespawnOrUnsummon(5s);
                        }
                        events.ScheduleEvent(EVENT_HERALD_SCENE15, 7s);
                        break;
                    case EVENT_HERALD_SCENE15:
                    {
                        me->SetWalk(true);
                        me->GetMotionMaster()->MovePoint(2, me->GetHomePosition());
                        Talk(SAY_THRALL_7);

                        if (Creature* sylvanas = ObjectAccessor::GetCreature(*me, sylvanasGUID))
                        {
                            sylvanas->SetWalk(true);
                            sylvanas->GetMotionMaster()->MovePoint(2, sylvanas->GetHomePosition());
                        }

                        if (Creature* portal = ObjectAccessor::GetCreature(*me, stormwindPortalGUID))
                            portal->DespawnOrUnsummon();

                        events.ScheduleEvent(EVENT_HERALD_RESET, 1min);
                        break;
                    }
                    case EVENT_HERALD_RESET:
                        Reset();
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap events;
        ObjectGuid guardsGUIDs[GUARDS_SIZE];
        ObjectGuid jainaGUID;
        ObjectGuid sylvanasGUID;
        ObjectGuid stormwindPortalGUID;
        bool spawnedGuards;
        bool sceneInProgress;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_thrall_herald_of_warAI(creature);
    }
};

class areatrigger_orgrimmar_herald_of_war : public AreaTriggerScript
{
public:
    areatrigger_orgrimmar_herald_of_war() : AreaTriggerScript("areatrigger_orgrimmar_herald_of_war") { }

    bool OnTrigger(Player* player, AreaTriggerDBC const* /*trigger*/) override
    {
        if (player->IsAlive() && player->GetQuestStatus(QUEST_HERALD_OF_WAR) == QUEST_STATUS_COMPLETE)
        {
            if (Creature* thrall = player->FindNearestCreature(NPC_THRALL_HERALD, 50.0f))
            {
                thrall->AI()->DoAction(ACTION_START_SCENE);
                return true;
            }
        }
        return false;
    }
};

void AddSC_orgrimmar()
{
    new npc_shenthul();
    new npc_thrall_warchief();
    new npc_overlord_runthak_orgrimmar();
    new npc_thrall_herald_of_war();
    new areatrigger_orgrimmar_herald_of_war();
}
