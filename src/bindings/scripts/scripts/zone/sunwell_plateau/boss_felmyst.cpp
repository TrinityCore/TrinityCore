/* Copyright ?2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Felmyst
SD%Complete: 0
SDComment:
EndScriptData */

#include "precompiled.h"
#include "def_sunwell_plateau.h"
#include "Player.h"

// AURA
#define AURA_SUNWELL_RADIANCE           45769
#define AURA_NOXIOUS_FUMES              47002
// LAND PHASE SPELL
#define SPELL_CLEAVE                    19983
#define SPELL_CORROSION                 45866
#define SPELL_GAS_NOVA                  45855
#define SPELL_ENCAPSULATE_CHANNEL       45661
#define SPELL_ENCAPSULATE_EFFECT        45665
#define SPELL_ENCAPSULATE_AOE           45662
// FLIGHT PHASE SPELL
#define SPELL_VAPOR_SELECT      45391   // fel to player, force cast 45392, 50000y selete target
#define SPELL_VAPOR_SUMMON      45392   // player summon vapor, radius around caster, 5y,
#define SPELL_VAPOR_FORCE       45388   // vapor to fel, force cast 45389
#define SPELL_VAPOR_CHANNEL     45389   // fel to vapor, green beam channel
#define SPELL_VAPOR_TRIGGER     45411   // linked to 45389, vapor to self, trigger 45410 and 46931
#define SPELL_VAPOR_DAMAGE      46931   // vapor damage, 4000
#define SPELL_TRAIL_SUMMON      45410   // vapor summon trail
#define SPELL_TRAIL_TRIGGER     45399   // trail to self, trigger 45402
#define SPELL_TRAIL_DAMAGE      45402   // trail damage, 2000 + 2000 dot
#define SPELL_DEAD_SUMMON       45400   // summon blazing dead, 5min
#define SPELL_DEAD_PASSIVE      45415
#define SPELL_FOG_BREATH        45495   // fel to self, speed burst
#define SPELL_FOG_TRIGGER       45582   // fog to self, trigger 45782
#define SPELL_FOG_FORCE         45782   // fog to player, force cast 45714
#define SPELL_FOG_INFORM        45714   // player let fel cast 45717, script effect
#define SPELL_FOG_CHARM         45717   // fel to player
#define SPELL_FOG_CHARM2        45726   // link to 45717

#define SPELL_TRANSFORM_TRIGGER 44885   // madrigosa to self, trigger 46350
#define SPELL_TRANSFORM_VISUAL  46350   //46411stun?
#define SPELL_TRANSFORM_FELMYST 45068   // become fel
#define SPELL_FELMYST_SUMMON    45069
// OTHER
#define SPELL_BERSERK           45078
#define SPELL_CLOUD_VISUAL      45212
#define SPELL_CLOUD_SUMMON      45884

//Creatures
#define MOB_FELMYST             25038
#define MOB_BRUTALLUS
#define MOB_KALECGOS
#define MOB_DEAD                25268
#define MOB_MADRIGOSA           25160
#define MOB_FELMYST_VISUAL      25041
#define MOB_FLIGHT_LEFT         25357
#define MOB_FLIGHT_RIGHT        25358
#define MOB_DEATH_CLOUD         25703
#define MOB_VAPOR               25265
#define MOB_VAPOR_TRAIL         25267

//Yells and Sounds
#define YELL_BIRTH      "Glory to Kil'jaeden! Death to all who oppose!"
#define SOUND_BIRTH            12477
#define YELL_KILL1      "I kill for the master!"
#define SOUND_KILL1            12480
#define YELL_KILL2      "The end has come!"
#define SOUND_KILL2            12481
#define YELL_BREATH     "Choke on your final breath!"
#define SOUND_BREATH   12478
#define YELL_TAKEOFF    "I am stronger than ever before!"
#define SOUND_TAKEOFF  12479
#define YELL_BERSERK    "No more hesitation! Your fates are written!"
#define SOUND_BERSERK  12482
#define YELL_DEATH      "Kil'jaeden... will... prevail..."
#define SOUND_DEATH            12483

#define YELL_KALECGOS   "Madrigosa deserved a far better fate. You did what had to be done, but this battle is far from over."

