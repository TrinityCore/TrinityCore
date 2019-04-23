/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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


#include "bastion_of_twilight.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"

#define SAY_AGGRO1       "Valiona, Theralion, put them in their place."
#define SOU_AGGRO1       22063
#define SAY_AGGRO2       "Do as the master commands, Theralion! Kill them!"
#define SOU_AGGRO2       21894
#define SAY_AGGRO3       "The master was clearly speaking to you, Valiona. I am far too busy to attack ANYONE."
#define SOU_AGGRO3       20300
#define SAY_AGGRO4       "You are worthless, Theralion!"
#define SOU_AGGRO4       21895
#define SAY_AGGRO5       "How dare you call me worthless! You will see why I am Mother's favored child!"
#define SOU_AGGRO5       20301
#define SAY_THER_KILL    "Bare your soul to me, mortal."
#define SOU_THER_KILL    20302
#define SAY_VAL_KILL     "Breathe your dying breath!"
#define SOU_VAL_KILL     21896
#define SAY_THER_ENG     "Writhe in AGONY!"
#define SOU_THER_ENG     20306
#define SOU_THER_LAU     20307
#define SAY_VAL_ENG      "Theralion! I will engulf the Hallway! Cover their escape!"
#define SOU_VAL_ENG      21898
#define SAY_VAL_BLA      "Enter Twilight!"
#define SOU_VAL_BLA      21899
#define SAY_THER_DAZ     "You are not the boss of me Valiona! I will engulf as I please!"
#define SOU_THER_DAZ     20304
#define SAY_THER_DA2    "There is no escape from the fury of the Twilight Flight!"
#define SOU_THER_DA2     20305
#define SAY_THER_DEA    "I knew I should have stayed out of this..."
#define SOU_THER_DEA     20303
#define SAY_VAL_DEA     "At least Theralion dies with me..."
#define SOU_VAL_DEA      21897



#define MAX_DAZZLIN_DESTRUCTION 6

enum BossPhases
{
    PHASE_NONE                                    = 0,
    PHASE_VALIONA_LAND                            = 1,
    PHASE_VALIONA_FLY                             = 2,
    PHASE_TERALION_LAND                           = 3,
    PHASE_THERALION_FLY                           = 4
};

enum BossActions
{
    ACTION_0                                      = 0,
    ACTION_VALIONA_LAND                           = 1,
    ACTION_VALIONA_FLY                            = 2,
    ACTION_THERALION_LAND                         = 3,
    ACTION_THERALION_FLY                          = 4,
    ACTION_VALIONA_LAND_MOVE                      = 5,
    ACTION_EMOTE_BREATH                           = 6,
};

enum Points
{
    POINT_THERALION_HOME                          = 50,
    POINT_VALIONA_HOME                            = 51,

    POINT_VALIONA_ABOVE_HOME                      = 52,

    POINT_CENTER_ROOM                             = 53,
    POINT_THERALION_ABOVE_HOME                    = 54,
};

Position const flightpoints[2] =
{
    {-740.000f,  -600.000f, 862.000f, 0.0f   }, //behind valiona
    {-740.665f,  -770.682f, 862.000f, 0.0f   }, //behind theralion
};

Position const flamepoints[9] =
{
    {-760.000f,  -600.000f, 837.000f, 0.0f   }, //0
    {-760.665f,  -620.682f, 837.000f, 0.0f   }, //1
    {-760.665f,  -640.682f, 836.700f, 0.0f   }, //2
    {-760.665f,  -660.682f, 836.700f, 0.0f   }, //3
    {-760.665f,  -680.682f, 832.000f, 0.0f   }, //4
    {-760.665f,  -700.682f, 835.000f, 0.0f   }, //5
    {-760.665f,  -720.682f, 835.000f, 0.0f   }, //6
    {-760.665f,  -740.682f, 837.000f, 0.0f   }, //7
    {-760.665f,  -760.682f, 837.000f, 0.0f   }, //8
};

enum valionaEvents
{
    EVENT_NONE                                    = 0,
    EVENT_BLACKOUT,
    EVENT_DEVOURING_FLAMES,
    EVENT_TWILIGHT_SHIFT,
    EVENT_DAZZLING_DESTRUCTION,
    EVENT_THERALION_LAND,
    EVENT_THERALION_TWILIGHT_BLASE,
};

enum theralionEvents
{
    EVENT_0                                       = 0,
    EVENT_INTRO,
    EVENT_ENGULFING_MAGIC,
    EVENT_TWILIGHT_SHIFT_THERALION,
    EVENT_FABULOUS_FLAMES,
    EVENT_VALIONA_LAND,
    EVENT_VALIONA_TWILIGHT_METEORITE,
    EVENT_VALIONA_TWILIGHT_BREATH,
    EVENT_VALIONA_TWILIGHT_SPAWN,
};

class boss_theralion : public CreatureScript
{
    public:
        boss_theralion() : CreatureScript("boss_theralion") {}

        struct boss_theralionAI : public BossAI
        {
            boss_theralionAI(Creature * creature) : BossAI(creature, DATA_THERALION), summons(me)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            SummonList summons;
            uint32 phase;
            uint32 killtimer;
            uint8  breathcount;
            uint8  spawncount;
            uint8  talkcount;
            int    spost;
            bool   forw;
            bool   introDone;

