/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "dragon_soul.h"
#include "Player.h"
#include "GameObject.h"
#include "SpellInfo.h"

enum Adds
{
};

enum Spells
{
    SPELL_FIERY_EXPLOSION       = 110263,
    SPELL_LIFEBINDING           = 109756,
    SPELL_OPEN_PORTAL           = 109527,
    SPELL_TWILIGHT_BREATH       = 105858,
};

enum Events
{
    EVENT_TWILIGHT_DRAKE = 1,
    EVENT_TWILIGHT_BREATH,
    EVENT_PATH,
    EVENT_PREULTRAXION,
};

enum Actions
{
    ACTION_LAST_DEF_OF_AZEROTH,
    ACTION_GIFT_OF_LIFE,
    ACTION_ESSENCE_OF_DREAMS,
    ACTION_SOURCE_OF_MAGIC,
    ACTION_TIMELOOP,
    ACTION_RITUAL_THRALL,
    ACTION_RITUAL_YSERA,
    ACTION_RITUAL_KALEC,
    ACTION_RITUAL_NOZ,
    ACTION_RITUAL_ALEXS,
    ACTION_DEATHWING_EVENT,
    ACTION_ULTRAXION_SPAWN,
};

enum ScriptedTexts
{
    //Afrasastrasz
    SAY_AFRA_1  = 0,
    SAY_AFRA_2  = 1,
    SAY_AFRA_3  = 2,
    SAY_AFRA_4  = 3,
    SAY_AFRA_5  = 4,

    //Tyrygosa
    SAY_TYRY_1  = 0,
    SAY_TYRY_2  = 1,
    SAY_TYRY_3  = 2,
    SAY_TYRY_4  = 3,
    SAY_TYRY_5  = 4,
    SAY_TYRY_6  = 5,
    SAY_TYRY_7  = 6,

    //Kalecgos
    SAY_KALEC_1  = 0,
    SAY_KALEC_2  = 1,
    SAY_KALEC_3  = 2,
    SAY_KALEC_4  = 3,
    SAY_KALEC_5  = 4,
    SAY_KALEC_6  = 5,
    SAY_KALEC_7  = 6,
    SAY_KALEC_8  = 7,

    //Alexstrasza
    SAY_ALEXS_1  = 0,
    SAY_ALEXS_2  = 1,
    SAY_ALEXS_3  = 2,
    SAY_ALEXS_4  = 3,

    //Ysera
    SAY_YSERA_1  = 0,
    SAY_YSERA_2  = 1,
    SAY_YSERA_3  = 2,

    //Nozdormu
    SAY_NOZ_1  = 0,

    //Thrall
    SAY_THRALL_1  = 0,
    SAY_THRALL_2  = 1,
    SAY_THRALL_3  = 2,
    SAY_THRALL_4  = 3,
    SAY_THRALL_5  = 4,
    SAY_THRALL_6  = 5,
    SAY_THRALL_7  = 6,
    SAY_THRALL_8  = 7,
    SAY_THRALL_9  = 8,

    //Deathwing
    SAY_DEATHW_1  = 0,
    SAY_DEATHW_2  = 1,
    SAY_DEATHW_3  = 2,
    SAY_DEATHW_4  = 3,

};

Position const DeathwingPos = { -1685.534f, -2383.067f, 353.860f, 3.24f };

const Position DeathwingPath[] =
{
    { -1619.036f, -2404.300f, 368.116f, 3.264f },
    { -1689.762f, -2293.969f, 366.197f, 2.799f },
};

class npc_trall_vs_ultraxion : public CreatureScript
{
    public:
        npc_trall_vs_ultraxion() : CreatureScript("npc_trall_vs_ultraxion") {}

