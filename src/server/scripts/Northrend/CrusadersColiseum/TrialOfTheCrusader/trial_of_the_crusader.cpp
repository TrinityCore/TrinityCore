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
SDName: Trial Of the crusader
SD%Complete: ??%
SDComment: event script based on /dev/rsa
SDCategory: trial_of_the_crusader
EndScriptData */

//Known Bugs:
// - Need better implementation of Gossip and correct gossip text and option
// - Misses Dalaran Teleport at the end.

#include "ScriptPCH.h"
#include "trial_of_the_crusader.h"

enum eYells
{
    SAY_STAGE_0_01            = -1649070,
    SAY_STAGE_0_02            = -1649071,
    SAY_STAGE_0_03a           = -1649072,
    SAY_STAGE_0_03h           = -1649073,
    SAY_STAGE_0_04            = -1649074,
    SAY_STAGE_0_05            = -1649075,
    SAY_STAGE_0_06            = -1649076,
    SAY_STAGE_0_WIPE          = -1649077,
    SAY_STAGE_1_01            = -1649080,
    SAY_STAGE_1_02            = -1649081,
    SAY_STAGE_1_03            = -1649082,
    SAY_STAGE_1_04            = -1649083,
    SAY_STAGE_1_05            = -1649030, //INTRO Jaraxxus
    SAY_STAGE_1_06            = -1649084,
    SAY_STAGE_1_07            = -1649086,
    SAY_STAGE_1_08            = -1649087,
    SAY_STAGE_1_09            = -1649088,
    SAY_STAGE_1_10            = -1649089,
    SAY_STAGE_1_11            = -1649090,
    SAY_STAGE_2_01            = -1649091,
    SAY_STAGE_2_02a           = -1649092,
    SAY_STAGE_2_02h           = -1649093,
    SAY_STAGE_2_03            = -1649094,
    SAY_STAGE_2_04a           = -1649095,
    SAY_STAGE_2_04h           = -1649096,
    SAY_STAGE_2_05a           = -1649097,
    SAY_STAGE_2_05h           = -1649098,
    SAY_STAGE_2_06            = -1649099,
    SAY_STAGE_3_01            = -1649100,
    SAY_STAGE_3_02            = -1649101,
    SAY_STAGE_3_03a           = -1649102,
    SAY_STAGE_3_03h           = -1649103,
    SAY_STAGE_4_01            = -1649104,
    SAY_STAGE_4_02            = -1649105,
    SAY_STAGE_4_03            = -1649106,
    SAY_STAGE_4_04            = -1649107,
    SAY_STAGE_4_05            = -1649108,
    SAY_STAGE_4_06            = -1649109,
    SAY_STAGE_4_07            = -1649110,
};

struct _Messages
{
    eAnnouncerMessages msgnum;
    uint32 id;
    bool state;
    uint32 encounter;
};

static _Messages _GossipMessage[]=
{
    {MSG_BEASTS, GOSSIP_ACTION_INFO_DEF+1, false, TYPE_BEASTS},
    {MSG_JARAXXUS, GOSSIP_ACTION_INFO_DEF+2, false, TYPE_JARAXXUS},
    {MSG_CRUSADERS, GOSSIP_ACTION_INFO_DEF+3, false, TYPE_CRUSADERS},
    {MSG_VALKIRIES, GOSSIP_ACTION_INFO_DEF+4, false, TYPE_VALKIRIES},
    {MSG_LICH_KING, GOSSIP_ACTION_INFO_DEF+5, false, TYPE_ANUBARAK},
    {MSG_ANUBARAK, GOSSIP_ACTION_INFO_DEF+6, true, TYPE_ANUBARAK}
};

enum
{
    NUM_MESSAGES = 6,
};

class npc_announcer_toc10 : public CreatureScript
{
    public:

        npc_announcer_toc10() : CreatureScript("npc_announcer_toc10") { }

        struct npc_announcer_toc10AI : public ScriptedAI
        {
            npc_announcer_toc10AI(Creature* creature) : ScriptedAI(creature)
            {
                m_pInstance = (InstanceScript*)creature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;

            void Reset()
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                if (Creature* pAlly = GetClosestCreatureWithEntry(me, NPC_THRALL, 300.0f))
                    pAlly->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                if (Creature* pAlly = GetClosestCreatureWithEntry(me, NPC_PROUDMOORE, 300.0f))
                    pAlly->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            void AttackStart(Unit* /*who*/) {}
        };

        bool OnGossipHello(Player* player, Creature* creature)
        {
            InstanceScript* instanceScript = creature->GetInstanceScript();
            if (!instanceScript)
                return true;

            char const* _message = "We are ready!";

            if (player->isInCombat() || instanceScript->IsEncounterInProgress() || instanceScript->GetData(TYPE_EVENT))
                return true;

            uint8 i = 0;
            for (; i < NUM_MESSAGES; ++i)
            {
                if ((!_GossipMessage[i].state && instanceScript->GetData(_GossipMessage[i].encounter) != DONE)
                    || (_GossipMessage[i].state && instanceScript->GetData(_GossipMessage[i].encounter) == DONE))
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, _message, GOSSIP_SENDER_MAIN, _GossipMessage[i].id);
                    break;
                }
            }

