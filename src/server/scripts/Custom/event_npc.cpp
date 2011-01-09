
#include "ScriptPCH.h"

enum Spells
{
    //===================FireSpells==========================
    SPELL_SUNBEAM_FIRE                               = 62872,
    SPELL_SCORCH_FIRE                                = 63474,
    SPELL_JETS_FIRE                                  = 63472,
    SPELL_FIREBALL_FIRE                              = 68926,
    SPELL_FLAMING_CINDER_FIRE                        = 67332,
    SPELL_BURNING_BITE_FIRE                          = 67626,
    //===================IceSpells===========================
    SPELL_ICEBOLT_ICE                                = 31249,
    SPELL_ICECHAINS_ICE                              = 22744,
    SPELL_FROST_BLAST_ICE                            = 72123,
    SPELL_FROST_BLAST_1_ICE                          = 27808,
    SPELL_FROST_SHIELD_ICE                           = 62650,
    SPELL_ICEBLAST_ICE                               = 28522,
    //===================EarthSpells=========================
    SPELL_NATURE_EARTH                               = 62519, //Stacks
    SPELL_GROUND_EARTH                               = 62859,
    SPELL_LIFEBLOOM_EARTH                            = 67959, // x3 for more powerful healing
    SPELL_WRATH_EARTH                                = 67953,
    SPELL_STUN_EARTH                                 = 52402,
    SPELL_POISON_NOVA_EARTH                          = 68989,
    SPELL_PETRIFYING_BREATH_EARTH                    = 62030,
    //===================DarkSpells==========================
    SPELL_SOULS_SMALL_DARK                           = 72521,
    SPELL_SOULS_LARGE_DARK                           = 72523,
    SPELL_SOULS_SUMMON_DARK                          = 68967,
    SPELL_MIRRORED_DARK                              = 69051,
    SPELL_DEATH_AND_DECAY_DARK                       = 72110,
    SPELL_DARK_VOLLEY_DARK                           = 63038,
    //___________________NPCSpells___________________________
    //===================FireElemental=======================
    SPELL_CURSE_OF_FLAMES_ELEMENTAL                  = 38010,
    SPELL_FLAME_BREATH_ELEMENTAL                     = 64021,
    //===================IceMage=============================
    SPELL_BLIZZARD                                   = 71118,
    SPELL_CONE_OF_COLD                               = 64655,
    SPELL_COUNTERSPELL                               = 59111,
    //===================FireMage============================
    SPELL_HEAL                                       = 71120,
    SPELL_FEL_FIREBALL                               = 66532,
    SPELL_FIRE_NOVA                                  = 68958,
    //===================DeathKnight=========================
    SPELL_FROST_STRIKE                               = 67937,
    SPELL_DEATH_COIL                                 = 67929,
    SPELL_GLACIAL_STRIKE                             = 71317,
    SPELL_ANTIMAGIC_ZONE                             = 51052,
    //===================Warrior=============================
    SPELL_SHOCKWAVE                                  = 75418,
    SPELL_BLOODTHRIST                                = 33964,
    SPELL_DISARM                                     = 15752,
    //===================Common==============================
    SPELL_FRENZY                                     = 47774,  // 15% AS for 2 min. Stacks.
    SPELL_FURY                                       = 66721,  // 5% damage. Stacks
};

enum eEnums
{
    NPC_FIRE_ELEMENTAL                               = 99007,
    GO_ICE_DOOR_1                                    =201910,
    GO_ICE_DOOR_2                                    =201911,
};

#define FIRE_SAY_AGGRO                                "Вам нечего здесь делать. Убирайтесь, пока живы!"
#define FIRE_SAY_FRENZY                               "Ярость наполняет меня!"
#define FIRE_SAY_SUMMON_TITAN                         "Слуги мои, помогите!"
#define FIRE_SAY_KILL                                 "Этим всё и закончится!"
#define FIRE_SAY_DIE                                  "На этот раз... вам повезло..."

class event_npc_firelord : public CreatureScript
{
    public:

        event_npc_firelord()
            : CreatureScript("event_npc_firelord")
        {
        }

        struct event_npc_firelordAI : public ScriptedAI
        {
            event_npc_firelordAI(Creature *c) : ScriptedAI(c),  summons(c) {}
			
            SummonList summons;

            uint32 m_uiSunbeamTimer;
            uint32 m_uiScorchTimer;
            uint32 m_uiJetsTimer;
            uint32 m_uiFireballTimer;
            uint32 m_uiFrenzyTimer;
            uint32 m_uiSummonTimer;
            uint32 m_uiFlamingCinderTimer;
            uint32 m_uiPhase;
            uint32 m_uiSummonCheck;
            uint32 m_uiFuryTimer;
            uint32 m_uiBurningBiteTimer;

