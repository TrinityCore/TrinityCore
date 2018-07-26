/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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

#include "shadopan_monastery.h"
#include "SpellAuras.h"

enum eSpells
{
    SPELL_STEALTH_COSMETIC      = 91194,
    SPELL_CRISE                 = 128248,
    SPELL_ICE_ARROW             = 126114,
    SPELL_EXPLOSION_DAMAGE      = 106966,
    SPELL_PURIFICATION_RITUAL   = 111690,
    SPELL_APPARITIONS_AURA      = 112060,

    // Residual Hatred
    SPELL_CURSE_OF_AGONY        = 112999,
    SPELL_RING_OF_MALICE        = 112932,
    SPELL_SHADOW_BOLT           = 112998,

    // Vestige of Hatred
    SPELL_BLACK_CLEAVE          = 113020,
    SPELL_DEATH_GRIP            = 113021,
    SPELL_ICE_TRAP              = 135382,
    SPELL_TOUCH_OF_WEAKNESS     = 113022,

    // Fragment of Hatred
    //SPELL_ICE_TRAP              = 135382,
    SPELL_SINISTER_STRIKE       = 112931,
    SPELL_VOLLEY_OF_HATRED      = 112911
};

enum eEvents
{
    // Residual Hatred
    EVENT_CURSE_OF_AGONY        = 1,
    EVENT_RING_OF_MALICE        = 2,
    EVENT_SHADOW_BOLT           = 3,

    // Vestige of Hatred
    EVENT_BLACK_CLEAVE          = 4,
    EVENT_DEATH_GRIP            = 5,
    EVENT_ICE_TRAP              = 6,
    EVENT_TOUCH_OF_WEAKNESS     = 7,

    // Fragment of Hatred
    //EVENT_ICE_TRAP              = 8,
    EVENT_SINISTER_STRIKE       = 9,
    EVENT_VOLLEY_OF_HATRED      = 10
};

class npc_shadopan_ambusher : public CreatureScript
{
    public:
        npc_shadopan_ambusher() :  CreatureScript("npc_shadopan_ambusher") { }

        struct npc_shadopan_ambusherAI : public ScriptedAI
        {
            npc_shadopan_ambusherAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 criseTimer;
            bool inFight;

            void Reset() override
            {
                criseTimer = 5000;
                inFight = false;
                me->AddAura(SPELL_STEALTH_COSMETIC, me);
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!inFight && me->GetDistance(who) < 35.0f)
                {
                    inFight = true;
                    me->RemoveAurasDueToSpell(SPELL_STEALTH_COSMETIC);
                    me->GetMotionMaster()->MoveJump(who->GetPositionX() + frand(-2.0f, 2.0f), who->GetPositionY() + frand(-2.0f, 2.0f), who->GetPositionZ(), 20.0f, 20.0f, 1);
                }
            }

            void MovementInform(uint32 uiType, uint32 uiId) override
            {
                if (uiType != EFFECT_MOTION_TYPE)
                    return;

                if (uiId == 1)
                {
                    DoZoneInCombat();
                    if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST))
                        AttackStart(target);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (criseTimer <= diff)
                {
                    DoZoneInCombat();
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                    {
                        me->getThreatManager().addThreat(target, 1000000.0f);
                        me->CastSpell(me, SPELL_CRISE, true);
                    }

                    criseTimer = urand(3000, 5000);
                }
                else criseTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_shadopan_ambusherAI(creature);
        }
};

class npc_shadopan_archery : public CreatureScript
{
    public:
        npc_shadopan_archery() :  CreatureScript("npc_shadopan_archery") { }

        struct npc_shadopan_archeryAI : public ScriptedAI
        {
            npc_shadopan_archeryAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            uint16 fireTimer;
            InstanceScript* pInstance;

            void Reset() override
            {
                fireTimer = urand(2000, 4000);
                me->setActive(true);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!pInstance || !pInstance->GetData(DATA_ARCHERY))
                    return;

