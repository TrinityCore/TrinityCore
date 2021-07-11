#include "ScriptedAI.h"
#include "Creature.h"
#include "SpellMgr.h"
#include "ScriptMgr.h"
#include "Util.h"

#define DEFAULT_MIN_CD 5000
#define DEFAULT_MAX_CD 15000
#define DEFAULT_TARGET GENERIC_TARGET_AUTO

#define GLOBAL_CD_MS 1500
//#define DEBUG_ON

enum
{
    GENERIC_TARGET_VICTIM = 0,
    GENERIC_TARGET_SELF = 1,
    GENERIC_TARGET_HOSTILE_RAND = 2,
    GENERIC_TARGET_HOSTILE_RAND_NOT_TOP = 3,
    GENERIC_TARGET_HOSTILE_IN_RANGE = 4,
    GENERIC_TARGET_FRIEND_NEED_HEAL = 5,
    GENERIC_TARGET_FRIEND_DISPELL_CC = 6,

    GENERIC_TARGET_AUTO = 100
};

enum
{
    SPELL_FLAG_CM                 = 0x001,
    SPELL_FLAG_APPLY_AURA         = 0x002,
    SPELL_FLAG_CAST_ON_AGGRO      = 0x004,
    SPELL_FLAG_STOP_ATTACK_TARGET = 0x008,
};

// Generic pour spells simples
struct GenericAISpell
{
    uint32 spellId;

    uint32 minCD;
    uint32 maxCD; /* Ou 0 si pas repetable.*/

    uint32 initialMinCD;
    uint32 initialMaxCD;

    uint8 target;

    uint32 timer;

    // Variables en interne.
    float minRange;
    float maxRange;
    uint32 healValue;

    uint32 spellFlags;
    uint32 targetAuraState;
};

struct MobSpellEntry
{
    uint32 entry;
    GenericAISpell spell;
};

std::vector<MobSpellEntry> GenericSpellMobData;


CreatureAI* GetAI_GenericSpellAI(Creature* pCreature);
GenericAISpell BuildGenericAISpell(uint32 spellId, uint32 minCD, uint32 maxCD, uint32 target);
void LoadSpellCacheData(GenericAISpell* spellToModify, SpellEntry const* spellInfos);
//void LoadGenericAISpellsData();

