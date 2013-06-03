-- Orphan Matron Aria
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=34365;

DELETE FROM `smart_scripts` WHERE `entryorguid`=34365 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`link`,`event_type`,`event_param1`,`event_param2`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(34365,1,4,62,10502,1,33,34365,7,'Orphan Matron Aria - On gossip select - Give quest credit'),
(34365,2,4,62,10502,2,11,65359,7,'Orphan Matron Aria - On gossip select - Create oracle orphan whistle'),
(34365,3,4,62,10502,3,11,65360,7,'Orphan Matron Aria - On gossip select - Create wolvar orphan whistle'),
(34365,4,0,61,0,0,72,0,7,'Orphan Matron Aria - On gossip select - Close gossip');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=10502;
INSERT INTO `gossip_menu_option`(`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`) VALUES
(10502,1,0,'Tell me about the orphans.',1,1),
(10502,2,0,'I need a new Oracle Orphan Whistle.',1,1),
(10502,3,0,'I need a new Wolvar Orphan Whistle.',1,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10502;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`) VALUES
(15,10502,1,1,12,10,0,0,'Childrens Week must be active'),
(15,10502,1,1,1,58818,0,0,'Needs aura 58818'),
(15,10502,1,1,9,13927,0,0,'Quest 13927 must be active'),
(15,10502,1,2,12,10,0,0,'Childrens Week must be active'),
(15,10502,1,2,1,58818,0,0,'Needs aura 58818'),
(15,10502,1,2,9,13926,0,0,'Quest 13926 must be active'),
(15,10502,2,0,12,10,0,0,'Childrens Week must be active'),
(15,10502,2,0,8,13926,0,0,'Quest 13926 must be rewarded'),
(15,10502,2,0,2,46397,1,1,'Must not have item 46397'),
(15,10502,3,0,12,10,0,0,'Childrens Week must be active'),
(15,10502,3,0,8,13927,0,0,'Quest 13926 must be rewarded'),
(15,10502,3,0,2,46396,1,1,'Must not have item 46397');

-- Orphan Matron Battlewail
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=14451;

DELETE FROM `smart_scripts` WHERE `entryorguid`=14451 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`link`,`event_type`,`event_param1`,`event_param2`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(14451,1,2,62,5848,1,11,23125,7,'Orphan Matron Battlewail - On gossip select - Create orc orphan whistle'),
(14451,2,0,61,0,0,72,0,7,'Orphan Matron Battlewail - On gossip select - Close gossip');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=5848;
INSERT INTO `gossip_menu_option`(`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`) VALUES
(5848,1,0,'I need a new Orc Orphan Whistle.',1,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=5848;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`) VALUES
(15,5848,1,0,12,10,0,0,'Childrens Week must be active'),
(15,5848,1,0,8,172,0,0,'Quest 172 must be rewarded'),
(15,5848,1,0,2,18597,1,1,'Must not have item 18597');

-- Orphan Matron Mercy
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=22819;

DELETE FROM `smart_scripts` WHERE `entryorguid`=22819 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`link`,`event_type`,`event_param1`,`event_param2`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(22819,1,3,62,8568,1,11,39512,7,'Orphan Matron Mercy - On gossip select - Create blood elf orphan whistle'),
(22819,2,3,62,8568,2,11,39513,7,'Orphan Matron Mercy - On gossip select - Create draenei orphan whistle'),
(22819,3,0,61,0,0,72,0,7,'Orphan Matron Mercy - On gossip select - Close gossip');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=8568;
INSERT INTO `gossip_menu_option`(`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`) VALUES
(8568,1,0,'I need a new Blood Elf Orphan Whistle.',1,1),
(8568,2,0,'I need a new Draenei Orphan Whistle.',1,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8568;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`) VALUES
(15,8568,1,0,12,10,0,0,'Childrens Week must be active'),
(15,8568,1,0,8,10942,0,0,'Quest 10942 must be rewarded'),
(15,8568,1,0,2,31880,1,1,'Must not have item 31880'),
(15,8568,2,0,12,10,0,0,'Childrens Week must be active'),
(15,8568,2,0,8,10943,0,0,'Quest 10943 must be rewarded'),
(15,8568,2,0,2,31881,1,1,'Must not have item 31881');

-- Orphan Matron Nightingale
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=14450;

DELETE FROM `smart_scripts` WHERE `entryorguid`=14450 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`link`,`event_type`,`event_param1`,`event_param2`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(14450,1,2,62,5849,1,11,23124,7,'Orphan Matron Nightingale - On gossip select - Create human orphan whistle'),
(14450,2,0,61,0,0,72,0,7,'Orphan Matron Nightingale - On gossip select - Close gossip');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=5849;
INSERT INTO `gossip_menu_option`(`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`) VALUES
(5849,1,0,'I need a new Human Orphan Whistle.',1,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=5849;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`) VALUES
(15,5849,1,0,12,10,0,0,'Childrens Week must be active'),
(15,5849,1,0,8,1468,0,0,'Quest 1468 must be rewarded'),
(15,5849,1,0,2,18598,1,1,'Must not have item 18598');

