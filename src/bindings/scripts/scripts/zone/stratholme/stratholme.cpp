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
SDName: Stratholme
SD%Complete: 100
SDComment: trash mobs for strat. Simple AI mobs converted to EAI (except Mindless Skeleton and Thuzadin Acolyte)
SDCategory: Stratholme
EndScriptData */

#include "precompiled.h"
#include "../../creature/simple_ai.h"

/*######
## mob_freed_soul
######*/

//Possibly more of these quotes around.
#define SAY_ZAPPED0 "Thanks to Egan"
#define SAY_ZAPPED1 "Rivendare must die"
#define SAY_ZAPPED2 "Who you gonna call?"
#define SAY_ZAPPED3 "Don't cross those beams!"

struct MANGOS_DLL_DECL mob_freed_soulAI : public ScriptedAI
{
    mob_freed_soulAI(Creature *c) : ScriptedAI(c) {Reset();}

    void Reset()
    {

        switch (rand()%4)
        {
        case 0:
            DoSay(SAY_ZAPPED0,LANG_UNIVERSAL,NULL);
            break;
        case 1:
            DoSay(SAY_ZAPPED1,LANG_UNIVERSAL,NULL);
            break;
        case 2:
            DoSay(SAY_ZAPPED2,LANG_UNIVERSAL,NULL);
            break;
        case 3:
            DoSay(SAY_ZAPPED3,LANG_UNIVERSAL,NULL);
            break;
        }
    }

    void Aggro(Unit* who)
    {
    }
};
CreatureAI* GetAI_mob_freed_soul(Creature *_Creature)
{
    return new mob_freed_soulAI (_Creature);
}
/*######
## mob_restless_soul
######*/

struct MANGOS_DLL_DECL mob_restless_soulAI : public ScriptedAI
{
    mob_restless_soulAI(Creature *c) : ScriptedAI(c) {Reset();}

    Unit* PlayerHolder;
    uint32 Die_Timer;
    bool OkToDie;

    void Reset()
    {
        Die_Timer = 10000;
        OkToDie = false;

        PlayerHolder = NULL;
    }

    void Aggro(Unit* who)
    {
    }

    void SummonFreedSoul(Unit* victim)
    {
        int Rand;
        int RandX;
        int RandY;

        Rand = rand()%1;
        switch (rand()%2)
        {
        case 0: RandX = 0 - Rand; break;
        case 1: RandX = 0 + Rand; break;
        }
        Rand = 0;
        Rand = rand()%1;
        switch (rand()%2)
        {
        case 0: RandY = 0 - Rand; break;
        case 1: RandY = 0 + Rand; break;
        }
        Rand = 0;
        DoSpawnCreature(11136, RandX, RandY, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 300000);
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if (caster->GetTypeId() == TYPEID_PLAYER)
        {
            if(!PlayerHolder && !OkToDie && spell->Id == 17368 && ((Player*)caster)->GetQuestStatus(5282) == QUEST_STATUS_INCOMPLETE)
            {
                PlayerHolder = caster;
                OkToDie = true;
                Die_Timer = 5000;
            }
        }
        return;
    }

