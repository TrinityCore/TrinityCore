-- Texts for Archaedas
DELETE FROM `creature_text` WHERE `entry`= 2748;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2748,0,0, 'Who dares awaken Archaedas? Who dares the wrath of the makers!',14,0,100,0,0,5855, 'Archaedas On Aggro'),
(2748,1,0, 'Awake ye servants, defend the discs!',14,0,100,0,0,5856, 'Archaedas On Summon Guardians'),
(2748,2,0, 'To my side, brothers. For the makers!',14,0,100,0,0,5857, 'Archaedas On Summon Vault Walkers'),
(2748,3,0, 'Reckless mortal.',14,0,100,0,0,5858, 'Archaedas On Player Kill');
