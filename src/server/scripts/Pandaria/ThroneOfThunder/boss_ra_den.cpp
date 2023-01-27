#include "throne_of_thunder.h"
#include "Group.h"
#include "SpellAuras.h"

// 7844 world state for heroic attempts

enum Spells 
{
    // Shared
    SPELL_MATERIALS_OF_CREATIONS = 138321,
    SPELL_LINGERING_ENERGIES = 138450,

    // Phase 1
    // Vita
    SPELL_IMBUED_WITH_VITA = 138332,
    SPELL_UNLEASHED_VITA = 138330,
    SPELL_FATAL_STRIKE = 138334,
    SPELL_UNSTABLE_VITA = 138297, // used by Ra-den
    SPELL_UNSTABLE_VITA_PLAYER = 138308, // used by players
    SPELL_VITA_SENSIVITY = 138372,
    SPELL_SUMMON_CRACKLING_STALKER = 138339,

    SPELL_UNSTABLE_VITA_VISUAL = 138371,
    SPELL_ANIMA_SENSITIVITY = 139318,
    SPELL_UNSTABLE_VITA_LINE_DAMAGE = 138370,
    // Anima
    SPELL_IMBUED_WITH_ANIMA = 138331,
    SPELL_MURDEROUS_STRIKE = 138333,
    SPELL_SUMMON_SANGUINE_HORROR = 138338,
    SPELL_UNLEASHED_ANIMA = 138329,
    SPELL_UNSTABLE_ANIMA = 138295, // dummy spell
    SPELL_UNSTABLE_ANIMA_VISUAL = 138294, // maybe...
    SPELL_UNSTABLE_ANIMA_PERIODIC = 138288, // player check spell (?)

    // Phase 2
    SPELL_RUIN = 139073,
    SPELL_RUIN_BOLT = 139087,

    SPELL_CALL_ESSENCE = 139040,

    SPELL_CORRUPTED_ANIMA = 139071,
    SPELL_CORRUPTED_VITA = 139072,

    // Crackling Stalker
    SPELL_CRACKLE = 138340,
    SPELL_CAUTERIZING_FLARE = 138337,

    // Sanguine Horror
    SPELL_SANGUINE_VOLLEY = 138341,

    //Achievement
    SPELL_ACHIEVEMENT_RADEN = 140182,
};

enum Creatures
{
    BOSS_RADEN = 69473,

    NPC_SANGUINE_HORROR = 69871,
    NPC_CRACKLING_STALKER = 69872,

    NPC_ESSENCE_OF_ANIMA = 69869,
    NPC_ESSENCE_OF_VITA = 69870,

    NPC_CORRUPTED_ANIMA = 69957,
    NPC_CORRUPTED_VITA = 69958,
};

static const Position CorruptedAnimaPosition[10] =
{
    { 5395.85f, 4678.5f, -2.47899f, 0.830314f }, // 1
    { 5421.87f, 4706.08f, -2.47899f, 0.596266f }, // 2
    { 5458.72f, 4714.56f, -2.47899f, 3.214f }, // 3
    { 5488.01f, 4692.09f, -2.47864f, 2.42468f }, // 4
    { 5504.24f, 4660.64f, -2.47872f, 1.89931f }, // 5
    { 5497.96f, 4629.92f, -2.47872f, 4.15891f }, // 6
    { 5473.94f, 4606.71f, -2.47872f, 0.617544f }, // 7
    { 5445.44f, 4600.93f, -2.47872f, 1.5364f }, // 8
    { 5419.47f, 4611.00f, -2.47872f, 0.900288f }, // 9
    { 5402.13f, 4630.9f, -2.47872f, 0.507587f }, // 10
};

static const Position CorruptedVitaPosition[10] =
{
    { 5457.97f, 4610.82f, -2.47872f + 5.0f, 0.323005f }, // 1
    { 5479.6f, 4622.76f, -2.47637f + 5.0f, 5.55375f }, // 2
    { 5492.19f, 4646.79f, -2.47637f + 5.0f, 1.4846f },  // 3
    { 5488.76f, 4672.49f, -2.47637f + 5.0f, 2.12863f }, // 4
    { 5470.54f, 4694.09f, -2.47887f + 5.0f, 2.68626f }, // 5
    { 5440.5f, 4701.99f, -2.47887f + 5.0f, 3.18734f }, // 6
    { 5414.9f, 4686.82f, -2.47887f + 5.0f, 3.95075f }, // 7
    { 5402.99f, 4655.22f, -2.47887f + 5.0f, 4.75421f }, // 8
    { 5417.78f, 4626.07f, -2.47887f + 5.0f, 5.50427f }, // 9
    { 5434.49f, 4611.88f, -2.47837f + 5.0f, 4.34975f }, // 10
};

enum CorruptedAnimaandVitaPoints
{
    POINT_1 = 1,
    POINT_2,
    POINT_3,
    POINT_4,
    POINT_5,
    POINT_6,
    POINT_7,
    POINT_8,
    POINT_9,
    POINT_10,

    POINT_RADEN = 11,
};

enum Data
{
    DATA_I_THOUGHT_HE_WAS_SUPPOSED_TO_BE_HARD = 8089,
};

enum Miscs
{
    DATA_VITA_PHASE = 1,
    DATA_ANIMA_PHASE = 2,
};

enum Achievements
{
    ACHIEVEMENT_I_THOUGHT_HE_WAS_SUPPOSED_TO_BE_HARD = 8089,
};

enum Events
{
    EVENT_IMMEDIATE = 1,

    EVENT_ENERGY_REGEN,

    // Sanguine Horror
    EVENT_SANGUINE_VOLLEY,

    // Crackling Stalker
    EVENT_CRACKLE,
    EVENT_CAUTERIZING_FLARE,

    // Ra-den
    EVENT_RUIN_BOLT,
    EVENT_MATERIALS_OF_CREATION,
    EVENT_SELECT_ORB_PHASE_2,
    // anima phase
    EVENT_UNLEASHED_ANIMA,
    EVENT_MURDEROUS_STRIKE,
    EVENT_UNSTABLE_ANIMA,
    EVENT_SUMMON_SANGUINE_HORROR,

    EVENT_REMOVE_SENSITIVITIES,

    //vita phase
    EVENT_SUMMON_CRACKLING_STALKER,
    EVENT_UNSTABLE_VITA,
    EVENT_VITA_FALSE_VARIABLE,
    EVENT_FATAL_STRIKE,
    EVENT_UNLEASHED_VITA,

    // SHARED 1st phase
    EVENT_REFORM_NPC,
    EVENT_CHECK_IF_BOSS_NEARBY,

    // Movement phase 2
    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
    EVENT_7,
    EVENT_8,
    EVENT_9,
    EVENT_10,

    EVENT_NEAR_RADEN,

    EVENT_KILL,
};

enum Timers
{
    TIMER_SANGUINE_VOLLEY = 8 * IN_MILLISECONDS,
    TIMER_SANGUINE_VOLLEY_SECOND = 2 * IN_MILLISECONDS,

    TIMER_CRACKLE = 10 * IN_MILLISECONDS,

    TIMER_RUIN_BOLT = 2 * IN_MILLISECONDS,
    TIMER_MATERIALS_OF_CREATIONS = 32 * IN_MILLISECONDS,

