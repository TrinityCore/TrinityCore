
////////////////////////////////////////////////////////////////////////////////
///
///  Davethebrave - Daniel.E.
///  Global Game Developement 2015 - 2020
///  All Rights Reserved.
///
////////////////////////////////////////////////////////////////////////////////

/*
Normal: 85%
Heroic: 70%
*/

#include "siege_of_orgrimmar.h"
#include "AreaTrigger.h"
#include "Player.h"
#include "Pet.h"
#include "boss_garrosh_hellscream.h"

static void DespawnCreaturesInArea(uint32 entry, WorldObject* object)
{
    std::list<Creature*> creatures;
    GetCreatureListWithEntryInGrid(creatures, object, entry, 1500.0f);
    if (creatures.empty())
        return;

    for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
        (*iter)->DespawnOrUnsummon();
}

static void RespawnCreatures(uint32 entry, WorldObject* object)
{
    std::list<Creature*> creatures;
    GetCreatureListWithEntryInGrid(creatures, object, entry, 1500.0f);
    if (creatures.empty())
        return;

    for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
        (*iter)->Respawn();
}

static void AttackStop(uint32 entry, WorldObject* object)
{
    std::list<Creature*> creatures;
    GetCreatureListWithEntryInGrid(creatures, object, entry, 1500.0f);
    if (creatures.empty())
        return;

    for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
    {
        if ((*iter)->IsAlive() && (*iter)->IsInCombat())
        {
            (*iter)->AttackStop();
            (*iter)->CombatStop();
        }
    }
}
/*
static class MostCreatureHPMissingInRange
{
public:
    MostCreatureHPMissingInRange(Unit const* obj, float range, uint32 hp) : i_obj(obj), i_range(range), i_hp(hp) {}

    bool operator()(Unit* u)
    {
        if (u->isAlive() && u->isInCombat() && !i_obj->IsHostileTo(u) && i_obj->IsWithinDistInMap(u, i_range) && u->GetMaxHealth() - u->GetHealth() > i_hp && u->GetTypeId() != TYPEID_PLAYER && u->GetEntry() != BOSS_GARROSH_HELLSCREAM)
        {
            i_hp = u->GetMaxHealth() - u->GetHealth();
            return true;
        }
        return false;
    }

private:
    Unit const* i_obj;
    float i_range;
    uint32 i_hp;
};
*/

class CheckIfPlayerOrGarroshAndRemove
{
public:
    CheckIfPlayerOrGarroshAndRemove() {}
    bool operator()(WorldObject* object)
    {
        if (object->GetTypeId() == TYPEID_PLAYER || object->GetEntry() != BOSS_GARROSH_HELLSCREAM)
            return true;
        else
            return false;
    }
};

class CheckIfGarroshAndRemove
{
public:
    CheckIfGarroshAndRemove() {}
    bool operator()(WorldObject* object)
    {
        if (object->GetEntry() == BOSS_GARROSH_HELLSCREAM)
            return true;
        else
            return false;
    }
};

class CheckIfPlayerAndRemove
{
public:
    CheckIfPlayerAndRemove() {}
    bool operator()(WorldObject* object)
    {
        if (object->GetTypeId() == TYPEID_PLAYER || object->GetEntry() != CREATURE_KORKRON_WARBRINGER && object->GetEntry() != CREATURE_FARSEER_WOLF_RIDER && object->GetEntry() != BOSS_GARROSH_HELLSCREAM)
            return true;
        else
            return false;
    }
};

void ModifyGarroshPride(uint32 p_BaseValue, Player* player)
{
    if (!player->HasAura(Spells::SPELL_GARROSH_POWER))
        return;

    if (Aura* l_Aura = player->GetAura(Spells::SPELL_GARROSH_POWER))
    {
        if (l_Aura->GetEffect(0)->GetMiscValue() == 263)
        {
            player->SetPower(Powers(POWER_ALTERNATE_POWER), p_BaseValue);
        }
    }
}

#define l_IntermissionMaxTime 60200
#define l_MaxIntermissionPhases 3

// Introduction basicevent
class garrosh_intermission_introduction : public BasicEvent
{
public:
    explicit garrosh_intermission_introduction(Unit* unit, int value) : obj(unit), modifier(value)
    {
    }

    bool Execute(uint64 /*currTiobj*/, uint32 /*diff*/)
    {
        if (obj)
        {
            if (InstanceScript* m_Instance = obj->GetInstanceScript())
            {
                if (Creature* l_Heart = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(DATA_GARROSH_HEART_OF_YSHAARAJ)))
                {
                    if (Creature* l_Garrosh = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(DATA_GARROSH_HELLSCREAM)))
                    {
                        if (l_Heart->AI() && l_Garrosh->AI())
                        {
                            switch (modifier)
                            {
                            case 0:
                                l_Garrosh->GetMotionMaster()->MovePoint(Movements::MOVEMENT_PHASE_2_ACTIVATION, l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetPositionX(), l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetPositionY(), l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetPositionZ());

                                obj->m_Events.AddEvent(new garrosh_intermission_introduction(obj, 1), obj->m_Events.CalculateTime(8000));
                                break;
                            case 1:
                                l_Garrosh->AI()->Talk(Talks::TALK_GARROSH_SPELL08);
                                l_Garrosh->CastSpell(l_Garrosh, Spells::SPELL_TEMPORARY_STRANGULATED_COSMETIC);
                                l_Heart->CastSpell(l_Garrosh, Spells::SPELL_PHASE_TWO_TRANSITION_PURPLE_SHIT);

                                l_Garrosh->SetDisableGravity(true);
                                l_Garrosh->SetCanFly(true);

                                obj->m_Events.AddEvent(new garrosh_intermission_introduction(obj, 2), obj->m_Events.CalculateTime(8000));
                                break;
                            case 2:
                                l_Garrosh->RemoveFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_DISABLE_MOVE | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC);
                                l_Garrosh->RemoveAura(Spells::SPELL_TEMPORARY_STRANGULATED_COSMETIC);
                                l_Garrosh->SetReactState(REACT_DEFENSIVE);

                                // Hack fixing garrosh health to prevent maxed health and death state
                                l_Garrosh->SetHealth(l_Garrosh->GetMaxHealth());

                                l_Garrosh->setFaction(16);

                                obj->m_Events.AddEvent(new garrosh_intermission_introduction(obj, 3), obj->m_Events.CalculateTime(12000));
                                break;
                            case 3:
                            {
                                std::list<Player*> l_ListPlayers;
                                l_Garrosh->GetPlayerListInGrid(l_ListPlayers, 300.0f);

                                if (l_ListPlayers.empty())
                                    return false;

                                Position pos;
                                l_Heart->GetPosition(pos.m_positionX,pos.m_positionY);
                                l_Heart->CastSpell(l_Garrosh, Spells::SPELL_ENTER_THE_REALM_OF_YSHAARAJ_PURPLE_BEAM);

                                l_Garrosh->GetMotionMaster()->MoveJump(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), 18.0f, 10.0f);

                                for (auto itr : l_ListPlayers)
                                {
                                    itr->AddAura(Spells::SPELL_ENTER_THE_REALM_OF_YSHAARAJ_SCREEN_EFFECT, itr);
                                    itr->GetMotionMaster()->MoveJump(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), 18.0f, 10.0f);
                                }

                                obj->m_Events.AddEvent(new garrosh_intermission_introduction(obj, 4), obj->m_Events.CalculateTime(3500));
                                break;
                            }
                            case 4:
                            {
                                if (l_Garrosh->GetAI())
                                    l_Garrosh->GetAI()->DoAction(Actions::ACTION_TELEPORT);
                                break;
                            }
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
private:
    Creature* storm;
    Unit* obj;
    int modifier;
    int Event;
};

// Introduction basicevent
class garrosh_fight_introduction : public BasicEvent
{
public:
    explicit garrosh_fight_introduction(Unit* unit, int value) : obj(unit), modifier(value)
    {
    }

    bool Execute(uint64 /*currTiobj*/, uint32 /*diff*/)
    {
        if (obj)
        {
            if (InstanceScript* l_Instance = obj->GetInstanceScript())
            {
                if (Creature* l_Thrall = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(DATA_THRALL)))
                {
                    if (Creature* l_Garrosh = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(DATA_GARROSH_HELLSCREAM)))
                    {
                        if (l_Thrall->AI() && l_Garrosh->AI())
                        {
                            switch (modifier)
                            {
                            case 0:
                                l_Thrall->AI()->Talk(Talks::TALK_THRALL_INTRO01);

                                obj->m_Events.AddEvent(new garrosh_fight_introduction(obj, 1), obj->m_Events.CalculateTime(12000));
                                break;
                            case 1:
                                l_Garrosh->AI()->Talk(Talks::TALK_INTRO01);

                                obj->m_Events.AddEvent(new garrosh_fight_introduction(obj, 2), obj->m_Events.CalculateTime(12000));
                                break;
                            case 2:
                                obj->m_Events.AddEvent(new garrosh_fight_introduction(obj, 3), obj->m_Events.CalculateTime(9000));
                                break;
                            case 3:
                                l_Garrosh->AI()->Talk(Talks::TALK_INTRO02);

                                obj->m_Events.AddEvent(new garrosh_fight_introduction(obj, 4), obj->m_Events.CalculateTime(13000));
                                break;
                            case 4:
                                l_Garrosh->AI()->Talk(Talks::TALK_INTRO03);

                                obj->m_Events.AddEvent(new garrosh_fight_introduction(obj, 5), obj->m_Events.CalculateTime(23000));
                                break;
                            case 5:
                                l_Thrall->AI()->Talk(Talks::TALK_THRALL_INTRO02);
                                l_Thrall->CastSpell(l_Thrall, Spells::SPELL_CALL_OF_THE_ELEMENTS);

                                obj->m_Events.AddEvent(new garrosh_fight_introduction(obj, 6), obj->m_Events.CalculateTime(10000));
                                break;
                            case 6:
                                l_Garrosh->AI()->Talk(Talks::TALK_INTRO04);

                                obj->m_Events.AddEvent(new garrosh_fight_introduction(obj, 7), obj->m_Events.CalculateTime(16500));
                                break;
                                // Missing gripped aura -- Temporary
                            case 7:
                                l_Thrall->RemoveAllAuras(); // -- needs to be tiobjd.
                                l_Thrall->AI()->Talk(Talks::TALK_THRALL_INTRO03);
                                obj->m_Events.AddEvent(new garrosh_fight_introduction(obj, 8), obj->m_Events.CalculateTime(4500));
                                break;
                            case 8:
                                l_Thrall->GetMotionMaster()->MovePoint(0, l_PositionThrallMovementPreFightWithGarrosh);
                                l_Garrosh->GetMotionMaster()->MovePoint(0, l_PositionTGarroshMovementPreFightWithGarrosh);
                                obj->m_Events.AddEvent(new garrosh_fight_introduction(obj, 9), obj->m_Events.CalculateTime(9000));
                                break;
                            case 9:
                                l_Thrall->CastSpell(l_Thrall, Spells::SPELL_GARROSH_THRALL_SPARRING);
                                l_Garrosh->CastSpell(l_Garrosh, Spells::SPELL_DEFEND_AGAINST_THRALL);
                                obj->m_Events.AddEvent(new garrosh_fight_introduction(obj, 10), obj->m_Events.CalculateTime(4000));
                                break;
                            case 10:
                                //l_Garrosh->CastSpell(l_Thrall, Spells::SPELL_CAST_THRALL_AWAY);
                                l_Thrall->SetUInt32Value(UNIT_NPC_EMOTESTATE, 444);
                                l_Garrosh->CastSpell(l_Thrall, 17748);

                                l_Thrall->GetMotionMaster()->MoveKnockbackFrom(l_Garrosh->GetPositionX(), l_Garrosh->GetPositionY(), 30.0f, 10.0f);
                                obj->m_Events.AddEvent(new garrosh_fight_introduction(obj, 11), obj->m_Events.CalculateTime(4000));
                                obj->m_Events.AddEvent(new garrosh_fight_introduction(obj, 900), obj->m_Events.CalculateTime(3000));
                                break;
                            case 11:
                                l_Garrosh->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE);
                                l_Garrosh->SetReactState(REACT_AGGRESSIVE);

                                l_Thrall->CastSpell(l_Thrall, Spells::SPELL_THRALL_STUNNED_FROM_HIT);
                                obj->m_Events.AddEvent(new garrosh_fight_introduction(obj, 12), obj->m_Events.CalculateTime(25000));
                                break;
                                // This where Thralls escape to the upper platform.
                            case 12:
                                l_Thrall->CastSpell(l_PositionThrall.GetPositionX(), l_PositionThrall.GetPositionY(), l_PositionThrall.GetPositionZ(), Spells::SPELL_ASTRAL_RECALL, false);
                                obj->m_Events.AddEvent(new garrosh_fight_introduction(obj, 13), obj->m_Events.CalculateTime(3000));
                                break;
                            case 13:
                                l_Thrall->NearTeleportTo(l_PositionThrall.GetPositionX(), l_PositionThrall.GetPositionY(), l_PositionThrall.GetPositionZ(), l_Thrall->GetOrientation());
                                break;
                            case 900: // Removes thrall's strangulate emote / temporary
                                l_Thrall->SetUInt32Value(UNIT_NPC_EMOTESTATE, 1);
                                l_Thrall->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
                                break;
                            }

                            return true;
                        }
                    }
                }
            }
        }

