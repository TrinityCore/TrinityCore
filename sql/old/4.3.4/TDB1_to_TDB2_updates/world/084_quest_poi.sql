DELETE FROM `quest_poi` WHERE (`questid`=6342 AND `id`=1);

DELETE FROM `quest_poi` WHERE `questid` IN (25832, 25372, 28514, 27128, 27230, 28457, 28512, 28713, 28714, 28715, 26948, 28723, 28724, 28725, 28726, 28727, 28728, 28729, 28730, 28731, 13945, 13946);
INSERT INTO `quest_poi` (`questid`, `id`, `objIndex`, `mapid`, `WorldMapAreaId`, `FloorId`, `unk3`, `unk4`) VALUES
(25832, 0, -1, 1, 606, 0, 0, 1), -- Return to Aviana
(25372, 1, -1, 1, 606, 0, 0, 1), -- Aessina's Miracle
(28514, 0, -1, 0, 29, 0, 0, 1), -- Mouton Flamestar
(27128, 0, 0, 429, 699, 1, 0, 1), -- King of the Gordok
(27128, 1, -1, 429, 699, 1, 0, 1), -- King of the Gordok
(27230, 0, -1, 329, 765, 2, 0, 7), -- Weapons for War
(27230, 1, 0, 329, 765, 2, 0, 7), -- Weapons for War
(27230, 2, -1, 329, 765, 2, 0, 7), -- Weapons for War
(28457, 0, -1, 1, 321, 0, 0, 1), -- A Dangerous Alliance
(28457, 1, 0, 230, 704, 2, 0, 1), -- A Dangerous Alliance
(28457, 2, 0, 230, 704, 2, 0, 1), -- A Dangerous Alliance
(28457, 3, 0, 230, 704, 2, 0, 1), -- A Dangerous Alliance
(28457, 4, 0, 230, 704, 2, 0, 1), -- A Dangerous Alliance
(28457, 5, 0, 230, 704, 2, 0, 1), -- A Dangerous Alliance
(28457, 6, 5, 230, 704, 2, 0, 1), -- A Dangerous Alliance
(28512, 0, -1, 0, 28, 0, 0, 1), -- To the Aid of the Thorium Brotherhood
(28713, 1, -1, 1, 41, 0, 0, 1), -- The Balance of Nature
(28713, 2, 0, 1, 41, 0, 0, 7), -- The Balance of Nature
(28714, 1, 4, 1, 41, 0, 0, 1), -- Fel Moss Corruption
(28714, 2, -1, 1, 41, 0, 0, 1), -- Fel Moss Corruption
(28715, 0, 4, 1, 41, 0, 0, 1), -- Demonic Thieves
(28715, 1, -1, 1, 41, 0, 0, 1), -- Demonic Thieves
(26948, 0, -1, 1, 41, 0, 0, 1), -- Rejuvenating Touch
(26948, 1, 1, 1, 41, 0, 0, 7), -- Rejuvenating Touch
(26948, 2, 0, 1, 41, 0, 0, 7), -- Rejuvenating Touch
(28723, 0, -1, 1, 41, 0, 0, 1), -- Priestess of the Moon
(28724, 0, 4, 1, 41, 0, 0, 1), -- Iverron's Antidote
(28724, 1, -1, 1, 41, 0, 0, 1), -- Iverron's Antidote
(28725, 0, -1, 1, 41, 0, 0, 7), -- The Woodland Protector
(28726, 0, 0, 1, 41, 0, 0, 1), -- Webwood Corruption
(28727, 0, 0, 1, 41, 0, 0, 1), -- Vile Touch
(28728, 0, -1, 1, 41, 0, 0, 1), -- Signs of Things to Come
(28729, 0, -1, 1, 41, 0, 0, 1), -- Teldrassil: Crown of Azeroth
(28729, 1, 4, 1, 41, 0, 0, 7), -- Teldrassil: Crown of Azeroth
(28730, 0, -1, 1, 41, 0, 0, 1), -- Precious Waters
(28731, 0, -1, 1, 41, 0, 0, 1), -- Teldrassil: Passing Awareness
(13945, 0, -1, 1, 41, 0, 0, 1), -- Resident Danger
(13945, 5, 0, 1, 41, 0, 0, 1), -- Resident Danger
(13946, 0, -1, 1, 41, 0, 0, 1), -- Nature's Reprisal
(13946, 1, 0, 1, 41, 0, 0, 1), -- Nature's Reprisal
(6342, 1, -1, 1, 41, 0, 0, 1); -- Flight to Auberdine


