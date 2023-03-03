///*
//* Copyright (C) 2012-2013 JadeCore <http://www.pandashan.com/>
//* Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
//* Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
//*
//* This program is free software; you can redistribute it and/or modify it
//* under the terms of the GNU General Public License as published by the
//* Free Software Foundation; either version 2 of the License, or (at your
//* option) any later version.
//*
//* This program is distributed in the hope that it will be useful, but WITHOUT
//* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//* more details.
//*
//* You should have received a copy of the GNU General Public License along
//* with this program. If not, see <http://www.gnu.org/licenses/>.
//*/
//
//#include "GameObjectAI.h"
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "throne_of_thunder.h"  
//
//enum eeSpells
//{
//    // MALAK
//    FRIGID_ASSAULT_AURA = 136904,
//    FRIGID_ASSAULT_STUN = 136910,
//    FRIGID_ASSAULT_STACK = 136903,
//    FRIGID_ASSAULT_DAMAGE = 136990,
//    BITING_COLD_DUMMY = 136917,
//    BITING_COLD_DAMAGE = 136991,
//    BITING_COLD_WORKING_AURA = 136992,
//    // HAUNTED MALAK
//    FROST_BITE_AURA = 136922,
//    FROST_BITE_SCREEN_VISUAL = 136926,
//    FROST_BITE_DUMMY = 136990,
//    FROST_BITE_BEACON = 137575,
//    FROST_BITE_DAMAGE = 136937,
//    // KARAZAJIN
//    SPELL_RECKLESS_CHARGE_SCRIPT = 137107,
//    SPELL_RECKLESS_CHARGE_DUMMY = 137117,
//    SPELL_RECKLESS_CHARGE_FACING = 137121,
//    SPELL_RECKLESS_CHARGE_AOE_VISUAL = 137122, // KNOCK + DAMAGE
//    SPELL_RECKLESS_CHARGE_UNKNOWN_DAMAGE = 137133,
//    SPELL_RECKLESS_CHARGE_AREA_TRIGGEERS = 138026,
//    // HAUNTED KAZARAJIN
//    SPELL_OVERLOAD = 137149,
//    // sul the sandcrawler
//    SPELL_SAND_BOLT = 136190,
//    SPELL_QUICKSAND_VISUAL = 136851,
//    SPELL_QUICKSAND_DOT = 136860,
//    SPELL_QUICKSAND_UNKNOWN_ROOT = 136521,
//    SPELL_ENSNARED = 136878,
//    SPELL_ENTRAPPED = 136857,
//    // Haunted sul the sandcrawler
//    SPELL_SAND_STORM = 136894,
//    SPELL_SAND_STORM_VISUAL = 136895, // handle manually
//    SPELL_SAND_STORM_DAMAGE = 136899,
//    SPELL_FORTIFIED = 136864, // handle hp manually
//    // Priestess Marli
//    SPELL_WRATH_OF_THE_LOA = 137344,
//    SPELL_BLESSING_OF_THE_LOA = 137203,
//    SPELL_BLESSING_OF_THE_LOA_SUMMON = 137200, // SPAWN AT ME
//    // HAUNTED PRIESTESS MARLI
//    SPELL_WRATH_OF_THE_LOA_SHADOW = 137347,
//    SPELL_SHADOW_LOA_SPIRIT = 137350,
//    SPELL_SHADOW_LOA_SPIRIT_SUMMON = 137202,
//
//    // HAUNTED - POSSESSED SPELL
//    SPELL_POSSESSED = 136442,
//
//    // MISC
//    SPELL_SHADOW_FORM = 15473,
//
//    // dark power
//    SPELL_CAST_DARK_POWER = 136507,
//    SPELL_LINGERING_POWER = 136467,
//    SPELL_BERSERK = 26662,
//};
//enum eeTriggers
//{
//
//};
//enum Creatures
//{
//    CREATURE_SULTHE_SANDCRAWLER = 69078,
//    CREATURE_FROST_KING_MALAK = 69131,
//    CREATURE_KARAZAJIN = 69131,
//    CREATURE_HIGH_PRIESTESS = 69131,
//    CREATURE_JARAGAL = 69135,
//    CREATURE_LIVING_SAND = 69153,
//    CREATURE_SPIRIT_LIGHT = 69480,
//    CREATURE_SPIRIT_SHADOW = 69492,
//    TRIGGER_QUICKSAND = 231866,
//
//    /*
//    new creature_quick_sand();
//    new creature_loa_spirit_shadow();
//    new creature_loa_spirit_light();
//    new creature_living_sand();
//    */
//};
//enum eeEvents
//{
//    EVENT_ASSAULT_AURA = 0,
//    EVENT_BITTING_COLD = 1,
//    EVENT_FROST_BITE = 2,
//    EVENT_FROST_BITE_AURA = 50,
//
//    EVENT_RECKLESS_CHARGE = 3,
//    EVENT_RECKLESS_CHARGE_MOVEMENT = 20,
//    CANCEL_OVERLOAD = 21,
//    EVENT_OVERLOAD = 4,
//
//    EVENT_SAND_BOLT = 5,
//    EVENT_QUICKSAND = 6,
//    EVENT_SPELL_ENSNARED = 7,
//
//    EVENT_WRATH_OF_THE_LOA = 8,
//    EVENT_SHADOW_LOA_SPIRIT = 9,
//    EVENT_BLESSING_LOA_SPIRIT = 10,
//    EVENT_WRATH_OF_THE_LOA_LIGHT = 11,
//
//    // EMPOWERED
//    EVENT_CAST_DARK_POWER = 12,
//
//    // Actions
//    EVENT_INITIALIZE_FIGHT = 13,
//    EVENT_CONTINUE_FIGHT = 14,
//
//    EVENT_SANDSTORM = 15,
//};
//enum eeActions
//{
//    ACTION_COMBAT_STARTED = 899,
//    ACTION_POSSESSED_PHASE = 900,
//    ACTION_CONTINUE_POSSESSION_CHAIN = 901,
//};
//enum eeTalks
//{
//    // Malak
//    MALAK_AGGRO = 100, // Ya' have met your match fools! (35387) 
//    MALAK_DEATH = 101, // The emprire.. can't fall.. ((35388)
//    MALAK_EVENT_01 = 102, // Winter.. is.. coming.. (35389)
//    MALAK_INTRO_01 = 103, // The Drakari will never fall to the likes of you.. (35390)
//    MALAK_KILL_01 = 104, // Death's cold embrace... (35391)
//    MALAK_KILL_02 = 105, // Weakness.. the Drakari's mate. (35392)
//    MALAK_SPELL_01 = 106, // Getting.. Cold? (35393)
//    MALAK_SPELL_02 = 107, // Freeze! (35394)
//    // Sul
//    SUL_AGGRO = 110, // The sand will consume everything! (35812)
//    SUL_EVENT01 = 111, // I'll burry you all! (35813)
//    SUL_SLAY = 112, // The sand are endless (35815) / The first of many (35816)
//    SUL_DEATH = 50, // I return... to the sands (36454)
//    // Marli
//    MARLI_AGGRO = 113, // Death to all who oppose the empire! (35432)
//    MARLI_DEATH = 114, // Sha'dra.. save me (35433)
//    MARLI_SAY = 115, // Another offering to the loa! (35436)
//    MARLI_SPELL01 = 116, // Embrace your demise! (35440)
//    // Garjal
//    GARJAL_SAY01 = 117, // Let me share this gift with ye' (35395)
//    GARJAL_SAY02 = 118, // Your spirit is mine (35396)
//    GARJAL_SAY03 = 119, // The thunder king will reward us for stoppin' ye' (35397)
//    GARJAL_SAY04 = 120, // Witness the power! of the spirit binder! (35398)
//    GARJAL_SAY05 = 121, // Time to die! (35399)
//    GARJAL_SAY06 = 122, // The Zandalari cannot be stopped (35400)
//    GARJAL_SAY07 = 123, // With the Thunda' king power! the Zandalari will be reborn! (35401)
//    GARJAL_SAY08 = 124, // Lei shen's power, makes us stronger! (35402)
//    GARJAL_SAY09 = 125, // Your soul will pay the price! (35403)
//    GARJAL_SAY10 = 126, // These fouls thought they beat me once before, they only make me stronger! Now we show dem the true power of the Zandalari! (35404)
//    GARJAL_SAY11 = 127, // Lei shen, let us proove you the might of the Zanadalari. We'll crush this intruders with a stand! (35405)
//    GARJAL_SAY12 = 128, // We'll never fail ye'.
//    // Kazarjin
//    KAZARJIN_AGGRO = 129, // Haha.. This.. is gonna hurt! (35566)
//    KAZARJIN_DEATH = 130, // The thunder king.. promised! (35567)
//    KAZARJIN_SLAY = 131, // Haha.. you shouldn't be missin' with the Zandalari (35571)
//};
//
//// Bob Marli
//#define blessingloaspiritinterval urand(20000, 35000)
//#define wrathoftheloainterval urand(5000, 8000)
//#define shadowloaspiritinterval urand(20000, 35000)
//#define recklessinterval urand(10000, 20000)
//#define overloadinterval urand(25000)
//
//
//class garajin_rp : public BasicEvent
//{
//public:
//    explicit garajin_rp(Unit* unit, int value) : obj(unit), modifier(value)
//    {
//    }
//
//    bool Execute(uint64 /*currTime*/, uint32 /*diff*/)
//    {
//        if (InstanceScript* instance = obj->GetInstanceScript())
//        {
//            if (Creature* garjal = instance->instance->GetCreature(instance->GetData64(DATA_GARAJAL)))
//            {
//                switch (modifier)
//                {
//                case 0:
//                    garjal->AI()->Talk(GARJAL_SAY01);
//                    garjal->m_Events.AddEvent(new garajin_rp(garjal, 1), garjal->m_Events.CalculateTime(20000));
//                    break;
//                case 1:
//                    garjal->AI()->Talk(GARJAL_SAY02);
//                    garjal->m_Events.AddEvent(new garajin_rp(garjal, 2), garjal->m_Events.CalculateTime(20000));
//                    break;
//                case 2:
//                    garjal->AI()->Talk(GARJAL_SAY03);
//                    garjal->m_Events.AddEvent(new garajin_rp(garjal, 3), garjal->m_Events.CalculateTime(20000));
//                    break;
//                case 3:
//                    garjal->AI()->Talk(GARJAL_SAY04);
//                    garjal->m_Events.AddEvent(new garajin_rp(garjal, 4), garjal->m_Events.CalculateTime(20000));
//                    break;
//                case 4:
//                    garjal->AI()->Talk(GARJAL_SAY05);
//                    garjal->m_Events.AddEvent(new garajin_rp(garjal, 5), garjal->m_Events.CalculateTime(20000));
//                    break;
//                case 5:
//                    garjal->AI()->Talk(GARJAL_SAY06);
//                    garjal->m_Events.AddEvent(new garajin_rp(garjal, 6), garjal->m_Events.CalculateTime(20000));
//                    break;
//                case 6:
//                    garjal->AI()->Talk(GARJAL_SAY07);
//                    garjal->m_Events.AddEvent(new garajin_rp(garjal, 7), garjal->m_Events.CalculateTime(20000));
//                    break;
//                case 7:
//                    garjal->AI()->Talk(GARJAL_SAY08);
//                    garjal->m_Events.AddEvent(new garajin_rp(garjal, 8), garjal->m_Events.CalculateTime(20000));
//                    break;
//                case 8:
//                    garjal->AI()->Talk(GARJAL_SAY09);
//                    garjal->m_Events.AddEvent(new garajin_rp(garjal, 9), garjal->m_Events.CalculateTime(20000));
//                    break;
//                case 9:
//                    garjal->AI()->Talk(GARJAL_SAY10);
//                    garjal->m_Events.AddEvent(new garajin_rp(garjal, 10), garjal->m_Events.CalculateTime(20000));
//                    break;
//                case 10:
//                    garjal->AI()->Talk(GARJAL_SAY11);
//                    garjal->m_Events.AddEvent(new garajin_rp(garjal, 11), garjal->m_Events.CalculateTime(20000));
//                    break;
//                case 11:
//                    garjal->AI()->Talk(GARJAL_SAY12);
//                    break;
//                }
//            }
//        }
//        return true;
//    }
//private:
//    Creature* storm;
//    Unit* obj;
//    int modifier;
//    int Event;
//};
//class creature_garajal_spirit : public CreatureScript
//{
//public:
//    creature_garajal_spirit() : CreatureScript("creature_garajal_spirit") { }
//
//    struct creature_garajal_spiritAI : public BossAI
//    {
//        creature_garajal_spiritAI(Creature* creature) : BossAI(creature, DATA_GARAJAL)
//        {
//            pInstance = creature->GetInstanceScript();
//        }
//
//        InstanceScript* pInstance;
//        EventMap events;
//
//        bool intro;
//        int32 listposition;
//
//        void Reset()
//        {
//            _Reset();
//            events.Reset();
//            summons.DespawnAll();
//
//            listposition = 0;
//        }
//        void JustReachedHome()
//        {
//            _JustReachedHome();
//
//            if (pInstance)
//                pInstance->SetBossState(DATA_GARAJAL, FAIL);
//        }
//        void EnterCombat(Unit* attacker)
//        {
//            if (pInstance)
//            {
//                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//                DoZoneInCombat();
//            }
//        }
//        void JustSummoned(Creature* summon)
//        {
//            summons.Summon(summon);
//        }
//        void DoAction(const int32 action)
//        {
//            if (action == ACTION_COMBAT_STARTED)
//            {
//                events.ScheduleEvent(EVENT_INITIALIZE_FIGHT, 1500);
//            }
//            if (action == ACTION_CONTINUE_POSSESSION_CHAIN)
//            {
//                events.ScheduleEvent(EVENT_CONTINUE_FIGHT, 1500);
//            }
//        }
//        void SummonedCreatureDespawn(Creature* summon)
//        {
//            summons.Despawn(summon);
//        }
//        void DespawnCreaturesInArea(uint32 entry, WorldObject* object)
//        {
//            std::list<Creature*> creatures;
//            GetCreatureListWithEntryInGrid(creatures, object, entry, 300.0f);
//            if (creatures.empty())
//                return;
//
//            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
//                (*iter)->DespawnOrUnsummon();
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            events.Update(diff);
//
//            switch (events.ExecuteEvent())
//            {
//            case EVENT_INITIALIZE_FIGHT:
//            {
//                if (Creature* Malak = instance->instance->GetCreature(instance->GetData64(DATA_MALAK)))
//                {
//                    Malak->m_Events.AddEvent(new garajin_rp(Malak, 0), Malak->m_Events.CalculateTime(5000));
//
//                    Malak->GetAI()->DoAction(ACTION_POSSESSED_PHASE);
//                    listposition = DATA_MALAK;
//                }
//                break;
//            }
//            case EVENT_CONTINUE_FIGHT:
//            {
//                std::list<Creature*> boss_list;
//
//                boss_list.clear();
//
//                if (instance)
//                {
//                    if (Creature* Sul = instance->instance->GetCreature(instance->GetData64(DATA_SAND_CRAWLER)))
//                    {
//                        if (Creature* Malak = instance->instance->GetCreature(instance->GetData64(DATA_MALAK)))
//                        {
//                            if (Creature* Marli = instance->instance->GetCreature(instance->GetData64(DATA_HIGH_PRIESTSESS)))
//                            {
//                                if (Creature* Kaz = instance->instance->GetCreature(instance->GetData64(DATA_KARAZJIN)))
//                                {
//                                    if (Sul->HasAura(SPELL_POSSESSED) || Malak->HasAura(SPELL_POSSESSED) || Marli->HasAura(SPELL_POSSESSED) || Kaz->HasAura(SPELL_POSSESSED))
//                                        return;
//
//                                    boss_list.push_back(Sul);
//                                    boss_list.push_back(Malak);
//                                    boss_list.push_back(Kaz);
//                                    boss_list.push_back(Marli);
//                                }
//                            }
//                        }
//                    }
//
//                    if (boss_list.empty())
//                        return;
//
//                    std::list<Creature*>::const_iterator it = boss_list.begin();
//                    std::advance(it, urand(0, boss_list.size() - 1));
//
//                    // add aura
//                    if ((*it) && (*it)->isAlive() && (*it)->IsInWorld())
//                    {
//                        (*it)->AddAura(SPELL_POSSESSED, (*it));
//
//                        if ((*it)->GetAI())
//                            (*it)->GetAI()->DoAction(ACTION_POSSESSED_PHASE);
//
//                        boss_list.remove((*it));
//                    }
//                }
//                break;
//            }
//            }
//
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new creature_garajal_spiritAI(creature);
//    }
//};
//class boss_malak : public CreatureScript
//{
//public:
//    boss_malak() : CreatureScript("boss_malak") { }
//
//    struct boss_malakAI : public BossAI
//    {
//        boss_malakAI(Creature* creature) : BossAI(creature, DATA_MALAK)
//        {
//            pInstance = creature->GetInstanceScript();
//            intro = false;
//        }
//
//        InstanceScript* pInstance;
//        EventMap events;
//
//        bool intro;
//        uint32 damage;
//        int32 hppcts;
//        Unit* target;
//
//        void Reset()
//        {
//            _Reset();
//            events.Reset();
//            summons.DespawnAll();
//            target = NULL;
//
//            hppcts = me->GetHealthPct() * 0.85;
//            me->SetMaxHealth(89000000);
//            me->SetHealth(89000000);
//
//            me->RemoveAllAuras();
//
//            me->SetHealth(me->GetMaxHealth());
//
//            me->SetPower(POWER_ENERGY, 0);
//            me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//            me->SetMaxPower(POWER_ENERGY, 100);
//            me->SetInt32Value(UNIT_FIELD_MAXPOWER1, 100);
//            me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
//        }
//        void JustReachedHome()
//        {
//            _JustReachedHome();
//            summons.DespawnAll();
//
//            if (pInstance)
//                pInstance->SetBossState(DATA_MALAK, FAIL);
//
//            if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64(DATA_GARAJAL)))
//            {
//                if (Creature* Sul = instance->instance->GetCreature(instance->GetData64(DATA_SAND_CRAWLER)))
//                {
//                    if (Creature* Marli = instance->instance->GetCreature(instance->GetData64(DATA_HIGH_PRIESTSESS)))
//                    {
//                        if (Creature* Kaz = instance->instance->GetCreature(instance->GetData64(DATA_KARAZJIN)))
//                        {
//                            Garjal->m_Events.KillAllEvents(true);
//
//                            Sul->GetMotionMaster()->MovePoint(0, Sul->GetHomePosition().GetPositionX(), Sul->GetHomePosition().GetPositionY(), Sul->GetHomePosition().GetPositionZ());
//                            Marli->GetMotionMaster()->MovePoint(0, Marli->GetHomePosition().GetPositionX(), Marli->GetHomePosition().GetPositionY(), Marli->GetHomePosition().GetPositionZ());
//                            Kaz->GetMotionMaster()->MovePoint(0, Kaz->GetHomePosition().GetPositionX(), Kaz->GetHomePosition().GetPositionY(), Kaz->GetHomePosition().GetPositionZ());
//                            Garjal->GetMotionMaster()->MovePoint(0, Garjal->GetHomePosition().GetPositionX(), Garjal->GetHomePosition().GetPositionY(), Garjal->GetHomePosition().GetPositionZ());
//                            me->GetMotionMaster()->MovePoint(0, me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ());
//
//                            me->Respawn();
//                            Sul->Respawn();
//                            Marli->Respawn();
//                            Kaz->Respawn();
//                            Garjal->Respawn();
//
//                            me->AI()->Reset();
//                            Sul->AI()->Reset();
//                            Marli->AI()->Reset();
//                            Kaz->AI()->Reset();
//                            Garjal->AI()->Reset();
//                        }
//                    }
//                }
//            }
//        }
//        void EnterCombat(Unit* attacker)
//        {
//            if (pInstance)
//            {
//                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//                DoZoneInCombat();
//            }
//
//            me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//
//            if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64(DATA_GARAJAL)))
//            {
//                if (Creature* Sul = instance->instance->GetCreature(instance->GetData64(DATA_SAND_CRAWLER)))
//                {
//                    if (Creature* Marli = instance->instance->GetCreature(instance->GetData64(DATA_HIGH_PRIESTSESS)))
//                    {
//                        if (Creature* Kaz = instance->instance->GetCreature(instance->GetData64(DATA_KARAZJIN)))
//                        {
//                            
//                            Sul->Attack(attacker, true);
//                            Kaz->Attack(attacker, false);
//                            me->Attack(attacker, true);
//                            Marli->Attack(attacker, true);
//
//                            Sul->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                            Kaz->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                            me->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                            Marli->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                        }
//                    }
//                }
//            }
//
//            Talk(MALAK_AGGRO);
//
//            // Start possession phase
//            if (Creature* Garajal = instance->instance->GetCreature(instance->GetData64(DATA_GARAJAL)))
//            {
//                Garajal->GetAI()->DoAction(ACTION_COMBAT_STARTED);
//            }
//
//            events.ScheduleEvent(EVENT_ASSAULT_AURA, 30000);
//            events.ScheduleEvent(EVENT_BITTING_COLD, 20000);
//        }
//        void JustSummoned(Creature* summon)
//        {
//            summons.Summon(summon);
//        }
//        void SummonedCreatureDespawn(Creature* summon)
//        {
//            summons.Despawn(summon);
//        }
//        void DespawnCreaturesInArea(uint32 entry, WorldObject* object)
//        {
//            std::list<Creature*> creatures;
//            GetCreatureListWithEntryInGrid(creatures, object, entry, 300.0f);
//            if (creatures.empty())
//                return;
//
//            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
//                (*iter)->DespawnOrUnsummon();
//        }
//        void DamageTaken(Unit* /*attacker*/, uint32& damage)
//        {
//            if (hppcts && me->HasAura(SPELL_POSSESSED))
//            {
//                if (me->HealthBelowPctDamaged(hppcts, damage))
//                {
//                    me->RemoveAura(SPELL_POSSESSED);
//
//                    if (!me->HasAura(SPELL_LINGERING_POWER))
//                    {
//                        me->AddAura(SPELL_LINGERING_POWER, me);
//                    }
//                    else
//                    {
//                        AuraPtr aura = me->GetAura(SPELL_LINGERING_POWER);
//
//                        if (aura)
//                        {
//                            aura->SetStackAmount(aura->GetStackAmount() + 1);
//                        }
//                    }
//
//                    me->RemoveAura(SPELL_SHADOW_FORM);
//
//                    events.CancelEvent(EVENT_CAST_DARK_POWER);
//                    events.CancelEvent(EVENT_FROST_BITE);
//                    events.ScheduleEvent(EVENT_ASSAULT_AURA, 30000);
//                    events.ScheduleEvent(EVENT_BITTING_COLD, 40000);
//
//                    // add aura
//                    if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64((DATA_GARAJAL))))
//                    {
//                        Garjal->GetAI()->DoAction(ACTION_CONTINUE_POSSESSION_CHAIN);
//                    }
//                }
//            }
//        }
//        void DoAction(const int32 action)
//        {
//            if (action == ACTION_POSSESSED_PHASE)
//            {
//                me->AddAura(SPELL_POSSESSED, me);
//                hppcts = me->GetHealthPct() * 0.85;
//
//                damage = 0;
//
//                me->SetPower(POWER_ENERGY, 0);
//                me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//
//                events.ScheduleEvent(EVENT_FROST_BITE, 5000);
//            }
//        }
//        void MoveInLineOfSight(Unit* who)
//        {
//            if (who && who->IsInWorld() && who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 35.0f) && !intro)
//            {
//                intro = true;
//                Talk(MALAK_INTRO_01);
//            }
//        }
//        void JustDied(Unit* killer)
//        {
//            Talk(MALAK_DEATH);
//
//
//            if (Creature* Sul = instance->instance->GetCreature(instance->GetData64(DATA_SAND_CRAWLER)))
//            {
//                if (Creature* Marli = instance->instance->GetCreature(instance->GetData64(DATA_HIGH_PRIESTSESS)))
//                {
//                    if (Creature* Kaz = instance->instance->GetCreature(instance->GetData64(DATA_KARAZJIN)))
//                    {
//                        if (Sul->isDead() && Marli->isDead() && Kaz->isDead())
//                        {
//                            if (Creature* Garajal = instance->instance->GetCreature(instance->GetData64(DATA_GARAJAL)))
//                            {
//                                if (killer)
//                                    killer->Kill(Garajal);
//
//                                std::list<Player*> pl_list;
//                                pl_list.clear();
//
//                                me->GetPlayerListInGrid(pl_list, 100.0f);
//
//                                if (pl_list.empty())
//                                    return;
//
//                                CurrencyOnKillEntry const* Curr = sObjectMgr->GetCurrencyOnKillEntry(me->ToCreature()->GetEntry());
//                                if (!Curr)
//                                    return;
//
//                                for (auto itr : pl_list)
//                                {
//                                    if (Curr->currencyId1 && Curr->currencyCount1)
//                                    {
//                                        if (CurrencyTypesEntry const* entry = sCurrencyTypesStore.LookupEntry(Curr->currencyId1))
//                                        {
//                                            if (Curr->currencyId1 == CURRENCY_TYPE_JUSTICE_POINTS)
//                                            {
//                                                if ((itr->GetCurrency(Curr->currencyId1, true) + Curr->currencyCount1) > itr->GetCurrencyTotalCap(entry))
//                                                {
//                                                    uint32 max = itr->GetCurrencyTotalCap(entry);
//                                                    uint32 lessPoint = max - itr->GetCurrency(Curr->currencyId1, true);
//                                                    uint32 rest = Curr->currencyCount1 - lessPoint;
//
//                                                    itr->ModifyCurrency(Curr->currencyId1, lessPoint);
//                                                }
//                                                else
//                                                    itr->ModifyCurrency(Curr->currencyId1, Curr->currencyCount1);
//                                            }
//                                            else
//                                                itr->ModifyCurrency(Curr->currencyId1, Curr->currencyCount1);
//                                        }
//                                    }
//                                }
//                            }
//                        }
//                        else
//                        {
//                            me->SetLootRecipient(NULL);
//                        }
//                    }
//                }
//            }
//
//            // add aura
//            if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64((DATA_GARAJAL))))
//            {
//                Garjal->GetAI()->DoAction(ACTION_CONTINUE_POSSESSION_CHAIN);
//            }
//        }
//        void KilledUnit(Unit* who) override
//        {
//            if (who->GetTypeId() == TYPEID_PLAYER)
//                Talk(MALAK_KILL_01);
//        }
//        void RegeneratePower(Powers power, int32& value)
//        {
//            if (power != POWER_ENERGY)
//                return;
//
//            if (!me->HasAura(SPELL_POSSESSED))
//                return;
//
//            AuraPtr aura = me->GetAura(SPELL_POSSESSED);
//
//            // Council Empowered boss regenerates 6 energy every 2s (15 energy for 5s) 
//            /*
//            if (aura->GetCharges() == 1)
//            value = 3;;
//            else
//            value = 3 + (aura->GetCharges() * 0.10);
//            */
//
//            value = 3;;
//
//            int32 val = me->GetPower(POWER_ENERGY);
//            if (val + value > 100)
//                val = 100;
//            else
//                val += value;
//            /*
//            if (value >= 100)
//            {
//            me->SetPower(POWER_ENERGY, 0);
//            me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//            events.ScheduleEvent(EVENT_CAST_DARK_POWER, 1000);
//            }
//            */
//            me->SetInt32Value(UNIT_FIELD_POWER1, val);
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (me->GetUInt32Value(UNIT_FIELD_POWER1) == 100 && me->HasAura(SPELL_POSSESSED))
//            {
//                me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//                events.ScheduleEvent(EVENT_CAST_DARK_POWER, 100);
//                events.CancelEvent(EVENT_FROST_BITE);
//                events.CancelEvent(EVENT_BITTING_COLD);
//                events.CancelEvent(EVENT_ASSAULT_AURA);
//
//                Talk(MALAK_EVENT_01);
//            }
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            switch (events.ExecuteEvent())
//            {
//            case EVENT_ASSAULT_AURA:
//            {
//                me->AddAura(FRIGID_ASSAULT_AURA, me);
//                events.ScheduleEvent(EVENT_ASSAULT_AURA, 30000);
//                break;
//            }
//            case EVENT_BITTING_COLD:
//            {
//                if (Unit* random = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true, -BITING_COLD_WORKING_AURA))
//                {
//                    Talk(MALAK_SPELL_01);
//
//                    me->CastSpell(random, BITING_COLD_DUMMY);
//                    events.ScheduleEvent(EVENT_BITTING_COLD, 40000);
//                }
//                break;
//            }
//            case EVENT_FROST_BITE:
//            {
//                if (Unit* random = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
//                {
//                    target = random;
//                    Talk(MALAK_SPELL_02);
//
//                    me->CastSpell(random, FROST_BITE_BEACON);
//                    events.ScheduleEvent(EVENT_FROST_BITE, 30000);
//                    events.ScheduleEvent(EVENT_FROST_BITE_AURA, 4000);
//                }
//                break;
//            }
//            case EVENT_FROST_BITE_AURA:
//            {
//                if (target == NULL)
//                    return;
//
//                me->CastSpell(target, FROST_BITE_AURA);
//
//                if (target->HasAura(FROST_BITE_AURA))
//                {
//                    AuraPtr aura = target->GetAura(FROST_BITE_AURA);
//
//                    if (aura)
//                    {
//                        aura->SetStackAmount(5);
//                    }
//                }
//                break;
//            }
//            case EVENT_CAST_DARK_POWER:
//            {
//                events.CancelEvent(EVENT_FROST_BITE);
//                events.CancelEvent(EVENT_BITTING_COLD);
//                events.CancelEvent(EVENT_ASSAULT_AURA);
//                int32 calc = 10000 + (damage * 10000);
//
//                me->CastCustomSpell(me, SPELL_CAST_DARK_POWER, &calc, NULL, NULL, true, NULL);
//                damage += 0.10;
//                events.ScheduleEvent(EVENT_CAST_DARK_POWER, 1000);
//                break;
//            }
//            }
//
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new boss_malakAI(creature);
//    }
//};
//class boss_sul : public CreatureScript
//{
//public:
//    boss_sul() : CreatureScript("boss_sul") { }
//
//    struct boss_sulAI : public BossAI
//    {
//        boss_sulAI(Creature* creature) : BossAI(creature, DATA_SAND_CRAWLER)
//        {
//            pInstance = creature->GetInstanceScript();
//        }
//
//        InstanceScript* pInstance;
//        EventMap events;
//
//        bool intro;
//        int32 hppcts;
//        uint32 damage;
//
//        void Reset()
//        {
//            _Reset();
//            events.Reset();
//            summons.DespawnAll();
//
//            me->SetMaxHealth(89000000);
//            me->SetHealth(89000000);
//
//            me->RemoveAllAuras();
//            hppcts = me->GetHealthPct() * 0.85;
//
//            me->SetHealth(me->GetMaxHealth());
//            me->SetPower(POWER_ENERGY, 0);
//            me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//            me->SetMaxPower(POWER_ENERGY, 100);
//            me->SetInt32Value(UNIT_FIELD_MAXPOWER1, 100);
//            me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
//        }
//        void JustReachedHome()
//        {
//            _JustReachedHome();
//
//            summons.DespawnAll();
//
//            if (pInstance)
//                pInstance->SetBossState(DATA_SAND_CRAWLER, FAIL);
//
//            if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64(DATA_GARAJAL)))
//            {
//                if (Creature* Malak = instance->instance->GetCreature(instance->GetData64(DATA_MALAK)))
//                {
//                    if (Creature* Marli = instance->instance->GetCreature(instance->GetData64(DATA_HIGH_PRIESTSESS)))
//                    {
//                        if (Creature* Kaz = instance->instance->GetCreature(instance->GetData64(DATA_KARAZJIN)))
//                        {
//                            Garjal->m_Events.KillAllEvents(true);
//
//                            Malak->GetMotionMaster()->MovePoint(0, Malak->GetHomePosition().GetPositionX(), Malak->GetHomePosition().GetPositionY(), Malak->GetHomePosition().GetPositionZ());
//                            Marli->GetMotionMaster()->MovePoint(0, Marli->GetHomePosition().GetPositionX(), Marli->GetHomePosition().GetPositionY(), Marli->GetHomePosition().GetPositionZ());
//                            Kaz->GetMotionMaster()->MovePoint(0, Kaz->GetHomePosition().GetPositionX(), Kaz->GetHomePosition().GetPositionY(), Kaz->GetHomePosition().GetPositionZ());
//                            Garjal->GetMotionMaster()->MovePoint(0, Garjal->GetHomePosition().GetPositionX(), Garjal->GetHomePosition().GetPositionY(), Garjal->GetHomePosition().GetPositionZ());
//                            me->GetMotionMaster()->MovePoint(0, me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ());
//
//                            me->Respawn();
//                            me->AI()->Reset();
//
//                            Malak->Respawn();
//                            Marli->Respawn();
//                            Kaz->Respawn();
//                            Garjal->Respawn();
//
//                            Malak->AI()->Reset();
//                            Marli->AI()->Reset();
//                            Kaz->AI()->Reset();
//                            Garjal->AI()->Reset();
//                        }
//                    }
//                }
//            }
//        }
//        void EnterCombat(Unit* attacker)
//        {
//            if (pInstance)
//            {
//                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//                DoZoneInCombat();
//            }
//
//
//            if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64(DATA_GARAJAL)))
//            {
//                if (Creature* Sul = instance->instance->GetCreature(instance->GetData64(DATA_SAND_CRAWLER)))
//                {
//                    if (Creature* Marli = instance->instance->GetCreature(instance->GetData64(DATA_HIGH_PRIESTSESS)))
//                    {
//                        if (Creature* Kaz = instance->instance->GetCreature(instance->GetData64(DATA_KARAZJIN)))
//                        {
//
//                            Sul->Attack(attacker, true);
//                            Kaz->Attack(attacker, false);
//                            me->Attack(attacker, true);
//                            Marli->Attack(attacker, true);
//
//                            Sul->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                            Kaz->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                            me->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                            Marli->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                        }
//                    }
//                }
//            }
//
//            me->SetPower(POWER_ENERGY, 0);
//            me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//
//            Talk(SUL_AGGRO);
//
//            events.ScheduleEvent(EVENT_SAND_BOLT, 8000);
//            events.ScheduleEvent(EVENT_QUICKSAND, 30000);
//        }
//        void JustSummoned(Creature* summon)
//        {
//            summons.Summon(summon);
//        }
//        void SummonedCreatureDespawn(Creature* summon)
//        {
//            summons.Despawn(summon);
//        }
//        void DespawnCreaturesInArea(uint32 entry, WorldObject* object)
//        {
//            std::list<Creature*> creatures;
//            GetCreatureListWithEntryInGrid(creatures, object, entry, 300.0f);
//            if (creatures.empty())
//                return;
//
//            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
//                (*iter)->DespawnOrUnsummon();
//        }
//        void DamageTaken(Unit* /*attacker*/, uint32& damage)
//        {
//            if (hppcts && me->HasAura(SPELL_POSSESSED))
//            {
//                if (me->HealthBelowPctDamaged(hppcts, damage))
//                {
//                    me->RemoveAura(SPELL_POSSESSED);
//                    if (!me->HasAura(SPELL_LINGERING_POWER))
//                    {
//                        me->AddAura(SPELL_LINGERING_POWER, me);
//                    }
//                    else
//                    {
//                        AuraPtr aura = me->GetAura(SPELL_LINGERING_POWER);
//
//                        if (aura)
//                        {
//                            aura->SetStackAmount(aura->GetStackAmount() + 1);
//                        }
//                    }
//
//                    me->RemoveAura(SPELL_SHADOW_FORM);
//
//                    events.CancelEvent(EVENT_SANDSTORM);
//                    events.CancelEvent(EVENT_CAST_DARK_POWER);
//
//                    events.ScheduleEvent(EVENT_QUICKSAND, 30000);
//                    events.ScheduleEvent(EVENT_SAND_BOLT, 8000);
//                    // add aura
//                    if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64((DATA_GARAJAL))))
//                    {
//                        Garjal->GetAI()->DoAction(ACTION_CONTINUE_POSSESSION_CHAIN);
//                    }
//                }
//            }
//        }
//        void DoAction(const int32 action)
//        {
//            if (action == ACTION_POSSESSED_PHASE)
//            {
//                me->AddAura(SPELL_POSSESSED, me);
//                hppcts = me->GetHealthPct() * 0.85;
//
//                damage = 0;
//
//                me->SetPower(POWER_ENERGY, 0);
//                me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//
//                events.ScheduleEvent(EVENT_SANDSTORM, 5000);
//            }
//        }
//        void KilledUnit(Unit* who) override
//        {
//            if (who->GetTypeId() == TYPEID_PLAYER)
//                Talk(SUL_SLAY);
//        }
//        void JustDied(Unit* killer)
//        {
//            Talk(SUL_DEATH);
//
//            // add aura
//            if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64((DATA_GARAJAL))))
//            {
//                Garjal->GetAI()->DoAction(ACTION_CONTINUE_POSSESSION_CHAIN);
//            }
//
//            if (Creature* Malak = instance->instance->GetCreature(instance->GetData64(DATA_MALAK)))
//            {
//                if (Creature* Marli = instance->instance->GetCreature(instance->GetData64(DATA_HIGH_PRIESTSESS)))
//                {
//                    if (Creature* Kaz = instance->instance->GetCreature(instance->GetData64(DATA_KARAZJIN)))
//                    {
//                        if (Malak->isDead() && Marli->isDead() && Kaz->isDead())
//                        {
//                            if (Creature* Garajal = instance->instance->GetCreature(instance->GetData64(DATA_GARAJAL)))
//                            {
//                                if (killer)
//                                    killer->Kill(Garajal);
//
//                                std::list<Player*> pl_list;
//                                pl_list.clear();
//
//                                me->GetPlayerListInGrid(pl_list, 100.0f);
//
//                                if (pl_list.empty())
//                                    return;
//
//                                CurrencyOnKillEntry const* Curr = sObjectMgr->GetCurrencyOnKillEntry(me->ToCreature()->GetEntry());
//                                if (!Curr)
//                                    return;
//
//                                for (auto itr : pl_list)
//                                {
//                                    if (Curr->currencyId1 && Curr->currencyCount1)
//                                    {
//                                        if (CurrencyTypesEntry const* entry = sCurrencyTypesStore.LookupEntry(Curr->currencyId1))
//                                        {
//                                            if (Curr->currencyId1 == CURRENCY_TYPE_JUSTICE_POINTS)
//                                            {
//                                                if ((itr->GetCurrency(Curr->currencyId1, true) + Curr->currencyCount1) > itr->GetCurrencyTotalCap(entry))
//                                                {
//                                                    uint32 max = itr->GetCurrencyTotalCap(entry);
//                                                    uint32 lessPoint = max - itr->GetCurrency(Curr->currencyId1, true);
//                                                    uint32 rest = Curr->currencyCount1 - lessPoint;
//
//                                                    itr->ModifyCurrency(Curr->currencyId1, lessPoint);
//                                                }
//                                                else
//                                                    itr->ModifyCurrency(Curr->currencyId1, Curr->currencyCount1);
//                                            }
//                                            else
//                                                itr->ModifyCurrency(Curr->currencyId1, Curr->currencyCount1);
//                                        }
//                                    }
//                                }
//                            }
//                        }
//                        else
//                        {
//                            me->SetLootRecipient(NULL);
//                        }
//                    }
//                }
//            }
//        }
//        void RegeneratePower(Powers power, int32& value)
//        {
//            if (power != POWER_ENERGY)
//                return;
//
//            if (!me->HasAura(SPELL_POSSESSED))
//                return;
//
//            AuraPtr aura = me->GetAura(SPELL_POSSESSED);
//
//            value = 3;;
//
//            int32 val = me->GetPower(POWER_ENERGY);
//            if (val + value > 100)
//                val = 100;
//            else
//                val += value;
//
//
//            me->SetInt32Value(UNIT_FIELD_POWER1, val);
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (me->GetUInt32Value(UNIT_FIELD_POWER1) == 100 && me->HasAura(SPELL_POSSESSED))
//            {
//                me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//                events.ScheduleEvent(EVENT_CAST_DARK_POWER, 100);
//            }
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            switch (events.ExecuteEvent())
//            {
//            case EVENT_SAND_BOLT:
//            {
//                if (Unit* random = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
//                    me->CastSpell(me, 136190);
//
//                events.ScheduleEvent(EVENT_SAND_BOLT, 8000);
//                break;
//            }
//            case EVENT_QUICKSAND:
//            {
//                Position pos;
//                me->GetRandomNearPosition(pos, 15.0f);
//
//                me->SummonCreature(TRIGGER_QUICKSAND, pos, TEMPSUMMON_MANUAL_DESPAWN);
//
//                events.ScheduleEvent(EVENT_QUICKSAND, 25000);
//                break;
//            }
//            case EVENT_SANDSTORM:
//            {
//                std::list<Creature*> quicksand_triggers;
//                me->GetCreatureListWithEntryInGrid(quicksand_triggers, TRIGGER_QUICKSAND, 200.0f);
//
//                std::list<Creature*> livingsand_creatures;
//                me->GetCreatureListWithEntryInGrid(livingsand_creatures, CREATURE_LIVING_SAND, 200.0f);
//
//                if (!quicksand_triggers.empty())
//                {
//                    for (auto itr : quicksand_triggers)
//                    {
//                        itr->SummonCreature(CREATURE_LIVING_SAND, itr->GetPositionX(), itr->GetPositionY(), itr->GetPositionZ(), itr->GetOrientation(), TEMPSUMMON_DEAD_DESPAWN);
//                        itr->DespawnOrUnsummon();
//                    }
//                }
//                if (!livingsand_creatures.empty()) // add fortified to living sand creatures
//                {
//                    for (auto ite : livingsand_creatures)
//                    {
//                        ite->AddAura(SPELL_FORTIFIED, ite);
//                    }
//                }
//
//                me->CastSpell(me, SPELL_SAND_STORM);
//                events.ScheduleEvent(EVENT_SANDSTORM, 40000);
//                break;
//            }
//            case EVENT_CAST_DARK_POWER:
//            {
//                events.CancelEvent(EVENT_FROST_BITE);
//                events.CancelEvent(EVENT_BITTING_COLD);
//                events.CancelEvent(EVENT_ASSAULT_AURA);
//
//                int32 calc = 10000 + (damage * 10000);
//
//                me->CastCustomSpell(me, SPELL_CAST_DARK_POWER, &calc, NULL, NULL, true, NULL);
//                damage += 0.10;
//
//                events.ScheduleEvent(EVENT_CAST_DARK_POWER, 1000);
//                break;
//            }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new boss_sulAI(creature);
//    }
//};
//class boss_high_priestess_marli : public CreatureScript
//{
//public:
//    boss_high_priestess_marli() : CreatureScript("boss_high_priestess_marli") { }
//
//    struct boss_high_priestess_marliAI : public BossAI
//    {
//        boss_high_priestess_marliAI(Creature* creature) : BossAI(creature, DATA_HIGH_PRIESTSESS)
//        {
//            pInstance = creature->GetInstanceScript();
//        }
//
//        InstanceScript* pInstance;
//        EventMap events;
//
//        bool intro;
//        int32 hppcts;
//        bool explode;
//		uint32 damage;
//
//        void Reset()
//        {
//            _Reset();
//            events.Reset();
//            summons.DespawnAll();
//
//            me->SetMaxHealth(89000000);
//            me->SetHealth(89000000);
//
//            explode = true;
//
//            me->RemoveAllAuras();
//
//            hppcts = me->GetHealthPct() * 0.85;
//
//            me->SetHealth(me->GetMaxHealth());
//            me->SetPower(POWER_ENERGY, 0);
//            me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//            me->SetMaxPower(POWER_ENERGY, 100);
//            me->SetInt32Value(UNIT_FIELD_MAXPOWER1, 100);
//            me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
//        }
//        void JustReachedHome()
//        {
//            _JustReachedHome();
//
//            summons.DespawnAll();
//
//            if (pInstance)
//                pInstance->SetBossState(DATA_HIGH_PRIESTSESS, FAIL);
//
//            if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64(DATA_GARAJAL)))
//            {
//                if (Creature* Malak = instance->instance->GetCreature(instance->GetData64(DATA_MALAK)))
//                {
//                    if (Creature* Sul = instance->instance->GetCreature(instance->GetData64(DATA_SAND_CRAWLER)))
//                    {
//                        if (Creature* Kaz = instance->instance->GetCreature(instance->GetData64(DATA_KARAZJIN)))
//                        {
//                            Garjal->m_Events.KillAllEvents(true);
//
//                            Malak->GetMotionMaster()->MovePoint(0, Malak->GetHomePosition().GetPositionX(), Malak->GetHomePosition().GetPositionY(), Malak->GetHomePosition().GetPositionZ());
//                            Sul->GetMotionMaster()->MovePoint(0, Sul->GetHomePosition().GetPositionX(), Sul->GetHomePosition().GetPositionY(), Sul->GetHomePosition().GetPositionZ());
//                            Kaz->GetMotionMaster()->MovePoint(0, Kaz->GetHomePosition().GetPositionX(), Kaz->GetHomePosition().GetPositionY(), Kaz->GetHomePosition().GetPositionZ());
//                            Garjal->GetMotionMaster()->MovePoint(0, Garjal->GetHomePosition().GetPositionX(), Garjal->GetHomePosition().GetPositionY(), Garjal->GetHomePosition().GetPositionZ());
//                            me->GetMotionMaster()->MovePoint(0, me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ());
//
//                            me->Respawn();
//                            me->AI()->Reset();
//
//                            Malak->Respawn();
//                            Sul->Respawn();
//                            Kaz->Respawn();
//                            Garjal->Respawn();
//
//                            Malak->AI()->Reset();
//                            Sul->AI()->Reset();
//                            Kaz->AI()->Reset();
//                            Garjal->AI()->Reset();
//                        }
//                    }
//                }
//            }
//        }
//        void EnterCombat(Unit* attacker)
//        {
//            if (pInstance)
//            {
//                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//                DoZoneInCombat();
//            }
//
//            if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64(DATA_GARAJAL)))
//            {
//                if (Creature* Sul = instance->instance->GetCreature(instance->GetData64(DATA_SAND_CRAWLER)))
//                {
//                    if (Creature* Malak = instance->instance->GetCreature(instance->GetData64(DATA_MALAK)))
//                    {
//                        if (Creature* Kaz = instance->instance->GetCreature(instance->GetData64(DATA_KARAZJIN)))
//                        {
//
//                            Sul->Attack(attacker, true);
//                            Kaz->Attack(attacker, false);
//                            me->Attack(attacker, true);
//                            Malak->Attack(attacker, true);
//
//                            Sul->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                            Kaz->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                            me->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                            Malak->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                        }
//                    }
//                }
//            }
//
//            me->SetPower(POWER_ENERGY, 0);
//            me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//
//            Talk(MARLI_AGGRO);
//
//            events.ScheduleEvent(EVENT_BLESSING_LOA_SPIRIT, blessingloaspiritinterval);
//            events.ScheduleEvent(EVENT_WRATH_OF_THE_LOA_LIGHT, wrathoftheloainterval);
//        }
//        void JustSummoned(Creature* summon)
//        {
//            summons.Summon(summon);
//        }
//        void SummonedCreatureDespawn(Creature* summon)
//        {
//            summons.Despawn(summon);
//        }
//        void DespawnCreaturesInArea(uint32 entry, WorldObject* object)
//        {
//            std::list<Creature*> creatures;
//            GetCreatureListWithEntryInGrid(creatures, object, entry, 300.0f);
//            if (creatures.empty())
//                return;
//
//            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
//                (*iter)->DespawnOrUnsummon();
//        }
//        void DamageTaken(Unit* /*attacker*/, uint32& damage)
//        {
//            if (hppcts && me->HasAura(SPELL_POSSESSED))
//            {
//                if (me->HealthBelowPctDamaged(hppcts, damage))
//                {
//                    me->RemoveAura(SPELL_POSSESSED);
//
//                    if (!me->HasAura(SPELL_LINGERING_POWER))
//                    {
//                        me->AddAura(SPELL_LINGERING_POWER, me);
//                    }
//                    else
//                    {
//                        AuraPtr aura = me->GetAura(SPELL_LINGERING_POWER);
//
//                        if (aura)
//                        {
//                            aura->SetStackAmount(aura->GetStackAmount() + 1);
//                        }
//                    }
//
//                    me->RemoveAura(SPELL_SHADOW_FORM);
//                    events.CancelEvent(EVENT_CAST_DARK_POWER);
//                    events.CancelEvent(EVENT_SHADOW_LOA_SPIRIT);
//                    events.CancelEvent(EVENT_WRATH_OF_THE_LOA);
//                    events.ScheduleEvent(EVENT_BLESSING_LOA_SPIRIT, blessingloaspiritinterval);
//                    events.ScheduleEvent(EVENT_WRATH_OF_THE_LOA_LIGHT, wrathoftheloainterval);
//
//                    // add aura
//                    if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64((DATA_GARAJAL))))
//                    {
//                        Garjal->GetAI()->DoAction(ACTION_CONTINUE_POSSESSION_CHAIN);
//                    }
//                }
//            }
//        }
//        void DoAction(const int32 action)
//        {
//            if (action == ACTION_POSSESSED_PHASE)
//            {
//                me->AddAura(SPELL_POSSESSED, me);
//                hppcts = me->GetHealthPct() * 0.85;
//
//                // Shadow visual
//                me->AddAura(SPELL_SHADOW_FORM, me);
//
//                damage = 0;
//
//                me->SetPower(POWER_ENERGY, 0);
//                me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//
//                events.CancelEvent(EVENT_WRATH_OF_THE_LOA_LIGHT);
//                events.CancelEvent(EVENT_BLESSING_LOA_SPIRIT);
//                events.ScheduleEvent(EVENT_SHADOW_LOA_SPIRIT, shadowloaspiritinterval);
//                events.ScheduleEvent(EVENT_WRATH_OF_THE_LOA, wrathoftheloainterval);
//            }
//        }
//        void KilledUnit(Unit* who) override
//        {
//            if (who->GetTypeId() == TYPEID_PLAYER)
//                Talk(MARLI_SAY);
//        }
//        void JustDied(Unit* killer)
//        {
//            Talk(MARLI_DEATH);
//
//
//            if (Creature* Sul = instance->instance->GetCreature(instance->GetData64(DATA_SAND_CRAWLER)))
//            {
//                if (Creature* Kaz = instance->instance->GetCreature(instance->GetData64(DATA_KARAZJIN)))
//                {
//                    if (Creature* Malak = instance->instance->GetCreature(instance->GetData64(DATA_MALAK)))
//                    {
//                        if (Sul->isDead() && Kaz->isDead() && Malak->isDead())
//                        {
//                            if (Creature* Garajal = instance->instance->GetCreature(instance->GetData64(DATA_GARAJAL)))
//                            {
//                                if (killer)
//                                    killer->Kill(Garajal);
//
//                                std::list<Player*> pl_list;
//                                pl_list.clear();
//
//                                me->GetPlayerListInGrid(pl_list, 100.0f);
//
//                                if (pl_list.empty())
//                                    return;
//
//                                CurrencyOnKillEntry const* Curr = sObjectMgr->GetCurrencyOnKillEntry(me->ToCreature()->GetEntry());
//                                if (!Curr)
//                                    return;
//
//                                for (auto itr : pl_list)
//                                {
//                                    if (Curr->currencyId1 && Curr->currencyCount1)
//                                    {
//                                        if (CurrencyTypesEntry const* entry = sCurrencyTypesStore.LookupEntry(Curr->currencyId1))
//                                        {
//                                            if (Curr->currencyId1 == CURRENCY_TYPE_JUSTICE_POINTS)
//                                            {
//                                                if ((itr->GetCurrency(Curr->currencyId1, true) + Curr->currencyCount1) > itr->GetCurrencyTotalCap(entry))
//                                                {
//                                                    uint32 max = itr->GetCurrencyTotalCap(entry);
//                                                    uint32 lessPoint = max - itr->GetCurrency(Curr->currencyId1, true);
//                                                    uint32 rest = Curr->currencyCount1 - lessPoint;
//
//                                                    itr->ModifyCurrency(Curr->currencyId1, lessPoint);
//                                                }
//                                                else
//                                                    itr->ModifyCurrency(Curr->currencyId1, Curr->currencyCount1);
//                                            }
//                                            else
//                                                itr->ModifyCurrency(Curr->currencyId1, Curr->currencyCount1);
//                                        }
//                                    }
//                                }
//                            }
//                        }
//                        else
//                        {
//                            me->SetLootRecipient(NULL);
//                        }
//                    }
//                }
//            }
//
//            // add aura
//            if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64((DATA_GARAJAL))))
//            {
//                Garjal->GetAI()->DoAction(ACTION_CONTINUE_POSSESSION_CHAIN);
//            }
//        }
//        void RegeneratePower(Powers power, int32& value)
//        {
//            if (power != POWER_ENERGY)
//                return;
//
//            if (!me->HasAura(SPELL_POSSESSED))
//                return;
//
//            AuraPtr aura = me->GetAura(SPELL_POSSESSED);
//
//            value = 3;;
//
//            int32 val = me->GetPower(POWER_ENERGY);
//            if (val + value > 100)
//                val = 100;
//            else
//                val += value;
//
//            me->SetInt32Value(UNIT_FIELD_POWER1, val);
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (me->GetUInt32Value(UNIT_FIELD_POWER1) == 100 && me->HasAura(SPELL_POSSESSED))
//            {
//                me->SetInt32Value(UNIT_FIELD_POWER1, 0);              
//                events.ScheduleEvent(EVENT_CAST_DARK_POWER, 100);
//            }
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            switch (events.ExecuteEvent())
//            {
//            case EVENT_BLESSING_LOA_SPIRIT:
//            {
//                me->CastSpell(me, SPELL_BLESSING_OF_THE_LOA_SUMMON);
//                events.ScheduleEvent(EVENT_BLESSING_LOA_SPIRIT, blessingloaspiritinterval);
//                break;
//            }
//            case EVENT_WRATH_OF_THE_LOA_LIGHT: // light
//            {
//                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0F, true))
//                    me->CastSpell(target, SPELL_WRATH_OF_THE_LOA);
//
//                events.ScheduleEvent(EVENT_WRATH_OF_THE_LOA_LIGHT, wrathoftheloainterval);
//                break;
//            }
//            // ABILITIES WHEN GETTING MAD
//            case EVENT_WRATH_OF_THE_LOA: // shadow
//            {
//                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0F, true))
//                    me->CastSpell(target, SPELL_WRATH_OF_THE_LOA_SHADOW);
//
//                events.ScheduleEvent(EVENT_WRATH_OF_THE_LOA, wrathoftheloainterval);
//                break;
//            }
//            case EVENT_SHADOW_LOA_SPIRIT:
//            {
//                me->CastSpell(me, SPELL_SHADOW_LOA_SPIRIT_SUMMON);
//                events.ScheduleEvent(EVENT_SHADOW_LOA_SPIRIT, shadowloaspiritinterval);
//                break;
//            }
//            case EVENT_CAST_DARK_POWER:
//            {
//                events.CancelEvent(EVENT_BLESSING_LOA_SPIRIT);
//                events.CancelEvent(EVENT_WRATH_OF_THE_LOA_LIGHT);
//                events.CancelEvent(EVENT_WRATH_OF_THE_LOA);
//                events.CancelEvent(EVENT_SHADOW_LOA_SPIRIT);
//
//                int32 calc = 10000 + (damage * 10000);
//
//                me->CastCustomSpell(me, SPELL_CAST_DARK_POWER, &calc, NULL, NULL, true, NULL);
//                damage += 0.10;
//
//                events.ScheduleEvent(EVENT_CAST_DARK_POWER, 10000);
//                break;
//            }
//            }
//            DoMeleeAttackIfReady(); // possibly wrath of loa yo
//        }
//    };
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new boss_high_priestess_marliAI(creature);
//    }
//};
//class boss_kazarjin : public CreatureScript
//{
//public:
//    boss_kazarjin() : CreatureScript("boss_kazarjin") { }
//
//    struct boss_kazarjinAI : public BossAI
//    {
//        boss_kazarjinAI(Creature* creature) : BossAI(creature, DATA_KARAZJIN)
//        {
//            pInstance = creature->GetInstanceScript();
//        }
//
//        InstanceScript* pInstance;
//        EventMap events;
//
//        bool intro;
//        bool explode;
//        uint32 damage;
//        uint32 timepertick;
//        int32 hppcts;
//        Unit* target = NULL;
//
//        void Reset()
//        {
//            _Reset();
//            events.Reset();
//            summons.DespawnAll();
//
//            target = NULL;
//            explode = true;
//
//            me->SetMaxHealth(89000000);
//            me->SetHealth(89000000);
//
//            hppcts = me->GetHealthPct() * 0.15;
//
//            me->SetReactState(REACT_PASSIVE);
//            me->RemoveAllAuras();
//
//            me->SetHealth(me->GetMaxHealth());
//            me->SetPower(POWER_ENERGY, 0);
//            me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//            me->SetMaxPower(POWER_ENERGY, 100);
//            me->SetInt32Value(UNIT_FIELD_MAXPOWER1, 100);
//            me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
//        }
//        void JustReachedHome()
//        {
//            _JustReachedHome();
//            summons.DespawnAll();
//
//            if (pInstance)
//                pInstance->SetBossState(DATA_KARAZJIN, FAIL);
//
//            if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64(DATA_GARAJAL)))
//            {
//                if (Creature* Malak = instance->instance->GetCreature(instance->GetData64(DATA_MALAK)))
//                {
//                    if (Creature* Sul = instance->instance->GetCreature(instance->GetData64(DATA_SAND_CRAWLER)))
//                    {
//                        if (Creature* Marli = instance->instance->GetCreature(instance->GetData64(DATA_HIGH_PRIESTSESS)))
//                        {
//                            Garjal->m_Events.KillAllEvents(true);
//
//                            Malak->GetMotionMaster()->MovePoint(0, Malak->GetHomePosition().GetPositionX(), Malak->GetHomePosition().GetPositionY(), Malak->GetHomePosition().GetPositionZ());
//                            Sul->GetMotionMaster()->MovePoint(0, Sul->GetHomePosition().GetPositionX(), Sul->GetHomePosition().GetPositionY(), Sul->GetHomePosition().GetPositionZ());
//                            Marli->GetMotionMaster()->MovePoint(0, Marli->GetHomePosition().GetPositionX(), Marli->GetHomePosition().GetPositionY(), Marli->GetHomePosition().GetPositionZ());
//                            Garjal->GetMotionMaster()->MovePoint(0, Garjal->GetHomePosition().GetPositionX(), Garjal->GetHomePosition().GetPositionY(), Garjal->GetHomePosition().GetPositionZ());
//                            me->GetMotionMaster()->MovePoint(0, me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ());
//
//                            me->Respawn();
//                            me->AI()->Reset();
//
//                            Malak->Respawn();
//                            Sul->Respawn();
//                            Marli->Respawn();
//                            Garjal->Respawn();
//
//                            Malak->AI()->Reset();
//                            Sul->AI()->Reset();
//                            Marli->AI()->Reset();
//                            Garjal->AI()->Reset();
//                        }
//                    }
//                }
//            }
//        }
//        void EnterCombat(Unit* attacker)
//        {
//            if (pInstance)
//            {
//                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//                DoZoneInCombat();
//            }
//
//            timepertick = 300; 
//
//            
//            if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64(DATA_GARAJAL)))
//            {
//                if (Creature* Sul = instance->instance->GetCreature(instance->GetData64(DATA_SAND_CRAWLER)))
//                {
//                    if (Creature* Malak = instance->instance->GetCreature(instance->GetData64(DATA_MALAK)))
//                    {
//                        if (Creature* mARLI = instance->instance->GetCreature(instance->GetData64(DATA_HIGH_PRIESTSESS)))
//                        {
//
//                            Sul->Attack(attacker, true);
//                            mARLI->Attack(attacker, false);
//                            me->Attack(attacker, true);
//                            Malak->Attack(attacker, true);
//
//                            Sul->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                            mARLI->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                            me->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                            Malak->GetMotionMaster()->MovePoint(0, attacker->GetPositionX(), attacker->GetPositionY(), attacker->GetPositionZ());
//                        }
//                    }
//                }
//            }
//          
//
//            me->SetPower(POWER_ENERGY, 0);
//            me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//            Talk(KAZARJIN_AGGRO);
//
//            events.ScheduleEvent(EVENT_RECKLESS_CHARGE, 8000);
//        }
//        void JustSummoned(Creature* summon)
//        {
//            summons.Summon(summon);
//        }
//        void SummonedCreatureDespawn(Creature* summon)
//        {
//            summons.Despawn(summon);
//        }
//        void DespawnCreaturesInArea(uint32 entry, WorldObject* object)
//        {
//            std::list<Creature*> creatures;
//            GetCreatureListWithEntryInGrid(creatures, object, entry, 300.0f);
//            if (creatures.empty())
//                return;
//
//            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
//                (*iter)->DespawnOrUnsummon();
//        }
//        void DamageTaken(Unit* attacker, uint32& damage)
//        {
//            if (hppcts && me->HasAura(SPELL_POSSESSED))
//            {
//                if (me->HealthBelowPctDamaged(hppcts, damage))
//                {
//                    me->RemoveAura(SPELL_POSSESSED);
//                    me->RemoveAura(SPELL_SHADOW_FORM);
//
//                    if (!me->HasAura(SPELL_LINGERING_POWER))
//                    {
//                        me->AddAura(SPELL_LINGERING_POWER, me);
//                    }
//                    else
//                    {
//                        AuraPtr aura = me->GetAura(SPELL_LINGERING_POWER);
//
//                        if (aura)
//                        {
//                            aura->SetStackAmount(aura->GetStackAmount() + 1);
//                        }
//                    }
//
//                    events.CancelEvent(EVENT_CAST_DARK_POWER);
//                    events.ScheduleEvent(EVENT_RECKLESS_CHARGE, 10000);
//
//                    // add aura
//                    if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64((DATA_GARAJAL))))
//                    {
//                        Garjal->GetAI()->DoAction(ACTION_CONTINUE_POSSESSION_CHAIN);
//                    }
//                }
//            }
//
//            if (me->HasAura(SPELL_OVERLOAD))
//            {
//                if (attacker->GetTypeId() == TYPEID_PLAYER)
//                {
//                    if (damage && damage > 0)
//                    {
//                        attacker->ToPlayer()->EnvironmentalDamage(DAMAGE_FIRE, damage * 0.40);
//                    }
//                }
//            }
//        }
//        void DoAction(const int32 action)
//        {
//            if (action == ACTION_POSSESSED_PHASE)
//            {
//                me->AddAura(SPELL_POSSESSED, me);
//                hppcts = me->GetHealthPct() * 0.85;
//
//                damage = 0;
//
//                me->SetPower(POWER_ENERGY, 0);
//                me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//
//                // Shadow visual
//                me->AddAura(SPELL_SHADOW_FORM, me);
//            }
//        }
//        void KilledUnit(Unit* who) override
//        {
//            if (who->GetTypeId() == TYPEID_PLAYER)
//                Talk(KAZARJIN_SLAY);
//        }
//        void JustDied(Unit* killer)
//        {
//            Talk(KAZARJIN_DEATH);
//
//            if (Creature* Sul = instance->instance->GetCreature(instance->GetData64(DATA_SAND_CRAWLER)))
//            {
//                if (Creature* Marli = instance->instance->GetCreature(instance->GetData64(DATA_HIGH_PRIESTSESS)))
//                {
//                    if (Creature* Malak = instance->instance->GetCreature(instance->GetData64(DATA_MALAK)))
//                    {
//                        if (Sul->isDead() && Marli->isDead() && Malak->isDead())
//                        {
//                            if (Creature* Garajal = instance->instance->GetCreature(instance->GetData64(DATA_GARAJAL)))
//                            {
//                                if (killer)
//                                    killer->Kill(Garajal);
//
//                                std::list<Player*> pl_list;
//                                pl_list.clear();
//
//                                me->GetPlayerListInGrid(pl_list, 100.0f);
//
//                                if (pl_list.empty())
//                                    return;
//
//                                CurrencyOnKillEntry const* Curr = sObjectMgr->GetCurrencyOnKillEntry(me->ToCreature()->GetEntry());
//                                if (!Curr)
//                                    return;
//
//                                for (auto itr : pl_list)
//                                {
//                                    if (Curr->currencyId1 && Curr->currencyCount1)
//                                    {
//                                        if (CurrencyTypesEntry const* entry = sCurrencyTypesStore.LookupEntry(Curr->currencyId1))
//                                        {
//                                            if (Curr->currencyId1 == CURRENCY_TYPE_JUSTICE_POINTS)
//                                            {
//                                                if ((itr->GetCurrency(Curr->currencyId1, true) + Curr->currencyCount1) > itr->GetCurrencyTotalCap(entry))
//                                                {
//                                                    uint32 max = itr->GetCurrencyTotalCap(entry);
//                                                    uint32 lessPoint = max - itr->GetCurrency(Curr->currencyId1, true);
//                                                    uint32 rest = Curr->currencyCount1 - lessPoint;
//
//                                                    itr->ModifyCurrency(Curr->currencyId1, lessPoint);
//                                                }
//                                                else
//                                                    itr->ModifyCurrency(Curr->currencyId1, Curr->currencyCount1);
//                                            }
//                                            else
//                                                itr->ModifyCurrency(Curr->currencyId1, Curr->currencyCount1);
//                                        }
//                                    }
//                                }
//                            }
//                        }
//                        else
//                        {
//                            me->SetLootRecipient(NULL);
//                        }
//                    }
//                }
//            }
//
//            // add aura
//            if (Creature* Garjal = instance->instance->GetCreature(instance->GetData64((DATA_GARAJAL))))
//            {
//                Garjal->GetAI()->DoAction(ACTION_CONTINUE_POSSESSION_CHAIN);
//            }
//        }
//        void RegeneratePower(Powers power, int32& value)
//        {
//            if (power != POWER_ENERGY)
//                return;
//
//            if (!me->HasAura(SPELL_POSSESSED))
//                return;
//
//            AuraPtr aura = me->GetAura(SPELL_POSSESSED);
//
//            value = 3;;
//
//            int32 val = me->GetPower(POWER_ENERGY);
//            if (val + value > 100)
//                val = 100;
//            else
//                val += value;
//
//
//            me->SetInt32Value(UNIT_FIELD_POWER1, val);
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (me->GetUInt32Value(UNIT_FIELD_POWER1) == 100 && me->HasAura(SPELL_POSSESSED))
//            {
//                me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//                events.ScheduleEvent(EVENT_CAST_DARK_POWER, 100);
//            }
//            if (me->HasAura(137117))
//            {
//                if (timepertick <= diff)
//                {
//                    std::list<Player*> pl_list;
//
//                    pl_list.clear();
//                    me->GetPlayerListInGrid(pl_list, 2.0f);
//
//                    for (auto itr : pl_list)
//                    {
//                        me->CastSpell(itr, SPELL_RECKLESS_CHARGE_UNKNOWN_DAMAGE);
//                    }
//
//                    timepertick = 560;
//                }
//                else
//                    timepertick -= diff;
//            }
//
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//
//            if (me->GetUInt32Value(UNIT_FIELD_POWER1) == 100)
//            {
//                me->SetInt32Value(UNIT_FIELD_POWER1, 0);
//                events.ScheduleEvent(EVENT_CAST_DARK_POWER, 1000);
//            }
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            switch (events.ExecuteEvent())
//            {
//            case EVENT_RECKLESS_CHARGE:
//                me->AddAura(SPELL_RECKLESS_CHARGE_DUMMY, me);
//
//                if (me->HasAura(SPELL_RECKLESS_CHARGE_DUMMY))
//                {
//                    AuraPtr aura = me->GetAura(SPELL_RECKLESS_CHARGE_DUMMY);
//                    aura->SetDuration(10000);
//                }
//
//                explode = false;
//                events.ScheduleEvent(EVENT_RECKLESS_CHARGE_MOVEMENT, 1000);
//                events.ScheduleEvent(EVENT_OVERLOAD, 6000);
//                break;
//            case EVENT_OVERLOAD:
//                me->RemoveAura(SPELL_RECKLESS_CHARGE_DUMMY);
//                me->CastSpell(me, SPELL_RECKLESS_CHARGE_AOE_VISUAL);
//
//                me->CastSpell(me, SPELL_OVERLOAD);
//                me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
//                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
//                me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
//
//                events.ScheduleEvent(CANCEL_OVERLOAD, 20000);
//                break;
//            case EVENT_RECKLESS_CHARGE_MOVEMENT:
//                me->SetSpeed(MOVE_RUN, 3.0f, true);
//                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true);
//
//                if (target)
//                    me->GetMotionMaster()->MovePoint(0, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
//                break;
//            case CANCEL_OVERLOAD:
//                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
//                me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
//                me->RemoveUnitMovementFlag(MOVEMENTFLAG_ROOT);
//                events.ScheduleEvent(EVENT_RECKLESS_CHARGE, 4000);
//                break;
//            case EVENT_CAST_DARK_POWER:
//            {
//                events.CancelEvent(EVENT_FROST_BITE);
//                events.CancelEvent(EVENT_BITTING_COLD);
//                events.CancelEvent(EVENT_ASSAULT_AURA);
//
//                int32 calc = 10000 + (damage * 10000);
//                me->CastCustomSpell(me, SPELL_CAST_DARK_POWER, &calc, NULL, NULL, true, NULL);
//                damage += 0.10;
//
//                events.ScheduleEvent(EVENT_CAST_DARK_POWER, 1000);
//                break;
//            }
//            }
//            DoMeleeAttackIfReady(); // possibly wrath of loa yo
//        }
//    };
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new boss_kazarjinAI(creature);
//    }
//};
//class creature_living_sand : public CreatureScript
//{
//public:
//    creature_living_sand() : CreatureScript("creature_living_sand") { }
//
//    struct creature_living_sandAI : public ScriptedAI
//    {
//        creature_living_sandAI(Creature* creature) : ScriptedAI(creature)
//        {
//            pInstance = creature->GetInstanceScript();
//        }
//
//        InstanceScript* pInstance;
//        EventMap events;
//
//        void Reset()
//        {
//            events.Reset();
//
//            me->SetMaxHealth(1000000);
//            me->SetHealth(1000000);
//        }
//        void JustDied(Unit* /*killer*/)
//        {
//            me->DespawnOrUnsummon(1000);
//            me->SummonCreature(TRIGGER_QUICKSAND, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
//        }
//    };
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new creature_living_sandAI(creature);
//    }
//};
//class creature_loa_spirit_light : public CreatureScript
//{
//public:
//    creature_loa_spirit_light() : CreatureScript("creature_loa_spirit_light") { }
//
//    struct mob_council : public ScriptedAI
//    {
//        mob_council(Creature* creature) : ScriptedAI(creature)
//        {
//            instance = creature->GetInstanceScript();
//        }
//
//        InstanceScript* instance;
//        EventMap events;
//        uint32 jumpTime;
//        Creature* target = NULL;
//        std::list<Creature*> councilBosses;
//        bool contact;
//
//        void Reset()
//        {
//            events.Reset();
//            jumpTime = 20 * IN_MILLISECONDS;
//            contact = false;
//            me->SetReactState(REACT_PASSIVE);
//            me->SetSpeed(MOVE_RUN, 0.3f, true);
//            me->SetMaxHealth(1390000);
//            me->SetHealth(1390000);
//
//            if (Creature* Malak = instance->instance->GetCreature(instance->GetData64(DATA_MALAK)))
//            {
//                if (Creature* Sul = instance->instance->GetCreature(instance->GetData64(DATA_SAND_CRAWLER)))
//                {
//                    if (Creature* Marli = instance->instance->GetCreature(instance->GetData64(DATA_HIGH_PRIESTSESS)))
//                    {
//                        if (Creature* Kaz = instance->instance->GetCreature(instance->GetData64(DATA_KARAZJIN)))
//                        {
//                            if (Malak->isAlive())
//                                councilBosses.push_back(Malak);
//                            if (Sul->isAlive())
//                                councilBosses.push_back(Sul);
//                            if (Marli->isAlive())
//                                councilBosses.push_back(Marli);
//                            if (Kaz->isAlive())
//                                councilBosses.push_back(Kaz);
//                        }
//                    }
//                }
//            }
//            if (councilBosses.empty())
//                return;
//
//            if (councilBosses.size() > 1)
//            {
//                councilBosses.sort(JadeCore::HealthPctOrderPred());
//                councilBosses.resize(1);
//            }
//            for (auto itr : councilBosses)
//            {
//                target = itr;
//            }
//        }
//        void FollowBoss(Creature* target)
//        {
//            me->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f, MOTION_SLOT_ACTIVE);
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (target == NULL || target && target->GetEntry() == 69132)
//                return;
//
//            if (jumpTime <= diff && !contact)
//            {
//                contact = true;
//
//                me->GetMotionMaster()->MoveJump(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 20.0f, 20.0f, 10.0f);
//                target->SetHealth((target->GetHealth() * 0.10) + target->GetHealth());
//                target->HealBySpell(target, sSpellMgr->GetSpellInfo(20473), (target->GetHealth() * 0.20), true); // maybe?
//                me->DespawnOrUnsummon(500);
//            }
//            else
//                jumpTime -= diff;
//
//            if (!me->isMoving())
//                FollowBoss(target);
//
//            if (me->IsWithinDistInMap(target, 1.0f, true))
//                jumpTime = 0;
//        }
//    };
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new mob_council(creature);
//    }
//};
//class creature_loa_spirit_shadow : public CreatureScript
//{
//public:
//    creature_loa_spirit_shadow() : CreatureScript("creature_loa_spirit_shadow") { }
//
//    struct mob_council : public ScriptedAI
//    {
//        mob_council(Creature* creature) : ScriptedAI(creature)
//        {
//            pInstance = creature->GetInstanceScript();
//        }
//
//        InstanceScript* pInstance;
//        EventMap events;
//        uint32 jumpTime;
//        Player* target = NULL;
//
//        void Reset()
//        {
//            events.Reset();
//            me->AddAura(SPELL_SHADOW_FORM, me);
//            me->SetReactState(REACT_PASSIVE);
//
//            me->SetMaxHealth(1850000);
//            me->SetHealth(1850000);
//
//            if (Player* nearest = me->FindNearestPlayer(100.0f, true))
//            {
//                target = nearest;
//                me->CastSpell(nearest, 137359); // visual
//            }
//
//            jumpTime = 20 * IN_MILLISECONDS;
//        }
//        void FollowPlayer(Unit* target)
//        {
//            me->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f, MOTION_SLOT_ACTIVE);
//        }
//        void JustDied(Unit* /*killer*/)
//        {
//            if (target && target->IsInWorld())
//            {
//                if (target->HasAura(137359))
//                {
//                    target->RemoveAura(137359); // visual
//                }
//            }
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (target == NULL)
//                return;
//
//            if (jumpTime <= diff)
//            {
//                me->GetMotionMaster()->MoveJump(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 20.0f, 20.0f, 10.0f);
//                me->Kill(target, true);
//                me->DespawnOrUnsummon(500);
//            }
//            else
//                jumpTime -= diff;
//
//            if (!me->isMoving() && target != NULL)
//                FollowPlayer(target);
//
//            if (me->IsWithinDistInMap(target, 1.0f))
//                jumpTime = 0;
//        }
//    };
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new mob_council(creature);
//    }
//};
//class creature_quick_sand : public CreatureScript
//{
//public:
//    creature_quick_sand() : CreatureScript("creature_quick_sand") { }
//
//    struct mob_council : public ScriptedAI
//    {
//        mob_council(Creature* creature) : ScriptedAI(creature)
//        {
//        }
//
//        InstanceScript* pInstance;
//        EventMap events;
//        uint32 ticktime;
//        uint32 slowticktime;
//
//        void Reset()
//        {
//            events.Reset();
//            me->AddAura(SPELL_QUICKSAND_VISUAL, me);
//
//            ticktime = 2000;
//            slowticktime = 5000;
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (ticktime <= diff)
//            {
//                std::list<Player*> pl_list;
//                me->GetPlayerListInGrid(pl_list, 4.0f);
//
//                if (pl_list.empty())
//                    return;
//
//                for (auto itr : pl_list)
//                {
//                    itr->CastSpell(itr, SPELL_QUICKSAND_DOT);
//
//                    if (AuraPtr _aura = itr->GetAura(SPELL_QUICKSAND_DOT))
//                    {
//                        _aura->SetDuration(1);
//                    }
//                }
//
//                ticktime = 2000;
//            }
//            else
//                ticktime -= diff;
//
//            if (slowticktime <= diff)
//            {
//                std::list<Player*> pl_list;
//
//                me->GetPlayerListInGrid(pl_list, 3.0f);
//                if (pl_list.empty())
//                    return;
//
//                for (auto itr : pl_list)
//                {
//                    if (!itr->HasAura(SPELL_ENTRAPPED))
//                        itr->AddAura(SPELL_ENTRAPPED, itr);
//                    /*
//                    if (!itr->HasAura(SPELL_ENSNARED))
//                    {
//                    itr->AddAura(SPELL_ENSNARED, itr);
//                    }
//                    else
//                    {
//                    AuraPtr aura = me->GetAura(SPELL_ENSNARED);
//
//                    if (aura)
//                    {
//                    if (aura->GetStackAmount() < 5)
//                    {
//                    aura->SetStackAmount(aura->GetStackAmount() + 1);
//                    }
//                    else
//                    {
//                    aura->Remove();
//
//                    }
//                    }
//                    }
//                    */
//                }
//
//                slowticktime = 8000;
//            }
//            else
//                slowticktime -= diff;
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new mob_council(creature);
//    }
//};
//class spell_friggid_stack_dummy : public SpellScriptLoader
//{
//public:
//    spell_friggid_stack_dummy() : SpellScriptLoader("spell_friggid_stack_dummy") { }
//
//    class spell_friggid_stack_dummy_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_friggid_stack_dummy_SpellScript);
//
//        void OnHitTarget()
//        {
//            if (GetCaster() || GetHitUnit())
//            {
//                if (!GetHitUnit()->HasAura(FRIGID_ASSAULT_STACK))
//                {
//                    GetHitUnit()->AddAura(FRIGID_ASSAULT_STACK, GetHitUnit());
//                }
//                else
//                {
//                    AuraPtr AURA = GetHitUnit()->GetAura(FRIGID_ASSAULT_STACK);
//
//                    if (AURA->GetStackAmount() > 14)
//                    {
//                        AURA->Remove();
//                        GetHitUnit()->AddAura(FRIGID_ASSAULT_STUN, GetHitUnit());
//                    }
//                }
//            }
//        }
//
//        void Register()
//        {
//            OnHit += SpellHitFn(spell_friggid_stack_dummy_SpellScript::OnHitTarget);
//        }
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_friggid_stack_dummy_SpellScript();
//    }
//};
//class spell_bitting_cold_dummy : public SpellScriptLoader
//{
//public:
//    spell_bitting_cold_dummy() : SpellScriptLoader("spell_bitting_cold_dummy") { }
//
//    class spell_bitting_cold_dummy_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_bitting_cold_dummy_SpellScript);
//
//        void OnHitTarget()
//        {
//            if (GetCaster() || GetHitUnit())
//            {
//                GetCaster()->CastSpell(GetHitUnit(), BITING_COLD_WORKING_AURA);
//            }
//        }
//
//        void Register()
//        {
//            OnHit += SpellHitFn(spell_bitting_cold_dummy_SpellScript::OnHitTarget);
//        }
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_bitting_cold_dummy_SpellScript();
//    }
//};
//class spell_frost_bite_dummy : public SpellScriptLoader
//{
//public:
//    spell_frost_bite_dummy() : SpellScriptLoader("spell_frost_bite_dummy") { }
//
//    class spell_frost_bite_dummy_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_frost_bite_dummy_SpellScript);
//
//        void OnHitTarget()
//        {
//            if (GetCaster() || GetHitUnit())
//            {
//                GetCaster()->CastSpell(GetHitUnit(), FROST_BITE_BEACON);
//            }
//        }
//
//        void Register()
//        {
//            OnHit += SpellHitFn(spell_frost_bite_dummy_SpellScript::OnHitTarget);
//        }
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_frost_bite_dummy_SpellScript();
//    }
//};
//class spell_frost_bite_beacon : public SpellScriptLoader
//{
//public:
//    spell_frost_bite_beacon() : SpellScriptLoader("spell_frost_bite_beacon") { }
//
//    class spell_frost_bite_beacon_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_frost_bite_beacon_AuraScript);
//
//        void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//        {
//            if (GetTarget())
//            {
//                GetTarget()->AddAura(FROST_BITE_AURA, GetTarget());
//                AuraPtr aura = GetTarget()->GetAura(FROST_BITE_AURA);
//                if (aura)
//                {
//                    aura->SetStackAmount(5);
//                }
//            }
//        }
//
//        void Register()
//        {
//            AfterEffectRemove += AuraEffectRemoveFn(spell_frost_bite_beacon_AuraScript::OnRemove, EFFECT_0, SPELL_EFFECT_APPLY_AURA, AURA_EFFECT_HANDLE_REAL);
//        }
//    };
//
//    AuraScript* GetAuraScript() const
//    {
//        return new spell_frost_bite_beacon_AuraScript();
//    }
//};
//class spell_frost_bite_damage_on_hit : public SpellScriptLoader
//{
//public:
//    spell_frost_bite_damage_on_hit() : SpellScriptLoader("spell_frost_bite_damage_on_hit") { }
//
//    class spell_frost_bite_damage_on_hit_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_frost_bite_damage_on_hit_SpellScript);
//
//        void OnHitTarget()
//        {
//            if (GetCaster() || GetHitUnit())
//            {
//                if (GetCaster()->HasAura(FROST_BITE_AURA))
//                {
//                    AuraPtr aura = GetCaster()->GetAura(FROST_BITE_AURA);
//
//                    if (aura && aura->GetStackAmount() < 2)
//                    {
//                        aura->Remove();
//                    }
//                    if (aura)
//                    {
//                        aura->SetStackAmount(aura->GetStackAmount() - 1);
//                    }
//
//                }
//            }
//        }
//
//        void Register()
//        {
//            OnHit += SpellHitFn(spell_frost_bite_damage_on_hit_SpellScript::OnHitTarget);
//        }
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_frost_bite_damage_on_hit_SpellScript();
//    }
//};
//// alliance ... horde = 1
//class alliance_eventmaster : public CreatureScript
//{
//public:
//    alliance_eventmaster() : CreatureScript("alliance_eventmaster") { }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
//    {
//        player->PlayerTalkClass->ClearMenus();
//
//        if (action == GOSSIP_ACTION_INFO_DEF + 5)
//        {
//            if (player->HasItemCount(99535, 1))
//            {
//                player->DestroyItemCount(99535, 1, true);
//
//                if (roll_chance_i(25))
//                {
//                    switch (player->GetTeam())
//                    {
//                    case ALLIANCE:
//                        creature->MonsterSay("Thanks to your donation, the Alliance will have a chance to prevail thanks to this", LANG_UNIVERSAL, creature->GetGUID());
//                        break;
//                    case HORDE:
//                        creature->MonsterSay("Well done, Warrior of the Horde! Now, we're closer to rebuild this Death Machine and destroy the Alliance Stronghold", LANG_UNIVERSAL, creature->GetGUID());
//                        break;
//                    }
//                }
//
//                QueryResult result = WorldDatabase.PQuery("SELECT * FROM event_northhold_watch WHERE team = %u", player->GetTeam());
//
//                if (result)
//                {
//                    Field* fields = result->Fetch();
//                    uint32 id_list = fields[0].GetUInt32();
//                    uint32 team = fields[1].GetUInt32();
//
//                    uint32 id_list_32 = id_list + 1;
//
//                    WorldDatabase.DirectPExecute("UPDATE event_northhold_watch SET points = %u WHERE team = %u", id_list_32, player->GetTeam());
//
//                    player->CLOSE_GOSSIP_MENU();
//                    return true;
//                }
//            }
//        }
//        return true;
//    }
//    bool OnGossipHello(Player* player, Creature* creature)
//    {
//        QueryResult result = WorldDatabase.PQuery("SELECT * FROM event_northhold_watch WHERE team = %u", player->GetTeam());
//
//        if (result)
//        {
//            Field* fields = result->Fetch();
//            uint32 id_list = fields[0].GetUInt32();
//            uint32 team = fields[1].GetUInt32();
//            std::string ostring;
//
//            if (team == HORDE)
//            {          
//                ostring += "The Horde has ";
//                ostring += id_list;
//                ostring += " / ";
//                ostring += "3000";
//            }
//            else
//            {
//                ostring += "The Alliance has ";
//                ostring += id_list;
//                ostring += " / ";
//                ostring += "3000";
//            }
//
//            ChatHandler(player->GetSession()).PSendSysMessage("Your faction has: %u", id_list);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ostring.c_str(), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);          
//        }
//
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Donate your precious materials for the defense of Northhold Watch!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
//
//        player->SEND_GOSSIP_MENU(1, creature->GetGUID());
//        return true;
//    }
//};
//
//void AddSC_council()
//{
//    // I guess I will put it here, for no reason
//    new alliance_eventmaster();
//
//    // bosses
//    new boss_high_priestess_marli();
//    new boss_malak();
//    new boss_sul();
//    new boss_kazarjin();
//    new creature_garajal_spirit();
//    // spells
//    new spell_frost_bite_damage_on_hit();
//    new spell_frost_bite_dummy();
//    new spell_frost_bite_beacon();
//    new spell_bitting_cold_dummy();
//    new spell_friggid_stack_dummy();
//    // creatures
//    new creature_quick_sand();
//    new creature_loa_spirit_shadow();
//    new creature_loa_spirit_light();
//    new creature_living_sand();
//}