        return true;
    }
private:
    Creature* storm;
    Unit* obj;
    int modifier;
    int Event;
};

class garrosh_spell_self_event : public BasicEvent
{
public:
    explicit garrosh_spell_self_event(Unit* unit, int SpellId) : obj(unit), modifier(SpellId)
    {
    }

    bool Execute(uint64 /*currTime*/, uint32 /*diff*/)
    {
        if (obj->GetTypeId() == TYPEID_PLAYER)
            return false;

        if (obj)
        {
            if (InstanceScript* l_Instance = obj->GetInstanceScript())
            {
                obj->CastSpell(obj, modifier);
            }
        }
        return true;
    }
private:
    Unit* obj;
    int modifier;
    int Event;
};

class garrosh_close_doors : public BasicEvent
{
public:
    explicit garrosh_close_doors(GameObject* _obj) : obj(_obj)
    {
    }

    bool Execute(uint64 /*currTime*/, uint32 /*diff*/)
    {
        if (!obj)
            return false;

        if (obj->GetTypeId() != TYPEID_GAMEOBJECT)
            return false;

        if (InstanceScript* m_Instance = obj->GetInstanceScript())
        {
            if (GameObject* l_GameObject = obj->ToGameObject())
            {
                // Yshaaraj Poop
                if (Creature * l_GarroshHellScream = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_GARROSH_HEART_OF_YSHAARAJ)))
                {
                    l_GameObject->SetLootState(GO_READY);
                    l_GameObject->UseDoorOrButton(10000, false, l_GarroshHellScream);
                }
            }
        }
        return true;
    }
private:
    GameObject* obj;
    int Event;
};

class garrosh_change_react_state : public BasicEvent
{
public:
    explicit garrosh_change_react_state(Unit* unit, int SpellId) : obj(unit), modifier(SpellId)
    {
    }

    bool Execute(uint64 /*currTime*/, uint32 /*diff*/)
    {
        if (obj->GetTypeId() == TYPEID_PLAYER)
            return false;

        if (obj)
        {
            if (InstanceScript* l_Instance = obj->GetInstanceScript())
            {
                obj->ToCreature()->SetReactState(REACT_DEFENSIVE);
                obj->RemoveUnitMovementFlag(MOVEMENTFLAG_ROOT);

                obj->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                obj->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);

                if (obj->ToCreature()->AI())
                    obj->ToCreature()->AI()->Talk(Talks::TALK_GARROSH_SPELL09);
            }
        }
        return true;
    }
private:
    Unit* obj;
    int modifier;
    int Event;
};

// Garrosh Hellscream -
class boss_garrosh_hellscream : public CreatureScript
{
public:
    boss_garrosh_hellscream() : CreatureScript("boss_garrosh_hellscream") { }

    struct boss_garrosh_hellscreamAI : public BossAI
    {
        boss_garrosh_hellscreamAI(Creature* creature) : BossAI(creature, eData::DATA_GARROSH_HELLSCREAM)
        {
            m_Instance = creature->GetInstanceScript();

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);

            HandleHallsDoorsAcitvation();
        }

        InstanceScript* m_Instance;
        uint32 m_embodiedCounter;
        uint32 i_Location;
        uint32 m_RandomIntermissionTalk;
        uint32 m_IntermissionOccured;
        uint16 m_GateIndentifier;

        uint8 m_PhaseCounter;

        std::list<uint64> l_ListPlayers;
        std::list<uint64> l_ListPlayersGarroshPower;
        bool m_Intro;
        bool m_IntermissionActive;
        bool m_NullDamage;
        bool m_ArsenalComment;

