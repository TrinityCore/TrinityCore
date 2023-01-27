/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "Spell.h"
#include "SpellAuras.h"
#include "bastion_of_twilight.h"

#define YELL_AGGRO  "We were fools to entrust an imbecile like Cho'gall with such a sacred duty. I will deal with you intruders myself!"
#define YELL_KILL_0 "My brood will feed on your bones!"
#define YELL_KILL_1 "Powerless..."
#define YELL_SUMMON "Feed, children! Take your fill from their meaty husks!"

enum spells
{
    SPELL_WRACK                                   = 89421,
    SPELL_WRACK_JUMP                              = 89435,
    SPELL_FLAME_BREATH                            = 90125,
    SPELL_TWILIGHT_SLICER                         = 92851,
    SPELL_TWILIGHT_PULSE                          = 92957,
    SPELL_DRAINED                                 = 89350,
    SPELL_PURPLE_BEAM                             = 88518,
    SPELL_SIN_TWILIGHT_BLAST                      = 89280,
    SPELL_TWILIGHT_SPIT                           = 89299,
    SPELL_TWILIGHT_ESSENCE                        = 89284,
    SPELL_TWILIGHT_POWER                          = 87220,
    SPELL_FIERY_RESOLVE                           = 87221,
    SPELL_MANA_BARRIER                            = 87299,
    SPELL_PYRRHIC_FOCUS                           = 87323,
    SPELL_TWILIGHT_CARAPACE                       = 87654,
    SPELL_ESSENCE_OF_THE_RED                      = 87946,
    SPELL_ABSORB_ESSENCE                          = 90107,
    SPELL_TWILIGHT_BREATH                         = 110212,
    SPELL_UNLEASH_ESSENCE                         = 90028,
};

enum events
{
    EVENT_WRACK = 1,
    EVENT_FLAME_BREATH,
    EVENT_TWILIGHT_SLICER,
    EVENT_RESET_ORBS,
    EVENT_ORB_START_CHANNEL,
    EVENT_CHECK_MELEE,
    EVENT_WHELP,
    EVENT_START_MAGIC_FIGHT,
    EVENT_TWILIGHT_DRAKE,
    EVENT_SPITECALLER,
};

enum sharedDatas
{
    DATA_PRIVATE_ORB0 = 0,
};

enum phases
{
    PHASE_NONE = 0,
    PHASE_ONE,
    PHASE_TWO,
    PHASE_THREE
};

enum sinestraActions
{
    ACTION_START_PHASE_3 = 1,
};

Position const spawnPos[9] =
{
    {-985.92f, -819.84f, 438.59f, 0.87f},
    {-975.81f, -815.15f, 438.59f, 1.02f},
    {-962.71f, -805.22f, 438.59f, 1.77f},
    {-948.02f, -799.14f, 438.59f, 2.09f},
    {-943.09f, -787.05f, 438.59f, 2.59f},
    {-994.34f, -739.91f, 438.59f, 5.39f},
    {-1005.45f, -746.29f, 438.59f, 5.51f},
    {-1018.57f, -760.42f, 438.59f, 5.71f},
    {-1029.42f, -774.76f, 438.59f, 0.22f},
};

class boss_sinestra : public CreatureScript
{
    public:
        boss_sinestra() : CreatureScript("boss_sinestra") {}

        struct boss_sinestraAI : public BossAI
        {
            boss_sinestraAI(Creature * creature) : BossAI(creature, DATA_SINESTRA), summons(me)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            Creature* orbs[2];
            Creature* eggs[2];
            SummonList summons;
            uint8 phase;
            uint8 killedEggs;

            void Reset() override
            {
                if (instance)
                {
                    instance->SetData(DATA_SINESTRA_EVENT, NOT_STARTED);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ESSENCE_OF_THE_RED);
                }

                events.Reset();
                summons.DespawnAll();


                orbs[0] = NULL;
                orbs[1] = NULL;
                eggs[0] = NULL;
                eggs[1] = NULL;
                phase = PHASE_NONE;
                killedEggs = 0;
                std::list<Creature*> unitList;
                me->GetCreatureListWithEntryInGrid(unitList, 48050, 250.0f);
                for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                {// despawn twilight whelps
                    (*itr)->DespawnOrUnsummon();
                }
                me->GetCreatureListWithEntryInGrid(unitList, 48018, 250.0f);
                for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                {// despawn twilight essence
                    (*itr)->DespawnOrUnsummon();
                }
            }

