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
SDName: Boss_Leotheras_The_Blind
SD%Complete: 80
SDComment: Possesion Support
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "precompiled.h"
#include "def_serpent_shrine.h"

// --- Spells used by Leotheras The Blind
#define SPELL_WHIRLWIND         37640
#define SPELL_CHAOS_BLAST       37674
#define SPELL_BERSERK           26662
#define SPELL_INSIDIOUS_WHISPER 37676
#define SPELL_DUAL_WIELD        42459

// --- Spells used in banish phase ---
#define BANISH_BEAM             38909
#define AURA_BANISH             37833

// --- Spells used by Greyheart Spellbinders
#define SPELL_EARTHSHOCK        39076
#define SPELL_MINDBLAST         37531

// --- Spells used by Inner Demons and creature ID
#define INNER_DEMON_ID          21857
#define AURA_DEMONIC_ALIGNMENT  37713
#define SPELL_SHADOWBOLT        39309
#define SPELL_SOUL_LINK         38007
#define SPELL_CONSUMING_MADNESS 37749 //not supported by core yet

//Misc.
#define MODEL_DEMON             20125
#define MODEL_NIGHTELF          20514
#define DEMON_FORM              21875
#define MOB_SPELLBINDER         21806

#define SAY_AGGRO               -1548009
#define SAY_SWITCH_TO_DEMON     -1548010
#define SAY_INNER_DEMONS        -1548011
#define SAY_DEMON_SLAY1         -1548012
#define SAY_DEMON_SLAY2         -1548013
#define SAY_DEMON_SLAY3         -1548014
#define SAY_NIGHTELF_SLAY1      -1548015
#define SAY_NIGHTELF_SLAY2      -1548016
#define SAY_NIGHTELF_SLAY3      -1548017
#define SAY_FINAL_FORM          -1548018
#define SAY_FREE                -1548019
#define SAY_DEATH               -1548020

struct TRINITY_DLL_DECL mob_inner_demonAI : public ScriptedAI
{
    mob_inner_demonAI(Creature *c) : ScriptedAI(c)
    {
        victimGUID = 0;
    }

    uint32 ShadowBolt_Timer;

    uint32 Link_Timer;
    uint64 victimGUID;

    void Reset()
    {
        ShadowBolt_Timer = 10000;
        Link_Timer = 1000;
    }
    void JustDied(Unit *victim)
    {
        Unit* pUnit = Unit::GetUnit((*m_creature),victimGUID);
        if (pUnit && pUnit->HasAura(SPELL_INSIDIOUS_WHISPER))
            pUnit->RemoveAurasDueToSpell(SPELL_INSIDIOUS_WHISPER);
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if(done_by->GetGUID() != victimGUID && done_by->GetGUID() != m_creature->GetGUID())
        {
            damage = 0;
            DoModifyThreatPercent(done_by, -100);
        }
    }

    void EnterCombat(Unit *who)
    {
        if (!victimGUID) return;
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (m_creature->getVictim()->GetGUID() != victimGUID)
        {
            Unit* owner = Unit::GetUnit((*m_creature),victimGUID);
                if (owner)
                    AttackStart(owner);
        }
        if(Link_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SOUL_LINK, true);
            Link_Timer = 1000;
        }else Link_Timer -= diff;


        if(!m_creature->HasAura(AURA_DEMONIC_ALIGNMENT))
            DoCast(m_creature, AURA_DEMONIC_ALIGNMENT,true);

        if(ShadowBolt_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SHADOWBOLT, false);
            ShadowBolt_Timer = 10000;
        }else ShadowBolt_Timer -= diff;

       DoMeleeAttackIfReady();
    }
};
//Original Leotheras the Blind AI
struct TRINITY_DLL_DECL boss_leotheras_the_blindAI : public ScriptedAI
{
    boss_leotheras_the_blindAI(Creature *c) : ScriptedAI(c)
    {
        m_creature->GetPosition(x,y,z);
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Demon = 0;

        for(uint8 i = 0; i < 3; i++)//clear guids
            SpellBinderGUID[i] = 0;
    }

    ScriptedInstance *pInstance;

    uint32 Whirlwind_Timer;
    uint32 ChaosBlast_Timer;
    uint32 SwitchToDemon_Timer;
    uint32 SwitchToHuman_Timer;
    uint32 Berserk_Timer;
    uint32 InnerDemons_Timer;
    uint32 BanishTimer;

