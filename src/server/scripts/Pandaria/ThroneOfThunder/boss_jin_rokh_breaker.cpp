#include "throne_of_thunder.h"
#include "GridNotifiers.h"
#include "DynamicObject.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum eSpells : uint32
{
    SPELL_CONDUCTIVE_WATER_SUMMON = 137145,
    SPELL_CONDUCTIVE_WATERFALL = 137340,
    SPELL_CONDUCTIVE_WATER_VISUAL = 137277, 
    SPELL_CONDUCTIVE_WATER_DUMMY = 137168,
    SPELL_CONDUCTIVE_WATER_GROW = 137694,
    SPELL_ELECTRIFY_WATERS = 138568,
    SPELL_ELECTRIFIED_WATER_VISUAL = 137978,

    SPELL_LIGHTNING_FISSURE_SUMMON = 137479,
    SPELL_LIGHTNING_FISSURE_VISUAL = 137480,
    SPELL_LIGHTNING_FISSURE_CONDUCTION = 138133,
    SPELL_LIGHTNING_FISSURE_AURA = 137484,

    SPELL_FOCUSED_LIGHTNING = 137399,
    //  SPELL_FOCUSED_LIGHTNING_VISUAL          = 137425,
    //  SPELL_FOCUSED_LIGHTNING_FIXATE          = 137422,
    SPELL_FOCUSED_LIGHTNING_SPEED = 137389,
    SPELL_FOCUSED_LIGHTNING_AOE = 137429,
    SPELL_FOCUSED_LIGHTNING_DETONATION = 137374,
    SPELL_VIOLENT_LIGHTNING_DETONATION = 138990,
    SPELL_FOCUSED_LIGHTNING_DAMAGE = 137423,
    SPELL_FOCUSED_LIGHTNING_TARGET = 137194,
    SPELL_FOCUSED_LIGHTNING_CONDUCTION = 137530,

    SPELL_IMPLOSION = 137507,

    SPELL_CONDUCTIVE_WATER_GROW_AURA = 137694,
    SPELL_CONDUCTIVE_WATERS = 138470,
    SPELL_ELECTRIFIED_WATERS = 138006,
    SPELL_FLUIDITY = 138002,

    SPELL_STATIC_BURST = 137162,
    SPELL_STATIC_WOUND = 138349,
    SPELL_STATIC_WOUND_DAMAGE = 138389,

    SPELL_LIGHTNING_STORM = 137313,
    SPELL_LIGHTNING_STORM_VISUAL = 138568,

    // Thundering Throw
    SPELL_THUNDERING_THROW = 137180, // Need SpellScript to handle ScriptEffect
    SPELL_THUNDERING_THROW_JUMP = 137173, // Casted by player on a statue
    SPELL_THUNDERING_THROW_SILENCE = 137161, // Silence, visuals
    SPELL_THUNDERING_THROW_FLY_VISUAL = 140594, // Visual in flight
    SPELL_THUNDERING_THROW_HIT_DAMAGE = 137370, // Damage on hit statue
    SPELL_THUNDERING_THROW_HIT_AOE_DAMAGE = 137167, // AOE Damage on hit statue
    SPELL_THUNDERING_THROW_STUN = 137371, // Stun after aoe damage on hit statue
    SPELL_THUNDERING_THROW_IMPACT_VISUAL = 140606, // Visual of the impact on ground

    // Heroic mode
    SPELL_LIGHTNING_STRIKE_DAMAGE = 137647, // used by diffuses & stalker
    SPELL_STORM_STALKER_SUMMON = 137283, // apply visual SPELL_LIGHTNING_STRIKE_VISUAL ( special ai )
    SPELL_LIGHTNING_STRIKE_DIFFUSE = 137966, // visual diffuses
    SPELL_LIGHTNING_STRIKE_VISUAL = 138299,

    SPELL_IONIZATION = 138732, // spellscript
    SPELL_IONIZATION_DAMAGE = 138733,
    SPELL_IONIZATION_CONDUCTION = 138743,
};

enum eCreatures : uint32
{
    NPC_LIGHTNING_FISSURE = 69609,
    NPC_CONDUCTIVE_WATER = 69469,
    NPC_FOCUSED_LIGHTNING = 69593,

    // Storm Stalkers
    NPC_STORM_MAIN_STALKER = 69676,
    NPC_STORM_EAST = 69713,
    NPC_STORM_WEST = 69715,
    NPC_STORM_NORTH = 69711,
    NPC_STORM_SOUTH = 69714,
};

enum iActions : int32
{
    ACTION_NONE,
    ACTION_DESTROYED,
    ACTION_RESET,
    ACTION_ELECTRIFY
};

static const float floorZ = 124.03f;

// added for general evets, it seems that all events are particularly added into main scripts, weird
enum HelperEvents
{
    EVENT_LIGHTNING_STRIKE_DAMAGE_PATH = 1,
    EVENT_HANDLE_SUMMON_AND_DAMAGE = 2,
};

enum eJDatas : uint32
{
    DATA_STATUE_DESTROYED,
};

class notInLosPredicate
{
public:
    notInLosPredicate(Unit* caster) : _caster(caster) {}
    bool operator()(WorldObject* target) const
    {
        return target && !target->IsWithinLOSInMap(_caster);
    }

private:
    Unit* _caster;
};

class validStatuePredicate
{
public:
    bool operator() (WorldObject* target) const
    {
        return target && target->ToPlayer() || ((target->ToCreature()->AI() && target->ToCreature()->AI()->GetData(DATA_STATUE_DESTROYED) == 1) || target->GetEntry() != NPC_JINROKH_STATUE);
    }
};

class electrifiedPredicate
{
public:
    bool operator()(Creature* target) const
    {
        return target && target->HasAura(SPELL_ELECTRIFIED_WATER_VISUAL);
    }
};

class scaleCheckPredicate
{
public:
    scaleCheckPredicate(Unit* caster) : _caster(caster) {}

    bool operator()(WorldObject* target) const
    {
        if (target && target->GetExactDist2d(_caster) > GetSizeProp(_caster))
            return true;
        return false;
    }
private:
    Unit* _caster;

    float GetSizeProp(Unit* propagator) const
    {
        if (Aura* pAura = propagator->GetAura(SPELL_CONDUCTIVE_WATER_GROW))
        {
            return ((float)0.4f * pAura->GetStackAmount());
        }

        return 0;
    }
};

class conductionPredicate
{
public:
    conductionPredicate(Creature* _waters) : waters(_waters) {}

    bool operator()(WorldObject* target) const
    {
        if (target && target->ToUnit())
        {
            if (target->ToUnit()->HasAura(SPELL_FLUIDITY, waters->GetGUID()))
                return false;
            if (target->ToUnit()->HasAura(SPELL_ELECTRIFIED_WATERS, waters->GetGUID()))
                return false;
        }

        return true;
    }
private:
    Creature* waters;
};

class notPlayerOrPetPredicate
{
public:
    bool operator()(WorldObject* target) const
    {
        return target && target->GetTypeId() != TYPEID_PLAYER;
    }
};

class focusedLightningPredicate
{
public:
    bool operator()(WorldObject* target) const
    {
        if (target)
        {
            if (target->ToCreature())
            {
                if (target->ToCreature()->GetEntry() != NPC_LIGHTNING_FISSURE)
                    return true;
                else
                    return false;
            }

            if (target->GetTypeId() == TYPEID_PLAYER)
                return false;

            return true;
        }
        return true;
    }
};

