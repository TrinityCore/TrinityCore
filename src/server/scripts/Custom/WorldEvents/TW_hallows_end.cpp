/* Hallow's End custom script placeholder */

#include "ScriptMgr.h"

enum HalloweenData
{
    // Headless Horseman fire event
    NPC_HEADLESS_FIRE                   = 23537,
    NPC_FIRE_DUMMY                      = 23686,
    NPC_SHADE_HORSEMAN                  = 23543,
    GO_FIRE_EFFIGY                      = 186720,
    GO_LARGE_JACK_O_LANTERN             = 186887,


    SPELL_FIRE_CREATE_NODE              = 42118,
    SPELL_WATER_SPOUT_VISUAL            = 42348,
    SPELL_FIRE_VISUAL_BUFF              = 42074,
    SPELL_FIRE_SIZE_STACK               = 42091,
    SPELL_FIRE_STARTING_SIZE            = 42096,
    SPELL_QUESTS_CREDITS                = 42242,
    SPELL_CREATE_WATER_BUCKET           = 42349,

    SPELL_HORSEMAN_CONFLAGRATION_1      = 42380,
    SPELL_HORSEMAN_CONFLAGRATION_2      = 42869,
    SPELL_HORSEMAN_JACK_O_LANTERN       = 44185,
    SPELL_HORSEMAN_CLEAVE               = 15496,

    SAY_HORSEMAN_SPAWN                  = 1,
    SAY_HORSEMAN_FIRES_OUT              = 2,
    SAY_HORSEMAN_FIRES_FAIL             = 3,
    SAY_HORSEMAN_LAUGHS                 = 4,

    QUEST_LET_THE_FIRES_COME_A          = 12135,
    QUEST_LET_THE_FIRES_COME_H          = 12139,
    QUEST_STOP_FIRES_A                  = 11131,
    QUEST_STOP_FIRES_H                  = 11219,
};

#define FIRE_NODES_PER_AREA  13

const Position FireNodesGoldShire[FIRE_NODES_PER_AREA + 1] =
{
    {-9459.41f, 43.90f, 64.23f, 0.00f},
    {-9472.57f, 41.11f, 64.17f, 0.00f},
    {-9467.22f, 85.86f, 66.20f, 0.00f},
    {-9472.94f, 93.84f, 69.20f, 0.00f},
    {-9462.50f, 103.90f, 68.51f, 0.00f},
    {-9467.84f, 100.69f, 66.12f, 0.00f},
    {-9456.91f, 112.81f, 66.12f, 0.00f},
    {-9478.22f, 41.65f, 69.85f, 0.00f},
    {-9481.30f, 24.87f, 69.08f, 0.00f},
    {-9482.69f, 14.39f, 62.94f, 0.00f},
    {-9471.16f, -6.65f, 70.76f, 0.00f},
    {-9451.26f, 38.83f, 68.02f, 0.00f},
    {-9450.13f, 89.46f, 66.22f, 0.00f},
    {-9464.28f,68.1982f,56.2331f,0.0f}, // Center of Town
};

const Position FireNodesRazorHill[FIRE_NODES_PER_AREA+1] =
{
    {372.70f, -4714.64f, 23.11f, 0.00f},
    {343.11f, -4708.87f, 29.19f, 0.00f},
    {332.06f, -4703.21f, 24.52f, 0.00f},
    {317.20f, -4694.22f, 16.78f, 0.00f},
    {326.30f, -4693.24f, 34.59f, 0.00f},
    {281.18f, -4705.37f, 22.38f, 0.00f},
    {293.32f, -4773.45f, 25.03f, 0.00f},
    {280.17f, -4831.90f, 22.25f, 0.00f},
    {319.04f, -4770.23f, 31.47f, 0.00f},
    {362.50f, -4676.11f, 28.63f, 0.00f},
    {348.71f, -4805.08f, 32.23f, 0.00f},
    {342.88f, -4837.07f, 26.29f, 0.00f},
    {361.80f, -4769.27f, 18.49f, 0.00f},
    {317.837f,-4734.06f,9.76272f,0.0f}, // Center of Town
};

enum HalloweenFireEvents
{
    EVENT_FIRE_NONE,
    EVENT_FIRE_HIT_BY_BUCKET,
    EVENT_FIRE_VISUAL_WATER,
    EVENT_FIRE_GROW_FIRE,
    EVENT_HORSEMAN_CONFLAGRATION,
    EVENT_HORSEMAN_CLEAVE,
    EVENT_HORSEMAN_LAUGHS,
    EVENT_FIRE_FINISH,
    EVENT_FIRE_FAIL,
};

