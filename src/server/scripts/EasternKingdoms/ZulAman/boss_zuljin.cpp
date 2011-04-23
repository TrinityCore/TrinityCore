/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_ZulJin
SD%Complete: 85%
SDComment:
EndScriptData */

#include "ScriptPCH.h"
#include "zulaman.h"

//Speech
const char* YELL_TRANSFORM_TO_LYNX = "Let me introduce to you my new bruddahs: fang and claw!";
#define SOUND_TRANSFORM_TO_LYNX 12094

const char* YELL_TRANSFORM_TO_BEAR = "Got me some new tricks...like me bruddah bear!";
#define SOUND_TRANSFORM_TO_BEAR 12092

const char* YELL_TRANSFORM_TO_DRAGONHAWK = "Ya don' have to look to da sky to see da dragonhawk!";
#define SOUND_TRANSFORM_TO_DRAGONHAWK 12095

const char* YELL_TRANSFORM_TO_EAGLE = "Dere be no hidin' from da eagle!";
#define SOUND_TRANSFORM_TO_EAGLE 12093

#define YELL_KILL_ONE "Da Amani de chuka!"
#define SOUND_KILL_ONE 12098

#define YELL_KILL_TWO "Lot more gonna fall like you!"
#define SOUND_KILL_TWO 12099

#define YELL_FIRE_BREATH "Fire kill you just as quick!"
#define SOUND_FIRE_BRETH 12096

#define YELL_AGGRO "Nobody badduh dan me!"
#define SOUND_AGGRO 12091

#define YELL_BERSERK "You too slow! Me too strong!"
#define SOUND_BERSERK 12097

#define YELL_DEATH "Mebbe me fall...but da Amani empire...never gonna die..."
#define SOUND_DEATH 12100

//Still not used, need more info
#define YELL_INTRO "Everybody always wanna take from us. Now we gonna start takin' back. Anybody who get in our way...gonna drown in their own blood! De Amani empire be back now...seekin' vengeance. And we gonna start...with you!"
#define SOUND_INTRO 12090

//Spells:
//====== Troll Form
#define SPELL_WHIRLWIND             17207
#define SPELL_GRIEVOUS_THROW        43093   // remove debuff after full healed
//====== Bear Form
#define SPELL_CREEPING_PARALYSIS    43095   // should cast on the whole raid
#define SPELL_OVERPOWER             43456   // use after melee attack dodged
//====== Eagle Form
#define SPELL_ENERGY_STORM          43983   // enemy area aura, trigger 42577
#define SPELL_ZAP_INFORM            42577
#define SPELL_ZAP_DAMAGE            43137   // 1250 damage
#define SPELL_SUMMON_CYCLONE        43112   // summon four feather vortex
#define CREATURE_FEATHER_VORTEX     24136
#define SPELL_CYCLONE_VISUAL        43119   // trigger 43147 visual
#define SPELL_CYCLONE_PASSIVE       43120   // trigger 43121 (4y aoe) every second
//Lynx Form
#define SPELL_CLAW_RAGE_HASTE       42583
#define SPELL_CLAW_RAGE_TRIGGER     43149
#define SPELL_CLAW_RAGE_DAMAGE      43150
#define SPELL_LYNX_RUSH_HASTE       43152
#define SPELL_LYNX_RUSH_DAMAGE      43153
//Dragonhawk Form
#define SPELL_FLAME_WHIRL           43213   // trigger two spells
#define SPELL_FLAME_BREATH          43215
#define SPELL_SUMMON_PILLAR         43216   // summon 24187
#define CREATURE_COLUMN_OF_FIRE     24187
#define SPELL_PILLAR_TRIGGER        43218   // trigger 43217

//cosmetic
#define SPELL_SPIRIT_AURA           42466
#define SPELL_SIPHON_SOUL           43501

//Transforms:
#define SPELL_SHAPE_OF_THE_BEAR     42594   // 15% dmg
#define SPELL_SHAPE_OF_THE_EAGLE    42606
#define SPELL_SHAPE_OF_THE_LYNX     42607   // haste melee 30%
#define SPELL_SHAPE_OF_THE_DRAGONHAWK   42608

#define SPELL_BERSERK 45078