static const Position aWaterPos[4] =
{
    { 5864.490f, 6290.628f, 124.03f, 5.51f },
    { 5917.633f, 6289.476f, 124.03f, 3.93f },
    { 5918.487f, 6236.848f, 124.03f, 2.36f },
    { 5865.241f, 6236.743f, 128.03f, 0.77f }
};

static const Position aCenterPos = { 5892.16f, 6263.58f, 124.7f, 0.0f };

class FocusedLightningSelection : public std::unary_function<Unit*, bool>
{
public:
    FocusedLightningSelection() { }

    bool operator()(Unit const* pTarget) const
    {
        if (!pTarget->ToPlayer())
            return false;

        Player* pPlayer = const_cast<Player*>(pTarget->ToPlayer());

        switch (pPlayer->getClass())
        {
        case CLASS_WARRIOR:
        case CLASS_ROGUE:
        case CLASS_DEATH_KNIGHT:
            return false;

        case CLASS_PALADIN:
            return pPlayer->GetSpecializationId() == TALENT_SPEC_PALADIN_HOLY;

        case CLASS_DRUID:
            return pPlayer->GetSpecializationId() == TALENT_SPEC_DRUID_BALANCE || pPlayer->GetSpecializationId() == TALENT_SPEC_DRUID_RESTORATION;

        case CLASS_MONK:
            return pPlayer->GetSpecializationId() == TALENT_SPEC_MONK_MISTWEAVER;

        case CLASS_MAGE:
        case CLASS_PRIEST:
        case CLASS_WARLOCK:
        case CLASS_HUNTER:
            return true;

        default:
            return false;
        }
    }
};

class boss_jinrokh : public CreatureScript
{
public:
    boss_jinrokh() : CreatureScript("boss_jinrokh") {}

    enum eEvents : uint32
    {
        EVENT_NONE,
        EVENT_STATIC_BURST,
        EVENT_FOCUSED_LIGHTNING,
        EVENT_THUNDERING_THROW,
        EVENT_LIGHTNING_STORM,
        EVENT_IONIZATION,
        EVENT_BERSERK,
        EVENT_HEIGHT_CHECK,
        EVENT_PROPAGATE_STORM,
        EVENT_INTRO_YELL,
        EVENT_SUMMON_LIGHTNING_STRIKES,
        EVENT_CHECK_PLAYERS_DISTANCE,
    };

    enum eTalks : uint32
    {
        TALK_INTRO,
        TALK_AGGRO,
        TALK_STATIC_BURST,
        TALK_THUNDERING_THROW,
        TALK_LIGHTNING_STORM,
        TALK_FOCUSED_LIGHTNING,
        EMOTE_THUNDERING_THROW,
        EMOTE_LIGHTNING_STORM,
        EMOTE_LIGHTNING_STORM_2,
        TALK_SLAY,
        TALK_BERSERK,
        TALK_DEATH
    };

    struct boss_jinrokhAI : public BossAI
    {
        boss_jinrokhAI(Creature* pCreature) : BossAI(pCreature, DATA_JINROKH)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, 138006, true); // Electrified Waters
            me->ApplySpellImmune(0, IMMUNITY_ID, 138470, true); // Conductive Waters
            me->ApplySpellImmune(0, IMMUNITY_ID, 138002, true); // Fluidity
        }

        uint32 m_uiPushTimer;
        EventMap m_mEvents;
        void Reset()
        {
            events.Reset();
            summons.DespawnAll();
            ResetStatues();
            UnsummonFissure();
            instance->SetBossState(DATA_JINROKH, NOT_STARTED);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void EnterEvadeMode(EvadeReason why)
        {
            ClearCombatfromPlayers();
            MakeStatuesPassive();
        }

        void EnterCombat(Unit* pWho)
        {
            events.ScheduleEvent(EVENT_STATIC_BURST, 24000);
            events.ScheduleEvent(EVENT_CHECK_PLAYERS_DISTANCE, 500, 0, 0);
            events.ScheduleEvent(EVENT_FOCUSED_LIGHTNING, 10000);
            events.ScheduleEvent(EVENT_THUNDERING_THROW, 30000);
            events.ScheduleEvent(EVENT_LIGHTNING_STORM, 90000); // 1,5 minutes 90000
            if (me->GetMap()->IsHeroic())
                events.ScheduleEvent(EVENT_IONIZATION, 60000, 0, 0);
            events.ScheduleEvent(EVENT_BERSERK, 7 * MINUTE * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_HEIGHT_CHECK, 2000);

            instance->SetBossState(DATA_JINROKH, IN_PROGRESS);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            me->SetInCombatWithZone(); // just checks
            Talk(TALK_AGGRO);

        }

        void JustSummoned(Creature* pSummoned)
        {
            summons.Summon(pSummoned);
        }

        void SummonedCreatureDespawn(Creature* pSummoned)
        {
            summons.Despawn(pSummoned);
        }

        void CheckHeight()
        {
            if (me->GetPositionZ() > floorZ + 3.5f || me->GetPositionZ() < floorZ - 1.2f)
                me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), floorZ + 0.2f, me->GetOrientation());

            events.ScheduleEvent(EVENT_HEIGHT_CHECK, 2000);
        }

        void DoCastBossSpell(Unit* target, uint32 spellId, bool trig, uint32 push = 0)
        {
            DoCast(target, spellId, trig);

            if (push)
                m_uiPushTimer = push;
        }

        void UnsummonFissure()
        {
            std::list<Creature*> cList;
            me->GetCreatureListWithEntryInGrid(cList, NPC_LIGHTNING_FISSURE, 500.0f);
            if (!cList.empty())
                for (std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();
        }

        void MakeStatuesPassive()
        {
            std::list<Creature*> cList;
            me->GetCreatureListWithEntryInGrid(cList, NPC_JINROKH_STATUE, 500.0f);
            if (!cList.empty())
                for (std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                {
                    (*itr)->ClearInCombat();
                    (*itr)->CombatStop();
                    (*itr)->SetReactState(REACT_PASSIVE);
                }
        }

        void ClearCombatfromPlayers()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->CombatStop(false);
                }
        }

        void JustDied(Unit* pKiller)
        {
            _JustDied();
            UnsummonFissure();
            Talk(TALK_DEATH);
            instance->SetBossState(DATA_JINROKH, DONE);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

            ResetStatues();
            MakeStatuesPassive();
            ClearCombatfromPlayers();
          
        }

        void KilledUnit(Unit* pVictim) override
        {
            Talk(TALK_SLAY);
        }

        void DoAction(int32 iAction) override
        {
            if (iAction == ACTION_START_INTRO)
            {
                if (Aura* pVisual = me->AddAura(SPELL_LIGHTNING_STORM_VISUAL, me))
                    pVisual->SetDuration(15000);

                m_mEvents.ScheduleEvent(EVENT_INTRO_YELL, 15000);
            }
        }

        void ResetStatues()
        {
            std::list<Creature*> pStatues;
            GetCreatureListWithEntryInGrid(pStatues, me, NPC_JINROKH_STATUE, 200.f);

            for (auto const pCreature : pStatues)
            {
                if (pCreature->AI())
                    pCreature->AI()->DoAction(ACTION_RESET);
            }
        }

        void SpellHitTarget(Unit* pHit, const SpellInfo* pSpellInfo) override
        {
            if (pHit)
            {
                if (pSpellInfo->Id == SPELL_THUNDERING_THROW)
                {
                    if (me->getThreatManager().getThreat(pHit))
                        me->getThreatManager().modifyThreatPercent(pHit, -100);
                }
            }
        }

        void DoHandleLightningStorm()
        {
            std::list<Creature*>pWaters;
            GetCreatureListWithEntryInGrid(pWaters, me, NPC_CONDUCTIVE_WATER, 200.f);

            pWaters.remove_if(electrifiedPredicate());

            for (Creature* pWater : pWaters)
            {
                if (pWater->AI())
                    pWater->AI()->DoAction(ACTION_ELECTRIFY);
            }
        }

        void MovementInform(uint32 uiType, uint32 uiPointId)
        {
            if (uiPointId == 1948)
            {
                me->NearTeleportTo(aCenterPos.GetPositionX(), aCenterPos.GetPositionY(), aCenterPos.GetPositionZ(), aCenterPos.GetOrientation());
                me->AddUnitState(UNIT_STATE_ROOT);

                DoHandleLightningStorm();

                events.ScheduleEvent(EVENT_PROPAGATE_STORM, 800);

                me->UpdateObjectVisibility();
            }
        }

        void PropagateStorm()
        {
            me->ClearUnitState(UNIT_STATE_ROOT);

            Talk(TALK_LIGHTNING_STORM);
            Talk(EMOTE_LIGHTNING_STORM);

            //DoCastBossSpell(me->GetVictim(), SPELL_LIGHTNING_STORM, false, 3000);
            DoCast(SPELL_LIGHTNING_STORM);
            if (Aura* pAura = me->AddAura(SPELL_LIGHTNING_STORM_VISUAL, me))
                pAura->SetDuration(15000);
        }

        void CheckDistancePlayers() // anti hacks
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            if (!playerList.isEmpty())
                for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                    if (Player* player = itr->GetSource())
                        if (!player->IsGameMaster())
                            if (player->GetDistance2d(aCenterPos.m_positionX, aCenterPos.m_positionY) > 75.0f)
                            {
                                me->Kill(player, true);
                                break;
                            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            
            m_mEvents.Update(uiDiff);

            switch (m_mEvents.ExecuteEvent())
            {
            case EVENT_INTRO_YELL:
                Talk(TALK_INTRO);
                me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                break;
            }

            if (!UpdateVictim())
                return;

            events.Update(uiDiff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_STATIC_BURST:
                    Talk(TALK_STATIC_BURST);
                    DoCastBossSpell(me->GetVictim(), SPELL_STATIC_BURST, false, 1000);
                    events.ScheduleEvent(EVENT_STATIC_BURST, 26000);
                    break;
                case EVENT_FOCUSED_LIGHTNING:
                    Talk(TALK_FOCUSED_LIGHTNING);
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        me->CastSpell(pTarget, SPELL_FOCUSED_LIGHTNING);
                    events.ScheduleEvent(EVENT_FOCUSED_LIGHTNING, urand(12000, 15000));
                    break;
                case EVENT_LIGHTNING_STORM:
                    me->GetMotionMaster()->MoveJump(aCenterPos, 35.f, 35.f, 1948);
                    events.ScheduleEvent(EVENT_LIGHTNING_STORM, 90000);
                    events.ScheduleEvent(EVENT_THUNDERING_THROW, 30000);
                    break;
                case EVENT_PROPAGATE_STORM:
                    PropagateStorm();
                    events.DelayEvents(15000);
                    break;
                case EVENT_THUNDERING_THROW:
                    DoCast(me->GetVictim(), SPELL_THUNDERING_THROW);
                    Talk(TALK_THUNDERING_THROW);
                    Talk(EMOTE_THUNDERING_THROW, me->GetVictim());
                    break;
                case EVENT_BERSERK:
                    Talk(TALK_BERSERK);
                    DoCast(me, SPELL_BERSERK, true);
                    break;
                case EVENT_HEIGHT_CHECK:
                    CheckHeight();
                    break;
                case EVENT_IONIZATION:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                    {
                        if (Player* player = itr->GetSource())
                        {
                            me->AddAura(SPELL_IONIZATION, player);
                        }
                    }
                    events.ScheduleEvent(EVENT_IONIZATION, 90000);
                    break;
                }
                case EVENT_CHECK_PLAYERS_DISTANCE:
                    CheckDistancePlayers();
                    events.ScheduleEvent(EVENT_CHECK_PLAYERS_DISTANCE, 500);
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_jinrokhAI(pCreature);
    }
};