    bool DealDamage;
    bool NeedThreatReset;
    bool DemonForm;
    bool IsFinalForm;
    bool EnrageUsed;
    float x,y,z;

    uint64 InnderDemon[5];
    uint32 InnderDemon_Count;
    uint64 Demon;
    uint64 SpellBinderGUID[3];

    void Reset()
    {
        CheckChannelers();
        BanishTimer = 1000;
        Whirlwind_Timer = 15000;
        ChaosBlast_Timer = 1000;
        SwitchToDemon_Timer = 45000;
        SwitchToHuman_Timer = 60000;
        Berserk_Timer = 600000;
        InnerDemons_Timer = 30000;
        m_creature->SetCanDualWield(true);
        DealDamage = true;
        DemonForm = false;
        IsFinalForm = false;
        NeedThreatReset = false;
        EnrageUsed = false;
        InnderDemon_Count = 0;
        m_creature->SetSpeed( MOVE_RUN, 2.0f, true);
        m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID, MODEL_NIGHTELF);
		m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID  , 0);
        m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, 0);
        m_creature->CastSpell(m_creature, SPELL_DUAL_WIELD, true);
        m_creature->SetCorpseDelay(1000*60*60);
        if(pInstance)
            pInstance->SetData(DATA_LEOTHERASTHEBLINDEVENT, NOT_STARTED);
    }

    void CheckChannelers(bool DoEvade = true)
    {
        for(uint8 i = 0; i < 3; i++)
        {
            Creature *add = Unit::GetCreature(*m_creature,SpellBinderGUID[i]);
            if (add && add->isAlive())
            {
                add->setDeathState(DEAD);
                add->RemoveCorpse();
            }else{
                if(add && add->isDead())
                    add->RemoveCorpse();
            }
            float nx = x;
            float ny = y;
            float o = 2.4f;
            if (i == 0) {nx += 10; ny -= 5; o=2.5f;}
            if (i == 1) {nx -= 8; ny -= 7; o=0.9f;}
            if (i == 2) {nx -= 3; ny += 9; o=5.0f;}
            Creature* binder = m_creature->SummonCreature(MOB_SPELLBINDER,nx,ny,z,o,TEMPSUMMON_DEAD_DESPAWN,0);
            if (binder)
                SpellBinderGUID[i] = binder->GetGUID();

        }
    }
    void MoveInLineOfSight(Unit *who)
    {
        if(m_creature->HasAura(AURA_BANISH))
            return;

        if( !m_creature->getVictim() && who->isTargetableForAttack() && ( m_creature->IsHostileTo( who )) && who->isInAccessiblePlaceFor(m_creature) )
        {
            if (m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;

            float attackRadius = m_creature->GetAttackDistance(who);
            if(m_creature->IsWithinDistInMap(who, attackRadius))
            {
                // Check first that object is in an angle in front of this one before LoS check
                if( m_creature->HasInArc(M_PI/2.0f, who) && m_creature->IsWithinLOSInMap(who) )
                {
                    AttackStart(who);
                }
            }
        }
    }

    void StartEvent()
    {
        DoScriptText(SAY_AGGRO, m_creature);
        if(pInstance)
            pInstance->SetData(DATA_LEOTHERASTHEBLINDEVENT, IN_PROGRESS);
    }

    void CheckBanish()
    {
        uint8 AliveChannelers = 0;
        for(uint8 i = 0; i < 3; i++)
        {
            Unit *add = Unit::GetUnit(*m_creature,SpellBinderGUID[i]);
            if (add && add->isAlive())
                AliveChannelers++;
        }

        // channelers == 0 remove banish aura
        if(AliveChannelers == 0 && m_creature->HasAura(AURA_BANISH))
        {
            // removing banish aura
            m_creature->RemoveAurasDueToSpell(AURA_BANISH);

            // Leotheras is getting immune again
            m_creature->ApplySpellImmune(AURA_BANISH, IMMUNITY_MECHANIC, MECHANIC_BANISH, true);

            // changing model to bloodelf
            m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID, MODEL_NIGHTELF);

            // and reseting equipment
            m_creature->LoadEquipment(m_creature->GetEquipmentId());

            if(pInstance && pInstance->GetData64(DATA_LEOTHERAS_EVENT_STARTER))
            {
                Unit *victim = NULL;
                victim = Unit::GetUnit(*m_creature, pInstance->GetData64(DATA_LEOTHERAS_EVENT_STARTER));
                if(victim)
                    m_creature->getThreatManager().addThreat(victim, 1);
                StartEvent();
            }
        }
        else if(AliveChannelers != 0 && !m_creature->HasAura(AURA_BANISH))
        {
            // channelers != 0 apply banish aura
            // removing Leotheras banish immune to apply AURA_BANISH
            m_creature->ApplySpellImmune(AURA_BANISH, IMMUNITY_MECHANIC, MECHANIC_BANISH, false);
            DoCast(m_creature, AURA_BANISH);

            // changing model
            m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID, MODEL_DEMON);

            // and removing weapons
            m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID  , 0);
            m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, 0);
        }
    }

    //Despawn all Inner Demon summoned
    void DespawnDemon()
    {
        for(int i=0; i<5; i++)
        {
            if(InnderDemon[i])
            {
                    //delete creature
                    Unit* pUnit = Unit::GetUnit((*m_creature), InnderDemon[i]);
                    if (pUnit && pUnit->isAlive())
                    {
                        pUnit->DealDamage(pUnit, pUnit->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                    }
                    InnderDemon[i] = 0;
            }
        }

        InnderDemon_Count = 0;
    }

    void CastConsumingMadness() //remove this once SPELL_INSIDIOUS_WHISPER is supported by core
    {
        for(int i=0; i<5; i++)
        {
            if(InnderDemon[i] > 0 )
            {
                Unit* pUnit = Unit::GetUnit((*m_creature), InnderDemon[i]);
                if (pUnit && pUnit->isAlive())
                {
                    Unit* pUnit_target = Unit::GetUnit((*pUnit), ((mob_inner_demonAI *)((Creature *)pUnit)->AI())->victimGUID);
                    if( pUnit_target && pUnit_target->isAlive())
                    {
                        pUnit->CastSpell(pUnit_target, SPELL_CONSUMING_MADNESS, true);
                        DoModifyThreatPercent(pUnit_target, -100);
                    }
                }
            }
        }
    }

    void KilledUnit(Unit *victim)
    {
        if (victim->GetTypeId() != TYPEID_PLAYER)
            return;

        if (DemonForm)
        {
            switch(rand()%3)
            {
                case 0: DoScriptText(SAY_DEMON_SLAY1, m_creature); break;
                case 1: DoScriptText(SAY_DEMON_SLAY2, m_creature); break;
                case 2: DoScriptText(SAY_DEMON_SLAY3, m_creature); break;
            }
        }
        else
        {
            switch(rand()%3)
            {
                case 0: DoScriptText(SAY_NIGHTELF_SLAY1, m_creature); break;
                case 1: DoScriptText(SAY_NIGHTELF_SLAY2, m_creature); break;
                case 2: DoScriptText(SAY_NIGHTELF_SLAY3, m_creature); break;
            }
        }
    }

    void JustDied(Unit *victim)
    {
        DoScriptText(SAY_DEATH, m_creature);

        //despawn copy
        if (Demon)
        {
            Unit *pUnit = NULL;
            pUnit = Unit::GetUnit((*m_creature), Demon);

            if (pUnit)
                pUnit->DealDamage(pUnit, pUnit->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }
        if (pInstance)
            pInstance->SetData(DATA_LEOTHERASTHEBLINDEVENT, DONE);
    }

    void EnterCombat(Unit *who)
    {
        if(m_creature->HasAura(AURA_BANISH))
        return;

        m_creature->LoadEquipment(m_creature->GetEquipmentId());
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (m_creature->HasAura(AURA_BANISH) || !UpdateVictim())
        {
            if(BanishTimer<diff)
            {
                CheckBanish();//no need to check every update tick
                BanishTimer = 1000;
            }else BanishTimer -= diff;
            return;
        }
        if(m_creature->HasAura(SPELL_WHIRLWIND))
            if(Whirlwind_Timer < diff)
            {
                Unit *newTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                if(newTarget)
                {
                    DoResetThreat();
                    m_creature->GetMotionMaster()->Clear();
                    m_creature->GetMotionMaster()->MovePoint(0,newTarget->GetPositionX(),newTarget->GetPositionY(),newTarget->GetPositionZ());
                }
                Whirlwind_Timer = 2000;
            }else Whirlwind_Timer -= diff;

        // reseting after changing forms and after ending whirlwind
        if(NeedThreatReset && !m_creature->HasAura(SPELL_WHIRLWIND))
        {
            // when changing forms seting timers (or when ending whirlwind - to avoid adding new variable i use Whirlwind_Timer to countdown 2s while whirlwinding)
            if(DemonForm)
                InnerDemons_Timer = 30000;
            else
                Whirlwind_Timer =  15000;

            NeedThreatReset = false;
            DoResetThreat();
            m_creature->GetMotionMaster()->Clear();
            m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
        }

        //Enrage_Timer ( 10 min )
        if(Berserk_Timer < diff && !EnrageUsed)
        {
            DoCast(m_creature, SPELL_BERSERK);
            EnrageUsed = true;
        }else Berserk_Timer -= diff;

        if(!DemonForm)
        {
            //Whirldind Timer
            if(!m_creature->HasAura(SPELL_WHIRLWIND))
            {
                if(Whirlwind_Timer < diff)
                {
                    DoCast(m_creature, SPELL_WHIRLWIND);
                    // while whirlwinding this variable is used to countdown target's change
                    Whirlwind_Timer = 2000;
                    NeedThreatReset = true;
                }else Whirlwind_Timer -= diff;
            }
            //Switch_Timer

            if(!IsFinalForm)
                if(SwitchToDemon_Timer < diff)
                {
                    //switch to demon form
                    m_creature->RemoveAurasDueToSpell(SPELL_WHIRLWIND,0);
                    m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID, MODEL_DEMON);
                    DoScriptText(SAY_SWITCH_TO_DEMON, m_creature);
					m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID  , 0);
				    m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, 0);
                    DemonForm = true;
                    NeedThreatReset = true;
                    SwitchToDemon_Timer = 45000;
                }else SwitchToDemon_Timer -= diff;
            DoMeleeAttackIfReady();
        }
        else
        {
            //ChaosBlast_Timer
            if (!m_creature->getVictim())
                return;
            if(m_creature->GetDistance(m_creature->getVictim()) < 30)
                m_creature->StopMoving();
            if(ChaosBlast_Timer < diff)
            {
                // will cast only when in range of spell
                if(m_creature->GetDistance(m_creature->getVictim()) < 30)
                {
                    //m_creature->CastSpell(m_creature->getVictim(), SPELL_CHAOS_BLAST, true);
                    int damage = 100;
                    m_creature->CastCustomSpell(m_creature->getVictim(), SPELL_CHAOS_BLAST, &damage, NULL, NULL, false, NULL, NULL, m_creature->GetGUID());
                }
                ChaosBlast_Timer = 3000;
            }else ChaosBlast_Timer -= diff;
            //Summon Inner Demon
            if(InnerDemons_Timer < diff)
            {
                std::list<HostilReference *>& ThreatList = m_creature->getThreatManager().getThreatList();
                std::vector<Unit *> TargetList;
                for(std::list<HostilReference *>::iterator itr = ThreatList.begin(); itr != ThreatList.end(); ++itr)
                {
                    Unit *tempTarget = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid());
                    if(tempTarget && tempTarget->GetTypeId() == TYPEID_PLAYER && tempTarget->GetGUID() != m_creature->getVictim()->GetGUID() && TargetList.size()<5)
                        TargetList.push_back( tempTarget );
                }
                SpellEntry *spell = (SpellEntry *)GetSpellStore()->LookupEntry(SPELL_INSIDIOUS_WHISPER);
                for(std::vector<Unit *>::iterator itr = TargetList.begin(); itr != TargetList.end(); ++itr)
                {
                    if( (*itr) && (*itr)->isAlive() )
                    {
                        Creature * demon = (Creature *)m_creature->SummonCreature(INNER_DEMON_ID, (*itr)->GetPositionX()+10, (*itr)->GetPositionY()+10, (*itr)->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                        if(demon)
                        {
                            ((ScriptedAI *)demon->AI())->AttackStart( (*itr) );
                            ((mob_inner_demonAI *)demon->AI())->victimGUID = (*itr)->GetGUID();

                            uint8 eff_mask=0;
                            for (int i=0; i<3; i++)
                            {
                                if (!spell->Effect[i])
                                    continue;
                                eff_mask|=1<<i;
                            }
                            (*itr)->AddAura(new Aura(spell, eff_mask, NULL, (*itr), (*itr)));
                            if( InnderDemon_Count > 4 ) InnderDemon_Count = 0;

                            //Safe storing of creatures
                            InnderDemon[InnderDemon_Count] = demon->GetGUID();

                            //Update demon count
                            InnderDemon_Count++;
                        }
                    }
                }
                DoScriptText(SAY_INNER_DEMONS, m_creature);

                InnerDemons_Timer = 999999;
            }else InnerDemons_Timer -= diff;

            //Switch_Timer
            if(SwitchToHuman_Timer < diff)
            {
                //switch to nightelf form
                m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID, MODEL_NIGHTELF);
                m_creature->LoadEquipment(m_creature->GetEquipmentId());

                CastConsumingMadness();
                DespawnDemon();

                DemonForm = false;
                NeedThreatReset = true;

                SwitchToHuman_Timer = 60000;
            }else SwitchToHuman_Timer -= diff;
        }

        if (!IsFinalForm && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 15)
        {
            //at this point he divides himself in two parts
            Creature *Copy = NULL;
            Copy = DoSpawnCreature(DEMON_FORM, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 6000);
            if(Copy)
             {
                 Demon = Copy->GetGUID();
                if (m_creature->getVictim())
                    Copy->AI()->AttackStart(m_creature->getVictim());
            }
            //set nightelf final form
            IsFinalForm = true;
            DemonForm = false;

            DoScriptText(SAY_FINAL_FORM, m_creature);
            m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID, MODEL_NIGHTELF);
            m_creature->LoadEquipment(m_creature->GetEquipmentId());
        }
    }
};

