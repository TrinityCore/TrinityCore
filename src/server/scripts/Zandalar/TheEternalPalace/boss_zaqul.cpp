#include "eternal_palace.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "AreaTriggerTemplate.h"
#include "PhaseShift.h"
#include "PhasingHandler.h"
#include "Player.h"

enum Spells
{
    SPELL_DARK_BEYOND_AT = 295335,
    SPELL_DARK_BEYOND_AURA = 298192,
    SPELL_MIND_TETHER_CAST = 295444,
    SPELL_MIND_TETHER_LINKAGE = 295498,
    SPELL_MIND_TETHER_LINKAGE_DAMAGE = 295642,
    SPELL_SNAPPED = 300133,
    SPELL_CRUSHING_GRASP_MAIN_CAST = 301141,
    SPELL_CRUSHING_GRASP_PORTAL_CAST = 292565,
    SPELL_CRUSHING_GRASP_AT = 292563, // portal asap
    SPELL_DREAD = 292963,
    SPELL_DREAD_DAMAGE = 299966,
    SPELL_PORTAL_OF_MADNESS_MISSILE = 294542,
    SPELL_DARK_TEAR = 294515,
    SPELL_DARK_TEAR_SUMMON = 299615,
    SPELL_VOID_ERUPTION = 304709,
    SPELL_HYSTERIA = 292971,
    SPELL_FEAR_REALM = 295173,
    SPELL_FEAR_REALM_CAST = 296257,
    SPELL_PUNCTURE_DARKNESS = 295099,
    SPELL_MADDENING_ERUPTION_DAMAGE_ALL = 295079,
    SPELL_MADDENING_ERUPTION_DAMAGE_ZONE = 295076,
    SPELL_MADDENING_ERUPTION_MISSILE = 302145, // zones asap
    SPELL_MANIFEST_NIGHTMARE = 293509,
    SPELL_NIGHTMARE_POOL_AT = 303818,
    SPELL_NIGHTMARE_POOL_AURA = 303819,
    SPELL_DELIRIUM_REALM = 295249, //aura on player within realm
    SPELL_SHATTERED_PSYCHE = 295327,
    SPELL_DELIRIUM_REALM_CAST = 296262, // 1
    SPELL_REALITY_PORTAL = 300584,
    SPELL_REALITY_PORTAL_AT = 302198,
    SPELL_REALITY_PORTAL_SUMMON = 302219,
    SPELL_RETURN_TO_REALITY = 296300,
    SPELL_REALITY_PORTAL_BUTTON = 302200,
    SPELL_REALITY_PORTAL_BUTTON_SPELL = 302202,
    SPELL_REALITY_PORTAL_BUTTON_SPELL_TRIGGERED = 296300,
    SPELL_MANIC_DREAD_MISSILE = 296012,
    SPELL_MANIC_DREAD_DAMAGE_MISSILE = 296022,
    SPELL_MANIC_DREAD_AURA = 296018,
    SPELL_CAUSTIC_DELIRIUM_AT = 296014, // formed by 1
    SPELL_CAUSTIC_DELIRIUM_AURA = 295999,
    SPELL_CAUSTIC_DELIRIUM_PERIODIC = 296015,
    SPELL_DARK_PULSE_CAST_SHIELD = 296078,
    SPELL_DARK_PULSE_CAST_DAMAGE = 296085,
    SPELL_MIND_FRACTURE = 296084,
    SPELL_DARK_PASSAGE_MISSILE = 299703,
    SPELL_DARK_PASSAGE_DAMAGE = 299705,
    SPELL_DARK_PASSAGE_SUMMONER_SUMMON = 299706,
    SPELL_FEAR_GATE_VISUAL_CAST = 299617,
    SPELL_SHROUD_OF_FEAR = 299591,
    SPELL_FEAR_GATE_BUTTON = 301426,
    SPELL_FEAR_GATE_BUTTON_TRIGGERED = 301427,
    SPELL_FEAR_GATE_MISC = 296300,
    SPELL_FEAR_GATE_SUMMON = 299722,
    SPELL_FEAR_GATE_AT = 299721, // 301433 ?
    SPELL_GATHERING_NIGHTMARE = 300635,
    SPELL_GATHERING_NIGHTMARE_SIZE = 300636,
    SPELL_QUIVERING_CLAWS = 294652,
    SPELL_TENTACLE_SLAM = 303832,
    SPELL_DREAD_SCREAM = 303543,
    SPELL_VOID_SLAM = 313897,
    SPELL_DARK_SHIELD = 301117,
    SPELL_PSYCHOTIC_SPLIT = 301068,
    SPELL_PSYCHOTIC_SPLIT_MISSILE = 295829, // ?!
};

enum Events
{
    EVENT_CHECK_ENERGY = 1,
    EVENT_DARK_BEYOND,
    EVENT_MIND_TETHER,
    EVENT_DREAD,
    EVENT_CRUSHING_GRASP,
    EVENT_PORTAL_OF_MADNESS,
    EVENT_MANIFEST_NIGHTMARE,
    EVENT_DELIRIUM_REALM,
    EVENT_MADDENING_ERUPTION,
    EVENT_MANIC_DREAD,
    EVENT_DARK_PULSE,
    EVENT_PSYCHOTIC_SPLIT,
    EVENT_DARK_PASSAGE,
    EVENT_MADDENING_ERUPTION_TRIGGER,
    EVENT_DARK_TEAR,
    EVENT_GATHERING_NIGHTMARE,
    EVENT_FEAR_GATE,
    EVENT_TENTACLE_SLAM,
    EVENT_VOID_SLAM,
    EVENT_DREAD_SCREAM,
};

enum Timers
{
    TIMER_CHECK_ENERGY = 1000 * IN_MILLISECONDS,
    TIMER_DARK_BEYOND = 2 * IN_MILLISECONDS,
    TIMER_MIND_TETHER = 3 * IN_MILLISECONDS,
    TIMER_MADDENING_ERUPTION = 35 * IN_MILLISECONDS,
    TIMER_MANIC_DREAD = 25 * IN_MILLISECONDS,
    TIMER_DARK_PULSE = 1 * IN_MILLISECONDS,
    TIMER_CRUSHING_GRASP = 40 * IN_MILLISECONDS,
    TIMER_DREAD = 25 * IN_MILLISECONDS,
    TIMER_PORTAL_OF_MADNESS = 15 * IN_MILLISECONDS,
    TIMER_DELIRIUM_REALM = 20 * IN_MILLISECONDS,
    TIMER_MANIFEST_NIGHTMARE = 45 * IN_MILLISECONDS,
    TIMER_PSYCHOTIC_SPLIT = 1 * IN_MILLISECONDS,
    TIMER_DARK_PASSAGE = 35 * IN_MILLISECONDS,
    TIMER_FEAR_GATE = 1 * IN_MILLISECONDS,
    TIMER_DARK_TEAR = 1 * IN_MILLISECONDS,
    TIMER_GATHERING_NIGHTMARE = 1 * IN_MILLISECONDS,
    TIMER_TENTACLE_SLAM = 8 * IN_MILLISECONDS,
    TIMER_MADDENING_ERUPTION_TRIGGER = 20 * IN_MILLISECONDS,
    TIMER_DREAD_SCREAM = 8 * IN_MILLISECONDS,
    TIMER_VOID_SLAM = 8 * IN_MILLISECONDS,
};

const Position centerPos = { 197.69f, 2012.56f, 755.92f };