            void EnterCombat(Unit* /*who*/) override
            {
                DoZoneInCombat(me);

                if (instance)
                {
                    instance->SetData(DATA_SINESTRA_EVENT, IN_PROGRESS);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                }

                // Sinestra begin fight with 60 % hp
                phase = PHASE_ONE;
                me->SetHealth(me->GetMaxHealth() * 0.60f);

                // Sinestra damage is reduced by 40% in first phase
                me->AddAura(SPELL_DRAINED, me);

                me->Yell(YELL_AGGRO, LANG_UNIVERSAL, 0);

                // Summon first egg
                if (Creature* egg = me->SummonCreature(46842, -993.72f, -669.54f, 440.20f, 4.57f, TEMPSUMMON_CORPSE_DESPAWN))
                {
                    eggs[0] = egg;
                    egg->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    egg->SetReactState(REACT_PASSIVE);
                    egg->AttackStop();
                    egg->StopMoving();
                    me->AddAura(SPELL_TWILIGHT_CARAPACE, egg);
                }

                // Summon second egg
                if (Creature* egg = me->SummonCreature(46842, -901.25f, -768.70f, 441.35f, 3.33f, TEMPSUMMON_CORPSE_DESPAWN))
                {
                    eggs[1] = egg;
                    egg->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    egg->SetReactState(REACT_PASSIVE);
                    egg->AttackStop();
                    egg->StopMoving();
                    me->AddAura(SPELL_TWILIGHT_CARAPACE, egg);
                }

                events.ScheduleEvent(EVENT_WRACK, 15000, PHASE_ONE);
                events.ScheduleEvent(EVENT_FLAME_BREATH, 20000, PHASE_ONE);
                events.ScheduleEvent(EVENT_TWILIGHT_SLICER, 28000, PHASE_ONE);
                events.ScheduleEvent(EVENT_CHECK_MELEE, 2000, PHASE_ONE);
                events.ScheduleEvent(EVENT_WHELP, urand(20000, 25000), PHASE_ONE);
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);