enum PhaseFelmyst
{
    PHASE_NULL  = 0,
    PHASE_GROUND = 1,
    PHASE_FLIGHT = 2,
};

enum EventFelmyst
{
    EVENT_NULL          =   0,
    EVENT_BERSERK       =   1,

    EVENT_CLEAVE        =   2,
    EVENT_CORROSION     =   3,
    EVENT_GAS_NOVA      =   4,
    EVENT_ENCAPSULATE   =   5,
    EVENT_FLIGHT        =   6,

    EVENT_FLIGHT_SEQUENCE   =   2,
    EVENT_SUMMON_DEAD       =   3,
    EVENT_SUMMON_FOG        =   4
};

static EventFelmyst MaxTimer[]=
{
    EVENT_NULL,
    EVENT_FLIGHT,
    EVENT_SUMMON_FOG,
};

struct TRINITY_DLL_DECL boss_felmystAI : public ScriptedAI
{
    boss_felmystAI(Creature *c) : ScriptedAI(c)
    {
        // wait for core patch be accepted
        SpellEntry *TempSpell = (SpellEntry*)GetSpellStore()->LookupEntry(SPELL_ENCAPSULATE_EFFECT);
        if(TempSpell->SpellIconID == 2294)
            TempSpell->SpellIconID = 2295;
        TempSpell = (SpellEntry*)GetSpellStore()->LookupEntry(SPELL_VAPOR_TRIGGER);
        if((TempSpell->Attributes & SPELL_ATTR_PASSIVE) == 0)
            TempSpell->Attributes |= SPELL_ATTR_PASSIVE;
        TempSpell = (SpellEntry*)GetSpellStore()->LookupEntry(SPELL_FOG_CHARM2);
        if((TempSpell->Attributes & SPELL_ATTR_PASSIVE) == 0)
            TempSpell->Attributes |= SPELL_ATTR_PASSIVE;
    }

    PhaseFelmyst Phase;
    EventFelmyst Event;
    uint32 Timer[EVENT_FLIGHT + 1];

    uint32 FlightCount;
    uint32 BreathCount;

    float BreathX, BreathY;

    void Reset()
    {
        Phase = PHASE_NULL;
        Event = EVENT_NULL;
        Timer[EVENT_BERSERK] = 600000;
        FlightCount = 0;

        m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
        m_creature->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 10);
        m_creature->SetFloatValue(UNIT_FIELD_COMBATREACH, 10);