UPDATE `quest_poi` SET `objIndex`=0 WHERE `questid`=2459 AND `id`=0; -- Ferocitas the Dream Eater
UPDATE `quest_poi` SET `objIndex`=5 WHERE `questid`=2459 AND `id`=1; -- Ferocitas the Dream Eater


DELETE FROM `quest_poi_points` WHERE (`questId`=25832 AND `id`=0) OR (`questId`=25372 AND `id`=1) OR (`questId`=28514 AND `id`=0) OR (`questId`=27128 AND `id`=0) OR (`questId`=27128 AND `id`=1) OR (`questId`=27230 AND `id`=0) OR (`questId`=27230 AND `id`=1) OR (`questId`=27230 AND `id`=2) OR (`questId`=28457 AND `id`=0) OR (`questId`=28457 AND `id`=1) OR (`questId`=28457 AND `id`=1) OR (`questId`=28457 AND `id`=1) OR (`questId`=28457 AND `id`=1) OR (`questId`=28457 AND `id`=1) OR (`questId`=28457 AND `id`=2) OR (`questId`=28457 AND `id`=2) OR (`questId`=28457 AND `id`=2) OR (`questId`=28457 AND `id`=3) OR (`questId`=28457 AND `id`=3) OR (`questId`=28457 AND `id`=3) OR (`questId`=28457 AND `id`=3) OR (`questId`=28457 AND `id`=4) OR (`questId`=28457 AND `id`=4) OR (`questId`=28457 AND `id`=4) OR (`questId`=28457 AND `id`=4) OR (`questId`=28457 AND `id`=5) OR (`questId`=28457 AND `id`=5) OR (`questId`=28457 AND `id`=5) OR (`questId`=28457 AND `id`=5) OR (`questId`=28457 AND `id`=5) OR (`questId`=28457 AND `id`=6) OR (`questId`=28512 AND `id`=0) OR (`questId`=28713 AND `id`=1) OR (`questId`=28713 AND `id`=2) OR (`questId`=28713 AND `id`=2) OR (`questId`=28713 AND `id`=2) OR (`questId`=28713 AND `id`=2) OR (`questId`=28713 AND `id`=2) OR (`questId`=28713 AND `id`=2) OR (`questId`=28713 AND `id`=2) OR (`questId`=28713 AND `id`=2) OR (`questId`=28713 AND `id`=2) OR (`questId`=28713 AND `id`=2) OR (`questId`=28713 AND `id`=2) OR (`questId`=28713 AND `id`=2) OR (`questId`=28714 AND `id`=1) OR (`questId`=28714 AND `id`=1) OR (`questId`=28714 AND `id`=1) OR (`questId`=28714 AND `id`=1) OR (`questId`=28714 AND `id`=1) OR (`questId`=28714 AND `id`=1) OR (`questId`=28714 AND `id`=1) OR (`questId`=28714 AND `id`=1) OR (`questId`=28714 AND `id`=2) OR (`questId`=28715 AND `id`=0) OR (`questId`=28715 AND `id`=0) OR (`questId`=28715 AND `id`=0) OR (`questId`=28715 AND `id`=0) OR (`questId`=28715 AND `id`=0) OR (`questId`=28715 AND `id`=0) OR (`questId`=28715 AND `id`=1) OR (`questId`=26948 AND `id`=0) OR (`questId`=26948 AND `id`=1) OR (`questId`=26948 AND `id`=1) OR (`questId`=26948 AND `id`=1) OR (`questId`=26948 AND `id`=1) OR (`questId`=26948 AND `id`=1) OR (`questId`=26948 AND `id`=1) OR (`questId`=26948 AND `id`=1) OR (`questId`=26948 AND `id`=1) OR (`questId`=26948 AND `id`=1) OR (`questId`=26948 AND `id`=1) OR (`questId`=26948 AND `id`=1) OR (`questId`=26948 AND `id`=1) OR (`questId`=26948 AND `id`=2) OR (`questId`=26948 AND `id`=2) OR (`questId`=26948 AND `id`=2) OR (`questId`=26948 AND `id`=2) OR (`questId`=26948 AND `id`=2) OR (`questId`=26948 AND `id`=2) OR (`questId`=26948 AND `id`=2) OR (`questId`=26948 AND `id`=2) OR (`questId`=26948 AND `id`=2) OR (`questId`=26948 AND `id`=2) OR (`questId`=26948 AND `id`=2) OR (`questId`=26948 AND `id`=2) OR (`questId`=28723 AND `id`=0) OR (`questId`=28724 AND `id`=0) OR (`questId`=28724 AND `id`=0) OR (`questId`=28724 AND `id`=0) OR (`questId`=28724 AND `id`=0) OR (`questId`=28724 AND `id`=0) OR (`questId`=28724 AND `id`=0) OR (`questId`=28724 AND `id`=1) OR (`questId`=28725 AND `id`=0) OR (`questId`=28726 AND `id`=0) OR (`questId`=28726 AND `id`=0) OR (`questId`=28726 AND `id`=0) OR (`questId`=28726 AND `id`=0) OR (`questId`=28726 AND `id`=0) OR (`questId`=28726 AND `id`=0) OR (`questId`=28726 AND `id`=0) OR (`questId`=28726 AND `id`=0) OR (`questId`=28727 AND `id`=0) OR (`questId`=28728 AND `id`=0) OR (`questId`=28729 AND `id`=0) OR (`questId`=28729 AND `id`=1) OR (`questId`=28730 AND `id`=0) OR (`questId`=28731 AND `id`=0) OR (`questId`=13945 AND `id`=0) OR (`questId`=13945 AND `id`=5) OR (`questId`=13945 AND `id`=5) OR (`questId`=13945 AND `id`=5) OR (`questId`=13945 AND `id`=5) OR (`questId`=13945 AND `id`=5) OR (`questId`=13945 AND `id`=5) OR (`questId`=13945 AND `id`=5) OR (`questId`=13945 AND `id`=5) OR (`questId`=13945 AND `id`=5) OR (`questId`=13945 AND `id`=5) OR (`questId`=13945 AND `id`=5) OR (`questId`=13946 AND `id`=0) OR (`questId`=13946 AND `id`=1) OR (`questId`=13946 AND `id`=1) OR (`questId`=13946 AND `id`=1) OR (`questId`=13946 AND `id`=1) OR (`questId`=13946 AND `id`=1) OR (`questId`=13946 AND `id`=1) OR (`questId`=6342 AND `id`=1);
INSERT INTO `quest_poi_points` (`questId`, `id`, `idx`, `x`, `y`) VALUES
(25832, 0, 0, 4837, -2812), -- Return to Aviana
(25372, 1, 0, 5125, -1759), -- Aessina's Miracle
(28514, 0, 0, -8063, -1000), -- Mouton Flamestar
(27128, 0, 0, 830, 481), -- King of the Gordok
(27128, 1, 0, 266, -26), -- King of the Gordok
(27230, 0, 0, 3677, -3642), -- Weapons for War
(27230, 1, 0, 3828, -3691), -- Weapons for War
(27230, 2, 0, 4050, -3465), -- Weapons for War
(28457, 0, 0, 1957, -4791), -- A Dangerous Alliance
(28457, 1, 0, 1097, -179), -- A Dangerous Alliance
(28457, 1, 1, 1101, -172), -- A Dangerous Alliance
(28457, 1, 2, 1103, -166), -- A Dangerous Alliance
(28457, 1, 3, 1103, -160), -- A Dangerous Alliance
(28457, 1, 4, 1093, -152), -- A Dangerous Alliance
(28457, 2, 0, 1204, -372), -- A Dangerous Alliance
(28457, 2, 1, 1211, -372), -- A Dangerous Alliance
(28457, 2, 2, 1204, -364), -- A Dangerous Alliance
(28457, 3, 0, 719, 32), -- A Dangerous Alliance
(28457, 3, 1, 719, 61), -- A Dangerous Alliance
(28457, 3, 2, 688, 54), -- A Dangerous Alliance
(28457, 3, 3, 713, 36), -- A Dangerous Alliance
(28457, 4, 0, 1165, -327), -- A Dangerous Alliance
(28457, 4, 1, 1163, -314), -- A Dangerous Alliance
(28457, 4, 2, 1154, -313), -- A Dangerous Alliance
(28457, 4, 3, 1151, -324), -- A Dangerous Alliance
(28457, 5, 0, 931, -259), -- A Dangerous Alliance
(28457, 5, 1, 937, -250), -- A Dangerous Alliance
(28457, 5, 2, 919, -231), -- A Dangerous Alliance
(28457, 5, 3, 872, -231), -- A Dangerous Alliance
(28457, 5, 4, 852, -245), -- A Dangerous Alliance
(28457, 6, 0, 652, 21), -- A Dangerous Alliance
(28512, 0, 0, -6894, -1853), -- To the Aid of the Thorium Brotherhood
(28713, 1, 0, 10313, 830), -- The Balance of Nature
(28713, 2, 0, 10313, 739), -- The Balance of Nature
(28713, 2, 1, 10369, 772), -- The Balance of Nature
(28713, 2, 2, 10391, 822), -- The Balance of Nature
(28713, 2, 3, 10408, 872), -- The Balance of Nature
(28713, 2, 4, 10408, 944), -- The Balance of Nature
(28713, 2, 5, 10397, 972), -- The Balance of Nature
(28713, 2, 6, 10336, 972), -- The Balance of Nature
(28713, 2, 7, 10291, 944), -- The Balance of Nature
(28713, 2, 8, 10263, 911), -- The Balance of Nature
(28713, 2, 9, 10258, 878), -- The Balance of Nature
(28713, 2, 10, 10258, 817), -- The Balance of Nature
(28713, 2, 11, 10263, 755), -- The Balance of Nature
(28714, 1, 0, 10266, 943), -- Fel Moss Corruption
(28714, 1, 1, 10282, 948), -- Fel Moss Corruption
(28714, 1, 2, 10350, 1018), -- Fel Moss Corruption
(28714, 1, 3, 10358, 1032), -- Fel Moss Corruption
(28714, 1, 4, 10353, 1044), -- Fel Moss Corruption
(28714, 1, 5, 10311, 1036), -- Fel Moss Corruption
(28714, 1, 6, 10254, 980), -- Fel Moss Corruption
(28714, 1, 7, 10261, 953), -- Fel Moss Corruption
(28714, 2, 0, 10313, 830), -- Fel Moss Corruption
(28715, 0, 0, 10264, 962), -- Demonic Thieves
(28715, 0, 1, 10368, 1032), -- Demonic Thieves
(28715, 0, 2, 10333, 1049), -- Demonic Thieves
(28715, 0, 3, 10302, 1035), -- Demonic Thieves
(28715, 0, 4, 10253, 993), -- Demonic Thieves
(28715, 0, 5, 10256, 965), -- Demonic Thieves
(28715, 1, 0, 10329, 825), -- Demonic Thieves
(26948, 0, 0, 10480, 825), -- Rejuvenating Touch
(26948, 1, 0, 10476, 720), -- Rejuvenating Touch
(26948, 1, 1, 10519, 732), -- Rejuvenating Touch
(26948, 1, 2, 10538, 745), -- Rejuvenating Touch
(26948, 1, 3, 10569, 775), -- Rejuvenating Touch
(26948, 1, 4, 10581, 812), -- Rejuvenating Touch
(26948, 1, 5, 10551, 862), -- Rejuvenating Touch
(26948, 1, 6, 10500, 892), -- Rejuvenating Touch
(26948, 1, 7, 10464, 893), -- Rejuvenating Touch
(26948, 1, 8, 10427, 868), -- Rejuvenating Touch
(26948, 1, 9, 10414, 812), -- Rejuvenating Touch
(26948, 1, 10, 10420, 775), -- Rejuvenating Touch
(26948, 1, 11, 10451, 738), -- Rejuvenating Touch
(26948, 2, 0, 10470, 707), -- Rejuvenating Touch
(26948, 2, 1, 10525, 714), -- Rejuvenating Touch
(26948, 2, 2, 10569, 738), -- Rejuvenating Touch
(26948, 2, 3, 10581, 782), -- Rejuvenating Touch
(26948, 2, 4, 10575, 812), -- Rejuvenating Touch
(26948, 2, 5, 10544, 868), -- Rejuvenating Touch
(26948, 2, 6, 10513, 880), -- Rejuvenating Touch
(26948, 2, 7, 10470, 887), -- Rejuvenating Touch
(26948, 2, 8, 10427, 880), -- Rejuvenating Touch
(26948, 2, 9, 10402, 850), -- Rejuvenating Touch
(26948, 2, 10, 10408, 794), -- Rejuvenating Touch
(26948, 2, 11, 10439, 732), -- Rejuvenating Touch
(28723, 0, 0, 10545, 875), -- Priestess of the Moon
(28724, 0, 0, 10551, 806), -- Iverron's Antidote
(28724, 0, 1, 10563, 808), -- Iverron's Antidote
(28724, 0, 2, 10599, 865), -- Iverron's Antidote
(28724, 0, 3, 10576, 900), -- Iverron's Antidote
(28724, 0, 4, 10538, 918), -- Iverron's Antidote
(28724, 0, 5, 10485, 895), -- Iverron's Antidote
(28724, 1, 0, 10545, 875), -- Iverron's Antidote
(28725, 0, 0, 10764, 934), -- The Woodland Protector
(28726, 0, 0, 10909, 854), -- Webwood Corruption
(28726, 0, 1, 10951, 870), -- Webwood Corruption
(28726, 0, 2, 10973, 937), -- Webwood Corruption
(28726, 0, 3, 10979, 979), -- Webwood Corruption
(28726, 0, 4, 10887, 984), -- Webwood Corruption
(28726, 0, 5, 10865, 979), -- Webwood Corruption
(28726, 0, 6, 10776, 926), -- Webwood Corruption
(28726, 0, 7, 10859, 859), -- Webwood Corruption
(28727, 0, 0, 10941, 923), -- Vile Touch
(28728, 0, 0, 10545, 875), -- Signs of Things to Come
(28729, 0, 0, 10545, 875), -- Teldrassil: Crown of Azeroth
(28729, 1, 0, 10708, 762), -- Teldrassil: Crown of Azeroth
(28730, 0, 0, 10493, 807), -- Precious Waters
(28731, 0, 0, 9737, 956), -- Teldrassil: Passing Awareness
(13945, 0, 0, 9812, 966), -- Resident Danger
(13945, 5, 0, 9981, 1344), -- Resident Danger
(13945, 5, 1, 10025, 1372), -- Resident Danger
(13945, 5, 2, 10092, 1458), -- Resident Danger
(13945, 5, 3, 10096, 1465), -- Resident Danger
(13945, 5, 4, 9964, 1548), -- Resident Danger
(13945, 5, 5, 9826, 1625), -- Resident Danger
(13945, 5, 6, 9753, 1631), -- Resident Danger
(13945, 5, 7, 9730, 1608), -- Resident Danger
(13945, 5, 8, 9719, 1551), -- Resident Danger
(13945, 5, 9, 9751, 1522), -- Resident Danger
(13945, 5, 10, 9950, 1362), -- Resident Danger
(13946, 0, 0, 9872, 959), -- Nature's Reprisal
(13946, 1, 0, 10088, 1029), -- Nature's Reprisal
(13946, 1, 1, 10173, 1086), -- Nature's Reprisal
(13946, 1, 2, 10174, 1108), -- Nature's Reprisal
(13946, 1, 3, 10119, 1122), -- Nature's Reprisal
(13946, 1, 4, 10064, 1121), -- Nature's Reprisal
(13946, 1, 5, 10047, 1035), -- Nature's Reprisal
(6342, 1, 0, 9973, 2624); -- Flight to Auberdine
