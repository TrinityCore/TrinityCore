#include "throne_of_thunder.h"
#include "Vehicle.h"
#include "SpellAuraEffects.h"
#include "SpellAuraDefines.h"

enum Spells
{
    // Iron Qon
    SPELL_THROW_SPEAR = 134925,
    SPELL_RETURN_SPEAR = 137712,
    SPELL_IMPALE = 134691,

    SPELL_IGNITE_CYCLONE = 136159, 
    SPELL_FREEZE_CYCLONE = 136153,
    SPELL_FIST_SMASH = 136146,
    SPELL_RISING_ANGER = 136323,

    // Roshak
    SPELL_MOLTEN_INFERNO = 134664,
    SPELL_MOLTEN_OVERLOAD = 137221,
    SPELL_UNLEASHED_FLAME = 139138,

    SPELL_BURNING_CINDERS_SPEAR = 136330, // visual on spear
    SPELL_BURNING_CINDERS = 134758, // trail visual too 
    SPELL_BURNING_CINDERS_DAMAGE = 137668,

    // Quetzal
    SPELL_ARCING_LIGHTNING_ZAP = 136192, // on on random target
    SPELL_ARCING_LIGHTNING = 136193, // on nearby players
    SPELL_ARCING_LIGHTNING_VISUAL = 136224,
    SPELL_ARCING_LIGHTNING_STUN = 136198, // npc creator

    SPELL_RUSHING_WINDS_STUN = 137654, // on players when hit by tornados
    SPELL_RUSHING_WINDS = 136161, // on tornados
    SPELL_RUSHING_WINDS_VISUAL = 136574, // trigger visual
    SPELL_RUSHING_WINDS_SPEED = 136590, // not used
    SPELL_RUSHING_WINDS_TORNADO_VISUAL = 135570,

    SPELL_ELECTRIFIED = 136615,
    SPELL_ELECTRIC_CHARGES = 137669,
    SPELL_STORM_CLOUD_VISUAL = 136421, // trail visual
    SPELL_STORM_CLOUD_SPEAR = 137657, // on spear

    // Damren
    SPELL_DEAD_ZONE = 137232,
    SPELL_DEAD_ZONE_DEBUFF = 135147,

    SPELL_DEAD_ZONE_1 = 137226,
    SPELL_DEAD_ZONE_2 = 137227,
    SPELL_DEAD_ZONE_3 = 137228,
    SPELL_DEAD_ZONE_4 = 137229,
    SPELL_DEAD_ZONE_5 = 137230,
    SPELL_DEAD_ZONE_6 = 137231,

    SPELL_DEAD_ZONE_FRONT = 135361,
    SPELL_DEAD_ZONE_BACK = 135225,
    SPELL_DEAD_ZONE_RIGHT = 135223,
    SPELL_DEAD_ZONE_LEFT = 135199,

    SPELL_FROZEN_RESILIENCE = 135144,
    SPELL_FREEZE = 135145,
    SPELL_SHATTER_SELF = 135146,
    SPELL_SHATTER_AOE = 137709,

    SPELL_FROZEN_BLOOD_AT = 136451, // areatrigger when spear is hit by visual | trail visual too 
    SPELL_FROZEN_BLOOD = 136449, // visual on spear
    SPELL_FROZEN_BLOOD_DAMAGE = 137664, // this is used when players are coming in contact with spear \ ground

    // heroic
    // Qeustzal
    SPELL_WHIRLING_WINDS_SUMMON = 77316,
    SPELL_WHIRLING_WINDS = 139167,
    SPELL_WHIRLING_WINDS_AT = 139166,

    // Damren
    SPELL_FROST_SPIKE = 139177,

    // freeze cyclone
    SPELL_FROZEN_SOLID = 136892,
    SPELL_FROZEN_SOLID_ICE_TOMB = 143776,
};

uint32 DeadZones[6] =
{
    SPELL_DEAD_ZONE_1,
    SPELL_DEAD_ZONE_2,
    SPELL_DEAD_ZONE_3,
    SPELL_DEAD_ZONE_4,
    SPELL_DEAD_ZONE_5,
    SPELL_DEAD_ZONE_6,
};

enum Creatures
{
    NPC_IRON_QON_SPEAR = 68480,

    NPC_DAMREN = 68081,
    NPC_QUESTZAL = 68080,
    NPC_ROSHAK = 68079,

    NPC_RUSHING_WINDS = 69703,
    NPC_RUSHING_WINDS_2 = 999280,
    NPC_RUSHING_WINDS_3 = 999281,
    NPC_RUSHING_WINDS_4 = 999282,
    NPC_RUSHING_WINDS_5 = 999283,
    NPC_RUSHING_WINDS_TRIGGER = 68852,
    NPC_WHIRLING_WINDS = 41245,
    NPC_LIGHTNING_CLOUD = 70660,

    NPC_TRAILS_HANDLER_1 = 999491,
    NPC_TRAILS_HANDLER_2 = 999492,
    NPC_TRAILS_HANDLER_3 = 999493,
    NPC_TRAILS_HANDLER_4 = 999494,

    NPC_ICE_TOMB = 71720,
};

Position const FirstRushingWind[8] =
{
    { 6036.76f, 4726.34f, 142.83f, 3.33f },
    { 5990.94f, 4710.38f, 142.83f, 3.48f },
    { 5991.69f, 4653.37f, 142.83f, 4.71f },
    { 6021.49f, 4631.92f, 142.83f, 5.66f },
    { 6082.12f, 4633.13f, 142.83f, 0.00f },
    { 6101.89f, 4658.11f, 142.83f, 0.83f },
    { 6102.25f, 4711.24f, 142.83f, 1.57f },
    { 6069.63f, 4724.77f, 142.83f, 3.04f },
};

Position const SecondRushingWind[7] =
{
    { 6051.40f, 4710.85f, 142.83f, 5.99f },
    { 6085.30f, 4698.50f, 142.83f, 5.87f },
    { 6084.66f, 4650.52f, 142.83f, 4.68f },
    { 6048.63f, 4637.36f, 142.83f, 3.54f },
    { 6016.11f, 4646.32f, 142.83f, 2.89f },
    { 5997.57f, 4673.21f, 142.83f, 2.11f },
    { 6006.72f, 4708.46f, 142.83f, 1.24f },
};

Position const ThirdRushingWind[7] =
{
    { 6014.21f, 4669.09f, 142.83f, 5.68f },
    { 6038.74f, 4652.73f, 142.83f, 2.62f },
    { 6066.38f, 4648.89f, 142.83f, 2.11f },
    { 6077.20f, 4673.67f, 142.83f, 3.07f },
    { 6063.22f, 4699.06f, 142.83f, 5.3f  },
    { 6047.18f, 4699.42f, 142.83f, 4.57f },
    { 6028.01f, 4697.76f, 142.83f, 5.83f },
};

Position const FourthRushingWind[6] =
{
    { 6046.01f, 4700.77f, 142.83f, 4.56f },
    { 6059.96f, 4689.29f, 142.83f, 3.45f },
    { 6059.84f, 4676.20f, 142.83f, 2.57f },
    { 6046.63f, 4670.15f, 142.83f, 2.88f },
    { 6030.33f, 4673.15f, 142.83f, 0.34f },
    { 6032.58f, 4692.41f, 142.83f, 5.38f },
};

enum Points
{
    POINT_1 = 1,
    POINT_2 = 2,
    POINT_3 = 3,
    POINT_4 = 4,
    POINT_5 = 5,
    POINT_6 = 6,
    POINT_7 = 7,
    POINT_8 = 8,
};

enum Timers
{
    TIMER_INIT = 0,

    TIMER_BERSERK = 12 * MINUTE * IN_MILLISECONDS,

    // Shared between first three phases
    TIMER_IMPALE = 20 * IN_MILLISECONDS,
    TIMER_THROW_SPEAR = 32 * IN_MILLISECONDS,
    TIMER_THROW_SPEAR_DOG = 5 * IN_MILLISECONDS,

    TIMER_SELECT_QUETZAL = 1 * IN_MILLISECONDS,
    TIMER_SELECT_DAMREN = 1 * IN_MILLISECONDS,

    // Ro'shak
    TIMER_ENERGY_GAIN = 2 * IN_MILLISECONDS,
    TIMER_UNLEASHED_FLAME = 3 * IN_MILLISECONDS,
    TIMER_MOLTEN_OVERLOAD = 1 * IN_MILLISECONDS,
    TIMER_MOLTEN_INFERNO = 15 * IN_MILLISECONDS,

    // Quetzal
    TIMER_ARCING_LIGHT = 30 * IN_MILLISECONDS,
    TIMER_WINDSTORM = 3 * MINUTE * IN_MILLISECONDS,

    // Damren
    TIMER_DEAD_ZONE = 10 * IN_MILLISECONDS,
    TIMER_FREEZE = 5 * IN_MILLISECONDS,

    // Last Phase
    TIMER_RISING_ANGER = 15 * IN_MILLISECONDS,
    TIMER_FIST_SMASH = 50 * IN_MILLISECONDS,
    TIMER_FIST_SMASH_SECOND = 30 * IN_MILLISECONDS,
    TIMER_IGNITE_CYCLONE_FIRE = 7 * IN_MILLISECONDS,
    TIMER_IGNITE_CYCLONE_FREEZE = 9 * IN_MILLISECONDS,
};

enum Events
{
    // Iron Qon
    EVENT_IMPALE = 1,
    EVENT_IMPALE_2,
    EVENT_IMPALE_3,
    EVENT_THROW_SPEAR, // roshak
    EVENT_THROW_SPEAR_DOG, // roshak
    EVENT_THROW_SPEAR_DOG_2, // quetzal
    EVENT_THROW_SPEAR_DOG_3, // damren
    EVENT_THROW_SPEAR_1, // quetzal
    EVENT_THROW_SPEAR_2, // damren

    EVENT_SELECT_QUETZAL,
    EVENT_SELECT_DAMREN,

    // Roshak
    EVENT_ENERGY_GAIN,
    EVENT_UNLEASHED_FLAME,
    EVENT_MOLTEN_OVERLOAD,
    EVENT_MOLTEN_INFERNO,
    EVENT_ADD_SAFE, // safer aura because spear is not supposed to spam cinder on ground if there are multiple spears 

    // HEROIC
    EVENT_WHIRLING,

    EVENT_CALL_THE_STORM,

    // Quetzal
    EVENT_RETURN_TO_COMBAT,
    EVENT_ARCING_LIGHT,
    EVENT_WINDSTORM,
    EVENT_WHIRL_AT,
    EVENT_INIT_WINDSTORM,
    EVENT_ATTACK_TARGET,

    // heroic
    EVENT_FROST_SPIKE,

    // Damren
    EVENT_DEAD_ZONE,
    EVENT_FREEZE,

    // Last Phase
    EVENT_IGNITE_CYCLONE,
    EVENT_RISING_ANGER,
    EVENT_FREEZE_NEARBY_PLAYERS,
    EVENT_FREEZE_CYCLONE,
    EVENT_FIST_SMASH,

