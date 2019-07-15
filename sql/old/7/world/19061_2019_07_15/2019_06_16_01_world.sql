ALTER TABLE `creature_template_model` DROP PRIMARY KEY;
ALTER TABLE `creature_template_model` ADD PRIMARY KEY (`CreatureID`, `Idx`);
