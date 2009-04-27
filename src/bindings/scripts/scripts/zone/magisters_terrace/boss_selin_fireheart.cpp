/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Selin_Fireheart
SD%Complete: 90
SDComment: Heroic and Normal Support. Needs further testing.
SDCategory: Magister's Terrace
EndScriptData */

#include "precompiled.h"
#include "def_magisters_terrace.h"

#define SAY_AGGRO                       -1585000
#define SAY_ENERGY                      -1585001
#define SAY_EMPOWERED                   -1585002
#define SAY_KILL_1                      -1585003
#define SAY_KILL_2                      -1585004
#define SAY_DEATH                       -1585005
#define EMOTE_CRYSTAL                   -1585006

//Crystal effect spells
#define SPELL_FEL_CRYSTAL_COSMETIC      44374
#define SPELL_FEL_CRYSTAL_DUMMY         44329
#define SPELL_FEL_CRYSTAL_VISUAL        44355
#define SPELL_MANA_RAGE                 44320               // This spell triggers 44321, which changes scale and regens mana Requires an entry in spell_script_target

//Selin's spells
#define SPELL_DRAIN_LIFE                44294
#define SPELL_FEL_EXPLOSION             44314

#define SPELL_DRAIN_MANA                46153               // Heroic only

#define CRYSTALS_NUMBER                 5
#define DATA_CRYSTALS                   6

#define CREATURE_FEL_CRYSTAL            24722

struct TRINITY_DLL_DECL boss_selin_fireheartAI : public ScriptedAI
{
    boss_selin_fireheartAI(Creature* c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());

