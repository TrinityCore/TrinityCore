/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Boss_Tomb_Of_Seven
SD%Complete: 90
SDComment: Learning Smelt Dark Iron if tribute quest rewarded. Missing event.
SDCategory: Blackrock Depths
EndScriptData */

#include "precompiled.h"
#include "def_blackrock_depths.h"

enum
{
    SPELL_SUNDERARMOR           = 11971,
    SPELL_SHIELDBLOCK           = 12169,
    SPELL_STRIKE                = 15580
};

struct TRINITY_DLL_DECL boss_angerrelAI : public ScriptedAI
{
    boss_angerrelAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    uint32 SunderArmor_Timer;
    uint32 ShieldBlock_Timer;
    uint32 Strike_Timer;

    void Reset()
    {
        SunderArmor_Timer = 8000;
        ShieldBlock_Timer = 15000;
        Strike_Timer = 12000;        
    }

    void EnterCombat(Unit *who)
    {
    }

    void EnterEvadeMode()
    {
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        m_creature->CombatStop(true);
        m_creature->LoadCreaturesAddon();
        if (m_creature->isAlive())
            m_creature->GetMotionMaster()->MoveTargetedHome();
        m_creature->SetLootRecipient(NULL);
        if (pInstance)
            pInstance->SetData64(DATA_EVENSTARTER, 0);
    }

    void JustDied(Unit *who)
    {
        if (pInstance)
            pInstance->SetData(DATA_GHOSTKILL, 1);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //SunderArmor_Timer
        if (SunderArmor_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SUNDERARMOR);
            SunderArmor_Timer = 28000;
        }else SunderArmor_Timer -= diff;

        //ShieldBlock_Timer
        if (ShieldBlock_Timer < diff)
        {
            DoCast(m_creature,SPELL_SHIELDBLOCK);
            ShieldBlock_Timer = 25000;
        }else ShieldBlock_Timer -= diff;

        //Strike_Timer
        if (Strike_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_STRIKE);
            Strike_Timer = 10000;
        }else Strike_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_angerrel(Creature* pCreature)
{
    return new boss_angerrelAI (pCreature);
}

enum
{
    SPELL_SINISTERSTRIKE        = 15581,
    SPELL_BACKSTAB              = 15582,
    SPELL_GOUGE                 = 12540
};

struct TRINITY_DLL_DECL boss_doperelAI : public ScriptedAI
{
    boss_doperelAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }
    
    ScriptedInstance* pInstance;
    uint32 SinisterStrike_Timer;
    uint32 BackStab_Timer;
    uint32 Gouge_Timer;

    void Reset()
    {
        SinisterStrike_Timer = 8000;
        BackStab_Timer = 12000;
        Gouge_Timer = 6000;
    }

    void EnterCombat(Unit *who)
    {
    }

    void EnterEvadeMode()
    {
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        m_creature->CombatStop(true);
        m_creature->LoadCreaturesAddon();
        if (m_creature->isAlive())
            m_creature->GetMotionMaster()->MoveTargetedHome();
        m_creature->SetLootRecipient(NULL);
        if (pInstance)
            pInstance->SetData64(DATA_EVENSTARTER, 0);
    }

    void JustDied(Unit *who)
    {
        if (pInstance)
            pInstance->SetData(DATA_GHOSTKILL, 1);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //SinisterStrike_Timer
        if (SinisterStrike_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SINISTERSTRIKE);
            SinisterStrike_Timer = 7000;
        }else SinisterStrike_Timer -= diff;

        //BackStab_Timer
        if (BackStab_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_BACKSTAB);
            BackStab_Timer = 6000;
        }else BackStab_Timer -= diff;

        //Gouge_Timer
        if (Gouge_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_GOUGE);
            Gouge_Timer = 8000;
        }else Gouge_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_doperel(Creature* pCreature)
{
    return new boss_doperelAI (pCreature);
}

enum
{
    SPELL_SHADOWBOLT        = 15232,
    SPELL_MANABURN          = 14033,
    SPELL_SHADOWSHIELD      = 12040
};

struct TRINITY_DLL_DECL boss_haterelAI : public ScriptedAI
{
    boss_haterelAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    uint32 ShadowBolt_Timer;
    uint32 ManaBurn_Timer;
    uint32 ShadowShield_Timer;
    uint32 Strike_Timer;

    void Reset()
    {
        ShadowBolt_Timer = 15000;
        ManaBurn_Timer = 3000;
        ShadowShield_Timer = 8000;
        Strike_Timer = 12000;
    }

    void EnterCombat(Unit *who)
    {
    }