struct checkSpecsPlayers : public std::unary_function<Unit*, bool>
{
    checkSpecsPlayers() {}

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

#define THALYSSRA_TEXT "We will not succumb to madness!"
#define ZAQUL_TEXT "Bend to the master's will."
#define THALYSSRA_TEXT_2 "Their whispers are driving me mad!"
#define ZAQUL_SPECIAL "None can escape N'Zoth's grasp!"
#define QUEEN_AZSHARA_RP "Nicely done! It is so rare for mortals to exceed my expectations. If only your friends had been as capable."

//150859
class bfa_boss_zaqul : public CreatureScript
{
public:
    bfa_boss_zaqul() : CreatureScript("bfa_boss_zaqul") { }

    struct bfa_boss_zaqul_AI : public BossAI
    {
        bfa_boss_zaqul_AI(Creature* creature) : BossAI(creature, DATA_ZAQUL), summons(me) { }

        SummonList summons;
        bool phase2;
        bool phase3;
        bool phase4;
        uint8 _echoKilled;

        Creature* GetThalyssra()
        {
            return me->FindNearestCreature(NPC_FIRST_ARCANIST_THALYSSRA, 200.0f, true);
        }

        void Reset() override
        {
            events.Reset();
            phase2 = false;
            phase3 = false;
            phase4 = false;
            summons.DespawnAll();
            ForcePhaseWipe();
            SetCustomPhase(me, 1, true);           
            _echoKilled = 0;
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
        }

        void EnterCombat(Unit* target)// override
        {
          //  _EnterCombat();
            Talk(0);            
            me->SummonCreature(NPC_FACING_TRIGGER_CRUSHING_GRASP, centerPos, TEMPSUMMON_MANUAL_DESPAWN);
            SwitchPhases(1);
        }

        void JustDied(Unit* target) override
        {
            Talk(1);
            _JustDied();
            ForcePhaseWipe();
            summons.DespawnAll();
            SetCustomPhase(me, 1, true);
        }

        void EnterEvadeMode(EvadeReason w) override
        {
            _DespawnAtEvade(15);
        }

        void KilledUnit(Unit* target) override
        {
            if (target->IsPlayer() && roll_chance_f(15))
                Talk(3);
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case NPC_CRUSHING_GRASP_TRIGGER:
                summon->AddUnitState(UNIT_STATE_ROOT);
                break;
            case NPC_HORRIFIC_SUMMONER:
            case NPC_HORRIFIC_SUMMONER_DARK_PASSAGE:
                summon->SetInCombatWithZone();
                break;
            case NPC_FIRST_ARCANIST_THALYSSRA:
                summon->AddUnitState(UNIT_STATE_ROOT);
                break;
            case NPC_ECHO_OF_DELIRIUM:
            case NPC_ECHO_OF_FEAR:
                summon->SetInCombatWithZone();
                break;
            }
        }

        void CheckEcho()
        {
            ++_echoKilled;

            Talk(4);

            if (_echoKilled >= 2)
                me->RemoveAura(SPELL_DARK_SHIELD);
        }

        void DamageTaken(Unit* target, uint32& damage) override
        {
            if (me->HealthBelowPct(85) && !phase2)
            {
                phase2 = true;
                SwitchPhases(2);
                me->CastSpell(me, SPELL_FEAR_REALM_CAST);
            }

            if (me->HealthBelowPct(70) && !phase3)
            {
                phase3 = true;
                SwitchPhases(3);
            }

            if (me->HealthBelowPct(50) && !phase4)
            {
                phase4 = true;
                SwitchPhases(4);
            }
        }

        void ForcePhaseWipe()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    SetCustomPhase(player, 1, true);
        }

        void SetFearRealmPhase()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    if (player->IsAlive() && !player->IsGameMaster())
                    {
                        SetCustomPhase(player, 2, true);
                        SetCustomPhase(me, 2, true);
                        player->AddAura(SPELL_FEAR_REALM, player);
                    }

