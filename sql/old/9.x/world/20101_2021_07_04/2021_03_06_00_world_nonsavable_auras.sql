ALTER TABLE `spell_custom_attr`
  MODIFY `entry` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'spell id',
  MODIFY `attributes` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'SpellCustomAttributes';

DELETE FROM `spell_custom_attr` WHERE `entry` IN (40075,55849,48517,48518,40120,33943,1066,165961);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(40075, 0x01000000), -- Fel Flak Fire
(55849, 0x01000000), -- Power Spark
(48517, 0x01000000), -- Eclipse (Solar)
(48518, 0x01000000), -- Eclipse (Lunar)
(40120, 0x01000000), -- Travel Form (Swift Flight)
(33943, 0x01000000), -- Travel Form (Flight)
(1066, 0x01000000), -- Travel Form (Aquatic)
(165961, 0x01000000); -- Travel Form (Stag)