-- Oracle Orphan
SET @TEXT_ORACLE_ORPHAN_1 = 1;
SET @TEXT_ORACLE_ORPHAN_2 = 2;
SET @TEXT_ORACLE_ORPHAN_3 = 3;
SET @TEXT_ORACLE_ORPHAN_4 = 4;
SET @TEXT_ORACLE_ORPHAN_5 = 5;
SET @TEXT_ORACLE_ORPHAN_6 = 6;
SET @TEXT_ORACLE_ORPHAN_7 = 7;
SET @TEXT_ORACLE_ORPHAN_8 = 8;
SET @TEXT_ORACLE_ORPHAN_9 = 9;
SET @TEXT_ORACLE_ORPHAN_10 = 10;
SET @TEXT_ORACLE_ORPHAN_11 = 11;
SET @TEXT_ORACLE_ORPHAN_12 = 12;
SET @TEXT_ORACLE_ORPHAN_13 = 13;
SET @TEXT_ORACLE_ORPHAN_14 = 14;

UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=33533;

DELETE FROM `smart_scripts` WHERE `entryorguid`=33533 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`event_type`,`event_param1`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(33533,8,65357,33,36209,7,'Oracle Orphan - On spellhit - Give quest credit');

DELETE FROM `creature_text` WHERE `entry`=33533;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`emote`) VALUE
(33533,@TEXT_ORACLE_ORPHAN_1,"Look!",12,0),
(33533,@TEXT_ORACLE_ORPHAN_2,"We can dance too!",12,0),
(33533,@TEXT_ORACLE_ORPHAN_3,"We made a new friend!",12,0),
(33533,@TEXT_ORACLE_ORPHAN_4,"We here! Only, if this is world tree, how come it broke when they tried to put whole world in?",12,0),
(33533,@TEXT_ORACLE_ORPHAN_5,"Look! Is that us? We think it's us. A bit older, maybe?",12,0),
(33533,@TEXT_ORACLE_ORPHAN_6,"Looks like we blessed by Great Ones! Shrines give magic, make us high-oracle someday? Maybe?",12,0),
(33533,@TEXT_ORACLE_ORPHAN_7,"Wow! A real Great One? We don't even think Soo-say has met a real Great One!",12,0),
(33533,@TEXT_ORACLE_ORPHAN_8,"Um, hello, Mr. Great One. We are honored to meet you.",12,0),
(33533,@TEXT_ORACLE_ORPHAN_9,"Maybe you're asleep, Mr. Great One? We stand. Must be hard working being Great One, collecting all the shinies we leave for you.",12,0),
(33533,@TEXT_ORACLE_ORPHAN_10,"We brought you a gift, Great One. Maybe you see it when you wake up. Maybe you remember we came to see you, oki?",12,0),
(33533,@TEXT_ORACLE_ORPHAN_11,"So that's the queen of the dragons? Hmm... we thought she'd be bigger. Yes, we did.",12,0),
(33533,@TEXT_ORACLE_ORPHAN_12,"How come she doesn't look like the other dragons? could she turn into a big ol' dragon if she wanted to?",12,0),
(33533,@TEXT_ORACLE_ORPHAN_13,"Um... Your Majesty, would you turn into a dragon for us?",12,0),
(33533,@TEXT_ORACLE_ORPHAN_14,"Oki... How about now?",12,0);

DELETE FROM `creature_questrelation` WHERE `id`=33533;

DELETE FROM `game_event_creature_quest` WHERE `id`=33533;
INSERT INTO `game_event_creature_quest`(`eventEntry`,`id`,`quest`) VALUES
(10,33533,13929),
(10,33533,13933),
(10,33533,13950),
(10,33533,13954),
(10,33533,13956),
(10,33533,13937),
(10,33533,13959);

