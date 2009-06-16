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
SDName: Boss_Priestess_Delrissa
SD%Complete: 45
SDComment: No Heroic support yet. Needs further testing. Several scripts for pets disabled, not seem to require any special script.
SDCategory: Magister's Terrace
EndScriptData */

#include "precompiled.h"
#include "def_magisters_terrace.h"

struct Speech
{
    int32 id;
};

static Speech LackeyDeath[]=
{
    {-1585013},
    {-1585014},
    {-1585015},
    {-1585016},
};

static Speech PlayerDeath[]=
{
    {-1585017},
    {-1585018},
    {-1585019},
    {-1585020},
    {-1585021},
};

#define SAY_AGGRO               -1585012
#define SAY_DEATH               -1585022

#define SPELL_DISPEL_MAGIC      27609
#define SPELL_FLASH_HEAL        17843
#define SPELL_SW_PAIN_NORMAL    14032
#define SPELL_SW_PAIN_HEROIC    15654
#define SPELL_SHIELD            44291
#define SPELL_RENEW_NORMAL      44174
#define SPELL_RENEW_HEROIC      46192

#define ORIENT                  4.98
#define POS_Z                   -19.9215

float LackeyLocations[4][2]=
{
    {123.77, 17.6007},
    {131.731, 15.0827},
    {121.563, 15.6213},
    {129.988, 17.2355},
};

const uint32 AddEntry[8]=
{
    24557,                                                  //Kagani Nightstrike
    24558,                                                  //Elris Duskhallow
    24554,                                                  //Eramas Brightblaze
    24561,                                                  //Yazzaj
    24559,                                                  //Warlord Salaris
    24555,                                                  //Garaxxas
    24553,                                                  //Apoko
    24556,                                                  //Zelfan
};

struct Add
{
    Add(uint32 _entry, uint64 _guid)
    {
        entry = _entry;
        guid  = _guid;
    }

    uint32 entry;
    uint64 guid;
};

struct TRINITY_DLL_DECL boss_priestess_delrissaAI : public ScriptedAI
{
    boss_priestess_delrissaAI(Creature* c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        Heroic = c->GetMap()->IsHeroic();
    }

    ScriptedInstance* pInstance;

    std::vector<Add*> Adds;

    uint8 LackeysKilled;
    uint8 PlayersKilled;

    uint32 HealTimer;
    uint32 RenewTimer;
    uint32 ShieldTimer;
    uint32 SWPainTimer;
    uint32 DispelTimer;
    uint32 ResetTimer;

    uint32 CombatPulseTimer;                                // Periodically puts all players in the instance in combat

    bool Heroic;

    void Reset()
    {
        LackeysKilled = 0;
        PlayersKilled = 0;

        HealTimer   = 15000;
        RenewTimer  = 10000;
        ShieldTimer = 2000;
        SWPainTimer = 5000;
        DispelTimer = 7500;
        ResetTimer = 5000;

        CombatPulseTimer  = 5000;

        SummonAdds();
        CheckAdds();

        if (pInstance)
        {
            pInstance->SetData(DATA_DELRISSA_EVENT, NOT_STARTED);
            pInstance->SetData(DATA_DELRISSA_DEATH_COUNT, 0);
        } else error_log(ERROR_INST_DATA);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        for(uint8 i = 0; i < Adds.size(); ++i)
            if(Unit* pAdd = Unit::GetUnit(*m_creature, Adds[i]->guid))
                pAdd->AddThreat(who, 1.0f);
    }

    void SummonAdds()
    {
        if(!Adds.empty())
            return;

        std::vector<uint32> AddList;
        for(uint8 i = 0; i < 8; ++i)
            AddList.push_back(AddEntry[i]);

        while(AddList.size() > 4)
            AddList.erase(AddList.begin() + rand()%AddList.size());

        for(uint8 i = 0; i < AddList.size(); ++i)
        {
            Creature* pAdd = m_creature->SummonCreature(AddList[i], LackeyLocations[i][0], LackeyLocations[i][1], POS_Z, ORIENT, TEMPSUMMON_DEAD_DESPAWN, 0);
            if (pAdd)
            {
                Add* nAdd = new Add(AddList[i], pAdd->GetGUID());
                Adds.push_back(nAdd);
            }
        }
    }

    void CheckAdds()
    {
        if (Adds.empty())
            return;

        uint32 n = 0;
        for(std::vector<Add*>::iterator i = Adds.begin(); i != Adds.end(); ++i, ++n)
        {
            Creature* pAdd = (Unit::GetCreature(*m_creature, (*i)->guid));
            if(pAdd && pAdd->isAlive())
            {
                pAdd->AI()->EnterEvadeMode();               // Force them out of combat and reset if they are in combat.
            }
            else
            {
                pAdd = m_creature->SummonCreature((*i)->entry, LackeyLocations[n][0], LackeyLocations[n][1], POS_Z, ORIENT, TEMPSUMMON_DEAD_DESPAWN, 0);
                if(pAdd)
                    (*i)->guid = pAdd->GetGUID();
                else
                    (*i)->guid = 0;
            }
        }
    }

