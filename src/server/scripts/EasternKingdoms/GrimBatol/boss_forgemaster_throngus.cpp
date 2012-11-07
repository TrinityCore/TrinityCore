/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
 
#include "ScriptPCH.h"
#include "grim_batol.h"

#define SAY_AGGRO                 "NO! Throngus get whipped again if he no finish!"
#define SAY_MACE_STANCE           "Oh, this is gonna HURT!"
#define SAY_SHIELD_STANCE         "You not get through defenses!"
#define SAY_SWORDS_STANCE         "Throngus SLICE you up!"
#define SAY_KILLED_PLAYER_0       "You break easy!"
#define SAY_KILLED_PLAYER_1       "Throngus use your corpse on body. Somewhere..."
#define SAY_DIED                  "Death... Good choice. Not best choice maybe, but better than fail and live."

enum Spells
{
    SPELL_BURNING_FLAMES        = 90759,
    SPELL_CAVE_IN_DAMAGE        = 74987,
    SPELL_CAVE_IN_VISUAL        = 74990,
    SPELL_DISORIENTING_ROAR     = 74976,
    SPELL_DISORIENTING_ROAR_H   = 90737,
    SPELL_DUAL_BLADES_BUFF      = 74981,
    SPELL_ENCUMBERED            = 75007,
    SPELL_FLAMING_ARROW         = 74944,
    SPELL_FLAMING_SHIELD        = 90819,
    SPELL_IMPALING_SLAM         = 75056,
    SPELL_LAVA_PATCH            = 90752,
    SPELL_MIGHTY_STOMP          = 74984,
    SPELL_PARALAX_SUMMON        = 74914,
    SPELL_PARALAX_TARGET        = 75071,
    SPELL_PERSONAL_PHALANX      = 74908,
    SPELL_PICK_WEAPON           = 75000,
    SPELL_SHIELD_BUFF           = 74909,
    SPELL_SHIELD_BUFF_H         = 76480,
    SPELL_SHIELD_VISUAL         = 94588,
    SPELL_TRASH_BUFF            = 74979,
};

enum Events
{
    EVENT_PICK_WEAPON           = 1,
    EVENT_MIGHTY_STOMP          = 2,
    EVENT_PERSONAL_PHALANX      = 3,
    EVENT_DISORIENTING_ROAR     = 4,
    EVENT_IMPALING_SLAM         = 5,
    EVENT_ARCHER_SHOOT          = 6,
};

enum Weapons
{
    WEAPON_NONE                 = 0,
    WEAPON_SHIELD               = 1,
    WEAPON_SWORDS               = 2,
    WEAPON_MACE                 = 3,
};

enum Equipments
{
    EQUIPMENT_ID_SWORD          = 65094,
    EQUIPMENT_ID_MACE           = 65090,
};

enum Npcs
{
    NPC_CAVE_IN                 = 40228,
    NPC_FIXATE_STALKER          = 40255,
};

Position const TwilightArcherSummonPos[13] =
{{-542.994f, -605.236f, 300.201f, 1.68049f},
{-543.59f, -605.413f, 283.784f, 1.50377f},
{-521.237f, -605.435f, 300.76f, 1.63886f},
{-483.862f, -588.658f, 297.574f, 2.38106f},
{-482.655f, -588.461f, 280.966f, 2.34571f},
{-471.266f, -575.324f, 295.906f, 2.30254f},
{-525.377f, -455.312f, 285.288f, 4.66187f},
{-544.49f, -454.961f, 295.831f, 4.79539f},
{-522.164f, -455.31f, 299.791f, 4.77575f},
{-468.703f, -489.004f, 300.462f, 3.78616f},
{-470.907f, -484.791f, 282.203f, 3.87255f},
{-485.052f, -474.621f, 296.525f, 3.92361f},
{-481.352f, -477.21f, 280.714f, 3.72334f}};