            void InitializeAI() override
            {
                introDone = false;
            }

            void SetFlyState(bool fly)
            {
                me->SetDisableGravity(fly);
                me->SetHover(fly);
                me->SetCanFly(fly);
                if (fly)
                {
                    me->SetSpeed(MOVE_FLIGHT, 3.0f);
                    me->SetReactState(REACT_PASSIVE);
                    me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
                }
                else
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_FLYING);
                }
            }

            /*void MoveInLineOfSight(Unit* who) override
            {
                if (!introDone && me->IsWithinDistInMap(who, 70.0f))
                {
                    Unit *chogall = instance->GetCreature(DATA_CHOGALL));
                    if (chogall)
                        chogall->Yell(SAY_AGGRO1, LANG_UNIVERSAL);
                    DoPlaySoundToSet(me, SOU_AGGRO1);
                    events.ScheduleEvent(EVENT_INTRO, 5000, 0, 0);
                    talkcount =0;
                    introDone = true;
                }
            }*/

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() ==  NPC_FABOLOUS_FLAME)
                {
                    summon->CastSpell(summon, SPELL_FABOLOUS_FLAME_VISUAL, true);
                    DoZoneInCombat(summon);
                    summon->setFaction(me->getFaction());
                    summon->SetReactState(REACT_PASSIVE);
                    summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    summon->AttackStop();
                    summon->StopMoving();
                }

                summons.Summon(summon);
            }

            void Reset() override
            {
                events.Reset();
                phase = PHASE_NONE;
                summons.DespawnAll();
                me->LowerPlayerDamageReq(me->GetMaxHealth());

                //me->SetHealth(me->GetMaxHealth());
                //me->GetMotionMaster()->MovePoint(POINT_THERALION_HOME, me->GetHomePosition());

                if (instance)
                {
                    instance->SetData(DATA_VALIONA_TERALION_HP, me->GetMaxHealth());
                    instance->SetData(DATA_VALIONA_THERALION_EVENT, NOT_STARTED);
                }
            }

            void JustReachedHome() override
            {
                SetFlyState(false);
                me->SetOrientation(me->GetHomePosition().GetOrientation());
            }

            void MovementInform(uint32 type, uint32 point) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case POINT_CENTER_ROOM:
                        // Schedule Events
                        me->Attack(me->GetVictim(), true);
                        me->AI()->AttackStart(me->GetVictim());
                        SetFlyState(false);
                        me->GetMotionMaster()->MoveChase(me->GetVictim(), 1.0f, 1.0f);
                        events.ScheduleEvent(EVENT_ENGULFING_MAGIC, urand(15000, 20000), 0, 0);
                        events.ScheduleEvent(EVENT_TWILIGHT_SHIFT_THERALION, 6000, 0, 0);
                        events.ScheduleEvent(EVENT_FABULOUS_FLAMES, urand(10000, 15000), 0, 0);
                        events.ScheduleEvent(EVENT_VALIONA_LAND, 95000, 0, 0);
                        events.ScheduleEvent(EVENT_VALIONA_TWILIGHT_BREATH, 60000, 0, 0);
                        events.ScheduleEvent(EVENT_VALIONA_TWILIGHT_METEORITE, urand(5000, 8000), 0, 0);
                        breathcount = 0;
                    case POINT_THERALION_HOME:
                        SetFlyState(false);
                        break;
                }
            }

            void DoAction(int32 actionId) override
            {
                switch (actionId)
                {
                    case ACTION_THERALION_LAND:
                        phase = PHASE_TERALION_LAND;
                        me->GetMotionMaster()->MovePoint(POINT_CENTER_ROOM, -741.23f, -686.75, 831.88f);
                        break;
                    case ACTION_THERALION_FLY:
                        events.CancelEvent(EVENT_FABULOUS_FLAMES);
                        events.CancelEvent(EVENT_TWILIGHT_SHIFT_THERALION);
                        events.CancelEvent(EVENT_ENGULFING_MAGIC);
                        events.CancelEvent(EVENT_VALIONA_LAND);
                        events.CancelEvent(EVENT_VALIONA_TWILIGHT_METEORITE);
                        events.CancelEvent(EVENT_VALIONA_TWILIGHT_BREATH);

                        phase = PHASE_THERALION_FLY;
                        SetFlyState(true);
                        me->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 20.0f);
                        break;
                }
            }

            void DamageTaken(Unit* /*who*/, uint32&damage) override
            {
                if (!me || !me->IsAlive())
                    return;

                if (instance){
                    instance->SetData(DATA_VALIONA_TERALION_HP, me->GetHealth() >= damage ? me->GetHealth() - damage : 0);
                    }

                if (damage > me->GetHealth() )
                {//teleport to center when dying
                    SetFlyState(false);
                    me->NearTeleportTo(-741.23f, -706.75, 831.88f, 0);
                    me->Yell(SAY_THER_DEA, LANG_UNIVERSAL);
                    DoPlaySoundToSet(me, SOU_THER_DEA);
                    /*Unit *valiona = instance->GetCreature(DATA_VALIONA));
                    if (valiona && valiona->IsAlive())
                    {
                        who->DealDamage(valiona,2);
                        me->Yell(SAY_THER_DEA, LANG_UNIVERSAL);
                        DoPlaySoundToSet(me, SOU_THER_DEA);
                    }*/
                }
            }

            void EnterCombat(Unit* victim) override
            {
                DoZoneInCombat(me);

                if (Creature* valiona = instance->GetCreature(DATA_VALIONA))
                {
                    if (!valiona->IsInCombat())
                    {
                        valiona->Attack(victim, false);
                        DoZoneInCombat(valiona);
                        valiona->AttackStop();

                        if (valiona->AI())
                            valiona->AI()->DoAction(ACTION_VALIONA_FLY);
                    }
                }

                if (!introDone)
                {
                    Unit *chogall = instance->GetCreature(DATA_CHOGALL);
                    if (chogall)
                        chogall->Yell(SAY_AGGRO1, LANG_UNIVERSAL);
                    DoPlaySoundToSet(me, SOU_AGGRO1);
                    events.ScheduleEvent(EVENT_INTRO, 5000, 0, 0);
                    talkcount =0;
                    introDone = true;
                }

                instance->SetData(DATA_VALIONA_THERALION_EVENT, IN_PROGRESS);

                events.ScheduleEvent(EVENT_ENGULFING_MAGIC, 35000, 0, 0);
                events.ScheduleEvent(EVENT_TWILIGHT_SHIFT_THERALION, 20000, 0, 0);
                events.ScheduleEvent(EVENT_FABULOUS_FLAMES, urand(10000, 16000), 0, 0);
                events.ScheduleEvent(EVENT_VALIONA_LAND, 95000, 0, 0);
                events.ScheduleEvent(EVENT_VALIONA_TWILIGHT_BREATH, 60000, 0, 0);
                events.ScheduleEvent(EVENT_VALIONA_TWILIGHT_METEORITE, urand(5000, 8000), 0, 0);
                breathcount = 0;
            }

            void JustDied(Unit* /*killer*/) override
            {
                summons.DespawnAll();
                /*
                if (me->GetMap()->GetDifficultyID() == DIFFICULTY_25_N)
                    killer->SummonGameObject(8000015, -741.23f, -686.75, 831.88f, 1.593f, 0.0f, 0.0f, 0.0f, 0.0f, 100000000);
                else if (me->GetMap()->GetDifficultyID() == DIFFICULTY_25_HC)
                    killer->SummonGameObject(8000018, -741.23f, -686.75, 831.88f, 1.593f, 0.0f, 0.0f, 0.0f, 0.0f, 100000000);
                else if (me->GetMap()->GetDifficultyID() == DIFFICULTY_10_HC)
                    killer->SummonGameObject(8000017, -741.23f, -686.75, 831.88f, 1.593f, 0.0f, 0.0f, 0.0f, 0.0f, 100000000);
                else
                    killer->SummonGameObject(8000016, -741.23f, -686.75, 831.88f, 1.593f, 0.0f, 0.0f, 0.0f, 0.0f, 100000000);
                */
                me->LowerPlayerDamageReq(me->GetMaxHealth());

                /*if (instance->GetData(DATA_FIEND_KILLS) >= 6)
                    instance->DoCompleteAchievement(4852);*/

                bool is25 = (me->GetMap()->GetDifficultyID() == DIFFICULTY_25_N || me->GetMap()->GetDifficultyID() == DIFFICULTY_25_HC);
                if (!me->GetMap()->GetPlayers().isEmpty())
                {
                    for (Map::PlayerList::const_iterator i = me->GetMap()->GetPlayers().begin(); i != me->GetMap()->GetPlayers().end(); ++i)
                    {
                        if (is25)
                            i->GetSource()->ModifyCurrency(396, 70 * 100);
                        else
                            i->GetSource()->ModifyCurrency(396, 40 * 100);
                    }
                }
                instance->SetData(DATA_VALIONA_THERALION_EVENT, DONE);
            }

            void KilledUnit(Unit* victim) override
            {
                if (!victim || victim->GetTypeId() != TYPEID_PLAYER || killtimer > 0)
                    return;
                me->Yell(SAY_THER_KILL, LANG_COMMON);
                DoPlaySoundToSet(me, SOU_THER_KILL);
                killtimer = 8000;
            }

            void UpdateAI(uint32 diff) override

            {
                if (instance->GetData(DATA_VALIONA_TERALION_HP) != 0)
                    me->SetHealth(instance->GetData(DATA_VALIONA_TERALION_HP));
                else
                    me->SetHealth(1);

                if (!UpdateVictim() && phase != PHASE_THERALION_FLY)
                    return;

                if (killtimer>=diff)
                killtimer -= diff;

                events.Update(diff);

                while (uint32 eventid = events.ExecuteEvent())
                {
                    switch (eventid)
                    {
                        case EVENT_INTRO:
                            switch(talkcount)
                            {
                            case 0:
                                if (Creature* valiona = instance->GetCreature(DATA_VALIONA))
                                {
                                    valiona->Yell(SAY_AGGRO2, LANG_UNIVERSAL);
                                    DoPlaySoundToSet(valiona, SOU_AGGRO2);
                                    events.ScheduleEvent(EVENT_INTRO, 6000, 0, 0);
                                }
                                break;
                            case 1:
                                me->Yell(SAY_AGGRO3, LANG_UNIVERSAL);
                                DoPlaySoundToSet(me, SOU_AGGRO3);
                                events.ScheduleEvent(EVENT_INTRO, 8000, 0, 0);
                                break;
                            case 2:
                                if (Creature* valiona = instance->GetCreature(DATA_VALIONA))
                                {
                                    valiona->Yell(SAY_AGGRO4, LANG_UNIVERSAL);
                                    DoPlaySoundToSet(valiona, SOU_AGGRO4);
                                    events.ScheduleEvent(EVENT_INTRO, 6000, 0, 0);
                                }
                                break;
                            case 3:
                                me->Yell(SAY_AGGRO5, LANG_UNIVERSAL);
                                DoPlaySoundToSet(me, SOU_AGGRO5);
                                break;
                            }
                            talkcount++;
                            break;
                        case EVENT_ENGULFING_MAGIC:
                            for (int8 i = 0; i < RAID_MODE(1, 3, 1, 3); i++)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                    me->AddAura(SPELL_ENGULFING_MAGIC, target);
                            }
                            if (roll_chance_i(50))
                            {
                                me->Yell(SAY_THER_ENG, LANG_UNIVERSAL);
                                DoPlaySoundToSet(me, SOU_THER_ENG);
                            }
                            else
                            {
                                DoPlaySoundToSet(me, SOU_THER_LAU);
                            }
                            events.ScheduleEvent(EVENT_ENGULFING_MAGIC, 35000, 0, 0);
                            break;
                        case EVENT_TWILIGHT_SHIFT_THERALION:
                            me->CastSpell(me->GetVictim(), SPELL_TWILIGHT_SHIFT, true);

                            if (me->GetVictim()->HasAura(SPELL_TWILIGHT_SHIFT) && me->GetVictim()->GetAura(SPELL_TWILIGHT_SHIFT)->GetStackAmount() >= 5)
                            {
                                me->GetVictim()->CastCustomSpell(me->GetVictim(), SPELL_SHIFTING_REALITY, NULL, NULL, NULL, true, 0, 0 , me->GetGUID());
                                me->GetVictim()->RemoveAura(SPELL_TWILIGHT_SHIFT);
                            }

                            events.ScheduleEvent(EVENT_TWILIGHT_SHIFT_THERALION, urand(20000, 25000), 0, 0);
                            break;
                        case EVENT_FABULOUS_FLAMES:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                me->CastSpell(target, SPELL_FABOLOUS_FLAMES, true);

                            events.ScheduleEvent(EVENT_FABULOUS_FLAMES, urand(15000, 20000), 0, 0);
                        break;
                        case EVENT_VALIONA_LAND:
                            events.CancelEvent(EVENT_FABULOUS_FLAMES);
                            events.CancelEvent(EVENT_TWILIGHT_SHIFT_THERALION);
                            events.CancelEvent(EVENT_ENGULFING_MAGIC);
                            events.CancelEvent(EVENT_VALIONA_TWILIGHT_METEORITE);
                            events.CancelEvent(EVENT_VALIONA_TWILIGHT_BREATH);
                            phase = PHASE_THERALION_FLY;
                            SetFlyState(true);
                            me->GetMotionMaster()->MovePoint(POINT_THERALION_ABOVE_HOME, me->GetHomePosition().m_positionX, me->GetHomePosition().m_positionY, me->GetHomePosition().m_positionZ + 20.0f);

                            if (Creature* valiona = instance->GetCreature(DATA_VALIONA))
                            {
                                if (valiona->AI())
                                    valiona->AI()->DoAction(ACTION_VALIONA_LAND_MOVE);
                            }
                            break;
                        case EVENT_VALIONA_TWILIGHT_METEORITE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            {
                                if (Creature* valiona = instance->GetCreature(DATA_VALIONA))
                                {
                                    valiona->AddAura(SPELL_TWILIGHT_METEORITE_TARGET, target);
                                    valiona->CastSpell(target, SPELL_TWILIGHT_METEORITE, false);
                                }
                            }
                            events.ScheduleEvent(EVENT_VALIONA_TWILIGHT_METEORITE, urand(6000, 8000), 0, 0);
                            break;
                        case EVENT_VALIONA_TWILIGHT_BREATH:
                            events.CancelEvent(EVENT_VALIONA_TWILIGHT_METEORITE);
                            if (Creature* valiona = instance->GetCreature(DATA_VALIONA))
                            {
                                switch(breathcount)
                                {
                                case 0:
                                    valiona->SetSpeed(MOVE_FLIGHT, 3.0f);
                                    valiona->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
                                    valiona->Yell(SAY_VAL_ENG, LANG_UNIVERSAL);
                                    DoPlaySoundToSet(me, SOU_VAL_ENG);
                                    //if (valiona->AI())
                                    //    valiona->AI()->DoAction(ACTION_EMOTE_BREATH);
                                    valiona->GetMotionMaster()->MovePoint(0, flightpoints[0]);
                                    events.ScheduleEvent(EVENT_VALIONA_TWILIGHT_BREATH, 5000, 0, 0);
                                    break;
                                case 1:
                                    valiona->SetSpeed(MOVE_FLIGHT, 6.0f);
                                    valiona->GetMotionMaster()->MovePoint(0, flightpoints[1]);
                                    spost = 0;
                                    spawncount = 0;
                                    forw = true;
                                    events.ScheduleEvent(EVENT_VALIONA_TWILIGHT_BREATH, 6000, 0, 0);
                                    events.ScheduleEvent(EVENT_VALIONA_TWILIGHT_SPAWN, 1000, 0, 0);
                                    break;
                                case 2:
                                    valiona->SetFacingToObject(me);
                                    events.ScheduleEvent(EVENT_VALIONA_TWILIGHT_BREATH, 4000, 0, 0);
                                    break;
                                case 3:
                                    valiona->GetMotionMaster()->MovePoint(0, flightpoints[0]);
                                    spawncount = 0;
                                    spost++;
                                    forw = false;
                                    events.ScheduleEvent(EVENT_VALIONA_TWILIGHT_SPAWN, 1000, 0, 0);
                                    events.ScheduleEvent(EVENT_VALIONA_TWILIGHT_BREATH, 6000, 0, 0);
                                    break;
                                case 4:
                                    valiona->SetFacingToObject(me);
                                    events.ScheduleEvent(EVENT_VALIONA_TWILIGHT_BREATH, 4000, 0, 0);
                                    break;
                                case 5:
                                    valiona->GetMotionMaster()->MovePoint(0, flightpoints[1]);
                                    spawncount = 0;
                                    spost++;
                                    forw = true;
                                    events.ScheduleEvent(EVENT_VALIONA_TWILIGHT_SPAWN, 1000, 0, 0);
                                    break;

                                }
                                breathcount++;
                            }
                            break;
                        case EVENT_VALIONA_TWILIGHT_SPAWN:
                            if (Creature* valiona = instance->GetCreature(DATA_VALIONA))
                            {
                                float X = flamepoints[spawncount].GetPositionX() + float(spost* 20.0f);
                                if (forw)
                                {
                                    valiona->SummonCreature(NPC_TWILIGHT_FLAME,
                                                       X,
                                                       flamepoints[spawncount].GetPositionY(),
                                                       flamepoints[spawncount].GetPositionZ(),
                                                       0);
                                }
                                else
                                {
                                    valiona->SummonCreature(NPC_TWILIGHT_FLAME,
                                                       X,
                                                       flamepoints[8-spawncount].GetPositionY(),
                                                       flamepoints[8-spawncount].GetPositionZ(),
                                                       0);
                                }
                                spawncount++;
                                if (spawncount < 9)
                                    events.ScheduleEvent(EVENT_VALIONA_TWILIGHT_SPAWN, 500, 0, 0);
                            }
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_theralionAI(creature);
        }
};