                DoZoneInCombat(summon);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (instance)
                {
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ESSENCE_OF_THE_RED);
                    instance->SetData(DATA_SINESTRA_EVENT, DONE);
                }
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                me->Yell(urand(0, 1) == 1 ? YELL_KILL_0 : YELL_KILL_1, LANG_UNIVERSAL, 0);
            }

            void DamageTaken(Unit* /*who*/, uint32& /*damage*/) override
            {
                if (me->GetHealthPct() <= 30.0f && phase == PHASE_ONE)
                {
                    phase = PHASE_TWO;
                    events.CancelEventGroup(PHASE_ONE);
                    me->RemoveAura(SPELL_DRAINED);
                    DoCast(SPELL_MANA_BARRIER);
                    events.ScheduleEvent(EVENT_START_MAGIC_FIGHT, 2000, PHASE_TWO);
                    events.ScheduleEvent(EVENT_TWILIGHT_DRAKE, urand(18000, 30000), PHASE_TWO);
                    events.ScheduleEvent(EVENT_SPITECALLER, urand(18000, 35000), PHASE_TWO);
                }
            }

            ObjectGuid GetGuidData(uint32 type)
            {
                switch (type)
                {
                    case DATA_PRIVATE_ORB0:
                        if (orbs[0])
                            return orbs[0]->GetGUID();
                        break;
                }

                return ObjectGuid::Empty;
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                if (summon->GetEntry() == 46842)
                {
                    killedEggs++;

                    if (killedEggs >= 2 && phase == PHASE_TWO)
                    {
                        phase = PHASE_THREE;
                        events.CancelEventGroup(PHASE_TWO);
                        me->CastStop();
                        me->RemoveAura(SPELL_MANA_BARRIER);

                        if (Creature* calen = me->FindNearestCreature(46277, 100.0f, true))
                        {
                            calen->CastStop();
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                calen->CastSpell(pTarget, SPELL_ESSENCE_OF_THE_RED, true);
                            calen->DisappearAndDie();
                        }

                        events.ScheduleEvent(EVENT_WRACK, 15000, PHASE_THREE);
                        events.ScheduleEvent(EVENT_FLAME_BREATH, 20000, PHASE_THREE);
                        events.ScheduleEvent(EVENT_TWILIGHT_SLICER, 28000, PHASE_THREE);
                        events.ScheduleEvent(EVENT_CHECK_MELEE, 2000, PHASE_THREE);
                        events.ScheduleEvent(EVENT_WHELP, urand(15000, 25000), PHASE_THREE);
                    }
                }
            }

            void UpdateAI(uint32 diff) override

            {
                if (!UpdateVictim() || (me->HasUnitState(UNIT_STATE_CASTING) && phase != PHASE_TWO))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WRACK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0f, 100.0f, true, 0))
                                DoCast(target, SPELL_WRACK, true);

                            events.ScheduleEvent(EVENT_WRACK, urand(75000, 80000), phase);
                            break;
                        case EVENT_FLAME_BREATH:
                            DoCastAOE(SPELL_FLAME_BREATH);
                            events.ScheduleEvent(EVENT_FLAME_BREATH, 20000, phase);
                            break;
                        case EVENT_TWILIGHT_SLICER:
                            for (uint8 i = 0; i < 2; i++)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0f, 100.0f, true, -SPELL_PURPLE_BEAM))
                                {
                                    Position pos = target->GetPosition();
                                    float width = frand(5, 20);
                                    float degree = frand(0, 6.28f);
                                    pos.Relocate(pos.GetPositionX() + cos(degree)*width, pos.GetPositionY() + sin(degree)*width);
                                    if (Creature* orb = me->SummonCreature(49863, pos, TEMPSUMMON_TIMED_DESPAWN, 15000, 0))
                                    {
                                        if (!orbs[0])
                                        {
                                            orbs[0] = orb;
                                            if (instance)
                                                instance->SetGuidData(DATA_ORB_0, orb->GetGUID());
                                        }
                                        else
                                        {
                                            orbs[1] = orb;

                                            if (instance)
                                                instance->SetGuidData(DATA_ORB_1, orb->GetGUID());
                                        }

                                        orb->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                                        orb->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                                        orb->AddThreat(target, 1000000.0f);
                                        orb->Attack(target, true);

                                        // Twilight pulse!
                                        orb->CastSpell(orb, SPELL_TWILIGHT_PULSE, true);
                                        if (Aura* aur = orb->AddAura(SPELL_PURPLE_BEAM, target))
                                            aur->SetDuration(60000);
                                    }
                                }
                            }
                            events.ScheduleEvent(EVENT_RESET_ORBS, 18000, phase);
                            events.ScheduleEvent(EVENT_TWILIGHT_SLICER, 28000, phase);
                            events.ScheduleEvent(EVENT_ORB_START_CHANNEL, 3500, phase);
                            break;
                        case EVENT_ORB_START_CHANNEL:
                            if (orbs[0] && orbs[1])
                            {
                                orbs[1]->CastSpell(orbs[0], SPELL_TWILIGHT_SLICER, true);
                                orbs[1]->ClearUnitState(UNIT_STATE_CASTING);

                                if (orbs[1]->GetVictim())
                                    orbs[1]->RemoveUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                                    orbs[1]->GetMotionMaster()->MoveChase(orbs[1]->GetVictim());

                                if (orbs[0]->GetVictim())
                                    orbs[0]->RemoveUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                                    orbs[0]->GetMotionMaster()->MoveChase(orbs[0]->GetVictim());
                            }
                            break;
                        case EVENT_RESET_ORBS:
                            orbs[0] = NULL;
                            orbs[1] = NULL;

                            if (instance)
                                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PURPLE_BEAM);
                            break;
                        case EVENT_CHECK_MELEE:
                            if (me->GetDistance2d(me->GetVictim()) >= 5.0f)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0f, 100.0f, true, 0))
                                    me->CastSpell(target, SPELL_SIN_TWILIGHT_BLAST, false);
                            }
                            events.ScheduleEvent(EVENT_CHECK_MELEE, 2000, phase);
                            break;
                        case EVENT_WHELP:
                            for (uint8 i = 0; i < 5; i++)
                            {
                                uint8 posId = urand(0, 8);
                                me->SummonCreature(48050, spawnPos[posId]);
                            }

                            me->Yell(YELL_SUMMON, LANG_UNIVERSAL, 0);
                            events.ScheduleEvent(EVENT_WHELP, urand(50000, 60000), phase);
                            break;
                        case EVENT_TWILIGHT_DRAKE:
                            me->SummonCreature(55636, spawnPos[urand(0, 8)]);
                            events.ScheduleEvent(EVENT_TWILIGHT_DRAKE, urand(18000, 30000), PHASE_TWO);
                            break;
                        case EVENT_SPITECALLER:
                            me->SummonCreature(48415, spawnPos[urand(0, 8)]);
                            events.ScheduleEvent(EVENT_SPITECALLER, urand(18000, 35000), PHASE_TWO);
                            break;
                        case EVENT_START_MAGIC_FIGHT:
                            if (Creature* calen = me->SummonCreature(46277, -1009.35f, -801.97f, 438.59f, 0.81f))
                            {
                                calen->CastSpell(calen, SPELL_PYRRHIC_FOCUS, true);
                                calen->Yell("Sintharia! Your master owes me a great debt... one that I intend to extract from his consort's hide!", LANG_UNIVERSAL, 0);

                                if (Creature* target = me->SummonCreature(46288, -988.828f, -787.879f, 449.618f, 0.49f))
                                {
                                    target->SetHover(true);
                                    target->SetDisableGravity(true);
                                    target->SetCanFly(true);

                                    target->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                                    target->GetMotionMaster()->MoveTakeoff(0, target->GetHomePosition());

                                    calen->CastSpell(target, SPELL_FIERY_RESOLVE, false);
                                    me->CastSpell(target, SPELL_TWILIGHT_POWER, false);

                                    calen->setRegeneratingHealth(false);
                                }
                            }

                            me->Yell("This will be your tomb as well as theirs!", LANG_UNIVERSAL, 0);

                            // Expose eggs!
                            if (eggs[0])
                                eggs[0]->RemoveAura(SPELL_TWILIGHT_CARAPACE);
                            if (eggs[1])
                                eggs[1]->RemoveAura(SPELL_TWILIGHT_CARAPACE);
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
            return new boss_sinestraAI(creature);
        }
};

