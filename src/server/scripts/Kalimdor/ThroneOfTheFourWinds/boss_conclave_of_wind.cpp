/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "throne_of_the_four_winds.h"

enum Spells
{
    // Anshal
    SPELL_SOOTHING_BREEZE           = 86205,
    SPELL_SOOTHING_BREEZE_SUMMON    = 86204,
    SPELL_SOOTHING_BREEZE_VISUAL    = 86208,

    SPELL_NURTURE_CHANNEL           = 85422,
    SPELL_NURTURE                   = 85425,
    SPELL_NURTURE_DUMMY_AURA        = 85428,
    SPELL_NURTURE_CREEPER_SUMMON    = 85429,

    SPELL_ZEPHYR_ULTIMATE           = 84638,

    SPELL_WITHERING_WIND            = 85576,
    SPELL_TOXIC_SPORE               = 86281,

    // Nezir
    SPELL_ICE_PATCH                 = 86122,
    SPELL_ICE_PATCH_VISUAL          = 86107,
    SPELL_ICE_PATCH_AURA            = 86111,

    SPELL_PERMAFROST                = 86082,
    SPELL_WIND_CHILL                = 84645,
    SPELL_CHILLING_WINDS            = 85578,

    SPELL_SLEET_STORM_ULTIMATE      = 84644,

    // Rohash
    SPELL_SLICING_GALE              = 86182,

    SPELL_WIND_BLAST                = 86193,
    SPELL_WIND_BLAST_EFFECT         = 85483,

    SPELL_HURRICANE_ULTIMATE        = 84643,

    SPELL_TORNADO                   = 86192,
    SPELL_TORNADO_DMG               = 86134,


    SPELL_DEAFING_WINDS             = 85573,

    SPELL_NO_ENERGY_REGEN           = 72242,
    SPELL_GATHER_STORMS             = 86307,
};

enum Events
{
    // Anshal
    EVENT_SOOTHING_BREEZE           = 1,
    EVENT_NURTURE,
    EVENT_ZEPHYR,
    EVENT_STOP_NURTURE,

    // Nezir
    EVENT_ICE_PATCH,
    EVENT_PERMAFROST,
    EVENT_WIND_CHILL,
    EVENT_SLEET_STORM_ULTIMATE,

    // Rohash
    EVENT_SLICING_GALE,
    EVENT_WIND_BLAST,
    EVENT_WIND_BLAST_END,
    EVENT_HURRICANE,
    EVENT_TORNADO,
    EVENT_STORM_SHIELD,
    EVENT_DESPAWN_TRIGGER
};

Position const TornadoWaypoints [] =
{
    {-4.0624f, 604.63f, 198.49f, 0},
    {-16.88f, 614.48f, 199.49f, 0},
    {-31.12f, 620.74f, 197.69f, 0},
    {-19.41f, 599.69f, 199.49f, 0},
    {-26.89f, 605.23f, 199.49f, 0},
    {-40.16f, 609.25f, 199.48f, 0},
    {-22.98f, 587.98f, 199.49f, 0},
    {-44.01f, 600.01f, 199.49f, 0},
    {-53.95f, 608.68f, 199.48f, 0},
    {-67.92f, 619.45f, 197.06f, 0},
    {-77.55f, 618.57f, 199.49f, 0},
    {-85.30f, 607.88f, 199.49f, 0},
    {-68.97f, 602.52f, 199.48f, 0},
    {-74.77f, 592.49f, 199.48f, 0},
    {-76.74f, 578.68f, 199.48f, 0},
    {-62.66f, 590.42f, 199.48f, 0},
    {-47.44f, 590.97f, 199.46f, 0},
    {-75.72f, 564.73f, 199.48f, 0},
    {-64.95f, 554.41f, 199.48f, 0},
    {-68.06f, 547.86f, 199.48f, 0},
    {-49.25f, 552.65f, 199.48f, 0},
    {-26.08f, 558.72f, 199.48f, 0},
    {-42.69f, 545.89f, 199.48f, 0},
    {-37.36f, 558.31f, 199.48f, 0},
    {-24.81f, 572.06f, 199.48f, 0},
};

