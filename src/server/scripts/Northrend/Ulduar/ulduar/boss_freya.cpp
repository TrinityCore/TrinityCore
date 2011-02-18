/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Freya
SDAuthor: PrinceCreed
SD%Complete: 100
SD%Comments:
EndScriptData */

#include "ScriptPCH.h"
#include "ulduar.h"

enum Yells
{
    SAY_AGGRO                                   = -1603180,
    SAY_AGGRO_WITH_ELDER                        = -1603181,
    SAY_SLAY_1                                  = -1603182,
    SAY_SLAY_2                                  = -1603183,
    SAY_DEATH                                   = -1603184,
    SAY_BERSERK                                 = -1603185,
    SAY_SUMMON_CONSERVATOR                      = -1603186,
    SAY_SUMMON_TRIO                             = -1603187,
    SAY_SUMMON_LASHERS                          = -1603188,
    SAY_YS_HELP                                 = -1603189,

    // Elder Brightleaf
    SAY_BRIGHTLEAF_AGGRO                        = -1603190,
    SAY_BRIGHTLEAF_SLAY_1                       = -1603191,
    SAY_BRIGHTLEAF_SLAY_2                       = -1603192,
    SAY_BRIGHTLEAF_DEATH                        = -1603193,

    // Elder Ironbranch
    SAY_IRONBRANCH_AGGRO                        = -1603194,
    SAY_IRONBRANCH_SLAY_1                       = -1603195,
    SAY_IRONBRANCH_SLAY_2                       = -1603196,
    SAY_IRONBRANCH_DEATH                        = -1603197,

    // Elder Stonebark
    SAY_STONEBARK_AGGRO                         = -1603198,
    SAY_STONEBARK_SLAY_1                        = -1603199,
    SAY_STONEBARK_SLAY_2                        = -1603200,
    SAY_STONEBARK_DEATH                         = -1603201
};

#define EMOTE_GIFT                              "A Lifebinder's Gift begins to grow!"
#define EMOTE_ALLIES                            "Allies of Nature have appeared!"

#define ACHIEVEMENT_KNOCK_ON_WOOD_1             RAID_MODE(3177, 3185)
#define ACHIEVEMENT_KNOCK_ON_WOOD_2             RAID_MODE(3178, 3186)
#define ACHIEVEMENT_KNOCK_ON_WOOD_3             RAID_MODE(3179, 3187)
#define ACHIEVEMENT_BACK_TO_NATURE              RAID_MODE(2982, 2983)

enum Spells
{
    // Freya
    SPELL_ATTUNED_TO_NATURE                     = 62519,
    SPELL_TOUCH_OF_EONAR                        = 62528,
    SPELL_SUNBEAM                               = 62623,
    SPELL_SUN_BEAM_SUMMON                       = 62450,
    SPELL_EONAR_GIFT                            = 62572,
    SPELL_SPAWN_NATURE_BOMB                     = 64604,
    SPELL_NATURE_BOMB_VISUAL                    = 64648,
    SPELL_SUMMON_ALLIES                         = 62678,
    SPELL_BERSERK                               = 47008,
    SPELL_FREYA_GROUND_TREMOR                   = 62437,
    SPELL_FREYA_IRON_ROOTS                      = 62283,
    SPELL_FREYA_UNSTABLE_ENERGY                 = 62451,
    SPELL_STONEBARKS_ESSENCE                    = 62386,
    SPELL_IRONBRANCHS_ESSENCE                   = 62387,
    SPELL_BRIGHTLEAFS_ESSENCE                   = 62385,
    SPELL_DRAINED_OF_POWER                      = 62467,
    RAID_10_0_SPELL_FREYA_CHEST                 = 62950,
    RAID_10_1_SPELL_FREYA_CHEST                 = 62952,
    RAID_10_2_SPELL_FREYA_CHEST                 = 62953,
    RAID_10_3_SPELL_FREYA_CHEST                 = 62954,
    RAID_25_0_SPELL_FREYA_CHEST                 = 62955,
    RAID_25_1_SPELL_FREYA_CHEST                 = 62956,
    RAID_25_2_SPELL_FREYA_CHEST                 = 62957,
    RAID_25_3_SPELL_FREYA_CHEST                 = 62958,
       
    // Detonating Lasher
    SPELL_DETONATE                              = 62598,
    SPELL_FLAME_LASH                            = 62608,
        
    // Ancient Conservator
    SPELL_CONSERVATORS_GRIP                     = 62532,
    SPELL_NATURES_FURY                          = 62589,
    
    // Ancient Water Spirit
    SPELL_TIDAL_WAVE                            = 62935,
    
    // Storm Lasher
    SPELL_LIGHTNING_LASH                        = 62648,
    SPELL_STORMBOLT                             = 62649,
    
    // Snaplasher
    SPELL_HARDENED_BARK                         = 62664,
    
    // Nature Bomb
    SPELL_NATURE_BOMB                           = 64587,
    SPELL_SUMMON_NATURE_BOMB                    = 64600,
    
