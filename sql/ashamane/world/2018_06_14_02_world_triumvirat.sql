SET @CGUID := 210118300;
SET @OGUID := 51013500;

DELETE FROM `instance_template` WHERE `map` = 1753;
INSERT INTO `instance_template` VALUES
(1753, 1669, "instance_seat_of_triumvirate", 1, 1);

DELETE FROM `areatrigger_template` WHERE `Id` IN (15562, 15446, 15626, 15830, 15477, 16038, 16217, 16383, 15505);
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(15562, 0, 6, 6, 6, 0, 0, 0, 0, 26654),
(15446, 0, 2, 2, 2, 0, 0, 0, 0, 26654),
(15626, 0, 4, 3, 3, 0, 0, 0, 0, 26654),
(15830, 0, 4, 50, 50, 0, 0, 0, 0, 26654),
(15477, 0, 0, 2, 2, 0, 0, 0, 0, 26654),
(16038, 0, 6, 3, 3, 0, 0, 0, 0, 26654),
(16217, 0, 6, 4, 4, 0, 0, 0, 0, 26654),
(16383, 0, 4, 10, 10, 0, 0, 0, 0, 26654),
(15505, 3, 6, 0, 0, 0, 0, 0, 0, 26654);

UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9645;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9645;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=5972;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9645;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=5972;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9645;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=5972;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9645;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9645;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9645;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9645;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9645;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=5972;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=5972;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=5972;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=26654 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26654 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26654 WHERE `Id`=9225;

DELETE FROM `areatrigger_template_polygon_vertices` WHERE (`AreaTriggerId`=15505 AND `Idx`=31) OR (`AreaTriggerId`=15505 AND `Idx`=30) OR (`AreaTriggerId`=15505 AND `Idx`=29) OR (`AreaTriggerId`=15505 AND `Idx`=28) OR (`AreaTriggerId`=15505 AND `Idx`=27) OR (`AreaTriggerId`=15505 AND `Idx`=26) OR (`AreaTriggerId`=15505 AND `Idx`=25) OR (`AreaTriggerId`=15505 AND `Idx`=24) OR (`AreaTriggerId`=15505 AND `Idx`=23) OR (`AreaTriggerId`=15505 AND `Idx`=22) OR (`AreaTriggerId`=15505 AND `Idx`=21) OR (`AreaTriggerId`=15505 AND `Idx`=20) OR (`AreaTriggerId`=15505 AND `Idx`=19) OR (`AreaTriggerId`=15505 AND `Idx`=18) OR (`AreaTriggerId`=15505 AND `Idx`=17) OR (`AreaTriggerId`=15505 AND `Idx`=16) OR (`AreaTriggerId`=15505 AND `Idx`=15) OR (`AreaTriggerId`=15505 AND `Idx`=14) OR (`AreaTriggerId`=15505 AND `Idx`=13) OR (`AreaTriggerId`=15505 AND `Idx`=12) OR (`AreaTriggerId`=15505 AND `Idx`=11) OR (`AreaTriggerId`=15505 AND `Idx`=10) OR (`AreaTriggerId`=15505 AND `Idx`=9) OR (`AreaTriggerId`=15505 AND `Idx`=8) OR (`AreaTriggerId`=15505 AND `Idx`=7) OR (`AreaTriggerId`=15505 AND `Idx`=6) OR (`AreaTriggerId`=15505 AND `Idx`=5) OR (`AreaTriggerId`=15505 AND `Idx`=4) OR (`AreaTriggerId`=15505 AND `Idx`=3) OR (`AreaTriggerId`=15505 AND `Idx`=2) OR (`AreaTriggerId`=15505 AND `Idx`=1) OR (`AreaTriggerId`=15505 AND `Idx`=0);
INSERT INTO `areatrigger_template_polygon_vertices` (`AreaTriggerId`, `Idx`, `VerticeX`, `VerticeY`, `VerticeTargetX`, `VerticeTargetY`, `VerifiedBuild`) VALUES
(15505, 31, 8.480957, 71.59863, 7.612793, 71.95703, 26654),
(15505, 30, 33.80127, 58.38965, 34.16455, 58.57715, 26654),
(15505, 29, 48.42529, 41.96582, 48.28125, 42.30762, 26654),
(15505, 28, 69.68506, 4.170898, 69.29688, 4.211914, 26654),
(15505, 27, 63.54053, -27.59668, 64.7915, -27.76367, 26654),
(15505, 26, 53.15771, -47.50293, 53.22803, -47.54883, 26654),
(15505, 25, 37.63965, -60.01855, 37.65771, -59.67676, 26654),
(15505, 24, 20.45068, -66.41504, 20.44434, -66.18848, 26654),
(15505, 23, 5.230957, -70.28027, 5.189941, -69.57227, 26654),
(15505, 22, -21.83057, -63.57617, -21.60596, -62.61523, 26654),
(15505, 21, -64.29883, -23.64063, -63.13574, -23.47559, 26654),
(15505, 20, -70.354, -2.958984, -70.17969, -4.193359, 26654),
(15505, 19, -65.14258, 26.64453, -62.75537, 23.79004, 26654),
(15505, 18, -51.22754, 47.43164, -51.125, 47.0332, 26654),
(15505, 17, -39.375, 36.00586, -25.41602, 22.98828, 26654),
(15505, 16, -56.80371, 22.9541, -32.79639, 10.59766, 26654),
(15505, 15, -56.3584, -2.505859, -32.78418, -2.59668, 26654),
(15505, 14, -51.68848, -18.98242, -30.0957, -11.96484, 26654),
(15505, 13, -17.13184, -50.66211, -10.52734, -30.61035, 26654),
(15505, 12, 3.826172, -54.94824, 0.8652344, -29.43066, 26654),
(15505, 11, 16.88281, -54.41797, 8.919922, -28.24414, 26654),
(15505, 10, 30.20996, -47.2041, 17.24707, -23.96289, 26654),
(15505, 9, 41.61719, -37.52051, 22.32275, -20.80762, 26654),
(15505, 8, 54.13281, -23.4668, 26.75342, -13.4668, 26654),
(15505, 7, 56.67627, 3.099609, 29.65625, -1.254883, 26654),
(15505, 6, 37.4043, 32.59473, 23.95313, 16.91699, 26654),
(15505, 5, 26.61182, 45.60156, 14.45459, 26.6123, 26654),
(15505, 4, 6.568359, 55.58887, 2.950195, 32.61816, 26654),
(15505, 3, -15.26904, 51.65918, -10.31543, 31.79492, 26654),
(15505, 2, -39.21631, 36.13965, -25.37695, 23.04688, 26654),
(15505, 1, -50.95508, 47.43848, -50.89795, 47.03027, 26654),
(15505, 0, -20.88135, 70.44336, -21.47314, 70.13379, 26654);


DELETE FROM `spell_areatrigger` WHERE (`AreaTriggerId`=9645) OR (`AreaTriggerId`=15386) OR (`AreaTriggerId`=9225) OR (`AreaTriggerId`=9397) OR (`AreaTriggerId`=16038) OR (`AreaTriggerId`=12740) OR (`AreaTriggerId`=15562) OR (`AreaTriggerId`=16383) OR (`AreaTriggerId`=15446) OR (`AreaTriggerId`=5972) OR (`AreaTriggerId`=15505) OR (`AreaTriggerId`=15626) OR (`AreaTriggerId`=15830) OR (`AreaTriggerId`=16217) OR (`AreaTriggerId`=15477);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(4928, 9645, 0, 0, 0, 0, 0, 0, 3000, 26654), -- SpellId : 192661
(10533, 15386, 2993, 0, 0, 0, 0, 0, 3000, 26654), -- SpellId : 242606
(4485, 9225, 0, 0, 0, 0, 0, 0, 10000, 26654), -- SpellId : 43265
(4658, 9397, 0, 0, 0, 0, 0, 0, 3865, 26654), -- SpellId : 190356
(11253, 16038, 0, 3448, 0, 0, 0, 0, 2900, 26654), -- SpellId : 250319
(8661, 12740, 0, 0, 0, 0, 0, 2831, 15000, 26654), -- SpellId : 84714
(10733, 15562, 0, 3152, 0, 0, 195, 0, 300000, 26654), -- SpellId : 245241
(11694, 16383, 0, 0, 0, 0, 0, 0, 0, 26654), -- SpellId : 254020
(11227, 15446, 0, 3322, 0, 0, 195, 0, 10000, 26654), -- SpellId : 249994
(1524, 5972, 0, 0, 0, 0, 0, 0, 10000, 26654), -- SpellId : 109248
(10668, 15505, 0, 0, 3138, 0, 0, 0, 1800000, 26654), -- SpellId : 244789
(10798, 15626, 0, 0, 0, 0, 0, 0, 299999, 26654), -- SpellId : 245903
(11022, 15830, 0, 0, 0, 0, 0, 0, 0, 26654), -- SpellId : 248144
(11455, 16217, 0, 3715, 0, 0, 0, 0, 4000, 26654), -- SpellId : 249952
(10656, 15477, 0, 0, 0, 0, 195, 0, 300000, 26654), -- SpellId : 249952
(10643, 15477, 0, 0, 0, 0, 195, 0, 240000, 26654); -- SpellId : 244579


