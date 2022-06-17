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
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

enum Creatures
{
    NPC_SELINA_DOURMAN                      = 10445
};

enum Events
{
    EVENT_SELINA_TALK_COOLDOWN              = 1
};

enum Gossips
{
    GOSSIP_MENU_SELINA_POIS                 = 13076,
    GOSSIP_MENU_SELINA_ITEM                 = 13113
};

enum GossipMenuOptions
{
    GOSSIP_MENU_OPTION_TONK_ARENA_POI       = 0,
    GOSSIP_MENU_OPTION_CANNON_POI           = 1,
    GOSSIP_MENU_OPTION_WHACK_A_GNOLL_POI    = 2,
    GOSSIP_MENU_OPTION_RING_TOSS_POI        = 3,
    GOSSIP_MENU_OPTION_SHOOTING_GALLERY_POI = 4,
    GOSSIP_MENU_OPTION_FORTUNE_TELLER_POI   = 5
};

enum Miscellanea
{
    DATA_ID_SELINA_TALK                     = 1,
    DATA_VALUE_SELINA_TEXT_WELCOME          = 1
};

enum PointsOfInterest
{
    POI_WHACK_A_GNOLL                       = 2716,
    POI_CANNON                              = 2717,
    POI_SHOOTING_GALLERY                    = 2718,
    POI_TONK_ARENA                          = 2719,
    POI_FORTUNE_TELLER                      = 2720,
    POI_RING_TOSS                           = 2721
};

enum Spells
{
    SPELL_REPLACE_DARKMOON_ADVENTURES_GUIDE = 103413
};

enum Texts
{
    SAY_WELCOME                             = 0
};

// 10445 - Selina Dourman
struct npc_selina_dourman : public ScriptedAI
{
    npc_selina_dourman(Creature* creature) : ScriptedAI(creature) { }

    bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
    {
        switch (menuId)
        {
            case GOSSIP_MENU_SELINA_POIS:
            {
                uint32 poiId = 0;
                switch (gossipListId)
                {
                    case GOSSIP_MENU_OPTION_TONK_ARENA_POI:
                        poiId = POI_TONK_ARENA;
                        break;
                    case GOSSIP_MENU_OPTION_CANNON_POI:
                        poiId = POI_CANNON;
                        break;
                    case GOSSIP_MENU_OPTION_WHACK_A_GNOLL_POI:
                        poiId = POI_WHACK_A_GNOLL;
                        break;
                    case GOSSIP_MENU_OPTION_RING_TOSS_POI:
                        poiId = POI_RING_TOSS;
                        break;
                    case GOSSIP_MENU_OPTION_SHOOTING_GALLERY_POI:
                        poiId = POI_SHOOTING_GALLERY;
                        break;
                    case GOSSIP_MENU_OPTION_FORTUNE_TELLER_POI:
                        poiId = POI_FORTUNE_TELLER;
                        break;
                    default:
                        break; 
                }
                if (poiId)
                    player->PlayerTalkClass->SendPointOfInterest(poiId);
                break;
            }
            case GOSSIP_MENU_SELINA_ITEM:
                me->CastSpell(player, SPELL_REPLACE_DARKMOON_ADVENTURES_GUIDE);
                CloseGossipMenuFor(player);
                break;
            default:
                break;
        }

        return false;
    }

    void SetData(uint32 id, uint32 value) override
    {
        if (!_talkTargetGuid.IsEmpty() && id == DATA_ID_SELINA_TALK && value == DATA_VALUE_SELINA_TEXT_WELCOME)
        {
            if (_events.GetTimeUntilEvent(EVENT_SELINA_TALK_COOLDOWN) == Milliseconds::max())
            {
                if (Unit* talkTarget = ObjectAccessor::GetUnit(*me, _talkTargetGuid))
                {
                    _events.ScheduleEvent(EVENT_SELINA_TALK_COOLDOWN, 30s);
                    Talk(SAY_WELCOME, talkTarget);
                }
            }
        }
    }

    void SetTalkTarget(ObjectGuid talkTargetGuid)
    {
        _talkTargetGuid = talkTargetGuid;
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_SELINA_TALK_COOLDOWN:
                _talkTargetGuid = ObjectGuid::Empty;
                break;
            default:
                break;
        }
    }

private:
    EventMap _events;
    ObjectGuid _talkTargetGuid;
};

// 7016 - Darkmoon Faire Entrance
class at_darkmoon_faire_entrance : public AreaTriggerScript
{
public:
    at_darkmoon_faire_entrance() : AreaTriggerScript("at_darkmoon_faire_entrance") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (Creature* selinaDourman = player->FindNearestCreature(NPC_SELINA_DOURMAN, 50.f))
        {
            if (npc_selina_dourman* selinaDourmanAI = CAST_AI(npc_selina_dourman, selinaDourman->GetAI()))
            {
                selinaDourmanAI->SetTalkTarget(player->GetGUID());
                selinaDourman->AI()->SetData(DATA_ID_SELINA_TALK, DATA_VALUE_SELINA_TEXT_WELCOME);
            }
        }

        return true;
    }
};

void AddSC_event_darkmoon_faire()
{
    RegisterCreatureAI(npc_selina_dourman);
    new at_darkmoon_faire_entrance();
}
