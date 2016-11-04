ALTER TABLE `character_cuf_profiles`
  CHANGE `unk146` `topPoint` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Frame top alignment' AFTER `boolOptions`,
  CHANGE `unk147` `bottomPoint` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Frame bottom alignment' AFTER `topPoint`,
  CHANGE `unk148` `leftPoint` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Frame left alignment' AFTER `bottomPoint`,
  CHANGE `unk150` `topOffset` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Frame position offset from top' AFTER `leftPoint`,
  CHANGE `unk152` `bottomOffset` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Frame position offset from bottom' AFTER `topOffset`,
  CHANGE `unk154` `leftOffset` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Frame position offset from left' AFTER `bottomOffset`;

UPDATE `character_cuf_profiles` SET `boolOptions`=((`boolOptions`&0x1800000)<<2)|(`boolOptions`&0x67FFFFF);
