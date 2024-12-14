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
SDName: Boss_Captain_Skarloc
SD%Complete: 75
SDComment: Missing adds, missing waypoints to move up to Thrall once spawned + speech before enter combat.
SDCategory: Caverns of Time, Old Hillsbrad Foothills
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "old_hillsbrad.h"
#include "ScriptedCreature.h"

/*######################
# boss_captain_skarloc #
#######################*/

enum CaptainSkarloc
{
    SAY_ENTER                   = 0,
    SAY_TAUNT1                  = 1,
    SAY_TAUNT2                  = 2,
    SAY_SLAY                    = 3,
    SAY_DEATH                   = 4,

    SPELL_HOLY_LIGHT            = 29427,
    SPELL_CLEANSE               = 29380,
    SPELL_HAMMER_OF_JUSTICE     = 13005,
    SPELL_HOLY_SHIELD           = 31904,
    SPELL_DEVOTION_AURA         = 8258,
    SPELL_CONSECRATION          = 38385
};

struct boss_captain_skarloc : public BossAI
{
    boss_captain_skarloc(Creature* creature) : BossAI(creature, DATA_CAPTAIN_SKARLOC)
    {
        Initialize();
    }

    void Initialize()
    {
        Holy_Light_Timer = urand(20000, 30000);
        Cleanse_Timer = 10000;
        HammerOfJustice_Timer = urand(20000, 35000);
        HolyShield_Timer = 240000;
        DevotionAura_Timer = 3000;
        Consecration_Timer = 8000;
    }

    uint32 Holy_Light_Timer;
    uint32 Cleanse_Timer;
    uint32 HammerOfJustice_Timer;
    uint32 HolyShield_Timer;
    uint32 DevotionAura_Timer;
    uint32 Consecration_Timer;

    void Reset() override
    {
        BossAI::Reset();
        Initialize();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        //This is not correct. Should taunt Thrall before engage in combat
        Talk(SAY_TAUNT1);
        Talk(SAY_TAUNT2);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        Talk(SAY_DEATH);

        instance->SetData(TYPE_THRALL_EVENT, OH_ESCORT_HORSE_RIDE);
    }

    void UpdateAI(uint32 diff) override
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Holy_Light
        if (Holy_Light_Timer <= diff)
        {
            DoCast(me, SPELL_HOLY_LIGHT);
            Holy_Light_Timer = 30000;
        } else Holy_Light_Timer -= diff;

        //Cleanse
        if (Cleanse_Timer <= diff)
        {
            DoCast(me, SPELL_CLEANSE);
            Cleanse_Timer = 10000;
        } else Cleanse_Timer -= diff;

        //Hammer of Justice
        if (HammerOfJustice_Timer <= diff)
        {
            DoCastVictim(SPELL_HAMMER_OF_JUSTICE);
            HammerOfJustice_Timer = 60000;
        } else HammerOfJustice_Timer -= diff;

        //Holy Shield
        if (HolyShield_Timer <= diff)
        {
            DoCast(me, SPELL_HOLY_SHIELD);
            HolyShield_Timer = 240000;
        } else HolyShield_Timer -= diff;

        //Devotion_Aura
        if (DevotionAura_Timer <= diff)
        {
            DoCast(me, SPELL_DEVOTION_AURA);
            DevotionAura_Timer = urand(45000, 55000);
        } else DevotionAura_Timer -= diff;

        //Consecration
        if (Consecration_Timer <= diff)
        {
            //DoCastVictim(SPELL_CONSECRATION);
            Consecration_Timer = urand(5000, 10000);
        } else Consecration_Timer -= diff;
    }
};

void AddSC_boss_captain_skarloc()
{
    RegisterOldHillsbradCreatureAI(boss_captain_skarloc);
}
