UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x10000000 WHERE `entry` IN (SELECT `creditEntry` FROM `instance_encounters` WHERE `creditType`=0);

DROP TABLE IF EXISTS `instance_encounters`;

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_dungeon_credit';