#define PHASE_BEAR 0
#define PHASE_EAGLE 1
#define PHASE_LYNX 2
#define PHASE_DRAGONHAWK 3
#define PHASE_TROLL 4

//coords for going for changing form
#define CENTER_X 120.148811f
#define CENTER_Y 703.713684f
#define CENTER_Z 45.111477f

struct SpiritInfoStruct
{
    uint32 entry;
    float x, y, z, orient;
};

static SpiritInfoStruct SpiritInfo[4] =
{
    {23878, 147.87f, 706.51f, 45.11f, 3.04f},
    {23880, 88.95f, 705.49f, 45.11f, 6.11f},
    {23877, 137.23f, 725.98f, 45.11f, 3.71f},
    {23879, 104.29f, 726.43f, 45.11f, 5.43f}
};

struct TransformStruct
{
    uint32 sound;
    std::string text;
    uint32 spell, unaura;
};

static TransformStruct Transform[4] =
{
    {SOUND_TRANSFORM_TO_BEAR, YELL_TRANSFORM_TO_BEAR, SPELL_SHAPE_OF_THE_BEAR, SPELL_WHIRLWIND},
    {SOUND_TRANSFORM_TO_EAGLE, YELL_TRANSFORM_TO_EAGLE, SPELL_SHAPE_OF_THE_EAGLE, SPELL_SHAPE_OF_THE_BEAR},
    {SOUND_TRANSFORM_TO_LYNX, YELL_TRANSFORM_TO_LYNX, SPELL_SHAPE_OF_THE_LYNX, SPELL_SHAPE_OF_THE_EAGLE},
    {SOUND_TRANSFORM_TO_DRAGONHAWK, YELL_TRANSFORM_TO_DRAGONHAWK, SPELL_SHAPE_OF_THE_DRAGONHAWK, SPELL_SHAPE_OF_THE_LYNX}
};

class boss_zuljin : public CreatureScript
{
    public:

        boss_zuljin()
            : CreatureScript("boss_zuljin")
        {
        }

        struct boss_zuljinAI : public ScriptedAI
        {
            boss_zuljinAI(Creature *c) : ScriptedAI(c), Summons(me)
            {
                pInstance = c->GetInstanceScript();
            }
            InstanceScript *pInstance;

            uint64 SpiritGUID[4];
            uint64 ClawTargetGUID;
            uint64 TankGUID;

            uint32 Phase;
            uint32 health_20;

            uint32 Intro_Timer;
            uint32 Berserk_Timer;

            uint32 Whirlwind_Timer;
            uint32 Grievous_Throw_Timer;

            uint32 Creeping_Paralysis_Timer;
            uint32 Overpower_Timer;

            uint32 Claw_Rage_Timer;
            uint32 Lynx_Rush_Timer;
            uint32 Claw_Counter;
            uint32 Claw_Loop_Timer;

            uint32 Flame_Whirl_Timer;
            uint32 Flame_Breath_Timer;
            uint32 Pillar_Of_Fire_Timer;

            SummonList Summons;

            void Reset()
            {
                if (pInstance)
                    pInstance->SetData(DATA_ZULJINEVENT, NOT_STARTED);

                Phase = 0;

                health_20 = me->CountPctFromMaxHealth(20);

                Intro_Timer = 37000;
                Berserk_Timer = 600000;

                Whirlwind_Timer = 7000;
                Grievous_Throw_Timer = 8000;

                Creeping_Paralysis_Timer = 7000;
                Overpower_Timer = 0;

                Claw_Rage_Timer = 5000;
                Lynx_Rush_Timer = 14000;
                Claw_Loop_Timer = 0;
                Claw_Counter = 0;

                Flame_Whirl_Timer = 5000;
                Flame_Breath_Timer = 6000;
                Pillar_Of_Fire_Timer = 7000;

                ClawTargetGUID = 0;
                TankGUID = 0;

                Summons.DespawnAll();

                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, 47174);
                //me->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO, 218172674);
                //me->SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_MELEE);
            }

