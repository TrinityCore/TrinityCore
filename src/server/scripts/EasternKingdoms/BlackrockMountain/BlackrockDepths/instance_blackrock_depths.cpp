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
#include "blackrock_depths.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "ScriptedCreature.h"

#define TIMER_TOMBOFTHESEVEN    15000
constexpr uint8 TOMB_OF_SEVEN_BOSS_NUM = 7;

enum Creatures
{
    NPC_GOLEM_LORD_ARGELMACH = 8983,
    NPC_BAELGAR              = 9016,
    NPC_LORD_INCENDIUS       = 9017,
    NPC_EMPEROR              = 9019,
    NPC_PHALANX              = 9502,
    NPC_PYROMANCER_LOREGRAIN = 9024,
    NPC_LORD_ROCCOR          = 9025,
    NPC_ANGERREL             = 9035,
    NPC_DOPEREL              = 9040,
    NPC_HATEREL              = 9034,
    NPC_VILEREL              = 9036,
    NPC_SEETHREL             = 9038,
    NPC_GLOOMREL             = 9037,
    NPC_DOOMREL              = 9039,
    NPC_WARDER_STILGISS      = 9041,
    NPC_FINEOUS_DARKVIRE     = 9056,
    NPC_HOUNDMASTER_GREBMAR  = 9319,
    NPC_PLUGGER_SPAZZRING    = 9499,
    NPC_HURLEY_BLACKBREATH   = 9537,
    NPC_RIBBLY_SCREWSPIGOT   = 9543,
    NPC_MAGMUS               = 9938,
    NPC_MOIRA                = 8929,
    NPC_COREN                = 23872,
};

enum GameObjects
{
    GO_ARENA1               = 161525,
    GO_ARENA2               = 161522,
    GO_ARENA3               = 161524,
    GO_ARENA4               = 161523,
    GO_SHADOW_LOCK          = 161460,
    GO_SHADOW_MECHANISM     = 161461,
    GO_SHADOW_GIANT_DOOR    = 157923,
    GO_SHADOW_DUMMY         = 161516,
    GO_BAR_KEG_SHOT         = 170607,
    GO_BAR_KEG_TRAP         = 171941,
    GO_BAR_DOOR             = 170571,
    GO_TOMB_ENTER           = 170576,
    GO_TOMB_EXIT            = 170577,
    GO_LYCEUM               = 170558,
    GO_SF_N                 = 174745, // Shadowforge Brazier North
    GO_SF_S                 = 174744, // Shadowforge Brazier South
    GO_GOLEM_ROOM_N         = 170573, // Magmus door North
    GO_GOLEM_ROOM_S         = 170574, // Magmus door Soutsh
    GO_THRONE_ROOM          = 170575, // Throne door
    GO_SPECTRAL_CHALICE     = 164869,
    GO_CHEST_SEVEN          = 169243
};

static constexpr DungeonEncounterData encounters[] =
{
    { BOSS_HIGH_INTERROGATOR_GERSTAHN, { { 227 }} },
    { BOSS_LORD_ROCCOR, { { 228 }} },
    { BOSS_HOUNDMASTER_GREBMAR, { { 229 }} },
    { BOSS_RING_OF_LAW, { { 230 }} },
    { BOSS_PYROMANCER_LOREGRAIN, { { 231 }} },
    { BOSS_LORD_INCENDIUS, { { 232 }} },
    { BOSS_WARDER_STILGISS, { { 233 }} },
    { BOSS_FINEOUS_DARKVIRE, { { 234 }} },
    { BOSS_BAELGAR, { { 235 }} },
    { BOSS_GENERAL_ANGERFORGE, { { 236 }} },
    { BOSS_GOLEM_LORD_ARGELMACH, { { 237 }} },
    { BOSS_HURLEY_BLACKBREATH, { { 238 }} },
    { BOSS_PHALANX, { { 239 }} },
    { BOSS_RIBBLY_SCREWSPIGOT, { { 240 }} },
    { BOSS_PLUGGER_SPAZZRING, { { 241 }} },
    { BOSS_AMBASSADOR_FLAMELASH, { { 242 }} },
    { BOSS_THE_SEVEN, { { 243 }} },
    { BOSS_MAGMUS, { { 244 }} },
    { BOSS_EMPEROR_DAGRAN_THAURISSAN, { { 245 }} }
};

