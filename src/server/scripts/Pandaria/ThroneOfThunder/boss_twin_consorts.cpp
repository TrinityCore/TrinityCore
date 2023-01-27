#include "throne_of_thunder.h"
#include "GameObject.h"
#include "PhaseShift.h"
#include "PhasingHandler.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Creatures
{
    NPC_SUEN = 68904,
    NPC_LURKERS = 69591,
    NPC_BEAST_OF_NIGHTMARES = 69479,
    NPC_MELT_ICE_TRIGGER = 999294,
    NPC_MOON_LOTUS = 69340, // main summoner
    NPC_MOON_LOTUS_MOVE = 69456, // MOVER
    NPC_STAR = 69365,
    NPC_ICE_COMET = 69704,

    NPC_CHI_JI = 69774,
    NPC_NIUZAO = 69777,
    NPC_XUEN = 69771,
    NPC_YU_LON = 69779,
     
    // Serpent Constellation
    NPC_YULON_CONSTELATION_CORRECT_1 = 999295,
    NPC_YULON_CONSTELATION_CORRECT_2 = 999296,
    NPC_YULON_CONSTELATION_CORRECT_3 = 999297,
    NPC_YULON_CONSTELATION_CORRECT_4 = 999298,
    NPC_YULON_CONSTELATION_CORRECT_5 = 999299,
    NPC_YULON_CONSTELATION_FAIL_6 = 999368,
    NPC_YULON_CONSTELATION_FAIL_7 = 999369,

    // Ox Constellation
    NPC_NIUZAO_CONSTELLATION_CORRECT_1 = 999449,
    NPC_NIUZAO_CONSTELLATION_CORRECT_2 = 999450,
    NPC_NIUZAO_CONSTELLATION_CORRECT_3 = 999451,
    NPC_NIUZAO_CONSTELLATION_CORRECT_4 = 999457,
    NPC_NIUZAO_CONSTELLATION_CORRECT_5 = 999458,
    NPC_NIUZAO_CONSTELLATION_FAIL_6 = 999459,
    NPC_NIUZAO_CONSTELLATION_FAIL_7 = 999460,

    // Tiger Constellation
    NPC_XUEN_CONSTELLATION_CORRECT_1 = 999461,
    NPC_XUEN_CONSTELLATION_CORRECT_2 = 999462,
    NPC_XUEN_CONSTELLATION_CORRECT_3 = 999463,
    NPC_XUEN_CONSTELLATION_CORRECT_4 = 999464,
    NPC_XUEN_CONSTELLATION_CORRECT_5 = 999465,
    NPC_XUEN_CONSTELLATION_CORRECT_6 = 999466,
    NPC_XUEN_CONSTELLATION_FAIL_7 = 999467,
    NPC_XUEN_CONSTELLATION_FAIL_8 = 999468,

    // Crane Constellation
    NPC_CHIJI_CONSTELLATION_CORRECT_1 = 999471,
    NPC_CHIJI_CONSTELLATION_CORRECT_2 = 999472,
    NPC_CHIJI_CONSTELLATION_CORRECT_3 = 999473,
    NPC_CHIJI_CONSTELLATION_CORRECT_4 = 999474,
    NPC_CHIJI_CONSTELLATION_CORRECT_5 = 999475,
    NPC_CHIJI_CONSTELLATION_CORRECT_6 = 999476,
    NPC_CHIJI_CONSTELLATION_FAIL_7 = 999477,
    NPC_CHIJI_CONSTELLATION_FAIL_8 = 999478,

    NPC_CRANE_RUSH_TRIGGER = 999479,

    NPC_TWIN_CONSORTS_CONTROLER = 999480,
    NPC_TIDAL_FORCE_SLOWER = 999481,
};

// player is teleported at: 6198.65f, 4214.27f, 146.50f, 2.34f
Position const ConstellationPoints[7] =
{
    { 6173.21f, 4240.08f, 146.53f, 0.42f }, // center
    { 6195.01f, 4238.06f, 146.49f, 2.28f }, // right bot
    { 6188.42f, 4255.24f, 146.48f, 2.29f }, // right middle
    { 6173.65f, 4260.87f, 146.48f, 4.30f }, // right top
    { 6157.13f, 4224.27f, 146.48f, 3.85f }, // left middle
    { 6171.67f, 4217.34f, 146.49f, 5.26f }, // left bot
    { 6151.36f, 4236.38f, 146.48f, 3.82f }, // left top
};

Position const Tiger[1] =
{
    { 6239.10f, 4247.66f, 151.44f, 3.23f },
};

Position const Serpent[1] =
{
    { 6164.72f, 4169.63f, 150.62f, 1.46f },
};

Position const Ox[1] =
{
    { 6104.25f, 4230.80f, 150.516f, 0.12f },
};

Position const Crane[1] =
{
    { 6181.09f, 4307.19f, 150.76f, 4.69f },
};

enum Spells
{
    // Celestial
    SPELL_RED_SHADOWY = 138065,
    SPELL_BLUE_SHADOWY = 138059,
    SPELL_GREEN_SHADOWY = 138071,
    SPELL_YELLOW_SHADOWY = 138069,

    SPELL_TIGERS_CELERITY = 146296, // maybe 138656 ? 
    SPELL_SERPENTS_VITALITY = 138306,
    SPELL_A_RUSH_OF_CRANES = 144470, // 500 ms summon
    SPELL_A_RUSH_OF_CRANES_SUMMON = 144495, // morph into 46475
    SPELL_CRANE_RUSH_AREATRIGGER = 138314,
    SPELL_CRANE_RUSH_DAMAGE = 138318, // damaging spell
    SPELL_FORTITUDE_OF_THE_OX = 138300,

    // Lu'lin
    SPELL_MOON_LOTUS = 136690,
    //SPELL_MOON_LOTUS_INVISIBLE = 137192,
    SPELL_MOON_LOTUS_ACTIVATE = 137118,
    SPELL_MOON_LOTUS_EFFECT = 136722, // sleep 
    SPELL_MOON_LOTUS_VISUAL = 137192,
    SPELL_MOON_LOTUS_AT_EFFECT = 136721, // npc trigger 0.4 speed

    SPELL_COSMIC_BARRAGE = 136752,

    SPELL_BEAST_OF_NIGHTMARES = 137341, // aura on player

    SPELL_CORRUPTED_HEALING = 137360,

    SPELL_CRASHING_STAR = 137129,

    SPELL_ICE_COMET = 137418,
    SPELL_ICY_SHADOWS = 137440, // debuff
    SPELL_ICY_SHADOWS_AT = 137439,
    SPELL_ICE_COMENT_VISUAL = 137420,

    SPELL_TIDAL_FORCE = 137531,
    SPELL_TIDAL_FORCE_DAMAGE = 137716,
    SPELL_TIDAL_FORCE_EFFECT = 137718,

    SPELL_TIDAL_FORCE_WAVE = 140863,

    // Suen
    SPELL_FAN_OF_FLAMES = 137408,

    SPELL_FLAMES_OF_PASSION = 137412,
    SPELL_FLAMES_OF_PASSION_PERIODIC = 137417, // area trigger spell ? 137416 > area persistant damage

    SPELL_BLAZING_RADIANCE = 137410, // damage
    SPELL_BLAZING_RADIANCE_STACK_DAMAGE = 139412, // periodic damage updater

    SPELL_LIGHT_OF_DAY = 138822,

    SPELL_TEARS_OF_THE_SUN = 137404,
    SPELL_LIGHT_OF_DAY_DARK = 137401,
    SPELL_TEARS_OF_THE_SUN_PERIODIC = 137405,

    SPELL_NUCLEAR_INFERNO = 137491,
    SPELL_NUCLEAR_INFERNO_DAMAGE = 137492,

    // Celestials
    SPELL_CELESTIAL_BEAM = 138206,

    SPELL_TIGER_CONSTELLATION = 138261,
    SPELL_OX_CONSTELLATION = 138260,
    SPELL_CRANE_CONSTELLATION = 138180,
    SPELL_SERPENT_CONSTELLATION = 138262,

    SPELL_CONSTELLATION_UPDATED = 137138,
    SPELL_CONSTELLATION_STATIONARY = 138039,

    SPELL_CONSTELLATION_FAIL = 138933,
    SPELL_CONSTELATION_SUCCES = 138930,

    // drawings and screen effects
    SPELL_INVOKE_SERPENT_SPIRIT = 138267,
    SPELL_INVOKE_OX_SPIRIT = 138254,
    SPELL_INVOKE_CRANE_SPIRIT = 138189,
    SPELL_INVOKE_TIGER_SPIRIT = 138264,

    // LURKERS
    SPELL_DARKNESS = 137382,
    SPELL_SHADOWED_VISUAL = 111705,
};

enum Events
{
    EVENT_MOON_LOTUS = 1,
    EVENT_COSMIC_BARRAGE,
    EVENT_BEAST_OF_NIGHTMARES,
    EVENT_SUMMON_LURKERS, // heroic only
    EVENT_TEARS_OF_THE_SUN,
    EVENT_TEARS_DONE,
    EVENT_LIGHT_OF_DAY_DARK,
    EVENT_CAST_DARKNESS,

    EVENT_FAN_OF_FLAMES,
    EVENT_ALREADY_A_PLAYERS,
    EVENT_FLAMES_OF_PASSION,
    EVENT_LIGHT_OF_DAY,
    EVENT_NUCLEAR_INFERNO,
    EVENT_FLAMES_OF_PASSION_FLAME,
    EVENT_STAR_ATTACK,
    EVENT_BLAZING_RADIANCE,
    EVENT_NUCLEAR_INFERNO_CLEAN,
    EVENT_MAKE_A_RUN,
    EVENT_SELECT_ORIENTATION_AND_RUSH,
    EVENT_ICE_COMET,
    EVENT_ICY_SHADOWS,

    EVENT_TIDAL_FORCE,
    EVENT_REMOVE_STACKS,
    EVENT_CHECK_ACTIVE,
    EVENT_SHUFFLE_ORIENTATION_AND_MOVE,
    EVENT_CHECK_PROXIMITY_PLAYERS,
    EVENT_SUMMON_AT,

    EVENT_DARKNESS_PHASE,
    EVENT_ICE_COMET_DUSK,
    EVENT_DAYLIGHT_PHASE,

    EVENT_BERSERK,
};

enum Actions
{
    ACTION_DARK_PHASE_LULIN = 2,

    ACTION_DAYLIGHT_PHASE_SUEN = 3,

    ACTION_DUSK = 4,

    ACTION_NO_LONGER_DARKNESS = 5,
    ACTION_DARKNESS = 6,

    ACTION_RESET_POINTS = 7,
    ACTION_ACTIVE_POINTS = 8,
    ACTION_CONSTELLATION_COMPLETE = 9,
    ACTION_PLAYER_IN_ROOM = 10,

    ACTION_LURKER_VISIBLE = 11,
    ACTION_LURKER_INVISIBLE = 12,

    ACTION_DUSK_END = 13,

    ACTION_BOSS_TIMERS_START = 14,
    ACTION_BOSS_TIMERS_DONE = 15,
    ACTION_BOSS_TIMERS_WIPE = 16,

    ACTION_RESET_CELESTIALS_DUSK = 17,
};

Position const MoonLotus[10] =
{
    { 6161.84f, 4197.94f, 146.48f, 2.99f },
    { 6135.09f, 4220.55f, 146.48f, 2.37f },
    { 6226.12f, 4245.04f, 146.47f, 4.32f },
    { 6133.09f, 4247.90f, 146.48f, 1.88f },
    { 6200.98f, 4276.29f, 146.48f, 5.74f },
    { 6186.13f, 4191.75f, 146.48f, 0.60f },
    { 6152.28f, 4282.76f, 146.48f, 0.91f },
    { 6156.41f, 4207.16f, 146.48f, 0.81f },
    { 6201.08f, 4213.95f, 146.50f, 4.21f },
};

Position const Lurkers[20] =
{
    { 6207.62f, 4230.40f, 146.49f, 3.01f },
    { 6220.99f, 4245.38f, 146.47f, 3.21f },
    { 6218.58f, 4262.52f, 146.47f, 3.43f },
    { 6200.75f, 4266.97f, 146.47f, 2.92f },
    { 6197.43f, 4281.36f, 146.47f, 2.00f },
    { 6182.48f, 4292.10f, 146.47f, 2.93f },
    { 6136.79f, 4275.58f, 146.58f, 3.98f },
    { 6160.55f, 4283.81f, 146.48f, 3.50f },
    { 6140.35f, 4208.22f, 146.48f, 4.90f },
    { 6124.44f, 4258.12f, 146.48f, 4.56f },
    { 6162.56f, 4190.71f, 146.48f, 5.61f },
    { 6137.44f, 4222.84f, 146.48f, 5.98f },
    { 6175.06f, 4201.31f, 146.48f, 0.70f },
    { 6127.47f, 4235.93f, 146.48f, 4.85f },
    { 6157.91f, 4190.52f, 146.48f, 2.63f },
    { 6171.56f, 4182.95f, 146.48f, 4.52f },
    { 6114.61f, 4228.38f, 146.48f, 3.67f },
    { 6200.27f, 4213.42f, 146.50f, 0.78f },
    { 6204.39f, 4229.03f, 146.49f, 2.79f },
    { 6222.84f, 4222.43f, 146.48f, 2.00f },
};

enum Timers
{
    TIMER_IMMEDIATE = 0,

    TIMER_DARKNESS_PHASE = 3 * IN_MILLISECONDS * MINUTE, // change to daylight
    TIMER_DAYLIGHT_PHASE = 3 * IN_MILLISECONDS * MINUTE, // change to dusk

    TIMER_BERSERK = 10 * IN_MILLISECONDS * MINUTE,

    // DARK PHASE

    // Suen in dark
    TIMER_TEARS_OF_THE_SUN = 40 * IN_MILLISECONDS,
    TIMER_LIGHT_OF_DAY = 20 * IN_MILLISECONDS,

