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
SDName: Shadowfang_Keep
SD%Complete: 75
SDComment: npc_shadowfang_prisoner using escortAI for movement to door. Might need additional code in case being attacked. Add proper texts/say().
SDCategory: Shadowfang Keep
EndScriptData */

/* ContentData
npc_shadowfang_prisoner
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "ScriptedEscortAI.h"
#include "shadowfang_keep.h"
#include "Player.h"

/*######
## npc_shadowfang_prisoner
######*/

enum Yells
{
    SAY_FREE_AS             = 0,
    SAY_OPEN_DOOR_AS        = 1,
    SAY_POST_DOOR_AS        = 2,
    SAY_FREE_AD             = 0,
    SAY_OPEN_DOOR_AD        = 1,
    SAY_POST1_DOOR_AD       = 2,
    SAY_POST2_DOOR_AD       = 3
};

enum Spells
{
    SPELL_UNLOCK            = 6421,

    SPELL_DARK_OFFERING     = 7154
};

enum Creatures
{
    NPC_ASH                 = 3850
};

#define GOSSIP_ITEM_DOOR        "Thanks, I'll follow you to the door."

class npc_shadowfang_prisoner : public CreatureScript
{
public:
    npc_shadowfang_prisoner() : CreatureScript("npc_shadowfang_prisoner") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_shadowfang_prisonerAI(creature);
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->CLOSE_GOSSIP_MENU();

            if (npc_escortAI* pEscortAI = CAST_AI(npc_shadowfang_prisoner::npc_shadowfang_prisonerAI, creature->AI()))
                pEscortAI->Start(false, false);
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        InstanceScript* instance = creature->GetInstanceScript();

        if (instance && instance->GetData(TYPE_FREE_NPC) != DONE && instance->GetData(TYPE_RETHILGORE) == DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_DOOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    struct npc_shadowfang_prisonerAI : public npc_escortAI
    {
        npc_shadowfang_prisonerAI(Creature* creature) : npc_escortAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            switch (waypointId)
            {
                case 0:
                    if (me->GetEntry() == NPC_ASH)
                        Talk(SAY_FREE_AS);
                    else
                        Talk(SAY_FREE_AD);
                    break;
                case 10:
                    if (me->GetEntry() == NPC_ASH)
                        Talk(SAY_OPEN_DOOR_AS);
                    else
                        Talk(SAY_OPEN_DOOR_AD);
                    break;
                case 11:
                    if (me->GetEntry() == NPC_ASH)
                        DoCast(me, SPELL_UNLOCK);
                    break;
                case 12:
                    if (me->GetEntry() == NPC_ASH)
                        Talk(SAY_POST_DOOR_AS);
                    else
                        Talk(SAY_POST1_DOOR_AD);

                    if (instance)
                        instance->SetData(TYPE_FREE_NPC, DONE);
                    break;
                case 13:
                    if (me->GetEntry() != NPC_ASH)
                        Talk(SAY_POST2_DOOR_AD);
                    break;
            }
        }

        void Reset() OVERRIDE {}
        void EnterCombat(Unit* /*who*/) OVERRIDE {}
    };

};

class npc_arugal_voidwalker : public CreatureScript
{
public:
    npc_arugal_voidwalker() : CreatureScript("npc_arugal_voidwalker") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_arugal_voidwalkerAI(creature);
    }

    struct npc_arugal_voidwalkerAI : public ScriptedAI
    {
        npc_arugal_voidwalkerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 uiDarkOffering;

        void Reset() OVERRIDE
        {
            uiDarkOffering = urand(200, 1000);
        }

        void UpdateAI(uint32 uiDiff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (uiDarkOffering <= uiDiff)
            {
                if (Creature* pFriend = me->FindNearestCreature(me->GetEntry(), 25.0f, true))
                    DoCast(pFriend, SPELL_DARK_OFFERING);
                else
                    DoCast(me, SPELL_DARK_OFFERING);
                uiDarkOffering = urand(4400, 12500);
            } else uiDarkOffering -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (instance)
                instance->SetData(TYPE_FENRUS, instance->GetData(TYPE_FENRUS) + 1);
        }
    };

};

class spell_shadowfang_keep_haunting_spirits : public SpellScriptLoader
{
    public:
        spell_shadowfang_keep_haunting_spirits() : SpellScriptLoader("spell_shadowfang_keep_haunting_spirits") { }

        class spell_shadowfang_keep_haunting_spirits_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_shadowfang_keep_haunting_spirits_AuraScript);

            void CalcPeriodic(AuraEffect const* /*aurEff*/, bool& isPeriodic, int32& amplitude)
            {
                isPeriodic = true;
                amplitude = (irand(0, 60) + 30) * IN_MILLISECONDS;
            }

            void HandleDummyTick(AuraEffect const* aurEff)
            {
                GetTarget()->CastSpell((Unit*)NULL, aurEff->GetAmount(), true);
            }

            void HandleUpdatePeriodic(AuraEffect* aurEff)
            {
                aurEff->CalculatePeriodic(GetCaster());
            }

            void Register() OVERRIDE
            {
                DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_shadowfang_keep_haunting_spirits_AuraScript::CalcPeriodic, EFFECT_0, SPELL_AURA_DUMMY);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_shadowfang_keep_haunting_spirits_AuraScript::HandleDummyTick, EFFECT_0, SPELL_AURA_DUMMY);
                OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_shadowfang_keep_haunting_spirits_AuraScript::HandleUpdatePeriodic, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_shadowfang_keep_haunting_spirits_AuraScript();
        }
};

void AddSC_shadowfang_keep()
{
    new npc_shadowfang_prisoner();
    new npc_arugal_voidwalker();
    new spell_shadowfang_keep_haunting_spirits();
}
