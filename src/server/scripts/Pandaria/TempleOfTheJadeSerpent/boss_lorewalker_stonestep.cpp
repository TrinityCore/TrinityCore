/*
    Dungeon : Template of the Jade Serpent 85-87
    Wise mari second boss
    Jade servers
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"

#define TYPE_SET_SUNS_SELECTABLE 2
#define TYPE_NUMBER_SUN_DEFEATED 1
#define TYPE_ZAO_ENTER_COMBAT    1
#define TYPE_ZAO_TALK            2
#define TYPE_LOREWALKTER_STONESTEP 0
#define TYPE_LOREWALKER_STONESTEP_TALK_AFTER_ZAO 3
#define TIMER_INTENSITY 2000
#define TIMER_DISSIPATION TIMER_INTENSITY
#define TYPE_GET_EVENT_LOREWALKER_STONESTEP 5
 

enum eBoss
{
    BOSS_LOREWALKER_STONESTEP = 1,
    BOSS_SUN = 2,
    BOSS_ZAO_SUNSEEKER = 3,

    BOSS_STRIFE = 4,
    BOSS_PERIL = 5,
};

enum eSpells
{
    SPELL_MEDITATION            = 122715,
    SPELL_ROOT_SELF             = 106822,
    SPELL_SUNFIRE_RAYS          = 107223, //09 26 28 - 09 46 29 - 10 06 46
    SPELL_SUN                   = 107349,
    SPELL_GROW_LOW              = 104921,
    SPELL_EXTRACT_SHA_3         = 111807,
    SPELL_EXTRACT_SHA_4         = 111768,
    SPELL_SHOOT_SUN             = 112084, //10 52 00 - 11 26 50 - 11 52 35
    SPELL_HELLFIRE_ARROW        = 113017,
    SPELL_SHA_CORRUPTION_2      = 120000,
    SPELL_EXTRACT_SHA           = 111764,

    SPELL_AGONY                 = 114571,
    SPELL_DISSIPATION           = 113379,
    SPELL_INTENSITY             = 113315,
    SPELL_ULTIMATE_POWER        = 113309,
};

enum eEvents
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

    EVENT_TALK_LOREWALKER_DESPAWN = 13,

    EVENT_STRIFE_0 = 14,
    EVENT_STRIFE_1 = 15,
    EVENT_STRIFE_2 = 16,
    EVENT_STRIFE_3 = 17,
    EVENT_STRIFE_4 = 18,
};

enum eTexts
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

enum eCreatures
{
    CREATURE_SCROLL                 = 57080,
    CREATURE_ZAO_SUNSEEKER          = 58826,
    CREATURE_HAUNTING_SHA_1         = 58865,
    CREATURE_HAUNTING_SHA_2         = 58856,
    CREATURE_SUN                    = 56915,
    CREATURE_OSONG                  = 56872,
};

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
            boss_lorewalker_stonestep_AI(Creature* creature) : BossAI(creature, BOSS_LOREWALKER_STONESTEP)
            {
                event_go = false;
            }

            bool event_go;
            uint64 scrollGUID;

            void Reset()
            {
                event_go = false;
                me->GetMotionMaster()->MoveTargetedHome();
                _Reset();
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                case TYPE_GET_EVENT_LOREWALKER_STONESTEP:
                    events.ScheduleEvent(EVENT_STRIFE_0, 500);
                    break;
                case 2://STATUS_LOREWALKER_STONESTEP_SPAWN_SUNS
                    events.ScheduleEvent(EVENT_SUN_0, 500);
                    break;
                case TYPE_LOREWALKER_STONESTEP_TALK_AFTER_ZAO:
                    Talk(EVENT_TALK_ZAO_ENTERS_COMBAT_0);
                    break;
                }
            }

            void KilledUnit(Unit* /*victim*/)
            {
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
            {
            }

            void MoveInLineOfSight(Unit* who)
            {
                // If Lorewalker stonestep sees a player, launch the speech.
                if (!event_go && who->GetTypeId() == TYPEID_PLAYER)
                {
                    event_go = true;
                    events.ScheduleEvent(EVENT_INTRO_0, 500);
                    instance->SetData(TYPE_LOREWALKTER_STONESTEP, 1);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TALK_LOREWALKER_DESPAWN:
                            me->ForcedDespawn();
                            break;
                        // This is the first speech when Lorewalker stonestep sees you for the first time.
                        case EVENT_INTRO_0:
                            Talk(EVENT_TALK_INTRO_0); //419621722
                            events.ScheduleEvent(EVENT_INTRO_1, 8019);
                            break;
                        case EVENT_INTRO_1:
                            Talk(EVENT_TALK_INTRO_1); //419629741
                            events.ScheduleEvent(EVENT_INTRO_2, 16162);
                            break;
                        case EVENT_INTRO_2:
                            Talk(EVENT_TALK_INTRO_2); //419645903
                            events.ScheduleEvent(EVENT_INTRO_3, 9578);
                            break;
                        case EVENT_INTRO_3:
                            Talk(EVENT_TALK_INTRO_3); //419655481
                            break;
                        // End of the first speech.

                        // TRIAL: Speech when the scroll is destroyed.
                        case EVENT_SUN_0:
                            me->RemoveAura(SPELL_ROOT_SELF);
                            Talk(EVENT_TALK_ZAO_APPEARS_0); //419667540
                            events.ScheduleEvent(EVENT_SUN_1, 9641);
                            break;
                        case EVENT_SUN_1:
                            Talk(EVENT_TALK_ZAO_APPEARS_1); //419677181
                            me->GetMotionMaster()->MovePoint(0, 838.033f, -2480.518f, 176.744f);
                            events.ScheduleEvent(EVENT_SUN_2, 811);
                            break;
                        case EVENT_SUN_2:
                            Talk(EVENT_TALK_ZAO_APPEARS_2); //419677992
                            me->GetMotionMaster()->MovePoint(0, 834.643f, -2490.361f, 179.897f);
                            events.ScheduleEvent(EVENT_SUN_3, 2792);
                            break;
                        case EVENT_SUN_3:
                            Talk(EVENT_TALK_ZAO_APPEARS_3); //419680784
                            me->SetFacingTo(1.239f);
                            instance->SetData(TYPE_SET_SUNS_SELECTABLE, 0);
                            events.ScheduleEvent(EVENT_SUN_4, 4214);
                            break;
                        case EVENT_SUN_4:
                            me->CastSpell(me, SPELL_MEDITATION, false);
                            Talk(EVENT_TALK_ZAO_APPEARS_4); //419722998
                            break;
                        // TRIAL: End of speech for destroyed scroll.

                        // ZAO: Speech when the scroll is destroyed.
                        case EVENT_STRIFE_0:
                            me->RemoveAura(SPELL_ROOT_SELF);
                            Talk(EVENT_TALK_STRIFE_0); //419667540
                            events.ScheduleEvent(EVENT_STRIFE_1, 9641);
                            break;
                        case EVENT_STRIFE_1:
                            Talk(EVENT_TALK_STRIFE_1); //419677181
                            me->GetMotionMaster()->MovePoint(0, 838.033f, -2480.518f, 176.744f);
                            events.ScheduleEvent(EVENT_STRIFE_2, 8011);
                            break;
                        case EVENT_STRIFE_2:
                            Talk(EVENT_TALK_STRIFE_2); //419677992
                            me->GetMotionMaster()->MovePoint(0, 834.643f, -2490.361f, 179.897f);
                            events.ScheduleEvent(EVENT_STRIFE_3, 5092);
                            break;
                        case EVENT_STRIFE_3:
                            {
                                Talk(EVENT_TALK_STRIFE_3); //419680784
                                me->SetFacingTo(1.239f);
                                events.ScheduleEvent(EVENT_STRIFE_4, 6014);
                                TempSummon* temp = me->SummonCreature(CREATURE_OSONG, 842.752f, -2468.911f, 174.959f);
                                if (!temp)
                                    break;
                                temp->setFaction(14);
                                temp->Attack(SelectTarget(SELECT_TARGET_RANDOM), true);
                                temp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                temp->SetFacingTo(1.239f);
                                sCreatureTextMgr->SendChat(temp, 0, 0);
                            }
                            break;
                        case EVENT_STRIFE_4:
                            me->CastSpell(me, SPELL_MEDITATION, false);
                            Talk(EVENT_TALK_STRIFE_4); //419722998
                            events.ScheduleEvent(EVENT_TALK_LOREWALKER_DESPAWN, 3000);
                            break;
                        // ZAO: End of speech for destroyed scroll.
                    }
                }

            }
        };
};

