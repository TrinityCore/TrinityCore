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
SDName: boss_grand_champions
SD%Complete: 92%
SDComment: missing yells. hunter AI sucks. no pvp diminuishing returns(is it DB related?)
SDCategory: Trial Of the Champion
EndScriptData */

#include "precompiled.h"
#include "trial_of_the_champion.h"

enum Spells
{
	//yells

	//warrior
	SPELL_MORTAL_STRIKE			= 68783,
	SPELL_MORTAL_STRIKE_H		= 68784,
	SPELL_BLADESTORM			= 63784,
	SPELL_INTERCEPT				= 67540,
	SPELL_ROLLING_THROW			= 47115, //need core support for spell 67546, using 47115 instead
	//mage
	SPELL_FIREBALL				= 66042,
	SPELL_FIREBALL_H			= 68310,
	SPELL_BLAST_WAVE			= 66044,
	SPELL_BLAST_WAVE_H			= 68312,
	SPELL_HASTE					= 66045,
	SPELL_POLYMORPH				= 66043,
	SPELL_POLYMORPH_H			= 68311,
	//shaman
	SPELL_CHAIN_LIGHTNING		= 67529,
	SPELL_CHAIN_LIGHTNING_H		= 68319,
	SPELL_EARTH_SHIELD			= 67530,
	SPELL_HEALING_WAVE			= 67528,
	SPELL_HEALING_WAVE_H		= 68318,
	SPELL_HEX_OF_MENDING		= 67534,
	//hunter
	SPELL_DISENGAGE				= 68340,
	SPELL_LIGHTNING_ARROWS		= 66083,
	SPELL_MULTI_SHOT			= 66081,
	SPELL_SHOOT					= 66079,
	//rogue
	SPELL_EVISCERATE			= 67709,
	SPELL_EVISCERATE_H			= 68317,
	SPELL_FAN_OF_KNIVES			= 67706,
	SPELL_POISON_BOTTLE			= 67701
};

// Warrior
struct TRINITY_DLL_DECL mob_toc5_warriorAI : public ScriptedAI
{
    mob_toc5_warriorAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		Reset();
		m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
	}

	ScriptedInstance* m_pInstance;

	uint32 Mortal_Strike_Timer;
	uint32 Bladestorm_Timer;
	uint32 Rolling_Throw_Timer;
	uint32 Intercept_Cooldown;
	uint32 intercept_check;

    void Reset()
    {
		m_creature->SetRespawnDelay(999999999);
		Mortal_Strike_Timer = 6000;
		Bladestorm_Timer = 20000;
		Rolling_Throw_Timer = 30000;
		Intercept_Cooldown = 0;
		intercept_check = 1000;
    }

	void EnterEvadeMode()
	{
	}

	void Aggro(Unit* pWho)
    {
		if (!m_pInstance)
			return;
		if (m_pInstance->GetData(TYPE_GRAND_CHAMPIONS) == DONE)
		    m_creature->ForcedDespawn();
		else
		    m_pInstance->SetData(TYPE_GRAND_CHAMPIONS, IN_PROGRESS);
    }

	void JustDied(Unit* pKiller)
        {
	    if (!m_pInstance)
		return;

            if(!m_creature->FindNearestCreature(35572, 200, true) && !m_creature->FindNearestCreature(35569, 200, true) && !m_creature->FindNearestCreature(35571, 200, true) && 
            !m_creature->FindNearestCreature(35570, 200, true) && !m_creature->FindNearestCreature(35617, 200, true) && !m_creature->FindNearestCreature(34705, 200, true)
            && !m_creature->FindNearestCreature(34702, 200, true) && !m_creature->FindNearestCreature(34701, 200, true) && !m_creature->FindNearestCreature(34657, 200, true)
            && !m_creature->FindNearestCreature(34703, 200, true))
                m_pInstance->SetData(TYPE_GRAND_CHAMPIONS, DONE);
	}

	void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectVictim() || !m_creature->getVictim())
            return;

		if (Mortal_Strike_Timer < diff)
        {
			DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_MORTAL_STRIKE, SPELL_MORTAL_STRIKE_H));
            Mortal_Strike_Timer = 6000;
        }else Mortal_Strike_Timer -= diff;  

		if (Rolling_Throw_Timer < diff)
        {
			DoCast(m_creature->getVictim(), SPELL_ROLLING_THROW);
            Rolling_Throw_Timer = 30000;
        }else Rolling_Throw_Timer -= diff;

		if (Bladestorm_Timer < diff)
        {
			DoCast(m_creature, SPELL_BLADESTORM);
            Bladestorm_Timer = 90000;
        }else Bladestorm_Timer -= diff;

		if (intercept_check < diff)
		{
			if (!m_creature->IsWithinDistInMap(m_creature->getVictim(), 8) && m_creature->IsWithinDistInMap(m_creature->getVictim(), 25) && Intercept_Cooldown < diff)
			{
				DoCast(m_creature->getVictim(), SPELL_INTERCEPT);
				Intercept_Cooldown = 15000;
			}
			intercept_check = 1000;
		}
		else 
		{
			intercept_check -= diff;
			Intercept_Cooldown -= diff;
		}
		
		DoMeleeAttackIfReady();
	}
};