class TW_item_water_bucket : public ItemScript
{
    public:

        TW_item_water_bucket() : ItemScript("TW_item_water_bucket") { }

        bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const& targets)
        {
            if (Creature* dummy = player->SummonCreature(NPC_FIRE_DUMMY, targets.GetDst()->_position.GetPositionX(), targets.GetDst()->_position.GetPositionY(), targets.GetDst()->_position.GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 500))
            {
                std::list<Creature*> firesList;
                Trinity::AllCreaturesOfEntryInRange checker(dummy, NPC_HEADLESS_FIRE, 3.0f);
                Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(dummy, firesList, checker);
                player->VisitNearbyObject(3.0f, searcher);

                if (firesList.empty())
                {
                    // Just some extra checks...
                    Creature* fire = dummy->FindNearestCreature(NPC_HEADLESS_FIRE, 3.0f, true);
                    if (fire && fire->IsAlive())
                        fire->AI()->SetGUID(player->GetGUID(), EVENT_FIRE_HIT_BY_BUCKET);
                    else if (Player* friendPlr = dummy->SelectNearestPlayer(3.0f))
                    {
                        if (friendPlr->IsFriendlyTo(player) && friendPlr->IsAlive())
                            player->CastSpell(friendPlr, SPELL_CREATE_WATER_BUCKET, true);
                    }
                    else
                        return false;
                }

                for (std::list<Creature*>::const_iterator i = firesList.begin(); i != firesList.end(); ++i)
                    if ((*i) && (*i)->IsAlive())
                        (*i)->AI()->SetGUID(player->GetGUID(), EVENT_FIRE_HIT_BY_BUCKET);
            }
            return false;
        }
};

class TW_npc_halloween_fire : public CreatureScript
{
public:
    TW_npc_halloween_fire() : CreatureScript("TW_npc_halloween_fire") { }


    struct TW_npc_halloween_fireAI : public ScriptedAI
    {
        TW_npc_halloween_fireAI(Creature* c) : ScriptedAI(c) {}

        bool fireEffigy;
        bool off;
        EventMap events;
        ObjectGuid _playerGUID;

        void Reset() override
        {
            off = false;
            fireEffigy = false;
            _playerGUID.Clear();
            events.Reset();
            // Mark the npc if is for handling effigy instead of horseman fires
            if (me->FindNearestGameObject(GO_FIRE_EFFIGY, 0.5f))
                fireEffigy = true;
            me->CastSpell(me, SPELL_FIRE_STARTING_SIZE, true);
            events.ScheduleEvent(EVENT_FIRE_GROW_FIRE, 1000);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            switch(events.ExecuteEvent())
            {
                case EVENT_FIRE_VISUAL_WATER:
                    me->CastSpell(me, SPELL_WATER_SPOUT_VISUAL, true);
                    if (fireEffigy)
                    {
                        if (GameObject* effigy = me->FindNearestGameObject(GO_FIRE_EFFIGY, 0.5f))
                        {
                            effigy->SetGoState(GO_STATE_READY);
                            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                                player->KilledMonsterCredit(me->GetEntry());
                            events.ScheduleEvent(EVENT_FIRE_GROW_FIRE, 22000);
                        }
                    } else {
                        if (Aura* fireSize = me->GetAura(SPELL_FIRE_SIZE_STACK))
                        {
                            if (fireSize->GetStackAmount() < 10)
                            {
                                me->RemoveAura(fireSize);
                                me->RemoveAurasDueToSpell(SPELL_FIRE_VISUAL_BUFF);
                                me->DespawnOrUnsummon(1000);
                            } else
                                fireSize->ModStackAmount(-10);
                        }
                    }
                    break;
                case EVENT_FIRE_GROW_FIRE:
                    if (fireEffigy)
                    {
                        if (GameObject* effigy = me->FindNearestGameObject(GO_FIRE_EFFIGY, 0.5f))
                            effigy->SetGoState(GO_STATE_ACTIVE);
                    } else {
                        if (off) break; // This fire have been extinguished

                        if (Aura* fireSize = me->GetAura(SPELL_FIRE_SIZE_STACK)) // This fire have maxium size
                            if(fireSize->GetStackAmount() == 255) break;

                        if (!me->HasAura(SPELL_FIRE_STARTING_SIZE))
                            me->CastSpell(me, SPELL_FIRE_STARTING_SIZE, true);
                        if (!me->HasAura(SPELL_FIRE_VISUAL_BUFF))
                            me->CastSpell(me, SPELL_FIRE_VISUAL_BUFF, true);
                        me->CastSpell(me, SPELL_FIRE_SIZE_STACK, true);
                        events.ScheduleEvent(EVENT_FIRE_GROW_FIRE, urand(1000,2500));
                    }
                    break;
            }
        }

