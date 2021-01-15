-- Quest: Lycanthoth the Corruptor (25272)
SET @GUID = 86;
DELETE FROM `gameobject` WHERE `guid`=@GUID;
INSERT INTO `gameobject`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID,202660,1,5140.46,-2305.41,1278.11,0.6981,1,120,255,1);

DELETE FROM `event_scripts` WHERE `id`=24005;
INSERT INTO `event_scripts`(`id`,`delay`,`command`,`datalong`,`datalong2`,`x`,`y`,`z`,`o`) VALUES
(24005,1,10,39446,120000,5132.08,-2307.12,1280.32,6.259);

UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`faction_A`=16,`faction_H`=16,`mindmg`=464,`maxdmg`=604,`attackpower`=708,`exp`=3,`baseattacktime`=2000,`minrangedmg`=353,`maxrangedmg`=512,`rangedattackpower`=112,`mingold`=15,`maxgold`=33,`AIName`='SmartAI',`InhabitType`=1 WHERE `entry`=39446;

DELETE FROM `creature_template_addon` WHERE `entry`=39446;
INSERT INTO `creature_template_addon`(`entry`,`auras`) VALUES
(39446,'74061');

DELETE FROM `smart_scripts` WHERE `entryorguid`=39446 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`event_type`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(39446,0,8000,8000,18000,21000,11,37776,1,'Lycanthoth - In combat - Cast Blood Howl');

-- Quest: The Westfall Brigarde
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (452,54371,124,54372,501,54373);

-- Riverpaw Bandit
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (452,54371) AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`event_type`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(452,1,0,5000,5000,12000,15000,11,30478,2,'Riverpaw Bandit - In combat - Cast Hemorrhage'),
(452,2,0,8000,8000,18000,21000,11,80576,2,'Riverpaw Bandit - In combat - Cast Shadowstep'), -- Spell is not working correctly
(54371,1,0,5000,5000,12000,15000,11,30478,2,'Riverpaw Bandit - In combat - Cast Hemorrhage'),
(54371,2,0,8000,8000,18000,21000,11,80576,2,'Riverpaw Bandit - In combat - Cast Shadowstep'); -- Spell is not working correctly

-- Riverpaw Brute
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (124,54372) AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`event_type`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(124,1,0,5000,5000,18000,21000,11,77558,2,'Riverpaw Brute - In combat - Cast Bloody Strike'),
(54372,1,0,5000,5000,18000,21000,11,77558,2,'Riverpaw Brute - In combat - Cast Bloody Strike');

-- Riverpaw Herbalist
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (501,54373) AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`event_type`,`event_flags`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`target_type`,`comment`) VALUES
(501,1,0,1,87,50101,50102,50103,1,'Riverpaw Brute - Enter combat - Call random action list'),
(54373,1,0,1,87,50101,50102,50103,1,'Riverpaw Brute - Enter combat - Call random action list');

DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 50101 AND 50103 AND `source_type`=9;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(50101,9,1,11,80471,1,'Riverpaw Brute - Action list - Cast Potion of Strength'),
(50102,9,1,11,80472,1,'Riverpaw Brute - Action list - Cast Elixir of Agility'),
(50103,9,1,11,80473,1,'Riverpaw Brute - Action list - Cast Tonic of Health');

-- Delete old aura appliance
DELETE FROM `creature_template_addon` WHERE `entry`=501;
