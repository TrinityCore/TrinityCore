-- Hana'zua
DELETE FROM `creature_addon` WHERE `guid`=308452;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(308452, 0, 0, 7, 1, 0, 0, 0, 0, 0, '');

UPDATE `creature_equip_template` SET `VerifiedBuild`=44232 WHERE (`ID`=1 AND `CreatureID` IN (5952,10556,39317,3101,3287,3112,3183,3111,3158,3882,3161,3159,3156,3155,12776,39206,3157,3153,39214,63296,3145,75685,3293,4311,71100)) OR (`ID`=2 AND `CreatureID`=3143);

UPDATE `creature_queststarter` SET `VerifiedBuild`=44232 WHERE (`id`=3145 AND `quest` IN (25133,25132,25131)) OR (`id`=11378 AND `quest` IN (25135,37446)) OR (`id`=3287 AND `quest` IN (25130,25129)) OR (`id`=5887 AND `quest`=25128) OR (`id`=3143 AND `quest` IN (25127,25172,25126)) OR (`id`=9796 AND `quest`=25136) OR (`id`=10176 AND `quest`=25152);
UPDATE `creature_questender` SET `VerifiedBuild`=44232 WHERE (`id`=3145 AND `quest` IN (25132,25131)) OR (`id`=11378 AND `quest` IN (25135,37446)) OR (`id`=3143 AND `quest` IN (25130,25127,25172,25126,25152)) OR (`id`=3287 AND `quest`=25129) OR (`id`=9796 AND `quest`=25136);

UPDATE `creature_model_info` SET `VerifiedBuild`=44232 WHERE `DisplayID` IN (549, 1128, 1973, 32226, 46130, 2486, 31389, 2025, 5233, 31421, 1876, 850, 6068, 1879, 9797, 9151, 3753, 1885, 1881, 1883, 1653, 1884, 1886, 4532, 14371, 31365, 9470, 1878, 1880, 31370, 42925, 3019, 9796, 2577, 1875, 31438, 12089, 31371, 9795, 31447, 9794, 10038, 1185, 15467, 901, 1967, 15468, 9800, 9799, 8971, 1139, 9801, 9798, 7511, 1960, 36583, 36584, 6815, 2487, 7129, 36585, 2732, 1959, 36598, 1987, 46940, 1206, 32171, 4515, 1560, 4366, 19017, 32173, 46126, 1986, 32172, 32170);
UPDATE `creature_model_info` SET `BoundingRadius`=0.459251970052719116, `CombatReach`=0.836734712123870849, `VerifiedBuild`=44232 WHERE `DisplayID`=31437;
UPDATE `creature_model_info` SET `BoundingRadius`=0.459251970052719116, `VerifiedBuild`=44232 WHERE `DisplayID` IN (503, 381);
UPDATE `creature_model_info` SET `BoundingRadius`=0.438775509595870971, `CombatReach`=0.877551019191741943, `VerifiedBuild`=44232 WHERE `DisplayID`=2485;
UPDATE `creature_model_info` SET `BoundingRadius`=1.065270185470581054, `CombatReach`=1.5, `VerifiedBuild`=44232 WHERE `DisplayID`=1963;
UPDATE `creature_model_info` SET `BoundingRadius`=0.582511007785797119, `VerifiedBuild`=44232 WHERE `DisplayID`=1225;
UPDATE `creature_model_info` SET `BoundingRadius`=0.548862099647521972, `VerifiedBuild`=44232 WHERE `DisplayID` IN (704, 193, 3027);
UPDATE `creature_model_info` SET `BoundingRadius`=5.220055580139160156, `VerifiedBuild`=44232 WHERE `DisplayID`=12110;

UPDATE `creature_questitem` SET `VerifiedBuild`=44232 WHERE (`Idx`=0 AND `CreatureEntry` IN (3183,3102,3281,3124,3101,3127,42859)) OR (`Idx`=1 AND `CreatureEntry`=3281);