            std::ostringstream str;
            str << "Za'qul drags you into the Fear Realm!";
            me->TextEmote(str.str().c_str(), 0, true);
        }

        void SetCustomPhase(Unit* UnitTarget, uint32 phase_id, bool visibility)
        {
            PhasingHandler::AddPhase(UnitTarget, phase_id, visibility);
        }

        void SwitchPhases(uint32 phase_id)
        {
            switch (phase_id)
            {
            case 1:
            {
                events.Reset();
                me->CastSpell(centerPos, SPELL_DARK_BEYOND_AT, true);
                events.ScheduleEvent(EVENT_DARK_BEYOND, TIMER_DARK_BEYOND);
                events.ScheduleEvent(EVENT_MIND_TETHER, TIMER_MIND_TETHER);
                events.ScheduleEvent(EVENT_CRUSHING_GRASP, TIMER_CRUSHING_GRASP);
                events.ScheduleEvent(EVENT_DREAD, TIMER_DREAD);
                events.ScheduleEvent(EVENT_PORTAL_OF_MADNESS, TIMER_PORTAL_OF_MADNESS);
                break;
            }
            case 2:
            {
                SetFearRealmPhase();
                me->CastSpell(centerPos, SPELL_DARK_BEYOND_AT, true);
                Talk(6);
                events.Reset();
                events.ScheduleEvent(EVENT_DARK_BEYOND, TIMER_DARK_BEYOND);
                events.ScheduleEvent(EVENT_MIND_TETHER, TIMER_MIND_TETHER);
                events.ScheduleEvent(EVENT_CRUSHING_GRASP, TIMER_CRUSHING_GRASP);
                events.ScheduleEvent(EVENT_DREAD, TIMER_DREAD);
                events.ScheduleEvent(EVENT_MADDENING_ERUPTION, TIMER_MADDENING_ERUPTION);
                events.ScheduleEvent(EVENT_MANIFEST_NIGHTMARE, TIMER_MANIFEST_NIGHTMARE);
                break;
            }
            case 3:
            {
                me->CastSpell(centerPos, SPELL_DARK_BEYOND_AT, true);
                events.Reset();
                events.ScheduleEvent(EVENT_DARK_BEYOND, TIMER_DARK_BEYOND);
                events.ScheduleEvent(EVENT_MIND_TETHER, TIMER_MIND_TETHER);
                events.ScheduleEvent(EVENT_CRUSHING_GRASP, TIMER_CRUSHING_GRASP);
                events.ScheduleEvent(EVENT_DREAD, TIMER_DREAD);
                events.ScheduleEvent(EVENT_MADDENING_ERUPTION, TIMER_MADDENING_ERUPTION);
                events.ScheduleEvent(EVENT_MANIFEST_NIGHTMARE, TIMER_MANIFEST_NIGHTMARE);
                events.ScheduleEvent(EVENT_DELIRIUM_REALM, TIMER_DELIRIUM_REALM);
                break;
            }
            case 4:
            {
                me->CastSpell(centerPos, SPELL_DARK_BEYOND_AT, true);
                events.Reset();
                events.ScheduleEvent(EVENT_DARK_BEYOND, TIMER_DARK_BEYOND);
                events.ScheduleEvent(EVENT_MIND_TETHER, TIMER_MIND_TETHER);
                events.ScheduleEvent(EVENT_CRUSHING_GRASP, TIMER_CRUSHING_GRASP);
                events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
                events.ScheduleEvent(EVENT_MANIC_DREAD, TIMER_MANIC_DREAD);
                events.ScheduleEvent(EVENT_DARK_PASSAGE, TIMER_DARK_PASSAGE);
                Position random = me->GetRandomPoint(centerPos, 30.0f);
                if (Creature* thalys = me->SummonCreature(NPC_FIRST_ARCANIST_THALYSSRA, random, TEMPSUMMON_MANUAL_DESPAWN))
                {
                    /*thalys->AI()->Talk(0);*/
                    me->GetScheduler().Schedule(3s, [this](TaskContext /*context*/)
                        {
                            //Talk(0);
                        });
                    me->GetScheduler().Schedule(5s, [this](TaskContext /*context*/)
                        {
                            /*if (Creature* thalys = GetThalyssra())
                                thalys->AI()->Talk(0);*/
                        });
                }
                break;
            }
            }
        }

        void SummonQueenAndPorta()
        {
            if (Creature* portal = me->SummonCreature(NPC_PORTAL_TO_AZSHARA, 195.06f, 2053.93f, 756.05f, TEMPSUMMON_MANUAL_DESPAWN))
                portal->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);

            if (Creature* queen = me->SummonCreature(NPC_QUEEN_AZSHARA_RP, 212.74f, 2059.38f, 777.33f, TEMPSUMMON_MANUAL_DESPAWN))
            {
                //SelectSoundAndText(queen, 14);
                queen->DespawnOrUnsummon(5 * IN_MILLISECONDS);
            }
        }

        bool HandleDarkBeyond()
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 200.0f);
            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    if (player->GetDistance(centerPos) >= 43.0f)
                    {
                        if (Aura* dark = player->AddAura(SPELL_DARK_BEYOND_AURA, player))
                        {
                            dark->SetMaxDuration(2 * IN_MILLISECONDS);
                            dark->SetDuration(2 * IN_MILLISECONDS);
                        }
                        return false;
                    }
                }
            }
            return true;
        }

        void HandleDeliriumRealm()
        {
            std::ostringstream str;
            str << "Za'qul tears open the pathway to Delirium Realm!";
            me->TextEmote(str.str().c_str(), 0, true);

            me->CastSpell(me, SPELL_DELIRIUM_REALM_CAST);
        }

        void SelectRandomPosition()
        {
            float x, y, z, o;
            float newy;
            switch (rand() % 6)
            {
            case 1:
                x = 160.59f;
                y = 1988.48f;
                newy = y + 5.0f;
                z = 756.12f;
                o = 0.57f;
                break;
            case 2:
                x = 214.99f;
                y = 1971.42f;
                newy = y + 5.0f;
                z = 756.23f;
                o = 1.98f;
                break;
            case 3:
                x = 241.93f;
                y = 2013.60f;
                newy = y + 5.0f;
                z = 756.23f;
                o = 3.05f;
                break;
            case 4:
                x = 225.99f;
                y = 2056.41f;
                z = 756.18f;
                o = 4.03f;
                break;
            case 5:
                x = 186.24f;
                y = 2054.84f;
                newy = y + 5.0f;
                z = 755.98f;
                o = 4.97f;
                break;
            case 6:
                x = 156.92f;
                y = 2029.49f;
                newy = y + 5.0f;
                z = 755.98f;
                o = 5.93f;
                break;
            }
            if (Creature* trigger = me->SummonCreature(NPC_CRUSHING_GRASP_TRIGGER, x, y, z, TEMPSUMMON_MANUAL_DESPAWN))
                trigger->SetOrientation(o);

            if (me->GetMap()->IsMythic())
            {
                for (uint8 i = 0; i < 2; ++i)
                {
                    if (Creature* trigger = me->SummonCreature(NPC_CRUSHING_GRASP_TRIGGER, x, (newy + i), z, TEMPSUMMON_MANUAL_DESPAWN))
                        trigger->SetOrientation(o);
                }
            }
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
                case EVENT_CHECK_ENERGY:
                {
                    if (me->GetPower(POWER_ENERGY) >= 100)
                    {
                        if (me->GetMap()->IsMythic())
                            events.ScheduleEvent(EVENT_PSYCHOTIC_SPLIT, TIMER_PSYCHOTIC_SPLIT);
                        else
                            events.ScheduleEvent(EVENT_DARK_PULSE, TIMER_DARK_PULSE);
                    }

                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + urand(1, 2));
                    events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
                    break;
                }
                case EVENT_DARK_PULSE:
                {
                    Talk(4);
                    std::ostringstream str;
                    str << "Za'qul prepares to unleash |cFFF00000|h[Dark Pulse]|h|r";
                    me->TextEmote(str.str().c_str(), 0, true);

                    me->CastSpell(me, SPELL_DARK_PULSE_CAST_SHIELD);
                    break;
                }
                case EVENT_PSYCHOTIC_SPLIT:
                {
                    Talk(4);
                    std::ostringstream str;
                    str << "Za'qul prepares to unleash |cFFF00000|h[Psychotic Split]|h|r";
                    me->TextEmote(str.str().c_str(), 0, true);

                    me->CastSpell(me, SPELL_PSYCHOTIC_SPLIT_MISSILE, true);
                    me->CastSpell(me, SPELL_DARK_SHIELD, true);
                    break;
                }
                case EVENT_DARK_PASSAGE:
                {
                    for (uint8 i = 0; i < 3; ++i)
                    {
                        Position random = me->GetRandomPoint(centerPos, 30.0f);
                        me->CastSpell(random, SPELL_DARK_PASSAGE_MISSILE);
                    }
                    events.ScheduleEvent(EVENT_DARK_PASSAGE, TIMER_DARK_PASSAGE);
                    break;
                }
                case EVENT_MIND_TETHER:
                {
                    Talk(6);
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_MIND_TETHER_CAST);
                    break;
                }
                case EVENT_DARK_BEYOND:
                {
                    HandleDarkBeyond();
                    events.ScheduleEvent(EVENT_DARK_BEYOND, TIMER_DARK_BEYOND);
                    break;
                }
                case EVENT_CRUSHING_GRASP:
                {
                    me->CastSpell(me, SPELL_CRUSHING_GRASP_MAIN_CAST);
                    events.ScheduleEvent(EVENT_CRUSHING_GRASP, TIMER_CRUSHING_GRASP);
                    break;
                }
                case EVENT_DREAD:
                {
                    Talk(7);
                    me->CastSpell(me->GetVictim(), SPELL_DREAD);
                    events.ScheduleEvent(EVENT_DREAD, TIMER_DREAD);
                    break;
                }
                case EVENT_PORTAL_OF_MADNESS:
                {
                    for (uint8 i = 0; i < 3; ++i)
                    {
                        Position random = me->GetRandomPoint(centerPos, 30.0f);
                        if (Creature* eruption = me->SummonCreature(NPC_MADDENING_ERUPTION_TRIGGER, random, TEMPSUMMON_MANUAL_DESPAWN))
                            me->CastSpell(eruption, SPELL_PORTAL_OF_MADNESS_MISSILE, true);
                    }
                    events.ScheduleEvent(EVENT_PORTAL_OF_MADNESS, TIMER_PORTAL_OF_MADNESS);
                    break;
                }
                case EVENT_MADDENING_ERUPTION:
                {
                    std::ostringstream str;
                    str << "Za'qul creates a |cFFF00000|h[Maddening Eruption]|h|r";
                    me->TextEmote(str.str().c_str(), 0, true);

                    Position random = me->GetRandomPoint(centerPos, 30.0f);
                    me->CastSpell(random, SPELL_MADDENING_ERUPTION_MISSILE);
                    events.ScheduleEvent(EVENT_MADDENING_ERUPTION, TIMER_MADDENING_ERUPTION);
                    break;
                }
                case EVENT_MANIFEST_NIGHTMARE:
                {
                    std::list<Player*> playerList;
                    me->GetPlayerListInGrid(playerList, 150.0f);
                    if (playerList.size() >= 2)
                        playerList.resize(2);

                    if (!playerList.empty())
                    {
                        for (auto player : playerList)
                        {
                            me->CastSpell(player, SPELL_MANIFEST_NIGHTMARE, true);
                        }
                    }

                    events.ScheduleEvent(EVENT_MANIFEST_NIGHTMARE, TIMER_MANIFEST_NIGHTMARE);
                    break;
                }
                case EVENT_DELIRIUM_REALM:
                {
                    Talk(8);
                    HandleDeliriumRealm();
                    events.ScheduleEvent(EVENT_DELIRIUM_REALM, TIMER_DELIRIUM_REALM);
                    break;
                }
                case EVENT_MANIC_DREAD:
                {
                    Talk(7);
                    std::ostringstream str;
                    str << "Za'qul prepares to unleash |cFFF00000|h[Manic Dread]|h|r";
                    me->TextEmote(str.str().c_str(), 0, true);
                    me->CastSpell(me, SPELL_MANIC_DREAD_AURA);
                    events.ScheduleEvent(EVENT_MANIC_DREAD, TIMER_MANIC_DREAD);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_zaqul_AI(creature);
    }
};

