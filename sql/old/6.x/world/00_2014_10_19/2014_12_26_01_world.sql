DROP TABLE IF EXISTS `quest_visual_effect`;
CREATE TABLE `quest_visual_effect` (
    `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
    `Index` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
    `VisualEffect` MEDIUMINT(8) NOT NULL DEFAULT '0',
    `VerifiedBuild` SMALLINT(5) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`, `Index`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


INSERT INTO `quest_visual_effect` (`ID`, `VisualEffect`)
SELECT `ID`, `VisualEffect2` FROM `quest_objectives`
WHERE `VisualEffect2`!=0;
UPDATE `quest_visual_effect` SET `Index`=1 WHERE `Index`=0;

INSERT INTO `quest_visual_effect` (`ID`, `VisualEffect`)
SELECT `ID`, `VisualEffect3` FROM `quest_objectives`
WHERE `VisualEffect3`!=0;
UPDATE `quest_visual_effect` SET `Index`=2 WHERE `Index`=0;

INSERT INTO `quest_visual_effect` (`ID`, `VisualEffect`)
SELECT `ID`, `VisualEffect4` FROM `quest_objectives`
WHERE `VisualEffect4`!=0;
UPDATE `quest_visual_effect` SET `Index`=3 WHERE `Index`=0;

INSERT INTO `quest_visual_effect` (`ID`, `VisualEffect`)
SELECT `ID`, `VisualEffect5` FROM `quest_objectives`
WHERE `VisualEffect5`!=0;
UPDATE `quest_visual_effect` SET `Index`=4 WHERE `Index`=0;

INSERT INTO `quest_visual_effect` (`ID`, `VisualEffect`)
SELECT `ID`, `VisualEffect1` FROM `quest_objectives`
WHERE `VisualEffect1`!=0;

UPDATE `quest_visual_effect` SET `VerifiedBuild`=19034;


ALTER TABLE `quest_objectives`
  DROP `VisualEffect1`,
  DROP `VisualEffect2`,
  DROP `VisualEffect3`,
  DROP `VisualEffect4`,
  DROP `VisualEffect5`;


DELETE FROM `quest_objectives` WHERE `Id` IN (251728, 263919, 263920, 268026, 269586, 269598);
INSERT INTO `quest_objectives` (`Id`, `QuestId`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `UnkFloat`, `Description`, `VerifiedBuild`) VALUES
(251728, 30187, 0, 0, 58438, 10, 0, 0, 'Checkpoints passed', 19034),
(263919, 30152, 0, 0, 58438, 10, 0, 0, 'Checkpoints passed', 19034),
(263920, 30152, 0, 1, 58530, 1, 0, 0, 'Pass underneath the Finish Line', 19034),
(268026, 31061, 0, 0, 62592, 8, 0, 0, 'Shan''ze Cloudrider saved', 19034),
(269586, 32295, 0, 0, 67944, 1, 0, 0, 'Determine the language of the tome', 19034),
(269598, 32295, 0, 1, 67945, 1, 0, 0, 'Determine the tome''s purpose', 19034);


DELETE FROM `quest_visual_effect` WHERE (`Id`=251728 AND `Index`=0) OR (`Id`=251728 AND `Index`=1) OR (`Id`=251728 AND `Index`=2) OR (`Id`=251728 AND `Index`=3) OR (`Id`=251728 AND `Index`=4) OR (`Id`=251728 AND `Index`=5) OR (`Id`=251728 AND `Index`=6) OR (`Id`=251728 AND `Index`=7) OR (`Id`=251728 AND `Index`=8) OR (`Id`=251728 AND `Index`=9) OR (`Id`=251809 AND `Index`=0) OR (`Id`=252884 AND `Index`=0) OR (`Id`=252885 AND `Index`=0) OR (`Id`=252886 AND `Index`=0) OR (`Id`=252887 AND `Index`=0) OR (`Id`=253758 AND `Index`=0) OR (`Id`=253759 AND `Index`=0) OR (`Id`=253760 AND `Index`=0) OR (`Id`=253761 AND `Index`=0) OR (`Id`=253762 AND `Index`=0) OR (`Id`=253763 AND `Index`=0) OR (`Id`=253764 AND `Index`=0) OR (`Id`=253765 AND `Index`=0) OR (`Id`=253826 AND `Index`=0) OR (`Id`=253850 AND `Index`=0) OR (`Id`=255745 AND `Index`=0) OR (`Id`=255746 AND `Index`=0) OR (`Id`=256244 AND `Index`=0) OR (`Id`=256310 AND `Index`=0) OR (`Id`=256330 AND `Index`=0) OR (`Id`=256331 AND `Index`=0) OR (`Id`=263919 AND `Index`=0) OR (`Id`=263919 AND `Index`=1) OR (`Id`=263919 AND `Index`=2) OR (`Id`=263919 AND `Index`=3) OR (`Id`=263919 AND `Index`=4) OR (`Id`=263919 AND `Index`=5) OR (`Id`=263919 AND `Index`=6) OR (`Id`=263919 AND `Index`=7) OR (`Id`=263919 AND `Index`=8) OR (`Id`=263919 AND `Index`=9) OR (`Id`=263919 AND `Index`=10) OR (`Id`=263920 AND `Index`=0) OR (`Id`=263920 AND `Index`=1) OR (`Id`=268026 AND `Index`=0) OR (`Id`=268026 AND `Index`=1) OR (`Id`=268026 AND `Index`=2) OR (`Id`=268026 AND `Index`=3) OR (`Id`=268026 AND `Index`=4) OR (`Id`=268026 AND `Index`=5) OR (`Id`=268026 AND `Index`=6) OR (`Id`=268157 AND `Index`=0) OR (`Id`=268157 AND `Index`=1) OR (`Id`=268230 AND `Index`=0) OR (`Id`=268231 AND `Index`=0) OR (`Id`=268231 AND `Index`=1) OR (`Id`=268239 AND `Index`=0) OR (`Id`=268239 AND `Index`=1) OR (`Id`=268239 AND `Index`=2) OR (`Id`=268481 AND `Index`=0) OR (`Id`=268481 AND `Index`=1) OR (`Id`=268890 AND `Index`=0) OR (`Id`=268987 AND `Index`=0) OR (`Id`=268987 AND `Index`=1) OR (`Id`=268987 AND `Index`=2) OR (`Id`=268999 AND `Index`=0) OR (`Id`=269586 AND `Index`=0) OR (`Id`=269586 AND `Index`=1) OR (`Id`=269586 AND `Index`=2) OR (`Id`=269586 AND `Index`=3) OR (`Id`=269586 AND `Index`=4) OR (`Id`=269586 AND `Index`=5) OR (`Id`=269586 AND `Index`=6) OR (`Id`=269586 AND `Index`=7) OR (`Id`=269586 AND `Index`=8) OR (`Id`=269586 AND `Index`=9) OR (`Id`=269598 AND `Index`=0) OR (`Id`=269598 AND `Index`=1) OR (`Id`=269598 AND `Index`=2) OR (`Id`=270080 AND `Index`=0) OR (`Id`=270109 AND `Index`=0) OR (`Id`=270111 AND `Index`=0) OR (`Id`=270112 AND `Index`=0) OR (`Id`=270144 AND `Index`=0) OR (`Id`=270145 AND `Index`=0) OR (`Id`=270458 AND `Index`=0) OR (`Id`=270458 AND `Index`=1) OR (`Id`=270459 AND `Index`=0) OR (`Id`=270459 AND `Index`=1) OR (`Id`=270460 AND `Index`=0) OR (`Id`=270460 AND `Index`=1) OR (`Id`=270479 AND `Index`=0) OR (`Id`=270480 AND `Index`=0) OR (`Id`=270481 AND `Index`=0) OR (`Id`=270482 AND `Index`=0) OR (`Id`=270570 AND `Index`=0) OR (`Id`=270571 AND `Index`=0) OR (`Id`=270571 AND `Index`=1) OR (`Id`=270571 AND `Index`=2);
INSERT INTO `quest_visual_effect` (`Id`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(251728, 0, 506, 19034),
(251728, 1, 507, 19034),
(251728, 2, 508, 19034),
(251728, 3, 509, 19034),
(251728, 4, 510, 19034),
(251728, 5, 511, 19034),
(251728, 6, 512, 19034),
(251728, 7, 513, 19034),
(251728, 8, 514, 19034),
(251728, 9, 515, 19034),
(251809, 0, 1552, 19034),
(252884, 0, 505, 19034),
(252885, 0, 505, 19034),
(252886, 0, 505, 19034),
(252887, 0, 505, 19034),
(253758, 0, 505, 19034),
(253759, 0, 505, 19034),
(253760, 0, 505, 19034),
(253761, 0, 505, 19034),
(253762, 0, 505, 19034),
(253763, 0, 505, 19034),
(253764, 0, 505, 19034),
(253765, 0, 505, 19034),
(253826, 0, 867, 19034),
(253850, 0, 658, 19034),
(255745, 0, 937, 19034),
(255746, 0, 937, 19034),
(256244, 0, 716, 19034),
(256310, 0, 937, 19034),
(256330, 0, 937, 19034),
(256331, 0, 937, 19034),
(263919, 0, 506, 19034),
(263919, 1, 507, 19034),
(263919, 2, 508, 19034),
(263919, 3, 509, 19034),
(263919, 4, 510, 19034),
(263919, 5, 511, 19034),
(263919, 6, 512, 19034),
(263919, 7, 513, 19034),
(263919, 8, 514, 19034),
(263919, 9, 515, 19034),
(263919, 10, 1551, 19034),
(263920, 0, 635, 19034),
(263920, 1, 1551, 19034),
(268026, 0, 528, 19034),
(268026, 1, 529, 19034),
(268026, 2, 530, 19034),
(268026, 3, 531, 19034),
(268026, 4, 532, 19034),
(268026, 5, 533, 19034),
(268026, 6, 534, 19034),
(268157, 0, 1117, 19034),
(268157, 1, 1118, 19034),
(268230, 0, 658, 19034),
(268231, 0, 658, 19034),
(268231, 1, 1142, 19034),
(268239, 0, 631, 19034),
(268239, 1, 632, 19034),
(268239, 2, 633, 19034),
(268481, 0, 1121, 19034),
(268481, 1, 1122, 19034),
(268890, 0, 538, 19034),
(268987, 0, 1009, 19034),
(268987, 1, 1010, 19034),
(268987, 2, 1011, 19034),
(268999, 0, 569, 19034),
(269586, 0, 1288, 19034),
(269586, 1, 1289, 19034),
(269586, 2, 1290, 19034),
(269586, 3, 1291, 19034),
(269586, 4, 1292, 19034),
(269586, 5, 1293, 19034),
(269586, 6, 1294, 19034),
(269586, 7, 1295, 19034),
(269586, 8, 1296, 19034),
(269586, 9, 1297, 19034),
(269598, 0, 1290, 19034),
(269598, 1, 1294, 19034),
(269598, 2, 1296, 19034),
(270080, 0, 658, 19034),
(270109, 0, 658, 19034),
(270111, 0, 658, 19034),
(270112, 0, 658, 19034),
(270144, 0, 658, 19034),
(270145, 0, 658, 19034),
(270458, 0, 1616, 19034),
(270458, 1, 1619, 19034),
(270459, 0, 1616, 19034),
(270459, 1, 1620, 19034),
(270460, 0, 1616, 19034),
(270460, 1, 1621, 19034),
(270479, 0, 1651, 19034),
(270480, 0, 1650, 19034),
(270481, 0, 1648, 19034),
(270482, 0, 1649, 19034),
(270570, 0, 505, 19034),
(270571, 0, 1616, 19034),
(270571, 1, 1634, 19034),
(270571, 2, 1635, 19034);
