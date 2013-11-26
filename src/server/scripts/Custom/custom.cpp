#include "ScriptPCH.h"

/* This is where custom scripts' loading functions should be declared. */
void AddSC_custom_scripts();
void AddSC_brewfest();
void AddSC_TW_boss_faction_champions();
void AddSC_TW_hallows_end();
void AddSC_TW_pilgrim();

/* This is where custom scripts should be added. */
void AddSC_custom()
{
    AddSC_custom_scripts();
    AddSC_brewfest();
    AddSC_TW_boss_faction_champions();
    AddSC_TW_hallows_end();
    AddSC_TW_pilgrim();
}