#include "eternal_palace.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "AreaTriggerTemplate.h"
#include "Unit.h"

enum Spells
{
    SPELL_SEPARATION_OF_POWER = 296716,
    SPELL_DESPERATE_MEASURES = 300088,
    SPELL_ARCANE_PROJECTION = 303674,
    SPELL_COMMANDERS_FURY = 299563,
    SPELL_COMMANDERS_FURY_AURA = 299575,
    SPELL_FRENETIC_CHARGE_PRE_AURA = 299914,
    SPELL_FRENETIC_CHARGE_CAST = 299915,
    SPELL_FRENETIC_CHARGE_JUMP = 299917,
    SPELL_FRENETIC_CHARGE_DAMAGE = 300550,
    SPELL_MIGHTY_RUPTURE_AURA = 300545,
    SPELL_MIGHTY_RUPTURE_AT = 300546,
    SPELL_ZEALOUS_ERUPTION_DAMAGE = 301808,
    SPELL_ZEALOUS_ERUPTION_CAST = 301807, //15
    SPELL_PASHMARS_TOUCH = 301829,
    SPELL_PASHMARS_TOUCH_AURA = 301830,
    SPELL_FANATICAL_ZEAL = 301832,
    SPELL_FANATICAL_VERDICT_CAST = 296850,
    SPELL_FANATICAL_VERDICT_PRE_AURA = 296851,
    SPELL_FANATICAL_VERDICT_DAMAGE = 296852,
    SPELL_POTENT_SPARK_CAST = 301947,
    SPELL_POTENT_SPARK_SUMMON = 297832,
    SPELL_POTENT_SPARK_DAMAGE = 304047,
    SPELL_POTENT_SPARK_DAMAGE_HEROIC = 297836,
    SPELL_POTENT_SPARK_AURA_SELF = 297851,
    SPELL_VIOLENT_OUTBURST = 297325,
};

enum Events
{
    EVENT_CHECK_ENERGY = 1,
    EVENT_FRENETIC_CHARGE,
    EVENT_ZEALOUS_ERUPTION,
    EVENT_FANATICAL_VERDICT,
    EVENT_POTENT_SPARK,
    EVENT_VIOLENT_OUTBURST,
};

enum DecreeEvents
{
    EVENT_FORM_RANKS = 20,
    EVENT_STAND_ALONE,
    EVENT_REPEAT_PERFORMANCE,
    EVENT_DEFERRED_SENTENCE,
    EVENT_OBEY_OR_SUFFER,
};
enum Timers
{
    TIMER_CHECK_ENERGY = 1 * IN_MILLISECONDS,
    TIMER_DECREE_START = 30 * IN_MILLISECONDS,
    TIMER_DECREE_NEXT = 60 * IN_MILLISECONDS,
    TIMER_DECREE_NEXT_HEROIC = 45 * IN_MILLISECONDS,
    TIMER_DECREE_NEXT_MYTHIC = 30 * IN_MILLISECONDS,
    TIMER_FRENETIC_CHARGE = 30 * IN_MILLISECONDS,
    TIMER_VIOLENT_OUTBURST = 1 * IN_MILLISECONDS,
    TIMER_ZEALOUS_ERUPTION = 1 * IN_MILLISECONDS,
    TIMER_POTENT_SPARK = 90 * IN_MILLISECONDS,
    TIMER_FANATICAL_VERDICT = 30 * IN_MILLISECONDS,
};

enum DecreeSpells
{
    SPELL_FORM_RANKS_AT = 303182, // 3
    SPELL_FORM_RANKS_DAMAGE = 303227,
    SPELL_FORM_RANKS_EXPLOSION = 303247,
    SPELL_REPEAT_PERFORMANCE_AURA = 304410,
    SPELL_REPEAT_PERFORMANCE_PROC_CHECK = 301244,
    SPELL_STAND_ALONE_VISUAL_AURA = 297648,
    SPELL_STAND_ALONE_DAMAGE = 297672,
    SPELL_DEFERRED_SENTENCE_DAMAGE = 297578,
    SPELL_DEFERRED_SENTENCE_AURA_STACK = 304128,
    SPELL_DEFFERED_SENTENCE_PERIODIC = 297564,
    SPELL_OBEY_OR_SUFFER = 297585,
    SPELL_SUFFERING = 297586,
    SPELL_SPHERE_OF_INFLUENCE = 303306,
    SPELL_STAND_ALONE_MYTHIC_AT = 302934,
    SPELL_REPEAT_PERFORMANCE_MYTHIC_AT = 302941,
    SPELL_FORM_RANKS_MYTHIC_AT = 302938,
    SPELL_DEFERRED_SENTENCE_MYTHIC_AT = 302942,
    SPELL_OBEY_OR_SUFFER_MYTHIC_AT = 302944,
};

uint32 DecreeAreaTriggerSpellByFlag[5] =
{
    SPELL_OBEY_OR_SUFFER_MYTHIC_AT,
    SPELL_DEFERRED_SENTENCE_MYTHIC_AT,
    SPELL_FORM_RANKS_MYTHIC_AT,
    SPELL_STAND_ALONE_MYTHIC_AT,
    SPELL_REPEAT_PERFORMANCE_MYTHIC_AT,
};

uint32 DecreeFlags[5] =
{
    NPC_FORM_RANKS,
    NPC_STAND_ALONE,
    NPC_DEFERRED_SENTENCE,
    NPC_OBEY_OR_SUFFER,
    NPC_REPEAT_PERFORMANCE,
};