// 295249
class bfa_spell_delirium_realm_aura : public SpellScriptLoader
{
public:
    bfa_spell_delirium_realm_aura() : SpellScriptLoader("bfa_spell_delirium_realm_aura") { }

    class bfa_spell_delirium_realm_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_delirium_realm_aura_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* target = GetTarget()->ToPlayer();
            if (!target)
                return;

            if (Aura* hysteria = target->AddAura(SPELL_HYSTERIA, target))
                hysteria->SetStackAmount(hysteria->GetStackAmount() + 1);
        }

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* target = GetTarget()->ToPlayer();
            if (!target)
                return;

            if (mode == AURA_REMOVE_BY_DEATH)
            {
                if (Unit* zaqul = target->FindNearestCreature(BOSS_ZAQUL, 200.0f, true))
                {
                    bfa_boss_zaqul::bfa_boss_zaqul_AI* ai = CAST_AI(bfa_boss_zaqul::bfa_boss_zaqul_AI, zaqul->GetAI());

                    ai->SetCustomPhase(target, 2, true);
                }
                Player* player = target->ToPlayer();
                if (player)
                    player->ResurrectPlayer(50.0f);
                target->AddAura(SPELL_SHATTERED_PSYCHE, target);
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_delirium_realm_aura_AuraScript::OnPeriodic, EFFECT_3, SPELL_AURA_PERIODIC_DUMMY);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_delirium_realm_aura_AuraScript::OnRemove, EFFECT_6, SPELL_AURA_SCREEN_EFFECT, AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_delirium_realm_aura_AuraScript();
    }
};

// 296262
class bfa_spell_delirium_realm_cast : public SpellScriptLoader
{
public:
    bfa_spell_delirium_realm_cast() : SpellScriptLoader("bfa_spell_delirium_realm_cast") { }

    class bfa_spell_delirium_realm_cast_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_delirium_realm_cast_SpellScript);

        void HandleDummy()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            std::list<AreaTrigger*> realms;
            caster->GetAreaTriggerListWithSpellIDInRange(realms, SPELL_CAUSTIC_DELIRIUM_AT, 30.0f);
            if (!realms.empty())
            {
                for (auto realmzone : realms)
                    realmzone->Remove();
            }

            for (uint8 i = 0; i < 3; ++i)
            {
                float x = caster->GetPositionX() + 5.0f * cos(i * M_PI / 5);
                float y = caster->GetPositionY();
                float z = caster->GetPositionZ();
                caster->CastSpell(SPELL_CAUSTIC_DELIRIUM_AT, true);
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_delirium_realm_cast_SpellScript::HandleDummy);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_delirium_realm_cast_SpellScript();
    }
};

// 17037 
class bfa_at_delirium_realm : public AreaTriggerEntityScript
{
public:
    bfa_at_delirium_realm() : AreaTriggerEntityScript("bfa_at_delirium_realm") { }

    struct bfa_at_delirium_realm_AI : AreaTriggerAI
    {
        bfa_at_delirium_realm_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        uint32 timer;

        void OnInitialize()
        {
            timer = 1000;
        }

        void OnRemove()
        {
            std::list<Player*> playerList;
            at->GetPlayerListInGrid(playerList, 3.0f);
            if (playerList.size() >= 1)
                playerList.resize(1);

            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    player->AddAura(SPELL_DELIRIUM_REALM, player);
                    if (Unit* zaqul = at->FindNearestCreature(BOSS_ZAQUL, 200.0f, true))
                    {
                        bfa_boss_zaqul::bfa_boss_zaqul_AI* ai = CAST_AI(bfa_boss_zaqul::bfa_boss_zaqul_AI, zaqul->GetAI());

                        ai->SetCustomPhase(player, 3, true);
                    }
                }
            }
        }

        void OnUpdate(uint32 diff) override
        {
            if (timer)
            {
                if (timer <= diff)
                {
                    std::list<Player*> playerList;
                    at->GetPlayerListInGrid(playerList, 3.0f);
                    if (!playerList.empty())
                    {
                        for (auto player : playerList)
                        {
                            if (!player->HasAura(SPELL_CAUSTIC_DELIRIUM_PERIODIC))
                            {
                                if (Aura* pool = player->AddAura(SPELL_CAUSTIC_DELIRIUM_PERIODIC, player))
                                {
                                    pool->SetMaxDuration(2000);
                                    pool->SetDuration(2000);
                                }
                            }
                        }
                    }
                    timer = 1000;
                }
                else
                    timer -= diff;
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_delirium_realm_AI(areatrigger);
    }
};

class bfa_npc_maddening_eruption_trigger : public CreatureScript
{
public:
    bfa_npc_maddening_eruption_trigger() : CreatureScript("bfa_npc_maddening_eruption_trigger")
    {
    }

    struct bfa_npc_maddening_eruption_trigger_AI : public ScriptedAI
    {
        bfa_npc_maddening_eruption_trigger_AI(Creature* creature) : ScriptedAI(creature)
        {
        }
        void Reset()
        {
            events.ScheduleEvent(EVENT_MADDENING_ERUPTION_TRIGGER, TIMER_MADDENING_ERUPTION_TRIGGER);
        }


        Creature* GetZaqul()
        {
            return me->FindNearestCreature(BOSS_ZAQUL, 10.0f, true);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MADDENING_ERUPTION_TRIGGER:
                {
                    if (Creature* zaqul = GetZaqul())
                    {
                        if (zaqul->GetDistance(me) <= 7.0f)
                        {
                            zaqul->AddAura(SPELL_PUNCTURE_DARKNESS, zaqul);
                            std::list<Player*> playerList;
                            me->GetPlayerListInGrid(playerList, 7.0f);
                            if (!playerList.empty())
                            {
                                for (auto player : playerList)
                                {
                                    zaqul->CastSpell(player, SPELL_MADDENING_ERUPTION_DAMAGE_ZONE, true);
                                }
                            }
                        }
                        else
                            zaqul->CastSpell(zaqul, SPELL_MADDENING_ERUPTION_DAMAGE_ALL, true);
                    }

                    me->DespawnOrUnsummon(2 * IN_MILLISECONDS);
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_maddening_eruption_trigger_AI(creature);
    }
};

// 295173
class bfa_spell_fear_realm_hysteria : public SpellScriptLoader
{
public:
    bfa_spell_fear_realm_hysteria() : SpellScriptLoader("bfa_spell_fear_realm_hysteria") { }

    class bfa_spell_fear_realm_hysteria_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_fear_realm_hysteria_AuraScript);

        void HandlePeriodic(AuraEffect const* aureff)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;

