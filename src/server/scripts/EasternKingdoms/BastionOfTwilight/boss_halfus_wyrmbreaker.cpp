/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2005 - 2011 MaNGOS <http://www.getmangos.org/>
 * Copyright (C) 2008 - 2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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

#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "bastion_of_twilight.h"
#include "GameObject.h"
#include "SpellAuras.h"
#include <cstring>

enum spell
{
    SPELL_UNRESPONSIVE                            = 86022,
    SPELL_DRAGONS_VEGEANCE                        = 87683,
    SPELL_MALEVOLENT_STRIKE                       = 83908,
    SPELL_MALEVOLENT_STRIKE_TRIG                  = 39171,
    SPELL_STONE_TOUCH                             = 83603,
    SPELL_STONE_GRIP                              = 84593,
    SPELL_FRENZIED_ASSAULT_                       = 83693,
    SPELL_NETHER_BLINDNESS                        = 83611,
    SPELL_FIREBOLT_BARRAGE_SLOW                   = 83733, // 83733
    SPELL_FIREBOLT_BARRAGE_FAST                   = 83720,
    SPELL_TIME_DILATATION                         = 83601,
    SPELL_SCORCHING_BREATH                        = 83707,
    SPELL_SHADOW_NOVA                             = 83703,
    SPELL_SHADOW_WRAPPED                          = 83952,
    SPELL_DANCING_FLAMES                          = 84106,
    SPELL_CYCLONE_WINDS                           = 84092,
    SPELL_ENRAGE                                  = 26662,
    SPELL_FURIOUS_ROAR                            = 83710,
    SPELL_ATROPHIC_POISON                         = 83609,
    SPELL_SUPERHEATED_BREATH                      = 83956,
};

enum events
{
    EVENT_MALEVOLENT_STRIKE = 1,
    EVENT_FRENZIED_ASSOULT,
    EVENT_FIREBALL_BARRAGE,
    EVENT_ENRAGE,
    EVENT_FURIOUS_ROAR,
    EVENT_SHADOW_NOVA,
    EVENT_SCORCHING_BREATH,
};

enum sharedActions
{
    ACTION_FIREBALL_BARRAGE_START                  = 1,
    ACTION_BREATH_START                            = 2,
};

class boss_halfus_wyrmbreaker : public CreatureScript
{
    public:
        boss_halfus_wyrmbreaker() : CreatureScript("boss_halfus_wyrmbreaker") {}

        struct boss_halfus_wyrmbreakerAI : public BossAI
        {
            boss_halfus_wyrmbreakerAI(Creature * creature) : BossAI(creature, DATA_WYRMBREAKER)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            uint8 barrageCount;
            bool firstFuriosCasted;
            uint8 roarCount;

            void Reset() override
            {
                instance->SetData(DATA_WYRMBREAKER_EVENT, NOT_STARTED);
                events.Reset();
                me->ClearUnitState(UNIT_STATE_STUNNED);
                barrageCount = 0;
                roarCount = 0;
                firstFuriosCasted = false;

                // Add Shadow nova aura (HEROIC)
                if (me->GetMap() && me->GetMap()->IsHeroic())
                    me->AddAura(SPELL_SHADOW_WRAPPED, me);

                if (Creature* dragon = instance->GetCreature(NPC_NETHER_SCION))
                {
                    if (!dragon->IsAlive())
                        dragon->Respawn(true);
                    else
                        dragon->AI()->EnterEvadeMode();
                }

                if (Creature* dragon = instance->GetCreature(NPC_STORM_RIDER))
                {
                    if (!dragon->IsAlive())
                        dragon->Respawn(true);
                    else
                        dragon->AI()->EnterEvadeMode();
                }

                if (Creature* dragon = instance->GetCreature(NPC_SLATE_DRAKE))
                {
                    if (!dragon->IsAlive())
                        dragon->Respawn(true);
                    else
                        dragon->AI()->EnterEvadeMode();
                }

                if (Creature* dragon = instance->GetCreature(NPC_TIME_WARDEN))
                {
                    if (!dragon->IsAlive())
                        dragon->Respawn(true);
                    else
                        dragon->AI()->EnterEvadeMode();
                }

                if (Creature* dragon = instance->GetCreature(NPC_PROTO_BEHEMOTH))
                {
                    if (!dragon->IsAlive())
                        dragon->Respawn(true);
                    else
                        dragon->AI()->EnterEvadeMode();
                }

                std::list<Creature*> unitList;
                me->GetCreatureListWithEntryInGrid(unitList, 44641, 100.0f);
                for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                {
                    if (!(*itr)->IsAlive())
                        (*itr)->Respawn(true);
                    else
                        (*itr)->AI()->EnterEvadeMode();
                }
            }

