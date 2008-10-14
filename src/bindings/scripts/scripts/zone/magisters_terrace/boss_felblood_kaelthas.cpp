/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: boss_felblood_kaelthas
SD%Complete: 80
SDComment: Normal and Heroic Support. Issues: Arcane Spheres do not initially follow targets. TODO: Convert Phoenix to ACID.
SDCategory: Magisters' Terrace
EndScriptData */

#include "precompiled.h"
#include "def_magisters_terrace.h"
#include "WorldPacket.h"

/*** Spells ***/

// Phase 1 spells

#define SPELL_FIREBALL_NORMAL         44189                 // Deals 2700-3300 damage at current target
#define SPELL_FIREBALL_HEROIC         46164                 //       4950-6050

#define SPELL_PHOENIX                 44194                 // Summons a phoenix (Doesn't work?)
#define SPELL_PHOENIX_BURN            44198                 // A spell Phoenix uses to damage everything around

#define SPELL_FLAMESTRIKE1_NORMAL     44190                 // Damage part
#define SPELL_FLAMESTRIKE1_HEROIC     46163                 // Heroic damage part
#define SPELL_FLAMESTRIKE2            44191                 // Flamestrike indicator before the damage
#define SPELL_FLAMESTRIKE3            44192                 // Summons the trigger + animation (projectile)

#define SPELL_SHOCK_BARRIER           46165                 // Heroic only; 10k damage shield, followed by Pyroblast
#define SPELL_PYROBLAST               36819                 // Heroic only; 45-55k fire damage

// Phase 2 spells

#define SPELL_GRAVITY_LAPSE_INITIAL   44224                 // Cast at the beginning of every Gravity Lapse
#define SPELL_GRAVITY_LAPSE_CHANNEL   44251                 // Channeled; blue beam animation to every enemy in range
#define SPELL_TELEPORT_CENTER         44218                 // Should teleport people to the center. Requires DB entry in spell_target_position.
#define SPELL_GRAVITY_LAPSE_FLY       44227                 // Hastens flyspeed and allows flying for 1 minute. For some reason removes 44226.
#define SPELL_GRAVITY_LAPSE_DOT       44226                 // Knocks up in the air and applies a 300 DPS DoT.
#define SPELL_ARCANE_SPHERE_PASSIVE   44263                 // Passive auras on Arcane Spheres
#define SPELL_POWER_FEEDBACK          44233                 // Stuns him, making him take 50% more damage for 10 seconds. Cast after Gravity Lapse

/*** Creatures ***/
#define CREATURE_PHOENIX              24674
#define CREATURE_PHOENIX_EGG          24675
#define CREATURE_ARCANE_SPHERE        24708

/*** Dialogues ***/
#define SAY_AGGRO                     "Don't look so smug! I know what you're thinking, but Tempest Keep was merely a set back. Did you honestly believe I would trust the future to some blind, half-night elf mongrel? Oh no, he was merely an instrument, a stepping stone to a much larger plan! It has all led to this, and this time, you will not interfere!"
#define SOUND_AGGRO                   12413                 // This yell should be done when the room is cleared. For now, set it as aggro yell.

#define SAY_PHOENIX                   "Vengeance burns!"
#define SOUND_PHOENIX                 12415

#define SAY_FLAMESTRIKE               "Felomin ashal!"
#define SOUND_FLAMESTRIKE             12417

#define SAY_GRAVITY_LAPSE             "I'll turn your world... upside... down..."
#define SOUND_GRAVITY_LAPSE           12418

#define SAY_TIRED                     "Master... grant me strength."
#define SOUND_TIRED                   12419

#define SAY_RECAST_GRAVITY            "Do not... get too comfortable."
#define SOUND_RECAST_GRAVITY          12420

#define SAY_DEATH                     "My demise accomplishes nothing! The Master will have you! You will drown in your own blood! This world shall burn! Aaaghh!"
#define SOUND_DEATH                   12421

/** Locations **/
float KaelLocations[3][2]=
{
    {148.744659, 181.377426},
    {140.823883, 195.403046},
    {156.574188, 195.650482},
};
#define LOCATION_Z      -16.727455