    // Lulin in dark
    TIMER_MOON_LOTUS = 32 * IN_MILLISECONDS,
    TIMER_COSMIC_BARRAGE = 20 * IN_MILLISECONDS,
    TIMER_BEAST_OF_NIGHTMARE = 50 * IN_MILLISECONDS,

    // HEROIC
    TIMER_LURKERS = 15 * IN_MILLISECONDS,

    // DAY PHASE

    // Suen in day
    TIMER_FAN_OF_FLAMES = 25 * IN_MILLISECONDS,
    TIMER_FLAMES_OF_PASSION = 35 * IN_MILLISECONDS,
    TIMER_BLAZING_RADIANCE = 2 * IN_MILLISECONDS,

    // Lulin in day
    TIMER_ICE_COMET = 15 * IN_MILLISECONDS,

    // DUSK

    // Suen
    TIMER_NUCLEAR_INFERNO = 50 * IN_MILLISECONDS,

    // Lulin
    TIMER_TIDAL_FORCE = 15 * IN_MILLISECONDS,
    TIMER_TIDAL_FORCE_SECOND = 40 * IN_MILLISECONDS,
};

enum Points
{
    POINT_FLAME = 1,
};

struct IsActive : public std::unary_function<Unit*, bool>
{
    IsActive() {}

    bool operator() (const Unit* pTarget)
    {
        return pTarget->HasAura(SPELL_MOON_LOTUS_VISUAL);
    }
};

enum Talks
{
    // Suen
    TALK_S_AGGRO = 1,
    TALK_S_PHASE_2 = 2,
    TALK_S_PHASE_3 = 3,
    TALK_S_FLAMES = 4,
    TALK_S_WIPE = 5,

    // Lu'lin
    TALK_L_AGGRO = 1,
    TALK_L_PHASE_1 = 2,
    TALK_L_PHASE_3 = 3,
    TALK_L_WIPE = 5,
};

struct isCompleted : public std::unary_function<Unit*, bool>
{
    isCompleted() {}

    bool operator() (const Unit* pTarget)
    {
        return !pTarget->HasNpcFlag(UNIT_NPC_FLAG_GOSSIP);
    }
};

uint8 TwinActive(InstanceScript* instance, Creature* me)
{
    uint8 count = 0;
    if (!instance || !me)
        return count;

    Creature* lulin = instance->GetCreature(instance->GetData64(NPC_LULIN));
    if (lulin && lulin->IsAlive())
        ++count;

    Creature* suen = instance->GetCreature(instance->GetData64(NPC_SUEN));
    if (suen && suen->IsAlive())
        ++count;

    return count;
}

Position const centerPoint = { 6172.89f, 4239.58f, 146.54f, 0.0f };

class bfa_boss_suen : public CreatureScript
{
public:
    bfa_boss_suen() : CreatureScript("bfa_boss_suen") { }

    struct bfa_boss_suenAI : public ScriptedAI
    {
        bfa_boss_suenAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
            me->ApplySpellImmune(0, IMMUNITY_ID, 31935, true); // Avenger's Shield
        }

        EventMap events;
        bool night;
        uint8 flames;
        bool NuclearInferno;
        bool isFinalPhase;
        InstanceScript* instance;

        void Reset()
        {
            flames = 0;
            isFinalPhase = false;
            NuclearInferno = false;
            night = false;
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->RestoreDisplayId();
            events.Reset();
        }

        Creature* Lulin()
        {
            return me->FindNearestCreature(NPC_LULIN, 500.0f, true);
        }

        Creature* LulinDead()
        {
            return me->FindNearestCreature(NPC_LULIN, 500.0f, false);
        }

        void EnterEvadeMode(EvadeReason why)
        {
            if (Creature* lulin = LulinDead())
            {
                lulin->Respawn();
            }

            Talk(TALK_S_WIPE);
            ActivateObjects();
            DespawnCreature(NPC_MOON_LOTUS);
            DespawnCreature(NPC_MOON_LOTUS_MOVE);
            DespawnCreature(NPC_BEAST_OF_NIGHTMARES);
            DespawnCreature(NPC_ICE_COMET);
            DespawnCreature(NPC_YU_LON);
            DespawnCreature(NPC_XUEN);
            DespawnCreature(NPC_CHI_JI);
            DespawnCreature(NPC_NIUZAO);
            DespawnCreature(NPC_LURKERS);
            if (instance)
                instance->SetBossState(DATA_TWIN_CONSORTS, FAIL);
            if (Creature* twinconsorts = GetTwinConsortsControler())
                twinconsorts->AI()->DoAction(ACTION_BOSS_TIMERS_WIPE);
        }

        Creature* GetTwinConsortsControler()
        {
            return me->FindNearestCreature(NPC_TWIN_CONSORTS_CONTROLER, 500.0f, true);
        }

        void RewardCurrencyAndUpdateState()
        {
        }

        void JustDied(Unit*)
        {
            if (Creature* lulin = Lulin())
            {
                lulin->AI()->DoAction(ACTION_DUSK_END);
                lulin->AI()->DoAction(ACTION_DARK_PHASE_LULIN);
            }
            if (isFinalPhase)
            {
                if (Creature* twinconsorts = GetTwinConsortsControler())
                    twinconsorts->AI()->DoAction(ACTION_BOSS_TIMERS_DONE);
                DespawnCreature(NPC_MOON_LOTUS);
                DespawnCreature(NPC_MOON_LOTUS_MOVE);
                DespawnCreature(NPC_BEAST_OF_NIGHTMARES);
                DespawnCreature(NPC_ICE_COMET);
                DespawnCreature(NPC_YU_LON);
                DespawnCreature(NPC_XUEN);
                DespawnCreature(NPC_CHI_JI);
                DespawnCreature(NPC_NIUZAO);
                DespawnCreature(NPC_LURKERS);
                DeactivateObjects();
            }

            if (instance)
            {
                Creature* lulin = instance->GetCreature(instance->GetData64(NPC_LULIN));
                Creature* suen = instance->GetCreature(instance->GetData64(NPC_SUEN));

                switch (TwinActive(instance, me))
                {
                case 1:
                    me->ResetLootRecipients();
                    break;
                case 0:
                    if (instance)
                    {
                        instance->SetBossState(DATA_TWIN_CONSORTS, DONE);
                        RewardCurrencyAndUpdateState();
                    }
                    break;
                default:
                    break;
                }
            }
        }

        void LurkersActive()
        {
            std::list<Creature*> Lurks;
            me->GetCreatureListWithEntryInGrid(Lurks, NPC_LURKERS, 500.0f);

            if (Lurks.empty())
                return;
            for (auto it = Lurks.begin(); it != Lurks.end(); ++it)
            {
                Creature* creature = *it;
                creature->AI()->DoAction(ACTION_LURKER_VISIBLE);
            }
        }

        void DespawnCreature(uint32 entry)
        {
            std::list<Creature*> creatureList;
            GetCreatureListWithEntryInGrid(creatureList, me, entry, 500.0f);
            if (!creatureList.empty())
                for (auto NowCreature : creatureList)
                    NowCreature->DespawnOrUnsummon();
        }

        void ExposeLurkers()
        {
            std::list<Creature*> Lurks;
            me->GetCreatureListWithEntryInGrid(Lurks, NPC_LURKERS, 500.0f);

            if (Lurks.empty())
                return;
            for (auto it = Lurks.begin(); it != Lurks.end(); ++it)
            {
                Creature* creature = *it;
                if (me->GetDistance(creature) < 11.0f)
                    creature->AI()->DoAction(ACTION_LURKER_VISIBLE);
            }
        }

        void DeactivateObjects()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, 218711, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, 218712, 500.0f);
            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_ACTIVE);
        }

        void ActivateObjects()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, 218712, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, 218711, 500.0f);
            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_READY);
        }

        void EnterCombat(Unit*)
        {
            Talk(TALK_S_AGGRO);
            if (Creature* lulin = Lulin())
            {
                if (lulin->HasAura(9454))
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            if (player->IsAlive())
                                player->Kill(player);
                    return;
                }
            }

            night = true;
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetDisplayId(22452);
            events.ScheduleEvent(EVENT_TEARS_OF_THE_SUN, TIMER_TEARS_OF_THE_SUN);
            events.ScheduleEvent(EVENT_LIGHT_OF_DAY_DARK, TIMER_LIGHT_OF_DAY);
            if (Creature* lulin = Lulin())
                lulin->SetInCombatWithZone();
        }

        void ResetCelestials()
        {
            std::list<Creature*> celestials;
            me->GetCreatureListWithEntryInGrid(celestials, NPC_CHI_JI, 500.0f);
            me->GetCreatureListWithEntryInGrid(celestials, NPC_YU_LON, 500.0f);
            me->GetCreatureListWithEntryInGrid(celestials, NPC_XUEN, 500.0f);
            me->GetCreatureListWithEntryInGrid(celestials, NPC_NIUZAO, 500.0f);

            if (!celestials.empty())
                for (auto it = celestials.begin(); it != celestials.end(); ++it)
                {
                    Creature* Celestial = *it;
                    Celestial->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);
                    Celestial->AI()->DoAction(ACTION_RESET_CELESTIALS_DUSK);
                }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_DAYLIGHT_PHASE_SUEN:
            {
                Talk(TALK_S_PHASE_2);
                LurkersActive();
                me->RestoreDisplayId();
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                night = false;
                events.Reset();
                events.ScheduleEvent(EVENT_DAYLIGHT_PHASE, TIMER_DAYLIGHT_PHASE);
                events.ScheduleEvent(EVENT_FAN_OF_FLAMES, TIMER_FAN_OF_FLAMES);
                events.ScheduleEvent(EVENT_FLAMES_OF_PASSION, TIMER_FLAMES_OF_PASSION);
                events.ScheduleEvent(EVENT_LIGHT_OF_DAY, TIMER_LIGHT_OF_DAY);
                events.ScheduleEvent(EVENT_BLAZING_RADIANCE, TIMER_BLAZING_RADIANCE);
                if (me->GetMap()->IsHeroic())
                    events.ScheduleEvent(EVENT_NUCLEAR_INFERNO, 41 * IN_MILLISECONDS);
                break;
            }
            case ACTION_DUSK:
                Talk(TALK_S_PHASE_3);
                me->RestoreDisplayId();
                night = false;
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                events.Reset();
                ResetCelestials();
                me->RemoveAura(SPELL_BLAZING_RADIANCE);
                if (me->GetMap()->IsHeroic())
                    events.ScheduleEvent(EVENT_NUCLEAR_INFERNO, TIMER_NUCLEAR_INFERNO);
                break;
            case ACTION_DUSK_END:
                isFinalPhase = true;
                break;
            }
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            if (me->HasAura(SPELL_NUCLEAR_INFERNO))
            {
                damage = 0;
                me->SetHealth(me->GetHealth() + 1);
                me->SetHealth(me->GetHealth() - 1);
            }
        }

        void CheckFlames()
        {
            ++flames;

            if (flames < 5)
            {
                //bfa_SendWorldText("flames count = %d", flames);
                events.ScheduleEvent(EVENT_FLAMES_OF_PASSION_FLAME, 1000);
            }

            if (flames >= 5)
            {
                events.CancelEvent(EVENT_FLAMES_OF_PASSION_FLAME);
                me->RemoveAura(137416);
                flames = 0;
            }
        }

        void CheckBoundary()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            if (!playerList.isEmpty())
                for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                    if (Player* player = itr->GetSource())
                        if (!player->IsGameMaster())
                            if (me->GetDistance2d(centerPoint.m_positionX, centerPoint.m_positionY) > 65.0f)
                            {
                                me->Kill(player, false);
                                break;
                            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (me->IsInCombat())
                CheckBoundary();

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_DAYLIGHT_PHASE:
                    me->AI()->DoAction(ACTION_DUSK);
                    if (Creature* lulin = Lulin())
                        lulin->AI()->DoAction(ACTION_DUSK);
                    break;
                case EVENT_FAN_OF_FLAMES:
                    Talk(TALK_S_FLAMES);
                    me->CastSpell(me->GetVictim(), SPELL_FAN_OF_FLAMES);
                    events.ScheduleEvent(EVENT_FAN_OF_FLAMES, TIMER_FAN_OF_FLAMES);
                    break;
                case EVENT_FLAMES_OF_PASSION:
                    if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 500.0f, true))
                    {
                        me->CastSpell(target, 137414, true); // flames of passion damage
                        me->GetMotionMaster()->MoveJump(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 35.0f, 30.0f, 0);
                        events.ScheduleEvent(EVENT_FLAMES_OF_PASSION_FLAME, 1500);
                        //me->CastSpell(target, SPELL_FLAMES_OF_PASSION);
                    }
                    events.ScheduleEvent(EVENT_FLAMES_OF_PASSION, TIMER_FLAMES_OF_PASSION);
                    break;
                case EVENT_FLAMES_OF_PASSION_FLAME:
                    CheckFlames();
                    me->CastSpell(me, 137416, true);
                    break;
                case EVENT_LIGHT_OF_DAY:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    {
                        me->CastSpell(target, SPELL_LIGHT_OF_DAY);
                        me->SummonCreature(NPC_MELT_ICE_TRIGGER, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 6000);
                    }
                    events.ScheduleEvent(EVENT_LIGHT_OF_DAY, TIMER_LIGHT_OF_DAY);
                    break;
                case EVENT_BLAZING_RADIANCE:
                    me->CastSpell(me, SPELL_BLAZING_RADIANCE, true);
                    me->AddAura(SPELL_BLAZING_RADIANCE_STACK_DAMAGE, me);
                    events.ScheduleEvent(EVENT_BLAZING_RADIANCE, TIMER_BLAZING_RADIANCE);
                    break;
                case EVENT_LIGHT_OF_DAY_DARK:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    {
                        me->NearTeleportTo(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), false);
                        me->CastSpell(target, SPELL_LIGHT_OF_DAY_DARK);
                    }
                    events.ScheduleEvent(EVENT_LIGHT_OF_DAY_DARK, 20000);
                    break;
                case EVENT_TEARS_OF_THE_SUN:
                    me->RestoreDisplayId();
                    me->CastSpell(me, SPELL_TEARS_OF_THE_SUN);
                    me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    ExposeLurkers();
                    events.ScheduleEvent(EVENT_TEARS_DONE, 10000);
                    break;
                case EVENT_TEARS_DONE:
                    me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                    me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                    me->SetDisplayId(22452);
                    events.ScheduleEvent(EVENT_TEARS_OF_THE_SUN, TIMER_TEARS_OF_THE_SUN);
                    break;
                case EVENT_NUCLEAR_INFERNO:
                {
                    if (Creature* lulin = Lulin())
                    {
                        if (lulin->IsAlive())
                        {
                            if (!lulin->HasAura(SPELL_TIDAL_FORCE))
                            {
                                NuclearInferno = true;
                                me->CastSpell(me, SPELL_NUCLEAR_INFERNO);
                            }
                        }
                    }
                    events.ScheduleEvent(EVENT_NUCLEAR_INFERNO, TIMER_NUCLEAR_INFERNO);
                    events.ScheduleEvent(EVENT_NUCLEAR_INFERNO_CLEAN, 8000);
                    break;
                }
                case EVENT_NUCLEAR_INFERNO_CLEAN:
                    NuclearInferno = false;
                    break;
                }
            }
            if (!night)
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_boss_suenAI(creature);
    }
};

