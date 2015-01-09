-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=36494;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(36494,0,0, 'Tiny creatures under feet, you bring Garfrost something good to eat!',14,0,100,0,0,0, 'Forgemaster Garfrost'),
(36494,1,0, 'Axe too weak. Garfrost make better and CRUSH YOU.',14,0,100,0,0,0, 'Forgemaster Garfrost'),
(36494,2,0, 'Garfrost tired of puny mortals. Now your bones will freeze!',14,0,100,0,0,0, 'Forgemaster Garfrost'),
(36494,3,0, 'Garfrost hope giant underpants clean. Save boss great shame. For later.',14,0,100,0,0,0, 'Forgemaster Garfrost'),
(36494,4,0, 'Will save for snack. For later.',12,0,100,0,0,0, 'Forgemaster Garfrost'),
(36494,4,1, 'That one maybe not so good to eat now. Stupid Garfrost! BAD! BAD!',12,0,100,0,0,0, 'Forgemaster Garfrost'),
(36494,5,0, '%s hurls a massive saronite boulder at you!',16,0,100,0,0,0, 'Forgemaster Garfrost'),
(36494,6,0, '%s casts |cFF00AACCDeep Freeze|r at $n.',41,0,100,0,0,0, 'Forgemaster Garfrost');
-- Remove old script text
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1658006 AND -1658001;