    void KilledUnit(Unit* victim)
    {
        if (victim->GetTypeId() != TYPEID_PLAYER)
            return;

        DoScriptText(PlayerDeath[PlayersKilled].id, m_creature);

        if (PlayersKilled < 4)
            ++PlayersKilled;
    }

    void KilledLackey()
    {
        DoScriptText(LackeyDeath[LackeysKilled].id, m_creature);

        if (LackeysKilled < 3)
            ++LackeysKilled;
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        CheckLootable();

        if (!pInstance)
        {
            error_log(ERROR_INST_DATA);
            return;
        }

        pInstance->SetData(DATA_DELRISSA_EVENT, DONE);

        if (GameObject* Door = GameObject::GetGameObject(*m_creature, pInstance->GetData64(DATA_DELRISSA_DOOR)))
            Door->SetGoState(GO_STATE_ACTIVE);
    }

    void CheckLootable()
    {
        if (LackeysKilled > 3)
            m_creature->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        else
            m_creature->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if(ResetTimer < diff)
        {
            float x, y, z, o;
            m_creature->GetHomePosition(x, y, z, o);
            if(m_creature->GetPositionZ() >= z+10)
            {
                EnterEvadeMode();
                return;
            }
            ResetTimer = 5000;
        }else ResetTimer -= diff;

        if (HealTimer < diff)
        {
            uint32 health = m_creature->GetHealth();
            Unit* target = m_creature;
            for(uint8 i = 0; i < Adds.size(); ++i)
                if (Unit* pAdd = Unit::GetUnit(*m_creature, Adds[i]->guid))
                    if (pAdd->isAlive() && pAdd->GetHealth() < health)
                        target = pAdd;

            DoCast(target, SPELL_FLASH_HEAL);
            HealTimer = 15000;
        }else HealTimer -= diff;

        if (RenewTimer < diff)
        {
            Unit* target = m_creature;
            if (rand()%2 == 1)
            {
                std::vector<Add*>::iterator itr = Adds.begin() + rand()%Adds.size();
                Unit* pAdd = Unit::GetUnit(*m_creature, (*itr)->guid);
                if (pAdd && pAdd->isAlive())
                    target = pAdd;
            }
            DoCast(target,Heroic ? SPELL_RENEW_HEROIC : SPELL_RENEW_NORMAL);
            RenewTimer = 5000;
        }else RenewTimer -= diff;

        if(ShieldTimer < diff)
        {
            Unit* target = m_creature;
            if (rand()%2 == 1)
            {
                std::vector<Add*>::iterator itr = Adds.begin() + rand()%Adds.size();
                if (Unit* pAdd = Unit::GetUnit(*m_creature, (*itr)->guid))
                    if (!pAdd->HasAura(SPELL_SHIELD) && pAdd->isAlive())
                        target = pAdd;
            }
            DoCast(target, SPELL_SHIELD);
            ShieldTimer = 7500;
        }else ShieldTimer -= diff;

        if (DispelTimer < diff)
        {
            Unit* target = NULL;
            bool friendly = false;
            if (rand()%2 == 1)
                target = SelectUnit(SELECT_TARGET_RANDOM, 0);
            else
            {
                friendly = true;
                if (rand()%2 == 1)
                    target = m_creature;
                else
                {
                    std::vector<Add*>::iterator itr = Adds.begin() + rand()%Adds.size();
                    Unit* pAdd = Unit::GetUnit(*m_creature, (*itr)->guid);
                    if (pAdd && pAdd->isAlive())
                        target = pAdd;
                }
            }
            if (target)
            {
                DoCast(target, SPELL_DISPEL_MAGIC);
                DispelTimer = 12000;
            }
        }else DispelTimer -= diff;

        if (SWPainTimer < diff)
        {
            DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0),Heroic ? SPELL_SW_PAIN_HEROIC : SPELL_SW_PAIN_NORMAL);
            SWPainTimer = 10000;
        }else SWPainTimer -= diff;

        /*
        if(CombatPulseTimer < diff)
        {
            DoZoneInCombat();
            for(uint8 i = 0; i < Adds.size(); ++i)
            {
                if(Unit* pAdd = Unit::GetUnit(*m_creature, Add[i]->guid))
                    if(pAdd->isAlive())
                        DoZoneInCombat(pAdd);
            }

            CombatPulseTimer = 10000;
        }else CombatPulseTimer -= diff;*/

        DoMeleeAttackIfReady();
    }
};

