-- 
DELETE FROM `player_classlevelstats` WHERE (`class`=12 AND `level` IN (69,70));
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`, `VerifiedBuild`) VALUES
(12, 69, 1580, 1903, 3038, 1294, 47213), -- BloodElf DemonHunter recalculated
(12, 70, 1734, 2089, 3463, 1421, 47213); -- BloodElf DemonHunter recalculated

UPDATE `player_classlevelstats` SET `str`=202, `agi`=243, `sta`=224, `inte`=165, `VerifiedBuild`=47213 WHERE (`class`=4 AND `level`=50); -- Undead Rogue recalculated
UPDATE `player_classlevelstats` SET `str`=114, `agi`=176, `sta`=238, `inte`=258, `VerifiedBuild`=47213 WHERE (`class`=8 AND `level`=51); -- Troll Mage recalculated
UPDATE `player_classlevelstats` SET `str`=84, `agi`=195, `sta`=180, `inte`=195, `VerifiedBuild`=47213 WHERE (`class`=10 AND `level`=46); -- Vulpera Monk recalculated
UPDATE `player_classlevelstats` SET `VerifiedBuild`=47213 WHERE (`class`=12 AND `level`=65);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=47213 WHERE (`class`=12 AND `level`=66);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=47213 WHERE (`class`=12 AND `level`=67);
UPDATE `player_classlevelstats` SET `VerifiedBuild`=47213 WHERE (`class`=12 AND `level`=68);