            player->SEND_GOSSIP_MENU(_GossipMessage[i].msgnum, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            player->CLOSE_GOSSIP_MENU();
            InstanceScript* instanceScript = creature->GetInstanceScript();
            if (!instanceScript)
                return true;

            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF+1:
                    if (instanceScript->GetData(TYPE_BEASTS) != DONE)
                    {
                        instanceScript->SetData(TYPE_EVENT, 110);
                        instanceScript->SetData(TYPE_NORTHREND_BEASTS, NOT_STARTED);
                        instanceScript->SetData(TYPE_BEASTS, NOT_STARTED);
                    }
                    break;
                case GOSSIP_ACTION_INFO_DEF+2:
                    if (Creature* jaraxxus = Unit::GetCreature(*player, instanceScript->GetData64(NPC_JARAXXUS)))
                    {
                        jaraxxus->RemoveAurasDueToSpell(SPELL_JARAXXUS_CHAINS);
                        jaraxxus->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        jaraxxus->SetReactState(REACT_AGGRESSIVE);
                        jaraxxus->SetInCombatWithZone();
                    }
                    else if (instanceScript->GetData(TYPE_JARAXXUS) != DONE)
                    {
                        instanceScript->SetData(TYPE_EVENT, 1010);
                        instanceScript->SetData(TYPE_JARAXXUS, NOT_STARTED);
                    }
                    break;
                case GOSSIP_ACTION_INFO_DEF+3:
                    if (instanceScript->GetData(TYPE_CRUSADERS) != DONE)
                    {
                        if (player->GetTeam() == ALLIANCE)
                            instanceScript->SetData(TYPE_EVENT, 3000);
                        else
                            instanceScript->SetData(TYPE_EVENT, 3001);
                        instanceScript->SetData(TYPE_CRUSADERS, NOT_STARTED);
                    }
                    break;
                case GOSSIP_ACTION_INFO_DEF+4:
                    if (instanceScript->GetData(TYPE_VALKIRIES) != DONE)
                    {
                        instanceScript->SetData(TYPE_EVENT, 4000);
                        instanceScript->SetData(TYPE_VALKIRIES, NOT_STARTED);
                    }
                    break;
                case GOSSIP_ACTION_INFO_DEF+5:
                {
                    if (instanceScript->GetData(TYPE_LICH_KING) != DONE && !player->isGameMaster())
                        return true;

                    if (GameObject* floor = GameObject::GetGameObject(*player, instanceScript->GetData64(GO_ARGENT_COLISEUM_FLOOR)))
                        floor->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);

                    creature->CastSpell(creature, 69016, false);

                    Creature* anubArak = Unit::GetCreature(*creature, instanceScript->GetData64(NPC_ANUBARAK));
                    if (!anubArak || !anubArak->isAlive())
                        anubArak = creature->SummonCreature(NPC_ANUBARAK, AnubarakLoc[0].GetPositionX(), AnubarakLoc[0].GetPositionY(), AnubarakLoc[0].GetPositionZ(), 3, TEMPSUMMON_CORPSE_TIMED_DESPAWN, DESPAWN_TIME);

                    instanceScript->SetData(TYPE_ANUBARAK, NOT_STARTED);

                    if (creature->IsVisible())
                        creature->SetVisible(false);
                    break;
                }
            }
            creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            return true;
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_announcer_toc10AI(creature);
        }
};

class boss_lich_king_toc : public CreatureScript
{
    public:

        boss_lich_king_toc() : CreatureScript("boss_lich_king_toc") { }

        struct boss_lich_king_tocAI : public ScriptedAI
        {
            boss_lich_king_tocAI(Creature* creature) : ScriptedAI(creature)
            {
                m_pInstance = (InstanceScript*)creature->GetInstanceScript();
            }

            InstanceScript* m_pInstance;
            uint32 m_uiUpdateTimer;

            void Reset()
            {
                m_uiUpdateTimer = 0;
                me->SetReactState(REACT_PASSIVE);
                if (Creature* summoned = me->SummonCreature(NPC_TRIGGER, ToCCommonLoc[2].GetPositionX(), ToCCommonLoc[2].GetPositionY(), ToCCommonLoc[2].GetPositionZ(), 5, TEMPSUMMON_TIMED_DESPAWN, 60000))
                {
                    summoned->CastSpell(summoned, 51807, false);
                    summoned->SetDisplayId(11686);
                }
                if (m_pInstance) m_pInstance->SetData(TYPE_LICH_KING, IN_PROGRESS);
                me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
            }