class boss_forgemaster_throngus: public CreatureScript
{
public:
    boss_forgemaster_throngus() : CreatureScript("boss_forgemaster_throngus") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_forgemaster_throngusAI (pCreature);
    }

    struct boss_forgemaster_throngusAI : public ScriptedAI
    {
        boss_forgemaster_throngusAI(Creature *c) : ScriptedAI(c), Summons(me) {}

        EventMap events;
        SummonList Summons;


        uint8 currentWeapon;
        uint8 phases[3];

        void EnterCombat(Unit* /*who*/)
        {
            me->MonsterYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
            events.ScheduleEvent(EVENT_PICK_WEAPON, urand(5000,10000));
        }

        void JustDied(Unit* /*killer*/)
        {
            me->MonsterYell(SAY_DIED, LANG_UNIVERSAL, NULL);
            Summons.DespawnAll();
        }

        void KilledUnit(Unit* victim)
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            switch (urand(0, 1))
            {
                case 0:
                    me->MonsterYell(SAY_KILLED_PLAYER_0, LANG_UNIVERSAL, 0);
                    break;
                case 1:
                    me->MonsterYell(SAY_KILLED_PLAYER_1, LANG_UNIVERSAL, 0);
                    break;
            }
        }

        void Reset()
        {
            currentWeapon = WEAPON_NONE;

            phases[0] = 0;
            phases[1] = 0;
            phases[2] = 0;

            events.Reset();
            Summons.DespawnAll();
            SetEquipmentSlots(false, 0, 0,0);
        }

        void SpellHit(Unit* target, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_PICK_WEAPON)
            {
                ResetWeapon();
                EquipWeapon();
                events.ScheduleEvent(EVENT_PICK_WEAPON, 30000);
            }
        }

        void JustSummoned(Creature* summon)
        {
            summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_PACIFIED);
            summon->SetDisplayId(11686);
            summon->SetUInt32Value(UNIT_FIELD_LEVEL, me->getLevel()); // Hide Level Up Animation
            summon->setFaction(me->getFaction());

            switch(summon->GetEntry())
            {
                case NPC_CAVE_IN:
                {
                    summon->CastSpell(summon, SPELL_CAVE_IN_VISUAL, true);
                    summon->CastSpell(summon, SPELL_CAVE_IN_DAMAGE, true);
                    break;
                }
                case NPC_FIRE_PATCH:
                {
                    summon->CastSpell(summon, SPELL_LAVA_PATCH, true);
                    break;
                }
                case NPC_TWILIGHT_ARCHER:
                {
                    summon->SetDisableGravity(true);
                    summon->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x01);
                    summon->SetCanFly(true);
                    summon->SendMovementFlagUpdate();
                    break;
                }
            }

            Summons.Summon(summon);
        }

        void UpdateAI(const uint32 diff)
        {
            if(!UpdateVictim())
                return;

            if(currentWeapon == WEAPON_SHIELD)
            {
                if(!me->HasAura(SPELL_SHIELD_VISUAL))
                    DoCast(me, SPELL_SHIELD_VISUAL, true);

                if(!me->HasAura(SPELL_PERSONAL_PHALANX))
                    DoCast(me, SPELL_PERSONAL_PHALANX, true);
            }

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_PICK_WEAPON:
                    {
                        DoCast(SPELL_PICK_WEAPON);
                        break;
                    }
                    case EVENT_MIGHTY_STOMP:
                    {
                        if (Unit* tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(tempTarget, SPELL_MIGHTY_STOMP);

                        events.ScheduleEvent(EVENT_MIGHTY_STOMP, 15000);
                        break;
                    }
                    case EVENT_PERSONAL_PHALANX:
                    {
                        if (Unit* tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        {
                            DoCast(tempTarget, SPELL_PARALAX_SUMMON, true);
                            DoCast(me, SPELL_FLAMING_SHIELD, true);
                            DoCast(tempTarget, SPELL_PARALAX_TARGET);
                        }

                        events.ScheduleEvent(EVENT_PERSONAL_PHALANX, 10000);
                        break;
                    }
                    case EVENT_IMPALING_SLAM:
                    {
                        if (Unit* tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(tempTarget, SPELL_IMPALING_SLAM);

                        events.ScheduleEvent(EVENT_IMPALING_SLAM, 7000);
                        break;
                    }
                    case EVENT_DISORIENTING_ROAR:
                    {
                        DoCastAOE(SPELL_DISORIENTING_ROAR);
                        events.ScheduleEvent(EVENT_DISORIENTING_ROAR, 11000);
                        break;
                    }
                }
            }

            DoMeleeAttackIfReady();
        }

        inline void EquipWeapon()
        {
            switch(currentWeapon = GetNextWeapon())
            {
                case WEAPON_SHIELD:
                {
                    SetEquipmentSlots(false, 0, 0,0);
                    me->MonsterYell(SAY_SHIELD_STANCE, LANG_UNIVERSAL, NULL);

                    for(uint32 i = 0; i <= sizeof(TwilightArcherSummonPos); i++)
                        me->SummonCreature(NPC_TWILIGHT_ARCHER, TwilightArcherSummonPos[i], TEMPSUMMON_MANUAL_DESPAWN);

                    DoCast(me, SPELL_SHIELD_VISUAL, true);
                    DoCast(me, SPELL_PERSONAL_PHALANX, true);
                    me->ModifyAuraState(AURA_STATE_UNKNOWN22, true);

                    events.ScheduleEvent(EVENT_PERSONAL_PHALANX, 1000);
                    break;
                }
                case WEAPON_SWORDS:
                {
                    SetEquipmentSlots(false, EQUIPMENT_ID_SWORD, EQUIPMENT_ID_SWORD,0);
                    me->MonsterYell(SAY_SWORDS_STANCE, LANG_UNIVERSAL, NULL);

                    DoCast(me, SPELL_DUAL_BLADES_BUFF, true);
                    DoCast(me, SPELL_TRASH_BUFF, true);

                    if(IsHeroic())
                        DoCast(me, SPELL_BURNING_FLAMES, true);

                    events.ScheduleEvent(EVENT_DISORIENTING_ROAR, 11000);
                    events.ScheduleEvent(EVENT_MIGHTY_STOMP, 15000);
                    break;
                }
                case WEAPON_MACE:
                {
                    SetEquipmentSlots(false, EQUIPMENT_ID_MACE, 0,0);
                    me->MonsterYell(SAY_MACE_STANCE, LANG_UNIVERSAL, NULL);

                    DoCast(me, SPELL_ENCUMBERED, true);

                    events.ScheduleEvent(EVENT_IMPALING_SLAM, 7000);
                    events.ScheduleEvent(EVENT_MIGHTY_STOMP, 15000);
                    break;
                }
            }

        }

        inline void ResetWeapon()
        {
            events.Reset();
            Summons.DespawnEntry(NPC_TWILIGHT_ARCHER);

            me->ModifyAuraState(AURA_STATE_UNKNOWN22, false);
            me->InterruptNonMeleeSpells(false, SPELL_PARALAX_TARGET);

            me->RemoveAura(SPELL_SHIELD_VISUAL);
            me->RemoveAura(SPELL_FLAMING_SHIELD);
            me->RemoveAura(SPELL_PERSONAL_PHALANX);

            me->RemoveAura(SPELL_DUAL_BLADES_BUFF);
            me->RemoveAura(SPELL_TRASH_BUFF);
            me->RemoveAura(SPELL_BURNING_FLAMES);

            me->RemoveAura(SPELL_ENCUMBERED);
        }

        inline uint8 GetNextWeapon()
        {
            uint8 base[3] = {WEAPON_SHIELD, WEAPON_SWORDS, WEAPON_MACE};

            if (phases[0]==0 && phases[1]==0 && phases[2]==0)
            {
                for(uint8 i = 0; i <= 2; i++)
                {
                    while(phases[i] == 0)
                    {
                        uint8 r = urand(0,2);
                        phases[i] = base[r];
                        base[r] = 0;
                    }
                }

                uint8 v = phases[0];
                phases[0] = 0;

                return v;
            }
            else
            {
                for(uint8 i = 0; i <= 2; i++)
                {
                    if(phases[i] != 0)
                    {
                        uint8 v = phases[i];
                        phases[i] = 0;

                        return v;
                    }
                }
            }

            return urand(WEAPON_SHIELD,WEAPON_MACE);
        }
    };
};

