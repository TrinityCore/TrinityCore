#include "SpellAuraEffects.h"
#include "SpellAuraDefines.h"
#include "throne_of_thunder.h"

enum Spells
{
    SPELL_CRITICALLY_DAMAGED = 138400,
    SPELL_EVASIVE = 140759,
    SPELL_ACCELERATION_LINK = 138453,

    SPELL_CRIMSON_WAKE_DAMAGE = 138485,
    SPELL_CRIMSON_WAKE_SUMMON = 138480,
    SPELL_CRIMSON_WAKE_FAST = 138544,
    SPELL_CIRMSON_WAKE_SLOW = 138482,
    SPELL_CRIMSON_WAKE_MEDIUM = 138484,
    SPELL_CRIMSON_WAKE_FIXATE = 138486, 

    SPELL_MATTER_SWAP_DAMAGE = 138618,
    SPELL_MATTER_SWAP_CAST = 138609,
    SPELL_TARGET_OF_SWAP = 139919,

    SPELL_EXPLOSIVE_SLAM = 138569,

    SPELL_ACTIVATION_SEQUENCE = 139537,

    SPELL_FULL_POWER_CAST = 138729,
    SPELL_FULL_POWER_MISSILE = 138749,

    SPELL_INTERRUPTING_JOLT = 138763,

    SPELL_ANIMA_FONT_MISSILE = 138697,
    SPELL_ANIMA_FONT = 138691,

    SPELL_TOUCH_OF_THE_ANIMUS = 138659,

    SPELL_EMPOWER_GOLEM = 138780,

    SPELL_SIPHON_ANIMA = 138644,

    SPELL_ANIMA_RING_DEBUFF = 136962,
    SPELL_ANIMA_RING = 136954,

    SPELL_CAP_100 = 138387,
    SPELL_CAP_36 = 138386,
    SPELL_CAP_8 = 138385,
    SPELL_CAP_4 = 138384,
    SPELL_POWERED_DOWN = 138373, //shared spell
};

enum Creatures
{
    NPC_BOSS_DARK_ANIMUS = 69427,
    NPC_MASSIVE_ANIMA_GOLEM = 69699,
    NPC_LARGE_ANIMA_GOLEM = 69700,
    NPC_ANIMA_GOLEM = 69701,
    NPC_ANIMA_ORB = 69756,
    NPC_CRIMSON_WAKE = 69951,
    NPC_ANIMA_RINGS_HANDLER = 999286,
    NPC_ANIMA_RINGS = 999287,
};

enum Events
{
    EVENT_CHECK_ACCELERATION = 1,
    EVENT_CRIMSON_WAKE,
    EVENT_EXPLOSIVE_SLAM,
    EVENT_FULL_POWER,
    EVENT_SELECTION_TARGET,
    EVENT_SUMMON_ANIMA,
    EVENT_MOVE_TO_TARGET,
    EVENT_UNAURA_AND_AURA,
    EVENT_ADD_AURA_BACK,
    EVENT_SUMMON_RINGS_ANIMA,
    EVENT_MATTER_SWAP,
    EVENT_CHECK_ENERGY_FOR_ANIMA_RING,
    EVENT_CHECK_ENERGY_FOR_INTERRUPTING_JOLT,
    EVENT_CHECK_ENERGY_FOR_FULL_POWER,
    EVENT_EMPOWER_GOLEM,
    EVENT_ANIMA_RING,
    EVENT_ANIMA_FONT,
    EVENT_INTERRUPTING_JOLT,
    EVENT_TOUCH_OF_THE_ANIMUS,
    EVENT_SIPHON_ANIMA,
    EVENT_CHECK_ENERGY_FOR_ANIMA_FONT,
    EVENT_CHECK_ENERGY,
    EVENT_ADD_ROOT_TO_ME_AND_ADDS,
    EVENT_ADD_LINK_AURA,
    EVENT_RESET_FORCED,
    EVENT_ADD_ENERGY_TEST, // not usable in script, testing stuff
};

enum Actions
{
    ACTION_INITIALIZE_RING_TO_WORLD = 1,
    ACTION_ACTIVATE = 2,
    ACTION_TRANSFER_ANIMA = 3,
    ACTION_ACCEPT_ANIMA = 4,
    ACTION_SET_AT_ACTIVE = 5,
    ACTION_FULL_POWER = 6,
    ACTION_CHEATERS = 7,
};

struct isInIdle : public std::unary_function<Unit*, bool>
{
    isInIdle() {}

    bool operator() (const Unit* pTarget)
    {
        return pTarget->HasUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
    }
};


struct IsActivating : public std::unary_function<Unit**, bool>
{
    IsActivating() {}

    bool operator() (const Unit* target)
    {
        return target->HasAura(139537);
    }
};

struct IsDead : public std::unary_function<Unit*, bool>
{
    IsDead() {}

    bool operator() (const Unit* target)
    {
        return target->isDead();
    }
};


struct IsFullPower : public std::unary_function<Unit*, bool>
{
    IsFullPower() {}

    bool operator() (const Unit* target)
    {
        return target->GetPower(POWER_ENERGY) == target->GetMaxPower(POWER_ENERGY);
    }
};

class bfa_npc_anima_golem : public CreatureScript
{
public:
    bfa_npc_anima_golem() : CreatureScript("bfa_npc_anima_golem") { }