class boss_anshal : public CreatureScript
{
public:
    boss_anshal() : CreatureScript("boss_anshal") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_anshalAI (creature);
    }

    struct boss_anshalAI : public BossAI
    {
        boss_anshalAI(Creature* creature) : BossAI(creature, DATA_CONCLAVE_OF_WIND_EVENT)
        {
            //instance = creature->GetInstanceScript();

            creature->SetPowerType(POWER_ENERGY);
            creature->SetMaxPower(POWER_ENERGY, 90);
        }

        //InstanceScript* instance;
        EventMap events;
        uint32 uiRegentimer;
        uint32 uiDownTimer;
        uint32 RecoverTimer;
        ObjectGuid PlayerGUID;
        bool UltimateUsed;
        bool Regen;
        bool CastingHeal;
        uint32 uiCheckAgroo;

        void Reset() override
        {
            _Reset();
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, NOT_STARTED);
            instance->SetData(DATA_GATHERING_STRENGTH, 0);
            instance->SetData(DATA_WEATHER_EVENT, NOT_STARTED);

            events.Reset();
            me->GetMotionMaster()->MoveTargetedHome();
            DespawnCreatures(NPC_RAVENOUS_CREEPER);

            Regen = true;
            CastingHeal = false;

            uiCheckAgroo = 5000;
            uiRegentimer = 1000;
            uiDownTimer = 0;
            RecoverTimer = 1000;
            me->SetPower(POWER_ENERGY, 0);
            me->SetReactState(REACT_PASSIVE);
        }

        void DespawnCreatures(uint32 entry)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, 100.0f);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, FAIL);
            instance->SetData(DATA_GATHERING_STRENGTH, 0);
            _EnterEvadeMode();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, IN_PROGRESS);
            instance->SetData(DATA_GATHERING_STRENGTH, 0);

            events.ScheduleEvent(EVENT_SOOTHING_BREEZE, urand(13000, 15000));
            events.ScheduleEvent(EVENT_NURTURE, urand(30000, 35000));

            me->SetInCombatWithZone();
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void SpellHit(Unit* hitter, const SpellInfo* spell) override
        {
            if (!hitter || !spell)
                return;

            if (spell->Id == SPELL_GATHER_STORMS)
            {
                CastingHeal = false;
                instance->SetData(DATA_GATHERING_STRENGTH, instance->GetData(DATA_GATHERING_STRENGTH)-1);
                me->SetInCombatWithZone();
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (damage >= me->GetHealth())
            {
                uint8 GatherStrenthCount = instance->GetData(DATA_GATHERING_STRENGTH);

                if (GatherStrenthCount < 3)
                {
                    damage = 0;
                    me->SetHealth(1);
                }

                if (CastingHeal == false)
                {
                    instance->SetData(DATA_GATHERING_STRENGTH, GatherStrenthCount+1);
                    //me->setDeathState(CORPSE);
                    me->RemoveAura(SPELL_WITHERING_WIND);
                    DoCast(me, SPELL_GATHER_STORMS);
                    CastingHeal = true;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!instance)
                return;

            if (instance->GetData(DATA_CONCLAVE_OF_WIND_EVENT) == IN_PROGRESS)
            {
                if (uiRegentimer <= diff && Regen)
                {
                    if (me->GetPower(POWER_ENERGY) == 90 && !UltimateUsed && CastingHeal == false)
                    {
                        me->NearTeleportTo(-48.f, 1053.f, 200.f, 3.9f);
                        me->CastSpell(me->GetVictim(), SPELL_ZEPHYR_ULTIMATE);
                        me->AddAura(SPELL_NO_ENERGY_REGEN, me);
                        instance->SetData(DATA_WEATHER_EVENT, IN_PROGRESS);
                        UltimateUsed = true;
                        uiDownTimer = 1000;
                    }
                    else
                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY)+1);

                    uiRegentimer = 1000;
                }
                else uiRegentimer -= diff;

                if (CastingHeal == true)
                    return;

                if (UltimateUsed)
                {
                    if (uiDownTimer <= diff)
                    {
                        Regen = false;
                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY)-6);
                        uiDownTimer = 1000;
                        if (me->GetPower(POWER_ENERGY) == 0)
                        {
                            events.RescheduleEvent(EVENT_SOOTHING_BREEZE, urand(15000, 20000));
                            events.RescheduleEvent(EVENT_NURTURE, urand(30000, 35000));
                            uiRegentimer = 1000;
                            UltimateUsed = false;
                            instance->SetData(DATA_WEATHER_EVENT, NOT_STARTED);
                            me->RemoveAurasDueToSpell(SPELL_NO_ENERGY_REGEN);
                            Regen = true;

                            bool changed = false;
                            if (Creature* nezir = instance->GetCreature(DATA_NEZIR))
                                if (!nezir->FindCurrentSpellBySpellId(SPELL_GATHER_STORMS))
                                {
                                    me->SetPower(POWER_ENERGY, nezir->GetPower(POWER_ENERGY));
                                    changed = true;
                                }

                            if (changed)
                                if (Creature* rohash = instance->GetCreature(DATA_ROHASH))
                                    if (!rohash->FindCurrentSpellBySpellId(SPELL_GATHER_STORMS))
                                        me->SetPower(POWER_ENERGY, rohash->GetPower(POWER_ENERGY));
                        }
                    }
                    else uiDownTimer -= diff;
                }


                if (uiCheckAgroo <= diff)
                {
                    if (!SelectTarget(SELECT_TARGET_NEAREST, 0, 90, true))
                    {
                        if (!me->HasAura(SPELL_WITHERING_WIND))
                            DoCast(me, SPELL_WITHERING_WIND, true);
                    }
                    else
                    {
                        if (me->HasAura(SPELL_WITHERING_WIND))
                            me->RemoveAura(SPELL_WITHERING_WIND);
                    }

                    if (me->GetVictim())
                        if (me->GetDistance2d(me->GetVictim()) > 90)
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 90.0f, true))
                            {
                                me->getThreatManager().resetAllAggro();
                                me->AddThreat(target, 10);
                            }
                    uiCheckAgroo = 5000;
                }
                else uiCheckAgroo -= diff;

                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SOOTHING_BREEZE:
                            if (Creature* creeper = me->FindNearestCreature(45812, 50))
                                DoCast(creeper, SPELL_SOOTHING_BREEZE_SUMMON, true);
                            else
                                DoCast(SPELL_SOOTHING_BREEZE_SUMMON);
                            events.ScheduleEvent(EVENT_SOOTHING_BREEZE, urand(25000, 35000));
                            break;

                        case EVENT_NURTURE:
                            DoCast(me, SPELL_NURTURE_CHANNEL);
                            events.ScheduleEvent(EVENT_STOP_NURTURE, 5000);
                            //events.ScheduleEvent(EVENT_NURTURE, urand(70000, 90000));
                            break;
                        case EVENT_STOP_NURTURE:
                            me->RemoveAurasDueToSpell(SPELL_NURTURE_DUMMY_AURA);
                            me->RemoveAurasDueToSpell(SPELL_NURTURE_CHANNEL);
                            me->RemoveAurasDueToSpell(SPELL_NURTURE_CREEPER_SUMMON);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summon->AI()->DoZoneInCombat();
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, DONE);
            instance->SetData(DATA_GATHERING_STRENGTH, 0);
            instance->DoUpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 88835);
            //instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            //Talk(RAND(SAY_DEATH_1, SAY_DEATH_2));
        }
    };
};

