/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Shade_of_Aran
SD%Complete: 95
SDComment: Flame wreath missing cast animation, mods won't triggere.
SDCategory: Karazhan
EndScriptData */

#include "precompiled.h"
#include "../../creature/simple_ai.h"
#include "def_karazhan.h"
#include "GameObject.h"

#define SAY_AGGRO1                  -1532073
#define SAY_AGGRO2                  -1532074
#define SAY_AGGRO3                  -1532075
#define SAY_FLAMEWREATH1            -1532076
#define SAY_FLAMEWREATH2            -1532077
#define SAY_BLIZZARD1               -1532078
#define SAY_BLIZZARD2               -1532079
#define SAY_EXPLOSION1              -1532080
#define SAY_EXPLOSION2              -1532081
#define SAY_DRINK                   -1532082                //Low Mana / AoE Pyroblast
#define SAY_ELEMENTALS              -1532083
#define SAY_KILL1                   -1532084
#define SAY_KILL2                   -1532085
#define SAY_TIMEOVER                -1532086
#define SAY_DEATH                   -1532087
#define SAY_ATIESH                  -1532088                //Atiesh is equipped by a raid member

//Spells
#define SPELL_FROSTBOLT     29954
#define SPELL_FIREBALL      29953
#define SPELL_ARCMISSLE     29955
#define SPELL_CHAINSOFICE   29991
#define SPELL_DRAGONSBREATH 29964
#define SPELL_MASSSLOW      30035
#define SPELL_FLAME_WREATH  29946
#define SPELL_AOE_CS        29961
#define SPELL_PLAYERPULL    32265
#define SPELL_AEXPLOSION    29973
#define SPELL_MASS_POLY     29963
#define SPELL_BLINK_CENTER  29967
#define SPELL_ELEMENTALS    29962
#define SPELL_CONJURE       29975
#define SPELL_DRINK         30024
#define SPELL_POTION        32453
#define SPELL_AOE_PYROBLAST 29978

//Creature Spells
#define SPELL_CIRCULAR_BLIZZARD     29951                   //29952 is the REAL circular blizzard that leaves persistant blizzards that last for 10 seconds
#define SPELL_WATERBOLT             31012
#define SPELL_SHADOW_PYRO           29978

//Creatures
#define CREATURE_WATER_ELEMENTAL    17167
#define CREATURE_SHADOW_OF_ARAN     18254
#define CREATURE_ARAN_BLIZZARD      17161

enum SuperSpell
{
    SUPER_FLAME = 0,
    SUPER_BLIZZARD,
    SUPER_AE,
};

