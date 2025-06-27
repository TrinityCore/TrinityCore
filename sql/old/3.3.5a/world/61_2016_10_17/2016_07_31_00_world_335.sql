-- SmartAI script for creature entry 9528 Arathandris Silversky and 9529 Maybess Riverbreeze
SET @Arathandris := 9528;
SET @Riverbreeze := 9529;

UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (@Arathandris,@Riverbreeze);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Arathandris,@Riverbreeze) AND `source_type`= 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Arathandris,0, 0,1, 62,0,100,0, 2208,0,0,0, 72,    0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Arathandris Silversky - On Gossip 2208 Option 0 selected - Close Gossip'),
(@Arathandris,0, 1,2, 61,0,100,0,    0,0,0,0, 11,15120,0,0,0,0,0,7,0,0,0,0,0,0,0,"Arathandris Silversky - On Gossip 2208 Option 0 selected - Cast 'Cenarion Beacon'"),
(@Arathandris,0, 2,0, 61,0,100,0,    0,0,0,0,  1,    0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Arathandris Silversky - On Gossip 2208 Option 0 Selected - Say Line 0'),
(@Riverbreeze,0, 0,1, 62,0,100,0,21400,0,0,0, 72,    0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maybess Riverbreeze - On Gossip 21400 Option 0 Selected - Close Gossip'),
(@Riverbreeze,0, 1,2, 61,0,100,0,    0,0,0,0, 11,15120,0,0,0,0,0,7,0,0,0,0,0,0,0,"Maybess Riverbreeze - On Gossip 21400 Option 0 Selected - Cast 'Cenarion Beacon'"),
(@Riverbreeze,0, 2,0, 61,0,100,0,    0,0,0,0,  1,    0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Maybess Riverbreeze - On Gossip 21400 Option 0 Selected - Say Line 0');

-- insert missing gossip_menu entries
DELETE FROM `gossip_menu` WHERE `entry` IN (2209, 21401) AND `text_id` IN (3046, 3047);
INSERT INTO `gossip_menu` (`entry`,`text_id`,`VerifiedBuild`) VALUES
(2209,  3046, 0),
(21401, 3047, 0);

UPDATE `gossip_menu_option` SET `action_menu_id` = 2209 WHERE `menu_id` = 2208 AND `OptionBroadcastTextID`= 5384;
UPDATE `gossip_menu_option` SET `action_menu_id`= 21401 WHERE `menu_id`= 21400 AND `OptionBroadcastTextID`= 5384;

DELETE FROM `creature_text` WHERE `entry` IN (@Arathandris,@Riverbreeze);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@Riverbreeze,0,0,'Here is a beacon for you, $n.  You must keep it in your possession if you are to find the corrupted items we will need.',12,1,100,25,5000,0,5244,0,'Arathandris Silversky - SAY_BEACON'),
(@Arathandris,0,0,'Here is a beacon for you, $n.  You must keep it in your possession if you are to find the corrupted items we will need.',12,7,100,25,5000,0,5245,0,'Arathandris Silversky - SAY_BEACON');

-- conditions for Arathandris Silversky's and Maybess Riverbreeze's gossip menus
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 21400 AND `SourceEntry` IN (2842,2843,2849);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14, 21400, 2842, 0, 0, 8, 0, 4102, 0, 0, 1, 0, 0, '', 'Maybess Riverbreeze - Show gossip text if player has not been rewarded quest 4102'),
(14, 21400, 2843, 0, 0, 6, 0,  469, 0, 0, 0, 0, 0, '', 'Maybess Riverbreeze - Show gossip text if player is alliance'),
(14, 21400, 2849, 0, 0, 8, 0, 4102, 0, 0, 0, 0, 0, '', 'Maybess Riverbreeze - Show gossip text if player has been rewarded quest 4102');

-- Correct some wrong quest IDs and NPC texts
UPDATE `conditions` SET `ConditionValue1`= 4101 WHERE `SourceGroup`= 2208 AND `ConditionValue1`= 3781;
UPDATE `conditions` SET `ConditionValue1`= 4102 WHERE `SourceGroup`= 21400 AND `ConditionValue1`= 3781;
UPDATE `conditions` SET `SourceEntry`= 2845 WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 2208 AND `SourceEntry`= 2848;
UPDATE `conditions` SET `SourceEntry`= 2848 WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 2208 AND `SourceEntry`= 2845 AND `ConditionValue1`= 4101;

-- Condition for source GOSSIP MENU OPTION condition type ITEM, item 11511 Cenarion Beacon
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup` IN (2208,21400) AND `SourceEntry`= 0 AND `SourceId`= 0 AND `NegativeCondition`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15, 2208,0,0,0, 2,0, 11511,1, 0,1,0,0,'','Do not show gossip menu 2208 option id 0 if player has 1 of Cenarion Beacon in bags or bank.'),
(15,21400,0,0,0, 2,0, 11511,1, 0,1,0,0,'','Do not show gossip menu 21400 option id 0 if player has 1 of Cenarion Beacon in bags or bank.');
