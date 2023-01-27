#include "PhasingHandler.h"
#include "PlayerAI.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "ScriptMgr.h"
#include "shrine_of_the_storm.h"
#include "InstanceScript.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

enum Volzith
{
    SPELL_CHANNEL                               = 274175,
    SPELL_VOID_ENERGY_DISABLE_REGEN             = 267255,
    SPELL_VOID_ENERGY_DO_REGEN                  = 267260,

    SPELL_YAWNING_GATE                          = 269399,
    SPELL_YAWNING_GATE_AURA = 269419,

    SPELL_TENTACLE_SLAM                         = 267364,
    SPELL_TENTACLE_SLAM_SUMMON = 267382,
    SPELL_TENTACLE_SLAM_DMG                     = 267385,

    SPELL_WHISPERS_OF_POWER                     = 267034,
    SPELL_WHISPERS_OF_POWER_AURA                = 267037,
    SPELL_OLD_TONGUE                            = 274551,

    SPELL_GRASP_OF_THE_SUNKEN_CITY              = 267360, // target entry 140038
    SPELL_GRASP_OF_THE_SUNKEN_CITY_CHANNEL      = 267444,
    SPELL_GRASP_OF_THE_SUNKEN_CITY_DPS_PHASE    = 278209, // 267425 phaseid 10745 need to implement SPELL_AURA_164 - start drowning
    SPELL_GRASP_OF_THE_SUNKEN_CITY_TANK_PHASE   = 274556, // 267442 phaseid 10747

    SPELL_CALL_THE_ABYSS                        = 267299,
    SPELL_CALL_THE_ABYSS_SUMMON = 267306,

    SPELL_THE_SUNKEN_CITY                       = 267524,
    SPELL_CONSUME_ESSENCE                       = 267809,

    SPELL_LEVIATHANS_WAKE                       = 267548,

    SPELL_ABYSSAL_ERUPTION_DMG                  = 267310,
    SPELL_ABYSSAL_ERUPTION_ENERGIZE             = 267311,
};

static Position const spawnPoints[3] =
{
    { 3658.58f, -1715.67f, 85.89f },
    { 3603.31f, -1742.71f, 85.82f },
    { 3619.73f, -1709.18f, 86.14f },
};

static Position const manifestSpawnPoints[15] =
{
    { 3675.83f, -1688.60f, 83.4349f },
    { 3656.23f, -1675.91f, 83.8259f },
    { 3636.15f, -1673.52f, 83.3167f },
    { 3621.70f, -1673.33f, 84.4263f },
    { 3611.91f, -1678.02f, 83.5110f },
    { 3593.11f, -1687.05f, 84.3794f },
    { 3575.16f, -1698.99f, 83.5286f },
    { 3570.94f, -1714.89f, 83.6414f },
    { 3570.48f, -1730.42f, 83.3317f },
    { 3576.01f, -1751.30f, 83.4642f },
    { 3581.68f, -1761.81f, 83.5611f },
    { 3594.58f, -1772.18f, 83.6898f },
    { 3610.53f, -1783.90f, 83.6852f },
    { 3624.24f, -1788.61f, 82.8457f },
    { 3635.22f, -1786.49f, 84.6600f },
};

enum Creatures
{
    BOSS_VOLZITH_THE_WHISPERER = 134069,

    NPC_FORGOTTEN_DENIZEN = 136297,
    NPC_SUNKEN_DENIZEN = 136100,
    NPC_TENTACLE = 135987,
    NPC_MANIFESTATION_OF_THE_DEEP = 135903,
};

enum Events
{
    EVENT_YAWNING_GATE = 1,
    EVENT_TENTACLE_SUMMON,
    EVENT_WHISPER_OF_POWER,

    EVENT_ADD_POWER,
    EVENT_GRASP_OF_THE_SUNKEN_CITY,

    EVENT_CONSUME_ESSENCE,

    EVENT_CALL_THE_ABYSS,

    EVENT_TENTACLE_SLAM,
};

enum Timers
{
    TIMER_YAWNING_GATE = 15 * IN_MILLISECONDS,
    TIMER_TENTACLE_SUMMON = 12 * IN_MILLISECONDS,
    TIMER_WHISPERS_OF_POWER = 30 * IN_MILLISECONDS,
    TIMER_CALL_THE_ABYSS = 45 * IN_MILLISECONDS,