    struct bfa_npc_anima_golemAI : public ScriptedAI
    {
        bfa_npc_anima_golemAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_POWERED_DOWN, me);
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 4);
            me->ApplySpellImmune(0, IMMUNITY_ID, 73680, true); // unleash elements exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 51690, true); // killing spree exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 122057, true); // Clash exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 126449, true); // clash exploits   
            me->ApplySpellImmune(0, IMMUNITY_ID, 115546, true); // provoke exploits
        }

        EventMap events;

        void Reset()
        {
            me->SetHealth(me->GetMaxHealth());
            events.Reset();
            me->SetPower(POWER_ENERGY, 4);
        }

        void EnterCombat(Unit*)
        {
            //me->AddAura(138451, me);
            //SCHEDULE_EVENT(EVENT_CHECK_ACCELERATION, 1000);
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 4);
            me->SetPower(POWER_ENERGY, 4);
            me->AddAura(SPELL_EVASIVE, me);
            events.ScheduleEvent(EVENT_ADD_LINK_AURA, 5000);

            if (Creature* animus = me->FindNearestCreature(NPC_BOSS_DARK_ANIMUS, 500.0f, true))
            {
                if (!animus->IsInCombat() && !animus->HasAura(SPELL_POWERED_DOWN))
                    animus->AI()->DoAction(ACTION_CHEATERS);
            }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_ACTIVATE:
            {
                me->RemoveAura(SPELL_POWERED_DOWN);
                me->SetInCombatWithZone();
                break;
            }
            }
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (damage >= me->GetHealth())
            {
                AnimaHandler();
            }
        }

        void AnimaHandler()
        {
            Creature* newUser = NULL;
            bool golemFound = false;
            std::list<Creature*> animaUsers;
            me->GetCreatureListWithEntryInGrid(animaUsers, NPC_MASSIVE_ANIMA_GOLEM, 200.0f);
            me->GetCreatureListWithEntryInGrid(animaUsers, NPC_LARGE_ANIMA_GOLEM, 200.0f);
            me->GetCreatureListWithEntryInGrid(animaUsers, BOSS_DARK_ANIMUS, 200.0f);

            animaUsers.remove_if(isInIdle());
            animaUsers.remove_if(IsActivating());
            animaUsers.remove_if(IsFullPower());

            if (!animaUsers.empty())
            {
                animaUsers.sort(Trinity::ObjectDistanceOrderPred(me, true));
                newUser = *animaUsers.begin();
                golemFound = true;
            }

            if (golemFound)
            {
                uint32 myEnergy = me->GetPower(POWER_ENERGY);

                if (me->GetPower(POWER_ENERGY) >= 0)
                {
                    newUser->SetPower(POWER_ENERGY, newUser->GetPower(POWER_ENERGY) + myEnergy);

                    switch (newUser->GetEntry())
                    {
                    case BOSS_DARK_ANIMUS:
                        newUser->RemoveAura(SPELL_POWERED_DOWN);
                        newUser->AI()->DoAction(ACTION_ACTIVATE);
                        break;
                    case NPC_MASSIVE_ANIMA_GOLEM:
                        newUser->RemoveAura(SPELL_POWERED_DOWN);
                        newUser->SetInCombatWithZone();
                        break;
                    }
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->GetPower(POWER_ENERGY) == 0)
                me->Kill(me);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ADD_LINK_AURA:
                    me->AddAura(138451, me);
                    break;
                case EVENT_CHECK_ACCELERATION:
                {
                    std::list<Creature*> cList;
                    me->GetCreatureListWithEntryInGrid(cList, NPC_ANIMA_GOLEM, 5.0f);
                    if (!cList.empty())
                        for (std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                        {
                            // Don't count self
                            if ((*itr) == me)
                                continue;
                            if (me->HasAura(SPELL_CRITICALLY_DAMAGED) || (*itr)->HasAura(SPELL_CRITICALLY_DAMAGED) || (*itr)->isDead()) // don't count critically damaged
                                continue;

                            if (me->GetDistance((*itr)) < 2.0f)
                            {
                                me->AddAura(SPELL_ACCELERATION_LINK, me);
                                (*itr)->AddAura(SPELL_ACCELERATION_LINK, (*itr));
                            }
                            else if (me->GetDistance((*itr)) > 2.0f)
                            {
                                me->RemoveAura(SPELL_ACCELERATION_LINK);
                                (*itr)->RemoveAura(SPELL_ACCELERATION_LINK);
                            }
                        }
                    events.ScheduleEvent(EVENT_CHECK_ACCELERATION, 1500);
                    break;
                }
                }
            }
            if (!me->HasAura(SPELL_CRITICALLY_DAMAGED))
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_anima_golemAI(creature);
    }
};

class bfa_npc_large_anima_golem : public CreatureScript
{
public:
    bfa_npc_large_anima_golem() : CreatureScript("bfa_npc_large_anima_golem") { }

    struct bfa_npc_large_anima_golemAI : public ScriptedAI
    {
        bfa_npc_large_anima_golemAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_POWERED_DOWN, me);
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 8);
            me->SetPower(POWER_ENERGY, 0);
            me->ApplySpellImmune(0, IMMUNITY_ID, 73680, true); // unleash elements exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 51690, true); // killing spree exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 122057, true); // Clash exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 126449, true); // clash exploits  
            me->ApplySpellImmune(0, IMMUNITY_ID, 115546, true); // provoke exploits
        }

        EventMap events;

        void Reset()
        {
            me->SetHealth(me->GetMaxHealth());
            events.Reset();
            me->SetPower(POWER_ENERGY, 0);
            events.ScheduleEvent(EVENT_CHECK_ENERGY, 1000);
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_CRIMSON_WAKE, 10000);
            events.ScheduleEvent(EVENT_CHECK_ENERGY, 1000);

            if (Creature* animus = me->FindNearestCreature(NPC_BOSS_DARK_ANIMUS, 500.0f, true))
            {
                if (!animus->IsInCombat() && !animus->HasAura(SPELL_POWERED_DOWN))
                    animus->AI()->DoAction(ACTION_CHEATERS);
            }
        }


        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (damage >= me->GetHealth())
            {
                AnimaHandler();
            }
        }

        void AnimaHandler()
        {
            Creature* newUser = NULL;
            bool golemFound = false;
            std::list<Creature*> animaUsers;
            me->GetCreatureListWithEntryInGrid(animaUsers, NPC_MASSIVE_ANIMA_GOLEM, 200.0f);
            me->GetCreatureListWithEntryInGrid(animaUsers, BOSS_DARK_ANIMUS, 200.0f);

            animaUsers.remove_if(IsActivating());
            animaUsers.remove_if(IsDead()); // just to be sure it doesn't add energy on dead golems, meh.
            animaUsers.remove_if(IsFullPower());

            if (!animaUsers.empty())
            {
                animaUsers.sort(Trinity::ObjectDistanceOrderPred(me, true));
                newUser = *animaUsers.begin();
                golemFound = true;
            }

            if (golemFound)
            {
                uint32 myEnergy = me->GetPower(POWER_ENERGY);

                if (me->GetPower(POWER_ENERGY) >= 0)
                {
                    newUser->SetPower(POWER_ENERGY, newUser->GetPower(POWER_ENERGY) + myEnergy);
                    newUser->RemoveAura(SPELL_POWERED_DOWN);
                    newUser->AI()->DoAction(ACTION_ACTIVATE);
                }
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
                case EVENT_CRIMSON_WAKE:
                    if (!me->HasAura(SPELL_POWERED_DOWN))
                        me->CastSpell(me, SPELL_CRIMSON_WAKE_SUMMON);
                    events.ScheduleEvent(EVENT_CRIMSON_WAKE, 15000);
                    break;
                case EVENT_CHECK_ENERGY:
                    if (me->GetPower(POWER_ENERGY) == 8)
                    {
                        me->SetInCombatWithZone();
                        me->RemoveAura(SPELL_POWERED_DOWN);
                    }
                    events.ScheduleEvent(EVENT_CHECK_ENERGY, 1000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_large_anima_golemAI(creature);
    }
};

class bfa_npc_crimson_wake : public CreatureScript
{
public:
    bfa_npc_crimson_wake() : CreatureScript("bfa_npc_crimson_wake") { }

    struct bfa_npc_crimson_wakeAI : public ScriptedAI
    {
        bfa_npc_crimson_wakeAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
        }

        EventMap events;
        uint64 playerGuid;

        void IsSummonedBy(Unit* summoner)
        {
            me->AddAura(SPELL_CIRMSON_WAKE_SLOW, me);
            me->DespawnOrUnsummon(30000);
            events.ScheduleEvent(EVENT_SELECTION_TARGET, 2000);
        }

        void Reset()
        {
            events.Reset();
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
                case EVENT_SELECTION_TARGET:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    {
                        me->AddAura(SPELL_CRIMSON_WAKE_FIXATE, (*itr));
                        me->AddThreat((*itr), 9999999999.9f);
                        me->AI()->AttackStart((*itr));
                    }
                    me->DespawnOrUnsummon(30000);
                    break;
                }
                }
            }
        }

        void DespawnOrUnsummon()
        {
            if (Unit* player = me->GetVictim())
            {
                player->RemoveAura(SPELL_CRIMSON_WAKE_FIXATE);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_crimson_wakeAI(creature);
    }
};