struct GenericSpellMob : public ScriptedAI
{
    GenericSpellMob(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    std::vector<GenericAISpell> m_uiSpells;

    // Si 'true', le mob attaquera a distance tant qu'il aura du mana.
    bool isDistanceCaster;
    uint32 casterGCD;

    void AddSpell(uint32 spellId, uint32 CDmin, uint32 CDmax, uint8 target)
    {
        GenericAISpell spell;
        spell.spellId = spellId;
        spell.minCD = CDmin;
        spell.maxCD = CDmax;
        spell.target = target;
        spell.minRange = 0.0f;
        spell.maxRange = 40.0f;
        spell.healValue = 0;
        AddSpell(spell);
    }

    void AddSpell(GenericAISpell insertSpell)
    {
        m_uiSpells.push_back(insertSpell);
#ifdef DEBUG_ON
        sLog.outString(">> Creature %u added spell %u (heal %u, range %f-%f, repeat %u-%u on target %u)", m_creature->GetEntry(),
                      insertSpell.spellId, insertSpell.healValue, insertSpell.minRange, insertSpell.maxRange,
                      insertSpell.minCD, insertSpell.maxCD, insertSpell.target);
#endif
    }

    void Finalize()
    {
        isDistanceCaster = true;
        if (m_uiSpells.empty())
        {
            isDistanceCaster = false;
            return;
        }

        std::vector<GenericAISpell>::iterator it;
        for (it = m_uiSpells.begin(); it != m_uiSpells.end() && isDistanceCaster; ++it)
        {
            if (it->minRange <= 2.0f)
                isDistanceCaster = false;
        }
        Reset();
    }

    void Reset()
    {
        std::vector<GenericAISpell>::iterator it;
        for (it = m_uiSpells.begin(); it != m_uiSpells.end(); ++it)
        {
#ifdef DEBUG_ON
            sLog.outString(">> Spell %u reset", it->spellId);
#endif
            if (isDistanceCaster)
                it->timer = urand(0, 3000);
            else
            {
                if (it->initialMinCD == it->initialMaxCD)
                    it->timer = it->initialMinCD;
                else
                    it->timer = urand(it->initialMinCD, it->initialMaxCD);
            }
            /*else
            {
                it->timer = 0;
            }*/
        }
        casterGCD = 0;
    }

    void UpdateAI(uint32 const uiDiff)
    {
        m_creature->SelectHostileTarget();
        if (!m_creature->GetVictim())
            return;
        /*if (isDistanceCaster)
        { // Check du CoolDown global
            if (casterGCD > uiDiff)
            {
                // Pas encore pret !
                casterGCD -= uiDiff;
                return;
            }
            else
            {
                casterGCD = GLOBAL_CD_MS;
            }
        }*/
        // Vu que le script ne fait que caster des sorts ...
        if (m_creature->IsNonMeleeSpellCasted(false))
            return;

        std::vector<GenericAISpell>::iterator it;
#ifdef DEBUG_ON
        sLog.outString("UpdateAI with SpellSize = %u", m_uiSpells.size());
#endif
        for (it = m_uiSpells.begin(); it != m_uiSpells.end(); ++it)
        {
#ifdef DEBUG_ON
            sLog.outString("Spell %u update : timer %u", it->spellId, it->timer);
#endif
            if (it->timer  < uiDiff)
            {
                Unit* target = nullptr;
                switch (it->target)
                {
                    case GENERIC_TARGET_SELF:
                        target = m_creature;
                        break;
                    case GENERIC_TARGET_VICTIM:
                        target = m_creature->GetVictim();
                        break;
                    case GENERIC_TARGET_HOSTILE_RAND:
                        target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
                        break;
                    case GENERIC_TARGET_HOSTILE_RAND_NOT_TOP:
                        target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1);
                        break;
                    case GENERIC_TARGET_HOSTILE_IN_RANGE:
                    {
                        for (uint8 i = 0; i < 10; ++i)
                        {
                            if (Unit* targetTest = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, i))
                            {
                                if (m_creature->IsInRange(targetTest, it->minRange, it->maxRange, false))
                                {
                                    target = targetTest;
                                    break;
                                }
                            }
                        }
                        break;

                    }
                    case GENERIC_TARGET_FRIEND_NEED_HEAL:
                    {
                        target = m_creature->FindLowestHpFriendlyUnit(it->maxRange, it->healValue / 4);
                        break;
                    }
                    case GENERIC_TARGET_FRIEND_DISPELL_CC:
                    {
                        std::list<Creature*> creaList = DoFindFriendlyCC(it->maxRange);

                        while (!creaList.empty())
                        {
                            Creature* crea = creaList.front();
                            creaList.pop_front();
                            // TODO : Chercher la creature qui correspond au dispell.
                            target = crea;
                        }
                        break;
                    }
                }
                bool cast = true;
                if (target)
                {
                    // Test pour le HEAL
                    if (it->healValue != 0)
                    {
                        // Points de vie qu'il manque
                        uint32 healthDiff = target->GetMaxHealth() - target->GetHealth();

                        // Overheal test
                        if (it->healValue > healthDiff
                                && target->GetHealthPercent() > 50.0f    // Et qu'on est pas en dessous de la moitie de vie
                           )
                            cast = false;
                    }
                }
                else
                    cast = false;

                if (cast && m_creature->IsNonMeleeSpellCasted(false))
                    cast = false;

                if (cast && it->spellFlags & SPELL_FLAG_APPLY_AURA)
                {
                    if (target->HasAura(it->spellId))
                        cast = false;
                }
                // Test CM
                if (cast && it->spellFlags & SPELL_FLAG_CM)
                {
                    uint32 targetCounts = m_creature->GetThreatManager().getThreatList().size();
                    // On ne CM pas si il n'y a personne d'autre.
                    if (targetCounts <= 1)
                        cast = false;
                }

                // Test TargetAuraState
                if (cast && it->targetAuraState)
                {
                    if (!target->HasAuraState(AuraState(it->targetAuraState)))
                        cast = false;
                }

                if (cast)
                {
                    DoCastSpellIfCan(target, it->spellId);
                    it->timer = urand(it->minCD, it->maxCD);
                    if (it->spellFlags & SPELL_FLAG_STOP_ATTACK_TARGET && target != m_creature->GetVictim()) // Change de cible
                    {
                        if (Unit* pSecondAggro = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 1))
                        {
                            if (pSecondAggro != target)
                            {
                                m_creature->GetThreatManager().modifyThreatPercent(target, -100);
                                AttackStart(pSecondAggro);
                            }
                        }
                    }
#ifdef DEBUG_ON
                    sLog.outString("Casting %u on %s. CD is %u", it->spellId, target->GetName(), it->timer);
#endif
                }
                else
                {
#ifdef DEBUG_ON
                    sLog.outString("Reporting cast of %u", it->spellId);
#endif
                    it->timer = 500; // Recheck dans 500 ms
                }
            }
            else
                it->timer -= uiDiff;
        }
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_GenericSpellAI(Creature* pCreature)
{
    bool foundSpecific = false;
    GenericSpellMob* ScriptedMob = new GenericSpellMob(pCreature);
    uint32 creatureId = pCreature->GetEntry();
#ifdef DEBUG_ON
    sLog.outString("GetAI for ID %u", creatureId);
#endif
    std::vector<MobSpellEntry>::iterator iter;
    for (iter = GenericSpellMobData.begin(); iter != GenericSpellMobData.end(); ++iter)
    {
        if (iter->entry == creatureId)
        {
            ScriptedMob->AddSpell(iter->spell);
            foundSpecific = true;
        }
    }
    if (foundSpecific)
    {
        ScriptedMob->Finalize();
        return ScriptedMob;
    }
    /* Sinon, ca signifie qu'il n'y a pas de script de ce mob en particulier.
    Dans ce cas, on recupere ses sorts (spell[1-4]) et on lui ajoute en fonction de comment sont scriptes ces sorts
    chez d'autres mobs.
    */
#ifdef DEBUG_ON
    sLog.outString("Impossible de trouver les spells du mob %u. Va essayer de les deduire ...", pCreature->GetEntry());
#endif
    bool mobFoundSpells[CREATURE_MAX_SPELLS] = {false};
    CreatureInfo const* infos = pCreature->GetCreatureInfo();
    // Ne pas chercher les sorts = 0
    for (uint8 i = 0; i < CREATURE_MAX_SPELLS; ++i)
    {
        if (infos->spells[i] == 0)
            mobFoundSpells[i] = true;
    }
    // On ajoute les sorts qu'on connait de creature_spells
    for (iter = GenericSpellMobData.begin(); iter != GenericSpellMobData.end(); ++iter)
    {
        for (uint8 i = 0; i < CREATURE_MAX_SPELLS; ++i)
        {
            if (!mobFoundSpells[i] // Pas deja ajoute
                    && iter->spell.spellId == infos->spells[i] // Et le sort est trouve dans la DB
               )
            {
                ScriptedMob->AddSpell(iter->spell);
                // Histoire de ne pas ajouter le meme sort 2 fois a la meme creature...
                mobFoundSpells[i] = true;
            }
        }
    }
    // Et finalement on essaye d'ajouter les autres
    for (uint8 i = 0; i < CREATURE_MAX_SPELLS; ++i)
    {
        if (!mobFoundSpells[i])
        {
            GenericAISpell mySpell = BuildGenericAISpell(
                                         infos->spells[i],
                                         DEFAULT_MIN_CD,
                                         DEFAULT_MAX_CD,
                                         DEFAULT_TARGET);
            if (mySpell.spellId != 0) // Pas d'erreur
                ScriptedMob->AddSpell(mySpell);
        }
    }
#ifdef DEBUG_ON
    sLog.outString("GetAI for ID %u -- END", creatureId);
#endif
    ScriptedMob->Finalize();
    return ScriptedMob;
}

