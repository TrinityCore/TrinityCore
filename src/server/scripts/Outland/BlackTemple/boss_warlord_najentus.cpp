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
SDName: Boss_Warlord_Najentus
SD%Complete: 95
SDComment:
SDCategory: Black Temple
EndScriptData */

#include "ScriptPCH.h"
#include "black_temple.h"

enum eEnums
{
    SAY_AGGRO                       = -1564000,
    SAY_NEEDLE1                     = -1564001,
    SAY_NEEDLE2                     = -1564002,
    SAY_SLAY1                       = -1564003,
    SAY_SLAY2                       = -1564004,
    SAY_SPECIAL1                    = -1564005,
    SAY_SPECIAL2                    = -1564006,
    SAY_ENRAGE1                     = -1564007,           //is this text actually in use?
    SAY_ENRAGE2                     = -1564008,
    SAY_DEATH                       = -1564009,

    //Spells
    SPELL_NEEDLE_SPINE              = 39992,
    SPELL_TIDAL_BURST               = 39878,
    SPELL_TIDAL_SHIELD              = 39872,
    SPELL_IMPALING_SPINE            = 39837,
    SPELL_CREATE_NAJENTUS_SPINE     = 39956,
    SPELL_HURL_SPINE                = 39948,
    SPELL_BERSERK                   = 26662,

    GOBJECT_SPINE                   = 185584,

    EVENT_BERSERK                   = 1,
    EVENT_YELL                      = 2,
    EVENT_NEEDLE                    = 3,
    EVENT_SPINE                     = 4,
    EVENT_SHIELD                    = 5,

    GCD_CAST                        = 1,
    GCD_YELL                        = 2
};

class boss_najentus : public CreatureScript
{
public:
    boss_najentus() : CreatureScript("boss_najentus") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_najentusAI (pCreature);
    }

    struct boss_najentusAI : public ScriptedAI
    {
        boss_najentusAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;

        uint64 SpineTargetGUID;

        void Reset()
        {
            events.Reset();

            SpineTargetGUID = 0;

            if (pInstance)
                pInstance->SetData(DATA_HIGHWARLORDNAJENTUSEVENT, NOT_STARTED);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(rand()%2 ? SAY_SLAY1 : SAY_SLAY2, me);
            events.DelayEvents(5000, GCD_YELL);
        }

        void JustDied(Unit* /*victim*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_HIGHWARLORDNAJENTUSEVENT, DONE);

            DoScriptText(SAY_DEATH, me);
        }

        void SpellHit(Unit* /*caster*/, const SpellEntry *spell)
        {
            if (spell->Id == SPELL_HURL_SPINE && me->HasAura(SPELL_TIDAL_SHIELD))
            {
                me->RemoveAurasDueToSpell(SPELL_TIDAL_SHIELD);
                DoCast(me, SPELL_TIDAL_BURST, true);
                ResetTimer();
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_HIGHWARLORDNAJENTUSEVENT, IN_PROGRESS);

            DoScriptText(SAY_AGGRO, me);
            DoZoneInCombat();
            events.ScheduleEvent(EVENT_BERSERK, 480000, GCD_CAST);
            events.ScheduleEvent(EVENT_YELL, 45000 + (rand()%76)*1000, GCD_YELL);
            ResetTimer();
        }

        bool RemoveImpalingSpine()
        {
            if (!SpineTargetGUID) return false;
            Unit* pTarget = Unit::GetUnit(*me, SpineTargetGUID);
            if (pTarget && pTarget->HasAura(SPELL_IMPALING_SPINE))
                pTarget->RemoveAurasDueToSpell(SPELL_IMPALING_SPINE);
            SpineTargetGUID=0;
            return true;
        }

        void ResetTimer(uint32 inc = 0)
        {
            events.RescheduleEvent(EVENT_NEEDLE, 10000 + inc, GCD_CAST);
            events.RescheduleEvent(EVENT_SPINE, 20000 + inc, GCD_CAST);
            events.RescheduleEvent(EVENT_SHIELD, 60000 + inc);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_SHIELD:
                        DoCast(me, SPELL_TIDAL_SHIELD, true);
                        ResetTimer(45000);
                        break;
                    case EVENT_BERSERK:
                        DoScriptText(SAY_ENRAGE2, me);
                        DoCast(me, SPELL_BERSERK, true);
                        events.DelayEvents(15000, GCD_YELL);
                        break;
                    case EVENT_SPINE:
                    {
                        Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1);
                        if (!pTarget) pTarget = me->getVictim();
                        if (pTarget)
                        {
                            DoCast(pTarget, SPELL_IMPALING_SPINE, true);
                            SpineTargetGUID = pTarget->GetGUID();
                            //must let target summon, otherwise you cannot click the spine
                            pTarget->SummonGameObject(GOBJECT_SPINE, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), me->GetOrientation(), 0, 0, 0, 0, 30);
                            DoScriptText(rand()%2 ? SAY_NEEDLE1 : SAY_NEEDLE2, me);
                            events.DelayEvents(1500, GCD_CAST);
                            events.DelayEvents(15000, GCD_YELL);
                        }
                        events.ScheduleEvent(EVENT_SPINE, 21000, GCD_CAST);
                        return;
                    }
                    case EVENT_NEEDLE:
                    {
                        //DoCast(me, SPELL_NEEDLE_SPINE, true);
                        std::list<Unit*> pTargets;
                        SelectTargetList(pTargets, 3, SELECT_TARGET_RANDOM, 80, true);
                        for (std::list<Unit*>::const_iterator i = pTargets.begin(); i != pTargets.end(); ++i)
                            DoCast(*i, 39835, true);
                        events.ScheduleEvent(EVENT_NEEDLE, urand(15000, 25000), GCD_CAST);
                        events.DelayEvents(1500, GCD_CAST);
                        return;
                    }
                    case EVENT_YELL:
                        DoScriptText(RAND(SAY_SPECIAL1, SAY_SPECIAL2), me);
                        events.ScheduleEvent(EVENT_YELL, urand(25000, 100000), GCD_YELL);
                        events.DelayEvents(15000, GCD_YELL);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class go_najentus_spine : public GameObjectScript
{
public:
    go_najentus_spine() : GameObjectScript("go_najentus_spine") { }

    bool OnGossipHello(Player* pPlayer, GameObject* pGo)
    {
        if (InstanceScript* pInstance = pGo->GetInstanceScript())
            if (Creature* Najentus = Unit::GetCreature(*pGo, pInstance->GetData64(DATA_HIGHWARLORDNAJENTUS)))
                if (CAST_AI(boss_najentus::boss_najentusAI, Najentus->AI())->RemoveImpalingSpine())
                {
                    pPlayer->CastSpell(pPlayer, SPELL_CREATE_NAJENTUS_SPINE, true);
                    pGo->Delete();
                }
        return true;
    }

};

void AddSC_boss_najentus()
{
    new boss_najentus();
    new go_najentus_spine();
}