            void MovementInform(uint32 uiType, uint32 uiId)
            {
                if (uiType != POINT_MOTION_TYPE)
                    return;
                switch (uiId)
                {
                    case 0:
                        m_pInstance->SetData(TYPE_EVENT, 5030);
                        break;
                    case 1:
                        m_pInstance->SetData(TYPE_EVENT, 5050);
                        break;
                }
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!m_pInstance) return;
                if (m_pInstance->GetData(TYPE_EVENT_NPC) != NPC_LICH_KING_1) return;

                m_uiUpdateTimer = m_pInstance->GetData(TYPE_EVENT_TIMER);
                if (m_uiUpdateTimer <= uiDiff)
                {
                    switch (m_pInstance->GetData(TYPE_EVENT))
                    {
                        case 5010:
                            DoScriptText(SAY_STAGE_4_02, me);
                            m_uiUpdateTimer = 3000;
                            me->GetMotionMaster()->MovePoint(0, LichKingLoc[0]);
                            m_pInstance->SetData(TYPE_EVENT, 5020);
                            break;
                        case 5030:
                            DoScriptText(SAY_STAGE_4_04, me);
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_TALK);
                            m_uiUpdateTimer = 10000;
                            m_pInstance->SetData(TYPE_EVENT, 5040);
                            break;
                        case 5040:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                            me->GetMotionMaster()->MovePoint(1, LichKingLoc[1]);
                            m_uiUpdateTimer = 1000;
                            m_pInstance->SetData(TYPE_EVENT, 0);
                            break;
                        case 5050:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                            m_uiUpdateTimer = 3000;
                            m_pInstance->SetData(TYPE_EVENT, 5060);
                            break;
                        case 5060:
                            DoScriptText(SAY_STAGE_4_05, me);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
                            m_uiUpdateTimer = 2500;
                            m_pInstance->SetData(TYPE_EVENT, 5070);
                            break;
                        case 5070:
                            me->CastSpell(me, 68198, false);
                            m_uiUpdateTimer = 1500;
                            m_pInstance->SetData(TYPE_EVENT, 5080);
                            break;
                        case 5080:
                            if (GameObject* pGoFloor = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(GO_ARGENT_COLISEUM_FLOOR)))
                                pGoFloor->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
                            me->CastSpell(me, 69016, false);
                            if (m_pInstance)
                            {
                                m_pInstance->SetData(TYPE_LICH_KING, DONE);
                                Creature* pTemp = Unit::GetCreature(*me, m_pInstance->GetData64(NPC_ANUBARAK));
                                if (!pTemp || !pTemp->isAlive())
                                    pTemp = me->SummonCreature(NPC_ANUBARAK, AnubarakLoc[0].GetPositionX(), AnubarakLoc[0].GetPositionY(), AnubarakLoc[0].GetPositionZ(), 3, TEMPSUMMON_CORPSE_TIMED_DESPAWN, DESPAWN_TIME);

                                m_pInstance->SetData(TYPE_EVENT, 0);
                            }
                            me->DespawnOrUnsummon();
                            m_uiUpdateTimer = 20000;
                            break;
                    }
                } else m_uiUpdateTimer -= uiDiff;
                m_pInstance->SetData(TYPE_EVENT_TIMER, m_uiUpdateTimer);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_lich_king_tocAI(creature);
        }
};

class npc_fizzlebang_toc : public CreatureScript
{
    public:

        npc_fizzlebang_toc() : CreatureScript("npc_fizzlebang_toc") { }

        struct npc_fizzlebang_tocAI : public ScriptedAI
        {
            npc_fizzlebang_tocAI(Creature* creature) : ScriptedAI(creature), Summons(me)
            {
                m_pInstance = (InstanceScript*)me->GetInstanceScript();
            }

            InstanceScript* m_pInstance;
            SummonList Summons;
            uint32 m_uiUpdateTimer;
            uint64 m_uiPortalGUID;
            uint64 m_uiTriggerGUID;

            void JustDied(Unit* killer)
            {
                DoScriptText(SAY_STAGE_1_06, me, killer);
                m_pInstance->SetData(TYPE_EVENT, 1180);
                if (Creature* pTemp = Unit::GetCreature(*me, m_pInstance->GetData64(NPC_JARAXXUS)))
                {
                    pTemp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    pTemp->SetReactState(REACT_AGGRESSIVE);
                    pTemp->SetInCombatWithZone();
                }
            }

            void Reset()
            {
                me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                m_uiPortalGUID = 0;
                me->GetMotionMaster()->MovePoint(1, ToCCommonLoc[10].GetPositionX(), ToCCommonLoc[10].GetPositionY()-60, ToCCommonLoc[10].GetPositionZ());
            }

            void MovementInform(uint32 uiType, uint32 uiId)
            {
                if (uiType != POINT_MOTION_TYPE) return;

                switch (uiId)
                {
                    case 1:
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        if (m_pInstance)
                        {
                            m_pInstance->DoUseDoorOrButton(m_pInstance->GetData64(GO_MAIN_GATE_DOOR));
                            m_pInstance->SetData(TYPE_EVENT, 1120);
                            m_pInstance->SetData(TYPE_EVENT_TIMER, 1000);
                        }
                        break;
                }
            }

