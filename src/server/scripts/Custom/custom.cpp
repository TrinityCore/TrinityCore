#include "ScriptPCH.h"

/* This is where custom scripts' loading functions should be declared. */
void AddSC_custom_scripts();
void AddSC_brewfest();
void AddSC_TW_boss_faction_champions();
void AddSC_TW_hallows_end();
void AddSC_TW_pilgrim();
void AddSC_TW_boss_falric();
void AddSC_TW_boss_lich_king_hor();
void AddSC_TW_boss_marwyn();
void AddSC_TW_halls_of_reflection();
void AddSC_TW_instance_halls_of_reflection();

/* This is where custom scripts should be added. */
void AddSC_custom()
{
    AddSC_custom_scripts();
    AddSC_brewfest();
    AddSC_TW_boss_faction_champions();
    AddSC_TW_hallows_end();
    AddSC_TW_pilgrim();
    AddSC_TW_boss_falric();
    AddSC_TW_boss_lich_king_hor();
    AddSC_TW_boss_marwyn();
    AddSC_TW_halls_of_reflection();
    AddSC_TW_instance_halls_of_reflection();
}
