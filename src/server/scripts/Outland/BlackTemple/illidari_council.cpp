/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
SDName: Illidari_Council
SD%Complete: 95
SDComment: Circle of Healing not working properly.
SDCategory: Black Temple
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "black_temple.h"

enum IllidariCouncil
{
    //Speech'n'Sounds
    SAY_GATH_SPECIAL1           = 2,
    SAY_GATH_SPECIAL2           = 3,
    SAY_GATH_SLAY               = 4,
    SAY_GATH_COMNT              = 5,
    SAY_GATH_DEATH              = 6,

    SAY_MALA_SPECIAL1           = 2,
    SAY_MALA_SPECIAL2           = 3,
    SAY_MALA_SLAY               = 4,
    SAY_MALA_COMNT              = 5,
    SAY_MALA_DEATH              = 6,

    SAY_ZERE_SPECIAL1           = 2,
    SAY_ZERE_SPECIAL2           = 3,
    SAY_ZERE_SLAY               = 4,
    SAY_ZERE_COMNT              = 5,
    SAY_ZERE_DEATH              = 6,

    SAY_VERA_SPECIAL1           = 2,
    SAY_VERA_SPECIAL2           = 3,
    SAY_VERA_SLAY               = 4,
    SAY_VERA_COMNT              = 5,
    SAY_VERA_DEATH              = 6,

    AKAMAID                     = 23089,

    // High Nethermancer Zerevor's spells
    SPELL_FLAMESTRIKE           = 41481,
    SPELL_BLIZZARD              = 41482,
    SPELL_ARCANE_BOLT           = 41483,
    SPELL_ARCANE_EXPLOSION      = 41524,
    SPELL_DAMPEN_MAGIC          = 41478,

    // Lady Malande's spells
    SPELL_EMPOWERED_SMITE       = 41471,
    SPELL_CIRCLE_OF_HEALING     = 41455,
    SPELL_REFLECTIVE_SHIELD     = 41475,
    SPELL_REFLECTIVE_SHIELD_T   = 33619,
    SPELL_DIVINE_WRATH          = 41472,
    SPELL_HEAL_VISUAL           = 24171,

    // Gathios the Shatterer's spells
    SPELL_BLESS_PROTECTION      = 41450,
    SPELL_BLESS_SPELLWARD       = 41451,
    SPELL_CONSECRATION          = 41541,
    SPELL_HAMMER_OF_JUSTICE     = 41468,
    SPELL_SEAL_OF_COMMAND       = 41469,
    SPELL_SEAL_OF_BLOOD         = 41459,
    SPELL_CHROMATIC_AURA        = 41453,
    SPELL_DEVOTION_AURA         = 41452,

    // Veras Darkshadow's spells
    SPELL_DEADLY_POISON         = 41485,
    SPELL_ENVENOM               = 41487,
    SPELL_VANISH                = 41479,
    SPELL_BERSERK               = 45078
};

#define ERROR_INST_DATA           "SD2 ERROR: Instance Data for Black Temple not set properly; Illidari Council event will not function properly."

struct CouncilYells
{
    int32 entry;
    uint32 timer;
};

static CouncilYells CouncilAggro[]=
{
    {0, 5000},                                       // Gathios
    {0, 5500},                                       // Veras
    {0, 5000},                                       // Malande
    {0, 0},                                          // Zerevor
};

// Need to get proper timers for this later
static CouncilYells CouncilEnrage[]=
{
    {1, 2000},                                       // Gathios
    {1, 6000},                                       // Veras
    {1, 5000},                                       // Malande
    {1, 0},                                          // Zerevor
};

class npc_blood_elf_council_voice_trigger : public CreatureScript
{
public:
    npc_blood_elf_council_voice_trigger() : CreatureScript("npc_blood_elf_council_voice_trigger") { }

    CreatureAI* GetAI(Creature* c) const override
    {
        return new npc_blood_elf_council_voice_triggerAI(c);
    }

    struct npc_blood_elf_council_voice_triggerAI : public ScriptedAI
    {
        npc_blood_elf_council_voice_triggerAI(Creature* creature) : ScriptedAI(creature)
        {
            for (uint8 i = 0; i < 4; ++i)
                Council[i] = 0;
        }

        uint64 Council[4];

        uint32 EnrageTimer;
        uint32 AggroYellTimer;