class boss_valiona : public CreatureScript
{
    public:
        boss_valiona() : CreatureScript("boss_valiona") { }

        struct boss_valionaAI : public BossAI
        {
            boss_valionaAI(Creature * creature) : BossAI(creature, DATA_VALIONA), summons(me)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            SummonList summons;
            uint32 phase;
            uint32 killtimer;
            uint8 dazzlingCount;

            void SetFlyState(bool fly)
            {
                me->SetDisableGravity(fly);
                me->SetHover(fly);
                me->SetCanFly(fly);
                if (fly)
                {
                    me->SetSpeed(MOVE_FLIGHT, 3.0f);
                    me->SetReactState(REACT_PASSIVE);
                    me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
                }
                else
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_FLYING);
                }
            }

            void KilledUnit(Unit* victim) override
            {
                if (!victim || victim->GetTypeId() != TYPEID_PLAYER || killtimer > 0)
                    return;
                me->Yell(SAY_VAL_KILL, LANG_UNIVERSAL);
                DoPlaySoundToSet(me, SOU_VAL_KILL);
                killtimer = 8000;
            }

            void MovementInform(uint32 type, uint32 point) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case POINT_VALIONA_ABOVE_HOME:
                        me->SetOrientation(me->GetHomePosition().GetOrientation());
                        break;
                    case POINT_CENTER_ROOM:
                        SetFlyState(false);
                        me->Attack(me->GetVictim(), true);
                        me->AI()->AttackStart(me->GetVictim());
                        me->AI()->DoAction(ACTION_VALIONA_LAND);
                        me->GetMotionMaster()->MoveChase(me->GetVictim(), 1.0f, 1.0f);
                        break;
                }
            }

            void JustReachedHome() override
            {
                SetFlyState(false);
                me->SetOrientation(me->GetHomePosition().GetOrientation());
            }

            void Reset() override
            {
                events.Reset();
                phase = PHASE_NONE;
                dazzlingCount = 0;
                summons.DespawnAll();
                me->LowerPlayerDamageReq(me->GetMaxHealth());

                if (instance)
                {
                    instance->SetData(DATA_VALIONA_TERALION_HP, me->GetMaxHealth());
                    instance->SetData(DATA_VALIONA_THERALION_EVENT, NOT_STARTED);
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->LowerPlayerDamageReq(me->GetMaxHealth());

                /*if (instance->GetData(DATA_FIEND_KILLS) >= 6)
                    instance->DoCompleteAchievement(4852);*/

                instance->SetData(DATA_VALIONA_THERALION_EVENT, DONE);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage) override
            {
                if (!me || !me->IsAlive())
                    return;

                if (instance)
                {
                    instance->SetData(DATA_VALIONA_TERALION_HP, me->GetHealth() >= damage ? me->GetHealth() - damage : 0);
                }

                if (damage > me->GetHealth())
                {//teleport to center when dying
                    SetFlyState(false);
                    me->NearTeleportTo(-741.23f, -666.75, 831.88f, 0);
                    me->Yell(SAY_VAL_DEA, LANG_UNIVERSAL);
                    DoPlaySoundToSet(me, SOU_VAL_DEA);
                    /*Unit *theralion = instance->GetCreature(DATA_THERALION));
                    if (theralion && theralion->IsAlive())
                    {
                        who->DealDamage(theralion,2);
                    }*/
                }
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() ==  NPC_THERALION_FLIGHT_TARGET_STALKER)
                {
                    summon->CastSpell(summon, SPELL_DAZZLING_DESTRUCTION_VISUAL, true);
                    DoZoneInCombat(summon);
                    summon->SetReactState(REACT_PASSIVE);
                    summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    summon->AttackStop();
                    summon->StopMoving();
                }
                else if (summon->GetEntry() ==  NPC_TWILIGHT_FLAME)
                {
                    DoZoneInCombat(summon);
                    summon->AddAura(SPELL_TWILIGHT_FLAME, summon);
                    summon->setFaction(me->getFaction());
                    summon->SetReactState(REACT_PASSIVE);
                    summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    summon->AttackStop();
                    summon->StopMoving();
                }
                summons.Summon(summon);
            }

            void UpdateAI(uint32 diff) override

            {
                if (instance->GetData(DATA_VALIONA_TERALION_HP) != 0)
                    me->SetHealth(instance->GetData(DATA_VALIONA_TERALION_HP));
                else
                    me->SetHealth(1);

                if (!UpdateVictim())
                    return;

                if (killtimer>=diff)
                killtimer -= diff;

                events.Update(diff);

                while (uint32 eventid = events.ExecuteEvent())
                {
                    switch (eventid)
                    {
                        case EVENT_BLACKOUT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                me->CastSpell(target, SPELL_BLACKOUT, true);
                            me->Yell(SAY_VAL_BLA, LANG_UNIVERSAL);
                            DoPlaySoundToSet(me, SOU_VAL_BLA);

                            events.ScheduleEvent(EVENT_BLACKOUT, 45000, 0, 0);
                            break;
                        case EVENT_DEVOURING_FLAMES:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            {
                                if (Creature* spTarget = me->SummonCreature(46588, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 8040))
                                {
                                    spTarget->setFaction(target->getFaction());
                                    spTarget->SetReactState(REACT_AGGRESSIVE);
                                    spTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                                    me->AddThreat(spTarget, 100000000.0f, SPELL_SCHOOL_MASK_NORMAL);
                                    spTarget->AddThreat(me, 100000000.0f, SPELL_SCHOOL_MASK_NORMAL);
                                    me->Attack(spTarget, true);
                                    spTarget->Attack(me, true);
                                    me->SetFacingToObject(spTarget);
                                    me->CastSpell(spTarget, SPELL_DEVOURING_FLAMES, false);
                                }
                            }
                            events.ScheduleEvent(EVENT_DEVOURING_FLAMES, urand(40000, 45000), 0, 0);
                            break;
                        case EVENT_TWILIGHT_SHIFT:
                            if (me->GetVictim())
                            {
                                me->CastSpell(me->GetVictim(), SPELL_TWILIGHT_SHIFT, true);

                                if (me->GetVictim()->HasAura(SPELL_TWILIGHT_SHIFT) && me->GetVictim()->GetAura(SPELL_TWILIGHT_SHIFT)->GetStackAmount() >= 5)
                                {
                                    me->GetVictim()->CastCustomSpell(me->GetVictim(), SPELL_SHIFTING_REALITY, NULL, NULL, NULL, true, 0, 0 , me->GetGUID());
                                    me->GetVictim()->RemoveAura(SPELL_TWILIGHT_SHIFT);
                                }
                            }
                            events.ScheduleEvent(EVENT_TWILIGHT_SHIFT, urand(20000, 25000), 0, 0);
                            break;
                        case EVENT_DAZZLING_DESTRUCTION:
                            if (dazzlingCount == 0)
                            {
                                if (Creature* theralion = instance->GetCreature(DATA_THERALION))
                                {
                                    if (roll_chance_i(50))
                                    {
                                        theralion->Yell(SAY_THER_DAZ, LANG_UNIVERSAL);
                                        DoPlaySoundToSet(theralion, SOU_THER_DAZ);
                                    }
                                    else
                                    {
                                        theralion->Yell(SAY_THER_DA2, LANG_UNIVERSAL);
                                        DoPlaySoundToSet(theralion, SOU_THER_DA2);
                                    }
                                }
                            }
                            // Cast 2 flames per time, 6 total
                            for (uint8 i = 0; i < 2; i++)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 0))
                                {
                                    if (Creature* theralion = instance->GetCreature(DATA_THERALION))
                                    {
                                        // Summon stalker
                                        if (Creature* stalker = me->SummonCreature(NPC_THERALION_FLIGHT_TARGET_STALKER, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 12000))
                                            theralion->CastSpell(stalker, SPELL_DAZZLING_DESTRUCTION_MISSILE, true);
                                    }
                                }
                                dazzlingCount++;
                            }
                            if (dazzlingCount < 6)
                                events.ScheduleEvent(EVENT_DAZZLING_DESTRUCTION, 4500, 0, 0);
                            else
                                events.ScheduleEvent(EVENT_THERALION_LAND, 1000, 0, 0);
                            break;
                        case EVENT_THERALION_LAND:
                            events.CancelEvent(EVENT_DAZZLING_DESTRUCTION);
                            events.CancelEvent(EVENT_TWILIGHT_SHIFT);
                            events.CancelEvent(EVENT_DEVOURING_FLAMES);
                            events.CancelEvent(EVENT_BLACKOUT);
                            events.CancelEvent(EVENT_THERALION_TWILIGHT_BLASE);

                            phase = PHASE_VALIONA_FLY;
                            SetFlyState(true);
                            me->GetMotionMaster()->MovePoint(POINT_VALIONA_ABOVE_HOME, me->GetHomePosition().m_positionX, me->GetHomePosition().m_positionY, me->GetHomePosition().m_positionZ + 20.0f);

                            if (Creature* theralion = instance->GetCreature(DATA_THERALION))
                            {
                                if (theralion->AI())
                                    theralion->AI()->DoAction(ACTION_THERALION_LAND);
                            }
                            break;
                        case EVENT_THERALION_TWILIGHT_BLASE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            {
                                if (Creature* theralion = instance->GetCreature(DATA_THERALION))
                                    theralion->CastSpell(target, SPELL_TWILIGHT_BLAST, false);
                            }
                            events.ScheduleEvent(EVENT_THERALION_TWILIGHT_BLASE, urand(3000, 4000), 0, 0);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void DoAction(int32 actionId) override
            {
                switch (actionId)
                {
                    case ACTION_EMOTE_BREATH:
                        Talk(0);
                        break;
                    case ACTION_VALIONA_LAND:
                        phase = PHASE_VALIONA_LAND;
                        dazzlingCount = 0;

                        // Schedule events
                        events.ScheduleEvent(EVENT_BLACKOUT, 45000, 0, 0);
                        events.ScheduleEvent(EVENT_DEVOURING_FLAMES, 40000, 0, 0);
                        events.ScheduleEvent(EVENT_TWILIGHT_SHIFT, 20000, 0, 0);
                        events.ScheduleEvent(EVENT_DAZZLING_DESTRUCTION, 102000, 0, 0);
                        events.ScheduleEvent(EVENT_THERALION_TWILIGHT_BLASE, urand(3000, 4000), 0, 0);
                        break;
                    case ACTION_VALIONA_LAND_MOVE:
                        phase = PHASE_VALIONA_LAND;
                        me->GetMotionMaster()->MovePoint(POINT_CENTER_ROOM, -741.23f, -686.75, 831.88f);
                        break;
                    case ACTION_VALIONA_FLY:
                        events.CancelEvent(EVENT_DAZZLING_DESTRUCTION);
                        events.CancelEvent(EVENT_TWILIGHT_SHIFT);
                        events.CancelEvent(EVENT_DEVOURING_FLAMES);
                        events.CancelEvent(EVENT_BLACKOUT);
                        events.CancelEvent(EVENT_THERALION_TWILIGHT_BLASE);

                        phase = PHASE_VALIONA_FLY;
                        SetFlyState(true);
                        me->GetMotionMaster()->MovePoint(POINT_VALIONA_ABOVE_HOME, me->GetHomePosition().m_positionX, me->GetHomePosition().m_positionY, me->GetHomePosition().m_positionZ + 20.0f);
                        break;
                }
            }

            void EnterCombat(Unit* victim) override
            {
                DoZoneInCombat(me);

                if (Creature* theralion = instance->GetCreature(DATA_THERALION))
                {
                    if (!theralion->IsInCombat())
                    {
                        theralion->Attack(victim, false);
                        DoZoneInCombat(theralion);
                        theralion->AttackStop();

                        if (theralion->AI())
                            theralion->AI()->DoAction(ACTION_THERALION_FLY);
                    }
                }

                instance->SetData(DATA_VALIONA_THERALION_EVENT, IN_PROGRESS);

                me->AI()->DoAction(ACTION_VALIONA_LAND);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_valionaAI(creature);
        }
};


