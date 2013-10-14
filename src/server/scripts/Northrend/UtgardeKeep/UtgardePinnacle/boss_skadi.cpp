/*
* Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "utgarde_pinnacle.h"
#include "Player.h"
#include "SpellInfo.h"

enum Yells
{
    SAY_AGGRO                           = 0,
    SAY_KILL                            = 1,
    SAY_DEATH                           = 3,
    SAY_DRAKE_DEATH                     = 5,
    SAY_DRAKE_BREATH                    = 6,
    EMOTE_BREATH                        = 1,
    EMOTE_RANGE                         = 2
};

static Position SpawnLoc = {468.931f, -513.555f, 104.723f, 0};

static Position Location[] =
{
    // Skadi
    {343.0203f, -507.3246f, 104.567f,  0}, // 0 24:31
    //Grauf
    {310.2165f, -510.5302f, 120.5487f, 0}, // 1 24:36
    {300.8685f, -520.3249f, 133.3664f, 0}, // 2
    {298.3447f, -529.4818f, 137.2831f, 0}, // 3
    {309.0959f, -540.3195f, 134.9774f, 0}, // 4
    {323.6415f, -547.9715f, 130.3106f, 0}, // 5
    {357.078f,  -549.1597f, 116.3105f, 0}, // 6
    {401.2573f, -550.2768f, 114.9216f, 0}, // 7
    {464.5062f, -555.9442f, 114.4494f, 0}, // 8
    {496.192f,  -556.9628f, 114.8661f, 0}, // 9
    {523.2011f, -548.9916f, 114.8661f, 0}, // 10
    //
    {523.2011f, -548.9916f, 114.8661f, 0}, // 11 24:52 -> within Range
    //
    {496.434f,  -517.578f,  120.0f,    0}, // 12 24:57
    //
    {496.434f,  -517.578f,  120.0f,    0}, // 13 25:02 -> breath
    //
    {453.1242f, -517.17f,   120.0273f, 0}, // 14 25:04
    {388.3312f, -514.3768f, 121.1193f, 0}, // 15
    {340.2752f, -512.0926f, 122.3138f, 0}, // 16
    {313.0756f, -509.138f,  125.175f,  0}, // 17
    {296.6964f, -522.6705f, 133.7026f, 0}, // 18
    {301.2957f, -549.4583f, 137.4249f, 0}, // 19
    {335.0746f, -552.1211f, 119.8416f, 0}, // 20
    {397.6237f, -553.9203f, 119.8416f, 0}, // 21
    {459.6321f, -558.0078f, 119.8416f, 0}, // 22
    {505.5458f, -568.7815f, 119.8416f, 0}, // 23
    {518.099f,  -560.8499f, 119.8416f, 0}, // 24
    {520.4827f, -541.5633f, 119.8416f, 0}, // 25
    //
    {520.4827f, -541.5633f, 119.8416f, 0},// 26 25:29 -> range
    //
    {496.434f,  -517.578f,  120.0f,    0},// 27 25:33
    //
    {496.434f,  -517.578f,  120.0f,    0},// 28 25:37 -> breath
    //
    {496.434f,  -517.578f,  120.0f,    0},// 29 25:38
    //
    {496.434f,  -517.578f,  106.8871f, 0},// 30 25:38
    // Breach Zone
    {485.4577f, -511.2515f, 115.3011f, 0},      //31
    {435.1892f, -514.5232f, 118.6719f, 0},      //32
    {413.9327f, -540.9407f, 138.2614f, 0}, //33
    {341.740997f, -516.955017f, 104.66900f, 3.0f}     // 34 Grauf Spawn
};

enum Phases
{
    PHASE_INTRO     = 1,
    PHASE_FLYING    = 2,
    PHASE_SHOOTABLE = 3,
    PHASE_GROUND    = 4
};

enum Events
{
    EVENT_CRUSH             = 1,
    EVENT_POISONED_SPEAR    = 2,
    EVENT_WHIRLWIND         = 3,
    EVENT_MOUNT             = 4,
    EVENT_MOVE              = 5,
    EVENT_STOP_CLOUD        = 6,
    EVENT_SUMMON            = 7
};

enum Spells
{
    // PHASE_INTRO
    SPELL_RIDE_VEHICLE      = 61791,
    // PHASE_FLYING
    SPELL_HARPOON_DAMAGE    = 48642, 
    SPELL_FREEZING_CLOUD_L  = 47590,
    SPELL_FREEZING_CLOUD_R  = 47592,
    SPELL_FREEZING_CLOUD_1  = 47594,
    SPELL_FREEZING_CLOUD_2  = 60020,
    SPELL_SKADI_TELEPORT    = 61790,
    // PHASE_GROUND
    SPELL_CRUSH             = 50234,
    SPELL_POISONED_SPEAR    = 50225, //isn't being casted =/
    SPELL_WHIRLWIND         = 50228 //random target, but not the tank approx. every 20s
};

enum Creatures
{
    NPC_YMIRJAR_WARRIOR       = 26690,
    NPC_YMIRJAR_WITCH_DOCTOR  = 26691,
    NPC_YMIRJAR_HARPOONER     = 26692,
    NPC_TRIGGER               = 28351
};

enum Achievments
{
    ACHIEV_TIMED_START_EVENT                      = 17726,
};

class boss_skadi : public CreatureScript
{
public:
    boss_skadi() : CreatureScript("boss_skadi") { }

    struct boss_skadiAI : public BossAI
    {
        boss_skadiAI(Creature* creature) : BossAI(creature, DATA_SKADI_THE_RUTHLESS), Summons(me)
        {
            instance = creature->GetInstanceScript();
            m_uiGraufGUID = 0;
        }

        InstanceScript* instance;
        SummonList Summons;
        uint64 m_uiGraufGUID;
        std::vector<uint64> triggersGUID;

        void Reset() OVERRIDE
        {
            _Reset();
            triggersGUID.clear();

            events.SetPhase(PHASE_INTRO);

            Summons.DespawnAll();
            me->SetSpeed(MOVE_FLIGHT, 3.0f);

            if ((Unit::GetCreature(*me, instance->GetData64(DATA_NPC_GRAUF)) == NULL) && !me->IsMounted())
                me->SummonCreature(NPC_GRAUF, Location[34]);
            if (instance)  
                instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }

        void JustReachedHome() OVERRIDE
        {
            me->Dismount();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            if (!Unit::GetCreature(*me, instance->GetData64(DATA_NPC_GRAUF)))
                me->SummonCreature(NPC_GRAUF, Location[34]);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
             _EnterCombat();
            Talk(SAY_AGGRO);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNK_6);
            events.SetPhase(PHASE_INTRO);
            events.ScheduleEvent(EVENT_MOUNT, 1 * IN_MILLISECONDS);
            events.SetPhase(PHASE_INTRO);
            events.ScheduleEvent(EVENT_MOUNT, 1 * IN_MILLISECONDS);
            if (instance)
                instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }

        void JustSummoned(Creature* summoned) OVERRIDE
        {
            switch (summoned->GetEntry())
            {
            case NPC_YMIRJAR_WARRIOR:
            case NPC_YMIRJAR_WITCH_DOCTOR:
            case NPC_YMIRJAR_HARPOONER:
                summoned->setActive(true);
                summoned->SetInCombatWithZone();
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    summoned->AI()->AttackStart(target);
                break;
            }
            Summons.Summon(summoned);
        }

        void SummonedCreatureDespawn(Creature* summoned) OVERRIDE
        {
            Summons.Despawn(summoned);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) OVERRIDE
        {
            if(spell->Id == SPELL_SKADI_TELEPORT)
            {
                events.SetPhase(PHASE_GROUND);
                events.ScheduleEvent(EVENT_CRUSH, 8000, 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_POISONED_SPEAR, 10000, 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_WHIRLWIND, 20000, 0, PHASE_GROUND);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_PLAY_DEATH_ANIM);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PET_IN_COMBAT);
            }
        }

        void KilledUnit(Unit* victim) OVERRIDE
        {
            if(victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILL);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEATH);
            _JustDied();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            events.Update(diff);

            if((events.IsInPhase(PHASE_FLYING) || events.IsInPhase(PHASE_GROUND)) && !UpdateVictim())

        void UpdateAI(uint32 diff) OVERRIDE
            if((events.IsInPhase(PHASE_FLYING) || events.IsInPhase(PHASE_GROUND)) && !UpdateVictim())
                return;

            if(events.IsInPhase(PHASE_GROUND))
                DoMeleeAttackIfReady();

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MOUNT:                    
                    me->CastSpell(me->GetUnit(*me, instance->GetData64(DATA_NPC_GRAUF)), SPELL_RIDE_VEHICLE);
                    me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_PLAY_DEATH_ANIM | UNIT_FLAG2_REGENERATE_POWER);
                    events.SetPhase(PHASE_FLYING);
                    events.ScheduleEvent(EVENT_SUMMON, 10000, 0, PHASE_FLYING);
                    break;
                case EVENT_SUMMON:
                    SpawnMobs();
                    events.ScheduleEvent(EVENT_SUMMON, 20000, 0, PHASE_FLYING); //20000
                    break;
                case EVENT_CRUSH:
                    DoCastVictim(SPELL_CRUSH);
                    events.ScheduleEvent(EVENT_CRUSH, 8000, 0, PHASE_GROUND);  
                    break;
                case EVENT_POISONED_SPEAR:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_POISONED_SPEAR);
                    events.ScheduleEvent(EVENT_POISONED_SPEAR, 10000, 0, PHASE_GROUND);
                    break;
                case EVENT_WHIRLWIND:
                    me->AI()->SelectTarget(SELECT_TARGET_BOTTOMAGGRO);
                    DoCastAOE(SPELL_WHIRLWIND);
                    events.ScheduleEvent(EVENT_WHIRLWIND, 23000, 0, PHASE_GROUND);
                    break;                        
                }
            }
        }

        void SpawnMobs()
        {
            for (uint8 i = 0; i < DUNGEON_MODE(5, 6); ++i)
            {
                switch (urand(0, 2))
                {
                case 0:
                    me->SummonCreature(NPC_YMIRJAR_WARRIOR, SpawnLoc.GetPositionX()+rand()%5, SpawnLoc.GetPositionY()+rand()%5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    break;
                case 1:
                    me->SummonCreature(NPC_YMIRJAR_WITCH_DOCTOR, SpawnLoc.GetPositionX()+rand()%5, SpawnLoc.GetPositionY()+rand()%5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    break;
                case 2:
                    me->SummonCreature(NPC_YMIRJAR_HARPOONER, SpawnLoc.GetPositionX()+rand()%5, SpawnLoc.GetPositionY()+rand()%5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    break;
                }
            }
        } 
    };
    CreatureAI* GetAI(Creature* creature) const OVERRIDE
};
    {
        return new boss_skadiAI(creature);
    }
};

class npc_grauf : public CreatureScript
{
public:
    npc_grauf() : CreatureScript("npc_grauf") { }
        }

    struct npc_graufAI : public ScriptedAI
        EventMap events;
        uint32 m_uiWaypointId;
        std::list<Creature*> CloudTriggerList;
        uint8 harpoonsHit;

        void Reset() OVERRIDE
    {
        npc_graufAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);
            instance = me->GetInstanceScript();
            
            if(Creature* pSkadi = Unit::GetCreature(*me, DATA_SKADI_THE_RUTHLESS))
            {
                pSkadi->AI()->EnterEvadeMode();
            me->SetCanFly(false);
        }

        InstanceScript* instance;
        EventMap events;
        uint32 m_uiWaypointId;
        std::list<Creature*> CloudTriggerList;
        uint8 harpoonsHit;
        

        void Reset() OVERRIDE
        {
            events.SetPhase(PHASE_INTRO);
            m_uiWaypointId = 0;
            harpoonsHit = 0;
            {
                if(me->GetHealth() <= me->GetMaxHealth() * (IsHeroic() ? 0.17f : 0.27f))
                {
                    if(Creature* pSkadi = Unit::GetCreature(*me, instance->GetData64(DATA_SKADI_THE_RUTHLESS)))
                    {
                        me->RemoveAllAuras();
                        pSkadi->CastSpell(pSkadi, SPELL_SKADI_TELEPORT, true);
                        pSkadi->AI()->Talk(SAY_DRAKE_DEATH);
                    }
                }
                me->DealDamage(me, me->GetMaxHealth() * (IsHeroic() ? 0.17f : 0.25f), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);
                harpoonsHit++;
            }

        void JustReachedHome() OVERRIDE
            {
            if(Creature* pSkadi = Unit::GetCreature(*me, DATA_SKADI_THE_RUTHLESS))
            {
                pSkadi->AI()->EnterEvadeMode();
            }
            me->SetDisableGravity(false);
                me->SetWalk(false);
            }
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) OVERRIDE
            me->GetCreatureListWithEntryInGrid(CloudTriggerList, NPC_TRIGGER, 200.0f);
            if(!CloudTriggerList.empty())
            {
            if(!instance)
                return;

            if(spell->Id == SPELL_HARPOON_DAMAGE)
                {
                if(me->GetHealth() <= me->GetMaxHealth() * (IsHeroic() ? 0.17f : 0.27f))
                    {
                        if (trigger->GetPositionY() > -511.0f && triggerLeft == true)
                            trigger->CastSpell(trigger, SPELL_FREEZING_CLOUD, true);
                        else if (trigger->GetPositionY() < -511.0f && triggerLeft == false)
                            trigger->CastSpell(trigger, SPELL_FREEZING_CLOUD, true);
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            events.Update(diff);

            //if (me->GetPositionX() >= 519)
            //{
            //    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            //    Talk(EMOTE_RANGE);
            //}
            //else
            //{
            //    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            //}

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MOVE:
                    switch (m_uiWaypointId)
                    {
                    if(Creature* pSkadi = Unit::GetCreature(*me, instance->GetData64(DATA_SKADI_THE_RUTHLESS)))
                    {
                        me->RemoveAllAuras();
                        pSkadi->CastSpell(pSkadi, SPELL_SKADI_TELEPORT, true);
                        pSkadi->AI()->Talk(SAY_DRAKE_DEATH);
                    }
                }
                me->DealDamage(me, me->GetMaxHealth() * (IsHeroic() ? 0.17f : 0.25f), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);
                harpoonsHit++;
            }
            if(spell->Id == SPELL_RIDE_VEHICLE)
            {
                events.SetPhase(PHASE_FLYING);
                events.ScheduleEvent(EVENT_MOVE, 1000, 0, PHASE_FLYING);
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->SetHover(true);
                me->SetWalk(false);
            }
        }

        void MovementInform(uint32 type, uint32 id) OVERRIDE
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case 1:
                        Talk(EMOTE_RANGE);
                        break;
                    case 2:
                        Talk(EMOTE_BREATH);
                        CastFreezingCloud();
                        break;
                    default:
                        break;
                }
            }

        void CastFreezingCloud() {
        void CastFreezingCloud() {
            me->GetCreatureListWithEntryInGrid(CloudTriggerList, NPC_TRIGGER, 200.0f);
            bool triggerLeft = urand(0,1);
            if(!CloudTriggerList.empty())
            {
                for (std::list<Creature*>::const_iterator itr = CloudTriggerList.begin(); itr != CloudTriggerList.end(); ++itr)
                {
                    if (Creature* trigger = *itr)
                    {
                        if (trigger->GetPositionY() > -511.0f && triggerLeft == true)
                        {
                            trigger->CastSpell(trigger, SPELL_FREEZING_CLOUD_1, true);
                            trigger->CastSpell(trigger, SPELL_FREEZING_CLOUD_2, true);
                        }
                        else if (trigger->GetPositionY() < -511.0f && triggerLeft == false)
                        {
                            trigger->CastSpell(trigger, SPELL_FREEZING_CLOUD_1, true);
                            trigger->CastSpell(trigger, SPELL_FREEZING_CLOUD_2, true);
                        }
                        }
                    }
                }
            }
        void UpdateAI(uint32 diff) OVERRIDE
                        {
            events.Update(diff);

            //if (me->GetPositionX() >= 519)
            //{
            //    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            //    Talk(EMOTE_RANGE);
            //}
            //else
            //{
            //    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            //}

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MOVE:
                    switch(m_uiWaypointId)
                    {
                        case 0:
                            me->GetMotionMaster()->MovePoint(0, Location[10]);
                            events.ScheduleEvent(EVENT_MOVE, 15*IN_MILLISECONDS, 0, PHASE_FLYING);
                            break;
                        case 1:
                            me->GetMotionMaster()->MovePoint(1, Location[11]);
                            
                            events.ScheduleEvent(EVENT_MOVE, 5*IN_MILLISECONDS, 0, PHASE_FLYING);
                            break;
                        case 2:
                            me->GetMotionMaster()->MovePoint(0, Location[12]);
                            events.ScheduleEvent(EVENT_MOVE, 5*IN_MILLISECONDS, 0, PHASE_FLYING);
                            break;
                        case 3:
                            me->GetMotionMaster()->MovePoint(2, Location[13]);
                            events.ScheduleEvent(EVENT_STOP_CLOUD, 5*IN_MILLISECONDS,0, PHASE_FLYING);
                            events.ScheduleEvent(EVENT_MOVE, 2*IN_MILLISECONDS, 0, PHASE_FLYING);
                            break;
                        case 4:
                            me->GetMotionMaster()->MovePoint(0, Location[25]);
                            events.ScheduleEvent(EVENT_MOVE, 25*IN_MILLISECONDS, 0, PHASE_FLYING);
                            break;
                        case 5:
                            me->GetMotionMaster()->MovePoint(1, Location[26]);
                            events.ScheduleEvent(EVENT_MOVE, 4*IN_MILLISECONDS, 0, PHASE_FLYING);
                            break;
                        case 6:
                            me->GetMotionMaster()->MovePoint(0, Location[27]);
                            events.ScheduleEvent(EVENT_MOVE, 4*IN_MILLISECONDS, 0, PHASE_FLYING);
                            break;
                        case 7:
                            me->GetMotionMaster()->MovePoint(1, Location[28]);
                            events.ScheduleEvent(EVENT_STOP_CLOUD, 5*IN_MILLISECONDS,0, PHASE_FLYING);
                            events.ScheduleEvent(EVENT_MOVE, 1*IN_MILLISECONDS, 0, PHASE_FLYING);
                            break;
                        case 8:
                            me->GetMotionMaster()->MovePoint(0, Location[29]);
                            m_uiWaypointId = 1;
                            events.ScheduleEvent(EVENT_MOVE, 4*IN_MILLISECONDS, 0, PHASE_FLYING);
                            break;
                    }
                    m_uiWaypointId++;
                    break;
                case EVENT_STOP_CLOUD:
                    me->RemoveAurasDueToSpell(SPELL_FREEZING_CLOUD_L);
                    me->RemoveAurasDueToSpell(SPELL_FREEZING_CLOUD_R);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_graufAI(creature);
    }
};

class go_harpoon_launcher : public GameObjectScript
{
public:
    go_harpoon_launcher() : GameObjectScript("go_harpoon_launcher") { }

    bool OnGossipHello(Player* player, GameObject* go) OVERRIDE
    {
        InstanceScript* instance = go->GetInstanceScript();

        if (!instance)
            return false;

        return false;
    }
};

void AddSC_boss_skadi()
{
    new boss_skadi();
    new npc_grauf();
    new go_harpoon_launcher();
}