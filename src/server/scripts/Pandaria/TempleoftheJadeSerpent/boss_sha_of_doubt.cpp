#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "temple_of_jade_serpent.h"
#include "Player.h"
#include "Group.h"
#include "ObjectAccessor.h"
#include "LFG.h"

enum eSpellsSha
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

enum eEventsSha
{
    EVENT_WITHER_WILL           = 1,
    EVENT_TOUCH_OF_NOTHINGNESS  = 2,
    EVENT_BOUNDS_OF_REALITY     = 3,

    EVENT_GATHERING_DOUBT       = 4,

    EVENT_SPELL_PHANTOM_STRIKE  = 5,
    EVENT_SPELL_ARMOR_BUFF      = 6,
    EVENT_SPELL_FURY            = 7,
    EVENT_SANCTUARY             = 8,
    EVENT_SIPHON_ESSENCE        = 9,
    EVENT_STUN                  = 10,
    EVENT_BLADE_SONG            = 11,
    EVENT_UNTAMED_FURY          = 12,
    EVENT_GLIMPSE_OF_MADNESS    = 13,
};

enum eTalksSha
{
    TALK_AGGRO,
    TALK_DEATH,
    TALK_FIGMENT_01,
    TALK_FIGMENT_02,
    TALK_RESET,
    TALK_SLAY_01,
    TALK_SLAY_02,
};

enum eActionsSha
{
    ACTION_FIGMENT_POP,
    ACTION_FIGMENT_DIED,
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
            boss_sha_of_doubt_AI(Creature* creature) : BossAI(creature, DATA_SHA_OF_DOUBT_EVENT) { }

            bool isAtBoundsOfReality;
            uint32 figmentsAlives;

            void Reset()
            {
                figmentsAlives = 0;
                me->CastSpell(me, SPELL_INVISIBILITY_DETECTION, false);
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
                events.ScheduleEvent(EVENT_BOUNDS_OF_REALITY, 60000);
            }

