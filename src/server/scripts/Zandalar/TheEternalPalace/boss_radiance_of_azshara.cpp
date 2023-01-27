#include "eternal_palace.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "AreaTriggerAI.h"
#include "MoveSplineInit.h"
#include <G3D/Vector3.h>
#include "AreaTrigger.h"
#include "Vehicle.h"

enum Spells
{
    SPELL_TIDE_FIST = 296566,
    SPELL_RADIANT_FURY = 299093,
    SPELL_ARCANADO_BURST_CAST = 304065,
    SPELL_ARCANADO_MISSILE = 304066,
    SPELL_ARCANADO_HIT = 304067,
    SPELL_ARCANADO_AT_DAMAGE = 304070,
    SPELL_ARCANADO_AT = 304068,
    SPELL_ARCANE_BOMB_VEH = 304026,
    SPELL_ARCANE_BOMB_VIS = 192711, //temp
    SPELL_ARCANE_BOMB_CAST = 304025,
    SPELL_ARCANE_BOMB_DAMAGE = 296746,
    SPELL_RIDE_VEHICLE = 46598,
    SPELL_UNSHACKLED_POWER = 296894,
    SPELL_SQUALL_TRAP_DAMAGE = 296509,
    SPELL_SQUALL_TRAP_ARMING = 296459,
    SPELL_SQUALL_TRAP_MISSILE = 296506,
    SPELL_SQUALL_TRAP_AT = 296460,
    SPELL_ANCIENT_TEMPEST_DUMMY = 300307,
    SPELL_ANCIENT_TEMPEST_AT = 296342,
    SPELL_ANCIENT_TEMPEST_DAMAGE = 295921,
    SPELL_ANCIENT_TEMPEST_PERIODIC = 295920,
    SPELL_ANCIENT_TEMPEST_VISUAL_AT = 296341,
    SPELL_ANCIENT_TEMPEST_BOSS = 295916,
    SPELL_GALE_BUFFET = 296701,
    SPELL_FOCUS_POWER = 304951,
    SPELL_SWIRLING_WINDS = 296389,
    SPELL_CHAIN_LIGHTNING = 296673,
};

enum Events
{
    EVENT_ENERGY_CHECK = 1,
    EVENT_PHASE_CHANGE,
    EVENT_ARCANE_BOMB,
    EVENT_UNSHACKLED_POWER,
    EVENT_TIDE_FIST,
    EVENT_ARCANADO_BURST,
    EVENT_SQAULL_TRAP,
    EVENT_SUMMON_STORMLINGS,
    EVENT_ANCIENT_TEMPEST,
    EVENT_GALE_BUFFET,
    EVENT_CHAIN_LIGHTNING,
};

enum Timers
{
    TIMER_ENERGY_CHECK = 1 * IN_MILLISECONDS,
    TIMER_PHASE_CHANGE = 105 * IN_MILLISECONDS,
    TIMER_GALE_BUFFET = 10 * IN_MILLISECONDS,
    TIMER_SUMMON_STORMLINGS = 20 * IN_MILLISECONDS,
    TIMER_CHAIN_LIGHTNING = 10 * IN_MILLISECONDS,
    TIMER_ARCANE_BOMB = 17 * IN_MILLISECONDS,
    TIMER_SQUALL_RAP = 2 * IN_MILLISECONDS,
    TIMER_TIDE_FIST = 18 * IN_MILLISECONDS,
    TIMER_ARCANADO_BURST = 25 * IN_MILLISECONDS,
    TIMER_UNSHACKLED_POWER = 20 * IN_MILLISECONDS,
};

const Position squallTrapPosition[3][17] =
{
    // FIRST
    {
    {845.45f, 623.99f, 1295.96f},
    {838.16f, 623.64f, 1295.96f},
    {831.01f, 623.29f, 1295.96f},
    {825.02f, 622.99f, 1295.96f},
    {818.60f, 622.68f, 1295.96f},
    {811.80f, 622.34f, 1295.96f},
     {804.77f, 622.02f, 1295.96f},
     },

     //SECOND
     {
     {771.90f, 600.62f, 1295.96f},
     {770.58f, 593.38f, 1295.96f},
     {769.34f, 586.53f, 1295.96f},
     {768.00f, 579.16f, 1295.96f},
     {766.57f, 571.25f, 1296.20f},
     },

     //THIRD
     {
     {739.56f, 656.40f, 1295.96f},
     {732.63f, 661.55f, 1295.96f},
     {726.31f, 666.24f, 1295.96f},
     {720.05f, 670.88f, 1295.96f},
     {713.98f, 675.49f, 1296.92f},
     },
};

