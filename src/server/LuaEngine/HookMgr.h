#include "ScriptMgr.h"
#include "ScriptPCH.h"
#include "LuaEngine.h"

#ifndef LUAHOOKS_H
#define LUAHOOKS_H

void Eluna_AddScriptHooks();

class ScriptEventMap
{
public:
    ScriptEventMap() { }
    ~ScriptEventMap() { ScriptEventsReset(); }

    struct eventData
    {
        int funcRef; uint32 delay; uint32 calls;
        eventData(int _funcRef, uint32 _delay, uint32 _calls) :
        funcRef(_funcRef), delay(_delay), calls(_calls) {}
    };

    typedef std::multimap<uint32, eventData> EventStore; // Not to use multimap? Can same function ref ID be used multiple times?

    virtual void OnScriptEvent(int funcRef, uint32 delay, uint32 calls) { }

    static void ScriptEventsResetAll(); // Unregisters and stops all timed events
    void ScriptEventsReset();
    void ScriptEventCancel(int funcRef);

    // Gets the event map saved for a guid
    static ScriptEventMap* GetEvents(WorldObject* obj)
    {
        if (!obj)
            return NULL;
        UNORDERED_MAP<uint64, ScriptEventMap*>::iterator it = ScriptEventMaps.find(obj->GetGUID());
        if (it != ScriptEventMaps.end())
            return it->second;
        return NULL;
    }

    void ScriptEventsUpdate(uint32 time)
    {
        _time += time;
    }

    bool ScriptEventsEmpty() const
    {
        return _eventMap.empty();
    }

    void ScriptEventCreate(int funcRef, uint32 delay, uint32 calls)
    {
        _eventMap.insert(EventStore::value_type(_time + delay, eventData(funcRef, delay, calls)));
    }

    void ScriptEventsExecute()
    {
        if (ScriptEventsEmpty())
            return;

        for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
        {
            if (itr->first > _time)
            {
                ++itr;
                continue;
            }

            OnScriptEvent(itr->second.funcRef, itr->second.delay, itr->second.calls);

            if (itr->second.calls != 1)
            {
                if (itr->second.calls > 1)
                    itr->second.calls = itr->second.calls-1;
                _eventMap.insert(EventStore::value_type(_time + itr->second.delay, itr->second));
            }
            _eventMap.erase(itr++);
        }
    }

    static UNORDERED_MAP<uint64, ScriptEventMap*> ScriptEventMaps; // Creature and gameobject timed events

private:
    EventStore _eventMap;
    uint32 _time;
};

class Hook_WorldScript : public WorldScript, public ScriptEventMap
{
public:
    Hook_WorldScript() : WorldScript("SmartHook_WorldScript"), ScriptEventMap()
    {
    }
    ~Hook_WorldScript()
    {
    }