            void EnterCombat(Unit * /*who*/)
            {
                if (pInstance)
                    pInstance->SetData(DATA_ZULJINEVENT, IN_PROGRESS);

                DoZoneInCombat();

                me->MonsterYell(YELL_INTRO, LANG_UNIVERSAL, 0);
                DoPlaySoundToSet(me, SOUND_INTRO);
                SpawnAdds();
                EnterPhase(0);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                if (Intro_Timer)
                    return;

                switch (urand(0,1))
                {
                    case 0:
                        me->MonsterYell(YELL_KILL_ONE, LANG_UNIVERSAL, 0);
                        DoPlaySoundToSet(me, SOUND_KILL_ONE);
                        break;
                    case 1:
                        me->MonsterYell(YELL_KILL_TWO, LANG_UNIVERSAL, 0);
                        DoPlaySoundToSet(me, SOUND_KILL_TWO);
                        break;
                }
            }

            void JustDied(Unit* /*Killer*/)
            {
                if (pInstance)
                    pInstance->SetData(DATA_ZULJINEVENT, DONE);

                me->MonsterYell(YELL_DEATH, LANG_UNIVERSAL, 0);
                DoPlaySoundToSet(me, SOUND_DEATH);
                Summons.DespawnEntry(CREATURE_COLUMN_OF_FIRE);

                if (Unit *Temp = Unit::GetUnit(*me, SpiritGUID[3]))
                    Temp->SetUInt32Value(UNIT_FIELD_BYTES_1,UNIT_STAND_STATE_DEAD);
            }

            void AttackStart(Unit *who)
            {
                if (Phase == 2)
                    AttackStartNoMove(who);
                else
                    ScriptedAI::AttackStart(who);
            }

