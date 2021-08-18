-- Icemist Warrior
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144|512|256) WHERE `entry` = 26772;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 26772 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26772,0,0,0,11,0,100,0,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Icemist Warrior - On Respawn - Add Flags Immune To Players & Immune To NPC's"),
(26772,0,1,0,11,0,100,0,0,0,0,0,0,11,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Icemist Warrior - On Respawn - Cast 'Permament Feign Death'"),
(26772,0,2,3,8,0,100,0,47378,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Icemist Warrior - On Spellhit 'Glory of the Ancestors' - Remove Flags Immune To Players & Immune To NPC's"),
(26772,0,3,4,61,0,100,0,0,0,0,0,0,28,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Icemist Warrior - On Spellhit 'Glory of the Ancestors' - Remove Aura 'Permament Feign Death'"),
(26772,0,4,0,61,0,100,0,0,0,0,0,0,91,257,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Icemist Warrior - On Spellhit 'Glory of the Ancestors' - Set Bytes 1"),
(26772,0,5,0,38,0,100,0,1,1,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Icemist Warrior - On Data Set 1 1 - Delayed Despawn");

-- Crazed Mana-Surge
UPDATE `creature_template` SET `unit_flags` = 32832 WHERE `entry` IN (26737,30519);

DELETE FROM `creature` WHERE `guid` = 131139 AND `id` = 26737;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(131139,26737,576,0,0,3,1,0,0,527.551025390625,-9.8988189697265625,-14.9401721954345703,0.03490658476948738,3600,0,0,37164,0,0,0,0,0,'',0);

DELETE FROM `creature_addon` WHERE `guid` = 131139;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(131139,0,0,0,1,0,0,"29266");

UPDATE `creature` SET `unit_flags` = 33588032, `dynamicflags` = 0 WHERE `guid` IN (126511,126512,126513,126514,126515,126516,126520,126521,131139) AND `id` = 26737;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 26737 AND `source_type` = 0 AND `id` IN (5,6);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 26737 AND `SourceId` = 0;

-- Crazed Mana-Wyrm
UPDATE `creature` SET `unit_flags` = 33588032, `dynamicflags` = 0 WHERE `guid` IN (126587,126588) AND `id` = 26761;

-- Azure Skyrazor
UPDATE `creature` SET `unit_flags` = 33588032, `dynamicflags` = 0 WHERE `guid` IN (126505,126506) AND `id` = 26736;

-- Azure Enforcer
UPDATE `creature` SET `wander_distance` = 0, `MovementType` = 0, `unit_flags` = 33588032, `dynamicflags` = 0 WHERE `guid` IN (126483,126484,126485,126492) AND `id` = 26734;
DELETE FROM `creature_addon` WHERE `guid` IN (126483,126484,126485,126492);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(126483,0,0,0,1,0,0,"29266"),
(126484,0,0,0,1,0,0,"29266"),
(126485,0,0,0,1,0,0,"29266"),
(126492,0,0,0,1,0,0,"29266");

-- Drom Frostgrip
UPDATE `creature` SET `npcflag` = 0, `unit_flags` = 0 WHERE `id` = 29751;

-- Darkspear Dragon Hunter
UPDATE `creature` SET `unit_flags` = 33536, `dynamicflags` = 0 WHERE `guid` IN (203380,203381,203382,203383,203384,203385) AND `id` = 26870;
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 26870;

-- Emaciated Mammoth Bull
DELETE FROM `creature` WHERE `guid` = 100832 AND `id` = 26271;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(100832,26271,571,0,0,1,1,0,0,3306.67236328125, 34.595703125, 79.14014434814453125, 5.497786998748779296,300,0,0,9940,0,0,0,0,0,'',0);

DELETE FROM `creature_addon` WHERE `guid` = 100832;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(100832,0,0,0,1,0,0,"29266");

UPDATE `creature` SET `unit_flags` = 33536 WHERE `guid` IN (110812,110813,110814,110815,110816,110817,100832) AND `id` = 26271;
