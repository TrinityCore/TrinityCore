/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
SDName: Urom
SD%Complete: 80
SDComment: Is not working SPELL_ARCANE_SHIELD. SPELL_FROSTBOMB has some issues, the damage aura should not stack.
SDCategory: Instance Script
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "oculus.h"
#include "SpellInfo.h"

enum Spells
{
    SPELL_ARCANE_SHIELD                           = 53813, //Dummy --> Channeled, shields the caster from damage.
    SPELL_EMPOWERED_ARCANE_EXPLOSION              = 51110,
    SPELL_EMPOWERED_ARCANE_EXPLOSION_2            = 59377,
    SPELL_FROSTBOMB                               = 51103, //Urom throws a bomb, hitting its target with the highest aggro which inflict directly 650 frost damage and drops a frost zone on the ground. This zone deals 650 frost damage per second and reduce the movement speed by 35%. Lasts 1 minute.
    SPELL_SUMMON_MENAGERIE                        = 50476, //Summons an assortment of creatures and teleports the caster to safety.
    SPELL_SUMMON_MENAGERIE_2                      = 50495,
    SPELL_SUMMON_MENAGERIE_3                      = 50496,
    SPELL_TELEPORT                                = 51112, //Teleports to the center of Oculus
    SPELL_TIME_BOMB                               = 51121, //Deals arcane damage to a random player, and after 6 seconds, deals zone damage to nearby equal to the health missing of the target afflicted by the debuff.
    SPELL_TIME_BOMB_2                             = 59376,
    SPELL_EVOCATE                                 = 51602 // He always cast it on reset or after teleportation
};

enum Yells
{
    SAY_SUMMON_1                                  = 0,
    SAY_SUMMON_2                                  = 1,
    SAY_SUMMON_3                                  = 2,
    SAY_AGGRO                                     = 3,
    EMOTE_ARCANE_EXPLOSION                        = 4,
    SAY_ARCANE_EXPLOSION                          = 5,
    SAY_DEATH                                     = 6,
    SAY_PLAYER_KILL                               = 7
};

enum Creatures
{
    NPC_PHANTASMAL_CLOUDSCRAPER                   = 27645,
    NPC_PHANTASMAL_MAMMOTH                        = 27642,
    NPC_PHANTASMAL_WOLF                           = 27644,

    NPC_PHANTASMAL_AIR                            = 27650,
    NPC_PHANTASMAL_FIRE                           = 27651,
    NPC_PHANTASMAL_WATER                          = 27653,

    NPC_PHANTASMAL_MURLOC                         = 27649,
    NPC_PHANTASMAL_NAGAL                          = 27648,
    NPC_PHANTASMAL_OGRE                           = 27647
};

struct Summons
{
    uint32 entry[4];
};

static Summons Group[]=
{
    { {NPC_PHANTASMAL_CLOUDSCRAPER, NPC_PHANTASMAL_CLOUDSCRAPER, NPC_PHANTASMAL_MAMMOTH, NPC_PHANTASMAL_WOLF} },
    { {NPC_PHANTASMAL_AIR, NPC_PHANTASMAL_AIR, NPC_PHANTASMAL_WATER, NPC_PHANTASMAL_FIRE} },
    { {NPC_PHANTASMAL_OGRE, NPC_PHANTASMAL_OGRE, NPC_PHANTASMAL_NAGAL, NPC_PHANTASMAL_MURLOC} }
};

static uint32 TeleportSpells[]=
{
    SPELL_SUMMON_MENAGERIE, SPELL_SUMMON_MENAGERIE_2, SPELL_SUMMON_MENAGERIE_3
};

class boss_urom : public CreatureScript
{
    public:
        boss_urom() : CreatureScript("boss_urom") { }

        struct boss_uromAI : public BossAI
        {
            boss_uromAI(Creature* creature) : BossAI(creature, DATA_UROM)
            {
                platform = 0;

                for (uint8 i = 0; i < 3; ++i)
                    group[i] = i;

                std::random_shuffle(group, group + 3);
            }

            void Reset() OVERRIDE
            {
                me->CastSpell(me, SPELL_EVOCATE);

                _Reset();

                x = 0.0f;
                y = 0.0f;
                canCast = false;
                canGoBack = false;

                me->GetMotionMaster()->MoveIdle();

                teleportTimer = urand(30000, 35000);
                arcaneExplosionTimer = 9000;
                castArcaneExplosionTimer = 2000;
                frostBombTimer = urand(5000, 8000);
                timeBombTimer = urand(20000, 25000);
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                _EnterCombat();

                StartAttack();
            }

            void AttackStart(Unit* who) OVERRIDE
            {
                if (!who)
                    return;

                if (me->GetPositionZ() > 518.63f)
                    DoStartNoMovement(who);
                else
                    BossAI::AttackStart(who);
            }