        void SetGUID(ObjectGuid guid, int32 id) override
        {
            if (off) return;

            if (id == EVENT_FIRE_HIT_BY_BUCKET)
            {
                _playerGUID = guid;
                if (fireEffigy)
                {
                    if (GameObject* effigy = me->FindNearestGameObject(GO_FIRE_EFFIGY, 0.5f))
                        if (effigy->GetGoState() == GO_STATE_ACTIVE)
                            events.ScheduleEvent(EVENT_FIRE_VISUAL_WATER, 1000);
                } else
                {
                    if (Creature* horseman = ObjectAccessor::GetCreature(*me, me->GetCreatorGUID()))
                        horseman->AI()->SetGUID(_playerGUID, EVENT_FIRE_HIT_BY_BUCKET);
                    events.ScheduleEvent(EVENT_FIRE_VISUAL_WATER, 1000);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_halloween_fireAI(creature);
    }
};

/* This should be fixed ASAP, as far as I know, HHman should appear flying on villages and
start casting SPELL_FIRE_CREATE_NODE on their buildings, maybe also son zone warning, also need
to fix the quests, there are 2 aviable now, when only one should be depending if the village is
alreade setted on fire or nor.
*/
class TW_npc_shade_horseman : public CreatureScript
{
public:
    TW_npc_shade_horseman() : CreatureScript("TW_npc_shade_horseman") { }


    struct TW_npc_shade_horsemanAI : public ScriptedAI
    {
        TW_npc_shade_horsemanAI(Creature* c) : ScriptedAI(c), fires(c) {}

        SummonList fires;
        EventMap events;
        bool moving;
        bool pointReached;
        bool allFiresSet;
        bool firesOut;
        uint32 wpCount;
        std::list<ObjectGuid> _playerList;

        void Reset() override
        {
            moving = true;
            pointReached = true;
            allFiresSet = false;
            firesOut = false;
            wpCount = 0;
            _playerList.clear();
            events.Reset();

            me->SetHealth(4440);
            me->Mount(25159);
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_DISABLE_MOVE);
            me->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT | MOVEMENTFLAG_DISABLE_GRAVITY);

            events.ScheduleEvent(EVENT_HORSEMAN_LAUGHS, urand(5000, 10000));
            events.ScheduleEvent(EVENT_HORSEMAN_CONFLAGRATION, urand(7000, 14000));
            events.ScheduleEvent(EVENT_FIRE_FAIL, 600000);
        }

        void JustSummoned(Creature* summon) override
        {
            if (!summon)
                return;

            summon->SetCreatorGUID(me->GetGUID());
            fires.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            if (!summon)
                return;

            fires.Despawn(summon);
        }

        void JustDied(Unit* killer) override
        {
            if (killer && killer->GetAreaId() == me->GetAreaId())
                killer->SummonGameObject(GO_LARGE_JACK_O_LANTERN, me->GetPositionX(), me->GetPositionY(), killer->GetPositionZ()+1.0f, me->GetOrientation(), 0.0f, 0.0f, 0.0f, 0.0f, 180000);
        }
        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (moving && id < FIRE_NODES_PER_AREA)
            {
                if (id == 0 && !allFiresSet)
                {
                    TC_LOG_INFO("scripts", "HEADLESS HORSEMAN BUG TRACKING Area %u.", me->GetAreaId());
                    Talk(SAY_HORSEMAN_SPAWN);
                }

                if (!allFiresSet)
                {
                    const Position pos = GetPositionsForArea()[wpCount];
                    if (pos.IsPositionValid())
                        me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_FIRE_CREATE_NODE, true);
                }

                if (id+1 == FIRE_NODES_PER_AREA)
                {
                    allFiresSet = true;
                    wpCount = 0;
                }
                else
                    ++wpCount;

                pointReached = true;
            } else if (id == FIRE_NODES_PER_AREA && firesOut)
            {
                me->ExitVehicle(); //Unmount();
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_DISABLE_MOVE);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT | MOVEMENTFLAG_DISABLE_GRAVITY);
                events.ScheduleEvent(EVENT_HORSEMAN_CLEAVE, urand(5000, 10000));
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);


            if (!firesOut)
            {
                const Position pos = GetPositionsForArea()[wpCount];

                if (!pos.IsPositionValid())
                    return;

                if (pointReached)
                {
                    pointReached = false;
                    me->GetMotionMaster()->MovePoint(wpCount, pos.GetPositionX(), pos.GetPositionY(), GetZForArea());
                }

                if (allFiresSet && fires.size() <= (uint32)(FIRE_NODES_PER_AREA*0.3f) && wpCount != FIRE_NODES_PER_AREA+1)
                {
                    Talk(SAY_HORSEMAN_FIRES_OUT);
                    wpCount = FIRE_NODES_PER_AREA;
                    me->GetMotionMaster()->MoveIdle();
                    me->GetMotionMaster()->MovePoint(FIRE_NODES_PER_AREA, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
                    fires.DespawnAll();
                    firesOut = true;
                    // Credit quest to players
                    if (!_playerList.empty())
                        for (std::list<ObjectGuid>::const_iterator i = _playerList.begin(); i != _playerList.end(); ++i)
                        if (Player* player = ObjectAccessor::GetPlayer(*me, *i))
                                player->CastSpell(player, SPELL_QUESTS_CREDITS, true);
                    return;
                }

                switch(events.ExecuteEvent())
                {
                    case EVENT_FIRE_FAIL:
                        fires.DespawnAll();
                        Talk(SAY_HORSEMAN_FIRES_FAIL);
                        wpCount = FIRE_NODES_PER_AREA+1;
                        me->GetMotionMaster()->MovePoint(wpCount, pos.GetPositionX(), pos.GetPositionY(), GetZForArea());
                        if (!_playerList.empty())
                        {
                            for (std::list<ObjectGuid>::const_iterator i = _playerList.begin(); i != _playerList.end(); ++i)
                            {
                                Player* player = ObjectAccessor::GetPlayer(*me, *i);
                                if (player)
                                {
                                    uint32 questId = player->GetTeam() == ALLIANCE ? QUEST_LET_THE_FIRES_COME_A : QUEST_LET_THE_FIRES_COME_H;
                                    if (player->GetQuestStatus(questId) == QUEST_STATUS_INCOMPLETE)
                                        player->FailQuest(questId);
                                }
                            }
                        }
                        me->DespawnOrUnsummon(10000);
                        break;
                    case EVENT_HORSEMAN_CONFLAGRATION:
                        if (!_playerList.empty())
                        {
                            for (std::list<ObjectGuid>::const_iterator i = _playerList.begin(); i != _playerList.end(); ++i)
                            {
                                Player* player = ObjectAccessor::GetPlayer(*me, *i);
                                if (player && player->GetDistance(me) <= 30.0f)
                                {
                                    me->CastSpell(player, RAND(SPELL_HORSEMAN_CONFLAGRATION_1, SPELL_HORSEMAN_CONFLAGRATION_2, SPELL_HORSEMAN_JACK_O_LANTERN), true);
                                    break;
                                }
                            }
                        }
                        events.ScheduleEvent(EVENT_HORSEMAN_CONFLAGRATION, urand(5000, 10000));
                        break;
                    case EVENT_HORSEMAN_LAUGHS:
                        Talk(SAY_HORSEMAN_LAUGHS);
                        events.ScheduleEvent(EVENT_HORSEMAN_LAUGHS, urand(10000, 25000));
                        break;
                }
            } else {
                switch(events.ExecuteEvent())
                {
                    case EVENT_HORSEMAN_CLEAVE:
                        if (Unit* victim = me->GetVictim())
                            me->CastSpell(victim, SPELL_HORSEMAN_CLEAVE, true);
                        events.ScheduleEvent(EVENT_HORSEMAN_CLEAVE, urand(5000, 10000));
                        return;
                    case EVENT_HORSEMAN_CONFLAGRATION:
                        if (!_playerList.empty())
                        {
                            for (std::list<ObjectGuid>::const_iterator i = _playerList.begin(); i != _playerList.end(); ++i)
                            {
                                Player* player = ObjectAccessor::GetPlayer(*me, *i);
                                if (player && player->GetAreaId() == me->GetAreaId() && player->GetDistance(me) <= 30.0f)
                                {
                                    me->CastSpell(player, RAND(SPELL_HORSEMAN_CONFLAGRATION_1, SPELL_HORSEMAN_CONFLAGRATION_2, SPELL_HORSEMAN_JACK_O_LANTERN), true);
                                    break;
                                }
                            }
                        }
                        events.ScheduleEvent(EVENT_HORSEMAN_CONFLAGRATION, urand(5000, 10000));
                        break;
                }
                DoMeleeAttackIfReady();
            }
        }

        const Position* GetPositionsForArea()
        {
            switch (me->GetAreaId())
            {
                case 87: //GoldShire
                    return FireNodesGoldShire;
                case 362: // Razor Hill
                case 2337:
                case 14:
                    return FireNodesRazorHill;
            }
            return NULL;
        }

        float GetZForArea()
        {
            switch (me->GetAreaId())
            {
                case 87: //GoldShire
                    return 77.6f;
                case 362: // Razor Hill
                case 2337:
                case 14:
                    return 40.0f;
            }
            return 0.0f;
        }

        void SetGUID(ObjectGuid guid, int32 id) override
        {
            if (id == EVENT_FIRE_HIT_BY_BUCKET)
            {
                _playerList.push_back(guid);
                _playerList.unique();
            }

        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_shade_horsemanAI(creature);
    }
};