            void Reset()
            {
                m_uiSunbeamTimer       =  urand(10000, 30000);
                m_uiScorchTimer        =  urand(10000, 35000);
                m_uiJetsTimer          =  urand(10000, 35000);
                m_uiFireballTimer      =  urand(10000, 28000);
                m_uiFrenzyTimer        =  70000;              //70 seconds
                m_uiSummonTimer        =  60000;
                m_uiFlamingCinderTimer =  urand(10000, 15000);
                m_uiPhase              =  1;
                m_uiSummonCheck        =  0;
                m_uiFuryTimer          =  urand(20000, 30000);
                m_uiBurningBiteTimer   =  urand(12000, 25000);
                me->SetReactState(REACT_DEFENSIVE);
            }

            void JustSummoned(Creature *summon)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                {
                    summon->CastSpell(pTarget, SPELL_CURSE_OF_FLAMES_ELEMENTAL, true);
                    summon->CastSpell(pTarget, SPELL_FLAME_BREATH_ELEMENTAL, true);
                }

                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    summon->AI()->AttackStart(pTarget);
                summons.Summon(summon);
            }

            void EnterCombat(Unit* pWho)
            {
                me->MonsterYell(FIRE_SAY_AGGRO, LANG_UNIVERSAL, 0);
                summons.DespawnAll();
            }

            void EnterEvadeMode()
            {
                ScriptedAI::EnterEvadeMode();
            }
			
            void KilledUnit(Unit *victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    me->MonsterYell(FIRE_SAY_KILL, LANG_UNIVERSAL, 0);
            }
			
            void JustDied(Unit* /*killer*/)
            {
                me->MonsterYell(FIRE_SAY_DIE, LANG_UNIVERSAL, 0);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;
					
                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                if (!me->getVictim())
                {
                    me->CombatStop(true);
                    EnterEvadeMode();
                }

                if (m_uiPhase > 1)
                {
                    //Jets Timer
                    if (m_uiJetsTimer <= uiDiff)
                    {
                        DoCast(me->getVictim(), SPELL_JETS_FIRE);

                        m_uiJetsTimer = urand(10000, 30000);
                    }
                    else
                        m_uiJetsTimer -= uiDiff;

                    //Sunbeam Timer
                    if (m_uiSunbeamTimer <= uiDiff)
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(pTarget, SPELL_SUNBEAM_FIRE);

                        m_uiSunbeamTimer = urand(10000, 20000);
                    }
                    else
                        m_uiSunbeamTimer -= uiDiff;

                    //Scorch Timer
                    if (m_uiScorchTimer <= uiDiff)
                    {
                        DoCast(me->getVictim(), SPELL_SCORCH_FIRE);
                        m_uiScorchTimer = urand(10000, 30000);
                    }
                    else
                        m_uiScorchTimer -= uiDiff;

                    //Fireball Timer
                    if (m_uiFireballTimer <= uiDiff)
                    {
                        DoCast(me->getVictim(), SPELL_FIREBALL_FIRE);
                        m_uiFireballTimer = urand(10000, 25000);
                    }
                    else
                        m_uiFireballTimer -= uiDiff;

                    if (m_uiFrenzyTimer <= uiDiff)
                    {
                        me->MonsterSay(FIRE_SAY_FRENZY, LANG_UNIVERSAL, 0);
                        DoCast(me, SPELL_FRENZY);
                        m_uiFrenzyTimer = urand(20000, 40000);
                    }
                    else
                        m_uiFrenzyTimer -= uiDiff;

                    //Flaming Cinder Timer
                    if (m_uiFlamingCinderTimer <= uiDiff)
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(pTarget, SPELL_FLAMING_CINDER_FIRE, true);

                        m_uiFlamingCinderTimer = urand(10000, 15000);
                    }
                    else
                        m_uiFlamingCinderTimer -= uiDiff;

                }
                else if (m_uiPhase == 1)                            //Phase timer
                {
                    //Frenzy Timer
                    if (m_uiFrenzyTimer <= uiDiff)
                    {
                        ++m_uiPhase;
                        me->MonsterSay(FIRE_SAY_FRENZY, LANG_UNIVERSAL, 0);
                        DoCast(me, SPELL_FRENZY);
                        m_uiFrenzyTimer = urand(30000, 50000);
                    }
                    else
                        m_uiFrenzyTimer -= uiDiff;

                    //Sunbeam Timer
                    if (m_uiSunbeamTimer <= uiDiff)
                    {
                        DoCast(me->getVictim(), SPELL_SUNBEAM_FIRE);

                        m_uiSunbeamTimer = urand(10000, 30000);
                    }
                    else
                        m_uiSunbeamTimer -= uiDiff;

                    //Scorch Timer
                    if (m_uiScorchTimer <= uiDiff)
                    {
                        DoCast(me->getVictim(), SPELL_SCORCH_FIRE);
                        m_uiScorchTimer = urand(10000, 35000);
                    }
                    else
                        m_uiScorchTimer -= uiDiff;
                }
				
                //Summon Timer
                if (m_uiSummonTimer <= uiDiff)
                {
                    me->MonsterYell(FIRE_SAY_SUMMON_TITAN, LANG_TITAN, 0);
                    me->SummonCreature(NPC_FIRE_ELEMENTAL, me->GetPositionX()+2, me->GetPositionY()+2, me->GetPositionZ()+1, 0, TEMPSUMMON_TIMED_DESPAWN, 50000);
                    m_uiSummonTimer = 60000;
                    m_uiSummonCheck = 50000;
                }
                else
                    m_uiSummonTimer -= uiDiff;
					
                //Summon Heal
                if (m_uiSummonCheck <= uiDiff)
                {
                    if (Creature *pElemental = GetClosestCreatureWithEntry(me, NPC_FIRE_ELEMENTAL, INTERACTION_DISTANCE*100))
                    {
                        for (uint8 i = 0; i < 4; ++i)
                            me->CastSpell(me, 71783, true);
                        me->CastSpell(me, SPELL_FURY, true);
                    }

                    m_uiSummonCheck = 1000000;    //Hack
                }
                else
                    m_uiSummonCheck -= uiDiff;

                //Burning Bite Timer
                if (m_uiBurningBiteTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        me->CastSpell(pTarget, SPELL_BURNING_BITE_FIRE, true);

                    m_uiBurningBiteTimer = urand(12000, 25000);
                }
                else
                    m_uiBurningBiteTimer -= uiDiff;

                //Fury Timer
                if (m_uiFuryTimer <= uiDiff)
                {
                    me->CastSpell(me, SPELL_FURY, true);

                    m_uiFuryTimer = urand(25000, 40000);
                }
                else
                    m_uiFuryTimer -= uiDiff;


                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new event_npc_firelordAI(creature);
        }

};

