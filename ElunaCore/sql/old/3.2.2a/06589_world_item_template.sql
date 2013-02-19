ALTER TABLE `item_template`
    ADD COLUMN `Faction` int(11) UNSIGNED DEFAULT '0' NOT NULL AFTER `Flags`;

ALTER TABLE item_template
  CHANGE COLUMN ItemLevel ItemLevel smallint(5) unsigned NOT NULL DEFAULT 0;