struct MANGOS_DLL_DECL boss_felblood_kaelthasAI : public ScriptedAI
{
    boss_felblood_kaelthasAI(Creature* c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
        Heroic = c->GetMap()->IsHeroic() ? true : false;
    }

    ScriptedInstance* pInstance;

    uint32 FireballTimer;
    uint32 PhoenixTimer;
    uint32 FlameStrikeTimer;
    uint32 CombatPulseTimer;

    //Heroic only
    uint32 PyroblastTimer;

    uint32 GravityLapseTimer;
    uint32 GravityLapsePhase;
    // 0 = No Gravity Lapse
    // 1 = Casting Gravity Lapse visual
    // 2 = Teleported people to self
    // 3 = Knocked people up in the air
    // 4 = Applied an aura that allows them to fly, channeling visual, relased Arcane Orbs.

    bool FirstGravityLapse;
    bool Heroic;

    uint8 Phase;
    // 0 = Not started
    // 1 = Fireball; Summon Phoenix; Flamestrike
    // 2 = Gravity Lapses

    void Reset()
    {
        // TODO: Timers
        FireballTimer = 0;
        PhoenixTimer = 30000;
        FlameStrikeTimer = 25000;
        CombatPulseTimer = 0;

        PyroblastTimer = 60000;

        GravityLapseTimer = 0;
        GravityLapsePhase = 0;

        FirstGravityLapse = true;

        Phase = 0;

        if(pInstance)
            pInstance->SetData(DATA_KAELTHAS_EVENT, 0);
    }

    void JustDied(Unit *killer)
    {
        DoYell(SAY_DEATH,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature,SOUND_DEATH);
    }

    void DamageTaken(Unit* done_by, uint32 &damage)
    {
        if(damage > m_creature->GetHealth())
            RemoveGravityLapse();                           // Remove Gravity Lapse so that players fall to ground if they kill him when in air.
    }

    void Aggro(Unit *who)
    {
        DoYell(SAY_AGGRO,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature,SOUND_AGGRO);
    }

    void SetThreatList(Creature* SummonedUnit)
    {
        if(!SummonedUnit) return;

        std::list<HostilReference*>& m_threatlist = m_creature->getThreatManager().getThreatList();
        std::list<HostilReference*>::iterator i = m_threatlist.begin();
        for(i = m_threatlist.begin(); i != m_threatlist.end(); i++)
        {
            Unit* pUnit = Unit::GetUnit((*m_creature), (*i)->getUnitGuid());
            if(pUnit && pUnit->isAlive())
            {
                float threat = m_creature->getThreatManager().getThreat(pUnit);
                SummonedUnit->AddThreat(pUnit, threat);
            }
        }
    }

    void TeleportPlayersToSelf()
    {
        float x = KaelLocations[0][0];
        float y = KaelLocations[0][1];
        m_creature->Relocate(x, y, LOCATION_Z, 0);
        //m_creature->SendMonsterMove(x, y, LOCATION_Z, 0, 0, 0); // causes some issues...
        std::list<HostilReference*>::iterator i = m_creature->getThreatManager().getThreatList().begin();
        for (i = m_creature->getThreatManager().getThreatList().begin(); i!= m_creature->getThreatManager().getThreatList().end();++i)
        {
            Unit* pUnit = Unit::GetUnit((*m_creature), (*i)->getUnitGuid());
            if(pUnit && (pUnit->GetTypeId() == TYPEID_PLAYER))
                pUnit->CastSpell(pUnit, SPELL_TELEPORT_CENTER, true);
        }
        DoCast(m_creature, SPELL_TELEPORT_CENTER, true);
    }

    void CastGravityLapseKnockUp()
    {
        std::list<HostilReference*>::iterator i = m_creature->getThreatManager().getThreatList().begin();
        for (i = m_creature->getThreatManager().getThreatList().begin(); i!= m_creature->getThreatManager().getThreatList().end();++i)
        {
            Unit* pUnit = Unit::GetUnit((*m_creature), (*i)->getUnitGuid());
            if(pUnit && (pUnit->GetTypeId() == TYPEID_PLAYER))
                // Knockback into the air
                pUnit->CastSpell(pUnit, SPELL_GRAVITY_LAPSE_DOT, true, 0, 0, m_creature->GetGUID());
        }
    }