            //if (Aura* hysteria = target->AddAura(SPELL_HYSTERIA, target))
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_fear_realm_hysteria_AuraScript::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_fear_realm_hysteria_AuraScript();
    }
};

// 292963
class bfa_spell_dread_aura : public SpellScriptLoader
{
public:
    bfa_spell_dread_aura() : SpellScriptLoader("bfa_spell_dread_aura") { }

    class bfa_spell_dread_aura_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_dread_aura_SpellScript);

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> playerList;
            caster->GetPlayerListInGrid(playerList, 100.0f);
            playerList.remove_if(checkSpecsPlayers());

            if (playerList.size() >= (caster->GetMap()->IsMythic() ? 4 : 3))
                playerList.resize((caster->GetMap()->IsMythic() ? 4 : 3));

            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    player->AddAura(SPELL_DREAD, player);
                }
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_dread_aura_SpellScript::HandleAfterCast);
        }
    };

    class bfa_spell_dread_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_dread_aura_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* target = GetTarget()->ToPlayer();
            if (!target)
                return;

            if (mode == AURA_REMOVE_BY_ENEMY_SPELL || mode == AURA_REMOVE_BY_EXPIRE)
                target->CastSpell(target, SPELL_DREAD_DAMAGE, true);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_dread_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_FEAR_2, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_dread_aura_AuraScript();
    }

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_dread_aura_SpellScript();
    }
};

// 295444
class bfa_spell_mind_tether_cast : public SpellScriptLoader
{
public:
    bfa_spell_mind_tether_cast() : SpellScriptLoader("bfa_spell_mind_tether_cast") { }

    class bfa_spell_mind_tether_cast_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_mind_tether_cast_SpellScript);

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster)
                return;

            if (target)
                caster->CastSpell(target, SPELL_MIND_TETHER_LINKAGE, true);
            else
                caster->CastSpell(caster->GetVictim(), SPELL_SNAPPED, true);
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_mind_tether_cast_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_mind_tether_cast_SpellScript();
    }
};

// 295498
class bfa_spell_mind_tether_aura : public SpellScriptLoader
{
public:
    bfa_spell_mind_tether_aura() : SpellScriptLoader("bfa_spell_mind_tether_aura") { }

    class bfa_spell_mind_tether_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_mind_tether_aura_AuraScript);

        float range;
        Unit* nearestPlayer;
        uint32 damageReceived;

        bool Load()
        {
            range = 30.0f;
            damageReceived = 0;
            nearestPlayer = NULL;
            return true;
        }

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* target = GetTarget()->ToPlayer();
            if (!target)
                return;

            std::list<Player*> playerList;
            target->GetPlayerListInGrid(playerList, 50.0f);
            if (playerList.size())
            {
                for (auto player : playerList)
                {
                    if (player->GetDistance(target) <= range)
                        nearestPlayer = player;
                }
            }

            if (nearestPlayer)
                target->AddAura(SPELL_MIND_TETHER_LINKAGE, nearestPlayer);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_mind_tether_aura_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_mind_tether_aura_AuraScript();
    }
};

// 296257
class bfa_spell_fear_realm_cast : public SpellScriptLoader
{
public:
    bfa_spell_fear_realm_cast() : SpellScriptLoader("bfa_spell_fear_realm_cast") { }

    class bfa_spell_fear_realm_cast_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_fear_realm_cast_SpellScript);

        void HandleDummy()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (Unit* zaqul = caster->ToCreature())
            {
                bfa_boss_zaqul::bfa_boss_zaqul_AI* ai = CAST_AI(bfa_boss_zaqul::bfa_boss_zaqul_AI, zaqul->GetAI());

                ai->SwitchPhases(2);
            }
        }
        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_fear_realm_cast_SpellScript::HandleDummy);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_fear_realm_cast_SpellScript();
    }
};

// 301141
class bfa_spell_crushing_grasp_cast : public SpellScriptLoader
{
public:
    bfa_spell_crushing_grasp_cast() : SpellScriptLoader("bfa_spell_crushing_grasp_cast") { }

    class bfa_spell_crushing_grasp_cast_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_crushing_grasp_cast_SpellScript);

        void HandleDummy()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (Unit* zaqul = caster->ToCreature())
            {
                bfa_boss_zaqul::bfa_boss_zaqul_AI* ai = CAST_AI(bfa_boss_zaqul::bfa_boss_zaqul_AI, zaqul->GetAI());
                ai->SelectRandomPosition();
            }
        }
        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_crushing_grasp_cast_SpellScript::HandleDummy);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_crushing_grasp_cast_SpellScript();
    }
};

//151034
struct bfa_npc_crushing_grasp_trigger : public ScriptedAI
{
    bfa_npc_crushing_grasp_trigger(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
    }

    void Initialize()
    {
        me->CastSpell(me, SPELL_CRUSHING_GRASP_AT, true);
        me->DespawnOrUnsummon(10 * IN_MILLISECONDS);
    }
};

class bfa_npc_horrific_summoner : public CreatureScript
{
public:
    bfa_npc_horrific_summoner() : CreatureScript("bfa_npc_horrific_summoner") { }

    struct bfa_npc_horrific_summoner_AI : public ScriptedAI
    {
        bfa_npc_horrific_summoner_AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            events.Reset(); 
        }

        void EnterCombat(Unit*) //override
        {
            events.ScheduleEvent(EVENT_DARK_TEAR, TIMER_DARK_TEAR);
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
                case EVENT_DARK_TEAR:
                    me->CastSpell(me, SPELL_DARK_TEAR);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private: EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_horrific_summoner_AI(creature);
    }
};

// 294515
class bfa_spell_dark_tear_cast : public SpellScriptLoader
{
public:
    bfa_spell_dark_tear_cast() : SpellScriptLoader("bfa_spell_dark_tear_cast") { }

    class bfa_spell_dark_tear_cast_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_dark_tear_cast_SpellScript);

        void AfterCastDummy()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_VOID_ERUPTION, true);
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_dark_tear_cast_SpellScript::AfterCastDummy);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_dark_tear_cast_SpellScript();
    }
};

class bfa_npc_horrific_vision : public CreatureScript
{
public:
    bfa_npc_horrific_vision() : CreatureScript("bfa_npc_horrific_vision") { }

    struct bfa_npc_horrific_vision_AI : public ScriptedAI
    {
        bfa_npc_horrific_vision_AI(Creature* creature) : ScriptedAI(creature), summons(me) { }

        SummonList summons;
        bool _dead;

        void Reset() override
        {
            _dead = false;
            events.Reset();
        }

        void EnterCombat(Unit*) //override
        {
            if (me->GetMap()->IsHeroic())
            {
                events.ScheduleEvent(EVENT_GATHERING_NIGHTMARE, TIMER_GATHERING_NIGHTMARE);
                if (Aura* nightmare = me->AddAura(SPELL_GATHERING_NIGHTMARE, me))
                {
                    nightmare->SetStackAmount(30);
                }
                me->AddAura(SPELL_GATHERING_NIGHTMARE_SIZE, me);
            }
        }

        void JustSummoned(Creature* creature) override
        {
            summons.Summon(creature);

            switch (creature->GetEntry())
            {
            case NPC_UNLEASHED_NIGHTMARE:
                creature->SetInCombatWithZone();
                break;
            }
        }

