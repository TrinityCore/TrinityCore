#include "eternal_palace.h"
#include "AreaTriggerAI.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "GridNotifiersImpl.h"

enum Spells
{
    SPELL_OXYGEN_RICH_MEMBRANE = 291977,
    SPELL_BIOLUMINESCENCE = 292133,
    SPELL_BIOLUMINESCENT_CLOUND = 292205, // 302135,
    SPELL_RADIANT_BIOMASS_AURA = 295412,
    SPELL_RADIANT_BIOMASS_PROC = 292138,
    SPELL_DARKEST_DEPTHS = 292127,
    SPELL_BIOELECTRIC_DISCHARGE = 305094,
    SPELL_FEEDING_FRENZY_AURA = 298424,
    SPELL_FEEDING_FRENZY_PROC = 298428,
    SPELL_TOXIC_SPINE_CAST = 292159,
    SPELL_TOXIC_SPINE_MISSILE = 292162,
    SPELL_SHOCK_PULSE_CAST = 292270,
    SPELL_SHOCK_PULSE_DAMAGE = 292279,
    SPELL_BIOELECTRIC_FEELERS_AURA = 297932,
    SPELL_BIOELECTRIC_FEELERS_DUMMY = 292232,
    SPELL_BIOELECTRIC_FEELERS_DAMAGE = 305330,
    SPELL_BIOELECTRIC_FEELERS_AT = 305405,
    SPELL_GAZE_FROM_BELOW = 292307,
    SPELL_CAVITATION_CAST = 292083,
    SPELL_CAVITATION_DAMAGE = 292084,
    SPELL_SLIPSTREAM_AT = 302036,
    SPELL_SLIPSTREAM = 301180,
    SPELL_GLOWING_STINGER_AT = 298594,
    SPELL_GLOWING_STINGER_AURA = 298595,
    SPELL_PIERCING_BARB_CAST = 301494,
    SPELL_PIERCING_BARB_AT = 305187,
    SPELL_PIERCING_BARB_DAMAGE = 301930,
};

enum Events
{
    EVENT_ADD_ENERGY = 1,
    EVENT_CHANGE_PHASE,
    EVENT_TOXIC_SPINE,
    EVENT_REMOVE_INTERMISSION,
    EVENT_SHOCK_PULSE,
    EVENT_REMOVE_MOVEMENT_FORCE,
    EVENT_PIERCING_BARB,
    EVENT_BIOELECTRIC_FEELERS,
};

enum Timers
{
    TIMER_ADD_ENERGY = 1 * IN_MILLISECONDS,
    TIMER_CHANGE_PHASE = 90 * IN_MILLISECONDS, //1.30m
    TIMER_TOXIC_SPINE = 8 * IN_MILLISECONDS,
    TIMER_TOXIC_SPINE_AFTER = 28 * IN_MILLISECONDS,
    TIMER_PIERCING_BARB = 12 * IN_MILLISECONDS,
    TIMER_PIERCING_BARB_AFTER = 24 * IN_MILLISECONDS,
    TIMER_BIOELECTRIC_FEELERS = 4 * IN_MILLISECONDS,
    TIMER_SHOCK_PULSE = 20 * IN_MILLISECONDS,
};

const Position platform1 = { -4.35f, 974.46f, 1255.90f, 3.21f }; // 3.21f
const Position platform2 = { -263.46f, 1099.83f, 1211.03f, 4.68f }; // 4.68
const Position platform3 = { -448.11f, 788.86f, 1171.09f, 0.85f }; // 0.85

const Position firstPlatformCheck = { -54.86f, 959.30f, 1249.38f }; //50y

// boss 40y
const Position secondPlatformCheck1 = { -300.46f, 1030.39f, 1207.40f }; // x 28, y, 20
const Position secondPlatformCheck2 = { -254.09f, 1020.45f, 1206.55f }; // x 27 y 20

// boss 35y
const Position thirdPlatformCheck1 = { -443.87f, 847.56f, 1167.82f }; //x 15 y 20
const Position thirdPlatformCheck2 = { -395.65f, 808.48f, 1166.90f }; //20y both

