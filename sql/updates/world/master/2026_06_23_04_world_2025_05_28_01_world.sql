-- Update "Return to Thrallmar" Quest requirements
INSERT INTO `quest_template_addon` (`ID`,`PrevQuestID`) VALUES
(10388,10129)
  ON DUPLICATE KEY UPDATE `PrevQuestID`=10129;
