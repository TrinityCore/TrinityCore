-- NPC talk text insert from sniff
DELETE FROM `script_texts` WHERE `npc_entry`=28923;
DELETE FROM `creature_text` WHERE `entry`=28923;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28923,0,0, 'I have witnessed the rise and fall of empires... the birth and extinction of entire species... Over countless millennia the foolishness of mortals has remained the only constant. Your presence here confirms this.',14,0,100,0,0,14160, 'Loken'),
(28923,1,0, 'My master has shown me the future, and you have no place in it. Azeroth will be reborn in darkness. Yogg-Saron shall be released! The Pantheon shall fall!',14,0,100,0,0,14161, 'Loken'),
(28923,2,0, 'What hope is there for you? None!',14,0,100,0,0,14162, 'Loken'),
(28923,3,0, 'You cannot hide from fate!',14,0,100,0,0,14163, 'Loken'),
(28923,3,1, 'Come closer. I will make it quick.',14,0,100,0,0,14164, 'Loken'),
(28923,3,2, 'Your flesh cannot hold out for long.',14,0,100,0,0,14165, 'Loken'),
(28923,4,0, 'Only mortal...',14,0,100,0,0,14166, 'Loken'),
(28923,4,1, 'I... am... FOREVER!',14,0,100,0,0,14167, 'Loken'),
(28923,4,2, 'What little time you had, you wasted!',14,0,100,0,0,14168, 'Loken'),
(28923,5,0, 'You stare blindly into the abyss!',14,0,100,0,0,14169, 'Loken'),
(28923,6,0, 'Your ignorance is profound. Can you not see where this path leads?',14,0,100,0,0,14170, 'Loken'),
(28923,7,0, 'You cross the precipice of oblivion!',14,0,100,0,0,14171, 'Loken'),
(28923,8,0, 'My death... heralds the end of this world.',14,0,100,0,0,14172, 'Loken'),
(28923,9,0, '%s begins to cast Lightning Nova!',41,0,100,0,0,0, 'Loken');
