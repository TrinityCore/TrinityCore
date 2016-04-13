#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "terrace_of_endless_spring.h"

enum Spells
{
    /* Protector Kaolan */
    SPELL_TOUCH_OF_SHA                = 117519,
    SPELL_DEFILED_GROUND_SUMMON       = 117986,
    SPELL_DEFILED_GROUND              = 117989,
    SPELL_EXPEL_CORRUPTION            = 117975,
    SPELL_EXPELLED_CORRUPTION         = 117943,
    SPELL_EXPELLED_CORRUPTION_TRIGGER = 117955,

    /* Elder Regail */
    SPELL_LIGHTNING_BOLT              = 117187,
    SPELL_LIGHTNING_PRISON            = 122874,
    SPELL_LIGHTNING_PRISON_TRIGGER    = 111850,
    SPELL_LIGHTNING_STORM             = 118077,
    SPELL_LIGHTNING_STORM_VISUAL_1    = 118064,
    SPELL_LIGHTNING_STORM_VISUAL_2    = 118040,
    SPELL_LIGHTNING_STORM_VISUAL_3    = 118053,
    SPELL_LIGHTNING_STORM_VISUAL_4    = 118054,
    SPELL_LIGHTNING_STORM_VISUAL_5    = 118055,
    SPELL_LIGHTNING_STORM_DAMAGE_1    = 118003,
    SPELL_LIGHTNING_STORM_DAMAGE_2    = 118004,
    SPELL_LIGHTNING_STORM_DAMAGE_3    = 118005,
    SPELL_LIGHTNING_STORM_DAMAGE_4    = 118007,
    SPELL_LIGHTNING_STORM_DAMAGE_5    = 118008,

    /* Elder Asani */
    SPELL_WATER_BOLT                  = 118312,
    SPELL_CLEANSING_WATERS            = 117309,
    SPELL_CLEANSING_WATERS_VISUAL     = 117250,
    SPELL_CLEANSING_WATERS_TRIGGER_1  = 117268, // First triggered spell
    SPELL_CLEANSING_WATERS_TRIGGER_2  = 117283, // Last triggered spell that apply buff
    SPELL_CORRUPTED_WATERS            = 117227,
    SPELL_CORRUPTED_WATERS_TRIGGER    = 117217,
    SPELL_CORRUPTED_WATERS_BUFF       = 117230,
    SPELL_PURIFIED                    = 117235,

    /* Shared Spells */
    SPELL_BERSERK                     = 26662,
    SPELL_SHA_MASK                    = 118221,
    SPELL_SHA_CORRUPTION              = 117052,
    SPELL_OVERWHELMING_CORRUPTION     = 117351,
};

enum Texts
{
    /* Protector Kaolan */
    SAY_KAOLAN_DEATH            = 0,
    SAY_KAOLAN_SHA_DOSE_1       = 1,
    SAY_KAOLAN_EXPEL_CORRUPTION = 2,
    SAY_KAOLAN_SHA_DOSE_2       = 3,
    SAY_KAOLAN_SLAY_1           = 4,
    SAY_KAOLAN_SLAY_2           = 5,

    /* Elder Regail */
    SAY_REGAIL_AGGRO            = 0,
    SAY_REGAIL_DEATH            = 1,
    SAY_REGAIL_SHA_DOSE_1       = 2,
    SAY_REGAIL_SHA_DOSE_2       = 3,
    SAY_REGAIL_LIGHTNING_STORM  = 4,
    SAY_REGAIL_SLAY_1           = 5,
    SAY_REGAIL_SLAY_2           = 6,

    /* Elder Asani */
    SAY_ASANI_DEATH             = 0,
    SAY_ASANI_SHA_DOSE_1        = 1,
    SAY_ASANI_CORRUPTED_WATERS  = 2,
    SAY_ASANI_SHA_DOSE_2        = 3,
    SAY_ASANI_SLAY_1            = 4,
    SAY_ASANI_SLAY_2            = 5,
};

