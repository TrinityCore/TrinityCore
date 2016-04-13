#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "temple_of_jade_serpent.h"

enum eSpellsLoreWalker
{
    SPELL_LOREWALKER_ALACRITY   = 122714,
    SPELL_MEDITATION            = 122715,
    SPELL_ROOT_SELF             = 106822,
    SPELL_SUNFIRE_RAYS          = 107223,
    SPELL_SUN                   = 107349,
    SPELL_BLUSTERING_VORTEX     = 67422,
    SPELL_GROW_LOW              = 104921,
    SPELL_EXTRACT_SHA_3         = 111807,
    SPELL_EXTRACT_SHA_4         = 111768,
    SPELL_SHOOT_SUN             = 112084,
    SPELL_HELLFIRE_ARROW        = 113017,
    SPELL_SHA_CORRUPTION        = 107034,
    SPELL_SHA_CORRUPTION_2      = 120000,
    SPELL_SHA_CORRUPTION_3      = 120000,
    SPELL_CORRUPTION_CHANNEL    = 42808,
    SPELL_EXTRACT_SHA           = 111764,

    SPELL_AGONY                 = 114571,
    SPELL_DISSIPATION           = 113379,
    SPELL_INTENSITY             = 113315,
    SPELL_ULTIMATE_POWER        = 113309,

    //SCROLL SPELLS
    SPELL_SCROLL_FLOOR          = 107350,
    SPELL_JADE_ENERGY_2         = 111452,
    SPELL_DRAW_SHA_2            = 111393,
    SPELL_DRAW_SHA_3            = 111431,
    SPELL_SHA_BURNING           = 111588,
    SPELL_SHA_EXPLOSION         = 111579,
    SPELL_DEATH                 = 98391,

    //SUN SPELLS
    SPELL_SUNFIRE_EXPLOSION     = 111737,
};

enum eEventsLoreWalker
{
    EVENT_INTRO_0 = 1,
    EVENT_INTRO_1 = 2,
    EVENT_INTRO_2 = 3,
    EVENT_INTRO_3 = 4,

    EVENT_SUN_0 = 5,
    EVENT_SUN_1 = 6,
    EVENT_SUN_2 = 7,
    EVENT_SUN_3 = 8,
    EVENT_SUN_4 = 9,

    EVENT_ZAO_ENTER_COMBAT_1 = 10,
    EVENT_ZAO_ENTER_COMBAT_2 = 11,
    EVENT_ZAO_ATTACK         = 12,

    EVENT_STRIFE_0 = 14,
    EVENT_STRIFE_1 = 15,
    EVENT_STRIFE_2 = 16,
    EVENT_STRIFE_3 = 17,
    EVENT_STRIFE_4 = 18,

    EVENT_WYPE_CHECKER = 19,

    EVENT_LUNCH_AGONY               = 20,
    EVENT_INTENSITY_OR_DISSIPATION  = 21,

    EVENT_SUNFIRE_CAST = 22,
};

enum eActionsLoreWalker
{
    ACTION_START_SUNFIRE     = 1,
    ACTION_ZAO_ENTER_COMBAT  = 2,
    ACTION_ZAO_TALK          = 3,
    ACTION_SUN_DESTROYED     = 4,
    ACTION_START_SUNS        = 5,
    ACTION_START_TRIAL       = 6,
    ACTION_TALK_AFTER_ZAO    = 7,
    ACTION_STATUS_FINISHED   = 8,

    ACTION_START_BLUSTERING  = 9,
    ACTION_SUNFIRE_EXPLOSION = 10,
    ACTION_ATTACK_ZAO        = 11,
    ACTION_SUNFIRE_CAST_RAY  = 12,
};

enum eTextsLoreWalker
{
    EVENT_TALK_INTRO_0 = 0,
    EVENT_TALK_INTRO_1 = 1,
    EVENT_TALK_INTRO_2 = 2,
    EVENT_TALK_INTRO_3 = 3,

    EVENT_TALK_ZAO_APPEARS_0 = 4,
    EVENT_TALK_ZAO_APPEARS_1 = 5,
    EVENT_TALK_ZAO_APPEARS_2 = 6,
    EVENT_TALK_ZAO_APPEARS_3 = 7,
    EVENT_TALK_ZAO_APPEARS_4 = 8,

    EVENT_TALK_ZAO_ENTERS_COMBAT_0 = 9,

    EVENT_TALK_STRIFE_0 = 10,
    EVENT_TALK_STRIFE_1 = 11,
    EVENT_TALK_STRIFE_2 = 12,
    EVENT_TALK_STRIFE_3 = 13,
    EVENT_TALK_STRIFE_4 = 14,
};

enum eLoreWalkerStonestepEvents
{
    EVENT_LOREWALKER_STONESTEP_SUNS  = 0,
    EVENT_LOREWALKER_STONESTEP_TRIAL = 1,
};

enum eStatusLoreWalker
{
    STATUS_LOREWALKER_STONESTEP_NONE        = 1,
    STATUS_LOREWALKER_STONESTEP_INTRO       = 2,
    //suns
    STATUS_LOREWALKER_STONESTEP_SPAWN_SUNS  = 3,
    STATUS_LOREWALKER_STONESTEP_SPAWN_SUNS_2= 4,
    STATUS_LOREWALKER_STONESTEP_ZAO_COMBAT  = 5,
    //trial
    STATUS_LOREWALKER_STONESTEP_START_TRIAL = 6,
    STATUS_LOREWALKER_STONESTEP_FINISH      = 7,
};