        void Reset() override
        {
            _Reset();
            events.Reset();

            l_ListPlayersGarroshPower.clear();

            m_NullDamage = false;
            m_ArsenalComment = false;
            m_IntermissionActive = false;
            m_GateIndentifier = 0;
            m_IntermissionOccured = 0;
            i_Location = 1;
            m_embodiedCounter = 0;
            m_RandomIntermissionTalk = 4000;
            m_PhaseCounter = Phases::PHASE_THE_TRUE_HORDE;
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
            summons.DespawnAll();

            // Activate doors
            HandleHallsDoorsAcitvation();

            uint32 l_Entry[7] = { Creatures::CREATURE_ANNHLIATE_TRIGGER, Creatures::CREATURE_DESECRATED_WERAPON_TRIGGER, Creatures::CREATURE_FARSEER_WOLF_RIDER, Creatures::CREATURE_VICIOUS_WAR_WOLF, Creatures::CREATURE_KORKRON_WARBRINGER, Creatures::CREATURE_SIEGE_ENGINEER, Creatures::CREATURE_MINION_YSHAARJ };

            for (auto itr : l_Entry)
            {
                DespawnCreaturesInArea(itr, me);
            }

            me->SetObjectScale(1.0);

            // Teleports players back incase a wipe.
            if (m_PhaseCounter >= Phases::PHASE_REALM_OF_YSHAARJ)
            {
                std::list<Player*> l_ListPlayers;
                me->GetPlayerListInGrid(l_ListPlayers, 500.0f);

                if (l_ListPlayers.empty())
                    return;

                for (auto itr : l_ListPlayers)
                {
                    itr->NearTeleportTo(l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetPositionX(), l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetPositionY(), l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetPositionZ(), l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetOrientation());
                }
            }

            if (m_Instance)
            {
                m_Instance->SetBossState(eData::DATA_GARROSH_HELLSCREAM, EncounterState::FAIL);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_GARROSH_POWER);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_ENTER_THE_REALM_OF_YSHAARAJ_SCREEN_EFFECT);

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            }
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            if ((spell->Id == 144989 || spell->Id == 145033) && target && target->IsInWorld())
            me->CastSpell(target, Spells::SPELL_EMPOWERED_WHIRLING_CORRUPTION_TRIGGER_MISSILE, true);
        }

        // Upon combat, close doors, upon reset open doors
        void HandleHallsDoorsAcitvation()
        {
            std::list<GameObject*> l_ListGameObjects;
            me->GetGameObjectListWithEntryInGrid(l_ListGameObjects, GameObjects::GAMEOBJECT_ENTRANCE, 1000.0f);

            if (l_ListGameObjects.empty())
                return;

            for (auto itr : l_ListGameObjects)
            {
                itr->SetLootState(GO_READY);
                itr->UseDoorOrButton(10000, false, me);
            }
        }

        void EnterCombat(Unit* attacker) override
        {
            if (m_Instance)
            {
                m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);
                DoZoneInCombat();
            }

            HandleHallsDoorsAcitvation();

            Talk(Talks::TALK_AGGRO);

            events.ScheduleEvent(Events::EVENT_ENGINEERS, 50 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(Events::EVENT_HELLSCREAMS_WARSONG, 25 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(Events::EVENT_DESECRATE, 10 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(Events::EVENT_KORKRON_WARBRINGERS, 30 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(Events::EVENT_FARSEER, 45 * TimeConstants::IN_MILLISECONDS);
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            summons.Despawn(summon);
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TypeID::TYPEID_PLAYER)
            {
                switch (urand(0, 2 ? m_PhaseCounter > 3 : 1))
                {
                case 0:
                    Talk(Talks::TALK_GARROSH_KILL01);
                    break;
                case 1:
                    Talk(Talks::TALK_GARROSH_KILL02);
                    break;
                case 2:
                    Talk(Talks::TALK_GARROSH_KILL03);
                    break;
                }
            }
        }

        void JustDied(Unit* killer) override
        {
            if (m_Instance)
            {
                m_Instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                m_Instance->SetBossState(DATA_GARROSH_HELLSCREAM, DONE);
            }

            me->RemoveAllAuras();

            HandleHallsDoorsAcitvation();

            _JustDied();
            Talk(Talks::TALK_DEATH01);
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
            case Actions::ACTION_TELEPORT:
            {
                if (Creature* l_Heart = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(DATA_GARROSH_HEART_OF_YSHAARAJ)))
                {
                    if (l_Heart->AI())
                    {
                            std::list <Player*> l_ListPlayers;
                            std::list<Creature*> m_ListCreatures;
                            me->GetPlayerListInGrid(l_ListPlayers, 500.0f);

                            DespawnCreaturesInArea(Creatures::CREATURE_KORKRON_IRON_STAR, me);
                            DespawnCreaturesInArea(Creatures::CREATURE_FARSEER_WOLF_RIDER, me);
                            DespawnCreaturesInArea(Creatures::CREATURE_KORKRON_WARBRINGER, me);

                            RespawnCreatures(Creatures::CREATURE_EMBODIED_FEAR, me);
                            RespawnCreatures(Creatures::CREATURE_EMBODIED_DOUBT, me);
                            RespawnCreatures(Creatures::CREATURE_EMBODIED_DESPAIR, me);

                            m_IntermissionActive = true;

                            if (l_ListPlayers.empty())
                                return;

                            if (!me->GetMap()->IsHeroic())
                            {
                                i_Location = urand(1, 3);
                            }

                            /*if (m_Instance != nullptr)
                            {
                                UnitList targets;
                                JadeCore::AnyUnitHavingBuffInObjectRangeCheck u_check(me, me, 100, Spells::SPELL_HELLSCREAMS_WARSONG, true);
                                JadeCore::UnitListSearcher<JadeCore::AnyUnitHavingBuffInObjectRangeCheck> searcher(me, targets, u_check);
                                me->VisitNearbyObject(100, searcher);

                                for (UnitList::const_iterator it = targets.begin(); it != targets.end(); ++it)
                                {
                                    if (!(*it) || !(*it)->HasAura(Spells::SPELL_HELLSCREAMS_WARSONG))
                                        return;

                                    (*it)->RemoveAura(Spells::SPELL_HELLSCREAMS_WARSONG);
                                }
                            }*/

                            // Garrosh react passive untill all adds dies.
                            me->SetReactState(ReactStates::REACT_PASSIVE);
                            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_IMMUNE_TO_PC);
                            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
                            me->AttackStop();
                            me->AddAura(Spells::SPELL_TEMPORARY_STRANGULATED_COSMETIC, me);
                            me->SummonCreature(Creatures::CREATURE_AURA_OF_YSHAARAJ, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                            me->SetCanFly(false);
                            me->SetDisableGravity(false);

                            switch (i_Location)
                            {
                            case Locations::LOCATION_TERRACE_OF_ENDLESS_SPRINGS:
                                m_embodiedCounter = 30;

                                me->NearTeleportTo(l_PositionTerraceOfEndlessSpringsGarrosh.GetPositionX(), l_PositionTerraceOfEndlessSpringsGarrosh.GetPositionY(), l_PositionTerraceOfEndlessSpringsGarrosh.GetPositionZ(), l_PositionJadeTempleGarrosh.GetOrientation());
                                me->GetCreatureListWithEntryInGrid(m_ListCreatures, Creatures::CREATURE_EMBODIED_DOUBT, 1000.0f);
                                break;
                            case Locations::LOCATION_JADE_TEMPLE:
                                m_embodiedCounter = 12;

                                me->NearTeleportTo(l_PositionJadeTempleGarrosh.GetPositionX(), l_PositionJadeTempleGarrosh.GetPositionY(), l_PositionJadeTempleGarrosh.GetPositionZ(), l_PositionJadeTempleGarrosh.GetOrientation());
                                me->GetCreatureListWithEntryInGrid(m_ListCreatures, Creatures::CREATURE_EMBODIED_DOUBT, 1000.0f);
                                break;
                            case Locations::LOCATION_RED_CRANE:
                                m_embodiedCounter = 2;

                                me->NearTeleportTo(l_PositionRedCraneGarrosh.GetPositionX(), l_PositionRedCraneGarrosh.GetPositionY(), l_PositionRedCraneGarrosh.GetPositionZ(), l_PositionRedCraneGarrosh.GetOrientation());
                                me->GetCreatureListWithEntryInGrid(m_ListCreatures, Creatures::CREATURE_EMBODIED_DESPAIR, 1000.0f);
                                break;
                            }

                            events.Reset();

                            if (!m_ListCreatures.empty())
                            {
                                for (auto itr : m_ListCreatures)
                                {
                                    itr->Respawn();
                                }
                            }

                            // Reset Walls
                            std::list<GameObject*> l_ListGameObjects;
                            me->GetGameObjectListWithEntryInGrid(l_ListGameObjects, GameObjects::GAMEOBJECT_GARROSH_ENCOUNTER_SHA_VORTEX_COLLISION, 1000.0f);

                            if (!l_ListGameObjects.empty())
                            {
                                for (auto itr : l_ListGameObjects)
                                {
                                    itr->SetLootState(GO_READY);
                                    itr->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                                }
                            }

                            m_IntermissionOccured++;

                            for (auto itr : l_ListPlayers)
                            {
                                itr->CastSpell(itr, Spells::SPELL_GARROSH_POWER);
                                itr->AddAura(144954, itr); // Buff

                                switch (i_Location)
                                {
                                case Locations::LOCATION_TERRACE_OF_ENDLESS_SPRINGS:
                                    itr->NearTeleportTo(l_PositionTerraceOfEndlessSpringsPlayers.GetPositionX(), l_PositionTerraceOfEndlessSpringsPlayers.GetPositionY(), l_PositionTerraceOfEndlessSpringsPlayers.GetPositionZ(), l_PositionTerraceOfEndlessSpringsPlayers.GetOrientation());
                                    break;
                                case Locations::LOCATION_JADE_TEMPLE:
                                    itr->NearTeleportTo(l_PositionJadeTemplePlayers.GetPositionX(), l_PositionJadeTemplePlayers.GetPositionY(), l_PositionJadeTemplePlayers.GetPositionZ(), l_PositionJadeTemplePlayers.GetOrientation());
                                    break;
                                case Locations::LOCATION_RED_CRANE:
                                    itr->NearTeleportTo(l_PositionRedCranePlayers.GetPositionX(), l_PositionRedCranePlayers.GetPositionY(), l_PositionRedCranePlayers.GetPositionZ(), l_PositionRedCranePlayers.GetOrientation());
                                    break;
                                }
                            }
                        }
                    break;
                }
            }
            case Actions::ACTION_RESET_COUNTER_DEAD_EMBODIEDS:
            {
                me->CastSpell(me, Spells::SPELL_YSHAARJ_PROTECTION_AURA);
                std::list<Player*> l_ListPlayers;
                me->GetPlayerListInGrid(l_ListPlayers, 2.0f);

                if (l_ListPlayers.empty())
                    return;

                for (auto itr : l_ListPlayers)
                {
                    if (itr->HasAura(Spells::SPELL_GARROSH_POWER))
                    {
                        if (Aura* l_Aura = itr->GetAura(Spells::SPELL_GARROSH_POWER))
                        {
                            // Resets Garrosh Power
                            ModifyGarroshPride(0, itr);
                        }
                    }
                }

                break;
            }
            case Actions::ACTION_EMBODIED_COUNT_DEATH:
            {
                if (m_embodiedCounter >= 1)
                {
                    m_embodiedCounter--;
                }

                if (m_embodiedCounter <= 0)
                {
                    // Yshaaraj Poop
                    if (Creature * l_HeartOfYshaarajTrigger = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_GARROSH_HEART_OF_YSHAARAJ)))
                    {
                        l_HeartOfYshaarajTrigger->CastStop();
                        l_HeartOfYshaarajTrigger->RemoveAllAuras();
                    }

                    uint32 l_SpellIds[4] = { Spells::SPELL_TEMPORARY_STRANGULATED_COSMETIC, Spells::SPELL_YSHAARJ_PROTECTION, Spells::SPELL_YSHAARJ_PROTECTION_AURA, Spells::SPELL_SHA_CHANNEL_2ND_PHASE };
                    // Remove all 2nd phase auras
                    for (uint32 i = 0; i <= 3; i++)
                    {
                        me->RemoveAura(l_SpellIds[i]);
                    }

                    if (m_IntermissionOccured <= 3)
                        me->m_Events.AddEvent(new garrosh_intermission_introduction(me, 3), me->m_Events.CalculateTime(irand(80000, 100000)));

                    me->SetReactState(ReactStates::REACT_DEFENSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
                    me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
                    me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
                    me->SetSpeed(MOVE_RUN, 0.0f);

                    DespawnCreaturesInArea(Creatures::CREATURE_AURA_OF_YSHAARAJ, me);

                    events.RescheduleEvent(Events::EVENT_ANNHILIATE, 5 * TimeConstants::IN_MILLISECONDS);
                    events.RescheduleEvent(Events::EVENT_PORT_TO_GARROSH_HALL, 25 * TimeConstants::IN_MILLISECONDS);

                }
                break;
            }
            }
        }

        void RegeneratePower(Powers power, int32& value)
        {
            if (power != POWER_ENERGY)
                return;

            if (m_embodiedCounter > 1)
            {
                value = 1;
            }
            else
                value = 0;

            int32 val = me->GetPower(POWER_ENERGY);
            if (val + value > 100)
                val = 100;
            else
                val += value;


            std::list<Player*> l_listPlayers;
            me->GetPlayerListInGrid(l_listPlayers, 1000.0f);

            // Sets Garrosh Power
            if (!l_listPlayers.empty())
            {
                for (auto itr : l_listPlayers)
                {
                    ModifyGarroshPride(me->GetInt32Value(UNIT_FIELD_POWER), itr);
                }
            }

            me->SetInt32Value(UNIT_FIELD_POWER, val);
        }

        void SummonKorkronSoldiers()
        {
            if (m_Instance == nullptr)
                return;

            Talk(Talks::TALK_GARROSH_SPELL03);

            if (GameObject * l_RightDoor = m_Instance->instance->GetGameObject(m_Instance->GetObjectGuid(DATA_RIGHT_DOOR_GARROSH)))
            {
                if (GameObject * l_LeftDoor = m_Instance->instance->GetGameObject(m_Instance->GetObjectGuid(DATA_LEFT_DOOR_GARROSH)))
                {
                    // Left Side
                    l_LeftDoor->SetLootState(LootState::GO_READY);
                    l_LeftDoor->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                    me->m_Events.AddEvent(new garrosh_close_doors(l_LeftDoor), me->m_Events.CalculateTime(8000));

                    for (int i = 0; i < 3; i++)
                    {
                        Creature* l_Korkron = me->SummonCreature(Creatures::CREATURE_KORKRON_WARBRINGER, l_PositionLeftDoor.GetPositionX() + frand(1.5f, 3.0f), l_PositionLeftDoor.GetPositionY() + frand(1.5f, 3.0f), l_PositionLeftDoor.GetPositionZ(), l_PositionLeftDoor.GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);

                        if (l_Korkron)
                        {
                            l_Korkron->GetMotionMaster()->MovePoint(2, 1030.901f, -5704.937f, -317.689f);
                        }
                    }

                    // Right Side
                    l_RightDoor->SetLootState(LootState::GO_READY);
                    l_RightDoor->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                    me->m_Events.AddEvent(new garrosh_close_doors(l_RightDoor), me->m_Events.CalculateTime(8000));

                    for (int i = 0; i < 3; i++)
                    {
                        Creature* l_Korkron = me->SummonCreature(Creatures::CREATURE_KORKRON_WARBRINGER, l_PositionRightDoor.GetPositionX() + frand(1.5f, 3.0f), l_PositionRightDoor.GetPositionY() + frand(1.5f, 3.0f), l_PositionRightDoor.GetPositionZ(), l_PositionRightDoor.GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);

                        if (l_Korkron)
                        {
                            l_Korkron->GetMotionMaster()->MovePoint(1, 1074.017f, -5563.278f, -317.688f);
                        }
                    }
                }

                m_GateIndentifier = 0 ? m_GateIndentifier = 1 : 1;
            }
        }

        void SummonFarseer()
        {
            if (m_Instance == nullptr)
                return;

            Talk(Talks::TALK_GARROSH_SPELL04);

            if (GameObject * l_RightDoor = m_Instance->instance->GetGameObject(m_Instance->GetObjectGuid(DATA_RIGHT_DOOR_GARROSH)))
            {
                if (GameObject * l_LeftDoor = m_Instance->instance->GetGameObject(m_Instance->GetObjectGuid(DATA_LEFT_DOOR_GARROSH)))
                {
                    switch (m_GateIndentifier)
                    {
                    case 0:
                    {
                        // Left Side
                        l_LeftDoor->SetLootState(LootState::GO_READY);
                        l_LeftDoor->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                        me->m_Events.AddEvent(new garrosh_close_doors(l_LeftDoor), me->m_Events.CalculateTime(8000));

                        Creature* l_Farseer = me->SummonCreature(Creatures::CREATURE_FARSEER_WOLF_RIDER, l_PositionLeftDoor.GetPositionX(), l_PositionLeftDoor.GetPositionY(), l_PositionLeftDoor.GetPositionZ(), l_PositionLeftDoor.GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);

                        if (l_Farseer)
                        {
                            l_Farseer->GetMotionMaster()->MovePoint(2, 1030.901f, -5704.937f, -317.689f);
                        }

                        break;
                    }
                    case 1:
                    {
                        // Right Side
                        l_RightDoor->SetLootState(LootState::GO_READY);
                        l_RightDoor->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                        me->m_Events.AddEvent(new garrosh_close_doors(l_RightDoor), me->m_Events.CalculateTime(8000));

                        Creature* l_Farseer = me->SummonCreature(Creatures::CREATURE_FARSEER_WOLF_RIDER, l_PositionRightDoor.GetPositionX(), l_PositionRightDoor.GetPositionY(), l_PositionRightDoor.GetPositionZ(), l_PositionRightDoor.GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);

                        if (l_Farseer)
                        {
                            l_Farseer->GetMotionMaster()->MovePoint(1, 1074.017f, -5563.278f, -317.688f);
                        }
                        break;
                    }
                    }

                    m_GateIndentifier = 0 ? m_GateIndentifier = 1 : 1;
                }
            }
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (m_NullDamage || m_IntermissionActive)
                damage = 0;

            switch (m_PhaseCounter)
            {
            case Phases::PHASE_THE_TRUE_HORDE:
                if (me->GetHealthPct() <= 10 && m_PhaseCounter == Phases::PHASE_THE_TRUE_HORDE)
                {
                    m_PhaseCounter = Phases::PHASE_REALM_OF_YSHAARJ;

                    Talk(Talks::TALK_DEATH);
                    events.Reset();

                    me->AttackStop();

                    if (m_Instance != nullptr)
                    {
                        m_Instance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_HELLSCREAMS_WARSONG);
                    }

                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_DISABLE_MOVE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC);

                    me->SetPower(POWER_ENERGY, 0);
                    me->SetInt32Value(UNIT_FIELD_POWER, 0);
                    me->SetMaxPower(POWER_ENERGY, 100);
                    me->SetInt32Value(UNIT_FIELD_MAXPOWER, 100);
                    me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN | UNIT_FLAG2_REGENERATE_POWER);

                    me->m_Events.AddEvent(new garrosh_intermission_introduction(me, 0), me->m_Events.CalculateTime(4500));
                }
                break;
            case Phases::PHASE_POWER_OF_YSHARJ:
                if (me->GetHealthPct() <= 10 && m_PhaseCounter == Phases::PHASE_POWER_OF_YSHARJ)
                {
                    events.Reset();
                    // Handle 4th event.
                    m_NullDamage = true;

                    me->m_Events.KillAllEvents(true);

                    if (m_IntermissionActive)
                    {
                        // Renewing the Iron Stars
                        std::list<Player*> l_ListPlayers;
                        me->GetPlayerListInGrid(l_ListPlayers, 300.0f);

                        if (l_ListPlayers.empty())
                            return;

                        for (auto itr : l_ListPlayers)
                        {
                            itr->NearTeleportTo(l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetPositionX(), l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetPositionY(), -307.205f, l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetOrientation());
                        }

                        m_IntermissionActive = false;
                    }

                    Talk(Talks::TALK_GARROSH_SPELL09);

                    me->SetReactState(REACT_PASSIVE);

                    me->GetMotionMaster()->MovePoint(0, l_PositionGarroshHellScreamSecondPhasePositionPreConvert);
                    me->m_Events.AddEvent(new garrosh_spell_self_event(me, Spells::SPELL_TRANSITION_THIRD_PHASE), me->m_Events.CalculateTime(6000));
                    me->m_Events.AddEvent(new garrosh_spell_self_event(me, Spells::SPELL_TRANSITION_THIRD_PHASE_CHANGE_FORM), me->m_Events.CalculateTime(11000));
                    me->m_Events.AddEvent(new garrosh_spell_self_event(me, Spells::SPELL_TRANSITION_THIRD_PHASE_VISUAL), me->m_Events.CalculateTime(8000));


                    events.ScheduleEvent(Events::EVENT_EMPOWERED_DESECRATE, 20 * TimeConstants::IN_MILLISECONDS);
                    events.ScheduleEvent(Events::EVENT_TOUCH_OF_YSHAARJ, 60 * TimeConstants::IN_MILLISECONDS);
                    events.ScheduleEvent(Events::EVENT_GRIPPING_DESPAIR, 12 * TimeConstants::IN_MILLISECONDS);
                    events.ScheduleEvent(Events::EVENT_WHIRLING_CORRUPTION, 35 * TimeConstants::IN_MILLISECONDS);
                    events.ScheduleEvent(Events::EVENT_MY_WORLD_REMOVE_FLAGS, 20 * TimeConstants::IN_MILLISECONDS);

                    m_PhaseCounter = Phases::PHASE_MY_WORlD;
                }
                break;
            case Phases::PHASE_MY_WORlD:
                // Do nothing, just die.
                break;
            };
        }

        void CheckCorruptionLevels()
        {
            // Shows markers
            if ((me->GetInt32Value(UNIT_FIELD_POWER) >= 100))
            {
                if (!me->HasAura(Spells::SPELL_EMPOWERED_GRIPPING_DESPAIR_AURA_DUMMY))
                    me->CastSpell(me, Spells::SPELL_EMPOWERED_GRIPPING_DESPAIR_AURA_DUMMY);
            }
            else if ((me->GetInt32Value(UNIT_FIELD_POWER) >= 75))
            {
                if (!me->HasAura(Spells::SPELL_EMPOWERED_DESECRATE_APPLY_AURA))
                    me->CastSpell(me, Spells::SPELL_EMPOWERED_DESECRATE_APPLY_AURA);
            }
            else if ((me->GetInt32Value(UNIT_FIELD_POWER) >= 45))
            {
                if (!me->HasAura(Spells::SPELL_EMPOWERED_TOUCH_OF_YSHRAAJ))
                    me->CastSpell(me, Spells::SPELL_EMPOWERED_TOUCH_OF_YSHRAAJ);
            }
            else if ((me->GetInt32Value(UNIT_FIELD_POWER) >= 25))
            {
                if (!me->HasAura(Spells::SPELL_EMPOWERED_WHIRL_CORRUPTION_SPELL_AURA_DUMMY))
                    me->CastSpell(me, Spells::SPELL_EMPOWERED_WHIRL_CORRUPTION_SPELL_AURA_DUMMY);
            }
        }

        void IntermissionRandomSayings(const uint32 diff)
        {
            Creature* l_NearestHearth = NULL;

            if (l_NearestHearth = me->FindNearestCreature(Creatures::CREATURE_HEART_OF_YSHAARAJ, 100.0f, true))
            {
                if (m_IntermissionActive)
                {
                    if (m_RandomIntermissionTalk <= diff)
                    {
                        switch (urand(0, 6))
                        {
                        case 0:
                            l_NearestHearth->AI()->Talk(Talks::TALK_YSHAARAJ_01);
                            break;
                        case 1:
                            l_NearestHearth->AI()->Talk(Talks::TALK_YSHAARAJ_02);
                            break;
                        case 2:
                            l_NearestHearth->AI()->Talk(Talks::TALK_YSHAARAJ_03);
                            break;
                        case 3:
                            l_NearestHearth->AI()->Talk(Talks::TALK_YSHAARAJ_04);
                            break;
                        case 4:
                            l_NearestHearth->AI()->Talk(Talks::TALK_YSHAARAJ_05);
                            break;
                        case 5:
                            l_NearestHearth->AI()->Talk(Talks::TALK_YSHAARAJ_06);
                            break;
                        }

                        m_RandomIntermissionTalk = 14000;
                    }
                    else
                        m_RandomIntermissionTalk -= diff;
                }
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            // Add indentifiers for auras
            CheckCorruptionLevels();

            // Random Intermission talks by Yshaaraj
            IntermissionRandomSayings(diff);

            if (m_IntermissionActive && m_embodiedCounter > 0)
            {
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                me->StopMoving();
            }

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case Events::EVENT_MY_WORLD_REMOVE_FLAGS:
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_ROOT);
                me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_STATE_CANNOT_TURN);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_DEFENSIVE);
                me->setFaction(16);
                me->Attack(me->GetVictim(), true);

                Talk(Talks::TALK_EVENT_7);

                // Grants him 25% hp, hardcoded
                me->SetHealth(me->GetHealth() + (me->GetMaxHealth() * 0.25));
                me->SetObjectScale(2.0f);

                Position l_Position;
                me->GetPosition();
                me->UpdatePosition(l_Position, true);
                //me->SendMovementFlagUpdate();
                break;
                // Phase 1
            case Events::EVENT_DESECRATE:
            {
                if (Unit* l_Target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 200.0f, true))
                {
                    if (m_PhaseCounter == 1)
                    {
                        me->CastSpell(l_Target, Spells::SPELL_DESECRATE_TRIGGER_MISSILE);
                    }
                    else if (m_PhaseCounter == 2)
                    {
                        // Phase 3
                        if (me->GetUInt32Value(UNIT_FIELD_POWER) >= 75) // ?? possible only once, dunno yet. creating it on heroic
                        {
                            // Cast Empowered Desecrate
                            me->CastSpell(l_Target, Spells::SPELL_EMPOWER_DESECRATE_TRIGGER_MISSILE);
                        }
                        else
                        {
                            me->CastSpell(l_Target, Spells::SPELL_DESECRATE_TRIGGER_MISSILE);
                        }
                    }
                    else if (m_PhaseCounter == 3)
                    {
                        me->CastSpell(l_Target, Spells::SPELL_EMPOWER_DESECRATE_TRIGGER_MISSILE);
                    }
                }

                events.ScheduleEvent(Events::EVENT_DESECRATE, 25 * TimeConstants::IN_MILLISECONDS);
                break;
            }
            case Events::EVENT_HELLSCREAMS_WARSONG:
                DoCastAOE(Spells::SPELL_HELLSCREAMS_WARSONG);

                Talk(Talks::TALK_GARROSH_SPELL05);

                events.ScheduleEvent(Events::EVENT_HELLSCREAMS_WARSONG, 80 * TimeConstants::IN_MILLISECONDS);
                break;
            case Events::EVENT_KORKRON_WARBRINGERS:
                SummonKorkronSoldiers();

                events.ScheduleEvent(Events::EVENT_KORKRON_WARBRINGERS, 70 * TimeConstants::IN_MILLISECONDS);
                break;
            case Events::EVENT_FARSEER:
                SummonFarseer();

                events.ScheduleEvent(Events::EVENT_FARSEER, 90 * TimeConstants::IN_MILLISECONDS);
                break;
            case Events::EVENT_ENGINEERS:
            {
                Talk(Talks::TALK_GARROSH_SPELL01);

                // Clean previous triggers
                DespawnCreaturesInArea(Creatures::CREATURE_KORKRON_IRON_STAR, me);
                DespawnCreaturesInArea(Creatures::CREATURE_STAR_EXPLOSIVE_TRIGGER, me);

                events.ScheduleEvent(Events::EVENT_ENGINEERS, 50 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(Events::EVENT_ENGINEERS + 1, 4 * TimeConstants::IN_MILLISECONDS);
                break;
            }
            case Events::EVENT_ENGINEERS + 1:
                // Right = 1; Left = 2
                for (int i = 0; i < 2; i++)
                {
                    Creature* l_Engineer = me->SummonCreature(Creatures::CREATURE_SIEGE_ENGINEER, l_PositionEngineers[i], TEMPSUMMON_MANUAL_DESPAWN);

                    if (l_Engineer)
                    {
                        l_Engineer->GetMotionMaster()->MovePoint(Movements::MOVEMENT_SIEGE_ENGINEER_IRON_STAR_ACTIVATION, l_PositionEngineersMovement[i].GetPositionX(), l_PositionEngineersMovement[i].GetPositionY(), l_PositionEngineersMovement[i].GetPositionZ());
                    }

                    Creature* l_IronStar = l_Engineer->SummonCreature(Creatures::CREATURE_KORKRON_IRON_STAR, l_PositionIronStars[i], TEMPSUMMON_MANUAL_DESPAWN);

                    if (l_IronStar && l_IronStar->GetAI())
                    {
                        l_IronStar->GetAI()->DoAction(i);
                    }
                }
                break;

                // Phase 2
            case Events::EVENT_ANNHILIATE:
                if (Unit* l_Target = me->GetVictim())
                {
                    me->CastSpell(l_Target, Spells::SPELL_ANNIHILATE_DAMAGE);
                }

                events.ScheduleEvent(Events::EVENT_ANNHILIATE, 5 * TimeConstants::IN_MILLISECONDS);
                break;

            case Events::EVENT_PORT_TO_GARROSH_HALL:
            {
                std::list<Player*> l_ListPlayers;
                me->GetPlayerListInGrid(l_ListPlayers, 300.0f);

                if (l_ListPlayers.empty())
                    return;

                for (auto itr : l_ListPlayers)
                {
                    itr->NearTeleportTo(l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetPositionX(), l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetPositionY(), -307.205f, l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetOrientation());
                }

                me->NearTeleportTo(l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetPositionX(), l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetPositionY(), -307.205f, l_PositionGarroshHellScreamSecondPhasePositionPreConvert.GetOrientation());

                m_IntermissionActive = false;

                m_PhaseCounter = Phases::PHASE_POWER_OF_YSHARJ;

                events.Reset();

                events.ScheduleEvent(Events::EVENT_WHIRLING_CORRUPTION, 20 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(Events::EVENT_TOUCH_OF_YSHAARJ, 40 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(Events::EVENT_DESECRATE, 10 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(Events::EVENT_GRIPPING_DESPAIR, 6 * TimeConstants::IN_MILLISECONDS);

                if (m_Instance != nullptr)
                {
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_GARROSH_POWER);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_ENTER_THE_REALM_OF_YSHAARAJ_SCREEN_EFFECT);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_REALM_OF_YSHAARAJ_DEBUFF_PURPLE);
                }

                me->SetReactState(REACT_DEFENSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_STATE_CANNOT_TURN);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_ROOT);
                me->SetSpeed(MOVE_RUN, 1.12f);

                switch (i_Location)
                {
                case Locations::LOCATION_TERRACE_OF_ENDLESS_SPRINGS:
                    AttackStop(Creatures::CREATURE_EMBODIED_FEAR, me);
                    break;
                case Locations::LOCATION_RED_CRANE:
                    AttackStop(Creatures::CREATURE_EMBODIED_DESPAIR, me);
                    break;
                case Locations::LOCATION_JADE_TEMPLE:
                    AttackStop(Creatures::CREATURE_EMBODIED_DOUBT, me);
                    break;
                }

                if (me->GetMap()->IsHeroic())
                    i_Location++;
                else
                    i_Location = Locations::LOCATION_THIRD_PHASE;

                // Starts Intermission again
               // if (i_Location < 4) // 3 max intermissios
                    //events.ScheduleEvent(Events::EVENT_TURN_PHASE_2_2, 40 * TimeConstants::IN_MILLISECONDS);
                break;
            }

            // Phase 3
            case Events::EVENT_WHIRLING_CORRUPTION:
                Talk(Talks::TALK_GARROSH_SPELL06);

                if (m_PhaseCounter == 2)
                {
                    if (me->GetUInt32Value(UNIT_FIELD_POWER) >= 25) // ?? possible only once, dunno yet. creating it on heroic
                    {
                        // Empowered Whirling Corruption
                        me->CastSpell(me, Spells::SPELL_EMPOWERED_WHIRL_CORRUPTION_DUMMY);
                    }
                    else
                    {
                        me->CastSpell(me, Spells::SPELL_WHIRLLING_CORRUPTION_PERIODIC_SPELL);
                    }
                }
                else if (m_PhaseCounter == 3)
                {
                    me->CastSpell(me, Spells::SPELL_EMPOWERED_WHIRL_CORRUPTION_DUMMY);
                }
                break;
            case Events::EVENT_TOUCH_OF_YSHAARJ:
            {
                std::list<Player*> l_TouchOfYsyhaarajTargets;
                me->GetPlayerListInGrid(l_TouchOfYsyhaarajTargets, 100.0f);

                if (l_TouchOfYsyhaarajTargets.empty())
                    return;

                std::list<Player*>::const_iterator it = l_TouchOfYsyhaarajTargets.begin();
                std::advance(it, urand(0, l_TouchOfYsyhaarajTargets.size() - 2 ? l_TouchOfYsyhaarajTargets.size() >= 2 : 1));

                if (m_PhaseCounter == 2)
                {
                    if (me->GetUInt32Value(UNIT_FIELD_POWER) >= 50) // ?? possible only once, dunno yet. creating it on heroic
                    {
                        me->CastSpell((*it), Spells::SPELL_TOUCH_OF_YSHRAAJ_SCRIPT_EFFECT, true);
                    }
                    else
                    {
                        me->CastSpell((*it), Spells::SPELL_TOUCH_OF_YSHRAAJ_SCHOOL_ABSORB, true);
                    }
                }
                else if (m_PhaseCounter == 3)
                {
                    me->CastSpell((*it), Spells::SPELL_EMPOWERED_TOUCH_OF_YSHRAAJ);
                }
                break;
            }
            case Events::EVENT_GRIPPING_DESPAIR:

                if (m_PhaseCounter == 2)
                {
                    if (Unit* l_Target = me->GetVictim())
                    {
                        // Empowered Gripping Despair
                        if (me->GetUInt32Value(UNIT_FIELD_POWER) >= 100) // ?? possible only once, dunno yet. creating it on heroic
                        {
                            me->CastSpell(l_Target, Spells::SPELL_EMPOWERED_GRIPPING_DESPAIR_PERIODIC_DAMAGE);
                        }
                        else
                        {
                            me->CastSpell(l_Target, Spells::SPELL_GRIPPING_DESPAIR_PERIODIC_DAMAGE);
                        }
                    }
                }
                else if (m_PhaseCounter == 3)
                {
                    if (Unit* l_Target = me->GetVictim())
                    {
                        me->CastSpell(l_Target, Spells::SPELL_EMPOWERED_GRIPPING_DESPAIR_PERIODIC_DAMAGE);
                    }
                }
                break;

            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_garrosh_hellscreamAI(creature);
    }
};