class bfa_boss_lulin : public CreatureScript
{
public:
    bfa_boss_lulin() : CreatureScript("bfa_boss_lulin") { }

    struct bfa_boss_lulinAI : public ScriptedAI
    {
        bfa_boss_lulinAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_ID, 31935, true); // Avenger's Shield
            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
        }

        EventMap events;
        bool alreadyActive;
        bool daylight;
        bool isFinalPhase;
        InstanceScript* instance;

        void Reset()
        {
            daylight = false;
            alreadyActive = false;
            isFinalPhase = false;
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->RestoreDisplayId();
            events.Reset();
            DespawnCreature(NPC_MOON_LOTUS);
            DespawnCreature(NPC_MOON_LOTUS_MOVE);
            DespawnCreature(NPC_BEAST_OF_NIGHTMARES);
            DespawnCreature(NPC_ICE_COMET);
            DespawnCreature(NPC_YU_LON);
            DespawnCreature(NPC_XUEN);
            DespawnCreature(NPC_CHI_JI);
            DespawnCreature(NPC_NIUZAO);
            DespawnCreature(NPC_LURKERS);
        }

        void RemoveBeastsDebuff()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(SPELL_BEAST_OF_NIGHTMARES);
                }
        }

        void CorrectPhase()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {

                    PhasingHandler::AddPhase(player, 1, false);
                }
        }

        Creature* suenDead()
        {
            return me->FindNearestCreature(NPC_SUEN, 500.0f, false);
        }

        void RewardCurrencyAndUpdateState()
        {
        }

        void JustDied(Unit*)
        {
            CorrectPhase(); // just to be sure
            RemoveBeastsDebuff();
            if (Creature* suen = Suen())
            {
                suen->AI()->DoAction(ACTION_DAYLIGHT_PHASE_SUEN);
                suen->AI()->DoAction(ACTION_DUSK_END);
            }
            if (isFinalPhase)
            {
                if (Creature* twinconsorts = GetTwinConsortsControler())
                    twinconsorts->AI()->DoAction(ACTION_BOSS_TIMERS_DONE);
                DespawnCreature(NPC_MOON_LOTUS);
                DespawnCreature(NPC_MOON_LOTUS_MOVE);
                DespawnCreature(NPC_BEAST_OF_NIGHTMARES);
                DespawnCreature(NPC_ICE_COMET);
                DespawnCreature(NPC_YU_LON);
                DespawnCreature(NPC_XUEN);
                DespawnCreature(NPC_CHI_JI);
                DespawnCreature(NPC_NIUZAO);
                DespawnCreature(NPC_LURKERS);
                DeactivateObjects();
            }

            if (instance)
            {
                Creature* lulin = instance->GetCreature(instance->GetData64(NPC_LULIN));
                Creature* suen = instance->GetCreature(instance->GetData64(NPC_SUEN));

                switch (TwinActive(instance, me))
                {
                case 1:
                    me->ResetLootRecipients();
                    break;
                case 0:
                    if (instance)
                    {
                        instance->SetBossState(DATA_TWIN_CONSORTS, DONE);
                        RewardCurrencyAndUpdateState();
                    }
                    break;
                default:
                    break;
                }
            }
        }


        Creature* GetTwinConsortsControler()
        {
            return me->FindNearestCreature(NPC_TWIN_CONSORTS_CONTROLER, 500.0f, true);
        }

        void LurkersInactive()
        {
            std::list<Creature*> Lurks;
            me->GetCreatureListWithEntryInGrid(Lurks, NPC_LURKERS, 500.0f);

            if (Lurks.empty())
                return;
            for (auto it = Lurks.begin(); it != Lurks.end(); ++it)
            {
                Creature* creature = *it;
                creature->AI()->DoAction(ACTION_LURKER_INVISIBLE);
            }
        }

        void EnterEvadeMode(EvadeReason w)
        {
     
            DeactivateObjects();
            Talk(TALK_L_WIPE);
            if (Creature* suen = suenDead())
            {
                suen->Respawn();
            }
            RemoveBeastsDebuff();
            if (instance)
                instance->SetBossState(DATA_TWIN_CONSORTS, FAIL);
            if (Creature* twinconsorts = GetTwinConsortsControler())
            {
                twinconsorts->AI()->DoAction(ACTION_BOSS_TIMERS_WIPE);
            }
        }

        void ActivateObjects()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, 218712, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, 218711, 500.0f);
            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_READY);
        }

        void DeactivateObjects()
        {
            std::list<GameObject*> gList;
            me->GetGameObjectListWithEntryInGrid(gList, 218711, 500.0f);
            me->GetGameObjectListWithEntryInGrid(gList, 218712, 500.0f);
            if (!gList.empty())
                for (std::list<GameObject*>::const_iterator itr = gList.begin(); itr != gList.end(); ++itr)
                    (*itr)->SetGoState(GO_STATE_ACTIVE);
        }

        void EnterCombat(Unit*)
        {
            Talk(TALK_L_AGGRO);
            ActivateObjects();
            events.ScheduleEvent(EVENT_DARKNESS_PHASE, TIMER_DARKNESS_PHASE);
            daylight = false;
            if (Creature* suen = Suen())
                suen->SetInCombatWithZone();
            me->AI()->DoAction(ACTION_DARK_PHASE_LULIN);
            for (uint8 i = 0; i < 10; ++i)
            {
                me->SummonCreature(NPC_MOON_LOTUS, MoonLotus[i], TEMPSUMMON_MANUAL_DESPAWN);
            }
            SummonCelestials();

            if (Creature* twinconsorts = GetTwinConsortsControler())
            {
                twinconsorts->AI()->DoAction(ACTION_BOSS_TIMERS_START);
            }
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            if (me->HasAura(SPELL_TIDAL_FORCE))
            {
                damage = 0;
                me->SetHealth(me->GetHealth() + 1);
                me->SetHealth(me->GetHealth() - 1);
            }
        }

        void SummonCelestials()
        {
            me->SummonCreature(NPC_YU_LON, Serpent[0], TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_CHI_JI, Crane[0], TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_NIUZAO, Ox[0], TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_XUEN, Tiger[0], TEMPSUMMON_MANUAL_DESPAWN);
        }

        void DespawnCreature(uint32 entry)
        {
            std::list<Creature*> creatureList;
            GetCreatureListWithEntryInGrid(creatureList, me, entry, 500.0f);
            if (!creatureList.empty())
                for (auto NowCreature : creatureList)
                    NowCreature->DespawnOrUnsummon();
        }


        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_DUSK_END:
                alreadyActive = false;
                isFinalPhase = true;
                events.CancelEvent(EVENT_ICE_COMET_DUSK);
                break;
            case ACTION_DARK_PHASE_LULIN:
            {
                if (alreadyActive)
                    return;
                Talk(TALK_L_PHASE_1);
                alreadyActive = true;
                LotusBloom();
                LurkersInactive();
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->RestoreDisplayId();
                events.ScheduleEvent(EVENT_MOON_LOTUS, TIMER_MOON_LOTUS);
                events.ScheduleEvent(EVENT_COSMIC_BARRAGE, TIMER_COSMIC_BARRAGE);
                events.ScheduleEvent(EVENT_BEAST_OF_NIGHTMARES, TIMER_BEAST_OF_NIGHTMARE);
                if (me->GetMap()->IsHeroic())
                    events.ScheduleEvent(EVENT_SUMMON_LURKERS, TIMER_LURKERS);
                events.CancelEvent(EVENT_TIDAL_FORCE);
                break;
            }
            case ACTION_DAYLIGHT_PHASE_SUEN:
                LotusNoLongerBlooms();
                daylight = true;
                if (Creature* suen = Suen())
                    suen->AI()->DoAction(ACTION_DAYLIGHT_PHASE_SUEN);
                me->SetDisplayId(22452);
                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                events.Reset();
                events.ScheduleEvent(EVENT_ICE_COMET, TIMER_ICE_COMET);
                break;
            case ACTION_DUSK:
                Talk(TALK_L_PHASE_3);
                me->RestoreDisplayId();
                daylight = false;
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                events.Reset();
                events.ScheduleEvent(EVENT_TIDAL_FORCE, TIMER_TIDAL_FORCE);
                events.ScheduleEvent(EVENT_ICE_COMET_DUSK, 10 * IN_MILLISECONDS);
                break;
            }
        }

        void LotusNoLongerBlooms()
        {
            std::list<Creature*> Moons;
            me->GetCreatureListWithEntryInGrid(Moons, NPC_MOON_LOTUS, 500.0f);

            if (Moons.empty())
                return;
            for (auto it = Moons.begin(); it != Moons.end(); ++it)
            {
                Creature* creature = *it;
                creature->AI()->DoAction(ACTION_NO_LONGER_DARKNESS);
            }
        }

        void LotusBloom()
        {
            std::list<Creature*> Moons;
            me->GetCreatureListWithEntryInGrid(Moons, NPC_MOON_LOTUS, 500.0f);

            if (Moons.empty())
                return;
            for (auto it = Moons.begin(); it != Moons.end(); ++it)
            {
                Creature* creature = *it;
                creature->AI()->DoAction(ACTION_DARKNESS);
            }
        }

        void ActivateLotus()
        {
            std::list<Creature*> Moons;
            me->GetCreatureListWithEntryInGrid(Moons, NPC_MOON_LOTUS, 500.0f);

            Moons.remove_if(IsActive());

            if (Moons.empty())
                return;
            if (Moons.size() >= 1)
                Trinity::Containers::RandomResize(Moons, 1);
            for (auto it = Moons.begin(); it != Moons.end(); ++it)
            {
                Creature* creature = *it;
                me->CastSpell(creature, SPELL_MOON_LOTUS_ACTIVATE, true);
                creature->AddAura(SPELL_MOON_LOTUS_VISUAL, creature);
            }
        }

        Creature* Suen()
        {
            return me->FindNearestCreature(NPC_SUEN, 500.0f, true);
        }

        void CheckBoundary()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            if (!playerList.isEmpty())
                for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                    if (Player* player = itr->GetSource())
                        if (!player->IsGameMaster())
                            if (me->GetDistance2d(centerPoint.m_positionX, centerPoint.m_positionY) > 65.0f)
                            {
                                me->Kill(player, false);
                                break;
                            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (me->IsInCombat())
                CheckBoundary();

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_DARKNESS_PHASE:
                    me->AI()->DoAction(ACTION_DAYLIGHT_PHASE_SUEN);
                    break;
                case EVENT_ICE_COMET:
                {
                    if (Creature* suen = Suen())
                    {
                        if (suen->IsAlive())
                        {
                            if (CAST_AI(bfa_boss_suen::bfa_boss_suenAI, suen->AI())->NuclearInferno == false)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 1000.0f, true))
                                {
                                    me->NearTeleportTo(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), false);
                                    me->CastSpell(target, SPELL_ICE_COMET);
                                    me->SummonCreature(NPC_ICE_COMET, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                                }
                            }
                        }
                    }
                    events.ScheduleEvent(EVENT_ICE_COMET, TIMER_ICE_COMET);
                    break;
                }
                case EVENT_ICE_COMET_DUSK:
                {
                    if (Creature* suen = Suen())
                    {
                        if (suen->IsAlive())
                        {
                            if (CAST_AI(bfa_boss_suen::bfa_boss_suenAI, suen->AI())->NuclearInferno == false)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 1000.0f, true))
                                {
                                    //me->NearTeleportTo(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), false);
                                    me->CastSpell(target, SPELL_ICE_COMET);
                                    me->SummonCreature(NPC_ICE_COMET, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                                }
                            }
                        }
                    }
                    events.ScheduleEvent(EVENT_ICE_COMET_DUSK, TIMER_ICE_COMET);
                    break;
                }
                case EVENT_MOON_LOTUS:
                    ActivateLotus();
                    events.ScheduleEvent(EVENT_MOON_LOTUS, TIMER_MOON_LOTUS);
                    break;
                case EVENT_COSMIC_BARRAGE:
                    me->SummonCreature(NPC_STAR, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 3000);
                    me->CastSpell(me, SPELL_COSMIC_BARRAGE);
                    events.ScheduleEvent(EVENT_COSMIC_BARRAGE, TIMER_COSMIC_BARRAGE);
                    break;
                case EVENT_BEAST_OF_NIGHTMARES:
                {
                    Unit* target = me->GetVictim();
                    if (target->HasAura(SPELL_BEAST_OF_NIGHTMARES))
                        return;
                    me->AddAura(SPELL_BEAST_OF_NIGHTMARES, target);
                    if (Creature* beast = me->SummonCreature(NPC_BEAST_OF_NIGHTMARES, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        beast->AddThreat(target, 9999999.9f);
                        beast->AI()->AttackStart(target);
                    }
                    events.ScheduleEvent(EVENT_BEAST_OF_NIGHTMARES, TIMER_BEAST_OF_NIGHTMARE);
                    break;
                }
                case EVENT_TIDAL_FORCE:
                {
                    if (Creature* suen = Suen())
                    {
                        if (suen->IsAlive())
                            if (CAST_AI(bfa_boss_suen::bfa_boss_suenAI, suen->AI())->NuclearInferno == false)
                                me->CastSpell(me, SPELL_TIDAL_FORCE);
                    }
                    events.ScheduleEvent(EVENT_TIDAL_FORCE, TIMER_TIDAL_FORCE_SECOND);
                    break;
                }
                case EVENT_SUMMON_LURKERS:
                {
                    uint8 pos = urand(0, 19);

                    me->SummonCreature(NPC_LURKERS, Lurkers[pos], TEMPSUMMON_MANUAL_DESPAWN);
                    events.ScheduleEvent(EVENT_SUMMON_LURKERS, TIMER_LURKERS);
                    break;
                }
                }
            }
            if (!daylight)
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_boss_lulinAI(creature);
    }
};

