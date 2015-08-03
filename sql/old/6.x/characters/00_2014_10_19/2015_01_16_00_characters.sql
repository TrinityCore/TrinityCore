--
-- Table structure for table `character_aura_effect`
--

DROP TABLE IF EXISTS `character_aura_effect`;
CREATE TABLE `character_aura_effect` (
  `guid` bigint(20) unsigned NOT NULL COMMENT 'Global Unique Identifier',
  `casterGuid` binary(16) NOT NULL COMMENT 'Full Global Unique Identifier' ,
  `itemGuid` binary(16) NOT NULL,
  `spell` int(10) unsigned NOT NULL ,
  `effectMask` int(10) unsigned NOT NULL,
  `effectIndex` tinyint(3) unsigned NOT NULL,
  `amount` int(11) NOT NULL DEFAULT 0,
  `baseAmount` int(11) NOT NULL DEFAULT 0,
PRIMARY KEY (`guid`,`casterGuid`,`itemGuid`,`spell`,`effectMask`,`effectIndex`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

--
-- Table structure for table `pet_aura_effect`
--

DROP TABLE IF EXISTS `pet_aura_effect`;
CREATE TABLE `pet_aura_effect` (
  `guid` int(10) unsigned NOT NULL COMMENT 'Global Unique Identifier',
  `casterGuid` binary(16) NOT NULL COMMENT 'Full Global Unique Identifier' ,
  `spell` int(10) unsigned NOT NULL,
  `effectMask` int(10) unsigned NOT NULL,
  `effectIndex` tinyint(3) unsigned NOT NULL,
  `amount` int(11) NOT NULL DEFAULT 0,
  `baseAmount` int(11) NOT NULL DEFAULT 0,
PRIMARY KEY (`guid`,`casterGuid`,`spell`,`effectMask`,`effectIndex`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Pet System';

TRUNCATE `character_aura`;
ALTER TABLE `character_aura`
  CHANGE `caster_guid` `casterGuid` binary(16) NOT NULL COMMENT 'Full Global Unique Identifier',
  CHANGE `item_guid` `itemGuid` binary(16) NOT NULL,
  CHANGE `spell` `spell` int(10) unsigned NOT NULL,
  CHANGE `effect_mask` `effectMask` int(10) unsigned NOT NULL,
  CHANGE `recalculate_mask` `recalculateMask` int(10) unsigned NOT NULL DEFAULT 0,
  CHANGE `stackcount` `stackCount` tinyint(3) unsigned NOT NULL DEFAULT 1,
  DROP `amount0`,
  DROP `amount1`,
  DROP `amount2`,
  DROP `base_amount0`,
  DROP `base_amount1`,
  DROP `base_amount2`,
  CHANGE `maxDuration` `maxDuration` int(11) NOT NULL DEFAULT 0,
  CHANGE `remainTime` `remainTime` int(11) NOT NULL DEFAULT 0,
  CHANGE `remainCharges` `remainCharges` tinyint(3) unsigned NOT NULL DEFAULT 0;

TRUNCATE `pet_aura`;
ALTER TABLE `pet_aura`
  CHANGE `caster_guid` `casterGuid` binary(16) NOT NULL COMMENT 'Full Global Unique Identifier',
  CHANGE `spell` `spell` int(10) unsigned NOT NULL,
  CHANGE `effect_mask` `effectMask` int(10) unsigned NOT NULL,
  CHANGE `recalculate_mask` `recalculateMask` int(10) unsigned NOT NULL DEFAULT 0,
  CHANGE `stackcount` `stackCount` tinyint(3) unsigned NOT NULL DEFAULT 1,
  DROP `amount0`,
  DROP `amount1`,
  DROP `amount2`,
  DROP `base_amount0`,
  DROP `base_amount1`,
  DROP `base_amount2`,
  CHANGE `maxDuration` `maxDuration` int(11) NOT NULL DEFAULT 0,
  CHANGE `remainTime` `remainTime` int(11) NOT NULL DEFAULT 0,
  CHANGE `remainCharges` `remainCharges` tinyint(3) unsigned NOT NULL DEFAULT 0;
