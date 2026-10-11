SET @BTDID := 10000000;

-- Broadcast text duration
DELETE FROM `broadcast_text_duration` WHERE (`VerifiedBuild`<0 AND `Locale`=1 AND `BroadcastTextID` IN (273753,277029));
INSERT INTO `broadcast_text_duration` (`ID`, `Locale`, `Duration`, `BroadcastTextID`, `VerifiedBuild`) VALUES
(@BTDID+0, 1, 3050, 273753, -63003),
(@BTDID+1, 1, 4200, 277029, -63003);
