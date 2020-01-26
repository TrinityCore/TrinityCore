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

//Known Bugs:
// - Need better implementation of Gossip and correct gossip text and option

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "TemporarySummon.h"
#include "trial_of_the_crusader.h"

enum Yells
{
    // Highlord Tirion Fordring - 34996
    SAY_STAGE_0_01            = 0,
    SAY_STAGE_0_02            = 1,
    SAY_STAGE_0_04            = 2,
    SAY_STAGE_0_05            = 3,
    SAY_STAGE_0_06            = 4,
    SAY_STAGE_0_WIPE          = 5,
    SAY_STAGE_1_01            = 6,
    SAY_STAGE_1_07            = 7,
    SAY_STAGE_1_08            = 8,
    SAY_STAGE_1_11            = 9,
    SAY_STAGE_2_01            = 10,
    SAY_STAGE_2_03            = 11,
    SAY_STAGE_2_06            = 12,
    SAY_STAGE_3_01            = 13,
    SAY_STAGE_3_02            = 14,
    SAY_STAGE_4_01            = 15,
    SAY_STAGE_4_03            = 16,

    // Varian Wrynn
    SAY_STAGE_0_03a           = 0,
    SAY_STAGE_1_10            = 1,
    SAY_STAGE_2_02a           = 2,
    SAY_STAGE_2_04a           = 3,
    SAY_STAGE_2_05a           = 4,
    SAY_STAGE_3_03a           = 5,

    // Garrosh
    SAY_STAGE_0_03h           = 0,
    SAY_STAGE_1_09            = 1,
    SAY_STAGE_2_02h           = 2,
    SAY_STAGE_2_04h           = 3,
    SAY_STAGE_2_05h           = 4,
    SAY_STAGE_3_03h           = 5,

    // Wilfred Fizzlebang
    SAY_STAGE_1_02            = 0,
    SAY_STAGE_1_03            = 1,
    SAY_STAGE_1_04            = 2,
    SAY_STAGE_1_06            = 3,

    // Lord Jaraxxus
    SAY_STAGE_1_05            = 0,

    //  The Lich King
    SAY_STAGE_4_02            = 0,
    SAY_STAGE_4_05            = 1,
    SAY_STAGE_4_04            = 2,

    // Highlord Tirion Fordring - 36095
    SAY_STAGE_4_06            = 0,
    SAY_STAGE_4_07            = 1
};

Position const ToCSpawnLoc[] =
{
    { 563.912f, 261.625f, 394.73f, 4.70437f },  //  0 Center
    { 575.451f, 261.496f, 394.73f,  4.6541f },  //  1 Left
    { 549.951f,  261.55f, 394.73f, 4.74835f }   //  2 Right
};

Position const ToCCommonLoc[23] =
{
    { 559.257996f, 90.266197f, 395.122986f, 0 },  //  0 Barrent

    { 563.672974f, 139.571f, 393.837006f, 0 },    //  1 Center
    { 563.833008f, 187.244995f, 394.5f, 0 },      //  2 Backdoor
    { 577.347839f, 195.338888f, 395.14f, 0 },     //  3 - Right
    { 550.955933f, 195.338888f, 395.14f, 0 },     //  4 - Left
    { 563.833008f, 195.244995f, 394.585561f, 0 }, //  5 - Center
    { 573.5f, 180.5f, 395.14f, 0 },               //  6 Move 0 Right
    { 553.5f, 180.5f, 395.14f, 0 },               //  7 Move 0 Left
    { 573.0f, 170.0f, 395.14f, 0 },               //  8 Move 1 Right
    { 555.5f, 170.0f, 395.14f, 0 },               //  9 Move 1 Left
    { 563.8f, 216.1f, 395.1f, 0 },                // 10 Behind the door

    { 575.042358f, 195.260727f, 395.137146f, 0 }, // 5
    { 552.248901f, 195.331955f, 395.132658f, 0 }, // 6
    { 573.342285f, 195.515823f, 395.135956f, 0 }, // 7
    { 554.239929f, 195.825577f, 395.137909f, 0 }, // 8
    { 571.042358f, 195.260727f, 395.137146f, 0 }, // 9
    { 556.720581f, 195.015472f, 395.132658f, 0 }, // 10
    { 569.534119f, 195.214478f, 395.139526f, 0 }, // 11
    { 569.231201f, 195.941071f, 395.139526f, 0 }, // 12
    { 558.811610f, 195.985779f, 394.671661f, 0 }, // 13
    { 567.641724f, 195.351501f, 394.659943f, 0 }, // 14
    { 560.633972f, 195.391708f, 395.137543f, 0 }, // 15
    { 565.816956f, 195.477921f, 395.136810f, 0 }  // 16
};

