DELETE FROM `hotfix_blob` WHERE `VerifiedBuild`>0 AND `TableHash` IN (0x00CB59F4, 0xD9F1B527);

DELETE FROM `campaign` WHERE `VerifiedBuild`>0 AND `ID` IN (284, 270);
INSERT INTO `campaign` (`ID`, `Title`, `Description`, `UiTextureKitID`, `RewardQuestID`, `Prerequisite`, `Stalled`, `Completed`, `OnlyStallIf`, `UiQuestDetailsThemeID`, `Flags`, `DisplayPriority`, `SortAsNormalQuest`, `UseMinimalHeader`, `VerifiedBuild`) VALUES
(284, 'The War of Light and Shadow', '', 5768, 0, 135490, 34450, 143073, 0, 74, 0, 1202, 0, 0, 65893),
(270, 'Midnight', '', 5767, 0, 147611, 147611, 138637, 0, 73, 0, 1201, 0, 0, 65893);

DELETE FROM `campaign_locale` WHERE `VerifiedBuild`>0 AND `ID` IN (284, 270);
INSERT INTO `campaign_locale` (`ID`, `locale`, `Title_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(284, 'deDE', 'Der Krieg von Licht und Schatten', '', 65893),
(270, 'deDE', 'Midnight', '', 65893),
(284, 'esES', 'La guerra de la Luz y las Sombras', '', 65893),
(270, 'esES', 'Midnight', '', 65893),
(284, 'esMX', 'La guerra entre la luz y la sombra', '', 65893),
(270, 'esMX', 'Midnight', '', 65893),
(284, 'frFR', 'La guerre de l\’Ombre et de la Lumière', '', 65893),
(270, 'frFR', 'Midnight', '', 65893),
(284, 'itIT', 'La guerra tra la Luce e l\'Ombra', '', 65893),
(270, 'itIT', 'Midnight', '', 65893),
(284, 'koKR', '빛과 어둠의 전쟁', '', 65893),
(270, 'koKR', '한밤', '', 65893),
(284, 'ptBR', 'A Guerra de Luz e Sombra', '', 65893),
(270, 'ptBR', 'Midnight', '', 65893),
(284, 'ruRU', 'Война Света и Тьмы', '', 65893),
(270, 'ruRU', 'Midnight', '', 65893),
(284, 'zhCN', '光与影之战', '', 65893),
(270, 'zhCN', '至暗之夜', '', 65893),
(284, 'zhTW', '光與影之戰', '', 65893),
(270, 'zhTW', '至暗之夜', '', 65893);
