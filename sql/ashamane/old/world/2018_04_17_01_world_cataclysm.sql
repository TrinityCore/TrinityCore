UPDATE `creature_template` SET `gossip_menu_id` = 3679, `npcflag` = 1, `unit_flags` = 768 WHERE `entry` = 3679;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('3679','0','0','Lets Go!','0','1','1','25416');

SET @ENTRY := 3679;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,3679,0,0,0,33,3678,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");


DELETE FROM `creature_template_addon` WHERE (`entry`=225);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (225, 0, 0, 0, 1, 233, '');

DELETE FROM `creature_template_addon` WHERE (`entry`=226);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (226, 0, 0, 0, 1, 69, '');


UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 43862;


UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=43730; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=43730; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=43730);

UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=288; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=288; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=288);

UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 26760;
UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 26773;

UPDATE `quest_objectives` SET `Amount` = 10  WHERE `QuestID` = 26739;

UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 43049;
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 938;

DELETE FROM `creature_template_addon` WHERE (`entry`=52821);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (52821, 0, 0, 3, 1, 0, 78677);

-- Lashtail Hatchling SAI
SET @ENTRY := 42736;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,75,0,100,513,0,100018,30,1000,80,42736,2,0,0,0,0,1,0,0,0,0,0,0,0,""),
(@ENTRY,0,1,0,38,0,100,512,1,1,0,0,33,42742,0,0,0,0,0,21,25,0,0,0,0,0,0,""),
(@ENTRY,0,2,0,38,0,100,512,2,2,0,0,33,42742,0,0,0,0,0,21,25,0,0,0,0,0,0,""),
(@ENTRY,0,3,0,38,0,100,512,3,3,0,0,33,42742,0,0,0,0,0,21,25,0,0,0,0,0,0,""),
(@ENTRY,0,4,5,1,0,100,0,2000,2000,8000,10000,11,79714,0,0,0,0,0,21,20,0,0,0,0,0,0,""),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,11,82324,0,0,0,0,0,21,20,0,0,0,0,0,0,"");

DELETE FROM `creature_template_addon` WHERE (`entry`=7802);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (7802, 0, 0, 0, 1, 233, '');



UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 54586;
UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 52604;



UPDATE `creature_template` SET `gossip_menu_id`='43042' WHERE `entry`='43042';

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('43042','0','0','Lets Go!','0','1','1','29416');

UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 26697;

SET @ENTRY := 43042;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,43042,0,0,0,62,0,0,0,0,0,0,7,0,0,0,-13634,-66,37,0,"Teleport");


UPDATE `creature_template` SET `npcflag` = 128 WHERE `entry` = 2663;

replace  into `npc_vendor`(`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`,`OverrideGoldCost`,`type`,`BonusListIDs`,`PlayerConditionID`,`IgnoreFiltering`,`VerifiedBuild`) values (2663,1,59148,0,0,0,0,1,NULL,0,0,26141);

-- Mob SAI Quest ITEM Give
SET @ENTRY := 43505;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,11741,0,0,0,56,59147,1,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Add Item");

UPDATE `creature_template` SET `npcflag` = 129 WHERE `entry` = 2663;

replace  into `npc_vendor`(`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`,`OverrideGoldCost`,`type`,`BonusListIDs`,`PlayerConditionID`,`IgnoreFiltering`,`VerifiedBuild`) values (43505,1,59147,0,0,0,0,1,NULL,0,0,26141);





UPDATE `creature_template` SET `npcflag` = 3, `gossip_menu_id` = 2487 WHERE `entry` = 2487;
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('2487','0','0','Here it IS!','0','1','1','29416');


SET @ENTRY := 2487;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,2487,0,0,0,33,2487,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");




REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('11727','0','1','I hear you\'ve got some drinks I can buy, Slim.','0','1','1','29416');

-- Mob SAI Quest ITEM Give
SET @ENTRY := 2491;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,11727,0,0,0,56,59037,1,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Add Item");

UPDATE `creature_template` SET `npcflag` = 1,`gossip_menu_id` = 11727 WHERE `entry` = 2491;

replace  into `npc_vendor`(`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`,`OverrideGoldCost`,`type`,`BonusListIDs`,`PlayerConditionID`,`IgnoreFiltering`,`VerifiedBuild`) values (2491,1,59037,0,0,0,0,1,NULL,0,0,26141);



