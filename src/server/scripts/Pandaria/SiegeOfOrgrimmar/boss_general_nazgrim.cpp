#include "siege_of_orgrimmar.hpp"

#define NAZGRIM_POWER_TYPE POWER_MANA
#define NAZGRIM_POWER_MAX 100

enum ScriptedTexts
{
    SAY_AGGRO_ALLIANCE  = 0,
    SAY_AGGRO_HORDE     = 1,
    SAY_DEATH_ALLIANCE  = 2,
    SAY_DEATH_GAMON_1   = 3,
    SAY_DEATH_GAMON_2   = 4,
    SAY_DEATH_HORDE_1   = 5,
    SAY_DEATH_HORDE_2   = 6,
    SAY_ADDS            = 7,
    SAY_ADDS_ALL        = 8,
    SAY_INTRO_ALLIANCE  = 9,

    SAY_IRON_JUGGERNAUT_INTRO   = 10,
    SAY_IRON_JUGGERNAUT_DEATH   = 11,
    SAY_IRON_JUGGERNAUT_OUTRO   = 12,

    SAY_INTRO_HORDE     = 13,
    SAY_WIPE            = 14,
};

enum Spells
{
    SPELL_ZERO_MANA_REGEN           = 96301,

    SPELL_BERSERK                   = 26662,

    SPELL_BATTLE_STANCE             = 143589,
    SPELL_BERSERKER_STANCE          = 143594,
    SPELL_DEFENSIVE_STANCE          = 143593,

    SPELL_GENERATE_RAGE             = 144278, // from defensive stance
    SPELL_GENERATE_RAGE_ENERGIZE    = 143597,

    SPELL_COOLING_OFF               = 143484,

    SPELL_ENEGRIZE_NAZGRIM_1        = 143590, // 3 points from banner
    SPELL_ENERGIZE_NAZGRIM_2        = 143876, // 3 points from aftershock
    SPELL_ENERGIZE_NAZGRIM_3        = 143877, // 5 points from ravager

    SPELL_SUNDERING_BLOW            = 143494,

    SPELL_BONECRACKER               = 143638,

    SPELL_HEROIC_SHOCKWAVE          = 143500,
    SPELL_HEROIC_SHOCKWAVE_DMG      = 143716,
    SPELL_HEROIC_SHOCKWAVE_FORCE    = 143713,
    SPELL_HEROIC_SHOCKWAVE_SUMMON   = 143715,

    SPELL_AFTERSHOCK                = 143712,

    SPELL_KORKRON_BANNER            = 143591,
    SPELL_KORKRON_BANNER_SUMMON     = 143501,
    SPELL_KORKRON_BANNER_AURA       = 143536,
    SPELL_KORKRON_BANNER_BUFF       = 143535,

    SPELL_WAR_SONG                  = 143503,

    SPELL_RAVAGER                   = 143872,
    SPELL_RAVAGER_AURA              = 143874,
    SPELL_RAVAGER_DMG               = 143873,

    SPELL_EXECUTE                   = 143502,

    // Kor'kron Ironblade
    SPELL_IRONSTORM                 = 143420,
    SPELL_IRONSTORM_DMG             = 143421,
    SPELL_LAST_STAND                = 143427,

    // Kor'kron Arcweaver
    SPELL_ARCANE_SHOCK              = 143432,
    SPELL_MAGICSTRIKE               = 143431,
    SPELL_UNSTABLE_BLINK            = 143433,

    // Kor'kron Assassin
    SPELL_ASSASSINS_MARK            = 143480,
    SPELL_BACKSTAB                  = 143481,
    SPELL_STEALTH                   = 118969,

    // Kor'kron Warshaman
    SPELL_EARTH_SHIELD              = 143475,
    SPELL_EARTH_SHIELD_HEAL         = 143479,
    SPELL_EMPOWERED_CHAIN_HEAL      = 143473,
    SPELL_HEALING_TIDE_TOTEM        = 143474,
    SPELL_HEALING_TIDE              = 143477,
    SPELL_HEALING_TIDE_HEAL         = 143478,

    // Kor'kron Sniper
    SPELL_SHOT                      = 143884,
    SPELL_HUNTERS_MARK              = 143882,
    SPELL_MULTI_SHOT                = 143887,
};

enum Adds
{
    NPC_KORKRON_BANNER              = 71626,
    NPC_GENERAL_NAZGRIM_AFTERSHOCK  = 71697,
    NPC_RAVAGER                     = 71762,

    NPC_ORGRIMMAR_FAITHFUL          = 71715,
    NPC_KORKRON_IRONBLADE           = 71516,
    NPC_KORKRON_ARCWEAVER           = 71517,
    NPC_KORKRON_ASSASSIN            = 71518,
    NPC_KORKRON_WARSHAMAN           = 71519,
    NPC_HEALING_TIDE_TOTEM          = 71610,
    NPC_KORKRON_SNIPER              = 71656,
};

enum Events
{
    EVENT_SWITCH_STANCE     = 1,
    EVENT_SUNDERING_BLOW,
    EVENT_BONECRACKER,
    EVENT_EXECUTE,
    EVENT_RAGE_SPELL,
    EVENT_BERSERK,
    EVENT_SUMMON_ADDS,

    // Kor'kron Warshaman
    EVENT_IRONSTORM,

    // Kor'kron Arcweaver
    EVENT_ARCANE_SHOCK,
    EVENT_MAGICSTRIKE,
    EVENT_UNSTABLE_BLINK,

    // Kor'kron Assassin
    EVENT_BACKSTAB,
    EVENT_ASSASSINS_MARK,

    // Kor'kron Warshaman
    EVENT_EARTH_SHIELD,
    EVENT_EMPOWERED_CHAIN_HEAL,
    EVENT_HEALING_TIDE_TOTEM,

    // Kor'kron Sniper
    EVENT_SHOT,
    EVENT_MULTI_SHOT,
};

enum Datas
{
    DATA_ADD_POSITION   = 1,
};

enum Actions
{

};

enum DisplayIds
{
    DISPLAY_ITEM_RAVAGER = 7717,
};

enum Timers
{
    TIMER_BERSERK               = 10 * MINUTE * IN_MILLISECONDS,
    TIMER_EVADE_CHECK           = 5 * IN_MILLISECONDS,

    TIMER_RAGE_SPELL            = 1 * IN_MILLISECONDS,

