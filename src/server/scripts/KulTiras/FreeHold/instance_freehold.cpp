/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "Creature.h"
#include "Group.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "World.h"
#include "InstanceScript.h"
#include "freehold.h"

struct instance_free_hold : public InstanceScript
{
    instance_free_hold(InstanceMap* map) : InstanceScript(map) { }
    
        void Initialize() override
    {
        skycapGuid = ObjectGuid::Empty;
        sharkbaitGuid = ObjectGuid::Empty;
        jollyGuid = ObjectGuid::Empty;
        eudoraGuid = ObjectGuid::Empty;
        raoulGuid = ObjectGuid::Empty;
        lightningGuid = ObjectGuid::Empty;
        tortollanGuid = ObjectGuid::Empty;
        trothakGuid = ObjectGuid::Empty;
        harlanGuid = ObjectGuid::Empty;
        gukgukGuid = ObjectGuid::Empty;
        gurgthockGuid = ObjectGuid::Empty;
        daveyGuid = ObjectGuid::Empty;
        captainsControllerGuid = ObjectGuid::Empty;
        countRaoul = 0;
        SetBossNumber(FreeholdData::DataMaxEncounters);
    }

    void OnCreatureCreate(Creature* creature) override
    {
        if (instance->IsHeroic())
            creature->SetBaseHealth(creature->GetMaxHealth() * 2.f);
        if (instance->IsMythic())
            creature->SetBaseHealth(creature->GetMaxHealth() * 1.33f);

        switch (creature->GetEntry())
        {
        case uint32(FreeholdCreature::NpcSkycapKragg):
            skycapGuid = creature->GetGUID();
            break;
        case uint32(FreeholdCreature::NpcSharkBaitBoss):
            sharkbaitGuid = creature->GetGUID();
            break;
        case uint32(FreeholdCreature::NpcCaptainJolly):
            jollyGuid = creature->GetGUID();
            break;
        case uint32(FreeholdCreature::NpcCaptainEudora):
            eudoraGuid = creature->GetGUID();
            break;
        case uint32(FreeholdCreature::NpcCaptainRaoul):
            raoulGuid = creature->GetGUID();
            break;
        case uint32(FreeholdCreature::NpcGukguk):
            gukgukGuid = creature->GetGUID();
            break;
        case uint32(FreeholdCreature::NpcGurgthock):
            gurgthockGuid = creature->GetGUID();
            break;
        case uint32(FreeholdCreature::NpcDavey):
            daveyGuid = creature->GetGUID();
            break;
        case uint32(FreeholdCreature::NpcLightning):
            lightningGuid = creature->GetGUID();
            break;
        case uint32(FreeholdCreature::NpcLudwigVonTortollan):
            tortollanGuid = creature->GetGUID();
            break;
        case uint32(FreeholdCreature::NpcTrothak):
            trothakGuid = creature->GetGUID();
            break;
        case uint32(FreeholdCreature::NpcHarlanSweete):
            harlanGuid = creature->GetGUID();
            break;
        case uint32(FreeholdCreature::NpcCaptainsController):
            captainsControllerGuid = creature->GetGUID();
            break;
        default:
            break;
        }
    }

    void OnPlayerEnter(Player* player) override
    {
        if (GetData(FreeholdData::DataCounciloCaptains) != DONE)
        {
            if (countRaoul >= 2)
            {
                if (Creature* raoul = instance->GetCreature(raoulGuid))
                {
                    raoul->AI()->DoAction(FreeholdAction::ActionSelectCaptainRaoul);
                }
            }
        }
    }

    void OnUnitDeath(Unit* unit) override
    {
        if (!unit->IsCreature())
            return;

        if (GetData(FreeholdData::DataCounciloCaptains) != DONE)
        {
            if (unit->GetEntry() == FreeholdCreature::NpcBlacktoothKnuckleduster)
            {
                countRaoul++;

                if (countRaoul >= 2)
                {
                    if (Creature* raoul = instance->GetCreature(raoulGuid))
                    {
                        raoul->AI()->DoAction(FreeholdAction::ActionSelectCaptainRaoul);
                    }
                }
            }
        }
    }

