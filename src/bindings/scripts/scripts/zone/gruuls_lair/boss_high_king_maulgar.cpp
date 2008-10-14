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
SDName: Boss_High_King_Maulgar
SD%Complete: 80
SDComment: Verify that the script is working properly
SDCategory: Gruul's Lair
EndScriptData */

#include "precompiled.h"
#include "def_gruuls_lair.h"

#define SOUND_AGGRO              11367                      //"Gronn are the real power in outland."

#define SOUND_ENRAGE             11368                      //"You will not defeat the hand of Gruul!"

#define SOUND_OGRE_DEATH1        11369                      //"You won't kill next one so easy!"
#define SOUND_OGRE_DEATH2        11370                      //"Pah! Does not prove anything!"
#define SOUND_OGRE_DEATH3        11371                      //"I'm not afraid of you."
#define SOUND_OGRE_DEATH4        11372                      //"Good, now you fight me!"

#define SOUND_SLAY1              11373                      //"You not so tough afterall!"
#define SOUND_SLAY2              11374                      //"Aha ha ha ha!"
#define SOUND_SLAY3              11375                      //"Mulgar is king!"

#define SOUND_DEATH              11376                      //"Gruul ...will crush you..."

// High King Maulgar
#define SPELL_ARCING_SMASH       39144
#define SPELL_MIGHTY_BLOW        33230
#define SPELL_WHIRLWIND          33238
#define SPELL_ENRAGE             34970

// Council spells
#define SPELL_DARK_DECAY        33129
#define SPELL_GREATER_POLYMORPH 33173
#define SPELL_LIGHTNING_BOLT    36152
#define SPELL_ARCANE_SHOCK      33175
#define SPELL_ARCANE_EXPLOSION  33237
#define SPELL_GREATER_PW_SHIELD 33147
#define SPELL_HEAL              33144
#define SPELL_GREATER_FIREBALL  33051
#define SPELL_SPELLSHIELD       33054
#define SPELL_BLAST_WAVE        33061

