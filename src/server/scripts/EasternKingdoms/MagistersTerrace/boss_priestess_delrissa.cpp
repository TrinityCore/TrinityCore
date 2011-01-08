/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Boss_Priestess_Delrissa
SD%Complete: 65
SDComment: No Heroic support yet. Needs further testing. Several scripts for pets disabled, not seem to require any special script.
SDCategory: Magister's Terrace
EndScriptData */

#include "ScriptPCH.h"
#include "magisters_terrace.h"

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

enum eEnums
{
    SAY_AGGRO               = -1585012,
    SAY_DEATH               = -1585022,

    SPELL_DISPEL_MAGIC      = 27609,
    SPELL_FLASH_HEAL        = 17843,
    SPELL_SW_PAIN_NORMAL    = 14032,
    SPELL_SW_PAIN_HEROIC    = 15654,
    SPELL_SHIELD            = 44291,
    SPELL_RENEW_NORMAL      = 44174,
    SPELL_RENEW_HEROIC      = 46192,

    MAX_ACTIVE_LACKEY       = 4
};

const float fOrientation = 4.98f;
const float fZLocation = -19.921f;

float LackeyLocations[4][2]=
{
    {123.77f, 17.6007f},
    {131.731f, 15.0827f},
    {121.563f, 15.6213f},
    {129.988f, 17.2355f},
};

const uint32 m_auiAddEntries[] =
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

