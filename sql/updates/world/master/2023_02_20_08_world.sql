SET @CGUID := 3000032;
SET @OGUID := 3000861;
SET @EVENT := 8;

-- Creature templates
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags`=32768 WHERE `entry`=40438; -- Steamwheedle Shyster
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=38342; -- [DND] Holiday - Love - Barber Bunny
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=38341; -- [DND] Holiday - Love - AH Bunny
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=38340; -- [DND] Holiday - Love - Bank Bunny
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags`=512 WHERE `entry` IN (38339, 38338, 38337); -- Snivel Rustrocket
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=38328; -- Roka
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=38288; -- Love Guard Perfume Bunny
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=38042; -- Kwee Q. Peddlefeet
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags`=512 WHERE `entry`=37715; -- Snivel Rustrocket
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=37675; -- Public Relations Agent
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=37674; -- Lovely Merchant
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags`=32768 WHERE `entry`=37671; -- Crown Supply Guard
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=37172; -- Detective Snap Snagglebolt
UPDATE `creature_template` SET `maxlevel`=70, `speed_run`=0.857142865657806396, `unit_flags`=768 WHERE `entry`=16085; -- Peddlefeet

DELETE FROM `creature_template_addon` WHERE `entry` IN (40438, 38342, 38341, 38340, 38339, 38338, 38337, 38328, 38288, 38042, 37715, 37675, 37674, 37671, 37172, 16085);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(40438, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 40438 (Steamwheedle Shyster)
(38342, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 38342 ([DND] Holiday - Love - Barber Bunny)
(38341, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 38341 ([DND] Holiday - Love - AH Bunny)
(38340, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 38340 ([DND] Holiday - Love - Bank Bunny)
(38339, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 38339 (Snivel Rustrocket)
(38338, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 38338 (Snivel Rustrocket)
(38337, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 38337 (Snivel Rustrocket)
(38328, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 38328 (Roka)
(38288, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 38288 (Love Guard Perfume Bunny)
(38042, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 38042 (Kwee Q. Peddlefeet)
(37715, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, '71776'), -- 37715 (Snivel Rustrocket) - Snivel Rustrocket Invisibility
(37675, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 37675 (Public Relations Agent)
(37674, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 37674 (Lovely Merchant)
(37671, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 37671 (Crown Supply Guard)
(37172, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 37172 (Detective Snap Snagglebolt)
(16085, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 16085 (Peddlefeet)

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (16085, 38340, 38341, 38342);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(16085, 0, 0, 1, 0, 0, 0, NULL),
(38340, 0, 0, 1, 0, 0, 0, NULL),
(38341, 0, 0, 1, 0, 0, 0, NULL),
(38342, 0, 0, 1, 0, 0, 0, NULL);

-- Gossips
DELETE FROM `gossip_menu` WHERE (`MenuID`=10929 AND `TextID`=15213);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(10929, 15213, 48069); -- 37715 (Snivel Rustrocket)

UPDATE `gossip_menu` SET `VerifiedBuild`=48069 WHERE (`MenuID`=10948 AND `TextID`=15212) OR (`MenuID`=11386 AND `TextID`=15857) OR (`MenuID`=10990 AND `TextID`=15280) OR (`MenuID`=10947 AND `TextID`=15211) OR (`MenuID`=10945 AND `TextID`=15209) OR (`MenuID`=10976 AND `TextID`=15256) OR (`MenuID`=10929 AND `TextID`=15188) OR (`MenuID`=10946 AND `TextID`=15210) OR (`MenuID`=10921 AND `TextID`=15170) OR (`MenuID`=16042 AND `TextID`=23141);

UPDATE `gossip_menu_option` SET `GossipOptionID`=37331, `VerifiedBuild`=48069 WHERE (`MenuID`=11386 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=37979, `VerifiedBuild`=48069 WHERE (`MenuID`=10948 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=36926, `VerifiedBuild`=48069 WHERE (`MenuID`=10946 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=36781, `VerifiedBuild`=48069 WHERE (`MenuID`=10945 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=36444, `VerifiedBuild`=48069 WHERE (`MenuID`=10976 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=36445, `OptionBroadcastTextId`=40429, `VerifiedBuild`=48069 WHERE (`MenuID`=10976 AND `OptionID`=1);
UPDATE `gossip_menu_option` SET `GossipOptionID`=38389, `VerifiedBuild`=48069 WHERE (`MenuID`=10929 AND `OptionID`=0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=10929;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (10929, 10948, 10976);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 10929, 15188, 0, 0, 47, 0, 24576, 2 | 64, 0, 1, 0, 0, '', 'Show gossip text 15188 if quest 24576 is not complete | rewarded'),
(14, 10929, 15188, 0, 1, 47, 0, 24576, 2 | 64, 0, 1, 0, 0, '', 'Show gossip text 15188 if quest 24657 is not complete | rewarded'),
(14, 10929, 15213, 0, 0, 47, 0, 24576, 2 | 64, 0, 0, 0, 0, '', 'Show gossip text 15213 if quest 24576 is complete | rewarded'),
(14, 10929, 15213, 0, 1, 47, 0, 24657, 2 | 64, 0, 0, 0, 0, '', 'Show gossip text 15213 if quest 24576 is complete | rewarded'),
(15, 10929, 0, 0, 0, 47, 0, 24576, 8, 0, 0, 0, 0, '', 'Show gossip option if quest 24576 is taken'),
(15, 10929, 0, 0, 1, 47, 0, 24657, 8, 0, 0, 0, 0, '', 'Show gossip option if quest 24657 is taken'),
(15, 10948, 0, 0, 0, 2, 0, 49661, 1, 1, 1, 0, 0, '', 'Show gossip option if player does not have Lovely Charm Collector''s Kit'),
(15, 10976, 0, 0, 0, 47, 0, 24541, 8, 0, 0, 0, 0, '', 'Show gossip option if quest 24541 is taken'),
(15, 10976, 0, 0, 1, 47, 0, 24656, 8, 0, 0, 0, 0, '', 'Show gossip option if quest 24656 is taken'),
(15, 10976, 1, 0, 0, 47, 0, 24576, 64, 0, 0, 0, 0, '', 'Show gossip option if quest 24576 is rewarded'),
(15, 10976, 1, 0, 1, 47, 0, 24657, 64, 0, 0, 0, 0, '', 'Show gossip option if quest 24657 is rewarded');

-- Equipments
DELETE FROM `creature_equip_template` WHERE `CreatureID`=38337 AND `ID`=1;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(38337, 1, 12850, 0, 0, 12851, 0, 0, 0, 0, 0, 48069); -- Snivel Rustrocket

UPDATE `creature_equip_template` SET `VerifiedBuild`=48069 WHERE (`ID`=1 AND `CreatureID` IN (176554,175135,173279,171791,169177,168459,89830,88703,88702,88701,74228,72559,62195,58155,51346,49750,49622,47571,46556,46555,46357,46142,46140,45339,45337,44878,44877,44876,44872,44871,44851,35068,31727,31726,31725,31724,31723,31720,23128,14392,14377,14375,6929,6466,5817,5614,5613,5611,5610,5609,5606,5188,4047,3370,3342,3323,3314,3313,3312,3296,3144)) OR (`ID`=4 AND `CreatureID`=169177) OR (`ID`=5 AND `CreatureID`=169177) OR (`ID`=6 AND `CreatureID`=169177) OR (`ID`=2 AND `CreatureID` IN (169177,74228,3296));

-- Models
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (111056, 110794, 110760, 110620, 110618, 110614, 110605, 110583, 110569, 110514, 111496, 110481, 110190, 111139, 105423, 104779, 106967, 106964);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(111056, 0.372000008821487426, 1.5, 0, 48069),
(110794, 0.347222000360488891, 1.5, 0, 48069),
(110760, 0.305999994277954101, 1.5, 0, 48069),
(110620, 0.722000002861022949, 3, 0, 48069),
(110618, 0.698000013828277587, 3, 0, 48069),
(110614, 0.722000002861022949, 3, 0, 48069),
(110605, 0.698000013828277587, 3, 0, 48069),
(110583, 0.722000002861022949, 3, 0, 48069),
(110569, 0.698000013828277587, 3, 0, 48069),
(110514, 0.722000002861022949, 3, 0, 48069),
(111496, 3.710472345352172851, 3.25, 0, 48069),
(110481, 0.347222000360488891, 1.5, 0, 48069),
(110190, 0.722000002861022949, 2, 0, 48069),
(111139, 0.236000001430511474, 1.5, 0, 48069),
(105423, 0.150000005960464477, 0.150000005960464477, 0, 48069),
(104779, 1.102368593215942382, 2.02500009536743164, 0, 48069),
(106967, 0.305999994277954101, 1.5, 0, 48069),
(106964, 0.305999994277954101, 1.5, 0, 48069);

UPDATE `creature_model_info` SET `VerifiedBuild`=48069 WHERE `DisplayID` IN (64062, 106345, 30313, 30314, 30316, 30315, 110191, 110183, 110187, 110186, 110185, 110184, 110182, 110181, 110165, 110138, 104187, 104198, 109888, 109886, 73093, 79383, 109709, 31958, 105577, 101799, 100500, 101484, 27153, 100444, 100158, 100157, 100150, 24079, 99385, 99374, 72174, 99139, 99138, 100727, 98725, 91667, 25423, 25436, 27589, 8631, 9132, 27599, 98009, 70436, 97757, 72325, 96328, 96332, 96329, 96084, 96422, 96327, 96364, 96916, 96915, 96914, 96913, 96910, 96906, 96905, 96903, 96885, 96884, 96883, 24877, 94494, 79390, 85697, 93637, 93433, 93434, 93431, 93422, 93420, 93418, 92463, 92464, 28048, 90133, 70992, 90366, 83764, 83765, 16697, 90318, 90304, 90303, 90301, 90302, 90255, 90252, 90246, 90245, 90244, 16235, 16238, 20988, 20985, 86333, 86332, 90129, 90130, 75972, 75973, 90242, 90243, 89937, 89935, 30312, 66245, 77407, 77405, 77406, 77690, 77687, 87513, 64307, 86393, 86688, 34252, 1592, 83227, 83228, 82803, 82770, 68512, 81476, 73494, 73128, 73121, 44315, 34207, 34208, 73028, 45692, 72807, 72802, 72804, 72800, 72801, 72795, 72791, 72792, 72786, 72788, 72784, 72779, 72765, 72778, 29310, 73053, 73054, 24982, 61763, 99455, 61027, 61026, 8001, 61024, 61023, 58745, 31737, 31738, 99462, 99507, 51098, 51000, 52707, 49770, 46126, 47982, 14612, 28300, 47465, 47231, 46986, 46897, 44740, 43726, 43725, 43724, 43722, 43721, 43720, 43719, 43718, 43717, 45862, 45864, 44604, 5705, 29968, 32790, 42722, 42720, 39637, 20545, 42389, 42388, 42387, 42385, 42386, 42384, 30781, 24806, 26741, 26747, 40012, 39910, 39809, 42562, 22602, 38804, 38800, 38631, 38008, 33303, 22769, 38047, 37864, 37795, 37725, 37724, 37723, 99809, 37329, 37331, 37328, 37330, 33194, 33191, 37138, 37020, 37088, 31760, 37437, 37023, 36598, 36585, 36583, 36584, 36615, 15468, 15467, 8971, 7511, 36559, 36545, 31988, 36170, 36169, 11414, 35844, 35843, 35827, 35819, 35818, 35816, 99822, 35695, 35545, 35544, 35538, 35504, 35500, 35499, 35498, 99460, 35250, 35249, 35244, 99810, 35242, 35241, 35237, 99808, 35218, 35216, 35198, 35195, 35194, 35193, 35192, 35187, 35186, 35185, 35184, 35183, 35148, 35140, 35141, 35133, 35053, 35052, 35051, 34932, 14370, 89803, 89802, 34843, 34842, 34841, 34695, 34694, 99513, 34673, 34593, 34569, 34568, 34567, 34566, 34565, 34564, 34562, 34561, 34558, 34557, 34556, 34555, 34551, 34421, 34412, 34406, 34340, 99426, 99427, 9392, 2141, 34268, 34266, 99510, 34247, 34246, 34245, 34243, 34242, 34241, 34222, 34220, 34219, 34214, 48528, 48526, 48525, 34206, 34204, 34203, 30413, 34185, 34184, 1310, 1320, 1318, 8000, 9133, 34157, 34156, 34155, 34154, 34144, 34143, 34141, 34139, 34136, 34111, 34110, 34109, 34114, 34113, 99429, 34108, 34107, 34066, 30501, 34059, 99403, 34049, 34046, 34047, 34045, 304, 33701, 33698, 33699, 33700, 35301, 4368, 3027, 193, 33032, 25092, 33016, 33015, 33014, 34705, 32997, 32998, 32996, 32982, 32981, 32937, 32936, 32938, 18269, 99807, 32171, 32173, 32172, 31852, 21072, 17612, 31041, 11686, 15990, 30712, 30711, 30708, 30728, 27823, 29795, 30108, 1917, 29599, 29569, 29496, 29396, 29375, 29371, 29370, 29369, 29368, 29367, 29366, 28118, 28120, 10824, 23513, 2541, 27727, 2729, 1042, 913, 4602, 27687, 27685, 27684, 27686, 27510, 99511, 27252, 27164, 25871, 25955, 21342, 22493, 24164, 22873, 22750, 22746, 22745, 22744, 22743, 22740, 22739, 21264, 17701, 17722, 17719, 17721, 17720, 17699, 17700, 19217, 16850, 81306, 81307, 45319, 45170, 15992, 15988, 15984, 15469, 15470, 15322, 15369, 20923, 14574, 14573, 14575, 38419, 14589, 38418, 14616, 99815, 14499, 51613, 14415, 14414, 14413, 13843, 13341, 4449, 12680, 12679, 12678, 12677, 12676, 12675, 12673, 12672, 12671, 247, 2327, 12229, 11734, 10697, 10696, 10695, 10589, 10578, 10472, 10186, 9739, 9261, 8848, 99820, 7871, 99508, 15352, 6854, 6843, 6873, 6303, 1206, 2957, 6060, 6006, 6005, 5846, 6839, 5770, 5769, 5706, 10732, 5205, 1560, 4546, 4545, 4534, 99461, 4356, 99457, 4351, 99817, 3759, 99456, 3609, 3608, 3606, 7137, 3605, 3604, 2328, 3128, 43669, 45320, 1987, 2954, 2956, 4464, 4515, 4514, 4612, 7136, 99818, 4363, 99509, 4358, 4231, 2735, 2734, 1394, 1393, 1392, 99814, 1390, 99811, 1388, 1387, 1386, 99812, 1384, 1383, 1382, 1381, 1380, 1379, 1378, 1377, 1375, 1374, 1373, 1372, 99819, 99821, 1368, 99823, 1366, 1358, 99454, 1334, 1333, 1332, 99458, 1330, 1329, 1328, 1327, 1323, 99428, 99816, 1319, 99813, 1316, 1315, 1314, 1313, 1312, 1311, 4260, 99451, 4259, 4601, 99453, 99452, 744, 99449, 99459, 82115, 9391, 8572, 4386, 4384, 46093, 901, 134, 4382, 64799, 207);
UPDATE `creature_model_info` SET `BoundingRadius`=0.280177772045135498, `CombatReach`=1, `VerifiedBuild`=48069 WHERE `DisplayID`=87564;

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (201314,200333,200248,199643,199625,199602,199288,199283,199275,199264,199202,199174,199164,199115,199025,199024,199023,199022,199021,198949,198557,198553,198552,198542,198540,198539,198538,198537,198536,198518,198070,191463,185670,185669,185473,185472,184187,183978,148030,118791,113827,38339,38338,38337,38328,37715,16085));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(201314, 0, 0, 0, 866, 48069),
(200333, 0, 0, 0, 378, 48069),
(200248, 0, 0, 0, 328, 48069),
(199643, 0, 0, 0, 864, 48069),
(199625, 0, 0, 0, 864, 48069),
(199602, 0, 0, 0, 864, 48069),
(199288, 0, 0, 0, 866, 48069),
(199283, 0, 0, 0, 865, 48069),
(199275, 0, 0, 0, 866, 48069),
(199264, 0, 0, 0, 866, 48069),
(199202, 0, 0, 0, 866, 48069),
(199174, 0, 0, 0, 866, 48069),
(199164, 0, 0, 0, 866, 48069),
(199115, 0, 0, 0, 864, 48069),
(199025, 0, 0, 0, 866, 48069),
(199024, 0, 0, 0, 866, 48069),
(199023, 0, 0, 0, 866, 48069),
(199022, 0, 0, 0, 866, 48069),
(199021, 0, 0, 0, 866, 48069),
(198949, 0, 0, 0, 293, 48069),
(198557, 0, 0, 0, 81, 48069),
(198553, 0, 0, 0, 866, 48069),
(198552, 0, 0, 0, 866, 48069),
(198542, 0, 0, 0, 866, 48069),
(198540, 0, 0, 0, 866, 48069),
(198539, 0, 0, 0, 866, 48069),
(198538, 0, 0, 0, 866, 48069),
(198537, 0, 0, 0, 866, 48069),
(198536, 0, 0, 0, 866, 48069),
(198518, 0, 0, 0, 866, 48069),
(198070, 0, 0, 0, 2424, 48069),
(191463, 0, 0, 0, 181, 48069),
(185670, 0, 0, 0, 181, 48069),
(185669, 0, 0, 0, 181, 48069),
(185473, 0, 0, 0, 866, 48069),
(185472, 0, 0, 0, 866, 48069),
(184187, 0, 0, 0, 371, 48069),
(183978, 0, 0, 0, 877, 48069),
(148030, 0, 0, 0, 866, 48069),
(118791, 0, 0, 0, 378, 48069),
(113827, 0, 0, 0, 371, 48069),
(38339, 0, 0, 0, 378, 48069),
(38338, 0, 0, 0, 378, 48069),
(38337, 0, 0, 0, 378, 48069),
(38328, 0, 0, 0, 378, 48069),
(37715, 0, 0, 0, 378, 48069),
(16085, 0, 0, 0, 371, 48069);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=48069 WHERE (`DifficultyID`=0 AND `Entry` IN (198541,198497,198096,197771,197770,197767,180684,180176,179897,176554,176261,176095,176094,176012,175135,175084,175050,174865,174864,174863,174170,174164,174147,173548,173281,173279,172558,171791,171691,171689,169177,169166,168628,168626,168623,168621,168619,168598,168597,168596,168553,168551,168540,168459,167032,161223,161203,160452,158789,158141,158138,158133,158131,155739,153285,152643,151937,150131,149626,149616,149523,149522,149409,149408,149371,149297,149296,149290,149279,149270,149258,148795,148770,148768,148265,148263,148250,148242,146626,145714,143622,142668,142666,141920,141912,141528,141310,140462,140210,139093,137762,135202,135201,133523,133271,133261,133186,132969,130911,114840,114131,114114,114068,114067,114066,113997,113540,113381,113380,113377,113376,113375,113374,113373,113331,113291,97526,89830,89713,88706,88705,88704,88703,88702,88701,85254,74228,73151,72939,72654,72559,71100,70301,69978,69977,69333,68979,68869,68655,66022,65078,65076,65074,65071,65065,65063,65061,65060,65058,65008,64105,63626,63086,62822,62821,62445,62200,62199,62198,62197,62196,62195,62194,62193,62115,62114,61369,61245,58199,58193,58155,57922,57801,55054,54870,54657,54473,54472,54113,54004,53081,52812,52810,52809,52382,52170,52036,52034,52033,52032,51346,51230,51195,50488,50482,50477,50323,50304,50088,49837,49750,49743,49737,49622,49573,49131,48513,48510,47818,47817,47815,47809,47808,47788,47771,47767,47764,47663,47649,47571,47336,47335,47321,47254,47253,47248,47247,47246,47233,46985,46755,46754,46742,46741,46718,46716,46709,46708,46675,46667,46642,46640,46639,46638,46637,46622,46621,46620,46619,46618,46572,46556,46555,46512,46359,46358,46357,46181,46142,46140,46082,46080,46078,45830,45814,45789,45659,45567,45566,45565,45563,45559,45558,45553,45552,45549,45548,45546,45545,45540,45347,45339,45337,45244,45230,45211,45139,45138,45137,45095,45094,45093,45086,45082,45081,45029,45025,45023,45019,45015,45008,44978,44975,44948,44919,44918,44878,44877,44876,44872,44871,44868,44867,44866,44865,44856,44854,44853,44852,44851,44788,44787,44785,44783,44782,44781,44780,44779,44770,44745,44743,44740,44735,44726,44725,44723,44338,44160,44158,43499,43239,43062,42859,42709,42673,42672,42671,42650,42638,42637,42548,42506,40891,40438,38821,38342,38341,38340,38288,38042,37675,37674,37671,37172,37072,35845,35364,35162,35096,35086,35068,34955,34765,34730,34723,34721,34719,34718,34717,34715,32642,32641,32520,31769,31768,31758,31757,31756,31755,31727,31726,31725,31724,31723,31720,31146,30723,30706,30611,29929,29143,28960,27489,26537,25081,25080,25075,24935,24934,24931,24930,24929,24927,24926,24924,23635,23128,20493,20492,20491,20490,20489,20488,20486,19850,17098,16926,16909,16869,16868,16076,16069,15476,15188,15186,14881,14541,14540,14539,14498,14451,14392,14377,14376,14375,13842,13417,12798,12797,12796,12795,12794,12793,12791,12790,12789,12353,12351,12136,11814,11178,11177,11176,11066,11046,11017,10880,10266,9988,9564,8659,8576,8404,7951,7793,7792,7790,7567,7565,7562,7311,7231,7230,7088,7010,6987,6986,6929,6566,6466,5951,5910,5909,5892,5875,5817,5816,5812,5811,5640,5639,5614,5613,5611,5610,5609,5606,5195,5188,5034,5029,4953,4752,4311,4047,4043,3413,3412,3409,3405,3404,3403,3400,3399,3372,3371,3370,3369,3368,3367,3366,3365,3364,3363,3362,3361,3360,3359,3358,3357,3356,3355,3354,3353,3352,3351,3350,3348,3347,3346,3345,3342,3335,3334,3333,3332,3331,3330,3329,3328,3327,3323,3322,3321,3319,3317,3316,3315,3314,3313,3312,3310,3296,3225,3216,3189,3144,3084,2857,2855,2756,1420,1412,1383,416,356));
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `VerifiedBuild`=48069 WHERE (`Entry`=63085 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=-4, `VerifiedBuild`=48069 WHERE (`Entry`=14499 AND `DifficultyID`=0);

-- Vendor data
DELETE FROM `npc_vendor` WHERE (`entry`=37674 AND `item`=187998 AND `ExtendedCost`=5791 AND `type`=1) OR (`entry`=37674 AND `item`=167732 AND `ExtendedCost`=5791 AND `type`=1) OR (`entry`=37674 AND `item`=165670 AND `ExtendedCost`=6450 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(37674, 30, 187998, 0, 5791, 1, 0, 0, 48069), -- Eternal Heirloom Scabbard
(37674, 29, 167732, 0, 5791, 1, 0, 0, 48069), -- Battle-Hardened Heirloom Scabbard
(37674, 24, 165670, 0, 6450, 1, 0, 0, 48069); -- Peddlefeet's Lovely Hearthstone

UPDATE `npc_vendor` SET `VerifiedBuild`=48069 WHERE (`entry`=37674 AND `item`=142341 AND `ExtendedCost`=3690 AND `type`=1) OR (`entry`=37674 AND `item`=144339 AND `ExtendedCost`=6149 AND `type`=1) OR (`entry`=37674 AND `item`=22261 AND `ExtendedCost`=2726 AND `type`=1) OR (`entry`=37674 AND `item`=116648 AND `ExtendedCost`=2729 AND `type`=1) OR (`entry`=37674 AND `item`=34480 AND `ExtendedCost`=2726 AND `type`=1) OR (`entry`=37674 AND `item`=50161 AND `ExtendedCost`=2733 AND `type`=1) OR (`entry`=37674 AND `item`=50160 AND `ExtendedCost`=2733 AND `type`=1) OR (`entry`=37674 AND `item`=116155 AND `ExtendedCost`=2729 AND `type`=1) OR (`entry`=37674 AND `item`=22235 AND `ExtendedCost`=2729 AND `type`=1) OR (`entry`=37674 AND `item`=22200 AND `ExtendedCost`=2727 AND `type`=1) OR (`entry`=37674 AND `item`=34258 AND `ExtendedCost`=2727 AND `type`=1) OR (`entry`=37674 AND `item`=22218 AND `ExtendedCost`=2728 AND `type`=1) OR (`entry`=37674 AND `item`=49909 AND `ExtendedCost`=2726 AND `type`=1) OR (`entry`=37674 AND `item`=21813 AND `ExtendedCost`=2728 AND `type`=1) OR (`entry`=37674 AND `item`=134860 AND `ExtendedCost`=2725 AND `type`=1) OR (`entry`=37674 AND `item`=49857 AND `ExtendedCost`=2725 AND `type`=1) OR (`entry`=37674 AND `item`=49858 AND `ExtendedCost`=2725 AND `type`=1) OR (`entry`=37674 AND `item`=49856 AND `ExtendedCost`=2725 AND `type`=1) OR (`entry`=37674 AND `item`=49860 AND `ExtendedCost`=2725 AND `type`=1) OR (`entry`=37674 AND `item`=49861 AND `ExtendedCost`=2725 AND `type`=1) OR (`entry`=37674 AND `item`=49859 AND `ExtendedCost`=2725 AND `type`=1) OR (`entry`=37674 AND `item`=50163 AND `ExtendedCost`=2727 AND `type`=1) OR (`entry`=37674 AND `item`=49927 AND `ExtendedCost`=2730 AND `type`=1);
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=48069 WHERE (`entry`=37674 AND `item`=151615 AND `ExtendedCost`=5791 AND `type`=1); -- Weathered Heirloom Scabbard
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=48069 WHERE (`entry`=37674 AND `item`=122341 AND `ExtendedCost`=5791 AND `type`=1); -- Timeworn Heirloom Scabbard
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=48069 WHERE (`entry`=37674 AND `item`=122339 AND `ExtendedCost`=5790 AND `type`=1); -- Ancient Heirloom Scabbard
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=48069 WHERE (`entry`=37674 AND `item`=72146 AND `ExtendedCost`=3690 AND `type`=1); -- Swift Lovebird

-- Gameobject templates
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=201778; -- Crown Chemical Co. Supplies
UPDATE `gameobject_template_addon` SET `faction`=94 WHERE `entry`=201752; -- Large Crate
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=202169; -- Standing, Large - Val

-- Quests
UPDATE `quest_template_addon` SET `SpecialFlags`=1 WHERE `ID`=44546;
UPDATE `quest_template_addon` SET `PrevQuestID`=24576 WHERE `ID` IN (28935, 44546);

UPDATE `quest_poi` SET `VerifiedBuild`=48069 WHERE (`QuestID`=24636 AND `BlobIndex`=7 AND `Idx1`=7) OR (`QuestID`=24636 AND `BlobIndex`=6 AND `Idx1`=6) OR (`QuestID`=24636 AND `BlobIndex`=5 AND `Idx1`=5) OR (`QuestID`=24636 AND `BlobIndex`=4 AND `Idx1`=4) OR (`QuestID`=24636 AND `BlobIndex`=3 AND `Idx1`=3) OR (`QuestID`=24636 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=24636 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=24636 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=24612 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=24612 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=24536 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=24536 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=24536 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=24576 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=24576 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=24576 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=24851 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=24851 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=24851 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=24851 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=24851 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=24850 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=24850 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=24541 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=24541 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=24541 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=24541 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=44546 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=44546 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=44546 AND `BlobIndex`=2 AND `Idx1`=3) OR (`QuestID`=44546 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=44546 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=44546 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=24635 AND `BlobIndex`=9 AND `Idx1`=17) OR (`QuestID`=24635 AND `BlobIndex`=8 AND `Idx1`=16) OR (`QuestID`=24635 AND `BlobIndex`=7 AND `Idx1`=15) OR (`QuestID`=24635 AND `BlobIndex`=6 AND `Idx1`=14) OR (`QuestID`=24635 AND `BlobIndex`=5 AND `Idx1`=13) OR (`QuestID`=24635 AND `BlobIndex`=4 AND `Idx1`=12) OR (`QuestID`=24635 AND `BlobIndex`=3 AND `Idx1`=11) OR (`QuestID`=24635 AND `BlobIndex`=2 AND `Idx1`=10) OR (`QuestID`=24635 AND `BlobIndex`=1 AND `Idx1`=9) OR (`QuestID`=24635 AND `BlobIndex`=0 AND `Idx1`=8) OR (`QuestID`=24635 AND `BlobIndex`=7 AND `Idx1`=7) OR (`QuestID`=24635 AND `BlobIndex`=6 AND `Idx1`=6) OR (`QuestID`=24635 AND `BlobIndex`=5 AND `Idx1`=5) OR (`QuestID`=24635 AND `BlobIndex`=4 AND `Idx1`=4) OR (`QuestID`=24635 AND `BlobIndex`=3 AND `Idx1`=3) OR (`QuestID`=24635 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=24635 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=24635 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=48069 WHERE (`QuestID`=24636 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=24636 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=24636 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=24636 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=24636 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=24636 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=24636 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=24636 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=24612 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=24612 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=24536 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=24536 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=24536 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=24536 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=24536 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=24536 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=24536 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=24536 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=24536 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=24536 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=24536 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=24536 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=24536 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=24536 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=24576 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=24576 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=24576 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=24851 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=24851 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=24851 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=24851 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=24851 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=24850 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=24850 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=24541 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=24541 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=24541 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=24541 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=44546 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=44546 AND `Idx1`=4 AND `Idx2`=11) OR (`QuestID`=44546 AND `Idx1`=4 AND `Idx2`=10) OR (`QuestID`=44546 AND `Idx1`=4 AND `Idx2`=9) OR (`QuestID`=44546 AND `Idx1`=4 AND `Idx2`=8) OR (`QuestID`=44546 AND `Idx1`=4 AND `Idx2`=7) OR (`QuestID`=44546 AND `Idx1`=4 AND `Idx2`=6) OR (`QuestID`=44546 AND `Idx1`=4 AND `Idx2`=5) OR (`QuestID`=44546 AND `Idx1`=4 AND `Idx2`=4) OR (`QuestID`=44546 AND `Idx1`=4 AND `Idx2`=3) OR (`QuestID`=44546 AND `Idx1`=4 AND `Idx2`=2) OR (`QuestID`=44546 AND `Idx1`=4 AND `Idx2`=1) OR (`QuestID`=44546 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=44546 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=44546 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=44546 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=44546 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=17 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=16 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=15 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=14 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=13 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=12 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=11 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=10 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=9 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=8 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=24635 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID` IN (24636 /*Bonbon Blitz*/, 24612 /*A Gift for the Emissary of Orgrimmar*/, 44546 /*Crushing the Crown*/, 24576 /*A Friendly Chat...*/, 24851 /*Hot On The Trail*/, 24850 /*Snivel's Sweetheart*/, 24541 /*Pilfering Perfume*/, 24635 /*A Cloudlet of Classy Cologne*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(24636, 1, 0, 0, 0, 0, 0, 0, 0, 48069), -- Bonbon Blitz
(24612, 0, 0, 0, 0, 0, 0, 0, 0, 48069), -- A Gift for the Emissary of Orgrimmar
(44546, 1, 5, 0, 0, 0, 0, 0, 0, 48069), -- Crushing the Crown
(24576, 1, 1, 0, 0, 0, 0, 0, 0, 48069), -- A Friendly Chat...
(24851, 1, 1, 0, 0, 0, 0, 0, 0, 48069), -- Hot On The Trail
(24850, 1, 1, 0, 0, 0, 0, 0, 0, 48069), -- Snivel's Sweetheart
(24541, 5, 1, 0, 0, 0, 0, 0, 0, 48069), -- Pilfering Perfume
(24635, 1, 0, 0, 0, 0, 0, 0, 0, 48069); -- A Cloudlet of Classy Cologne

UPDATE `quest_details` SET `VerifiedBuild`=48069 WHERE `ID`=24536;

DELETE FROM `quest_request_items` WHERE `ID`=44546;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(44546, 0, 0, 0, 0, 'Did you teach ''em a lesson?', 48069); -- Crushing the Crown

UPDATE `quest_request_items` SET `VerifiedBuild`=48069 WHERE `ID` IN (24636, 24536);
UPDATE `quest_request_items` SET `VerifiedBuild`=48069 WHERE `ID` IN (24576, 24541);
UPDATE `quest_request_items` SET `CompletionText`='That cologne isn''t going to give itself out, you know.$B$BGet spraying!', `VerifiedBuild`=48069 WHERE `ID`=24635; -- A Cloudlet of Classy Cologne
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `CompletionText`='Did you find him?', `VerifiedBuild`=48069 WHERE `ID`=24851; -- Hot On The Trail

UPDATE `quest_offer_reward` SET `RewardText`='Hey, thanks, kid. Give it over, let''s take a look.\n\n<He takes the device from you and fiddles with it.>\n\nOh, that ain''t good.', `VerifiedBuild`=48069 WHERE `ID`=24536; -- Something Stinks
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Lovely work, $n! People will be tripping over one another to get Crown chocolates now that they''ve had a chance to taste those sweet, romantic treats.$B$BHere''s a little something for helping us out.', `VerifiedBuild`=48069 WHERE `ID`=24636; -- Bonbon Blitz
UPDATE `quest_offer_reward` SET `RewardText`='You got his ledger? Really? That''s great, $n. There''s probably loads of good information in here.', `VerifiedBuild`=48069 WHERE `ID`=24576; -- A Friendly Chat...
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=18, `RewardText`='You''re not Snivel. He was supposed to be here an hour ago! What have you done with him?$B$B<Roka seems to calm down when you tell her that you''re looking for Snivel, too. Then, tears start to well up in her eyes.>$B$BThis isn''t like my sweet Snivel. Do you think something''s happened to him?', `VerifiedBuild`=48069 WHERE `ID`=24850; -- Snivel's Sweetheart
UPDATE `quest_offer_reward` SET `RewardText`='You got it, huh? Good job, kid. Top notch. Let''s see what we got here.\n\n<He cracks open the crate and rummages around inside.>', `VerifiedBuild`=48069 WHERE `ID`=24541; -- Pilfering Perfume
UPDATE `quest_offer_reward` SET `Emote1`=18, `Emote2`=18, `VerifiedBuild`=48069 WHERE `ID`=24851; -- Hot On The Trail
UPDATE `quest_offer_reward` SET `VerifiedBuild`=48069 WHERE `ID`=24635;

DELETE FROM `creature_queststarter` WHERE (`id`=37675 AND `quest`=24636) OR (`id`=38042 AND `quest`=24612) OR (`id`=37172 AND `quest`=24536) OR (`id`=37172 AND `quest` IN (44546,24850,24541)) OR (`id`=38328 AND `quest` IN (24576,24851)) OR (`id`=37675 AND `quest`=24635);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(37675, 24636, 48069), -- Bonbon Blitz offered Public Relations Agent
(38042, 24612, 48069), -- A Gift for the Emissary of Orgrimmar offered Kwee Q. Peddlefeet
(37172, 24536, 48069), -- Something Stinks offered Detective Snap Snagglebolt
(37172, 44546, 48069), -- Crushing the Crown offered Detective Snap Snagglebolt
(38328, 24576, 48069), -- A Friendly Chat... offered Roka
(38328, 24851, 48069), -- Hot On The Trail offered Roka
(37172, 24850, 48069), -- Snivel's Sweetheart offered Detective Snap Snagglebolt
(37172, 24541, 48069), -- Pilfering Perfume offered Detective Snap Snagglebolt
(37675, 24635, 48069); -- A Cloudlet of Classy Cologne offered Public Relations Agent

DELETE FROM `game_event_creature_quest` WHERE `id`=37172 OR (`id`=37675 AND `quest`=24636) OR (`id`=38042 AND `quest`=24612) OR (`id`=38328 AND `quest` IN (24576,24851)) OR (`id`=37675 AND `quest`=24635);

DELETE FROM `creature_questender` WHERE (`id`=37172 AND `quest`=44546);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(37172, 44546, 48069); -- Crushing the Crown ended by Detective Snap Snagglebolt

UPDATE `creature_questender` SET `VerifiedBuild`=48069 WHERE (`id`=37172 AND `quest`=24536) OR (`id`=37675 AND `quest`=24636) OR (`id`=37172 AND `quest` IN (24576,24541)) OR (`id`=38328 AND `quest` IN (24851,24850)) OR (`id`=37675 AND `quest`=24635);

DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (24638, 24645, 24647, 24648, 24649, 24650, 24651, 24652, 28935);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1, 24638, 0, '', '', 'Deprecated quest: Crushing the Crown'),
(1, 24645, 0, '', '', 'Deprecated quest: Crushing the Crown'),
(1, 24647, 0, '', '', 'Deprecated quest: Crushing the Crown'),
(1, 24648, 0, '', '', 'Deprecated quest: Crushing the Crown'),
(1, 24649, 0, '', '', 'Deprecated quest: Crushing the Crown'),
(1, 24650, 0, '', '', 'Deprecated quest: Crushing the Crown'),
(1, 24651, 0, '', '', 'Deprecated quest: Crushing the Crown'),
(1, 24652, 0, '', '', 'Deprecated quest: Crushing the Crown'),
(1, 28935, 0, '', '', 'Deprecated quest: Crushing the Crown');

-- Misc
DELETE FROM `spell_area` WHERE `spell`=71777 AND `area`=1637;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(71777, 1637, 24576, 0, 0, 0, 2, 3, 10, 0);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+17;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Orgrimmar
(@CGUID+0, 37172, 1, 1637, 5170, '0', 0, 0, 0, 0, 1614.2447509765625, -4389.90478515625, 21.01449394226074218, 4.293509960174560546, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Detective Snap Snagglebolt (Area: Valley of Strength - Difficulty: 0) (Auras: )
(@CGUID+1, 37674, 1, 1637, 5170, '0', 0, 0, 0, 0, 1593.56005859375, -4429.0400390625, 15.53543281555175781, 1.675516128540039062, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Lovely Merchant (Area: Valley of Strength - Difficulty: 0) (Auras: )
(@CGUID+2, 37675, 1, 1637, 5170, '0', 0, 0, 0, 0, 1592, -4429.0498046875, 15.59403324127197265, 1.151917338371276855, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Public Relations Agent (Area: Valley of Strength - Difficulty: 0) (Auras: )
(@CGUID+3, 37715, 1, 1637, 5167, '0', 0, 0, 0, 1, 1828.609375, -4404.923828125, 103.7520980834960937, 1.186823844909667968, 120, 0, 0, 118565, 0, 0, 0, 0, 0, 48069), -- Snivel Rustrocket (Area: The Drag - Difficulty: 0) (Auras: 71776 - Snivel Rustrocket Invisibility)
(@CGUID+4, 38042, 1, 1637, 5170, '0', 0, 0, 0, 0, 1595.81005859375, -4428.14990234375, 14.28303337097167968, 1.221730470657348632, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Kwee Q. Peddlefeet (Area: Valley of Strength - Difficulty: 0)
(@CGUID+5, 38288, 1, 1637, 5170, '0', 0, 0, 0, 0, 1573.9200439453125, -4397.10986328125, 16.0081329345703125, 0, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Love Guard Perfume Bunny (Area: Valley of Strength - Difficulty: 0)
(@CGUID+6, 38288, 1, 1637, 5332, '0', 0, 0, 0, 0, 1674.75, -4097.919921875, 45.93563079833984375, 0, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Love Guard Perfume Bunny (Area: Orgrimmar Embassy - Difficulty: 0)
(@CGUID+7, 38288, 1, 1637, 0, '0', 0, 0, 0, 0, 1931.77001953125, -4287.43017578125, 25.67013359069824218, 0, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Love Guard Perfume Bunny (Area: 0 - Difficulty: 0)
(@CGUID+8, 38288, 1, 1637, 5171, '0', 0, 0, 0, 0, 1893.239990234375, -4507.31005859375, 24.94853401184082031, 0, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Love Guard Perfume Bunny (Area: Valley of Wisdom - Difficulty: 0)
(@CGUID+9, 38288, 1, 1637, 5168, '0', 0, 0, 0, 0, 2015.27001953125, -4687.39990234375, 28.61023330688476562, 0, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Love Guard Perfume Bunny (Area: Valley of Honor - Difficulty: 0)
(@CGUID+10, 38328, 1, 1637, 5167, '0', 0, 0, 0, 0, 1781.52001953125, -4508.14013671875, 27.82263374328613281, 3.351032257080078125, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Roka (Area: The Drag - Difficulty: 0)
(@CGUID+11, 38340, 1, 1637, 1637, '0', 0, 0, 0, 0, 1520.43994140625, -4355.08984375, 20.62393379211425781, 3.717551231384277343, 120, 0, 0, 112919, 3155, 0, 0, 0, 0, 48069), -- [DND] Holiday - Love - Bank Bunny (Area: Orgrimmar - Difficulty: 0)
(@CGUID+12, 38341, 1, 1637, 5170, '0', 0, 0, 0, 0, 1635.18994140625, -4442.7900390625, 17.0984344482421875, 1.989675283432006835, 120, 0, 0, 112919, 3155, 0, 0, 0, 0, 48069), -- [DND] Holiday - Love - AH Bunny (Area: Valley of Strength - Difficulty: 0)
(@CGUID+13, 38342, 1, 1637, 5169, '0', 0, 0, 0, 0, 1785.1800537109375, -4206.2099609375, 40.31103134155273437, 0, 120, 0, 0, 112919, 3155, 0, 0, 0, 0, 48069), -- [DND] Holiday - Love - Barber Bunny (Area: Valley of Spirits - Difficulty: 0)
(@CGUID+14, 40438, 1, 1637, 5170, '0', 0, 0, 0, 0, 1571.1510009765625, -4383.47412109375, 16.42013931274414062, 4.677482128143310546, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Steamwheedle Shyster (Area: Valley of Strength - Difficulty: 0) (Auras: )
-- The Dranosh'ar Blockade
(@CGUID+15, 37671, 1, 14, 4982, '0', 0, 0, 0, 1, 1391.407958984375, -4486.05029296875, 31.53259086608886718, 3.211405754089355468, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Orgrimmar - Difficulty: 0)
(@CGUID+16, 37671, 1, 14, 4982, '0', 0, 0, 0, 1, 1394.1978759765625, -4481.76025390625, 31.2533111572265625, 2.199114799499511718, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- Crown Supply Guard (Area: Orgrimmar - Difficulty: 0)
(@CGUID+17, 37671, 1, 14, 4982, '0', 0, 0, 0, 1, 1395, -4490.43017578125, 31.70433425903320312, 4.450589656829833984, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069); -- Crown Supply Guard (Area: Orgrimmar - Difficulty: 0)

UPDATE `creature` SET `phaseUseFlags`=1 WHERE `guid` BETWEEN @CGUID+15 AND @CGUID+17;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+163;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Orgrimmar
(@OGUID+0, 181015, 1, 1637, 1637, '0', 0, 0, 1431.02001953125, -4429.31982421875, 25.30839920043945312, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+1, 181015, 1, 1637, 1637, '0', 0, 0, 1438.06005859375, -4360.259765625, 25.31410026550292968, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+2, 181015, 1, 1637, 1637, '0', 0, 0, 1450.3055419921875, -4429.1162109375, 25.45359230041503906, 2.64692997932434082, 0, 0, 0.969569206237792968, 0.244817420840263366, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+3, 181015, 1, 1637, 1637, '0', 0, 0, 1461.6199951171875, -4412.8701171875, 25.33069992065429687, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+4, 181015, 1, 1637, 1637, '0', 0, 0, 1430.47998046875, -4426.52978515625, 25.3069000244140625, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+5, 181015, 1, 1637, 1637, '0', 0, 0, 1396.6319580078125, -4482.50537109375, 30.87226104736328125, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+6, 181015, 1, 1637, 1637, '0', 0, 0, 1397.5103759765625, -4487.90087890625, 32.46278762817382812, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+7, 181015, 1, 1637, 1637, '0', 0, 0, 1395.001708984375, -4487.11279296875, 31.3753662109375, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+8, 181015, 1, 1637, 1637, '0', 0, 0, 1392.9375, -4485.20166015625, 31.41420555114746093, 0, 0, 0, 0, 1, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+9, 181015, 1, 1637, 5170, '0', 0, 0, 1591.8699951171875, -4432.18994140625, 14.10420036315917968, 4.817109584808349609, 0, 0, -0.66913032531738281, 0.74314504861831665, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+10, 181015, 1, 1637, 5170, '0', 0, 0, 1591.93994140625, -4429.10986328125, 14.32989978790283203, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+11, 181015, 1, 1637, 5170, '0', 0, 0, 1593.1800537109375, -4431.89990234375, 14.10420036315917968, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+12, 181015, 1, 1637, 5170, '0', 0, 0, 1593.52001953125, -4429.080078125, 14.26739978790283203, 5.986480236053466796, 0, 0, -0.14780902862548828, 0.989015936851501464, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+13, 181015, 1, 1637, 5170, '0', 0, 0, 1594.5400390625, -4431.68017578125, 14.1381998062133789, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+14, 181015, 1, 1637, 5170, '0', 0, 0, 1616.9947509765625, -4349.29345703125, 24.72856330871582031, 0.909920096397399902, 0, 0, 0.439426422119140625, 0.898278594017028808, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+15, 181015, 1, 1637, 5169, '0', 0, 0, 1737.4100341796875, -4069.719970703125, 48.42779922485351562, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+16, 181015, 1, 1637, 5169, '0', 0, 0, 1739.489990234375, -4068.919921875, 48.1074981689453125, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+17, 181015, 1, 1637, 5169, '0', 0, 0, 1738.9300537109375, -4070.35009765625, 49.35660171508789062, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+18, 181015, 1, 1637, 5169, '0', 0, 0, 1738.969970703125, -4070.3798828125, 48.10770034790039062, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 48069), -- Standing, Large - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+19, 181016, 1, 1637, 1637, '0', 0, 0, 1543.31005859375, -4363.77978515625, 20.5475006103515625, 4.991643905639648437, 0, 0, -0.60181427001953125, 0.798636078834533691, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+20, 181016, 1, 1637, 1637, '0', 0, 0, 1546.18994140625, -4358.0400390625, 18.04109954833984375, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+21, 181016, 1, 1637, 1637, '0', 0, 0, 1537.75, -4375.93994140625, 17.67499923706054687, 5.061456203460693359, 0, 0, -0.57357597351074218, 0.819152355194091796, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+22, 181016, 1, 1637, 1637, '0', 0, 0, 1563.93994140625, -4429.7900390625, 14.31309986114501953, 1.553341388702392578, 0, 0, 0.700908660888671875, 0.713251054286956787, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+23, 181016, 1, 1637, 5170, '0', 0, 0, 1569.3819580078125, -4382.36962890625, 16.33680534362792968, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+24, 181016, 1, 1637, 5170, '0', 0, 0, 1556.81005859375, -4331.14990234375, 22.68700027465820312, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+25, 181016, 1, 1637, 5170, '0', 0, 0, 1617.3900146484375, -4414.43994140625, 14.88309955596923828, 1.658061861991882324, 0, 0, 0.737277030944824218, 0.67559051513671875, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+26, 181016, 1, 1637, 5170, '0', 0, 0, 1607.72998046875, -4383.830078125, 20.79039955139160156, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+27, 181016, 1, 1637, 5170, '0', 0, 0, 1624.8021240234375, -4341.876953125, 21.11966896057128906, 2.695053339004516601, 0, 0, 0.975178718566894531, 0.221419259905815124, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+28, 181016, 1, 1637, 5170, '0', 0, 0, 1607.923583984375, -4337.27978515625, 21.11966896057128906, 3.268130779266357421, 0, 0, -0.99799919128417968, 0.063226766884326934, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+29, 181016, 1, 1637, 5170, '0', 0, 0, 1593.260009765625, -4310.6201171875, 20.62369918823242187, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+30, 181016, 1, 1637, 5170, '0', 0, 0, 1662.050048828125, -4339.31005859375, 63.58499908447265625, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+31, 181016, 1, 1637, 5170, '0', 0, 0, 1668.0899658203125, -4351.06982421875, 63.58499908447265625, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+32, 181016, 1, 1637, 5170, '0', 0, 0, 1642.969970703125, -4230.47998046875, 52.0428009033203125, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+33, 181016, 1, 1637, 5170, '0', 0, 0, 1707.4200439453125, -4308.009765625, 31.22760009765625, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+34, 181016, 1, 1637, 5170, '0', 0, 0, 1577.092041015625, -4217.59375, 54.19200897216796875, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+35, 181016, 1, 1637, 5170, '0', 0, 0, 1738.0799560546875, -4399.5, 36.53369903564453125, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+36, 181016, 1, 1637, 5170, '0', 0, 0, 1747.0400390625, -4412.490234375, 36.96250152587890625, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+37, 181016, 1, 1637, 5170, '0', 0, 0, 1537.5504150390625, -4206.1337890625, 54.383453369140625, 0.132501229643821716, 0, 0, 0.066202163696289062, 0.997806251049041748, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+38, 181016, 1, 1637, 5170, '0', 0, 0, 1588.361083984375, -4178.126953125, 52.32696533203125, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+39, 181016, 1, 1637, 5170, '0', 0, 0, 1594.1597900390625, -4162.80712890625, 51.74104690551757812, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+40, 181016, 1, 1637, 5170, '0', 0, 0, 1573.921875, -4164.142578125, 53.75942230224609375, 0.047823697328567504, 0, 0, 0.023909568786621093, 0.999714136123657226, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+41, 181016, 1, 1637, 5169, '0', 0, 0, 1727.25, -4065.760009765625, 49.26470184326171875, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+42, 181016, 1, 1637, 0, '0', 0, 0, 1916.9000244140625, -4227.490234375, 37.07920074462890625, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: 0 - Difficulty: 0)
(@OGUID+43, 181016, 1, 1637, 5167, '0', 0, 0, 1904.030029296875, -4673.02001953125, 35.39350128173828125, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 120, 255, 1, 48069), -- Standing, Exterior, Medium - Val (Area: The Drag - Difficulty: 0)
(@OGUID+44, 181017, 1, 1637, 1637, '0', 0, 0, 1568.6600341796875, -4430.39990234375, 22.46669960021972656, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 48069), -- Hanging, Streamer - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+45, 181017, 1, 1637, 5170, '0', 0, 0, 1572.1099853515625, -4429.39990234375, 22.37619972229003906, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 48069), -- Hanging, Streamer - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+46, 181017, 1, 1637, 5170, '0', 0, 0, 1603.8385009765625, -4354.29345703125, 26.67957305908203125, 2.460444450378417968, 0, 0, 0.942563056945800781, 0.334028273820877075, 120, 255, 1, 48069), -- Hanging, Streamer - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+47, 181017, 1, 1637, 0, '0', 0, 0, 1919.7900390625, -4232.330078125, 42.38560104370117187, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 48069), -- Hanging, Streamer - Val (Area: 0 - Difficulty: 0)
(@OGUID+48, 181017, 1, 1637, 5168, '0', 0, 0, 1918.699951171875, -4729.64013671875, 44.61510086059570312, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 120, 255, 1, 48069), -- Hanging, Streamer - Val (Area: Valley of Honor - Difficulty: 0)
(@OGUID+49, 181018, 1, 1637, 1637, '0', 0, 0, 1423.8177490234375, -4428.921875, 29.56694984436035156, 0.168968856334686279, 0, 0, 0.084383964538574218, 0.9964333176612854, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+50, 181018, 1, 1637, 1637, '0', 0, 0, 1442.5103759765625, -4359.3349609375, 29.79220008850097656, 3.351046562194824218, 0, 0, -0.99452114105224609, 0.104535527527332305, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+51, 181018, 1, 1637, 1637, '0', 0, 0, 1422.7742919921875, -4420.73291015625, 29.58182144165039062, 0.238904312252998352, 0, 0, 0.119168281555175781, 0.992874085903167724, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+52, 181018, 1, 1637, 1637, '0', 0, 0, 1443.4427490234375, -4367.59033203125, 29.67009925842285156, 3.231614112854003906, 0, 0, -0.99898719787597656, 0.044995453208684921, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+53, 181018, 1, 1637, 1637, '0', 0, 0, 1537.530029296875, -4371.990234375, 26.2845001220703125, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+54, 181018, 1, 1637, 1637, '0', 0, 0, 1565.719970703125, -4436.2900390625, 19.36989974975585937, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+55, 181018, 1, 1637, 5170, '0', 0, 0, 1577.8900146484375, -4432.9501953125, 19.15780067443847656, 1.413715124130249023, 0, 0, 0.649447441101074218, 0.760406434535980224, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+56, 181018, 1, 1637, 5170, '0', 0, 0, 1665.3499755859375, -4338.89990234375, 69.08350372314453125, 0.471238493919372558, 0, 0, 0.233445167541503906, 0.972369968891143798, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+57, 181018, 1, 1637, 5170, '0', 0, 0, 1670.5400390625, -4347.97021484375, 69.05699920654296875, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+58, 181018, 1, 1637, 5170, '0', 0, 0, 1695.1400146484375, -4271.14990234375, 37.30810165405273437, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+59, 181018, 1, 1637, 5170, '0', 0, 0, 1700.5, -4275.990234375, 37.31660079956054687, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+60, 181018, 1, 1637, 5170, '0', 0, 0, 1663.8199462890625, -4433.52001953125, 24.72699928283691406, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+61, 181018, 1, 1637, 5170, '0', 0, 0, 1670.949951171875, -4423.81982421875, 25.05089950561523437, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+62, 181018, 1, 1637, 5169, '0', 0, 0, 1709.199951171875, -4085.52001953125, 51.69260025024414062, 2.897245407104492187, 0, 0, 0.99254608154296875, 0.121869951486587524, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+63, 181018, 1, 1637, 5169, '0', 0, 0, 1729.1800537109375, -4080.590087890625, 56.01599884033203125, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+64, 181018, 1, 1637, 5169, '0', 0, 0, 1740.31005859375, -4076.7099609375, 55.63199996948242187, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+65, 181018, 1, 1637, 5169, '0', 0, 0, 1747.469970703125, -4198.3798828125, 54.29600143432617187, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+66, 181018, 1, 1637, 0, '0', 0, 0, 1860.77001953125, -4291.64013671875, 31.61899948120117187, 0.052358884364366531, 0, 0, 0.02617645263671875, 0.999657332897186279, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: 0 - Difficulty: 0)
(@OGUID+67, 181018, 1, 1637, 0, '0', 0, 0, 1886.199951171875, -4281.509765625, 28.75539970397949218, 4.066620349884033203, 0, 0, -0.89493370056152343, 0.44619917869567871, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: 0 - Difficulty: 0)
(@OGUID+68, 181018, 1, 1637, 0, '0', 0, 0, 1914.27001953125, -4188.22021484375, 40.4468994140625, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: 0 - Difficulty: 0)
(@OGUID+69, 181018, 1, 1637, 0, '0', 0, 0, 1932.4100341796875, -4182.22021484375, 40.4954986572265625, 5.637413978576660156, 0, 0, -0.31730461120605468, 0.948323667049407958, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: 0 - Difficulty: 0)
(@OGUID+70, 181018, 1, 1637, 0, '0', 0, 0, 1952.469970703125, -4204.52978515625, 38.86209869384765625, 3.420850038528442382, 0, 0, -0.99026775360107421, 0.139175355434417724, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: 0 - Difficulty: 0)
(@OGUID+71, 181018, 1, 1637, 5171, '0', 0, 0, 1904.1099853515625, -4364.18017578125, 46.06280136108398437, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+72, 181018, 1, 1637, 5171, '0', 0, 0, 1896.68994140625, -4365.68994140625, 46.20119857788085937, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+73, 181018, 1, 1637, 5171, '0', 0, 0, 1907.4000244140625, -4380.60986328125, 46.34769821166992187, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+74, 181018, 1, 1637, 5171, '0', 0, 0, 1900.0400390625, -4382.08984375, 46.42800140380859375, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+75, 181018, 1, 1637, 5167, '0', 0, 0, 1888.52001953125, -4600.31005859375, 41.44359970092773437, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: The Drag - Difficulty: 0)
(@OGUID+76, 181018, 1, 1637, 5167, '0', 0, 0, 1934.8800048828125, -4594.58984375, 41.61320114135742187, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: The Drag - Difficulty: 0)
(@OGUID+77, 181018, 1, 1637, 5167, '0', 0, 0, 1900.760009765625, -4678.77978515625, 39.08229827880859375, 5.585053920745849609, 0, 0, -0.34202003479003906, 0.939692676067352294, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: The Drag - Difficulty: 0)
(@OGUID+78, 181018, 1, 1637, 5168, '0', 0, 0, 1999.1700439453125, -4668.81005859375, 30.54710006713867187, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Honor - Difficulty: 0)
(@OGUID+79, 181018, 1, 1637, 5168, '0', 0, 0, 2038.800048828125, -4681.9501953125, 35.07889938354492187, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Honor - Difficulty: 0)
(@OGUID+80, 181018, 1, 1637, 5168, '0', 0, 0, 2034.510009765625, -4670.43994140625, 34.97359848022460937, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Honor - Difficulty: 0)
(@OGUID+81, 181018, 1, 1637, 5168, '0', 0, 0, 2070.340087890625, -4804.7099609375, 31.90710067749023437, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Honor - Difficulty: 0)
(@OGUID+82, 181018, 1, 1637, 5168, '0', 0, 0, 2078.75, -4800.27978515625, 31.87400054931640625, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 120, 255, 1, 48069), -- Hanging, Tall/Thin, Medium - Val (Area: Valley of Honor - Difficulty: 0)
(@OGUID+83, 181020, 1, 1637, 5170, '0', 0, 0, 1611.719970703125, -4426.97021484375, 18.53499984741210937, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 120, 255, 1, 48069), -- Hanging, Square, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+84, 181020, 1, 1637, 5170, '0', 0, 0, 1619.52001953125, -4419.08984375, 18.13489913940429687, 3.019413232803344726, 0, 0, 0.998134613037109375, 0.061051756143569946, 120, 255, 1, 48069), -- Hanging, Square, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+85, 181020, 1, 1637, 5170, '0', 0, 0, 1600.8021240234375, -4357.77783203125, 23.33384323120117187, 2.568755865097045898, 0, 0, 0.959261894226074218, 0.282518386840820312, 120, 255, 1, 48069), -- Hanging, Square, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+86, 181020, 1, 1637, 5170, '0', 0, 0, 1606.310791015625, -4351.125, 23.33384323120117187, 2.709914922714233398, 0, 0, 0.976797103881835937, 0.21416686475276947, 120, 255, 1, 48069), -- Hanging, Square, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+87, 181020, 1, 1637, 5170, '0', 0, 0, 1583.8199462890625, -4223.68994140625, 57.40999984741210937, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 48069), -- Hanging, Square, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+88, 181020, 1, 1637, 5170, '0', 0, 0, 1600.010009765625, -4210.419921875, 57.44120025634765625, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 48069), -- Hanging, Square, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+89, 181020, 1, 1637, 5170, '0', 0, 0, 1753.6600341796875, -4387.60009765625, 44.42029953002929687, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 48069), -- Hanging, Square, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+90, 181020, 1, 1637, 5170, '0', 0, 0, 1747.4599609375, -4391.85986328125, 44.42950057983398437, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 48069), -- Hanging, Square, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+91, 181020, 1, 1637, 5170, '0', 0, 0, 1756.81005859375, -4405.8701171875, 44.31529998779296875, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 120, 255, 1, 48069), -- Hanging, Square, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+92, 181020, 1, 1637, 5170, '0', 0, 0, 1763.0799560546875, -4401.580078125, 44.29320144653320312, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 48069), -- Hanging, Square, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+93, 181020, 1, 1637, 0, '0', 0, 0, 1917.9000244140625, -4231.1298828125, 39.3524017333984375, 1.186823248863220214, 0, 0, 0.559192657470703125, 0.829037725925445556, 120, 255, 1, 48069), -- Hanging, Square, Medium - Val (Area: 0 - Difficulty: 0)
(@OGUID+94, 181020, 1, 1637, 5167, '0', 0, 0, 1900.3199462890625, -4687.97998046875, 39.13949966430664062, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 120, 255, 1, 48069), -- Hanging, Square, Medium - Val (Area: The Drag - Difficulty: 0)
(@OGUID+95, 181021, 1, 1637, 1637, '0', 0, 0, 1383.579833984375, -4369.72900390625, 53.08074188232421875, 3.281238555908203125, 0, 0, -0.99756336212158203, 0.069766148924827575, 120, 255, 1, 48069), -- Hanging, Door - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+96, 181021, 1, 1637, 1637, '0', 0, 0, 1485.3021240234375, -4417.88720703125, 56.03487014770507812, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 48069), -- Hanging, Door - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+97, 181021, 1, 1637, 5170, '0', 0, 0, 1601.6700439453125, -4368.97998046875, 34.77560043334960937, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 48069), -- Hanging, Door - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+98, 181021, 1, 1637, 5170, '0', 0, 0, 1609.6700439453125, -4384.16015625, 34.65570068359375, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 120, 255, 1, 48069), -- Hanging, Door - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+99, 181021, 1, 1637, 5170, '0', 0, 0, 1587.8199462890625, -4212.85009765625, 103.4339981079101562, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 48069), -- Hanging, Door - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+100, 181021, 1, 1637, 5169, '0', 0, 0, 1706.56005859375, -3929.85009765625, 72.10649871826171875, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, 48069), -- Hanging, Door - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+101, 181022, 1, 1637, 5167, '0', 0, 0, 1869.699951171875, -4520.35986328125, 24.58790016174316406, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 120, 255, 1, 48069), -- Standing, Giant - Val (Area: The Drag - Difficulty: 0)
(@OGUID+102, 181027, 1, 1637, 5170, '0', 0, 0, 1610.189208984375, -4131.19091796875, 47.70912551879882812, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+103, 181027, 1, 1637, 5332, '0', 0, 0, 1633.7899169921875, -4116.98974609375, 47.67217636108398437, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: Orgrimmar Embassy - Difficulty: 0)
(@OGUID+104, 181027, 1, 1637, 5332, '0', 0, 0, 1637.27783203125, -4092.244873046875, 47.67217636108398437, 1.047197580337524414, 0, 0, 0.5, 0.866025388240814208, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: Orgrimmar Embassy - Difficulty: 0)
(@OGUID+105, 181027, 1, 1637, 5332, '0', 0, 0, 1608.232666015625, -4100.73291015625, 47.67217636108398437, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: Orgrimmar Embassy - Difficulty: 0)
(@OGUID+106, 181027, 1, 1637, 5332, '0', 0, 0, 1666.84033203125, -4093.100830078125, 47.67217636108398437, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: Orgrimmar Embassy - Difficulty: 0)
(@OGUID+107, 181027, 1, 1637, 5169, '0', 0, 0, 1681.3004150390625, -4085.59033203125, 47.70714569091796875, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+108, 181027, 1, 1637, 0, '0', 0, 0, 1945.06005859375, -4292.58984375, 22.27196502685546875, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: 0 - Difficulty: 0)
(@OGUID+109, 181027, 1, 1637, 0, '0', 0, 0, 1956.3199462890625, -4266.85009765625, 22.27196502685546875, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: 0 - Difficulty: 0)
(@OGUID+110, 181027, 1, 1637, 0, '0', 0, 0, 1918.6700439453125, -4331.8798828125, 22.27196502685546875, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: 0 - Difficulty: 0)
(@OGUID+111, 181027, 1, 1637, 0, '0', 0, 0, 1946.449951171875, -4277.8798828125, 22.27196502685546875, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: 0 - Difficulty: 0)
(@OGUID+112, 181027, 1, 1637, 0, '0', 0, 0, 1916.760009765625, -4318.31982421875, 22.27196502685546875, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: 0 - Difficulty: 0)
(@OGUID+113, 181027, 1, 1637, 0, '0', 0, 0, 1905.4200439453125, -4329.75, 22.27196502685546875, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: 0 - Difficulty: 0)
(@OGUID+114, 181027, 1, 1637, 5171, '0', 0, 0, 1937.6500244140625, -4322.25, 22.27196502685546875, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+115, 181027, 1, 1637, 5171, '0', 0, 0, 1953.1400146484375, -4326.83984375, 22.27196502685546875, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+116, 181027, 1, 1637, 5171, '0', 0, 0, 1964.3199462890625, -4283.77978515625, 22.27196502685546875, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: Valley of Wisdom - Difficulty: 0)
(@OGUID+117, 181027, 1, 1637, 5167, '0', 0, 0, 1987.5899658203125, -4625.14990234375, 26.74469757080078125, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: The Drag - Difficulty: 0)
(@OGUID+118, 181027, 1, 1637, 5167, '0', 0, 0, 1961.1400146484375, -4645.22021484375, 26.74469757080078125, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: The Drag - Difficulty: 0)
(@OGUID+119, 181027, 1, 1637, 5167, '0', 0, 0, 1979.739990234375, -4649.8701171875, 26.74469757080078125, 1.186823248863220214, 0, 0, 0.559192657470703125, 0.829037725925445556, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: The Drag - Difficulty: 0)
(@OGUID+120, 181027, 1, 1637, 5168, '0', 0, 0, 1993, -4673.7998046875, 26.74469757080078125, 2.321286916732788085, 0, 0, 0.917059898376464843, 0.398749500513076782, 120, 255, 1, 48069), -- Floating, Medium - Val (Area: Valley of Honor - Difficulty: 0)
(@OGUID+121, 181055, 1, 1637, 5170, '0', 0, 0, 1616.550048828125, -4423.97998046875, 27.18330001831054687, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 48069), -- Hanging, Streamer x3 - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+122, 181055, 1, 1637, 5170, '0', 0, 0, 1586.5999755859375, -4311.75, 28.184600830078125, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 120, 255, 1, 48069), -- Hanging, Streamer x3 - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+123, 181055, 1, 1637, 5170, '0', 0, 0, 1667.9300537109375, -4343.41015625, 73.01419830322265625, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 48069), -- Hanging, Streamer x3 - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+124, 181055, 1, 1637, 5170, '0', 0, 0, 1799.31005859375, -4370.669921875, 107.9680023193359375, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 48069), -- Hanging, Streamer x3 - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+125, 181055, 1, 1637, 5332, '0', 0, 0, 1640.0699462890625, -4121.75, 67.02790069580078125, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 120, 255, 1, 48069), -- Hanging, Streamer x3 - Val (Area: Orgrimmar Embassy - Difficulty: 0)
(@OGUID+126, 181055, 1, 1637, 5169, '0', 0, 0, 1734.68994140625, -4078.679931640625, 58.73630142211914062, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 48069), -- Hanging, Streamer x3 - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+127, 181055, 1, 1637, 0, '0', 0, 0, 1951.3900146484375, -4199.58984375, 41.89910125732421875, 3.45575571060180664, 0, 0, -0.98768806457519531, 0.156436234712600708, 120, 255, 1, 48069), -- Hanging, Streamer x3 - Val (Area: 0 - Difficulty: 0)
(@OGUID+128, 181055, 1, 1637, 5168, '0', 0, 0, 2037.280029296875, -4676.0498046875, 42.38940048217773437, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 48069), -- Hanging, Streamer x3 - Val (Area: Valley of Honor - Difficulty: 0)
(@OGUID+129, 181055, 1, 1637, 5168, '0', 0, 0, 2073.52001953125, -4766.5, 33.80910110473632812, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 48069), -- Hanging, Streamer x3 - Val (Area: Valley of Honor - Difficulty: 0)
(@OGUID+130, 181060, 1, 1637, 1637, '0', 0, 0, 1514.97998046875, -4347.080078125, 21.87989997863769531, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+131, 181060, 1, 1637, 1637, '0', 0, 0, 1511, -4353.7099609375, 21.87989997863769531, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+132, 181060, 1, 1637, 1637, '0', 0, 0, 1519.72998046875, -4346.31005859375, 21.89909934997558593, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Orgrimmar - Difficulty: 0)
(@OGUID+133, 181060, 1, 1637, 5170, '0', 0, 0, 1577.530029296875, -4464.759765625, 17.26910018920898437, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+134, 181060, 1, 1637, 5170, '0', 0, 0, 1580.0999755859375, -4464.06005859375, 17.23870086669921875, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+135, 181060, 1, 1637, 5170, '0', 0, 0, 1576.56005859375, -4462.5400390625, 23.16650009155273437, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+136, 181060, 1, 1637, 5170, '0', 0, 0, 1582.6800537109375, -4460.990234375, 23.16650009155273437, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+137, 181060, 1, 1637, 5170, '0', 0, 0, 1583.2900390625, -4463.080078125, 17.24099922180175781, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+138, 181060, 1, 1637, 5170, '0', 0, 0, 1606.98095703125, -4359.05029296875, 24.15967750549316406, 2.459839344024658203, 0, 0, 0.942461967468261718, 0.334313392639160156, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+139, 181060, 1, 1637, 5170, '0', 0, 0, 1608.782958984375, -4356.7568359375, 24.159698486328125, 2.459839344024658203, 0, 0, 0.942461967468261718, 0.334313392639160156, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+140, 181060, 1, 1637, 5170, '0', 0, 0, 1617.986083984375, -4348.05908203125, 24.11872482299804687, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+141, 181060, 1, 1637, 5170, '0', 0, 0, 1639.2239990234375, -4444.65283203125, 18.51654434204101562, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+142, 181060, 1, 1637, 5170, '0', 0, 0, 1613.046875, -4349.74462890625, 24.08938026428222656, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+143, 181060, 1, 1637, 5170, '0', 0, 0, 1635.7135009765625, -4448.33837890625, 18.51782989501953125, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+144, 181060, 1, 1637, 5170, '0', 0, 0, 1642.949951171875, -4446.10009765625, 26.27840042114257812, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Strength - Difficulty: 0)
(@OGUID+145, 181060, 1, 1637, 5169, '0', 0, 0, 1728.760009765625, -4081.260009765625, 71.351898193359375, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+146, 181060, 1, 1637, 5169, '0', 0, 0, 1730, -4078.510009765625, 71.4373016357421875, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+147, 181060, 1, 1637, 5169, '0', 0, 0, 1742.6099853515625, -4084.449951171875, 69.10540008544921875, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+148, 181060, 1, 1637, 5169, '0', 0, 0, 1741.1400146484375, -4080.510009765625, 69.105499267578125, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 48069), -- Standing, Interior, Small - Val (Area: Valley of Spirits - Difficulty: 0)
(@OGUID+149, 202169, 1, 1637, 5167, '0', 0, 0, 1830.1632080078125, -4406.53125, 104.9327011108398437, 0, 0, 0, 0, 1, 120, 255, 1, 48069), -- Standing, Large - Val (Area: The Drag - Difficulty: 0)
(@OGUID+150, 202169, 1, 1637, 5167, '0', 0, 0, 1830.0972900390625, -4406.62158203125, 103.6575164794921875, 0.959929943084716796, 0, 0, 0.461748123168945312, 0.887011110782623291, 120, 255, 1, 48069), -- Standing, Large - Val (Area: The Drag - Difficulty: 0)
(@OGUID+151, 202169, 1, 1637, 5167, '0', 0, 0, 1827.732666015625, -4406.57470703125, 103.6764984130859375, 0.959929943084716796, 0, 0, 0.461748123168945312, 0.887011110782623291, 120, 255, 1, 48069), -- Standing, Large - Val (Area: The Drag - Difficulty: 0)
(@OGUID+152, 201940, 1, 1637, 5170, '0', 0, 0, 1593.199951171875, -4431.35009765625, 14.15279960632324218, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, 48069), -- Valentine Arch (x2.00) (Area: Valley of Strength - Difficulty: 0)
-- The Dranosh'ar Blockade
(@OGUID+153, 201752, 1, 14, 4982, '0', 0, 0, 1396.4757080078125, -4482.71533203125, 32.14787673950195312, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 48069), -- Large Crate (Area: Orgrimmar - Difficulty: 0)
(@OGUID+154, 201752, 1, 14, 4982, '0', 0, 0, 1394.4010009765625, -4485.6875, 31.35416030883789062, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 48069), -- Large Crate (Area: Orgrimmar - Difficulty: 0)
(@OGUID+155, 201752, 1, 14, 4982, '0', 0, 0, 1396.595458984375, -4486.0556640625, 31.15484046936035156, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 48069), -- Large Crate (Area: Orgrimmar - Difficulty: 0)
(@OGUID+156, 201752, 1, 14, 4982, '0', 0, 0, 1393.3194580078125, -4486.796875, 31.42902565002441406, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 48069), -- Large Crate (Area: Orgrimmar - Difficulty: 0)
(@OGUID+157, 201752, 1, 14, 4982, '0', 0, 0, 1397.5711669921875, -4487.939453125, 31.21067047119140625, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 48069), -- Large Crate (Area: Orgrimmar - Difficulty: 0)
(@OGUID+158, 201752, 1, 14, 4982, '0', 0, 0, 1395.8125, -4486.439453125, 32.56021499633789062, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, 48069), -- Large Crate (Area: Orgrimmar - Difficulty: 0)
(@OGUID+159, 201752, 1, 14, 4982, '0', 0, 0, 1394.18408203125, -4484.10791015625, 31.24832916259765625, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 48069), -- Large Crate (Area: Orgrimmar - Difficulty: 0)
(@OGUID+160, 201752, 1, 14, 4982, '0', 0, 0, 1397.376708984375, -4488.02099609375, 33.71861648559570312, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 120, 255, 1, 48069), -- Large Crate (Area: Orgrimmar - Difficulty: 0)
(@OGUID+161, 201752, 1, 14, 4982, '0', 0, 0, 1394.0416259765625, -4488.3974609375, 31.47749519348144531, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 48069), -- Large Crate (Area: Orgrimmar - Difficulty: 0)
(@OGUID+162, 201778, 1, 14, 4982, '0', 0, 0, 1393.6771240234375, -4486.033203125, 32.672271728515625, 0, 0, 0, 0, 1, 120, 255, 1, 48069), -- Crown Chemical Co. Supplies (Area: Orgrimmar - Difficulty: 0)
(@OGUID+163, 201778, 1, 14, 4982, '0', 0, 0, 1394.2603759765625, -4484.3681640625, 32.50795745849609375, 5.148722648620605468, 0, 0, -0.53729915618896484, 0.843391716480255126, 120, 255, 1, 48069); -- Crown Chemical Co. Supplies (Area: Orgrimmar - Difficulty: 0)

UPDATE `gameobject` SET `phaseUseFlags`=1 WHERE `guid` BETWEEN @OGUID+153 AND @OGUID+163;

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+149 AND @OGUID+151;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `invisibilityType`, `invisibilityValue`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+149, 0, 0, 0, 1, 9, 1001, 0, 0),
(@OGUID+150, 0, 0, 0, 1, 9, 1001, 0, 0),
(@OGUID+151, 0, 0, 0, 1, 9, 1001, 0, 0);

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+17;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1),
(@EVENT, @CGUID+2),
(@EVENT, @CGUID+3),
(@EVENT, @CGUID+4),
(@EVENT, @CGUID+5),
(@EVENT, @CGUID+6),
(@EVENT, @CGUID+7),
(@EVENT, @CGUID+8),
(@EVENT, @CGUID+9),
(@EVENT, @CGUID+10),
(@EVENT, @CGUID+11),
(@EVENT, @CGUID+12),
(@EVENT, @CGUID+13),
(@EVENT, @CGUID+14),
(@EVENT, @CGUID+15),
(@EVENT, @CGUID+16),
(@EVENT, @CGUID+17);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+163;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+0),
(@EVENT, @OGUID+1),
(@EVENT, @OGUID+2),
(@EVENT, @OGUID+3),
(@EVENT, @OGUID+4),
(@EVENT, @OGUID+5),
(@EVENT, @OGUID+6),
(@EVENT, @OGUID+7),
(@EVENT, @OGUID+8),
(@EVENT, @OGUID+9),
(@EVENT, @OGUID+10),
(@EVENT, @OGUID+11),
(@EVENT, @OGUID+12),
(@EVENT, @OGUID+13),
(@EVENT, @OGUID+14),
(@EVENT, @OGUID+15),
(@EVENT, @OGUID+16),
(@EVENT, @OGUID+17),
(@EVENT, @OGUID+18),
(@EVENT, @OGUID+19),
(@EVENT, @OGUID+20),
(@EVENT, @OGUID+21),
(@EVENT, @OGUID+22),
(@EVENT, @OGUID+23),
(@EVENT, @OGUID+24),
(@EVENT, @OGUID+25),
(@EVENT, @OGUID+26),
(@EVENT, @OGUID+27),
(@EVENT, @OGUID+28),
(@EVENT, @OGUID+29),
(@EVENT, @OGUID+30),
(@EVENT, @OGUID+31),
(@EVENT, @OGUID+32),
(@EVENT, @OGUID+33),
(@EVENT, @OGUID+34),
(@EVENT, @OGUID+35),
(@EVENT, @OGUID+36),
(@EVENT, @OGUID+37),
(@EVENT, @OGUID+38),
(@EVENT, @OGUID+39),
(@EVENT, @OGUID+40),
(@EVENT, @OGUID+41),
(@EVENT, @OGUID+42),
(@EVENT, @OGUID+43),
(@EVENT, @OGUID+44),
(@EVENT, @OGUID+45),
(@EVENT, @OGUID+46),
(@EVENT, @OGUID+47),
(@EVENT, @OGUID+48),
(@EVENT, @OGUID+49),
(@EVENT, @OGUID+50),
(@EVENT, @OGUID+51),
(@EVENT, @OGUID+52),
(@EVENT, @OGUID+53),
(@EVENT, @OGUID+54),
(@EVENT, @OGUID+55),
(@EVENT, @OGUID+56),
(@EVENT, @OGUID+57),
(@EVENT, @OGUID+58),
(@EVENT, @OGUID+59),
(@EVENT, @OGUID+60),
(@EVENT, @OGUID+61),
(@EVENT, @OGUID+62),
(@EVENT, @OGUID+63),
(@EVENT, @OGUID+64),
(@EVENT, @OGUID+65),
(@EVENT, @OGUID+66),
(@EVENT, @OGUID+67),
(@EVENT, @OGUID+68),
(@EVENT, @OGUID+69),
(@EVENT, @OGUID+70),
(@EVENT, @OGUID+71),
(@EVENT, @OGUID+72),
(@EVENT, @OGUID+73),
(@EVENT, @OGUID+74),
(@EVENT, @OGUID+75),
(@EVENT, @OGUID+76),
(@EVENT, @OGUID+77),
(@EVENT, @OGUID+78),
(@EVENT, @OGUID+79),
(@EVENT, @OGUID+80),
(@EVENT, @OGUID+81),
(@EVENT, @OGUID+82),
(@EVENT, @OGUID+83),
(@EVENT, @OGUID+84),
(@EVENT, @OGUID+85),
(@EVENT, @OGUID+86),
(@EVENT, @OGUID+87),
(@EVENT, @OGUID+88),
(@EVENT, @OGUID+89),
(@EVENT, @OGUID+90),
(@EVENT, @OGUID+91),
(@EVENT, @OGUID+92),
(@EVENT, @OGUID+93),
(@EVENT, @OGUID+94),
(@EVENT, @OGUID+95),
(@EVENT, @OGUID+96),
(@EVENT, @OGUID+97),
(@EVENT, @OGUID+98),
(@EVENT, @OGUID+99),
(@EVENT, @OGUID+100),
(@EVENT, @OGUID+101),
(@EVENT, @OGUID+102),
(@EVENT, @OGUID+103),
(@EVENT, @OGUID+104),
(@EVENT, @OGUID+105),
(@EVENT, @OGUID+106),
(@EVENT, @OGUID+107),
(@EVENT, @OGUID+108),
(@EVENT, @OGUID+109),
(@EVENT, @OGUID+110),
(@EVENT, @OGUID+111),
(@EVENT, @OGUID+112),
(@EVENT, @OGUID+113),
(@EVENT, @OGUID+114),
(@EVENT, @OGUID+115),
(@EVENT, @OGUID+116),
(@EVENT, @OGUID+117),
(@EVENT, @OGUID+118),
(@EVENT, @OGUID+119),
(@EVENT, @OGUID+120),
(@EVENT, @OGUID+121),
(@EVENT, @OGUID+122),
(@EVENT, @OGUID+123),
(@EVENT, @OGUID+124),
(@EVENT, @OGUID+125),
(@EVENT, @OGUID+126),
(@EVENT, @OGUID+127),
(@EVENT, @OGUID+128),
(@EVENT, @OGUID+129),
(@EVENT, @OGUID+130),
(@EVENT, @OGUID+131),
(@EVENT, @OGUID+132),
(@EVENT, @OGUID+133),
(@EVENT, @OGUID+134),
(@EVENT, @OGUID+135),
(@EVENT, @OGUID+136),
(@EVENT, @OGUID+137),
(@EVENT, @OGUID+138),
(@EVENT, @OGUID+139),
(@EVENT, @OGUID+140),
(@EVENT, @OGUID+141),
(@EVENT, @OGUID+142),
(@EVENT, @OGUID+143),
(@EVENT, @OGUID+144),
(@EVENT, @OGUID+145),
(@EVENT, @OGUID+146),
(@EVENT, @OGUID+147),
(@EVENT, @OGUID+148),
(@EVENT, @OGUID+149),
(@EVENT, @OGUID+150),
(@EVENT, @OGUID+151),
(@EVENT, @OGUID+152),
(@EVENT, @OGUID+153),
(@EVENT, @OGUID+154),
(@EVENT, @OGUID+155),
(@EVENT, @OGUID+156),
(@EVENT, @OGUID+157),
(@EVENT, @OGUID+158),
(@EVENT, @OGUID+159),
(@EVENT, @OGUID+160),
(@EVENT, @OGUID+161),
(@EVENT, @OGUID+162),
(@EVENT, @OGUID+163);