    TIMER_FATAL_STRIKE = 5 * IN_MILLISECONDS,
    TIMER_ENERGY_REGEN = 4 * IN_MILLISECONDS, // SHARED!
    TIMER_UNLEASHED_VITA = 500, //* IN_MILLISECONDS,
    TIMER_UNSTABLE_VITA = 10 * IN_MILLISECONDS,
    TIMER_SUMMON_CRACKLING_STALKER = 29 * IN_MILLISECONDS,

    TIMER_MURDEROUS_STRIKE = 5 * IN_MILLISECONDS,
    TIMER_UNLEASHED_ANIMA = 500, //* IN_MILLISECONDS,
    TIMER_UNSTABLE_ANIMA = 10 * IN_MILLISECONDS,
    TIMER_SUMMON_SANGUINE_HORROR = 29 * IN_MILLISECONDS,
};

enum Actions
{
    ACTION_ANIMA_PHASE = 1,
    ACTION_VITA_PHASE = 2,

    ACTION_MOVE_TO_RADEN = 3,
};

enum Talks
{
    TALK_AGGRO = 1,
    TALK_MURDEROUS_STRIKE = 2,
    TALK_MATERIALS_OF_CREATIONS = 3,
    TALK_UNSTABLE_VITA = 4,
    TALK_UNSTABLE_ANIMA = 5,
    TALK_PHASE_2 = 6,
    TALK_DEFEAT = 7,
    TALK_BERSERK = 8,
};

class bfa_npc_sanguine_horror : public CreatureScript
{
public:
    bfa_npc_sanguine_horror() : CreatureScript("bfa_npc_sanguine_horror") { }

    struct bfa_npc_sanguine_horrorAI : public ScriptedAI
    {
        bfa_npc_sanguine_horrorAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit*)
        {
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_SANGUINE_VOLLEY, TIMER_SANGUINE_VOLLEY);
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                me->SetObjectScale(0.5f);
                me->AddAura(90391, me); // periodic damage
                events.Reset();
                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                events.ScheduleEvent(EVENT_REFORM_NPC, 30 * IN_MILLISECONDS);
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SANGUINE_VOLLEY:
                    if (Unit* target = me->GetVictim())
                    {
                        if (!target->IsWithinMeleeRange(me))
                            me->CastSpell(target, SPELL_SANGUINE_VOLLEY);
                    }
                    events.ScheduleEvent(EVENT_SANGUINE_VOLLEY, TIMER_SANGUINE_VOLLEY_SECOND);
                    break;
                case EVENT_REFORM_NPC:
                    me->SetObjectScale(1.0f);
                    me->AddUnitState(UNIT_STATE_ROOT);
                    me->RemoveAura(90391);
                    me->SetHealth(me->GetMaxHealth());
                    
                    me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    events.ScheduleEvent(EVENT_SANGUINE_VOLLEY, TIMER_SANGUINE_VOLLEY_SECOND);
                    break;
                }
            }
            if (!me->HasAura(90391))
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_sanguine_horrorAI(creature);
    }
};

class bfa_npc_crackling_stalker : public CreatureScript
{
public:
    bfa_npc_crackling_stalker() : CreatureScript("bfa_npc_crackling_stalker") { }

    struct bfa_npc_crackling_stalkerAI : public ScriptedAI
    {
        bfa_npc_crackling_stalkerAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void JustDied(Unit*)
        {
            me->CastSpell(me, SPELL_CAUTERIZING_FLARE, true);

            std::list<Creature*> sang;
            me->GetCreatureListWithEntryInGrid(sang, NPC_SANGUINE_HORROR, 8.0f);

            if (!sang.empty())
            {
                for (std::list<Creature*>::iterator itr = sang.begin(); itr != sang.end(); ++itr)
                {
                    Creature* sanguine = (*itr);

                    if (sanguine->HasAura(90391))
                        me->Kill(sanguine);
                }
            }
        }

        void IsSummonedBy(Unit*)
        {
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_CRACKLE, TIMER_CRACKLE);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CRACKLE:
                    me->CastSpell(me->GetVictim(), SPELL_CRACKLE);
                    events.ScheduleEvent(EVENT_CRACKLE, TIMER_CRACKLE);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_crackling_stalkerAI(creature);
    }
};

class bfa_boss_ra_den : public CreatureScript
{
public:
    bfa_boss_ra_den() : CreatureScript("bfa_boss_ra_den") { }

    struct bfa_boss_ra_denAI : public ScriptedAI
    {
        bfa_boss_ra_denAI(Creature* creature) : ScriptedAI(creature)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            instance = creature->GetInstanceScript();
            //set_speed(2.0f);
            _achievement = 0;
        }

        EventMap events;
        EventMap eventsOOC;
        bool phaseTwo;
        bool vitaActive;
        bool animaActive;
        bool encounterCompleted;
        InstanceScript* instance;
        uint32 _achievement;
        uint32 vita;
        uint32 anima;

        void Reset()
        {
            RemoveVitaSpells();
            RemoveAnimaSpells();
            me->SetHealth(me->GetMaxHealth());
            phaseTwo = false;
            vitaActive = false;
            animaActive = false;
            vita = 0;
            anima = 0;
            encounterCompleted = false;
            events.Reset();
            eventsOOC.Reset();
            DespawnCreature(NPC_ESSENCE_OF_ANIMA);
            DespawnCreature(NPC_CRACKLING_STALKER);
            DespawnCreature(NPC_SANGUINE_HORROR);
            DespawnCreature(NPC_ESSENCE_OF_VITA);
            DespawnCreature(NPC_CORRUPTED_ANIMA);
            DespawnCreature(NPC_CORRUPTED_VITA);
            if (instance)
                instance->SetBossState(DATA_RA_DEN, NOT_STARTED);
        }

