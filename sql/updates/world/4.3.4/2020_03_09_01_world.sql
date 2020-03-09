-- Fireplume Peak movement updates
UPDATE `creature_template_movement` SET `Swim`= 1 WHERE `CreatureId` IN (52660, 53245, 53249);

-- Quest Chains
-- The Sanctuary Must Not Fall unlocks
UPDATE `quest_template_addon` SET `PrevQuestID`= 29198 WHERE `ID` IN (29125, 29126, 29147, 29148, 29164, 29165, 29101, 29122, 29161, 29162, 29123, 29127, 29149, 29163);
-- Through the Gates of Hell unlocks
UPDATE `quest_template_addon` SET `PrevQuestID`= 29201 WHERE `ID` IN (29139, 29143, 29138, 29137, 29304, 29141, 29142, 29128, 29181, 29179);
-- The Fate of Runetotem unlocks
UPDATE `quest_template_addon` SET `PrevQuestID`= 29202 WHERE `ID` IN (29248, 29246, 29247);
-- Druid of the Talon chain
UPDATE `quest_template_addon` SET `PrevQuestID`= 29182 WHERE `ID`= 29206;
UPDATE `quest_template_addon` SET `PrevQuestID`= 29206 WHERE `ID`= 29264;
UPDATE `quest_template_addon` SET `PrevQuestID`= 29264 WHERE `ID`= 29265;
UPDATE `quest_template_addon` SET `PrevQuestID`= 29265 WHERE `ID`= 29274;
UPDATE `quest_template_addon` SET `PrevQuestID`= 29272 WHERE `ID`= 29273;
UPDATE `quest_template_addon` SET `ExclusiveGroup`= 29274 WHERE `ID` IN (29274, 29273);
-- Fireplume Peak dailies
UPDATE `quest_template_addon` SET `PrevQuestID`= 29274 WHERE `ID` IN (29293, 29287, 29288, 29290, 29289, 29296);
UPDATE `quest_template_addon` SET `PrevQuestID`= 29283 WHERE `ID` IN (29243, 29305);
-- Crimson Lasher
UPDATE `quest_template_addon` SET `PrevQuestID`= 29245 WHERE `ID`= 29249;
UPDATE `quest_template_addon` SET `PrevQuestID`= 29249 WHERE `ID`= 29254;
UPDATE `quest_template_addon` SET `PrevQuestID`= 29254 WHERE `ID` IN (29299, 29257, 29255);
-- Shadow Warden dailies
-- UPDATE `quest_template_addon` SET `PrevQuestID`= 29214 WHERE `ID`= 29215;
UPDATE `quest_template_addon` SET `PrevQuestID`= 29215 WHERE `ID`= 29204;
UPDATE `quest_template_addon` SET `PrevQuestID`= 29204 WHERE `ID`= 29205;
UPDATE `quest_template_addon` SET `PrevQuestID`= 29205 WHERE `ID` IN (29211, 29192, 29159, 29189, 29160, 29210);

DELETE FROM `quest_template_addon` WHERE `ID` IN (29199, 29181, 29214, 29215, 29203);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES
(29199, 29198),
(29181, 29201),
(29214, 29201),
(29215, 29214),
(29203, 29279);

-- Pooling
SET @POOL := 645019;
DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOL+0 AND @POOL+11;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOL+0, 1, 'Molten Front Dalies 1'),
(@POOL+1, 1, 'Molten Front Dalies 2'),
(@POOL+2, 1, 'Molten Front Dalies 3'),
(@POOL+3, 1, 'Molten Front Dalies 4'),
(@POOL+4, 1, 'Molten Front Dalies 5'),
(@POOL+5, 1, 'Molten Front Dalies Pool 1'),
(@POOL+6, 2, 'Molten Front Dalies 6'),
(@POOL+7, 2, 'Molten Front Dalies 7'),
(@POOL+8, 2, 'Molten Front Dalies 8'),
(@POOL+9, 2, 'Molten Front Dalies 9'),
(@POOL+10, 2, 'Molten Front Dalies 10'),
(@POOL+11, 1, 'Molten Front Dalies Pool 2');

DELETE FROM `pool_quest` WHERE `pool_entry` BETWEEN @POOL+0 AND @POOL+11;
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
-- 0
(29139, @POOL+0, 'Molten Front - Aggressive Growth'),
(29143, @POOL+0, 'Molten Front - Wisp Away'),
-- 1
(29137, @POOL+1, 'Molten Front - Breach in the Defenses'),
(29304, @POOL+1, 'Molten Front - The Dogs of War'),
(29141, @POOL+1, 'Molten Front - The Harder They Fall'),
(29142, @POOL+1, 'Molten Front - Traitors Return'),
-- 2
(29248, @POOL+2, 'Molten Front - Releasing the Pressure'),
(29246, @POOL+2, 'Molten Front - Relieving the Pain'),
(29247, @POOL+2, 'Molten Front - Treating the Wounds'),
-- 3
(29123, @POOL+3, 'Molten Front - Rage Agains the Flames'),
(29127, @POOL+3, 'Molten Front - Rage Agains the Flames'),
(29149, @POOL+3, 'Molten Front - Rage Agains the Flames'),
(29163, @POOL+3, 'Molten Front - Rage Agains the Flames'),
-- 4
(29166, @POOL+4, 'Molten Front - Supplies for the Other Side'),
-- 6
(29125, @POOL+6, 'Molten Front - Between the Trees'),
(29126, @POOL+6, 'Molten Front - The Power of Malorne'),
-- 7
(29147, @POOL+7, 'Molten Front - Call the Flock'),
(29148, @POOL+7, 'Molten Front - Wings Aflame'),
-- 8
(29164, @POOL+8, 'Molten Front - Pefecting Your Howl'),
(29165, @POOL+8, 'Molten Front - The Call of the Pack'),
-- 9
(29101, @POOL+9, 'Molten Front - Pefecting Punting Season'),
(29122, @POOL+9, 'Molten Front - Pefecting Echoes of Nemesis'),
-- 10
(29161, @POOL+10, 'Molten Front - The Bears Up There'),
(29162, @POOL+10, 'Molten Front - Nature''s Blessing');


DELETE FROM `pool_pool` WHERE `pool_id` BETWEEN @POOL+0 AND @POOL+11;
INSERT INTO `pool_pool` (`pool_id`, `mother_pool`, `chance`, `description`) VALUES
(@POOL+3, @POOL+5, 0, 'Molten Front Dailies'),
(@POOL+4, @POOL+5, 0, 'Molten Front Dailies'),
(@POOL+6, @POOL+11, 0, 'Molten Front Dailies'),
(@POOL+7, @POOL+11, 0, 'Molten Front Dailies'),
(@POOL+8, @POOL+11, 0, 'Molten Front Dailies'),
(@POOL+9, @POOL+11, 0, 'Molten Front Dailies'),
(@POOL+10, @POOL+11, 0, 'Molten Front Dailies');