enum Events
{
    /* Protector Kaolan */
    EVENT_TOUCH_OF_SHA               = 1,
    EVENT_DEFILED_GROUND             = 2,
    EVENT_EXPEL_CORRUPTION           = 3,

    /* Elder Regail */
    EVENT_LIGHTNING_BOLT             = 1,
    EVENT_LIGHTNING_PRISON           = 2,
    EVENT_LIGHTNING_STORM            = 3,

    /* Elder Asani */
    EVENT_WATER_BOLT                 = 1,
    EVENT_CLEANSING_WATERS           = 2,
    EVENT_CORRUPTED_WATERS           = 3,

    /* Cleansing Waters */
    EVENT_CLEANSING_WATERS_TRIGGER   = 1,

    /* Shared events */
    EVENT_BERSERK                    = 4,
};

enum Npcs
{
    NPC_CORRUPTED_WATERS      = 60621,
};

enum Phases
{
    PHASE_NULL,
    PHASE_FIRST_SHA_CORRUPTION_DOSE,
    PHASE_SECOND_SHA_CORRUPTION_DOSE
};

class TouchOfShaTargetSelector : public std::unary_function<Unit*, bool>
{
    public:
        TouchOfShaTargetSelector(UnitAI* ai) : _ai(ai) { }

    bool operator()(Unit* unit) const
    {
        if (unit->GetTypeId() != TYPEID_PLAYER)
            return false;

        if (unit->HasAura(SPELL_TOUCH_OF_SHA))
            return false;

        return true;
    }

    private:
        UnitAI* _ai;
};

class boss_protector_kaolan : public CreatureScript
{
public:
    boss_protector_kaolan() : CreatureScript("boss_protector_kaolan") { }

    struct boss_protector_kaolanAI : public ScriptedAI
    {
        boss_protector_kaolanAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        SummonList summons;
        bool fivePct;

        void Reset() override
        {
            events.Reset();
            events.SetPhase(PHASE_NULL);

            summons.DespawnAll();

            fivePct = false;

            if (me->HasAura(SPELL_SHA_CORRUPTION))
                me->RemoveAurasDueToSpell(SPELL_SHA_CORRUPTION);

            if (!me->HasAura(SPELL_SHA_MASK))
                me->CastSpell(me, SPELL_SHA_MASK);

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            if (instance)
            {
                if (Creature* regail = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_REGAIL)))
                    if (regail->isDead())
                        regail->Respawn();

