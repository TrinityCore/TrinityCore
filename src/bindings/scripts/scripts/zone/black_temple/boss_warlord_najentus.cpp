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
SD%Complete: 95
SDComment:
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
#define SPELL_NEEDLE_SPINE             39835
#define SPELL_NEEDLE_AOE               39968
#define SPELL_TIDAL_BURST              39878
#define SPELL_TIDAL_SHIELD             39872
#define SPELL_IMPALING_SPINE           39837
#define SPELL_CREATE_NAJENTUS_SPINE    39956
#define SPELL_HURL_SPINE               39948
#define SPELL_BERSERK                  45078

#define GOBJECT_SPINE                  185584

struct TRINITY_DLL_DECL boss_najentusAI : public ScriptedAI
{
    boss_najentusAI(Creature *c) : ScriptedAI(c) 
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance* pInstance;

    uint32 NeedleSpineTimer;
    uint32 EnrageTimer;
    uint32 SpecialYellTimer;
    uint32 TidalShieldTimer;
    uint32 ImpalingSpineTimer;

    uint64 SpineTargetGUID;

    void Reset()
    {
        EnrageTimer = 480000;
        SpecialYellTimer = 45000 + (rand()%76)*1000;

        ResetTimer();

        SpineTargetGUID = 0;

        if(pInstance)
            pInstance->SetData(DATA_HIGHWARLORDNAJENTUSEVENT, NOT_STARTED);
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
            pInstance->SetData(DATA_HIGHWARLORDNAJENTUSEVENT, DONE);

        DoYell(SAY_DEATH, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature,SOUND_DEATH);
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if(spell->Id == SPELL_HURL_SPINE && m_creature->HasAura(SPELL_TIDAL_SHIELD, 0))
        {
            m_creature->RemoveAurasDueToSpell(SPELL_TIDAL_SHIELD);
            m_creature->CastSpell(m_creature, SPELL_TIDAL_BURST, true);
            ResetTimer();
        }
    }

    void Aggro(Unit *who)
    {
        if(pInstance)
            pInstance->SetData(DATA_HIGHWARLORDNAJENTUSEVENT, IN_PROGRESS);

        DoYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_AGGRO);
        DoZoneInCombat();
    }

    bool RemoveImpalingSpine()
    {
        if(!SpineTargetGUID) return false;
        Unit* target = Unit::GetUnit(*m_creature, SpineTargetGUID);
        if(target && target->HasAura(SPELL_IMPALING_SPINE, 1))
            target->RemoveAurasDueToSpell(SPELL_IMPALING_SPINE);
        SpineTargetGUID=0;
        return true;
    }

    void ResetTimer(uint32 inc = 0)
    {
        NeedleSpineTimer = 10000 + inc;
        TidalShieldTimer = 60000 + inc;
        ImpalingSpineTimer = 20000 + inc;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if(TidalShieldTimer < diff)
        {
            m_creature->InterruptNonMeleeSpells(false);
            DoCast(m_creature, SPELL_TIDAL_SHIELD, true);
            ResetTimer(45000);
        }else TidalShieldTimer -= diff;

        if(EnrageTimer < diff)
        {
            DoYell(SAY_ENRAGE, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_ENRAGE);
            m_creature->CastSpell(m_creature, SPELL_BERSERK, true);
            EnrageTimer = 600000;
        }else EnrageTimer -= diff;

        // Needle
        if(NeedleSpineTimer < diff)
        {
            for(uint8 i = 0; i < 3; ++i)
            {
                Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1);
                if(!target) target = m_creature->getVictim();
                m_creature->CastSpell(target, SPELL_NEEDLE_SPINE, true);
            }
            m_creature->SetInFront(m_creature->getVictim());
            NeedleSpineTimer = 30000;
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
            if(!target) target = m_creature->getVictim();
            m_creature->CastSpell(target, SPELL_IMPALING_SPINE, true);
            m_creature->SetInFront(m_creature->getVictim());
            SpineTargetGUID = target->GetGUID();
            m_creature->SummonGameObject(GOBJECT_SPINE, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), m_creature->GetOrientation(), 0, 0, 0, 0, 30);

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
            ImpalingSpineTimer = 21000;
        }else ImpalingSpineTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

bool GOHello_go_najentus_spine(Player *player, GameObject* _GO)
{
    if(ScriptedInstance* pInstance = (ScriptedInstance*)_GO->GetInstanceData())
        if(Creature* Najentus = (Creature*)Unit::GetUnit(*_GO, pInstance->GetData64(DATA_HIGHWARLORDNAJENTUS)))
            if(((boss_najentusAI*)Najentus->AI())->RemoveImpalingSpine())
            {
                player->CastSpell(player, SPELL_CREATE_NAJENTUS_SPINE, true);
                _GO->SetLootState(GO_NOT_READY);
                _GO->SetRespawnTime(0);
            }
    return true;
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
    newscript->Name = "go_najentus_spine";
    newscript->pGOHello = &GOHello_go_najentus_spine;
    m_scripts[nrscripts++] = newscript;
}