// Empowered Whirling Corruption - 145037
class spell_whirling_corruption : public SpellScriptLoader
{
public:
    spell_whirling_corruption() : SpellScriptLoader("spell_whirling_corruption") { }

    class spell_whirling_corruptionAuraScript : public AuraScript
    {
        PrepareAuraScript(spell_whirling_corruptionAuraScript);

        void HandlePeriodic(AuraEffect* /*aurEff*/)
        {
            PreventDefaultAction();

            if (!GetCaster())
                return;

            if (GetSpellInfo() && GetSpellInfo()->Id == 145037) // Empowered
            {
                GetCaster()->CastSpell(GetCaster(), 144994, true);
            }
            else
            {
                GetCaster()->CastSpell(GetCaster(), 144994, true);
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_whirling_corruptionAuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_whirling_corruptionAuraScript();
    }
};

// Touch of Yshaaraj - 145096
class spell_touch_of_yshaaraj_proc_two : public SpellScriptLoader
{
public:
    spell_touch_of_yshaaraj_proc_two() : SpellScriptLoader("spell_touch_of_yshaaraj_proc_two") { }

    class spell_touch_of_yshaaraj_proc_twoAuraScript : public AuraScript
    {
        PrepareAuraScript(spell_touch_of_yshaaraj_proc_twoAuraScript);

