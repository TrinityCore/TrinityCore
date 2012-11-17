/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_KelThuzad
SD%Complete: 80%
SDComment: VERIFY SCRIPT
SDCategory: Naxxramas
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "naxxramas.h"
#include "Player.h"

enum Yells
{
    //when shappiron dies. dialog between kel and lich king (in this order)
    SAY_SAPP_DIALOG1                                       = -1533084, //not used
    SAY_SAPP_DIALOG2_LICH                                  = -1533085, //not used
    SAY_SAPP_DIALOG3                                       = -1533086, //not used
    SAY_SAPP_DIALOG4_LICH                                  = -1533087, //not used
    SAY_SAPP_DIALOG5                                       = -1533088, //not used
    SAY_CAT_DIED                                           = -1533089, //when cat dies, not used
    //when each of the 4 wing bosses dies
    SAY_TAUNT1                                             = -1533090, //not used
    SAY_TAUNT2                                             = -1533091, //not used
    SAY_TAUNT3                                             = -1533092, //not used
    SAY_TAUNT4                                             = -1533093, //not used
    SAY_SUMMON_MINIONS                                     = -1533105, //start of phase 1
    SAY_AGGRO_1                                            = -1533094, //start of phase 2
    SAY_AGGRO_2                                            = -1533095,
    SAY_AGGRO_3                                            = -1533096,
    SAY_SLAY_1                                             = -1533097,
    SAY_SLAY_2                                             = -1533098,
    SAY_DEATH                                              = -1533099,
    SAY_CHAIN_1                                            = -1533100,
    SAY_CHAIN_2                                            = -1533101,
    SAY_FROST_BLAST                                        = -1533102,
    SAY_SPECIAL_1                                          = -1533106,
    SAY_SPECIAL_2                                          = -1533107,
    SAY_SPECIAL_3                                          = -1533108,
    SAY_REQUEST_AID                                        = -1533103, //start of phase 3
    SAY_ANSWER_REQUEST                                     = -1533104  //lich king answer
};

enum Events
{
    EVENT_NONE,
    EVENT_BOLT,
    EVENT_NOVA,
    EVENT_CHAIN,
    EVENT_CHAINED_SPELL,
    EVENT_DETONATE,
    EVENT_FISSURE,
    EVENT_BLAST,

    EVENT_WASTE,
    EVENT_ABOMIN,
    EVENT_WEAVER,
    EVENT_ICECROWN,
    EVENT_TRIGGER,

    EVENT_PHASE,
    EVENT_MORTAL_WOUND,
};

enum Spells
{
    SPELL_FROST_BOLT                                       = 28478,
    H_SPELL_FROST_BOLT                                     = 55802,
    SPELL_FROST_BOLT_AOE                                   = 28479,
    H_SPELL_FROST_BOLT_AOE                                 = 55807,
    SPELL_SHADOW_FISURE                                    = 27810,
    SPELL_VOID_BLAST                                       = 27812,
    SPELL_MANA_DETONATION                                  = 27819,
    SPELL_MANA_DETONATION_DAMAGE                           = 27820,
    SPELL_FROST_BLAST                                      = 27808,
    SPELL_CHAINS_OF_KELTHUZAD                              = 28410, //28408 script effect
    SPELL_KELTHUZAD_CHANNEL                                = 29423,
    SPELL_BERSERK                                          = 28498,

