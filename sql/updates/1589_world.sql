# 1589
-- Spiritual Attunement
UPDATE `spell_proc_event` SET `procFlags` = `procFlags`|0x80000 WHERE `entry` IN ('31785','33776');