            void DoAction(int32 actionId)
            {
                switch (actionId)
                {
                    case ACTION_FIGMENT_POP:
                    {
                        ++figmentsAlives;
                        break;
                    }
                    case ACTION_FIGMENT_DIED:
                    {
                        if(--figmentsAlives <= 0)
                            me->RemoveAura(SPELL_BOUNDS_OF_REALITY_2);
                        break;
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WITHER_WILL:
                        {
                            if (!me->HasAura(SPELL_BOUNDS_OF_REALITY_2))
                            {
                                me->CastSpell(SelectTarget(SELECT_TARGET_RANDOM), SPELL_WITHER_WILL, false);
                                me->CastSpell(SelectTarget(SELECT_TARGET_RANDOM), SPELL_WITHER_WILL, false);
                            }
                            events.ScheduleEvent(EVENT_WITHER_WILL, 5000);
                            break;
                        }
                        case EVENT_TOUCH_OF_NOTHINGNESS:
                        {
                            if (!me->HasAura(SPELL_BOUNDS_OF_REALITY_2))
                                me->CastSpell(SelectTarget(SELECT_TARGET_RANDOM), SPELL_TOUCH_OF_NOTHINGNESS, false);
                            events.ScheduleEvent(EVENT_TOUCH_OF_NOTHINGNESS, 30000);
                            break;
                        }
                        case EVENT_BOUNDS_OF_REALITY:
                        {
                            Talk(TALK_FIGMENT_01 + urand(0, 1));
                            me->CastSpell(me, SPELL_BOUNDS_OF_REALITY_2, false);
                            //Spawns the figment of doubt
                            Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();

                            if (!PlayerList.isEmpty())
                            {
                                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                {
                                    Player* plr = i->GetSource();
                                    if (!plr)
                                        continue;
                                    plr->CastSpell(plr, SPELL_FIGMENT_OF_DOUBT_3, false);
                                    plr->CastSpell(plr, SPELL_DRAW_DOUBT, false);
                                }
                            }
                            events.ScheduleEvent(EVENT_BOUNDS_OF_REALITY, 60000);
                            break;
                        }
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
                _class = CLASS_DPS;
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;
            Classes _class;

            void Reset()
            {
                if (!pInstance)
                    return;

                me->CastSpell(me, SPELL_GROW, false);

                Player* owner = NULL;

                if (TempSummon* tempMe = me->ToTempSummon())
                    if (Unit* summoner = tempMe->GetSummoner())
                        owner = summoner->ToPlayer();

                if (!owner)
                    return;

                me->SetDisplayId(owner->GetDisplayId()); // A check au cas où ça crasherait
                
                uint8 role = lfg::PLAYER_ROLE_DAMAGE;

                if(owner && owner->GetGroup())
                   // role = owner->GetGroup()->GetMemberRole(GetGUID(owner->GetGUID()));
                    role = owner->GetGroup()->GetLfgRoles(owner->GetGUID());

                if (role & lfg::PLAYER_ROLE_DAMAGE)
                    _class = CLASS_DPS;
                else if (role & lfg::PLAYER_ROLE_HEALER)
                    _class = CLASS_HEAL;
                else if (role & lfg::PLAYER_ROLE_TANK)
                    _class = CLASS_TANK;

                owner->CastSpell(me, SPELL_FIGMENT_OF_DOUBT_2, true);

                Creature* sha = me->GetMap()->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(CREATURE_SHA_OF_DOUBT)));
                if(sha && sha->GetAI())
                    sha->GetAI()->DoAction(ACTION_FIGMENT_POP);
            }

            void JustDied(Unit* killer)
            {
                if (!pInstance)
                    return;

                me->CastSpell(me, SPELL_DROWNED_STATE, false);
                me->RemoveAura(SPELL_GATHERING_DOUBT);
                me->DespawnOrUnsummon(5000);
                Creature* sha = me->GetMap()->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(CREATURE_SHA_OF_DOUBT)));
                if(sha && sha->GetAI())
                    sha->GetAI()->DoAction(ACTION_FIGMENT_DIED);
            }

            void EnterCombat(Unit* u)
            {
                if (!pInstance)
                    return;

                me->CastSpell(me, SPELL_GATHERING_DOUBT, false);
                events.ScheduleEvent(EVENT_GATHERING_DOUBT, 1000);
                
                events.ScheduleEvent(EVENT_SIPHON_ESSENCE, 8000);
                switch (_class)
                {
                    case CLASS_DPS:
                        events.ScheduleEvent(EVENT_SPELL_FURY, 5000);
                        events.ScheduleEvent(EVENT_BLADE_SONG, 13000);
                        events.ScheduleEvent(EVENT_GLIMPSE_OF_MADNESS, 8000);
                        break;
                    case CLASS_HEAL:
                        events.ScheduleEvent(EVENT_SPELL_PHANTOM_STRIKE, 20000);
                        events.ScheduleEvent(EVENT_STUN, 7000);
                        break;
                    case CLASS_TANK:
                        events.ScheduleEvent(EVENT_SPELL_ARMOR_BUFF, 10000);
                        events.ScheduleEvent(EVENT_SANCTUARY, 10000);
                        events.ScheduleEvent(EVENT_STUN, 7000);
                        break;
                }

                Creature* sha = me->GetMap()->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(CREATURE_SHA_OF_DOUBT)));
                if(sha && sha->GetAI())
                    sha->GetAI()->DoAction(ACTION_FIGMENT_POP);
            }

            void UpdateAI(uint32 diff)
            {
                if (!pInstance)
                    return;

                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GATHERING_DOUBT:
                        {
                            if (me->GetAuraCount(SPELL_GATHERING_DOUBT_2) == 30)
                            {
                                me->CastSpell(me, SPELL_RELEASE_DOUBT, false);
                                me->RemoveAura(SPELL_GATHERING_DOUBT);
                                me->DealDamage(me, me->GetMaxHealth());

                                me->DespawnOrUnsummon(5000);

                                uint64 guid_sha_of_doubt = pInstance->GetData64(CREATURE_SHA_OF_DOUBT);
                                if (guid_sha_of_doubt != 0)
                                {
                                    Creature* creature = me->GetMap()->GetCreature(pInstance->GetObjectGuid(guid_sha_of_doubt));
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
                        }
                        case EVENT_SPELL_PHANTOM_STRIKE:
                        {
                            me->CastSpell(me->GetVictim(), 9806, false);
                            events.ScheduleEvent(EVENT_SPELL_PHANTOM_STRIKE, 20000);
                            break;
                        }
                        case EVENT_SPELL_ARMOR_BUFF:
                        {
                            me->CastSpell(me, 34199, false);
                            events.ScheduleEvent(EVENT_SPELL_ARMOR_BUFF, 10000);
                            break;
                        }
                        case EVENT_SPELL_FURY:
                        {
                            me->CastSpell(me, 15494, false);
                            events.ScheduleEvent(EVENT_SPELL_FURY, 5000);
                            break;
                        }
                        case EVENT_SANCTUARY:
                        {
                            me->CastSpell(me, 69207, false);
                            events.ScheduleEvent(EVENT_SANCTUARY, 10000);
                            break;
                        }
                        case EVENT_SIPHON_ESSENCE:
                        {
                            me->CastSpell(me, 40291, false);
                            events.ScheduleEvent(EVENT_SIPHON_ESSENCE, 8000);
                            break;
                        }
                        case EVENT_STUN:
                        {
                            me->CastSpell(me->GetVictim(), 23454, false);
                            events.ScheduleEvent(EVENT_STUN, 7000);
                            break;
                        }
                        case EVENT_BLADE_SONG:
                        {
                            me->CastSpell(me, 38282, false);
                            events.ScheduleEvent(EVENT_BLADE_SONG, 13000);
                            break;
                        }
                        case EVENT_UNTAMED_FURY:
                        {
                            me->CastSpell(me, 23719, false);
                            events.ScheduleEvent(EVENT_UNTAMED_FURY, 9000);
                            break;
                        }
                        case EVENT_GLIMPSE_OF_MADNESS:
                        {
                            me->CastSpell(me->GetVictim(), 26108, false);
                            events.ScheduleEvent(EVENT_GLIMPSE_OF_MADNESS, 8000);
                            break;
                        }
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