        DespawnSummons(MOB_VAPOR_TRAIL);
  m_creature->setActive(false);
    }

    void EnterCombat(Unit *who)
    {
  m_creature->setActive(true);
        DoZoneInCombat();
        m_creature->CastSpell(m_creature, AURA_SUNWELL_RADIANCE, true);
        m_creature->CastSpell(m_creature, AURA_NOXIOUS_FUMES, true);
        EnterPhase(PHASE_GROUND);
    }

    void AttackStart(Unit *who)
    {
        if(Phase != PHASE_FLIGHT)
            ScriptedAI::AttackStart(who);
    }

    void MoveInLineOfSight(Unit *who)
    {
        if(Phase != PHASE_FLIGHT)
            ScriptedAI::MoveInLineOfSight(who);
    }

    void KilledUnit(Unit* victim)
    {
        switch(rand()%2)
        {
        case 0:
            DoYell(YELL_KILL1,LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_KILL1);
            break;
        case 1:
            DoYell(YELL_KILL2,LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_KILL2);
            break;
        }
    }

    void JustDied(Unit* Killer)
    {
        DoYell(YELL_DEATH, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_DEATH);
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        // workaround for linked aura
        /*if(spell->Id == SPELL_VAPOR_FORCE)
        {
            caster->CastSpell(caster, SPELL_VAPOR_TRIGGER, true);
        }*/
        // workaround for mind control
        if(spell->Id == SPELL_FOG_INFORM)
        {
            float x, y, z;
            caster->GetPosition(x, y, z);
            Unit* summon = m_creature->SummonCreature(MOB_DEAD, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
            if(summon)
            {
                summon->SetMaxHealth(caster->GetMaxHealth());
                summon->SetHealth(caster->GetMaxHealth());
                summon->CastSpell(summon, SPELL_FOG_CHARM, true);
                summon->CastSpell(summon, SPELL_FOG_CHARM2, true);
            }
            m_creature->DealDamage(caster, caster->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }
    }

    void JustSummoned(Creature *summon)
    {
        if(summon->GetEntry() == MOB_DEAD)
        {
            summon->AI()->AttackStart(SelectUnit(SELECT_TARGET_RANDOM, 0));
            DoZoneInCombat(summon);
            summon->CastSpell(summon, SPELL_DEAD_PASSIVE, true);
        }
    }

    void MovementInform(uint32, uint32)
    {
        Timer[EVENT_FLIGHT_SEQUENCE] = 1;
    }

    void DamageTaken(Unit*, uint32 &damage)
    {
        if(Phase != PHASE_GROUND && damage >= m_creature->GetHealth())
            damage = 0;
    }

    void EnterPhase(PhaseFelmyst NextPhase)
    {
        switch(NextPhase)
        {
        case PHASE_GROUND:
            Timer[EVENT_CLEAVE] = 5000 + rand()%5 * 1000;
            Timer[EVENT_CORROSION] = 10000 + rand()%10 * 1000;
            Timer[EVENT_GAS_NOVA] = 15000 + rand()%5 * 1000;
            Timer[EVENT_ENCAPSULATE] = 20000 + rand()%5 * 1000;
            Timer[EVENT_FLIGHT] = 60000;
            break;
        case PHASE_FLIGHT:
            Timer[EVENT_FLIGHT_SEQUENCE] = 1000;
            Timer[EVENT_SUMMON_DEAD] = 0;
            Timer[EVENT_SUMMON_FOG] = 0;
            FlightCount = 0;
            BreathCount = 0;
            break;
        default:
            break;
        }
        Phase = NextPhase;
    }

    void HandleFlightSequence()
    {
        switch(FlightCount)
        {
        case 0:
            m_creature->AttackStop();
            m_creature->GetMotionMaster()->Clear(false);
            m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
            m_creature->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
            m_creature->StopMoving();
            DoYell(YELL_TAKEOFF, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_TAKEOFF);
            Timer[EVENT_FLIGHT_SEQUENCE] = 2000;
            break;
        case 1:
            m_creature->GetMotionMaster()->MovePoint(0, m_creature->GetPositionX()+1, m_creature->GetPositionY(), m_creature->GetPositionZ()+10);
            Timer[EVENT_FLIGHT_SEQUENCE] = 0;
            break;
        case 2:
            if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0, 150, true))
            {
                Creature* Vapor = m_creature->SummonCreature(MOB_VAPOR, target->GetPositionX()-5+rand()%10, target->GetPositionY()-5+rand()%10, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 9000);
                if(Vapor)
                {
                    Vapor->AI()->AttackStart(target);
                    m_creature->InterruptNonMeleeSpells(false);
                    m_creature->CastSpell(Vapor, SPELL_VAPOR_CHANNEL, false); // core bug
                    Vapor->CastSpell(Vapor, SPELL_VAPOR_TRIGGER, true);
                }
            }else EnterEvadeMode();
            Timer[EVENT_FLIGHT_SEQUENCE] = 10000;
            break;
        case 3:
            DespawnSummons(MOB_VAPOR_TRAIL);
            //m_creature->CastSpell(m_creature, SPELL_VAPOR_SELECT); need core support
            if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0, 150, true))
            {
                //target->CastSpell(target, SPELL_VAPOR_SUMMON, true); need core support
                Creature* Vapor = m_creature->SummonCreature(MOB_VAPOR, target->GetPositionX()-5+rand()%10, target->GetPositionY()-5+rand()%10, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 9000);
                if(Vapor)
                {
                    Vapor->AI()->AttackStart(target);
                    m_creature->InterruptNonMeleeSpells(false);
                    m_creature->CastSpell(Vapor, SPELL_VAPOR_CHANNEL, false); // core bug
                    Vapor->CastSpell(Vapor, SPELL_VAPOR_TRIGGER, true);
                }
            }else EnterEvadeMode();
            Timer[EVENT_FLIGHT_SEQUENCE] = 10000;
            break;
        case 4:
            DespawnSummons(MOB_VAPOR_TRAIL);
            Timer[EVENT_FLIGHT_SEQUENCE] = 1;
            break;
        case 5:
            if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0, 150, true))
            {
                BreathX = target->GetPositionX();
                BreathY = target->GetPositionY();
                float x, y, z;
                target->GetContactPoint(m_creature, x, y, z, 70);
                m_creature->GetMotionMaster()->MovePoint(0, x, y, z+10);
            }else EnterEvadeMode();
            Timer[EVENT_FLIGHT_SEQUENCE] = 0;
            break;
        case 6:
            m_creature->SetOrientation(m_creature->GetAngle(BreathX, BreathY));
            m_creature->StopMoving();
            DoTextEmote("takes a deep breath.", NULL);
            Timer[EVENT_FLIGHT_SEQUENCE] = 10000;
            break;
        case 7:
            m_creature->CastSpell(m_creature, SPELL_FOG_BREATH, true);
            {
                float x, y, z;
                m_creature->GetPosition(x, y, z);
                x = 2 * BreathX - x;
                y = 2 * BreathY - y;
                m_creature->GetMotionMaster()->MovePoint(0, x, y, z);
            }
            Timer[EVENT_SUMMON_FOG] = 1;
            Timer[EVENT_FLIGHT_SEQUENCE] = 0;
            break;
        case 8:
            m_creature->RemoveAurasDueToSpell(SPELL_FOG_BREATH);
            BreathCount++;
            Timer[EVENT_SUMMON_FOG] = 0;
            Timer[EVENT_FLIGHT_SEQUENCE] = 1;
            if(BreathCount < 3) FlightCount = 4;
            break;
        case 9:
            if(Unit* target = SelectUnit(SELECT_TARGET_TOPAGGRO, 0))
            {
                float x, y, z;
                target->GetContactPoint(m_creature, x, y, z);
                m_creature->GetMotionMaster()->MovePoint(0, x, y, z);
            }else EnterEvadeMode();
            Timer[EVENT_FLIGHT_SEQUENCE] = 0;
            break;
        case 10:
            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            m_creature->StopMoving();
            m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
            EnterPhase(PHASE_GROUND);
            m_creature->AI()->AttackStart(SelectUnit(SELECT_TARGET_TOPAGGRO, 0));
            break;
        default:
            break;
        }
        FlightCount++;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
        {
            if(Phase == PHASE_FLIGHT && !m_creature->IsInEvadeMode())
                EnterEvadeMode();
            return;
        }

        Event = EVENT_NULL;
        for(uint32 i = 1; i <= MaxTimer[Phase]; i++)
        {
            if(Timer[i])
                if(Timer[i] <= diff)
                {
                    if(!Event)
                        Event = (EventFelmyst)i;
                }else Timer[i] -= diff;
        }

        if(m_creature->IsNonMeleeSpellCasted(false))
            return;

        if(Phase == PHASE_GROUND)
        {
            switch(Event)
            {
            case EVENT_BERSERK:
                DoYell(YELL_BERSERK, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_BERSERK);
                m_creature->CastSpell(m_creature, SPELL_BERSERK, true);
                Timer[EVENT_BERSERK] = 0;
                break;
            case EVENT_CLEAVE:
                m_creature->CastSpell(m_creature->getVictim(), SPELL_CLEAVE, false);
                Timer[EVENT_CLEAVE] = 5000 + rand()%5 * 1000;
                break;
            case EVENT_CORROSION:
                m_creature->CastSpell(m_creature->getVictim(), SPELL_CORROSION, false);
                Timer[EVENT_CORROSION] = 20000 + rand()%10 * 1000;
                break;
            case EVENT_GAS_NOVA:
                m_creature->CastSpell(m_creature, SPELL_GAS_NOVA, false);
                Timer[EVENT_GAS_NOVA] = 20000 + rand()%5 * 1000;
                break;
            case EVENT_ENCAPSULATE:
                if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0, 150, true))
                {
                    m_creature->CastSpell(target, SPELL_ENCAPSULATE_CHANNEL, false);
                    target->CastSpell(target, SPELL_ENCAPSULATE_EFFECT, true);// linked aura, need core patch to remove this hack
                    Timer[EVENT_ENCAPSULATE] = 25000 + rand()%5 * 1000;
                }break;
            case EVENT_FLIGHT:
                EnterPhase(PHASE_FLIGHT);
                break;
            default:
                DoMeleeAttackIfReady();
                break;
            }
        }

        if(Phase == PHASE_FLIGHT)
        {
            switch(Event)
            {
            case EVENT_BERSERK:
                DoYell(YELL_BERSERK, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_BERSERK);
                m_creature->CastSpell(m_creature, SPELL_BERSERK, true);
                Timer[EVENT_BERSERK] = 0;
                break;
            case EVENT_FLIGHT_SEQUENCE:
                HandleFlightSequence();
                break;
            case EVENT_SUMMON_FOG:
                {
                    float x, y, z;
                    m_creature->GetPosition(x, y, z);
                    m_creature->UpdateGroundPositionZ(x, y, z);
                    if(Creature *Fog = m_creature->SummonCreature(MOB_VAPOR_TRAIL, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN, 10000))
                    {
                        Fog->RemoveAurasDueToSpell(SPELL_TRAIL_TRIGGER);
                        Fog->CastSpell(Fog, SPELL_FOG_TRIGGER, true);
                    }
                }
                Timer[EVENT_SUMMON_FOG] = 1000;
                break;
            default:
                break;
            }
        }
    }

    void DespawnSummons(uint32 entry)
    {
        std::list<Creature*> templist;
        float x, y, z;
        m_creature->GetPosition(x, y, z);

        {
            CellPair pair(Trinity::ComputeCellPair(x, y));
            Cell cell(pair);
            cell.data.Part.reserved = ALL_DISTRICT;
            cell.SetNoCreate();

            Trinity::AllCreaturesOfEntryInRange check(m_creature, entry, 100);
            Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(m_creature, templist, check);

            TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange>, GridTypeMapContainer> cSearcher(searcher);

            CellLock<GridReadGuard> cell_lock(cell, pair);
            cell_lock->Visit(cell_lock, cSearcher, *(m_creature->GetMap()));
        }

        for(std::list<Creature*>::iterator i = templist.begin(); i != templist.end(); ++i)
        {
            if(entry == MOB_VAPOR_TRAIL && Phase == PHASE_FLIGHT)
            {
                float x, y, z;
                (*i)->GetPosition(x, y, z);
                m_creature->SummonCreature(MOB_DEAD, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
            }
            (*i)->SetVisibility(VISIBILITY_OFF);
            (*i)->setDeathState(JUST_DIED);
            if((*i)->getDeathState() == CORPSE)
                (*i)->RemoveCorpse();
        }
    }
};

