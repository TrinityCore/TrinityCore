#include "Chat.h"
#include "CombatAI.h"
#include "Conversation.h"
#include "Creature.h"
#include "CreatureGroups.h"
#include "CreatureTextMgr.h"
#include "DBCEnums.h"
#include "DynamicObject.h"
#include "emerald_nightmare.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "LFGMgr.h"
#include "LFGPackets.h"
#include "LFGQueue.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MiscPackets.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "PhasingHandler.h"
#include "SceneMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"
#include "Transport.h"
#include "Unit.h"
#include "Vehicle.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_NIGHTMARE_BLADES = 1,
    SAY_MANIFEST_CORRUPTION = 2,
    SAY_DARKENING_SOUL = 3,
    SAY_PEREPHASE = 4,
    SAY_DEATH = 5,
};

enum Spells
{
    SPELL_XAVIUS_ENERGIZE = 226192,
    SPELL_XAVIUS_ENERGIZE_PHASE_1 = 226184,
    SPELL_XAVIUS_ENERGIZE_PHASE_2 = 226193,
    SPELL_XAVIUS_ENERGIZE_PHASE_3 = 226185,
    SPELL_UNFATHOMABLE_REALITY = 207160,

    //Phase 1
    SPELL_LURKING_ERUPTION = 208322,
    SPELL_MANIFEST_CORRUPTION = 210264,
    SPELL_DARKENING_SOUL = 206651,
    SPELL_DARKENING_SOUL_AOE = 207859,
    SPELL_DARKENING_SOUL_ENERGY = 206652,
    SPELL_NIGHTMARE_BLADES_FILTER = 209000, //Check target
    SPELL_NIGHTMARE_BLADES_FILTER_2 = 211579, //Sum trigger
    SPELL_NIGHTMARE_BLADES_SUM = 206653,
    SPELL_NIGHTMARE_BLADES_MARK = 209001,
    SPELL_NIGHTMARE_BLADES_MARK_2 = 211802,
    SPELL_NIGHTMARE_BLADES_DMG = 206656,

    //Phase 2
    SPELL_BLACKENING_SOUL = 209158,
    SPELL_BLACKENED = 205612,
    SPELL_BLACKENED_TAINTING_ENERGY = 207853,
    SPELL_NIGHTMARE_INFUSION = 209443,
    SPELL_CALL_OF_NIGHTMARES = 205588, //Energy cost
    SPELL_SPAWN_INCONCEIVABLE = 205739, //Summon Inconceivable Horror
    SPELL_TAINTED_DISCHARGE_TRIG_AT = 208362,
    SPELL_TAINTED_DISCHARGE_AT = 208363,
    SPELL_CORRUPTION_METEOR = 206308,

    //Phase 3
    SPELL_WRITHING_DEEP = 226194, //Energy cost

    //Phase 2: Heroic
    SPELL_BONDS_OF_TERROR = 209032,
    SPELL_BONDS_OF_TERROR_AURA = 209034,
    SPELL_BONDS_OF_TERROR_AURA_2 = 210451,

    //Player spells
    SPELL_NIGHTMARE_TORMENT_ALT_POWER = 189960,
    SPELL_NIGHTMARE_TORMENT_TICK = 226227,
    SPELL_THE_DREAMING_SUM_CLONE = 206000,
    SPELL_THE_DREAMING_CLONE_IMAGE = 206002,
    SPELL_DREAM_SIMULACRUM = 206005,
    SPELL_AWAKENING_DREAM = 207634,
    SPELL_INSANITY_LEVEL_1 = 210203,
    SPELL_INSANITY_LEVEL_2 = 210204,
    SPELL_DESCENT_INTO_MADNESS = 208431,
    SPELL_CORRUPTION_MADNESS = 207409,

    //Player clone spells
    SPELL_DREAMING_CLONE_ABORB = 189449,

    //Dread Abomination
    SPELL_CORRUPTION_CRUSHING_SHADOWS = 208748,

    //Lurking Terror
    SPELL_TORMENTING_FIXATION_FILTER = 205770,
    SPELL_TORMENTING_FIXATION = 205771,
    SPELL_TORMENTING_INFECTION_AT = 217989, //Normal
    SPELL_TORMENTING_INFECTION_DMG = 217990,
    SPELL_TORMENTING_DETONATION_AT = 205780, //Heroic
    SPELL_TORMENTING_DETONATION_DMG = 205782,

    //Corruption Horror
    SPELL_CORRUPTION_HORROR_BIRTH = 213345,
    SPELL_TORMENTING_SWIPE = 224649,
    SPELL_CORRUPTING_NOVA = 207830,

    //Inconceivable Horror
    SPELL_DARK_RUINATION = 209288,
    SPELL_TAINTED_DISCHARGE_SUM = 212124, //Summon Inconceivable Horror

    //Nightmare Tentacle
    SPELL_NIGHTMARE_BOLT = 206920,
};

enum eEvents
{
    EVENT_ABOMINATION_CRUSHING = 1,
    EVENT_DARKENING_SOUL = 2,
    EVENT_NIGHTMARE_BLADES = 3,
    EVENT_BLACKENING_SOUL = 4,
    EVENT_NIGHTMARE_INFUSION = 5,
    EVENT_CORRUPTION_METEOR = 6,
    EVENT_CHECK_ALT_POWER = 7,

    //Heroic
    EVENT_BONDS_OF_TERROR,
};

enum ePhase
{
    PHASE_1 = 0,
    PHASE_2,
    PHASE_3
};

Position const dreadPos[8] =
{
    { -3061.0f, -4959.0f, 147.78f, 5.4f },
    { -2919.0f, -5101.0f, 147.78f, 2.3f },
    { -3090.0f, -5030.0f, 147.78f, 0.0f },
    { -3061.0f, -5101.0f, 147.78f, 0.7f },
    { -2990.0f, -5130.0f, 147.78f, 1.5f },
    { -2919.0f, -4959.0f, 147.78f, 3.9f },
    { -2990.0f, -4930.0f, 147.78f, 4.7f },
    { -2890.0f, -5030.0f, 147.78f, 3.1f }
};

Position const centrPos = { -2990.16f, -5029.85f, 147.78f };

