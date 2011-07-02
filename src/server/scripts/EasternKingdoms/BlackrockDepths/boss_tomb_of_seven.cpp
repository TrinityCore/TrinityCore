/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Tomb_Of_Seven
SD%Complete: 90
SDComment: Learning Smelt Dark Iron if tribute quest rewarded. Missing event.
SDCategory: Blackrock Depths
EndScriptData */

#include "ScriptPCH.h"
#include "blackrock_depths.h"

enum Spells
{
    SPELL_SMELT_DARK_IRON                                  = 14891,
    SPELL_LEARN_SMELT                                      = 14894,
};

enum Quests
{
    QUEST_SPECTRAL_CHALICE                                 = 4083
};

enum Misc
{
    DATA_SKILLPOINT_MIN                                    = 230
};

#define GOSSIP_ITEM_TEACH_1 "Teach me the art of smelting dark iron"
#define GOSSIP_ITEM_TEACH_2 "Continue..."
#define GOSSIP_ITEM_TEACH_3 "[PH] Continue..."
#define GOSSIP_ITEM_TRIBUTE "I want to pay tribute"

class boss_gloomrel : public CreatureScript
{
public:
    boss_gloomrel() : CreatureScript("boss_gloomrel") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TEACH_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                player->SEND_GOSSIP_MENU(2606, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+11:
                player->CLOSE_GOSSIP_MENU();
                creature->CastSpell(player, SPELL_LEARN_SMELT, false);
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TEACH_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
                player->SEND_GOSSIP_MENU(2604, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+22:
                player->CLOSE_GOSSIP_MENU();
                if (InstanceScript* pInstance = creature->GetInstanceScript())
                {
                    //are 5 minutes expected? go template may have data to despawn when used at quest
                    pInstance->DoRespawnGameObject(pInstance->GetData64(DATA_GO_CHALICE), MINUTE*5);
                }
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetQuestRewardStatus(QUEST_SPECTRAL_CHALICE) == 1 && player->GetSkillValue(SKILL_MINING) >= DATA_SKILLPOINT_MIN && !player->HasSpell(SPELL_SMELT_DARK_IRON))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TEACH_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        if (player->GetQuestRewardStatus(QUEST_SPECTRAL_CHALICE) == 0 && player->GetSkillValue(SKILL_MINING) >= DATA_SKILLPOINT_MIN)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TRIBUTE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

};

enum DoomrelSpells
{
    SPELL_SHADOWBOLTVOLLEY                                 = 15245,
    SPELL_IMMOLATE                                         = 12742,
    SPELL_CURSEOFWEAKNESS                                  = 12493,
    SPELL_DEMONARMOR                                       = 13787,
    SPELL_SUMMON_VOIDWALKERS                               = 15092
};

#define GOSSIP_ITEM_CHALLENGE   "Your bondage is at an end, Doom'rel. I challenge you!"
#define GOSSIP_SELECT_DOOMREL   "[PH] Continue..."

class boss_doomrel : public CreatureScript
{
public:
    boss_doomrel() : CreatureScript("boss_doomrel") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_DOOMREL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                player->SEND_GOSSIP_MENU(2605, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->CLOSE_GOSSIP_MENU();
                //start event here
                creature->setFaction(FACTION_HOSTILE);
                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                creature->AI()->AttackStart(player);
                InstanceScript* pInstance = creature->GetInstanceScript();
                if (pInstance)
                    pInstance->SetData64(DATA_EVENSTARTER, player->GetGUID());
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_CHALLENGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->SEND_GOSSIP_MENU(2601, creature->GetGUID());

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_doomrelAI (creature);
    }

    struct boss_doomrelAI : public ScriptedAI
    {
        boss_doomrelAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;
        uint32 ShadowVolley_Timer;
        uint32 Immolate_Timer;
        uint32 CurseOfWeakness_Timer;
        uint32 DemonArmor_Timer;
        bool Voidwalkers;

        void Reset()
        {
            ShadowVolley_Timer = 10000;
            Immolate_Timer = 18000;
            CurseOfWeakness_Timer = 5000;
            DemonArmor_Timer = 16000;
            Voidwalkers = false;

            me->setFaction(FACTION_FRIEND);

            // was set before event start, so set again
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);

            if (pInstance)
            {
                if (pInstance->GetData(DATA_GHOSTKILL) >= 7)
                    me->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
                else
                    me->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void EnterEvadeMode()
        {
            me->RemoveAllAuras();
            me->DeleteThreatList();
            me->CombatStop(true);
            me->LoadCreaturesAddon();
            if (me->isAlive())
                me->GetMotionMaster()->MoveTargetedHome();
            me->SetLootRecipient(NULL);
            if (pInstance)
                pInstance->SetData64(DATA_EVENSTARTER, 0);
        }

        void JustDied(Unit* /*who*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_GHOSTKILL, 1);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //ShadowVolley_Timer
            if (ShadowVolley_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_SHADOWBOLTVOLLEY);
                ShadowVolley_Timer = 12000;
            } else ShadowVolley_Timer -= diff;

            //Immolate_Timer
            if (Immolate_Timer <= diff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(pTarget, SPELL_IMMOLATE);

                Immolate_Timer = 25000;
            } else Immolate_Timer -= diff;

            //CurseOfWeakness_Timer
            if (CurseOfWeakness_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CURSEOFWEAKNESS);
                CurseOfWeakness_Timer = 45000;
            } else CurseOfWeakness_Timer -= diff;

            //DemonArmor_Timer
            if (DemonArmor_Timer <= diff)
            {
                DoCast(me, SPELL_DEMONARMOR);
                DemonArmor_Timer = 300000;
            } else DemonArmor_Timer -= diff;

            //Summon Voidwalkers
            if (!Voidwalkers && HealthBelowPct(51))
            {
                DoCast(me->getVictim(), SPELL_SUMMON_VOIDWALKERS, true);
                Voidwalkers = true;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_tomb_of_seven()
{
    new boss_gloomrel();
    new boss_doomrel();
}