#define ICE_SAY_AGGRO                                "Я проморожу вас насквозь!"
#define ICE_SAY_KILL                                 "Ещё одна бесполезная ледышка!"
#define ICE_SAY_DIE                                  "Но! Я же был бессмертен..."

#define EMOTE_ICE_SHIELD_ICE                         "Кожа Стража льда Алкида покрывается коркой льда"

class event_npc_icelord : public CreatureScript
{
    public:

        event_npc_icelord()
            : CreatureScript("event_npc_icelord")
        {
        }

        struct event_npc_icelordAI : public ScriptedAI
        {
            event_npc_icelordAI(Creature *c) : ScriptedAI(c) {}


            uint32 m_uiIceBoltTimer;
            uint32 m_uiIceChainsTimer;
            uint32 m_uiFrostBlastTimer;
            uint32 m_uiFrostShieldDuration;
            uint32 m_uiFrostShieldCooldown;
            uint32 m_uiFrostBlast;
            uint32 m_uiIceBlastTimer;

            void Reset()
            {
                m_uiIceBoltTimer          = urand(5000, 20000);
                m_uiIceChainsTimer        = urand(10000,25000);
                m_uiFrostBlastTimer       = urand(10000,20000);
                m_uiFrostShieldCooldown   = urand(20000,22000);
                m_uiFrostBlast            = urand(40000,80000);
                m_uiIceBlastTimer         = urand(20000,40000);
                me->SetReactState(REACT_DEFENSIVE);
            }

            void JustSummoned(Creature *summon)
            {
            }

            void EnterCombat(Unit* pWho)
            {
                me->MonsterYell(ICE_SAY_AGGRO, LANG_UNIVERSAL, 0);
            }

            void EnterEvadeMode()
            {
                ScriptedAI::EnterEvadeMode();
            }
			
            void KilledUnit(Unit *victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    me->MonsterYell(ICE_SAY_KILL, LANG_UNIVERSAL, 0);
            }
			
