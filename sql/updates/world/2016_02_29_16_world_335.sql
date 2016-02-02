-- more creature_text for Mr. Smite, changing ID for existing text from 0 to 1:
DELETE FROM `creature_text` WHERE `entry`= 646 AND `BroadcastTextId` IN (1148,1149,1344,1345);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(646,0,0,"You there! Check out that noise!",                                   14,0,100,0,0,5775,1148,3,'Smite SAY_CHECK'),
(646,1,0,"We're under attack! Avast, ye swabs! Repel the invaders!",           14,0,100,0,0,5777,1149,3,'Smite SAY_AGGRO'),
(646,2,0,"You landlubbers are tougher than I thought! I'll have to improvise!",14,0,100,0,0,5778,1344,3,'Smite SAY_IMPROVISE'),
(646,3,0,"D'ah! Now you're making me angry!",                                  14,0,100,0,0,5779,1345,3,'Smite SAY_ANGRY');
