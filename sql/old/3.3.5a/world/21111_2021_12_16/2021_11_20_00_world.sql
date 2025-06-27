-- 
ALTER TABLE `spell_custom_attr`
  MODIFY `entry` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'spell id',
  MODIFY `attributes` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'SpellCustomAttributes';

SET @SPELL_ATTR0_CU_AURA_CANNOT_BE_SAVED := 16777216;

DELETE FROM `spell_custom_attr` WHERE `entry` IN (44413,40075,55849,73822,73828);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(44413, @SPELL_ATTR0_CU_AURA_CANNOT_BE_SAVED), -- Incanter's Absorption
(40075, @SPELL_ATTR0_CU_AURA_CANNOT_BE_SAVED), -- Fel Flak Fire
(55849, @SPELL_ATTR0_CU_AURA_CANNOT_BE_SAVED), -- Power Spark
(73822, @SPELL_ATTR0_CU_AURA_CANNOT_BE_SAVED), -- Hellscream's Warsong (ICC)
(73828, @SPELL_ATTR0_CU_AURA_CANNOT_BE_SAVED); -- Strength of Wrynn (ICC)
