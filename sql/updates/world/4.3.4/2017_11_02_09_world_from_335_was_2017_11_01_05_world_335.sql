/*
-- Darkfang Venomspitter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4414;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4414 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4414,0,0,0,0,0,100,0,1000,2000,3000,4500,11,7951,64,0,0,0,0,2,0,0,0,0,0,0,0,"Darkfang Venomspitter - In Combat - Cast Toxic Spit");

-- Giant Darkfang Spider
DELETE FROM `smart_scripts` WHERE `entryorguid`=4415 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4415,0,0,0,0,0,100,0,4000,12000,16000,24000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Darkfang Spider - In Combat - Cast Poison");

-- Drywallow Crocolisk
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4341;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4341 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4341,0,0,0,0,0,100,0,5000,7000,18000,22000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drywallow Crocolisk - In Combat - Cast Tendon Rip");

-- Drywallow Snapper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4343;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4343 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4343,0,0,0,0,0,100,0,5000,7000,6000,8000,11,19319,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drywallow Snapper - In Combat - Cast Vicious Bite");

-- Noxious Flayer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4346;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4346 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4346,0,0,0,0,0,100,0,3000,5000,6000,9000,11,43132,0,0,0,0,0,2,0,0,0,0,0,0,0,"Noxious Flayer - In Combat - Cast Poison Burst");

-- Noxious Reaver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4347;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4347 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4347,0,0,0,0,0,100,0,7000,9000,12000,15000,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Noxious Reaver - In Combat - Cast Swoop"),
(4347,0,1,0,25,0,100,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noxious Reaver - On Reset - Cast Poison Proc");

-- Noxious Shredder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4348;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4348 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4348,0,0,0,25,0,100,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noxious Shredder - On Reset - Cast Thrash"),
(4348,0,1,0,25,0,100,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noxious Shredder - On Reset - Cast Poison Proc");

-- Theramore Deserter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5057;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5057 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5057,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Deserter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodfen Screecher
DELETE FROM `smart_scripts` WHERE `entryorguid`=4352 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4352,0,2,0,2,0,100,1,0,30,0,0,39,20,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfen Screecher - Between 0-30% Health - Call For Help (No Repeat)");

-- Bloodfen Razormaw
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4356;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4356 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4356,0,0,0,0,0,100,0,4000,10000,8000,14000,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfen Razormaw - In Combat - Cast Infected Wound");

-- Bloodfen Lashtail
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4357;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4357 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4357,0,0,0,0,0,100,0,5000,11000,16000,22000,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfen Lashtail - In Combat - Cast Lash");

-- Goreclaw the Ravenous
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23873;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23873 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23873,0,0,0,4,0,100,0,0,0,0,0,11,53625,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goreclaw the Ravenous - On Aggro - Cast Heroic Leap"),
(23873,0,1,0,0,0,100,0,5000,9000,18000,22000,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goreclaw the Ravenous - In Combat - Cast Gore");

-- Brimgore
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4339;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4339 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4339,0,0,0,0,0,100,0,6000,9000,8000,13000,11,8873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brimgore - In Combat - Cast Flame Breath");

-- Scorchscale Drake
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23687;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23687 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23687,0,0,0,0,0,100,0,6000,9000,8000,13000,11,8873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorchscale Drake - In Combat - Cast Flame Breath");

-- Searing Whelp
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4324;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4324 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4324,0,0,0,0,0,100,0,4000,7000,5000,9000,11,11021,0,0,0,0,0,2,0,0,0,0,0,0,0,"Searing Whelp - In Combat - Cast Flamespit");

-- Searing Hatchling
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4323;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4323 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4323,0,0,0,0,0,100,0,0,0,3400,4800,11,11985,64,0,0,0,0,2,0,0,0,0,0,0,0,"Searing Hatchling - In Combat - Cast Fireball");

-- Hayoc
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14234;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14234 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14234,0,0,0,0,0,100,0,3000,5000,9000,14000,11,17157,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hayoc - In Combat - Cast Lightning Breath"),
(14234,0,1,0,0,0,100,0,7000,9000,9000,14000,11,21059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hayoc - In Combat - Cast Acid Spit");

-- Acidic Swamp Ooze
DELETE FROM `smart_scripts` WHERE `entryorguid`=4393 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4393,0,2,0,0,0,100,0,5000,9000,5000,11000,11,9459,0,0,0,0,0,2,0,0,0,0,0,0,0,"Acidic Swamp Ooze - In Combat - Cast Corrosive Ooze");

-- Grimtotem Breaker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23592;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23592 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23592,0,0,0,0,0,100,0,5000,9000,8000,13000,11,43108,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Breaker - In Combat - Cast Bone Breaker");

-- Grimtotem Spirit-Shifter
DELETE FROM `smart_scripts` WHERE `entryorguid`=23593 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23593,0,0,0,0,0,100,0,3000,5000,8000,12000,11,11824,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Spirit-Shifter - In Combat - Cast Shock"),
(23593,0,1,0,0,0,100,0,7000,9000,16000,20000,11,43110,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Spirit-Shifter - In Combat - Cast Summon Spirit Wolf");

-- Grimtotem Spirit Wolf
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26111;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26111 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26111,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,40,0,0,0,0,0,0,"Grimtotem Spirit Wolf - On Just Summoned - Start Attack");

-- Grimtotem Elder
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23714;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23714 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23714,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Elder - In Combat - Cast Lightning Bolt"),
(23714,0,1,0,14,0,100,0,500,40,16000,21000,11,11986,0,0,0,0,0,7,0,0,0,0,0,0,0,"Grimtotem Elder - Friendly At 500 Health - Cast Healing Wave");

-- Grimtotem Destroyer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23594;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23594 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23594,0,0,0,0,0,100,0,5000,8000,12000,15000,11,11876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Destroyer - In Combat - Cast War Stomp");

-- Grimtotem Earthbinder
DELETE FROM `smart_scripts` WHERE `entryorguid`=23595 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23595,0,0,0,4,0,100,0,0,0,0,0,11,38184,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Earthbinder - On Aggro - Cast Windfury"),
(23595,0,1,0,0,0,100,0,5000,7000,19000,22000,11,15786,2,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Earthbinder - In Combat - Cast Earthbind Totem");

-- Apothecary Cylla
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23881;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23881 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23881,0,0,0,25,0,100,0,0,0,0,0,11,10022,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Cylla - On Reset - Cast Deadly Poison"),
(23881,0,1,0,0,0,100,0,5000,7000,45000,50000,11,35204,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Cylla - In Combat - Cast Toxic Fumes");

-- Darkmist Spider
DELETE FROM `smart_scripts` WHERE `entryorguid`=4376 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4376,0,0,0,0,0,100,0,4000,12000,18000,26000,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkmist Spider - In Combat - Cast Poison");

-- Darkmist Recluse
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4378;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4378 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4378,0,0,0,0,0,100,0,4000,9000,15000,20000,11,43133,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkmist Recluse - In Combat - Cast Debilitating Poison");

-- Darkmist Silkspinner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4379;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4379 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4379,0,0,0,0,0,100,0,4000,12000,18000,26000,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkmist Silkspinner - In Combat - Cast Poison"),
(4379,0,1,0,9,0,100,0,0,30,9000,14000,11,745,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkmist Silkspinner - Within 0-30 Range - Cast Web");

-- Darkmist Widow
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4380;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4380 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4380,0,0,0,0,0,100,0,4000,12000,18000,26000,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darkmist Widow - In Combat - Cast Poison"),
(4380,0,1,0,0,0,100,0,2000,3000,8000,11000,11,43134,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkmist Widow - In Combat - Cast Hatch Spiderlings");

-- Darkmist Hatchling
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4377;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4377 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4377,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,40,0,0,0,0,0,0,"Darkmist Hatchling - On Just Summoned - Start Attack");

-- Withervine Creeper
DELETE FROM `smart_scripts` WHERE `entryorguid`=4382 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4382,0,0,0,0,0,100,0,3000,7000,12000,16000,11,43130,0,0,0,0,0,5,0,0,0,0,0,0,0,"Withervine Creeper - In Combat - Cast Creeping Vines");

-- Withervine Rager 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4385;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4385 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4385,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withervine Rager - Between 0-30% Health - Cast Enrage (No Repeat)"),
(4385,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withervine Rager - Between 0-30% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=4385;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4385,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Withervine Rager");

-- Withervine Mire Beast
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4387;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4387 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4387,0,0,0,0,0,100,0,5000,8000,11000,15000,11,5337,0,0,0,0,0,2,0,0,0,0,0,0,0,"Withervine Mire Beast - In Combat - Cast Wither Strike");

-- Theramore Infiltrator
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4834;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4834 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4834,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Infiltrator - Between 0-15% Health - Flee For Assist (No Repeat)"),
(4834,0,1,0,25,0,100,0,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Infiltrator - On Reset - Cast Sneak");

-- Muckshell Clacker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4401;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4401 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4401,0,0,0,0,0,100,0,6000,9000,20000,25000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Muckshell Clacker - In Combat - Cast Tendon Rip");

-- Muckshell Pincer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4403;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4403 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4403,0,0,0,4,0,100,0,0,0,0,0,11,674,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muckshell Pincer - On Aggro - Cast Dual Wield");

-- Muckshell Scrabbler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4404;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4404 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4404,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Muckshell Scrabbler - In Combat - Cast Lightning Bolt"),
(4404,0,1,0,14,0,100,0,900,40,16000,21000,11,8005,0,0,0,0,0,7,0,0,0,0,0,0,0,"Muckshell Scrabbler - Friendly At 900 Health - Cast Healing Wave");

-- Murk Thresher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4389;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4389 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4389,0,0,0,25,0,100,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murk Thresher - On Reset - Cast Thrash");

-- Elder Murk Thresher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4390;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4390 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4390,0,0,0,25,0,100,0,0,0,0,0,11,12787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Murk Thresher - On Reset - Cast Thrash");

-- Privateer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23620;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23620 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23620,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Privateer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Deserter Lieutenant
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23637;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23637 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23637,0,0,0,13,0,100,0,18000,22000,0,0,11,11972,2,0,0,0,0,2,0,0,0,0,0,0,0,"Deserter Lieutenant - Target Casting - Cast Shield Bash");

-- Mudrock Spikeshell
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4397;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4397 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4397,0,0,0,25,0,100,0,0,0,0,0,11,8393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mudrock Spikeshell - On Reset - Cast Barbs");

-- Defias Rummager
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23589;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23589 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23589,0,0,0,4,0,100,0,0,0,0,0,11,38557,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Rummager - On Aggro - Cast Throw"),
(23589,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Rummager - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Defias Conjuror
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23590;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23590 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23590,0,0,0,23,0,100,0,12544,0,1000,2000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjuror - On Has No Aura 'Frost Armor' - Cast Frost Armor"),
(23590,0,1,0,0,0,100,0,0,0,3400,4800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Conjuror - In Combat - Cast Fireball"),
(23590,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Conjuror - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Garn Mathers
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23679;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23679 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23679,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Garn Mathers - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Defias Diver
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23591;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23591 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23591,0,0,0,4,0,100,0,0,0,0,0,11,43107,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Diver - On Aggro - Cast Spear Throw"),
(23591,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Diver - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Razorspine
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23841;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23841 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23841,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razorspine - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Burgle Eye
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14230;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14230 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14230,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burgle Eye - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Mirefin Oracle
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4363;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4363 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4363,0,0,0,1,0,100,0,1000,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirefin Oracle - Out of Combat - Cast Lightning Shield"),
(4363,0,1,0,16,0,100,0,12550,1,15000,30000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirefin Oracle - On Friendly Unit Missing Buff 'Lightning Shield' - Cast Lightning Shield"),
(4363,0,2,0,14,0,100,0,800,40,14000,19000,11,959,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mirefin Oracle - Friendly At 800 Health - Cast Healing Wave"),
(4363,0,3,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mirefin Oracle - In Combat - Cast Lightning Bolt"),
(4363,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirefin Oracle - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Mirefin Muckdweller
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4361;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4361 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4361,0,0,0,9,0,100,0,0,5,13000,16000,11,9462,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mirefin Muckdweller - Within 0-5 Range - Cast Mirefin Fungus"),
(4361,0,1,0,0,0,100,0,4000,9000,30000,35000,11,6278,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mirefin Muckdweller - In Combat - Cast Creeping Mold"),
(4361,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirefin Muckdweller - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Mirefin Coastrunner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4362;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4362 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4362,0,0,0,0,0,100,0,5000,7000,11000,15000,11,37998,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mirefin Coastrunner - In Combat - Cast Piercing Strike"),
(4362,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirefin Coastrunner - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Oozeworm
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14237;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14237 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14237,0,0,0,4,0,100,1,0,0,0,0,11,22911,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oozeworm - On Aggro - Cast Charge"),
(14237,0,1,0,0,0,100,0,5000,9000,17000,22000,11,66954,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oozeworm - In Combat - Cast Acidic Strike");

-- Deadmire
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4841;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4841 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4841,0,0,0,0,0,100,0,6000,9000,16000,19000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadmire - In Combat - Cast Rend"),
(4841,0,1,0,0,0,100,0,9000,12000,21000,24000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadmire - In Combat - Cast Tendon Rip");

-- Ripscale
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14233;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14233 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14233,0,0,0,0,0,100,0,5000,8000,15000,18000,11,33912,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ripscale - In Combat - Cast Rip"),
(14233,0,1,0,0,0,100,0,8000,11000,24000,27000,11,7367,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ripscale - In Combat - Cast Infected Bite");

-- Drogoth the Roamer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14231;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14231 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14231,0,0,0,0,0,100,0,6000,9000,16000,21000,11,11876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drogoth the Roamer - In Combat - Cast War Stomp");

-- Lord Angler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14236;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14236 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14236,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Angler - Between 0-15% Health - Flee For Assist (No Repeat)");

-- The Rot
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14235;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14235 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14235,0,0,0,0,0,100,0,0,0,2900,4300,11,21067,64,0,0,0,0,2,0,0,0,0,0,0,0,"The Rot - In Combat - Cast Poison Bolt"),
(14235,0,1,0,9,0,100,0,0,5,12000,15000,11,22595,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Rot - Within 0-5 Range - Cast Poison Shock");

-- Random movement for some creatures
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE `guid` IN (31481,200145);

-- Fix spawn position for one creature
UPDATE `creature` SET `position_z`=-7.17478 WHERE `guid`=8447;
*/
