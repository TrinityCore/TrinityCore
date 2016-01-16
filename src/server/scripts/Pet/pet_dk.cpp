/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
 * Scriptnames of files in this file should be prefixed with "npc_pet_dk_".
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CombatAI.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"

enum DeathKnightSpells
{
    // Ebon Gargoyle
    SPELL_DK_SUMMON_GARGOYLE_1      = 49206,
    SPELL_DK_SUMMON_GARGOYLE_2      = 50514,
    SPELL_DK_DISMISS_GARGOYLE       = 50515,
    SPELL_DK_SANCTUARY              = 54661,

    // Dancing Rune Weapon
    SPELL_DK_DANCING_RUNE_WEAPON    = 49028,
    SPELL_COPY_WEAPON = 63416,
    SPELL_DK_RUNE_WEAPON_MARK = 50474,
    SPELL_DK_DANCING_RUNE_WEAPON_VISUAL = 53160,
    SPELL_FAKE_AGGRO_RADIUS_8_YARD = 49812,
    SPELL_DK_RUNE_WEAPON_SCALING_01 = 51905,
    SPELL_DK_RUNE_WEAPON_SCALING = 51906,
    SPELL_PET_SCALING__MASTER_SPELL_06__SPELL_HIT_EXPERTISE_SPELL_PENETRATION = 67561,
    SPELL_DK_PET_SCALING_03 = 61697,
    SPELL_AGGRO_8_YD_PBAE = 49813,
    // Main Spells
    SPELL_BLOOD_STRIKE = 49926,
    SPELL_PLAGUE_STRIKE = 49917,
    
    SPELL_DISMISS_RUNEBLADE = 50707 // Right now despawn is done by its duration
};

class npc_pet_dk_ebon_gargoyle : public CreatureScript
{
    public:
        npc_pet_dk_ebon_gargoyle() : CreatureScript("npc_pet_dk_ebon_gargoyle") { }

        struct npc_pet_dk_ebon_gargoyleAI : CasterAI
        {
            npc_pet_dk_ebon_gargoyleAI(Creature* creature) : CasterAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                // Not needed to be despawned now
                _despawnTimer = 0;
            }

            void InitializeAI() override
            {
                Initialize();

                CasterAI::InitializeAI();
                ObjectGuid ownerGuid = me->GetOwnerGUID();
                if (!ownerGuid)
                    return;

                // Find victim of Summon Gargoyle spell
                std::list<Unit*> targets;
                Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(me, me, 30.0f);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(me, targets, u_check);
                me->VisitNearbyObject(30.0f, searcher);
                for (std::list<Unit*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
                    if ((*iter)->HasAura(SPELL_DK_SUMMON_GARGOYLE_1, ownerGuid))
                    {
                        me->Attack((*iter), false);
                        break;
                    }
            }

            void JustDied(Unit* /*killer*/) override
            {
                // Stop Feeding Gargoyle when it dies
                if (Unit* owner = me->GetOwner())
                    owner->RemoveAurasDueToSpell(SPELL_DK_SUMMON_GARGOYLE_2);
            }

            // Fly away when dismissed
            void SpellHit(Unit* source, SpellInfo const* spell) override
            {
                if (spell->Id != SPELL_DK_DISMISS_GARGOYLE || !me->IsAlive())
                    return;

                Unit* owner = me->GetOwner();
                if (!owner || owner != source)
                    return;

                // Stop Fighting
                me->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE, true);

                // Sanctuary
                me->CastSpell(me, SPELL_DK_SANCTUARY, true);
                me->SetReactState(REACT_PASSIVE);

                //! HACK: Creature's can't have MOVEMENTFLAG_FLYING
                // Fly Away
                me->SetCanFly(true);
                me->SetSpeed(MOVE_FLIGHT, 0.75f, true);
                me->SetSpeed(MOVE_RUN, 0.75f, true);
                float x = me->GetPositionX() + 20 * std::cos(me->GetOrientation());
                float y = me->GetPositionY() + 20 * std::sin(me->GetOrientation());
                float z = me->GetPositionZ() + 40;
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MovePoint(0, x, y, z);

                // Despawn as soon as possible
                _despawnTimer = 4 * IN_MILLISECONDS;
            }

            void UpdateAI(uint32 diff) override
            {
                if (_despawnTimer > 0)
                {
                    if (_despawnTimer > diff)
                        _despawnTimer -= diff;
                    else
                        me->DespawnOrUnsummon();
                    return;
                }

                CasterAI::UpdateAI(diff);
            }

        private:
           uint32 _despawnTimer;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_pet_dk_ebon_gargoyleAI(creature);
        }
};

