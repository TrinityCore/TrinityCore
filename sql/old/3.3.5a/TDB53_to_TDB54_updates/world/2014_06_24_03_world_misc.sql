--
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry` =26570;
UPDATE `creature` SET `spawndist`=20, `MovementType`=1 WHERE `id` =26570;

DELETE FROM `smart_scripts` WHERE `entryorguid` =26570;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26570, 0, 0, 1, 8,  0, 100, 0, 47214, 0, 0, 0, 11, 47208, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Famished Scourge Troll - On Spell Hit Burninate - Give Quest Credit'),
(26570, 0, 1, 2,61,  0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Famished Scourge Troll - Linked with Previous Event - Die'),
(26570, 0, 2, 0,61,  0, 100, 0, 0, 0, 0, 0, 41, 20000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Famished Scourge Troll - Linked with Previous Event - Despawn After 20 seconds'),
(26570, 0, 3, 0,11,  0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Famished Scourge Troll - On Spawn - Set Run');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=9416;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(9416, 0, 0, 'I need some more of your fine grog, Mack.', 25821, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN(9416);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 9416, 0, 0, 0, 9, 0, 12038, 0, 0, 0, 0, 0, '', 'Gossip Option requires Seared Scourge Taken'),
(15, 9416, 0, 0, 0, 2, 0, 35908, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Macks Dark Grog'),
(15, 9416, 0, 0, 1, 9, 0, 12029, 0, 0, 0, 0, 0, '', 'Gossip Option requires Seared Scourge Taken'),
(15, 9416, 0, 0, 1, 2, 0, 35908, 1, 0, 1, 0, 0, '', 'Gossip Option requires Player does not have Macks Dark Grog');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(26604);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(26604) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26604,0,0,1,62,0,100,0,9416,0,0,0,85,47244,2,0,0,0,0,7,0,0,0,0,0,0,0,'Mack Fearsen - On Gossip Option 0 Selected - Invoker cast Create Macks Dark Grog'),
(26604,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Mack Fearsen - Link - Close Gossip'),
(26604,0,2,0,1,0,100,0,10000,10000,90000,90000,1,0,10000,0,0,0,0,1,0,0,0,0,0,0,0,'Mack Fearsen - On OOC LOS - Say Line 0'),
(26604,0,3,0,52,0,100,0,0,26604,0,0,1,1,10000,0,0,0,0,1,0,0,0,0,0,0,0,'Mack Fearsen - On Text Over line 0 - Say Line 1'),
(26604,0,4,0,52,0,100,0,1,26604,0,0,1,2,10000,0,0,0,0,1,0,0,0,0,0,0,0,'Mack Fearsen - On Text Over line 1 - Say Line 2');

DELETE FROM `creature_text` WHERE `entry`=26604;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(26604, 0, 0, 'Shcourged trooolls roashting....', 12, 0, 100, 0, 0, 0, 'Mack Fearsen', 27290),
(26604, 1, 0, '...on an open fire.....', 12, 0, 100, 0, 0, 0, 'Mack Fearsen', 27291),
(26604, 2, 0, 'That''s it! Far as I got... Whatd''ya think?', 12, 0, 100, 0, 0, 0, 'Mack Fearsen', 27292);