struct isTank : public std::unary_function<Unit*, bool>
{
    isTank() {}

    bool operator() (const Unit* pTarget)
    {
        Player* player = const_cast<Player*>(pTarget->ToPlayer());
        uint32 specialization = player->GetSpecializationId();
        return ((player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_BEAR)
            || (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_PROTECTION)
            || (player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_PROTECTION)
            || (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_BLOOD));
    }
};

struct isSwapped : public std::unary_function<Unit*, bool>
{
    isSwapped() {}

    bool operator() (const Unit* pTarget)
    {
        return pTarget->HasAura(SPELL_MATTER_SWAP_CAST);
    }
};

struct isSwapTarget : public std::unary_function<Unit*, bool>
{
    isSwapTarget() {}

    bool operator() (const Unit* pTarget)
    {
        return pTarget->HasAura(SPELL_TARGET_OF_SWAP);
    }
};

class bfa_npc_massive_anima_golem : public CreatureScript
{
public:
    bfa_npc_massive_anima_golem() : CreatureScript("bfa_npc_massive_anima_golem") { }

    struct bfa_npc_massive_anima_golemAI : public ScriptedAI
    {
        bfa_npc_massive_anima_golemAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_POWERED_DOWN, me);
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 36);
            me->SetPower(POWER_ENERGY, 0);
            me->ApplySpellImmune(0, IMMUNITY_ID, 73680, true); // unleash elements exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 51690, true); // killing spree exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 122057, true); // Clash exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 115546, true); // provoke exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 126449, true); // clash exploits   
        }

        EventMap events;

        void Reset()
        {
            me->SetHealth(me->GetMaxHealth());
            events.Reset();
            me->SetPower(POWER_ENERGY, 0);
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_EXPLOSIVE_SLAM, 5000);
            events.ScheduleEvent(EVENT_MATTER_SWAP, urand(2000, 7000));

            if (Creature* animus = me->FindNearestCreature(NPC_BOSS_DARK_ANIMUS, 500.0f, true))
            {
                if (!animus->IsInCombat() && !animus->HasAura(SPELL_POWERED_DOWN))
                    animus->AI()->DoAction(ACTION_CHEATERS);
            }
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (damage >= me->GetHealth())
            {
                AnimaHandler();
            }
        }

        void AnimaHandler()
        {
            Creature* newUser = NULL;
            bool golemFound = false;
            std::list<Creature*> animaUsers;
            me->GetCreatureListWithEntryInGrid(animaUsers, BOSS_DARK_ANIMUS, 200.0f);

            animaUsers.remove_if(IsActivating());

            if (!animaUsers.empty())
            {
                animaUsers.sort(Trinity::ObjectDistanceOrderPred(me, true));
                newUser = *animaUsers.begin();
                golemFound = true;
            }

            if (golemFound)
            {
                uint32 myEnergy = me->GetPower(POWER_ENERGY);

                if (me->GetPower(POWER_ENERGY) >= 0)
                {
                    newUser->SetPower(POWER_ENERGY, newUser->GetPower(POWER_ENERGY) + myEnergy);
                    newUser->RemoveAura(SPELL_POWERED_DOWN);
                    newUser->AI()->DoAction(ACTION_ACTIVATE);
                }
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
                case EVENT_EXPLOSIVE_SLAM:
                    me->CastSpell(me->GetVictim(), SPELL_EXPLOSIVE_SLAM);
                    events.ScheduleEvent(EVENT_EXPLOSIVE_SLAM, 15000);
                    break;
                case EVENT_MATTER_SWAP:
                {
                    std::list<Player*> PlayerList;
                    GetPlayerListInGrid(PlayerList, me, 100.0f);

                    PlayerList.remove_if(isTank());
                    PlayerList.remove_if(isSwapped());
                    PlayerList.remove_if(isSwapTarget());

                    if (!PlayerList.empty())
                        if (PlayerList.size() > 1)
                            Trinity::Containers::RandomResize(PlayerList, 1);
                    for (auto player : PlayerList)
                    {
                        me->CastSpell(player, SPELL_MATTER_SWAP_CAST);
                    }
                    //if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250.0f, true))
                    //    me->CastSpell(target, SPELL_MATTER_SWAP_CAST);
                    events.ScheduleEvent(EVENT_MATTER_SWAP, urand(20000, 35000));
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_massive_anima_golemAI(creature);
    }
};

struct hasTouchAura : public std::unary_function<Unit*, bool>
{
    hasTouchAura() {}

    bool operator() (const Unit* pTarget)
    {
        return !pTarget->HasAura(SPELL_TOUCH_OF_THE_ANIMUS);
    }
};

struct dontHaveTouchAura : public std::unary_function<Unit*, bool>
{
    dontHaveTouchAura() {}

    bool operator() (const Unit* target)
    {
        return target && !target->HasAura(SPELL_TOUCH_OF_THE_ANIMUS);
    }
};

struct isDisable : public std::unary_function<Unit*, bool>
{
    isDisable() {}

    bool operator() (const Unit* pTarget)
    {
        return pTarget->HasAura(SPELL_POWERED_DOWN);
    }
};

struct isDamaged : public std::unary_function<Unit*, bool>
{
    isDamaged() {}

    bool operator() (const Unit* pTarget)
    {
        return pTarget->HasAura(SPELL_CRITICALLY_DAMAGED);
    }
};

class bfa_boss_dark_animus : public CreatureScript
{
public:
    bfa_boss_dark_animus() : CreatureScript("bfa_boss_dark_animus") { }

    struct bfa_boss_dark_animusAI : public ScriptedAI
    {
        bfa_boss_dark_animusAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_POWERED_DOWN, me);
            me->ApplySpellImmune(0, IMMUNITY_ID, 73680, true); // unleash elements exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 51690, true); // killing spree exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 122057, true); // Clash exploits
            me->ApplySpellImmune(0, IMMUNITY_ID, 126449, true); // clash exploits   
            instance = creature->GetInstanceScript();
        }

        EventMap events;
        bool alreadyActive;
        InstanceScript* instance;

        void Reset()
        {
            alreadyActive = false;
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->SetHealth(me->GetMaxHealth());
            events.Reset();
            me->SetPower(POWER_ENERGY, 0);
            RemoveTouchOfAnimus();
            if (Creature* orb = me->FindNearestCreature(NPC_ANIMA_ORB, 500.0f, false))
                orb->Respawn();
            if (Creature* atorb = me->FindNearestCreature(NPC_AREATRIGGER_ANIMA, 500.0f, false))
                atorb->Respawn();

            if (instance)
                instance->SetBossState(DATA_DARK_ANIMUS, NOT_STARTED);
        }

        void TeleportPlayers()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->NearTeleportTo(5622.65f, 4805.53f, 82.90f, 0.0f, false);
                    player->Kill(player, false);
                }
        }

        void CheckPrimaryTarget()
        {
            Unit* myTarget = me->GetVictim();
            if (!myTarget)
                return;
            if (me->IsInCombat())
            {
                if (myTarget->IsPet() || myTarget->IsGuardian())
                    me->Kill(myTarget);
            }
        }

        Creature* GetAnimaOrb()
        {
            return me->FindNearestCreature(NPC_ANIMA_ORB, 400.0f, true);
        }

        void EnterCombat(Unit*)
        {
            if (Creature* animaOrb = GetAnimaOrb())
            {
                if (animaOrb->IsAlive() || animaOrb->HasAura(9454))
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            if (player->IsAlive())
                                player->Kill(player);
                    return;
                }
            }

            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            //me->SetPower(POWER_ENERGY, 0); // in case it fails
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            if (me->GetMap()->IsHeroic())
                me->SetPower(POWER_ENERGY, 52);
            if (instance)
                instance->SetBossState(DATA_DARK_ANIMUS, IN_PROGRESS);;
        }

        void RemoveTouchOfAnimus()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->HasAura(SPELL_TOUCH_OF_THE_ANIMUS))
                        player->RemoveAura(SPELL_TOUCH_OF_THE_ANIMUS);
                }
        }

        void DespawnCreature(uint32 entry)
        {
            std::list<Creature*> creatureList;
            GetCreatureListWithEntryInGrid(creatureList, me, entry, 500.0f);
            for (auto NowCreature : creatureList)
                NowCreature->DespawnOrUnsummon();
        }

        void RemoveAdds()
        {
            DespawnCreature(NPC_ANIMA_GOLEM);
            DespawnCreature(NPC_LARGE_ANIMA_GOLEM);
            DespawnCreature(NPC_MASSIVE_ANIMA_GOLEM);
        }

        void EnterEvadeMode(EvadeReason w)
        {
            float x, y, z, o;
            events.ScheduleEvent(EVENT_ADD_ROOT_TO_ME_AND_ADDS, 7000);
            me->GetHomePosition(x, y, z, o);
            me->GetMotionMaster()->Clear(false);
            me->GetMotionMaster()->MovePoint(5000, x, y, z);
            me->NearTeleportTo(x, y, z, 0, false);
            TeleportPlayers();
            if (instance)
                instance->SetBossState(DATA_DARK_ANIMUS, FAIL);
            ScriptedAI::EnterEvadeMode();
        }

        void JustDied(Unit*)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            RemoveAdds();
            RemoveTouchOfAnimus();
            if (instance)
                instance->SetBossState(DATA_DARK_ANIMUS, DONE);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_ACTIVATE:
            {
                if (alreadyActive)
                    return;
                alreadyActive = true;
                me->RemoveAura(SPELL_POWERED_DOWN);
                me->SetInCombatWithZone();
                if (me->GetMap()->IsHeroic())
                {
                    events.ScheduleEvent(EVENT_SIPHON_ANIMA, 2 * MINUTE * IN_MILLISECONDS);
                }
                else
                    events.ScheduleEvent(EVENT_SIPHON_ANIMA, 6000);

                events.ScheduleEvent(EVENT_TOUCH_OF_THE_ANIMUS, 8000);
                events.ScheduleEvent(EVENT_CHECK_ENERGY_FOR_ANIMA_FONT, 1000);
                events.ScheduleEvent(EVENT_CHECK_ENERGY_FOR_ANIMA_RING, 1200);
                events.ScheduleEvent(EVENT_CHECK_ENERGY_FOR_FULL_POWER, 3000);
                events.ScheduleEvent(EVENT_CHECK_ENERGY_FOR_INTERRUPTING_JOLT, 3500);
                if (me->GetMap()->IsHeroic())
                    events.ScheduleEvent(EVENT_EMPOWER_GOLEM, 15000);
                break;
            }
            case ACTION_ACCEPT_ANIMA:
                //me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 1);
                break;
            case ACTION_CHEATERS:
            {
                Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* player = i->GetSource())
                        if (player->IsAlive())
                        {
                            player->Kill(player, true);
                            player->NearTeleportTo(5622.65f, 4805.53f, 82.90f, 0.0f, false);
                        }
                break;
            }
            }
        }

        void GolemsAnima()
        {
            std::list<Creature*> anima;
            GetCreatureListWithEntryInGrid(anima, me, NPC_ANIMA_GOLEM, 1000.f);

            for (Creature* golem : anima)
            {
                if (golem->HasAura(SPELL_POWERED_DOWN))
                    continue;
                golem->AI()->DoAction(ACTION_TRANSFER_ANIMA);
            }
        }

        void EmpowerGolem()
        {
            std::list<Creature*> GolemList;
            me->GetCreatureListWithEntryInGrid(GolemList, NPC_ANIMA_GOLEM, 500.f);
            me->GetCreatureListWithEntryInGrid(GolemList, NPC_LARGE_ANIMA_GOLEM, 500.0f);
            me->GetCreatureListWithEntryInGrid(GolemList, NPC_MASSIVE_ANIMA_GOLEM, 500.0f);

            GolemList.remove_if(isDisable());
            GolemList.remove_if(isDamaged());

            uint32 healthPoints = 100;
            if (!GolemList.empty())
                for (std::list<Creature*>::iterator itr = GolemList.begin(); itr != GolemList.end(); ++itr)
                    if (Creature* oneGolem = (*itr)->ToCreature())
                    {
                        if (oneGolem->GetHealthPct() < healthPoints)
                        {
                            healthPoints = oneGolem->GetHealthPct();
                            me->AddAura(SPELL_EMPOWER_GOLEM, oneGolem);
                        }
                    }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            CheckPrimaryTarget();

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SIPHON_ANIMA:
                {
                    me->CastSpell(me, SPELL_SIPHON_ANIMA);
                    GolemsAnima();
                    std::ostringstream str;
                    str << "Dark Animus drains power from the other golems with |cFFF00000|Hspell:138644|h[Siphon Anima]|h|r !";
                    me->TextEmote(str.str().c_str(), 0, true);
                    if (me->GetMap()->IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_SIPHON_ANIMA, 20 * IN_MILLISECONDS);
                    }
                    else
                    {
                        events.ScheduleEvent(EVENT_SIPHON_ANIMA, 8000);
                    }
                    break;
                }
                case EVENT_CHECK_ENERGY_FOR_ANIMA_RING:
                {
                    if (me->GetPower(POWER_ENERGY) >= 25)
                    {
                        events.ScheduleEvent(EVENT_ANIMA_RING, 5000);
                        events.CancelEvent(EVENT_CHECK_ENERGY_FOR_ANIMA_RING);
                        break;
                    }
                    else
                    {
                        events.ScheduleEvent(EVENT_CHECK_ENERGY_FOR_ANIMA_RING, 1000);
                    }
                    break;
                }
                case EVENT_CHECK_ENERGY_FOR_ANIMA_FONT:
                {
                    if (me->GetPower(POWER_ENERGY) >= 50)
                    {
                        events.ScheduleEvent(EVENT_ANIMA_FONT, 2000);
                        events.CancelEvent(EVENT_CHECK_ENERGY_FOR_ANIMA_FONT);
                        break;
                    }
                    else
                    {
                        events.ScheduleEvent(EVENT_CHECK_ENERGY_FOR_ANIMA_FONT, 2500);
                    }
                    break;
                }
                case EVENT_CHECK_ENERGY_FOR_INTERRUPTING_JOLT:
                {
                    if (me->GetPower(POWER_ENERGY) >= 75)
                    {
                        events.ScheduleEvent(EVENT_INTERRUPTING_JOLT, 5000);
                        events.CancelEvent(EVENT_CHECK_ENERGY_FOR_INTERRUPTING_JOLT);
                        break;
                    }
                    else
                    {
                        events.ScheduleEvent(EVENT_CHECK_ENERGY_FOR_INTERRUPTING_JOLT, 1500);
                    }
                    break;
                }
                case EVENT_CHECK_ENERGY_FOR_FULL_POWER:
                {
                    events.ScheduleEvent(EVENT_CHECK_ENERGY_FOR_FULL_POWER, 2000);
                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        break;
                    if (me->GetPower(POWER_ENERGY) == 100)
                        me->CastSpell(me, SPELL_FULL_POWER_CAST, true);
                    break;
                }
                case EVENT_EMPOWER_GOLEM:
                    EmpowerGolem();
                    events.ScheduleEvent(EVENT_EMPOWER_GOLEM, 15000);
                    break;
                case EVENT_ANIMA_RING:
                    if (Unit* victim = me->GetVictim())
                        me->CastSpell(victim, SPELL_ANIMA_RING);
                    if (Unit* victim = me->GetVictim())
                        me->SummonCreature(NPC_ANIMA_RINGS_HANDLER, victim->GetPositionX(), victim->GetPositionY(), victim->GetPositionZ(), victim->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 20000);
                    events.ScheduleEvent(EVENT_ANIMA_RING, 30000);
                    break;
                case EVENT_ANIMA_FONT:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);

                    targets.remove_if(hasTouchAura());

                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        me->CastSpell((*itr), SPELL_ANIMA_FONT);

                    events.ScheduleEvent(EVENT_ANIMA_FONT, 30000);
                    break;
                }
                case EVENT_INTERRUPTING_JOLT:
                {
                    me->CastSpell(me, SPELL_INTERRUPTING_JOLT);
                    std::ostringstream str;
                    str << "Stop casting! Dark Animus is generating an |cFFF00000|Hspell:138763|h[Interrupting Jolt]|h|r !";
                    me->TextEmote(str.str().c_str(), 0, true);
                    events.ScheduleEvent(EVENT_INTERRUPTING_JOLT, 22000);
                    break;
                }
                case EVENT_TOUCH_OF_THE_ANIMUS:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        me->CastSpell((*itr), SPELL_TOUCH_OF_THE_ANIMUS);

                    events.ScheduleEvent(EVENT_TOUCH_OF_THE_ANIMUS, 15000);
                    break;
                }
                case EVENT_ADD_ROOT_TO_ME_AND_ADDS:
                    me->AddAura(SPELL_POWERED_DOWN, me);
                    PowerDownGolems(SPELL_POWERED_DOWN, NPC_ANIMA_GOLEM);
                    PowerDownGolems(SPELL_POWERED_DOWN, NPC_MASSIVE_ANIMA_GOLEM);
                    PowerDownGolems(SPELL_POWERED_DOWN, NPC_LARGE_ANIMA_GOLEM);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void PowerDownGolems(uint32 spellId, uint32 entry)
        {
            std::list<Creature*> summonsList;
            GetCreatureListWithEntryInGrid(summonsList, me, entry, 200.0f);
            if (!summonsList.empty())
                for (std::list<Creature*>::iterator summs = summonsList.begin(); summs != summonsList.end(); summs++)
                    if ((*summs)->IsAlive())
                        (*summs)->AddAura(spellId, *summs);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_boss_dark_animusAI(creature);
    }
};

