/*
ALTER TABLE `spell_proc`
  CHANGE `spellId` `SpellId` int(11) NOT NULL DEFAULT 0 FIRST,
  CHANGE `schoolMask` `SchoolMask` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `SpellId`,
  CHANGE `spellFamilyName` `SpellFamilyName` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `SchoolMask`,
  CHANGE `spellFamilyMask0` `SpellFamilyMask0` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SpellFamilyName`,
  CHANGE `spellFamilyMask1` `SpellFamilyMask1` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SpellFamilyMask0`,
  CHANGE `spellFamilyMask2` `SpellFamilyMask2` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SpellFamilyMask1`,
  CHANGE `typeMask` `ProcFlags` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SpellFamilyMask2`,
  CHANGE `spellTypeMask` `SpellTypeMask` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ProcFlags`,
  CHANGE `spellPhaseMask` `SpellPhaseMask` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SpellTypeMask`,
  CHANGE `hitMask` `HitMask` int(10) unsigned NOT NULL DEFAULT 0 AFTER `SpellPhaseMask`,
  CHANGE `attributesMask` `AttributesMask` int(10) unsigned NOT NULL DEFAULT 0 AFTER `HitMask`,
  CHANGE `ratePerMinute` `ProcsPerMinute` float NOT NULL DEFAULT 0 AFTER `AttributesMask`,
  CHANGE `chance` `Chance` float NOT NULL DEFAULT 0 AFTER `ProcsPerMinute`,
  CHANGE `cooldown` `Cooldown` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Chance`,
  CHANGE `charges` `Charges` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `Cooldown`;
*/