    //spells for chained
    //warlock
    SPELL_CURSE_OF_AGONY                                   = 47864,
    SPELL_SHADOW_BOLT                                      = 47809,
    //shaman
    SPELL_EARTH_SHOCK                                      = 49231,
    SPELL_HEALING_WAVE                                     = 49273,
    //mage
    SPELL_FROST_FIREBOLT                                   = 47610,
    SPELL_ARCANE_MISSILES                                  = 42846,
    //rogue
    SPELL_HEMORRHAGE                                       = 48660,
    SPELL_MUTILATE                                         = 48666,
    //paladin
    SPELL_HOLY_SHOCK                                       = 48825,
    SPELL_HAMMER_OF_JUSTICE                                = 10308,
    //priest
    SPELL_VAMPIRIC_TOUCH                                   = 48160,
    SPELL_RENEW                                            = 48068,
    //hunter
    SPELL_MULTI_SHOT                                       = 49048,
    SPELL_VOLLEY                                           = 58434,
    //warrior
    SPELL_BLADESTORM                                       = 46924,
    SPELL_CLEAVE                                           = 47520,
    //druid
    SPELL_MOONFIRE                                         = 48463,
    SPELL_LIFEBLOOM                                        = 48451,
    //death knight
    SPELL_PLAGUE_STRIKE                                    = 49921,
    SPELL_HOWLING_BLAST                                    = 51411,

    // Abomination spells
    SPELL_FRENZY                                           = 28468,
    SPELL_MORTAL_WOUND                                     = 28467,
};

enum Creatures
{
    NPC_WASTE                                              = 16427, // Soldiers of the Frozen Wastes
    NPC_ABOMINATION                                        = 16428, // Unstoppable Abominations
    NPC_WEAVER                                             = 16429, // Soul Weavers
    NPC_ICECROWN                                           = 16441 // Guardians of Icecrown
};

const Position Pos[12] =
{
    {3783.272705f, -5062.697266f, 143.711203f, 3.617599f},     //LEFT_FAR
    {3730.291260f, -5027.239258f, 143.956909f, 4.461900f},     //LEFT_MIDDLE
    {3757.6f, -5172.0f, 143.7f, 1.97f},                        //WINDOW_PORTAL05
    {3759.355225f, -5174.128418f, 143.802383f, 2.170104f},     //RIGHT_FAR
    {3700.724365f, -5185.123047f, 143.928024f, 1.309310f},     //RIGHT_MIDDLE
    {3700.86f, -5181.29f, 143.928024f, 1.42f},                 //WINDOW_PORTAL04
    {3754.431396f, -5080.727734f, 142.036316f, 3.736189f},     //LEFT_FAR
    {3724.396484f, -5061.330566f, 142.032700f, 4.564785f},     //LEFT_MIDDLE
    {3732.02f, -5028.53f, 143.92f, 4.49f},                     //WINDOW_PORTAL02
    {3687.571777f, -5126.831055f, 142.017807f, 0.604023f},     //RIGHT_FAR
    {3707.990733f, -5151.450195f, 142.032562f, 1.376855f},     //RIGHT_MIDDLE
    {3782.76f, -5062.97f, 143.79f, 3.82f},                     //WINDOW_PORTAL03
};

//creatures in corners
//Unstoppable Abominations
#define MAX_ABOMINATIONS                        21
const Position PosAbominations[MAX_ABOMINATIONS] =
{
    {3755.52f, -5155.22f, 143.480f, 2.0f},
    {3744.35f, -5164.03f, 143.590f, 2.00f},
    {3749.28f, -5159.04f, 143.190f, 2.0f},
    {3774.47f, -5076.28f, 143.528f, 2.15912f},
    {3765.94f, -5074.15f, 143.186f, 3.77233f},
    {3763.15f, -5063.36f, 143.694f, 3.77233f},
    {3737.81f, -5045.69f, 143.709f, 4.9033f},
    {3728.13f, -5045.01f, 143.355f, 1.45069f},
    {3721.56f, -5048.35f, 143.542f, 1.45069f},
    {3689.55f, -5049.66f, 143.637f, 5.2104f},
    {3681.71f, -5053.03f, 143.242f, 2.47957f},
    {3677.64f, -5061.44f, 143.358f, 2.47957f},
    {3654.2f, -5090.87f, 143.469f, 1.0313f},
    {3650.39f, -5097.45f, 143.496f, 2.5047f},
    {3658.7f, -5103.59f, 143.607f, 3.3278f},
    {3659.02f, -5133.97f, 143.624f, 3.84538f},
    {3666.33f, -5139.34f, 143.183f, 3.84538f},
    {3669.74f, -5149.63f, 143.678f, 0.528643f},
    {3695.53f, -5169.53f, 143.671f, 2.11908f},
    {3701.98f, -5166.51f, 143.395f, 1.24257f},
    {3709.62f, -5169.15f, 143.576f, 5.97695f},
};

