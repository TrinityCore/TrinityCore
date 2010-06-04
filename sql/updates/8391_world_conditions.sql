-- ----------------------------
-- Table structure for conditions
-- ----------------------------
CREATE TABLE `conditions` (
  `SourceTypeOrReferenceId` mediumint(8) NOT NULL DEFAULT '0',
  `SourceGroup` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `SourceEntry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `ElseGroup` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `ConditionTypeOrReference` mediumint(8) NOT NULL DEFAULT '0',
  `ConditionValue1` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `ConditionValue2` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `ConditionValue3` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `ErrorTextId` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Condition System';

-- convert loot conditions
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 1,creature_loot_template.entry,creature_loot_template.item,creature_loot_template.lootcondition,creature_loot_template.condition_value1,creature_loot_template.condition_value2 FROM creature_loot_template WHERE creature_loot_template.lootcondition>0;
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 2,disenchant_loot_template.entry,disenchant_loot_template.item,disenchant_loot_template.lootcondition,disenchant_loot_template.condition_value1,disenchant_loot_template.condition_value2 FROM disenchant_loot_template WHERE disenchant_loot_template.lootcondition>0;
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 3,fishing_loot_template.entry,fishing_loot_template.item,fishing_loot_template.lootcondition,fishing_loot_template.condition_value1,fishing_loot_template.condition_value2 FROM fishing_loot_template WHERE fishing_loot_template.lootcondition>0;
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 4,gameobject_loot_template.entry,gameobject_loot_template.item,gameobject_loot_template.lootcondition,gameobject_loot_template.condition_value1,gameobject_loot_template.condition_value2 FROM gameobject_loot_template WHERE gameobject_loot_template.lootcondition>0;
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 5,item_loot_template.entry,item_loot_template.item,item_loot_template.lootcondition,item_loot_template.condition_value1,item_loot_template.condition_value2 FROM item_loot_template WHERE item_loot_template.lootcondition>0;
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 6,mail_loot_template.entry,mail_loot_template.item,mail_loot_template.lootcondition,mail_loot_template.condition_value1,mail_loot_template.condition_value2 FROM mail_loot_template WHERE mail_loot_template.lootcondition>0;
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 7,milling_loot_template.entry,milling_loot_template.item,milling_loot_template.lootcondition,milling_loot_template.condition_value1,milling_loot_template.condition_value2 FROM milling_loot_template WHERE milling_loot_template.lootcondition>0;
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 8,pickpocketing_loot_template.entry,pickpocketing_loot_template.item,pickpocketing_loot_template.lootcondition,pickpocketing_loot_template.condition_value1,pickpocketing_loot_template.condition_value2 FROM pickpocketing_loot_template WHERE pickpocketing_loot_template.lootcondition>0;
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 9,prospecting_loot_template.entry,prospecting_loot_template.item,prospecting_loot_template.lootcondition,prospecting_loot_template.condition_value1,prospecting_loot_template.condition_value2 FROM prospecting_loot_template WHERE prospecting_loot_template.lootcondition>0;
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 10,reference_loot_template.entry,reference_loot_template.item,reference_loot_template.lootcondition,reference_loot_template.condition_value1,reference_loot_template.condition_value2 FROM reference_loot_template WHERE reference_loot_template.lootcondition>0;
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 11,skinning_loot_template.entry,skinning_loot_template.item,skinning_loot_template.lootcondition,skinning_loot_template.condition_value1,skinning_loot_template.condition_value2 FROM skinning_loot_template WHERE skinning_loot_template.lootcondition>0;
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 12,spell_loot_template.entry,spell_loot_template.item,spell_loot_template.lootcondition,spell_loot_template.condition_value1,spell_loot_template.condition_value2 FROM spell_loot_template WHERE spell_loot_template.lootcondition>0;

-- convert spell script targets
INSERT INTO conditions (SourceTypeOrReferenceId,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 13,spell_script_target.entry,18,spell_script_target.type,spell_script_target.targetEntry FROM spell_script_target;

-- convert gossip menu conditions
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 14,gossip_menu.entry,gossip_menu.text_id,gossip_menu.cond_1,gossip_menu.cond_1_val_1,gossip_menu.cond_1_val_2 FROM gossip_menu WHERE gossip_menu.cond_1>0;
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 14,gossip_menu.entry,gossip_menu.text_id,gossip_menu.cond_2,gossip_menu.cond_2_val_1,gossip_menu.cond_2_val_2 FROM gossip_menu WHERE gossip_menu.cond_2>0;

-- convert gossip menu options conditions
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 15,gossip_menu_option.menu_id,gossip_menu_option.id,gossip_menu_option.cond_1,gossip_menu_option.cond_1_val_1,gossip_menu_option.cond_1_val_2 FROM gossip_menu_option WHERE gossip_menu_option.cond_1>0;
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 15,gossip_menu_option.menu_id,gossip_menu_option.id,gossip_menu_option.cond_2,gossip_menu_option.cond_2_val_1,gossip_menu_option.cond_2_val_2 FROM gossip_menu_option WHERE gossip_menu_option.cond_2>0;
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 15,gossip_menu_option.menu_id,gossip_menu_option.id,gossip_menu_option.cond_3,gossip_menu_option.cond_3_val_1,gossip_menu_option.cond_3_val_2 FROM gossip_menu_option WHERE gossip_menu_option.cond_3>0;

-- convert item required target
INSERT INTO conditions (SourceTypeOrReferenceId,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) SELECT 18,item_required_target.entry,24,item_required_target.type,item_required_target.targetEntry FROM item_required_target;

-- drop no more needed condition fields

-- drop not used loot conditions
ALTER TABLE creature_loot_template DROP COLUMN lootcondition,DROP COLUMN condition_value1,DROP COLUMN condition_value2;
ALTER TABLE disenchant_loot_template DROP COLUMN lootcondition,DROP COLUMN condition_value1,DROP COLUMN condition_value2;
ALTER TABLE fishing_loot_template DROP COLUMN lootcondition,DROP COLUMN condition_value1,DROP COLUMN condition_value2;
ALTER TABLE gameobject_loot_template DROP COLUMN lootcondition,DROP COLUMN condition_value1,DROP COLUMN condition_value2;
ALTER TABLE item_loot_template DROP COLUMN lootcondition,DROP COLUMN condition_value1,DROP COLUMN condition_value2;
ALTER TABLE mail_loot_template DROP COLUMN lootcondition,DROP COLUMN condition_value1,DROP COLUMN condition_value2;
ALTER TABLE milling_loot_template DROP COLUMN lootcondition,DROP COLUMN condition_value1,DROP COLUMN condition_value2;
ALTER TABLE pickpocketing_loot_template DROP COLUMN lootcondition,DROP COLUMN condition_value1,DROP COLUMN condition_value2;
ALTER TABLE prospecting_loot_template DROP COLUMN lootcondition,DROP COLUMN condition_value1,DROP COLUMN condition_value2;
ALTER TABLE reference_loot_template DROP COLUMN lootcondition,DROP COLUMN condition_value1,DROP COLUMN condition_value2;
ALTER TABLE skinning_loot_template DROP COLUMN lootcondition,DROP COLUMN condition_value1,DROP COLUMN condition_value2;
ALTER TABLE spell_loot_template DROP COLUMN lootcondition,DROP COLUMN condition_value1,DROP COLUMN condition_value2;

-- drop spell_script_target table, it is built into conditions
DROP TABLE IF EXISTS `spell_script_target`;

-- drop item_required_target table, it is built into conditions
DROP TABLE IF EXISTS `item_required_target`;

-- drop not used gossip conditions
ALTER TABLE gossip_menu DROP COLUMN cond_1,DROP COLUMN cond_1_val_1,DROP COLUMN cond_1_val_2,DROP COLUMN cond_2,DROP COLUMN cond_2_val_1,DROP COLUMN cond_2_val_2;
ALTER TABLE gossip_menu_option DROP COLUMN cond_1,DROP COLUMN cond_1_val_1,DROP COLUMN cond_1_val_2,DROP COLUMN cond_2,DROP COLUMN cond_2_val_1,DROP COLUMN cond_2_val_2;