#define SPELL_HEALING_POTION    15503

struct TRINITY_DLL_DECL boss_priestess_guestAI : public ScriptedAI
{
    boss_priestess_guestAI(Creature* c) : ScriptedAI(c)
    {
        Group.clear();
        pInstance = c->GetInstanceData();
        AcquireGUIDs();
    }

    ScriptedInstance* pInstance;

    std::vector<Add*> Group;

    uint32 ResetThreatTimer;

    bool UsedPotion;

    void Reset()
    {
        UsedPotion = false;

        ResetThreatTimer = 5000 + rand()%15000;             // These guys like to switch targets often, and are not meant to be tanked.
    }

    void EnterCombat(Unit* who) {}

    void JustDied(Unit* killer)
    {
        if (!pInstance)
        {
            error_log(ERROR_INST_DATA);
            return;
        }

        Creature* Delrissa = (Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_DELRISSA)));
        if (Delrissa)
        {
            pInstance->SetData(DATA_DELRISSA_DEATH_COUNT, 1);

            CAST_AI(boss_priestess_delrissaAI, Delrissa->AI())->KilledLackey();

            if (!Delrissa->isAlive() && pInstance->GetData(DATA_DELRISSA_DEATH_COUNT) > 3)
                Delrissa->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        }
    }

    void KilledUnit(Unit* victim)
    {
        if (!pInstance)
        {
            error_log(ERROR_INST_DATA);
            return;
        }

        Creature* Delrissa = (Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_DELRISSA)));
        if (Delrissa)
            Delrissa->AI()->KilledUnit(victim);
    }

    void AcquireGUIDs()
    {
        if (!pInstance)
        {
            error_log(ERROR_INST_DATA);
            return;
        }

        Creature* Delrissa = (Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_DELRISSA)));
        if (Delrissa)
        {
            Group = CAST_AI(boss_priestess_delrissaAI, Delrissa->AI())->Adds;
            Add* dAdd = new Add(Delrissa->GetEntry(), Delrissa->GetGUID());
            Group.push_back(dAdd);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 25) && !UsedPotion)
        {
            DoCast(m_creature, SPELL_HEALING_POTION, true);
            UsedPotion = true;
        }

        if (ResetThreatTimer < diff)
        {
            DoResetThreat();
            ResetThreatTimer = 5000 + rand()%15000;
        }else ResetThreatTimer -= diff;
    }
};

#define SPELL_KIDNEY_SHOT        27615
#define SPELL_GOUGE              12540
#define SPELL_KICK               27613
#define SPELL_VANISH             44290
#define SPELL_BACKSTAB           15657
#define SPELL_EVISCERATE         27611

struct TRINITY_DLL_DECL boss_kagani_nightstrikeAI : public boss_priestess_guestAI
{
    //Rogue
    boss_kagani_nightstrikeAI(Creature *c) : boss_priestess_guestAI(c) {}

    uint32 Gouge_Timer;
    uint32 Kick_Timer;
    uint32 Vanish_Timer;
    uint32 Eviscerate_Timer;
    uint32 Wait_Timer;
    bool InVanish;

    void Reset()
    {
        Gouge_Timer = 5500;
        Kick_Timer = 7000;
        Vanish_Timer = 2000;
        Eviscerate_Timer = 6000;
        Wait_Timer = 5000;
        InVanish = false;
        m_creature->SetVisibility(VISIBILITY_ON);

        boss_priestess_guestAI::Reset();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        boss_priestess_guestAI::UpdateAI(diff);

        if (Vanish_Timer < diff)
        {
            m_creature->SetVisibility(VISIBILITY_OFF);      // ...? Hacklike
            DoCast(m_creature, SPELL_VANISH);
            InVanish = true;
            Vanish_Timer = 30000;
            Wait_Timer = 10000;
            DoResetThreat();
            m_creature->AddThreat(SelectUnit(SELECT_TARGET_RANDOM, 0), 1000.0f);
        }else Vanish_Timer -= diff;

        if (InVanish)
        {
            if (Wait_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_BACKSTAB, true);
                DoCast(m_creature->getVictim(), SPELL_KIDNEY_SHOT, true);
                m_creature->SetVisibility(VISIBILITY_ON);       // ...? Hacklike
                InVanish = false;
            }else Wait_Timer -= diff;
        }

        if (Gouge_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_GOUGE);
            Gouge_Timer = 5500;
        }else Gouge_Timer -= diff;

        if (Kick_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_KICK);
            Kick_Timer = 7000;
        }else Kick_Timer -= diff;

        if (Eviscerate_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_EVISCERATE);
            Eviscerate_Timer = 4000;
        }else Eviscerate_Timer -= diff;

        if (!InVanish)
            DoMeleeAttackIfReady();
    }
};