//High King Maulgar AI
struct MANGOS_DLL_DECL boss_high_king_maulgarAI : public ScriptedAI
{
    boss_high_king_maulgarAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        for(uint8 i = 0; i < 4; ++i)
            Council[i] = 0;
        Reset();
    }

    ScriptedInstance* pInstance;

    uint32 ArcingSmash_Timer;
    uint32 MightyBlow_Timer;
    uint32 Whirlwind_Timer;
    uint32 Charging_Timer;

    bool Phase2;

    uint64 Council[4];

    void Reset()
    {
        ArcingSmash_Timer = 10000;
        MightyBlow_Timer = 40000;
        Whirlwind_Timer = 30000;
        Charging_Timer = 0;
        Phase2 = false;

        Creature *pCreature = NULL;
        for(uint8 i = 0; i < 4; i++)
        {
            if(Council[i])
            {
                pCreature = (Creature*)(Unit::GetUnit((*m_creature), Council[i]));
                if(pCreature && !pCreature->isAlive())
                {
                    pCreature->Respawn();
                    pCreature->AI()->EnterEvadeMode();
                }
            }
        }

        //reset encounter
        if (pInstance)
            pInstance->SetData(DATA_MAULGAREVENT, 0);
    }

    void KilledUnit()
    {
        switch(rand()%2)
        {
            case 0:  DoPlaySoundToSet(m_creature, SOUND_SLAY1);  break;
            case 1:  DoPlaySoundToSet(m_creature, SOUND_SLAY2);  break;
            case 2:  DoPlaySoundToSet(m_creature, SOUND_SLAY3);  break;
        }
    }

    void JustDied(Unit* Killer)
    {
        DoPlaySoundToSet(m_creature, SOUND_DEATH);

        if (pInstance)
            pInstance->SetData(DATA_MAULGAREVENT, 0);
    }

    void Aggro(Unit *who) { StartEvent(who); }

    void GetCouncil()
    {
        //get council member's guid to respawn them if needed
        Council[0] = pInstance->GetData64(DATA_KIGGLERTHECRAZED);
        Council[1] = pInstance->GetData64(DATA_BLINDEYETHESEER);
        Council[2] = pInstance->GetData64(DATA_OLMTHESUMMONER);
        Council[3] = pInstance->GetData64(DATA_KROSHFIREHAND);
    }

    void StartEvent(Unit *who)
    {
        if(!pInstance)
            return;

        GetCouncil();

        DoPlaySoundToSet(m_creature, SOUND_AGGRO);

        pInstance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
        pInstance->SetData(DATA_MAULGAREVENT, 1);
    }

    void UpdateAI(const uint32 diff)
    {
        //Only if not incombat check if the event is started
        if(!InCombat && pInstance && pInstance->GetData(DATA_MAULGAREVENT))
        {
            Unit* target = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_MAULGAREVENT_TANK));

            if(target)
            {
                DoStartAttackAndMovement(target);

                GetCouncil();

                DoPlaySoundToSet(m_creature, SOUND_AGGRO);
            }
        }

        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //someone evaded!
        if(pInstance && !pInstance->GetData(DATA_MAULGAREVENT))
            EnterEvadeMode();

        //ArcingSmash_Timer
        if (ArcingSmash_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_ARCING_SMASH);
            ArcingSmash_Timer = 10000;
        }else ArcingSmash_Timer -= diff;

        //Whirlwind_Timer
        if (Whirlwind_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_WHIRLWIND);
            Whirlwind_Timer = 55000;
        }else Whirlwind_Timer -= diff;

        //MightyBlow_Timer
        if (MightyBlow_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_MIGHTY_BLOW);
            MightyBlow_Timer = 30000+rand()%10000;
        }else MightyBlow_Timer -= diff;

        //Entering Phase 2
        if(!Phase2 && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 50)
        {
            Phase2 = true;
            DoPlaySoundToSet(m_creature, SOUND_ENRAGE);
        }

        if(Phase2)
        {
            //Charging_Timer
            if(Charging_Timer < diff)
            {
                Unit* target = NULL;
                target = SelectUnit(SELECT_TARGET_RANDOM, 0);
                if(target)
                    DoStartAttackAndMovement(target);

                Charging_Timer = 20000;
            }else Charging_Timer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

//Olm The Summoner AI
struct MANGOS_DLL_DECL boss_olm_the_summonerAI : public ScriptedAI
{
    boss_olm_the_summonerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    uint32 DarkDecay_Timer;
    uint32 Summon_Timer;

    ScriptedInstance* pInstance;

    void Reset()
    {
        DarkDecay_Timer = 10000;
        Summon_Timer = 15000;

        //reset encounter
        if (pInstance)
            pInstance->SetData(DATA_MAULGAREVENT, 0);
    }

    void Aggro(Unit *who)
    {
        if(pInstance)
        {
            pInstance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
            pInstance->SetData(DATA_MAULGAREVENT, 1);
        }
    }

    float DoCalculateRandomLocation()
    {
        float Loc;
        float Rand = rand()%8;

        switch(rand()%2)
        {
            case 0: Loc = 0 + Rand; break;
            case 1: Loc = 0 - Rand; break;
        }
        return Loc;
    }

    void UpdateAI(const uint32 diff)
    {
        //Only if not incombat check if the event is started
        if(!InCombat && pInstance && pInstance->GetData(DATA_MAULGAREVENT))
        {
            Unit* target = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_MAULGAREVENT_TANK));

            if(target)
            {
                DoStartAttackAndMovement(target);
            }
        }

        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //someone evaded!
        if(pInstance && !pInstance->GetData(DATA_MAULGAREVENT))
            EnterEvadeMode();

        //DarkDecay_Timer
        if(DarkDecay_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_DARK_DECAY);
            DarkDecay_Timer = 20000;
        }else DarkDecay_Timer -= diff;

        //Summon_Timer
        if(Summon_Timer < diff)
        {
            Creature *Add = NULL;
            Add = DoSpawnCreature(18847, DoCalculateRandomLocation(), DoCalculateRandomLocation(), 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
            Summon_Timer = 30000;
        }else Summon_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

//Kiggler The Crazed AI
struct MANGOS_DLL_DECL boss_kiggler_the_crazedAI : public ScriptedAI
{
    boss_kiggler_the_crazedAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    uint32 GreatherPolymorph_Timer;
    uint32 LightningBolt_Timer;
    uint32 ArcaneShock_Timer;
    uint32 ArcaneExplosion_Timer;

    ScriptedInstance* pInstance;

    void Reset()
    {
        GreatherPolymorph_Timer = 5000;
        LightningBolt_Timer = 10000;
        ArcaneShock_Timer = 20000;
        ArcaneExplosion_Timer = 30000;

        //reset encounter
        if (pInstance)
            pInstance->SetData(DATA_MAULGAREVENT, 0);
    }

    void Aggro(Unit *who)
    {
        if(pInstance)
        {
            pInstance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
            pInstance->SetData(DATA_MAULGAREVENT, 1);
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!m_creature->getVictim() && who->isTargetableForAttack() && who->isInAccessablePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            if (!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;

            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who))
            {
                if(who->HasStealthAura())
                    who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

                if(!InCombat)
                {
                    DoStartAttackAndMovement(who);
                    if(pInstance)
                    {
                        pInstance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
                        pInstance->SetData(DATA_MAULGAREVENT, 1);
                    }
                }
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Only if not incombat check if the event is started
        if(!InCombat && pInstance && pInstance->GetData(DATA_MAULGAREVENT))
        {
            Unit* target = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_MAULGAREVENT_TANK));

            if(target)
            {
                DoStartAttackAndMovement(target);
            }
        }

        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //someone evaded!
        if(pInstance && !pInstance->GetData(DATA_MAULGAREVENT))
            EnterEvadeMode();

        //GreaterPolymorph_Timer / disabled: it makes you fall under the texture / if you've got vmaps feel free to uncomment this
        /*if(GreaterPolymorph_Timer < diff)
        {
            Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 0);
            if(target)
                DoCast(target, SPELL_GREATER_POLYMORPH);

            GreaterPolymorph_Timer = 20000;
        }else GreaterPolymorph_Timer -= diff;*/

        //LightningBolt_Timer
        if(LightningBolt_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_LIGHTNING_BOLT);
            LightningBolt_Timer = 15000;
        }else LightningBolt_Timer -= diff;

        //ArcaneShock_Timer
        if(ArcaneShock_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_ARCANE_SHOCK);
            ArcaneShock_Timer = 20000;
        }else ArcaneShock_Timer -= diff;

        //ArcaneExplosion_Timer
        if(ArcaneExplosion_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_ARCANE_EXPLOSION);
            ArcaneExplosion_Timer = 30000;
        }else ArcaneExplosion_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

