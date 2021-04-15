-- Creature text for Amphitheater Vendor
DELETE FROM `creature_text` WHERE `entry` IN (30098);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(30098,0,0, 'Snacks!',12,0,100,0,0,0,'Amphitheater Vendor'),
(30098,0,1, 'Snacks for sale!',12,0,100,0,0,0,'Amphitheater Vendor'),
(30098,0,2, 'Get your snacks here!',12,0,100,0,0,0,'Amphitheater Vendor'),
(30098,0,3, 'Snacks! Get your snacks here!',12,0,100,0,0,0,'Amphitheater Vendor'),
(30098,0,4, 'Popcorn! Get your popcorn!',12,0,100,0,0,0,'Amphitheater Vendor'),
(30098,0,5, 'Peanuts! Get your peanuts here!',12,0,100,0,0,0,'Amphitheater Vendor'),
(30098,0,6, 'Anguish Ale! Cold Anguish Ale here!',12,0,100,0,0,0,'Amphitheater Vendor'),
(30098,0,7, 'Popcorn! Peanuts! Ale!',12,0,100,0,0,0,'Amphitheater Vendor');
