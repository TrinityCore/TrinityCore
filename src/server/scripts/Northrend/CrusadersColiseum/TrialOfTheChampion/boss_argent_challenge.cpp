/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Argent Challenge Encounter.
SD%Complete: 50 %
SDComment: AI for Argent Soldiers are not implemented. AI from bosses need more improvements.
SDCategory: Trial of the Champion
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "trial_of_the_champion.h"
#include "ScriptedEscortAI.h"

enum Yells
{
    // Eadric the Pure
    EADRIC_SAY_INTRO = 0,
    EADRIC_SAY_AGGRO,
    EADRIC_EMOTE_RADIANCE,
    EADRIC_EMOTE_HAMMER_RIGHTEOUS,
    EADRIC_SAY_HAMMER_RIGHTEOUS,

    // Argent Confessor Paletress
    PALETRESS_SAY_INTRO_1 = 0,
    PALETRESS_SAY_INTRO_2,
    PALETRESS_SAY_AGGRO,
    PALETRESS_SAY_MEMORY_SUMMON,
    PALETRESS_SAY_MEMORY_DEATH,

    SAY_KILL_PLAYER,
    SAY_DEFEATED,

    // Memory of X
    EMOTE_WAKING_NIGHTMARE      = 0
};

enum Spells
{
    // Eadric the Pure
    SPELL_EADRIC_ACHIEVEMENT    = 68197,
    SPELL_HAMMER_JUSTICE        = 66863,
    SPELL_HAMMER_RIGHTEOUS      = 66867,
    SPELL_RADIANCE              = 66935,
    SPELL_VENGEANCE             = 66865,
    SPELL_HAMMER_THROW_BACK     = 66905,

    // Paletress
    SPELL_SMITE                 = 66536,
    SPELL_HOLY_FIRE             = 66538,
    SPELL_RENEW                 = 66537,
    SPELL_HOLY_NOVA             = 66546,
    SPELL_SHIELD                = 66515,
    SPELL_CONFESS               = 66680,
    SPELL_SUMMON_MEMORY         = 66545,

    // Memory of X (Summon)
    SPELL_MEMORY_ALGALON        = 66715,
    SPELL_MEMORY_ARCHIMONDE     = 66704,
    SPELL_MEMORY_CHROMAGGUS     = 66697,
    SPELL_MEMORY_CYANIGOSA      = 66709,
    SPELL_MEMORY_DELRISSA       = 66706,
    SPELL_MEMORY_ECK            = 66710,
    SPELL_MEMORY_ENTROPIUS      = 66707,
    SPELL_MEMORY_GRUUL          = 66702,
    SPELL_MEMORY_HAKKAR         = 66698,
    SPELL_MEMORY_HEIGAN         = 66712,
    SPELL_MEMORY_HEROD          = 66694,
    SPELL_MEMORY_HOGGER         = 66543,
    SPELL_MEMORY_IGNIS          = 66713,
    SPELL_MEMORY_ILLIDAN        = 66705,
    SPELL_MEMORY_INGVAR         = 66708,
    SPELL_MEMORY_KALITHRESH     = 66700,
    SPELL_MEMORY_LUCIFRON       = 66695,
    SPELL_MEMORY_MALCHEZAAR     = 66701,
    SPELL_MEMORY_MUTANUS        = 66692,
    SPELL_MEMORY_ONYXIA         = 66711,
    SPELL_MEMORY_THUNDERAAN     = 66696,
    SPELL_MEMORY_VANCLEEF       = 66691,
    SPELL_MEMORY_VASHJ          = 66703,
    SPELL_MEMORY_VEKNILASH      = 66699,
    SPELL_MEMORY_VEZAX          = 66714,

    // Memory
    SPELL_OLD_WOUNDS            = 66620,
    SPELL_SHADOWS_PAST          = 66619,
    SPELL_WAKING_NIGHTMARE      = 66552,
};

enum Events
{
    // Eadric the Pure
    EVENT_VENGANCE = 1,
    EVENT_RADIANCE,
    EVENT_JUSTICE_HAMMER,
    // Paletress
    EVENT_HOLY_SMITE,
    EVENT_HOLY_FIRE,
    EVENT_RENEW,
    // Memory
    EVENT_OLD_WOUNDS,
    EVENT_SHADOW_PAST,
    EVENT_WAKING_NIGHTMARE,
    EVENT_RESET,
};

enum Phases
{
    PHASE_ONE = 1,
    PHASE_SHIELDED,
};

class OrientationCheck : public std::unary_function<Unit*, bool>
{
    public:
        explicit OrientationCheck(Unit* _caster) : caster(_caster) { }
        bool operator()(WorldObject* object)
        {
            return !object->isInFront(caster, 2.5f) || !object->IsWithinDist(caster, 40.0f);
        }