    void OnOpenStateChange(bool open)
    {
        for (std::vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_OPEN_STATE_CHANGE).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_OPEN_STATE_CHANGE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_OPEN_STATE_CHANGE);
            sEluna->PushBoolean(sEluna->LuaState, open);
            sEluna->ExecuteCall(2, 0);
        }
    }
    void OnConfigLoad(bool reload)
    {
        for (std::vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_CONFIG_LOAD).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_CONFIG_LOAD).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_CONFIG_LOAD);
            sEluna->PushBoolean(sEluna->LuaState, reload);
            sEluna->ExecuteCall(2, 0);
        }
    }
    void OnMotdChange(std::string& newMotd)
    {
        for (std::vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_MOTD_CHANGE).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_MOTD_CHANGE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_MOTD_CHANGE);
            sEluna->PushString(sEluna->LuaState, newMotd.c_str());
            sEluna->ExecuteCall(2, 0);
        }
    }
    void OnShutdownInitiate(ShutdownExitCode code, ShutdownMask mask)
    {
        for (std::vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN_INIT).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN_INIT).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_SHUTDOWN_INIT);
            sEluna->PushInteger(sEluna->LuaState, code);
            sEluna->PushInteger(sEluna->LuaState, mask);
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnShutdownCancel()
    {
        for (std::vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN_CANCEL).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN_CANCEL).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_SHUTDOWN_CANCEL);
            sEluna->ExecuteCall(1, 0);
        }
    }
    void OnWorldUpdate(uint32 diff)
    {
        ScriptEventsUpdate(diff);
        ScriptEventsExecute();
        for (std::vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_UPDATE).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_UPDATE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_UPDATE);
            sEluna->PushUnsigned(sEluna->LuaState, diff);
            sEluna->ExecuteCall(2, 0);
        }
    }
    // executed when a  timed event fires
    void OnScriptEvent(int funcRef, uint32 delay, uint32 calls)
    {
        sEluna->BeginCall(funcRef);
        sEluna->PushUnsigned(sEluna->LuaState, funcRef);
        sEluna->PushUnsigned(sEluna->LuaState, delay);
        sEluna->PushUnsigned(sEluna->LuaState, calls);
        sEluna->ExecuteCall(3, 0);
    }
    void OnStartup()
    {
        for (std::vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_STARTUP).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_STARTUP).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_STARTUP);
            sEluna->ExecuteCall(1, 0);
        }
    }
    void OnShutdown()
    {
        for (std::vector<int>::iterator itr = sEluna->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN).begin();
            itr != sEluna->ServerEventBindings.at(WORLD_EVENT_ON_SHUTDOWN).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WORLD_EVENT_ON_SHUTDOWN);
            sEluna->ExecuteCall(1, 0);
        }
    }
};
class Hook_CreatureScript : public CreatureScript
{
public:
    Hook_CreatureScript() : CreatureScript("SmartHook_CreatureScript") // Smart suppressing error @startup
    {
    }
    ~Hook_CreatureScript()
    {
    }

    struct ScriptCreatureAI : ScriptedAI, public ScriptEventMap
    {
        ScriptCreatureAI(Creature* creature) : ScriptedAI(creature), ScriptEventMap()
        {
        }
        ~ScriptCreatureAI()
        {
            ScriptEventMap::ScriptEventMaps.erase(me->GetGUID());
        }