class npc_focused_lightning : public CreatureScript
{
    enum eEvents : uint32
    {
        EVENT_NONE,
        EVENT_FISSURE_CHECK,
        EVENT_FOCUSATE_DETONATION,
        EVENT_FIXATE_PLAYER,
        EVENT_MOVE_TO_PLAYERS,
        EVENT_INIT_FOCUED_SCRIPT,
    };

public:
    npc_focused_lightning() : CreatureScript("npc_focused_lightning") {}

    struct npc_focused_lightningAI : public ScriptedAI
    {
        npc_focused_lightningAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            //Initialize();
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetObjectScale(0.3f);
            me->AddAura(SPELL_FOCUSED_LIGHTNING_VISUAL, me);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_THREAT, true);
        }

        uint64 playerGuid;
        EventMap events;

        void Reset()
        {
            events.Reset();
            playerGuid = 0;
        }

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_INIT_FOCUED_SCRIPT, 2500, 0, 0);
            events.ScheduleEvent(EVENT_FIXATE_PLAYER, 1500, 0, 0);
            DoCast(SPELL_FOCUSED_LIGHTNING_TARGET);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->AddAura(42716, me); // root aura
        }

        // NOT USED TOO, OMG SO FUCKING USELESS, i'm doing it by my own style
        /*void Initialize()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            m_mEvents.ScheduleEvent(EVENT_FISSURE_CHECK, 1000);
            me->AddAura(SPELL_FOCUSED_LIGHTNING_VISUAL, me);
            me->AddAura(SPELL_FOCUSED_LIGHTNING_SPEED, me);

            DoCast(SPELL_FOCUSED_LIGHTNING_TARGET);
        }

        // Not used RAGELESS
        void CheckHeight()
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE))
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);

            if (me->GetPositionZ() > floorZ + 3.5f || me->GetPositionZ() < floorZ - 1.2f)
                me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), floorZ + 0.2f, me->GetOrientation());
        }*/

        /*void GetFixatedPlayerOrGetNewIfNeeded()
        {
            std::list<Player*> players;
            GetPlayerListInGrid(players, me, 200.f);

            if (players.empty())
            {
                TC_LOG_ERROR("scripts", "Focused Lightning guid %u found no players in instance %u, possible exploit", me->GetGUIDLow(), me->GetMap()->GetInstanceId());
                return;
            }

            for (Player* pPlayer : players)
            {
                if (pPlayer->HasAura(SPELL_FOCUSED_LIGHTNING_FIXATE, me->GetGUID()))
                {
                    m_targetGuid = pPlayer->GetGUID();
                    Talk(0, pPlayer);
                    return;
                }
            }

            if (Player* pPlayer = Trinity::Containers::SelectRandomContainerElement(players))
            {
                me->CastSpell(pPlayer, SPELL_FOCUSED_LIGHTNING_FIXATE, true);
                m_targetGuid = pPlayer->GetGUID();
                Talk(0, pPlayer);
            }
        }*/

        void UpdateAI(uint32 uiDiff)
        {
            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_INIT_FOCUED_SCRIPT:
                    me->SetObjectScale(1.0f);
                    break;
                case EVENT_FIXATE_PLAYER:
                {
                    me->RemoveAura(42716); // root aura
                    me->AddUnitState(UNIT_STATE_ROOT);
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    {
                        me->AddAura(SPELL_FOCUSED_LIGHTNING_SPEED, me);
                        me->AI()->AttackStart((*itr));
                        me->AddThreat((*itr), 99999999.9f);
                        me->AddAura(137422, (*itr));
                        events.ScheduleEvent(EVENT_MOVE_TO_PLAYERS, 1000, 0, 0);
                        break;
                    }
                }
                case EVENT_MOVE_TO_PLAYERS:
                {
                    if (Unit* target = me->GetVictim())
                    {
                        //me->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);

                        if (!target || target->isDead())
                            me->DespawnOrUnsummon();

                        if (me->GetDistance(target) < 2.0f)
                        {
                            if (!target->HasAura(SPELL_FLUIDITY) || !target->HasAura(SPELL_ELECTRIFIED_WATERS))
                                me->CastSpell(target, SPELL_FOCUSED_LIGHTNING_DETONATION, true);
                            else if (target->HasAura(SPELL_FLUIDITY) || target->HasAura(SPELL_ELECTRIFIED_WATERS))
                                target->CastSpell(target, SPELL_FOCUSED_LIGHTNING_CONDUCTION, true);
                            me->SummonCreature(NPC_LIGHTNING_FISSURE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                            target->RemoveAurasDueToSpell(137422);
                            
                            me->Kill(me);
                            me->DespawnOrUnsummon(100);
                        }
                        events.ScheduleEvent(EVENT_MOVE_TO_PLAYERS, 1000, 0, 0);
                        break;
                    }
                }
                // ## old script
                /*case EVENT_FISSURE_CHECK:
                    CheckHeight();
                    if (Unit* pTarget = ObjectAccessor::GetPlayer(*me, m_targetGuid))
                    {
                    me->GetMotionMaster()->MoveFollow(pTarget, 0.f, 0.f);
                    }
                    else
                    {
                    GetFixatedPlayerOrGetNewIfNeeded();
                    me->GetMotionMaster()->MoveFollow(pTarget, 0.f, 0.f);
                    }
                    m_mEvents.ScheduleEvent(EVENT_FISSURE_CHECK, 400);
                    m_mEvents.ScheduleEvent(EVENT_FOCUSATE_DETONATION, 500, 0, 0);
                    break;
                    case EVENT_FOCUSATE_DETONATION:
                    {
                    Unit* target = me->GetVictim();
                    if (!target)
                    return;

                    // detonation
                    if (target->GetDistance(me) < 2.0f)
                    {
                    DoCast(SPELL_FOCUSED_LIGHTNING_DETONATION);
                    me->DespawnOrUnsummon(100);
                    me->Kill(me);
                    }
                    m_mEvents.ScheduleEvent(EVENT_FOCUSATE_DETONATION, 500, 0, 0);
                    break;
                    }*/
                }
            }
        }

    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_focused_lightningAI(pCreature);
    }

};

