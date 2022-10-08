/*
    Dungeon : Template of the Jade Serpent 85-87
    Sha of doubt fourth boss
    Jade servers
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

#define TYPE_CLASS_FIGMENT 8
#define TYPE_CLASS_FIGMENT_DIE 9

enum eBosses
{
    BOSS_SHA_OF_DOUBT,
};

enum eSpells
{
    SPELL_WITHER_WILL           = 106736,
    SPELL_TOUCH_OF_NOTHINGNESS  = 106113,
    SPELL_FIGMENT_OF_DOUBT      = 106937,
    SPELL_BOUNDS_OF_REALITY     = 131498,
    SPELL_BOUNDS_OF_REALITY_2   = 117665,
    SPELL_CHI_WAVE              = 132464,
    SPELL_CHI_WAVE_2            = 132466,
    
    SPELL_FIGMENT_OF_DOUBT_2    = 106935,
    SPELL_FIGMENT_OF_DOUBT_3    = 106936,
    SPELL_COPY_WEAPON           = 41054,
    SPELL_COPY_WEAPON_2         = 41055,
    SPELL_GROW                  = 104921,
    SPELL_DROWNED_STATE         = 117509,
    SPELL_DRAW_DOUBT            = 106290,
    SPELL_KNOCK_BACK_SELF       = 117525,
    SPELL_GATHERING_DOUBT       = 117570,
    SPELL_GATHERING_DOUBT_2     = 117571,
    SPELL_INVISIBILITY_DETECTION= 126839,
    SPELL_WEAKENED_BLOWS        = 115798,
    SPELL_RELEASE_DOUBT         = 106112,
};

enum eEvents
{
    EVENT_WITHER_WILL = 1,
    EVENT_TOUCH_OF_NOTHINGNESS = 2,
    EVENT_BOUNDS_OF_REALITY = 3,

    EVENT_GATHERING_DOUBT = 4,

    EVENT_SPELL_PHANTOM_STRIKE = 5,
    EVENT_SPELL_ARMOR_BUFF = 6,
    EVENT_SPELL_FURY = 7,
    EVENT_SANCTUARY = 8,
    EVENT_SIPHON_ESSENCE = 9,
    EVENT_STUN = 10,
    EVENT_BLADE_SONG = 11,
    EVENT_UNTAMED_FURY = 12,
    EVENT_GLIMPSE_OF_MADNESS = 13,
};

enum eCreatures
{
    CREATURE_SHA_OF_DOUBT           = 56439,
};

enum eTalks
{
    TALK_AGGRO,
    TALK_DEATH,
    TALK_FIGMENT_01,
    TALK_FIGMENT_02,
    TALK_RESET,
    TALK_SLAY_01,
    TALK_SLAY_02,
};

class boss_sha_of_doubt : public CreatureScript
{
    public:
        boss_sha_of_doubt() : CreatureScript("boss_sha_of_doubt") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_sha_of_doubt_AI(creature);
        }

        struct boss_sha_of_doubt_AI : public BossAI
        {
            boss_sha_of_doubt_AI(Creature* creature) : BossAI(creature, BOSS_SHA_OF_DOUBT)
            {
                me->CastSpell(me, SPELL_INVISIBILITY_DETECTION, false);
            }
            bool isAtBoundsOfReality;

            void Reset()
            {
                Talk(TALK_RESET);
                events.Reset();
                _Reset();
            }

            void KilledUnit(Unit* u)
            {
                Talk(TALK_SLAY_01 + urand(0, 1));
            }

            void JustDied(Unit* u)
            {
                Talk(TALK_DEATH);
            }

            void EnterCombat(Unit* unit)
            {
                Talk(TALK_AGGRO);
                events.ScheduleEvent(EVENT_WITHER_WILL, 5000);
                events.ScheduleEvent(EVENT_TOUCH_OF_NOTHINGNESS, 500);
                events.ScheduleEvent(EVENT_BOUNDS_OF_REALITY, 3000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WITHER_WILL:
                            if (!me->HasAura(SPELL_BOUNDS_OF_REALITY_2))
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                {
                                    me->CastSpell(target, SPELL_WITHER_WILL, false);
                                    me->CastSpell(target, SPELL_WITHER_WILL, false);
                                }
                            }
                            events.ScheduleEvent(EVENT_WITHER_WILL, 5000);

                            break;
                        case EVENT_TOUCH_OF_NOTHINGNESS:
                            if (!me->HasAura(SPELL_BOUNDS_OF_REALITY_2))
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                    me->CastSpell(target, SPELL_TOUCH_OF_NOTHINGNESS, false);
                            events.ScheduleEvent(EVENT_TOUCH_OF_NOTHINGNESS, 30000);

                            break;
                        case EVENT_BOUNDS_OF_REALITY:
                        {
                            Talk(TALK_FIGMENT_01 + urand(0, 1));
                            if (me->GetInstanceScript())
                                me->GetInstanceScript()->SetData(TYPE_CLASS_FIGMENT, 0);
                            me->CastSpell(me, SPELL_BOUNDS_OF_REALITY_2, false);
                            //Spawns the figment of doubt
                            Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();

                            if (!PlayerList.isEmpty())
                            {
                                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                {
                                    Player* plr = i->getSource();
                                    if (!plr)
                                        continue;
                                    plr->CastSpell(plr, SPELL_FIGMENT_OF_DOUBT_3, false);
                                    plr->CastSpell(plr, SPELL_DRAW_DOUBT, false);
                                }
                            }
                            events.ScheduleEvent(EVENT_BOUNDS_OF_REALITY, 60000);

                            break;
                        }
                        default:
                            break;
                    }
                }
                
                if (!me->HasAura(SPELL_BOUNDS_OF_REALITY_2))
                    DoMeleeAttackIfReady();
            }
        };
};

class mob_figment_of_doubt : public CreatureScript
{
    public:
        mob_figment_of_doubt() : CreatureScript("mob_figment_of_doubt") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_figment_of_doubt_AI(creature);
        }

        enum Classes
        {
            CLASS_DPS,
            CLASS_HEAL,
            CLASS_TANK,
        };

        struct mob_figment_of_doubt_AI : public ScriptedAI
        {
            mob_figment_of_doubt_AI(Creature* creature) : ScriptedAI(creature)
            {
                me->CastSpell(me, SPELL_GROW, false);
                Classes cl = Classes(me->GetInstanceScript()->GetData(TYPE_CLASS_FIGMENT));
                if (cl <= CLASS_TANK)
                    _class = cl;
                else
                    _class = CLASS_DPS;
            }
            EventMap events;
            Classes _class;

            void JustDied(Unit* killer)
            {
                me->CastSpell(me, SPELL_DROWNED_STATE, false);
                me->RemoveAura(SPELL_GATHERING_DOUBT);
                me->ForcedDespawn(5000);
                me->GetInstanceScript()->SetData(TYPE_CLASS_FIGMENT_DIE, _class);
            }

            void EnterCombat(Unit* u)
            {
                me->CastSpell(me, SPELL_GATHERING_DOUBT, false);
                events.ScheduleEvent(EVENT_GATHERING_DOUBT, 1000);
                
                events.ScheduleEvent(EVENT_SIPHON_ESSENCE, 8000);
                switch (_class)
                {
                    case CLASS_DPS:
                        events.ScheduleEvent(EVENT_SPELL_FURY, 5000);
                        events.ScheduleEvent(EVENT_BLADE_SONG, 13000);
                        events.ScheduleEvent(EVENT_GLIMPSE_OF_MADNESS, 8000);
                    case CLASS_HEAL:
                        events.ScheduleEvent(EVENT_SPELL_PHANTOM_STRIKE, 20000);
                        events.ScheduleEvent(EVENT_STUN, 7000);
                    case CLASS_TANK:
                        events.ScheduleEvent(EVENT_SPELL_ARMOR_BUFF, 10000);
                        events.ScheduleEvent(EVENT_SANCTUARY, 10000);
                        events.ScheduleEvent(EVENT_STUN, 7000);
                        break;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GATHERING_DOUBT:
                            if (me->GetAuraCount(SPELL_GATHERING_DOUBT_2) == 30)
                            {
                                me->CastSpell(me, SPELL_RELEASE_DOUBT, false);
                                me->RemoveAura(SPELL_GATHERING_DOUBT);
                                me->DealDamage(me, me->GetMaxHealth());

                                me->ForcedDespawn(5000);

                                uint64 guid_sha_of_doubt = 0;

                                if (me->GetInstanceScript())
                                    guid_sha_of_doubt = me->GetInstanceScript()->GetData64(CREATURE_SHA_OF_DOUBT);

                                if (guid_sha_of_doubt != 0)
                                {
                                    Creature* creature = me->GetMap()->GetCreature(guid_sha_of_doubt);
                                    if (!creature)
                                        return;

                                    const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(SPELL_RELEASE_DOUBT);
                                    if (!spellInfo)
                                        return;

                                    creature->CastSpell(creature, SPELL_CHI_WAVE, true);
                                    me->HealBySpell(creature, spellInfo, uint32(float(creature->GetMaxHealth())* 0.1f));
                                }
                            }
                            else
                                events.ScheduleEvent(EVENT_GATHERING_DOUBT, 1000);
                            break;
                        case EVENT_SPELL_PHANTOM_STRIKE:
                            if (me->getVictim())
                                me->CastSpell(me->getVictim(), 9806, false);
                            events.ScheduleEvent(EVENT_SPELL_PHANTOM_STRIKE, 20000);
                            break;
                        case EVENT_SPELL_ARMOR_BUFF:
                            me->CastSpell(me, 34199, false);
                            events.ScheduleEvent(EVENT_SPELL_ARMOR_BUFF, 10000);
                            break;
                        case EVENT_SPELL_FURY:
                            me->CastSpell(me, 15494, false);
                            events.ScheduleEvent(EVENT_SPELL_FURY, 5000);
                            break;
                        case EVENT_SANCTUARY:
                            me->CastSpell(me, 69207, false);
                            events.ScheduleEvent(EVENT_SANCTUARY, 10000);
                            break;
                        case EVENT_SIPHON_ESSENCE:
                            me->CastSpell(me, 40291, false);
                            events.ScheduleEvent(EVENT_SIPHON_ESSENCE, 8000);
                            break;
                        case EVENT_STUN:
                            if (me->getVictim())
                                me->CastSpell(me->getVictim(), 23454, false);
                            events.ScheduleEvent(EVENT_STUN, 7000);
                            break;
                        case EVENT_BLADE_SONG:
                            me->CastSpell(me, 38282, false);
                            events.ScheduleEvent(EVENT_BLADE_SONG, 13000);
                            break;
                        case EVENT_UNTAMED_FURY:
                            me->CastSpell(me, 23719, false);
                            events.ScheduleEvent(EVENT_UNTAMED_FURY, 9000);
                            break;
                        case EVENT_GLIMPSE_OF_MADNESS:
                            if (me->getVictim())
                                me->CastSpell(me->getVictim(), 26108, false);
                            events.ScheduleEvent(EVENT_GLIMPSE_OF_MADNESS, 8000);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

void AddSC_boss_sha_of_doubt()
{
    new boss_sha_of_doubt();
    new mob_figment_of_doubt();
}