class boss_priestess_delrissa : public CreatureScript
{
public:
    boss_priestess_delrissa() : CreatureScript("boss_priestess_delrissa") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_priestess_delrissaAI(pCreature);
    }

    struct boss_priestess_delrissaAI : public ScriptedAI
    {
        boss_priestess_delrissaAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            memset(&m_auiLackeyGUID, 0, sizeof(m_auiLackeyGUID));
            LackeyEntryList.clear();
        }

        InstanceScript* pInstance;

        std::vector<uint32> LackeyEntryList;
        uint64 m_auiLackeyGUID[MAX_ACTIVE_LACKEY];

        uint8 PlayersKilled;

        uint32 HealTimer;
        uint32 RenewTimer;
        uint32 ShieldTimer;
        uint32 SWPainTimer;
        uint32 DispelTimer;
        uint32 ResetTimer;

        void Reset()
        {
            PlayersKilled = 0;

            HealTimer   = 15000;
            RenewTimer  = 10000;
            ShieldTimer = 2000;
            SWPainTimer = 5000;
            DispelTimer = 7500;
            ResetTimer = 5000;

            InitializeLackeys();
        }

        //this mean she at some point evaded
        void JustReachedHome()
        {
            if (pInstance)
                 pInstance->SetData(DATA_DELRISSA_EVENT, FAIL);
        }

        void EnterCombat(Unit* who)
        {
            DoScriptText(SAY_AGGRO, me);

            for (uint8 i = 0; i < MAX_ACTIVE_LACKEY; ++i)
            {
                if (Unit* pAdd = Unit::GetUnit(*me, m_auiLackeyGUID[i]))
                {
                    if (!pAdd->getVictim())
                    {
                        who->SetInCombatWith(pAdd);
                        pAdd->AddThreat(who, 0.0f);
                    }
                }
            }

            if (pInstance)
                pInstance->SetData(DATA_DELRISSA_EVENT, IN_PROGRESS);
        }

        void InitializeLackeys()
        {
            //can be called if Creature are dead, so avoid
            if (!me->isAlive())
                return;

            uint8 j = 0;

            //it's empty, so first time
            if (LackeyEntryList.empty())
            {
                //pre-allocate size for speed
                LackeyEntryList.resize((sizeof(m_auiAddEntries) / sizeof(uint32)));

                //fill vector array with entries from Creature array
                for (uint8 i = 0; i < LackeyEntryList.size(); ++i)
                    LackeyEntryList[i] = m_auiAddEntries[i];

                //remove random entries
                while (LackeyEntryList.size() > MAX_ACTIVE_LACKEY)
                    LackeyEntryList.erase(LackeyEntryList.begin() + rand()%LackeyEntryList.size());

                //summon all the remaining in vector
                for (std::vector<uint32>::const_iterator itr = LackeyEntryList.begin(); itr != LackeyEntryList.end(); ++itr)
                {
                    if (Creature* pAdd = me->SummonCreature((*itr), LackeyLocations[j][0], LackeyLocations[j][1], fZLocation, fOrientation, TEMPSUMMON_CORPSE_DESPAWN, 0))
                        m_auiLackeyGUID[j] = pAdd->GetGUID();

                    ++j;
                }
            }
            else
            {
                for (std::vector<uint32>::const_iterator itr = LackeyEntryList.begin(); itr != LackeyEntryList.end(); ++itr)
                {
                    Unit* pAdd = Unit::GetUnit(*me, m_auiLackeyGUID[j]);

                    //object already removed, not exist
                    if (!pAdd)
                    {
                        if (Creature* pAdd = me->SummonCreature((*itr), LackeyLocations[j][0], LackeyLocations[j][1], fZLocation, fOrientation, TEMPSUMMON_CORPSE_DESPAWN, 0))
                            m_auiLackeyGUID[j] = pAdd->GetGUID();
                    }
                    ++j;
                }
            }
        }

        void KilledUnit(Unit* victim)
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            DoScriptText(PlayerDeath[PlayersKilled].id, me);

            if (PlayersKilled < 4)
                ++PlayersKilled;
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (!pInstance)
                return;

            if (pInstance->GetData(DATA_DELRISSA_DEATH_COUNT) == MAX_ACTIVE_LACKEY)
                pInstance->SetData(DATA_DELRISSA_EVENT, DONE);
            else
            {
                if (me->HasFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE))
                    me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (ResetTimer <= diff)
            {
                float x, y, z, o;
                me->GetHomePosition(x, y, z, o);
                if (me->GetPositionZ() >= z+10)
                {
                    EnterEvadeMode();
                    return;
                }
                ResetTimer = 5000;
            } else ResetTimer -= diff;

            if (HealTimer <= diff)
            {
                uint32 health = me->GetHealth();
                Unit *pTarget = me;
                for (uint8 i = 0; i < MAX_ACTIVE_LACKEY; ++i)
                {
                    if (Unit* pAdd = Unit::GetUnit(*me, m_auiLackeyGUID[i]))
                    {
                        if (pAdd->isAlive() && pAdd->GetHealth() < health)
                            pTarget = pAdd;
                    }
                }

                DoCast(pTarget, SPELL_FLASH_HEAL);
                HealTimer = 15000;
            } else HealTimer -= diff;

            if (RenewTimer <= diff)
            {
                Unit *pTarget = me;

                if (urand(0,1))
                    if (Unit* pAdd = Unit::GetUnit(*me, m_auiLackeyGUID[rand()%MAX_ACTIVE_LACKEY]))
                        if (pAdd->isAlive())
                            pTarget = pAdd;

                DoCast(pTarget, SPELL_RENEW_NORMAL);
                RenewTimer = 5000;
            } else RenewTimer -= diff;

            if (ShieldTimer <= diff)
            {
                Unit *pTarget = me;

                if (urand(0,1))
                    if (Unit* pAdd = Unit::GetUnit(*me, m_auiLackeyGUID[rand()%MAX_ACTIVE_LACKEY]))
                        if (pAdd->isAlive() && !pAdd->HasAura(SPELL_SHIELD))
                            pTarget = pAdd;

                DoCast(pTarget, SPELL_SHIELD);
                ShieldTimer = 7500;
            } else ShieldTimer -= diff;

            if (DispelTimer <= diff)
            {
                Unit *pTarget = NULL;

                if (urand(0,1))
                    pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                else
                {
                    if (urand(0,1))
                        pTarget = me;
                    else
                        if (Unit* pAdd = Unit::GetUnit(*me, m_auiLackeyGUID[rand()%MAX_ACTIVE_LACKEY]))
                            if (pAdd->isAlive())
                                pTarget = pAdd;
                }

                if (pTarget)
                    DoCast(pTarget, SPELL_DISPEL_MAGIC);

                DispelTimer = 12000;
            } else DispelTimer -= diff;

            if (SWPainTimer <= diff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(pTarget, SPELL_SW_PAIN_NORMAL);

                SWPainTimer = 10000;
            } else SWPainTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};


