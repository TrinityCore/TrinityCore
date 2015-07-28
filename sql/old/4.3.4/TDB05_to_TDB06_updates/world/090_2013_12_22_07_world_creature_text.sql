-- NPC talk text insert from sniff
UPDATE `creature_text` SET `text`= 'What is this? Mok-thorin ka! Kill them!' WHERE `entry`=26798 AND `groupid`=0;
UPDATE `creature_text` SET `text`= 'Gaagh...' WHERE `entry`=26798 AND `groupid`=2;
UPDATE `creature_text` SET `text`= 'You know what they say about curiosity....' WHERE `entry`=26731 AND `groupid`=0;
DELETE FROM `creature_text` WHERE `entry`=26763 AND `groupid` IN (4,5);
DELETE FROM `creature_text` WHERE `entry`=26794 AND `groupid`=6;
DELETE FROM `creature_text` WHERE `entry`=26723 AND `groupid`=5;
DELETE FROM `creature_text` WHERE `entry`=34716 AND `id`=4;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(26763,4,0, '%s opens a Chaotic Rift!',41,0,100,0,0,0, 'Anomalus'),
(26763,5,0, '%s shields himself and diverts his power to the rifts!',41,0,100,0,0,0, 'Anomalus'),
(26794,6,0, '%s goes into a frenzy!',41,0,100,0,0,0, 'Ormorok the Tree-Shaper'),
(26723,5,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'Keristrasza'),
(34716,0,4, 'I thought I''d never make it out of here alive.',12,0,100,5,0,0, 'Captive Aspirant');
