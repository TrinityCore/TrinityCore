/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "ScriptMgr.h"
#include "seat_of_triumvirate.h"

enum Spells
{
    //Nightmare Bolt
    SPELL_NB_TARGET = 204808,  //Targets a random player
    SPELL_NB_DAMAGE = 200185,

    //Waking Nightmare
    SPELL_WN_TARGET_AT = 200243,  //Targets a random player
    //Growing Paranoia
    SPELL_GP_TARGET_AT = 200289,  //Targets a random player
    //Overwhelming Terror
    SPELL_OT_TARGET = 200329,  //Targets a random player
    //Induced Paranoia
    SPELL_IP_TARGET = 200359,  //Targets a random player

    //Apocalyptic Nightmare
    SPELL_AN_TARGET = 200050,  //Cast after reaching 50% health
    SPELL_AN_TRIGGERMISSILE = 200067,
    SPELL_AN_MISSILE = 200111,
    SPELL_AN_DAMAGE = 204502,
    SPELL_AN_TRIGGERMISSILE_1 = 221267, //ocd trigger much ?
    SPELL_AN_MISSILE_1 = 221268

};

enum Talks
{
    SAY_PULL = 0,
    SAY_DIE = 1,
    SAY_15PCT = 2,
    SAY_90PCT = 3,
};

// 124309
struct boss_viceroy_nezhar : public BossAI
{
    boss_viceroy_nezhar(Creature* creature) : BossAI(creature, DATA_VICEROY_NEZHAR) { }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_NB_TARGET, 20s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (!hp90 && HealthBelowPct(90))
        {
            Talk(SAY_90PCT);
            hp90 = true;
        }

        if (!hp15 && HealthBelowPct(15))
        {
            Talk(SAY_15PCT);
            hp15 = true;
        }

        if (!hp50 && HealthBelowPct(50))
        {
            DoCastSelf(SPELL_AN_TARGET);
            hp50 = true;
        }

        switch (eventId)
        {
        case SPELL_NB_TARGET:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0, true))
                DoCast(target, SPELL_NB_TARGET);
            events.Repeat(20s);
            break;
        }
        case SPELL_IP_TARGET:
        {

            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0, true))
                DoCast(target, SPELL_IP_TARGET);
            events.Repeat(20s);
            break;
        }
        }

    }

private:
    bool hp90;
    bool hp15;
    bool hp50;
};

void AddSC_boss_viceroy_nezhar()
{
    RegisterCreatureAI(boss_viceroy_nezhar);
}