//Leotheras the Blind Demon Form AI
struct TRINITY_DLL_DECL boss_leotheras_the_blind_demonformAI : public ScriptedAI
{
    boss_leotheras_the_blind_demonformAI(Creature *c) : ScriptedAI(c) {}

    uint32 ChaosBlast_Timer;
    bool DealDamage;

    void Reset()
    {
        ChaosBlast_Timer = 1000;
        DealDamage = true;
    }

    void StartEvent()
    {
        DoScriptText(SAY_FREE, m_creature);
    }

    void KilledUnit(Unit *victim)
    {
        if (victim->GetTypeId() != TYPEID_PLAYER)
            return;

        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_DEMON_SLAY1, m_creature); break;
            case 1: DoScriptText(SAY_DEMON_SLAY2, m_creature); break;
            case 2: DoScriptText(SAY_DEMON_SLAY3, m_creature); break;
        }
    }

    void JustDied(Unit *victim)
    {
        //invisibility (blizzlike, at the end of the fight he doesn't die, he disappears)
        m_creature->CastSpell(m_creature, 8149, true);
    }

    void EnterCombat(Unit *who)
    {
        StartEvent();
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim() )
            return;
        //ChaosBlast_Timer
        if(m_creature->GetDistance(m_creature->getVictim()) < 30)
            m_creature->StopMoving();

        if(ChaosBlast_Timer < diff)
         {
            // will cast only when in range od spell
            if(m_creature->GetDistance(m_creature->getVictim()) < 30)
            {
                //m_creature->CastSpell(m_creature->getVictim(),SPELL_CHAOS_BLAST,true);
                int damage = 100;
                m_creature->CastCustomSpell(m_creature->getVictim(), SPELL_CHAOS_BLAST, &damage, NULL, NULL, false, NULL, NULL, m_creature->GetGUID());
                ChaosBlast_Timer = 3000;
            }
         }else ChaosBlast_Timer -= diff;

        //Do NOT deal any melee damage to the target.
    }
};
struct TRINITY_DLL_DECL mob_greyheart_spellbinderAI : public ScriptedAI
{
    mob_greyheart_spellbinderAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance *)c->GetInstanceData());;
        leotherasGUID = 0;
        AddedBanish = false;
    }

    ScriptedInstance *pInstance;

    uint64 leotherasGUID;

    uint32 Mindblast_Timer;
    uint32 Earthshock_Timer;

    bool AddedBanish;

    void Reset()
    {
        Mindblast_Timer  = 3000 + rand()%5000;
        Earthshock_Timer = 5000 + rand()%5000;

        if(pInstance)
        {
            pInstance->SetData64(DATA_LEOTHERAS_EVENT_STARTER, 0);
            Creature *leotheras = (Creature *)Unit::GetUnit(*m_creature, leotherasGUID);
            if(leotheras && leotheras->isAlive())
                ((boss_leotheras_the_blindAI*)leotheras->AI())->CheckChannelers(false);
        }
    }

    void EnterCombat(Unit *who)
    {
        m_creature->InterruptNonMeleeSpells(false);
        if(pInstance)
            pInstance->SetData64(DATA_LEOTHERAS_EVENT_STARTER, who->GetGUID());
    }

    void JustRespawned()
    {
        AddedBanish = false;
        Reset();
    }

    void CastChanneling()
    {
        if(!m_creature->isInCombat() && !m_creature->m_currentSpells[CURRENT_CHANNELED_SPELL])
        {
            if(leotherasGUID)
            {
                Creature *leotheras = (Creature *)Unit::GetUnit(*m_creature, leotherasGUID);
                if(leotheras && leotheras->isAlive())
                    DoCast(leotheras, BANISH_BEAM);
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(pInstance)
        {
            if(!leotherasGUID)
                leotherasGUID = pInstance->GetData64(DATA_LEOTHERAS);

            if(!m_creature->isInCombat() && pInstance->GetData64(DATA_LEOTHERAS_EVENT_STARTER))
            {
                Unit *victim = NULL;
                victim = Unit::GetUnit(*m_creature, pInstance->GetData64(DATA_LEOTHERAS_EVENT_STARTER));
                if(victim)
                    AttackStart(victim);
            }
        }

        if(!UpdateVictim())
        {
            CastChanneling();
            return;
        }

        if(pInstance && !pInstance->GetData64(DATA_LEOTHERAS_EVENT_STARTER))
        {
            EnterEvadeMode();
            return;
        }

        if(Mindblast_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);

            if ( target )DoCast(target, SPELL_MINDBLAST);

            Mindblast_Timer = 10000 + rand()%5000;
        }else Mindblast_Timer -= diff;

        if(Earthshock_Timer < diff)
        {
            Map *map = m_creature->GetMap();
            Map::PlayerList const &PlayerList = map->GetPlayers();
            for(Map::PlayerList::const_iterator itr = PlayerList.begin();itr != PlayerList.end(); ++itr)
            {
                if (Player* i_pl = itr->getSource())
                {
                    bool isCasting = false;
                    for(uint8 i = 0; i < CURRENT_MAX_SPELL; ++i)
                        if(i_pl->m_currentSpells[i])
                            isCasting = true;

                    if(isCasting)
                    {
                        DoCast(i_pl, SPELL_EARTHSHOCK);
                        break;
                    }
                }
            }
            Earthshock_Timer = 8000 + rand()%7000;
        }else Earthshock_Timer -= diff;
        DoMeleeAttackIfReady();
    }

    void JustDied(Unit *killer) {}
};
CreatureAI* GetAI_boss_leotheras_the_blind(Creature *_Creature)
{
    return new boss_leotheras_the_blindAI (_Creature);
}

CreatureAI* GetAI_boss_leotheras_the_blind_demonform(Creature *_Creature)
{
    return new boss_leotheras_the_blind_demonformAI (_Creature);
}

CreatureAI* GetAI_mob_greyheart_spellbinder(Creature *_Creature)
{
    return new mob_greyheart_spellbinderAI (_Creature);
}

CreatureAI* GetAI_mob_inner_demon(Creature *_Creature)
{
    return new mob_inner_demonAI (_Creature);
}
void AddSC_boss_leotheras_the_blind()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_leotheras_the_blind";
    newscript->GetAI = &GetAI_boss_leotheras_the_blind;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="boss_leotheras_the_blind_demonform";
    newscript->GetAI = &GetAI_boss_leotheras_the_blind_demonform;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_greyheart_spellbinder";
    newscript->GetAI = &GetAI_mob_greyheart_spellbinder;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_inner_demon";
    newscript->GetAI = &GetAI_mob_inner_demon;
    newscript->RegisterSelf();
}

