#include "new_karazhan.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_AGGRO_2 = 1,
    SAY_COMMAND_FEL_BEAM = 2,
    SAY_COMMAND_FEL_BEAM_WARN = 3,
    SAY_DEMONIC_PORTAL = 4,
    SAY_DEMONIC_PORTAL_WARN = 5,
    SAY_MOVING_TO_SHIP = 6,
    SAY_MOVING_TO_SHIP_2 = 7,
    SAY_STABILIZE_RIFT = 8,
    SAY_DEATH = 9,
};

enum Spells
{
    SPELL_BURNING_BLAST = 229083,
    SPELL_COMMAND_FEL_BEAM = 229242,
    SPELL_FEL_BEAM_AT = 229244, //Dmg 229248
    SPELL_FEL_FLAMES_AT = 229249, //Dmg 229250
    SPELL_COMMAND_BOMBARDMENT = 229284,
    SPELL_DISINTEGRATE_FILTER = 229153,
    SPELL_DISINTEGRATE = 229151,
    SPELL_CHAOTIC_SHADOWS = 229159,

    SPELL_SOUL_HARVEST = 229906,
    SPELL_STABILIZE_RIFT = 230084,

    SPELL_LEGION_SPAWN = 230280,

    //Change phase
    SPELL_DEMONIC_PORTAL_SUM = 229607,
    SPELL_DEMONIC_PORTAL_AT = 229610, //Fly Auras from player: 229599
    SPELL_DEMONIC_PORTAL_SCALE = 229598,

    //Summons
    SPELL_BOMBARDMENT_AURA_1 = 229287,
    SPELL_BOMBARDMENT_AURA_2 = 229288,

    //Khadgar & Medivh
    SPELL_ENERGY_PORTAL_SPAWN = 229651, //Medivh
    SPELL_RAVEN_FORM = 229645, //Khadgar
};

enum eEvents
{
    EVENT_BURNING_BLAST = 1,
    EVENT_COMMAND_FEL_BEAM = 2,
    EVENT_DISINTEGRATE = 3,
    EVENT_CHAOTIC_SHADOWS = 4,
    EVENT_COMMAND_BOMBARDMENT = 5,
    EVENT_DEMONIC_PORTAL_1 = 6,
    EVENT_DEMONIC_PORTAL_2 = 7,
    EVENT_DEMONIC_PORTAL_3 = 8,
    EVENT_CHECK_PLAYER = 9,
    EVENT_STABILIZE_RIFT = 10,
    EVENT_SUMMON_GUARD = 11,

    EVENT_1,
    EVENT_2,
};

enum ePhase
{
    PHASE_1 = 1,
    PHASE_2 = 2,
    PHASE_3 = 3,
    PHASE_CHANGE,
};

//114790
class boss_vizaduum_the_watcher : public CreatureScript
{
public:
    boss_vizaduum_the_watcher() : CreatureScript("boss_vizaduum_the_watcher") {}

    struct boss_vizaduum_the_watcherAI : public BossAI
    {
        boss_vizaduum_the_watcherAI(Creature* creature) : BossAI(creature, DATA_VIZADUUM)
        {
            _introDone1 = false;
            _introDone2 = false;
        }

        ObjectGuid CannonTargetGUID;
        bool _introDone1, _introDone2;
        bool eventCheckPlayer = false;
        uint8 evadePhase;
        uint8 vPhase;
        uint8 healthPct;
        uint16 sumGuardTimer;

        void Reset() override
        {
            _Reset();
            me->SetReactState(REACT_AGGRESSIVE);
            eventCheckPlayer = false;
            evadePhase = 1;
            vPhase = 1;
            healthPct = 66;
            sumGuardTimer = 3000;

            for (uint8 i = 0; i < 3; i++)
                me->SummonCreature(NPC_COMMAND_SHIP, commandPos[i]);

            for (uint8 i = 0; i < 4; i++)
            {
                if (Creature* summon = me->SummonCreature(NPC_SOUL_HARVESTER, harvestPos[i]))
                    summon->CastSpell(summon, SPELL_SOUL_HARVEST, true);
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            Talk(SAY_AGGRO_2);
            _JustEngagedWith();

            DefaultEvent(PHASE_1);
        }

        void EnterEvadeMode(EvadeReason w)
        {
            BossAI::EnterEvadeMode();
            me->GetMotionMaster()->MoveIdle();
            me->NearTeleportTo(3657.5f, -2125.8f, 815.681f, 4.99f); //Home
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!_introDone1 && me->IsWithinDistInMap(who, 155.0f))
            {
                _introDone1 = true;
                if (Creature* mediv = me->SummonCreature(116124, 3743.72f, -2237.46f, 812.86f, 5.65f))
                    mediv->CastSpell(mediv, 229650);
                if (Creature* khadgar = me->SummonCreature(116259, 3751.08f, -2247.26f, 808.20f, 2.46f))
                    khadgar->CastSpell(khadgar, 229650);
            }
            if (!_introDone2 && me->IsWithinDistInMap(who, 90.0f))
            {
                _introDone2 = true;
                who->CastSpell(who, 184104);
            }
        }