    private:
        Unit* caster;
};

class spell_eadric_radiance : public SpellScriptLoader
{
    public:
        spell_eadric_radiance() : SpellScriptLoader("spell_eadric_radiance") { }
        class spell_eadric_radiance_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_eadric_radiance_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove_if(OrientationCheck(GetCaster()));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_eadric_radiance_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_eadric_radiance_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_eadric_radiance_SpellScript();
        }
};

class boss_eadric : public CreatureScript
{
public:
    boss_eadric() : CreatureScript("boss_eadric") { }

    struct boss_eadricAI : public BossAI
    {
        boss_eadricAI(Creature* creature) : BossAI(creature, BOSS_ARGENT_CHALLENGE_E)
        {
            Initialize();
            creature->SetReactState(REACT_PASSIVE);
        }

        void Initialize()
        {
            _defeated = false;
        }

        void Reset() override
        {
            _Reset();
            Initialize();
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo *spell) override
        {
            if (spell->Id == SPELL_HAMMER_THROW_BACK && me->GetHealth() <= (uint32)spell->GetEffect(EFFECT_0)->BasePoints)
                instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT_FACEROOLLER);
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                EnterEvadeMode();
                me->setFaction(35);
                if (!_defeated)
                {
                    events.ScheduleEvent(EVENT_RESET, 5000);
                    Talk(SAY_DEFEATED);
                    _defeated = true;
                }
            }
        }

        void MovementInform(uint32 MovementType, uint32 pointId) override
        {
            if (MovementType != POINT_MOTION_TYPE || pointId == 1)
                return;

            _JustDied();
            me->DisappearAndDie();
        }

        void EnterCombat(Unit* /*victim*/) override
        {
            Talk(EADRIC_SAY_AGGRO);
            events.ScheduleEvent(EVENT_VENGANCE, 10 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_RADIANCE, 16 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_JUSTICE_HAMMER, 25 * IN_MILLISECONDS);
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILL_PLAYER);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_RESET:
                    me->GetMotionMaster()->MovePoint(0, 746.87f, 665.87f, 411.75f);
                    break;
                case EVENT_JUSTICE_HAMMER:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
                    {
                        me->InterruptNonMeleeSpells(true);
                        me->TextEmote(EADRIC_EMOTE_HAMMER_RIGHTEOUS, target);
                        DoCast(target, SPELL_HAMMER_JUSTICE);
                        DoCast(target, SPELL_HAMMER_RIGHTEOUS);
                        Talk(EADRIC_SAY_HAMMER_RIGHTEOUS);
                    }
                    events.ScheduleEvent(EVENT_JUSTICE_HAMMER, 25 * IN_MILLISECONDS);
                    break;
                case EVENT_VENGANCE:
                    DoCast(me, SPELL_VENGEANCE);
                    events.ScheduleEvent(EVENT_VENGANCE, 10 * IN_MILLISECONDS);
                    break;
                case EVENT_RADIANCE:
                    Talk(EADRIC_EMOTE_RADIANCE);
                    DoCastAOE(SPELL_RADIANCE);
                    events.ScheduleEvent(EVENT_RADIANCE, 16 * IN_MILLISECONDS);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        bool _defeated;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_eadricAI>(creature);
    }
};

class boss_paletress : public CreatureScript
{
public:
    boss_paletress() : CreatureScript("boss_paletress") { }

    struct boss_paletressAI : public BossAI
    {
        boss_paletressAI(Creature* creature) : BossAI(creature, BOSS_ARGENT_CHALLENGE_P)
        {
            Initialize();
            creature->SetReactState(REACT_PASSIVE);
        }

        void Initialize()
        {
            _defeated = false;
        }

        void Reset() override
        {
            _Reset();
            events.SetPhase(PHASE_ONE);
            me->RemoveAllAuras();

            Initialize();
        }

        void SetData(uint32 id, uint32 /*value*/) override
        {
            if (id == 1)
            {
                Talk(PALETRESS_SAY_MEMORY_DEATH);
                me->RemoveAura(SPELL_SHIELD);
            }
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                EnterEvadeMode();
                me->setFaction(35);
                if (!_defeated)
                {
                    Talk(SAY_DEFEATED);
                    events.ScheduleEvent(EVENT_RESET, 7 * IN_MILLISECONDS);
                    _defeated = true;
                }
            }
        }

        void MovementInform(uint32 MovementType, uint32 pointId) override
        {
            if (MovementType != POINT_MOTION_TYPE || pointId == 1)
                return;

            _JustDied();
            me->DisappearAndDie();
        }

