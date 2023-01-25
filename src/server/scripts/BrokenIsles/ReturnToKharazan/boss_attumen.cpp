#include "new_karazhan.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_INTANGIBLE_PRESENCE = 1,
    SAY_RIDERLESS = 2,
    SAY_DEATH = 3,
    SAY_MIGHTY_STOMP = 4,
};

enum Spells
{
    ///Midnight
    SPELL_STAMP_VISUAL = 227640,
    SPELL_INTANGIBLE_PRESENCE = 227404,
    SPELL_INTANGIBLE_PRESENCE_VIS_1 = 227436,
    SPELL_INTANGIBLE_PRESENCE_VIS_2 = 227437, //Random target
    SPELL_INTANGIBLE_PRESENCE_DMG = 227415,
    SPELL_INTANGIBLE_PRESENCE_DMG_2 = 227419,
    SPELL_MIGHTY_STOMP = 227363,
    SPELL_SPECTRAL_CHARGE = 227587,
    SPELL_SPECTRAL_CHARGE_AT = 227367,

    SPELL_SHIMMERING = 227422,

    //Phase 2
    SPELL_RIDERLESS = 227338,
    SPELL_MEZAIR = 227339,

    SPELL_ENRAGE = 228895,

    ///Attumen
    SPELL_MOUNTED_STRIKE = 227636,
    SPELL_ANIM_DISMOUNTED = 227474, //bug anim
    SPELL_MORTAL_STRIKE = 227493,
    SPELL_STAMP = 227638,
    SPELL_SHARED_SUFFERING = 228852,
    SPELL_FEIGN_DEATH = 114371,
};

enum eEvents
{
    ///Midnight
    EVENT_INTANGIBLE_PRESENCE = 1,
    EVENT_MIGHTY_STOMP = 2,
    EVENT_SPECTRAL_CHARGE = 3,

    //Phase 2
    EVENT_CHECK_HEALTH = 4,
    EVENT_MEZAIR = 5,
    EVENT_MOVING_TO_HUNTSMAN = 6,

    ///Attumen
    EVENT_MORTAL_STRIKE = 1,
    EVENT_SHARED_SUFFERING = 2,
    EVENT_CHECK_VICTIM = 3,
};

enum ePhase
{
    PHASE_1 = 0,
    PHASE_2
};

enum Actions
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
    ACTION_4,
    ACTION_5,

    EVENT_1,
    EVENT_2,
};

//114264
class boss_rtk_midnight : public CreatureScript
{
public:
    boss_rtk_midnight() : CreatureScript("boss_rtk_midnight") {}

    struct boss_rtk_midnightAI : public BossAI
    {
        boss_rtk_midnightAI(Creature* creature) : BossAI(creature, DATA_MIDNIGHT), summons(me) {}

        SummonList summons;
        bool attumenSpawnRide = false;
        bool phaseRiderless = false;
        bool attumenDied = false;
        uint8 spectralCount = 0;

        void Reset() override
        {
            _Reset();
            summons.DespawnAll();
            attumenSpawnRide = false;
            phaseRiderless = false;
            attumenDied = false;
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
            me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_PASSIVE);

            if (me)
                if (auto attumen = me->SummonCreature(NPC_ATTUMEN_THE_HUNTSMAN, me->GetPosition()))
                    attumen->EnterVehicle(me);
        }

        void JustEngagedWith(Unit* /*who*/) override //58:42
        {
            _JustEngagedWith();
            DefaultEvents(PHASE_1);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            summons.DespawnEntry(NPC_INTANGIBLE_PRESSENCE);

            EntryCheckPredicate pred(NPC_ATTUMEN_THE_HUNTSMAN);
            summons.DoAction(ACTION_5, pred);
        }