    void CastGravityLapseFly()                              // Use Fly Packet hack for now as players can't cast "fly" spells unless in map 530. Has to be done a while after they get knocked into the air...
    {
        std::list<HostilReference*>::iterator i = m_creature->getThreatManager().getThreatList().begin();
        for (i = m_creature->getThreatManager().getThreatList().begin(); i!= m_creature->getThreatManager().getThreatList().end();++i)
        {
            Unit* pUnit = Unit::GetUnit((*m_creature), (*i)->getUnitGuid());
            if(pUnit && (pUnit->GetTypeId() == TYPEID_PLAYER))
            {
                // Also needs an exception in spell system.
                pUnit->CastSpell(pUnit, SPELL_GRAVITY_LAPSE_FLY, true, 0, 0, m_creature->GetGUID());
                // Use packet hack
                WorldPacket data(12);
                data.SetOpcode(SMSG_MOVE_SET_CAN_FLY);
                data.append(pUnit->GetPackGUID());
                data << uint32(0);
                pUnit->SendMessageToSet(&data, true);
            }
        }
    }

    void RemoveGravityLapse()
    {
        std::list<HostilReference*>::iterator i = m_creature->getThreatManager().getThreatList().begin();
        for (i = m_creature->getThreatManager().getThreatList().begin(); i!= m_creature->getThreatManager().getThreatList().end();++i)
        {
            Unit* pUnit = Unit::GetUnit((*m_creature), (*i)->getUnitGuid());
            if(pUnit && (pUnit->GetTypeId() == TYPEID_PLAYER))
            {
                pUnit->RemoveAurasDueToSpell(SPELL_GRAVITY_LAPSE_FLY);
                pUnit->RemoveAurasDueToSpell(SPELL_GRAVITY_LAPSE_DOT);
                WorldPacket data(12);
                data.SetOpcode(SMSG_MOVE_UNSET_CAN_FLY);
                data.append(pUnit->GetPackGUID());
                data << uint32(0);
                pUnit->SendMessageToSet(&data, true);
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(!m_creature->getVictim() && !m_creature->SelectHostilTarget())
            return;

        switch(Phase)
        {
            case 0:
            {
                // *Heroic mode only:
                if(Heroic)
                    if(PyroblastTimer < diff)
                {
                    DoCast(m_creature, SPELL_SHOCK_BARRIER, true);
                    DoCast(m_creature->getVictim(), SPELL_PYROBLAST);
                    PyroblastTimer = 60000;
                }else PyroblastTimer -= diff;

                if(FireballTimer < diff)
                {
                    // *Normal/Heroic mode support
                    if(Heroic) DoCast(m_creature->getVictim(), SPELL_FIREBALL_HEROIC);
                    else       DoCast(m_creature->getVictim(), SPELL_FIREBALL_NORMAL);
                    FireballTimer = 2000 + rand()%4000;
                }else FireballTimer -= diff;

                if(PhoenixTimer < diff)
                {
                    uint32 random = rand()%2 + 1;
                    float x = KaelLocations[random][0];
                    float y = KaelLocations[random][1];
                    Creature* Phoenix = m_creature->SummonCreature(CREATURE_PHOENIX, x, y, LOCATION_Z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000);
                    if(Phoenix)
                    {
                        Phoenix->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);
                        SetThreatList(Phoenix);
                    }

                    DoYell(SAY_PHOENIX, LANG_UNIVERSAL, NULL);
                    DoPlaySoundToSet(m_creature,SOUND_PHOENIX);

                    PhoenixTimer = 40000;
                }else PhoenixTimer -= diff;

                if(FlameStrikeTimer < diff)
                {
                    Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0);
                    if(target)
                    {
                        DoCast(target, SPELL_FLAMESTRIKE3, true);
                        FlameStrikeTimer = 20000 + rand()%5000;

                        DoYell(SAY_FLAMESTRIKE, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(m_creature, SOUND_FLAMESTRIKE);
                    }
                }else FlameStrikeTimer -= diff;

                // Below 50%
                if(m_creature->GetMaxHealth() * 0.5 > m_creature->GetHealth())
                {
                    m_creature->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, true);
                    m_creature->StopMoving();
                    m_creature->GetMotionMaster()->Clear();
                    m_creature->GetMotionMaster()->MoveIdle();
                    GravityLapseTimer = 0;
                    GravityLapsePhase = 0;
                    Phase = 1;
                }
                DoMeleeAttackIfReady();
            }
            break;

            case 1:
            {
                if(GravityLapseTimer < diff)
                {
                    switch(GravityLapsePhase)
                    {
                        case 0:
                            if(FirstGravityLapse)           // Different yells at 50%, and at every following Gravity Lapse
                            {
                                DoYell(SAY_GRAVITY_LAPSE,LANG_UNIVERSAL,NULL);
                                DoPlaySoundToSet(m_creature,SOUND_GRAVITY_LAPSE);
                                FirstGravityLapse = false;
                                if(pInstance)
                                {
                                    GameObject* KaelLeft = GameObject::GetGameObject(*m_creature, pInstance->GetData64(DATA_KAEL_STATUE_LEFT));
                                    if(KaelLeft) KaelLeft->SetGoState(0);
                                    GameObject* KaelRight = GameObject::GetGameObject(*m_creature, pInstance->GetData64(DATA_KAEL_STATUE_RIGHT));
                                    if(KaelRight) KaelRight->SetGoState(0);
                                }
                            }else
                            {
                                DoYell(SAY_RECAST_GRAVITY,LANG_UNIVERSAL,NULL);
                                DoPlaySoundToSet(m_creature,SOUND_RECAST_GRAVITY);
                            }
                            DoCast(m_creature, SPELL_GRAVITY_LAPSE_INITIAL);
                            GravityLapseTimer = 2000 + diff;// Don't interrupt the visual spell
                            GravityLapsePhase = 1;
                            break;

                        case 1:
                            TeleportPlayersToSelf();
                            GravityLapseTimer = 1000;
                            GravityLapsePhase = 2;
                            break;

                        case 2:
                            CastGravityLapseKnockUp();
                            GravityLapseTimer = 1000;
                            GravityLapsePhase = 3;
                            break;

                        case 3:
                            CastGravityLapseFly();
                            GravityLapseTimer = 30000;
                            GravityLapsePhase = 4;
                            for(uint8 i = 0; i < 3; ++i)
                            {
                                Creature* Orb = DoSpawnCreature(CREATURE_ARCANE_SPHERE, 5, 5, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000);
                                if(Orb) SetThreatList(Orb);
                            }
                            DoCast(m_creature, SPELL_GRAVITY_LAPSE_CHANNEL);
                            break;

                        case 4:
                            m_creature->InterruptNonMeleeSpells(false);
                            DoYell(SAY_TIRED,LANG_UNIVERSAL,NULL);
                            DoPlaySoundToSet(m_creature,SOUND_TIRED);
                            DoCast(m_creature, SPELL_POWER_FEEDBACK);
                            RemoveGravityLapse();
                            GravityLapseTimer = 10000;
                            GravityLapsePhase = 0;
                            break;
                    }
                }else GravityLapseTimer -= diff;
            }
            break;
        }
    }
};

