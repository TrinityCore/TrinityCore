/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Boss_Warlord_Najentus
SD%Complete: 90
SDComment: Using a creature workaround instead of a GO for Impaling Spine.
SDCategory: Black Temple
EndScriptData */

#include "precompiled.h"
#include "def_black_temple.h"

//Aggro
#define SAY_AGGRO       "You will die, in the name of Lady Vashj!"
#define SOUND_AGGRO     11450

//Needle (Random)
#define SAY_NEEDLE1     "Stick around!"
#define SOUND_NEEDLE1   11451

#define SAY_NEEDLE2     "I'll deal with you later!"
#define SOUND_NEEDLE2   11452

//Slay
#define SAY_SLAY1       "Your success was short lived!"
#define SOUND_SLAY1     11455

#define SAY_SLAY2       "Time for you to go!"
#define SOUND_SLAY2     11456

//Special
#define SAY_SPECIAL1    "Bel'anen dal'lorei!"
#define SOUND_SPECIAL1  11453

#define SAY_SPECIAL2    "Blood will flow!"
#define SOUND_SPECIAL2  11454

//Enrage
#define SAY_ENRAGE      "My patience has ran out! Die, DIE!"
#define SOUND_ENRAGE    11458

//Death
#define SAY_DEATH       "Lord Illidan will... crush you."
#define SOUND_DEATH     11459

//Spells
#define SPELL_CRASHINGWAVE             40100
#define SPELL_NEEDLE_SPINE             39835
#define SPELL_NEEDLE_AOE               39968
#define SPELL_TIDAL_BURST              39878
#define SPELL_TIDAL_SHIELD             39872                // Not going to use this since Hurl Spine doesn't dispel it.
#define SPELL_IMPALING_SPINE           39837
#define SPELL_CREATE_NAJENTUS_SPINE    39956
#define SPELL_HURL_SPINE               39948
#define SPELL_SHIELD_VISUAL            37136
#define SPELL_BERSERK                  45078

#define DISPLAYID_SPINE         7362

struct TRINITY_DLL_DECL mob_najentus_spineAI : public ScriptedAI
{
    mob_najentus_spineAI(Creature *c) : ScriptedAI(c)
    {
        Reset();
    }

    uint64 SpineVictimGUID;

    void Reset() {  SpineVictimGUID = 0; }

    void SetSpineVictimGUID(uint64 guid){ SpineVictimGUID = guid; }

    void JustDied(Unit *killer)
    {
        // Make the killer have the Najentus Spine item to pierce Tidal Shield
        if(killer)
            killer->CastSpell(killer, SPELL_CREATE_NAJENTUS_SPINE, true);
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if(damage < m_creature->GetHealth()) return;

        // Remove the Impaling Spine DoT from whoever was affected
        if(SpineVictimGUID)
        {
            Unit* victim = Unit::GetUnit((*m_creature), SpineVictimGUID);
            if(victim && ((victim->HasAura(SPELL_IMPALING_SPINE, 0)) || (victim->HasAura(SPELL_IMPALING_SPINE, 1)) || (victim->HasAura(SPELL_IMPALING_SPINE, 2))))
                victim->RemoveAurasDueToSpell(SPELL_IMPALING_SPINE);
        }
    }

    void Aggro(Unit* who) {}
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff) {}
};

struct TRINITY_DLL_DECL boss_najentusAI : public ScriptedAI
{
    boss_najentusAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance* pInstance;
    uint32 CrashingWaveTimer;
    uint32 NeedleSpineTimer;
    uint32 EnrageTimer;
    uint32 SpecialYellTimer;
    uint32 TidalShieldTimer;
    uint32 ImpalingSpineTimer;
    uint32 CheckTimer;                                      // This timer checks if Najentus is Tidal Shielded and if so, regens health. If not, sets IsShielded to false
    uint32 DispelShieldTimer;                               // This shield is only supposed to last 30 seconds, but the SPELL_SHIELD_VISUAL lasts forever

    uint64 SpineTargetGUID;
    uint64 SpineGUID;

    bool IsShielded;