    TIMER_CONSUME_ESSENCE = 11 * IN_MILLISECONDS,

    TIMER_ADD_POWER = 3 * IN_MILLISECONDS,

    TIMER_TENTACLE_SLAM = 8 * IN_MILLISECONDS
};

const Position centerPos = { 3631.75f, -1728.81f, 105.55f  }; //cheaters 80y

enum Actions
{
    ACTION_COUNT_DPS_PHASE = 1,
    ACTION_COUNT_TANK_HEAL_PHASE = 2,
};

enum SoundIds
{
    SOUND_1 = 103098,
    SOUND_2 = 103110,

    SOUND_5 = 103104,
};

#define INTRO_TEXT_VOID "Ugalazul bwrxil' qu rax"
#define INTRO_TEXT "Darkness roots. Pestilence spreads. The doorway is open"

#define AGGRO_TEXT_VOID "Aglathrax hig' thrixa."
#define AGGRO_TEXT "I reside within your lungs!"

#define GRASP_TEXT_VOID "Skitsh qi'uthik illith!"
#define GRASP_TEXT "Beneath the tides, your truth awaits."

#define ABYSS_TEXT_VOID "Kril lax qutholil!"
#define ABYSS_TEXT "The crawling ones have awakened!"

#define KILL_TEXT_VOID "Krax il' oni OGOG!"
#define KILL_TEXT "Listen to the music of the drowned."

#define DEATH_TEXT_VOID "Bwixki amala zal qullllll...."
#define DEATH_TEXT "I will await you... in the dark..."

class bfa_boss_volzith_the_whisperer : public CreatureScript
{
public:
    bfa_boss_volzith_the_whisperer() : CreatureScript("bfa_boss_volzith_the_whisperer")
    {}

    struct bfa_boss_volzith_the_whisperer_AI : public BossAI
    {
        bfa_boss_volzith_the_whisperer_AI(Creature* creature) : BossAI(creature, DATA_VOLZITH), summons(me)
        {
            instance = me->GetInstanceScript();
            me->RemoveUnitFlag2(UNIT_FLAG2_REGENERATE_POWER);
            me->setRegeneratingHealth(false);
        }

        EventMap events;
        InstanceScript* instance;
        SummonList summons;
        uint8 dpsAdd;
        uint8 tankhealAdd;
        uint8 endPhaseCheck;
        bool introText;

        void Reset()
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 60);
            me->RemoveAllAreaTriggers();