                if (Creature* asani = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_ASANI)))
                    if (asani->isDead())
                        asani->Respawn();

                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOUCH_OF_SHA);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->CastSpell(me, SPELL_SHA_CORRUPTION);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            
            if (instance)
            {
                if (Creature* regail = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_REGAIL)))
                    if (Creature* asani = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_ASANI)))
                    {
                        if (regail->IsAlive())
                            regail->SetHealth(regail->GetMaxHealth());

                        if (asani->IsAlive())
                            asani->SetHealth(asani->GetMaxHealth());

                        if (regail->isDead() && asani->isDead())
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }

                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOUCH_OF_SHA);
            }

            summons.DespawnAll();
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(RAND(SAY_KAOLAN_SLAY_1, SAY_KAOLAN_SLAY_2));
        }

        void JustSummoned(Creature* summoned) override
        {
            summons.Summon(summoned);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            summons.Despawn(summon);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (instance)
            {
                if (Creature* regail = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_REGAIL)))
                    if (!regail->IsInCombat())
                        regail->SetInCombatWithZone();

                if (Creature* asani = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_ASANI)))
                    if (!asani->IsInCombat())
                        asani->SetInCombatWithZone();

                if (!me->IsInCombat())
                    me->SetInCombatWithZone();
            }

            events.ScheduleEvent(EVENT_TOUCH_OF_SHA, 40*IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_BERSERK, 8*MINUTE*IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (instance)
            {
                if (Creature* regail = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_REGAIL)))
                    if (!regail->IsInCombat() && regail->IsAlive())
                        regail->SetInCombatWithZone();

                if (Creature* asani = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_ASANI)))
                    if (!asani->IsInCombat() && asani->IsAlive())
                        asani->SetInCombatWithZone();
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            if (HealthBelowPct(5) && !fivePct)
            {
                Talk(SAY_KAOLAN_DEATH);
                fivePct = true;
            }

            if (instance)
            {
                if (Aura* corruption = me->GetAura(SPELL_SHA_CORRUPTION))
                    if (corruption->GetStackAmount() == 1 && !events.IsInPhase(PHASE_FIRST_SHA_CORRUPTION_DOSE))
                    {
                        if (Creature* asani = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_ASANI)))
                            if (asani->isDead())
                                Talk(SAY_KAOLAN_SHA_DOSE_1);

                        events.ScheduleEvent(EVENT_DEFILED_GROUND, 5*IN_MILLISECONDS);
                        events.SetPhase(PHASE_FIRST_SHA_CORRUPTION_DOSE);
                    }
                    else if (corruption->GetStackAmount() == 2 && !events.IsInPhase(PHASE_SECOND_SHA_CORRUPTION_DOSE))
                    {
                        Talk(SAY_KAOLAN_SHA_DOSE_2);
                        events.ScheduleEvent(EVENT_EXPEL_CORRUPTION, 5*IN_MILLISECONDS);
                        events.SetPhase(PHASE_SECOND_SHA_CORRUPTION_DOSE);
                    }
            }
            
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TOUCH_OF_SHA:
                    {
                        std::list<Unit*> targets;
                        SelectTargetList(targets, TouchOfShaTargetSelector(me->AI()), 1, SELECT_TARGET_RANDOM);

                        if (targets.empty())
                        {
                            events.CancelEvent(EVENT_TOUCH_OF_SHA);
                            break;
                        }

                        for (std::list<Unit*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        {
                            Unit* target = *itr;
                            me->CastSpell(target, SPELL_TOUCH_OF_SHA);
                        }

                        events.ScheduleEvent(EVENT_TOUCH_OF_SHA, 30*IN_MILLISECONDS);
                        break;
                    }

                    case EVENT_DEFILED_GROUND:
                        me->CastSpell(me->GetVictim(), SPELL_DEFILED_GROUND_SUMMON);
                        
                        events.ScheduleEvent(EVENT_DEFILED_GROUND, 16*IN_MILLISECONDS);
                        break;

                    case EVENT_EXPEL_CORRUPTION:
                        me->CastSpell(me->GetVictim(), SPELL_EXPEL_CORRUPTION);
                        Talk(SAY_KAOLAN_EXPEL_CORRUPTION);

                        events.ScheduleEvent(EVENT_EXPEL_CORRUPTION, 42*IN_MILLISECONDS);
                        break;

                    case EVENT_BERSERK:
                        me->CastSpell(me, SPELL_BERSERK);

                        events.CancelEvent(EVENT_BERSERK);
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
        return new boss_protector_kaolanAI(creature);
    }
};

class boss_elder_regail : public CreatureScript
{
public:
    boss_elder_regail() : CreatureScript("boss_elder_regail") { }

    struct boss_elder_regailAI : public ScriptedAI
    {
        boss_elder_regailAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        int32 lightningStorms;
        bool fivePct;

        void Reset() override
        {
            events.Reset();
            events.SetPhase(PHASE_NULL);
            
            lightningStorms = 0;
            fivePct = false;

            if (me->HasAura(SPELL_SHA_CORRUPTION))
                me->RemoveAurasDueToSpell(SPELL_SHA_CORRUPTION);

            if (me->HasAura(SPELL_OVERWHELMING_CORRUPTION))
                me->RemoveAurasDueToSpell(SPELL_OVERWHELMING_CORRUPTION);

            if (!me->HasAura(SPELL_SHA_MASK))
                me->CastSpell(me, SPELL_SHA_MASK);

            if (instance)
            {
                if (Creature* kaolan = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_KAOLAN)))
                    if (kaolan->isDead())
                        kaolan->Respawn();

