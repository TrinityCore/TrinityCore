-- 
UPDATE `creature_template` SET `gossip_menu_id`=230 WHERE `entry`=6669;
DELETE FROM `gossip_menu` WHERE `MenuID` IN (21208,230) AND `TextID` IN (718,758);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES (230,718),(230,758);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=230 AND `OptionID`=0;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES 
(230, 0, 0, 'Turn the key to start the machine.', 2703, 1, 1, 0, 0, 0, 0, '', 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=230;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=230;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=6669;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 230, 0, 0, 0, 9, 0, 2078, 0, 0, 0, 0, 0, '', 'Show gossip option if player has quest 2078 but not complete'),
(15, 230, 0, 0, 0, 2, 0, 7442, 1, 0, 0, 0, 0, '', 'Show gossip option if player has item 7442'),
(22, 11, 6669, 0, 0, 23, 1, 452, 0, 0, 1, 0, 0, '', 'The Threshwackonator 4100 SAI condition to despawns if in the wrong area'),
(14, 230, 758, 0, 0, 9, 0, 2078, 0, 0, 0, 0, 0, '', 'Show gossip text if player has quest 2078 but not complete'),
(14, 230, 758, 0, 0, 2, 0, 7442, 1, 0, 0, 0, 0, '', 'Show gossip text if player has item 7442');

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE  `entry`=6669;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6669 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(6669,0,0,1,62,0,100,0,230,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'The Threshwackonator 4100 - On Gossip Option Selected - Close Gossip'),
(6669,0,1,2,61,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'The Threshwackonator 4100 - On Gossip Option Selected - Set NPC Flags'),
(6669,0,2,3,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'The Threshwackonator 4100 - On Gossip Option Selected - Say Line 0'),
(6669,0,3,4,61,0,100,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'The Threshwackonator 4100 - On Gossip Option Selected - Follow Invoker'),
(6669,0,4,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'The Threshwackonator 4100 - On Gossip Option Selected - Set Phase 1'),
(6669,0,5,6,75,0,100,1,0,6667,5,0,1,0,0,0,0,0,0,19,6667,0,0,0.0,0.0,0.0,0.0,'The Threshwackonator 4100 - On Creature 6667 within 5 yards - Say Line 0 on creature 6667'),
(6669,0,6,7,61,0,100,1,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'The Threshwackonator 4100 - On Creature 6667 within 5 yards - Set Home Position'),
(6669,0,7,8,61,0,100,1,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'The Threshwackonator 4100 - On Creature 6667 within 5 yards - Set hostile'),
(6669,0,8,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'The Threshwackonator 4100 - On Creature 6667 within 5 yards - Set Phase 1'),
(6669,0,9,0,1,3,100,1,300000,300000,0,0,41,0,15,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'The Threshwackonator 4100 - OOC (Phase 3) - Despawn after 5 minutes'),
(6669,0,10,0,1,3,100,1,3000,3000,0,0,41,0,15,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'The Threshwackonator 4100 - OOC (Phase 3) - Despawn after 3 Secs');