        void EnterEvadeMode(EvadeReason w)
        {
            me->NearTeleportTo(me->GetHomePosition());
            me->RemoveAurasDueToSpell(SPELL_ENRAGE);
            me->RemoveAurasDueToSpell(SPELL_RIDERLESS);
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

        void PassengerBoarded(Unit* passenger, int8 /*seatID*/, bool apply) override
        {
            if (!apply || passenger == nullptr)
                return;

            if (!attumenSpawnRide && passenger->GetEntry() == NPC_ATTUMEN_THE_HUNTSMAN)
            {
                attumenSpawnRide = true;
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);
            }
        }

        void DefaultEvents(uint8 phaseEvent)
        {
            events.Reset();

            switch (phaseEvent)
            {
            case PHASE_1:
                events.RescheduleEvent(EVENT_INTANGIBLE_PRESENCE, 6000);
                events.RescheduleEvent(EVENT_MIGHTY_STOMP, 14000);
                //events.RescheduleEvent(EVENT_SPECTRAL_CHARGE, 47000); //47s
                break;
            case PHASE_2:
                events.RescheduleEvent(EVENT_CHECK_HEALTH, 1000);
                events.RescheduleEvent(EVENT_MEZAIR, 3000);
                break;
            }
        }

        void SpellFinishCast(const SpellInfo* spell)
        {
            if (spectralCount < 3 && spell->Id == SPELL_SPECTRAL_CHARGE)
            {
                spectralCount++;

                Position pos1, pos2;
                float angle = frand(0.0f, 6.28f);
                float angle2 = angle + M_PI;
                float dist = 5.0f;
                float dist2 = 5.0f;

                for (uint8 i = 0; i < 11; i++)
                {
                    me->GetNearPosition(dist, angle + frand(-3.14f / 2.0f, 3.14f / 2.0f));
                    me->CastSpell(pos1, SPELL_SPECTRAL_CHARGE_AT, true);
                    dist += 4;
                }

                for (uint8 i = 0; i < 6; i++)
                {
                    me->GetNearPosition(dist, angle2 + frand(-3.14f / 2.0f, 3.14f / 2.0f));
                    me->CastSpell(pos2, SPELL_SPECTRAL_CHARGE_AT, true);
                    dist2 += 4;
                }
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if ((me->HealthBelowPct(51) || damage >= me->GetHealth()) && !attumenDied)
            {
                damage = 0;
                me->SetHealth(me->CountPctFromMaxHealth(50));

                if (!phaseRiderless)
                {
                    phaseRiderless = true;
                    me->AttackStop();
                    DoCast(me, SPELL_RIDERLESS, true);
                    DefaultEvents(PHASE_2);
                    EntryCheckPredicate pred(NPC_ATTUMEN_THE_HUNTSMAN);
                    summons.DoAction(ACTION_1, pred);
                }
            }
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_INTANGIBLE_PRESENCE_VIS_1)
            {
                if (Creature* summon = me->SummonCreature(NPC_INTANGIBLE_PRESSENCE, target->GetPosition()))
                {
                    summon->CastSpell(target, 46598, true);
                    summon->CastSpell(summon, SPELL_SHIMMERING, true);
                }
            }
        }