        uint8 YellCounter;                                      // Serves as the counter for both the aggro and enrage yells

        bool EventStarted;

        void Reset() override
        {
            EnrageTimer = 900000;                               // 15 minutes
            AggroYellTimer = 500;

            YellCounter = 0;

            EventStarted = false;
        }

        // finds and stores the GUIDs for each Council member using instance data system.
        void LoadCouncilGUIDs()
        {
            if (InstanceScript* instance = me->GetInstanceScript())
            {
                Council[0] = instance->GetData64(DATA_GATHIOS_THE_SHATTERER);
                Council[1] = instance->GetData64(DATA_VERAS_DARKSHADOW);
                Council[2] = instance->GetData64(DATA_LADY_MALANDE);
                Council[3] = instance->GetData64(DATA_HIGH_NETHERMANCER_ZEREVOR);
            } else TC_LOG_ERROR("scripts", ERROR_INST_DATA);
        }

        void EnterCombat(Unit* /*who*/) override { }

        void AttackStart(Unit* /*who*/) override { }
        void MoveInLineOfSight(Unit* /*who*/) override { }


        void UpdateAI(uint32 diff) override
        {
            if (!EventStarted)
                return;

            if (YellCounter > 3)
                return;

            if (AggroYellTimer)
            {
                if (AggroYellTimer <= diff)
            {
                if (Creature* pMember = ObjectAccessor::GetCreature(*me, Council[YellCounter]))
                {
                    pMember->AI()->Talk(CouncilAggro[YellCounter].entry);
                    AggroYellTimer = CouncilAggro[YellCounter].timer;
                }
                ++YellCounter;
                if (YellCounter > 3)
                    YellCounter = 0;                            // Reuse for Enrage Yells
            } else AggroYellTimer -= diff;
            }

            if (EnrageTimer)
            {
                if (EnrageTimer <= diff)
            {
                if (Creature* pMember = ObjectAccessor::GetCreature(*me, Council[YellCounter]))
                {
                    pMember->CastSpell(pMember, SPELL_BERSERK, true);
                    pMember->AI()->Talk(CouncilEnrage[YellCounter].entry);
                    EnrageTimer = CouncilEnrage[YellCounter].timer;
                }
                ++YellCounter;
            } else EnrageTimer -= diff;
            }
        }
    };

};

