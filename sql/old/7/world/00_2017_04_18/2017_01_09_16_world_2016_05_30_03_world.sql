--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=50232;
INSERT INTO `conditions` VALUES
(13, 1, 50232, 0, 1, 31, 0, 3, 28236, 0, 0, 0, 0, "", "Searing Wrath target can be Azure Ring Captain"),
(13, 1, 50232, 0, 2, 31, 0, 3, 27638, 0, 0, 0, 0, "", "Searing Wrath target can be Azure Ring Guardian"),
(13, 1, 50232, 0, 3, 31, 0, 3, 28276, 0, 0, 0, 0, "", "Searing Wrath target can be Greater Lay Whelp"),
(13, 1, 50232, 0, 4, 31, 0, 3, 27656, 0, 0, 0, 0, "", "Searing Wrath target can be Eregos");