        //Called at World update tick
        void UpdateAI(uint32 diff)
        {
            ScriptedAI::UpdateAI(diff);
            ScriptEventsUpdate(diff);
            ScriptEventsExecute();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_AIUPDATE);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_AIUPDATE);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnsigned(sEluna->LuaState, diff);
            sEluna->ExecuteCall(3, 0);
        }

        // executed when a  timed event fires
        void OnScriptEvent(int funcRef, uint32 delay, uint32 calls)
        {
            sEluna->BeginCall(funcRef);
            sEluna->PushUnsigned(sEluna->LuaState, funcRef);
            sEluna->PushUnsigned(sEluna->LuaState, delay);
            sEluna->PushUnsigned(sEluna->LuaState, calls);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(4, 0);
        }

        //Called for reaction at enter to combat if not in combat yet (enemy can be NULL)
        //Called at creature aggro either by MoveInLOS or Attack Start
        void EnterCombat(Unit* target)
        {
            ScriptedAI::EnterCombat(target);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_ENTER_COMBAT);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_ENTER_COMBAT);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, target);
            sEluna->ExecuteCall(3, 0);
        }

        // Called at any Damage from any attacker (before damage apply)
        void DamageTaken(Unit* attacker, uint32& damage)
        {
            ScriptedAI::DamageTaken(attacker, damage);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_DAMAGE_TAKEN);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_DAMAGE_TAKEN);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, attacker);
            sEluna->PushUnsigned(sEluna->LuaState, damage);
            sEluna->ExecuteCall(4, 0);
        }

        //Called at creature death
        void JustDied(Unit* killer)
        {
            ScriptedAI::JustDied(killer);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_DIED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_DIED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, killer);
            sEluna->ExecuteCall(3, 0);
        }

        //Called at creature killing another unit
        void KilledUnit(Unit* victim)
        {
            ScriptedAI::KilledUnit(victim);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_TARGET_DIED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_TARGET_DIED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, victim);
            sEluna->ExecuteCall(3, 0);
        }

        // Called when the creature summon successfully other creature
        void JustSummoned(Creature* summon)
        {
            ScriptedAI::JustSummoned(summon);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, summon);
            sEluna->ExecuteCall(3, 0);
        }

        // Called when a summoned creature is despawned
        void SummonedCreatureDespawn(Creature* summon)
        {
            ScriptedAI::SummonedCreatureDespawn(summon);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, summon);
            sEluna->ExecuteCall(3, 0);
        }

        // Called when hit by a spell
        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            ScriptedAI::SpellHit(caster, spell);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_HIT_BY_SPELL);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_HIT_BY_SPELL);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, caster);
            sEluna->PushUnsigned(sEluna->LuaState, spell->Id); // Pass spell object?
            sEluna->ExecuteCall(4, 0);
        }

        // Called when spell hits a target
        void SpellHitTarget(Unit* target, SpellInfo const* spell)
        {
            ScriptedAI::SpellHitTarget(target, spell);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SPELL_HIT_TARGET);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SPELL_HIT_TARGET);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, target);
            sEluna->PushUnsigned(sEluna->LuaState, spell->Id); // Pass spell object?
            sEluna->ExecuteCall(4, 0);
        }

        //Called at waypoint reached or PointMovement end
        void MovementInform(uint32 type, uint32 id)
        {
            ScriptedAI::MovementInform(type, id);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_REACH_WP);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_REACH_WP);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnsigned(sEluna->LuaState, type);
            sEluna->PushUnsigned(sEluna->LuaState, id);
            sEluna->ExecuteCall(4, 0);
        }

        // Called when AI is temporarily replaced or put back when possess is applied or removed
        void OnPossess(bool apply)
        {
            ScriptedAI::OnPossess(apply);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_POSSESS);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_POSSESS);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushBoolean(sEluna->LuaState, apply);
            sEluna->ExecuteCall(3, 0);
        }

        //Called at creature reset either by death or evade
        void Reset()
        {
            ScriptedAI::Reset();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_RESET);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_RESET);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(2, 0);
        }

        // Called before EnterCombat even before the creature is in combat.
        void AttackStart(Unit* target)
        {
            ScriptedAI::AttackStart(target);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_PRE_COMBAT);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_PRE_COMBAT);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, target);
            sEluna->ExecuteCall(3, 0);
        }

        // Called in Creature::Update when deathstate = DEAD. Inherited classes may maniuplate the ability to respawn based on scripted events.
        bool CanRespawn()
        {
            ScriptedAI::CanRespawn();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_CAN_RESPAWN);
            if (!bind)
                return true;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_CAN_RESPAWN);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(2, 0);
            return true;
        }

        // Called for reaction at stopping attack at no attackers or targets
        void EnterEvadeMode()
        {
            ScriptedAI::EnterEvadeMode();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_LEAVE_COMBAT);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_LEAVE_COMBAT);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(2, 0);
        }

        // Called when the creature is summoned successfully by other creature
        void IsSummonedBy(Unit* summoner)
        {
            ScriptedAI::IsSummonedBy(summoner);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SUMMONED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SUMMONED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, summoner);
            sEluna->ExecuteCall(3, 0);
        }

        void SummonedCreatureDies(Creature* summon, Unit* killer)
        {
            ScriptedAI::SummonedCreatureDies(summon, killer);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, summon);
            sEluna->PushUnit(sEluna->LuaState, killer);
            sEluna->ExecuteCall(4, 0);
        }

        // Called when the creature is target of hostile action: swing, hostile spell landed, fear/etc)
        void AttackedBy(Unit* attacker)
        {
            ScriptedAI::AttackedBy(attacker);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_ATTACKED_AT);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_ATTACKED_AT);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, attacker);
            sEluna->ExecuteCall(3, 0);
        }

        // Called when creature is spawned or respawned (for reseting variables)
        void JustRespawned()
        {
            ScriptedAI::JustRespawned();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SPAWN);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SPAWN);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(2, 0);
        }

        void OnCharmed(bool apply)
        {
            ScriptedAI::OnCharmed(apply);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_CHARMED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_CHARMED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushBoolean(sEluna->LuaState, apply);
            sEluna->ExecuteCall(3, 0);
        }

        // Called at reaching home after evade
        void JustReachedHome()
        {
            ScriptedAI::JustReachedHome();
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_REACH_HOME);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_REACH_HOME);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->ExecuteCall(2, 0);
        }

        // Called at text emote receive from player
        void ReceiveEmote(Player* player, uint32 emoteId)
        {
            ScriptedAI::ReceiveEmote(player, emoteId);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_RECEIVE_EMOTE);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_RECEIVE_EMOTE);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushUnsigned(sEluna->LuaState, emoteId);
            sEluna->ExecuteCall(4, 0);
        }

        // Called when owner takes damage
        void OwnerAttackedBy(Unit* attacker)
        {
            ScriptedAI::OwnerAttackedBy(attacker);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_OWNER_ATTACKED_AT);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_OWNER_ATTACKED_AT);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, attacker);
            sEluna->ExecuteCall(3, 0);
        }

        // Called when owner attacks something
        void OwnerAttacked(Unit* target)
        {
            ScriptedAI::OwnerAttacked(target);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_OWNER_ATTACKED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_OWNER_ATTACKED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, target);
            sEluna->ExecuteCall(3, 0);
        }

        // called when the corpse of this creature gets removed
        void CorpseRemoved(uint32& respawnDelay)
        {
            ScriptedAI::CorpseRemoved(respawnDelay);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_CORPSE_REMOVED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_CORPSE_REMOVED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnsigned(sEluna->LuaState, respawnDelay);
            sEluna->ExecuteCall(3, 0);
        }

        void PassengerBoarded(Unit* passenger, int8 seatId, bool apply)
        {
            ScriptedAI::PassengerBoarded(passenger, seatId, apply);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_PASSANGER_BOARDED);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_PASSANGER_BOARDED);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, passenger);
            sEluna->PushInteger(sEluna->LuaState, seatId);
            sEluna->PushBoolean(sEluna->LuaState, apply);
            sEluna->ExecuteCall(5, 0);
        }

        void OnSpellClick(Unit* clicker)
        {
            ScriptedAI::OnSpellClick(clicker);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SPELL_CLICK);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_SPELL_CLICK);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, clicker);
            sEluna->ExecuteCall(3, 0);
        }

        void MoveInLineOfSight(Unit* who)
        {
            ScriptedAI::MoveInLineOfSight(who);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_MOVE_IN_LOS);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_MOVE_IN_LOS);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, who);
            sEluna->ExecuteCall(3, 0);
        }

        // Called if IsVisible(Unit* who) is true at each who move, reaction at visibility zone enter
        void MoveInLineOfSight_Safe(Unit* who)
        {
            ScriptedAI::MoveInLineOfSight_Safe(who);
            int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS);
            sEluna->PushUnit(sEluna->LuaState, me);
            sEluna->PushUnit(sEluna->LuaState, who);
            sEluna->ExecuteCall(3, 0);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        if (!sEluna->CreatureEventBindings->GetBindMap(creature->GetEntry()))
            return NULL;

        ScriptCreatureAI* luaCreatureAI = new ScriptCreatureAI(creature);
        ScriptEventMap::ScriptEventMaps[creature->GetGUID()] = luaCreatureAI;
        return luaCreatureAI;
    }
};
class Hook_GameObjectScript : public GameObjectScript
{
public:
    Hook_GameObjectScript() : GameObjectScript("SmartHook_GameObjectScript") // Smart suppressing error @startup
    {
    }
    ~Hook_GameObjectScript()
    {
    }