#define SPELL_IMMOLATE               44267
#define SPELL_SHADOW_BOLT            12471
#define SPELL_SEED_OF_CORRUPTION     44141
#define SPELL_CURSE_OF_AGONY         14875
#define SPELL_FEAR                   38595
#define SPELL_IMP_FIREBALL           44164
#define SPELL_SUMMON_IMP             44163

//#define CREATURE_IMP                 44163
//#define CREATURE_FIZZLE              24656

/*struct TRINITY_DLL_DECL mob_fizzleAI : public ScriptedAI
{
    mob_fizzleAI(Creature *c) : ScriptedAI(c) {}

    uint64 EllrisGUID;
    uint32 Firebal_Timer;

    void Reset() { EllrisGUID = 0; }

    void KilledUnit(Unit* victim);
    void JustDied(Unit* killer);

    void EnterCombat(Unit* who){}

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Chain cast
        if (!m_creature->IsNonMeleeSpellCasted(false))
            DoCast(m_creature->getVictim(),SPELL_IMP_FIREBALL);
        else DoMeleeAttackIfReady();
    }
};*/

struct TRINITY_DLL_DECL boss_ellris_duskhallowAI : public boss_priestess_guestAI
{
    //Warlock
    boss_ellris_duskhallowAI(Creature *c) : boss_priestess_guestAI(c) {}

    bool HasSummonedImp;

    uint32 Immolate_Timer;
    uint32 Shadow_Bolt_Timer;
    uint32 Seed_of_Corruption_Timer;
    uint32 Curse_of_Agony_Timer;
    uint32 Fear_Timer;

    void Reset()
    {
        HasSummonedImp = false;

        Immolate_Timer = 6000;
        Shadow_Bolt_Timer = 3000;
        Seed_of_Corruption_Timer = 2000;
        Curse_of_Agony_Timer = 1000;
        Fear_Timer = 10000;

        boss_priestess_guestAI::Reset();
    }

    void JustDied(Unit* killer)
    {
        boss_priestess_guestAI::JustDied(killer);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!HasSummonedImp)
        {
            //Imp will not despawn unless it's killed, even if owner dies, this is correct way.
            DoCast(m_creature,SPELL_SUMMON_IMP);
            HasSummonedImp = true;
        }

        if (!UpdateVictim())
            return;

        boss_priestess_guestAI::UpdateAI(diff);

        if (Immolate_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_IMMOLATE);
            Immolate_Timer = 6000;
        }else Immolate_Timer -= diff;

        if (Shadow_Bolt_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SHADOW_BOLT);
            Shadow_Bolt_Timer = 5000;
        }else Shadow_Bolt_Timer -= diff;

        if (Seed_of_Corruption_Timer < diff)
        {
            DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_SEED_OF_CORRUPTION);
            Seed_of_Corruption_Timer = 10000;
        }else Seed_of_Corruption_Timer -= diff;

        if (Curse_of_Agony_Timer < diff)
        {
            DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_CURSE_OF_AGONY);
            Curse_of_Agony_Timer = 13000;
        }else Curse_of_Agony_Timer -= diff;

        if (Fear_Timer < diff)
        {
            DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_FEAR);
            Fear_Timer = 10000;
        }else Fear_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

/*void mob_fizzleAI::JustDied(Unit* killer)
{
    if(Creature* Ellris = (Unit::GetCreature(*m_creature, EllrisGUID)))
        CAST_AI(boss_ellris_duskhallowAI, Ellris->AI())->ImpGUID = 0;
}

void mob_fizzleAI::KilledUnit(Unit* victim)
{
    if(Creature* Ellris = (Unit::GetCreature(*m_creature, EllrisGUID)))
        CAST_AI(boss_ellris_duskhallowAI, Ellris->AI())->KilledUnit(victim);
}*/

#define SPELL_KNOCKDOWN            11428
#define SPELL_SNAP_KICK            46182

struct TRINITY_DLL_DECL boss_eramas_brightblazeAI : public boss_priestess_guestAI
{
    //Monk
    boss_eramas_brightblazeAI(Creature *c) : boss_priestess_guestAI(c) {}

    uint32 Knockdown_Timer;
    uint32 Snap_Kick_Timer;

    void Reset()
    {
        Knockdown_Timer = 6000;
        Snap_Kick_Timer = 4500;

        boss_priestess_guestAI::Reset();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        boss_priestess_guestAI::UpdateAI(diff);

        if (Knockdown_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_KNOCKDOWN);
            Knockdown_Timer = 6000;
        }else Knockdown_Timer -= diff;

        if (Snap_Kick_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SNAP_KICK);
            Snap_Kick_Timer  = 4500;
        }else Snap_Kick_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