            void JustSummoned(Creature* summoned)
            {
                Summons.Summon(summoned);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!m_pInstance) return;

                if (m_pInstance->GetData(TYPE_EVENT_NPC) != NPC_FIZZLEBANG) return;

                m_uiUpdateTimer = m_pInstance->GetData(TYPE_EVENT_TIMER);
                if (m_uiUpdateTimer <= uiDiff)
                {
                    switch (m_pInstance->GetData(TYPE_EVENT))
                    {
                        case 1110:
                            m_pInstance->SetData(TYPE_EVENT, 1120);
                            m_uiUpdateTimer = 4000;
                            break;
                        case 1120:
                            DoScriptText(SAY_STAGE_1_02, me);
                            m_pInstance->SetData(TYPE_EVENT, 1130);
                            m_uiUpdateTimer = 12000;
                            break;
                        case 1130:
                            me->GetMotionMaster()->MovementExpired();
                            DoScriptText(SAY_STAGE_1_03, me);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_SPELLCAST_OMNI);
                            if (Unit* pTrigger =  me->SummonCreature(NPC_TRIGGER, ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY(), ToCCommonLoc[1].GetPositionZ(), 4.69494f, TEMPSUMMON_MANUAL_DESPAWN))
                            {
                                m_uiTriggerGUID = pTrigger->GetGUID();
                                pTrigger->SetFloatValue(OBJECT_FIELD_SCALE_X, 2.0f);
                                pTrigger->SetDisplayId(22862);
                                pTrigger->CastSpell(pTrigger, SPELL_WILFRED_PORTAL, false);
                            }
                            m_pInstance->SetData(TYPE_EVENT, 1132);
                            m_uiUpdateTimer = 4000;
                            break;
                        case 1132:
                            me->GetMotionMaster()->MovementExpired();
                            m_pInstance->SetData(TYPE_EVENT, 1134);
                            m_uiUpdateTimer = 4000;
                            break;
                        case 1134:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_SPELLCAST_OMNI);
                            if (Creature* pPortal = me->SummonCreature(NPC_WILFRED_PORTAL, ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY(), ToCCommonLoc[1].GetPositionZ(), 4.71239f, TEMPSUMMON_MANUAL_DESPAWN))
                            {
                                pPortal->SetReactState(REACT_PASSIVE);
                                pPortal->SetFloatValue(OBJECT_FIELD_SCALE_X, 2.0f);
                                pPortal->CastSpell(pPortal, SPELL_WILFRED_PORTAL, false);
                                m_uiPortalGUID = pPortal->GetGUID();
                            }
                            m_uiUpdateTimer = 4000;
                            m_pInstance->SetData(TYPE_EVENT, 1135);
                            break;
                        case 1135:
                            m_pInstance->SetData(TYPE_EVENT, 1140);
                            m_uiUpdateTimer = 3000;
                            break;
                        case 1140:
                            DoScriptText(SAY_STAGE_1_04, me);
                            if (Creature* pTemp = me->SummonCreature(NPC_JARAXXUS, ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY(), ToCCommonLoc[1].GetPositionZ(), 5.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, DESPAWN_TIME))
                            {
                                pTemp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                pTemp->SetReactState(REACT_PASSIVE);
                                pTemp->GetMotionMaster()->MovePoint(0, ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY()-10, ToCCommonLoc[1].GetPositionZ());
                            }
                            m_pInstance->SetData(TYPE_EVENT, 1142);
                            m_uiUpdateTimer = 5000;
                            break;
                        case 1142:
                            if (Creature* pTemp = Unit::GetCreature(*me, m_pInstance->GetData64(NPC_JARAXXUS)))
                                pTemp->SetTarget(me->GetGUID());
                            if (Creature* pTrigger = Unit::GetCreature(*me, m_uiTriggerGUID))
                                pTrigger->DespawnOrUnsummon();
                            if (Creature* pPortal = Unit::GetCreature(*me, m_uiPortalGUID))
                                pPortal->DespawnOrUnsummon();
                            m_pInstance->SetData(TYPE_EVENT, 1144);
                            m_uiUpdateTimer = 10000;
                            break;
                        case 1144:
                            if (Creature* pTemp = Unit::GetCreature(*me, m_pInstance->GetData64(NPC_JARAXXUS)))
                                DoScriptText(SAY_STAGE_1_05, pTemp);
                            m_pInstance->SetData(TYPE_EVENT, 1150);
                            m_uiUpdateTimer = 5000;
                            break;
                        case 1150:
                            if (Creature* pTemp = Unit::GetCreature(*me, m_pInstance->GetData64(NPC_JARAXXUS)))
                            {
                                //1-shot Fizzlebang
                                pTemp->CastSpell(me, 67888, false);
                                me->SetInCombatWith(pTemp);
                                pTemp->AddThreat(me, 1000.0f);
                                pTemp->AI()->AttackStart(me);
                            }
                            m_pInstance->SetData(TYPE_EVENT, 1160);
                            m_uiUpdateTimer = 3000;
                            break;
                    }
                } else m_uiUpdateTimer -= uiDiff;
                m_pInstance->SetData(TYPE_EVENT_TIMER, m_uiUpdateTimer);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_fizzlebang_tocAI(creature);
        }
};