    struct ScriptGameObjectAI : public GameObjectAI, public ScriptEventMap
    {
        ScriptGameObjectAI(GameObject* _go) : GameObjectAI(_go), ScriptEventMap()
        {
        }
        ~ScriptGameObjectAI()
        {
            ScriptEventMap::ScriptEventMaps.erase(go->GetGUID());
        }

        void UpdateAI(uint32 diff)
        {
            ScriptEventsUpdate(diff);
            ScriptEventsExecute();
            int bind = sEluna->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_AIUPDATE);
            if (!bind)
                return;
            sEluna->BeginCall(bind);
            sEluna->PushInteger(sEluna->LuaState, GAMEOBJECT_EVENT_ON_AIUPDATE);
            sEluna->PushGO(sEluna->LuaState, go);
            sEluna->PushUnsigned(sEluna->LuaState, diff);
            sEluna->ExecuteCall(3, 0);
        }

        // executed when a timed event fires
        void OnScriptEvent(int funcRef, uint32 delay, uint32 calls)
        {
            sEluna->BeginCall(funcRef);
            sEluna->PushUnsigned(sEluna->LuaState, funcRef);
            sEluna->PushUnsigned(sEluna->LuaState, delay);
            sEluna->PushUnsigned(sEluna->LuaState, calls);
            sEluna->PushGO(sEluna->LuaState, go);
            sEluna->ExecuteCall(4, 0);
        }