        uint32 RandomWalkingTimer;

        bool Load()
        {
            RandomWalkingTimer = 3000;
            return true;
        }

        void OnUpdate(uint32 diff, AuraEffect* aurEff)
        {
            if (GetTarget())
            {
                if (GetCaster())
                {
                    // Remove buff when target is below 20 precent
                    if (GetTarget()->GetHealthPct() <= 20)
                    {
                        GetTarget()->RemoveAura(SPELL_TOUCH_OF_YSHRAAJ_SCRIPT_EFFECT);
                        GetTarget()->RemoveAura(SPELL_EMPOWERED_TOUCH_OF_YSHRAAJ);
                    }

                    // Diff to cast Touch of Yshaaraj
                    if (RandomWalkingTimer <= diff)
                    {
                        UnitList targets;
                        //JadeCore::AnyPlayerHavingBuffInObjectRangeCheck u_check(GetTarget(), GetTarget(), 300.0f, Spells::SPELL_EMPOWERED_TOUCH_OF_YSHRAAJ ? GetSpellInfo()->Id == SPELL_EMPOWERED_TOUCH_OF_YSHRAAJ : SPELL_TOUCH_OF_YSHRAAJ_SCRIPT_EFFECT, true);
                        //JadeCore::UnitListSearcher<JadeCore::AnyPlayerHavingBuffInObjectRangeCheck> searcher(GetTarget(), targets, u_check);
                        //GetTarget()->VisitNearbyObject(300.0f, searcher);

                        std::list<Unit*>::const_iterator it = targets.begin();
                        std::advance(it, urand(0, targets.size() - 1));

                        if (GetSpellInfo() && GetSpellInfo()->Id == Spells::SPELL_EMPOWERED_TOUCH_OF_YSHRAAJ)
                        {
                            GetTarget()->CastSpell((*it), Spells::SPELL_EMPOWERED_TOUCH_OF_YSHRAAJ);
                        }
                        else
                        {

                            GetTarget()->CastSpell((*it), Spells::SPELL_TOUCH_OF_YSHRAAJ_SCRIPT_EFFECT, false);
                        }

                        RandomWalkingTimer = 3000;
                    }
                    else
                        RandomWalkingTimer -= diff;
                }
            }
        }

        void HandleOnApply(const AuraEffect* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* l_Caster = GetCaster())
            {
                if (Unit* l_Target = GetTarget())
                {
                    OriginalFaction = l_Target->getFaction();

                    l_Target->SetCharmedBy(l_Caster, CHARM_TYPE_CHARM);
                    l_Target->setFaction(GetCaster()->getFaction());
                    l_Target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                    l_Target->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);

                    if (GetSpellInfo()->Id == Spells::SPELL_EMPOWERED_TOUCH_OF_YSHRAAJ)
                    {
                        l_Target->RemoveAura(Spells::SPELL_TOUCH_OF_YSHRAAJ_SCHOOL_ABSORB01);
                        l_Target->AddAura(Spells::SPELL_EMPOWERED_TOUCH_OF_YSHRAAJ_DEBUFF, l_Target);
                    }
                }
            }
        }

        void OnRemove(const AuraEffect* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* l_Caster = GetCaster())
            {
                if (Unit* l_Target = GetTarget())
                {
                    l_Target->RemoveFlag(UNIT_FIELD_FLAGS,   UNIT_FLAG_DISABLE_MOVE);
                    l_Target->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
                    l_Target->RemoveCharmedBy(l_Caster);
                    l_Target->RemoveCharmAuras();

                    if (OriginalFaction != NULL)
                        l_Target->setFaction(OriginalFaction);
                }
            }
        }

    private:
        uint32 OriginalFaction;

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_touch_of_yshaaraj_proc_twoAuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_touch_of_yshaaraj_proc_twoAuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_SPEED_ALWAYS, AURA_EFFECT_HANDLE_REAL);
            //OnEffectUpdate += AuraEffectUpdateFn(spell_touch_of_yshaaraj_proc_twoAuraScript::OnUpdate, EFFECT_6, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_touch_of_yshaaraj_proc_twoAuraScript();
    }
};

// not sure if needed
// Enter the realm of Y'sharaaj
class spell_enter_the_realm_yshaaraj : public SpellScriptLoader
{
public:
    spell_enter_the_realm_yshaaraj() : SpellScriptLoader("spell_enter_the_realm_yshaaraj") { }

    class spell_enter_the_realm_yshaaraj_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_enter_the_realm_yshaaraj_AuraScript);

        void OnRemove(const AuraEffect* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetTarget())
            {
                if (GetCaster())
                {
                    if (InstanceScript* m_Instance = GetTarget()->GetInstanceScript())
                    {
                        if (Creature * l_Garrosh = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_GARROSH_HELLSCREAM)))
                        {
                            if (l_Garrosh->GetAI())
                                l_Garrosh->GetAI()->DoAction(Actions::ACTION_BACKPORT);
                        }
                    }
                }
            }
        }

        void Register()
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_enter_the_realm_yshaaraj_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_SPEED_ALWAYS, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_enter_the_realm_yshaaraj_AuraScript();
    }
};

// Empowered Gripping Despair - 145195  // 149252
class spell_empowered_gripping_despair : public SpellScriptLoader
{
public:
    spell_empowered_gripping_despair() : SpellScriptLoader("spell_empowered_gripping_despair") { }

    class spell_empowered_gripping_despair_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_empowered_gripping_despair_AuraScript);

        void OnRemove(const AuraEffect* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetTarget())
            {
                if (GetCaster())
                {
                    GetCaster()->CastSpell(GetTarget(), Spells::SPELL_EXPLOSIDE_DESPAIR_DAMAGE);
                    GetCaster()->CastSpell(GetTarget(), Spells::SPELL_EXPLOSIDE_DESPAIR_MECHANIC_PRECENT);
                }
            }
        }

        void Register()
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_empowered_gripping_despair_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_empowered_gripping_despair_AuraScript();
    }
};

