/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "violet_hold.h"
#include "Player.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

#define GOSSIP_START_EVENT  "Get your people to safety, we'll keep the Blue Dragonflight's forces at bay."
#define GOSSIP_ITEM_1       "Activate the crystals when we get in trouble, right"
#define GOSSIP_I_WANT_IN    "I'm not fighting, so send me in now!"
#define SAY_EVENT_LOCK      "I'm locking the door. Good luck, and thank you for doing this."
#define SPAWN_TIME          20000

enum PortalCreatures
{
    NPC_AZURE_INVADER_1         = 30661,
    NPC_AZURE_INVADER_2         = 30961,
    NPC_AZURE_SPELLBREAKER_1    = 30662,
    NPC_AZURE_SPELLBREAKER_2    = 30962,
    NPC_AZURE_BINDER_1          = 30663,
    NPC_AZURE_BINDER_2          = 30918,
    NPC_AZURE_MAGE_SLAYER_1     = 30664,
    NPC_AZURE_MAGE_SLAYER_2     = 30963,
    NPC_AZURE_CAPTAIN           = 30666,
    NPC_AZURE_SORCEROR          = 30667,
    NPC_AZURE_RAIDER            = 30668,
    NPC_AZURE_STALKER           = 32191
};

enum AzureInvaderSpells
{
    SPELL_CLEAVE                = 15496,
    SPELL_IMPALE                = 58459,
    SPELL_BRUTAL_STRIKE         = 58460,
    SPELL_SUNDER_ARMOR          = 58461
};

enum AzureSellbreakerSpells
{
    SPELL_ARCANE_BLAST          = 58462,
    SPELL_SLOW                  = 25603,
    SPELL_CHAINS_OF_ICE         = 58464,
    SPELL_CONE_OF_COLD          = 58463,
};

enum AzureBinderSpells
{
    SPELL_ARCANE_BARRAGE        = 58456,
    SPELL_ARCANE_EXPLOSION      = 58455,
    SPELL_FROST_NOVA            = 58458,
    SPELL_FROSTBOLT             = 58457,
};

enum AzureMageSlayerSpells
{
    SPELL_ARCANE_EMPOWERMENT    = 58469,
    SPELL_SPELL_LOCK            = 30849
};

enum AzureCaptainSpells
{
    SPELL_MORTAL_STRIKE         = 32736,
    SPELL_WHIRLWIND_OF_STEEL    = 41057
};

enum AzureSorcerorSpells
{
    SPELL_ARCANE_STREAM         = 60181,
    SPELL_MANA_DETONATION       = 60182,
};

enum AzureRaiderSpells
{
    SPELL_CONCUSSION_BLOW       = 52719,
    SPELL_MAGIC_REFLECTION      = 60158
};

enum AzureStalkerSpells
{
    SPELL_BACKSTAB              = 58471,
    SPELL_TACTICAL_BLINK        = 58470
};

enum AzureSaboteurSpells
{
    SABOTEUR_SHIELD_DISRUPTION  = 58291,
    SABOTEUR_SHIELD_EFFECT      = 45775
};

enum TrashDoorSpell
{
    SPELL_DESTROY_DOOR_SEAL     = 58040
};

enum Spells
{
    SPELL_PORTAL_CHANNEL        = 58012,
    SPELL_CRYSTAL_ACTIVATION    = 57804, // visual effect
    SPELL_ARCANE_SPHERE_PASSIVE = 44263
};

enum Sinclari
{
    SAY_SINCLARI_1              = 0
};

float FirstPortalWPs [6][3] =
{
    {1877.670288f, 842.280273f, 43.333591f},
    {1877.338867f, 834.615356f, 38.762287f},
    {1872.161011f, 823.854309f, 38.645401f},
    {1864.860474f, 815.787170f, 38.784843f},
    {1858.953735f, 810.048950f, 44.008759f},
    {1843.707153f, 805.807739f, 44.135197f}
    //{1825.736084f, 807.305847f, 44.363785f}
};

float SecondPortalFirstWPs [9][3] =
{
    {1902.561401f, 853.334656f, 47.106117f},
    {1895.486084f, 855.376404f, 44.334591f},
    {1882.805176f, 854.993286f, 43.333591f},
    {1877.670288f, 842.280273f, 43.333591f},
    {1877.338867f, 834.615356f, 38.762287f},
    {1872.161011f, 823.854309f, 38.645401f},
    {1864.860474f, 815.787170f, 38.784843f},
    {1858.953735f, 810.048950f, 44.008759f},
    {1843.707153f, 805.807739f, 44.135197f}
    //{1825.736084f, 807.305847f, 44.363785f}
};

float SecondPortalSecondWPs [8][3] =
{
    {1929.392212f, 837.614990f, 47.136166f},
    {1928.290649f, 824.750427f, 45.474411f},
    {1915.544922f, 826.919373f, 38.642811f},
    {1900.933960f, 818.855652f, 38.801647f},
    {1886.810547f, 813.536621f, 38.490490f},
    {1869.079712f, 808.701538f, 38.689003f},
    {1860.843384f, 806.645020f, 44.008789f},
    {1843.707153f, 805.807739f, 44.135197f}
    //{1825.736084f, 807.305847f, 44.363785f}
};

float ThirdPortalWPs [8][3] =
{
    {1934.049438f, 815.778503f, 52.408699f},
    {1928.290649f, 824.750427f, 45.474411f},
    {1915.544922f, 826.919373f, 38.642811f},
    {1900.933960f, 818.855652f, 38.801647f},
    {1886.810547f, 813.536621f, 38.490490f},
    {1869.079712f, 808.701538f, 38.689003f},
    {1860.843384f, 806.645020f, 44.008789f},
    {1843.707153f, 805.807739f, 44.135197f}
    //{1825.736084f, 807.305847f, 44.363785f}
};

