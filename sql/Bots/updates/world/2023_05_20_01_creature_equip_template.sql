--
SET @BOT_START = 70587;
SET @BOT_END   = 70591;

DELETE FROM `creature_equip_template` WHERE `CreatureID` BETWEEN @BOT_START AND @BOT_END;
INSERT INTO `creature_equip_template`
(`CreatureID`,`ID`,`VerifiedBuild`)
VALUES
('70587','1','-1'),
('70588','1','-1'),
('70589','1','-1'),
('70590','1','-1'),
('70591','1','-1');