class instance_blackrock_depths : public InstanceMapScript
{
public:
    instance_blackrock_depths() : InstanceMapScript(BRDScriptName, 230) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_blackrock_depths_InstanceMapScript(map);
    }

    struct instance_blackrock_depths_InstanceMapScript : public InstanceScript
    {
        instance_blackrock_depths_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(MAX_ENCOUNTER);
            LoadDungeonEncounterData(encounters);

            BarAleCount = 0;
            GhostKillCount = 0;
            TombTimer = TIMER_TOMBOFTHESEVEN;
            TombEventCounter = 0;
        }

        ObjectGuid EmperorGUID;
        ObjectGuid PhalanxGUID;
        ObjectGuid MagmusGUID;
        ObjectGuid MoiraGUID;
        ObjectGuid CorenGUID;

        ObjectGuid GoArena1GUID;
        ObjectGuid GoArena2GUID;
        ObjectGuid GoArena3GUID;
        ObjectGuid GoArena4GUID;
        ObjectGuid GoShadowLockGUID;
        ObjectGuid GoShadowMechGUID;
        ObjectGuid GoShadowGiantGUID;
        ObjectGuid GoShadowDummyGUID;
        ObjectGuid GoBarKegGUID;
        ObjectGuid GoBarKegTrapGUID;
        ObjectGuid GoBarDoorGUID;
        ObjectGuid GoTombEnterGUID;
        ObjectGuid GoTombExitGUID;
        ObjectGuid GoLyceumGUID;
        ObjectGuid GoSFSGUID;
        ObjectGuid GoSFNGUID;
        ObjectGuid GoGolemNGUID;
        ObjectGuid GoGolemSGUID;
        ObjectGuid GoThroneGUID;
        ObjectGuid GoChestGUID;
        ObjectGuid GoSpectralChaliceGUID;

        uint32 BarAleCount;
        uint32 GhostKillCount;
        ObjectGuid TombBossGUIDs[TOMB_OF_SEVEN_BOSS_NUM];
        ObjectGuid TombEventStarterGUID;
        uint32 TombTimer;
        uint32 TombEventCounter;

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_EMPEROR: EmperorGUID = creature->GetGUID(); break;
                case NPC_PHALANX: PhalanxGUID = creature->GetGUID(); break;
                case NPC_MOIRA: MoiraGUID = creature->GetGUID(); break;
                case NPC_COREN: CorenGUID = creature->GetGUID(); break;
                case NPC_DOOMREL: TombBossGUIDs[0] = creature->GetGUID(); break;
                case NPC_DOPEREL: TombBossGUIDs[1] = creature->GetGUID(); break;
                case NPC_HATEREL: TombBossGUIDs[2] = creature->GetGUID(); break;
                case NPC_VILEREL: TombBossGUIDs[3] = creature->GetGUID(); break;
                case NPC_SEETHREL: TombBossGUIDs[4] = creature->GetGUID(); break;
                case NPC_GLOOMREL: TombBossGUIDs[5] = creature->GetGUID(); break;
                case NPC_ANGERREL: TombBossGUIDs[6] = creature->GetGUID(); break;
                case NPC_MAGMUS:
                    MagmusGUID = creature->GetGUID();
                    if (!creature->IsAlive())
                        HandleGameObject(GetGuidData(DATA_THRONE_DOOR), true); // if Magmus is dead open door to last boss
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_ARENA1: GoArena1GUID = go->GetGUID(); break;
                case GO_ARENA2: GoArena2GUID = go->GetGUID(); break;
                case GO_ARENA3: GoArena3GUID = go->GetGUID(); break;
                case GO_ARENA4: GoArena4GUID = go->GetGUID(); break;
                case GO_SHADOW_LOCK: GoShadowLockGUID = go->GetGUID(); break;
                case GO_SHADOW_MECHANISM: GoShadowMechGUID = go->GetGUID(); break;
                case GO_SHADOW_GIANT_DOOR: GoShadowGiantGUID = go->GetGUID(); break;
                case GO_SHADOW_DUMMY: GoShadowDummyGUID = go->GetGUID(); break;
                case GO_BAR_KEG_SHOT: GoBarKegGUID = go->GetGUID(); break;
                case GO_BAR_KEG_TRAP: GoBarKegTrapGUID = go->GetGUID(); break;
                case GO_BAR_DOOR: GoBarDoorGUID = go->GetGUID(); break;
                case GO_TOMB_ENTER: GoTombEnterGUID = go->GetGUID(); break;
                case GO_TOMB_EXIT:
                    GoTombExitGUID = go->GetGUID();
                    if (GhostKillCount >= TOMB_OF_SEVEN_BOSS_NUM)
                        HandleGameObject(ObjectGuid::Empty, true, go);
                    else
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_LYCEUM: GoLyceumGUID = go->GetGUID(); break;
                case GO_SF_S: GoSFSGUID = go->GetGUID(); break;
                case GO_SF_N: GoSFNGUID = go->GetGUID(); break;
                case GO_GOLEM_ROOM_N: GoGolemNGUID = go->GetGUID(); break;
                case GO_GOLEM_ROOM_S: GoGolemSGUID = go->GetGUID(); break;
                case GO_THRONE_ROOM: GoThroneGUID = go->GetGUID(); break;
                case GO_CHEST_SEVEN: GoChestGUID = go->GetGUID(); break;
                case GO_SPECTRAL_CHALICE: GoSpectralChaliceGUID = go->GetGUID(); break;
            }
        }

        void OnUnitDeath(Unit* unit) override
        {
            switch (unit->GetEntry())
            {
                case NPC_LORD_ROCCOR: SetBossState(BOSS_LORD_ROCCOR, DONE); break;
                case NPC_HOUNDMASTER_GREBMAR: SetBossState(BOSS_HOUNDMASTER_GREBMAR, DONE); break;
                case NPC_PYROMANCER_LOREGRAIN: SetBossState(BOSS_PYROMANCER_LOREGRAIN, DONE); break;
                case NPC_LORD_INCENDIUS: SetBossState(BOSS_LORD_INCENDIUS, DONE); break;
                case NPC_WARDER_STILGISS: SetBossState(BOSS_WARDER_STILGISS, DONE); break;
                case NPC_FINEOUS_DARKVIRE: SetBossState(BOSS_FINEOUS_DARKVIRE, DONE); break;
                case NPC_BAELGAR: SetBossState(BOSS_BAELGAR, DONE); break;
                case NPC_GOLEM_LORD_ARGELMACH: SetBossState(BOSS_GOLEM_LORD_ARGELMACH, DONE); break;
                case NPC_HURLEY_BLACKBREATH: SetBossState(BOSS_HURLEY_BLACKBREATH, DONE); break;
                case NPC_RIBBLY_SCREWSPIGOT: SetBossState(BOSS_RIBBLY_SCREWSPIGOT, DONE); break;
                case NPC_PLUGGER_SPAZZRING: SetBossState(BOSS_PLUGGER_SPAZZRING, DONE); break;
                default: break;
            }
        }

        void SetGuidData(uint32 type, ObjectGuid data) override
        {
            TC_LOG_DEBUG("scripts", "Instance Blackrock Depths: SetGuidData update (Type: {} Data {})", type, data.ToString());

            switch (type)
            {
            case DATA_EVENSTARTER:
                TombEventStarterGUID = data;
                if (!TombEventStarterGUID)
                    TombOfSevenReset();//reset
                else
                    TombOfSevenStart();//start
                break;
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            TC_LOG_DEBUG("scripts", "Instance Blackrock Depths: SetData update (Type: {} Data {})", type, data);

            switch (type)
            {
                case TYPE_RING_OF_LAW:
                    SetBossState(BOSS_RING_OF_LAW, EncounterState(data));
                    break;
                case TYPE_VAULT:
                    SetBossState(1, EncounterState(data));
                    break;
                case TYPE_BAR:
                    if (data == SPECIAL)
                        ++BarAleCount;
                    else
                        SetBossState(2, EncounterState(data));
                    break;
                case TYPE_TOMB_OF_SEVEN:
                    SetBossState(BOSS_THE_SEVEN, EncounterState(data));
                    break;
                case TYPE_LYCEUM:
                    SetBossState(4, EncounterState(data));
                    break;
                case TYPE_IRON_HALL:
                    SetBossState(BOSS_MAGMUS, EncounterState(data));
                    break;
                case DATA_GHOSTKILL:
                    GhostKillCount += data;
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case TYPE_RING_OF_LAW:
                    return GetBossState(BOSS_RING_OF_LAW);
                case TYPE_VAULT:
                    return GetBossState(1);
                case TYPE_BAR:
                    if (GetBossState(2) == IN_PROGRESS && BarAleCount == 3)
                        return SPECIAL;
                    else
                        return GetBossState(2);
                case TYPE_TOMB_OF_SEVEN:
                    return GetBossState(BOSS_THE_SEVEN);
                case TYPE_LYCEUM:
                    return GetBossState(4);
                case TYPE_IRON_HALL:
                    return GetBossState(BOSS_MAGMUS);
                case DATA_GHOSTKILL:
                    return GhostKillCount;
            }
            return 0;
        }

        ObjectGuid GetGuidData(uint32 data) const override
        {
            switch (data)
            {
                case DATA_EMPEROR:
                    return EmperorGUID;
                case DATA_PHALANX:
                    return PhalanxGUID;
                case DATA_MOIRA:
                    return MoiraGUID;
                case DATA_COREN:
                    return CorenGUID;
                case DATA_ARENA1:
                    return GoArena1GUID;
                case DATA_ARENA2:
                    return GoArena2GUID;
                case DATA_ARENA3:
                    return GoArena3GUID;
                case DATA_ARENA4:
                    return GoArena4GUID;
                case DATA_GO_BAR_KEG:
                    return GoBarKegGUID;
                case DATA_GO_BAR_KEG_TRAP:
                    return GoBarKegTrapGUID;
                case DATA_GO_BAR_DOOR:
                    return GoBarDoorGUID;
                case DATA_EVENSTARTER:
                    return TombEventStarterGUID;
                case DATA_SF_BRAZIER_N:
                    return GoSFNGUID;
                case DATA_SF_BRAZIER_S:
                    return GoSFSGUID;
                case DATA_THRONE_DOOR:
                    return GoThroneGUID;
                case DATA_GOLEM_DOOR_N:
                    return GoGolemNGUID;
                case DATA_GOLEM_DOOR_S:
                    return GoGolemSGUID;
                case DATA_GO_CHALICE:
                    return GoSpectralChaliceGUID;
            }
            return ObjectGuid::Empty;
        }

        void TombOfSevenEvent()
        {
            if (GhostKillCount < TOMB_OF_SEVEN_BOSS_NUM && !TombBossGUIDs[TombEventCounter].IsEmpty())
            {
                if (Creature* boss = instance->GetCreature(TombBossGUIDs[TombEventCounter]))
                {
                    boss->SetFaction(FACTION_DARK_IRON_DWARVES);
                    boss->SetImmuneToPC(false);
                    if (Unit* target = boss->SelectNearestTarget(500))
                        boss->AI()->AttackStart(target);
                }
            }
        }

        void TombOfSevenReset()
        {
            HandleGameObject(GoTombExitGUID, false);//event reseted, close exit door
            HandleGameObject(GoTombEnterGUID, true);//event reseted, open entrance door
            for (uint8 i = 0; i < TOMB_OF_SEVEN_BOSS_NUM; ++i)
            {
                if (Creature* boss = instance->GetCreature(TombBossGUIDs[i]))
                {
                    if (!boss->IsAlive())
                        boss->Respawn();
                    else
                        boss->SetFaction(FACTION_FRIENDLY);
                }
            }
            GhostKillCount = 0;
            TombEventStarterGUID.Clear();
            TombEventCounter = 0;
            TombTimer = TIMER_TOMBOFTHESEVEN;
            SetData(TYPE_TOMB_OF_SEVEN, NOT_STARTED);
        }

        void TombOfSevenStart()
        {
            HandleGameObject(GoTombExitGUID, false);//event started, close exit door
            HandleGameObject(GoTombEnterGUID, false);//event started, close entrance door
            SetData(TYPE_TOMB_OF_SEVEN, IN_PROGRESS);
        }

        void TombOfSevenEnd()
        {
            DoRespawnGameObject(GoChestGUID, 24h);
            HandleGameObject(GoTombExitGUID, true);//event done, open exit door
            HandleGameObject(GoTombEnterGUID, true);//event done, open entrance door
            TombEventStarterGUID.Clear();
            SetData(TYPE_TOMB_OF_SEVEN, DONE);
        }
        void Update(uint32 diff) override
        {
            if (!TombEventStarterGUID.IsEmpty() && GhostKillCount < TOMB_OF_SEVEN_BOSS_NUM)
            {
                if (TombTimer <= diff)
                {
                    TombTimer = TIMER_TOMBOFTHESEVEN;
                    if (TombEventCounter < TOMB_OF_SEVEN_BOSS_NUM)
                    {
                        TombOfSevenEvent();
                        ++TombEventCounter;
                    }

                    // Check Killed bosses
                    for (uint8 i = 0; i < TOMB_OF_SEVEN_BOSS_NUM; ++i)
                    {
                        if (Creature* boss = instance->GetCreature(TombBossGUIDs[i]))
                        {
                            if (!boss->IsAlive())
                            {
                                GhostKillCount = i+1;
                             }
                        }
                    }
                } else TombTimer -= diff;
            }
            if (GhostKillCount >= TOMB_OF_SEVEN_BOSS_NUM && !TombEventStarterGUID.IsEmpty())
                TombOfSevenEnd();
        }
    };
};

void AddSC_instance_blackrock_depths()
{
    new instance_blackrock_depths();
}
