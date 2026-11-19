ALTER TABLE `broadcast_text_duration` MODIFY `BroadcastTextID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `Duration`;

ALTER TABLE `chr_customization_option`
  DROP `ChrRacesID`,
  DROP `Sex`;

ALTER TABLE `difficulty` ADD `Unknown1105` int NOT NULL DEFAULT 0 AFTER `GroupSizeSpellPointsCurveID`;

ALTER TABLE `lfg_dungeons` ADD `MaxPremadeGroupSize` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `MentorCharLevel`;

ALTER TABLE `spell_misc` ADD `Attributes16` int NOT NULL DEFAULT 0 AFTER `Attributes15`;