class spell_dazzling_destruction : public SpellScriptLoader
{
    public:
        spell_dazzling_destruction() : SpellScriptLoader("spell_dazzling_destruction") { }

        class spell_dazzling_destructionSpellScript : public SpellScript
        {
            int32 spell_trigger;
            PrepareSpellScript(spell_dazzling_destructionSpellScript);

            bool Load() override
            {
                spell_trigger = GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetHitUnit(),spell_trigger,false);
            }

            void HandleOnHit()
            {
                /*std::list<Unit*> players;
                std::list<Unit*>::const_iterator itr;
                if (!GetHitUnit()->ToPlayer())
                    return;
                GetHitUnit()->ToPlayer()->GetRaidMember(players,5.0f);
                for (itr=players.begin();itr!=players.end();++itr)
                {
                    if ((*itr)->GetTypeId() == TYPEID_PLAYER)
                    {
                        GetCaster()->CastSpell((*itr),SPELL_DESTRUCTION_PROCS,false);
                    }
                }*/
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dazzling_destructionSpellScript::HandleDummy,EFFECT_0,SPELL_EFFECT_DUMMY);
                OnHit += SpellHitFn(spell_dazzling_destructionSpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dazzling_destructionSpellScript();
        }
};

class spell_blackout : public SpellScriptLoader {
public:
    spell_blackout() : SpellScriptLoader("spell_blackout")
    {    }

