 /*
  * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
  * Copyright (C) 2010-2018 Trinity <http://www.projecttrinity.org/>
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
#include "halls_of_origination.h"
#include "GameObject.h"
#include "ScriptedGossip.h"

enum Quotes
{
    SAY_BRANN_INTRO_1           = 0,
    SAY_BRANN_INTRO_2           = 1,
    SAY_BRANN_INTRO_3           = 2,
    SAY_BRANN_INTRO_4           = 3,
    SAY_BRANN_INTRO_5           = 4,
    SAY_BRANN_INTRO_6           = 5,
    SAY_BRANN_INTRO_7           = 6,
    SAY_BRANN_ELEMENTALS_1      = 7,
    SAY_BRANN_ELEMENTALS_2      = 8,
    SAY_BRANN_ELEMENTALS_3      = 9,
    SAY_BRANN_ELEMENTALS_4      = 10,
    SAY_BRANN_ANRAPHET_DEATH    = 11,
    SAY_BRANN_OUTRO             = 12,
    SAY_INTRO                   = 0,
    SAY_AGGRO                   = 1,
    SAY_SLAY                    = 2,
    SAY_ALPHA_BEAMS             = 3,
    SAY_OMEGA_STANCE            = 4,
    SAY_DEATH                   = 5,
};

enum Spells
{
    SPELL_ALPHA_BEAM_CHANNEL    = 91210,
    SPELL_ALPHA_BEAMS           = 76184,
    SPELL_OMEGA_STANCE          = 75622,
    SPELL_OMEGA_STANCE_SUMMON   = 77106, // z+30
    SPELL_OMEGA_STANCE_VISUAL   = 77121,
    SPELL_CRUMBLING_RUIN        = 75609,
    SPELL_NEMESIS_STRIKE        = 75604
};

enum Entities
{
    NPC_ALPHA_BEAMS             = 41144,
    NPC_OMEGA_STANCE            = 41194,
};

enum Events
{
    EVENT_ALPHA_BEAMS           = 1,
    EVENT_ALPHA_BEAMS_END,
    EVENT_OMEGA_STANCE,
    EVENT_OMEGA_STANCE_VISUAL,
    EVENT_CRUMBLING_RUIN,
    EVENT_NEMESIS_STRIKE,
};

enum Phases
{
    PHASE_NORMAL                = 1,
    PHASE_ALPHA_BEAMS,
    PHASE_OMEGA_STANCE
};

enum Misc
{
    PATH_INTRO                  = 3978801,
};

class boss_anraphet : public CreatureScript
{
    struct boss_anraphetAI : public BossAI
    {
        boss_anraphetAI(Creature * creature) : BossAI(creature, DATA_ANRAPHET) {}

        void Reset() override
        {
            intro = false;
            introTimer = 5000;
            omegaVisual = false;
            omegaTimer = 2000;
            events.SetPhase(PHASE_NORMAL);
            me->SetReactState(REACT_AGGRESSIVE);
            _Reset();
        }

        void EnterCombat(Unit* who) override
        {
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_NEMESIS_STRIKE, urand(5000, 8000), 1);
            events.ScheduleEvent(EVENT_ALPHA_BEAMS, 10000, 1);
            events.ScheduleEvent(EVENT_OMEGA_STANCE, 15000, 1);
            events.ScheduleEvent(EVENT_CRUMBLING_RUIN, 20000);
            BossAI::EnterCombat(who);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if(type == WAYPOINT_MOTION_TYPE)
            {
                if(id == 0)
                    Talk(SAY_INTRO);
            }
        }

        void SetData(uint32 data, uint32) override
        {
            if(data == DATA_ANRAPHET_INTRO)
                intro = true;
        }

        void JustSummoned(Creature* summon) override
        {
            if(summon->GetEntry() == NPC_ALPHA_BEAMS)
            {
                me->SetFacingToObject(summon);
                DoCast(summon, SPELL_ALPHA_BEAM_CHANNEL, true);
            }
            BossAI::JustSummoned(summon);
        }

        void JustDied(Unit* killer) override
        {
            instance->DoRemoveAurasDueToSpellOnPlayers(91206);
            Talk(SAY_DEATH);
            BossAI::JustDied(killer);
        }

        void UpdateAI(uint32 diff) override
        {
            if(intro)
            {
                if(introTimer <= diff)
                {
                    intro = false;
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MovePath(PATH_INTRO, false);
                }else introTimer -= diff;
            }

            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(omegaVisual)
            {
                if(omegaTimer <= diff)
                {
                    omegaVisual = false;
                    omegaTimer = 2000;
                    if(Creature * stalker = me->FindNearestCreature(NPC_OMEGA_STANCE, 100.0f))
                        stalker->CastSpell(stalker, SPELL_OMEGA_STANCE_VISUAL, true);
                }else omegaTimer -= diff;
            }

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_ALPHA_BEAMS:
                    Talk(SAY_ALPHA_BEAMS);
                    events.SetPhase(PHASE_ALPHA_BEAMS);
                    me->SetReactState(REACT_PASSIVE);
                    //me->AttackStop();
                    me->SetTarget(ObjectGuid::Empty);
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveIdle();
                    DoCast(SPELL_ALPHA_BEAMS);
                    events.DelayEvents(13000, 1);
                    events.ScheduleEvent(EVENT_ALPHA_BEAMS_END, 13000, 0, PHASE_ALPHA_BEAMS);
                    break;
                case EVENT_ALPHA_BEAMS_END:
                    events.SetPhase(PHASE_NORMAL);
                    me->SetReactState(REACT_AGGRESSIVE);
                    if(Unit * victim = me->GetVictim())
                    {
                        me->SetTarget(victim->GetGUID());
                        DoStartMovement(victim);
                    }
                    events.ScheduleEvent(EVENT_ALPHA_BEAMS, urand(15000, 25000), 1);
                    break;
                case EVENT_CRUMBLING_RUIN:
                    DoCast(me, SPELL_CRUMBLING_RUIN, true);
                    events.ScheduleEvent(EVENT_CRUMBLING_RUIN, 20000);
                    break;
                case EVENT_NEMESIS_STRIKE:
                    DoCastVictim(SPELL_NEMESIS_STRIKE, true);
                    events.ScheduleEvent(EVENT_NEMESIS_STRIKE, urand (12000, 15000), 1);
                    break;
                case EVENT_OMEGA_STANCE:
                    Talk(SAY_OMEGA_STANCE);
                    DoCast(SPELL_OMEGA_STANCE);
                    me->SummonCreature(NPC_OMEGA_STANCE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 30.0f, 0, TEMPSUMMON_TIMED_DESPAWN, 10000);
                    omegaVisual = true;
                    events.ScheduleEvent(EVENT_OMEGA_STANCE, urand(25000, 30000), 1);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
        bool omegaVisual;
        bool intro;
        uint32 introTimer;
        uint32 omegaTimer;
    };

public:
    boss_anraphet() : CreatureScript("boss_anraphet") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_anraphetAI(creature);
    }
};

class npc_air_warden_hoo : public CreatureScript
{
    enum
    {
        SPELL_WIND_SHEAR                = 77334,
        SPELL_WHIRLING_WINDS            = 77316,
    };

    struct npc_air_warden_hooAI : public ScriptedAI
    {
        npc_air_warden_hooAI(Creature * creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            windshearTimer = urand(5000, 8000);
            whirlingwindsTimer = urand(5000, 8000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if(instance)
                instance->SetData(DATA_AIR_WARDEN, DONE);
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            if(windshearTimer <= diff)
            {
                if(Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                    DoCast(target, SPELL_WIND_SHEAR, false);
                windshearTimer = urand(8000, 10000);
            }else windshearTimer -= diff;

            if(whirlingwindsTimer <= diff)
            {
                DoCast(SPELL_WHIRLING_WINDS);
                whirlingwindsTimer = 12000;
            }else whirlingwindsTimer -= diff;

            DoMeleeAttackIfReady();
        }
    private:
        uint32 windshearTimer;
        uint32 whirlingwindsTimer;
        InstanceScript * instance;
    };

public:
    npc_air_warden_hoo() : CreatureScript("npc_air_warden_hoo") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_air_warden_hooAI(creature);
    }
};

class npc_whirling_winds_hoo : public CreatureScript
{
    enum
    {
        SPELL_WHIRLING_WINDS_EFF                = 77333,
        SPELL_WHIRLING_WINDS_EFF_H              = 91153
    };

    struct npc_whirling_winds_hooAI : public ScriptedAI
    {
        npc_whirling_winds_hooAI(Creature * creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            currentTarget = ObjectGuid::Empty;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);

            ThreatContainer::StorageType const& m_threatList = summoner->getThreatManager().getThreatList();
            if (m_threatList.empty())
                return;

            for(ThreatContainer::StorageType::const_iterator itr = m_threatList.begin(); itr != m_threatList.end(); ++itr)
            {
                Unit * unit = ObjectAccessor::GetUnit(*me, (*itr)->getUnitGuid());
                if(unit && unit->IsAlive() && unit->GetTypeId() == TYPEID_PLAYER)
                    targetGUIDs.push_back((*itr)->getUnitGuid());
            }

            if(!targetGUIDs.empty())
            {
                Unit * target = ObjectAccessor::GetUnit(*me, targetGUIDs.front());
                if(target && target->IsAlive())
                {
                    currentTarget = targetGUIDs.front();
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
                }
            }
        }

        void SpellHit(Unit* target, const SpellInfo* spell) override
        {
            if(target->GetGUID() == currentTarget && (spell->Id == SPELL_WHIRLING_WINDS_EFF || spell->Id == SPELL_WHIRLING_WINDS_EFF_H))
            {
                targetGUIDs.pop_front();
                if(!targetGUIDs.empty())
                {
                    for(std::list<ObjectGuid>::const_iterator itr = targetGUIDs.begin(); itr != targetGUIDs.end(); ++itr)
                    {
                        Unit * target = ObjectAccessor::GetUnit(*me, (*itr));
                        if(target && target->IsAlive())
                        {
                            currentTarget = (*itr);
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
                            break;
                        }
                        else
                            targetGUIDs.pop_front();
                    }
                }
            }
        }



    private:
        ObjectGuid currentTarget;
        std::list<ObjectGuid> targetGUIDs;
        InstanceScript * instance;
    };

public:
    npc_whirling_winds_hoo() : CreatureScript("npc_whirling_winds_hoo") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_whirling_winds_hooAI(creature);
    }
};

class npc_earth_warden_hoo : public CreatureScript
{
    enum
    {
        SPELL_IMPALE                = 77235,
        SPELL_ROCKWAVE              = 77234
    };

    struct npc_earth_warden_hooAI : public ScriptedAI
    {
        npc_earth_warden_hooAI(Creature * creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            impaleTimer = urand(8000, 10000);
            rockwaveTimer = urand(5000, 8000);
            rockWave = false;
        }

        void JustDied(Unit* /*killer*/) override
        {
            if(instance)
                instance->SetData(DATA_EARTH_WARDEN, DONE);
        }

        void UpdateAI(uint32 diff) override
        {
            if(!rockWave && !UpdateVictim())
                return;

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(rockwaveTimer <= diff)
            {
                if(rockWave)
                {
                    rockWave = false;
                    me->SetReactState(REACT_AGGRESSIVE);
                    if(Unit * victim = me->GetVictim())
                    {
                        me->SetTarget(victim->GetGUID());
                        DoStartMovement(victim);
                    }
                    rockwaveTimer = urand(15000, 20000);
                }else
                {
                    rockWave = true;
                    if(Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                    {
                        me->SetReactState(REACT_PASSIVE);
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveIdle();
                        me->SetTarget(target->GetGUID());

                        me->SetFacingToObject(target);
                        DoCast(target, SPELL_ROCKWAVE, false);
                        rockwaveTimer = 1000;
                    }
                }
            }else rockwaveTimer -= diff;

            if(impaleTimer <= diff)
            {
                DoCastVictim(SPELL_IMPALE);
                impaleTimer = urand(12000, 16000);
            }else impaleTimer -= diff;

            DoMeleeAttackIfReady();
        }
    private:
        uint32 rockwaveTimer;
        uint32 impaleTimer;
        bool rockWave;
        InstanceScript * instance;
    };

