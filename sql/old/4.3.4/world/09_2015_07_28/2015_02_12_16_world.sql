UPDATE `npc_text` SET `BroadcastTextID0`=38980 WHERE `ID`=15486;
DELETE FROM `gossip_menu` WHERE `entry`=11133 AND `text_id`=15486;
INSERT INTO `gossip_menu` (`entry`, `text_id`)  VALUES (11133,15486);
DELETE FROM `gossip_menu_option` WHERE `menu_id` = 11133;
INSERT INTO `gossip_menu_option` (`menu_id`, id, option_icon, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`) VALUES 
(11133, 0, 0, 'You''re not hideous, Lilian... you''re one of us.  Here, look in this mirror, see for yourself.', 38981, 1, 1);

-- Lilian Voss SAI
SET @ENTRY := 38910;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,1,100,0,11133,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Run Script (Phase 1)"),
(@ENTRY,0,1,8,61,1,100,0,11133,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Close Gossip (Phase 1)"),
(@ENTRY,0,2,3,62,2,100,0,11133,0,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Run Script (Phase 2)"),
(@ENTRY,0,3,9,61,2,100,0,11133,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Close Gossip (Phase 2)"),
(@ENTRY,0,4,0,25,0,100,0,0,0,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Reset - Set Emote State 431"),
(@ENTRY,0,5,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Reset - Set Event Phase 1"),
(@ENTRY,0,6,0,40,0,100,0,11,@ENTRY*100+00,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Waypoint 11 Reached - Set Emote State 431"),
(@ENTRY,0,7,0,40,0,100,0,11,@ENTRY*100+01,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Waypoint 11 Reached - Set Emote State 431"),
(@ENTRY,0,8,0,61,0,100,0,11133,0,0,0,85,73210,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Invoker Cast 'Show Mirror' (Phase 1)"),
(@ENTRY,0,9,0,61,0,100,0,11133,0,0,0,85,73210,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lilian Voss - On Gossip Option 0 Selected - Invoker Cast 'Show Mirror' (Phase 1)");

DELETE FROM `creature_text` WHERE `entry`=38910 ;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(38910, 0, 0, 'You don''t understand... I CAN''T be undead! Not me, not now...', 12, 0, 100, 22, 0, 0, 'Lilian', 38982);

-- Actionlist SAI
SET @ENTRY := 3891000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,17,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Set Emote State 26"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,2000,2000,33,38910,0,0,0,0,0,17,0,30,0,0,0,0,0,"Lilian Voss - On Script - Quest Credit 'The Truth of the Grave'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,53,1,3891000,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Start Waypoint"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Set Event Phase 2");

-- Actionlist SAI
SET @ENTRY := 3891001;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,17,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Set Emote State 26"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,2000,2000,33,38910,0,0,0,0,0,17,0,30,0,0,0,0,0,"Lilian Voss - On Script - Quest Credit 'The Truth of the Grave'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,53,1,3891001,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Start Waypoint"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lilian Voss - On Script - Set Event Phase 1");

DELETE FROM `waypoints` WHERE entry=3891000;
INSERT INTO `waypoints`(entry, pointid, position_x, position_y, position_z) VALUES
(3891000, 1, 1857.42, 1561.47, 99.079),
(3891000, 2, 1864.89, 1574.94, 99.0361),
(3891000, 3, 1868.91, 1575.56, 97.5441),
(3891000, 4, 1875.28, 1574.12, 94.314),
(3891000, 5, 1875.91, 1572.36, 94.314),
(3891000, 6, 1873, 1570.42, 94.314),
(3891000, 7, 1868.25, 1568.28, 94.314),
(3891000, 8, 1864.41, 1567.87, 94.314),
(3891000, 9, 1861.8, 1563.51, 94.3124),
(3891000, 10, 1860.59, 1558.04, 94.782),
(3891000, 11, 1857.21, 1555.61, 94.7926);

DELETE FROM `waypoints` WHERE entry=3891001;
INSERT INTO `waypoints`(entry, pointid, position_x, position_y, position_z) VALUES
(3891001, 11, 1854.83, 1555.63, 99.07),
(3891001, 10, 1857.42, 1561.47, 99.079),
(3891001, 9, 1864.89, 1574.94, 99.0361),
(3891001, 8, 1868.91, 1575.56, 97.5441),
(3891001, 7, 1875.28, 1574.12, 94.314),
(3891001, 6, 1875.91, 1572.36, 94.314),
(3891001, 5, 1873, 1570.42, 94.314),
(3891001, 4, 1868.25, 1568.28, 94.314),
(3891001, 3, 1864.41, 1567.87, 94.314),
(3891001, 2, 1861.8, 1563.51, 94.3124),
(3891001, 1, 1860.59, 1558.04, 94.782);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11133;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,11133,0,0,9,24961,0,0,0,'','Show gossip if player has Quest: the-truth-of-the-grave');
