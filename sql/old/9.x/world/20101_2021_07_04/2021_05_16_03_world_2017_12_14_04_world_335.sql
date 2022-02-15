-- Bloodsail Sea Dog
DELETE FROM `smart_scripts` WHERE `entryorguid`=1565 AND `source_type`=0 AND `id` IN (0,1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1565,0,0,0,25,0,100,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodsail Sea Dog - On Reset - Cast Poison Proc"),
(1565,0,1,0,67,0,100,0,6000,8000,0,0,11,37685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Sea Dog - On Behind Target - Cast Backstab"),
(1565,0,2,0,0,0,100,0,11000,14000,21000,24000,11,12540,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bloodsail Sea Dog - In Combat - Cast Gouge");

-- Bloodsail Elder Magus
DELETE FROM `smart_scripts` WHERE `entryorguid`=1653 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1653,0,0,0,0,0,100,0,0,0,3400,4800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Elder Magus - In Combat CMC - Cast Fireball"),
(1653,0,1,0,0,0,100,0,7000,11000,9000,15000,11,20827,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodsail Elder Magus - In Combat - Cast Flamestrike");

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

-- Murkgill Coldbringer
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=4460 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4460 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4460,0,2,0,9,0,100,0,0,8,15000,18000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkgill Coldbringer - Within 0-8 Range - Cast Frost Nova");

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

-- Kurzen Headshrinker
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=941 AND `source_type`=0 AND `id`=1;

-- Sergeant Malthus
UPDATE `smart_scripts` SET `event_param1`=3000, `event_param2`=6000 WHERE `entryorguid`=814 AND `source_type`=0 AND `id`=0;

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

-- Bloodscalp Warrior
DELETE FROM `smart_scripts` WHERE `entryorguid`=587 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(587,0,0,0,0,0,100,0,5000,9000,16000,22000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscalp Warrior - In Combat - Cast Disarm");

-- Skullsplitter Mystic
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=780 AND `source_type`=0 AND `id`=0;

-- Skullsplitter Spiritchaser
UPDATE `smart_scripts` SET `event_param1`=0, `event_param2`=0, `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=672 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=672 AND `source_type`=0 AND `id`=2;

-- Skullsplitter Headhunter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=781;
DELETE FROM `smart_scripts` WHERE `entryorguid`=781 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(781,0,0,0,0,0,100,0,3000,5000,12000,16000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Headhunter - In Combat - Cast Net"),
(781,0,1,0,9,0,100,0,0,5,22000,26000,11,3148,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Headhunter - Within 0-5 Range - Cast Head Crack"),
(781,0,2,0,0,0,100,0,0,0,2000,4000,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Headhunter - In Combat - Cast Throw"),
(781,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Skullsplitter Headhunter - Between 0-15% Health - Flee For Assist (No Repeat)");

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

-- Add missing spawn for Mosh'Ogg Butcher
SET @GUID := 769;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@GUID,723,0,1,-12492.5,-942.217,42.1543,0.814825,300,10,0);
