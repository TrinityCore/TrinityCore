/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
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

#include "precompiled.h"

#define GCD_CAST    1

/*######
##Quest 12848
######*/

#define SAY_EVENT_START                 "I will dismantle this festering hellhole!"
#define SAY_EVENT_ATTACK                "It ends here!"

#define SPELL_SOUL_PRISON_CHAIN_SELF    54612
#define SPELL_SOUL_PRISON_CHAIN         54613

#define SPELL_ICY_TOUCH                 52372
#define SPELL_PLAGUE_STRIKE             52373
#define SPELL_BLOOD_STRIKE              52374
#define SPELL_DEATH_COIL                52375

#define EVENT_ICY_TOUCH                 1
#define EVENT_PLAGUE_STRIKE             2
#define EVENT_BLOOD_STRIKE              3
#define EVENT_DEATH_COIL                4

uint32 acherus_soul_prison[12] =
{
    191577,
    191580,
    191581,
    191582,
    191583,
    191584,
    191585,
    191586,
    191587,
    191588,
    191589,
    191590
};

uint32 acherus_unworthy_initiate[5] =
{
    29519,
    29520,
    29565,
    29566,
    29567
};

enum initiate_phase
{
    Chained,
    ToEquipping,
    Equipping,
    ToAttacking,
    Attacking
};

float modelid_dk_armor[20] =
{
    25432, // bloodelf female
    25422, // bloodelf male
    25412, // draenei female
    25420, // draenei male
    25406, // dwarf female
    25414, // dwarf male
    25438, // forsaken female
    25426, // forsaken male
    25408, // gnome female
    25426, // gnome male
    25404, // human female
    25375, // human male
    25410, // nightelf female
    25418, // nightelf male
    25436, // orc female
    25424, // orc male
    25440, // tauren female
    25430, // tauren male
    25434, // troll female
    25428  // troll male
};

float modelid_dk_unworthy[20] =
{
    25369, // bloodelf female
    25373, // bloodelf male
    25363, // draenei female
    25357, // draenei male
    25361, // dwarf female
    25356, // dwarf male
    25372, // forsaken female
    25367, // forsaken male
    25362, // gnome female
    25359, // gnome male
    25355, // human female
    25354, // human male
    25360, // nightelf female
    25358, // nightelf male
    25368, // orc female
    25364, // orc male
    25371, // tauren female
    25366, // tauren male
    25370, // troll female
    25365  // troll male
};

struct TRINITY_DLL_DECL npc_unworthy_initiateAI : public ScriptedAI
{
    npc_unworthy_initiateAI(Creature *c) : ScriptedAI(c) {Reset();}

    bool event_startet;
    uint64 event_starter;
    initiate_phase phase;
    uint32 wait_timer;
    float targ_x,targ_y,targ_z;

    EventMap events;