SET @ENTRY := 43377;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,83017,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Insect Swarm"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4700,11,78907,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Starfire"),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,15000,18000,11,79823,0,0,0,0,0,4,0,0,0,0,0,0,0,"Cast Starfall"),
(@ENTRY,0,3,0,62,0,100,0,11736,0,0,0,56,59035,1,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Add Item");


replace  into `npc_vendor`(`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`,`OverrideGoldCost`,`type`,`BonusListIDs`,`PlayerConditionID`,`IgnoreFiltering`,`VerifiedBuild`) values (43377,1,59035,0,0,0,0,1,NULL,0,0,26141);

SET @ENTRY := -204361;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,11711,0,0,0,33,43252,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,1,0,62,0,100,0,11711,1,0,0,33,43245,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");


UPDATE `creature_template` SET `KillCredit1` = 43252 WHERE `entry` = 43245;
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 43245;
UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 43245;

UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 26552;

replace  into `creature_queststarter`(`id`,`quest`) values (44084,26552);
replace  into `creature_questender`(`id`,`quest`) values (44084,26552);

SET @ENTRY := 44084;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,26552,0,0,0,15,26552,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Quest Add');


UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 26553;

replace  into `creature_queststarter`(`id`,`quest`) values (44084,26553);
replace  into `creature_questender`(`id`,`quest`) values (44084,26553);

UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 26554;

replace  into `creature_queststarter`(`id`,`quest`) values (44084,26554);
replace  into `creature_questender`(`id`,`quest`) values (44084,26554);


UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 26555;

replace  into `creature_queststarter`(`id`,`quest`) values (44084,26555);
replace  into `creature_questender`(`id`,`quest`) values (44084,26555);

UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 2546;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 2548;

UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 34884;

UPDATE `creature_template` SET `KillCredit1` = 45235 WHERE `entry` = 45239;
UPDATE `creature_template` SET `KillCredit1` = 44447 WHERE `entry` = 45240;
UPDATE `creature_template` SET `KillCredit1` = 43636 WHERE `entry` = 4505;
UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 26633;

UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 26662;
UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 26663;

SET @ENTRY := 49635;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,12511,0,0,0,62,0,0,0,0,0,0,7,0,0,0,1362,-1275,60,4,"Teleport");

DELETE FROM `creature_addon` WHERE (`guid`=212073);


UPDATE `creature_template` SET `unit_flags` = 32768, `type_flags` = 0 WHERE `entry` = 45235;

UPDATE `creature_template` SET `ScriptName` = "" WHERE `ScriptName` = "generic_creature";