        void ClearCombatfromPlayers()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->CombatStop();
                    me->CombatStop();
                }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
            case DATA_I_THOUGHT_HE_WAS_SUPPOSED_TO_BE_HARD:
                _achievement++;
                break;
            case DATA_VITA_PHASE:
                vita++;
                break;
            case DATA_ANIMA_PHASE:
                anima++;
                break;
            }
        }

        uint32 GetData(uint32 type) const
        {
            switch (type)
            {
            case DATA_I_THOUGHT_HE_WAS_SUPPOSED_TO_BE_HARD:
                return _achievement;
                break;
            case DATA_VITA_PHASE:
                return vita;
                break;
            case DATA_ANIMA_PHASE:
                return anima;
                break;
            }

            return 0;
        }

        void KilledUnit(Unit* killed)
        {
            me->GetAI()->SetData(DATA_I_THOUGHT_HE_WAS_SUPPOSED_TO_BE_HARD, 1);
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            if (me->HealthBelowPct(40) && !phaseTwo)
            {
                phaseTwo = true;
                Talk(TALK_PHASE_2);
                me->AddUnitState(UNIT_STATE_ROOT);
                me->AddAura(SPELL_RUIN, me);
                RemoveVitaSpells();
                RemoveAnimaSpells();
                RemoveUnleashedAnima();
                events.Reset();
                SummonCorruptedVitaAnima();
                events.ScheduleEvent(EVENT_RUIN_BOLT, TIMER_RUIN_BOLT);
                events.ScheduleEvent(EVENT_SELECT_ORB_PHASE_2, 15 * IN_MILLISECONDS);
            }

            if (me->HealthBelowPct(5) && !encounterCompleted)
            {
                events.Reset();
                encounterCompleted = true;
                ClearCombatfromPlayers();
                me->CastSpell(me, SPELL_ACHIEVEMENT_RADEN, true);
                me->SetFaction(35);
                eventsOOC.ScheduleEvent(EVENT_KILL, 5000);
                RemoveVitaSpells();
                RemoveAnimaSpells();
                DespawnCreature(NPC_ESSENCE_OF_ANIMA);
                DespawnCreature(NPC_CRACKLING_STALKER);
                DespawnCreature(NPC_SANGUINE_HORROR);
                DespawnCreature(NPC_ESSENCE_OF_VITA);
                DespawnCreature(NPC_CORRUPTED_ANIMA);
                DespawnCreature(NPC_CORRUPTED_VITA);
                me->RemoveAllAuras();
                me->AttackStop();
                damage = 0;
                Talk(TALK_DEFEAT);
                if (instance)
                    instance->SetBossState(DATA_RA_DEN, DONE);

                // looting chest
                uint32 chestID = 0;
                switch (me->GetMap()->GetDifficultyID())
                {
                case DIFFICULTY_10_HC:
                    chestID = 218997;
                    break;
                case DIFFICULTY_25_HC:
                    chestID = 218998;
                    break;
                }

            }
        }

        void RemoveUnleashedAnima()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    player->RemoveAura(SPELL_UNLEASHED_ANIMA);
        }

        void EnterEvadeMode(EvadeReason w)
        {
            if (encounterCompleted)
                return;


            RemoveUnleashedAnima();
            me->GetAI()->SetData(DATA_I_THOUGHT_HE_WAS_SUPPOSED_TO_BE_HARD, 1);
            RemoveVitaSpells();
            RemoveAnimaSpells();
            me->ClearUnitState(UNIT_STATE_ROOT);
            if (instance)
                instance->SetBossState(DATA_RA_DEN, FAIL);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_ANIMA_PHASE:
                if (animaActive)
                    return;
                animaActive = true;
                RemoveVitaSpells();
                me->RemoveAura(SPELL_IMBUED_WITH_VITA);
                vita = 0;
                me->AddAura(SPELL_IMBUED_WITH_ANIMA, me);
                //DespawnCreature(NPC_ESSENCE_OF_VITA);
                events.CancelEvent(EVENT_MURDEROUS_STRIKE);
                events.CancelEvent(EVENT_UNSTABLE_ANIMA);
                events.CancelEvent(EVENT_SUMMON_SANGUINE_HORROR);
                events.CancelEvent(EVENT_UNLEASHED_ANIMA);
                // if scheduled ..
                events.CancelEvent(EVENT_FATAL_STRIKE);
                events.CancelEvent(EVENT_UNSTABLE_VITA);
                events.CancelEvent(EVENT_UNLEASHED_VITA);
                events.CancelEvent(EVENT_SUMMON_CRACKLING_STALKER);
                events.ScheduleEvent(EVENT_MURDEROUS_STRIKE, TIMER_MURDEROUS_STRIKE);
                if (me->GetAI()->GetData(DATA_ANIMA_PHASE) < 1)
                {
                    events.ScheduleEvent(EVENT_UNLEASHED_ANIMA, TIMER_UNLEASHED_ANIMA);
                    events.ScheduleEvent(EVENT_UNSTABLE_ANIMA, TIMER_UNSTABLE_ANIMA);
                }
                me->AI()->SetData(DATA_ANIMA_PHASE, 1);
                events.ScheduleEvent(EVENT_SUMMON_SANGUINE_HORROR, TIMER_SUMMON_SANGUINE_HORROR);
                break;
            case ACTION_VITA_PHASE:
                if (vitaActive)
                    return;
                vitaActive = true;
                anima = 0;
                RemoveAnimaSpells();
                me->RemoveAura(SPELL_IMBUED_WITH_ANIMA);
                me->AddAura(SPELL_IMBUED_WITH_VITA, me);
                //DespawnCreature(NPC_ESSENCE_OF_ANIMA);
                events.ScheduleEvent(EVENT_REMOVE_SENSITIVITIES, 5000);
                events.CancelEvent(EVENT_FATAL_STRIKE);
                events.CancelEvent(EVENT_UNSTABLE_VITA);
                events.CancelEvent(EVENT_UNLEASHED_VITA);
                events.CancelEvent(EVENT_SUMMON_CRACKLING_STALKER);
                // if scheduled .. 
                events.CancelEvent(EVENT_MURDEROUS_STRIKE);
                events.CancelEvent(EVENT_UNSTABLE_ANIMA);
                events.CancelEvent(EVENT_SUMMON_SANGUINE_HORROR);
                events.CancelEvent(EVENT_UNLEASHED_ANIMA);
                events.ScheduleEvent(EVENT_VITA_FALSE_VARIABLE, 800);
                events.ScheduleEvent(EVENT_FATAL_STRIKE, TIMER_FATAL_STRIKE);
                if (me->GetAI()->GetData(DATA_VITA_PHASE) < 1)
                {
                    events.ScheduleEvent(EVENT_UNLEASHED_VITA, TIMER_UNLEASHED_VITA);
                    events.ScheduleEvent(EVENT_UNSTABLE_VITA, TIMER_UNSTABLE_VITA);
                }
                me->AI()->SetData(DATA_VITA_PHASE, 1);
                events.ScheduleEvent(EVENT_SUMMON_CRACKLING_STALKER, TIMER_SUMMON_CRACKLING_STALKER);
                break;
            }
        }

        void DespawnCreature(uint32 entry)
        {
            std::list<Creature*> creatureList;
            GetCreatureListWithEntryInGrid(creatureList, me, entry, 500.0f);
            for (auto NowCreature : creatureList)
                NowCreature->DespawnOrUnsummon();
        }

        void SummonCorruptedVitaAnima()
        {
            // Vita
            Creature* temp1 = me->SummonCreature(NPC_CORRUPTED_VITA, CorruptedVitaPosition[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* temp2 = me->SummonCreature(NPC_CORRUPTED_VITA, CorruptedVitaPosition[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* temp3 = me->SummonCreature(NPC_CORRUPTED_VITA, CorruptedVitaPosition[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* temp4 = me->SummonCreature(NPC_CORRUPTED_VITA, CorruptedVitaPosition[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* temp5 = me->SummonCreature(NPC_CORRUPTED_VITA, CorruptedVitaPosition[4], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* temp6 = me->SummonCreature(NPC_CORRUPTED_VITA, CorruptedVitaPosition[5], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* temp7 = me->SummonCreature(NPC_CORRUPTED_VITA, CorruptedVitaPosition[6], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* temp8 = me->SummonCreature(NPC_CORRUPTED_VITA, CorruptedVitaPosition[7], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* temp9 = me->SummonCreature(NPC_CORRUPTED_VITA, CorruptedVitaPosition[8], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* temp10 = me->SummonCreature(NPC_CORRUPTED_VITA, CorruptedVitaPosition[9], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);

            temp1->GetMotionMaster()->MovePoint(POINT_1, CorruptedVitaPosition[1]);
            temp2->GetMotionMaster()->MovePoint(POINT_2, CorruptedVitaPosition[2]);
            temp3->GetMotionMaster()->MovePoint(POINT_3, CorruptedVitaPosition[3]);
            temp4->GetMotionMaster()->MovePoint(POINT_4, CorruptedVitaPosition[4]);
            temp5->GetMotionMaster()->MovePoint(POINT_5, CorruptedVitaPosition[5]);
            temp6->GetMotionMaster()->MovePoint(POINT_6, CorruptedVitaPosition[6]);
            temp7->GetMotionMaster()->MovePoint(POINT_7, CorruptedVitaPosition[7]);
            temp8->GetMotionMaster()->MovePoint(POINT_8, CorruptedVitaPosition[8]);
            temp9->GetMotionMaster()->MovePoint(POINT_9, CorruptedVitaPosition[9]);
            temp10->GetMotionMaster()->MovePoint(POINT_10, CorruptedVitaPosition[0]);

            // Anima
            Creature* tmp1 = me->SummonCreature(NPC_CORRUPTED_ANIMA, CorruptedAnimaPosition[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* tmp2 = me->SummonCreature(NPC_CORRUPTED_ANIMA, CorruptedAnimaPosition[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* tmp3 = me->SummonCreature(NPC_CORRUPTED_ANIMA, CorruptedAnimaPosition[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* tmp4 = me->SummonCreature(NPC_CORRUPTED_ANIMA, CorruptedAnimaPosition[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* tmp5 = me->SummonCreature(NPC_CORRUPTED_ANIMA, CorruptedAnimaPosition[4], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* tmp6 = me->SummonCreature(NPC_CORRUPTED_ANIMA, CorruptedAnimaPosition[5], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* tmp7 = me->SummonCreature(NPC_CORRUPTED_ANIMA, CorruptedAnimaPosition[6], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* tmp8 = me->SummonCreature(NPC_CORRUPTED_ANIMA, CorruptedAnimaPosition[7], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* tmp9 = me->SummonCreature(NPC_CORRUPTED_ANIMA, CorruptedAnimaPosition[8], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);
            Creature* tmp10 = me->SummonCreature(NPC_CORRUPTED_ANIMA, CorruptedAnimaPosition[9], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 0);

            tmp1->GetMotionMaster()->MovePoint(POINT_1, CorruptedAnimaPosition[1]);
            tmp2->GetMotionMaster()->MovePoint(POINT_2, CorruptedAnimaPosition[2]);
            tmp3->GetMotionMaster()->MovePoint(POINT_3, CorruptedAnimaPosition[3]);
            tmp4->GetMotionMaster()->MovePoint(POINT_4, CorruptedAnimaPosition[4]);
            tmp5->GetMotionMaster()->MovePoint(POINT_5, CorruptedAnimaPosition[5]);
            tmp6->GetMotionMaster()->MovePoint(POINT_6, CorruptedAnimaPosition[6]);
            tmp7->GetMotionMaster()->MovePoint(POINT_7, CorruptedAnimaPosition[7]);
            tmp8->GetMotionMaster()->MovePoint(POINT_8, CorruptedAnimaPosition[8]);
            tmp9->GetMotionMaster()->MovePoint(POINT_9, CorruptedAnimaPosition[9]);
            tmp10->GetMotionMaster()->MovePoint(POINT_10, CorruptedAnimaPosition[0]);
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_MATERIALS_OF_CREATION, 10 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_ENERGY_REGEN, TIMER_ENERGY_REGEN);
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
            Talk(TALK_AGGRO);
            if (instance)
                instance->SetBossState(DATA_RA_DEN, IN_PROGRESS);
            RemoveReincarnationcooldown();
        }

        void RemoveReincarnationcooldown()
        {
            // no longer in use
        }

        void RemoveVitaSpells()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(SPELL_UNSTABLE_VITA_PLAYER);
                }
        }

        void RemoveAnimaSpells()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(SPELL_ANIMA_SENSITIVITY);
                    player->RemoveAura(138288);
                    player->RemoveAura(138294);
                    player->RemoveAura(SPELL_UNSTABLE_ANIMA);
                }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            eventsOOC.Update(diff);
            while (uint32 eventId = eventsOOC.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_KILL:
                    me->SetVisible(false);
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            player->Kill(me);
                        }
                    break;
                }
            }

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_REMOVE_SENSITIVITIES:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            player->RemoveAura(SPELL_UNLEASHED_ANIMA);
                    break;
                }
                case EVENT_MATERIALS_OF_CREATION:
                    Talk(TALK_MATERIALS_OF_CREATIONS);
                    me->CastSpell(me, SPELL_MATERIALS_OF_CREATIONS);
                    events.ScheduleEvent(EVENT_MATERIALS_OF_CREATION, TIMER_MATERIALS_OF_CREATIONS);
                    break;
                case EVENT_ENERGY_REGEN:
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 10);
                    events.ScheduleEvent(EVENT_ENERGY_REGEN, TIMER_ENERGY_REGEN);
                    break;
                case EVENT_FATAL_STRIKE:
                    if (me->GetPower(POWER_ENERGY) == 100)
                    {
                        me->CastSpell(me->GetVictim(), SPELL_FATAL_STRIKE, true);
                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - 100);
                    }
                    events.ScheduleEvent(EVENT_FATAL_STRIKE, TIMER_FATAL_STRIKE);
                    break;
                case EVENT_MURDEROUS_STRIKE:
                    if (me->GetPower(POWER_ENERGY) == 100)
                    {
                        Talk(TALK_MURDEROUS_STRIKE);
                        me->CastSpell(me->GetVictim(), SPELL_MURDEROUS_STRIKE, true);
                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - 100);
                    }
                    events.ScheduleEvent(EVENT_MURDEROUS_STRIKE, TIMER_MURDEROUS_STRIKE);
                    break;
                case EVENT_VITA_FALSE_VARIABLE:
                    vitaActive = false;
                    break;
                case EVENT_UNLEASHED_VITA:
                    me->CastSpell(me, SPELL_UNLEASHED_VITA);
                    me->CastSpell(me, SPELL_LINGERING_ENERGIES, true);
                    break;
                case EVENT_UNLEASHED_ANIMA:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            player->RemoveAura(SPELL_VITA_SENSIVITY);
                    animaActive = false;
                    me->CastSpell(me, SPELL_UNLEASHED_ANIMA);
                    me->CastSpell(me, SPELL_LINGERING_ENERGIES, true);
                    break;
                }
                case EVENT_SUMMON_CRACKLING_STALKER:
                {
                    if (Creature* stalker = me->SummonCreature(NPC_CRACKLING_STALKER, me->GetPositionX() + 15.0f, me->GetPositionY(), me->GetPositionZ(), 0.0f, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        if (Aura* stacks = me->GetAura(SPELL_LINGERING_ENERGIES))
                        {
                            uint32 newstacks = stacks->GetStackAmount();
                            if (Aura* stalkerStack = me->AddAura(SPELL_LINGERING_ENERGIES, stalker))
                                stalkerStack->SetStackAmount(newstacks);
                        }
                    }
                    events.ScheduleEvent(EVENT_SUMMON_CRACKLING_STALKER, TIMER_SUMMON_CRACKLING_STALKER);
                    break;
                }
                case EVENT_SUMMON_SANGUINE_HORROR:
                {
                    if (Creature* horror = me->SummonCreature(NPC_SANGUINE_HORROR, me->GetPositionX() + 15.0f, me->GetPositionY(), me->GetPositionZ(), 0.0f, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        if (Aura* stacks = me->GetAura(SPELL_LINGERING_ENERGIES))
                        {
                            uint32 newstacks = stacks->GetStackAmount();
                            if (Aura* stalkerStack = me->AddAura(SPELL_LINGERING_ENERGIES, horror))
                                stalkerStack->SetStackAmount(newstacks);
                        }
                    }
                    events.ScheduleEvent(EVENT_SUMMON_SANGUINE_HORROR, TIMER_SUMMON_SANGUINE_HORROR);
                    break;
                }
                case EVENT_RUIN_BOLT:
                    if (Unit* target = me->GetVictim())
                    {
                        if (!target->IsWithinMeleeRange(me))
                            me->CastSpell(target, SPELL_RUIN_BOLT);
                    }
                    events.ScheduleEvent(EVENT_RUIN_BOLT, TIMER_RUIN_BOLT);
                    break;
                case EVENT_UNSTABLE_VITA:
                {
                    Talk(TALK_UNSTABLE_VITA);
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        me->CastSpell((*itr), SPELL_UNSTABLE_VITA_PLAYER);
                    
                    break;
                }
                case EVENT_UNSTABLE_ANIMA:
                {
                    Talk(TALK_UNSTABLE_ANIMA);
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        me->CastSpell((*itr), SPELL_UNSTABLE_ANIMA_PERIODIC);
                    break;
                }
                case EVENT_SELECT_ORB_PHASE_2:
                {
                    std::list<Creature*> corrupted;
                    me->GetCreatureListWithEntryInGrid(corrupted, NPC_CORRUPTED_ANIMA, 500.0f);
                    me->GetCreatureListWithEntryInGrid(corrupted, NPC_CORRUPTED_VITA, 500.0f);

                    if (!corrupted.empty())
                        if (corrupted.size() > 1)
                            Trinity::Containers::RandomResize(corrupted, 1);
                    for (std::list<Creature*>::iterator itr = corrupted.begin(); itr != corrupted.end(); ++itr)
                    {
                        Creature* animaorvita = *itr;

                        animaorvita->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
                        animaorvita->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                        animaorvita->GetMotionMaster()->Clear(true);
                        animaorvita->StopMoving();
                        animaorvita->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), false);
                        animaorvita->AI()->DoAction(ACTION_MOVE_TO_RADEN);
                    }
                    events.ScheduleEvent(EVENT_SELECT_ORB_PHASE_2, 15 * IN_MILLISECONDS);
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_boss_ra_denAI(creature);
    }
};

class bfa_npc_essence_of_vita : public CreatureScript
{
public:
    bfa_npc_essence_of_vita() : CreatureScript("bfa_npc_essence_of_vita") { }

    struct bfa_npc_essence_of_vitaAI : public ScriptedAI
    {
        bfa_npc_essence_of_vitaAI(Creature* creature) : ScriptedAI(creature)
        {
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_THREAT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, 61391, true);
            //set_speed(0.5f);
            me->SetReactState(REACT_PASSIVE);
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            //bfa_AddRootAura(me, 1000);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* summoner)
        {
            //me->AddThreat(summoner, 999999999.9f);
            //me->AI()->AttackStart(summoner);
            me->GetMotionMaster()->MovePoint(0, summoner->GetPositionX(), summoner->GetPositionY(), summoner->GetPositionZ() + 1.0f, false);
            me->GetMotionMaster()->MoveChase(summoner);
            events.ScheduleEvent(EVENT_CHECK_IF_BOSS_NEARBY, 1000);
        }

        Creature* GetRaden()
        {
            return me->FindNearestCreature(BOSS_RADEN, 500.0f, true);
        }

        Creature* GetAnima()
        {
            return me->FindNearestCreature(NPC_ESSENCE_OF_ANIMA, 150.0f, true);
        }

        void JustDied(Unit*)
        {
            if (Creature* anima = GetAnima())
                anima->DespawnOrUnsummon(1000);
            if (Creature* raden = GetRaden())
                raden->AI()->DoAction(ACTION_ANIMA_PHASE);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (Creature* raden = GetRaden())
            {
                me->GetMotionMaster()->MoveFollow(raden, 0.0f, 0.0f);
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_IF_BOSS_NEARBY:
                    if (Creature* raden = GetRaden())
                    {
                        if (me->GetDistance(raden) <= 4.0f)
                        {
                            raden->AI()->DoAction(ACTION_VITA_PHASE);
                            me->DespawnOrUnsummon(500);
                            events.CancelEvent(EVENT_CHECK_IF_BOSS_NEARBY);
                        }
                    }
                    events.ScheduleEvent(EVENT_CHECK_IF_BOSS_NEARBY, 1500);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_essence_of_vitaAI(creature);
    }
};

class bfa_npc_essence_of_anima : public CreatureScript
{
public:
    bfa_npc_essence_of_anima() : CreatureScript("bfa_npc_essence_of_anima") { }

    struct bfa_npc_essence_of_animaAI : public ScriptedAI
    {
        bfa_npc_essence_of_animaAI(Creature* creature) : ScriptedAI(creature)
        {
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_THREAT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, 61391, true);
            //set_speed(0.5f);
            me->SetReactState(REACT_PASSIVE);
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            //bfa_AddRootAura(me, 1000);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* summoner)
        {
            //me->AddThreat(summoner, 999999999.9f);
            //me->AI()->AttackStart(summoner);
            me->GetMotionMaster()->MoveChase(summoner);
            events.ScheduleEvent(EVENT_CHECK_IF_BOSS_NEARBY, 1000);
        }

        Creature* GetRaden()
        {
            return me->FindNearestCreature(BOSS_RADEN, 500.0f, true);
        }

        Creature* GetVita()
        {
            return me->FindNearestCreature(NPC_ESSENCE_OF_VITA, 150.0f, true);
        }

        void JustDied(Unit*)
        {
            if (Creature* vita = GetVita())
                vita->DespawnOrUnsummon(1000);
            if (Creature* raden = GetRaden())
                raden->AI()->DoAction(ACTION_VITA_PHASE);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (Creature* raden = GetRaden())
            {
                me->GetMotionMaster()->MoveFollow(raden, 0.0f, 0.0f);
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_IF_BOSS_NEARBY:
                    if (Creature* raden = GetRaden())
                    {
                        if (me->GetDistance(raden) <= 4.0f)
                        {
                            raden->AI()->DoAction(ACTION_ANIMA_PHASE);
                            me->DespawnOrUnsummon(500);
                            events.CancelEvent(EVENT_CHECK_IF_BOSS_NEARBY);
                        }
                    }
                    events.ScheduleEvent(EVENT_CHECK_IF_BOSS_NEARBY, 1500);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_essence_of_animaAI(creature);
    }
};

class bfa_spell_materials_of_creation : public SpellScriptLoader
{
public:
    bfa_spell_materials_of_creation() : SpellScriptLoader("bfa_spell_materials_of_creation") { }

    class bfa_spell_materials_of_creation_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_materials_of_creation_SpellScript)

            void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            float positionAnimaX = 0.0f;
            float positionAnimaY = 0.0f;
            float positionAnimaZ = 0.0f;
            float positionVitaX = 0.0f;
            float positionVitaY = 0.0f;
            float positionVitaZ = 0.0f;
            switch (rand() % 5)
            {
            case 0:
                positionAnimaX = 5409.22f;
                positionAnimaY = 4678.63f;
                positionAnimaZ = -2.47f;

                positionVitaX = 5487.15f;
                positionVitaY = 4631.14f;
                positionVitaZ = 2.47f;
                break;
            case 1:
                positionAnimaX = 5453.59f;
                positionAnimaY = 4607.33f;
                positionAnimaZ = -2.47f;

                positionVitaX = 5448.44f;
                positionVitaY = 4703.32f;
                positionVitaZ = 2.47f;
                break;
            case 2:
                positionAnimaX = 5472.04f;
                positionAnimaY = 4693.92f;
                positionAnimaZ = -2.47f;

                positionVitaX = 5420.59f;
                positionVitaY = 4620.57f;
                positionVitaZ = 2.47f;
                break;
            case 3:
                positionAnimaX = 5405.50f;
                positionAnimaY = 4634.48f;
                positionAnimaZ = -2.47f;

                positionVitaX = 5490.08f;
                positionVitaY = 4672.37f;
                positionVitaZ = 2.47f;
                break;
            case 4:
                positionAnimaX = 5492.52f;
                positionAnimaY = 4645.80f;
                positionAnimaZ = -2.47f;

                positionVitaX = 5403.41f;
                positionVitaY = 4668.96f;
                positionVitaZ = 2.47f;
                break;

            }
            caster->SummonCreature(NPC_ESSENCE_OF_ANIMA, positionAnimaX, positionAnimaY, positionAnimaZ, 0.0f, TEMPSUMMON_MANUAL_DESPAWN);
            caster->SummonCreature(NPC_ESSENCE_OF_VITA, positionVitaX, positionVitaY, positionVitaZ + 0.5f, 0.0f, TEMPSUMMON_MANUAL_DESPAWN);
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_materials_of_creation_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_materials_of_creation_SpellScript();
    }
};
struct PossibleGMs : public std::unary_function<Unit*, bool>
{
    PossibleGMs() {}

    bool operator() (const Unit* target)
    {
        Player* player = const_cast<Player*>(target->ToPlayer());
        return player->IsGameMaster();
    }
};

struct VitaSensitivity : public std::unary_function<Unit*, bool>
{
    VitaSensitivity() {}

    bool operator() (const Unit* target)
    {
        return target->HasAura(SPELL_VITA_SENSIVITY);
    }
};

struct DeadTargets : public std::unary_function<Unit*, bool>
{
    DeadTargets() {}

    bool operator() (const Unit* target)
    {
        return target->isDead();
    }
};

struct AnimaSensitivity : public std::unary_function<Unit*, bool>
{
    AnimaSensitivity() {}

    bool operator() (const Unit* target)
    {
        return target->HasAura(SPELL_ANIMA_SENSITIVITY);
    }
};

struct TargetsAreDead : public std::unary_function<Unit*, bool>
{
    TargetsAreDead() {}

    bool operator() (const Unit* target)
    {
        return target->isDead();
    }
};

// Unstable Vita
class bfa_spell_unstable_vita : public SpellScriptLoader
{
public:
    bfa_spell_unstable_vita() : SpellScriptLoader("bfa_spell_unstable_vita") {}

    class bfa_spell_unstable_vita_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_unstable_vita_AuraScript);

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            switch (caster->GetMap()->GetDifficultyID())
            {
            case DIFFICULTY_10_HC:
                this->SetMaxDuration(13 * IN_MILLISECONDS);
                this->SetDuration(13 * IN_MILLISECONDS);
                break;
            case DIFFICULTY_25_HC:
                this->SetMaxDuration(5 * IN_MILLISECONDS);
                this->SetDuration(5 * IN_MILLISECONDS);
                break;
            }
        }

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            AuraRemoveMode remove = GetTargetApplication()->GetRemoveMode();
            if (remove != AURA_REMOVE_BY_EXPIRE)
                return;

            Player* target = GetTarget()->ToPlayer();
            Player* mostDistant = GetTarget()->ToPlayer();
            if (!target || !mostDistant)
                return;

            target->ApplySpellImmune(0, IMMUNITY_ID, 138370, true); // unstable vita damage temp
            std::list<Player*> targets;
            target->GetPlayerListInGrid(targets, 200.0f);

            targets.remove_if(PossibleGMs());
            targets.remove_if(TargetsAreDead());
            //targets.remove_if(VitaSensitivity());
            targets.remove(target);
            if (!targets.empty())
            {
                targets.sort(Trinity::ObjectDistanceOrderPred(target, false));
                mostDistant = *targets.begin();
                target->CastSpell(mostDistant, SPELL_UNSTABLE_VITA_PLAYER, true);
                target->CastSpell(mostDistant, SPELL_UNSTABLE_VITA_VISUAL);
                target->CastSpell(target, SPELL_VITA_SENSIVITY);
                if (mostDistant->HasAura(SPELL_VITA_SENSIVITY))
                    target->Kill(mostDistant, true);
            }

            Map::PlayerList const& playerList = target->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    Position mainObject; // caster
                    Position secondObject; // distant player
                    //target->GetPosition(&mainObject);
                    //mostDistant->GetPosition(&secondObject);
                    //if (bfa_IsOnBeam(player, mainObject, secondObject, 10.0f, 3.0f, target->GetDistance(mostDistant)))
                    if(player->IsInBetween(mainObject, secondObject, 10.0f))
                    {
                        target->CastSpell(player, SPELL_UNSTABLE_VITA_LINE_DAMAGE, true);
                    }
                }
            target->ApplySpellImmune(0, IMMUNITY_ID, 138370, false); // unstable vita damage temp
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_unstable_vita_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_unstable_vita_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_unstable_vita_AuraScript();
    }

};

class bfa_spell_unstable_vita_damage : public SpellScriptLoader
{
public:
    bfa_spell_unstable_vita_damage() : SpellScriptLoader("bfa_spell_unstable_vita_damage") {}

    class bfa_spell_unstable_vita_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_unstable_vita_damage_SpellScript);

        void HandleOnHit(SpellEffIndex index)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (target->HasAura(SPELL_VITA_SENSIVITY))
                        caster->Kill(target, false);
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_unstable_vita_damage_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_unstable_vita_damage_SpellScript();
    }

};

// POSSIBLY NEEDED LATER
/*class bfa_spell_unstable_anima : public SpellScriptLoader
{
public:
bfa_spell_unstable_anima() : SpellScriptLoader("bfa_spell_unstable_anima") { }

class bfa_spell_unstable_anima_AuraScript : public AuraScript
{
PrepareAuraScript(bfa_spell_unstable_anima_AuraScript);

void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
{
Unit* caster = GetCaster();

if (!caster)
return;

caster->AddAura(138294, caster); // visual circle
}

void OnPeriodic(AuraEffect const* aurEff)
{
Unit* caster = GetCaster();

if (!caster)
return;

Aura * aura = GetAura();
int32 damageontenman = 250000;
int32 damageontwentyfiveman = 625000;

std::list<Player*> playerList;
GetPlayerListInGrid(playerList, caster, 8.0f);

if (!playerList.empty())
for (std::list<Player*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
{
// Don't count self
if ((*itr) == caster)
continue;

if (playerList.size())
{
int32 finalDamage = caster->GetMap()->Is25ManRaid() ? damageontwentyfiveman : damageontenman;
int32 executionDamage = finalDamage / playerList.size();
if (AuraEffect * aurEff = aura->GetEffect(EFFECT_2))
{
aurEff->SetAmount(executionDamage);
}
}
}
}

void Register()
{
OnEffectApply += AuraEffectApplyFn(bfa_spell_unstable_anima_AuraScript::OnApply, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_unstable_anima_AuraScript::OnPeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE);
}
};

AuraScript* GetAuraScript() const
{
return new bfa_spell_unstable_anima_AuraScript();
}
};*/

class bfa_npc_corrupted_anima : public CreatureScript
{
public:
    bfa_npc_corrupted_anima() : CreatureScript("bfa_npc_corrupted_anima") { }

    struct bfa_npc_corrupted_animaAI : public ScriptedAI
    {
        bfa_npc_corrupted_animaAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, 61391, true);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            //set_speed(1.5f);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        Creature* GetRaden()
        {
            return me->FindNearestCreature(BOSS_RADEN, 500.0f, true);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_MOVE_TO_RADEN:
            {
                //set_speed(0.5f);
                events.Reset();
                events.ScheduleEvent(EVENT_NEAR_RADEN, 2000);
                break;
            }
            }
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            if (damage >= me->GetHealth())
            {
                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 8.0f);

                playerList.remove_if(PossibleGMs());
                playerList.remove_if(DeadTargets());

                if (playerList.size() > 1)
                    who->CastSpell(who, 139075, true); // on soak
                else if (playerList.size() == 1)
                {
                    int32 damage = 10000000;
                    who->CastCustomSpell(who, 139075, &damage, NULL, NULL, true);
                }
                RemoveAnimaSensitivity();
            }
        }

        void RemoveAnimaSensitivity()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    player->RemoveAura(SPELL_ANIMA_SENSITIVITY);
        }

        void MovementInform(uint32 type, uint32 id)
        {
            switch (id)
            {
            case POINT_1:
                events.ScheduleEvent(EVENT_1, 1);
                break;
            case POINT_2:
                events.ScheduleEvent(EVENT_2, 1);
                break;
            case POINT_3:
                events.ScheduleEvent(EVENT_3, 1);
                break;
            case POINT_4:
                events.ScheduleEvent(EVENT_4, 1);
                break;
            case POINT_5:
                events.ScheduleEvent(EVENT_5, 1);
                break;
            case POINT_6:
                events.ScheduleEvent(EVENT_6, 1);
                break;
            case POINT_7:
                events.ScheduleEvent(EVENT_7, 1);
                break;
            case POINT_8:
                events.ScheduleEvent(EVENT_8, 1);
                break;
            case POINT_9:
                events.ScheduleEvent(EVENT_9, 1);
                break;
            case POINT_10:
                events.ScheduleEvent(EVENT_10, 1);
                break;
            case POINT_RADEN:
                if (Creature* raden = GetRaden())
                    me->CastSpell(raden, SPELL_CORRUPTED_ANIMA, true);
                break;
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    me->GetMotionMaster()->MovePoint(POINT_2, CorruptedAnimaPosition[1]);
                    break;
                case EVENT_2:
                    me->GetMotionMaster()->MovePoint(POINT_3, CorruptedAnimaPosition[2]);
                    break;
                case EVENT_3:
                    me->GetMotionMaster()->MovePoint(POINT_4, CorruptedAnimaPosition[3]);
                    break;
                case EVENT_4:
                    me->GetMotionMaster()->MovePoint(POINT_5, CorruptedAnimaPosition[4]);
                    break;
                case EVENT_5:
                    me->GetMotionMaster()->MovePoint(POINT_6, CorruptedAnimaPosition[5]);
                    break;
                case EVENT_6:
                    me->GetMotionMaster()->MovePoint(POINT_7, CorruptedAnimaPosition[6]);
                    break;
                case EVENT_7:
                    me->GetMotionMaster()->MovePoint(POINT_8, CorruptedAnimaPosition[7]);
                    break;
                case EVENT_8:
                    me->GetMotionMaster()->MovePoint(POINT_9, CorruptedAnimaPosition[8]);
                    break;
                case EVENT_9:
                    me->GetMotionMaster()->MovePoint(POINT_10, CorruptedAnimaPosition[9]);
                    break;
                case EVENT_10:
                    me->GetMotionMaster()->MovePoint(POINT_1, CorruptedAnimaPosition[0]);
                    break;
                case EVENT_NEAR_RADEN:
                    if (Creature* raden = GetRaden())
                        if (me->GetDistance(raden) <= 3.0f)
                        {
                            me->CastSpell(raden, SPELL_CORRUPTED_ANIMA, true);
                            me->DespawnOrUnsummon(500);
                        }
                    events.ScheduleEvent(EVENT_NEAR_RADEN, 2000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_corrupted_animaAI(creature);
    }
};

class bfa_npc_corrupted_vita : public CreatureScript
{
public:
    bfa_npc_corrupted_vita() : CreatureScript("bfa_npc_corrupted_vita") { }

    struct bfa_npc_corrupted_vitaAI : public ScriptedAI
    {
        bfa_npc_corrupted_vitaAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->ApplySpellImmune(0, IMMUNITY_ID, 61391, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            //set_speed(1.5f);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        Creature* GetRaden()
        {
            return me->FindNearestCreature(BOSS_RADEN, 500.0f, true);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_MOVE_TO_RADEN:
            {
                //set_speed(0.5f);
                events.Reset();
                events.ScheduleEvent(EVENT_NEAR_RADEN, 2000);
                break;
            }
            }
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            if (damage >= me->GetHealth())
                me->CastSpell(who, 139078, true);
        }

        void MovementInform(uint32 type, uint32 id)
        {
            switch (id)
            {
            case POINT_1:
                events.ScheduleEvent(EVENT_1, 1);
                break;
            case POINT_2:
                events.ScheduleEvent(EVENT_2, 1);
                break;
            case POINT_3:
                events.ScheduleEvent(EVENT_3, 1);
                break;
            case POINT_4:
                events.ScheduleEvent(EVENT_4, 1);
                break;
            case POINT_5:
                events.ScheduleEvent(EVENT_5, 1);
                break;
            case POINT_6:
                events.ScheduleEvent(EVENT_6, 1);
                break;
            case POINT_7:
                events.ScheduleEvent(EVENT_7, 1);
                break;
            case POINT_8:
                events.ScheduleEvent(EVENT_8, 1);
                break;
            case POINT_9:
                events.ScheduleEvent(EVENT_9, 1);
                break;
            case POINT_10:
                events.ScheduleEvent(EVENT_10, 1);
                break;
            case POINT_RADEN:
                if (Creature* raden = GetRaden())
                    me->CastSpell(raden, SPELL_CORRUPTED_VITA, true);
                me->DespawnOrUnsummon(1000);
                break;
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    me->GetMotionMaster()->MovePoint(POINT_2, CorruptedVitaPosition[1]);
                    break;
                case EVENT_2:
                    me->GetMotionMaster()->MovePoint(POINT_3, CorruptedVitaPosition[2]);
                    break;
                case EVENT_3:
                    me->GetMotionMaster()->MovePoint(POINT_4, CorruptedVitaPosition[3]);
                    break;
                case EVENT_4:
                    me->GetMotionMaster()->MovePoint(POINT_5, CorruptedVitaPosition[4]);
                    break;
                case EVENT_5:
                    me->GetMotionMaster()->MovePoint(POINT_6, CorruptedVitaPosition[5]);
                    break;
                case EVENT_6:
                    me->GetMotionMaster()->MovePoint(POINT_7, CorruptedVitaPosition[6]);
                    break;
                case EVENT_7:
                    me->GetMotionMaster()->MovePoint(POINT_8, CorruptedVitaPosition[7]);
                    break;
                case EVENT_8:
                    me->GetMotionMaster()->MovePoint(POINT_9, CorruptedVitaPosition[8]);
                    break;
                case EVENT_9:
                    me->GetMotionMaster()->MovePoint(POINT_10, CorruptedVitaPosition[9]);
                    break;
                case EVENT_10:
                    me->GetMotionMaster()->MovePoint(POINT_1, CorruptedVitaPosition[0]);
                    break;
                case EVENT_NEAR_RADEN:
                    if (Creature* raden = GetRaden())
                        if (me->GetDistance(raden) <= 3.0f)
                        {
                            me->CastSpell(raden, SPELL_CORRUPTED_VITA, true);
                            me->DespawnOrUnsummon(500);
                        }
                    events.ScheduleEvent(EVENT_NEAR_RADEN, 2000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_corrupted_vitaAI(creature);
    }
};

// 138288
class bfa_spell_unstable_anima : public SpellScriptLoader
{
public:
    bfa_spell_unstable_anima() : SpellScriptLoader("bfa_spell_unstable_anima") { }

    class bfa_spell_unstable_anima_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_unstable_anima_AuraScript);

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();

            if (!caster || !target)
                return;

            if (Aura* vizual = target->AddAura(138294, target)) // visual circle
            {
                vizual->SetMaxDuration(-1);
                vizual->SetDuration(-1);
            }
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();

            if (!caster || !target)
                return;

            target->RemoveAura(138294); // visual circle
        }

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();

            if (!caster || !target)
                return;
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, caster, 8.0f);

            playerList.remove_if(PossibleGMs());
            playerList.remove_if(DeadTargets());
            playerList.remove_if(AnimaSensitivity());

            if (!playerList.empty())
                for (std::list<Player*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                {
                    if (playerList.size() > 1)
                        target->CastSpell(target, 139075, true); // on soak
                    else if (playerList.size() == 1)
                        target->CastSpell(target, 138296, true); // no targets? wipe
                }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_unstable_anima_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_unstable_anima_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_unstable_anima_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_unstable_anima_AuraScript();
    }
};

class bfa_spell_anima_explosion_players : public SpellScriptLoader
{
public:
    bfa_spell_anima_explosion_players() : SpellScriptLoader("bfa_spell_anima_explosion_players") { }

    class bfa_spell_anima_explosion_players_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_anima_explosion_players_SpellScript);

        uint8 targetsPlayers;

        bool Load()
        {
            targetsPlayers = 1;
            return true;
        }

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            targetsPlayers = targets.size();
        }

        void RecalculateDamage(SpellEffIndex effIndex)
        {
            SetHitDamage(GetHitDamage() / targetsPlayers);
        }

        void OnHit(SpellEffIndex index)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    caster->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ANIMA_SENSITIVITY, true); // temp anima explosion sensitivity
                    if (!target->HasAura(SPELL_ANIMA_SENSITIVITY))
                        caster->AddAura(SPELL_ANIMA_SENSITIVITY, target);
                    caster->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ANIMA_SENSITIVITY, false); // temp anima explosion sensitivity
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_anima_explosion_players_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_anima_explosion_players_SpellScript::CheckTargets, EFFECT_0, TARGET_SRC_CASTER);
            OnEffectHitTarget += SpellEffectFn(bfa_spell_anima_explosion_players_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            OnEffectHitTarget += SpellEffectFn(bfa_spell_anima_explosion_players_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_anima_explosion_players_SpellScript();
    }
};


class bfa_spell_murderous_strke : public SpellScriptLoader
{
public:
    bfa_spell_murderous_strke() : SpellScriptLoader("bfa_spell_murderous_strke") { }

    /*class bfa_spell_murderous_strke_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_murderous_strke_SpellScript);

        void OnHit(SpellEffIndex index)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (!caster || !target)
                        return;
                    int32 targetHealth = target->GetHealth();
                    SetHitDamage(GetHitDamage() + targetHealth);
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_murderous_strke_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    };*/

    class bfa_spell_murderous_strke_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_murderous_strke_AuraScript);

        void CalculateAmount(AuraEffect const* auraEffect, int32& amount, bool& /*canBeRecalculated*/)
        {
            Unit* target = GetCaster()->GetVictim();
            if (!target)
                return;
            amount += target->GetHealth();
        }

        void Register()
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(bfa_spell_murderous_strke_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_murderous_strke_AuraScript();
    }

    /*SpellScript* GetSpellScript() const
    {
        return new bfa_spell_murderous_strke_SpellScript();
    }*/
};

class bfa_spell_ruin_bolt : public SpellScriptLoader
{
public:
    bfa_spell_ruin_bolt() : SpellScriptLoader("bfa_spell_ruin_bolt") { }

    class bfa_spell_ruin_bolt_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_ruin_bolt_SpellScript);

        void RecalculateDamage(SpellEffIndex effIndex)
        {
            SetHitDamage(1000000);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_ruin_bolt_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_ruin_bolt_SpellScript();
    }
};

class bfa_spell_fatal_strike : public SpellScriptLoader
{
public:
    bfa_spell_fatal_strike() : SpellScriptLoader("bfa_spell_fatal_strike") { }

    class bfa_spell_fatal_strike_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_fatal_strike_SpellScript);

        void RecalculateDamage(SpellEffIndex effIndex)
        {
            Unit* target = GetHitUnit();
            if (!target)
                return;

            if (target->HasAura(132402) || target->HasAura(77535) || target->HasAura(115307) || target->HasAura(132403) || target->HasAura(132404))
                SetHitDamage(1);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_fatal_strike_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_fatal_strike_SpellScript();
    }
};

void AddSC_bfa_boss_raden()
{
    new bfa_boss_ra_den;
    new bfa_npc_crackling_stalker;
    new bfa_npc_essence_of_anima;
    new bfa_npc_essence_of_vita;
    new bfa_npc_sanguine_horror;
    new bfa_npc_corrupted_anima;
    new bfa_npc_corrupted_vita;

    new bfa_spell_materials_of_creation;
    new bfa_spell_unstable_vita;
    new bfa_spell_anima_explosion_players;
    new bfa_spell_unstable_vita_damage;
    new bfa_spell_unstable_anima;
    new bfa_spell_ruin_bolt;
    new bfa_spell_fatal_strike;
    new bfa_spell_murderous_strke;
}