struct checkSpec : public std::unary_function<Unit*, bool>
{
    checkSpec() {}

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

const Position centerPos = { 772.46f, 638.60f, 1290.00f }; //100y

//152364
class bfa_boss_radiance_of_azshara : public CreatureScript
{
public:
    bfa_boss_radiance_of_azshara() : CreatureScript("bfa_boss_radiance_of_azshara")  { }

    struct bfa_boss_radiance_of_azshara_AI : public BossAI
    {
        bfa_boss_radiance_of_azshara_AI(Creature* creature) : BossAI(creature, DATA_RADIANCE_OF_AZSHARA), summons(me) { }

        SummonList summons;
        uint8 countStormwraith;

        void Reset() override
        {
            BossAI::Reset();
            countStormwraith = 0;
            me->RemoveAllAreaTriggers();
            SetCombatMovement(false);
            me->SetPowerType(POWER_MANA);
            me->SetMaxPower(POWER_MANA, 100);
            me->SetPower(POWER_MANA, 0);
        }

        void MoveInLineOfSight(Unit* target) override
        {
            if (!target->IsPlayer())
                return;

            if (target->GetDistance(me) <= 30.0f)
                me->CastSpell(target, SPELL_RADIANT_FURY, true);
        }

        void EnterCombat(Unit*)// override
        {
            Talk(3);      
          //  _EnterCombat();
            ChangePhase(1);
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case NPC_STORMWRAITH:
                summon->SetInCombatWithZone();
                break;
            }
        }        

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            switch (summon->GetEntry())
            {
            case NPC_STORMWRAITH:
            {
                ++countStormwraith;
                if (IsMythic())
                {
                    if (countStormwraith > 1)
                        ChangePhase(1);
                }
                else if (countStormwraith >= 1)
                    ChangePhase(1);
                break;
            }
            }
        }

        void KilledUnit(Unit* target) override
        {
            if (target->IsPlayer() && roll_chance_f(15))
                Talk(5);
        }

        void EnterEvadeMode(EvadeReason w) override
        {
            _JustReachedHome();
            summons.DespawnAll();
            me->RemoveAllAreaTriggers();
            _DespawnAtEvade(15);
        }

        void JustDied(Unit*) override
        {
            Talk(7);
            _JustDied();
            summons.DespawnAll();
            me->RemoveAllAreaTriggers();
        }

        void ChangePhase(uint8 phase)
        {
            switch (phase)
            {
            case 1:
            {
                events.Reset();
                events.ScheduleEvent(EVENT_PHASE_CHANGE, TIMER_PHASE_CHANGE);
                if (me->HasAura(SPELL_ANCIENT_TEMPEST_BOSS))
                    me->RemoveAura(SPELL_ANCIENT_TEMPEST_BOSS);
                events.ScheduleEvent(EVENT_ENERGY_CHECK, TIMER_ENERGY_CHECK);
                events.ScheduleEvent(EVENT_TIDE_FIST, TIMER_TIDE_FIST);
                events.ScheduleEvent(EVENT_ARCANADO_BURST, TIMER_ARCANADO_BURST);
                events.ScheduleEvent(EVENT_UNSHACKLED_POWER, TIMER_UNSHACKLED_POWER);
                events.ScheduleEvent(EVENT_ARCANE_BOMB, TIMER_ARCANE_BOMB);
                me->RemoveAllAreaTriggers();
                break;
            }
            case 2:
            {
                Talk(3);
                std::ostringstream str;
                str << "Radiance of Azshara begins to summon an |cFFF00000|h[Ancient Tempest]|h|r!";
                me->TextEmote(str.str().c_str(), 0, true);
                events.Reset();
                AddTempestOnPlayers();
                events.ScheduleEvent(EVENT_ARCANE_BOMB, TIMER_ARCANE_BOMB);
                me->CastSpell(me, SPELL_ANCIENT_TEMPEST_BOSS);
                events.ScheduleEvent(EVENT_SQAULL_TRAP, TIMER_SQUALL_RAP);
                break;
            }
            }
        }

