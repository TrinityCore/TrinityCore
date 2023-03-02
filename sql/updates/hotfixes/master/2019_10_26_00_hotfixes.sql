ALTER TABLE `item_appearance` ADD `SubclassID` int(11) NOT NULL DEFAULT 0 AFTER `DisplayType`;

ALTER TABLE `item_sparse` CHANGE `ZoneBound` `ZoneBound1` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `InstanceBound`;
ALTER TABLE `item_sparse` ADD `ZoneBound2` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `ZoneBound1`;

ALTER TABLE `power_type` MODIFY `ID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `CostGlobalStringTag`;

ALTER TABLE `spell_effect` MODIFY `EffectAura` smallint(6) NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `spell_misc` MODIFY `Attributes1` int(11) NOT NULL DEFAULT 0 AFTER `ID`;
ALTER TABLE `spell_misc` MODIFY `Attributes2` int(11) NOT NULL DEFAULT 0 AFTER `Attributes1`;
ALTER TABLE `spell_misc` MODIFY `Attributes3` int(11) NOT NULL DEFAULT 0 AFTER `Attributes2`;
ALTER TABLE `spell_misc` MODIFY `Attributes4` int(11) NOT NULL DEFAULT 0 AFTER `Attributes3`;
ALTER TABLE `spell_misc` MODIFY `Attributes5` int(11) NOT NULL DEFAULT 0 AFTER `Attributes4`;
ALTER TABLE `spell_misc` MODIFY `Attributes6` int(11) NOT NULL DEFAULT 0 AFTER `Attributes5`;
ALTER TABLE `spell_misc` MODIFY `Attributes7` int(11) NOT NULL DEFAULT 0 AFTER `Attributes6`;
ALTER TABLE `spell_misc` MODIFY `Attributes8` int(11) NOT NULL DEFAULT 0 AFTER `Attributes7`;
ALTER TABLE `spell_misc` MODIFY `Attributes9` int(11) NOT NULL DEFAULT 0 AFTER `Attributes8`;
ALTER TABLE `spell_misc` MODIFY `Attributes10` int(11) NOT NULL DEFAULT 0 AFTER `Attributes9`;
ALTER TABLE `spell_misc` MODIFY `Attributes11` int(11) NOT NULL DEFAULT 0 AFTER `Attributes10`;
ALTER TABLE `spell_misc` MODIFY `Attributes12` int(11) NOT NULL DEFAULT 0 AFTER `Attributes11`;
ALTER TABLE `spell_misc` MODIFY `Attributes13` int(11) NOT NULL DEFAULT 0 AFTER `Attributes12`;
ALTER TABLE `spell_misc` MODIFY `Attributes14` int(11) NOT NULL DEFAULT 0 AFTER `Attributes13`;

ALTER TABLE `spell_visual_kit` MODIFY `FallbackPriority` tinyint(4) NOT NULL DEFAULT 0 AFTER `Flags`;
ALTER TABLE `spell_visual_kit` MODIFY `FallbackSpellVisualKitId` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `FallbackPriority`;

ALTER TABLE `transmog_set` ADD `PlayerConditionID` int(11) NOT NULL DEFAULT 0 AFTER `UiOrder`;

ALTER TABLE `unit_power_bar` MODIFY `StartPower` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `MaxPower`;

DROP TABLE `item_upgrade`;
DROP TABLE `ruleset_item_upgrade`;
DROP TABLE `world_safe_locs`;
DROP TABLE `world_safe_locs_locale`;