        Crystals.clear();
        //GUIDs per instance is static, so we only need to load them once.
        if (pInstance)
        {
            uint32 size = pInstance->GetData(DATA_FEL_CRYSTAL_SIZE);
            for(uint8 i = 0; i < size; ++i)
            {
                uint64 guid = pInstance->GetData64(DATA_FEL_CRYSTAL);
                debug_log("TSCR: Selin: Adding Fel Crystal %u to list", guid);
                Crystals.push_back(guid);
            }
        }
        Heroic = c->GetMap()->IsHeroic();
    }

    ScriptedInstance* pInstance;
    bool Heroic;

    std::list<uint64> Crystals;

    uint32 DrainLifeTimer;
    uint32 DrainManaTimer;
    uint32 FelExplosionTimer;
    uint32 DrainCrystalTimer;
    uint32 EmpowerTimer;

    bool IsDraining;
    bool DrainingCrystal;

    uint64 CrystalGUID;                                     // This will help us create a pointer to the crystal we are draining. We store GUIDs, never units in case unit is deleted/offline (offline if player of course).

    void Reset()
    {
        if (pInstance)
        {
            //for(uint8 i = 0; i < CRYSTALS_NUMBER; ++i)
            for(std::list<uint64>::iterator itr = Crystals.begin(); itr != Crystals.end(); ++itr)
            {
                //Unit* pUnit = Unit::GetUnit(*m_creature, FelCrystals[i]);
                Unit* pUnit = Unit::GetUnit(*m_creature, *itr);
                if (pUnit)
                {
                    if(!pUnit->isAlive())
                        ((Creature*)pUnit)->Respawn();      // Let MaNGOS handle setting death state, etc.

                    // Only need to set unselectable flag. You can't attack unselectable units so non_attackable flag is not necessary here.
                    pUnit->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }
            }

            GameObject* Door = GameObject::GetGameObject(*m_creature, pInstance->GetData64(DATA_SELIN_ENCOUNTER_DOOR));
            if (Door)
                Door->SetGoState(GO_STATE_ACTIVE);                        // Open the big encounter door. Close it in Aggro and open it only in JustDied(and here)
                                                            // Small door opened after event are expected to be closed by default
            // Set Inst data for encounter
            pInstance->SetData(DATA_SELIN_EVENT, NOT_STARTED);
        }else error_log(ERROR_INST_DATA);

        DrainLifeTimer = 3000 + rand()%4000;
        DrainManaTimer = DrainLifeTimer + 5000;
        FelExplosionTimer = 2100;
        DrainCrystalTimer = 10000 + rand()%5000;
        DrainCrystalTimer = 20000 + rand()%5000;
        EmpowerTimer = 10000;

        IsDraining = false;
        DrainingCrystal = false;
        CrystalGUID = 0;
    }

    void SelectNearestCrystal()
    {
        if (Crystals.empty())
            return;

        float ShortestDistance = 0;
        CrystalGUID = 0;
        Unit* pCrystal = NULL;
        Unit* CrystalChosen = NULL;
        //for(uint8 i =  0; i < CRYSTALS_NUMBER; ++i)
        for(std::list<uint64>::iterator itr = Crystals.begin(); itr != Crystals.end(); ++itr)
        {
            pCrystal = NULL;
            //pCrystal = Unit::GetUnit(*m_creature, FelCrystals[i]);
            pCrystal = Unit::GetUnit(*m_creature, *itr);
            if (pCrystal && pCrystal->isAlive())
            {
                if (!ShortestDistance || (ShortestDistance > m_creature->GetDistance2d(pCrystal)))
                {
                    ShortestDistance = m_creature->GetDistance2d(pCrystal);
                    CrystalGUID = pCrystal->GetGUID();
                    CrystalChosen = pCrystal;               // Store a copy of pCrystal so we don't need to recreate a pointer to closest crystal for the movement and yell.
                }
            }
        }
        if (CrystalChosen)
        {
            DoScriptText(SAY_ENERGY, m_creature);
            DoScriptText(EMOTE_CRYSTAL, m_creature);

            CrystalChosen->CastSpell(CrystalChosen, SPELL_FEL_CRYSTAL_COSMETIC, true);

            float x, y, z;                                  // coords that we move to, close to the crystal.
            CrystalChosen->GetClosePoint(x, y, z, m_creature->GetObjectSize(), CONTACT_DISTANCE);

            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
            m_creature->GetMotionMaster()->MovePoint(1, x, y, z);
            DrainingCrystal = true;
        }
    }

    void ShatterRemainingCrystals()
    {
        if (Crystals.empty())
            return;

        //for(uint8 i = 0; i < CRYSTALS_NUMBER; ++i)
        for(std::list<uint64>::iterator itr = Crystals.begin(); itr != Crystals.end(); ++itr)
        {
            //Creature* pCrystal = (Unit::GetCreature(*m_creature, FelCrystals[i]));
            Creature* pCrystal = (Unit::GetCreature(*m_creature, *itr));
            if (pCrystal && pCrystal->isAlive())
                pCrystal->DealDamage(pCrystal, pCrystal->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }
    }

    void Aggro(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
        {
            GameObject* EncounterDoor = GameObject::GetGameObject(*m_creature, pInstance->GetData64(DATA_SELIN_ENCOUNTER_DOOR));
            if (EncounterDoor)
                EncounterDoor->SetGoState(GO_STATE_READY);               //Close the encounter door, open it in JustDied/Reset
        }
    }

    void KilledUnit(Unit* victim)
    {
        switch(rand()%2)
        {
            case 0: DoScriptText(SAY_KILL_1, m_creature); break;
            case 1: DoScriptText(SAY_KILL_2, m_creature); break;
        }
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (type == POINT_MOTION_TYPE && id == 1)
        {
            Unit* CrystalChosen = Unit::GetUnit(*m_creature, CrystalGUID);
            if (CrystalChosen && CrystalChosen->isAlive())
            {
                // Make the crystal attackable
                // We also remove NON_ATTACKABLE in case the database has it set.
                CrystalChosen->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
                CrystalChosen->CastSpell(m_creature, SPELL_MANA_RAGE, true);
                IsDraining = true;
            }
            else
            {
                // Make an error message in case something weird happened here
                error_log("TSCR: Selin Fireheart unable to drain crystal as the crystal is either dead or despawned");
                DrainingCrystal = false;
            }
        }
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (!pInstance)
        {
            error_log(ERROR_INST_DATA);
            return;
        }

        pInstance->SetData(DATA_SELIN_EVENT, DONE);         // Encounter complete!

        GameObject* EncounterDoor = GameObject::GetGameObject((*m_creature), pInstance->GetData64(DATA_SELIN_ENCOUNTER_DOOR));
        if (EncounterDoor)
            EncounterDoor->SetGoState(GO_STATE_ACTIVE);                   // Open the encounter door

        GameObject* ContinueDoor = GameObject::GetGameObject(*m_creature, pInstance->GetData64(DATA_SELIN_DOOR));
        if (ContinueDoor)
            ContinueDoor->SetGoState(GO_STATE_ACTIVE);                    // Open the door leading further in

        ShatterRemainingCrystals();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (!DrainingCrystal)
        {
            uint32 maxPowerMana = m_creature->GetMaxPower(POWER_MANA);
            if (maxPowerMana && ((m_creature->GetPower(POWER_MANA)*100 / maxPowerMana) < 10))
            {
                if (DrainLifeTimer < diff)
                {
                    DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_DRAIN_LIFE);
                    DrainLifeTimer = 10000;
                }else DrainLifeTimer -= diff;

                // Heroic only
                if (Heroic)
                {
                    if (DrainManaTimer < diff)
                    {
                        DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_DRAIN_MANA);
                        DrainManaTimer = 10000;
                    }else DrainManaTimer -= diff;
                }
            }

            if (FelExplosionTimer < diff)
            {
                if (!m_creature->IsNonMeleeSpellCasted(false))
                {
                    DoCast(m_creature, SPELL_FEL_EXPLOSION);
                    FelExplosionTimer = 2000;
                }
            }else FelExplosionTimer -= diff;

            // If below 10% mana, start recharging
            maxPowerMana = m_creature->GetMaxPower(POWER_MANA);
            if (maxPowerMana && ((m_creature->GetPower(POWER_MANA)*100 / maxPowerMana) < 10))
            {
                if (DrainCrystalTimer < diff)
                {
                    SelectNearestCrystal();
                    if (Heroic) DrainCrystalTimer = 10000 + rand()%5000;
                    else        DrainCrystalTimer = 20000 + rand()%5000;
                }else DrainCrystalTimer -= diff;
            }

        }else
        {
            if (IsDraining)
            {
                if (EmpowerTimer < diff)
                {
                    IsDraining = false;
                    DrainingCrystal = false;

                    DoScriptText(SAY_EMPOWERED, m_creature);

                    Unit* CrystalChosen = Unit::GetUnit(*m_creature, CrystalGUID);
                    if (CrystalChosen && CrystalChosen->isAlive())
                        // Use Deal Damage to kill it, not setDeathState.
                        CrystalChosen->DealDamage(CrystalChosen, CrystalChosen->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);

                    CrystalGUID = 0;

                    m_creature->GetMotionMaster()->Clear();
                    m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
                }else EmpowerTimer -= diff;
            }
        }

        DoMeleeAttackIfReady();                             // No need to check if we are draining crystal here, as the spell has a stun.
    }
};

