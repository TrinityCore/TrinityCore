-- Gnome start area fix

UPDATE `creature_template` SET `faction` = 58 WHERE `entry` = 54586;
DELETE FROM `gameobject_loot_template` WHERE `Entry`=40856 AND `Item`=73209;
REPLACE  INTO `gameobject_loot_template`(`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) values 
(40856,77278,0,100,1,1,0,1,1,NULL),
(40856,77279,0,100,1,1,0,1,1,NULL);
UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '265726'; 
UPDATE `creature_template` SET `faction` = 58 WHERE `entry` = 54587;
UPDATE `creature_template` SET `faction` = 58 WHERE `entry` = 65470;
UPDATE `creature_template` SET `faction` = 58 WHERE `entry` = 65471;
DELETE FROM `creature_queststarter` WHERE `id` = '63238' AND `quest` = '31138'; 
DELETE FROM `creature_queststarter` WHERE `id` = '42366' AND `quest` = '26207'; 
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 46363;
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` = 63238;

DELETE FROM `creature_queststarter` WHERE `id` = '42331' AND `quest` = '26198'; 

-- Multi-bot Text'
DELETE FROM `creature_text` WHERE `CreatureId`=42598;
INSERT INTO `creature_text` (`CreatureId`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(42598, 0, 0, 'Initiating cleanup ... ...', 12, 0, 100, 0, 0, 0, 42476, 'GS-9x Multi-Bot');

-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=79424 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 79424, 0, 0, 31, 0, 3, 42563, 0, 0, 0, 0, '', 'Spell Clean Up Toxic Pool (effect 0) will hit the potential target of the spell if target is unit Toxic Pool.');

DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (12634);
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('12634','0','0','I need a new GS-9x Multibot.','50617','1','1','29416');

-- Condition for source Gossip menu option condition type Quest taken
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12634 AND `SourceEntry`=0 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12634, 0, 0, 1, 9, 0, 26205, 0, 0, 0, 0, 0, '', 'Show gossip menu 12634 option id 0 if quest A Job for the Multi-Bot has been taken.');

DELETE FROM `creature_queststarter` WHERE `id` IN (42563,42645,42224);
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=42563;