            void JustDied(Unit* /*killer*/)
            {
                if (GameObject *pDoor1 = GetClosestGameObjectWithEntry(me, GO_ICE_DOOR_1, INTERACTION_DISTANCE*1000))
                    if (pDoor1->GetGoState() != GO_STATE_ACTIVE)
                        pDoor1->UseDoorOrButton();
                if (GameObject *pDoor2 = GetClosestGameObjectWithEntry(me, GO_ICE_DOOR_2, INTERACTION_DISTANCE*1000))
                    if (pDoor2->GetGoState() != GO_STATE_ACTIVE)
                        pDoor2->UseDoorOrButton();
                me->MonsterYell(ICE_SAY_DIE, LANG_UNIVERSAL, 0);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;
					
                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                if (!me->getVictim())
                {
                    me->CombatStop(true);
                    EnterEvadeMode();
                }

                //Icebolt Timer
                if (m_uiIceBoltTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        me->CastSpell(pTarget, SPELL_ICEBOLT_ICE, true);

                    m_uiIceBoltTimer = urand(5000, 15000);
                }
                else
                    m_uiIceBoltTimer -= uiDiff;

                //IceBlast Timer
                if (m_uiIceBlastTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        me->CastSpell(pTarget, SPELL_ICEBLAST_ICE, true);

                    m_uiIceBlastTimer = urand(20000,40000);
                }
                else
                    m_uiIceBlastTimer -= uiDiff;

                //Ice Chains Timer
                if (m_uiIceChainsTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_ICECHAINS_ICE);

                    m_uiIceChainsTimer = urand(10000, 17000);
                }
                else
                    m_uiIceChainsTimer -= uiDiff;

                //Frost Blast (AOE) Timer
                if (m_uiFrostBlast <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_FROST_BLAST_1_ICE);

                    m_uiFrostBlast = urand(40000,80000);
                }
                else
                    m_uiFrostBlast -= uiDiff;

                //Frost Blast Timer
                if (m_uiFrostBlastTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_FROST_BLAST_ICE);

                    m_uiFrostBlastTimer = urand(10000,20000);
                }
                else
                    m_uiFrostBlastTimer -= uiDiff;

                //Ice Shield duration
                if (m_uiFrostShieldDuration <= uiDiff && me->HasAura(SPELL_FROST_SHIELD_ICE))
                {
                    me->RemoveAurasDueToSpell(SPELL_FROST_SHIELD_ICE);
                }
                else
                    m_uiFrostShieldDuration -= uiDiff;

                //Ice Shield cooldown
                if (m_uiFrostShieldCooldown <= uiDiff)
                {
                    DoCast(me, SPELL_FROST_SHIELD_ICE);
                    me->MonsterTextEmote(EMOTE_ICE_SHIELD_ICE, 0);
                    m_uiFrostShieldCooldown = urand(20000, 22000);
                    m_uiFrostShieldDuration = urand(10000, 15000);
                }
                else
                    m_uiFrostShieldCooldown -= uiDiff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new event_npc_icelordAI(creature);
        }

};

#define EARTH_SAY_AGGRO                               "Вам не следовало сюда приходить! Это место станет вашей могилой!"
#define EARTH_EMOTE_NATURE                            "Стража замли Акрилия наполняют силы земли"
#define EARTH_SAY_KILL                                "Отправляйся в землю!"
#define EARTH_SAY_DIE                                 "Мать земля, помо... ох..."

class event_npc_earthlord : public CreatureScript
{
    public:

        event_npc_earthlord()
            : CreatureScript("event_npc_earthlord")
        {
        }

        struct event_npc_earthlordAI : public ScriptedAI
        {
            event_npc_earthlordAI(Creature *c) : ScriptedAI(c) {}

            uint32 m_uiNatureTimer;
            uint32 m_uiGroundTimer;
            uint32 m_uiLifebloomTimer;
            uint32 m_uiWrathTimer;
            uint32 m_uiStunTimer;
            uint32 m_uiPoisonNovaTimer;
            uint32 m_uiFuryTimer;
            uint32 m_uiPetrifyingBreathTimer;

            void Reset()
            {
                m_uiNatureTimer           = urand(20000, 30000);
                m_uiGroundTimer           = urand(10000, 30000);
                m_uiLifebloomTimer        = urand(10000, 30000);
                m_uiWrathTimer            = urand(5000,  10000);
                m_uiStunTimer             = urand(10000, 20000);
                m_uiPoisonNovaTimer       = urand(5000,  20000);
                m_uiFuryTimer             = urand(25000, 40000);
                m_uiPetrifyingBreathTimer = urand(10000, 20000);
                me->SetReactState(REACT_DEFENSIVE);
            }

            void JustSummoned(Creature *summon)
            {
            }

            void EnterCombat(Unit* pWho)
            {
                me->MonsterYell(EARTH_SAY_AGGRO, LANG_UNIVERSAL, 0);
                me->RemoveAurasDueToSpell(SPELL_FURY);
            }