UPDATE `creature_template` SET `VerifiedBuild`=44232 WHERE `entry` IN (5891, 1420, 5890, 165189, 3125, 3882, 44058, 11378, 21354, 304, 305, 10556, 12776, 39379, 39380, 28302, 3098, 3099, 3101, 3102, 3111, 75685, 39399, 3112, 39400, 62114, 62115, 33030, 3115, 62116, 3116, 5887, 39408, 3122, 32207, 3123, 3124, 157969, 3126, 356, 3127, 20029, 20030, 18377, 3143, 3145, 73780, 18380, 9796, 14505, 3153, 3155, 61325, 3156, 3157, 3158, 3159, 3160, 3161, 4271, 6491, 5951, 5952, 3183, 63296, 39206, 61369, 4311, 39214, 39215, 49743, 39224, 40891, 12922, 71100, 65011, 1860, 42859, 10176, 44820, 3281, 3287, 4953, 3293, 65065, 3300, 49837, 61751, 39317, 39323, 39326, 20217);
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3287; -- Hana'zua
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=39326; -- Raggaran
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3183; -- Yarrog Baneshadow
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `dynamicflags`=0 WHERE `entry`=3102; -- Felstalker
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `unit_flags`=67108864, `dynamicflags`=64 WHERE `entry`=3281; -- Sarkoth
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `unit_flags`=33536, `dynamicflags`=0 WHERE `entry`=39215; -- Captured Northwatch Scout
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=39224; -- Lo'Shall
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3158; -- Duokna
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=9796; -- Galgar
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3882; -- Zlagk
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3161; -- Rarc
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3160; -- Huklah
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3159; -- Kzan Thornslash
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3143; -- Gornek
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3156; -- Nartok
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3155; -- Rwag
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=5887; -- Canaga Earthcaller
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=12776; -- Hraug
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=39206; -- Acrypha
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=10176; -- Kaltunk
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3157; -- Shikrik
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3153; -- Frang
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=39214; -- Karranisha
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35 WHERE `entry`=63296; -- Gato
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `unit_flags3`=8388625 WHERE `entry`=44820; -- Training Dummy
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=39400; -- Farmer Krella
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3145; -- Zureetha Fargaze
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=39399; -- Farmer Lok'lub
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=11378; -- Foreman Thazz'ril
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=39317; -- Northwatch Scout
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=39408; -- Durotar Farmhand
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3098; -- Mottled Boar
UPDATE `creature_template` SET `minlevel`=63, `maxlevel`=63 WHERE `entry`=5952; -- Den Grunt
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=10556; -- Lazy Peon
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `unit_flags`=32768 WHERE `entry`=3101; -- Vile Familiar
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3124; -- Scorpid Worker
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=39323; -- Thonk
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=75685; -- Razor Hill Grunt
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `speed_walk`=1 WHERE `entry`=5891; -- Minor Manifestation of Earth
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `speed_walk`=1 WHERE `entry`=5890; -- Redrock Earth Spirit

UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='6752' WHERE `entry`=3124; -- 3124 (Scorpid Worker) - 6752
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='159549' WHERE `entry`=3143; -- 3143 (Gornek) - 159549