    // Eonars_Gift
    SPELL_LIFEBINDERS_GIFT                      = 62584, 
    SPELL_PHEROMONES                            = 62619,
    SPELL_EONAR_VISUAL                          = 62579,
    
    // Healthy Spore
    SPELL_HEALTHY_SPORE_VISUAL                  = 62538,
    SPELL_GROW                                  = 62559,
    SPELL_POTENT_PHEROMONES                     = 62541,
    SPELL_POTENT_PHEROMONES_AURA                = 64321,
    
    // Elder Stonebark
    SPELL_PETRIFIED_BARK                        = 62337,
    SPELL_FISTS_OF_STONE                        = 62344,
    SPELL_GROUND_TREMOR                         = 62325,
    
    // Elder Ironbranch
    SPELL_IMPALE                                = 62310,
    SPELL_THORN_SWARM                           = 64060,
    SPELL_IRON_ROOTS                            = 62438,
    
    // Elder Brightleaf
    SPELL_BRIGHTLEAF_FLUX                       = 62239,
    SPELL_UNSTABLE_ENERGY                       = 62217,
    SPELL_SOLAR_FLARE                           = 62240,
    SPELL_PHOTOSYNTHESIS                        = 62209,
    SPELL_UNSTABLE_SUN_BEAM                     = 62211,
    SPELL_UNSTABLE_SUN_BEAM_SUMMON              = 62450,
    SPELL_UNSTABLE_SUN_BEAM_VISUAL              = 62216
};

enum FreyaNpcs
{
    NPC_SUN_BEAM                                = 33170,
    NPC_DETONATING_LASHER                       = 32918,
    NPC_ANCIENT_CONSERVATOR                     = 33203,
    NPC_ANCIENT_WATER_SPIRIT                    = 33202,
    NPC_STORM_LASHER                            = 32919,
    NPC_SNAPLASHER                              = 32916,
    NPC_NATURE_BOMB                             = 34129,
    GOB_NATURE_BOMB                             = 194902,
    NPC_EONARS_GIFT                             = 33228,
    NPC_HEALTHY_SPORE                           = 33215,
    NPC_UNSTABLE_SUN_BEAM                       = 33050
};

enum Events
{
    EVENT_NONE,
    EVENT_SUNBEAM,
    EVENT_EONAR_GIFT,
    EVENT_SUMMON_ALLIES,
    EVENT_NATURE_BOMB,
    EVENT_BRIGHTLEAF,
    EVENT_IRONBRANCH,
    EVENT_STONEBARK,
    EVENT_PHASE_2,
    EVENT_BERSERK
};

enum Actions
{
    ACTION_LASHER                               = 0,
    ACTION_ELEMENTAL                            = 1,
    ACTION_ANCIENT                              = 2,
    ACTION_ELEMENTAL_DEAD                       = 3
};

enum
{
    // Con-speed-atory timed achievement.
    // TODO Should be started when 1st trash is killed.
    ACHIEV_CON_SPEED_ATORY_START_EVENT          = 21597,
    SPELL_ACHIEVEMENT_CHECK                     = 65074,

    // Lumberjacked timed achievement.
    // TODO should be started when 1st elder is killed.
    // Spell should be casted when 3rd elder is killed.
    ACHIEV_LUMBERJACKED                         = 21686,
    SPELL_LUMBERJACKED_ACHIEVEMENT_CHECK        = 65296,
};

