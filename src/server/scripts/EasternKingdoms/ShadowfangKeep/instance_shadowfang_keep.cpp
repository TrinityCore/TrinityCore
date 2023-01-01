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
SDName: Instance_Shadowfang_Keep
SD%Complete: 90
SDComment:
SDCategory: Shadowfang Keep
EndScriptData */

#include "ScriptMgr.h"
#include "shadowfang_keep.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

#define MAX_ENCOUNTER              4

enum Yells
{
    SAY_BOSS_DIE_AD         = 4,
    SAY_BOSS_DIE_AS         = 3,
    SAY_ARCHMAGE            = 0
};

enum Creatures
{
    NPC_ASH                 = 3850,
    NPC_ADA                 = 3849,
    NPC_ARCHMAGE_ARUGAL     = 4275,
    NPC_ARUGAL_VOIDWALKER   = 4627
};

enum GameObjects
{
    GO_COURTYARD_DOOR       = 18895, //door to open when talking to NPC's
    GO_SORCERER_DOOR        = 18972, //door to open when Fenrus the Devourer
    GO_ARUGAL_DOOR          = 18971  //door to open when Wolf Master Nandos
};

enum Spells
{
    SPELL_ASHCROMBE_TELEPORT    = 15742
};

const Position SpawnLocation[] =
{
    {-148.199f, 2165.647f, 128.448f, 1.026f},
    {-153.110f, 2168.620f, 128.448f, 1.026f},
    {-145.905f, 2180.520f, 128.448f, 4.183f},
    {-140.794f, 2178.037f, 128.448f, 4.090f},
    {-138.640f, 2170.159f, 136.577f, 2.737f}
};
class instance_shadowfang_keep : public InstanceMapScript
{
public:
    instance_shadowfang_keep() : InstanceMapScript(SFKScriptName, 33) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_shadowfang_keep_InstanceMapScript(map);
    }

    struct instance_shadowfang_keep_InstanceMapScript : public InstanceScript
    {
        instance_shadowfang_keep_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(MAX_ENCOUNTER);

            uiPhase = 0;
            uiTimer = 0;
        }

        ObjectGuid uiAshGUID;
        ObjectGuid uiAdaGUID;
        ObjectGuid uiArchmageArugalGUID;

        ObjectGuid DoorCourtyardGUID;
        ObjectGuid DoorSorcererGUID;
        ObjectGuid DoorArugalGUID;

        uint8 uiPhase;
        uint16 uiTimer;

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_ASH: uiAshGUID = creature->GetGUID(); break;
                case NPC_ADA: uiAdaGUID = creature->GetGUID(); break;
                case NPC_ARCHMAGE_ARUGAL: uiArchmageArugalGUID = creature->GetGUID(); break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_COURTYARD_DOOR:
                    DoorCourtyardGUID = go->GetGUID();
                    if (GetBossState(0) == DONE)
                        HandleGameObject(ObjectGuid::Empty, true, go);
                    break;
                case GO_SORCERER_DOOR:
                    DoorSorcererGUID = go->GetGUID();
                    if (GetBossState(2) == DONE)
                        HandleGameObject(ObjectGuid::Empty, true, go);
                    break;
                case GO_ARUGAL_DOOR:
                    DoorArugalGUID = go->GetGUID();
                    if (GetBossState(3) == DONE)
                        HandleGameObject(ObjectGuid::Empty, true, go);
                    break;
            }
        }

        void DoSpeech()
        {
            Creature* pAda = instance->GetCreature(uiAdaGUID);
            Creature* pAsh = instance->GetCreature(uiAshGUID);

            if (pAda && pAda->IsAlive() && pAsh && pAsh->IsAlive())
            {
                pAda->AI()->Talk(SAY_BOSS_DIE_AD);
                pAsh->AI()->Talk(SAY_BOSS_DIE_AS);
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case TYPE_FREE_NPC:
                    if (data == DONE)
                        DoUseDoorOrButton(DoorCourtyardGUID);
                    SetBossState(0, EncounterState(data));
                    break;
                case TYPE_RETHILGORE:
                    if (data == DONE)
                        DoSpeech();
                    SetBossState(1, EncounterState(data));
                    break;
                case TYPE_FENRUS:
                    switch (data)
                    {
                        case DONE:
                            uiTimer = 1000;
                            uiPhase = 1;
                            break;
                        case 7:
                            DoUseDoorOrButton(DoorSorcererGUID);
                            break;
                    }
                    SetBossState(2, EncounterState(data));
                    break;
                case TYPE_NANDOS:
                    if (data == DONE)
                        DoUseDoorOrButton(DoorArugalGUID);
                    SetBossState(3, EncounterState(data));
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case TYPE_FREE_NPC:
                    return GetBossState(0);
                case TYPE_RETHILGORE:
                    return GetBossState(1);
                case TYPE_FENRUS:
                    return GetBossState(2);
                case TYPE_NANDOS:
                    return GetBossState(3);
            }
            return 0;
        }

        void Update(uint32 uiDiff) override
        {
            if (GetData(TYPE_FENRUS) != DONE)
                return;

            Creature* pArchmage = instance->GetCreature(uiArchmageArugalGUID);

            if (!pArchmage || !pArchmage->IsAlive())
                return;

            if (uiPhase)
            {
                if (uiTimer <= uiDiff)
                {
                    switch (uiPhase)
                    {
                        case 1:
                        {
                            Creature* summon = pArchmage->SummonCreature(pArchmage->GetEntry(), SpawnLocation[4], TEMPSUMMON_TIMED_DESPAWN, 10s);
                            summon->SetImmuneToPC(true);
                            summon->SetReactState(REACT_DEFENSIVE);
                            summon->CastSpell(summon, SPELL_ASHCROMBE_TELEPORT, true);
                            summon->AI()->Talk(SAY_ARCHMAGE);
                            uiTimer = 2000;
                            uiPhase = 2;
                            break;
                        }
                        case 2:
                        {
                            pArchmage->SummonCreature(NPC_ARUGAL_VOIDWALKER, SpawnLocation[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1min);
                            pArchmage->SummonCreature(NPC_ARUGAL_VOIDWALKER, SpawnLocation[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1min);
                            pArchmage->SummonCreature(NPC_ARUGAL_VOIDWALKER, SpawnLocation[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1min);
                            pArchmage->SummonCreature(NPC_ARUGAL_VOIDWALKER, SpawnLocation[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1min);
                            uiPhase = 0;
                            break;
                        }

                    }
                } else uiTimer -= uiDiff;
            }
        }
    };

};

void AddSC_instance_shadowfang_keep()
{
    new instance_shadowfang_keep();
}