class npc_tirion_toc : public CreatureScript
{
    public:

        npc_tirion_toc() : CreatureScript("npc_tirion_toc") { }

        struct npc_tirion_tocAI : public ScriptedAI
        {
            npc_tirion_tocAI(Creature* creature) : ScriptedAI(creature)
            {
                m_pInstance = (InstanceScript*)me->GetInstanceScript();
            }

            InstanceScript* m_pInstance;
            uint32 m_uiUpdateTimer;

            void Reset() {}

            void AttackStart(Unit* /*who*/) {}

            void UpdateAI(const uint32 uiDiff)
            {
                if (!m_pInstance) return;
                if (m_pInstance->GetData(TYPE_EVENT_NPC) != NPC_TIRION) return;

                m_uiUpdateTimer = m_pInstance->GetData(TYPE_EVENT_TIMER);
                if (m_uiUpdateTimer <= uiDiff)
                {
                    switch (m_pInstance->GetData(TYPE_EVENT))
                    {
                        case 110:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK);
                            DoScriptText(SAY_STAGE_0_01, me);
                            m_uiUpdateTimer = 22000;
                            m_pInstance->SetData(TYPE_EVENT, 120);
                            break;
                        case 140:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK);
                            DoScriptText(SAY_STAGE_0_02, me);
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 150);
                            break;
                        case 150:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                            if (m_pInstance->GetData(TYPE_BEASTS) != DONE)
                            {
                                m_pInstance->DoUseDoorOrButton(m_pInstance->GetData64(GO_MAIN_GATE_DOOR));

                                if (Creature* pTemp = me->SummonCreature(NPC_GORMOK, ToCSpawnLoc[0].GetPositionX(), ToCSpawnLoc[0].GetPositionY(), ToCSpawnLoc[0].GetPositionZ(), 5, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30*IN_MILLISECONDS))
                                {
                                    pTemp->GetMotionMaster()->MovePoint(0, ToCCommonLoc[5].GetPositionX(), ToCCommonLoc[5].GetPositionY(), ToCCommonLoc[5].GetPositionZ());
                                    pTemp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                                    pTemp->SetReactState(REACT_PASSIVE);
                                }
                            }
                            m_uiUpdateTimer = 3000;
                            m_pInstance->SetData(TYPE_EVENT, 155);
                            break;
                        case 155:
                            m_pInstance->SetData(TYPE_BEASTS, IN_PROGRESS);
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 160);
                            break;
                        case 200:
                            DoScriptText(SAY_STAGE_0_04, me);
                            m_uiUpdateTimer = 8000;
                            m_pInstance->SetData(TYPE_EVENT, 205);
                            break;
                        case 205:
                            m_uiUpdateTimer = 3000;
                            m_pInstance->SetData(TYPE_EVENT, 210);
                            break;
                        case 210:
                            if (m_pInstance->GetData(TYPE_BEASTS) != DONE)
                            {
                                m_pInstance->DoUseDoorOrButton(m_pInstance->GetData64(GO_MAIN_GATE_DOOR));
                                if (Creature* pTemp = me->SummonCreature(NPC_DREADSCALE, ToCSpawnLoc[1].GetPositionX(), ToCSpawnLoc[1].GetPositionY(), ToCSpawnLoc[1].GetPositionZ(), 5, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    pTemp->GetMotionMaster()->MovePoint(0, ToCCommonLoc[8].GetPositionX(), ToCCommonLoc[8].GetPositionY(), ToCCommonLoc[8].GetPositionZ());
                                    pTemp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                                    pTemp->SetReactState(REACT_PASSIVE);
                                }
                                if (Creature* pTemp = me->SummonCreature(NPC_ACIDMAW, ToCCommonLoc[9].GetPositionX(), ToCCommonLoc[9].GetPositionY(), ToCCommonLoc[9].GetPositionZ(), 5, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    pTemp->SetVisible(true);
                                    pTemp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                                    pTemp->SetReactState(REACT_PASSIVE);
                                }
                            }
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 220);
                            break;
                        case 220:
                            m_pInstance->SetData(TYPE_EVENT, 230);
                            break;
                        case 300:
                            DoScriptText(SAY_STAGE_0_05, me);
                            m_uiUpdateTimer = 8000;
                            m_pInstance->SetData(TYPE_EVENT, 305);
                            break;
                        case 305:
                            m_uiUpdateTimer = 3000;
                            m_pInstance->SetData(TYPE_EVENT, 310);
                            break;
                        case 310:
                            if (m_pInstance->GetData(TYPE_BEASTS) != DONE)
                            {
                                m_pInstance->DoUseDoorOrButton(m_pInstance->GetData64(GO_MAIN_GATE_DOOR));
                                if (Creature* pTemp = me->SummonCreature(NPC_ICEHOWL, ToCSpawnLoc[0].GetPositionX(), ToCSpawnLoc[0].GetPositionY(), ToCSpawnLoc[0].GetPositionZ(), 5, TEMPSUMMON_DEAD_DESPAWN))
                                {
                                    pTemp->GetMotionMaster()->MovePoint(2, ToCCommonLoc[5].GetPositionX(), ToCCommonLoc[5].GetPositionY(), ToCCommonLoc[5].GetPositionZ());
                                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                                    me->SetReactState(REACT_PASSIVE);

                                }
                            }
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 315);
                            break;
                        case 315:
                            m_pInstance->SetData(TYPE_EVENT, 320);
                            break;
                        case 400:
                            DoScriptText(SAY_STAGE_0_06, me);
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 0);
                            break;
                        case 666:
                            DoScriptText(SAY_STAGE_0_WIPE, me);
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 0);
                            break;
                        case 1010:
                            DoScriptText(SAY_STAGE_1_01, me);
                            m_uiUpdateTimer = 7000;
                            m_pInstance->DoUseDoorOrButton(m_pInstance->GetData64(GO_MAIN_GATE_DOOR));
                            me->SummonCreature(NPC_FIZZLEBANG, ToCSpawnLoc[0].GetPositionX(), ToCSpawnLoc[0].GetPositionY(), ToCSpawnLoc[0].GetPositionZ(), 2, TEMPSUMMON_CORPSE_TIMED_DESPAWN, DESPAWN_TIME);
                            m_pInstance->SetData(TYPE_EVENT, 0);
                            break;
                        case 1180:
                            DoScriptText(SAY_STAGE_1_07, me);
                            m_uiUpdateTimer = 3000;
                            m_pInstance->SetData(TYPE_EVENT, 0);
                            break;
                        case 2000:
                            DoScriptText(SAY_STAGE_1_08, me);
                            m_uiUpdateTimer = 18000;
                            m_pInstance->SetData(TYPE_EVENT, 2010);
                            break;
                        case 2030:
                            DoScriptText(SAY_STAGE_1_11, me);
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 0);
                            break;
                        case 3000:
                            DoScriptText(SAY_STAGE_2_01, me);
                            m_uiUpdateTimer = 12000;
                            m_pInstance->SetData(TYPE_EVENT, 3050);
                            break;
                        case 3001:
                            DoScriptText(SAY_STAGE_2_01, me);
                            m_uiUpdateTimer = 12000;
                            m_pInstance->SetData(TYPE_EVENT, 3051);
                            break;
                        case 3060:
                            DoScriptText(SAY_STAGE_2_03, me);
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 3070);
                            break;
                        case 3061:
                            DoScriptText(SAY_STAGE_2_03, me);
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 3071);
                            break;
                        //Summoning crusaders
                        case 3091:
                            if (Creature* pChampionController = me->SummonCreature(NPC_CHAMPIONS_CONTROLLER, ToCCommonLoc[1]))
                                pChampionController->AI()->SetData(0, HORDE);
                            m_uiUpdateTimer = 3000;
                            m_pInstance->SetData(TYPE_EVENT, 3092);
                            break;
                        //Summoning crusaders
                        case 3090:
                            if (Creature* pChampionController = me->SummonCreature(NPC_CHAMPIONS_CONTROLLER, ToCCommonLoc[1]))
                                pChampionController->AI()->SetData(0, ALLIANCE);
                            m_uiUpdateTimer = 3000;
                            m_pInstance->SetData(TYPE_EVENT, 3092);
                            break;
                        case 3092:
                            if (Creature* pChampionController = Unit::GetCreature((*me), m_pInstance->GetData64(NPC_CHAMPIONS_CONTROLLER)))
                                pChampionController->AI()->SetData(1, NOT_STARTED);
                            m_pInstance->SetData(TYPE_EVENT, 3095);
                            break;
                        //Crusaders battle end
                        case 3100:
                            DoScriptText(SAY_STAGE_2_06, me);
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 0);
                            break;
                        case 4000:
                            DoScriptText(SAY_STAGE_3_01, me);
                            m_uiUpdateTimer = 13000;
                            m_pInstance->SetData(TYPE_EVENT, 4010);
                            break;
                        case 4010:
                            DoScriptText(SAY_STAGE_3_02, me);
                            if (Creature* pTemp = me->SummonCreature(NPC_LIGHTBANE, ToCSpawnLoc[1].GetPositionX(), ToCSpawnLoc[1].GetPositionY(), ToCSpawnLoc[1].GetPositionZ(), 5, TEMPSUMMON_CORPSE_TIMED_DESPAWN, DESPAWN_TIME))
                            {
                                pTemp->SetVisible(false);
                                pTemp->SetReactState(REACT_PASSIVE);
                                pTemp->SummonCreature(NPC_LIGHT_ESSENCE, TwinValkyrsLoc[0].GetPositionX(), TwinValkyrsLoc[0].GetPositionY(), TwinValkyrsLoc[0].GetPositionZ());
                                pTemp->SummonCreature(NPC_LIGHT_ESSENCE, TwinValkyrsLoc[1].GetPositionX(), TwinValkyrsLoc[1].GetPositionY(), TwinValkyrsLoc[1].GetPositionZ());
                            }
                            if (Creature* pTemp = me->SummonCreature(NPC_DARKBANE, ToCSpawnLoc[2].GetPositionX(), ToCSpawnLoc[2].GetPositionY(), ToCSpawnLoc[2].GetPositionZ(), 5, TEMPSUMMON_CORPSE_TIMED_DESPAWN, DESPAWN_TIME))
                            {
                                pTemp->SetVisible(false);
                                pTemp->SetReactState(REACT_PASSIVE);
                                pTemp->SummonCreature(NPC_DARK_ESSENCE, TwinValkyrsLoc[2].GetPositionX(), TwinValkyrsLoc[2].GetPositionY(), TwinValkyrsLoc[2].GetPositionZ());
                                pTemp->SummonCreature(NPC_DARK_ESSENCE, TwinValkyrsLoc[3].GetPositionX(), TwinValkyrsLoc[3].GetPositionY(), TwinValkyrsLoc[3].GetPositionZ());
                            }
                            m_uiUpdateTimer = 3000;
                            m_pInstance->SetData(TYPE_EVENT, 4015);
                            break;
                        case 4015:
                            m_pInstance->DoUseDoorOrButton(m_pInstance->GetData64(GO_MAIN_GATE_DOOR));
                            if (Creature* pTemp = Unit::GetCreature((*me), m_pInstance->GetData64(NPC_LIGHTBANE)))
                            {
                                pTemp->GetMotionMaster()->MovePoint(1, ToCCommonLoc[8].GetPositionX(), ToCCommonLoc[8].GetPositionY(), ToCCommonLoc[8].GetPositionZ());
                                pTemp->SetVisible(true);
                            }
                            if (Creature* pTemp = Unit::GetCreature((*me), m_pInstance->GetData64(NPC_DARKBANE)))
                            {
                                pTemp->GetMotionMaster()->MovePoint(1, ToCCommonLoc[9].GetPositionX(), ToCCommonLoc[9].GetPositionY(), ToCCommonLoc[9].GetPositionZ());
                                pTemp->SetVisible(true);
                            }
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 4016);
                            break;
                        case 4016:
                            m_pInstance->SetData(TYPE_EVENT, 4017);
                            break;
                        case 4040:
                            m_uiUpdateTimer = 60000;
                            m_pInstance->SetData(TYPE_EVENT, 5000);
                            break;
                        case 5000:
                            DoScriptText(SAY_STAGE_4_01, me);
                            m_uiUpdateTimer = 10000;
                            m_pInstance->SetData(TYPE_EVENT, 5005);
                            break;
                        case 5005:
                            m_uiUpdateTimer = 8000;
                            m_pInstance->SetData(TYPE_EVENT, 5010);
                            me->SummonCreature(NPC_LICH_KING_1, ToCSpawnLoc[0].GetPositionX(), ToCSpawnLoc[0].GetPositionY(), ToCSpawnLoc[0].GetPositionZ(), 5);
                            break;
                        case 5020:
                            DoScriptText(SAY_STAGE_4_03, me);
                            m_uiUpdateTimer = 1000;
                            m_pInstance->SetData(TYPE_EVENT, 0);
                            break;
                        case 6000:
                            me->NearTeleportTo(AnubarakLoc[0].GetPositionX(), AnubarakLoc[0].GetPositionY(), AnubarakLoc[0].GetPositionZ(), 4.0f);
                            m_uiUpdateTimer = 20000;
                            m_pInstance->SetData(TYPE_EVENT, 6005);
                            break;
                        case 6005:
                            DoScriptText(SAY_STAGE_4_06, me);
                            m_uiUpdateTimer = 20000;
                            m_pInstance->SetData(TYPE_EVENT, 6010);
                            break;
                        case 6010:
                            if (IsHeroic())
                            {
                                DoScriptText(SAY_STAGE_4_07, me);
                                m_uiUpdateTimer = 60000;
                                m_pInstance->SetData(TYPE_ANUBARAK, SPECIAL);
                                m_pInstance->SetData(TYPE_EVENT, 6020);
                            } else m_pInstance->SetData(TYPE_EVENT, 6030);
                            break;
                        case 6020:
                            me->DespawnOrUnsummon();
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 6030);
                            break;
                    }
                } else m_uiUpdateTimer -= uiDiff;
                m_pInstance->SetData(TYPE_EVENT_TIMER, m_uiUpdateTimer);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_tirion_tocAI(creature);
        }
};

