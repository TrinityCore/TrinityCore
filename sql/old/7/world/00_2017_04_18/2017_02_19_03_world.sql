ALTER TABLE `creature_equip_template`
  ADD `AppearanceModID1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ItemID1`,
  ADD `ItemVisual1` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AppearanceModID1`,
  ADD `AppearanceModID2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ItemID2`,
  ADD `ItemVisual2` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AppearanceModID2`,
  ADD `AppearanceModID3` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `ItemID3`,
  ADD `ItemVisual3` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `AppearanceModID3`;