enum Actions
{
    ACTION_INIT_DECREE = 1,
    ACTION_DEAD_KILL,
};

struct noTanks : public std::unary_function<Unit*, bool>
{
    noTanks() {}

    bool operator() (const Unit* pTarget)
    {
        Player* player = const_cast<Player*>(pTarget->ToPlayer());
        uint32 specialization = player->GetSpecializationId();
        return ((player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_BEAR)
            || (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_PROTECTION)
            || (player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_PROTECTION)
            || (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_BLOOD)
            || (player->getClass() == CLASS_DEMON_HUNTER && specialization == TALENT_SPEC_DEMON_HUNTER_VENGEANCE)
            || (player->getClass() == CLASS_MONK && specialization == TALENT_SPEC_MONK_BREWMASTER));
    }
};

const Position centerPos = { 196.03f, 1443.84f, 858.91f };

Position decreeSpawnTrigger = { 196.29f, 1393.21f, 869.79f };

Position flagPos[5] =
{
    {196.355f, 1477.08f, 858.91f},
    {236.54f, 1443.90f, 858.91f},
    {202.42f, 1406.81f, 858.91f},
    {162.60f, 1416.94f, 858.91f},
    {160.13f, 1467.54f, 858.91f},
};

#define PASHAMAR_AGGRO "Off with their heads!"
#define FRENETIC_CHARGE_TEXT "Death awaits you!"
#define PASHMAR_SPECIAL_TEXT "I shall strike you down!"
#define SILIVAZ_SPECIAL_TEXT "Face my wrath!"
#define DECREE_SPECIAL_1 "I am weary of this farce. Obey my edicts or suffer the consequences."
#define DECREE_SPECIAL_2 "This pageant grows tiresome. I command you to provide more entertainment."
#define SILIVAZ_KILLED_TARGET "Pitiful!"
#define PASHMAR_KILLED_TARGET "You have been found wanting!"

class bfa_boss_silivaz_the_zealous : public CreatureScript
{
public:
    bfa_boss_silivaz_the_zealous() : CreatureScript("bfa_boss_silivaz_the_zealous")
    {
    }

    struct bfa_boss_silivaz_the_zealous_AI : public BossAI
    {
        bfa_boss_silivaz_the_zealous_AI(Creature* creature) : BossAI(creature, DATA_THE_QUEENS_COURT)
        {
            instance = creature->GetInstanceScript();
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
        }

        InstanceScript* instance;
        EventMap events;
        bool _dead;

        void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
        {
            if (!me)
                return;

            if (me)
            {
                switch (selectedTextSound)
                {
                case 1:
                    me->Yell(SILIVAZ_SPECIAL_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 2:
                    me->Yell(FRENETIC_CHARGE_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 3:
                    me->Yell(SILIVAZ_KILLED_TARGET, LANG_UNIVERSAL, NULL);
                    break;
                }
            }
        }

        void KilledUnit(Unit* t)
        {
            SelectSoundAndText(me, 3);
        }

        void Reset()
        {
            _dead = false;
            events.Reset();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            DespawnCreature(NPC_QUEEN_AZSHARA_DECREE, 500);
        //    me->AddAura(AURA_OVERRIDE_POWER_COLOR_DEMONIC);
        }

        void JustDied(Unit*)
        {
            DespawnCreature(NPC_QUEEN_AZSHARA_DECREE, 500);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        bool checkPashmarDistance()
        {
            if (Creature* pashmar = GetPashmar())
            {
                if (me->GetDistance(pashmar) <= 21.0f)
                {
                    if (Aura* sep = me->AddAura(SPELL_SEPARATION_OF_POWER, me))
                    {
                        sep->SetMaxDuration(2000);
                        sep->SetDuration(2000);
                    }
                    if (Aura* sep2 = pashmar->AddAura(SPELL_SEPARATION_OF_POWER, pashmar))
                    {
                        sep2->SetMaxDuration(2000);
                        sep2->SetDuration(2000);
                    }
                }
                return false;
            }

            return true;
        }

        void DamageTaken(Unit* at, uint32& damage)
        {
            if (damage >= me->GetHealth() && !_dead)
            {
                _dead = true;
                damage = 0;
                me->SetHealth(100);
                events.Reset();
                if (Creature* pashmar = GetPashmar())
                    pashmar->AI()->DoAction(ACTION_DEAD_KILL);
                me->CastSpell(me, SPELL_DESPERATE_MEASURES);
            }
        }

        void DespawnCreature(uint32 entry, uint32 timer)
        {
            std::list<Creature*> clist;
            me->GetCreatureListWithEntryInGrid(clist, entry, 200.0f);
            if (clist.size())
            {
                for (auto creature : clist)
                    creature->DespawnOrUnsummon(timer);
            }
        }

        void OnSpellFinished(SpellInfo const* spellInfo) //override
        {
            switch (spellInfo->Id)
            {
            case SPELL_DESPERATE_MEASURES:
            {
                _dead = false;
                events.ScheduleEvent(EVENT_FRENETIC_CHARGE, TIMER_FRENETIC_CHARGE);
                events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
                break;
            }
            }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_DEAD_KILL:
                if (_dead)
                {
                    me->Kill(me);
                    if (Creature* pashmar = GetPashmar())
                        pashmar->Kill(pashmar);
                }
                break;
            }
        }

        void EnterEvadeMode(EvadeReason w)
        {
            _DespawnAtEvade(15);
        }

        void EnterCombat(Unit*)
        {
            me->SetPower(POWER_ENERGY, 0);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            if (Creature* pashmar = GetPashmar())
                pashmar->SetInCombatWithZone();

            me->AddAura(SPELL_COMMANDERS_FURY_AURA, me);

            events.ScheduleEvent(EVENT_FRENETIC_CHARGE, TIMER_FRENETIC_CHARGE);
            events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
        }

        Creature* GetPashmar()
        {
            return me->FindNearestCreature(BOSS_PASHMAR_THE_FANATICAL, 200.0f, true);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->IsInCombat())
                checkPashmarDistance();

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_ENERGY:
                {
                    if (me->GetPower(POWER_ENERGY) >= 100)
                    {
                        events.ScheduleEvent(EVENT_ZEALOUS_ERUPTION, TIMER_ZEALOUS_ERUPTION);
                        me->SetPower(POWER_ENERGY, 0);
                    }

                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + urand(1, 2));
                    events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
                    break;
                }
                case EVENT_ZEALOUS_ERUPTION:
                {
                    SelectSoundAndText(me, 1);
                    std::ostringstream str;
                    str << "Silivaz is casting |cFFF00000|h[Zealous Eruption]|h|r!";
                    me->TextEmote(str.str().c_str(), 0, true);
                    me->CastSpell(me, SPELL_ZEALOUS_ERUPTION_CAST);
                    break;
                }
                case EVENT_FRENETIC_CHARGE:
                {
                    SelectSoundAndText(me, 2);
                    std::list<Player*> playerList;
                    me->GetPlayerListInGrid(playerList, 200.0f);
                    playerList.remove_if(noTanks());

                    if (playerList.size() >= 1)
                        playerList.resize(1);

                    if (!playerList.empty())
                    {
                        for (auto player : playerList)
                        {
                            std::ostringstream str;
                            str << "Silivaz the Zealous targets " << (player->GetName()) << " for |cFFF00000|h[Frenetic Charge]|h|r!";
                            me->TextEmote(str.str().c_str(), 0, true);

                            player->AddAura(SPELL_FRENETIC_CHARGE_PRE_AURA, player);
                            me->CastSpell(player, SPELL_FRENETIC_CHARGE_CAST);
                        }
                    }

                    events.ScheduleEvent(EVENT_FRENETIC_CHARGE, TIMER_FRENETIC_CHARGE);
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_silivaz_the_zealous_AI(creature);
    }
};

// 299563
class bfa_spell_commanders_fury : public SpellScriptLoader
{
public:
    bfa_spell_commanders_fury() : SpellScriptLoader("bfa_spell_commanders_fury") { }

