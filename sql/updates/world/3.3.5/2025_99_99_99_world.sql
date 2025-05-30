-- SM: Move Herod summons to database
-- To-do: maybe random sniffed positions
SET @HEROD=3975;
SET @TRAINEE=6575;
DELETE FROM `creature_summon_groups` WHERE `summonerId`=@HEROD AND `entry`=@TRAINEE;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000),
(@HEROD, 0, 0, @TRAINEE, 1939.18, -431.58, 17.09, 6.22, 6, 600000);

-- I don't think this ever had any waypoints, but only movementId in creature_template
DELETE FROM `script_waypoint` WHERE `entry`=@TRAINEE;

-- Shoud all of them say texts ?
DELETE FROM `creature_text` WHERE `CreatureID`=@TRAINEE;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@TRAINEE,0,0,"The master has fallen!  Avenge him, my brethren!",14,0,100,0,0,0,2842,0,"Scarlet Trainee");

UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName`='' WHERE `entry`=@TRAINEE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@TRAINEE AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@TRAINEE, 0, 0, 0, 54, 0, 100, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Scarlet Trainee - On Just Spawned - Say Line 0"),
(@TRAINEE, 0, 1, 0, 25, 0, 100, 2, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 1965.09, -431.607, 6.26076, 0, "Scarlet Trainee - On Reset - Move to pos");
