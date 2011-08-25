/*
 * Copyright (C) 2008-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
 * Comment:  Find correct mushrooms spell to make them visible - buffs of the mushrooms not ever applied to the users...
 */

#include "ScriptPCH.h"
#include "ahnkahet.h"

enum Spells
{
    SPELL_BASH                              = 57094, // Victim
    SPELL_ENTANGLING_ROOTS                  = 57095, // Random Victim 100Y
    SPELL_MINI                              = 57055, // Self
    SPELL_VENOM_BOLT_VOLLEY                 = 57088, // Random Victim 100Y
    SPELL_HEALTHY_MUSHROOM_POTENT_FUNGUS    = 56648, // Killer 3Y
    SPELL_POISONOUS_MUSHROOM_POISON_CLOUD   = 57061, // Self - Duration 8 Sec
    SPELL_POISONOUS_MUSHROOM_VISUAL_AREA    = 61566, // Self
    SPELL_POISONOUS_MUSHROOM_VISUAL_AURA    = 56741, // Self
    SPELL_PUTRID_MUSHROOM                   = 31690  // To make the mushrooms visible
};

enum Creatures
{
    NPC_HEALTHY_MUSHROOM    = 30391,
    NPC_POISONOUS_MUSHROOM  = 30435
};

class boss_amanitar : public CreatureScript
{
public:
    boss_amanitar() : CreatureScript("boss_amanitar") { }

    struct boss_amanitarAI : public ScriptedAI
    {
        boss_amanitarAI(Creature * c) : ScriptedAI(c), summons(c)
        {
            pInstance = c->GetInstanceScript();
            FirstTime = true;
        }

        void Reset()
        {
            uiRootTimer = urand(5 * IN_MILLISECONDS, 9 * IN_MILLISECONDS);
            uiBashTimer = urand(10 * IN_MILLISECONDS, 14 * IN_MILLISECONDS);
            uiBoltTimer = urand(15 * IN_MILLISECONDS, SEKUNDEN_30);
            uiSpawnTimer = 0;

            me->SetMeleeDamageSchool(SPELL_SCHOOL_NATURE);
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);

            if (pInstance)
            {
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MINI);
                if (!FirstTime)
                    pInstance->SetData(DATA_AMANITAR_EVENT, FAIL);
                else
                    FirstTime = false;
            }
            summons.DespawnAll();
        }

        void JustSummoned(Creature * summon)
        {
            summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature * summon)
        {
            summons.Despawn(summon);
        }

        void JustDied(Unit * /*Killer*/)
        {
            if (pInstance)
            {
                pInstance->SetData(DATA_AMANITAR_EVENT, DONE);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MINI);
            }
            summons.DespawnAll();
        }

        void EnterCombat(Unit * /*who*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_AMANITAR_EVENT, IN_PROGRESS);

            DoCast(me, SPELL_MINI, false);

            DoZoneInCombat();
        }

        void SpawnAdds()
        {
            for (uint8 i=0; i<20; ++i)
            {
                if (Unit * victim = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    Position pos;
                    victim->GetPosition(&pos);
                    me->GetRandomNearPosition(pos, float(urand(5, 80)));
                    me->SummonCreature(NPC_POISONOUS_MUSHROOM, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, SEKUNDEN_30);
                    me->GetRandomNearPosition(pos, float(urand(5, 80)));
                    me->SummonCreature(NPC_HEALTHY_MUSHROOM, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, SEKUNDEN_30);
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            if (uiSpawnTimer <= diff)
            {
                SpawnAdds();
                uiSpawnTimer = urand(35 * IN_MILLISECONDS, SEKUNDEN_40);
            } else uiSpawnTimer -= diff;

            if (uiRootTimer <= diff)
            {
                if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_ENTANGLING_ROOTS);
                uiRootTimer = urand(15 * IN_MILLISECONDS, SEKUNDEN_30);
            } else uiRootTimer -= diff;

            if (uiBashTimer <= diff)
            {
                DoCastVictim(SPELL_BASH);
                uiBashTimer = urand(15 * IN_MILLISECONDS, SEKUNDEN_30);
            } else uiBashTimer -= diff;

            if (uiBoltTimer <= diff)
            {
                if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_VENOM_BOLT_VOLLEY);
                uiBoltTimer = urand(15 * IN_MILLISECONDS, SEKUNDEN_30);
            } else uiBoltTimer -= diff;

            DoMeleeAttackIfReady();
        }
    private:
        InstanceScript * pInstance;
        SummonList summons;

        uint32 uiRootTimer;
        uint32 uiBashTimer;
        uint32 uiBoltTimer;
        uint32 uiSpawnTimer;
    };

    CreatureAI * GetAI(Creature * creature) const
    {
        return new boss_amanitarAI(creature);
    }
};

class mob_amanitar_mushrooms : public CreatureScript
{
public:
    mob_amanitar_mushrooms() : CreatureScript("mob_amanitar_mushrooms") { }

    struct mob_amanitar_mushroomsAI : public Scripted_NoMovementAI
    {
        mob_amanitar_mushroomsAI(Creature * c) : Scripted_NoMovementAI(c)
        {
            me->SetDisplayId(26981); // Korrekte Anzeige erzwingen!
        }

        uint32 uiAuraTimer;
        uint32 uiDeathTimer;

        void Reset()
        {
            DoCast(me, SPELL_PUTRID_MUSHROOM, true); // Hack, to make the mushrooms visible, can't find orig. spell...

            if (me->GetEntry() == NPC_POISONOUS_MUSHROOM)
                DoCast(me, SPELL_POISONOUS_MUSHROOM_VISUAL_AURA, true);

            uiAuraTimer = 0;
            uiDeathTimer = SEKUNDEN_30;
        }

        void DamageTaken(Unit * done_by, uint32 & damage)
        {
            if (damage >= me->GetHealth() && me->GetEntry() == NPC_HEALTHY_MUSHROOM && done_by->GetTypeId() == TYPEID_PLAYER)
            {
                me->InterruptNonMeleeSpells(false);
                DoCast(done_by, SPELL_HEALTHY_MUSHROOM_POTENT_FUNGUS, true);
            }
        }

        void EnterCombat(Unit * /*who*/) { }
        void AttackStart(Unit * /*victim*/, float /*dist*/ = 0) { }

        void UpdateAI(const uint32 diff)
        {
            if (me->GetEntry() == NPC_POISONOUS_MUSHROOM)
            {
                if (uiAuraTimer <= diff)
                {
                    DoCast(me, SPELL_POISONOUS_MUSHROOM_VISUAL_AREA, true);
                    DoCast(me, SPELL_POISONOUS_MUSHROOM_POISON_CLOUD, false);
                    uiAuraTimer = 7 * IN_MILLISECONDS;
                } else uiAuraTimer -= diff;
            }
            if (uiDeathTimer <= diff)
                me->DisappearAndDie();
            else uiDeathTimer -= diff;
        }
    };

    CreatureAI * GetAI(Creature * creature) const
    {
        return new mob_amanitar_mushroomsAI(creature);
    }
};

void AddSC_boss_amanitar()
{
    new boss_amanitar;
    new mob_amanitar_mushrooms;
}