CreatureAI* GetAI_mob_toc5_warrior(Creature* pCreature)
{
    return new mob_toc5_warriorAI(pCreature);
}

// Mage
struct TRINITY_DLL_DECL mob_toc5_mageAI : public ScriptedAI
{
    mob_toc5_mageAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		Reset();
		m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
	}

	ScriptedInstance* m_pInstance;

	uint32 Fireball_Timer;
	uint32 Blast_Wave_Timer;
	uint32 Haste_Timer;
	uint32 Polymorph_Timer;

    void Reset()
    {
		m_creature->SetRespawnDelay(999999999);
		Fireball_Timer = 0;
		Blast_Wave_Timer = 20000;
		Haste_Timer = 9000;
		Polymorph_Timer = 15000;
    }

	void EnterEvadeMode()
	{
	}

	void Aggro(Unit* pWho)
    {
		if (!m_pInstance)
			return;
		if (m_pInstance->GetData(TYPE_GRAND_CHAMPIONS) == DONE)
		    m_creature->ForcedDespawn();
		else
		    m_pInstance->SetData(TYPE_GRAND_CHAMPIONS, IN_PROGRESS);
    }

	void JustDied(Unit* pKiller)
        {
	    if (!m_pInstance)
		return;

            if(!m_creature->FindNearestCreature(35572, 200, true) && !m_creature->FindNearestCreature(35569, 200, true) && !m_creature->FindNearestCreature(35571, 200, true) && 
            !m_creature->FindNearestCreature(35570, 200, true) && !m_creature->FindNearestCreature(35617, 200, true) && !m_creature->FindNearestCreature(34705, 200, true)
            && !m_creature->FindNearestCreature(34702, 200, true) && !m_creature->FindNearestCreature(34701, 200, true) && !m_creature->FindNearestCreature(34657, 200, true)
            && !m_creature->FindNearestCreature(34703, 200, true))
                m_pInstance->SetData(TYPE_GRAND_CHAMPIONS, DONE);
	}

	void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectVictim() || !m_creature->getVictim())
            return;

		if (Fireball_Timer < diff)
        {
            DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_FIREBALL, SPELL_FIREBALL_H));
            Fireball_Timer = 3000;
        }else Fireball_Timer -= diff;  

		if (Blast_Wave_Timer < diff)
        {
			DoCast(m_creature, DUNGEON_MODE(SPELL_BLAST_WAVE, SPELL_BLAST_WAVE_H));
            Blast_Wave_Timer = 20000;
        }else Blast_Wave_Timer -= diff;

		if (Haste_Timer < diff)
        {
			DoCast(m_creature, SPELL_HASTE);
            Haste_Timer = 10000;
        }else Haste_Timer -= diff;

		if (Polymorph_Timer < diff)
        {
			if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,1))
                DoCast(target, DUNGEON_MODE(SPELL_POLYMORPH, SPELL_POLYMORPH_H));
            Polymorph_Timer = 15000;
        }else Polymorph_Timer -= diff;
		
		DoMeleeAttackIfReady();
	}
};

