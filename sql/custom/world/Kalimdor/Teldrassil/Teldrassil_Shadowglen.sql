-- Teldrassil Shadowglen fixes

-- Creatures
SET @CGUID := 900000;
DELETE FROM `creature` WHERE `guid` = @CGUID+1224;
INSERT INTO `creature` VALUES
(@CGUID+1224, 63331, 1, 6450, 256, 0, 0, 0, 0, -1, 0, 1, 10425.4, 765.203, 1322.67, 1.76636, 300, 0, 0, 100, 0, 0, 0, 0, 0, '', '', 0);