struct TRINITY_DLL_DECL boss_aranAI : public ScriptedAI
{
    boss_aranAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
    }

    ScriptedInstance* pInstance;

    uint32 SecondarySpellTimer;
    uint32 NormalCastTimer;
    uint32 SuperCastTimer;
    uint32 BerserkTimer;
    uint32 CloseDoorTimer;                                  // Don't close the door right on aggro in case some people are still entering.

    uint8 LastSuperSpell;

    uint32 FlameWreathTimer;
    uint32 FlameWreathCheckTime;
    uint64 FlameWreathTarget[3];
    float FWTargPosX[3];
    float FWTargPosY[3];

    uint32 CurrentNormalSpell;
    uint32 ArcaneCooldown;
    uint32 FireCooldown;
    uint32 FrostCooldown;

    uint32 DrinkInturruptTimer;

    bool ElementalsSpawned;
    bool Drinking;
    bool DrinkInturrupted;

    void Reset()
    {
        SecondarySpellTimer = 5000;
        NormalCastTimer = 0;
        SuperCastTimer = 35000;
        BerserkTimer = 720000;
        CloseDoorTimer = 15000;

        LastSuperSpell = rand()%3;

        FlameWreathTimer = 0;
        FlameWreathCheckTime = 0;

        CurrentNormalSpell = 0;
        ArcaneCooldown = 0;
        FireCooldown = 0;
        FrostCooldown = 0;

        DrinkInturruptTimer = 10000;

        ElementalsSpawned = false;
        Drinking = false;
        DrinkInturrupted = false;

        if(pInstance)
        {
            // Not in progress
            pInstance->SetData(DATA_SHADEOFARAN_EVENT, NOT_STARTED);

            if(GameObject* Door = GameObject::GetGameObject(*m_creature, pInstance->GetData64(DATA_GAMEOBJECT_LIBRARY_DOOR)))
                Door->SetGoState(0);
        }
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
        case 0: DoScriptText(SAY_KILL1, m_creature); break;
        case 1: DoScriptText(SAY_KILL2, m_creature); break;
        }
    }

    void JustDied(Unit *victim)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if(pInstance)
        {
            pInstance->SetData(DATA_SHADEOFARAN_EVENT, DONE);

            if(GameObject* Door = GameObject::GetGameObject(*m_creature, pInstance->GetData64(DATA_GAMEOBJECT_LIBRARY_DOOR)))
                Door->SetGoState(0);
        }
    }

    void Aggro(Unit *who)
    {
        switch(rand()%3)
        {
        case 0: DoScriptText(SAY_AGGRO1, m_creature); break;
        case 1: DoScriptText(SAY_AGGRO2, m_creature); break;
        case 2: DoScriptText(SAY_AGGRO3, m_creature); break;
        }

        if(pInstance)
        {
            pInstance->SetData(DATA_SHADEOFARAN_EVENT, IN_PROGRESS);
            if(GameObject* Door = GameObject::GetGameObject(*m_creature, pInstance->GetData64(DATA_GAMEOBJECT_LIBRARY_DOOR)))
                Door->SetGoState(1);
        }
    }

    void FlameWreathEffect()
    {
        std::vector<Unit*> targets;
        std::list<HostilReference *> t_list = m_creature->getThreatManager().getThreatList();

        if(!t_list.size())
            return;

        //store the threat list in a different container
        for(std::list<HostilReference *>::iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
        {
            Unit *target = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid());
            //only on alive players
            if(target && target->isAlive() && target->GetTypeId() == TYPEID_PLAYER )
                targets.push_back( target);
        }

        //cut down to size if we have more than 3 targets
        while(targets.size() > 3)
            targets.erase(targets.begin()+rand()%targets.size());

        uint32 i = 0;
        for(std::vector<Unit*>::iterator itr = targets.begin(); itr!= targets.end(); ++itr)
        {
            if(*itr)
            {
                FlameWreathTarget[i] = (*itr)->GetGUID();
                FWTargPosX[i] = (*itr)->GetPositionX();
                FWTargPosY[i] = (*itr)->GetPositionY();
                m_creature->CastSpell((*itr), SPELL_FLAME_WREATH, true);
                i++;
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim() )
            return;

        if(CloseDoorTimer)
        {
            if(CloseDoorTimer <= diff)
            {
                if(pInstance)
                {
                    if(GameObject* Door = GameObject::GetGameObject(*m_creature, pInstance->GetData64(DATA_GAMEOBJECT_LIBRARY_DOOR)))
                        Door->SetGoState(1);
                    CloseDoorTimer = 0;
                }
            }else CloseDoorTimer -= diff;
        }

        //Cooldowns for casts
        if (ArcaneCooldown)
        {
            if (ArcaneCooldown >= diff)
                ArcaneCooldown -= diff;
        else ArcaneCooldown = 0;
        }

        if (FireCooldown)
        {
            if (FireCooldown >= diff)
                FireCooldown -= diff;
        else FireCooldown = 0;
        }

        if (FrostCooldown)
        {
            if (FrostCooldown >= diff)
                FrostCooldown -= diff;
        else FrostCooldown = 0;
        }

        if(!Drinking && m_creature->GetMaxPower(POWER_MANA) && (m_creature->GetPower(POWER_MANA)*100 / m_creature->GetMaxPower(POWER_MANA)) < 20)
        {
            Drinking = true;
            m_creature->InterruptNonMeleeSpells(false);

            DoScriptText(SAY_DRINK, m_creature);

            if (!DrinkInturrupted)
            {
                m_creature->CastSpell(m_creature, SPELL_MASS_POLY, true);
                m_creature->CastSpell(m_creature, SPELL_CONJURE, false);
                m_creature->CastSpell(m_creature, SPELL_DRINK, false);
                                                            //Sitting down
                m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, 1);
                DrinkInturruptTimer = 10000;
            }
        }

        //Drink Inturrupt
        if (Drinking && DrinkInturrupted)
        {
            Drinking = false;
            m_creature->RemoveAurasDueToSpell(SPELL_DRINK);
            m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
            m_creature->SetPower(POWER_MANA, m_creature->GetMaxPower(POWER_MANA)-32000);
            m_creature->CastSpell(m_creature, SPELL_POTION, false);
        }

        //Drink Inturrupt Timer
        if (Drinking && !DrinkInturrupted)
            if (DrinkInturruptTimer >= diff)
                DrinkInturruptTimer -= diff;
        else
        {
            m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
            m_creature->CastSpell(m_creature, SPELL_POTION, true);
            m_creature->CastSpell(m_creature, SPELL_AOE_PYROBLAST, false);
            DrinkInturrupted = true;
            Drinking = false;
        }

        //Don't execute any more code if we are drinking
        if (Drinking)
            return;

        //Normal casts
        if(NormalCastTimer < diff)
        {
            if (!m_creature->IsNonMeleeSpellCasted(false))
            {
                Unit* target = NULL;
                target = SelectUnit(SELECT_TARGET_RANDOM, 0);
                if (!target)
                    return;

                uint32 Spells[3];
                uint8 AvailableSpells = 0;

                //Check for what spells are not on cooldown
                if (!ArcaneCooldown)
                {
                    Spells[AvailableSpells] = SPELL_ARCMISSLE;
                    AvailableSpells++;
                }
                if (!FireCooldown)
                {
                    Spells[AvailableSpells] = SPELL_FIREBALL;
                    AvailableSpells++;
                }
                if (!FrostCooldown)
                {
                    Spells[AvailableSpells] = SPELL_FROSTBOLT;
                    AvailableSpells++;
                }

                //If no available spells wait 1 second and try again
                if (AvailableSpells)
                {
                    CurrentNormalSpell = Spells[rand() % AvailableSpells];
                    DoCast(target, CurrentNormalSpell);
                }
            }
            NormalCastTimer = 1000;
        }else NormalCastTimer -= diff;

        if(SecondarySpellTimer < diff)
        {
            switch (rand()%2)
            {

                case 0:
                    DoCast(m_creature, SPELL_AOE_CS);
                    break;
                case 1:
                    if (Unit* pUnit = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pUnit, SPELL_CHAINSOFICE);
                    break;
            }
            SecondarySpellTimer = 5000 + (rand()%15000);
        }else SecondarySpellTimer -= diff;

        if(SuperCastTimer < diff)
        {
            uint8 Available[2];

            switch (LastSuperSpell)
            {
                case SUPER_AE:
                    Available[0] = SUPER_FLAME;
                    Available[1] = SUPER_BLIZZARD;
                    break;
                case SUPER_FLAME:
                    Available[0] = SUPER_AE;
                    Available[1] = SUPER_BLIZZARD;
                    break;
                case SUPER_BLIZZARD:
                    Available[0] = SUPER_FLAME;
                    Available[1] = SUPER_AE;
                    break;
            }

            LastSuperSpell = Available[rand()%2];

            switch (LastSuperSpell)
            {
                case SUPER_AE:

                    if (rand()%2)
                        DoScriptText(SAY_EXPLOSION1, m_creature);
                    else
                        DoScriptText(SAY_EXPLOSION2, m_creature);

                    m_creature->CastSpell(m_creature, SPELL_BLINK_CENTER, true);
                    m_creature->CastSpell(m_creature, SPELL_PLAYERPULL, true);
                    m_creature->CastSpell(m_creature, SPELL_MASSSLOW, true);
                    m_creature->CastSpell(m_creature, SPELL_AEXPLOSION, false);
                    break;

                case SUPER_FLAME:
                    if (rand()%2)
                        DoScriptText(SAY_FLAMEWREATH1, m_creature);
                    else
                        DoScriptText(SAY_FLAMEWREATH2, m_creature);

                    FlameWreathTimer = 20000;
                    FlameWreathCheckTime = 500;

                    FlameWreathTarget[0] = 0;
                    FlameWreathTarget[1] = 0;
                    FlameWreathTarget[2] = 0;

                    FlameWreathEffect();
                    break;

                case SUPER_BLIZZARD:

                    if (rand()%2)
                        DoScriptText(SAY_BLIZZARD1, m_creature);
                    else
                        DoScriptText(SAY_BLIZZARD2, m_creature);

                    Creature* Spawn = NULL;
                    Spawn = DoSpawnCreature(CREATURE_ARAN_BLIZZARD, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 25000);
                    if (Spawn)
                    {
                        Spawn->setFaction(m_creature->getFaction());
                        Spawn->CastSpell(Spawn, SPELL_CIRCULAR_BLIZZARD, false);
                    }
                    break;
            }

            SuperCastTimer = 35000 + (rand()%5000);
        }else SuperCastTimer -= diff;

        if(!ElementalsSpawned && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 40)
        {
            ElementalsSpawned = true;

            for (uint32 i = 0; i < 4; i++)
            {
                Creature* pUnit = DoSpawnCreature(CREATURE_WATER_ELEMENTAL, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 90000);
                if (pUnit)
                {
                    pUnit->Attack(m_creature->getVictim(), true);
                    pUnit->setFaction(m_creature->getFaction());
                }
            }

            DoScriptText(SAY_ELEMENTALS, m_creature);
        }

        if(BerserkTimer < diff)
        {
            for (uint32 i = 0; i < 5; i++)
            {
                Creature* pUnit = DoSpawnCreature(CREATURE_SHADOW_OF_ARAN, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                if (pUnit)
                {
                    pUnit->Attack(m_creature->getVictim(), true);
                    pUnit->setFaction(m_creature->getFaction());
                }
            }

            DoScriptText(SAY_TIMEOVER, m_creature);

            BerserkTimer = 60000;
        }else BerserkTimer -= diff;

        //Flame Wreath check
        if (FlameWreathTimer)
        {
            if (FlameWreathTimer >= diff)
                FlameWreathTimer -= diff;
            else FlameWreathTimer = 0;

            if (FlameWreathCheckTime < diff)
            {
                for (uint32 i = 0; i < 3; i++)
                {
                    if (!FlameWreathTarget[i])
                        continue;

                    Unit* pUnit = Unit::GetUnit(*m_creature, FlameWreathTarget[i]);
                    if (pUnit && pUnit->GetDistance2d(FWTargPosX[i], FWTargPosY[i]) > 3)
                    {
                        pUnit->CastSpell(pUnit, 20476, true, 0, 0, m_creature->GetGUID());
                        pUnit->CastSpell(pUnit, 11027, true);
                        FlameWreathTarget[i] = 0;
                    }
                }
                FlameWreathCheckTime = 500;
            }else FlameWreathCheckTime -= diff;
        }

        if (ArcaneCooldown && FireCooldown && FrostCooldown)
            DoMeleeAttackIfReady();
    }

    void DamageTaken(Unit* pAttacker, uint32 &damage)
    {
        if (!DrinkInturrupted && Drinking && damage)
            DrinkInturrupted = true;
    }

    void SpellHit(Unit* pAttacker, const SpellEntry* Spell)
    {
        //We only care about inturrupt effects and only if they are durring a spell currently being casted
        if ((Spell->Effect[0]!=SPELL_EFFECT_INTERRUPT_CAST &&
            Spell->Effect[1]!=SPELL_EFFECT_INTERRUPT_CAST &&
            Spell->Effect[2]!=SPELL_EFFECT_INTERRUPT_CAST) || !m_creature->IsNonMeleeSpellCasted(false))
            return;

        //Inturrupt effect
        m_creature->InterruptNonMeleeSpells(false);

        //Normally we would set the cooldown equal to the spell duration
        //but we do not have access to the DurationStore

        switch (CurrentNormalSpell)
        {
            case SPELL_ARCMISSLE: ArcaneCooldown = 5000; break;
            case SPELL_FIREBALL: FireCooldown = 5000; break;
            case SPELL_FROSTBOLT: FrostCooldown = 5000; break;
        }
    }
};