        struct npc_trall_vs_ultraxionAI : public ScriptedAI
        {
            npc_trall_vs_ultraxionAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                timer = 0;
                phase = 0;
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!phase && me->GetExactDist(who) < 10.0f)
                    if (Player* player = who->ToPlayer())
                        phase = 1;
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_RITUAL_THRALL:
                        me->CastSpell(me, SPELL_WARD_OF_EARTH);
                        break;
                    case ACTION_LAST_DEF_OF_AZEROTH:
                        me->CastSpell(me, SPELL_LAST_DEF_OF_AZEROTH);
                        break;
                }
            }

            void UpdateAI(uint32 diff) override

            {
                if (!phase)
                    return;

                if (timer <= diff)
                {
                    Creature* kalec = me->FindNearestCreature(NPC_KALECGOS, 50.0f, true);
                    Creature* alexs = me->FindNearestCreature(NPC_ALEXTRASZA_THE_LIFE_BINDER, 50.0f, true);
                    Creature* ysera = me->FindNearestCreature(NPC_YSERA_THE_AWAKENED, 50.0f, true);
                    Creature* noz = me->FindNearestCreature(NPC_NOZDORMU_THE_TIMELESS_ONE, 50.0f, true);
                    Creature* portal = me->FindNearestCreature(NPC_TRAVEL_TO_EYE_OF_ETERNITY, 50.0f);
                    Creature* soul = me->FindNearestCreature(NPC_THE_DRAGON_SOUL, 50.0f);
                    switch (phase)
                    {
                        case 1:
                            Talk(SAY_THRALL_7);
                            timer = 12000;
                            break;
                        case 2:
                            alexs->AI()->Talk(SAY_ALEXS_3);
                            timer = 4000;
                            break;
                        case 3:
                            kalec->AI()->Talk(SAY_KALEC_6);
                            timer = 9000;
                            break;
                        case 4:
                            kalec->AI()->Talk(SAY_KALEC_7);
                            timer = 10000;
                            break;
                        case 5:
                            Talk(SAY_THRALL_8);
                            timer = 9000;
                            break;
                        case 6:
                            ysera->AI()->Talk(SAY_YSERA_3);
                            timer = 8000;
                            break;
                        case 7:
                            Talk(SAY_THRALL_9);
                            timer = 7000;
                            break;
                        case 8:
                            kalec->AI()->Talk(SAY_KALEC_8);
                            kalec->SetFacingToObject(portal);
                            portal->CastSpell(portal, SPELL_OPEN_PORTAL);
                            timer = 8000;
                            break;
                        case 9:
                            portal->CastSpell(portal, SPELL_TELEPORT_VISUAL_DISABLED, true);
                            portal->CastSpell(portal, SPELL_TELEPORT_VISUAL_ACTIVE, true);
                            kalec->SetFacingToObject(soul);
                            return;
                    }
                    ++phase;
                }
                else
                    timer -= diff;
            }

            private:
                InstanceScript* instance;
                int8 phase;
                uint32 timer;
                bool prehagara;

        };

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
        {
            if (Creature* deathwing = creature->FindNearestCreature(NPC_DEATHWING_PREULTRAXION, 1000.0f, true))
            {
                player->PlayerTalkClass->ClearMenus();
                CloseGossipMenuFor(player);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                creature->AI()->DoAction(ACTION_RITUAL_THRALL);

                if (Creature* kalec = creature->FindNearestCreature(NPC_KALECGOS, 50.0f, true))
                    kalec->AI()->DoAction(ACTION_RITUAL_KALEC);

                if (Creature* alexs = creature->FindNearestCreature(NPC_ALEXTRASZA_THE_LIFE_BINDER, 50.0f, true))
                    alexs->AI()->DoAction(ACTION_RITUAL_ALEXS);

                if (Creature* ysera = creature->FindNearestCreature(NPC_YSERA_THE_AWAKENED, 50.0f, true))
                    ysera->AI()->DoAction(ACTION_RITUAL_YSERA);

                if (Creature* noz = creature->FindNearestCreature(NPC_NOZDORMU_THE_TIMELESS_ONE, 50.0f, true))
                    noz->AI()->DoAction(ACTION_RITUAL_NOZ);

                if (Creature* soul = creature->FindNearestCreature(NPC_THE_DRAGON_SOUL, 50.0f))
                {
                    soul->GetMotionMaster()->MovePoint(0, soul->GetPositionX(), soul->GetPositionY(), soul->GetPositionZ()+ 4.0f);
                    soul->SetCanFly(true);
                    soul->SetDisableGravity(true);
                }
            }
            else
            {
                player->PlayerTalkClass->ClearMenus();
                CloseGossipMenuFor(player);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                if (Creature* ysera = creature->FindNearestCreature(NPC_YSERA_THE_AWAKENED, 200.0f, true))
                    ysera->AI()->DoAction(ACTION_ULTRAXION_SPAWN);
            }
            return true;
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_trall_vs_ultraxionAI(creature);
        }
};

class npc_ysera : public CreatureScript
{
    public:
        npc_ysera() : CreatureScript("npc_ysera") {}

