/* Copyright(C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
*(at your option) any later version.
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
SDName: Boss_Magtheridon
SD%Complete: 60
SDComment: In Development
SDCategory: Hellfire Citadel, Magtheridon's lair
EndScriptData */
#include "precompiled.h"
#include "def_magtheridons_lair.h"
struct Yell
{
    int32 id;
};
static Yell RandomTaunt[]=
{
    {-1544000},
    {-1544001},
    {-1544002},
    {-1544003},
    {-1544004},
    {-1544005},
};
#define SAY_FREED                   -1544006
#define SAY_AGGRO                   -1544007
#define SAY_BANISH                  -1544008
#define SAY_CHAMBER_DESTROY         -1544009
#define SAY_PLAYER_KILLED           -1544010
#define SAY_DEATH                   -1544011
#define EMOTE_BERSERK               -1544012
#define EMOTE_BLASTNOVA             -1544013
#define EMOTE_BEGIN                 -1544014
#define MOB_MAGTHERIDON     17257
#define MOB_ROOM            17516
#define MOB_CHANNELLER      17256
#define MOB_ABYSSAL         17454
#define SPELL_BLASTNOVA             30616
#define SPELL_CLEAVE                30619
#define SPELL_QUAKE_TRIGGER         30657 // must be cast with 30561 as the proc spell
#define SPELL_QUAKE_KNOCKBACK       30571
#define SPELL_BLAZE_TARGET          30541 // core bug, does not support target 7
#define SPELL_BLAZE_TRAP            30542
#define SPELL_DEBRIS_KNOCKDOWN      36449
#define SPELL_DEBRIS_VISUAL         30632
#define SPELL_DEBRIS_DAMAGE         30631 // core bug, does not support target 8
#define SPELL_CAMERA_SHAKE          36455
#define SPELL_BERSERK               27680
#define SPELL_SHADOW_CAGE           30168
#define SPELL_SHADOW_GRASP          30410
#define SPELL_SHADOW_GRASP_VISUAL   30166
#define SPELL_MIND_EXHAUSTION       44032   //Casted by the cubes when channeling ends
#define SPELL_SHADOW_CAGE_C         30205
#define SPELL_SHADOW_GRASP_C        30207
#define SPELL_SHADOW_BOLT_VOLLEY    30510
#define SPELL_DARK_MENDING          30528
#define SPELL_FEAR                  30530 //39176
#define SPELL_BURNING_ABYSSAL       30511
#define SPELL_SOUL_TRANSFER         30531 // core bug, does not support target 7
#define SPELL_FIRE_BLAST            37110
// count of clickers needed to interrupt blast nova
#define CLICKERS_COUNT              5
typedef std::map<uint64, uint64> CubeMap;
struct TRINITY_DLL_DECL mob_abyssalAI : public ScriptedAI
{
    mob_abyssalAI(Creature *c) : ScriptedAI(c)
    {
        trigger = 0;
        Despawn_Timer = 60000;
    }
    uint32 FireBlast_Timer;
    uint32 Despawn_Timer;
    uint32 trigger;
    void Reset()
    {
        FireBlast_Timer = 6000;
    }
    void SpellHit(Unit*, const SpellEntry *spell)
    {
        if (trigger == 2 && spell->Id == SPELL_BLAZE_TARGET)
        {
            m_creature->CastSpell(m_creature, SPELL_BLAZE_TRAP, true);
            m_creature->SetVisibility(VISIBILITY_OFF);
            Despawn_Timer = 130000;
        }
    }
    void SetTrigger(uint32 _trigger)
    {
        trigger = _trigger;
        m_creature->SetDisplayId(11686);
        if (trigger == 1) //debris
        {
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            m_creature->CastSpell(m_creature, SPELL_DEBRIS_VISUAL, true);
            FireBlast_Timer = 5000;
            Despawn_Timer = 10000;
        }
    }
    void EnterCombat(Unit* who) {DoZoneInCombat();}
    void AttackStart(Unit *who) {if (!trigger) ScriptedAI::AttackStart(who);}
    void MoveInLineOfSight(Unit *who) {if (!trigger) ScriptedAI::MoveInLineOfSight(who);}
    void UpdateAI(const uint32 diff)
    {
        if (trigger)
        {
            if (trigger == 1)
            {
                if (FireBlast_Timer < diff)
                {
                    m_creature->CastSpell(m_creature, SPELL_DEBRIS_DAMAGE, true);
                    trigger = 3;
                }else FireBlast_Timer -= diff;
            }
            return;
        }
        if (Despawn_Timer < diff)
        {
            m_creature->ForcedDespawn();
        }else Despawn_Timer -= diff;
        if (!UpdateVictim())
            return;
        if (FireBlast_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_FIRE_BLAST);
            FireBlast_Timer = 5000+rand()%10000;
        }else FireBlast_Timer -= diff;
        DoMeleeAttackIfReady();
    }
};
struct TRINITY_DLL_DECL boss_magtheridonAI : public ScriptedAI
{
    boss_magtheridonAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        m_creature->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 10);
        m_creature->SetFloatValue(UNIT_FIELD_COMBATREACH, 10);
        // target 7, random target with certain entry spell, need core fix
        SpellEntry *TempSpell;
        TempSpell = GET_SPELL(SPELL_BLAZE_TARGET);
        if (TempSpell && TempSpell->EffectImplicitTargetA[0] != 6)
        {
            TempSpell->EffectImplicitTargetA[0] = 6;
            TempSpell->EffectImplicitTargetB[0] = 0;
        }
        TempSpell = GET_SPELL(SPELL_QUAKE_TRIGGER);
        if (TempSpell && TempSpell->EffectTriggerSpell[0] != SPELL_QUAKE_KNOCKBACK)
        {
            TempSpell->EffectTriggerSpell[0] = SPELL_QUAKE_KNOCKBACK;
        }
    }
    CubeMap Cube;
    ScriptedInstance* pInstance;
    uint32 Berserk_Timer;
    uint32 Quake_Timer;
    uint32 Cleave_Timer;
    uint32 BlastNova_Timer;
    uint32 Blaze_Timer;
    uint32 Debris_Timer;
    uint32 RandChat_Timer;
    bool Phase3;
    bool NeedCheckCube;
    void Reset()
    {
        Berserk_Timer = 1320000;
        Quake_Timer = 40000;
        Debris_Timer = 10000;
        Blaze_Timer = 10000+rand()%20000;
        BlastNova_Timer = 60000;
        Cleave_Timer = 15000;
        RandChat_Timer = 90000;
        Phase3 = false;
        NeedCheckCube = false;
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->addUnitState(UNIT_STAT_STUNNED);
        m_creature->CastSpell(m_creature, SPELL_SHADOW_CAGE_C, true);
    }
    void JustReachedHome()
    {
        if (pInstance)
        {
            pInstance->SetData(DATA_MAGTHERIDON_EVENT, NOT_STARTED);
            pInstance->SetData(DATA_COLLAPSE, false);
        }
    }
    void SetClicker(uint64 cubeGUID, uint64 clickerGUID)
    {
        // to avoid multiclicks from 1 cube
        if (uint64 guid = Cube[cubeGUID])
            DebuffClicker(Unit::GetUnit(*m_creature, guid));
        Cube[cubeGUID] = clickerGUID;
        NeedCheckCube = true;
    }
    //function to interrupt channeling and debuff clicker with mind exh(used if second person clicks with same cube or after dispeling/ending shadow grasp DoT)
    void DebuffClicker(Unit *clicker)
    {
        if (!clicker || !clicker->isAlive())
            return;
        clicker->RemoveAurasDueToSpell(SPELL_SHADOW_GRASP); // cannot interrupt triggered spells
        clicker->InterruptNonMeleeSpells(false);
        clicker->CastSpell(clicker, SPELL_MIND_EXHAUSTION, true);
    }
    void NeedCheckCubeStatus()
    {
        uint32 ClickerNum = 0;
        // now checking if every clicker has debuff from manticron(it is dispelable atm rev 6110 : S)
        // if not - apply mind exhaustion and delete from clicker's list
        for (CubeMap::iterator i = Cube.begin(); i != Cube.end(); ++i)
        {
            Unit *clicker = Unit::GetUnit(*m_creature, (*i).second);
            if (!clicker || !clicker->HasAura(SPELL_SHADOW_GRASP))
            {
                DebuffClicker(clicker);
                (*i).second = 0;
            }else ClickerNum++;
        }
        // if 5 clickers from other cubes apply shadow cage
        if (ClickerNum >= CLICKERS_COUNT && !m_creature->HasAura(SPELL_SHADOW_CAGE))
        {
            DoScriptText(SAY_BANISH, m_creature);
            m_creature->CastSpell(m_creature, SPELL_SHADOW_CAGE, true);
        }
        else if (ClickerNum < CLICKERS_COUNT && m_creature->HasAura(SPELL_SHADOW_CAGE))
            m_creature->RemoveAurasDueToSpell(SPELL_SHADOW_CAGE);
        if (!ClickerNum) NeedCheckCube = false;
    }
    void KilledUnit(Unit* victim)
    {
        DoScriptText(SAY_PLAYER_KILLED, m_creature);
    }
    void JustDied(Unit* Killer)
    {
        if (pInstance)
            pInstance->SetData(DATA_MAGTHERIDON_EVENT, DONE);
        DoScriptText(SAY_DEATH, m_creature);
    }
    void MoveInLineOfSight(Unit* who) {}
    void AttackStart(Unit *who)
    {
        if (!m_creature->hasUnitState(UNIT_STAT_STUNNED))
            ScriptedAI::AttackStart(who);
    }
    void EnterCombat(Unit *who)
    {
        if (pInstance)
            pInstance->SetData(DATA_MAGTHERIDON_EVENT, IN_PROGRESS);
        DoZoneInCombat();
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->RemoveAurasDueToSpell(SPELL_SHADOW_CAGE_C);
        DoScriptText(SAY_FREED, m_creature);
   }
    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->isInCombat())
        {
            if (RandChat_Timer < diff)
            {
                DoScriptText(RandomTaunt[rand()%6].id, m_creature);
                RandChat_Timer = 90000;
            }else RandChat_Timer -= diff;
        }
        if (!UpdateVictim())
            return;
        if (NeedCheckCube) NeedCheckCubeStatus();
        if (Berserk_Timer < diff)
        {
            m_creature->CastSpell(m_creature, SPELL_BERSERK, true);
            DoScriptText(EMOTE_BERSERK, m_creature);
            Berserk_Timer = 60000;
        }else Berserk_Timer -= diff;
        if (Cleave_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CLEAVE);
            Cleave_Timer = 10000;
        }else Cleave_Timer -= diff;
        if (BlastNova_Timer < diff)
        {
            // to avoid earthquake interruption
            if (!m_creature->hasUnitState(UNIT_STAT_STUNNED))
            {
                DoScriptText(EMOTE_BLASTNOVA, m_creature);
                DoCast(m_creature, SPELL_BLASTNOVA);
                BlastNova_Timer = 60000;
            }
        }else BlastNova_Timer -= diff;
        if (Quake_Timer < diff)
        {
            // to avoid blastnova interruption
            if (!m_creature->IsNonMeleeSpellCasted(false))
            {
                m_creature->CastSpell(m_creature, SPELL_QUAKE_TRIGGER, true);
                Quake_Timer = 50000;
            }
        }else Quake_Timer -= diff;
        if (Blaze_Timer < diff)
        {
            if (Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 0))
            {
                float x, y, z;
                target->GetPosition(x, y, z);
                Creature *summon = m_creature->SummonCreature(MOB_ABYSSAL, x, y, z, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                if (summon)
                {
                    CAST_AI(mob_abyssalAI, summon->AI())->SetTrigger(2);
                    m_creature->CastSpell(summon, SPELL_BLAZE_TARGET, true);
                    summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }
            }
            Blaze_Timer = 20000 + rand()%20000;
        }else Blaze_Timer -= diff;
        if (!Phase3 && m_creature->GetHealth()*10 < m_creature->GetMaxHealth()*3
            && !m_creature->IsNonMeleeSpellCasted(false) // blast nova
            && !m_creature->hasUnitState(UNIT_STAT_STUNNED)) // shadow cage and earthquake
        {
            Phase3 = true;
            DoScriptText(SAY_CHAMBER_DESTROY, m_creature);
            m_creature->CastSpell(m_creature, SPELL_CAMERA_SHAKE, true);
            m_creature->CastSpell(m_creature, SPELL_DEBRIS_KNOCKDOWN, true);
            if (pInstance)
                pInstance->SetData(DATA_COLLAPSE, true);
        }
        if (Phase3)
        {
            if (Debris_Timer < diff)
            {
                if (Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                {
                    float x, y, z;
                    target->GetPosition(x, y, z);
                    Creature *summon = m_creature->SummonCreature(MOB_ABYSSAL, x, y, z, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    if (summon) CAST_AI(mob_abyssalAI, summon->AI())->SetTrigger(1);
                }
                Debris_Timer = 10000;
            }else Debris_Timer -= diff;
        }
        DoMeleeAttackIfReady();
    }
};
struct TRINITY_DLL_DECL mob_hellfire_channelerAI : public ScriptedAI
{
    mob_hellfire_channelerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance =m_creature->GetInstanceData();
    }
    ScriptedInstance* pInstance;
    uint32 ShadowBoltVolley_Timer;
    uint32 DarkMending_Timer;
    uint32 Fear_Timer;
    uint32 Infernal_Timer;
    uint32 Check_Timer;
    void Reset()
    {
        ShadowBoltVolley_Timer = 8000 + rand()%2000;
        DarkMending_Timer = 10000;
        Fear_Timer = 15000 + rand()%5000;
        Infernal_Timer = 10000 + rand()%40000;
        Check_Timer = 5000;
    }
    void EnterCombat(Unit *who)
    {
        if (pInstance)
            pInstance->SetData(DATA_CHANNELER_EVENT, IN_PROGRESS);
        m_creature->InterruptNonMeleeSpells(false);
        DoZoneInCombat();
    }
    void JustReachedHome()
    {
        if (pInstance)
            pInstance->SetData(DATA_CHANNELER_EVENT, NOT_STARTED);
        m_creature->CastSpell(m_creature, SPELL_SHADOW_GRASP_C, false);
    }
    void JustSummoned(Creature *summon)
    {
        summon->AI()->AttackStart(m_creature->getVictim());
    }
    void DamageTaken(Unit*, uint32 &damage)
    {
        if (damage >= m_creature->GetHealth())
            m_creature->CastSpell(m_creature, SPELL_SOUL_TRANSFER, true);
    }
    void JustDied(Unit* who)
    {
        if (pInstance)
            pInstance->SetData(DATA_CHANNELER_EVENT, DONE);
    }
    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;
        if (ShadowBoltVolley_Timer < diff)
        {
            DoCast(m_creature, SPELL_SHADOW_BOLT_VOLLEY);
            ShadowBoltVolley_Timer = 10000 + rand()%10000;
        }else ShadowBoltVolley_Timer -= diff;
        if (DarkMending_Timer < diff)
        {
            if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 50)
                DoCast(m_creature, SPELL_DARK_MENDING);
            DarkMending_Timer = 10000 +(rand() % 10000);
        }else DarkMending_Timer -= diff;
        if (Fear_Timer < diff)
        {
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1))
                DoCast(target, SPELL_FEAR);
            Fear_Timer = 25000 + rand()%15000;
        }else Fear_Timer -= diff;
        if (Infernal_Timer < diff)
        {
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                m_creature->CastSpell(target, SPELL_BURNING_ABYSSAL, true);
            Infernal_Timer = 30000 + rand()%10000;
        }else Infernal_Timer -= diff;
        DoMeleeAttackIfReady();
    }
};
//Manticron Cube
bool GOHello_go_Manticron_Cube(Player* pPlayer, GameObject* pGo)
{
    ScriptedInstance* pInstance = pGo->GetInstanceData();
    if (!pInstance)
        return true;
    if (pInstance->GetData(DATA_MAGTHERIDON_EVENT) != IN_PROGRESS) return true;
    Creature *Magtheridon =Unit::GetCreature(*pGo, pInstance->GetData64(DATA_MAGTHERIDON));
    if (!Magtheridon || !Magtheridon->isAlive()) return true;
    // if exhausted or already channeling return
    if (pPlayer->HasAura(SPELL_MIND_EXHAUSTION) || pPlayer->HasAura(SPELL_SHADOW_GRASP))
        return true;
    pPlayer->InterruptNonMeleeSpells(false);
    pPlayer->CastSpell(pPlayer, SPELL_SHADOW_GRASP, true);
    pPlayer->CastSpell(pPlayer, SPELL_SHADOW_GRASP_VISUAL, false);
    CAST_AI(boss_magtheridonAI, Magtheridon->AI())->SetClicker(pGo->GetGUID(), pPlayer->GetGUID());
    return true;
}
CreatureAI* GetAI_boss_magtheridon(Creature* pCreature)
{
    return new boss_magtheridonAI(pCreature);
}
CreatureAI* GetAI_mob_hellfire_channeler(Creature* pCreature)
{
    return new mob_hellfire_channelerAI(pCreature);
}
CreatureAI* GetAI_mob_abyssalAI(Creature* pCreature)
{
    return new mob_abyssalAI(pCreature);
}
void AddSC_boss_magtheridon()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_magtheridon";
    newscript->GetAI = &GetAI_boss_magtheridon;
    newscript->RegisterSelf();
    newscript = new Script;
    newscript->Name = "mob_hellfire_channeler";
    newscript->GetAI = &GetAI_mob_hellfire_channeler;
    newscript->RegisterSelf();
    newscript = new Script;
    newscript->Name = "go_manticron_cube";
    newscript->pGOHello = &GOHello_go_Manticron_Cube;
    newscript->RegisterSelf();
    newscript = new Script;
    newscript->Name = "mob_abyssal";
    newscript->GetAI = &GetAI_mob_abyssalAI;
    newscript->RegisterSelf();
}