            void DoMeleeAttackIfReady()
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    if (me->isAttackReady() && me->IsWithinMeleeRange(me->getVictim()))
                    {
                        if (Phase == 1 && !Overpower_Timer)
                        {
                            uint32 health = me->getVictim()->GetHealth();
                            me->AttackerStateUpdate(me->getVictim());
                            if (me->getVictim() && health == me->getVictim()->GetHealth())
                            {
                                DoCast(me->getVictim(), SPELL_OVERPOWER, false);
                                Overpower_Timer = 5000;
                            }
                        } else me->AttackerStateUpdate(me->getVictim());
                        me->resetAttackTimer();
                    }
                }
            }

            void SpawnAdds()
            {
                Creature *pCreature = NULL;
                for (uint8 i = 0; i < 4; ++i)
                {
                    pCreature = me->SummonCreature(SpiritInfo[i].entry, SpiritInfo[i].x, SpiritInfo[i].y, SpiritInfo[i].z, SpiritInfo[i].orient, TEMPSUMMON_DEAD_DESPAWN, 0);
                    if (pCreature)
                    {
                        pCreature->CastSpell(pCreature, SPELL_SPIRIT_AURA, true);
                        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        SpiritGUID[i] = pCreature->GetGUID();
                    }
                }
            }

            void DespawnAdds()
            {
                for (uint8 i = 0; i < 4; ++i)
                {
                    Unit* Temp = NULL;
                    if (SpiritGUID[i])
                    {
                        Temp = Unit::GetUnit(*me, SpiritGUID[i]);
                        if (Temp)
                        {
                            Temp->SetVisible(false);
                            Temp->setDeathState(DEAD);
                        }
                    }
                    SpiritGUID[i] = 0;
                }
            }

            void JustSummoned(Creature *summon)
            {
                Summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature *summon)
            {
                Summons.Despawn(summon);
            }

            void EnterPhase(uint32 NextPhase)
            {
                switch(NextPhase)
                {
                case 0:
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                    DoTeleportTo(CENTER_X, CENTER_Y, CENTER_Z, 100);
                    DoResetThreat();
                    me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, 0);
                    me->RemoveAurasDueToSpell(Transform[Phase].unaura);
                    DoCast(me, Transform[Phase].spell);
                    me->MonsterYell(Transform[Phase].text.c_str(), LANG_UNIVERSAL, 0);
                    DoPlaySoundToSet(me, Transform[Phase].sound);
                    if (Phase > 0)
                    {
                        if (Unit *Temp = Unit::GetUnit(*me, SpiritGUID[Phase - 1]))
                            Temp->SetUInt32Value(UNIT_FIELD_BYTES_1,UNIT_STAND_STATE_DEAD);
                    }
                    if (Unit *Temp = Unit::GetUnit(*me, SpiritGUID[NextPhase - 1]))
                        Temp->CastSpell(me, SPELL_SIPHON_SOUL, false); // should m cast on temp
                    if (NextPhase == 2)
                    {
                        me->GetMotionMaster()->Clear();
                        DoCast(me, SPELL_ENERGY_STORM, true); // enemy aura
                        for (uint8 i = 0; i < 4; ++i)
                        {
                            Creature* Vortex = DoSpawnCreature(CREATURE_FEATHER_VORTEX, 0, 0, 0, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                            if (Vortex)
                            {
                                Vortex->CastSpell(Vortex, SPELL_CYCLONE_PASSIVE, true);
                                Vortex->CastSpell(Vortex, SPELL_CYCLONE_VISUAL, true);
                                Vortex->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                Vortex->SetSpeed(MOVE_RUN, 1.0f);
                                Vortex->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0));
                                DoZoneInCombat(Vortex);
                            }
                        }
                    }
                    else
                        me->AI()->AttackStart(me->getVictim());
                    if (NextPhase == 3)
                    {
                        me->RemoveAurasDueToSpell(SPELL_ENERGY_STORM);
                        Summons.DespawnEntry(CREATURE_FEATHER_VORTEX);
                        me->GetMotionMaster()->MoveChase(me->getVictim());
                    }
                    break;
                default:
                    break;
                }
                Phase = NextPhase;
            }

            void UpdateAI(const uint32 diff)
            {
                if (!TankGUID)
                {
                    if (!UpdateVictim())
                        return;

                    if (me->GetHealth() < health_20 * (4 - Phase))
                        EnterPhase(Phase + 1);
                }

                if (Berserk_Timer <= diff)
                {
                    DoCast(me, SPELL_BERSERK, true);
                    me->MonsterYell(YELL_BERSERK, LANG_UNIVERSAL, 0);
                    DoPlaySoundToSet(me, SOUND_BERSERK);
                    Berserk_Timer = 60000;
                } else Berserk_Timer -= diff;

                switch (Phase)
                {
                case 0:
                    if (Intro_Timer)
                    {
                        if (Intro_Timer <= diff)
                        {
                            me->MonsterYell(YELL_AGGRO, LANG_UNIVERSAL, 0);
                            DoPlaySoundToSet(me, SOUND_AGGRO);
                            Intro_Timer = 0;
                        } else Intro_Timer -= diff;
                    }

                    if (Whirlwind_Timer <= diff)
                    {
                        DoCast(me, SPELL_WHIRLWIND);
                        Whirlwind_Timer = 15000 + rand()%5000;
                    } else Whirlwind_Timer -= diff;

                    if (Grievous_Throw_Timer <= diff)
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(pTarget, SPELL_GRIEVOUS_THROW, false);
                        Grievous_Throw_Timer = 10000;
                    } else Grievous_Throw_Timer -= diff;
                    break;

                case 1:
                    if (Creeping_Paralysis_Timer <= diff)
                    {
                        DoCast(me, SPELL_CREEPING_PARALYSIS);
                        Creeping_Paralysis_Timer = 20000;
                    } else Creeping_Paralysis_Timer -= diff;

                    if (Overpower_Timer <= diff)
                    {
                        // implemented in DoMeleeAttackIfReady()
                        Overpower_Timer = 0;
                    } else Overpower_Timer -= diff;
                    break;

                case 2:
                    return;

                case 3:
                    if (Claw_Rage_Timer <= diff)
                    {
                        if (!TankGUID)
                        {
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                TankGUID = me->getVictim()->GetGUID();
                                me->SetSpeed(MOVE_RUN, 5.0f);
                                AttackStart(pTarget); // change victim
                                Claw_Rage_Timer = 0;
                                Claw_Loop_Timer = 500;
                                Claw_Counter = 0;
                            }
                        }
                        else if (!Claw_Rage_Timer) // do not do this when Lynx_Rush
                        {
                            if (Claw_Loop_Timer <= diff)
                            {
                                Unit *pTarget = me->getVictim();
                                if (!pTarget || !pTarget->isTargetableForAttack()) pTarget = Unit::GetUnit(*me, TankGUID);
                                if (!pTarget || !pTarget->isTargetableForAttack()) pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                                if (pTarget)
                                {
                                    AttackStart(pTarget);
                                    if (me->IsWithinMeleeRange(pTarget))
                                    {
                                        DoCast(pTarget, SPELL_CLAW_RAGE_DAMAGE, true);
                                        ++Claw_Counter;
                                        if (Claw_Counter == 12)
                                        {
                                            Claw_Rage_Timer = 15000 + rand()%5000;
                                            me->SetSpeed(MOVE_RUN, 1.2f);
                                            AttackStart(Unit::GetUnit(*me, TankGUID));
                                            TankGUID = 0;
                                            return;
                                        }
                                        else
                                            Claw_Loop_Timer = 500;
                                    }
                                }
                                else
                                {
                                    EnterEvadeMode(); // if (pTarget)
                                    return;
                                }
                            } else Claw_Loop_Timer -= diff;
                        } //if (TankGUID)
                    } else Claw_Rage_Timer -= diff;

                    if (Lynx_Rush_Timer <= diff)
                    {
                        if (!TankGUID)
                        {
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                TankGUID = me->getVictim()->GetGUID();
                                me->SetSpeed(MOVE_RUN, 5.0f);
                                AttackStart(pTarget); // change victim
                                Lynx_Rush_Timer = 0;
                                Claw_Counter = 0;
                            }
                        }
                        else if (!Lynx_Rush_Timer)
                        {
                            Unit *pTarget = me->getVictim();
                            if (!pTarget || !pTarget->isTargetableForAttack())
                            {
                                pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                                AttackStart(pTarget);
                            }
                            if (pTarget)
                            {
                                if (me->IsWithinMeleeRange(pTarget))
                                {
                                    DoCast(pTarget, SPELL_LYNX_RUSH_DAMAGE, true);
                                    ++Claw_Counter;
                                    if (Claw_Counter == 9)
                                    {
                                        Lynx_Rush_Timer = 15000 + rand()%5000;
                                        me->SetSpeed(MOVE_RUN, 1.2f);
                                        AttackStart(Unit::GetUnit(*me, TankGUID));
                                        TankGUID = 0;
                                    }
                                    else
                                        AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0));
                                }
                            }
                            else
                            {
                                EnterEvadeMode(); // if (pTarget)
                                return;
                            }
                        } //if (TankGUID)
                    } else Lynx_Rush_Timer -= diff;

                    break;
                case 4:
                    if (Flame_Whirl_Timer <= diff)
                    {
                        DoCast(me, SPELL_FLAME_WHIRL);
                        Flame_Whirl_Timer = 12000;
                    }Flame_Whirl_Timer -= diff;

                    if (Pillar_Of_Fire_Timer <= diff)
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_SUMMON_PILLAR);
                        Pillar_Of_Fire_Timer = 10000;
                    } else Pillar_Of_Fire_Timer -= diff;

                    if (Flame_Breath_Timer <= diff)
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            me->SetInFront(pTarget);
                        DoCast(me, SPELL_FLAME_BREATH);
                        Flame_Breath_Timer = 10000;
                    } else Flame_Breath_Timer -= diff;
                    break;

                default:
                    break;
                }

                if (!TankGUID)
                    DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_zuljinAI(creature);
        }
};

class mob_zuljin_vortex : public CreatureScript
{
    public:

        mob_zuljin_vortex()
            : CreatureScript("mob_zuljin_vortex")
        {
        }

        struct mob_zuljin_vortexAI : public ScriptedAI
        {
            mob_zuljin_vortexAI(Creature *c) : ScriptedAI(c) {}

            void Reset() {}

            void EnterCombat(Unit * /*pTarget*/) {}

            void SpellHit(Unit *caster, const SpellEntry *spell)
            {
                if (spell->Id == SPELL_ZAP_INFORM)
                    DoCast(caster, SPELL_ZAP_DAMAGE, true);
            }

            void UpdateAI(const uint32 /*diff*/)
            {
                //if the vortex reach the target, it change his target to another player
                if (me->IsWithinMeleeRange(me->getVictim()))
                    AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0));
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_zuljin_vortexAI(creature);
        }
};

void AddSC_boss_zuljin()
{
    new boss_zuljin();
    new mob_zuljin_vortex();
}

