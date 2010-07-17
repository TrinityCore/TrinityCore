/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Areatrigger_Scripts
SD%Complete: 100
SDComment: Scripts for areatriggers
SDCategory: Areatrigger
EndScriptData */

/* ContentData
at_aldurthar_gate               q13315/q13351
at_coilfang_waterfall           4591
at_legion_teleporter            4560 Teleporter TO Invasion Point: Cataclysm
at_ravenholdt
at_warsong_slaughterhouse
at_warsong_grainery
at_torp_farm
at_warsong_farms                q11686
at_stormwright_shelf            q12741
EndContentData */

#include "ScriptedPch.h"

/*######
## AreaTrigger_at_aldurthar_gate
######*/

enum eAldurtharGate
{
    TRIGGER_SOUTH                               = 5284,

    TRIGGER_CENTRAL                             = 5285,
    TRIGGER_NORTH                               = 5286,
    TRIGGER_NORTHWEST                           = 5287,

    NPC_SOUTH_GATE                              = 32195,
    NPC_CENTRAL_GATE                            = 32196,
    NPC_NORTH_GATE                              = 32197,
    NPC_NORTHWEST_GATE                          = 32199
};

bool AreaTrigger_at_aldurthar_gate(Player* pPlayer, const AreaTriggerEntry* pAt)
{
    switch(pAt->id)
    {
        case TRIGGER_SOUTH:     pPlayer->KilledMonsterCredit(NPC_SOUTH_GATE, 0);     break;
        case TRIGGER_CENTRAL:   pPlayer->KilledMonsterCredit(NPC_CENTRAL_GATE, 0);   break;
        case TRIGGER_NORTH:     pPlayer->KilledMonsterCredit(NPC_NORTH_GATE, 0);     break;
        case TRIGGER_NORTHWEST: pPlayer->KilledMonsterCredit(NPC_NORTHWEST_GATE, 0); break;
    }
    return true;
}

/*######
## at_coilfang_waterfall
######*/

enum eCoilfangGOs
{
    GO_COILFANG_WATERFALL   = 184212
};

bool AreaTrigger_at_coilfang_waterfall(Player *pPlayer, const AreaTriggerEntry * /*pAt*/)
{
    if (GameObject* pGo = GetClosestGameObjectWithEntry(pPlayer, GO_COILFANG_WATERFALL, 35.0f))
        if (pGo->getLootState() == GO_READY)
            pGo->UseDoorOrButton();

    return false;
}

/*#####
## at_legion_teleporter
#####*/

enum eLegionTeleporter
{
    SPELL_TELE_A_TO         = 37387,
    QUEST_GAINING_ACCESS_A  = 10589,

    SPELL_TELE_H_TO         = 37389,
    QUEST_GAINING_ACCESS_H  = 10604
};

bool AreaTrigger_at_legion_teleporter(Player *pPlayer, const AreaTriggerEntry * /*pAt*/)
{
    if (pPlayer->isAlive() && !pPlayer->isInCombat())
    {
        if (pPlayer->GetTeam() == ALLIANCE && pPlayer->GetQuestRewardStatus(QUEST_GAINING_ACCESS_A))
        {
            pPlayer->CastSpell(pPlayer, SPELL_TELE_A_TO, false);
            return true;
        }

        if (pPlayer->GetTeam() == HORDE && pPlayer->GetQuestRewardStatus(QUEST_GAINING_ACCESS_H))
        {
            pPlayer->CastSpell(pPlayer, SPELL_TELE_H_TO, false);
            return true;
        }

        return false;
    }
    return false;
}

enum eRavenholdt
{
    QUEST_MANOR_RAVENHOLDT  = 6681,
    NPC_RAVENHOLDT          = 13936
};

bool AreaTrigger_at_ravenholdt(Player* pPlayer, const AreaTriggerEntry* /*pAt*/)
{
    if (pPlayer->GetQuestStatus(QUEST_MANOR_RAVENHOLDT) == QUEST_STATUS_INCOMPLETE)
        pPlayer->KilledMonsterCredit(NPC_RAVENHOLDT, 0);

    return false;
}

/*######
## at_warsong_farms
######*/

enum eWarsongFarms
{
    QUEST_THE_WARSONG_FARMS                     = 11686,

    NPC_CREDIT_SLAUGHTERHOUSE                   = 25672,
    NPC_CREDIT_GRAINERY                         = 25669,
    NPC_CREDIT_TORP_FARM                        = 25671,

