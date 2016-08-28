-- 
DELETE FROM `creature_queststarter` WHERE `quest` IN (11520, 11532, 11535, 11538, 11539, 11542, 11545);

DELETE FROM `creature_queststarter` WHERE `quest`=11534;
INSERT INTO `creature_queststarter` VALUES
(25034, 11534);