Position const eventPos[10] =
{
    { -2953.67f, -5117.50f, 147.70f, 0.0f },
    { -2938.12f, -4980.82f, 147.70f, 0.0f },
    { -3069.40f, -4997.82f, 147.70f, 0.0f },

    { -2960.12f, -5043.86f, 147.70f, 0.0f },
    { -2995.12f, -4992.84f, 147.70f, 0.0f },
    { -3015.60f, -5056.74f, 147.70f, 0.0f },

    { -3030.53f, -5054.32f, 147.70f, 0.0f },
    { -2971.15f, -5066.08f, 147.70f, 0.0f },
    { -2956.51f, -4994.40f, 147.70f, 0.0f },
    { -3030.22f, -4992.07f, 147.70f, 0.0f }

};

// 103769 - Xavius
class boss_xavius : public CreatureScript
{
public:
    boss_xavius() : CreatureScript("boss_xavius") {}

    struct boss_xaviusAI : public BossAI
    {
        boss_xaviusAI(Creature* creature) : BossAI(creature, DATA_XAVIUS)
        {
            intro = true;
        }

        bool intro;
        uint8 healthPct;
        uint8 healthPhasePct;
        uint8 eventPhase;

        void Reset() override
        {
            _Reset();
            healthPct = 95;
            healthPhasePct = 65;
            eventPhase = 0;
            me->SetPower(POWER_ENERGY, 30);

            if (instance->GetBossState(DATA_PRE_EVENT_XAVIUS) == DONE) // only after pre-event boss can start to do any things
            {
                if (intro)
                {
                    intro = false;
                    me->SetVisible(true);
                    me->SetHomePosition(-3019.56f, -5060.41f, 147.70f, me->GetHomePosition().GetOrientation());
                    me->GetMotionMaster()->MovePoint(0, -3019.56f, -5060.41f, 147.70f);
                }

                me->SetReactState(REACT_AGGRESSIVE);

                for (uint8 i = 0; i < 8; i++)
                    me->SummonCreature(NPC_DREAD_ABOMINATION, dreadPos[i]);
            }
            else
            {
                me->SetVisible(false);
                me->SetReactState(REACT_PASSIVE);
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            _EnterCombat();
            ClearPlayerAuras();
            DoCast(me, SPELL_XAVIUS_ENERGIZE_PHASE_1, true);
            DoCast(me, SPELL_UNFATHOMABLE_REALITY, true);
            instance->DoCastSpellOnPlayers(SPELL_NIGHTMARE_TORMENT_ALT_POWER);

            StartEvents(PHASE_1);

            if (Creature* yzera = me->SummonCreature(NPC_YZERA, -2988.90f, -5028.98f, 182.07f))
            {
                AddTimedDelayedOperation(5000, [yzera]() -> void
                {
                    yzera->CastSpell(yzera, 222713);
                });
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            ClearPlayerAuras();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            BossAI::EnterEvadeMode();
            ClearPlayerAuras();
        }

        void StartEvents(uint8 phase)
        {
            events.Reset();
            eventPhase = phase;

            switch (phase)
            {
            case PHASE_1:
                events.ScheduleEvent(EVENT_ABOMINATION_CRUSHING, 12000);
                events.ScheduleEvent(EVENT_DARKENING_SOUL, 7000);
                events.ScheduleEvent(EVENT_NIGHTMARE_BLADES, 18000);
                break;
            case PHASE_2:
                events.ScheduleEvent(EVENT_BLACKENING_SOUL, 7000);
                events.ScheduleEvent(EVENT_CORRUPTION_METEOR, 21000);
                events.ScheduleEvent(EVENT_NIGHTMARE_INFUSION, 32000);
                if (GetDifficulty() == DIFFICULTY_HEROIC_RAID || GetDifficulty() == DIFFICULTY_MYTHIC_RAID)
                    events.ScheduleEvent(EVENT_BONDS_OF_TERROR, 12000);
                break;
            case PHASE_3:
                events.ScheduleEvent(EVENT_BLACKENING_SOUL, 7000);
                events.ScheduleEvent(EVENT_NIGHTMARE_BLADES, 18000);
                events.ScheduleEvent(EVENT_CORRUPTION_METEOR, 21000);
                events.ScheduleEvent(EVENT_NIGHTMARE_INFUSION, 32000);
                break;
            }
            events.ScheduleEvent(EVENT_CHECK_ALT_POWER, 2000);
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (!attacker->HasAura(SPELL_NIGHTMARE_TORMENT_ALT_POWER))
            {
                damage = 0;
                return;
            }

            if (me->HealthBelowPct(healthPct))
            {
                if (healthPct > 60)
                    healthPct = 60;
                else
                    healthPct = 0;

                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 100.0f);

                if (!playerList.empty())
                {
                    Trinity::Containers::RandomResize(playerList, playerList.size() > 1 ? playerList.size() / 2 : 1);

                    for (auto const& player : playerList)
                    {
                        if (!player || !player->IsAlive() || player->IsGameMaster())
                            continue;

                        player->CastSpell(player, SPELL_THE_DREAMING_SUM_CLONE, true);
                    }

                    if (Creature* yzera = me->FindNearestCreature(NPC_YZERA, 100.0f, true))
                    {
                        AddTimedDelayedOperation(5000, [yzera]() -> void
                        {
                            yzera->CastSpell(yzera, 222713);
                        });
                    }
                }
            }

            //Regulates events phases
            if (me->HealthBelowPct(healthPhasePct))
            {
                Talk(SAY_PEREPHASE);
                if (healthPhasePct > 30) //65%
                {
                    StartEvents(PHASE_2);
                    healthPhasePct = 30;
                }
                else
                {
                    StartEvents(PHASE_3);
                    healthPhasePct = 0;
                }
            }
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_CALL_OF_NIGHTMARES)
            {
                Position pos;
                float angle = 0.0f;
                for (uint8 i = 0; i < 6; i++)
                {
                    angle = frand(0, 6.0f);
                    //centrPos.SimplePosXYRelocationByAngle(pos, 55.0f, angle);
                    me->CastSpell(pos, SPELL_TAINTED_DISCHARGE_SUM, true);
                }
            }
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_NIGHTMARE_BLADES_MARK)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, checkPlayers(), 150.0f, true, -SPELL_NIGHTMARE_BLADES_MARK))
                    DoCast(pTarget, SPELL_NIGHTMARE_BLADES_MARK_2, true);
                Talk(SAY_NIGHTMARE_BLADES);
            }
        }

        /*void OnAreaTriggerDespawn(uint32 spellId, Position pos, bool duration) override
        {
            if (duration && spellId == SPELL_TAINTED_DISCHARGE_AT)
                me->CastSpell(pos, SPELL_TAINTED_DISCHARGE_SUM, true);
        }*/

        uint32 GetData(uint32 type) const override
        {
            if (type == DATA_XAVIUS)
                return eventPhase;
            return 0;
        }

        void ClearPlayerAuras()
        {
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NIGHTMARE_TORMENT_ALT_POWER);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NIGHTMARE_TORMENT_TICK);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INSANITY_LEVEL_1);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INSANITY_LEVEL_2);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DREAM_SIMULACRUM);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DESCENT_INTO_MADNESS);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CORRUPTION_MADNESS);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLACKENING_SOUL);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BONDS_OF_TERROR_AURA);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BONDS_OF_TERROR_AURA_2);
        }

        bool checkPlayers()
        {
            std::list<HostileReference*> threatList = me->getThreatManager().getThreatList();
            if (threatList.size() > 1)
                return true;

            return false;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            /* if (CheckHomeDistToEvade(diff, 45.0f, centrPos.GetPositionX(), centrPos.GetPositionY(), centrPos.GetPositionZ()))
                 return;*/

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ABOMINATION_CRUSHING:
                {
                    EntryCheckPredicate pred(NPC_DREAD_ABOMINATION);
                    summons.DoAction(1, pred, 1);
                    events.ScheduleEvent(EVENT_ABOMINATION_CRUSHING, 10000);
                    break;
                }
                case EVENT_DARKENING_SOUL:
                    DoCastVictim(SPELL_DARKENING_SOUL);
                    events.ScheduleEvent(EVENT_DARKENING_SOUL, 8000);
                    if (urand(0, 3) == 3)
                        Talk(SAY_DARKENING_SOUL);
                    break;
                case EVENT_NIGHTMARE_BLADES:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, checkPlayers(), 150.0f, true, -SPELL_NIGHTMARE_BLADES_MARK_2))
                    {
                        DoCast(target, SPELL_NIGHTMARE_BLADES_MARK, true);
                        DoCast(target, SPELL_NIGHTMARE_BLADES_MARK_2, true);
                    }
                    events.ScheduleEvent(EVENT_NIGHTMARE_BLADES, 16000);
                    break;
                case EVENT_BLACKENING_SOUL:
                    DoCastVictim(SPELL_BLACKENING_SOUL);
                    events.ScheduleEvent(EVENT_BLACKENING_SOUL, 7000);
                    break;
                case EVENT_NIGHTMARE_INFUSION:
                    DoCast(me, SPELL_NIGHTMARE_INFUSION, true);
                    events.ScheduleEvent(EVENT_NIGHTMARE_INFUSION, 62000);
                    break;
                case EVENT_CORRUPTION_METEOR:
                    DoCast(me, SPELL_CORRUPTION_METEOR, true);
                    events.ScheduleEvent(EVENT_CORRUPTION_METEOR, 29000);
                    break;
                case EVENT_CHECK_ALT_POWER:
                {
                    Map::PlayerList const& players = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        if (Player* player = itr->GetSource())
                            if (player->IsAlive() && !player->IsGameMaster() && !player->HasAura(SPELL_NIGHTMARE_TORMENT_ALT_POWER))
                                player->CastSpell(player, SPELL_NIGHTMARE_TORMENT_ALT_POWER, true);
                    }
                    events.ScheduleEvent(EVENT_CHECK_ALT_POWER, 2000);
                    break;
                }
                case EVENT_BONDS_OF_TERROR:
                {
                    uint8 freePlayerCount = 0;
                    std::list<HostileReference*> threatlist = me->getThreatManager().getThreatList();

                    if (!threatlist.empty())
                    {
                        for (std::list<HostileReference*>::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
                            if (Player* player = ObjectAccessor::GetPlayer(*me, (*itr)->getUnitGuid()))
                                if (!player->HasAura(SPELL_BONDS_OF_TERROR_AURA) && !player->HasAura(SPELL_BONDS_OF_TERROR_AURA_2) &&
                                    (me->GetVictim() && me->GetVictim()->GetGUID() != player->GetGUID()))
                                {
                                    freePlayerCount++;
                                }
                    }

                    if (freePlayerCount > 1)
                        DoCast(me, SPELL_BONDS_OF_TERROR, true);
                    events.ScheduleEvent(EVENT_BONDS_OF_TERROR, 12000);
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_xaviusAI(creature);
    }
};