Position const TwinValkyrsLoc[] =
{
    { 586.060242f, 117.514809f, 394.41f, 0 }, // 0 - Dark essence 1
    { 541.602112f, 161.879837f, 394.41f, 0 }, // 1 - Dark essence 2
    { 541.021118f, 117.262932f, 394.41f, 0 }, // 2 - Light essence 1
    { 586.200562f, 162.145523f, 394.41f, 0 }  // 3 - Light essence 2
};

Position const LichKingLoc[] =
{
    { 563.549f, 152.474f, 394.393f, 0 },          // 0 - Lich king start
    { 563.547f, 141.613f, 393.908f, 0 }           // 1 - Lich king end
};

Position const AnubarakLoc[6] =
{
    { 783.9305f, 132.9722f, 142.6711f, 3.141593f }, // 0 - Anub'arak Spawn Location (sniffed)
    { 695.240051f, 137.834824f, 142.200000f, 0 },  // 1 - Anub'arak move point location
    { 694.886353f, 102.484665f, 142.119614f, 0 },  // 3 - Nerub Spawn
    { 694.500671f, 185.363968f, 142.117905f, 0 },  // 5 - Nerub Spawn
    { 731.987244f, 83.3824690f, 142.119614f, 0 },  // 2 - Nerub Spawn
    { 740.184509f, 193.443390f, 142.117584f, 0 }   // 4 - Nerub Spawn
};

Position const EndSpawnLoc[] =
{
    { 648.9167f, 131.0208f, 141.6161f, 0.f }, // 0 - Highlord Tirion Fordring
    { 649.1614f, 142.0399f, 141.3057f, 0.f }, // 1 - Argent Mage
    { 644.6250f, 149.2743f, 140.6015f, 5.f }  // 2 - Portal to Dalaran
};

struct _Messages
{
    AnnouncerMessages msgnum;
    uint32 id;
    bool state;
    uint32 encounter;
};

static _Messages _GossipMessage[]=
{
    {MSG_BEASTS, GOSSIP_ACTION_INFO_DEF + 1, false, BOSS_BEASTS},
    {MSG_JARAXXUS, GOSSIP_ACTION_INFO_DEF + 2, false, BOSS_JARAXXUS},
    {MSG_CRUSADERS, GOSSIP_ACTION_INFO_DEF + 3, false, BOSS_CRUSADERS},
    {MSG_VALKIRIES, GOSSIP_ACTION_INFO_DEF + 4, false, BOSS_VALKIRIES},
    {MSG_LICH_KING, GOSSIP_ACTION_INFO_DEF + 5, false, BOSS_ANUBARAK},
    {MSG_ANUBARAK, GOSSIP_ACTION_INFO_DEF + 6, true, BOSS_ANUBARAK}
};

enum Messages
{
    NUM_MESSAGES = 6
};

class npc_announcer_toc10 : public CreatureScript
{
    public:
        npc_announcer_toc10() : CreatureScript("npc_announcer_toc10") { }

        struct npc_announcer_toc10AI : public ScriptedAI
        {
            npc_announcer_toc10AI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                if (Creature* pAlly = GetClosestCreatureWithEntry(me, NPC_THRALL, 300.0f))
                    pAlly->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                if (Creature* pAlly = GetClosestCreatureWithEntry(me, NPC_PROUDMOORE, 300.0f))
                    pAlly->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            }