DELETE FROM `creature_involvedrelation` WHERE `id`=33533;
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES
(33533,13929),
(33533,13933),
(33533,13950),
(33533,13954),
(33533,13956),
(33533,13937),
(33533,13926);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry` IN (13954,13956,13937);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`comment`) VALUES
(19,13954,8,13929,'Accept quest 13954 - Quest 13929 needs to be rewarded'),
(19,13954,8,13933,'Accept quest 13954 - Quest 13933 needs to be rewarded'),
(19,13954,8,13950,'Accept quest 13954 - Quest 13950 needs to be rewarded'),
(19,13956,8,13929,'Accept quest 13956 - Quest 13929 needs to be rewarded'),
(19,13956,8,13933,'Accept quest 13956 - Quest 13933 needs to be rewarded'),
(19,13956,8,13950,'Accept quest 13956 - Quest 13950 needs to be rewarded'),
(19,13937,8,13956,'Accept quest 13937 - Quest 13956 needs to be rewarded'),
(20,13954,8,13929,'Show quest mark 13954 - Quest 13929 needs to be rewarded'),
(20,13954,8,13933,'Show quest mark 13954 - Quest 13933 needs to be rewarded'),
(20,13954,8,13950,'Show quest mark 13954 - Quest 13950 needs to be rewarded'),
(20,13956,8,13929,'Show quest mark 13956 - Quest 13929 needs to be rewarded'),
(20,13956,8,13933,'Show quest mark 13956 - Quest 13933 needs to be rewarded'),
(20,13956,8,13950,'Show quest mark 13956 - Quest 13950 needs to be rewarded'),
(20,13937,8,13956,'Show quest mark 13937 - Quest 13956 needs to be rewarded');

-- Wolvar Orphan
SET @TEXT_WOLVAR_ORPHAN_1 = 1;
SET @TEXT_WOLVAR_ORPHAN_2 = 2;
SET @TEXT_WOLVAR_ORPHAN_3 = 3;
SET @TEXT_WOLVAR_ORPHAN_4 = 4;
SET @TEXT_WOLVAR_ORPHAN_5 = 5;
SET @TEXT_WOLVAR_ORPHAN_6 = 6;
SET @TEXT_WOLVAR_ORPHAN_7 = 7;
SET @TEXT_WOLVAR_ORPHAN_8 = 8;
SET @TEXT_WOLVAR_ORPHAN_9 = 9;
SET @TEXT_WOLVAR_ORPHAN_10 = 10;
SET @TEXT_WOLVAR_ORPHAN_11 = 11;
SET @TEXT_WOLVAR_ORPHAN_12 = 12;
SET @TEXT_WOLVAR_ORPHAN_13 = 13;

UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=33532;

DELETE FROM `smart_scripts` WHERE `entryorguid`=33532 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`event_type`,`event_param1`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(33532,8,65357,33,36209,7,'Wolvar Orphan - On spellhit - Give quest credit');

DELETE FROM `creature_text` WHERE `entry`=33532;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`emote`) VALUE
(33532,@TEXT_WOLVAR_ORPHAN_1,"Look!",12,0),
(33532,@TEXT_WOLVAR_ORPHAN_2,"Got you back!",12,0),
(33532,@TEXT_WOLVAR_ORPHAN_3,"Good snowball fight!",12,0),
(33532,@TEXT_WOLVAR_ORPHAN_4,"Look! That must be Kekek as a mighty warrior! See? What Kekek tell you?",12,0),
(33532,@TEXT_WOLVAR_ORPHAN_5,"Hmm... that Kekek very old. Must be elder, leader of Frenzyheart. This good. Kekek have good future as warrior and leader. Kekek very happy you bring him here. Orphan-lady never do that for Kekek.",12,0),
(33532,@TEXT_WOLVAR_ORPHAN_6,"Wow. At last, Kekek get to meet Hemet Nesingwary!",12,0),
(33532,@TEXT_WOLVAR_ORPHAN_7,"Even Frenzyheart know all about you after you come to Sholazar. Maybe you teach Kekek your tricks?",12,0),
(33532,@TEXT_WOLVAR_ORPHAN_8,"Not sure how reading helps. Kekek can't read anyway, but if Hemet Nesingwary say, Kekek try.",12,0),
(33532,@TEXT_WOLVAR_ORPHAN_9,"Maybe give up and throw book at animals, but try.",12,0),
(33532,@TEXT_WOLVAR_ORPHAN_10,"You think maybe one day, Kekek lead Frenzyheart home, like bear-men fight to get tree-city back? Kekek want own home, not city with purple men, not jungle with big-tongues.",12,0),
(33532,@TEXT_WOLVAR_ORPHAN_11,"Kekek thought we go see dragon queen. This just some elf-lady with funny horns.",12,0),
(33532,@TEXT_WOLVAR_ORPHAN_12,"But why? Dragons big and powerful. Elf-lady weak. Kekek want to see dragon queen's real form.",12,0),
(33532,@TEXT_WOLVAR_ORPHAN_13,"Oh! Now Kekek understand. Not want to be crushed by big dragon-lady. Maybe come back sometime when not so crowded. Nice to meet you, dragon-lady.",12,0);

DELETE FROM `game_event_creature_quest` WHERE `id`=33532;
INSERT INTO `game_event_creature_quest`(`eventEntry`,`id`,`quest`) VALUES
(10,33532,13938),
(10,33532,13960),
(10,33532,13930),
(10,33532,13951),
(10,33532,13934),
(10,33532,13955),
(10,33532,13957);

DELETE FROM `creature_involvedrelation` WHERE `id`=33532;
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES
(33532,13938),
(33532,13930),
(33532,13927),
(33532,13951),
(33532,13934),
(33532,13955),
(33532,13957);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry` IN (13955,13957,13938);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`comment`) VALUES
(19,13955,8,13930,'Accept quest 13955 - Quest 13930 needs to be rewarded'),
(19,13955,8,13934,'Accept quest 13955 - Quest 13934 needs to be rewarded'),
(19,13955,8,13951,'Accept quest 13955 - Quest 13951 needs to be rewarded'),
(19,13957,8,13930,'Accept quest 13957 - Quest 13930 needs to be rewarded'),
(19,13957,8,13934,'Accept quest 13957 - Quest 13934 needs to be rewarded'),
(19,13957,8,13951,'Accept quest 13957 - Quest 13951 needs to be rewarded'),
(19,13938,8,13957,'Accept quest 13938 - Quest 13957 needs to be rewarded'),
(20,13955,8,13930,'Show quest mark 13955 - Quest 13930 needs to be rewarded'),
(20,13955,8,13934,'Show quest mark 13955 - Quest 13934 needs to be rewarded'),
(20,13955,8,13951,'Show quest mark 13955 - Quest 13951 needs to be rewarded'),
(20,13957,8,13930,'Show quest mark 13957 - Quest 13930 needs to be rewarded'),
(20,13957,8,13934,'Show quest mark 13957 - Quest 13934 needs to be rewarded'),
(20,13957,8,13951,'Show quest mark 13957 - Quest 13951 needs to be rewarded'),
(20,13938,8,13957,'Show quest mark 13938 - Quest 13957 needs to be rewarded');