// 104096 - Sleeping Version
class npc_xavius_sleeping_version : public CreatureScript
{
public:
    npc_xavius_sleeping_version() : CreatureScript("npc_xavius_sleeping_version") {}

    struct npc_xavius_sleeping_versionAI : public ScriptedAI
    {
        npc_xavius_sleeping_versionAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        uint16 checkStateBoss;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            checkStateBoss = 1000;
            summoner->CastSpell(me, SPELL_THE_DREAMING_CLONE_IMAGE, true);
            DoCast(me, SPELL_DREAMING_CLONE_ABORB, true);
        }

        void UpdateAI(uint32 diff) override
        {
            if (checkStateBoss)
            {
                if (checkStateBoss <= diff)
                {
                    checkStateBoss = 1000;
                    if (instance->GetBossState(DATA_XAVIUS) != IN_PROGRESS)
                    {
                        checkStateBoss = 0;
                        me->DespawnOrUnsummon();
                    }
                }
                else checkStateBoss -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_xavius_sleeping_versionAI(creature);
    }
};

// 105343 - Dread Abomination
class npc_xavius_dread_abomination : public CreatureScript
{
public:
    npc_xavius_dread_abomination() : CreatureScript("npc_xavius_dread_abomination") {}

    struct npc_xavius_dread_abominationAI : public ScriptedAI
    {
        npc_xavius_dread_abominationAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            me->SetReactState(REACT_PASSIVE);
            me->SetVisible(false);
        }

        EventMap events;

        void Reset() override {}

        void DoAction(int32 const action) override
        {
            events.ScheduleEvent(1, 100);
        }