    TIMER_SWITCH_STANCE_FIRST   = 1 * IN_MILLISECONDS,
    TIMER_SWITCH_STANCE         = 60 * IN_MILLISECONDS,

    TIMER_SUNDERING_BLOW_FIRST  = 8 * IN_MILLISECONDS,
    TIMER_SUNDERING_BLOW        = 8 * IN_MILLISECONDS,

    TIMER_BONECRACKER_FIRST     = 20 * IN_MILLISECONDS,
    TIMER_BONECRACKER           = 30 * IN_MILLISECONDS,

    TIMER_EXECUTE               = 18 * IN_MILLISECONDS,

    TIMER_SUMMON_ADDS_FIRST     = 45 * IN_MILLISECONDS,
    TIMER_SUMMON_ADDS           = 45 * IN_MILLISECONDS,

    // Kor'kron Ironblade
    TIMER_IRONSTORM_FIRST_MIN   = 6 * IN_MILLISECONDS,
    TIMER_IRONSTORM_FIRST_MAX   = 10 * IN_MILLISECONDS,
    TIMER_IRONSTORM_MIN         = 3 * IN_MILLISECONDS,
    TIMER_IRONSTORM_MAX         = 5 * IN_MILLISECONDS,

    // Kor'kron Arcweaver
    TIMER_ARCANE_SHOCK_FIRST    = 1 * IN_MILLISECONDS,
    TIMER_ARCANE_SHOCK          = 1500,
    TIMER_MAGICSTRIKE_FIRST_MIN = 5 * IN_MILLISECONDS,
    TIMER_MAGICSTRIKE_FIRST_MAX = 5 * IN_MILLISECONDS,
    TIMER_MAGICSTRIKE_MIN       = 15 * IN_MILLISECONDS,
    TIMER_MAGICSTRIKE_MAX       = 20 * IN_MILLISECONDS,
    TIMER_UNSTABLE_BLINK_MIN    = 20 * IN_MILLISECONDS,
    TIMER_UNSTABLE_BLINK_MAX    = 25 * IN_MILLISECONDS,

    // Kor'kron Assassin
    TIMER_BACKSTAB              = 2 * IN_MILLISECONDS,

    // Kor'kron Warshaman
    TIMER_EARTH_SHIELD_FIRST    = 5 * IN_MILLISECONDS,
    TIMER_EARTH_SHIELD          = 40 * IN_MILLISECONDS,
    TIMER_EMPOWERED_CHAIN_HEAL  = 15 * IN_MILLISECONDS,
    TIMER_HEALING_TIDE_TOTEM    = 20 * IN_MILLISECONDS,

    // Kor'kron Sniper
    TIMER_SHOT_FIRST            = 1,
    TIMER_SHOT                  = 3 * IN_MILLISECONDS,
    TIMER_MULTI_SHOT_FIRST      = 10 * IN_MILLISECONDS,
    TIMER_MULTI_SHOT            = 25 * IN_MILLISECONDS,
};

enum MovementPoints : int
{
    POINT_ADDS_POSITION = 1,
    POINT_RAVAGER,
};

enum Stances : int
{
    STANCE_NONE         = 0,
    BATTLE_STANCE       = 1,
    BERSERKER_STANCE    = 2,
    DEFENSIVE_STANCE    = 3,
};

#define ADDS_NORMAL_COUNT 2
#define ADDS_HEROIC_COUNT 3
#define ADD_POSITIONS_COUNT 5

const Position addSpawnPos[ADD_POSITIONS_COUNT][2] =
{
    {
        {1584.02f, -4591.88f, -66.80f, 5.84f},
        {1588.61f, -4594.49f, -66.73f, 5.78f}
    },
    {
        {1591.88f, -4584.03f, -66.81f, 5.22f},
        {1594.81f, -4590.88f, -66.73f, 5.02f}
    },
    {
        {1559.00f, -4621.40f, -66.92f, 5.76f},
        {1564.27f, -4624.34f, -66.93f, 5.77f}
    },
    {
        {1558.65f, -4634.91f, -67.05f, 0.50f},
        {1563.88f, -4632.72f, -67.05f, 0.37f}
    },
    {
        {1568.02f, -4647.59f, -66.84f, 0.78f},
        {1572.80f, -4642.79f, -66.70f, 0.78f}
    }
};

#define RAVAGER_POSITIONS_COUNT 25
const Position ravagerPos[RAVAGER_POSITIONS_COUNT] =
{
    {1643.64f, -4645.60f, -66.79f, 3.44f},
    {1637.34f, -4647.63f, -66.76f, 3.45f},
    {1617.09f, -4653.23f, -66.70f, 3.36f},
    {1597.75f, -4646.55f, -66.66f, 2.10f},
    {1606.33f, -4636.58f, -66.66f, 0.16f},
    {1621.81f, -4635.69f, -66.66f, 0.06f},
    {1633.32f, -4630.58f, -66.71f, 0.86f},
    {1635.59f, -4622.14f, -66.80f, 1.59f},
    {1629.13f, -4620.30f, -66.70f, 3.62f},
    {1617.72f, -4626.42f, -66.66f, 3.50f},
    {1610.47f, -4629.20f, -66.67f, 3.51f},
    {1588.71f, -4634.87f, -66.70f, 3.17f},
    {1576.44f, -4625.86f, -66.68f, 1.82f},
    {1582.23f, -4621.98f, -66.69f, 0.15f},
    {1604.74f, -4618.87f, -66.70f, 0.20f},
    {1617.71f, -4615.71f, -66.68f, 0.27f},
    {1627.99f, -4606.91f, -66.67f, 1.36f},
    {1623.68f, -4596.37f, -66.37f, 2.48f},
    {1609.05f, -4589.64f, -66.62f, 2.87f},
    {1601.66f, -4595.68f, -66.68f, 4.78f},
    {1597.47f, -4607.35f, -66.69f, 3.39f},
    {1584.17f, -4608.35f, -66.68f, 3.33f},
    {1581.86f, -4619.30f, -66.68f, 4.48f},
    {1568.73f, -4627.20f, -66.79f, 4.14f},
    {1567.53f, -4636.09f, -66.87f, 5.06f}
};

#define EVADE_DISTANCE 95.f

const Position centerOfRoomPos = { 1608.81f, -4629.61f, -66.60f, 0.0f };
#define DISTANCE_FROM_CENTER 30.f

class boss_general_nazgrim : public CreatureScript
{
    public:

        boss_general_nazgrim() : CreatureScript("boss_general_nazgrim") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_general_nazgrimAI(creature);
        }

        struct boss_general_nazgrimAI : public BossAI
        {
            boss_general_nazgrimAI(Creature* creature) : BossAI(creature, DATA_GENERAL_NAZGRIM),
                m_IsIntroDone(false), m_FaithfulSpawned(false), checkEvadeTimer(TIMER_EVADE_CHECK)
            {
                //ApplyAllImmunities(true);

                me->setActive(true);

                SetEquipmentSlots(false, DISPLAY_ITEM_RAVAGER);
            }

            void Reset() override
            {
                _Reset();

                InitPowers();
                SpawnOrgrimmarFaithfuls();
                RemoveInstanceAuras();

                me->SetReactState(REACT_AGGRESSIVE);

                m_CurrentStance = STANCE_NONE;
                m_LastHeroicShockwavePosition = me->GetHomePosition();
                m_IsLowHealth = false;

                me->SetEmoteState(Emote::EMOTE_STATE_READY2H);
            }

            void EnterCombat(Unit* who) override
            {
                TalkAggro();
                events.ScheduleEvent(EVENT_BERSERK, TIMER_BERSERK);
                events.ScheduleEvent(EVENT_SWITCH_STANCE, TIMER_SWITCH_STANCE_FIRST);
                events.ScheduleEvent(EVENT_SUNDERING_BLOW, TIMER_SUNDERING_BLOW_FIRST);
                events.ScheduleEvent(EVENT_BONECRACKER, TIMER_BONECRACKER_FIRST);
                events.ScheduleEvent(EVENT_RAGE_SPELL, TIMER_RAGE_SPELL);
                events.ScheduleEvent(EVENT_SUMMON_ADDS, TIMER_SUMMON_ADDS_FIRST);

                if (IsHeroic())
                {
                    events.ScheduleEvent(EVENT_EXECUTE, TIMER_EXECUTE);
                }

                OrgrimmarFaithfulsAggro(who);

                DoZoneInCombat();
                instance->SetBossState(DATA_GENERAL_NAZGRIM, IN_PROGRESS);
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!m_IsIntroDone && who->IsPlayer() && me->GetDistance(who) <= 80.0f)
                {
                    m_IsIntroDone = true;

                    TalkIntro();
                }
            }

            void MovementInform(uint32 p_Type, uint32 p_Id) override
            {
                if (p_Id == EVENT_JUMP)
                {
                    // reenable moving to the target
                    me->ClearUnitState(UNIT_STATE_MELEE_ATTACKING);
                }
            }

            void JustDied(Unit* who) override
            {
                _JustDied();

                RemoveInstanceAuras();
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_IRON_JUGGERNAUT_DEAD)
                {
                    AddTimedDelayedOperation(4000, [this]() -> void
                    {
                        Talk(SAY_IRON_JUGGERNAUT_DEATH);
                    });
                    //m_SceneHelper.AddSceneActionTalk(SAY_IRON_JUGGERNAUT_DEATH, 4000);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (CheckEvade(diff))
                    return;

                events.Update(diff);

                CheckLowHealth();

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

            void ExecuteEvent(const uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_BERSERK:
                        DoCast(me, SPELL_BERSERK);
                        break;
                    case EVENT_SWITCH_STANCE:
                        SwitchStance();
                        events.ScheduleEvent(EVENT_SWITCH_STANCE, TIMER_SWITCH_STANCE);
                        break;
                    case EVENT_SUNDERING_BLOW:
                        // set 'triggered', because spell is applied on next swing
                        DoCastVictim(SPELL_SUNDERING_BLOW, true);
                        events.ScheduleEvent(EVENT_SUNDERING_BLOW, TIMER_SUNDERING_BLOW);
                        break;
                    case EVENT_BONECRACKER:
                        me->CastCustomSpell(SPELL_BONECRACKER, SPELLVALUE_MAX_TARGETS, Is25ManRaid() ? 5 : 2, me, false);
                        events.ScheduleEvent(EVENT_BONECRACKER, TIMER_BONECRACKER);
                        break;
                    case EVENT_EXECUTE:
                        DoExecute();
                        events.ScheduleEvent(EVENT_EXECUTE, TIMER_EXECUTE);
                        break;
                    case EVENT_RAGE_SPELL:
                        DoRageSpell();
                        events.ScheduleEvent(EVENT_RAGE_SPELL, TIMER_RAGE_SPELL);
                        break;
                    case EVENT_SUMMON_ADDS:
                        DoSpawnAdds();
                        events.ScheduleEvent(EVENT_SUMMON_ADDS, TIMER_SUMMON_ADDS);
                        break;
                }
            }

            Position GetLastHeroicShockwavePosition()
            {
                return m_LastHeroicShockwavePosition;
            }

        private:

            void TalkIntro()
            {
                uint32 team = instance->GetData(DATA_TEAM_IN_INSTANCE);

                if (team == ALLIANCE)
                {
                    Talk(SAY_INTRO_ALLIANCE);
                }
                else if (team == HORDE)
                {
                    Talk(SAY_INTRO_HORDE);
                }
            }

            void TalkAggro()
            {
                uint32 team = instance->GetData(DATA_TEAM_IN_INSTANCE);
                if (team == ALLIANCE)
                {
                    Talk(SAY_AGGRO_ALLIANCE);
                }
                else if (team == HORDE)
                {
                    Talk(SAY_AGGRO_HORDE);
                }
            }

            void InitPowers()
            {
                me->AddAura(SPELL_ZERO_MANA_REGEN, me);

                me->SetPowerType(NAZGRIM_POWER_TYPE);
                me->SetMaxPower(NAZGRIM_POWER_TYPE, NAZGRIM_POWER_MAX);
                me->SetPower(NAZGRIM_POWER_TYPE, 0);
            }

            void SpawnOrgrimmarFaithfuls()
            {
                if (m_FaithfulSpawned)
                    return;

                m_FaithfulSpawned = true;

                Position l_Pos = { 1640.0f, -4645.0f, -66.78f, 5.38f };

                for (uint8 l_Row = 0; l_Row < 4; ++l_Row)
                {
                    for (uint8 l_Column = 0; l_Column < 7; ++l_Column)
                    {
                        if (l_Column != 3)
                        {
                            me->SummonCreature(NPC_ORGRIMMAR_FAITHFUL, l_Pos);
                        }

                        l_Pos.m_positionX -= 4.0f;
                        l_Pos.m_positionY -= 3.0f;
                    }

                    l_Pos.m_positionX += 24.0f;
                    l_Pos.m_positionY += 28.0f;
                }
            }

            void OrgrimmarFaithfulsAggro(Unit* target)
            {
                for (ObjectGuid l_SummonGuid : summons)
                {
                    if (ObjectAccessor::GetCreature(*me, l_SummonGuid)->GetEntry() == NPC_ORGRIMMAR_FAITHFUL)
                    {
                        if (Creature* l_Faithful = ObjectAccessor::GetCreature(*me, l_SummonGuid))
                        {
                            if (l_Faithful->IsAlive() && !l_Faithful->IsInCombat())
                                l_Faithful->AI()->AttackStart(target);
                        }
                    }
                }
            }

            void SwitchStance()
            {
                uint32 currentStanceSpellId = 0;
                uint32 nextStanceSpellId = 0;
                Stances nextStance = STANCE_NONE;

                switch (m_CurrentStance)
                {
                    case BATTLE_STANCE:
                        currentStanceSpellId = SPELL_BATTLE_STANCE;
                        nextStanceSpellId = SPELL_BERSERKER_STANCE;
                        nextStance = BERSERKER_STANCE;
                        break;
                    case BERSERKER_STANCE:
                        currentStanceSpellId = SPELL_BERSERKER_STANCE;
                        nextStanceSpellId = SPELL_DEFENSIVE_STANCE;
                        nextStance = DEFENSIVE_STANCE;
                        break;
                    case DEFENSIVE_STANCE:
                        currentStanceSpellId = SPELL_DEFENSIVE_STANCE;
                        nextStanceSpellId = SPELL_BATTLE_STANCE;
                        nextStance = BATTLE_STANCE;
                        break;
                    default:
                        currentStanceSpellId = 0;
                        nextStanceSpellId = SPELL_BATTLE_STANCE;
                        nextStance = BATTLE_STANCE;
                        break;
                }

                if (currentStanceSpellId)
                {
                    me->RemoveAura(currentStanceSpellId);
                }

                if (nextStanceSpellId)
                {
                    me->CastSpell(me, nextStanceSpellId, true);
                }

                m_CurrentStance = nextStance;
            }

            void DoExecute()
            {
                DoCastVictim(SPELL_EXECUTE);
            }

            void DoRageSpell()
            {
                if (me->HasAura(SPELL_COOLING_OFF))
                    return;

                uint32 rageSpellId = 0;
                Unit* target = NULL;

                int32 currentPower = me->GetPower(NAZGRIM_POWER_TYPE);

                if (currentPower >= 100)
                {
                    rageSpellId = SPELL_RAVAGER;
                    target = me->GetVictim();
                }
                else if (currentPower >= 70)
                {
                    rageSpellId = SPELL_WAR_SONG;
                    target = me;
                }
                else if (currentPower >= 50)
                {
                    rageSpellId = SPELL_KORKRON_BANNER;
                    target = me;
                }
                else if (currentPower >= 30)
                {
                    rageSpellId = SPELL_HEROIC_SHOCKWAVE;
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0, -20.0f, true);
                    if (!target)
                        target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);

                    if (target)
                    {
                        m_LastHeroicShockwavePosition = target->GetPosition();
                        //target->GetPosition(&m_LastHeroicShockwavePosition);
                    }
                }

                if (rageSpellId && target)
                {
                    DoCast(target, rageSpellId);
                    me->AddAura(SPELL_COOLING_OFF, me);
                }
            }

            void DoSpawnAdds()
            {
                Talk(SAY_ADDS);

                SpawnAdds(IsHeroic() ? ADDS_HEROIC_COUNT : ADDS_NORMAL_COUNT);
            }

            void DoSpawnAdditionalAdds()
            {
                Talk(SAY_ADDS_ALL);

                SpawnAdds(4);
            }

            void CheckLowHealth()
            {
                if (m_IsLowHealth)
                    return;

                if (me->GetHealthPct() <= 10.f)
                {
                    m_IsLowHealth = true;

                    DoSpawnAdditionalAdds();
                }
            }

            void SpawnAdds(const uint32 count)
            {
                std::list<uint32> addsEntries{ NPC_KORKRON_IRONBLADE, NPC_KORKRON_ASSASSIN, NPC_KORKRON_ARCWEAVER, NPC_KORKRON_WARSHAMAN };
                if (IsHeroic())
                    addsEntries.push_back(NPC_KORKRON_SNIPER);
                Trinity::Containers::RandomResize(addsEntries, count);

                std::list<uint32> addsPositions{ 0, 1, 2, 3, 4 };
                Trinity::Containers::RandomResize(addsPositions, count);

                for (auto creatureEntry : addsEntries)
                {
                    if (addsPositions.empty())
                        break;

                    uint32 positionIndex = addsPositions.front();
                    addsPositions.pop_front();

                    if (Creature* pCreature = me->SummonCreature(creatureEntry, addSpawnPos[positionIndex][0]))
                    {
                        pCreature->GetMotionMaster()->MovePoint(POINT_ADDS_POSITION, addSpawnPos[positionIndex][1]);
                    }
                }
            }

            void RemoveInstanceAuras()
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ASSASSINS_MARK);
            }

            bool CheckEvade(const uint32 diff)
            {
                if (checkEvadeTimer <= diff)
                {
                    checkEvadeTimer = TIMER_EVADE_CHECK;

                    if (me->GetExactDist(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ()) >= EVADE_DISTANCE)
                    {
                        EnterEvadeMode();
                        return true;
                    }
                }
                else
                {
                    checkEvadeTimer -= diff;
                }

                return false;
            }

        private:

            bool m_IsIntroDone;
            bool m_FaithfulSpawned;
            Stances m_CurrentStance;
            Position m_LastHeroicShockwavePosition;
            bool m_IsLowHealth;
            uint32 checkEvadeTimer;

        };
};

