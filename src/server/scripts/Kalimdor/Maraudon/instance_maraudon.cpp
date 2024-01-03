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

/*
This placeholder for the instance is needed for dungeon finding to be able
to give credit after the boss defined in lastEncounterDungeon is killed.
Without it, the party doing random dungeon won't get satchel of spoils and
gets instead the deserter debuff.
*/

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Unit.h"
#include "maraudon.h"

static constexpr DungeonEncounterData Encounters[] =
{
    { BOSS_NOXXION, { { 422 } } },
    { BOSS_RAZORLASH, { { 423 } } },
    { BOSS_TINKERER_GIZLOCK, { { 427 } } },
    { BOSS_LORD_VYLETONGUE, { { 424 } } },
    { BOSS_CELEBRAS_THE_CURSED, { { 425 } } },
    { BOSS_LANDSLIDE, { { 426 } } },
    { BOSS_ROTGRIP, { { 428 } } },
    { BOSS_PRINCESS_THERADRAS, { { 429 } } },
};

class instance_maraudon : public InstanceMapScript
{
public:
    instance_maraudon() : InstanceMapScript(MaraudonScriptName, 349) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_maraudon_InstanceMapScript(map);
    }

    struct instance_maraudon_InstanceMapScript : public InstanceScript
    {
        instance_maraudon_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders("Maraudon_v1");
            SetBossNumber(MAX_ENCOUNTER);
            LoadDungeonEncounterData(Encounters);
        }

        void OnUnitDeath(Unit* unit) override
        {
            switch (unit->GetEntry())
            {
                case NPC_RAZORLASH:         SetBossState(BOSS_RAZORLASH, DONE); break;
                case NPC_TINKERER_GIZLOCK:  SetBossState(BOSS_TINKERER_GIZLOCK, DONE); break;
                case NPC_LORD_VYLETONGUE:   SetBossState(BOSS_LORD_VYLETONGUE, DONE); break;
                case NPC_ROTGRIP:           SetBossState(BOSS_ROTGRIP, DONE); break;
                default:                    break;
            }
        }
    };
};

void AddSC_instance_maraudon()
{
    new instance_maraudon();
}