Position sunPositions[5] =
{
    { 830.067f, -2466.660f, 179.240f, 1.266608f },
    { 836.632f, -2467.159f, 178.139f, 1.266608f },
    { 839.659f, -2469.159f, 182.496f, 1.266608f },
    { 845.263f, -2469.179f, 178.209f, 1.266608f },
    { 850.361f, -2474.320f, 178.196f, 1.266608f }
};

Position sunTriggerPositions[5] =
{
    { 830.067f, -2466.660f, 176.320f, 0.0f },
    { 836.632f, -2467.159f, 176.320f, 0.0f },
    { 839.659f, -2469.159f, 176.320f, 0.0f },
    { 845.263f, -2469.179f, 176.320f, 0.0f },
    { 850.361f, -2474.320f, 176.320f, 0.0f }
};

//56843 - lorewalker stonestep
class boss_lorewalker_stonestep : public CreatureScript
{
    public:
        boss_lorewalker_stonestep() : CreatureScript("boss_lorewalker_stonestep") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_lorewalker_stonestep_AI(creature);
        }

        struct boss_lorewalker_stonestep_AI : public BossAI
        {
            boss_lorewalker_stonestep_AI(Creature* creature) : BossAI(creature, DATA_LOREWALKER_STONESTEP_EVENT)
            {
                instance = creature->GetInstanceScript();
            }

            bool event_go;
            uint8 sunDefeated;
            eStatusLoreWalker statusBattle;
            InstanceScript* instance;
            
            void Reset()
            {
                event_go = false;
                sunDefeated = 0;
                me->CastSpell(me, SPELL_ROOT_SELF, true);
                /*DespawnCreatures(CREATURE_SCROLL);


                DespawnCreatures(CREATURE_OSONG);
                DespawnCreatures(CREATURE_PERIL);
                DespawnCreatures(CREATURE_STRIFE);

                DespawnCreatures(CREATURE_ZAO_SUNSEEKER);
                DespawnCreatures(CREATURE_SUN);
                DespawnCreatures(CREATURE_SUN_2);
                DespawnCreatures(CREATURE_HAUNTING_SHA);*/

                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, SPELL_SHA_CORRUPTION, 1000.0f);
                GetCreatureListWithEntryInGrid(creatures, me, SPELL_SHA_CORRUPTION_3, 1000.0f);
                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                    (*iter)->Respawn();

                std::list<Creature*> sunfires;
                GetCreatureListWithEntryInGrid(sunfires, me, CREATURE_SUN_2, 1000.0f);
                for (std::list<Creature*>::iterator iter = sunfires.begin(); iter != sunfires.end(); ++iter)
                        (*iter)->RemoveAura(SPELL_BLUSTERING_VORTEX);

                statusBattle = STATUS_LOREWALKER_STONESTEP_NONE;

                _Reset();
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_START_TRIAL:
                    {
                        statusBattle = STATUS_LOREWALKER_STONESTEP_START_TRIAL;
                        events.ScheduleEvent(EVENT_STRIFE_0, 500);
                        events.ScheduleEvent(EVENT_WYPE_CHECKER, 3000);
                        instance->SetBossState(DATA_LOREWALKER_STONESTEP_EVENT, IN_PROGRESS);
                        break;
                    }
                    case ACTION_START_SUNS:
                    {
                        statusBattle = STATUS_LOREWALKER_STONESTEP_SPAWN_SUNS;
                        events.ScheduleEvent(EVENT_SUN_0, 500);
                        events.ScheduleEvent(EVENT_WYPE_CHECKER, 3000);
                        instance->SetBossState(DATA_LOREWALKER_STONESTEP_EVENT, IN_PROGRESS);
                        break;
                    }
                    case ACTION_TALK_AFTER_ZAO:
                    {
                        Talk(EVENT_TALK_ZAO_ENTERS_COMBAT_0);
                        break;
                    }
                    case ACTION_SUN_DESTROYED:
                    {
                        if(++sunDefeated >= 5)
                        {
                            statusBattle = STATUS_LOREWALKER_STONESTEP_ZAO_COMBAT;

                            if (Creature* zao = me->FindNearestCreature(CREATURE_ZAO_SUNSEEKER, 100.0f))
                                if (zao->GetAI())
                                    zao->GetAI()->DoAction(ACTION_ZAO_ENTER_COMBAT);

                            std::list<Creature*> sunFires;
                            GetCreatureListWithEntryInGrid(sunFires, me, CREATURE_SUN, 100.0f);
                            for (std::list<Creature*>::iterator iter = sunFires.begin() ; iter != sunFires.end() ; ++iter)
                                (*iter)->RemoveAura(SPELL_BLUSTERING_VORTEX);
                        }
                        break;
                    }
                    case ACTION_STATUS_FINISHED:
                    {
                        instance->SetBossState(DATA_LOREWALKER_STONESTEP_EVENT, DONE);
                        statusBattle = STATUS_LOREWALKER_STONESTEP_FINISH;
                        Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            if (Player* player = i->GetSource())
                                player->CastSpell(player, SPELL_LOREWALKER_ALACRITY, false);

                        /*DespawnCreatures(CREATURE_OSONG);
                        DespawnCreatures(CREATURE_SUN);
                        DespawnCreatures(CREATURE_SUN_2);
                        DespawnCreatures(CREATURE_HAUNTING_SHA);*/
                        break;
                    }
                }
            }

            void KilledUnit(Unit* /*victim*/)
            {
            }

            void JustDied(Unit* /*killer*/)
            {
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                //this creature never dies
                damage = 0;
            }

            void MoveInLineOfSight(Unit* who)
            {
                // If Lorewalker stonestep sees a player, launch the speech.
                if (!event_go && who->GetTypeId() == TYPEID_PLAYER)
                {
                    event_go = true;
                    events.ScheduleEvent(EVENT_INTRO_0, 500);
                    statusBattle = STATUS_LOREWALKER_STONESTEP_INTRO;
                    me->SummonCreature(CREATURE_SCROLL, 846.953f, -2453.21f, 175.961f);
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!instance)
                    return;
                
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        // This is the first speech when Lorewalker stonestep sees you for the first time.
                        case EVENT_INTRO_0:
                        {
                            Talk(EVENT_TALK_INTRO_0); //419621722
                            events.ScheduleEvent(EVENT_INTRO_1, 8019);
                            break;
                        }
                        case EVENT_INTRO_1:
                        {
                            Talk(EVENT_TALK_INTRO_1); //419629741
                            events.ScheduleEvent(EVENT_INTRO_2, 16162);
                            break;
                        }
                        case EVENT_INTRO_2:
                        {
                            Talk(EVENT_TALK_INTRO_2); //419645903
                            events.ScheduleEvent(EVENT_INTRO_3, 9578);
                            break;
                        }
                        case EVENT_INTRO_3:
                        {
                            Talk(EVENT_TALK_INTRO_3); //419655481
                            if (Creature* scroll = me->GetMap()->GetCreature(me->GetInstanceScript()->GetObjectGuid(CREATURE_SCROLL)))
                                scroll->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            break;
                        }
                        // End of the first speech.

                        // TRIAL: Speech when the scroll is destroyed.
                        case EVENT_SUN_0:
                        {
                            me->RemoveAura(SPELL_ROOT_SELF);
                            Talk(EVENT_TALK_ZAO_APPEARS_0); //419667540
                            events.ScheduleEvent(EVENT_SUN_1, 9641);
                            break;
                        }
                        case EVENT_SUN_1:
                        {
                            Talk(EVENT_TALK_ZAO_APPEARS_1); //419677181
                            me->GetMotionMaster()->MovePoint(0, 838.033f, -2480.518f, 176.744f);
                            events.ScheduleEvent(EVENT_SUN_2, 811);
                            break;
                        }
                        case EVENT_SUN_2:
                        {
                            Talk(EVENT_TALK_ZAO_APPEARS_2); //419677992
                            me->GetMotionMaster()->MovePoint(0, 834.643f, -2490.361f, 179.897f);
                            events.ScheduleEvent(EVENT_SUN_3, 2792);
                            break;
                        }
                        case EVENT_SUN_3:
                        {
                            Talk(EVENT_TALK_ZAO_APPEARS_3); //419680784
                            me->SetFacingTo(1.239f);

                            std::list<Creature*> sunfires;
                            GetCreatureListWithEntryInGrid(sunfires, me, CREATURE_SUN, 200.0f);
                            for (std::list<Creature*>::iterator iter = sunfires.begin(); iter != sunfires.end(); ++iter)
                                if ((*iter)->GetAI())
                                    (*iter)->GetAI()->DoAction(ACTION_START_SUNFIRE);

                            std::list<Creature*> sunfiresTrigger;
                            GetCreatureListWithEntryInGrid(sunfiresTrigger, me, CREATURE_SUN_2, 200.0f);
                            for(std::list<Creature*>::iterator iter = sunfiresTrigger.begin(); iter != sunfiresTrigger.end(); ++iter)
                                if((*iter)->GetAI())
                                    (*iter)->GetAI()->DoAction(ACTION_SUNFIRE_EXPLOSION);

                            events.ScheduleEvent(EVENT_SUNFIRE_CAST, 2000);
                            events.ScheduleEvent(EVENT_SUN_4, 4214);
                            break;
                        }

                        case EVENT_SUN_4:
                        {
                            me->CastSpell(me, SPELL_MEDITATION, false);
                            Talk(EVENT_TALK_ZAO_APPEARS_4); //419722998
                            break;
                        }
                        // TRIAL: End of speech for destroyed scroll.

                        // ZAO: Speech when the scroll is destroyed.
                        case EVENT_STRIFE_0:
                        {
                            me->RemoveAura(SPELL_ROOT_SELF);
                            Talk(EVENT_TALK_STRIFE_0); //419667540
                            events.ScheduleEvent(EVENT_STRIFE_1, 9641);
                            break;
                        }
                        case EVENT_STRIFE_1:
                        {
                            Talk(EVENT_TALK_STRIFE_1); //419677181
                            me->GetMotionMaster()->MovePoint(0, 838.033f, -2480.518f, 176.744f);
                            events.ScheduleEvent(EVENT_STRIFE_2, 8011);
                            break;
                        }
                        case EVENT_STRIFE_2:
                        {
                            Talk(EVENT_TALK_STRIFE_2); //419677992
                            me->GetMotionMaster()->MovePoint(0, 834.643f, -2490.361f, 179.897f);
                            events.ScheduleEvent(EVENT_STRIFE_3, 5092);
                            break;
                        }
                        case EVENT_STRIFE_3:
                        {
                            Talk(EVENT_TALK_STRIFE_3); //419680784
                            events.ScheduleEvent(EVENT_STRIFE_4, 6014);
                            break;
                        }
                        case EVENT_STRIFE_4:
                        {
                            me->CastSpell(me, SPELL_MEDITATION, false);
                            Talk(EVENT_TALK_STRIFE_4); //419722998
                            break;
                        }
                        // ZAO: End of speech for destroyed scroll.

                       /* case EVENT_WYPE_CHECKER:
                        {
                            if(statusBattle >= STATUS_LOREWALKER_STONESTEP_INTRO && statusBattle < STATUS_LOREWALKER_STONESTEP_FINISH && instance->)
                                Reset();
                            else
                                events.ScheduleEvent(EVENT_WYPE_CHECKER, 3000);
                            break;
                        }*/

                        case EVENT_SUNFIRE_CAST:
                        {
                            std::list<Creature*> sunfires;
                            // Get all surounding sunfires
                            GetCreatureListWithEntryInGrid(sunfires, me, CREATURE_SUN, 200.0f);

                            // Choose one randomly
                            Trinity::Containers::RandomResizeList(sunfires, 1);

                            if (sunfires.size() == 0)
                                break;

                            Creature *elicted = sunfires.front();

                            if (elicted->GetAI())
                            {
                                // Ask to cas ray spell
                                elicted->GetAI()->DoAction(ACTION_SUNFIRE_CAST_RAY);
                                // Schedule next in 2 seconds
                                events.ScheduleEvent(EVENT_SUNFIRE_CAST, 2000);
                            }

                            break;
                        }

                    }
                }

            }
        };
};

