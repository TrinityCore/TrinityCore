#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "TrainerAction.h"

using namespace ai;

void TrainerAction::Learn(uint32 cost, TrainerSpell const* tSpell, ostringstream& msg)
{
    if (bot->GetMoney() < cost)
        return;

    bot->ModifyMoney(-int32(cost));
    if (tSpell->IsCastable())
        bot->CastSpell(bot, tSpell->spell, true);
    else
        bot->LearnSpell(tSpell->learnedSpell[0], false, false);

    msg << " - learned";
}

void TrainerAction::List(Creature* creature, TrainerSpellAction action, SpellIds& spells)
{
    TellHeader(creature);

    TrainerSpellData const* trainer_spells = creature->GetTrainerSpells();
    float fDiscountMod =  bot->GetReputationPriceDiscount(creature);
    uint32 totalCost = 0;

    for (TrainerSpellMap::const_iterator itr =  trainer_spells->spellList.begin(); itr !=  trainer_spells->spellList.end(); ++itr)
    {
        TrainerSpell const* tSpell = &itr->second;

        if (!tSpell)
            continue;

        if (!tSpell->learnedSpell && !bot->IsSpellFitByClassAndRace(tSpell->learnedSpell[0]))
            continue;

        TrainerSpellState state = bot->GetTrainerSpellState(tSpell);
        if (state != TRAINER_SPELL_GREEN)
            continue;

        uint32 spellId = tSpell->spell;
        const SpellInfo *const pSpellInfo =  sSpellMgr->GetSpellInfo(spellId);
        if (!pSpellInfo)
            continue;

        uint32 cost = uint32(floor(tSpell->spellCost *  fDiscountMod));
        totalCost += cost;

        ostringstream out;
        out << chat->formatSpell(pSpellInfo) << chat->formatMoney(cost);

        if (action && (spells.empty() || spells.find(tSpell->spell) != spells.end() || spells.find(tSpell->learnedSpell[0]) != spells.end()))
            (this->*action)(cost, tSpell, out);

        ai->TellMaster(out);
    }

    TellFooter(totalCost);
}


bool TrainerAction::Execute(Event event)
{
    string text = event.getParam();

    Player* master = GetMaster();
    if (!master)
        return false;

    Unit* target = master->GetSelectedUnit();
    if (!target)
        return false;

    Creature *creature = ai->GetCreature(target->GetGUID());
    if (!creature)
        return false;

    // check present spell in trainer spell list
    TrainerSpellData const* cSpells = creature->GetTrainerSpells();
    if (!cSpells)
    {
        ai->TellMaster("No spells can be learned from this trainer");
        return false;
    }

    uint32 spell = chat->parseSpell(text);
    SpellIds spells;
    if (spell)
        spells.insert(spell);

    if (text == "learn")
        List(creature, &TrainerAction::Learn, spells);
    else
        List(creature, NULL, spells);

    return true;
}

void TrainerAction::TellHeader(Creature* creature)
{
    ostringstream out; out << "--- can learn from " << creature->GetName() << " ---";
    ai->TellMaster(out);
}

void TrainerAction::TellFooter(uint32 totalCost)
{
    if (totalCost)
    {
        ostringstream out; out << "Total cost: " << chat->formatMoney(totalCost);
        ai->TellMaster(out);
    }
}
