ALTER TABLE `jump_charge_params`
  ADD `minHeight` float AFTER `jumpGravity`,
  ADD `maxHeight` float AFTER `minHeight`,
  ADD `unlimitedSpeed` tinyint(1) NOT NULL DEFAULT 0 AFTER `treatSpeedAsMoveTimeSeconds`;

UPDATE `jump_charge_params` SET `maxHeight`=0.001,`unlimitedSpeed`=1 WHERE `id`=2; -- Infernal Strike
UPDATE `jump_charge_params` SET `maxHeight`=0.001 WHERE `id`=9; -- Metamorphosis
UPDATE `jump_charge_params` SET `minHeight`=6 WHERE `id`=17; -- Heroic Leap
UPDATE `jump_charge_params` SET `speed`=50,`treatSpeedAsMoveTimeSeconds`=0 WHERE `id`=18; -- Harpoon
UPDATE `jump_charge_params` SET `minHeight`=1.5 WHERE `id` IN (529,530,531); -- Windrunner
UPDATE `jump_charge_params` SET `minHeight`=5 WHERE `id`=566; -- Invigorating Field
UPDATE `jump_charge_params` SET `minHeight`=1,`speed`=70,`treatSpeedAsMoveTimeSeconds`=0,`unlimitedSpeed`=1 WHERE `id`=574; -- Earthen Grasp
UPDATE `jump_charge_params` SET `minHeight`=3,`speed`=60,`treatSpeedAsMoveTimeSeconds`=0,`unlimitedSpeed`=1 WHERE `id`=592; -- Stonecrash
UPDATE `jump_charge_params` SET `minHeight`=5,`speed`=0.75 WHERE `id`=626; -- Necrotic Claws
UPDATE `jump_charge_params` SET `minHeight`=3 WHERE `id`=647; -- Pounce
UPDATE `jump_charge_params` SET `minHeight`=3,`speed`=18,`treatSpeedAsMoveTimeSeconds`=0 WHERE `id`=648; -- Defensive Bulwark
UPDATE `jump_charge_params` SET `minHeight`=3 WHERE `id`=649; -- Ambush
UPDATE `jump_charge_params` SET `minHeight`=3 WHERE `id`=660; -- Heated Swings
UPDATE `jump_charge_params` SET `minHeight`=5 WHERE `id`=661; -- Might of the Forge
UPDATE `jump_charge_params` SET `speed`=50,`treatSpeedAsMoveTimeSeconds`=0 WHERE `id`=709; -- Fiery Focus
UPDATE `jump_charge_params` SET `speed`=1 WHERE `id` IN (713,714);
UPDATE `jump_charge_params` SET `minHeight`=12 WHERE `id`=719; -- Cast Away
UPDATE `jump_charge_params` SET `maxHeight`=10 WHERE `id`=720; -- Cast Away
UPDATE `jump_charge_params` SET `maxHeight`=4 WHERE `id`=959; -- Chains of Oppression

DELETE FROM `jump_charge_params` WHERE `id` IN (110,169,175);
INSERT INTO `jump_charge_params` (`id`,`speed`,`treatSpeedAsMoveTimeSeconds`,`unlimitedSpeed`,`minHeight`,`maxHeight`,`spellVisualId`,`progressCurveId`,`parabolicCurveId`,`triggerSpellId`) VALUES
(110,50,0,0,8,NULL,NULL,NULL,NULL,NULL), -- Toxic Leap
(169,50,0,0,NULL,NULL,NULL,NULL,NULL,NULL), -- Ravaging Leap
(175,1,1,0,6,NULL,NULL,NULL,NULL,NULL); -- Dark Leap

ALTER TABLE `jump_charge_params` DROP `jumpGravity`;

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_volkaal_toxic_leap';
