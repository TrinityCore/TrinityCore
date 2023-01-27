-- Stabled Argent Warhorse
DELETE FROM `conditions` WHERE `SourceGroup`=33870 AND `SourceTypeOrReferenceId`=18 AND SourceEntry=63663; 
INSERT INTO `conditions` VALUES (18,33870,63663,0,0,9,0,13664,0,0,0,0,0,'','Spellclick requires quest 13664 active');