// 57080 - scroll
class mob_lorewalker_scroll : public CreatureScript
{
public:
    mob_lorewalker_scroll() : CreatureScript("mob_lorewalker_scroll") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_lorewalker_scroll_AI(creature);
    }

    struct mob_lorewalker_scroll_AI : public ScriptedAI
    {
        mob_lorewalker_scroll_AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint8 eventChoosen;

        void Reset()
        {
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_PASSIVE);

            me->CastSpell(me, SPELL_SCROLL_FLOOR, false);
            me->CastSpell(me, SPELL_JADE_ENERGY_2, false);
            me->CastSpell(me, SPELL_GROW_LOW, false);

            eventChoosen = urand(EVENT_LOREWALKER_STONESTEP_SUNS, EVENT_LOREWALKER_STONESTEP_TRIAL);
        }

        // When the scroll dies, we must draw all the corrupted units.
        void JustDied(Unit* /*killer*/)
        {
            if (!instance)
                return;

            me->RemoveAura(SPELL_JADE_ENERGY_2);
            me->RemoveAura(SPELL_SCROLL_FLOOR);
            me->RemoveAura(SPELL_GROW_LOW);
            me->CastSpell(me, SPELL_SHA_BURNING, false);
            me->CastSpell(me, SPELL_SHA_EXPLOSION, false);
            me->CastSpell(me, SPELL_DEATH, false);

            //Then draw all the corrupted units and summon the suns.
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, SPELL_SHA_CORRUPTION, 1000.0f);
            GetCreatureListWithEntryInGrid(creatures, me, SPELL_SHA_CORRUPTION_3, 1000.0f);
            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
            {
                Creature* c = (*iter);
                me->AddAura(SPELL_DRAW_SHA_2, c);
                c->CastSpell(me, SPELL_DRAW_SHA_3, false);
                c->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, me->GetGUID().GetEntry());
                c->SetUInt32Value(UNIT_CHANNEL_SPELL, SPELL_CORRUPTION_CHANNEL);
                c->DespawnOrUnsummon(2000);
            }

            if (eventChoosen == EVENT_LOREWALKER_STONESTEP_SUNS)
            {
                Creature* lorewalker = me->GetMap()->GetCreature((ObjectGuid)me->GetInstanceScript()->GetData64(CREATURE_LOREWALKTER_STONESTEP));
                if (lorewalker && lorewalker->GetAI())
                    lorewalker->GetAI()->DoAction(ACTION_START_SUNS);

                //Suns
                for (uint8 i = 0; i < 5; ++i)
                    me->SummonCreature(CREATURE_SUN, sunPositions[i].GetPositionX(), sunPositions[i].GetPositionY(), sunPositions[i].GetPositionZ(), sunPositions[i].GetOrientation());

                //Suns 2
                for (uint8 i = 0; i < 5; ++i)
                    me->SummonCreature(CREATURE_SUN_2, sunTriggerPositions[i].GetPositionX(), sunTriggerPositions[i].GetPositionY(), sunTriggerPositions[i].GetPositionZ());

                //Summon Zao
                me->SummonCreature(CREATURE_ZAO_SUNSEEKER, 846.877f, -2449.110f, 175.044f, 4.450f);

                std::list<Creature*> sunfires;
                GetCreatureListWithEntryInGrid(sunfires, me, CREATURE_SUN_2, 1000.0f);
                for (std::list<Creature*>::iterator iter = sunfires.begin(); iter != sunfires.end(); ++iter)
                    if ((*iter)->GetAI())
                        (*iter)->GetAI()->DoAction(ACTION_START_BLUSTERING);

            }
            else if (eventChoosen == EVENT_LOREWALKER_STONESTEP_TRIAL)
            {
                Creature* lorewalker = me->GetMap()->GetCreature(me->GetInstanceScript()->GetObjectGuid(CREATURE_LOREWALKTER_STONESTEP));
                if (lorewalker && lorewalker->GetAI())
                    lorewalker->GetAI()->DoAction(ACTION_START_TRIAL);

                Creature* strife = me->SummonCreature(CREATURE_STRIFE, 847.530f, -2469.184f, 174.960f, 1.525f);
                Creature* peril  = me->SummonCreature(CREATURE_PERIL,  836.906f, -2465.859f, 174.960f, 1.014f);

                if (TempSummon* osong = me->SummonCreature(CREATURE_OSONG, 846.81f, -2453.73f, 174.96f, 4.409964f))
                {
                    if (Creature* victim = urand(0, 1) ? strife: peril)
                        osong->Attack(victim, true);
                    osong->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    sCreatureTextMgr->SendChat(osong, 0, 0);
                }
            }
        }
    };
};