class npc_illidari_council : public CreatureScript
{
public:
    npc_illidari_council() : CreatureScript("npc_illidari_council") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_illidari_councilAI>(creature);
    }

    struct npc_illidari_councilAI : public ScriptedAI
    {
        npc_illidari_councilAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            for (uint8 i = 0; i < 4; ++i)
                Council[i] = 0;
        }

        InstanceScript* instance;

        uint64 Council[4];

        uint32 CheckTimer;
        uint32 EndEventTimer;

        uint8 DeathCount;

        bool EventBegun;

        void Reset() override
        {
            CheckTimer    = 2000;
            EndEventTimer = 0;

            DeathCount = 0;

            Creature* pMember = NULL;
            for (uint8 i = 0; i < 4; ++i)
            {
                pMember = ObjectAccessor::GetCreature((*me), Council[i]);
                if (!pMember)
                    continue;

                if (!pMember->IsAlive())
                {
                    pMember->RemoveCorpse();
                    pMember->Respawn();
                }
                pMember->AI()->EnterEvadeMode();
            }

            instance->SetBossState(DATA_ILLIDARI_COUNCIL, NOT_STARTED);
            if (Creature* VoiceTrigger = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_BLOOD_ELF_COUNCIL_VOICE)))
                VoiceTrigger->AI()->EnterEvadeMode();

            EventBegun = false;

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetDisplayId(11686);
        }

        void EnterCombat(Unit* /*who*/) override { }
        void AttackStart(Unit* /*who*/) override { }
        void MoveInLineOfSight(Unit* /*who*/) override { }


        void StartEvent(Unit* target)
        {
            if (target && target->IsAlive())
            {
                Council[0] = instance->GetData64(DATA_GATHIOS_THE_SHATTERER);
                Council[1] = instance->GetData64(DATA_HIGH_NETHERMANCER_ZEREVOR);
                Council[2] = instance->GetData64(DATA_LADY_MALANDE);
                Council[3] = instance->GetData64(DATA_VERAS_DARKSHADOW);

                // Start the event for the Voice Trigger
                if (Creature* VoiceTrigger = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_BLOOD_ELF_COUNCIL_VOICE)))
                {
                    CAST_AI(npc_blood_elf_council_voice_trigger::npc_blood_elf_council_voice_triggerAI, VoiceTrigger->AI())->LoadCouncilGUIDs();
                    CAST_AI(npc_blood_elf_council_voice_trigger::npc_blood_elf_council_voice_triggerAI, VoiceTrigger->AI())->EventStarted = true;
                }

                for (uint8 i = 0; i < 4; ++i)
                {
                    if (Council[i])
                    {
                        if (Creature* member = ObjectAccessor::GetCreature(*me, Council[i]))
                            if (member->IsAlive())
                                member->AI()->AttackStart(target);
                    }
                }

                instance->SetBossState(DATA_ILLIDARI_COUNCIL, IN_PROGRESS);

                EventBegun = true;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!EventBegun)
                return;

            if (EndEventTimer)
            {
                if (EndEventTimer <= diff)
                {
                    if (DeathCount > 3)
                    {
                        if (Creature* VoiceTrigger = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_BLOOD_ELF_COUNCIL_VOICE)))
                            VoiceTrigger->DealDamage(VoiceTrigger, VoiceTrigger->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                        instance->SetBossState(DATA_ILLIDARI_COUNCIL, DONE);
                        //me->SummonCreature(AKAMAID, 746.466980f, 304.394989f, 311.90208f, 6.272870f, TEMPSUMMON_DEAD_DESPAWN, 0);
                        me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                        return;
                    }

                    Creature* pMember = (ObjectAccessor::GetCreature(*me, Council[DeathCount]));
                    if (pMember && pMember->IsAlive())
                        pMember->DealDamage(pMember, pMember->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                    ++DeathCount;
                    EndEventTimer = 1500;
                } else EndEventTimer -= diff;
            }

            if (CheckTimer)
            {
                if (CheckTimer <= diff)
                {
                    uint8 EvadeCheck = 0;
                    for (uint8 i = 0; i < 4; ++i)
                    {
                        if (Council[i])
                        {
                            if (Creature* Member = (ObjectAccessor::GetCreature((*me), Council[i])))
                            {
                                // This is the evade/death check.
                                if (Member->IsAlive() && !Member->GetVictim())
                                    ++EvadeCheck;                   //If all members evade, we reset so that players can properly reset the event
                                else if (!Member->IsAlive())         // If even one member dies, kill the rest, set instance data, and kill self.
                                {
                                    EndEventTimer = 1000;
                                    CheckTimer = 0;
                                    return;
                                }
                            }
                        }
                    }

                    if (EvadeCheck > 3)
                        Reset();

                    CheckTimer = 2000;
                } else CheckTimer -= diff;
            }

        }
    };

};

struct boss_illidari_councilAI : public ScriptedAI
{
    boss_illidari_councilAI(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
        for (uint8 i = 0; i < 4; ++i)
            Council[i] = 0;
        LoadedGUIDs = false;
    }

    uint64 Council[4];

    InstanceScript* instance;

    bool LoadedGUIDs;

    void EnterCombat(Unit* who) override
    {
        if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_ILLIDARI_COUNCIL)))
            CAST_AI(npc_illidari_council::npc_illidari_councilAI, controller->AI())->StartEvent(who);
        DoZoneInCombat();
        // Load GUIDs on first aggro because the Creature guids are only set as the creatures are created in world-
        // this means that for each creature, it will attempt to LoadGUIDs even though some of the other creatures are
        // not in world, and thus have no GUID set in the instance data system. Putting it in aggro ensures that all the creatures
        // have been loaded and have their GUIDs set in the instance data system.
        if (!LoadedGUIDs)
            LoadGUIDs();
    }

    void EnterEvadeMode() override
    {
        for (uint8 i = 0; i < 4; ++i)
        {
            if (Unit* unit = ObjectAccessor::GetUnit(*me, Council[i]))
                if (unit != me && unit->GetVictim())
                {
                    AttackStart(unit->GetVictim());
                    return;
                }
        }
        ScriptedAI::EnterEvadeMode();
    }

    void DamageTaken(Unit* done_by, uint32 &damage) override
    {
        if (done_by == me)
            return;

        damage /= 4;
        for (uint8 i = 0; i < 4; ++i)
        {
            if (Creature* unit = ObjectAccessor::GetCreature(*me, Council[i]))
                if (unit != me && damage < unit->GetHealth())
                {
                    unit->ModifyHealth(-int32(damage));
                    unit->LowerPlayerDamageReq(damage);
                }
        }
    }

    void LoadGUIDs()
    {
        Council[0] = instance->GetData64(DATA_LADY_MALANDE);
        Council[1] = instance->GetData64(DATA_HIGH_NETHERMANCER_ZEREVOR);
        Council[2] = instance->GetData64(DATA_GATHIOS_THE_SHATTERER);
        Council[3] = instance->GetData64(DATA_VERAS_DARKSHADOW);

        LoadedGUIDs = true;
    }
};