class TW_npc_halloween_orphan_matron : public CreatureScript
{
public:
    TW_npc_halloween_orphan_matron() : CreatureScript("TW_npc_halloween_orphan_matron") { }

    ObjectGuid _headlessHoresemanGUID;

    bool OnGossipHello(Player* player, Creature* me)
    {
        player->PrepareQuestMenu(me->GetGUID());

        if (ObjectAccessor::GetCreature(*me, _headlessHoresemanGUID))
        {
            QuestMenu &qm = player->PlayerTalkClass->GetQuestMenu();
            QuestMenu qm2;

            uint32 quest1 = player->GetTeam() == ALLIANCE ? QUEST_LET_THE_FIRES_COME_A : QUEST_LET_THE_FIRES_COME_H;
            uint32 quest2 = player->GetTeam() == ALLIANCE ? QUEST_STOP_FIRES_A : QUEST_STOP_FIRES_H;

            // Copy current quest menu ignoring some quests
            for (uint32 i = 0; i<qm.GetMenuItemCount(); ++i)
            {
                if (qm.GetItem(i).QuestId == quest1 || qm.GetItem(i).QuestId == quest2)
                    continue;

                qm2.AddMenuItem(qm.GetItem(i).QuestId, qm.GetItem(i).QuestIcon);
            }

            if (player->GetQuestStatus(quest1) == QUEST_STATUS_NONE)
            {
                if (player->GetQuestStatus(quest2) == QUEST_STATUS_NONE)
                    qm2.AddMenuItem(quest2, 2);
                else if (player->GetQuestStatus(quest2) != QUEST_STATUS_REWARDED)
                    qm2.AddMenuItem(quest2, 4);
            }
            else
                if (player->GetQuestStatus(quest1) != QUEST_STATUS_REWARDED)
                    qm2.AddMenuItem(quest1, 4);

            qm.ClearMenu();

            for (uint32 i = 0; i<qm2.GetMenuItemCount(); ++i)
                qm.AddMenuItem(qm2.GetItem(i).QuestId, qm2.GetItem(i).QuestIcon);
        }

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(me), me->GetGUID());
        return true;
    }

    bool OnQuestAccept(Player* player, Creature* me, Quest const* quest)
    {
        if (!(me->GetAreaId() == 87 || me->GetAreaId() == 362))
            return true;

        if (quest->GetQuestId() == QUEST_LET_THE_FIRES_COME_A || quest->GetQuestId() == QUEST_LET_THE_FIRES_COME_H)
        {
            Creature* horseman = ObjectAccessor::GetCreature(*me, _headlessHoresemanGUID);

            if (!horseman)
            {
                TC_LOG_INFO("scripts", "HEADLESS HORSEMAN BUG TRACKING. SUMMON: GUID Player: (" UI64FMTD "). Area %u.", player->GetGUID(), player->GetAreaId());
                if (Creature* newHorseman = player->SummonCreature(NPC_SHADE_HORSEMAN, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 20.0f, 0, TEMPSUMMON_DEAD_DESPAWN, 180000))
                    _headlessHoresemanGUID = newHorseman->GetGUID();
            }
        }
        return true;
    }
};

void AddSC_TW_hallows_end()
{
    new TW_item_water_bucket();
    new TW_npc_halloween_fire();
    new TW_npc_shade_horseman();
    new TW_npc_halloween_orphan_matron();
}