        bool RegulatePersonnalVisibility()
        {
            if (Unit* owner = me->GetOwner())
            {
                std::list<HostileReference*> threatlist = owner->getThreatManager().getThreatList();
                if (!threatlist.empty())
                {
                    for (std::list<HostileReference*>::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
                        if (Player* player = ObjectAccessor::GetPlayer(*me, (*itr)->getUnitGuid()))
                        {
                            if (player->HasAura(SPELL_INSANITY_LEVEL_1)) // anon_me enemy cannot determine friend from foe ignore player if aura activated
                                return false;

                        }
                    //if (!me->IsInPersonnalVisibilityList(player->GetGUID()))
                       // me->AddPlayerInPersonnalVisibilityList(player->GetGUID());
                    return true;
                }
            }
            events.Reset();
            me->SetVisible(false);
            return false;
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    if (RegulatePersonnalVisibility())
                        events.ScheduleEvent(2, 500);
                    break;
                case 2:
                    me->SetVisible(true);
                    events.ScheduleEvent(3, 1000);
                    break;
                case 3:
                    DoCast(SPELL_CORRUPTION_CRUSHING_SHADOWS);
                    events.ScheduleEvent(4, 5000);
                    break;
                case 4:
                    me->SetVisible(false);
                    //me->ClearVisibleOnlyForSomePlayers();
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_xavius_dread_abominationAI(creature);
    }
};

// 103694 - Lurking Terror
class npc_xavius_lurking_terror : public CreatureScript
{
public:
    npc_xavius_lurking_terror() : CreatureScript("npc_xavius_lurking_terror") {}

    struct npc_xavius_lurking_terrorAI : public ScriptedAI
    {
        npc_xavius_lurking_terrorAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetSpeed(MOVE_RUN, 0.6f);
            me->SetSpeed(MOVE_WALK, 0.6f);
        }

        EventMap events;
        ObjectGuid targetGUID;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            events.ScheduleEvent(1, 2000);
            events.ScheduleEvent(3, 3000);
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_TORMENTING_FIXATION_FILTER)
            {
                DoCast(target, SPELL_TORMENTING_FIXATION, true);
                targetGUID = target->GetGUID();
                events.ScheduleEvent(2, 1000);
            }

            if (spell->Id == SPELL_TORMENTING_INFECTION_DMG || spell->Id == SPELL_TORMENTING_DETONATION_DMG)
            {
                events.Reset();
                me->GetMotionMaster()->Clear();
                me->DespawnOrUnsummon(1000);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCast(me, SPELL_TORMENTING_FIXATION_FILTER, true);
                    break;
                case 2:
                    if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
                    {
                        me->GetMotionMaster()->MovePoint(1, target->GetPosition());
                        events.ScheduleEvent(2, 500);
                    }
                    else
                        events.ScheduleEvent(1, 1000);
                    break;
                case 3:
                    if (GetDifficulty() != DIFFICULTY_MYTHIC_RAID)
                        DoCast(me, SPELL_TORMENTING_INFECTION_AT, true);
                    else
                        DoCast(me, SPELL_TORMENTING_DETONATION_AT, true);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_xavius_lurking_terrorAI(creature);
    }
};

// 103695 - Corruption Horror
class npc_xavius_corruption_horror : public CreatureScript
{
public:
    npc_xavius_corruption_horror() : CreatureScript("npc_xavius_corruption_horror") {}

    struct npc_xavius_corruption_horrorAI : public ScriptedAI
    {
        npc_xavius_corruption_horrorAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            DoCast(me, SPELL_CORRUPTION_HORROR_BIRTH, true);
            DoZoneInCombat(me, 100.0f);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(1, 9000);
            events.ScheduleEvent(2, 14000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCastVictim(SPELL_TORMENTING_SWIPE);
                    events.ScheduleEvent(1, 10000);
                    break;
                case 2:
                    DoCast(SPELL_CORRUPTING_NOVA);
                    events.ScheduleEvent(2, 20000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_xavius_corruption_horrorAI(creature);
    }
};

// 104422 - Nightmare Blades
class npc_xavius_nightmare_blades : public CreatureScript
{
public:
    npc_xavius_nightmare_blades() : CreatureScript("npc_xavius_nightmare_blades") {}

    struct npc_xavius_nightmare_bladesAI : public ScriptedAI
    {
        npc_xavius_nightmare_bladesAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        EventMap events;
        std::list<ObjectGuid> listGuid;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            listGuid.clear();
            events.ScheduleEvent(1, 200);
        }

        /*bool LoadObjectData(ObjectGuid const& guid) override
        {
            bool find = false;
            for (auto targetGuid : listGuid)
                if (targetGuid == guid)
                    find = true;
            if (!find)
                listGuid.push_back(guid);
            return find;
        }*/

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                {
                    if (Unit* owner = me->GetOwner())
                        if (Unit* target = owner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true, SPELL_NIGHTMARE_BLADES_MARK))
                        {
                            Position pos;
                            float angle = target->GetRelativeAngle(me);
                            float dist = me->GetDistance(target) + 20.0f;
                            target->GetNearPosition(dist, angle);

                            float angle2 = pos.GetRelativeAngle(target);
                            float dist2 = 8.0f;
                            for (uint8 i = 0; i < 18; i++)
                            {
                                // pos.SimplePosXYRelocationByAngle(pos, dist2, angle2);
                              //  me->m_Events.AddEvent(new DelayDestCastEvent(*me, pos, SPELL_NIGHTMARE_BLADES_DMG, true), me->m_Events.CalculateTime(i * 150));
                            }
                        }
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_xavius_nightmare_bladesAI(creature);
    }
};

// 105611 - Inconceivable Horror
class npc_xavius_inconceivable_horror : public CreatureScript
{
public:
    npc_xavius_inconceivable_horror() : CreatureScript("npc_xavius_inconceivable_horror") {}

    struct npc_xavius_inconceivable_horrorAI : public ScriptedAI
    {
        npc_xavius_inconceivable_horrorAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetSpeed(MOVE_RUN, 0.3f);
            me->SetSpeed(MOVE_WALK, 0.3f);
        }