// 56915 - suns
class mob_sun : public CreatureScript
{
    public:
        mob_sun() : CreatureScript("mob_sun") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_sun_AI(creature);
        }

        struct mob_sun_AI : public ScriptedAI
        {
            mob_sun_AI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            void Reset()
            {
                me->CastSpell(me, SPELL_SUN, false);
                me->CastSpell(me, SPELL_GROW_LOW, false);
                me->SetReactState(REACT_PASSIVE);

                me->AddUnitState(UNIT_STATE_ROOT);
                me->SetDisableGravity(true);
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_START_SUNFIRE:
                    {
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        break;
                    }
                    case ACTION_SUNFIRE_CAST_RAY:
                    {
                        if (!instance)
                            return;

                        if (!me->IsAlive())
                            return;

                        Map::PlayerList const &PlayerList = instance->instance->GetPlayers();

                        if (PlayerList.isEmpty())
                            return;

                        Map::PlayerList::const_iterator it = PlayerList.begin();
                        uint8 randPlayer = urand(0, PlayerList.getSize() - 1);
                        for (uint8 i = 0; i < randPlayer; ++i, ++it);

                        if (it == PlayerList.end())
                            return;

                        if (Player* player = it->GetSource())
                            me->CastSpell(player, SPELL_SUNFIRE_RAYS, true);
                        break;
                    }
                }
            }

            void JustDied(Unit* killer)
            {
                if (!instance)
                    return;

                if (Creature* loreWalker = me->GetMap()->GetCreature(me->GetInstanceScript()->GetObjectGuid(CREATURE_LOREWALKTER_STONESTEP)))
                    if(loreWalker->GetAI())
                        loreWalker->GetAI()->DoAction(ACTION_SUN_DESTROYED);

                //summon one haunting sha.
                me->CastSpell(me, SPELL_EXTRACT_SHA, false);
            }
        };
};