            void EnterCombat(Unit* /*who*/) override
            {
                DoZoneInCombat(me);

                instance->SetData(DATA_WYRMBREAKER_EVENT, IN_PROGRESS);

                me->Yell("Cho'gall will have your heads! ALL OF THEM!", LANG_UNIVERSAL, 0);
                DoPlaySoundToSet(me, 20186);

                // Increased Attack Speed
                me->AddAura(SPELL_FRENZIED_ASSAULT, me);

                // Malevolent Strike Aura trigger
                me->AddAura(SPELL_MALEVOLENT_STRIKE_TRIG, me);

                // Add Heroic Auras & Events
                if (me->GetMap() && me->GetMap()->IsHeroic())
                {
                    me->AddAura(SPELL_SHADOW_WRAPPED, me);
                    events.ScheduleEvent(EVENT_SHADOW_NOVA, urand(11000, 12000));
                    events.ScheduleEvent(EVENT_SCORCHING_BREATH, urand(25000, 27000));
                }

                // Firball Barrage activator
                if (Creature* proto = instance->GetCreature(NPC_PROTO_BEHEMOTH))
                {
                    me->AddAura(SPELL_DANCING_FLAMES, proto);
                    DoZoneInCombat(proto);
                    proto->SetReactState(REACT_PASSIVE);
                    proto->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    proto->Attack(me->GetVictim(), true);
                    proto->AttackStop();
                    proto->StopMoving();

                    // Superheated breath!
                    if (me->GetMap() && me->GetMap()->IsHeroic())
                        me->AddAura(SPELL_SUPERHEATED_BREATH, proto);

                    events.ScheduleEvent(EVENT_FIREBALL_BARRAGE, urand(15000, 20000));
                }
                events.ScheduleEvent(EVENT_ENRAGE, 360000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (instance)
                {
                    instance->SetData(DATA_WYRMBREAKER_EVENT, DONE);
                    if (Creature* proto = instance->GetCreature(NPC_PROTO_BEHEMOTH))
                        proto->DisappearAndDie();
                }
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                me->Yell("The burden of the damned falls upon you!", LANG_UNIVERSAL, 0);
                DoPlaySoundToSet(me, 20188);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage) override
            {
                if (damage > 0)
                {
                    if (me->HealthBelowPct(50) && !firstFuriosCasted)
                    {
                        firstFuriosCasted = true;
                        events.ScheduleEvent(EVENT_FURIOUS_ROAR, 1000);
                    }
                }
            }

            void DoAction(int32 actionId) override
            {
                switch (actionId)
                {
                    case ACTION_BREATH_START:
                        events.ScheduleEvent(EVENT_SCORCHING_BREATH, urand(25000, 27000));
                        break;
                }
            }

            void UpdateAI(uint32 diff) override

            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SCORCHING_BREATH:
                            // Cast breath
                            if (Creature* proto = instance->GetCreature(NPC_PROTO_BEHEMOTH))
                            {
                                proto->CastSpell(proto, SPELL_SCORCHING_BREATH, false);
                                events.ScheduleEvent(EVENT_SCORCHING_BREATH, urand(25000, 27000));
                            }
                            break;
                        case EVENT_FIREBALL_BARRAGE:
                            // Cast barrage on random players
                            if (Creature* proto = instance->GetCreature(NPC_PROTO_BEHEMOTH))
                            {
                                for (uint8 i = 0; i < RAID_MODE(urand(1, !proto->HasAura(SPELL_TIME_DILATATION) ? 4 : 6), urand(3, !proto->HasAura(SPELL_TIME_DILATATION) ? 8 : 16)); ++i)
                                {
                                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 0))
                                    {
                                        if (proto->HasAura(SPELL_TIME_DILATATION))
                                            proto->CastSpell(target, SPELL_FIREBOLT_BARRAGE_SLOW, true);
                                        else
                                            proto->CastSpell(target, SPELL_FIREBOLT_BARRAGE_FAST, true);
                                    }
                                }