    class bfa_spell_commanders_fury_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_commanders_fury_AuraScript);

        ObjectGuid currentTarget;

        bool Load() override
        {
            currentTarget = ObjectGuid::Empty;
            return true;
        }

        void HandleOnProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            Unit* caster = eventInfo.GetActor(); // boss
            Unit* target = eventInfo.GetActionTarget(); // current target
            if (!caster || !target)
                return;

            if (target->GetGUID() != currentTarget)
            {
                if (Aura* frenzy = caster->GetAura(SPELL_COMMANDERS_FURY_AURA))
                    frenzy->SetStackAmount(1);
                currentTarget = target->GetGUID();
            }
            else
                caster->CastSpell(caster, SPELL_COMMANDERS_FURY_AURA, true);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(bfa_spell_commanders_fury_AuraScript::HandleOnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_commanders_fury_AuraScript();
    }
};

// 299915
class bfa_spell_frenetic_charge_cast : public SpellScriptLoader
{
public:
    bfa_spell_frenetic_charge_cast() : SpellScriptLoader("bfa_spell_frenetic_charge_cast") { }

    class bfa_spell_frenetic_charge_cast_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_frenetic_charge_cast_SpellScript);

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            Unit* target = caster->GetVictim();
            if (!target || !caster)
                return;

            caster->CastSpell(target, SPELL_FRENETIC_CHARGE_JUMP, true);
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_frenetic_charge_cast_SpellScript::HandleAfterCast);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_frenetic_charge_cast_SpellScript();
    }
};

// 299917
class bfa_spell_frenetic_charge_at_create : public SpellScriptLoader
{
public:
    bfa_spell_frenetic_charge_at_create() : SpellScriptLoader("bfa_spell_frenetic_charge_at_create") { }

    class bfa_spell_frenetic_charge_at_create_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_frenetic_charge_at_create_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = GetHitUnit())
                    caster->CastSpell(/*target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), */SPELL_MIGHTY_RUPTURE_AT, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_frenetic_charge_at_create_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_JUMP);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new bfa_spell_frenetic_charge_at_create_SpellScript();
    }
};

// 300550
class bfa_spell_frenetic_charge_damage : public SpellScriptLoader
{
public:
    bfa_spell_frenetic_charge_damage() : SpellScriptLoader("bfa_spell_frenetic_charge_damage") { }

    class bfa_spell_frenetic_charge_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_frenetic_charge_damage_SpellScript);

        uint32 targetList;

        bool Load() override
        {
            targetList = 1; // initial player 
            return true;
        }

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            targetList = targets.size();
        }

        void RecalculateDamage(SpellEffIndex index)
        {
            SetHitDamage(GetHitDamage() / targetList);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_frenetic_charge_damage_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(bfa_spell_frenetic_charge_damage_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_frenetic_charge_damage_SpellScript();
    }
};

// 17380
class bfa_at_flags_spell : public AreaTriggerEntityScript
{
public:
    bfa_at_flags_spell() : AreaTriggerEntityScript("bfa_at_flags_spell") { }