        EventMap events;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            events.ScheduleEvent(1, 1000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Unit* owner = me->GetOwner())
                if (owner->IsInCombat())
                    owner->CastSpell(me->GetPosition(), SPELL_TAINTED_DISCHARGE_TRIG_AT, true);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    if (Unit* owner = me->GetOwner())
                    {
                        if (me->GetDistance(owner) > 10.0f)
                        {
                            Position pos;
                            me->GetNearPosition(me->GetDistance(owner) / 2, me->GetRelativeAngle(owner));
                            me->GetMotionMaster()->MovePoint(1, pos);
                            events.ScheduleEvent(1, 1000);
                        }
                        else
                        {
                            me->GetMotionMaster()->Clear();
                            me->SetFacingToObject(owner);
                            DoCast(SPELL_DARK_RUINATION);
                            events.ScheduleEvent(1, 5000);
                        }
                    }
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_xavius_inconceivable_horrorAI(creature);
    }
};

// 104592 - Nightmare Tentacle
class npc_xavius_nightmare_tentacle : public CreatureScript
{
public:
    npc_xavius_nightmare_tentacle() : CreatureScript("npc_xavius_nightmare_tentacle") {}

    struct npc_xavius_nightmare_tentacleAI : public ScriptedAI
    {
        npc_xavius_nightmare_tentacleAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            SetCombatMovement(false);
        }

        EventMap events;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            events.ScheduleEvent(1, 500);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
                        DoCast(target, SPELL_NIGHTMARE_BOLT);
                    events.ScheduleEvent(1, urand(3, 5) * IN_MILLISECONDS);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_xavius_nightmare_tentacleAI(creature);
    }
};

// 109847 - Rift of Aln
class npc_xavius_event_conroller : public CreatureScript
{
public:
    npc_xavius_event_conroller() : CreatureScript("npc_xavius_event_conroller") {}