#define SPELL_POLYMORPH             13323
#define SPELL_ICE_BLOCK             27619
#define SPELL_BLIZZARD              44178
#define SPELL_ICE_LANCE             46194
#define SPELL_CONE_OF_COLD          38384
#define SPELL_FROSTBOLT             15043
#define SPELL_BLINK                 14514

struct TRINITY_DLL_DECL boss_yazzaiAI : public boss_priestess_guestAI
{
    //Mage
    boss_yazzaiAI(Creature *c) : boss_priestess_guestAI(c) {}

    bool HasIceBlocked;

    uint32 Polymorph_Timer;
    uint32 Ice_Block_Timer;
    uint32 Wait_Timer;
    uint32 Blizzard_Timer;
    uint32 Ice_Lance_Timer;
    uint32 Cone_of_Cold_Timer;
    uint32 Frostbolt_Timer;
    uint32 Blink_Timer;

    void Reset()
    {
        HasIceBlocked = false;

        Polymorph_Timer = 1000;
        Ice_Block_Timer = 20000;
        Wait_Timer = 10000;
        Blizzard_Timer = 8000;
        Ice_Lance_Timer = 12000;
        Cone_of_Cold_Timer = 10000;
        Frostbolt_Timer = 3000;
        Blink_Timer = 8000;

        boss_priestess_guestAI::Reset();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        boss_priestess_guestAI::UpdateAI(diff);

        if (Polymorph_Timer < diff)
        {
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
            {
                DoCast(target, SPELL_POLYMORPH);
                Polymorph_Timer = 20000;
            }
        }else Polymorph_Timer -= diff;

        if (((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 35) && !HasIceBlocked)
        {
            DoCast(m_creature, SPELL_ICE_BLOCK);
            HasIceBlocked = true;
        }

        if (Blizzard_Timer < diff)
        {
            DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_BLIZZARD);
            Blizzard_Timer = 8000;
        }else Blizzard_Timer -= diff;

        if (Ice_Lance_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_ICE_LANCE);
            Ice_Lance_Timer = 12000;
        }else Ice_Lance_Timer -= diff;

        if (Cone_of_Cold_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_CONE_OF_COLD);
            Cone_of_Cold_Timer = 10000;
        }else Cone_of_Cold_Timer -= diff;

        if (Frostbolt_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_FROSTBOLT);
            Frostbolt_Timer = 8000;
        }else Frostbolt_Timer -= diff;

        if (Blink_Timer < diff)
        {
            bool InMeleeRange = false;
            std::list<HostilReference*>& t_list = m_creature->getThreatManager().getThreatList();
            for(std::list<HostilReference*>::iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
            {
                if (Unit* target = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid()))
                {
                    //if in melee range
                    if (target->IsWithinDistInMap(m_creature, 5))
                    {
                        InMeleeRange = true;
                        break;
                    }
                }
            }

            //if anybody is in melee range than escape by blink
            if (InMeleeRange)
                DoCast(m_creature, SPELL_BLINK);

            Blink_Timer = 8000;
        }else Blink_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

#define SPELL_INTERCEPT_STUN         27577
#define SPELL_DISARM                 27581
#define SPELL_PIERCING_HOWL          23600
#define SPELL_FRIGHTENING_SHOUT      19134
#define SPELL_HAMSTRING              27584
#define SPELL_BATTLE_SHOUT           27578
#define SPELL_MORTAL_STRIKE          44268

struct TRINITY_DLL_DECL boss_warlord_salarisAI : public boss_priestess_guestAI
{
    //Warrior
    boss_warlord_salarisAI(Creature *c) : boss_priestess_guestAI(c) {}

    uint32 Intercept_Stun_Timer;
    uint32 Disarm_Timer;
    uint32 Piercing_Howl_Timer;
    uint32 Frightening_Shout_Timer;
    uint32 Hamstring_Timer;
    uint32 Mortal_Strike_Timer;

    void Reset()
    {
        Intercept_Stun_Timer = 500;
        Disarm_Timer = 6000;
        Piercing_Howl_Timer = 10000;
        Frightening_Shout_Timer = 18000;
        Hamstring_Timer = 4500;
        Mortal_Strike_Timer = 8000;
        DoCast(m_creature, SPELL_BATTLE_SHOUT);

        boss_priestess_guestAI::Reset();
    }

    void EnterCombat(Unit* who)
    {
        DoCast(m_creature, SPELL_BATTLE_SHOUT);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        boss_priestess_guestAI::UpdateAI(diff);

        if (Intercept_Stun_Timer < diff)
        {
            bool InMeleeRange = false;
            std::list<HostilReference*>& t_list = m_creature->getThreatManager().getThreatList();
            for(std::list<HostilReference*>::iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
            {
                if (Unit* target = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid()))
                {
                    //if in melee range
                    if (target->IsWithinDistInMap(m_creature, 5))
                    {
                        InMeleeRange = true;
                        break;
                    }
                }
            }

            //if nobody is in melee range than try to use Intercept
            if (!InMeleeRange)
                DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_INTERCEPT_STUN);

            Intercept_Stun_Timer = 10000;
        }else Intercept_Stun_Timer -= diff;

