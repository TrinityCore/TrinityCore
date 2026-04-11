ALTER TABLE `jump_charge_params`
  ADD `minHeight` float AFTER `jumpGravity`,
  ADD `maxHeight` float AFTER `minHeight`,
  ADD `unlimitedSpeed` tinyint(1) NOT NULL DEFAULT 0 AFTER `treatSpeedAsMoveTimeSeconds`;

ALTER TABLE `jump_charge_params` DROP `jumpGravity`;

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

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_volkaal_toxic_leap';

UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `action_type`=97; -- wipe old and bad data

UPDATE `smart_scripts` SET `action_param2`=3,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=-5000044 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=10,`action_param4`=0 WHERE `entryorguid`=-651795 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=9,`action_param4`=0 WHERE `entryorguid`=-376334 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=9,`action_param4`=0 WHERE `entryorguid`=-376334 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=9,`action_param4`=0 WHERE `entryorguid`=-376319 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=9,`action_param4`=0 WHERE `entryorguid`=-376319 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=9,`action_param4`=0 WHERE `entryorguid`=-376306 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=9,`action_param4`=0 WHERE `entryorguid`=-376306 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=10,`action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=24742 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=26608 AND `source_type`=0 AND `id`=3; -- this script is wrong, should not be a jump. movement is done by entering a dummy vehicle at destination
UPDATE `smart_scripts` SET `action_param2`=10,`action_param2`=0,`action_param3`=6,`action_param4`=0 WHERE `entryorguid`=27409 AND `source_type`=0 AND `id`=3;
UPDATE `smart_scripts` SET `action_param2`=10,`action_param2`=0,`action_param3`=6,`action_param4`=0 WHERE `entryorguid`=27409 AND `source_type`=0 AND `id`=4;
UPDATE `smart_scripts` SET `action_param2`=36,`action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=28665 AND `source_type`=0 AND `id`=14;
UPDATE `smart_scripts` SET `action_param2`=16,`action_param2`=5,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=28996 AND `source_type`=0 AND `id`=4;
UPDATE `smart_scripts` SET `action_param2`=30,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=29895 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=3,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=30020 AND `source_type`=0 AND `id`=3;
UPDATE `smart_scripts` SET `action_param2`=3,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=30022 AND `source_type`=0 AND `id`=3;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=35118 AND `source_type`=0 AND `id`=3; -- what is this script? they don't jump (and why is something looking like spawn specific script bound to creature id?)
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=35118 AND `source_type`=0 AND `id`=4; -- what is this script? they don't jump (and why is something looking like spawn specific script bound to creature id?)
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=1,`action_param4`=0 WHERE `entryorguid`=77695 AND `source_type`=0 AND `id`=3;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=1,`action_param4`=0 WHERE `entryorguid`=77695 AND `source_type`=0 AND `id`=5;
UPDATE `smart_scripts` SET `action_param1`=28,`action_param2`=0,`action_param3`=30,`action_param4`=0 WHERE `entryorguid`=2743901 AND `source_type`=9 AND `id`=12;
UPDATE `smart_scripts` SET `action_param1`=63,`action_param2`=15,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=2905000 AND `source_type`=9 AND `id`=5;
UPDATE `smart_scripts` SET `action_type`=11,`action_param1`=60591,`action_param2`=0,`target_type`=1,`target_x`=0,`target_y`=0,`target_z`=0,`target_o`=0,`comment`='Thane Banahogg - On Script - Cast Leap' WHERE `entryorguid`=3127700 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488400 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488400 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488401 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488401 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488402 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488402 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488403 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488403 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488404 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488404 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488405 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488405 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488406 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488406 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488407 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488407 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488408 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488408 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488409 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488409 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488410 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488410 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488411 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488411 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=5,`action_param4`=0 WHERE `entryorguid`=3488411 AND `source_type`=9 AND `id`=3;
UPDATE `smart_scripts` SET `action_param2`=2,`action_param3`=2,`action_param4`=0 WHERE `entryorguid`=5673000 AND `source_type`=9 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=2,`action_param3`=2,`action_param4`=0 WHERE `entryorguid`=5673001 AND `source_type`=9 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=2,`action_param3`=2,`action_param4`=0 WHERE `entryorguid`=5673001 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=2,`action_param3`=2,`action_param4`=0 WHERE `entryorguid`=5673002 AND `source_type`=9 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=2,`action_param3`=2,`action_param4`=0 WHERE `entryorguid`=5673003 AND `source_type`=9 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=2,`action_param3`=2,`action_param4`=0 WHERE `entryorguid`=5673004 AND `source_type`=9 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=2,`action_param3`=2,`action_param4`=0 WHERE `entryorguid`=5673004 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=2,`action_param3`=2,`action_param4`=0 WHERE `entryorguid`=5673005 AND `source_type`=9 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=6168001 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=10,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=6168002 AND `source_type`=9 AND `id`=4;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=6168003 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=10,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=6168004 AND `source_type`=9 AND `id`=4;
UPDATE `smart_scripts` SET `action_param2`=8,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=6178000 AND `source_type`=9 AND `id`=3;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=6178801 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=10,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=6178802 AND `source_type`=9 AND `id`=4;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=6178803 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=10,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=6178804 AND `source_type`=9 AND `id`=4;
UPDATE `smart_scripts` SET `action_param2`=5,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=6179000 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=6713100 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=6713100 AND `source_type`=9 AND `id`=8;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=6713101 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=6713101 AND `source_type`=9 AND `id`=8;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=12168400 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=12715900 AND `source_type`=9 AND `id`=4;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=16113000 AND `source_type`=9 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=16113000 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=16113001 AND `source_type`=9 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=0,`action_param3`=0,`action_param4`=0 WHERE `entryorguid`=16113001 AND `source_type`=9 AND `id`=1;
