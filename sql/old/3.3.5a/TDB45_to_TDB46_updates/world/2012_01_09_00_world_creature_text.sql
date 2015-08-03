DELETE FROM `creature_text` WHERE `entry`=16011;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16011,0,0, 'An aura of necrotic energy blocks all healing!',41,0,100,0,0,0, 'Loatheb'),
(16011,1,0, 'The aura fades away, allowing for healing once more!',41,0,100,0,0,0, 'Loatheb'),
(16011,2,0, 'The aura''s power begins to wane!',41,0,100,0,0,0, 'Loatheb');