    class spell_blackout_AuraScript: public AuraScript
    {
        PrepareAuraScript(spell_blackout_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (!GetCaster() || !GetUnitOwner())
                return;

            GetUnitOwner()->CastCustomSpell(GetUnitOwner(), SPELL_BLACKOUT_DMG, NULL, NULL, NULL, true, 0, 0, GetCaster()->GetGUID());
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_blackout_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_blackout_AuraScript();
    }
};

class spell_devouring_flame : public SpellScriptLoader
{
    public:
        spell_devouring_flame() : SpellScriptLoader("spell_devouring_flame") { }

        class spell_devouring_flame_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_devouring_flame_AuraScript);

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (GetCaster())
                    GetCaster()->CastSpell(GetCaster(), SPELL_DEVOURING_FLAMES_TRG, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_devouring_flame_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_devouring_flame_AuraScript();
        }
};

class spell_engulfing_magic : public SpellScriptLoader
{
    public:
        spell_engulfing_magic() : SpellScriptLoader("spell_engulfing_magic") { }
        class spell_engulfing_magic_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_engulfing_magic_SpellScript);
            void onDmg()
            {
                if (!GetHitUnit() || !GetCaster())
                    return;

                // Remove caster
                if (GetHitUnit()->GetGUID() == GetCaster()->GetGUID())
                    SetHitDamage(0);
                else
                    SetHitDamage(GetHitDamage() / 2);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_engulfing_magic_SpellScript::onDmg);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_engulfing_magic_SpellScript();
        }
};

