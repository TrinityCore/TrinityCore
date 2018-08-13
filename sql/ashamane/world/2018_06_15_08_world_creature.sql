# correction of NPC Jilanne http://www.wowhead.com/npc=16261/sathiel
DELETE FROM `creature` WHERE `guid`=68316;
INSERT INTO `creature` VALUES (68316, 16261, 530, 0, 0, 1, 0, 0, 0, -1, 0, 0, 8692.4, -6639.63, 72.746, 6.16351, 300, 0, 0, 270, 382, 0, 0, 0, 0, 0, 0, '', 0);
#Check-in Sathiel <Trade Supplies> http://www.wowhead.com/npc=16860/jilanne
DELETE FROM `creature` WHERE `guid`=68392;
INSERT INTO `creature` VALUES (68392, 16860, 530, 0, 0, 1, 0, 0, 0, -1, 0, 1, 8684.41, -6694.29, 73.1376, 0.0934024, 300, 0, 0, 227, 350, 0, 0, 0, 0, 0, 0, '', 0);