        if (Disarm_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_DISARM);
            Disarm_Timer = 6000;
        }else Disarm_Timer -= diff;

        if (Hamstring_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_HAMSTRING);
            Hamstring_Timer = 4500;
        }else Hamstring_Timer -= diff;

        if (Mortal_Strike_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_MORTAL_STRIKE);
            Mortal_Strike_Timer = 4500;
        }else Mortal_Strike_Timer -= diff;

        if (Piercing_Howl_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_PIERCING_HOWL);
            Piercing_Howl_Timer = 10000;
        }else Piercing_Howl_Timer -= diff;

        if (Frightening_Shout_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_FRIGHTENING_SHOUT);
            Frightening_Shout_Timer = 18000;
        }else Frightening_Shout_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

#define SPELL_AIMED_SHOT            44271
#define SPELL_SHOOT                 15620
#define SPELL_CONCUSSIVE_SHOT       27634
#define TRIGGER_CONCUSSIVE_SHOT     19410
#define SPELL_MULTI_SHOT            31942
#define SPELL_WING_CLIP             44286
#define SPELL_FREEZING_TRAP         44136

#define CREATURE_SLIVER             24552

/*struct TRINITY_DLL_DECL mob_sliverAI : public ScriptedAI
{
    mob_sliverAI(Creature *c) : ScriptedAI(c) {}

    uint64 GaraxxasGUID;

    void Reset() { GaraxxasGUID = 0; }

    void KilledUnit(Unit* victim);
    void JustDied(Unit* killer);

    void EnterCombat(Unit* who){}

};*/

struct TRINITY_DLL_DECL boss_garaxxasAI : public boss_priestess_guestAI
{
    //Hunter
    boss_garaxxasAI(Creature *c) : boss_priestess_guestAI(c) {}

    //uint64 SliverGUID;
    bool HasSummonedSliver;

    uint32 Aimed_Shot_Timer;
    uint32 Shoot_Timer;
    uint32 Concussive_Shot_Timer;
    uint32 Multi_Shot_Timer;
    uint32 Wing_Clip_Timer;
    uint32 Freezing_Trap_Timer;

    void Reset()
    {
        //SliverGUID = 0;
        HasSummonedSliver = false;

        Aimed_Shot_Timer = 6000;
        Shoot_Timer = 2500;
        Concussive_Shot_Timer = 8000;
        Multi_Shot_Timer = 10000;
        Wing_Clip_Timer = 4000;
        Freezing_Trap_Timer = 15000;

        boss_priestess_guestAI::Reset();
    }

    void JustDied(Unit* killer)
    {
        boss_priestess_guestAI::JustDied(killer);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!HasSummonedSliver)
        {
            Creature* Sliver = m_creature->SummonCreature(CREATURE_SLIVER, 0, 0, 0, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
            if (Sliver)
            {
                //CAST_AI(mob_sliverAI, Sliver->AI())->GaraxxasGUID = m_creature->GetGUID();
                //SliverGUID = Sliver->GetGUID();
                HasSummonedSliver = true;
            }
        }

        if (!UpdateVictim())
            return;

        boss_priestess_guestAI::UpdateAI(diff);

        if (m_creature->IsWithinDistInMap(m_creature->getVictim(), 5.0f))
        {
            if (Wing_Clip_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_WING_CLIP);
                Wing_Clip_Timer = 4000;
            }else Wing_Clip_Timer -= diff;

            if (Freezing_Trap_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_FREEZING_TRAP);
                Freezing_Trap_Timer = 30000;
            }else Freezing_Trap_Timer -= diff;

            DoMeleeAttackIfReady();
        }
        else
        {
            if (Concussive_Shot_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_CONCUSSIVE_SHOT);
                Concussive_Shot_Timer = 8000;
            }else Concussive_Shot_Timer -= diff;

            if (Multi_Shot_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_MULTI_SHOT);
                Multi_Shot_Timer = 10000;
            }else Multi_Shot_Timer -= diff;

            if (Aimed_Shot_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_AIMED_SHOT);
                Aimed_Shot_Timer = 6000;
            }else Aimed_Shot_Timer -= diff;

            if (Shoot_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_SHOOT);
                Shoot_Timer = 2500;
            }else Shoot_Timer -= diff;
        }
    }
};