class npc_ravenous_creeper_trigger : public CreatureScript
{
public:
    npc_ravenous_creeper_trigger() : CreatureScript("npc_ravenous_creeper_trigger") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ravenous_creeper_triggerAI(creature);
    }

    struct npc_ravenous_creeper_triggerAI : public Scripted_NoMovementAI
    {
        npc_ravenous_creeper_triggerAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED);
            me->SetReactState(REACT_PASSIVE);
        }

        uint32 DespawnTimer;

        void Reset() override
        {
            DoCast(me, SPELL_NURTURE_CREEPER_SUMMON);
        }

        void JustSummoned(Creature* summon) override
        {
            summon->AI()->DoZoneInCombat();
        }
    };
};

class npc_ravenous_creeper : public CreatureScript
{
public:
    npc_ravenous_creeper() : CreatureScript("npc_ravenous_creeper") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ravenous_creeperAI (creature);
    }

    struct npc_ravenous_creeperAI : public ScriptedAI
    {
        npc_ravenous_creeperAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiToxicTimer;
        uint32 uiCheckAgroo;

        void Reset() override
        {
            uiToxicTimer = 10000;
            uiCheckAgroo = 5000;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (uiToxicTimer <= diff)
            {
                DoCast(me, SPELL_TOXIC_SPORE);
                uiToxicTimer = 21000;
            }else uiToxicTimer -= diff;

            if (uiCheckAgroo <= diff)
            {
                if (me->GetDistance2d(me->GetVictim()) > 90)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        me->getThreatManager().resetAllAggro();
                        me->AddThreat(target, 10);
                    }
                }
                uiCheckAgroo = 5000;
            }else uiCheckAgroo -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class boss_nezir : public CreatureScript
{
public:
    boss_nezir() : CreatureScript("boss_nezir") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_nezirAI (creature);
    }

    struct boss_nezirAI : public BossAI
    {
        boss_nezirAI(Creature* creature) : BossAI(creature, DATA_CONCLAVE_OF_WIND_EVENT)
        {
            //instance = creature->GetInstanceScript();

            creature->SetPowerType(POWER_ENERGY);
            creature->SetMaxPower(POWER_ENERGY, 90);
        }

        //InstanceScript* instance;
        EventMap events;
        uint32 uiRegentimer;
        uint32 uiDownTimer;
        uint32 uiCheckAgroo;
        bool Regen;
        bool UltimateUsed;
        bool CastingHeal;

        void Reset() override
        {
            _Reset();
            me->SetReactState(REACT_PASSIVE);
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, NOT_STARTED);
            instance->SetData(DATA_GATHERING_STRENGTH, 0);
            instance->SetData(DATA_WEATHER_EVENT, NOT_STARTED);

            events.Reset();
            me->GetMotionMaster()->MoveTargetedHome();

            uiCheckAgroo = 5000;
            uiRegentimer = 1000;
            uiDownTimer = 0;
            me->SetPower(POWER_ENERGY, 0);
            Regen = true;
            UltimateUsed = false;
            CastingHeal = false;
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, FAIL);
            instance->SetData(DATA_GATHERING_STRENGTH, 0);
            _EnterEvadeMode();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, IN_PROGRESS);
            instance->SetData(DATA_GATHERING_STRENGTH, 0);

            events.ScheduleEvent(EVENT_ICE_PATCH, urand(10000, 12000));
            events.ScheduleEvent(EVENT_PERMAFROST, urand(20000, 23000));
            events.ScheduleEvent(EVENT_WIND_CHILL, 15000);
            events.ScheduleEvent(EVENT_SLEET_STORM_ULTIMATE, 30000);

            me->SetInCombatWithZone();
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void SpellHit(Unit* hitter, const SpellInfo* spell) override
        {
            if (!hitter || !spell)
                return;

            if (spell->Id == SPELL_GATHER_STORMS)
            {
                CastingHeal = false;
                instance->SetData(DATA_GATHERING_STRENGTH, instance->GetData(DATA_GATHERING_STRENGTH)-1);
                me->SetInCombatWithZone();
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (damage >= me->GetHealth())
            {
                uint8 GatherStrenthCount = instance->GetData(DATA_GATHERING_STRENGTH);

                if (GatherStrenthCount < 3)
                {
                    damage = 0;
                    me->SetHealth(1);
                }

                if (CastingHeal == false)
                {
                    instance->SetData(DATA_GATHERING_STRENGTH, GatherStrenthCount+1);
                    //me->setDeathState(CORPSE);
                    me->RemoveAura(SPELL_CHILLING_WINDS);
                    DoCast(me, SPELL_GATHER_STORMS);
                    CastingHeal = true;
                }
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, DONE);
            instance->SetData(DATA_GATHERING_STRENGTH, 0);
            instance->DoUpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 88835);
            //instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            //Talk(RAND(SAY_DEATH_1, SAY_DEATH_2));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!instance)
                return;

            if (instance->GetData(DATA_CONCLAVE_OF_WIND_EVENT) == IN_PROGRESS)
            {
                if (uiRegentimer <= diff && Regen)
                {
                    if (me->GetPower(POWER_ENERGY) == 90 && !UltimateUsed && CastingHeal == false)
                    {
                        me->CastSpell(me->GetVictim(), SPELL_SLEET_STORM_ULTIMATE);
                        me->AddAura(SPELL_NO_ENERGY_REGEN, me);
                        instance->SetData(DATA_WEATHER_EVENT, IN_PROGRESS);
                        me->NearTeleportTo(188.62f, 812.97f, 199.48f, 0.96f);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                        UltimateUsed = true;
                        uiDownTimer = 1000;
                    }
                    else
                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY)+1);

                    uiRegentimer = 1000;
                }
                else uiRegentimer -= diff;

                if (CastingHeal == true)
                    return;

                if (UltimateUsed)
                {
                    if (uiDownTimer <= diff)
                    {
                        Regen = false;
                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY)-6);
                        uiDownTimer = 1000;
                        if (me->GetPower(POWER_ENERGY) == 0)
                        {
                            uiRegentimer = 1000;
                            UltimateUsed = false;
                            me->RemoveAurasDueToSpell(SPELL_NO_ENERGY_REGEN);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                            instance->SetData(DATA_WEATHER_EVENT, NOT_STARTED);
                            Regen = true;

                            bool changed = false;
                            if (Creature* anshal = instance->GetCreature(DATA_ANSHAL))
                                if (!anshal->FindCurrentSpellBySpellId(SPELL_GATHER_STORMS))
                                {
                                    me->SetPower(POWER_ENERGY, anshal->GetPower(POWER_ENERGY));
                                    changed = true;
                                }

                            if (changed)
                                if (Creature* rohash = instance->GetCreature(DATA_ROHASH))
                                    if (!rohash->FindCurrentSpellBySpellId(SPELL_GATHER_STORMS))
                                        me->SetPower(POWER_ENERGY, rohash->GetPower(POWER_ENERGY));
                        }
                    }
                    else uiDownTimer -= diff;
                }

                if (uiCheckAgroo <= diff)
                {
                    if (!SelectTarget(SELECT_TARGET_NEAREST, 0, 90, true))
                    {
                        if (!me->HasAura(SPELL_CHILLING_WINDS))
                            DoCast(me, SPELL_CHILLING_WINDS, true);
                    }
                    else
                    {
                        if (me->HasAura(SPELL_CHILLING_WINDS))
                            me->RemoveAura(SPELL_CHILLING_WINDS);
                    }

                    if (me->GetVictim())
                        if (me->GetDistance2d(me->GetVictim()) > 90)
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 90.0f, true))
                            {
                                me->getThreatManager().resetAllAggro();
                                me->AddThreat(target, 10);
                            }

                    uiCheckAgroo = 5000;
                }
                else uiCheckAgroo -= diff;

                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ICE_PATCH:
                            if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0 , 30.0f, true))
                                DoCast(target, SPELL_ICE_PATCH);
                            events.ScheduleEvent(EVENT_ICE_PATCH, urand(17000, 22000));
                            break;

                        case EVENT_PERMAFROST:
                            DoCastVictim(SPELL_PERMAFROST);
                            events.ScheduleEvent(EVENT_PERMAFROST, 20000);
                            break;

                        case EVENT_WIND_CHILL:
                            DoCastAOE(SPELL_WIND_CHILL);
                            events.ScheduleEvent(EVENT_WIND_CHILL, 10500);
                            break;

                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        }
    };
};

