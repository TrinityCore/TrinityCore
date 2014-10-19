SET @GUID := 445; -- Set by TDB
DELETE FROM creature WHERE id IN (55531,55536,55537,55535);
INSERT INTO creature (guid, id, map, spawnMask, phaseMask, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, MovementType) VALUES 
(@GUID, 55531, 576, 3, 1, 200.607, -5.280913, -12.88977, 6.265732, 7200, 0, 0), -- 55531 (Area: 0)
(@GUID+1, 55536, 576, 3,  1, 200.5534, -17.12531, -16.55337, 1.58825, 7200, 0, 0), -- 55536 (Area: 0)
(@GUID+2, 55537, 576, 3,  1, 188.6897, -5.330469, -16.55337, 6.265732, 7200, 0, 0), -- 55537 (Area: 0)
(@GUID+3, 55535, 576, 3,  1, 200.6899, 6.597652, -16.55337, 4.694936, 7200, 0, 0), -- 55535 (Area: 0)
(@GUID+4, 54638, 576, 3,  1, 200.228, -5.223128, -14.06271, 6.265732, 7200, 0, 0), -- 54638 (Area: 0)
(@GUID+5, 54638, 576, 3,  1, 234.6658, -5.257102, 6.311501, 3.071779, 7200, 0, 0); -- 54638 (Area: 0)


UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (55531,55536,55537,55535);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (55531,55536,55537,55535);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(55531,0,0,0,1,0,100,0,100,200,30000,30000,11,55840,0,0,0,0,0,19,54638,20,0,0,0,0,0,""),
(55536,0,0,0,1,0,100,0,100,200,30000,30000,11,55838,0,0,0,0,0,19,54638,20,0,0,0,0,0,""),
(55535,0,0,0,1,0,100,0,100,200,30000,30000,11,55841,0,0,0,0,0,19,54638,20,0,0,0,0,0,""),
(55537,0,0,0,1,0,100,0,100,200,30000,30000,11,55824,0,0,0,0,0,19,54638,20,0,0,0,0,0,"");

UPDATE `creature_template` SET `minlevel`=72,`maxlevel`=72, `faction_a`=2006,`faction_h`=2006, `unit_flags`=0x300, `unit_class`=8 WHERE `entry`=55531; -- 55531
UPDATE `creature_template` SET `minlevel`=72,`maxlevel`=72, `faction_a`=2006,`faction_h`=2006, `unit_flags`=0x300, `unit_class`=8 WHERE `entry`=55537; -- 55537
UPDATE `creature_template` SET `minlevel`=72,`maxlevel`=72, `faction_a`=2006,`faction_h`=2006, `unit_flags`=0x300, `unit_class`=8 WHERE `entry`=55536; -- 55536
UPDATE `creature_template` SET `minlevel`=72,`maxlevel`=72, `faction_a`=2006,`faction_h`=2006, `unit_flags`=0x300, `unit_class`=8 WHERE `entry`=55535;
UPDATE `creature_template` SET `minlevel`=60,`maxlevel`=60, `unit_flags`=0x2000100 WHERE `entry`=54638; -- 54638
