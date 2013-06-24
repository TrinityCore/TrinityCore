/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectDefines.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "blackrock_spire.h"
#include "InstanceScript.h"

uint32 const DragonspireRunes[7] = { GO_ROOM_1_RUNE, GO_ROOM_2_RUNE, GO_ROOM_3_RUNE, GO_ROOM_4_RUNE, GO_ROOM_5_RUNE, GO_ROOM_6_RUNE, GO_ROOM_7_RUNE };

uint32 const DragonspireMobs[3] = { NPC_BLACKHAND_DREADWEAVER, NPC_BLACKHAND_SUMMONER, NPC_BLACKHAND_VETERAN };

enum EventIds
{
    EVENT_DARGONSPIRE_ROOM_STORE           = 1,
    EVENT_DARGONSPIRE_ROOM_CHECK           = 2
};

class instance_blackrock_spire : public InstanceMapScript
{
public:
    instance_blackrock_spire() : InstanceMapScript(BRSScriptName, 229) { }

    struct instance_blackrock_spireMapScript : public InstanceScript
    {
        instance_blackrock_spireMapScript(InstanceMap* map) : InstanceScript(map) { }

        void Initialize()
        {
            SetBossNumber(EncounterCount);
            HighlordOmokk           = 0;
            ShadowHunterVoshgajin   = 0;
            WarMasterVoone          = 0;
            MotherSmolderweb        = 0;
            UrokDoomhowl            = 0;
            QuartermasterZigris     = 0;
            GizrultheSlavener       = 0;
            Halycon                 = 0;
            OverlordWyrmthalak      = 0;
            PyroguardEmberseer      = 0;
            WarchiefRendBlackhand   = 0;
            Gyth                    = 0;
            TheBeast                = 0;
            GeneralDrakkisath       = 0;
            go_emberseerin          = 0;
            go_doors                = 0;
            go_emberseerout         = 0;
            go_blackrockaltar       = 0;
        }