//Soldiers of the Frozen Wastes
#define MAX_WASTES                              49
const Position PosWastes[MAX_WASTES] =
{
    {3754.41f, -5147.24f, 143.204f, 2.0f},
    {3754.68f, -5156.17f, 143.418f, 2.0f},
    {3757.91f, -5160.12f, 143.503f, 2.0f},
    {3752.67f, -5164.6f, 143.395f, 2.0f},
    {3745.42f, -5164.47f, 143.565f, 2.74587f},
    {3741.2f, -5155.92f, 143.17f, 5.29134f},
    {3746.57f, -5148.82f, 143.176f, 5.07772f},
    {3778.14f, -5070.1f, 143.568f, 3.16208f},
    {3775.09f, -5078.97f, 143.65f, 2.81022f},
    {3773.54f, -5083.47f, 143.758f, 3.21549f},
    {3765, -5078.29f, 143.176f, 4.36688f},
    {3766.94f, -5072.63f, 143.184f, 5.27951f},
    {3762.68f, -5064.94f, 143.635f, 3.95297f},
    {3769.9f, -5059.94f, 143.74f, 3.36549f},
    {3736.33f, -5042.18f, 143.643f, 5.9471f},
    {3727.51f, -5040.58f, 143.502f, 0.871859f},
    {3719.89f, -5049.64f, 143.58f, 4.75172f},
    {3720.69f, -5044.43f, 143.662f, 1.87245f},
    {3725.69f, -5048.99f, 143.363f, 2.48271f},
    {3732.33f, -5054.01f, 143.44f, 3.59405f},
    {3738.09f, -5051.06f, 143.718f, 4.70931f},
    {3682.76f, -5063.5f, 143.175f, 0.636238f},
    {3686.7f, -5060.58f, 143.18f, 0.636238f},
    {3682.45f, -5057.21f, 143.184f, 5.61252f},
    {3677.57f, -5053.34f, 143.369f, 1.52531f},
    {3677.3f, -5062.26f, 143.369f, 2.73482f},
    {3691.21f, -5053.02f, 143.421f, 5.93218f},
    {3685.22f, -5053.34f, 143.314f, 4.70303f},
    {3652.11f, -5088.47f, 143.555f, 0.793317f},
    {3648.23f, -5093.21f, 143.311f, 1.18837f},
    {3648.14f, -5100.11f, 143.632f, 2.12221f},
    {3653.88f, -5099.7f, 143.558f, 3.04348f},
    {3661.23f, -5100.33f, 143.42f, 4.08335f},
    {3663.49f, -5092.77f, 143.346f, 4.47134f},
    {3661.85f, -5087.99f, 143.571f, 1.0148f},
    {3664.56f, -5149.01f, 143.532f, 0.0762528f},
    {3665.01f, -5142.04f, 143.201f, 1.72009f},
    {3671.15f, -5142.92f, 143.174f, 4.81535f},
    {3670.18f, -5134.38f, 143.177f, 5.37534f},
    {3664.33f, -5131.69f, 143.262f, 5.39576f},
    {3658.21f, -5133.63f, 143.662f, 1.3863f},
    {3659.7f, -5144.49f, 143.363f, 2.32328f},
    {3705.71f, -5179.63f, 143.746f, 1.06743f},
    {3696.77f, -5177.45f, 143.759f, 5.36748f},
    {3700.97f, -5173.13f, 143.52f, 3.26575f},
    {3708.53f, -5172.19f, 143.573f, 3.26575f},
    {3712.49f, -5167.62f, 143.657f, 5.63295f},
    {3704.89f, -5161.84f, 143.239f, 5.63295f},
    {3695.66f, -5164.63f, 143.674f, 1.54416f},
};

