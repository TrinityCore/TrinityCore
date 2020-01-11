/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
Name: Boss_Shirrak_the_dead_watcher
%Complete: 80
Comment: InhibitMagic should stack slower far from the boss, proper Visual for Focus Fire, heroic implemented
Category: Auchindoun, Auchenai Crypts
EndScriptData */

#include "ScriptMgr.h"
#include "auchenai_crypts.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_INHIBITMAGIC          = 32264,
    SPELL_ATTRACTMAGIC          = 32265,
    SPELL_CARNIVOROUSBITE       = 36383,

    SPELL_FIERY_BLAST           = 32302,

    SPELL_FOCUS_FIRE_VISUAL     = 42075 //need to find better visual
};

enum Say
{
    EMOTE_FOCUSED               = 0
};

enum Creatures
{
    NPC_FOCUS_FIRE            = 18374
};

class boss_shirrak_the_dead_watcher : public CreatureScript
{
public:
    boss_shirrak_the_dead_watcher() : CreatureScript("boss_shirrak_the_dead_watcher") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetAuchenaiCryptsAI<boss_shirrak_the_dead_watcherAI>(creature);
    }

    struct boss_shirrak_the_dead_watcherAI : public ScriptedAI
    {
        boss_shirrak_the_dead_watcherAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            Inhibitmagic_Timer = 0;
            Attractmagic_Timer = 28000;
            Carnivorousbite_Timer = 10000;
            FocusFire_Timer = 17000;
            FocusedTargetGUID.Clear();
        }

        uint32 Inhibitmagic_Timer;
        uint32 Attractmagic_Timer;
        uint32 Carnivorousbite_Timer;
        uint32 FocusFire_Timer;

        ObjectGuid FocusedTargetGUID;

        void Reset() override
        {
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override
        { }

        void JustSummoned(Creature* summoned) override
        {
            if (summoned && summoned->GetEntry() == NPC_FOCUS_FIRE)
            {
                summoned->CastSpell(summoned, SPELL_FOCUS_FIRE_VISUAL, false);
                summoned->SetFaction(me->GetFaction());
                summoned->SetLevel(me->GetLevel());
                summoned->AddUnitState(UNIT_STATE_ROOT);

                if (Unit* pFocusedTarget = ObjectAccessor::GetUnit(*me, FocusedTargetGUID))
                    summoned->AI()->AttackStart(pFocusedTarget);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            //Inhibitmagic_Timer
            if (Inhibitmagic_Timer <= diff)
            {
                float dist;
                Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    if (Player* i_pl = i->GetSource())
                        if (i_pl->IsAlive() && (dist = i_pl->GetDistance(me)) < 45)
                        {
                            i_pl->RemoveAurasDueToSpell(SPELL_INHIBITMAGIC);
                            me->AddAura(SPELL_INHIBITMAGIC, i_pl);
                            if (dist < 35)
                                me->AddAura(SPELL_INHIBITMAGIC, i_pl);
                            if (dist < 25)
                                me->AddAura(SPELL_INHIBITMAGIC, i_pl);
                            if (dist < 15)
                                me->AddAura(SPELL_INHIBITMAGIC, i_pl);
                        }
                Inhibitmagic_Timer = 3000 + (rand32() % 1000);
            } else Inhibitmagic_Timer -= diff;

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Attractmagic_Timer
            if (Attractmagic_Timer <= diff)
            {
                DoCast(me, SPELL_ATTRACTMAGIC);
                Attractmagic_Timer = 30000;
                Carnivorousbite_Timer = 1500;
            } else Attractmagic_Timer -= diff;

            //Carnivorousbite_Timer
            if (Carnivorousbite_Timer <= diff)
            {
                DoCast(me, SPELL_CARNIVOROUSBITE);
                Carnivorousbite_Timer = 10000;
            } else Carnivorousbite_Timer -= diff;

            //FocusFire_Timer
            if (FocusFire_Timer <= diff)
            {
                // Summon Focus Fire & Emote
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1);
                if (target && target->GetTypeId() == TYPEID_PLAYER && target->IsAlive())
                {
                    FocusedTargetGUID = target->GetGUID();
                    me->SummonCreature(NPC_FOCUS_FIRE, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 5500);
                    Talk(EMOTE_FOCUSED, target);
                }
                FocusFire_Timer = 15000 + (rand32() % 5000);
            } else FocusFire_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class npc_focus_fire : public CreatureScript
{
public:
    npc_focus_fire() : CreatureScript("npc_focus_fire") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetAuchenaiCryptsAI<npc_focus_fireAI>(creature);
    }

    struct npc_focus_fireAI : public ScriptedAI
    {
        npc_focus_fireAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            FieryBlast_Timer = 3000 + (rand32() % 1000);
            fiery1 = fiery2 = true;
        }

        uint32 FieryBlast_Timer;
        bool fiery1, fiery2;

        void Reset() override
        {
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override
        { }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //FieryBlast_Timer
            if (fiery2 && FieryBlast_Timer <= diff)
            {
                DoCast(me, SPELL_FIERY_BLAST);

                if (fiery1) fiery1 = false;
                else if (fiery2) fiery2 = false;

                FieryBlast_Timer = 1000;
            } else FieryBlast_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_shirrak_the_dead_watcher()
{
    new boss_shirrak_the_dead_watcher();
    new npc_focus_fire();
}