        void DamageTaken(Unit* target, uint32& damage) override
        {
            if (_dead)
                damage = 0;
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
                case EVENT_GATHERING_NIGHTMARE:
                {
                    if (Aura* nightmare = me->GetAura(SPELL_GATHERING_NIGHTMARE))
                    {
                        if (nightmare->GetStackAmount() >= 1)
                            nightmare->SetStackAmount(nightmare->GetStackAmount() - 1);
                        else if (!me->HasAura(SPELL_GATHERING_NIGHTMARE))
                        {
                            _dead = true;
                            me->SummonCreature(NPC_UNLEASHED_NIGHTMARE, me->GetPosition(), TEMPSUMMON_DEAD_DESPAWN);
                            me->DespawnOrUnsummon(500);
                        }
                    }
                    events.ScheduleEvent(EVENT_GATHERING_NIGHTMARE, TIMER_GATHERING_NIGHTMARE);
                    break;
                }
                }
            }
        }

        void DoMeleeAttackIfReady()
        {
            if (Unit* target = me->GetVictim())
                me->CastSpell(target, SPELL_QUIVERING_CLAWS, true);
        }
    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_horrific_vision_AI(creature);
    }
};

// 294652
class bfa_spell_quivering_claws : public SpellScriptLoader
{
public:
    bfa_spell_quivering_claws() : SpellScriptLoader("bfa_spell_quivering_claws") { }

    class bfa_spell_quivering_claws_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_quivering_claws_SpellScript);

        void HandleDummy()
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!target || !caster)
                return;

            if (Aura* hysteria = caster->AddAura(SPELL_HYSTERIA, target))
            {
                hysteria->SetStackAmount(hysteria->GetStackAmount() + 1);
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_quivering_claws_SpellScript::HandleDummy);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_quivering_claws_SpellScript();
    }
};

// 17455 
class bfa_at_nightmare_pool : public AreaTriggerEntityScript
{
public:
    bfa_at_nightmare_pool() : AreaTriggerEntityScript("bfa_at_nightmare_pool") { }

    struct bfa_at_nightmare_pool_AI : AreaTriggerAI
    {
        bfa_at_nightmare_pool_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        uint32 timer;

        void OnInitialize()
        {
            timer = 1000;
        }

        void OnUpdate(uint32 diff) override
        {
            if (timer)
            {
                if (timer <= diff)
                {
                    std::list<Player*> playerList;
                    at->GetPlayerListInGrid(playerList, 4.5f);
                    if (!playerList.empty())
                    {
                        for (auto player : playerList)
                        {
                            if (!player->HasAura(SPELL_NIGHTMARE_POOL_AURA))
                            {
                                if (Aura* pool = player->AddAura(SPELL_NIGHTMARE_POOL_AURA, player))
                                {
                                    pool->SetMaxDuration(2000);
                                    pool->SetDuration(2000);
                                }
                            }
                        }
                    }
                    timer = 1000;
                }
                else
                    timer -= diff;
            }
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_nightmare_pool_AI(areatrigger);
    }
};

class bfa_npc_first_arcanist_thalyssra : public CreatureScript
{
public:
    bfa_npc_first_arcanist_thalyssra() : CreatureScript("bfa_npc_first_arcanist_thalyssra")  { }

    struct bfa_npc_first_arcanist_thalyssra_AI : public ScriptedAI
    {
        bfa_npc_first_arcanist_thalyssra_AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->CastSpell(me, SPELL_REALITY_PORTAL_AT, true);
            me->CastSpell(me, SPELL_REALITY_PORTAL);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_first_arcanist_thalyssra_AI(creature);
    }
};

// 17303
class bfa_at_reality_portal : public AreaTriggerEntityScript
{
public:
    bfa_at_reality_portal() : AreaTriggerEntityScript("bfa_at_reality_portal") { }

    struct bfa_at_reality_portal_AI : AreaTriggerAI
    {
        bfa_at_reality_portal_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit)
        {
            if (unit->GetTypeId() == TYPEID_PLAYER)
                if (!unit->HasAura(SPELL_REALITY_PORTAL_BUTTON))
                    unit->AddAura(SPELL_REALITY_PORTAL_BUTTON, unit);
        }

        void OnUnitExit(Unit* unit)
        {
            if (unit->HasAura(SPELL_REALITY_PORTAL_BUTTON))
                unit->RemoveAura(SPELL_REALITY_PORTAL_BUTTON);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_reality_portal_AI(areatrigger);
    }
};

// 302202
class bfa_spell_return_to_reality_button : public SpellScriptLoader
{
public:
    bfa_spell_return_to_reality_button() : SpellScriptLoader("bfa_spell_return_to_reality_button") { }

    class bfa_spell_return_to_reality_button_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_return_to_reality_button_SpellScript);

        void HandleDummy()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_REALITY_PORTAL_BUTTON_SPELL_TRIGGERED, true);
            if (Unit* zaqul = caster->FindNearestCreature(BOSS_ZAQUL, 200.0f, true))
            {
                bfa_boss_zaqul::bfa_boss_zaqul_AI* ai = CAST_AI(bfa_boss_zaqul::bfa_boss_zaqul_AI, zaqul->GetAI());

                ai->SetCustomPhase(caster, 1, true);
            }
            caster->RemoveAura(SPELL_REALITY_PORTAL_BUTTON);
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_return_to_reality_button_SpellScript::HandleDummy);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_return_to_reality_button_SpellScript();
    }
};

// 296022
class bfa_spell_manic_dread_missile : public SpellScriptLoader
{
public:
    bfa_spell_manic_dread_missile() : SpellScriptLoader("bfa_spell_manic_dread_missile") { }

    class bfa_spell_manic_dread_missile_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_manic_dread_missile_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (WorldLocation const* target = GetExplTargetDest())
                    caster->CastSpell(/*target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), */SPELL_CAUSTIC_DELIRIUM_AT, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_manic_dread_missile_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new bfa_spell_manic_dread_missile_SpellScript();
    }
};

// 296018
class bfa_spell_manic_dread_aura : public SpellScriptLoader
{
public:
    bfa_spell_manic_dread_aura() : SpellScriptLoader("bfa_spell_manic_dread_aura") { }

    class bfa_spell_manic_dread_aura_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_manic_dread_aura_SpellScript);

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> playerList;
            caster->GetPlayerListInGrid(playerList, 100.0f);
            playerList.remove_if(checkSpecsPlayers());

            if (playerList.size() >= (caster->GetMap()->IsMythic() ? 4 : 3))
                playerList.resize((caster->GetMap()->IsMythic() ? 4 : 3));

            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    player->AddAura(SPELL_MANIC_DREAD_AURA, player);
                }
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_manic_dread_aura_SpellScript::HandleAfterCast);
        }
    };

    class bfa_spell_manic_dread_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_manic_dread_aura_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* target = GetTarget()->ToPlayer();
            if (!target)
                return;

            if (mode == AURA_REMOVE_BY_ENEMY_SPELL || mode == AURA_REMOVE_BY_EXPIRE)
            {
                if (Creature* zaqul = target->FindNearestCreature(BOSS_ZAQUL, 200.0f, true))
                    zaqul->CastSpell(target, SPELL_MANIC_DREAD_MISSILE, true);
            }
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_manic_dread_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_FEAR_2, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_manic_dread_aura_AuraScript();
    }

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_manic_dread_aura_SpellScript();
    }
};

// 295999
class bfa_spell_caustic_delirium_aura : public SpellScriptLoader
{
public:
    bfa_spell_caustic_delirium_aura() : SpellScriptLoader("bfa_spell_caustic_delirium_aura") { }

    class bfa_spell_caustic_delirium_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_caustic_delirium_aura_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* target = GetTarget()->ToPlayer();
            if (!target)
                return;

