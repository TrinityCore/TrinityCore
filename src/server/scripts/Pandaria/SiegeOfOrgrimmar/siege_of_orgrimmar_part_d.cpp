#include "siege_of_orgrimmar.hpp"

// TODO:
// script some spells for NPC_GATECRUSHER_SAVAH 73670
// script all spells for NPC_WINDREAVER_TARRATH 73667
// script all spells for NPC_KLAXXI_SKIRMISHER 73012

enum Adds
{
    // Before the paragons
    NPC_GATECRUSHER_SAVAH       = 73670,
    NPC_WINDREAVER_TARRATH      = 73667,
    NPC_GRANDMASTER_ALCHEMIST_KIXEN = 73696,
    NPC_KORTHIK_HONOR_GUARD     = 72954,
    NPC_KLAXXI_SKIRMISHER       = 73012,
    NPC_SRATHIK_AMBER_MASTER    = 72929,
    NPC_RESONATING_AMBER        = 72966,
    NPC_KOVOK                   = 72927,

    // Before Garrosh
    NPC_KORKRON_REAPER          = 73414,
    NPC_ICHOR_OF_YSHAARJ        = 73415,
    NPC_HARBRINGER_OF_YSHAARJ   = 73452,
    NPC_MANIFESTATION           = 73454,
};

enum Spells
{
    // Gatecrusher Sav'ah
    SPELL_ENRAGE                    = 61369,
    SPELL_BRUTAL_HEMORRHAGE         = 148375,
    SPELL_PREMEDITATED_SLAUGHTER_AOE    = 148397,
    SPELL_PREMEDITATED_SLAUGHTER_1  = 148391, // triggered after 148397
    SPELL_PREMEDITATED_SLAUGHTER_SCRIPT = 148423,
    SPELL_PREMEDITATED_SLAUGHTER_2  = 148426, // triggered after 148423

    // Windreaver Tar'rath
    SPELL_WINDREAVER_TECHNIQUE      = 148370,
    SPELL_WINDREAVER_TECHNIQUE_DMG  = 148371,

    // Grand Master Alchemist Ki'xen
    SPELL_ALCHEMICAL_MASTERY        = 148456,

    // Kor'thik Honor Guard
    SPELL_PIERCE                    = 146556,
    SPELL_FRENZIED_ASSAULT_AOE      = 146531, // target players
    SPELL_FRENZIED_ASSAULT_JUMP     = 146527,
    SPELL_FRENZIED_ASSAULT          = 146536,
    SPELL_FRENZIED_ASSAULT_DMG      = 146535,

    // Klaxxi Skirmisher
    SPELL_FLY_BY_AOE                = 146687, // target players
    SPELL_FLY_BY_CHARGE_1           = 146693,
    SPELL_FLY_BY_SCRIPT_1           = 146699, // triggered by 146693
    SPELL_FLY_BY_AURA               = 146694,
    SPELL_FLY_BY_SCRIPT_2           = 146698,
    SPELL_FLY_BY_CHARGE_2           = 146700,
    SPELL_FLY_BY_REMOVE             = 146702, // removes 146694

    // Sra'thik Amber-Master
    SPELL_AMBER_BLAST               = 146511,
    SPELL_RESONATING_AMBER_AOE      = 146499, // target players
    SPELL_RESONATING_AMBER_SUMMON   = 146455,
    SPELL_RESONATING_AMBER_AURA     = 146454,
    SPELL_RESONATING_AMBER_DMG      = 146452,
    SPELL_RESONATING_AMBER_SCALE    = 146502, // triggered by 146501 (periodic)
    SPELL_AMBER_GROWTH              = 146501,

    // Kovok
    SPELL_GROUND_SLAM               = 146621,
    SPELL_MIGHTY_CLEAVE             = 146605,
    SPELL_POISON_BLAST              = 146606,

    // Kor'kron Reaper
    SPELL_CHARGE                    = 147640,
    SPELL_REAPING_WHIRLWIND         = 147642,
    SPELL_REAPER                    = 147644,

    // Ichor of Y'Shaarj
    SPELL_EMPOWERING_CORRUPTION     = 147564,

    // Harbringer of Y'Shaarj
    SPELL_GRASP_OF_YSHAARJ          = 147647,
    SPELL_GRASP_OF_YSHAARJ_SUMMON   = 147648,
    SPELL_YSHAARJ_TOUCHED           = 147553,

    // Manifestation
    SPELL_BOUND_YSHAARJ_POWER       = 147754,
};