        struct npc_yseraAI : public ScriptedAI
        {
            npc_yseraAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                timer = 0;
                phase = 0;
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!phase && me->GetExactDist(who) < 5.0f)
                    if (Player* player = who->ToPlayer())
                        if (instance->GetBossState(DATA_HAGARA) == DONE)
                            phase = 1;
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_RITUAL_YSERA:
                        me->CastSpell(me, SPELL_WARD_OF_DREAMS);
                        break;
                    case ACTION_ESSENCE_OF_DREAMS:
                        me->CastSpell(me, SPELL_ESSENCE_OF_DREAMS);
                        break;
                    case ACTION_ULTRAXION_SPAWN:
                        Talk(SAY_ALEXS_1);
                        me->SummonCreature(NPC_ULTRAXION, ultraxionPos[0], TEMPSUMMON_DEAD_DESPAWN);
                        break;
                }
            }

            void UpdateAI(uint32 diff) override

            {
                if (!phase)
                    return;

                if (timer <= diff)
                {
                    Creature* kalec = me->FindNearestCreature(NPC_KALECGOS, 50.0f, true);
                    Creature* alexs = me->FindNearestCreature(NPC_ALEXTRASZA_THE_LIFE_BINDER, 50.0f, true);
                    Creature* thrall = me->FindNearestCreature(NPC_THRALL_1, 50.0f, true);
                    Creature* noz = me->FindNearestCreature(NPC_NOZDORMU_THE_TIMELESS_ONE, 50.0f, true);
                    Creature* portal = me->FindNearestCreature(NPC_TRAVEL_TO_EYE_OF_ETERNITY, 50.0f);
                    Creature* soul = me->FindNearestCreature(NPC_THE_DRAGON_SOUL, 50.0f);
                    switch (phase)
                    {
                        case 1:;
                            Talk(SAY_YSERA_2);
                            DoCast(me, SPELL_CHARGING_UP_DREAMS);
                            me->SummonCreature(NPC_THE_DRAGON_SOUL, dsoulPos, TEMPSUMMON_MANUAL_DESPAWN);
                            me->SummonCreature(NPC_DEATHWING_PREULTRAXION, DeathwingPath[1], TEMPSUMMON_MANUAL_DESPAWN);
                            timer = 4000;
                            break;
                        case 2:
                            noz->AI()->Talk(SAY_NOZ_1);
                            noz->CastSpell(noz, SPELL_CHARGING_UP_TIME);
                            timer = 4000;
                            break;
                        case 3:
                            kalec->AI()->Talk(SAY_KALEC_4);
                            kalec->CastSpell(kalec, SPELL_CHARGING_UP_MAGIC);
                            timer = 5000;
                            break;
                        case 4:
                            alexs->AI()->Talk(SAY_ALEXS_4);
                            alexs->CastSpell(alexs, SPELL_CHARGING_UP_LIFE);
                            timer = 10000;
                            break;
                        case 5:
                            thrall->AI()->Talk(SAY_THRALL_3);
                            thrall->CastSpell(me, SPELL_CHARGING_UP_EARTH);
                            timer = 6000;
                            break;
                        case 6:
                            thrall->AI()->Talk(SAY_THRALL_6);
                            timer= 9000;
                            break;
                        case 7:
                            thrall->AI()->Talk(SAY_THRALL_4);
                            thrall->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            break;
                        case 8:
                            me->SetFacingToObject(soul);
                            return;
                    }
                    ++phase;
                }
                else
                    timer -= diff;
            }

            private:
                InstanceScript* instance;
                int8 phase;
                uint32 timer;

        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_yseraAI(creature);
        }
};

class npc_aspect_of_magic : public CreatureScript
{
public:
    npc_aspect_of_magic() : CreatureScript("npc_aspect_of_magic") { }

    struct npc_aspect_of_magicAI : public ScriptedAI
    {
        npc_aspect_of_magicAI(Creature* creature) : ScriptedAI(creature)
        {
            _drakenum = 0;
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
                case ACTION_RITUAL_KALEC:
                    me->CastSpell(me, SPELL_WARD_OF_MAGIC);
                    events.ScheduleEvent(EVENT_TWILIGHT_DRAKE, 10000);
                    break;
                case ACTION_SOURCE_OF_MAGIC:
                    me->CastSpell(me, SPELL_SOURCE_OF_MAGIC);
                    break;
            }
        }

        void UpdateAI(uint32 diff) override