class mob_sun : public CreatureScript
{
    public:
        mob_sun() : CreatureScript("mob_sun") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_sun_AI(creature);
        }

        struct mob_sun_AI : public BossAI
        {
            mob_sun_AI(Creature* creature) : BossAI(creature, BOSS_SUN)
            {
                me->CastSpell(me, SPELL_SUN, false);
                me->CastSpell(me, SPELL_GROW_LOW, false);
                me->AddUnitState(UNIT_STATE_ROOT);
                me->SetDisableGravity(true);
                me->SetOrientation(1.239f);
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                case TYPE_SET_SUNS_SELECTABLE:
                    events.ScheduleEvent(1, 2000);
                    break;
                }
            }

            void JustDied(Unit* killer)
            {
                me->GetInstanceScript()->SetData(TYPE_NUMBER_SUN_DEFEATED, 1);
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case 1:
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM);
                        if (target != nullptr)
                            me->CastSpell(target, SPELL_SUNFIRE_RAYS, true);
                        events.ScheduleEvent(1, 5000);
                        break;
                    }
                }
            }
        };
};

class mob_zao : public CreatureScript
{
    public:
        mob_zao() : CreatureScript("mob_zao") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_zao_AI(creature);
        }

        struct mob_zao_AI : public BossAI
        {
            mob_zao_AI(Creature* creature) : BossAI(creature, BOSS_ZAO_SUNSEEKER)
            {
                isCorrupted = false;
                me->AddUnitState(UNIT_STATE_ROOT);
            }
            std::list<uint64> suns;

            bool isCorrupted;

            void DamageTaken(Unit* attacker, uint32&)
            {
                if (attacker->ToCreature()
                    && (attacker->ToCreature()->GetEntry() == CREATURE_HAUNTING_SHA_1
                    || attacker->ToCreature()->GetEntry() == CREATURE_HAUNTING_SHA_2))
                {
                    attacker->ToCreature()->ForcedDespawn();
                    isCorrupted = true;
                    me->setFaction(14);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->CastSpell(me, SPELL_SHA_CORRUPTION_2, false);
                }
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                case TYPE_ZAO_ENTER_COMBAT:
                    events.ScheduleEvent(EVENT_ZAO_ATTACK, 1000);
                    break;
                case TYPE_ZAO_TALK:
                    events.Reset();
                    events.ScheduleEvent(EVENT_ZAO_ENTER_COMBAT_1, 1000);
                    break;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (suns.empty())
                {
                    std::list<Creature*> searcher;
                    GetCreatureListWithEntryInGrid(searcher, me, CREATURE_SUN, 50.0f);
                    for (auto itr : searcher)
                    {
                        if (!itr)
                            continue;
                        suns.push_back(itr->GetGUID());
                    }
                    events.ScheduleEvent(EVENT_ZAO_ATTACK, 15000);
                }

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    // Speech of Zao entering combat
                    case EVENT_ZAO_ENTER_COMBAT_1: //419729036
                        Talk(EVENT_TALK_INTRO_0);
                        events.ScheduleEvent(EVENT_ZAO_ENTER_COMBAT_2, 32635);
                        break;
                    case EVENT_ZAO_ENTER_COMBAT_2: //419761671
                        me->GetInstanceScript()->SetData(TYPE_LOREWALKER_STONESTEP_TALK_AFTER_ZAO, 0);
                        events.ScheduleEvent(EVENT_ZAO_ATTACK, 1000);
                        break;
                    // End of speech of Zao entering combat
                    case EVENT_ZAO_ATTACK:
                        if (isCorrupted)
                        {
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM);
                            if (target != nullptr)
                                me->CastSpell(target, SPELL_HELLFIRE_ARROW, true);
                            events.ScheduleEvent(EVENT_ZAO_ATTACK, 3000);
                        }
                        else
                        {
                            if (!suns.empty())
                            {
                                uint32 rand = urand(0, suns.size());
                                uint64 guid_target = 0;
                                Creature* target = nullptr;
                                for (auto guid : suns)
                                {
                                    if (rand == 0)
                                    {
                                        guid_target = guid;
                                        break;
                                    }
                                    --rand;
                                }
                                target = me->GetInstanceScript()->instance->GetCreature(guid_target);
                                if (target != nullptr)
                                    me->CastSpell(target, SPELL_SHOOT_SUN, false);
                                else
                                    suns.remove(guid_target);
                                events.ScheduleEvent(EVENT_ZAO_ATTACK, 3000);
                            }
                        }
                        break;
                    }
                }
            }
        };
};

