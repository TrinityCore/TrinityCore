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

#include "zulgurub.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum Yells
{
    SAY_AGGRO               = 0,
    SAY_BLOODVENOM          = 1, // ID - 96842 Venomous Effusion
    SAY_TRANSFROM           = 2, // ID - 97354 Blessing of the Snake God
    SAY_WORD_OF_HETHISS     = 3, // ID - 96560 Word of Hethiss
    EMOTE_BLOODVENOM        = 4, // ID - 96842 Bloodvenom
    EMOTE_VENOM_WITHDRAWAL  = 5, // ID - 96653 Venom Withdrawal
    SAY_PLAYER_KILL         = 6,
    SAY_DEATH               = 7
};

enum Spells
{
};

enum Events
{
};

struct boss_venoxis : public BossAI
{
    boss_venoxis(Creature* creature) : BossAI(creature, DATA_VENOXIS) { }

    void Reset() override
    {
        _Reset();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_PLAYER_KILL);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
    /*
        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    */
    }
};

void AddSC_boss_venoxis()
{
    RegisterZulGurubCreatureAI(boss_venoxis);
}
