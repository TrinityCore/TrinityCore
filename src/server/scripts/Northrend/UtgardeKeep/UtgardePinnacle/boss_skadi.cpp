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
    EMOTE_RANGE                         = 2,
    SAY_DEATH                           = 3,
    SAY_DRAKE_DEATH                     = 5,
    //EMOTE_BREATH                        = 5,
    SAY_DRAKE_BREATH                    = 6
};

static Position SpawnLoc = {468.931f, -513.555f, 104.723f, 0};
static Position Location[]=
{
    // Boss
    {341.740997f, -516.955017f, 104.66900f, 0}, // 0
    {293.299f, -505.95f, 142.03f, 0},           // 1
    {301.664f, -535.164f, 146.097f, 0},         // 2
    {521.031006f, -544.667847f, 128.80064f, 0}, // 3
    {477.311981f, -509.296814f, 104.72308f, 0}, // 4
    {341.740997f, -516.955017f, 104.66900f, 0}, // 5
    {341.740997f, -516.955017f, 104.66900f, 0}, // 6
    {341.740997f, -516.955017f, 104.66900f, 0}, // 7
    // Breach Zone
    {485.4577f, -511.2515f, 115.3011f, 0},      //8
    {435.1892f, -514.5232f, 118.6719f, 0},      //9
    {413.9327f, -540.9407f, 138.2614f, 0},      //10
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
    SPELL_FREEZING_CLOUD    = 47579,
    SPELL_FREEZING_CLOUD_L  = 47590,
    SPELL_FREEZING_CLOUD_R  = 47592,
    SPELL_SKADI_TELEPORT    = 61790,
    // PHASE_GROUND
    SPELL_CRUSH             = 50234,
    SPELL_CRUSH_H           = 59330,
    SPELL_POISONED_SPEAR    = 50225, //isn't being casted =/
    SPELL_POISONED_SPEAR_H  = 59331,
    SPELL_WHIRLWIND         = 50228, //random target, but not the tank approx. every 20s
    SPELL_WHIRLWIND_H       = 59322
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
                me->SummonCreature(NPC_GRAUF, Location[0].GetPositionX(), Location[0].GetPositionY(), Location[0].GetPositionZ(), 3.0f);
            if (instance)  
                instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }

        void JustReachedHome() OVERRIDE
        {
            me->Dismount();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            if (!Unit::GetCreature(*me, instance->GetData64(DATA_NPC_GRAUF)))
                me->SummonCreature(NPC_GRAUF, Location[0].GetPositionX(), Location[0].GetPositionY(), Location[0].GetPositionZ(), 3.0f);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
             _EnterCombat();
            Talk(SAY_AGGRO);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
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
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE );
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

        void UpdateAI(uint32 diff) OVERRIDE
        {
            events.Update(diff);

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
                    events.SetPhase(PHASE_FLYING);
                    events.ScheduleEvent(EVENT_SUMMON, 10000, 0, PHASE_FLYING);
                    break;
                case EVENT_SUMMON:
                    SpawnMobs();
                    events.ScheduleEvent(EVENT_SUMMON, 20000, 0, PHASE_FLYING); //20000
                    break;
                case EVENT_CRUSH:
                    DoCastVictim(IsHeroic() ? SPELL_CRUSH_H : SPELL_CRUSH);
                    events.ScheduleEvent(EVENT_CRUSH, 8000, 0, PHASE_GROUND);  
                    break;
                case EVENT_POISONED_SPEAR:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, IsHeroic() ? SPELL_POISONED_SPEAR_H : SPELL_POISONED_SPEAR);
                    events.ScheduleEvent(EVENT_POISONED_SPEAR, 10000, 0, PHASE_GROUND);
                    break;
                case EVENT_WHIRLWIND:
                    DoCastAOE(IsHeroic() ?  SPELL_WHIRLWIND_H : SPELL_WHIRLWIND);
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
    {
        return new boss_skadiAI(creature);
    }
};

class npc_grauf : public CreatureScript
{
public:
    npc_grauf() : CreatureScript("npc_grauf") { }