class bfa_npc_beast_of_nightmare : public CreatureScript
{
public:
    bfa_npc_beast_of_nightmare() : CreatureScript("bfa_npc_beast_of_nightmare") { }

    struct bfa_npc_beast_of_nightmareAI : public ScriptedAI
    {
        bfa_npc_beast_of_nightmareAI(Creature* creature) : ScriptedAI(creature)
        {
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_THREAT, true);
        }

        void RemoveBeast()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(SPELL_BEAST_OF_NIGHTMARES);
                }
        }

        void JustDied(Unit*)
        {
            RemoveBeast();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_beast_of_nightmareAI(creature);
    }
};

// 69340
class bfa_npc_moon_lotus : public CreatureScript
{
public:
    bfa_npc_moon_lotus() : CreatureScript("bfa_npc_moon_lotus") { }

    struct bfa_npc_moon_lotusAI : public ScriptedAI
    {
        bfa_npc_moon_lotusAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFaction(7);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        EventMap events;
        bool bloom;

        void IsSummonedBy(Unit*)
        {
            events.ScheduleEvent(EVENT_CHECK_ACTIVE, 5000);
            bloom = true;
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_NO_LONGER_DARKNESS:
                bloom = false;
                break;
            case ACTION_DARKNESS:
                bloom = true;
                break;
            }
        }

        void Reset()
        {
            bloom = false;
            events.Reset();
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_ACTIVE:
                    if (me->HasAura(SPELL_MOON_LOTUS_VISUAL))
                    {
                        events.ScheduleEvent(EVENT_SUMMON_AT, 2000);
                        events.CancelEvent(EVENT_CHECK_ACTIVE);
                        break;
                    }
                    events.ScheduleEvent(EVENT_CHECK_ACTIVE, 3000);
                    break;
                case EVENT_SUMMON_AT:
                    if (bloom)
                        me->SummonCreature(NPC_MOON_LOTUS_MOVE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 60000);
                    events.ScheduleEvent(EVENT_SUMMON_AT, 20000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_moon_lotusAI(creature);
    }
};

// 69456
class bfa_npc_moon_lotus_movement : public CreatureScript
{
public:
    bfa_npc_moon_lotus_movement() : CreatureScript("bfa_npc_moon_lotus_movement") { }

    struct bfa_npc_moon_lotus_movementAI : public ScriptedAI
    {
        bfa_npc_moon_lotus_movementAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFaction(7);
            //set_speed(0.4f);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        EventMap events;

        void IsSummonedBy(Unit*)
        {
            events.ScheduleEvent(EVENT_SHUFFLE_ORIENTATION_AND_MOVE, 3000);
            events.ScheduleEvent(EVENT_CHECK_PROXIMITY_PLAYERS, 2000);
        }

        void Reset()
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_PROXIMITY_PLAYERS:
                {
                    me->CastSpell(me, 136721, true);
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (player->GetDistance(me) < 1.0f)
                            {
                                player->AddAura(SPELL_MOON_LOTUS_EFFECT, player);
                            }
                        }
                    events.ScheduleEvent(EVENT_CHECK_PROXIMITY_PLAYERS, 2000);
                    break;
                }
                case EVENT_SHUFFLE_ORIENTATION_AND_MOVE:
                {
                    float orientation = 0.0f;
                    switch (rand() % 6)
                    {
                    case 0:
                        orientation = 0.78f;
                        break;
                    case 1:
                        orientation = 0.04f;
                        break;
                    case 2:
                        orientation = 2.84f;
                        break;
                    case 3:
                        orientation = 2.24f;
                        break;
                    case 4:
                        orientation = 4.57f;
                        break;
                    case 5:
                        orientation = 3.89f;
                        break;
                    }
                    Position pos;
                    me->GetNearPoint(NULL, pos.m_positionX, pos.m_positionY, pos.m_positionZ, DEFAULT_WORLD_OBJECT_SIZE, 150, orientation);
                    me->GetMotionMaster()->MovePoint(0, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_moon_lotus_movementAI(creature);
    }
};

struct notValidSpec : public std::unary_function<Unit*, bool>
{
    notValidSpec() {}

    bool operator() (const Unit* pTarget)
    {
        Player* player = const_cast<Player*>(pTarget->ToPlayer());
        uint32 specialization = player->GetSpecializationId();
        return ((player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_BEAR)
            || (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_PROTECTION)
            || (player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_PROTECTION)
            || (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_BLOOD)
            || (player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_CAT)
            || (player->getClass() == CLASS_SHAMAN && specialization == TALENT_SPEC_SHAMAN_ENHANCEMENT)
            || (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_ARMS)
            || (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_FURY)
            || (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_FROST)
            || (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_UNHOLY)
            || (player->getClass() == CLASS_ROGUE)
            || (player->getClass() == CLASS_MONK && specialization == TALENT_SPEC_MONK_BATTLEDANCER)
            || (player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_HOLY));
    }
};

// 69365
class bfa_npc_star : public CreatureScript
{
public:
    bfa_npc_star() : CreatureScript("bfa_npc_star") { }

    struct bfa_npc_starAI : public ScriptedAI
    {
        bfa_npc_starAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFaction(7);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit*)
        {
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_STAR_ATTACK, 100);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_STAR_ATTACK:
                {
                    std::list<Unit*> players;
                    SelectTargetList(players, Is25ManRaid() ? 8 : 4, SELECT_TARGET_RANDOM, 300.0f, true);
                    players.remove_if(notValidSpec());
                    if (!players.empty())
                        for (std::list<Unit*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            me->CastSpell(*itr, SPELL_CRASHING_STAR, true);
                        }
                    /*switch (me->GetMap()->GetDifficulty())
                    {
                        case RAID_DIFFICULTY_10MAN_HEROIC:
                        case RAID_DIFFICULTY_10MAN_NORMAL:
                            Star10();
                            break;
                        case RAID_DIFFICULTY_25MAN_HEROIC:
                        case RAID_DIFFICULTY_25MAN_NORMAL:
                            Star25();
                            break;
                    }*/
                    break;
                }
                }
            }
        }

        Creature* Lulin()
        {
            return me->FindNearestCreature(NPC_LULIN, 500.0f, true);
        }

        void Star10()
        {
            std::list<Unit*> targets;
            SelectTargetList(targets, 1, SELECT_TARGET_RANDOM, 500.0f, true);
            targets.remove_if(notValidSpec()); // in this case, tank specc'ed players

            if (!targets.empty())
                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                {
                    me->CastSpell((*itr), SPELL_CRASHING_STAR, true);
                }
        }

        void Star25()
        {
            std::list<Unit*> targets;
            SelectTargetList(targets, 25, SELECT_TARGET_RANDOM, 500.0f, true);
            targets.remove_if(notValidSpec()); // in this case, tank specc'ed players

            if (!targets.empty())
                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                {
                    if (Creature* lulin = Lulin())
                        lulin->CastSpell((*itr), SPELL_CRASHING_STAR, true);
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_starAI(creature);
    }
};

// 137404
class bfa_spell_tears_of_the_sun : public SpellScriptLoader
{
public:
    bfa_spell_tears_of_the_sun() : SpellScriptLoader("bfa_spell_tears_of_the_sun") { }

    class bfa_spell_tears_of_the_sun_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_tears_of_the_sun_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            ExposeLurkers();
            Unit* myTarget = caster->GetVictim();

            if (!myTarget)
                return;
            caster->GetMotionMaster()->MoveJump(myTarget->GetPositionX(), myTarget->GetPositionY(), myTarget->GetPositionZ(), 35.0f, 35.0f, 0);
        }

        void ExposeLurkers()
        {
            Unit* caster = GetCaster();

            std::list<Creature*> Lurks;
            caster->GetCreatureListWithEntryInGrid(Lurks, NPC_LURKERS, 500.0f);

            if (Lurks.empty())
                return;
            for (auto it = Lurks.begin(); it != Lurks.end(); ++it)
            {
                Creature* creature = *it;
                if (caster->GetDistance(creature) < 11.0f)
                    creature->AI()->DoAction(ACTION_LURKER_VISIBLE);
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_tears_of_the_sun_AuraScript::OnPeriodic, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    class bfa_spell_tears_of_the_sun_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_tears_of_the_sun_SpellScript);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->Is25ManRaid() ? 5 : 2);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_tears_of_the_sun_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_tears_of_the_sun_SpellScript();
    }

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_tears_of_the_sun_AuraScript();
    }
};

enum CometEvents
{
    EVENT_COMET_ADD_VISUAL = 1,
};

class bfa_npc_ice_comet : public CreatureScript
{
public:
    bfa_npc_ice_comet() : CreatureScript("bfa_npc_ice_comet") { }

    struct bfa_npc_ice_cometAI : public ScriptedAI
    {
        bfa_npc_ice_cometAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        EventMap events;

        void IsSummonedBy(Unit*)
        {
            me->CastSpell(me, SPELL_ICE_COMENT_VISUAL);
            me->CastSpell(me, 137439); // icy shadows visual
            events.ScheduleEvent(EVENT_REMOVE_STACKS, 1000);
            events.ScheduleEvent(EVENT_COMET_ADD_VISUAL, 1500);
        }

        Creature* Suen()
        {
            return me->FindNearestCreature(NPC_SUEN, 6.0f, true);
        }

        Creature* SuenOrientation()
        {
            return me->FindNearestCreature(NPC_SUEN, 500.0f, true);
        }

        void Reset()
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (Creature* suen = SuenOrientation())
            {
                float ori = me->GetAngle(suen);
                me->SetOrientation(ori);
                me->SetFacingTo(ori);
                me->SetFacingToObject(suen);
                me->AI()->AttackStart(suen);
                me->AddThreat(suen, 999999999.9f);
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_REMOVE_STACKS:
                {
                    if (Creature* suen = Suen())
                    {
                        int32 damage = CalculatePct(me->GetHealth(), 10);
                        if (suen->GetDistance(me) < 10.0f)
                        {
                            if (suen->HasAura(SPELL_BLAZING_RADIANCE_STACK_DAMAGE))
                            {
                                me->DealDamage(me, damage);

                                if (me->GetHealthPct() <= 10) // the 10% damage wasn't working if the comet has <10%, in this case we simply kill it
                                    me->Kill(me);
                            }
                        }

                        if (suen->GetDistance(me) < 6.0f)
                        {
                            if (Aura* radiance = suen->GetAura(SPELL_BLAZING_RADIANCE_STACK_DAMAGE))
                            {
                                radiance->ModStackAmount(-1);
                            }
                        }
                    }
                    events.ScheduleEvent(EVENT_REMOVE_STACKS, 1000);
                    break;
                }
                case EVENT_COMET_ADD_VISUAL:
                    me->CastSpell(me, 137439, true);
                    events.ScheduleEvent(EVENT_COMET_ADD_VISUAL, 1500);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_ice_cometAI(creature);
    }
};

// 137491
class bfa_spell_nuclear_inferno : public SpellScriptLoader
{
public:
    bfa_spell_nuclear_inferno() : SpellScriptLoader("bfa_spell_nuclear_inferno") { }

    class bfa_spell_nuclear_inferno_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_nuclear_inferno_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            if (!GetCaster())
                return;

            GetCaster()->CastSpell(nullptr, SPELL_NUCLEAR_INFERNO_DAMAGE);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_nuclear_inferno_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_nuclear_inferno_AuraScript();
    }
};

// 137531
class bfa_spell_tidal_force : public SpellScriptLoader
{
public:
    bfa_spell_tidal_force() : SpellScriptLoader("bfa_spell_tidal_force") { }