struct npc_nazgrim_korkron_addAI : public ScriptedAI
{
    public:

        npc_nazgrim_korkron_addAI(Creature* creature) : ScriptedAI(creature)
        {
            //ApplyAllImmunities(true);

            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, false);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, false);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);

            me->setActive(true);

            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            events.Reset();
            summons.DespawnAll();
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == POINT_ADDS_POSITION)
            {
                me->GetMotionMaster()->MovementExpired(false);

                DoAggro();
            }
        }

        void JustDied(Unit* who) override
        {
            events.Reset();
            summons.DespawnAll();

            me->DespawnOrUnsummon(3000);
        }

    protected:

        virtual void DoAggro() { }

        bool TryToGetClose(Unit* victim)
        {
            if (!victim)
                return false;

            if (me->isMoving())
                return false;

            const float range = 30.f;

            if (!me->IsWithinDistInMap(victim, range))
            {
                me->GetMotionMaster()->MoveChase(victim, range);
                return true;
            }

            if (!me->IsWithinLOSInMap(victim))
            {
                me->GetMotionMaster()->MoveChase(victim, MELEE_RANGE);
                return true;
            }

            return false;
        }
};

class npc_general_nazgrim_korkron_ironblade : public CreatureScript
{
    public:
        npc_general_nazgrim_korkron_ironblade() : CreatureScript("npc_general_nazgrim_korkron_ironblade") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_general_nazgrim_korkron_ironbladeAI(creature);
        }

        struct npc_general_nazgrim_korkron_ironbladeAI : public npc_nazgrim_korkron_addAI
        {
            npc_general_nazgrim_korkron_ironbladeAI(Creature* creature) : npc_nazgrim_korkron_addAI(creature) { }

            void Reset() override
            {
                npc_nazgrim_korkron_addAI::Reset();

                m_IsLastStandDone = false;
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (CheckForLastStand())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING | UNIT_STATE_CONTROLLED))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_IRONSTORM:
                            DoCast(me, SPELL_IRONSTORM);
                            /// The creature can move during casting this spell
                            me->ClearUnitState(UnitState::UNIT_STATE_CASTING);
                            break;
                    }
                }

                if (!me->HasAura(Spells::SPELL_IRONSTORM))
                    DoMeleeAttackIfReady();
            }

            void OnSpellCastInterrupt(SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_IRONSTORM)
                    events.ScheduleEvent(EVENT_IRONSTORM, urand(TIMER_IRONSTORM_MIN, TIMER_IRONSTORM_MAX));
            }

        protected:

            virtual void DoAggro() override
            {
                me->SetReactState(REACT_AGGRESSIVE);

                events.ScheduleEvent(EVENT_IRONSTORM, urand(TIMER_IRONSTORM_FIRST_MIN, TIMER_IRONSTORM_FIRST_MAX));
            }

        private:

            bool CheckForLastStand()
            {
                if (!m_IsLastStandDone && me->GetHealthPct() <= 50.0f)
                {
                    m_IsLastStandDone = true;

                    me->InterruptNonMeleeSpells(false);
                    DoCast(me, SPELL_LAST_STAND);
                    return true;
                }

                return false;
            }

        private:
            bool m_IsLastStandDone = false;
        };
};