    void JustDied(Unit* Killer)
    {
        if (Killer->GetTypeId() == TYPEID_PLAYER)
        {
            //check quest status
            if(PlayerHolder == ((Player*)Killer) && ((Player*)Killer)->GetQuestStatus(5282) == QUEST_STATUS_INCOMPLETE)
            {
                SummonFreedSoul(m_creature->getVictim());
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (PlayerHolder && OkToDie && Die_Timer < diff)
        {
            PlayerHolder->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }
        else Die_Timer -= diff;

        return;
    }
};
CreatureAI* GetAI_mob_restless_soul(Creature *_Creature)
{
    return new mob_restless_soulAI (_Creature);
}

/*######
## mobs_spectral_ghostly_citizen
######*/

struct MANGOS_DLL_DECL mobs_spectral_ghostly_citizenAI : public ScriptedAI
{
    mobs_spectral_ghostly_citizenAI(Creature *c) : ScriptedAI(c) {Reset();}

    Unit* PlayerHolder;
    uint32 Die_Timer;
    bool OkToDie;

    void Reset()
    {
        Die_Timer = 5000;
        OkToDie = false;
        PlayerHolder = NULL;
    }

    void Aggro(Unit* who)
    {
    }

    void SummonRestlessSoul(Unit* victim)
    {
        int Rand;
        int RandX;
        int RandY;

        Rand = rand()%7;
        switch (rand()%2)
        {
        case 0: RandX = 0 - Rand; break;
        case 1: RandX = 0 + Rand; break;
        }
        Rand = 0;
        Rand = rand()%7;
        switch (rand()%2)
        {
        case 0: RandY = 0 - Rand; break;
        case 1: RandY = 0 + Rand; break;
        }
        Rand = 0;
        DoSpawnCreature(11122, RandX, RandY, 0, 0, TEMPSUMMON_CORPSE_DESPAWN, 600000);
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if (caster->GetTypeId() == TYPEID_PLAYER)
        {
            if(!PlayerHolder && !OkToDie && spell->Id == 17368 && ((Player*)caster)->GetQuestStatus(5282) == QUEST_STATUS_INCOMPLETE)
            {
                PlayerHolder = caster;
                OkToDie = true;
                Die_Timer = 5000;
            }
        }
        return;
    }

    void JustDied(Unit* Killer)
    {
        if (Killer->GetTypeId() == TYPEID_PLAYER)
        {
            //check quest status
            if(PlayerHolder == ((Player*)Killer) && ((Player*)Killer)->GetQuestStatus(5282) == QUEST_STATUS_INCOMPLETE)
            {
                SummonRestlessSoul(m_creature->getVictim());                        //always one
                if (rand()%100 < 90) SummonRestlessSoul(m_creature->getVictim());   //90% a second
                if (rand()%100 < 50) SummonRestlessSoul(m_creature->getVictim());   //50% a third
                if (rand()%100 < 30) SummonRestlessSoul(m_creature->getVictim());   //30% a fourth
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (PlayerHolder && OkToDie && Die_Timer < diff)
        {
            PlayerHolder->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }
        else Die_Timer -= diff;

        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_mobs_spectral_ghostly_citizen(Creature *_Creature)
{
    return new mobs_spectral_ghostly_citizenAI (_Creature);
}
bool ReciveEmote_mobs_spectral_ghostly_citizen(Player *player, Creature *_Creature, uint32 emote)
{
    _Creature->HandleEmoteCommand(emote);

    if (emote == TEXTEMOTE_DANCE)
        ((mobs_spectral_ghostly_citizenAI*)_Creature->AI())->EnterEvadeMode();

    return true;
}

/*######
## mob_mindless_skeleton
######*/

CreatureAI* GetAI_mob_mindless_skeleton(Creature *_Creature)
{
    SimpleAI* ai = new SimpleAI (_Creature);

    //dazed
    ai->Spell[0].Enabled = true;
    ai->Spell[0].Spell_Id = 13496;
    ai->Spell[0].Cooldown = 15000; 
    ai->Spell[0].First_Cast = 3000;
    ai->Spell[0].Cast_Target_Type = CAST_HOSTILE_TARGET;

    ai->EnterEvadeMode();

    return ai;
}

/*######
## mob_thuzadin_acolyte
######*/

CreatureAI* GetAI_mob_thuzadin_acolyte(Creature *_Creature)
{
    SimpleAI* ai = new SimpleAI (_Creature);

    //dazed
    ai->Spell[0].Enabled = true;
    ai->Spell[0].Spell_Id = 13496;
    ai->Spell[0].Cooldown = 15000; 
    ai->Spell[0].First_Cast = 1000;
    ai->Spell[0].Cast_Target_Type = CAST_HOSTILE_TARGET;

    ai->EnterEvadeMode();

    return ai;
}

/*######
## 
######*/

void AddSC_stratholme()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="mob_freed_soul";
    newscript->GetAI = GetAI_mob_freed_soul;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_restless_soul";
    newscript->GetAI = GetAI_mob_restless_soul;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mobs_spectral_ghostly_citizen";
    newscript->GetAI = GetAI_mobs_spectral_ghostly_citizen;
    newscript->pReceiveEmote = &ReciveEmote_mobs_spectral_ghostly_citizen;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_mindless_skeleton";
    newscript->GetAI = GetAI_mob_mindless_skeleton;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_thuzadin_acolyte";
    newscript->GetAI = GetAI_mob_thuzadin_acolyte;
    m_scripts[nrscripts++] = newscript;
}