DELETE FROM `creature_template_addon` WHERE `entry` IN (75685 /*75685 (Razor Hill Grunt)*/, 39380 /*39380 (Shin Stonepillar)*/, 39379 /*39379 (Gor the Enforcer)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(75685, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 75685 (Razor Hill Grunt)
(39380, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 39380 (Shin Stonepillar)
(39379, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''); -- 39379 (Gor the Enforcer)

UPDATE `creature_template_model` SET `VerifiedBuild`=44232 WHERE (`Idx`=0 AND `CreatureID` IN (3125,165189, 44058,3287,6491,39326,3183,3102,157969,3281,39215,39224,9796,3882,3158,63296,44820,39214,39206,12922,12776,10176,5887,3161,3160,3159,3157,3156,3155,3153,3143,39408,39400,39399,39317,11378,5952,3145,3098,10556,3124,3101,49743,3111,61369,3112,4953,75685,61751,39323,1860,62115,3122,3099,62114,3115,3126,3293,3116,3127,3123,61325,49837,62116,71100,42859,40891,39380,39379,5951,4311,3300,33030,21354,73780,65065,356,32207,28302,20217,20029,20030,18380,18377,14505,4271,305,65011,304)) OR (`Idx`=1 AND `CreatureID` IN (39215,39317,5952,49743,4953,75685,62115,62114,61325,49837,71100,42859,40891,3300)) OR (`Idx`=3 AND `CreatureID` IN (5952,49743,4953,75685,62115,62114,49837,71100,40891)) OR (`Idx`=2 AND `CreatureID` IN (5952,49743,4953,75685,62115,62114,61325,49837,71100,42859,40891,3300));
UPDATE `creature_template_model` SET `VerifiedBuild`=44232 WHERE (`CreatureID`=5891 AND `Idx`=0) OR (`CreatureID`=5890 AND `Idx` IN (2,1,0)) OR (`CreatureID`=1420 AND `Idx`=0);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=44232 WHERE (`DifficultyID`=0 AND `Entry` IN (1420,40971,40970,3125,44058,3287,6491,3102,3281,39215,39224,3158,9796,3882,3161,3160,3159,3143,3156,3155,5887,12776,39206,10176,3157,3153,39214,63296,44820,39400,3145,39399,11378,39317,39408,3098,5952,10556,3101,3124,49743,3111,61369,3112,4953,61751,39323,75685,62115,3122,3099,62114,3115,3126,3293,3116,3127,3123,49837,61325,62116,4311,42859,5951,39380,39379,71100,3300,40891));

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (39326,3183,5891,5890));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(39326, 0, 0, 0, 70, 44232),
(3183, 0, 0, 0, 70, 44232),
(5891, 0, 0, 0, 70, 44232),
(5890, 0, 0, 0, 70, 44232);

UPDATE `creature_text` SET `Emote`=1, `comment`='Hana\'zua to Player' WHERE `CreatureID`=3287 AND `GroupID`=0 AND `ID`=0;
UPDATE `creature_text` SET `comment`='Galgar to Duokna' WHERE `CreatureID`=9796 AND `GroupID`=0 AND `ID` IN (0,1,2,3);
UPDATE `creature_text` SET `Sound`=7514, `comment`='Lazy Peon to Player' WHERE `CreatureID`=10556 AND `GroupID`=0 AND `ID`=0;

DELETE FROM `creature_text` WHERE (`CreatureID`=39317 AND `ID` IN (0,1,2)) OR (`CreatureID`=3145 AND `ID`=0) OR (`CreatureID`=3183 AND `ID` IN(0, 1)) OR (`CreatureID`=9796 AND `ID`=4) OR (`CreatureID`=10556 AND `ID` IN (2,3,4)) OR (`CreatureID`=11378 AND `ID`=0);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(39317, 0, 0, 'Lieutenant Palliter will have your head.', 12, 0, 100, 0, 0, 0, 0 /*UNKNOWN*/, 0, 'Northwatch Scout to Player'),
(39317, 0, 1, 'You don\'t belong here.', 12, 0, 100, 0, 0, 0, 0 /*UNKNOWN*/, 0, 'Northwatch Scout to Player'),
(39317, 0, 2, 'Horde scum!', 12, 0, 100, 0, 0, 0, 34969, 0, 'Northwatch Scout to Player'), -- BroadcastTextID: 34969 - 70901 - 129953 - 170353
(3145, 0, 0, '$C, I have an important mission for you.', 12, 0, 100, 1, 0, 0, 0 /*UNKNOWN*/, 0, 'Zureetha Fargaze to Player'),
(3183, 0, 0, 'I know what you\'re after and you won\'t have it!', 12, 0, 100, 5, 0, 0, 0 /*UNKNOWN*/, 0, 'Yarrog Baneshadow to Player'),
(3183, 1, 0, 'We are... everywhere.', 12, 0, 100, 153, 0, 0, 0 /*UNKNOWN*/, 0, 'Yarrog Baneshadow to Player'),
(9796, 0, 4, '$n, I have a task for you.', 12, 0, 100, 1, 0, 0, 0 /*UNKNOWN*/, 0, 'Galgar to Player'),
(10556, 0, 2, 'OK boss, I get back to tree-hitting.', 12, 1, 100, 0, 0, 7514, 40937, 0, 'Lazy Peon to Player'),
(10556, 0, 3, 'Just was resting eyes!  Back to work now!', 12, 1, 100, 0, 0, 7514, 40938, 0, 'Lazy Peon to Player'),
(10556, 0, 4, 'Sleepy... so sleepy...', 12, 1, 100, 0, 0, 7514, 40936, 0, 'Lazy Peon to Player'), -- BroadcastTextID: 40936 - 152174
(11378, 0, 0, '$n, get over here!', 14, 0, 100, 22, 0, 0, 0 /*UNKNOWN*/, 0, 'Foreman Thazz\'ril to Player');

