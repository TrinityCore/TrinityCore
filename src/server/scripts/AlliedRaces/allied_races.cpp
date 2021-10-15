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

#include "Conversation.h"
#include "DBCEnums.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "World.h"
#include "WorldSession.h"
#include "ScriptedGossip.h"
#include "MotionMaster.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"
#include "ZoneScript.h"


enum
{
    SPELL_ACHERUS_DEATH_CHARGER = 48778,
    SPELL_RUNEFORGING           = 53428,

    AURA_DOMINION_OVER_ACHERUS  = 54055, // this should be 51721 but it has a problem, so we will use 54055 instead

    AREA_EBON_HOLD_EAST_KINGD = 4281,
    MAP_EASTERN_KINGD         = 0,
    MAP_ALLIED_DK_ICECROWN    = 2297
};


class AlliedRaces : public PlayerScript
{
public:
	AlliedRaces() : PlayerScript("AlliedRaces") { }


    void OnLogin(Player* player, bool firstLogin) override
    {
		if (firstLogin)
		{
            /* Cinematic - Pandaren death knight */
            //Store all future Allied races cinematics on first login here, not in CharacterHandler, it will create camera bugs and some other issues
			if (player->getRace() == RACE_PANDAREN_HORDE || RACE_PANDAREN_ALLIANCE && player->GetMapId() == MAP_ALLIED_DK_ICECROWN && player->getClass() == CLASS_DEATH_KNIGHT)
            {
                //player->GetSceneMgr().PlaySceneByPackageId(2780);
            }


            /* Fix allied race deathknight missing spells */
            // the questline is wierd even on official blizz... so this is permanent fix. - Varjgard
            if ((player->getClass() == CLASS_DEATH_KNIGHT) && (player->IsAlliedRace()))
            {
                /* Acherus Death Charger */
                if (!player->HasSpell(SPELL_ACHERUS_DEATH_CHARGER))
                    player->LearnSpell(SPELL_ACHERUS_DEATH_CHARGER, false, 0 , true);

                /* Runeforging */
                if (!player->HasSpell(SPELL_RUNEFORGING))
                    player->LearnSpell(SPELL_RUNEFORGING, false, 0 , true);
            }
		}
    }

    void OnUpdateArea(Player* player, uint32 newArea, uint32 /*oldArea*/)
    {
        /* Fix allied race deathknight missing aura */
        /* Dominion Over Acherus */
        if ((player->GetAreaId() == AREA_EBON_HOLD_EAST_KINGD) && (player->GetMapId() == MAP_EASTERN_KINGD) && (player->IsAlliedRace()))
        {
            if (!player->HasAura(AURA_DOMINION_OVER_ACHERUS))
                player->CastSpell(player, AURA_DOMINION_OVER_ACHERUS);
        }

        if ((newArea != AREA_EBON_HOLD_EAST_KINGD)  && (player->IsAlliedRace()))
        {
            if (player->HasAura(AURA_DOMINION_OVER_ACHERUS))
                player->RemoveAura(AURA_DOMINION_OVER_ACHERUS);
        }
    }
};

// alliedrace dk valkyr battle maiden - npc id 228534
class npc_valkyr_battle_maiden_allied : public CreatureScript
{
public:
    npc_valkyr_battle_maiden_allied() : CreatureScript("npc_valkyr_battle_maiden_allied") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_valkyr_battle_maiden_alliedAI(creature);
    }

    struct npc_valkyr_battle_maiden_alliedAI : public PassiveAI
    {
        npc_valkyr_battle_maiden_alliedAI(Creature* creature) : PassiveAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            FlyBackTimer = 500;
            phase = 0;
            x = 0.f;
            y = 0.f;
            z = 0.f;
        }

        uint32 FlyBackTimer;
        float x, y, z;
        uint32 phase;

        void Reset() override
        {
            me->setActive(true);
            me->SetVisible(false);
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->SetCanFly(true);

            me->GetPosition(x, y, z);
            z += 4.0f;
            x -= 3.5f;
            y -= 5.0f;
            me->GetMotionMaster()->Clear();
            me->UpdatePosition(x, y, z, 0.0f);
        }

        void UpdateAI(uint32 diff) override
        {
            if (FlyBackTimer <= diff)
            {
                Player* player = NULL;
                if (me->IsSummon())
                    if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                        player = summoner->ToPlayer();

                if (!player)
                    phase = 3;

                switch (phase)
                {
                    case 0:
                        me->SetWalk(false);
                        me->HandleEmoteCommand(EMOTE_STATE_FLYGRABCLOSED);
                        FlyBackTimer = 500;
                        break;
                    case 1:
                        player->GetClosePoint(x, y, z, me->GetObjectSize());
                        z += 2.5f;
                        x -= 2.0f;
                        y -= 1.5f;
                        me->GetMotionMaster()->MovePoint(0, x, y, z);
                        me->SetTarget(player->GetGUID());
                        me->SetVisible(true);
                        FlyBackTimer = 1;
                        break;
                    case 2:
                        DoCast(player, 51918, true); // this is only for visual effect!
                        me->HandleEmoteCommand(EMOTE_ONESHOT_CUSTOM_SPELL_01);
                        Talk(0, player);
                        player->TeleportTo(2297, 498.144653f, -2124.429932f, 840.856934f, 3.065104f);
                        player->ResurrectPlayer(100.0f, false);
                        FlyBackTimer = 3000;
                        break;
                    case 3:
                        me->SetVisible(false);
                        FlyBackTimer = 3000;
                        break;
                    case 4:
                        me->DisappearAndDie();
                        break;
                    default:
                        break;
                }
                ++phase;
            }
            else FlyBackTimer -= diff;
        }
    };
};

// allied dk zone - map id - 2297
class zone_allied_dk : public PlayerScript
{
public:
    zone_allied_dk() : PlayerScript("zone_allied_dk") { }

    void OnPlayerDeath(Player* player)
    {
        if (player->GetMapId() == MAP_ALLIED_DK_ICECROWN)
            player->SummonCreature(228534, player->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0U, 0U);
    }

};


void AddSC_AlliedRaces()
{
    RegisterPlayerScript(AlliedRaces);
    new npc_valkyr_battle_maiden_allied();
    new zone_allied_dk();
}