struct hasRingAura : public std::unary_function<Unit*, bool>
{
    hasRingAura() {}

    bool operator() (const Unit* pTarget)
    {
        return pTarget->HasAura(138978);
    }
};

// HANDLER SCRIPT
class bfa_npc_anima_rings : public CreatureScript
{
public:
    bfa_npc_anima_rings() : CreatureScript("bfa_npc_anima_rings") { }

    struct bfa_npc_anima_ringsAI : public ScriptedAI
    {
        bfa_npc_anima_ringsAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        EventMap events;
        float _x;
        float _y;
        float point;

        void Reset()
        {
            events.Reset();
            me->AddUnitState(UNIT_STATE_ROOT);
            point = 0;
            _x = me->GetPositionX();
            _y = me->GetPositionY();
        }

        void EnterCombat(Unit* unit)
        {
            events.RescheduleEvent(EVENT_SUMMON_ANIMA, 3000);
            me->DespawnOrUnsummon(20000);
        }

        void JustSummoned(Creature* summoned)
        {
            summoned->CastSpell(summoned, 138674, true);
        }

        void ReturnRings()
        {
            std::list<Creature*> rings;
            me->GetCreatureListWithEntryInGrid(rings, NPC_ANIMA_RINGS, 200.0f);

            for (auto oneRing : rings)
            {
                oneRing->AI()->DoAction(ACTION_INITIALIZE_RING_TO_WORLD);
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SUMMON_ANIMA:
                {
                    if (Unit* darkAnimus = me->FindNearestCreature(BOSS_DARK_ANIMUS, 500.0f, true))
                    {
                        if (Unit* target = darkAnimus->GetVictim())
                        {
                            me->GetMotionMaster()->MovePoint(0, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
                            point = 0;
                            _x = target->GetPositionX();
                            _y = target->GetPositionY();
                            me->AddAura(138978, target);
                        }
                    }
                    //events.ScheduleEvent(EVENT_SUMMON_ANIMA, 30000);
                    events.ScheduleEvent(EVENT_SUMMON_RINGS_ANIMA, 2000);
                    break;
                }
                case EVENT_SUMMON_RINGS_ANIMA:
                {
                    if (point == 15)
                    {
                        ReturnRings();
                        break;
                    }
                    float x = _x + 5.0f * cos(point * M_PI / 7);
                    float y = _y + 5.0f * sin(point * M_PI / 7);
                    me->SummonCreature(999287, x, y, me->GetPositionZ() + 5.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 15000);
                    ++point;
                    events.RescheduleEvent(EVENT_SUMMON_RINGS_ANIMA, 200);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_anima_ringsAI(creature);
    }
};

// PERIODIC RINGS
class bfa_npc_anima_rings_move : public CreatureScript
{
public:
    bfa_npc_anima_rings_move() : CreatureScript("bfa_npc_anima_rings_move") { }

    struct bfa_npc_anima_rings_moveAI : public ScriptedAI
    {
        bfa_npc_anima_rings_moveAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
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
            case ACTION_INITIALIZE_RING_TO_WORLD:
                events.ScheduleEvent(EVENT_MOVE_TO_TARGET, 500);
                break;
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    if (player->GetDistance(me) < 0.3f && !player->IsGameMaster() && !player->HasAura(SPELL_ANIMA_RING_DEBUFF))
                        me->CastSpell(player, SPELL_ANIMA_RING_DEBUFF);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MOVE_TO_TARGET:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    {
                        me->GetMotionMaster()->MoveChase((*itr));
                        me->AddThreat((*itr), 99999999.9f);
                        me->AI()->AttackStart((*itr));
                        events.ScheduleEvent(EVENT_UNAURA_AND_AURA, 500);
                    }
                    break;
                }
                case EVENT_UNAURA_AND_AURA:
                    me->RemoveAllAreaTriggers();
                    events.ScheduleEvent(EVENT_ADD_AURA_BACK, 300);
                    break;
                case EVENT_ADD_AURA_BACK:
                    me->CastSpell(me, 138674, true);
                    events.ScheduleEvent(EVENT_UNAURA_AND_AURA, 300);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_anima_rings_moveAI(creature);
    }
};

// 69756
class bfa_npc_anima_orb : public CreatureScript
{
public:
    bfa_npc_anima_orb() : CreatureScript("bfa_npc_anima_orb") { }

    struct bfa_npc_anima_orbAI : public ScriptedAI
    {
        bfa_npc_anima_orbAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(138116, me);
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
            case ACTION_SET_AT_ACTIVE:
            {
                ResetNpcs(NPC_ANIMA_GOLEM);
                ResetNpcs(NPC_LARGE_ANIMA_GOLEM);
                ResetNpcs(NPC_MASSIVE_ANIMA_GOLEM);
                events.ScheduleEvent(EVENT_RESET_FORCED, 1000);
                SetCorretEnergyHACKMassive();
                SetCorretEnergyHACKLarge();
                break;
            }
            }
        }

        void SetCorretEnergyHACKMassive()
        {
            std::list<Creature*> massive;
            me->GetCreatureListWithEntryInGrid(massive, NPC_MASSIVE_ANIMA_GOLEM, 500.0f);

            if (!massive.empty())
                for (auto it = massive.begin(); it != massive.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->SetPowerType(POWER_ENERGY);
                    creature->SetMaxPower(POWER_ENERGY, 36);
                    creature->SetPower(POWER_ENERGY, 0);
                }
        }


        void SetCorretEnergyHACKLarge()
        {
            std::list<Creature*> large;
            me->GetCreatureListWithEntryInGrid(large, NPC_LARGE_ANIMA_GOLEM, 500.0f);

            if (!large.empty())
                for (auto it = large.begin(); it != large.end(); ++it)
                {
                    Creature* creature = *it;
                    creature->SetPowerType(POWER_ENERGY);
                    creature->SetMaxPower(POWER_ENERGY, 8);
                    creature->SetPower(POWER_ENERGY, 0);
                }
        }

        void ResetNpcs(uint32 entry)
        {
            std::list<Creature*> summonsList;
            GetCreatureListWithEntryInGrid(summonsList, me, entry, 300.0f);
            if (!summonsList.empty())
                for (std::list<Creature*>::iterator summs = summonsList.begin(); summs != summonsList.end(); summs++)
                {
                    (*summs)->Respawn();
                    (*summs)->SetFullHealth();
                    (*summs)->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    float x, y, z, o;
                    (*summs)->GetHomePosition(x, y, z, o);
                    (*summs)->NearTeleportTo(x, y, z, 0, false);
                    //(*summs)->GetMotionMaster()->Clear();
                    //(*summs)->GetMotionMaster()->MoveTargetedHome();
                    (*summs)->RemoveAllAuras();
                }
        }

        void AddStunAura(uint32 entry)
        {
            std::list<Creature*> stunnedAdds;
            GetCreatureListWithEntryInGrid(stunnedAdds, me, entry, 500.0f);
            if (!stunnedAdds.empty())
                for (std::list<Creature*>::iterator stunNOW = stunnedAdds.begin(); stunNOW != stunnedAdds.end(); stunNOW++)
                {
                    if (!(*stunNOW)->HasAura(SPELL_POWERED_DOWN))
                        (*stunNOW)->AddAura(SPELL_POWERED_DOWN, (*stunNOW));
                }
        }

        void SetInCombatStateNpcs(uint32 entry)
        {
            std::list<Creature*> Adds;
            GetCreatureListWithEntryInGrid(Adds, me, entry, 300.0f);
            if (!Adds.empty())
                for (std::list<Creature*>::iterator npcs = Adds.begin(); npcs != Adds.end(); npcs++)
                    (*npcs)->SetInCombatWithZone();
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_RESET_FORCED:
                    AddStunAura(NPC_ANIMA_GOLEM);
                    AddStunAura(NPC_LARGE_ANIMA_GOLEM);
                    AddStunAura(NPC_MASSIVE_ANIMA_GOLEM);
                    AddStunAura(BOSS_DARK_ANIMUS);
                    switch (me->GetMap()->GetDifficultyID())
                    {
                    case DIFFICULTY_10_N:
                    case DIFFICULTY_10_HC:
                        SetCriticallyDamaged();
                        SetAddsInactiveLarge();
                        //SetAddsInactiveMassive();
                        break;
                    }
                    break;
                }
            }
        }