        void EnterCombat(Unit* /*victim*/) override
        {
            Talk(PALETRESS_SAY_AGGRO);
            events.ScheduleEvent(EVENT_HOLY_FIRE, urand(9000, 12000));
            events.ScheduleEvent(EVENT_HOLY_SMITE, urand(5000, 7000));
            events.ScheduleEvent(EVENT_RENEW, urand(2000, 5000));
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILL_PLAYER);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_RESET:
                    me->GetMotionMaster()->MovePoint(0, 746.87f, 665.87f, 411.75f);
                    break;
                case EVENT_HOLY_FIRE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
                        DoCast(target, SPELL_HOLY_FIRE);
                    if (me->HasAura(SPELL_SHIELD))
                        events.ScheduleEvent(EVENT_HOLY_FIRE, 13 * IN_MILLISECONDS);
                    else
                        events.ScheduleEvent(EVENT_HOLY_FIRE, urand(9000, 12000));
                    break;
                case EVENT_HOLY_SMITE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
                        DoCast(target, SPELL_SMITE);
                    if (me->HasAura(SPELL_SHIELD))
                        events.ScheduleEvent(EVENT_HOLY_SMITE, 9 * IN_MILLISECONDS);
                    else
                        events.ScheduleEvent(EVENT_HOLY_SMITE, urand(5000, 7000));
                    break;
                case EVENT_RENEW:
                    if (me->HasAura(SPELL_SHIELD))
                    {
                        me->InterruptNonMeleeSpells(true);
                        uint8 uiTarget = urand(0, 1);
                        switch (uiTarget)
                        {
                        case 0:
                            DoCast(me, SPELL_RENEW);
                            break;
                        case 1:
                            for (SummonList::const_iterator itr = summons.begin(); itr != summons.end(); ++itr)
                            {
                                if (Creature* pMemory = ObjectAccessor::GetCreature(*me, *itr))
                                    DoCast(pMemory, SPELL_RENEW);
                            }
                            break;
                        }
                        events.ScheduleEvent(EVENT_RENEW, urand(15000, 17000));
                    }
                    else
                        events.ScheduleEvent(EVENT_RENEW, 5 * IN_MILLISECONDS);
                    break;
                default:
                    break;
                }
            }

            if (events.IsInPhase(PHASE_ONE) && !HealthAbovePct(25))
            {
                events.SetPhase(PHASE_SHIELDED);
                me->InterruptNonMeleeSpells(true);
                DoCastAOE(SPELL_HOLY_NOVA, false);
                DoCast(me, SPELL_SHIELD);
                Talk(PALETRESS_SAY_MEMORY_SUMMON);
                DoCastAOE(SPELL_SUMMON_MEMORY, false);
                DoCastAOE(SPELL_CONFESS, false);
            }
            DoMeleeAttackIfReady();
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

        private:
            bool _defeated;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_paletressAI>(creature);
    }
};

class npc_memory : public CreatureScript
{
public:
    npc_memory() : CreatureScript("npc_memory") { }

    struct npc_memoryAI : public ScriptedAI
    {
        npc_memoryAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*victim*/)
        {
            events.ScheduleEvent(EVENT_OLD_WOUNDS, 12 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_WAKING_NIGHTMARE, 7 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SHADOW_PAST, 5 * IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_OLD_WOUNDS:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_OLD_WOUNDS);
                    events.ScheduleEvent(EVENT_OLD_WOUNDS, 12 * IN_MILLISECONDS);
                    break;
                case EVENT_WAKING_NIGHTMARE:
                    Talk(EMOTE_WAKING_NIGHTMARE);
                    DoCast(me, SPELL_WAKING_NIGHTMARE);
                    events.ScheduleEvent(EVENT_WAKING_NIGHTMARE, 7 * IN_MILLISECONDS);
                    break;
                case EVENT_SHADOW_PAST:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        DoCast(target, SPELL_SHADOWS_PAST);
                    events.ScheduleEvent(EVENT_SHADOW_PAST, 5 * IN_MILLISECONDS);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(DATA_MEMORY_ENTRY, me->GetEntry());

            if (TempSummon* summ = me->ToTempSummon())
                if (Unit* summoner = summ->GetSummoner())
                    summoner->GetAI()->SetData(1, 0);
        }

        private:
            EventMap events;
            InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_memoryAI>(creature);
    }
};

class npc_argent_soldier : public CreatureScript
{
public:
    npc_argent_soldier() : CreatureScript("npc_argent_soldier") { }

    // THIS AI NEEDS MORE IMPROVEMENTS
    struct npc_argent_soldierAI : public npc_escortAI
    {
        npc_argent_soldierAI(Creature* creature) : npc_escortAI(creature)
        {
            instance = creature->GetInstanceScript();
            me->SetReactState(REACT_AGGRESSIVE);
            SetDespawnAtEnd(false);
            uiWaypoint = 0;
        }

