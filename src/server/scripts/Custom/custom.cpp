#include "ScriptPCH.h"

/* This is where custom scripts' loading functions should be declared. */
void AddSC_custom_scripts();
void AddSC_brewfest();
void AddSC_TW_boss_faction_champions();
void AddSC_TW_hallows_end();
void AddSC_TW_pilgrim();
void AddSC_TW_instance_trial_of_the_champion();
void AddSC_TW_boss_grand_champions();
void AddSC_TW_boss_black_knight();
void AddSC_TW_boss_argent_challenge();
void AddSC_TW_trial_of_the_champion();
void AddSC_TW_boss_thorim();
void AddSC_custom_commandscript();
void AddSC_TW_boss_apothecary_trio();
void AddSC_TW_boss_hadronox();

/* This is where custom scripts should be added. */
void AddSC_custom()
{
    AddSC_custom_scripts();
    AddSC_brewfest();
    AddSC_TW_boss_faction_champions();
    AddSC_TW_hallows_end();
    AddSC_TW_pilgrim();
    AddSC_TW_instance_trial_of_the_champion();
    AddSC_TW_boss_argent_challenge();
    AddSC_TW_boss_black_knight();
    AddSC_TW_boss_grand_champions();
    AddSC_TW_trial_of_the_champion();
    AddSC_TW_boss_thorim();
    AddSC_custom_commandscript();
    AddSC_TW_boss_apothecary_trio();
    AddSC_TW_boss_hadronox();
}