                if (Creature* asani = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_ASANI)))
                    if (asani->isDead())
                        asani->Respawn();
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->CastSpell(me, SPELL_SHA_CORRUPTION);

            if (instance)
            {
                if (Creature* kaolan = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_KAOLAN)))
                    if (Creature* asani = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_ASANI)))
                    {
                        if (kaolan->IsAlive())
                            kaolan->SetHealth(kaolan->GetMaxHealth());

                        if (asani->IsAlive())
                            asani->SetHealth(asani->GetMaxHealth());

                        if (kaolan->isDead() && asani->isDead())
                            kaolan->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }
            }
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(RAND(SAY_REGAIL_SLAY_1, SAY_REGAIL_SLAY_2));
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_REGAIL_AGGRO);
            
            if (instance)
            {
                if (Creature* kaolan = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_KAOLAN)))
                    if (!kaolan->IsInCombat())
                        kaolan->SetInCombatWithZone();

                if (Creature* asani = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_ASANI)))
                    if (!asani->IsInCombat())
                        asani->SetInCombatWithZone();

                if (!me->IsInCombat())
                    me->SetInCombatWithZone();
            }

            events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 0);
            events.ScheduleEvent(EVENT_LIGHTNING_PRISON, 17*IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_BERSERK, 8*MINUTE*IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (instance)
            {
                if (Creature* kaolan = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_KAOLAN)))
                    if (!kaolan->IsInCombat() && kaolan->IsAlive())
                        kaolan->SetInCombatWithZone();

                if (Creature* asani = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_ASANI)))
                    if (!asani->IsInCombat() && asani->IsAlive())
                        asani->SetInCombatWithZone();
            }

            events.Update(diff);

            if (HealthBelowPct(5) && !fivePct)
            {
                Talk(SAY_REGAIL_DEATH);
                fivePct = true;
            }

            if (instance)
                if (Aura* corruption = me->GetAura(SPELL_SHA_CORRUPTION))
                    if (corruption->GetStackAmount() == 1 && !events.IsInPhase(PHASE_FIRST_SHA_CORRUPTION_DOSE))
                    {
                        if (Creature* kaolan = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_KAOLAN)))
                            if (kaolan->isDead())
                                Talk(SAY_REGAIL_SHA_DOSE_1);

                        events.CancelEvent(EVENT_LIGHTNING_PRISON);
                        events.ScheduleEvent(EVENT_LIGHTNING_PRISON, 15*IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_LIGHTNING_STORM, 28*IN_MILLISECONDS);
                        events.SetPhase(PHASE_FIRST_SHA_CORRUPTION_DOSE);
                    }
                    else if (corruption->GetStackAmount() == 2 && !events.IsInPhase(PHASE_SECOND_SHA_CORRUPTION_DOSE))
                    {
                        Talk(SAY_REGAIL_SHA_DOSE_1);
                        me->CastSpell(me, SPELL_OVERWHELMING_CORRUPTION);
                        events.SetPhase(PHASE_SECOND_SHA_CORRUPTION_DOSE);
                    }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_LIGHTNING_BOLT:
                    {
                        if (!me->HasUnitState(UNIT_STATE_CASTING))
                            me->CastSpell(me->GetVictim(), SPELL_LIGHTNING_BOLT);

                        uint32 spellTimer = me->HasAura(SPELL_CORRUPTED_WATERS_BUFF) ? 2*IN_MILLISECONDS : 3*IN_MILLISECONDS;
                        events.ScheduleEvent(EVENT_LIGHTNING_BOLT, spellTimer);
                        break;
                    }

                    case EVENT_LIGHTNING_PRISON:
                    {
                        me->CastSpell(me, SPELL_LIGHTNING_PRISON_TRIGGER);
                        me->CastSpell(me, SPELL_LIGHTNING_PRISON);

                        events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 2*IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_LIGHTNING_PRISON, 27*IN_MILLISECONDS);
                        break;
                    }

                    case EVENT_LIGHTNING_STORM:
                    {
                        if (lightningStorms == 0)
                        {
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                            me->CastSpell(me, SPELL_LIGHTNING_STORM);
                            events.CancelEvent(EVENT_LIGHTNING_PRISON);
                            events.ScheduleEvent(EVENT_LIGHTNING_STORM, 2*IN_MILLISECONDS);
                            lightningStorms++;
                        }

                        else if (lightningStorms == 1)
                        {
                            Talk(SAY_REGAIL_LIGHTNING_STORM);
                            me->CastSpell(me, SPELL_LIGHTNING_STORM_VISUAL_1);
                            events.ScheduleEvent(EVENT_LIGHTNING_STORM, 2*IN_MILLISECONDS);
                            lightningStorms++;
                        }

                        else if (lightningStorms == 2)
                        {
                            me->CastSpell(me, SPELL_LIGHTNING_STORM_DAMAGE_1);
                            events.ScheduleEvent(EVENT_LIGHTNING_STORM, 600);
                            lightningStorms++;
                        }

                        else if (lightningStorms == 3)
                        {
                            me->CastSpell(me, SPELL_LIGHTNING_STORM_VISUAL_2);
                            events.ScheduleEvent(EVENT_LIGHTNING_STORM, 2*IN_MILLISECONDS);
                            lightningStorms++;
                        }

                        else if (lightningStorms == 4)
                        {
                            me->CastSpell(me, SPELL_LIGHTNING_STORM_DAMAGE_2);
                            events.ScheduleEvent(EVENT_LIGHTNING_STORM, 600);
                            lightningStorms++;
                        }

                        else if (lightningStorms == 5)
                        {
                            me->CastSpell(me, SPELL_LIGHTNING_STORM_VISUAL_3);
                            events.ScheduleEvent(EVENT_LIGHTNING_STORM, 2*IN_MILLISECONDS);
                            lightningStorms++;
                        }

                        else if (lightningStorms == 6)
                        {
                            me->CastSpell(me, SPELL_LIGHTNING_STORM_DAMAGE_3);
                            events.ScheduleEvent(EVENT_LIGHTNING_STORM, 600);
                            lightningStorms++;
                        }

                        else if (lightningStorms == 7)
                        {
                            me->CastSpell(me, SPELL_LIGHTNING_STORM_VISUAL_4);
                            events.ScheduleEvent(EVENT_LIGHTNING_STORM, 2*IN_MILLISECONDS);
                            lightningStorms++;
                        }

                        else if (lightningStorms == 8)
                        {
                            me->CastSpell(me, SPELL_LIGHTNING_STORM_DAMAGE_4);
                            events.ScheduleEvent(EVENT_LIGHTNING_STORM, 600);
                            lightningStorms++;
                        }

                        else if (lightningStorms == 9)
                        {
                            me->CastSpell(me, SPELL_LIGHTNING_STORM_VISUAL_5);
                            events.ScheduleEvent(EVENT_LIGHTNING_STORM, 2*IN_MILLISECONDS);
                            lightningStorms++;
                        }

                        else if (lightningStorms == 10)
                        { 
                            me->CastSpell(me, SPELL_LIGHTNING_STORM_DAMAGE_5);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                            events.ScheduleEvent(EVENT_LIGHTNING_PRISON, 3*IN_MILLISECONDS);
                            events.ScheduleEvent(EVENT_LIGHTNING_STORM, 29*IN_MILLISECONDS);
                            lightningStorms = 0;
                        }
                        break;
                    }

                    case EVENT_BERSERK:
                        me->CastSpell(me, SPELL_BERSERK);

                        events.CancelEvent(EVENT_BERSERK);
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
        return new boss_elder_regailAI(creature);
    }
};