    struct bfa_at_flags_spell_AI : AreaTriggerAI
    {
        bfa_at_flags_spell_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUpdate(uint32 diff)
        {
            std::list<Player*> playerList;
            at->GetPlayerListInGrid(playerList, 30.0f);
            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    if (player->GetDistance(at->GetPosition()) <= 29.0f)
                    {
                        if (!player->HasAura(SPELL_SPHERE_OF_INFLUENCE))
                        {
                            if (Aura* influ = player->AddAura(SPELL_SPHERE_OF_INFLUENCE, player))
                            {
                                influ->SetMaxDuration(2000);
                                influ->SetDuration(2000);
                            }
                        }
                    }
                }
            }
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_flags_spell_AI(areatrigger);
    }
};

// 17071
class bfa_at_mighty_rupture : public AreaTriggerEntityScript
{
public:
    bfa_at_mighty_rupture() : AreaTriggerEntityScript("bfa_at_mighty_rupture") { }

    struct bfa_at_mighty_rupture_AI : AreaTriggerAI
    {
        bfa_at_mighty_rupture_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUpdate(uint32 diff)
        {
            std::list<Player*> playerList;
            at->GetPlayerListInGrid(playerList, 5.0f);
            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    if (!player->HasAura(SPELL_MIGHTY_RUPTURE_AURA))
                    {
                        if (Aura* rapids = player->AddAura(SPELL_MIGHTY_RUPTURE_AURA, player))
                        {
                            rapids->SetMaxDuration(2000);
                            rapids->SetDuration(2000);
                        }
                    }
                }
            }
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_mighty_rupture_AI(areatrigger);
    }
};

// 301807
class bfa_spell_zealous_eruption_periodic : public SpellScriptLoader
{
public:
    bfa_spell_zealous_eruption_periodic() : SpellScriptLoader("bfa_spell_zealous_eruption_periodic") { }

    class bfa_spell_zealous_eruption_periodic_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_zealous_eruption_periodic_AuraScript);

        void HandlePeriodic(AuraEffect const* aureff)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> playerList;
            caster->GetPlayerListInGrid(playerList, 150.0f);
            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    if (player->GetDistance(caster) > 16.0f)
                        player->CastSpell(player, SPELL_ZEALOUS_ERUPTION_DAMAGE, true);
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_zealous_eruption_periodic_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_zealous_eruption_periodic_AuraScript();
    }
};

class bfa_boss_pashmar_the_fanatical : public CreatureScript
{
public:
    bfa_boss_pashmar_the_fanatical() : CreatureScript("bfa_boss_pashmar_the_fanatical")
    {
    }

    struct bfa_boss_pashmar_the_fanatical_AI : public BossAI
    {
        bfa_boss_pashmar_the_fanatical_AI(Creature* creature) : BossAI(creature, DATA_THE_QUEENS_COURT), summons(me)
        {
            instance = creature->GetInstanceScript();
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
        }


        InstanceScript* instance;
        EventMap events;
        SummonList summons;
        bool _dead;

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case NPC_POTENT_SPARK:
                summon->AddUnitState(UNIT_STATE_ROOT);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, summon);
                break;
            case NPC_QUEEN_AZSHARA_DECREE:
                summon->AI()->DoAction(ACTION_INIT_DECREE);
                break;
            }
        }

        void JustDied(Unit* at)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void SummonedCreatureDies(Creature* summon, Unit* at)
        {
            switch (summon->GetEntry())
            {
            case NPC_POTENT_SPARK:
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, summon);
                break;
            }
        }

        void Reset()
        {
            _dead = false;
            events.Reset();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
          //  me->AddAura(AURA_OVERRIDE_POWER_COLOR_OCEAN);
        }

        void DamageTaken(Unit* at, uint32& damage)
        {
            if (damage >= me->GetHealth() && !_dead)
            {
                _dead = true;
                damage = 0;
                me->SetHealth(100);
                events.Reset();
                    if (Creature* silivaz = GetSilivaz())
                        silivaz->AI()->DoAction(ACTION_DEAD_KILL);
                me->CastSpell(me, SPELL_DESPERATE_MEASURES);
            }
        }

        void OnSpellFinished(SpellInfo const* spellInfo) //override
        {
            switch (spellInfo->Id)
            {
            case SPELL_DESPERATE_MEASURES:
            {
                _dead = false;
                events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
                events.ScheduleEvent(EVENT_POTENT_SPARK, TIMER_POTENT_SPARK);
                events.ScheduleEvent(EVENT_FANATICAL_VERDICT, TIMER_FANATICAL_VERDICT);
                break;
            }
            }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_DEAD_KILL:
                if (_dead)
                {
                    me->Kill(me);
                    if (Creature* silivaz = GetSilivaz())
                        silivaz->Kill(silivaz);
                }
                break;
            }
        }

        void EnterEvadeMode(EvadeReason w)
        {
            _DespawnAtEvade(15);
        }


        void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
        {
            if (!me)
                return;

            if (me)
            {
                switch (selectedTextSound)
                {
                case 1:
                    me->Yell(PASHMAR_SPECIAL_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 2:
                    me->Yell(PASHAMAR_AGGRO, LANG_UNIVERSAL, NULL);
                    break;
                case 3:
                    me->Yell(PASHMAR_KILLED_TARGET, LANG_UNIVERSAL, NULL);
                    break;
                }
            }
        }

        void KilledUnit(Unit* t)
        {
            SelectSoundAndText(me, 3);
        }

        void EnterCombat(Unit*)
        {
            SelectSoundAndText(me, 2);
            me->SummonCreature(NPC_QUEEN_AZSHARA_DECREE, decreeSpawnTrigger, TEMPSUMMON_MANUAL_DESPAWN);

            me->SetPower(POWER_ENERGY, 0);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            if (Creature* silivaz = GetSilivaz())
                silivaz->SetInCombatWithZone();

            me->AddAura(SPELL_PASHMARS_TOUCH, me);

            events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
            events.ScheduleEvent(EVENT_POTENT_SPARK, TIMER_POTENT_SPARK);
            events.ScheduleEvent(EVENT_FANATICAL_VERDICT, TIMER_FANATICAL_VERDICT);
        }

        Creature* GetSilivaz()
        {
            return me->FindNearestCreature(BOSS_SILIVAZ_THE_ZEALOUS, 200.0f, true);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_ENERGY:
                {
                    if (me->GetPower(POWER_ENERGY) >= 100)
                    {
                        events.ScheduleEvent(EVENT_VIOLENT_OUTBURST, TIMER_VIOLENT_OUTBURST);
                        me->SetPower(POWER_ENERGY, 0);
                    }

                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + urand(1, 2));
                    events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
                    break;
                }
                case EVENT_VIOLENT_OUTBURST:
                {
                    SelectSoundAndText(me, 1);
                    std::ostringstream str;
                    str << "Pashmar is casting |cFFF00000|h[Violent Outburst]|h|r!";
                    me->TextEmote(str.str().c_str(), 0, true);

                    me->CastSpell(me, SPELL_VIOLENT_OUTBURST);
                    break;
                }
                case EVENT_POTENT_SPARK:
                {
                    me->CastSpell(me, SPELL_POTENT_SPARK_CAST);
                    events.ScheduleEvent(EVENT_POTENT_SPARK, TIMER_POTENT_SPARK);
                    break;
                }
                case EVENT_FANATICAL_VERDICT:
                {
                    me->CastSpell(me, SPELL_FANATICAL_VERDICT_CAST);
                    events.ScheduleEvent(EVENT_FANATICAL_VERDICT, TIMER_FANATICAL_VERDICT);
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_pashmar_the_fanatical_AI(creature);
    }
};