class npc_siege_of_orgrimmar_gatecrusher_savah : public CreatureScript
{
    enum LocalEvents
    {
        EVENT_ENRAGE    = 1,
        EVENT_BRUTAL_HEMORRHAGE,
        EVENT_PREMEDITATED_SLAUGHTER,
    };

    enum LocalTimers
    {
        TIMER_ENRAGE                    = 4 * IN_MILLISECONDS,
        TIMER_BRUTAL_HEMORRHAGE_FIRST   = 8 * IN_MILLISECONDS,
        TIMER_BRUTAL_HEMORRHAGE         = 15 * IN_MILLISECONDS,
    };

    public:
        npc_siege_of_orgrimmar_gatecrusher_savah() : CreatureScript("npc_siege_of_orgrimmar_gatecrusher_savah") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_gatecrusher_savahAI(creature);
        }

        struct npc_siege_of_orgrimmar_gatecrusher_savahAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_gatecrusher_savahAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* who) override
            {
                events.ScheduleEvent(EVENT_ENRAGE, TIMER_ENRAGE);
                events.ScheduleEvent(EVENT_BRUTAL_HEMORRHAGE, TIMER_BRUTAL_HEMORRHAGE_FIRST);
            }

            void JustDied(Unit* killer) override
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_ENRAGE:
                        DoEnrage();
                        break;
                    case EVENT_BRUTAL_HEMORRHAGE:
                        DoBrutalHemorrhage();
                        events.ScheduleEvent(EVENT_BRUTAL_HEMORRHAGE, TIMER_BRUTAL_HEMORRHAGE);
                        break;
                }
            }

            void DoEnrage()
            {
                DoCast(me, SPELL_ENRAGE);
            }

            void DoBrutalHemorrhage()
            {
                DoCastVictim(SPELL_BRUTAL_HEMORRHAGE);
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_grandmaster_alchemist_kixen : public CreatureScript
{
    enum LocalEvents
    {
        EVENT_ALCHEMICAL_MASTERY    = 1,
    };

    enum LocalTimers
    {
        TIMER_ALCHEMICAL_MASTERY_FIRST  = 5 * IN_MILLISECONDS,
        TIMER_ALCHEMICAL_MASTERY        = 10 * IN_MILLISECONDS,
    };

    public:
        npc_siege_of_orgrimmar_grandmaster_alchemist_kixen() : CreatureScript("npc_siege_of_orgrimmar_grandmaster_alchemist_kixen") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_grandmaster_alchemist_kixenAI(creature);
        }

        struct npc_siege_of_orgrimmar_grandmaster_alchemist_kixenAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_grandmaster_alchemist_kixenAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* who) override
            {
                events.ScheduleEvent(EVENT_ALCHEMICAL_MASTERY, TIMER_ALCHEMICAL_MASTERY_FIRST);
            }

            void JustDied(Unit* killer) override
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_ALCHEMICAL_MASTERY:
                        DoAlchemicalMastery();
                        events.ScheduleEvent(EVENT_ALCHEMICAL_MASTERY, TIMER_ALCHEMICAL_MASTERY);
                        break;
                }
            }

            void DoAlchemicalMastery()
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                {
                    DoCast(target, SPELL_ALCHEMICAL_MASTERY);
                }
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_korthik_honor_guard : public CreatureScript
{
    enum LocalEvents
    {
        EVENT_PIERCE    = 1,
        EVENT_FRENZIED_ASSAULT,
    };

    enum LocalTimers
    {
        TIMER_PIERCE_FIRST              = 5 * IN_MILLISECONDS,
        TIMER_PIERCE                    = 15 * IN_MILLISECONDS,

        TIMER_FRENZIED_ASSAULT_FIRST    = 10 * IN_MILLISECONDS,
        TIMER_FRENZIED_ASSAULT          = 30 * IN_MILLISECONDS,
    };

    public:
        npc_siege_of_orgrimmar_korthik_honor_guard() : CreatureScript("npc_siege_of_orgrimmar_korthik_honor_guard") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_korthik_honor_guardAI(creature);
        }

        struct npc_siege_of_orgrimmar_korthik_honor_guardAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_korthik_honor_guardAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* who) override
            {
                events.ScheduleEvent(EVENT_PIERCE, TIMER_PIERCE_FIRST);
                events.ScheduleEvent(EVENT_FRENZIED_ASSAULT, TIMER_FRENZIED_ASSAULT_FIRST);
            }

            void JustDied(Unit* killer) override
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_PIERCE:
                        DoPierce();
                        events.ScheduleEvent(EVENT_PIERCE, TIMER_PIERCE);
                        break;
                    case EVENT_FRENZIED_ASSAULT:
                        DoFrenziedAssault();
                        events.ScheduleEvent(EVENT_FRENZIED_ASSAULT, TIMER_FRENZIED_ASSAULT);
                        break;
                }
            }

            void DoPierce()
            {
                DoCastVictim(SPELL_PIERCE);
            }

            void DoFrenziedAssault()
            {
                DoCastAOE(SPELL_FRENZIED_ASSAULT_AOE);
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_klaxxi_skirmisher : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_klaxxi_skirmisher() : CreatureScript("npc_siege_of_orgrimmar_klaxxi_skirmisher") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_klaxxi_skirmisherAI(creature);
        }

        struct npc_siege_of_orgrimmar_klaxxi_skirmisherAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_klaxxi_skirmisherAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
            }

            void JustDied(Unit* killer)
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_srathik_amber_master : public CreatureScript
{
    enum LocalEvents
    {
        EVENT_AMBER_BLAST   = 1,
        EVENT_RESONATING_AMBER,
    };

    enum LocalTimers
    {
        TIMER_AMBER_BLAST_FIRST         = 1 * IN_MILLISECONDS,
        TIMER_AMBER_BLAST               = 3 * IN_MILLISECONDS,

        TIMER_RESONATING_AMBER_FIRST    = 6 * IN_MILLISECONDS,
        TIMER_RESONATING_AMBER          = 16 * IN_MILLISECONDS,
    };

    public:
        npc_siege_of_orgrimmar_srathik_amber_master() : CreatureScript("npc_siege_of_orgrimmar_srathik_amber_master") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_srathik_amber_masterAI(creature);
        }

        struct npc_siege_of_orgrimmar_srathik_amber_masterAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_srathik_amber_masterAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                events.Reset();
                summons.DespawnAll();
            }

            void EnterCombat(Unit* who) override
            {
                events.ScheduleEvent(EVENT_AMBER_BLAST, TIMER_AMBER_BLAST_FIRST);
                events.ScheduleEvent(EVENT_RESONATING_AMBER, TIMER_RESONATING_AMBER_FIRST);
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);

                if (me->IsInCombat())
                    DoZoneInCombat(summon);

                if (summon->GetEntry() == NPC_RESONATING_AMBER)
                {
                    me->StopMoving();
                    me->GetMotionMaster()->MovementExpired(false);

                    DoAmberGrowth(summon);
                }
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);
            }

            void JustDied(Unit* killer) override
            {
                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_AMBER_BLAST:
                        DoAmberBlast();
                        events.ScheduleEvent(EVENT_AMBER_BLAST, TIMER_AMBER_BLAST);
                        break;
                    case EVENT_RESONATING_AMBER:
                        DoResonatingAmber();
                        events.RescheduleEvent(EVENT_AMBER_BLAST, TIMER_AMBER_BLAST);
                        events.ScheduleEvent(EVENT_RESONATING_AMBER, TIMER_RESONATING_AMBER);
                        break;
                }
            }

            void DoAmberBlast()
            {
                DoCastVictim(SPELL_AMBER_BLAST);
            }

            void DoResonatingAmber()
            {
                DoCastAOE(SPELL_RESONATING_AMBER_AOE);
            }

            void DoAmberGrowth(Creature* pAmber)
            {
                DoCast(pAmber, SPELL_AMBER_GROWTH);
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_resonating_amber : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_resonating_amber() : CreatureScript("npc_siege_of_orgrimmar_resonating_amber") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_resonating_amberAI(creature);
        }

        struct npc_siege_of_orgrimmar_resonating_amberAI : public Scripted_NoMovementAI
        {
            npc_siege_of_orgrimmar_resonating_amberAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetReactState(REACT_PASSIVE);
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

            void Reset() override
            {
                me->AddAura(SPELL_RESONATING_AMBER_AURA, me);
            }

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_kovok : public CreatureScript
{
    enum LocalEvents
    {
        EVENT_GROUND_SLAM   = 1,
        EVENT_MIGHTY_CLEAVE,
        EVENT_POISON_BLAST,
    };

    enum LocalTimers
    {
        TIMER_GROUND_SLAM_FIRST     = 7 * IN_MILLISECONDS,
        TIMER_GROUND_SLAM           = 20 * IN_MILLISECONDS,
        TIMER_MIGHTY_CLEAVE_FIRST   = 4 * IN_MILLISECONDS,
        TIMER_MIGHTY_CLEAVE         = 11 * IN_MILLISECONDS,
        TIMER_POISON_BLAST_FIRST    = 10 * IN_MILLISECONDS,
        TIMER_POISON_BLAST          = 20 * IN_MILLISECONDS,
    };

    public:
        npc_siege_of_orgrimmar_kovok() : CreatureScript("npc_siege_of_orgrimmar_kovok") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_kovokAI(creature);
        }

        struct npc_siege_of_orgrimmar_kovokAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_kovokAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                me->SetBoundingRadius(4.0f);
                me->SetCombatReach(7.56f);
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* who) override
            {
                events.ScheduleEvent(EVENT_GROUND_SLAM, TIMER_GROUND_SLAM_FIRST);
                events.ScheduleEvent(EVENT_MIGHTY_CLEAVE, TIMER_MIGHTY_CLEAVE_FIRST);
                events.ScheduleEvent(EVENT_POISON_BLAST, TIMER_POISON_BLAST_FIRST);
            }

            void JustDied(Unit* killer) override
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_GROUND_SLAM:
                        DoGroundSlam();
                        events.ScheduleEvent(EVENT_GROUND_SLAM, TIMER_GROUND_SLAM);
                        break;
                    case EVENT_MIGHTY_CLEAVE:
                        DoMightyCleave();
                        events.ScheduleEvent(EVENT_MIGHTY_CLEAVE, TIMER_MIGHTY_CLEAVE);
                        break;
                    case EVENT_POISON_BLAST:
                        DoPoisonBlast();
                        events.ScheduleEvent(EVENT_POISON_BLAST, TIMER_POISON_BLAST);
                        break;
                }
            }

            void DoGroundSlam()
            {
                DoCastAOE(SPELL_GROUND_SLAM);
            }

            void DoMightyCleave()
            {
                DoCastVictim(SPELL_MIGHTY_CLEAVE);
            }

            void DoPoisonBlast()
            {
                DoCastAOE(SPELL_POISON_BLAST);
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_korkron_reaper : public CreatureScript
{
    enum LocalEvents
    {
        EVENT_CHARGE_1   = 1,
        EVENT_REAPER,
    };

    enum LocalTimers
    {
        TIMER_CHARGE_FIRST  = 1 * IN_MILLISECONDS,
        TIMER_CHARGE        = 30 * IN_MILLISECONDS,
        TIMER_REAPER_FIRST  = 7 * IN_MILLISECONDS,
        TIMER_REAPER        = 20 * IN_MILLISECONDS,
    };

    public:
        npc_siege_of_orgrimmar_korkron_reaper() : CreatureScript("npc_siege_of_orgrimmar_korkron_reaper") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_korkron_reaperAI(creature);
        }

        struct npc_siege_of_orgrimmar_korkron_reaperAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_korkron_reaperAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* who) override
            {
                events.ScheduleEvent(EVENT_CHARGE_1, TIMER_CHARGE_FIRST);
                events.ScheduleEvent(EVENT_REAPER, TIMER_REAPER_FIRST);
            }

            void JustDied(Unit* killer) override
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_CHARGE_1:
                        DoCharge();
                        events.ScheduleEvent(EVENT_CHARGE_1, TIMER_CHARGE);
                        break;
                    case EVENT_REAPER:
                        DoReaper();
                        events.ScheduleEvent(EVENT_REAPER, TIMER_REAPER);
                        break;
                }
            }

            void DoCharge()
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -15.f, true);
                if (!target)
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.f, true);

                if (target)
                {
                    DoCast(target, SPELL_CHARGE);
                }
            }

            void DoReaper()
            {
                DoCastVictim(SPELL_REAPER);
            }

            void DoPoisonBlast()
            {
                DoCastAOE(SPELL_POISON_BLAST);
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_ichor_of_yshaarj : public CreatureScript
{
    enum LocalEvents
    {
        EVENT_EMPOWERING_CORRUPTION   = 1,
    };

    enum LocalTimers
    {
        TIMER_EMPOWERING_CORRUPTION_MIN  = 15 * IN_MILLISECONDS,
        TIMER_EMPOWERING_CORRUPTION_MAX = 40 * IN_MILLISECONDS,
    };

    public:
        npc_siege_of_orgrimmar_ichor_of_yshaarj() : CreatureScript("npc_siege_of_orgrimmar_ichor_of_yshaarj") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_ichor_of_yshaarjAI(creature);
        }

        struct npc_siege_of_orgrimmar_ichor_of_yshaarjAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_ichor_of_yshaarjAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* who) override
            {
                events.ScheduleEvent(EVENT_EMPOWERING_CORRUPTION, urand(TIMER_EMPOWERING_CORRUPTION_MIN, TIMER_EMPOWERING_CORRUPTION_MAX));
            }

            void JustDied(Unit* killer) override
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_EMPOWERING_CORRUPTION:
                        DoEmpoweringCorruption();
                        events.ScheduleEvent(EVENT_EMPOWERING_CORRUPTION, urand(TIMER_EMPOWERING_CORRUPTION_MIN, TIMER_EMPOWERING_CORRUPTION_MAX));
                        break;
                }
            }

            void DoEmpoweringCorruption()
            {
                DoCastAOE(SPELL_EMPOWERING_CORRUPTION);
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_harbringer_of_yshaarj : public CreatureScript
{
    enum LocalEvents
    {
        EVENT_GRASP_OF_YSHAARJ  = 1,
        EVENT_YSHAARJ_TOUCHED,
    };

    enum LocalTimers
    {
        TIMER_GRASP_OF_YSHAARJ_FIRST = 10 * IN_MILLISECONDS,
        TIMER_GRASP_OF_YSHAARJ       = 25 * IN_MILLISECONDS,
        TIMER_YSHAARJ_TOUCHED_FIRST  = 15 * IN_MILLISECONDS,
        TIMER_YSHAARJ_TOUCHED        = 30 * IN_MILLISECONDS,
    };

    public:
        npc_siege_of_orgrimmar_harbringer_of_yshaarj() : CreatureScript("npc_siege_of_orgrimmar_harbringer_of_yshaarj") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_harbringer_of_yshaarjAI(creature);
        }

        struct npc_siege_of_orgrimmar_harbringer_of_yshaarjAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_harbringer_of_yshaarjAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                events.Reset();
                summons.DespawnAll();
            }

            void EnterCombat(Unit* who) override
            {
                events.ScheduleEvent(EVENT_GRASP_OF_YSHAARJ, TIMER_GRASP_OF_YSHAARJ_FIRST);
                events.ScheduleEvent(EVENT_YSHAARJ_TOUCHED, TIMER_YSHAARJ_TOUCHED);
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);
            }

            void JustDied(Unit* killer) override
            {
                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_GRASP_OF_YSHAARJ:
                        DoGraspOfYshaarj();
                        events.ScheduleEvent(EVENT_GRASP_OF_YSHAARJ, TIMER_GRASP_OF_YSHAARJ);
                        break;
                    case EVENT_YSHAARJ_TOUCHED:
                        DoYshaarjTouched();
                        events.ScheduleEvent(EVENT_YSHAARJ_TOUCHED, TIMER_YSHAARJ_TOUCHED);
                        break;
                }
            }

            void DoGraspOfYshaarj()
            {
                DoCastAOE(SPELL_GRASP_OF_YSHAARJ);
            }

            void DoYshaarjTouched()
            {
                DoCast(me, SPELL_YSHAARJ_TOUCHED);
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_manifestation : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_manifestation() : CreatureScript("npc_siege_of_orgrimmar_manifestation") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_manifestationAI(creature);
        }

        struct npc_siege_of_orgrimmar_manifestationAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_manifestationAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
                m_IsUnkillable = false;
            }

            void IsSummonedBy(Unit* owner) override
            {
                if (owner && owner->GetEntry() == NPC_HARBRINGER_OF_YSHAARJ)
                {
                    m_IsUnkillable = true;
                    owner->AddAura(SPELL_BOUND_YSHAARJ_POWER, me);
                }
            }

            void DamageTaken(Unit* who, uint32& damage) override
            {
                if (m_IsUnkillable && me->GetHealth() <= damage)
                {
                    damage = 0;
                }
            }

        private:

            InstanceScript* pInstance;
            bool m_IsUnkillable;
        };
};