    void Reset()
    {
        phase = Chained;
        events.Reset();
        m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, 8);
        m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID  , 0);
        event_startet = false;
    }

    void EnterCombat(Unit *who)
    {
        events.ScheduleEvent(EVENT_ICY_TOUCH, 1000, GCD_CAST);
        events.ScheduleEvent(EVENT_PLAGUE_STRIKE, 3000, GCD_CAST);
        events.ScheduleEvent(EVENT_BLOOD_STRIKE, 2000, GCD_CAST);
        events.ScheduleEvent(EVENT_DEATH_COIL, 5000, GCD_CAST);
    }

    void JustDied(Unit *killer)
    {
        if(m_creature->GetEntry() !=  29519)
            if(killer->GetTypeId() == TYPEID_PLAYER)
                ((Player*)killer)->KilledMonster(29519,m_creature->GetGUID());
    }

    void AddEquipp()
    {
        int model_counter = 0;
        for(int i = 0; i< 20; i++)
        {
            if(m_creature->GetDisplayId() == modelid_dk_unworthy[i])
            {
                model_counter = i;
                break;
            }
        }

        m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID, modelid_dk_armor[model_counter]);
        m_creature->LoadEquipment(m_creature->GetEquipmentId());
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if(type != POINT_MOTION_TYPE)
            return;

        if(id == 1)
        {
            wait_timer = 5000;
            AddEquipp();

            DoSay(SAY_EVENT_ATTACK,LANG_UNIVERSAL,NULL);
            m_creature->HandleEmoteCommand(EMOTE_ONESHOT_TALK);

            phase = ToAttacking;
        }
    }

    void EventStart(Creature* anchor, Player* target)
    {
        wait_timer = 5000;
        phase = ToEquipping;

        m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);

        anchor->GetPosition(targ_x,targ_y,targ_z);
        anchor->DealDamage(anchor,anchor->GetHealth());
        m_creature->RemoveAurasDueToSpell(SPELL_SOUL_PRISON_CHAIN_SELF);
        m_creature->RemoveAurasDueToSpell(SPELL_SOUL_PRISON_CHAIN);

        DoSay(SAY_EVENT_START,LANG_UNIVERSAL,NULL);
        m_creature->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
        event_starter = target->GetGUID();
    }

    void UpdateAI(const uint32 diff);
};

CreatureAI* GetAI_npc_unworthy_initiate(Creature *_Creature)
{
    return new npc_unworthy_initiateAI(_Creature);
}

struct TRINITY_DLL_DECL npc_unworthy_initiate_anchorAI : public ScriptedAI
{
    npc_unworthy_initiate_anchorAI(Creature *c) : ScriptedAI(c) { guid_target = 0; }

    uint64 guid_target;

    void Aggro(Unit *who) {}
    void Reset(){}

    void SetTarget(uint64 target);
    uint64 GetTarget()
    {
        return guid_target;
    }

    void UpdateAI(const uint32 diff){}
};

void npc_unworthy_initiate_anchorAI::SetTarget(uint64 target)
{
    if(guid_target == 0)
        guid_target = target;
}

void npc_unworthy_initiateAI::UpdateAI(const uint32 diff)
{
    switch(phase)
    {
    case Chained:
        if(!m_creature->HasAura(SPELL_SOUL_PRISON_CHAIN))
        {
            float x, y, z;
            float dist = 99;

            for(int i = 0; i < 12; i++)
            {
                GameObject* temp_prison;
                temp_prison = FindGameObject(acherus_soul_prison[i],30,m_creature);
                if(!temp_prison) return;
                if(dist == 99 || dist > m_creature->GetDistance2d(temp_prison))
                {
                    temp_prison->GetPosition(x, y, z);
                    dist = m_creature->GetDistance2d(temp_prison);
                }
            }

            Creature* trigger = m_creature->SummonCreature(29521,x,y,z,0,TEMPSUMMON_MANUAL_DESPAWN,1000);
            if(trigger)
            {
                ((npc_unworthy_initiate_anchorAI*)trigger->AI())->SetTarget(m_creature->GetGUID());
                trigger->CastSpell(m_creature,SPELL_SOUL_PRISON_CHAIN,true);
            }

        }
        return;
    case ToEquipping:
        if(wait_timer)
        {
            if(wait_timer < diff)
            {
                m_creature->GetMotionMaster()->MovePoint(1,targ_x,targ_y,m_creature->GetPositionZ());
                phase = Equipping;
                wait_timer = 0;
            }else wait_timer -= diff;
        }
        return;
    case ToAttacking:
        if(wait_timer)
        {
            if(wait_timer < diff)
            {
                m_creature->setFaction(14);
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
                phase = Attacking;

                if(Unit* target = Unit::GetUnit((*m_creature),event_starter))
                    m_creature->AI()->AttackStart(target);
                wait_timer = 0;
            }else wait_timer -= diff;
        }
        return;
    case Attacking:
            if(!UpdateVictim())
                return;

            events.Update(diff);

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_ICY_TOUCH:
                        DoCast(m_creature->getVictim(), SPELL_ICY_TOUCH);
                        events.DelayEvents(1000, GCD_CAST);
                        events.ScheduleEvent(EVENT_ICY_TOUCH, 5000, GCD_CAST);
                        break;
                    case EVENT_PLAGUE_STRIKE:
                        DoCast(m_creature->getVictim(), SPELL_PLAGUE_STRIKE);
                        events.DelayEvents(1000, GCD_CAST);
                        events.ScheduleEvent(SPELL_PLAGUE_STRIKE, 5000, GCD_CAST);
                        break;
                    case EVENT_BLOOD_STRIKE:
                        DoCast(m_creature->getVictim(), SPELL_BLOOD_STRIKE);
                        events.DelayEvents(1000, GCD_CAST);
                        events.ScheduleEvent(EVENT_BLOOD_STRIKE, 5000, GCD_CAST);
                        break;
                    case EVENT_DEATH_COIL:
                        DoCast(m_creature->getVictim(), SPELL_DEATH_COIL);
                        events.DelayEvents(1000, GCD_CAST);
                        events.ScheduleEvent(EVENT_DEATH_COIL, 5000, GCD_CAST);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        return;
    }
}