    void Reset()
    {
        IsShielded = false;

        CrashingWaveTimer = 28000;
        NeedleSpineTimer = 10000;
        EnrageTimer = 480000;
        SpecialYellTimer = 45000 + (rand()%76)*1000;
        TidalShieldTimer = 60000;
        ImpalingSpineTimer = 45000;
        CheckTimer = 2000;
        DispelShieldTimer = 30000;

        SpineTargetGUID = 0;
        SpineGUID = 0;

        if(pInstance)
        {
            if(m_creature->isAlive())
            {
                pInstance->SetData(DATA_HIGHWARLORDNAJENTUSEVENT, NOT_STARTED);
                ToggleGate(true);
            }
            else  ToggleGate(false);
        }
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
            case 0:
                DoYell(SAY_SLAY1,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, SOUND_SLAY1);
                break;
            case 1:
                DoYell(SAY_SLAY2,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, SOUND_SLAY2);
                break;
        }
    }

    void JustDied(Unit *victim)
    {
        if(pInstance)
        {
            pInstance->SetData(DATA_HIGHWARLORDNAJENTUSEVENT, DONE);
            ToggleGate(false);
        }

        DoYell(SAY_DEATH, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature,SOUND_DEATH);
    }

    void ToggleGate(bool close)
    {
        if(GameObject* Gate = GameObject::GetGameObject(*m_creature, pInstance->GetData64(DATA_GAMEOBJECT_NAJENTUS_GATE)))
            if(close)   Gate->SetGoState(0);                // Closed
        else        Gate->SetGoState(2);                    // Opened
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if(IsShielded)
        {
            if(spell->Id == SPELL_HURL_SPINE)
            {
                if(m_creature->HasAura(SPELL_SHIELD_VISUAL, 0))
                    m_creature->RemoveAurasDueToSpell(SPELL_SHIELD_VISUAL);
                if(m_creature->HasAura(SPELL_TIDAL_SHIELD, 0))
                    m_creature->RemoveAurasDueToSpell(SPELL_TIDAL_SHIELD);
                DoCast(m_creature->getVictim(), SPELL_TIDAL_BURST);
                IsShielded = false;
            }
        }
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if(IsShielded)
            damage = 0;
    }

    void Aggro(Unit *who)
    {
        if(pInstance)
            pInstance->SetData(DATA_HIGHWARLORDNAJENTUSEVENT, IN_PROGRESS);

        DoYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_AGGRO);

        DoZoneInCombat();
    }

    // This is a workaround since we cannot summon GameObjects at will.
    // Instead, we create a custom creature on top of the player.
    // When someone kills the creature, the killer gets the "Naj'entus Spine" item.
    // This item is the only item that should be able to pierce Tidal Shield
    void DoImpalingSpineWorkaround(Unit* target)
    {
        Creature* Spine = NULL;
        Spine = m_creature->SummonCreature(500000, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_DEAD_DESPAWN, 10000);
        if(Spine)
        {
            Spine->setFaction(m_creature->getFaction());
            ((mob_najentus_spineAI*)Spine->AI())->SetSpineVictimGUID(target->GetGUID());
            SpineTargetGUID = target->GetGUID();
        }
    }

    bool RemoveImpalingSpine(uint64 guid)
    {
        if(!IsShielded || guid == SpineTargetGUID) return false;

        if(SpineTargetGUID)
        {
            Unit* target = Unit::GetUnit((*m_creature), SpineTargetGUID);
            if(target && target->HasAura(SPELL_IMPALING_SPINE, 0))
            {
                target->RemoveAurasDueToSpell(SPELL_IMPALING_SPINE);
                return true;
            }
        }

        return false;
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if(CheckTimer < diff)
        {
            // if(m_creature->HasAura(SPELL_TIDAL_SHIELD, 0))
            if(m_creature->HasAura(SPELL_SHIELD_VISUAL, 0))
                m_creature->SetHealth(m_creature->GetHealth() + (m_creature->GetMaxHealth()/100));
            else
                IsShielded = false;

            CheckTimer = 2000;
        }else CheckTimer -= diff;

        if(IsShielded)
        {
            m_creature->GetMotionMaster()->Clear(false);
            m_creature->GetMotionMaster()->MoveIdle();
            if(!m_creature->HasAura(SPELL_SHIELD_VISUAL, 0))
                DoCast(m_creature, SPELL_SHIELD_VISUAL);
            if(DispelShieldTimer < diff)
            {
                m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
                if(m_creature->HasAura(SPELL_SHIELD_VISUAL, 0))
                    m_creature->RemoveAurasDueToSpell(SPELL_SHIELD_VISUAL);
                IsShielded = false;
            }else DispelShieldTimer -= diff;

            return;                                         // Don't cast or do anything while Shielded
        }

        // Crashing Wave
        if(CrashingWaveTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_CRASHINGWAVE);
            CrashingWaveTimer = 28500;
        }else CrashingWaveTimer -= diff;

        if(!m_creature->HasAura(SPELL_BERSERK, 0))
            if(EnrageTimer < diff)
        {
            DoYell(SAY_ENRAGE, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_ENRAGE);
            DoCast(m_creature, SPELL_BERSERK);
        }else EnrageTimer -= diff;

        // Needle
        if(NeedleSpineTimer < diff)
        {
            for(uint8 i = 0; i < 3; ++i)
            {
                Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1);
                if(!target)
                    target = m_creature->getVictim();

                DoCast(target, SPELL_NEEDLE_AOE, true);
                DoCast(target, SPELL_NEEDLE_SPINE);
            }

            NeedleSpineTimer = 60000;
        }else NeedleSpineTimer -= diff;

        if(SpecialYellTimer < diff)
        {
            switch(rand()%2)
            {
                case 0:
                    DoPlaySoundToSet(m_creature, SOUND_SPECIAL1);
                    break;
                case 1:
                    DoYell(SAY_SPECIAL2, LANG_UNIVERSAL, NULL);
                    DoPlaySoundToSet(m_creature, SOUND_SPECIAL2);
                    break;
            }
            SpecialYellTimer = 25000 + (rand()%76)*1000;
        }else SpecialYellTimer -= diff;

        if(ImpalingSpineTimer < diff)
        {
            Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1);
            if(!target)
                target = m_creature->getVictim();

            if(target && (target->GetTypeId() == TYPEID_PLAYER))
            {
                DoCast(target, SPELL_IMPALING_SPINE);
                //DoImpalingSpineWorkaround(target);
                SpineTargetGUID = target->GetGUID();
                ImpalingSpineTimer = 45000;

                switch(rand()%2)
                {
                    case 0:
                        DoYell(SAY_NEEDLE1, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(m_creature, SOUND_NEEDLE1);
                        break;
                    case 1:
                        DoYell(SAY_NEEDLE2, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(m_creature, SOUND_NEEDLE2);
                        break;
                }
            }
        }else ImpalingSpineTimer -= diff;

        if(TidalShieldTimer < diff)
        {
            m_creature->InterruptNonMeleeSpells(false);
            DoCast(m_creature, SPELL_SHIELD_VISUAL, true);
            // DoCast(m_creature, SPELL_TIDAL_SHIELD);
            m_creature->GetMotionMaster()->Clear(false);
            m_creature->GetMotionMaster()->MoveIdle();
            IsShielded = true;
            TidalShieldTimer = 60000;
            CheckTimer = 2000;
            DispelShieldTimer = 30000;
        }else TidalShieldTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

bool GOHello_go_najentus_spine(Player *player, GameObject* _GO)
{
    ScriptedInstance* pInstance = ((ScriptedInstance*)_GO->GetInstanceData());
    if(pInstance)
    {
        uint64 NajentusGUID = pInstance->GetData64(DATA_HIGHWARLORDNAJENTUS);
        if(NajentusGUID)
        {
            Creature* Najentus = ((Creature*)Unit::GetUnit((*_GO), NajentusGUID));
            if(Najentus)
            {
                if(((boss_najentusAI*)Najentus->AI())->RemoveImpalingSpine(player->GetGUID()))
                    return true;
            }else error_log("ERROR: Na'entus Spine GameObject unable to find Naj'entus");
        }else error_log("ERROR: Invalid GUID acquired for Naj'entus by Naj'entus Spine GameObject");
    }
    else error_log("ERROR: Naj'entus Spine spawned in invalid instance or location");

    return true;
}

CreatureAI* GetAI_mob_najentus_spine(Creature *_Creature)
{
    return new mob_najentus_spineAI (_Creature);
}

CreatureAI* GetAI_boss_najentus(Creature *_Creature)
{
    return new boss_najentusAI (_Creature);
}

void AddSC_boss_najentus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_najentus";
    newscript->GetAI = GetAI_boss_najentus;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name = "mob_najentus_spine";
    newscript->GetAI = GetAI_mob_najentus_spine;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name = "go_najentus_spine";
    newscript->pGOHello = &GOHello_go_najentus_spine;
    m_scripts[nrscripts++] = newscript;
}
