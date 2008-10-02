UPDATE `quest_template` SET `ZoneOrSort` =  -61 WHERE `ZoneOrSort` = 0  AND `RequiredClass` =  9;
UPDATE `quest_template` SET `ZoneOrSort` =  -81 WHERE `ZoneOrSort` = 0  AND `RequiredClass` =  1;
UPDATE `quest_template` SET `ZoneOrSort` =  -82 WHERE `ZoneOrSort` = 0  AND `RequiredClass` =  7;
UPDATE `quest_template` SET `ZoneOrSort` = -141 WHERE `ZoneOrSort` = 0  AND `RequiredClass` =  2;
UPDATE `quest_template` SET `ZoneOrSort` = -161 WHERE `ZoneOrSort` = 0  AND `RequiredClass` =  8;
UPDATE `quest_template` SET `ZoneOrSort` = -162 WHERE `ZoneOrSort` = 0  AND `RequiredClass` =  4;
UPDATE `quest_template` SET `ZoneOrSort` = -261 WHERE `ZoneOrSort` = 0  AND `RequiredClass` =  3;
UPDATE `quest_template` SET `ZoneOrSort` = -262 WHERE `ZoneOrSort` = 0  AND `RequiredClass` =  5;
UPDATE `quest_template` SET `ZoneOrSort` = -263 WHERE `ZoneOrSort` = 0  AND `RequiredClass` = 11;

UPDATE `quest_template` SET `ZoneOrSort` =  -24 WHERE `ZoneOrSort` = 0  AND `RequiredSkill` = 182;
UPDATE `quest_template` SET `ZoneOrSort` = -101 WHERE `ZoneOrSort` = 0  AND `RequiredSkill` = 356;
UPDATE `quest_template` SET `ZoneOrSort` = -121 WHERE `ZoneOrSort` = 0  AND `RequiredSkill` = 164;
UPDATE `quest_template` SET `ZoneOrSort` = -181 WHERE `ZoneOrSort` = 0  AND `RequiredSkill` = 171;
UPDATE `quest_template` SET `ZoneOrSort` = -182 WHERE `ZoneOrSort` = 0  AND `RequiredSkill` = 165;
UPDATE `quest_template` SET `ZoneOrSort` = -201 WHERE `ZoneOrSort` = 0  AND `RequiredSkill` = 202;
UPDATE `quest_template` SET `ZoneOrSort` = -264 WHERE `ZoneOrSort` = 0  AND `RequiredSkill` = 197;
UPDATE `quest_template` SET `ZoneOrSort` = -304 WHERE `ZoneOrSort` = 0  AND `RequiredSkill` = 185;
UPDATE `quest_template` SET `ZoneOrSort` = -324 WHERE `ZoneOrSort` = 0  AND `RequiredSkill` = 129;

ALTER TABLE `quest_template`
	ADD COLUMN  `SuggestedPlayers` int(11) unsigned NOT NULL DEFAULT 0 AFTER `RequiredRepValue`,
	DROP COLUMN `RequiredClass`,
	DROP COLUMN `RequiredSkill`;