const Position jellyFishFirstSpawn = { -161.72f, 991.28f, 1242.16f };
const Position jellyFishSecondSpawn = { -354.09f, 911.11f, 1204.11f };

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

// TEMPFIX: slipstream on phase change, intended atm

class bfa_boss_blackwater_behemoth : public CreatureScript
{
public:
    bfa_boss_blackwater_behemoth() : CreatureScript("bfa_boss_blackwater_behemoth")
    {
    }

    struct bfa_boss_blackwater_behemoth_AI : public BossAI
    {
        bfa_boss_blackwater_behemoth_AI(Creature* creature) : BossAI(creature, DATA_BLACKWATER_BEHEMOTH), summons(me)
        {
            instance = creature->GetInstanceScript();
            creature->SetPowerType(POWER_ENERGY);
            creature->SetMaxPower(POWER_ENERGY, 100);
            creature->SetPower(POWER_ENERGY, 0);
            creature->AddUnitState(UNIT_STATE_ROOT);
        }

        InstanceScript* instance;
        EventMap events;
        bool isIntermission;
        SummonList summons;
        bool canApplyForce;
        uint8 phase;
        bool oxygenSpawned;

        void SpawnOxygenNpc()
        {
            if (Creature* oxy = me->SummonCreature(NPC_OXYGEN_RICH_MEMBRANE, -63.28f, 926.95f, 1251.44f, TEMPSUMMON_MANUAL_DESPAWN))
                oxy->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!oxygenSpawned)
            {
                Map::PlayerList const& lPlayers = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                    if (Player* pPlayer = itr->GetSource())
                        if (pPlayer->IsAlive() && pPlayer->IsWithinDist(me, 200.f) && !pPlayer->IsGameMaster())
                        {
                            SpawnOxygenNpc();
                            oxygenSpawned = true;
                            return;
                        }
            }
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case NPC_PUFFERFISH:
                summon->SetReactState(REACT_PASSIVE);
                summon->SetFaction(14);
                break;
            case NPC_DARKWATER_JELLYFISH:
                summon->SetReactState(REACT_PASSIVE);
                summon->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                break;
            }
        }

        void ValidatePufferFish()
        {
            if (phase == 0)
            {
                me->SummonCreature(NPC_PUFFERFISH, -28.66f, 941.94f, 1258.47f, TEMPSUMMON_MANUAL_DESPAWN);
                me->SummonCreature(NPC_PUFFERFISH, -29.43f, 1007.05f, 1252.15f, TEMPSUMMON_MANUAL_DESPAWN);
            }

            if (phase == 1)
            {
                me->SummonCreature(NPC_PUFFERFISH, -240.81f, 1002.57f, 1210.03f, TEMPSUMMON_MANUAL_DESPAWN);
                me->SummonCreature(NPC_PUFFERFISH, -300.05f, 1006.00f, 1211.28f, TEMPSUMMON_MANUAL_DESPAWN);
            }

            if (phase == 2)
            {
                me->SummonCreature(NPC_PUFFERFISH, -397.64f, 769.03f, 1168.23f, TEMPSUMMON_MANUAL_DESPAWN);
                me->SummonCreature(NPC_PUFFERFISH, -466.33f, 837.49f, 1171.01f, TEMPSUMMON_MANUAL_DESPAWN);
            }
        }

        void ValidateDarkestDepths(bool active)
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 500.0f);
            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    if (active)
                    {
                        me->AddAura(SPELL_DARKEST_DEPTHS, player);
                    }
                    else if (!active)
                        player->RemoveAura(SPELL_DARKEST_DEPTHS);
                }
            }
        }

        void Reset()
        {
            ValidateDarkestDepths(false);
            summons.DespawnAll();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            events.Reset();
            if (!me->HasUnitState(UNIT_STATE_ROOT))
                me->AddUnitState(UNIT_STATE_ROOT);

            oxygenSpawned = false;
            isIntermission = false;
            canApplyForce = false;

            me->NearTeleportTo(platform1.GetPositionX(), platform1.GetPositionY(), platform1.GetPositionZ(), platform1.GetOrientation(), false);
        }

        void JustDied(Unit*)
        {
            summons.DespawnAll();
            ValidateDarkestDepths(false);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        //TEMP
        void HandleSpliStream()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    if (!player->IsGameMaster())
                        player->AddAura(SPELL_SLIPSTREAM, player);
        }

        void CheckBioluminescence()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    if (!player->IsGameMaster())
                    {
                        if (!player->HasAura(SPELL_BIOLUMINESCENCE))
                            player->AddAura(SPELL_DARKEST_DEPTHS, player);
                        else if (player->HasAura(SPELL_BIOLUMINESCENCE))
                            player->RemoveAura(SPELL_DARKEST_DEPTHS);
                    }
        }

        void EnterEvadeMode(EvadeReason w)
        {
            _DespawnAtEvade(15);
        }

        void EnterCombat(Unit*)
        {
            me->AddAura(SPELL_FEEDING_FRENZY_AURA, me);

            ValidateDarkestDepths(true);

            if (phase >= 1)
                me->NearTeleportTo(platform1.GetPositionX(), platform1.GetPositionY(), platform1.GetPositionZ(), platform1.GetOrientation(), false);

            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            if (!me->HasUnitState(UNIT_STATE_ROOT))
                me->AddUnitState(UNIT_STATE_ROOT);

            me->SetPower(POWER_ENERGY, 0);
            phase = 0;
            ValidatePufferFish();

            events.ScheduleEvent(EVENT_CHANGE_PHASE, TIMER_CHANGE_PHASE);
            events.ScheduleEvent(EVENT_TOXIC_SPINE, TIMER_TOXIC_SPINE);
            events.ScheduleEvent(EVENT_SHOCK_PULSE, TIMER_SHOCK_PULSE);
            events.ScheduleEvent(EVENT_BIOELECTRIC_FEELERS, TIMER_BIOELECTRIC_FEELERS);

            if (me->GetMap()->IsMythic())
                events.ScheduleEvent(EVENT_PIERCING_BARB, TIMER_PIERCING_BARB);
        }

        bool PlatformCheck()
        {
            if (!isIntermission)
            {
                Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* player = i->GetSource())
                    {
                        if (!player->IsGameMaster()) //gm check
                        {
                            if (phase == 0)
                            {
                                if (player->GetDistance(firstPlatformCheck.GetPositionX(), firstPlatformCheck.GetPositionY(), firstPlatformCheck.GetPositionZ()) > 50.0f)
                                {
                                    if (player->HasAura(SPELL_BIOLUMINESCENCE))
                                    {
                                        if (!player->HasAura(SPELL_GAZE_FROM_BELOW))
                                            player->CastSpell(player, SPELL_GAZE_FROM_BELOW, true);
                                    }
                                    return false;
                                }

                            }

                            if (phase == 1) // 1.x 28, y, 20, boss 40y | 2. // x 27 y 20
                            {
                                if (player->GetDistance(secondPlatformCheck1.GetPositionX()) > 28.0f || secondPlatformCheck1.GetPositionY() > 20.0f || (platform2.GetPositionX() && platform2.GetPositionY() > 40.0f)
                                    || secondPlatformCheck2.GetPositionX() > 27.0f || secondPlatformCheck2.GetPositionY() > 20.0f)
                                {
                                    if (player->HasAura(SPELL_BIOLUMINESCENCE))
                                    {
                                        if (!player->HasAura(SPELL_GAZE_FROM_BELOW))
                                            player->CastSpell(player, SPELL_GAZE_FROM_BELOW, true);
                                    }
                                    return false;
                                }
                            }

                            if (phase == 2) // boss 35y
                            {
                                if (player->GetDistance(thirdPlatformCheck1.GetPositionX()) > 15.0f || thirdPlatformCheck1.GetPositionY() > 20.0f || (thirdPlatformCheck2.GetPositionX() && thirdPlatformCheck2.GetPositionY() > 20.0f)
                                    || (platform3.GetPositionX() && platform3.GetPositionY() > 35.0f))
                                {
                                    if (player->HasAura(SPELL_BIOLUMINESCENCE))
                                    {
                                        if (!player->HasAura(SPELL_GAZE_FROM_BELOW))
                                            player->CastSpell(player, SPELL_GAZE_FROM_BELOW, true);
                                    }
                                    return false;
                                }
                            }
                        }
                    }
            }
            return true;
        }


        void HandleJellyFish()
        {
            if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
            {
                if (phase == 1)
                {
                    for (uint32 i = 0; i < 40; ++i)
                    {
                        Position random = me->GetRandomPoint(jellyFishFirstSpawn, 45.0f);
                        me->SummonCreature(NPC_DARKWATER_JELLYFISH, random, TEMPSUMMON_MANUAL_DESPAWN);
                    }
                }

                if (phase == 2)
                {
                    for (uint32 i = 0; i < 50; ++i)
                    {
                        Position random = me->GetRandomPoint(jellyFishSecondSpawn, 65.0f);
                        me->SummonCreature(NPC_DARKWATER_JELLYFISH, random, TEMPSUMMON_MANUAL_DESPAWN);
                    }
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->IsInCombat())
            {
                PlatformCheck();
                CheckBioluminescence();
            }

            if (canApplyForce)
            {
                Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* player = i->GetSource())
                    {
                        if (!player->IsGameMaster())
                        {
                            player->ApplyMovementForce(me->GetGUID(), me->GetPosition(), -5.0f, 0);
                        }
                    }
            }
            else
            {
                Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* player = i->GetSource())
                    {
                        if (!player->IsGameMaster())
                        {
                            player->RemoveMovementForce(me->GetGUID());
                        }
                    }
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHANGE_PHASE:
                {
                    ++phase;
                    HandleSpliStream();
                    ValidatePufferFish();

                    if (phase == 1)
                    {
                        me->NearTeleportTo(platform2.GetPositionX(), platform2.GetPositionY(), platform2.GetPositionZ(), platform2.GetOrientation(), false);
                        me->GetScheduler().Schedule(2s, [this](TaskContext /*context*/)
                            {
                                me->CastSpell(me, SPELL_CAVITATION_CAST);
                            });
                    }

                    if (phase == 2)
                    {
                        me->NearTeleportTo(platform3.GetPositionX(), platform3.GetPositionY(), platform3.GetPositionZ(), platform3.GetOrientation(), false);
                        me->GetScheduler().Schedule(2s, [this](TaskContext /*context*/)
                            {
                                me->CastSpell(me, SPELL_CAVITATION_CAST);
                            });
                    }

                    HandleJellyFish();
                    isIntermission = true;
                    events.ScheduleEvent(EVENT_REMOVE_INTERMISSION, 35 * IN_MILLISECONDS);
                    me->SetPower(POWER_ENERGY, 0);
                    events.ScheduleEvent(EVENT_CHANGE_PHASE, TIMER_CHANGE_PHASE);
                    break;
                }
                case EVENT_ADD_ENERGY: // cosmetic
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 1);
                    events.ScheduleEvent(EVENT_ADD_ENERGY, TIMER_ADD_ENERGY);
                    break;
                case EVENT_REMOVE_INTERMISSION:
                    isIntermission = false;
                    break;
                case EVENT_TOXIC_SPINE:
                {
                    me->CastSpell(me, SPELL_TOXIC_SPINE_CAST);
                    events.ScheduleEvent(EVENT_TOXIC_SPINE, TIMER_TOXIC_SPINE_AFTER);
                    break;
                }
                case EVENT_SHOCK_PULSE:
                {
                    std::ostringstream str;
                    str << "The Blackwater Behemoth begins casting |cFFF00000|h[Shock Pulse]|h|r!";
                    me->TextEmote(str.str().c_str(), 0, true);

                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_SHOCK_PULSE_CAST);
                    canApplyForce = true;
                    events.ScheduleEvent(EVENT_REMOVE_MOVEMENT_FORCE, 5500);
                    events.ScheduleEvent(EVENT_SHOCK_PULSE, TIMER_SHOCK_PULSE);
                    break;
                }
                case EVENT_REMOVE_MOVEMENT_FORCE:
                    canApplyForce = false;
                    break;
                case EVENT_BIOELECTRIC_FEELERS:
                    me->CastSpell(me, SPELL_BIOELECTRIC_FEELERS_AURA);
                    break;
                case EVENT_PIERCING_BARB:
                {
                    std::list<Player*> playerList;
                    me->GetPlayerListInGrid(playerList, 100.0f);
                    playerList.remove_if(noTanks());
                    if (!playerList.empty())
                    {
                        if (playerList.size() >= 1)
                            playerList.resize(1);

                        for (auto player : playerList)
                        {
                            std::ostringstream str;
                            str << player->GetName(); " has been targeted by |cFFF00000|h[Piercing Barb]|h|r!";
                            me->TextEmote(str.str().c_str(), 0, true);

                            me->CastSpell(player, SPELL_PIERCING_BARB_CAST);
                        }
                    }
                    events.ScheduleEvent(EVENT_PIERCING_BARB, TIMER_PIERCING_BARB_AFTER);
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_blackwater_behemoth_AI(creature);
    }
};