GenericAISpell BuildGenericAISpell(uint32 spellId, uint32 minCD, uint32 maxCD, uint32 target)
{
    GenericAISpell tmpSpell;
    tmpSpell.spellId  = spellId;
    tmpSpell.minCD    = minCD;
    tmpSpell.maxCD    = maxCD;
    tmpSpell.target   = target;

    SpellEntry const* spell = sSpellMgr.GetSpellEntry(tmpSpell.spellId);
    if (!spell)
    {
#ifdef DEBUG_ON
        sLog.outString(">> Sort introuvable (id=%u) !", tmpSpell.spellId);
#endif
        tmpSpell.spellId = 0;
        return tmpSpell;
    }
    LoadSpellCacheData(&tmpSpell, spell);
    return tmpSpell;
}

void LoadSpellCacheData(GenericAISpell* spellToModify, SpellEntry const* spellInfos)
{
    spellToModify->minRange = 0.0f;
    spellToModify->maxRange = 40.0f;
    spellToModify->healValue = 0;
    spellToModify->spellFlags = 0;
    spellToModify->initialMinCD = 0; //spellToModify->minCD;
    spellToModify->initialMaxCD = 0; //spellToModify->maxCD;
    spellToModify->targetAuraState = spellInfos->TargetAuraState;

#ifdef DEBUG_ON
    sLog.outString(">> Loading Spell %s (id=%u) !", spellInfos->SpellName[2].c_str(), spellToModify->spellId);
#endif

    // Check de la portee
    SpellRangeEntry const* rangeEntry = sSpellRangeStore.LookupEntry(spellInfos->rangeIndex);
    if (spellInfos->rangeIndex != 0 && rangeEntry)
    {
        spellToModify->minRange = rangeEntry->minRange;
        spellToModify->maxRange = rangeEntry->maxRange;
    }

    // Heal check
    for (uint8 i = 0; i < 3; ++i)
    {
        if (spellInfos->Effect[i] == 10) // HEAL
            spellToModify->healValue += spellInfos->EffectBasePoints[i];
    }

    if (spellToModify->target == GENERIC_TARGET_AUTO)
    {
        /* 1 : Sorts amicaux*/
        // Heal
        if (spellToModify->healValue != 0)
            spellToModify->target = GENERIC_TARGET_FRIEND_NEED_HEAL;
        // Autres sorts positifs
        else if (Spells::IsPositiveSpell(spellToModify->spellId))
            spellToModify->target = GENERIC_TARGET_SELF;
        /* 2 : Sorts negatifs*/
        // Attaque a distance
        else if (spellToModify->minRange >= 2.0f)
            spellToModify->target = GENERIC_TARGET_HOSTILE_IN_RANGE;
        // Sinon, on prend l'aggro n1
        else
            spellToModify->target = GENERIC_TARGET_VICTIM;

        switch (spellInfos->Category)
        {
            case 21: // Enrager
            {
                spellToModify->target = GENERIC_TARGET_SELF;
                spellToModify->initialMinCD = 60000;
                spellToModify->initialMaxCD = 60000;
                break;
            }
            case 44: // Charge
            {
                spellToModify->target = GENERIC_TARGET_HOSTILE_IN_RANGE;
                spellToModify->initialMinCD = 0;
                spellToModify->initialMaxCD = 1;
                spellToModify->minCD        = 10000;
                spellToModify->maxCD        = 12000;
                spellToModify->spellFlags |= SPELL_FLAG_CAST_ON_AGGRO;
                break;
            }
        }

        // Si le sort a un CD
        if (spellInfos->CategoryRecoveryTime > 1500)
        {
            spellToModify->initialMinCD = 0;
            spellToModify->initialMaxCD = 5000;
            spellToModify->minCD        = spellInfos->CategoryRecoveryTime;
            spellToModify->maxCD        = spellInfos->CategoryRecoveryTime;
        }
        // Autres modifs :
        for (uint8 i = 0; i < 3; ++i)
        {
            switch (spellInfos->Effect[i])
            {
                case SPELL_EFFECT_APPLY_AURA:
                case SPELL_EFFECT_APPLY_AREA_AURA_PARTY:
                {
                    switch (spellInfos->EffectApplyAuraName[i])
                    {
                        case SPELL_AURA_MOD_CHARM:
                        case SPELL_AURA_MOD_POSSESS:
                            spellToModify->spellFlags |= SPELL_FLAG_CM;
                            break;
                    }
                    spellToModify->spellFlags |= SPELL_FLAG_APPLY_AURA;
                    break;
                }
                case SPELL_EFFECT_SUMMON_GUARDIAN:
                {
                    int32 duration = spellInfos->GetDuration();
                    if (duration > 0) 
                    {
                        spellToModify->minCD = duration;
                        spellToModify->maxCD = duration;
                    }
                }
            }
        }
        if (spellInfos->AuraInterruptFlags & AURA_INTERRUPT_FLAG_DAMAGE)
            spellToModify->spellFlags |= SPELL_FLAG_STOP_ATTACK_TARGET;
        // Bouclier divin, bene de protection, bloc de glace et autres : CD different
        // SELECT field0, field6, field7, field8, field122 FROM spells WHERE field8 & 0x200000 AND field6 & 0x50000 AND (field7 & 0x8000 OR field7=0) limit 0,50;
        if (spellInfos->Attributes & 0x50000 && (spellInfos->AttributesEx & 0x8000 || spellInfos->AttributesEx == 0) && spellInfos->AttributesEx2 & 0x200000)
        {
            // Apres 30 a 50 sec de combat
            spellToModify->initialMinCD = 30000;
            spellToModify->initialMaxCD = 50000;
            // Toutes les 3 a 4 minutes ensuite
            spellToModify->minCD        = 180000;
            spellToModify->maxCD        = 240000;
        }
#ifdef DEBUG_ON
        if (spellToModify->spellFlags != 0)
            sLog.outString("SpellFlags are 0x%x for %u", spellToModify->spellFlags, spellToModify->spellId);
#endif
    }
}
/* this was never used
void LoadGenericAISpellsData()
{
    GenericSpellMobData.clear();
    QueryResult* pResult = WorldDatabase.PQuery("SELECT entry, spell, minCD, maxCD, target FROM creature_spells");
    sLog.outString("Nostalrius: Loading 'creature_spells'");

    if (pResult)
    {
        uint32 uiCount = 0;

        do
        {
            Field* pFields = pResult->Fetch();
            MobSpellEntry pTmp;

            pTmp.entry          = pFields[0].GetUInt32();

            pTmp.spell = BuildGenericAISpell(
                             pFields[1].GetUInt32(), // spellId
                             pFields[2].GetUInt32(), // minCD
                             pFields[3].GetUInt32(), // maxCD
                             pFields[4].GetUInt32()  // target
                         );
            if (pTmp.spell.spellId != 0)
                GenericSpellMobData.push_back(pTmp);

            ++uiCount;
        }
        while (pResult->NextRow());

        delete pResult;

        sLog.outString("");
        sLog.outString(">> Loaded %u spells datas", uiCount);
    }
    else
    {
        sLog.outString("");
        sLog.outString(">> Loaded 0 mob spells datas. DB table `creature_spells` is empty.");
    }
}
*/
void AddSC_generic_spell_ai()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "generic_spell_ai";
    newscript->GetAI = &GetAI_GenericSpellAI;
    newscript->RegisterSelf();
    //LoadGenericAISpellsData();
}