        void Reset()
        {
            sEluna->BeginCall(sEluna->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_RESET));
            sEluna->PushInteger(sEluna->LuaState, GAMEOBJECT_EVENT_ON_RESET);
            sEluna->PushGO(sEluna->LuaState, go);
            sEluna->ExecuteCall(2, 0);
        }
    };

    GameObjectAI* GetAI(GameObject* gameObject) const
    {
        if (!sEluna->GameObjectEventBindings->GetBindMap(gameObject->GetEntry()))
            return NULL;

        ScriptGameObjectAI* luaGameObjectAI = new ScriptGameObjectAI(gameObject);
        ScriptEventMap::ScriptEventMaps[gameObject->GetGUID()] = luaGameObjectAI;
        return luaGameObjectAI;
    }
};

class HookScript;
class HookMgr
{
public:
    typedef std::set<HookScript*> HookPointerSet;
    HookPointerSet hookPointers;
    // used for AI events
    Hook_CreatureScript* CreatureAI;
    Hook_GameObjectScript* GameObjectAI;
    Hook_WorldScript* WorldAI;

    HookMgr()
    {
        CreatureAI = new Hook_CreatureScript();
        GameObjectAI = new Hook_GameObjectScript();
        WorldAI = new Hook_WorldScript();
    }

    // misc
    void HandleGossipSelectOption(Player* player, uint64 guid, uint32 sender, uint32 action, std::string code, uint32 menuId);
    bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg);
    bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg, Group* group);
    bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg, Guild* guild);
    bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg, Channel* channel);
    void OnElunaRestart(uint32 eventId);
    // item
    bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, Item* target);
    bool OnQuestAccept(Player* player, Item* item, Quest const* quest);
    bool OnUse(Player* player, Item* item, SpellCastTargets const& targets);
    bool OnExpire(Player* player, ItemTemplate const* proto);
    // creature
    bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, Creature* target);
    bool OnGossipHello(Player* player, Creature* creature);
    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action);
    bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, const char* code);
    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest);
    bool OnQuestSelect(Player* player, Creature* creature, Quest const* quest);
    bool OnQuestComplete(Player* player, Creature* creature, Quest const* quest);
    bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 opt);
    uint32 GetDialogStatus(Player* player, Creature* creature);
    // gameobject
    bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, GameObject* target);
    bool OnGossipHello(Player* player, GameObject* go);
    bool OnGossipSelect(Player* player, GameObject* go, uint32 sender, uint32 action);
    bool OnGossipSelectCode(Player* player, GameObject* go, uint32 sender, uint32 action, const char* code);
    bool OnQuestAccept(Player* player, GameObject* go, Quest const* quest);
    bool OnQuestReward(Player* player, GameObject* go, Quest const* quest, uint32 opt);
    uint32 GetDialogStatus(Player* player, GameObject* go);
    void OnDestroyed(GameObject* go, Player* player);
    void OnDamaged(GameObject* go, Player* player);
    void OnLootStateChanged(GameObject* go, uint32 state, Unit* unit);
    void OnGameObjectStateChanged(GameObject* go, uint32 state);
    // areatrigger
    bool OnTrigger(Player* player, AreaTriggerEntry const* trigger);
    // weather
    void OnChange(Weather* weather, WeatherState state, float grade);
    // condition
    bool OnConditionCheck(Condition* condition, ConditionSourceInfo& sourceInfo);
    // transport
    void OnAddPassenger(Transport* transport, Player* player);
    void OnAddCreaturePassenger(Transport* transport, Creature* creature);
    void OnRemovePassenger(Transport* transport, Player* player);
    void OnRelocate(Transport* transport, uint32 waypointId, uint32 mapId, float x, float y, float z);
};
#define sHookMgr ACE_Singleton<HookMgr, ACE_Null_Mutex>::instance()