        void JustDied(Unit*)
        {
            ActivateGolems();
            SetBossActive();
            SetInCombatStateNpcs(NPC_MASSIVE_ANIMA_GOLEM);
            SetInCombatStateNpcs(NPC_LARGE_ANIMA_GOLEM);
            SetInCombatStateNpcs(NPC_ANIMA_GOLEM);
        }

        Creature* GetDarkAnimus()
        {
            return me->FindNearestCreature(BOSS_DARK_ANIMUS, 500.0f, true);
        }

        void SetBossActive()
        {
            Creature* darkanimus = GetDarkAnimus();
            if (!darkanimus)
                return;
            if (me->GetMap()->IsHeroic())
                darkanimus->AI()->DoAction(ACTION_ACTIVATE);
            else
            {
                darkanimus->AddAura(139537, darkanimus);
                darkanimus->SetInCombatWithZone();
            }
        }

        void SetCriticallyDamaged()
        {
            std::list<Creature*> damaged;
            me->GetCreatureListWithEntryInGrid(damaged, NPC_ANIMA_GOLEM, 500.0f);

            if (damaged.empty())
                return;
            if (damaged.size() >= 13)
                Trinity::Containers::RandomResize(damaged, 13);
            for (auto it = damaged.begin(); it != damaged.end(); ++it)
            {
                Creature* creature = *it;
                creature->AddAura(SPELL_CRITICALLY_DAMAGED, creature);
            }
        }