float FourthPortalWPs [9][3] =
{
    {1921.658447f, 761.657043f, 50.866741f},
    {1910.559814f, 755.780457f, 47.701447f},
    {1896.664673f, 752.920898f, 47.667004f},
    {1887.398804f, 763.633240f, 47.666851f},
    {1879.020386f, 775.396973f, 38.705990f},
    {1872.439087f, 782.568604f, 38.808292f},
    {1863.573364f, 791.173584f, 38.743660f},
    {1857.811890f, 796.765564f, 43.950329f},
    {1845.577759f, 800.681152f, 44.104248f}
    //{1827.100342f, 801.605957f, 44.363358f}
};

float FifthPortalWPs [6][3] =
{
    {1887.398804f, 763.633240f, 47.666851f},
    {1879.020386f, 775.396973f, 38.705990f},
    {1872.439087f, 782.568604f, 38.808292f},
    {1863.573364f, 791.173584f, 38.743660f},
    {1857.811890f, 796.765564f, 43.950329f},
    {1845.577759f, 800.681152f, 44.104248f}
    //{1827.100342f, 801.605957f, 44.363358f}
};

float SixthPoralWPs [4][3] =
{
    {1888.861084f, 805.074768f, 38.375790f},
    {1869.793823f, 804.135804f, 38.647018f},
    {1861.541504f, 804.149780f, 43.968292f},
    {1843.567017f, 804.288208f, 44.139091f}
    //{1826.889648f, 803.929993f, 44.363239f}
};

const float SaboteurFinalPos1[3][3] =
{
    {1892.502319f, 777.410767f, 38.630402f},
    {1891.165161f, 762.969421f, 47.666920f},
    {1893.168091f, 740.919189f, 47.666920f}
};
const float SaboteurFinalPos2[3][3] =
{
    {1882.242676f, 834.818726f, 38.646786f},
    {1879.220825f, 842.224854f, 43.333641f},
    {1873.842896f, 863.892456f, 43.333641f}
};
const float SaboteurFinalPos3[2][3] =
{
    {1904.298340f, 792.400391f, 38.646782f},
    {1935.716919f, 758.437073f, 30.627895f}
};
const float SaboteurFinalPos4[3] =
{
    1855.006104f, 760.641724f, 38.655266f
};
const float SaboteurFinalPos5[3] =
{
    1906.667358f, 841.705566f, 38.637894f
};
const float SaboteurFinalPos6[5][3] =
{
    {1911.437012f, 821.289246f, 38.684128f},
    {1920.734009f, 822.978027f, 41.525414f},
    {1928.262939f, 830.836609f, 44.668266f},
    {1929.338989f, 837.593933f, 47.137596f},
    {1931.063354f, 848.468445f, 47.190434f}
 };

const Position PortalLocation[] =
{
    { 1877.51f, 850.104f, 44.6599f, 4.7822f },     // WP 1
    { 1936.07f, 803.198f, 53.3749f, 3.12414f },     // WP 3
    { 1890.64f, 753.471f, 48.7224f, 1.71042f },     // WP 5
};

#define MAX_PRE_EVENT_PORTAL    3

ObjectGuid preEventPortalGUID[MAX_PRE_EVENT_PORTAL] = { ObjectGuid::Empty };

const Position MovePosition = { 1806.955566f, 803.851807f, 44.363323f, 0.0f };
const Position playerTeleportPosition = { 1830.531006f, 803.939758f, 44.340508f, 6.281611f };
const Position sinclariOutsidePosition = { 1820.429810f, 804.066040f, 44.363998f, 0.0f };
const Position sinclariCrystalPosition = { 1828.868286f, 798.468811f, 44.363998f, 3.890467f };

class npc_sinclari_vh : public CreatureScript
{
public:
    npc_sinclari_vh() : CreatureScript("npc_sinclari_vh") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CLOSE_GOSSIP_MENU();
                ENSURE_AI(npc_sinclari_vh::npc_sinclariAI, creature->AI())->uiPhase = 1;
                if (InstanceScript* instance = creature->GetInstanceScript())
                    instance->SetData(DATA_MAIN_EVENT_PHASE, SPECIAL);
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->SEND_GOSSIP_MENU(13854, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->NearTeleportTo(playerTeleportPosition.GetPositionX(), playerTeleportPosition.GetPositionY(), playerTeleportPosition.GetPositionZ(), playerTeleportPosition.GetOrientation(), true);
                player->CLOSE_GOSSIP_MENU();
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (InstanceScript* instance = creature->GetInstanceScript())
        {
            switch (instance->GetData(DATA_MAIN_EVENT_PHASE))
            {
                case NOT_STARTED:
                case FAIL: // Allow to start event if not started or wiped
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                    player->SEND_GOSSIP_MENU(13853, creature->GetGUID());
                    break;
                case IN_PROGRESS: // Allow to teleport inside if event is in progress
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_I_WANT_IN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                    player->SEND_GOSSIP_MENU(13853, creature->GetGUID());
                    break;
                default:
                    player->SEND_GOSSIP_MENU(13910, creature->GetGUID());
            }
        }
        return true;
    }

    struct npc_sinclariAI : public ScriptedAI
    {
        npc_sinclariAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiPhase = 0;
            uiTimer = 0;
        }

        InstanceScript* instance;

        uint8  uiPhase;
        uint32 uiTimer;