class boss_freya : public CreatureScript
{
public:
    boss_freya() : CreatureScript("boss_freya") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_freyaAI(pCreature);
    }

    struct boss_freyaAI : public BossAI
    {
        boss_freyaAI(Creature* pCreature) : BossAI(pCreature, BOSS_FREYA)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        }

        uint8 spawnOrder[3];
        uint8 spawnedAdds;
        uint8 EldersCount;
        int32 uiElemTimer;
        Creature* Elemental[3];
        bool checkElementalAlive;

        void Reset()
        {
            _Reset();
        
            if (instance)
            {
                for (uint8 data = DATA_BRIGHTLEAF; data <= DATA_STONEBARK; ++data)
                {
                    if (Creature *pCreature = Creature::GetCreature((*me), instance->GetData64(data)))
                    {
                        if (pCreature->isAlive())
                            pCreature->AI()->EnterEvadeMode();
                    }
                }
            }
            me->UpdateMaxHealth();
            spawnedAdds = 0;
            EldersCount = 0;
            checkElementalAlive = true;
            randomizeSpawnOrder();        
        }

        void KilledUnit(Unit * /*victim*/)
        {
            if (!(rand()%5))
                DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), me);
        }

        void JustDied(Unit * /*victim*/)
        {
            DoScriptText(SAY_DEATH, me);
            _JustDied();
        
            me->setFaction(35);
        
            if (instance)
            {
                // Kill credit
                instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, 65074);
                // Knock on Wood
                if (EldersCount == 1)
                    instance->DoCompleteAchievement(ACHIEVEMENT_KNOCK_ON_WOOD_1);
                // Knock, Knock on Wood 
                if (EldersCount == 2)
                    instance->DoCompleteAchievement(ACHIEVEMENT_KNOCK_ON_WOOD_2);
                // Knock, Knock, Knock on Wood
                if (EldersCount == 3)
                    instance->DoCompleteAchievement(ACHIEVEMENT_KNOCK_ON_WOOD_3);
                // Getting Back to Nature
                if (me->HasAura(SPELL_ATTUNED_TO_NATURE))
                    if (me->GetAura(SPELL_ATTUNED_TO_NATURE, 0)->GetStackAmount() >= 25)
                        instance->DoCompleteAchievement(ACHIEVEMENT_BACK_TO_NATURE);
            }
        
            // Hard mode chest
            uint32 chest;
            switch (EldersCount)
            {
                case 0:
                    chest = RAID_MODE(194324, 194328);
                    break;
                case 1:
                    chest = RAID_MODE(194325, 194329);
                    break;
                case 2:
                    chest = RAID_MODE(194326, 194330);
                    break;
                case 3:
                    chest = RAID_MODE(194327, 194331);
                    break;
            }
            // Summon spells not work correctly, chest respawn is infinite
            me->SummonGameObject(chest,(me->GetPositionX()+15*cos(me->GetOrientation())),(me->GetPositionY()+15*sin(me->GetOrientation())),me->GetPositionZ(),me->GetOrientation(),0,0,1,0,0);
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            _EnterCombat();
        
            DoCast(me, SPELL_TOUCH_OF_EONAR);
            for (uint32 i = 0; i < 150; ++i)
                DoCast(me, SPELL_ATTUNED_TO_NATURE);

            events.ScheduleEvent(EVENT_SUNBEAM, 20000);
            events.ScheduleEvent(EVENT_EONAR_GIFT, 30000);
            events.ScheduleEvent(EVENT_SUMMON_ALLIES, 10000);
            events.ScheduleEvent(EVENT_NATURE_BOMB, 375000);
            events.ScheduleEvent(EVENT_BERSERK, 600000);
        
            if (instance)
            {
                // Freya hard mode can be triggered simply by letting the elders alive
                if (Creature* Brightleaf = me->GetCreature(*me, instance->GetData64(DATA_BRIGHTLEAF)))
                    if (Brightleaf->isAlive())
                    {
                        EldersCount++;
                        Brightleaf->SetInCombatWithZone();
                        Brightleaf->AddAura(SPELL_BRIGHTLEAFS_ESSENCE, Brightleaf);
                        Brightleaf->AddAura(SPELL_DRAINED_OF_POWER, Brightleaf);
                        events.ScheduleEvent(EVENT_BRIGHTLEAF, urand(15000, 30000));
                    }
            
                if (Creature* Ironbranch = me->GetCreature(*me, instance->GetData64(DATA_IRONBRANCH)))
                    if (Ironbranch->isAlive())
                    {
                        EldersCount++;
                        Ironbranch->SetInCombatWithZone();
                        Ironbranch->AddAura(SPELL_IRONBRANCHS_ESSENCE, Ironbranch);
                        Ironbranch->AddAura(SPELL_DRAINED_OF_POWER, Ironbranch);
                        events.ScheduleEvent(EVENT_IRONBRANCH, urand(45000, 60000));
                    }
            
                if (Creature* Stonebark = me->GetCreature(*me, instance->GetData64(DATA_STONEBARK)))
                    if (Stonebark->isAlive())
                    {
                        EldersCount++;
                        Stonebark->SetInCombatWithZone();
                        me->AddAura(SPELL_STONEBARKS_ESSENCE, me);
                        Stonebark->AddAura(SPELL_DRAINED_OF_POWER, Stonebark);
                        events.ScheduleEvent(EVENT_STONEBARK, urand(35000, 45000));
                    }
            }
            if (EldersCount == 0)
                DoScriptText(SAY_AGGRO, me);
            else
            {
                DoScriptText(SAY_AGGRO_WITH_ELDER, me);
                // each Elder left up will increase the health of both Freya and her adds. (20% per Elder)
                me->SetMaxHealth(me->GetMaxHealth() + (uint32)(me->GetMaxHealth() * EldersCount * 20 / 100));
                me->SetHealth(me->GetMaxHealth());
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            // Elementals must be killed within 12 seconds of each other, or they will all revive and heal
            if (checkElementalAlive)
                uiElemTimer = 0;
            else
            {
                uiElemTimer += diff;
                if (uiElemTimer > 12000)
                {
                    for (uint32 i = 0; i < 3; i++)
                    {
                        if (Elemental[i]->isAlive())
                            Elemental[i]->SetHealth(Elemental[i]->GetMaxHealth());
                        else
                            Elemental[i]->Respawn();
                    }
                    checkElementalAlive = true;
                }
                else
                {
                    if (Elemental[0]->isDead())
                        if (Elemental[1]->isDead())
                            if (Elemental[2]->isDead())
                            {
                                for (uint32 i = 0; i < 3; i++)
                                    Elemental[i]->ForcedDespawn(3000);
                                
                                if (Creature* Freya = me->GetCreature(*me, instance->GetData64(DATA_FREYA)))
                                    Freya->AI()->DoAction(ACTION_ELEMENTAL);
                            }
                }
            }
                           
            if (me->getVictim() && !me->getVictim()->GetCharmerOrOwnerPlayerOrPlayerItself())
                me->Kill(me->getVictim());
            
            events.Update(diff);
                        
            if (events.GetTimer() > 360000)
                events.CancelEvent(EVENT_SUMMON_ALLIES);
            
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_SUNBEAM:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            if (pTarget->isAlive())
                                DoCast(pTarget, SPELL_SUNBEAM);
                        events.ScheduleEvent(EVENT_SUNBEAM, urand(10000, 15000));
                        break;
                    case EVENT_EONAR_GIFT:
                        me->MonsterTextEmote(EMOTE_GIFT, 0, true);
                        DoCast(SPELL_EONAR_GIFT);
                        events.ScheduleEvent(EVENT_EONAR_GIFT, urand(35000, 45000));
                        break;
                    case EVENT_SUMMON_ALLIES:
                        me->MonsterTextEmote(EMOTE_ALLIES, 0, true);
                        DoCast(me, SPELL_SUMMON_ALLIES);
                        spawnAdd();
                        events.ScheduleEvent(EVENT_SUMMON_ALLIES, 60000);
                        break;
                    case EVENT_NATURE_BOMB:
                        DoCastAOE(SPELL_NATURE_BOMB_VISUAL);
                        DoCastAOE(SPELL_SPAWN_NATURE_BOMB);
                        events.ScheduleEvent(EVENT_NATURE_BOMB, urand(15000, 20000));
                        break;
                    case EVENT_BRIGHTLEAF:
                        for (int8 n = 0; n < 3; n++)
                        {
                            Position pos;
                            me->GetRandomNearPosition(pos, 30);
                            me->SummonCreature(NPC_SUN_BEAM, pos, TEMPSUMMON_TIMED_DESPAWN, 10000);
                        }
                        events.ScheduleEvent(EVENT_BRIGHTLEAF, urand(35000, 45000));
                        break;
                    case EVENT_IRONBRANCH:
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            pTarget->CastSpell(pTarget, SPELL_FREYA_IRON_ROOTS,true);
                        events.ScheduleEvent(EVENT_IRONBRANCH, urand(45000, 60000));
                        break;
                    case EVENT_STONEBARK:
                        DoCastAOE(SPELL_FREYA_GROUND_TREMOR);
                        events.ScheduleEvent(EVENT_STONEBARK, urand(25000, 30000));
                        break;
                    case EVENT_BERSERK:
                        DoCast(me, SPELL_BERSERK, true);
                        DoScriptText(SAY_BERSERK, me);
                        events.CancelEvent(EVENT_BERSERK);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    
        void randomizeSpawnOrder()
        {
            //Spawn order algorithm
            spawnOrder[0] = 0; //Detonating Lasher
            spawnOrder[1] = 1; //Elemental Adds 
            spawnOrder[2] = 2; //Ancient Conservator
        
            //Swaps the entire array
            for(uint8 n = 0; n < 3; n++)
            {
                uint8 random = rand() % 2;
                uint8 temp = spawnOrder[random];
                spawnOrder[random] = spawnOrder[n];
                spawnOrder[n] = temp;
            }
        }

        void spawnAdd()
        {
            switch(spawnedAdds)
            {
                case 0: spawnHandler(spawnOrder[0]);break;
                case 1: spawnHandler(spawnOrder[1]);break;
                case 2: spawnHandler(spawnOrder[2]);break;
            }

            spawnedAdds++;
            if (spawnedAdds > 2)
            {
                spawnedAdds = 0;
            }
        }

        void spawnHandler(uint8 add)
        {
            switch(add)
            {
                case 0:
                {
                    DoScriptText(SAY_SUMMON_LASHERS, me);
                    //Spawn 10 Detonating Lashers
                    for(uint8 n = 0; n < 10; n++)
                    {
                        //Make sure that they don't spawn in a pile
                        int8 randomX = -25 + rand() % 50;
                        int8 randomY = -25 + rand() % 50;
                        me->SummonCreature(NPC_DETONATING_LASHER, me->GetPositionX() + randomX, me->GetPositionY() + randomY, me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1500);
                    }
                    break;
                }
                case 1:
                {
                    DoScriptText(SAY_SUMMON_TRIO, me);
                    //Make sure that they don't spawn in a pile
                    int8 randomX = -25 + rand() % 50;
                    int8 randomY = -25 + rand() % 50;
                    Elemental[0] = me->SummonCreature(NPC_SNAPLASHER, me->GetPositionX() + randomX, me->GetPositionY() + randomY, me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN);
                    randomX = -25 + rand() % 50;
                    randomY = -25 + rand() % 50;
                    Elemental[1] = me->SummonCreature(NPC_ANCIENT_WATER_SPIRIT, me->GetPositionX() + randomX, me->GetPositionY() + randomY, me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN);
                    randomX = -25 + rand() % 50;
                    randomY = -25 + rand() % 50;
                    Elemental[2] = me->SummonCreature(NPC_STORM_LASHER, me->GetPositionX() + randomX, me->GetPositionY() + randomY, me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN);
                    break;
                }
                case 2: 
                {
                    DoScriptText(SAY_SUMMON_CONSERVATOR, me);
                    int8 randomX = -25 + rand() % 50;
                    int8 randomY = -25 + rand() % 50;
                    me->SummonCreature(NPC_ANCIENT_CONSERVATOR, me->GetPositionX() + randomX, me->GetPositionY() + randomY, me->GetPositionZ()+1, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 7000);
                    break;
                }
            }
        }
    
        void DoAction(const int32 action)
        {
            switch (action)
            {
                case ACTION_LASHER:
                    for (uint32 i = 0; i < 2; ++i)
                        me->RemoveAuraFromStack(SPELL_ATTUNED_TO_NATURE, 0, AURA_REMOVE_BY_DEFAULT);
                    break;
                case ACTION_ELEMENTAL:
                    checkElementalAlive = true;
                    for (uint32 i = 0; i < 30; ++i)
                        me->RemoveAuraFromStack(SPELL_ATTUNED_TO_NATURE, 0, AURA_REMOVE_BY_DEFAULT);
                    break;
                case ACTION_ANCIENT:
                    for (uint32 i = 0; i < 25; ++i)
                        me->RemoveAuraFromStack(SPELL_ATTUNED_TO_NATURE, 0, AURA_REMOVE_BY_DEFAULT);
                    break;
                case ACTION_ELEMENTAL_DEAD:
                    checkElementalAlive = false;
                    break;
            }
        }
    };

};


