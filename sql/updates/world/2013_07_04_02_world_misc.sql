UPDATE `creature_template` SET `ScriptName` = REPLACE(`ScriptName`, 'mob_', 'npc_') WHERE `ScriptName` LIKE 'mob\_%';
UPDATE `creature_template` SET `ScriptName` = REPLACE(`ScriptName`, 'mobs_', 'npc_') WHERE `ScriptName` LIKE 'mobs\_%';
UPDATE `spell_script_names` SET `ScriptName`='spell_trash_npc_glacial_strike' WHERE `ScriptName`='spell_trash_mob_glacial_strike';