    // Wind Rush events ( movement )
    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
    EVENT_7,
    EVENT_8,

    EVENT_CHECK_NEARBY_PLAYERS_RUSHING,
    EVENT_REMOVE_PLAYERS,
    // Spear
    EVENT_DO_FIRE,
    EVENT_DO_FROZEN,
    EVENT_DO_STORM,

    EVENT_EJECT_QON,
};

enum Actions
{
    ACTION_ENTER_LAST_PHASE = 1,
    ACTION_COUNT_DOGS_FLEE = 2, // used on heroic
    ACTION_ROSHAK_DIED = 3,
    ACTION_QUETZAL_DIED = 4,
    ACTION_START_COMBAT = 5, // shared between Quetzal and Damren
    ACTION_CAST_BURNING_TRAIL = 6,
    ACTION_CAST_FROZEN_BLOOD = 7,
    ACTION_CAST_STORM_CLOUD = 8,
    ACTION_CALLING_THE_STORM = 9,
    ACTION_STOP_CALLING_THE_STORM = 10,
    ACTION_BREAKING_THE_ICE = 11,
    ACTION_STOP_BREAKING_THE_ICE = 12,
    ACTION_SPARK_OF_MOLTEN_FLARE = 13,
    ACTION_STOP_SPARK_OF_MOLTEN_FLARE = 14,
    ACTION_START_FREEZING = 15,
    ACTION_LAST_PHASE_EJECTION = 16,
};

struct NotIgnited : public std::unary_function<Unit*, bool>
{
    NotIgnited() {}

    bool operator() (const Unit* pTarget)
    {
        return pTarget->HasAura(SPELL_IGNITE_CYCLONE);
    }
};

enum Talks
{
    TALK_AGGRO = 1,
    TALK_QUETZAL_SELECT = 2,
    TALK_DAMREN_SELECT = 3,
    TALK_ROSHAK_SELECT = 4,
    TALK_PHASE_2 = 5,
    TALK_WIPE = 6,
    TALK_DEATH = 7,
};

class bfa_boss_iron_qon : public CreatureScript
{
public:
    bfa_boss_iron_qon() : CreatureScript("bfa_boss_iron_qon") { }

    struct bfa_boss_iron_qonAI : public ScriptedAI
    {
        bfa_boss_iron_qonAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            instance = creature->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_ID, 137668, true); // burning cinders
            // taunt immunity - exploits..
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_THREAT, true);
        }

        EventMap events;
        InstanceScript* instance;
        bool mounted;
        bool lastPhase;
        uint8 dogs;

        Creature* damren()
        {
            return me->FindNearestCreature(NPC_DAMREN, 1500.0f, true);
        }

        Creature* quetzal()
        {
            return me->FindNearestCreature(NPC_QUESTZAL, 1500.0f, true);
        }

        Creature* roshak()
        {
            return me->FindNearestCreature(NPC_ROSHAK, 1500.0f, true);
        }

        Creature* Spear()
        {
            return me->FindNearestCreature(NPC_IRON_QON_SPEAR, 1500.0f, true);
        }

        void Reset()
        {
            mounted = false;
            lastPhase = false;
            dogs = 0;
            events.Reset();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            DespawnCreature(NPC_IRON_QON_SPEAR);
            DespawnCreature(NPC_RUSHING_WINDS);
            DespawnCreature(NPC_LIGHTNING_CLOUD);
            DespawnCreature(NPC_WHIRLING_WINDS);
            DespawnCreature(NPC_RUSHING_WINDS_2);
            DespawnCreature(NPC_RUSHING_WINDS_3);
            DespawnCreature(NPC_RUSHING_WINDS_4);
            DespawnCreature(NPC_RUSHING_WINDS_5);
            DespawnCreature(NPC_RUSHING_WINDS_TRIGGER);
            RespawnQuilens();

            if (instance)
                instance->SetBossState(DATA_IRON_QON, NOT_STARTED);
        }

        void DespawnCreature(uint32 entry)
        {
            std::list<Creature*> creatureList;
            GetCreatureListWithEntryInGrid(creatureList, me, entry, 500.0f);
            if (!creatureList.empty())
                for (auto NowCreature : creatureList)
                    NowCreature->DespawnOrUnsummon();
        }

        void RespawnQuilens()
        {
            std::list<Creature*> quilens;
            me->GetCreatureListWithEntryInGrid(quilens, NPC_DAMREN, 500.0f);
            me->GetCreatureListWithEntryInGrid(quilens, NPC_ROSHAK, 500.0f);
            me->GetCreatureListWithEntryInGrid(quilens, NPC_QUESTZAL, 500.0f);
            if (quilens.empty())
                return;
            for (auto it = quilens.begin(); it != quilens.end(); ++it)
            {
                Creature* creature = *it;
                if (creature->isDead())
                    creature->Respawn();
            }
        }

        void RemoveArcingLightning()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    player->RemoveAura(136193);
        }

        void EnterEvadeMode(EvadeReason w)
        {
            ScriptedAI::EnterEvadeMode();
            Talk(TALK_WIPE);
            me->ExitVehicle();
            RemoveArcingLightning();
            if (instance)
                instance->SetBossState(DATA_IRON_QON, FAIL);
        }

        void JustDied(Unit*)
        {
            RemoveArcingLightning();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            Talk(TALK_DEATH);
            DespawnCreature(NPC_IRON_QON_SPEAR);
            DespawnCreature(NPC_RUSHING_WINDS);
            DespawnCreature(NPC_LIGHTNING_CLOUD);
            DespawnCreature(NPC_WHIRLING_WINDS);
            DespawnCreature(NPC_RUSHING_WINDS_2);
            DespawnCreature(NPC_RUSHING_WINDS_3);
            DespawnCreature(NPC_RUSHING_WINDS_4);
            DespawnCreature(NPC_RUSHING_WINDS_5);
            DespawnCreature(NPC_RUSHING_WINDS_TRIGGER);
            if (instance)
                instance->SetBossState(DATA_IRON_QON, DONE);
        }

        void EnterCombat(Unit*)
        {
            if (instance)
            {
                if (!me->GetMap()->IsLFR() && instance->GetBossState(DATA_DARK_ANIMUS) != DONE)
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            if (player->IsAlive())
                                player->Kill(player);
                    return;
                }
            }

            Talk(TALK_AGGRO);
            if (Creature* rosh = roshak())
                rosh->SetInCombatWithZone();
            if (Creature* ren = damren())
                ren->SetInCombatWithZone();
            if (Creature* quet = quetzal())
                quet->SetInCombatWithZone();

            if (Creature* rosh = roshak())
                me->EnterVehicle(rosh, 0);
            Talk(TALK_ROSHAK_SELECT);
            mounted = true;
            events.ScheduleEvent(EVENT_IMPALE, TIMER_IMPALE);
            events.ScheduleEvent(EVENT_THROW_SPEAR, TIMER_THROW_SPEAR);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            if (instance)
                instance->SetBossState(DATA_IRON_QON, IN_PROGRESS);
        }

        void DogsToAttackHEROIC()
        {
            std::list<Creature*> quilens;
            me->GetCreatureListWithEntryInGrid(quilens, NPC_ROSHAK, 500.0f);
            me->GetCreatureListWithEntryInGrid(quilens, NPC_DAMREN, 500.0f);
            me->GetCreatureListWithEntryInGrid(quilens, NPC_QUESTZAL, 500.0f);

            if (quilens.empty())
                return;

            for (auto dog = quilens.begin(); dog != quilens.end(); ++dog)
            {
                Creature* activeDog = *dog;

                activeDog->RemoveAura(42716);
                activeDog->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                activeDog->GetMotionMaster()->Clear();
                activeDog->GetMotionMaster()->MoveChase(me->GetVictim());
                //activeDog->AI()->DoAction(ACTION_LAST_PHASE_EJECTION);
            }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_ENTER_LAST_PHASE:
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_THREAT, false);
                Talk(TALK_PHASE_2);
                me->ExitVehicle();
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                mounted = false;
                lastPhase = true;
                events.CancelEvent(EVENT_THROW_SPEAR);
                events.CancelEvent(EVENT_THROW_SPEAR_DOG);
                events.CancelEvent(EVENT_THROW_SPEAR_1);
                events.CancelEvent(EVENT_THROW_SPEAR_2);
                events.CancelEvent(EVENT_THROW_SPEAR_1);
                events.CancelEvent(EVENT_THROW_SPEAR_2);
                events.CancelEvent(EVENT_IMPALE);
                events.ScheduleEvent(EVENT_IGNITE_CYCLONE, TIMER_IGNITE_CYCLONE_FIRE);
                events.ScheduleEvent(EVENT_FREEZE_CYCLONE, TIMER_IGNITE_CYCLONE_FREEZE);
                events.ScheduleEvent(EVENT_FIST_SMASH, TIMER_FIST_SMASH);
                events.ScheduleEvent(EVENT_RISING_ANGER, TIMER_RISING_ANGER);
                if (me->GetMap()->IsHeroic())
                {
                    DogsToAttackHEROIC();
                    if (Creature* rosh = roshak())
                        rosh->AI()->DoAction(ACTION_LAST_PHASE_EJECTION);
                    if (Creature* quet = quetzal())
                        quet->AI()->DoAction(ACTION_LAST_PHASE_EJECTION);
                }
                break;
            case ACTION_COUNT_DOGS_FLEE:
                if (me->GetMap()->IsHeroic())
                    DogsCounts();
                break;
            case ACTION_ROSHAK_DIED:
                Talk(TALK_QUETZAL_SELECT);
                if (Creature* quet = quetzal())
                    quet->AI()->DoAction(ACTION_STOP_CALLING_THE_STORM);

                if (lastPhase)
                    return;
                events.ScheduleEvent(EVENT_SELECT_QUETZAL, TIMER_SELECT_QUETZAL);
                events.CancelEvent(EVENT_THROW_SPEAR);
                events.CancelEvent(EVENT_IMPALE);
                events.ScheduleEvent(EVENT_IMPALE_2, TIMER_IMPALE);
                events.CancelEvent(EVENT_THROW_SPEAR_DOG);
                events.ScheduleEvent(EVENT_THROW_SPEAR_1, TIMER_THROW_SPEAR);
                break;
            case ACTION_QUETZAL_DIED:
                Talk(TALK_DAMREN_SELECT);
                if (Creature* damr = damren())
                    damr->AI()->DoAction(ACTION_STOP_BREAKING_THE_ICE);

                if (lastPhase)
                    return;
                events.CancelEvent(EVENT_THROW_SPEAR_1);
                events.CancelEvent(EVENT_IMPALE_2);
                events.CancelEvent(EVENT_THROW_SPEAR_DOG_2);
                events.ScheduleEvent(EVENT_SELECT_DAMREN, TIMER_SELECT_DAMREN);
                events.ScheduleEvent(EVENT_THROW_SPEAR_2, TIMER_THROW_SPEAR);
                events.ScheduleEvent(EVENT_IMPALE_3, TIMER_IMPALE);
                break;
            }
        }

        void DogsCounts()
        {
            ++dogs;

            if (dogs == 1)
                me->AI()->DoAction(ACTION_ROSHAK_DIED);
            if (dogs == 2)
                me->AI()->DoAction(ACTION_QUETZAL_DIED);
            if (dogs == 3)
                me->AI()->DoAction(ACTION_ENTER_LAST_PHASE);
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
                case EVENT_IMPALE:
                    if (Creature* rosh = roshak())
                        if (Unit* target = rosh->GetVictim())
                            me->CastSpell(target, SPELL_IMPALE);
                    events.ScheduleEvent(EVENT_IMPALE, TIMER_IMPALE);
                    break;
                case EVENT_IMPALE_2:
                    if (Creature* quet = quetzal())
                        if (Unit* target = quet->GetVictim())
                            me->CastSpell(target, SPELL_IMPALE);
                    events.ScheduleEvent(EVENT_IMPALE_2, TIMER_IMPALE);
                    break;
                case EVENT_IMPALE_3:
                    if (Creature* ren = damren())
                        if (Unit* target = ren->GetVictim())
                            me->CastSpell(target, SPELL_IMPALE);
                    events.ScheduleEvent(EVENT_IMPALE_3, TIMER_IMPALE);
                    break;
                case EVENT_THROW_SPEAR:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        me->CastSpell((*itr), SPELL_THROW_SPEAR);

                    events.ScheduleEvent(EVENT_THROW_SPEAR, TIMER_THROW_SPEAR);
                    events.ScheduleEvent(EVENT_THROW_SPEAR_DOG, TIMER_THROW_SPEAR_DOG);
                    break;
                }
                case EVENT_THROW_SPEAR_1:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        me->CastSpell((*itr), SPELL_THROW_SPEAR);

                    events.ScheduleEvent(EVENT_THROW_SPEAR_1, TIMER_THROW_SPEAR);
                    events.ScheduleEvent(EVENT_THROW_SPEAR_DOG_2, TIMER_THROW_SPEAR_DOG);
                    break;
                }
                case EVENT_THROW_SPEAR_2:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        me->CastSpell((*itr), SPELL_THROW_SPEAR);

                    events.ScheduleEvent(EVENT_THROW_SPEAR_2, TIMER_THROW_SPEAR);
                    events.ScheduleEvent(EVENT_THROW_SPEAR_DOG_3, TIMER_THROW_SPEAR_DOG);
                    break;
                }
                case EVENT_THROW_SPEAR_DOG: // Roshak
                {
                    if (Creature* rosh = roshak())
                    {
                        if (Creature* spear = Spear())
                        {
                            rosh->CastSpell(spear, SPELL_BURNING_CINDERS_SPEAR, true);
                            spear->CastSpell(spear, SPELL_BURNING_CINDERS);
                            spear->AI()->DoAction(ACTION_CAST_BURNING_TRAIL);
                        }
                    }
                    break;
                }
                case EVENT_THROW_SPEAR_DOG_2: // Quetzal
                {
                    if (Creature* quet = quetzal())
                    {
                        if (Creature* spear = Spear())
                        {
                            quet->CastSpell(spear, SPELL_STORM_CLOUD_SPEAR, true);
                            spear->CastSpell(spear, SPELL_STORM_CLOUD_VISUAL);
                            spear->AI()->DoAction(ACTION_CAST_STORM_CLOUD);
                        }
                    }
                    break;
                }
                case EVENT_THROW_SPEAR_DOG_3: // Damren
                {
                    if (Creature* damre = damren())
                    {
                        if (Creature* spear = Spear())
                        {
                            damre->CastSpell(spear, SPELL_FROZEN_BLOOD, true);
                            spear->CastSpell(spear, SPELL_FROZEN_BLOOD_AT);
                            spear->AI()->DoAction(ACTION_CAST_FROZEN_BLOOD);
                        }
                    }
                    break;
                }
                case EVENT_FIST_SMASH:
                    me->CastSpell(me, SPELL_FIST_SMASH);
                    events.ScheduleEvent(EVENT_FIST_SMASH, TIMER_FIST_SMASH_SECOND);
                    break;
                case EVENT_RISING_ANGER:
                    me->AddAura(SPELL_RISING_ANGER, me);
                    events.ScheduleEvent(EVENT_RISING_ANGER, TIMER_RISING_ANGER);
                    break;
                case EVENT_IGNITE_CYCLONE:
                    IgniteCyclons();
                    break;
                case EVENT_FREEZE_CYCLONE:
                    FreezeCyclons();
                    break;
                case EVENT_SELECT_QUETZAL:
                {
                    me->ExitVehicle();
                    if (Creature* quet = quetzal())
                    {
                        me->EnterVehicle(quet, 0);
                        quet->AI()->DoAction(ACTION_START_COMBAT);
                    }
                    break;
                }
                case EVENT_SELECT_DAMREN:
                {
                    me->ExitVehicle();
                    if (Creature* dam = damren())
                    {
                        me->EnterVehicle(dam, 0);
                        dam->AI()->DoAction(ACTION_START_COMBAT);
                    }
                    break;
                }
                }
            }
            if (!mounted)
                DoMeleeAttackIfReady();
        }

        void IgniteCyclons()
        {
            std::list<Creature*> cyclone;
            me->GetCreatureListWithEntryInGrid(cyclone, NPC_RUSHING_WINDS, 500.0f);
            me->GetCreatureListWithEntryInGrid(cyclone, NPC_RUSHING_WINDS_2, 500.0f);
            if (cyclone.empty())
                return;
            if (cyclone.size() >= 2)
                Trinity::Containers::RandomResize(cyclone, 2);
            for (auto it = cyclone.begin(); it != cyclone.end(); ++it)
            {
                Creature* creature = *it;
                creature->AddAura(SPELL_IGNITE_CYCLONE, creature);
            }
        }

        void FreezeCyclons()
        {
            std::list<Creature*> cyclone;
            me->GetCreatureListWithEntryInGrid(cyclone, NPC_RUSHING_WINDS_3, 500.0f);

            cyclone.remove_if(NotIgnited());

            if (!cyclone.empty())
                for (auto it = cyclone.begin(); it != cyclone.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->AddAura(SPELL_FREEZE_CYCLONE, creature);
                    creature->AI()->DoAction(ACTION_START_FREEZING);
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_boss_iron_qonAI(creature);
    }
};