enum eHealingPotion
{
    SPELL_HEALING_POTION    = 15503
};

//all 8 possible lackey use this common
struct boss_priestess_lackey_commonAI : public ScriptedAI
{
    boss_priestess_lackey_commonAI(Creature* c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceScript();
        memset(&m_auiLackeyGUIDs, 0, sizeof(m_auiLackeyGUIDs));
        AcquireGUIDs();
    }

    InstanceScript* pInstance;

    uint64 m_auiLackeyGUIDs[MAX_ACTIVE_LACKEY];
    uint32 ResetThreatTimer;

    bool UsedPotion;

    void Reset()
    {
        UsedPotion = false;

        // These guys does not follow normal threat system rules
        // For later development, some alternative threat system should be made
        // We do not know what this system is based upon, but one theory is class (healers=high threat, dps=medium, etc)
        // We reset their threat frequently as an alternative until such a system exist
        ResetThreatTimer = urand(5000,20000);

        // in case she is not alive and Reset was for some reason called, respawn her (most likely party wipe after killing her)
        if (Creature* pDelrissa = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_DELRISSA) : 0))
        {
            if (!pDelrissa->isAlive())
                pDelrissa->Respawn();
        }
    }

    void EnterCombat(Unit* pWho)
    {
        if (!pWho)
            return;

        if (pInstance)
        {
            for (uint8 i = 0; i < MAX_ACTIVE_LACKEY; ++i)
            {
                if (Unit* pAdd = Unit::GetUnit(*me, m_auiLackeyGUIDs[i]))
                {
                    if (!pAdd->getVictim() && pAdd != me)
                    {
                        pWho->SetInCombatWith(pAdd);
                        pAdd->AddThreat(pWho, 0.0f);
                    }
                }
            }

            if (Creature* pDelrissa = Unit::GetCreature(*me, pInstance->GetData64(DATA_DELRISSA)))
            {
                if (pDelrissa->isAlive() && !pDelrissa->getVictim())
                {
                    pWho->SetInCombatWith(pDelrissa);
                    pDelrissa->AddThreat(pWho, 0.0f);
                }
            }
        }
    }

    void JustDied(Unit* /*killer*/)
    {
        if (!pInstance)
            return;

        Creature* pDelrissa = Unit::GetCreature(*me, pInstance->GetData64(DATA_DELRISSA));
        uint32 uiLackeyDeathCount = pInstance->GetData(DATA_DELRISSA_DEATH_COUNT);

        if (!pDelrissa)
            return;

        //should delrissa really yell if dead?
        DoScriptText(LackeyDeath[uiLackeyDeathCount].id, pDelrissa);

        pInstance->SetData(DATA_DELRISSA_DEATH_COUNT, SPECIAL);

        //increase local var, since we now may have four dead
        ++uiLackeyDeathCount;

        if (uiLackeyDeathCount == MAX_ACTIVE_LACKEY)
        {
            //time to make her lootable and complete event if she died before lackeys
            if (!pDelrissa->isAlive())
            {
                if (!pDelrissa->HasFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE))
                    pDelrissa->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);

                pInstance->SetData(DATA_DELRISSA_EVENT, DONE);
            }
        }
    }

    void KilledUnit(Unit* victim)
    {
        if (!pInstance)
            return;

        if (Creature* Delrissa = Unit::GetCreature(*me, pInstance->GetData64(DATA_DELRISSA)))
            Delrissa->AI()->KilledUnit(victim);
    }

    void AcquireGUIDs()
    {
        if (!pInstance)
            return;

        if (Creature* Delrissa = (Unit::GetCreature(*me, pInstance->GetData64(DATA_DELRISSA))))
        {
            for (uint8 i = 0; i < MAX_ACTIVE_LACKEY; ++i)
                m_auiLackeyGUIDs[i] = CAST_AI(boss_priestess_delrissa::boss_priestess_delrissaAI, Delrissa->AI())->m_auiLackeyGUID[i];
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UsedPotion && HealthBelowPct(25))
        {
            DoCast(me, SPELL_HEALING_POTION);
            UsedPotion = true;
        }

        if (ResetThreatTimer <= diff)
        {
            DoResetThreat();
            ResetThreatTimer = 5000 + rand()%15000;
        } else ResetThreatTimer -= diff;
    }
};