class npc_lightning_fissure : public CreatureScript
{
public:
    npc_lightning_fissure() : CreatureScript("npc_lightning_fissure") {}

    struct npc_lightning_fissureAI : public ScriptedAI
    {
        npc_lightning_fissureAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            Initialize();
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetReactState(REACT_PASSIVE);
        }

        EventMap m_mEvents;
        uint32 fissureAura;

        void Initialize()
        {
            me->AddAura(SPELL_LIGHTNING_FISSURE_VISUAL, me);
            //me->AddAura(SPELL_LIGHTNING_FISSURE_AURA, me);
            fissureAura = 1000;
            m_mEvents.ScheduleEvent(1, 500);
        }

        void Reset()
        {
            fissureAura = 1000;
        }

        float GetSizeProp(Unit* propagator) const
        {
            if (Aura* pAura = propagator->GetAura(SPELL_CONDUCTIVE_WATER_GROW))
            {
                return ((float)0.4f * pAura->GetStackAmount());
            }

            return 0;
        }

        void DoCheckFissure()
        {
            if (Creature* pWaters = GetClosestCreatureWithEntry(me, NPC_CONDUCTIVE_WATER, 100.f))
            {
                if (me->GetExactDist2d(pWaters) < GetSizeProp(pWaters))
                {
                    DoCast(me, SPELL_LIGHTNING_FISSURE_CONDUCTION, true);
                    me->DespawnOrUnsummon();
                    return;
                }
            }

            m_mEvents.ScheduleEvent(1, 500);
        }

        void UpdateAI(uint32 uiDiff)
        {
            m_mEvents.Update(uiDiff);

            if (fissureAura <= uiDiff)
            {
                me->AddAura(SPELL_LIGHTNING_FISSURE_AURA, me);
                fissureAura = 3000;
            }
            else fissureAura -= uiDiff;

            switch (m_mEvents.ExecuteEvent())
            {
            case 1:
                DoCheckFissure();
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lightning_fissureAI(pCreature);
    }
};

class spell_focused_lightning_targeting : public SpellScriptLoader
{
public:
    spell_focused_lightning_targeting() : SpellScriptLoader("spell_focused_lightning_targeting") {}

    class spell_focused_lightning_targeting_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_focused_lightning_targeting_SpellScript);

        /*void SelectTargets(std::list<WorldObject*>&targets)
        {
            /*if (GetCaster())
            {
                targets.remove_if(notPlayerPredicate());
                targets.remove_if(notInLosPredicate(GetCaster()));

                if (targets.size() > 1)
                {
                    Trinity::Containers::RandomResizeList(targets, 1);
                }
            }
        }*/

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();

            if (!caster || targets.empty())
                return;

            // Remove specific specs
            for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
            {
                if (Player* player = (*itr)->ToPlayer())
                {
                    // Check specs
                    uint32 spec = player->GetSpecializationId();
                    bool checkSpec = false;

                    switch (spec)
                    {
                    case TALENT_SPEC_DRUID_BEAR:
                    case TALENT_SPEC_DRUID_CAT:
                    case TALENT_SPEC_WARRIOR_FURY:
                    case TALENT_SPEC_WARRIOR_ARMS:
                    case TALENT_SPEC_PALADIN_PROTECTION:
                    case TALENT_SPEC_PALADIN_RETRIBUTION:
                    case TALENT_SPEC_WARRIOR_PROTECTION:
                    case TALENT_SPEC_DEATHKNIGHT_UNHOLY:
                    case TALENT_SPEC_DEATHKNIGHT_FROST:
                    case TALENT_SPEC_DEATHKNIGHT_BLOOD:
                    case TALENT_SPEC_ROGUE_SUBTLETY:
                    case TALENT_SPEC_ROGUE_COMBAT:
                    case TALENT_SPEC_ROGUE_ASSASSINATION:
                    case TALENT_SPEC_HUNTER_MARKSMAN:
                    case TALENT_SPEC_HUNTER_SURVIVAL:
                    case TALENT_SPEC_HUNTER_BEASTMASTER:
                    case TALENT_SPEC_MONK_BREWMASTER:
                    case TALENT_SPEC_MONK_BATTLEDANCER:
                    case TALENT_SPEC_SHAMAN_ENHANCEMENT:
                        checkSpec = true;
                        break;
                    }

                    if (checkSpec)
                    {
                        targets.erase(itr++);
                        continue;
                    }
                }
                ++itr;
            }
        }

        void HandleHit()
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_FOCUSED_LIGHTNING_FIXATE, true);

            if (caster->ToCreature() && caster->ToCreature()->AI())
            {
                caster->ToCreature()->AI()->Talk(0, target);
                caster->ToCreature()->AI()->SetGUID(target->GetGUID());
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_focused_lightning_targeting_SpellScript::HandleHit);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_focused_lightning_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_focused_lightning_targeting_SpellScript();
    }
};