            void EnterEvadeMode()
            {
                ScriptedAI::EnterEvadeMode();
            }
			
            void KilledUnit(Unit *victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    me->MonsterYell(EARTH_SAY_KILL, LANG_UNIVERSAL, 0);
            }
			
            void JustDied(Unit* /*killer*/)
            {
                me->MonsterYell(EARTH_SAY_DIE, LANG_UNIVERSAL, 0);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;
					
                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                if (!me->getVictim())
                {
                    me->CombatStop(true);
                    EnterEvadeMode();
                }
				
                //Attuned to Nature Timer
                if (m_uiNatureTimer <= uiDiff)
                {
                    me->CastSpell(me, SPELL_NATURE_EARTH, true);
                    me->MonsterTextEmote(EARTH_EMOTE_NATURE, 0);

                    m_uiNatureTimer = urand(20000, 30000);
                }
                else
                    m_uiNatureTimer -= uiDiff;
					
                //Fury Timer
                if (m_uiFuryTimer <= uiDiff)
                {
                    me->CastSpell(me, SPELL_FURY, true);

                    m_uiFuryTimer = urand(25000, 40000);
                }
                else
                    m_uiFuryTimer -= uiDiff;

                //Ground Tremor Timer
                if (m_uiGroundTimer <= uiDiff)
                {
                    me->CastSpell(me, SPELL_GROUND_EARTH, true);

                    m_uiGroundTimer = urand(15000, 30000);
                }
                else
                    m_uiGroundTimer -= uiDiff;

                //Poison Nova Timer
                if (m_uiPoisonNovaTimer <= uiDiff)
                {
                    me->CastSpell(me, SPELL_POISON_NOVA_EARTH, true);

                    m_uiPoisonNovaTimer = urand(5000, 20000);
                }
                else
                    m_uiPoisonNovaTimer -= uiDiff;

                //Lifebloom Timer
                if (m_uiLifebloomTimer <= uiDiff)
                {
                    for (uint8 i = 0; i < 4; ++i)
                        me->CastSpell(me, SPELL_LIFEBLOOM_EARTH, true);

                    m_uiLifebloomTimer = urand(10000, 30000);
                }
                else
                    m_uiLifebloomTimer -= uiDiff;

                //Wrath Timer
                if (m_uiWrathTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        me->CastSpell(pTarget, SPELL_WRATH_EARTH, true);

                    m_uiWrathTimer = urand(5000,  10000);
                }
                else
                    m_uiWrathTimer -= uiDiff;

                //Petrifying Breath Timer
                if (m_uiPetrifyingBreathTimer <= uiDiff)
                {
                    me->CastSpell(me->getVictim(), SPELL_PETRIFYING_BREATH_EARTH, true);

                    m_uiPetrifyingBreathTimer = urand(10000,  20000);
                }
                else
                    m_uiPetrifyingBreathTimer -= uiDiff;
					
                //Stun Timer
                if (m_uiStunTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        me->CastSpell(pTarget, SPELL_STUN_EARTH, true);

                    m_uiStunTimer = urand(10000, 20000);
                }
                else
                    m_uiStunTimer -= uiDiff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new event_npc_earthlordAI(creature);
        }

};

#define DARK_SAY_AGGRO                                "Гости? Неожиданно..."
#define DARK_SAY_FRENZY                               "О да..! Я чувствую как ваша ярость наполняет меня!"
#define DARK_SAY_SUMMON                               "Посмотрите на души тех, кто был здесь до вас."
#define DARK_SAY_KILL                                 "Твоя душа пополнит мою армию!"
#define DARK_SAY_DIE                                  "Я слишком стар для таких битв..."

class event_npc_darklord : public CreatureScript
{
    public:

        event_npc_darklord()
            : CreatureScript("event_npc_darklord")
        {
        }

        struct event_npc_darklordAI : public ScriptedAI
        {
            event_npc_darklordAI(Creature *c) : ScriptedAI(c) {}

            uint32 m_uiRandom1Timer;
            uint32 m_uiRandom2Timer;
            uint32 m_uiRandom3Timer;
            uint32 m_uiSummonSoulsTimer;
            uint32 m_uiMirroredTimer;
            uint32 m_uiDecayTimer;
            uint32 m_uiVolleyTimer;
            uint32 m_uiFrenzy;
            uint32 m_uiFuryTimer;
            uint32 dPhase;