//Soul Weavers
#define MAX_WEAVERS                             7
const Position PosWeavers[MAX_WEAVERS] =
{
    {3752.45f, -5168.35f, 143.562f, 1.6094f},
    {3772.2f, -5070.04f, 143.329f, 1.93686f},
    {3732.28f, -5032.88f, 143.771f, 3.08355f},
    {3689.05f, -5055.7f, 143.172f, 6.09554f},
    {3649.45f, -5093.17f, 143.299f, 2.51805f},
    {3659.7f, -5144.49f, 143.363f, 4.08806f},
    {3704.71f, -5175.96f, 143.597f, 3.36549f},
};

// predicate function to select not charmed target
struct NotCharmedTargetSelector : public std::unary_function<Unit*, bool>
{
    NotCharmedTargetSelector() {}

    bool operator()(Unit const* target) const
    {
        return !target->isCharmed();
    }
};

class boss_kelthuzad : public CreatureScript
{
public:
    boss_kelthuzad() : CreatureScript("boss_kelthuzad") { }

    struct boss_kelthuzadAI : public BossAI
    {
        boss_kelthuzadAI(Creature* creature) : BossAI(creature, BOSS_KELTHUZAD), spawns(creature)
        {
            uiFaction = me->getFaction();
        }

        uint32 Phase;
        uint32 uiGuardiansOfIcecrownTimer;
        uint32 uiFaction;

        uint8  nGuardiansOfIcecrownCount;
        uint8  nAbomination;
        uint8  nWeaver;

        std::map<uint64, float> chained;

        uint64 PortalsGUID[4];
        uint64 KTTriggerGUID;

        SummonList spawns; // adds spawn by the trigger. kept in separated list (i.e. not in summons)

        void Reset()
        {
            _Reset();

            PortalsGUID[0] = PortalsGUID[1] = PortalsGUID[2] = PortalsGUID[3] = 0;
            KTTriggerGUID = 0;

            me->setFaction(35);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
            std::map<uint64, float>::const_iterator itr;
            for (itr = chained.begin(); itr != chained.end(); ++itr)
            {
                if (Player* charmed = Unit::GetPlayer(*me, (*itr).first))
                    charmed->SetObjectScale((*itr).second);
            }

            chained.clear();
            spawns.DespawnAll();

            FindGameObjects();

            if (instance)
                instance->SetData(DATA_ABOMINATION_KILLED, 0);

            if (GameObject* pKTTrigger = me->GetMap()->GetGameObject(KTTriggerGUID))
            {
                pKTTrigger->ResetDoorOrButton();
                pKTTrigger->SetPhaseMask(1, true);
            }

            for (uint8 i = 0; i <= 3; ++i)
            {
                if (GameObject* pPortal = me->GetMap()->GetGameObject(PortalsGUID[i]))
                {
                    if (!((pPortal->getLootState() == GO_READY) || (pPortal->getLootState() == GO_NOT_READY)))
                        pPortal->ResetDoorOrButton();
                }
            }

            nGuardiansOfIcecrownCount = 0;
            uiGuardiansOfIcecrownTimer = 5000;                   //5 seconds for summoning each Guardian of Icecrown in phase 3

            Phase = 0;
            nAbomination = 0;
            nWeaver = 0;
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
        }

        void JustDied(Unit* /*killer*/)
        {
            _JustDied();
            DoScriptText(SAY_DEATH, me);

            std::map<uint64, float>::const_iterator itr;
            for (itr = chained.begin(); itr != chained.end(); ++itr)
            {
                if (Player* player = Unit::GetPlayer(*me, (*itr).first))
                    player->SetObjectScale((*itr).second);
            }
            chained.clear();
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->setFaction(uiFaction);

            _EnterCombat();
            FindGameObjects();
            for (uint8 i = 0; i <= 3; ++i)
            {
                if (GameObject* pPortal = me->GetMap()->GetGameObject(PortalsGUID[i]))
                    pPortal->ResetDoorOrButton();
            }
            DoCast(me, SPELL_KELTHUZAD_CHANNEL, false);
            DoScriptText(SAY_SUMMON_MINIONS, me);
            Phase = 1;
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetFloatValue(UNIT_FIELD_COMBATREACH, 4);
            me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 4);
            events.ScheduleEvent(EVENT_TRIGGER, 5000);
            events.ScheduleEvent(EVENT_WASTE, 15000);
            events.ScheduleEvent(EVENT_ABOMIN, 30000);
            events.ScheduleEvent(EVENT_WEAVER, 50000);
            events.ScheduleEvent(EVENT_PHASE, 228000);
        }

