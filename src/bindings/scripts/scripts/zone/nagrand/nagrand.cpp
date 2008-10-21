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
SDName: Nagrand
SD%Complete: 90
SDComment: Quest support: 9849, 9918, 9874, 9991, 10107, 10108, 10044, 10172, 10646, 10085. TextId's unknown for altruis_the_sufferer and greatmother_geyah (npc_text)
SDCategory: Nagrand
EndScriptData */

/* ContentData
mob_shattered_rumbler
mob_lump
mob_sunspring_villager
npc_altruis_the_sufferer
npc_greatmother_geyah
npc_lantresor_of_the_blade
npc_creditmarker_visit_with_ancestors
EndContentData */

#include "precompiled.h"

/*######
## mob_shattered_rumbler - this should be done with ACID
######*/

struct TRINITY_DLL_DECL mob_shattered_rumblerAI : public ScriptedAI
{
    bool Spawn;

    mob_shattered_rumblerAI(Creature *c) : ScriptedAI(c) {Reset();}

    void Reset()
    {
        Spawn = false;
    }

    void Aggro(Unit* who) {}

    void SpellHit(Unit *Hitter, const SpellEntry *Spellkind)
    {
        if(Spellkind->Id == 32001 && !Spawn)
        {
            float x = m_creature->GetPositionX();
            float y = m_creature->GetPositionY();
            float z = m_creature->GetPositionZ();

            Hitter->SummonCreature(18181,x+(0.7 * (rand()%30)),y+(rand()%5),z,0,TEMPSUMMON_CORPSE_TIMED_DESPAWN,60000);
            Hitter->SummonCreature(18181,x+(rand()%5),y-(rand()%5),z,0,TEMPSUMMON_CORPSE_TIMED_DESPAWN,60000);
            Hitter->SummonCreature(18181,x-(rand()%5),y+(0.5 *(rand()%60)),z,0,TEMPSUMMON_CORPSE_TIMED_DESPAWN,60000);
            m_creature->setDeathState(CORPSE);
            Spawn = true;
        }
        return;
    }
};
CreatureAI* GetAI_mob_shattered_rumbler(Creature *_Creature)
{
    return new mob_shattered_rumblerAI (_Creature);
}

/*######
## mob_lump
######*/

#define SPELL_VISUAL_SLEEP  16093
#define SPELL_SPEAR_THROW   32248

#define LUMP_SAY0 "In Nagrand, food hunt ogre!"
#define LUMP_SAY1 "You taste good with maybe a little salt and pepper."

#define LUMP_DEFEAT "OK, OK! Lump give up!"

struct TRINITY_DLL_DECL mob_lumpAI : public ScriptedAI
{
    mob_lumpAI(Creature *c) : ScriptedAI(c)
    {
        bReset = false;
        Reset();
    }

    uint32 Reset_Timer;
    uint32 Spear_Throw_Timer;
    bool bReset;

    void Reset()
    {
        Reset_Timer = 60000;
        Spear_Throw_Timer = 2000;

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    }

    void DamageTaken(Unit *done_by, uint32 & damage)
    {
        if (done_by->GetTypeId() == TYPEID_PLAYER && (m_creature->GetHealth() - damage)*100 / m_creature->GetMaxHealth() < 30)
        {
            if (!bReset && ((Player*)done_by)->GetQuestStatus(9918) == QUEST_STATUS_INCOMPLETE)
            {
                //Take 0 damage
                damage = 0;

                ((Player*)done_by)->AttackStop();
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                m_creature->RemoveAllAuras();
                m_creature->DeleteThreatList();
                m_creature->CombatStop();
                m_creature->setFaction(1080);               //friendly
                m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, PLAYER_STATE_SIT);
                m_creature->Say(LUMP_DEFEAT, LANG_UNIVERSAL, 0);

                bReset = true;
            }
        }
    }

    void Aggro(Unit *who)
    {
        if (m_creature->HasAura(SPELL_VISUAL_SLEEP,0))
            m_creature->RemoveAura(SPELL_VISUAL_SLEEP,0);

        if (!m_creature->IsStandState())
            m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, PLAYER_STATE_NONE);

        switch(rand()%2)
        {
            case 0:
                DoSay(LUMP_SAY0,LANG_UNIVERSAL,NULL);
                break;
            case 1:
                DoSay(LUMP_SAY1,LANG_UNIVERSAL,NULL);
                break;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //check if we waiting for a reset
        if (bReset)
        {
            if (Reset_Timer < diff)
            {
                EnterEvadeMode();
                bReset = false;
                m_creature->setFaction(1711);               //hostile
            }
            else Reset_Timer -= diff;
        }

        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        //Spear_Throw_Timer
        if (Spear_Throw_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SPEAR_THROW);
            Spear_Throw_Timer = 20000;
        }else Spear_Throw_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_lump(Creature *_creature)
{
    return new mob_lumpAI(_creature);
}

