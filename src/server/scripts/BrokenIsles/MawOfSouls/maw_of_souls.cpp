/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "ScriptedCreature.h"
#include "Player.h"
#include "GameObject.h"
#include "PassiveAI.h"
#include "maw_of_souls.h"

enum MOSSpells
{

    // Night Watch Mariner 97182
    SPELL_NWM_BIND              = 195279, // TANK ONLY!
    SPELL_LANTERN_OF_DARKNESS   = 192019,

    // Shroud Hound 97119
    SPELL_SHROUD_STRIKE         = 194506,

    // Seacursed Soulkeeper 97200
    SPELL_BLACKWATER_BLAST      = 200208,
    SPELL_DEFIANT_STRIKE_ONE    = 195031,
    SPELL_DEFIANT_STRIKE_TWO    = 195036,

    // Seacursed Slaver 97043
    SPELL_BARBED_SPEAR          = 194674,
    SPELL_FRACTURE              = 198752,
    SPELL_SWIRLING_MUCK         = 201567, // Or 201567, either of them

    // Seacursed Swiftblade 98919
    SPELL_SEA_LEGS              = 194615,
    SPELL_DECEPTIVE_STRIKE_ONE  = 185325,
    SPELL_DECEPTIVE_STRIKE_TWO  = 199250,
    SPELL_VERY_SINISTER_STRIKE  = 199327,

    // Waterlogged Soul Guard 99188
    SPELL_CURSE_OF_HOPE         = 194640,
    SPELL_SIX_POUND_BARREL      = 194442,
    SPELL_SOUL_SIPHON_WSG       = 194657, // Random person, except tank!

    // Helarjar Champion 97097
    SPELL_BONE_CHILLING_SCREAM  = 198405,
    SPELL_GHOSTLY_RAGE          = 194663,

    // Skjal 99307
    SPELL_SKJAL_BIND            = 195279,
    SPELL_DEBILITATING_SHOUT    = 195293,
    SPELL_SKJAL_DOUBLE          = 195250,
    SPELL_GIVE_NO_QUARTER       = 196885, // Or 198324

};

// NPC 97119 - DONE
class npc_shroud_hound : public CreatureScript
{
public:
    npc_shroud_hound() : CreatureScript("npc_shroud_hound") {}

    struct npc_shroud_houndAI : public ScriptedAI
    {
        npc_shroud_houndAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            Initialize();
        }

        void Initialize()
        {
            shroudTimer = 6 * IN_MILLISECONDS;
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
            {
                if(auraRemoved)
                    auraRemoved = false;

                return;
            }

            if(!auraRemoved)
            {
                auraRemoved = true;
                me->RemoveAura(145953);
            }

            if(shroudTimer <= diff)
            {
                if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                {
                    DoCast(target, SPELL_SHROUD_STRIKE);
                }

                shroudTimer = _shroudTimer;
            }
            else
                shroudTimer -= diff;

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
        bool auraRemoved = false;
        uint32 shroudTimer;
        uint32 _shroudTimer = 8 * IN_MILLISECONDS;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetMawOfSoulsAI<npc_shroud_houndAI>(creature);
    }
};


class npc_night_watch_mariner : public CreatureScript
{
public:
    npc_night_watch_mariner() : CreatureScript("npc_night_watch_mariner") {}

    struct npc_night_watch_marinerAI : public ScriptedAI
    {
        npc_night_watch_marinerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            Initialize();
        }

        void Initialize()
        {

        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if(!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetMawOfSoulsAI<npc_night_watch_marinerAI>(creature);
    }
};


class npc_seacursed_soulkeeper : public CreatureScript
{
public:
    npc_seacursed_soulkeeper() : CreatureScript("npc_seacursed_soulkeeper") {}

    struct npc_seacursed_soulkeeperAI : public ScriptedAI
    {
        npc_seacursed_soulkeeperAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            Initialize();
        }

        void Initialize()
        {
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if(!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetMawOfSoulsAI<npc_seacursed_soulkeeperAI>(creature);
    }
};


class npc_seacursed_slaver : public CreatureScript
{
public:
    npc_seacursed_slaver() : CreatureScript("npc_seacursed_slaver") {}

    struct npc_seacursed_slaverAI : public ScriptedAI
    {
        npc_seacursed_slaverAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            Initialize();
        }

        void Initialize()
        {
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if(!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetMawOfSoulsAI<npc_seacursed_slaverAI>(creature);
    }
};


class npc_seacursed_swiftblade : public CreatureScript
{
public:
    npc_seacursed_swiftblade() : CreatureScript("npc_seacursed_swiftblade") {}

    struct npc_seacursed_swiftbladeAI : public ScriptedAI
    {
        npc_seacursed_swiftbladeAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            Initialize();
        }

        void Initialize()
        {
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if(!UpdateVictim())
            {
                if(auraRemoved)
                    auraRemoved = false;
                return;
            }

            if(!auraRemoved)
            {
                auraRemoved = true;
                me->RemoveAura(197227);
            }

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
        bool auraRemoved = false;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetMawOfSoulsAI<npc_seacursed_swiftbladeAI>(creature);
    }
};


class npc_waterlogged_soul_guard : public CreatureScript
{
public:
    npc_waterlogged_soul_guard() : CreatureScript("npc_waterlogged_soul_guard") {}

    struct npc_waterlogged_soul_guardAI : public ScriptedAI
    {
        npc_waterlogged_soul_guardAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            Initialize();
        }

        void Initialize()
        {
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if(!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetMawOfSoulsAI<npc_waterlogged_soul_guardAI>(creature);
    }
};


// NPC 97097 - DONE
class npc_helarjar_champion : public CreatureScript
{
public:
    npc_helarjar_champion() : CreatureScript("npc_helarjar_champion") {}

    struct npc_helarjar_championAI : public ScriptedAI
    {
        npc_helarjar_championAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            Initialize();
        }

        void Initialize()
        {
            ghostlyRageTimer = 12 * IN_MILLISECONDS;
            boneChillingScreamTimer = _boneChillingScreamTimer;
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            if(ghostlyRageTimer <= diff)
            {
                DoCast(me, SPELL_GHOSTLY_RAGE);
                ghostlyRageTimer = _ghostlyRageTimer;
            }
            else
                ghostlyRageTimer -= diff;

            if(boneChillingScreamTimer <= diff)
            {
                DoCastVictim(SPELL_BONE_CHILLING_SCREAM);
                boneChillingScreamTimer = _boneChillingScreamTimer;
            }
            else
                boneChillingScreamTimer -= diff;

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
        uint32 boneChillingScreamTimer;
        uint32 _boneChillingScreamTimer = 18 * IN_MILLISECONDS;
        uint32 ghostlyRageTimer;
        uint32 _ghostlyRageTimer = 15 * IN_MILLISECONDS;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetMawOfSoulsAI<npc_helarjar_championAI>(creature);
    }
};

class npc_skjal_maw : public CreatureScript
{
public:
    npc_skjal_maw() : CreatureScript("npc_skjal_maw") {}

    struct npc_skjal_mawAI : public ScriptedAI
    {
        npc_skjal_mawAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            Initialize();
        }

        void Initialize()
        {
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if(!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetMawOfSoulsAI<npc_skjal_mawAI>(creature);
    }
};

void AddSC_maw_of_souls()
{
    new npc_shroud_hound();
    new npc_night_watch_mariner();
    new npc_seacursed_soulkeeper();
    new npc_seacursed_slaver();
    new npc_seacursed_swiftblade();
    new npc_waterlogged_soul_guard();
    new npc_helarjar_champion();
    new npc_skjal_maw();
}