// Gripping Despair Damage - 145199
class spell_empowered_gripping_despair_debuff : public SpellScriptLoader
{
public:
    spell_empowered_gripping_despair_debuff() : SpellScriptLoader("spell_empowered_gripping_despair_debuff") { }

    class spell_empowered_gripping_despair_debuff_AuraScript : public SpellScript
    {
        PrepareSpellScript(spell_empowered_gripping_despair_debuff_AuraScript);

        void HandleDamageCalc(SpellEffIndex /*effIndex*/)
        {
            if (GetCaster())
            {
                if (GetHitUnit())
                {
                    if (!GetSpellInfo())
                        return;

                    if (Aura* l_Aura = GetHitUnit()->GetAura(Spells::SPELL_EXPLOSIDE_DESPAIR_MECHANIC_PRECENT))
                    {
                        float l_Stacks = float(l_Aura->GetStackAmount() / 100);
                        uint32 l_Damage = GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints;

                        l_Damage += (uint32(float(l_Stacks)) * l_Damage);

                        SetHitDamage(l_Damage);

                        l_Damage = 0;
                    }
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_empowered_gripping_despair_debuff_AuraScript::HandleDamageCalc, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_empowered_gripping_despair_debuff_AuraScript();
    }
};

// Desecrate - 144745
class spell_desecrate_dummy : public SpellScriptLoader
{
public:
    spell_desecrate_dummy() : SpellScriptLoader("spell_desecrate_dummy") { }

    class spell_desecrate_dummy_Spellscript : public SpellScript
    {
        PrepareSpellScript(spell_desecrate_dummy_Spellscript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* l_Unit = GetCaster())
            {
                if (Unit* l_Target = GetExplTargetUnit())
                {
                    l_Unit->CastSpell(l_Target, Spells::SPELL_DESECRATE_TRIGGER_MISSILE);
                }
            }
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_desecrate_dummy_Spellscript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_desecrate_dummy_Spellscript();
    }
};

// Empowering Corruption - 145043
class spell_empowering_corruption_filter : public SpellScriptLoader
{
public:
    spell_empowering_corruption_filter() : SpellScriptLoader("spell_empowering_corruption_filter") { }

    class spell_empowering_corruption_filter_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_empowering_corruption_filter_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (!GetCaster())
                return;

            targets.clear();

            std::list<Creature*> l_TempoListCreatures;
            GetCaster()->GetCreatureListWithEntryInGrid(l_TempoListCreatures, Creatures::CREATURE_MINION_YSHAARJ, 2.0f);

            if (l_TempoListCreatures.empty())
                return;

            for (auto itr : l_TempoListCreatures)
            {
                targets.push_back(itr->ToUnit());
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_empowering_corruption_filter_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_empowering_corruption_filter_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_empowering_corruption_filter_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_empowering_corruption_filter_SpellScript();
    }
};

// Enter Realm of Y'Shaarj - 144867
class spell_enter_realm_of_yshaarj_purple_beam : public SpellScriptLoader
{
public:
    spell_enter_realm_of_yshaarj_purple_beam() : SpellScriptLoader("spell_enter_realm_of_yshaarj_purple_beam") { }

    class spell_enter_realm_of_yshaarj_purple_beam_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_enter_realm_of_yshaarj_purple_beam_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (!GetCaster())
                return;

            targets.clear();

            InstanceScript* l_Instance = GetCaster()->GetInstanceScript();

            if (l_Instance != nullptr)
            {
                if (Creature * l_Garrosh = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_GARROSH_HELLSCREAM)))
                {
                    std::list<Player*> l_ListPlayers;
                    GetCaster()->GetPlayerListInGrid(l_ListPlayers, 300.0f);

                    if (!l_ListPlayers.empty())
                    {
                        for (auto itr : l_ListPlayers)
                        {
                            targets.push_back(itr);
                        }
                    }

                    targets.push_back(l_Garrosh);
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_enter_realm_of_yshaarj_purple_beam_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_enter_realm_of_yshaarj_purple_beam_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_enter_realm_of_yshaarj_purple_beam_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_enter_realm_of_yshaarj_purple_beam_SpellScript::FilterTargets, EFFECT_3, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_enter_realm_of_yshaarj_purple_beam_SpellScript();
    }
};

// Ancsetral Healing - 144867
class spell_ancsetral_healing : public SpellScriptLoader
{
public:
    spell_ancsetral_healing() : SpellScriptLoader("spell_ancsetral_healing") { }

    class spell_ancsetral_healing_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_ancsetral_healing_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (!GetCaster())
                return;

            targets.remove_if(CheckIfGarroshAndRemove());
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ancsetral_healing_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_TARGET_ALLY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_ancsetral_healing_SpellScript();
    }
};

// Hellscream's Warsong -  144821
class spell_hellscream_warsong_filter : public SpellScriptLoader
{
public:
    spell_hellscream_warsong_filter() : SpellScriptLoader("spell_hellscream_warsong_filter") { }

    class spell_hellscream_warsong_filter_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hellscream_warsong_filter_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (!GetCaster())
                return;

            targets.remove_if(CheckIfPlayerAndRemove());
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hellscream_warsong_filter_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hellscream_warsong_filter_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hellscream_warsong_filter_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_hellscream_warsong_filter_SpellScript();
    }
};


// Embodied Fear - 72237
class garrosh_hellscream_embodied_fear : public CreatureScript
{
public:
    garrosh_hellscream_embodied_fear() : CreatureScript("garrosh_hellscream_embodied_fear") { }

    struct siege_of_orgrimmar_creaturesAI : public BossAI
    {
        siege_of_orgrimmar_creaturesAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;

        void Reset() override
        {
            events.Reset();
            me->setFaction(16);

            me->SetReactState(REACT_AGGRESSIVE);
        }

        void JustDied(Unit* killer) override
        {
            if (roll_chance_i(20))
            {
                // Drops on the dead embodied
                me->CastSpell(me, Spells::SPELL_COURAGE_TRIGGER_MISSILE, true);
            }

            if (Creature * l_Garrosh = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_GARROSH_HELLSCREAM)))
            {
                if (l_Garrosh->GetAI())
                    l_Garrosh->GetAI()->DoAction(Actions::ACTION_EMBODIED_COUNT_DEATH);
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new siege_of_orgrimmar_creaturesAI(creature);
    }
};

// Embodied Doubt - 72236
class garrosh_hellscream_embodied_doubt : public CreatureScript
{
public:
    garrosh_hellscream_embodied_doubt() : CreatureScript("garrosh_hellscream_embodied_doubt") { }

    struct siege_of_orgrimmar_creaturesAI : public BossAI
    {
        siege_of_orgrimmar_creaturesAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;

        void Reset() override
        {
            events.Reset();
            me->setFaction(16);

            me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* attacker) override
        {
            events.ScheduleEvent(Events::EVENT_EMBODIED_DOUBT, urand(8 * TimeConstants::IN_MILLISECONDS, 20 * TimeConstants::IN_MILLISECONDS));
        }

        void JustDied(Unit* killer) override
        {
            Position l_Position;
            l_Position = me->GetRandomNearPosition(frand(5.0f, 8.0f));

            // Missile at random location
            me->CastSpell(l_Position.GetPositionX(), l_Position.GetPositionY(), l_Position.GetPositionZ(), Spells::SPELL_CONSUMED_FAITH_TRIGGER_MISSILE, true);

            if (Creature * l_Garrosh = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_GARROSH_HELLSCREAM)))
            {
                if (l_Garrosh->GetAI())
                    l_Garrosh->GetAI()->DoAction(Actions::ACTION_EMBODIED_COUNT_DEATH);
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case Events::EVENT_EMBODIED_DOUBT:
                if (Unit* l_Target = me->GetVictim())
                    me->CastSpell(l_Target, Spells::SPELL_EMBODIED_DOUBT_DAMAGE);

                events.ScheduleEvent(Events::EVENT_EMBODIED_DOUBT, 10 * TimeConstants::IN_MILLISECONDS);
                break;
            }

            DoMeleeAttackIfReady();
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new siege_of_orgrimmar_creaturesAI(creature);
    }
};

// Embodied Despair - 72238
class garrosh_hellscream_embodied_despair : public CreatureScript
{
public:
    garrosh_hellscream_embodied_despair() : CreatureScript("garrosh_hellscream_embodied_despair") { }

    struct siege_of_orgrimmar_creaturesAI : public BossAI
    {
        siege_of_orgrimmar_creaturesAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;

        void Reset() override
        {
            events.Reset();
            me->setFaction(16);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* attacker) override
        {
            events.ScheduleEvent(Events::EVENT_ULTIMATE_DESPAIR, urand(8 * TimeConstants::IN_MILLISECONDS, 20 * TimeConstants::IN_MILLISECONDS));
        }

        void JustDied(Unit* killer) override
        {
            Position l_Position;
            l_Position = me->GetRandomNearPosition(frand(5.0f, 8.0f));

            // Missile at random location
            me->CastSpell(l_Position.GetPositionX(), l_Position.GetPositionY(), l_Position.GetPositionZ(), Spells::SPELL_CONSUMED_HOPE_TRIGGER, true);

            if (Creature * l_Garrosh = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_GARROSH_HELLSCREAM)))
            {
                if (l_Garrosh->GetAI())
                    l_Garrosh->GetAI()->DoAction(Actions::ACTION_EMBODIED_COUNT_DEATH);
            }

            // Ultimate Despair
            if (Creature* l_Despair = me->FindNearestCreature(Creatures::CREATURE_EMBODIED_DESPAIR, 100.0f, true))
                l_Despair->CastSpell(l_Despair, Spells::SPELL_ULTIMATE_DESPAIR_TRIGGER_SPELL);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new siege_of_orgrimmar_creaturesAI(creature);
    }
};

// Thrall - 73483
class garrosh_hellscream_creature_thrall : public CreatureScript
{
public:
    garrosh_hellscream_creature_thrall() : CreatureScript("garrosh_hellscream_creature_thrall") { }

    struct siege_of_orgrimmar_creaturesAI : public BossAI
    {
        siege_of_orgrimmar_creaturesAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
            m_Intro = false;
        }

        InstanceScript* m_Instance;
        bool m_Intro;

        void Reset() override
        {
            me->setFaction(35);
            me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            //if (me->FindNearestPlayer(10.0f, true) && !m_Intro)
           // {
                m_Intro = true;
                me->m_Events.AddEvent(new garrosh_fight_introduction(me, 0), me->m_Events.CalculateTime(500));
            //}
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new siege_of_orgrimmar_creaturesAI(creature);
    }
};

// Iron Star - 73059
class garrosh_hellscream_creature_iron_star : public CreatureScript
{
public:
    garrosh_hellscream_creature_iron_star() : CreatureScript("garrosh_hellscream_creature_iron_star") { }

    struct siege_of_orgrimmar_creaturesAI : public ScriptedAI
    {
        siege_of_orgrimmar_creaturesAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
            m_Activated = false;
        }

        InstanceScript* m_Instance;
        uint32 m_PDiff;
        uint64 m_Trigger = NULL;
        bool m_Activated;

        void Reset() override
        {
            m_PDiff = 1000;
            me->setFaction(35);
            me->SetObjectScale(2.0f);
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);