        void SetAddsInactiveMassive()
        {
            std::list<Creature*> Golems;
            me->GetCreatureListWithEntryInGrid(Golems, NPC_MASSIVE_ANIMA_GOLEM, 500.0f);

            if (!Golems.empty())
                if (Golems.size() > 1)
                    Trinity::Containers::RandomResize(Golems, 1);
            for (auto it = Golems.begin(); it != Golems.end(); ++it)
            {
                Creature* creature = *it;
                creature->AddAura(SPELL_POWERED_DOWN, creature);
                creature->AddAura(SPELL_CRITICALLY_DAMAGED, creature);
                creature->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                creature->GetMotionMaster()->Clear();
                creature->GetMotionMaster()->MoveTargetedHome();
            }
        }

        void SetAddsInactiveLarge()
        {
            std::list<Creature*> Golems;
            me->GetCreatureListWithEntryInGrid(Golems, NPC_LARGE_ANIMA_GOLEM, 500.0f);

            if (!Golems.empty())
                if (Golems.size() > 3)
                    Trinity::Containers::RandomResize(Golems, 3);
            for (auto it = Golems.begin(); it != Golems.end(); ++it)
            {
                Creature* creature = *it;
                creature->AddAura(SPELL_CRITICALLY_DAMAGED, creature);
                //creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                creature->GetMotionMaster()->Clear();
                creature->GetMotionMaster()->MoveTargetedHome();
            }
        }