            if (this->GetStackAmount() >= 5)
            {
                if (Unit* zaqul = target->FindNearestCreature(BOSS_ZAQUL, 200.0f, true))
                {
                    bfa_boss_zaqul::bfa_boss_zaqul_AI* ai = CAST_AI(bfa_boss_zaqul::bfa_boss_zaqul_AI, zaqul->GetAI());

                    ai->SetCustomPhase(target, 3, true);
                    this->Remove();
                    if (target->GetMap()->IsHeroic() || target->GetMap()->IsMythic())
                    {
                        for (uint8 i = 0; i < 3; ++i)
                        {
                            Position random = target->GetRandomPoint(centerPos, 20.0f);
                            if (Creature* tentacle = target->SummonCreature(NPC_TENTACLE_DELIRIUM, random, TEMPSUMMON_MANUAL_DESPAWN))
                            {
                                tentacle->SetInCombatWithZone();
                                ai->SetCustomPhase(tentacle, 3, true);
                            }
                        }
                    }
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_caustic_delirium_aura_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_caustic_delirium_aura_AuraScript();
    }
};

// 296078
class bfa_spell_dark_pulse_shield : public SpellScriptLoader
{
public:
    bfa_spell_dark_pulse_shield() : SpellScriptLoader("bfa_spell_dark_pulse_shield") { }

    class bfa_spell_dark_pulse_shield_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_dark_pulse_shield_AuraScript);

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_DARK_PULSE_CAST_DAMAGE);
        }

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (mode == AURA_REMOVE_BY_INTERRUPT)
            {
                caster->CastSpell(caster, SPELL_MIND_FRACTURE, true);
                caster->CastStop(SPELL_DARK_PULSE_CAST_DAMAGE);
            }
        }

        void CalculateAmount(AuraEffect const* auraEffect, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount += GetCaster()->CountPctFromMaxHealth(5);
        }

        void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            if (dmgInfo.GetDamage() >= absorbAmount)
                this->Remove(AURA_REMOVE_BY_INTERRUPT);
        }

        void Register()
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(bfa_spell_dark_pulse_shield_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(bfa_spell_dark_pulse_shield_AuraScript::OnAbsorb, EFFECT_0);
            OnEffectApply += AuraEffectApplyFn(bfa_spell_dark_pulse_shield_AuraScript::OnApply, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_dark_pulse_shield_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_dark_pulse_shield_AuraScript();
    }
};

class bfa_npc_tentacle_delirium : public CreatureScript
{
public:
    bfa_npc_tentacle_delirium() : CreatureScript("bfa_npc_tentacle_delirium") { }

    struct bfa_npc_tentacle_delirium_AI : public ScriptedAI
    {
        bfa_npc_tentacle_delirium_AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            events.Reset();
            me->SetObjectScale(0.1f);
        }

        void EnterCombat(Unit* target) //override
        {
            events.ScheduleEvent(EVENT_TENTACLE_SLAM, TIMER_TENTACLE_SLAM);
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
                case EVENT_TENTACLE_SLAM:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20.0f, true, 0))
                        me->CastSpell(target, SPELL_TENTACLE_SLAM);
                    events.ScheduleEvent(EVENT_TENTACLE_SLAM, TIMER_TENTACLE_SLAM);
                    break;
                }
            }
        }
    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_tentacle_delirium_AI(creature);
    }
};

// 301117
class bfa_spell_dark_shield : public SpellScriptLoader
{
public:
    bfa_spell_dark_shield() : SpellScriptLoader("bfa_spell_dark_shield") { }

    class bfa_spell_dark_shield_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_dark_shield_AuraScript);

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            PhasingHandler::AddPhase(caster, 2, false);
            caster->SummonCreature(NPC_ECHO_OF_FEAR, caster->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
            PhasingHandler::AddPhase(caster, 3, false);
            caster->SummonCreature(NPC_ECHO_OF_DELIRIUM, caster->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
            PhasingHandler::AddPhase(caster, 1, true);

            caster->CastSpell(caster, SPELL_PSYCHOTIC_SPLIT);
        }

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (mode == AURA_REMOVE_BY_INTERRUPT)
            {
                caster->CastSpell(caster, SPELL_MIND_FRACTURE, true);
                caster->CastStop(SPELL_PSYCHOTIC_SPLIT);
            }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_dark_shield_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DAMAGE_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_dark_shield_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DAMAGE_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_dark_shield_AuraScript();
    }
};

class bfa_npc_echo_of_fear : public CreatureScript
{
public:
    bfa_npc_echo_of_fear() : CreatureScript("bfa_npc_echo_of_fear")  { }

    struct bfa_npc_echo_of_fear_AI : public ScriptedAI
    {
        bfa_npc_echo_of_fear_AI(Creature* creature) : ScriptedAI(creature) { }

        bool _died;

        void Reset() override
        {
            events.Reset();
            _died = false;
        }

        Creature* GetZaqul()
        {
            return me->FindNearestCreature(BOSS_ZAQUL, 20.0f, true);
        }

        void DamageTaken(Unit* target, uint32& damage) override
        {
            if (damage >= me->GetHealth() && !_died)
            {
                _died = true;
                PhasingHandler::AddPhase(me, 1, false);
                if (Creature* zaqul = GetZaqul())
                {
                    CAST_AI(bfa_boss_zaqul::bfa_boss_zaqul_AI, zaqul->GetAI())->CheckEcho();
                    me->DespawnOrUnsummon(1 * IN_MILLISECONDS);
                }
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }
        }

        void EnterCombat(Unit* target) //override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.ScheduleEvent(EVENT_DREAD_SCREAM, TIMER_DREAD_SCREAM);
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
                case EVENT_DREAD_SCREAM:
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_DREAD_SCREAM);
                    events.ScheduleEvent(EVENT_DREAD_SCREAM, TIMER_DREAD_SCREAM);
                    break;
                }
            }
        }
    private:
        InstanceScript* instance;
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_echo_of_fear_AI(creature);
    }
};

class bfa_npc_echo_of_delirium : public CreatureScript
{
public:
    bfa_npc_echo_of_delirium() : CreatureScript("bfa_npc_echo_of_delirium") { }

    struct bfa_npc_echo_of_delirium_AI : public ScriptedAI
    {
        bfa_npc_echo_of_delirium_AI(Creature* creature) : ScriptedAI(creature) { }

        bool _died;

        void Reset() override
        {
            events.Reset();
            _died = false;
        }

        Creature* GetZaqul()
        {
            return me->FindNearestCreature(BOSS_ZAQUL, 20.0f, true);
        }

        void DamageTaken(Unit* target, uint32& damage) override
        {
            if (damage >= me->GetHealth() && !_died)
            {
                _died = true;
                PhasingHandler::AddPhase(me, 1, false);
                if (Creature* zaqul = GetZaqul())
                {
                    CAST_AI(bfa_boss_zaqul::bfa_boss_zaqul_AI, zaqul->GetAI())->CheckEcho();
                    me->DespawnOrUnsummon(1 * IN_MILLISECONDS);
                }
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }
        }

        void EnterCombat(Unit* target) //override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.ScheduleEvent(EVENT_VOID_SLAM, TIMER_VOID_SLAM);
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
                case EVENT_VOID_SLAM:
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_VOID_SLAM);
                    events.ScheduleEvent(EVENT_VOID_SLAM, TIMER_VOID_SLAM);
                    break;
                }
            }
        }
    private:
        InstanceScript* instance;
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_echo_of_delirium_AI(creature);
    }
};

class bfa_npc_horrific_summoner_dark_passage : public CreatureScript
{
public:
    bfa_npc_horrific_summoner_dark_passage() : CreatureScript("bfa_npc_horrific_summoner_dark_passage") { }

