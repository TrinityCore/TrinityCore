UPDATE `gossip_menu_option` SET `OptionIcon`=10, `VerifiedBuild`=15211 WHERE (`MenuId`=12941 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='I\'ll go get some help. Hang in there.', `VerifiedBuild`=15211 WHERE (`MenuId`=9843 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='I\'m sorry that I didn\'t get here sooner. What happened?', `VerifiedBuild`=15211 WHERE (`MenuId`=9842 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Are you okay? I\'ve come to take you back to Frosthold if you can stand.', `VerifiedBuild`=15211 WHERE (`MenuId`=9841 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='How can I help?', `VerifiedBuild`=15211 WHERE (`MenuId`=3302 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='I feel sick.', `OptionBroadcastTextId`=6661, `VerifiedBuild`=15211 WHERE (`MenuId`=3303 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='This is an atrocity.', `OptionBroadcastTextId`=6659, `VerifiedBuild`=15211 WHERE (`MenuId`=3301 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Tell me more.', `VerifiedBuild`=15211 WHERE (`MenuId`=3304 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='No restraints? Just in a circle?', `VerifiedBuild`=15211 WHERE (`MenuId`=3305 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionText`='Kara, I need to be flown out to the Dens of Dying to find Bixie.', `VerifiedBuild`=15211 WHERE (`MenuId`=9683 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionIcon`=1, `VerifiedBuild`=15211 WHERE (`MenuId`=1964 AND `OptionIndex`=0);

DELETE FROM `gossip_menu_option` WHERE `MenuId`=8357;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES 
(8357, 0, 0, 'World\'s End Tavern', 19241, 1, 1, 15211),
(8357, 1, 0, 'Bank', 44628, 1, 1, 15211),
(8357, 2, 0, 'Inn', 44629, 1, 1, 15211),
(8357, 3, 0, 'Flight Master', 45379, 1, 1, 15211),
(8357, 4, 0, 'Mailbox', 45381, 1, 1, 15211),
(8357, 5, 0, 'Stable Master', 45383, 1, 1, 15211),
(8357, 6, 0, 'Battlemaster', 19209, 1, 1, 15211),
(8357, 7, 0, 'Class Trainer', 45382, 1, 1, 15211),
(8357, 8, 0, 'Profession Trainer', 2869, 0, 0, 15211),
(8357, 9, 0, 'Alchemy Lab', 20383, 1, 1, 15211),
(8357, 10, 0, 'Gem Merchant', 20385, 1, 1, 15211),
(8357, 11, 0, 'Mana Loom', 19589, 1, 1, 0);

DELETE FROM `gossip_menu_option_action` WHERE `MenuId`=8357;
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(8357, 0, 8358, 240),
(8357, 1, 8359, 241),
(8357, 2, 8360, 242),
(8357, 3, 8361, 243),
(8357, 4, 8363, 242),
(8357, 5, 8364, 245),
(8357, 6, 8365, 0),
(8357, 7, 12749, 0),
(8357, 8, 8403, 0),
(8357, 9, 8551, 257),
(8357, 10, 8552, 258),
(8357, 11, 8550, 256);

DELETE FROM `gossip_menu_option` WHERE `MenuId`=8403;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(8403, 0, 0, 'Alchemy', 52058, 1, 1, 15211),
(8403, 1, 0, 'Archaeology', 44649, 1, 1, 15211),
(8403, 2, 0, 'Blacksmithing', 0, 1, 1, 15211),
(8403, 3, 0, 'Cooking', 0, 1, 1, 15211),
(8403, 4, 0, 'Enchanting', 0, 1, 1, 15211),
(8403, 5, 0, 'Engineering', 0, 1, 1, 15211),
(8403, 6, 0, 'First Aid', 0, 1, 1, 15211),
(8403, 7, 0, 'Herbalism', 0, 1, 1, 15211),
(8403, 8, 0, 'Inscription', 0, 0, 0, 15211),
(8403, 9, 0, 'Jewelcrafting', 45758, 0, 0, 15211),
(8403, 10, 0, 'Leatherworking', 52071, 0, 0, 15211),
(8403, 11, 0, 'Mining', 0, 0, 0, 15211),
(8403, 12, 0, 'Skinning', 52076, 0, 0, 15211),
(8403, 13, 0, 'Tailoring', 0, 0, 0, 15211);

DELETE FROM `gossip_menu_option_action` WHERE `MenuId`=8403;
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(8403, 0, 8411, 248),
(8403, 2, 8412, 249),
(8403, 3, 8413, 250),
(8403, 4, 8414, 251),
(8403, 6, 8415, 252),
(8403, 9, 8416, 253),
(8403, 10, 8417, 254),
(8403, 12, 8418, 255);

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=9855 AND `OptionIndex`=0) OR (`MenuId`=9860 AND `OptionIndex`=0) OR (`MenuId`=12115 AND `OptionIndex`=0) OR (`MenuId`=12114 AND `OptionIndex`=0) OR (`MenuId`=12113 AND `OptionIndex`=0) OR (`MenuId`=9182 AND `OptionIndex`=0) OR (`MenuId`=3301 AND `OptionIndex`=0) OR (`MenuId`=9199 AND `OptionIndex`=1) OR (`MenuId`=9297 AND `OptionIndex`=1) OR (`MenuId`=9297 AND `OptionIndex`=0) OR (`MenuId`=9200 AND `OptionIndex`=0) OR (`MenuId`=9199 AND `OptionIndex`=0) OR (`MenuId`=7849 AND `OptionIndex`=0) OR (`MenuId`=11039 AND `OptionIndex`=0) OR (`MenuId`=11043 AND `OptionIndex`=0) OR (`MenuId`=11041 AND `OptionIndex`=0) OR (`MenuId`=11054 AND `OptionIndex`=0) OR (`MenuId`=11055 AND `OptionIndex`=0) OR (`MenuId`=11056 AND `OptionIndex`=0) OR (`MenuId`=11057 AND `OptionIndex`=0) OR (`MenuId`=11058 AND `OptionIndex`=0) OR (`MenuId`=11059 AND `OptionIndex`=0) OR (`MenuId`=11060 AND `OptionIndex`=0) OR (`MenuId`=11036 AND `OptionIndex`=1) OR (`MenuId`=2177 AND `OptionIndex`=0) OR (`MenuId`=5684 AND `OptionIndex`=2) OR (`MenuId`=5674 AND `OptionIndex`=8) OR (`MenuId`=5683 AND `OptionIndex`=0) OR (`MenuId`=5674 AND `OptionIndex`=7) OR (`MenuId`=5682 AND `OptionIndex`=0) OR (`MenuId`=5674 AND `OptionIndex`=6) OR (`MenuId`=5681 AND `OptionIndex`=0) OR (`MenuId`=5674 AND `OptionIndex`=5) OR (`MenuId`=5680 AND `OptionIndex`=0) OR (`MenuId`=5674 AND `OptionIndex`=4) OR (`MenuId`=5679 AND `OptionIndex`=0) OR (`MenuId`=5674 AND `OptionIndex`=3) OR (`MenuId`=5678 AND `OptionIndex`=0) OR (`MenuId`=5674 AND `OptionIndex`=2) OR (`MenuId`=5677 AND `OptionIndex`=0) OR (`MenuId`=5674 AND `OptionIndex`=1) OR (`MenuId`=5676 AND `OptionIndex`=0) OR (`MenuId`=5674 AND `OptionIndex`=0) OR (`MenuId`=3781 AND `OptionIndex`=3) OR (`MenuId`=5002 AND `OptionIndex`=2) OR (`MenuId`=5673 AND `OptionIndex`=1) OR (`MenuId`=5003 AND `OptionIndex`=0) OR (`MenuId`=5673 AND `OptionIndex`=0) OR (`MenuId`=3781 AND `OptionIndex`=2) OR (`MenuId`=5670 AND `OptionIndex`=2) OR (`MenuId`=5669 AND `OptionIndex`=6) OR (`MenuId`=5227 AND `OptionIndex`=0) OR (`MenuId`=5669 AND `OptionIndex`=5) OR (`MenuId`=5671 AND `OptionIndex`=0) OR (`MenuId`=5669 AND `OptionIndex`=4) OR (`MenuId`=5225 AND `OptionIndex`=0) OR (`MenuId`=5669 AND `OptionIndex`=3) OR (`MenuId`=5621 AND `OptionIndex`=0) OR (`MenuId`=5669 AND `OptionIndex`=2) OR (`MenuId`=5223 AND `OptionIndex`=0) OR (`MenuId`=5669 AND `OptionIndex`=1) OR (`MenuId`=5668 AND `OptionIndex`=0) OR (`MenuId`=5669 AND `OptionIndex`=0) OR (`MenuId`=3781 AND `OptionIndex`=1) OR (`MenuId`=5705 AND `OptionIndex`=1) OR (`MenuId`=5692 AND `OptionIndex`=5) OR (`MenuId`=5695 AND `OptionIndex`=0) OR (`MenuId`=5692 AND `OptionIndex`=4) OR (`MenuId`=3781 AND `OptionIndex`=0) OR (`MenuId`=5693 AND `OptionIndex`=1) OR (`MenuId`=5692 AND `OptionIndex`=3) OR (`MenuId`=5706 AND `OptionIndex`=0) OR (`MenuId`=5692 AND `OptionIndex`=2) OR (`MenuId`=5699 AND `OptionIndex`=0) OR (`MenuId`=5692 AND `OptionIndex`=1) OR (`MenuId`=5697 AND `OptionIndex`=1) OR (`MenuId`=5692 AND `OptionIndex`=0) OR (`MenuId`=6211 AND `OptionIndex`=0) OR (`MenuId`=10646 AND `OptionIndex`=0) OR (`MenuId`=10645 AND `OptionIndex`=0) OR (`MenuId`=10644 AND `OptionIndex`=0) OR (`MenuId`=10643 AND `OptionIndex`=0) OR (`MenuId`=10642 AND `OptionIndex`=0) OR (`MenuId`=10641 AND `OptionIndex`=0) OR (`MenuId`=2178 AND `OptionIndex`=0) OR (`MenuId`=2179 AND `OptionIndex`=0) OR (`MenuId`=3285 AND `OptionIndex`=5) OR (`MenuId`=3285 AND `OptionIndex`=3) OR (`MenuId`=3285 AND `OptionIndex`=2) OR (`MenuId`=3285 AND `OptionIndex`=1) OR (`MenuId`=3285 AND `OptionIndex`=0) OR (`MenuId`=2101 AND `OptionIndex`=0) OR (`MenuId`=1296 AND `OptionIndex`=0) OR (`MenuId`=10477 AND `OptionIndex`=0) OR (`MenuId`=10994 AND `OptionIndex`=1) OR (`MenuId`=10994 AND `OptionIndex`=0) OR (`MenuId`=10981 AND `OptionIndex`=0) OR (`MenuId`=10980 AND `OptionIndex`=0) OR (`MenuId`=10979 AND `OptionIndex`=0) OR (`MenuId`=10989 AND `OptionIndex`=0) OR (`MenuId`=10978 AND `OptionIndex`=0) OR (`MenuId`=10980 AND `OptionIndex`=1) OR (`MenuId`=11238 AND `OptionIndex`=0) OR (`MenuId`=10780 AND `OptionIndex`=1) OR (`MenuId`=11324 AND `OptionIndex`=0) OR (`MenuId`=12456 AND `OptionIndex`=2) OR (`MenuId`=12455 AND `OptionIndex`=1) OR (`MenuId`=12451 AND `OptionIndex`=0) OR (`MenuId`=12014 AND `OptionIndex`=1) OR (`MenuId`=12012 AND `OptionIndex`=1) OR (`MenuId`=5667 AND `OptionIndex`=1) OR (`MenuId`=7671 AND `OptionIndex`=0) OR (`MenuId`=7672 AND `OptionIndex`=0) OR (`MenuId`=7673 AND `OptionIndex`=0) OR (`MenuId`=7669 AND `OptionIndex`=0) OR (`MenuId`=11665 AND `OptionIndex`=1) OR (`MenuId`=5739 AND `OptionIndex`=1) OR (`MenuId`=12606 AND `OptionIndex`=2);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(9855, 0, 9852, 0),
(9860, 0, 9852, 0),
(12115, 0, 12116, 0),
(12114, 0, 12115, 0),
(12113, 0, 12114, 0),
(9182, 0, 9181, 0),
(3301, 0, 3303, 0),
(9199, 1, 9297, 0),
(9297, 1, 9296, 0),
(9297, 0, 9295, 0),
(9200, 0, 9201, 0),
(9199, 0, 9200, 0),
(7849, 0, 7852, 0),
(11039, 0, 11038, 0),
(11043, 0, 11042, 0),
(11041, 0, 11040, 0),
(11054, 0, 11053, 0),
(11055, 0, 11036, 0),
(11056, 0, 11055, 0),
(11057, 0, 11056, 0),
(11058, 0, 11057, 0),
(11059, 0, 11058, 0),
(11060, 0, 11059, 0),
(11036, 1, 11060, 0),
(2177, 0, 2181, 0),
(5684, 2, 3781, 0),
(5674, 8, 5684, 0),
(5683, 0, 5674, 0),
(5674, 7, 5683, 0),
(5682, 0, 5674, 0),
(5674, 6, 5682, 0),
(5681, 0, 5674, 0),
(5674, 5, 5681, 0),
(5680, 0, 5674, 0),
(5674, 4, 5680, 0),
(5679, 0, 5674, 0),
(5674, 3, 5679, 0),
(5678, 0, 5674, 0),
(5674, 2, 5678, 0),
(5677, 0, 5674, 0),
(5674, 1, 5677, 0),
(5676, 0, 5674, 0),
(5674, 0, 5676, 0),
(3781, 3, 5674, 0),
(5002, 2, 3781, 0),
(5673, 1, 5002, 0),
(5003, 0, 5673, 0),
(5673, 0, 5003, 0),
(3781, 2, 5673, 0),
(5670, 2, 3781, 0),
(5669, 6, 5670, 0),
(5227, 0, 5669, 0),
(5669, 5, 5227, 0),
(5671, 0, 5669, 0),
(5669, 4, 5671, 0),
(5225, 0, 5669, 0),
(5669, 3, 5225, 0),
(5621, 0, 5669, 0),
(5669, 2, 5621, 0),
(5223, 0, 5669, 0),
(5669, 1, 5223, 0),
(5668, 0, 5669, 0),
(5669, 0, 5668, 0),
(3781, 1, 5669, 0),
(5705, 1, 3781, 0),
(5692, 5, 5705, 0),
(5695, 0, 5692, 0),
(5692, 4, 5695, 0),
(3781, 0, 5692, 0),
(5693, 1, 3781, 0),
(5692, 3, 5693, 0),
(5706, 0, 5692, 0),
(5692, 2, 5706, 0),
(5699, 0, 5692, 0),
(5692, 1, 5699, 0),
(5697, 1, 3781, 0),
(5692, 0, 5697, 0),
(6211, 0, 6212, 0),
(10646, 0, 10647, 0),
(10645, 0, 10646, 0),
(10644, 0, 10645, 0),
(10643, 0, 10644, 0),
(10642, 0, 10643, 0),
(10641, 0, 10642, 0),
(2178, 0, 2180, 0),
(2179, 0, 2182, 0),
(3285, 5, 3284, 0),
(3285, 3, 4901, 0),
(3285, 2, 3282, 403),
(3285, 1, 3281, 0),
(3285, 0, 3280, 0),
(2101, 0, 8766, 0),
(1296, 0, 1221, 0),
(10477, 0, 10476, 0),
(10994, 1, 11030, 0),
(10994, 0, 11029, 0),
(10981, 0, 10982, 0),
(10980, 0, 10981, 0),
(10979, 0, 10980, 0),
(10989, 0, 10979, 0),
(10978, 0, 10989, 0),
(10980, 1, 10981, 0),
(11238, 0, 11237, 0),
(10780, 1, 10784, 0),
(11324, 0, 11325, 0),
(12456, 2, 12457, 0),
(12455, 1, 12456, 0),
(12451, 0, 12455, 0),
(12014, 1, 12013, 0),
(12012, 1, 12011, 0),
(5667, 1, 5716, 0),
(7671, 0, 7670, 0),
(7672, 0, 7671, 0),
(7673, 0, 7672, 0),
(7669, 0, 7673, 0),
(11665, 1, 11669, 0),
(5739, 1, 5744, 0),
(12606, 2, 10371, 0);

UPDATE `gossip_menu_option_action` SET `ActionMenuId`=4463 WHERE (`MenuId`=6649 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=4463 WHERE (`MenuId`=4484 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=3301 WHERE (`MenuId`=3304 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=6211 WHERE (`MenuId`=6187 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=460 WHERE (`MenuId`=6225 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=6210 WHERE (`MenuId`=6185 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE  `MenuId`=10768 AND `OptionIndex`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE  `MenuId`=10768 AND `OptionIndex`=1;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE  `MenuId`=10768 AND `OptionIndex`=2;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE  `MenuId`=10768 AND `OptionIndex`=3;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE  `MenuId`=10768 AND `OptionIndex`=4;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE  `MenuId`=10768 AND `OptionIndex`=5;
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=10758, `ActionPoiId`=0 WHERE (`MenuId`=10768 AND `OptionIndex`=4);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=10768, `ActionPoiId`=0 WHERE (`MenuId`=10769 AND `OptionIndex`=5);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=7666, `ActionPoiId`=0 WHERE (`MenuId`=7667 AND `OptionIndex`=14);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=6211, `ActionPoiId`=0 WHERE (`MenuId`=6208 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=6208, `ActionPoiId`=0 WHERE (`MenuId`=6185 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=9962, `ActionPoiId`=0 WHERE (`MenuId`=9971 AND `OptionIndex`=3);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=6211, `ActionPoiId`=0 WHERE (`MenuId`=6209 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=6209, `ActionPoiId`=0 WHERE (`MenuId`=6185 AND `OptionIndex`=2);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=468 WHERE (`MenuId`=13076 AND `OptionIndex`=5);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=10334, `ActionPoiId`=0 WHERE (`MenuId`=10337 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=10332, `ActionPoiId`=0 WHERE (`MenuId`=10336 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=6211, `ActionPoiId`=0 WHERE (`MenuId`=6209 AND `OptionIndex`=1);