    struct npc_graufAI : public ScriptedAI
    {
        npc_graufAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);
            instance = me->GetInstanceScript();
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
        }

        void JustReachedHome() OVERRIDE
        {
            if(Creature* pSkadi = Unit::GetCreature(*me, DATA_SKADI_THE_RUTHLESS))
            {
                pSkadi->AI()->EnterEvadeMode();
            }
            me->SetCanFly(false);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) OVERRIDE
        {
            if(!instance)
                return;

            if(spell->Id == SPELL_HARPOON_DAMAGE)
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

        void CastFreezingCloud(bool triggerLeft) {
            me->GetCreatureListWithEntryInGrid(CloudTriggerList, NPC_TRIGGER, 200.0f);
            if(!CloudTriggerList.empty())
            {
                for (std::list<Creature*>::const_iterator itr = CloudTriggerList.begin(); itr != CloudTriggerList.end(); ++itr)
                {
                    if (Creature* trigger = *itr)
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
                    case 0:
                        me->GetMotionMaster()->MovePoint(0, Location[1].GetPositionX(), Location[1].GetPositionY(), Location[1].GetPositionZ());
                        events.ScheduleEvent(EVENT_MOVE, 5*IN_MILLISECONDS, 0, PHASE_FLYING);
                        break;
                    case 1:
                        me->GetMotionMaster()->MovePoint(0, Location[2].GetPositionX(), Location[2].GetPositionY(), Location[2].GetPositionZ());
                        events.ScheduleEvent(EVENT_MOVE, 2*IN_MILLISECONDS, 0, PHASE_FLYING);
                        break;
                    case 2:
                        me->GetMotionMaster()->MovePoint(0, Location[3].GetPositionX(), Location[3].GetPositionY(), Location[3].GetPositionZ());
                        events.ScheduleEvent(EVENT_MOVE, 1.5*IN_MILLISECONDS, 0, PHASE_FLYING);
                        break;
                    case 3:
                        me->GetMotionMaster()->MovePoint(0, Location[8].GetPositionX(), Location[8].GetPositionY(), Location[8].GetPositionZ());
                        if(Creature* pSkadi = Unit::GetCreature(*me, instance->GetData64(DATA_SKADI_THE_RUTHLESS)))
                        {
                            pSkadi->AI()->Talk(SAY_DRAKE_BREATH);
                        }
                        events.ScheduleEvent(EVENT_MOVE, 2.5*IN_MILLISECONDS, 0, PHASE_FLYING);
                        break;
                    case 4:
                        me->GetMotionMaster()->MovePoint(0, Location[9].GetPositionX(), Location[9].GetPositionY(), Location[9].GetPositionZ());
                        switch(urand(0,1))
                        {
                        case 0 : 
                            DoCast(SPELL_FREEZING_CLOUD_L);
                            CastFreezingCloud(true);
                            break;
                        case 1 :
                            DoCast(SPELL_FREEZING_CLOUD_R);
                            CastFreezingCloud(false);
                            break;
                        }
                        events.ScheduleEvent(EVENT_STOP_CLOUD, 5*IN_MILLISECONDS, 0, PHASE_FLYING);
                        events.ScheduleEvent(EVENT_MOVE, 2*IN_MILLISECONDS, 0, PHASE_FLYING);
                        break;
                    case 5:
                        me->GetMotionMaster()->MovePoint(0, Location[10].GetPositionX(), Location[10].GetPositionY(), Location[10].GetPositionZ());
                        events.ScheduleEvent(EVENT_MOVE, 3*IN_MILLISECONDS, 0, PHASE_FLYING);
                        break;
                    case 6:
                        me->GetMotionMaster()->MovePoint(0, Location[3].GetPositionX(), Location[3].GetPositionY(), Location[3].GetPositionZ());
                        m_uiWaypointId = 2;
                        events.ScheduleEvent(EVENT_MOVE, 15*IN_MILLISECONDS, 0, PHASE_FLYING);
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