CreatureAI* GetAI_mob_toc5_mage(Creature* pCreature)
{
    return new mob_toc5_mageAI(pCreature);
}

// Shaman
struct TRINITY_DLL_DECL mob_toc5_shamanAI : public ScriptedAI
{
    mob_toc5_shamanAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		Reset();
		m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
	}

	ScriptedInstance* m_pInstance;

	uint32 Chain_Lightning_Timer;
	uint32 Earth_Shield_Timer;
	uint32 Healing_Wave_Timer;
	uint32 Hex_Timer;

	float mob1_health;
	float mob2_health;
	float mob3_health;

    void Reset()
    {
		m_creature->SetRespawnDelay(999999999);
		Chain_Lightning_Timer = 1000;
		Earth_Shield_Timer = 5000;
		Healing_Wave_Timer = 13000;
		Hex_Timer = 10000;
    }

	void EnterEvadeMode()
	{
	}

	void Aggro(Unit* pWho)
    {
		if (!m_pInstance)
			return;
		if (m_pInstance->GetData(TYPE_GRAND_CHAMPIONS) == DONE)
	            m_creature->ForcedDespawn();
		else
		    m_pInstance->SetData(TYPE_GRAND_CHAMPIONS, IN_PROGRESS);
    }

	void JustDied(Unit* pKiller)
        {
	    if (!m_pInstance)
		return;

            if(!m_creature->FindNearestCreature(35572, 200, true) && !m_creature->FindNearestCreature(35569, 200, true) && !m_creature->FindNearestCreature(35571, 200, true) && 
            !m_creature->FindNearestCreature(35570, 200, true) && !m_creature->FindNearestCreature(35617, 200, true) && !m_creature->FindNearestCreature(34705, 200, true)
            && !m_creature->FindNearestCreature(34702, 200, true) && !m_creature->FindNearestCreature(34701, 200, true) && !m_creature->FindNearestCreature(34657, 200, true)
            && !m_creature->FindNearestCreature(34703, 200, true))
                m_pInstance->SetData(TYPE_GRAND_CHAMPIONS, DONE);
	}

	void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectVictim() || !m_creature->getVictim())
            return;

		if (Chain_Lightning_Timer < diff)
        {
			DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_CHAIN_LIGHTNING, SPELL_CHAIN_LIGHTNING_H));
            Chain_Lightning_Timer = 10000;
        }else Chain_Lightning_Timer -= diff;  

		if (Hex_Timer < diff)
        {
			DoCast(m_creature->getVictim(), SPELL_HEX_OF_MENDING);
            Hex_Timer = 20000;
        }else Hex_Timer -= diff;

	if (Healing_Wave_Timer < diff)
        {
            if(Unit* target = m_creature->SelectNearestTarget(40))
                if(target->GetHealth() == target->GetHealth() * 100 / target->GetMaxHealth() && target->IsFriendlyTo(m_creature))
                {
                    DoCast(target, DUNGEON_MODE(SPELL_HEALING_WAVE, SPELL_HEALING_WAVE_H));
                    Healing_Wave_Timer = 8000;
                }
        }else Healing_Wave_Timer -= diff;

	if (Earth_Shield_Timer < diff)
        {
            if(Unit* target = m_creature->SelectNearestTarget(40))
                if(!target->HasAura(SPELL_EARTH_SHIELD,m_creature->GetGUID()) && target->IsFriendlyTo(m_creature))
                {
                    DoCast(target, SPELL_EARTH_SHIELD);
                    Earth_Shield_Timer = 25000;
                }
        }else Earth_Shield_Timer -= diff;
		
		DoMeleeAttackIfReady();
	}
};