    struct npc_xavius_event_conrollerAI : public ScriptedAI
    {
        npc_xavius_event_conrollerAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            instance = me->GetInstanceScript();
            countAdds = 0;
            checkevade = 1000;
            SetCanSeeEvenInPassiveMode(true);
            if (instance->GetBossState(DATA_PRE_EVENT_XAVIUS) == NOT_STARTED)
            {
                for (int i = 0; i < 9; ++i)
                {
                    me->SummonCreature(NPC_SMALL_TRASH, eventPos[6].GetPositionX() + irand(-15, 15), eventPos[6].GetPositionY() + irand(-15, 15), eventPos[6].GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
                for (int i = 0; i < 9; ++i)
                {
                    me->SummonCreature(NPC_SMALL_TRASH, eventPos[7].GetPositionX() + irand(-15, 15), eventPos[7].GetPositionY() + irand(-15, 15), eventPos[7].GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
                for (int i = 0; i < 9; ++i)
                {
                    me->SummonCreature(NPC_SMALL_TRASH, eventPos[8].GetPositionX() + irand(-15, 15), eventPos[8].GetPositionY() + irand(-15, 15), eventPos[8].GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
                for (int i = 0; i < 9; ++i)
                {
                    me->SummonCreature(NPC_SMALL_TRASH, eventPos[9].GetPositionX() + irand(-15, 15), eventPos[9].GetPositionY() + irand(-15, 15), eventPos[9].GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                }
            }
        }

        SummonList summons;
        EventMap events;
        InstanceScript* instance; // DATA_PRE_EVENT_XAVIUS

        uint8 countAdds;
        uint32 checkevade;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (instance->GetBossState(DATA_PRE_EVENT_XAVIUS) != NOT_STARTED)
                return;

            if (me->GetExactDist2d(who) <= 17.0f)
                return;
            events.Reset();
            instance->SetBossState(DATA_PRE_EVENT_XAVIUS, IN_PROGRESS);
            std::list<Creature*> adds;
            GetCreatureListWithEntryInGrid(adds, me, NPC_SMALL_TRASH, 150.0f);
            if (!adds.empty())
                for (std::list<Creature*>::iterator itr = adds.begin(); itr != adds.end(); ++itr)
                {
                    (*itr)->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                    (*itr)->GetMotionMaster()->MovePoint(0, (2.0*(*itr)->GetPositionX() - me->GetPositionX()), (2.0*(*itr)->GetPositionY() - me->GetPositionY()), (*itr)->GetPositionZ()); // way for nice despawn
                    (*itr)->DespawnOrUnsummon(3000);
                }
            events.ScheduleEvent(1, 5000);
            countAdds = 0;
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            // DoZoneInCombat(summon, 100.0f);
            if (summon->GetEntry() == NPC_SMALL_TRASH)
                summon->GetMotionMaster()->MoveRandom(5.0f);
            else if (Player* targ = me->SelectNearestPlayer(100.0f))
                summon->AI()->AttackStart(targ);
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            if (summon->GetEntry() != NPC_IN_THE_SHADOW && summon->GetEntry() != NPC_NIGHTMARE_AMALGAMATION && summon->GetEntry() != NPC_SHADOW_POUNDER)
                return;

            countAdds++;

            switch (countAdds)
            {
            case 3:
                events.ScheduleEvent(2, 3000);
                break;
            case 6:
                events.ScheduleEvent(3, 3000);
                break;
            case 12:
                events.ScheduleEvent(5, 5000);
                break;
            default:
                break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (checkevade <= diff)
            {
                if (instance->GetBossState(DATA_PRE_EVENT_XAVIUS) == IN_PROGRESS)
                    if (me->SelectNearestPlayer(70.0f))
                    {
                        events.Reset();
                        instance->SetBossState(DATA_PRE_EVENT_XAVIUS, NOT_STARTED);
                        summons.DespawnAll();
                    }
                checkevade = 1000;
            }
            else
                checkevade -= diff;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    for (uint8 i = 0; i < 3; i++)
                        me->SummonCreature(NPC_IN_THE_SHADOW, eventPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    events.ScheduleEvent(6, 5000);
                    break;
                case 2:
                    for (uint8 i = 0; i < 3; i++)
                        me->SummonCreature(NPC_NIGHTMARE_AMALGAMATION, eventPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    events.ScheduleEvent(6, 5000);
                    break;
                case 3:
                    for (uint8 i = 0; i < 2; i++)
                        me->SummonCreature(NPC_NIGHTMARE_AMALGAMATION, eventPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    me->SummonCreature(NPC_IN_THE_SHADOW, eventPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    events.ScheduleEvent(4, 7000);
                    events.ScheduleEvent(6, 5000);
                    break;
                case 4:
                    for (uint8 i = 3; i < 6; i++)
                        me->SummonCreature(NPC_SHADOW_POUNDER, eventPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    break;
                case 5:
                {
                    instance->SetBossState(DATA_PRE_EVENT_XAVIUS, DONE);
                    if (Creature* boss = me->FindNearestCreature(NPC_XAVIUS, 100.0f, true))
                        boss->AI()->Reset();
                    events.Reset();
                    summons.DespawnAll();
                    break;
                }
                case 6:
                    for (uint8 i = 0; i < 6; i++)
                        me->SummonCreature(NPC_DARK_DEVOURERS, me->GetPositionX() + irand(-25, 25), me->GetPositionY() + irand(-25, 25), me->GetPositionZ());
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_xavius_event_conrollerAI(creature);
    }
};

// 226184 - Xavius Energize Phase 1
class spell_xavius_periodic_energize : public SpellScriptLoader
{
public:
    spell_xavius_periodic_energize() : SpellScriptLoader("spell_xavius_periodic_energize") { }

    class spell_xavius_periodic_energize_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_xavius_periodic_energize_AuraScript);

        uint8 powerCount = 0;
        uint8 castCount = 0;
        bool hightTick = false;

        void OnTick(AuraEffect const* aurEff)
        {
            Creature* caster = GetCaster()->ToCreature();
            if (!caster || !caster->IsInCombat())
                return;

            powerCount = caster->GetPower(POWER_ENERGY);

            if (powerCount < 100)
            {
                if (caster->AI()->GetData(DATA_XAVIUS) == PHASE_2)
                {
                    if (hightTick)
                    {
                        caster->SetPower(POWER_ENERGY, powerCount + 3);
                        hightTick = false;
                    }
                    else
                    {
                        caster->SetPower(POWER_ENERGY, powerCount + 2);
                        hightTick = true;
                    }
                }
                else
                    caster->SetPower(POWER_ENERGY, powerCount + 5);
            }
            else if (!caster->HasUnitState(UNIT_STATE_CASTING))
            {
                if (caster->AI()->GetData(DATA_XAVIUS) == PHASE_1)
                {
                    castCount++;

                    if (castCount < 3)
                        caster->CastSpell(caster, SPELL_LURKING_ERUPTION, true);
                    else
                    {
                        castCount = 0;
                        caster->CastSpell(caster, SPELL_MANIFEST_CORRUPTION, true);
                        caster->AI()->Talk(SAY_MANIFEST_CORRUPTION);
                    }
                    caster->SetPower(POWER_ENERGY, 0);
                }
                else if (caster->AI()->GetData(DATA_XAVIUS) == PHASE_2)
                {
                    caster->CastSpell(caster, SPELL_CALL_OF_NIGHTMARES);
                }
                else if (caster->AI()->GetData(DATA_XAVIUS) == PHASE_3)
                {
                    caster->CastSpell(caster, SPELL_WRITHING_DEEP);
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_xavius_periodic_energize_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_xavius_periodic_energize_AuraScript();
    }
};

// 206005 - Dream Simulacrum
class spell_xavius_dream_simulacrum : public SpellScriptLoader
{
public:
    spell_xavius_dream_simulacrum() : SpellScriptLoader("spell_xavius_dream_simulacrum") {}

    class spell_xavius_dream_simulacrum_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_xavius_dream_simulacrum_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            /*if (Player* player = GetTarget()->ToPlayer())
            {
                if (InstanceScript* instance = player->GetInstanceScript())
                    if (instance->GetBossState(DATA_XAVIUS) != IN_PROGRESS)
                        return;
                CreatureList infernales;
                GuidList* summonList = GetCreatureListWithEntryInGrid(infernales, NPC_SLEEPING_VERSION, 250.0f);
                for (GuidList::const_iterator iter = summonList->begin(); iter != summonList->end(); ++iter)
                {
                    if (Creature* summon = ObjectAccessor::GetCreature(*player, (*iter)))
                    {
                        player->ResetAllPowers();
                        player->RemoveAllAurasOnDeath();
                        player->CastSpell(summon, SPELL_AWAKENING_DREAM, true);
                        summon->DespawnOrUnsummon(100);
                    }
                }
            }*/
        }

        void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32 & absorbAmount)
        {
            if (!GetTarget())
                return;

            if (dmgInfo.GetDamage() < GetTarget()->GetHealth())
                absorbAmount = 0;
            else
                GetAura()->Remove();
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_xavius_dream_simulacrum_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_xavius_dream_simulacrum_AuraScript::OnAbsorb, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_xavius_dream_simulacrum_AuraScript();
    }
};

// 189960 - Nightmare Torment
class spell_xavius_nightmare_torment_alt_power : public SpellScriptLoader
{
public:
    spell_xavius_nightmare_torment_alt_power() : SpellScriptLoader("spell_xavius_nightmare_torment_alt_power") { }

    class spell_xavius_nightmare_torment_alt_power_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_xavius_nightmare_torment_alt_power_AuraScript);

        bool madnes = false;

        void OnTick(AuraEffect const* aurEff)
        {
            if (!GetCaster())
                return;

            if (Player* player = GetCaster()->ToPlayer())
            {
                uint8 altPower = player->GetPower(POWER_ALTERNATE_POWER);

                if (altPower < 100 && madnes)
                    madnes = false;

                if (altPower >= 33 && altPower < 66 && !player->HasAura(SPELL_INSANITY_LEVEL_1))
                    player->CastSpell(player, SPELL_INSANITY_LEVEL_1, true);
                else if (altPower < 33 && player->HasAura(SPELL_INSANITY_LEVEL_1))
                    player->RemoveAurasDueToSpell(SPELL_INSANITY_LEVEL_1);

                if (altPower >= 66 && altPower < 100 && !player->HasAura(SPELL_INSANITY_LEVEL_2))
                    player->CastSpell(player, SPELL_INSANITY_LEVEL_2, true);
                else if (altPower < 66 && player->HasAura(SPELL_INSANITY_LEVEL_2))
                    player->RemoveAurasDueToSpell(SPELL_INSANITY_LEVEL_2);

                if (altPower >= 100 && !madnes)
                {
                    madnes = true;
                    player->CastSpell(player, SPELL_DESCENT_INTO_MADNESS, true);
                }
            }
        }

        void CalculateAmount(AuraEffect const* aurEff, int32 & amount, bool& /*canBeRecalculated*/)
        {
            amount = 1;
        }

        void Absorb(AuraEffect* /*AuraEffect**/, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            absorbAmount = 0;
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_xavius_nightmare_torment_alt_power_AuraScript::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_xavius_nightmare_torment_alt_power_AuraScript::CalculateAmount, EFFECT_2, SPELL_AURA_SCHOOL_HEAL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_xavius_nightmare_torment_alt_power_AuraScript::Absorb, EFFECT_2);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_xavius_nightmare_torment_alt_power_AuraScript();
    }
};

// 208860 - Corruption: Crushing Shadows
class spell_xavius_crushing_shadows : public SpellScriptLoader
{
public:
    spell_xavius_crushing_shadows() : SpellScriptLoader("spell_xavius_crushing_shadows") { }

    class spell_xavius_crushing_shadows_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_xavius_crushing_shadows_SpellScript);

        void DealDamage()
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            Position const* pos = GetExplTargetDest();
            float distance = pos->GetExactDist2d(GetHitUnit());
            float radius = GetSpellInfo()->GetEffect(EFFECT_0)->CalcRadius(GetCaster());
            uint32 damage = GetHitDamage() * (1 - ((distance * 3) / radius));

            SetHitDamage(damage);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_xavius_crushing_shadows_SpellScript::DealDamage);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_xavius_crushing_shadows_SpellScript();
    }
};

// 207160 - Corruption: Unfathomable Reality
class spell_xavius_unfathomable_reality : public SpellScriptLoader
{
public:
    spell_xavius_unfathomable_reality() : SpellScriptLoader("spell_xavius_unfathomable_reality") { }

    class spell_xavius_unfathomable_reality_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_xavius_unfathomable_reality_AuraScript);

        void OnTick(AuraEffect const* aurEff)
        {
            if (!GetCaster())
                return;

            Position pos;
            GetCaster()->GetRandomNearPosition(60.0f);
            GetCaster()->CastSpell(pos, 206878, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_xavius_unfathomable_reality_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_xavius_unfathomable_reality_AuraScript();
    }
};

// 208431 - Corruption: Descent into Madness
class spell_xavius_descent_into_madness : public SpellScriptLoader
{
public:
    spell_xavius_descent_into_madness() : SpellScriptLoader("spell_xavius_descent_into_madness") {}

    class spell_xavius_descent_into_madness_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_xavius_descent_into_madness_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (Player* player = GetTarget()->ToPlayer())
            {
                if (player->HasAura(SPELL_DREAM_SIMULACRUM))
                {
                    player->RemoveAurasDueToSpell(SPELL_DREAM_SIMULACRUM);
                    return;
                }

                if (InstanceScript* instance = player->GetInstanceScript())
                    if (instance->GetBossState(DATA_XAVIUS) == IN_PROGRESS)
                        if (Creature* xavius = instance->instance->GetCreature(instance->GetGuidData(NPC_XAVIUS)))
                        {
                            xavius->CastSpell(player, SPELL_CORRUPTION_MADNESS, true);
                        }
            }
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_xavius_descent_into_madness_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_xavius_descent_into_madness_AuraScript();
    }
};

// 206651 - Darkening Soul
// 209158 - Blackening Soul
class spell_xavius_darkening_soul : public SpellScriptLoader
{
public:
    spell_xavius_darkening_soul() : SpellScriptLoader("spell_xavius_darkening_soul") {}

    class spell_xavius_darkening_soul_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_xavius_darkening_soul_AuraScript);

        bool remove = false;
        bool dispel = false;

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (!GetCaster() || !GetTarget() || GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL || remove)
                return;

            if (GetTarget())
            {
                remove = true;

                if (GetId() == SPELL_DARKENING_SOUL)
                    GetTarget()->CastSpell(GetTarget(), SPELL_DARKENING_SOUL_AOE, true);
                else if (GetId() == SPELL_BLACKENING_SOUL)
                    GetTarget()->CastSpell(GetTarget(), SPELL_BLACKENED, true);
            }
        }

        void HandleDispel(DispelInfo* dispelInfo)
        {
            if (!GetCaster() || dispel)
                return;

            if (Unit* dispeller = dispelInfo->GetDispeller())
            {
                dispel = true;

                if (GetId() == SPELL_DARKENING_SOUL)
                    dispeller->CastSpell(dispeller, SPELL_DARKENING_SOUL_ENERGY, true);
                else if (GetId() == SPELL_BLACKENING_SOUL)
                    dispeller->CastSpell(dispeller, SPELL_BLACKENED_TAINTING_ENERGY, true);
            }
        }

        void Register() override
        {
            OnDispel += AuraDispelFn(spell_xavius_darkening_soul_AuraScript::HandleDispel);
            OnEffectRemove += AuraEffectRemoveFn(spell_xavius_darkening_soul_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_xavius_darkening_soul_AuraScript();
    }
};

// 211802 - Nightmare Blades
class spell_xavius_nightmare_blades : public SpellScriptLoader
{
public:
    spell_xavius_nightmare_blades() : SpellScriptLoader("spell_xavius_nightmare_blades") { }

    class spell_xavius_nightmare_blades_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_xavius_nightmare_blades_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (!GetCaster() || !GetTarget())
                return;

            if (!GetTarget()->HasAura(SPELL_NIGHTMARE_BLADES_MARK))
                GetCaster()->CastSpell(GetTarget(), SPELL_NIGHTMARE_BLADES_SUM, true);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_xavius_nightmare_blades_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_xavius_nightmare_blades_AuraScript();
    }
};

// 206656 - Nightmare Blades
class spell_xavius_nightmare_blades_dmg_filter : public SpellScriptLoader
{
public:
    spell_xavius_nightmare_blades_dmg_filter() : SpellScriptLoader("spell_xavius_nightmare_blades_dmg_filter") { }

    class spell_xavius_nightmare_blades_dmg_filter_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_xavius_nightmare_blades_dmg_filter_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (Unit* caster = GetCaster())
            {
                /*for (std::list<WorldObject*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    if (caster->GetAI()->GetObjectData((*itr)->GetGUID()))
                        targets.remove(*itr++);*/
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xavius_nightmare_blades_dmg_filter_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xavius_nightmare_blades_dmg_filter_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_xavius_nightmare_blades_dmg_filter_SpellScript();
    }
};

// 210451 - Bonds of Terror
class spell_xavius_bonds_of_terror : public SpellScriptLoader
{
public:
    spell_xavius_bonds_of_terror() : SpellScriptLoader("spell_xavius_bonds_of_terror") { }

    class spell_xavius_bonds_of_terror_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_xavius_bonds_of_terror_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (GetCaster() && GetCaster()->HasAura(SPELL_BONDS_OF_TERROR_AURA))
                GetCaster()->RemoveAurasDueToSpell(SPELL_BONDS_OF_TERROR_AURA);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_xavius_bonds_of_terror_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_xavius_bonds_of_terror_AuraScript();
    }
};

// 226194 - Writhing Deep
class spell_xavius_writhing_deep : public SpellScriptLoader
{
public:
    spell_xavius_writhing_deep() : SpellScriptLoader("spell_xavius_writhing_deep") { }

