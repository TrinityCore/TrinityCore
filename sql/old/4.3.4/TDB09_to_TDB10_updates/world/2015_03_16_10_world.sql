-- Navarax's Gambit
DELETE FROM `creature_text` WHERE `entry` IN (47842, 48487);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(47842, 0, 0, 'Your death will tell a different story!', 14, 0, 100, 0, 0, 0, 48370, 'Arch Druid Navarax to Player'),
(48487, 0, 0, 'What is going on in here?!', 12, 0, 100, 5, 0, 0, 48691, 'Whisperwind Druid to Player'),
(48487, 1, 0, 'The Arch Druid... how in the world...?', 12, 0, 100, 274, 0, 0, 48692, 'Whisperwind Druid to Player'),
(48487, 2, 0, 'I... I must tell the others. You should find Huntress Selura right away.', 12, 0, 100, 1, 0, 0, 48693, 'Whisperwind Druid to Player');

DELETE FROM `gossip_menu` WHERE (`entry`=12353 AND `text_id`=17477);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(12353, 17477); -- 47923

DELETE FROM `broadcast_text` WHERE `ID`=48373;
INSERT INTO `broadcast_text` (`ID`, `Language`, `MaleText`, `FemaleText`, `EmoteID0`, `EmoteID1`, `EmoteID2`, `EmoteDelay0`, `EmoteDelay1`, `EmoteDelay2`, `SoundId`, `Unk1`, `Unk2`, `VerifiedBuild`) VALUES
(48373, 0, 'Yes, my child?', '', 0, 0, 0, 0, 0, 0, 0, 0, 1, 19342); -- 48373

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=12398 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(12398, 0, 0, 'You''re accused of being a demon in disguise, Navarax... if that''s even your real name!', 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12398 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12398, 0, 0, 0, 9, 0, 28264, 0, 0, 0, 0, 0, '', 'Gossip Option requires quest not complete');

-- Arch Druid Navarax SAI
SET @ENTRY := 47842;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,12398,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Druid Navarax - On Gossip Option 0 Selected - Set Faction 14"),
(@ENTRY,0,1,4,61,0,100,0,12398,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Arch Druid Navarax - On Gossip Option 0 Selected - Start Attacking"),
(@ENTRY,0,2,0,25,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Druid Navarax - On Reset - Set Faction 35"),
(@ENTRY,0,3,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Druid Navarax - On Aggro - Say Line 0"),
(@ENTRY,0,4,7,61,0,100,0,12398,0,0,0,11,89515,2,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Druid Navarax - On Gossip Option 0 Selected - Cast 'Xaravan's Transformation'"),
(@ENTRY,0,5,0,0,0,100,0,1000,1000,5000,5000,11,36996,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arch Druid Navarax - In Combat - Cast 'Claw Swipe'"),
(@ENTRY,0,6,0,6,0,100,0,0,0,0,0,12,48487,6,0,0,0,0,8,0,0,0,6050.23,-934.345,455.853,1.15377,"Arch Druid Navarax - On Just Died - Summon Creature 'Whisperwind Druid'"),
(@ENTRY,0,7,0,61,0,100,0,12398,0,0,0,3,48160,0,0,0,0,0,0,0,0,0,0,0,0,0,"Arch Druid Navarax - On Gossip Option 0 Selected - Morph To Model 10189"),
(@ENTRY,0,8,0,0,0,100,1,1000,1000,0,0,3,48160,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Druid Navarax - In Combat - Morph To Creature Xaravan");

-- Whisperwind Druid SAI
SET @ENTRY := 48487;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,53,1,48487,0,0,0,0,1,0,0,0,0,0,0,0,"Whisperwind Druid - On Just Summoned - Start Waypoint"),
(@ENTRY,0,1,2,40,0,100,0,1,48487,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Whisperwind Druid - On Waypoint 1 Reached - Run Script"),
(@ENTRY,0,2,0,61,0,100,0,1,48487,0,0,54,12000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whisperwind Druid - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,40,0,100,0,3,48487,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whisperwind Druid - On Waypoint 3 Reached - Despawn In 2000 ms");

-- Actionlist SAI
SET @ENTRY := 4848700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 1"),
(@ENTRY,9,2,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 2");

DELETE FROM `waypoints` WHERE `entry`=48487;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(48487, 1, 6053.084473, -927.829712, 455.742828, 'Whisperwind Druid'),
(48487, 2, 6050.680664, -933.536255, 455.892639, 'Whisperwind Druid'),
(48487, 3, 6054.942383, -934.681335, 455.893829, 'Whisperwind Druid');