class boss_elder_asani : public CreatureScript
{
public:
    boss_elder_asani() : CreatureScript("boss_elder_asani") { }

    struct boss_elder_asaniAI : public ScriptedAI
    {
        boss_elder_asaniAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        SummonList summons;
        bool fivePct;

        void Reset() override
        {
            events.Reset();
            events.SetPhase(PHASE_NULL);

            summons.DespawnAll();

            fivePct = false;

            if (me->HasAura(SPELL_SHA_CORRUPTION))
                me->RemoveAurasDueToSpell(SPELL_SHA_CORRUPTION);

            if (me->HasAura(SPELL_OVERWHELMING_CORRUPTION))
                me->RemoveAurasDueToSpell(SPELL_OVERWHELMING_CORRUPTION);

            if (!me->HasAura(SPELL_SHA_MASK))
                me->CastSpell(me, SPELL_SHA_MASK);

            if (instance)
            {
                if (Creature* kaolan = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_KAOLAN)))
                    if (kaolan->isDead())
                        kaolan->Respawn();

                if (Creature* regail = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_REGAIL)))
                    if (regail->isDead())
                        regail->Respawn();
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_ASANI_DEATH);

            me->CastSpell(me, SPELL_SHA_CORRUPTION);

            if (instance)
            {
                if (Creature* kaolan = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_KAOLAN)))
                    if (Creature* regail = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_REGAIL)))
                    {
                        if (kaolan->IsAlive())
                            kaolan->SetHealth(kaolan->GetMaxHealth());

                        if (regail->IsAlive())
                            regail->SetHealth(regail->GetMaxHealth());

                        if (kaolan->isDead() && regail->isDead())
                            kaolan->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }

                if (Creature* waters = me->FindNearestCreature(NPC_CORRUPTED_WATERS, 99999.0f, true))
                    waters->DespawnOrUnsummon();
            }

            summons.DespawnAll();
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(RAND(SAY_ASANI_SLAY_1, SAY_ASANI_SLAY_2));
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (instance)
            {
                if (Creature* kaolan = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_KAOLAN)))
                    if (!kaolan->IsInCombat())
                        kaolan->SetInCombatWithZone();

                if (Creature* regail = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_REGAIL)))
                    if (!regail->IsInCombat())
                        regail->SetInCombatWithZone();

                if (!me->IsInCombat())
                    me->SetInCombatWithZone();
            }

            events.ScheduleEvent(EVENT_WATER_BOLT, 0);
            events.ScheduleEvent(EVENT_CLEANSING_WATERS, 12*IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_BERSERK, 8*MINUTE*IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (instance)
            {
                if (Creature* kaolan = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_KAOLAN)))
                    if (!kaolan->IsInCombat() && kaolan->IsAlive())
                        kaolan->SetInCombatWithZone();

                if (Creature* regail = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_REGAIL)))
                    if (!regail->IsInCombat() && regail->IsAlive())
                        regail->SetInCombatWithZone();
            }

            events.Update(diff);

            if (HealthBelowPct(5) && !fivePct)
            {
                Talk(SAY_ASANI_DEATH);
                fivePct = true;
            }

            if (instance)
            {
                if (Aura* corruption = me->GetAura(SPELL_SHA_CORRUPTION))
                    if (corruption->GetStackAmount() == 1 && !events.IsInPhase(PHASE_FIRST_SHA_CORRUPTION_DOSE))
                    {
                        if (Creature* regail = ObjectAccessor::GetCreature(*me, instance->GetObjectGuid(DATA_REGAIL)))
                            if (regail->isDead())
                                Talk(SAY_ASANI_SHA_DOSE_1);

                        events.ScheduleEvent(EVENT_CORRUPTED_WATERS, 12*IN_MILLISECONDS);
                        events.SetPhase(PHASE_FIRST_SHA_CORRUPTION_DOSE);
                    }
                    else if (corruption->GetStackAmount() == 2 && !events.IsInPhase(PHASE_SECOND_SHA_CORRUPTION_DOSE))
                    {
                        Talk(SAY_ASANI_SHA_DOSE_2);
                        me->CastSpell(me, SPELL_OVERWHELMING_CORRUPTION);
                        events.SetPhase(PHASE_SECOND_SHA_CORRUPTION_DOSE);
                    }
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_WATER_BOLT:
                    {
                        if (!me->HasUnitState(UNIT_STATE_CASTING))
                            me->CastSpell(me->GetVictim(), SPELL_WATER_BOLT);

                        uint32 spellTimer = me->HasAura(SPELL_CORRUPTED_WATERS_BUFF) ? 2*IN_MILLISECONDS : 3*IN_MILLISECONDS;
                        events.ScheduleEvent(EVENT_WATER_BOLT, spellTimer);
                        break;
                    }

                    case EVENT_CLEANSING_WATERS:
                        me->CastSpell(me, SPELL_CLEANSING_WATERS);

                        events.ScheduleEvent(EVENT_CLEANSING_WATERS, 35*IN_MILLISECONDS);
                        break;

                    case EVENT_CORRUPTED_WATERS:
                        if (!me->FindNearestCreature(NPC_CORRUPTED_WATERS, 99999.0f)) // No more than one
                        {
                            Talk(SAY_ASANI_CORRUPTED_WATERS);
                            me->CastSpell(me, SPELL_CORRUPTED_WATERS);
                        }

                        events.ScheduleEvent(EVENT_CORRUPTED_WATERS, 45*IN_MILLISECONDS);
                        break;

                    case EVENT_BERSERK:
                        me->CastSpell(me, SPELL_BERSERK);

                        events.CancelEvent(EVENT_BERSERK);
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
        return new boss_elder_asaniAI(creature);
    }
};