-- Gnoll Escape (25867) quest script - квест на Открытие клеток
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 205157;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 205155;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 207428;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 205160;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 205159;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 205156;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 207427;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 44902;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (205157, 44902, 4490200,205155,207428,205160,205159,207427,205156);
REPLACE INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(205157, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(205157, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 44902, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(205157, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 44902, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(205155, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(205155, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 44902, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(205155, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 44902, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(207428, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(207428, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 44902, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(207428, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 44902, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(205160, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(205160, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 44902, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(205160, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 44902, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(205159, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(205159, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 44902, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(205159, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 44902, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(207427, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(207427, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 44902, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(207427, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 44902, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(205156, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(205156, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 44902, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(205156, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 44902, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(44902, 0, 0, 0, 38, 0, 100, 1, 1, 1, 0, 0, 80, 4490200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - on data set 1 1 - run actionlist (4490200)'),
(4490200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 44902, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - give quest credit (41410)'),
(4490200, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 46, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - run forward 10 yards'),
(4490200, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - despawn');



UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 44902;




-- Mob SAI GOSSIP Faction change
SET @ENTRY := 45162;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,11943,0,0,0,2,22,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Gossip - Change Faction"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Change Faction at 30% HP'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,33,45162,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Gossip - Quest credit");



DELETE FROM `gameobject` WHERE `id`=18972;

UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 27210;
UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 27210;
UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 27212;



UPDATE `creature_loot_template` SET `Chance` = 100 WHERE `Item` = 5847;

replace  into `creature_queststarter`(`id`,`quest`) values (23843,27183);
replace  into `creature_questender`(`id`,`quest`) values (23843,27183);

-- Grimtotem Breaker SAI
SET @ENTRY := 23592;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,15000,17000,11,43108,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Breaker - In Combat - Cast 'Bone Breaker'");

UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 23741;


-- Gnoll Escape (25867) quest script - квест на Открытие клеток
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 186287;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 23720;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (186287, 23720, 2372000);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(186287, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(186287, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 23720, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(186287, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 23720, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(23720, 0, 0, 0, 38, 0, 100, 1, 1, 1, 0, 0, 80, 2372000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - on data set 1 1 - run actionlist (2372000)'),
(2372000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 23720, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - give quest credit (41410)'),
(2372000, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 46, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - run forward 10 yards'),
(2372000, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - despawn');





SET @ENTRY := 38805;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,72925,0,0,0,33,38805,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");
UPDATE `creature_template` SET `faction` = 2316 WHERE `entry` = 38805;

DELETE FROM `creature_template_addon` WHERE (`entry`=38805);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (38805, 0, 0, 0, 1, 0, 84063);


SET @ENTRY := 38619;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,24934,0,0,0,62,1,0,0,0,0,0,7,0,0,0,-2161,-4085,21,1,'Teleport on Quest Add');

UPDATE `quest_objectives` SET `ObjectID` = 38661, `Amount` = 5  WHERE `QuestID` = 24939;

replace  into `creature_queststarter`(`id`,`quest`) values (107574,27241);
replace  into `creature_questender`(`id`,`quest`) values (4968,27241);

UPDATE `creature_template` SET `unit_flags` = 33554434 WHERE `entry` = 23751;
UPDATE `creature_template` SET `unit_flags` = 33554434 WHERE `entry` = 23752;
UPDATE `creature_template` SET `unit_flags` = 33554434 WHERE `entry` = 23753;

SET @ENTRY := 23751;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,42356,0,0,0,33,23751,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

SET @ENTRY := 23752;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,42356,0,0,0,33,23752,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

SET @ENTRY := 23753;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,42356,0,0,0,33,23753,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");


UPDATE `creature_template` SET `KillCredit1` = 23797 WHERE `entry` = 4394;



UPDATE `creature_template` SET `KillCredit1` = 23797 WHERE `entry` = 4393;
UPDATE `creature_template` SET `KillCredit1` = 23797 WHERE `entry` = 4394;

-- Quest 27291 Peace at Last

DELETE FROM `conditions` WHERE (`SourceEntry`='52354'); 
INSERT INTO `conditions` VALUES (17, 0, 52354, 0, 0, 30, 0, 186322, 2, 0, 0, 0, 0, '', NULL);
DELETE FROM `spell_scripts` WHERE (`datalong`='23768'); 
DELETE FROM `spell_scripts` WHERE (`datalong`='23769');
INSERT INTO `spell_scripts` VALUES (52354, 0, 0, 10, 23768, 120000, 0, -3532.4, -4316.63, 7.04762, 2.60968);
INSERT INTO `spell_scripts` VALUES (52354, 0, 0, 10, 23769, 120000, 0, -3533.11, -4318.63, 7.05794, 2.49187);




SET @ENTRY := 40358;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,11372,1,0,0,62,1,0,0,0,0,0,7,0,0,0,-4464,-535,7,0,"Teleport"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,33,39897,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Despawn");


UPDATE `creature_template` SET `HoverHeight` = 15 WHERE `entry` = 23687;



UPDATE `creature_template` SET `faction` = 2316 WHERE `entry` = 5089;


UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=45417; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=45417; 
UPDATE `creature` SET `phaseID`=0 WHERE `id`=45417; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=45417);


UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 27448;

UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=45428; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=45428; 
UPDATE `creature` SET `phaseID`=0 WHERE `id`=45428; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=45428);


UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 27373;

replace  into `creature_queststarter`(`id`,`quest`) values (45428,27369);
replace  into `creature_questender`(`id`,`quest`) values (45417,27369);

UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=45429; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=45429; 
UPDATE `creature` SET `phaseID`=0 WHERE `id`=45429; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=45429);


UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 27381;


SET @ENTRY := 11063;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,3864,0,0,0,56,13202,1,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Add Item");

UPDATE `creature_template` SET `npcflag` = 1,`gossip_menu_id` = 3864 WHERE `entry` = 11063;

replace  into `npc_vendor`(`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`,`OverrideGoldCost`,`type`,`BonusListIDs`,`PlayerConditionID`,`IgnoreFiltering`,`VerifiedBuild`) values (11063,1,13202,0,0,0,0,1,NULL,0,0,26141);




UPDATE `quest_objectives` SET `ObjectID` = 8546, `Amount` = 7  WHERE `QuestID` = 27421;


UPDATE `creature_template` SET `npcflag` = 3 WHERE `entry` = 11063;


UPDATE `creature_template` SET `modelid1` = 15880, `modelid2` = 15880, `unit_flags` = 33555200 WHERE `entry` = 100018;

SET @ENTRY := 100018;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,513,3,3,0,0,80,100018,2,0,0,0,0,1,0,0,0,0,0,0,0,""),
(@ENTRY,0,1,0,1,0,100,1,2000,2000,2000,2000,11,150290,0,0,0,0,0,1,0,0,0,0,0,0,0,""),
(@ENTRY,0,2,0,8,0,100,0,85327,0,0,0,12,45963,5,60000,0,0,0,8,0,0,0,3440.01,-4978.98,195.76,5.458,""),
(@ENTRY,0,3,1,8,0,100,0,85327,0,0,0,33,45738,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 27489;

UPDATE `creature_template` SET `KillCredit1` = 45738 WHERE `entry` = 8561;

UPDATE `creature` SET `spawntimesecs` = 120 WHERE `guid` = 19023;

UPDATE `creature_template` SET `KillCredit1` = 45845, `KillCredit2` = 45846 WHERE `entry` = 17878;


DELETE FROM `creature_addon` WHERE (`guid`=174595);

DELETE FROM `creature_addon` WHERE (`guid`=174761);
DELETE FROM `creature_addon` WHERE (`guid`=175045);
DELETE FROM `creature_addon` WHERE (`guid`=175074);
DELETE FROM `creature_addon` WHERE (`guid`=175115);
DELETE FROM `creature_addon` WHERE (`guid`=175179);
DELETE FROM `creature_addon` WHERE (`guid`=175198);
DELETE FROM `creature_addon` WHERE (`guid`=175205);
DELETE FROM `creature_addon` WHERE (`guid`=175317);
DELETE FROM `creature_addon` WHERE (`guid`=175318);

DELETE FROM `creature_addon` WHERE (`guid`=175073);
DELETE FROM `creature_addon` WHERE (`guid`=175097);
DELETE FROM `creature_addon` WHERE (`guid`=175098);
DELETE FROM `creature_addon` WHERE (`guid`=175127);
DELETE FROM `creature_addon` WHERE (`guid`=175165);
DELETE FROM `creature_addon` WHERE (`guid`=175166);
DELETE FROM `creature_addon` WHERE (`guid`=175181);
DELETE FROM `creature_addon` WHERE (`guid`=175197);
DELETE FROM `creature_addon` WHERE (`guid`=175200);
DELETE FROM `creature_addon` WHERE (`guid`=175211);
DELETE FROM `creature_addon` WHERE (`guid`=175217);
DELETE FROM `creature_addon` WHERE (`guid`=175309);

DELETE FROM `creature_addon` WHERE (`guid`=174764);
DELETE FROM `creature_addon` WHERE (`guid`=175056);
DELETE FROM `creature_addon` WHERE (`guid`=175174);
DELETE FROM `creature_addon` WHERE (`guid`=175210);
DELETE FROM `creature_addon` WHERE (`guid`=175216);
DELETE FROM `creature_addon` WHERE (`guid`=175218);
DELETE FROM `creature_addon` WHERE (`guid`=175275);
DELETE FROM `creature_addon` WHERE (`guid`=175290);

DELETE FROM `creature_template_addon` WHERE (`entry`=47289);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (47289, 0, 0, 0, 1, 69, '');

-- Mataus the Wrathcaster <The Scarlet Crusade>
SET @ENTRY := 46093;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,18266,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Agony'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,10000,27000,11,85800,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowflame'),
(@ENTRY,0,3,0,2,0,100,0,0,80,10000,15000,11,17173,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drain Life at 80% HP');

UPDATE `creature_template` SET `unit_flags` = 33664 WHERE `entry` = 6547;

UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 6547;

-- Huntsman Leopold <The Scarlet Crusade>
SET @ENTRY := 46094;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,79721,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Explosive Shot'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,80004,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Snake Trap on Close');


DELETE FROM `creature_template_addon` WHERE (`entry`=16376);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (16376, 0, 0, 0, 1, 233, '');


UPDATE `creature_template` SET `KillCredit1` = 11064 WHERE `entry` = 8530;


UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 8530;


-- Plaguewood Reanimator SAI
SET @ENTRY := 45897;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,51733,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Aura on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,51733,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Aura on Evade'),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,12000,13000,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Shadow Shock");


UPDATE `quest_objectives` SET `ObjectID` = 0, `Amount` = 0  WHERE `QuestID` = 27526;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 11064;

UPDATE `creature_template` SET `unit_flags` = 32768, `type_flags` = 0 WHERE `entry` = 10414;




UPDATE `gameobject_template` SET `Data1` = 0 WHERE `entry` = 175356;

DELETE FROM `gameobject` WHERE `id`=175356;


UPDATE `creature_template` SET `MovementType` = 0, `InhabitType` = 4 WHERE `entry` = 10415;



DELETE FROM `creature_template_addon` WHERE (`entry`=10415);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (10415, 0, 0, 33554432, 0, 0, '');

DELETE FROM `gameobject` WHERE `id`=175374;
DELETE FROM `gameobject` WHERE `id`=175373;
DELETE FROM `gameobject` WHERE `id`=175405;
DELETE FROM `gameobject` WHERE `id`=175796;


DELETE FROM `creature_template_addon` WHERE (`entry`=47059);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (47059, 0, 0, 0, 1, 233, '');
DELETE FROM `creature_template_addon` WHERE (`entry`=47532);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (47532, 0, 0, 0, 1, 233, '');
DELETE FROM `creature_template_addon` WHERE (`entry`=47340);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (47340, 0, 0, 0, 1, 69, '');



UPDATE `creature_template` SET `unit_flags` = 536871814, `dynamicflags` = 32, `type_flags` = 128 WHERE `entry` = 46014;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (46014);
DELETE FROM `creature_template_addon` WHERE (`entry`=46014);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (46014, 0, 0, 7, 1, 0, 29266);

UPDATE `creature_template` SET `unit_flags2` = 1 WHERE `entry` = 46014;

UPDATE `creature_template` SET `gossip_menu_id` = 46014, `npcflag` = 16777217 WHERE `entry` = 46014;


replace  into `npc_vendor`(`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`,`OverrideGoldCost`,`type`,`BonusListIDs`,`PlayerConditionID`,`IgnoreFiltering`,`VerifiedBuild`) values (46014,1,61923,0,0,0,0,1,NULL,0,0,26141);

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('46014','0','0','Check his pocket...','0','1','1','29416');

SET @ENTRY := 46014;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,11741,0,0,0,56,61923,1,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Add Item");







SET @ENTRY := 48705;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,48705,0,0,0,62,0,0,0,0,0,0,7,0,0,0,-9784.71,-3920.3,24,1,"Teleport");

UPDATE `creature_template` SET `gossip_menu_id` = 48705, `npcflag` = 1 WHERE `entry` = 48705;


REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('48705','0','0','I am ready to GO!!!','0','1','1','29416');



DELETE FROM `creature_template_addon` WHERE (`entry`=45791);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (45791, 0, 0, 0, 1, 69, ''); 



SET @ENTRY := 46503;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,12132,0,0,0,62,0,0,0,0,0,0,7,0,0,0,-9999,-4560,22,0,"Teleport");

DELETE FROM `creature_template_addon` WHERE (`entry`=46702);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (46702, 0, 0, 0, 1, 233, '');

UPDATE `creature_template` SET `unit_flags` = 536871814, `dynamicflags` = 32, `type_flags` = 128 WHERE `entry` = 46881;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (46881);
DELETE FROM `creature_template_addon` WHERE (`entry`=46881);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (46881, 0, 0, 7, 1, 0, 29266);

UPDATE `creature_template` SET `unit_flags2` = 1 WHERE `entry` = 46881;

UPDATE `creature_template` SET `gossip_menu_id` = 46881 WHERE `entry` = 46881;

UPDATE `creature_template` SET `gossip_menu_id` = 46881, `npcflag` = 1 WHERE `entry` = 46881;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('46881','0','0','Check solder...','0','1','1','29416');


SET @ENTRY := 46881;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,46881,0,0,0,33,46909,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");

UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 46166;


UPDATE `creature_template` SET `unit_flags` = 536871814, `dynamicflags` = 32, `type_flags` = 128 WHERE `entry` = 46882;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (46882);
DELETE FROM `creature_template_addon` WHERE (`entry`=46882);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (46882, 0, 0, 7, 1, 0, 29266);

UPDATE `creature_template` SET `unit_flags2` = 1 WHERE `entry` = 46882;

UPDATE `creature_template` SET `gossip_menu_id` = 46882 WHERE `entry` = 46882;

UPDATE `creature_template` SET `gossip_menu_id` = 46882, `npcflag` = 1 WHERE `entry` = 46882;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('46882','0','0','Check solder...','0','1','1','29416');


SET @ENTRY := 46882;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,46882,0,0,0,33,46913,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");


DELETE FROM `creature_template_addon` WHERE (`entry`=46486);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (46486, 0, 0, 0, 1, 234, '');

DELETE FROM `creature_template_addon` WHERE (`entry`=46487);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (46487, 0, 0, 0, 1, 234, '');


UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=17127; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=17127; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=17127; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=17127);

UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=1776; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=1776; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=1776; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=1776);
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 42387;

UPDATE `creature_template` SET `KillCredit1` = 42417 WHERE `entry` = 42387;

replace  into `creature_queststarter`(`id`,`quest`) values (107574,26370);
replace  into `creature_questender`(`id`,`quest`) values (234,26370);



UPDATE `creature_template` SET `InhabitType` = 5, `HoverHeight` = 10 WHERE `entry` = 43533;


UPDATE `creature_template` SET `gossip_menu_id` = 43572, `npcflag` = 1 WHERE `entry` = 43572;



REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('43572','0','0','Lets Go!','0','1','1','29416');

SET @ENTRY := 43572;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,43572,0,0,0,33,43574,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");



UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=48704; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=48704; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=48704; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=48704);


UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=48708; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=48708; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=48708; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=48708);


UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=16134; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=16134; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=16134; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=16134);

SET @ENTRY := 48704;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,27762,0,0,0,62,0,0,0,0,0,0,7,0,0,0,-6651.38,-4750.83,10,4,'Teleport on Quest Add');


-- Dustbelcher Initiate
SET @ENTRY := 46694;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball');

DELETE FROM `creature_template_addon` WHERE (`entry`=48068);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (48068, 0, 0, 0, 1, 69, '');



UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=46654; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=46654; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=46654; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=46654);


DELETE FROM `creature_template_addon` WHERE (`entry`=46773);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (46773, 0, 0, 0, 1, 233, '');
DELETE FROM `creature_template_addon` WHERE (`entry`=46772);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (46772, 0, 0, 0, 1, 233, '');



SET @ENTRY := 46768;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,12146,0,0,0,33,46768,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

SET @ENTRY := 46769;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,12147,0,0,0,33,46769,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");


DELETE FROM `creature_template_addon` WHERE (`entry`=48096);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (48096, 0, 0, 0, 1, 233, '');


UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=46852; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=46852; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=46852; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=46852);


UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=46853; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=46853; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=46853; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=46853);
DELETE FROM `gameobject` WHERE `id`=208121;

UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=46854; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=46854; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=46854; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=46854);



SET @ENTRY := 46852;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,27828,0,0,0,15,27828,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Quest Add');


SET @ENTRY := 46853;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,27834,0,0,0,15,27834,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Quest Add');


SET @ENTRY := 46854;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,27835,0,0,0,15,27835,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Quest Add');

UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=47393; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=47393; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=47393; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=47393);

UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=14627; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=14627; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=14627; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=14627);



UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=14624; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=14624; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=14624; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=14624);


UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=14628; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=14628; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=14628; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=14628);


UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=14626; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=14626; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=14626; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=14626);

UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=14625; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=14625; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=14625; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=14625);

DELETE FROM `creature_template_addon` WHERE (`entry`=14635);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (14635, 0, 0, 3, 1, 0, 78677);


SET @ENTRY := 45897;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,51733,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Shadow Aura on Spawn"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,51733,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Shadow Aura on Evade"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,12000,13000,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Shadow Shock");

-- Iron Summit Guard SAI
SET @ENTRY := 47434;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Shoot"),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flee at 15% HP"),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Say Text at 15% HP"),
(@ENTRY,0,3,0,9,0,100,0,0,20,8000,9000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Net on Close"),
(@ENTRY,0,4,1,62,0,100,0,12265,0,0,0,33,47434,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");


-- Plaguewood Reanimator SAI
SET @ENTRY := 45897;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,51733,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Shadow Aura on Spawn"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,51733,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Shadow Aura on Evade"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,12000,13000,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Shadow Shock");

UPDATE `creature_template` SET `InhabitType` = 4, `HoverHeight` = 40 WHERE `entry` = 8964;
UPDATE `creature_template` SET `KillCredit1` = 47467 WHERE `entry` = 47470;


UPDATE `creature_template` SET `gossip_menu_id` = 47814, `npcflag` = 1 WHERE `entry` = 47814;
SET @ENTRY := 47814;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,47814,0,0,0,56,63114,1,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Add Item"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");
replace  into `npc_vendor`(`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`,`OverrideGoldCost`,`type`,`BonusListIDs`,`PlayerConditionID`,`IgnoreFiltering`,`VerifiedBuild`) values (47814,1,63114,0,0,0,0,1,NULL,0,0,26141);
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('47814','0','0','Take him.','0','1','1','29416');


UPDATE `creature_template` SET `gossip_menu_id` = 47820, `npcflag` = 1 WHERE `entry` = 47820;
SET @ENTRY := 47820;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,47820,0,0,0,56,63116,1,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Add Item"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");
replace  into `npc_vendor`(`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`,`OverrideGoldCost`,`type`,`BonusListIDs`,`PlayerConditionID`,`IgnoreFiltering`,`VerifiedBuild`) values (47820,1,63116,0,0,0,0,1,NULL,0,0,26141);
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('47820','0','0','Take him.','0','1','1','29416');


UPDATE `creature_template` SET `gossip_menu_id` = 47821, `npcflag` = 1 WHERE `entry` = 47821;
SET @ENTRY := 47821;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,47821,0,0,0,56,63117,1,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Add Item"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");
replace  into `npc_vendor`(`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`,`OverrideGoldCost`,`type`,`BonusListIDs`,`PlayerConditionID`,`IgnoreFiltering`,`VerifiedBuild`) values (47821,1,63117,0,0,0,0,1,NULL,0,0,26141);
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('47821','0','0','Take him.','0','1','1','29416');


UPDATE `creature_template` SET `gossip_menu_id` = 47822, `npcflag` = 1 WHERE `entry` = 47822;
SET @ENTRY := 47822;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,47822,0,0,0,56,63119,1,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Add Item"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");
replace  into `npc_vendor`(`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`,`OverrideGoldCost`,`type`,`BonusListIDs`,`PlayerConditionID`,`IgnoreFiltering`,`VerifiedBuild`) values (47822,1,63119,0,0,0,0,1,NULL,0,0,26141);
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('47822','0','0','Take him.','0','1','1','29416');




-- Blackrock War Kodo SAI
SET @ENTRY := 48111;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,6266,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Kodo Stomp on Close"),
(@ENTRY,0,1,1,8,0,100,0,89477,0,0,0,33,48112,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

UPDATE `creature_template` SET `KillCredit1` = 48112 WHERE `entry` = 48111;
UPDATE `creature_template` SET `unit_flags` = 67108864 WHERE `entry` = 48111;


UPDATE `creature_template` SET `KillCredit1` = 48210 WHERE `entry` = 48201;

UPDATE `creature_template` SET `unit_flags` = 32768, `type_flags` = 2147484160 WHERE `entry` = 48156;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 48133;
UPDATE `creature_template` SET `KillCredit1` = 48195 WHERE `entry` = 7025;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 48312;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 48316;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 48314;

UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=48306; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=48306; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=48306; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=48306);

UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=48307; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=48307; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=48307; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=48307);



DELETE FROM `creature` WHERE `id`=48649;


UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (8338,48156,8400,47276,46761,46773,46772,48068,43150,46487,46486,46881,46882,46415,47289,45897,5243,41177,41195,6547,44240,45433,45434,23720,23636,38805,44941,12937,12936,44439,44902,43562,43506,45263,42907,5669,5674,5702,5705,5703,5728,5704,269,3301,52821,50511,50512,16225,16378,42387,45791,23751,23752,23753,23720,44941,12937,12936,44439,44902,43562,43506,45263,42907,5669,5674,5702,5705,5703,5728,5704,269,3301,52821);
