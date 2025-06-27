-- Bloodsail Warlock
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=1564 AND `source_type`=0 AND `id`=3;
UPDATE `smart_scripts` SET `event_param1`=3000, `event_param2`=9000, `event_param3`=15000, `event_param4`=20000 WHERE `entryorguid`=1564 AND `source_type`=0 AND `id`=4;

-- Bloodsail Swashbuckler
UPDATE `smart_scripts` SET `event_param1`=5000, `event_param2`=9000 WHERE `entryorguid`=1563 AND `source_type`=0 AND `id`=0;

-- Bloodsail Sea Dog
DELETE FROM `smart_scripts` WHERE `entryorguid`=1565 AND `source_type`=0 AND `id` IN (0,1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1565,0,0,0,25,0,100,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Sea Dog - On Reset - Cast Poison Proc"),
(1565,0,1,0,67,0,100,0,6000,8000,0,0,11,37685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Sea Dog - On Behind Target - Cast Backstab"),
(1565,0,2,0,0,0,100,0,11000,14000,21000,24000,11,12540,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bloodsail Sea Dog - In Combat - Cast Gouge");

-- Bloodsail Swabby
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4506;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4506 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4506,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Swabby - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Captain Keelhaul
DELETE FROM `smart_scripts` WHERE `entryorguid`=2548 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2548,0,1,0,0,0,100,0,3000,5000,12000,18000,11,7896,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Keelhaul - In Combat - Cast Exploding Shot"),
(2548,0,2,0,9,0,100,0,0,8,30000,35000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Keelhaul - Within 0-8 Range - Cast Demoralizing Shout");

-- Bloodsail Elder Magus
DELETE FROM `smart_scripts` WHERE `entryorguid`=1653 AND `source_type`=0 AND `id` IN (0,1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1653,0,0,0,0,0,100,0,0,0,3400,4800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Elder Magus - In Combat CMC - Cast Fireball"),
(1653,0,1,0,9,0,100,0,0,8,12000,16000,11,11969,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Elder Magus - Within 0-8 Range - Cast Fire Nova"),
(1653,0,2,0,0,0,100,0,7000,11000,9000,15000,11,20827,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Elder Magus - In Combat - Cast Flamestrike");

-- Captain Stillwater
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=2550 AND `source_type`=0 AND `id`=0;

-- Zanzil Witch Doctor
UPDATE `smart_scripts` SET `event_param1`=500, `event_param2`=1000, `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=1490 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1490 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1490,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zanzil Witch Doctor - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Zanzil Hunter
DELETE FROM `smart_scripts` WHERE `entryorguid`=1489 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1489,0,0,0,0,0,100,0,0,0,2000,4000,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Zanzil Hunter - In Combat - Cast Throw");

-- Zanzil Zombie
UPDATE `smart_scripts` SET `event_param1`=4000, `event_param2`=9000 WHERE `entryorguid`=1488 AND `source_type`=0 AND `id`=0;

-- Zanzil the Outcast
DELETE FROM `smart_scripts` WHERE `entryorguid`=2534 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2534,0,0,0,0,0,100,0,0,0,23000,28000,11,8832,2,0,0,0,0,1,0,0,0,0,0,0,0,"Zanzil the Outcast - In Combat - Cast Ward of Zanzil"),
(2534,0,1,0,0,0,100,0,1000,1000,3000,5000,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Zanzil the Outcast - In Combat - Cast Lightning Bolt"),
(2534,0,2,0,0,0,100,0,6000,9000,19000,22000,11,8264,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zanzil the Outcast - In Combat - Cast Lava Spout Totem");

-- Zanzil Skeleton
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6388;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6388 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6388,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Zanzil Skeleton - Just Summoned - Start Attacking");

-- Naga Explorer
DELETE FROM `smart_scripts` WHERE `entryorguid`=1907 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1907,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Naga Explorer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Lord Sakrasis
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2541;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2541 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2541,0,0,0,0,0,100,0,5000,7000,7000,11000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Sakrasis - In Combat - Cast Cleave"),
(2541,0,1,0,0,0,100,0,6000,9000,13000,16000,11,3583,34,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Sakrasis - In Combat - Cast Deadly Poison");

-- Lashtail Raptor
DELETE FROM `smart_scripts` WHERE `entryorguid`=686 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(686,0,0,0,0,0,100,0,5000,8000,16000,21000,11,6607,2,0,0,0,0,2,0,0,0,0,0,0,0,"Lashtail Raptor - In Combat - Cast Lash");

-- Snapjaw Crocolisk
DELETE FROM `smart_scripts` WHERE `entryorguid`=1152 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1152,0,0,0,0,0,100,0,3000,5000,11000,13000,11,3604,2,0,0,0,0,2,0,0,0,0,0,0,0,"Snapjaw Crocolisk - In Combat - Cast Tendon Rip");

-- Elder Stranglethorn Tiger
DELETE FROM `smart_scripts` WHERE `entryorguid`=1085 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1085,0,0,0,0,0,100,0,6000,9000,16000,19000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Stranglethorn Tiger - In Combat - Cast Rend");

-- Murkgill Oracle
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=4459 AND `source_type`=0 AND `id`=0;

-- Murkgill Forager
DELETE FROM `smart_scripts` WHERE `entryorguid`=4457 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4457,0,0,0,0,0,100,0,6000,8000,16000,19000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkgill Forager - In Combat - Cast Rend"),
(4457,0,1,0,0,0,100,0,3000,5000,4000,9000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Murkgill Forager - In Combat - Cast Poison");

-- Murkgill Lord
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=4460 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4460 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4460,0,2,0,9,0,100,0,0,8,15000,18000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Lord - Within 0-8 Range - Cast Frost Nova");

-- Gluggle
UPDATE `smart_scripts` SET `event_param1`=7000, `event_param2`=9000 WHERE `entryorguid`=14487 AND `source_type`=0 AND `id`=0;

-- Bhag'thera
DELETE FROM `smart_scripts` WHERE `entryorguid`=728 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(728,0,0,0,0,0,100,0,7000,9000,13000,16000,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bhag'thera - In Combat - Cast Rend Flesh"),
(728,0,1,0,0,0,100,0,3000,5000,24000,26000,11,6016,2,0,0,0,0,2,0,0,0,0,0,0,0,"Bhag'thera - In Combat - Cast Pierce Armor");

-- Mosh'Ogg Brute
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1142;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1142 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1142,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosh'Ogg Brute - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1142;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1142,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Mosh'Ogg Brute"),
(1142,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Mosh'Ogg Brute"),
(1142,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Mosh'Ogg Brute");

-- Mosh'Ogg Witch Doctor
DELETE FROM `smart_scripts` WHERE `entryorguid`=1144 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1144,0,2,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosh'Ogg Witch Doctor - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1144;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1144,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,1925,0,"Mosh'Ogg Witch Doctor"),
(1144,0,1,"Me smash! You die!",12,0,100,0,0,0,1926,0,"Mosh'Ogg Witch Doctor"),
(1144,0,2,"I'll crush you!",12,0,100,0,0,0,1927,0,"Mosh'Ogg Witch Doctor");

-- Mosh'Ogg Mauler
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=678 AND `source_type`=0 AND `id`=0;

-- Mosh'Ogg Shaman
UPDATE `smart_scripts` SET `event_param1`=2000, `event_param2`=6000, `event_param3`=5000, `event_param4`=11000 WHERE `entryorguid`=679 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_param1`=7000, `event_param2`=13000 WHERE `entryorguid`=679 AND `source_type`=0 AND `id`=2;

-- Mosh'Ogg Warmonger
UPDATE `smart_scripts` SET `event_chance`=100, `event_param1`=5000, `event_param2`=7000 WHERE `entryorguid`=709 AND `source_type`=0 AND `id`=0;

-- Mosh'Ogg Spellcrafter
DELETE FROM `smart_scripts` WHERE `entryorguid`=710 AND `source_type`=0 AND `id` IN (0,1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(710,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosh'Ogg Spellcrafter - Out of Combat - Cast Frost Armor"),
(710,0,1,0,0,0,100,0,0,0,3000,5000,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mosh'Ogg Spellcrafter - In Combat CMC - Cast Fireball"),
(710,0,2,0,0,0,100,0,7000,8000,9000,12000,11,11829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mosh'Ogg Spellcrafter - In Combat - Cast Flamestrike");

-- Mosh'Ogg Butcher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=723;
DELETE FROM `smart_scripts` WHERE `entryorguid`=723 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(723,0,0,0,4,0,100,0,0,0,0,0,11,29651,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosh'Ogg Butcher - On Aggro - Cast Dual Wield"),
(723,0,1,0,0,0,100,0,5000,7000,7000,11000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mosh'Ogg Butcher - In Combat - Cast Cleave"),
(723,0,2,0,25,0,100,0,0,0,0,0,11,12787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosh'Ogg Butcher - On Reset - Cast Thrash");

-- Venture Co. Geologist
DELETE FROM `smart_scripts` WHERE `entryorguid`=1096 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1096,0,0,0,0,0,100,0,0,0,3000,5000,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Geologist - Out of Combat - Cast Lightning Bolt"),
(1096,0,1,0,0,0,100,0,5000,8000,30000,33000,11,184,32,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - In Combat - Cast Fire Shield II"),
(1096,0,2,0,2,0,100,0,0,50,11000,16000,11,4979,2,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Geologist - Between 0-50% Health - Cast Quick Flame Ward"),
(1096,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Venture Co. Geologist - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Foreman Cozzle
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4723;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4723 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4723,0,0,0,0,0,100,0,0,0,3000,5000,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Foreman Cozzle - In Combat - Cast Lightning Bolt"),
(4723,0,1,0,0,0,100,0,5000,8000,30000,33000,11,184,32,0,0,0,0,1,0,0,0,0,0,0,0,"Foreman Cozzle - In Combat - Cast Fire Shield II"),
(4723,0,2,0,2,0,100,0,0,50,11000,16000,11,4979,2,0,0,0,0,1,0,0,0,0,0,0,0,"Foreman Cozzle - Between 0-50% Health - Cast Quick Flame Ward"),
(4723,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Foreman Cozzle - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Kurzen Subchief
DELETE FROM `smart_scripts` WHERE `entryorguid`=978 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(978,0,1,0,25,0,100,0,0,0,0,0,11,3284,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Subchief - On Reset - Cast Violent Shield");

-- Kurzen Headshrinker
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=941 AND `source_type`=0 AND `id`=1;

-- Sergeant Malthus
UPDATE `smart_scripts` SET `event_param1`=3000, `event_param2`=6000 WHERE `entryorguid`=814 AND `source_type`=0 AND `id`=0;

-- Kurzen Medicine Man
DELETE FROM `smart_scripts` WHERE `entryorguid`=940 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(940,0,0,0,14,0,100,0,250,30,19000,28000,11,6077,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kurzen Medicine Man - On Friendly At 250 Health - Cast Renew"),
(940,0,1,0,14,0,100,0,550,30,34000,39000,11,6064,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kurzen Medicine Man - On Friendly At 550 Health - Cast Heal");

-- Cold Eye Basilisk
DELETE FROM `smart_scripts` WHERE `entryorguid`=690 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(690,0,0,0,0,0,100,0,7000,9000,22000,26000,11,3636,0,0,0,0,0,5,0,0,0,0,0,0,0,"Cold Eye Basilisk - In Combat - Cast Crystalline Slumber");

-- Thrashtail Basilisk
DELETE FROM `smart_scripts` WHERE `entryorguid`=1550 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1550,0,0,0,0,0,100,0,5000,7000,14000,18000,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thrashtail Basilisk - In Combat - Cast Lash");

-- Ironjaw Basilisk
DELETE FROM `smart_scripts` WHERE `entryorguid`=1551 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1551,0,0,0,0,0,100,0,7000,9000,22000,26000,11,5106,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ironjaw Basilisk - In Combat - Cast Crystal Flash");

-- Scale Belly
DELETE FROM `smart_scripts` WHERE `entryorguid`=1552 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1552,0,0,0,0,0,100,0,7000,9000,22000,26000,11,5106,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scale Belly - In Combat - Cast Crystal Flash");

-- Kurmokk
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14491;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14491 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14491,0,0,0,2,0,100,1,0,50,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurmokk - Between 0-50% Health - Cast Enrage (No Repeat)"),
(14491,0,1,0,2,0,100,1,0,50,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurmokk - Between 0-50% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=14491;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14491,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Kurmokk");

-- Bloodscalp Shaman
DELETE FROM `smart_scripts` WHERE `entryorguid`=697 AND `source_type`=0 AND `id` IN (1,4,5);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(697,0,1,0,16,0,100,0,8788,1,15000,30000,11,8788,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Shaman - On Friendly Unit Missing Buff 'Lightning Shield' - Cast Lightning Shield"),
(697,0,4,0,0,0,100,0,7000,11000,15000,19000,11,11969,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Shaman - In Combat - Cast Fire Nova"),
(697,0,5,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bloodscalp Shaman - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodscalp Warrior
DELETE FROM `smart_scripts` WHERE `entryorguid`=587 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(587,0,0,0,0,0,100,0,5000,9000,16000,22000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscalp Warrior - In Combat - Cast Disarm");

-- Bloodscalp Scavenger
DELETE FROM `smart_scripts` WHERE `entryorguid`=702 AND `source_type`=0 AND `id` IN (1,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(702,0,1,0,0,0,100,0,5000,10000,20000,30000,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscalp Scavenger - In Combat - Cast Poison"),
(702,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bloodscalp Scavenger - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodscalp Witch Doctor
DELETE FROM `smart_scripts` WHERE `entryorguid`=660 AND `source_type`=0 AND `id` IN (0,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(660,0,0,0,0,0,100,0,4000,6000,25000,30000,11,8376,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Witch Doctor - In Combat - Cast Earthgrab Totem"),
(660,0,2,0,0,0,100,0,7000,9000,25000,30000,11,5605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Witch Doctor - In Combat - Cast Healing Ward"),
(660,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bloodscalp Witch Doctor - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Skullsplitter Mystic
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=780 AND `source_type`=0 AND `id`=0;

-- Skullsplitter Spiritchaser
UPDATE `smart_scripts` SET `event_param1`=0, `event_param2`=0, `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=672 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=672 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(672,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Skullsplitter Spiritchaser - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Skullsplitter Scout
DELETE FROM `smart_scripts` WHERE `entryorguid`=782 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(782,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Skullsplitter Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Skullsplitter Witch Doctor
DELETE FROM `smart_scripts` WHERE `entryorguid`=670 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(670,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Skullsplitter Witch Doctor - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Skullsplitter Beastmaster
DELETE FROM `smart_scripts` WHERE `entryorguid`=784 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(784,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Skullsplitter Beastmaster - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Skullsplitter Headhunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=781;
DELETE FROM `smart_scripts` WHERE `entryorguid`=781 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(781,0,0,0,0,0,100,0,3000,5000,12000,16000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Headhunter - In Combat - Cast Net"),
(781,0,1,0,9,0,100,0,0,5,22000,26000,11,3148,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Headhunter - Within 0-5 Range - Cast Head Crack"),
(781,0,2,0,0,0,100,0,0,0,2000,4000,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Headhunter - In Combat - Cast Throw"),
(781,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Skullsplitter Headhunter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Ana'thek the Cruel
DELETE FROM `smart_scripts` WHERE `entryorguid`=1059 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1059,0,1,0,12,0,100,1,0,20,0,0,11,7160,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ana'thek the Cruel - Target Between 0-20% Health - Cast 'Execute' (No Repeat)");

-- Mogh the Undying
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1060;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1060 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1060,0,0,0,1,0,100,1,1000,2000,0,0,11,8813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogh the Undying - Out of Combat - Cast Summon Kurzen Mindslave"),
(1060,0,1,0,2,0,100,0,0,50,12000,16000,11,8809,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogh the Undying - Between 0-50% Health - Cast Slave Drain"),
(1060,0,2,0,0,0,100,0,0,0,3000,5000,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mogh the Undying - In Combat - Cast Shadow Bolt"),
(1060,0,3,0,1,0,100,0,1000,1000,1800000,1800000,11,20798,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogh the Undying - Out of Combat - Cast Demon Skin");

-- Kurzen Mindslave
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6366;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6366 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6366,0,0,0,14,0,100,0,800,40,15000,18000,11,11642,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kurzen Mindslave - Friendly At 800 Health - Cast Heal"),
(6366,0,1,0,0,0,100,0,8000,12000,18000,24000,11,7964,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Mindslave - In Combat - Cast Smoke Bomb");

-- Delete wrong spawn
DELETE FROM `creature` WHERE `guid`=769; -- Kurzen Mindslave spawns via script
DELETE FROM `creature_addon` WHERE `guid`=769;

-- Add missing spawn for Mosh'Ogg Butcher
SET @GUID := 769;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,723,0,0,0,1,1,0,1,-12492.5,-942.217,42.1543,0.814825,300,10,0,2050,0,1,0,0,0,"",0);

-- Fix spawn position for Rippa
UPDATE `creature` SET `position_x`=-14451.6, `position_y`=806.17, `position_z`=-36.7082 WHERE `guid`=49058;

-- Add random movement for some creatures
UPDATE `creature` SET `spawndist`=10, `MovementType`=1 WHERE `guid` IN (2169,1342,1348);

-- Add equipment to Zanzil the Outcast
DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (2534);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(2534,1,5303,0,0,0);
