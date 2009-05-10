/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Boss_Sapphiron
SD%Complete: 0
SDComment: Place Holder
SDCategory: Naxxramas
EndScriptData */

#include "precompiled.h"
#include "def_naxxramas.h"

#define EMOTE_BREATH            -1533082
#define EMOTE_ENRAGE            -1533083

#define SPELL_FROST_AURA        HEROIC(28531,55799)
#define SPELL_CLEAVE            19983
#define SPELL_TAIL_SWEEP        HEROIC(55697,55696)
#define SPELL_SUMMON_BLIZZARD   28560
#define SPELL_LIFE_DRAIN        HEROIC(28542,55665)
#define SPELL_ICEBOLT           28522
#define SPELL_FROST_BREATH      29318
#define SPELL_FROST_EXPLOSION   28524
#define SPELL_FROST_MISSILE     30101
#define SPELL_BERSERK           26662
#define SPELL_DIES              29357

#define SPELL_CHILL             HEROIC(28547,55699)

#define MOB_BLIZZARD            16474
#define GO_ICEBLOCK             181247

enum Phases
{
    PHASE_NULL = 0,
    PHASE_BIRTH,
    PHASE_GROUND,
    PHASE_FLIGHT,
};

enum Events
{
    EVENT_BERSERK   = 1,
    EVENT_CLEAVE,
    EVENT_TAIL,
    EVENT_DRAIN,
    EVENT_BLIZZARD,
    EVENT_FLIGHT,
    EVENT_LIFTOFF,
    EVENT_ICEBOLT,
    EVENT_BREATH,
    EVENT_EXPLOSION,
    EVENT_LAND,
    EVENT_GROUND,
    EVENT_BIRTH,
};

typedef std::map<uint64, uint64> IceBlockMap;

struct TRINITY_DLL_DECL boss_sapphironAI : public ScriptedAI
{
    boss_sapphironAI(Creature* c) : ScriptedAI(c)
        , phase(PHASE_NULL)
    {
    }

    EventMap events;
    Phases phase;
    uint32 iceboltCount;
    IceBlockMap iceblocks;

    void InitializeAI()
    {
        float x, y, z;
        me->GetPosition(x, y, z);
        me->SummonGameObject(GO_BIRTH, x, y, z, 0, 0, 0, 0, 0, 0);
        me->SetVisibility(VISIBILITY_OFF);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->SetReactState(REACT_PASSIVE);

        Reset();
    }

    void Reset()
    {
        if(phase = PHASE_FLIGHT)
            ClearIceBlock();

        events.Reset();
        phase = PHASE_NULL;
    }

    void EnterCombat(Unit *who)
    {
        DoZoneInCombat();
        me->CastSpell(me, SPELL_FROST_AURA, true);

        events.ScheduleEvent(EVENT_BERSERK, 15*60000);
        EnterPhaseGround();
    }

    void SpellHitTarget(Unit *target, const SpellEntry *spell)
    {
        if(spell->Id == SPELL_ICEBOLT)
        {
            IceBlockMap::iterator itr = iceblocks.find(target->GetGUID());
            if(itr != iceblocks.end() && !itr->second)
            {
                if(GameObject *iceblock = me->SummonGameObject(GO_ICEBLOCK, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, 0, 0, 0, 0, 25000))
                    itr->second = iceblock->GetGUID();
            }
        }
    }

    void JustDied(Unit*)
    {
        me->CastSpell(me, SPELL_DIES, true);
    }

    void MovementInform(uint32, uint32 id)
    {
        if(id == 1)
            events.ScheduleEvent(EVENT_LIFTOFF, 0);
    }

    void DoAction(const int32 param)
    {
        if(param == DATA_SAPPHIRON_BIRTH)
        {
            phase = PHASE_BIRTH;
            events.ScheduleEvent(EVENT_BIRTH, 23000);
        }
    }

    void EnterPhaseGround()
    {
        phase = PHASE_GROUND;
        me->SetReactState(REACT_AGGRESSIVE);
        events.SetPhase(PHASE_GROUND);
        events.ScheduleEvent(EVENT_CLEAVE, 5000+rand()%10000, 0, PHASE_GROUND);
        events.ScheduleEvent(EVENT_TAIL, 5000+rand()%10000, 0, PHASE_GROUND);
        events.ScheduleEvent(EVENT_DRAIN, 24000, 0, PHASE_GROUND);
        events.ScheduleEvent(EVENT_BLIZZARD, 5000+rand()%5000, 0, PHASE_GROUND);
        events.ScheduleEvent(EVENT_FLIGHT, 45000);
    }

    void ClearIceBlock()
    {
        for(IceBlockMap::iterator itr = iceblocks.begin(); itr != iceblocks.end(); ++itr)
        {
            if(Player *player = Unit::GetPlayer(itr->first))
                player->RemoveAura(SPELL_ICEBOLT);
            if(GameObject *go = GameObject::GetGameObject(*me, itr->second))
                go->Delete();
        }
        iceblocks.clear();
    }