        void ActivateGolems()
        {
            std::list<Creature*> anima;
            GetCreatureListWithEntryInGrid(anima, me, NPC_ANIMA_GOLEM, 1000.f);

            if (!anima.empty())
                for (Creature* golem : anima)
                {
                    golem->AI()->DoAction(ACTION_ACTIVATE);
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_anima_orbAI(creature);
    }
};

// 999288
class bfa_npc_anima_orb_areatrigger : public CreatureScript
{
public:
    bfa_npc_anima_orb_areatrigger() : CreatureScript("bfa_npc_anima_orb_areatrigger") { }

    struct bfa_npc_anima_orb_areatriggerAI : public ScriptedAI
    {
        bfa_npc_anima_orb_areatriggerAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisplayId(11686);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
        }

        void UpdateAI(uint32 diff)
        {
            if (me->HasAura(9454))
            {
                if (Creature* animaorb = animaOrb())
                    if (!animaorb->HasAura(9454))
                    {
                        animaorb->AddAura(9454, animaorb);
                        animaorb->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                    }
                return;
            }

            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->GetDistance2d(me) < 15.0f && !player->IsGameMaster() && !player->isDead())
                    {
                        if (Creature* animaorb = animaOrb())
                        {
                            animaorb->AI()->DoAction(ACTION_SET_AT_ACTIVE);
                            animaorb->RemoveAura(9454);
                            animaorb->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                        }
                        me->Kill(me);
                    }
                }
        }

        Creature* animaOrb()
        {
            return me->FindNearestCreature(NPC_ANIMA_ORB, 500.0f, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_anima_orb_areatriggerAI(creature);
    }
};

// 138373
class bfa_spell_powered_down : public SpellScriptLoader
{
public:
    bfa_spell_powered_down() : SpellScriptLoader("bfa_spell_powered_down") { }

    class bfa_spell_powered_down_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_powered_down_AuraScript);

        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (!GetCaster())
                return;
            GetCaster()->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (!GetCaster())
                return;
            GetCaster()->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_powered_down_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_powered_down_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_powered_down_AuraScript();
    }
};

// 138400
class bfa_spell_critically_damaged : public SpellScriptLoader
{
public:
    bfa_spell_critically_damaged() : SpellScriptLoader("bfa_spell_critically_damaged") { }

    class bfa_spell_critically_damaged_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_critically_damaged_AuraScript);

        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (!GetCaster())
                return;
            GetCaster()->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            uint32 health = GetCaster()->CountPctFromMaxHealth(5);
            GetCaster()->SetHealth(health);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_critically_damaged_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_critically_damaged_AuraScript();
    }
};

struct PossibleGMs : public std::unary_function<Unit*, bool>
{
    PossibleGMs() {}

    bool operator() (const Unit* target)
    {
        Player* player = const_cast<Player*>(target->ToPlayer());
        return player->IsGameMaster();
    }
};

// 138609
class bfa_spell_matter_swap : public SpellScriptLoader
{
public:
    bfa_spell_matter_swap() : SpellScriptLoader("bfa_spell_matter_swap") {}

