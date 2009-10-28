/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>.sourceforge.net/>
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
SDComment: Quest support: 9849, 9868, 9918, 9874, 9991, 10107, 10108, 10044, 10172, 10646, 10085, 10987. TextId's unknown for altruis_the_sufferer and greatmother_geyah (npc_text)
SDCategory: Nagrand
EndScriptData */

/* ContentData
mob_shattered_rumbler
mob_lump
mob_sunspring_villager
npc_altruis_the_sufferer
npc_greatmother_geyah
npc_lantresor_of_the_blade
npc_maghar_captive
npc_creditmarker_visit_with_ancestors
mob_sparrowhawk
EndContentData */

#include "precompiled.h"
#include "escort_ai.h"

/*######
## mob_shattered_rumbler - this should be done with ACID
######*/

struct TRINITY_DLL_DECL mob_shattered_rumblerAI : public ScriptedAI
{
    bool Spawn;

    mob_shattered_rumblerAI(Creature *c) : ScriptedAI(c) {}

    void Reset()
    {
        Spawn = false;
    }

    void EnterCombat(Unit* who) {}

    void SpellHit(Unit *Hitter, const SpellEntry *Spellkind)
    {
        if (Spellkind->Id == 32001 && !Spawn)
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
CreatureAI* GetAI_mob_shattered_rumbler(Creature* pCreature)
{
    return new mob_shattered_rumblerAI (pCreature);
}

/*######
## mob_lump
######*/

#define SPELL_VISUAL_SLEEP  16093
#define SPELL_SPEAR_THROW   32248

#define LUMP_SAY0 -1000293
#define LUMP_SAY1 -1000294

#define LUMP_DEFEAT -1000295

#define GOSSIP_HL "I need answers, ogre!"
#define GOSSIP_SL1 "Why are Boulderfist out this far? You know that this is Kurenai territory."
#define GOSSIP_SL2 "And you think you can just eat anything you want? You're obviously trying to eat the Broken of Telaar."
#define GOSSIP_SL3 "This means war, Lump! War I say!"

struct TRINITY_DLL_DECL mob_lumpAI : public ScriptedAI
{
    mob_lumpAI(Creature *c) : ScriptedAI(c)
    {
        bReset = false;
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

    void AttackedBy(Unit* pAttacker)
    {
        if (m_creature->getVictim())
            return;

        if (m_creature->IsFriendlyTo(pAttacker))
            return;

        AttackStart(pAttacker);
    }

    void DamageTaken(Unit *done_by, uint32 & damage)
    {
        if (done_by->GetTypeId() == TYPEID_PLAYER && (m_creature->GetHealth() - damage)*100 / m_creature->GetMaxHealth() < 30)
        {
            if (!bReset && CAST_PLR(done_by)->GetQuestStatus(9918) == QUEST_STATUS_INCOMPLETE)
            {
                //Take 0 damage
                damage = 0;

                CAST_PLR(done_by)->AttackStop();
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                m_creature->RemoveAllAuras();
                m_creature->DeleteThreatList();
                m_creature->CombatStop(true);
                m_creature->setFaction(1080);               //friendly
                m_creature->SetStandState(UNIT_STAND_STATE_SIT);
                DoScriptText(LUMP_DEFEAT, m_creature);

                bReset = true;
            }
        }
    }

    void EnterCombat(Unit *who)
    {
        if (m_creature->HasAura(SPELL_VISUAL_SLEEP))
            m_creature->RemoveAura(SPELL_VISUAL_SLEEP);

        if (!m_creature->IsStandState())
             m_creature->SetStandState(UNIT_STAND_STATE_STAND);

        DoScriptText(RAND(LUMP_SAY0,LUMP_SAY1), m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        //check if we waiting for a reset
        if (bReset)
        {
            if (Reset_Timer <= diff)
            {
                EnterEvadeMode();
                bReset = false;
                m_creature->setFaction(1711);               //hostile
                return;
            }
            else Reset_Timer -= diff;
        }

        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Spear_Throw_Timer
        if (Spear_Throw_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SPEAR_THROW);
            Spear_Throw_Timer = 20000;
        } else Spear_Throw_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_lump(Creature* pCreature)
{
    return new mob_lumpAI(pCreature);
}

bool GossipHello_mob_lump(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(9918) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    pPlayer->SEND_GOSSIP_MENU(9352, pCreature->GetGUID());

    return true;
}

bool GossipSelect_mob_lump(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SL1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->SEND_GOSSIP_MENU(9353, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SL2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(9354, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SL3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(9355, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->SEND_GOSSIP_MENU(9356, pCreature->GetGUID());
            pPlayer->TalkedToCreature(18354, pCreature->GetGUID());
            break;
    }
    return true;
}

/*####
# mob_sunspring_villager - should be done with ACID
####*/

struct TRINITY_DLL_DECL mob_sunspring_villagerAI : public ScriptedAI
{
    mob_sunspring_villagerAI(Creature *c) : ScriptedAI(c) {}

    void Reset()
    {
        m_creature->SetUInt32Value(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
        m_creature->SetStandState(UNIT_STAND_STATE_DEAD);
    }

    void EnterCombat(Unit *who) {}

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if (spell->Id == 32146)
        {
            m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            m_creature->RemoveCorpse();
        }
    }
};
CreatureAI* GetAI_mob_sunspring_villager(Creature* pCreature)
{
    return new mob_sunspring_villagerAI (pCreature);
}

/*######
## npc_altruis_the_sufferer
######*/

#define GOSSIP_HATS1 "I see twisted steel and smell sundered earth."
#define GOSSIP_HATS2 "Well...?"
#define GOSSIP_HATS3 "[PH] Story about Illidan's Pupil"

#define GOSSIP_SATS1 "Legion?"
#define GOSSIP_SATS2 "And now?"
#define GOSSIP_SATS3 "How do you see them now?"
#define GOSSIP_SATS4 "Forge camps?"
#define GOSSIP_SATS5 "Ok."
#define GOSSIP_SATS6 "[PH] Story done"

bool GossipHello_npc_altruis_the_sufferer(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    //gossip before obtaining Survey the Land
    if (pPlayer->GetQuestStatus(9991) == QUEST_STATUS_NONE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HATS1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+10);

    //gossip when Survey the Land is incomplete (technically, after the flight)
    if (pPlayer->GetQuestStatus(9991) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HATS2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+20);

    //wowwiki.com/Varedis
    if (pPlayer->GetQuestStatus(10646) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HATS3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+30);

    pPlayer->SEND_GOSSIP_MENU(9419, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_altruis_the_sufferer(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+10:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SATS1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
            pPlayer->SEND_GOSSIP_MENU(9420, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+11:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SATS2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
            pPlayer->SEND_GOSSIP_MENU(9421, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+12:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SATS3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
            pPlayer->SEND_GOSSIP_MENU(9422, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+13:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SATS4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
            pPlayer->SEND_GOSSIP_MENU(9423, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+14:
            pPlayer->SEND_GOSSIP_MENU(9424, pCreature->GetGUID());
            break;

        case GOSSIP_ACTION_INFO_DEF+20:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SATS5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 21);
            pPlayer->SEND_GOSSIP_MENU(9427, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+21:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->AreaExploredOrEventHappens(9991);
            break;

        case GOSSIP_ACTION_INFO_DEF+30:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SATS6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 31);
            pPlayer->SEND_GOSSIP_MENU(384, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+31:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->AreaExploredOrEventHappens(10646);
            break;
    }
    return true;
}

bool QuestAccept_npc_altruis_the_sufferer(Player* pPlayer, Creature* pCreature, Quest const *quest)
{
    if (!pPlayer->GetQuestRewardStatus(9991))              //Survey the Land, q-id 9991
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->ActivateTaxiPathTo(532);                  //TaxiPath 532
    }
    return true;
}

/*######
## npc_greatmother_geyah
######*/

#define GOSSIP_HGG1 "Hello, Greatmother. Garrosh told me that you wanted to speak with me."
#define GOSSIP_HGG2 "Garrosh is beyond redemption, Greatmother. I fear that in helping the Mag'har, I have convinced Garrosh that he is unfit to lead."

#define GOSSIP_SGG1 "You raised all of the orcs here, Greatmother?"
#define GOSSIP_SGG2 "Do you believe that?"
#define GOSSIP_SGG3 "What can be done? I have tried many different things. I have done my best to help the people of Nagrand. Each time I have approached Garrosh, he has dismissed me."
#define GOSSIP_SGG4 "Left? How can you choose to leave?"
#define GOSSIP_SGG5 "What is this duty?"
#define GOSSIP_SGG6 "Is there anything I can do for you, Greatmother?"
#define GOSSIP_SGG7 "I have done all that I could, Greatmother. I thank you for your kind words."
#define GOSSIP_SGG8 "Greatmother, you are the mother of Durotan?"
#define GOSSIP_SGG9 "Greatmother, I never had the honor. Durotan died long before my time, but his heroics are known to all on my world. The orcs of Azeroth reside in a place known as Durotar, named after your son. And ... (You take a moment to breathe and think through what you are about to tell the Greatmother.)"
#define GOSSIP_SGG10 "It is my Warchief, Greatmother. The leader of my people. From my world. He ... He is the son of Durotan. He is your grandchild."
#define GOSSIP_SGG11 "I will return to Azeroth at once, Greatmother."

//all the textId's for the below is unknown, but i do believe the gossip item texts are proper.
bool GossipHello_npc_greatmother_geyah(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(10044) == QUEST_STATUS_INCOMPLETE)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HGG1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
    }
    else if (pPlayer->GetQuestStatus(10172) == QUEST_STATUS_INCOMPLETE)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HGG2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
        pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
    }
    else

        pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_greatmother_geyah(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SGG1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SGG2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SGG3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SGG4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SGG5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SGG6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:
            pPlayer->AreaExploredOrEventHappens(10044);
            pPlayer->CLOSE_GOSSIP_MENU();
            break;

        case GOSSIP_ACTION_INFO_DEF + 10:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SGG7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
            pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SGG8, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
            pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SGG9, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
            pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 13:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SGG10, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
            pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 14:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SGG11, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 15);
            pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 15:
            pPlayer->AreaExploredOrEventHappens(10172);
            pPlayer->CLOSE_GOSSIP_MENU();
            break;
    }
    return true;
}

/*######
## npc_lantresor_of_the_blade
######*/

#define GOSSIP_HLB "I have killed many of your ogres, Lantresor. I have no fear."
#define GOSSIP_SLB1 "Should I know? You look like an orc to me."
#define GOSSIP_SLB2 "And the other half?"
#define GOSSIP_SLB3 "I have heard of your kind, but I never thought to see the day when I would meet a half-breed."
#define GOSSIP_SLB4 "My apologies. I did not mean to offend. I am here on behalf of my people."
#define GOSSIP_SLB5 "My people ask that you pull back your Boulderfist ogres and cease all attacks on our territories. In return, we will also pull back our forces."
#define GOSSIP_SLB6 "We will fight you until the end, then, Lantresor. We will not stand idly by as you pillage our towns and kill our people."
#define GOSSIP_SLB7 "What do I need to do?"

bool GossipHello_npc_lantresor_of_the_blade(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(10107) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(10108) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HLB, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    pPlayer->SEND_GOSSIP_MENU(9361, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_lantresor_of_the_blade(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SLB1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->SEND_GOSSIP_MENU(9362, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SLB2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(9363, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SLB3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(9364, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SLB4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->SEND_GOSSIP_MENU(9365, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SLB5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->SEND_GOSSIP_MENU(9366, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SLB6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->SEND_GOSSIP_MENU(9367, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SLB7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->SEND_GOSSIP_MENU(9368, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+7:
            pPlayer->SEND_GOSSIP_MENU(9369, pCreature->GetGUID());
            if (pPlayer->GetQuestStatus(10107) == QUEST_STATUS_INCOMPLETE)
                pPlayer->AreaExploredOrEventHappens(10107);
            if (pPlayer->GetQuestStatus(10108) == QUEST_STATUS_INCOMPLETE)
                pPlayer->AreaExploredOrEventHappens(10108);
            break;
    }
    return true;
}

/*#####
## npc_maghar_captive
#####*/

enum eMagharCaptive
{
    SAY_MAG_START               = -1000482,
    SAY_MAG_NO_ESCAPE           = -1000483,
    SAY_MAG_MORE                = -1000484,
    SAY_MAG_MORE_REPLY          = -1000485,
    SAY_MAG_LIGHTNING           = -1000486,
    SAY_MAG_SHOCK               = -1000487,
    SAY_MAG_COMPLETE            = -1000488,

    SPELL_CHAIN_LIGHTNING       = 16006,
    SPELL_EARTHBIND_TOTEM       = 15786,
    SPELL_FROST_SHOCK           = 12548,
    SPELL_HEALING_WAVE          = 12491,

    QUEST_TOTEM_KARDASH_H       = 9868,

    NPC_MURK_RAIDER             = 18203,
    NPC_MURK_BRUTE              = 18211,
    NPC_MURK_SCAVENGER          = 18207,
    NPC_MURK_PUTRIFIER          = 18202
};

static float m_afAmbushA[]= {-1568.805786, 8533.873047, 1.958};
static float m_afAmbushB[]= {-1491.554321, 8506.483398, 1.248};

struct TRINITY_DLL_DECL npc_maghar_captiveAI : public npc_escortAI
{
    npc_maghar_captiveAI(Creature* pCreature) : npc_escortAI(pCreature) { Reset(); }

    uint32 m_uiChainLightningTimer;
    uint32 m_uiHealTimer;
    uint32 m_uiFrostShockTimer;

    void Reset()
    {
        m_uiChainLightningTimer = 1000;
        m_uiHealTimer = 0;
        m_uiFrostShockTimer = 6000;
    }

    void Aggro(Unit* pWho)
    {
        m_creature->CastSpell(m_creature, SPELL_EARTHBIND_TOTEM, false);
    }

    void WaypointReached(uint32 uiPointId)
    {
        switch(uiPointId)
        {
            case 7:
                DoScriptText(SAY_MAG_MORE, m_creature);

                if (Creature* pTemp = m_creature->SummonCreature(NPC_MURK_PUTRIFIER, m_afAmbushB[0], m_afAmbushB[1], m_afAmbushB[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000))
                    DoScriptText(SAY_MAG_MORE_REPLY, pTemp);

                m_creature->SummonCreature(NPC_MURK_PUTRIFIER, m_afAmbushB[0]-2.5f, m_afAmbushB[1]-2.5f, m_afAmbushB[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);

                m_creature->SummonCreature(NPC_MURK_SCAVENGER, m_afAmbushB[0]+2.5f, m_afAmbushB[1]+2.5f, m_afAmbushB[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                m_creature->SummonCreature(NPC_MURK_SCAVENGER, m_afAmbushB[0]+2.5f, m_afAmbushB[1]-2.5f, m_afAmbushB[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                break;
            case 16:
                DoScriptText(SAY_MAG_COMPLETE, m_creature);

                if (Player* pPlayer = GetPlayerForEscort())
                    pPlayer->GroupEventHappens(QUEST_TOTEM_KARDASH_H, m_creature);

                SetRun();
                break;
        }
    }

    void JustSummoned(Creature* pSummoned)
    {
        if (pSummoned->GetEntry() == NPC_MURK_BRUTE)
            DoScriptText(SAY_MAG_NO_ESCAPE, pSummoned);

        if (pSummoned->isTotem())
            return;

        pSummoned->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
        pSummoned->GetMotionMaster()->MovePoint(0, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ());
        pSummoned->AI()->AttackStart(m_creature);

    }

    void SpellHitTarget(Unit* pTarget, const SpellEntry* pSpell)
    {
        if (pSpell->Id == SPELL_CHAIN_LIGHTNING)
        {
            if (rand()%10)
                return;

            DoScriptText(SAY_MAG_LIGHTNING, m_creature);
        }
    }

    void UpdateEscortAI(const uint32 uiDiff)
    {
        if (/*!m_creature->SelectHostilTarget() ||*/ !m_creature->getVictim())
            return;

        if (m_uiChainLightningTimer <= uiDiff)
        {
            DoCast(m_creature->getVictim(), SPELL_CHAIN_LIGHTNING);
            m_uiChainLightningTimer = urand(7000, 14000);
        }
        else
            m_uiChainLightningTimer -= uiDiff;

        if (m_creature->GetHealth()*100 < m_creature->GetMaxHealth()*30)
        {
            if (m_uiHealTimer <= uiDiff)
            {
                DoCast(m_creature, SPELL_HEALING_WAVE);
                m_uiHealTimer = 5000;
            }
            else
                m_uiHealTimer -= uiDiff;
        }

        if (m_uiFrostShockTimer <= uiDiff)
        {
            DoCast(m_creature->getVictim(), SPELL_FROST_SHOCK);
            m_uiFrostShockTimer = urand(7500, 15000);
        }
        else
            m_uiFrostShockTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

bool QuestAccept_npc_maghar_captive(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_TOTEM_KARDASH_H)
    {
        if (npc_maghar_captiveAI* pEscortAI = dynamic_cast<npc_maghar_captiveAI*>(pCreature->AI()))
        {
            pCreature->SetStandState(UNIT_STAND_STATE_STAND);
            pCreature->setFaction(232);

            pEscortAI->Start(true, false, pPlayer->GetGUID(), pQuest);

            DoScriptText(SAY_MAG_START, pCreature);

            pCreature->SummonCreature(NPC_MURK_RAIDER, m_afAmbushA[0]+2.5f, m_afAmbushA[1]-2.5f, m_afAmbushA[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            pCreature->SummonCreature(NPC_MURK_PUTRIFIER, m_afAmbushA[0]-2.5f, m_afAmbushA[1]+2.5f, m_afAmbushA[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            pCreature->SummonCreature(NPC_MURK_BRUTE, m_afAmbushA[0], m_afAmbushA[1], m_afAmbushA[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
        }
    }
    return true;
}

CreatureAI* GetAI_npc_maghar_captive(Creature* pCreature)
{
    return new npc_maghar_captiveAI(pCreature);
}

/*######
## npc_creditmarker_visist_with_ancestors
######*/

struct TRINITY_DLL_DECL npc_creditmarker_visit_with_ancestorsAI : public ScriptedAI
{
    npc_creditmarker_visit_with_ancestorsAI(Creature* c) : ScriptedAI(c) {}

    void Reset() {}

    void EnterCombat(Unit* who) {}

    void MoveInLineOfSight(Unit *who)
    {
        if (!who)
            return;

        if (who->GetTypeId() == TYPEID_PLAYER)
        {
            if (CAST_PLR(who)->GetQuestStatus(10085) == QUEST_STATUS_INCOMPLETE)
            {
                uint32 creditMarkerId = m_creature->GetEntry();
                if ((creditMarkerId >= 18840) && (creditMarkerId <= 18843))
                {
                    // 18840: Sunspring, 18841: Laughing, 18842: Garadar, 18843: Bleeding
                    if (!CAST_PLR(who)->GetReqKillOrCastCurrentCount(10085, creditMarkerId))
                        CAST_PLR(who)->KilledMonsterCredit(creditMarkerId, m_creature->GetGUID());
                }
            }
        }
    }
};

CreatureAI* GetAI_npc_creditmarker_visit_with_ancestors(Creature* pCreature)
{
    return new npc_creditmarker_visit_with_ancestorsAI (pCreature);
}

/*######
## mob_sparrowhawk
######*/

#define SPELL_SPARROWHAWK_NET 39810
#define SPELL_ITEM_CAPTIVE_SPARROWHAWK 39812

struct TRINITY_DLL_DECL mob_sparrowhawkAI : public ScriptedAI
{

    mob_sparrowhawkAI(Creature *c) : ScriptedAI(c) {}

    uint32 Check_Timer;
    uint64 PlayerGUID;
    bool fleeing;

    void Reset()
    {
        m_creature->RemoveAurasDueToSpell(SPELL_SPARROWHAWK_NET);
        Check_Timer = 1000;
        PlayerGUID = 0;
        fleeing = false;
    }
    void AttackStart(Unit *who)
    {
        if (PlayerGUID)
            return;

        ScriptedAI::AttackStart(who);
    }

    void EnterCombat(Unit* who) {}

    void MoveInLineOfSight(Unit *who)
    {
        if (!who || PlayerGUID)
            return;

        if (!PlayerGUID && who->GetTypeId() == TYPEID_PLAYER && m_creature->IsWithinDistInMap(who, 30) && CAST_PLR(who)->GetQuestStatus(10987) == QUEST_STATUS_INCOMPLETE)
        {
            PlayerGUID = who->GetGUID();
            return;
        }

        ScriptedAI::MoveInLineOfSight(who);
    }

    void UpdateAI(const uint32 diff)
    {
        if (Check_Timer <= diff)
        {
            if (PlayerGUID)
            {
                if (fleeing && m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() != FLEEING_MOTION_TYPE)
                    fleeing = false;

                Player* pPlayer = Unit::GetPlayer(PlayerGUID);
                if (pPlayer && m_creature->IsWithinDistInMap(pPlayer, 30))
                {
                    if (!fleeing)
                    {
                        m_creature->DeleteThreatList();
                        m_creature->GetMotionMaster()->MoveFleeing(pPlayer);
                        fleeing = true;
                    }
                }
                else if (fleeing)
                {
                    m_creature->GetMotionMaster()->MovementExpired(false);
                    PlayerGUID = 0;
                    fleeing = false;
                }
            }
            Check_Timer = 1000;
        } else Check_Timer -= diff;

        if (PlayerGUID)
            return;

        ScriptedAI::UpdateAI(diff);
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if (caster->GetTypeId() == TYPEID_PLAYER)
        {
            if (spell->Id == SPELL_SPARROWHAWK_NET && CAST_PLR(caster)->GetQuestStatus(10987) == QUEST_STATUS_INCOMPLETE)
            {
                m_creature->CastSpell(caster, SPELL_ITEM_CAPTIVE_SPARROWHAWK, true);
                m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                m_creature->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
            }
        }
        return;
    }
};

CreatureAI* GetAI_mob_sparrowhawk(Creature* pCreature)
{
    return new mob_sparrowhawkAI (pCreature);
}

/*####
#
####*/

void AddSC_nagrand()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "mob_shattered_rumbler";
    newscript->GetAI = &GetAI_mob_shattered_rumbler;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_lump";
    newscript->GetAI = &GetAI_mob_lump;
    newscript->pGossipHello =  &GossipHello_mob_lump;
    newscript->pGossipSelect = &GossipSelect_mob_lump;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_sunspring_villager";
    newscript->GetAI = &GetAI_mob_sunspring_villager;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_altruis_the_sufferer";
    newscript->pGossipHello =  &GossipHello_npc_altruis_the_sufferer;
    newscript->pGossipSelect = &GossipSelect_npc_altruis_the_sufferer;
    newscript->pQuestAccept =  &QuestAccept_npc_altruis_the_sufferer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_greatmother_geyah";
    newscript->pGossipHello =  &GossipHello_npc_greatmother_geyah;
    newscript->pGossipSelect = &GossipSelect_npc_greatmother_geyah;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_lantresor_of_the_blade";
    newscript->pGossipHello =  &GossipHello_npc_lantresor_of_the_blade;
    newscript->pGossipSelect = &GossipSelect_npc_lantresor_of_the_blade;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_maghar_captive";
    newscript->GetAI = &GetAI_npc_maghar_captive;
    newscript->pQuestAccept = &QuestAccept_npc_maghar_captive;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_creditmarker_visit_with_ancestors";
    newscript->GetAI = &GetAI_npc_creditmarker_visit_with_ancestors;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_sparrowhawk";
    newscript->GetAI = &GetAI_mob_sparrowhawk;
    newscript->RegisterSelf();
}