// 301947
class bfa_spell_potent_spark_cast : public SpellScriptLoader
{
public:
    bfa_spell_potent_spark_cast() : SpellScriptLoader("bfa_spell_potent_spark_cast") { }

    class bfa_spell_potent_spark_cast_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_potent_spark_cast_SpellScript);

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            for (uint8 i = 0; i < 3; ++i)
            {
                Position random = caster->GetRandomPoint(centerPos, 30.0f);
                caster->CastSpell(random, SPELL_POTENT_SPARK_SUMMON, true);
            }

        }
        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_potent_spark_cast_SpellScript::HandleAfterCast);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_potent_spark_cast_SpellScript();
    }
};

class bfa_npc_potent_spark : public CreatureScript
{
public:
    bfa_npc_potent_spark() : CreatureScript("bfa_npc_potent_spark")
    {
    }

    struct bfa_npc_potent_spark_AI : public ScriptedAI
    {
        bfa_npc_potent_spark_AI(Creature* creature) : ScriptedAI(creature)
        {
        }

        bool _died;

        void Reset()
        {
            _died = false;
            me->AddAura(SPELL_POTENT_SPARK_AURA_SELF, me);
        }

        void DamageTaken(Unit* at, uint32& damage)
        {
            if (damage >= me->GetHealth() && _died)
            {
                _died = true;
                damage = 0;
                me->CastSpell(me, me->GetMap()->IsHeroic() ? SPELL_POTENT_SPARK_DAMAGE_HEROIC : SPELL_POTENT_SPARK_DAMAGE, true);
                me->DespawnOrUnsummon(500);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_potent_spark_AI(creature);
    }
};

// 296850
class bfa_spell_fanatical_verdict : public SpellScriptLoader
{
public:
    bfa_spell_fanatical_verdict() : SpellScriptLoader("bfa_spell_fanatical_verdict") { }

    class bfa_spell_fanatical_verdict_SpellScritp : public SpellScript
    {
        PrepareSpellScript(bfa_spell_fanatical_verdict_SpellScritp);

        void HandleScript()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> playerList;
            caster->GetPlayerListInGrid(playerList, 200.0f);
            playerList.remove_if(noTanks());
            if (playerList.size() >= (caster->GetMap()->IsMythic() ? 6 : 3))
                playerList.resize(caster->GetMap()->IsMythic() ? 6 : 3);

            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    player->AddAura(SPELL_FANATICAL_VERDICT_PRE_AURA, player);
                }
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_fanatical_verdict_SpellScritp::HandleScript);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_fanatical_verdict_SpellScritp();
    }
};

// 296851
class bfa_spell_fanatical_verdict_aura : public SpellScriptLoader
{
public:
    bfa_spell_fanatical_verdict_aura() : SpellScriptLoader("bfa_spell_fanatical_verdict_aura") { }

    class bfa_spell_fanatical_verdict_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_fanatical_verdict_aura_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget()->ToPlayer();
            if (!target)
                return;

            target->CastSpell(target, SPELL_FANATICAL_VERDICT_DAMAGE, true);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_fanatical_verdict_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_fanatical_verdict_aura_AuraScript();
    }
};

// 17397
class bfa_at_form_ranks : public AreaTriggerEntityScript
{
public:
    bfa_at_form_ranks() : AreaTriggerEntityScript("bfa_at_form_ranks") { }