class npc_garrosh_toc : public CreatureScript
{
    public:

        npc_garrosh_toc() : CreatureScript("npc_garrosh_toc") { }

        struct npc_garrosh_tocAI : public ScriptedAI
        {
            npc_garrosh_tocAI(Creature* creature) : ScriptedAI(creature)
            {
                m_pInstance = (InstanceScript*)me->GetInstanceScript();
            }

            InstanceScript* m_pInstance;
            uint32 m_uiUpdateTimer;

            void Reset() {}

            void AttackStart(Unit* /*who*/) {}

            void UpdateAI(const uint32 uiDiff)
            {
                if (!m_pInstance) return;
                if (m_pInstance->GetData(TYPE_EVENT_NPC) != NPC_GARROSH) return;

                m_uiUpdateTimer = m_pInstance->GetData(TYPE_EVENT_TIMER);
                if (m_uiUpdateTimer <= uiDiff)
                {
                    switch (m_pInstance->GetData(TYPE_EVENT))
                    {
                        case 130:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK);
                            DoScriptText(SAY_STAGE_0_03h, me);
                            m_uiUpdateTimer = 3000;
                            m_pInstance->SetData(TYPE_EVENT, 132);
                            break;
                        case 132:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 140);
                            break;
                        case 2010:
                            DoScriptText(SAY_STAGE_1_09, me);
                            m_uiUpdateTimer = 9000;
                            m_pInstance->SetData(TYPE_EVENT, 2020);
                            break;
                        case 3050:
                            DoScriptText(SAY_STAGE_2_02h, me);
                            m_uiUpdateTimer = 15000;
                            m_pInstance->SetData(TYPE_EVENT, 3060);
                            break;
                        case 3070:
                            DoScriptText(SAY_STAGE_2_04h, me);
                            m_uiUpdateTimer = 6000;
                            m_pInstance->SetData(TYPE_EVENT, 3080);
                            break;
                        case 3081:
                            DoScriptText(SAY_STAGE_2_05h, me);
                            m_uiUpdateTimer = 3000;
                            m_pInstance->SetData(TYPE_EVENT, 3091);
                            break;
                        case 4030:
                            DoScriptText(SAY_STAGE_3_03h, me);
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 4040);
                            break;
                    }
                } else m_uiUpdateTimer -= uiDiff;
                m_pInstance->SetData(TYPE_EVENT_TIMER, m_uiUpdateTimer);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_garrosh_tocAI(creature);
        }
};

