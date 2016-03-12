-- 
UPDATE `creature_text` SET `TEXT`="Managed to find me, eh? No matter, you won't live to tell anyone of it!", `type`=12, `BroadcastTextId`=33589 WHERE `entry`=33456 AND `groupid`=0;
UPDATE `smart_scripts` SET `entryorguid`=-272020 WHERE `entryorguid`=-23440;
UPDATE `smart_scripts` SET `entryorguid`=-272125 WHERE `entryorguid`=-23439;
UPDATE `smart_scripts` SET `entryorguid`=-272200 WHERE `entryorguid`=-23438;
UPDATE `smart_scripts` SET `entryorguid`=-272467 WHERE `entryorguid`=-23437;
UPDATE `smart_scripts` SET `entryorguid`=-272587 WHERE `entryorguid`=-23436;
UPDATE `smart_scripts` SET `entryorguid`=-272605 WHERE `entryorguid`=-23433;
UPDATE `smart_scripts` SET `entryorguid`=-272606 WHERE `entryorguid`=-23432;
UPDATE `smart_scripts` SET `entryorguid`=-272314 WHERE `entryorguid`=-23429;
UPDATE `smart_scripts` SET `entryorguid`=-272479 WHERE `entryorguid`=-23426;
UPDATE `creature` SET `position_x`=-8553.759, `position_y`=-4384.336, `position_z`=-163.354 WHERE `guid`=272314;
UPDATE `creature` SET `position_x`=-8548.921, `position_y`=-4229.951, `position_z`=-138.103 WHERE `guid`=272479;
UPDATE `creature` SET `spawndist`=10 WHERE `id`=19918;
UPDATE `smart_scripts` SET `action_param1`=0  WHERE `entryorguid` IN(474) AND `source_type`=0 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=545 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=548 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=11971 WHERE `entryorguid`=568 AND `id`=2 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=579 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=75002, `event_param1`=100, `event_param2`=200 WHERE `entryorguid`=683 AND `id`=0 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=75930 WHERE `entryorguid`=736 AND `id`=0 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=938 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts`  SET `action_param1`=3359 WHERE `entryorguid`=940 AND `id`=0 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=940 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET action_param1=57780, `event_param3`=3000, `event_param4`=4000 WHERE `entryorguid`=942 AND `id`=0 AND `source_type`=0;
UPDATE `smart_scripts` SET action_param1=6274 WHERE `entryorguid`=1029 AND `id`=1 AND source_type=0;
UPDATE `smart_scripts` SET `action_param1`=78660, `event_param3`=4000, `event_param4`=5000 WHERE `entryorguid`=1036 AND `id`=2 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=76622 WHERE `entryorguid`=1036 AND `id`=3 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=78648 WHERE `entryorguid`=1038 AND `id`=1 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=13005 WHERE `entryorguid`=1679 AND `id`=0 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1679 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1854 AND `source_type`=0 AND `id`IN (4,1);
UPDATE `smart_scripts` SET `action_param1`=13445 WHERE `entryorguid`=1907 AND `id`=1 AND `source_type`=0;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2010;
UPDATE `smart_scripts` SET `action_param1`=84036 WHERE `entryorguid`=2030 AND `id`=2 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2077 AND `source_type`=0 AND `id`=7;
UPDATE `smart_scripts` SET `action_param1`=11971 WHERE `entryorguid`=2269 AND `id`=1 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=13323 WHERE `entryorguid`=2319 AND `id`=2 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=8258 WHERE `entryorguid`=2344 AND `id`=0 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2371 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2373 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2376 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=11831 WHERE `entryorguid`=2377 AND `id`=0 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2557 AND `source_type`=0 AND `id` IN (0,1);
DELETE FROM `smart_scripts` WHERE `entryorguid`=2570 AND `source_type`=0 AND `id` IN (2);
UPDATE `smart_scripts` SET `action_param1`=11831 WHERE `action_param1`=865;
UPDATE `smart_scripts` SET `action_param1`=82617 WHERE `entryorguid`=2574 AND `id`=1 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2583 AND `source_type`=0 AND `id` IN (0);
DELETE FROM `smart_scripts` WHERE `entryorguid`=2596 AND `source_type`=0 AND `id` IN (1);
UPDATE `smart_scripts` SET `action_param1`=79886 WHERE `entryorguid`=2602 AND `id`=0 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2612 AND `source_type`=0 AND `id` IN (2);
DELETE FROM `smart_scripts` WHERE `entryorguid`=2713 AND `source_type`=0 AND `id` IN (1);
UPDATE `smart_scripts` SET `action_param1`=11986 WHERE `action_param1`=8005;
UPDATE `smart_scripts` SET `action_param1`=76622 WHERE `entryorguid`=2739 AND `id`=1 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2742 AND `source_type`=0 AND `id` IN (0,1);
UPDATE `smart_scripts` SET `action_param1`=465 WHERE `entryorguid`=2744 AND `id`=0 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3458 AND `source_type`=0 AND `id` IN (1);
UPDATE `smart_scripts` SET `action_param1`=20790 WHERE `entryorguid`=3672 AND `id`=1 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=20790 WHERE `entryorguid`=3840 AND `id`=3 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=17253 WHERE `entryorguid`=17253 AND `id`=0 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3940 AND `source_type`=0 AND `id` IN (2);
UPDATE `smart_scripts` SET `action_param1`=11640 WHERE `entryorguid`=3940 AND `id`=1 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=13860 WHERE `entryorguid`=3940 AND `id`=0 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4116 AND `source_type`=0 AND `id` IN (1);
UPDATE `creature_template` SET `AIName`="" WHERE `entry`=4278;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4278 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=20296 WHERE `entryorguid`=4289 AND `id`=1 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4296 AND `source_type`=0 AND `id` IN (1);
DELETE FROM `smart_scripts` WHERE `entryorguid`=4299 AND `source_type`=0 AND `id` IN (0, 1);
UPDATE `smart_scripts` SET `action_param1`=34517 WHERE `entryorguid`=4300 AND `id`=1 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=12039 WHERE `entryorguid`=4303 AND `id`=2 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4303 AND `source_type`=0 AND `id` IN (3);
DELETE FROM `smart_scripts` WHERE `entryorguid`=4517 AND `source_type`=0 AND `id` IN (0,2);
UPDATE `smart_scripts` SET `action_param1`=11980 WHERE `entryorguid`=4798 AND `id`=0 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=15044 WHERE `entryorguid`=4805 AND `id`=2 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4809 AND `source_type`=0 AND `id` IN (0);
UPDATE `smart_scripts` SET `action_param1`=22691 WHERE `entryorguid`=4818 AND `id`=1 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4820 AND `source_type`=0 AND `id` IN (1);
DELETE FROM `smart_scripts` WHERE `entryorguid`=4847 AND `source_type`=0 AND `id` IN (0,2);
DELETE FROM `smart_scripts` WHERE `entryorguid`=4850 AND `source_type`=0 AND `id` IN (1);
DELETE FROM `smart_scripts` WHERE `entryorguid`=4852 AND `source_type`=0 AND `id` IN (1);
DELETE FROM `smart_scripts` WHERE `entryorguid`=4971 AND `source_type`=0 AND `id` IN (2);
UPDATE `smart_scripts` SET `action_param1`=19514 WHERE `entryorguid`=5236 AND `id` IN (1,2,3) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=15089 WHERE `entryorguid`=5333 AND `id` IN (0) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=23895 WHERE `entryorguid`=5335 AND `id` IN (0) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=23895 WHERE `entryorguid`=5682 AND `id` IN (0) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=14053 WHERE `entryorguid`=5682 AND `id` IN (1) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5976 AND `source_type`=0 AND `id` IN (5);
UPDATE `smart_scripts` SET `action_param1`=17253 WHERE `entryorguid`=3939 AND `id` IN (0) AND `source_type`=0;
UPDATE `creature_template` SET `AIName`="" WHERE `entry`=6207;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6207 AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=11970 WHERE `entryorguid`=6226 AND `id` IN (0) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7175 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7291 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7321 AND `source_type`=0 and `id`=0;
UPDATE `smart_scripts` SET `action_param1`=15786 WHERE `entryorguid`=7727 AND `id` IN (0) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=79914 WHERE `entryorguid`=7727 AND `id` IN (1) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7843 AND `source_type`=0 AND `id`=4;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=8338 AND `id` IN (1) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8378 AND `source_type`=0 and `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8382 AND `source_type`=0 and `id`=2;
UPDATE `smart_scripts` SET `action_param1`=15732 WHERE `entryorguid`=10425 AND `id` IN (0) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=17253 WHERE `entryorguid`=10979 AND `id` IN (0) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=6788 WHERE `entryorguid`=11032 AND `id` IN (1) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11563 AND `source_type`=0 and `id`=3;
UPDATE `creature_template` SET `AIName`="" WHERE `entry` in (12204, 12205);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (12204, 12205) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=45026 WHERE `entryorguid`=13219 AND `id` IN (0) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14718 AND `source_type`=0 and `id`=1;
UPDATE `smart_scripts` SET `action_param1`=8269 WHERE `entryorguid`=15277 AND `id` IN (6) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=16827 WHERE `entryorguid`=16348 AND `id` IN (0) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=2 WHERE `entryorguid`=17253 AND `id` IN (0) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17551 AND `source_type`=0 and `id`=1;
UPDATE `smart_scripts` SET `action_param1`=17139 WHERE `entryorguid`=23368 AND `id` IN (2) AND `source_type`=0;
UPDATE `smart_scripts` SET `event_param1`=0, `event_param2`=15 WHERE `entryorguid`=25073 AND `id` IN (4) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=56641 WHERE `entryorguid`=25087 AND `id` IN (1) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26428 AND `source_type`=0 and `id`=11;
UPDATE `smart_scripts` SET `action_param1`=339 WHERE `entryorguid` IN (27199)  AND `id` IN (0) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=339 WHERE `entryorguid` IN (32742)  AND `id` IN (1) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=0 WHERE `entryorguid`=34697 AND `id` IN (0) AND `source_type`=0;
UPDATE `smart_scripts` SET `event_param2`=34872 WHERE `entryorguid`=34872 AND `id` IN (3) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=66780 WHERE `entryorguid`=35126 AND `id` IN (0) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=66781 WHERE `entryorguid`=35128 AND `id` IN (0) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=66782 WHERE `entryorguid`=35130 AND `id` IN (0) AND `source_type`=0;
SET @ENTRY := 37804;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Kaja\'Cola! Poissard the Weasel advise you to drink, or else ... !',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,1, '"Lift it challenge the Goa" to drink Kaja''Cola!',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,2, 'Drink Kaja\'Cola!',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,3, 'Kaja\'Cola is proud to sponsor the Bilgewater Buccaneers!',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,4, 'Kaja\'Cola! When your hacks take the upper hand!',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,5, 'New k \' Cola! Still one hundred percent of ideas are more!',14,0,50,0,0,0, 'say Text');
SET @ENTRY := 35186;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'This party lacks a bit of brilliant',12,0,100,10,0,0, 'say Text'),
(@ENTRY,1,0, 'Thanks !',12,0,100,17,0,0, 'say Text'),
(@ENTRY,2,0, 'Passport delicious! And these are just the out-of A \"work?',12,0,100,7,0,0, 'say Text'),
(@ENTRY,3,0, 'Wouhaya, Fireworks! Again, again!',12,0,50,400,0,0, 'say Text'),
(@ENTRY,3,1, 'Woahhh! I have never seen anything as generally follows. Yet! Yet!',12,0,50,401,0,0, 'say Text'),
(@ENTRY,4,0, 'This white Pa wine and sparkling is delicious. Where have you found?',12,0,50,17,0,0, 'say Text'),
(@ENTRY,4,1, 'Thank you. I was soon offcourse. Yum yum!',12,0,50,7,0,0, 'say Text'),
(@ENTRY,5,0, 'I need a bucket!',12,0,50,1,0,0, 'say Text'),
(@ENTRY,5,1, 'I am hungry! But where is the food good blood?',14,0,50,6,0,0, 'say Text'),
(@ENTRY,5,2, 'If only I had someone with whom dance.',12,0,50,5,0,0, 'say Text'),
(@ENTRY,5,3, 'I love Fireworks! It is necessary that its repeats in the eardrum and it we have blouisse the view.',12,0,50,5,0,0, 'say Text'),
(@ENTRY,5,4, 'I love Fireworks!',12,0,50,5,0,0, 'say Text'),
(@ENTRY,5,5, 'Ah the love! Made go to your buttock Wouhaya Boniface!',12,0,50,21,0,0, 'say Text');
SET @ENTRY := 49178;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(49178, 0, 0, 'FOOD FOR GROLNAR!', 14, 0, 100, 0, 0, 0, 0, 0, 'Grolnar the Berserk');
SET @ENTRY := 39965;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(39965, 0, 0, 'FOOD FOR GROLNAR!', 14, 0, 100, 0, 0, 0, 0, 0, 'Grolnar the Berserk');
DELETE FROM `smart_scripts` WHERE `entryorguid`=39965 AND `source_type`=0 AND `id`=11;
UPDATE `creature_template` SET `AIName`="" WHERE `entry` IN (50897);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (50897) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=100625, `action_param2`=0, `action_param3`=0 WHERE `entryorguid`=54004 AND `id` IN (0) AND `source_type`=0;
UPDATE `smart_scripts` SET `action_param1`=170 WHERE `entryorguid` IN (181058,184798,186403,190594,191124,191365,191578) AND `action_type` IN (44) AND `source_type`=1;
UPDATE `smart_scripts` SET `action_param1`=170 WHERE `entryorguid` IN (19112300) AND `action_type` IN (44) AND `source_type`=9 AND `id`=0;
UPDATE `smart_scripts` SET `action_param1`=169 WHERE `entryorguid` IN (19112300) AND `action_type` IN (44) AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=169 WHERE `entryorguid` IN (18640300, 19136500) AND `action_type` IN (44) AND `source_type`=9 AND `id`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=2018 AND `id` IN (1) AND `source_type`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=3502 AND `id` IN (1) AND `source_type`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=3696 AND `id` IN (4) AND `source_type`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` in (14715,5862,5953,36636,37548) AND `source_type`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` in (38912, 38070, 35161, 34872,3845,2206,7175) AND `source_type`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` in (45438) AND `source_type`=0 and id=7;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` in (45410) AND `source_type`=0 and `id` in (0);
UPDATE `smart_scripts` SET `event_type`=2, `event_flags`=3, `event_param2`=30 WHERE `entryorguid`=7175 AND `id` IN (2) AND `source_type`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` in (12864) AND `source_type`=0 and `id` in (1);
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` in (14753) AND `source_type`=0 and `id` in (3);
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` in (43325, 47762) AND `source_type`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` in (23636,24841,24842,38942,33419, 34309, 36660,36890) AND `source_type`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (34830) AND `source_type`=0 AND id=1;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (36815) AND `source_type`=0 AND id=1;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (37212,39261,39268,39317) AND `source_type`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` in (298100) AND `source_type`=9;