struct MANGOS_DLL_DECL mob_felkael_flamestrikeAI : public ScriptedAI
{
    mob_felkael_flamestrikeAI(Creature *c) : ScriptedAI(c)
    {
        Reset();
        Heroic = c->GetMap()->IsHeroic() ? true : false;
    }

    uint32 FlameStrikeTimer;
    bool Heroic;

    void Reset()
    {
        FlameStrikeTimer = 5000;

        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->setFaction(14);

        DoCast(m_creature, SPELL_FLAMESTRIKE2, true);
    }

    void Aggro(Unit *who) {}
    void MoveInLineOfSight(Unit *who) {}
    void UpdateAI(const uint32 diff)
    {
        if(FlameStrikeTimer < diff)
        {
            // *Normal/Heroic mode support
            if(Heroic) DoCast(m_creature, SPELL_FLAMESTRIKE1_HEROIC, true);
            else       DoCast(m_creature, SPELL_FLAMESTRIKE1_NORMAL, true);
            m_creature->DealDamage(m_creature, m_creature->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }else FlameStrikeTimer -= diff;
    }
};

struct MANGOS_DLL_DECL mob_felkael_phoenixAI : public ScriptedAI
{
    mob_felkael_phoenixAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 BurnTimer;

    void Reset()
    {
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);
        BurnTimer = 2000;
    }