// 58815 - other suns (witch one are those ?)
class mob_sunfire : public CreatureScript
{
public:
    mob_sunfire() : CreatureScript("mob_sunfire") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_sunfire_AI(creature);
    }

    struct mob_sunfire_AI : public ScriptedAI
    {
        mob_sunfire_AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        void DoAction(int32 action)
        {
            if(action == ACTION_START_BLUSTERING)
                me->CastSpell(me, SPELL_BLUSTERING_VORTEX, false); //Blustering Vortex, Fire vortex display

            if(action == ACTION_SUNFIRE_EXPLOSION)
                me->CastSpell(me, SPELL_SUNFIRE_EXPLOSION, true);
        }
    };
};

// 58826 - zao

class mob_zao : public CreatureScript
{
    public:
        mob_zao() : CreatureScript("mob_zao") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_zao_AI(creature);
        }

        struct mob_zao_AI : public ScriptedAI
        {
            mob_zao_AI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            EventMap events;

            std::list<Creature*> suns;
            bool isCorrupted;

            void Reset()
            {
                isCorrupted = false;

                me->AddUnitState(UNIT_STATE_ROOT);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                events.Reset();
                events.ScheduleEvent(EVENT_ZAO_ATTACK, 15000);
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (attacker->ToCreature())
                {
                    uint32 entry = attacker->ToCreature()->GetEntry();
                    if(entry == CREATURE_SUN || entry == CREATURE_SUN_2)
                    {
                        damage = 0;
                    }
                }
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_ZAO_ENTER_COMBAT:
                    {
                        isCorrupted = true;
                        me->setFaction(14);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->CastSpell(me, SPELL_SHA_CORRUPTION_2, false);
                        me->SetFullHealth();
                        events.ScheduleEvent(EVENT_ZAO_ENTER_COMBAT_1, 1000);
                        break;
                    }
                }
            }

            void JustDied(Unit* killer)
            {
                if (!instance)
                    return;

                if (Creature* loreWalker = me->GetMap()->GetCreature(me->GetInstanceScript()->GetObjectGuid(CREATURE_LOREWALKTER_STONESTEP)))
                    if (loreWalker->GetAI())
                        loreWalker->GetAI()->DoAction(ACTION_STATUS_FINISHED);
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        // Speech of Zao entering combat
                        case EVENT_ZAO_ENTER_COMBAT_1: //419729036
                        {
                            Talk(EVENT_TALK_INTRO_0);
                            events.ScheduleEvent(EVENT_ZAO_ENTER_COMBAT_2, 32635);
                            break;
                        }
                        case EVENT_ZAO_ENTER_COMBAT_2: //419761671
                        {
                            Creature* c = me->FindNearestCreature(CREATURE_LOREWALKTER_STONESTEP, 1000.0f);
                            if(c && c->GetAI())
                                c->GetAI()->DoAction(ACTION_TALK_AFTER_ZAO);
                            events.Reset();

                            events.ScheduleEvent(EVENT_ZAO_ATTACK, 1000);
                            break;
                        }
                        // End of speech of Zao entering combat
                        case EVENT_ZAO_ATTACK:
                        {
                            if (isCorrupted)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                    me->CastSpell(target, SPELL_HELLFIRE_ARROW, true);
                            }
                            else
                            {
                                suns.clear();
                                GetCreatureListWithEntryInGrid(suns, me, CREATURE_SUN, 50.0f);

                                if (!suns.empty())
                                {
                                    uint32 rand = urand(0, suns.size());
                                    Creature* target = NULL;
                                    for (auto sun : suns)
                                    {
                                        if (rand == 0)
                                        {
                                            target = sun;
                                            break;
                                        }
                                        --rand;
                                    }
                                    if (target)
                                        me->CastSpell(target, SPELL_SHOOT_SUN, false);
                                }
                            }
                            events.ScheduleEvent(EVENT_ZAO_ATTACK, 2000);
                            break;
                        }
                    }
                }
            }
        };
};

