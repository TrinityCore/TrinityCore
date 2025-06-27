-- A Crew Under Fire
UPDATE `creature_template` SET `ScriptName`='' WHERE  `entry`=8380;
UPDATE `quest_template` SET `SpecialFlags`=2 WHERE  `Id`=3382;
UPDATE `creature_template` SET `ScriptName`='' WHERE  `entry` IN (12205, 12204);
UPDATE `creature` SET orientation = 2.43043 WHERE guid = 35899;

-- Captain Vanessa Beltis SAI
SET @ENTRY := 8380;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,3382,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vanessa Beltis - On Quest 'A Crew Under Fire' Taken - Run Script"),
(@ENTRY,0,1,4,61,0,100,0,3382,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vanessa Beltis - On Quest 'A Crew Under Fire' Taken - Set Faction 250"),
(@ENTRY,0,2,5,11,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vanessa Beltis - On Respawn - Set Faction 35"),
(@ENTRY,0,3,0,6,0,100,0,0,0,0,0,6,3382,0,0,0,0,0,17,0,50,0,0,0,0,0,"Captain Vanessa Beltis - On Just Died - Fail Quest 'A Crew Under Fire'"),
(@ENTRY,0,4,0,61,0,100,0,3382,0,0,0,82,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vanessa Beltis - On Quest 'A Crew Under Fire' Taken - Add Npc Flag "),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vanessa Beltis - On Respawn - Add Npc Flags Gossip & Questgiver");

-- Spitelash Witch SAI
SET @ENTRY := 12205;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,118,0,8000,8000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Witch - On Spellhit 'Polymorph' - Run Script"),
(@ENTRY,0,1,0,8,0,100,0,12824,0,8000,8000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Witch - On Spellhit 'Polymorph' - Run Script"),
(@ENTRY,0,2,0,8,0,100,0,12825,0,8000,8000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Witch - On Spellhit 'Polymorph' - Run Script"),
(@ENTRY,0,3,0,8,0,100,0,12826,0,8000,8000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Witch - On Spellhit 'Polymorph' - Run Script"),
(@ENTRY,0,4,0,54,0,100,0,0,0,0,0,53,1,12205,0,0,0,2,1,0,0,0,0,0,0,0,"Spitelash Witch - On Just Summoned - Start Waypoint"),
(@ENTRY,0,5,0,1,0,100,0,1000,1000,60000,60000,11,12550,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Witch - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,6,0,0,0,100,0,2000,2000,4000,5000,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Witch - In Combat - Cast 'Frostbolt'");

DELETE FROM `waypoints` WHERE `entry`=12205;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(12205, 1, 2370.83,-5893.06,10.6607, 'Spitelash Witch'),
(12205, 2, 2377.23,-5904.07,11.067, 'Spitelash Witch'),
(12205, 3, 2378.04,-5915.15,10.7378, 'Spitelash Witch'),
(12205, 4, 2374.96,-5932,9.66682, 'Spitelash Witch'),
(12205, 5, 2374.06,-5963.62,9.89577, 'Spitelash Witch');

-- Spitelash Raider SAI
SET @ENTRY := 12204;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,118,0,8000,8000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Raider - On Spellhit 'Polymorph' - Run Script"),
(@ENTRY,0,1,0,8,0,100,0,12824,0,8000,8000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Raider - On Spellhit 'Polymorph' - Run Script"),
(@ENTRY,0,2,0,8,0,100,0,12825,0,8000,8000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Raider - On Spellhit 'Polymorph' - Run Script"),
(@ENTRY,0,3,0,8,0,100,0,12826,0,8000,8000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Raider - On Spellhit 'Polymorph' - Run Script"),
(@ENTRY,0,4,0,54,0,100,0,0,0,0,0,53,1,12204,0,0,0,2,1,0,0,0,0,0,0,0,"Spitelash Raider - On Just Summoned - Start Waypoint"),
(@ENTRY,0,5,0,0,0,100,0,40,1000,6500,9000,11,12545,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Raider - In Combat - Cast 'Spitelash'"),
(@ENTRY,0,6,0,0,0,100,0,1000,2500,11000,15000,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Raider - In Combat - Cast 'Frost Shock'");

DELETE FROM `waypoints` WHERE `entry`=12204;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(12204, 1, 2370.83,-5893.06,10.6607, 'Spitelash Raider'),
(12204, 2, 2379.97,-5904.9,10.7712, 'Spitelash Raider'),
(12204, 3, 2376.15,-5924.8,9.84824, 'Spitelash Raider'),
(12204, 4, 2373.41,-5962.79,9.70075, 'Spitelash Raider');

-- Actionlist SAI
SET @ENTRY := 1220500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,29124,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Polymorph'"),
(@ENTRY,9,1,0,0,0,100,0,5000,5000,0,0,11,28406,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Polymorph Backfire'"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,11,6924,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Remove Polymorph'"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Despawn Instant");

-- Actionlist SAI
SET @ENTRY := 838000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vanessa Beltis - On Script - Set Active On"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vanessa Beltis - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,0,0,50,0,0,0,0,"Captain Vanessa Beltis - On Script - Set Data 1 1"),
-- 1. wave
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,12,12205,6,300000,0,0,0,8,0,0,0,2370.83,-5893.06,-5893.06,5.45564,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Witch'"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2367.58,-5889.81,11.3931,5.36209,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2369.53,-5888.84,11.2888,5.23643,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2366.15,-5891.65,11.72,5.46812,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
-- 2nd wave
(@ENTRY,9,7,0,0,0,100,0,50000,50000,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2370.83,-5893.06,10.6607,5.45564,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2367.58,-5889.81,11.3931,5.36209,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,12,12205,6,300000,0,0,0,8,0,0,0,2369.53,-5888.84,11.2888,5.23643,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Witch'"),
(@ENTRY,9,10,0,0,0,100,0,1000,1000,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2366.15,-5891.65,11.72,5.46812,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
-- 3. wave
(@ENTRY,9,11,0,0,0,100,0,52000,52000,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2370.83,-5893.06,10.6607,5.45564,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
(@ENTRY,9,12,0,0,0,100,0,1000,1000,0,0,12,12205,6,300000,0,0,0,8,0,0,0,2367.58,-5889.81,11.3931,5.36209,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Witch'"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2369.53,-5888.84,11.2888,5.23643,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
(@ENTRY,9,14,0,0,0,100,0,0,0,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2366.15,-5891.65,11.72,5.46812,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
-- 4. wave
(@ENTRY,9,15,0,0,0,100,0,54000,54000,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2370.83,-5893.06,10.6607,5.45564,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2367.58,-5889.81,11.3931,5.36209,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
(@ENTRY,9,17,0,0,0,100,0,0,0,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2369.53,-5888.84,11.2888,5.23643,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,12,12205,6,300000,0,0,0,8,0,0,0,2366.15,-5891.65,11.72,5.46812,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Witch'"),
-- 5. wave
(@ENTRY,9,19,0,0,0,100,0,55000,55000,0,0,12,12205,6,300000,0,0,0,8,0,0,0,2370.83,-5893.06,10.6607,5.45564,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Witch'"),
(@ENTRY,9,20,0,0,0,100,0,1000,1000,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2367.58,-5889.81,11.3931,5.36209,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
(@ENTRY,9,21,0,0,0,100,0,0,0,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2369.53,-5888.84,11.2888,5.23643,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,12,12205,6,300000,0,0,0,8,0,0,0,2366.15,-5891.65,11.72,5.46812,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Witch'"),
-- 6. wave
(@ENTRY,9,23,0,0,0,100,0,55000,55000,0,0,12,12205,6,300000,0,0,0,8,0,0,0,2370.83,-5893.06,10.6607,5.45564,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Witch'"),
(@ENTRY,9,24,0,0,0,100,0,1000,1000,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2367.58,-5889.81,11.3931,5.36209,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
(@ENTRY,9,25,0,0,0,100,0,0,0,0,0,12,12204,6,300000,0,0,0,8,0,0,0,2369.53,-5888.84,11.2888,5.23643,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Raider'"),
(@ENTRY,9,26,0,0,0,100,0,0,0,0,0,12,12205,6,300000,0,0,0,8,0,0,0,2366.15,-5891.65,11.72,5.46812,"Captain Vanessa Beltis - On Script - Summon Creature 'Spitelash Witch'"),
(@ENTRY,9,27,0,0,0,100,0,10000,10000,0,0,15,3382,0,0,0,0,0,17,0,30,0,0,0,0,0,"Captain Vanessa Beltis - On Script - Quest Credit 'A Crew Under Fire'"),
(@ENTRY,9,28,0,0,0,100,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vanessa Beltis - On Script - Set Active Off"),
(@ENTRY,9,29,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,9,0,0,50,0,0,0,0,"Captain Vanessa Beltis - On Script - Set Data 2 2"),
(@ENTRY,9,30,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vanessa Beltis - On Script - Set Faction 35"),
(@ENTRY,9,31,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Vanessa Beltis - On Script - set NPC-Flag");

DELETE FROM `creature_text` WHERE `entry`=8380;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(8380, 0, 0, 'Stand Prepared! The naga won\'t wait long to press their advantage once they know we\'re alive.', 12, 0, 100, 0, 0, 0, 'Captain Vanessa Beltis', 4658);

-- Lindros SAI
SET @ENTRY := 8381;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lindros - On Data Set 1 1 - Set Faction 250"),
(@ENTRY,0,1,0,38,0,100,0,2,2,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lindros - On Data Set 2 2 - Set Faction 35"),
(@ENTRY,0,2,0,4,0,100,0,0,0,0,0,11,11975,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lindros - On Aggro - Cast 'Arcane Explosion'"),
(@ENTRY,0,3,0,0,0,100,0,1000,4000,3000,4000,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lindros - In Combat - Cast 'Fireball'");

-- Alexandra Blazen SAI
SET @ENTRY := 8378;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alexandra Blazen - On Data Set 1 1 - Set Faction 250"),
(@ENTRY,0,1,0,38,0,100,0,2,2,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alexandra Blazen - On Data Set 2 2 - Set Faction 35"),
(@ENTRY,0,2,0,4,0,100,0,0,0,0,0,11,1006,2,0,0,0,0,1,0,0,0,0,0,0,0,"Alexandra Blazen - On Aggro - Cast 'Inner Fire'"),
(@ENTRY,0,3,0,2,0,100,0,0,0,20000,20000,11,11640,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alexandra Blazen - Between 0-0% Health - Cast 'Renew'");

-- Patrick Mills SAI
SET @ENTRY := 8382;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Patrick Mills - On Data Set 1 1 - Set Faction 250"),
(@ENTRY,0,1,0,38,0,100,0,2,2,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Patrick Mills - On Data Set 2 2 - Set Faction 35"),
(@ENTRY,0,2,0,4,0,100,0,0,0,0,0,11,1032,2,0,0,0,0,1,0,0,0,0,0,0,0,"Patrick Mills - On Aggro - Cast 'Devotion Aura'"),
(@ENTRY,0,3,0,0,0,100,0,2000,2000,4000,4000,11,17143,0,0,0,0,0,2,0,0,0,0,0,0,0,"Patrick Mills - In Combat - Cast 'Holy Strike'");

-- Horizon Scout Crewman SAI
SET @ENTRY := 8386;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horizon Scout Crewman - On Data Set 1 1 - Set Faction 250"),
(@ENTRY,0,1,0,38,0,100,0,2,2,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horizon Scout Crewman - On Data Set 2 2 - Set Faction 35"),
(@ENTRY,0,2,0,0,0,100,0,2000,2000,4000,4000,11,6660,2,0,0,0,0,2,0,0,0,0,0,0,0,"Horizon Scout Crewman - In Combat - Cast 'Shoot'");