CreatureAI* GetAI_boss_selin_fireheart(Creature *_Creature)
{
    return new boss_selin_fireheartAI (_Creature);
};

struct TRINITY_DLL_DECL mob_fel_crystalAI : public ScriptedAI
{
    mob_fel_crystalAI(Creature *c) : ScriptedAI(c) {}

    void Reset() {}
    void Aggro(Unit* who) {}
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff) {}

    void JustDied(Unit* killer)
    {
        if (ScriptedInstance* pInstance = ((ScriptedInstance*)m_creature->GetInstanceData()))
        {
            Creature* Selin = (Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_SELIN)));
            if (Selin && Selin->isAlive())
            {
                if (((boss_selin_fireheartAI*)Selin->AI())->CrystalGUID == m_creature->GetGUID())
                {
                    // Set this to false if we are the creature that Selin is draining so his AI flows properly
                    ((boss_selin_fireheartAI*)Selin->AI())->DrainingCrystal = false;
                    ((boss_selin_fireheartAI*)Selin->AI())->IsDraining = false;
                    ((boss_selin_fireheartAI*)Selin->AI())->EmpowerTimer = 10000;
                    if (Selin->getVictim())
                    {
                        Selin->AI()->AttackStart(Selin->getVictim());
                        Selin->GetMotionMaster()->MoveChase(Selin->getVictim());
                    }
                }
            }
        }else error_log(ERROR_INST_DATA);
    }
};

CreatureAI* GetAI_mob_fel_crystal(Creature *_Creature)
{
    return new mob_fel_crystalAI (_Creature);
};

void AddSC_boss_selin_fireheart()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_selin_fireheart";
    newscript->GetAI = &GetAI_boss_selin_fireheart;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_fel_crystal";
    newscript->GetAI = &GetAI_mob_fel_crystal;
    newscript->RegisterSelf();
}