    struct bfa_at_form_ranks_AI : AreaTriggerAI
    {
        bfa_at_form_ranks_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        uint32 despawn;

        void OnInitialize()
        {
            despawn = 5000;
        }

        void OnUpdate(uint32 diff)
        {
            if (despawn)
            {
                if (despawn <= diff)
                {
                    if (Creature* boss = at->FindNearestCreature(NPC_FORM_RANKS, 200.0f, true))
                    {
                        boss->CastSpell(at->GetPosition(), SPELL_FORM_RANKS_EXPLOSION, true);
                        boss->CastSpell(at->GetPosition(), SPELL_FORM_RANKS_DAMAGE, true);
                    }
                    at->Remove();
                    despawn = 5000;
                }
                else
                    despawn -= diff;
            }
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_form_ranks_AI(areatrigger);
    }
};

// 303227
class bfa_spell_form_ranks_damage : public SpellScriptLoader
{
public:
    bfa_spell_form_ranks_damage() : SpellScriptLoader("bfa_spell_form_ranks_damage") { }

    class bfa_spell_form_ranks_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_form_ranks_damage_SpellScript);

        uint32 targetList;

        bool Load() override
        {
            targetList = 0;
            return true;
        }

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            targetList = targets.size();
        }

        void RecalculateDamage(SpellEffIndex index)
        {
            if (targetList < 1)
            {
                SetHitDamage(GetHitDamage() + 6716 * 3);
            }
            else SetHitDamage(GetHitDamage());
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_form_ranks_damage_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_TARGET_ANY);
            OnEffectHitTarget += SpellEffectFn(bfa_spell_form_ranks_damage_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_form_ranks_damage_SpellScript();
    }
};

class bfa_npc_decree_controller : public CreatureScript
{
public:
    bfa_npc_decree_controller() : CreatureScript("bfa_npc_decree_controller")
    {
    }

    struct bfa_npc_decree_controller_AI : public ScriptedAI
    {
        bfa_npc_decree_controller_AI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            creature->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            creature->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
        }

        EventMap events;
        SummonList summons;

        void Reset()
        {
            events.Reset();
        }