-- Blood Elf Orphan
UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`|2 WHERE `Id` IN (10945,10953,10951,10963);

DELETE FROM `game_event_creature_quest` WHERE `id`=22817;
INSERT INTO `game_event_creature_quest`(`eventEntry`,`id`,`quest`) VALUES
(10,22817,10945),
(10,22817,10953),
(10,22817,10951),
(10,22817,10963),
(10,22817,11975),
(10,22817,10967);

DELETE FROM `creature_involvedrelation` WHERE `id`=22817;
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES
(22817,10942),
(22817,10951),
(22817,11975),
(22817,10963);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry` IN (11975,10963,10967);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`comment`) VALUES
(19,11975,8,10945,'Accept quest 11975 - Quest 10945 needs to be rewarded'),
(19,11975,8,10953,'Accept quest 11975 - Quest 10953 needs to be rewarded'),
(19,11975,8,10951,'Accept quest 11975 - Quest 10951 needs to be rewarded'),
(19,10963,8,10945,'Accept quest 10963 - Quest 10945 needs to be rewarded'),
(19,10963,8,10953,'Accept quest 10963 - Quest 10953 needs to be rewarded'),
(19,10963,8,10951,'Accept quest 10963 - Quest 10951 needs to be rewarded'),
(19,10967,8,10963,'Accept quest 10967 - Quest 10963 needs to be rewarded'),
(20,11975,8,10945,'Show quest mark 11975 - Quest 10945 needs to be rewarded'),
(20,11975,8,10953,'Show quest mark 11975 - Quest 10953 needs to be rewarded'),
(20,11975,8,10951,'Show quest mark 11975 - Quest 10951 needs to be rewarded'),
(20,10963,8,10945,'Show quest mark 10963 - Quest 10945 needs to be rewarded'),
(20,10963,8,10953,'Show quest mark 10963 - Quest 10953 needs to be rewarded'),
(20,10963,8,10951,'Show quest mark 10963 - Quest 10951 needs to be rewarded'),
(20,10967,8,10963,'Show quest mark 10967 - Quest 10963 needs to be rewarded');