UPDATE `gameobject_questitem` SET `VerifiedBuild`=44232 WHERE (`Idx`=0 AND `GameObjectEntry` IN (178087,171938,3290));
UPDATE `gameobject_template` SET `VerifiedBuild`=44232 WHERE `entry` IN (203841, 1619, 101749, 63674, 203857, 203856, 202839, 202835, 203844, 203843, 31408, 186238, 190549, 165742, 165743, 165744, 165741, 165751, 165745, 165749, 165748, 165747, 203845, 203850, 3719, 1618, 203853, 1731, 3290, 203854, 1617, 55615, 203855, 206575, 204190, 204164, 252071, 206574, 204187, 204166, 204165, 206737, 204666, 204665, 204658, 204645, 152614, 204193, 204189, 204188, 204186, 204184, 204177, 204176, 204175, 203471, 165746, 18083, 203842, 3084, 12665, 165750, 165740, 202587, 272677, 175784);
UPDATE `gameobject_template` SET `ContentTuningId`=70, `VerifiedBuild`=44232 WHERE `entry`=202580; -- Den Cage
UPDATE `gameobject_template` SET `IconName`='questinteract', `Data0`=1702, `Data1`=0, `Data30`=11500, `ContentTuningId`=70, `VerifiedBuild`=44325 WHERE `entry`=171938; -- Cactus Apple
UPDATE `gameobject_template` SET `IconName`='questinteract', `Data0`=93, `Data3`=0, `Data6`=0, `Data31`=1, `ContentTuningId`=1481, `VerifiedBuild`=44325 WHERE `entry`=178087; -- Thazz'ril's Pick
UPDATE `gameobject_template_addon` SET `flags`=2179076 WHERE `entry`=178087; -- Thazz'ril's Pick
UPDATE `gameobject_template_addon` SET `flags`=65540 WHERE `entry`=171938; -- Cactus Apple