bool GossipHello_mob_lump(Player *player, Creature *_Creature)
{
    if (player->GetQuestStatus(9918) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM( 0, "I need answers, ogre!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    player->SEND_GOSSIP_MENU(9352, _Creature->GetGUID());

    return true;
}

bool GossipSelect_mob_lump(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF:
            player->ADD_GOSSIP_ITEM( 0, "Why are Boulderfist out this far? You know that this is Kurenai territory.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SEND_GOSSIP_MENU(9353, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM( 0, "And you think you can just eat anything you want? You're obviously trying to eat the Broken of Telaar.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->SEND_GOSSIP_MENU(9354, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->ADD_GOSSIP_ITEM( 0, "This means war, Lump! War I say!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->SEND_GOSSIP_MENU(9355, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            player->SEND_GOSSIP_MENU(9356, _Creature->GetGUID());
            player->TalkedToCreature(18354, _Creature->GetGUID());
            break;
    }
    return true;
}

/*####
# mob_sunspring_villager - should be done with ACID
####*/

struct TRINITY_DLL_DECL mob_sunspring_villagerAI : public ScriptedAI
{
    mob_sunspring_villagerAI(Creature *c) : ScriptedAI(c) {Reset();}

    void Reset()
    {
        m_creature->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 32);
        m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1,7);   // lay down
    }

    void Aggro(Unit *who) {}

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if(spell->Id == 32146)
        {
            m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            m_creature->RemoveCorpse();
        }
    }
};
CreatureAI* GetAI_mob_sunspring_villager(Creature *_Creature)
{
    return new mob_sunspring_villagerAI (_Creature);
}

/*######
## npc_altruis_the_sufferer
######*/

