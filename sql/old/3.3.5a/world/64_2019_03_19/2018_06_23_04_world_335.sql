-- Pygmy Venom Web Spider
DELETE FROM `smart_scripts` WHERE `entryorguid`=539 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(539,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pygmy Venom Web Spider - On Reset - Cast 'Poison Proc'");

-- Venom Web Spider
DELETE FROM `smart_scripts` WHERE `entryorguid`=217 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(217,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venom Web Spider - On Reset - Cast 'Poison Proc'"),
(217,0,1,0,0,0,100,0,2000,12000,13000,23000,0,11,745,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venom Web Spider - In Combat - Cast 'Web'");

-- Green Recluse
DELETE FROM `smart_scripts` WHERE `entryorguid`=569 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(569,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Green Recluse - On Reset - Cast 'Poison Proc'");

-- Rabid Dire Wolf
DELETE FROM `smart_scripts` WHERE `entryorguid`=565 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(565,0,0,0,0,0,100,0,6000,12000,12000,18000,0,11,3150,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rabid Dire Wolf - In Combat - Cast 'Rabies'");

-- Black Ravager
DELETE FROM `smart_scripts` WHERE `entryorguid`=628 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(628,0,0,0,0,0,100,0,5000,9000,16000,20000,0,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Ravager - In Combat - Cast 'Rend'");

-- Nightbane Shadow Weaver
DELETE FROM `smart_scripts` WHERE `entryorguid`=533 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(533,0,0,0,0,0,100,0,0,0,3000,5000,0,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - In Combat - Cast 'Shadow Bolt'"),
(533,0,1,0,0,0,100,0,6000,9000,18000,21000,0,11,992,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - In Combat - Cast 'Shadow Word: Pain'");

-- Fenros
DELETE FROM `smart_scripts` WHERE `entryorguid`=507 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(507,0,1,0,0,0,100,0,2000,5000,12000,18000,0,11,6725,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fenros - In Combat - Cast 'Flame Spike'"),
(507,0,2,0,0,0,100,0,11000,13000,15000,17000,0,11,865,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fenros - In Combat - Cast 'Frost Nova'");

-- Fetid Corpse
DELETE FROM `smart_scripts` WHERE `entryorguid`=1270 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1270,0,0,0,11,0,100,0,0,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fetid Corpse - On Respawn - Cast 'Birth'"),
(1270,0,1,0,0,0,100,0,5000,11000,16000,22000,0,11,7102,2,0,0,0,0,2,0,0,0,0,0,0,0,"Fetid Corpse - In Combat - Cast 'Contagion of Rot'");

-- Black Widow Hatchling
DELETE FROM `smart_scripts` WHERE `entryorguid`=930 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(930,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Widow Hatchling - On Reset - Cast 'Poison Proc'"),
(930,0,1,0,0,0,100,0,5000,13000,14000,18000,0,11,7367,32,0,0,0,0,2,0,0,0,0,0,0,0,"Black Widow Hatchling - In Combat - Cast 'Infected Bite'");

-- Insane Ghoul
DELETE FROM `smart_scripts` WHERE `entryorguid`=511 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(511,0,0,0,11,0,100,0,0,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Insane Ghoul - On Respawn - Cast 'Birth'");

-- Nightbane Vile Fang
DELETE FROM `smart_scripts` WHERE `entryorguid`=206 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(206,0,0,0,0,0,100,0,2000,16000,8000,20000,0,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightbane Vile Fang - In Combat - Cast 'Infected Wound'");

-- Nightbane Tainted One
DELETE FROM `smart_scripts` WHERE `entryorguid`=920 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(920,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Tainted One - On Reset - Cast 'Poison Proc'"),
(920,0,1,0,0,0,100,0,11000,16000,19000,24000,0,11,3424,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Tainted One - In Combat - Cast 'Tainted Howl'");

-- Gutspill
DELETE FROM `smart_scripts` WHERE `entryorguid`=6170 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6170,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gutspill - On Reset - Cast 'Poison Proc'"),
(6170,0,1,0,0,0,100,0,11000,16000,19000,24000,0,11,3424,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gutspill - In Combat - Cast 'Tainted Howl'");

-- Defias Night Blade
DELETE FROM `smart_scripts` WHERE `entryorguid`=909 AND `source_type`=0 AND `id` IN (0,1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(909,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Night Blade - On Reset - Cast 'Poison Proc'"),
(909,0,1,0,25,0,100,0,0,0,0,0,0,11,8601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Night Blade - On Reset - Cast 'Slowing Poison'"),
(909,0,2,0,0,0,100,0,3000,6000,5000,8000,0,11,2589,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Night Blade - In Combat - Cast 'Backstab'");

-- Defias Enchanter
UPDATE `smart_scripts` SET `action_param2`=0, `event_param4`=26000 WHERE `entryorguid`=910 AND `source_type`=0 AND `id`=2;

-- Bone Chewer
DELETE FROM `smart_scripts` WHERE `entryorguid`=210 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(210,0,0,0,11,0,100,0,0,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bone Chewer - On Respawn - Cast 'Birth'"),
(210,0,1,0,0,0,100,0,5000,12000,16000,23000,0,11,6016,2,0,0,0,0,2,0,0,0,0,0,0,0,"Bone Chewer - In Combat - Cast 'Pierce Armor'");

-- Rotted One
DELETE FROM `smart_scripts` WHERE `entryorguid`=948 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(948,0,0,0,11,0,100,0,0,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rotted One - On Respawn - Cast 'Birth'");

-- Flesh Eating Worm
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2462;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2462 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2462,0,0,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Flesh Eating Worm - Just Summoned - Start Attacking");

-- Plague Spreader
DELETE FROM `smart_scripts` WHERE `entryorguid`=604 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(604,0,0,0,11,0,100,0,0,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Spreader - On Respawn - Cast 'Birth'"),
(604,0,1,0,0,0,100,0,5000,9000,12000,18000,0,11,3436,32,0,0,0,0,5,0,0,0,0,0,0,0,"Plague Spreader - In Combat - Cast 'Wandering Plague'");

-- Carrion Recluse
DELETE FROM `smart_scripts` WHERE `entryorguid`=949 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(949,0,0,0,0,0,100,0,8000,16000,14000,30000,0,11,3609,0,0,0,0,0,2,0,0,0,0,0,0,0,"Carrion Recluse - In Combat - Cast 'Paralyzing Poison'");

-- Skeletal Raider
DELETE FROM `smart_scripts` WHERE `entryorguid`=1110 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1110,0,0,0,25,0,100,0,0,0,0,0,0,11,8601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Raider - On Reset - Cast 'Slowing Poison'");

-- Skeletal Healer
DELETE FROM `smart_scripts` WHERE `entryorguid`=787 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(787,0,1,0,14,0,100,1,360,40,0,0,0,11,2054,0,0,0,0,0,7,0,0,0,0,0,0,0,"Skeletal Healer - Friendly At 360 Health - Cast 'Heal' (No Repeat)");

-- Mor'Ladim
DELETE FROM `smart_scripts` WHERE `entryorguid`=522 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(522,0,0,0,0,0,100,0,6000,8000,10000,26000,0,11,3547,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mor'Ladim - In Combat - Cast 'Enraging Memories'");

-- Brain Eater
DELETE FROM `smart_scripts` WHERE `entryorguid`=570 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(570,0,0,0,11,0,100,0,0,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brain Eater - On Respawn - Cast 'Birth'"),
(570,0,1,0,0,0,100,0,2000,8000,16000,24000,0,11,3429,0,0,0,0,0,5,0,0,0,0,0,0,0,"Brain Eater - In Combat - Cast 'Plague Mind'");

-- Lord Malathrom
DELETE FROM `smart_scripts` WHERE `entryorguid`=503 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(503,0,0,0,11,0,100,0,0,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Malathrom - On Respawn - Cast 'Birth'"),
(503,0,1,0,0,0,100,0,2000,4000,7000,9000,0,11,2767,32,0,0,0,0,5,0,0,0,0,0,0,0,"Lord Malathrom - In Combat - Cast 'Shadow Word: Pain'"),
(503,0,2,0,0,0,100,0,5000,11000,22000,30000,0,11,3537,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Malathrom - In Combat - Cast 'Minions of Malathrom'");

-- Sludge
DELETE FROM `smart_scripts` WHERE `entryorguid`=2479 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2479,0,0,0,25,0,100,0,0,0,0,0,0,11,3512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sludge - On Reset - Cast 'Sludge Passive'"),
(2479,0,1,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Sludge - Just Summoned - Start Attacking");

-- Sloth
DELETE FROM `smart_scripts` WHERE `entryorguid`=2475 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2475,0,0,0,25,0,100,0,0,0,0,0,0,11,3509,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sloth - On Reset - Cast 'Sloth Passive'"),
(2475,0,1,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Sloth - Just Summoned - Start Attacking");

-- Skeletal Warder
DELETE FROM `smart_scripts` WHERE `entryorguid`=785 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(785,0,0,0,0,0,100,0,10000,16000,10000,16000,0,11,4979,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Warder - In Combat - Cast 'Quick Flame Ward'"),
(785,0,1,0,0,0,100,0,2000,9000,20000,27000,0,11,8699,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Warder - In Combat - Cast 'Unholy Frenzy'");

-- Splinter Fist Ogre
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid` IN (212,892,1251,891,889) AND `source_type`=0 AND `id`=0; 

-- Splinter Fist Warrior
DELETE FROM `smart_scripts` WHERE `entryorguid`=212 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(212,0,1,0,0,0,100,0,3000,7000,14000,21000,0,11,5242,2,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Warrior - In Combat - Cast 'Battle Shout'");

-- Splinter Fist Fire Weaver
DELETE FROM `smart_scripts` WHERE `entryorguid`=891 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(891,0,2,0,0,0,100,0,5000,8000,12000,18000,0,11,20296,0,0,0,0,0,5,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - In Combat - Cast 'Flamestrike'");

-- Splinter Fist Enslaver
DELETE FROM `smart_scripts` WHERE `entryorguid`=1487 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1487,0,1,0,0,0,100,0,1000,3000,13000,17000,0,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Splinter Fist Enslaver - In Combat - Cast 'Net'"),
(1487,0,2,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Enslaver - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1487;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1487,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Splinter Fist Enslaver"),
(1487,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Splinter Fist Enslaver"),
(1487,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Splinter Fist Enslaver");

-- Zzarc' Vul
DELETE FROM `smart_scripts` WHERE `entryorguid`=300 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(300,0,0,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zzarc' Vul - On Aggro - Say Line 0"),
(300,0,1,0,0,0,100,0,5000,7000,11000,15000,0,11,8716,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zzarc' Vul - In Combat - Cast 'Low Swipe'");

DELETE FROM `creature_text` WHERE `CreatureID`=300;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(300,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Zzarc' Vul"),
(300,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Zzarc' Vul"),
(300,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Zzarc' Vul");

-- Morbent Fel
UPDATE `creature_template` SET `unit_class`=2 WHERE `entry`=24782;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1200 AND `source_type`=0 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1200,0,2,0,0,0,100,0,0,0,3000,5000,0,11,3108,64,0,0,0,0,2,0,0,0,0,0,0,0,"Morbent Fel - In Combat - Cast 'Touch of Death'"),
(1200,0,3,0,0,0,100,0,3000,6000,18000,24000,0,11,3109,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morbent Fel - In Combat - Cast 'Presence of Death'");