class boss_gathios_the_shatterer : public CreatureScript
{
public:
    boss_gathios_the_shatterer() : CreatureScript("boss_gathios_the_shatterer") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_gathios_the_shattererAI>(creature);
    }

    struct boss_gathios_the_shattererAI : public boss_illidari_councilAI
    {
        boss_gathios_the_shattererAI(Creature* creature) : boss_illidari_councilAI(creature) { }

        uint32 ConsecrationTimer;
        uint32 HammerOfJusticeTimer;
        uint32 SealTimer;
        uint32 AuraTimer;
        uint32 BlessingTimer;

        void Reset() override
        {
            ConsecrationTimer = 40000;
            HammerOfJusticeTimer = 10000;
            SealTimer = 40000;
            AuraTimer = 90000;
            BlessingTimer = 60000;
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_GATH_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_GATH_DEATH);
        }

        Unit* SelectCouncilMember()
        {
            Unit* unit = me;
            uint32 member = 0;                                  // He chooses Lady Malande most often

            if (rand()%10 == 0)                                  // But there is a chance he picks someone else.
                member = urand(1, 3);

            if (member != 2)                                     // No need to create another pointer to us using Unit::GetUnit
                unit = ObjectAccessor::GetUnit(*me, Council[member]);
            return unit;
        }

        void CastAuraOnCouncil()
        {
            uint32 spellid = 0;
            switch (urand(0, 1))
            {
                case 0: spellid = SPELL_DEVOTION_AURA;   break;
                case 1: spellid = SPELL_CHROMATIC_AURA;  break;
            }
            for (uint8 i = 0; i < 4; ++i)
            {
                Unit* unit = ObjectAccessor::GetUnit(*me, Council[i]);
                if (unit)
                    unit->CastSpell(unit, spellid, true, 0, 0, me->GetGUID());
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (BlessingTimer <= diff)
            {
                if (Unit* unit = SelectCouncilMember())
                {
                    switch (urand(0, 1))
                    {
                        case 0:
                            DoCast(unit, SPELL_BLESS_SPELLWARD);
                            break;

                        case 1:
                            DoCast(unit, SPELL_BLESS_PROTECTION);
                            break;
                    }
                }
                BlessingTimer = 60000;
            } else BlessingTimer -= diff;

            if (ConsecrationTimer <= diff)
            {
                DoCast(me, SPELL_CONSECRATION);
                ConsecrationTimer = 40000;
            } else ConsecrationTimer -= diff;

            if (HammerOfJusticeTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    // is in ~10-40 yd range
                    if (me->IsInRange(target, 10.0f, 40.0f, false))
                    {
                        DoCast(target, SPELL_HAMMER_OF_JUSTICE);
                        HammerOfJusticeTimer = 20000;
                    }
                }
            } else HammerOfJusticeTimer -= diff;

            if (SealTimer <= diff)
            {
                switch (urand(0, 1))
                {
                    case 0: DoCast(me, SPELL_SEAL_OF_COMMAND);  break;
                    case 1: DoCast(me, SPELL_SEAL_OF_BLOOD);    break;
                }
                SealTimer = 40000;
            } else SealTimer -= diff;

            if (AuraTimer <= diff)
            {
                CastAuraOnCouncil();
                AuraTimer = 90000;
            } else AuraTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class boss_high_nethermancer_zerevor : public CreatureScript
{
public:
    boss_high_nethermancer_zerevor() : CreatureScript("boss_high_nethermancer_zerevor") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_high_nethermancer_zerevorAI>(creature);
    }

    struct boss_high_nethermancer_zerevorAI : public boss_illidari_councilAI
    {
        boss_high_nethermancer_zerevorAI(Creature* creature) : boss_illidari_councilAI(creature) { }

        uint32 BlizzardTimer;
        uint32 FlamestrikeTimer;
        uint32 ArcaneBoltTimer;
        uint32 DampenMagicTimer;
        uint32 Cooldown;
        uint32 ArcaneExplosionTimer;

        void Reset() override
        {
            BlizzardTimer = urand(30, 91) * 1000;
            FlamestrikeTimer = urand(30, 91) * 1000;
            ArcaneBoltTimer = 10000;
            DampenMagicTimer = 2000;
            ArcaneExplosionTimer = 14000;
            Cooldown = 0;
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_ZERE_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_ZERE_DEATH);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (Cooldown)
            {
                if (Cooldown <= diff) Cooldown = 0;
                else
                {
                    Cooldown -= diff;
                    return;                                     // Don't cast any other spells if global cooldown is still ticking
                }
            }

            if (DampenMagicTimer <= diff)
            {
                DoCast(me, SPELL_DAMPEN_MAGIC);
                Cooldown = 1000;
                DampenMagicTimer = 67200;                      // almost 1, 12 minutes
                ArcaneBoltTimer += 1000;                        // Give the Mage some time to spellsteal Dampen.
            } else DampenMagicTimer -= diff;

            if (ArcaneExplosionTimer <= diff)
            {
                DoCastVictim(SPELL_ARCANE_EXPLOSION);
                Cooldown = 1000;
                ArcaneExplosionTimer = 14000;
            } else ArcaneExplosionTimer -= diff;

            if (ArcaneBoltTimer <= diff)
            {
                DoCastVictim(SPELL_ARCANE_BOLT);
                ArcaneBoltTimer = 3000;
                Cooldown = 2000;
            } else ArcaneBoltTimer -= diff;

            if (BlizzardTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    DoCast(target, SPELL_BLIZZARD);
                    BlizzardTimer = urand(45, 91) * 1000;
                    FlamestrikeTimer += 10000;
                    Cooldown = 1000;
                }
            } else BlizzardTimer -= diff;

            if (FlamestrikeTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    DoCast(target, SPELL_FLAMESTRIKE);
                    FlamestrikeTimer = urand(55, 101) * 1000;
                    BlizzardTimer += 10000;
                    Cooldown = 2000;
                }
            } else FlamestrikeTimer -= diff;
        }
    };

};

