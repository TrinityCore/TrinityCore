#include "instance_skyreach.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

class mob_skyreach_arcanologist : public CreatureScript
{
public:
    // Entry: 76376
    mob_skyreach_arcanologist()  : CreatureScript("mob_skyreach_arcanologist") {  }

    enum class Spells : uint32
    {
        SOLAR_DETONATION = 160288, // 7 seconds.
        SOLAR_STORM = 159215, // 12 to 15 seconds.
        SOLAR_STORM_1 = 159216,
        SOLAR_STORM_2 = 159218,
        SOLAR_STORM_3 = 159221,
        SOLAR_STORM_DMG = 159226,
    };

    enum class Events : uint32
    {
        SOLAR_DETONATION = 1,
        SOLAR_STORM = 2,
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_skyreach_arcanologistAI(creature);
    }

    struct mob_skyreach_arcanologistAI : public ScriptedAI
    {
        mob_skyreach_arcanologistAI(Creature* creature) : ScriptedAI(creature),
            m_instance(creature->GetInstanceScript()),
            m_events()
        {
        }

        void Reset() override
        {
            m_events.Reset();

            if (m_instance)
                m_instance->SetData(Data::SkyreachArcanologistReset, 0);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (m_instance)
                m_instance->SetData(Data::SkyreachArcanologistIsDead, 0);

            if (IsHeroic())
                m_instance->DoCompleteAchievement(uint32(Achievements::MagnifyEnhance));
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            m_events.ScheduleEvent(uint32(Events::SOLAR_DETONATION), urand(2500, 7500));
            m_events.ScheduleEvent(uint32(Events::SOLAR_STORM), urand(5000, 10000));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            m_events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (m_events.ExecuteEvent())
            {
            case uint32(Events::SOLAR_DETONATION):
                m_events.ScheduleEvent(uint32(Events::SOLAR_DETONATION), urand(6500, 7500));
                if (Player* player = me->SelectRandomPlayerInRange(15.0f,true))
                    me->CastSpell(player, uint32(Spells::SOLAR_DETONATION));
                break;
            case uint32(Events::SOLAR_STORM):
                m_events.ScheduleEvent(uint32(Events::SOLAR_STORM), urand(12000, 15000));
                me->CastSpell(me->GetVictim(), uint32(Spells::SOLAR_STORM));
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }

        InstanceScript* m_instance;
        EventMap m_events;
    };
};

class boss_araknath : public CreatureScript
{
public:
    // Entry: 76141
    boss_araknath()   : CreatureScript("boss_araknath")  {   }

    enum class Spells : uint32
    {
        MELEE = 154121, // Every 2 seconds.
        SMASH = 154110, // Every 6 to 7 seconds.
        BURST = 154135, // Every 23 seconds.
        BREATH_OF_SINDRAGOSA = 155168,
        SUBMERGE = 154164,
        SUBMERGED = 154163,
    };

    enum class Events : uint32
    {
        SHUT_DOORS = 1,
        MELEE = 2,
        SMASH = 3,
        BURST = 4,
        ENERGIZE_START = 5,
        ENERGIZE_STOP = 6,
        Reset = 7
    };

    ScriptedAI* GetAI(Creature* creature) const
    {
        return new boss_araknathAI(creature);
    }

    struct boss_araknathAI : public BossAI
    {
        boss_araknathAI(Creature* creature) : BossAI(creature, Data::Araknath),
            m_Initialized(false),
            m_InitializationTimer(0)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SNARE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
        }

        void Reset() override
        {
            if (!me->IsAlive())
                return;

            me->ResetLootMode();
            events.Reset();
            summons.DespawnAll();

            me->RemoveAllAuras();
            me->CombatStop();
            me->AddAura(uint32(Spells::SUBMERGED), me);
            me->SetReactState(REACT_PASSIVE);

            events.ScheduleEvent(uint32(Events::Reset), 100);

            // We need time so that all the mobs are spawned.
            m_InitializationTimer = 500;
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();

            if (instance)
                instance->SetData(Data::AraknathSolarConstructorActivation, false);
        }

        void KilledUnit(Unit* /*p_Victim*/)
        {
        }

        void JustReachedHome()
        {
            _JustReachedHome();

            if (instance)
            {
                instance->SetBossState(Data::Araknath, FAIL);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            _EnterCombat();
            events.ScheduleEvent(uint32(Events::MELEE), 2000);
            events.ScheduleEvent(uint32(Events::SMASH), urand(5500, 7000));
            events.ScheduleEvent(uint32(Events::BURST), urand(21500, 23000));
            events.ScheduleEvent(uint32(Events::ENERGIZE_START), 12000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!m_Initialized && m_InitializationTimer <= 0)
            {
                m_Initialized = true;

                if (instance && (instance->GetBossState(Data::Araknath) == EncounterState::SPECIAL || instance->GetBossState(Data::Araknath) == EncounterState::IN_PROGRESS))
                    instance->SetData(Data::SkyreachArcanologistIsDead, 0);
            }
            else
                m_InitializationTimer -= diff;

            if (me->GetDistance(me->GetHomePosition()) > 23.0f && !me->IsInEvadeMode())
                EnterEvadeMode();

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case uint32(Events::MELEE):
                events.ScheduleEvent(uint32(Events::MELEE), 2000);
                me->CastSpell(me->GetVictim(), uint32(Spells::MELEE));
                break;
            case uint32(Events::SMASH):
                events.ScheduleEvent(uint32(Events::SMASH), urand(5500, 7000));
                me->CastSpell(me, uint32(Spells::SMASH));

                events.CancelEvent(uint32(Events::MELEE));
                events.ScheduleEvent(uint32(Events::MELEE), 2000);
                break;
            case uint32(Events::BURST):
                events.ScheduleEvent(uint32(Events::BURST), urand(21500, 23000));
                me->CastSpell(me->GetVictim(), uint32(Spells::BURST));
                break;
            case uint32(Events::ENERGIZE_START):
                events.ScheduleEvent(uint32(Events::ENERGIZE_STOP), 12000);

                if (instance)
                    instance->SetData(Data::AraknathSolarConstructorActivation, true);
                break;
            case uint32(Events::ENERGIZE_STOP):
                events.ScheduleEvent(uint32(Events::ENERGIZE_START), 3000);

                if (instance)
                    instance->SetData(Data::AraknathSolarConstructorActivation, false);
                break;
            default:
                break;
            }
        }

        bool m_Initialized;
        int32 m_InitializationTimer;
    };
};

void AddSC_boss_araknath()
{
    new mob_skyreach_arcanologist();
    new boss_araknath();
}