bool GossipHello_npc_altruis_the_sufferer(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    //gossip before obtaining Survey the Land
    if ( player->GetQuestStatus(9991) == QUEST_STATUS_NONE )
        player->ADD_GOSSIP_ITEM( 0, "I see twisted steel and smell sundered earth.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+10);

    //gossip when Survey the Land is incomplete (technically, after the flight)
    if (player->GetQuestStatus(9991) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM( 0, "Well...?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+20);

    //wowwiki.com/Varedis
    if (player->GetQuestStatus(10646) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM( 0, "[PH] Story about Illidan's Pupil", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+30);

    player->SEND_GOSSIP_MENU(9419, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_altruis_the_sufferer(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF+10:
            player->ADD_GOSSIP_ITEM( 0, "Legion?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->SEND_GOSSIP_MENU(9420, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+11:
            player->ADD_GOSSIP_ITEM( 0, "And now?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
            player->SEND_GOSSIP_MENU(9421, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+12:
            player->ADD_GOSSIP_ITEM( 0, "How do you see them now?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
            player->SEND_GOSSIP_MENU(9422, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+13:
            player->ADD_GOSSIP_ITEM( 0, "Forge camps?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
            player->SEND_GOSSIP_MENU(9423, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+14:
            player->SEND_GOSSIP_MENU(9424, _Creature->GetGUID());
            break;

        case GOSSIP_ACTION_INFO_DEF+20:
            player->ADD_GOSSIP_ITEM( 0, "Ok.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 21);
            player->SEND_GOSSIP_MENU(9427, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+21:
            player->CLOSE_GOSSIP_MENU();
            player->AreaExploredOrEventHappens(9991);
            break;

        case GOSSIP_ACTION_INFO_DEF+30:
            player->ADD_GOSSIP_ITEM( 0, "[PH] Story done", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 31);
            player->SEND_GOSSIP_MENU(384, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+31:
            player->CLOSE_GOSSIP_MENU();
            player->AreaExploredOrEventHappens(10646);
            break;
    }
    return true;
}

bool QuestAccept_npc_altruis_the_sufferer(Player *player, Creature *creature, Quest const *quest )
{
    if ( !player->GetQuestRewardStatus(9991) )              //Survey the Land, q-id 9991
    {
        player->CLOSE_GOSSIP_MENU();

        std::vector<uint32> nodes;

        nodes.resize(2);
        nodes[0] = 113;                                     //from
        nodes[1] = 114;                                     //end at
        player->ActivateTaxiPathTo(nodes);                  //TaxiPath 532
    }
    return true;
}

/*######
## npc_greatmother_geyah
######*/

//all the textId's for the below is unknown, but i do believe the gossip item texts are proper.
bool GossipHello_npc_greatmother_geyah(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if (player->GetQuestStatus(10044) == QUEST_STATUS_INCOMPLETE)
    {
        player->ADD_GOSSIP_ITEM( 0, "Hello, Greatmother. Garrosh told me that you wanted to speak with me.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(),_Creature->GetGUID());
    }
    else if (player->GetQuestStatus(10172) == QUEST_STATUS_INCOMPLETE)
    {
        player->ADD_GOSSIP_ITEM( 0, "Garrosh is beyond redemption, Greatmother. I fear that in helping the Mag'har, I have convinced Garrosh that he is unfit to lead.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
        player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(),_Creature->GetGUID());
    }
    else

        player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(),_Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_greatmother_geyah(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
            player->ADD_GOSSIP_ITEM( 0, "You raised all of the orcs here, Greatmother?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            player->ADD_GOSSIP_ITEM( 0, "Do you believe that?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            player->ADD_GOSSIP_ITEM( 0, "What can be done? I have tried many different things. I have done my best to help the people of Nagrand. Each time I have approached Garrosh, he has dismissed me.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:
            player->ADD_GOSSIP_ITEM( 0, "Left? How can you choose to leave?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:
            player->ADD_GOSSIP_ITEM( 0, "What is this duty?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:
            player->ADD_GOSSIP_ITEM( 0, "Is there anything I can do for you, Greatmother?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:
            player->AreaExploredOrEventHappens(10044);
            player->CLOSE_GOSSIP_MENU();
            break;

        case GOSSIP_ACTION_INFO_DEF + 10:
            player->ADD_GOSSIP_ITEM( 0, "I have done all that I could, Greatmother. I thank you for your kind words.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:
            player->ADD_GOSSIP_ITEM( 0, "Greatmother, you are the mother of Durotan?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
            player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:
            player->ADD_GOSSIP_ITEM( 0, "Greatmother, I never had the honor. Durotan died long before my time, but his heroics are known to all on my world. The orcs of Azeroth reside in a place known as Durotar, named after your son. And ... (You take a moment to breathe and think through what you are about to tell the Greatmother.)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
            player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 13:
            player->ADD_GOSSIP_ITEM( 0, "It is my Warchief, Greatmother. The leader of my people. From my world. He ... He is the son of Durotan. He is your grandchild.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
            player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 14:
            player->ADD_GOSSIP_ITEM( 0, "I will return to Azeroth at once, Greatmother.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 15);
            player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 15:
            player->AreaExploredOrEventHappens(10172);
            player->CLOSE_GOSSIP_MENU();
            break;
    }
    return true;
}

/*######
## npc_lantresor_of_the_blade
######*/

bool GossipHello_npc_lantresor_of_the_blade(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if (player->GetQuestStatus(10107) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(10108) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM( 0, "I have killed many of your ogres, Lantresor. I have no fear.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    player->SEND_GOSSIP_MENU(9361, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_lantresor_of_the_blade(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF:
            player->ADD_GOSSIP_ITEM( 0, "Should I know? You look like an orc to me.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SEND_GOSSIP_MENU(9362, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM( 0, "And the other half?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->SEND_GOSSIP_MENU(9363, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->ADD_GOSSIP_ITEM( 0, "I have heard of your kind, but I never thought to see the day when I would meet a half-breed.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->SEND_GOSSIP_MENU(9364, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            player->ADD_GOSSIP_ITEM( 0, "My apologies. I did not mean to offend. I am here on behalf of my people.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->SEND_GOSSIP_MENU(9365, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            player->ADD_GOSSIP_ITEM( 0, "My people ask that you pull back your Boulderfist ogres and cease all attacks on our territories. In return, we will also pull back our forces.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->SEND_GOSSIP_MENU(9366, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            player->ADD_GOSSIP_ITEM( 0, "We will fight you until the end, then, Lantresor. We will not stand idly by as you pillage our towns and kill our people.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->SEND_GOSSIP_MENU(9367, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
            player->ADD_GOSSIP_ITEM( 0, "What do I need to do?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->SEND_GOSSIP_MENU(9368, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+7:
            player->SEND_GOSSIP_MENU(9369, _Creature->GetGUID());
            if (player->GetQuestStatus(10107) == QUEST_STATUS_INCOMPLETE)
                player->AreaExploredOrEventHappens(10107);
            if (player->GetQuestStatus(10108) == QUEST_STATUS_INCOMPLETE)
                player->AreaExploredOrEventHappens(10108);
            break;
    }
    return true;
}

/*######
## npc_creditmarker_visist_with_ancestors (Quest 10085)
######*/

struct TRINITY_DLL_DECL npc_creditmarker_visit_with_ancestorsAI : public ScriptedAI
{
    npc_creditmarker_visit_with_ancestorsAI(Creature* c) : ScriptedAI(c) { Reset(); }

    void Reset() {}

    void Aggro(Unit* who) {}

    void MoveInLineOfSight(Unit *who)
    {
        if(!who)
            return;

        if(who->GetTypeId() == TYPEID_PLAYER)
        {
            if(((Player*)who)->GetQuestStatus(10085) == QUEST_STATUS_INCOMPLETE)
            {
                uint32 creditMarkerId = m_creature->GetEntry();
                if((creditMarkerId >= 18840) && (creditMarkerId <= 18843))
                {
                    // 18840: Sunspring, 18841: Laughing, 18842: Garadar, 18843: Bleeding
                    if(!((Player*)who)->GetReqKillOrCastCurrentCount(10085, creditMarkerId))
                        ((Player*)who)->KilledMonster(creditMarkerId, m_creature->GetGUID());
                }
            }
        }
    }
};

CreatureAI* GetAI_npc_creditmarker_visit_with_ancestors(Creature *_Creature)
{
    return new npc_creditmarker_visit_with_ancestorsAI (_Creature);
}

/*######
## AddSC
######*/

void AddSC_nagrand()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="mob_shattered_rumbler";
    newscript->GetAI = GetAI_mob_shattered_rumbler;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_lump";
    newscript->GetAI = GetAI_mob_lump;
    newscript->pGossipHello =  &GossipHello_mob_lump;
    newscript->pGossipSelect = &GossipSelect_mob_lump;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_sunspring_villager";
    newscript->GetAI = GetAI_mob_sunspring_villager;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_altruis_the_sufferer";
    newscript->pGossipHello =  &GossipHello_npc_altruis_the_sufferer;
    newscript->pGossipSelect = &GossipSelect_npc_altruis_the_sufferer;
    newscript->pQuestAccept =  &QuestAccept_npc_altruis_the_sufferer;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_greatmother_geyah";
    newscript->pGossipHello =  &GossipHello_npc_greatmother_geyah;
    newscript->pGossipSelect = &GossipSelect_npc_greatmother_geyah;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_lantresor_of_the_blade";
    newscript->pGossipHello =  &GossipHello_npc_lantresor_of_the_blade;
    newscript->pGossipSelect = &GossipSelect_npc_lantresor_of_the_blade;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_creditmarker_visit_with_ancestors";
    newscript->GetAI = GetAI_npc_creditmarker_visit_with_ancestors;
    m_scripts[nrscripts++] = newscript;
}