            void Reset()
            {
                m_uiRandom1Timer        = urand(10000,12000);
                m_uiRandom2Timer        = urand(7000, 12000);
                m_uiRandom3Timer        = urand(11000,15000);
                m_uiFrenzy              = urand(40000,55000);
                m_uiSummonSoulsTimer    = urand(12000,20000);
                m_uiMirroredTimer       = urand(20000,27000);
                m_uiDecayTimer          = urand(15000,45000);
                m_uiVolleyTimer         = urand(15000,37000);
                m_uiFuryTimer           = urand(25000,40000);
                dPhase = 1;
                me->SetReactState(REACT_DEFENSIVE);
            }

            void JustSummoned(Creature *summon)
            {
                summon->CastSpell(summon, SPELL_FRENZY, true);
                summon->CastSpell(summon, SPELL_FURY, true);
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    summon->AI()->AttackStart(pTarget);
            }

            void EnterCombat(Unit* pWho)
            {
                me->MonsterYell(DARK_SAY_AGGRO, LANG_UNIVERSAL, 0);
                me->RemoveAurasDueToSpell(SPELL_FURY);
            }

            void EnterEvadeMode()
            {
                ScriptedAI::EnterEvadeMode();
            }

            void KilledUnit(Unit *victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    me->MonsterYell(DARK_SAY_KILL, LANG_UNIVERSAL, 0);
            }

            void JustDied(Unit* /*killer*/)
            {
                me->MonsterYell(DARK_SAY_DIE, LANG_UNIVERSAL, 0);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;
					
                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                if (!me->getVictim())
                {
                    me->CombatStop(true);
                    EnterEvadeMode();
                }

                //Random 1 Timer
                if (m_uiRandom1Timer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        me->CastSpell(pTarget, urand(0, 1) ? SPELL_SUNBEAM_FIRE : SPELL_FROST_BLAST_ICE, true);

                    m_uiRandom1Timer = urand(10000, 30000);
                }
                else
                    m_uiRandom1Timer -= uiDiff;

                //Random 2 Timer
                if (m_uiRandom2Timer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        me->CastSpell(pTarget, urand(0, 1) ? SPELL_STUN_EARTH : SPELL_GROUND_EARTH, true);

                    m_uiRandom2Timer = urand(7000, 12000);
                }
                else
                    m_uiRandom2Timer -= uiDiff;

                //Random 3 Timer
                if (m_uiRandom3Timer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        me->CastSpell(pTarget, urand(0, 1) ? SPELL_SCORCH_FIRE : SPELL_ICECHAINS_ICE, true);

                    m_uiRandom3Timer = urand(11000,15000);
                }
                else
                    m_uiRandom3Timer -= uiDiff;

                //Mirrored Timer
                if (m_uiMirroredTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        me->CastSpell(pTarget, SPELL_MIRRORED_DARK, true);

                    m_uiMirroredTimer = urand(20000,27000);
                }
                else
                    m_uiMirroredTimer -= uiDiff;

                //Death and Decay Timer
                if (m_uiDecayTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        me->CastSpell(pTarget, SPELL_DEATH_AND_DECAY_DARK, true);

                    m_uiDecayTimer = urand(15000,45000);
                }
                else
                    m_uiDecayTimer -= uiDiff;

                //Dark Volley Timer
                if (m_uiVolleyTimer <= uiDiff)
                {
                    me->CastSpell(me, SPELL_DARK_VOLLEY_DARK, true);

                    m_uiVolleyTimer = urand(15000,45000);
                }
                else
                    m_uiVolleyTimer -= uiDiff;

                //Summon Timer
                if (m_uiSummonSoulsTimer <= uiDiff)
                {
                    for (uint8 n = 0; n < dPhase*4; ++n)
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(pTarget, SPELL_SOULS_SUMMON_DARK, true);

                    me->MonsterSay(DARK_SAY_SUMMON, LANG_UNIVERSAL, 0);
                    m_uiSummonSoulsTimer = urand(12000,20000);
                }
                else
                    m_uiSummonSoulsTimer -= uiDiff;

                //Fury Timer
                if (m_uiFuryTimer <= uiDiff)
                {
                    me->CastSpell(me, SPELL_FURY, true);

                    m_uiFuryTimer = urand(25000, 40000);
                }
                else
                    m_uiFuryTimer -= uiDiff;

                if (dPhase == 1)
                {
                    //Frenzy & Phase Timer
                    if (m_uiFrenzy <= uiDiff)
                    {
                        ++dPhase;
                        me->MonsterSay(DARK_SAY_FRENZY, LANG_UNIVERSAL, 0);
                        me->CastSpell(me, SPELL_FRENZY, true);
                        me->CastSpell(me, SPELL_SOULS_SMALL_DARK, true);
                        m_uiFrenzy = urand(40000,55000);
                    }
                    else
                        m_uiFrenzy -= uiDiff;

                } else if (dPhase < 5 && dPhase !=1) {
                    //Frenzy & Phase Timer
                    if (m_uiFrenzy <= uiDiff)
                    {
                        ++dPhase;
                        me->MonsterSay(DARK_SAY_FRENZY, LANG_UNIVERSAL, 0);
                        me->CastSpell(me, SPELL_FRENZY, true);
                        m_uiFrenzy = urand(40000,50000);
                    }
                    else
                        m_uiFrenzy -= uiDiff;

                } else if (dPhase == 5) {
                    //Frenzy & Phase Timer
                    if (m_uiFrenzy <= uiDiff)
                    {
                        ++dPhase;
                        me->MonsterSay(DARK_SAY_FRENZY, LANG_UNIVERSAL, 0);
                        me->CastSpell(me, SPELL_FRENZY, true);
                        me->CastSpell(me, SPELL_SOULS_LARGE_DARK, true);
                        m_uiFrenzy = urand(40000,55000);
                    }
                    else
                        m_uiFrenzy -= uiDiff;
                } else if (dPhase > 5) {
                    //Frenzy & Phase Timer
                    if (m_uiFrenzy <= uiDiff)
                    {
                        ++dPhase;
                        me->MonsterSay(DARK_SAY_FRENZY, LANG_UNIVERSAL, 0);
                        me->CastSpell(me, SPELL_FRENZY, true);
                        m_uiFrenzy = urand(35000,45000);
                    }
                    else
                        m_uiFrenzy -= uiDiff;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new event_npc_darklordAI(creature);
        }

};

class event_mage_ice : public CreatureScript
{
    public:

        event_mage_ice()
            : CreatureScript("event_mage_ice")
        {
        }

        struct event_mage_iceAI : public ScriptedAI
        {
            event_mage_iceAI(Creature *c) : ScriptedAI(c) {}

            uint32 m_uiBlizzardTimer;
            uint32 m_uiConeTimer;
            uint32 m_uiCounterspellTimer;

            void Reset()
            {
                m_uiBlizzardTimer      = urand(15000, 30000);
                m_uiConeTimer          = urand(10000, 15000);
                m_uiCounterspellTimer  = urand(10000, 20000);
            }

            void JustSummoned(Creature *summon)
            {
            }

            void EnterCombat(Unit* pWho)
            {
            }

            void EnterEvadeMode()
            {
            }
			
            void KilledUnit(Unit *victim)
            {
            }
			
            void JustDied(Unit* /*killer*/)
            {
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;
					
                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;
				
                //Blizzard Timer
                if (m_uiBlizzardTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_BLIZZARD);

                    m_uiBlizzardTimer = urand(15000, 30000);
                }
                else
                    m_uiBlizzardTimer -= uiDiff;

                //Cone of Cold Timer
                if (m_uiConeTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_CONE_OF_COLD);

                    m_uiConeTimer = urand(10000, 15000);
                }
                else
                    m_uiConeTimer -= uiDiff;

                //Counterspell Timer
                if (m_uiCounterspellTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_COUNTERSPELL);

                    m_uiCounterspellTimer = urand(10000, 20000);
                }
                else
                    m_uiCounterspellTimer -= uiDiff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new event_mage_iceAI(creature);
        }

};

class event_mage_fire : public CreatureScript
{
    public:

        event_mage_fire()
            : CreatureScript("event_mage_fire")
        {
        }

        struct event_mage_fireAI : public ScriptedAI
        {
            event_mage_fireAI(Creature *c) : ScriptedAI(c) {}

            uint32 m_uiHealTimer;
            uint32 m_uiFFireballTimer;
            uint32 m_uiFireNovaTimer;

            void Reset()
            {
                m_uiHealTimer      = urand(15000, 20000);
                m_uiFFireballTimer = urand(10000, 15000);
                m_uiFireNovaTimer  = urand(10000, 20000);
            }

            void JustSummoned(Creature *summon)
            {
            }

            void EnterCombat(Unit* pWho)
            {
            }

            void EnterEvadeMode()
            {
            }
			
            void KilledUnit(Unit *victim)
            {
            }
			
            void JustDied(Unit* /*killer*/)
            {
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;
					
                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;
				
                //Chain heal Timer
                if (m_uiHealTimer <= uiDiff)
                {
                    if (Unit *pAlly = DoSelectLowestHpFriendly(INTERACTION_DISTANCE*100))
                        DoCast(pAlly, SPELL_HEAL);

                    m_uiHealTimer = urand(15000, 20000);
                }
                else
                    m_uiHealTimer -= uiDiff;

                //Fel Fireball Timer
                if (m_uiFFireballTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_FEL_FIREBALL);

                    m_uiFFireballTimer = urand(10000, 15000);
                }
                else
                    m_uiFFireballTimer -= uiDiff;