-- Draenei Orphan
UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`|2 WHERE `Id` IN (10956,10968,10950,10952,10954,10962);

DELETE FROM `game_event_creature_quest` WHERE `id`=22818;
INSERT INTO `game_event_creature_quest`(`eventEntry`,`id`,`quest`) VALUES
(10,22818,10952),
(10,22818,10950),
(10,22818,10966),
(10,22818,10954),
(10,22818,10956),
(10,22818,10962);

DELETE FROM `creature_involvedrelation` WHERE `id`=22818;
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES
(22818,10950),
(22818,10952),
(22818,10943),
(22818,10962);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry` IN (10956,10962,10966);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`comment`) VALUES
(19,10956,8,10950,'Accept quest 10956 - Quest 10950 needs to be rewarded'),
(19,10956,8,10954,'Accept quest 10956 - Quest 10954 needs to be rewarded'),
(19,10956,8,10952,'Accept quest 10956 - Quest 10952 needs to be rewarded'),
(19,10962,8,10950,'Accept quest 10962 - Quest 10950 needs to be rewarded'),
(19,10962,8,10954,'Accept quest 10962 - Quest 10954 needs to be rewarded'),
(19,10962,8,10952,'Accept quest 10962 - Quest 10952 needs to be rewarded'),
(19,10966,8,10962,'Accept quest 10966 - Quest 10962 needs to be rewarded'),
(20,10956,8,10950,'Show quest mark 10956 - Quest 10950 needs to be rewarded'),
(20,10956,8,10954,'Show quest mark 10956 - Quest 10954 needs to be rewarded'),
(20,10956,8,10952,'Show quest mark 10956 - Quest 10952 needs to be rewarded'),
(20,10962,8,10950,'Show quest mark 10962 - Quest 10950 needs to be rewarded'),
(20,10962,8,10954,'Show quest mark 10962 - Quest 10954 needs to be rewarded'),
(20,10962,8,10952,'Show quest mark 10962 - Quest 10952 needs to be rewarded'),
(20,10966,8,10962,'Show quest mark 10966 - Quest 10962 needs to be rewarded');

-- Human Orphan
DELETE FROM `creature_questrelation` WHERE `id`=14305;

DELETE FROM `game_event_creature_quest` WHERE `id`=14305;
INSERT INTO `game_event_creature_quest`(`eventEntry`,`id`,`quest`) VALUES
(10,14305,171),
(10,14305,558),
(10,14305,1687),
(10,14305,1479),
(10,14305,1558),
(10,14305,4822);

DELETE FROM `creature_involvedrelation` WHERE `id`=14305;
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES
(14305,1468),
(14305,558),
(14305,1687),
(14305,1479),
(14305,1558),
(14305,4822);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry` IN (558,4822,171);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`comment`) VALUES
(19,558,8,1687,'Accept quest 558 - Quest 1687 needs to be rewarded'),
(19,558,8,1558,'Accept quest 558 - Quest 1558 needs to be rewarded'),
(19,558,8,1479,'Accept quest 558 - Quest 1479 needs to be rewarded'),
(19,558,16,1101,'Accept quest 558 - Needs to be in race mask 1101'),
(19,4822,8,1687,'Accept quest 4822 - Quest 1687 needs to be rewarded'),
(19,4822,8,1558,'Accept quest 4822 - Quest 1558 needs to be rewarded'),
(19,4822,8,1479,'Accept quest 4822 - Quest 1479 needs to be rewarded'),
(19,171,8,4822,'Accept quest 171 - Quest 4822 needs to be rewarded'),
(20,558,8,1687,'Show quest mark 558 - Quest 1687 needs to be rewarded'),
(20,558,8,1558,'Show quest mark 558 - Quest 1558 needs to be rewarded'),
(20,558,8,1479,'Show quest mark 558 - Quest 1479 needs to be rewarded'),
(20,558,16,1101,'Show quest mark 558 - Needs to be in race mask 1101'),
(20,4822,8,1687,'Show quest mark 4822 - Quest 1687 needs to be rewarded'),
(20,4822,8,1558,'Show quest mark 4822 - Quest 1558 needs to be rewarded'),
(20,4822,8,1479,'Show quest mark 4822 - Quest 1479 needs to be rewarded'),
(20,171,8,4822,'Show quest mark 171 - Quest 4822 needs to be rewarded');

-- Orcish Orphan
DELETE FROM `creature_questrelation` WHERE `id`=14444;

DELETE FROM `game_event_creature_quest` WHERE `id`=14444;
INSERT INTO `game_event_creature_quest`(`eventEntry`,`id`,`quest`) VALUES
(10,14444,910),
(10,14444,911),
(10,14444,1800),
(10,14444,925),
(10,14444,915),
(10,14444,5502);

DELETE FROM `creature_involvedrelation` WHERE `id`=14444;
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES
(14444,925),
(14444,172),
(14444,910),
(14444,911),
(14444,1800),
(14444,915);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry` IN (915,925,5502);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`comment`) VALUES
(19,925,8,910,'Accept quest 925 - Quest 910 needs to be rewarded'),
(19,925,8,911,'Accept quest 925 - Quest 911 needs to be rewarded'),
(19,925,8,1800,'Accept quest 925 - Quest 1800 needs to be rewarded'),
(19,915,8,910,'Accept quest 915 - Quest 910 needs to be rewarded'),
(19,915,8,911,'Accept quest 915 - Quest 911 needs to be rewarded'),
(19,915,8,1800,'Accept quest 915 - Quest 1800 needs to be rewarded'),
(19,5502,8,925,'Accept quest 5502 - Quest 925 needs to be rewarded'),
(20,925,8,910,'Show quest mark 925 - Quest 910 needs to be rewarded'),
(20,925,8,911,'Show quest mark 925 - Quest 911 needs to be rewarded'),
(20,925,8,1800,'Show quest mark 925 - Quest 1800 needs to be rewarded'),
(20,915,8,910,'Show quest mark 915 - Quest 910 needs to be rewarded'),
(20,915,8,911,'Show quest mark 915 - Quest 911 needs to be rewarded'),
(20,915,8,1800,'Show quest mark 915 - Quest 1800 needs to be rewarded'),
(20,5502,8,925,'Show quest mark 5502 - Quest 925 needs to be rewarded');