    class bfa_spell_tidal_force_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_tidal_force_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            float orientation = 0.0f;
            switch (rand() % 11)
            {
            case 0:
                orientation = 0.78f;
                break;
            case 1:
                orientation = 0.04f;
                break;
            case 2:
                orientation = 2.84f;
                break;
            case 3:
                orientation = 2.24f;
                break;
            case 4:
                orientation = 4.57f;
                break;
            case 5:
                orientation = 3.89f;
                break;
            case 6:
                orientation = 6.15f;
                break;
            case 7:
                orientation = 4.76f;
                break;
            case 8:
                orientation = 1.20f;
                break;
            case 9:
                orientation = 5.93f;
                break;
            case 10:
                orientation = 5.01f;
                break;
            }
            if (!caster->HasAura(138645))
            {
                caster->SetFacingTo(orientation);
                caster->SetOrientation(orientation);
                caster->CastSpell(caster, SPELL_TIDAL_FORCE_WAVE, true);
                caster->CastSpell(caster, SPELL_TIDAL_FORCE_DAMAGE, true);
            }
            else
            {
                if (aurEff->GetTickNumber() % 3 == 0)
                {
                    if (Creature* TidalForce = caster->SummonCreature(NPC_TIDAL_FORCE_SLOWER, caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 10000))
                    {
                        Position pos;
                        TidalForce->GetNearPoint(NULL, pos.m_positionX, pos.m_positionY, pos.m_positionZ, DEFAULT_WORLD_OBJECT_SIZE, 150, orientation);
                        TidalForce->GetMotionMaster()->MovePoint(0, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
                    }
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_tidal_force_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_tidal_force_AuraScript();
    }
};

class bfa_npc_melt_ice_comet : public CreatureScript
{
public:
    bfa_npc_melt_ice_comet() : CreatureScript("bfa_npc_melt_ice_comet") { }

    struct bfa_npc_melt_ice_cometAI : public ScriptedAI
    {
        bfa_npc_melt_ice_cometAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        Creature* comet()
        {
            return me->FindNearestCreature(NPC_ICE_COMET, 8.0f);
        }

        void UpdateAI(uint32 diff)
        {
            if (Creature* IceComet = comet())
                IceComet->Kill(IceComet);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_melt_ice_cometAI(creature);
    }
};

// 138267 ( serpent ), 138254 ( ox ), 138189 ( crane ), 138264 ( tiger )
class bfa_spell_invoke_celestials : public SpellScriptLoader
{
public:
    bfa_spell_invoke_celestials() : SpellScriptLoader("bfa_spell_invoke_celestials") { }

    class bfa_spell_invoke_celestials_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_invoke_celestials_AuraScript);

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();

            if (!caster || !target)
                return;
            PhasingHandler::AddPhase(target, 1, true);

        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_invoke_celestials_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_SCREEN_EFFECT, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_invoke_celestials_AuraScript();
    }
};

/*
######## YU'LON CONSTELLATION START
*/

class bfa_npc_yulon_constellation : public CreatureScript
{
public:
    bfa_npc_yulon_constellation() : CreatureScript("bfa_npc_yulon_constellation") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->NearTeleportTo(6198.65f, 4214.27f, 146.50f, 2.34f, false);
        player->AddAura(SPELL_INVOKE_SERPENT_SPIRIT, player);
        PhasingHandler::AddPhase(player, 2, true);
        creature->SummonCreature(NPC_YULON_CONSTELATION_CORRECT_3, ConstellationPoints[0], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_YULON_CONSTELATION_CORRECT_1, ConstellationPoints[4], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_YULON_CONSTELATION_CORRECT_2, ConstellationPoints[5], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_YULON_CONSTELATION_CORRECT_5, ConstellationPoints[2], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_YULON_CONSTELATION_CORRECT_4, ConstellationPoints[1], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_YULON_CONSTELATION_FAIL_6, ConstellationPoints[6], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_YULON_CONSTELATION_FAIL_7, ConstellationPoints[3], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->AI()->DoAction(ACTION_PLAYER_IN_ROOM);
        return true;
    }

    struct bfa_npc_yulon_constellationAI : public ScriptedAI
    {
        bfa_npc_yulon_constellationAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_GREEN_SHADOWY, me);
        }

        EventMap events;
        bool completed;

        void RemoveStars()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_FAIL_6, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_FAIL_7, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->DespawnOrUnsummon();
                }
        }

        void RemoveInvokeAura()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    PhasingHandler::AddPhase(me, 2, false);
                    player->RemoveAura(SPELL_INVOKE_SERPENT_SPIRIT);
                    PhasingHandler::AddPhase(me, 1, true);
                }
        }

        void CastCooldownOnCelestials()
        {
            std::list<Creature*> celestials;
            me->GetCreatureListWithEntryInGrid(celestials, NPC_XUEN, 500.0f);
            me->GetCreatureListWithEntryInGrid(celestials, NPC_NIUZAO, 500.0f);
            me->GetCreatureListWithEntryInGrid(celestials, NPC_CHI_JI, 500.0f);

            celestials.remove_if(isCompleted());

            if (!celestials.empty())
                for (auto it = celestials.begin(); it != celestials.end(); ++it)
                {
                    Creature* celestial = *it;
                    if (Aura* cdAura = celestial->AddAura(65508, celestial))
                    {
                        cdAura->SetDuration(30 * IN_MILLISECONDS);
                        cdAura->SetMaxDuration(30 * IN_MILLISECONDS);
                    }
                }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_CONSTELLATION_COMPLETE:
                RemoveStars();
                RemoveInvokeAura();
                completed = true;
                break;
            case ACTION_PLAYER_IN_ROOM:
                CastCooldownOnCelestials();
                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                if (!completed)
                    events.ScheduleEvent(EVENT_ALREADY_A_PLAYERS, 30 * IN_MILLISECONDS);
                break;
            case ACTION_RESET_CELESTIALS_DUSK:
                completed = false;
                break;
            }
        }

        void Reset()
        {
            events.Reset();
            completed = false;
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ALREADY_A_PLAYERS:
                    if (completed)
                        return;
                    me->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_yulon_constellationAI(creature);
    }
};

// 999368, 999369
class bfa_npc_yulon_constellation_fail : public CreatureScript
{
public:
    bfa_npc_yulon_constellation_fail() : CreatureScript("bfa_npc_yulon_constellation_fail") { }

    struct bfa_npc_yulon_constellation_failAI : public ScriptedAI
    {
        bfa_npc_yulon_constellation_failAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
            PhasingHandler::AddPhase(me, 2, true);
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_5, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void UpdateAI(uint32 diff)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->GetDistance(me) < 1.0f && player->HasAura(SPELL_INVOKE_SERPENT_SPIRIT))
                    {
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL);
                        RemoveCorrectBeams();
                    }
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_yulon_constellation_failAI(creature);
    }
};

// 999295
class bfa_npc_yulon_constellation_succes_1 : public CreatureScript
{
public:
    bfa_npc_yulon_constellation_succes_1() : CreatureScript("bfa_npc_yulon_constellation_succes_1") { }

    struct bfa_npc_yulon_constellation_succes_1AI : public ScriptedAI
    {
        bfa_npc_yulon_constellation_succes_1AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->AddAura(34126, me);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
            PhasingHandler::AddPhase(me, 2, true);
        }

        Creature* secondPoint()
        {
            return me->FindNearestCreature(NPC_YULON_CONSTELATION_CORRECT_2, 500.0f, true);
        }

        void UpdateAI(uint32 diff)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->GetDistance(me) < 1.0f)
                    {
                        me->CastSpell(me, SPELL_CONSTELATION_SUCCES);
                        if (Creature* second = secondPoint())
                            second->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    }
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_yulon_constellation_succes_1AI(creature);
    }
};

// 999296
class bfa_npc_yulon_constellation_succes_2 : public CreatureScript
{
public:
    bfa_npc_yulon_constellation_succes_2() : CreatureScript("bfa_npc_yulon_constellation_succes_2") { }

    struct bfa_npc_yulon_constellation_succes_2AI : public ScriptedAI
    {
        bfa_npc_yulon_constellation_succes_2AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isSecondActive;
        bool notActive;

        void Reset()
        {
            isSecondActive = false;
            notActive = false;
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        Creature* firstPoint()
        {
            return me->FindNearestCreature(NPC_YULON_CONSTELATION_CORRECT_1, 500.0f, true);
        }

        Creature* nextPoint()
        {
            return me->FindNearestCreature(NPC_YULON_CONSTELATION_CORRECT_3, 500.0f, true);
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_5, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        RemoveCorrectBeams();
                        return;
                    }
                    isSecondActive = true;
                    if (Creature* first = firstPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* next = nextPoint())
                        next->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_yulon_constellation_succes_2AI(creature);
    }
};

// 999297
class bfa_npc_yulon_constellation_succes_3 : public CreatureScript
{
public:
    bfa_npc_yulon_constellation_succes_3() : CreatureScript("bfa_npc_yulon_constellation_succes_3") { }

    struct bfa_npc_yulon_constellation_succes_3AI : public ScriptedAI
    {
        bfa_npc_yulon_constellation_succes_3AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isThirdActive;
        bool notActive;

        void Reset()
        {
            isThirdActive = false;
            notActive = false;
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_5, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        Creature* secondPoint()
        {
            return me->FindNearestCreature(NPC_YULON_CONSTELATION_CORRECT_2, 500.0f, true);
        }

        Creature* nextPoint()
        {
            return me->FindNearestCreature(NPC_YULON_CONSTELATION_CORRECT_4, 500.0f, true);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        RemoveCorrectBeams();
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        return;
                    }
                    isThirdActive = true;
                    if (Creature* first = secondPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* next = nextPoint())
                        next->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_yulon_constellation_succes_3AI(creature);
    }
};

// 999298
class bfa_npc_yulon_constellation_succes_4 : public CreatureScript
{
public:
    bfa_npc_yulon_constellation_succes_4() : CreatureScript("bfa_npc_yulon_constellation_succes_4") { }

    struct bfa_npc_yulon_constellation_succes_4AI : public ScriptedAI
    {
        bfa_npc_yulon_constellation_succes_4AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isForthActive;
        bool notActive;

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_5, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        void Reset()
        {
            notActive = false;
            isForthActive = false;
        }

        Creature* thirdPoint()
        {
            return me->FindNearestCreature(NPC_YULON_CONSTELATION_CORRECT_3, 500.0f, true);
        }

        Creature* nextPoint()
        {
            return me->FindNearestCreature(NPC_YULON_CONSTELATION_CORRECT_5, 500.0f, true);
        }
        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        RemoveCorrectBeams();
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        return;
                    }
                    isForthActive = true;
                    if (Creature* first = thirdPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* next = nextPoint())
                        next->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_yulon_constellation_succes_4AI(creature);
    }
};

// 999299
class bfa_npc_yulon_constellation_succes_5 : public CreatureScript
{
public:
    bfa_npc_yulon_constellation_succes_5() : CreatureScript("bfa_npc_yulon_constellation_succes_5") { }

    struct bfa_npc_yulon_constellation_succes_5AI : public ScriptedAI
    {
        bfa_npc_yulon_constellation_succes_5AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isFifthActive;
        bool notActive;

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_YULON_CONSTELATION_CORRECT_5, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void Reset()
        {
            isFifthActive = false;
            notActive = false;
        }

        Creature* forthPoint()
        {
            return me->FindNearestCreature(NPC_YULON_CONSTELATION_CORRECT_4, 500.0f, true);
        }

        Creature* Yulon()
        {
            return me->FindNearestCreature(NPC_YU_LON, 500.0f, true);
        }

        Creature* pointthree()
        {
            return me->FindNearestCreature(NPC_YULON_CONSTELATION_CORRECT_3, 500.0f, true);
        }

        void RemoveInvokeAura()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(SPELL_INVOKE_SERPENT_SPIRIT);
                }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        RemoveCorrectBeams();
                        return;
                    }
                    isFifthActive = true;
                    RemoveInvokeAura();
                    if (Creature* first = forthPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* PointThree = pointthree())
                    {
                        //PointThree->SetPhaseMask(1, true);
                        PhasingHandler::AddPhase(PointThree, 1, true);
                        PointThree->CastSpell(PointThree, SPELL_SERPENTS_VITALITY, true);
                        PointThree->DespawnOrUnsummon(5000);
                        PhasingHandler::AddPhase(me, 1, false);
                    }
                    if (Creature* yulon = Yulon())
                    {
                        yulon->AI()->DoAction(ACTION_CONSTELLATION_COMPLETE);
                    }
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_yulon_constellation_succes_5AI(creature);
    }
};

/*
######## YU'LON CONSTELLATION END
*/


/*
######## CHI-JI CONSTELLATION START
*/


class bfa_npc_chiji_constellation : public CreatureScript
{
public:
    bfa_npc_chiji_constellation() : CreatureScript("bfa_npc_chiji_constellation") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->NearTeleportTo(6198.65f, 4214.27f, 146.50f, 2.34f, false);
        player->AddAura(SPELL_INVOKE_CRANE_SPIRIT, player);
        PhasingHandler::AddPhase(player, 2, true);
        creature->SummonCreature(NPC_CHIJI_CONSTELLATION_CORRECT_1, ConstellationPoints[4], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_CHIJI_CONSTELLATION_CORRECT_2, ConstellationPoints[3], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_CHIJI_CONSTELLATION_CORRECT_3, ConstellationPoints[2], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_CHIJI_CONSTELLATION_CORRECT_4, ConstellationPoints[0], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_CHIJI_CONSTELLATION_CORRECT_5, ConstellationPoints[4], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_CHIJI_CONSTELLATION_CORRECT_6, ConstellationPoints[5], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_CHIJI_CONSTELLATION_FAIL_8, ConstellationPoints[1], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_CHIJI_CONSTELLATION_FAIL_7, ConstellationPoints[6], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->AI()->DoAction(ACTION_PLAYER_IN_ROOM);
        return true;
    }

