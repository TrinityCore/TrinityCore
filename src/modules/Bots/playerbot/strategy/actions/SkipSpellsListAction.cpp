#include "botpch.h"
#include "../../playerbot.h"
#include "SkipSpellsListAction.h"
#include "../values/SkipSpellsListValue.h"
#include "LootAction.h"
#include "../../ServerFacade.h"

using namespace ai;


bool SkipSpellsListAction::Execute(Event event)
{
    string cmd = event.getParam();

    set<uint32>& skipSpells = AI_VALUE(set<uint32>&, "skip spells list");

    SpellIds spellIds = parseIds(cmd);
    if (!spellIds.empty()) {
        skipSpells.clear();
        for (SpellIds::iterator i = spellIds.begin(); i != spellIds.end(); ++i)
        {
            skipSpells.insert(*i);
        }
        cmd = "?";
    }

    if (cmd == "reset")
    {
        skipSpells.clear();
        ai->TellMaster("Ignored spell list is empty");
        return true;
    }

    if (cmd.empty() || cmd == "?")
    {
        ostringstream out;
        if (skipSpells.empty())
        {
            ai->TellMaster("Ignored spell list is empty");
            return true;
        }

        out << "Ignored spell list: ";

        bool first = true;
        for (set<uint32>::iterator i = skipSpells.begin(); i != skipSpells.end(); i++)
        {
            SpellEntry const* spell = sServerFacade.LookupSpellInfo(*i);
            if (!spell)
                continue;

            if (first) first = false; else out << ", ";
            out << chat->formatSpell(spell);
        }
        ai->TellMaster(out);
    }
    else
    {
        bool remove = cmd.size() > 1 && cmd.substr(0, 1) == "-";
        if (remove)
            cmd = cmd.substr(1);

        uint32 spellId = chat->parseSpell(cmd);
        if (!spellId)
        {
            ai->TellMaster("Unknown spell");
            return false;
        }

        SpellEntry const* spell = sServerFacade.LookupSpellInfo(spellId);
        if (!spell)
            return false;

        if (remove)
        {
            set<uint32>::iterator j = skipSpells.find(spellId);
            if (j != skipSpells.end())
            {
                skipSpells.erase(j);
                ostringstream out;
                out << chat->formatSpell(spell) << " removed from ignored spells";
                ai->TellMaster(out);
                return true;
            }
        }
        else
        {
            set<uint32>::iterator j = skipSpells.find(spellId);
            if (j == skipSpells.end())
            {
                skipSpells.insert(spellId);
                ostringstream out;
                out << chat->formatSpell(spell) << " added to ignored spells";
                ai->TellMaster(out);
                return true;
            }
        }
    }

    return false;
}


SpellIds SkipSpellsListAction::parseIds(string text)
{
    SpellIds spellIds;

    uint8 pos = 0;
    while (pos < text.size())
    {
        int endPos = text.find(',', pos);
        if (endPos == -1)
            endPos = text.size();

        string idC = text.substr(pos, endPos - pos);
        uint32 id = atol(idC.c_str());
        pos = endPos + 1;
        if (id)
            spellIds.insert(id);
    }

    return spellIds;
}
