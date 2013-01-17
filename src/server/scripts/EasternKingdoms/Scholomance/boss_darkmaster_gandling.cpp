/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

/*
Name: Boss_Darkmaster_Gandling
%Complete: 90
Comment: Doors Not yet reopening.
Category: Scholomance
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "scholomance.h"
#include "SpellScript.h"

enum Says
{
   YELL_SUMMONED                = 0
};

enum Spells
{
    SPELL_ARCANEMISSILES        = 15790,
    SPELL_SHADOWSHIELD          = 12040,
    SPELL_CURSE                 = 18702,
    SPELL_SHADOW_PORTAL         = 17950
};

enum Events
{
    EVENT_ARCANEMISSILES        = 1,
    EVENT_SHADOWSHIELD          = 2,
    EVENT_CURSE                 = 3,
    EVENT_SHADOW_PORTAL         = 4
};

class boss_darkmaster_gandling : public CreatureScript
{
    public: boss_darkmaster_gandling() : CreatureScript("boss_darkmaster_gandling") { }

        struct boss_darkmaster_gandlingAI : public BossAI
        {
            boss_darkmaster_gandlingAI(Creature* creature) : BossAI(creature, DATA_DARKMASTERGANDLING) {}

            void Reset()
            {
                _Reset();
                if (GameObject* gate = me->GetMap()->GetGameObject(instance->GetData64(GO_GATE_GANDLING)))
                    gate->SetGoState(GO_STATE_ACTIVE);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                if (GameObject* gate = me->GetMap()->GetGameObject(instance->GetData64(GO_GATE_GANDLING)))
                    gate->SetGoState(GO_STATE_ACTIVE);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_ARCANEMISSILES, 4500);
                events.ScheduleEvent(EVENT_SHADOWSHIELD, 12000);
                events.ScheduleEvent(EVENT_CURSE, 2000);
                events.ScheduleEvent(EVENT_SHADOW_PORTAL, 16000);

                if (GameObject* gate = me->GetMap()->GetGameObject(instance->GetData64(GO_GATE_GANDLING)))
                    gate->SetGoState(GO_STATE_READY);
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                Talk(YELL_SUMMONED);
                me->GetMotionMaster()->MoveRandom(5);
            }

            void UpdateAI(uint32 const diff)
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
                        case EVENT_ARCANEMISSILES:
                            DoCastVictim(SPELL_ARCANEMISSILES, true);
                            events.ScheduleEvent(EVENT_ARCANEMISSILES, 8000);
                            break;
                        case EVENT_SHADOWSHIELD:
                            DoCast(me, SPELL_SHADOWSHIELD);
                            events.ScheduleEvent(EVENT_SHADOWSHIELD, urand(14000, 28000));
                            break;
                        case EVENT_CURSE:
                            DoCastVictim(SPELL_CURSE, true);
                            events.ScheduleEvent(EVENT_CURSE, urand(15000, 27000));
                            break;
                        case EVENT_SHADOW_PORTAL:
                            if (HealthAbovePct(3))
                            {
                                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_SHADOW_PORTAL, true);
                                events.ScheduleEvent(EVENT_SHADOW_PORTAL, urand(17000, 27000));
                            }
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_darkmaster_gandlingAI (creature);
        }
};

// Script for Shadow Portal spell 17950
enum Rooms
{
    ROOM_HALL_OF_SECRETS        = 0,
    ROOM_HALL_OF_THE_DAMNED     = 1,
    ROOM_THE_COVEN              = 2,
    ROOM_THE_SHADOW_VAULT       = 3,
    ROOM_BAROV_FAMILY_VAULT     = 4,
    ROOM_VAULT_OF_THE_RAVENIAN  = 5
};

enum SPSpells
{
    SPELL_SHADOW_PORTAL_HALLOFSECRETS          = 17863,
    SPELL_SHADOW_PORTAL_HALLOFTHEDAMNED        = 17939,
    SPELL_SHADOW_PORTAL_THECOVEN               = 17943,
    SPELL_SHADOW_PORTAL_THESHADOWVAULT         = 17944,
    SPELL_SHADOW_PORTAL_BAROVFAMILYVAULT       = 17946,
    SPELL_SHADOW_PORTAL_VAULTOFTHERAVENIAN     = 17948
};

class spell_shadow_portal : public SpellScriptLoader
{
    public:
        spell_shadow_portal() : SpellScriptLoader("spell_shadow_portal") { }

        class spell_shadow_portal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_shadow_portal_SpellScript);

            void HandleCast(SpellEffIndex /*effIndex*/)
            {
                Creature* caster = GetCaster()->ToCreature();
                int8 attempts  = 0;
                int32 spell_to_cast =0;

                while (!spell_to_cast)
                {
                    if (attempts++ >= 6) break;

                    switch (urand(0, 5))
                    {
                        case ROOM_HALL_OF_SECRETS:
                            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                                if (GameObject::GetGameObject(*caster, instance->GetData64(GO_GATE_RAVENIAN))->GetGoState() == GO_STATE_ACTIVE)
                                    spell_to_cast = SPELL_SHADOW_PORTAL_HALLOFSECRETS;
                            break;
                        case ROOM_HALL_OF_THE_DAMNED:
                            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                                if (GameObject::GetGameObject(*caster, instance->GetData64(GO_GATE_THEOLEN))->GetGoState() == GO_STATE_ACTIVE)
                                    spell_to_cast = SPELL_SHADOW_PORTAL_HALLOFTHEDAMNED;
                            break;
                        case ROOM_THE_COVEN:
                            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                                if (GameObject::GetGameObject(*caster, instance->GetData64(GO_GATE_MALICIA))->GetGoState() == GO_STATE_ACTIVE)
                                    spell_to_cast = SPELL_SHADOW_PORTAL_THECOVEN;
                            break;
                        case ROOM_THE_SHADOW_VAULT:
                            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                                if (GameObject::GetGameObject(*caster, instance->GetData64(GO_GATE_ILLUCIA))->GetGoState() == GO_STATE_ACTIVE)
                                    spell_to_cast = SPELL_SHADOW_PORTAL_THESHADOWVAULT;
                            break;
                        case ROOM_BAROV_FAMILY_VAULT:
                            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                                if (GameObject::GetGameObject(*caster, instance->GetData64(GO_GATE_BAROV))->GetGoState() == GO_STATE_ACTIVE)
                                    spell_to_cast = SPELL_SHADOW_PORTAL_BAROVFAMILYVAULT;
                            break;
                        case ROOM_VAULT_OF_THE_RAVENIAN:
                            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                                if (GameObject::GetGameObject(*caster, instance->GetData64(GO_GATE_POLKELT))->GetGoState() == GO_STATE_ACTIVE)
                                    spell_to_cast = SPELL_SHADOW_PORTAL_VAULTOFTHERAVENIAN;
                            break;
                    }

                    if (spell_to_cast)
                        GetHitUnit()->CastSpell(GetHitUnit(), spell_to_cast);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_shadow_portal_SpellScript::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_shadow_portal_SpellScript();
        }
};

