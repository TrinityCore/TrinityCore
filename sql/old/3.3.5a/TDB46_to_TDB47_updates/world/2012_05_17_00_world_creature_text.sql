-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=9816;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(9816,0,0, '%s begins to regain its strength!',16,0,100,0,0,0, 'Pyroguard Emberseer'),
(9816,1,0, '%s is nearly at full strength!',16,0,100,0,0,0, 'Pyroguard Emberseer'),
(9816,2,0, '%s regains its power and breaks free of its bonds!',16,0,100,0,0,0, 'Pyroguard Emberseer'),
(9816,3,0, 'Ha! Ha! Ha! Thank you for freeing me, fools. Now let me repay you by charring the flesh from your bones.',14,0,100,0,0,0, 'Pyroguard Emberseer');