struct TRINITY_DLL_DECL water_elementalAI : public ScriptedAI
{
    water_elementalAI(Creature *c) : ScriptedAI(c) {}

    uint32 CastTimer;

    void Reset()
    {
        CastTimer = 2000 + (rand()%3000);
    }

    void Aggro(Unit* who) {}

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim() )
            return;

        if(CastTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_WATERBOLT);
            CastTimer = 2000 + (rand()%3000);
        }else CastTimer -= diff;
    }
};

CreatureAI* GetAI_boss_aran(Creature *_Creature)
{
    return new boss_aranAI (_Creature);
}

CreatureAI* GetAI_water_elemental(Creature *_Creature)
{
    return new water_elementalAI (_Creature);
}

// CONVERT TO ACID
CreatureAI* GetAI_shadow_of_aran(Creature *_Creature)
{
    outstring_log("TSCR: Convert simpleAI script for Creature Entry %u to ACID", _Creature->GetEntry());
    SimpleAI* ai = new SimpleAI (_Creature);

    ai->Spell[0].Enabled = true;
    ai->Spell[0].Spell_Id = SPELL_SHADOW_PYRO;
    ai->Spell[0].Cooldown = 5000;
    ai->Spell[0].First_Cast = 1000;
    ai->Spell[0].Cast_Target_Type = CAST_HOSTILE_TARGET;

    ai->EnterEvadeMode();

    return ai;
}

void AddSC_boss_shade_of_aran()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_shade_of_aran";
    newscript->GetAI = &GetAI_boss_aran;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_shadow_of_aran";
    newscript->GetAI = &GetAI_shadow_of_aran;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_aran_elemental";
    newscript->GetAI = &GetAI_water_elemental;
    newscript->RegisterSelf();
}