    struct bfa_npc_chiji_constellationAI : public ScriptedAI
    {
        bfa_npc_chiji_constellationAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_RED_SHADOWY, me);
        }

        EventMap events;
        bool completed;

        void Reset()
        {
            events.Reset();
            completed = false;
        }

        void RemoveInvokeAura()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                   // me->SetPhaseMask(2, false);
                    PhasingHandler::AddPhase(me, 2, false);
                    player->RemoveAura(SPELL_INVOKE_CRANE_SPIRIT);
                   // me->SetPhaseMask(1, true);
                    PhasingHandler::AddPhase(me, 1, true);
                }
        }

        void RemoveStars()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_6, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_FAIL_8, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_FAIL_7, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->DespawnOrUnsummon();
                }
        }

        void CastCooldownOnCelestials()
        {
            std::list<Creature*> celestials;
            me->GetCreatureListWithEntryInGrid(celestials, NPC_XUEN, 500.0f);
            me->GetCreatureListWithEntryInGrid(celestials, NPC_NIUZAO, 500.0f);
            me->GetCreatureListWithEntryInGrid(celestials, NPC_YU_LON, 500.0f);

            celestials.remove_if(isCompleted());

            if (!celestials.empty())
                for (auto it = celestials.begin(); it != celestials.end(); ++it)
                {
                    Creature* celestial = *it;
                    if (Aura* cdAura = celestial->AddAura(65508, celestial))
                    {
                        cdAura->SetDuration(30 * IN_MILLISECONDS);
                        cdAura->SetMaxDuration(30 * IN_MILLISECONDS);
                    }
                }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_CONSTELLATION_COMPLETE:
                RemoveStars();
                RemoveInvokeAura();
                me->SummonCreature(NPC_CRANE_RUSH_TRIGGER, 6180.91f, 4304.33f, 146.48f, 4.63f, TEMPSUMMON_MANUAL_DESPAWN);
                completed = true;
                break;
            case ACTION_PLAYER_IN_ROOM:
                CastCooldownOnCelestials();
                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                if (!completed)
                    events.ScheduleEvent(EVENT_ALREADY_A_PLAYERS, 30 * IN_MILLISECONDS);
                break;
            case ACTION_RESET_CELESTIALS_DUSK:
                completed = false;
                break;
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ALREADY_A_PLAYERS:
                    if (completed)
                        return;
                    me->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);
                    break;
                }
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_chiji_constellationAI(creature);
    }
};

class bfa_npc_chiji_constellation_fail : public CreatureScript
{
public:
    bfa_npc_chiji_constellation_fail() : CreatureScript("bfa_npc_chiji_constellation_fail") { }

    struct bfa_npc_chiji_constellation_failAI : public ScriptedAI
    {
        bfa_npc_chiji_constellation_failAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
           // me->SetPhaseMask(2, true);
            PhasingHandler::AddPhase(me, 2, true);
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_6, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void UpdateAI(uint32 diff)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->GetDistance(me) < 1.0f && player->HasAura(SPELL_INVOKE_CRANE_SPIRIT))
                    {
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL);
                        RemoveCorrectBeams();
                    }
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_chiji_constellation_failAI(creature);
    }
};

class bfa_npc_chiji_constellation_succes_1 : public CreatureScript
{
public:
    bfa_npc_chiji_constellation_succes_1() : CreatureScript("bfa_npc_chiji_constellation_succes_1") { }

    struct bfa_npc_chiji_constellation_succes_1AI : public ScriptedAI
    {
        bfa_npc_chiji_constellation_succes_1AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->AddAura(34126, me);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
            //me->SetPhaseMask(2, true);
        }

        Creature* secondPoint()
        {
            return me->FindNearestCreature(NPC_CHIJI_CONSTELLATION_CORRECT_2, 500.0f, true);
        }

        void UpdateAI(uint32 diff)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->GetDistance(me) < 1.0f)
                    {
                        me->CastSpell(me, SPELL_CONSTELATION_SUCCES);
                        if (Creature* second = secondPoint())
                            second->AI()->DoAction(ACTION_ACTIVE_POINTS);
                        //(SPELL_CONSTELATION_SUCCES, 5000);
                    }
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_chiji_constellation_succes_1AI(creature);
    }
};

class bfa_npc_chiji_constellation_succes_2 : public CreatureScript
{
public:
    bfa_npc_chiji_constellation_succes_2() : CreatureScript("bfa_npc_chiji_constellation_succes_2") { }

    struct bfa_npc_chiji_constellation_succes_2AI : public ScriptedAI
    {
        bfa_npc_chiji_constellation_succes_2AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            //me->SetPhaseMask(2, true);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isSecondActive;
        bool notActive;

        void Reset()
        {
            isSecondActive = false;
            notActive = false;
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        Creature* firstPoint()
        {
            return me->FindNearestCreature(NPC_CHIJI_CONSTELLATION_CORRECT_1, 500.0f, true);
        }

        Creature* nextPoint()
        {
            return me->FindNearestCreature(NPC_CHIJI_CONSTELLATION_CORRECT_3, 500.0f, true);
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_6, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        RemoveCorrectBeams();
                        return;
                    }
                    isSecondActive = true;
                    if (Creature* first = firstPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* next = nextPoint())
                        next->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_chiji_constellation_succes_2AI(creature);
    }
};

class bfa_npc_chiji_constellation_succes_3 : public CreatureScript
{
public:
    bfa_npc_chiji_constellation_succes_3() : CreatureScript("bfa_npc_chiji_constellation_succes_3") { }

    struct bfa_npc_chiji_constellation_succes_3AI : public ScriptedAI
    {
        bfa_npc_chiji_constellation_succes_3AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isThirdActive;
        bool notActive;

        void Reset()
        {
            isThirdActive = false;
            notActive = false;
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_6, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        Creature* secondPoint()
        {
            return me->FindNearestCreature(NPC_CHIJI_CONSTELLATION_CORRECT_2, 500.0f, true);
        }

        Creature* nextPoint()
        {
            return me->FindNearestCreature(NPC_CHIJI_CONSTELLATION_CORRECT_4, 500.0f, true);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        RemoveCorrectBeams();
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        return;
                    }
                    isThirdActive = true;
                    if (Creature* first = secondPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* next = nextPoint())
                        next->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_chiji_constellation_succes_3AI(creature);
    }
};

class bfa_npc_chiji_constellation_succes_4 : public CreatureScript
{
public:
    bfa_npc_chiji_constellation_succes_4() : CreatureScript("bfa_npc_chiji_constellation_succes_4") { }

    struct bfa_npc_chiji_constellation_succes_4AI : public ScriptedAI
    {
        bfa_npc_chiji_constellation_succes_4AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isForthActive;
        bool notActive;

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_6, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        void Reset()
        {
            notActive = false;
            isForthActive = false;
        }

        Creature* thirdPoint()
        {
            return me->FindNearestCreature(NPC_CHIJI_CONSTELLATION_CORRECT_3, 500.0f, true);
        }

        Creature* nextPoint()
        {
            return me->FindNearestCreature(NPC_CHIJI_CONSTELLATION_CORRECT_5, 500.0f, true);
        }
        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        RemoveCorrectBeams();
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        return;
                    }
                    isForthActive = true;
                    if (Creature* first = thirdPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* next = nextPoint())
                        next->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_chiji_constellation_succes_4AI(creature);
    }
};

class bfa_npc_chiji_constellation_succes_5 : public CreatureScript
{
public:
    bfa_npc_chiji_constellation_succes_5() : CreatureScript("bfa_npc_chiji_constellation_succes_5") { }

    struct bfa_npc_chiji_constellation_succes_5AI : public ScriptedAI
    {
        bfa_npc_chiji_constellation_succes_5AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isFifthActive;
        bool notActive;

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_6, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        void Reset()
        {
            notActive = false;
            isFifthActive = false;
        }

        Creature* forthPoint()
        {
            return me->FindNearestCreature(NPC_CHIJI_CONSTELLATION_CORRECT_4, 500.0f, true);
        }

        Creature* nextPoint()
        {
            return me->FindNearestCreature(NPC_CHIJI_CONSTELLATION_CORRECT_6, 500.0f, true);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                        return;
                    isFifthActive = true;
                    if (Creature* first = forthPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* next = nextPoint())
                        next->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_chiji_constellation_succes_5AI(creature);
    }
};

class bfa_npc_chiji_constellation_succes_6 : public CreatureScript
{
public:
    bfa_npc_chiji_constellation_succes_6() : CreatureScript("bfa_npc_chiji_constellation_succes_6") { }

    struct bfa_npc_chiji_constellation_succes_6AI : public ScriptedAI
    {
        bfa_npc_chiji_constellation_succes_6AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isFifthActive;
        bool notActive;

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_CHIJI_CONSTELLATION_CORRECT_6, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void Reset()
        {
            isFifthActive = false;
            notActive = false;
        }

        Creature* fifthPoint()
        {
            return me->FindNearestCreature(NPC_CHIJI_CONSTELLATION_CORRECT_5, 500.0f, true);
        }

        Creature* Yulon()
        {
            return me->FindNearestCreature(NPC_CHI_JI, 500.0f, true);
        }

        Creature* pointthree()
        {
            return me->FindNearestCreature(NPC_CHIJI_CONSTELLATION_CORRECT_4, 500.0f, true);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        RemoveCorrectBeams();
                        return;
                    }
                    isFifthActive = true;
                    if (Creature* first = fifthPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* PointThree = pointthree())
                    {
                        PhasingHandler::AddPhase(PointThree, 1, true);
                        PointThree->DespawnOrUnsummon(2000);
                        PhasingHandler::AddPhase(me, 1, false);
                    }
                    if (Creature* yulon = Yulon())
                    {
                        yulon->AI()->DoAction(ACTION_CONSTELLATION_COMPLETE);
                    }
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_chiji_constellation_succes_6AI(creature);
    }
};

/*
######## CHI-JI CONSTELLATION END
*/

/*
######## NIUZAO CONSTELLATION START
*/

class bfa_npc_niuazo_constellation : public CreatureScript
{
public:
    bfa_npc_niuazo_constellation() : CreatureScript("bfa_npc_niuazo_constellation") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->NearTeleportTo(6198.65f, 4214.27f, 146.50f, 2.34f, false);
        player->AddAura(SPELL_INVOKE_OX_SPIRIT, player);
        PhasingHandler::AddPhase(player, 2, true);
        creature->SummonCreature(NPC_NIUZAO_CONSTELLATION_CORRECT_1, ConstellationPoints[4], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_NIUZAO_CONSTELLATION_CORRECT_2, ConstellationPoints[0], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_NIUZAO_CONSTELLATION_CORRECT_3, ConstellationPoints[2], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_NIUZAO_CONSTELLATION_CORRECT_4, ConstellationPoints[1], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_NIUZAO_CONSTELLATION_CORRECT_5, ConstellationPoints[6], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_NIUZAO_CONSTELLATION_FAIL_6, ConstellationPoints[3], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_NIUZAO_CONSTELLATION_FAIL_7, ConstellationPoints[5], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->AI()->DoAction(ACTION_PLAYER_IN_ROOM);
        return true;
    }

    struct bfa_npc_niuazo_constellationAI : public ScriptedAI
    {
        bfa_npc_niuazo_constellationAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_YELLOW_SHADOWY, me);
        }

        EventMap events;
        bool completed;

        void Reset()
        {
            events.Reset();
            completed = false;
        }

        void CastCooldownOnCelestials()
        {
            std::list<Creature*> celestials;
            me->GetCreatureListWithEntryInGrid(celestials, NPC_XUEN, 500.0f);
            me->GetCreatureListWithEntryInGrid(celestials, NPC_YU_LON, 500.0f);
            me->GetCreatureListWithEntryInGrid(celestials, NPC_CHI_JI, 500.0f);

            celestials.remove_if(isCompleted());

            if (!celestials.empty())
                for (auto it = celestials.begin(); it != celestials.end(); ++it)
                {
                    Creature* celestial = *it;
                    if (Aura* cdAura = celestial->AddAura(65508, celestial))
                    {
                        cdAura->SetDuration(30 * IN_MILLISECONDS);
                        cdAura->SetMaxDuration(30 * IN_MILLISECONDS);
                    }
                }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_CONSTELLATION_COMPLETE:
                RemoveStars();
                RemoveInvokeAura();
                completed = true;
                break;
            case ACTION_PLAYER_IN_ROOM:
                CastCooldownOnCelestials();
                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                if (!completed)
                    events.ScheduleEvent(EVENT_ALREADY_A_PLAYERS, 30 * IN_MILLISECONDS);
                break;
            case ACTION_RESET_CELESTIALS_DUSK:
                completed = false;
                break;
            }
        }

        void RemoveStars()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_FAIL_6, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_FAIL_7, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->DespawnOrUnsummon();
                }
        }

        void RemoveInvokeAura()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    PhasingHandler::AddPhase(me, 2, false);
                    player->RemoveAura(SPELL_INVOKE_OX_SPIRIT);
                    PhasingHandler::AddPhase(me, 1, true);
                }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ALREADY_A_PLAYERS:
                    if (completed)
                        return;
                    me->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);
                    break;
                }
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_niuazo_constellationAI(creature);
    }
};

class bfa_npc_niuzao_constellation_fail : public CreatureScript
{
public:
    bfa_npc_niuzao_constellation_fail() : CreatureScript("bfa_npc_niuzao_constellation_fail") { }

    struct bfa_npc_niuzao_constellation_failAI : public ScriptedAI
    {
        bfa_npc_niuzao_constellation_failAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
            PhasingHandler::AddPhase(me, 2, true);
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_5, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void UpdateAI(uint32 diff)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->GetDistance(me) < 1.0f && player->HasAura(SPELL_INVOKE_OX_SPIRIT))
                    {
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL);
                        RemoveCorrectBeams();
                    }
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_niuzao_constellation_failAI(creature);
    }
};

class bfa_npc_niuzao_constellation_succes_1 : public CreatureScript
{
public:
    bfa_npc_niuzao_constellation_succes_1() : CreatureScript("bfa_npc_niuzao_constellation_succes_1") { }

    struct bfa_npc_niuzao_constellation_succes_1AI : public ScriptedAI
    {
        bfa_npc_niuzao_constellation_succes_1AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->AddAura(34126, me);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
            PhasingHandler::AddPhase(me, 2, true);
        }

        Creature* secondPoint()
        {
            return me->FindNearestCreature(NPC_NIUZAO_CONSTELLATION_CORRECT_2, 500.0f, true);
        }

        void UpdateAI(uint32 diff)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->GetDistance(me) < 1.0f)
                    {
                        me->CastSpell(me, SPELL_CONSTELATION_SUCCES);
                        if (Creature* second = secondPoint())
                            second->AI()->DoAction(ACTION_ACTIVE_POINTS);
  
                    }
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_niuzao_constellation_succes_1AI(creature);
    }
};