// 292159 toxic spine
class bfa_spell_toxic_spine : public SpellScriptLoader
{
public:
    bfa_spell_toxic_spine() : SpellScriptLoader("bfa_spell_toxic_spine") { }

    class bfa_spell_toxic_spine_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toxic_spine_SpellScript);

        void AfterCast(SpellEffIndex index)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            std::list<Player*> playerList;
            caster->GetPlayerListInGrid(playerList, 100.0f);
            if (!playerList.empty())
            {
                if (caster->GetMap()->IsMythic())
                {
                    if (playerList.size() >= 10)
                    {
                        playerList.resize(10);
                    }
                }
                else
                {
                    if (playerList.size() >= 5)
                        playerList.resize(5);
                }

                for (std::list<Player*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                {
                    caster->CastSpell((*itr), SPELL_TOXIC_SPINE_MISSILE, true);
                }
            }
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(bfa_spell_toxic_spine_SpellScript::AfterCast, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toxic_spine_SpellScript();
    }
};

// 298424 feeding frenzy
class bfa_spell_feeding_frenzy : public SpellScriptLoader
{
public:
    bfa_spell_feeding_frenzy() : SpellScriptLoader("bfa_spell_feeding_frenzy") { }

    class bfa_spell_feeding_frenzy_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_feeding_frenzy_AuraScript);

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
                if (Aura* frenzy = caster->GetAura(SPELL_FEEDING_FRENZY_AURA))
                    frenzy->SetStackAmount(1);
                currentTarget = target->GetGUID();
            }
            else
                caster->CastSpell(caster, SPELL_FEEDING_FRENZY_AURA, true);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(bfa_spell_feeding_frenzy_AuraScript::HandleOnProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_feeding_frenzy_AuraScript();
    }
};