        void SpawnStormwraith()
        {
            float x, y, z;
            switch (rand() % 2)
            {
            case 1:
                x = 734.86f;
                y = 588.79f;
                z = 1295.96f;
                break;
            case 2:
                x = 739.83f;
                y = 685.29f;
                z = 1295.96f;
                break;
            }

            me->SummonCreature(NPC_STORMWRAITH, x, y, z, TEMPSUMMON_MANUAL_DESPAWN);

            if (IsMythic())
            {
                switch (rand() % 2)
                {
                case 1:
                    x = 806.63f;
                    y = 685.96f;
                    z = 1295.96f;
                    break;
                case 2:
                    x = 815.21f;
                    y = 593.88f;
                    z = 1295.96f;
                    break;
                }

                me->SummonCreature(NPC_STORMWRAITH, x, y, z, TEMPSUMMON_MANUAL_DESPAWN);
            }
        }

        void AddTempestOnPlayers()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    if (!player->IsGameMaster())
                        player->AddAura(SPELL_ANCIENT_TEMPEST_PERIODIC, player);
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
                case EVENT_ARCANE_BOMB:
                {
                    me->CastSpell(me, SPELL_ARCANE_BOMB_CAST);
                    events.ScheduleEvent(EVENT_ARCANE_BOMB, TIMER_ARCANE_BOMB);
                    break;
                }
                case EVENT_PHASE_CHANGE:
                    ChangePhase(2);
                    break;
                case EVENT_ENERGY_CHECK:
                    me->ModifyPower(POWER_MANA, +5);
                    events.ScheduleEvent(EVENT_ENERGY_CHECK, 5000);
                    break;
                case EVENT_TIDE_FIST:
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_TIDE_FIST);
                    events.ScheduleEvent(EVENT_TIDE_FIST, TIMER_TIDE_FIST);
                    break;
                case EVENT_ARCANADO_BURST:
                {
                    me->CastSpell(me, SPELL_ARCANADO_BURST_CAST);
                    events.ScheduleEvent(EVENT_ARCANADO_BURST, TIMER_ARCANADO_BURST);
                    break;
                }
                case EVENT_UNSHACKLED_POWER:
                {
                    Talk(1);
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_UNSHACKLED_POWER);
                    events.ScheduleEvent(EVENT_UNSHACKLED_POWER, TIMER_UNSHACKLED_POWER);
                    break;
                }
                case EVENT_SQAULL_TRAP:
                {
                    for (uint8 i = 0; i < 7; ++i)
                        me->CastSpell(squallTrapPosition[1][i], SPELL_SQUALL_TRAP_AT);
                    for (uint8 i = 0; i < 5; ++i)
                        me->CastSpell(squallTrapPosition[2][i], SPELL_SQUALL_TRAP_AT);
                    for (uint8 i = 0; i < 5; ++i)
                        me->CastSpell(squallTrapPosition[3][i], SPELL_SQUALL_TRAP_AT);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_radiance_of_azshara_AI(creature);
    }
};

// 304065
class bfa_spell_arcanado_burst_cast : public SpellScriptLoader
{
public:
    bfa_spell_arcanado_burst_cast() : SpellScriptLoader("bfa_spell_arcanado_burst_cast") { }

    class bfa_spell_arcanado_burst_cast_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_arcanado_burst_cast_SpellScript);

        void AfterCast(SpellEffIndex index)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            float x, y, z;
            std::list<Player*> playerList;
            caster->GetPlayerListInGrid(playerList, 100.0f);
            if (!playerList.empty())
            {
                if (playerList.size() >= 3)
                    playerList.resize(3);

                for (auto player : playerList)
                {
                    x = player->GetPositionX();
                    y = player->GetPositionY();
                    z = player->GetPositionZ();

                 //   caster->CastSpell(x, y, z, SPELL_ARCANADO_MISSILE, true);
                }
            }
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(bfa_spell_arcanado_burst_cast_SpellScript::AfterCast, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_arcanado_burst_cast_SpellScript();
    }
};

// 304025
class bfa_spell_arcane_bomb_radiance_dummy : public SpellScriptLoader
{
public:
    bfa_spell_arcane_bomb_radiance_dummy() : SpellScriptLoader("bfa_spell_arcane_bomb_radiance_dummy") { }