    ObjectGuid GetGuidData(uint32 type) const override
    {
        switch (type)
        {
        case uint32(FreeholdCreature::NpcSkycapKragg):
            return skycapGuid;
            break;
        case uint32(FreeholdCreature::NpcSharkBaitBoss):
            return sharkbaitGuid;
            break;
        case uint32(FreeholdCreature::NpcCaptainJolly):
            return jollyGuid;
            break;
        case uint32(FreeholdCreature::NpcCaptainEudora):
            return eudoraGuid;
            break;
        case uint32(FreeholdCreature::NpcCaptainRaoul):
            return raoulGuid;
            break;
        case uint32(FreeholdCreature::NpcGukguk):
            return gukgukGuid;
            break;
        case uint32(FreeholdCreature::NpcGurgthock):
            return gurgthockGuid;
            break;
        case uint32(FreeholdCreature::NpcDavey):
            return daveyGuid;
            break;
        case uint32(FreeholdCreature::NpcLightning):
            return lightningGuid;
            break;
        case uint32(FreeholdCreature::NpcLudwigVonTortollan):
            return tortollanGuid;
            break;
        case uint32(FreeholdCreature::NpcTrothak):
            return trothakGuid;
            break;
        case uint32(FreeholdCreature::NpcHarlanSweete):
            return harlanGuid;
            break;
        case DataCaptainsController:
            return captainsControllerGuid;
        default:
            break;
        }

        return ObjectGuid::Empty;
    }

    ObjectGuid skycapGuid;
    ObjectGuid sharkbaitGuid;
    ObjectGuid jollyGuid;
    ObjectGuid eudoraGuid;
    ObjectGuid raoulGuid;
    ObjectGuid lightningGuid;
    ObjectGuid tortollanGuid;
    ObjectGuid trothakGuid;
    ObjectGuid harlanGuid;
    ObjectGuid gukgukGuid;
    ObjectGuid gurgthockGuid;
    ObjectGuid daveyGuid;
    ObjectGuid captainsControllerGuid;
    uint8 countRaoul;
};

// 9000000 - NPC Teleporter Free Hold
class npc_free_hold_entrance_teleporter : public CreatureScript
{
public:
    npc_free_hold_entrance_teleporter() : CreatureScript("npc_free_hold_entrance_teleporter") { }
    struct npc_free_hold_entrance_teleporterAI : public ScriptedAI
    {
        npc_free_hold_entrance_teleporterAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        void UpdateAI(uint32 diff) override
        {
            std::list<Player*> targetList;
            GetPlayerListInGrid(targetList, me, 8.0f);

            if (!targetList.empty())
            {
                for (auto itr : targetList)
                {
                    if (Player* player = itr->ToPlayer())
                    {
                        if ((player->GetGroup() && player->GetGroup()->isRaidGroup()) || player->IsGameMaster())
                        {
                            uint32 playerMapID = player->GetMap()->GetId();

                            switch (playerMapID)
                            {
                            case 1643:
                                player->TeleportTo(1754, -1591.513f, -995.6175f, 73.85955f, 2.4204f, TELE_TO_NOT_LEAVE_COMBAT);
                                break;
                            case 1754:
                                player->TeleportTo(1643, -1576.46313f, -1298.69787f, 31.31189f, 5.513684f, TELE_TO_NOT_LEAVE_COMBAT);
                                break;
                            default:
                                break;
                            }
                        }
                    }
                }
            }
        }

    private:
        InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_free_hold_entrance_teleporterAI(creature);
    }
};

void AddSC_instance_freehold()
{
    RegisterInstanceScript(instance_free_hold, 1754);
    new npc_free_hold_entrance_teleporter();
}