// 297932 bioelectric feelers
class bfa_spell_bioelectric_feelers : public SpellScriptLoader
{
public:
    bfa_spell_bioelectric_feelers() : SpellScriptLoader("bfa_spell_bioelectric_feelers") { }

    class bfa_spell_bioelectric_feelers_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_bioelectric_feelers_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
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
                        if (initialPlayer->GetDistance2d(otherPlayer) <= 5.0f)
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
                caster->CastSpell(validTarget, SPELL_BIOELECTRIC_FEELERS_DAMAGE, true);
            }
        }



        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_bioelectric_feelers_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_bioelectric_feelers_AuraScript();
    }
};

// 292307 gaze from below
class bfa_spell_gaze_from_below : public SpellScriptLoader
{
public:
    bfa_spell_gaze_from_below() : SpellScriptLoader("bfa_spell_gaze_from_below") { }

    class bfa_spell_gaze_from_below_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_gaze_from_below_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;

            target->Kill(target, false);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_gaze_from_below_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_gaze_from_below_AuraScript();
    }
};

// 298595 glowing stinger
class bfa_spell_glowing_stinger : public SpellScriptLoader
{
public:
    bfa_spell_glowing_stinger() : SpellScriptLoader("bfa_spell_glowing_stinger") { }

    class bfa_spell_glowing_stinger_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_glowing_stinger_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;

