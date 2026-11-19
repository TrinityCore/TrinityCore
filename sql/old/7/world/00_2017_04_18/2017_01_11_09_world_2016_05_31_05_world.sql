-- 
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `Id`=12836;

DELETE FROM `conditions` WHERE `SourceEntry`=12828 AND `SourceTypeOrReferenceId` IN (19, 20);
INSERT INTO `conditions` VALUES
(19, 0, 12828, 0, 0, 8, 0, 12827, 0, 0, 0, 0, 0, "", "Show mark for quest 'Ample Inspiration' only if quest 'Reclaimed Rations' is rewarded"),
(20, 0, 12828, 0, 0, 8, 0, 12827, 0, 0, 0, 0, 0, "", "Can accept quest 'Ample Inspiration' only if quest 'Reclaimed Rations' is rewarded");

DELETE FROM `quest_template_addon` WHERE `ID` IN (12862, 13060);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestId`) VALUES
(12862, 12824),
(13060, 12824);