class npc_ice_patch : public CreatureScript
{
public:
    npc_ice_patch() : CreatureScript("npc_ice_patch") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ice_patchAI (creature);
    }

    struct npc_ice_patchAI : public Scripted_NoMovementAI
    {
        npc_ice_patchAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED);
            me->SetReactState(REACT_PASSIVE);
        }

        uint32 DespawnTimer;

        void Reset() override
        {
            DespawnTimer = 30000;

        }

        void UpdateAI(uint32 diff) override
        {
            if (DespawnTimer <= diff)
            {
                me->DespawnOrUnsummon();

            }
            else DespawnTimer -= diff;
        }
    };
};

class npc_soothing_breeze : public CreatureScript
{
public:
    npc_soothing_breeze() : CreatureScript("npc_soothing_breeze") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_soothing_breezeAI (creature);
    }

    struct npc_soothing_breezeAI : public Scripted_NoMovementAI
    {
        npc_soothing_breezeAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED);
            me->SetReactState(REACT_PASSIVE);
            me->SetSpeed(MOVE_WALK, 0.4f);
        }

        uint32 DespawnTimer;

        void Reset() override
        {
            DespawnTimer = 30000;

        }

        void UpdateAI(uint32 diff) override
        {
            if (DespawnTimer <= diff)
            {
                me->DespawnOrUnsummon();

            }else DespawnTimer -= diff;
        }
    };
};