CreatureAI* GetAI_mob_toc5_shaman(Creature* pCreature)
{
    return new mob_toc5_shamanAI(pCreature);
}

// Hunter
struct TRINITY_DLL_DECL mob_toc5_hunterAI : public ScriptedAI
{
    mob_toc5_hunterAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		Reset();
		m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
	}

	ScriptedInstance* m_pInstance;

    uint32 Shoot_Timer;
	uint32 Lightning_Arrows_Timer;
	uint32 Multi_Shot_Timer;
	uint32 Disengage_Cooldown;
	uint32 enemy_check;
	uint32 disengage_check;

    void Reset()
    {
		m_creature->SetRespawnDelay(999999999);
		Shoot_Timer = 0;
		Lightning_Arrows_Timer = 13000;
		Multi_Shot_Timer = 10000;
		Disengage_Cooldown = 0;
		enemy_check = 1000;
		disengage_check;
    }

	void EnterEvadeMode()
	{
	}

	void Aggro(Unit* pWho)
    {
		if (!m_pInstance)
			return;
		if (m_pInstance->GetData(TYPE_GRAND_CHAMPIONS) == DONE)
		    m_creature->ForcedDespawn();
		else
		    m_pInstance->SetData(TYPE_GRAND_CHAMPIONS, IN_PROGRESS);
    }

	void JustDied(Unit* pKiller)
        {
	    if (!m_pInstance)
		return;

            if(!m_creature->FindNearestCreature(35572, 200, true) && !m_creature->FindNearestCreature(35569, 200, true) && !m_creature->FindNearestCreature(35571, 200, true) && 
            !m_creature->FindNearestCreature(35570, 200, true) && !m_creature->FindNearestCreature(35617, 200, true) && !m_creature->FindNearestCreature(34705, 200, true)
            && !m_creature->FindNearestCreature(34702, 200, true) && !m_creature->FindNearestCreature(34701, 200, true) && !m_creature->FindNearestCreature(34657, 200, true)
            && !m_creature->FindNearestCreature(34703, 200, true))
                m_pInstance->SetData(TYPE_GRAND_CHAMPIONS, DONE);
	}

	void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectVictim() || !m_creature->getVictim())
            return;

		if (enemy_check < diff)
		{
			if (!m_creature->IsWithinDistInMap(m_creature->getVictim(), 8) && m_creature->IsWithinDistInMap(m_creature->getVictim(), 30))
			{
				m_creature->SetSpeed(MOVE_RUN, 0.0001);
			}
			else
			{
				m_creature->SetSpeed(MOVE_RUN, 1);
			}
			enemy_check = 100;
		}else enemy_check -= diff;

		if (Disengage_Cooldown>0)
			Disengage_Cooldown -= diff;

		if (Shoot_Timer < diff)
        {
			DoCast(m_creature->getVictim(), SPELL_SHOOT);
            Shoot_Timer = 3000;
        }else Shoot_Timer -= diff;  

		if (Multi_Shot_Timer < diff)
        {
			m_creature->CastStop(SPELL_SHOOT);
			DoCast(m_creature->getVictim(), SPELL_MULTI_SHOT);
            Multi_Shot_Timer = 10000;
        }else Multi_Shot_Timer -= diff;

		if (Lightning_Arrows_Timer < diff)
        {
			m_creature->CastStop(SPELL_SHOOT);
			DoCast(m_creature, SPELL_LIGHTNING_ARROWS);
            Lightning_Arrows_Timer = 25000;
        }else Lightning_Arrows_Timer -= diff;

		if (disengage_check < diff)
		{
			if (m_creature->IsWithinDistInMap(m_creature->getVictim(), 5) && Disengage_Cooldown == 0)
			{
				DoCast(m_creature, SPELL_DISENGAGE);
				Disengage_Cooldown = 15000;
			}
			disengage_check = 1000;
		}else disengage_check -= diff;
		
		DoMeleeAttackIfReady();
	}
};

