DELETE FROM `gossip_menu_option` WHERE (`MenuId`=6874 AND `OptionIndex`=4) OR (`MenuId`=6874 AND `OptionIndex`=3) OR (`MenuId`=6874 AND `OptionIndex`=2) OR (`MenuId`=6874 AND `OptionIndex`=1) OR (`MenuId`=6874 AND `OptionIndex`=0) OR (`MenuId`=12591 AND `OptionIndex`=0) OR (`MenuId`=11099 AND `OptionIndex`=0) OR (`MenuId`=11477 AND `OptionIndex`=0) OR (`MenuId`=11535 AND `OptionIndex`=0) OR (`MenuId`=11535 AND `OptionIndex`=7) OR (`MenuId`=11592 AND `OptionIndex`=0) OR (`MenuId`=11447 AND `OptionIndex`=1) OR (`MenuId`=12168 AND `OptionIndex`=0) OR (`MenuId`=11514 AND `OptionIndex`=0) OR (`MenuId`=11510 AND `OptionIndex`=0) OR (`MenuId`=11511 AND `OptionIndex`=0) OR (`MenuId`=11508 AND `OptionIndex`=0) OR (`MenuId`=11509 AND `OptionIndex`=0) OR (`MenuId`=11489 AND `OptionIndex`=0) OR (`MenuId`=12135 AND `OptionIndex`=0) OR (`MenuId`=12136 AND `OptionIndex`=0) OR (`MenuId`=12137 AND `OptionIndex`=0) OR (`MenuId`=12138 AND `OptionIndex`=0) OR (`MenuId`=12044 AND `OptionIndex`=2) OR (`MenuId`=12044 AND `OptionIndex`=1) OR (`MenuId`=12044 AND `OptionIndex`=0) OR (`MenuId`=12043 AND `OptionIndex`=2) OR (`MenuId`=12043 AND `OptionIndex`=1) OR (`MenuId`=12043 AND `OptionIndex`=0) OR (`MenuId`=7869 AND `OptionIndex`=3) OR (`MenuId`=7869 AND `OptionIndex`=2) OR (`MenuId`=7760 AND `OptionIndex`=1) OR (`MenuId`=7757 AND `OptionIndex`=1) OR (`MenuId`=7759 AND `OptionIndex`=1) OR (`MenuId`=12167 AND `OptionIndex`=0) OR (`MenuId`=8903 AND `OptionIndex`=1);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(6874, 4, 0, 'Where is Elder Winterhoof?', 11544, 13623),
(6874, 3, 0, 'Where is Elder Stormbrow?', 11542, 13623),
(6874, 2, 0, 'Where is Elder Skychaser?', 11546, 13623),
(6874, 1, 0, 'Where is Elder Starglade?', 11656, 13623),
(6874, 0, 0, 'Where is Elder Bellowrage?', 11552, 13623),
(12591, 0, 1, 'I wish to browse your wares.', 4424, 13623), -- OptionBroadcastTextID: 4424 - 9818 - 12631 - 13966 - 14925 - 15955 - 16125 - 16127 - 17085 - 18217 - 19466 - 38807
(11099, 0, 1, 'I wish to browse your wares.', 4424, 13623), -- OptionBroadcastTextID: 4424 - 9818 - 12631 - 13966 - 14925 - 15955 - 16125 - 16127 - 17085 - 18217 - 19466 - 38807
(11477, 0, 0, 'I\'m ready to begin the assault on the terrace.', 41193, 13623),
(11535, 0, 0, 'Hexascrub, let me see that merciless one again.', 41660, 13623),
(11535, 7, 0, 'Here, I made a Promising Fuel Sample.  Three parts hammerhead and two parts remora.', 42016, 13623),
(11592, 0, 0, 'Mix the samples together!', 42003, 13623),
(11447, 1, 0, 'I lost my Fang of Goldrinn. Can I have another?', 40903, 13623),
(12168, 0, 0, 'Tell me about the Shrine of Goldrinn.', 41321, 13623),
(11514, 0, 0, 'Are there any weaknesses we can exploit? Any holes in the naga defenses?', 41378, 13623),
(11510, 0, 0, 'Did you see Captain Taylor and his men?', 41376, 13623),
(11511, 0, 0, 'How did you escape, Pollard?', 41372, 13623),
(11508, 0, 0, 'What can you tell me about your captors?', 41370, 13623),
(11509, 0, 0, 'How did you get down here?', 41368, 13623), -- OptionBroadcastTextID: 41368 - 41707
(11489, 0, 0, 'Who are you, friend?', 40025, 13623),
(12135, 0, 0, 'Well, let\'s get to it then.', 46426, 13623),
(12136, 0, 0, 'And I take it you\'re going again...', 46424, 13623),
(12137, 0, 0, 'You seem very certain.', 46422, 13623),
(12138, 0, 0, 'Yeah...', 46420, 13623),
(12044, 2, 0, 'Throw in all 12 flasks.', 45722, 13623),
(12044, 1, 0, 'Throw in an entire flask.', 45721, 13623),
(12044, 0, 0, 'Do nothing.  Betina said only one drop was needed.', 45727, 13623),
(12043, 2, 0, 'Throw in all 12 flasks.', 45722, 13623),
(12043, 1, 0, 'Throw in an entire flask.', 45721, 13623),
(12043, 0, 0, 'Put in a drop of liquid, as Betina requested.', 45720, 13623),
(7869, 3, 1, 'I want to browse your goods.', 3370, 13623),
(7869, 2, 5, 'Make this inn your home.', 2822, 13623),
(7760, 1, 0, 'Advisor, what\'s the latest news?', 15767, 13623),
(7757, 1, 0, 'Why are you fixing all of this up?', 15757, 13623),
(7759, 1, 0, 'What are you doing there?', 15763, 13623),
(12167, 0, 0, 'Tell me about the Shrine of Goldrinn.', 41321, 13623),
(8903, 1, 5, 'Make this inn your home.', 2822, 13623);

UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=8851 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=8762 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=7288 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=7288 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=9162 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=342 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=342 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=9741 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=9741 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=9741 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=9603 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=9550 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=9555 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=10950 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=10847 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=9545 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=9541 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=9544 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=9543 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=9511 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=9891 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=7772 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=8035 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=13623 WHERE (`MenuId`=9868 AND `OptionIndex`=2);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=45926, `VerifiedBuild`=13623 WHERE (`MenuId`=12059 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=49254, `VerifiedBuild`=13623 WHERE (`MenuId`=12480 AND `OptionIndex`=0);