struct TRINITY_DLL_DECL mob_felmyst_vaporAI : public ScriptedAI
{
    mob_felmyst_vaporAI(Creature *c) : ScriptedAI(c)
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetSpeed(MOVE_RUN, 0.8);
    }
    void Reset() {}
    void EnterCombat(Unit* who)
    {
        DoZoneInCombat();
        //m_creature->CastSpell(m_creature, SPELL_VAPOR_FORCE, true); core bug
    }
    void UpdateAI(const uint32 diff)
    {
        if(!m_creature->getVictim())
            AttackStart(SelectUnit(SELECT_TARGET_RANDOM, 0));
    }
};

struct TRINITY_DLL_DECL mob_felmyst_trailAI : public ScriptedAI
{
    mob_felmyst_trailAI(Creature *c) : ScriptedAI(c)
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->CastSpell(m_creature, SPELL_TRAIL_TRIGGER, true);
        m_creature->SetUInt64Value(UNIT_FIELD_TARGET, m_creature->GetGUID());
        m_creature->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 0.01); // core bug
    }
    void Reset() {}
    void EnterCombat(Unit* who) {}
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff) {}
};

CreatureAI* GetAI_boss_felmyst(Creature *_Creature)
{
    return new boss_felmystAI(_Creature);
}

CreatureAI* GetAI_mob_felmyst_vapor(Creature *_Creature)
{
    return new mob_felmyst_vaporAI(_Creature);
}

CreatureAI* GetAI_mob_felmyst_trail(Creature *_Creature)
{
    return new mob_felmyst_trailAI(_Creature);
}

void AddSC_boss_felmyst()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_felmyst";
    newscript->GetAI = &GetAI_boss_felmyst;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_felmyst_vapor";
    newscript->GetAI = &GetAI_mob_felmyst_vapor;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_felmyst_trail";
    newscript->GetAI = &GetAI_mob_felmyst_trail;
    newscript->RegisterSelf();
}