    void EnterEvadeMode()
    {
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        m_creature->CombatStop(true);
        m_creature->LoadCreaturesAddon();
        if (m_creature->isAlive())
            m_creature->GetMotionMaster()->MoveTargetedHome();
        m_creature->SetLootRecipient(NULL);
        if (pInstance)
            pInstance->SetData64(DATA_EVENSTARTER, 0);
    }

    void JustDied(Unit *who)
    {
        if (pInstance)
            pInstance->SetData(DATA_GHOSTKILL, 1);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //ShadowBolt_Timer
        if (ShadowBolt_Timer < diff)
        {
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(target,SPELL_SHADOWBOLT);
            ShadowBolt_Timer = 7000;
        }else ShadowBolt_Timer -= diff;

        //ManaBurn_Timer
        if (ManaBurn_Timer < diff)
        {
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(target,SPELL_MANABURN);

            ManaBurn_Timer = 13000;
        }else ManaBurn_Timer -= diff;

        //ShadowShield_Timer
        if (ShadowShield_Timer < diff)
        {
            DoCast(m_creature,SPELL_SHADOWSHIELD);
            ShadowShield_Timer = 25000;
        }else ShadowShield_Timer -= diff;

        //Strike_Timer
        if (Strike_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_STRIKE);
            Strike_Timer = 10000;
        }else Strike_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_haterel(Creature* pCreature)
{
    return new boss_haterelAI (pCreature);
}

enum
{
    SPELL_MINDBLAST             = 15587,
    SPELL_HEAL                  = 15586,
    SPELL_PRAYEROFHEALING       = 15585,
    SPELL_SHIELD                = 11974
};

struct TRINITY_DLL_DECL boss_vilerelAI : public ScriptedAI
{
    boss_vilerelAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    uint32 MindBlast_Timer;
    uint32 Heal_Timer;
    uint32 PrayerOfHealing_Timer;
    uint32 Shield_Timer;

    void Reset()
    {
        MindBlast_Timer = 10000;
        Heal_Timer = 35000;
        PrayerOfHealing_Timer = 25000;
        Shield_Timer = 3000;
    }

    void EnterCombat(Unit *who)
    {
    }

    void EnterEvadeMode()
    {
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        m_creature->CombatStop(true);
        m_creature->LoadCreaturesAddon();
        if (m_creature->isAlive())
            m_creature->GetMotionMaster()->MoveTargetedHome();
        m_creature->SetLootRecipient(NULL);
        if (pInstance)
            pInstance->SetData64(DATA_EVENSTARTER, 0);
    }

    void JustDied(Unit *who)
    {
        if (pInstance)
            pInstance->SetData(DATA_GHOSTKILL, 1);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //MindBlast_Timer
        if (MindBlast_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_MINDBLAST);
            MindBlast_Timer = 7000;
        }else MindBlast_Timer -= diff;

        //Heal_Timer
        if (Heal_Timer < diff)
        {
            DoCast(m_creature,SPELL_HEAL);
            Heal_Timer = 20000;
        }else Heal_Timer -= diff;

        //PrayerOfHealing_Timer
        if (PrayerOfHealing_Timer < diff)
        {
            DoCast(m_creature,SPELL_PRAYEROFHEALING);
            PrayerOfHealing_Timer = 30000;
        }else PrayerOfHealing_Timer -= diff;

        //Shield_Timer
        if (Shield_Timer < diff)
        {
            DoCast(m_creature,SPELL_SHIELD);
            Shield_Timer = 30000;
        }else Shield_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_vilerel(Creature* pCreature)
{
    return new boss_vilerelAI (pCreature);
}

enum
{
    SPELL_FROSTBOLT         = 12675,
    SPELL_FROSTARMOR        = 12544,                        //This is actually a buff he gives himself
    SPELL_CONEOFCOLD        = 15244,
    SPELL_FROSTNOVA         = 12674,
    SPELL_FROSTWARD         = 15044
};

struct TRINITY_DLL_DECL boss_seethrelAI : public ScriptedAI
{
    boss_seethrelAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    uint32 FrostArmor_Timer;
    uint32 Frostbolt_Timer;
    uint32 ConeofCold_Timer;
    uint32 FrostNova_Timer;
    uint32 FrostWard_Timer;

    void Reset()
    {
        FrostArmor_Timer = 2000;
        Frostbolt_Timer = 6000;
        ConeofCold_Timer = 18000;
        FrostNova_Timer = 12000;
        FrostWard_Timer = 25000;

        m_creature->CastSpell(m_creature,SPELL_FROSTARMOR,true);
    }

    void EnterCombat(Unit *who)
    {
    }

