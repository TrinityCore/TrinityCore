-- condition for Glyph of Shadow triggered (only in Shadowform)
DELETE FROM `conditions` WHERE `SourceEntry` IN (61792);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `Comment`) VALUES
  (17,61792,1,15473,'Glyph of Shadow triggered - Shadowform');