enum NiuzaoBuff
{
    EVENT_CAST_BUFF = 1,
};

enum NiuzaoActions
{
    ACTION_CAST_OX_FORT = 1,
};

class bfa_npc_niuzao_constellation_succes_2 : public CreatureScript
{
public:
    bfa_npc_niuzao_constellation_succes_2() : CreatureScript("bfa_npc_niuzao_constellation_succes_2") { }

    struct bfa_npc_niuzao_constellation_succes_2AI : public ScriptedAI
    {
        bfa_npc_niuzao_constellation_succes_2AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isSecondActive;
        bool notActive;
        EventMap events;

        void Reset()
        {
            isSecondActive = false;
            notActive = false;
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            case ACTION_CAST_OX_FORT:
                events.ScheduleEvent(EVENT_CAST_BUFF, 2000);
                break;
            }
        }

        Creature* firstPoint()
        {
            return me->FindNearestCreature(NPC_NIUZAO_CONSTELLATION_CORRECT_1, 500.0f, true);
        }

        Creature* nextPoint()
        {
            return me->FindNearestCreature(NPC_NIUZAO_CONSTELLATION_CORRECT_3, 500.0f, true);
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_5, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        RemoveCorrectBeams();
                        return;
                    }
                    isSecondActive = true;
                    if (Creature* first = firstPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* next = nextPoint())
                        next->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
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
                case EVENT_CAST_BUFF:
                    me->CastSpell(me, 138298, true);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_niuzao_constellation_succes_2AI(creature);
    }
};

class bfa_npc_niuzao_constellation_succes_3 : public CreatureScript
{
public:
    bfa_npc_niuzao_constellation_succes_3() : CreatureScript("bfa_npc_niuzao_constellation_succes_3") { }

    struct bfa_npc_niuzao_constellation_succes_3AI : public ScriptedAI
    {
        bfa_npc_niuzao_constellation_succes_3AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isThirdActive;
        bool notActive;

        void Reset()
        {
            isThirdActive = false;
            notActive = false;
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_5, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        Creature* secondPoint()
        {
            return me->FindNearestCreature(NPC_NIUZAO_CONSTELLATION_CORRECT_2, 500.0f, true);
        }

        Creature* nextPoint()
        {
            return me->FindNearestCreature(NPC_NIUZAO_CONSTELLATION_CORRECT_4, 500.0f, true);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        RemoveCorrectBeams();
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        return;
                    }
                    isThirdActive = true;
                    if (Creature* first = secondPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* next = nextPoint())
                        next->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_niuzao_constellation_succes_3AI(creature);
    }
};

class bfa_npc_niuzao_constellation_succes_4 : public CreatureScript
{
public:
    bfa_npc_niuzao_constellation_succes_4() : CreatureScript("bfa_npc_niuzao_constellation_succes_4") { }

    struct bfa_npc_niuzao_constellation_succes_4AI : public ScriptedAI
    {
        bfa_npc_niuzao_constellation_succes_4AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isForthActive;
        bool notActive;

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_5, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        void Reset()
        {
            notActive = false;
            isForthActive = false;
        }

        Creature* thirdPoint()
        {
            return me->FindNearestCreature(NPC_NIUZAO_CONSTELLATION_CORRECT_3, 500.0f, true);
        }

        Creature* nextPoint()
        {
            return me->FindNearestCreature(NPC_NIUZAO_CONSTELLATION_CORRECT_5, 500.0f, true);
        }
        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        RemoveCorrectBeams();
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        return;
                    }
                    isForthActive = true;
                    if (Creature* first = thirdPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* next = nextPoint())
                        next->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_niuzao_constellation_succes_4AI(creature);
    }
};

class bfa_npc_niuzao_constellation_succes_5 : public CreatureScript
{
public:
    bfa_npc_niuzao_constellation_succes_5() : CreatureScript("bfa_npc_niuzao_constellation_succes_5") { }

    struct bfa_npc_niuzao_constellation_succes_5AI : public ScriptedAI
    {
        bfa_npc_niuzao_constellation_succes_5AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isFifthActive;
        bool notActive;

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_NIUZAO_CONSTELLATION_CORRECT_5, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void Reset()
        {
            isFifthActive = false;
            notActive = false;
        }

        Creature* forthPoint()
        {
            return me->FindNearestCreature(NPC_NIUZAO_CONSTELLATION_CORRECT_4, 500.0f, true);
        }

        Creature* Yulon()
        {
            return me->FindNearestCreature(NPC_NIUZAO, 500.0f, true);
        }

        Creature* pointthree()
        {
            return me->FindNearestCreature(NPC_NIUZAO_CONSTELLATION_CORRECT_2, 500.0f, true);
        }

        void AddFortitudePlayers()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->CastSpell(player, SPELL_FORTITUDE_OF_THE_OX, true);
                }
        }

        void RemoveInvokeAura()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(SPELL_INVOKE_OX_SPIRIT);
                }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        RemoveCorrectBeams();
                        return;
                    }
                    isFifthActive = true;
                    RemoveInvokeAura();
                    if (Creature* first = forthPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* PointThree = pointthree())
                    {
                        PhasingHandler::AddPhase(PointThree, 1, true);
                        //PointThree->CastSpell(PointThree, SPELL_FORTITUDE_OF_THE_OX, true);
                        //PointThree->CastSpell(PointThree, 138298, true);
                        PointThree->AI()->DoAction(ACTION_CAST_OX_FORT);
                        PointThree->DespawnOrUnsummon(5000);

                        PhasingHandler::AddPhase(me, 1, false);
                        //AddFortitudePlayers();
                    }
                    if (Creature* yulon = Yulon())
                        yulon->AI()->DoAction(ACTION_CONSTELLATION_COMPLETE);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_niuzao_constellation_succes_5AI(creature);
    }
};

/*
######## NIUZAO CONSTELLATION END
*/

/*
######## XUEN CONSTELLATION START
*/

class bfa_npc_xuen_constellation : public CreatureScript
{
public:
    bfa_npc_xuen_constellation() : CreatureScript("bfa_npc_xuen_constellation") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->NearTeleportTo(6198.65f, 4214.27f, 146.50f, 2.34f, false);
        player->AddAura(SPELL_INVOKE_TIGER_SPIRIT, player);
        PhasingHandler::AddPhase(player, 2, true);
        creature->SummonCreature(NPC_XUEN_CONSTELLATION_CORRECT_1, ConstellationPoints[4], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_XUEN_CONSTELLATION_CORRECT_2, ConstellationPoints[1], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_XUEN_CONSTELLATION_CORRECT_3, ConstellationPoints[0], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_XUEN_CONSTELLATION_CORRECT_4, ConstellationPoints[6], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_XUEN_CONSTELLATION_CORRECT_5, ConstellationPoints[2], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_XUEN_CONSTELLATION_CORRECT_6, ConstellationPoints[4], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_XUEN_CONSTELLATION_FAIL_7, ConstellationPoints[3], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->SummonCreature(NPC_XUEN_CONSTELLATION_FAIL_8, ConstellationPoints[5], TEMPSUMMON_TIMED_DESPAWN, 30000);
        creature->AI()->DoAction(ACTION_PLAYER_IN_ROOM);
        return true;
    }

    struct bfa_npc_xuen_constellationAI : public ScriptedAI
    {
        bfa_npc_xuen_constellationAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_BLUE_SHADOWY, me);
        }

        EventMap events;
        bool completed;

        void Reset()
        {
            events.Reset();
            completed = false;
        }

        void RemoveInvokeAura()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    PhasingHandler::AddPhase(me, 2, false);
                    player->RemoveAura(SPELL_INVOKE_TIGER_SPIRIT);
                    PhasingHandler::AddPhase(me, 1, true);
                }
        }

        void CastCooldownOnCelestials()
        {
            std::list<Creature*> celestials;
            me->GetCreatureListWithEntryInGrid(celestials, NPC_YU_LON, 500.0f);
            me->GetCreatureListWithEntryInGrid(celestials, NPC_NIUZAO, 500.0f);
            me->GetCreatureListWithEntryInGrid(celestials, NPC_CHI_JI, 500.0f);

            celestials.remove_if(isCompleted());

            if (!celestials.empty())
                for (auto it = celestials.begin(); it != celestials.end(); ++it)
                {
                    Creature* celestial = *it;
                    if (Aura* cdAura = celestial->AddAura(65508, celestial))
                    {
                        cdAura->SetDuration(30 * IN_MILLISECONDS);
                        cdAura->SetMaxDuration(30 * IN_MILLISECONDS);
                    }
                }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_CONSTELLATION_COMPLETE:
                RemoveStars();
                RemoveInvokeAura();
                completed = true;
                break;
            case ACTION_PLAYER_IN_ROOM:
                CastCooldownOnCelestials();
                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                if (!completed)
                    events.ScheduleEvent(EVENT_ALREADY_A_PLAYERS, 30 * IN_MILLISECONDS);
                break;
            case ACTION_RESET_CELESTIALS_DUSK:
                completed = false;
                break;
            }
        }

        void RemoveStars()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_6, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_FAIL_7, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_FAIL_8, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->DespawnOrUnsummon();
                }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ALREADY_A_PLAYERS:
                    if (completed)
                        return;
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    break;
                }
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_xuen_constellationAI(creature);
    }
};

class bfa_npc_xuen_constellation_fail : public CreatureScript
{
public:
    bfa_npc_xuen_constellation_fail() : CreatureScript("bfa_npc_xuen_constellation_fail") { }

    struct bfa_npc_xuen_constellation_failAI : public ScriptedAI
    {
        bfa_npc_xuen_constellation_failAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
            PhasingHandler::AddPhase(me, 2, true);
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_6, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void UpdateAI(uint32 diff)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->GetDistance(me) < 1.0f && player->HasAura(SPELL_INVOKE_TIGER_SPIRIT))
                    {
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL);
                        RemoveCorrectBeams();
                    }
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_xuen_constellation_failAI(creature);
    }
};

class bfa_npc_xuen_constellation_succes_1 : public CreatureScript
{
public:
    bfa_npc_xuen_constellation_succes_1() : CreatureScript("bfa_npc_xuen_constellation_succes_1") { }

    struct bfa_npc_xuen_constellation_succes_1AI : public ScriptedAI
    {
        bfa_npc_xuen_constellation_succes_1AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->AddAura(34126, me);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
            PhasingHandler::AddPhase(me, 2, true);
        }

        Creature* secondPoint()
        {
            return me->FindNearestCreature(NPC_XUEN_CONSTELLATION_CORRECT_2, 500.0f, true);
        }

        void UpdateAI(uint32 diff)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->GetDistance(me) < 1.0f)
                    {
                        me->CastSpell(me, SPELL_CONSTELATION_SUCCES);
                        if (Creature* second = secondPoint())
                            second->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    }
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_xuen_constellation_succes_1AI(creature);
    }
};

class bfa_npc_xuen_constellation_succes_2 : public CreatureScript
{
public:
    bfa_npc_xuen_constellation_succes_2() : CreatureScript("bfa_npc_xuen_constellation_succes_2") { }

    struct bfa_npc_xuen_constellation_succes_2AI : public ScriptedAI
    {
        bfa_npc_xuen_constellation_succes_2AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isSecondActive;
        bool notActive;

        void Reset()
        {
            isSecondActive = false;
            notActive = false;
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        Creature* firstPoint()
        {
            return me->FindNearestCreature(NPC_XUEN_CONSTELLATION_CORRECT_1, 500.0f, true);
        }

        Creature* nextPoint()
        {
            return me->FindNearestCreature(NPC_XUEN_CONSTELLATION_CORRECT_3, 500.0f, true);
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_6, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        RemoveCorrectBeams();
                        return;
                    }
                    isSecondActive = true;
                    if (Creature* first = firstPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* next = nextPoint())
                        next->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_xuen_constellation_succes_2AI(creature);
    }
};

class bfa_npc_xuen_constellation_succes_3 : public CreatureScript
{
public:
    bfa_npc_xuen_constellation_succes_3() : CreatureScript("bfa_npc_xuen_constellation_succes_3") { }

    struct bfa_npc_xuen_constellation_succes_3AI : public ScriptedAI
    {
        bfa_npc_xuen_constellation_succes_3AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isThirdActive;
        bool notActive;

        void Reset()
        {
            isThirdActive = false;
            notActive = false;
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_6, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        Creature* secondPoint()
        {
            return me->FindNearestCreature(NPC_XUEN_CONSTELLATION_CORRECT_2, 500.0f, true);
        }

        Creature* nextPoint()
        {
            return me->FindNearestCreature(NPC_XUEN_CONSTELLATION_CORRECT_4, 500.0f, true);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        RemoveCorrectBeams();
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        return;
                    }
                    isThirdActive = true;
                    if (Creature* first = secondPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* next = nextPoint())
                        next->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_xuen_constellation_succes_3AI(creature);
    }
};

class bfa_npc_xuen_constellation_succes_4 : public CreatureScript
{
public:
    bfa_npc_xuen_constellation_succes_4() : CreatureScript("bfa_npc_xuen_constellation_succes_4") { }

    struct bfa_npc_xuen_constellation_succes_4AI : public ScriptedAI
    {
        bfa_npc_xuen_constellation_succes_4AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isForthActive;
        bool notActive;

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_6, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        void Reset()
        {
            notActive = false;
            isForthActive = false;
        }

        Creature* thirdPoint()
        {
            return me->FindNearestCreature(NPC_XUEN_CONSTELLATION_CORRECT_3, 500.0f, true);
        }

