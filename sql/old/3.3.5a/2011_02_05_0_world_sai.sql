SET @GUID = 208787; -- creature.guid (need 2)

SET @Diver=31689; -- Gnome Diver
UPDATE `creature_template` SET `AIName`='SmartAI',`vehicleid`=0,`InhabitType`=4 WHERE `entry`=@Diver; -- Gnome Diver
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry` IN (31719,31768,31769); -- Cosmetic Frenzy, Stabled Hunter Pet -- flying
-- Model data
UPDATE `creature_model_info` SET `bounding_radius`=0.3519,`combat_reach`=1,`gender`=0 WHERE `modelid`=27657; -- Gnome Diver
UPDATE `creature_model_info` SET `bounding_radius`=0.09,`combat_reach`=1,`gender`=2 WHERE `modelid`=23514; -- Stabled Hunter Pet
UPDATE `creature_model_info` SET `bounding_radius`=0.245,`combat_reach`=1,`gender`=2 WHERE `modelid`=23513; -- Stabled Hunter Pet
UPDATE `creature_model_info` SET `bounding_radius`=0.35,`combat_reach`=0,`gender`=2 WHERE `modelid`=2955; -- Cosmetic Albino Snake
UPDATE `creature_model_info` SET `bounding_radius`=0.374,`combat_reach`=0,`gender`=2 WHERE `modelid`=27718; -- Cosmetic Smolderweb Hatchling
UPDATE `creature_model_info` SET `bounding_radius`=0.35,`combat_reach`=0,`gender`=2 WHERE `modelid`=2954; -- Cosmetic Ribbon Snake
UPDATE `creature_model_info` SET `bounding_radius`=0.25,`combat_reach`=0,`gender`=2 WHERE `modelid`=5555; -- Cosmetic Cat Set 2/2
UPDATE `creature_model_info` SET `bounding_radius`=0.35,`combat_reach`=0,`gender`=2 WHERE `modelid`=1206; -- Cosmetic Black Kingsnake
UPDATE `creature_model_info` SET `bounding_radius`=0.3519,`combat_reach`=1,`gender`=1 WHERE `modelid`=25791; -- Breanni
UPDATE `creature_model_info` SET `bounding_radius`=0.35,`combat_reach`=0,`gender`=2 WHERE `modelid`=2957; -- Cosmetic Brown Snake
UPDATE `creature_model_info` SET `bounding_radius`=0.15,`combat_reach`=1,`gender`=2 WHERE `modelid`=3233; -- Cosmetic Cockroach
UPDATE `creature_model_info` SET `bounding_radius`=0.3,`combat_reach`=0,`gender`=2 WHERE `modelid`=27719; -- Cosmetic Worg Pup
UPDATE `creature_model_info` SET `bounding_radius`=0,`combat_reach`=1,`gender`=2 WHERE `modelid`=1141; -- Cosmetic Rat
UPDATE `creature_model_info` SET `bounding_radius`=0.6,`combat_reach`=0,`gender`=2 WHERE `modelid`=27682; -- Cosmetic Pig
UPDATE `creature_model_info` SET `bounding_radius`=0.25,`combat_reach`=0,`gender`=2 WHERE `modelid`=5586; -- Cosmetic Cat Set 1/2
UPDATE `creature_model_info` SET `bounding_radius`=0.2,`combat_reach`=0,`gender`=2 WHERE `modelid`=27881; -- Cosmetic Turtle
UPDATE `creature_model_info` SET `bounding_radius`=0.2749995,`combat_reach`=0,`gender`=2 WHERE `modelid`=23519; -- Stabled Hunter Pet
UPDATE `creature_model_info` SET `bounding_radius`=0.28,`combat_reach`=0,`gender`=2 WHERE `modelid`=27690; -- Stabled Hunter Pet
UPDATE `creature_model_info` SET `bounding_radius`=0.45,`combat_reach`=1,`gender`=2 WHERE `modelid`=4636; -- Stabled Hunter Pet
UPDATE `creature_model_info` SET `bounding_radius`=1.122,`combat_reach`=0,`gender`=2 WHERE `modelid`=2540; -- Stabled Hunter Pet
UPDATE `creature_model_info` SET `bounding_radius`=0.383,`combat_reach`=1,`gender`=1 WHERE `modelid`=25607; -- Tassia Whisperglen

-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry` IN (@Diver,28951,28690,31719,31742,31709,31795,31714,31729,31710,31711,31733,31796,31732,31735,31728,31740,31741,31755,31756,31757,31758,31768,31769);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@Diver,0,33554432,1,0, '59562 0'), -- Gnome Diver
(28951,0,0,257,0, '60913 0 61354 0'), -- Breanni
(28690,0,0,257,0, NULL), -- Tassia Whisperglen
(31719,0,0,1,0, NULL), -- Cosmetic Frenzy
(31742,0,0,1,0, NULL), -- Cosmetic Prairie Dog
(31709,0,0,1,0, NULL), -- Cosmetic Albino Snake
(31795,0,0,1,0, NULL), -- Cosmetic Smolderweb Hatchling
(31714,0,0,1,0, NULL), -- Cosmetic Ribbon Snake
(31729,0,0,1,0, NULL), -- Cosmetic Cat Set 2/2
(31710,0,0,1,0, NULL), -- Cosmetic Black Kingsnake
(31711,0,0,1,0, NULL), -- Cosmetic Brown Snake
(31733,0,0,1,0, NULL), -- Cosmetic Cockroach
(31796,0,0,1,0, NULL), -- Cosmetic Worg Pup
(31732,0,0,1,0, NULL), -- Cosmetic Rat
(31735,0,0,1,0, NULL), -- Cosmetic Pig
(31728,0,0,1,0, NULL), -- Cosmetic Cat Set 1/2
(31740,0,0,1,0, NULL), -- Cosmetic Turtle
(31741,0,0,1,0, NULL), -- Cosmetic Rabbit
(31755,0,0,1,0, NULL), -- Stabled Hunter Pet
(31756,0,0,1,0, NULL), -- Stabled Hunter Pet
(31757,0,0,1,0, NULL), -- Stabled Hunter Pet
(31758,0,0,1,0, NULL), -- Stabled Hunter Pet
(31768,0,0,1,0, NULL), -- Stabled Hunter Pet
(31769,0,0,1,0, NULL); -- Stabled Hunter Pet