                if (fireTimer <= diff)
                {
                    ObjectGuid targetGUID = ObjectGuid::Empty;

                    if (pInstance->GetData(DATA_ARCHERY) == 1 && me->GetEntry() == NPC_ARCHERY_FIRST)
                    {
                        targetGUID = pInstance->GetGuidData(NPC_ARCHERY_TARGET);
                        fireTimer = urand(2000, 4000);
                    }
                    else if (pInstance->GetData(DATA_ARCHERY) == 2 && me->GetEntry() == NPC_ARCHERY_SECOND)
                    {
                        Map::PlayerList const& playerList = pInstance->instance->GetPlayers();

                        if (!playerList.isEmpty())
                        {
                            Map::PlayerList::const_iterator Itr = playerList.begin();

                            uint8 advance = urand(0, playerList.getSize() - 1);
                            for (uint8 i = 0; i < advance; ++i, ++Itr);

                            if (Player* player = Itr->GetSource())
                                targetGUID = player->GetGUID();
                        }

                        fireTimer = urand(5000, 10000);
                    }
                    else
                        fireTimer = 5000;

                    if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
                        me->CastSpell(target, SPELL_ICE_ARROW, false);
                }
                else fireTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_shadopan_archeryAI(creature);
        }
};

class npc_shadopan_hatred : public CreatureScript
{
    public:
        npc_shadopan_hatred() :  CreatureScript("npc_shadopan_hatred") { }

        struct npc_shadopan_hatredAI : public ScriptedAI
        {
            npc_shadopan_hatredAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                if (me->GetEntry() == NPC_RESIDUAL_OF_HATRED)
                {
                    events.ScheduleEvent(EVENT_CURSE_OF_AGONY, urand(1000, 5000));
                    events.ScheduleEvent(EVENT_RING_OF_MALICE, urand(12500, 15000));
                    events.ScheduleEvent(EVENT_SHADOW_BOLT, urand(2500, 10000));
                }
                else if (me->GetEntry() == NPC_VESTIGE_OF_HATRED)
                {
                    events.ScheduleEvent(EVENT_BLACK_CLEAVE, 15000);
                    events.ScheduleEvent(EVENT_DEATH_GRIP, urand(7500, 12500));
                    events.ScheduleEvent(EVENT_ICE_TRAP, urand (17500, 22500));
                    events.ScheduleEvent(EVENT_TOUCH_OF_WEAKNESS, urand(20000, 25000));
                }
                else
                {
                    events.ScheduleEvent(EVENT_ICE_TRAP, urand (17500, 22500));
                    events.ScheduleEvent(EVENT_SINISTER_STRIKE, urand(2500, 10000));
                    events.ScheduleEvent(EVENT_VOLLEY_OF_HATRED, urand(7500, 12500));
                }
            }

            void EnterCombat(Unit* /*victim*/) override
            {
                DoZoneInCombat();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (me->HasAura(SPELL_APPARITIONS_AURA))
                    damage = 0;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                switch(events.ExecuteEvent())
                {
                    // Residual Hatred
                    case EVENT_CURSE_OF_AGONY:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(target, SPELL_CURSE_OF_AGONY, false);

                        events.ScheduleEvent(EVENT_CURSE_OF_AGONY, urand(1000, 5000));
                        break;
                    }
                    case EVENT_RING_OF_MALICE:
                    {
                        me->CastSpell(me, SPELL_RING_OF_MALICE, false);
                        events.ScheduleEvent(EVENT_RING_OF_MALICE, urand(12500, 15000));
                        break;
                    }
                    case EVENT_SHADOW_BOLT:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, SPELL_SHADOW_BOLT, false);

                        events.ScheduleEvent(EVENT_SHADOW_BOLT, urand(2500, 10000));
                        break;
                    }
                    // Vestige of Hatred
                    case EVENT_BLACK_CLEAVE:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, SPELL_BLACK_CLEAVE, false);

                        events.ScheduleEvent(EVENT_BLACK_CLEAVE, 15000);
                        break;
                    }
                    case EVENT_DEATH_GRIP:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST))
                            me->CastSpell(target, SPELL_DEATH_GRIP, false);

                        events.ScheduleEvent(EVENT_DEATH_GRIP, urand(7500, 12500));
                        break;
                    }
                    case EVENT_TOUCH_OF_WEAKNESS:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(target, SPELL_TOUCH_OF_WEAKNESS, false);

                        events.ScheduleEvent(EVENT_TOUCH_OF_WEAKNESS, urand(20000, 25000));
                        break;
                    }
                    // Vestige of Hatred
                    case EVENT_SINISTER_STRIKE:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, SPELL_SINISTER_STRIKE, false);

                        events.ScheduleEvent(EVENT_SINISTER_STRIKE, urand(2500, 10000));
                        break;
                    }
                    case EVENT_VOLLEY_OF_HATRED:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(target, SPELL_TOUCH_OF_WEAKNESS, false);

                        events.ScheduleEvent(EVENT_VOLLEY_OF_HATRED, urand(7500, 12500));
                        break;
                    }
                    // Common
                    case EVENT_ICE_TRAP:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(target, SPELL_ICE_TRAP, false);

                        events.ScheduleEvent(EVENT_ICE_TRAP, urand (17500, 22500));
                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_shadopan_hatredAI(creature);
        }
};