        InstanceScript* instance;

        uint8 uiWaypoint;

        void WaypointReached(uint32 waypointId) override
        {
            if (waypointId == 0)
            {
                switch (uiWaypoint)
                {
                    case 0:
                        me->SetFacingTo(5.81f);
                        break;
                    case 1:
                        me->SetFacingTo(4.60f);
                        break;
                    case 2:
                        me->SetFacingTo(2.79f);
                        break;
                }
            }
        }

        void SetData(uint32 uiType, uint32 /*uiData*/) override
        {
            switch (me->GetEntry())
            {
                case NPC_ARGENT_LIGHWIELDER:
                    switch (uiType)
                    {
                        case 0:
                            AddWaypoint(0, 712.14f, 628.42f, 411.88f);
                            break;
                        case 1:
                            AddWaypoint(0, 742.44f, 650.29f, 411.79f);
                            break;
                        case 2:
                            AddWaypoint(0, 783.33f, 615.29f, 411.84f);
                            break;
                    }
                    break;
                case NPC_ARGENT_MONK:
                    switch (uiType)
                    {
                        case 0:
                            AddWaypoint(0, 713.12f, 632.97f, 411.90f);
                            break;
                        case 1:
                            AddWaypoint(0, 746.73f, 650.24f, 411.56f);
                            break;
                        case 2:
                            AddWaypoint(0, 781.32f, 610.54f, 411.82f);
                            break;
                    }
                    break;
                case NPC_PRIESTESS:
                    switch (uiType)
                    {
                        case 0:
                            AddWaypoint(0, 715.06f, 637.07f, 411.91f);
                            break;
                        case 1:
                            AddWaypoint(0, 750.72f, 650.20f, 411.77f);
                            break;
                        case 2:
                            AddWaypoint(0, 779.77f, 607.03f, 411.81f);
                            break;
                    }
                    break;
            }

            Start(false, true);
            uiWaypoint = uiType;
        }

        void UpdateAI(uint32 uiDiff) override
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(DATA_ARGENT_SOLDIER_DEFEATED, instance->GetData(DATA_ARGENT_SOLDIER_DEFEATED) + 1);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_argent_soldierAI>(creature);
    }
};

uint32 const memorySpellId[25] =
{
    SPELL_MEMORY_ALGALON,
    SPELL_MEMORY_ARCHIMONDE,
    SPELL_MEMORY_CHROMAGGUS,
    SPELL_MEMORY_CYANIGOSA,
    SPELL_MEMORY_DELRISSA,
    SPELL_MEMORY_ECK,
    SPELL_MEMORY_ENTROPIUS,
    SPELL_MEMORY_GRUUL,
    SPELL_MEMORY_HAKKAR,
    SPELL_MEMORY_HEIGAN,
    SPELL_MEMORY_HEROD,
    SPELL_MEMORY_HOGGER,
    SPELL_MEMORY_IGNIS,
    SPELL_MEMORY_ILLIDAN,
    SPELL_MEMORY_INGVAR,
    SPELL_MEMORY_KALITHRESH,
    SPELL_MEMORY_LUCIFRON,
    SPELL_MEMORY_MALCHEZAAR,
    SPELL_MEMORY_MUTANUS,
    SPELL_MEMORY_ONYXIA,
    SPELL_MEMORY_THUNDERAAN,
    SPELL_MEMORY_VANCLEEF,
    SPELL_MEMORY_VASHJ,
    SPELL_MEMORY_VEKNILASH,
    SPELL_MEMORY_VEZAX
};

// 66545 - Summon Memory
class spell_paletress_summon_memory : public SpellScriptLoader
{
    public:
        spell_paletress_summon_memory() : SpellScriptLoader("spell_paletress_summon_memory") { }

        class spell_paletress_summon_memory_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paletress_summon_memory_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                for (uint8 i = 0; i < 25; ++i)
                    if (!sSpellMgr->GetSpellInfo(memorySpellId[i]))
                        return false;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
                targets.clear();
                targets.push_back(target);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell(GetHitUnit(), memorySpellId[urand(0, 24)], true, NULL, NULL, GetCaster()->GetGUID());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paletress_summon_memory_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_paletress_summon_memory_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_paletress_summon_memory_SpellScript();
        }
};

void AddSC_boss_argent_challenge()
{
    new boss_eadric();
    new spell_eadric_radiance();
    new boss_paletress();
    new npc_memory();
    new npc_argent_soldier();
    new spell_paletress_summon_memory();
}