-- Home of the bear-men
SET @GUIDS = 85179;
SET @GUID_GRIZZLEMAW_TRIGGER_1 = @GUIDS + 0;
SET @GUID_GRIZZLEMAW_TRIGGER_2 = @GUIDS + 1;
SET @GUID_GRIZZLEMAW_TRIGGER_3 = @GUIDS + 2;

UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_grizzlemaw_cw_trigger',`flags_extra`=0 WHERE `entry`=36209;

DELETE FROM `creature` WHERE `guid` IN (@GUID_GRIZZLEMAW_TRIGGER_1,@GUID_GRIZZLEMAW_TRIGGER_2,@GUID_GRIZZLEMAW_TRIGGER_3);
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`) VALUES
(@GUID_GRIZZLEMAW_TRIGGER_1,36209,571,4068.82,-3811,223.4),
(@GUID_GRIZZLEMAW_TRIGGER_2,36209,571,4073.2,-3734.354,222.6634),
(@GUID_GRIZZLEMAW_TRIGGER_3,36209,571,3923.109,-3763.967,165.362);

-- Elder Kekek
SET @GUID_KEKEK = @GUIDS + 3;
SET @TEXT_ELDER_KEKEK_1 = 1;

UPDATE `creature_template` SET `ScriptName`='npc_elder_kekek' WHERE `entry`=34387;

DELETE FROM `creature` WHERE `guid`=@GUID_KEKEK OR `id`=34387;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`) VALUES
(@GUID_KEKEK,34387,571,4181.482,-461.453,120.728,1.398097);

DELETE FROM `creature_text` WHERE `entry`=34387;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`emote`) VALUE
(34387,@TEXT_ELDER_KEKEK_1,"No worry, Kekek. You grow up, be strong for Frenzyheart. You lead people back to old home, where there no big-tongue babies.",12,0);

-- Alexstraza
SET @TEXT_ALEXSTRASZA_2 = 2;
SET @TEXT_KRASUS_8 = 8;

UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_alexstraza_the_lifebinder' WHERE `entry`=26917;

DELETE FROM `creature_text` WHERE (`entry`=26917 AND `groupid`=@TEXT_ALEXSTRASZA_2) OR (`entry`=27990 AND `groupid`=@TEXT_KRASUS_8);
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`emote`) VALUE
(26917,@TEXT_ALEXSTRASZA_2,"If I was in my dragon form, there wouldn't be any room for anyone else, little one.",12,0),
(27990,@TEXT_KRASUS_8,"Rest assured, Kekek, she is the queen of the dragons. We often take the forms of smaller beings when we work with them.",12,0);

-- High Oracle Soo Roo
SET @GUID_SOO_ROO = @GUIDS + 4;
SET @TEXT_SOO_ROO_1 = 1;

UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_high_oracle_soo_roo' WHERE `entry`=34386;

DELETE FROM `creature_text` WHERE `entry`=34386;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`emote`) VALUE
(34386,@TEXT_SOO_ROO_1,"We remember this visit, yes we do. Never forget what you learn from your new friend, little Roo. You got great future ahead.",12,0);

