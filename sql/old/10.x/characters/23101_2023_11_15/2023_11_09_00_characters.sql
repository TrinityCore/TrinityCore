ALTER TABLE `characters` 
  ADD `personalTabardEmblemStyle` int NOT NULL DEFAULT -1 AFTER `lastLoginBuild`,
  ADD `personalTabardEmblemColor` int NOT NULL DEFAULT -1 AFTER `personalTabardEmblemStyle`,
  ADD `personalTabardBorderStyle` int NOT NULL DEFAULT -1 AFTER `personalTabardEmblemColor`,
  ADD `personalTabardBorderColor` int NOT NULL DEFAULT -1 AFTER `personalTabardBorderStyle`,
  ADD `personalTabardBackgroundColor` int NOT NULL DEFAULT -1 AFTER `personalTabardBorderColor`;
