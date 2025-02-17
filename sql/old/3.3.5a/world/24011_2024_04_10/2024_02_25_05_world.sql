-- Tavara should spawn with a HP pool of 68/102
UPDATE `creature` SET `curhealth`=68 WHERE `id`=17551;

-- Blizz like respawn time for "Tavara" (Timed it on WotLK Classic)
UPDATE `creature` SET `spawntimesecs`=10 WHERE `ID`=17551;

-- Tavara Script after she gets healed during "Help Tavara" (9586)
DELETE FROM `creature_text` WHERE `CreatureID`=17551;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17551,0,0,"Thank you, kind $gsir:lady;!",12,35,100,2,0,0,17578,0,"Tavara"),
(17551,1,0,"Please tell Guvan that I'll be fine, thanks to you.",12,35,100,3,0,0,14224,0,"Tavara");

DELETE FROM `waypoints` WHERE `entry`=17551;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(17551,1,-4101.234,-12806.457,6.095,'Tavara'),
(17551,2,-4073.742,-12840.701,1.473,'Tavara'),
(17551,3,-4071.070,-12850.257,2.570,'Tavara'),
(17551,4,-4074.439,-12862.463,2.199,'Tavara');

DELETE FROM `smart_scripts` WHERE `entryorguid`=17551 AND `event_type` IN (8,40);
DELETE FROM `smart_scripts` WHERE `entryorguid`=1755100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17551,0,0,0,40,0,100,0,4,17551,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tavara - On Waypoint 4 Reached - Despawn"),
(17551,0,1,0,8,0,100,0,2050,0,0,0,0,33,17551,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Tavara - On Spellhit - Give Quest Credit"),
(17551,0,2,0,8,0,100,0,2052,0,0,0,0,33,17551,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Tavara - On Spellhit - Give Quest Credit"),
(17551,0,3,0,8,0,100,0,59544,0,0,0,0,33,17551,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Tavara - On Spellhit - Give Quest Credit"),
(17551,0,4,0,8,0,100,0,139,0,0,0,0,33,17551,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Tavara - On Spellhit - Give Quest Credit"),
(17551,0,5,0,8,0,100,1,2050,0,0,0,0,80,1755100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tavara - On Spellhit - Run Script"),
(17551,0,6,0,8,0,100,1,2052,0,0,0,0,80,1755100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tavara - On Spellhit - Run Script"),
(17551,0,7,0,8,0,100,1,59544,0,0,0,0,80,1755100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tavara - On Spellhit - Run Script"),
(17551,0,8,0,8,0,100,1,139,0,0,0,0,80,1755100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tavara - On Spellhit - Run Script"),
(1755100,9,0,0,0,0,100,0,500,500,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tavara - On Script - Remove Flag Standstate 'Kneel'"),
(1755100,9,1,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Tavara - On Script - Set Orientation Invoker"),
(1755100,9,2,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Tavara - On Script - Say Line 0"),
(1755100,9,3,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tavara - On Script - Say Line 1"),
(1755100,9,4,0,0,0,100,0,4000,4000,0,0,0,53,1,17551,0,0,0,2,1,0,0,0,0,0,0,0,0,"Tavara - On Script - Start Waypoint");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=17551;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,2,17551,0,0,47,0,9586,10,0,0,0,0,"","Smart Event 1 for creature Tavara only executes if player has quest 'Help Tavara' in progress or completed"),
(22,3,17551,0,0,47,0,9586,10,0,0,0,0,"","Smart Event 2 for creature Tavara only executes if player has quest 'Help Tavara' in progress or completed"),
(22,4,17551,0,0,47,0,9586,10,0,0,0,0,"","Smart Event 3 for creature Tavara only executes if player has quest 'Help Tavara' in progress or completed"),
(22,5,17551,0,0,47,0,9586,10,0,0,0,0,"","Smart Event 4 for creature Tavara only executes if player has quest 'Help Tavara' in progress or completed"),
(22,6,17551,0,0,47,0,9586,10,0,0,0,0,"","Smart Event 5 for creature Tavara only executes if player has quest 'Help Tavara' in progress or completed"),
(22,7,17551,0,0,47,0,9586,10,0,0,0,0,"","Smart Event 6 for creature Tavara only executes if player has quest 'Help Tavara' in progress or completed"),
(22,8,17551,0,0,47,0,9586,10,0,0,0,0,"","Smart Event 7 for creature Tavara only executes if player has quest 'Help Tavara' in progress or completed"),
(22,9,17551,0,0,47,0,9586,10,0,0,0,0,"","Smart Event 8 for creature Tavara only executes if player has quest 'Help Tavara' in progress or completed");
