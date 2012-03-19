-- Twilight Corrupter say text
DELETE FROM `creature_text` WHERE `entry`=15625;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15625,0,0, 'Come, $N. See what the Nightmare brings...',14,0,100,0,0,0, 'Twilight Corrupter'),
(15625,1,0, 'The Nightmare cannot be stopped!',14,0,100,0,0,0, 'Twilight Corrupter'),
(15625,2,0, 'Twilight Corrupter squeezes the last bit of life out of $N and swallows their soul.',16,0,100,0,0,0, 'Twilight Corrupter');
