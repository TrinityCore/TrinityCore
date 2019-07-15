-- 
DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (57006, 57015, 57018, 57007, 57008, 57009, 57010, 57011);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionType`, `OptionNpcFlag`, `OptionBroadcastTextID`) VALUES
(57015, 0, 0, "Yes I checked, I'm missing the top piece!", 1, 1, 11778),
(57015, 1, 0, "Yes I checked, I'm missing the left piece!", 1, 1, 11780),
(57006, 0, 0, "I lost Lord Valthalak's Amulet!", 1, 1, 11773),
(57006, 1, 0, "I lost a piece of Lord Valthalak's Amulet!", 1, 1, 11776),
(57006, 2, 0,"I've misplaced the Brazier of Beckoning!", 1, 1, 11784),
(57006, 3, 0,"Bodley, tell me what's going on.", 1, 1, 11915),
(57018, 0, 0,"Yes, please summon it back!", 1, 1, 11786),
(57007, 0, 0,"You were telling me about The Veiled Blade and how you took the wrong mission.", 1, 1, 11917),
(57008, 0, 0,"No, no, please continue... it's just that the air up here is so, um, smoky.", 1, 1, 11919),
(57009, 0, 0,"Please continue, Bodley.", 1, 1, 11921),
(57010, 0, 0,"I thought you were almost done?", 1, 1, 11923),
(57011, 0, 0,"What happened to your mercenary company, The Veiled Blade?", 1, 1, 11925);

DELETE FROM `gossip_menu_option_action` WHERE `MenuId` IN (57006, 57015, 57018, 57007, 57008, 57009, 57010, 57011);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES 
(57015, 0, 57016, 0),
(57015, 1, 57017, 0),
(57006, 0, 57014, 0),
(57006, 1, 57015, 0),
(57006, 2, 57018, 0),
(57006, 3, 57007, 0),
(57018, 0, 57019, 0),
(57007, 0, 57008, 0),
(57008, 0, 57009, 0),
(57009, 0, 57010, 0),
(57010, 0, 57011, 0),
(57011, 0, 57012, 0);

UPDATE `creature_template` SET `gossip_menu_id`=57006, `AIName`='SmartAI', `npcflag`=3 WHERE `entry`=16033;
DELETE FROM `gossip_menu` WHERE `MenuId` BETWEEN 57006 AND 57019;
INSERT INTO `gossip_menu` (`MenuId`,`TextId`) VALUES (57006,50002),(57007,50003),(57008,50004),(57009,50005),(57010,50006),(57011,50007),(57012,50008),(57006,50009),(57014,50010),(57015,50011),(57016,50012),(57017,50013),(57018,50014),(57019,50015);

DELETE FROM `npc_text` WHERE `ID` BETWEEN 50002 AND 50015;
INSERT INTO `npc_text` (`ID`, `Probability0`, `BroadcastTextID0`, `VerifiedBuild`) VALUES 
(50002, 1, 11772, 0),
(50003, 1, 11916, 0),
(50004, 1, 11918, 0),
(50005, 1, 11920, 0),
(50006, 1, 11922, 0),
(50007, 1, 11924, 0),
(50008, 1, 11926, 0),
(50009, 1, 11830, 0),
(50010, 1, 11774, 0),
(50011, 1, 11777, 0),
(50012, 1, 11779, 0),
(50013, 1, 11781, 0),
(50014, 1, 11785, 0),
(50015, 1, 11787, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=16033 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16033, 0, 0, 0, 62, 0, 100, 0, 57015, 0, 0, 0, 11, 27544, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bodley - On Gossip Select - Cast Add Item Left'),
(16033, 0, 1, 0, 62, 0, 100, 0, 57015, 1, 0, 0, 11, 27542, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bodley - On Gossip Select - Cast Add Item Top'),
(16033, 0, 2, 0, 62, 0, 100, 0, 57018, 0, 0, 0, 11, 27566, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bodley - On Gossip Select - Cast Add Item Brasero'),
(16033, 0, 3, 0, 62, 0, 100, 0, 57006, 3, 0, 0, 11, 27537, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bodley - On Gossip Select - Cast Add Item Amulette');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (57006,57015);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (57006);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15, 57006, 1, 0, 0, 8, 0, 8966, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57006, 1, 0, 0, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57006, 1, 0, 0, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57006, 1, 0, 1, 8, 0, 8967, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57006, 1, 0, 1, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57006, 1, 0, 1, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57006, 1, 0, 2, 8, 0, 8968, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57006, 1, 0, 2, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57006, 1, 0, 2, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57006, 1, 0, 3, 8, 0, 8969, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57006, 1, 0, 3, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57006, 1, 0, 3, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57006, 1, 0, 4, 8, 0, 9015, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57006, 1, 0, 4, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57006, 1, 0, 4, 2, 0, 22047, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57006, 0, 0, 0, 8, 0, 8994, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57006, 0, 0, 0, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57006, 0, 0, 0, 2, 0, 22048, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57006, 2, 0, 0, 8, 0, 8995, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57006, 2, 0, 0, 2, 0, 22056, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57015, 1, 0, 0, 8, 0, 8966, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57015, 1, 0, 0, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57015, 1, 0, 0, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57015, 1, 0, 1, 8, 0, 8967, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57015, 1, 0, 1, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57015, 1, 0, 1, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57015, 1, 0, 2, 8, 0, 8968, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57015, 1, 0, 2, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57015, 1, 0, 2, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57015, 1, 0, 3, 8, 0, 8969, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57015, 1, 0, 3, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57015, 1, 0, 3, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57015, 0, 0, 4, 8, 0, 9015, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57015, 0, 0, 4, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57015, 0, 0, 4, 2, 0, 22047, 1, 0, 1, 0, '', 'Requires Missing Item'),
(14, 57006, 50009, 0, 0, 8, 0, 8997, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(14, 57006, 50009, 0, 1, 8, 0, 8998, 0, 0, 0, 0, '', 'Requires Quest Rewarded'); 