    void Aggro(Unit* who) {}

    void JustDied(Unit* slayer)
    {
        DoSpawnCreature(CREATURE_PHOENIX_EGG, 0, 0, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 45000);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if (BurnTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_PHOENIX_BURN);
            BurnTimer = 2000;
        }else BurnTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct MANGOS_DLL_DECL mob_felkael_phoenix_eggAI : public ScriptedAI
{
    mob_felkael_phoenix_eggAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 HatchTimer;

    void Reset() {   HatchTimer = 15000;   }

    void Aggro(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}

    void UpdateAI(const uint32 diff)
    {
        if(HatchTimer < diff)
        {
            DoSpawnCreature(CREATURE_PHOENIX, 0, 0, 0, 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);
            m_creature->DealDamage(m_creature, m_creature->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }else HatchTimer -= diff;
    }
};

struct MANGOS_DLL_DECL mob_arcane_sphereAI : public ScriptedAI
{
    mob_arcane_sphereAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 DespawnTimer;
    uint32 ChangeTargetTimer;

    bool TargetLocked;

    void Reset()
    {
        DespawnTimer = 30000;
        ChangeTargetTimer = 5000;
        TargetLocked = false;

        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->setFaction(14);
        DoCast(m_creature, SPELL_ARCANE_SPHERE_PASSIVE, true);
    }

    void MoveInLineOfSight(Unit* who)
    {
        if(TargetLocked)
            return;
        if(who && who->IsHostileTo(m_creature) && (m_creature->IsWithinDistInMap(who, 25)))
            StalkTarget(who);
    }

    void Aggro(Unit* who) {}

    void StalkTarget(Unit* target)
    {
        if(!target)
            return;

        m_creature->GetMotionMaster()->MoveChase(target);
        TargetLocked = true;
    }

    void UpdateAI(const uint32 diff)
    {
        if(DespawnTimer < diff)
            m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        else DespawnTimer -= diff;

        if(!m_creature->getVictim() || !m_creature->SelectHostilTarget())
            return;

        if(ChangeTargetTimer < diff)
        {
            TargetLocked = false;
            ChangeTargetTimer = 10000;
        }else ChangeTargetTimer -= diff;
    }
};

CreatureAI* GetAI_boss_felblood_kaelthas(Creature* c)
{
    return new boss_felblood_kaelthasAI(c);
}

CreatureAI* GetAI_mob_arcane_sphere(Creature* c)
{
    return new mob_arcane_sphereAI(c);
}

CreatureAI* GetAI_mob_felkael_phoenix(Creature* c)
{
    return new mob_felkael_phoenixAI(c);
}

CreatureAI* GetAI_mob_felkael_phoenix_egg(Creature* c)
{
    return new mob_felkael_phoenix_eggAI(c);
}

CreatureAI* GetAI_mob_felkael_flamestrike(Creature* c)
{
    return new mob_felkael_flamestrikeAI(c);
}

void AddSC_boss_felblood_kaelthas()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_felblood_kaelthas";
    newscript->GetAI = GetAI_boss_felblood_kaelthas;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name = "mob_arcane_sphere";
    newscript->GetAI = GetAI_mob_arcane_sphere;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_felkael_phoenix";
    newscript->GetAI = GetAI_mob_felkael_phoenix;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_felkael_phoenix_egg";
    newscript->GetAI = GetAI_mob_felkael_phoenix_egg;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_felkael_flamestrike";
    newscript->GetAI = GetAI_mob_felkael_flamestrike;
    m_scripts[nrscripts++] = newscript;
}