DELETE FROM `conversation_actors` WHERE (`ConversationId`=5430 AND `Idx`=0) OR (`ConversationId`=5430 AND `Idx`=1) OR (`ConversationId`=5307 AND `ConversationActorId`=59235 AND `Idx`=0) OR (`ConversationId`=5632 AND `Idx`=0) OR (`ConversationId`=5632 AND `Idx`=1) OR (`ConversationId`=6053 AND `ConversationActorId`=59304 AND `Idx`=0) OR (`ConversationId`=6057 AND `ConversationActorId`=59304 AND `Idx`=0) OR (`ConversationId`=5306 AND `ConversationActorId`=59235 AND `Idx`=0) OR (`ConversationId`=5639 AND `Idx`=0) OR (`ConversationId`=5647 AND `Idx`=1) OR (`ConversationId`=5647 AND `Idx`=0) OR (`ConversationId`=5305 AND `ConversationActorId`=59235 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
-- (5430, 0, 0, 26654), -- Full: 0x203078DB2078D7C00028C700001C37D1 Creature/0 R3102/S10439 Map: 1753 Entry: 123743 (Alleria Windrunner) Low: 1849297
-- (5430, 0, 1, 26654), -- Full: 0x203078DB207A2AC00028C700001C37D1 Creature/0 R3102/S10439 Map: 1753 Entry: 125099 (Locus-Walker) Low: 1849297
(5307, 59235, 0, 26654),
-- (5632, 0, 0, 26654), -- Full: 0x203078DB2078D7C00028C700001C34A4 Creature/0 R3102/S10439 Map: 1753 Entry: 123743 (Alleria Windrunner) Low: 1848484
-- (5632, 0, 1, 26654), -- Full: 0x203078DB2078D8000028C700001C34A4 Creature/0 R3102/S10439 Map: 1753 Entry: 123744 (Locus-Walker) Low: 1848484
(6053, 59304, 0, 26654),
(6057, 59304, 0, 26654),
(5306, 59235, 0, 26654),
-- (5639, 0, 0, 26654), -- Full: 0x203078DB207AE4000028C700001C36F5 Creature/0 R3102/S10439 Map: 1753 Entry: 125840 (Locus-Walker) Low: 1849077
-- (5647, 0, 1, 26654), -- Full: 0x0
-- (5647, 0, 0, 26654), -- Full: 0x203078DB20784CC00028C700001C381B Creature/0 R3102/S10439 Map: 1753 Entry: 123187 (Alleria Windrunner) Low: 1849371
(5305, 59235, 0, 26654);


DELETE FROM `conversation_actor_template` WHERE `Id` IN (59235, 59304);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(59235, 122316, 76771, 26654),
(59304, 120917, 76272, 26654);


DELETE FROM `conversation_line_template` WHERE `Id` IN (12190, 12174, 12173, 12172, 11853, 12598, 12597, 12596, 13446, 13450, 11852, 12609, 12608, 12607, 12626, 12625, 12624, 11851);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(12190, 36605, 0, 0, 0, 26654),
(12174, 23534, 0, 0, 0, 26654),
(12173, 11076, 0, 1, 0, 26654),
(12172, 0, 0, 0, 0, 26654),
(11853, 0, 1054, 0, 0, 26654),
(12598, 16122, 0, 0, 0, 26654),
(12597, 4929, 0, 1, 0, 26654),
(12596, 0, 0, 0, 0, 26654),
(13446, 0, 121, 0, 0, 26654),
(13450, 0, 121, 0, 0, 26654),
(11852, 0, 1054, 0, 0, 26654),
(12609, 20019, 0, 0, 0, 26654),
(12608, 12353, 0, 0, 8240, 26654),
(12607, 0, 0, 0, 0, 26654),
(12626, 21784, 469675824, 1, 0, 26654),
(12625, 8083, 469675824, 1, 0, 26654),
(12624, 0, 469675824, 0, 0, 26654),
(11851, 0, 1054, 0, 0, 26654);


DELETE FROM `conversation_template` WHERE `Id` IN (5647, 5430, 5639, 5307, 5306, 6057, 5305, 5632, 6053);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(5647, 12624, 28370, 26654),
(5430, 12172, 40659, 26654),
(5639, 12607, 26442, 26654),
(5307, 11853, 9504, 26654),
(5306, 11852, 7901, 26654),
(6057, 13450, 2569, 26654),
(5305, 11851, 9982, 26654),
(5632, 12596, 22764, 26654),
(6053, 13446, 7693, 26654);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (272954 /*Armory Seal*/, 277384 /*Abandoned Treasure*/, 272918 /*Gilded Triumvirate Chest*/, 272950 /*Collision Wall*/, 273789 /*Doodad_7FX_ArgusDungeon_AlleriaVoidWall001*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(272954, 0, 16), -- Armory Seal
(277384, 0, 278560), -- Abandoned Treasure
(272918, 0, 8196), -- Gilded Triumvirate Chest
(272950, 0, 8208), -- Collision Wall
(273789, 0, 48); -- Doodad_7FX_ArgusDungeon_AlleriaVoidWall001


DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+693;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5455.371, 10856.07, 20.1597, 3.81089, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+1, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5442.819, 10777.57, 20.18209, 3.607419, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+2, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5437.595, 10770.93, 20.18209, 2.364305, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+3, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5431.748, 10778.28, 20.23654, 4.410963, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+4, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5441.592, 10864.77, 21.08078, 6.22747, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+5, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5470.615, 10809.47, 17.26447, 2.837986, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23) (Auras: 244087 - -0-, 244300 - -0-)
(@CGUID+6, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5466.918, 10808.63, 17.25347, 1.006229, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (Auras: 244087 - -0-, 244300 - -0-)
(@CGUID+7, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5468.858, 10813.4, 17.25174, 4.093652, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (Auras: 244087 - -0-, 244300 - -0-)
(@CGUID+8, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5493.069, 10875.91, 20.74522, 0.3721198, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23)
(@CGUID+9, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5477.73, 10822.01, 17.2924, 5.576241, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+10, 125855, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5450.017, 10851.54, 34.09304, 6.147438, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+11, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5507.473, 10815.13, 17.25073, 4.941376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+12, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5497.78, 10788.73, 17.25, 0.7574638, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+13, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5467.66, 10848.39, 20.41214, 0.05230689, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+14, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5490.811, 10865.51, 20.19492, 0.2577458, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23) (Auras: 244087 - -0-) (possible waypoints or random movement)
(@CGUID+15, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5464.702, 10779.05, 19.68154, 2.692097, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+16, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5448.351, 10758.79, 20.19641, 4.524559, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23)
(@CGUID+17, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5466.549, 10779.24, 19.43703, 3.246872, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-)
(@CGUID+18, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5481.098, 10807.19, 17.2924, 4.438658, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (Auras: 244087 - -0-)
(@CGUID+19, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5449.856, 10751.2, 20.19641, 2.849299, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23)
(@CGUID+20, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5434.325, 10867.22, 22.00148, 0.03665115, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+21, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5480.988, 10811.74, 17.2924, 4.471224, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (Auras: 244087 - -0-)
(@CGUID+22, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5486.406, 10864.34, 20.1674, 0.2122467, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (Auras: 244087 - -0-) (possible waypoints or random movement)
(@CGUID+23, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5464.491, 10860.93, 20.15872, 4.872573, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+24, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5481.637, 10830.05, 17.2924, 3.613949, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-)
(@CGUID+25, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5439.197, 10872.92, 20.83772, 4.131474, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+26, 122398, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5447.374, 10754.11, 20.19641, 0.1312736, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Sapped Voidlord (Area: -0- - Difficulty: 23) (Auras: 245753 - -0-)
(@CGUID+27, 122313, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5510.343, 10800.22, 21.61538, 1.30955, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Zuraal the Ascended (Area: -0- - Difficulty: 23) (Auras: 244087 - -0-, 246913 - -0-)
(@CGUID+28, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5480.591, 10814.74, 17.2924, 4.335744, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+29, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5483.429, 10864.03, 20.22877, 0.2009186, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (Auras: 244087 - -0-) (possible waypoints or random movement)
(@CGUID+30, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5475.807, 10871.73, 20.56647, 2.701612, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+31, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5482.827, 10727.61, 21.09206, 3.253318, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+32, 122398, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5500.836, 10879.13, 20.19489, 3.93728, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Sapped Voidlord (Area: -0- - Difficulty: 23) (Auras: 245753 - -0-)
(@CGUID+33, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5467.667, 10904.98, 12.28429, 4.682398, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+34, 125855, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5500.373, 10878.13, 40.27689, 4.864802, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+35, 122398, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5498.298, 10910.23, 13.92234, 0.1312736, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Sapped Voidlord (Area: -0- - Difficulty: 23) (Auras: 245753 - -0-)
(@CGUID+36, 125855, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5465.858, 10895.27, 27.75072, 0.5458177, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+37, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5464.288, 10736.72, 20.19641, 5.027327, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23)
(@CGUID+38, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5491.272, 10722.75, 21.53645, 0.06671112, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (Auras: 249133 - -0-)
(@CGUID+39, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5522.386, 10810.73, 17.26041, 3.951421, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+40, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5468, 10906.71, 12.04997, 4.673308, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+41, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5496.182, 10913.88, 13.67602, 5.064742, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23)
(@CGUID+42, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5472.458, 10911.45, 12.47505, 4.620456, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+43, 125855, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5459.995, 10748.69, 40.32311, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+44, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5473.938, 10732.9, 20.22517, 3.307774, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23)
(@CGUID+45, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5495.574, 10725.18, 20.71479, 3.766458, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (Auras: 249133 - -0-)
(@CGUID+46, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5518.581, 10786.27, 17.27501, 0.7885875, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+47, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5477.075, 10892.61, 17.24269, 4.667115, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+48, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5493.133, 10723.81, 21.25808, 2.050396, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-)
(@CGUID+49, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5515.287, 10783.47, 17.27783, 0.8223028, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+50, 122398, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5469.601, 10734.16, 20.19641, 1.45127, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Sapped Voidlord (Area: -0- - Difficulty: 23) (Auras: 245753 - -0-)
(@CGUID+51, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5503.892, 10872.93, 20.19489, 1.865606, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23)
(@CGUID+52, 120652, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5343.49, 10868.08, 29.47722, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Global Affix Stalker (Area: -0- - Difficulty: 23)
(@CGUID+53, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5514.613, 10781.27, 17.27783, 0.846635, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+54, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5512.445, 10783.56, 17.24611, 1.747417, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+55, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5461.421, 10907.08, 11.47854, 5.048496, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+56, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5542.944, 10771.71, 17.31433, 1.435478, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+57, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5533.642, 10732.1, 20.22222, 0.6148561, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+58, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5544.775, 10864.88, 20.73523, 5.661304, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23)
(@CGUID+59, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5568.704, 10903.21, 11.58871, 6.209309, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+60, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5528.186, 10885.96, 20.16821, 2.683544, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+61, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5589.59, 10833.4, 20.19522, 0.7081963, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23)
(@CGUID+62, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5529.279, 10904.83, 16.09549, 5.93389, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+63, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5543.641, 10761.09, 18.13275, 0.7190676, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: ) (possible waypoints or random movement)
(@CGUID+64, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5581.585, 10853.34, 20.31043, 5.999905, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23)
(@CGUID+65, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5569.385, 10897.91, 13.47446, 3.078318, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+66, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5540.658, 10887.48, 20.11583, 1.538144, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+67, 122398, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5566.507, 10731.77, 20.38776, 5.719316, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Sapped Voidlord (Area: -0- - Difficulty: 23) (Auras: 245753 - -0-)
(@CGUID+68, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5586.313, 10852.07, 20.48797, 3.16072, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23)
(@CGUID+69, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5502.292, 10913.15, 13.42431, 4.584033, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23)
(@CGUID+70, 125855, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5494.307, 10920.17, 27.06912, 3.410857, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+71, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5547.378, 10718.1, 22.48307, 5.64408, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+72, 122560, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5535.776, 10721.27, 20.78404, 1.085384, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23) (Auras: 244087 - -0-)
(@CGUID+73, 125855, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5559.852, 10752.99, 36.45972, 6.08441, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+74, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5547.094, 10853.65, 20.31757, 0.4296499, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23)
(@CGUID+75, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5536.561, 10733.98, 20.21669, 0.5016577, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+76, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5565.9, 10724.69, 21.38036, 1.45407, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23)
(@CGUID+77, 122398, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5551.43, 10859.81, 20.23495, 3.120897, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Sapped Voidlord (Area: -0- - Difficulty: 23) (Auras: 245753 - -0-)
(@CGUID+78, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5503.149, 10919.71, 11.82083, 2.867054, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+79, 122560, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5532.754, 10719.22, 20.49325, 1.085384, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23) (Auras: 244087 - -0-)
(@CGUID+80, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5528.894, 10895.89, 16.79321, 0.9092346, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+81, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5575.292, 10727.66, 20.59967, 2.389254, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23)
(@CGUID+82, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5643.036, 10679.48, 35.64671, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+83, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5583.513, 10752.43, 20.21646, 4.29101, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23)
(@CGUID+84, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5599.656, 10840.38, 21.47185, 3.733407, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23)
(@CGUID+85, 122410, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5565.168, 10624.89, 39.85925, 2.380675, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Skyfin (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+86, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5605.121, 10886.96, 12.81863, 2.006639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+87, 122398, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5593.77, 10836.4, 20.39204, 2.77987, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Sapped Voidlord (Area: -0- - Difficulty: 23) (Auras: 245753 - -0-)
(@CGUID+88, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5568.854, 10596.65, 44.42821, 5.790679, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+89, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5647.664, 10678.39, 30.63877, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+90, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5577.833, 10905.19, 10.21841, 0.7961456, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+91, 122410, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5569.389, 10610.71, 40.86507, 2.296176, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Skyfin (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+92, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5568.861, 10907.3, 9.928106, 1.896559, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+93, 123767, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5647.664, 10678.39, 5.024189, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Event Portal Stalker (Area: -0- - Difficulty: 23)
(@CGUID+94, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5582.274, 10750.85, 20.22184, 1.248004, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23)
(@CGUID+95, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5615.865, 10823.92, 20.187, 3.548708, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+96, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5651.071, 10682.78, 36.87661, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+97, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5644.483, 10682.66, 42.17636, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+98, 125855, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5588.625, 10890.52, 32.78469, 2.750384, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+99, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5585.585, 10755.24, 20.19845, 4.29101, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (Auras: 249133 - -0-)
(@CGUID+100, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5587.147, 10744.63, 21.03495, 2.366881, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+101, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5647.749, 10683.69, 33.20461, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+102, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5644.608, 10675.84, 39.29032, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+103, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5577.944, 10889.06, 5.248923, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+104, 125855, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5561.411, 10907.94, 27.6628, 2.07895, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+105, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5645.483, 10674.96, 29.213, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+106, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5565.116, 10588.56, 40.28466, 5.790679, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+107, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5761.181, 10694.92, 24.37366, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+108, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5761.686, 10698.48, 28.18912, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+109, 123767, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5761.181, 10694.92, 5.34789, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Event Portal Stalker (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+110, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5759.539, 10691.15, 31.6478, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+111, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5569.652, 10586.32, 32.13634, 5.790679, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+112, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5759.513, 10697.41, 33.53006, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+113, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5758.855, 10694.46, 36.55644, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+114, 123767, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5570.301, 10590.57, 5.795361, 5.790679, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Event Portal Stalker (Area: -0- - Difficulty: 23)
(@CGUID+115, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5570.951, 10595.42, 34.54237, 5.790679, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+116, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5762.134, 10692.11, 30.18538, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+117, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5565.28, 10593.11, 36.6891, 5.790679, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+118, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5573.794, 10590.63, 29.48135, 5.790679, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+119, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5650.452, 10674.41, 34.4435, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+120, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5763.52, 10696.6, 38.07614, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+121, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5573.781, 10592.79, 46.38359, 5.790679, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+122, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5763.734, 10692.92, 34.83605, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+123, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5573.733, 10584.77, 43.17229, 5.790679, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+124, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5651.843, 10678.06, 31.74681, 5.210605, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+125, 122457, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5543.87, 10560.36, 7.657487, 1.336207, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Darkcaller (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+126, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5764.572, 10695.42, 25.32891, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+127, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5574.307, 10588.37, 37.83184, 5.790679, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+128, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5535.111, 10819.39, 17.1861, 2.707031, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+129, 126283, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5509.865, 10867.45, 20.17078, 3.085753, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Urjad (Area: -0- - Difficulty: 23) (Auras: 244061 - -0-)
(@CGUID+130, 122056, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6140.166, 10391.43, 19.86437, 3.054519, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Viceroy Nezhar (Area: -0- - Difficulty: 23) (Auras: 245029 - -0-, 246913 - -0-)
(@CGUID+131, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5519.403, 10777.12, 17.27783, 2.59368, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+132, 122832, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6142.809, 10388.22, 19.87156, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Center Point (Area: -0- - Difficulty: 23) (Auras: 244789 - -0-)
(@CGUID+133, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5510.117, 10780.93, 17.27783, 0.4834604, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+134, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5512.689, 10821.77, 17.25844, 4.261487, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+135, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5472.725, 10818.66, 17.2924, 5.536067, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+136, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5542.968, 10825.17, 17.57135, 5.225288, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+137, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5486.542, 10776.17, 17.2924, 1.123954, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+138, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5498.05, 10765.55, 17.2924, 1.151741, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
-- (@CGUID+139, 122058, 0, 8910, 8907, 3, '8683', 0, 0, 0, -0.9330277, 0.7008306, 6.616698, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Tentacle (Area: -0- - Difficulty: 23) (Auras: 61791 - Ride Vehicle) - !!! on transport - transport template not found !!!
(@CGUID+140, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5463.88, 10786.78, 18.6263, 4.969377, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+141, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5535.132, 10778.82, 17.18933, 0.03677517, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+142, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5498.222, 10827.81, 17.2924, 0.2049712, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
-- (@CGUID+143, 122058, 0, 8910, 8907, 3, '8683', 0, 0, 0, -0.9330277, 0.252317, 6.349215, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Tentacle (Area: -0- - Difficulty: 23) (Auras: 61791 - Ride Vehicle) - !!! on transport - transport template not found !!!
(@CGUID+144, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5544.92, 10790.79, 17.18933, 3.417657, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+145, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5494.901, 10784.31, 17.25073, 1.685098, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+146, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5487.833, 10810.96, 17.2924, 5.210487, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+147, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5507.798, 10814.83, 17.25844, 5.442997, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
-- (@CGUID+148, 122058, 0, 8910, 8907, 3, '8683', 0, 0, 0, -0.9330277, -0.2836974, 6.349215, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Tentacle (Area: -0- - Difficulty: 23) (Auras: 61791 - Ride Vehicle) - !!! on transport - transport template not found !!!
(@CGUID+149, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5544.522, 10777.66, 17.18933, 3.837152, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+150, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5485.572, 10840.02, 17.70386, 4.924075, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+151, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5558.117, 10786.19, 18.7053, 4.879797, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+152, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5485.817, 10795.14, 17.2924, 2.619229, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
-- (@CGUID+153, 122058, 0, 8910, 8907, 3, '8683', 0, 0, 0, -0.9330279, -0.7193725, 6.616698, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Tentacle (Area: -0- - Difficulty: 23) (Auras: 61791 - Ride Vehicle) - !!! on transport - transport template not found !!!
(@CGUID+154, 122403, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5590.924, 10651.91, 6.184028, 1.174716, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Champion (Area: -0- - Difficulty: 23)
(@CGUID+155, 122413, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5591.938, 10657.83, 5.967014, 4.363108, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Riftstalker (Area: -0- - Difficulty: 23)
(@CGUID+156, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5600.642, 10692.93, 5.776047, 5.99211, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23)
(@CGUID+157, 122403, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5603.157, 10693.97, 5.86632, 3.720093, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Champion (Area: -0- - Difficulty: 23)
(@CGUID+158, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5636.017, 10846.83, 16.97348, 5.016619, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 244087 - -0-, 245746 - -0-)
(@CGUID+159, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5607.778, 10693.15, 5.775742, 2.565419, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+160, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5643.344, 10844.24, 15.76006, 5.016619, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 244087 - -0-, 245746 - -0-)
(@CGUID+161, 122322, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5643.003, 10852.98, 14.34267, 5.016619, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Famished Broken (Area: -0- - Difficulty: 23) (Auras: 244087 - -0-)
(@CGUID+162, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5615.582, 10684.81, 5.451465, 2.389019, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+163, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5594.885, 10657.59, 5.767602, 4.849805, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23)
(@CGUID+164, 122421, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5588.404, 10655.74, 6.310764, 5.863243, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Umbral War-Adept (Area: -0- - Difficulty: 23)
(@CGUID+165, 122410, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5568.068, 10538.3, 62.49419, 2.550207, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Skyfin (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+166, 122410, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5539.3, 10541.79, 60.1003, 2.048891, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Skyfin (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+167, 122410, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5544.983, 10546.07, 59.80535, 2.142148, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Skyfin (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+168, 122410, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5643.76, 11054.43, 81.43021, 3.63225, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Skyfin (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+169, 122410, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5747.161, 10924.64, 80.73389, 2.830033, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Skyfin (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+170, 122410, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5739.022, 10921.89, 80.7965, 2.828692, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Skyfin (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+171, 122413, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5624.401, 10656.21, 4.907336, 4.016971, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Riftstalker (Area: -0- - Difficulty: 23)
(@CGUID+172, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5553.924, 10604.2, 7.184193, 1.862732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+173, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5557.161, 10607.33, 7.184193, 3.800095, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+174, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5612.704, 10639.04, 5.415725, 3.156687, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+175, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5486.254, 10776.54, 17.2924, 0.1366304, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+176, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5496.88, 10764.58, 17.2924, 0.3192425, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+177, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5494.901, 10784.31, 17.25073, 1.629309, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 244074 - -0-)
(@CGUID+178, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5486.087, 10795.47, 17.2924, 4.937063, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23)
(@CGUID+179, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5519.899, 10776.82, 17.25075, 2.960051, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23)
(@CGUID+180, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5510.304, 10780.75, 17.27783, 4.116625, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23)
(@CGUID+181, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5486.357, 10776.47, 17.2924, 1.404328, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23)
(@CGUID+182, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5507.114, 10815.65, 17.25844, 4.316658, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+183, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5463.414, 10786.8, 18.67733, 3.333923, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+184, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5497.556, 10765.23, 17.2924, 3.872852, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 244074 - -0-)
(@CGUID+185, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5539.001, 10803.71, 17.1861, 3.430828, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 244074 - -0-)
(@CGUID+186, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5512.181, 10822.37, 17.25844, 3.711424, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+187, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5497.676, 10826.91, 17.25074, 4.488614, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 244074 - -0-)
(@CGUID+188, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5534.135, 10778.88, 17.25842, 1.10101, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 244074 - -0-)
(@CGUID+189, 126283, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5525.037, 10866.6, 20.19205, 3.085632, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Urjad (Area: -0- - Difficulty: 23) (Auras: 244061 - -0-)
(@CGUID+190, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5545.367, 10778.08, 17.21882, 4.057859, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 244074 - -0-)
(@CGUID+191, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5562.386, 10801.56, 19.04647, 3.758342, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 244074 - -0-)
(@CGUID+192, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5509.147, 10779.82, 17.25074, 0.135054, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 244074 - -0-)
(@CGUID+193, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5558.022, 10786.75, 17.87909, 0.5995166, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 244074 - -0-)
(@CGUID+194, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5485.572, 10840.02, 17.70386, 0.9391664, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+195, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5519.899, 10776.82, 17.25075, 2.811635, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 244074 - -0-)
(@CGUID+196, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5494.901, 10784.31, 17.25073, 2.236973, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+197, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5486.192, 10775.48, 17.25073, 0.7591203, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+198, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5487.02, 10812.37, 17.25074, 6.099653, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+199, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5484.813, 10795.64, 17.25074, 5.470387, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+200, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5536.691, 10818.66, 17.25074, 2.740978, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 254732 - -0-, 244061 - -0-)
(@CGUID+201, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5543.563, 10823.9, 17.45209, 4.369164, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 244074 - -0-)
(@CGUID+202, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5523.458, 10813.22, 17.25844, 5.722295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 244074 - -0-)
(@CGUID+203, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5544.202, 10789.49, 17.18933, 3.951077, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 244074 - -0-)
(@CGUID+204, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5472.108, 10820.07, 17.2924, 3.330809, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+205, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5472.227, 10801.84, 17.2924, 4.03775, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+206, 122313, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5510.343, 10800.22, 21.61538, 1.30955, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Zuraal the Ascended (Area: -0- - Difficulty: 23) (Auras: ) (possible waypoints or random movement)
(@CGUID+207, 126211, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5635.016, 10674.61, 6.58036, 1.800345, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Channel Stalker (Area: -0- - Difficulty: 23) (Auras: ) (possible waypoints or random movement)
(@CGUID+208, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5485.438, 10795.54, 17.2924, 5.232336, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+209, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5486.182, 10776.5, 17.2924, 1.580464, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 244074 - -0-)
(@CGUID+210, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5494.534, 10784.75, 17.2924, 2.268382, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+211, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5463.785, 10786.87, 18.53259, 6.197517, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+212, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5471.251, 10800.29, 17.26042, 1.174366, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+213, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5488.13, 10811.64, 17.2924, 2.771138, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+214, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5472.879, 10818.55, 17.25074, 2.304892, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+215, 122482, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5485.664, 10795.52, 17.2924, 3.004215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Dark Aberration (Area: -0- - Difficulty: 23) (Auras: 244074 - -0-)
(@CGUID+216, 124264, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5569.005, 10785.67, 19.16175, 3.021646, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Move Alleria Stalker (Area: -0- - Difficulty: 23) (Auras: 246858 - -0-) (possible waypoints or random movement)
(@CGUID+217, 123743, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5570.568, 10786.76, 19.15117, 3.021646, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Alleria Windrunner (Area: -0- - Difficulty: 23)
(@CGUID+218, 123744, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5569.807, 10783.51, 19.38297, 3.021646, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Locus-Walker (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+219, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5691.749, 10773.98, 41.64091, 1.352621, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+220, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5875.051, 10467.55, 37.81124, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+221, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5867.355, 10460.42, 35.71687, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+222, 122410, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5779.962, 10729.7, 6.841028, 4.510385, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Skyfin (Area: -0- - Difficulty: 23)
(@CGUID+223, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5866.611, 10463.78, 48.17125, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+224, 123767, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5870.917, 10463.69, 8.770593, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Event Portal Stalker (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+225, 125493, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5694.357, 10807.49, 18.36916, 6.25578, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+226, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5867.822, 10467.49, 43.34559, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+227, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5631.637, 10654.73, 4.933362, 1.523474, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23)
(@CGUID+228, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5870.917, 10463.69, 34.19255, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+229, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5872.979, 10469.73, 45.73067, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+230, 127008, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5701.906, 10761.33, 23.32919, 4.805771, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Assault Door Stalker (Area: -0- - Difficulty: 23) (Auras: ) (possible waypoints or random movement)
(@CGUID+231, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5618.942, 10623.18, 5.441191, 0.6981407, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: ) (possible waypoints or random movement)
(@CGUID+232, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5647.455, 10635.9, 5.117573, 0.4366437, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23) (Auras: ) (possible waypoints or random movement)
(@CGUID+233, 125493, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5692.066, 10677.55, 8.049815, 5.562428, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+234, 125493, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5691.661, 10680.91, 9.033256, 5.898024, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+235, 122413, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5668.077, 10645.85, 5.752316, 0.6948303, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Riftstalker (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+236, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5632.766, 10646.69, 5.022924, 4.904652, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23)
(@CGUID+237, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5695.282, 10670.4, 7.433496, 5.729054, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+238, 126211, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5698.402, 10819.69, 10.58809, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Channel Stalker (Area: -0- - Difficulty: 23)
(@CGUID+239, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5978.28, 10635.4, 53.98371, 5.18805, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+240, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5705.831, 10781.37, 19.09586, 2.31718, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+241, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5632.721, 10640.59, 5.040725, 0.1193222, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+242, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5981.376, 10637.6, 34.72852, 5.18805, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+243, 122403, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5678.479, 10695.96, 5.347877, 5.099031, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Champion (Area: -0- - Difficulty: 23)
(@CGUID+244, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5876.077, 10457.25, 40.31922, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+245, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5982.008, 10633.24, 49.85466, 5.18805, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+246, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5870.913, 10459.81, 49.87742, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+247, 122413, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5681.009, 10693.28, 5.359212, 2.120209, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Riftstalker (Area: -0- - Difficulty: 23)
(@CGUID+248, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5978.573, 10642.02, 36.96878, 5.18805, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+249, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5874.293, 10463.58, 52.18624, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654); -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+250, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5693.229, 10729.69, 19.13954, 2.023283, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+251, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5708.437, 10822.92, 9.520784, 6.186224, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+252, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5984.292, 10633.62, 42.24612, 5.18805, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+253, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5982.845, 10641.6, 46.69135, 5.18805, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+254, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5985.495, 10636.55, 56.76542, 5.18805, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+255, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5975.688, 10640.47, 44.10973, 5.18805, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+256, 123767, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5982.642, 10637.72, 12.64009, 5.18805, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Event Portal Stalker (Area: -0- - Difficulty: 23)
(@CGUID+257, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5985.863, 10641.17, 41.51536, 5.18805, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+258, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5661.741, 10619.68, 6.984692, 1.704513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+259, 122413, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5666.018, 10620.76, 6.235362, 1.704513, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Shadowguard Riftstalker (Area: -0- - Difficulty: 23) (Auras: ) (possible waypoints or random movement)
(@CGUID+260, 126249, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5545.836, 10562.97, 7.607554, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Orb Stalker (Area: -0- - Difficulty: 23)
(@CGUID+261, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5690.465, 10642.47, 7.362106, 2.316882, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+262, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5702.879, 10664.85, 6.869646, 1.69052, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+263, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5685.01, 10632.34, 7.744006, 3.165961, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+264, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5689.392, 10638.45, 7.752658, 1.534662, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+265, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5697.942, 10642.88, 7.480702, 3.036165, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+266, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5714.873, 10666.47, 6.310788, 5.551906, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+267, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5715.788, 10663.6, 5.908278, 1.227668, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+268, 122421, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5731.139, 10805.24, 5.845858, 2.038012, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Umbral War-Adept (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+269, 125780, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5728.103, 10852.93, 15.53865, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Generic Bunny (Area: -0- - Difficulty: 23)
(@CGUID+270, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6018.151, 10588.76, 40.62226, 4.33654, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+271, 125493, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5736.161, 10766.49, 6.514185, 3.24912, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+272, 122403, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5760.038, 10782.07, 5.510542, 2.465598, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Champion (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+273, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6015.894, 10580.99, 48.72253, 4.33654, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+274, 122413, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5754.261, 10786.98, 5.635542, 2.473155, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Riftstalker (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+275, 125493, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5749.071, 10824.3, 9.354174, 4.018499, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+276, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5756.519, 10784.89, 5.585768, 2.465903, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+277, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6018.448, 10573.67, 59.15406, 4.33654, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+278, 126211, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5766.705, 10797.32, 16.32407, 0.1676375, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Channel Stalker (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+279, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5749.004, 10704.23, 5.389552, 6.27742, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+280, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5763.363, 10796, 5.704721, 1.511564, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+281, 123767, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6023.385, 10580.28, 19.65816, 4.33654, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Event Portal Stalker (Area: -0- - Difficulty: 23)
(@CGUID+282, 126211, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5761.752, 10801.55, 13.71006, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Channel Stalker (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+283, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5761.286, 10793.29, 5.63459, 0.9390466, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23)
(@CGUID+284, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5769.937, 10767.79, 5.759855, 5.118695, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+285, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5739.04, 10678.68, 5.389544, 4.534558, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+286, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5733.854, 10661.98, 5.774334, 0.4634601, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+287, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6029.858, 10582.04, 56.03404, 4.33654, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+288, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6023.953, 10578.17, 53.76139, 4.33654, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+289, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6023.385, 10580.28, 65.44225, 4.33654, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+290, 122413, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5775.762, 10769.02, 6.207337, 3.507522, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Riftstalker (Area: -0- - Difficulty: 23)
(@CGUID+291, 126211, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5769.038, 10795.64, 6.945275, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Channel Stalker (Area: -0- - Difficulty: 23)
(@CGUID+292, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5760.976, 10709.42, 5.389552, 1.716473, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+293, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6024.863, 10571.69, 48.61631, 4.33654, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+294, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5782.835, 10769.48, 7.244644, 1.571069, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23)
(@CGUID+295, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6029.816, 10569.66, 39.66548, 4.33654, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+296, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5781.917, 10793.07, 6.297431, 3.055196, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+297, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5761.518, 10693.43, 5.389544, 4.067281, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+298, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5733.002, 10653.45, 5.628673, 1.539318, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+299, 122410, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5864.158, 10689.62, 13.74706, 5.607583, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Skyfin (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+300, 126211, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5776.706, 10760.98, 6.694691, 0.9744509, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Channel Stalker (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+301, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6031.912, 10577.14, 53.00792, 4.33654, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+302, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5779.896, 10767.06, 7.215634, 5.42022, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23)
(@CGUID+303, 122403, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5737.253, 10655.67, 5.672818, 4.225536, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Shadowguard Champion (Area: -0- - Difficulty: 23) (Auras: ) (possible waypoints or random movement)
(@CGUID+304, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5783.876, 10726.62, 6.962279, 1.535974, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23)
(@CGUID+305, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5784.107, 10761.38, 7.24837, 4.590411, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+306, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5761.925, 10680.38, 5.389544, 0.1525829, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: ) (possible waypoints or random movement)
(@CGUID+307, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5787.639, 10772.71, 6.919756, 4.507146, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+308, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5789.125, 10748.66, 21.31347, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+309, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5773.359, 10705.16, 5.4551, 4.973158, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+310, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5775.827, 10706.44, 5.418482, 1.515483, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+311, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5790.863, 10774.4, 6.543791, 6.173796, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+312, 122413, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5737.191, 10653, 5.628673, 1.539318, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Shadowguard Riftstalker (Area: -0- - Difficulty: 23) (Auras: ) (possible waypoints or random movement)
(@CGUID+313, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5786.969, 10812.15, -8.997127, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+314, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5777.111, 10726.36, 6.80382, 0.6262807, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23)
(@CGUID+315, 122410, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5764.035, 10537.47, 22.33663, 2.379694, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Skyfin (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+316, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5775.017, 10690.25, 5.389544, 1.121161, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+317, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5802.052, 10811.05, -15.06204, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+318, 122403, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5777.231, 10664.96, 5.330219, 1.567582, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Shadowguard Champion (Area: -0- - Difficulty: 23) (Auras: ) (possible waypoints or random movement)
(@CGUID+319, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5723.94, 10613.18, -13.09898, 1.444332, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+320, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5758.061, 10617.51, -3.262153, 1.643108, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+321, 122413, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5789.896, 10658.23, 5.398015, 2.367102, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Shadowguard Riftstalker (Area: -0- - Difficulty: 23) (Auras: ) (possible waypoints or random movement)
(@CGUID+322, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5799.754, 10860.11, -25.06693, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+323, 122407, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5793.098, 10657.99, 5.455219, 2.460348, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Warp Stalker (Area: -0- - Difficulty: 23) (Auras: ) (possible waypoints or random movement)
(@CGUID+324, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5829.292, 10788.42, 0.8675922, 0.1984769, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+325, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5733.334, 10612.11, -13.63636, 1.617649, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+326, 122407, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5816.31, 10677, 8.723784, 3.138391, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Warp Stalker (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+327, 122410, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5651.634, 10471.35, 19.7551, 1.091612, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Skyfin (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+328, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5826.447, 10776.57, 3.129468, 0.1078441, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+329, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5812.313, 10680.06, 8.02096, 5.951669, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+330, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5814.951, 10673.2, 8.130492, 0.5781733, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+331, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5819.861, 10722.82, 8.619058, 1.318825, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+332, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5824.283, 10724.11, 8.484291, 1.318825, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23)
(@CGUID+333, 125493, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5812.697, 10809.3, -65.46191, 3.225255, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+334, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5824.482, 10677.51, 7.971378, 1.970285, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+335, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5764.679, 10607.84, -12.79167, 1.589419, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+336, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5822.698, 10677.05, 7.900638, 4.342576, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+337, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5815.271, 10665.72, 8.048128, 6.274944, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+338, 126312, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5866.233, 10698.86, 13.74706, 5.930089, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Sealed Void Cache (Area: -0- - Difficulty: 23) (Auras: 250745 - -0-)
(@CGUID+339, 122413, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5791.659, 10621.2, 4.508101, 0.7070666, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Riftstalker (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+340, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5873.499, 10721.28, 13.74696, 1.891024, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+341, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5840.928, 10697.08, 12.3752, 1.534909, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+342, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5854.794, 10685.26, 15.08078, 3.122554, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+343, 126312, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5871.68, 10720.64, 13.74696, 5.712882, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Sealed Void Cache (Area: -0- - Difficulty: 23) (Auras: 250745 - -0-)
(@CGUID+344, 125493, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5842.066, 10836.86, -54.01838, 2.566274, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+345, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5865.984, 10738.22, 15.90721, 4.873677, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+346, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5841.137, 10686.52, 12.20473, 1.736186, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+347, 122407, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5794, 10617.34, 4.47502, 6.202781, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Warp Stalker (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+348, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5776.481, 10608.69, -3.739875, 1.111078, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+349, 122410, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5941.533, 10655.53, 55.77725, 5.226726, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Skyfin (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+350, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5732.232, 10582.57, -15.93296, 3.05311, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+351, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5803.37, 10625.32, 6.018036, 0.3275225, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+352, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5805.399, 10614.99, 5.768036, 0.01018386, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+353, 122403, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5796.417, 10614.6, 4.5499, 1.539318, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Champion (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+354, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5818.844, 10631.69, 7.716767, 4.664522, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+355, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5814.539, 10624.67, 6.497284, 3.577652, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+356, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5849.663, 10712.9, 10.78183, 5.460733, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+357, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5853.241, 10799.95, -18.53566, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+358, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5747.496, 10584.99, -14.11654, 0.220349, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+359, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5859.405, 10685.95, 13.77632, 2.760165, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+360, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5831.703, 10841.51, -59.60893, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+361, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5830.024, 10662.65, 9.930025, 0.1080261, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+362, 125493, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5840.427, 10842.22, -55.48785, 2.220218, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+363, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5739.874, 10572.15, -14.27588, 2.868688, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
-- (@CGUID+364, 32639, 0, 8910, 8907, 3, '8683', 0, 0, 0, 0, 0, 0, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Gnimo (Area: -0- - Difficulty: 23) - !!! on transport - transport template not found !!!
(@CGUID+365, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5889.002, 10728.31, 13.78863, 5.473519, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+366, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5890.899, 10743.57, 13.82515, 0.06210658, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+367, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5775.617, 10587.05, -14.93295, 1.742772, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+368, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5894.065, 10723.78, 13.78863, 0.1464648, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+369, 122571, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5760.104, 10679.25, 5.348302, 1.641393, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Rift Warden (Area: -0- - Difficulty: 23) (Auras: ) (possible waypoints or random movement)
(@CGUID+370, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5900.797, 10733.6, 13.76289, 4.751744, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+371, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5771.395, 10573.1, -15.03638, 0.8102372, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+372, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5883.63, 10719.24, 13.74703, 1.775269, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+373, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5888.984, 10723.85, 13.74708, 2.684963, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+374, 126312, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5869.845, 10669.2, 13.70774, 0.2303837, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Sealed Void Cache (Area: -0- - Difficulty: 23) (Auras: 250745 - -0-)
(@CGUID+375, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5865.391, 10684.75, 13.74706, 2.137674, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23)
(@CGUID+376, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5867.595, 10691.75, 13.74706, 3.047368, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23)
(@CGUID+377, 122407, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5880.409, 10727.79, 13.74696, 5.245177, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Warp Stalker (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+378, 124276, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5858.62, 10603.33, 39.22849, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Conversation Controller (Area: -0- - Difficulty: 23)
(@CGUID+379, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5919.221, 10727.79, 13.78873, 1.4167, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+380, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5813.505, 10564.07, 1.806545, 3.407858, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+381, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5901.482, 10755.72, 14.36731, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+382, 126211, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5922.403, 10719.87, 21.68866, 0.4363526, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Channel Stalker (Area: -0- - Difficulty: 23)
(@CGUID+383, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5710.585, 10539.51, -15.94649, 4.60393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+384, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5893.129, 10620.39, 12.72169, 0.04544951, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23)
(@CGUID+385, 126211, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5930.421, 10717.1, 15.58051, 0.4363526, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Channel Stalker (Area: -0- - Difficulty: 23)
(@CGUID+386, 126211, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5930.79, 10725.91, 23.88243, 0.60399, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Channel Stalker (Area: -0- - Difficulty: 23)
(@CGUID+387, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5901.064, 10614.37, 13.01441, 3.485882, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23)
(@CGUID+388, 126211, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5927.861, 10717.81, 24.11661, 0.60399, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Channel Stalker (Area: -0- - Difficulty: 23)
(@CGUID+389, 122403, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5898.229, 10619.14, 12.90098, 3.485882, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Champion (Area: -0- - Difficulty: 23)
(@CGUID+390, 122413, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5895.3, 10612.94, 12.82152, 0.9457684, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Riftstalker (Area: -0- - Difficulty: 23)
(@CGUID+391, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5928.137, 10704.57, 13.78873, 2.357026, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+392, 126211, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5933.764, 10724.71, 21.56415, 0.4363526, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Channel Stalker (Area: -0- - Difficulty: 23)
(@CGUID+393, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5830.592, 10541.16, 1.450824, 0.7804464, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+394, 122410, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5717.276, 10434.54, 93.6363, 1.459341, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Skyfin (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+395, 122410, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5711.938, 10431.34, 94.6582, 1.460074, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Skyfin (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+396, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5937.54, 10717.36, 13.7464, 2.622447, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+397, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5561.633, 10618.24, 5.866457, 0.9153296, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+398, 128171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5751.222, 10512.15, -14.91232, 4.97734, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+399, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5861.143, 10543.97, 16.63747, 1.111516, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+400, 122403, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5863.285, 10547.33, 15.46208, 1.018821, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Shadowguard Champion (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+401, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5744.413, 10496.54, -14.33817, 1.930414, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+402, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5840.25, 10537.39, 13.25005, 1.868655, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+403, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5941.887, 10680.47, 13.79799, 4.349298, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+404, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5938.453, 10776.54, 0.7256944, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+405, 122421, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5916.083, 10566.93, 15.12868, 2.260748, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Umbral War-Adept (Area: -0- - Difficulty: 23)
(@CGUID+406, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5953.507, 10725.47, 13.7464, 6.190223, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+407, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5914.669, 10560.57, 14.66595, 2.260748, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23)
(@CGUID+408, 122403, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5916.092, 10570.62, 15.11536, 2.260748, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Champion (Area: -0- - Difficulty: 23)
(@CGUID+409, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5944.883, 10752.96, 4.674624, 5.262735, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+410, 122413, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5915.027, 10563.12, 14.98034, 2.260748, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Riftstalker (Area: -0- - Difficulty: 23)
(@CGUID+411, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5961.382, 10695.47, 13.73741, 0.730637, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+412, 126312, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5962.492, 10682.7, 13.67163, 3.564451, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Sealed Void Cache (Area: -0- - Difficulty: 23) (Auras: 250745 - -0-)
(@CGUID+413, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5960.938, 10705.73, 13.7464, 1.570796, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+414, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5955.899, 10752.62, 4.371157, 2.671123, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+415, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5967.03, 10711.78, 14.9777, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+416, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5940.795, 10783.73, 2.642361, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+417, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5690.999, 10502.84, -16.74477, 6.041582, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+418, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5703.051, 10474.19, 6.07921, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+419, 122401, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5633.361, 10615.54, 6.015682, 5.05127, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Trickster (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+420, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5726.376, 10443.46, -16.09911, 4.127707, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+421, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5780.038, 10487.47, -15.86676, 3.835205, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+422, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5713.564, 10446.08, -16.90327, 5.805153, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+423, 128171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5746.303, 10474.02, -16.18511, 2.120904, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23) (possible waypoints or random movement)
(@CGUID+424, 125493, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5530.681, 10413.91, -78.48325, 2.443655, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+425, 125493, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5523.09, 10414.73, -79.217, 2.619602, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+426, 125493, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5521.472, 10411.59, -77.92847, 2.61407, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+427, 122401, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5905.25, 10654.03, 13.05019, 4.060501, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Trickster (Area: -0- - Difficulty: 23) (Auras: 245655 - -0-)
(@CGUID+428, 122403, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5905.442, 10616.8, 13.10993, 0.5572084, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Champion (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+429, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5905.096, 10619.6, 13.11446, 0.2143196, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+430, 122413, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5909.604, 10623.05, 13.29496, 0.7284139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Riftstalker (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+431, 124171, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5907.838, 10618.37, 13.2342, 0.06817966, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Subjugator (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+432, 122404, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5921.358, 10530.79, 10.33333, 0.1066362, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+433, 122404, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5920.082, 10538.96, 8.371337, 0.1379938, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+434, 122421, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5925.876, 10534.83, 9.980932, 0.1114111, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Umbral War-Adept (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+435, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5961.231, 10624.39, 13.68097, 5.824718, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23)
(@CGUID+436, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5839.149, 10484.27, 5.589923, 6.117716, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+437, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5979.767, 10640.56, 12.67437, 3.178525, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+438, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5980.227, 10619.84, 14.40265, 4.389458, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+439, 122403, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5973.677, 10685.19, 14.53228, 2.042131, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Shadowguard Champion (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+440, 122404, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5980.978, 10688.35, 14.93005, 3.517871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+441, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5988.104, 10675.85, 28.87581, 4.849228, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+442, 122405, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5978.82, 10689.77, 14.82627, 3.691756, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Shadowguard Conjurer (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+443, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5974.894, 10721.44, 10.55937, 2.871645, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+444, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5847.582, 10460.89, 6.165654, 3.695761, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+445, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5979.116, 10591.57, 15.44701, 0.6578975, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+446, 125504, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5996.728, 10683.61, 29.87581, 4.143279, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Shardling (Area: -0- - Difficulty: 23)
(@CGUID+447, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5983.632, 10741.83, 5.791695, 3.807168, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+448, 122401, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5818.518, 10615.75, 4.98506, 1.728774, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Trickster (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+449, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5967.406, 10768.92, 2.695796, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+450, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5964.876, 10746.95, 4.12311, 1.936071, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+451, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5959.719, 10778.69, 4.043403, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+452, 122571, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5864.155, 10479.11, 8.678588, 5.313222, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Rift Warden (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+453, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5793.448, 10452.6, -23.89633, 3.138755, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+454, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5872.588, 10457.88, 8.595563, 1.641986, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+455, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5878.985, 10454.83, 9.078718, 3.475655, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+456, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5813.297, 10440.57, 2.628544, 2.222068, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+457, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5871.526, 10447.01, 8.324852, 4.504035, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+458, 122413, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5760.804, 10446.33, -29.03272, 4.935923, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Riftstalker (Area: -0- - Difficulty: 23)
(@CGUID+459, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5788.064, 10425.44, -3.320585, 1.067784, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+460, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5837.492, 10422.51, 3.37284, 5.765714, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+461, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5814.605, 10415.02, -38.79016, 3.041694, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23)
(@CGUID+462, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5813.429, 10418.22, -38.74616, 3.35085, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23)
(@CGUID+463, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5855.7, 10414.11, 25.56352, 1.329231, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+464, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5974.883, 10493.44, 19.61241, 0.1109219, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+465, 122407, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5721.285, 10430.53, -36.80595, 3.94383, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Warp Stalker (Area: -0- - Difficulty: 23)
(@CGUID+466, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5985.359, 10497.41, 19.03338, 0.6862805, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+467, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5984.718, 10486.39, 20.35448, 3.806489, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+468, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5814.595, 10394.18, 3.243262, 0.3343918, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+469, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5876.006, 10389.08, 2.205126, 5.874227, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+470, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6012.923, 10495.34, 19.79638, 3.785745, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+471, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5879.485, 10387.43, 2.410339, 2.162689, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+472, 122403, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6034.619, 10524.69, 17.18169, 1.373452, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Champion (Area: -0- - Difficulty: 23)
(@CGUID+473, 122421, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6031.75, 10522.35, 17.54378, 1.373452, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Umbral War-Adept (Area: -0- - Difficulty: 23)
(@CGUID+474, 122413, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6028.132, 10520.78, 17.52709, 1.373452, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Riftstalker (Area: -0- - Difficulty: 23)
(@CGUID+475, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6008.95, 10455.13, 19.75296, 0.9599197, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+476, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6026.848, 10489.64, 21.31555, 1.746976, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+477, 122405, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6010.188, 10436.32, 19.05728, 3.152243, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Shadowguard Conjurer (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+478, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5764, 10696.72, 5.348958, 4.196375, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+479, 122404, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6006.659, 10436.54, 19.2564, 3.199001, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+480, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5911.795, 10368.15, 1.953638, 2.75256, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+481, 124947, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6048.723, 10477.7, 20.67857, 2.687364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Flayer (Area: -0- - Difficulty: 23)
(@CGUID+482, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5890.696, 10359.22, -0.07990313, 1.579903, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+483, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6054.774, 10506.84, 20.04391, 2.715939, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+484, 122407, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5755.176, 10383.63, -41.7584, 0.1749207, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Warp Stalker (Area: -0- - Difficulty: 23)
(@CGUID+485, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6050.913, 10497.93, 20.18412, 3.754076, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-) (possible waypoints or random movement)
(@CGUID+486, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6022.973, 10445.01, 19.30435, 0.7107565, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-) (possible waypoints or random movement)
(@CGUID+487, 122404, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6048.24, 10471.94, 21.12502, 6.218332, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+488, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5757.02, 10367.58, -41.99996, 2.320677, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23)
(@CGUID+489, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5754.874, 10364.94, -41.58791, 2.011521, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23)
(@CGUID+490, 122408, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5756.705, 10363.98, -41.08729, 2.011521, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadow Stalker (Area: -0- - Difficulty: 23)
(@CGUID+491, 122571, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5760.104, 10679.25, 5.348302, 1.641393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Rift Warden (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+492, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5853.303, 10610.69, 13.37876, 5.143523, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+493, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5737.244, 10677.34, 5.348958, 1.892212, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+494, 122316, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5914.434, 10696.14, 13.74705, 3.985884, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Saprish (Area: -0- - Difficulty: 23) (Auras: 247145 - -0-)
(@CGUID+495, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5915.149, 10705.9, 45.84222, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+496, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5916.361, 10709.6, 50.07211, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+497, 123767, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5919.455, 10705.8, 13.74719, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Event Portal Stalker (Area: -0- - Difficulty: 23) (Auras: 246258 - -0-)
(@CGUID+498, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5919.455, 10705.8, 39.5068, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+499, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5921.518, 10711.85, 33.04166, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654); -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+500, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5924.615, 10699.36, 43.22453, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+501, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5923.59, 10709.66, 46.26637, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+502, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5919.452, 10701.92, 42.29681, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+503, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5915.893, 10702.54, 38.34678, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+504, 124266, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5922.832, 10705.7, 38.7571, 5.138988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Wave Rift Target Stalker (Area: -0- - Difficulty: 23)
(@CGUID+505, 122319, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5911.299, 10698.82, 13.74706, 3.985884, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Darkfang (Area: -0- - Difficulty: 23) (Auras: 246943 - -0-)
(@CGUID+506, 125340, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5919.641, 10693.8, 13.74706, 3.985884, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadewing (Area: -0- - Difficulty: 23)
(@CGUID+507, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6018.823, 10746.23, 4.365597, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+508, 125505, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5876.071, 10564.27, 14.85344, 4.128198, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+509, 125495, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 5728.513, 10660.07, 6.976394, 1.166852, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+510, 122405, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6085.628, 10498.7, 24.13554, 1.419854, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Conjurer (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+511, 122404, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6053.984, 10467.97, 20.87271, 2.687364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+512, 122404, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6082.47, 10503.06, 23.44162, 4.706611, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+513, 122404, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6086.458, 10499.85, 24.29593, 2.553184, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+514, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6075.765, 10470.63, 23.25798, 6.050677, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-)
(@CGUID+515, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6084.344, 10477.1, 23.38615, 1.119982, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: 245746 - -0-)
(@CGUID+516, 122404, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6092.399, 10486.74, 24.01323, 2.183439, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+517, 122404, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6094.462, 10488.74, 24.5009, 2.325817, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+518, 124947, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6058.083, 10463.12, 21.29291, 2.687364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Flayer (Area: -0- - Difficulty: 23)
(@CGUID+519, 122405, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6092.835, 10489.78, 24.55577, 2.292979, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Conjurer (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+520, 126249, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6087.567, 10498.08, 24.58295, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Orb Stalker (Area: -0- - Difficulty: 23)
(@CGUID+521, 122404, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6069.507, 10450.6, 24.62908, 3.543079, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23)
(@CGUID+522, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6085.052, 10462.2, 24.86849, 1.912905, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+523, 122405, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6056.597, 10446.73, 23.45233, 5.495826, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Conjurer (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+524, 126249, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6062.494, 10445.36, 24.57729, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Orb Stalker (Area: -0- - Difficulty: 23)
(@CGUID+525, 122404, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6065.032, 10440.48, 25.16714, 2.075033, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23) (Auras: 244300 - -0-)
(@CGUID+526, 127451, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6098.904, 10437.93, 28.92117, 5.374617, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Thal'kiel (Area: -0- - Difficulty: 23)
(@CGUID+527, 127466, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6098.232, 10435.54, 29.39316, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Xal'atath (Area: -0- - Difficulty: 23)
(@CGUID+528, 124947, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6139.003, 10428.15, 19.74057, 2.687364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Flayer (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+529, 122423, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6141.56, 10433.02, 19.77544, 0.4942766, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Grand Shadow-Weaver (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+530, 122404, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6140.132, 10428.22, 19.75714, 0.5012558, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+531, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6086.906, 10398.63, 20.30778, 4.448565, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+532, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6093.241, 10405.32, 20.18572, 0.02644656, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+533, 122404, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6136.768, 10434.44, 19.76947, 0.5024009, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+534, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6171.95, 10454.42, 24.50847, 4.57726, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23)
(@CGUID+535, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6156.156, 10439.71, 19.8006, 4.097429, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+536, 122478, 1753, 8910, 8907, 3, '8683', 0, 0, 0, 6164.146, 10431.46, 20.03182, 4.916943, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+537, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6152.311, 10395.59, 19.85558, 3.808901, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+538, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6122.842, 10411.53, 19.82465, 5.038818, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+539, 124947, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6151.192, 10419.34, 19.75342, 2.687364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Flayer (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+540, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6118.786, 10381.21, 19.91185, 1.176562, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+541, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6134.665, 10393.25, 19.87643, 4.264319, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+542, 124947, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6145.492, 10424.96, 19.7309, 2.687364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Flayer (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+543, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6115.791, 10405.61, 20.01736, 6.229828, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+544, 122405, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6150.176, 10424.53, 19.72079, 2.687364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Conjurer (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+545, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6136.431, 10406.59, 19.84407, 3.808901, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+546, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6117.624, 10393.3, 19.79049, 0.721143, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+547, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6128.858, 10400.28, 19.85788, 3.808901, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+548, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6132.618, 10384.73, 19.89745, 6.229828, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23) (Auras: 244771 - -0-)
(@CGUID+549, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6152.993, 10408.93, 19.81597, 4.264319, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+550, 122478, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6184.191, 10461.24, 29.2838, 0.7405078, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23)
(@CGUID+551, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6145, 10401.97, 19.84834, 3.808901, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+552, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6106.156, 10388.76, 19.83588, 0.721143, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+553, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6109.024, 10381.51, 19.97617, 0.721143, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+554, 122404, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6138.772, 10423.51, 19.75576, 2.687364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+555, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6140.902, 10413.93, 19.81716, 5.038818, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+556, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6144.29, 10391.51, 19.87883, 4.264319, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+557, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6129.953, 10414.78, 19.82425, 5.038818, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+558, 122478, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6094.583, 10394.76, 19.93278, 1.578005, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+559, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6107.25, 10399.15, 19.7184, 6.229828, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23) (Auras: 244771 - -0-)
(@CGUID+560, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6125.712, 10391.63, 19.87808, 5.038818, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23) (Auras: 244771 - -0-)
(@CGUID+561, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6132.563, 10376.97, 19.9044, 5.038818, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+562, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6114.405, 10372.24, 19.90321, 0.721143, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+563, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6160.219, 10400.67, 19.78125, 4.264319, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+564, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6125.15, 10370.45, 19.91314, 6.229828, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+565, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6164.972, 10391.11, 19.80512, 3.034401, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+566, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6145.646, 10379.54, 19.91245, 5.038818, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23) (Auras: 244771 - -0-)
(@CGUID+567, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6118.729, 10367.4, 19.89558, 1.176562, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+568, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6134.501, 10364.76, 19.90257, 1.176562, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+569, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6168.683, 10382.51, 19.78493, 3.034401, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+570, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6126.391, 10359.54, 19.8716, 1.176562, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+571, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6140.536, 10367.18, 19.92583, 1.95106, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23) (Auras: 244771 - -0-)
(@CGUID+572, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6156.636, 10382.33, 19.88228, 3.034401, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23) (Auras: 244771 - -0-)
(@CGUID+573, 122404, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6125.621, 10354.15, 19.88863, 2.687364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Voidbender (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+574, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6153.066, 10369.76, 19.97915, 1.95106, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+575, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6166.471, 10371.94, 19.74132, 3.034401, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+576, 124947, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6118.866, 10350.63, 19.8558, 2.687364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Flayer (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+577, 124947, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6128.546, 10351.44, 19.91222, 2.687364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Flayer (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+578, 122405, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6121.979, 10345.71, 19.89357, 2.687364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Conjurer (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+579, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6138.733, 10355.19, 19.74653, 1.95106, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+580, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6153.984, 10359.12, 20.13021, 3.034401, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+581, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6149.712, 10354.94, 19.76215, 1.95106, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+582, 122826, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6161.098, 10362.37, 19.90799, 3.034401, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Tentacle Stalker (Area: -0- - Difficulty: 23)
(@CGUID+583, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6225.482, 10399.48, 46.65553, 4.973876, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+584, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6225.168, 10400.09, 47.79573, 4.744791, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+585, 125104, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6076.19, 10319.4, 34.11213, 0.8654144, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- L'ura Door Barrier Stalker (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+586, 122478, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6170.592, 10304.94, 22.47931, 4.916149, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23)
(@CGUID+587, 122478, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6180.148, 10301.94, 25.16857, 2.245886, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23)
(@CGUID+588, 122478, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6137.282, 10296.01, 21.89371, 4.116171, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23)
(@CGUID+589, 122478, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6138.988, 10304.15, 20.56316, 0.6716297, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23)
(@CGUID+590, 122478, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6145.863, 10287.78, 22.43484, 4.273014, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Discharge (Area: -0- - Difficulty: 23)
(@CGUID+591, 127450, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6038.757, 10279.25, 18.91119, 5.374617, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Thal'kiel (Area: -0- - Difficulty: 23)
(@CGUID+592, 127465, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6037.919, 10281.06, 19.00733, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Xal'atath (Area: -0- - Difficulty: 23)
(@CGUID+593, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6010.441, 10248, 14.84273, 0.1472755, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+594, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5988.174, 10259.44, 15.68376, 0.1219041, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+595, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6003.979, 10254.22, 15.16561, 0.4469658, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+596, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5989.917, 10261.16, 16.0747, 0.1219041, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+597, 122401, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6105.992, 10407.26, 19.88894, 0.4790594, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Shadowguard Trickster (Area: -0- - Difficulty: 23)
(@CGUID+598, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5993.932, 10251.83, 15.02051, 0.3659929, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+599, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6004.681, 10247.85, 14.54757, 1.079034, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+600, 127448, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6004.624, 10246.46, 14.44099, 5.374617, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Thal'kiel (Area: -0- - Difficulty: 23)
(@CGUID+601, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5997.753, 10251.14, 15.24346, 0.3659929, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+602, 127464, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6005.72, 10248.21, 14.62826, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Xal'atath (Area: -0- - Difficulty: 23)
(@CGUID+603, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6007.932, 10243.68, 14.39029, 0.2864453, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+604, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6000.649, 10245.81, 14.19302, 1.079034, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+605, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5981.972, 10254.27, 13.48005, 5.348707, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+606, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5992.958, 10247.21, 13.96998, 0.4469658, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+607, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6004.129, 10241.79, 14.05822, 0.2864453, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+608, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5990.167, 10248.14, 13.90313, 0.1219041, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+609, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5983.822, 10255.09, 14.10737, 5.673767, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+610, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5997.624, 10242.54, 13.79505, 0.9246682, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+611, 124734, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5978.563, 10258.87, 14.13577, 5.585053, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Call to the Void Stalker (Area: -0- - Difficulty: 23)
(@CGUID+612, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6018.867, 10231.34, 15.21498, 0.1219041, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+613, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6010.594, 10236.65, 14.79665, 4.96033, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+614, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6000.981, 10238.16, 13.62658, 0.1320795, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+615, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5987.566, 10243.11, 13.57771, 0.9246682, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+616, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5981.91, 10247.84, 13.46102, 0.1219041, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+617, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6009.655, 10232.04, 13.97312, 5.285392, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+618, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5992.346, 10240.48, 13.37762, 0.9246682, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+619, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6005.244, 10232.55, 13.45968, 5.204419, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+620, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5980.107, 10251.31, 13.63576, 4.5287, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+621, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6018.951, 10228.95, 15.02211, 5.204419, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+622, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6014.54, 10230.66, 14.54858, 5.285392, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+623, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5991.327, 10244.01, 13.64614, 0.9246682, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+624, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6006.463, 10235.02, 13.82612, 4.96033, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+625, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5985.226, 10248.79, 13.69627, 5.592794, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+626, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5979.337, 10250.1, 13.48005, 5.592794, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+627, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5981.258, 10239.34, 13.48005, 0.9246682, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+628, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6006.319, 10224.48, 12.8853, 0.1472755, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+629, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6012.236, 10226.69, 13.34541, 0.1219041, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+630, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5995.628, 10235.91, 13.34578, 0.1320795, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+631, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6009.05, 10226.06, 13.14034, 6.105399, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+632, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5990.063, 10232.06, 14.76193, 0.7925887, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+633, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6010.514, 10222.96, 12.97672, 0.1219041, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+634, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6013.572, 10223.91, 13.19991, 5.285392, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+635, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5988.664, 10233.88, 13.48005, 0.9246682, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+636, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5997.432, 10230.65, 13.82593, 0.1320795, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+637, 124734, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6018.161, 10221.21, 13.22072, 2.486375, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Call to the Void Stalker (Area: -0- - Difficulty: 23) (Auras: 247840 - -0-)
(@CGUID+638, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5984.24, 10237.64, 13.48005, 5.348707, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+639, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5995.484, 10235.93, 13.34092, 0.1320795, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+640, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6002.285, 10232.58, 13.31556, 0.1320795, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+641, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5978.075, 10237.08, 14.53017, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+642, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5975.165, 10238.96, 13.48005, 5.348707, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+643, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5991.873, 10228.2, 13.48005, 0.9246682, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+644, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5982.824, 10233.65, 14.95906, 0.7925887, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+645, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6008.394, 10220.71, 12.99744, 0.1219041, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+646, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6011.401, 10220.1, 12.89852, 0.06630259, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+647, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6002.618, 10223.65, 12.77554, 0.06630259, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+648, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5997.274, 10223.26, 14.52798, 6.105399, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+649, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6076.831, 10204.29, 2.044917, 5.888216, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+650, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6155.353, 10227.07, -92.33365, 3.194186, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+651, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6149.277, 10224.3, -92.06852, 2.326809, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+652, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6158.907, 10223.96, -91.6697, 2.299619, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+653, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5993.133, 10221.17, 13.48005, 0.1320795, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+654, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5970.912, 10233.7, 14.38075, 0.7925887, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+655, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5992.233, 10211.57, 13.7475, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+656, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5990.188, 10222.88, 14.54332, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+657, 124729, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5979.276, 10220.38, 14.28613, 0.7938516, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- L'ura (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+658, 123008, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5966.145, 10236.47, 13.89532, 0.7925887, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Crash/Voidling Stalker (Area: -0- - Difficulty: 23)
(@CGUID+659, 125102, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6122.074, 10366.93, 19.9201, 3.932354, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Portal (Area: -0- - Difficulty: 23)
(@CGUID+660, 125099, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6120.978, 10359.82, 19.8998, 4.074625, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Locus-Walker (Area: -0- - Difficulty: 23)
(@CGUID+661, 123743, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6115.902, 10366.87, 19.96081, 3.86651, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Alleria Windrunner (Area: -0- - Difficulty: 23)
-- (@CGUID+662, 32639, 0, 8910, 8909, 3, '8683', 0, 0, 0, 0, 0, 0, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Gnimo (Area: -0- - Difficulty: 23) - !!! on transport - transport template not found !!!
(@CGUID+663, 125857, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5994.662, 10260.55, 16.24727, 4.748749, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Lashing Voidling (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+664, 125860, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5992.86, 10250.06, 14.64301, 1.556652, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Rift Warden (Area: -0- - Difficulty: 23)
(@CGUID+665, 125857, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5998.62, 10260.48, 16.26443, 4.748749, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Lashing Voidling (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+666, 125860, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6007.292, 10234.68, 14.01007, 0.4977352, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Rift Warden (Area: -0- - Difficulty: 23) (Auras: 241896 - -0-)
(@CGUID+667, 125857, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5991.37, 10259.36, 16.10565, 4.748749, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Lashing Voidling (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+668, 125102, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5993.901, 10259.29, 15.95934, 4.751625, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Portal (Area: -0- - Difficulty: 23)
(@CGUID+669, 125857, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6017.668, 10236.83, 15.4178, 3.327192, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Lashing Voidling (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+670, 125102, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6017.91, 10236.11, 15.51964, 4.751625, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Void Portal (Area: -0- - Difficulty: 23)
(@CGUID+671, 125857, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6018.666, 10233.62, 15.50652, 3.327192, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Lashing Voidling (Area: -0- - Difficulty: 23) (Auras: 254727 - -0-)
(@CGUID+672, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5952.767, 10167.88, -8.943727, 3.63663, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+673, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5942.341, 10168.45, -9.577409, 5.571172, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+674, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5938.537, 10157.87, -11.57625, 5.76098, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+675, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5892.711, 10192.28, -10.82328, 0.8301551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+676, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5875.309, 10211.12, -10.92242, 1.650382, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+677, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5899.889, 10162.15, -16.42161, 0.560163, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+678, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5897.981, 10159.27, -16.44947, 0.579323, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+679, 125857, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6017.668, 10236.83, 15.4178, 3.327192, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Lashing Voidling (Area: -0- - Difficulty: 23) (Auras: 254727 - -0-)
(@CGUID+680, 125857, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6018.666, 10233.62, 15.50652, 3.327192, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Lashing Voidling (Area: -0- - Difficulty: 23) (Auras: 254727 - -0-)
(@CGUID+681, 125857, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5998.62, 10260.48, 16.26443, 4.748749, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Lashing Voidling (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+682, 125857, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5994.662, 10260.55, 16.24727, 4.748749, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Lashing Voidling (Area: -0- - Difficulty: 23) (Auras: )
(@CGUID+683, 125857, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6017.851, 10240.54, 15.68484, 3.327192, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Lashing Voidling (Area: -0- - Difficulty: 23) (Auras: 254727 - -0-)
(@CGUID+684, 125857, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5991.37, 10259.36, 16.10565, 4.748749, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Lashing Voidling (Area: -0- - Difficulty: 23) (Auras: 254727 - -0-)
(@CGUID+685, 125099, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6007.618, 10252.8, 15.07147, 3.745866, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Locus-Walker (Area: -0- - Difficulty: 23)
(@CGUID+686, 123187, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6008.144, 10249.87, 14.87445, 3.745866, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Alleria Windrunner (Area: -0- - Difficulty: 23) (Auras: 247870 - -0-)
(@CGUID+687, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5818.007, 10263.87, -10.16563, 0.807494, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+688, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5813.82, 10284.17, -9.104483, 1.701444, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+689, 125855, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 5812.399, 10288.67, -8.834449, 0.7981206, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@CGUID+690, 125871, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6008.144, 10249.87, 14.87445, 3.745866, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Alleria Windrunner (Area: -0- - Difficulty: 23)
(@CGUID+691, 125872, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6007.616, 10252.78, 15.07006, 3.745861, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Locus-Walker (Area: -0- - Difficulty: 23)
(@CGUID+692, 125871, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6008.144, 10249.87, 14.95779, 3.745866, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Alleria Windrunner (Area: -0- - Difficulty: 23) (Auras: 250027 - -0-)
(@CGUID+693, 125872, 1753, 8910, 8909, 3, '8683', 0, 0, 0, 6007.616, 10252.78, 15.15339, 3.745861, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654); -- Locus-Walker (Area: -0- - Difficulty: 23)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+693;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, '244087 244300'), -- Shadowguard Subjugator - 244087 - -0-, 244300 - -0-
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, '244087 244300'), -- Famished Broken - 244087 - -0-, 244300 - -0-
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, '244087 244300'), -- Famished Broken - 244087 - -0-, 244300 - -0-
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+9, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+10, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+11, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+14, 0, 0, 0, 1, 0, 0, 0, 0, '244087'), -- Shadowguard Subjugator - 244087 - -0-
(@CGUID+15, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+16, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+17, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, '244087'), -- Famished Broken - 244087 - -0-
(@CGUID+19, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, '244087'), -- Famished Broken - 244087 - -0-
(@CGUID+22, 0, 0, 0, 1, 0, 0, 0, 0, '244087'), -- Famished Broken - 244087 - -0-
(@CGUID+23, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+25, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+26, 0, 0, 0, 1, 0, 0, 0, 0, '245753'), -- Sapped Voidlord - 245753 - -0-
(@CGUID+27, 0, 0, 50331648, 1, 0, 0, 0, 0, '244087 246913'), -- Zuraal the Ascended - 244087 - -0-, 246913 - -0-
(@CGUID+28, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+29, 0, 0, 0, 1, 0, 0, 0, 0, '244087'), -- Famished Broken - 244087 - -0-
(@CGUID+30, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+31, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, '245753'), -- Sapped Voidlord - 245753 - -0-
(@CGUID+33, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+34, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+35, 0, 0, 0, 1, 0, 0, 0, 0, '245753'), -- Sapped Voidlord - 245753 - -0-
(@CGUID+36, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+37, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+38, 0, 0, 0, 1, 0, 0, 0, 0, '249133'), -- Famished Broken - 249133 - -0-
(@CGUID+39, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+40, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+41, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+42, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+43, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+44, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+45, 0, 0, 0, 1, 0, 0, 0, 0, '249133'), -- Famished Broken - 249133 - -0-
(@CGUID+46, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+47, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+48, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+49, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+50, 0, 0, 0, 1, 0, 0, 0, 0, '245753'), -- Sapped Voidlord - 245753 - -0-
(@CGUID+51, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+52, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Global Affix Stalker
(@CGUID+53, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+54, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+56, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Void Discharge - 244300 - -0-
(@CGUID+57, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Famished Broken - 244300 - -0-
(@CGUID+58, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+59, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+60, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+61, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+62, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+63, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+64, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+65, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+66, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+67, 0, 0, 0, 1, 0, 0, 0, 0, '245753'), -- Sapped Voidlord - 245753 - -0-
(@CGUID+68, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+69, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+70, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+71, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+72, 0, 0, 0, 1, 0, 0, 0, 0, '244087'), -- Shadow Stalker - 244087 - -0-
(@CGUID+73, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+74, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+75, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Subjugator - 244300 - -0-
(@CGUID+76, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+77, 0, 0, 0, 1, 0, 0, 0, 0, '245753'), -- Sapped Voidlord - 245753 - -0-
(@CGUID+78, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+79, 0, 0, 0, 1, 0, 0, 0, 0, '244087'), -- Shadow Stalker - 244087 - -0-
(@CGUID+80, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+81, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+82, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+83, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+84, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+85, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfin
(@CGUID+86, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+87, 0, 0, 0, 1, 0, 0, 0, 0, '245753'), -- Sapped Voidlord - 245753 - -0-
(@CGUID+88, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+89, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+90, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+91, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfin
(@CGUID+92, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+93, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wave Event Portal Stalker
(@CGUID+94, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Famished Broken
(@CGUID+95, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+96, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+97, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+98, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+99, 0, 0, 0, 1, 0, 0, 0, 0, '249133'), -- Famished Broken - 249133 - -0-
(@CGUID+100, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+101, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+102, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+103, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+104, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+105, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+106, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+107, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+108, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+109, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wave Event Portal Stalker
(@CGUID+110, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+111, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+112, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+113, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+114, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wave Event Portal Stalker
(@CGUID+115, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+116, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+117, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+118, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+119, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+120, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+121, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+122, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+123, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+124, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+125, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Darkcaller
(@CGUID+126, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+127, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+128, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+129, 0, 0, 0, 1, 0, 0, 0, 0, '244061'), -- Urjad - 244061 - -0-
(@CGUID+130, 0, 0, 0, 1, 0, 0, 0, 0, '245029 246913'), -- Viceroy Nezhar - 245029 - -0-, 246913 - -0-
(@CGUID+131, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+132, 0, 0, 0, 1, 0, 0, 0, 0, '244789'), -- Center Point - 244789 - -0-
(@CGUID+133, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+134, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+135, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+136, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+137, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+138, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+139, 0, 0, 0, 1, 0, 0, 0, 0, '61791'), -- Void Tentacle - 61791 - Ride Vehicle
(@CGUID+140, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+141, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+142, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+143, 0, 0, 0, 1, 0, 0, 0, 0, '61791'), -- Void Tentacle - 61791 - Ride Vehicle
(@CGUID+144, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+145, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+146, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+147, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+148, 0, 0, 0, 1, 0, 0, 0, 0, '61791'), -- Void Tentacle - 61791 - Ride Vehicle
(@CGUID+149, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+150, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+151, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+152, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+153, 0, 0, 0, 1, 0, 0, 0, 0, '61791'), -- Void Tentacle - 61791 - Ride Vehicle
(@CGUID+154, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Champion
(@CGUID+155, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Riftstalker
(@CGUID+156, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+157, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Champion
(@CGUID+158, 0, 0, 0, 1, 0, 0, 0, 0, '244087 245746'), -- Void Discharge - 244087 - -0-, 245746 - -0-
(@CGUID+159, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+160, 0, 0, 0, 1, 0, 0, 0, 0, '244087 245746'), -- Void Discharge - 244087 - -0-, 245746 - -0-
(@CGUID+161, 0, 0, 0, 1, 0, 0, 0, 0, '244087'), -- Famished Broken - 244087 - -0-
(@CGUID+162, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+163, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Stalker
(@CGUID+164, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Umbral War-Adept
(@CGUID+165, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfin
(@CGUID+166, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfin
(@CGUID+167, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfin
(@CGUID+168, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfin
(@CGUID+169, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfin
(@CGUID+170, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfin
(@CGUID+171, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Riftstalker
(@CGUID+172, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Stalker
(@CGUID+173, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+174, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+175, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+176, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+177, 0, 0, 0, 1, 0, 0, 0, 0, '244074'), -- Dark Aberration - 244074 - -0-
(@CGUID+178, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+179, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+180, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+181, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+182, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+183, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+184, 0, 0, 0, 1, 0, 0, 0, 0, '244074'), -- Dark Aberration - 244074 - -0-
(@CGUID+185, 0, 0, 0, 1, 0, 0, 0, 0, '244074'), -- Dark Aberration - 244074 - -0-
(@CGUID+186, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+187, 0, 0, 0, 1, 0, 0, 0, 0, '244074'), -- Dark Aberration - 244074 - -0-
(@CGUID+188, 0, 0, 0, 1, 0, 0, 0, 0, '244074'), -- Dark Aberration - 244074 - -0-
(@CGUID+189, 0, 0, 0, 1, 0, 0, 0, 0, '244061'), -- Urjad - 244061 - -0-
(@CGUID+190, 0, 0, 0, 1, 0, 0, 0, 0, '244074'), -- Dark Aberration - 244074 - -0-
(@CGUID+191, 0, 0, 0, 1, 0, 0, 0, 0, '244074'), -- Dark Aberration - 244074 - -0-
(@CGUID+192, 0, 0, 0, 1, 0, 0, 0, 0, '244074'), -- Dark Aberration - 244074 - -0-
(@CGUID+193, 0, 0, 0, 1, 0, 0, 0, 0, '244074'), -- Dark Aberration - 244074 - -0-
(@CGUID+194, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+195, 0, 0, 0, 1, 0, 0, 0, 0, '244074'), -- Dark Aberration - 244074 - -0-
(@CGUID+196, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+197, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+198, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+199, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+200, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- Dark Aberration - 254732 - -0-, 244061 - -0-
(@CGUID+201, 0, 0, 0, 1, 0, 0, 0, 0, '244074'), -- Dark Aberration - 244074 - -0-
(@CGUID+202, 0, 0, 0, 1, 0, 0, 0, 0, '244074'), -- Dark Aberration - 244074 - -0-
(@CGUID+203, 0, 0, 0, 1, 0, 0, 0, 0, '244074'), -- Dark Aberration - 244074 - -0-
(@CGUID+204, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+205, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+206, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Zuraal the Ascended
(@CGUID+207, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Channel Stalker
(@CGUID+208, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+209, 0, 0, 0, 1, 0, 0, 0, 0, '244074'), -- Dark Aberration - 244074 - -0-
(@CGUID+210, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+211, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+212, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+213, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+214, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dark Aberration
(@CGUID+215, 0, 0, 0, 1, 0, 0, 0, 0, '244074'), -- Dark Aberration - 244074 - -0-
(@CGUID+216, 0, 0, 0, 1, 0, 0, 0, 0, '246858'), -- Move Alleria Stalker - 246858 - -0-
(@CGUID+217, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Alleria Windrunner
(@CGUID+218, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Locus-Walker
(@CGUID+219, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+220, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+221, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+222, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfin
(@CGUID+223, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+224, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wave Event Portal Stalker
(@CGUID+225, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+226, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+227, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+228, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+229, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+230, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Assault Door Stalker
(@CGUID+231, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+232, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+233, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+234, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+235, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Riftstalker
(@CGUID+236, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Stalker
(@CGUID+237, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+238, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Channel Stalker
(@CGUID+239, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+240, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+241, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+242, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+243, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Champion
(@CGUID+244, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+245, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+246, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+247, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Riftstalker
(@CGUID+248, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+249, 0, 0, 50331648, 1, 0, 0, 0, 0, ''); -- Wave Rift Target Stalker

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+250, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+251, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+252, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+253, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+254, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+255, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+256, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wave Event Portal Stalker
(@CGUID+257, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+258, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Stalker
(@CGUID+259, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Riftstalker
(@CGUID+260, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Orb Stalker
(@CGUID+261, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+262, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+263, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+264, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+265, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+266, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+267, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+268, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Umbral War-Adept - 244300 - -0-
(@CGUID+269, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Generic Bunny
(@CGUID+270, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+271, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+272, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Champion - 244300 - -0-
(@CGUID+273, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+274, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Riftstalker - 244300 - -0-
(@CGUID+275, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+276, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadow Stalker - 244300 - -0-
(@CGUID+277, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+278, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Channel Stalker
(@CGUID+279, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+280, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+281, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wave Event Portal Stalker
(@CGUID+282, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Channel Stalker
(@CGUID+283, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+284, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+285, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+286, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+287, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+288, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+289, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+290, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Riftstalker
(@CGUID+291, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Channel Stalker
(@CGUID+292, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+293, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+294, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Stalker
(@CGUID+295, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+296, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+297, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+298, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Stalker
(@CGUID+299, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfin
(@CGUID+300, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Channel Stalker
(@CGUID+301, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+302, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+303, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Champion
(@CGUID+304, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+305, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+306, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+307, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+308, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+309, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Void Discharge - 244300 - -0-
(@CGUID+310, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+311, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+312, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Riftstalker
(@CGUID+313, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+314, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+315, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfin
(@CGUID+316, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+317, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+318, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Champion
(@CGUID+319, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+320, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+321, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Riftstalker
(@CGUID+322, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+323, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Warp Stalker
(@CGUID+324, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+325, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+326, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Warp Stalker
(@CGUID+327, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfin
(@CGUID+328, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+329, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+330, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+331, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Stalker
(@CGUID+332, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+333, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+334, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+335, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+336, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+337, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+338, 0, 0, 0, 1, 0, 0, 0, 0, '250745'), -- Sealed Void Cache - 250745 - -0-
(@CGUID+339, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Riftstalker
(@CGUID+340, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Void Discharge - 244300 - -0-
(@CGUID+341, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+342, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+343, 0, 0, 0, 1, 0, 0, 0, 0, '250745'), -- Sealed Void Cache - 250745 - -0-
(@CGUID+344, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+345, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+346, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+347, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Warp Stalker
(@CGUID+348, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+349, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfin
(@CGUID+350, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+351, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+352, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+353, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Champion
(@CGUID+354, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+355, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+356, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+357, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+358, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+359, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+360, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+361, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+362, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+363, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+364, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Gnimo
(@CGUID+365, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Void Discharge - 244300 - -0-
(@CGUID+366, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+367, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+368, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+369, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Rift Warden
(@CGUID+370, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+371, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+372, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Subjugator - 244300 - -0-
(@CGUID+373, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Subjugator - 244300 - -0-
(@CGUID+374, 0, 0, 0, 1, 0, 0, 0, 0, '250745'), -- Sealed Void Cache - 250745 - -0-
(@CGUID+375, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+376, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+377, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Warp Stalker - 244300 - -0-
(@CGUID+378, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Conversation Controller
(@CGUID+379, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+380, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+381, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+382, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Channel Stalker
(@CGUID+383, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+384, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Subjugator
(@CGUID+385, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Channel Stalker
(@CGUID+386, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Channel Stalker
(@CGUID+387, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Stalker
(@CGUID+388, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Channel Stalker
(@CGUID+389, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Champion
(@CGUID+390, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Riftstalker
(@CGUID+391, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+392, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Channel Stalker
(@CGUID+393, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+394, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfin
(@CGUID+395, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfin
(@CGUID+396, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+397, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+398, 0, 0, 50331648, 1, 0, 0, 0, 0, '244300'), -- Void Shardling - 244300 - -0-
(@CGUID+399, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Subjugator - 244300 - -0-
(@CGUID+400, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Champion - 244300 - -0-
(@CGUID+401, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+402, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+403, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+404, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+405, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Umbral War-Adept
(@CGUID+406, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+407, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Stalker
(@CGUID+408, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Champion
(@CGUID+409, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+410, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Riftstalker
(@CGUID+411, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+412, 0, 0, 0, 1, 0, 0, 0, 0, '250745'), -- Sealed Void Cache - 250745 - -0-
(@CGUID+413, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+414, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+415, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+416, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+417, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+418, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+419, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Trickster
(@CGUID+420, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+421, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+422, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+423, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+424, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+425, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+426, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+427, 0, 0, 0, 1, 0, 0, 0, 0, '245655'), -- Shadowguard Trickster - 245655 - -0-
(@CGUID+428, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Champion - 244300 - -0-
(@CGUID+429, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadow Stalker - 244300 - -0-
(@CGUID+430, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Riftstalker - 244300 - -0-
(@CGUID+431, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Subjugator - 244300 - -0-
(@CGUID+432, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Voidbender - 244300 - -0-
(@CGUID+433, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Voidbender - 244300 - -0-
(@CGUID+434, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Umbral War-Adept - 244300 - -0-
(@CGUID+435, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+436, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+437, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Void Discharge - 244300 - -0-
(@CGUID+438, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+439, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Champion - 244300 - -0-
(@CGUID+440, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Voidbender - 244300 - -0-
(@CGUID+441, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+442, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Conjurer - 244300 - -0-
(@CGUID+443, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+444, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+445, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+446, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Void Shardling
(@CGUID+447, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+448, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Trickster
(@CGUID+449, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+450, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+451, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+452, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Rift Warden - 244300 - -0-
(@CGUID+453, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+454, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Void Discharge - 244300 - -0-
(@CGUID+455, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Void Discharge - 244300 - -0-
(@CGUID+456, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+457, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Void Discharge - 244300 - -0-
(@CGUID+458, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Riftstalker
(@CGUID+459, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+460, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+461, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Stalker
(@CGUID+462, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Stalker
(@CGUID+463, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+464, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Void Discharge - 244300 - -0-
(@CGUID+465, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Warp Stalker
(@CGUID+466, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Void Discharge - 244300 - -0-
(@CGUID+467, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Void Discharge - 244300 - -0-
(@CGUID+468, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+469, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+470, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+471, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+472, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Champion
(@CGUID+473, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Umbral War-Adept
(@CGUID+474, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Riftstalker
(@CGUID+475, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Void Discharge - 244300 - -0-
(@CGUID+476, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+477, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Conjurer - 244300 - -0-
(@CGUID+478, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+479, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Voidbender - 244300 - -0-
(@CGUID+480, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+481, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Flayer
(@CGUID+482, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+483, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+484, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Warp Stalker
(@CGUID+485, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+486, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Void Discharge - 244300 - -0-
(@CGUID+487, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Voidbender - 244300 - -0-
(@CGUID+488, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Stalker
(@CGUID+489, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Stalker
(@CGUID+490, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Stalker
(@CGUID+491, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Rift Warden
(@CGUID+492, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+493, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+494, 0, 0, 0, 1, 0, 0, 0, 0, '247145'), -- Saprish - 247145 - -0-
(@CGUID+495, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+496, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+497, 0, 0, 0, 1, 0, 0, 0, 0, '246258'), -- Wave Event Portal Stalker - 246258 - -0-
(@CGUID+498, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+499, 0, 0, 50331648, 1, 0, 0, 0, 0, ''); -- Wave Rift Target Stalker

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+500, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+501, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+502, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+503, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+504, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wave Rift Target Stalker
(@CGUID+505, 0, 0, 0, 1, 0, 0, 0, 0, '246943'), -- Darkfang - 246943 - -0-
(@CGUID+506, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadewing
(@CGUID+507, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+508, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+509, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+510, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Conjurer
(@CGUID+511, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Voidbender - 244300 - -0-
(@CGUID+512, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Voidbender
(@CGUID+513, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Voidbender
(@CGUID+514, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+515, 0, 0, 0, 1, 0, 0, 0, 0, '245746'), -- Void Discharge - 245746 - -0-
(@CGUID+516, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Voidbender
(@CGUID+517, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Voidbender
(@CGUID+518, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Flayer
(@CGUID+519, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Conjurer
(@CGUID+520, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Orb Stalker
(@CGUID+521, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Voidbender
(@CGUID+522, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+523, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Conjurer - 244300 - -0-
(@CGUID+524, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Orb Stalker
(@CGUID+525, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- Shadowguard Voidbender - 244300 - -0-
(@CGUID+526, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+527, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+528, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Flayer
(@CGUID+529, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Grand Shadow-Weaver
(@CGUID+530, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Voidbender
(@CGUID+531, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+532, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+533, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Voidbender
(@CGUID+534, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+535, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+536, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+537, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+538, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+539, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Flayer
(@CGUID+540, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+541, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+542, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Flayer
(@CGUID+543, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+544, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Conjurer
(@CGUID+545, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+546, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+547, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+548, 0, 0, 0, 1, 0, 0, 0, 0, '244771'), -- Tentacle Stalker - 244771 - -0-
(@CGUID+549, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+550, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+551, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+552, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+553, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+554, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Voidbender
(@CGUID+555, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+556, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+557, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+558, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+559, 0, 0, 0, 1, 0, 0, 0, 0, '244771'), -- Tentacle Stalker - 244771 - -0-
(@CGUID+560, 0, 0, 0, 1, 0, 0, 0, 0, '244771'), -- Tentacle Stalker - 244771 - -0-
(@CGUID+561, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+562, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+563, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+564, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+565, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+566, 0, 0, 0, 1, 0, 0, 0, 0, '244771'), -- Tentacle Stalker - 244771 - -0-
(@CGUID+567, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+568, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+569, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+570, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+571, 0, 0, 0, 1, 0, 0, 0, 0, '244771'), -- Tentacle Stalker - 244771 - -0-
(@CGUID+572, 0, 0, 0, 1, 0, 0, 0, 0, '244771'), -- Tentacle Stalker - 244771 - -0-
(@CGUID+573, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Voidbender
(@CGUID+574, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+575, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+576, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Flayer
(@CGUID+577, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Flayer
(@CGUID+578, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowguard Conjurer
(@CGUID+579, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+580, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+581, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+582, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tentacle Stalker
(@CGUID+583, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+584, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+585, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- L'ura Door Barrier Stalker
(@CGUID+586, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+587, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+588, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+589, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+590, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Discharge
(@CGUID+591, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+592, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+593, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+594, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+595, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+596, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+597, 0, 0, 131072, 1, 0, 0, 0, 0, ''), -- Shadowguard Trickster
(@CGUID+598, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+599, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+600, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+601, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+602, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+603, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+604, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+605, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+606, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+607, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+608, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+609, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+610, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+611, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Call to the Void Stalker
(@CGUID+612, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+613, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+614, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+615, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+616, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+617, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+618, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+619, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+620, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+621, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+622, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+623, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+624, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+625, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+626, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+627, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+628, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+629, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+630, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+631, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+632, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+633, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+634, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+635, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+636, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+637, 0, 0, 0, 1, 0, 0, 0, 0, '247840'), -- Call to the Void Stalker - 247840 - -0-
(@CGUID+638, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+639, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+640, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+641, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+642, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+643, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+644, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+645, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+646, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+647, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+648, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+649, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+650, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+651, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+652, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+653, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+654, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+655, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+656, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+657, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- L'ura
(@CGUID+658, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Crash/Voidling Stalker
(@CGUID+659, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Portal
(@CGUID+660, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Locus-Walker
(@CGUID+661, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Alleria Windrunner
(@CGUID+662, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Gnimo
(@CGUID+663, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lashing Voidling
(@CGUID+664, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Rift Warden
(@CGUID+665, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lashing Voidling
(@CGUID+666, 0, 0, 0, 1, 0, 0, 0, 0, '241896'), -- Rift Warden - 241896 - -0-
(@CGUID+667, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lashing Voidling
(@CGUID+668, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Portal
(@CGUID+669, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lashing Voidling
(@CGUID+670, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Void Portal
(@CGUID+671, 0, 0, 0, 1, 0, 0, 0, 0, '254727'), -- Lashing Voidling - 254727 - -0-
(@CGUID+672, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+673, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+674, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+675, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+676, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+677, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+678, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+679, 0, 0, 0, 1, 0, 0, 0, 0, '254727'), -- Lashing Voidling - 254727 - -0-
(@CGUID+680, 0, 0, 0, 1, 0, 0, 0, 0, '254727'), -- Lashing Voidling - 254727 - -0-
(@CGUID+681, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lashing Voidling
(@CGUID+682, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lashing Voidling
(@CGUID+683, 0, 0, 0, 1, 0, 0, 0, 0, '254727'), -- Lashing Voidling - 254727 - -0-
(@CGUID+684, 0, 0, 0, 1, 0, 0, 0, 0, '254727'), -- Lashing Voidling - 254727 - -0-
(@CGUID+685, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Locus-Walker
(@CGUID+686, 0, 0, 0, 1, 0, 0, 0, 0, '247870'), -- Alleria Windrunner - 247870 - -0-
(@CGUID+687, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+688, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+689, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -0-
(@CGUID+690, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Alleria Windrunner
(@CGUID+691, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Locus-Walker
(@CGUID+692, 0, 0, 0, 1, 0, 0, 0, 0, '250027'), -- Alleria Windrunner - 250027 - -0-
(@CGUID+693, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Locus-Walker

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 246779, 1753, 8910, 8907, 3, '8683', 0, 5433.176, 10816.68, 20.30814, 2.385823, 0, 0, 0.9294472, 0.3689552, 7200, 255, 1, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@OGUID+1, 252145, 1753, 8910, 8907, 3, '8683', 0, 5413.991, 10818.33, 20.21275, 2.885626, 0, 0, 0.9918213, 0.1276344, 7200, 255, 1, 26654), -- Instance Portal (Area: -0- - Difficulty: 23)
(@OGUID+2, 272062, 1753, 8910, 8907, 3, '8683', 0, 6074.822, 10317.99, 23.67831, 0.7947479, 0.02548075, -0.03737926, 0.3869715, 0.9209813, 7200, 255, 1, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@OGUID+3, 273661, 1753, 8910, 8907, 3, '8683', 0, 6020.543, 10262.48, 16.75822, 0.7947479, 0.02548075, -0.03737926, 0.3869715, 0.9209813, 7200, 255, 0, 26654), -- -0- (Area: -0- - Difficulty: 23)
(@OGUID+4, 273789, 1753, 8910, 8907, 3, '8683', 0, 5701.001, 10754.23, 18.94999, 2.888511, 0, 0, 0.9920044, 0.1262032, 7200, 255, 1, 26654), -- Doodad_7FX_ArgusDungeon_AlleriaVoidWall001 (Area: -0- - Difficulty: 23)
(@OGUID+5, 272950, 1753, 8910, 8907, 3, '8683', 0, 5727.299, 10852.85, 10.84482, 4.84225, -0.1284308, 0.0005226135, -0.6604404, 0.7398133, 7200, 255, 1, 26654), -- Collision Wall (Area: -0- - Difficulty: 23)
(@OGUID+6, 272918, 1753, 8910, 8907, 3, '8683', 0, 5718.307, 10924.47, -6.572661, 4.742767, -0.1072445, 0.02630424, -0.695857, 0.7096406, 7200, 255, 1, 26654), -- Gilded Triumvirate Chest (Area: -0- - Difficulty: 23)
-- (@OGUID+7, 233282, 1753, 8910, 8907, 3, '8683', 0, 5460.905, 10814.33, 20.11815, 0.8433919, 0, 0, 0.4093084, 0.9123961, 7200, 255, 1, 26654), -- Refreshment Table (Area: -0- - Difficulty: 23) - !!! might be temporary spawn !!!
(@OGUID+8, 272954, 1753, 8910, 8907, 3, '8683', 0, 5728.264, 10852.89, 14.7409, 4.815954, -0.07929277, 0.05858326, -0.6669989, 0.7385074, 7200, 255, 1, 26654); -- Armory Seal (Area: -0- - Difficulty: 23)
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+2, 0.02548086, -0.03737972, 0.386972, 0.9209811), -- -0-
(@OGUID+3, 0.02548086, -0.03737972, 0.386972, 0.9209811), -- -0-
(@OGUID+4, 0, 0, 0.9920049, 0.126199); -- Doodad_7FX_ArgusDungeon_AlleriaVoidWall001

DELETE FROM `creature_template_addon` WHERE `entry` IN (125872 /*125872 (Locus-Walker)*/, 125871 /*125871 (Alleria Windrunner)*/, 123187 /*123187 (Alleria Windrunner) - -0-*/, 125860 /*125860 (Rift Warden)*/, 125857 /*125857 (Lashing Voidling) - -0-*/, 125099 /*125099 (Locus-Walker)*/, 124729 /*124729 (L'ura)*/, 124734 /*124734 (Call to the Void Stalker)*/, 127464 /*127464 (Xal'atath)*/, 127448 /*127448 (Thal'kiel)*/, 123008 /*123008 (Crash/Voidling Stalker)*/, 127465 /*127465 (Xal'atath)*/, 127450 /*127450 (Thal'kiel)*/, 125104 /*125104 (L'ura Door Barrier Stalker)*/, 122826 /*122826 (Tentacle Stalker)*/, 122423 /*122423 (Grand Shadow-Weaver)*/, 127466 /*127466 (Xal'atath)*/, 127451 /*127451 (Thal'kiel)*/, 125340 /*125340 (Shadewing)*/, 122319 /*122319 (Darkfang) - -0-*/, 122316 /*122316 (Saprish) - -0-*/, 124947 /*124947 (Void Flayer)*/, 122404 /*122404 (Shadowguard Voidbender) - -0-*/, 122401 /*122401 (Shadowguard Trickster)*/, 124276 /*124276 (Conversation Controller)*/, 122571 /*122571 (Rift Warden)*/, 125836 /*125836 (Alleria Windrunner)*/, 126312 /*126312 (Sealed Void Cache) - -0-*/, 122407 /*122407 (Warp Stalker)*/, 125780 /*125780 (Generic Bunny)*/, 127008 /*127008 (Assault Door Stalker)*/, 123744 /*123744 (Locus-Walker)*/, 123743 /*123743 (Alleria Windrunner)*/, 124264 /*124264 (Move Alleria Stalker) - -0-*/, 126211 /*126211 (Void Channel Stalker)*/, 122421 /*122421 (Umbral War-Adept)*/, 122408 /*122408 (Shadow Stalker)*/, 122413 /*122413 (Shadowguard Riftstalker)*/, 122403 /*122403 (Shadowguard Champion)*/, 122058 /*122058 (Void Tentacle) - Ride Vehicle*/, 122832 /*122832 (Center Point) - -0-*/, 122056 /*122056 (Viceroy Nezhar) - -0-, -0-*/, 126283 /*126283 (Urjad) - -0-*/, 122482 /*122482 (Dark Aberration) - -0-, -0-*/, 122457 /*122457 (Darkcaller)*/, 123767 /*123767 (Wave Event Portal Stalker)*/, 122410 /*122410 (Skyfin)*/, 124266 /*124266 (Wave Rift Target Stalker)*/, 122560 /*122560 (Shadow Stalker) - -0-*/, 122313 /*122313 (Zuraal the Ascended) - -0-, -0-*/, 122398 /*122398 (Sapped Voidlord) - -0-*/, 122322 /*122322 (Famished Broken) - -0-, -0-*/, 124171 /*124171 (Shadowguard Subjugator) - -0-, -0-*/, 122478 /*122478 (Void Discharge) - -0-*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(125872, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 125872 (Locus-Walker)
(125871, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 125871 (Alleria Windrunner)
(123187, 0, 0, 0, 1, 0, 0, 0, 0, '247870'), -- 123187 (Alleria Windrunner) - -0-
(125860, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 125860 (Rift Warden)
(125857, 0, 0, 0, 1, 0, 0, 0, 0, '254727'), -- 125857 (Lashing Voidling) - -0-
(125099, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 125099 (Locus-Walker)
(124729, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 124729 (L'ura)
(124734, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 124734 (Call to the Void Stalker)
(127464, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 127464 (Xal'atath)
(127448, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 127448 (Thal'kiel)
(123008, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 123008 (Crash/Voidling Stalker)
(127465, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 127465 (Xal'atath)
(127450, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 127450 (Thal'kiel)
(125104, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 125104 (L'ura Door Barrier Stalker)
(122826, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 122826 (Tentacle Stalker)
(122423, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 122423 (Grand Shadow-Weaver)
(127466, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 127466 (Xal'atath)
(127451, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 127451 (Thal'kiel)
(125340, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 125340 (Shadewing)
(122319, 0, 0, 0, 1, 0, 0, 0, 0, '246943'), -- 122319 (Darkfang) - -0-
(122316, 0, 0, 0, 1, 0, 0, 0, 0, '247145'), -- 122316 (Saprish) - -0-
(124947, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 124947 (Void Flayer)
(122404, 0, 0, 0, 1, 0, 0, 0, 0, '244300'), -- 122404 (Shadowguard Voidbender) - -0-
(122401, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 122401 (Shadowguard Trickster)
(124276, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 124276 (Conversation Controller)
(122571, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 122571 (Rift Warden)
(125836, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 125836 (Alleria Windrunner)
(126312, 0, 0, 0, 1, 0, 0, 0, 0, '250745'), -- 126312 (Sealed Void Cache) - -0-
(122407, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 122407 (Warp Stalker)
(125780, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 125780 (Generic Bunny)
(127008, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 127008 (Assault Door Stalker)
(123744, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 123744 (Locus-Walker)
(123743, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 123743 (Alleria Windrunner)
(124264, 0, 0, 0, 1, 0, 0, 0, 0, '246858'), -- 124264 (Move Alleria Stalker) - -0-
(126211, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 126211 (Void Channel Stalker)
(122421, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 122421 (Umbral War-Adept)
(122408, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 122408 (Shadow Stalker)
(122413, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 122413 (Shadowguard Riftstalker)
(122403, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 122403 (Shadowguard Champion)
(122058, 0, 0, 0, 1, 0, 0, 0, 0, '61791'), -- 122058 (Void Tentacle) - Ride Vehicle
(122832, 0, 0, 0, 1, 0, 0, 0, 0, '244789'), -- 122832 (Center Point) - -0-
(122056, 0, 0, 0, 1, 0, 0, 0, 0, '245029 246913'), -- 122056 (Viceroy Nezhar) - -0-, -0-
(126283, 0, 0, 0, 1, 0, 0, 0, 0, '244061'), -- 126283 (Urjad) - -0-
(122482, 0, 0, 0, 1, 0, 0, 0, 0, '254732 244061'), -- 122482 (Dark Aberration) - -0-, -0-
(122457, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 122457 (Darkcaller)
(123767, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 123767 (Wave Event Portal Stalker)
(122410, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 122410 (Skyfin)
(124266, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 124266 (Wave Rift Target Stalker)
(122560, 0, 0, 0, 1, 0, 0, 0, 0, '244087'), -- 122560 (Shadow Stalker) - -0-
(122313, 0, 0, 50331648, 1, 0, 0, 0, 0, '244087 246913'), -- 122313 (Zuraal the Ascended) - -0-, -0-
(122398, 0, 0, 0, 1, 0, 0, 0, 0, '245753'), -- 122398 (Sapped Voidlord) - -0-
(122322, 0, 0, 0, 1, 0, 0, 0, 0, '244087 244300'), -- 122322 (Famished Broken) - -0-, -0-
(124171, 0, 0, 0, 1, 0, 0, 0, 0, '244087 244300'), -- 124171 (Shadowguard Subjugator) - -0-, -0-
(122478, 0, 0, 0, 1, 0, 0, 0, 0, '245746'); -- 122478 (Void Discharge) - -0-

UPDATE `creature_template_addon` SET `auras`='244300' WHERE `entry`=122405; -- 122405 (Shadowguard Conjurer)
UPDATE `creature_template_addon` SET `auras`='244300' WHERE `entry`=128171; -- 128171 (Void Shardling)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=126249; -- 126249 (Void Orb Stalker)


UPDATE `creature_model_info` SET `BoundingRadius`=0.375, `CombatReach`=0.75, `VerifiedBuild`=26654 WHERE `DisplayID`=29209;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=77177;
UPDATE `creature_model_info` SET `BoundingRadius`=5.25105, `CombatReach`=1.5, `VerifiedBuild`=26654 WHERE `DisplayID`=78182;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=76900;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=27824;
UPDATE `creature_model_info` SET `BoundingRadius`=3.295663, `CombatReach`=1.125, `VerifiedBuild`=26654 WHERE `DisplayID`=78427;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=76602;
UPDATE `creature_model_info` SET `BoundingRadius`=2.15751, `CombatReach`=2, `VerifiedBuild`=26654 WHERE `DisplayID`=76771;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=78264;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=75011;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=76423;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=75005;
UPDATE `creature_model_info` SET `BoundingRadius`=2.283493, `CombatReach`=2, `VerifiedBuild`=26654 WHERE `DisplayID`=76471;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=28111;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=28282;
UPDATE `creature_model_info` SET `BoundingRadius`=1.570025, `CombatReach`=1.5, `VerifiedBuild`=26654 WHERE `DisplayID`=78866;
UPDATE `creature_model_info` SET `BoundingRadius`=1.082868, `CombatReach`=0.5, `VerifiedBuild`=26654 WHERE `DisplayID`=75244;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=78509;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=78500;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=27823;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=17188;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=78499;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9467019, `CombatReach`=1.5, `VerifiedBuild`=26654 WHERE `DisplayID`=78752;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=76272;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=24719;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=74907;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=76899;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=75003;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=76939;
UPDATE `creature_model_info` SET `BoundingRadius`=1.328089, `CombatReach`=1.5, `VerifiedBuild`=26654 WHERE `DisplayID`=76613;
UPDATE `creature_model_info` SET `BoundingRadius`=1.723945, `CombatReach`=3, `VerifiedBuild`=26654 WHERE `DisplayID`=78415;
UPDATE `creature_model_info` SET `BoundingRadius`=2.694395, `CombatReach`=7, `VerifiedBuild`=26654 WHERE `DisplayID`=77510;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=19634;
UPDATE `creature_model_info` SET `BoundingRadius`=3.261701, `CombatReach`=3, `VerifiedBuild`=26654 WHERE `DisplayID`=76915;
UPDATE `creature_model_info` SET `BoundingRadius`=0.1, `CombatReach`=0.2, `VerifiedBuild`=26654 WHERE `DisplayID`=43227;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=74905;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7980885, `CombatReach`=1.1, `VerifiedBuild`=26654 WHERE `DisplayID`=76593;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=76587;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=78502;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=36952;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=36944;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=78511;
UPDATE `creature_model_info` SET `BoundingRadius`=1.501148, `CombatReach`=1.5, `VerifiedBuild`=26654 WHERE `DisplayID`=77871;
UPDATE `creature_model_info` SET `BoundingRadius`=1.318663, `CombatReach`=3.25, `VerifiedBuild`=26654 WHERE `DisplayID`=56285;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=36955;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=75479;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8835884, `CombatReach`=1.4, `VerifiedBuild`=26654 WHERE `DisplayID`=76542;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=76601;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=125872 AND `ID`=1) OR (`CreatureID`=125871 AND `ID`=1) OR (`CreatureID`=123187 AND `ID`=1) OR (`CreatureID`=125099 AND `ID`=1) OR (`CreatureID`=122316 AND `ID`=1) OR (`CreatureID`=122404 AND `ID`=1) OR (`CreatureID`=122401 AND `ID`=1) OR (`CreatureID`=125836 AND `ID`=1) OR (`CreatureID`=123743 AND `ID`=1) OR (`CreatureID`=122403 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(125872, 1, 124381, 0, 0, 0, 0, 0, 0, 0, 0), -- Locus-Walker
(125871, 1, 0, 0, 0, 0, 0, 0, 151781, 0, 0), -- Alleria Windrunner
(123187, 1, 0, 0, 0, 0, 0, 0, 151781, 0, 0), -- Alleria Windrunner
(125099, 1, 124381, 0, 0, 0, 0, 0, 0, 0, 0), -- Locus-Walker
(122316, 1, 124381, 0, 0, 0, 0, 0, 0, 0, 0), -- Saprish
(122404, 1, 124732, 0, 0, 0, 0, 0, 0, 0, 0), -- Shadowguard Voidbender
(122401, 1, 132465, 0, 0, 92498, 0, 0, 0, 0, 0), -- Shadowguard Trickster
(125836, 1, 0, 0, 0, 0, 0, 0, 151781, 0, 0), -- Alleria Windrunner
(123743, 1, 0, 0, 0, 0, 0, 0, 151781, 0, 0), -- Alleria Windrunner
(122403, 1, 61346, 0, 0, 0, 0, 0, 0, 0, 0); -- Shadowguard Champion



UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=125872; -- Locus-Walker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2916, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=125871; -- Alleria Windrunner
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768 WHERE `entry`=123187; -- Alleria Windrunner
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=125860; -- Rift Warden
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=125857; -- Lashing Voidling
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=125099; -- Locus-Walker
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=124729; -- L'ura
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=33556480 WHERE `entry`=124734; -- Call to the Void Stalker
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=127464; -- Xal'atath
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=127448; -- Thal'kiel
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=123008; -- Crash/Voidling Stalker
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=127465; -- Xal'atath
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=127450; -- Thal'kiel
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048 WHERE `entry`=125104; -- L'ura Door Barrier Stalker
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=122826; -- Tentacle Stalker
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122423; -- Grand Shadow-Weaver
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=127466; -- Xal'atath
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=127451; -- Thal'kiel
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=125340; -- Shadewing
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=122319; -- Darkfang
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=122316; -- Saprish
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124947; -- Void Flayer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122405; -- Shadowguard Conjurer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=122404; -- Shadowguard Voidbender
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122401; -- Shadowguard Trickster
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048 WHERE `entry`=124276; -- Conversation Controller
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122571; -- Rift Warden
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2916, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=125836; -- Alleria Windrunner
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=34816 WHERE `entry`=126312; -- Sealed Void Cache
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122407; -- Warp Stalker
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344 WHERE `entry`=125780; -- Generic Bunny
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048 WHERE `entry`=127008; -- Assault Door Stalker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=123744; -- Locus-Walker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2916, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=123743; -- Alleria Windrunner
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048 WHERE `entry`=124264; -- Move Alleria Stalker
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048 WHERE `entry`=126211; -- Void Channel Stalker
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122421; -- Umbral War-Adept
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=122408; -- Shadow Stalker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122413; -- Shadowguard Riftstalker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122403; -- Shadowguard Champion
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=133120, `unit_flags3`=1 WHERE `entry`=122058; -- Void Tentacle
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=1073743872, `unit_flags3`=1 WHERE `entry`=122832; -- Center Point
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=2147516672, `unit_flags2`=1073741824, `unit_flags3`=1, `VehicleId`=5408 WHERE `entry`=122056; -- Viceroy Nezhar
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=126283; -- Urjad
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122482; -- Dark Aberration
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=122457; -- Darkcaller
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=4196352 WHERE `entry`=123767; -- Wave Event Portal Stalker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=122410; -- Skyfin
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=4196352 WHERE `entry`=124266; -- Wave Rift Target Stalker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2156, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=122560; -- Shadow Stalker
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=2147516672, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=122313; -- Zuraal the Ascended
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768 WHERE `entry`=122398; -- Sapped Voidlord
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122322; -- Famished Broken
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124171; -- Shadowguard Subjugator
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122478; -- Void Discharge

SET @GROUP_ID := 0;
SET @ID := 0;

DELETE FROM `creature_text` WHERE `CreatureID` IN (122056, 122313, 122316, 123187, 123743, 124276, 125099, 125836, 125840);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(122056, @GROUP_ID+0, @ID+0, 'I shall bring you to your twilight!', 14, 0, 100, 0, 0, 87091, 0, 'Viceroy Nezhar to Player'),
(122056, @GROUP_ID+1, @ID+0, 'No! The darkness... was to be mine...', 14, 0, 100, 0, 0, 87092, 0, 'Viceroy Nezhar to Player'),
(122313, @GROUP_ID+0, @ID+0, 'I will end you!', 14, 0, 100, 53, 0, 87136, 0, 'Zuraal the Ascended to Player'),
(122313, @GROUP_ID+1, @ID+0, 'To the Void with you!', 14, 0, 100, 0, 0, 87137, 0, 'Zuraal the Ascended to Player'),
(122313, @GROUP_ID+2, @ID+0, '|TINTERFACE\\ICONS\\ability_fixated_state_red.blp:20|t Zuraal the Ascended has fixated on you!', 42, 0, 100, 0, 0, 0, 0, 'Zuraal the Ascended to Player'),
(122313, @GROUP_ID+3, @ID+0, 'Pathetic!', 14, 0, 100, 0, 0, 87132, 0, 'Zuraal the Ascended to Player'),
(122313, @GROUP_ID+4, @ID+0, 'Darkness give me strength!', 14, 0, 100, 53, 0, 87135, 0, 'Zuraal the Ascended to Player'),
(122313, @GROUP_ID+5, @ID+0, 'I shall send you to the darkness!', 14, 0, 100, 0, 0, 87138, 0, 'Zuraal the Ascended to Player'),
(122313, @GROUP_ID+6, @ID+0, 'Clarity... comes to me. The Void... was weak.', 14, 0, 100, 0, 0, 87134, 0, 'Zuraal the Ascended to Hati'),
(122316, @GROUP_ID+0, @ID+0, 'Our efforts will not be interrupted!', 14, 0, 100, 0, 0, 87074, 0, 'Saprish to Player'),
(122316, @GROUP_ID+1, @ID+0, 'I shall always be one step ahead!', 14, 0, 100, 0, 0, 87078, 0, 'Saprish'),
(122316, @GROUP_ID+2, @ID+0, 'Strike hard and fast!', 14, 0, 100, 0, 0, 87079, 0, 'Saprish'),
(122316, @GROUP_ID+3, @ID+0, 'I did not... foresee this.', 14, 0, 100, 0, 0, 87077, 0, 'Saprish to Player'),
(123187, @GROUP_ID+0, @ID+0, 'Look out!', 14, 0, 100, 0, 0, 87492, 0, 'Alleria Windrunner to L''ura'),
(123743, @GROUP_ID+0, @ID+0, 'Champions! Over Here!', 14, 0, 100, 0, 0, 87562, 0, 'Alleria Windrunner to Hati'),
(123743, @GROUP_ID+1, @ID+0, 'Follow me!', 14, 0, 100, 0, 0, 87563, 0, 'Alleria Windrunner to Player'),
(124276, @GROUP_ID+0, @ID+0, '|TInterface\\ICONS\\SPELL_WARLOCK_DEMONICPORTAL_PURPLE:20|tA void tear has appeared at the Lower Nether Gate!', 42, 0, 100, 0, 0, 0, 0, 'Conversation Controller to Player'),
(124276, @GROUP_ID+1, @ID+0, '|TInterface\\ICONS\\SPELL_WARLOCK_DEMONICPORTAL_PURPLE:20|tA void tear has appeared at the Temple Foundation!', 42, 0, 100, 0, 0, 0, 0, 'Conversation Controller to Player'),
(125099, @GROUP_ID+0, @ID+0, 'Siphon the portal energy! The naaru''s weakness will become your strength!', 14, 0, 100, 0, 0, 88268, 0, 'Locus-Walker to Alleria Windrunner'),
(125836, @GROUP_ID+0, @ID+0, 'Figure out their motives... and put a stop to their efforts.', 14, 0, 100, 1, 0, 87561, 0, 'Alleria Windrunner to Player'),
(125840, @GROUP_ID+0, @ID+0, 'Thank you for removing the obstacles between me and this staff, heroes.', 12, 0, 100, 0, 0, 87825, 0, 'Locus-Walker to Saprish''s Staff');


UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=4, `HealthModifier`=15, `ManaModifier`=15, `VerifiedBuild`=26654 WHERE `entry`=125871; -- Alleria Windrunner
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `VerifiedBuild`=26654 WHERE `entry`=125099; -- Locus-Walker
UPDATE `creature_template` SET `type`=10, `VerifiedBuild`=26654 WHERE `entry`=124734; -- Call to the Void Stalker
UPDATE `creature_template` SET `type`=10, `type_flags`=1048576, `VerifiedBuild`=26654 WHERE `entry`=127464; -- Xal'atath
UPDATE `creature_template` SET `type`=10, `type_flags`=1048576, `VerifiedBuild`=26654 WHERE `entry`=127465; -- Xal'atath
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `HealthModifier`=50, `VerifiedBuild`=26654 WHERE `entry`=124106; -- Void Tear
UPDATE `creature_template` SET `type`=10, `type_flags`=1048576, `VerifiedBuild`=26654 WHERE `entry`=127466; -- Xal'atath
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `family`=2, `type`=1, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=10.7692, `movementId`=164, `VerifiedBuild`=26654 WHERE `entry`=122319; -- Darkfang
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=6.23077, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=122404; -- Shadowguard Voidbender
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=6.23077, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=122401; -- Shadowguard Trickster
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `type_flags`=1073741824, `VerifiedBuild`=26654 WHERE `entry`=125078; -- Unstable Trap Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=128171; -- Void Shardling
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=15, `type_flags`=2097224, `HealthModifier`=12.3077, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=122571; -- Rift Warden
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `type_flags`=1048576, `type_flags2`=6, `VerifiedBuild`=26654 WHERE `entry`=126312; -- Sealed Void Cache
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `family`=2, `type`=1, `type_flags`=1, `HealthModifier`=6.23077, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=122408; -- Shadow Stalker
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=15, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=0.2, `VerifiedBuild`=26654 WHERE `entry`=122482; -- Dark Aberration
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=43.8462, `VerifiedBuild`=26654 WHERE `entry`=122056; -- Viceroy Nezhar
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `family`=2, `type`=1, `type_flags`=1, `HealthModifier`=6.23077, `VerifiedBuild`=26654 WHERE `entry`=122560; -- Shadow Stalker
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=15, `type_flags`=2097224, `HealthModifier`=6.23077, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=122478; -- Void Discharge
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `type_flags`=1074790400, `type_flags2`=4, `VerifiedBuild`=26654 WHERE `entry`=123054; -- Remnant of Anguish
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=15, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=8, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=124745; -- Greater Rift Warden
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=15, `type_flags`=2097224, `HealthModifier`=2, `VerifiedBuild`=26654 WHERE `entry`=125857; -- Lashing Voidling
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=125102; -- Void Portal
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=10, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=97.6923, `VerifiedBuild`=26654 WHERE `entry`=124729; -- L'ura
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `type_flags`=2097224, `type_flags2`=65536, `HealthModifier`=0.7692308, `VerifiedBuild`=26654 WHERE `entry`=124964; -- Unstable Dark Matter
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=1.53846, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=124967; -- Shadow-Weaver Essence
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=10, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=122423; -- Grand Shadow-Weaver
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `VerifiedBuild`=26654 WHERE `entry`=125840; -- Locus-Walker
UPDATE `creature_template` SET `type`=10, `VerifiedBuild`=26654 WHERE `entry`=125131; -- Saprish's Staff
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `family`=34, `type`=1, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=10.7692, `movementId`=113, `VerifiedBuild`=26654 WHERE `entry`=125340; -- Shadewing
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=15, `type_flags`=2097224, `HealthModifier`=1.15385, `VerifiedBuild`=26654 WHERE `entry`=124947; -- Void Flayer
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=122405; -- Shadowguard Conjurer
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=15, `type_flags`=2097224, `HealthModifier`=6.23077, `VerifiedBuild`=26654 WHERE `entry`=125081; -- Warp Stalker
UPDATE `creature_template` SET `type`=10, `type_flags`=1024, `VerifiedBuild`=26654 WHERE `entry`=124168; -- Ruinous Strike Stalker
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `VerifiedBuild`=26654 WHERE `entry`=124276; -- Conversation Controller
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `VerifiedBuild`=26654 WHERE `entry`=124264; -- Move Alleria Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=47649; -- Efflorescence
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=10, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=122421; -- Umbral War-Adept
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `VerifiedBuild`=26654 WHERE `entry`=122058; -- Void Tentacle
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `family`=34, `type`=1, `type_flags`=1, `HealthModifier`=6.23077, `VerifiedBuild`=26654 WHERE `entry`=122410; -- Skyfin
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=6.23077, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=124171; -- Shadowguard Subjugator
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=15, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=0.3846154, `VerifiedBuild`=26654 WHERE `entry`=123050; -- Waning Void
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=4, `HealthModifier`=15, `ManaModifier`=0, `VerifiedBuild`=26654 WHERE `entry`=123187; -- Alleria Windrunner
UPDATE `creature_template` SET `type`=10, `type_flags`=1048576, `VerifiedBuild`=26654 WHERE `entry`=127448; -- Thal'kiel
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `VerifiedBuild`=26654 WHERE `entry`=123008; -- Crash/Voidling Stalker
UPDATE `creature_template` SET `type`=10, `VerifiedBuild`=26654 WHERE `entry`=125104; -- L'ura Door Barrier Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=122412; -- Bound Voidlord
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=15, `HealthModifier`=3, `VerifiedBuild`=26654 WHERE `entry`=127949; -- Void Manifestation
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=1.53846, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=124880; -- War-Adept Essence
UPDATE `creature_template` SET `IconName`='speak', `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=4, `HealthModifier`=15, `ManaModifier`=15, `VerifiedBuild`=26654 WHERE `entry`=125836; -- Alleria Windrunner
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=15, `type_flags`=2097224, `HealthModifier`=6.23077, `VerifiedBuild`=26654 WHERE `entry`=122407; -- Warp Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=126249; -- Void Orb Stalker
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=4, `HealthModifier`=15, `ManaModifier`=15, `VerifiedBuild`=26654 WHERE `entry`=123743; -- Alleria Windrunner
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=15, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=1.15385, `movementId`=70, `VerifiedBuild`=26654 WHERE `entry`=122716; -- Coalesced Void
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=6.23077, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=122403; -- Shadowguard Champion
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=15, `ManaModifier`=80, `VerifiedBuild`=26654 WHERE `entry`=120917; -- Alleria Windrunner
UPDATE `creature_template` SET `type`=10, `VerifiedBuild`=26654 WHERE `entry`=124266; -- Wave Rift Target Stalker
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=61.5385, `movementId`=180, `VerifiedBuild`=26654 WHERE `entry`=122313; -- Zuraal the Ascended
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=6.23077, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=122322; -- Famished Broken
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `VerifiedBuild`=26654 WHERE `entry`=125872; -- Locus-Walker
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=15, `type_flags`=2097224, `HealthModifier`=12.3077, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=125860; -- Rift Warden
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=15, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=1.15385, `VerifiedBuild`=26654 WHERE `entry`=122827; -- Umbral Tentacle
UPDATE `creature_template` SET `type`=10, `type_flags`=1048576, `VerifiedBuild`=26654 WHERE `entry`=127450; -- Thal'kiel
UPDATE `creature_template` SET `type`=10, `VerifiedBuild`=26654 WHERE `entry`=122826; -- Tentacle Stalker
UPDATE `creature_template` SET `type`=10, `type_flags`=1048576, `VerifiedBuild`=26654 WHERE `entry`=127451; -- Thal'kiel
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `VerifiedBuild`=26654 WHERE `entry`=124427; -- Void Trap
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=15, `type_flags`=2097224, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=125981; -- Fragmented Voidling
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `family`=2, `type`=1, `type_flags`=2097224, `HealthModifier`=6.23077, `VerifiedBuild`=26654 WHERE `entry`=125080; -- Shadow Stalker
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=33.0769, `movementId`=164, `VerifiedBuild`=26654 WHERE `entry`=122316; -- Saprish
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=125504; -- Void Shardling
UPDATE `creature_template` SET `type`=10, `type_flags`=1073742848, `VerifiedBuild`=26654 WHERE `entry`=125780; -- Generic Bunny
UPDATE `creature_template` SET `type`=10, `VerifiedBuild`=26654 WHERE `entry`=127008; -- Assault Door Stalker
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `VerifiedBuild`=26654 WHERE `entry`=123744; -- Locus-Walker
UPDATE `creature_template` SET `type`=10, `VerifiedBuild`=26654 WHERE `entry`=126211; -- Void Channel Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=31216; -- Mirror Image
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=121661; -- Sneaky Snake
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=6.23077, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=122413; -- Shadowguard Riftstalker
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=15, `type_flags`=2097224, `HealthModifier`=23.07692, `VerifiedBuild`=26654 WHERE `entry`=126283; -- Urjad
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `VerifiedBuild`=26654 WHERE `entry`=122832; -- Center Point
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=2, `type`=10, `type_flags`=2097224, `HealthModifier`=45, `VerifiedBuild`=26654 WHERE `entry`=122457; -- Darkcaller
UPDATE `creature_template` SET `type`=10, `VerifiedBuild`=26654 WHERE `entry`=123767; -- Wave Event Portal Stalker
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=4, `type_flags`=2097224, `HealthModifier`=6.23077, `movementId`=144, `VerifiedBuild`=26654 WHERE `entry`=122398; -- Sapped Voidlord


UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=124729 AND `Idx`=3); -- L'ura
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=124729 AND `Idx`=2); -- L'ura
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=124729 AND `Idx`=1); -- L'ura
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=124729 AND `Idx`=0); -- L'ura
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=122423 AND `Idx`=0); -- Grand Shadow-Weaver
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=122405 AND `Idx`=0); -- Shadowguard Conjurer
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=125081 AND `Idx`=1); -- Warp Stalker
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=125081 AND `Idx`=0); -- Warp Stalker
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=122421 AND `Idx`=0); -- Umbral War-Adept
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=122410 AND `Idx`=1); -- Skyfin
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=122410 AND `Idx`=0); -- Skyfin
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=124171 AND `Idx`=0); -- Shadowguard Subjugator
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=122407 AND `Idx`=1); -- Warp Stalker
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=122407 AND `Idx`=0); -- Warp Stalker
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=122403 AND `Idx`=0); -- Shadowguard Champion
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=122322 AND `Idx`=1); -- Famished Broken
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=122322 AND `Idx`=0); -- Famished Broken
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=122404 AND `Idx`=0); -- Shadowguard Voidbender
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=122401 AND `Idx`=0); -- Shadowguard Trickster
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=122056 AND `Idx`=0); -- Viceroy Nezhar
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=122316 AND `Idx`=0); -- Saprish
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=122413 AND `Idx`=0); -- Shadowguard Riftstalker

DELETE FROM `gameobject_template` WHERE `entry` IN (273789 /*Doodad_7FX_ArgusDungeon_AlleriaVoidWall001*/, 272950 /*Collision Wall*/, 272954 /*Armory Seal*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(273789, 0, 44277, 'Doodad_7FX_ArgusDungeon_AlleriaVoidWall001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Doodad_7FX_ArgusDungeon_AlleriaVoidWall001
(272950, 5, 6391, 'Collision Wall', '', '', '', 0.65, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Collision Wall
(272954, 8, 43866, 'Armory Seal', '', '', '', 1.2, 1925, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26654); -- Armory Seal

UPDATE `gameobject_template` SET `VerifiedBuild`=26654 WHERE `entry`=233282; -- Refreshment Table
UPDATE `gameobject_template` SET `type`=3, `displayId`=23883, `IconName`='questinteract', `Data0`=1634, `Data3`=1, `Data8`=48231, `Data10`=1, `Data11`=1, `Data12`=1, `Data13`=1, `Data17`=51600, `Data20`=100, `Data28`=1, `Data30`=75420, `Data31`=1, `VerifiedBuild`=26654 WHERE `entry`=272918; -- Gilded Triumvirate Chest
UPDATE `gameobject_template` SET `type`=50, `displayId`=44843, `IconName`='openhand', `Data0`=43, `Data1`=76544, `Data6`=120, `Data12`=105, `Data15`=1, `Data17`=2331, `Data18`=5, `Data19`=1, `VerifiedBuild`=26654 WHERE `entry`=277384; -- Abandoned Treasure

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=272918 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(272918, 0, 152202, 26654); -- Gilded Triumvirate Chest

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 246922;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(13, 1, 246922, 31, 3, 122313);

UPDATE creature SET spawnMask = 8388870 WHERE map = 1753;
UPDATE gameobject SET spawnMask = 8388870 WHERE map = 1753;

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id IN (122482, 126283));
DELETE FROM `creature` WHERE `guid` IN (210118489,210118506);

DELETE FROM `spell_area` WHERE `area` = 8910;
INSERT INTO `spell_area` VALUES
(244074, 8910, 0, 0, 0, -1, 0, 2, 3, 64, 11);

UPDATE `creature_template` SET `scriptname` = "boss_zuraal_the_ascended" WHERE `entry` = 122313;
UPDATE `creature_template` SET `scriptname` = "npc_shadowguard_subjugator" WHERE `entry` = 124171;
UPDATE `creature_template` SET `scriptname` = "npc_coalesced_void" WHERE `entry` = 122716;

DELETE FROM `spell_script_names` WHERE `scriptname` IN ("spell_null_palm", "aura_void_phased");
INSERT INTO `spell_script_names` VALUES
(246134, "spell_null_palm"),
(246913, "aura_void_phased");

UPDATE `areatrigger_template` SET ScriptName = "at_umbral_ejection" WHERE id = 15477;