class npc_general_nazgrim_korkron_arcweaver : public CreatureScript
{
    public:
        npc_general_nazgrim_korkron_arcweaver() : CreatureScript("npc_general_nazgrim_korkron_arcweaver") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_general_nazgrim_korkron_arcweaverAI(creature);
        }

        struct npc_general_nazgrim_korkron_arcweaverAI : public npc_nazgrim_korkron_addAI
        {
            npc_general_nazgrim_korkron_arcweaverAI(Creature* creature) : npc_nazgrim_korkron_addAI(creature)
            {
            }

            void Reset()
            {
                npc_nazgrim_korkron_addAI::Reset();
            }

            void AttackStart(Unit* who)
            {
                if (!who)
                    return;

                if (me->Attack(who, true))
                    DoStartNoMovement(who);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (TryToGetClose(me->GetVictim()))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ARCANE_SHOCK:
                            DoCastVictim(SPELL_ARCANE_SHOCK);
                            events.ScheduleEvent(EVENT_ARCANE_SHOCK, TIMER_ARCANE_SHOCK);
                            break;
                        case EVENT_MAGICSTRIKE:
                            DoCastAOE(SPELL_MAGICSTRIKE);
                            events.ScheduleEvent(EVENT_MAGICSTRIKE, urand(TIMER_MAGICSTRIKE_MIN, TIMER_MAGICSTRIKE_MAX));
                            break;
                        case EVENT_UNSTABLE_BLINK:
                            DoCast(SPELL_UNSTABLE_BLINK);
                            events.ScheduleEvent(EVENT_UNSTABLE_BLINK, urand(TIMER_UNSTABLE_BLINK_MIN, TIMER_UNSTABLE_BLINK_MAX));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

         protected:

            virtual void DoAggro() override
            {
                me->SetReactState(REACT_AGGRESSIVE);

                events.ScheduleEvent(EVENT_ARCANE_SHOCK, TIMER_ARCANE_SHOCK_FIRST);
                events.ScheduleEvent(EVENT_MAGICSTRIKE, urand(TIMER_MAGICSTRIKE_FIRST_MIN, TIMER_MAGICSTRIKE_FIRST_MAX));
                events.ScheduleEvent(EVENT_UNSTABLE_BLINK, urand(TIMER_UNSTABLE_BLINK_MIN, TIMER_UNSTABLE_BLINK_MAX));
            }

        };
};

class npc_general_nazgrim_korkron_assassin : public CreatureScript
{
    public:
        npc_general_nazgrim_korkron_assassin() : CreatureScript("npc_general_nazgrim_korkron_assassin") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_general_nazgrim_korkron_assassinAI(creature);
        }

        struct npc_general_nazgrim_korkron_assassinAI : public npc_nazgrim_korkron_addAI
        {
            npc_general_nazgrim_korkron_assassinAI(Creature* creature) : npc_nazgrim_korkron_addAI(creature)
            {
            }

            void Reset()
            {
                npc_nazgrim_korkron_addAI::Reset();

                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
            }

            void UpdateAI(const uint32 diff)
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
                        case EVENT_BACKSTAB:
                            if (Unit* target = me->GetVictim())
                            {
                                if (target->isInBack(me))
                                {
                                    DoCast(target, SPELL_BACKSTAB);
                                }
                            }
                            events.ScheduleEvent(EVENT_BACKSTAB, TIMER_BACKSTAB);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        protected:

            virtual void DoAggro() override
            {
                me->SetReactState(REACT_AGGRESSIVE);

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                {
                    me->AddAura(SPELL_ASSASSINS_MARK, target);
                    me->AddAura(SPELL_STEALTH, me);
                    me->AddThreat(target, 1000000.0f);
                    AttackStart(target);
                }

                events.ScheduleEvent(EVENT_BACKSTAB, TIMER_BACKSTAB);
            }

        };
};