class npc_elder_brightleaf : public CreatureScript
{
public:
    npc_elder_brightleaf() : CreatureScript("npc_elder_brightleaf") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_elder_brightleafAI (pCreature);
    }

    struct npc_elder_brightleafAI : public ScriptedAI
    {
        npc_elder_brightleafAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        uint32 uiUnstableSunbeamTimer;
        uint32 uiSolarFlareTimer;
        uint32 uiUnstableEnergyTimer;
        uint32 uiBrightleafFluxTimer;

        void Reset()
        {
            uiUnstableSunbeamTimer = 5000;
            uiSolarFlareTimer = 10000;
            uiUnstableEnergyTimer = 20000;
            uiBrightleafFluxTimer = 0;
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            DoScriptText(SAY_BRIGHTLEAF_AGGRO, me);
        }
    
        void KilledUnit(Unit* /*victim*/)
        {
            if (!(rand()%5))
                 DoScriptText(RAND(SAY_BRIGHTLEAF_SLAY_1,SAY_BRIGHTLEAF_SLAY_2), me);
        }

        void JustDied(Unit* /*victim*/)
        {
            DoScriptText(SAY_BRIGHTLEAF_DEATH, me);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            
            if (GetClosestCreatureWithEntry(me, NPC_SUN_BEAM, 4.0f))
                DoCast(me, SPELL_PHOTOSYNTHESIS, true);

            if (uiUnstableSunbeamTimer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    if (pTarget->isAlive())
                        me->SummonCreature(NPC_UNSTABLE_SUN_BEAM, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 10000);
                uiUnstableSunbeamTimer = 8000;
            }
            else uiUnstableSunbeamTimer -= diff;

            if (uiSolarFlareTimer <= diff)
            {
                DoCast(SPELL_SOLAR_FLARE);
                uiSolarFlareTimer = urand(10000, 15000);
            }
            else uiSolarFlareTimer -= diff;
            
            if (uiUnstableEnergyTimer <= diff)
            {
                DoCast(SPELL_UNSTABLE_ENERGY);
                uiUnstableEnergyTimer = 15000;
            }
            else uiUnstableEnergyTimer -= diff;
            
            if (uiBrightleafFluxTimer <= diff)
            {
                me->RemoveAurasDueToSpell(SPELL_BRIGHTLEAF_FLUX);
                for (uint32 i = 0; i < urand(1,10); ++i)
                    DoCast(me, SPELL_BRIGHTLEAF_FLUX);
            
                uiBrightleafFluxTimer = 4000;
            }
            else uiBrightleafFluxTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};


class npc_sun_beam : public CreatureScript
{
public:
    npc_sun_beam() : CreatureScript("npc_sun_beam") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_sun_beamAI (pCreature);
    }

    struct npc_sun_beamAI : public Scripted_NoMovementAI
    {
        npc_sun_beamAI(Creature *pCreature) : Scripted_NoMovementAI(pCreature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
            me->SetDisplayId(23258);
            DoCast(SPELL_FREYA_UNSTABLE_ENERGY);
            DoCast(SPELL_UNSTABLE_SUN_BEAM_VISUAL);
        }
    };

};


