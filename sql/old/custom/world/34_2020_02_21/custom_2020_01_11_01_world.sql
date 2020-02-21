UPDATE `creature_template` SET `ScriptName`= '' WHERE `ScriptName`= 'npc_sfk_bloodthirsty_ghoul';
DELETE FROM `achievement_criteria_data` WHERE `ScriptName`= 'achievement_bullet_time';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_godfrey_summon_bloodthirsty_ghouls' WHERE `ScriptName`= 'spell_sfk_summon_bloodthirsty_ghouls';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_godfrey_pistol_barrage' WHERE `ScriptName`= 'spell_sfk_pistol_barrage';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_godfrey_pistol_barrage_aoe' WHERE `ScriptName`= 'spell_sfk_pistol_barrage_summon';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_godfrey_cursed_bullets' WHERE `ScriptName`= 'spell_sfk_cursed_bullets';