// NpcID : 60906
class npc_defiled_ground : public CreatureScript
{
public:
    npc_defiled_ground() : CreatureScript("npc_defiled_ground")
    {
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_defiled_groundAI(creature);
    }

    struct npc_defiled_groundAI : public ScriptedAI
    {
        npc_defiled_groundAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset() override
        {
            if (instance)
            {
                me->setFaction(14);

                if (!me->IsInCombat())
                    me->SetInCombatWithZone();

                me->SetDisplayId(11686); // Invisible
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                me->CastSpell(me, SPELL_DEFILED_GROUND);
            }
        }
    };
};

// NpcID : 60886
class npc_expelled_corruption : public CreatureScript
{
public:
    npc_expelled_corruption() : CreatureScript("npc_expelled_corruption")
    {
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_expelled_corruptionAI(creature);
    }

    struct npc_expelled_corruptionAI : public ScriptedAI
    {
        npc_expelled_corruptionAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset() override
        {
            if (instance)
            {
                me->setFaction(14);

                if (!me->IsInCombat())
                    me->SetInCombatWithZone();

                me->SetDisplayId(11686); // Invisible
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                me->CastSpell(me, SPELL_EXPELLED_CORRUPTION);
            }
        }
    };
};

// NpcID : 60646
class npc_cleansing_waters : public CreatureScript
{
public:
    npc_cleansing_waters() : CreatureScript("npc_cleansing_waters")
    {
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_cleansing_watersAI(creature);
    }