            target->CastSpell(target, SPELL_BIOLUMINESCENCE, true);
            target->CastSpell(target, SPELL_GAZE_FROM_BELOW, true);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_glowing_stinger_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_glowing_stinger_AuraScript();
    }
};

class bfa_npc_oxygen_rich_membrane : public CreatureScript
{
public:
    bfa_npc_oxygen_rich_membrane() : CreatureScript("bfa_npc_oxygen_rich_membrane") { }

    bool OnGossipHello(Player* player, Creature* me)
    {
        if (!me || !player)
            return false;

        if (!player->HasAura(SPELL_OXYGEN_RICH_MEMBRANE))
        {
            player->CastSpell(player, SPELL_OXYGEN_RICH_MEMBRANE, true);
        }
        return true;
    }
};

class bfa_npc_pufferfish : public CreatureScript
{
public:
    bfa_npc_pufferfish() : CreatureScript("bfa_npc_pufferfish") {}

    struct bfa_npc_pufferfish_AI : public ScriptedAI
    {
        bfa_npc_pufferfish_AI(Creature* creature) : ScriptedAI(creature)
        {
            creature->AddUnitState(UNIT_STATE_ROOT);
        }

        bool dead;

        void Reset()
        {
            dead = false;
        }

        void DamageTaken(Unit* at, uint32& damage)
        {
            if (damage >= me->GetHealth() && !dead)
            {
                dead = true;
                damage = 0;
                me->CastSpell(me, SPELL_BIOLUMINESCENT_CLOUND, true);
                me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                me->DespawnOrUnsummon(10 * IN_MILLISECONDS);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_pufferfish_AI(creature);
    }
};

class bfa_npc_darkwater_jellyfish : public CreatureScript
{
public:
    bfa_npc_darkwater_jellyfish() : CreatureScript("bfa_npc_darkwater_jellyfish") {}

