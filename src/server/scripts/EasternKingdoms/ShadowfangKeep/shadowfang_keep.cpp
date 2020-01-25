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
SDName: Shadowfang_Keep
SD%Complete: 75
SDComment: npc_shadowfang_prisoner using escortAI for movement to door. Might need additional code in case being attacked. Add proper texts/say().
SDCategory: Shadowfang Keep
EndScriptData */

/* ContentData
npc_shadowfang_prisoner
EndContentData */

#include "ScriptMgr.h"
#include "shadowfang_keep.h"
#include "InstanceScript.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

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

class npc_shadowfang_prisoner : public CreatureScript
{
public:
    npc_shadowfang_prisoner() : CreatureScript("npc_shadowfang_prisoner") { }

    struct npc_shadowfang_prisonerAI : public EscortAI
    {
        npc_shadowfang_prisonerAI(Creature* creature) : EscortAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            if (Player* player = GetPlayerForEscort())
            {
                switch (waypointId)
                {
                    case 0:
                        if (me->GetEntry() == NPC_ASH)
                            Talk(SAY_FREE_AS, player);
                        else
                            Talk(SAY_FREE_AD, player);
                        break;
                    case 10:
                        if (me->GetEntry() == NPC_ASH)
                            Talk(SAY_OPEN_DOOR_AS, player);
                        else
                            Talk(SAY_OPEN_DOOR_AD, player);
                        break;
                    case 11:
                        if (me->GetEntry() == NPC_ASH)
                            DoCast(me, SPELL_UNLOCK);
                        break;
                    case 12:
                        if (me->GetEntry() == NPC_ASH)
                            Talk(SAY_POST_DOOR_AS, player);
                        else
                            Talk(SAY_POST1_DOOR_AD, player);

                        instance->SetData(TYPE_FREE_NPC, DONE);
                        break;
                    case 13:
                        if (me->GetEntry() != NPC_ASH)
                            Talk(SAY_POST2_DOOR_AD, player);
                        break;
                }
            }
        }

        void Reset() override { }
        void JustEngagedWith(Unit* /*who*/) override { }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);
                Start(false, false, player->GetGUID());
            }
            return true;
        }

        bool GossipHello(Player* player) override
        {
            if (instance->GetData(TYPE_FREE_NPC) != DONE && instance->GetData(TYPE_RETHILGORE) == DONE)
                AddGossipItemFor(player, Player::GetDefaultGossipMenuForSource(me), 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetShadowfangKeepAI<npc_shadowfang_prisonerAI>(creature);
    }
};

class npc_arugal_voidwalker : public CreatureScript
{
public:
    npc_arugal_voidwalker() : CreatureScript("npc_arugal_voidwalker") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetShadowfangKeepAI<npc_arugal_voidwalkerAI>(creature);
    }

    struct npc_arugal_voidwalkerAI : public ScriptedAI
    {
        npc_arugal_voidwalkerAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiDarkOffering = urand(200, 1000);
        }

        InstanceScript* instance;

        uint32 uiDarkOffering;

        void Reset() override
        {
            Initialize();
        }

        void UpdateAI(uint32 uiDiff) override
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

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(TYPE_FENRUS, instance->GetData(TYPE_FENRUS) + 1);
        }
    };

};

enum ArugalSpells
{
    SPELL_TELE_UPPER    = 7587,
    SPELL_TELE_SPAWN    = 7586,
    SPELL_TELE_STAIRS   = 7136,
    NUM_TELEPORT_SPELLS =    3,
    SPELL_ARUGAL_CURSE  = 7621,
    SPELL_THUNDERSHOCK  = 7803,
    SPELL_VOIDBOLT      = 7588
};

enum ArugalTexts
{
    SAY_AGGRO       = 1, // You, too, shall serve!
    SAY_TRANSFORM   = 2, // Release your rage!
    SAY_SLAY        = 3  // Another falls!
};

enum ArugalEvents
{
    EVENT_VOID_BOLT = 1,
    EVENT_TELEPORT,
    EVENT_THUNDERSHOCK,
    EVENT_CURSE
};

class boss_archmage_arugal : public CreatureScript
{
    public:
        boss_archmage_arugal() : CreatureScript("boss_archmage_arugal") { }

        struct boss_archmage_arugalAI : public BossAI
        {
            boss_archmage_arugalAI(Creature* creature) : BossAI(creature, BOSS_ARUGAL) { }

            uint32 teleportSpells[NUM_TELEPORT_SPELLS] =
            {
                SPELL_TELE_SPAWN,
                SPELL_TELE_UPPER,
                SPELL_TELE_STAIRS
            };

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_ARUGAL_CURSE)
                    Talk(SAY_TRANSFORM);
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_CURSE, 7s);
                events.ScheduleEvent(EVENT_TELEPORT, 15s);
                events.ScheduleEvent(EVENT_VOID_BOLT, 1s);
                events.ScheduleEvent(EVENT_THUNDERSHOCK, 10s);
            }

            void AttackStart(Unit* who) override
            {
                AttackStartCaster(who, 100.0f); // void bolt range is 100.f
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CURSE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 30.0f, true))
                                DoCast(target, SPELL_ARUGAL_CURSE);
                            events.Repeat(Seconds(15));
                            break;
                        case EVENT_TELEPORT:
                        {
                            // ensure we never cast the same teleport twice in a row
                            uint8 spellIndex = urand(1, NUM_TELEPORT_SPELLS-1);
                            std::swap(teleportSpells[0], teleportSpells[spellIndex]);
                            DoCast(teleportSpells[0]);
                            events.Repeat(Seconds(20));
                            break;
                        }
                        case EVENT_THUNDERSHOCK:
                            DoCastAOE(SPELL_THUNDERSHOCK);
                            events.Repeat(Seconds(30));
                            break;
                        case EVENT_VOID_BOLT:
                            DoCastVictim(SPELL_VOIDBOLT);
                            events.Repeat(Seconds(5));
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetShadowfangKeepAI<boss_archmage_arugalAI>(creature);
        }
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
                GetTarget()->CastSpell(nullptr, aurEff->GetAmount(), true);
            }

            void HandleUpdatePeriodic(AuraEffect* aurEff)
            {
                aurEff->CalculatePeriodic(GetCaster());
            }

            void Register() override
            {
                DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_shadowfang_keep_haunting_spirits_AuraScript::CalcPeriodic, EFFECT_0, SPELL_AURA_DUMMY);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_shadowfang_keep_haunting_spirits_AuraScript::HandleDummyTick, EFFECT_0, SPELL_AURA_DUMMY);
                OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_shadowfang_keep_haunting_spirits_AuraScript::HandleUpdatePeriodic, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_shadowfang_keep_haunting_spirits_AuraScript();
        }
};

void AddSC_shadowfang_keep()
{
    new npc_shadowfang_prisoner();
    new npc_arugal_voidwalker();
    new boss_archmage_arugal();
    new spell_shadowfang_keep_haunting_spirits();
}
