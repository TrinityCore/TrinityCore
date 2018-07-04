-- 
DELETE FROM `conditions` WHERE `SourceEntry` IN (22777, 22776, 22775) AND `SourceTypeOrReferenceId`=23;
INSERT INTO `conditions` VALUES
(23, 16444, 22777, 0, 0, 9, 0, 9067, 0, 0, 0, 0, 0, "", "Bundle of Fireworks can be bought only if on quest 'The Party Never Ends'"),
(23, 16443, 22776, 0, 0, 9, 0, 9067, 0, 0, 0, 0, 0, "", "Springpaw Appetizers can be bought only if on quest 'The Party Never Ends'"),
(23, 16442, 22775, 0, 0, 9, 0, 9067, 0, 0, 0, 0, 0, "", "Suntouched Special Reserve can be bought only if on quest 'The Party Never Ends'");

DELETE FROM `conditions` WHERE `SourceEntry` IN (1939, 1941, 1942) AND `SourceTypeOrReferenceId`=23;
INSERT INTO `conditions` VALUES
(23, 465, 1939, 0, 0, 9, 0, 116, 0, 0, 0, 0, 0, "", "Skin of Sweet Rum can be bought only if on quest 'Dry Times'"),
(23, 277, 1941, 0, 0, 9, 0, 116, 0, 0, 0, 0, 0, "", "Cask of Merlot can be bought only if on quest 'Dry Times'"),
(23, 274, 1942, 0, 0, 9, 0, 116, 0, 0, 0, 0, 0, "", "Bottle of Moonshine can be bought only if on quest 'Dry Times'");