    AT_SLAUGHTERHOUSE                           = 4873,
    AT_GRAINERY                                 = 4871,
    AT_TORP_FARM                                = 4872
};

bool AreaTrigger_at_warsong_farms(Player* pPlayer, const AreaTriggerEntry* pAt)
{
    if (!pPlayer->isDead() && pPlayer->GetQuestStatus(QUEST_THE_WARSONG_FARMS) == QUEST_STATUS_INCOMPLETE)
    {
        switch(pAt->id)
        {
            case AT_SLAUGHTERHOUSE: pPlayer->KilledMonsterCredit(NPC_CREDIT_SLAUGHTERHOUSE, 0); break;
            case AT_GRAINERY:       pPlayer->KilledMonsterCredit(NPC_CREDIT_GRAINERY, 0);       break;
            case AT_TORP_FARM:      pPlayer->KilledMonsterCredit(NPC_CREDIT_TORP_FARM, 0);      break;
        }
    }
    return true;
 }

/*######
## at_stormwright_shelf
######*/

enum eStormwrightShelf
{
    QUEST_STRENGTH_OF_THE_TEMPEST               = 12741,

    SPELL_CREATE_TRUE_POWER_OF_THE_TEMPEST      = 53067
};

bool AreaTrigger_at_stormwright_shelf(Player* pPlayer, const AreaTriggerEntry* /*pAt*/)
{
    if (!pPlayer->isDead() && pPlayer->GetQuestStatus(QUEST_STRENGTH_OF_THE_TEMPEST) == QUEST_STATUS_INCOMPLETE)
        pPlayer->CastSpell(pPlayer, SPELL_CREATE_TRUE_POWER_OF_THE_TEMPEST, false);

    return true;
}

/*######
## at_scent_larkorwi
######*/

enum eScentLarkorwi
{
    QUEST_SCENT_OF_LARKORWI                     = 4291,
    NPC_LARKORWI_MATE                           = 9683
};

bool AreaTrigger_at_scent_larkorwi(Player* pPlayer, const AreaTriggerEntry* /*pAt*/)
{
    if (!pPlayer->isDead() && pPlayer->GetQuestStatus(QUEST_SCENT_OF_LARKORWI) == QUEST_STATUS_INCOMPLETE)
    {
        if (!pPlayer->FindNearestCreature(NPC_LARKORWI_MATE,15))
            pPlayer->SummonCreature(NPC_LARKORWI_MATE, pPlayer->GetPositionX()+5, pPlayer->GetPositionY(), pPlayer->GetPositionZ(), 3.3, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 100000);
    }

    return false;
}

/*#####
## at_last_rites
#####*/

enum eAtLastRites
{
    QUEST_LAST_RITES                          = 12019
};

bool AreaTrigger_at_last_rites(Player* pPlayer, const AreaTriggerEntry* pAt)
{
    if (pPlayer->GetQuestStatus(QUEST_LAST_RITES) != QUEST_STATUS_INCOMPLETE)
        return false;

    WorldLocation pPosition;

    switch(pAt->id)
    {
        case 5332:
        case 5338:
            pPosition = WorldLocation(571,3733.68,3563.25,290.812,3.665192);
            break;
        case 5334:
            pPosition = WorldLocation(571,3802.38,3585.95,49.5765,0);
            break;
        case 5340:
            pPosition = WorldLocation(571,3687.91,3577.28,473.342,0);
            break;
        default:
            return false;
    }

    pPlayer->TeleportTo(pPosition);

    return false;
}

void AddSC_areatrigger_scripts()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "at_aldurthar_gate";
    newscript->pAreaTrigger = &AreaTrigger_at_aldurthar_gate;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_coilfang_waterfall";
    newscript->pAreaTrigger = &AreaTrigger_at_coilfang_waterfall;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_legion_teleporter";
    newscript->pAreaTrigger = &AreaTrigger_at_legion_teleporter;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_ravenholdt";
    newscript->pAreaTrigger = &AreaTrigger_at_ravenholdt;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_warsong_farms";
    newscript->pAreaTrigger = &AreaTrigger_at_warsong_farms;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_stormwright_shelf";
    newscript->pAreaTrigger = &AreaTrigger_at_stormwright_shelf;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_scent_larkorwi";
    newscript->pAreaTrigger = &AreaTrigger_at_scent_larkorwi;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_last_rites";
    newscript->pAreaTrigger = &AreaTrigger_at_last_rites;
    newscript->RegisterSelf();
}