            void SetPosition(uint8 i)
            {
                switch (i)
                {
                    case 0:
                        x = me->GetPositionX() + 4;
                        y = me->GetPositionY() - 4;
                        break;
                    case 1:
                        x = me->GetPositionX() + 4;
                        y = me->GetPositionY() + 4;
                        break;
                    case 2:
                        x = me->GetPositionX() - 4;
                        y = me->GetPositionY() + 4;
                        break;
                    case 3:
                        x = me->GetPositionX() - 4;
                        y = me->GetPositionY() - 4;
                        break;
                    default:
                        break;
                }
            }

            void StartAttack()
            {
                if (platform > 2)
                {
                    Talk(SAY_AGGRO);
                    return;
                }

                // summon guards and jump to next platform
                for (uint8 i = 0; i < 4; ++i)
                {
                    SetPosition(i);
                    me->SummonCreature(Group[group[platform]].entry[i], x, y, me->GetPositionZ(), me->GetOrientation());
                }

                Talk(platform);
                DoCast(TeleportSpells[platform]);

                ++platform;
            }

            void KilledUnit(Unit* who) OVERRIDE
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_PLAYER_KILL);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                if (platform < 3)
                    return;

                events.Update(diff);

                if (teleportTimer <= diff)
                {
                    me->InterruptNonMeleeSpells(false);
                    me->GetMotionMaster()->MoveIdle();
                    DoCast(SPELL_TELEPORT);
                    teleportTimer = urand(30000, 35000);
                }
                else
                    teleportTimer -= diff;

                if (canCast && !me->FindCurrentSpellBySpellId(SPELL_EMPOWERED_ARCANE_EXPLOSION))
                {
                    if (castArcaneExplosionTimer <= diff)
                    {
                        canCast = false;
                        canGoBack = true;
                        DoCastAOE(SPELL_EMPOWERED_ARCANE_EXPLOSION);
                        castArcaneExplosionTimer = 2000;
                    }
                    else
                        castArcaneExplosionTimer -= diff;
                }

                if (canGoBack)
                {
                    if (arcaneExplosionTimer <= diff)
                    {
                        Position pos;
                        me->EnsureVictim()->GetPosition(&pos);

                        me->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation());
                        me->GetMotionMaster()->MoveChase(me->GetVictim());
                        me->SetWalk(true);

                        Talk(EMOTE_ARCANE_EXPLOSION);
                        Talk(SAY_ARCANE_EXPLOSION);

                        canCast = false;
                        canGoBack = false;
                        arcaneExplosionTimer = 9000;
                    }
                    else
                        arcaneExplosionTimer -= diff;
                }

                if (!me->IsNonMeleeSpellCast(false, true, true))
                {
                    if (frostBombTimer <= diff)
                    {
                        DoCastVictim(SPELL_FROSTBOMB);
                        frostBombTimer = urand(5000, 8000);
                    }
                    else
                        frostBombTimer -= diff;

                    if (timeBombTimer <= diff)
                    {
                        if (Unit* unit = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(unit, SPELL_TIME_BOMB);

                        timeBombTimer = urand(20000, 25000);
                    }
                    else
                        timeBombTimer -= diff;
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                _JustDied();
                Talk(SAY_DEATH);
                DoCast(me, SPELL_DEATH_SPELL, true); // we cast the spell as triggered or the summon effect does not occur
            }

            void LeaveCombat()
            {
                me->RemoveAllAuras();
                me->CombatStop(false);
                me->DeleteThreatList();
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) OVERRIDE
            {
                switch (spellInfo->Id)
                {
                    case SPELL_SUMMON_MENAGERIE:
                        me->SetHomePosition(968.66f, 1042.53f, 527.32f, 0.077f);
                        LeaveCombat();
                        me->CastSpell(me, SPELL_EVOCATE);
                        break;
                    case SPELL_SUMMON_MENAGERIE_2:
                        me->SetHomePosition(1164.02f, 1170.85f, 527.321f, 3.66f);
                        LeaveCombat();
                        me->CastSpell(me, SPELL_EVOCATE);
                        break;
                    case SPELL_SUMMON_MENAGERIE_3:
                        me->SetHomePosition(1118.31f, 1080.377f, 508.361f, 4.25f);
                        LeaveCombat();
                        me->CastSpell(me, SPELL_EVOCATE);
                        break;
                    case SPELL_TELEPORT:
                        //! Unconfirmed, previous below
                        me->SetDisableGravity(true);
                        //me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY); // with out it the npc will fall down while is casting
                        canCast = true;
                        break;
                    default:
                        break;
                }
            }

        private:
            float x, y;

            bool canCast;
            bool canGoBack;

            uint8 platform;

            uint8 group[3];

            uint32 teleportTimer;
            uint32 arcaneExplosionTimer;
            uint32 castArcaneExplosionTimer;
            uint32 frostBombTimer;
            uint32 timeBombTimer;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetOculusAI<boss_uromAI>(creature);
        }
};

void AddSC_boss_urom()
{
    new boss_urom();
}