class mob_haunting_sha : public CreatureScript
{
    public:
        mob_haunting_sha() : CreatureScript("mob_haunting_sha") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_haunting_sha_AI(creature);
        }

        struct mob_haunting_sha_AI : public BossAI
        {
            mob_haunting_sha_AI(Creature* creature) : BossAI(creature, BOSS_ZAO_SUNSEEKER)
            {
                me->setFaction(14);
                me->CastSpell(me, SPELL_EXTRACT_SHA, false);
            }

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(1, 1000);
            }

            void DoAction(const int32 action)
            {
                if (action != 0)
                    return;

                uint64 guid = me->GetInstanceScript()->GetData64(CREATURE_ZAO_SUNSEEKER);
                if (guid != 0)
                {
                    Creature* zao = me->GetMap()->GetCreature(guid);
                    if(!zao)
                        return;

                    me->getThreatManager().addThreat(zao, 1000000.f);
                    me->AI()->AttackStart(zao);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!me->getVictim())
                {
                    Map::PlayerList const& PlayerList = me->GetInstanceScript()->instance->GetPlayers();

                    if (!PlayerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            Player* plr = i->getSource();
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
                    case 1:
                        if (!me->getVictim())
                            return;
                        me->CastSpell(me->getVictim(), 114646, false);
                        events.ScheduleEvent(1, 2000);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class mob_strife : public CreatureScript
{
    public:
        mob_strife() : CreatureScript("mob_strife") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_strife_AI(creature);
        }

        struct mob_strife_AI : public BossAI
        {
            mob_strife_AI(Creature* creature) : BossAI(creature, BOSS_STRIFE)
            {
                me->setFaction(14);
                timer_intensity = TIMER_INTENSITY;
                timer_dissipation = TIMER_DISSIPATION;
                countIntensity = 0;
                hasBeenHit = false;
            }
            uint32 timer_dissipation;
            uint32 timer_intensity;
            int32 countIntensity;
            bool hasBeenHit;

            void DamageTaken(Unit* unit, uint32&)
            {
                timer_dissipation = TIMER_DISSIPATION;
                hasBeenHit = true;
            }

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(1, 1000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (timer_dissipation <= diff)
                {
                    me->RemoveAuraFromStack(SPELL_INTENSITY);
                    if (!me->HasAura(SPELL_INTENSITY))
                        me->AddAura(SPELL_DISSIPATION, me);
                    timer_dissipation = TIMER_DISSIPATION;
                    --countIntensity;
                    if (countIntensity == -10)
                        countIntensity = -10;
                }
                else
                    timer_dissipation -= diff;

                if (timer_intensity <= diff)
                {
                    if (hasBeenHit)
                    {
                        me->RemoveAuraFromStack(SPELL_DISSIPATION);
                        if (!me->HasAura(SPELL_DISSIPATION))
                            me->AddAura(SPELL_INTENSITY, me);
                        ++countIntensity;

                        if (countIntensity == 10)
                        {
                            me->CastSpell(me, SPELL_ULTIMATE_POWER, false);
                            me->RemoveAura(SPELL_INTENSITY);
                        }
                        if (countIntensity > 10)
                            countIntensity = 10;
                    }
                    hasBeenHit = false;
                    timer_intensity = TIMER_INTENSITY;
                }
                else
                    timer_intensity -= diff;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case 1:
                        if (!me->getVictim())
                            return;
                        me->CastSpell(me->getVictim(), SPELL_AGONY, false);
                        events.ScheduleEvent(1, 2000);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class mob_peril : public CreatureScript
{
    public:
        mob_peril() : CreatureScript("mob_peril") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_peril_AI(creature);
        }

        struct mob_peril_AI : public BossAI
        {
            mob_peril_AI(Creature* creature) : BossAI(creature, BOSS_PERIL)
            {
                me->setFaction(14);
                timer_intensity = TIMER_INTENSITY;
                timer_dissipation = TIMER_DISSIPATION;
                countIntensity = 0;
                hasBeenHit = false;
            }
            uint32 timer_dissipation;
            uint32 timer_intensity;
            int32 countIntensity;
            bool hasBeenHit;

            void DamageTaken(Unit* unit, uint32&)
            {
                timer_dissipation = TIMER_DISSIPATION;
                hasBeenHit = true;
            }

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(1, 1000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (timer_dissipation <= diff)
                {
                    me->RemoveAuraFromStack(SPELL_INTENSITY);
                    if (!me->HasAura(SPELL_INTENSITY))
                        me->AddAura(SPELL_DISSIPATION, me);
                    timer_dissipation = TIMER_DISSIPATION;
                    --countIntensity;
                    if (countIntensity == -10)
                        countIntensity = -10;
                }
                else
                    timer_dissipation -= diff;

                if (timer_intensity <= diff)
                {
                    if (hasBeenHit)
                    {
                        me->RemoveAuraFromStack(SPELL_DISSIPATION);
                        if (!me->HasAura(SPELL_DISSIPATION))
                            me->AddAura(SPELL_INTENSITY, me);
                        ++countIntensity;

                        if (countIntensity == 10)
                        {
                            me->CastSpell(me, SPELL_ULTIMATE_POWER, false);
                            me->RemoveAura(SPELL_INTENSITY);
                        }
                        if (countIntensity > 10)
                            countIntensity = 10;
                    }
                    hasBeenHit = false;
                    timer_intensity = TIMER_INTENSITY;
                }
                else
                    timer_intensity -= diff;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case 1:
                        if (!me->getVictim())
                            return;
                        me->CastSpell(me->getVictim(), SPELL_AGONY, false);
                        events.ScheduleEvent(1, 2000);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

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
            mob_nodding_tiger_AI(Creature* creature) : ScriptedAI(creature)
            {
            }
            EventMap events;

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(1, 2000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case 1:
                        me->CastSpell(me->getVictim(), 31289, false);
                        events.ScheduleEvent(1, 3000);
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

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
            mob_golden_beetle_AI(Creature* creature) : ScriptedAI(creature)
            {
            }
            EventMap events;

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(1, 2000);
                events.ScheduleEvent(2, 4000);
                events.ScheduleEvent(3, 6000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case 1:
                        me->CastSpell(me->getVictim(), 128051, false);
                        events.ScheduleEvent(1, 10000);
                        break;
                    case 2:
                        me->CastSpell(me->getVictim(), 88023, false);
                        events.ScheduleEvent(2, 5000);
                        break;
                    case 3:
                        me->CastSpell(me->getVictim(), 31589, false);
                        events.ScheduleEvent(3, 15000);
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

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
            mob_jiang_xiang_AI(Creature* creature) : ScriptedAI(creature)
            {
            }
            EventMap events;

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(1, 2000);
                events.ScheduleEvent(2, 4000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case 1:
                        me->CastSpell(me->getVictim(), 114805, false);
                        events.ScheduleEvent(1, 10000);
                        break;
                    case 2:
                        me->CastSpell(me->getVictim(), 114803, false);
                        events.ScheduleEvent(2, 5000);
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

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
            mob_songbird_queen_AI(Creature* creature) : ScriptedAI(creature)
            {
            }
            EventMap events;

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(1, 2000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case 1:
                        me->CastSpell(me->getVictim(), 114826, false);
                        events.ScheduleEvent(1, 10000);
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

class mob_talking_fish: public CreatureScript
{
    public:
        mob_talking_fish() : CreatureScript("mob_talking_fish") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_talking_fish_AI(creature);
        }

        enum eTalks
        {
            TALK_0,
            TALK_1,
            TALK_2,
            TALK_3,
        };

        struct mob_talking_fish_AI : public ScriptedAI
        {
            mob_talking_fish_AI(Creature* creature) : ScriptedAI(creature)
            {
            }
            EventMap events;

            void EnterCombat(Unit* unit)
            {
                Talk(TALK_0 + urand(0, 3));
                events.ScheduleEvent(1, 2000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case 1:
                        me->CastSpell(me->getVictim(), 114811, false);
                        events.ScheduleEvent(1, 10000);
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

void AddSC_boss_lorewalker_stonestep()
{
    new boss_lorewalker_stonestep();
    new mob_sun();
    new mob_zao();
    new mob_haunting_sha();
    new mob_peril();
    new mob_strife();
    //Trashes
    new mob_nodding_tiger();
    new mob_golden_beetle();
    new mob_jiang_xiang();
    new mob_songbird_queen();
    new mob_talking_fish();
}