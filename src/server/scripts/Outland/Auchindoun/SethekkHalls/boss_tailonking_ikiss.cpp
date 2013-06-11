/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Talon_King_Ikiss
SD%Complete: 80
SDComment: Heroic supported. Some details missing, but most are spell related.
SDCategory: Auchindoun, Sethekk Halls
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "sethekk_halls.h"

enum TailonkingIkiss
{
    SAY_INTRO                   = 0,
    SAY_AGGRO                   = 1,
    SAY_SLAY                    = 2,
    SAY_DEATH                   = 3,
    EMOTE_ARCANE_EXP            = 4,

    SPELL_BLINK                 = 38194,
    SPELL_BLINK_TELEPORT        = 38203,
    SPELL_MANA_SHIELD           = 38151,
    SPELL_ARCANE_BUBBLE         = 9438,
    H_SPELL_SLOW                = 35032,
    SPELL_POLYMORPH             = 38245,
    H_SPELL_POLYMORPH           = 43309,
    SPELL_ARCANE_VOLLEY         = 35059,
    H_SPELL_ARCANE_VOLLEY       = 40424,
    SPELL_ARCANE_EXPLOSION      = 38197,
    H_SPELL_ARCANE_EXPLOSION    = 40425
};

class boss_talon_king_ikiss : public CreatureScript
{
public:
    boss_talon_king_ikiss() : CreatureScript("boss_talon_king_ikiss") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_talon_king_ikissAI (creature);
    }

    struct boss_talon_king_ikissAI : public ScriptedAI
    {
        boss_talon_king_ikissAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 ArcaneVolley_Timer;
        uint32 Sheep_Timer;
        uint32 Blink_Timer;
        uint32 Slow_Timer;

        bool ManaShield;
        bool Blink;
        bool Intro;

        void Reset()
        {
            ArcaneVolley_Timer = 5000;
            Sheep_Timer = 8000;
            Blink_Timer = 35000;
            Slow_Timer = 15000+rand()%15000;
            Blink = false;
            Intro = false;
            ManaShield = false;
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!me->GetVictim() && me->canCreatureAttack(who))
            {
                if (!Intro && me->IsWithinDistInMap(who, 100))
                {
                    Intro = true;
                    Talk(SAY_INTRO);
                }

                if (!me->CanFly() && me->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                    return;

                float attackRadius = me->GetAttackDistance(who);
                if (me->IsWithinDistInMap(who, attackRadius) && me->IsWithinLOSInMap(who))
                {
                    //who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
                    AttackStart(who);
                }
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);

            if (instance)
                instance->SetData(DATA_IKISSDOOREVENT, DONE);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_SLAY);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (Blink)
            {
                DoCast(me, SPELL_ARCANE_EXPLOSION);
                DoCast(me, SPELL_ARCANE_BUBBLE, true);
                Blink = false;
            }

            if (ArcaneVolley_Timer <= diff)
            {
                DoCast(me, SPELL_ARCANE_VOLLEY);
                ArcaneVolley_Timer = 7000+rand()%5000;
            } else ArcaneVolley_Timer -= diff;

            if (Sheep_Timer <= diff)
            {
                Unit* target;

                //second top aggro target in normal, random target in heroic correct?
                if (IsHeroic())
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                else
                    target = SelectTarget(SELECT_TARGET_TOPAGGRO, 1);

                if (target)
                    DoCast(target, SPELL_POLYMORPH);
                Sheep_Timer = 15000+rand()%2500;
            } else Sheep_Timer -= diff;

            //may not be correct time to cast
            if (!ManaShield && HealthBelowPct(20))
            {
                DoCast(me, SPELL_MANA_SHIELD);
                ManaShield = true;
            }

            if (IsHeroic())
            {
                if (Slow_Timer <= diff)
                {
                    DoCast(me, H_SPELL_SLOW);
                    Slow_Timer = 15000+rand()%25000;
                } else Slow_Timer -= diff;
            }

            if (Blink_Timer <= diff)
            {
                Talk(EMOTE_ARCANE_EXP);

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    if (me->IsNonMeleeSpellCasted(false))
                        me->InterruptNonMeleeSpells(false);

                    //Spell doesn't work, but we use for visual effect at least
                    DoCast(target, SPELL_BLINK);

                    float X = target->GetPositionX();
                    float Y = target->GetPositionY();
                    float Z = target->GetPositionZ();

                    DoTeleportTo(X, Y, Z);

                    DoCast(target, SPELL_BLINK_TELEPORT);
                    Blink = true;
                }
                Blink_Timer = 35000+rand()%5000;
            } else Blink_Timer -= diff;

            if (!Blink)
                DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_talon_king_ikiss()
{
    new boss_talon_king_ikiss();
}
