ALTER TABLE `spell_target_position` DROP PRIMARY KEY;
ALTER TABLE `spell_target_position` ADD `OrderIndex` int NOT NULL DEFAULT '0' AFTER `EffectIndex`;
ALTER TABLE `spell_target_position` ADD PRIMARY KEY(`ID`,`EffectIndex`,`OrderIndex`);