    class bfa_spell_matter_swap_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_matter_swap_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Player* target = GetTarget()->ToPlayer();
            Player* swapTarget = GetTarget()->ToPlayer();
            if (!caster || !target || !swapTarget)
                return;

            std::list<Player*> players;
            target->GetPlayerListInGrid(players, 200.0f);

            for (auto targetedPlayer : players)
            {
                if (targetedPlayer->HasAura(SPELL_TARGET_OF_SWAP))
                {
                    int32 damageCaster = GetAura()->GetEffect(EFFECT_0) ? GetAura()->GetEffect(EFFECT_0)->GetAmount() : 0;
                    int32 damageTarget = GetAura()->GetEffect(EFFECT_1) ? GetAura()->GetEffect(EFFECT_1)->GetAmount() : 0;
                    damageCaster = CalculatePct(target->GetMaxHealth(), damageCaster);
                    damageTarget = CalculatePct(target->GetMaxHealth(), damageTarget);

                    target->CastCustomSpell(targetedPlayer, SPELL_MATTER_SWAP_DAMAGE, &damageTarget, NULL, NULL, true);
                    targetedPlayer->CastCustomSpell(target, SPELL_MATTER_SWAP_DAMAGE, &damageCaster, NULL, NULL, true);

                    targetedPlayer->NearTeleportTo(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), false);
                    target->NearTeleportTo(targetedPlayer->GetPositionX(), targetedPlayer->GetPositionY(), targetedPlayer->GetPositionZ(), targetedPlayer->GetOrientation(), false);

                    break;
                }
            }
        }

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Player* target = GetTarget()->ToPlayer();
            Player* mostDistant = GetTarget()->ToPlayer();
            if (!target || !mostDistant)
                return;

            Aura* aura = GetAura();
            uint32 duration = aura->GetDuration() / IN_MILLISECONDS;
            if (duration < 10)
            {
                if (AuraEffect* aurEff = aura->GetEffect(EFFECT_0))
                    aurEff->SetAmount(duration * 10);
                if (AuraEffect* aurEff = aura->GetEffect(EFFECT_1))
                    aurEff->SetAmount((10 - duration) * 10);
            }

            std::list<Player*> targets;
            target->GetPlayerListInGrid(targets, 200.0f);

            targets.remove_if(PossibleGMs());
            targets.remove(target);
            if (!targets.empty())
            {
                targets.sort(Trinity::ObjectDistanceOrderPred(target, false));
                mostDistant = *targets.begin();
                target->AddAura(SPELL_TARGET_OF_SWAP, mostDistant);
            }
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_matter_swap_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_matter_swap_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_matter_swap_AuraScript();
    }

};

// 138644
class bfa_spell_siphon_anima : public SpellScriptLoader
{
public:
    bfa_spell_siphon_anima() : SpellScriptLoader("bfa_spell_siphon_anima") { }

    class bfa_spell_siphon_anima_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_siphon_anima_SpellScript);

        void OnHit(SpellEffIndex index)
        {
            Unit* caster = GetCaster();

            if (Unit* target = GetHitUnit())
            {
                if (!target)
                    return;

                if (target->GetEntry() == NPC_ANIMA_GOLEM || target->GetEntry() == NPC_MASSIVE_ANIMA_GOLEM || target->GetEntry() == NPC_LARGE_ANIMA_GOLEM)
                {
                    if (target->GetPower(POWER_ENERGY) > 0)
                    {
                        target->SetPower(POWER_ENERGY, target->GetPower(POWER_ENERGY) - 1);
                        caster->SetPower(POWER_ENERGY, caster->GetPower(POWER_ENERGY) + 1);
                    }

                    if (target->GetPower(POWER_ENERGY) == 0)
                        target->Kill(target);
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_siphon_anima_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_POWER_DRAIN);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_siphon_anima_SpellScript();
    }

};

class bfa_spell_full_power : public SpellScriptLoader
{
public:
    bfa_spell_full_power() : SpellScriptLoader("bfa_spell_full_power") { }

    class bfa_spell_full_power_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_full_power_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            if (!GetCaster())
                return;

            GetCaster()->CastSpell(GetCaster()->GetVictim(), 138738, true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_full_power_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_full_power_AuraScript();
    }
};

// 138451
class bfa_spell_acceleration_link : public SpellScriptLoader
{
public:
    bfa_spell_acceleration_link() : SpellScriptLoader("bfa_spell_acceleration_link") { }

    class bfa_spell_acceleration_link_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_acceleration_link_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();

            std::list<Creature*> cList;
            caster->GetCreatureListWithEntryInGrid(cList, NPC_ANIMA_GOLEM, 5.0f);

            cList.remove_if(isDamaged());

            if (!cList.empty())
                for (std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                {
                    // Don't count self
                    if ((*itr) == caster)
                        continue;
                    if (caster->HasAura(SPELL_CRITICALLY_DAMAGED) || (*itr)->HasAura(SPELL_CRITICALLY_DAMAGED)) // don't count critically damaged
                        continue;
                    if ((*itr)->GetDistance(caster) < 2.0f && (*itr)->IsAlive())
                    {
                        caster->AddAura(SPELL_ACCELERATION_LINK, caster);
                        (*itr)->AddAura(SPELL_ACCELERATION_LINK, (*itr));

                        // Aura on caster
                        if (Aura* link = caster->GetAura(SPELL_ACCELERATION_LINK))
                        {
                            stacks = cList.size() - 1;
                            link->SetStackAmount(stacks);
                        }
                        // Aura on listed creature w/o caster
                        if (Aura* link2 = (*itr)->GetAura(SPELL_ACCELERATION_LINK))
                        {
                            stacks = cList.size() - 1;
                            link2->SetStackAmount(stacks);
                        }
                    }
                    else if ((*itr)->GetDistance(caster) > 2.0f)
                    {
                        caster->RemoveAura(SPELL_ACCELERATION_LINK);
                        (*itr)->RemoveAura(SPELL_ACCELERATION_LINK);
                    }
                }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_acceleration_link_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }

    private:
        uint32 stacks;

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_acceleration_link_AuraScript();
    }
};

void AddSC_bfa_boss_dark_animus()
{
    new bfa_npc_anima_golem;
    new bfa_npc_massive_anima_golem;
    new bfa_npc_large_anima_golem;
    new bfa_npc_crimson_wake;
    new bfa_boss_dark_animus;
    new bfa_npc_anima_rings;
    new bfa_npc_anima_rings_move;
    new bfa_npc_anima_orb;
    new bfa_npc_anima_orb_areatrigger;

    new bfa_spell_critically_damaged;
    new bfa_spell_powered_down;
    new bfa_spell_matter_swap;
    new bfa_spell_siphon_anima;
    new bfa_spell_full_power;
    new bfa_spell_acceleration_link;
}
