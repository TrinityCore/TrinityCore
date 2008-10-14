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
SDName: Blades_Edge_Mountains
SD%Complete: 90
SDComment: Quest support: 10503, 10504, 10556, 10609, 10682, 10980. Ogri'la->Skettis Flight. (npc_daranelle needs bit more work before consider complete)
SDCategory: Blade's Edge Mountains
EndScriptData */

/* ContentData
mobs_bladespire_ogre
mobs_nether_drake
npc_daranelle
npc_overseer_nuaar
npc_saikkal_the_elder
npc_skyguard_handler_irena
EndContentData */

#include "precompiled.h"

/*######
## mobs_bladespire_ogre
######*/

//TODO: add support for quest 10512 + creature abilities
struct TRINITY_DLL_DECL mobs_bladespire_ogreAI : public ScriptedAI
{
    mobs_bladespire_ogreAI(Creature *c) : ScriptedAI(c) {Reset();}

    void Reset()
    {
    }

    void Aggro(Unit* who)
    {
    }

    void JustDied(Unit* Killer)
    {
        if (Killer->GetTypeId() == TYPEID_PLAYER)
            ((Player*)Killer)->KilledMonster(19995, m_creature->GetGUID());
    }
};
CreatureAI* GetAI_mobs_bladespire_ogre(Creature *_Creature)
{
    return new mobs_bladespire_ogreAI (_Creature);
}

/*######
## mobs_nether_drake
######*/

#define SAY_NIHIL_1         "Muahahahaha! You fool! You've released me from my banishment in the interstices between space and time!"
#define SAY_NIHIL_2         "All of Draenor shall quick beneath my feet! I will destroy this world and reshape it in my image!"
#define SAY_NIHIL_3         "Where shall I begin? I cannot bother myself with a worm such as yourself. There is a world to be conquered!"
#define SAY_NIHIL_4         "No doubt the fools that banished me are long dead. I shall take wing survey my demense. Pray to whatever gods you hold dear that we do not meet again."
#define SAY_NIHIL_INTERRUPT "NOOOOooooooo!"

#define ENTRY_WHELP                 20021
#define ENTRY_PROTO                 21821
#define ENTRY_ADOLE                 21817
#define ENTRY_MATUR                 21820
#define ENTRY_NIHIL                 21823

#define SPELL_T_PHASE_MODULATOR     37573

#define SPELL_ARCANE_BLAST          38881
#define SPELL_MANA_BURN             38884
#define SPELL_INTANGIBLE_PRESENCE   36513

struct TRINITY_DLL_DECL mobs_nether_drakeAI : public ScriptedAI
{
    mobs_nether_drakeAI(Creature *c) : ScriptedAI(c) {Reset();}

    bool IsNihil;
    uint32 NihilSpeech_Timer;
    uint32 NihilSpeech_Phase;

    uint32 ArcaneBlast_Timer;
    uint32 ManaBurn_Timer;
    uint32 IntangiblePresence_Timer;

    void Reset()
    {
        NihilSpeech_Timer = 2000;
        IsNihil = false;
        if( m_creature->GetEntry() == ENTRY_NIHIL )
        {
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            IsNihil = true;
        }
        NihilSpeech_Phase = 1;

        ArcaneBlast_Timer = 7500;
        ManaBurn_Timer = 10000;
        IntangiblePresence_Timer = 15000;
    }

