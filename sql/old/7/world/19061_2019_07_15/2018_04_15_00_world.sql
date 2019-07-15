-- 
DELETE FROM `gossip_menu` WHERE (`MenuId`=15021 AND `TextId`=21251) OR (`MenuId`=7939 AND `TextId`=9935) OR (`MenuId`=7939 AND `TextId`=9991);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(15021, 21251, 26124), -- Nicki Tinytech
(7939, 9935, 26124), -- 18931 (Amish Wildhammer)
(7939, 9991, 26124); -- 18931 (Amish Wildhammer)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=8254 AND `OptionIndex`=1) OR (`MenuId`=8096 AND `OptionIndex`=2) OR (`MenuId`=7970 AND `OptionIndex`=2) OR (`MenuId`=7970 AND `OptionIndex`=3) OR (`MenuId`=8002 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(8254, 1, 3, 'Train me.', 3266, 26124),
(8096, 2, 0, 'Send me to the Abyssal Shelf!', 16615, 26124), -- OptionBroadcastTextID: 16615 - 18200
(7970, 2, 0, 'Send me to Shatter Point!', 17935, 26124), -- OptionBroadcastTextID: 17935 - 17937
(7970, 3, 0, 'I''m on a bombing mission for Forward Commander Kingston.  I need a gryphon destroyer!', 18198, 26124),
(8002, 0, 1, 'I wish to browse your wares.', 4424, 26124); -- OptionBroadcastTextID: 4424 - 9818 - 12631 - 13966 - 14925 - 15955 - 16125 - 16127 - 17085 - 18217 - 19466 - 38807
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=17936, `VerifiedBuild`=26124 WHERE (`MenuId`=8096 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=14258, `VerifiedBuild`=26124 WHERE (`MenuId`=7448 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=8254 AND `OptionIndex`=1) OR (`MenuId`=7826 AND `OptionIndex`=0) OR (`MenuId`=7818 AND `OptionIndex`=0) OR (`MenuId`=7810 AND `OptionIndex`=0) OR (`MenuId`=7816 AND `OptionIndex`=0) OR (`MenuId`=7817 AND `OptionIndex`=0) OR (`MenuId`=7879 AND `OptionIndex`=0) OR (`MenuId`=7842 AND `OptionIndex`=0) OR (`MenuId`=8646 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(8254, 1, 27),
(7826, 0, 27),
(7818, 0, 62),
(7810, 0, 122),
(7816, 0, 56),
(7817, 0, 163),
(7879, 0, 136),
(7842, 0, 196),
(8646, 0, 29);
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=7883 AND `OptionIndex`=0) OR (`MenuId`=7884 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(7883, 0, 1, 'I want to browse your goods.', 3370, 26124),
(7884, 0, 1, 'I want to browse your goods.', 3370, 26124);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=33065, `VerifiedBuild`=26124 WHERE (`MenuId`=10219 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=26124 WHERE (`MenuId`=7948 AND `OptionIndex`=0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=15022 AND `TextId`=21252) OR (`MenuId`=7574 AND `TextId`=9204) OR (`MenuId`=7724 AND `TextId`=9432) OR (`MenuId`=15145 AND `TextId`=21709);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(15022, 21252, 26124), -- Ras'an
(7574, 9204, 26124), -- 17923 (Fahssn)
(7724, 9432, 26124), -- 18581 (Alliance Field Scout)
(15145, 21709, 26124); -- 17896 (Kameel Longstride)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=7512 AND `OptionIndex`=0) OR (`MenuId`=7724 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(7512, 0, 3, 'Train me.', 3266, 26124),
(7724, 0, 0, 'Give me a battle standard. I will take control of Twin Spire Ruins.', 15537, 26124); -- OptionBroadcastTextID: 15537 - 15539
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=14879, `VerifiedBuild`=26124 WHERE (`MenuId`=7585 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=14874, `VerifiedBuild`=26124 WHERE (`MenuId`=7583 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=14872, `VerifiedBuild`=26124 WHERE (`MenuId`=7582 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34245, `VerifiedBuild`=26124 WHERE (`MenuId`=10437 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=26124 WHERE (`MenuId`=7896 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=14741, `VerifiedBuild`=26124 WHERE (`MenuId`=7560 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=14739, `VerifiedBuild`=26124 WHERE (`MenuId`=7559 AND `OptionIndex`=3);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=7585 AND `OptionIndex`=0) OR (`MenuId`=7583 AND `OptionIndex`=0) OR (`MenuId`=7582 AND `OptionIndex`=0) OR (`MenuId`=9821 AND `OptionIndex`=3);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(7585, 0, 7586, 0),
(7583, 0, 7585, 0),
(7582, 0, 7583, 0),
(9821, 3, 15145, 0);
DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=10437 AND `OptionIndex`=0) OR (`MenuId`=7512 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(10437, 0, 10),
(7512, 0, 407);
DELETE FROM `points_of_interest` WHERE `ID` IN (613, 614, 611, 612, 610);
INSERT INTO `points_of_interest` (`ID`, `PositionX`, `PositionY`, `Icon`, `Flags`, `Importance`, `Name`, `VerifiedBuild`) VALUES
(613, -2258.863, 5563.93, 7, 99, 0, 'The Seer''s Library', 26124),
(614, -1460.84, 4992.25, 7, 99, 0, 'Old Man Barlo', 26124),
(611, -1863.639, 5430.006, 7, 99, 0, 'Shattrath City Center', 26124),
(612, -2086.52, 5316.64, 7, 99, 0, 'Shattrath Archaeology', 26124),
(610, -1877.333, 5365.512, 7, 99, 0, 'Shattrath Guild Services', 26124);
DELETE FROM `gossip_menu` WHERE (`MenuId`=7705 AND `TextId`=9425) OR (`MenuId`=7696 AND `TextId`=9407) OR (`MenuId`=8268 AND `TextId`=10292) OR (`MenuId`=14262 AND `TextId`=17659) OR (`MenuId`=14263 AND `TextId`=17892) OR (`MenuId`=15023 AND `TextId`=21253) OR (`MenuId`=20590 AND `TextId`=30863) OR (`MenuId`=12960 AND `TextId`=18228) OR (`MenuId`=12959 AND `TextId`=18228) OR (`MenuId`=15399 AND `TextId`=18228) OR (`MenuId`=12958 AND `TextId`=18228) OR (`MenuId`=12957 AND `TextId`=18228) OR (`MenuId`=15400 AND `TextId`=22140) OR (`MenuId`=12956 AND `TextId`=18228) OR (`MenuId`=12748 AND `TextId`=17895) OR (`MenuId`=12337 AND `TextId`=17334) OR (`MenuId`=12747 AND `TextId`=17893) OR (`MenuId`=12641 AND `TextId`=1205);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(7705, 9425, 26124), -- 18482 (Empoor)
(7696, 9407, 26124), -- 18446 (Earthbinder Tavgren)
(8268, 10292, 26124), -- 20791 (Iorioa)
(14262, 17659, 26124), -- 50127 (Windstalker Ifram)
(14263, 17892, 26124), -- 50128 (Fel-Caller Guloto)
(15023, 21253, 26124), -- Morulu The Elder
(20590, 30863, 26124), -- 115546 (Lunelli)
(12960, 18228, 26124), -- 19687 (Shattrath City Peacekeeper)
(12959, 18228, 26124), -- 19687 (Shattrath City Peacekeeper)
(15399, 18228, 26124), -- 19687 (Shattrath City Peacekeeper)
(12958, 18228, 26124), -- 19687 (Shattrath City Peacekeeper)
(12957, 18228, 26124), -- 19687 (Shattrath City Peacekeeper)
(15400, 22140, 26124), -- 19687 (Shattrath City Peacekeeper)
(12956, 18228, 26124), -- 19687 (Shattrath City Peacekeeper)
(12748, 17895, 26124), -- 19687 (Shattrath City Peacekeeper)
(12337, 17334, 26124), -- 19687 (Shattrath City Peacekeeper)
(12747, 17893, 26124), -- 19687 (Shattrath City Peacekeeper)
(12641, 1205, 26124); -- 25580 (Old Man Barlo)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=8034 AND `OptionIndex`=0) OR (`MenuId`=7952 AND `OptionIndex`=1) OR (`MenuId`=7952 AND `OptionIndex`=0) OR (`MenuId`=10363 AND `OptionIndex`=1) OR (`MenuId`=10363 AND `OptionIndex`=0) OR (`MenuId`=14136 AND `OptionIndex`=9) OR (`MenuId`=14136 AND `OptionIndex`=8) OR (`MenuId`=7484 AND `OptionIndex`=1) OR (`MenuId`=7484 AND `OptionIndex`=0) OR (`MenuId`=8282 AND `OptionIndex`=11) OR (`MenuId`=8326 AND `OptionIndex`=21) OR (`MenuId`=8326 AND `OptionIndex`=20) OR (`MenuId`=8326 AND `OptionIndex`=18) OR (`MenuId`=8326 AND `OptionIndex`=16) OR (`MenuId`=8326 AND `OptionIndex`=15) OR (`MenuId`=8326 AND `OptionIndex`=13) OR (`MenuId`=8326 AND `OptionIndex`=11) OR (`MenuId`=8326 AND `OptionIndex`=9) OR (`MenuId`=8326 AND `OptionIndex`=8);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(8034, 0, 1, 'Let''s see what you have.', 11820, 26124), -- OptionBroadcastTextID: 11820 - 17411 - 92547 - 122256 - 122264 - 122277 - 122283 - 122291 - 122296 - 122299 - 122301 - 122309
(7952, 1, 1, 'Let me browse your goods.', 2823, 26124), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(7952, 0, 5, 'Make this inn your home.', 2822, 26124),
(10363, 1, 1, 'Let me browse your goods.', 2823, 26124), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(10363, 0, 3, 'Train me.', 3266, 26124),
(14136, 9, 0, 'I want to talk about the Arcane Momentum technique.', 125293, 26124),
(14136, 8, 0, 'Enter the Proving Grounds', 74757, 26124),
(7484, 1, 8, 'I want to create a guild crest.', 3415, 26124),
(7484, 0, 7, 'How do I form a guild?', 3413, 26124),
(8282, 11, 0, 'Gem Merchant', 20385, 26124),
(8326, 21, 0, 'Skinning', 2948, 26124), -- OptionBroadcastTextID: 2948 - 3471 - 4869 - 5140 - 5376 - 5899 - 6628 - 6716 - 6786 - 6955 - 7034 - 7118 - 15273 - 19237 - 45770 - 52076 - 106243
(8326, 20, 0, 'Tailoring', 2951, 26124), -- OptionBroadcastTextID: 2951 - 3469 - 4871 - 5144 - 5380 - 5900 - 6629 - 6717 - 6787 - 6956 - 7035 - 7121 - 15275 - 32148 - 45760 - 52077
(8326, 18, 0, 'Mining', 2944, 26124), -- OptionBroadcastTextID: 2944 - 3468 - 4868 - 5138 - 5898 - 6627 - 6714 - 6785 - 6954 - 7033 - 15271 - 32147 - 45769 - 51348 - 78976
(8326, 16, 0, 'Leatherworking', 2947, 26124), -- OptionBroadcastTextID: 2947 - 3467 - 4866 - 5133 - 5371 - 5897 - 6626 - 6713 - 6784 - 6953 - 7032 - 7115 - 15269 - 19236 - 45759 - 52071
(8326, 15, 0, 'Jewelcrafting', 15267, 26124), -- OptionBroadcastTextID: 15267 - 18338 - 19235 - 44647 - 45758
(8326, 13, 0, 'Inscription', 31542, 26124), -- OptionBroadcastTextID: 31542 - 32146 - 45757 - 48811
(8326, 11, 0, 'Herbalism', 2950, 26124), -- OptionBroadcastTextID: 2950 - 3466 - 4865 - 5129 - 5130 - 5370 - 5896 - 6625 - 6712 - 6783 - 6952 - 7031 - 7112 - 15265 - 32145 - 45434 - 45768
(8326, 9, 0, 'Fishing', 3005, 26124), -- OptionBroadcastTextID: 3005 - 3465 - 4864 - 5127 - 5368 - 5895 - 6624 - 6711 - 6782 - 6951 - 7030 - 7109 - 15263 - 32144 - 45436 - 45767 - 99684
(8326, 8, 0, 'First Aid', 2949, 26124); -- OptionBroadcastTextID: 2949 - 3464 - 4863 - 5125 - 5366 - 5894 - 6623 - 6710 - 6781 - 6950 - 7029 - 7106 - 15261 - 19238 - 45765 - 52066
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=26124 WHERE (`MenuId`=7949 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Train me.', `VerifiedBuild`=26124 WHERE (`MenuId`=9879 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Profession Trainer', `VerifiedBuild`=26124 WHERE (`MenuId`=8357 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionText`='Class Trainer', `VerifiedBuild`=26124 WHERE (`MenuId`=8357 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19755, `VerifiedBuild`=26124 WHERE (`MenuId`=8460 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Engineering', `VerifiedBuild`=26124 WHERE (`MenuId`=8326 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionText`='Enchanting', `VerifiedBuild`=26124 WHERE (`MenuId`=8326 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionText`='Cooking', `VerifiedBuild`=26124 WHERE (`MenuId`=8326 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionText`='Blacksmithing', `VerifiedBuild`=26124 WHERE (`MenuId`=8326 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionText`='Archaeology', `OptionBroadcastTextId`=44649, `VerifiedBuild`=26124 WHERE (`MenuId`=8326 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionText`='Alchemy Lab', `OptionBroadcastTextId`=20383, `VerifiedBuild`=26124 WHERE (`MenuId`=8282 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionText`='Battlemaster', `VerifiedBuild`=26124 WHERE (`MenuId`=8282 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `OptionText`='Profession Trainer', `VerifiedBuild`=26124 WHERE (`MenuId`=8282 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `OptionText`='Class Trainer', `VerifiedBuild`=26124 WHERE (`MenuId`=8282 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `OptionText`='Guild Services', `OptionBroadcastTextId`=50956, `VerifiedBuild`=26124 WHERE (`MenuId`=8282 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3266, `VerifiedBuild`=26124 WHERE (`MenuId`=12641 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=14136 AND `OptionIndex`=9) OR (`MenuId`=8326 AND `OptionIndex`=20) OR (`MenuId`=8282 AND `OptionIndex`=11) OR (`MenuId`=8326 AND `OptionIndex`=21) OR (`MenuId`=8326 AND `OptionIndex`=18) OR (`MenuId`=8326 AND `OptionIndex`=16) OR (`MenuId`=8326 AND `OptionIndex`=15) OR (`MenuId`=8326 AND `OptionIndex`=13) OR (`MenuId`=8326 AND `OptionIndex`=11) OR (`MenuId`=8326 AND `OptionIndex`=9) OR (`MenuId`=8326 AND `OptionIndex`=8);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(14136, 9, 20690, 0),
(8326, 20, 12960, 613),
(8282, 11, 8548, 0),
(8326, 21, 8333, 255),
(8326, 18, 12959, 613),
(8326, 16, 8334, 254),
(8326, 15, 15399, 613),
(8326, 13, 12958, 613),
(8326, 11, 12957, 613),
(8326, 9, 15400, 614),
(8326, 8, 8331, 252);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=8546, `ActionPoiId`=257 WHERE (`MenuId`=8282 AND `OptionIndex`=10);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=12956, `ActionPoiId`=613 WHERE (`MenuId`=8326 AND `OptionIndex`=7);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=8330, `ActionPoiId`=251 WHERE (`MenuId`=8326 AND `OptionIndex`=5);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=8328, `ActionPoiId`=250 WHERE (`MenuId`=8326 AND `OptionIndex`=3);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=8335, `ActionPoiId`=249 WHERE (`MenuId`=8326 AND `OptionIndex`=2);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=12337, `ActionPoiId`=612 WHERE (`MenuId`=8326 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=8326 WHERE (`MenuId`=8282 AND `OptionIndex`=8);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=12748, `ActionPoiId`=611 WHERE (`MenuId`=8282 AND `OptionIndex`=7);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=12747, `ActionPoiId`=610 WHERE (`MenuId`=8282 AND `OptionIndex`=6);
DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=8433 AND `OptionIndex`=0) OR (`MenuId`=10363 AND `OptionIndex`=0) OR (`MenuId`=10362 AND `OptionIndex`=0) OR (`MenuId`=10361 AND `OptionIndex`=0) OR (`MenuId`=10364 AND `OptionIndex`=0) OR (`MenuId`=10359 AND `OptionIndex`=0) OR (`MenuId`=10350 AND `OptionIndex`=0) OR (`MenuId`=10351 AND `OptionIndex`=0) OR (`MenuId`=10365 AND `OptionIndex`=0) OR (`MenuId`=9879 AND `OptionIndex`=0) OR (`MenuId`=8268 AND `OptionIndex`=0) OR (`MenuId`=8540 AND `OptionIndex`=0) OR (`MenuId`=8460 AND `OptionIndex`=0) OR (`MenuId`=8785 AND `OptionIndex`=0) OR (`MenuId`=12641 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(8433, 0, 149),
(10363, 0, 407),
(10362, 0, 27),
(10361, 0, 56),
(10364, 0, 163),
(10359, 0, 122),
(10350, 0, 133),
(10351, 0, 91),
(10365, 0, 62),
(9879, 0, 63),
(8268, 0, 149),
(8540, 0, 122),
(8460, 0, 136),
(8785, 0, 136),
(12641, 0, 10);
DELETE FROM `gossip_menu` WHERE (`MenuId`=8206 AND `TextId`=10201);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(8206, 10201, 26124); -- 20876 (Human Refugee)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=7771 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(7771, 0, 0, 'Private Weeks, I need another disguise.', 15788, 26124);
DELETE FROM `gossip_menu` WHERE (`MenuId`=15024 AND `TextId`=21254);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(15024, 21254, 26124); -- Narrok
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=7719 AND `OptionIndex`=2);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(7719, 2, 0, 'Ready to survey the land.', 56571, 26124);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15560, `VerifiedBuild`=26124 WHERE (`MenuId`=7730 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0, `VerifiedBuild`=26124 WHERE (`MenuId`=7679 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0, `VerifiedBuild`=26124 WHERE (`MenuId`=7675 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15289, `VerifiedBuild`=26124 WHERE (`MenuId`=7671 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15287, `VerifiedBuild`=26124 WHERE (`MenuId`=7672 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15285, `VerifiedBuild`=26124 WHERE (`MenuId`=7673 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15283, `VerifiedBuild`=26124 WHERE (`MenuId`=7669 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=7732 AND `OptionIndex`=0) OR (`MenuId`=7671 AND `OptionIndex`=0) OR (`MenuId`=7672 AND `OptionIndex`=0) OR (`MenuId`=7673 AND `OptionIndex`=0) OR (`MenuId`=7669 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(7732, 0, 7731, 0),
(7671, 0, 7670, 0),
(7672, 0, 7671, 0),
(7673, 0, 7672, 0),
(7669, 0, 7673, 0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=7579 AND `TextId`=9221) OR (`MenuId`=7699 AND `TextId`=9403);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(7579, 9221, 26124), -- 18180 (Hemet Nesingwary)
(7699, 9403, 26124); -- 18471 (Gurgthock)
DELETE FROM `gossip_menu` WHERE (`MenuId`=8304 AND `TextId`=10537);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(8304, 10537, 26124); -- 21461 (Rally Zapnabber)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=8375 AND `OptionIndex`=0) OR (`MenuId`=8304 AND `OptionIndex`=5);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(8375, 0, 5, 'Make this inn your home.', 2822, 26124),
(8304, 5, 0, 'I want to fly to an old location!', 19735, 26124);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0, `VerifiedBuild`=26124 WHERE (`MenuId`=8306 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionText`='I have the signed waiver!  Fire me into the Singing Ridge!', `VerifiedBuild`=26124 WHERE (`MenuId`=8454 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Take me to Singing Ridge.', `VerifiedBuild`=26124 WHERE (`MenuId`=8304 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionIcon`=1, `OptionText`='I want to browse your goods.', `OptionBroadcastTextId`=3370, `VerifiedBuild`=26124 WHERE (`MenuId`=8375 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionText`='Send me to Razaan''s Landing!', `VerifiedBuild`=26124 WHERE (`MenuId`=8304 AND `OptionIndex`=2);
DELETE FROM `gossip_menu` WHERE (`MenuId`=8736 AND `TextId`=11056) OR (`MenuId`=8506 AND `TextId`=10638) OR (`MenuId`=8508 AND `TextId`=10641);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(8736, 11056, 26124), -- 23473 (Aether-tech Apprentice)
(8506, 10638, 26124), -- 22215 (Treebole)
(8508, 10641, 26124); -- 22053 (Mosswood the Ancient)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=8455 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(8455, 0, 0, 'Send me back to the Jagged Ridge.', 19729, 26124);
UPDATE `gossip_menu_option` SET `OptionText`='Send me back to Razaan''s Landing.', `OptionBroadcastTextId`=19731, `VerifiedBuild`=26124 WHERE (`MenuId`=8455 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionText`='Send me back to the Singing Ridge.', `OptionBroadcastTextId`=19730, `VerifiedBuild`=26124 WHERE (`MenuId`=8455 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionText`='Take me to Ruuan.', `VerifiedBuild`=26124 WHERE (`MenuId`=8304 AND `OptionIndex`=3);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=8304 AND `OptionIndex`=5);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(8304, 5, 8455, 0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=8726 AND `TextId`=11035);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(8726, 11035, 26124); -- 23428 (Jho'nass)
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=8726 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(8726, 0, 8689, 0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=8950 AND `TextId`=12052);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(8950, 12052, 26124); -- 58152 (Tini Smalls)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=8950 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(8950, 0, 1, 'Let me browse your goods.', 2823, 26124); -- OptionBroadcastTextID: 2823 - 7509 - 8097
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=8001 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(8001, 0, 8036, 0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=8230 AND `TextId`=10232) OR (`MenuId`=8101 AND `TextId`=10039);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(8230, 10232, 26124), -- 20985 (Captain Saeed)
(8101, 10039, 26124); -- 20281 (Drijya)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=8071 AND `OptionIndex`=0) OR (`MenuId`=8230 AND `OptionIndex`=0) OR (`MenuId`=8228 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(8071, 0, 0, 'Wind Trader Marid, I''ve returned with more information on the nether drakes. I''m prepared to be your business partner, and for an extra sum, I''ll take care of that troublesome elf and her human friend.', 17754, 26124),
(8230, 0, 0, 'I am ready. Let''s make history!', 18641, 26124),
(8228, 0, 0, 'I am that fleshling, Saeed. Let''s go!', 18639, 26124);
DELETE FROM `gossip_menu` WHERE (`MenuId`=7556 AND `TextId`=9169) OR (`MenuId`=13052 AND `TextId`=18330) OR (`MenuId`=8666 AND `TextId`=10901) OR (`MenuId`=8652 AND `TextId`=10862) OR (`MenuId`=8287 AND `TextId`=10327) OR (`MenuId`=8397 AND `TextId`=10496) OR (`MenuId`=8756 AND `TextId`=11091) OR (`MenuId`=8528 AND `TextId`=10666) OR (`MenuId`=15025 AND `TextId`=21255);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(7556, 9169, 26124), -- 17772 (Lady Jaina Proudmoore)
(13052, 18330, 26124), -- 54890 (Field Commander Mahfuun)
(8666, 10901, 26124), -- 23139 (Overlord Mor'ghor)
(8652, 10862, 26124), -- 23140 (Taskmaster Varkule Dragonbreath)
(8287, 10327, 26124), -- 21318 (Spirit of Ar'tor)
(8397, 10496, 26124), -- 21657 (Neltharaku)
(8756, 11091, 26124), -- 22059 (Wildhammer Gryphon Rider)
(8528, 10666, 26124), -- 21471 (Stormer Ewan Wildwing)
(15025, 21255, 26124); -- Bloodknight Antari
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=9113 AND `OptionIndex`=0) OR (`MenuId`=8287 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(9113, 0, 5, 'Make this inn your home.', 2822, 26124),
(8287, 0, 0, 'I require the aid of another spirit hunter, Ar''tor.', 19017, 26124);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=21079, `VerifiedBuild`=26124 WHERE (`MenuId`=8654 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='I am ready to join your forces in battle, Xi''ri.', `VerifiedBuild`=26124 WHERE (`MenuId`=8650 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=14698, `VerifiedBuild`=26124 WHERE (`MenuId`=7552 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=53903, `VerifiedBuild`=26124 WHERE (`MenuId`=7989 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=53903, `VerifiedBuild`=26124 WHERE (`MenuId`=7988 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=53903, `VerifiedBuild`=26124 WHERE (`MenuId`=7987 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=53903, `VerifiedBuild`=26124 WHERE (`MenuId`=7986 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=53903, `VerifiedBuild`=26124 WHERE (`MenuId`=7985 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0, `VerifiedBuild`=26124 WHERE (`MenuId`=8339 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Very well. I will return to the Black Temple and notify Lord Illidan of your unwillingness to carry out his wishes. I suggest you make arrangements with your subordinates and let them know that you will be leaving this world soon.', `VerifiedBuild`=26124 WHERE (`MenuId`=8340 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0, `VerifiedBuild`=26124 WHERE (`MenuId`=8259 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionIcon`=1, `OptionText`='Let me browse your goods.', `VerifiedBuild`=26124 WHERE (`MenuId`=9113 AND `OptionIndex`=1);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=7552 AND `OptionIndex`=0) OR (`MenuId`=8497 AND `OptionIndex`=0) OR (`MenuId`=8301 AND `OptionIndex`=0) OR (`MenuId`=8276 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(7552, 0, 7556, 0),
(8497, 0, 8397, 0),
(8301, 0, 8311, 0),
(8276, 0, 8259, 0);
DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=8622 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(8622, 0, 386);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52971, `VerifiedBuild`=26365 WHERE (`MenuId`=12992 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=21879, `VerifiedBuild`=26365 WHERE (`MenuId`=8749 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=21879, `VerifiedBuild`=26365 WHERE (`MenuId`=8750 AND `OptionIndex`=0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=13043 AND `TextId`=18318) OR (`MenuId`=13042 AND `TextId`=18316) OR (`MenuId`=13049 AND `TextId`=18325) OR (`MenuId`=13086 AND `TextId`=18377) OR (`MenuId`=13062 AND `TextId`=18343);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(13043, 18318, 26365), -- 54849 (Naturalist Bite)
(13042, 18316, 26365), -- 54848 (Watcher Jhang)
(13049, 18325, 26365), -- 54852 (Earthbinder Rayge)
(13086, 18377, 26365), -- 55138 (Advance Scout Chadwick)
(13062, 18343, 26365); -- 54933 (Advance Scout Chadwick)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=9055 AND `OptionIndex`=1) OR (`MenuId`=9055 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(9055, 1, 1, 'I want to browse your goods.', 3370, 26365),
(9055, 0, 5, 'Make this inn your home.', 2822, 26365);

UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7865 AND `TextId`=9632); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7865 AND `TextId`=9631); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8100 AND `TextId`=10717); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8094 AND `TextId`=10009); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8096 AND `TextId`=10010); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8095 AND `TextId`=10010); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7961 AND `TextId`=9784); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7970 AND `TextId`=9801); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8241 AND `TextId`=10255); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7826 AND `TextId`=9575); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7328 AND `TextId`=8712); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7351 AND `TextId`=8771); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7448 AND `TextId`=9021); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7352 AND `TextId`=9939); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8049 AND `TextId`=9941); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7352 AND `TextId`=9938); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7691 AND `TextId`=9385); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7810 AND `TextId`=9546); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8002 AND `TextId`=9868); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7309 AND `TextId`=8676); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7300 AND `TextId`=8656); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8554 AND `TextId`=10707); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7320 AND `TextId`=8688); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8100 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8096 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8094 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8095 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7826 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7826 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7352 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7691 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7810 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7810 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7816 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7939 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7939 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8163 AND `TextId`=10105); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7963 AND `TextId`=9788); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7964 AND `TextId`=9787); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8162 AND `TextId`=10104); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8161 AND `TextId`=10103); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7953 AND `TextId`=10109); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7954 AND `TextId`=9770); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7341 AND `TextId`=8750); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7331 AND `TextId`=8715); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7953 AND `TextId`=9769); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10219 AND `TextId`=14206); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7306 AND `TextId`=8672); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7391 AND `TextId`=8852); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7948 AND `TextId`=9051); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7360 AND `TextId`=8792); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7884 AND `TextId`=9647); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7396 AND `TextId`=8858); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7390 AND `TextId`=8851); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7393 AND `TextId`=8854); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7392 AND `TextId`=8853); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7883 AND `TextId`=9646); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7892 AND `TextId`=9656); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7878 AND `TextId`=9642); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7965 AND `TextId`=9789); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8254 AND `TextId`=10275); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8051 AND `TextId`=8772); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8043 AND `TextId`=9933); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8044 AND `TextId`=9932); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7352 AND `TextId`=9944); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8538 AND `TextId`=10682); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8539 AND `TextId`=10683); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8554 AND `TextId`=10706); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7301 AND `TextId`=8658); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8538 AND `TextId`=10801); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7817 AND `TextId`=9546); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7842 AND `TextId`=9599); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7957 AND `TextId`=9775); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8163 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8161 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8162 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7964 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7948 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7396 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7892 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7820 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8044 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7352 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7352 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7301 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7301 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7817 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7817 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7842 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7957 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7510 AND `TextId`=9106); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7516 AND `TextId`=9113); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7511 AND `TextId`=9108); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8562 AND `TextId`=10730); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7573 AND `TextId`=9202); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7586 AND `TextId`=9231); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7585 AND `TextId`=9229); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7583 AND `TextId`=9227); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7582 AND `TextId`=9226); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7683 AND `TextId`=9370); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10437 AND `TextId`=6961); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7613 AND `TextId`=9264); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7611 AND `TextId`=9262); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7612 AND `TextId`=9263); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7896 AND `TextId`=9051); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7614 AND `TextId`=9265); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7512 AND `TextId`=9109); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7610 AND `TextId`=9261); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7550 AND `TextId`=9167); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7488 AND `TextId`=9074); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7855 AND `TextId`=9617); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7496 AND `TextId`=9086); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7879 AND `TextId`=9546); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7620 AND `TextId`=9274); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7560 AND `TextId`=9177); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8249 AND `TextId`=10266); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8566 AND `TextId`=10735); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7559 AND `TextId`=9176); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10437 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7611 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7612 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7724 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7855 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7855 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7879 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7879 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8249 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7569 AND `TextId`=9196); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7529 AND `TextId`=9131); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7571 AND `TextId`=9199); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7587 AND `TextId`=9235); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7588 AND `TextId`=9236); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7589 AND `TextId`=9237); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7591 AND `TextId`=9239); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7590 AND `TextId`=9238); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7526 AND `TextId`=9128); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7495 AND `TextId`=9085); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7588 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7589 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7590 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7590 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7495 AND `OptionIndex`=0);
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=258;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=259;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=257;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=255;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=254;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=252;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=251;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=250;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=249;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=248;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=245;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=244;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=243;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=242;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=261;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=241;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=260;
UPDATE `points_of_interest` SET `VerifiedBuild`=26124 WHERE `ID`=240;
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7814 AND `TextId`=9566); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8034 AND `TextId`=9921); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7952 AND `TextId`=9766); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7698 AND `TextId`=9393); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7753 AND `TextId`=9493); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7745 AND `TextId`=9484); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7692 AND `TextId`=9383); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7703 AND `TextId`=9401); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7704 AND `TextId`=9405); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7696 AND `TextId`=9391); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8433 AND `TextId`=10292); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10352 AND `TextId`=14365); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10363 AND `TextId`=10650); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10362 AND `TextId`=16705); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10361 AND `TextId`=10653); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10364 AND `TextId`=10652); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10359 AND `TextId`=10649); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10350 AND `TextId`=16706); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8181 AND `TextId`=10153); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10351 AND `TextId`=9384); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10365 AND `TextId`=10651); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9879 AND `TextId`=13702); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8357 AND `TextId`=10430); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8014 AND `TextId`=9881); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8013 AND `TextId`=9880); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8012 AND `TextId`=9879); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8011 AND `TextId`=9878); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8010 AND `TextId`=9877); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8009 AND `TextId`=9876); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9105 AND `TextId`=12309); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9307 AND `TextId`=12623); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9046 AND `TextId`=12227); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=14137 AND `TextId`=9193); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=14140 AND `TextId`=9187); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=14199 AND `TextId`=16540); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=14144 AND `TextId`=9189); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=14139 AND `TextId`=9186); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=14142 AND `TextId`=9185); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=20690 AND `TextId`=31032); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=14136 AND `TextId`=9192); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7484 AND `TextId`=9071); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9832 AND `TextId`=13583); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=14258 AND `TextId`=17616); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=14206 AND `TextId`=5717); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8751 AND `TextId`=11083); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8752 AND `TextId`=11084); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8738 AND `TextId`=11064); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8739 AND `TextId`=11064); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8740 AND `TextId`=11064); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8741 AND `TextId`=11064); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8742 AND `TextId`=11064); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8743 AND `TextId`=11064); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7733 AND `TextId`=9451); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7937 AND `TextId`=9730); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7900 AND `TextId`=9713); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8540 AND `TextId`=9546); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7908 AND `TextId`=9714); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8033 AND `TextId`=9920); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7734 AND `TextId`=9452); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10606 AND `TextId`=14675); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8227 AND `TextId`=10224); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=11821 AND `TextId`=16573); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8460 AND `TextId`=10568); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7947 AND `TextId`=11947); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7816 AND `TextId`=9546); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8774 AND `TextId`=11215); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8000 AND `TextId`=9854); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8568 AND `TextId`=10744); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8541 AND `TextId`=10686); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8785 AND `TextId`=11231); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8784 AND `TextId`=11230); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9205 AND `TextId`=12507); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7713 AND `TextId`=9417); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8549 AND `TextId`=10699); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8547 AND `TextId`=10698); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8548 AND `TextId`=10697); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8546 AND `TextId`=10696); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8333 AND `TextId`=10398); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8334 AND `TextId`=10399); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8331 AND `TextId`=10396); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8330 AND `TextId`=10395); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8328 AND `TextId`=10393); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8335 AND `TextId`=10400); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8327 AND `TextId`=10392); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8326 AND `TextId`=10391); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8321 AND `TextId`=10387); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8320 AND `TextId`=10386); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8319 AND `TextId`=10385); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8318 AND `TextId`=10384); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8316 AND `TextId`=10383); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8317 AND `TextId`=10382); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8314 AND `TextId`=10381); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8313 AND `TextId`=10380); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8315 AND `TextId`=10379); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8329 AND `TextId`=10394); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8282 AND `TextId`=10321); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7704 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8433 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10362 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10362 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10361 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10361 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10364 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10364 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10359 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10359 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10350 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10350 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10351 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10351 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10365 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10365 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9879 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8357 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8357 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8357 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8357 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8357 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8357 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8357 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8357 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8357 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8014 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8013 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8012 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8011 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8010 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8009 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9307 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9046 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=20690 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8268 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9832 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7937 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7900 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8540 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10606 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8227 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=11821 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7947 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7816 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8774 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8785 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8784 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8784 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7713 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8548 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8548 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8326 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8321 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8321 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8320 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8320 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8320 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8320 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8317 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8317 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8315 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8315 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8282 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8282 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8282 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8282 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8282 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8282 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8683 AND `TextId`=10953); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8687 AND `TextId`=11058); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8719 AND `TextId`=10980); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8660 AND `TextId`=10888); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8630 AND `TextId`=10819); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8667 AND `TextId`=10903); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8753 AND `TextId`=11089); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8559 AND `TextId`=10721); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9818 AND `TextId`=13548); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8031 AND `TextId`=9918); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8029 AND `TextId`=9914); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8028 AND `TextId`=9905); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8526 AND `TextId`=10662); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8535 AND `TextId`=10677); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7741 AND `TextId`=9477); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8555 AND `TextId`=10680); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7696 AND `TextId`=9444); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8232 AND `TextId`=10234); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7755 AND `TextId`=9498); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7757 AND `TextId`=9497); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7761 AND `TextId`=9506); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7760 AND `TextId`=9505); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7758 AND `TextId`=9503); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7759 AND `TextId`=9502); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7775 AND `TextId`=9523); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7771 AND `TextId`=9517); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7751 AND `TextId`=9490); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7743 AND `TextId`=9481); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7773 AND `TextId`=9521); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7738 AND `TextId`=9471); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8683 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7757 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7760 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7759 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7729 AND `TextId`=9440); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7731 AND `TextId`=9443); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7732 AND `TextId`=9442); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7730 AND `TextId`=9441); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7725 AND `TextId`=9435); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7714 AND `TextId`=9424); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7715 AND `TextId`=9423); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7716 AND `TextId`=9422); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7717 AND `TextId`=9421); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7718 AND `TextId`=9420); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7719 AND `TextId`=9419); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7631 AND `TextId`=9312); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7700 AND `TextId`=9395); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7674 AND `TextId`=9357); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7675 AND `TextId`=9369); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7676 AND `TextId`=9368); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7677 AND `TextId`=9367); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7678 AND `TextId`=9366); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7679 AND `TextId`=9365); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7680 AND `TextId`=9364); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7681 AND `TextId`=9363); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7682 AND `TextId`=9362); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7675 AND `TextId`=9361); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7670 AND `TextId`=9356); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7671 AND `TextId`=9355); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7672 AND `TextId`=9354); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7673 AND `TextId`=9353); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7669 AND `TextId`=9352); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7940 AND `TextId`=9733); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8663 AND `TextId`=10893); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7887 AND `TextId`=9649); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7890 AND `TextId`=9653); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7685 AND `TextId`=9374); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7886 AND `TextId`=9648); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7941 AND `TextId`=9735); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7888 AND `TextId`=9650); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7943 AND `TextId`=9738); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7695 AND `TextId`=9389); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7891 AND `TextId`=9659); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7729 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7731 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7732 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7725 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7715 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7716 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7717 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7718 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7719 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7676 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7677 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7678 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7680 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7681 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7682 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7887 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7890 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7886 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7888 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7562 AND `TextId`=9180); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7563 AND `TextId`=9181); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7564 AND `TextId`=9182); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7579 AND `TextId`=9257); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7579 AND `TextId`=9256); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7607 AND `TextId`=9286); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7592 AND `TextId`=9284); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7841 AND `TextId`=9598); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7628 AND `TextId`=9290); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7578 AND `TextId`=9220); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9096 AND `TextId`=12294); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8567 AND `TextId`=10736); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7626 AND `TextId`=9288); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7841 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7628 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7579 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7576 AND `TextId`=9208); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8343 AND `TextId`=10363); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8306 AND `TextId`=10410); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8454 AND `TextId`=10561); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8375 AND `TextId`=10450); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8352 AND `TextId`=10423); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8251 AND `TextId`=10270); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8271 AND `TextId`=10300); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8235 AND `TextId`=10245); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8252 AND `TextId`=10271); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8351 AND `TextId`=10422); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=1581 AND `TextId`=824); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8247 AND `TextId`=10264); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8236 AND `TextId`=10246); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8407 AND `TextId`=10509); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8303 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8304 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=1581 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=1581 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8388 AND `TextId`=10469); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8685 AND `TextId`=10932); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8676 AND `TextId`=10914); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8677 AND `TextId`=10913); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8614 AND `TextId`=10791); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8681 AND `TextId`=10927); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8672 AND `TextId`=10922); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8673 AND `TextId`=10911); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8672 AND `TextId`=10910); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8681 AND `TextId`=10926); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8722 AND `TextId`=11000); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8723 AND `TextId`=11017); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8724 AND `TextId`=11026); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8757 AND `TextId`=11094); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8679 AND `TextId`=10919); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8680 AND `TextId`=10923); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8678 AND `TextId`=10916); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8721 AND `TextId`=10987); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8717 AND `TextId`=10976); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8716 AND `TextId`=10967); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8642 AND `TextId`=10841); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8669 AND `TextId`=10906); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8737 AND `TextId`=11059); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8718 AND `TextId`=10977); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8736 AND `TextId`=11066); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8670 AND `TextId`=10907); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8640 AND `TextId`=10838); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8657 AND `TextId`=10878); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8620 AND `TextId`=10860); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8496 AND `TextId`=10612); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8370 AND `TextId`=10444); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8657 AND `TextId`=10877); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8620 AND `TextId`=10800); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8491 AND `TextId`=10603); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8440 AND `TextId`=10545); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8439 AND `TextId`=10544); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8438 AND `TextId`=10543); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8437 AND `TextId`=10542); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8435 AND `TextId`=10541); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8436 AND `TextId`=10539); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8446 AND `TextId`=10553); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8529 AND `TextId`=10667); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8431 AND `TextId`=10534); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8430 AND `TextId`=10533); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8429 AND `TextId`=10532); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8432 AND `TextId`=10538); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8508 AND `TextId`=10640); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8615 AND `TextId`=10793); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8447 AND `TextId`=10554); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8523 AND `TextId`=10657); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8455 AND `TextId`=10562); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8304 AND `TextId`=10360); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8303 AND `TextId`=10569); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8385 AND `TextId`=10466); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8661 AND `TextId`=10889); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8676 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8677 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8673 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8672 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8722 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8723 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8724 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8679 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8721 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8717 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8737 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8523 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8439 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8438 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8437 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8435 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8436 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8429 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8661 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=342 AND `TextId`=820); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12941 AND `TextId`=18205); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=681 AND `TextId`=1231); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=4161 AND `TextId`=5207); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8716 AND `TextId`=10965); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8704 AND `TextId`=10949); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8671 AND `TextId`=10909); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8703 AND `TextId`=10948); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8689 AND `TextId`=10931); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8726 AND `TextId`=11029); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8681 AND `TextId`=11007); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8670 AND `TextId`=10997); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=342 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=342 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12941 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=681 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=4161 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8716 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8704 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8671 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8703 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8689 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8726 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8003 AND `TextId`=9869); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8082 AND `TextId`=9990); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8036 AND `TextId`=10045); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8036 AND `TextId`=9922); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8048 AND `TextId`=9937); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7981 AND `TextId`=9828); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7994 AND `TextId`=9846); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8082 AND `TextId`=9989); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8030 AND `TextId`=9916); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7820 AND `TextId`=9546); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9781 AND `TextId`=13459); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8710 AND `TextId`=10957); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7992 AND `TextId`=9844); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8106 AND `TextId`=10031); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8007 AND `TextId`=9872); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10248 AND `TextId`=14231); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8008 AND `TextId`=9875); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8308 AND `TextId`=10365); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8001 AND `TextId`=9863); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8027 AND `TextId`=9904); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7991 AND `TextId`=9841); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8082 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8036 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8710 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8001 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8068 AND `TextId`=9968); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8062 AND `TextId`=9958); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8128 AND `TextId`=10065); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8228 AND `TextId`=10229); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8229 AND `TextId`=10230); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8063 AND `TextId`=9959); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8071 AND `TextId`=9971); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8121 AND `TextId`=10061); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8122 AND `TextId`=10060); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8123 AND `TextId`=10059); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8120 AND `TextId`=10058); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8182 AND `TextId`=10178); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8103 AND `TextId`=10022); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8070 AND `TextId`=9970); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8576 AND `TextId`=10752); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7982 AND `TextId`=9832); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8542 AND `TextId`=10687); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8056 AND `TextId`=9949); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8119 AND `TextId`=10056); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8646 AND `TextId`=10846); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7818 AND `TextId`=9546); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8006 AND `TextId`=9871); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8107 AND `TextId`=10032); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8116 AND `TextId`=10045); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8115 AND `TextId`=10045); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8545 AND `TextId`=10691); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8032 AND `TextId`=9919); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8231 AND `TextId`=10233); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8054 AND `TextId`=9947); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8084 AND `TextId`=9994); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7996 AND `TextId`=9848); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7995 AND `TextId`=9847); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8126 AND `TextId`=10064); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8038 AND `TextId`=9925); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8113 AND `TextId`=10045); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8042 AND `TextId`=9930); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8041 AND `TextId`=9929); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8039 AND `TextId`=9927); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8040 AND `TextId`=9926); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8045 AND `TextId`=9934); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8046 AND `TextId`=9931); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8113 AND `TextId`=9922); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8062 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8229 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8063 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8121 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8122 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8123 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8120 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8103 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8070 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7982 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7982 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8646 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8646 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7818 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7818 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8116 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8115 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8545 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8084 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8126 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8113 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8041 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8040 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8046 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8654 AND `TextId`=10866); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7552 AND `TextId`=9168); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8560 AND `TextId`=7778); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7990 AND `TextId`=9840); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7989 AND `TextId`=9839); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7988 AND `TextId`=9838); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7987 AND `TextId`=9837); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7986 AND `TextId`=9835); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7985 AND `TextId`=9834); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7984 AND `TextId`=9836); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8031 AND `TextId`=9917); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8398 AND `TextId`=10497); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8396 AND `TextId`=10495); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8395 AND `TextId`=10494); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8393 AND `TextId`=10493); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8394 AND `TextId`=10492); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7719 AND `TextId`=9427); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8564 AND `TextId`=10733); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8692 AND `TextId`=10936); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8665 AND `TextId`=10896); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8662 AND `TextId`=10892); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8648 AND `TextId`=10848); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8668 AND `TextId`=10904); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8647 AND `TextId`=10847); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8649 AND `TextId`=10849); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8754 AND `TextId`=11090); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8493 AND `TextId`=10854); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8497 AND `TextId`=10616); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8498 AND `TextId`=10615); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8499 AND `TextId`=10614); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8397 AND `TextId`=10613); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8493 AND `TextId`=10606); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7596 AND `TextId`=9243); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8310 AND `TextId`=10373); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8372 AND `TextId`=10447); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8650 AND `TextId`=10851); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7949 AND `TextId`=8618); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8500 AND `TextId`=10625); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8350 AND `TextId`=10421); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8338 AND `TextId`=10409); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8339 AND `TextId`=10408); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8340 AND `TextId`=10407); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8341 AND `TextId`=10406); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8342 AND `TextId`=10405); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8336 AND `TextId`=10401); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8311 AND `TextId`=10375); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8664 AND `TextId`=10894); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7966 AND `TextId`=9800); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8276 AND `TextId`=10318); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8277 AND `TextId`=10317); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8278 AND `TextId`=10316); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8279 AND `TextId`=10315); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8280 AND `TextId`=10314); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8281 AND `TextId`=10313); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8259 AND `TextId`=10312); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8259 AND `TextId`=10280); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8238 AND `TextId`=10250); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8374 AND `TextId`=10449); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8389 AND `TextId`=10470); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8492 AND `TextId`=10605); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8464 AND `TextId`=10573); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8301 AND `TextId`=10356); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8296 AND `TextId`=10349); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8356 AND `TextId`=10427); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8392 AND `TextId`=10491); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8449 AND `TextId`=10556); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8457 AND `TextId`=10563); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9113 AND `TextId`=823); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8622 AND `TextId`=10808); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8623 AND `TextId`=10809); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7973 AND `TextId`=9805); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8387 AND `TextId`=10468); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8284 AND `TextId`=10323); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8560 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7984 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8031 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8398 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8396 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8395 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8393 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8394 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7719 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8648 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8647 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8649 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8497 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8498 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8499 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8397 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7596 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7949 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8350 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8301 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8338 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8341 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8342 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8336 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8301 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8664 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8276 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8277 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8278 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8279 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8280 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8281 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8259 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8356 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8622 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8623 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8387 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=8181 AND `TextId`=10153); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=7937 AND `TextId`=9730); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=12992 AND `TextId`=18269); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=7937 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=8650 AND `TextId`=10851); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=8713 AND `TextId`=10960); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=8750 AND `TextId`=11082); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=8654 AND `TextId`=10866); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=8713 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=8654 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=8749 AND `TextId`=11078); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=8750 AND `TextId`=11081); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=8750 AND `OptionIndex`=1);
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9307 AND `TextId`=12623); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9046 AND `TextId`=12227); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=8268 AND `TextId`=10292); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9832 AND `TextId`=13583); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=7990 AND `TextId`=9840); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=7989 AND `TextId`=9839); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=7988 AND `TextId`=9838); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=7987 AND `TextId`=9837); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=7986 AND `TextId`=9835); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=7985 AND `TextId`=9834); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=7984 AND `TextId`=9836); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=8400 AND `TextId`=10500); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=699 AND `TextId`=1250); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=12941 AND `TextId`=18205); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=6944 AND `TextId`=7778); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9307 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9046 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=8268 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9832 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=7989 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=7988 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=7987 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=7986 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=7985 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=7984 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=699 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=12941 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=6944 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9088 AND `TextId`=12287); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9143 AND `TextId`=12371); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9062 AND `TextId`=12252); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9105 AND `TextId`=12309); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9087 AND `TextId`=12286); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9061 AND `TextId`=12251); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9198 AND `TextId`=12497); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9050 AND `TextId`=12237); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9055 AND `TextId`=9051); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=15145 AND `TextId`=21709); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9821 AND `TextId`=13584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9115 AND `TextId`=12323); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9065 AND `TextId`=12259); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9126 AND `TextId`=12338); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9143 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9062 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9062 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9087 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9061 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9198 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9050 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9821 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9821 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26365 WHERE (`MenuId`=9126 AND `OptionIndex`=0);
