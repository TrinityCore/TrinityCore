DELETE FROM `spell_proc` WHERE `SpellId` IN (17670,50908,58501,-1120);
INSERT INTO `spell_proc` (`SpellId`, `AttributesMask`) VALUES
(17670, 0x10),      -- Argent Dawn Commission
(50908, 0x20),      -- Seal of Onslaught
(58501, 0x40),      -- Iron Boot Flask
(-1120, 0x01|0x40); -- Drain Soul

UPDATE `spell_proc` SET `AttributesMask`=`AttributesMask`|0x10 WHERE `SpellId`= 34827; -- Water Shield
UPDATE `spell_proc` SET `AttributesMask`=`AttributesMask`|0x20 WHERE `SpellId`=-52795; -- Borrowed Time
UPDATE `spell_proc` SET `AttributesMask`=`AttributesMask`|0x20 WHERE `SpellId`=-63156; -- Decimation