class boss_lady_malande : public CreatureScript
{
public:
    boss_lady_malande() : CreatureScript("boss_lady_malande") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_lady_malandeAI>(creature);
    }

    struct boss_lady_malandeAI : public boss_illidari_councilAI
    {
        boss_lady_malandeAI(Creature* creature) : boss_illidari_councilAI(creature) { }

        uint32 EmpoweredSmiteTimer;
        uint32 CircleOfHealingTimer;
        uint32 DivineWrathTimer;
        uint32 ReflectiveShieldTimer;

        void Reset() override
        {
            EmpoweredSmiteTimer = 38000;
            CircleOfHealingTimer = 20000;
            DivineWrathTimer = 40000;
            ReflectiveShieldTimer = 0;
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_MALA_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_MALA_DEATH);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (EmpoweredSmiteTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    DoCast(target, SPELL_EMPOWERED_SMITE);
                    EmpoweredSmiteTimer = 38000;
                }
            } else EmpoweredSmiteTimer -= diff;

            if (CircleOfHealingTimer <= diff)
            {
                DoCast(me, SPELL_CIRCLE_OF_HEALING);
                CircleOfHealingTimer = 60000;
            } else CircleOfHealingTimer -= diff;

            if (DivineWrathTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    DoCast(target, SPELL_DIVINE_WRATH);
                    DivineWrathTimer = urand(40, 81) * 1000;
                }
            } else DivineWrathTimer -= diff;

            if (ReflectiveShieldTimer <= diff)
            {
                DoCast(me, SPELL_REFLECTIVE_SHIELD);
                ReflectiveShieldTimer = 65000;
            } else ReflectiveShieldTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class boss_veras_darkshadow : public CreatureScript
{
public:
    boss_veras_darkshadow() : CreatureScript("boss_veras_darkshadow") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_veras_darkshadowAI>(creature);
    }

    struct boss_veras_darkshadowAI : public boss_illidari_councilAI
    {
        boss_veras_darkshadowAI(Creature* creature) : boss_illidari_councilAI(creature) { }

        uint64 EnvenomTargetGUID;

        uint32 DeadlyPoisonTimer;
        uint32 VanishTimer;
        uint32 AppearEnvenomTimer;

        bool HasVanished;

        void Reset() override
        {
            EnvenomTargetGUID = 0;

            DeadlyPoisonTimer = 20000;
            VanishTimer = urand(60, 121) * 1000;
            AppearEnvenomTimer = 150000;

            HasVanished = false;
            me->SetVisible(true);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_VERA_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_VERA_DEATH);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (!HasVanished)
            {
                if (DeadlyPoisonTimer <= diff)
                {
                    DoCastVictim(SPELL_DEADLY_POISON);
                    DeadlyPoisonTimer = urand(15, 46) * 1000;
                } else DeadlyPoisonTimer -= diff;

                if (AppearEnvenomTimer <= diff)                   // Cast Envenom. This is cast 4 seconds after Vanish is over
                {
                    DoCastVictim(SPELL_ENVENOM);
                    AppearEnvenomTimer = 90000;
                } else AppearEnvenomTimer -= diff;

                if (VanishTimer <= diff)                          // Disappear and stop attacking, but follow a random unit
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        VanishTimer = 30000;
                        AppearEnvenomTimer= 28000;
                        HasVanished = true;
                        me->SetVisible(false);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        DoResetThreat();
                                                                // Chase a unit. Check before DoMeleeAttackIfReady prevents from attacking
                        me->AddThreat(target, 500000.0f);
                        me->GetMotionMaster()->MoveChase(target);
                    }
                } else VanishTimer -= diff;

                DoMeleeAttackIfReady();
            }
            else
            {
                if (VanishTimer <= diff)                          // Become attackable and poison current target
                {
                    Unit* target = me->GetVictim();
                    DoCast(target, SPELL_DEADLY_POISON);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    DoResetThreat();
                    me->AddThreat(target, 3000.0f);      // Make Veras attack his target for a while, he will cast Envenom 4 seconds after.
                    DeadlyPoisonTimer += 6000;
                    VanishTimer = 90000;
                    AppearEnvenomTimer = 4000;
                    HasVanished = false;
                } else VanishTimer -= diff;

                if (AppearEnvenomTimer <= diff)                   // Appear 2 seconds before becoming attackable (Shifting out of vanish)
                {
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveChase(me->GetVictim());
                    me->SetVisible(true);
                    AppearEnvenomTimer = 6000;
                } else AppearEnvenomTimer -= diff;
            }
        }
    };
};