//Blindeye The Seer AI
struct MANGOS_DLL_DECL boss_blindeye_the_seerAI : public ScriptedAI
{
    boss_blindeye_the_seerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    uint32 GreaterPowerWordShield_Timer;
    uint32 Heal_Timer;

    ScriptedInstance* pInstance;

    void Reset()
    {
        GreaterPowerWordShield_Timer = 5000;
        Heal_Timer = 30000;

        //reset encounter
        if (pInstance)
            pInstance->SetData(DATA_MAULGAREVENT, 0);
    }

    void Aggro(Unit *who)
    {
        if(pInstance)
        {
            pInstance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
            pInstance->SetData(DATA_MAULGAREVENT, 1);
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!m_creature->getVictim() && who->isTargetableForAttack() && who->isInAccessablePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            if (!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;

            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who))
            {
                if(who->HasStealthAura())
                    who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

                if(!InCombat)
                {
                    DoStartAttackAndMovement(who);
                    if(pInstance)
                    {
                        pInstance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
                        pInstance->SetData(DATA_MAULGAREVENT, 1);
                    }
                }
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Only if not incombat check if the event is started
        if(!InCombat && pInstance && pInstance->GetData(DATA_MAULGAREVENT))
        {
            Unit* target = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_MAULGAREVENT_TANK));

            if(target)
            {
                DoStartAttackAndMovement(target);
            }
        }

        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //someone evaded!
        if(pInstance && !pInstance->GetData(DATA_MAULGAREVENT))
            EnterEvadeMode();