                                ++barrageCount;
                                if (barrageCount == (proto->HasAura(SPELL_TIME_DILATATION) ? 3 : 8))
                                {
                                    barrageCount = 0;
                                    events.ScheduleEvent(EVENT_FIREBALL_BARRAGE, urand(13000, 15000));
                                } else
                                    events.ScheduleEvent(EVENT_FIREBALL_BARRAGE, !proto->HasAura(SPELL_TIME_DILATATION) ? 2500 : 1000);
                            }
                            break;
                        case EVENT_ENRAGE:
                            me->CastSpell(me, SPELL_ENRAGE, true);
                            break;
                        case EVENT_FURIOUS_ROAR:
                            roarCount++;
                            me->CastSpell(me, SPELL_FURIOUS_ROAR, false);
                            if (roarCount < 3)
                            {
                                events.ScheduleEvent(EVENT_FURIOUS_ROAR, 3000);
                            }
                            else
                            {
                                roarCount = 0;
                                events.ScheduleEvent(EVENT_FURIOUS_ROAR, 30000);
                            }
                            break;
                        case EVENT_SHADOW_NOVA:
                            me->CastSpell(me, SPELL_SHADOW_NOVA, false);
                            events.ScheduleEvent(EVENT_SHADOW_NOVA, urand(8000, 9000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_halfus_wyrmbreakerAI(creature);
        }
};

class npc_halfus_dragon : public CreatureScript
{
    public:
        npc_halfus_dragon() : CreatureScript("npc_halfus_dragon")
        { }

        struct npc_halfus_dragonAI : public ScriptedAI
        {
            npc_halfus_dragonAI(Creature * creature) : ScriptedAI(creature)
            {
                pInstance = (InstanceScript*)creature->GetInstanceScript();
            }

            InstanceScript* pInstance;

            void Reset() override
            {
                me->RemoveAllAuras();
                me->setFaction(35);

                switch (me->GetEntry())
                {
                    case NPC_STORM_RIDER:
                        if (me->GetMap() && !me->GetMap()->IsHeroic())
                            me->AddAura(SPELL_UNRESPONSIVE, me);

                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        return;
                    default:
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* halfus = pInstance->GetCreature(DATA_WYRMBREAKER))
                {
                    if (halfus->HasAura(SPELL_DRAGONS_VEGEANCE))
                    {
                        if (Aura* vengeance = halfus->GetAura(SPELL_DRAGONS_VEGEANCE))
                        {
                            uint8 stacks = vengeance->GetStackAmount();
                            stacks++;
                            halfus->SetAuraStack(SPELL_DRAGONS_VEGEANCE, halfus, stacks);
                        }
                    }
                    else
                        me->AddAura(SPELL_DRAGONS_VEGEANCE, halfus);
                }
            }

            void UpdateAI(uint32 /*uiDiff*/) override
            {
                if (me->HasFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE))
                {
                    me->SetReactState(REACT_PASSIVE);
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_halfus_dragonAI(creature);
        }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (!player || !creature)
                return false;

            if (creature->HasAura(SPELL_UNRESPONSIVE))
                return false;

            player->PlayerTalkClass->ClearMenus();
            CloseGossipMenuFor(player);

            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            creature->setFaction(14);
            creature->SetReactState(REACT_AGGRESSIVE);

