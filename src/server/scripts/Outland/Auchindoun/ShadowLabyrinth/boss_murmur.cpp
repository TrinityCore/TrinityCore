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
SDName: Boss_Murmur
SD%Complete: 90
SDComment: Timers may be incorrect
SDCategory: Auchindoun, Shadow Labyrinth
EndScriptData */

#include "ScriptPCH.h"
#include "shadow_labyrinth.h"

#define EMOTE_SONIC_BOOM            -1555036

#define SPELL_SONIC_BOOM_CAST       DUNGEON_MODE(33923, 38796)
#define SPELL_SONIC_BOOM_EFFECT     DUNGEON_MODE(33666, 38795)
#define SPELL_RESONANCE             33657
#define SPELL_MURMURS_TOUCH         DUNGEON_MODE(33711, 38794)
#define SPELL_MAGNETIC_PULL         33689
#define SPELL_SONIC_SHOCK           38797
#define SPELL_THUNDERING_STORM      39365

class boss_murmur : public CreatureScript
{
public:
    boss_murmur() : CreatureScript("boss_murmur") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_murmurAI (pCreature);
    }

    struct boss_murmurAI : public ScriptedAI
    {
        boss_murmurAI(Creature *c) : ScriptedAI(c)
        {
            SetCombatMovement(false);
        }

        uint32 SonicBoom_Timer;
        uint32 MurmursTouch_Timer;
        uint32 Resonance_Timer;
        uint32 MagneticPull_Timer;
        uint32 SonicShock_Timer;
        uint32 ThunderingStorm_Timer;
        bool SonicBoom;

        void Reset()
        {
            SonicBoom_Timer = 30000;
            MurmursTouch_Timer = 8000 + rand()%12000;
            Resonance_Timer = 5000;
            MagneticPull_Timer = 15000 + rand()%15000;
            ThunderingStorm_Timer = 15000;
            SonicShock_Timer = 10000;
            SonicBoom = false;

            //database should have `RegenHealth`=0 to prevent regen
            uint32 hp = me->CountPctFromMaxHealth(40);
            if (hp) me->SetHealth(hp);
            me->ResetPlayerDamageReq();
        }

        void SonicBoomEffect()
        {
            std::list<HostileReference *> t_list = me->getThreatManager().getThreatList();
            for (std::list<HostileReference *>::const_iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
            {
               Unit *pTarget = Unit::GetUnit(*me, (*itr)->getUnitGuid());
               if (pTarget && pTarget->GetTypeId() == TYPEID_PLAYER)
               {
                   //Not do anything without aura, spell can be resisted!
                   if (pTarget->HasAura(SPELL_SONIC_BOOM_CAST) && me->IsWithinDistInMap(pTarget, 34.0f))
                   {
                       //This will be wrong calculation. Also, comments suggest it must deal damage
                       pTarget->SetHealth(pTarget->CountPctFromMaxHealth(20));
                   }
               }
            }
        }

        void EnterCombat(Unit * /*who*/) { }

        // Sonic Boom instant damage (needs core fix instead of this)
        void SpellHitTarget(Unit *pTarget, const SpellEntry *spell)
        {
            if (pTarget && pTarget->isAlive() && spell && spell->Id == uint32(SPELL_SONIC_BOOM_EFFECT))
                me->DealDamage(pTarget, (pTarget->GetHealth()*90)/100, NULL, SPELL_DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NATURE, spell);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target or casting
            if (!UpdateVictim() || me->IsNonMeleeSpellCasted(false))
                return;

            // Sonic Boom
            if (SonicBoom)
            {
                DoCast(me, SPELL_SONIC_BOOM_EFFECT, true);
                SonicBoomEffect();

                SonicBoom = false;
                Resonance_Timer = 1500;
            }
            if (SonicBoom_Timer <= diff)
            {
                DoScriptText(EMOTE_SONIC_BOOM, me);
                DoCast(me, SPELL_SONIC_BOOM_CAST);
                SonicBoom_Timer = 30000;
                SonicBoom = true;
                return;
            } else SonicBoom_Timer -= diff;

            // Murmur's Touch
            if (MurmursTouch_Timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 80, true))
                    DoCast(pTarget, SPELL_MURMURS_TOUCH);
                MurmursTouch_Timer = 25000 + rand()%10000;
            } else MurmursTouch_Timer -= diff;

            // Resonance
            if (!SonicBoom && !(me->IsWithinMeleeRange(me->getVictim())))
            {
                if (Resonance_Timer <= diff)
                {
                    DoCast(me, SPELL_RESONANCE);
                    Resonance_Timer = 5000;
                } else Resonance_Timer -= diff;
            }

            // Magnetic Pull
            if (MagneticPull_Timer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    if (pTarget->GetTypeId() == TYPEID_PLAYER && pTarget->isAlive())
                    {
                        DoCast(pTarget, SPELL_MAGNETIC_PULL);
                        MagneticPull_Timer = 15000+rand()%15000;
                        return;
                    }
                MagneticPull_Timer = 500;
            } else MagneticPull_Timer -= diff;

            if (IsHeroic())
            {
                // Thundering Storm
                if (ThunderingStorm_Timer <= diff)
                {
                    std::list<HostileReference*>& m_threatlist = me->getThreatManager().getThreatList();
                    for (std::list<HostileReference*>::const_iterator i = m_threatlist.begin(); i != m_threatlist.end(); ++i)
                        if (Unit *pTarget = Unit::GetUnit((*me), (*i)->getUnitGuid()))
                            if (pTarget->isAlive() && !me->IsWithinDist(pTarget, 35, false))
                                DoCast(pTarget, SPELL_THUNDERING_STORM, true);
                    ThunderingStorm_Timer = 15000;
                } else ThunderingStorm_Timer -= diff;

                // Sonic Shock
                if (SonicShock_Timer <= diff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 20, false))
                        if (pTarget->isAlive())
                            DoCast(pTarget, SPELL_SONIC_SHOCK);
                    SonicShock_Timer = 10000+rand()%10000;
                } else SonicShock_Timer -= diff;
            }

            // Select nearest most aggro target if top aggro too far
            if (!me->isAttackReady())
                return;
            if (!me->IsWithinMeleeRange(me->getVictim()))
            {
                std::list<HostileReference*>& m_threatlist = me->getThreatManager().getThreatList();
                for (std::list<HostileReference*>::const_iterator i = m_threatlist.begin(); i != m_threatlist.end(); ++i)
                    if (Unit *pTarget = Unit::GetUnit((*me), (*i)->getUnitGuid()))
                        if (pTarget->isAlive() && me->IsWithinMeleeRange(pTarget))
                        {
                            me->TauntApply(pTarget);
                            break;
                        }
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_murmur()
{
    new boss_murmur();
}
