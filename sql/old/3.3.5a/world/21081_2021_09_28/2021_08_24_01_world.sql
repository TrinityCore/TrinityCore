-- Cultist Corpse
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 28464;
UPDATE `creature_template_addon` SET `bytes2` = 1 WHERE `entry` = 28464;
UPDATE `creature` SET `position_x` = 5536.11181640625, `position_y` = 4094.2939453125, `position_z` = 43.29499435424804687, `orientation` = 3.124139308929443359, `VerifiedBuild` = 11159 WHERE `id` = 28464;

-- Vrykul Corpse
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 24467;
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1, `auras` = '29266' WHERE `entry` = 24467;

-- Dead Warmaiden & Dead Warbear
-- She has subname 'PH Texture' and nothing in sniffs tells it should not be displayed to players
-- Weird creatures, they also have type flags 2048 for no reason and https://www.wowhead.com/npc=29584/dead-warmaiden#comments
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1 WHERE `entry` = 29585;

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 29584;
DELETE FROM `creature_template_addon` WHERE `entry` = 29584;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(29584,0,0,0,1,0,0,'29266');

DELETE FROM `creature` WHERE `guid` = 82999 AND `id` = 29584;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(82999,29584,571,67,0,1,1,0,1,7065.1728515625,-2121.101806640625,756.0772705078125,0.087266460061073303,300,0,0,0,0,0,0,0,0,'',11159);

-- Halfdan's Soul
UPDATE `creature_template` SET `dynamicflags` = 0 WHERE `entry` = 24119;
UPDATE `creature_template_addon` SET `bytes2` = 1, `auras` = '37119 36545 36550' WHERE `entry` = 24119;
-- There are 2 Floating Drowned spells but only 36545 can apply flags, not 36550
-- Luckily they don't always comes in pair and that can be checked in sniffs
DELETE FROM `spell_script_names` WHERE `spell_id` = 36545 AND `ScriptName` = 'spell_gen_feign_death_no_prevent_emotes';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(36545,'spell_gen_feign_death_no_prevent_emotes');

-- Scout Jyoba
UPDATE `creature_template` SET `unit_flags` = 768, `dynamicflags` = 0 WHERE `entry` = 18035;
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1, `auras` = '29266' WHERE `entry` = 18035;

-- Blood Knight Dawnstar
-- Not sniffed but not really guessed
UPDATE `creature_template` SET `speed_walk` = 1, `unit_flags` = 768, `dynamicflags` = 0 WHERE `entry` = 17832;
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1, `auras` = '29266' WHERE `entry` = 17832;

-- Creteus
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 30493;

-- Death Knight Initiate
UPDATE `creature_template` SET `dynamicflags` = 0 WHERE `entry` = 28391;
UPDATE `creature_template` SET `dynamicflags` = 0 WHERE `entry` = 28394;

-- Forsaken Prisoner, auras he uses are part of event
UPDATE `creature_template` SET `dynamicflags` = 0 WHERE `entry` = 27219;