        {

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TWILIGHT_DRAKE:
                    {
                        _drakenum++;
                        if (_drakenum <= 15)
                        {
                            angle = urand(1.77f, 4.82f);
                            me->SummonCreature(NPC_TWILIGHT_ASSAULTER, me->GetPositionX()+ 20*cos(angle), me->GetPositionY()+ 20*cos(angle), me->GetPositionZ()+ 13, 0, TEMPSUMMON_DEAD_DESPAWN);
                            events.ScheduleEvent(EVENT_TWILIGHT_DRAKE, 15333);
                        }
                        else if (_drakenum > 15)
                        {
                            if (Creature* deathwing = me->FindNearestCreature(NPC_DEATHWING_PREULTRAXION, 1000.0f, true))
                            {
                                deathwing->AI()->DoAction(ACTION_DEATHWING_EVENT);
                                events.CancelEvent(EVENT_TWILIGHT_DRAKE);
                            }
                        }

                        std::list<Player*> targets;
                        me->GetPlayerListInGrid(targets, 500.0f);

                        if (targets.size() == 0)
                        {
                            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_1, 100.0f, true))
                                thrall->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                            events.CancelEvent(EVENT_TWILIGHT_DRAKE);
                        }
                    }
                    break;
                default:
                    break;
                }
            }
        }
    private:
        EventMap events;
        InstanceScript* instance;
        uint8 _drakenum;
        float angle;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_aspect_of_magicAI(creature);
    }
};

class npc_nozdormu : public CreatureScript
{
public:
    npc_nozdormu() : CreatureScript("npc_nozdormu") {}

    struct npc_nozdormuAI : public ScriptedAI
    {
        npc_nozdormuAI(Creature* creature) : ScriptedAI(creature){}

        void DoAction(int32 action)
        {
            switch (action)
            {
                case ACTION_RITUAL_NOZ:
                    me->CastSpell(me, SPELL_WARD_OF_TIME);
                    break;
                case ACTION_TIMELOOP:
                    me->CastSpell(me, SPELL_TIMELOOP);
                    break;
            }
        }
    private:

        EventMap events;
        InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_nozdormuAI(creature);
    }
};

class npc_alexstrasza : public CreatureScript
{
public:
    npc_alexstrasza() : CreatureScript("npc_alexstrasza") {}

    struct npc_alexstraszaAI : public ScriptedAI
    {
        npc_alexstraszaAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            timer = 0;
            phase = 0;
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
                case ACTION_RITUAL_ALEXS:
                    me->CastSpell(me, SPELL_WARD_OF_LIFE);
                    break;
                case ACTION_GIFT_OF_LIFE:
                    me->CastSpell(me, SPELL_GIFT_OF_LIFE);
                    break;
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!phase && me->GetExactDist(who) < 10.0f)
                if (Player* player = who->ToPlayer())
                    if (instance->GetBossState(DATA_ULTRAXION) == DONE)
                        phase = 1;
        }

        void UpdateAI(uint32 diff) override

        {
            if (!phase)
                return;

            if (timer <= diff)
            {
                Creature* kalec = me->FindNearestCreature(NPC_KALECGOS, 50.0f, true);
                Creature* alexs = me->FindNearestCreature(NPC_ALEXTRASZA_THE_LIFE_BINDER, 50.0f, true);
                Creature* thrall = me->FindNearestCreature(NPC_THRALL_1, 50.0f, true);
                Creature* noz = me->FindNearestCreature(NPC_NOZDORMU_THE_TIMELESS_ONE, 50.0f, true);
                switch (phase)
                {
                    case 1:
                        Talk(SAY_ALEXS_1);
                        kalec->RemoveAllAuras();
                        alexs->RemoveAllAuras();
                        thrall->RemoveAllAuras();
                        noz->RemoveAllAuras();
                        if (Creature* soul = me->FindNearestCreature(NPC_THE_DRAGON_SOUL, 50.0f))
                        {
                            soul->RemoveAllAuras();
                            soul->GetMotionMaster()->MovePoint(0, dsoulPos);
                            soul->CastSpell(soul, SPELL_SOUL_CHARGED);
                        }
                        timer = 8000;
                        break;
                    case 2:
                        thrall->AI()->Talk(SAY_THRALL_5);
                        thrall->GetMotionMaster()->MovePoint(0, dsoulPos);
                        timer = 11000;
                        break;
                    case 3:
                        instance->DoCastSpellOnPlayers(SPELL_PLAY_MOVIE_DEATHWING_1);
                        timer = 2000;
                        break;
                    case 4:
                        me->SummonGameObject(GO_ALLIANCE_SHIP_1, skyfireSpawn.GetPositionX(), skyfireSpawn.GetPositionY(), skyfireSpawn.GetPositionZ(), skyfireSpawn.GetOrientation(), QuaternionData(), me->GetRespawnTime());
                        me->SummonCreature(NPC_SKY_CAPTAIN_SWAYZE, swayzePos, TEMPSUMMON_MANUAL_DESPAWN);
                        timer = 1000000;
                        return;
                }
                ++phase;
            }
            else
                timer -= diff;
        }

    private:
        int8 phase;
        uint32 timer;
        EventMap events;
        InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_alexstraszaAI(creature);
    }
};