            void AttackStart(Unit* /*who*/) override { }
        };

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            InstanceScript* instance = creature->GetInstanceScript();
            if (!instance)
                return true;

            char const* _message = "We are ready!";

            if (player->IsInCombat() || instance->IsEncounterInProgress())
                return true;

            uint8 i = 0;
            for (; i < NUM_MESSAGES; ++i)
            {
                if ((!_GossipMessage[i].state && instance->GetBossState(_GossipMessage[i].encounter) != DONE)
                    || (_GossipMessage[i].state && instance->GetBossState(_GossipMessage[i].encounter) == DONE))
                {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, _message, GOSSIP_SENDER_MAIN, _GossipMessage[i].id);
                    break;
                }
            }

            if (i >= NUM_MESSAGES)
                return false;

            SendGossipMenuFor(player, _GossipMessage[i].msgnum, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
        {
            ClearGossipMenuFor(player);
            CloseGossipMenuFor(player);
            InstanceScript* instance = creature->GetInstanceScript();
            if (!instance)
                return true;

            if (instance->GetBossState(BOSS_BEASTS) != DONE)
            {
                instance->SetData(TYPE_EVENT, 110);
                instance->SetData(TYPE_NORTHREND_BEASTS, NOT_STARTED);
                instance->SetBossState(BOSS_BEASTS, NOT_STARTED);
            }
            else if (instance->GetBossState(BOSS_JARAXXUS) != DONE)
            {
                // if Jaraxxus is spawned, but the raid wiped
                if (Creature* jaraxxus = ObjectAccessor::GetCreature(*player, instance->GetGuidData(NPC_JARAXXUS)))
                {
                    jaraxxus->RemoveAurasDueToSpell(SPELL_JARAXXUS_CHAINS);
                    jaraxxus->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
                    jaraxxus->SetReactState(REACT_DEFENSIVE);
                    jaraxxus->SetInCombatWithZone();
                }
                else
                {
                    instance->SetData(TYPE_EVENT, 1010);
                    instance->SetBossState(BOSS_JARAXXUS, NOT_STARTED);
                }
            }
            else if (instance->GetBossState(BOSS_CRUSADERS) != DONE)
            {
                if (player->GetTeam() == ALLIANCE)
                    instance->SetData(TYPE_EVENT, 3000);
                else
                    instance->SetData(TYPE_EVENT, 3001);
                instance->SetBossState(BOSS_CRUSADERS, NOT_STARTED);
            }
            else if (instance->GetBossState(BOSS_VALKIRIES) != DONE)
            {
                instance->SetData(TYPE_EVENT, 4000);
                instance->SetBossState(BOSS_VALKIRIES, NOT_STARTED);
            }
            else if (instance->GetBossState(BOSS_LICH_KING) != DONE)
            {
                if (creature->GetMap()->GetPlayers().getFirst()->GetSource()->GetTeam() == ALLIANCE)
                    instance->SetData(TYPE_EVENT, 4020);
                else
                    instance->SetData(TYPE_EVENT, 4030);
                instance->SetBossState(BOSS_LICH_KING, NOT_STARTED);
            }
            creature->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            return true;
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_announcer_toc10AI>(creature);
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
                _instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                if (Creature* summoned = me->SummonCreature(NPC_TRIGGER, ToCCommonLoc[2].GetPositionX(), ToCCommonLoc[2].GetPositionY(), ToCCommonLoc[2].GetPositionZ(), 5, TEMPSUMMON_TIMED_DESPAWN, 1*MINUTE*IN_MILLISECONDS))
                {
                    summoned->CastSpell(summoned, 51807, false);
                    summoned->SetDisplayFromModel(1);
                }

                _instance->SetBossState(BOSS_LICH_KING, IN_PROGRESS);
                me->SetWalk(true);
            }

            void MovementInform(uint32 uiType, uint32 uiId) override
            {
                if (uiType != POINT_MOTION_TYPE || !_instance)
                    return;

                switch (uiId)
                {
                    case 0:
                        _instance->SetData(TYPE_EVENT, 5030);
                        break;
                    case 1:
                        _instance->SetData(TYPE_EVENT, 5050);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 uiDiff) override
            {
                if (!_instance)
                    return;

                if (_instance->GetData(TYPE_EVENT_NPC) != NPC_LICH_KING)
                    return;

                uint32 _updateTimer = _instance->GetData(TYPE_EVENT_TIMER);
                if (_updateTimer <= uiDiff)
                {
                    switch (_instance->GetData(TYPE_EVENT))
                    {
                        case 5010:
                            Talk(SAY_STAGE_4_02);
                            _updateTimer = 3*IN_MILLISECONDS;
                            me->GetMotionMaster()->MovePoint(0, LichKingLoc[0]);
                            _instance->SetData(TYPE_EVENT, 5020);
                            break;
                        case 5030:
                            Talk(SAY_STAGE_4_04);
                            me->SetEmoteState(EMOTE_STATE_TALK);
                            _updateTimer = 10*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 5040);
                            break;
                        case 5040:
                            me->SetEmoteState(EMOTE_ONESHOT_NONE);
                            me->GetMotionMaster()->MovePoint(1, LichKingLoc[1]);
                            _updateTimer = 1*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 0);
                            break;
                        case 5050:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                            _updateTimer = 3*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 5060);
                            break;
                        case 5060:
                            Talk(SAY_STAGE_4_05);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
                            _updateTimer = 2.5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 5070);
                            break;
                        case 5070:
                            me->CastSpell(me, 68198, false);
                            _updateTimer = 1.5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 5080);
                            break;
                        case 5080:
                        {
                            if (GameObject* go = ObjectAccessor::GetGameObject(*me, _instance->GetGuidData(GO_ARGENT_COLISEUM_FLOOR)))
                                go->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);

                            me->CastSpell(me, SPELL_CORPSE_TELEPORT, false);
                            me->CastSpell(me, SPELL_DESTROY_FLOOR_KNOCKUP, false);

                            _instance->SetBossState(BOSS_LICH_KING, DONE);

                            if (!ObjectAccessor::GetCreature(*me, _instance->GetGuidData(NPC_ANUBARAK)))
                                me->SummonCreature(NPC_ANUBARAK, AnubarakLoc[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, DESPAWN_TIME);

                            _instance->SetData(TYPE_EVENT, 0);

                            me->DespawnOrUnsummon();
                            _updateTimer = 20*IN_MILLISECONDS;
                            break;
                        }
                        default:
                            break;
                    }
                }
                else
                    _updateTimer -= uiDiff;

                _instance->SetData(TYPE_EVENT_TIMER, _updateTimer);
            }

            private:
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<boss_lich_king_tocAI>(creature);
        }
};