class npc_unstable_sun_beam : public CreatureScript
{
public:
    npc_unstable_sun_beam() : CreatureScript("npc_unstable_sun_beam") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_unstable_sun_beamAI (pCreature);
    }

    struct npc_unstable_sun_beamAI : public Scripted_NoMovementAI
    {
        npc_unstable_sun_beamAI(Creature *pCreature) : Scripted_NoMovementAI(pCreature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
            me->SetDisplayId(23258);
            DoCast(SPELL_UNSTABLE_SUN_BEAM);
        }
    };

};


class npc_elder_ironbranch : public CreatureScript
{
public:
    npc_elder_ironbranch() : CreatureScript("npc_elder_ironbranch") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_elder_ironbranchAI (pCreature);
    }

    struct npc_elder_ironbranchAI : public ScriptedAI
    {
        npc_elder_ironbranchAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        uint32 uiImpaleTimer;
        uint32 uiThornSwarmTimer;
        uint32 uiIronRootTimer;

        void Reset()
        {
            uiImpaleTimer = 15000;
            uiThornSwarmTimer = 20000;
            uiIronRootTimer = 8000;
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            DoScriptText(SAY_IRONBRANCH_AGGRO, me);
        }
    
        void KilledUnit(Unit* /*victim*/)
        {
            if (!(rand()%5))
                 DoScriptText(RAND(SAY_IRONBRANCH_SLAY_1,SAY_IRONBRANCH_SLAY_2), me);
        }

        void JustDied(Unit* /*victim*/)
        {
            DoScriptText(SAY_IRONBRANCH_DEATH, me);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiImpaleTimer <= diff && me->IsWithinMeleeRange(me->getVictim()))
            {
                DoCastVictim(SPELL_IMPALE);
                uiImpaleTimer = urand(15000, 20000);
            }
            else uiImpaleTimer -= diff;

            if (uiThornSwarmTimer <= diff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    DoCast(pTarget, SPELL_THORN_SWARM);
                uiThornSwarmTimer = urand(20000, 24000);
            }
            else uiThornSwarmTimer -= diff;

            if (uiIronRootTimer <= diff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                {
                    if (pTarget && !pTarget->HasAura(SPELL_IMPALE))
                        pTarget->CastSpell(pTarget, SPELL_IRON_ROOTS, true);
                }
                uiIronRootTimer = urand(20000, 25000);
            }
            else uiIronRootTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};


