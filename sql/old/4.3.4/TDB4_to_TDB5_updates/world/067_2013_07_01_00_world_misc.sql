-- Text for Halycon
DELETE FROM `creature_text` WHERE `entry` IN (10220);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(10220,0,0,'%s lets loose a guttural growl as her body collapses. A horrifying howl can be heard echoing through the halls of Blackrock Spire. Something is very, very angry.',16,0,100,0,0,0,'Halycon DEATH');

-- Text for Urok Doomhowl
DELETE FROM `creature_text` WHERE `entry` IN (10584);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(10584,0,0,'You have summoned me, fool!  Now DIE!',14,0,100,0,0,0,'Urok Doomhowl SUMMON'),
(10584,1,0,'Me smash! You die!',12,0,100,0,0,0,'Urok Doomhowl AGGRO');

DELETE FROM `creature` WHERE `guid`=44457;
DELETE FROM `creature` WHERE `guid`=45844;
DELETE FROM `gameobject` WHERE `id`=175584;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=10268; - 4.x
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=10584; - 4.x
UPDATE `gameobject` SET `position_x`=-14.35011,`position_y`=-395.8278,`position_z`=48.50652,`orientation`=3.141593,`rotation2`=-1,`rotation3`=0 WHERE `guid`=99791;

UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'boss_gizrul_the_slavener' WHERE `entry`=10268;
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'boss_urok_doomhowl' WHERE `entry`=10584;

-- Pathing for Gizrul the Slavener Entry: 10268
SET @PATH := 402450;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-166.7968,-381.5575,64.40081,0,0,1,0,100,0),
(@PATH,2,-166.8486,-370.3099,64.40081,0,0,1,0,100,0),
(@PATH,3,-166.4099,-356.3583,64.40081,0,0,1,0,100,0),
(@PATH,4,-166.0918,-341.4831,64.40081,0,0,1,0,100,0),
(@PATH,5,-168.4625,-328.9532,64.40081,0,0,1,0,100,0),
(@PATH,6,-173.3950,-325.9816,64.40932,0,0,1,0,100,0);