enum EventFromPhaseThree
{
    EVENT_PHASE_THREE_EVENT = 1,
    EVENT_PHASE_THREE_EVENT_2 = 2,
};

class bfa_npc_roshak : public CreatureScript
{
public:
    bfa_npc_roshak() : CreatureScript("bfa_npc_roshak") { }

    struct bfa_npc_roshakAI : public ScriptedAI
    {
        bfa_npc_roshakAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            //me->SetClass(UNIT_CLASS_ROGUE);
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->ApplySpellImmune(0, IMMUNITY_ID, 137668, true); // burning cinders
        }

        EventMap events;
        InstanceScript* instance;
        bool flee;

        void Reset()
        {
            flee = false;
            me->SetHealth(me->GetMaxHealth());
            events.Reset();
            me->ClearUnitState(UNIT_STATE_ROOT);
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
            if (Creature* qon = IronQon())
                qon->ExitVehicle();
        }

        Creature* IronQon()
        {
            return me->FindNearestCreature(NPC_IRON_QON, 500.0f, true);
        }

        void JustDied(Unit*)
        {
            if (Creature* qon = IronQon())
                qon->AI()->DoAction(ACTION_ROSHAK_DIED);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            if (me->GetMap()->IsHeroic())
            {
                if (me->HealthBelowPct(25) && !flee)
                {
                    flee = true;
                    if (Creature* qon = IronQon())
                    {
                        qon->ExitVehicle();
                        qon->AI()->DoAction(ACTION_COUNT_DOGS_FLEE);
                        events.Reset();
                        me->SetCanFly(true);
                        me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                        me->GetMotionMaster()->MovePoint(600, 6017.59f, 4718.26f, 167.87f, false);
                    }
                }
            }
        }