    class bfa_spell_arcane_bomb_radiance_dummy_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_arcane_bomb_radiance_dummy_SpellScript);

        void AfterCast(SpellEffIndex index)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> targets;
            caster->GetPlayerListInGrid(targets, 100.0f);
            targets.remove_if(checkSpec()); //no tanks

            if (!targets.empty())
                if (targets.size() >= 3)
                    targets.resize(3);

            for (std::list<Player*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
            {
                std::ostringstream str;
                str << (*itr)->GetName(); " is targeted by |cFFF00000|h[Arcane Bomb]|h|r!";
                caster->TextEmote(str.str().c_str(), 0, true);
                caster->CastSpell((*itr), SPELL_ARCANE_BOMB_VEH, true);
            }

        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(bfa_spell_arcane_bomb_radiance_dummy_SpellScript::AfterCast, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_arcane_bomb_radiance_dummy_SpellScript();
    }
};

// 304067
class bfa_spell_arcanado_burst_dummy : public SpellScriptLoader
{
public:
    bfa_spell_arcanado_burst_dummy() : SpellScriptLoader("bfa_spell_arcanado_burst_dummy") { }

    class bfa_spell_arcanado_burst_dummy_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_arcanado_burst_dummy_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.size() == 0 || targets.size())
                SummonAt();
        }

        void SummonAt()
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

          /*  if (const WorldLocation* pos = GetExplTargetDest())
            {
                caster->CastSpell(pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), SPELL_ARCANADO_AT, true);
            }*/
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_arcanado_burst_dummy_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_arcanado_burst_dummy_SpellScript();
    }
};

// 17469 
class bfa_at_arcanado : public AreaTriggerEntityScript
{
public:
    bfa_at_arcanado() : AreaTriggerEntityScript("bfa_at_arcanado") { }

    struct bfa_at_arcanado_AI : AreaTriggerAI
    {
        bfa_at_arcanado_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        uint32 destroyTimer;
        uint32 damageTimer;

        void FillCirclePath(Position const& center, float radius, float z, Movement::PointsArray& path, bool clockwise)
        {
            float step = clockwise ? -M_PI / 8.0f : M_PI / 8.0f;
            float angle = center.GetAngle(at->GetPositionX(), at->GetPositionY());

            for (uint8 iter = 0; iter < 16; angle += step, ++iter)
            {
                G3D::Vector3 point;
                point.x = center.GetPositionX() + radius * cosf(angle);
                point.y = center.GetPositionY() + radius * sinf(angle);
                point.z = z;
                path.push_back(point);
            }
        }

        void OnInitialize() override
        {
            destroyTimer = 0;
            damageTimer = 0;

            Position center = at->GetPosition();

            std::vector<G3D::Vector3> points;
            FillCirclePath(center, 1.0f, at->GetPositionZ(), points, true);
            at->InitSplines(points, 40000);
        }

        void OnUpdate(uint32 diff) override
        {
            destroyTimer += diff;
            if (destroyTimer >= 20 * IN_MILLISECONDS)
            {
                at->Remove();
                destroyTimer = 0;
            }

            damageTimer += diff;
            if (damageTimer >= 2 * IN_MILLISECONDS)
            {
                Map::PlayerList const& playerList = at->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* player = i->GetSource())
                    {
                        if (!player->IsGameMaster() && player->GetDistance(at) <= 5.5f) //gm check
                        {
                            player->CastSpell(player, SPELL_ARCANADO_AT_DAMAGE, true);
                        }
                    }

                damageTimer = 0;
            }
        };
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_arcanado_AI(areatrigger);
    }
};

//16695 
class bfa_at_squall_trap : public AreaTriggerEntityScript
{
public:
    bfa_at_squall_trap() : AreaTriggerEntityScript("bfa_at_squall_trap") { }

    struct bfa_at_squall_trap_AI : AreaTriggerAI
    {
        bfa_at_squall_trap_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        uint32 damageTimer;

        void OnInitialize() override
        {
            damageTimer = 0;
        }