class npc_fizzlebang_toc : public CreatureScript
{
    public:
        npc_fizzlebang_toc() : CreatureScript("npc_fizzlebang_toc") { }

        struct npc_fizzlebang_tocAI : public ScriptedAI
        {
            npc_fizzlebang_tocAI(Creature* creature) : ScriptedAI(creature), _summons(me)
            {
                _instance = me->GetInstanceScript();
            }

            void JustDied(Unit* killer) override
            {
                Talk(SAY_STAGE_1_06, killer);
                _instance->SetData(TYPE_EVENT, 1180);
                if (Creature* jaraxxus = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(NPC_JARAXXUS)))
                {
                    jaraxxus->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
                    jaraxxus->SetReactState(REACT_AGGRESSIVE);
                    jaraxxus->SetInCombatWithZone();
                }
            }

            void Reset() override
            {
                _portalGUID.Clear();
                me->SetWalk(true);
                me->GetMotionMaster()->MovePoint(1, ToCCommonLoc[10].GetPositionX(), ToCCommonLoc[10].GetPositionY()-60, ToCCommonLoc[10].GetPositionZ());
            }

            void MovementInform(uint32 uiType, uint32 uiId) override
            {
                if (uiType != POINT_MOTION_TYPE)
                    return;

                switch (uiId)
                {
                    case 1:
                        me->SetWalk(false);
                        _instance->DoUseDoorOrButton(_instance->GetGuidData(GO_MAIN_GATE_DOOR));
                        _instance->SetData(TYPE_EVENT, 1120);
                        _instance->SetData(TYPE_EVENT_TIMER, 1*IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summoned) override
            {
                _summons.Summon(summoned);
            }

            void UpdateAI(uint32 uiDiff) override
            {
                if (!_instance)
                    return;

                if (_instance->GetData(TYPE_EVENT_NPC) != NPC_FIZZLEBANG)
                    return;

                uint32 _updateTimer = _instance->GetData(TYPE_EVENT_TIMER);
                if (_updateTimer <= uiDiff)
                {
                    switch (_instance->GetData(TYPE_EVENT))
                    {
                        case 1110:
                            _instance->SetData(TYPE_EVENT, 1120);
                            _updateTimer = 4*IN_MILLISECONDS;
                            break;
                        case 1120:
                            Talk(SAY_STAGE_1_02);
                            _instance->SetData(TYPE_EVENT, 1130);
                            _updateTimer = 12*IN_MILLISECONDS;
                            break;
                        case 1130:
                            me->GetMotionMaster()->MovementExpired();
                            Talk(SAY_STAGE_1_03);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_SPELL_CAST_OMNI);
                            if (Creature* pTrigger = me->SummonCreature(NPC_TRIGGER, ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY(), ToCCommonLoc[1].GetPositionZ(), 4.69494f, TEMPSUMMON_MANUAL_DESPAWN))
                            {
                                _triggerGUID = pTrigger->GetGUID();
                                pTrigger->SetObjectScale(2.0f);
                                pTrigger->SetDisplayFromModel(0);
                                pTrigger->CastSpell(pTrigger, SPELL_WILFRED_PORTAL, false);
                            }
                            _instance->SetData(TYPE_EVENT, 1132);
                            _updateTimer = 4*IN_MILLISECONDS;
                            break;
                        case 1132:
                            me->GetMotionMaster()->MovementExpired();
                            _instance->SetData(TYPE_EVENT, 1134);
                            _updateTimer = 4*IN_MILLISECONDS;
                            break;
                        case 1134:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_SPELL_CAST_OMNI);
                            if (Creature* pPortal = me->SummonCreature(NPC_WILFRED_PORTAL, ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY(), ToCCommonLoc[1].GetPositionZ(), 4.71239f, TEMPSUMMON_MANUAL_DESPAWN))
                            {
                                pPortal->SetReactState(REACT_PASSIVE);
                                pPortal->SetObjectScale(2.0f);
                                pPortal->CastSpell(pPortal, SPELL_WILFRED_PORTAL, false);
                                _portalGUID = pPortal->GetGUID();
                            }
                            _updateTimer = 4*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 1135);
                            break;
                        case 1135:
                            _instance->SetData(TYPE_EVENT, 1140);
                            _updateTimer = 3*IN_MILLISECONDS;
                            break;
                        case 1140:
                            Talk(SAY_STAGE_1_04);
                            if (Creature* jaraxxus = me->SummonCreature(NPC_JARAXXUS, ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY(), ToCCommonLoc[1].GetPositionZ(), 5.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, DESPAWN_TIME))
                            {
                                jaraxxus->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
                                jaraxxus->SetReactState(REACT_PASSIVE);
                                jaraxxus->GetMotionMaster()->MovePoint(0, ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY()-10, ToCCommonLoc[1].GetPositionZ());
                            }
                            _instance->SetData(TYPE_EVENT, 1142);
                            _updateTimer = 5*IN_MILLISECONDS;
                            break;
                        case 1142:
                            if (Creature* jaraxxus = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(NPC_JARAXXUS)))
                                jaraxxus->SetTarget(me->GetGUID());
                            if (Creature* pTrigger = ObjectAccessor::GetCreature(*me, _triggerGUID))
                                pTrigger->DespawnOrUnsummon();
                            if (Creature* pPortal = ObjectAccessor::GetCreature(*me, _portalGUID))
                                pPortal->DespawnOrUnsummon();
                            _instance->SetData(TYPE_EVENT, 1144);
                            _updateTimer = 10*IN_MILLISECONDS;
                            break;
                        case 1144:
                            if (Creature* jaraxxus = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(NPC_JARAXXUS)))
                                jaraxxus->AI()->Talk(SAY_STAGE_1_05);
                            _instance->SetData(TYPE_EVENT, 1150);
                            _updateTimer = 5*IN_MILLISECONDS;
                            break;
                        case 1150:
                            if (Creature* jaraxxus = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(NPC_JARAXXUS)))
                            {
                                //1-shot Fizzlebang
                                jaraxxus->CastSpell(me, 67888, false); // 67888 - Fel Lightning
                                me->SetInCombatWith(jaraxxus);
                                jaraxxus->AddThreat(me, 1000.0f);
                                jaraxxus->AI()->AttackStart(me);
                            }
                            _instance->SetData(TYPE_EVENT, 1160);
                            _updateTimer = 3*IN_MILLISECONDS;
                            break;
                    }
                }
                else
                    _updateTimer -= uiDiff;
                _instance->SetData(TYPE_EVENT_TIMER, _updateTimer);
            }

            private:
                InstanceScript* _instance;
                SummonList _summons;
                ObjectGuid _portalGUID;
                ObjectGuid _triggerGUID;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_fizzlebang_tocAI>(creature);
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
                _instance = me->GetInstanceScript();
            }

            void Reset() override { }

            void AttackStart(Unit* /*who*/) override { }

            void UpdateAI(uint32 uiDiff) override
            {
                if (!_instance)
                    return;

                if (_instance->GetData(TYPE_EVENT_NPC) != NPC_TIRION)
                    return;

                uint32 _updateTimer = _instance->GetData(TYPE_EVENT_TIMER);
                if (_updateTimer <= uiDiff)
                {
                    switch (_instance->GetData(TYPE_EVENT))
                    {
                        case 110:
                            me->SetEmoteState(EMOTE_ONESHOT_TALK);
                            Talk(SAY_STAGE_0_01);
                            _updateTimer = 22*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 120);
                            break;
                        case 140:
                            me->SetEmoteState(EMOTE_ONESHOT_TALK);
                            Talk(SAY_STAGE_0_02);
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 150);
                            break;
                        case 150:
                            me->SetEmoteState(EMOTE_STATE_NONE);
                            if (_instance->GetBossState(BOSS_BEASTS) != DONE)
                            {
                                _instance->DoUseDoorOrButton(_instance->GetGuidData(GO_MAIN_GATE_DOOR));

                                if (Creature* gormok = me->SummonCreature(NPC_GORMOK, ToCSpawnLoc[0].GetPositionX(), ToCSpawnLoc[0].GetPositionY(), ToCSpawnLoc[0].GetPositionZ(), 5, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30*IN_MILLISECONDS))
                                {
                                    gormok->GetMotionMaster()->MovePoint(0, ToCCommonLoc[5].GetPositionX(), ToCCommonLoc[5].GetPositionY(), ToCCommonLoc[5].GetPositionZ());
                                    gormok->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                                    gormok->SetReactState(REACT_PASSIVE);
                                }
                            }
                            _updateTimer = 3*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 155);
                            break;
                        case 155:
                            // keep the raid in combat for the whole encounter, pauses included
                            me->SetInCombatWithZone();
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 160);
                            break;
                        case 200:
                            Talk(SAY_STAGE_0_04);
                            if (_instance->GetBossState(BOSS_BEASTS) != DONE)
                            {
                                _instance->DoUseDoorOrButton(_instance->GetGuidData(GO_MAIN_GATE_DOOR));
                                if (Creature* dreadscale = me->SummonCreature(NPC_DREADSCALE, ToCSpawnLoc[1].GetPositionX(), ToCSpawnLoc[1].GetPositionY(), ToCSpawnLoc[1].GetPositionZ(), 5, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    dreadscale->GetMotionMaster()->MovePoint(0, ToCCommonLoc[5].GetPositionX(), ToCCommonLoc[5].GetPositionY(), ToCCommonLoc[5].GetPositionZ());
                                    dreadscale->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                                    dreadscale->SetReactState(REACT_PASSIVE);
                                }
                            }
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 220);
                            break;
                        case 220:
                            _instance->SetData(TYPE_EVENT, 230);
                            break;
                        case 300:
                            Talk(SAY_STAGE_0_05);
                            if (_instance->GetBossState(BOSS_BEASTS) != DONE)
                            {
                                _instance->DoUseDoorOrButton(_instance->GetGuidData(GO_MAIN_GATE_DOOR));
                                if (Creature* icehowl = me->SummonCreature(NPC_ICEHOWL, ToCSpawnLoc[0].GetPositionX(), ToCSpawnLoc[0].GetPositionY(), ToCSpawnLoc[0].GetPositionZ(), 5, TEMPSUMMON_DEAD_DESPAWN))
                                {
                                    icehowl->GetMotionMaster()->MovePoint(2, ToCCommonLoc[5].GetPositionX(), ToCCommonLoc[5].GetPositionY(), ToCCommonLoc[5].GetPositionZ());
                                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                                    me->SetReactState(REACT_PASSIVE);
                                }
                            }
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 315);
                            break;
                        case 315:
                            _instance->SetData(TYPE_EVENT, 320);
                            break;
                        case 400:
                            Talk(SAY_STAGE_0_06);
                            me->getThreatManager().clearReferences();
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 0);
                            break;
                        case 666:
                            Talk(SAY_STAGE_0_WIPE);
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 0);
                            break;
                        case 1010:
                            Talk(SAY_STAGE_1_01);
                            _updateTimer = 7*IN_MILLISECONDS;
                            _instance->DoUseDoorOrButton(_instance->GetGuidData(GO_MAIN_GATE_DOOR));
                            me->SummonCreature(NPC_FIZZLEBANG, ToCSpawnLoc[0].GetPositionX(), ToCSpawnLoc[0].GetPositionY(), ToCSpawnLoc[0].GetPositionZ(), 2, TEMPSUMMON_CORPSE_TIMED_DESPAWN, DESPAWN_TIME);
                            _instance->SetData(TYPE_EVENT, 0);
                            break;
                        case 1180:
                            Talk(SAY_STAGE_1_07);
                            _updateTimer = 3*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 0);
                            break;
                        case 2000:
                            Talk(SAY_STAGE_1_08);
                            _updateTimer = 18*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 2010);
                            break;
                        case 2030:
                            Talk(SAY_STAGE_1_11);
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 0);
                            break;
                        case 3000:
                            Talk(SAY_STAGE_2_01);
                            _updateTimer = 12*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 3050);
                            break;
                        case 3001:
                            Talk(SAY_STAGE_2_01);
                            _updateTimer = 10*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 3051);
                            break;
                        case 3060:
                            Talk(SAY_STAGE_2_03);
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 3070);
                            break;
                        case 3061:
                            Talk(SAY_STAGE_2_03);
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 3071);
                            break;
                        //Summoning crusaders
                        case 3091:
                            if (Creature* pChampionController = me->SummonCreature(NPC_CHAMPIONS_CONTROLLER, ToCCommonLoc[1]))
                                pChampionController->AI()->SetData(0, HORDE);
                            _updateTimer = 3*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 3092);
                            break;
                        //Summoning crusaders
                        case 3090:
                            if (Creature* pChampionController = me->SummonCreature(NPC_CHAMPIONS_CONTROLLER, ToCCommonLoc[1]))
                                pChampionController->AI()->SetData(0, ALLIANCE);
                            _updateTimer = 3*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 3092);
                            break;
                        case 3092:
                            if (Creature* pChampionController = ObjectAccessor::GetCreature((*me), _instance->GetGuidData(NPC_CHAMPIONS_CONTROLLER)))
                                pChampionController->AI()->SetData(1, NOT_STARTED);
                            _instance->SetData(TYPE_EVENT, 3095);
                            break;
                        //Crusaders battle end
                        case 3100:
                            Talk(SAY_STAGE_2_06);
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 0);
                            break;
                        case 4000:
                            Talk(SAY_STAGE_3_01);
                            _updateTimer = 13*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 4010);
                            break;
                        case 4010:
                            Talk(SAY_STAGE_3_02);
                            if (Creature* lightbane = me->SummonCreature(NPC_LIGHTBANE, ToCSpawnLoc[1].GetPositionX(), ToCSpawnLoc[1].GetPositionY(), ToCSpawnLoc[1].GetPositionZ(), 5, TEMPSUMMON_CORPSE_TIMED_DESPAWN, DESPAWN_TIME))
                            {
                                lightbane->SetVisible(false);
                                lightbane->SetReactState(REACT_PASSIVE);
                                lightbane->SummonCreature(NPC_LIGHT_ESSENCE, TwinValkyrsLoc[0].GetPositionX(), TwinValkyrsLoc[0].GetPositionY(), TwinValkyrsLoc[0].GetPositionZ());
                                lightbane->SummonCreature(NPC_LIGHT_ESSENCE, TwinValkyrsLoc[1].GetPositionX(), TwinValkyrsLoc[1].GetPositionY(), TwinValkyrsLoc[1].GetPositionZ());
                            }
                            if (Creature* darkbane = me->SummonCreature(NPC_DARKBANE, ToCSpawnLoc[2].GetPositionX(), ToCSpawnLoc[2].GetPositionY(), ToCSpawnLoc[2].GetPositionZ(), 5, TEMPSUMMON_CORPSE_TIMED_DESPAWN, DESPAWN_TIME))
                            {
                                darkbane->SetVisible(false);
                                darkbane->SetReactState(REACT_PASSIVE);
                                darkbane->SummonCreature(NPC_DARK_ESSENCE, TwinValkyrsLoc[2].GetPositionX(), TwinValkyrsLoc[2].GetPositionY(), TwinValkyrsLoc[2].GetPositionZ());
                                darkbane->SummonCreature(NPC_DARK_ESSENCE, TwinValkyrsLoc[3].GetPositionX(), TwinValkyrsLoc[3].GetPositionY(), TwinValkyrsLoc[3].GetPositionZ());
                            }
                            _updateTimer = 3*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 4015);
                            break;
                        case 4015:
                            _instance->DoUseDoorOrButton(_instance->GetGuidData(GO_MAIN_GATE_DOOR));
                            if (Creature* lightbane = ObjectAccessor::GetCreature((*me), _instance->GetGuidData(NPC_LIGHTBANE)))
                            {
                                lightbane->GetMotionMaster()->MovePoint(1, ToCCommonLoc[8].GetPositionX(), ToCCommonLoc[8].GetPositionY(), ToCCommonLoc[8].GetPositionZ());
                                lightbane->SetVisible(true);
                            }
                            if (Creature* darkbane = ObjectAccessor::GetCreature((*me), _instance->GetGuidData(NPC_DARKBANE)))
                            {
                                darkbane->GetMotionMaster()->MovePoint(1, ToCCommonLoc[9].GetPositionX(), ToCCommonLoc[9].GetPositionY(), ToCCommonLoc[9].GetPositionZ());
                                darkbane->SetVisible(true);
                            }
                            _updateTimer = 10*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 4016);
                            break;
                        case 4016:
                            _instance->DoUseDoorOrButton(_instance->GetGuidData(GO_MAIN_GATE_DOOR));
                            _instance->SetData(TYPE_EVENT, 4017);
                            break;
                        case 4040:
                            _updateTimer = 1*MINUTE*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 5000);
                            break;
                        case 5000:
                            Talk(SAY_STAGE_4_01);
                            _updateTimer = 10*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 5005);
                            break;
                        case 5005:
                            _updateTimer = 8*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 5010);
                            me->SummonCreature(NPC_LICH_KING, ToCCommonLoc[2].GetPositionX(), ToCCommonLoc[2].GetPositionY(), ToCCommonLoc[2].GetPositionZ(), 5);
                            break;
                        case 5020:
                            Talk(SAY_STAGE_4_03);
                            _updateTimer = 1*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 0);
                            break;
                        case 6000:
                            me->SummonCreature(NPC_TIRION_FORDRING, EndSpawnLoc[0]);
                            me->SummonCreature(NPC_ARGENT_MAGE, EndSpawnLoc[1]);
                            me->SummonGameObject(GO_PORTAL_TO_DALARAN, EndSpawnLoc[2], QuaternionData::fromEulerAnglesZYX(EndSpawnLoc[2].GetOrientation(), 0.0f, 0.0f), 0);
                            _updateTimer = 20*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 6005);
                            break;
                        case 6005:
                            if (Creature* tirionFordring = ObjectAccessor::GetCreature((*me), _instance->GetGuidData(NPC_TIRION_FORDRING)))
                                tirionFordring->AI()->Talk(SAY_STAGE_4_06);
                            _updateTimer = 20*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 6010);
                            break;
                        case 6010:
                            if (IsHeroic())
                            {
                                if (Creature* tirionFordring = ObjectAccessor::GetCreature((*me), _instance->GetGuidData(NPC_TIRION_FORDRING)))
                                    tirionFordring->AI()->Talk(SAY_STAGE_4_07);
                                _updateTimer = 1*MINUTE*IN_MILLISECONDS;
                                _instance->SetBossState(BOSS_ANUBARAK, SPECIAL);
                                _instance->SetData(TYPE_EVENT, 6020);
                            }
                            else
                                _instance->SetData(TYPE_EVENT, 6030);
                            break;
                        case 6020:
                            me->DespawnOrUnsummon();
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 6030);
                            break;
                        default:
                            break;
                    }
                }
                else
                    _updateTimer -= uiDiff;
                _instance->SetData(TYPE_EVENT_TIMER, _updateTimer);
            }
            private:
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_tirion_tocAI>(creature);
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
                _instance = me->GetInstanceScript();
            }

            void Reset() override { }

            void AttackStart(Unit* /*who*/) override { }

            void UpdateAI(uint32 uiDiff) override
            {
                if (!_instance)
                    return;

                if (_instance->GetData(TYPE_EVENT_NPC) != NPC_GARROSH)
                    return;

                uint32 _updateTimer = _instance->GetData(TYPE_EVENT_TIMER);
                if (_updateTimer <= uiDiff)
                {
                    switch (_instance->GetData(TYPE_EVENT))
                    {
                        case 130:
                            me->SetEmoteState(EMOTE_ONESHOT_TALK);
                            Talk(SAY_STAGE_0_03h);
                            _updateTimer = 3*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 132);
                            break;
                        case 132:
                            me->SetEmoteState(EMOTE_STATE_NONE);
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 140);
                            break;
                        case 2010:
                            Talk(SAY_STAGE_1_09);
                            _updateTimer = 9*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 2020);
                            break;
                        case 3050:
                            Talk(SAY_STAGE_2_02h);
                            _updateTimer = 15*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 3060);
                            break;
                        case 3070:
                            Talk(SAY_STAGE_2_04h);
                            _updateTimer = 6*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 3080);
                            break;
                        case 3081:
                            Talk(SAY_STAGE_2_05h);
                            _updateTimer = 3*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 3091);
                            break;
                        case 4030:
                            Talk(SAY_STAGE_3_03h);
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 4040);
                            break;
                        default:
                            break;
                    }
                }
                else
                    _updateTimer -= uiDiff;
                _instance->SetData(TYPE_EVENT_TIMER, _updateTimer);
            }
            private:
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_garrosh_tocAI>(creature);
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
                _instance = me->GetInstanceScript();
            }

            void Reset() override { }

            void AttackStart(Unit* /*who*/) override { }

            void UpdateAI(uint32 uiDiff) override
            {
                if (!_instance)
                    return;

                if (_instance->GetData(TYPE_EVENT_NPC) != NPC_VARIAN)
                    return;

                uint32 _updateTimer = _instance->GetData(TYPE_EVENT_TIMER);
                if (_updateTimer <= uiDiff)
                {
                    switch (_instance->GetData(TYPE_EVENT))
                    {
                        case 120:
                            me->SetEmoteState(EMOTE_ONESHOT_TALK);
                            Talk(SAY_STAGE_0_03a);
                            _updateTimer = 2*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 122);
                            break;
                        case 122:
                            me->SetEmoteState(EMOTE_STATE_NONE);
                            _updateTimer = 3*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 130);
                            break;
                        case 2020:
                            Talk(SAY_STAGE_1_10);
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 2030);
                            break;
                        case 3051:
                            Talk(SAY_STAGE_2_02a);
                            _updateTimer = 17*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 3061);
                            break;
                        case 3071:
                            Talk(SAY_STAGE_2_04a);
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 3081);
                            break;
                        case 3080:
                            Talk(SAY_STAGE_2_05a);
                            _updateTimer = 3*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 3090);
                            break;
                        case 4020:
                            Talk(SAY_STAGE_3_03a);
                            _updateTimer = 5*IN_MILLISECONDS;
                            _instance->SetData(TYPE_EVENT, 4040);
                            break;
                        default:
                            break;
                    }
                }
                else
                    _updateTimer -= uiDiff;
                _instance->SetData(TYPE_EVENT_TIMER, _updateTimer);
            }
            private:
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_varian_tocAI>(creature);
        }
};

void AddSC_trial_of_the_crusader()
{
    new boss_lich_king_toc();
    new npc_announcer_toc10();
    new npc_fizzlebang_toc();
    new npc_tirion_toc();
    new npc_garrosh_toc();
    new npc_varian_toc();
}