        void MovementInform(uint32 type, uint32 pointId)
        {
            switch (pointId)
            {
            case 600:
                me->AddUnitState(UNIT_STATE_ROOT);
                break;
            }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_SPARK_OF_MOLTEN_FLARE:
                events.ScheduleEvent(EVENT_ENERGY_GAIN, TIMER_ENERGY_GAIN);
                events.ScheduleEvent(EVENT_UNLEASHED_FLAME, TIMER_UNLEASHED_FLAME);
                break;
            case ACTION_STOP_SPARK_OF_MOLTEN_FLARE:
                events.CancelEvent(EVENT_UNLEASHED_FLAME);
                events.CancelEvent(EVENT_ENERGY_GAIN);
                break;
            case ACTION_LAST_PHASE_EJECTION:
                events.ScheduleEvent(EVENT_PHASE_THREE_EVENT, 5000);
                events.ScheduleEvent(EVENT_PHASE_THREE_EVENT_2, 1000);
                events.ScheduleEvent(EVENT_EJECT_QON, 5000);
                break;
            }
        }

        void SetBossAndAddsInCombat()
        {
            std::list<Creature*> ironqon;
            me->GetCreatureListWithEntryInGrid(ironqon, BOSS_IRON_QON, 2000.0f);
            me->GetCreatureListWithEntryInGrid(ironqon, NPC_DAMREN, 2000.0f);
            me->GetCreatureListWithEntryInGrid(ironqon, NPC_QUESTZAL, 2000.0f);

            if (!ironqon.empty())
                for (std::list<Creature*>::const_iterator itr = ironqon.begin(); itr != ironqon.end(); ++itr)
                {
                    Creature* npcs = (*itr);

                    if (!npcs->IsInCombat())
                        npcs->SetInCombatWithZone();
                }
        }

        void EnterCombat(Unit*)
        {
            if (Creature* ironqon = IronQon())
            {
                if (ironqon->HasAura(9454))
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            if (player->IsAlive())
                                player->Kill(player);
                    return;
                }
            }
            SetBossAndAddsInCombat();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            me->SetPower(POWER_ENERGY, 0);
            events.ScheduleEvent(EVENT_ENERGY_GAIN, TIMER_ENERGY_GAIN);
            events.ScheduleEvent(EVENT_MOLTEN_INFERNO, TIMER_MOLTEN_INFERNO);
            events.ScheduleEvent(EVENT_MOLTEN_OVERLOAD, TIMER_MOLTEN_OVERLOAD);
            events.ScheduleEvent(EVENT_UNLEASHED_FLAME, TIMER_UNLEASHED_FLAME);
            if (me->GetMap()->IsHeroic())
            {
                if (Creature* quet = quetzal())
                    quet->AI()->DoAction(ACTION_CALLING_THE_STORM);
            }
        }

        Creature* quetzal()
        {
            return me->FindNearestCreature(NPC_QUESTZAL, 500.0f, true);
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
                case EVENT_PHASE_THREE_EVENT:
                {
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 5);
                    if (me->GetPower(POWER_ENERGY) > 30)
                    {
                        std::list<Player*> players;
                        Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                            if (Player* player = i->GetSource())
                                if (player->IsAlive())
                                    players.push_back(player);
                        Player* validTarget = NULL;
                        uint32 expectedPlayers = me->GetMap()->Is25ManRaid() ? 5 : 3;
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
                            me->CastSpell(validTarget, SPELL_UNLEASHED_FLAME);
                            me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - 30);
                        }
                    }
                    events.ScheduleEvent(EVENT_PHASE_THREE_EVENT, 3000);
                    break;
                }
                case EVENT_PHASE_THREE_EVENT_2:
                    if (me->GetPower(POWER_ENERGY) == 100)
                    {
                        me->CastSpell(me, SPELL_MOLTEN_OVERLOAD);
                    }
                    events.ScheduleEvent(EVENT_PHASE_THREE_EVENT_2, 1000);
                    break;
                case EVENT_EJECT_QON:
                    if (Vehicle* meVeh = me->GetVehicleKit())
                        meVeh->RemoveAllPassengers();
                    events.ScheduleEvent(EVENT_EJECT_QON, 3000);
                    break;
                case EVENT_ENERGY_GAIN:
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 5);
                    events.ScheduleEvent(EVENT_ENERGY_GAIN, TIMER_ENERGY_GAIN);
                    break;
                case EVENT_MOLTEN_OVERLOAD:
                    if (me->GetPower(POWER_ENERGY) == 100)
                    {
                        me->CastSpell(me, SPELL_MOLTEN_OVERLOAD);
                    }
                    events.ScheduleEvent(EVENT_MOLTEN_OVERLOAD, TIMER_MOLTEN_OVERLOAD);
                    break;
                case EVENT_MOLTEN_INFERNO:
                    if (me->GetPower(POWER_ENERGY) > 10)
                    {
                        me->CastSpell(me, SPELL_MOLTEN_INFERNO);
                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - 10);
                    }
                    events.ScheduleEvent(EVENT_MOLTEN_INFERNO, TIMER_MOLTEN_INFERNO);
                    break;
                case EVENT_UNLEASHED_FLAME:
                    if (me->GetPower(POWER_ENERGY) > 30)
                    {
                        std::list<Player*> players;
                        Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                            if (Player* player = i->GetSource())
                                if (player->IsAlive())
                                    players.push_back(player);
                        Player* validTarget = NULL;
                        uint32 expectedPlayers = me->GetMap()->Is25ManRaid() ? 5 : 3;
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
                            me->CastSpell(validTarget, SPELL_UNLEASHED_FLAME);
                            me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - 30);
                        }
                    }
                    events.ScheduleEvent(EVENT_UNLEASHED_FLAME, TIMER_UNLEASHED_FLAME);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_roshakAI(creature);
    }
};

class bfa_npc_quetzal : public CreatureScript
{
public:
    bfa_npc_quetzal() : CreatureScript("bfa_npc_quetzal") { }

    struct bfa_npc_quetzalAI : public ScriptedAI
    {
        bfa_npc_quetzalAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* instance;
        bool flee;

        void Reset()
        {
            flee = false;

            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->ClearUnitState(UNIT_STATE_ROOT);
            events.Reset();
            if (Creature* qon = IronQon())
                qon->ExitVehicle();
        }

        Creature* IronQon()
        {
            return me->FindNearestCreature(NPC_IRON_QON, 500.0f, true);
        }

        void JustDied(Unit*)
        {
            if (Creature* qon = IronQon())
                qon->AI()->DoAction(ACTION_QUETZAL_DIED);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        Creature* damren()
        {
            return me->FindNearestCreature(NPC_DAMREN, 500.0f, true);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_START_COMBAT:
            {
                if (me->GetMap()->IsHeroic())
                {
                    if (Creature* damr = damren())
                        damr->AI()->DoAction(ACTION_BREAKING_THE_ICE);
                }
                events.ScheduleEvent(EVENT_ARCING_LIGHT, TIMER_ARCING_LIGHT);
                events.ScheduleEvent(EVENT_WINDSTORM, 45 * IN_MILLISECONDS);
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->ClearUnitState(UNIT_STATE_ROOT);
                me->GetMotionMaster()->Clear();
                if (Creature* qon = IronQon())
                    me->GetMotionMaster()->MoveChase(qon->GetVictim());
                break;
            }
            case ACTION_CALLING_THE_STORM:
                events.ScheduleEvent(EVENT_CALL_THE_STORM, 8000);
                break;
            case ACTION_STOP_CALLING_THE_STORM:
                events.CancelEvent(EVENT_CALL_THE_STORM);
                break;
            case ACTION_LAST_PHASE_EJECTION:
                events.ScheduleEvent(EVENT_EJECT_QON, 5000);
                events.ScheduleEvent(EVENT_ARCING_LIGHT, TIMER_ARCING_LIGHT);
                break;
            }
        }

        void SetBossAndAddsInCombat()
        {
            std::list<Creature*> ironqon;
            me->GetCreatureListWithEntryInGrid(ironqon, BOSS_IRON_QON, 2000.0f);
            me->GetCreatureListWithEntryInGrid(ironqon, NPC_DAMREN, 2000.0f);
            me->GetCreatureListWithEntryInGrid(ironqon, NPC_ROSHAK, 2000.0f);

            if (!ironqon.empty())
                for (std::list<Creature*>::const_iterator itr = ironqon.begin(); itr != ironqon.end(); ++itr)
                {
                    Creature* npcs = (*itr);

                    if (!npcs->IsInCombat())
                        npcs->SetInCombatWithZone();
                }
        }

        void EnterCombat(Unit*)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            SetBossAndAddsInCombat();
        }


        void DamageTaken(Unit* who, uint32& damage)
        {
            if (me->GetMap()->IsHeroic())
            {
                if (me->HealthBelowPct(25) && !flee)
                {
                    flee = true;
                    if (Creature* qon = IronQon())
                    {
                        qon->ExitVehicle();
                        qon->AI()->DoAction(ACTION_COUNT_DOGS_FLEE);
                        events.Reset();
                        me->SetCanFly(true);
                        me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                        me->GetMotionMaster()->MovePoint(600, 6017.59f, 4718.26f, 167.87f, false);
                    }
                }
            }
        }

        void MovementInform(uint32 type, uint32 pointId)
        {
            switch (pointId)
            {
            case 500:
                me->AddUnitState(UNIT_STATE_ROOT);
                break;
            case 600:
                me->AddUnitState(UNIT_STATE_ROOT);
                break;
            }
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
                case EVENT_EJECT_QON:
                    if (Vehicle* meVeh = me->GetVehicleKit())
                        meVeh->RemoveAllPassengers();
                    events.ScheduleEvent(EVENT_EJECT_QON, 1000);
                    break;
                case EVENT_ARCING_LIGHT:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    {
                        me->CastSpell((*itr), SPELL_ARCING_LIGHTNING_ZAP);
                        std::ostringstream str;
                        str << (*itr)->GetName() << " is affected by |cFFF00000|Hspell:136192|h[Lightning Storm]|h|r!";
                        me->TextEmote(str.str().c_str(), 0, true);
                    }
                    events.ScheduleEvent(EVENT_ARCING_LIGHT, TIMER_ARCING_LIGHT);
                    break;
                }
                case EVENT_WINDSTORM:
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MovePoint(500, 6017.59f, 4718.26f, 167.87f, false);
                    me->SummonCreature(NPC_RUSHING_WINDS_TRIGGER, 6045.30f, 4690.59f, 142.83f, 1.58f, TEMPSUMMON_TIMED_DESPAWN, 20000);
                    events.ScheduleEvent(EVENT_WINDSTORM, TIMER_WINDSTORM);
                    events.ScheduleEvent(EVENT_ATTACK_TARGET, 20000);
                    break;
                case EVENT_ATTACK_TARGET:
                    me->ClearUnitState(UNIT_STATE_ROOT);
                    me->GetMotionMaster()->Clear();
                    if (Creature* qon = IronQon())
                        me->GetMotionMaster()->MoveChase(qon->GetVictim());
                    break;
                case EVENT_CALL_THE_STORM:
                    if (Unit* random = SelectTarget(SELECT_TARGET_FARTHEST, 0, 500.0f, true))
                    {
                        if (Creature* winds = me->SummonCreature(41245, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 15000))
                        {
                            winds->GetMotionMaster()->MovePoint(500, random->GetPositionX(), random->GetPositionY(), random->GetPositionZ(), false);
                            //winds->AI()->AttackStart(random);
                            //winds->AddThreat(random, 99999999.9f);
                        }
                    }
                    events.ScheduleEvent(EVENT_CALL_THE_STORM, 30000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_quetzalAI(creature);
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
            );
    }
};

enum EventFromPhaseThrees
{
    EVENT_PHASE_THREE_DAMREN = 1,
};

class bfa_npc_damren : public CreatureScript
{
public:
    bfa_npc_damren() : CreatureScript("bfa_npc_damren") { }

    struct bfa_npc_damrenAI : public ScriptedAI
    {
        bfa_npc_damrenAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* instance;
        bool flee;

        void Reset()
        {
            flee = false;
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            events.Reset();
            if (Creature* qon = IronQon())
                qon->ExitVehicle();
            if (me->HasReactState(REACT_PASSIVE))
                me->SetReactState(REACT_AGGRESSIVE);
        }

        Creature* IronQon()
        {
            return me->FindNearestCreature(NPC_IRON_QON, 500.0f, true);
        }

        Creature* roshak()
        {
            return me->FindNearestCreature(NPC_ROSHAK, 500.0f, true);
        }

        void JustDied(Unit*)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            if (Creature* qon = IronQon())
                qon->AI()->DoAction(ACTION_ENTER_LAST_PHASE);
        }

        void SetBossAndAddsInCombat()
        {
            std::list<Creature*> ironqon;
            me->GetCreatureListWithEntryInGrid(ironqon, BOSS_IRON_QON, 2000.0f);
            me->GetCreatureListWithEntryInGrid(ironqon, NPC_QUESTZAL, 2000.0f);
            me->GetCreatureListWithEntryInGrid(ironqon, NPC_ROSHAK, 2000.0f);

            if (!ironqon.empty())
                for (std::list<Creature*>::const_iterator itr = ironqon.begin(); itr != ironqon.end(); ++itr)
                {
                    Creature* npcs = (*itr);

                    if (!npcs->IsInCombat())
                        npcs->SetInCombatWithZone();
                }
        }