enum DancingRuneWeapon
{
    DATA_INITIAL_TARGET_GUID = 1
};

class npc_pet_dk_rune_weapon : public CreatureScript
{
    public:
        npc_pet_dk_rune_weapon() : CreatureScript("npc_pet_dk_rune_weapon") { }

        struct npc_pet_dk_rune_weaponAI : ScriptedAI
        {
            npc_pet_dk_rune_weaponAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();

                // Prevent early victim engage
                creature->SetReactState(REACT_DEFENSIVE);
            }

            void Initialize()
            {
                _spellCooldown = 0;
                _secondSpellCooldown = 0;
            }

            void IsSummonedBy(Unit* summoner) override
            {
                // Set second creature_template model, invisible
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);

                DoCast(summoner, SPELL_COPY_WEAPON, true);
                DoCast(summoner, SPELL_DK_RUNE_WEAPON_MARK, true);
                DoCast(me, SPELL_DK_DANCING_RUNE_WEAPON_VISUAL, true);
                DoCast(me, SPELL_FAKE_AGGRO_RADIUS_8_YARD, true);
                DoCast(me, SPELL_DK_RUNE_WEAPON_SCALING_01, true);
                DoCast(me, SPELL_DK_RUNE_WEAPON_SCALING, true);
                DoCast(me, SPELL_PET_SCALING__MASTER_SPELL_06__SPELL_HIT_EXPERTISE_SPELL_PENETRATION, true);
                DoCast(me, SPELL_DK_PET_SCALING_03, true);

                _secondSpellCooldown = 6 * IN_MILLISECONDS;
            }

            void MoveInLineOfSight(Unit* /*who*/) override { }

            void SetGUID(ObjectGuid guid, int32 type) override
            {
                switch (type)
                {
                    case DATA_INITIAL_TARGET_GUID:
                        _targetGUID = guid;
                        if (Unit* target = ObjectAccessor::GetUnit(*me, _targetGUID))
                        {
                            AttackStart(target);
                            DoCast(target, SPELL_AGGRO_8_YD_PBAE, true);
                            _spellCooldown = 1 * IN_MILLISECONDS;
                        }
                        break;
                    default:
                        break;
                }
            }

            void AttackStart(Unit* who) override
            {
                if (who && me->Attack(who, true))
                {
                    me->GetMotionMaster()->MoveChase(who);
                }
            }

            void OwnerMeleeDamageDealt(Unit* /*owner*/, CalcDamageInfo* damageInfo) override
            {
                if (Unit* target = ObjectAccessor::GetUnit(*me, _targetGUID))
                {
                    damageInfo->damage /= 2;
                    damageInfo->cleanDamage /= 2;

                    // Even if its a DK, HITINFO_RAGE_GAIN is sent on rune autoattacks
                    CleanDamage cleanDamage(damageInfo->cleanDamage, damageInfo->absorb, damageInfo->attackType, damageInfo->hitOutCome);
                    me->DealDamage(target, damageInfo->damage, &cleanDamage, DIRECT_DAMAGE, SpellSchoolMask(damageInfo->damageSchoolMask), nullptr);
                }
            }

            void SpellHit(Unit* /*source*/, SpellInfo const* /*spell*/) override
            {

            }

            void UpdateAI(uint32 diff) override
            {
                /*
                    Investigate further if these casts are done by
                    any owned aura, eitherway SMSG_SPELL_GO
                    is sent every X seconds.
                */
                if (_spellCooldown)
                {
                    if (_spellCooldown <= diff)
                    {
                        // Cast every second
                        if (Unit* victim = ObjectAccessor::GetUnit(*me, _targetGUID))
                            DoCast(victim, SPELL_AGGRO_8_YD_PBAE, true);
                        _spellCooldown = 1 * IN_MILLISECONDS;
                    }
                    else
                        _spellCooldown -= diff;

                    if (_secondSpellCooldown <= diff)
                    {
                        // Cast every 6 seconds
                        DoCast(me, SPELL_DK_DANCING_RUNE_WEAPON_VISUAL, true);
                        _secondSpellCooldown = 6 * IN_MILLISECONDS;
                    }
                    else
                        _secondSpellCooldown -= diff;
                }
            }

            private:
                ObjectGuid _targetGUID;
                uint32 _spellCooldown;
                uint32 _secondSpellCooldown;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_pet_dk_rune_weaponAI(creature);
        }
};

void AddSC_deathknight_pet_scripts()
{
    new npc_pet_dk_ebon_gargoyle();
    new npc_pet_dk_rune_weapon();
}
