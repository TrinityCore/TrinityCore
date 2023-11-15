-- Update Evoker stats with simc
UPDATE `player_classlevelstats` SET `str` = 175, `agi` = 270, `sta` = 732, `inte` = 398 WHERE `class` = 13 AND `Level` = 58;
UPDATE `player_classlevelstats` SET `str` = 186, `agi` = 288, `sta` = 779, `inte` = 423 WHERE `class` = 13 AND `Level` = 59;
UPDATE `player_classlevelstats` SET `str` = 198, `agi` = 306, `sta` = 828, `inte` = 450 WHERE `class` = 13 AND `Level` = 60;
UPDATE `player_classlevelstats` SET `str` = 295, `agi` = 456, `sta` = 1235, `inte` = 670 WHERE `class` = 13 AND `Level` = 61;
UPDATE `player_classlevelstats` SET `str` = 336, `agi` = 519, `sta` = 1407, `inte` = 764 WHERE `class` = 13 AND `Level` = 62;
UPDATE `player_classlevelstats` SET `str` = 383, `agi` = 592, `sta` = 1603, `inte` = 870 WHERE `class` = 13 AND `Level` = 63;
UPDATE `player_classlevelstats` SET `str` = 436, `agi` = 674, `sta` = 1826, `inte` = 992 WHERE `class` = 13 AND `Level` = 64;
UPDATE `player_classlevelstats` SET `str` = 497, `agi` = 768, `sta` = 2081, `inte` = 1130 WHERE `class` = 13 AND `Level` = 65;
UPDATE `player_classlevelstats` SET `str` = 566, `agi` = 875, `sta` = 2370, `inte` = 1287 WHERE `class` = 13 AND `Level` = 66;
UPDATE `player_classlevelstats` SET `str` = 645, `agi` = 997, `sta` = 2701, `inte` = 1466 WHERE `class` = 13 AND `Level` = 67;
UPDATE `player_classlevelstats` SET `str` = 735, `agi` = 1136, `sta` = 3077, `inte` = 1671 WHERE `class` = 13 AND `Level` = 68;
UPDATE `player_classlevelstats` SET `str` = 838, `agi` = 1294, `sta` = 3506, `inte` = 1903 WHERE `class` = 13 AND `Level` = 69;
UPDATE `player_classlevelstats` SET `str` = 919, `agi` = 1421, `sta` = 3848, `inte` = 2089 WHERE `class` = 13 AND `Level` = 70;

UPDATE `player_classlevelstats` SET `VerifiedBuild` = 0 WHERE `Class` = 13 AND `Level` BETWEEN 58 AND 70;