        void EnterCombat(Unit*)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            SetBossAndAddsInCombat();
        }

        void HandleDeadZone(uint32 selectAura)
        {
            switch (selectAura)
            {
            case SPELL_DEAD_ZONE_1:
                me->CastSpell(me, SPELL_DEAD_ZONE_1, true);
                break;
            case SPELL_DEAD_ZONE_2:
                me->CastSpell(me, SPELL_DEAD_ZONE_2, true);
                break;
            case SPELL_DEAD_ZONE_3:
                me->CastSpell(me, SPELL_DEAD_ZONE_3, true);
                break;
            case SPELL_DEAD_ZONE_4:
                me->CastSpell(me, SPELL_DEAD_ZONE_4, true);
                break;
            case SPELL_DEAD_ZONE_5:
                me->CastSpell(me, SPELL_DEAD_ZONE_5, true);
                break;
            case SPELL_DEAD_ZONE_6:
                me->CastSpell(me, SPELL_DEAD_ZONE_6, true);
                break;
            }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_START_COMBAT:
            {
                if (Creature* ros = roshak())
                    ros->AI()->DoAction(ACTION_SPARK_OF_MOLTEN_FLARE);
                me->AddAura(SPELL_FROZEN_RESILIENCE, me);
                events.ScheduleEvent(EVENT_DEAD_ZONE, TIMER_DEAD_ZONE);
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->ClearUnitState(UNIT_STATE_ROOT);
                me->GetMotionMaster()->Clear();
                if (Creature* qon = IronQon())
                    me->GetMotionMaster()->MoveChase(qon->GetVictim());
                break;
            }
            case ACTION_BREAKING_THE_ICE:
                events.ScheduleEvent(EVENT_FROST_SPIKE, 8000);
                break;
            case ACTION_STOP_BREAKING_THE_ICE:
                events.CancelEvent(EVENT_FROST_SPIKE);
                break;
            case ACTION_LAST_PHASE_EJECTION:
                events.ScheduleEvent(EVENT_PHASE_THREE_DAMREN, 10 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_EJECT_QON, 5000);
                break;
            }
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            if (who->HasAura(SPELL_DEAD_ZONE_DEBUFF))
            {
                damage = 0;
                me->SetHealth(me->GetHealth() + 1);
                me->SetHealth(me->GetHealth() - 1);
            }

            if (me->GetMap()->IsHeroic())
            {
                if (me->HealthBelowPct(25) && !flee)
                {
                    flee = true;
                    if (Creature* qon = IronQon())
                    {
                        qon->ExitVehicle();
                        qon->AI()->DoAction(ACTION_COUNT_DOGS_FLEE);
                        events.Reset();
                        me->AI()->DoAction(ACTION_LAST_PHASE_EJECTION);
                        if (Creature* ros = roshak())
                            ros->AI()->DoAction(ACTION_STOP_SPARK_OF_MOLTEN_FLARE);
                    }
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            // check dead zones
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
            {
                Player* player = i->GetSource();
                if (!player || !player->IsAlive())
                    continue;
                bool inDeadZone = false;

                float angle = me->GetAngle(player);
                angle -= me->GetOrientation();
                angle = Position::NormalizeOrientation(angle);
                if (angle > M_PI)
                    angle -= 2.0f * 3.14f;
                bool inLeft = angle > 0;
                bool inRight = angle < 0;

                if (me->HasAura(SPELL_DEAD_ZONE_FRONT) && me->isInFront(player, 3.14f / 2.0f))
                    inDeadZone = true;
                else if (me->HasAura(SPELL_DEAD_ZONE_BACK) && me->isInBack(player, 3.14f / 2.0f))
                    inDeadZone = true;
                else if (me->HasAura(SPELL_DEAD_ZONE_RIGHT) && inRight)
                    inDeadZone = true;
                else if (me->HasAura(SPELL_DEAD_ZONE_LEFT) && inLeft)
                    inDeadZone = true;

                if (!inDeadZone)
                    player->RemoveAura(SPELL_DEAD_ZONE_DEBUFF);
                else
                    me->AddAura(SPELL_DEAD_ZONE_DEBUFF, player);
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_PHASE_THREE_DAMREN:
                {
                    Unit* target = me->GetVictim();
                    if (!target)
                    {
                        events.ScheduleEvent(EVENT_PHASE_THREE_DAMREN, 1000);
                        break;
                    }
                    me->CastSpell(me, SPELL_DEAD_ZONE); //  if (player->HasInArc(M_PI, areatrigger)) => se uita spre areatrigger
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->StopMoving();
                    if (Creature* trigger = me->SummonCreature(60942, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 6000))
                    {
                        me->SetFacingToObject(trigger);
                        me->AddThreat(trigger, 9.9999999f);
                    }
                    events.ScheduleEvent(EVENT_PHASE_THREE_DAMREN, 12 * IN_MILLISECONDS);
                    events.ScheduleEvent(EVENT_RETURN_TO_COMBAT, 6000);
                    break;
                }
                case EVENT_EJECT_QON:
                    if (Vehicle* meVeh = me->GetVehicleKit())
                        meVeh->RemoveAllPassengers();
                    events.ScheduleEvent(EVENT_EJECT_QON, 1000);
                    break;
                case EVENT_DEAD_ZONE:
                {
                    Unit* target = me->GetVictim();
                    if (!target)
                    {
                        events.ScheduleEvent(EVENT_DEAD_ZONE, 1000);
                        break;
                    }
                    me->CastSpell(me, SPELL_DEAD_ZONE); //  if (player->HasInArc(M_PI, areatrigger)) => se uita spre areatrigger
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->StopMoving();
                    if (Creature* trigger = me->SummonCreature(60942, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 6000))
                    {
                        me->SetFacingToObject(trigger);
                        me->AddThreat(trigger, 9.9999999f);
                    }
                    events.ScheduleEvent(EVENT_RETURN_TO_COMBAT, 6000);
                    events.ScheduleEvent(EVENT_FREEZE, TIMER_FREEZE);
                    break;
                }
                case EVENT_RETURN_TO_COMBAT:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_FREEZE:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        me->AddAura(SPELL_FREEZE, (*itr));
                    events.ScheduleEvent(EVENT_DEAD_ZONE, TIMER_DEAD_ZONE);
                    break;
                }
                case EVENT_FROST_SPIKE:
                    switch (me->GetMap()->GetDifficultyID())
                    {
                    case DIFFICULTY_10_N:
                    case DIFFICULTY_10_HC:
                        CastSpikes();
                        break;
                    case DIFFICULTY_25_HC:
                    case DIFFICULTY_25_N:
                        CastSpikes25();
                        break;
                    }
                    events.ScheduleEvent(EVENT_FROST_SPIKE, 30000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void CastSpikes() // for 10 diffs
        {
            std::list<Unit*> targets;
            SelectTargetList(targets, 2, SELECT_TARGET_RANDOM, 1000.0f, true);
            targets.remove_if(notValidSpec()); // in this case, tank specc'ed players

            if (!targets.empty())
                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    DoCast(*itr, SPELL_FROST_SPIKE, true);
        }

        void CastSpikes25()
        {
            std::list<Unit*> targets;
            SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 10000.0f, true);
            targets.remove_if(notValidSpec()); //tanks

            if (!targets.empty())
                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    DoCast(*itr, SPELL_FROST_SPIKE, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_damrenAI(creature);
    }
};

class bfa_npc_iron_qon_spear : public CreatureScript
{
public:
    bfa_npc_iron_qon_spear() : CreatureScript("bfa_npc_iron_qon_spear") { }

    struct bfa_npc_iron_qon_spearAI : public ScriptedAI
    {
        bfa_npc_iron_qon_spearAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_CAST_BURNING_TRAIL:
            {
                events.ScheduleEvent(EVENT_DO_FIRE, 500);
                events.ScheduleEvent(EVENT_ADD_SAFE, 15000);
                me->SummonCreature(NPC_TRAILS_HANDLER_1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 1.0f, me->GetOrientation());
                me->SummonCreature(NPC_TRAILS_HANDLER_2, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 1.0f, me->GetOrientation());
                me->SummonCreature(NPC_TRAILS_HANDLER_3, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 1.0f, me->GetOrientation());
                me->SummonCreature(NPC_TRAILS_HANDLER_4, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 1.0f, me->GetOrientation());
                me->DespawnOrUnsummon(45000);
                break;
            }
            case ACTION_CAST_FROZEN_BLOOD:
            {
                events.ScheduleEvent(EVENT_DO_FROZEN, 500);
                events.ScheduleEvent(EVENT_ADD_SAFE, 15000);
                me->SummonCreature(NPC_TRAILS_HANDLER_1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 1.0f, me->GetOrientation());
                me->SummonCreature(NPC_TRAILS_HANDLER_2, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 1.0f, me->GetOrientation());
                me->SummonCreature(NPC_TRAILS_HANDLER_3, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 1.0f, me->GetOrientation());
                me->SummonCreature(NPC_TRAILS_HANDLER_4, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 1.0f, me->GetOrientation());
                me->DespawnOrUnsummon(10000);
                break;
            }
            case ACTION_CAST_STORM_CLOUD:
            {
                events.ScheduleEvent(EVENT_DO_STORM, 500);
                events.ScheduleEvent(EVENT_ADD_SAFE, 15000);
                me->SummonCreature(NPC_TRAILS_HANDLER_1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 1.0f, me->GetOrientation());
                me->SummonCreature(NPC_TRAILS_HANDLER_2, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 1.0f, me->GetOrientation());
                me->SummonCreature(NPC_TRAILS_HANDLER_3, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 1.0f, me->GetOrientation());
                me->SummonCreature(NPC_TRAILS_HANDLER_4, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 1.0f, me->GetOrientation());
                me->DespawnOrUnsummon(10000);
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
                case EVENT_ADD_SAFE:
                    me->AddAura(139054, me);
                    break;
                case EVENT_DO_FIRE:
                {
                    if (me->HasAura(139054))
                        return;
                    std::list<Creature*> triggers;
                    me->GetCreatureListWithEntryInGrid(triggers, NPC_TRAILS_HANDLER_1, 500.0f);
                    me->GetCreatureListWithEntryInGrid(triggers, NPC_TRAILS_HANDLER_2, 500.0f);
                    me->GetCreatureListWithEntryInGrid(triggers, NPC_TRAILS_HANDLER_3, 500.0f);
                    me->GetCreatureListWithEntryInGrid(triggers, NPC_TRAILS_HANDLER_4, 500.0f);
                    if (triggers.empty())
                        return;
                    for (auto it = triggers.begin(); it != triggers.end(); ++it)
                    {
                        Creature* creature = *it;
                        me->CastSpell(creature, SPELL_BURNING_CINDERS, true);
                    }
                    events.ScheduleEvent(EVENT_DO_FIRE, 400);
                    break;
                }
                case EVENT_DO_FROZEN:
                {
                    if (me->HasAura(139054))
                        return;
                    std::list<Creature*> triggers;
                    me->GetCreatureListWithEntryInGrid(triggers, NPC_TRAILS_HANDLER_1, 500.0f);
                    me->GetCreatureListWithEntryInGrid(triggers, NPC_TRAILS_HANDLER_2, 500.0f);
                    me->GetCreatureListWithEntryInGrid(triggers, NPC_TRAILS_HANDLER_3, 500.0f);
                    me->GetCreatureListWithEntryInGrid(triggers, NPC_TRAILS_HANDLER_4, 500.0f);
                    if (triggers.empty())
                        return;
                    for (auto it = triggers.begin(); it != triggers.end(); ++it)
                    {
                        Creature* creature = *it;
                        me->CastSpell(creature, SPELL_FROZEN_BLOOD_AT, true);
                    }
                    events.ScheduleEvent(EVENT_DO_FROZEN, 400);
                    break;
                }
                case EVENT_DO_STORM:
                {
                    if (me->HasAura(139054))
                        return;
                    std::list<Creature*> triggers;
                    me->GetCreatureListWithEntryInGrid(triggers, NPC_TRAILS_HANDLER_1, 500.0f);
                    me->GetCreatureListWithEntryInGrid(triggers, NPC_TRAILS_HANDLER_2, 500.0f);
                    me->GetCreatureListWithEntryInGrid(triggers, NPC_TRAILS_HANDLER_3, 500.0f);
                    me->GetCreatureListWithEntryInGrid(triggers, NPC_TRAILS_HANDLER_4, 500.0f);
                    if (triggers.empty())
                        return;
                    for (auto it = triggers.begin(); it != triggers.end(); ++it)
                    {
                        Creature* creature = *it;
                        me->CastSpell(creature, SPELL_STORM_CLOUD_VISUAL, true);
                    }
                    events.ScheduleEvent(EVENT_DO_STORM, 400);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_iron_qon_spearAI(creature);
    }
};

class bfa_npc_trail_handlers : public CreatureScript
{
public:
    bfa_npc_trail_handlers() : CreatureScript("bfa_npc_trail_handlers") { }

    struct bfa_npc_trail_handlersAI : public ScriptedAI
    {
        bfa_npc_trail_handlersAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);

            me->ApplySpellImmune(0, IMMUNITY_ID, 137664, true); // frozen blood
            me->ApplySpellImmune(0, IMMUNITY_ID, 137669, true); // storm cloud
            me->ApplySpellImmune(0, IMMUNITY_ID, 137668, true); // burning cinders
        }

        float orientation1 = 3.09f;
        float orientation2 = 1.63f;
        float orientation3 = 5.68f;
        float orientation4 = 4.20f;

        void IsSummonedBy(Unit* caster)
        {
            me->DespawnOrUnsummon(50000); // manual despawn because when our main summoner is despawning, it will despawn this too

            switch (me->GetEntry())
            {
            case NPC_TRAILS_HANDLER_1:
            {
                Position pos;
                me->GetNearPoint(NULL, pos.m_positionX, pos.m_positionY, pos.m_positionZ, DEFAULT_WORLD_OBJECT_SIZE, 180, orientation1);
                me->GetMotionMaster()->MovePoint(0, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
                break;
            }
            case NPC_TRAILS_HANDLER_2:
            {
                Position pos;
                me->GetNearPoint(NULL, pos.m_positionX, pos.m_positionY, pos.m_positionZ, DEFAULT_WORLD_OBJECT_SIZE, 180, orientation2);
                me->GetMotionMaster()->MovePoint(0, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
                break;
            }
            case NPC_TRAILS_HANDLER_3:
            {
                Position pos;
                me->GetNearPoint(NULL, pos.m_positionX, pos.m_positionY, pos.m_positionZ, DEFAULT_WORLD_OBJECT_SIZE, 180, orientation3);
                me->GetMotionMaster()->MovePoint(0, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
                break;
            }
            case NPC_TRAILS_HANDLER_4:
            {
                Position pos;
                me->GetNearPoint(NULL, pos.m_positionX, pos.m_positionY, pos.m_positionZ, DEFAULT_WORLD_OBJECT_SIZE, 180, orientation4);
                me->GetMotionMaster()->MovePoint(0, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
                break;
            }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_trail_handlersAI(creature);
    }
};

class bfa_npc_windstorm : public CreatureScript
{
public:
    bfa_npc_windstorm() : CreatureScript("bfa_npc_windstorm") { }

    struct bfa_npc_windstormAI : public ScriptedAI
    {
        bfa_npc_windstormAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
            me->SetFaction(7);
            me->SetDisplayId(1126);
        }

        EventMap events;

        void IsSummonedBy(Unit* owner)
        {
            me->AddAura(SPELL_RUSHING_WINDS_VISUAL, me);
            events.ScheduleEvent(EVENT_INIT_WINDSTORM, 2000);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->GetDistance(me) > 45.0f)
                        player->RemoveAura(136577);
                }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_INIT_WINDSTORM:
                {
                    DragAllPlayers();
                    me->SummonCreature(NPC_RUSHING_WINDS, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_RUSHING_WINDS_2, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_RUSHING_WINDS_3, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_RUSHING_WINDS_4, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 20000);
                    me->SummonCreature(NPC_RUSHING_WINDS_5, 6087.45f, 4709.58f, 142.83f, me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 20000);
                    me->SummonCreature(NPC_RUSHING_WINDS_5, 6073.92f, 4670.83f, 142.83f, me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 20000);
                    me->SummonCreature(NPC_RUSHING_WINDS_5, 6047.48f, 4650.22f, 142.83f, me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 20000);
                    me->SummonCreature(NPC_RUSHING_WINDS_5, 6014.72f, 4670.69f, 142.83f, me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 20000);
                    me->SummonCreature(NPC_RUSHING_WINDS_5, 6024.49f, 4714.56f, 142.83f, me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 20000);
                    me->SummonCreature(NPC_RUSHING_WINDS_5, 6070.49f, 4720.42f, 142.83f, me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 20000);
                    me->SummonCreature(NPC_RUSHING_WINDS_5, 6045.19f, 4722.81f, 142.83f, me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 20000);
                    break;
                }
                }
            }
        }

        void DragAllPlayers()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->AddAura(136577, player);
                    player->GetMotionMaster()->MoveCharge(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 30.0f, 35.0f);
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_windstormAI(creature);
    }
};

// 137221
class bfa_spell_molten_overload : public SpellScriptLoader
{
public:
    bfa_spell_molten_overload() : SpellScriptLoader("bfa_spell_molten_overload") { }

    class bfa_spell_molten_overload_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_molten_overload_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            if (!GetCaster())
                return;

            GetCaster()->SetPower(POWER_ENERGY, GetCaster()->GetPower(POWER_ENERGY) - 10);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_molten_overload_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_molten_overload_AuraScript();
    }
};


class bfa_spell_lightning_storm : public SpellScriptLoader
{
public:
    bfa_spell_lightning_storm() : SpellScriptLoader("bfa_spell_lightning_storm") { }

    class bfa_spell_lightning_storm_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_lightning_storm_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* target = GetTarget()->ToPlayer();
            if (!GetCaster() || !target)
                return;

            //target->CastSpell(target, 136226);

            Map::PlayerList const& playerList = target->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (target == player)
                        continue;

                    if (player->GetDistance(target) < 5.0f)
                    {
                        target->AddAura(SPELL_ARCING_LIGHTNING, player);
                    }
                }
        }

        void HandleApply(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            Unit* target = GetTarget()->ToPlayer();
            if (!target)
                return;

            if (Creature* cloud = target->SummonCreature(70660, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN))
                cloud->DespawnOrUnsummon(30 * IN_MILLISECONDS);
            //target->CastSpell(target, SPELL_ARCING_LIGHTNING_STUN, true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_lightning_storm_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            OnEffectApply += AuraEffectApplyFn(bfa_spell_lightning_storm_AuraScript::HandleApply, EFFECT_1, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_lightning_storm_AuraScript();
    }
};