DELETE FROM `creature` WHERE `guid`=@GUID_SOO_ROO OR `id`=34386;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`) VALUES
(@GUID_SOO_ROO,34386,571,4120.996,-329.486,121.443817,0.299253);

-- Nesingwary
SET @TEXT_NESINGWARY_1 = 1;

DELETE FROM `creature_text` WHERE `entry`=27986;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`emote`) VALUE
(27986,@TEXT_NESINGWARY_1,"Well, lad, you can start by readin' The Green Hills of Stranglethorn. Then, maybe you can join me on one of my safaris. What do you say?",12,0);

-- Snowfall Glade Playmate
SET @GUID_SNOWFALL_GLADE_PLAYMATE = @GUIDS + 5;
SET @TEXT_SNOWFALL_GLADE_PLAYMATE_1 = 1;
SET @TEXT_SNOWFALL_GLADE_PLAYMATE_2 = 2;

UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_snowfall_glade_playmate' WHERE `entry`=34490;

DELETE FROM `creature_text` WHERE `entry`=34490;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`emote`) VALUE
(34490,@TEXT_SNOWFALL_GLADE_PLAYMATE_1,"Better watch out!",12,0),
(34490,@TEXT_SNOWFALL_GLADE_PLAYMATE_2,"Got you good!",12,0);

DELETE FROM `creature` WHERE `guid`=@GUID_SNOWFALL_GLADE_PLAYMATE OR `id`=34490;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`) VALUES
(@GUID_SNOWFALL_GLADE_PLAYMATE,34490,571,3325.193,1026.451,138.1712,2.062184);

-- Winterfin Playmate
SET @GUID_WINTERFIN_PLAYMATE = @GUIDS + 6;
SET @TEXT_WINTERFIN_PLAYMATE_1 = 1;
SET @TEXT_WINTERFIN_PLAYMATE_2 = 2;

UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_winterfin_playmate' WHERE `entry`=34489;

DELETE FROM `creature_text` WHERE `entry`=34489;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`emote`) VALUE
(34489,@TEXT_WINTERFIN_PLAYMATE_1,"Wanna see what I can do?",12,0),
(34489,@TEXT_WINTERFIN_PLAYMATE_2,"Now dance together!",12,0);

DELETE FROM `creature` WHERE `guid`=@GUID_WINTERFIN_PLAYMATE OR `id`=34489;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`) VALUES
(@GUID_WINTERFIN_PLAYMATE,34489,571,4382.502,6066.199,0.724562,3.571894);

-- Biggest Tree Ever
SET @GUID_BIGGEST_TREE_TRIGGER = @GUIDS + 7;

UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_the_biggest_tree',`flags_extra`=0 WHERE `entry`=34381;

DELETE FROM `creature` WHERE `guid`=@GUID_BIGGEST_TREE_TRIGGER OR `id`=34381;
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`) VALUES
(@GUID_BIGGEST_TREE_TRIGGER,34381,571,4022.666,-3777.682,115.443588,4.857019);

-- Meeting A Great One
UPDATE `creature_template` SET `ScriptName`='npc_the_etymidian' WHERE `entry`=28092;

-- POIs
DELETE FROM `quest_poi` WHERE `questId` IN (13956,13929,13950,13951,13957,13933,13934,13930,13954,13955);
INSERT INTO `quest_poi`(`questId`,`objIndex`,`mapid`,`WorldMapAreaId`,`unk4`) VALUES
(13956,16,1,201,3),
(13929,16,571,490,3),
(13950,16,571,486,3),
(13951,16,571,488,3),
(13957,16,571,493,3),
(13933,16,571,488,3),
(13934,16,571,488,3),
(13930,16,571,490,3),
(13954,16,571,488,3),
(13955,16,571,488,3);

DELETE FROM `quest_poi_points` WHERE `questid` IN (13956,13929,13950,13951,13957,13933,13934,13930,13954,13955);
INSERT INTO `quest_poi_points`(`questId`,`x`,`y`) VALUES
(13956,-6193,-1223),
(13929,4022,-3777),
(13950,4382,6066),
(13951,3325,1026),
(13957,5584,5748),
(13933,4121,-329),
(13934,4181,-461),
(13930,4071,-3773),
(13954,3530,271),
(13955,3530,271);

-- NPC areatriggers
SET @GUID_AERIS_LANDING_TRIGGER = @GUIDS + 8;
SET @GUID_SILVERMOON_TRIGGER_01 = @GUIDS + 9;
SET @GUID_AUCHINDOUN_TRIGGER = @GUIDS + 10;
SET @GUID_SPOREGGAR_TRIGGER = @GUIDS + 11;
SET @GUID_THRONE_OF_ELEMENTS_TRIGGER = @GUIDS + 12;

UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=0,`unit_flags`=33554432,`ScriptName`='npc_cw_area_trigger',`AIName`='' WHERE `entry` IN (22905,22851,22838,22866,22831,22829,22872,22839);

DELETE FROM `creature` WHERE `guid` IN (@GUID_SILVERMOON_TRIGGER_01,@GUID_AERIS_LANDING_TRIGGER,@GUID_AUCHINDOUN_TRIGGER,@GUID_SPOREGGAR_TRIGGER,@GUID_THRONE_OF_ELEMENTS_TRIGGER);
INSERT INTO `creature`(`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`) VALUES
(@GUID_AERIS_LANDING_TRIGGER,22838,530,-2075.759,8559.336,23.027,4.857019),
(@GUID_SILVERMOON_TRIGGER_01,22866,530,9506.086,-7329.313,14.397272,0),
(@GUID_AUCHINDOUN_TRIGGER,22831,530,-3320.860,4925.095,-101.1,0),
(@GUID_SPOREGGAR_TRIGGER,22829,530,203.587,8550.11,22.3256,0),
(@GUID_THRONE_OF_ELEMENTS_TRIGGER,22839,530,-781.294,6943.52,33.3344,0);

-- Misc
DELETE `game_event_creature` FROM `game_event_creature` INNER JOIN `creature` ON `creature`.`guid`=`game_event_creature`.`guid`
WHERE `id` IN (22905,22851,22838,22866,22831,22829,22872,22839,14450,22819,14451,34365,34387,34386,34490,34489,34381,36209);
INSERT INTO `game_event_creature`(`eventEntry`,`guid`) SELECT 10,`guid` FROM `creature`
WHERE `id` IN (22905,22851,22838,22866,22831,22829,22872,22839,14450,22819,14451,34365,34387,34386,34490,34489,34381,36209);

DELETE FROM `game_event_npc_vendor` WHERE `eventEntry`=10 AND `item`=46693;
INSERT INTO `game_event_npc_vendor` (`eventEntry`, `guid`, `item`) VALUES
(10,99369,46693),
(10,97984,46693);

UPDATE `item_template` SET `minMoneyLoot`=50000,`maxMoneyLoot`=50000 WHERE `entry`=23022;
UPDATE `item_template` SET `HolidayId`=201 WHERE `entry` IN (46396,46397,31880,31881,18598,18597);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (23012,23013,39478,39479,65352,65353);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ErrorTextId`,`Comment`) VALUES
(17,0,23012,0,12,10,0,"Orphan Whistle only while children's week"),
(17,0,23013,0,12,10,0,"Orphan Whistle only while children's week"),
(17,0,39478,0,12,10,0,"Orphan Whistle only while children's week"),
(17,0,39479,0,12,10,0,"Orphan Whistle only while children's week"),
(17,0,65352,0,12,10,0,"Orphan Whistle only while children's week"),
(17,0,65353,0,12,10,0,"Orphan Whistle only while children's week");

UPDATE `quest_poi_points` SET `x`=1642,`y`=239 WHERE `questId`=1800 AND `id`=0 AND `idx`=0;
UPDATE `quest_poi_points` SET `x`=-248,`y`=956 WHERE `questId`=10952 AND `id`=0 AND `idx`=0;
UPDATE `quest_poi_points` SET `x`=-11400.211,`y`=1944.599 WHERE `questId`=1687 AND `id`=0 AND `idx`=0;
UPDATE `quest_poi_points` SET `x`=-998.183,`y`=-3822.07 WHERE `questId`=910 AND `id`=0 AND `idx`=0;
UPDATE `quest_poi_points` SET `x`=1260.812,`y`=-2223.765 WHERE `questId`=911 AND `id`=0 AND `idx`=0;
UPDATE `quest_poi_points` SET `x`=9933,`y`=2500 WHERE `questId`=1479 AND `id`=0 AND `idx`=0;
UPDATE `quest_poi_points` SET `x`=-2075.759,`y`=8559.336 WHERE `questId`=10954 AND `id`=0 AND `idx`=0;
UPDATE `quest_poi_points` SET `x`=9506,`y`=-7329 WHERE `questId`=11975 AND `id`=0 AND `idx`=0;
UPDATE `quest_poi_points` SET `x`=-3320.860,`y`=4925.095 WHERE `questId`=10950 AND `id`=0 AND `idx`=0;
UPDATE `quest_poi_points` SET `x`=203.587,`y`=8550.11 WHERE `questId`=10945 AND `id`=0 AND `idx`=0;
UPDATE `quest_poi_points` SET `x`=-781.294,`y`=6943.52 WHERE `questId`=10953 AND `id`=0 AND `idx`=0;