class npc_iron_roots : public CreatureScript
{
public:
    npc_iron_roots() : CreatureScript("npc_iron_roots") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_iron_rootsAI (pCreature);
    }

    struct npc_iron_rootsAI : public Scripted_NoMovementAI
    {
        npc_iron_rootsAI(Creature *pCreature) : Scripted_NoMovementAI(pCreature) 
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_STUNNED);
            me->setFaction(16);
        }

        void JustDied(Unit* victim)
        {
            if (me->ToTempSummon()->GetSummoner())
            {
                if (me->GetEntry() == 33088)    // Iron Roots
                    me->ToTempSummon()->GetSummoner()->RemoveAurasDueToSpell(SPELL_FREYA_IRON_ROOTS);
                else                            // Strengthened Iron Roots
                    me->ToTempSummon()->GetSummoner()->RemoveAurasDueToSpell(SPELL_IRON_ROOTS);
            }

            me->ForcedDespawn(2000);
        }
    };

};


class npc_elder_stonebark : public CreatureScript
{
public:
    npc_elder_stonebark() : CreatureScript("npc_elder_stonebark") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_elder_stonebarkAI (pCreature);
    }

    struct npc_elder_stonebarkAI : public ScriptedAI
    {
        npc_elder_stonebarkAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        uint32 uiGroundTremorTimer;
        uint32 uiFistsOfStoneTimer;
        uint32 uiPetrifiedBarkTimer;

        void Reset()
        {
            uiGroundTremorTimer = urand(5000, 10000);
            uiFistsOfStoneTimer = 25000;
            uiPetrifiedBarkTimer = 35000;
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            DoScriptText(SAY_STONEBARK_AGGRO, me);
        }
    
        void KilledUnit(Unit* /*victim*/)
        {
            if (!(rand()%5))
                 DoScriptText(RAND(SAY_STONEBARK_SLAY_1,SAY_STONEBARK_SLAY_2), me);
        }

        void JustDied(Unit* /*victim*/)
        {
            DoScriptText(SAY_STONEBARK_DEATH, me);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_CASTING))
                return;

            if (uiGroundTremorTimer <= diff)
            {
                DoCastVictim(SPELL_GROUND_TREMOR);
                uiGroundTremorTimer = urand(20000, 25000);
            }
            else uiGroundTremorTimer -= diff;

            if (uiFistsOfStoneTimer <= diff)
            {
                DoCast(me, SPELL_PETRIFIED_BARK);
                uiFistsOfStoneTimer = 50000;
            }
            else uiFistsOfStoneTimer -= diff;
        
            if (uiPetrifiedBarkTimer <= diff)
            {
                DoCast(me, SPELL_FISTS_OF_STONE);
                uiPetrifiedBarkTimer = 60000;
            }
            else uiPetrifiedBarkTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};