class npc_varian_toc : public CreatureScript
{
    public:

        npc_varian_toc() : CreatureScript("npc_varian_toc") { }

        struct npc_varian_tocAI : public ScriptedAI
        {
            npc_varian_tocAI(Creature* creature) : ScriptedAI(creature)
            {
                m_pInstance = (InstanceScript*)me->GetInstanceScript();
            }

            InstanceScript* m_pInstance;
            uint32 m_uiUpdateTimer;

            void Reset() {}

            void AttackStart(Unit* /*who*/) {}

            void UpdateAI(const uint32 uiDiff)
            {
                if (!m_pInstance) return;
                if (m_pInstance->GetData(TYPE_EVENT_NPC) != NPC_VARIAN) return;

                m_uiUpdateTimer = m_pInstance->GetData(TYPE_EVENT_TIMER);
                if (m_uiUpdateTimer <= uiDiff)
                {
                    switch (m_pInstance->GetData(TYPE_EVENT))
                    {
                        case 120:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK);
                            DoScriptText(SAY_STAGE_0_03a, me);
                            m_uiUpdateTimer = 2000;
                            m_pInstance->SetData(TYPE_EVENT, 122);
                            break;
                        case 122:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                            m_uiUpdateTimer = 3000;
                            m_pInstance->SetData(TYPE_EVENT, 130);
                            break;
                        case 2020:
                            DoScriptText(SAY_STAGE_1_10, me);
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 2030);
                            break;
                        case 3051:
                            DoScriptText(SAY_STAGE_2_02a, me);
                            m_uiUpdateTimer = 10000;
                            m_pInstance->SetData(TYPE_EVENT, 3061);
                            break;
                        case 3071:
                            DoScriptText(SAY_STAGE_2_04a, me);
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 3081);
                            break;
                        case 3080:
                            DoScriptText(SAY_STAGE_2_05a, me);
                            m_uiUpdateTimer = 3000;
                            m_pInstance->SetData(TYPE_EVENT, 3090);
                            break;
                        case 4020:
                            DoScriptText(SAY_STAGE_3_03a, me);
                            m_uiUpdateTimer = 5000;
                            m_pInstance->SetData(TYPE_EVENT, 4040);
                            break;
                    }
                } else m_uiUpdateTimer -= uiDiff;
                m_pInstance->SetData(TYPE_EVENT_TIMER, m_uiUpdateTimer);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_varian_tocAI(creature);
        }
};

void AddSC_trial_of_the_crusader()
{
    new npc_announcer_toc10();
    new boss_lich_king_toc();
    new npc_fizzlebang_toc();
    new npc_tirion_toc();
    new npc_garrosh_toc();
    new npc_varian_toc();
}