        void DoAction(int32 const action) override
        {
            if (action == ACTION_1)
            {
                phaseRiderless = true;
                attumenDied = true;
                events.Reset();
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveAurasDueToSpell(SPELL_RIDERLESS);
                DoCast(me, SPELL_ENRAGE, true);
                DefaultEvents(PHASE_1);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == 1003) // charge - SPELL_MEZAIR
                events.RescheduleEvent(EVENT_MOVING_TO_HUNTSMAN, 500);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_INTANGIBLE_PRESENCE:
                {
                    EntryCheckPredicate pred(NPC_ATTUMEN_THE_HUNTSMAN);
                    summons.DoAction(ACTION_3, pred); //Talk
                    DoCast(SPELL_INTANGIBLE_PRESENCE);
                    events.RescheduleEvent(EVENT_INTANGIBLE_PRESENCE, 58000);
                    break;
                }
                case EVENT_MIGHTY_STOMP:
                {
                    EntryCheckPredicate pred(NPC_ATTUMEN_THE_HUNTSMAN);
                    summons.DoAction(ACTION_4, pred); //Talk
                    DoCast(SPELL_MIGHTY_STOMP);
                    events.RescheduleEvent(EVENT_MIGHTY_STOMP, 14000);
                    break;
                }
                case EVENT_SPECTRAL_CHARGE:
                    spectralCount = 0;
                    DoCast(SPELL_SPECTRAL_CHARGE);
                    events.RescheduleEvent(EVENT_SPECTRAL_CHARGE, 47000);
                    break;
                case EVENT_CHECK_HEALTH:
                {
                    if (me->GetHealthPct() == 100)
                    {
                        phaseRiderless = false;
                        EntryCheckPredicate pred(NPC_ATTUMEN_THE_HUNTSMAN);
                        summons.DoAction(ACTION_2, pred);
                        me->RemoveAurasDueToSpell(SPELL_RIDERLESS);
                        me->SetReactState(REACT_AGGRESSIVE);
                        DefaultEvents(PHASE_1);
                        break;
                    }
                    events.RescheduleEvent(EVENT_CHECK_HEALTH, 1000);
                    break;
                }
                case EVENT_MEZAIR:
                    me->StopMoving();
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                    {
                        me->SetFacingToObject(target);
                        me->CastSpell(target, SPELL_MEZAIR, false);
                    }
                    events.RescheduleEvent(EVENT_MEZAIR, 6000);
                    break;
                case EVENT_MOVING_TO_HUNTSMAN:
                    if (Creature* huntsman = me->FindNearestCreature(NPC_ATTUMEN_THE_HUNTSMAN, 80.0f))
                    {
                        Position pos;
                        huntsman->GetNearPosition(6.0f, frand(0.0f, 6.28f));
                        me->GetMotionMaster()->MovePoint(1, pos);
                    }
                    break;
                }
            }

            if (!phaseRiderless)
                DoSpellAttackIfReady(SPELL_STAMP_VISUAL);
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_rtk_midnightAI(creature);
    }
};

//114262
class npc_attumen_the_huntsman : public CreatureScript
{
public:
    npc_attumen_the_huntsman() : CreatureScript("npc_attumen_the_huntsman") {}

    struct npc_attumen_the_huntsmanAI : public ScriptedAI
    {
        npc_attumen_the_huntsmanAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;
        bool ride = true;
        bool fakeDied = false;

        void Reset() override
        {
            events.Reset();
            ride = true;
            fakeDied = false;
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            events.RescheduleEvent(EVENT_CHECK_VICTIM, 1000);
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
            case ACTION_1:
                if (me->IsAlive())
                    Talk(SAY_RIDERLESS);
                ride = false;
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                events.RescheduleEvent(EVENT_MORTAL_STRIKE, 10000);
                events.RescheduleEvent(EVENT_SHARED_SUFFERING, 18000);
                break;
            case ACTION_2:
                ride = true;
                events.Reset();
                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                if (Unit* owner = me->GetOwner())
                    DoCast(owner, 46598, true); //Ride veh
                break;
            case ACTION_3:
                if (me->IsAlive())
                    Talk(SAY_INTANGIBLE_PRESENCE);
                break;
            case ACTION_4:
                if (me->IsAlive())
                    Talk(SAY_MIGHTY_STOMP);
                break;
            case ACTION_5:
                Talk(SAY_DEATH);
                me->Kill(me,me);
                break;
            }
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_MOUNTED_STRIKE)
                me->CastSpell(target, SPELL_STAMP, TriggerCastFlags(TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE));
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                me->SetHealth(me->CountPctFromMaxHealth(1));

