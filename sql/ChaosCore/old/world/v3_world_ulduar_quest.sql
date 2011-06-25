SET @GUID := 302683;

DELETE FROM `creature` WHERE `id` IN (33956,33957);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@GUID,'33956','603','1','1','0','0','1444.86','112.472','423.641','2.71061','300','0','0','75600','0','0','0','0','0','0'),
(@GUID+1,'33957','603','2','1','0','0','1443.35','123.526','423.641','3.67446','300','0','0','75600','0','0','0','0','0','0');

UPDATE `quest_template` SET `PrevQuestId`=13604 WHERE `entry`=13607;
UPDATE `quest_template` SET `PrevQuestId`=13607, `NextQuestId`=13614, `ExclusiveGroup`=-13606 WHERE `entry`=13606;
UPDATE `quest_template` SET `PrevQuestId`=13607, `NextQuestId`=13614, `ExclusiveGroup`=-13606 WHERE `entry`=13609;
UPDATE `quest_template` SET `PrevQuestId`=13607, `NextQuestId`=13614, `ExclusiveGroup`=-13606 WHERE `entry`=13610;
UPDATE `quest_template` SET `PrevQuestId`=13607, `NextQuestId`=13614, `ExclusiveGroup`=-13606 WHERE `entry`=13611;

UPDATE `quest_template` SET `PrevQuestId`=13817 WHERE `entry`=13816;
UPDATE `quest_template` SET `PrevQuestId`=13816, `NextQuestId`=13818, `ExclusiveGroup`=-13821 WHERE `entry`=13821;
UPDATE `quest_template` SET `PrevQuestId`=13816, `NextQuestId`=13818, `ExclusiveGroup`=-13821 WHERE `entry`=13822;
UPDATE `quest_template` SET `PrevQuestId`=13816, `NextQuestId`=13818, `ExclusiveGroup`=-13821 WHERE `entry`=13823;
UPDATE `quest_template` SET `PrevQuestId`=13816, `NextQuestId`=13818, `ExclusiveGroup`=-13821 WHERE `entry`=13824;