        void OnUpdate(uint32 diff) override
        {
            damageTimer += diff;
            if (damageTimer >= 2 * IN_MILLISECONDS)
            {
                Map::PlayerList const& playerList = at->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* player = i->GetSource())
                    {
                        if (!player->IsGameMaster() && player->GetDistance(at) <= 3.0f) //gm check
                        {
                            player->CastSpell(player, SPELL_SQUALL_TRAP_DAMAGE, true);
                            player->CastSpell(player->GetPosition(), SPELL_ARCANADO_AT, true);
                            at->Remove();
                        }
                    }

                damageTimer = 0;
            }
        };
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_squall_trap_AI(areatrigger);
    }
};

// 304026
class bfa_spell_arcane_bomb_radiance : public SpellScriptLoader
{
public:
    bfa_spell_arcane_bomb_radiance() : SpellScriptLoader("bfa_spell_arcane_bomb_radiance")
    {}

    class bfa_spell_arcane_bomb_radiance_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(bfa_spell_arcane_bomb_radiance_SpellScript);

        void HandleSummon()
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            Position summon_pos = GetHitUnit()->GetPosition();

            GetCaster()->SummonCreature(NPC_ARCANE_BOMB_TRIGGER, summon_pos, TEMPSUMMON_TIMED_DESPAWN, 20 * IN_MILLISECONDS);
        }

        void Register()
        {
            AfterHit += SpellHitFn(bfa_spell_arcane_bomb_radiance_SpellScript::HandleSummon);
        }
    };

    class bfa_spell_arcane_bomb_radiance_Aurascript : public AuraScript
    {
    public:
        PrepareAuraScript(bfa_spell_arcane_bomb_radiance_Aurascript);

        void HandleDispel(DispelInfo* dispelInfo)
        {
            if (!GetCaster() || !GetUnitOwner())
                return;

            Unit* owner = GetUnitOwner();

            owner->RemoveAurasDueToSpell(SPELL_RIDE_VEHICLE);

            if (Vehicle* vehicle = owner->GetVehicle())
                vehicle->RemoveAllPassengers();

            if (Creature* bomb = owner->FindNearestCreature(NPC_ARCANE_BOMB_TRIGGER, 50.0f, true))
                bomb->AddUnitState(UNIT_STATE_ROOT);
        }

        void Register()
        {
            OnDispel += AuraDispelFn(bfa_spell_arcane_bomb_radiance_Aurascript::HandleDispel);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_arcane_bomb_radiance_Aurascript();
    }

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_arcane_bomb_radiance_SpellScript();
    }
};

class bfa_npc_arcane_bomb_radiance : public CreatureScript
{
public:
    bfa_npc_arcane_bomb_radiance() : CreatureScript("bfa_npc_arcane_bomb_radiance")  { }

    struct bfa_npc_arcane_bomb_radiance_AI : public ScriptedAI
    {
        bfa_npc_arcane_bomb_radiance_AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _timerCast = 0;
            _casted = false;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (!summoner)
                return;

            _summoner = summoner;

            for (auto& it : me->GetMap()->GetPlayers())
            {
                if (Player* player = it.GetSource())
                {
                    if (player->HasAura(SPELL_ARCANE_BOMB_VEH))
                    {
                        me->NearTeleportTo(player->GetPosition());
                        DoCast(player, SPELL_RIDE_VEHICLE, true);
                        DoCast(player, SPELL_ARCANE_BOMB_VIS, true);
                        events.ScheduleEvent(EVENT_ARCANE_BOMB, 100);
                        break;
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                if (eventId == EVENT_ARCANE_BOMB)
                {
                    DoCast(me, SPELL_ARCANE_BOMB_DAMAGE, false);
                }
            }
        }

    private:
        EventMap events;
        Unit* _summoner;
        bool _casted;
        uint32 _timerCast;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_arcane_bomb_radiance_AI(creature);
    }
};

class bfa_npc_stormwraith : public CreatureScript
{
public:
    bfa_npc_stormwraith() : CreatureScript("bfa_npc_stormwraith") { }

    struct bfa_npc_stormwraith_AI : public ScriptedAI
    {
        bfa_npc_stormwraith_AI(Creature* creature) : ScriptedAI(creature) { }
        
        void Reset() override
        {
            events.Reset();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->CastSpell(me, SPELL_ANCIENT_TEMPEST_VISUAL_AT, true);
        }

        void JustDied(Unit*) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void EnterCombat(Unit*) //override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            me->CastSpell(me, SPELL_FOCUS_POWER);

