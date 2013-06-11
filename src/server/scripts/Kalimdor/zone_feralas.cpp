/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Feralas
SD%Complete: 100
SDComment: Quest support: 3520, 2767, Special vendor Gregan Brewspewer
SDCategory: Feralas
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "Player.h"
#include "WorldSession.h"

/*######
## npc_gregan_brewspewer
######*/

#define GOSSIP_HELLO "Buy somethin', will ya?"

class npc_gregan_brewspewer : public CreatureScript
{
public:
    npc_gregan_brewspewer() : CreatureScript("npc_gregan_brewspewer") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
            player->SEND_GOSSIP_MENU(2434, creature->GetGUID());
        }
        if (action == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (creature->IsVendor() && player->GetQuestStatus(3909) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(2433, creature->GetGUID());
        return true;
    }

};

/*######
## npc_oox22fe
######*/

enum OOX
{
    SAY_OOX_START           = 0,
    SAY_OOX_AGGRO           = 1,
    SAY_OOX_AMBUSH          = 2,
    SAY_OOX_END             = 3,

    NPC_YETI                = 7848,
    NPC_GORILLA             = 5260,
    NPC_WOODPAW_REAVER      = 5255,
    NPC_WOODPAW_BRUTE       = 5253,
    NPC_WOODPAW_ALPHA       = 5258,
    NPC_WOODPAW_MYSTIC      = 5254,

    QUEST_RESCUE_OOX22FE    = 2767,
    FACTION_ESCORTEE_A      = 774,
    FACTION_ESCORTEE_H      = 775
};

class npc_oox22fe : public CreatureScript
{
public:
    npc_oox22fe() : CreatureScript("npc_oox22fe") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest)
    {
        if (quest->GetQuestId() == QUEST_RESCUE_OOX22FE)
        {
            creature->AI()->Talk(SAY_OOX_START);
            //change that the npc is not lying dead on the ground
            creature->SetStandState(UNIT_STAND_STATE_STAND);

            if (player->GetTeam() == ALLIANCE)
                creature->setFaction(FACTION_ESCORTEE_A);

            if (player->GetTeam() == HORDE)
                creature->setFaction(FACTION_ESCORTEE_H);

            if (npc_escortAI* pEscortAI = CAST_AI(npc_oox22fe::npc_oox22feAI, creature->AI()))
                pEscortAI->Start(true, false, player->GetGUID());

        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_oox22feAI(creature);
    }

    struct npc_oox22feAI : public npc_escortAI
    {
        npc_oox22feAI(Creature* creature) : npc_escortAI(creature) { }

        void WaypointReached(uint32 waypointId)
        {
            switch (waypointId)
            {
                // First Ambush(3 Yetis)
                case 11:
                    Talk(SAY_OOX_AMBUSH);
                    me->SummonCreature(NPC_YETI, -4841.01f, 1593.91f, 73.42f, 3.98f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    me->SummonCreature(NPC_YETI, -4837.61f, 1568.58f, 78.21f, 3.13f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    me->SummonCreature(NPC_YETI, -4841.89f, 1569.95f, 76.53f, 0.68f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    break;
                //Second Ambush(3 Gorillas)
                case 21:
                    Talk(SAY_OOX_AMBUSH);
                    me->SummonCreature(NPC_GORILLA, -4595.81f, 2005.99f, 53.08f, 3.74f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    me->SummonCreature(NPC_GORILLA, -4597.53f, 2008.31f, 52.70f, 3.78f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    me->SummonCreature(NPC_GORILLA, -4599.37f, 2010.59f, 52.77f, 3.84f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    break;
                //Third Ambush(4 Gnolls)
                case 30:
                    Talk(SAY_OOX_AMBUSH);
                    me->SummonCreature(NPC_WOODPAW_REAVER, -4425.14f, 2075.87f, 47.77f, 3.77f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    me->SummonCreature(NPC_WOODPAW_BRUTE, -4426.68f, 2077.98f, 47.57f, 3.77f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    me->SummonCreature(NPC_WOODPAW_MYSTIC, -4428.33f, 2080.24f, 47.43f, 3.87f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    me->SummonCreature(NPC_WOODPAW_ALPHA, -4430.04f, 2075.54f, 46.83f, 3.81f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                    break;
                case 37:
                    Talk(SAY_OOX_END);
                    // Award quest credit
                    if (Player* player = GetPlayerForEscort())
                        player->GroupEventHappens(QUEST_RESCUE_OOX22FE, me);
                    break;
            }
        }

        void Reset()
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
                me->SetStandState(UNIT_STAND_STATE_DEAD);
        }

        void EnterCombat(Unit* /*who*/)
        {
            //For an small probability the npc says something when he get aggro
            if (urand(0, 9) > 7)
                Talk(SAY_OOX_AGGRO);
        }

        void JustSummoned(Creature* summoned)
        {
            summoned->AI()->AttackStart(me);
        }
    };

};

/*######
## npc_screecher_spirit
######*/

class npc_screecher_spirit : public CreatureScript
{
public:
    npc_screecher_spirit() : CreatureScript("npc_screecher_spirit") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->SEND_GOSSIP_MENU(2039, creature->GetGUID());
        player->TalkedToCreature(creature->GetEntry(), creature->GetGUID());
        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

        return true;
    }

};

enum GordunniTrap
{
    GO_GORDUNNI_DIRT_MOUND = 144064,
};

class spell_gordunni_trap : public SpellScriptLoader
{
    public:
        spell_gordunni_trap() : SpellScriptLoader("spell_gordunni_trap") { }

        class spell_gordunni_trap_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gordunni_trap_SpellScript);

            void HandleDummy()
            {
                if (Unit* caster = GetCaster())
                    if (GameObject* chest = caster->SummonGameObject(GO_GORDUNNI_DIRT_MOUND, caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0))
                    {
                        chest->SetSpellId(GetSpellInfo()->Id);
                        caster->RemoveGameObject(chest, false);
                    }
            }

            void Register()
            {
                OnCast += SpellCastFn(spell_gordunni_trap_SpellScript::HandleDummy);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_gordunni_trap_SpellScript();
        }
};

/*######
## AddSC
######*/

void AddSC_feralas()
{
    new npc_gregan_brewspewer();
    new npc_oox22fe();
    new npc_screecher_spirit();
    new spell_gordunni_trap();
}