    void Aggro(Unit* who) { }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if( spell->Id == SPELL_T_PHASE_MODULATOR && caster->GetTypeId() == TYPEID_PLAYER )
        {
            uint32 cEntry = 0;

            switch( m_creature->GetEntry() )
            {
                case ENTRY_WHELP:
                    switch(rand()%4)
                    {
                        case 0: cEntry = ENTRY_PROTO; break;
                        case 1: cEntry = ENTRY_ADOLE; break;
                        case 2: cEntry = ENTRY_MATUR; break;
                        case 3: cEntry = ENTRY_NIHIL; break;
                    }
                    break;
                case ENTRY_PROTO:
                    switch(rand()%3)
                    {
                        case 0: cEntry = ENTRY_ADOLE; break;
                        case 1: cEntry = ENTRY_MATUR; break;
                        case 2: cEntry = ENTRY_NIHIL; break;
                    }
                    break;
                case ENTRY_ADOLE:
                    switch(rand()%3)
                    {
                        case 0: cEntry = ENTRY_PROTO; break;
                        case 1: cEntry = ENTRY_MATUR; break;
                        case 2: cEntry = ENTRY_NIHIL; break;
                    }
                    break;
                case ENTRY_MATUR:
                    switch(rand()%3)
                    {
                        case 0: cEntry = ENTRY_PROTO; break;
                        case 1: cEntry = ENTRY_ADOLE; break;
                        case 2: cEntry = ENTRY_NIHIL; break;
                    }
                    break;
                case ENTRY_NIHIL:
                    if( NihilSpeech_Phase )
                    {
                        DoYell(SAY_NIHIL_INTERRUPT,LANG_UNIVERSAL,NULL);
                        IsNihil = false;
                        switch(rand()%3)
                        {
                            case 0: cEntry = ENTRY_PROTO; break;
                            case 1: cEntry = ENTRY_ADOLE; break;
                            case 2: cEntry = ENTRY_MATUR; break;
                        }
                    }
                    break;
            }

            if( cEntry )
            {
                m_creature->UpdateEntry(cEntry);

                if( cEntry == ENTRY_NIHIL )
                {
                    m_creature->InterruptNonMeleeSpells(true);
                    m_creature->RemoveAllAuras();
                    m_creature->DeleteThreatList();
                    m_creature->CombatStop();
                    InCombat = false;
                    Reset();
                }
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if( IsNihil )
        {
            if( NihilSpeech_Phase )
            {
                if(NihilSpeech_Timer <= diff)
                {
                    switch( NihilSpeech_Phase )
                    {
                        case 1:
                            DoSay(SAY_NIHIL_1,LANG_UNIVERSAL,NULL);
                            ++NihilSpeech_Phase;
                            break;
                        case 2:
                            DoSay(SAY_NIHIL_2,LANG_UNIVERSAL,NULL);
                            ++NihilSpeech_Phase;
                            break;
                        case 3:
                            DoSay(SAY_NIHIL_3,LANG_UNIVERSAL,NULL);
                            ++NihilSpeech_Phase;
                            break;
                        case 4:
                            DoSay(SAY_NIHIL_4,LANG_UNIVERSAL,NULL);
                            ++NihilSpeech_Phase;
                            break;
                        case 5:
                            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                                            // + MOVEMENTFLAG_LEVITATING
                            m_creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
                            //then take off to random location. creature is initially summoned, so don't bother do anything else.
                            m_creature->GetMotionMaster()->MovePoint(0, m_creature->GetPositionX()+100, m_creature->GetPositionY(), m_creature->GetPositionZ()+100);
                            NihilSpeech_Phase = 0;
                            break;
                    }
                    NihilSpeech_Timer = 5000;
                }else NihilSpeech_Timer -=diff;
            }
            return;                                         //anything below here is not interesting for Nihil, so skip it
        }

        if( !m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        if( IntangiblePresence_Timer <= diff )
        {
            DoCast(m_creature->getVictim(),SPELL_INTANGIBLE_PRESENCE);
            IntangiblePresence_Timer = 15000+rand()%15000;
        }else IntangiblePresence_Timer -= diff;

        if( ManaBurn_Timer <= diff )
        {
            Unit* target = m_creature->getVictim();
            if( target && target->getPowerType() == POWER_MANA )
                DoCast(target,SPELL_MANA_BURN);
            ManaBurn_Timer = 8000+rand()%8000;
        }else ManaBurn_Timer -= diff;

        if( ArcaneBlast_Timer <= diff )
        {
            DoCast(m_creature->getVictim(),SPELL_ARCANE_BLAST);
            ArcaneBlast_Timer = 2500+rand()%5000;
        }else ArcaneBlast_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_mobs_nether_drake(Creature *_Creature)
{
    return new mobs_nether_drakeAI (_Creature);
}

/*######
## npc_daranelle
######*/

struct TRINITY_DLL_DECL npc_daranelleAI : public ScriptedAI
{
    npc_daranelleAI(Creature *c) : ScriptedAI(c) {Reset();}

    void Reset()
    {
    }

    void Aggro(Unit* who)
    {
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
        {
            if(who->HasAura(36904,0))
            {
                DoSay("Good $N, you are under the spell's influence. I must analyze it quickly, then we can talk.",LANG_COMMON,who);
                //TODO: Move the below to updateAI and run if this statement == true
                ((Player*)who)->KilledMonster(21511, m_creature->GetGUID());
                ((Player*)who)->RemoveAurasDueToSpell(36904);
            }
        }

        if (!m_creature->getVictim() && who->isTargetableForAttack() && who->isInAccessablePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            if (!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;

            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who))
            {
                if(who->HasStealthAura())
                    who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

                //Begin melee attack if we are within range
                DoStartAttackAndMovement(who);
            }
        }
    }
};

CreatureAI* GetAI_npc_daranelle(Creature *_Creature)
{
    return new npc_daranelleAI (_Creature);
}

/*######
## npc_overseer_nuaar
######*/

bool GossipHello_npc_overseer_nuaar(Player *player, Creature *_Creature)
{
    if (player->GetQuestStatus(10682) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM( 0, "Overseer, I am here to negotiate on behalf of the Cenarion Expedition.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(10532, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_overseer_nuaar(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
        player->SEND_GOSSIP_MENU(10533, _Creature->GetGUID());
        player->AreaExploredOrEventHappens(10682);
    }
    return true;
}

/*######
## npc_saikkal_the_elder
######*/

bool GossipHello_npc_saikkal_the_elder(Player *player, Creature *_Creature)
{
    if (player->GetQuestStatus(10980) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM( 0, "Yes... yes, it's me.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(10794, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_saikkal_the_elder(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM( 0, "Yes elder. Tell me more of the book.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            player->SEND_GOSSIP_MENU(10795, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->TalkedToCreature(_Creature->GetEntry(), _Creature->GetGUID());
            player->SEND_GOSSIP_MENU(10796, _Creature->GetGUID());
            break;
    }
    return true;
}

/*######
## npc_skyguard_handler_irena
######*/

#define GOSSIP_SKYGUARD "Fly me to Skettis please"

bool GossipHello_npc_skyguard_handler_irena(Player *player, Creature *_Creature )
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if (player->GetReputationRank(1031) >= REP_HONORED)
        player->ADD_GOSSIP_ITEM( 2, GOSSIP_SKYGUARD, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_skyguard_handler_irena(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
        player->CLOSE_GOSSIP_MENU();

        std::vector<uint32> nodes;

        nodes.resize(2);
        nodes[0] = 172;                                     //from ogri'la
        nodes[1] = 171;                                     //end at skettis
        player->ActivateTaxiPathTo(nodes);                  //TaxiPath 706
    }
    return true;
}

/*######
## AddSC
######*/

void AddSC_blades_edge_mountains()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="mobs_bladespire_ogre";
    newscript->GetAI = GetAI_mobs_bladespire_ogre;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mobs_nether_drake";
    newscript->GetAI = GetAI_mobs_nether_drake;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_daranelle";
    newscript->GetAI = GetAI_npc_daranelle;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_overseer_nuaar";
    newscript->pGossipHello = &GossipHello_npc_overseer_nuaar;
    newscript->pGossipSelect = &GossipSelect_npc_overseer_nuaar;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_saikkal_the_elder";
    newscript->pGossipHello = &GossipHello_npc_saikkal_the_elder;
    newscript->pGossipSelect = &GossipSelect_npc_saikkal_the_elder;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_skyguard_handler_irena";
    newscript->pGossipHello =  &GossipHello_npc_skyguard_handler_irena;
    newscript->pGossipSelect = &GossipSelect_npc_skyguard_handler_irena;
    m_scripts[nrscripts++] = newscript;
}