        void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
        {
            if (!me)
                return;

            if (me)
            {
                switch (selectedTextSound)
                {
                case 1:
                    me->Yell(DECREE_SPECIAL_1, LANG_UNIVERSAL, NULL);
                    break;
                case 2:
                    me->Yell(DECREE_SPECIAL_2, LANG_UNIVERSAL, NULL);
                    break;
                }
            }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_INIT_DECREE:
            {
                events.ScheduleEvent(EVENT_FORM_RANKS, TIMER_DECREE_START);
                if (me->GetMap()->IsMythic())
                {
                    for (uint8 i = 0; i < 5; ++i)
                        me->SummonCreature(DecreeFlags[i], flagPos[i], TEMPSUMMON_MANUAL_DESPAWN);
                }
                break;
            }
            }
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case NPC_FORM_RANKS:
            case NPC_OBEY_OR_SUFFER:
            case NPC_DEFERRED_SENTENCE:
            case NPC_STAND_ALONE:
            case NPC_REPEAT_PERFORMANCE:
                summon->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                summon->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                summon->AddUnitState(UNIT_STATE_ROOT);
                break;
            }
        }

        void HandleSphereOfInfluence(uint32 entry, uint32 spellId)
        {
            std::list<Creature*> flagsList;
            me->GetCreatureListWithEntryInGrid(flagsList, NPC_FORM_RANKS, 200.0f);
            me->GetCreatureListWithEntryInGrid(flagsList, NPC_STAND_ALONE, 200.0f);
            me->GetCreatureListWithEntryInGrid(flagsList, NPC_OBEY_OR_SUFFER, 200.0f);
            me->GetCreatureListWithEntryInGrid(flagsList, NPC_DEFERRED_SENTENCE, 200.0f);
            me->GetCreatureListWithEntryInGrid(flagsList, NPC_REPEAT_PERFORMANCE, 200.0f);
            if (!flagsList.empty())
            {
                for (auto flag : flagsList)
                {
                    for (uint8 i = 0; i < 5; ++i)
                        flag->RemoveAura(DecreeAreaTriggerSpellByFlag[i]);
                    flag->CastSpell(entry, spellId, true);
                }
            }
        }

        void DamageTaken(Unit* d, uint32& damage)
        {
            damage = 0;
        }

        void FormRanks()
        {
            for (uint8 i = 0; i < (me->GetMap()->IsMythic() ? 6 : 3); ++i)
            {
                Position random = me->GetRandomPoint(centerPos, me->GetMap()->IsMythic() ? 40.0f : 15.0f);
                me->CastSpell(random, SPELL_FORM_RANKS_AT, true);
            }

            me->GetScheduler().Schedule(5s, [this](TaskContext /*context*/)
                {
                    for (uint8 i = 0; i < (me->GetMap()->IsMythic() ? 6 : 3); ++i)
                    {
                        Position random = me->GetRandomPoint(centerPos, me->GetMap()->IsMythic() ? 40.0f : 15.0f);
                        me->CastSpell(random, SPELL_FORM_RANKS_AT, true);
                    }
                });

            me->GetScheduler().Schedule(10s, [this](TaskContext /*context*/)
                {
                    for (uint8 i = 0; i < (me->GetMap()->IsMythic() ? 6 : 3); ++i)
                    {
                        Position random = me->GetRandomPoint(centerPos, me->GetMap()->IsMythic() ? 40.0f : 15.0f);
                        me->CastSpell(random, SPELL_FORM_RANKS_AT, true);
                    }
                });
        }

        void StandAlone()
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 200.0f);
            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    player->AddAura(SPELL_STAND_ALONE_VISUAL_AURA, player);
                }
            }
        }

        void ObeyOrSuffer()
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 200.0f);
            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    player->AddAura(SPELL_OBEY_OR_SUFFER, player);
                }
            }
        }

        void RepeatPerformance()
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 200.0f);
            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    player->AddAura(SPELL_REPEAT_PERFORMANCE_PROC_CHECK, player);
                }
            }
        }

        void DeferredSentence()
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 200.0f);
            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    player->AddAura(SPELL_DEFFERED_SENTENCE_PERIODIC, player);
                }
            }
        }

        void SelectDecreeText(uint32 text_id)
        {
            switch (text_id)
            {
            case 1:
            {
                SelectSoundAndText(me, urand(1, 2));
                std::ostringstream str;
                str << "Queen Azshara enacts her decree |cFFF00000|h[Form Ranks]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case 2:
            {
                SelectSoundAndText(me, urand(1, 2));
                std::ostringstream str;
                str << "Queen Azshara enacts her decree |cFFF00000|h[Stand Alone]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case 3:
            {
                SelectSoundAndText(me, urand(1, 2));
                std::ostringstream str;
                str << "Queen Azshara enacts her decree |cFFF00000|h[Deferred Sentence]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case 4:
            {
                SelectSoundAndText(me, urand(1, 2));
                std::ostringstream str;
                str << "Queen Azshara enacts her decree |cFFF00000|h[Obey and Suffer]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            case 5:
            {
                SelectSoundAndText(me, urand(1, 2));
                std::ostringstream str;
                str << "Queen Azshara enacts her decree |cFFF00000|h[Repeat Performance]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                break;
            }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_FORM_RANKS:
                {
                    FormRanks();
                    SelectDecreeText(1);
                    HandleSphereOfInfluence(NPC_FORM_RANKS, SPELL_FORM_RANKS_MYTHIC_AT);
                    if (me->GetMap()->IsMythic())
                    {
                        events.ScheduleEvent(EVENT_STAND_ALONE, TIMER_DECREE_NEXT_MYTHIC);
                    }
                    else if (me->GetMap()->IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_STAND_ALONE, TIMER_DECREE_NEXT_HEROIC);
                    }
                   // else if (me->GetMap()->IsNormal() || me->GetMap()->IsLFR())
                    {
                        events.ScheduleEvent(EVENT_STAND_ALONE, TIMER_DECREE_NEXT);
                    }
                    break;
                }
                case EVENT_STAND_ALONE:
                {
                    StandAlone();
                    SelectDecreeText(2);
                    HandleSphereOfInfluence(NPC_STAND_ALONE, SPELL_STAND_ALONE_MYTHIC_AT);
                    if (me->GetMap()->IsMythic())
                    {
                        events.ScheduleEvent(EVENT_REPEAT_PERFORMANCE, TIMER_DECREE_NEXT_MYTHIC);
                    }
                    else if (me->GetMap()->IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_REPEAT_PERFORMANCE, TIMER_DECREE_NEXT_HEROIC);
                    }
                 //   else if (me->GetMap()->IsNormal() || me->GetMap()->IsLFR())
                    {
                        events.ScheduleEvent(EVENT_REPEAT_PERFORMANCE, TIMER_DECREE_NEXT);
                    }
                    break;
                }
                case EVENT_REPEAT_PERFORMANCE:
                {
                    RepeatPerformance();
                    SelectDecreeText(3);
                    HandleSphereOfInfluence(NPC_REPEAT_PERFORMANCE, SPELL_REPEAT_PERFORMANCE_MYTHIC_AT);
                    if (me->GetMap()->IsMythic())
                    {
                        events.ScheduleEvent(EVENT_DEFERRED_SENTENCE, TIMER_DECREE_NEXT_MYTHIC);
                    }
                    else if (me->GetMap()->IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_DEFERRED_SENTENCE, TIMER_DECREE_NEXT_HEROIC);
                    }
                  //  else if (me->GetMap()->IsNormal() || me->GetMap()->IsLFR())
                    {
                        events.ScheduleEvent(EVENT_DEFERRED_SENTENCE, TIMER_DECREE_NEXT);
                    }
                    break;
                }
                case EVENT_DEFERRED_SENTENCE:
                {
                    DeferredSentence();
                    SelectDecreeText(5);
                    HandleSphereOfInfluence(NPC_DEFERRED_SENTENCE, SPELL_DEFERRED_SENTENCE_MYTHIC_AT);
                    if (me->GetMap()->IsMythic())
                    {
                        events.ScheduleEvent(EVENT_OBEY_OR_SUFFER, TIMER_DECREE_NEXT_MYTHIC);
                    }
                    else if (me->GetMap()->IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_OBEY_OR_SUFFER, TIMER_DECREE_NEXT_HEROIC);
                    }
                 //   else if (me->GetMap()->IsNormal() || me->GetMap()->IsLFR())
                    {
                        events.ScheduleEvent(EVENT_OBEY_OR_SUFFER, TIMER_DECREE_NEXT);
                    }
                    break;
                }
                case EVENT_OBEY_OR_SUFFER:
                {
                    ObeyOrSuffer();
                    SelectDecreeText(4);
                    HandleSphereOfInfluence(NPC_OBEY_OR_SUFFER, SPELL_OBEY_OR_SUFFER_MYTHIC_AT);
                    if (me->GetMap()->IsMythic())
                    {
                        events.ScheduleEvent(EVENT_FORM_RANKS, TIMER_DECREE_NEXT_MYTHIC);
                    }
                    else if (me->GetMap()->IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_FORM_RANKS, TIMER_DECREE_NEXT_HEROIC);
                    }
                //    else if (me->GetMap()->IsNormal() || me->GetMap()->IsLFR())
                    {
                        events.ScheduleEvent(EVENT_FORM_RANKS, TIMER_DECREE_NEXT);
                    }
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_decree_controller_AI(creature);
    }
};