    void EnterEvadeMode()
    {
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        m_creature->CombatStop(true);
        m_creature->LoadCreaturesAddon();
        if (m_creature->isAlive())
            m_creature->GetMotionMaster()->MoveTargetedHome();
        m_creature->SetLootRecipient(NULL);
        if (pInstance)
            pInstance->SetData64(DATA_EVENSTARTER, 0);
    }

    void JustDied(Unit *who)
    {
        if (pInstance)
            pInstance->SetData(DATA_GHOSTKILL, 1);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //FrostArmor_Timer
        if (FrostArmor_Timer < diff)
        {
            DoCast(m_creature, SPELL_FROSTARMOR);
            FrostArmor_Timer = 180000;
        }else FrostArmor_Timer -= diff;

        //Frostbolt_Timer
        if (Frostbolt_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_FROSTBOLT);
            Frostbolt_Timer = 15000;
        }else Frostbolt_Timer -= diff;

        //ConeofCold_Timer
        if (ConeofCold_Timer < diff)
        {
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(target,SPELL_CONEOFCOLD);

            ConeofCold_Timer = 22000;
        }else ConeofCold_Timer -= diff;

        //FrostNova_Timer
        if (FrostNova_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_FROSTNOVA);
            FrostNova_Timer = 14000;
        }else FrostNova_Timer -= diff;

        //FrostWard_Timer
        if (FrostWard_Timer < diff)
        {
            DoCast(m_creature,SPELL_FROSTWARD);
            FrostWard_Timer = 68000;
        }else FrostWard_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_seethrel(Creature* pCreature)
{
    return new boss_seethrelAI (pCreature);
}

enum
{
    SPELL_HAMSTRING             = 9080,
    SPELL_CLEAVE                = 40504,
    SPELL_MORTALSTRIKE          = 13737
};

struct TRINITY_DLL_DECL boss_gloomrelAI : public ScriptedAI
{
    boss_gloomrelAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    uint32 Hamstring_Timer;
    uint32 Cleave_Timer;
    uint32 MortalStrike_Timer;

    void Reset()
    {
        Hamstring_Timer = 19000;
        Cleave_Timer = 6000;
        MortalStrike_Timer = 10000;

        m_creature->setFaction(FACTION_FRIEND);
    }

    void EnterCombat(Unit *who)
    {
    }

    void EnterEvadeMode()
    {
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        m_creature->CombatStop(true);
        m_creature->LoadCreaturesAddon();
        if (m_creature->isAlive())
            m_creature->GetMotionMaster()->MoveTargetedHome();
        m_creature->SetLootRecipient(NULL);
        if (pInstance)
            pInstance->SetData64(DATA_EVENSTARTER, 0);
    }

    void JustDied(Unit *who)
    {
        if (pInstance)
            pInstance->SetData(DATA_GHOSTKILL, 1);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //Hamstring_Timer
        if (Hamstring_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_HAMSTRING);
            Hamstring_Timer = 14000;
        }else Hamstring_Timer -= diff;

        //Cleave_Timer
        if (Cleave_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CLEAVE);
            Cleave_Timer = 8000;
        }else Cleave_Timer -= diff;

        //MortalStrike_Timer
        if (MortalStrike_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_MORTALSTRIKE);
            MortalStrike_Timer = 12000;
        }else MortalStrike_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_gloomrel(Creature* pCreature)
{
    return new boss_gloomrelAI (pCreature);
}

#define GOSSIP_ITEM_TEACH_1 "Teach me the art of smelting dark iron"
#define GOSSIP_ITEM_TEACH_2 "Continue..."
#define GOSSIP_ITEM_TRIBUTE "I want to pay tribute"

bool GossipHello_boss_gloomrel(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestRewardStatus(4083) == 1 && pPlayer->GetSkillValue(SKILL_MINING) >= 230 && !pPlayer->HasSpell(14891))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TEACH_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

    if (pPlayer->GetQuestRewardStatus(4083) == 0 && pPlayer->GetSkillValue(SKILL_MINING) >= 230)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TRIBUTE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
    return true;
}