    struct npc_cleansing_watersAI : public ScriptedAI
    {
        npc_cleansing_watersAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void Reset() override
        {
            events.Reset();

            me->SetDisplayId(11686); // Invisible
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            me->CastSpell(me, SPELL_CLEANSING_WATERS_TRIGGER_1);
            me->CastSpell(me, SPELL_CLEANSING_WATERS_VISUAL);

            events.ScheduleEvent(EVENT_CLEANSING_WATERS_TRIGGER, 8*IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CLEANSING_WATERS_TRIGGER:
                        me->CastSpell(me, SPELL_CLEANSING_WATERS_TRIGGER_2);
                        me->DespawnOrUnsummon(30*IN_MILLISECONDS);

                        events.CancelEvent(EVENT_CLEANSING_WATERS_TRIGGER);
                        break;

                    default:
                        break;
                }
            }
        }
    };
};

// NpcID : 60621
class npc_corrupted_waters : public CreatureScript
{
public:
    npc_corrupted_waters() : CreatureScript("npc_corrupted_waters")
    {
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_corrupted_watersAI(creature);
    }

    struct npc_corrupted_watersAI : public ScriptedAI
    {
        npc_corrupted_watersAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset() override
        {
            if (instance)
            {
                me->setFaction(14);

                if (!me->IsInCombat())
                    me->SetInCombatWithZone();

                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);

                me->CastSpell(me, SPELL_CORRUPTED_WATERS_TRIGGER);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance)
            {
                me->CastSpell(me, SPELL_PURIFIED);
                me->DespawnOrUnsummon(5*IN_MILLISECONDS);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (me->HasAura(SPELL_CLEANSING_WATERS_TRIGGER_2))
                me->RemoveAurasDueToSpell(SPELL_CLEANSING_WATERS_TRIGGER_2);
        }
    };
};

