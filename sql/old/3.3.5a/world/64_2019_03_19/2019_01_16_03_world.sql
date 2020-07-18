-- Guard Captain Zorek (23728)
DELETE FROM `smart_scripts` WHERE `entryorguid`=23728 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2372801 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23728,0,1,0,62,0,100,0,8984,0,0,0,0,80,2372801,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Captain Zorek - On Quest Accepted - Action list'"),
(2372801,9,0,0,0,0,100,0,0,0,0,0,0,11,49845,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Captain Zorek - Action list - Cast 'Valgarde Gryphon'"),
(2372801,9,1,0,0,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Guard Captain Zorek - Action list - Close gossip"),
(2372801,9,2,0,0,0,100,0,1000,1000,0,0,0,86,63313,0,7,0,0,0,19,27886,0,0,0,0,0,0,0,"Guard Captain Zorek - Action list - cross cast ride");

DELETE FROM `gossip_menu_option` WHERE `MenuId`=8984 AND `OptionID`=0;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(8984, 0, 0, 'Take me to Lieutenant Icehammer, Zorek!', 31741, 1, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup`=8984;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,8984,0,0,0,28,0,11427,0,0,0,0,0,"","Show gossip option 8984 if quest 11427 taken");

DELETE FROM `vehicle_template_accessory` WHERE `entry`=27886;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(27886, 27887, 0, 1, "Valgarde Gryphon", 5, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 27886;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(27886,48365,1,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup` IN(27886);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`Comment`) VALUES
(18,27886,48365,0,31,0,3,27887,0,0,'Require npc for spellclick');

DELETE FROM `spell_target_position` WHERE `ID` IN (49845);
INSERT INTO `spell_target_position` (`ID`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`) VALUES
(49845, 571, 603.6032, -5034.397, 1.1338, 0.694764);

-- Valgarde Gryphon (27886)
SET @GRYPHON:= 27886;
UPDATE `creature_template` SET `AIName`='SmartAI', `speed_run`=1.14286 WHERE `entry`=@GRYPHON;
DELETE FROM `creature_template_movement` WHERE `CreatureId`=@GRYPHON;
INSERT INTO `creature_template_movement` (`CreatureID`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(@GRYPHON,0,0,2,0);
DELETE FROM `smart_scripts` WHERE `entryorguid`=27886 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GRYPHON,0,0,1,27,0,100,0,0,0,0,0,0,53,1,@GRYPHON,0,0,0,0,1,0,0,0,0,0,0,0,0,"Valgarde Gryphon - On Passenger Boarded - Start Waypoint"),
(@GRYPHON,0,1,2,61,0,100,0,0,0,0,0,0,11,49303,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Valgarde Gryphon - On Passenger Boarded - cast fly"),
(@GRYPHON,0,2,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,19,27887,0,0,0,0,0,0,0,"Valgarde Gryphon - On Passenger Boarded - Say text"),
(@GRYPHON,0,3,4,40,0,100,0,15,@GRYPHON,0,0,0,11,45472,0,0,0,0,0,21,5,0,0,0,0,0,0,0,"Valgarde Gryphon - On Waypoint 15 Reached - Cast 'Parachute"),
(@GRYPHON,0,4,5,61,0,100,0,0,0,0,0,0,11,62539,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Valgarde Gryphon - On Waypoint 15 Reached - Dismount"),
(@GRYPHON,0,5,0,61,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,19,27887,0,0,0,0,0,0,0,"Valgarde Gryphon - On Waypoint 15 Reached - say text"),
(@GRYPHON,0,6,0,1,0,100,0,5000,5000,5000,5000,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Valgarde Gryphon - Ooc - despawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN(@GRYPHON);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, @GRYPHON, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Valgarde Gryphon - Only run SAI if invoker is player'),
(22, 7, @GRYPHON, 0, 0, 1, 1, 63313, 0, 0, 1, 0, 0, '', 'Valgarde Gryphon - Only run SAI no aura 63313');

DELETE FROM `creature_text` WHERE `CreatureID`=27887;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(27887,0,0,"Off we go!",12,7,100,0,0,0,27225,0,"Valgarde Gryphon Rider"),
(27887,1,0,"Here ya go, friend! Icehammer is right inside that vrykul building! Give 'em hell!",12,7,100,0,0,0,27228,0,"Valgarde Gryphon Rider");

DELETE FROM `waypoints` WHERE `entry`=27886;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@GRYPHON, 1, 611.694153, -5049.680176, 24.236082, 'Valgarde Gryphon'),
(@GRYPHON, 2, 645.473206, -5088.019531, 30.966393, 'Valgarde Gryphon'),
(@GRYPHON, 3, 712.810547, -5091.938965, 35.150776, 'Valgarde Gryphon'),
(@GRYPHON, 4, 943.164795, -5001.226074, 51.646461, 'Valgarde Gryphon'),
(@GRYPHON, 5, 1043.208984, -4975.551270, 42.536732, 'Valgarde Gryphon'),
(@GRYPHON, 6, 1105.994263, -4981.366699, 44.616421, 'Valgarde Gryphon'),
(@GRYPHON, 7, 1168.691772, -4956.152344, 43.580040, 'Valgarde Gryphon'),
(@GRYPHON, 8, 1188.284546, -4949.069336, 43.889103, 'Valgarde Gryphon'),
(@GRYPHON, 9, 1224.690918, -5034.330566, 45.493435, 'Valgarde Gryphon'),
(@GRYPHON, 10, 1284.036011, -5064.889160, 70.936272, 'Valgarde Gryphon'),
(@GRYPHON, 11, 1299.864014, -5123.960449, 92.312981, 'Valgarde Gryphon'),
(@GRYPHON, 12, 1268.888550, -5172.307129, 125.225029, 'Valgarde Gryphon'),
(@GRYPHON, 13, 1204.625854, -5202.031250, 162.438080, 'Valgarde Gryphon'),
(@GRYPHON, 14, 1264.150391, -5293.074707, 194.687225, 'Valgarde Gryphon'),
(@GRYPHON, 15, 1250.924927, -5318.654297, 202.334183, 'Valgarde Gryphon'),
(@GRYPHON, 16, 1100.08349, -5329.9238, 227.26312, 'Valgarde Gryphon');