// 58865 - haunting sha pursuing zao
class mob_haunting_sha : public CreatureScript
{
    public:
        mob_haunting_sha() : CreatureScript("mob_haunting_sha") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_haunting_sha_AI(creature);
        }

        struct mob_haunting_sha_AI : public ScriptedAI
        {
            mob_haunting_sha_AI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            EventMap events;

            enum eEventHauntingSha
            {
                EVENT_HAUNTING_GAZE = 1,
            };

            enum eSpellsHauntingSha
            {
                SPELL_HAUNTING_GAZE = 114646,
            };

            void Reset()
            {
                me->setFaction(14);
                events.Reset();
            }

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(EVENT_HAUNTING_GAZE, 1000);
            }

            void DoAction(int32 action)
            {
                if (!instance)
                    return;

                if(action == ACTION_ATTACK_ZAO)
                {
                    me->Respawn();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                    if(Creature* zao = me->GetMap()->GetCreature((ObjectGuid)me->GetInstanceScript()->GetData64(CREATURE_ZAO_SUNSEEKER)))
                    {
                        me->getThreatManager().addThreat(zao, 1000000.f);
                        me->AI()->AttackStart(zao);
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!me->GetVictim())
                {
                    Map::PlayerList const& PlayerList = me->GetInstanceScript()->instance->GetPlayers();

                    if (!PlayerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            Player* plr = i->GetSource();
                            if( !plr)
                                continue;
                            me->getThreatManager().addThreat(plr, 1.0f);
                        }
                    }
                    me->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM));
                }

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_HAUNTING_GAZE:
                        if (me->GetVictim() && me->GetVictim()->GetTypeId() == TYPEID_PLAYER)
                            me->CastSpell(me->GetVictim(), SPELL_HAUNTING_GAZE, false);
                        events.ScheduleEvent(EVENT_HAUNTING_GAZE, 2000);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

