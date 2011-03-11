UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry`=38153;
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry` IN (37187,37200);
UPDATE `creature` SET `npcflag`=0 WHERE `entry` IN (37187,37200);
UPDATE `creature` SET `npcflag`=`npcflag`|1 WHERE `guid`=200982; -- Set gossip flag for spawn at Deathbringer's Rise

DELETE FROM `creature_text` WHERE `entry`=37187 AND `groupid` BETWEEN 15 AND 18;
DELETE FROM `creature_text` WHERE `entry`=37200 AND `groupid` BETWEEN 13 AND 15;
DELETE FROM `creature_text` WHERE `entry`=37119 AND `groupid` IN (4,5);
DELETE FROM `creature_text` WHERE `entry`=37181 AND `groupid`=2;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(37187,15,0, 'The paladin still lives? Is it possible, Highlord? Could he have survived?',0,0,0,6,0,17107, 'High Overlord Saurfang - SAY_SAURFANG_INTRO_1'),
(37187,16,0, 'Then we must save him! If we rescue Bolvar Fordragon, we may quell the unrest between the Alliance and the Horde.',0,0,0,5,0,17108, 'High Overlord Saurfang - SAY_SAURFANG_INTRO_2'),
(37187,17,0, 'Our mission is now clear: The Lich King will answer for his crimes and we will save Highlord Bolvar Fordragon!',0,0,0,15,0,17109, 'High Overlord Saurfang - SAY_SAURFANG_INTRO_3'),
(37187,18,0, 'Kor''kron, prepare Orgrim''s Hammer for its final voyage! Champions, our gunship will find a point to dock on the upper reaches of the citadel. Meet us there!',1,0,0,22,0,17110, 'High Overlord Saurfang - SAY_SAURFANG_INTRO_4'),
(37119,4,0, 'The power of the Light knows no bounds, Saurfang. His soul is under great strain, but he lives - for now.',0,0,0,1,0,16658, 'Highlord Tirion Fordring - SAY_TIRION_INTRO_5'),
(37181,2,0, 'But that honor is no longer yours. Soon, I will have a new champion.',1,0,0,0,0,17232, 'The Lich King - SAY_LK_INTRO_3'),
(37200,13,0, 'Could it be, Lord Fordring? If Bolvar lives, mayhap there is hope fer peace between the Alliance and the Horde. We must reach the top o'' this cursed place and free the paladin!',0,0,0,6,0,16980, 'Muradin Bronzebeard - SAY_SAURFANG_INTRO_2'),
(37200,14,0, 'Prepare the Skybreaker fer an aerial assault on the citadel!',1,0,0,5,0,16981, 'Muradin Bronzebeard - SAY_SAURFANG_INTRO_3'),
(37200,15,0, 'Heroes, ye must fight yer way to a clear extraction point within Icecrown. We''ll try an'' rendezvous on the ramparts!',1,0,0,22,0,16982, 'Muradin Bronzebeard - SAY_SAURFANG_INTRO_4'),
(37119,5,0, 'By the Light, it must be so!',0,0,0,5,0,16657, 'Highlord Tirion Fordring - SAY_TIRION_INTRO_A_5');

SET @GUID := 200984;
SET @PATH_ID := @GUID*10;
DELETE FROM `waypoint_data` WHERE `id`=@PATH_ID;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH_ID,0,-39.2257,2211.269,27.90252,0,0,0,100,0),
(@PATH_ID,1,-27.3663,2211.575,30.11564,0,0,0,100,0),
(@PATH_ID,2,-15.8420,2211.618,30.11566,0,0,0,100,0),
(@PATH_ID,3,2.744797,2211.411,30.11566,0,0,0,100,0),
(@PATH_ID,4,24.05210,2211.306,30.11566,0,0,0,100,0),
(@PATH_ID,5,64.72570,2211.561,30.11567,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=@GUID;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(@GUID,@GUID,0,0,0),
(@GUID,201185,2.72779,127.636,0),
(@GUID,200979,5.34512,256.1602,0),
(@GUID,200889,3.59949,206.7455,0);

DELETE FROM `linked_respawn` WHERE `linkedGuid`=@GUID AND `linkType`=0;
INSERT INTO `linked_respawn` (`guid`,`linkedGuid`,`linkType`) VALUES
(201185,@GUID,0),
(200979,@GUID,0),
(200889,@GUID,0),
(@GUID,@GUID,0);