class spell_siege_of_orgrimmar_frenzied_assault_aoe : public SpellScriptLoader
{
    public:
        spell_siege_of_orgrimmar_frenzied_assault_aoe() : SpellScriptLoader("spell_siege_of_orgrimmar_frenzied_assault_aoe") { }

        class spell_siege_of_orgrimmar_frenzied_assault_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siege_of_orgrimmar_frenzied_assault_aoe_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_FRENZIED_ASSAULT_JUMP, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_siege_of_orgrimmar_frenzied_assault_aoe_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siege_of_orgrimmar_frenzied_assault_aoe_SpellScript();
        }
};

class spell_siege_of_orgrimmar_resonating_amber_aoe : public SpellScriptLoader
{
    public:
        spell_siege_of_orgrimmar_resonating_amber_aoe() : SpellScriptLoader("spell_siege_of_orgrimmar_resonating_amber_aoe") { }

        class spell_siege_of_orgrimmar_resonating_amber_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siege_of_orgrimmar_resonating_amber_aoe_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_RESONATING_AMBER_SUMMON, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_siege_of_orgrimmar_resonating_amber_aoe_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siege_of_orgrimmar_resonating_amber_aoe_SpellScript();
        }
};

class spell_siege_of_orgrimmar_empowering_corruption : public SpellScriptLoader
{
    public:
        spell_siege_of_orgrimmar_empowering_corruption() : SpellScriptLoader("spell_siege_of_orgrimmar_empowering_corruption") { }