            events.ScheduleEvent(EVENT_SUMMON_STORMLINGS, TIMER_SUMMON_STORMLINGS);
            events.ScheduleEvent(EVENT_GALE_BUFFET, TIMER_GALE_BUFFET);
        }

        bool checkTempest()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (player->GetDistance(me->GetHomePosition()) >= 30.0f)
                        {
                            if (Aura* deubff1 = player->AddAura(SPELL_ANCIENT_TEMPEST_PERIODIC, player))
                            {
                                deubff1->SetMaxDuration(2000);
                                deubff1->SetDuration(2000);
                                return false;
                            }
                        }

                        if (me->GetDistance(me->GetHomePosition()) >= 30.0f)
                        {
                            if (Aura* debuff = me->AddAura(SPELL_SWIRLING_WINDS, me))
                            {
                                debuff->SetMaxDuration(2000);
                                debuff->SetDuration(2000);
                                return false;
                            }
                        }
                    }

                }

            return true;
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->IsInCombat())
            {
                checkTempest();
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SUMMON_STORMLINGS:
                {
                    for (uint8 i = 0; i < 3; ++i)
                        if (Creature* storms = me->SummonCreature(NPC_STORMLING, me->GetPositionX() + urand(5.0f, 10.0f), me->GetPositionY() + urand(5.0f, 10.0f), me->GetPositionZ(), TEMPSUMMON_MANUAL_DESPAWN))
                            storms->SetInCombatWithZone();
                    events.ScheduleEvent(EVENT_SUMMON_STORMLINGS, TIMER_SUMMON_STORMLINGS);
                    break;
                }
                case EVENT_GALE_BUFFET:
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_GALE_BUFFET);
                    events.ScheduleEvent(EVENT_GALE_BUFFET, TIMER_GALE_BUFFET);
                    break;
                }
            }
        }
    private:
        EventMap events;
        InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_stormwraith_AI(creature);
    }
};

// 295920
class bfa_spell_ancient_tempest_players : public SpellScriptLoader
{
public:
    bfa_spell_ancient_tempest_players() : SpellScriptLoader("bfa_spell_ancient_tempest_players") { }

    class bfa_spell_ancient_tempest_players_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_ancient_tempest_players_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;

            target->CastSpell(target, SPELL_ANCIENT_TEMPEST_DAMAGE, true);
        }

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;

            target->ApplyMovementForce(caster->GetGUID(), caster->GetPosition(), -5.0f, 0);
        }

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;

            target->RemoveMovementForce(caster->GetGUID());
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_ancient_tempest_players_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_ancient_tempest_players_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectApply += AuraEffectApplyFn(bfa_spell_ancient_tempest_players_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_ancient_tempest_players_AuraScript();
    }
};

class bfa_npc_stormlings : public CreatureScript
{
public:
    bfa_npc_stormlings() : CreatureScript("bfa_npc_stormlings") { }

    struct bfa_npc_stormlings_AI : public ScriptedAI
    {
        bfa_npc_stormlings_AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit*)// override
        {
            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, TIMER_CHAIN_LIGHTNING);
        }

        bool checkTempest()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (me->GetDistance(me->GetHomePosition()) >= 30.0f)
                        {
                            if (Aura* debuff = me->AddAura(SPELL_SWIRLING_WINDS, me))
                            {
                                debuff->SetMaxDuration(2000);
                                debuff->SetDuration(2000);
                                return false;
                            }
                        }
                    }

                }

            return true;
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->IsInCombat())
            {
                checkTempest();
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHAIN_LIGHTNING:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        me->CastSpell(target, SPELL_CHAIN_LIGHTNING);
                    events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, TIMER_CHAIN_LIGHTNING);
                    break;
                }
                }
            }
        }
    private:
        EventMap events;
        InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_stormlings_AI(creature);
    }
};

void AddSC_boss_radiance_of_azshara()
{
    new bfa_boss_radiance_of_azshara();
    new bfa_at_arcanado();
    new bfa_at_squall_trap();
    new bfa_npc_arcane_bomb_radiance();
    new bfa_npc_stormlings();
    new bfa_npc_stormwraith();
    new bfa_spell_ancient_tempest_players();
    new bfa_spell_arcanado_burst_cast();
    new bfa_spell_arcanado_burst_dummy();
    new bfa_spell_arcane_bomb_radiance();
    new bfa_spell_arcane_bomb_radiance_dummy();
}