    class spell_xavius_writhing_deep_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_xavius_writhing_deep_SpellScript);

        void HandleScript(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);

            if (Unit* caster = GetCaster())
            {
                Position pos;
                caster->GetNearPosition(frand(15.0f, 25.0f), (urand(0, 6)));
                uint32 spellId = GetSpellInfo()->GetEffect(effIndex)->TriggerSpell;
                uint32 delay = GetSpellInfo()->GetEffect(effIndex)->MiscValue;
               // caster->m_Events.AddEvent(new DelayDestCastEvent(*caster, pos, spellId, true), caster->m_Events.CalculateTime(delay));
            }
        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_xavius_writhing_deep_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectLaunch += SpellEffectFn(spell_xavius_writhing_deep_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectLaunch += SpellEffectFn(spell_xavius_writhing_deep_SpellScript::HandleScript, EFFECT_2, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectLaunch += SpellEffectFn(spell_xavius_writhing_deep_SpellScript::HandleScript, EFFECT_3, SPELL_EFFECT_TRIGGER_SPELL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_xavius_writhing_deep_SpellScript();
    }
};

// 207830 - Corrupting Nova
class spell_xavius_corrupting_nova : public SpellScriptLoader
{
public:
    spell_xavius_corrupting_nova() : SpellScriptLoader("spell_xavius_corrupting_nova") { }

    class spell_xavius_corrupting_nova_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_xavius_corrupting_nova_SpellScript);

        void HandleScriptEffect(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(EFFECT_1);

            if (Unit* target = GetHitUnit())
                if (target->HasAura(SPELL_NIGHTMARE_TORMENT_ALT_POWER))
                {
                    uint32 power = target->GetPower(POWER_ALTERNATE_POWER);
                    target->SetPower(POWER_ALTERNATE_POWER, power + 5);
                }
        }

        void Register() override
        {
            OnEffectLaunchTarget += SpellEffectFn(spell_xavius_corrupting_nova_SpellScript::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_xavius_corrupting_nova_SpellScript();
    }
};

// 206369 - Corruption Meteor
// 207849 - Corruption Meteor
class spell_xavius_corruption_meteor : public SpellScriptLoader
{
public:
    spell_xavius_corruption_meteor() : SpellScriptLoader("spell_xavius_corruption_meteor") {}

    class spell_xavius_corruption_meteor_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_xavius_corruption_meteor_SpellScript);

        uint8 targetCount = 0;

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.size() > 1)
                targetCount = targets.size();
        }

        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster() || !GetHitUnit() || targetCount == 0)
                return;

            SetHitDamage(GetHitDamage() / targetCount);
        }

        void HandleEnergy(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster() || !GetHitUnit() || targetCount == 0)
                return;

            SetEffectValue(GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints / targetCount);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xavius_corruption_meteor_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_xavius_corruption_meteor_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            OnEffectHitTarget += SpellEffectFn(spell_xavius_corruption_meteor_SpellScript::HandleEnergy, EFFECT_0, SPELL_EFFECT_ENERGIZE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_xavius_corruption_meteor_SpellScript();
    }
};