        void DefaultEvent(uint8 phase)
        {
            events.Reset();

            switch (phase)
            {
            case PHASE_1:
                events.RescheduleEvent(EVENT_BURNING_BLAST, 2000);
                events.RescheduleEvent(EVENT_COMMAND_FEL_BEAM, 6000);
                events.RescheduleEvent(EVENT_DISINTEGRATE, 11000);
                events.RescheduleEvent(EVENT_CHAOTIC_SHADOWS, 16000);
                events.RescheduleEvent(EVENT_COMMAND_BOMBARDMENT, 26000);
                break;
            case PHASE_2:
                events.RescheduleEvent(EVENT_BURNING_BLAST, 2000);
                events.RescheduleEvent(EVENT_DISINTEGRATE, 11000);
                events.RescheduleEvent(EVENT_CHAOTIC_SHADOWS, 16000);
                events.RescheduleEvent(EVENT_COMMAND_BOMBARDMENT, 26000);
                break;
            case PHASE_3:
                events.RescheduleEvent(EVENT_BURNING_BLAST, 2000);
                events.RescheduleEvent(EVENT_DISINTEGRATE, 11000);
                events.RescheduleEvent(EVENT_CHAOTIC_SHADOWS, 16000);
                events.RescheduleEvent(EVENT_SUMMON_GUARD, 2000);
                break;
            case PHASE_CHANGE:
                if (healthPct == 33)
                    Talk(SAY_DEMONIC_PORTAL);
                events.RescheduleEvent(EVENT_DEMONIC_PORTAL_1, 1000);
                break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_VIZADUUM_HP_PHASE:
                return healthPct;
            case DATA_VIZADUUM_PHASE:
                return vPhase;
            }
            return 0;
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_DISINTEGRATE_FILTER:
            {
                me->SetFacingToObject(target);
                if (vPhase >= 2)
                    me->CastSpell(target, SPELL_DISINTEGRATE, false);
                else
                    DoCast(target, SPELL_DISINTEGRATE);
                break;
            }
            case SPELL_COMMAND_BOMBARDMENT:
                target->CastSpell(target, SPELL_BOMBARDMENT_AURA_1, true);
                target->CastSpell(target, SPELL_BOMBARDMENT_AURA_2, true);
                break;
            case SPELL_STABILIZE_RIFT:
                Talk(SAY_STABILIZE_RIFT);
                target->CastSpell(target, 230086, true); //Visual
                break;
            }
        }

        void SpellFinishCast(const SpellInfo* spell)
        {
            switch (spell->Id)
            {
            case SPELL_DISINTEGRATE:
                if (!eventCheckPlayer)
                    me->SetReactState(REACT_AGGRESSIVE);
                break;
            }
        }