class npc_eonars_gift : public CreatureScript
{
public:
    npc_eonars_gift() : CreatureScript("npc_eonars_gift") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_eonars_giftAI (pCreature);
    }

    struct npc_eonars_giftAI : public Scripted_NoMovementAI
    {
        npc_eonars_giftAI(Creature *pCreature) : Scripted_NoMovementAI(pCreature)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_STUNNED);
            fScale = 0.2f;
            me->SetFloatValue(OBJECT_FIELD_SCALE_X, fScale);
            uiScaleTimer = 200;
            uiLifebindersGiftTimer = 12000;
            DoCast(me, SPELL_PHEROMONES, true);
            DoCast(me, SPELL_EONAR_VISUAL, true);
        }

        float fScale;
        uint32 uiScaleTimer;
        uint32 uiLifebindersGiftTimer;

        void UpdateAI(const uint32 diff)
        {
            if (uiLifebindersGiftTimer <= diff)
            {
                DoCast(me, SPELL_LIFEBINDERS_GIFT, true);
                me->SetFloatValue(OBJECT_FIELD_SCALE_X, 0);
                me->ForcedDespawn(1000);
                uiLifebindersGiftTimer = 12000;
            }
            else uiLifebindersGiftTimer -= diff;

            if (uiScaleTimer <= diff)
            {
                fScale += 0.025f;
                me->SetFloatValue(OBJECT_FIELD_SCALE_X, fScale);
            }
            else uiScaleTimer -= diff;
        }
    };

};


class npc_nature_bomb : public CreatureScript
{
public:
    npc_nature_bomb() : CreatureScript("npc_nature_bomb") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_nature_bombAI (pCreature);
    }

    struct npc_nature_bombAI : public Scripted_NoMovementAI
    {
        npc_nature_bombAI(Creature *pCreature) : Scripted_NoMovementAI(pCreature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetDisplayId(23258);
            uiExplosionTimer = 10000;
            DoCast(me, SPELL_SUMMON_NATURE_BOMB, true);
        }

        uint32 uiExplosionTimer;

        void UpdateAI(const uint32 diff)
        {
            if (uiExplosionTimer <= diff)
            {
                DoCast(me, SPELL_NATURE_BOMB);
                if (GameObject* pBomb = me->FindNearestGameObject(GOB_NATURE_BOMB, 1))
                    me->RemoveGameObject(pBomb, true);
                me->ForcedDespawn(2000);
                uiExplosionTimer = 10000;
            }
            else uiExplosionTimer -= diff;
        }
    };

};


class npc_detonating_lasher : public CreatureScript
{
public:
    npc_detonating_lasher() : CreatureScript("npc_detonating_lasher") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_detonating_lasherAI (pCreature);
    }

    struct npc_detonating_lasherAI : public ScriptedAI
    {
        npc_detonating_lasherAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        uint32 uiFlameLashTimer;
        uint32 uiSwitchTargetTimer;

        void Reset()
        {
            uiFlameLashTimer = urand(5000, 10000);
            uiSwitchTargetTimer = urand(6000, 8000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiFlameLashTimer <= diff)
            {
                DoCastVictim(SPELL_FLAME_LASH);
                uiFlameLashTimer = urand(5000, 10000);
            }
            else uiFlameLashTimer -= diff;

            if (uiSwitchTargetTimer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 60, true))
                    me->AI()->AttackStart(pTarget);
                uiSwitchTargetTimer = urand(6000, 8000);
            }
            else uiSwitchTargetTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*victim*/)
        {
            DoCast(me, SPELL_DETONATE);

            if (Creature* Freya = me->GetCreature(*me, pInstance->GetData64(DATA_FREYA)))
                Freya->AI()->DoAction(ACTION_LASHER);
        }
    };

};


class npc_ancient_conservator : public CreatureScript
{
public:
    npc_ancient_conservator() : CreatureScript("npc_ancient_conservator") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_ancient_conservatorAI (pCreature);
    }

    struct npc_ancient_conservatorAI : public ScriptedAI
    {
        npc_ancient_conservatorAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        }

        InstanceScript* pInstance;
        uint32 uiNaturesFuryTimer;
        uint32 uiSpawnHealthySporeTimer;
        uint32 uiSpawnPauseTimer;
        uint8 healthySporesSpawned;

        void EnterCombat(Unit* /*pWho*/)
        {
            DoCast(me, SPELL_CONSERVATORS_GRIP);
        }

        void Reset()
        {
            uiNaturesFuryTimer = 5000;
            uiSpawnHealthySporeTimer = 0;
            uiSpawnPauseTimer = 20000;
            healthySporesSpawned = 0;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() || (me->HasUnitState(UNIT_STAT_CASTING)))
                return;

            if (uiNaturesFuryTimer <= diff)
            {
                Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 60, true);
                //Prevent casting natures fury on a target that is already affected
                if (pTarget && !pTarget->HasAura(SPELL_NATURES_FURY))
                    DoCast(pTarget, SPELL_NATURES_FURY);
                me->AddAura(SPELL_CONSERVATORS_GRIP, me);
                uiNaturesFuryTimer = 5000;
            }
            else uiNaturesFuryTimer -= diff;

            if (uiSpawnHealthySporeTimer <= diff && healthySporesSpawned < 10)
            {
                for (uint32 i = 0; i < 2; ++i)
                {
                    Position pos;
                    me->GetRandomNearPosition(pos, 25);
                    me->SummonCreature(NPC_HEALTHY_SPORE, pos, TEMPSUMMON_TIMED_DESPAWN, 20000);
                }
                healthySporesSpawned += 2;
                uiSpawnHealthySporeTimer = 2000;
            }
            else uiSpawnHealthySporeTimer -= diff;

            if (uiSpawnPauseTimer <= diff)
            {
                healthySporesSpawned = 0;
                uiSpawnPauseTimer = 20000;
                uiSpawnHealthySporeTimer = 0;
            }
            else uiSpawnPauseTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*victim*/)
        {
            if (Creature* Freya = me->GetCreature(*me, pInstance->GetData64(DATA_FREYA)))
                Freya->AI()->DoAction(ACTION_ANCIENT);
        }
    };

};