DELETE FROM `gameobject_loot_template` WHERE `Entry`=16332;
INSERT INTO `gameobject_loot_template`(`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(16332, 16332, 0, 100, 1, 1, 0, 1, 1, '');

DELETE FROM `gossip_menu` WHERE (`MenuID`=21733 AND `TextID`=33157) OR (`MenuID`=14002 AND `TextID`=5715) OR (`MenuID`=14001 AND `TextID`=4793) OR (`MenuID`=14003 AND `TextID`=5006) OR (`MenuID`=14227 AND `TextID`=17176) OR (`MenuID`=13999 AND `TextID`=4985) OR (`MenuID`=14191 AND `TextID`=5001);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(21733, 33157, 44232), -- 3287 (Hana'zua) - Broadcast_text - 138726
(14002, 5715, 44232), -- 3156 (Nartok) - Broadcast_text - 8291
(14001, 4793, 44232), -- 3155 (Rwag) - Broadcast_text - 7476
(14003, 5006, 44232), -- 3157 (Shikrik) - Broadcast_text - 7660
(14227, 17176, 44232), -- 39206 (Acrypha) - Broadcast_text - 47371
(13999, 4985, 44232), -- 3153 (Frang) - Broadcast_text - 7631
(14191, 5001, 44232); -- 39214 (Karranisha) - Broadcast_text - 7652

UPDATE `gossip_menu` SET `VerifiedBuild`=44232 WHERE `MenuID`=83 AND `TextID`=580;
UPDATE `gossip_menu` SET `VerifiedBuild`=44232 WHERE `MenuID`=12670 AND `TextID`=12549;
UPDATE `gossip_menu` SET `VerifiedBuild`=44232 WHERE `MenuID`=13895 AND `TextID`=19889;

UPDATE `npc_vendor` SET `VerifiedBuild`=44232 WHERE (`entry`=3158 AND `item`=4496 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3158 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3158 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3882 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3882 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3882 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3882 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3882 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3882 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3882 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3882 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3882 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3882 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3882 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3882 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3161 AND `item`=1200 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3161 AND `item`=17183 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3161 AND `item`=2391 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3161 AND `item`=2390 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3161 AND `item`=2389 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3161 AND `item`=2388 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3161 AND `item`=2387 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3161 AND `item`=2386 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3160 AND `item`=714 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3160 AND `item`=1836 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3160 AND `item`=210 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3160 AND `item`=209 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3160 AND `item`=1835 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3160 AND `item`=85 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3160 AND `item`=711 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3160 AND `item`=3596 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3160 AND `item`=195 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3160 AND `item`=194 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3160 AND `item`=3595 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3160 AND `item`=193 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3159 AND `item`=2132 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3159 AND `item`=2139 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3159 AND `item`=2480 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3159 AND `item`=2130 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3159 AND `item`=2479 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3159 AND `item`=2134 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3159 AND `item`=1194 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3159 AND `item`=2131 AND `ExtendedCost`=0 AND `type`=1);

UPDATE `quest_details` SET `Emote1`=1, `Emote2`=25, `Emote3`=1, `VerifiedBuild`=44232 WHERE `ID`=25133; -- Report to Sen'jin Village
UPDATE `quest_details` SET `Emote2`=6, `Emote3`=1, `VerifiedBuild`=44232 WHERE `ID`=25135; -- Thazz'ril's Pick
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=25, `VerifiedBuild`=44232 WHERE `ID`=25132; -- Burning Blade Medallion
UPDATE `quest_details` SET `VerifiedBuild`=44232 WHERE `ID` IN (25130, 25129, 37446, 25136, 25152);
UPDATE `quest_details` SET `Emote2`=273, `Emote3`=25, `VerifiedBuild`=44232 WHERE `ID`=25131; -- Vile Familiars
UPDATE `quest_details` SET `Emote2`=6, `VerifiedBuild`=44232 WHERE `ID`=25128; -- Hana'zua
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=6, `VerifiedBuild`=44232 WHERE `ID`=25127; -- Sting of the Scorpid
UPDATE `quest_details` SET `Emote1`=274, `Emote2`=5, `Emote3`=1, `VerifiedBuild`=44232 WHERE `ID`=25172; -- Invaders in Our Home
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=273, `VerifiedBuild`=44232 WHERE `ID`=25126; -- Cutting Teeth

DELETE FROM `quest_greeting` WHERE (`ID`=3143 AND `Type`=0);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(3143, 0, 0, 0, 'The Valley of Trials will temper even the weakest into a warrior worthy to join the Horde. Those who cannot rise to its tests will be left to bake in the scorching desert sun.', 44232); -- 3143

UPDATE `quest_objectives` SET `VerifiedBuild`=44232 WHERE `ID` IN (391353, 267187, 267186, 259624, 264756, 397237, 265482, 265539, 289536, 289535, 289167, 254390, 254389, 265224, 265589, 265588, 264980, 265233, 276230, 276229, 265175, 265013, 256783, 256287);

UPDATE `quest_offer_reward` SET `Emote2`=274, `RewardText`='You retrieved it! Well done!\n\nYour efforts within the Burning Blade Coven are key in rooting out this cult in the Valley of Trials. But I fear they have further aims in our land.\n\nWe have not seen the end of them.', `VerifiedBuild`=44232 WHERE `ID`=25132; -- Burning Blade Medallion
UPDATE `quest_offer_reward` SET `Emote1`=4, `RewardText`='Great, you got it! Thanks a lot, $n. This is my favorite pick! Now if my peons ever finish chopping down these trees, maybe we can find a nice cave to mine!', `VerifiedBuild`=44232 WHERE `ID`=25135; -- Thazz'ril's Pick
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=273, `RewardText`='From your description of the beast, I believe you must be speaking of Sarkoth! It is no wonder that Hana\'zua was overtaken by it. Aid will be dispatched to him immediately, trouble yourself no more with Hana\'zua\'s plight.\n\nHowever, I must say, I am most impressed to hear that you brought Sarkoth to death. It is a feat to be proud of, $n. And that you would fight for a stranger\'s honor, while other tasks occupied your time, your own honor is heightened.', `VerifiedBuild`=44232 WHERE `ID`=25130; -- Back to the Den
UPDATE `quest_offer_reward` SET `Emote2`=273, `RewardText`='You have done well, $n.\n\nAlthough the Vile Familiars were merely pets of the darker powers within the Burning Blade, your success against them foretells greater deeds ahead.', `VerifiedBuild`=44232 WHERE `ID`=25131; -- Vile Familiars
UPDATE `quest_offer_reward` SET `VerifiedBuild`=44232 WHERE `ID`=25129;
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1, `RewardText`='There is an important lesson that you must take away from fighting scorpids. The smallest or largest of opponents can still send you to your doom. In fierce combat, any number of things can prove your downfall.\n\nI have no more to teach you, $n. You have done well, and I will watch your progress with interest.', `VerifiedBuild`=44232 WHERE `ID`=25127; -- Sting of the Scorpid
UPDATE `quest_offer_reward` SET `RewardText`='Good, good. Maybe they\'ll think twice before slacking next time! Thanks for the help!', `VerifiedBuild`=44232 WHERE `ID`=37446; -- Lazy Peons
UPDATE `quest_offer_reward` SET `Emote1`=4, /*`Emote2`=4294967295, `Emote3`=4294967295, `Emote4`=4294967295,*/ `VerifiedBuild`=44232 WHERE `ID`=25136; -- Galgar's Cactus Apple Surprise
UPDATE `quest_offer_reward` SET `Emote1`=273, `RewardText`='Executed with quickness and discretion. A job well done.', `VerifiedBuild`=44232 WHERE `ID`=25172; -- Invaders in Our Home
UPDATE `quest_offer_reward` SET `RewardText`='Hmm, not bad, $n. But don\'t let it get to your head...you\'ll fight tougher than boars in your career.\n\nNonetheless, you\'ve proven yourself well, and your next trial will be against a considerably more dangerous opponent, so you\'ll need some extra protection.', `VerifiedBuild`=44232 WHERE `ID`=25126; -- Cutting Teeth
UPDATE `quest_offer_reward` SET `RewardText`='Another one of Kaltunk\'s recruits, hmm?\n\nA sorry state of affairs we find ourselves in if this is the best the Horde can produce. No matter. By the time we think you\'re ready to leave the Valley, you\'ll be a proud warrior of the Horde.', `VerifiedBuild`=44232 WHERE `ID`=25152; -- Your Place In The World

UPDATE `quest_poi` SET `VerifiedBuild`=44232 WHERE (`QuestID`=25133 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=25133 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=25135 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=25135 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=25135 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=25135 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=25132 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=25132 AND `BlobIndex`=1 AND `Idx1`=4) OR (`QuestID`=25132 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=25132 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=25132 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=25132 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=25130 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=25130 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=25129 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=25129 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=25129 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=25131 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=25131 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=25131 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=25128 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=25128 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=37446 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=37446 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37446 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=25127 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=25127 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=25127 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=25136 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=25136 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=25136 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=25172 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=25172 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=25172 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=25126 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=25126 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=25126 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=25152 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=25152 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=44232 WHERE (`QuestID`=25133 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=25133 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=25135 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=25135 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=25135 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=25135 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=25132 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=25132 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=25132 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=25132 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=25132 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=25132 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=25132 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=25132 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=25132 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=25132 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=25132 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=25132 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=25130 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=25130 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=25129 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=25129 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=25129 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=25131 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=25131 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=25131 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=25131 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=25131 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=25131 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=25131 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=25131 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=25131 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=25131 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=25131 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=25131 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=25131 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=25128 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=25128 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=37446 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37446 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=37446 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=37446 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=37446 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=37446 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=37446 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=37446 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=37446 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=37446 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=37446 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=37446 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37446 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=25127 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=25127 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=25127 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=25127 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=25127 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=25127 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=25127 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=25127 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=25127 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=25127 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=25136 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=25136 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=25136 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=25136 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=25136 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=25136 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=25136 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=25136 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=25136 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=25136 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=25136 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=25136 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=25136 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=25136 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=25172 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=25172 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=25172 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=25172 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=25172 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=25172 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=25172 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=25172 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=25172 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=25126 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=25126 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=25126 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=25126 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=25126 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=25126 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=25126 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=25126 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=25126 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=25126 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=25126 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=25152 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=25152 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='No good lazy...\n\nEh? Do you have my blackjack? Did you catch any peons sleeping on the job?!', `VerifiedBuild`=44232 WHERE `ID`=37446; -- Lazy Peons
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=44232 WHERE `ID`=25136; -- Galgar's Cactus Apple Surprise
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`='Have you entered the Burning Blade Coven, $n? Did you find my pick?', `VerifiedBuild`=44232 WHERE `ID`=25135; -- Thazz'ril's Pick
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=44232 WHERE `ID`=25132; -- Burning Blade Medallion
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `CompletionText`='To prove yourself against the Burning Blade, you must first defeat these vile familiars. Return to me when you have done this.', `VerifiedBuild`=44232 WHERE `ID`=25131; -- Vile Familiars
UPDATE `quest_request_items` SET `CompletionText`='Ahhh... my father always said I would never amount to much, and here, lying beneath a tree as life seeps away, I\'m afraid it looks like he was right.\n\nAt least I wish to die knowing that my last enemy in life lays dead.', `VerifiedBuild`=44232 WHERE `ID`=25129; -- Sarkoth
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=44232 WHERE `ID`=25127; -- Sting of the Scorpid
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=274, `VerifiedBuild`=44232 WHERE `ID`=25126; -- Cutting Teeth
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='Quickly, $n. Dispatch of these humans in our valley.', `VerifiedBuild`=44232 WHERE `ID`=25172; -- Invaders in Our Home

UPDATE `quest_template` SET `VerifiedBuild`=44232 WHERE `ID` IN (25152, 46736, 46735, 46277);
UPDATE `quest_template` SET `RewardBonusMoney`=120, `VerifiedBuild`=44232 WHERE `ID` IN (56775, 59926); -- Warming Up
UPDATE `quest_template` SET `RewardBonusMoney`=90, `VerifiedBuild`=44232 WHERE `ID`=24974; -- Ever So Lonely
UPDATE `quest_template` SET `RewardBonusMoney`=30, `VerifiedBuild`=44232 WHERE `ID`=9704; -- Slain by the Wretched
UPDATE `quest_template` SET `RewardBonusMoney`=120, `VerifiedBuild`=44232 WHERE `ID`=8468; -- WANTED: Thaelis the Hungerer
UPDATE `quest_template` SET `RewardBonusMoney`=0, `VerifiedBuild`=44232 WHERE `ID`=9329; -- The Forsaken
UPDATE `quest_template` SET `RewardBonusMoney`=120, `VerifiedBuild`=44232 WHERE `ID`=14438; -- Sharing the Land
UPDATE `quest_template` SET `RewardBonusMoney`=120, `VerifiedBuild`=44232 WHERE `ID`=25236; -- Thunder Down Under
UPDATE `quest_template` SET `RewardBonusMoney`=90, `VerifiedBuild`=44232 WHERE `ID`=25170; -- Cleaning Up the Coastline
UPDATE `quest_template` SET `RewardBonusMoney`=450, `VerifiedBuild`=44232 WHERE `ID`=871; -- In Defense of Far Watch
UPDATE `quest_template` SET `RewardBonusMoney`=540, `VerifiedBuild`=44232 WHERE `ID`=25135; -- Thazz'ril's Pick
UPDATE `quest_template` SET `RewardBonusMoney`=660, `VerifiedBuild`=44232 WHERE `ID`=25132; -- Burning Blade Medallion
UPDATE `quest_template` SET `RewardBonusMoney`=90, `VerifiedBuild`=44232 WHERE `ID`=25130; -- Back to the Den
UPDATE `quest_template` SET `RewardBonusMoney`=360, `VerifiedBuild`=44232 WHERE `ID`=25129; -- Sarkoth
UPDATE `quest_template` SET `RewardBonusMoney`=540, `VerifiedBuild`=44232 WHERE `ID`=25131; -- Vile Familiars
UPDATE `quest_template` SET `RewardBonusMoney`=90, `VerifiedBuild`=44232 WHERE `ID`=25128; -- Hana'zua
UPDATE `quest_template` SET `RewardBonusMoney`=360, `VerifiedBuild`=44232 WHERE `ID`=37446; -- Lazy Peons
UPDATE `quest_template` SET `RewardBonusMoney`=270, `VerifiedBuild`=44232 WHERE `ID`=25127; -- Sting of the Scorpid
UPDATE `quest_template` SET `RewardBonusMoney`=300, `VerifiedBuild`=44232 WHERE `ID`=25136; -- Galgar's Cactus Apple Surprise
UPDATE `quest_template` SET `RewardBonusMoney`=210, `VerifiedBuild`=44232 WHERE `ID`=25172; -- Invaders in Our Home
UPDATE `quest_template` SET `RewardBonusMoney`=150, `VerifiedBuild`=44232 WHERE `ID`=25126; -- Cutting Teeth
UPDATE `quest_template` SET `RewardBonusMoney`=270, `VerifiedBuild`=44232 WHERE `ID`=25133; -- Report to Sen'jin Village

UPDATE `quest_template_addon` SET `NextQuestID`=0 WHERE `ID`=25128; -- Hana'zua
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=25129; -- Sarkoth

UPDATE `quest_visual_effect` SET `VerifiedBuild`=44232 WHERE (`Index`=0 AND `ID` IN (264980,276229, 391353,259624,397237));

-- Gornek SAI
UPDATE `creature_template` SET `AIName`="", `scriptname`="" WHERE `entry`=3143;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=25128 AND `ConditionTypeOrReference`=47 AND `ConditionValue1`=25129;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 25128, 0, 0, 47, 0, 25129, 1, 0, 0, 0, 0, '', 'Show quest 25128 - Hana\'zua if quest 25129 - Sarkoth is not taken/complete/rewarded');

 -- Creature 39317 smart ai
SET @ENTRY := 39317;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 4, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On aggro - Self: Talk 0 to invoker');
