ALTER TABLE `playerchoice`
  ADD COLUMN `ShowChoicesAsGrid` tinyint(1) NOT NULL DEFAULT 0 AFTER `RequiresSelection`,
  ADD COLUMN `HideAnswerArt` tinyint(1) NOT NULL DEFAULT 0 AFTER `ShowChoicesAsGrid`,
  ADD COLUMN `ShowChoicesAsColumns` tinyint(1) NOT NULL DEFAULT 0 AFTER `HideAnswerArt`;