CreatureAI* GetAI_npc_unworthy_initiate_anchor(Creature *_Creature)
{
    return new npc_unworthy_initiate_anchorAI(_Creature);
}

bool GOHello_go_acherus_soul_prison(Player *player, GameObject* _GO)
{
    Creature* finder = player->SummonCreature(WORLD_TRIGGER,_GO->GetPositionX(),_GO->GetPositionY(),_GO->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN,2000);
    if(!finder) return false;

    Unit* prison_anchor = FindCreature(29521,5,finder);
    if(!prison_anchor) return false;

    uint64 owner = ((npc_unworthy_initiate_anchorAI*)((Creature*)prison_anchor)->AI())->GetTarget();

    Creature* prisoner = Creature::GetCreature((*player),owner);

    if(prisoner && prison_anchor)
    {
        ((npc_unworthy_initiateAI*)(prisoner->AI()))->EventStart((Creature*)prison_anchor,player);
    }

    return false;
}

/*######
## npc_death_knight_initiate
######*/

#define GOSSIP_DKI      "Duel with me!"

#define SAY_DKI_DUEL1   "Remember this day, $N, for it is the day that you will be thoroughly owned."
#define SAY_DKI_DUEL2   "I'm going to tear your heart out, cupcake!"
#define SAY_DKI_DUEL3   "You have challenged death itself!"
#define SAY_DKI_DUEL4   "Don't make me laugh."
#define SAY_DKI_DUEL5   "Here come the tears..."
#define SAY_DKI_DUEL6   "No potions!"

struct TRINITY_DLL_DECL npc_death_knight_initiateAI : public ScriptedAI
{
    npc_death_knight_initiateAI(Creature *c) : ScriptedAI(c) {Reset();}

    void Reset()
    {
        m_creature->setFaction(2084);
    }

    void EnterCombat(Unit *who) {
        if(who->GetTypeId() == TYPEID_PLAYER) {
            switch(rand()%6)
            {
                case 0: DoSay(SAY_DKI_DUEL1, LANG_UNIVERSAL, who); break;
                case 1: DoSay(SAY_DKI_DUEL2, LANG_UNIVERSAL, who); break;
                case 2: DoSay(SAY_DKI_DUEL3, LANG_UNIVERSAL, who); break;
                case 3: DoSay(SAY_DKI_DUEL4, LANG_UNIVERSAL, who); break;
                case 4: DoSay(SAY_DKI_DUEL5, LANG_UNIVERSAL, who); break;
                case 5: DoSay(SAY_DKI_DUEL6, LANG_UNIVERSAL, who); break;
            }
        }
    }

    void Aggro(Unit *who) { }

