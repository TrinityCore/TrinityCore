SET @TEAM_ALLIANCE := 469;
SET @TEAM_HORDE := 67;
SET @GUILD_FACTION := 1168;
SET @REP_REVERED := 0 | 64 | 128;

SET @VENDOR := 46572;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR AND `SourceEntry` IN (65363, 65364) AND `ElseGroup`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ElseGroup`) VALUES
(23, @VENDOR, 65363, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0, 1); -- Guild Herald

SET @VENDOR := 46602;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR AND `SourceEntry` IN (65363, 65364) AND `ElseGroup`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ElseGroup`) VALUES
(23, @VENDOR, 65363, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0, 1); -- Guild Herald


SET @VENDOR := 51495;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR AND `SourceEntry` IN (65363, 65364) AND `ElseGroup`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ElseGroup`) VALUES
(23, @VENDOR, 65363, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0, 1); -- Guild Herald


SET @VENDOR := 51496;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR AND `SourceEntry` IN (65363, 65364) AND `ElseGroup`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ElseGroup`) VALUES
(23, @VENDOR, 65363, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0, 1); -- Guild Herald


SET @VENDOR := 51501;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR AND `SourceEntry` IN (65363, 65364) AND `ElseGroup`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ElseGroup`) VALUES
(23, @VENDOR, 65363, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0, 1); -- Guild Herald


SET @VENDOR := 51502;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR AND `SourceEntry` IN (65363, 65364) AND `ElseGroup`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ElseGroup`) VALUES
(23, @VENDOR, 65363, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0, 1); -- Guild Herald

SET @VENDOR := 51503;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR AND `SourceEntry` IN (65363, 65364) AND `ElseGroup`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ElseGroup`) VALUES
(23, @VENDOR, 65363, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0, 1); -- Guild Herald

SET @VENDOR := 51504;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR AND `SourceEntry` IN (65363, 65364) AND `ElseGroup`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ElseGroup`) VALUES
(23, @VENDOR, 65363, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0, 1); -- Guild Herald

SET @VENDOR := 51512;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR AND `SourceEntry` IN (65363, 65364) AND `ElseGroup`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ElseGroup`) VALUES
(23, @VENDOR, 65363, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0, 1); -- Guild Herald

SET @VENDOR := 52268;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR AND `SourceEntry` IN (65363, 65364) AND `ElseGroup`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ElseGroup`) VALUES
(23, @VENDOR, 65363, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0, 1); -- Guild Herald


SET @VENDOR := 49588;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR AND `SourceEntry` IN (65363, 65364) AND `ElseGroup`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ElseGroup`) VALUES
(23, @VENDOR, 65363, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0, 1); -- Guild Herald

SET @VENDOR := 49590;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR AND `SourceEntry` IN (65363, 65364) AND `ElseGroup`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ElseGroup`) VALUES
(23, @VENDOR, 65363, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0, 1); -- Guild Herald

SET @VENDOR := 49586;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR AND `SourceEntry` IN (65363, 65364) AND `ElseGroup`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ElseGroup`) VALUES
(23, @VENDOR, 65363, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0, 1); -- Guild Herald

SET @VENDOR := 49587;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 23 AND `SourceGroup`= @VENDOR AND `SourceEntry` IN (65363, 65364) AND `ElseGroup`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ElseGroup`) VALUES
(23, @VENDOR, 65363, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65363, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65363, 6, @TEAM_HORDE, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 17, 4948, 0, 1), -- Guild Herald
(23, @VENDOR, 65364, 5, @GUILD_FACTION, @REP_REVERED, 1), -- Guild Herald
(23, @VENDOR, 65364, 6, @TEAM_ALLIANCE, 0, 1); -- Guild Herald