    void UpdateAI(const uint32 diff)
    {
        if(!phase)
            return;

        events.Update(diff);

        if(phase == PHASE_GROUND)
        {
            if(!UpdateVictim())
                return;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_BERSERK:
                        DoScriptText(EMOTE_ENRAGE, m_creature);
                        DoCast(me, SPELL_BERSERK);
                        return;
                    case EVENT_CLEAVE:
                        DoCast(me->getVictim(), SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, 5000+rand()%10000, 0, PHASE_GROUND);
                        return;
                    case EVENT_TAIL:
                        DoCastAOE(SPELL_TAIL_SWEEP);
                        events.ScheduleEvent(EVENT_TAIL, 5000+rand()%10000, 0, PHASE_GROUND);
                        return;
                    case EVENT_DRAIN:
                        DoCastAOE(SPELL_LIFE_DRAIN);
                        events.ScheduleEvent(EVENT_DRAIN, 24000, 0, PHASE_GROUND);
                        return;
                    case EVENT_BLIZZARD:
                    {
                        //DoCastAOE(SPELL_SUMMON_BLIZZARD);
                        float x, y, z;
                        me->GetGroundPointAroundUnit(x, y, z, rand_norm()*20, rand_norm()*2*M_PI);
                        if(Creature *summon = me->SummonCreature(MOB_BLIZZARD, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN, 25000+rand()%5000))
                            summon->GetMotionMaster()->MoveRandom(40);
                        events.ScheduleEvent(EVENT_BLIZZARD, HEROIC(20000,7000), 0, PHASE_GROUND);
                        break;
                    }
                    case EVENT_FLIGHT:
                        phase = PHASE_FLIGHT;
                        events.SetPhase(PHASE_FLIGHT);
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        float x, y, z, o;
                        me->GetHomePosition(x, y, z, o);
                        me->GetMotionMaster()->MovePoint(1, x, y, z);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
        else
        {
            /*if(me->getThreatManager().isThreatListEmpty())
            {
                EnterEvadeMode();
                return;
            }*/

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_LIFTOFF:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                        me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                        me->SendMovementFlagUpdate();
                        events.ScheduleEvent(EVENT_ICEBOLT, 1500);
                        iceboltCount = HEROIC(2,3);
                        return;
                    case EVENT_ICEBOLT:
                    {
                        std::vector<Unit*> targets;
                        std::list<HostilReference*>::iterator i = me->getThreatManager().getThreatList().begin();
                        for(; i != me->getThreatManager().getThreatList().end(); ++i)
                            if((*i)->getTarget()->GetTypeId() == TYPEID_PLAYER && !(*i)->getTarget()->HasAura(SPELL_ICEBOLT))
                                targets.push_back((*i)->getTarget());

                        if(targets.empty())
                            iceboltCount = 0;
                        else
                        {
                            std::vector<Unit*>::iterator itr = targets.begin();
                            advance(itr, rand()%targets.size());
                            iceblocks.insert(std::make_pair((*itr)->GetGUID(), 0));
                            DoCast(*itr, SPELL_ICEBOLT);
                            --iceboltCount;
                        }

                        if(iceboltCount)
                            events.ScheduleEvent(EVENT_ICEBOLT, 1000);
                        else
                            events.ScheduleEvent(EVENT_BREATH, 1000);
                        return;
                    }
                    case EVENT_BREATH:
                    {
                        DoScriptText(EMOTE_BREATH, me);
                        DoCastAOE(SPELL_FROST_MISSILE);
                        events.ScheduleEvent(EVENT_EXPLOSION, 8000);
                        return;
                    }
                    case EVENT_EXPLOSION:
                        CastExplosion();
                        ClearIceBlock();
                        events.ScheduleEvent(EVENT_LAND, 3000);
                        return;
                    case EVENT_LAND:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                        me->SendMovementFlagUpdate();
                        events.ScheduleEvent(EVENT_GROUND, 1500);
                        return;
                    case EVENT_GROUND:
                        EnterPhaseGround();
                        return;
                    case EVENT_BIRTH:
                        me->SetVisibility(VISIBILITY_ON);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        me->SetReactState(REACT_AGGRESSIVE);
                        return;
                }
            }//if(uint32 eventId = events.ExecuteEvent())
        }//if(phase == PHASE_GROUND)
    }

    void CastExplosion()
    {
        DoZoneInCombat(); // make sure everyone is in threatlist
        std::vector<Unit*> targets;
        std::list<HostilReference*>::iterator i = me->getThreatManager().getThreatList().begin();
        for(; i != me->getThreatManager().getThreatList().end(); ++i)
        {
            Unit *target = (*i)->getTarget();
            if(target->GetTypeId() != TYPEID_PLAYER)
                continue;

            if(target->HasAura(SPELL_ICEBOLT))
            {
                target->ApplySpellImmune(0, IMMUNITY_ID, SPELL_FROST_EXPLOSION, true);
                targets.push_back(target);
                continue;
            }

            for(IceBlockMap::iterator itr = iceblocks.begin(); itr != iceblocks.end(); ++itr)
            {
                if(GameObject *go = GameObject::GetGameObject(*me, itr->second))
                {
                    if(go->IsInBetween(me, target, 2.0f)
                        && me->GetExactDistance2d(target->GetPositionX(), target->GetPositionY()) - me->GetExactDistance2d(go->GetPositionX(), go->GetPositionY()) < 5.0f)
                    {
                        target->ApplySpellImmune(0, IMMUNITY_ID, SPELL_FROST_EXPLOSION, true);
                        targets.push_back(target);
                        break;
                    }
                }
            }
        }

        me->CastSpell(me, SPELL_FROST_EXPLOSION, true);

        for(std::vector<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
            (*itr)->ApplySpellImmune(0, IMMUNITY_ID, SPELL_FROST_EXPLOSION, false);
    }
};

CreatureAI* GetAI_boss_sapphiron(Creature *_Creature)
{
    return new boss_sapphironAI (_Creature);
}

void AddSC_boss_sapphiron()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_sapphiron";
    newscript->GetAI = &GetAI_boss_sapphiron;
    newscript->RegisterSelf();
}