enum eRogueSpells
{
    SPELL_KIDNEY_SHOT       = 27615,
    SPELL_GOUGE             = 12540,
    SPELL_KICK              = 27613,
    SPELL_VANISH            = 44290,
    SPELL_BACKSTAB          = 15657,
    SPELL_EVISCERATE        = 27611
};

class boss_kagani_nightstrike : public CreatureScript
{
public:
    boss_kagani_nightstrike() : CreatureScript("boss_kagani_nightstrike") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_kagani_nightstrikeAI(pCreature);
    }

    struct boss_kagani_nightstrikeAI : public boss_priestess_lackey_commonAI
    {
        //Rogue
        boss_kagani_nightstrikeAI(Creature *c) : boss_priestess_lackey_commonAI(c) {}

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
            me->SetVisible(true);

            boss_priestess_lackey_commonAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            boss_priestess_lackey_commonAI::UpdateAI(diff);

            if (Vanish_Timer <= diff)
            {
                DoCast(me, SPELL_VANISH);

                Unit* pUnit = SelectUnit(SELECT_TARGET_RANDOM, 0);

                DoResetThreat();

                if (pUnit)
                    me->AddThreat(pUnit, 1000.0f);

                InVanish = true;
                Vanish_Timer = 30000;
                Wait_Timer = 10000;
            } else Vanish_Timer -= diff;

            if (InVanish)
            {
                if (Wait_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_BACKSTAB, true);
                    DoCast(me->getVictim(), SPELL_KIDNEY_SHOT, true);
                    me->SetVisible(true);       // ...? Hacklike
                    InVanish = false;
                } else Wait_Timer -= diff;
            }

            if (Gouge_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_GOUGE);
                Gouge_Timer = 5500;
            } else Gouge_Timer -= diff;

            if (Kick_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_KICK);
                Kick_Timer = 7000;
            } else Kick_Timer -= diff;

            if (Eviscerate_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_EVISCERATE);
                Eviscerate_Timer = 4000;
            } else Eviscerate_Timer -= diff;

            if (!InVanish)
                DoMeleeAttackIfReady();
        }
    };

};


enum eWarlockSpells
{
    SPELL_IMMOLATE              = 44267,
    SPELL_SHADOW_BOLT           = 12471,
    SPELL_SEED_OF_CORRUPTION    = 44141,
    SPELL_CURSE_OF_AGONY        = 14875,
    SPELL_FEAR                  = 38595,
    SPELL_IMP_FIREBALL          = 44164,
    SPELL_SUMMON_IMP            = 44163
};