        //GreaterPowerWordShield_Timer
        if(GreaterPowerWordShield_Timer < diff)
        {
            DoCast(m_creature, SPELL_GREATER_PW_SHIELD);
            GreaterPowerWordShield_Timer = 40000;
        }else GreaterPowerWordShield_Timer -= diff;

        //Heal_Timer
        if(Heal_Timer < diff)
        {
            DoCast(m_creature, SPELL_HEAL);
            Heal_Timer = 60000;
        }else Heal_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

//Krosh Firehand AI
struct MANGOS_DLL_DECL boss_krosh_firehandAI : public ScriptedAI
{
    boss_krosh_firehandAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    uint32 GreaterFireball_Timer;
    uint32 SpellShield_Timer;
    uint32 BlastWave_Timer;

    ScriptedInstance* pInstance;

    void Reset()
    {
        GreaterFireball_Timer = 1000;
        SpellShield_Timer = 5000;
        BlastWave_Timer = 20000;

        //reset encounter
        if (pInstance)
            pInstance->SetData(DATA_MAULGAREVENT, 0);
    }

    void Aggro(Unit *who)
    {
        if(pInstance)
        {
            pInstance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
            pInstance->SetData(DATA_MAULGAREVENT, 1);
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!m_creature->getVictim() && who->isTargetableForAttack() && who->isInAccessablePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            if (!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;

            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who))
            {
                if(who->HasStealthAura())
                    who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

                if(!InCombat)
                {
                    DoStartAttackAndMovement(who);
                    if(pInstance)
                    {
                        pInstance->SetData64(DATA_MAULGAREVENT_TANK, who->GetGUID());
                        pInstance->SetData(DATA_MAULGAREVENT, 1);
                    }
                }
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Only if not incombat check if the event is started
        if(!InCombat && pInstance && pInstance->GetData(DATA_MAULGAREVENT))
        {
            Unit* target = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_MAULGAREVENT_TANK));

            if(target)
            {
                DoStartAttackAndMovement(target);
            }
        }

        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //someone evaded!
        if(pInstance && !pInstance->GetData(DATA_MAULGAREVENT))
            EnterEvadeMode();

        //GreaterFireball_Timer
        if(GreaterFireball_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_GREATER_FIREBALL);
            GreaterFireball_Timer = 2000;
        }else GreaterFireball_Timer -= diff;

        //SpellShield_Timer
        if(SpellShield_Timer < diff)
        {
            m_creature->InterruptNonMeleeSpells(false);
            DoCast(m_creature->getVictim(), SPELL_SPELLSHIELD);
            SpellShield_Timer = 30000;
        }else SpellShield_Timer -= diff;

        //BlastWave_Timer
        if(BlastWave_Timer < diff)
        {
            m_creature->InterruptNonMeleeSpells(false);
            DoCast(m_creature->getVictim(), SPELL_BLAST_WAVE);
            BlastWave_Timer = 60000;
        }else BlastWave_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_high_king_maulgar(Creature *_Creature)
{
    return new boss_high_king_maulgarAI (_Creature);
}

CreatureAI* GetAI_boss_olm_the_summoner(Creature *_Creature)
{
    return new boss_olm_the_summonerAI (_Creature);
}

CreatureAI *GetAI_boss_kiggler_the_crazed(Creature *_Creature)
{
    return new boss_kiggler_the_crazedAI (_Creature);
}

CreatureAI *GetAI_boss_blindeye_the_seer(Creature *_Creature)
{
    return new boss_blindeye_the_seerAI (_Creature);
}

CreatureAI *GetAI_boss_krosh_firehand(Creature *_Creature)
{
    return new boss_krosh_firehandAI (_Creature);
}

void AddSC_boss_high_king_maulgar()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_high_king_maulgar";
    newscript->GetAI = GetAI_boss_high_king_maulgar;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="boss_kiggler_the_crazed";
    newscript->GetAI = GetAI_boss_kiggler_the_crazed;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="boss_blindeye_the_seer";
    newscript->GetAI = GetAI_boss_blindeye_the_seer;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="boss_olm_the_summoner";
    newscript->GetAI = GetAI_boss_olm_the_summoner;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="boss_krosh_firehand";
    newscript->GetAI = GetAI_boss_krosh_firehand;
    m_scripts[nrscripts++] = newscript;
}