        void FindGameObjects()
        {
            PortalsGUID[0] = instance ? instance->GetData64(DATA_KELTHUZAD_PORTAL01) : 0;
            PortalsGUID[1] = instance ? instance->GetData64(DATA_KELTHUZAD_PORTAL02) : 0;
            PortalsGUID[2] = instance ? instance->GetData64(DATA_KELTHUZAD_PORTAL03) : 0;
            PortalsGUID[3] = instance ? instance->GetData64(DATA_KELTHUZAD_PORTAL04) : 0;
            KTTriggerGUID = instance ? instance->GetData64(DATA_KELTHUZAD_TRIGGER) : 0;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (Phase == 1)
            {
                while (uint32 eventId = events.GetEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WASTE:
                            DoSummon(NPC_WASTE, Pos[RAND(0, 3, 6, 9)]);
                            events.RepeatEvent(urand(2000, 5000));
                            break;
                        case EVENT_ABOMIN:
                            if (nAbomination < 8)
                            {
                                DoSummon(NPC_ABOMINATION, Pos[RAND(1, 4, 7, 10)]);
                                nAbomination++;
                                events.RepeatEvent(20000);
                            }
                            else
                                events.PopEvent();
                            break;
                        case EVENT_WEAVER:
                            if (nWeaver < 8)
                            {
                                DoSummon(NPC_WEAVER, Pos[RAND(0, 3, 6, 9)]);
                                nWeaver++;
                                events.RepeatEvent(25000);
                            }
                            else
                                events.PopEvent();
                            break;
                        case EVENT_TRIGGER:
                            if (GameObject* pKTTrigger = me->GetMap()->GetGameObject(KTTriggerGUID))
                                pKTTrigger->SetPhaseMask(2, true);
                            events.PopEvent();
                            break;
                        case EVENT_PHASE:
                            events.Reset();
                            DoScriptText(RAND(SAY_AGGRO_1, SAY_AGGRO_2, SAY_AGGRO_3), me);
                            spawns.DespawnAll();
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
                            me->CastStop();

                            DoStartMovement(me->getVictim());
                            events.ScheduleEvent(EVENT_BOLT, urand(5000, 10000));
                            events.ScheduleEvent(EVENT_NOVA, 15000);
                            events.ScheduleEvent(EVENT_DETONATE, urand(30000, 40000));
                            events.ScheduleEvent(EVENT_FISSURE, urand(10000, 30000));
                            events.ScheduleEvent(EVENT_BLAST, urand(60000, 120000));
                            if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                                events.ScheduleEvent(EVENT_CHAIN, urand(30000, 60000));
                            Phase = 2;
                            break;
                        default:
                            events.PopEvent();
                            break;
                    }
                }
            }
            else
            {
                //start phase 3 when we are 45% health
                if (Phase != 3)
                {
                    if (HealthBelowPct(45))
                    {
                        Phase = 3;
                        DoScriptText(SAY_REQUEST_AID, me);
                        //here Lich King should respond to KelThuzad but I don't know which Creature to make talk
                        //so for now just make Kelthuzad says it.
                        DoScriptText(SAY_ANSWER_REQUEST, me);

                        for (uint8 i = 0; i <= 3; ++i)
                        {
                            if (GameObject* pPortal = me->GetMap()->GetGameObject(PortalsGUID[i]))
                            {
                                if (pPortal->getLootState() == GO_READY)
                                    pPortal->UseDoorOrButton();
                            }
                        }
                    }
                }
                else if (nGuardiansOfIcecrownCount < RAID_MODE(2, 4))
                {
                    if (uiGuardiansOfIcecrownTimer <= diff)
                    {
                        // TODO : Add missing text
                        if (Creature* pGuardian = DoSummon(NPC_ICECROWN, Pos[RAND(2, 5, 8, 11)]))
                            pGuardian->SetFloatValue(UNIT_FIELD_COMBATREACH, 2);
                        ++nGuardiansOfIcecrownCount;
                        uiGuardiansOfIcecrownTimer = 5000;
                    }
                    else uiGuardiansOfIcecrownTimer -= diff;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.GetEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BOLT:
                            DoCastVictim(RAID_MODE(SPELL_FROST_BOLT, H_SPELL_FROST_BOLT));
                            events.RepeatEvent(urand(5000, 10000));
                            break;
                        case EVENT_NOVA:
                            DoCastAOE(RAID_MODE(SPELL_FROST_BOLT_AOE, H_SPELL_FROST_BOLT_AOE));
                            events.RepeatEvent(urand(15000, 30000));
                            break;
                        case EVENT_CHAIN:
                        {
                            uint32 count = urand(1, 3);
                            for (uint8 i = 1; i <= count; i++)
                            {
                                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 200, true);
                                if (target && !target->isCharmed() && (chained.find(target->GetGUID()) == chained.end()))
                                {
                                    DoCast(target, SPELL_CHAINS_OF_KELTHUZAD);
                                    float scale = target->GetFloatValue(OBJECT_FIELD_SCALE_X);
                                    chained.insert(std::make_pair(target->GetGUID(), scale));
                                    target->SetObjectScale(scale * 2);
                                    events.ScheduleEvent(EVENT_CHAINED_SPELL, 2000); //core has 2000ms to set unit flag charm
                                }
                            }
                            if (!chained.empty())
                                DoScriptText(RAND(SAY_CHAIN_1, SAY_CHAIN_2), me);
                            events.RepeatEvent(urand(100000, 180000));
                            break;
                        }
                        case EVENT_CHAINED_SPELL:
                        {
                            std::map<uint64, float>::iterator itr;
                            for (itr = chained.begin(); itr != chained.end();)
                            {
                                if (Unit* player = Unit::GetPlayer(*me, (*itr).first))
                                {
                                    if (!player->isCharmed())
                                    {
                                        player->SetObjectScale((*itr).second);
                                        std::map<uint64, float>::iterator next = itr;
                                        ++next;
                                        chained.erase(itr);
                                        itr = next;
                                        continue;
                                    }

                                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, NotCharmedTargetSelector()))
                                    {
                                        switch (player->getClass())
                                        {
                                            case CLASS_DRUID:
                                                if (urand(0, 1))
                                                    player->CastSpell(target, SPELL_MOONFIRE, false);
                                                else
                                                    player->CastSpell(me, SPELL_LIFEBLOOM, false);
                                                break;
                                            case CLASS_HUNTER:
                                                player->CastSpell(target, RAND(SPELL_MULTI_SHOT, SPELL_VOLLEY), false);
                                                break;
                                            case CLASS_MAGE:
                                                player->CastSpell(target, RAND(SPELL_FROST_FIREBOLT, SPELL_ARCANE_MISSILES), false);
                                                break;
                                            case CLASS_WARLOCK:
                                                player->CastSpell(target, RAND(SPELL_CURSE_OF_AGONY, SPELL_SHADOW_BOLT), true);
                                                break;
                                            case CLASS_WARRIOR:
                                                player->CastSpell(target, RAND(SPELL_BLADESTORM, SPELL_CLEAVE), false);
                                                break;
                                            case CLASS_PALADIN:
                                                if (urand(0, 1))
                                                    player->CastSpell(target, SPELL_HAMMER_OF_JUSTICE, false);
                                                else
                                                    player->CastSpell(me, SPELL_HOLY_SHOCK, false);
                                                break;
                                            case CLASS_PRIEST:
                                                if (urand(0, 1))
                                                    player->CastSpell(target, SPELL_VAMPIRIC_TOUCH, false);
                                                else
                                                    player->CastSpell(me, SPELL_RENEW, false);
                                                break;
                                            case CLASS_SHAMAN:
                                                if (urand(0, 1))
                                                    player->CastSpell(target, SPELL_EARTH_SHOCK, false);
                                                else
                                                    player->CastSpell(me, SPELL_HEALING_WAVE, false);
                                                break;
                                            case CLASS_ROGUE:
                                                player->CastSpell(target, RAND(SPELL_HEMORRHAGE, SPELL_MUTILATE), false);
                                                break;
                                            case CLASS_DEATH_KNIGHT:
                                                if (urand(0, 1))
                                                    player->CastSpell(target, SPELL_PLAGUE_STRIKE, true);
                                                else
                                                    player->CastSpell(target, SPELL_HOWLING_BLAST, true);
                                                break;
                                        }
                                    }
                                }
                                ++itr;
                            }