class boss_ellris_duskhallow : public CreatureScript
{
public:
    boss_ellris_duskhallow() : CreatureScript("boss_ellris_duskhallow") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_ellris_duskhallowAI(pCreature);
    }

    struct boss_ellris_duskhallowAI : public boss_priestess_lackey_commonAI
    {
        //Warlock
        boss_ellris_duskhallowAI(Creature *c) : boss_priestess_lackey_commonAI(c) {}

        uint32 Immolate_Timer;
        uint32 Shadow_Bolt_Timer;
        uint32 Seed_of_Corruption_Timer;
        uint32 Curse_of_Agony_Timer;
        uint32 Fear_Timer;

        void Reset()
        {
            Immolate_Timer = 6000;
            Shadow_Bolt_Timer = 3000;
            Seed_of_Corruption_Timer = 2000;
            Curse_of_Agony_Timer = 1000;
            Fear_Timer = 10000;

            boss_priestess_lackey_commonAI::Reset();
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            DoCast(me, SPELL_SUMMON_IMP);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            boss_priestess_lackey_commonAI::UpdateAI(diff);

            if (Immolate_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_IMMOLATE);
                Immolate_Timer = 6000;
            } else Immolate_Timer -= diff;

            if (Shadow_Bolt_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_SHADOW_BOLT);
                Shadow_Bolt_Timer = 5000;
            } else Shadow_Bolt_Timer -= diff;

            if (Seed_of_Corruption_Timer <= diff)
            {
                if (Unit* pUnit = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    DoCast(pUnit, SPELL_SEED_OF_CORRUPTION);

                Seed_of_Corruption_Timer = 10000;
            } else Seed_of_Corruption_Timer -= diff;

            if (Curse_of_Agony_Timer <= diff)
            {
                if (Unit* pUnit = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    DoCast(pUnit, SPELL_CURSE_OF_AGONY);

                Curse_of_Agony_Timer = 13000;
            } else Curse_of_Agony_Timer -= diff;

            if (Fear_Timer <= diff)
            {
                if (Unit* pUnit = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    DoCast(pUnit, SPELL_FEAR);

                Fear_Timer = 10000;
            } else Fear_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

enum eKickDown
{
    SPELL_KNOCKDOWN     = 11428,
    SPELL_SNAP_KICK     = 46182
};

class boss_eramas_brightblaze : public CreatureScript
{
public:
    boss_eramas_brightblaze() : CreatureScript("boss_eramas_brightblaze") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_eramas_brightblazeAI(pCreature);
    }

    struct boss_eramas_brightblazeAI : public boss_priestess_lackey_commonAI
    {
        //Monk
        boss_eramas_brightblazeAI(Creature *c) : boss_priestess_lackey_commonAI(c) {}

        uint32 Knockdown_Timer;
        uint32 Snap_Kick_Timer;

        void Reset()
        {
            Knockdown_Timer = 6000;
            Snap_Kick_Timer = 4500;

            boss_priestess_lackey_commonAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            boss_priestess_lackey_commonAI::UpdateAI(diff);

            if (Knockdown_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_KNOCKDOWN);
                Knockdown_Timer = 6000;
            } else Knockdown_Timer -= diff;

            if (Snap_Kick_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_SNAP_KICK);
                Snap_Kick_Timer  = 4500;
            } else Snap_Kick_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

enum eMageSpells
{
    SPELL_POLYMORPH         = 13323,
    SPELL_ICE_BLOCK         = 27619,
    SPELL_BLIZZARD          = 44178,
    SPELL_ICE_LANCE         = 46194,
    SPELL_CONE_OF_COLD      = 38384,
    SPELL_FROSTBOLT         = 15043,
    SPELL_BLINK             = 14514
};

class boss_yazzai : public CreatureScript
{
public:
    boss_yazzai() : CreatureScript("boss_yazzai") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_yazzaiAI(pCreature);
    }

    struct boss_yazzaiAI : public boss_priestess_lackey_commonAI
    {
        //Mage
        boss_yazzaiAI(Creature *c) : boss_priestess_lackey_commonAI(c) {}

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

            boss_priestess_lackey_commonAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            boss_priestess_lackey_commonAI::UpdateAI(diff);

            if (Polymorph_Timer <= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                {
                    DoCast(pTarget, SPELL_POLYMORPH);
                    Polymorph_Timer = 20000;
                }
            } else Polymorph_Timer -= diff;

            if (HealthBelowPct(35) && !HasIceBlocked)
            {
                DoCast(me, SPELL_ICE_BLOCK);
                HasIceBlocked = true;
            }

            if (Blizzard_Timer <= diff)
            {
                if (Unit* pUnit = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    DoCast(pUnit, SPELL_BLIZZARD);

                Blizzard_Timer = 8000;
            } else Blizzard_Timer -= diff;

            if (Ice_Lance_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_ICE_LANCE);
                Ice_Lance_Timer = 12000;
            } else Ice_Lance_Timer -= diff;

            if (Cone_of_Cold_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CONE_OF_COLD);
                Cone_of_Cold_Timer = 10000;
            } else Cone_of_Cold_Timer -= diff;

            if (Frostbolt_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FROSTBOLT);
                Frostbolt_Timer = 8000;
            } else Frostbolt_Timer -= diff;

            if (Blink_Timer <= diff)
            {
                bool InMeleeRange = false;
                std::list<HostileReference*>& t_list = me->getThreatManager().getThreatList();
                for (std::list<HostileReference*>::const_iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
                {
                    if (Unit *pTarget = Unit::GetUnit(*me, (*itr)->getUnitGuid()))
                    {
                        //if in melee range
                        if (pTarget->IsWithinDistInMap(me, 5))
                        {
                            InMeleeRange = true;
                            break;
                        }
                    }
                }

                //if anybody is in melee range than escape by blink
                if (InMeleeRange)
                    DoCast(me, SPELL_BLINK);

                Blink_Timer = 8000;
            } else Blink_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

enum eWarriorSpells
{
    SPELL_INTERCEPT_STUN        = 27577,
    SPELL_DISARM                = 27581,
    SPELL_PIERCING_HOWL         = 23600,
    SPELL_FRIGHTENING_SHOUT     = 19134,
    SPELL_HAMSTRING             = 27584,
    SPELL_BATTLE_SHOUT          = 27578,
    SPELL_MORTAL_STRIKE         = 44268
};

class boss_warlord_salaris : public CreatureScript
{
public:
    boss_warlord_salaris() : CreatureScript("boss_warlord_salaris") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_warlord_salarisAI(pCreature);
    }

    struct boss_warlord_salarisAI : public boss_priestess_lackey_commonAI
    {
        //Warrior
        boss_warlord_salarisAI(Creature *c) : boss_priestess_lackey_commonAI(c) {}

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

            boss_priestess_lackey_commonAI::Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoCast(me, SPELL_BATTLE_SHOUT);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            boss_priestess_lackey_commonAI::UpdateAI(diff);

            if (Intercept_Stun_Timer <= diff)
            {
                bool InMeleeRange = false;
                std::list<HostileReference*>& t_list = me->getThreatManager().getThreatList();
                for (std::list<HostileReference*>::const_iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
                {
                    if (Unit *pTarget = Unit::GetUnit(*me, (*itr)->getUnitGuid()))
                    {
                        //if in melee range
                        if (pTarget->IsWithinDistInMap(me, ATTACK_DISTANCE))
                        {
                            InMeleeRange = true;
                            break;
                        }
                    }
                }

                //if nobody is in melee range than try to use Intercept
                if (!InMeleeRange)
                {
                    if (Unit* pUnit = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pUnit, SPELL_INTERCEPT_STUN);
                }

                Intercept_Stun_Timer = 10000;
            } else Intercept_Stun_Timer -= diff;

            if (Disarm_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_DISARM);
                Disarm_Timer = 6000;
            } else Disarm_Timer -= diff;

            if (Hamstring_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_HAMSTRING);
                Hamstring_Timer = 4500;
            } else Hamstring_Timer -= diff;

            if (Mortal_Strike_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_MORTAL_STRIKE);
                Mortal_Strike_Timer = 4500;
            } else Mortal_Strike_Timer -= diff;

            if (Piercing_Howl_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_PIERCING_HOWL);
                Piercing_Howl_Timer = 10000;
            } else Piercing_Howl_Timer -= diff;

            if (Frightening_Shout_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FRIGHTENING_SHOUT);
                Frightening_Shout_Timer = 18000;
            } else Frightening_Shout_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