class bfa_npc_lightning_cloud : public CreatureScript
{
public:
    bfa_npc_lightning_cloud() : CreatureScript("bfa_npc_lightning_cloud") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->HasAura(136192) || player->IsGameMaster())
            return false;

        creature->Kill(creature);
        return true;
    }

    struct bfa_npc_lightning_cloudAI : public ScriptedAI
    {
        bfa_npc_lightning_cloudAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void JustDied(Unit*)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(SPELL_ARCING_LIGHTNING_ZAP);
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_lightning_cloudAI(creature);
    }
};

// 134628
class bfa_spell_unleashed_flame : public SpellScriptLoader
{
public:
    bfa_spell_unleashed_flame() : SpellScriptLoader("bfa_spell_unleashed_flame") { }

    class bfa_spell_unleashed_flame_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_unleashed_flame_SpellScript);

        uint8 targetsPlayers;

        bool Load()
        {
            targetsPlayers = 1;
            return true;
        }

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            targetsPlayers = targets.size();
        }

        void RecalculateDamage(SpellEffIndex effIndex)
        {
            SetHitDamage(GetHitDamage() / targetsPlayers);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_unleashed_flame_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(bfa_spell_unleashed_flame_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_unleashed_flame_SpellScript();
    }
};

// 135144
class bfa_spell_frozen_resilience : public SpellScriptLoader
{
public:
    bfa_spell_frozen_resilience() : SpellScriptLoader("bfa_spell_frozen_resilience") { }

    class bfa_spell_frozen_resilience_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_frozen_resilience_AuraScript);

        void HandleOnProc(const AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            if (Unit* pCaster = eventInfo.GetActor())
            {
                if (!eventInfo.GetDamageInfo())
                    return;

                int32 uiDamages = eventInfo.GetDamageInfo()->GetDamage() * 0.10f; // 10% of damages returned to the player

                if (Unit* pVictim = eventInfo.GetActionTarget())
                {
                    pVictim->CastCustomSpell(pCaster, 135142, &uiDamages, NULL, NULL, true);
                }
            }
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(bfa_spell_frozen_resilience_AuraScript::HandleOnProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_frozen_resilience_AuraScript();
    }
};

// 135145
class bfa_spell_freeze : public SpellScriptLoader
{
public:
    bfa_spell_freeze() : SpellScriptLoader("bfa_spell_freeze") { }

    class bfa_spell_freeze_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_freeze_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* target = GetTarget()->ToPlayer();
            if (!GetCaster() || !target)
                return;
            if (aurEff->GetTickNumber() == 3)
                target->RemoveAura(135145);
        }

        void OnRemove(AuraEffect const*  /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget()->ToPlayer();
            if (!GetCaster() || !target)
                return;

            target->CastSpell(target, SPELL_SHATTER_AOE, true);
            target->CastSpell(target, SPELL_SHATTER_SELF, true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_freeze_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_freeze_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_freeze_AuraScript;
    }
};

// 137232
class bfa_spell_dead_zone : public SpellScriptLoader
{
public:
    bfa_spell_dead_zone() : SpellScriptLoader("bfa_spell_dead_zone") {}

    class bfa_spell_dead_zone_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_dead_zone_SpellScript);

        void HandleEffectHitTarget(SpellEffIndex /*eff_idx*/)
        {
            if (Creature* pCreature = GetHitCreature())
            {
                if (!pCreature)
                    return;

                std::list<uint32> zones;

                for (uint8 i = 0; i < 6; ++i)
                    zones.push_back(DeadZones[i]);


                uint32 randomZoneAura = Trinity::Containers::SelectRandomContainerElement(zones);
                CAST_AI(bfa_npc_damren::bfa_npc_damrenAI, pCreature->AI())->HandleDeadZone(randomZoneAura);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_dead_zone_SpellScript::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_dead_zone_SpellScript();
    }
};