class spell_shifting_reality : public SpellScriptLoader
{
    public:
        spell_shifting_reality() : SpellScriptLoader("spell_shifting_reality") { }
        class spell_shifting_reality_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_shifting_reality_SpellScript);
            void onDmg()
            {
                if (!GetHitUnit() || !GetCaster())
                    return;

                if (GetHitUnit()->GetGUID() == GetCaster()->GetGUID())
                    return;

                if (!GetHitUnit()->ToPlayer())
                    return;

                if (!GetHitUnit()->HasAura(74807))
                    GetHitUnit()->AddAura(74807, GetHitUnit());
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_shifting_reality_SpellScript::onDmg);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_shifting_reality_SpellScript();
        }
};


class npc_twilight_portal_bot : public CreatureScript
{
    public:
        npc_twilight_portal_bot() : CreatureScript("npc_twilight_portal_bot") { }

        bool OnGossipHello(Player* pPlayer, Creature* /*pCreature*/) override
        {
            pPlayer->RemoveAura(74807);
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override
        {
            ClearGossipMenuFor(player);
            return true;
        }

        struct npc_twilight_portal_botAI : public ScriptedAI
        {
            npc_twilight_portal_botAI(Creature* c) : ScriptedAI(c)
            { }

            InstanceScript* instance;
            uint32 timer;

            void Reset() override
            {
                timer = 1000;
            }

            void UpdateAI(uint32 diff) override

            {
                if (timer <= diff)
                {
                    if (!me->HasAura(86291))
                        me->AddAura(86291, me);

                    timer = 1000;
                } else
                    timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_twilight_portal_botAI(creature);
        }
};

class npc_twilight_fiend : public CreatureScript
{
public:
    npc_twilight_fiend() : CreatureScript("npc_twilight_fiend") { }

    struct npc_twilight_fiendAI : public ScriptedAI
    {
        npc_twilight_fiendAI(Creature* c) : ScriptedAI(c)
        {
            me->SetReactState(REACT_AGGRESSIVE);
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(DATA_FIEND_KILLS, 1);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_twilight_fiendAI(creature);
    }
};

void AddSC_boss_theralion()
{
    new boss_theralion();
    new boss_valiona();

    new spell_dazzling_destruction();
    new spell_blackout();
    new spell_devouring_flame();
    new spell_engulfing_magic();
    new spell_shifting_reality();

    new npc_twilight_portal_bot();
    new npc_twilight_fiend();
}