public:
    npc_earth_warden_hoo() : CreatureScript("npc_earth_warden_hoo") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_earth_warden_hooAI(creature);
    }
};

class npc_flame_warden_hoo : public CreatureScript
{
    enum
    {
        SPELL_LAVA_ERUPTION             = 77273,
        SPELL_RAGING_INFERNO            = 77241
    };

    struct npc_flame_warden_hooAI : public ScriptedAI
    {
        npc_flame_warden_hooAI(Creature * creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            eruptionTimer = urand(5000, 7000);
            infernoTimer = urand(3000, 4000);
        }

        void JustDied(Unit* /*unit*/) override
        {
            if(instance)
                instance->SetData(DATA_FLAME_WARDEN, 1);
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(eruptionTimer <= diff)
            {
                Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 1, 50.0f, true);
                if(!target)
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true);
                if(target)
                    DoCast(target, SPELL_LAVA_ERUPTION, true);
                eruptionTimer = urand(8000, 10000);
            }else eruptionTimer -= diff;

            if(infernoTimer <= diff)
            {
                DoCast(SPELL_RAGING_INFERNO);
                infernoTimer = urand(15000, 25000);
            }else infernoTimer -= diff;

            DoMeleeAttackIfReady();
        }

    private:
        uint32 eruptionTimer;
        uint32 infernoTimer;
        InstanceScript * instance;
    };