// First Rushing Wind - 8 points
class bfa_npc_rushing_wind_1 : public CreatureScript
{
public:
    bfa_npc_rushing_wind_1() : CreatureScript("bfa_npc_rushing_wind_1") { }

    struct bfa_npc_rushing_wind_1AI : public ScriptedAI
    {
        bfa_npc_rushing_wind_1AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->AddAura(SPELL_RUSHING_WINDS, me);
            me->AddAura(SPELL_RUSHING_WINDS_TORNADO_VISUAL, me);
            me->SetReactState(REACT_PASSIVE);
            me->SetFaction(7);
            me->SetDisplayId(38497);
        }

        EventMap events;
        bool playerIn;

        void IsSummonedBy(Unit* summoner)
        {
            playerIn = false;
            if (Vehicle* meVehicle = me->GetVehicleKit())
            {
                meVehicle->RemoveAllPassengers();
            }
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            events.ScheduleEvent(EVENT_1, 1000);
            events.ScheduleEvent(EVENT_CHECK_NEARBY_PLAYERS_RUSHING, 3000);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_NEARBY_PLAYERS_RUSHING:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (player->GetDistance(me) < 4.0f && !player->HasAura(137654))
                            {
                                player->AddAura(137654, player);
                                player->EnterVehicle(me);
                                playerIn = true;
                                if (playerIn)
                                    events.ScheduleEvent(EVENT_REMOVE_PLAYERS, 2000);
                            }
                        }
                    events.ScheduleEvent(EVENT_CHECK_NEARBY_PLAYERS_RUSHING, 2000);
                    break;
                }
                case EVENT_REMOVE_PLAYERS:
                    if (Vehicle* vehicle = me->GetVehicleKit())
                        vehicle->RemoveAllPassengers();
                    playerIn = false;
                    break;
                case EVENT_1:
                    me->GetMotionMaster()->MovePoint(POINT_1, FirstRushingWind[0]);
                    break;
                case EVENT_2:
                    me->GetMotionMaster()->MovePoint(POINT_2, FirstRushingWind[1]);
                    break;
                case EVENT_3:
                    me->GetMotionMaster()->MovePoint(POINT_3, FirstRushingWind[2]);
                    break;
                case EVENT_4:
                    me->GetMotionMaster()->MovePoint(POINT_4, FirstRushingWind[3]);
                    break;
                case EVENT_5:
                    me->GetMotionMaster()->MovePoint(POINT_5, FirstRushingWind[4]);
                    break;
                case EVENT_6:
                    me->GetMotionMaster()->MovePoint(POINT_6, FirstRushingWind[5]);
                    break;
                case EVENT_7:
                    me->GetMotionMaster()->MovePoint(POINT_7, FirstRushingWind[6]);
                    break;
                case EVENT_8:
                    me->GetMotionMaster()->MovePoint(POINT_8, FirstRushingWind[7]);
                    break;
                }
            }
        }

        void MovementInform(uint32 type, uint32 pointId)
        {
            switch (pointId)
            {
            case POINT_1:
                events.ScheduleEvent(EVENT_2, 500);
                break;
            case POINT_2:
                events.ScheduleEvent(EVENT_3, 500);
                break;
            case POINT_3:
                events.ScheduleEvent(EVENT_4, 500);
                break;
            case POINT_4:
                events.ScheduleEvent(EVENT_5, 500);
                break;
            case POINT_5:
                events.ScheduleEvent(EVENT_6, 500);
                break;
            case POINT_6:
                events.ScheduleEvent(EVENT_7, 500);
                break;
            case POINT_7:
                events.ScheduleEvent(EVENT_8, 500);
                break;
            case POINT_8:
                events.ScheduleEvent(EVENT_1, 500);
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_rushing_wind_1AI(creature);
    }
};

// Second Rushing Wind - 7 points
class bfa_npc_rushing_wind_2 : public CreatureScript
{
public:
    bfa_npc_rushing_wind_2() : CreatureScript("bfa_npc_rushing_wind_2") { }

    struct bfa_npc_rushing_wind_2AI : public ScriptedAI
    {
        bfa_npc_rushing_wind_2AI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_RUSHING_WINDS, me);
            me->AddAura(SPELL_RUSHING_WINDS_TORNADO_VISUAL, me);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_PASSIVE);
            me->SetFaction(7);
            me->SetDisplayId(38497);
        }

        EventMap events;
        bool playerIn;

        void IsSummonedBy(Unit* summoner)
        {
            playerIn = false;
            if (Vehicle* meVehicle = me->GetVehicleKit())
            {
                meVehicle->RemoveAllPassengers();
            }
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            events.ScheduleEvent(EVENT_1, 1000);
            events.ScheduleEvent(EVENT_CHECK_NEARBY_PLAYERS_RUSHING, 3000);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_NEARBY_PLAYERS_RUSHING:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (player->GetDistance(me) < 4.0f && !player->HasAura(137654))
                            {
                                player->AddAura(137654, player);
                                player->EnterVehicle(me);
                                playerIn = true;
                                if (playerIn)
                                    events.ScheduleEvent(EVENT_REMOVE_PLAYERS, 2000);
                            }
                        }
                    events.ScheduleEvent(EVENT_CHECK_NEARBY_PLAYERS_RUSHING, 2000);
                    break;
                }
                case EVENT_REMOVE_PLAYERS:
                    if (Vehicle* vehicle = me->GetVehicleKit())
                        vehicle->RemoveAllPassengers();
                    playerIn = false;
                    break;
                case EVENT_1:
                    me->GetMotionMaster()->MovePoint(POINT_1, SecondRushingWind[0]);
                    break;
                case EVENT_2:
                    me->GetMotionMaster()->MovePoint(POINT_2, SecondRushingWind[1]);
                    break;
                case EVENT_3:
                    me->GetMotionMaster()->MovePoint(POINT_3, SecondRushingWind[2]);
                    break;
                case EVENT_4:
                    me->GetMotionMaster()->MovePoint(POINT_4, SecondRushingWind[3]);
                    break;
                case EVENT_5:
                    me->GetMotionMaster()->MovePoint(POINT_5, SecondRushingWind[4]);
                    break;
                case EVENT_6:
                    me->GetMotionMaster()->MovePoint(POINT_6, SecondRushingWind[5]);
                    break;
                case EVENT_7:
                    me->GetMotionMaster()->MovePoint(POINT_7, SecondRushingWind[6]);
                    break;
                }
            }
        }

        void MovementInform(uint32 type, uint32 pointId)
        {
            switch (pointId)
            {
            case POINT_1:
                events.ScheduleEvent(EVENT_2, 500);
                break;
            case POINT_2:
                events.ScheduleEvent(EVENT_3, 500);
                break;
            case POINT_3:
                events.ScheduleEvent(EVENT_4, 500);
                break;
            case POINT_4:
                events.ScheduleEvent(EVENT_5, 500);
                break;
            case POINT_5:
                events.ScheduleEvent(EVENT_6, 500);
                break;
            case POINT_6:
                events.ScheduleEvent(EVENT_7, 500);
                break;
            case POINT_7:
                events.ScheduleEvent(EVENT_1, 500);
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_rushing_wind_2AI(creature);
    }
};

// Third Rushing Wind - 7 points
class bfa_npc_rushing_wind_3 : public CreatureScript
{
public:
    bfa_npc_rushing_wind_3() : CreatureScript("bfa_npc_rushing_wind_3") { }

    struct bfa_npc_rushing_wind_3AI : public ScriptedAI
    {
        bfa_npc_rushing_wind_3AI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_RUSHING_WINDS, me);
            me->AddAura(SPELL_RUSHING_WINDS_TORNADO_VISUAL, me);
            me->SetReactState(REACT_PASSIVE);
            me->SetFaction(7);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetDisplayId(38497);
        }

        EventMap events;
        bool playerIn;

        void IsSummonedBy(Unit* summoner)
        {
            playerIn = false;
            if (Vehicle* meVehicle = me->GetVehicleKit())
            {
                meVehicle->RemoveAllPassengers();
            }
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            events.ScheduleEvent(EVENT_1, 1000);
            events.ScheduleEvent(EVENT_CHECK_NEARBY_PLAYERS_RUSHING, 3000);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_START_FREEZING:
                events.CancelEvent(EVENT_CHECK_NEARBY_PLAYERS_RUSHING);
                events.ScheduleEvent(EVENT_FREEZE_NEARBY_PLAYERS, 2000);
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
                case EVENT_FREEZE_NEARBY_PLAYERS:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (player->GetDistance(me) < 4.0f && !player->HasAura(SPELL_FROZEN_SOLID))
                            {
                                player->AddAura(SPELL_FROZEN_SOLID, player);
                                me->CastSpell(player, SPELL_FROZEN_SOLID_ICE_TOMB, true);
                            }
                        }
                    events.ScheduleEvent(EVENT_FREEZE_NEARBY_PLAYERS, 2000);
                    break;
                }
                case EVENT_CHECK_NEARBY_PLAYERS_RUSHING:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (player->GetDistance(me) < 4.0f && !player->HasAura(137654))
                            {
                                player->AddAura(137654, player);
                                player->EnterVehicle(me);
                                playerIn = true;
                                if (playerIn)
                                    events.ScheduleEvent(EVENT_REMOVE_PLAYERS, 2000);
                            }
                        }
                    events.ScheduleEvent(EVENT_CHECK_NEARBY_PLAYERS_RUSHING, 2000);
                    break;
                }
                case EVENT_REMOVE_PLAYERS:
                    if (Vehicle* vehicle = me->GetVehicleKit())
                        vehicle->RemoveAllPassengers();
                    playerIn = false;
                    break;
                case EVENT_1:
                    me->GetMotionMaster()->MovePoint(POINT_1, ThirdRushingWind[0]);
                    break;
                case EVENT_2:
                    me->GetMotionMaster()->MovePoint(POINT_2, ThirdRushingWind[1]);
                    break;
                case EVENT_3:
                    me->GetMotionMaster()->MovePoint(POINT_3, ThirdRushingWind[2]);
                    break;
                case EVENT_4:
                    me->GetMotionMaster()->MovePoint(POINT_4, ThirdRushingWind[3]);
                    break;
                case EVENT_5:
                    me->GetMotionMaster()->MovePoint(POINT_5, ThirdRushingWind[4]);
                    break;
                case EVENT_6:
                    me->GetMotionMaster()->MovePoint(POINT_6, ThirdRushingWind[5]);
                    break;
                case EVENT_7:
                    me->GetMotionMaster()->MovePoint(POINT_7, ThirdRushingWind[6]);
                    break;
                }
            }
        }

        void MovementInform(uint32 type, uint32 pointId)
        {
            switch (pointId)
            {
            case POINT_1:
                events.ScheduleEvent(EVENT_2, 500);
                break;
            case POINT_2:
                events.ScheduleEvent(EVENT_3, 500);
                break;
            case POINT_3:
                events.ScheduleEvent(EVENT_4, 500);
                break;
            case POINT_4:
                events.ScheduleEvent(EVENT_5, 500);
                break;
            case POINT_5:
                events.ScheduleEvent(EVENT_6, 500);
                break;
            case POINT_6:
                events.ScheduleEvent(EVENT_7, 500);
                break;
            case POINT_7:
                events.ScheduleEvent(EVENT_1, 500);
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_rushing_wind_3AI(creature);
    }
};