/*class mob_twilight_archer : public CreatureScript
{
public:
    mob_twilight_archer() : CreatureScript("mob_twilight_archer") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_twilight_archerAI (creature);
    }

    struct mob_twilight_archerAI : public ScriptedAI
    {
        mob_twilight_archerAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            DoZoneInCombat();
            events.ScheduleEvent(EVENT_ARCHER_SHOOT, urand(2500,10000));
        }

        void UpdateAI(const uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_ARCHER_SHOOT:
                    {
                        if (Unit* nearPlayer = SelectTarget(SELECT_TARGET_RANDOM, 0, 500.0f, true))
                            DoCast(nearPlayer,SPELL_FLAMING_ARROW,true);
                        events.ScheduleEvent(EVENT_ARCHER_SHOOT, urand(2500,10000));
                        break;
                    }
                }
            }
        }
    };
};*/

class spell_mighty_stomp_summon : public SpellScriptLoader
{
    public:
        spell_mighty_stomp_summon() : SpellScriptLoader("spell_mighty_stomp_summon") { }

        class spell_mighty_stomp_summon_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mighty_stomp_summon_SpellScript);

            bool Load()
            {
                if (!GetCaster()->GetInstanceScript())
                    return false;
                return true;
            }

            void HandleForceCast(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (!GetHitUnit())
                    return;

                float x, y, z;
                GetHitUnit()->GetPosition(x, y, z);
                GetCaster()->SummonCreature(NPC_CAVE_IN, x, y, z, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 4 * MINUTE * IN_MILLISECONDS);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_mighty_stomp_summon_SpellScript::HandleForceCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_mighty_stomp_summon_SpellScript();
        }
};

class spell_personal_phalanx_summon : public SpellScriptLoader
{
    public:
        spell_personal_phalanx_summon() : SpellScriptLoader("spell_personal_phalanx_summon") { }

        class spell_personal_phalanx_summon_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_personal_phalanx_summon_SpellScript);

            bool Load()
            {
                if (!GetCaster()->GetInstanceScript())
                    return false;
                return true;
            }

            void HandleForceCast(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (!GetHitUnit())
                    return;

                float x, y, z;
                GetHitUnit()->GetPosition(x, y, z);
                GetCaster()->SummonCreature(NPC_FIXATE_STALKER, x, y, z, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 4 * IN_MILLISECONDS);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_personal_phalanx_summon_SpellScript::HandleForceCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_personal_phalanx_summon_SpellScript();
        }
};

void AddSC_boss_forgemaster_throngus()
{
    new boss_forgemaster_throngus();
    //new mob_twilight_archer();
    new spell_mighty_stomp_summon();
    new spell_personal_phalanx_summon();
}