public:
    npc_flame_warden_hoo() : CreatureScript("npc_flame_warden_hoo") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_flame_warden_hooAI(creature);
    }
};

class npc_water_warden_hoo : public CreatureScript
{
    enum
    {
        SPELL_BUBBLE_BOUND_HC           = 91158,
        SPELL_BUBBLE_BOUND              = 77336,
        SPELL_AQUA_BOMB_AURA            = 77349,
        SPELL_WATER_BUBBLE              = 77335,
        NPC_WATER_BUBBLE                = 41257
    };

    struct npc_water_warden_hooAI : public ScriptedAI
    {
        npc_water_warden_hooAI(Creature * creature) : ScriptedAI(creature), summons(me)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            targetGUID = ObjectGuid::Empty;
            bubbleTimer = 10000;
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BUBBLE_BOUND_HC);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BUBBLE_BOUND);
            summons.DespawnAll();
        }

        void JustDied(Unit* ) override
        {
            if(instance)
                instance->SetData(DATA_WATER_WARDEN, DONE);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BUBBLE_BOUND_HC);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BUBBLE_BOUND);
            summons.DespawnAll();
        }

        void JustSummoned(Creature* summoned) override
        {
            if(summoned->GetEntry() == NPC_WATER_BUBBLE)
            {
                summoned->AI()->SetGUID(targetGUID);
                targetGUID = ObjectGuid::Empty;
            }
            summons.Summon(summoned);
        }

        void SummonedCreatureDespawn(Creature* summoned) override
        {
            summons.Despawn(summoned);
        }

        void SummonedCreatureDies(Creature* summoned, Unit* ) override
        {
            summoned->DespawnOrUnsummon();
        }

        void SpellHitTarget(Unit* victim, const SpellInfo* spell) override
        {
            if(spell->Id == SPELL_WATER_BUBBLE)
                targetGUID = victim->GetGUID();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoCast(me, SPELL_AQUA_BOMB_AURA, true);
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            if(bubbleTimer <= diff)
            {
                DoCast(SPELL_WATER_BUBBLE);
                bubbleTimer = urand(12000, 15000);
            }else bubbleTimer -= diff;

            DoMeleeAttackIfReady();
        }

    private:
        uint32 bubbleTimer;
        InstanceScript * instance;
        ObjectGuid targetGUID;
        SummonList summons;
    };