enum whelpEvents
{
    EVENT_SPIT = 1,
};

enum whelpActions
{
    ACTION_SET_AS_RESPWANED = 1,
};

class npc_sinestra_twilight_whelp : public CreatureScript
{
    public:
        npc_sinestra_twilight_whelp() : CreatureScript("npc_sinestra_twilight_whelp")
        { }

        struct npc_sinestra_twilight_whelpAI : public ScriptedAI
        {
            npc_sinestra_twilight_whelpAI(Creature * creature) : ScriptedAI(creature)
            {
                pInstance = (InstanceScript*)creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;
            bool respawned;

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_SPIT, urand(10000, 35000));
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                respawned = false;
            }

            void DoAction(int32 actionId) override
            {
                switch (actionId)
                {
                    case ACTION_SET_AS_RESPWANED:
                        respawned = true;
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (respawned)
                    return;

                Position pos = me->GetPosition();
                if (Creature* essence = me->SummonCreature(48018, pos, TEMPSUMMON_MANUAL_DESPAWN, 0, 0))
                {
                    DoZoneInCombat(essence);
                    essence->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                    essence->SetReactState(REACT_PASSIVE);
                    essence->AttackStop();
                    essence->StopMoving();
                }
            }

            void UpdateAI(uint32 uiDiff) override
            {
                events.Update(uiDiff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SPIT:
                            DoCastVictim(SPELL_TWILIGHT_SPIT);

                            events.ScheduleEvent(EVENT_SPIT, urand(35000, 50000));
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_sinestra_twilight_whelpAI(creature);
        }
};


enum sinestraAddEvents
{
    EVENT_TWILIGHT_BREATH = 1,
    EVENT_UNLEASH_ESSENCE,
};

class npc_sinestra_add : public CreatureScript
{
    public:
        npc_sinestra_add() : CreatureScript("npc_sinestra_add")
        { }

        struct npc_sinestra_addAI : public ScriptedAI
        {
            npc_sinestra_addAI(Creature * creature) : ScriptedAI(creature)
            {
                instance = (InstanceScript*)creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            bool respawned;

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (me->GetEntry() == 55636)
                    events.ScheduleEvent(EVENT_TWILIGHT_BREATH, urand(7000, 10000));
                else
                    events.ScheduleEvent(EVENT_UNLEASH_ESSENCE, urand(22000, 30000));
            }

            void UpdateAI(uint32 uiDiff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(uiDiff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TWILIGHT_BREATH:
                            DoCastVictim(SPELL_TWILIGHT_BREATH);
                            events.ScheduleEvent(EVENT_TWILIGHT_BREATH, urand(15000, 20000));
                            break;
                        case EVENT_UNLEASH_ESSENCE:
                            DoCastAOE(SPELL_UNLEASH_ESSENCE);
                            events.ScheduleEvent(EVENT_UNLEASH_ESSENCE, urand(22000, 30000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_sinestra_addAI(creature);
        }
};

class spell_sinestra_wreck : public SpellScriptLoader
{
    public:
        spell_sinestra_wreck() : SpellScriptLoader("spell_sinestra_wreck") { }

        class spell_sinestra_wreck_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sinestra_wreck_AuraScript);

            void HandleShareBuff (AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTargetApplication())
                    return;

                if (!GetTargetApplication()->GetBase())
                    return;

                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
                {
                    if (Unit* target = GetTarget())
                    {
                        CustomSpellValues values;
                        values.AddSpellMod(SPELLVALUE_MAX_TARGETS, 2);
                        values.AddSpellMod(SPELLVALUE_BASE_POINT1, GetTargetApplication()->GetBase()->GetDuration());
                        target->CastCustomSpell(SPELL_WRACK_JUMP, values, nullptr, TRIGGERED_FULL_MASK, nullptr, nullptr, GetCasterGUID());
                    }
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_sinestra_wreck_AuraScript::HandleShareBuff, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sinestra_wreck_AuraScript();
        }
};


class spell_sinestra_wrack_jump : public SpellScriptLoader
{
    public:
        spell_sinestra_wrack_jump() :  SpellScriptLoader("spell_sinestra_wrack_jump") { }

        class spell_sinestra_wrack_jump_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sinestra_wrack_jump_SpellScript);

            void SelectTarget(std::list<WorldObject*>& targets)
            {
                targets.remove(GetCaster());
                targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));

                if (targets.size() < 3)
                    return;

                targets.resize(2);
            }

            void Hit(SpellMissInfo /*missInfo*/)
            {
                if (!GetHitUnit())
                    return;

                if (!GetCaster())
                    return;

                if (!GetOriginalCaster())
                    return;

                if (Aura* debuff = GetOriginalCaster()->AddAura(89421, GetHitUnit()))
                {
                    if (!GetSpellValue())
                        return;

                    int32 duration = GetSpellValue()->EffectBasePoints[1];
                    debuff->SetDuration(duration, false);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sinestra_wrack_jump_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sinestra_wrack_jump_SpellScript::SelectTarget, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
                BeforeHit += BeforeSpellHitFn(spell_sinestra_wrack_jump_SpellScript::Hit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sinestra_wrack_jump_SpellScript();
        }
};

class OrientationCheck : public std::unary_function<Unit*, bool>
{
    public:
        explicit OrientationCheck(Unit* _orb1, Unit* _orb2) : orb1(_orb1), orb2(_orb2) { }
        bool operator()(WorldObject* object)
        {
            return !object->IsInBetween(orb1, orb2, 2.0f);
        }

    private:
        Unit* orb1;
        Unit* orb2;
};

class ExactDistanceCheck
{
    public:
        ExactDistanceCheck(Unit* source, float dist) : _source(source), _dist(dist) {}

        bool operator()(WorldObject* unit)
        {
            return _source->GetExactDist2d(unit) > _dist;
        }

    private:
        Unit* _source;
        float _dist;
};

class spell_sinestra_phyrric_focus : public SpellScriptLoader
{
    public:
        spell_sinestra_phyrric_focus() : SpellScriptLoader("spell_sinestra_phyrric_focus") { }

        class spell_sinestra_phyrric_focus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sinestra_phyrric_focus_AuraScript);

            void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                {
                    if (caster->GetHealthPct() <= 1)
                    {
                        if (InstanceScript* instance = caster->GetInstanceScript())
                        {
                            if (Creature* sinestra = instance->GetCreature(DATA_SINESTRA))
                            {
                                sinestra->CastStop();
                                sinestra->AI()->DoAction(ACTION_START_PHASE_3);
                            }
                        }
                        caster->Yell("All is lost.... Forgive me, my Queen....", LANG_UNIVERSAL, 0);
                        caster->DealDamage(caster, caster->GetMaxHealth() + 100);
                        return;
                    }
                    caster->DealDamage(caster, caster->GetMaxHealth() * 0.01f);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_sinestra_phyrric_focus_AuraScript::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sinestra_phyrric_focus_AuraScript();
        }
};

void AddSC_boss_sinestra()
{
    new boss_sinestra();
    new npc_sinestra_twilight_whelp();
    new npc_sinestra_add();
    new spell_sinestra_wreck();
    new spell_sinestra_wrack_jump();
    new spell_sinestra_phyrric_focus();
}