        void Reset() override
        {
            Initialize();

            me->SetReactState(REACT_AGGRESSIVE);
            for (uint8 i = 0; i < MAX_PRE_EVENT_PORTAL; i++)
                if (TempSummon* summon = me->SummonCreature(NPC_TELEPORTATION_PORTAL, PortalLocation[i], TEMPSUMMON_MANUAL_DESPAWN))
                    preEventPortalGUID[i] = summon->GetGUID();

            std::list<Creature*> GuardList;
            me->GetCreatureListWithEntryInGrid(GuardList, NPC_VIOLET_HOLD_GUARD, 40.0f);
            if (!GuardList.empty())
            {
                for (std::list<Creature*>::const_iterator itr = GuardList.begin(); itr != GuardList.end(); ++itr)
                {
                    if (Creature* pGuard = *itr)
                    {
                        pGuard->DisappearAndDie();
                        pGuard->Respawn();
                        pGuard->SetVisible(true);
                        pGuard->SetReactState(REACT_AGGRESSIVE);
                    }
                }
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (uiPhase)
            {
                if (uiTimer <= uiDiff)
                {
                    switch (uiPhase)
                    {
                        case 1:
                            me->SetWalk(true);
                            me->GetMotionMaster()->MovePoint(0, sinclariCrystalPosition);
                            uiTimer = 1000;
                            uiPhase = 6;
                            break;
                        case 2:
                        {
                            me->SetFacingTo(me->GetOrientation() - 3.14f);
                            Talk(SAY_SINCLARI_1);
                            uiTimer = 1500;
                            uiPhase = 7;
                            break;
                        }
                        case 3:
                        {
                            std::list<Creature*> GuardList;
                            me->GetCreatureListWithEntryInGrid(GuardList, NPC_VIOLET_HOLD_GUARD, 40.0f);
                            if (!GuardList.empty())
                                for (std::list<Creature*>::const_iterator itr = GuardList.begin(); itr != GuardList.end(); ++itr)
                                {
                                    if (Creature* pGuard = *itr)
                                    {
                                        pGuard->SetVisible(false);
                                    }
                                }
                            uiTimer = 2000;
                            uiPhase = 4;
                            break;
                        }
                        case 4:
                            me->GetMotionMaster()->MovePoint(0, sinclariOutsidePosition);
                            uiTimer = 4000;
                            uiPhase = 5;
                            break;
                        case 5:
                            me->SetFacingTo(0.006673f);
                            me->Say(SAY_EVENT_LOCK, LANG_UNIVERSAL, me); // need to change to db say
                            me->SetReactState(REACT_PASSIVE);
                            uiTimer = 3000;
                            uiPhase = 8;
                            break;
                        case 6:
                            me->GetMotionMaster()->MovementExpired();
                            me->HandleEmoteCommand(EMOTE_STATE_USE_STANDING);
                            uiTimer = 2000;
                            uiPhase = 2;
                            break;
                        case 7:
                        {
                            std::list<Creature*> creatures;
                            GetCreatureListWithEntryInGrid(creatures, me, NPC_TELEPORTATION_PORTAL, 200.0f);
                            GetCreatureListWithEntryInGrid(creatures, me, NPC_AZURE_BINDER_1, 200.0f);
                            GetCreatureListWithEntryInGrid(creatures, me, NPC_AZURE_MAGE_SLAYER_1, 200.0f);
                            GetCreatureListWithEntryInGrid(creatures, me, NPC_AZURE_INVADER_1, 200.0f);
                            DoCast(SPELL_CRYSTAL_ACTIVATION);
                            if (!creatures.empty())
                            {
                                for (std::list<Creature*>::iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                                    (*itr)->DisappearAndDie();
                            }
                            uiTimer = 500;
                            uiPhase = 9;
                        }
                        break;
                        case 8:
                            instance->SetData(DATA_MAIN_EVENT_PHASE, IN_PROGRESS);
                            uiTimer = 0;
                            uiPhase = 0;
                            break;
                        case 9:
                        {
                            std::list<Creature*> GuardList;
                            me->GetCreatureListWithEntryInGrid(GuardList, NPC_VIOLET_HOLD_GUARD, 40.0f);
                            if (!GuardList.empty())
                                for (std::list<Creature*>::const_iterator itr = GuardList.begin(); itr != GuardList.end(); ++itr)
                                {
                                    if (Creature* pGuard = *itr)
                                    {
                                        pGuard->SetReactState(REACT_PASSIVE);
                                        pGuard->SetWalk(false);
                                        pGuard->GetMotionMaster()->MovePoint(0, MovePosition);
                                    }
                                }
                            uiTimer = 4000;
                            uiPhase = 3;
                        }
                        break;
                    }
                }
                else uiTimer -= uiDiff;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_sinclariAI>(creature);
    }
};

class npc_azure_saboteur : public CreatureScript
{
public:
    npc_azure_saboteur() : CreatureScript("npc_azure_saboteur") { }

    struct npc_azure_saboteurAI : public npc_escortAI
    {
        npc_azure_saboteurAI(Creature* creature) : npc_escortAI(creature)
        {
            instance = creature->GetInstanceScript();
            bHasGotMovingPoints = false;
            uiBoss = 0;
            Reset();
        }

        InstanceScript* instance;
        bool bHasGotMovingPoints;
        uint32 uiBoss;

        void Reset() override
        {
            if (!uiBoss)
                uiBoss = instance->GetData(DATA_WAVE_COUNT) == 6 ? instance->GetData(DATA_FIRST_BOSS) : instance->GetData(DATA_SECOND_BOSS);
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void WaypointReached(uint32 waypointId) override
        {
            switch (uiBoss)
            {
                case 1:
                    if (waypointId == 2)
                        FinishPointReached();
                    break;
                case 2:
                    if (waypointId == 2)
                        FinishPointReached();
                    break;
                case 3:
                    if (waypointId == 1)
                        FinishPointReached();
                    break;
                case 4:
                    if (waypointId == 0)
                        FinishPointReached();
                    break;
                case 5:
                    if (waypointId == 0)
                        FinishPointReached();
                    break;
                case 6:
                    if (waypointId == 4)
                        FinishPointReached();
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (instance->GetData(DATA_MAIN_EVENT_PHASE) != IN_PROGRESS)
                me->CastStop();

            npc_escortAI::UpdateAI(diff);

            if (!bHasGotMovingPoints)
            {
                bHasGotMovingPoints = true;
                switch (uiBoss)
                {
                    case 1:
                        for (int i=0;i<3;i++)
                            AddWaypoint(i, SaboteurFinalPos1[i][0], SaboteurFinalPos1[i][1], SaboteurFinalPos1[i][2], 0);
                        me->SetHomePosition(SaboteurFinalPos1[2][0], SaboteurFinalPos1[2][1], SaboteurFinalPos1[2][2], 4.762346f);
                        break;
                    case 2:
                        for (int i=0;i<3;i++)
                            AddWaypoint(i, SaboteurFinalPos2[i][0], SaboteurFinalPos2[i][1], SaboteurFinalPos2[i][2], 0);
                        me->SetHomePosition(SaboteurFinalPos2[2][0], SaboteurFinalPos2[2][1], SaboteurFinalPos2[2][2], 1.862674f);
                        break;
                    case 3:
                        for (int i=0;i<2;i++)
                            AddWaypoint(i, SaboteurFinalPos3[i][0], SaboteurFinalPos3[i][1], SaboteurFinalPos3[i][2], 0);
                        me->SetHomePosition(SaboteurFinalPos3[1][0], SaboteurFinalPos3[1][1], SaboteurFinalPos3[1][2], 5.500638f);
                        break;
                    case 4:
                        AddWaypoint(0, SaboteurFinalPos4[0], SaboteurFinalPos4[1], SaboteurFinalPos4[2], 0);
                        me->SetHomePosition(SaboteurFinalPos4[0], SaboteurFinalPos4[1], SaboteurFinalPos4[2], 3.991108f);
                        break;
                    case 5:
                        AddWaypoint(0, SaboteurFinalPos5[0], SaboteurFinalPos5[1], SaboteurFinalPos5[2], 0);
                        me->SetHomePosition(SaboteurFinalPos5[0], SaboteurFinalPos5[1], SaboteurFinalPos5[2], 1.100841f);
                        break;
                    case 6:
                        for (int i=0;i<5;i++)
                            AddWaypoint(i, SaboteurFinalPos6[i][0], SaboteurFinalPos6[i][1], SaboteurFinalPos6[i][2], 0);
                        me->SetHomePosition(SaboteurFinalPos6[4][0], SaboteurFinalPos6[4][1], SaboteurFinalPos6[4][2], 0.983031f);
                        break;
                }

                SetDespawnAtEnd(false);
                Start(true, true);
            }
        }

        void FinishPointReached()
        {
            me->CastSpell(me, SABOTEUR_SHIELD_DISRUPTION, false);
            me->DisappearAndDie();
            if (Creature* pSaboPort = ObjectAccessor::GetCreature((*me), instance->GetGuidData(DATA_SABOTEUR_PORTAL)))
                pSaboPort->DisappearAndDie();
            instance->SetData(DATA_START_BOSS_ENCOUNTER, 1);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_azure_saboteurAI>(creature);
    }
};

class npc_teleportation_portal_vh : public CreatureScript
{
public:
    npc_teleportation_portal_vh() : CreatureScript("npc_teleportation_portal_vh") { }

    struct npc_teleportation_portalAI : public ScriptedAI
    {
        npc_teleportation_portalAI(Creature* creature) : ScriptedAI(creature), listOfMobs(me)
        {
            Initialize();
            instance = creature->GetInstanceScript();
            uiTypeOfMobsPortal = urand(0, 1);    // 0 - elite mobs   1 - portal guardian or portal keeper with regular mobs

            if (instance->GetData(DATA_MAIN_EVENT_PHASE) == NOT_STARTED)
                uiTypeOfMobsPortal = 2;
        }

        void Initialize()
        {
            uiSpawnTimer = 10000;
            bPortalGuardianOrKeeperOrEliteSpawn = false;
        }

        uint32 uiSpawnTimer;
        bool bPortalGuardianOrKeeperOrEliteSpawn;
        uint8 uiTypeOfMobsPortal;

        SummonList listOfMobs;

        InstanceScript* instance;

        void Reset() override
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override { }

        void MoveInLineOfSight(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (instance->GetData(DATA_MAIN_EVENT_PHASE) == IN_PROGRESS)
            {
                if (instance->GetData(DATA_REMOVE_NPC) == 1)
                {
                    me->DespawnOrUnsummon();
                    instance->SetData(DATA_REMOVE_NPC, 0);
                }
            }

            uint8 uiWaveCount = instance->GetData(DATA_WAVE_COUNT);
            if ((uiWaveCount == 6) || (uiWaveCount == 12)) //Don't spawn mobs on boss encounters
                return;

            switch (uiTypeOfMobsPortal)
            {
                // spawn elite mobs and then set portals visibility to make it look like it dissapeard
                case 0:
                    if (!bPortalGuardianOrKeeperOrEliteSpawn)
                    {
                        if (uiSpawnTimer <= diff)
                        {
                            bPortalGuardianOrKeeperOrEliteSpawn = true;
                            uint8 k = uiWaveCount < 12 ? 2 : 3;
                            for (uint8 i = 0; i < k; ++i)
                            {
                                uint32 entry = RAND(NPC_AZURE_CAPTAIN, NPC_AZURE_RAIDER, NPC_AZURE_STALKER, NPC_AZURE_SORCEROR);
                                DoSummon(entry, me, 2.0f, 20000, TEMPSUMMON_DEAD_DESPAWN);
                            }
                            me->SetVisible(false);
                        } else uiSpawnTimer -= diff;
                    }
                    else
                    {
                        // if all spawned elites have died kill portal
                        if (listOfMobs.empty())
                        {
                            me->Kill(me, false);
                            me->RemoveCorpse();
                        }
                    }
                    break;
                // spawn portal guardian or portal keeper with regular mobs
                case 1:
                    if (uiSpawnTimer <= diff)
                    {
                        if (bPortalGuardianOrKeeperOrEliteSpawn)
                        {
                            uint8 k = instance->GetData(DATA_WAVE_COUNT) < 12 ? 3 : 4;
                            for (uint8 i = 0; i < k; ++i)
                            {
                                uint32 entry = RAND(NPC_AZURE_INVADER_1, NPC_AZURE_INVADER_2, NPC_AZURE_SPELLBREAKER_1, NPC_AZURE_SPELLBREAKER_2, NPC_AZURE_MAGE_SLAYER_1, NPC_AZURE_MAGE_SLAYER_2, NPC_AZURE_BINDER_1, NPC_AZURE_BINDER_2);
                                DoSummon(entry, me, 2.0f, 20000, TEMPSUMMON_DEAD_DESPAWN);
                            }
                        }
                        else
                        {
                            bPortalGuardianOrKeeperOrEliteSpawn = true;
                            uint32 entry = RAND(NPC_PORTAL_GUARDIAN, NPC_PORTAL_KEEPER);
                            if (Creature* pPortalKeeper = DoSummon(entry, me, 2.0f, 0, TEMPSUMMON_DEAD_DESPAWN))
                                me->CastSpell(pPortalKeeper, SPELL_PORTAL_CHANNEL, false);
                        }
                        uiSpawnTimer = SPAWN_TIME;
                    } else uiSpawnTimer -= diff;

                    if (bPortalGuardianOrKeeperOrEliteSpawn && !me->IsNonMeleeSpellCast(false))
                    {
                        me->Kill(me, false);
                        me->RemoveCorpse();
                    }
                    break;
                case 2: // Pre-event
                    if (uiSpawnTimer <= diff)
                    {
                        uint32 entry = RAND(NPC_AZURE_INVADER_1, NPC_AZURE_MAGE_SLAYER_1, NPC_AZURE_BINDER_1);
                        DoSummon(entry, me, 2.0f, 20000, TEMPSUMMON_DEAD_DESPAWN);
                        uiSpawnTimer = SPAWN_TIME;
                    } else uiSpawnTimer -= diff;
                    break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance->GetData(DATA_MAIN_EVENT_PHASE) == IN_PROGRESS)
                instance->SetData(DATA_WAVE_COUNT, instance->GetData(DATA_WAVE_COUNT) + 1);
        }

        void JustSummoned(Creature* summoned) override
        {
            if (instance->GetData(DATA_MAIN_EVENT_PHASE) == IN_PROGRESS)
            {
                listOfMobs.Summon(summoned);
                instance->SetGuidData(DATA_ADD_TRASH_MOB, summoned->GetGUID());
            }
        }

        void SummonedCreatureDies(Creature* summoned, Unit* /*killer*/) override
        {
            if (instance->GetData(DATA_MAIN_EVENT_PHASE) == IN_PROGRESS)
            {
                listOfMobs.Despawn(summoned);
                instance->SetGuidData(DATA_DEL_TRASH_MOB, summoned->GetGUID());
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_teleportation_portalAI>(creature);
    }
};

struct violet_hold_trashAI : public npc_escortAI
{
    violet_hold_trashAI(Creature* creature) : npc_escortAI(creature)
    {
        instance = creature->GetInstanceScript();
        bHasGotMovingPoints = false;


        if (instance->GetData(DATA_MAIN_EVENT_PHASE) == NOT_STARTED)
        {
            if (Creature* portal = me->FindNearestCreature(NPC_TELEPORTATION_PORTAL, 10.0f))
            {
                ObjectGuid portalGUID = portal->GetGUID();
                for (uint8 i = 0; i < MAX_PRE_EVENT_PORTAL; i++)
                    if (portalGUID == preEventPortalGUID[i])
                        portalLocationID = i * 2;
            }
        }
        else
        {
            portalLocationID = instance->GetData(DATA_PORTAL_LOCATION);
            Reset();
        }
    }

    public:
        InstanceScript* instance;
        bool bHasGotMovingPoints;
        uint32 portalLocationID;
        uint32 secondPortalRouteID;

    void WaypointReached(uint32 waypointId) override
    {
        switch (portalLocationID)
        {
            case 0:
                if (waypointId == 5)
                    CreatureStartAttackDoor();
                break;
            case 1:
                if ((waypointId == 8 && secondPortalRouteID == 0) || (waypointId == 7 && secondPortalRouteID == 1))
                    CreatureStartAttackDoor();
                break;
            case 2:
                if (waypointId == 7)
                    CreatureStartAttackDoor();
                break;
            case 3:
                if (waypointId == 8)
                    CreatureStartAttackDoor();
                break;
            case 4:
                if (waypointId == 5)
                    CreatureStartAttackDoor();
                break;
            case 5:
                if (waypointId == 3)
                    CreatureStartAttackDoor();
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (instance->GetData(DATA_MAIN_EVENT_PHASE) != IN_PROGRESS)
            me->CastStop();

        if (!bHasGotMovingPoints)
        {
            bHasGotMovingPoints = true;
            switch (portalLocationID)
            {
                case 0:
                    for (int i=0;i<6;i++)
                        AddWaypoint(i, FirstPortalWPs[i][0]+irand(-1, 1), FirstPortalWPs[i][1]+irand(-1, 1), FirstPortalWPs[i][2]+irand(-1, 1), 0);
                    me->SetHomePosition(FirstPortalWPs[5][0], FirstPortalWPs[5][1], FirstPortalWPs[5][2], 3.149439f);
                    break;
                case 1:
                    secondPortalRouteID = urand(0, 1);
                    switch (secondPortalRouteID)
                    {
                        case 0:
                            for (int i=0;i<9;i++)
                                AddWaypoint(i, SecondPortalFirstWPs[i][0]+irand(-1, 1), SecondPortalFirstWPs[i][1]+irand(-1, 1), SecondPortalFirstWPs[i][2], 0);
                            me->SetHomePosition(SecondPortalFirstWPs[8][0]+irand(-1, 1), SecondPortalFirstWPs[8][1]+irand(-1, 1), SecondPortalFirstWPs[8][2]+irand(-1, 1), 3.149439f);
                            break;
                        case 1:
                            for (int i=0;i<8;i++)
                                AddWaypoint(i, SecondPortalSecondWPs[i][0]+irand(-1, 1), SecondPortalSecondWPs[i][1]+irand(-1, 1), SecondPortalSecondWPs[i][2], 0);
                            me->SetHomePosition(SecondPortalSecondWPs[7][0], SecondPortalSecondWPs[7][1], SecondPortalSecondWPs[7][2], 3.149439f);
                            break;
                    }
                    break;
                case 2:
                    for (int i=0;i<8;i++)
                        AddWaypoint(i, ThirdPortalWPs[i][0]+irand(-1, 1), ThirdPortalWPs[i][1]+irand(-1, 1), ThirdPortalWPs[i][2], 0);
                    me->SetHomePosition(ThirdPortalWPs[7][0], ThirdPortalWPs[7][1], ThirdPortalWPs[7][2], 3.149439f);
                    break;
                case 3:
                    for (int i=0;i<9;i++)
                        AddWaypoint(i, FourthPortalWPs[i][0]+irand(-1, 1), FourthPortalWPs[i][1]+irand(-1, 1), FourthPortalWPs[i][2], 0);
                    me->SetHomePosition(FourthPortalWPs[8][0], FourthPortalWPs[8][1], FourthPortalWPs[8][2], 3.149439f);
                    break;
                case 4:
                    for (int i=0;i<6;i++)
                        AddWaypoint(i, FifthPortalWPs[i][0]+irand(-1, 1), FifthPortalWPs[i][1]+irand(-1, 1), FifthPortalWPs[i][2], 0);
                    me->SetHomePosition(FifthPortalWPs[5][0], FifthPortalWPs[5][1], FifthPortalWPs[5][2], 3.149439f);
                    break;
                case 5:
                    for (int i=0;i<4;i++)
                        AddWaypoint(i, SixthPoralWPs[i][0]+irand(-1, 1), SixthPoralWPs[i][1]+irand(-1, 1), SixthPoralWPs[i][2], 0);
                    me->SetHomePosition(SixthPoralWPs[3][0], SixthPoralWPs[3][1], SixthPoralWPs[3][2], 3.149439f);
                    break;
            }
            SetDespawnAtEnd(false);
            Start(true, true);
        }

        npc_escortAI::UpdateAI(diff);
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SetData(DATA_NPC_PRESENCE_AT_DOOR_REMOVE, 1);
    }

    void CreatureStartAttackDoor()
    {
        me->SetReactState(REACT_PASSIVE);
        DoCast(SPELL_DESTROY_DOOR_SEAL);
        instance->SetData(DATA_NPC_PRESENCE_AT_DOOR_ADD, 1);
    }
};

class npc_azure_invader : public CreatureScript
{
public:
    npc_azure_invader() : CreatureScript("npc_azure_invader") { }

    struct npc_azure_invaderAI : public violet_hold_trashAI
    {
        npc_azure_invaderAI(Creature* creature) : violet_hold_trashAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiCleaveTimer = 5000;
            uiImpaleTimer = 4000;
            uiBrutalStrikeTimer = 5000;
            uiSunderArmorTimer = 4000;
        }

        uint32 uiCleaveTimer;
        uint32 uiImpaleTimer;
        uint32 uiBrutalStrikeTimer;
        uint32 uiSunderArmorTimer;

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            violet_hold_trashAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            if (me->GetEntry() == NPC_AZURE_INVADER_1)
            {
                if (uiCleaveTimer <= diff)
                {
                    DoCastVictim(SPELL_CLEAVE);
                    uiCleaveTimer = 5000;
                } else uiCleaveTimer -= diff;

                if (uiImpaleTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(target, SPELL_IMPALE);
                    uiImpaleTimer = 4000;
                } else uiImpaleTimer -= diff;
            }

            if (me->GetEntry() == NPC_AZURE_INVADER_2)
            {
                if (uiBrutalStrikeTimer <= diff)
                {
                    DoCastVictim(SPELL_BRUTAL_STRIKE);
                    uiBrutalStrikeTimer = 5000;
                } else uiBrutalStrikeTimer -= diff;

                if (uiSunderArmorTimer <= diff)
                {
                    DoCastVictim(SPELL_SUNDER_ARMOR);
                    uiSunderArmorTimer = urand(8000, 10000);
                } else uiSunderArmorTimer -= diff;

                DoMeleeAttackIfReady();
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_azure_invaderAI>(creature);
    }
};

class npc_azure_binder : public CreatureScript
{
public:
    npc_azure_binder() : CreatureScript("npc_azure_binder") { }

    struct npc_azure_binderAI : public violet_hold_trashAI
    {
        npc_azure_binderAI(Creature* creature) : violet_hold_trashAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiArcaneExplosionTimer = 5000;
            uiArcainBarrageTimer = 4000;
            uiFrostNovaTimer = 5000;
            uiFrostboltTimer = 4000;
        }

        uint32 uiArcaneExplosionTimer;
        uint32 uiArcainBarrageTimer;
        uint32 uiFrostNovaTimer;
        uint32 uiFrostboltTimer;

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            violet_hold_trashAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            if (me->GetEntry() == NPC_AZURE_BINDER_1)
            {
                if (uiArcaneExplosionTimer <= diff)
                {
                    DoCast(SPELL_ARCANE_EXPLOSION);
                    uiArcaneExplosionTimer = 5000;
                } else uiArcaneExplosionTimer -= diff;

                if (uiArcainBarrageTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(target, SPELL_ARCANE_BARRAGE);
                    uiArcainBarrageTimer = 6000;
                } else uiArcainBarrageTimer -= diff;
            }

            if (me->GetEntry() == NPC_AZURE_BINDER_2)
            {
                if (uiFrostNovaTimer <= diff)
                {
                    DoCast(SPELL_FROST_NOVA);
                    uiFrostNovaTimer = 5000;
                } else uiFrostNovaTimer -= diff;

                if (uiFrostboltTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(target, SPELL_FROSTBOLT);
                    uiFrostboltTimer = 6000;
                } else uiFrostboltTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_azure_binderAI>(creature);
    }
};

class npc_azure_mage_slayer : public CreatureScript
{
public:
    npc_azure_mage_slayer() : CreatureScript("npc_azure_mage_slayer") { }

    struct npc_azure_mage_slayerAI : public violet_hold_trashAI
    {
        npc_azure_mage_slayerAI(Creature* creature) : violet_hold_trashAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiArcaneEmpowermentTimer = 5000;
            uiSpellLockTimer = 5000;
        }

        uint32 uiArcaneEmpowermentTimer;
        uint32 uiSpellLockTimer;

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            violet_hold_trashAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            if (me->GetEntry() == NPC_AZURE_MAGE_SLAYER_1)
            {
                if (uiArcaneEmpowermentTimer <= diff)
                {
                    DoCast(me, SPELL_ARCANE_EMPOWERMENT);
                        uiArcaneEmpowermentTimer = 14000;
                } else uiArcaneEmpowermentTimer -= diff;
            }

            if (me->GetEntry() == NPC_AZURE_MAGE_SLAYER_2)
            {
                if (uiSpellLockTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(target, SPELL_SPELL_LOCK);
                    uiSpellLockTimer = 9000;
                } else uiSpellLockTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_azure_mage_slayerAI>(creature);
    }
};

class npc_azure_raider : public CreatureScript
{
public:
    npc_azure_raider() : CreatureScript("npc_azure_raider") { }

    struct npc_azure_raiderAI : public violet_hold_trashAI
    {
        npc_azure_raiderAI(Creature* creature) : violet_hold_trashAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiConcussionBlowTimer = 5000;
            uiMagicReflectionTimer = 8000;
        }

        uint32 uiConcussionBlowTimer;
        uint32 uiMagicReflectionTimer;

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            violet_hold_trashAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            if (uiConcussionBlowTimer <= diff)
            {
                DoCastVictim(SPELL_CONCUSSION_BLOW);
                uiConcussionBlowTimer = 5000;
            } else uiConcussionBlowTimer -= diff;

            if (uiMagicReflectionTimer <= diff)
            {
                DoCast(SPELL_MAGIC_REFLECTION);
                uiMagicReflectionTimer = urand(10000, 15000);
            } else uiMagicReflectionTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_azure_raiderAI>(creature);
    }
};

class npc_azure_stalker : public CreatureScript
{
public:
    npc_azure_stalker() : CreatureScript("npc_azure_stalker") { }

    struct npc_azure_stalkerAI : public violet_hold_trashAI
    {
        npc_azure_stalkerAI(Creature* creature) : violet_hold_trashAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            _backstabTimer = 1300;
            _tacticalBlinkTimer = 8000;
            _tacticalBlinkCast = false;
        }

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            violet_hold_trashAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            if (!_tacticalBlinkCast)
            {
                if (_tacticalBlinkTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40, true))
                        DoCast(target, SPELL_TACTICAL_BLINK);
                    _tacticalBlinkTimer = 6000;
                    _tacticalBlinkCast = true;
                } else _tacticalBlinkTimer -= diff;
            }

            else
            {
                if (_backstabTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 10, true))
                        DoCast(target, SPELL_BACKSTAB);
                    _tacticalBlinkCast = false;
                    _backstabTimer =1300;
                } else _backstabTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }

    private:
        uint32 _backstabTimer;
        uint32 _tacticalBlinkTimer;
        bool _tacticalBlinkCast;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_azure_stalkerAI>(creature);
    }
};

class npc_azure_spellbreaker : public CreatureScript
{
public:
    npc_azure_spellbreaker() : CreatureScript("npc_azure_spellbreaker") { }

    struct npc_azure_spellbreakerAI : public violet_hold_trashAI
    {
        npc_azure_spellbreakerAI(Creature* creature) : violet_hold_trashAI(creature)
        {
            Initialize();
             instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiArcaneBlastTimer = 5000;
            uiSlowTimer = 4000;
            uiChainsOfIceTimer = 5000;
            uiConeOfColdTimer = 4000;
        }

        uint32 uiArcaneBlastTimer;
        uint32 uiSlowTimer;
        uint32 uiChainsOfIceTimer;
        uint32 uiConeOfColdTimer;

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            violet_hold_trashAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            if (me->GetEntry() == NPC_AZURE_SPELLBREAKER_1)
            {
                if (uiArcaneBlastTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(target, SPELL_ARCANE_BLAST);
                    uiArcaneBlastTimer = 6000;
                } else uiArcaneBlastTimer -= diff;

                if (uiSlowTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(target, SPELL_SLOW);
                    uiSlowTimer = 5000;
                } else uiSlowTimer -= diff;
            }

            if (me->GetEntry() == NPC_AZURE_SPELLBREAKER_2)
            {
                if (uiChainsOfIceTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(target, SPELL_CHAINS_OF_ICE);
                    uiChainsOfIceTimer = 7000;
                } else uiChainsOfIceTimer -= diff;

                if (uiConeOfColdTimer <= diff)
                {
                    DoCast(SPELL_CONE_OF_COLD);
                    uiConeOfColdTimer = 5000;
                } else uiConeOfColdTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_azure_spellbreakerAI>(creature);
    }
};

class npc_azure_captain : public CreatureScript
{
public:
    npc_azure_captain() : CreatureScript("npc_azure_captain") { }

    struct  npc_azure_captainAI : public violet_hold_trashAI
    {
        npc_azure_captainAI(Creature* creature) : violet_hold_trashAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiMortalStrikeTimer = 5000;
            uiWhirlwindTimer = 8000;
        }

        uint32 uiMortalStrikeTimer;
        uint32 uiWhirlwindTimer;

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            violet_hold_trashAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            if (uiMortalStrikeTimer <= diff)
            {
                DoCastVictim(SPELL_MORTAL_STRIKE);
                uiMortalStrikeTimer = 5000;
            } else uiMortalStrikeTimer -= diff;

            if (uiWhirlwindTimer <= diff)
            {
                DoCast(me, SPELL_WHIRLWIND_OF_STEEL);
                uiWhirlwindTimer = 8000;
            } else uiWhirlwindTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_azure_captainAI>(creature);
    }
};

class npc_azure_sorceror : public CreatureScript
{
public:
    npc_azure_sorceror() : CreatureScript("npc_azure_sorceror") { }

    struct  npc_azure_sorcerorAI : public violet_hold_trashAI
    {
        npc_azure_sorcerorAI(Creature* creature) : violet_hold_trashAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiArcaneStreamTimer = 4000;
            uiArcaneStreamTimerStartingValueHolder = uiArcaneStreamTimer;
            uiManaDetonationTimer = 5000;
        }

        uint32 uiArcaneStreamTimer;
        uint32 uiArcaneStreamTimerStartingValueHolder;
        uint32 uiManaDetonationTimer;

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            violet_hold_trashAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            if (uiArcaneStreamTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_ARCANE_STREAM);
                uiArcaneStreamTimer = urand(0, 5000)+5000;
                uiArcaneStreamTimerStartingValueHolder = uiArcaneStreamTimer;
            } else uiArcaneStreamTimer -= diff;

            if (uiManaDetonationTimer <= diff && uiArcaneStreamTimer >=1500 && uiArcaneStreamTimer <= uiArcaneStreamTimerStartingValueHolder/2)
            {
                DoCast(SPELL_MANA_DETONATION);
                uiManaDetonationTimer = urand(2000, 6000);
            } else uiManaDetonationTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_azure_sorcerorAI>(creature);
    }
};

class npc_violet_hold_arcane_sphere : public CreatureScript
{
public:
    npc_violet_hold_arcane_sphere() : CreatureScript("npc_violet_hold_arcane_sphere") { }