                if (!fakeDied)
                {
                    fakeDied = true;
                    me->AttackStop();
                    me->RemoveAllAuras();
                    me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                    me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                    DoCast(me, SPELL_FEIGN_DEATH, true);

                    if (auto owner = me->GetOwner())
                    {
                        if (owner->IsAlive())
                            owner->GetAI()->DoAction(ACTION_1);
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MORTAL_STRIKE:
                    DoCastVictim(SPELL_MORTAL_STRIKE);
                    events.RescheduleEvent(EVENT_MORTAL_STRIKE, 16000);
                    break;
                case EVENT_SHARED_SUFFERING:
                    DoCast(SPELL_SHARED_SUFFERING);
                    events.RescheduleEvent(EVENT_SHARED_SUFFERING, 18000);
                    break;
                case EVENT_CHECK_VICTIM:
                    if (ride)
                    {
                        if (Unit* owner = me->GetOwner())
                        {
                            if (owner->GetVictim() && me->GetVictim() && owner->GetVictim() != me->GetVictim())
                            {
                               //DoResetThreat();
                                //me->AddThreat(owner->GetVictim(), 10000.0f);
                            }
                        }
                    }
                    events.RescheduleEvent(EVENT_CHECK_VICTIM, 1000);
                    break;
                }
            }

            if (me->GetVehicleCreatureBase())
                DoSpellAttackIfReady(SPELL_MOUNTED_STRIKE);
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_attumen_the_huntsmanAI(creature);
    }
};

//114315
class npc_rtk_intangible_pressence : public CreatureScript
{
public:
    npc_rtk_intangible_pressence() : CreatureScript("npc_rtk_intangible_pressence") {}

    struct npc_rtk_intangible_pressenceAI : public ScriptedAI
    {
        npc_rtk_intangible_pressenceAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void Reset() override
        {
            events.RescheduleEvent(EVENT_1, 3000);
            events.RescheduleEvent(EVENT_2, 500);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    me->CastSpell(me, SPELL_INTANGIBLE_PRESENCE_DMG, TriggerCastFlags(TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE));
                    events.RescheduleEvent(EVENT_1, 3000);
                    break;
                case EVENT_2:
                    if (!me->GetVehicleBase())
                    {
                        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INTANGIBLE_PRESENCE);
                        me->DespawnOrUnsummon(100);
                        break;
                    }
                    events.RescheduleEvent(EVENT_2, 500);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_rtk_intangible_pressenceAI(creature);
    }
};

//227404
class spell_rtk_intangible_presence : public SpellScriptLoader
{
public:
    spell_rtk_intangible_presence() : SpellScriptLoader("spell_rtk_intangible_presence") {}

    class spell_rtk_intangible_presence_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rtk_intangible_presence_SpellScript);

        uint8 targetCount = 0;
        uint8 randTarget = 1;

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            for (auto const& target : targets)
            {
                if (target->ToPlayer() && target->ToPlayer()->HasAura(SPELL_INTANGIBLE_PRESENCE))
                    target->ToPlayer()->RemoveAurasDueToSpell(SPELL_INTANGIBLE_PRESENCE);
            }
            if (targets.size() > 1)
                randTarget = urand(1, targets.size());
        }

        void HandleAfterHit()
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            targetCount++;

            if (randTarget == targetCount)
                GetCaster()->CastSpell(GetHitUnit(), SPELL_INTANGIBLE_PRESENCE_VIS_1, true);
            else
                GetCaster()->CastSpell(GetHitUnit(), SPELL_INTANGIBLE_PRESENCE_VIS_2, true);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_rtk_intangible_presence_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            AfterHit += SpellHitFn(spell_rtk_intangible_presence_SpellScript::HandleAfterHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rtk_intangible_presence_SpellScript();
    }

    class spell_rtk_intangible_presence_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rtk_intangible_presence_AuraScript);

        void HandleDispel(DispelInfo* dispelInfo)
        {
            if (Unit* owner = GetUnitOwner())
                if (Vehicle* veh = owner->GetVehicleKit())
                        owner->CastSpell(owner, SPELL_INTANGIBLE_PRESENCE_DMG_2, true);
        }

        void Register() override
        {
            OnDispel += AuraDispelFn(spell_rtk_intangible_presence_AuraScript::HandleDispel);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rtk_intangible_presence_AuraScript();
    }
};

void AddSC_boss_attumen_new()
{
    new boss_rtk_midnight();
    new npc_attumen_the_huntsman();
    new npc_rtk_intangible_pressence();
    new spell_rtk_intangible_presence();
}