                //Fire Nova timer
                if (m_uiFireNovaTimer <= uiDiff)
                {
                    DoCast(me, SPELL_FIRE_NOVA);

                    m_uiFireNovaTimer = urand(8000,  15000);
                }
                else
                    m_uiFireNovaTimer -= uiDiff;


                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new event_mage_fireAI(creature);
        }

};

class event_dk : public CreatureScript
{
    public:

        event_dk()
            : CreatureScript("event_dk")
        {
        }

        struct event_dkAI : public ScriptedAI
        {
            event_dkAI(Creature *c) : ScriptedAI(c) {}

            uint32 m_uiFrostStrikeTimer;
            uint32 m_uiDeathCoilTimer;
            uint32 m_uiGlacialStrikeTimer;
            uint32 m_uiTapTimer;

            void Reset()
            {
                m_uiFrostStrikeTimer      = urand(6000, 10000);
                m_uiDeathCoilTimer        = urand(5000, 15000);
                m_uiGlacialStrikeTimer    = urand(10000,17000);
                m_uiTapTimer              = urand(12000,17000);
            }

            void JustSummoned(Creature *summon)
            {
            }

            void EnterCombat(Unit* pWho)
            {
            }

            void EnterEvadeMode()
            {
            }
			
            void KilledUnit(Unit *victim)
            {
            }
			
            void JustDied(Unit* /*killer*/)
            {
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;
					
                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;
				
                //Death Coil Timer
                if (m_uiDeathCoilTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_DEATH_COIL);

                    m_uiDeathCoilTimer = urand(5000, 15000);
                }
                else
                    m_uiDeathCoilTimer -= uiDiff;

                //Frost Strike Timer
                if (m_uiFrostStrikeTimer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_FROST_STRIKE);

                    m_uiFrostStrikeTimer = urand(7000, 10000);
                }
                else
                    m_uiFrostStrikeTimer -= uiDiff;

                //Glacial Strike Timer
                if (m_uiGlacialStrikeTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_GLACIAL_STRIKE);

                    m_uiGlacialStrikeTimer = urand(7000, 17000);
                }
                else
                    m_uiGlacialStrikeTimer -= uiDiff;
					
                // Rune Tap Timer
                if (m_uiTapTimer <= uiDiff && !HealthAbovePct(35))
                {
                    me->CastSpell(me, SPELL_ANTIMAGIC_ZONE, true);

                    m_uiTapTimer = urand(12000, 17000);
                }
                else
                    m_uiTapTimer -= uiDiff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new event_dkAI(creature);
        }

};

class event_warrior : public CreatureScript
{
    public:

        event_warrior()
            : CreatureScript("event_warrior")
        {
        }

        struct event_warriorAI : public ScriptedAI
        {
            event_warriorAI(Creature *c) : ScriptedAI(c) {}

            uint32 m_uiShockwaveTimer;
            uint32 m_uiBloodthristTimer;
            uint32 m_uiDisarmTimer;

            void Reset()
            {
                m_uiShockwaveTimer      = urand(8000,12000);
                m_uiBloodthristTimer    = urand(5000, 9000);
                m_uiDisarmTimer         = urand(8000,20000);
            }

            void JustSummoned(Creature *summon)
            {
            }

            void EnterCombat(Unit* pWho)
            {
            }

            void EnterEvadeMode()
            {
            }
			
            void KilledUnit(Unit *victim)
            {
            }
			
            void JustDied(Unit* /*killer*/)
            {
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;
					
                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;
				
                //Shockwave Timer
                if (m_uiShockwaveTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_SHOCKWAVE);

                    m_uiShockwaveTimer = urand(8000, 10000);
                }
                else
                    m_uiShockwaveTimer -= uiDiff;

                //Bloddthrist Timer
                if (m_uiBloodthristTimer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_BLOODTHRIST);

                    m_uiBloodthristTimer = urand(5000, 9000);
                }
                else
                    m_uiBloodthristTimer -= uiDiff;

                //Disarm Timer
                if (m_uiDisarmTimer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_DISARM);

                    m_uiDisarmTimer = urand(8000, 10000);
                }
                else
                    m_uiDisarmTimer -= uiDiff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new event_warriorAI(creature);
        }

};

void AddSC_event_npc()
{
    new event_npc_firelord();
    new event_npc_icelord();
    new event_npc_earthlord();
    new event_npc_darklord();
    new event_mage_ice();
    new event_mage_fire();
    new event_dk();
    new event_warrior();
}

// © gmlt.A [worldofwarcraft.by]