            if (InstanceScript* instance = creature->GetInstanceScript())
            {
                if (Creature* halfus = instance->GetCreature(DATA_WYRMBREAKER))
                {
                    switch (creature->GetEntry())
                    {
                        case NPC_SLATE_DRAKE:
                            creature->AddAura(SPELL_STONE_TOUCH, halfus);
                            break;
                        case NPC_NETHER_SCION:
                            creature->AddAura(SPELL_NETHER_BLINDNESS, halfus);
                            break;
                        case NPC_TIME_WARDEN:
                            if (InstanceScript* instance = creature->GetInstanceScript())
                            {
                                if (Creature* proto = instance->GetCreature(NPC_PROTO_BEHEMOTH))
                                    creature->AddAura(SPELL_TIME_DILATATION, proto);
                            }
                            break;
                        case NPC_STORM_RIDER:
                            creature->AddAura(SPELL_CYCLONE_WINDS, halfus);
                            break;
                    }

                    if (!halfus->IsInCombat())
                    {
                        halfus->Attack(player, true);
                        halfus->GetMotionMaster()->MoveChase(player, 1.0f, 1.0f);
                    }
                }
            }
            creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            return true;
        }

        bool OnGossipSelect(Player* /*pPlayer*/, Creature* /*creature*/, uint32 /*uiSender*/, uint32 /*uiAction*/) override
        {
            return true;
        }
};

class spell_halfus_stone_touch : public SpellScriptLoader
{
    public:
        spell_halfus_stone_touch() : SpellScriptLoader("spell_halfus_stone_touch") { }

        class spell_halfus_stone_touch_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halfus_stone_touch_AuraScript);

            void HandleEffectApply(AuraEffect const * /*aurEff*/)
            {
                if (Unit * target = GetTarget())
                {
                    target->AddUnitState(UNIT_STATE_STUNNED);
                    target->ClearUnitState(UNIT_STATE_CASTING);
                    target->AddAura(SPELL_STONE_GRIP, target);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_halfus_stone_touch_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_halfus_stone_touch_AuraScript();
        }
};

class spell_halfus_stone_grip : public SpellScriptLoader
{
    public:
        spell_halfus_stone_grip() : SpellScriptLoader("spell_halfus_stone_grip") { }

        class spell_halfus_stone_grip_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halfus_stone_grip_AuraScript);

            void HandleEffectApply(AuraEffect const * /*aurEff*/)
            {
                if (Unit * target = GetTarget())
                {
                    target->ClearUnitState(UNIT_STATE_STUNNED);
                    target->RemoveAurasDueToSpell(SPELL_STONE_GRIP);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_halfus_stone_grip_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_halfus_stone_grip_AuraScript();
        }
};

class go_whelp_cage : public GameObjectScript
{
public:
    go_whelp_cage() : GameObjectScript("go_whelp_cage") { }

    bool OnGossipHello(Player* pPlayer, GameObject* pGO) override
    {
        if (!pPlayer || !pPlayer->ToUnit() || !pGO)
            return false;

        InstanceScript* instance;
        instance = pGO->GetInstanceScript();
        if (!instance)
            return false;

        std::list<Creature*> unitList;
        pGO->GetCreatureListWithEntryInGrid(unitList, 44641, 100.0f);
        for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
        {
            // Venom da drake!
            if (Creature* proto = instance->GetCreature(NPC_PROTO_BEHEMOTH))
                (*itr)->AddAura(SPELL_ATROPHIC_POISON, proto);

            (*itr)->setFaction(14);
            (*itr)->SetReactState(REACT_AGGRESSIVE);

        }

        if (Creature* halfus = instance->GetCreature(DATA_WYRMBREAKER))
        {
            if (!halfus->IsInCombat())
            {
                halfus->Attack(pPlayer, true);
                halfus->GetMotionMaster()->MoveChase(pPlayer, 1.0f, 1.0f);
            }
        }

        pGO->SetGoState(GO_STATE_ACTIVE);
        return true;
    }
};

void AddSC_boss_halfus_wyrmbreaker()
{
    new boss_halfus_wyrmbreaker();
    new npc_halfus_dragon();
    new spell_halfus_stone_touch();
    new spell_halfus_stone_grip();
    new go_whelp_cage();
}
