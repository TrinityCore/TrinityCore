-- NPC talk text for Gatewatcher Gyro-Kill
DELETE FROM `creature_text` WHERE `entry`=19218;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(19218,0,0, 'I predict a painful death.',14,0,100,0,0,11101, 'Gatewatcher Gyro-Kill - Aggro'),
(19218,1,0, 'Your strategy was flawed.',14,0,100,0,0,11102, 'Gatewatcher Gyro-Kill - On Kill'),
(19218,1,1, 'Yes, the only logical outcome.',12,0,100,0,0,11103, 'Gatewatcher Gyro-Kill - On Kill'),
(19218,2,0, 'Measure twice; cut once.',14,0,100,0,0,11104, 'Gatewatcher Gyro-Kill - Sawblades'),
(19218,2,1, 'If my division is correct you should be quite dead.',14,0,100,0,0,11105, 'Gatewatcher Gyro-Kill - Sawblades'),
(19218,3,0, 'An unforeseen... contingency.',14,0,100,0,0,11106, 'Gatewatcher Gyro-Kill - On Death');

-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=19218; 4.x removed
-- DELETE FROM `creature_ai_texts` WHERE `entry` BETWEEN -86 AND -81; 4.x removed
UPDATE `creature_template` SET `AIName`='', `ScriptName`= 'Boss_Gatewatcher_Gyrokill' WHERE `entry`=19218;
