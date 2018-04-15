-- NPC talk text insert from sniff
DELETE FROM `script_texts` WHERE `npc_entry`=28587;
DELETE FROM `creature_text` WHERE `entry`=28587;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28587,0,0, 'It is you who have destroyed my children? You... shall... pay!',14,0,100,0,0,13960, 'Volkhan'),
(28587,1,0, 'Life from lifelessness... death for you.',14,0,100,0,0,13961, 'Volkhan'),
(28587,1,1, 'Nothing is wasted in the process. You will see....',14,0,100,0,0,13962, 'Volkhan'),
(28587,2,0, 'I will crush you beneath my boots!',14,0,100,0,0,13963, 'Volkhan'),
(28587,2,1, 'All my work... undone!',14,0,100,0,0,13964, 'Volkhan'),
(28587,3,0, 'The armies of iron will conquer all!',14,0,100,0,0,13965, 'Volkhan'),
(28587,3,1, 'Ha, pathetic!',14,0,100,0,0,13966, 'Volkhan'),
(28587,3,2, 'You have cost me too much work!',14,0,100,0,0,13967, 'Volkhan'),
(28587,4,0, 'The master was right... to be concerned.',14,0,100,0,0,13968, 'Volkhan'),
(28587,5,0, '%s runs to his anvil!',41,0,100,0,0,0, 'Volkhan'),
(28587,6,0, '%s prepares to shatter his Brittle Golems!',41,0,100,0,0,0, 'Volkhan');