            introText = false;
            DespawnCreature(NPC_SUNKEN_DENIZEN);
            DespawnCreature(NPC_TENTACLE);
            DespawnCreature(NPC_FORGOTTEN_DENIZEN);
            DespawnCreature(NPC_MANIFESTATION_OF_THE_DEEP);

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
                    me->PlayDirectSound(SOUND_1);
                    me->Whisper(INTRO_TEXT, LANG_UNIVERSAL, NULL);
                    me->Yell(INTRO_TEXT_VOID, LANG_UNIVERSAL, NULL);
                    break;
                case 2:
                    me->PlayDirectSound(SOUND_2);
                    me->Whisper(AGGRO_TEXT, LANG_UNIVERSAL, NULL);
                    me->Yell(AGGRO_TEXT_VOID, LANG_UNIVERSAL, NULL);
                    break;
                case 3:
                    me->Whisper(ABYSS_TEXT, LANG_UNIVERSAL, NULL);
                    me->Yell(ABYSS_TEXT_VOID, LANG_UNIVERSAL, NULL);
                    break;
                case 4:
                    me->Whisper(DEATH_TEXT, LANG_UNIVERSAL, NULL);
                    me->Yell(DEATH_TEXT_VOID, LANG_UNIVERSAL, NULL);
                    break;
                case 5:
                    me->PlayDirectSound(SOUND_5);
                    me->Whisper(KILL_TEXT_VOID, LANG_UNIVERSAL, NULL);
                    me->Yell(KILL_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 6:
                    me->Whisper(GRASP_TEXT, LANG_UNIVERSAL, NULL);
                    me->Yell(GRASP_TEXT_VOID, LANG_UNIVERSAL, NULL);
                    break;
                }
            }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!introText)
            {
                Map::PlayerList const& lPlayers = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                    if (Player* pPlayer = itr->GetSource())
                        if (pPlayer->IsAlive() && pPlayer->IsWithinDist(me, 50.f))
                        {
                            SelectSoundAndText(me, 1);
                            introText = true;
                            return;
                        }
            }
        }

        void KilledUnit(Unit* at)
        {
            SelectSoundAndText(me, 5);
        }

        void EnterEvadeMode(EvadeReason why)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            DespawnCreature(NPC_SUNKEN_DENIZEN);
            DespawnCreature(NPC_TENTACLE);
            DespawnCreature(NPC_FORGOTTEN_DENIZEN);
            DespawnCreature(NPC_MANIFESTATION_OF_THE_DEEP);
            me->RemoveAllAreaTriggers();

            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 60);
            me->CastStop();

            _DespawnAtEvade(15);
        }

        void DespawnCreature(uint32 entry)
        {
            std::list<Creature*> creatureList;
            GetCreatureListWithEntryInGrid(creatureList, me, entry, 500.0f);
            if (!creatureList.empty())
                for (auto NowCreature : creatureList)
                    NowCreature->DespawnOrUnsummon();
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case NPC_TENTACLE:
            case NPC_SUNKEN_DENIZEN:
            case NPC_FORGOTTEN_DENIZEN:
                summon->SetInCombatWithZone();
                break;
            }
        }

        void HandleSunkenPhase()
        {
            std::list<Unit*> dpsList;
            std::list<Unit*> TanksHealersList;

            //clearing
            dpsList.clear();
            TanksHealersList.clear();


            bool dps = false; // spliting with this, true = only dmg, false = tanks and healer

            //gather info about available players
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        uint32 specialization = player->GetSpecializationId();

                        if (player->getClass() == CLASS_PRIEST && specialization == TALENT_SPEC_PRIEST_DISCIPLINE ||
                            player->getClass() == CLASS_PRIEST && specialization == TALENT_SPEC_PRIEST_HOLY ||
                            player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_RESTORATION ||
                            player->getClass() == CLASS_MONK && specialization == TALENT_SPEC_MONK_MISTWEAVER ||
                            player->getClass() == CLASS_SHAMAN && specialization == TALENT_SPEC_SHAMAN_RESTORATION ||
                            player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_PROTECTION ||
                            player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_BLOOD || 
                            player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_PROTECTION ||
                            player->getClass() == CLASS_MONK && specialization == TALENT_SPEC_MONK_BREWMASTER ||
                            player->getClass() == CLASS_DEMON_HUNTER && specialization == TALENT_SPEC_DEMON_HUNTER_VENGEANCE ||
                            player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_BEAR)
                        {
                            dps = false;
                        }

                        if (!dps)
                            TanksHealersList.push_back(player);
                        else
                            dpsList.push_back(player);
                    }

                }

            if (!TanksHealersList.empty())
            {
                for (auto target : TanksHealersList)
                {
                    if (Aura* special = target->AddAura(SPELL_GRASP_OF_THE_SUNKEN_CITY_TANK_PHASE, target))
                    {
                        special->SetMaxDuration(10 * MINUTE);
                        special->SetDuration(10 * MINUTE);
                    }
                }
            }

            if (!dpsList.empty())
            {
                for (auto target : dpsList)
                {
                    if (Aura* special = target->AddAura(SPELL_GRASP_OF_THE_SUNKEN_CITY_DPS_PHASE, target))
                    {
                        special->SetMaxDuration(10 * MINUTE);
                        special->SetDuration(10 * MINUTE);
                    }
                }
            }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_COUNT_DPS_PHASE:
                ++dpsAdd;
                ++endPhaseCheck;
                if (endPhaseCheck >= 3)
                    EndSunkenPhase();
                break;
            case ACTION_COUNT_TANK_HEAL_PHASE:
                ++tankhealAdd;
                ++endPhaseCheck;
                if (endPhaseCheck >= 3)
                    EndSunkenPhase();
                break;
            }
        }

        void EndSunkenPhase()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        player->RemoveAura(SPELL_GRASP_OF_THE_SUNKEN_CITY_DPS_PHASE);
                        player->RemoveAura(SPELL_GRASP_OF_THE_SUNKEN_CITY_TANK_PHASE);
                        me->CastStop();
                    }
                }
        }

        void checkSunkenPhase()
        {
            if (me->HasAura(SPELL_GRASP_OF_THE_SUNKEN_CITY_CHANNEL))
            {
                bool checkAlive;

                Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* player = i->GetSource())
                    {
                        if (!player->IsGameMaster() && player->IsAlive() &&
                            player->HasAura(SPELL_GRASP_OF_THE_SUNKEN_CITY_DPS_PHASE) || player->HasAura(SPELL_GRASP_OF_THE_SUNKEN_CITY_TANK_PHASE))
                            checkAlive = true;
                        else
                            checkAlive = false;
                    }

                if (!checkAlive)
                    EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
            }
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (me->HasAura(SPELL_GRASP_OF_THE_SUNKEN_CITY_CHANNEL))
            {
                damage = 0;
                me->SetHealth(me->GetHealth() + 1);
                me->SetHealth(me->GetHealth() - 1);
            }
        }

        bool CheckCheaters()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (me->GetDistance(centerPos.GetPositionX(), centerPos.GetPositionY(), centerPos.GetPositionZ()) >= 80.0f)
                        {
                            me->Kill(player, false);
                            std::ostringstream str;
                            str << "CHEATERS!";
                            me->TextEmote(str.str().c_str(), 0, true);
                            return false;
                        }
                    }

                }

            return true;
        }

        void JustDied(Unit*)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            DespawnCreature(NPC_SUNKEN_DENIZEN);
            DespawnCreature(NPC_TENTACLE);
            DespawnCreature(NPC_FORGOTTEN_DENIZEN);
            DespawnCreature(NPC_MANIFESTATION_OF_THE_DEEP);
            me->RemoveAllAreaTriggers();
            SelectSoundAndText(me, 4);
        }

        void EnterCombat(Unit* w)
        {
            SelectSoundAndText(me, 2);

            tankhealAdd = 0;
            dpsAdd = 0;
            endPhaseCheck = 0;

            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            events.ScheduleEvent(EVENT_ADD_POWER, TIMER_ADD_POWER);
            events.ScheduleEvent(EVENT_YAWNING_GATE, TIMER_YAWNING_GATE);
            events.ScheduleEvent(EVENT_TENTACLE_SUMMON, TIMER_TENTACLE_SUMMON);
            events.ScheduleEvent(EVENT_WHISPER_OF_POWER, TIMER_WHISPERS_OF_POWER);

            if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
                events.ScheduleEvent(EVENT_CALL_THE_ABYSS, TIMER_CALL_THE_ABYSS);
        }

        // one empty container, gather all players, select only by spec active and insert into container than select only one as valid, no healer spec > select random
        void SelectHealerOrOther()
        {
            std::list<Unit*> validTargets;
            bool isHealer = false;

            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        uint32 specialization = player->GetSpecializationId();

                        if (player->getClass() == CLASS_PRIEST && specialization == TALENT_SPEC_PRIEST_DISCIPLINE ||
                            player->getClass() == CLASS_PRIEST && specialization == TALENT_SPEC_PRIEST_HOLY ||
                            player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_RESTORATION ||
                            player->getClass() == CLASS_MONK && specialization == TALENT_SPEC_MONK_MISTWEAVER ||
                            player->getClass() == CLASS_SHAMAN && specialization == TALENT_SPEC_SHAMAN_RESTORATION)
                        {
                            isHealer = true;
                        }

                        if (isHealer)
                            validTargets.push_back(player);
                        else
                            validTargets.push_back(player); 
                    }
                }

            if (!validTargets.empty())
                if (validTargets.size() >= 1)
                    validTargets.resize(1);

            for (auto target : validTargets)
            {
                me->AddAura(SPELL_WHISPERS_OF_POWER_AURA, target);
            }
        }

        void CheckDpsRoom()
        {
            if (!me->HasAura(SPELL_GRASP_OF_THE_SUNKEN_CITY_CHANNEL))
                return;

            bool switchTankHealPhase = false;

            std::list<Creature*> dpsRoom;
            me->GetCreatureListWithEntryInGrid(dpsRoom, NPC_FORGOTTEN_DENIZEN, 500.0f);
            if (dpsRoom.empty())
            {
                switchTankHealPhase = true;
            }

            if (switchTankHealPhase)
            {
                Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* player = i->GetSource())
                    {
                        if (!player->IsGameMaster()) //gm check
                        {
                            player->AddAura(SPELL_GRASP_OF_THE_SUNKEN_CITY_TANK_PHASE, player);
                            player->RemoveAura(SPELL_GRASP_OF_THE_SUNKEN_CITY_DPS_PHASE);
                        }
                    }
            }

        }
        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->IsInCombat())
                CheckCheaters();

            if (me->IsInCombat())
                checkSunkenPhase();

            CheckDpsRoom();

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ADD_POWER:
                {
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + urand(2, 5));
                    if (me->GetPower(POWER_ENERGY) == 100)
                    {
                        me->SetPower(POWER_ENERGY, 0);
                        events.ScheduleEvent(EVENT_GRASP_OF_THE_SUNKEN_CITY, 1000);
                    }
                    events.ScheduleEvent(EVENT_ADD_POWER, TIMER_ADD_POWER);
                    break;
                }
                case EVENT_GRASP_OF_THE_SUNKEN_CITY:
                {
                    SelectSoundAndText(me, 6);

                    me->CastSpell(me, SPELL_GRASP_OF_THE_SUNKEN_CITY_CHANNEL);

                    HandleSunkenPhase();

                    me->SummonCreature(NPC_FORGOTTEN_DENIZEN, spawnPoints[0], TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_FORGOTTEN_DENIZEN, spawnPoints[1], TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_SUNKEN_DENIZEN, spawnPoints[2], TEMPSUMMON_CORPSE_DESPAWN);
                }
                    break;
                case EVENT_YAWNING_GATE:
                    me->CastSpell(me, SPELL_YAWNING_GATE);
                    events.ScheduleEvent(EVENT_YAWNING_GATE, TIMER_YAWNING_GATE);
                    break;
                case EVENT_TENTACLE_SUMMON:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 1, SELECT_TARGET_RANDOM, 500.0f, true);

                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (auto target : targets)
                    {
                        me->CastSpell(target, SPELL_TENTACLE_SLAM_SUMMON, true);
                    }
                    events.ScheduleEvent(EVENT_TENTACLE_SUMMON, TIMER_TENTACLE_SUMMON);
                    break;
                }
                case EVENT_WHISPER_OF_POWER:
                    SelectHealerOrOther();
                    events.ScheduleEvent(EVENT_WHISPER_OF_POWER, TIMER_WHISPERS_OF_POWER);
                    break;
                case EVENT_CALL_THE_ABYSS:
                    SelectSoundAndText(me, 3);
                    me->CastSpell(me, SPELL_CALL_THE_ABYSS);
                    events.ScheduleEvent(EVENT_CALL_THE_ABYSS, TIMER_CALL_THE_ABYSS);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_volzith_the_whisperer_AI(creature);
    }
};