enum eHunterSpells
{
    SPELL_AIMED_SHOT            = 44271,
    SPELL_SHOOT                 = 15620,
    SPELL_CONCUSSIVE_SHOT       = 27634,
    SPELL_MULTI_SHOT            = 31942,
    SPELL_WING_CLIP             = 44286,
    SPELL_FREEZING_TRAP         = 44136,

    NPC_SLIVER                  = 24552
};

class boss_garaxxas : public CreatureScript
{
public:
    boss_garaxxas() : CreatureScript("boss_garaxxas") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_garaxxasAI(pCreature);
    }

    struct boss_garaxxasAI : public boss_priestess_lackey_commonAI
    {
        //Hunter
        boss_garaxxasAI(Creature *c) : boss_priestess_lackey_commonAI(c) { m_uiPetGUID = 0; }

        uint64 m_uiPetGUID;

        uint32 Aimed_Shot_Timer;
        uint32 Shoot_Timer;
        uint32 Concussive_Shot_Timer;
        uint32 Multi_Shot_Timer;
        uint32 Wing_Clip_Timer;
        uint32 Freezing_Trap_Timer;

        void Reset()
        {
            Aimed_Shot_Timer = 6000;
            Shoot_Timer = 2500;
            Concussive_Shot_Timer = 8000;
            Multi_Shot_Timer = 10000;
            Wing_Clip_Timer = 4000;
            Freezing_Trap_Timer = 15000;

            Unit* pPet = Unit::GetUnit(*me,m_uiPetGUID);
            if (!pPet)
                me->SummonCreature(NPC_SLIVER, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);

            boss_priestess_lackey_commonAI::Reset();
        }

        void JustSummoned(Creature* pSummoned)
        {
            m_uiPetGUID = pSummoned->GetGUID();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            boss_priestess_lackey_commonAI::UpdateAI(diff);

            if (me->IsWithinDistInMap(me->getVictim(), ATTACK_DISTANCE))
            {
                if (Wing_Clip_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_WING_CLIP);
                    Wing_Clip_Timer = 4000;
                } else Wing_Clip_Timer -= diff;

                if (Freezing_Trap_Timer <= diff)
                {
                    //attempt find go summoned from spell (casted by me)
                    GameObject* pGo = me->GetGameObject(SPELL_FREEZING_TRAP);

                    //if we have a pGo, we need to wait (only one trap at a time)
                    if (pGo)
                        Freezing_Trap_Timer = 2500;
                    else
                    {
                        //if pGo does not exist, then we can cast
                        DoCast(me->getVictim(), SPELL_FREEZING_TRAP);
                        Freezing_Trap_Timer = 15000;
                    }
                } else Freezing_Trap_Timer -= diff;

                DoMeleeAttackIfReady();
            }
            else
            {
                if (Concussive_Shot_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_CONCUSSIVE_SHOT);
                    Concussive_Shot_Timer = 8000;
                } else Concussive_Shot_Timer -= diff;

                if (Multi_Shot_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_MULTI_SHOT);
                    Multi_Shot_Timer = 10000;
                } else Multi_Shot_Timer -= diff;

                if (Aimed_Shot_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_AIMED_SHOT);
                    Aimed_Shot_Timer = 6000;
                } else Aimed_Shot_Timer -= diff;

                if (Shoot_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_SHOOT);
                    Shoot_Timer = 2500;
                } else Shoot_Timer -= diff;
            }
        }
    };

};

