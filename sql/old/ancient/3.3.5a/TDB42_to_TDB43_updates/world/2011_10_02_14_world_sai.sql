-- Quest: No Where to Run (12261)
-- SAI for Destructive Ward
SET @ENTRY :=27430;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - On spawn Start Script'),
(@ENTRY*100,9,0,0,0,0,100,0,2000,2000,0,0,11,48715,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Summon Smoldering Skeleton'),
(@ENTRY*100,9,1,0,0,0,100,0,15000,15000,0,0,11,48715,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Summon Smoldering Skeleton'),
(@ENTRY*100,9,2,0,0,0,100,0,1000,1000,0,0,11,48735,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Destructive Ward Powerup'),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Raid Emote'),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,11,48733,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Destructive Pulse'),
(@ENTRY*100,9,5,0,0,0,100,0,15000,15000,0,0,11,48718,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Summon Smoldering Construct'),
(@ENTRY*100,9,6,0,0,0,100,0,15000,15000,0,0,11,48718,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Summon Smoldering Construct'),
(@ENTRY*100,9,7,0,0,0,100,0,1000,1000,0,0,11,48735,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Destructive Ward Powerup'),
(@ENTRY*100,9,8,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Raid Emote'),
(@ENTRY*100,9,9,0,0,0,100,0,0,0,0,0,11,48733,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Destructive Pulse'),
(@ENTRY*100,9,10,0,0,0,100,0,25000,25000,0,0,11,48715,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Summon Smoldering Skeleton'),
(@ENTRY*100,9,11,0,0,0,100,0,0,0,0,0,11,48715,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Summon Smoldering Skeleton'),
(@ENTRY*100,9,12,0,0,0,100,0,0,0,0,0,11,48718,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Summon Smoldering Construct'),
(@ENTRY*100,9,13,0,0,0,100,0,2000,2000,0,0,11,48735,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Destructive Ward Powerup'),
(@ENTRY*100,9,14,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Raid Emote'),
(@ENTRY*100,9,15,0,0,0,100,0,0,0,0,0,11,48734,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Destructive Barrage'),
(@ENTRY*100,9,16,0,0,0,100,0,1000,1000,0,0,11,48734,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Destructive Barrage'),
(@ENTRY*100,9,17,0,0,0,100,0,1000,1000,0,0,11,48734,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Destructive Barrage'),
(@ENTRY*100,9,18,0,0,0,100,0,0,0,0,0,11,52409,0,0,0,0,0,23,0,0,0,0,0,0,0, 'Destructive Ward - Destructive Ward Kill Credit'),
(@ENTRY*100,9,19,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Destructive Ward - Despawn');

DELETE FROM `creature_text` WHERE `entry`=27430;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(27430,0,0, 'The Destructive Ward gains in power.',41,0,100,0,0,0, 'Destructive Ward'),
(27430,1,0, 'The Destructive Ward is fully charged!',41,0,100,0,0,0, 'Destructive Ward');

-- Template update
UPDATE `creature_template` SET `exp`=2,`minlevel`=73,`maxlevel`=73,`unit_flags`=`unit_flags`|4|256,`speed_run`=1, RegenHealth=0 WHERE `entry`=27430; -- Destructive Ward

-- Model data
UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=1,`gender`=2 WHERE `modelid`=25167; -- Destructive Ward
UPDATE `creature_model_info` SET `bounding_radius`=0.945,`combat_reach`=0.945,`gender`=0 WHERE `modelid`=23951; -- Snowfall Elk

-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry` IN (27430,26615);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(26615,0,0,1,0, NULL), -- Snowfall Elk
(27430,0,0,1,0, NULL); -- Destructive Ward