class npc_dragonsoul_dragons : public CreatureScript
{
public:
    npc_dragonsoul_dragons() : CreatureScript("npc_dragonsoul_dragons") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_dragonsoul_dragonsAI (pCreature);
    }

    struct npc_dragonsoul_dragonsAI : public ScriptedAI
    {
        npc_dragonsoul_dragonsAI(Creature* pCreature) : ScriptedAI(pCreature){}

        EventMap events;

        void Reset() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.ScheduleEvent(EVENT_TWILIGHT_BREATH, 4000);
        }

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TWILIGHT_BREATH:
                        DoCastVictim(SPELL_TWILIGHT_BREATH);
                        events.ScheduleEvent(EVENT_TWILIGHT_BREATH, 4000);
                        break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_deathwing_preultraxion : public CreatureScript
{
public:
    npc_deathwing_preultraxion() : CreatureScript("npc_deathwing_preultraxion") { }

    struct npc_deathwing_preultraxionAI : public ScriptedAI
    {
        npc_deathwing_preultraxionAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            instance = pCreature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        uint32 path;
        uint32 text;

        void InitializeAI() override
        {
            me->SetSpeed(MOVE_FLIGHT, 3.0f);
            text = 0;
            path = 0;
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_HOVER);
            events.ScheduleEvent(EVENT_PATH, 15000);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
                case ACTION_DEATHWING_EVENT:
                    me->GetMotionMaster()->MovePoint(0, DeathwingPos);
                    events.CancelEvent(EVENT_PATH);
                    events.ScheduleEvent(EVENT_PREULTRAXION, 15000);
                    break;
            }
        }

        void Reset() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            while (uint32 eventid = events.ExecuteEvent())
            {
                switch (eventid)
                {
                case EVENT_PATH:
                    switch (path)
                    {
                        case 0:
                            me->GetMotionMaster()->MovePoint(0, DeathwingPath[path++]);
                            events.ScheduleEvent(EVENT_PATH, 8000);
                            break;
                        case 1:
                            me->GetMotionMaster()->MovePoint(0, DeathwingPath[path++]);
                            events.ScheduleEvent(EVENT_PATH, 8000);
                            break;
                        case 2:
                            path = 0;
                            me->GetMotionMaster()->MovePoint(0, DeathwingPath[path]);
                            events.ScheduleEvent(EVENT_PATH, 8000);
                            break;
                    default:
                        break;
                    }
                    break;

                    case EVENT_PREULTRAXION:
                        switch (text)
                        {
                            case 0:
                                ++text;
                                Talk(SAY_DEATHW_1);
                                events.ScheduleEvent(EVENT_PREULTRAXION, 12000);
                                break;
                            case 1:
                                ++text;
                                Talk(SAY_DEATHW_2);
                                events.ScheduleEvent(EVENT_PREULTRAXION, 10000);
                                break;
                            case 2:
                                ++text;
                                Talk(SAY_DEATHW_3);
                                events.ScheduleEvent(EVENT_PREULTRAXION, 10000);
                                break;
                            case 3:
                                if (Creature* ysera = me->FindNearestCreature(NPC_YSERA_THE_AWAKENED, 200.0f, true))
                                    ysera->AI()->DoAction(ACTION_ULTRAXION_SPAWN);

                                instance->SetBossState(DATA_TRALL_VS_ULTRAXION, DONE);
                                me->GetMotionMaster()->MovePoint(0, DeathwingPath[0]);
                                me->DespawnOrUnsummon(5000);
                                break;
                        default:
                            break;
                        }
                        break;
                }
            }
        }

    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_deathwing_preultraxionAI (pCreature);
    }
};

class npc_ds_Twilight_siege_breaker : public CreatureScript
{
public:
    npc_ds_Twilight_siege_breaker() : CreatureScript("npc_ds_Twilight_siege_breaker") { }