// SpellID : 117955
class spell_expelled_corruption : public SpellScriptLoader
{
public:
    spell_expelled_corruption() : SpellScriptLoader("spell_expelled_corruption")
    {
    }

    class spell_expelled_corruption_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_expelled_corruption_SpellScript);

        void HandleEffect(SpellEffIndex /*effIndex*/)
        {
            if (!GetHitUnit())
                return;

            int32 bp = GetEffectValue();
            int32 dmg = bp;
            int32 newBp = bp*0.25f; // min damage = 1/4 bp
            int32 lastBp = bp*0.75f;
            float radius = 30.0f; // EFFECT_RADIUS_30_YARDS

            if (Unit* caster = GetCaster())
            {
                float dist = caster->GetDistance2d(GetHitUnit()->GetPositionX(), GetHitUnit()->GetPositionY());
                dmg = newBp + float(1.0f - dist / radius) * lastBp;
            }
                
            SetHitDamage(dmg);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_expelled_corruption_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_expelled_corruption_SpellScript();
    }
};
// Lightning Prison #111850#
class spell_lightning_prison : public SpellScriptLoader
{
public:
    spell_lightning_prison() : SpellScriptLoader("spell_lightning_prison") { }
   
    class spell_lightning_prison_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_lightning_prison_SpellScript)
       
        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (Unit *pCaster = GetCaster())
                if (Map *pMap = pCaster->GetMap())
                    switch (pMap->GetDifficultyID())
                    {
                        // Resize to 2 target in 10 man
                        case DIFFICULTY_10_N:
                        case DIFFICULTY_10_HC:
                            Trinity::Containers::RandomResizeList(targets, 2);
                            break;
                       
                        // Resize to 3 targets in 25 man
                        case DIFFICULTY_25_N:
                        case DIFFICULTY_25_HC:
                            Trinity::Containers::RandomResizeList(targets, 3);
                            break;

                        default:
                            break;
                    }
        }
       
        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_lightning_prison_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };
   
    SpellScript *GetSpellScript() const
    {
        return new spell_lightning_prison_SpellScript();
    }
};

void AddSC_boss_protectors_of_the_endless()
{
    new boss_protector_kaolan();
    new boss_elder_regail();
    new boss_elder_asani();
    new npc_defiled_ground();
    new npc_expelled_corruption();
    new npc_cleansing_waters();
    new npc_corrupted_waters();
    new spell_expelled_corruption();
    new spell_lightning_prison();
}
