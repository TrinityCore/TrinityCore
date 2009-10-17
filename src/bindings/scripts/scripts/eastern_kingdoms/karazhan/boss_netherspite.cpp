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
SDName: Boss_Netherspite
SD%Complete: 90
SDComment: Not sure about timing and portals placing
SDCategory: Karazhan
EndScriptData */
#include "precompiled.h"
#include "def_karazhan.h"
#define EMOTE_PHASE_PORTAL          -1532089
#define EMOTE_PHASE_BANISH          -1532090
#define SPELL_NETHERBURN_AURA       30522
#define SPELL_VOIDZONE              37063
#define SPELL_NETHER_INFUSION       38688
#define SPELL_NETHERBREATH          38523
#define SPELL_BANISH_VISUAL         39833
#define SPELL_BANISH_ROOT           42716
#define SPELL_EMPOWERMENT           38549
#define SPELL_NETHERSPITE_ROAR      38684
const float PortalCoord[3][3] =
{
    {-11195.353516, -1613.237183, 278.237258}, // Left side
    {-11137.846680, -1685.607422, 278.239258}, // Right side
    {-11094.493164, -1591.969238, 279.949188}  // Back side
};
enum Netherspite_Portal{
    RED_PORTAL = 0, // Perseverence
    GREEN_PORTAL = 1, // Serenity
    BLUE_PORTAL = 2 // Dominance
};
const uint32 PortalID[3] = {17369, 17367, 17368};
const uint32 PortalVisual[3] = {30487,30490,30491};
const uint32 PortalBeam[3] = {30465,30464,30463};
const uint32 PlayerBuff[3] = {30421,30422,30423};
const uint32 NetherBuff[3] = {30466,30467,30468};
const uint32 PlayerDebuff[3] = {38637,38638,38639};
struct TRINITY_DLL_DECL boss_netherspiteAI : public ScriptedAI
{
    boss_netherspiteAI(Creature* c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        for (int i=0; i<3; ++i)
        {
            PortalGUID[i] = 0;
            BeamTarget[i] = 0;
            BeamerGUID[i] = 0;
        }
        // need core fix
        for (int i=0; i<3; ++i)
        {
            if(SpellEntry *spell = (SpellEntry*)GetSpellStore()->LookupEntry(PlayerBuff[i]))
                spell->AttributesEx |= SPELL_ATTR_EX_NEGATIVE;
        }
    }
    ScriptedInstance* pInstance;
    bool PortalPhase;
    bool Berserk;
    uint32 PhaseTimer; // timer for phase switching
    uint32 VoidZoneTimer;
    uint32 NetherInfusionTimer; // berserking timer
    uint32 NetherbreathTimer;
    uint32 EmpowermentTimer;
    uint32 PortalTimer; // timer for beam checking
    uint64 PortalGUID[3]; // guid's of portals
    uint64 BeamerGUID[3]; // guid's of auxiliary beaming portals
    uint64 BeamTarget[3]; // guid's of portals' current targets
    bool IsBetween(WorldObject* u1, WorldObject* target, WorldObject* u2) // the in-line checker
    {
        if(!u1 || !u2 || !target)
            return false;
        float xn, yn, xp, yp, xh, yh;
        xn = u1->GetPositionX();
        yn = u1->GetPositionY();
        xp = u2->GetPositionX();
        yp = u2->GetPositionY();
        xh = target->GetPositionX();
        yh = target->GetPositionY();
        // check if target is between (not checking distance from the beam yet)
        if(dist(xn,yn,xh,yh)>=dist(xn,yn,xp,yp) || dist(xp,yp,xh,yh)>=dist(xn,yn,xp,yp))
            return false;
        // check  distance from the beam
        return (abs((xn-xp)*yh+(yp-yn)*xh-xn*yp+xp*yn)/dist(xn,yn,xp,yp) < 1.5f);
    }
    float dist(float xa, float ya, float xb, float yb) // auxiliary method for distance
    {
        return sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
    }
    void Reset()
    {
        Berserk = false;
        NetherInfusionTimer = 540000;
        VoidZoneTimer = 15000;
        NetherbreathTimer = 3000;
        HandleDoors(true);
        DestroyPortals();
    }
    void SummonPortals()
    {
        uint8 r = rand()%4;
        uint8 pos[3];
        pos[RED_PORTAL] = (r%2 ? (r>1 ? 2: 1): 0);
        pos[GREEN_PORTAL] = (r%2 ? 0: (r>1 ? 2: 1));
        pos[BLUE_PORTAL] = (r>1 ? 1: 2); // Blue Portal not on the left side (0)
        for (int i=0; i<3; ++i)
            if(Creature *portal = m_creature->SummonCreature(PortalID[i],PortalCoord[pos[i]][0],PortalCoord[pos[i]][1],PortalCoord[pos[i]][2],0,TEMPSUMMON_TIMED_DESPAWN,60000))
            {
                PortalGUID[i] = portal->GetGUID();
                portal->AddAura(PortalVisual[i], portal);
            }
    }
    void DestroyPortals()
    {
        for (int i=0; i<3; ++i)
        {
            if(Creature *portal = Unit::GetCreature(*m_creature, PortalGUID[i]))
                portal->DisappearAndDie();
            if(Creature *portal = Unit::GetCreature(*m_creature, BeamerGUID[i]))
                portal->DisappearAndDie();
            PortalGUID[i] = 0;
            BeamTarget[i] = 0;
        }
    }
    void UpdatePortals() // Here we handle the beams' behavior
    {
        for (int j=0; j<3; ++j) // j = color
            if(Creature *portal = Unit::GetCreature(*m_creature, PortalGUID[j]))
            {
                // the one who's been casted upon before
                Unit *current = Unit::GetUnit(*portal, BeamTarget[j]);
                // temporary store for the best suitable beam reciever
                Unit *target = m_creature;
                if(Map* map = m_creature->GetMap())
                {
                    Map::PlayerList const& players = map->GetPlayers();
                    // get the best suitable target
                    for (Map::PlayerList::const_iterator i = players.begin(); i!=players.end(); ++i)
                    {
                        Player* p = i->getSource();
                        if(p && p->isAlive() // alive
                            && (!target || target->GetDistance2d(portal)>p->GetDistance2d(portal)) // closer than current best
                            && !p->HasAura(PlayerDebuff[j],0) // not exhausted
                            && !p->HasAura(PlayerBuff[(j+1)%3],0) // not on another beam
                            && !p->HasAura(PlayerBuff[(j+2)%3],0)
                            && IsBetween(m_creature, p, portal)) // on the beam
                            target = p;
                    }
                }
                // buff the target
                if(target->GetTypeId() == TYPEID_PLAYER)
                    target->AddAura(PlayerBuff[j], target);
                else
                    target->AddAura(NetherBuff[j], target);
                // cast visual beam on the chosen target if switched
                // simple target switching isn't working -> using BeamerGUID to cast (workaround)
                if(!current || target != current)
                {
                    BeamTarget[j] = target->GetGUID();
                    // remove currently beaming portal
                    if(Creature *beamer = Unit::GetCreature(*portal, BeamerGUID[j]))
                    {
                        beamer->CastSpell(target, PortalBeam[j], false);
                        beamer->DisappearAndDie();
                        BeamerGUID[j] = 0;
                    }
                    // create new one and start beaming on the target
                    if(Creature *beamer = portal->SummonCreature(PortalID[j],portal->GetPositionX(),portal->GetPositionY(),portal->GetPositionZ(),portal->GetOrientation(),TEMPSUMMON_TIMED_DESPAWN,60000))
                    {
                        beamer->CastSpell(target, PortalBeam[j], false);
                        BeamerGUID[j] = beamer->GetGUID();
                    }
                }
                // aggro target if Red Beam
                if(j==RED_PORTAL && m_creature->getVictim() != target && target->GetTypeId() == TYPEID_PLAYER)
                    m_creature->getThreatManager().addThreat(target, 100000.0f+DoGetThreat(m_creature->getVictim()));
            }
    }
    void SwitchToPortalPhase()
    {
        m_creature->RemoveAurasDueToSpell(SPELL_BANISH_ROOT);
        m_creature->RemoveAurasDueToSpell(SPELL_BANISH_VISUAL);
        SummonPortals();
        PhaseTimer = 60000;
        PortalPhase = true;
        PortalTimer = 10000;
        EmpowermentTimer = 10000;
        DoScriptText(EMOTE_PHASE_PORTAL,m_creature);
    }
    void SwitchToBanishPhase()
    {
        m_creature->RemoveAurasDueToSpell(SPELL_EMPOWERMENT);
        m_creature->RemoveAurasDueToSpell(SPELL_NETHERBURN_AURA);
        DoCast(m_creature,SPELL_BANISH_VISUAL,true);
        DoCast(m_creature,SPELL_BANISH_ROOT,true);
        DestroyPortals();
        PhaseTimer = 30000;
        PortalPhase = false;
        DoScriptText(EMOTE_PHASE_BANISH,m_creature);
        for (int i=0; i<3; ++i)
            m_creature->RemoveAurasDueToSpell(NetherBuff[i]);
    }
    void HandleDoors(bool open) // Massive Door switcher
    {
        if(GameObject *Door = GameObject::GetGameObject(*m_creature, pInstance ? pInstance->GetData64(DATA_GO_MASSIVE_DOOR) : 0))
            Door->SetGoState(open ? GO_STATE_ACTIVE : GO_STATE_READY);
    }
    void Aggro(Unit *who)
    {
        HandleDoors(false);
        SwitchToPortalPhase();
    }
    void JustDied(Unit* killer)
    {
        HandleDoors(true);
        DestroyPortals();
    }
    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;
        // Void Zone
        if(VoidZoneTimer < diff)
        {
            DoCast(SelectTarget(SELECT_TARGET_RANDOM,1,45,true),SPELL_VOIDZONE,true);
            VoidZoneTimer = 15000;
        }else VoidZoneTimer -= diff;
        // NetherInfusion Berserk
        if(!Berserk && NetherInfusionTimer < diff)
        {
            m_creature->AddAura(SPELL_NETHER_INFUSION, m_creature);
            DoCast(m_creature, SPELL_NETHERSPITE_ROAR);
            Berserk = true;
        }else NetherInfusionTimer -= diff;
        if(PortalPhase) // PORTAL PHASE
        {
            // Distribute beams and buffs
            if(PortalTimer < diff)
            {
                UpdatePortals();
                PortalTimer = 1000;
            }else PortalTimer -= diff;
            // Empowerment & Nether Burn
            if(EmpowermentTimer < diff)
            {
                DoCast(m_creature, SPELL_EMPOWERMENT);
                m_creature->AddAura(SPELL_NETHERBURN_AURA, m_creature);
                EmpowermentTimer = 90000;
            }else EmpowermentTimer -= diff;
            if(PhaseTimer < diff)
            {
                if(!m_creature->IsNonMeleeSpellCasted(false))
                {
                    SwitchToBanishPhase();
                    return;
                }
            }else PhaseTimer -= diff;
        }
        else // BANISH PHASE
        {
            // Netherbreath
            if(NetherbreathTimer < diff)
            {
                if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0,40,true))
                    DoCast(target,SPELL_NETHERBREATH);
                NetherbreathTimer = 5000+rand()%2000;
            }else NetherbreathTimer -= diff;
            if(PhaseTimer < diff)
            {
                if(!m_creature->IsNonMeleeSpellCasted(false))
                {
                    SwitchToPortalPhase();
                    return;
                }
            }else PhaseTimer -= diff;
        }
        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_netherspite(Creature *_Creature)
{
    return new boss_netherspiteAI(_Creature);
}
void AddSC_boss_netherspite()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_netherspite";
    newscript->GetAI = GetAI_boss_netherspite;
    newscript->RegisterSelf();
}
