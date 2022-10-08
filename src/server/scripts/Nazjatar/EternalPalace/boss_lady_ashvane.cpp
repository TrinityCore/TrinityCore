#include "eternal_palace.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "AreaTriggerTemplate.h"
#include "GridNotifiers.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "G3D/Vector3.h"

enum Spells
{
    SPELL_HARDENED_CARAPACE = 296650,
    SPELL_HARDENED_CARAPACE_BAR = 296861,
    SPELL_HARDENED_CARAPACE_DUMMY = 297240,
    
    SPELL_CORAL_GROWTH_MISSILE = 296554,
    SPELL_CORAL_GROWTH_SUMMON = 296555,
    SPELL_CORAL_GROWTH_VISUAL  = 296556,

    SPELL_RIPPLING_WAVE_DAMAGE = 296688,
    SPELL_RIPPLING_WAVE_CAST = 296662,
    SPELL_RIPPLING_WAVE_AT = 296671,
    SPELL_EMPOWERED_RIPPLING_WAVE_AT = 302779,

    SPELL_WATERLOGGED = 296693,

    SPELL_CUTTING_CORAL_AT_BOSS = 296726, //13
    SPELL_CUTTING_CORAL_DAMAGE = 296752,
    SPELL_CUTTING_CORAL_AT_ADD = 302534, //7

    SPELL_UPSURGE_DAMAGE = 298054,
    SPELL_UPSURGE_MISSILE = 298055,

    SPELL_BRINY_BUBBLE_AURA = 302992,
    SPELL_BRINY_BUBBLE_PRE_AURA_MYTHIC = 297397,
    SPELL_BRINY_BUBBLE_PRE_AURA = 302989,
    SPELL_BRINY_BUBBLE_CAST = 297402,
    SPELL_BRINY_BUBBLE_NPC_VISUAL = 297338,

    SPELL_BARNACLE_BASH = 296725,

    SPELL_EXPOSED_AZERITE_AURA = 297201,
    SPELL_EXPOSED_AZERITE_DAMAGE = 297206,

    // Controller spell casts on marked spell, thx blizz
    SPELL_ARCING_AZERITE_DAMAGE = 296944,
    SPELL_ARCING_AZERITE_YELLOW_MARK = 296938,
    SPELL_ARCING_AZERITE_RED_MARK = 296939,
    SPELL_ARCING_AZERITE_BLUE_MARK = 296940,
    
    SPELL_ARCING_AZERITE_YELLOW_CONTROLLER = 296941,
    SPELL_ARCING_AZERITE_RED_CONTROLLER = 296942,
    SPELL_ARCING_AZERITE_BLUE_CONTROLLER = 296943,

    SPELL_REGENERATIVE_CORAL_AT = 302844,
    SPELL_REGENERATIVE_CORAL_MISSILE = 302851,
    SPELL_REGENERATIVE_CORAL_DAMAGE = 302855,
};

enum Events
{
    EVENT_CORAL_GROWTH = 1,

    EVENT_RIPPLING_WAVE,

    EVENT_UPSURGE,

    EVENT_BRINY_BUBBLE,

    EVENT_BARNACLE_BASH,

    EVENT_EXPOSED_AZERITE,

    //MISC
    EVENT_PHASE_2_BAR_REGEN,
};

enum Timers
{
    TIMER_CORAL_GROWTH = 25 * IN_MILLISECONDS,
    TIMER_CORAL_GROWTH_AFTER = 50 * IN_MILLISECONDS,

    TIMER_RIPPLING_WAVE = 15 * IN_MILLISECONDS,
    TIMER_RIPPLING_WAVE_AFTER = 30 * IN_MILLISECONDS,

    TIMER_UPSURGE = 3 * IN_MILLISECONDS,
    TIMER_UPSURGE_AFTER = 18 * IN_MILLISECONDS,

    TIMER_BRINY_BUBBLE = 45 * IN_MILLISECONDS,

    TIMER_EXPOSED_AZERITE = 40 * IN_MILLISECONDS,

    TIMER_BARNACLE_BASH = 7 * IN_MILLISECONDS,
    TIMER_BARNACLE_BASH_AFTER = 15 * IN_MILLISECONDS,

    //misc
    TIMER_PHASE_2_BAR_REGEN = 1 * IN_MILLISECONDS,
};

const Position centerPos = { 298.22f, 634.11f, 1284.72f }; //55y checks, 35y for corals

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

