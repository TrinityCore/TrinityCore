/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
SDName: Magisters_Terrace
SD%Complete: 100
SDComment: Quest support: 11490(post-event)
SDCategory: Magisters Terrace
EndScriptData */

/* ContentData
npc_kalecgos
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "SpellInfo.h"

/*######
## npc_kalecgos
######*/

enum Spells
{
    SPELL_TRANSFORM_TO_KAEL     = 44670,
    SPELL_ORB_KILL_CREDIT       = 46307
};

enum Creatures
{
    NPC_KAEL                    = 24848 //human form entry
};

enum Misc
{
    POINT_ID_LAND               = 1
};

const float afKaelLandPoint[] = {225.045f, -276.236f, -5.434f};

#define GOSSIP_ITEM_KAEL_1      "Who are you?"
#define GOSSIP_ITEM_KAEL_2      "What can we do to assist you?"
#define GOSSIP_ITEM_KAEL_3      "What brings you to the Sunwell?"
#define GOSSIP_ITEM_KAEL_4      "You're not alone here?"
#define GOSSIP_ITEM_KAEL_5      "What would Kil'jaeden want with a mortal woman?"

// This is friendly keal that appear after used Orb.
// If we assume DB handle summon, summon appear somewhere outside the platform where Orb is
class npc_kalecgos : public CreatureScript
{
public:
    npc_kalecgos() : CreatureScript("npc_kalecgos") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAEL_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(12500, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAEL_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                player->SEND_GOSSIP_MENU(12502, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAEL_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                player->SEND_GOSSIP_MENU(12606, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAEL_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                player->SEND_GOSSIP_MENU(12607, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->SEND_GOSSIP_MENU(12608, creature->GetGUID());
                break;
        }

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAEL_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        player->SEND_GOSSIP_MENU(12498, creature->GetGUID());

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_kalecgosAI(creature);
    }

    struct npc_kalecgosAI : public ScriptedAI
    {
        npc_kalecgosAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 m_uiTransformTimer;

        void Reset() override
        {
            m_uiTransformTimer = 0;

            // we must assume he appear as dragon somewhere outside the platform of orb, and then move directly to here
            if (me->GetEntry() != NPC_KAEL)
                me->GetMotionMaster()->MovePoint(POINT_ID_LAND, afKaelLandPoint[0], afKaelLandPoint[1], afKaelLandPoint[2]);
        }

        void MovementInform(uint32 uiType, uint32 uiPointId) override
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            if (uiPointId == POINT_ID_LAND)
                m_uiTransformTimer = MINUTE*IN_MILLISECONDS;
        }

        // some targeting issues with the spell, so use this workaround as temporary solution
        void DoWorkaroundForQuestCredit()
        {
            Map* map = me->GetMap();

            if (!map || map->IsHeroic())
                return;

            Map::PlayerList const &lList = map->GetPlayers();

            if (lList.isEmpty())
                return;

            SpellInfo const* spell = sSpellMgr->GetSpellInfo(SPELL_ORB_KILL_CREDIT);

            for (Map::PlayerList::const_iterator i = lList.begin(); i != lList.end(); ++i)
            {
                if (Player* player = i->GetSource())
                {
                    if (spell && spell->Effects[0].MiscValue)
                        player->KilledMonsterCredit(spell->Effects[0].MiscValue, 0);
                }
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (m_uiTransformTimer)
            {
                if (m_uiTransformTimer <= uiDiff)
                {
                    DoCast(me, SPELL_ORB_KILL_CREDIT, false);
                    DoWorkaroundForQuestCredit();

                    // Transform and update entry, now ready for quest/read gossip
                    DoCast(me, SPELL_TRANSFORM_TO_KAEL, false);
                    me->UpdateEntry(NPC_KAEL);

                    m_uiTransformTimer = 0;
                } else m_uiTransformTimer -= uiDiff;
            }
        }
    };
};

void AddSC_magisters_terrace()
{
    new npc_kalecgos();
}
