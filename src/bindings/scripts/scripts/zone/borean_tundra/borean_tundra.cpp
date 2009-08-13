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
SDName: Borean_Tundra
SD%Complete: 100
SDComment:
SDCategory: Borean Tundra
EndScriptData */

/* ContentData
npc_tiare
npc_surristrasz
EndContentData */

#include "precompiled.h"

/*######
## npc_tiare
######*/

#define GOSSIP_ITEM_TELEPORT    "Teleport me to Amber Ledge, please."

bool GossipHello_npc_tiare(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TELEPORT, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_GOSSIP);
    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_tiare(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_OPTION_GOSSIP)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->CastSpell(pPlayer,50135,true);
    }
    return true;
}

/*######
## npc_surristrasz
######*/

#define GOSSIP_ITEM_FREE_FLIGHT "I'd like passage to the Transitus Shield."
#define GOSSIP_ITEM_FLIGHT      "May I use a drake to fly elsewhere?"

bool GossipHello_npc_surristrasz(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pCreature->isTaxi())
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FREE_FLIGHT, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_GOSSIP);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_ITEM_FLIGHT, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_TAXIVENDOR);
    }

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_surristrasz(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_OPTION_GOSSIP)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->CastSpell(pPlayer,46064,true);               //TaxiPath 795 (amber to coldarra)
    }
    if (action == GOSSIP_OPTION_TAXIVENDOR)
    {
        pPlayer->GetSession()->SendTaxiMenu(pCreature);
    }
    return true;
}

/*######
## npc_sinkhole_kill_credit
######*/

enum
{
    SPELL_SET_CART                = 46797,
    SPELL_EXPLODE_CART            = 46799,
    SPELL_SUMMON_CART             = 46798,
    SPELL_SUMMON_WORM             = 46800,
};

struct TRINITY_DLL_DECL npc_sinkhole_kill_creditAI : public ScriptedAI
{
    npc_sinkhole_kill_creditAI(Creature* c) : ScriptedAI(c){}

    uint32 Phase_Timer;
    uint8  Phase;
    Unit* Caster;

    void Reset()
    {
        Phase_Timer = 500;
        Phase = 0;
        Caster = NULL;
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if (Phase)
            return;

        if (spell->Id == SPELL_SET_CART && CAST_PLR(caster)->GetQuestStatus(11897) == QUEST_STATUS_INCOMPLETE)
        {
            Phase = 1;
            Caster = caster;
        }
    }

    void EnterCombat(Unit* who) { }

    void UpdateAI(const uint32 diff)
    {
        if (!Phase)
            return;

        if (Phase_Timer < diff)
        {
            switch (Phase)
            {
                case 1:
                    DoCast(m_creature, SPELL_EXPLODE_CART, true);
                    DoCast(m_creature, SPELL_SUMMON_CART, true);
                    if (GameObject* cart = m_creature->FindNearestGameObject(188160,3))
                        cart->SetUInt32Value(GAMEOBJECT_FACTION, 14);                        
                    Phase_Timer = 3000;
                    Phase = 2;
                    break;
                case 2:
                    if (GameObject* cart = m_creature->FindNearestGameObject(188160,3)) 
                        cart->UseDoorOrButton();
                    DoCast(m_creature, SPELL_EXPLODE_CART, true);
                    Phase_Timer = 3000;
                    Phase = 3;
                    break;
                case 3:
                    DoCast(m_creature, SPELL_EXPLODE_CART, true);
                    Phase_Timer = 2000;
                    Phase = 4;
                case 5:
                    DoCast(m_creature, SPELL_SUMMON_WORM, true);
                    if (Unit* worm = m_creature->FindNearestCreature(26250, 3))
                    {
                        worm->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        worm->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
                    }
                    Phase_Timer = 1000;
                    Phase = 6;
                    break;
                case 6:
                    DoCast(m_creature, SPELL_EXPLODE_CART, true);
                    if (Unit* worm = m_creature->FindNearestCreature(26250, 3))
                    {
                        m_creature->DealDamage(worm, worm->GetHealth());
                        worm->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                    }
                    Phase_Timer = 2000;
                    Phase = 7;
                    break;
                case 7:
                    DoCast(m_creature, SPELL_EXPLODE_CART, true);
                    CAST_PLR(Caster)->KilledMonster(m_creature->GetCreatureInfo(),m_creature->GetGUID());
                    Phase_Timer = 5000;
                    Phase = 8;
                    break;
                case 8:
                    EnterEvadeMode();
                    break;
            }
        } else Phase_Timer -= diff;
        
    }

};

CreatureAI* GetAI_npc_sinkhole_kill_credit(Creature* pCreature)
{
    return new npc_sinkhole_kill_creditAI(pCreature);
}

/*######
## npc_khunok_the_behemoth
######*/

struct TRINITY_DLL_DECL npc_khunok_the_behemothAI : public ScriptedAI
{
    npc_khunok_the_behemothAI(Creature *c) : ScriptedAI(c) {}

    void MoveInLineOfSight(Unit *who)
    {
        ScriptedAI::MoveInLineOfSight(who);

        if (who->GetTypeId() != TYPEID_UNIT)
            return;

        if (who->GetEntry() == 25861 && me->IsWithinDistInMap(who, 10.0f))
        {
            if (Unit *owner = who->GetOwner())
            {
                if (owner->GetTypeId() == TYPEID_PLAYER)
                {
                    DoCast(owner, 46231, true);
                    CAST_CRE(who)->ForcedDespawn();
                }
            }
        }
    }
};

CreatureAI* GetAI_npc_khunok_the_behemoth(Creature* pCreature)
{
    return new npc_khunok_the_behemothAI(pCreature);
}

void AddSC_borean_tundra()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_tiare";
    newscript->pGossipHello =  &GossipHello_npc_tiare;
    newscript->pGossipSelect = &GossipSelect_npc_tiare;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_surristrasz";
    newscript->pGossipHello =  &GossipHello_npc_surristrasz;
    newscript->pGossipSelect = &GossipSelect_npc_surristrasz;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_sinkhole_kill_credit";
    newscript->GetAI = &GetAI_npc_sinkhole_kill_credit;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_khunok_the_behemoth";
    newscript->GetAI = &GetAI_npc_khunok_the_behemoth;
    newscript->RegisterSelf();
}