// Script for Shadow Portal spells 17863, 17939, 17943, 17944, 17946, 17948
Position const SummonPos[18] =
{
    // Hall of Secrects



    // The Hall of the damned
    { 177.9624f, -68.23893f, 84.95197f, 3.228859f },
    { 183.7705f, -61.43489f, 84.92424f, 5.148721f },
    { 184.7035f, -77.74805f, 84.92424f, 4.660029f },
    // The Coven
    { 111.7203f, -1.105035f, 85.45985f, 3.961897f },
    { 118.0079f, 6.430664f, 85.31169f, 2.408554f },
    { 120.0276f, -7.496636f, 85.31169f, 2.984513f },
    // The Shadow Vault
    { 245.3716f, 0.628038f, 72.73877f, 0.01745329f },
    { 240.9920f, 3.405653f, 72.73877f, 6.143559f },
    { 240.9543f, -3.182943f, 72.73877f, 0.2268928f },
    // Barov Family Vault
    { 181.8245f, -42.58117f, 75.4812f, 4.660029f },
    { 177.7456f, -42.74745f, 75.4812f, 4.886922f },
    { 185.6157f, -42.91200f, 75.4812f, 4.45059f },
    // Vault of the Ravenian



};

enum Creatures
{
    NPC_RISEN_GUARDIAN                  = 11598
};