class npc_general_nazgrim_korkron_warshaman : public CreatureScript
{
    public:
        npc_general_nazgrim_korkron_warshaman() : CreatureScript("npc_general_nazgrim_korkron_warshaman") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_general_nazgrim_korkron_warshamanAI(creature);
        }

        struct npc_general_nazgrim_korkron_warshamanAI : public npc_nazgrim_korkron_addAI
        {
            npc_general_nazgrim_korkron_warshamanAI(Creature* creature) : npc_nazgrim_korkron_addAI(creature)
            {
            }

            void Reset()
            {
                npc_nazgrim_korkron_addAI::Reset();
            }

            void EnterCombat(Unit* who)
            {
            }

            void UpdateAI(const uint32 diff)
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
                        case EVENT_EARTH_SHIELD:

                            me->GetFriendlyUnitListInRange(friendlys, 20.0f);
                            if (friendlys.empty())
                                return;

                            friendlys.sort(Trinity::DistanceOrderPred(me));
                            itr = friendlys.begin();
                            if (Unit* target = *itr)
                            {
                                DoCast(target, SPELL_EARTH_SHIELD);
                            }
                            events.ScheduleEvent(EVENT_EARTH_SHIELD, TIMER_EARTH_SHIELD);
                            break;
                        case EVENT_EMPOWERED_CHAIN_HEAL:
                            DoCast(me, SPELL_EMPOWERED_CHAIN_HEAL);
                            events.ScheduleEvent(EVENT_EMPOWERED_CHAIN_HEAL, TIMER_EMPOWERED_CHAIN_HEAL);
                            break;
                        case EVENT_HEALING_TIDE_TOTEM:
                            DoCast(me, SPELL_HEALING_TIDE_TOTEM);
                            events.ScheduleEvent(EVENT_HEALING_TIDE_TOTEM, TIMER_HEALING_TIDE_TOTEM);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        protected:

            virtual void DoAggro() override
            {
                me->SetReactState(REACT_AGGRESSIVE);

                events.ScheduleEvent(EVENT_EARTH_SHIELD, TIMER_EARTH_SHIELD_FIRST);
                events.ScheduleEvent(EVENT_EMPOWERED_CHAIN_HEAL, TIMER_EMPOWERED_CHAIN_HEAL);
                events.ScheduleEvent(EVENT_HEALING_TIDE_TOTEM, TIMER_HEALING_TIDE_TOTEM);
            }
        private:
            std::list<Unit*> friendlys;
            std::list<Unit*>::iterator itr;
        };
};

class npc_general_nazgrim_korkron_sniper : public CreatureScript
{
    public:
        npc_general_nazgrim_korkron_sniper() : CreatureScript("npc_general_nazgrim_korkron_sniper") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_general_nazgrim_korkron_sniperAI(creature);
        }

        struct npc_general_nazgrim_korkron_sniperAI : public npc_nazgrim_korkron_addAI
        {
            npc_general_nazgrim_korkron_sniperAI(Creature* creature) : npc_nazgrim_korkron_addAI(creature)
            {
                m_TargetGuid = ObjectGuid::Empty;
            }

            void Reset()
            {
                npc_nazgrim_korkron_addAI::Reset();

                // wrong item
                SetEquipmentSlots(false, 103953, 0, 103953);
            }

            void EnterCombat(Unit* who)  override
            {
            }

            void AttackStart(Unit* who) override
            {
                if (me->Attack(who, true))
                    DoStartNoMovement(who);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (TryToGetClose(me->GetVictim()))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHOT:
                            DoShot();
                            events.ScheduleEvent(EVENT_SHOT, TIMER_SHOT);
                            break;
                        case EVENT_MULTI_SHOT:
                            DoMultiShot();
                            events.ScheduleEvent(EVENT_MULTI_SHOT, TIMER_MULTI_SHOT);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        protected:

            virtual void DoAggro() override
            {
                me->SetReactState(REACT_AGGRESSIVE);

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                {
                    m_TargetGuid = target->GetGUID();

                    me->AddAura(SPELL_HUNTERS_MARK, target);
                    me->ClearUnitState(UNIT_STATE_CASTING);
                }

                events.ScheduleEvent(EVENT_SHOT, TIMER_SHOT_FIRST);
                events.ScheduleEvent(EVENT_MULTI_SHOT, TIMER_MULTI_SHOT_FIRST);
            }

            void DoShot()
            {
                if (Unit* target = ObjectAccessor::GetUnit(*me, m_TargetGuid))
                {
                    me->SetFacingToObject(target);
                    DoCast(target, SPELL_SHOT);
                }
            }

            void DoMultiShot()
            {
                if (Unit* target = ObjectAccessor::GetUnit(*me, m_TargetGuid))
                {
                    me->SetFacingToObject(target);
                    DoCast(target, SPELL_MULTI_SHOT);
                }
            }

        private:

            ObjectGuid m_TargetGuid;

        };
};

class npc_general_nazgrim_healing_tide_totem : public CreatureScript
{
    public:
        npc_general_nazgrim_healing_tide_totem() : CreatureScript("npc_general_nazgrim_healing_tide_totem") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_general_nazgrim_healing_tide_totemAI(creature);
        }

        struct npc_general_nazgrim_healing_tide_totemAI : public Scripted_NoMovementAI
        {
            npc_general_nazgrim_healing_tide_totemAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetControlled(true, UNIT_STATE_ROOT);

                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                me->AddAura(SPELL_HEALING_TIDE, me);
            }

            void UpdateAI(const uint32 diff) override
            {

            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_general_nazgrim_aftershock : public CreatureScript
{
    public:
        npc_general_nazgrim_aftershock() : CreatureScript("npc_general_nazgrim_aftershock") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_general_nazgrim_aftershockAI(creature);
        }

        struct npc_general_nazgrim_aftershockAI : public Scripted_NoMovementAI
        {
            npc_general_nazgrim_aftershockAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));
                me->SetReactState(REACT_PASSIVE);
            }

            void IsSummonedBy(Unit* owner)
            {
                if (InstanceScript* pInstance = me->GetInstanceScript())
                {
                    if (Creature* pNazgrim = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_GENERAL_NAZGRIM)))
                    {
                        if (boss_general_nazgrim::boss_general_nazgrimAI* nazgrimAI = CAST_AI(boss_general_nazgrim::boss_general_nazgrimAI, pNazgrim->GetAI()))
                        {
                            Position pos = nazgrimAI->GetLastHeroicShockwavePosition();

                            me->SetOrientation(me->GetAngle(&pos));
                            me->SetFacingTo(me->GetAngle(&pos));

                            DoCastAOE(SPELL_AFTERSHOCK);
                        }
                    }
                }
            }
        };
};