// 208593 - Teleport: Xavius Boss
class teleport_xavius : public CreatureScript
{
public:
    teleport_xavius() : CreatureScript("teleport_xavius") { }

    struct teleport_xaviusAI : public ScriptedAI
    {
        teleport_xaviusAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (who->GetDistance2d(me) < 5.0f)
                {
                    if (!player->HasAura(223216))
                    {
                        player->CastSpell(player, 223216, true);
                        player->CastSpell(player, 223237);
                    }
                    else
                        player->CastSpell(player, 225949);
                }
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new teleport_xaviusAI(creature);
    }
};

// 223216 - Teleport to Rift
class spell_teleport_to_rift : public SpellScriptLoader
{
public:
    spell_teleport_to_rift() : SpellScriptLoader("spell_teleport_to_rift") { }

    class spell_teleport_to_rift_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_teleport_to_rift_AuraScript);

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (!GetTarget())
                return;

            if (GetTarget()->GetTypeId() == TYPEID_PLAYER)
            {
                GetTarget()->GetMotionMaster()->MovePath(9370973, false);
                GetTarget()->ToPlayer()->SetClientControl(GetTarget(), 0);
                GetTarget()->ToPlayer()->SetCanFly(true);
            }
        }

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (GetTarget())
                if (GetTarget()->GetTypeId() == TYPEID_PLAYER)
                {
                    GetTarget()->ToPlayer()->SetClientControl(GetTarget(), 1);
                    GetTarget()->ToPlayer()->SetCanFly(false);
                }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_teleport_to_rift_AuraScript::OnApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_teleport_to_rift_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_teleport_to_rift_AuraScript();
    }
};

void AddSC_xavius()
{
    new boss_xavius();
    new npc_xavius_sleeping_version();
    new npc_xavius_dread_abomination();
    new npc_xavius_lurking_terror();
    new npc_xavius_corruption_horror();
    new npc_xavius_nightmare_blades();
    new npc_xavius_inconceivable_horror();
    new npc_xavius_nightmare_tentacle();
    new spell_teleport_to_rift();
    new spell_xavius_periodic_energize();
    new spell_xavius_dream_simulacrum();
    new spell_xavius_nightmare_torment_alt_power();
    new spell_xavius_crushing_shadows();
    new spell_xavius_unfathomable_reality();
    new spell_xavius_descent_into_madness();
    new spell_xavius_darkening_soul();
    new spell_xavius_nightmare_blades();
    new spell_xavius_nightmare_blades_dmg_filter();
    new spell_xavius_bonds_of_terror();
    new spell_xavius_writhing_deep();
    new spell_xavius_corrupting_nova();
    new spell_xavius_corruption_meteor();

    new teleport_xavius();
    new npc_xavius_event_conroller();
}