class npc_healthy_spore : public CreatureScript
{
public:
    npc_healthy_spore() : CreatureScript("npc_healthy_spore") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_healthy_sporeAI (pCreature);
    }

    struct npc_healthy_sporeAI : public Scripted_NoMovementAI
    {
        npc_healthy_sporeAI(Creature *pCreature) : Scripted_NoMovementAI(pCreature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetInCombatWithZone();
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!me->HasAura(SPELL_HEALTHY_SPORE_VISUAL))
            {
                DoCast(me, SPELL_HEALTHY_SPORE_VISUAL);
                DoCast(me, SPELL_POTENT_PHEROMONES);
                DoCast(me, SPELL_GROW);
            }
        }
    };

};


class npc_storm_lasher : public CreatureScript
{
public:
    npc_storm_lasher() : CreatureScript("npc_storm_lasher") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_storm_lasherAI (pCreature);
    }

    struct npc_storm_lasherAI : public ScriptedAI
    {
        npc_storm_lasherAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        uint32 uiLightningLashTimer;
        uint32 uiStormboltTimer;

        void Reset()
        {
            uiLightningLashTimer = 4000;
            uiStormboltTimer = 15000;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() || (me->HasUnitState(UNIT_STAT_CASTING)))
                return;
            
            if (uiLightningLashTimer <= diff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 60, true))
                    DoCast(pTarget, SPELL_LIGHTNING_LASH);
                uiLightningLashTimer = urand(3000, 6000);
            }
            else uiLightningLashTimer -= diff;

            if (uiStormboltTimer <= diff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 60, true))
                    DoCast(pTarget, SPELL_STORMBOLT);
                uiStormboltTimer = 15000;
            }
            else uiStormboltTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*victim*/)
        {
            if (Creature* Freya = me->GetCreature(*me, pInstance->GetData64(DATA_FREYA)))
                Freya->AI()->DoAction(ACTION_ELEMENTAL_DEAD);
        }
    };

};


class npc_snaplasher : public CreatureScript
{
public:
    npc_snaplasher() : CreatureScript("npc_snaplasher") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_snaplasherAI (pCreature);
    }

    struct npc_snaplasherAI : public ScriptedAI
    {
        npc_snaplasherAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
            DoCast(me, SPELL_HARDENED_BARK);
        }

        InstanceScript* pInstance;

        void JustDied(Unit* /*victim*/)
        {
            if (Creature* Freya = me->GetCreature(*me, pInstance->GetData64(DATA_FREYA)))
                Freya->AI()->DoAction(ACTION_ELEMENTAL_DEAD);
        }
    };

};

class npc_ancient_water_spirit : public CreatureScript
{
public:
    npc_ancient_water_spirit() : CreatureScript("npc_ancient_water_spirit") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_ancient_water_spiritAI (pCreature);
    }

    struct npc_ancient_water_spiritAI : public ScriptedAI
    {
        npc_ancient_water_spiritAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        uint32 uiTidalWaveTimer;

        void Reset()
        {
            uiTidalWaveTimer = 10000;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiTidalWaveTimer <= diff)
            {
                DoCastVictim(SPELL_TIDAL_WAVE);
                uiTidalWaveTimer = 15000;
            }
            else uiTidalWaveTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*victim*/)
        {
            if (Creature* Freya = me->GetCreature(*me, pInstance->GetData64(DATA_FREYA)))
                Freya->AI()->DoAction(ACTION_ELEMENTAL_DEAD);
        }
    };

};


void AddSC_boss_freya()
{
    new boss_freya();
    new npc_elder_brightleaf();
    new npc_sun_beam();
    new npc_unstable_sun_beam();
    new npc_elder_ironbranch();
    new npc_iron_roots();
    new npc_elder_stonebark();
    new npc_eonars_gift();
    new npc_nature_bomb();
    new npc_detonating_lasher();
    new npc_ancient_conservator();
    new npc_healthy_spore();
    new npc_storm_lasher();
    new npc_snaplasher();
    new npc_ancient_water_spirit();
}