CreatureAI* GetAI_mob_toc5_hunter(Creature* pCreature)
{
    return new mob_toc5_hunterAI(pCreature);
}

// Rogue
struct TRINITY_DLL_DECL mob_toc5_rogueAI : public ScriptedAI
{
    mob_toc5_rogueAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		Reset();
		m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
	}

	ScriptedInstance* m_pInstance;

	uint32 Eviscerate_Timer;
	uint32 FoK_Timer;
	uint32 Poison_Timer;

    void Reset()
    {
		m_creature->SetRespawnDelay(999999999);
		Eviscerate_Timer = 15000;
		FoK_Timer = 10000;
		Poison_Timer = 7000;
    }

	void EnterEvadeMode()
	{
	}

	void Aggro(Unit* pWho)
    {
		if (!m_pInstance)
			return;
		if (m_pInstance->GetData(TYPE_GRAND_CHAMPIONS) == DONE)
		    m_creature->ForcedDespawn();
		else
		    m_pInstance->SetData(TYPE_GRAND_CHAMPIONS, IN_PROGRESS);
    }

	void JustDied(Unit* pKiller)
        {
	    if (!m_pInstance)
		return;

            if(!m_creature->FindNearestCreature(35572, 200, true) && !m_creature->FindNearestCreature(35569, 200, true) && !m_creature->FindNearestCreature(35571, 200, true) && 
            !m_creature->FindNearestCreature(35570, 200, true) && !m_creature->FindNearestCreature(35617, 200, true) && !m_creature->FindNearestCreature(34705, 200, true)
            && !m_creature->FindNearestCreature(34702, 200, true) && !m_creature->FindNearestCreature(34701, 200, true) && !m_creature->FindNearestCreature(34657, 200, true)
            && !m_creature->FindNearestCreature(34703, 200, true))
                m_pInstance->SetData(TYPE_GRAND_CHAMPIONS, DONE);
	}

	void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectVictim() || !m_creature->getVictim())
            return;

		if (Eviscerate_Timer < diff)
        {
			DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_EVISCERATE, SPELL_EVISCERATE_H));
            Eviscerate_Timer = 10000;
        }else Eviscerate_Timer -= diff;  

		if (FoK_Timer < diff)
        {
			DoCast(m_creature->getVictim(), SPELL_FAN_OF_KNIVES);
			FoK_Timer = 7000;
        }else FoK_Timer -= diff;

		if (Poison_Timer < diff)
        {
			if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
				DoCast(m_creature, SPELL_POISON_BOTTLE);
            Poison_Timer = 6000;
        }else Poison_Timer -= diff;
		
		DoMeleeAttackIfReady();
	}
};

CreatureAI* GetAI_mob_toc5_rogue(Creature* pCreature)
{
    return new mob_toc5_rogueAI(pCreature);
}

void AddSC_boss_grand_champions()
{
    Script* NewScript;

    NewScript = new Script;
    NewScript->Name = "mob_toc5_warrior";
	NewScript->GetAI = &GetAI_mob_toc5_warrior;
    NewScript->RegisterSelf();

	NewScript = new Script;
    NewScript->Name = "mob_toc5_mage";
	NewScript->GetAI = &GetAI_mob_toc5_mage;
    NewScript->RegisterSelf();

	NewScript = new Script;
    NewScript->Name = "mob_toc5_shaman";
	NewScript->GetAI = &GetAI_mob_toc5_shaman;
    NewScript->RegisterSelf();

	NewScript = new Script;
    NewScript->Name = "mob_toc5_hunter";
	NewScript->GetAI = &GetAI_mob_toc5_hunter;
    NewScript->RegisterSelf();

	NewScript = new Script;
    NewScript->Name = "mob_toc5_rogue";
	NewScript->GetAI = &GetAI_mob_toc5_rogue;
    NewScript->RegisterSelf();
}