class npc_general_nazgrim_ravager : public CreatureScript
{
    public:
        npc_general_nazgrim_ravager() : CreatureScript("npc_general_nazgrim_ravager") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_general_nazgrim_ravagerAI(creature);
        }

        struct npc_general_nazgrim_ravagerAI : public ScriptedAI
        {
            npc_general_nazgrim_ravagerAI(Creature* creature) : ScriptedAI(creature),
                m_IsMoving(false), m_BeginMoveTimer(1000)
            {
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset()
            {
                me->SetSpeed(MOVE_RUN, 0.3f);
                me->AddAura(SPELL_RAVAGER_AURA, me);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (id == POINT_RAVAGER)
                {
                    me->GetMotionMaster()->MovementExpired(false);
                    Move();
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                BeginMoving(diff);
            }

        private:

            void BeginMoving(const uint32 diff)
            {
                if (m_IsMoving)
                    return;

                if (m_BeginMoveTimer <= diff)
                {
                    m_IsMoving = true;

                    Move();
                }
                else
                {
                    m_BeginMoveTimer -= diff;
                }
            }

            void Move()
            {
                Position pos;
                SelectRandomPosition(pos);

                me->GetMotionMaster()->MovePoint(POINT_RAVAGER, pos);
            }

            void SelectRandomPosition(Position& pos)
            {
                uint32 i = urand(0, RAVAGER_POSITIONS_COUNT-1);
                pos = ravagerPos[i];
            }

        private:

            uint32 m_BeginMoveTimer;
            bool m_IsMoving;
        };
};

class npc_general_nazgrim_korkron_banner : public CreatureScript
{
    public:
        npc_general_nazgrim_korkron_banner() : CreatureScript("npc_general_nazgrim_korkron_banner") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_general_nazgrim_korkron_bannerAI(creature);
        }

        struct npc_general_nazgrim_korkron_bannerAI : public Scripted_NoMovementAI
        {
            npc_general_nazgrim_korkron_bannerAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetControlled(true, UNIT_STATE_ROOT);
            }

            void Reset()
            {
                me->AddAura(SPELL_KORKRON_BANNER_AURA, me);
            }

            void JustDied(Unit* /*who*/) override
            {
                me->DespawnOrUnsummon(1000);
            }

            void UpdateAI(const uint32 diff) override
            {

            }
        };
};

class npc_general_nazgrim_orgrimmar_faithful : public CreatureScript
{
    public:
        npc_general_nazgrim_orgrimmar_faithful() : CreatureScript("npc_general_nazgrim_orgrimmar_faithful") { }

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_general_nazgrim_orgrimmar_faithfulAI(p_Creature);
        }

        struct npc_general_nazgrim_orgrimmar_faithfulAI : public ScriptedAI
        {
            npc_general_nazgrim_orgrimmar_faithfulAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            void Reset() override
            {
                me->SetReactState(REACT_DEFENSIVE);
                me->SetEmoteState(Emote::EMOTE_STATE_READY2H);
            }

            void EnterCombat(Unit* who) override
            {
                DoAggro();
            }

        private:

            void DoAggro()
            {
                if (InstanceScript* pInstance = me->GetInstanceScript())
                {
                    if (Creature* pNazgrim = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_GENERAL_NAZGRIM)))
                    {
                        if (pNazgrim->IsAlive() && !pNazgrim->IsInCombat())
                            DoZoneInCombat(pNazgrim, 100.f);
                    }
                }
            }
        };
};

class spell_general_nazgrim_sundering_blow : public SpellScriptLoader
{
    public:
        spell_general_nazgrim_sundering_blow() : SpellScriptLoader("spell_general_nazgrim_sundering_blow") { }

        class spell_general_nazgrim_sundering_blow_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_general_nazgrim_sundering_blow_SpellScript);

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                PreventHitDefaultEffect(effIndex);

                uint8 stacks = 1;

                if (Unit* victim = GetCaster()->GetVictim())
                {
                    if (auto aura = victim->GetAura(SPELL_SUNDERING_BLOW))
                    {
                        stacks = aura->GetStackAmount();
                    }
                }

                GetCaster()->EnergizeBySpell(GetCaster(), GetSpellInfo()->Id, 5 * stacks, NAZGRIM_POWER_TYPE);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_general_nazgrim_sundering_blow_SpellScript::HandleHitTarget, EFFECT_2, SPELL_EFFECT_ENERGIZE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_general_nazgrim_sundering_blow_SpellScript();
        }
};

class spell_general_nazgrim_heroic_shockwave_force : public SpellScriptLoader
{
    public:
        spell_general_nazgrim_heroic_shockwave_force() : SpellScriptLoader("spell_general_nazgrim_heroic_shockwave_force") { }

        class spell_general_nazgrim_heroic_shockwave_force_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_general_nazgrim_heroic_shockwave_force_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (Creature* pNazgrim = GetCaster()->ToCreature())
                {
                    std::list<Unit*> rangeTargets;

                    pNazgrim->AI()->SelectTargetList(rangeTargets, 2, SELECT_TARGET_RANDOM, -15.0f, true);

                    if (rangeTargets.size() < 2)
                    {
                        pNazgrim->AI()->SelectTargetList(rangeTargets, 2, SELECT_TARGET_RANDOM, 0.0f, true);
                    }

                    targets.clear();

                    for (auto target : rangeTargets)
                        targets.push_back(target);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_general_nazgrim_heroic_shockwave_force_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_general_nazgrim_heroic_shockwave_force_SpellScript();
        }
};

class spell_general_nazgrim_defensive_stance : public SpellScriptLoader
{
    public:
        spell_general_nazgrim_defensive_stance() : SpellScriptLoader("spell_general_nazgrim_defensive_stance") { }