class bfa_npc_tentacle : public CreatureScript
{
public:
    bfa_npc_tentacle() : CreatureScript("bfa_npc_tentacle")
    {}

    struct bfa_npc_tentacle_AI : public ScriptedAI
    {
        bfa_npc_tentacle_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* w)
        {
            events.ScheduleEvent(EVENT_TENTACLE_SLAM, TIMER_TENTACLE_SLAM);
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
                case EVENT_TENTACLE_SLAM:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 100.0f))
                    {
                        me->CastSpell(target, SPELL_TENTACLE_SLAM_DMG);
                    }
                    events.ScheduleEvent(EVENT_TENTACLE_SLAM, TIMER_TENTACLE_SLAM);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_tentacle_AI(creature);
    }
};

class bfa_npc_manifestation_of_the_deep : public CreatureScript
{
public:
    bfa_npc_manifestation_of_the_deep() : CreatureScript("bfa_npc_manifestation_of_the_deep")
    {}

    struct bfa_npc_manifestation_of_the_deep_AI : public ScriptedAI
    {
        bfa_npc_manifestation_of_the_deep_AI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        Creature* GetVolzith()
        {
            return me->FindNearestCreature(BOSS_VOLZITH_THE_WHISPERER, 500.0f, true);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (Creature* volzith = GetVolzith())
            {
                me->GetMotionMaster()->MoveChase(volzith);
                if (me->GetDistance(volzith) <= 1.0f)
                {
                    me->CastSpell(me, SPELL_ABYSSAL_ERUPTION_DMG, true);
                    volzith->SetPower(POWER_ENERGY, volzith->GetPower(POWER_ENERGY) + 1);
                    me->DespawnOrUnsummon();
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_manifestation_of_the_deep_AI(creature);
    }
};

class bfa_npc_forgotten_denizen : public CreatureScript
{
public:
    bfa_npc_forgotten_denizen() : CreatureScript("bfa_npc_forgotten_denizen")
    {}

    struct bfa_npc_forgotten_denizen_AI : public ScriptedAI
    {
        bfa_npc_forgotten_denizen_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisplayId(68244);
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        Creature* GetVolzith()
        {
            return me->FindNearestCreature(BOSS_VOLZITH_THE_WHISPERER, 500.0f, true);
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (!attacker->HasAura(SPELL_GRASP_OF_THE_SUNKEN_CITY_DPS_PHASE))
            {
                damage = 0;
                me->SetHealth(me->GetHealth() + 1);
                me->SetHealth(me->GetHealth() - 1);
            }

            if (damage >= me->GetHealth())
            {
                if (Creature* volzith = GetVolzith())
                    volzith->AI()->DoAction(ACTION_COUNT_DPS_PHASE);
                me->DespawnOrUnsummon(1000);
            }
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_CONSUME_ESSENCE, 3000);
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
                case EVENT_CONSUME_ESSENCE:
                    me->CastSpell(me->GetVictim(), SPELL_CONSUME_ESSENCE);
                    events.ScheduleEvent(EVENT_CONSUME_ESSENCE, TIMER_CONSUME_ESSENCE);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_forgotten_denizen_AI(creature);
    }
};

class bfa_npc_sunken_denizen : public CreatureScript
{
public:
    bfa_npc_sunken_denizen() : CreatureScript("bfa_npc_sunken_denizen")
    {}

    struct bfa_npc_sunken_denizen_AI : public ScriptedAI
    {
        bfa_npc_sunken_denizen_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_LEVIATHANS_WAKE);
        }

        EventMap events;

        Creature* GetVolzith()
        {
            return me->FindNearestCreature(BOSS_VOLZITH_THE_WHISPERER, 500.0f, true);
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (!attacker->HasAura(SPELL_GRASP_OF_THE_SUNKEN_CITY_TANK_PHASE))
            {
                damage = 0;
                me->SetHealth(me->GetHealth() + 1);
                me->SetHealth(me->GetHealth() - 1);
            }

            if (damage >= me->GetHealth())
            {
                if (Creature* volzith = GetVolzith())
                    volzith->AI()->DoAction(ACTION_COUNT_TANK_HEAL_PHASE);
                AddSpecialAuraOnDeath();
                me->DespawnOrUnsummon(1000);
            }
        }


        void AddSpecialAuraOnDeath()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        player->AddAura(SPELL_GRASP_OF_THE_SUNKEN_CITY_DPS_PHASE);
                        player->RemoveAura(SPELL_GRASP_OF_THE_SUNKEN_CITY_TANK_PHASE);
                    }
                }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!me->IsInCombat())
                me->SetInCombatWithZone();

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_sunken_denizen_AI(creature);
    }
};