// SPELL_REFLECTIVE_SHIELD
class spell_boss_lady_malande_shield : public SpellScriptLoader
{
public:
    spell_boss_lady_malande_shield() : SpellScriptLoader("spell_boss_lady_malande_shield") { }

    class spell_boss_lady_malande_shield_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_boss_lady_malande_shield_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return sSpellMgr->GetSpellInfo(SPELL_REFLECTIVE_SHIELD_T);
        }

        void Trigger(AuraEffect* aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount)
        {
            Unit* target = GetTarget();
            if (dmgInfo.GetAttacker() == target)
                return;
            int32 bp = absorbAmount / 2;
            target->CastCustomSpell(dmgInfo.GetAttacker(), SPELL_REFLECTIVE_SHIELD_T, &bp, NULL, NULL, true, NULL, aurEff);
        }

        void Register() override
        {
             AfterEffectAbsorb += AuraEffectAbsorbFn(spell_boss_lady_malande_shield_AuraScript::Trigger, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_boss_lady_malande_shield_AuraScript();
    }
};

void AddSC_boss_illidari_council()
{
    new npc_illidari_council();
    new npc_blood_elf_council_voice_trigger();
    new boss_gathios_the_shatterer();
    new boss_lady_malande();
    new boss_veras_darkshadow();
    new boss_high_nethermancer_zerevor();
    new spell_boss_lady_malande_shield();
}
