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
SDName: Thunder_Bluff
SD%Complete: 100
SDComment: Quest support: 925
SDCategory: Thunder Bluff
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"

/*#####
# npc_cairne_bloodhoof
######*/

enum CairneBloodhoof
{
    SPELL_BERSERKER_CHARGE  = 16636,
    SPELL_CLEAVE            = 16044,
    SPELL_MORTAL_STRIKE     = 16856,
    SPELL_THUNDERCLAP       = 23931,
    SPELL_UPPERCUT          = 22916
};

enum Sounds
{
    SOUND_AGGRO             = 5884
};

enum Gossips
{
    GOSSIP_MENU_HCB         = 5851,
    GOSSIP_OPTION_HCB       = 0
};

/// @todo verify abilities/timers
class npc_cairne_bloodhoof : public CreatureScript
{
public:
    npc_cairne_bloodhoof() : CreatureScript("npc_cairne_bloodhoof") { }

    struct npc_cairne_bloodhoofAI : public ScriptedAI
    {
        npc_cairne_bloodhoofAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            BerserkerChargeTimer = 30000;
            CleaveTimer = 5000;
            MortalStrikeTimer = 10000;
            ThunderclapTimer = 15000;
            UppercutTimer = 10000;
        }

        uint32 BerserkerChargeTimer;
        uint32 CleaveTimer;
        uint32 MortalStrikeTimer;
        uint32 ThunderclapTimer;
        uint32 UppercutTimer;

        void Reset() override
        {
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            DoPlaySoundToSet(me, SOUND_AGGRO);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (BerserkerChargeTimer <= diff)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_BERSERKER_CHARGE);
                BerserkerChargeTimer = 25000;
            } else BerserkerChargeTimer -= diff;

            if (UppercutTimer <= diff)
            {
                DoCastVictim(SPELL_UPPERCUT);
                UppercutTimer = 20000;
            } else UppercutTimer -= diff;

            if (ThunderclapTimer <= diff)
            {
                DoCastVictim(SPELL_THUNDERCLAP);
                ThunderclapTimer = 15000;
            } else ThunderclapTimer -= diff;

            if (MortalStrikeTimer <= diff)
            {
                DoCastVictim(SPELL_MORTAL_STRIKE);
                MortalStrikeTimer = 15000;
            } else MortalStrikeTimer -= diff;

            if (CleaveTimer <= diff)
            {
                DoCastVictim(SPELL_CLEAVE);
                CleaveTimer = 7000;
            } else CleaveTimer -= diff;
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            if (action == GOSSIP_SENDER_INFO)
            {
                player->CastSpell(player, 23123, false);
                SendGossipMenuFor(player, 7014, me->GetGUID());
            }
            return true;
        }

        bool OnGossipHello(Player* player) override
        {
            InitGossipMenuFor(player, GOSSIP_MENU_HCB);
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            if (player->GetQuestStatus(925) == QUEST_STATUS_INCOMPLETE)
                AddGossipItemFor(player, GOSSIP_MENU_HCB, GOSSIP_OPTION_HCB, GOSSIP_SENDER_MAIN, GOSSIP_SENDER_INFO);

            SendGossipMenuFor(player, 7013, me->GetGUID());

            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_cairne_bloodhoofAI(creature);
    }
};

void AddSC_thunder_bluff()
{
    new npc_cairne_bloodhoof();
}