                            if (chained.empty())
                                events.PopEvent();
                            else
                                events.RepeatEvent(5000);

                            break;
                        }
                        case EVENT_DETONATE:
                        {
                            std::vector<Unit*> unitList;
                            ThreatContainer::StorageType const &threatList = me->getThreatManager().getThreatList();
                            for (ThreatContainer::StorageType::const_iterator itr = threatList.begin(); itr != threatList.end(); ++itr)
                            {
                                Unit * const target = (*itr)->getTarget();

                                if (target->GetTypeId() == TYPEID_PLAYER
                                        && target->getPowerType() == POWER_MANA
                                        && target->GetPower(POWER_MANA))
                                {
                                    unitList.push_back(target);
                                }
                            }

                            if (!unitList.empty())
                            {
                                std::vector<Unit*>::const_iterator itr = unitList.begin();
                                advance(itr, rand()%unitList.size());
                                DoCast(*itr, SPELL_MANA_DETONATION);
                                DoScriptText(RAND(SAY_SPECIAL_1, SAY_SPECIAL_2, SAY_SPECIAL_3), me);
                            }

                            events.RepeatEvent(urand(20000, 50000));
                            break;
                        }
                        case EVENT_FISSURE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_SHADOW_FISURE);
                            events.RepeatEvent(urand(10000, 45000));
                            break;
                        case EVENT_BLAST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, RAID_MODE(1, 0), 0, true))
                                DoCast(target, SPELL_FROST_BLAST);
                            if (rand()%2)
                                DoScriptText(SAY_FROST_BLAST, me);
                            events.RepeatEvent(urand(30000, 90000));
                            break;
                        default:
                            events.PopEvent();
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_kelthuzadAI (creature);
    }
};

