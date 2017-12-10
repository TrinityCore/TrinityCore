ALTER TABLE `spell_enchant_proc_data`
    CHANGE `entry` `EnchantID` int(10) UNSIGNED NOT NULL,
    CHANGE `customChance` `Chance` float DEFAULT '0' NOT NULL,
    CHANGE `PPMChance` `ProcsPerMinute` float DEFAULT '0' NOT NULL,
    CHANGE `procEx` `HitMask` int(10) UNSIGNED DEFAULT '0' NOT NULL,
    ADD COLUMN `AttributesMask` int(10) UNSIGNED DEFAULT '0' NOT NULL AFTER `HitMask`;
