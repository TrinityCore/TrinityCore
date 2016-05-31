-- Vilebranch Speaker
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'mob_vilebranch_speaker' WHERE `entry`=11391;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=11391;

-- NPC talk text for Bloodlord Mandokir from sniff
DELETE FROM `creature_text` WHERE `entry`=11382 AND `groupid`=4;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(11382,4,0, '%s goes into a rage after seeing his raptor fall in battle!',16,0,100,0,0,0, 'Bloodlord Mandokir - Ohgan Dead');

/* 4.x removed
-- Bloodlord Mandokir path from sniff
SET @PATH := 492861;
DELETE FROM `creature_template_addon` WHERE `entry`=11382;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`auras`) VALUES (11382,@PATH,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-12312.66,-1889.255,131.5301,0,1,0,100,0),
(@PATH,2,-12368.16,-1861.005,131.5301,0,1,0,100,0),
(@PATH,3,-12352.66,-1875.505,131.5301,0,1,0,100,0),
(@PATH,4,-12351.41,-1876.505,130.7801,0,1,0,100,0),
(@PATH,5,-12347.41,-1877.505,131.0301,0,1,0,100,0),
(@PATH,6,-12343.16,-1877.505,131.2801,0,1,0,100,0),
(@PATH,7,-12334.91,-1879.755,131.5301,0,1,0,100,0),
(@PATH,8,-12329.91,-1889.505,131.0301,0,1,0,100,0),
(@PATH,9,-12328.66,-1892.255,131.0301,0,1,0,100,0),
(@PATH,10,-12326.41,-1894.255,131.2801,0,1,0,100,0),
(@PATH,11,-12318.16,-1896.255,131.2801,0,1,0,100,0),
(@PATH,12,-12301.41,-1896.255,131.5301,0,1,0,100,0),
(@PATH,13,-12293.16,-1899.005,131.7801,0,1,0,100,0),
(@PATH,14,-12292.16,-1899.005,131.7801,0,1,0,100,0),
(@PATH,15,-12291.16,-1899.005,131.7801,0,1,0,100,0),
(@PATH,16,-12289.41,-1900.505,131.7801,0,1,0,100,0),
(@PATH,17,-12287.41,-1902.505,131.7801,0,1,0,100,0),
(@PATH,18,-12285.41,-1904.755,131.7801,0,1,0,100,0),
(@PATH,19,-12280.66,-1906.755,131.7801,0,1,0,100,0),
(@PATH,20,-12276.41,-1907.755,131.7801,0,1,0,100,0),
(@PATH,21,-12275.41,-1908.755,131.7801,0,1,0,100,0),
(@PATH,22,-12272.41,-1917.255,131.7801,0,1,0,100,0),
(@PATH,23,-12268.16,-1921.255,131.5301,0,1,0,100,0),
(@PATH,24,-12259.91,-1919.255,131.0301,0,1,0,100,0),
(@PATH,25,-12255.66,-1919.255,130.5301,0,1,0,100,0);
*/
