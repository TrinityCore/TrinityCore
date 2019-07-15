ALTER TABLE `animation_data` MODIFY COLUMN `BehaviorID` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ID`;
ALTER TABLE `animation_data` MODIFY COLUMN `BehaviorTier` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `BehaviorID`;
ALTER TABLE `animation_data` MODIFY COLUMN `Fallback` int(11) NOT NULL DEFAULT 0 AFTER `BehaviorTier`;

ALTER TABLE `spell_item_enchantment` MODIFY COLUMN `TransmogPlayerConditionID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `EffectScalingPoints3`;