class npc_tornado_rohash : public CreatureScript
{
public:
    npc_tornado_rohash() : CreatureScript("npc_tornado_rohash") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tornado_rohashAI (creature);
    }

    struct npc_tornado_rohashAI : public ScriptedAI
    {
        npc_tornado_rohashAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        uint32 uiPathTimer;

        void Reset() override
        {
            uiPathTimer = 2000;
        }

        void UpdateAI(uint32 diff) override
        {
            if (uiPathTimer <= diff)
            {
                me->GetMotionMaster()->MovePoint(0, TornadoWaypoints[urand(0, 24)]);
                uiPathTimer = 5000;
            }else uiPathTimer -= diff;
        }
    };
};

class boss_rohash : public CreatureScript
{
public:
    boss_rohash() : CreatureScript("boss_rohash") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_rohashAI (creature);
    }

    struct boss_rohashAI : public BossAI
    {
        boss_rohashAI(Creature* creature) : BossAI(creature, DATA_CONCLAVE_OF_WIND_EVENT)
        {
            creature->SetPowerType(POWER_ENERGY);
            creature->SetMaxPower(POWER_ENERGY, 90);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
            me->ApplySpellImmune(0, IMMUNITY_ID, 85483, true);
        }

        uint32 uiRegentimer;
        uint32 uiDownTimer;
        uint32 uiCheckAgroo;
        uint32 uiTurnTimer;

        bool IsCastingWindBlast;
        bool UltimateUsed;
        bool Regen;
        bool CastingHeal;

        void Reset() override
        {
            _Reset();
            me->SetReactState(REACT_PASSIVE);
            if (instance)
            {
                instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, NOT_STARTED);
                instance->SetData(DATA_GATHERING_STRENGTH, 0);
                instance->SetData(DATA_WEATHER_EVENT, NOT_STARTED);
            }

            IsCastingWindBlast = false;

            events.Reset();

            if (me->IsInWorld())
                me->GetMotionMaster()->MoveTargetedHome();

            uiTurnTimer = 30000;
            uiCheckAgroo = 5000;
            uiRegentimer = 1000;
            uiDownTimer = 0;
            me->SetPower(POWER_ENERGY, 0);

            Regen = true;
            UltimateUsed = false;
            CastingHeal = false;

            if (Creature* trigger = me->FindNearestCreature(45979, 90))
                trigger->DespawnOrUnsummon();

            summons.DespawnAll();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, FAIL);
            instance->SetData(DATA_GATHERING_STRENGTH, 0);
            _EnterEvadeMode();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, IN_PROGRESS);
            instance->SetData(DATA_GATHERING_STRENGTH, 0);

            events.ScheduleEvent(EVENT_SLICING_GALE, 3000);
            events.ScheduleEvent(EVENT_WIND_BLAST, 30000);
            events.ScheduleEvent(EVENT_TORNADO, 10000);

            me->SetInCombatWithZone();
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void JustSummoned(Creature* pSummon) override
        {
            switch (pSummon->GetEntry())
            {
                case NPC_TORNADO:
                {
                    summons.Summon(pSummon);
                    break;
                }
            }
        }

        void SpellHit(Unit* hitter, const SpellInfo* spell) override
        {
            if (!hitter || !spell)
                return;

            if (spell->Id == SPELL_GATHER_STORMS)
            {
                CastingHeal = false;
                instance->SetData(DATA_GATHERING_STRENGTH, instance->GetData(DATA_GATHERING_STRENGTH)-1);
                me->SetInCombatWithZone();
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (damage >= me->GetHealth())
            {
                uint8 GatherStrenthCount = instance->GetData(DATA_GATHERING_STRENGTH);

                if (GatherStrenthCount < 3)
                {
                    damage = 0;
                    me->SetHealth(1);
                }

                if (CastingHeal == false)
                {
                    instance->SetData(DATA_GATHERING_STRENGTH, GatherStrenthCount+1);
                    //me->setDeathState(CORPSE);
                    me->RemoveAura(SPELL_DEAFING_WINDS);
                    DoCast(me, SPELL_GATHER_STORMS);
                    CastingHeal = true;
                }
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, DONE);
            instance->SetData(DATA_GATHERING_STRENGTH, 0);
            instance->DoUpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 88835);
        }

        void SummonThreatController()
        {
            if (Creature* hurricane = me->SummonCreature(46419, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()+25, 3.32963f, TEMPSUMMON_TIMED_DESPAWN, 16000))
            {
                hurricane->SetCanFly(true);
                hurricane->SetDisableGravity(true);
                hurricane->SetUnitMovementFlags(MOVEMENTFLAG_DISABLE_GRAVITY);
                //hurricane->SetVisible(false);
                hurricane->GetMotionMaster()->MoveRotate(15000, urand(0, 1) ? ROTATE_DIRECTION_LEFT : ROTATE_DIRECTION_RIGHT);
            }

            me->SetInCombatWithZone();
            if (Creature* Trigger = me->SummonCreature(45979, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 3.32963f, TEMPSUMMON_TIMED_DESPAWN, 16000))
            {
                Trigger->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                Trigger->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                Trigger->SetReactState(REACT_AGGRESSIVE);
                Trigger->setFaction(18);
                Trigger->Attack(me, true);
                me->AddThreat(Trigger, 200000.0f);
                me->_addAttacker(Trigger);
                me->SetInCombatWith(Trigger);
                events.ScheduleEvent(EVENT_DESPAWN_TRIGGER, 20000);
            }
        }

        void UpdateOrientation()
        {
            float orient = me->GetOrientation();
            me->SetFacingTo(orient - M_PI/75);
            float x, y, z;
            z = me->GetPositionZ();
            me->GetNearPoint2D(x, y, 10.0f, me->GetOrientation());
            if (Creature* temp = me->SummonCreature(34211, x, y, z, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 100))
                me->SetTarget(temp->GetGUID());
        }

        void UpdateAI(uint32 diff) override
        {
            if (!instance)
                return;

            if (instance->GetData(DATA_CONCLAVE_OF_WIND_EVENT) == IN_PROGRESS)
            {
                if (uiRegentimer <= diff && Regen)
                {
                    if (me->GetPower(POWER_ENERGY) == 90 && !UltimateUsed && CastingHeal == false)
                    {
                        SummonThreatController();
                        summons.DespawnEntry(46207);
                        me->CastSpell(me->GetVictim(), SPELL_HURRICANE_ULTIMATE);
                        me->AddAura(SPELL_NO_ENERGY_REGEN, me);
                        instance->SetData(DATA_WEATHER_EVENT, IN_PROGRESS);
                        UltimateUsed = true;
                        uiDownTimer = 1000;
                    }
                    else
                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY)+1);

                    uiRegentimer = 1000;
                }
                else uiRegentimer -= diff;

                if (CastingHeal == true)
                    return;

                if (UltimateUsed)
                {
                    if (uiDownTimer <= diff)
                    {
                        Regen = false;
                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY)-6);
                        uiDownTimer = 1000;
                        if (me->GetPower(POWER_ENERGY) == 0)
                        {
                            uiRegentimer = 1000;
                            UltimateUsed = false;
                            me->RemoveAurasDueToSpell(SPELL_NO_ENERGY_REGEN);
                            instance->SetData(DATA_WEATHER_EVENT, NOT_STARTED);
                            events.ScheduleEvent(EVENT_TORNADO, 10000);
                            Regen = true;

                            bool changed = false;
                            if (Creature* anshal = instance->GetCreature(DATA_ANSHAL))
                                if (!anshal->FindCurrentSpellBySpellId(SPELL_GATHER_STORMS))
                                {
                                    me->SetPower(POWER_ENERGY, anshal->GetPower(POWER_ENERGY));
                                    changed = true;
                                }

                            if (changed)
                                if (Creature* nezir = instance->GetCreature(DATA_NEZIR))
                                    if (!nezir->FindCurrentSpellBySpellId(SPELL_GATHER_STORMS))
                                        me->SetPower(POWER_ENERGY, nezir->GetPower(POWER_ENERGY));
                        }
                    }
                    else uiDownTimer -= diff;
                }

                if (uiCheckAgroo <= diff)
                {
                    if (!SelectTarget(SELECT_TARGET_NEAREST, 0, 90, true))
                    {
                        if (!me->HasAura(SPELL_DEAFING_WINDS))
                            DoCast(me, SPELL_DEAFING_WINDS, true);

                    }else if (me->HasAura(SPELL_DEAFING_WINDS))
                        me->RemoveAura(SPELL_DEAFING_WINDS);

                    if (me->GetVictim())
                        if (me->GetDistance2d(me->GetVictim()) > 90)
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 90, true))
                            {
                                me->getThreatManager().resetAllAggro();
                                me->AddThreat(target, 10);
                            }
                        uiCheckAgroo = 5000;
                }
                else uiCheckAgroo -= diff;

                if (uiTurnTimer <= diff)
                {
                    if (IsCastingWindBlast)
                    {
                        me->SetFacingTo(irand(0,4));
                        UpdateOrientation();
                    }
                    uiTurnTimer = 70;
                }
                else uiTurnTimer -= diff;

                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {

                    case EVENT_WIND_BLAST:
                        me->SetReactState(REACT_PASSIVE);
                        UpdateOrientation();
                        DoCast(SPELL_WIND_BLAST);
                        IsCastingWindBlast = true;
                        uiTurnTimer = 2000;
                        uiCheckAgroo = 15000;
                        events.ScheduleEvent(EVENT_WIND_BLAST_END, 10000);
                        events.ScheduleEvent(EVENT_WIND_BLAST, 90000); // 90s cd
                        break;

                    case EVENT_WIND_BLAST_END:
                        me->SetReactState(REACT_AGGRESSIVE);
                        uiTurnTimer = 0xFFFFFF;
                        IsCastingWindBlast = false;
                        break;

                    case EVENT_SLICING_GALE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 90.0f, true))
                        {
                            DoCast(target, SPELL_SLICING_GALE);
                        }
                        else
                            DoCastVictim(SPELL_SLICING_GALE);
                        events.ScheduleEvent(EVENT_SLICING_GALE, 4000);
                        break;

                    case EVENT_TORNADO:
                        DoCastVictim(SPELL_TORNADO);
                        //events.ScheduleEvent(EVENT_TORNADO, 45000);
                        break;

                    /*case EVENT_DESPAWN_TRIGGER:
                        // Threat Trigger
                        if (Creature* trigger = me->FindNearestCreature(45979, 90))
                            trigger->DespawnOrUnsummon();
                        //Hurricane Trigger
                        if (Creature* trigger = me->FindNearestCreature(46419, 90))
                            trigger->DespawnOrUnsummon();
                        break;
                        */
                    default:
                        break;

                    }
                }
                DoMeleeAttackIfReady();
            }
        }
    };
};