class at_kelthuzad_center : public AreaTriggerScript
{
public:
    at_kelthuzad_center() : AreaTriggerScript("at_kelthuzad_center") { }

    bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/)
    {
        if (player->isGameMaster())
            return false;

        InstanceScript* instance = player->GetInstanceScript();
        if (!instance || instance->IsEncounterInProgress() || instance->GetBossState(BOSS_KELTHUZAD) == DONE)
            return false;

        Creature* pKelthuzad = Unit::GetCreature(*player, instance->GetData64(DATA_KELTHUZAD));
        if (!pKelthuzad)
            return false;

        boss_kelthuzad::boss_kelthuzadAI* pKelthuzadAI = CAST_AI(boss_kelthuzad::boss_kelthuzadAI, pKelthuzad->AI());
        if (!pKelthuzadAI)
            return false;

        pKelthuzadAI->AttackStart(player);
        if (GameObject* trigger = instance->instance->GetGameObject(instance->GetData64(DATA_KELTHUZAD_TRIGGER)))
        {
            if (trigger->getLootState() == GO_READY)
                trigger->UseDoorOrButton();

            // Note: summon must be done by trigger and not by KT.
            // Otherwise, they attack immediately as KT is in combat.
            for (uint8 i = 0; i < MAX_ABOMINATIONS; ++i)
            {
                if (Creature* sum = trigger->SummonCreature(NPC_ABOMINATION, PosAbominations[i]))
                {
                    pKelthuzadAI->spawns.Summon(sum);
                    sum->GetMotionMaster()->MoveRandom(9.0f);
                    sum->SetReactState(REACT_DEFENSIVE);
                }
            }
            for (uint8 i = 0; i < MAX_WASTES; ++i)
            {
                if (Creature* sum = trigger->SummonCreature(NPC_WASTE, PosWastes[i]))
                {
                    pKelthuzadAI->spawns.Summon(sum);
                    sum->GetMotionMaster()->MoveRandom(5.0f);
                    sum->SetReactState(REACT_DEFENSIVE);
                }
            }
            for (uint8 i = 0; i < MAX_WEAVERS; ++i)
            {
                if (Creature* sum = trigger->SummonCreature(NPC_WEAVER, PosWeavers[i]))
                {
                    pKelthuzadAI->spawns.Summon(sum);
                    sum->GetMotionMaster()->MoveRandom(9.0f);
                    sum->SetReactState(REACT_DEFENSIVE);
                }
            }
        }

        return true;
    }
};