        class spell_siege_of_orgrimmar_empowering_corruption_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siege_of_orgrimmar_empowering_corruption_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                Unit* caster = GetCaster();
                if (!caster)
                {
                    targets.clear();
                    return;
                }

                targets.remove_if([&](WorldObject* obj) -> bool
                {
                    return !obj->IsCreature() || !caster->IsFriendlyTo(obj->ToUnit());
                });
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siege_of_orgrimmar_empowering_corruption_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siege_of_orgrimmar_empowering_corruption_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siege_of_orgrimmar_empowering_corruption_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siege_of_orgrimmar_empowering_corruption_SpellScript();
        }
};

class spell_siege_of_orgrimmar_grasp_of_yshaarj : public SpellScriptLoader
{
    public:
        spell_siege_of_orgrimmar_grasp_of_yshaarj() : SpellScriptLoader("spell_siege_of_orgrimmar_grasp_of_yshaarj") { }

        class spell_siege_of_orgrimmar_grasp_of_yshaarj_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siege_of_orgrimmar_grasp_of_yshaarj_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_GRASP_OF_YSHAARJ_SUMMON, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_siege_of_orgrimmar_grasp_of_yshaarj_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siege_of_orgrimmar_grasp_of_yshaarj_SpellScript();
        }
};


class at_siegecrafter_blackfuse : public AreaTriggerScript
{
    public:

