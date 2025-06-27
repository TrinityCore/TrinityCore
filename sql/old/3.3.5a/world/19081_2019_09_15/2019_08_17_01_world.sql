ALTER TABLE `spell_proc` ADD `DisableEffectsMask` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AttributesMask`;

UPDATE `spell_proc` SET `DisableEffectsMask`=((`AttributesMask` >> 4) & 0x7);
UPDATE `spell_proc` SET `AttributesMask`=(`AttributesMask` & 0xF);