uint32 ArcingAzeriteColors[6] =
{
    SPELL_ARCING_AZERITE_YELLOW_MARK,
    SPELL_ARCING_AZERITE_RED_MARK,
    SPELL_ARCING_AZERITE_BLUE_MARK,
    SPELL_ARCING_AZERITE_YELLOW_CONTROLLER,
    SPELL_ARCING_AZERITE_RED_CONTROLLER,
    SPELL_ARCING_AZERITE_BLUE_CONTROLLER
};

#define AGGRO_TEXT "You! I'll tear you apart!"
#define BASH_TEXT "Die, vermin!"
#define EXPOSED_AZERITE "Azerite is mine to wield!"
#define BUBBLE_TEXT "Your corpses will feed the depths!"
#define PHASE1_TEXT "You should have killed me when you had the chance."
#define DEATH_TEXT "Is this true power?"
#define SIGHT_TEXT "How long I've waited for that."

class bfa_boss_lady_ashvane : public CreatureScript
{
public:
    bfa_boss_lady_ashvane() : CreatureScript("bfa_boss_lady_ashvane")
    {
    }

    struct bfa_boss_lady_ashvane_AI : public BossAI
    {
        bfa_boss_lady_ashvane_AI(Creature* creature) : BossAI(creature, DATA_LADY_ASHVANE), summons(me)
        {
            instance = creature->GetInstanceScript();
            introText = false;
        }

        InstanceScript* instance;
        EventMap events;
        SummonList summons;
        uint32 _carapace;
        uint32 azeriteCount = 6;
        bool introText;