    struct npc_ds_Twilight_siege_breakerAI : public ScriptedAI
    {
        npc_ds_Twilight_siege_breakerAI(Creature* creature) : ScriptedAI(creature) {}

        void IsSummonedBy(Unit* summoner) override
        {
            if (Creature* stalker = me->FindNearestCreature(57261, 500.0f, true))
                me->GetMotionMaster()->MoveChase(stalker);
        }

        void JustDied(Unit* /*killer*/) override
        {
            DoCast(SPELL_FIERY_EXPLOSION);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ds_Twilight_siege_breakerAI(creature);
    }
};

class npc_ds_defenders : public CreatureScript
{
public:
    npc_ds_defenders() : CreatureScript("npc_ds_defenders") { }

    struct npc_ds_defendersAI : public ScriptedAI
    {
        npc_ds_defendersAI(Creature* creature) : ScriptedAI(creature) {}

            void InitializeAI() override
            {
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    me->SetVisible(false);
            }

            void UpdateAI(uint32 diff) override

            {
                if (Creature* morchok = me->FindNearestCreature(NPC_MORCHOK, 500.0f, false))
                    me->SetVisible(true);
            }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ds_defendersAI(creature);
    }
};

class npc_ds_lord_afrasastrasz : public CreatureScript
{
public:
    npc_ds_lord_afrasastrasz() : CreatureScript("npc_ds_lord_afrasastrasz") { }

    struct npc_ds_lord_afrasastraszAI : public ScriptedAI
    {
        npc_ds_lord_afrasastraszAI(Creature* creature) : ScriptedAI(creature) {}

        void IsSummonedBy(Unit* /*owner*/) override
        {
            Talk(SAY_AFRA_1);
            me->SetSpeed(MOVE_WALK, 1.5f);
            me->SetSpeed(MOVE_RUN, 1.5f);
            if (Creature* tyr = me->FindNearestCreature(NPC_TYRYGOSA, 500.0f, true))
                me->GetMotionMaster()->MoveFollow(tyr, 3.0f, 0);
        }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!who)
                    return;

                if (!who->ToCreature())
                    return;

                if (me->GetDistance(who) > 4.0f)
                    return;

                if (who->GetEntry() == NPC_TYRYGOSA)
                {
                    me->SetStandState(UNIT_STAND_STATE_KNEEL);
                    me->SummonCreature(NPC_LIFEBINDER, me->GetPositionX(), me->GetPositionY() + 4.0f, me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                    me->SummonCreature(NPC_LIFEBINDER, me->GetPositionX(), me->GetPositionY() - 4.0f, me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                }
            }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ds_lord_afrasastraszAI(creature);
    }
};

class npc_ds_lifebinder : public CreatureScript
{
public:
    npc_ds_lifebinder() : CreatureScript("npc_ds_lifebinder") { }

    struct npc_ds_lifebinderAI : public ScriptedAI
    {
        npc_ds_lifebinderAI(Creature* creature) : ScriptedAI(creature) {}

        void IsSummonedBy(Unit* /*owner*/) override
        {
            if (Creature* tyr = me->FindNearestCreature(NPC_TYRYGOSA, 5.0f, true))
                me->CastSpell(tyr, SPELL_LIFEBINDING);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ds_lifebinderAI(creature);
    }
};

class npc_ds_tyrygosa : public CreatureScript
{
public:
    npc_ds_tyrygosa() : CreatureScript("npc_ds_tyrygosa") { }

    struct npc_ds_tyrygosaAI : public ScriptedAI
    {
        npc_ds_tyrygosaAI(Creature* creature) : ScriptedAI(creature) {}

        void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
        {
            if (spellInfo->Id == SPELL_LIFEBINDING)
            {
                Talk(SAY_TYRY_1);
                me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
                me->RemoveFlag(OBJECT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ds_tyrygosaAI(creature);
    }
};

void AddSC_dragon_soul()
{
    new npc_trall_vs_ultraxion();
    new npc_ysera();
    new npc_aspect_of_magic();
    new npc_nozdormu();
    new npc_alexstrasza();
    new npc_dragonsoul_dragons();
    new npc_deathwing_preultraxion();
    new npc_ds_Twilight_siege_breaker();
    new npc_ds_defenders();
    new npc_ds_lord_afrasastrasz();
    new npc_ds_lifebinder();
    new npc_ds_tyrygosa();
}
