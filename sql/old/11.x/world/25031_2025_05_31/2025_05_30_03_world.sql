DELETE FROM `areatrigger_scripts` WHERE `entry` = 6200;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6200, 'at_abyssal_depths_whirlpool_entrance');

UPDATE `creature_template` SET `faction`=14, `speed_walk`=2.799999952316284179, `speed_run`=1, `unit_flags`=0x2000000, `unit_flags3`=0x0, `VehicleId`=1023, `AIName`='', `ScriptName`='npc_abyssal_depths_whirlpool_vehicle' WHERE `entry`=44373; -- Whirlpool Vehicle

DELETE FROM `creature_template_addon` WHERE `entry` = 44373;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(44373, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- 44373 (Whirlpool Vehicle)

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000 WHERE (`Entry`=44373 AND `DifficultyID`=0); -- 44373 (Whirlpool Vehicle) - Floating

-- fix whirlpool vehicle spawn orientation
UPDATE `spell_target_position` SET `Orientation` = 4.939281940460205078 WHERE `ID` = 82891;

-- Path 1 for Whirlpool Vehicle
SET @ENTRY := 44373;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x2, 21, 'Whirlpool Vehicle - Scripted Path - Fly Under Whirlpool');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -5700, 5353, -1409.9166, NULL, 0);

-- fix Teleport Under Whirlpool orientation
UPDATE `spell_target_position` SET `Orientation` = 5.585050106048583984 WHERE `ID` = 82903;

-- fix Teleport to Vashj'ir orientation
UPDATE `spell_target_position` SET `Orientation` = 2.156670093536376953 WHERE `ID` = 85040;

UPDATE `gossip_menu_option` SET `GossipOptionID`=37688, `VerifiedBuild`=60822 WHERE (`MenuID`=12038 AND `OptionID`=0);

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 45514;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 45514 and `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45514, 0, 0, 01, '', 62, 0, 100, 0, 12038, 0, 0, 0, 0, '', 85, 85040, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wavespeaker Valoren - On Gossip Option 0 Selected - Cast \'Teleport to Vashj\'ir\'');
