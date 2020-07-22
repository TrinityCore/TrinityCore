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
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "npc_pet_mag_".
 */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "CombatAI.h"
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "PetAI.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_INHERIT_MASTERS_THREAT_LIST   = 58838,
    SPELL_PET_HEALTH_SCALING            = 61679,
    SPELL_CLONE_ME                      = 45204,
    SPELL_COPY_OFFHAND_WEAPON           = 45206,
    SPELL_COPY_WEAPON                   = 41055,
    SPELL_INITIALIZE_IMAGES             = 58836,

    SPELL_FIREBALL                      = 88082,
    SPELL_FROST_BOLT                    = 59638,
    SPELL_ARCANE_BLAST                  = 88084
};

enum CreatureIds
{
    NPC_MIRROR_IMAGE_FIRE   = 47244,
    NPC_MIRROR_IMAGE_ARCANE = 47243,
    NPC_MIRROR_IMAGE_FROST  = 31216
};

enum Events
{
    EVENT_CAST_ABILITY = 1
};

struct npc_pet_mage_mirror_image : ScriptedAI
{
    npc_pet_mage_mirror_image(Creature* creature) : ScriptedAI(creature), _angle(0.f) { }

    void AttackStart(Unit* who) override
    {
        AttackStartCaster(who, 20.0f);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        DoCastAOE(SPELL_INHERIT_MASTERS_THREAT_LIST);
        DoCastSelf(SPELL_PET_HEALTH_SCALING);
        summoner->CastSpell(me, SPELL_CLONE_ME, true);
        DoCast(summoner, SPELL_COPY_OFFHAND_WEAPON);
        DoCast(summoner, SPELL_COPY_WEAPON);

        _angle = summoner->GetAngle(me);
        me->FollowTarget(summoner);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_INHERIT_MASTERS_THREAT_LIST)
        {
            Unit* summoner = me->ToTempSummon()->GetSummoner();
            if (!summoner)
                return;

            if (target->IsInCombatWith(summoner))
            {
                AddThreat(me, target->GetThreatManager().GetThreat(summoner), target);
                me->EngageWithTarget(target);
            }
        }
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_INITIALIZE_IMAGES)
        {
            _events.ScheduleEvent(EVENT_CAST_ABILITY, 500ms);
            if (Unit* target = me->SelectVictim())
                AttackStart(target);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CAST_ABILITY:
                    if (me->GetEntry() == NPC_MIRROR_IMAGE_FROST)
                        DoCastVictim(SPELL_FROST_BOLT);
                    if (me->GetEntry() == NPC_MIRROR_IMAGE_FIRE)
                        DoCastVictim(SPELL_FIREBALL);
                    else if (me->GetEntry() == NPC_MIRROR_IMAGE_ARCANE)
                        DoCastVictim(SPELL_ARCANE_BLAST);

                    _events.Repeat(3s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    float _angle;
};

void AddSC_mage_pet_scripts()
{
    RegisterCreatureAI(npc_pet_mage_mirror_image);
}