        void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
        {
            if (!me)
                return;

            if (me)
            {
                switch (selectedTextSound)
                {
                case 1:
                    me->Yell(AGGRO_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 2:
                    me->Yell(DEATH_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 3:
                    me->Yell(SIGHT_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 4:
                    me->Yell(EXPOSED_AZERITE, LANG_UNIVERSAL, NULL);
                    break;
                case 5:
                    me->Yell(BUBBLE_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 6:
                    me->Yell(PHASE1_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 7:
                    me->Yell(BASH_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                }
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!introText)
            {
                Map::PlayerList const& lPlayers = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                    if (Player* pPlayer = itr->GetSource())
                        if (pPlayer->IsAlive() && pPlayer->IsWithinDist(me, 65.f))
                        {
                            SelectSoundAndText(me, 3);
                            introText = true;
                            return;
                        }
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case NPC_CORAL_GROWTH:
                summon->AddUnitState(UNIT_STATE_ROOT);
                break;
            }
        }

        void Reset() override
        {
            summons.DespawnAll();
            me->RemoveAllAreaTriggers();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void JustDied(Unit*) override
        {
            summons.DespawnAll();
            SelectSoundAndText(me, 2);
            me->RemoveAllAreaTriggers();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void EnterEvadeMode(EvadeReason w) override
        {
            _DespawnAtEvade(15);
        }

        void HandlePhases(uint32 phaseId)
        {
            switch (phaseId)
            {
            case 1:
            {
                events.Reset();
                if (me->HasAura(SPELL_HARDENED_CARAPACE_BAR))
                    me->RemoveAura(SPELL_HARDENED_CARAPACE_BAR);

                events.ScheduleEvent(EVENT_BARNACLE_BASH, TIMER_BARNACLE_BASH);
                events.ScheduleEvent(EVENT_BRINY_BUBBLE, TIMER_BRINY_BUBBLE);
                events.ScheduleEvent(EVENT_UPSURGE, TIMER_UPSURGE);

                events.ScheduleEvent(EVENT_CORAL_GROWTH, TIMER_CORAL_GROWTH);
                events.ScheduleEvent(EVENT_RIPPLING_WAVE, TIMER_RIPPLING_WAVE);
                break;
            }
            case 2:
            {
                events.Reset();
                if(me->GetPower(POWER_ALTERNATE_POWER) >= 1)
                    me->SetPower(POWER_ALTERNATE_POWER, 0);

                me->AddAura(SPELL_HARDENED_CARAPACE_BAR, me);
                events.ScheduleEvent(EVENT_PHASE_2_BAR_REGEN, TIMER_PHASE_2_BAR_REGEN);
                events.ScheduleEvent(EVENT_EXPOSED_AZERITE, TIMER_EXPOSED_AZERITE);

                events.ScheduleEvent(EVENT_BARNACLE_BASH, TIMER_BARNACLE_BASH);
                events.ScheduleEvent(EVENT_BRINY_BUBBLE, TIMER_BRINY_BUBBLE);
                events.ScheduleEvent(EVENT_UPSURGE, TIMER_UPSURGE);
                break;
            }
            }
        }

        void EnterCombat(Unit*) override
        {
            HandlePhases(1);
            _carapace = 0;
            SelectSoundAndText(me, 1);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        }

        void UpdateAI(uint32 diff) override
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
                case EVENT_PHASE_2_BAR_REGEN:
                {
                    me->SetPower(POWER_ALTERNATE_POWER, me->GetPower(POWER_ALTERNATE_POWER) + 1);

                    if (me->GetPower(POWER_ALTERNATE_POWER) == 100)
                    {
                        HandlePhases(1);
                        SelectSoundAndText(me, 6);
                        me->CastSpell(me, SPELL_HARDENED_CARAPACE_DUMMY);
                        ++_carapace;
                    }
                    events.ScheduleEvent(EVENT_PHASE_2_BAR_REGEN, TIMER_PHASE_2_BAR_REGEN);
                    break;
                }
                case EVENT_BARNACLE_BASH:
                {
                    SelectSoundAndText(me, 7);
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_BARNACLE_BASH);

                    events.ScheduleEvent(EVENT_BARNACLE_BASH, TIMER_BARNACLE_BASH_AFTER);
                    break;
                }
                case EVENT_UPSURGE:
                {
                    std::list<Player*> playerList;
                    me->GetPlayerListInGrid(playerList, 100.0f);
                    playerList.remove_if(noTanks());

                    if (playerList.size())
                        playerList.resize(me->GetMap()->IsMythic() ? 6 : 3);

                    if (!playerList.empty())
                    {
                        for (auto player : playerList)
                        {
                            me->CastSpell(player, SPELL_UPSURGE_MISSILE);
                        }
                    }

                    events.ScheduleEvent(EVENT_UPSURGE, TIMER_UPSURGE_AFTER);
                    break;
                }
                case EVENT_CORAL_GROWTH:
                {
                    for (uint8 i = 0; i < (me->GetMap()->IsMythic() ? 3 : 2); ++i)
                    {
                        Position pos = me->GetRandomPoint(centerPos, 35.0f);
                        me->CastSpell(pos, SPELL_CORAL_GROWTH_MISSILE);
                    }

                    events.ScheduleEvent(EVENT_CORAL_GROWTH, TIMER_CORAL_GROWTH_AFTER);
                    break;
                }
                case EVENT_RIPPLING_WAVE:
                {
                    me->CastSpell(me, SPELL_RIPPLING_WAVE_CAST);
                    events.ScheduleEvent(EVENT_RIPPLING_WAVE, TIMER_RIPPLING_WAVE);
                    break;
                }
                case EVENT_BRINY_BUBBLE:
                    SelectSoundAndText(me, 5);
                    me->CastSpell(me, SPELL_BRINY_BUBBLE_CAST);
                    events.ScheduleEvent(EVENT_BRINY_BUBBLE, TIMER_BRINY_BUBBLE);
                    break;
                case EVENT_EXPOSED_AZERITE:
                    SelectSoundAndText(me, 4);
                    HandleExposedAzeriteMain();
                    events.ScheduleEvent(EVENT_EXPOSED_AZERITE, TIMER_EXPOSED_AZERITE);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void HandleExposedAzeriteMain()
        {
            for (uint32 i = 0; i < azeriteCount; i++)
            {
                std::list<Player*> playerList;
                me->GetPlayerListInGrid(playerList, 100.0f);
                if (playerList.size() >= azeriteCount)
                    playerList.resize(azeriteCount);

                for (std::list<Player*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                {
                    me->CastSpell((*itr), ArcingAzeriteColors[azeriteCount], true);
                }
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_lady_ashvane_AI(creature);
    }
};

// 296662
class bfa_spell_rippling_wave_cast : public SpellScriptLoader
{
public:
    bfa_spell_rippling_wave_cast() : SpellScriptLoader("bfa_spell_rippling_wave_cast") { }

    class bfa_spell_rippling_wave_cast_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_rippling_wave_cast_SpellScript);

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Creature*> coralList;
            std::list<Creature*> mostDistCoral;
            caster->GetCreatureListWithEntryInGrid(coralList, NPC_CORAL_GROWTH, 100.0f);

            coralList.sort(Trinity::DistanceOrderPred(caster)); // mythic requires the most distant to be empowered
            mostDistCoral.push_back(coralList.front());
            coralList.remove(coralList.front());
            if (!coralList.empty())
            {
                for (auto coral : coralList)
                {
                    coral->CastSpell(coral, SPELL_RIPPLING_WAVE_AT, true);
                }
            }

            if (mostDistCoral.size() >= 1)
                mostDistCoral.resize(1);

            if (!mostDistCoral.empty())
            {
                if (caster->GetMap()->IsMythic())
                {
                    for (auto empowered : mostDistCoral)
                        empowered->CastSpell(empowered, SPELL_EMPOWERED_RIPPLING_WAVE_AT, true);
                }
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_rippling_wave_cast_SpellScript::HandleAfterCast);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_rippling_wave_cast_SpellScript();
    }
};

// 296726
class bfa_spell_barnacle_bash : public SpellScriptLoader
{
public:
    bfa_spell_barnacle_bash() : SpellScriptLoader("bfa_spell_barnacle_bash") { }

    class bfa_spell_barnacle_bash_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_barnacle_bash_SpellScript);

        void HandleAfterCast(SpellEffIndex)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_CUTTING_CORAL_AT_BOSS, true);
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(bfa_spell_barnacle_bash_SpellScript::HandleAfterCast, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_barnacle_bash_SpellScript();
    }
};

// 16727
class bfa_at_cutting_coral_ashvane : public AreaTriggerEntityScript
{
public:
    bfa_at_cutting_coral_ashvane() : AreaTriggerEntityScript("bfa_at_cutting_coral_ashvane") { }

    struct bfa_at_cutting_coral_ashvane_AI : AreaTriggerAI
    {
        bfa_at_cutting_coral_ashvane_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        uint32 m_CheckTimer;
        uint32 despawn;

        void OnInitialize() override
        {
            despawn = 60000;
            m_CheckTimer = 1000;
        }

        void OnUpdate(uint32 diff) override
        {
            if (at->GetMap()->IsNormal())
            {
                if (despawn)
                {
                    if (despawn <= diff)
                    {
                        at->Remove();
                        despawn = 1000;
                    }
                    else
                        despawn -= diff;
                }
            }

            if (m_CheckTimer)
            {
                if (m_CheckTimer <= diff)
                {
                    std::list<Player*> playerList;
                    at->GetPlayerListInGrid(playerList, 13.0f);
                    if (!playerList.empty())
                    {
                        for (auto player : playerList)
                        {
                            if (Aura* cutting = player->AddAura(SPELL_CUTTING_CORAL_DAMAGE, player))
                            {
                                cutting->SetMaxDuration(2000);
                                cutting->SetDuration(2000);
                            }
                        }
                    }
                    m_CheckTimer = 1000;
                }
                else
                    m_CheckTimer -= diff;
            }
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_cutting_coral_ashvane_AI(areatrigger);
    }
};

// 17327
class bfa_at_cutting_coral_growth : public AreaTriggerEntityScript
{
public:
    bfa_at_cutting_coral_growth() : AreaTriggerEntityScript("bfa_at_cutting_coral_growth") { }

    struct bfa_at_cutting_coral_growth_AI : AreaTriggerAI
    {
        bfa_at_cutting_coral_growth_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        uint32 m_CheckTimer;

        void OnInitialize() override
        {
            m_CheckTimer = 1000;
        }

        void OnUpdate(uint32 diff) override
        {

            if (m_CheckTimer)
            {
                if (m_CheckTimer <= diff)
                {
                    std::list<Player*> playerList;
                    at->GetPlayerListInGrid(playerList, 8.0f);
                    if (!playerList.empty())
                    {
                        for (auto player : playerList)
                        {
                            if (Aura* cutting = player->AddAura(SPELL_CUTTING_CORAL_DAMAGE, player))
                            {
                                cutting->SetMaxDuration(2000);
                                cutting->SetDuration(2000);
                            }
                        }
                    }
                    m_CheckTimer = 1000;
                }
                else
                    m_CheckTimer -= diff;
            }
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_cutting_coral_growth_AI(areatrigger);
    }
};

class bfa_npc_coral_growth : public CreatureScript
{
public:
    bfa_npc_coral_growth() : CreatureScript("bfa_npc_coral_growth")
    {
    }

    struct bfa_npc_script_ai_AI : public ScriptedAI
    {
        bfa_npc_script_ai_AI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            me->AddAura(SPELL_CORAL_GROWTH_VISUAL, me);
            me->CastSpell(me, SPELL_CUTTING_CORAL_AT_ADD, true);
        }

        void JustDied(Unit*) override
        {
            if (me->GetMap()->IsMythic())
            {
                for (uint8 i = 0; i < 4; ++i)
                {
                    Position random = me->GetRandomPoint(me->GetPosition(), 20.0f);
                    me->CastSpell(random, SPELL_REGENERATIVE_CORAL_MISSILE);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_script_ai_AI(creature);
    }
};

// 302855
class bfa_spell_regenerative_coral_dummy : public SpellScriptLoader
{
public:
    bfa_spell_regenerative_coral_dummy() : SpellScriptLoader("bfa_spell_regenerative_coral_dummy") { }

    class bfa_spell_regenerative_coral_dummy_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_regenerative_coral_dummy_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (WorldLocation const* target = GetExplTargetDest())
                    caster->CastSpell(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), SPELL_CORAL_GROWTH_SUMMON, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_regenerative_coral_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new bfa_spell_regenerative_coral_dummy_SpellScript();
    }
};

// 297240
class bfa_spell_hardened_carapace_cast : public SpellScriptLoader
{
public:
    bfa_spell_hardened_carapace_cast() : SpellScriptLoader("bfa_spell_hardened_carapace_cast") { }

    class bfa_spell_hardened_carapace_cast_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_hardened_carapace_cast_SpellScript);

        void HandleDummy()
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_HARDENED_CARAPACE, true);
        }

        void Register() override
        {
            AfterCast += SpellCastFn(bfa_spell_hardened_carapace_cast_SpellScript::HandleDummy);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new bfa_spell_hardened_carapace_cast_SpellScript();
    }
};

// 296650
class bfa_spell_hardened_carapace_aura : public SpellScriptLoader
{
public:
    bfa_spell_hardened_carapace_aura() : SpellScriptLoader("bfa_spell_hardened_carapace_aura") { }

    class bfa_spell_hardened_carapace_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_hardened_carapace_aura_AuraScript);

        void CalculateAmount(AuraEffect const* auraEffect, int32& amount, bool& /*canBeRecalculated*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            float base_multiplier;
            uint32 carapaceCasted;

            if (Creature* lady = caster->ToCreature())
            {
                bfa_boss_lady_ashvane::bfa_boss_lady_ashvane_AI* ai = CAST_AI(bfa_boss_lady_ashvane::bfa_boss_lady_ashvane_AI, lady->GetAI());

                carapaceCasted = ai->_carapace;
            }

            if (carapaceCasted >= 1)
                base_multiplier = 0.150f; // applly multiplier only when another carapace is casted
            else
                base_multiplier = 0;

            int32 totalAmount = base_multiplier * carapaceCasted;
            amount += GetCaster()->CountPctFromMaxHealth(40) * totalAmount;
        }

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            if (Creature* lady = caster->ToCreature())
            {
                bfa_boss_lady_ashvane::bfa_boss_lady_ashvane_AI* ai = CAST_AI(bfa_boss_lady_ashvane::bfa_boss_lady_ashvane_AI, lady->GetAI());

                ai->HandlePhases(2);
            }
        }

        void Register()
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(bfa_spell_hardened_carapace_aura_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_hardened_carapace_aura_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_hardened_carapace_aura_AuraScript();
    }
};

// 16715
class bfa_at_rippling_wave : public AreaTriggerEntityScript
{
public:
    bfa_at_rippling_wave() : AreaTriggerEntityScript("bfa_at_rippling_wave") { }

    struct bfa_at_rippling_wave_AI : AreaTriggerAI
    {
        bfa_at_rippling_wave_AI(AreaTrigger* at) : AreaTriggerAI(at) { }

        uint32 cooldownDamage;
        float x;
        float y;

        Creature* GetLady()
        {
            return at->FindNearestCreature(BOSS_LADY_ASHVANE, 100.0f, true);
        }

        void OnInitialize() override
        {
            CheckDistanceBoss();
        }

        void CheckDistanceBoss() // boss moves and initialize only take that point
        {
            if (Creature* lady = GetLady())
            {
                x = lady->GetPositionX();
                y = lady->GetPositionY();
            }
            std::vector<G3D::Vector3> points;
            points.push_back(G3D::Vector3(at->GetPositionX(), at->GetPositionY(), at->GetPositionZ()));
            points.push_back(G3D::Vector3(x, y, at->GetPositionZ()));
            at->InitSplines(points, 10000);
        }

        void OnUnitEnter(Unit* unit)
        {
            if (Creature* lady = GetLady())
            {
                if (Aura* carapace = lady->GetAura(SPELL_HARDENED_CARAPACE))
                {
                    int32 newAmount = lady->CountPctFromMaxHealth(10); // 10% to add
                    int32 base = carapace->GetEffect(EFFECT_0)->GetAmount(); // current amount
                    uint32 totalAmountToAdd = base + newAmount; // ++
                    carapace->GetEffect(EFFECT_0)->SetAmount(totalAmountToAdd);
                }
                at->Remove();
            }
        }

        void OnUpdate(uint32 time) override
        {
            if (cooldownDamage > 0)
                cooldownDamage -= time;
            else
            {
                CheckDistanceBoss();          
                std::list<Player*> playerList;
                at->GetPlayerListInGrid(playerList, 2.0f);
                if (!playerList.empty())
                {
                    for (auto player : playerList)
                    {
                        if (Aura* waterlog = player->AddAura(SPELL_WATERLOGGED, player))
                        {
                            if (player->GetMap()->IsMythic())
                            {
                                waterlog->SetMaxDuration(1200000);
                                waterlog->SetDuration(1200000);
                            }
                        }
                        player->CastSpell(player, SPELL_RIPPLING_WAVE_DAMAGE, true);
                        at->Remove();
                    }
                }
                cooldownDamage = 1000;
            }
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_rippling_wave_AI(areatrigger);
    }
};

// 17366
class bfa_at_regenerative_coral : public AreaTriggerEntityScript
{
public:
    bfa_at_regenerative_coral() : AreaTriggerEntityScript("bfa_at_regenerative_coral") { }

    struct bfa_at_regenerative_coral_AI : AreaTriggerAI
    {
        bfa_at_regenerative_coral_AI(AreaTrigger* at) : AreaTriggerAI(at) { }

        void OnRemove() override
        {
            std::list<Player*> playerList;
            at->GetPlayerListInGrid(playerList, 3.5f);
            if (!playerList.empty())
            {
                for (auto player : playerList)
                    player->CastSpell(player, SPELL_REGENERATIVE_CORAL_DAMAGE, true);
            }
            else if (playerList.empty())
            {
                Position pos = at->GetPosition();
                Unit* lady = at->GetCaster();
                lady->CastSpell(pos, SPELL_CORAL_GROWTH_SUMMON, true);
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_regenerative_coral_AI(areatrigger);
    }
};

// 17357
class bfa_at_empowered_rippling_wave : public AreaTriggerEntityScript
{
public:
    bfa_at_empowered_rippling_wave() : AreaTriggerEntityScript("bfa_at_empowered_rippling_wave") { }

    struct bfa_at_empowered_rippling_wave_AI : AreaTriggerAI
    {
        bfa_at_empowered_rippling_wave_AI(AreaTrigger* at) : AreaTriggerAI(at) { }

        uint32 cooldownDamage;
        float x;
        float y;
        ObjectGuid currentTarget;

        Creature* GetLady()
        {
            return at->FindNearestCreature(BOSS_LADY_ASHVANE, 100.0f, true);
        }

        void OnInitialize() override
        {
            CheckDistanceBoss();
            currentTarget = ObjectGuid::Empty;
        }

        void CheckDistanceBoss() // boss moves and initialize only take that point
        {
            if (Creature* lady = GetLady())
            {
                x = lady->GetPositionX();
                y = lady->GetPositionY();
            }
            std::vector<G3D::Vector3> points;
            points.push_back(G3D::Vector3(at->GetPositionX(), at->GetPositionY(), at->GetPositionZ()));
            points.push_back(G3D::Vector3(x, y, at->GetPositionZ()));
            at->InitSplines(points, 10000);
        }

        void OnUnitEnter(Unit* unit)
        {
            if (Creature* lady = GetLady())
            {
                if (Aura* carapace = lady->GetAura(SPELL_HARDENED_CARAPACE))
                {
                    int32 newAmount = lady->CountPctFromMaxHealth(10); // 10% to add
                    int32 base = carapace->GetEffect(EFFECT_0)->GetAmount(); // current amount
                    uint32 totalAmountToAdd = base + newAmount; // ++
                    carapace->GetEffect(EFFECT_0)->SetAmount(totalAmountToAdd);
                }
                at->Remove();
            }
        }

        void OnUnitExit(Unit* unit)
        {
            currentTarget = ObjectGuid::Empty; //clears when players exists
        }

        void OnUpdate(uint32 time) override
        {
            if (cooldownDamage > 0)
                cooldownDamage -= time;
            else
            {
                CheckDistanceBoss();
                std::list<Player*> playerList;
                at->GetPlayerListInGrid(playerList, 3.5f);
                if (!playerList.empty())
                {
                    for (auto player : playerList)
                    {
                        if (player->GetGUID() != currentTarget)
                        {
                            if (Aura* waterlog = player->AddAura(SPELL_WATERLOGGED, player))
                            {
                                if (player->GetMap()->IsMythic())
                                {
                                    waterlog->SetMaxDuration(1200000);
                                    waterlog->SetDuration(1200000);
                                    currentTarget = player->GetGUID();
                                }
                            }
                            player->CastSpell(player, SPELL_RIPPLING_WAVE_DAMAGE, true);
                            at->Remove();
                        }
                    }
                }
                cooldownDamage = 1000;
            }
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_empowered_rippling_wave_AI(areatrigger);
    }
};

// 297402
class bfa_spell_briny_bubble : public SpellScriptLoader
{
public:
    bfa_spell_briny_bubble() : SpellScriptLoader("bfa_spell_briny_bubble") { }

    class bfa_spell_briny_bubble_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_briny_bubble_SpellScript);

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            Unit* target = caster->GetVictim();
            if (!caster || !target)
                return;

            std::list<Player*> playerList;
            caster->GetPlayerListInGrid(playerList, 100.0f);
            playerList.remove_if(noTanks());

            if (playerList.size() >= 2)
                playerList.resize(2);

            if (!playerList.empty())
            {
                for (auto player : playerList)
                    player->AddAura(player->GetMap()->IsMythic() ? SPELL_BRINY_BUBBLE_PRE_AURA_MYTHIC : SPELL_BRINY_BUBBLE_PRE_AURA, player);
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_briny_bubble_SpellScript::HandleAfterCast);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_briny_bubble_SpellScript();
    }
};

// 302989
class bfa_spell_briny_bubble_aura : public SpellScriptLoader
{
public:
    bfa_spell_briny_bubble_aura() : SpellScriptLoader("bfa_spell_briny_bubble_aura") { }

    class bfa_spell_briny_bubble_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_briny_bubble_aura_AuraScript);

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;

            target->CastSpell(target, SPELL_BRINY_BUBBLE_AURA, true);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_briny_bubble_aura_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_briny_bubble_aura_AuraScript();
    }
};

// 297397
class bfa_spell_briny_bubble_aura_mythic : public SpellScriptLoader
{
public:
    bfa_spell_briny_bubble_aura_mythic() : SpellScriptLoader("bfa_spell_briny_bubble_aura_mythic") { }

    class bfa_spell_briny_bubble_aura_mythic_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_briny_bubble_aura_mythic_AuraScript);

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;

            std::list<Player*> playerList;
            target->GetPlayerListInGrid(playerList, 12.0f);
            if (playerList.size())
            {
                for (auto player : playerList)
                {
                    player->CastSpell(player, SPELL_BRINY_BUBBLE_AURA, true);
                    target->CastSpell(target, SPELL_BRINY_BUBBLE_AURA, true);
                }
            }
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_briny_bubble_aura_mythic_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_briny_bubble_aura_mythic_AuraScript();
    }
};

class bfa_npc_briny_bubble : public CreatureScript
{
public:
    bfa_npc_briny_bubble() : CreatureScript("bfa_npc_briny_bubble")
    {
    }

    struct bfa_npc_briny_bubble_AI : public ScriptedAI
    {
        bfa_npc_briny_bubble_AI(Creature* creature) : ScriptedAI(creature)
        {
            creature->AddAura(SPELL_BRINY_BUBBLE_NPC_VISUAL, creature);
            creature->AddUnitState(UNIT_STATE_ROOT);
        }

        void JustDied(Unit* unit) override
        {
            if (auto owner = me->GetOwner())
            {
                owner->RemoveAura(SPELL_BRINY_BUBBLE_AURA);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_briny_bubble_AI(creature);
    }
};

// 296941, 296942, 296943
class bfa_spell_arcing_azerite_controller_red_yellow_blue : public SpellScriptLoader
{
public:
    bfa_spell_arcing_azerite_controller_red_yellow_blue() : SpellScriptLoader("bfa_spell_arcing_azerite_controller_red_yellow_blue") { }

    class bfa_spell_arcing_azerite_controller_red_yellow_blue_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_arcing_azerite_controller_red_yellow_blue_AuraScript);

        bool IsOnBeam(WorldObject* obj, Position source, Position destination, float heightDiff, float beamWidth, float beamLenght)
        {
            if (beamLenght < obj->GetExactDist2d(source.GetPositionX(), source.GetPositionY()))
                return false;

            if (obj->GetPositionZ() - heightDiff > std::max(source.GetPositionZ(), destination.GetPositionZ()) &&
                obj->GetPositionZ() + heightDiff < std::min(source.GetPositionZ(), destination.GetPositionZ()))
                return false;

            float angleSourceDest = source.GetAngle(&destination);
            float angleSourcePoint = source.GetAngle(obj);

            float angle = fabs(angleSourceDest - angleSourcePoint);
            return fabs(sin(angle)) * source.GetExactDist2d(obj->GetPositionX(), obj->GetPositionY()) < beamWidth;
        }

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;

            std::list<Creature*> coralList;

            std::list<Player*> playerList;
            caster->GetPlayerListInGrid(playerList, 100.0f);
            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    if (target->HasAura(SPELL_ARCING_AZERITE_BLUE_CONTROLLER))
                    {
                        if (player->HasAura(SPELL_ARCING_AZERITE_BLUE_MARK))
                            target->CastSpell(player, SPELL_ARCING_AZERITE_DAMAGE, true);
                    }

                    if (target->HasAura(SPELL_ARCING_AZERITE_RED_CONTROLLER))
                    {
                        if (player->HasAura(SPELL_ARCING_AZERITE_RED_MARK))
                            target->CastSpell(player, SPELL_ARCING_AZERITE_DAMAGE, true);
                    }

                    if (target->HasAura(SPELL_ARCING_AZERITE_YELLOW_CONTROLLER))
                    {
                        if (player->HasAura(SPELL_ARCING_AZERITE_YELLOW_MARK))
                            target->CastSpell(player, SPELL_ARCING_AZERITE_DAMAGE, true);
                    }

                    Map::PlayerList const& playerList = target->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player_between = i->GetSource())
                        {

                            Position myPos = target->GetPosition();
                            Position triggerPos = player->GetPosition();
                            if (IsOnBeam(player, myPos, triggerPos, 3.0f, 2.0f, target->GetExactDist2d(player)))
                            {
                                target->GetCreatureListWithEntryInGrid(coralList, NPC_CORAL_GROWTH);
                                target->CastSpell(player_between, SPELL_ARCING_AZERITE_DAMAGE, true);
                            }
                        }

                    if (coralList.size())
                    {
                        for (auto coral : coralList)
                            coral->DespawnOrUnsummon();
                        coralList.clear();
                    }

                }
            }
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_arcing_azerite_controller_red_yellow_blue_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_arcing_azerite_controller_red_yellow_blue_AuraScript();
    }
};

void AddSC_boss_lady_ashvane()
{
    new bfa_boss_lady_ashvane();

    new bfa_npc_coral_growth();
    new bfa_npc_briny_bubble();

    new bfa_at_cutting_coral_ashvane();
    new bfa_at_cutting_coral_growth();
    new bfa_at_empowered_rippling_wave();
    new bfa_at_regenerative_coral();
    new bfa_at_rippling_wave();

    new bfa_spell_barnacle_bash();
    new bfa_spell_briny_bubble();
    new bfa_spell_briny_bubble_aura();
    new bfa_spell_briny_bubble_aura_mythic();
    new bfa_spell_hardened_carapace_aura();
    new bfa_spell_hardened_carapace_cast();
    new bfa_spell_regenerative_coral_dummy();
    new bfa_spell_rippling_wave_cast();
    new bfa_spell_arcing_azerite_controller_red_yellow_blue();
}