class spell_shadopan_explosion: public SpellScriptLoader
{
    public:
        spell_shadopan_explosion() : SpellScriptLoader("spell_shadopan_explosion") { }

        class spell_shadopan_explosion_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_shadopan_explosion_AuraScript);

            void OnRemove(AuraEffect const*, AuraEffectHandleModes)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEATH)
                    if (Unit* caster = GetCaster())
                        caster->CastSpell(caster, SPELL_EXPLOSION_DAMAGE, true);
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_shadopan_explosion_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_shadopan_explosion_AuraScript();
        }
};

class spell_shadopan_apparitions: public SpellScriptLoader
{
    public:
        spell_shadopan_apparitions() : SpellScriptLoader("spell_shadopan_apparitions") { }

        class spell_shadopan_apparitions_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_shadopan_apparitions_AuraScript);

            void OnPeriodic(AuraEffect const* /*auraEff*/)
            {
                PreventDefaultAction();

                if (Unit* caster = GetCaster())
                {
                    if (caster->HasAura(SPELL_PURIFICATION_RITUAL))
                    {
                        GetAura()->Remove();
                        return;
                    }

                    std::list<Creature*> hatredList;

                    caster->GetCreatureListWithEntryInGridAppend(hatredList, NPC_RESIDUAL_OF_HATRED, 20.0f);
                    caster->GetCreatureListWithEntryInGridAppend(hatredList, NPC_VESTIGE_OF_HATRED,  20.0f);
                    caster->GetCreatureListWithEntryInGridAppend(hatredList, NPC_FRAGMENT_OF_HATRED, 20.0f);

                    for (auto hatred: hatredList)
                        if (hatred->IsAlive())
                            hatred->CastSpell(hatred, GetSpellInfo()->GetEffect(0)->TriggerSpell, true);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_shadopan_apparitions_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_shadopan_apparitions_AuraScript();
        }
};

enum areaTrigger
{
    AREATRIGGER_ARCHERY_FIRST_BEGIN     = 8271,
    AREATRIGGER_ARCHERY_FIRST_END       = 8272,
    AREATRIGGER_ARCHERY_SECOND_FIRST    = 7121,
    AREATRIGGER_ARCHERY_SECOND_END      = 7126
};

class areatrigger_at_shadopan_archery : public AreaTriggerScript
{
    public:

        areatrigger_at_shadopan_archery() : AreaTriggerScript("areatrigger_at_shadopan_archery") {}

        bool OnTrigger(Player* player, AreaTriggerEntry const* trigger, bool /*enter*/) override
        {
            InstanceScript* pInstance = player->GetInstanceScript();

            if (!pInstance)
                return false;

            switch (trigger->ID)
            {
                case AREATRIGGER_ARCHERY_FIRST_BEGIN:
                    pInstance->SetData(DATA_ARCHERY, 1);
                    break;
                case AREATRIGGER_ARCHERY_FIRST_END:
                    pInstance->SetData(DATA_ARCHERY, 0);
                    break;
                case AREATRIGGER_ARCHERY_SECOND_FIRST:
                    pInstance->SetData(DATA_ARCHERY, 2);
                    break;
                case AREATRIGGER_ARCHERY_SECOND_END:
                    pInstance->SetData(DATA_ARCHERY, 0);
                    break;
            }

            return false;
        }
};

void AddSC_shadopan_monastery()
{
    new npc_shadopan_ambusher();
    new npc_shadopan_archery();
    new npc_shadopan_hatred();
    new spell_shadopan_explosion();
    new spell_shadopan_apparitions();
    new areatrigger_at_shadopan_archery();
}