        void OnPlayerEnter(Player* /*player*/)
        {
            if ((GetBossState(DATA_DRAGONSPIRE_ROOM) != DONE))
                Events.ScheduleEvent(EVENT_DARGONSPIRE_ROOM_STORE, 4000);
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < EncounterCount; ++i)
            {
                if (encounter[i] == IN_PROGRESS)
                    return true;
            }
            return false;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_OMOKK:
                    HighlordOmokk = creature->GetGUID();
                    break;
                case NPC_SHADOW_HUNTER_VOSHGAJIN:
                    ShadowHunterVoshgajin = creature->GetGUID();
                    break;
                case NPC_WARMASTER_VOONE:
                    WarMasterVoone = creature->GetGUID();
                    break;
                case NPC_MOTHER_SMOLDERWEB:
                    MotherSmolderweb = creature->GetGUID();
                    break;
                case NPC_UROK_DOOMHOWL:
                    UrokDoomhowl = creature->GetGUID();
                    break;
                case NPC_QUARTERMASTER_ZIGRIS:
                    QuartermasterZigris = creature->GetGUID();
                    break;
                case NPC_GIZRUL_THE_SLAVENER:
                    GizrultheSlavener = creature->GetGUID();
                    break;
                case  NPC_HALYCON:
                    Halycon = creature->GetGUID();
                    break;
                case  NPC_OVERLORD_WYRMTHALAK:
                    OverlordWyrmthalak = creature->GetGUID();
                    break;
                case  NPC_PYROGAURD_EMBERSEER:
                    PyroguardEmberseer = creature->GetGUID();
                    if ((GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE))
                        creature->DespawnOrUnsummon();
                    break;
                case  NPC_WARCHIEF_REND_BLACKHAND:
                    WarchiefRendBlackhand = creature->GetGUID();
                    break;
                case NPC_GYTH:
                    Gyth = creature->GetGUID();
                    break;
                case NPC_THE_BEAST:
                    TheBeast = creature->GetGUID();
                    break;
                case NPC_GENERAL_DRAKKISATH:
                    GeneralDrakkisath = creature->GetGUID();
                    break;
                case NPC_BLACKHAND_DREADWEAVER:
                case NPC_BLACKHAND_SUMMONER:
                case NPC_BLACKHAND_VETERAN:
                    break;
             }
         }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_WHELP_SPAWNER:
                    go->CastSpell(NULL, SPELL_SUMMON_ROOKERY_WHELP);
                    break;
                case GO_EMBERSEER_IN:
                    go_emberseerin = go->GetGUID();
                    if ((GetBossState(DATA_DRAGONSPIRE_ROOM) == DONE))
                        go->SetGoState(GO_STATE_ACTIVE);
                    break;
                case GO_DOORS:
                    go_doors = go->GetGUID();
                    if ((GetBossState(DATA_DRAGONSPIRE_ROOM) == DONE))
                        go->SetGoState(GO_STATE_ACTIVE);
                    break;
                case GO_EMBERSEER_OUT:
                    go_emberseerout = go->GetGUID();
                    if ((GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE))
                        go->SetGoState(GO_STATE_ACTIVE);
                    break;
                case GO_BLACKROCK_ALTAR:
                    go_blackrockaltar = go->GetGUID();
                    if ((GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE))
                        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                    break;
                case GO_ROOM_1_RUNE:
                    go_roomrunes[0] = go->GetGUID();
                    if ((GetBossState(DATA_ROOM_1_RUNE) == DONE))
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_ROOM_2_RUNE:
                    go_roomrunes[1] = go->GetGUID();
                    if ((GetBossState(DATA_ROOM_2_RUNE) == DONE))
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_ROOM_3_RUNE:
                    go_roomrunes[2] = go->GetGUID();
                    if ((GetBossState(DATA_ROOM_3_RUNE) == DONE))
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_ROOM_4_RUNE:
                    go_roomrunes[3] = go->GetGUID();
                    if ((GetBossState(DATA_ROOM_4_RUNE) == DONE))
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_ROOM_5_RUNE:
                    go_roomrunes[4] = go->GetGUID();
                    if ((GetBossState(DATA_ROOM_5_RUNE) == DONE))
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_ROOM_6_RUNE:
                    go_roomrunes[5] = go->GetGUID();
                    if ((GetBossState(DATA_ROOM_6_RUNE) == DONE))
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_ROOM_7_RUNE:
                    go_roomrunes[6] = go->GetGUID();
                    if ((GetBossState(DATA_ROOM_7_RUNE) == DONE))
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_EMBERSEER_RUNE_1:
                    go_emberseerrunes[0] = go->GetGUID();
                    if ((GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE))
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_EMBERSEER_RUNE_2:
                    go_emberseerrunes[1] = go->GetGUID();
                    if ((GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE))
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_EMBERSEER_RUNE_3:
                    go_emberseerrunes[2] = go->GetGUID();
                    if ((GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE))
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_EMBERSEER_RUNE_4:
                    go_emberseerrunes[3] = go->GetGUID();
                    if ((GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE))
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_EMBERSEER_RUNE_5:
                    go_emberseerrunes[4] = go->GetGUID();
                    if ((GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE))
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_EMBERSEER_RUNE_6:
                    go_emberseerrunes[5] = go->GetGUID();
                    if ((GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE))
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_EMBERSEER_RUNE_7:
                    go_emberseerrunes[6] = go->GetGUID();
                    if ((GetBossState(DATA_PYROGAURD_EMBERSEER) == DONE))
                        go->SetGoState(GO_STATE_READY);
                    break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state)
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
                case DATA_OMOKK:
                case DATA_SHADOW_HUNTER_VOSHGAJIN:
                case DATA_WARMASTER_VOONE:
                case DATA_MOTHER_SMOLDERWEB:
                case DATA_UROK_DOOMHOWL:
                case DATA_QUARTERMASTER_ZIGRIS:
                case DATA_GIZRUL_THE_SLAVENER:
                case DATA_HALYCON:
                case DATA_OVERLORD_WYRMTHALAK:
                case DATA_PYROGAURD_EMBERSEER:
                case DATA_WARCHIEF_REND_BLACKHAND:
                case DATA_GYTH:
                case DATA_THE_BEAST:
                case DATA_GENERAL_DRAKKISATH:
                case DATA_DRAGONSPIRE_ROOM:
                default:
                    break;
            }

             return true;
        }

        void ProcessEvent(WorldObject* /*gameObject*/, uint32 eventId)
        {
            switch (eventId)
            {
                case EVENT_PYROGUARD_EMBERSEER:
                    if (GetBossState(DATA_PYROGAURD_EMBERSEER) == NOT_STARTED)
                        if (Creature* Emberseer = instance->GetCreature(PyroguardEmberseer))
                            Emberseer->AI()->SetData(1, 1);
                    break;
                default:
                    break;
            }
        }

        uint64 GetData64(uint32 type) const
        {
            switch (type)
            {
                case DATA_OMOKK:
                    return HighlordOmokk;
                    break;
                case DATA_SHADOW_HUNTER_VOSHGAJIN:
                    return ShadowHunterVoshgajin;
                    break;
                case DATA_WARMASTER_VOONE:
                    return WarMasterVoone;
                    break;
                case DATA_MOTHER_SMOLDERWEB:
                    return MotherSmolderweb;
                    break;
                case DATA_UROK_DOOMHOWL:
                    return UrokDoomhowl;
                    break;
                case DATA_QUARTERMASTER_ZIGRIS:
                    return QuartermasterZigris;
                    break;
                case DATA_GIZRUL_THE_SLAVENER:
                    return GizrultheSlavener;
                    break;
                case DATA_HALYCON:
                    return Halycon;
                    break;
                case DATA_OVERLORD_WYRMTHALAK:
                    return OverlordWyrmthalak;
                    break;
                case DATA_PYROGAURD_EMBERSEER:
                    return PyroguardEmberseer;
                    break;
                case DATA_WARCHIEF_REND_BLACKHAND:
                    return WarchiefRendBlackhand;
                    break;
                case DATA_GYTH:
                    return Gyth;
                    break;
                case DATA_THE_BEAST:
                    return TheBeast;
                    break;
                case DATA_GENERAL_DRAKKISATH:
                    return GeneralDrakkisath;
                    break;
                case GO_EMBERSEER_IN:
                    return go_emberseerin;
                    break;
                case GO_DOORS:
                    return go_doors;
                    break;
                case GO_EMBERSEER_OUT:
                    return go_emberseerout;
                    break;
                case GO_BLACKROCK_ALTAR:
                    return go_blackrockaltar;
                    break;
                case GO_ROOM_1_RUNE:
                    return go_roomrunes[0];
                    break;
                case GO_ROOM_2_RUNE:
                    return go_roomrunes[1];
                    break;
                case GO_ROOM_3_RUNE:
                    return go_roomrunes[2];
                    break;
                case GO_ROOM_4_RUNE:
                    return go_roomrunes[3];
                    break;
                case GO_ROOM_5_RUNE:
                    return go_roomrunes[4];
                    break;
                case GO_ROOM_6_RUNE:
                    return go_roomrunes[5];
                    break;
                case GO_ROOM_7_RUNE:
                    return go_roomrunes[6];
                    break;
                case GO_EMBERSEER_RUNE_1:
                    return go_emberseerrunes[0];
                    break;
                case GO_EMBERSEER_RUNE_2:
                    return go_emberseerrunes[1];
                    break;
                case GO_EMBERSEER_RUNE_3:
                    return go_emberseerrunes[2];
                    break;
                case GO_EMBERSEER_RUNE_4:
                    return go_emberseerrunes[3];
                    break;
                case GO_EMBERSEER_RUNE_5:
                    return go_emberseerrunes[4];
                    break;
                case GO_EMBERSEER_RUNE_6:
                    return go_emberseerrunes[5];
                    break;
                case GO_EMBERSEER_RUNE_7:
                    return go_emberseerrunes[6];
                    break;
            }
            return 0;
        }

        void Update(uint32 diff)
        {
            Events.Update(diff);

            while (uint32 eventId = Events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DARGONSPIRE_ROOM_STORE:
                        Dragonspireroomstore();
                        Events.ScheduleEvent(EVENT_DARGONSPIRE_ROOM_CHECK, 2500);
                        break;
                    case EVENT_DARGONSPIRE_ROOM_CHECK:
                        Dragonspireroomcheck();
                        if ((GetBossState(DATA_DRAGONSPIRE_ROOM) != DONE))
                            Events.ScheduleEvent(EVENT_DARGONSPIRE_ROOM_CHECK, 2500);
                        break;
                    default:
                         break;
                }
            }
        }

        void Dragonspireroomstore()
        {
            uint8 creaturecount;

            for (uint8 i = 0; i < 7; ++i)
            {
                creaturecount = 0;

                if (GameObject* rune = instance->GetGameObject(go_roomrunes[i]))
                {
                    for (uint8 ii = 0; ii < 3; ++ii)
                    {
                        std::list<Creature*> creatureList;
                        GetCreatureListWithEntryInGrid(creatureList, rune, DragonspireMobs[ii], 15.0f);
                        for (std::list<Creature*>::iterator itr = creatureList.begin(); itr != creatureList.end(); ++itr)
                        {
                            if (Creature* creatureList = *itr)
                            {
                                runecreaturelist[i] [creaturecount] = creatureList->GetGUID();
                                ++creaturecount;
                            }
                        }
                    }
                }
            }
        }

        void Dragonspireroomcheck()
        {
            for (uint8 i = 0; i < 7; ++i)
            {
                bool _mobAlive = false;

                if (GameObject* rune = instance->GetGameObject(go_roomrunes[i]))
                {
                    if (rune->GetGoState() == GO_STATE_ACTIVE)
                    {
                        for (uint8 ii = 0; ii < 5; ++ii)
                        {
                            if (Creature* mob = instance->GetCreature(runecreaturelist[i] [ii]))
                            {
                                if (mob->IsAlive())
                                    _mobAlive = true;
                            }
                        }
                    }

                    if (!_mobAlive && rune->GetGoState() == GO_STATE_ACTIVE)
                    {
                        rune->SetGoState(GO_STATE_READY);

                        switch (rune->GetEntry())
                        {
                            case GO_ROOM_1_RUNE:
                                SetBossState(DATA_ROOM_1_RUNE, DONE);
                                break;
                            case GO_ROOM_2_RUNE:
                                SetBossState(DATA_ROOM_2_RUNE, DONE);
                                break;
                            case GO_ROOM_3_RUNE:
                                SetBossState(DATA_ROOM_3_RUNE, DONE);
                                break;
                            case GO_ROOM_4_RUNE:
                                SetBossState(DATA_ROOM_4_RUNE, DONE);
                                break;
                            case GO_ROOM_5_RUNE:
                                SetBossState(DATA_ROOM_5_RUNE, DONE);
                                break;
                            case GO_ROOM_6_RUNE:
                                SetBossState(DATA_ROOM_6_RUNE, DONE);
                                break;
                            case GO_ROOM_7_RUNE:
                                SetBossState(DATA_ROOM_7_RUNE, DONE);
                                break;
                        }
                    }

                    if (GetBossState(DATA_ROOM_1_RUNE) == DONE && GetBossState(DATA_ROOM_2_RUNE) == DONE && GetBossState(DATA_ROOM_3_RUNE) == DONE &&
                        GetBossState(DATA_ROOM_4_RUNE) == DONE &&GetBossState(DATA_ROOM_5_RUNE) == DONE && GetBossState(DATA_ROOM_6_RUNE) == DONE &&
                        GetBossState(DATA_ROOM_7_RUNE) == DONE)
                    {
                        SetBossState(DATA_DRAGONSPIRE_ROOM, DONE);
                        if (GameObject* door1 = instance->GetGameObject(go_emberseerin))
                            door1->SetGoState(GO_STATE_ACTIVE);
                        if (GameObject* door2 = instance->GetGameObject(go_doors))
                            door2->SetGoState(GO_STATE_ACTIVE);
                    }
                }
            }
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "B S " << GetBossSaveData();

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void Load(const char* strIn)
        {
            if (!strIn)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(strIn);

            char dataHead1, dataHead2;

            std::istringstream loadStream(strIn);
            loadStream >> dataHead1 >> dataHead2;

            if (dataHead1 == 'B' && dataHead2 == 'S')
            {
                for (uint8 i = 0; i < EncounterCount; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;
                }
            }

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        protected:
            EventMap Events;
            uint32 encounter[EncounterCount];
            std::string m_strInstData;
            uint64 HighlordOmokk;
            uint64 ShadowHunterVoshgajin;
            uint64 WarMasterVoone;
            uint64 MotherSmolderweb;
            uint64 UrokDoomhowl;
            uint64 QuartermasterZigris;
            uint64 GizrultheSlavener;
            uint64 Halycon;
            uint64 OverlordWyrmthalak;
            uint64 PyroguardEmberseer;
            uint64 WarchiefRendBlackhand;
            uint64 Gyth;
            uint64 TheBeast;
            uint64 GeneralDrakkisath;
            uint64 go_emberseerin;
            uint64 go_doors;
            uint64 go_emberseerout;
            uint64 go_blackrockaltar;
            uint64 go_roomrunes[7];
            uint64 go_emberseerrunes[7];
            uint64 runecreaturelist[7] [5];
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_blackrock_spireMapScript(map);
    }

};

void AddSC_instance_blackrock_spire()
{
    new instance_blackrock_spire();
}