    struct npc_violet_hold_arcane_sphereAI : public ScriptedAI
    {
        npc_violet_hold_arcane_sphereAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            DespawnTimer = 3000;
        }

        uint32 DespawnTimer;

        void Reset() override
        {
            Initialize();

            me->SetDisableGravity(true);
            DoCast(me, SPELL_ARCANE_SPHERE_PASSIVE, true);
        }

        void EnterCombat(Unit * /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (DespawnTimer <= diff)
                me->Kill(me);
            else
                DespawnTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_violet_hold_arcane_sphereAI(creature);
    }
};

class go_activation_crystal : public GameObjectScript
{
public:
    go_activation_crystal() : GameObjectScript("go_activation_crystal") { }

    bool OnGossipHello(Player * /*player*/, GameObject* go) override
    {
        go->EventInform(EVENT_ACTIVATE_CRYSTAL);
        return false;
    }
};

class spell_crystal_activation : public SpellScriptLoader
{
public:
    spell_crystal_activation() : SpellScriptLoader("spell_crystal_activation") { }

    class spell_crystal_activation_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_crystal_activation_SpellScript);

        void HandleSendEvent(SpellEffIndex effIndex)
        {
            if (GetHitUnit()->GetEntry() == NPC_VIOLET_HOLD_GUARD)
                PreventHitDefaultEffect(effIndex);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_crystal_activation_SpellScript::HandleSendEvent, EFFECT_0, SPELL_EFFECT_SEND_EVENT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_crystal_activation_SpellScript();
    }
};

void AddSC_violet_hold()
{
    new npc_sinclari_vh();
    new npc_teleportation_portal_vh();
    new npc_azure_invader();
    new npc_azure_spellbreaker();
    new npc_azure_binder();
    new npc_azure_mage_slayer();
    new npc_azure_captain();
    new npc_azure_sorceror();
    new npc_azure_raider();
    new npc_azure_stalker();
    new npc_azure_saboteur();
    new npc_violet_hold_arcane_sphere();
    new go_activation_crystal();
    new spell_crystal_activation();
}