-- Random movement for two of the Stabled Hunter Pets
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE `guid` IN (97556,97653);

-- Aura used by all Cosmetic* npcs in Dalaran
-- DELETE FROM `spell_dbc` WHERE `Id`=28782;
-- INSERT INTO `spell_dbc` (`Id`,`Comment`) VALUES (28782, 'Dalaran Cosmetic Aura - Unknown effect');

-- SAI/Gnome Diver: reply to emotes
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Diver AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)VALUES
(@Diver,0,0,0,22,0,100,0,78,5000,5000,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gnome Diver: Salute - Salute'),
(@Diver,0,1,0,22,0,100,0,21,5000,5000,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gnome Diver: Cheer - Bow'),
(@Diver,0,2,0,22,0,100,0,101,5000,5000,0,5,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gnome Diver: Wave - Wave'),
(@Diver,0,3,0,22,0,100,0,34,5000,5000,0,5,94,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gnome Diver: Dance - Dance'),
(@Diver,0,4,0,22,0,100,0,328,5000,5000,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gnome Diver: Flirt - Laugh'),
(@Diver,0,5,0,22,0,100,0,58,5000,5000,0,5,23,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gnome Diver: Kiss - Flex'),
(@Diver,0,6,0,22,0,100,0,77,5000,5000,0,5,14,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gnome Diver: Rude - Rude');

-- Waypoints for flying birds
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (31768,31769));
DELETE FROM `creature` WHERE `id` IN (31768,31769);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,31768,571,1,1,0,0,5864.76025,561.5035,656.350159,3.38593864,120,0,0,1,0,0,2,0,0,0),
(@GUID+1,31769,571,1,1,0,0,5871.1377,556.659363,660.738953,1.44698894,120,0,0,1,0,0,2,0,0,0);
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES
(@GUID+0,(@GUID+0)*10),
(@GUID+1,(@GUID+1)*10);
DELETE FROM `waypoint_data`  WHERE `id` IN ((@GUID+0)*10,(@GUID+1)*10);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES	
((@GUID+0)*10,00,5865.73,561.7454,656.3502),
((@GUID+0)*10,01,5864.76,561.5035,656.3502),
((@GUID+0)*10,02,5865.858,545.6048,657.8221),
((@GUID+0)*10,03,5856.59,546.2563,657.8221),
((@GUID+0)*10,04,5851.967,553.7063,657.8221),
((@GUID+0)*10,05,5848.848,559.3509,657.8221),
((@GUID+0)*10,06,5855.463,567.5033,657.8221),
((@GUID+0)*10,07,5861.43,566.0272,657.8221),
((@GUID+0)*10,08,5870.177,562.2965,657.8221),
((@GUID+0)*10,09,5872.478,553.6407,657.8221),
((@GUID+0)*10,10,5864.64,545.9483,657.8221),
((@GUID+0)*10,11,5856.267,546.3598,657.8221),
((@GUID+0)*10,12,5851.878,553.7315,657.8221),
((@GUID+0)*10,13,5848.888,559.2279,657.8221),
((@GUID+0)*10,14,5848.888,559.2279,657.8221),
((@GUID+1)*10,0,5856.941,550.4024,656.2946),
((@GUID+1)*10,1,5856.993,551.4011,656.2946),
((@GUID+1)*10,2,5852.679,558.0845,660.739),
((@GUID+1)*10,3,5852.628,548.4319,660.739),
((@GUID+1)*10,4,5862.95,547.2537,660.739),
((@GUID+1)*10,5,5871.105,556.4464,660.739),
((@GUID+1)*10,6,5866.302,565.8504,660.739),
((@GUID+1)*10,7,5857.606,565.6177,660.739),
((@GUID+1)*10,8,5857.606,565.6177,660.739);