    struct bfa_npc_darkwater_jellyfish_AI : public ScriptedAI
    {
        bfa_npc_darkwater_jellyfish_AI(Creature* creature) : ScriptedAI(creature)
        {
            creature->AddUnitState(UNIT_STATE_ROOT);
        }

        void UpdateAI(uint32 diff)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster() && (player->GetDistance(me) <= 2.0f))
                    {
                        if (!player->HasAura(SPELL_GLOWING_STINGER_AURA))
                            player->AddAura(SPELL_GLOWING_STINGER_AURA, player);
                    }
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_darkwater_jellyfish_AI(creature);
    }
};

// 301930 piercing barb damage
class bfa_spell_piercing_barb_damage : public SpellScriptLoader
{
public:
    bfa_spell_piercing_barb_damage() : SpellScriptLoader("bfa_spell_piercing_barb_damage") { }

    class bfa_spell_piercing_barb_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_piercing_barb_damage_SpellScript);

        uint32 targetList;

        bool Load() override
        {
            targetList = 0;
            return true;
        }

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_PIERCING_BARB_DAMAGE, true);
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
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_piercing_barb_damage_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_TARGET_ENEMY);
            OnEffectHitTarget += SpellEffectFn(bfa_spell_piercing_barb_damage_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            AfterCast += SpellCastFn(bfa_spell_piercing_barb_damage_SpellScript::HandleAfterCast);

        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_piercing_barb_damage_SpellScript();
    }
};

// 301494 piercing barb 
class bfa_spell_piercing_barb_beam : public SpellScriptLoader
{
public:
    bfa_spell_piercing_barb_beam() : SpellScriptLoader("bfa_spell_piercing_barb_beam") { }

