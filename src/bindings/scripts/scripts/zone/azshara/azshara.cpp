/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Azshara
SD%Complete: 90
SDComment: Quest support: 2744, 3141, 9364
SDCategory: Azshara
EndScriptData */

/* ContentData
mobs_spitelashes
npc_loramus_thalipedes
EndContentData */

#include "precompiled.h"

/*######
## mobs_spitelashes
######*/

struct TRINITY_DLL_DECL mobs_spitelashesAI : public ScriptedAI
{
    mobs_spitelashesAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 morphtimer;
    bool spellhit;

    void Reset()
    {
        morphtimer = 0;
        spellhit = false;
    }

    void Aggro(Unit *who) { }

    void SpellHit(Unit *Hitter, const SpellEntry *Spellkind)
    {
        if( !spellhit &&
            Hitter->GetTypeId() == TYPEID_PLAYER &&
            ((Player*)Hitter)->GetQuestStatus(9364) == QUEST_STATUS_INCOMPLETE &&
            (Spellkind->Id==118 || Spellkind->Id== 12824 || Spellkind->Id== 12825 || Spellkind->Id== 12826) )
        {
            spellhit=true;
            DoCast(m_creature,29124);                       //become a sheep
        }
    }

    void UpdateAI(const uint32 diff)
    {
        // we mustn't remove the creature in the same round in which we cast the summon spell, otherwise there will be no summons
        if( spellhit && morphtimer>=5000 )
        {
            m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            m_creature->RemoveCorpse();                     //you don't see any corpse on off.
            EnterEvadeMode();                               //spellhit will be set to false
        }
        // walk 5 seconds before summoning
        if( spellhit && morphtimer<5000 )
        {
            morphtimer+=diff;
            if( morphtimer>=5000 )
            {
                DoCast(m_creature,28406);                   //summon copies
                DoCast(m_creature,6924);                    //visual explosion
            }
        }
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //TODO: add abilities for the different creatures
        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_mobs_spitelashes(Creature *_Creature)
{
    return new mobs_spitelashesAI (_Creature);
}

/*######
## npc_loramus_thalipedes
######*/

bool GossipHello_npc_loramus_thalipedes(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if (player->GetQuestStatus(2744) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM( 0, "Can you help me?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    if (player->GetQuestStatus(3141) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM( 0, "Tell me your story", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_loramus_thalipedes(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->CLOSE_GOSSIP_MENU();
            player->AreaExploredOrEventHappens(2744);
            break;

        case GOSSIP_ACTION_INFO_DEF+2:
            player->ADD_GOSSIP_ITEM( 0, "Please continue", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 21);
            player->SEND_GOSSIP_MENU(1813, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+21:
            player->ADD_GOSSIP_ITEM( 0, "I do not understand", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
            player->SEND_GOSSIP_MENU(1814, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+22:
            player->ADD_GOSSIP_ITEM( 0, "Indeed", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
            player->SEND_GOSSIP_MENU(1815, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+23:
            player->ADD_GOSSIP_ITEM( 0, "I will do this with or your help, Loramus", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
            player->SEND_GOSSIP_MENU(1816, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+24:
            player->ADD_GOSSIP_ITEM( 0, "Yes", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
            player->SEND_GOSSIP_MENU(1817, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+25:
            player->CLOSE_GOSSIP_MENU();
            player->AreaExploredOrEventHappens(3141);
            break;
    }
    return true;
}

void AddSC_azshara()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="mobs_spitelashes";
    newscript->GetAI = GetAI_mobs_spitelashes;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_loramus_thalipedes";
    newscript->pGossipHello =  &GossipHello_npc_loramus_thalipedes;
    newscript->pGossipSelect = &GossipSelect_npc_loramus_thalipedes;
    m_scripts[nrscripts++] = newscript;
}