bool GossipSelect_boss_gloomrel(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TEACH_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
            pPlayer->SEND_GOSSIP_MENU(2606, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+11:
            pPlayer->CLOSE_GOSSIP_MENU();
            pCreature->CastSpell(pPlayer, 14894, false);
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "[PH] Continue...", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
            pPlayer->SEND_GOSSIP_MENU(2604, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+22:
            pPlayer->CLOSE_GOSSIP_MENU();
            if (ScriptedInstance* pInstance = pCreature->GetInstanceData())
            {
                //are 5 minutes expected? go template may have data to despawn when used at quest
                pInstance->DoRespawnGameObject(pInstance->GetData64(DATA_GO_CHALICE),MINUTE*5);
            }
            break;
    }
    return true;
}

enum
{
    SPELL_SHADOWBOLTVOLLEY               = 15245,
    SPELL_IMMOLATE                       = 12742,
    SPELL_CURSEOFWEAKNESS                = 12493,
    SPELL_DEMONARMOR                     = 13787,
    SPELL_SUMMON_VOIDWALKERS             = 15092
};

struct TRINITY_DLL_DECL boss_doomrelAI : public ScriptedAI
{
    boss_doomrelAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    uint32 ShadowVolley_Timer;
    uint32 Immolate_Timer;
    uint32 CurseOfWeakness_Timer;
    uint32 DemonArmor_Timer;
    bool Voidwalkers;
    int Rand;
    int RandX;
    int RandY;
    Creature* Summoned;

    void Reset()
    {
        ShadowVolley_Timer = 10000;
        Immolate_Timer = 18000;
        CurseOfWeakness_Timer = 5000;
        DemonArmor_Timer = 16000;
        Voidwalkers = false;

        m_creature->setFaction(FACTION_FRIEND);

        // was set before event start, so set again
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);

        if (pInstance)
            if (pInstance->GetData(DATA_GHOSTKILL) >= 7)
                m_creature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
            else
                m_creature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
    }

    void EnterCombat(Unit *who)
    {
    }

    void EnterEvadeMode()
    {
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        m_creature->CombatStop(true);
        m_creature->LoadCreaturesAddon();
        if (m_creature->isAlive())
            m_creature->GetMotionMaster()->MoveTargetedHome();
        m_creature->SetLootRecipient(NULL);
        if (pInstance)
            pInstance->SetData64(DATA_EVENSTARTER, 0);
    }

    void JustDied(Unit *who)
    {
        if (pInstance)
            pInstance->SetData(DATA_GHOSTKILL, 1);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //ShadowVolley_Timer
        if (ShadowVolley_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SHADOWBOLTVOLLEY);
            ShadowVolley_Timer = 12000;
        }else ShadowVolley_Timer -= diff;

        //Immolate_Timer
        if (Immolate_Timer < diff)
        {
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(target,SPELL_IMMOLATE);

            Immolate_Timer = 25000;
        }else Immolate_Timer -= diff;

        //CurseOfWeakness_Timer
        if (CurseOfWeakness_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CURSEOFWEAKNESS);
            CurseOfWeakness_Timer = 45000;
        }else CurseOfWeakness_Timer -= diff;

        //DemonArmor_Timer
        if (DemonArmor_Timer < diff)
        {
            DoCast(m_creature,SPELL_DEMONARMOR);
            DemonArmor_Timer = 300000;
        }else DemonArmor_Timer -= diff;

        //Summon Voidwalkers
        if (!Voidwalkers && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 51)
        {
            m_creature->CastSpell(m_creature->getVictim(), SPELL_SUMMON_VOIDWALKERS, true);
            Voidwalkers = true;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_doomrel(Creature* pCreature)
{
    return new boss_doomrelAI (pCreature);
}

#define GOSSIP_ITEM_CHALLENGE   "Your bondage is at an end, Doom'rel. I challenge you!"

bool GossipHello_boss_doomrel(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_CHALLENGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->SEND_GOSSIP_MENU(2601, pCreature->GetGUID());

    return true;
}

bool GossipSelect_boss_doomrel(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "[PH] Continue...", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(2605, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->CLOSE_GOSSIP_MENU();
            //start event here
            pCreature->setFaction(FACTION_HOSTILE);
            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
            pCreature->AI()->AttackStart(pPlayer);
            ScriptedInstance* pInstance = pCreature->GetInstanceData();
            if (pInstance)
                pInstance->SetData64(DATA_EVENSTARTER,pPlayer->GetGUID());
            break;
    }
    return true;
}

void AddSC_boss_tomb_of_seven()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_angerrel";
    newscript->GetAI = &GetAI_boss_angerrel;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_doperel";
    newscript->GetAI = &GetAI_boss_doperel;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_haterel";
    newscript->GetAI = &GetAI_boss_haterel;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_vilerel";
    newscript->GetAI = &GetAI_boss_vilerel;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_seethrel";
    newscript->GetAI = &GetAI_boss_seethrel;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_gloomrel";
    newscript->GetAI = &GetAI_boss_gloomrel;
    newscript->pGossipHello = &GossipHello_boss_gloomrel;
    newscript->pGossipSelect = &GossipSelect_boss_gloomrel;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_doomrel";
    newscript->GetAI = &GetAI_boss_doomrel;
    newscript->pGossipHello = &GossipHello_boss_doomrel;
    newscript->pGossipSelect = &GossipSelect_boss_doomrel;
    newscript->RegisterSelf();
}