    void JustDied(Unit *killer) { }

    void UpdateAI(const uint32 diff)
    {
        if ( !UpdateVictim() )
            return;

        Unit *victim = m_creature->getVictim();

        if(victim->GetTypeId() == TYPEID_PLAYER) {
            if ( (victim->GetHealth()*100)/victim->GetMaxHealth() <= 10 ) {
                m_creature->setFaction(2084);
                victim->AttackStop();
                m_creature->CombatStop();
                m_creature->RemoveAllAuras();
                EnterEvadeMode();
            }
        }

        DoMeleeAttackIfReady();
    }

    void DamageTaken(Unit *done_by, uint32 & damage)
    {
        if(done_by->GetTypeId() == TYPEID_PLAYER && damage > m_creature->GetHealth())
        {
            //Take 0 damage
            damage = 0;
            ((Player*)done_by)->AttackStop();
            ((Player*)done_by)->KilledMonster(29025,m_creature->GetGUID());
            m_creature->setFaction(2084);
            m_creature->RemoveAllAuras();
            m_creature->CombatStop();
            EnterEvadeMode();
        }
    }
};

CreatureAI* GetAI_npc_death_knight_initiate(Creature *_Creature)
{
    return new npc_death_knight_initiateAI(_Creature);
}

bool GossipHello_npc_death_knight_initiate(Player *player, Creature *_Creature)
{
    if( player->GetQuestStatus(12733) == QUEST_STATUS_INCOMPLETE )
        player->ADD_GOSSIP_ITEM(0, GOSSIP_DKI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(),_Creature->GetGUID());
    return true;
}

bool GossipSelect_npc_death_knight_initiate(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if( action == GOSSIP_ACTION_INFO_DEF )
    {
        player->CastSpell(player, 52991, true);
        _Creature->setFaction(14);
        ((npc_death_knight_initiateAI*)_Creature->AI())->AttackStart(player);
    }
    return true;
}

/*######
## npc_salanar_the_horseman
######*/

struct TRINITY_DLL_DECL npc_salanar_the_horsemanAI : public ScriptedAI
{
    npc_salanar_the_horsemanAI(Creature *c) : ScriptedAI(c) {Reset();}

    void Reset() { }

    void MoveInLineOfSight(Unit *who)
    {
        if( (who->GetTypeId() == TYPEID_UNIT) && ((Creature*)who)->isVehicle() && m_creature->IsWithinDistInMap(who, 25.0f) )
        {
            if( Unit *charmer = who->GetCharmer() )
            {
                if( charmer->GetTypeId() == TYPEID_PLAYER && ((Player*)charmer)->GetQuestStatus(12680) == QUEST_STATUS_INCOMPLETE )
                {
                    ((Player*)charmer)->KilledMonster(28767,m_creature->GetGUID());
                    ((Player*)charmer)->ExitVehicle();
                    // TODO: dismiss Vehicle; Now we cant do it from script.
                }
            }
        }
    }
};

CreatureAI* GetAI_npc_salanar_the_horseman(Creature *_Creature)
{
    return new npc_salanar_the_horsemanAI(_Creature);
}

void AddSC_the_scarlet_enclave()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_unworthy_initiate";
    newscript->GetAI = &GetAI_npc_unworthy_initiate;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_unworthy_initiate_anchor";
    newscript->GetAI = &GetAI_npc_unworthy_initiate_anchor;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_acherus_soul_prison";
    newscript->pGOHello = &GOHello_go_acherus_soul_prison;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_death_knight_initiate";
    newscript->pGossipHello = &GossipHello_npc_death_knight_initiate;
    newscript->pGossipSelect = &GossipSelect_npc_death_knight_initiate;
    newscript->GetAI = &GetAI_npc_death_knight_initiate;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_salanar_the_horseman";
    newscript->GetAI = &GetAI_npc_salanar_the_horseman;
    newscript->RegisterSelf();
}