DELETE FROM `spell_script_target` WHERE `entry` IN (58836);
INSERT INTO `spell_script_target` VALUES (58836, 1, 31216);
UPDATE `creature_template` SET `ScriptName`='npc_mirror_image' WHERE `entry`=31216;
UPDATE `creature_template` SET `spell1`=59638, `spell2` = 59637 WHERE `entry`=31216;