class spell_focused_lightning_aoe : public SpellScriptLoader
{
public:
    spell_focused_lightning_aoe() : SpellScriptLoader("spell_focused_lightning_aoe") {}

    class spell_focused_lightning_aoe_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_focused_lightning_aoe_SpellScript);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(focusedLightningPredicate());
        }

        void HandleEffectHitTarget(SpellEffIndex eff_idx)
        {
            if (Unit* pCaster = GetCaster())
            {
                if (Creature* pLightningFissure = GetHitCreature())
                {
                    if (!pLightningFissure->HasAura(SPELL_LIGHTNING_FISSURE_AURA))
                        return;

                    // implosion
                    pLightningFissure->DisappearAndDie();
                    pCaster->CastSpell(pCaster, SPELL_IMPLOSION, true);
                    pCaster->Kill(pCaster);
                    return;
                }

                if (Unit* pUnit = GetHitUnit())
                {
                    // Should we detonate?
                    // if (pUnit->HasAura(SPELL_FOCUSED_LIGHTNING_FIXATE, pCaster->GetGUID()))
                    //{
                    /*bool violent = false;
                    bool should_conduct = false;

                    if (pUnit->HasAura(SPELL_FLUIDITY))
                    {
                        pUnit->CastSpell(pUnit, SPELL_FOCUSED_LIGHTNING_CONDUCTION, true, 0, 0, pCaster->GetGUID());
                        should_conduct = true;
                    }
                    else if (pUnit->HasAura(SPELL_ELECTRIFIED_WATERS))
                    {
                        pUnit->CastSpell(pUnit, SPELL_FOCUSED_LIGHTNING_CONDUCTION, true, 0, 0, pCaster->GetGUID());
                        violent = true;
                        should_conduct = true;
                    }

                    // already handled in npc events
                    //pCaster->CastSpell(pUnit, violent ? SPELL_VIOLENT_LIGHTNING_DETONATION : SPELL_FOCUSED_LIGHTNING_DETONATION, true);

                    /*if (!should_conduct) removed because we will handle it manually not via a spellscript
                    {
                        pCaster->SummonCreature(NPC_LIGHTNING_FISSURE, pCaster->GetPositionX(), pCaster->GetPositionY(), pCaster->GetPositionZ(), pCaster->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                    }*/
                    //  }

                    pCaster->CastSpell(pUnit, SPELL_FOCUSED_LIGHTNING_DAMAGE, true);
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_focused_lightning_aoe_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_focused_lightning_aoe_SpellScript::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_focused_lightning_aoe_SpellScript();
    }
};

class spell_focused_lightning_speed : public SpellScriptLoader
{
public:
    spell_focused_lightning_speed() : SpellScriptLoader("spell_focused_lightning_speed") {}

    class spell_focused_lightning_speed_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_focused_lightning_speed_AuraScript);

        void HandleOnPeriodic(AuraEffect const* aurEff)
        {
            if (WorldObject* pOwner = GetOwner())
            {
                if (pOwner->ToUnit())
                {
                    pOwner->ToUnit()->CastSpell(pOwner->ToUnit(), SPELL_FOCUSED_LIGHTNING_AOE, true);
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_focused_lightning_speed_AuraScript::HandleOnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_focused_lightning_speed_AuraScript();
    }
};

class spell_focused_lightning_detonation : public SpellScriptLoader
{
public:
    spell_focused_lightning_detonation() : SpellScriptLoader("spell_focused_lightning_detonation") {}

    class spell_focused_lightning_detonation_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_focused_lightning_detonation_SpellScript);

        void HandleAfterHit()
        {
            if (GetCaster())
                GetCaster()->UpdateObjectVisibility();
        }

        void Register()
        {
            AfterHit += SpellHitFn(spell_focused_lightning_detonation_SpellScript::HandleAfterHit);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new spell_focused_lightning_detonation_SpellScript();
    }
};

class spell_implosion : public SpellScriptLoader
{
public:
    spell_implosion() : SpellScriptLoader("spell_implosion") {}

    class spell_implosion_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_implosion_SpellScript)

            void SelectTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(notPlayerPredicate());
        }

        void HandleAfterHit()
        {
            if (GetCaster())
                GetCaster()->Kill(GetCaster());
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_implosion_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_implosion_SpellScript::SelectTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
            AfterHit += SpellHitFn(spell_implosion_SpellScript::HandleAfterHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_implosion_SpellScript();
    }
};

class spell_static_wound : public SpellScriptLoader
{
public:
    spell_static_wound() : SpellScriptLoader("spell_static_wound") {}

    class spell_static_wound_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_static_wound_AuraScript);

            bool Load()
        {
            m_timer = 3000;
            return true;
        }

        uint32 m_timer;

        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Aura* pAura = GetAura())
                pAura->SetStackAmount(10);
        }

        void HandleOnReApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Aura* pAura = GetAura())
                pAura->SetStackAmount(pAura->GetStackAmount() + 10 > 30 ? 30 : pAura->GetStackAmount() + 10);
        }

        void HandleOnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            uint32 m_stacks = GetAura()->GetStackAmount();
        }

        void HandleOnUpdate(AuraEffect const* aurEff)
        {
            // Static Wound already has 0 to 3 seconds periodic dummy script so we just remove the old script and leave -1 stacks every 3s
            ModStackAmount(-1);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_static_wound_AuraScript::HandleOnProc, EFFECT_0, SPELL_AURA_DUMMY);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_static_wound_AuraScript::HandleOnUpdate, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY); //@ RAGELESS FIXME -> periodic dummy dbc spellfix

            //OnEffectApply += AuraEffectApplyFn(spell_static_wound_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            //OnEffectApply += AuraEffectApplyFn(spell_static_wound_AuraScript::HandleOnReApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAPPLY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_static_wound_AuraScript();
    }
};

class spell_static_wound_damage : public SpellScriptLoader
{
public:
    spell_static_wound_damage() : SpellScriptLoader("spell_static_wound_damage") {}

    class spell_static_wound_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_static_wound_damage_SpellScript);

        void HandleEffectHitTarget(SpellEffIndex eff_idx)
        {
            Unit* target = GetHitUnit();
            Unit* caster = GetCaster();

            Map::PlayerList const& playerList = caster->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player == caster) // if target if caster, don't damage him
                        continue;

                    if (player == target) // if target is another player(s) , damage them for 3%
                        SetHitDamage(CalculatePct(GetHitDamage(), 33));
                }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_static_wound_damage_SpellScript::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_static_wound_damage_SpellScript();
    }
};

class spell_static_burst : public SpellScriptLoader
{
public:
    spell_static_burst() : SpellScriptLoader("spell_static_burst") {}

    class spell_static_burst_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_static_burst_AuraScript);

        void HandleOnPeriodic(AuraEffect const* aurEff)
        {
            if (Unit* pUnit = GetOwner()->ToUnit())
            {
                if (Aura* pAura = pUnit->GetAura(SPELL_STATIC_WOUND))
                {
                    pAura->ModStackAmount(pAura->GetStackAmount() + 10 < 30 ? (pAura->GetStackAmount() + 10) : 30);
                    pAura->SetDuration(25000);
                }
                else if (Aura* pAura = pUnit->AddAura(SPELL_STATIC_WOUND, pUnit))
                    pAura->SetStackAmount(10);
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_static_burst_AuraScript::HandleOnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_static_burst_AuraScript();
    }
};

class spell_lightning_storm_visual : public SpellScriptLoader
{
public:
    spell_lightning_storm_visual() : SpellScriptLoader("spell_lightning_storm_visual") {}

