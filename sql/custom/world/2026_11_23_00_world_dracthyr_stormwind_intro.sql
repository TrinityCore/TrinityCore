-- ============================================================================
-- Custom Fix: Alliance Dracthyr Introductory Questline in Stormwind City
-- Quests: 84424, 65286 (Draconic Connections), 66513 (Ground Leave)
-- NPCs: Chromie (167032), Scalecommander Azurathel (189603)
-- ============================================================================

UPDATE `creature_template`
SET `npcflag` = `npcflag` | 3
WHERE `entry` = 167032;

INSERT IGNORE INTO `creature_questender` (`id`, `quest`) VALUES
(167032, 84424);

UPDATE `creature_template`
SET `npcflag` = `npcflag` | 3
WHERE `entry` = 189603;

DELETE FROM `creature`
WHERE `id` = 189603 AND `guid` != 9004556;

UPDATE `creature`
SET `PhaseId` = 0,
    `PhaseGroup` = 0,
    `spawnDifficulties` = ''
WHERE `guid` = 9004556;

INSERT IGNORE INTO `creature_queststarter` (`id`, `quest`) VALUES
(189603, 65286),
(189603, 66513);

INSERT IGNORE INTO `creature_questender` (`id`, `quest`) VALUES
(189603, 65286),
(189603, 66513);

INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`)
VALUES (66513, 65286)
ON DUPLICATE KEY UPDATE `PrevQuestID` = 65286;