// 59726 - strife
// 59051 - peril
class mob_peril_and_strife : public CreatureScript
{
    public:
    mob_peril_and_strife() : CreatureScript("mob_peril_and_strife") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_peril_and_strife_AI(creature);
    }

    struct mob_peril_and_strife_AI : public ScriptedAI
    {
        mob_peril_and_strife_AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        int32 countIntensity;
        bool hasBeenHit;
        EventMap events;

        bool isPeril;

        void Reset()
        {
            me->setFaction(14);
            countIntensity = 0;
            hasBeenHit = false;
            me->SetReactState(REACT_DEFENSIVE);
            events.Reset();
            me->AddAura(SPELL_ROOT_SELF, me);
            me->AddUnitState(UNIT_STATE_ROOT);

            isPeril = me->GetEntry() == CREATURE_PERIL;
        }

        Creature* GetOther()
        {
            if (!instance)
                return NULL;

            return me->GetMap()->GetCreature(instance->GetObjectGuid(me->GetInstanceScript()->GetData64(isPeril ? CREATURE_STRIFE: CREATURE_PERIL)));
        }

        void DamageTaken(Unit* unit, uint32&)
        {
            hasBeenHit = true;

            if (Creature* other = GetOther())
                other->SetInCombatWithZone();
        }

        void EnterCombat(Unit* unit)
        {
            events.ScheduleEvent(EVENT_LUNCH_AGONY,                 1000);
            events.ScheduleEvent(EVENT_INTENSITY_OR_DISSIPATION,    2000);
        }

        void JustDied(Unit* killer)
        {
            Creature* other = GetOther();

            if (other && other->isDead())
            {
                if (Creature* loreWalker = me->GetMap()->GetCreature(me->GetInstanceScript()->GetObjectGuid(CREATURE_LOREWALKTER_STONESTEP)))
                    if(loreWalker->GetAI())
                        loreWalker->GetAI()->DoAction(ACTION_STATUS_FINISHED);
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_LUNCH_AGONY:
                    {
                        me->CastSpell(me->GetVictim(), SPELL_AGONY, false);
                        events.ScheduleEvent(EVENT_LUNCH_AGONY, 2000);
                        break;
                    }
                    case EVENT_INTENSITY_OR_DISSIPATION:
                    {
                        if (hasBeenHit)
                        {
                            me->RemoveAuraFromStack(SPELL_DISSIPATION);
                            if (!me->HasAura(SPELL_DISSIPATION))
                                me->AddAura(SPELL_INTENSITY, me);

                            if (++countIntensity > 10)
                                countIntensity = 10;

                            if (countIntensity == 10)
                            {
                                me->CastSpell(me, SPELL_ULTIMATE_POWER, false);
                                me->RemoveAura(SPELL_INTENSITY);
                                countIntensity = 0;
                            }
                        }
                        else
                        {
                            me->RemoveAuraFromStack(SPELL_INTENSITY);
                            if (!me->HasAura(SPELL_INTENSITY))
                                me->AddAura(SPELL_DISSIPATION, me);

                            if (--countIntensity < -10)
                                countIntensity = -10;
                        }
                        hasBeenHit = false;
                        events.ScheduleEvent(EVENT_INTENSITY_OR_DISSIPATION, 2000);
                        break;
                    }
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

// 59544 - nodding tiger (trash)
class mob_nodding_tiger: public CreatureScript
{
    public:
        mob_nodding_tiger() : CreatureScript("mob_nodding_tiger") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_nodding_tiger_AI(creature);
        }

        struct mob_nodding_tiger_AI : public ScriptedAI
        {
            mob_nodding_tiger_AI(Creature* creature) : ScriptedAI(creature) { }
            EventMap events;

            enum eEventsNoddingTiger
            {
                EVENT_CLAW = 1,
            };

            enum eSpellsNoddingTiger
            {
                SPELL_CLAW = 31289,
            };

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(EVENT_CLAW, 2000);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CLAW:
                            me->CastSpell(me->GetVictim(), SPELL_CLAW, false);
                            events.ScheduleEvent(EVENT_CLAW, 3000);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

// 59545 - golden beetle (trash)
class mob_golden_beetle: public CreatureScript
{
    public:
        mob_golden_beetle() : CreatureScript("mob_golden_beetle") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_golden_beetle_AI(creature);
        }

        struct mob_golden_beetle_AI : public ScriptedAI
        {
            mob_golden_beetle_AI(Creature* creature) : ScriptedAI(creature) { }
            EventMap events;

            enum eEventsGoldenBeetle
            {
                EVENT_SERRATED_SHASH = 1,
                EVENT_SHROUD_OF_GOLD = 2,
                EVENT_SLOW           = 3,
            };

            enum eSpellsGoldenBeetle
            {
                SPELL_SERRATED_SHASH = 128051,
                SPELL_SHROUD_OF_GOLD = 88023,
                SPELL_SLOW           = 31589,
            };

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(EVENT_SERRATED_SHASH, 2000);
                events.ScheduleEvent(EVENT_SHROUD_OF_GOLD, 4000);
                events.ScheduleEvent(3, 6000);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case 1:
                            me->CastSpell(me->GetVictim(), SPELL_SERRATED_SHASH, false);
                            events.ScheduleEvent(EVENT_SERRATED_SHASH, 10000);
                            break;
                        case 2:
                            me->CastSpell(me->GetVictim(), SPELL_SHROUD_OF_GOLD, false);
                            events.ScheduleEvent(EVENT_SHROUD_OF_GOLD, 5000);
                            break;
                        case 3:
                            me->CastSpell(me->GetVictim(), SPELL_SLOW, false);
                            events.ScheduleEvent(EVENT_SLOW, 15000);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

// 59547 - 65317 - the two junglers (trash)
class mob_jiang_xiang: public CreatureScript
{
    public:
        mob_jiang_xiang() : CreatureScript("mob_jiang_xiang") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_jiang_xiang_AI(creature);
        }

        struct mob_jiang_xiang_AI : public ScriptedAI
        {
            mob_jiang_xiang_AI(Creature* creature) : ScriptedAI(creature) { }
            EventMap events;

            enum eEventsJiangXiang
            {
                EVENT_AERIALIST_KICK = 1,
                //EVENT_ICE_TRAP       = 2,
                EVENT_THROW_TORCH    = 3,
            };

            enum eSpellsJiangXiang
            {
                SPELL_JUGGLER_JIANG         = 114745,
                SPELL_JUGGLER_XIANG         = 114718,

                SPELL_AERIALIST_KICK = 114805,
                //SPELL_ICE_TRAP       = 135382,
                SPELL_THROW_TORCH    = 114803,
            };

            void Reset()
            {
                if(me->GetEntry() == CREATURE_JIANG)
                    me->CastSpell(me, SPELL_JUGGLER_JIANG, false);
                else if(me->GetEntry() == CREATURE_XIANG)
                    me->CastSpell(me, SPELL_JUGGLER_XIANG, false);

                me->CastSpell(me, SPELL_SHA_CORRUPTION_3, false);
                events.Reset();
            }

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(EVENT_AERIALIST_KICK, 2000);
                events.ScheduleEvent(EVENT_THROW_TORCH, 4000);
                //events.ScheduleEvent(EVENT_ICE_TRAP, 6000);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_AERIALIST_KICK:
                        me->CastSpell(me->GetVictim(), SPELL_AERIALIST_KICK, false);
                        events.ScheduleEvent(EVENT_AERIALIST_KICK, 10000);
                        break;
                    //case EVENT_ICE_TRAP:
                    //    me->CastSpell(me->GetVictim(), SPELL_ICE_TRAP, false);
                    //    events.ScheduleEvent(EVENT_ICE_TRAP, 15000);
                    //    break;
                    case EVENT_THROW_TORCH:
                        me->CastSpell(me->GetVictim(), SPELL_THROW_TORCH, false);
                        events.ScheduleEvent(EVENT_THROW_TORCH, 5000);
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

// 59553 - songbird queen (trash)
class mob_songbird_queen: public CreatureScript
{
    public:
        mob_songbird_queen() : CreatureScript("mob_songbird_queen") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_songbird_queen_AI(creature);
        }

        struct mob_songbird_queen_AI : public ScriptedAI
        {
            mob_songbird_queen_AI(Creature* creature) : ScriptedAI(creature) { }
            EventMap events;

            enum eEventsSongbirdQueen
            {
                //EVENT_ICE_TRAP = 1,
                EVENT_SONGBIRD_SERENADE = 2,
            };

            enum eSpellsSongbirdQueen
            {
                //SPELL_ICE_TRAP = 135382,
                SPELL_SONGBIRD_SERENADE = 114826,
            };

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(EVENT_SONGBIRD_SERENADE, 2000);
                //events.ScheduleEvent(EVENT_ICE_TRAP, 6000);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    //case EVENT_ICE_TRAP:
                    //    me->CastSpell(me, SPELL_ICE_TRAP, false);
                    //    events.ScheduleEvent(EVENT_ICE_TRAP, 15000);
                    //    break;
                    case EVENT_SONGBIRD_SERENADE:
                        me->CastSpell(me->GetVictim(), SPELL_SONGBIRD_SERENADE, false);
                        events.ScheduleEvent(EVENT_SONGBIRD_SERENADE, 10000);
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

// 59149 - 56882 - 56871 - 56872 - 56873 - 56874 - 59545 - 59552 - 59544 (trash)
class mob_sha_corrupted_generic: public CreatureScript
{
public:
    mob_sha_corrupted_generic() : CreatureScript("mob_sha_corrupted_generic") { }
    mob_sha_corrupted_generic(const char* scriptname) : CreatureScript(scriptname) { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_sha_corrupted_generic_AI(creature);
    }

    struct mob_sha_corrupted_generic_AI : public ScriptedAI
    {
        mob_sha_corrupted_generic_AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset()
        {
            _Reset();
        }

        void _Reset()
        {
            me->CastSpell(me, SPELL_SHA_CORRUPTION, false);
        }
    };
};

// 59546 - talking fish (trash)
class mob_talking_fish: public mob_sha_corrupted_generic
{
    public:
        mob_talking_fish() : mob_sha_corrupted_generic("mob_talking_fish") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_sha_corrupted_generic_AI(creature);
        }

        enum eTalks
        {
            TALK_0,
            TALK_1,
            TALK_2,
            TALK_3,
        };

        enum eSpells
        {
            SPELL_WATER_BUBBLE          = 114549,
            SPELL_BUBLE_SPRAY           = 114811,
        };

        enum eEvents
        {
            EVENT_BUBLE_SPRAY = 1,
        };

        struct mob_talking_fish_AI : public mob_sha_corrupted_generic_AI
        {
            mob_talking_fish_AI(Creature* creature) : mob_sha_corrupted_generic_AI(creature) { }
            EventMap events;

            void Reset()
            {
                me->CastSpell(me, SPELL_WATER_BUBBLE, false);
                _Reset();
                events.Reset();
            }

            void EnterCombat(Unit* unit)
            {
                Talk(TALK_0 + urand(0, 3));
                events.ScheduleEvent(EVENT_BUBLE_SPRAY, 2000);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_BUBLE_SPRAY:
                        me->CastSpell(me->GetVictim(), SPELL_BUBLE_SPRAY, false);
                        events.ScheduleEvent(EVENT_BUBLE_SPRAY, 10000);
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

//59555 - hunting sha (trash)
class mob_hunting_sha: public mob_sha_corrupted_generic
{
public:
    mob_hunting_sha() : mob_sha_corrupted_generic("mob_hunting_sha") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_hunting_sha_AI(creature);
    }

    struct mob_hunting_sha_AI : public mob_sha_corrupted_generic_AI
    {
        mob_hunting_sha_AI(Creature* creature) : mob_sha_corrupted_generic_AI(creature) { }

        enum eSpellsHuntingSha
        {
            SPELL_HAUNTING_GAZE = 114650,
        };

        void Reset()
        {
            me->CastSpell(me, SPELL_HAUNTING_GAZE, false);
            _Reset();
        }
    };
};

//59553 - gru (trash)
class mob_lorewalker_gru: public mob_sha_corrupted_generic
{
public:
    mob_lorewalker_gru() : mob_sha_corrupted_generic("mob_lorewalker_gru") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_lorewalker_gru_AI(creature);
    }

    struct mob_lorewalker_gru_AI : public mob_sha_corrupted_generic_AI
    {
        mob_lorewalker_gru_AI(Creature* creature) : mob_sha_corrupted_generic_AI(creature) { }

        enum eSpellsGru
        {
            SPELL_SINGING_SONGBIRD      = 114789,
        };

        void Reset()
        {
            me->CastSpell(me, SPELL_SINGING_SONGBIRD, false);
            _Reset();
        }
    };
};

void AddSC_boss_lorewalker_stonestep()
{

    //core
    new boss_lorewalker_stonestep();
    new mob_lorewalker_scroll();
    //Suns
    new mob_sun();
    new mob_sunfire();
    new mob_zao();
    new mob_haunting_sha();
    //Trial
    new mob_peril_and_strife();
    //Trashes
    new mob_nodding_tiger();
    new mob_golden_beetle();
    new mob_jiang_xiang();
    new mob_songbird_queen();
    new mob_sha_corrupted_generic();
    new mob_talking_fish();
    new mob_hunting_sha();
    new mob_lorewalker_gru();
}