    class spell_lightning_storm_visual_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_lightning_storm_visual_AuraScript);

        void OnAuraEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (GetCaster())
            {
                if (GetCaster()->HasAura(SPELL_LIGHTNING_STORM))
                    SetDuration(15000);
            }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_lightning_storm_visual_AuraScript::OnAuraEffectApply, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_lightning_storm_visual_AuraScript();
    }
};

class spell_thundering_throw_silence : public SpellScriptLoader
{
public:
    spell_thundering_throw_silence() : SpellScriptLoader("spell_thundering_throw_silence") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(validStatuePredicate());

            if (targets.size() > 1)
            {
                if (GetCaster())
                    targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));

                //if (WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets))
                {
                    //targets.emplace(targets.begin(), target);
                    targets.resize(1);
                }
            }
        }

        void HandleOnEffectHit(SpellEffIndex effIdx)
        {
            Unit* caster = GetCaster();
            Creature* target = GetHitCreature();

            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_THUNDERING_THROW_JUMP, true);

            if (target->AI())
            {
                target->AI()->DoAction(ACTION_DESTROYED);
                target->AI()->SetGUID(caster->GetGUID());
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_impl::HandleOnEffectHit, EFFECT_4, SPELL_EFFECT_DUMMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_impl::SelectTargets, EFFECT_4, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

class spell_thundering_throw_damage : public SpellScriptLoader
{
public:
    spell_thundering_throw_damage() : SpellScriptLoader("spell_thundering_throw_damage") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void HandleOnEffectHit(SpellEffIndex effIdx)
        {
            if (Unit* pUnit = GetHitUnit())
                pUnit->CastSpell(pUnit, SPELL_THUNDERING_THROW_STUN, true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_impl::HandleOnEffectHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

class spell_thundering_throw : public SpellScriptLoader
{
public:
    spell_thundering_throw() : SpellScriptLoader("spell_thundering_throw") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void HandleOnHit()
        {
            if (Unit* pUnit = GetHitUnit())
                pUnit->CastSpell(pUnit, SPELL_THUNDERING_THROW_SILENCE);
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_impl::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

static uint32 max_casts = 66;

class npc_jinrokh_statue : public CreatureScript
{
    enum eEvents
    {
        EVENT_NONE,
        EVENT_WATER_BEAM,
        EVENT_SPAWN_WATER,
    };

public:
    npc_jinrokh_statue() : CreatureScript("npc_jinrokh_statue") {}

    struct npc_jinrokh_statueAI : public ScriptedAI
    {
        npc_jinrokh_statueAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
        }

        void DoAction(int32 iAction) override
        {
            if (iAction == ACTION_DESTROYED)
            {
 
                events.ScheduleEvent(EVENT_WATER_BEAM, 4000);
                events.ScheduleEvent(EVENT_SPAWN_WATER, 7000);
                SetData(DATA_STATUE_DESTROYED, 1);
            }

            if (iAction == ACTION_RESET)
            {
 
                me->SetVisible(false);
                me->SetVisible(true);
                me->UpdateObjectVisibility();
                me->RemoveAllAuras();
                events.Reset();
                SetData(DATA_STATUE_DESTROYED, 0);

                if (Creature* pWaters = GetClosestCreatureWithEntry(me, NPC_CONDUCTIVE_WATER, 100.f))
                    pWaters->DespawnOrUnsummon();
            }
        }

        Position DoSpawnWater()
        {
            uint8 dist = 0;
            float i_range = 1000.f;

            for (uint8 i = 0; i < 4; ++i)
            {
                float new_dist = me->GetDistance(aWaterPos[i]);

                if (new_dist < i_range)
                {
                    dist = i;
                    i_range = new_dist;
                }
            }

            return aWaterPos[dist];
        }

        void DoTossPlayer(Player* pPlayer)
        {

            Position pos = DoSpawnWater();
            pPlayer->CastSpell(pos.m_positionX, pos.m_positionY, pos.m_positionZ, SPELL_THUNDERING_THROW_JUMP, true);
            pPlayer->CastSpell(pPlayer, SPELL_THUNDERING_THROW_HIT_DAMAGE, true);
        }
        void DoStunPlayer(Player* pPlayer)
        {
            pPlayer->CastSpell(pPlayer, SPELL_THUNDERING_THROW_HIT_AOE_DAMAGE, true);
            pPlayer->CastSpell(pPlayer, SPELL_THUNDERING_THROW_STUN, true);
            pPlayer->RemoveAurasDueToSpell(SPELL_THUNDERING_THROW_SILENCE);

 
        }

        void UpdateAI(uint32 uiDiff)
        {
            events.Update(uiDiff);

            switch (events.ExecuteEvent())
            {
            case EVENT_WATER_BEAM:
                me->AddAura(SPELL_CONDUCTIVE_WATERFALL, me);
                break;
            case EVENT_SPAWN_WATER:
                if (Creature* pWater = me->SummonCreature(NPC_CONDUCTIVE_WATER, DoSpawnWater()))
                {
                    if (pWater->AI())
                        pWater->AI()->DoAction(ACTION_RESET);
                }
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_jinrokh_statueAI(pCreature);
    }
};

class npc_conductive_water : public CreatureScript
{
    enum eEvents
    {
        EVENT_NONE,
        EVENT_GROW,
        EVENT_ELECTRIFY,
        EVENT_FINALIZE_ELECTRIFY
    };

public:
    npc_conductive_water() : CreatureScript("npc_conductive_water") {}

    struct npc_conductive_waterAI : public ScriptedAI
    {
        npc_conductive_waterAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        uint32 m_size;
        EventMap events;

        void DoAction(int32 iAction) override
        {
            if (iAction == ACTION_RESET)
            {
                m_size = 0;
                me->AddAura(SPELL_CONDUCTIVE_WATER_VISUAL, me);
                events.ScheduleEvent(EVENT_GROW, 500);
            }

            if (iAction == ACTION_ELECTRIFY)
            {
                events.ScheduleEvent(EVENT_ELECTRIFY, 5000);
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            events.Update(uiDiff);

            switch (events.ExecuteEvent())
            {
            case EVENT_GROW:
                events.ScheduleEvent(EVENT_GROW, 500);
                if (m_size < max_casts)
                {
                    DoCast(me, SPELL_CONDUCTIVE_WATER_GROW, true);
                    ++m_size;
                }
                DoCast(me, SPELL_CONDUCTIVE_WATER_DUMMY, true);
                break;
            case EVENT_ELECTRIFY:
                events.ScheduleEvent(EVENT_FINALIZE_ELECTRIFY, 1500);
                me->AddAura(SPELL_ELECTRIFY_WATERS, me);
                break;
            case EVENT_FINALIZE_ELECTRIFY:
                me->AddAura(SPELL_ELECTRIFIED_WATER_VISUAL, me);
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_conductive_waterAI(pCreature);
    }
};

class spell_conductive_water_dummy : public SpellScriptLoader
{
public:
    spell_conductive_water_dummy() : SpellScriptLoader("spell_conductive_water_dummy") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            if (Unit* caster = GetCaster())
            {
                //targets.remove_if(notPlayerOrPetPredicate());
                targets.remove_if(scaleCheckPredicate(caster));
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_impl::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    class aura_impl : public AuraScript
    {
        PrepareAuraScript(aura_impl);

        float GetSizeProp(Unit* propagator) const
        {
            if (Aura* pAura = propagator->GetAura(SPELL_CONDUCTIVE_WATER_GROW))
            {
                return ((float)0.4f * pAura->GetStackAmount());
            }

            return 0;
        }

        uint32 spellId() const
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->HasAura(SPELL_ELECTRIFIED_WATER_VISUAL))
                    return SPELL_ELECTRIFIED_WATERS;

                return SPELL_FLUIDITY;
            }

            return 0;
        }

        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* owner = GetTarget();
            Unit* caster = GetCaster();

            if (!owner || !caster)
                return;

            if (Aura* pAura = owner->GetAura(spellId(), caster->GetGUID()))
            {
                pAura->RefreshDuration();

                if (!owner->HasAura(SPELL_CONDUCTIVE_WATERS))
                    owner->AddAura(SPELL_CONDUCTIVE_WATERS, owner);
            }
            else
                caster->AddAura(spellId(), owner);
        }

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* owner = GetTarget();
            Unit* caster = GetCaster();

            if (!owner || !caster)
                return;

            float dist_ex = owner->GetExactDist2d(caster);

            if (Aura* pAura = owner->GetAura(SPELL_FLUIDITY, caster->GetGUID()))
            {
                if (dist_ex > GetSizeProp(caster))
                    pAura->Remove(AURA_REMOVE_BY_EXPIRE);
            }
            else if (Aura* pAura = owner->GetAura(SPELL_ELECTRIFIED_WATERS, caster->GetGUID()))
            {
                if (dist_ex > GetSizeProp(caster))
                    pAura->Remove(AURA_REMOVE_BY_EXPIRE);
            }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(aura_impl::HandleOnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            //OnEffectRemove += AuraEffectRemoveFn(aura_impl::HandleOnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }

    AuraScript* GetAuraScript() const
    {
        return new aura_impl();
    }
};

class spell_water_auras : public SpellScriptLoader
{
public:
    spell_water_auras() : SpellScriptLoader("spell_water_auras") {}

    class aura_impl : public AuraScript
    {
        PrepareAuraScript(aura_impl);

        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Unit* owner = GetOwner()->ToUnit())
            {
                if (Aura* pAura = owner->GetAura(SPELL_CONDUCTIVE_WATERS))
                {
                    pAura->RefreshDuration();
                }
                else if (Aura* pAura = owner->AddAura(SPELL_CONDUCTIVE_WATERS, owner))
                {
                    pAura->SetMaxDuration(GetMaxDuration());
                    pAura->RefreshDuration();
                }
            }
        }

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Unit* owner = GetOwner()->ToUnit())
                owner->RemoveAurasDueToSpell(SPELL_CONDUCTIVE_WATERS);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(aura_impl::HandleOnApply, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
            OnEffectApply += AuraEffectApplyFn(aura_impl::HandleOnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(aura_impl::HandleOnRemove, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(aura_impl::HandleOnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new aura_impl();
    }
};

class spell_focused_lightning_conduction : public SpellScriptLoader
{
public:
    spell_focused_lightning_conduction() : SpellScriptLoader("spell_focused_lightning_conduction") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            if (Unit* caster = GetCaster())
            {
                if (Creature* pWaters = GetClosestCreatureWithEntry(caster, NPC_CONDUCTIVE_WATER, 100.f))
                {
                    targets.remove_if(conductionPredicate(pWaters));
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_impl::SelectTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

class spell_lightning_fissure_conduction : public SpellScriptLoader
{
public:
    spell_lightning_fissure_conduction() : SpellScriptLoader("spell_lightning_fissure_conduction") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(notPlayerPredicate());

            if (Unit* caster = GetCaster())
            {
                if (Creature* pWaters = GetClosestCreatureWithEntry(caster, NPC_CONDUCTIVE_WATER, 100.f))
                {
                    targets.remove_if(conductionPredicate(pWaters));
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_impl::SelectTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

class spell_focused_lightning : public SpellScriptLoader
{
public:
    spell_focused_lightning() : SpellScriptLoader("spell_focused_lightning") {}

    class spell_focused_lightning_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_focused_lightning_SpellScript);

        void HandleAfterCast()
        {
            Unit* pCaster = GetCaster();
            Unit* pHit = GetHitUnit();

            Position pos;
            pCaster->GetRandomNearPosition(20.0f);
            pCaster->SummonCreature(NPC_FOCUSED_LIGHTNING, pos, TEMPSUMMON_DEAD_DESPAWN);
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_focused_lightning_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_focused_lightning_SpellScript();
    }
};

class spell_lightning_fissure_damage : public SpellScriptLoader
{
public:
    spell_lightning_fissure_damage() : SpellScriptLoader("spell_lightning_fissure_damage") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(notPlayerPredicate());
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_impl::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

// Ionization - 138732
class bfa_spell_jinrokh_ionization : public SpellScriptLoader
{
public:
    bfa_spell_jinrokh_ionization() : SpellScriptLoader("bfa_spell_jinrokh_ionization") { }

    class bfa_spell_jinrokh_ionization_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_jinrokh_ionization_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_IONIZATION_DAMAGE, true);

            // Conduction
            if (caster->HasAura(SPELL_CONDUCTIVE_WATERS))
            {
                Map::PlayerList const& playerList = caster->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                {
                    if (Player* player = itr->GetSource())
                    {
                        if (player->HasAura(SPELL_CONDUCTIVE_WATERS))
                            caster->CastSpell(player, SPELL_IONIZATION_DAMAGE, true);
                    }
                }
            }
        }

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;

            // custom shit, meh
            if (target->HasSpell(56222) || target->HasSpell(115295) || target->HasSpell(31935) || target->HasSpell(20243) ||
                target->HasAura(31224) || target->HasAura(19263) || target->HasAura(642))
                target->RemoveAura(138732);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_jinrokh_ionization_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_jinrokh_ionization_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    class bfa_spell_jinrokh_ionization_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_jinrokh_ionization_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();

            if (!caster || targets.empty())
                return;

            // Remove specific specs
            for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
            {
                if (Player* player = (*itr)->ToPlayer())
                {
                    // Check specs
                    uint32 spec = player->GetSpecializationId();
                    bool checkSpec = false;

                    switch (spec)
                    {
                    case TALENT_SPEC_DRUID_BEAR:
                    case TALENT_SPEC_PALADIN_PROTECTION:
                    case TALENT_SPEC_WARRIOR_PROTECTION:
                    case TALENT_SPEC_DEATHKNIGHT_BLOOD:
                        checkSpec = true;
                        break;
                    }

                    if (checkSpec)
                    {
                        targets.erase(itr++);
                        continue;
                    }
                }
                ++itr;
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_jinrokh_ionization_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_TARGET_ANY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_jinrokh_ionization_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_TARGET_ANY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_jinrokh_ionization_SpellScript();
    }

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_jinrokh_ionization_AuraScript();
    }
};

// Ionization - 138733 ( damaging spell )
class bfa_spell_jinrokh_ionization_damage : public SpellScriptLoader
{
public:
    bfa_spell_jinrokh_ionization_damage() : SpellScriptLoader("bfa_spell_jinrokh_ionization_damage") { }

    class bfa_spell_jinrokh_ionization_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_jinrokh_ionization_damage_SpellScript);

        void OnHit(SpellEffIndex index)
        {
            if (Unit* target = GetHitUnit())
            {
                if (!target)
                    return;

                if (target->HasSpell(56222) || target->HasSpell(115295) || target->HasSpell(31935) || target->HasSpell(20243) ||
                    target->HasAura(31224) || target->HasAura(19263) || target->HasAura(642)) // ignore tanks ( spell check because .. damn, nvm )
                    SetHitDamage(0);

                /*uint32 damage = 0;
                switch (target->GetMap()->GetDifficulty())
                {
                    case RAID_DIFFICULTY_10MAN_HEROIC:
                    case RAID_DIFFICULTY_10MAN_NORMAL:
                    case RAID_DIFFICULTY_25MAN_HEROIC:
                    case RAID_DIFFICULTY_25MAN_NORMAL:
                        damage = 450000;
                }*/

                //SetHitDamage(damage);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_jinrokh_ionization_damage_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_jinrokh_ionization_damage_SpellScript();
    }

};

// Lightning Strike stalker - 69676
class bfa_npc_lightning_strike_stalker : public CreatureScript
{
public:
    bfa_npc_lightning_strike_stalker() : CreatureScript("bfa_npc_lightning_strike_stalker") { }

    struct bfa_npc_lightning_strike_stalkerAI : public ScriptedAI
    {
        bfa_npc_lightning_strike_stalkerAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetSpeed(MOVE_RUN, 0.1f);
            me->SetSpeed(MOVE_WALK, 0.1f);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetReactState(REACT_PASSIVE);
        }

        EventMap events;

        void IsSummonedBy(Unit* caster)
        {
            me->CastSpell(me, SPELL_LIGHTNING_STRIKE_VISUAL, true);
            events.ScheduleEvent(EVENT_HANDLE_SUMMON_AND_DAMAGE, 5000, 0, 0);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_HANDLE_SUMMON_AND_DAMAGE:
                    DoCast(SPELL_LIGHTNING_STRIKE_DAMAGE);
                    me->SummonCreature(NPC_STORM_EAST, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 2.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 7000);
                    me->SummonCreature(NPC_STORM_NORTH, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 2.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 7000);
                    me->SummonCreature(NPC_STORM_WEST, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 2.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 7000);
                    me->SummonCreature(NPC_STORM_SOUTH, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 2.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 7000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_lightning_strike_stalkerAI(creature);
    }
};

// Lightning Strike diffuse lights
class bfa_npc_lightning_strike_diffuse_lights : public CreatureScript
{
public:
    bfa_npc_lightning_strike_diffuse_lights() : CreatureScript("bfa_npc_lightning_strike_diffuse_lights") { }

    struct bfa_npc_lightning_strike_diffuse_lightsAI : public ScriptedAI
    {
        bfa_npc_lightning_strike_diffuse_lightsAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_LIGHTNING_STRIKE_DIFFUSE, me);
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
        }

        EventMap events;
        float north = 6.27691f;
        float south = 3.154962f;
        float west = 1.561388f;
        float east = 4.778380f;

        void IsSummonedBy(Unit* caster)
        {
            events.ScheduleEvent(EVENT_LIGHTNING_STRIKE_DAMAGE_PATH, 500);

            switch (me->GetEntry())
            {
            case NPC_STORM_EAST:
            {
                Position pos;
                me->GetNearPoint(NULL, pos.m_positionX, pos.m_positionY, pos.m_positionZ, DEFAULT_WORLD_OBJECT_SIZE, 150, east);
                me->GetMotionMaster()->MovePoint(0, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
                break;
            }
            case NPC_STORM_NORTH:
            {
                Position pos;
                me->GetNearPoint(NULL, pos.m_positionX, pos.m_positionY, pos.m_positionZ, DEFAULT_WORLD_OBJECT_SIZE, 150, north);
                me->GetMotionMaster()->MovePoint(0, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
                break;
            }
            case NPC_STORM_SOUTH:
            {
                Position pos;
                me->GetNearPoint(NULL, pos.m_positionX, pos.m_positionY, pos.m_positionZ, DEFAULT_WORLD_OBJECT_SIZE, 150, south);
                me->GetMotionMaster()->MovePoint(0, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
                break;
            }
            case NPC_STORM_WEST:
            {
                Position pos;
                me->GetNearPoint(NULL, pos.m_positionX, pos.m_positionY, pos.m_positionZ, DEFAULT_WORLD_OBJECT_SIZE, 150, west);
                me->GetMotionMaster()->MovePoint(0, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
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
                case EVENT_LIGHTNING_STRIKE_DAMAGE_PATH:
                    me->CastSpell(me, SPELL_LIGHTNING_STRIKE_DAMAGE, true);
                    events.ScheduleEvent(EVENT_LIGHTNING_STRIKE_DAMAGE_PATH, 500);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_lightning_strike_diffuse_lightsAI(creature);
    }
};

// Lightning Storm periodic summon - 137313
class bfa_spell_jinrokh_strikes_summon : public SpellScriptLoader
{
public:
    bfa_spell_jinrokh_strikes_summon() : SpellScriptLoader("bfa_spell_jinrokh_strikes_summon") { }

    class bfa_spell_jinrokh_strikes_summon_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_jinrokh_strikes_summon_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            // We don't know the exact number of spawns but we will do it like this: every 5 ticks will summon 3 orbs, tick at apply ( auto by attribute ), 5, 10, 14
            if (caster->GetMap()->IsHeroic())
            {
                if (aurEff->GetTickNumber() == 5)
                {
                    caster->CastSpell(caster, SPELL_STORM_STALKER_SUMMON, true);
                    caster->CastSpell(caster, SPELL_STORM_STALKER_SUMMON, true);
                    caster->CastSpell(caster, SPELL_STORM_STALKER_SUMMON, true);
                }
                if (aurEff->GetTickNumber() == 10)
                {
                    caster->CastSpell(caster, SPELL_STORM_STALKER_SUMMON, true);
                    caster->CastSpell(caster, SPELL_STORM_STALKER_SUMMON, true);
                    caster->CastSpell(caster, SPELL_STORM_STALKER_SUMMON, true);
                }
                if (aurEff->GetTickNumber() == 14)
                {
                    caster->CastSpell(caster, SPELL_STORM_STALKER_SUMMON, true);
                    caster->CastSpell(caster, SPELL_STORM_STALKER_SUMMON, true);
                    caster->CastSpell(caster, SPELL_STORM_STALKER_SUMMON, true);
                }
            }
        }


        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (!GetCaster())
                return;
            GetCaster()->AddUnitState(UNIT_STATE_ROOT);
            GetCaster()->AddAura(42716, GetCaster());
        }

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (!GetCaster())
                return;
            GetCaster()->ClearUnitState(UNIT_STATE_ROOT);
            GetCaster()->RemoveAura(42716);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_jinrokh_strikes_summon_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            OnEffectApply += AuraEffectApplyFn(bfa_spell_jinrokh_strikes_summon_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_jinrokh_strikes_summon_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_jinrokh_strikes_summon_AuraScript();
    }
};

void AddSC_boss_jinrokh()
{
    new boss_jinrokh();
    new npc_focused_lightning();
    new npc_lightning_fissure();
    new spell_focused_lightning_targeting();
    new spell_focused_lightning_aoe();
    new spell_focused_lightning_speed();
    new spell_focused_lightning_detonation();
    new spell_implosion();
    new spell_static_wound();
    new spell_static_wound_damage();
    new spell_static_burst();
    new spell_lightning_storm_visual();
    new spell_thundering_throw_silence();
    //new spell_thundering_throw_damage(); INTENDED, was working not correctly
    new spell_thundering_throw();
    new npc_jinrokh_statue();
    new npc_conductive_water();
    new spell_conductive_water_dummy();
    new spell_water_auras();
    new spell_focused_lightning_conduction();
    new spell_lightning_fissure_conduction();
    new spell_focused_lightning();
    new spell_lightning_fissure_damage();
    new bfa_spell_jinrokh_ionization;
    new bfa_spell_jinrokh_ionization_damage;
    new bfa_npc_lightning_strike_stalker;
    new bfa_npc_lightning_strike_diffuse_lights;
    new bfa_spell_jinrokh_strikes_summon;
}