enum Spells
{
    SPELL_WINDFURY_TOTEM        = 27621,
    SPELL_WAR_STOMP             = 46026,
    SPELL_PURGE                 = 27626,
    SPELL_LESSER_HEALING_WAVE   = 44256,
    SPELL_FROST_SHOCK           = 21401,
    SPELL_FIRE_NOVA_TOTEM       = 44257,
    SPELL_EARTHBIND_TOTEM       = 15786
};

class boss_apoko : public CreatureScript
{
public:
    boss_apoko() : CreatureScript("boss_apoko") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_apokoAI(pCreature);
    }

    struct boss_apokoAI : public boss_priestess_lackey_commonAI
    {
        //Shaman
        boss_apokoAI(Creature *c) : boss_priestess_lackey_commonAI(c) {}

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

            boss_priestess_lackey_commonAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            boss_priestess_lackey_commonAI::UpdateAI(diff);

            if (Totem_Timer <= diff)
            {
                DoCast(me, RAND(SPELL_WINDFURY_TOTEM,SPELL_FIRE_NOVA_TOTEM,SPELL_EARTHBIND_TOTEM));
                ++Totem_Amount;
                Totem_Timer = Totem_Amount*2000;
            } else Totem_Timer -= diff;

            if (War_Stomp_Timer <= diff)
            {
                DoCast(me, SPELL_WAR_STOMP);
                War_Stomp_Timer = 10000;
            } else War_Stomp_Timer -= diff;

            if (Purge_Timer <= diff)
            {
                if (Unit* pUnit = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    DoCast(pUnit, SPELL_PURGE);

                Purge_Timer = 15000;
            } else Purge_Timer -= diff;

            if (Frost_Shock_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FROST_SHOCK);
                Frost_Shock_Timer = 7000;
            } else Frost_Shock_Timer -= diff;

            if (Healing_Wave_Timer <= diff)
            {
                // std::vector<Add*>::const_iterator itr = Group.begin() + rand()%Group.size();
                // uint64 guid = (*itr)->guid;
                // if (guid)
                // {
                //   Unit* pAdd = Unit::GetUnit(*me, (*itr)->guid);
                //   if (pAdd && pAdd->isAlive())
                //   {
                DoCast(me, SPELL_LESSER_HEALING_WAVE);
                Healing_Wave_Timer = 5000;
                //    }
                // }
            } else Healing_Wave_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

enum eEngineerSpells
{
    SPELL_GOBLIN_DRAGON_GUN     = 44272,
    SPELL_ROCKET_LAUNCH         = 44137,
    SPELL_RECOMBOBULATE         = 44274,
    SPELL_HIGH_EXPLOSIVE_SHEEP  = 44276,
    SPELL_FEL_IRON_BOMB         = 46024,
    SPELL_SHEEP_EXPLOSION       = 44279
};

class boss_zelfan : public CreatureScript
{
public:
    boss_zelfan() : CreatureScript("boss_zelfan") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_zelfanAI(pCreature);
    }

    struct boss_zelfanAI : public boss_priestess_lackey_commonAI
    {
        //Engineer
        boss_zelfanAI(Creature *c) : boss_priestess_lackey_commonAI(c) {}

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

            boss_priestess_lackey_commonAI::Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            boss_priestess_lackey_commonAI::UpdateAI(diff);

            if (Goblin_Dragon_Gun_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_GOBLIN_DRAGON_GUN);
                Goblin_Dragon_Gun_Timer = 10000;
            } else Goblin_Dragon_Gun_Timer -= diff;

            if (Rocket_Launch_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_ROCKET_LAUNCH);
                Rocket_Launch_Timer = 9000;
            } else Rocket_Launch_Timer -= diff;

            if (Fel_Iron_Bomb_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FEL_IRON_BOMB);
                Fel_Iron_Bomb_Timer = 15000;
            } else Fel_Iron_Bomb_Timer -= diff;

            if (Recombobulate_Timer <= diff)
            {
                for (uint8 i = 0; i < MAX_ACTIVE_LACKEY; ++i)
                {
                    if (Unit* pAdd = Unit::GetUnit(*me, m_auiLackeyGUIDs[i]))
                    {
                        if (pAdd->IsPolymorphed())
                        {
                            DoCast(pAdd, SPELL_RECOMBOBULATE);
                            break;
                        }
                    }
                }
                Recombobulate_Timer = 2000;
            } else Recombobulate_Timer -= diff;

            if (High_Explosive_Sheep_Timer <= diff)
            {
                DoCast(me, SPELL_HIGH_EXPLOSIVE_SHEEP);
                High_Explosive_Sheep_Timer = 65000;
            } else High_Explosive_Sheep_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

/*
class mob_high_explosive_sheep : public CreatureScript
{
public:
    mob_high_explosive_sheep() : CreatureScript("mob_high_explosive_sheep") { }

    //CreatureAI* GetAI(Creature* pCreature) const
    //{
    //    return new mob_high_explosive_sheepAI (pCreature);
    //};
};
*/

void AddSC_boss_priestess_delrissa()
{
    new boss_priestess_delrissa();
    new boss_kagani_nightstrike();
    new boss_ellris_duskhallow();
    new boss_eramas_brightblaze();
    new boss_yazzai();
    new boss_warlord_salaris();
    new boss_garaxxas();
    new boss_apoko();
    new boss_zelfan();
    // new mob_high_explosive_sheep();
}