/*void mob_sliverAI::JustDied(Unit* killer)
{
    if(Creature* Garaxxas = (Unit::GetCreature(*m_creature, GaraxxasGUID)))
        CAST_AI(boss_garaxxasAI, Garaxxas->AI())->SliverGUID = 0;
}

void mob_sliverAI::KilledUnit(Unit* victim)
{
    if(Creature* Garaxxas = (Unit::GetCreature(*m_creature, GaraxxasGUID)))
        CAST_AI(boss_garaxxasAI, Garaxxas->AI())->KilledUnit(victim);
}*/

#define SPELL_WINDFURY_TOTEM         27621
#define SPELL_WAR_STOMP              46026
#define SPELL_PURGE                  27626
#define SPELL_LESSER_HEALING_WAVE    44256
#define SPELL_FROST_SHOCK            21401
#define SPELL_FIRE_NOVA_TOTEM        44257
#define SPELL_EARTHBIND_TOTEM        15786

struct TRINITY_DLL_DECL boss_apokoAI : public boss_priestess_guestAI
{
    //Shaman
    boss_apokoAI(Creature *c) : boss_priestess_guestAI(c) {}

    uint32 Totem_Timer;
    uint8  Totem_Amount;
    uint32 War_Stomp_Timer;
    uint32 Purge_Timer;
    uint32 Healing_Wave_Timer;
    uint32 Frost_Shock_Timer;

    void Reset()
    {
        Totem_Timer = 2000;
        Totem_Amount = 1;
        War_Stomp_Timer = 10000;
        Purge_Timer = 8000;
        Healing_Wave_Timer = 5000;
        Frost_Shock_Timer = 7000;

        boss_priestess_guestAI::Reset();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        boss_priestess_guestAI::UpdateAI(diff);

        if (Totem_Timer < diff)
        {
            switch(rand()%3)
            {
                case 0: DoCast(m_creature, SPELL_WINDFURY_TOTEM); break;
                case 1: DoCast(m_creature, SPELL_FIRE_NOVA_TOTEM); break;
                case 2: DoCast(m_creature, SPELL_EARTHBIND_TOTEM); break;
            }
            ++Totem_Amount;
            Totem_Timer = Totem_Amount*2000;
        }else Totem_Timer -= diff;

        if (War_Stomp_Timer < diff)
        {
            DoCast(m_creature, SPELL_WAR_STOMP);
            War_Stomp_Timer = 10000;
        }else War_Stomp_Timer -= diff;

        if (Purge_Timer < diff)
        {
            DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_PURGE);
            Purge_Timer = 15000;
        }else Purge_Timer -= diff;

        if (Frost_Shock_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_FROST_SHOCK);
            Frost_Shock_Timer = 7000;
        }else Frost_Shock_Timer -= diff;

        if (Healing_Wave_Timer < diff)
        {
            // std::vector<Add*>::iterator itr = Group.begin() + rand()%Group.size();
            // uint64 guid = (*itr)->guid;
            // if(guid)
            // {
            //   Unit* pAdd = Unit::GetUnit(*m_creature, (*itr)->guid);
            //   if(pAdd && pAdd->isAlive())
            //   {
            DoCast(m_creature, SPELL_LESSER_HEALING_WAVE);
            Healing_Wave_Timer = 5000;
            //    }
            // }
        }else Healing_Wave_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

#define SPELL_GOBLIN_DRAGON_GUN        44272
#define SPELL_ROCKET_LAUNCH            44137
#define SPELL_RECOMBOBULATE            44274
#define SPELL_HIGH_EXPLOSIVE_SHEEP     44276
#define SPELL_FEL_IRON_BOMB            46024
#define SPELL_SHEEP_EXPLOSION          44279

#define CREATURE_EXPLOSIVE_SHEEP        24715

struct TRINITY_DLL_DECL boss_zelfanAI : public boss_priestess_guestAI
{
    //Engineer
    boss_zelfanAI(Creature *c) : boss_priestess_guestAI(c) {}

    uint32 Goblin_Dragon_Gun_Timer;
    uint32 Rocket_Launch_Timer;
    uint32 Recombobulate_Timer;
    uint32 High_Explosive_Sheep_Timer;
    uint32 Fel_Iron_Bomb_Timer;

    void Reset()
    {
        Goblin_Dragon_Gun_Timer = 20000;
        Rocket_Launch_Timer = 7000;
        Recombobulate_Timer = 4000;
        High_Explosive_Sheep_Timer = 10000;
        Fel_Iron_Bomb_Timer = 15000;

        boss_priestess_guestAI::Reset();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        boss_priestess_guestAI::UpdateAI(diff);

        if (Goblin_Dragon_Gun_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_GOBLIN_DRAGON_GUN);
            Goblin_Dragon_Gun_Timer = 10000;
        }else Goblin_Dragon_Gun_Timer -= diff;