enum ScriptEventId
{
    SPELL_EVENT_HALLOFSECRETS          = 5618,
    SPELL_EVENT_HALLOFTHEDAMNED        = 5619,
    SPELL_EVENT_THECOVEN               = 5620,
    SPELL_EVENT_THESHADOWVAULT         = 5621,
    SPELL_EVENT_BAROVFAMILYVAULT       = 5622,
    SPELL_EVENT_VAULTOFTHERAVENIAN     = 5623
};

class spell_shadow_portal_rooms : public SpellScriptLoader
{
    public:
        spell_shadow_portal_rooms() : SpellScriptLoader("spell_shadow_portal_rooms") { }

        class spell_shadow_portal_rooms_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_shadow_portal_rooms_SpellScript);

            void HandleSendEvent(SpellEffIndex effIndex)
            {
                // If only one player in threat list fail spell

                Creature* Summoned = NULL;
                Creature* caster = GetCaster()->ToCreature();

                int8 pos_to_summon = 0;
                int8 phase_to_set = 0;
                int32 gate_to_close = 0;

                switch (GetSpellInfo()->Effects[effIndex].MiscValue)
                {
                    case SPELL_EVENT_HALLOFSECRETS:
                        pos_to_summon = 0; // Not yet spawned
                        phase_to_set = 1;
                        gate_to_close = GO_GATE_RAVENIAN;
                        break;
                    case SPELL_EVENT_HALLOFTHEDAMNED:
                        pos_to_summon = 0;
                        phase_to_set = 2;
                        gate_to_close = GO_GATE_THEOLEN;
                        break;
                    case SPELL_EVENT_THECOVEN:
                        pos_to_summon = 3;
                        phase_to_set = 3;
                        gate_to_close = GO_GATE_MALICIA;
                        break;
                    case SPELL_EVENT_THESHADOWVAULT:
                        pos_to_summon = 6;
                        phase_to_set = 4;
                        gate_to_close = GO_GATE_ILLUCIA;
                        break;
                    case SPELL_EVENT_BAROVFAMILYVAULT:
                        pos_to_summon = 9;
                        phase_to_set = 5;
                        gate_to_close = GO_GATE_BAROV;
                        break;
                    case SPELL_EVENT_VAULTOFTHERAVENIAN:
                        pos_to_summon = 0; // Not yet spawned
                        phase_to_set = 6;
                        gate_to_close = GO_GATE_POLKELT;
                        break;
                    default:
                        break;
                }

                if (gate_to_close && (GetCaster()->GetMap()->GetId() == 289))
                {
                    for (uint8 i = 0; i < 3; ++i)
                    {
                        Summoned = GetCaster()->SummonCreature(NPC_RISEN_GUARDIAN, SummonPos[pos_to_summon++], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                        if (Summoned)
                        {
                            Summoned->GetMotionMaster()->MoveRandom(5);
                            Summoned->AI()->SetData(0, phase_to_set);
                        }
                    }

                    if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                        if (GameObject* gate = GameObject::GetGameObject(*caster, instance->GetData64(gate_to_close)))
                            gate->SetGoState(GO_STATE_READY);
                }
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_shadow_portal_rooms_SpellScript::HandleSendEvent, EFFECT_1, SPELL_EFFECT_SEND_EVENT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_shadow_portal_rooms_SpellScript();
        }
};

void AddSC_boss_darkmaster_gandling()
{
    new boss_darkmaster_gandling();
    new spell_shadow_portal();
    new spell_shadow_portal_rooms();
}