-- Engineer Grindspark SAI
SET @ENTRY := 42553;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - On Resst - Set Phase 1"),
(@ENTRY,0,1,0,20,1,100,0,26222,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - On Quest Reward - Run Script"),
(@ENTRY,0,2,0,19,0,100,0,26205,0,0,0,85,79419,0,0,0,0,0,7,0,0,0,0,0,0,0,"Engineer Grindspark - On Quest Accept - Invoker Cast 'Force Cast Summon Multi-Bot'"),
(@ENTRY,0,3,4,62,0,100,0,12634,0,0,0,85,79419,0,0,0,0,0,7,0,0,0,0,0,0,0,"Engineer Grindspark - On Gossip Option Select - Invoker Cast 'Force Cast Summon Multi-Bot'"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Engineer Grindspark - On Gossip Option Select - Invoker Cast 'Force Cast Summon Multi-Bot'"),
(@ENTRY,0,5,0,20,0,100,0,26205,0,0,0,85,79435,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - On Quest Reward - Invoker Cast''"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Set Phase 0"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Turn run off"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Say 0"),
(@ENTRY*100,9,3,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5070.834,455.209,410.7567,0,"Engineer Grindspark - Script - Move to"),
(@ENTRY*100,9,4,0,0,0,100,0,3000,3000,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Set Emotstate"),
(@ENTRY*100,9,5,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Set Emotstate"),
(@ENTRY*100,9,6,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Say 1"),
(@ENTRY*100,9,7,0,0,0,100,0,3500,3500,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Say 2'"),
(@ENTRY*100,9,8,0,0,0,100,0,3500,3500,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Play Emote 'OneShotTalk'"),
(@ENTRY*100,9,9,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,19,42945,10,0,0,0,0,0,"Areatrigger - Script - Set Data 1 1 for GS-9x Prototype"),
(@ENTRY*100,9,10,0,0,0,100,0,7500,7500,0,0,69,0,0,0,0,0,0,8,0,0,0,-5073.268,454.8828,410.9308,0,"Engineer Grindspark - Script - Move to"),
(@ENTRY*100,9,11,0,0,0,100,0,1300,1300,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.321288,"Engineer Grindspark - Script - Turn to"),
(@ENTRY*100,9,12,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Say 3'"),
(@ENTRY*100,9,13,0,0,0,100,0,5000,5000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Set Phase 1");
-- Engineer Grindspark text
DELETE FROM `creature_text` WHERE `CreatureId`=@ENTRY;
INSERT INTO `creature_text` (`CreatureId`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Time to put the finishing touches on my bot.', 12, 0, 100, 5, 0, 0, 42947, 'Engineer Grindspark'),
(@ENTRY, 1, 0, 'At last, it''s finished.', 12, 0, 100, 25, 0, 0, 42948, 'Engineer Grindspark'),
(@ENTRY, 2, 0, 'Arise my, uh... what shall I call you? How about ''multi-bot''? Arise, my multi-bot!', 12, 0, 100, 5, 0, 0, 42949, 'Engineer Grindspark'),
(@ENTRY, 3, 0, 'Uh... a couple more tweaks should do it, I think...', 12, 0, 100, 6, 0, 0, 42950, 'Engineer Grindspark');

-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=79424 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 79424, 0, 0, 31, 0, 3, 42563, 0, 0, 0, 0, '', 'Spell Clean Up Toxic Pool (effect 0) will hit the potential target of the spell if target is unit Toxic Pool.');

-- GS-9x Prototype SAI
SET @ENTRY := 42945;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,1,0,0,0,0,11,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - On Reset - Cast 'Permanent Feign Death'"),
(@ENTRY,0,1,0,38,0,100,0,1,1,10000,10000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - On Data Set - Run Script"),
(@ENTRY,0,2,3,40,0,100,0,8,@ENTRY,0,0,11,46419,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - On Reached WP8 - Cast 'Cosmetic - Explosion'"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,41,1000,2,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - On Reached WP8 - Despawn"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,28,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - Script - Remove aura"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,19,536870912,0,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - Script - Remove Unit flag"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,19,1,1,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - Script - Remove Unit flag2"),
(@ENTRY*100,9,3,0,0,0,100,0,2000,2000,0,0,4,12182,0,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - Script - Play Sound"),
(@ENTRY*100,9,4,0,0,0,100,0,1000,1000,0,0,53,1,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - Script - Load Path");
-- Pathing for GS-9x Prototype
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-5076.739,457.9864,410.2584, 'GS-9x Prototype'),
(@ENTRY,2,-5079.739,458.7364,409.0084, 'GS-9x Prototype'),
(@ENTRY,3,-5081.489,459.2364,408.0084, 'GS-9x Prototype'),
(@ENTRY,4,-5083.489,459.7364,407.2584, 'GS-9x Prototype'),
(@ENTRY,5,-5086.989,460.7364,406.5084, 'GS-9x Prototype'),
(@ENTRY,6,-5089.989,461.4864,405.7584, 'GS-9x Prototype'),
(@ENTRY,7,-5093.739,462.4864,405.0084, 'GS-9x Prototype'),
(@ENTRY,8,-5097.021,463.3582,404.2216, 'GS-9x Prototype');

-- Condition for source Quest accept condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=26316 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 26316, 0, 1, 8, 0, 26205, 0, 0, 0, 0, 0, '', 'Show quest What''s Keeping Jessup? if quest A Job for the Multi-Bot has been rewarded.'),
(19, 0, 26316, 0, 1, 8, 0, 26264, 0, 0, 0, 0, 0, '', 'Show quest What''s Keeping Jessup? if quest What''s Left Behind has been rewarded.'),
(19, 0, 26316, 0, 1, 8, 0, 26265, 0, 0, 0, 0, 0, '', 'Show quest What''s Keeping Jessup? if quest Dealing with the Fallout has been rewarded.');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 42598 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(42598, '0', '0', '1', '8', '0', '100', '0', '79416', '0', '15000', '17000', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'On Dummy Spell hit Talk'),
(42598, '0', '1', '2', '61', '0', '100', '0', '0', '0', '0', '0', '11', '79424', '2', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Cast Cleanup Toxic Pool'),
(42598, '0', '2', '0', '61', '0', '100', '0', '0', '0', '0', '0', '11', '79422', '2', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Cast Toxic Pool Credit to Master');

DELETE FROM  smart_scripts WHERE entryorguid=42563;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(42563, 0, 1, 0, 1, 0, 100, 0, 0, 0, 0, 0, 33, 42563, 0, 0, 0, 0, 0, 21, 15, 0, 0, 0, 0, 0, 0,'Credit quest 26205');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE (`entry`='42563');



-- Nevin Twistwrench SAI
SET @ENTRY := 45966;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,28167,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nevin Twistwrench - On Quest Accept - Say 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,85,80653,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nevin Twistwrench - On Quest Accept - Invoker Cast 'Irradiated'"),
(@ENTRY,0,2,0,1,0,100,0,1000,1000,60000,60000,12,46449,1,58000,0,0,0,8,0,0,0,-4958.17,827.382,285.8983,2.722714,"Nevin Twistwrench - OOC - Spawn 'S.A.F.E. Operative'");
-- Nevin Twistwrench text
DELETE FROM `creature_text` WHERE `creatureid`=@ENTRY;
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'We have to break through those mindless leper gnomes if we want to get out of here alive!', 12, 0, 100, 25, 0, 0, 46382, 'Nevin Twistwrench');


-- Captain Tread Sparknozzle SAI
SET @ENTRY := 42489;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,30000,300000,300000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Tread Sparknozzle - OOC - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Say 0"),
(@ENTRY*100,9,1,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Say 1"),
(@ENTRY*100,9,2,0,0,0,100,0,10000,10000,0,0,1,0,0,0,0,0,0,19,42491,10,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Hinkles Fastblast Say 0"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,42505,10,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Set Data"),
(@ENTRY*100,9,4,0,0,0,100,0,8000,8000,0,0,1,1,0,0,0,0,0,19,42491,10,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Hinkles Fastblast Say 1"),
(@ENTRY*100,9,5,0,0,0,100,0,11000,11000,0,0,1,0,0,0,0,0,0,19,42366,10,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Kelsey Steelspark Say 0"),
(@ENTRY*100,9,6,0,0,0,100,0,9000,9000,0,0,1,0,0,0,0,0,0,19,42490,10,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Elgin Clickspring Say 0"),
(@ENTRY*100,9,7,0,0,0,100,0,0,0,0,0,12,43132,1,20000,0,0,0,8,0,0,0,-5138.01,498.262,396.4203,1.500983,"Captain Tread Sparknozzle - Script - Spawn 43132"),
(@ENTRY*100,9,8,0,0,0,100,0,0,0,0,0,12,43132,1,20000,0,0,0,8,0,0,0,-5138.44,498.372,396.4214,1.413717,"Captain Tread Sparknozzle - Script - Spawn 43132"),
(@ENTRY*100,9,9,0,0,0,100,0,0,0,0,0,12,43132,1,20000,0,0,0,8,0,0,0,-5138.9,498.429,396.4363,1.413717,"Captain Tread Sparknozzle - Script - Spawn 43132"),
(@ENTRY*100,9,10,0,0,0,100,0,4000,4000,0,0,12,43131,1,16000,0,0,0,8,0,0,0,-5139.73,499.203,396.4203,6.195919,"Captain Tread Sparknozzle - Script - Spawn 43131"),
(@ENTRY*100,9,11,0,0,0,100,0,0,0,0,0,12,43131,1,16000,0,0,0,8,0,0,0,-5139.75,499.571,396.4563,6.195919,"Captain Tread Sparknozzle - Script - Spawn 43131"),
(@ENTRY*100,9,12,0,0,0,100,0,0,0,0,0,12,43131,1,16000,0,0,0,8,0,0,0,-5139.76,499.977,396.4433,6.195919,"Captain Tread Sparknozzle - Script - Spawn 43131"),
(@ENTRY*100,9,13,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Say 2"),
(@ENTRY*100,9,14,0,0,0,100,0,0,0,0,0,5,4,0,0,0,0,0,11,43132,10,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Image of Dwarf  Mountaineer oneshotcheer"),
(@ENTRY*100,9,15,0,0,0,100,0,8000,8000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Say 3"),
(@ENTRY*100,9,16,0,0,0,100,0,0,0,0,0,5,4,0,0,0,0,0,11,43131,10,0,0,0,0,0,"Captain Tread Sparknozzle - Script - Image of Gnomeregan Infantry oneshotcheer");

DELETE FROM `creature_text` WHERE `creatureid` IN (42489,42491,42366,42490);
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(42489, 0, 0, 'We can''t afford to let our enemy, Thermaplugg, continue to tighten his grip on the rest of Gnomeregan.', 12, 0, 100, 1, 0, 0, 43103, 'Captain Tread Sparknozzle'),
(42489, 1, 0, 'He has ordered his crony, Razlo Crushcog, to keep us on the defensive. Hinkles, what''s the latest intelligence on Razlo and his men?', 12, 0, 100, 1, 0, 0, 43104, 'Captain Tread Sparknozzle'),
(42491, 0, 0, 'It''s been hard for our scouts to get information on what Crushcog is planning.', 12, 0, 100, 1, 0, 0, 43105, 'Hinkles Fastblast to Captain Tread Sparknozzle'),
(42491, 1, 0, 'What we do know is that Crushcog is using an advanced mechano-tank prototype and his irradiated gnomes are trying to repair more at the old arsenal.', 12, 0, 100, 1, 0, 0, 43110, 'Hinkles Fastblast to Captain Tread Sparknozzle'),
(42366, 0, 0, 'We''re going to have a hard time handling this one alone. I sent a message to the dwarven capital of Ironforge asking for their support.', 12, 0, 100, 1, 0, 0, 43111, 'Kelsey Steelspark to Captain Tread Sparknozzle'),
(42490, 0, 0, 'A messenger reached us from Brewnall Village this morning. The dwarves are sending a squad of mountaineers to help us.', 12, 0, 100, 1, 0, 0, 43117, 'Elgin Clickspring to Captain Tread Sparknozzle'),
(42489, 2, 0, 'We have to be in position to strike against Crushcog when the mountaineers arrive.', 12, 0, 100, 1, 0, 0, 43118, 'Captain Tread Sparknozzle to Captain Tread Sparknozzle'),
(42489, 3, 0, 'With Crushcog defeated, Thermaplugg is sure to be quaking in his mechano-tank, and rightly so. You''re next, Thermaplugg. You''re next!', 12, 0, 100, 1, 0, 0, 43119, 'Captain Tread Sparknozzle to Captain Tread Sparknozzle');

-- Image of Razlo Crushcog SAI
SET @ENTRY := 42505;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,1,0,0,0,0,11,16245,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - On Reset - Cast Freeze Anim'"),
(@ENTRY,0,1,0,38,0,100,0,1,1,10000,10000,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - On Data Set - Load Path'"),
(@ENTRY,0,2,0,40,0,100,0,2,@ENTRY,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - On Reached WP2 - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,12,43133,1,42000,0,0,0,8,0,0,0,-5137.05,499.769,396.4573,3.106686,"Image of Razlo Crushcog - Script - Spawn 43133"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,12,43133,1,42000,0,0,0,8,0,0,0,-5138.56,500.873,396.4693,4.34587,"Image of Razlo Crushcog - Script - Spawn 43133"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,3,0,35960,0,0,0,0,11,43133,5,0,0,0,0,0,"Image of Razlo Crushcog - Script - Image of Mechano-Tank Set Model"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.996804,"Image of Razlo Crushcog - Script - Turn to"),
(@ENTRY*100,9,4,0,0,0,100,0,30000,30000,0,0,28,16245,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - Script - Remove aura Freeze Anim"),
(@ENTRY*100,9,5,0,0,0,100,0,0,0,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - Script - Emote OneShotExclamation"),
(@ENTRY*100,9,6,0,0,0,100,0,8000,8000,0,0,41,0,8,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - Script - Despawn");
-- Pathing for Image of Razlo Crushcog
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-5140.15,498.619,396.504, 'Image of Razlo Crushcog'),
(@ENTRY,2,-5137.77,500.366,395.8836, 'Image of Razlo Crushcog');

-- High Tinker Mekkatorque <King of Gnomes> SAI
SET @ENTRY := 42317;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - On Resst - Set Phase 1"),
(@ENTRY,0,1,0,19,1,100,0,26208,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - On Quest Accept - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Set Phase 0"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Turn run off"),
(@ENTRY*100,9,2,0,0,0,100,0,4000,4000,0,0,11,79227,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Cast 'Op: Gnomeregan Recap Credit'"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Say 0"),
(@ENTRY*100,9,4,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5132.723,491.5582,395.7945,0,"High Tinker Mekkatorque - Script - Move to"),
(@ENTRY*100,9,5,0,0,0,100,0,1000,1000,0,0,4,8684,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Play Sound"),
(@ENTRY*100,9,6,0,0,0,100,0,9000,9000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Say 1"),
(@ENTRY*100,9,7,0,0,0,100,0,0,0,0,0,12,42419,1,83000,0,0,0,8,0,0,0,-5134.90,495.592,396.4183,5.61996,"High Tinker Mekkatorque - Script - Spawn Image of High Tinker Mekkatorque"),
(@ENTRY*100,9,8,0,0,0,100,0,0,0,0,0,12,42420,1,83000,0,0,0,8,0,0,0,-5134.27,496.132,396.4193,5.532694,"High Tinker Mekkatorque - Script - Spawn Image of Doc Cogspin"),
(@ENTRY*100,9,9,0,0,0,100,0,0,0,0,0,12,42422,1,83000,0,0,0,8,0,0,0,-5135.19,494.830,396.4193,5.5676,"High Tinker Mekkatorque - Script - Spawn Image of Hinkles Fastblast"),
(@ENTRY*100,9,10,0,0,0,100,0,0,0,0,0,12,42441,1,83000,0,0,0,8,0,0,0,-5133.28,496.009,396.4193,4.433136,"High Tinker Mekkatorque - Script - Spawn Irradiated Trogg Corpse"),
(@ENTRY*100,9,11,0,0,0,100,0,0,0,0,0,12,42441,1,83000,0,0,0,8,0,0,0,-5134.98,494.033,396.4183,0.7504916,"High Tinker Mekkatorque - Script - Spawn Irradiated Trogg Corpse"),
(@ENTRY*100,9,12,0,0,0,100,0,0,0,0,0,12,42452,1,83000,0,0,0,8,0,0,0,-5132.73,493.806,396.5594,2.111848,"High Tinker Mekkatorque - Script - Spawn Irradiator 3000 Image"),
(@ENTRY*100,9,13,0,0,0,100,0,0,0,0,0,50,203862,83,0,0,0,0,8,0,0,0,-5133.672,494.8368,395.4257,0,"High Tinker Mekkatorque - Script - Spawn 203862"),
(@ENTRY*100,9,14,0,0,0,100,0,6000,6000,0,0,1,0,1,0,0,0,0,19,42419,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of High Tinker Mekkatorque Say 0"),
(@ENTRY*100,9,15,0,0,0,100,0,7000,7000,0,0,12,42423,1,70000,0,0,0,8,0,0,0,-5133.471,494.375,396.4433,2.775074,"High Tinker Mekkatorque - Script - Spawn 42423"),
(@ENTRY*100,9,16,0,0,0,100,0,1000,1000,0,0,1,0,1,0,0,0,0,19,42423,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Thermaplugg's Brag-bot Say 0"),
(@ENTRY*100,9,17,0,0,0,100,0,7000,7000,0,0,1,1,1,0,0,0,0,19,42423,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Thermaplugg's Brag-bot Say 1"),
(@ENTRY*100,9,18,0,0,0,100,0,4000,4000,0,0,1,2,1,0,0,0,0,19,42423,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Thermaplugg's Brag-bot Say 2"),
(@ENTRY*100,9,19,0,0,0,100,0,4000,4000,0,0,1,1,1,0,0,0,0,19,42419,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of High Tinker Mekkatorque Say 1"),
(@ENTRY*100,9,20,0,0,0,100,0,5000,5000,0,0,1,0,1,0,0,0,0,19,42452,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Irradiator 3000 Image Say 0"),
(@ENTRY*100,9,21,0,0,0,100,0,11000,11000,0,0,1,2,1,0,0,0,0,19,42419,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of High Tinker Mekkatorque Say 2"),
(@ENTRY*100,9,22,0,0,0,100,0,7000,7000,0,0,1,3,1,0,0,0,0,19,42419,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of High Tinker Mekkatorque Say 3"),
(@ENTRY*100,9,23,0,0,0,100,0,10000,10000,0,0,1,3,1,0,0,0,0,19,42423,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Thermaplugg's Brag-bot Say 3"),
(@ENTRY*100,9,24,0,0,0,100,0,0,0,0,0,43,0,0,0,0,0,0,19,42420,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Doc Cogspin Remove mount"),
(@ENTRY*100,9,25,0,0,0,100,0,0,0,0,0,43,0,0,0,0,0,0,19,42422,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Hinkles Fastblast Remove mount"),
(@ENTRY*100,9,26,0,0,0,100,0,1000,1000,0,0,17,69,0,0,0,0,0,19,42420,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Doc Cogspin set emotestate 69"),
(@ENTRY*100,9,27,0,0,0,100,0,0,0,0,0,17,428,0,0,0,0,0,19,42422,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Hinkles Fastblast set emotestate 428"),
(@ENTRY*100,9,28,0,0,0,100,0,5000,5000,0,0,1,1,1,0,0,0,0,19,42452,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Irradiator 3000 Image Say 1"),
(@ENTRY*100,9,29,0,0,0,100,0,5000,5000,0,0,1,5,1,0,0,0,0,19,42419,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of High Tinker Mekkatorque Say 5"),
(@ENTRY*100,9,30,0,0,0,100,0,6000,6000,0,0,86,51347,0,19,42422,10,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Hinkles Fastblast Cast 'Teleport Visual Only'"),
(@ENTRY*100,9,31,0,0,0,100,0,0,0,0,0,86,51347,0,19,42420,10,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Doc Cogspin Cast 'Teleport Visual Only"),
(@ENTRY*100,9,32,0,0,0,100,0,0,0,0,0,86,51347,0,19,42419,10,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of High Tinker Mekkatorque Cast 'Teleport Visual Only"),
(@ENTRY*100,9,33,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,19,42419,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of High Tinker Mekkatorque Despawn"),
(@ENTRY*100,9,34,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,42420,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Doc Cogspin Despawn"),
(@ENTRY*100,9,35,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,42422,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Image of Hinkles Fastblast Despawn"),
(@ENTRY*100,9,36,0,0,0,100,0,1000,1000,0,0,86,51929,0,19,42452,10,0,0,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Irradiator 3000 Image Cast 'Bloody Explosion (Green)'"),
(@ENTRY*100,9,37,0,0,0,100,0,0,0,0,0,86,46419,0,19,42452,10,0,0,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Irradiator 3000 Image Cast 'Cosmetic - Explosion'"),
(@ENTRY*100,9,38,0,0,0,100,0,2000,2000,0,0,41,0,0,0,0,0,0,9,42441,0,10,0,0,0,0,"High Tinker Mekkatorque - Script - Irradiated Trogg Corpse Despawn"),
(@ENTRY*100,9,39,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,42452,10,0,0,0,0,0,"High Tinker Mekkatorque - Script - Irradiator 3000 Image Despawn"),
(@ENTRY*100,9,40,0,0,0,100,0,2000,2000,0,0,11,79227,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Cast 'Op: Gnomeregan Recap Credit'"),
(@ENTRY*100,9,41,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Say 2"),
(@ENTRY*100,9,42,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5131.771,490.1035,395.5858,0,"High Tinker Mekkatorque - Script - Move to"),
(@ENTRY*100,9,43,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.303835,"High Tinker Mekkatorque - Script - turn to"),
(@ENTRY*100,9,44,0,0,0,100,0,1000,1000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Tinker Mekkatorque - Script - Set Phase 1");
-- High Tinker Mekkatorque text
DELETE FROM `creature_text` WHERE `creatureid`=@ENTRY;
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'We assembled a mighty force and defeated Thermaplugg''s servants, fighting our way into the city. But, the usurper Thermaplugg had one last trick up his sleeve...', 12, 0, 100, 1, 0, 20895, 42408, 'High Tinker Mekkatorque'),
(@ENTRY, 1, 0, 'Take a look at this holotable. I want to show you a bit about Operation: Gnomeregan.', 12, 0, 100, 25, 0, 12148, 48277, 'High Tinker Mekkatorque'),
(@ENTRY, 2, 0, 'We were forced to retreat. Thermaplugg continues to hide behind the radiation, sending his crony, Crushcog, to harass us here on the surface.', 12, 0, 100, 1, 0, 20896, 42411, 'High Tinker Mekkatorque');
DELETE FROM `creature_text` WHERE `creatureid`=42419;
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(42419, 0, 0, 'It''s too quiet. Where are Thermaplugg''s defense forces?', 12, 0, 100, 1, 0, 17552, 39883, 'Image of High Tinker Mekkatorque'),
(42419, 1, 0, 'IT''S A TRAP! That''s a fully functional irradiator!', 12, 0, 100, 5, 0, 17554, 39869, 'Image of High Tinker Mekkatorque'),
(42419, 2, 0, 'Ten minutes? Plenty of time to disarm the device.', 12, 0, 100, 1, 0, 17556, 39893, 'Image of High Tinker Mekkatorque'),
(42419, 3, 0, 'Hinkles, hand me that Whirring Bronze Gizmo and some Fresh Spring Water. Cogspin, toss me that Dirty Trogg Cloth and a Handful of Copper Bolts...', 12, 0, 100, 1, 0, 0, 39894, 'Image of High Tinker Mekkatorque'),
(42419, 5, 0, 'Whuh-oh! We''ve got to get out of here! Lapforge, beam us back, quickly!', 12, 0, 100, 5, 0, 17557, 39895, 'Image of High Tinker Mekkatorque');
DELETE FROM `creature_text` WHERE `creatureid`=42423;
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(42423, 0, 0, 'No! No, no, NO!!! I won''t allow you into my kingdom, usurper! I WON''T ALLOW IT! ', 12, 0, 100, 0, 0, 17570, 39885, 'Thermaplugg''s Brag-bot'),
(42423, 1, 0, 'Activate the Ultimate Atomic Protection System.', 12, 0, 100, 0, 0, 0, 39886, 'Thermaplugg''s Brag-bot'),
(42423, 2, 0, '...DISINTEGRATE THEM ALL!', 12, 0, 100, 0, 0, 0, 39887, 'Thermaplugg''s Brag-bot'),
(42423, 3, 0, 'TEN MINUTES?! You left the factory setting on? Give me that controller, you idiot!', 12, 0, 100, 0, 0, 17572, 39889, 'Thermaplugg''s Brag-bot');
DELETE FROM `creature_text` WHERE `creatureid`=42452;
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(42452, 0, 0, 'Irradiator 3000 activated. Attention. Emergency. You now have ten minutes to reach minimum safe distance.', 12, 0, 100, 0, 0, 17635, 39928, 'Irradiator 3000 Image'),
(42452, 1, 0, '*BEEP* Attention. Emergency. You now have ten seconds to reach minimum safe distance.', 12, 0, 100, 0, 0, 17636, 39929, 'Irradiator 3000 Image');

UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=42316;
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=42319;

-- High Tinker Mekkatorque
DELETE FROM `creature_text` WHERE `creatureid` IN (42849);
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(42849, 0, 0, 'Mekgineer Thermaplugg refuses to acknowledge that his defeat is imminent! He has sent Razlo Crushcog to prevent us from rebuilding our beloved Gnomeregan!', 12, 0, 100, 5, 0, 20890, 42758, 'High Tinker Mekkatorque'),
(42849, 1, 0, 'But $n has thwarted his plans at every turn, and the dwarves of Ironforge stand with us!', 12, 0, 100, 25, 0, 20891, 42759, 'High Tinker Mekkatorque'),
(42849, 2, 0, 'Let''s send him crawling back to his master in defeat!', 12, 0, 100, 5, 0, 20892, 42760, 'High Tinker Mekkatorque'),
(42849, 3, 0, 'We''ve done it! We''re victorious!', 12, 0, 100, 5, 0, 20893, 42763, 'High Tinker Mekkatorque'),
(42849, 4, 0, 'With Crushcog defeated, Thermaplugg is sure to be quaking in his mechano-tank, and rightly so. You''re next Thermaplugg. You''re next!', 12, 0, 100, 5, 0, 20894, 42765, 'High Tinker Mekkatorque'),
(42849, 5, 0, 'Mekkatorque-Cannon!', 14, 0, 100, 0, 0, 0, 42829, 'High Tinker Mekkatorque'),
(42849, 6, 0, 'Mekkatorque-Ray!', 14, 0, 100, 0, 0, 0, 42832, 'High Tinker Mekkatorque'),
(42849, 7, 0, 'Mekkatorque-Missiles!', 14, 0, 100, 0, 0, 0, 42833, 'High Tinker Mekkatorque'),
(42849, 8, 0, 'Mekkatorque-Beam!', 14, 0, 100, 0, 0, 0, 42834, 'High Tinker Mekkatorque');

-- Mountaineer Stonegrind
DELETE FROM `creature_text` WHERE `creatureid` IN (42852);
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(42852, 0, 0, 'Aye, let''s teach this addle-brained gnome a lesson!', 12, 0, 100, 25, 0, 0, 42767, 'Mountaineer Stonegrind'),
(42852, 1, 0, 'That''ll teach you to mess with the might of Ironforge and Gnomeregan!', 12, 0, 100, 25, 0, 0, 42766, 'Mountaineer Stonegrind');

-- Razlo Crushcog
DELETE FROM `creature_text` WHERE `creatureid` IN (42839);
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(42839, 0, 0, 'You! How did you escape detection by my sentry-bots?', 12, 0, 100, 0, 0, 21243, 42761, 'Razlo Crushcog'),
(42839, 1, 0, 'No matter! My guardians and I will make short work of you. To arms, men!', 12, 0, 100, 0, 0, 21244, 42762, 'Razlo Crushcog'),
(42839, 2, 0, 'You will never defeat the true sons of Gnomeregan!', 12, 0, 100, 0, 0, 21245, 42781, 'Razlo Crushcog');

-- Engineer Grindspark SAI
SET @ENTRY := 42553;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - On Resst - Set Phase 1"),
(@ENTRY,0,1,0,20,1,100,0,26222,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - On Quest Reward - Run Script"),
(@ENTRY,0,2,0,19,0,100,0,26205,0,0,0,85,79419,0,0,0,0,0,7,0,0,0,0,0,0,0,"Engineer Grindspark - On Quest Accept - Invoker Cast 'Force Cast Summon Multi-Bot'"),
(@ENTRY,0,3,4,62,0,100,0,12634,0,0,0,85,79419,0,0,0,0,0,7,0,0,0,0,0,0,0,"Engineer Grindspark - On Gossip Option Select - Invoker Cast 'Force Cast Summon Multi-Bot'"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Engineer Grindspark - On Gossip Option Select - Invoker Cast 'Force Cast Summon Multi-Bot'"),
(@ENTRY,0,5,0,20,0,100,0,26205,0,0,0,85,79435,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - On Quest Reward - Invoker Cast''"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Set Phase 0"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Turn run off"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Say 0"),
(@ENTRY*100,9,3,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5070.834,455.209,410.7567,0,"Engineer Grindspark - Script - Move to"),
(@ENTRY*100,9,4,0,0,0,100,0,3000,3000,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Set Emotstate"),
(@ENTRY*100,9,5,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Set Emotstate"),
(@ENTRY*100,9,6,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Say 1"),
(@ENTRY*100,9,7,0,0,0,100,0,3500,3500,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Say 2'"),
(@ENTRY*100,9,8,0,0,0,100,0,3500,3500,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Play Emote 'OneShotTalk'"),
(@ENTRY*100,9,9,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,19,42945,10,0,0,0,0,0,"Areatrigger - Script - Set Data 1 1 for GS-9x Prototype"),
(@ENTRY*100,9,10,0,0,0,100,0,7500,7500,0,0,69,0,0,0,0,0,0,8,0,0,0,-5073.268,454.8828,410.9308,0,"Engineer Grindspark - Script - Move to"),
(@ENTRY*100,9,11,0,0,0,100,0,1300,1300,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.321288,"Engineer Grindspark - Script - Turn to"),
(@ENTRY*100,9,12,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Say 3'"),
(@ENTRY*100,9,13,0,0,0,100,0,5000,5000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Engineer Grindspark - Script - Set Phase 1");
-- Engineer Grindspark text
DELETE FROM `creature_text` WHERE `creatureid`=@ENTRY;
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Time to put the finishing touches on my bot.', 12, 0, 100, 5, 0, 0, 42947, 'Engineer Grindspark'),
(@ENTRY, 1, 0, 'At last, it''s finished.', 12, 0, 100, 25, 0, 0, 42948, 'Engineer Grindspark'),
(@ENTRY, 2, 0, 'Arise my, uh... what shall I call you? How about ''multi-bot''? Arise, my multi-bot!', 12, 0, 100, 5, 0, 0, 42949, 'Engineer Grindspark'),
(@ENTRY, 3, 0, 'Uh... a couple more tweaks should do it, I think...', 12, 0, 100, 6, 0, 0, 42950, 'Engineer Grindspark');

-- GS-9x Prototype SAI
SET @ENTRY := 42945;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,1,0,0,0,0,11,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - On Reset - Cast 'Permanent Feign Death'"),
(@ENTRY,0,1,0,38,0,100,0,1,1,10000,10000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - On Data Set - Run Script"),
(@ENTRY,0,2,3,40,0,100,0,8,@ENTRY,0,0,11,46419,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - On Reached WP8 - Cast 'Cosmetic - Explosion'"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,41,1000,2,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Razlo Crushcog - On Reached WP8 - Despawn"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,28,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - Script - Remove aura"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,19,536870912,0,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - Script - Remove Unit flag"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,19,1,1,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - Script - Remove Unit flag2"),
(@ENTRY*100,9,3,0,0,0,100,0,2000,2000,0,0,4,12182,0,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - Script - Play Sound"),
(@ENTRY*100,9,4,0,0,0,100,0,1000,1000,0,0,53,1,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"GS-9x Prototype - Script - Load Path");

-- Gnomeregan Trainee SAI
SET @ENTRY := 42329;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,5000,5000,5000,87,@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2,0,0,0,1,0,0,0,0,0,0,0,"Gnomeregan Trainee - OOC - Run Random Script"),
(@ENTRY*100  ,9,0,0,0,0,100,0,0,0,0,0,11,42880,0,0,0,0,0,9,42328,0,2,0,0,0,0,"Gnomeregan Trainee - OOC - Cast 'Cosmetic - Combat Attack 1H'"),
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,11,44079,0,0,0,0,0,9,42328,0,2,0,0,0,0,"Gnomeregan Trainee - OOC - Cast 'Cosmetic - Combat Special Attack 1H'"),
(@ENTRY*100+2,9,0,0,0,0,100,0,0,0,0,0,11,78959,0,0,0,0,0,9,42328,0,2,0,0,0,0,"Gnomeregan Trainee - OOC - Cast 'Cosmetic - Combat Attack 1H (Thrust)'");
UPDATE `creature_template_addon` SET `emote`=333 WHERE entry=42329;

UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 204019;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 42645;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (204019, 42645, 4264500);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(204019, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Cage - on gameobject state changed - store player'),
(204019, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 42645, 5, 0, 0, 0, 0, 0, 'Cage - linked - send player to Mosshide'),
(204019, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 42645, 5, 0, 0, 0, 0, 0, 'Cage - linked - set data 1 1 to Mosshide within 5 yards'),
(42645, 0, 0, 0, 38, 0, 100, 1, 1, 1, 0, 0, 80, 4264500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mosshide - on data set 1 1 - run actionlist (4264500)'),
(4264500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 42645, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Mosshide - actionlist - give quest credit (42645)'),
(4264500, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 46, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mosshide - actionlist - run forward 10 yards'),
(4264500, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mosshide - actionlist - despawn');

DELETE FROM `gameobject` WHERE `id`=204042;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(51003223, 204042, 0, 0, 0, 1, 0, 0, 0, -1, -5522.18, 699.831, 375.867, 4.89203, 0, 0, -0.640831, 0.767682, 300, 255, 1, 0, '', 0);

UPDATE `creature_template` SET `npcflag` = 0, `unit_flags` = 512 WHERE `entry` = 42224;
DELETE FROM `creature` WHERE `id`=42839;
UPDATE `creature_template` SET `unit_flags` = 512 WHERE `entry` = 42494;
-- Crushcog Sentry-Bot SAI
SET @ENTRY := 42291;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,84152,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wailing Siren on Close'),
(@ENTRY,0,1,2,8,0,100,0,79781,0,0,0,33,42796,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");
UPDATE `quest_objectives` SET `ObjectID` = '42494' WHERE `ID` = '265862'; 
UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 42494;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (46447,46185,46208,42557,42328,42494);