        if (Rocket_Launch_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_ROCKET_LAUNCH);
            Rocket_Launch_Timer = 9000;
        }else Rocket_Launch_Timer -= diff;

        if (Fel_Iron_Bomb_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_FEL_IRON_BOMB);
            Fel_Iron_Bomb_Timer = 15000;
        }else Fel_Iron_Bomb_Timer -= diff;

        if (Recombobulate_Timer < diff)
        {
            for(uint8 i = 0; i < Group.size(); ++i)
            {
                if (Unit* pAdd = Unit::GetUnit(*m_creature, Group[i]->guid))
                {
                    if (pAdd->IsPolymorphed())
                    {
                        DoCast(pAdd, SPELL_RECOMBOBULATE);
                        break;
                    }
                }
            }
        }else Recombobulate_Timer -= diff;

        if (High_Explosive_Sheep_Timer < diff)
        {
            DoCast(m_creature, SPELL_HIGH_EXPLOSIVE_SHEEP);
            High_Explosive_Sheep_Timer = 65000;
        }else High_Explosive_Sheep_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

//struct TRINITY_DLL_DECL mob_high_explosive_sheepAI : public ScriptedAI
//{
//    mob_high_explosive_sheepAI(Creature *c) : ScriptedAI(c) {}
//
//    uint32 Explosion_Timer;
//
//    void Reset()
//    {
//        Explosion_Timer = 60000;
//    }
//
//    void JustDied(Unit *Killer){}
//
//    void EnterCombat(Unit *who){}
//
//    void UpdateAI(const uint32 diff)
//    {
//        if(Explosion_Timer < diff)
//        {
//            DoCast(m_creature->getVictim(), SPELL_SHEEP_EXPLOSION);
//        }else
//            Explosion_Timer -= diff;
//    }
//};

/*CreatureAI* GetAI_mob_sliver(Creature *_Creature)
{
    return new mob_sliverAI (_Creature);
};*/

//CreatureAI* GetAI_mob_high_explosive_sheep(Creature *_Creature)
//{
//    return new mob_high_explosive_sheepAI (_Creature);
//};

/*CreatureAI* GetAI_mob_fizzle(Creature *_Creature)
{
    return new mob_fizzleAI (_Creature);
};*/

CreatureAI* GetAI_boss_priestess_delrissa(Creature *_Creature)
{
    return new boss_priestess_delrissaAI (_Creature);
}

CreatureAI* GetAI_boss_kagani_nightstrike(Creature *_Creature)
{
    return new boss_kagani_nightstrikeAI (_Creature);
}

CreatureAI* GetAI_ellris_duskhallow(Creature *_Creature)
{
    return new boss_ellris_duskhallowAI (_Creature);
}

CreatureAI* GetAI_eramas_brightblaze(Creature *_Creature)
{
    return new boss_eramas_brightblazeAI (_Creature);
}

CreatureAI* GetAI_yazzai(Creature *_Creature)
{
    return new boss_yazzaiAI (_Creature);
}

CreatureAI* GetAI_warlord_salaris(Creature *_Creature)
{
    return new boss_warlord_salarisAI (_Creature);
}

CreatureAI* GetAI_garaxxas(Creature *_Creature)
{
    return new boss_garaxxasAI (_Creature);
}

CreatureAI* GetAI_apoko(Creature *_Creature)
{
    return new boss_apokoAI (_Creature);
}

CreatureAI* GetAI_zelfan(Creature *_Creature)
{
    return new boss_zelfanAI (_Creature);
}

void AddSC_boss_priestess_delrissa()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_priestess_delrissa";
    newscript->GetAI = &GetAI_boss_priestess_delrissa;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_kagani_nightstrike";
    newscript->GetAI = &GetAI_boss_kagani_nightstrike;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_ellris_duskhallow";
    newscript->GetAI = &GetAI_ellris_duskhallow;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_eramas_brightblaze";
    newscript->GetAI = &GetAI_eramas_brightblaze;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_yazzai";
    newscript->GetAI = &GetAI_yazzai;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_warlord_salaris";
    newscript->GetAI = &GetAI_warlord_salaris;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_garaxxas";
    newscript->GetAI = &GetAI_garaxxas;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_apoko";
    newscript->GetAI = &GetAI_apoko;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_zelfan";
    newscript->GetAI = &GetAI_zelfan;
    newscript->RegisterSelf();

    /*newscript = new Script;
    newscript->Name = "mob_high_explosive_sheep";
    newscript->GetAI = &GetAI_mob_high_explosive_sheep;
    newscript->RegisterSelf();*/

    /*newscript = new Script;
    newscript->Name = "mob_fizzle";
    newscript->GetAI = &GetAI_mob_fizzle;
    newscript->RegisterSelf();*/

    /*newscript = new Script;
    newscript->Name = "mob_sliver";
    newscript->GetAI = &GetAI_mob_sliver;
    newscript->RegisterSelf();*/
}