// Forth Rushing Wind - 6 points
class bfa_npc_rushing_wind_4 : public CreatureScript
{
public:
    bfa_npc_rushing_wind_4() : CreatureScript("bfa_npc_rushing_wind_4") { }

    struct bfa_npc_rushing_wind_4AI : public ScriptedAI
    {
        bfa_npc_rushing_wind_4AI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_RUSHING_WINDS, me);
            me->AddAura(SPELL_RUSHING_WINDS_TORNADO_VISUAL, me);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_PASSIVE);
            me->SetFaction(7);
            me->SetDisplayId(38497);
        }

        EventMap events;
        bool playerIn;

        void IsSummonedBy(Unit* summoner)
        {
            playerIn = false;
            if (Vehicle* meVehicle = me->GetVehicleKit())
            {
                meVehicle->RemoveAllPassengers();
            }
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            events.ScheduleEvent(EVENT_CHECK_NEARBY_PLAYERS_RUSHING, 3000);
            events.ScheduleEvent(EVENT_1, 1000);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_NEARBY_PLAYERS_RUSHING:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (player->GetDistance(me) < 4.0f && !player->HasAura(137654))
                            {
                                player->AddAura(137654, player);
                                player->EnterVehicle(me);
                                playerIn = true;
                                if (playerIn)
                                    events.ScheduleEvent(EVENT_REMOVE_PLAYERS, 2000);
                            }
                        }
                    events.ScheduleEvent(EVENT_CHECK_NEARBY_PLAYERS_RUSHING, 2000);
                    break;
                }
                case EVENT_REMOVE_PLAYERS:
                    if (Vehicle* vehicle = me->GetVehicleKit())
                        vehicle->RemoveAllPassengers();
                    playerIn = false;
                    break;
                case EVENT_1:
                    me->GetMotionMaster()->MovePoint(POINT_1, FourthRushingWind[0]);
                    break;
                case EVENT_2:
                    me->GetMotionMaster()->MovePoint(POINT_2, FourthRushingWind[1]);
                    break;
                case EVENT_3:
                    me->GetMotionMaster()->MovePoint(POINT_3, FourthRushingWind[2]);
                    break;
                case EVENT_4:
                    me->GetMotionMaster()->MovePoint(POINT_4, FourthRushingWind[3]);
                    break;
                case EVENT_5:
                    me->GetMotionMaster()->MovePoint(POINT_5, FourthRushingWind[4]);
                    break;
                case EVENT_6:
                    me->GetMotionMaster()->MovePoint(POINT_1, FourthRushingWind[5]);
                    break;
                }
            }
        }

        void MovementInform(uint32 type, uint32 pointId)
        {
            switch (pointId)
            {
            case POINT_1:
                events.ScheduleEvent(EVENT_2, 500);
                break;
            case POINT_2:
                events.ScheduleEvent(EVENT_3, 500);
                break;
            case POINT_3:
                events.ScheduleEvent(EVENT_4, 500);
                break;
            case POINT_4:
                events.ScheduleEvent(EVENT_5, 500);
                break;
            case POINT_5:
                events.ScheduleEvent(EVENT_6, 500);
                break;
            case POINT_6:
                events.ScheduleEvent(EVENT_1, 500);
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_rushing_wind_4AI(creature);
    }
};

// 5th rushing wind, random movement
class bfa_npc_rushing_wind_5 : public CreatureScript
{
public:
    bfa_npc_rushing_wind_5() : CreatureScript("bfa_npc_rushing_wind_5") { }

    struct bfa_npc_rushing_wind_5AI : public ScriptedAI
    {
        bfa_npc_rushing_wind_5AI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_RUSHING_WINDS, me);
            me->AddAura(SPELL_RUSHING_WINDS_TORNADO_VISUAL, me);
            me->SetReactState(REACT_PASSIVE);
            me->SetFaction(7);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetDisplayId(38497);
        }

        EventMap events;
        bool playerIn;

        void IsSummonedBy(Unit* summoner)
        {
            playerIn = false;
            if (Vehicle* meVehicle = me->GetVehicleKit())
            {
                meVehicle->RemoveAllPassengers();
            }
            events.ScheduleEvent(EVENT_1, 500);
            events.ScheduleEvent(EVENT_CHECK_NEARBY_PLAYERS_RUSHING, 3000);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_NEARBY_PLAYERS_RUSHING:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (player->GetDistance(me) < 4.0f && !player->HasAura(137654))
                            {
                                player->AddAura(137654, player);
                                player->EnterVehicle(me);
                                playerIn = true;
                                if (playerIn)
                                    events.ScheduleEvent(EVENT_REMOVE_PLAYERS, 2000);
                            }
                        }
                    events.ScheduleEvent(EVENT_CHECK_NEARBY_PLAYERS_RUSHING, 2000);
                    break;
                }
                case EVENT_REMOVE_PLAYERS:
                    if (Vehicle* vehicle = me->GetVehicleKit())
                        vehicle->RemoveAllPassengers();
                    playerIn = false;
                    break;
                case EVENT_1:
                    me->GetMotionMaster()->MoveRandom(20.0f);
                    events.ScheduleEvent(EVENT_1, 1000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_rushing_wind_5AI(creature);
    }
};

// 137669
class bfa_spell_storm_cloud : public SpellScriptLoader
{
public:
    bfa_spell_storm_cloud() : SpellScriptLoader("bfa_spell_storm_cloud") { }

    class bfa_spell_storm_cloud_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_storm_cloud_AuraScript);

            void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();

            if (!caster || !target)
                return;

            // Check aura stacks for stun apply.
            if (Aura* electric = target->GetAura(SPELL_ELECTRIC_CHARGES))
            {
                int32 stacks = electric->GetStackAmount();

                // Stack handling.
                if (stacks >= 3 && !target->HasAura(SPELL_ELECTRIFIED))
                {
                    target->RemoveAurasDueToSpell(SPELL_ELECTRIC_CHARGES);
                    caster->AddAura(SPELL_ELECTRIFIED, target);
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_storm_cloud_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_storm_cloud_AuraScript();
    }
};

// 136193
class bfa_spell_arcing_lightning : public SpellScriptLoader
{
public:
    bfa_spell_arcing_lightning() : SpellScriptLoader("bfa_spell_arcing_lightning") { }

    class bfa_spell_arcing_lightning_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_arcing_lightning_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();

            if (!caster || !target)
                return;

            Map::PlayerList const& playerList = caster->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->GetDistance(target) < 3.0f)
                    {
                        if (player == target)
                            continue;
                        if (!player->HasAura(SPELL_ARCING_LIGHTNING))
                            target->AddAura(SPELL_ARCING_LIGHTNING, player);
                    }
                }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_arcing_lightning_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_arcing_lightning_AuraScript();
    }
};


class bfa_npc_whirling_winds : public CreatureScript
{
public:
    bfa_npc_whirling_winds() : CreatureScript("bfa_npc_whirling_winds") { }

    struct bfa_npc_whirling_windsAI : public ScriptedAI
    {
        bfa_npc_whirling_windsAI(Creature* creature) : ScriptedAI(creature)
        {
            me->CastSpell(me, SPELL_WHIRLING_WINDS_AT, true);
            me->SetReactState(REACT_PASSIVE);
            me->SetFaction(7);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->ApplySpellImmune(0, IMMUNITY_ID, 137664, true); // frozen blood
            me->ApplySpellImmune(0, IMMUNITY_ID, 137669, true); // storm cloud
            me->ApplySpellImmune(0, IMMUNITY_ID, 137668, true); // burning cinders
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* summoner)
        {
            events.ScheduleEvent(EVENT_WHIRLING, 1000);
            events.ScheduleEvent(EVENT_WHIRL_AT, 500);
        }

        void MovementInform(uint32 type, uint32 pointId)
        {
            switch (pointId)
            {
            case 500:
                me->DespawnOrUnsummon(1000);
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
                case EVENT_WHIRL_AT:
                    me->CastSpell(me, SPELL_WHIRLING_WINDS_AT, true);
                    events.ScheduleEvent(EVENT_WHIRL_AT, 500);
                    break;
                case EVENT_WHIRLING:
                    //me->CastSpell(me, SPELL_WHIRLING_WINDS_AT, true);

                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (player->GetDistance(me) < 10.0f)
                            {
                                player->CastSpell(player, SPELL_WHIRLING_WINDS);
                            }
                        }
                    events.ScheduleEvent(EVENT_WHIRLING, 1000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_whirling_windsAI(creature);
    }
};

class bfa_npc_freeze_cyclone_ice_tomb : public CreatureScript
{
public:
    bfa_npc_freeze_cyclone_ice_tomb() : CreatureScript("bfa_npc_freeze_cyclone_ice_tomb") { }

    struct bfa_npc_freeze_cyclone_ice_tombAI : public ScriptedAI
    {
        bfa_npc_freeze_cyclone_ice_tombAI(Creature* creature) : ScriptedAI(creature)
        {
            me->RemoveAura(42716);
            me->SetDisplayId(30890);
        }

        void JustDied(Unit*)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->GetDistance(me) <= 5.0f)
                    {
                        player->RemoveAura(SPELL_FROZEN_SOLID);
                    }
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_freeze_cyclone_ice_tombAI(creature);
    }
};

void AddSC_bfa_boss_iron_qon()
{
    new bfa_boss_iron_qon;
    new bfa_npc_damren;
    new bfa_npc_quetzal;
    new bfa_npc_roshak;
    new bfa_npc_iron_qon_spear;
    new bfa_npc_windstorm;
    new bfa_npc_lightning_cloud;
    new bfa_npc_rushing_wind_1;
    new bfa_npc_rushing_wind_2;
    new bfa_npc_rushing_wind_3;
    new bfa_npc_rushing_wind_4;
    new bfa_npc_rushing_wind_5;
    new bfa_npc_trail_handlers;
    new bfa_npc_whirling_winds;
    new bfa_npc_freeze_cyclone_ice_tomb;

    new bfa_spell_molten_overload;
    new bfa_spell_lightning_storm;
    new bfa_spell_unleashed_flame;
    new bfa_spell_frozen_resilience;
    new bfa_spell_freeze;
    new bfa_spell_dead_zone;
    new bfa_spell_storm_cloud;
    new bfa_spell_arcing_lightning;
}
