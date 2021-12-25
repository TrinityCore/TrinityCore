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
 * Scriptnames of files in this file should be prefixed with "npc_pet_hun_".
 */

#include "ScriptMgr.h"
#include "CreatureAIImpl.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

enum HunterSpells
{
    SPELL_HUNTER_CRIPPLING_POISON       = 30981, // Viper
    SPELL_HUNTER_DEADLY_POISON_PASSIVE  = 34657, // Venomous Snake
    SPELL_HUNTER_MIND_NUMBING_POISON    = 25810  // Viper
};

enum HunterCreatures
{
    NPC_HUNTER_VIPER                    = 19921
};

class npc_pet_hunter_snake_trap : public CreatureScript
{
    public:
        npc_pet_hunter_snake_trap() : CreatureScript("npc_pet_hunter_snake_trap") { }

        struct npc_pet_hunter_snake_trapAI : public ScriptedAI
        {
            npc_pet_hunter_snake_trapAI(Creature* creature) : ScriptedAI(creature), _isViper(false), _spellTimer(0) { }

            void JustEngagedWith(Unit* /*who*/) override { }

            void JustAppeared() override
            {
                _isViper = me->GetEntry() == NPC_HUNTER_VIPER ? true : false;

                me->SetMaxHealth(uint32(107 * (me->GetLevel() - 40) * 0.025f));
                // Add delta to make them not all hit the same time
                me->SetBaseAttackTime(BASE_ATTACK, me->GetBaseAttackTime(BASE_ATTACK) + urandms(0,6));

                if (!_isViper && !me->HasAura(SPELL_HUNTER_DEADLY_POISON_PASSIVE))
                    DoCast(me, SPELL_HUNTER_DEADLY_POISON_PASSIVE, true);
            }

            // Redefined for random target selection:
            void MoveInLineOfSight(Unit* /*who*/) override { }

            void UpdateAI(uint32 diff) override
            {
                if (me->GetVictim() && me->GetVictim()->HasBreakableByDamageCrowdControlAura())
                { // don't break cc
                    me->GetThreatManager().ClearFixate();
                    me->InterruptNonMeleeSpells(false);
                    me->AttackStop();
                    return;
                }

                if (me->IsSummon() && !me->GetThreatManager().GetFixateTarget())
                { // find new target
                    Unit* summoner = me->ToTempSummon()->GetSummonerUnit();

                    std::vector<Unit*> targets;
                    for (std::pair<ObjectGuid const, PvPCombatReference*> const& pair : summoner->GetCombatManager().GetPvPCombatRefs())
                    {
                        Unit* enemy = pair.second->GetOther(summoner);
                        if (!enemy->HasBreakableByDamageCrowdControlAura() && me->CanCreatureAttack(enemy) && me->IsWithinDistInMap(enemy, me->GetAttackDistance(enemy)))
                            targets.push_back(enemy);
                    }

                    if (targets.empty())
                        for (std::pair<ObjectGuid const, CombatReference*> const& pair : summoner->GetCombatManager().GetPvECombatRefs())
                        {
                            Unit* enemy = pair.second->GetOther(summoner);
                            if (!enemy->HasBreakableByDamageCrowdControlAura() && me->CanCreatureAttack(enemy) && me->IsWithinDistInMap(enemy, me->GetAttackDistance(enemy)))
                                targets.push_back(enemy);
                        }

                    for (Unit* target : targets)
                        me->EngageWithTarget(target);

                    if (!targets.empty())
                    {
                        Unit* target = Trinity::Containers::SelectRandomContainerElement(targets);
                        me->GetThreatManager().FixateTarget(target);
                    }
                }

                if (!UpdateVictim())
                    return;

                // Viper
                if (_isViper)
                {
                    if (_spellTimer <= diff)
                    {
                        if (!urand(0, 2)) // 33% chance to cast
                            DoCastVictim(RAND(SPELL_HUNTER_MIND_NUMBING_POISON, SPELL_HUNTER_CRIPPLING_POISON));

                        _spellTimer = 3000;
                    }
                    else
                        _spellTimer -= diff;
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool _isViper;
            uint32 _spellTimer;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_pet_hunter_snake_trapAI(creature);
        }
};

void AddSC_hunter_pet_scripts()
{
    new npc_pet_hunter_snake_trap();
}