// 301244
class bfa_spell_repeat_performance : public SpellScriptLoader
{
public:
    bfa_spell_repeat_performance() : SpellScriptLoader("bfa_spell_repeat_performance") { }

    class bfa_spell_repeat_performance_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_repeat_performance_AuraScript);

        uint32 _sameSpell;

        bool Load()
        {
            _sameSpell = 1; // 1 because it was already initialized when aura is applied, same ability again > apply aura
            return true;
        }

        void HandleOnProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            Unit* caster = eventInfo.GetActor();
            Unit* target = eventInfo.GetActionTarget();

            if (!caster || !target)
                return;

            _sameSpell = eventInfo.GetSpellInfo()->Id;

            if (_sameSpell > 2)
                target->CastSpell(target, SPELL_REPEAT_PERFORMANCE_AURA, true);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(bfa_spell_repeat_performance_AuraScript::HandleOnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_repeat_performance_AuraScript();
    }
};

// 297564
class spell_deferred_sentence_periodic : public SpellScriptLoader
{
public:
    spell_deferred_sentence_periodic() : SpellScriptLoader("spell_deferred_sentence_periodic") { }

    class spell_deferred_sentence_periodic_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_deferred_sentence_periodic_AuraScript);

        void HandlePeriodic(AuraEffect const* aureff)
        {
            Unit* target = GetCaster();
            if (!target)
                return;

            if (Aura* stacks = target->GetAura(SPELL_DEFERRED_SENTENCE_AURA_STACK))
            {
                if (target->isMoving())
                {
                    stacks->SetStackAmount(stacks->GetStackAmount() + 1);
                }
                else if (!target->isMoving())
                {
                    target->CastSpell(target, SPELL_DEFERRED_SENTENCE_DAMAGE, true);
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_deferred_sentence_periodic_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new spell_deferred_sentence_periodic_AuraScript();
    }
};

// 297578
class bfa_spell_deferred_sentence_damage : public SpellScriptLoader
{
public:
    bfa_spell_deferred_sentence_damage() : SpellScriptLoader("bfa_spell_deferred_sentence_damage") { }

    class bfa_spell_deferred_sentence_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_deferred_sentence_damage_SpellScript);

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (Aura* stacks = caster->GetAura(SPELL_DEFERRED_SENTENCE_AURA_STACK))
            {
                uint32 _damage = stacks->GetStackAmount();
                SetHitDamage(GetHitDamage() * _damage);
                stacks->SetStackAmount(1);
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_deferred_sentence_damage_SpellScript::HandleAfterCast);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_deferred_sentence_damage_SpellScript();
    }
};

// 297648
class bfa_spell_stand_alone_court : public SpellScriptLoader
{
public:
    bfa_spell_stand_alone_court() : SpellScriptLoader("bfa_spell_stand_alone_court") { }

    class bfa_spell_stand_alone_court_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_stand_alone_court_AuraScript);

        void HandlePeriodic(AuraEffect const* aureff)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> players;
            Map::PlayerList const& playerList = caster->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    if (player->IsAlive())
                        players.push_back(player);
            Player* validTarget = NULL;
            uint32 expectedPlayers = 2;
            if (players.size())
            {
                for (auto initialPlayer : players)
                {
                    uint32 count = 1; // initial player
                    for (auto otherPlayer : players)
                    {
                        if (initialPlayer == otherPlayer)
                            continue;
                        if (initialPlayer->GetDistance2d(otherPlayer) <= 3.0f)
                            count++;
                    }
                    if (count >= expectedPlayers)
                    {
                        validTarget = initialPlayer;
                        break;
                    }
                }
            }
            if (validTarget)
            {
                caster->CastSpell(caster, SPELL_STAND_ALONE_DAMAGE, true);
                caster->CastSpell(validTarget, SPELL_STAND_ALONE_DAMAGE, true);
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_stand_alone_court_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_stand_alone_court_AuraScript();
    }
};

void AddSC_boss_queens_court()
{
    new bfa_boss_pashmar_the_fanatical();
    new bfa_boss_silivaz_the_zealous();
    new bfa_npc_decree_controller();
    new bfa_npc_potent_spark();
    new bfa_at_flags_spell();
    new bfa_at_form_ranks();
    new bfa_at_mighty_rupture();
    new bfa_spell_fanatical_verdict();
    new bfa_spell_commanders_fury();
    new bfa_spell_deferred_sentence_damage();
    new bfa_spell_fanatical_verdict_aura();
    new bfa_spell_form_ranks_damage();
    new bfa_spell_frenetic_charge_at_create();
    new bfa_spell_frenetic_charge_cast();
    new bfa_spell_frenetic_charge_damage();
    new bfa_spell_potent_spark_cast();
    new spell_deferred_sentence_periodic();
    new bfa_spell_repeat_performance();
    new bfa_spell_stand_alone_court();
    new bfa_spell_zealous_eruption_periodic();
}
