UPDATE `gossip_menu_option` SET `OptionIcon`=10, `VerifiedBuild`=15595 WHERE (`MenuId`=12949 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionIcon`=11, `OptionText`='Yes. I do.', `VerifiedBuild`=15595 WHERE (`MenuId`=4463 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='I\'m not here to fight.  I\'ve only been asked to speak with you.', `VerifiedBuild`=15595 WHERE (`MenuId`=12485 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='What elekks are for sale?', `OptionBroadcastTextId`=18586, `VerifiedBuild`=15595 WHERE (`MenuId`=8213 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Chromie, you and I both know what\'s going to happen in this time stream. We\'ve seen this all before.$B$BCan you just skip us ahead to all the real action?', `VerifiedBuild`=15595 WHERE (`MenuId`=9586 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionText`='I am ready.', `VerifiedBuild`=15595 WHERE (`MenuId`=11156 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='You talk to Undertaker Mordo.  He\'ll tell you what to do.  That\'s all I know.', `VerifiedBuild`=15595 WHERE (`MenuId`=12489 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Calm down, Valdred.  Undertaker Mordo probably sewed some new ones on for you.', `VerifiedBuild`=15595 WHERE (`MenuId`=12488 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Don\'t you remember?  You died.', `VerifiedBuild`=15595 WHERE (`MenuId`=12487 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='I\'m not an abomination, I\'m simply undead.  I just want to speak with you.', `VerifiedBuild`=15595 WHERE (`MenuId`=12483 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='I am here for training.', `VerifiedBuild`=15595 WHERE (`MenuId`=4007 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionIcon`=1, `OptionText`='I want to browse your goods.', `OptionBroadcastTextId`=3370, `VerifiedBuild`=15595 WHERE (`MenuId`=2890 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionText`='Lay your hand on the stone.', `VerifiedBuild`=15595 WHERE (`MenuId`=9274 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Lay your hand on the stone.', `VerifiedBuild`=15595 WHERE (`MenuId`=9273 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='I must return to the world of shadows, Koltira. Send me back.', `VerifiedBuild`=15595 WHERE (`MenuId`=9456 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='For the Horde!\n\nArm yourself from the crates that surround us and report to Agmar\'s Hammer, east of here. Your first trial as a member of the Horde is to survive the journey.\n\nLok\'tar ogar!', `VerifiedBuild`=15595 WHERE (`MenuId`=9303 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Then repeat after me: \"Lok\'tar ogar! Victory or death - it is these words that bind me to the Horde. For they are the most sacred and fundamental of truths to any warrior of the Horde.\n\nI give my flesh and blood freely to the Warchief. I am the instrument of my Warchief\'s desire. I am a weapon of my Warchief\'s command.\n\nFrom this moment until the end of days I live and die - For the Horde!\"', `VerifiedBuild`=15595 WHERE (`MenuId`=9304 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='I wish to train, Aesom.', `OptionBroadcastTextId`=15943, `VerifiedBuild`=15595 WHERE (`MenuId`=7517 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='I require training, Nissa.', `OptionBroadcastTextId`=8369, `VerifiedBuild`=15595 WHERE (`MenuId`=4762 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='I\'m afraid not, Schneider. Your time has come!', `VerifiedBuild`=15595 WHERE (`MenuId`=9507 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Afraid not. Your days as a sanitation engineer are coming to an end.', `VerifiedBuild`=15595 WHERE (`MenuId`=9509 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='No, chancellor, I wouldn\'t say that I\'m here to \'rescue\' you, per se.', `VerifiedBuild`=15595 WHERE (`MenuId`=9510 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Lilian, you\'re one of the Forsaken, like me.  Which brings the question: why did the Scarlet Crusade put you in a cage?  They usually kill the undead on sight.', `OptionBroadcastTextId`=38988, `VerifiedBuild`=15595 WHERE (`MenuId`=11134 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='I\'m here to rescue you.', `OptionBroadcastTextId`=38986, `VerifiedBuild`=15595 WHERE (`MenuId`=11135 AND `OptionIndex`=0);
UPDATE `conditions` SET `SourceGroup`=11135 WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11134 AND `SourceEntry`=0 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=9 AND `ConditionTarget`=0 AND `ConditionValue1`=24979 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
DELETE FROM `gossip_menu` WHERE  `MenuID`=11134 AND `TextID`=15487;
DELETE FROM `gossip_menu` WHERE  `MenuID`=11135 AND `TextID`=15488;

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=11351 AND `OptionIndex`=0) OR (`MenuId`=11352 AND `OptionIndex`=0) OR (`MenuId`=11581 AND `OptionIndex`=0) OR (`MenuId`=11580 AND `OptionIndex`=0) OR (`MenuId`=11579 AND `OptionIndex`=0) OR (`MenuId`=11578 AND `OptionIndex`=0) OR (`MenuId`=11577 AND `OptionIndex`=0) OR (`MenuId`=11576 AND `OptionIndex`=0) OR (`MenuId`=11575 AND `OptionIndex`=0) OR (`MenuId`=11574 AND `OptionIndex`=0) OR (`MenuId`=12210 AND `OptionIndex`=0) OR (`MenuId`=12211 AND `OptionIndex`=0) OR (`MenuId`=12215 AND `OptionIndex`=0) OR (`MenuId`=12214 AND `OptionIndex`=0) OR (`MenuId`=12222 AND `OptionIndex`=0) OR (`MenuId`=12221 AND `OptionIndex`=0) OR (`MenuId`=12220 AND `OptionIndex`=0) OR (`MenuId`=12218 AND `OptionIndex`=0) OR (`MenuId`=12217 AND `OptionIndex`=0) OR (`MenuId`=12067 AND `OptionIndex`=0) OR (`MenuId`=11969 AND `OptionIndex`=1) OR (`MenuId`=11976 AND `OptionIndex`=7) OR (`MenuId`=11969 AND `OptionIndex`=2) OR (`MenuId`=11976 AND `OptionIndex`=6) OR (`MenuId`=11976 AND `OptionIndex`=5) OR (`MenuId`=11976 AND `OptionIndex`=4) OR (`MenuId`=11976 AND `OptionIndex`=3) OR (`MenuId`=11976 AND `OptionIndex`=2) OR (`MenuId`=11976 AND `OptionIndex`=1) OR (`MenuId`=11976 AND `OptionIndex`=0) OR (`MenuId`=11969 AND `OptionIndex`=3) OR (`MenuId`=11969 AND `OptionIndex`=4) OR (`MenuId`=11977 AND `OptionIndex`=3) OR (`MenuId`=11969 AND `OptionIndex`=5) OR (`MenuId`=11977 AND `OptionIndex`=2) OR (`MenuId`=11977 AND `OptionIndex`=1) OR (`MenuId`=11977 AND `OptionIndex`=0) OR (`MenuId`=11969 AND `OptionIndex`=6) OR (`MenuId`=11978 AND `OptionIndex`=3) OR (`MenuId`=11969 AND `OptionIndex`=7) OR (`MenuId`=11978 AND `OptionIndex`=2) OR (`MenuId`=11978 AND `OptionIndex`=1) OR (`MenuId`=11978 AND `OptionIndex`=0) OR (`MenuId`=11969 AND `OptionIndex`=0) OR (`MenuId`=11767 AND `OptionIndex`=1) OR (`MenuId`=11592 AND `OptionIndex`=1) OR (`MenuId`=11591 AND `OptionIndex`=1) OR (`MenuId`=11590 AND `OptionIndex`=1) OR (`MenuId`=11589 AND `OptionIndex`=2) OR (`MenuId`=11588 AND `OptionIndex`=2) OR (`MenuId`=11593 AND `OptionIndex`=2) OR (`MenuId`=11586 AND `OptionIndex`=0) OR (`MenuId`=11590 AND `OptionIndex`=0) OR (`MenuId`=11589 AND `OptionIndex`=0) OR (`MenuId`=11588 AND `OptionIndex`=0) OR (`MenuId`=11593 AND `OptionIndex`=0) OR (`MenuId`=11562 AND `OptionIndex`=0) OR (`MenuId`=11559 AND `OptionIndex`=0) OR (`MenuId`=11560 AND `OptionIndex`=0) OR (`MenuId`=11558 AND `OptionIndex`=0) OR (`MenuId`=11557 AND `OptionIndex`=0) OR (`MenuId`=11555 AND `OptionIndex`=0) OR (`MenuId`=13012 AND `OptionIndex`=1) OR (`MenuId`=6225 AND `OptionIndex`=1) OR (`MenuId`=13019 AND `OptionIndex`=1) OR (`MenuId`=6575 AND `OptionIndex`=1) OR (`MenuId`=13018 AND `OptionIndex`=1) OR (`MenuId`=11551 AND `OptionIndex`=0) OR (`MenuId`=11379 AND `OptionIndex`=0) OR (`MenuId`=10620 AND `OptionIndex`=0) OR (`MenuId`=10624 AND `OptionIndex`=0) OR (`MenuId`=10622 AND `OptionIndex`=0) OR (`MenuId`=12795 AND `OptionIndex`=0) OR (`MenuId`=12981 AND `OptionIndex`=0) OR (`MenuId`=10192 AND `OptionIndex`=1) OR (`MenuId`=10192 AND `OptionIndex`=0) OR (`MenuId`=7421 AND `OptionIndex`=0) OR (`MenuId`=9900 AND `OptionIndex`=1) OR (`MenuId`=12979 AND `OptionIndex`=0) OR (`MenuId`=12897 AND `OptionIndex`=0) OR (`MenuId`=7468 AND `OptionIndex`=0) OR (`MenuId`=12356 AND `OptionIndex`=0) OR (`MenuId`=12361 AND `OptionIndex`=0) OR (`MenuId`=12358 AND `OptionIndex`=0) OR (`MenuId`=1294 AND `OptionIndex`=0) OR (`MenuId`=3331 AND `OptionIndex`=5) OR (`MenuId`=3329 AND `OptionIndex`=4) OR (`MenuId`=3331 AND `OptionIndex`=4) OR (`MenuId`=3329 AND `OptionIndex`=5) OR (`MenuId`=3331 AND `OptionIndex`=3) OR (`MenuId`=3331 AND `OptionIndex`=2) OR (`MenuId`=3331 AND `OptionIndex`=1) OR (`MenuId`=3331 AND `OptionIndex`=0) OR (`MenuId`=8276 AND `OptionIndex`=0) OR (`MenuId`=11795 AND `OptionIndex`=0) OR (`MenuId`=11794 AND `OptionIndex`=1) OR (`MenuId`=11877 AND `OptionIndex`=1) OR (`MenuId`=7706 AND `OptionIndex`=0) OR (`MenuId`=7581 AND `OptionIndex`=0) OR (`MenuId`=7581 AND `OptionIndex`=1) OR (`MenuId`=7552 AND `OptionIndex`=1) OR (`MenuId`=7552 AND `OptionIndex`=0) OR (`MenuId`=8908 AND `OptionIndex`=0) OR (`MenuId`=13162 AND `OptionIndex`=0) OR (`MenuId`=11892 AND `OptionIndex`=1) OR (`MenuId`=8767 AND `OptionIndex`=0) OR (`MenuId`=8767 AND `OptionIndex`=1) OR (`MenuId`=11144 AND `OptionIndex`=0) OR (`MenuId`=1186 AND `OptionIndex`=0) OR (`MenuId`=10962 AND `OptionIndex`=0) OR (`MenuId`=11026 AND `OptionIndex`=0) OR (`MenuId`=11027 AND `OptionIndex`=0) OR (`MenuId`=11025 AND `OptionIndex`=0) OR (`MenuId`=11024 AND `OptionIndex`=0) OR (`MenuId`=10941 AND `OptionIndex`=1) OR (`MenuId`=10896 AND `OptionIndex`=0) OR (`MenuId`=10894 AND `OptionIndex`=0) OR (`MenuId`=10895 AND `OptionIndex`=0) OR (`MenuId`=3558 AND `OptionIndex`=12) OR (`MenuId`=3558 AND `OptionIndex`=11) OR (`MenuId`=3558 AND `OptionIndex`=10) OR (`MenuId`=3558 AND `OptionIndex`=9) OR (`MenuId`=3558 AND `OptionIndex`=8) OR (`MenuId`=3558 AND `OptionIndex`=7) OR (`MenuId`=3558 AND `OptionIndex`=6) OR (`MenuId`=3558 AND `OptionIndex`=5) OR (`MenuId`=3558 AND `OptionIndex`=4) OR (`MenuId`=3558 AND `OptionIndex`=3) OR (`MenuId`=3558 AND `OptionIndex`=2) OR (`MenuId`=3558 AND `OptionIndex`=1) OR (`MenuId`=3558 AND `OptionIndex`=0) OR (`MenuId`=1297 AND `OptionIndex`=0) OR (`MenuId`=4557 AND `OptionIndex`=1) OR (`MenuId`=4556 AND `OptionIndex`=1) OR (`MenuId`=2304 AND `OptionIndex`=1) OR (`MenuId`=1293 AND `OptionIndex`=0) OR (`MenuId`=11240 AND `OptionIndex`=0) OR (`MenuId`=12046 AND `OptionIndex`=1) OR (`MenuId`=10708 AND `OptionIndex`=0) OR (`MenuId`=12890 AND `OptionIndex`=0) OR (`MenuId`=10316 AND `OptionIndex`=3) OR (`MenuId`=12975 AND `OptionIndex`=0) OR (`MenuId`=12974 AND `OptionIndex`=0) OR (`MenuId`=10502 AND `OptionIndex`=4) OR (`MenuId`=12950 AND `OptionIndex`=0) OR (`MenuId`=6953 AND `OptionIndex`=0) OR (`MenuId`=3285 AND `OptionIndex`=4) OR (`MenuId`=7492 AND `OptionIndex`=0) OR (`MenuId`=7493 AND `OptionIndex`=0) OR (`MenuId`=11322 AND `OptionIndex`=1) OR (`MenuId`=11322 AND `OptionIndex`=0) OR (`MenuId`=9615 AND `OptionIndex`=1) OR (`MenuId`=8908 AND `OptionIndex`=1) OR (`MenuId`=1971 AND `OptionIndex`=0) OR (`MenuId`=5768 AND `OptionIndex`=0) OR (`MenuId`=5769 AND `OptionIndex`=0) OR (`MenuId`=5765 AND `OptionIndex`=0) OR (`MenuId`=5764 AND `OptionIndex`=0) OR (`MenuId`=5102 AND `OptionIndex`=0) OR (`MenuId`=12799 AND `OptionIndex`=4) OR (`MenuId`=12799 AND `OptionIndex`=2) OR (`MenuId`=12168 AND `OptionIndex`=3) OR (`MenuId`=11461 AND `OptionIndex`=0) OR (`MenuId`=11544 AND `OptionIndex`=0) OR (`MenuId`=11541 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(11351, 0, 11350, 0),
(11352, 0, 11351, 0),
(11581, 0, 11582, 0),
(11580, 0, 11581, 0),
(11579, 0, 11580, 0),
(11578, 0, 11579, 0),
(11577, 0, 11578, 0),
(11576, 0, 11577, 0),
(11575, 0, 11576, 0),
(11574, 0, 11575, 0),
(12210, 0, 12212, 0),
(12211, 0, 12210, 0),
(12215, 0, 12216, 0),
(12214, 0, 12215, 0),
(12222, 0, 12223, 0),
(12221, 0, 12222, 0),
(12220, 0, 12221, 0),
(12218, 0, 12219, 0),
(12217, 0, 12218, 0),
(12067, 0, 12068, 0),
(11969, 1, 11973, 0),
(11976, 7, 11981, 0),
(11969, 2, 11976, 0),
(11976, 6, 11988, 0),
(11976, 5, 11987, 0),
(11976, 4, 11986, 0),
(11976, 3, 11985, 0),
(11976, 2, 11982, 0),
(11976, 1, 11981, 0),
(11976, 0, 11980, 0),
(11969, 3, 11974, 0),
(11969, 4, 11975, 0),
(11977, 3, 11991, 0),
(11969, 5, 11977, 0),
(11977, 2, 12442, 0),
(11977, 1, 11990, 0),
(11977, 0, 11989, 0),
(11969, 6, 11975, 0),
(11978, 3, 11992, 0),
(11969, 7, 11978, 0),
(11978, 2, 11994, 0),
(11978, 1, 11990, 0),
(11978, 0, 11992, 0),
(11969, 0, 11973, 0),
(11767, 1, 4463, 0),
(11592, 1, 11595, 0),
(11591, 1, 11592, 0),
(11590, 1, 11591, 0),
(11589, 2, 11590, 0),
(11588, 2, 11589, 0),
(11593, 2, 11588, 0),
(11586, 0, 11593, 0),
(11590, 0, 11591, 0),
(11589, 0, 11590, 0),
(11588, 0, 11589, 0),
(11593, 0, 11588, 0),
(11562, 0, 11561, 0),
(11559, 0, 11562, 0),
(11560, 0, 11559, 0),
(11558, 0, 11560, 0),
(11557, 0, 11558, 0),
(11555, 0, 11557, 0),
(13012, 1, 13064, 0),
(6225, 1, 13064, 0),
(13019, 1, 13064, 0),
(6575, 1, 13064, 460),
(13018, 1, 13064, 460),
(11551, 0, 11552, 0),
(11379, 0, 11551, 0),
(10620, 0, 10619, 0),
(10624, 0, 10623, 0),
(10622, 0, 10621, 0),
(12795, 0, 12981, 0),
(12981, 0, 12982, 0),
(10192, 1, 10196, 0),
(10192, 0, 10196, 0),
(7421, 0, 7422, 0),
(9900, 1, 9899, 0),
(12979, 0, 12980, 0),
(12897, 0, 12979, 0),
(7468, 0, 1221, 0),
(12356, 0, 12357, 0),
(12361, 0, 12360, 0),
(12358, 0, 12359, 0),
(1294, 0, 1221, 0),
(3331, 5, 3330, 0),
(3329, 4, 3316, 0),
(3331, 4, 3329, 0),
(3329, 5, 3317, 0),
(3331, 3, 4903, 0),
(3331, 2, 3313, 0),
(3331, 1, 3312, 0),
(3331, 0, 3311, 0),
(8276, 0, 8259, 0),
(11795, 0, 11794, 0),
(11794, 1, 11795, 0),
(11877, 1, 4463, 0),
(7706, 0, 8533, 0),
(7581, 0, 7701, 0),
(7581, 1, 7584, 0),
(7552, 1, 7689, 0),
(7552, 0, 7556, 0),
(8908, 0, 8920, 0),
(13162, 0, 13163, 0),
(11892, 1, 6944, 0),
(8767, 0, 8765, 0),
(8767, 1, 8764, 0),
(11144, 0, 11183, 0),
(1186, 0, 1187, 0),
(10962, 0, 10961, 0),
(11026, 0, 11028, 0),
(11027, 0, 11026, 0),
(11025, 0, 11027, 0),
(11024, 0, 11025, 0),
(10941, 1, 11024, 0),
(10896, 0, 10897, 0),
(10894, 0, 10896, 0),
(10895, 0, 10894, 0),
(3558, 12, 3557, 0),
(3558, 11, 3556, 0),
(3558, 10, 3555, 0),
(3558, 9, 3554, 0),
(3558, 8, 10013, 0),
(3558, 7, 3553, 0),
(3558, 6, 3552, 0),
(3558, 5, 3551, 0),
(3558, 4, 3550, 0),
(3558, 3, 3549, 0),
(3558, 2, 3548, 0),
(3558, 1, 3547, 0),
(3558, 0, 3546, 0),
(1297, 0, 1221, 0),
(4557, 1, 4461, 0),
(4556, 1, 4461, 0),
(2304, 1, 4461, 0),
(1293, 0, 1221, 0),
(11240, 0, 11239, 0),
(12046, 1, 12047, 0),
(10708, 0, 10711, 0),
(12890, 0, 12889, 0),
(10316, 3, 10315, 0),
(12975, 0, 12976, 0),
(12974, 0, 12975, 0),
(10502, 4, 10505, 0),
(12950, 0, 12951, 0),
(6953, 0, 6952, 0),
(3285, 4, 3283, 0),
(7492, 0, 7491, 0),
(7493, 0, 7492, 0),
(11322, 1, 11325, 0),
(11322, 0, 11324, 0),
(9615, 1, 9616, 0),
(8908, 1, 8920, 0),
(1971, 0, 8765, 0),
(5768, 0, 5767, 0),
(5769, 0, 5768, 0),
(5765, 0, 5769, 0),
(5764, 0, 5765, 0),
(5102, 0, 5764, 0),
(12799, 4, 13002, 0),
(12799, 2, 12904, 0),
(12168, 3, 11496, 0),
(11461, 0, 11461, 0),
(11544, 0, 11545, 0),
(11541, 0, 11544, 0);

UPDATE `gossip_menu_option_action` SET `ActionMenuId`=9014 WHERE (`MenuId`=9015 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=464 WHERE (`MenuId`=13076 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=8929 WHERE (`MenuId`=8886 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=7787 WHERE (`MenuId`=7777 AND `OptionIndex`=8);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=12635 WHERE (`MenuId`=7777 AND `OptionIndex`=10);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=8193 WHERE (`MenuId`=3329 AND `OptionIndex`=3);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=8192 WHERE (`MenuId`=3329 AND `OptionIndex`=2);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=10767 WHERE (`MenuId`=10769 AND `OptionIndex`=8);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=11136 WHERE (`MenuId`=11134 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=11134 WHERE (`MenuId`=11135 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=3338 WHERE (`MenuId`=3354 AND `OptionIndex`=3);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=12264 WHERE (`MenuId`=3354 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=3558 WHERE (`MenuId`=3533 AND `OptionIndex`=6);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=3572 WHERE (`MenuId`=3580 AND `OptionIndex`=6);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=3337, `ActionPoiId`=433 WHERE (`MenuId`=3354 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=447 WHERE (`MenuId`=3356 AND `OptionIndex`=3);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=446 WHERE (`MenuId`=3356 AND `OptionIndex`=2);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=3263 WHERE (`MenuId`=3283 AND `OptionIndex`=3);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=7797 WHERE (`MenuId`=7788 AND `OptionIndex`=2);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=7788 WHERE (`MenuId`=7777 AND `OptionIndex`=9);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=7799 WHERE (`MenuId`=7788 AND `OptionIndex`=4);