    struct bfa_npc_horrific_summoner_dark_passage_AI : public ScriptedAI
    {
        bfa_npc_horrific_summoner_dark_passage_AI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            creature->AddAura(SPELL_SHROUD_OF_FEAR, creature);
            PhasingHandler::AddPhase(creature, 2, true);
        }

        SummonList summons;

        void Reset() override
        {
            events.Reset();
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case NPC_FEAR_GATE:
                summon->AddUnitState(UNIT_STATE_ROOT);
                break;
            }
        }

        void EnterCombat(Unit* target) //override
        {
            events.ScheduleEvent(EVENT_FEAR_GATE, TIMER_FEAR_GATE);
        }

        void DamageTaken(Unit* target, uint32& damage) override
        {
            if (damage >= me->GetHealth())
                summons.DespawnAll();
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
                case EVENT_FEAR_GATE:
                    me->SummonCreature(NPC_FEAR_GATE, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
                    me->CastSpell(me, SPELL_FEAR_GATE_VISUAL_CAST);
                    break;
                }
            }
        }
    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_horrific_summoner_dark_passage_AI(creature);
    }
};

// 299617
class bfa_spell_fear_gate_cast : public SpellScriptLoader
{
public:
    bfa_spell_fear_gate_cast() : SpellScriptLoader("bfa_spell_fear_gate_cast") { }

    class bfa_spell_fear_gate_cast_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_fear_gate_cast_SpellScript);

        void HandleDummy()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            PhasingHandler::AddPhase(caster, 1, false);
            caster->CastSpell(caster, SPELL_VOID_ERUPTION, true);
            PhasingHandler::AddPhase(caster, 2, false);
            caster->CastSpell(caster, SPELL_VOID_ERUPTION, true);
            PhasingHandler::AddPhase(caster, 3, false);
            caster->CastSpell(caster, SPELL_VOID_ERUPTION, true);

            if (Creature* npc = caster->ToCreature())
                npc->DespawnOrUnsummon(2 * IN_MILLISECONDS);
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_fear_gate_cast_SpellScript::HandleDummy);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_fear_gate_cast_SpellScript();
    }
};

class bfa_npc_fear_gate : public CreatureScript
{
public:
    bfa_npc_fear_gate() : CreatureScript("bfa_npc_fear_gate") { }

    struct bfa_npc_fear_gate_AI : public ScriptedAI
    {
        bfa_npc_fear_gate_AI(Creature* creature) : ScriptedAI(creature) { }

        void UpdateAI(uint32 diff)
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 5.0f);
            if (playerList.size())
            {
                for (auto player : playerList)
                {
                    if (player->GetDistance(me) <= 3)
                    {
                        if (!player->HasAura(SPELL_FEAR_GATE_BUTTON))
                            player->AddAura(SPELL_FEAR_GATE_BUTTON, player);
                    }
                    else
                    {
                        if (player->HasAura(SPELL_FEAR_GATE_BUTTON))
                            player->RemoveAura(SPELL_FEAR_GATE_BUTTON);
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_fear_gate_AI(creature);
    }
};

// 301427
class bfa_spell_fear_gate_button : public SpellScriptLoader
{
public:
    bfa_spell_fear_gate_button() : SpellScriptLoader("bfa_spell_fear_gate_button") { }

    class bfa_spell_fear_gate_button_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_fear_gate_button_SpellScript);

        void HandleDummy()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_FEAR_GATE_BUTTON_TRIGGERED, true);
            caster->CastSpell(caster, SPELL_FEAR_GATE_MISC, true);
            if (Unit* zaqul = caster->FindNearestCreature(BOSS_ZAQUL, 200.0f, true))
            {
                bfa_boss_zaqul::bfa_boss_zaqul_AI* ai = CAST_AI(bfa_boss_zaqul::bfa_boss_zaqul_AI, zaqul->GetAI());

                ai->SetCustomPhase(caster, 1, true);
            }
            caster->RemoveAura(SPELL_FEAR_GATE_BUTTON);
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_fear_gate_button_SpellScript::HandleDummy);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_fear_gate_button_SpellScript();
    }
};

class bfa_npc_teleporter_queen_azshara : public CreatureScript
{
public:
    bfa_npc_teleporter_queen_azshara() : CreatureScript("bfa_npc_teleporter_queen_azshara") { }

    bool OnGossipHello(Player* player, Creature* me)
    {
        if (!me || !player)
            return false;

        player->NearTeleportTo(213.88f, 2405.74f, 710.81f, 0.0f, false);
        return true;
    }
};

// 295498
class bfa_spell_mind_tether_damage_share : public SpellScriptLoader
{
public:
    bfa_spell_mind_tether_damage_share() : SpellScriptLoader("bfa_spell_mind_tether_damage_share") { }

    class bfa_spell_mind_tether_damage_share_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_mind_tether_damage_share_AuraScript);

        void HandleOnProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            Unit* target = GetTarget()->ToPlayer();
            if (!target)
                return;

            uint32 sharedDamage = eventInfo.GetDamageInfo()->GetDamage();

            std::list<Player*> players;
            Map::PlayerList const& playerList = target->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    if (player->IsAlive() && player->HasAura(SPELL_MIND_TETHER_LINKAGE))
                        players.push_back(player);
            Player* validTarget = NULL;
            if (players.size())
            {
                for (auto initialPlayer : players)
                {
                    if (initialPlayer == target)
                        continue;
                    initialPlayer = validTarget;
                    break;
                }
            }
            if (validTarget)
            {
             //   CustomSpellValues values;
                //if (target->GetMap()->IsNormal())
                //    values.AddSpellMod(SPELLVALUE_BASE_POINT0, (sharedDamage / 2));
              //  else
               //     values.AddSpellMod(SPELLVALUE_BASE_POINT0, sharedDamage);

               // target->CastCustomSpell(SPELL_MIND_TETHER_LINKAGE_DAMAGE, values, validTarget, TRIGGERED_FULL_MASK);
            }
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(bfa_spell_mind_tether_damage_share_AuraScript::HandleOnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_mind_tether_damage_share_AuraScript();
    }
};

void AddSC_boss_zaqul()
{
    new bfa_boss_zaqul();
    RegisterCreatureAI(bfa_npc_crushing_grasp_trigger);
    new bfa_npc_first_arcanist_thalyssra();
    new bfa_npc_horrific_summoner();
    new bfa_npc_horrific_vision();
    new bfa_npc_maddening_eruption_trigger();
    new bfa_npc_tentacle_delirium();
    new bfa_npc_echo_of_delirium();
    new bfa_npc_echo_of_fear();
    new bfa_npc_horrific_summoner_dark_passage();
    new bfa_npc_fear_gate();
    new bfa_npc_teleporter_queen_azshara();
    new bfa_at_delirium_realm();
    new bfa_at_nightmare_pool();
    new bfa_at_reality_portal();
    new bfa_spell_caustic_delirium_aura();
    new bfa_spell_dark_shield();
    new bfa_spell_mind_tether_damage_share();
    new bfa_spell_fear_gate_button();
    new bfa_spell_fear_gate_cast();
    new bfa_spell_quivering_claws();
    new bfa_spell_crushing_grasp_cast();
    new bfa_spell_dark_pulse_shield();
    new bfa_spell_dark_tear_cast();
    new bfa_spell_delirium_realm_aura();
    new bfa_spell_delirium_realm_cast();
    new bfa_spell_dread_aura();
    new bfa_spell_fear_realm_cast();
    new bfa_spell_fear_realm_hysteria();
    new bfa_spell_manic_dread_aura();
    new bfa_spell_manic_dread_missile();
    new bfa_spell_mind_tether_aura();
    new bfa_spell_return_to_reality_button();
    new bfa_spell_mind_tether_cast();
}