public:
    npc_water_warden_hoo() : CreatureScript("npc_water_warden_hoo") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_water_warden_hooAI(creature);
    }
};

class npc_water_bubble_hoo : public CreatureScript
{
    enum
    {
        SPELL_BUBBLE_BOUND_HC       = 91158,
        SPELL_BUBBLE_BOUND          = 77336,
    };

    struct npc_water_bubble_hooAI : public ScriptedAI
    {
        npc_water_bubble_hooAI(Creature * creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            summonerGUID = ObjectGuid::Empty;
            checkTimer = 10000;
        }

        void SetGUID(ObjectGuid guid, int32 ) override
        {
            summonerGUID = guid;
        }

        void JustDied(Unit* ) override
        {
            if(Unit * summoner = ObjectAccessor::GetUnit(*me, summonerGUID))
            {
                summoner->RemoveAurasDueToSpell(SPELL_BUBBLE_BOUND);
                summoner->RemoveAurasDueToSpell(SPELL_BUBBLE_BOUND_HC);
            }

            me->DespawnOrUnsummon(20000);
        }

    private:
        ObjectGuid summonerGUID;
        uint32 checkTimer;
    };

public:
    npc_water_bubble_hoo() : CreatureScript("npc_water_bubble_hoo") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_water_bubble_hooAI(creature);
    }
};

