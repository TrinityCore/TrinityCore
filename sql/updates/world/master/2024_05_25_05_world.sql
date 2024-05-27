SET @CGUID := 7000550;

DELETE FROM `phase_name` WHERE `ID`=12870;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12870, 'Cosmetic: Kul Tiran Unlock Questline - Wicker Beast in Wicker Hovel');

DELETE FROM `phase_area` WHERE `PhaseId`=12870;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9500, 12870, 'Cosmetic: Kul Tiran Unlock Questline - Wicker Beast in Wicker Hovel - Bleak Hills Mine'),
(9432, 12870, 'Cosmetic: Kul Tiran Unlock Questline - Wicker Beast in Wicker Hovel - Watchman''s Rise');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12870));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12870, 0, 0, 0, 47, 0, 55136, 74, 0, '', 1, 'Player doesn\'t have Her Dog Days Are Over (55136) in state incomplete, complete, rewarded'),
(26, 12870, 0, 0, 0, 48, 0, 388746, 0, 1, '', 0, 'Player has quest objective 388746 == 1 (but hasn\'t rewarded quest yet)');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 150885, 1643, 8721, 9500, '0', 12870, 0, 0, 0, 161.9340362548828125, 3202.85498046875, 283.35394287109375, 2.528188228607177734, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847); -- Wicker Beast (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1

-- 
UPDATE `creature_model_info` SET `VerifiedBuild`=54847 WHERE `DisplayID` IN (85028, 85029, 106962, 85408, 4259, 85407, 85410, 30244, 84293, 84296, 84295, 85409, 4601, 79540, 80653, 88527, 85965, 80444, 79523, 73274, 77269, 79522, 40025, 40021, 79552, 70445, 64016, 70443, 40020, 70451, 79806, 80955, 79808, 80953, 70442, 2177, 81082, 79366, 70440, 82000, 86952, 81965, 79375, 79195, 81994, 85629, 40093, 51294, 36620, 82001, 87979, 88292, 80054, 45149, 76994, 72014, 64184, 76995, 75365, 78631, 70448, 32187, 82797, 84086, 78046, 81745, 84087, 79313, 82959, 63016, 76875, 90896, 79001, 78999, 78468, 78216, 78214, 84085, 78210, 77046, 78211, 236, 82795, 76855, 78215, 78964, 77048, 79496, 78467, 38857, 78196, 79952, 78195, 82546, 78212, 82579, 88481, 76857, 238, 88616, 82936, 36957, 36956, 85649, 87370, 82947, 79280, 60901, 79246, 9829, 36595, 976, 15468, 38497, 6533, 81928, 81866, 77489, 90148, 80753, 79557, 91494, 91495, 90814, 8550, 90149, 86806, 86805, 86803, 80754, 45092, 80752, 82954, 80854, 82955, 40713, 80778, 79871, 85189, 85188, 88594, 80983, 87918, 64329, 82019, 82239, 81199, 79558, 70449, 62722, 79559, 82950, 79211, 30256, 81753, 42408, 85214, 45491, 82543, 82540, 78472, 78990, 78963, 84804, 82544, 79900, 78965, 78962, 77498, 76548, 79560, 81746, 82796, 83812, 76552, 78992, 78469, 79382, 78471, 17188, 79380, 82539, 82937, 81747, 88482, 75339, 82612, 77053, 81743, 85213, 78475, 82538, 75340, 78994, 80845, 82541, 78993, 80846, 77043, 82545, 39726, 78835, 237, 78967, 45490, 81957, 42744, 70446, 76880, 4626, 229, 76870, 6302, 76889, 79058, 76856, 79059, 81084, 33719, 32646, 88290, 8014, 45494, 86197, 81078, 4260, 30263, 84294);
UPDATE `creature_model_info` SET `BoundingRadius`=0.665383040904998779, `CombatReach`=0.800000011920928955, `VerifiedBuild`=54847 WHERE `DisplayID` IN (70663, 71224);
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1.5, `VerifiedBuild`=54847 WHERE `DisplayID` IN (81966, 81964);
UPDATE `creature_model_info` SET `BoundingRadius`=1.847487092018127441, `VerifiedBuild`=54847 WHERE `DisplayID`=32546;
UPDATE `creature_model_info` SET `BoundingRadius`=0.938482880592346191, `CombatReach`=1, `VerifiedBuild`=54847 WHERE `DisplayID`=78242;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `VerifiedBuild`=54847 WHERE `DisplayID`=82537;
UPDATE `creature_model_info` SET `BoundingRadius`=1.594119191169738769, `CombatReach`=1.760000109672546386, `VerifiedBuild`=54847 WHERE `DisplayID`=79267;
UPDATE `creature_model_info` SET `BoundingRadius`=0.642672121524810791, `CombatReach`=1.5, `VerifiedBuild`=54847 WHERE `DisplayID`=765;
UPDATE `creature_model_info` SET `BoundingRadius`=1.32942509651184082, `CombatReach`=1.60000002384185791, `VerifiedBuild`=54847 WHERE `DisplayID`=81194;
UPDATE `creature_model_info` SET `BoundingRadius`=0.908434152603149414, `CombatReach`=1.5, `VerifiedBuild`=54847 WHERE `DisplayID`=87960;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6987152099609375, `CombatReach`=1.5, `VerifiedBuild`=54847 WHERE `DisplayID`=87959;
UPDATE `creature_model_info` SET `BoundingRadius`=1.594113588333129882, `CombatReach`=1, `VerifiedBuild`=54847 WHERE `DisplayID`=79800;

DELETE FROM `gameobject_template` WHERE `entry` IN (322638 /*Gnawed Bone*/, 322637 /*Squeaky Toy*/, 322636 /*Worn Collar*/, 322620 /*Storeroom Keys*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(322638, 3, 26528, 'Gnawed Bone', 'questinteract', 'Collecting', '', 2, 2160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 95371, 1, 0, 0, 0, 674, 54847), -- Gnawed Bone
(322637, 3, 36950, 'Squeaky Toy', 'questinteract', 'Collecting', '', 1, 2160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 95370, 1, 0, 0, 0, 674, 54847), -- Squeaky Toy
(322636, 3, 52309, 'Worn Collar', 'questinteract', 'Collecting', '', 2, 2160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 95369, 1, 0, 0, 0, 674, 54847), -- Worn Collar
(322620, 3, 42973, 'Storeroom Keys', 'questinteract', 'Collecting', '', 1.5, 2160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 95364, 1, 0, 0, 0, 674, 54847); -- Storeroom Keys

UPDATE `gameobject_template` SET `VerifiedBuild`=54847 WHERE `entry` IN (287329, 277273, 296271, 276258, 276257, 276251, 279586, 279587, 292912, 279594, 292913, 295192, 295190, 295188, 295170, 295169, 295168, 295167, 295166, 295165, 295164, 295163, 281014, 295183, 278778, 295293, 295210, 295220, 295295, 295292, 295209, 295207, 295294, 295208, 295299, 295297, 295296, 295216, 295215, 295214, 295213, 295298, 295212, 295211, 295303, 295302, 295301, 295300, 295225, 295224, 295223, 295222, 277514, 279319, 279318, 273955, 295178, 276256, 297132, 295179, 295316, 295317, 276733, 297139, 295794, 295793, 295792, 295791, 317053, 316866, 316865, 316864, 294921, 35591, 275074, 281464, 281420, 294927, 281909, 288480, 288195, 277717, 278402, 277427, 277386, 281609, 295314, 294556, 295313, 287404, 295277, 295276, 295273, 295272, 294477, 294476, 294475, 292547, 295802, 295274, 295226, 295275, 295227, 295247, 303145, 295801, 295206, 295321, 295271, 295270, 295246, 295221, 289310, 282250, 281718, 272201, 272200, 295269, 295266, 295268, 295258, 295260, 296390, 295902, 295901, 295900, 295899, 295898, 295267, 295261, 295259, 295200, 295265, 295264, 295263, 295262, 295219, 295218, 295217, 278252, 309572, 279703, 280693, 302838, 302839, 292873, 297937, 278571, 278406, 278405, 279289, 278528, 291204, 290146, 276240, 290145, 298913, 298459, 297137, 297136, 277595, 276255, 276254, 302779, 298769, 277596, 276403, 276253, 276234, 278432, 297630, 295778, 297903, 297902, 297892, 276874, 276645, 276872, 276871, 276868, 277331, 277330, 277329, 276873, 276867, 375181);
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=54847 WHERE `entry`=273270; -- Harbor Seaweed
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=54847 WHERE `entry`=273798; -- Jar of Blubber
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=54847 WHERE `entry`=273799; -- Bundle of Vellum
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=54847 WHERE `entry`=276837; -- Recipe Rock
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=54847 WHERE `entry`=287941; -- Bag of Horse Treats
UPDATE `gameobject_template` SET `ContentTuningId`=705, `VerifiedBuild`=54847 WHERE `entry`=275070; -- Small Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=54847 WHERE `entry`=276838; -- Stirring Bone
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=54847 WHERE `entry`=278813; -- Post
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=54847 WHERE `entry`=276270; -- Soup Stone
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=54847 WHERE `entry`=281172; -- Suspicious Pile of Meat
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=54847 WHERE `entry`=277415; -- Drust Rune Trap
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=54847 WHERE `entry`=273956; -- Small Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=54847 WHERE `entry`=276206; -- Bundle of Wicker
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=54847 WHERE `entry`=276205; -- Bones
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=54847 WHERE `entry`=276204; -- Fruit
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=54847 WHERE `entry`=276203; -- Herbs
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=54847 WHERE `entry`=276202; -- Grain
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=54847 WHERE `entry`=276201; -- Scrolls
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=54847 WHERE `entry`=276200; -- Entrails
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=54847 WHERE `entry`=276247; -- Child-sized Backpack
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=77845, `ContentTuningId`=187, `VerifiedBuild`=54847 WHERE `entry`=278516; -- Adventurer's Society Loot Stash
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=54847 WHERE `entry`=276869; -- Wrapped Supplies
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=54847 WHERE `entry`=276870; -- Cask of Salted Fish

DELETE FROM `gameobject_questitem` WHERE (`Idx`=0 AND `GameObjectEntry` IN (322638,322637,322636,322620));
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(322638, 0, 167174, 54847), -- Gnawed Bone
(322637, 0, 167173, 54847), -- Squeaky Toy
(322636, 0, 167172, 54847), -- Worn Collar
(322620, 0, 167168, 54847); -- Storeroom Keys

UPDATE `gameobject_questitem` SET `VerifiedBuild`=54847 WHERE (`Idx`=0 AND `GameObjectEntry` IN (276258,276257,273270,273798,273799,276838,276270,281909,277427,276255,276254,276253,281137,284422,280802));
