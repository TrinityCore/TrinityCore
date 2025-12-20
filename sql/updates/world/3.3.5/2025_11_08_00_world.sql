--
UPDATE `creature_template_movement` SET `Rooted` = 1 WHERE `CreatureId` = 25741;

UPDATE `spell_script_names` SET `ScriptName` = 'spell_muru_summon_blood_elves_periodic' WHERE `ScriptName` = 'spell_summon_blood_elves_periodic';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_muru_summon_blood_elves_script' WHERE `ScriptName` = 'spell_summon_blood_elves_script';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_muru_dark_fiend_magic' WHERE `ScriptName` = 'spell_dark_fiend_skin';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_muru_transform_visual_missile_periodic' WHERE `ScriptName` = 'spell_transform_visual_missile_periodic';

UPDATE `spell_target_position` SET `PositionX` = 1723.2922, `PositionY` = 712.71094, `PositionZ` = 71.190320 WHERE `ID` = 46037;
UPDATE `spell_target_position` SET `PositionX` = 1728.3705, `PositionY` = 707.41840, `PositionZ` = 71.190315 WHERE `ID` = 46038;
UPDATE `spell_target_position` SET `PositionX` = 1905.3964, `PositionY` = 548.84240, `PositionZ` = 71.304535 WHERE `ID` = 46039;
UPDATE `spell_target_position` SET `PositionX` = 1908.0374, `PositionY` = 547.56110, `PositionZ` = 71.310750 WHERE `ID` = 46040;

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_void_spawn' WHERE `entry` = 25824;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25824 AND `source_type` = 0;

UPDATE `creature_template` SET `ScriptName` = 'npc_darkness' WHERE `entry` = 25879;

UPDATE `creature_template` SET `ScriptName` = 'npc_singularity' WHERE `entry` = 25855;

UPDATE `creature_template` SET `ScriptName` = 'npc_void_sentinel_summoner' WHERE `entry` = 25782;

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_shadowsword_berserker' WHERE `entry` = 25798;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25798 AND `source_type` = 0;

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_shadowsword_fury_mage' WHERE `entry` = 25799;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25799 AND `source_type` = 0;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (46228,46242,46262);

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_muru_summon_void_sentinel_summoner';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45978, 'spell_muru_summon_void_sentinel_summoner');

UPDATE `creature_template` SET `speed_run` = 0.428571 WHERE `entry` = 25744;