        void OnInterruptCast(Unit* /*caster*/, uint32 /*spellId*/, uint32 curSpellID, uint32 /*schoolMask*/)
        {
            if (curSpellID == SPELL_STABILIZE_RIFT)
                sumGuardTimer = 30000;
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (me->HealthBelowPct(healthPct))
            {
                vPhase = healthPct == 66 ? 2 : 3;
                healthPct == 66 ? healthPct = 33 : healthPct = 0;
                me->AttackStop();
                DefaultEvent(PHASE_CHANGE);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == WAYPOINT_MOTION_TYPE)
            {
                if (id == 6 && healthPct || id == 7 && !healthPct)
                {
                    if (id == 6 && healthPct)
                        evadePhase = 2;
                    else if (id == 7 && !healthPct)
                        evadePhase = 3;

                    ResetThreat(me);
                    me->SetCanFly(false);
                    me->RemoveAurasDueToSpell(SPELL_DEMONIC_PORTAL_SCALE);
                    events.RescheduleEvent(EVENT_CHECK_PLAYER, 1000);
                    eventCheckPlayer = true;

                    if (!healthPct)
                    {
                        me->SetFacingTo(1.1f);
                        events.RescheduleEvent(EVENT_STABILIZE_RIFT, 2000);

                        for (uint8 i = 2; i < 8; i++)
                            me->SummonCreature(NPC_FELGUARD_SENTRY, guardPos[i]);

                        for (uint8 i = 0; i < 4; i++)
                            me->SummonCreature(NPC_SHADOW_SPITTER, spitterPos[i]);
                    }
                    else
                        me->SetFacingTo(5.61f);
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
                case EVENT_BURNING_BLAST:
                    DoCastVictim(SPELL_BURNING_BLAST);
                    events.RescheduleEvent(EVENT_BURNING_BLAST, 5000);
                    break;
                case EVENT_COMMAND_FEL_BEAM:
                    CannonTargetGUID.Clear();
                    Talk(SAY_COMMAND_FEL_BEAM);
                    DoCast(SPELL_COMMAND_FEL_BEAM);
                    events.RescheduleEvent(EVENT_COMMAND_FEL_BEAM, 40000);
                    break;
                case EVENT_DISINTEGRATE:
                    me->AttackStop();
                    DoCast(SPELL_DISINTEGRATE_FILTER);
                    events.RescheduleEvent(EVENT_DISINTEGRATE, 11000);
                    break;
                case EVENT_CHAOTIC_SHADOWS:
                    DoCast(SPELL_CHAOTIC_SHADOWS);
                    events.RescheduleEvent(EVENT_CHAOTIC_SHADOWS, 30000);
                    break;
                case EVENT_COMMAND_BOMBARDMENT:
                    DoCast(SPELL_COMMAND_BOMBARDMENT);
                    events.RescheduleEvent(EVENT_COMMAND_BOMBARDMENT, 25000);
                    break;
                case EVENT_DEMONIC_PORTAL_1:
                {
                    //DoCast(me, SPELL_DEMONIC_PORTAL_SUM, true);
                    //>>> HACK!!!
                    float x, y, z;
                    me->GetClosePoint(x, y, z, me->GetObjectSize(), 4.0f);
                    me->SummonCreature(NPC_DEMONIC_PORTAL, x, y, me->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 10000);
                    Talk(SAY_DEMONIC_PORTAL_WARN);
                    ///<<<
                    events.RescheduleEvent(EVENT_DEMONIC_PORTAL_2, 500);
                    break;
                }
                case EVENT_DEMONIC_PORTAL_2:
                    me->CastSpell(me, SPELL_DEMONIC_PORTAL_AT, true);
                    events.RescheduleEvent(EVENT_DEMONIC_PORTAL_3, 3000);
                    break;
                case EVENT_DEMONIC_PORTAL_3:
                    evadePhase = 0;
                    me->SetCanFly(true);
                    me->CastSpell(me, SPELL_DEMONIC_PORTAL_SCALE, true);
                    if (healthPct == 33)
                        Talk(SAY_MOVING_TO_SHIP);
                    else if (healthPct == 0)
                        Talk(SAY_MOVING_TO_SHIP_2);
                    if (healthPct)
                        me->GetMotionMaster()->MovePath(me->GetEntry() * 100, false);
                    else
                        me->GetMotionMaster()->MovePath(me->GetEntry() * 100 + 1, false);
                    break;
                case EVENT_CHECK_PLAYER:
                    if (Unit* target = SelectTarget(SELECT_TARGET_MINDISTANCE, 0, 30.0f, true, false))
                    {
                        me->InterruptNonMeleeSpells(false);
                        AddThreat(target, 1000.0f);
                        me->SetReactState(REACT_AGGRESSIVE);
                        DefaultEvent(healthPct ? PHASE_2 : PHASE_3);
                        eventCheckPlayer = false;
                    }
                    else
                    {
                        if (healthPct)
                            me->CastSpell(me, SPELL_DISINTEGRATE, false);
                        events.RescheduleEvent(EVENT_CHECK_PLAYER, 3000);
                    }
                    break;
                case EVENT_STABILIZE_RIFT:
                    DoCast(SPELL_STABILIZE_RIFT);
                    break;
                case EVENT_SUMMON_GUARD:
                    for (uint8 i = 0; i < 2; i++)
                    {
                        if (Creature* summon = me->SummonCreature(NPC_FELGUARD_SENTRY, guardPos[i]))
                        {
                            summon->CastSpell(summon, SPELL_LEGION_SPAWN, true);
                            summon->AI()->DoZoneInCombat(summon, 200.0f);
                        }
                    }
                    events.RescheduleEvent(EVENT_SUMMON_GUARD, sumGuardTimer);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_vizaduum_the_watcherAI(creature);
    }
};

//115274
class npc_vizaduum_fel_cannon : public CreatureScript
{
public:
    npc_vizaduum_fel_cannon() : CreatureScript("npc_vizaduum_fel_cannon") {}

    struct npc_vizaduum_fel_cannonAI : public ScriptedAI
    {
        npc_vizaduum_fel_cannonAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            me->SetReactState(REACT_PASSIVE);
        }

        InstanceScript* instance;
        EventMap events;
        ObjectGuid targetGUID;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            if (Creature* boss = instance->instance->GetCreature(instance->GetGuidData(NPC_VIZADUUM_THE_WATCHER)))
                targetGUID = boss->GetAI()->GetGUID(DATA_CANNON_TARGET_GUID);

            events.RescheduleEvent(EVENT_1, 1000);
            events.RescheduleEvent(EVENT_2, 2000);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    if (Unit* summoner = me->GetOwner())
                        summoner->CastSpell(me, SPELL_FEL_BEAM_AT, true);
                    break;
                case EVENT_2:
                    if (Unit* player = me->GetVictim())
                        me->GetMotionMaster()->MovePoint(1, player->GetPosition());
                    else
                    {
                        me->DespawnOrUnsummon(100);
                        break;
                    }
                    events.RescheduleEvent(EVENT_2, 1000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_vizaduum_fel_cannonAI(creature);
    }
};

//115734
class npc_vizaduum_shadow_spitter : public CreatureScript
{
public:
    npc_vizaduum_shadow_spitter() : CreatureScript("npc_vizaduum_shadow_spitter") {}

    struct npc_vizaduum_shadow_spitterAI : public ScriptedAI
    {
        npc_vizaduum_shadow_spitterAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetCanFly(true);
        }

        EventMap events;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            events.RescheduleEvent(EVENT_1, 3000);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    if (!me->IsInCombat())
                        DoZoneInCombat(me, 200.0f);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                    {
                        me->SetFacingToObject(target);
                        DoCast(target, 230066, true);
                    }
                    events.RescheduleEvent(EVENT_1, 5000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_vizaduum_shadow_spitterAI(creature);
    }
};

//115497, 114463
class npc_archmage_khadgar_medivh_vizaduum : public CreatureScript
{
public:
    npc_archmage_khadgar_medivh_vizaduum() : CreatureScript("npc_archmage_khadgar_medivh_vizaduum") {}

    struct npc_archmage_khadgar_medivh_vizaduumAI : public ScriptedAI
    {
        npc_archmage_khadgar_medivh_vizaduumAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        EventMap events;

        void Reset() override
        {
            switch (me->GetEntry())
            {
            case NPC_ARCHMAGE_KHADGAR_VIZADUUM:
                events.RescheduleEvent(EVENT_1, 3000);
                DelayTalk(me, 4, 0, nullptr);
                DelayTalk(me, 24, 1, nullptr);
                DelayTalk(me, 43, 2, nullptr);
                DelayTalk(me, 76, 3, nullptr);
                events.RescheduleEvent(EVENT_2, 80000);
                break;
            case NPC_MEDIVH_VIZADUUM:
                DelayTalk(me, 15, 0, nullptr);
                DelayTalk(me, 30, 1, nullptr);
                DelayTalk(me, 49, 2, nullptr);
                DelayTalk(me, 55, 3, nullptr);
                DelayTalk(me, 67, 4, nullptr);
                break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    me->RemoveAurasDueToSpell(SPELL_RAVEN_FORM);
                    break;
                case EVENT_2:
                    DoCast(me, 196978, true);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_archmage_khadgar_medivh_vizaduumAI(creature);
    }
};

//115493
class npc_vizaduum_demonic_portal : public CreatureScript
{
public:
    npc_vizaduum_demonic_portal() : CreatureScript("npc_vizaduum_demonic_portal") {}

    struct npc_vizaduum_demonic_portalAI : public ScriptedAI
    {
        npc_vizaduum_demonic_portalAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        uint32 timer = 0;

        void Reset() override
        {
            if (!me->GetOwner())
                timer = 31000;
        }

        void UpdateAI(uint32 diff) override
        {
            if (timer)
            {
                if (timer <= diff)
                {
                    timer = 31000;
                    DoCast(me, 229591, true);
                }
                else
                    timer -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_vizaduum_demonic_portalAI(creature);
    }
};

//229241
class spell_vizaduum_acquiring_target : public SpellScriptLoader
{
public:
    spell_vizaduum_acquiring_target() : SpellScriptLoader("spell_vizaduum_acquiring_target") {}

    class spell_vizaduum_acquiring_target_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_vizaduum_acquiring_target_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (GetHitUnit())
            {
                if (InstanceScript* instance = GetHitUnit()->GetInstanceScript())
                    if (Creature* boss = instance->instance->GetCreature(instance->GetGuidData(NPC_VIZADUUM_THE_WATCHER)))
                        boss->AI()->SetGUID(GetHitUnit()->GetGUID(), DATA_CANNON_TARGET_GUID);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_vizaduum_acquiring_target_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_vizaduum_acquiring_target_SpellScript();
    }
};

//229286
class spell_vizaduum_bombardment : public SpellScriptLoader
{
public:
    spell_vizaduum_bombardment() : SpellScriptLoader("spell_vizaduum_bombardment") {}

    class spell_vizaduum_bombardment_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_vizaduum_bombardment_SpellScript);

        void HandleTriggerEffect(SpellEffIndex effIndex)
        {
            Position pos;

            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                if (Creature* boss = instance->instance->GetCreature(instance->GetGuidData(NPC_VIZADUUM_THE_WATCHER)))
                {
                    if (boss->GetAI()->GetData(DATA_VIZADUUM_HP_PHASE) == 66)
                        pos = { 3666.64f, -2159.92f, 815.59f };
                    else if (boss->GetAI()->GetData(DATA_VIZADUUM_HP_PHASE) == 33)
                        pos = { 3943.07f, -1993.89f, 926.76f };
                }

        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_vizaduum_bombardment_SpellScript::HandleTriggerEffect, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_vizaduum_bombardment_SpellScript();
    }
};

//229599
class spell_vizaduum_demonic_portal : public SpellScriptLoader
{
public:
    spell_vizaduum_demonic_portal() : SpellScriptLoader("spell_vizaduum_demonic_portal") { }

    class spell_vizaduum_demonic_portal_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_vizaduum_demonic_portal_AuraScript);

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (Player* player = GetTarget()->ToPlayer())
            {
                bool alive = true;
                uint8 eventPhaseHP = 0;

                if (InstanceScript* instance = player->GetInstanceScript())
                {
                    if (Creature* boss = instance->instance->GetCreature(instance->GetGuidData(NPC_VIZADUUM_THE_WATCHER)))
                    {
                        if (boss->IsAlive())
                            eventPhaseHP = boss->GetAI()->GetData(DATA_VIZADUUM_HP_PHASE);
                        else
                            alive = false;
                    }
                }
                player->GetMotionMaster()->MoveIdle();

                if (alive)
                    player->GetMotionMaster()->MovePath(eventPhaseHP ? 11479002 : 11479003, false);
                else
                    player->GetMotionMaster()->MovePath(11479004, false);
            }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_vizaduum_demonic_portal_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_vizaduum_demonic_portal_AuraScript();
    }
};

//229159
class spell_vizaduum_chaotic_shadows : public SpellScriptLoader
{
public:
    spell_vizaduum_chaotic_shadows() : SpellScriptLoader("spell_vizaduum_chaotic_shadows") { }

    class spell_vizaduum_chaotic_shadows_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_vizaduum_chaotic_shadows_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            switch (GetCaster()->GetMap()->GetDifficultyID())
            {
            case DIFFICULTY_MYTHIC:
            case DIFFICULTY_MYTHIC_KEYSTONE:
                Trinity::Containers::RandomResize(targets, GetCaster()->GetAI()->GetData(DATA_VIZADUUM_PHASE));
                break;
            default:
                Trinity::Containers::RandomResize(targets, 1);
                break;
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_vizaduum_chaotic_shadows_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_vizaduum_chaotic_shadows_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_vizaduum_chaotic_shadows_SpellScript();
    }
};

void AddSC_boss_vizaduum()
{
    new boss_vizaduum_the_watcher();
    new npc_vizaduum_fel_cannon();
    new npc_vizaduum_shadow_spitter();
    new npc_archmage_khadgar_medivh_vizaduum();
    new npc_vizaduum_demonic_portal();
    new spell_vizaduum_acquiring_target();
    new spell_vizaduum_bombardment();
    new spell_vizaduum_demonic_portal();
    new spell_vizaduum_chaotic_shadows();
}