class HookScript
{
public:
    HookScript()
    {
        sHookMgr->hookPointers.insert(this);
    }
    ~HookScript()
    {
        sHookMgr->hookPointers.erase(this);
    }
    // misc
    virtual void HandleGossipSelectOption(Player* player, uint64 guid, uint32 sender, uint32 action, std::string code, uint32 menuId) { }
    virtual bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg) { return true; }
    virtual bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg, Group* group) { return true; }
    virtual bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg, Guild* guild) { return true; }
    virtual bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg, Channel* channel) { return true; }
    virtual void OnElunaRestart(uint32 eventId) { }
    // item
    virtual bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, Item* target) { return false; }
    virtual bool OnQuestAccept(Player* player, Item* item, Quest const* quest) { return false; }
    virtual bool OnUse(Player* player, Item* item, SpellCastTargets const& targets) { return false; }
    virtual bool OnExpire(Player* player, ItemTemplate const* proto) { return false; }
    // creature
    virtual bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, Creature* target) { return false; }
    virtual bool OnGossipHello(Player* player, Creature* creature) { return false; }
    virtual bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) { return false; }
    virtual bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, const char* code) { return false; }
    virtual bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) { return false; }
    virtual bool OnQuestSelect(Player* player, Creature* creature, Quest const* quest) { return false; }
    virtual bool OnQuestComplete(Player* player, Creature* creature, Quest const* quest) { return false; }
    virtual bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 opt) { return false; }
    virtual uint32 GetDialogStatus(Player* player, Creature* creature) { return false; }
    // gameobject
    virtual bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, GameObject* target) { return false; }
    virtual bool OnGossipHello(Player* player, GameObject* go) { return false; }
    virtual bool OnGossipSelect(Player* player, GameObject* go, uint32 sender, uint32 action) { return false; }
    virtual bool OnGossipSelectCode(Player* player, GameObject* go, uint32 sender, uint32 action, const char* code) { return false; }
    virtual bool OnQuestAccept(Player* player, GameObject* go, Quest const* quest) { return false; }
    virtual bool OnQuestReward(Player* player, GameObject* go, Quest const* quest, uint32 opt) { return false; }
    virtual uint32 GetDialogStatus(Player* player, GameObject* go) { return 100; }
    virtual void OnDestroyed(GameObject* go, Player* player) { }
    virtual void OnDamaged(GameObject* go, Player* player) { }
    virtual void OnLootStateChanged(GameObject* go, uint32 state, Unit* unit) { }
    virtual void OnGameObjectStateChanged(GameObject* go, uint32 state) { }
    // areatrigger
    virtual bool OnTrigger(Player* player, AreaTriggerEntry const* trigger) { return false; }
    // weather
    virtual void OnChange(Weather* weather, WeatherState state, float grade) { }
    // condition
    virtual bool OnConditionCheck(Condition* condition, ConditionSourceInfo& sourceInfo) { return true; }
    // transport
    virtual void OnAddPassenger(Transport* transport, Player* player) { }
    virtual void OnAddCreaturePassenger(Transport* transport, Creature* creature) { }
    virtual void OnRemovePassenger(Transport* transport, Player* player) { }
    virtual void OnRelocate(Transport* transport, uint32 waypointId, uint32 mapId, float x, float y, float z) { }
};
#endif
