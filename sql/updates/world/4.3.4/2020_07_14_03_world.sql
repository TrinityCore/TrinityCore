-- Throne of the Tides
UPDATE `creature_template_addon` SET `auras`= '95293' WHERE `entry` IN (51395, 51391);
UPDATE `creature_addon` SET `auras`= '95293' WHERE `guid` IN (254995, 254849);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (51395, 51391);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(51395, 0, 0, 1, 0),
(51391, 0, 0, 1, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (51391, 51395);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(51391, 95284, 1, 0),
(51395, 95285, 1, 0);

-- The Stonecore
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (51396, 51397);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(51396, 0, 0, 1, 0),
(51397, 0, 0, 1, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (340437, 340628);
INSERT INTO `creature_addon` (`guid`, `bytes1`, `auras`) VALUES
(340437, 50331648, '95299'),
(340628, 50331648, '95299');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (51396, 51397);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(51396, 95284, 1, 0),
(51397, 95285, 1, 0);

UPDATE `creature_template` SET `unit_flags`= 0, `flags_extra`= 0, `AIName`= 'NullCreatureAI' WHERE `entry` IN (51396, 51397);

-- Blackrock Caverns
UPDATE `creature_template` SET `VehicleId`= 1536, `unit_flags`= 0, `unit_flags2`= 67110912, `npcflag`= 0x01000000, `flags_extra`= 0 WHERE `entry`= 51340;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 51340;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(51340, 84965, 1, 1);

SET @ENTRY := 51340;
SET @GUID := -361878;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 27, 0, 100, 0, 0, 0, 0, 0, 11, 95210, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On passenger boarded (vehicle) - Self: Cast spell 95210 on Action invoker // ");

SET @GUID := -361877;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 27, 0, 100, 0, 0, 0, 0, 0, 11, 95012, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On passenger boarded (vehicle) - Self: Cast spell 95012 on Action invoker // ");


-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (95284, 95285, 95209, 95013) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 95284, 0, 0, 31, 0, 3, 51395, 0, 0, 0, '', 'Teleport - Target Throne of the Tides Teleporter'),
(13, 1, 95284, 0, 1, 31, 0, 3, 51397, 0, 0, 0, '', 'Teleport - Target Stonecore Teleporter'),
(13, 1, 95285, 0, 0, 31, 0, 3, 51391, 0, 0, 0, '', 'Teleport - Target Throne of the Tides Teleporter'),
(13, 1, 95285, 0, 1, 31, 0, 3, 51396, 0, 0, 0, '', 'Teleport - Target Stonecore Teleporter'),
(13, 1, 95209, 0, 1, 31, 0, 3, 51340, 361877, 0, 0, '', 'Twilight Portal - Target Twilight Portal'),
(13, 1, 95013, 0, 1, 31, 0, 3, 51340, 361878, 0, 0, '', 'Twilight Portal - Target Twilight Portal');

DELETE FROM `spell_target_position` WHERE `ID` IN (95284, 95285);

-- Spawn Groups
DELETE FROM `spawn_group_template` WHERE `groupId`= 434;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(434, 'Blackrock Caverns - Twilight Portals', 4);

DELETE FROM `instance_spawn_groups` WHERE `instanceMapId`= 645 AND `spawnGroupId`= 434;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(645, 2, 8, 434, 1);

DELETE FROM `spawn_group` WHERE `groupId`= 434;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(434, 0, 361878),
(434, 0, 361877);