        Creature* nextPoint()
        {
            return me->FindNearestCreature(NPC_XUEN_CONSTELLATION_CORRECT_5, 500.0f, true);
        }
        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        RemoveCorrectBeams();
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        return;
                    }
                    isForthActive = true;
                    if (Creature* first = thirdPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* next = nextPoint())
                        next->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_xuen_constellation_succes_4AI(creature);
    }
};

class bfa_npc_xuen_constellation_succes_5 : public CreatureScript
{
public:
    bfa_npc_xuen_constellation_succes_5() : CreatureScript("bfa_npc_xuen_constellation_succes_5") { }

    struct bfa_npc_xuen_constellation_succes_5AI : public ScriptedAI
    {
        bfa_npc_xuen_constellation_succes_5AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isFifthActive;
        bool notActive;

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_6, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        void Reset()
        {
            notActive = false;
            isFifthActive = false;
        }

        Creature* forthPoint()
        {
            return me->FindNearestCreature(NPC_XUEN_CONSTELLATION_CORRECT_4, 500.0f, true);
        }

        Creature* nextPoint()
        {
            return me->FindNearestCreature(NPC_XUEN_CONSTELLATION_CORRECT_6, 500.0f, true);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                    {
                        me->CastSpell(me, SPELL_CONSTELLATION_FAIL, true);
                        RemoveCorrectBeams();
                        return;
                    }
                    isFifthActive = true;
                    if (Creature* first = forthPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* next = nextPoint())
                        next->AI()->DoAction(ACTION_ACTIVE_POINTS);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_xuen_constellation_succes_5AI(creature);
    }
};

class bfa_npc_xuen_constellation_succes_6 : public CreatureScript
{
public:
    bfa_npc_xuen_constellation_succes_6() : CreatureScript("bfa_npc_xuen_constellation_succes_6") { }

    struct bfa_npc_xuen_constellation_succes_6AI : public ScriptedAI
    {
        bfa_npc_xuen_constellation_succes_6AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            PhasingHandler::AddPhase(me, 2, true);
            me->AddAura(SPELL_CONSTELLATION_STATIONARY, me);
        }

        bool isFifthActive;
        bool notActive;

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_RESET_POINTS:
                notActive = false;
                break;
            case ACTION_ACTIVE_POINTS:
                notActive = true;
                break;
            }
        }

        void RemoveCorrectBeams()
        {
            std::list<Creature*> correctBeams;
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_1, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_2, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_3, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_4, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_5, 500.0f);
            me->GetCreatureListWithEntryInGrid(correctBeams, NPC_XUEN_CONSTELLATION_CORRECT_6, 500.0f);

            if (correctBeams.empty())
                return;

            if (!correctBeams.empty())
                for (auto it = correctBeams.begin(); it != correctBeams.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->RemoveAura(SPELL_CELESTIAL_BEAM);
                    creature->AI()->DoAction(ACTION_RESET_POINTS);
                }
        }

        void Reset()
        {
            isFifthActive = false;
            notActive = false;
        }

        Creature* fifthPoint()
        {
            return me->FindNearestCreature(NPC_XUEN_CONSTELLATION_CORRECT_5, 500.0f, true);
        }

        Creature* Yulon()
        {
            return me->FindNearestCreature(NPC_XUEN, 500.0f, true);
        }

        Creature* pointthree()
        {
            return me->FindNearestCreature(NPC_XUEN_CONSTELLATION_CORRECT_3, 500.0f, true);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->GetDistance(me) < 1.0f)
                {
                    if (!notActive)
                        return;
                    isFifthActive = true;
                    if (Creature* first = fifthPoint())
                        first->CastSpell(me, SPELL_CELESTIAL_BEAM);
                    if (Creature* PointThree = pointthree())
                    {
                        PhasingHandler::AddPhase(PointThree, 1, true);
                        PointThree->DespawnOrUnsummon(5000);
                        PointThree->CastSpell(PointThree, 138656, true);
                        PhasingHandler::AddPhase(me, 1, false);
                    }
                    if (Creature* yulon = Yulon())
                        yulon->AI()->DoAction(ACTION_CONSTELLATION_COMPLETE);
                    me->CastSpell(me, SPELL_CONSTELATION_SUCCES, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_xuen_constellation_succes_6AI(creature);
    }
};

/*
######## XUEN CONSTELLATION END
*/

// 138298
class bfa_spell_fortitude_of_the_ox : public SpellScriptLoader
{
public:
    bfa_spell_fortitude_of_the_ox() : SpellScriptLoader("bfa_spell_fortitude_of_the_ox") { }

    class bfa_spell_fortitude_of_the_ox_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_fortitude_of_the_ox_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            int32 basePoints0 = int32(GetHitUnit()->CountPctFromMaxHealth(GetEffectValue()));

            GetCaster()->CastCustomSpell(GetHitUnit(), 138300, &basePoints0, NULL, NULL, true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_fortitude_of_the_ox_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_fortitude_of_the_ox_SpellScript();
    }
};

class bfa_npc_crane_rush_trigger : public CreatureScript
{
public:
    bfa_npc_crane_rush_trigger() : CreatureScript("bfa_npc_crane_rush_trigger") { }

    struct bfa_npc_crane_rush_triggerAI : public ScriptedAI
    {
        bfa_npc_crane_rush_triggerAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit*)
        {
            me->DespawnOrUnsummon(16 * IN_MILLISECONDS);
            me->AddAura(SPELL_A_RUSH_OF_CRANES, me);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_crane_rush_triggerAI(creature);
    }
};

class bfa_npc_crane_rush : public CreatureScript
{
public:
    bfa_npc_crane_rush() : CreatureScript("bfa_npc_crane_rush") { }

    struct bfa_npc_crane_rushAI : public ScriptedAI
    {
        bfa_npc_crane_rushAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit*)
        {
            //set_speed(4.0f);
            me->DespawnOrUnsummon(30 * IN_MILLISECONDS);
            me->SetDisplayId(46475);
            events.ScheduleEvent(EVENT_MAKE_A_RUN, 100);
            events.ScheduleEvent(EVENT_SELECT_ORIENTATION_AND_RUSH, 500);
        }

        Creature* Lulin()
        {
            return me->FindNearestCreature(NPC_LULIN, 7.0f, true);
        }

        Creature* Suen()
        {
            return me->FindNearestCreature(NPC_SUEN, 7.0f, true);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MAKE_A_RUN:
                {
                    int32 safeHp = 5;

                    if (Creature* suen = Suen())
                    {
                        if (suen->GetHealthPct() < safeHp)
                            return;

                        if (suen->GetDistance(me) < 7.0f)
                            suen->CastSpell(suen, SPELL_CRANE_RUSH_DAMAGE, true);
                    }

                    if (Creature* lulin = Lulin())
                    {
                        if (lulin->GetHealthPct() < safeHp)
                            return;

                        if (lulin->GetDistance(me) < 7.0f)
                            lulin->CastSpell(lulin, SPELL_CRANE_RUSH_DAMAGE, true);
                    }
                    events.ScheduleEvent(EVENT_MAKE_A_RUN, 500);
                    break;
                }
                case EVENT_SELECT_ORIENTATION_AND_RUSH:
                {
                    float orientation = 4.50f;
                    Position pos;
                    me->GetNearPoint(NULL, pos.m_positionX, pos.m_positionY, pos.m_positionZ, DEFAULT_WORLD_OBJECT_SIZE, 250, orientation);
                    me->GetMotionMaster()->MovePoint(0, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_crane_rushAI(creature);
    }
};

class bfa_npc_lurkers_in_the_night : public CreatureScript
{
public:
    bfa_npc_lurkers_in_the_night() : CreatureScript("bfa_npc_lurkers_in_the_night") { }

    struct bfa_npc_lurkers_in_the_nightAI : public ScriptedAI
    {
        bfa_npc_lurkers_in_the_nightAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit*)
        {
            me->SetInCombatWithZone();
            me->AddAura(SPELL_SHADOWED_VISUAL, me);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            events.ScheduleEvent(EVENT_CAST_DARKNESS, 2000);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_LURKER_VISIBLE:
                me->ClearUnitState(UNIT_STATE_ROOT);
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveAura(SPELL_SHADOWED_VISUAL);
                events.CancelEvent(EVENT_CAST_DARKNESS);
                break;
            case ACTION_LURKER_INVISIBLE:
                me->AddUnitState(UNIT_STATE_ROOT);
                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                me->AddAura(SPELL_SHADOWED_VISUAL, me);
                events.ScheduleEvent(EVENT_CAST_DARKNESS, 2000);
                break;
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CAST_DARKNESS:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 500.0f, true))
                        me->CastSpell(target, SPELL_DARKNESS);
                    events.ScheduleEvent(EVENT_CAST_DARKNESS, 2000);
                    break;
                }
            }
            if (!me->HasAura(SPELL_SHADOWED_VISUAL))
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_lurkers_in_the_nightAI(creature);
    }
};

class bfa_npc_twin_consorts_controler : public CreatureScript
{
public:
    bfa_npc_twin_consorts_controler() : CreatureScript("bfa_npc_twin_consorts_controler") { }

    struct bfa_npc_twin_consorts_controlerAI : public ScriptedAI
    {
        bfa_npc_twin_consorts_controlerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* instance;

        void Reset()
        {
            events.Reset();
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_BOSS_TIMERS_START:
                events.ScheduleEvent(EVENT_BERSERK, TIMER_BERSERK);
                if (instance)
                    instance->SetBossState(DATA_TWIN_CONSORTS, IN_PROGRESS);
                break;
            case ACTION_BOSS_TIMERS_WIPE:
                events.Reset();
                if (instance)
                    instance->SetBossState(DATA_TWIN_CONSORTS, NOT_STARTED);
                break;
            case ACTION_BOSS_TIMERS_DONE:
                break;
            }
        }

        Creature* GetLulin()
        {
            return me->FindNearestCreature(NPC_LULIN, 500.0f, true);
        }

        Creature* GetSuen()
        {
            return me->FindNearestCreature(NPC_SUEN, 500.0f, true);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_BERSERK:
                {
                    if (Creature* suen = GetSuen())
                        suen->AddAura(26662, suen);
                    if (Creature* lulin = GetLulin())
                        lulin->AddAura(26662, lulin);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_twin_consorts_controlerAI(creature);
    }
};

class bfa_npc_tidal_force_slow : public CreatureScript
{
public:
    bfa_npc_tidal_force_slow() : CreatureScript("bfa_npc_tidal_force_slow") { }

    struct bfa_npc_tidal_force_slowAI : public ScriptedAI
    {
        bfa_npc_tidal_force_slowAI(Creature* creature) : ScriptedAI(creature)
        {
            //set_speed(0.7f);
            me->AddAura(59635, me);
            me->SetObjectScale(3.0f);
        }

        uint32 despawnTimer;

        void Reset()
        {
            despawnTimer = 3000;
        }

        void UpdateAI(uint32 diff)
        {
            if (despawnTimer <= diff)
            {
                me->DespawnOrUnsummon();
            }
            else despawnTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_tidal_force_slowAI(creature);
    }
};

// cooldown between celestials - 65508
class bfa_spell_celestial_cooldown : public SpellScriptLoader
{
public:
    bfa_spell_celestial_cooldown() : SpellScriptLoader("bfa_spell_celestial_cooldown") { }

    class bfa_spell_celestial_cooldown_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_celestial_cooldown_AuraScript);

        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (!GetCaster())
                return;
            GetCaster()->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        }

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (!GetCaster())
                return;
            GetCaster()->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);
        }
        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_celestial_cooldown_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_celestial_cooldown_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_celestial_cooldown_AuraScript();
    }
};

void AddSC_bfa_boss_twin_consorts()
{
    new bfa_npc_twin_consorts_controler;
    new bfa_boss_suen;
    new bfa_boss_lulin;
    new bfa_npc_moon_lotus;
    new bfa_npc_moon_lotus_movement;
    new bfa_npc_star;
    new bfa_npc_ice_comet;
    new bfa_npc_melt_ice_comet;
    new bfa_npc_crane_rush;
    new bfa_npc_lurkers_in_the_night;
    new bfa_npc_crane_rush_trigger;
    new bfa_npc_tidal_force_slow;
    new bfa_npc_beast_of_nightmare;
    new bfa_npc_yulon_constellation;
    new bfa_npc_yulon_constellation_fail;
    new bfa_npc_yulon_constellation_succes_1;
    new bfa_npc_yulon_constellation_succes_2;
    new bfa_npc_yulon_constellation_succes_3;
    new bfa_npc_yulon_constellation_succes_4;
    new bfa_npc_yulon_constellation_succes_5;
    new bfa_npc_niuazo_constellation;
    new bfa_npc_niuzao_constellation_fail;
    new bfa_npc_niuzao_constellation_succes_1;
    new bfa_npc_niuzao_constellation_succes_2;
    new bfa_npc_niuzao_constellation_succes_3;
    new bfa_npc_niuzao_constellation_succes_4;
    new bfa_npc_niuzao_constellation_succes_5;
    new bfa_npc_chiji_constellation;
    new bfa_npc_chiji_constellation_fail;
    new bfa_npc_chiji_constellation_succes_1;
    new bfa_npc_chiji_constellation_succes_2;
    new bfa_npc_chiji_constellation_succes_3;
    new bfa_npc_chiji_constellation_succes_4;
    new bfa_npc_chiji_constellation_succes_5;
    new bfa_npc_chiji_constellation_succes_6;
    new bfa_npc_xuen_constellation;
    new bfa_npc_xuen_constellation_fail;
    new bfa_npc_xuen_constellation_succes_1;
    new bfa_npc_xuen_constellation_succes_2;
    new bfa_npc_xuen_constellation_succes_3;
    new bfa_npc_xuen_constellation_succes_4;
    new bfa_npc_xuen_constellation_succes_5;
    new bfa_npc_xuen_constellation_succes_6;

    //new bfa_spell_nuclear_inferno;
    new bfa_spell_tears_of_the_sun;
    new bfa_spell_tidal_force;
    new bfa_spell_fortitude_of_the_ox;
    new bfa_spell_invoke_celestials;
    new bfa_spell_celestial_cooldown;
}