        at_siegecrafter_blackfuse()
            : AreaTriggerScript("at_siegecrafter_blackfuse")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool p_Enter) override
        {
            if (p_Enter)
                SendBlackfuseIntro(player);

            return true;
        }

    private:

        void SendBlackfuseIntro(WorldObject* searcher)
        {
            if (InstanceScript* pInstance = searcher->GetInstanceScript())
            {
                if (pInstance->GetBossState(DATA_THOK_THE_BLOODTHIRSTY) == DONE &&
                    pInstance->GetBossState(DATA_SIEGECRAFTER_BLACKFUSE) != DONE &&
                    pInstance->GetData(DATA_BLACKFUSE_INTRO) != DONE)
                {
                    pInstance->SetData(DATA_BLACKFUSE_INTRO, DONE);
                }
            }
        }
};

void AddSC_siege_of_orgrimmar_part_d()
{
    new npc_siege_of_orgrimmar_gatecrusher_savah();     // 73670
    new npc_siege_of_orgrimmar_grandmaster_alchemist_kixen();   // 73696
    new npc_siege_of_orgrimmar_korthik_honor_guard();   // 72954
    new npc_siege_of_orgrimmar_klaxxi_skirmisher();     // 73012
    new npc_siege_of_orgrimmar_srathik_amber_master();  // 72929
    new npc_siege_of_orgrimmar_resonating_amber();      // 72966
    new npc_siege_of_orgrimmar_kovok();                 // 72927
    new npc_siege_of_orgrimmar_korkron_reaper();        // 73414
    new npc_siege_of_orgrimmar_ichor_of_yshaarj();      // 73415
    new npc_siege_of_orgrimmar_harbringer_of_yshaarj(); // 73452
    new npc_siege_of_orgrimmar_manifestation();         // 73454

    new spell_siege_of_orgrimmar_frenzied_assault_aoe();    // 146531
    new spell_siege_of_orgrimmar_resonating_amber_aoe();    // 146499
    new spell_siege_of_orgrimmar_empowering_corruption();   // 147564
    new spell_siege_of_orgrimmar_grasp_of_yshaarj();        // 147647

    new at_siegecrafter_blackfuse();                    // 9638
}