            me->SetSpeed(MOVE_RUN, 3.8f);
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
                case Actions::ACTION_IRON_STAR_LEFT:
                {
                    Creature* l_Temp = me->SummonCreature(Creatures::CREATURE_STAR_EXPLOSIVE_TRIGGER, 1037.116f, -5737.422f, -317.671f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);

                    if (l_Temp)
                        m_Trigger = l_Temp->GetGUID();
                    break;
                }
                case Actions::ACTION_IRON_STAR_RIGHT:
                {
                    Creature* l_Temp = me->SummonCreature(Creatures::CREATURE_STAR_EXPLOSIVE_TRIGGER, 1109.485f, -5543.685f, -317.671f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);

                    if (l_Temp)
                        m_Trigger = l_Temp->GetGUID();
                    break;
                }
                case Actions::ACTION_ACTIVATE_IRON_STAR:
                {
                    if (m_Trigger)
                    {
                        if (Creature* l_Target = ObjectAccessor::GetCreature(*me, GetGUID(m_Trigger)))
                        {
                            me->GetMotionMaster()->MovePoint(0, l_Target->GetPositionX(), l_Target->GetPositionY(), l_Target->GetPositionZ());
                            me->CastSpell(me, Spells::SPELL_IRON_STAR_IMPACT_AURA_VISUAL_FULL);

                            m_Activated = true;
                        }
                    }
                    break;
                }
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            // Fix orientation
            if (Creature* l_Target = ObjectAccessor::GetCreature(*me, GetGUID(m_Trigger)))
            {
                if (!me->isMoving() && m_Trigger && l_Target->IsInWorld() && !m_Activated)
                {
                    me->SetFacingToObject(l_Target);
                }
            }

            if (m_Activated)
            {
                if (Creature* l_Target = ObjectAccessor::GetCreature(*me, GetGUID(m_Trigger)))
                {
                    if (me->IsWithinDistInMap(l_Target, 1.5f))
                    {
                        me->CastSpell(me, Spells::SPELL_EXPLODING_IRON_STAR);

                        me->Kill(me);
                        me->DespawnOrUnsummon(2000);
                        m_Activated = false;
                    }
                }

                if (m_PDiff <= diff)
                {
                    // Kokron Creatures
                    std::list<Creature*> l_ListCreatures;
                    me->GetCreatureListWithEntryInGrid(l_ListCreatures, Creatures::CREATURE_KORKRON_WARBRINGER, 24.0f);
                    me->GetCreatureListWithEntryInGrid(l_ListCreatures, Creatures::CREATURE_FARSEER_WOLF_RIDER, 24.0f);

                    if (!l_ListCreatures.empty())
                    {
                        for (auto itr : l_ListCreatures)
                        {
                            itr->CastSpell(itr, Spells::SPELL_IRON_STAR_IMPACT_DAMAGE_KNOCKBACK);
                        }
                    }

                    // Players
                    std::list<Player*> l_ListPlayers;
                    me->GetPlayerListInGrid(l_ListPlayers, 24.0f);

                    if (!l_ListPlayers.empty())
                    {
                        for (auto itr : l_ListPlayers)
                        {
                            itr->CastSpell(itr, Spells::SPELL_IRON_STAR_IMPACT_DAMAGE_KNOCKBACK);
                        }
                    }

                    m_PDiff = 1000;
                }
                else
                {
                    m_PDiff -= diff;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new siege_of_orgrimmar_creaturesAI(creature);
    }
};

// Korkron Warbringer - 71979
class garrosh_hellscream_korkron_warbringer : public CreatureScript
{
public:
    garrosh_hellscream_korkron_warbringer() : CreatureScript("garrosh_hellscream_korkron_warbringer") { }

    struct siege_of_orgrimmar_creaturesAI : public BossAI
    {
        siege_of_orgrimmar_creaturesAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;

        void Reset() override
        {
            events.Reset();
            DoZoneInCombat();
            me->setFaction(16);

            events.ScheduleEvent(Events::EVENT_MOVE_TO_GARROSH, 5 * TimeConstants::IN_MILLISECONDS);
        }

        void EnterCombat(Unit* attacker) override
        {
            events.ScheduleEvent(Events::EVENT_HAMSTRING, urand(8 * TimeConstants::IN_MILLISECONDS, 20 * TimeConstants::IN_MILLISECONDS));
        }

        void OnAddThreat(Unit* victim, float& fThreat, SpellSchoolMask /*schoolMask*/, SpellInfo const* /*threatSpell*/)
        {
            if (me->GetMap()->IsHeroic())
                fThreat = 0;
            return;
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case Events::EVENT_HAMSTRING:
                {
                    if (!UpdateVictim())
                        return;

                    if (Unit* l_Target = me->GetVictim())
                        me->CastSpell(l_Target, Spells::SPELL_HAMSTRING);

                    events.ScheduleEvent(Events::EVENT_HAMSTRING, urand(8 * TimeConstants::IN_MILLISECONDS, 20 * TimeConstants::IN_MILLISECONDS));
                    break;
                }
                case Events::EVENT_MOVE_TO_GARROSH:
                    if (Creature * l_Garrosh = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_GARROSH_HELLSCREAM)))
                        me->GetMotionMaster()->MovePoint(3, l_Garrosh->GetPositionX(), l_Garrosh->GetPositionY(), l_Garrosh->GetPositionZ());
                    break;
            }

            DoMeleeAttackIfReady();
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new siege_of_orgrimmar_creaturesAI(creature);
    }
};

// Siege Engineer - 71984
class garrosh_hellscream_creature_siege_engineer : public CreatureScript
{
public:
    garrosh_hellscream_creature_siege_engineer() : CreatureScript("garrosh_hellscream_creature_siege_engineer") { }

    struct siege_of_orgrimmar_creaturesAI : public BossAI
    {
        siege_of_orgrimmar_creaturesAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint64 m_IronStarGuid;

        void Reset() override
        {
            events.Reset();
            me->setFaction(16);

            me->SetReactState(ReactStates::REACT_PASSIVE);
        }

        void JustDied(Unit* killer) override
        {
            events.CancelEvent(Events::EVENT_ACTIVATE_IRON_STAR01);

            me->CastStop();
            me->DespawnOrUnsummon(1000);
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);

            m_IronStarGuid = summon->GetGUID();

            events.ScheduleEvent(Events::EVENT_ACTIVATE_IRON_STAR, 6 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_ACTIVATE_IRON_STAR01, 21 * TimeConstants::IN_MILLISECONDS);
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case Events::EVENT_ACTIVATE_IRON_STAR01:
                {
                    me->DespawnOrUnsummon(20000);

                    if (Creature* l_IronStar = ObjectAccessor::GetCreature(*me, GetGUID(m_IronStarGuid)))
                    {
                        if (l_IronStar->GetAI())
                            l_IronStar->GetAI()->DoAction(ACTION_ACTIVATE_IRON_STAR);
                    }
                    break;
                }
                case Events::EVENT_ACTIVATE_IRON_STAR:
                {
                    if (Creature* l_IronStar = ObjectAccessor::GetCreature(*me, GetGUID(m_IronStarGuid)))
                    {
                        me->CastSpell(l_IronStar, Spells::SPELL_ACTIVATE_IRON_STAR);
                        break;
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new siege_of_orgrimmar_creaturesAI(creature);
    }
};

// Farseer Wolf Rider - 71983 / Vicious War Wolf - 71994
class garrosh_hellscream_farseer_wolf_rider : public CreatureScript
{
public:
    garrosh_hellscream_farseer_wolf_rider() : CreatureScript("garrosh_hellscream_farseer_wolf_rider") { }

    struct siege_of_orgrimmar_creaturesAI : public BossAI
    {
        siege_of_orgrimmar_creaturesAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;

        void Reset() override
        {
            events.Reset();
            DoZoneInCombat();
            me->setFaction(16);
            me->CastSpell(me, 100333, true); // Hacked
            events.ScheduleEvent(Events::EVENT_MOVE_TO_GARROSH, 6 * TimeConstants::IN_MILLISECONDS);
        }

        void EnterCombat(Unit* attacker) override
        {
            events.ScheduleEvent(Events::EVENT_CHAIN_LIGHTNING, urand(17 * TimeConstants::IN_MILLISECONDS, 25 * TimeConstants::IN_MILLISECONDS));
            events.ScheduleEvent(Events::EVENT_ANCESTRAL_CHAIN_HEAL, urand(15 * TimeConstants::IN_MILLISECONDS, 22 * TimeConstants::IN_MILLISECONDS));
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            if (spell && spell->HasEffect(SPELL_EFFECT_INTERRUPT_CAST))
            {
                if (!me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                me->CastSpell(me, Spells::SPELL_ANCESTRAL_FURY);
            }
        }

        void JustDied(Unit* killer) override
        {
            me->RemoveAura(100333);
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case Events::EVENT_ANCESTRAL_CHAIN_HEAL:
                {
                    if (!UpdateVictim())
                        return;

                    Unit* l_Target = NULL;

                    if (l_Target = me->FindNearestCreature(CREATURE_KORKRON_WARBRINGER, 30.0f, true))
                    if (l_Target && l_Target->IsInWorld())
                        me->CastSpell(l_Target, Spells::SPELL_ANCESTRAL_CHAIN_HEAL);

                    events.ScheduleEvent(Events::EVENT_ANCESTRAL_CHAIN_HEAL, urand(20 * TimeConstants::IN_MILLISECONDS, 25 * TimeConstants::IN_MILLISECONDS));
                    break;
                }
                case Events::EVENT_CHAIN_LIGHTNING:
                {
                    if (!UpdateVictim())
                        return;

                    if (Unit* l_Target = me->GetVictim())
                        me->CastSpell(l_Target, Spells::SPELL_CHAIN_LIGHTNING);

                    events.ScheduleEvent(Events::EVENT_CHAIN_LIGHTNING, urand(12 * TimeConstants::IN_MILLISECONDS, 16 * TimeConstants::IN_MILLISECONDS));
                    break;
                }
                case Events::EVENT_MOVE_TO_GARROSH:
                    if (Creature * l_Garrosh = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_GARROSH_HELLSCREAM)))
                    me->GetMotionMaster()->MovePoint(3, l_Garrosh->GetPositionX(), l_Garrosh->GetPositionY(), l_Garrosh->GetPositionZ());
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new siege_of_orgrimmar_creaturesAI(creature);
    }
};

// Vicious War Wolf - 71994
class boss_farseer_vicious_war_wolf : public CreatureScript
{
public:
    boss_farseer_vicious_war_wolf() : CreatureScript("boss_farseer_vicious_war_wolf") { }

    struct boss_farseer_vicious_war_wolfAI : public BossAI
    {
        boss_farseer_vicious_war_wolfAI(Creature* creature) : ScriptedAI(creature), mVehicle(creature->GetVehicleKit())
        {
            m_Instance = me->GetInstanceScript();
        }

        Vehicle* mVehicle;
        InstanceScript* m_Instance;

        void Reset() override
        {
            events.Reset();
            ASSERT(mVehicle);

            me->SetReactState(ReactStates::REACT_AGGRESSIVE);

            events.ScheduleEvent(Events::EVENT_MOVE_TO_GARROSH, 5 * TimeConstants::IN_MILLISECONDS);
        }

        void UpdateAI(uint32 const diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::EVENT_MOVE_TO_GARROSH:
                        if (Creature * l_Garrosh = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_GARROSH_HELLSCREAM)))
                            me->GetMotionMaster()->MovePoint(3, l_Garrosh->GetPositionX(), l_Garrosh->GetPositionY(), l_Garrosh->GetPositionZ());
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_farseer_vicious_war_wolfAI(creature);
    }
};

// Desecrated Weapon - 72154
class garrosh_hellscream_creature_desecrated_weapon : public CreatureScript
{
public:
    garrosh_hellscream_creature_desecrated_weapon() : CreatureScript("garrosh_hellscream_creature_desecrated_weapon") { }

    struct siege_of_orgrimmar_creaturesAI : public BossAI
    {
        siege_of_orgrimmar_creaturesAI(Creature* creature) : ScriptedAI(creature), m_AreatriggerGUID(0)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint32 m_nextSizePct;

        uint32 m_DesecrateDebuff;
        uint64 m_AreatriggerGUID = NULL;
        float m_Radius;

