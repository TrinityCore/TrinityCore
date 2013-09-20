#include "ScriptPCH.h"

/* This is where custom scripts' loading functions should be declared. */
void AddSC_custom_scripts();
void AddSC_brewfest();
void AddSC_TW_boss_faction_champions();

/* This is where custom scripts should be added. */
void AddSC_custom()
{
    AddSC_custom_scripts();
    AddSC_brewfest();
    AddSC_TW_boss_faction_champions();
}