static const Position pos = {-429.583f, 367.019f, 89.79282f, 0.0f};
#define GOSSIP_ITEM_EVENT   "We're ready! Go, Brann!"

class npc_brann_bronzebeard_hoo : public CreatureScript
{
    enum
    {
        EVENT_OPEN_DOOR         = 1,
        EVENT_TALK_2,
        EVENT_MOVE_PT,
        EVENT_TALK_3,
        EVENT_TALK_4,
        EVENT_TALK_5,
        EVENT_TALK_6,
        EVENT_TALK_7,

        BRANN_TEXTID            = 15794,
    };

    struct npc_brann_bronzebeard_hooAI : public ScriptedAI
    {
        npc_brann_bronzebeard_hooAI(Creature * creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            events.Reset();
            EventInProgress = false;
            elementals = 0;
        }

        void SetData(uint32 uiType, uint32 uiData) override
        {
            if(!EventInProgress && uiType == DATA_BRANN_EVENT)
            {
                me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                EventInProgress = true;
                Talk(SAY_BRANN_INTRO_1);
                events.ScheduleEvent(EVENT_OPEN_DOOR, 3000);
            }
            else if(uiType == DATA_BRANN_ELEMENTALS)
            {
                elementals = int8(uiData);
                if(EventInProgress)
                    Talk(SAY_BRANN_ELEMENTALS_1 + uiData - 1);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if(!EventInProgress)
                return;

            events.Update(diff);
            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_OPEN_DOOR:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_USE_STANDING);
                    events.ScheduleEvent(EVENT_TALK_2, 4000);
                    break;
                case EVENT_TALK_2:
                    Talk(SAY_BRANN_INTRO_2);
                    if(GameObject * go = me->FindNearestGameObject(GO_VAULT_OF_LIGHTS_ENTRANCE, 100.0f))
                        go->UseDoorOrButton();
                    events.ScheduleEvent(EVENT_MOVE_PT, 3000);
                    break;
                case EVENT_MOVE_PT:
                    me->GetMotionMaster()->MovePoint(0, pos);
                    events.ScheduleEvent(EVENT_TALK_3, 7000);
                    break;
                case EVENT_TALK_3:
                    Talk(SAY_BRANN_INTRO_3);
                    events.ScheduleEvent(EVENT_TALK_4, 15000);
                    break;
                case EVENT_TALK_4:
                    Talk(SAY_BRANN_INTRO_4);
                    events.ScheduleEvent(EVENT_TALK_5, 5000);
                    break;
                case EVENT_TALK_5:
                    Talk(SAY_BRANN_INTRO_5);
                    events.ScheduleEvent(EVENT_TALK_6, 6000);
                    break;
                case EVENT_TALK_6:
                    Talk(SAY_BRANN_INTRO_6);
                    events.ScheduleEvent(EVENT_TALK_7, 3000);
                    break;
                case EVENT_TALK_7:
                    Talk(SAY_BRANN_INTRO_7);
                    break;
                }
            }
        }
    private:
        bool EventInProgress;
        int8 elementals;
        EventMap events;
    };

public:
    npc_brann_bronzebeard_hoo() : CreatureScript("npc_brann_bronzebeard_hoo") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_brann_bronzebeard_hooAI(creature);
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_EVENT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        SendGossipMenuFor(player, BRANN_TEXTID, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
    {
        player->PlayerTalkClass->ClearMenus();
        creature->AI()->SetData(DATA_BRANN_EVENT, 1);
        return true;
    }
};

void AddSC_boss_anraphet()
{
    new boss_anraphet();
    new npc_air_warden_hoo();
    new npc_whirling_winds_hoo();
    new npc_earth_warden_hoo();
    new npc_flame_warden_hoo();
    new npc_water_warden_hoo();
    new npc_water_bubble_hoo();
    new npc_brann_bronzebeard_hoo();
}