    class bfa_spell_piercing_barb_beam_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_piercing_barb_beam_AuraScript);

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

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();
            Unit* target = caster->GetVictim();
            if (!caster || !target)
                return;

            std::list<Player*> targetList;

            Unit* maintrigger = caster;
            Unit* triggerTarget = target;
            Unit* targetPlayer = NULL;

            if (!maintrigger || !triggerTarget)
                return;

            Map::PlayerList const& playerList = maintrigger->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    Position myPos = maintrigger->GetPosition();
                    Position triggerPos = triggerTarget->GetPosition();
                    if (IsOnBeam(player, myPos, triggerPos, 3.0f, 2.0f, maintrigger->GetExactDist2d(triggerTarget)) && maintrigger->isInFront(player))
                    {
                        targetList.push_back(player);
                    }
                    else
                        targetList.remove(player);
                }
        }



        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_piercing_barb_beam_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_piercing_barb_beam_AuraScript();
    }
};


// 292279 shock pulse damage 
class bfa_spell_shock_pulse_damage : public SpellScriptLoader
{
public:
    bfa_spell_shock_pulse_damage() : SpellScriptLoader("bfa_spell_shock_pulse_damage") { }

    class bfa_spell_shock_pulse_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_shock_pulse_damage_SpellScript);

        void DealDamage()
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            if (!caster || !target)
                return;

            float distance = 50.0f;

            SetHitDamage(GetHitDamage() / distance);
        }

        void Register()
        {
            OnHit += SpellHitFn(bfa_spell_shock_pulse_damage_SpellScript::DealDamage);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_shock_pulse_damage_SpellScript();
    }
};

// 16226 bioluminescence
class bfa_at_bioluminescence : public AreaTriggerEntityScript
{
public:
    bfa_at_bioluminescence() : AreaTriggerEntityScript("bfa_at_bioluminescence") { }

    struct bfa_at_bioluminescence_AI : AreaTriggerAI
    {
        bfa_at_bioluminescence_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUpdate(uint32 diff)
        {
            float range = 8.0f;

            std::list<Player*> playerList;
            at->GetPlayerListInGrid(playerList, 8.0f);
           /* if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    if (!player->HasAura(SPELL_BIOLUMINESCENCE) && !player->GetRoleForGroup() == ROLE_TANK)
                        player->AddAura(SPELL_BIOLUMINESCENCE, player);
                    else if (!player->HasAura(SPELL_BIOLUMINESCENCE && player->GetRoleForGroup() == ROLE_TANK))
                        player->AddAura(SPELL_RADIANT_BIOMASS_AURA, player);
                }*/
           // }
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_bioluminescence_AI(areatrigger);
    }
};

// 295412 radiant biomass
class bfa_spell_radiant_biomass : public SpellScriptLoader
{
public:
    bfa_spell_radiant_biomass() : SpellScriptLoader("bfa_spell_radiant_biomass") { }

    class bfa_spell_radiant_biomass_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_radiant_biomass_AuraScript);

        void HandleOnProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            Unit* caster = eventInfo.GetActor();
            Unit* target = eventInfo.GetActionTarget();
            if (!caster || !target)
                return;

            caster->CastSpell(caster, SPELL_RADIANT_BIOMASS_PROC, true);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(bfa_spell_radiant_biomass_AuraScript::HandleOnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_radiant_biomass_AuraScript();
    }
};

void AddSC_blackwater_behemoth()
{
    new bfa_boss_blackwater_behemoth();
    new bfa_npc_oxygen_rich_membrane();
    new bfa_npc_darkwater_jellyfish();
    new bfa_npc_pufferfish();
    new bfa_at_bioluminescence();
    new bfa_spell_bioelectric_feelers();
    new bfa_spell_feeding_frenzy();
    new bfa_spell_gaze_from_below();
    new bfa_spell_glowing_stinger();
    new bfa_spell_piercing_barb_beam();
    new bfa_spell_piercing_barb_damage();
    new bfa_spell_radiant_biomass();
    new bfa_spell_shock_pulse_damage();
    new bfa_spell_toxic_spine();
}