        class spell_general_nazgrim_defensive_stance_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_general_nazgrim_defensive_stance_AuraScript);

            bool HandleCheckProc(ProcEventInfo& eventInfo)
            {
                if (Unit* attacker = eventInfo.GetActor())
                {
                    if (HasCooldown(attacker->GetGUID()))
                        return false;

                    AddCooldown(attacker->GetGUID());
                }
                return true;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* actor = eventInfo.GetActor();

                Unit* target = eventInfo.GetActionTarget();

                if (!actor || !target)
                    return;

                if (actor->HasAura(SPELL_SUNDERING_BLOW))
                    return;

                target->CastSpell(actor, SPELL_GENERATE_RAGE, true);
            }

            void Register()
            {
                DoCheckProc += AuraCheckProcFn(spell_general_nazgrim_defensive_stance_AuraScript::HandleCheckProc);
                OnEffectProc += AuraEffectProcFn(spell_general_nazgrim_defensive_stance_AuraScript::OnProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
            }

        private:

            // HACK: use this functions untill creatures have spell cooldown impletentation
            void AddCooldown(ObjectGuid guid)
            {

                /*uint64 currTime = 0;
                ACE_OS::gettimeofday().msec(currTime);
                m_Cooldowns[guid] = currTime + 1000;*/
            }

            bool HasCooldown(ObjectGuid guid)
            {
                /*if (m_Cooldowns.find(guid) == m_Cooldowns.end())
                    return false;

                uint64 currTime = 0;
                ACE_OS::gettimeofday().msec(currTime);
                bool hasCooldown = m_Cooldowns[guid] > currTime;*/

                bool hasCooldown = true;
                return hasCooldown;
            }

        private:

            std::map<ObjectGuid /*guid*/, uint64 /*time*/> m_Cooldowns;
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_general_nazgrim_defensive_stance_AuraScript();
        }
};

class spell_general_nazgrim_earth_shield : public SpellScriptLoader
{
    public:
        spell_general_nazgrim_earth_shield() : SpellScriptLoader("spell_general_nazgrim_earth_shield") { }

        class spell_general_nazgrim_earth_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_general_nazgrim_earth_shield_AuraScript);

            bool HandleCheckProc(ProcEventInfo& eventInfo)
            {
                if (HasCooldown())
                {
                    return false;
                }

                AddCooldown();
                return true;
            }

            void Register()
            {
                DoCheckProc += AuraCheckProcFn(spell_general_nazgrim_earth_shield_AuraScript::HandleCheckProc);
            }

        private:

            // HACK: use this functions untill creatures have spell cooldown impletentation
            void AddCooldown()
            {
                /*uint64 currTime = 0;
                ACE_OS::gettimeofday().msec(currTime);
                m_CooldownTime = currTime + 3000;*/
            }

            bool HasCooldown()
            {
                /*uint64 currTime = 0;
                ACE_OS::gettimeofday().msec(currTime);
                bool hasCooldown = m_CooldownTime > currTime;*/

                //need to fix
                bool hasCooldown = true;
                return hasCooldown;
            }

        private:

            uint64 m_CooldownTime = 0;
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_general_nazgrim_earth_shield_AuraScript();
        }
};

class spell_general_nazgrim_korkron_banner : public SpellScriptLoader
{
    public:
        spell_general_nazgrim_korkron_banner() : SpellScriptLoader("spell_general_nazgrim_korkron_banner") { }

        class spell_general_nazgrim_korkron_banner_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_general_nazgrim_korkron_banner_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                // HACK:
                // Override this effect because default effect summon a banner as guardian. Guardians have special stat calcutation (level, health) that depends on it's owner. We don't need it.

                PreventHitDefaultEffect(effIndex);

                WorldLocation* dest = GetHitDest();

                GetCaster()->SummonCreature(NPC_KORKRON_BANNER, *dest, TEMPSUMMON_TIMED_DESPAWN, 60000);
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_general_nazgrim_korkron_banner_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_general_nazgrim_korkron_banner_SpellScript();
        }
};

class spell_general_nazgrim_unstable_blink : public SpellScriptLoader
{
    public:
        spell_general_nazgrim_unstable_blink() : SpellScriptLoader("spell_general_nazgrim_unstable_blink") { }

        class spell_general_nazgrim_unstable_blink_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_general_nazgrim_unstable_blink_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                Unit* caster = GetCaster();

                PreventHitDefaultEffect(effIndex);

                if (!caster)
                    return;

                Position blinkPos;
                float angle = frand(0, 2 * float(M_PI));
                blinkPos.m_positionX = centerOfRoomPos.GetPositionX() + DISTANCE_FROM_CENTER * std::cos(angle);
                blinkPos.m_positionY = centerOfRoomPos.GetPositionY() + DISTANCE_FROM_CENTER * std::sin(angle);
                blinkPos.m_positionZ = centerOfRoomPos.GetPositionZ() + 1.f;
                blinkPos.SetOrientation(caster->GetOrientation());

                WorldLocation loc = *GetExplTargetDest();
                loc.Relocate(blinkPos);
                SetExplTargetDest(loc);
                GetHitDest()->Relocate(blinkPos);

                caster->NearTeleportTo(blinkPos.GetPositionX(), blinkPos.GetPositionY(), blinkPos.GetPositionZ(), blinkPos.GetOrientation());
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_general_nazgrim_unstable_blink_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_LEAP);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_general_nazgrim_unstable_blink_SpellScript();
        }
};

void AddSC_boss_general_nazgrim()
{
    new boss_general_nazgrim();                         // 71515

    new npc_general_nazgrim_korkron_ironblade();        // 71516
    new npc_general_nazgrim_korkron_arcweaver();        // 71517
    new npc_general_nazgrim_korkron_assassin();         // 71518
    new npc_general_nazgrim_korkron_warshaman();        // 71519
    new npc_general_nazgrim_korkron_sniper();           // 71656
    new npc_general_nazgrim_healing_tide_totem();       // 71610
    new npc_general_nazgrim_aftershock();               // 71697
    new npc_general_nazgrim_ravager();                  // 71762
    new npc_general_nazgrim_korkron_banner();           // 71626
    new npc_general_nazgrim_orgrimmar_faithful();       // 71715

    new spell_general_nazgrim_sundering_blow();         // 143494
    new spell_general_nazgrim_heroic_shockwave_force(); // 143713
    new spell_general_nazgrim_defensive_stance();       // 143593
    new spell_general_nazgrim_earth_shield();           // 143475
    new spell_general_nazgrim_korkron_banner();         // 143501
    new spell_general_nazgrim_unstable_blink();         // 143433
}