        void Reset() override
        {
            events.Reset();
            me->setFaction(16);
            DoZoneInCombat();

            m_Radius = 6.0f;
            m_nextSizePct = 90;
            m_DesecrateDebuff = 2000;

            me->SetReactState(REACT_PASSIVE);
            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);

            me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);

            me->SetHealth(me->GetMaxHealth());

            me->CastSpell(me, Spells::SPELL_DESECRATED_WEAPON);
            me->CastSpell(me, Spells::SPELL_DESECRATED_PURPLE_GROUND);
        }

        void SetGUID(uint64 guid, int32 /*param*/) override
        {
            if (m_AreatriggerGUID == NULL && guid != NULL)
            {
                if (ObjectAccessor::GetAreaTrigger(*me, GetGUID(m_AreatriggerGUID)))
                {
                    m_AreatriggerGUID = guid;
                }
            }
        }

        void HackVisuals() // Stupid hack, but seems to work
        {
            me->RemoveAura(144760);
            me->AddAura(144760, me);
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (damage == 0)
                return;

            // afraid
            if (m_nextSizePct)
            {
                if (me->HealthBelowPctDamaged(m_nextSizePct, damage))
                {
                    if (AreaTrigger* l_AreaTrigger = ObjectAccessor::GetAreaTrigger(*me, GetGUID(m_AreatriggerGUID)))
                    {
                        l_AreaTrigger->SetObjectScale((l_AreaTrigger->GetObjectSize() - 0.10f));
                        m_nextSizePct -= 10;

                        m_Radius -= 0.5f;

                        if (m_nextSizePct < 10)
                        {
                            me->DespawnOrUnsummon(500);
                            l_AreaTrigger->Remove();
                        }
                    }
                }
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (m_DesecrateDebuff <= diff)
            {
                std::list<Player*> pl_list;
                me->GetPlayerListInGrid(pl_list, 6.0f);

                if (pl_list.empty())
                    return;

                for (auto itr : pl_list)
                {
                    itr->CastSpell(itr, 144762); // Dot

                    if (itr->GetAura(144762))
                    {
                        Aura* l_Aura = itr->GetAura(144762);

                        l_Aura->SetDuration(1);
                    }
                }
            }
            else
            {
                m_DesecrateDebuff -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new siege_of_orgrimmar_creaturesAI(creature);
    }
};

// Desecrated Weapon - 72198
class garrosh_hellscream_creature_empowered_desecrated_weapon : public CreatureScript
{
public:
    garrosh_hellscream_creature_empowered_desecrated_weapon() : CreatureScript("garrosh_hellscream_creature_empowered_desecrated_weapon") { }

    struct siege_of_orgrimmar_creaturesAI : public BossAI
    {
        siege_of_orgrimmar_creaturesAI(Creature* creature) : ScriptedAI(creature), m_AreatriggerGUID(0)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint32 m_nextSizePct;

        uint32 m_DesecrateDebuff;
        uint64 m_AreatriggerGUID = NULL;
        float m_Radius;

        void Reset() override
        {
            events.Reset();
            me->setFaction(16);
            DoZoneInCombat();

            m_DesecrateDebuff = 2000;
            m_nextSizePct = 90;
            m_Radius = 6.0f;

            me->SetReactState(REACT_PASSIVE);
            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);

            me->SetHealth(me->GetMaxHealth());

            me->CastSpell(me, Spells::SPELL_DESECRATED_WEAPON);
            me->CastSpell(me, Spells::SPELL_DESECRATED_PURPLE_GROUND);
        }

        void SetGUID(uint64 guid, int32 /*param*/) override
        {
            if (m_AreatriggerGUID == NULL && guid != NULL)
            {
                if (ObjectAccessor::GetAreaTrigger(*me, GetGUID(m_AreatriggerGUID)))
                {
                    m_AreatriggerGUID = guid;
                }
            }
        }

        void RegeneratePower(Powers power, int32& value) override
        {
            if (power != POWER_ENERGY)
                return;

            if (!me->GetMap()->IsHeroic())
                return;

            int32 val = me->GetPower(POWER_ENERGY);
            if (val + value > 100)
                val = 100;
            else
                val += value;

            me->SetInt32Value(UNIT_FIELD_POWER, val);
        }

        void HackVisuals() // Stupid hack, but seems to work
        {
            me->RemoveAura(144760);
            me->AddAura(144760, me);
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            // afraid
            damage = 0;
        }

        void UpdateAI(const uint32 diff) override
        {
            // Currently is out of usage.
            //HackVisuals();

            if (m_DesecrateDebuff <= diff)
            {
                std::list<Player*> pl_list;
                me->GetPlayerListInGrid(pl_list, 6.0f);

                if (pl_list.empty())
                    return;

                for (auto itr : pl_list)
                {
                    itr->CastSpell(itr, 144762); // Dot

                    if (itr->GetAura(144762))
                    {
                        Aura* l_Aura = itr->GetAura(144762);

                        l_Aura->SetDuration(1);
                    }
                }
            }
            else
            {
                m_DesecrateDebuff -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new siege_of_orgrimmar_creaturesAI(creature);
    }
};

// Minion Of Yshaaraj - 72272
class garrosh_hellscream_creature_minion_of_yshaaraj : public CreatureScript
{
public:
    garrosh_hellscream_creature_minion_of_yshaaraj() : CreatureScript("garrosh_hellscream_creature_minion_of_yshaaraj") { }

    struct siege_of_orgrimmar_creaturesAI : public BossAI
    {
        siege_of_orgrimmar_creaturesAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;

        void Reset() override
        {
            events.Reset();
            me->setFaction(16);
        }

        void JustDied(Unit* killer) override
        {
            events.ScheduleEvent(Events::EVENT_EMPOWERING_CORRUPTION, 1 * TimeConstants::IN_MILLISECONDS);
        }

        void RegeneratePower(Powers power, int32& value) override
        {
            if (power != POWER_ENERGY)
                return;

            if (!me->GetMap()->IsHeroic())
                return;

            int32 val = me->GetPower(POWER_ENERGY);
            if (val + value > 100)
                val = 100;
            else
                val += value;

            if (me->GetMap()->IsHeroic())
            {
                if (val >= 100)
                {
                    val = 0;
                    events.ScheduleEvent(Events::EVENT_EMPOWERING_CORRUPTION, 1 * TimeConstants::IN_MILLISECONDS);
                }
            }

            me->SetInt32Value(UNIT_FIELD_POWER, val);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case Events::EVENT_EMPOWERING_CORRUPTION:
                me->CastSpell(me, Spells::SPELL_EMPOWERING_CORRUPTION);
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new siege_of_orgrimmar_creaturesAI(creature);
    }
};

// Heart of Yshaaraj - 72215
class garrosh_hellscream_creature_heart_of_yshaaraj : public CreatureScript
{
public:
    garrosh_hellscream_creature_heart_of_yshaaraj() : CreatureScript("garrosh_hellscream_creature_heart_of_yshaaraj") { }

    struct siege_of_orgrimmar_creaturesAI : public BossAI
    {
        siege_of_orgrimmar_creaturesAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        std::list<Creature*> m_ListCreatures;
        bool m_Garrosh;
        uint32 i_Rand;

        void Reset() override
        {
            events.Reset();
            me->setFaction(35);
            m_Garrosh = false;

            me->SetReactState(REACT_PASSIVE);
            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE);
            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
        }

        void UpdateAI(const uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new siege_of_orgrimmar_creaturesAI(creature);
    }
};

// Heart of Yshaaraj 2nd phase prop - 72228
class garrosh_hellscream_creature_second_phase_prop_heart_of_yshaaraj : public CreatureScript
{
public:
    garrosh_hellscream_creature_second_phase_prop_heart_of_yshaaraj() : CreatureScript("garrosh_hellscream_creature_second_phase_prop_heart_of_yshaaraj") { }

    struct siege_of_orgrimmar_creaturesAI : public BossAI
    {
        siege_of_orgrimmar_creaturesAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;

        uint32 l_DiffShaBolts;

        void Reset() override
        {
            events.Reset();
            me->setFaction(16);

            me->SetDisableGravity(true);
            me->SetCanFly(true);

            l_DiffShaBolts = 4000;

            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE);
            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (Creature* l_Garrosh = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(DATA_GARROSH_HELLSCREAM)))
            {
                if (boss_garrosh_hellscream::boss_garrosh_hellscreamAI* linkAI = CAST_AI(boss_garrosh_hellscream::boss_garrosh_hellscreamAI, l_Garrosh->GetAI()))
                {
                    // Embodied Counter
                    if (linkAI->m_embodiedCounter != 0)
                    {
                        if (!me->HasUnitState(UNIT_STATE_CASTING))
                        {
                            if (l_Garrosh->IsWithinDistInMap(me, 30.0f))
                                me->CastSpell(l_Garrosh, 144946);
                        }
                    }
                    else
                    {
                        me->CastStop();
                    }

                    if (l_DiffShaBolts <= diff)
                    {
                        if (Creature* l_Garrosh = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(DATA_GARROSH_HELLSCREAM)))
                        {
                            if (linkAI->m_IntermissionActive && linkAI->i_Location == 1) // Terrace of Endless Springs
                            {
                                if (Unit* l_Target = SelectTarget(SELECT_TARGET_RANDOM, 0, 300.0f, true))
                                    me->CastSpell(l_Target, Spells::SPELL_CRUSHING_FEAR_PERIODIC_TRIGGER);
                            }

                            l_DiffShaBolts = 4000;
                        }
                        else
                        {
                            l_DiffShaBolts -= diff;
                        }
                    }
                }
            }
        }
        };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new siege_of_orgrimmar_creaturesAI(creature);
    }
};

// Heart of Yshaaraj 2nd phase prop - 78097
class garrosh_hellscream_heart_of_yshaaraj_protection_aura : public CreatureScript
{
public:
    garrosh_hellscream_heart_of_yshaaraj_protection_aura() : CreatureScript("garrosh_hellscream_heart_of_yshaaraj_protection_aura") { }

    struct siege_of_orgrimmar_creaturesAI : public BossAI
    {
        siege_of_orgrimmar_creaturesAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;

        uint32 l_DiffShaBolts;

        void Reset() override
        {
            events.Reset();
            me->setFaction(16);

            me->CastSpell(me, Spells::SPELL_YSHAARJ_PROTECTION);
            me->CastSpell(me, Spells::SPELL_YSHAARJ_PROTECTION_AURA);

            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_IMMUNE_TO_PC);
            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new siege_of_orgrimmar_creaturesAI(creature);
    }
};

void AddSC_garrosh_hellscream()
{
    // Bosses
    new boss_garrosh_hellscream();

    // Creatures
    new garrosh_hellscream_creature_desecrated_weapon();
    new garrosh_hellscream_creature_empowered_desecrated_weapon();
    new garrosh_hellscream_creature_heart_of_yshaaraj();
    new garrosh_hellscream_creature_iron_star();
    new garrosh_hellscream_creature_minion_of_yshaaraj();
    new garrosh_hellscream_creature_second_phase_prop_heart_of_yshaaraj();
    new garrosh_hellscream_creature_siege_engineer();
    new garrosh_hellscream_creature_thrall();
    new garrosh_hellscream_embodied_despair();
    new garrosh_hellscream_embodied_doubt();
    new garrosh_hellscream_embodied_fear();
    new garrosh_hellscream_farseer_wolf_rider();
    new garrosh_hellscream_korkron_warbringer();
    new garrosh_hellscream_heart_of_yshaaraj_protection_aura();
    new boss_farseer_vicious_war_wolf();

    // Spells
    new spell_desecrate_dummy();
    new spell_empowered_gripping_despair_debuff();
    new spell_empowered_gripping_despair();
    new spell_whirling_corruption();
    new spell_empowering_corruption_filter();
    new spell_enter_the_realm_yshaaraj();
    new spell_touch_of_yshaaraj_proc_two();
    new spell_hellscream_warsong_filter();
    new spell_ancsetral_healing();
    new spell_enter_realm_of_yshaarj_purple_beam();
}