// 267299
class bfa_spell_call_the_abyss : public SpellScriptLoader
{
public:
    bfa_spell_call_the_abyss() : SpellScriptLoader("bfa_spell_call_the_abyss") { }

    class bfa_spell_call_the_abyss_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_call_the_abyss_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Position const dest = manifestSpawnPoints[urand(0, 15)];
            GetCaster()->CastSpell(dest, SPELL_CALL_THE_ABYSS_SUMMON, true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_call_the_abyss_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_call_the_abyss_AuraScript();
    }
};

// 13312 
class bfa_yawning_gate_at : public AreaTriggerEntityScript
{
public:
    bfa_yawning_gate_at() : AreaTriggerEntityScript("bfa_yawning_gate_at") { }

    struct bfa_yawning_gate_at_AI : AreaTriggerAI
    {
        bfa_yawning_gate_at_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            if (!unit->HasAura(SPELL_YAWNING_GATE_AURA) && unit->IsPlayer())
                unit->CastSpell(unit, SPELL_YAWNING_GATE_AURA, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            unit->RemoveAurasDueToSpell(SPELL_YAWNING_GATE_AURA);
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_yawning_gate_at_AI(areatrigger);
    }
};


void AddSC_boss_volzith_the_whisperer()
{
    new bfa_boss_volzith_the_whisperer();
    new bfa_npc_tentacle();
    new bfa_npc_forgotten_denizen();
    new bfa_npc_manifestation_of_the_deep();
    new bfa_npc_sunken_denizen();

    new bfa_spell_call_the_abyss();

    new bfa_yawning_gate_at();
}