class spell_nurture_aura : public SpellScriptLoader
{
public:
    spell_nurture_aura() : SpellScriptLoader("spell_nurture_aura") {}

    class spell_nurture_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_nurture_aura_AuraScript);

        void HandleEffectCalcPeriodic(AuraEffect const* /*aurEff*/, bool& isPeriodic, int32& /*amplitude*/)
        {
            isPeriodic = true;
        }

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_NURTURE_CREEPER_SUMMON, true);
        }

        void Register() override
        {
            DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_nurture_aura_AuraScript::HandleEffectCalcPeriodic, EFFECT_0, SPELL_AURA_DUMMY);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_nurture_aura_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_nurture_aura_AuraScript();
    }
};

class spell_nezir_sleet_storm : public SpellScriptLoader
{
    public:
        spell_nezir_sleet_storm() : SpellScriptLoader("spell_nezir_sleet_storm") { }

        class spell_nezir_sleet_storm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_nezir_sleet_storm_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                targetCount = unitList.size();
            }

            void CalcDamage()
            {
                SetHitDamage(int32(GetHitDamage() / targetCount));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_nezir_sleet_storm_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnHit += SpellHitFn(spell_nezir_sleet_storm_SpellScript::CalcDamage);
            }

        protected:
            uint32 targetCount;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_nezir_sleet_storm_SpellScript();
        }
};

class PlayerInRangeCheck
{
    public:
        explicit PlayerInRangeCheck(Unit* _caster) : caster(_caster) { }

        bool operator() (WorldObject* unit)
        {
            if (caster->HasInArc(float(M_PI) * 104.0f / 180.0f, unit))
                return false;

            return true;
        }

        Unit* caster;
};

class spell_wind_blast : public SpellScriptLoader
{
    public:
        spell_wind_blast() : SpellScriptLoader("spell_wind_blast") { }

        class spell_wind_blast_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_wind_blast_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove_if(PlayerInRangeCheck(GetCaster()));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_wind_blast_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_wind_blast_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENTRY_110);
            }

        protected:
            uint32 targetCount;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_wind_blast_SpellScript();
        }
};

void AddSC_boss_conclave_of_wind()
{
    new boss_anshal();
    new npc_ravenous_creeper_trigger();
    new npc_ravenous_creeper();
    new npc_soothing_breeze();
    new boss_nezir();
    new npc_ice_patch();
    new boss_rohash();
    new spell_nurture_aura();
    new npc_tornado_rohash();
    new spell_nezir_sleet_storm();
    new spell_wind_blast();
}
