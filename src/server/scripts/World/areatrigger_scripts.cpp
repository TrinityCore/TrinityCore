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

#include "ScriptPCH.h"

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

class AreaTrigger_at_aldurthar_gate : public AreaTriggerScript
{
    public:

        AreaTrigger_at_aldurthar_gate()
            : AreaTriggerScript("at_aldurthar_gate")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* trigger)
        {
            switch(trigger->id)
            {
                case TRIGGER_SOUTH:     player->KilledMonsterCredit(NPC_SOUTH_GATE, 0);     break;
                case TRIGGER_CENTRAL:   player->KilledMonsterCredit(NPC_CENTRAL_GATE, 0);   break;
                case TRIGGER_NORTH:     player->KilledMonsterCredit(NPC_NORTH_GATE, 0);     break;
                case TRIGGER_NORTHWEST: player->KilledMonsterCredit(NPC_NORTHWEST_GATE, 0); break;
            }
            return true;
        }
};

/*######
## at_coilfang_waterfall
######*/

enum eCoilfangGOs
{
    GO_COILFANG_WATERFALL   = 184212
};

class AreaTrigger_at_coilfang_waterfall : public AreaTriggerScript
{
    public:

        AreaTrigger_at_coilfang_waterfall()
            : AreaTriggerScript("at_coilfang_waterfall")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/)
        {
            if (GameObject* pGo = GetClosestGameObjectWithEntry(player, GO_COILFANG_WATERFALL, 35.0f))
                if (pGo->getLootState() == GO_READY)
                    pGo->UseDoorOrButton();

            return false;
        }
};

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

class AreaTrigger_at_legion_teleporter : public AreaTriggerScript
{
    public:

        AreaTrigger_at_legion_teleporter()
            : AreaTriggerScript("at_legion_teleporter")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/)
        {
            if (player->isAlive() && !player->isInCombat())
            {
                if (player->GetTeam() == ALLIANCE && player->GetQuestRewardStatus(QUEST_GAINING_ACCESS_A))
                {
                    player->CastSpell(player, SPELL_TELE_A_TO, false);
                    return true;
                }

                if (player->GetTeam() == HORDE && player->GetQuestRewardStatus(QUEST_GAINING_ACCESS_H))
                {
                    player->CastSpell(player, SPELL_TELE_H_TO, false);
                    return true;
                }

                return false;
            }
            return false;
        }
};

enum eRavenholdt
{
    QUEST_MANOR_RAVENHOLDT  = 6681,
    NPC_RAVENHOLDT          = 13936
};

class AreaTrigger_at_ravenholdt : public AreaTriggerScript
{
    public:

        AreaTrigger_at_ravenholdt()
            : AreaTriggerScript("at_ravenholdt")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/)
        {
            if (player->GetQuestStatus(QUEST_MANOR_RAVENHOLDT) == QUEST_STATUS_INCOMPLETE)
                player->KilledMonsterCredit(NPC_RAVENHOLDT, 0);

            return false;
        }
};

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

class AreaTrigger_at_warsong_farms : public AreaTriggerScript
{
    public:

        AreaTrigger_at_warsong_farms()
            : AreaTriggerScript("at_warsong_farms")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* trigger)
        {
            if (!player->isDead() && player->GetQuestStatus(QUEST_THE_WARSONG_FARMS) == QUEST_STATUS_INCOMPLETE)
            {
                switch(trigger->id)
                {
                    case AT_SLAUGHTERHOUSE: player->KilledMonsterCredit(NPC_CREDIT_SLAUGHTERHOUSE, 0); break;
                    case AT_GRAINERY:       player->KilledMonsterCredit(NPC_CREDIT_GRAINERY, 0);       break;
                    case AT_TORP_FARM:      player->KilledMonsterCredit(NPC_CREDIT_TORP_FARM, 0);      break;
                }
            }
            return true;
        }
};

/*######
## at_stormwright_shelf
######*/

enum eStormwrightShelf
{
    QUEST_STRENGTH_OF_THE_TEMPEST               = 12741,

    SPELL_CREATE_TRUE_POWER_OF_THE_TEMPEST      = 53067
};

class AreaTrigger_at_stormwright_shelf : public AreaTriggerScript
{
    public:

        AreaTrigger_at_stormwright_shelf()
            : AreaTriggerScript("at_stormwright_shelf")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/)
        {
            if (!player->isDead() && player->GetQuestStatus(QUEST_STRENGTH_OF_THE_TEMPEST) == QUEST_STATUS_INCOMPLETE)
                player->CastSpell(player, SPELL_CREATE_TRUE_POWER_OF_THE_TEMPEST, false);

            return true;
        }
};

/*######
## at_scent_larkorwi
######*/

enum eScentLarkorwi
{
    QUEST_SCENT_OF_LARKORWI                     = 4291,
    NPC_LARKORWI_MATE                           = 9683
};

class AreaTrigger_at_scent_larkorwi : public AreaTriggerScript
{
    public:

        AreaTrigger_at_scent_larkorwi()
            : AreaTriggerScript("at_scent_larkorwi")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/)
        {
            if (!player->isDead() && player->GetQuestStatus(QUEST_SCENT_OF_LARKORWI) == QUEST_STATUS_INCOMPLETE)
            {
                if (!player->FindNearestCreature(NPC_LARKORWI_MATE,15))
                    player->SummonCreature(NPC_LARKORWI_MATE, player->GetPositionX()+5, player->GetPositionY(), player->GetPositionZ(), 3.3f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 100000);
            }

            return false;
        }
};

/*#####
## at_last_rites
#####*/

enum eAtLastRites
{
    QUEST_LAST_RITES                          = 12019,
    QUEST_BREAKING_THROUGH                    = 11898,
};

class AreaTrigger_at_last_rites : public AreaTriggerScript
{
    public:

        AreaTrigger_at_last_rites()
            : AreaTriggerScript("at_last_rites")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* trigger)
        {
            if (!(player->GetQuestStatus(QUEST_LAST_RITES) == QUEST_STATUS_INCOMPLETE || 
                player->GetQuestStatus(QUEST_LAST_RITES) == QUEST_STATUS_COMPLETE ||
                player->GetQuestStatus(QUEST_BREAKING_THROUGH) == QUEST_STATUS_INCOMPLETE ||
                player->GetQuestStatus(QUEST_BREAKING_THROUGH) == QUEST_STATUS_COMPLETE))
                return false;

            WorldLocation pPosition;

            switch(trigger->id)
            {
                case 5332:
                case 5338:
                    pPosition = WorldLocation(571,3733.68f,3563.25f,290.812f,3.665192f);
                    break;
                case 5334:
                    pPosition = WorldLocation(571,3802.38f,3585.95f,49.5765f,0.0f);
                    break;
                case 5340:
                    pPosition = WorldLocation(571,3687.91f,3577.28f,473.342f,0.0f);
                    break;
                default:
                    return false;
            }

            player->TeleportTo(pPosition);

            return false;
        }
};

void AddSC_areatrigger_scripts()
{
    new AreaTrigger_at_aldurthar_gate();
    new AreaTrigger_at_coilfang_waterfall();
    new AreaTrigger_at_legion_teleporter();
    new AreaTrigger_at_ravenholdt();
    new AreaTrigger_at_warsong_farms();
    new AreaTrigger_at_stormwright_shelf();
    new AreaTrigger_at_scent_larkorwi();
    new AreaTrigger_at_last_rites();
}