class npc_kelthuzad_abomination : public CreatureScript
{
    public:
        npc_kelthuzad_abomination() : CreatureScript("npc_kelthuzad_abomination") { }

        struct npc_kelthuzad_abominationAI : public ScriptedAI
        {
            npc_kelthuzad_abominationAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_MORTAL_WOUND, urand(2000, 5000));
                DoCast(me, SPELL_FRENZY, true);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MORTAL_WOUND:
                            DoCastVictim(SPELL_MORTAL_WOUND, true);
                            _events.ScheduleEvent(EVENT_MORTAL_WOUND, urand(10000, 15000));
                            break;
                        default:
                            break;
                    }
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                if (_instance)
                    _instance->SetData(DATA_ABOMINATION_KILLED, _instance->GetData(DATA_ABOMINATION_KILLED) + 1);
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_kelthuzad_abominationAI(creature);
        }
};

class spell_kelthuzad_detonate_mana : public SpellScriptLoader
{
    public:
        spell_kelthuzad_detonate_mana() : SpellScriptLoader("spell_kelthuzad_detonate_mana") { }

        class spell_kelthuzad_detonate_mana_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_kelthuzad_detonate_mana_AuraScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MANA_DETONATION_DAMAGE))
                    return false;
                return true;
            }

            void HandleScript(AuraEffect const* aurEff)
            {
                PreventDefaultAction();

                Unit* target = GetTarget();
                if (int32 mana = int32(target->GetMaxPower(POWER_MANA) / 10))
                {
                    mana = target->ModifyPower(POWER_MANA, -mana);
                    target->CastCustomSpell(SPELL_MANA_DETONATION_DAMAGE, SPELLVALUE_BASE_POINT0, -mana * 10, target, true, NULL, aurEff);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_kelthuzad_detonate_mana_AuraScript::HandleScript, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_kelthuzad_detonate_mana_AuraScript();
        }
};

class achievement_just_cant_get_enough : public AchievementCriteriaScript
{
   public:
       achievement_just_cant_get_enough() : AchievementCriteriaScript("achievement_just_cant_get_enough") { }

       bool OnCheck(Player* /*player*/, Unit* target)
       {
           if (!target)
               return false;

           if (InstanceScript* instance = target->GetInstanceScript())
               if (instance->GetData(DATA_ABOMINATION_KILLED) >= 18)
                   return true;

           return false;
       }
};

void AddSC_boss_kelthuzad()
{
    new boss_kelthuzad();
    new at_kelthuzad_center();
    new npc_kelthuzad_abomination();
    new spell_kelthuzad_detonate_mana();
    new achievement_just_cant_get_enough();
}
