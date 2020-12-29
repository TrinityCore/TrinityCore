-- Missing Page Text

DELETE FROM `page_text` WHERE `ID` IN (7154, 4874, 4958);
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES 
(7154, '...of sea, spirit and self...', 0, 0, 0, 0),
(4874, 'Care: debris.', 0, 0, 0, 0),
(4958, 'ATTACK! $B$BPUT FIST IN FACE! $B$BCONTINUE THE ATTACKING!', 0, 0, 0, 0);