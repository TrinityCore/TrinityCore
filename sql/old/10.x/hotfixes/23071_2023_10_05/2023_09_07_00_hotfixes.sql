ALTER TABLE `chr_classes` MODIFY `RolesMask` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `ClassColorB`;

ALTER TABLE `chr_customization_element` ADD `ParticleColorID` int NOT NULL DEFAULT 0 AFTER `AnimKitID`;

ALTER TABLE `creature_model_data` ADD `WalkSpeed` float NOT NULL DEFAULT 0 AFTER `FileDataID`;
ALTER TABLE `creature_model_data` ADD `RunSpeed` float NOT NULL DEFAULT 0 AFTER `WalkSpeed`;

ALTER TABLE `taxi_nodes` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `CharacterBitNumber`;

ALTER TABLE `taxi_path_node` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `ContinentID`;
