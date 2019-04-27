#include "project_language.h"
#include "Player.h"
#include "WorldSession.h"
#include "ObjectAccessor.h"

namespace PROJECT {
namespace Language {

std::vector<std::map<uint32, char *> > StringsList;

void Reload()
{
    StringsList.clear();
    // resize the vector
    for (int i = 0; i < PROJECT::Language::Languages::MAX; i++)
        StringsList.resize(PROJECT::Language::Languages::MAX);

    QueryResult result = WorldDatabase.Query("SELECT id, fr, en FROM project_strings");
    if (!result)
        return;
    // cleanup
    for (std::vector<std::map<uint32, char *> >::iterator it = StringsList.begin(); it != StringsList.end(); ++it)
    {
        for (std::map<uint32, char *>::iterator itr = (*it).begin(); itr != (*it).end(); ++itr)
            free((*itr).second);
        (*it).clear();
    }
    // populate the vector
    do
    {
        Field * fields = result->Fetch();
        uint32 id = fields[0].GetUInt32();
        for (int i = 0; i < PROJECT::Language::Languages::MAX; i++)
        {
            const char * tmp = fields[i + 1].GetCString();
            StringsList[i][id] = (char *)malloc(strlen(tmp) + 1);
            strcpy(StringsList[i][id], tmp);
            StringsList[i][id][strlen(tmp)] = '\0';
        }
    } while (result->NextRow());
}

Languages GetLanguageForPlayer(Player * player)
{
    return player->GetSession()->Variables.GetValue<Languages>("Language");
}

const char * GetLanguageString(uint32 stringId, Languages language)
{
    std::map<uint32, char *>::iterator i = StringsList[language].find(stringId);
    if (i == StringsList[language].end())
        return "*STRING_NOT_FOUND*";

    return i->second;
}

const char * GetLanguageString(uint32 stringId, Player * player)
{
    return GetLanguageString(stringId, GetLanguageForPlayer(player));
}

const char * GetLanguageString(uint32 stringId, ObjectGuid playerGuid)
{
    Languages language = Languages::ENGLISH;

    Player * player = ObjectAccessor::FindPlayer(playerGuid);
    if (player)
        return GetLanguageString(stringId, player);
    else
    {
        if (QueryResult result = CharacterDatabase.PQuery("SELECT account FROM characters WHERE guid = %u", playerGuid.GetCounter()))
        {
            uint32 accId = (result->Fetch())[0].GetInt32();

            if (QueryResult result = LoginDatabase.PQuery("SELECT site_lang FROM account WHERE id = %u", accId))
            {
                Field * field = result->Fetch();
                const char * lang = field[0].GetCString();
                if (!strcmp(lang, "FR"))
                    language = Languages::FRENCH;
            }
        }
    }

    return GetLanguageString(stringId, language);
}

const char * GetLanguageName(Languages language)
{
    switch (language)
    {
        case Languages::FRENCH:
            return "Français";
        case Languages::ENGLISH:
            return "English";
    }

    return "---";
}

} // Language
} // PROJECT
