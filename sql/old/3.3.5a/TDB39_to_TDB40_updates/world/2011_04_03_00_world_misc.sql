-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry` IN (15214,25171,30281,30298,30342,30343,31898,31899,32498,33222,33223,33225,33229);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(15214,0,0,1,0, NULL), -- Invisible Stalker
(25171,0,0,1,0, NULL), -- Invisible Stalker (Scale x0.5)
(30281,0,1,1,0, NULL), -- Silver Covenant Hippogryph
(30298,0,0,1,0, NULL), -- Invisible Stalker (Float, Uninteractible, LargeAOI)
(30342,0,0,1,0, NULL), -- Orgrim's Hammer
(30343,0,0,1,0, NULL), -- The Skybreaker
(31898,0,0,1,0, NULL), -- Asric
(31899,0,0,1,0, NULL), -- Jadaar
(32498,0,0,1,0, '51583 0'), -- Glacier Penguin; Aura: [DND] Creature Random Size (0 - 50)
(33222,0,0,1,0, '5301 0'), -- Sir Marcus Barlowe; Aura: Defensive State (DND)
(33223,0,0,1,0, '5301 0'), -- Captain Joseph Holley Aura: Defensive State (DND)
(33225,0,0,1,0, '5301 0 62594 0'), -- Marshal Jacob Alerius Aura: Defensive State (DND), Stormwind Champion's Pennant
(33229,0,0,1,0, '7056 0'); -- Melee Target

UPDATE `creature_template_addon` SET `bytes1`=0,`bytes2`=1,`mount`=0,`emote`=0,`auras`=NULL WHERE `entry`=17213; -- Broom
UPDATE `creature_model_info` SET `bounding_radius`=0.2263,`combat_reach`=0.73,`gender`=2 WHERE `modelid`=25391; -- Glacier Penguin

-- Template updates
UPDATE `creature_template` SET `speed_run`=0.85714 WHERE `entry`=17213; -- Broom
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25171; -- Invisible Stalker (Scale x0.5) (move to new file)
UPDATE `creature_template` SET `speed_run`=4.28571 WHERE `entry`=30281; -- Silver Covenant Hippogryph
UPDATE `creature_template` SET `minlevel`=80,`exp`=1 WHERE `entry`=31898; -- Asric
UPDATE `creature_template` SET `minlevel`=80,`exp`=1 WHERE `entry`=31899; -- Jadaar
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=32498; -- Glacier Penguin
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33536 WHERE `entry`=33222; -- Sir Marcus Barlowe
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33536 WHERE `entry`=33223; -- Captain Joseph Holley
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33536 WHERE `entry`=33225; -- Marshal Jacob Alerius
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|131072,`dynamicflags`=132,`speed_walk`=1,`speed_run`=1,`flags_extra`=`flags_extra`|262144 WHERE `entry`=33229; -- Melee Target

-- Spawns
UPDATE  `creature` SET `position_x`= 8530.686,`position_y`=647.2205,`position_z`=558.7308,`orientation`=1.623156 WHERE `guid` =202363; -- Invisible Stalker
DELETE FROM `creature` WHERE `guid` IN (110531,110391); -- wrong Asric & Jadaar spawns in Dalaran Sewers

SET @CGUID = 209019;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+7 AND `id`=25171;
DELETE FROM `creature` WHERE `guid`=@CGUID+8 AND `id`=30298;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(@CGUID+0,25171,571,1,1,0,0,8363.315,783.223938,550.2727,3.33357882,120,0,0,1,0,0,0), -- Invisible Stalker (Scale x0.5)
(@CGUID+1,25171,571,1,1,0,0,8366.177,766.661438,551.2031,1.83259571,120,0,0,1,0,0,0), -- Invisible Stalker (Scale x0.5)
(@CGUID+2,25171,571,1,1,0,0,8366.972,896.803833,552.576355,2.75762,120,0,0,1,0,0,0), -- Invisible Stalker (Scale x0.5)
(@CGUID+3,25171,571,1,1,0,0,8370.458,779.0816,550.0816,3.33357882,120,0,0,1,0,0,0), -- Invisible Stalker (Scale x0.5)
(@CGUID+4,25171,571,1,1,0,0,8371.508,770.821167,550.436157,2.72271371,120,0,0,1,0,0,0), -- Invisible Stalker (Scale x0.5)
(@CGUID+5,25171,571,1,1,0,0,8375.15,908.0208,549.7291,2.75762,120,0,0,1,0,0,0), -- Invisible Stalker (Scale x0.5)
(@CGUID+6,25171,571,1,1,0,0,8388.508,888.4358,548.0348,2.443461,120,0,0,1,0,0,0), -- Invisible Stalker (Scale x0.5)
(@CGUID+7,25171,571,1,1,0,0,8393.317,894.256958,546.748,2.75762,120,0,0,1,0,0,0), -- Invisible Stalker (Scale x0.5)
(@CGUID+8,30298,571,1,1,0,0,8440.007,793.1233,585.525,0,120,0,0,1,0,0,0); -- Invisible Stalker (Float, Uninteractible, LargeAOI)

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=25171 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25171,0,0,0,1,0,100,1,500,500,0,0,11,63413,0,0,0,0,0,11,35469,10,0,0,0,0,0, 'Invisible Stalker (Scale x0.5) - OOC cast Rope Beam in Gormok the Impaler (not repeteable)'),
(25171,0,1,0,1,0,100,1,500,500,0,0,11,63413,0,0,0,0,0,11,35470,10,0,0,0,0,0, 'Invisible Stalker (Scale x0.5) - OOC cast Rope Beam in Icehowl (not repeteable)');
