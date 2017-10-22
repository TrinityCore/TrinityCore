/*
-- Worg
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1765;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1765 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1765,0,0,0,0,0,100,0,4000,14000,24000,34000,11,24604,2,0,0,0,0,1,0,0,0,0,0,0,0,"Worg - In Combat - Cast Furious Howl");

-- Mottled Worg
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1766;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1766 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1766,0,0,0,0,0,100,0,5000,9000,22000,26000,11,3150,2,0,0,0,0,2,0,0,0,0,0,0,0,"Mottled Worg - In Combat - Cast Rabies");

-- Gorefang
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12431;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12431 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12431,0,0,0,0,0,100,0,6000,9000,16000,19000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorefang - In Combat - Cast Rend");

-- Vile Fin Shredder
DELETE FROM `smart_scripts` WHERE `entryorguid`=1767 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1767,0,0,0,0,0,100,0,3000,7000,16000,24000,11,3252,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Fin Shredder - In Combat - Cast Shred"),
(1767,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Shredder - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Vile Fin Tidehunter
DELETE FROM `smart_scripts` WHERE `entryorguid`=1768 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1768,0,0,0,0,0,100,0,5000,9000,6000,14000,11,12748,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Tidehunter - In Combat - Cast Frost Nova"),
(1768,0,1,0,23,0,100,0,12544,0,1000,2000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Tidehunter - On Has No Aura Frost Armor - Cast Frost Armor"),
(1768,0,2,0,14,0,100,0,70,80,12000,16000,11,4980,2,0,0,0,0,7,0,0,0,0,0,0,0,"Vile Fin Tidehunter - Friendly At 70 Health - Cast Cast Quick Frost Ward"),
(1768,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Tidehunter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Ravenclaw Raider
DELETE FROM `smart_scripts` WHERE `entryorguid`=1865 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1865,0,0,0,0,0,100,0,2000,6000,22000,26000,11,5271,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravenclaw Raider - In Combat - Cast Cursed Blade");

-- Ravenclaw Slave
DELETE FROM `smart_scripts` WHERE `entryorguid`=1866 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1866,0,0,0,0,0,100,0,4000,9000,6000,14000,11,7761,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ravenclaw Slave - In Combat - Cast Shared Bondage"),
(1866,0,1,0,11,0,100,0,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ravenclaw Slave - On Respawn - Cast Birth");

-- Ivar the Foul
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1971;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1971 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1971,0,0,0,11,0,100,0,0,0,0,0,11,7667,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ivar the Foul - On Respawn - Cast Foul Odor"),
(1971,0,1,0,11,0,100,0,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ivar the Foul - On Respawn - Cast Birth");

-- Ferocious Grizzled Bear
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1778;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1778 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1778,0,0,0,0,0,100,0,6000,12000,14000,20000,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ferocious Grizzled Bear - In Combat - Cast Swipe");

-- Giant Grizzled Bear
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1797;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1797 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1797,0,0,0,0,0,100,0,6000,12000,14000,20000,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Grizzled Bear - In Combat - Cast Swipe");

-- Old Vicejaw
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12432;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12432 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12432,0,0,0,0,0,100,0,5000,10000,7000,12000,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,"Old Vicejaw - In Combat - Cast Strike");

-- Rot Hide Gladerunner
DELETE FROM `smart_scripts` WHERE `entryorguid`=1772 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1772,0,0,0,0,0,100,0,2000,12000,30000,45000,11,3237,2,0,0,0,0,2,0,0,0,0,0,0,0,"Rot Hide Gladerunner - In Combat - Cast Curse of Thule"),
(1772,0,1,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rot Hide Gladerunner - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1772;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1772,0,0,"Grrrrr!",12,0,100,0,0,0,1869,0,"Rot Hide Gladerunner"),
(1772,0,1,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Rot Hide Gladerunner"),
(1772,0,2,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Rot Hide Gladerunner");

-- Rot Hide Mystic
DELETE FROM `smart_scripts` WHERE `entryorguid`=1773 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1773,0,0,0,0,0,100,0,2000,12000,30000,45000,11,3237,2,0,0,0,0,2,0,0,0,0,0,0,0,"Rot Hide Mystic - In Combat - Cast Curse of Thule"),
(1773,0,1,0,14,0,100,0,150,40,14000,22000,11,332,0,0,0,0,0,7,0,0,0,0,0,0,0,"Rot Hide Mystic - Friendly At 150 Health - Cast Healing Wave"),
(1773,0,2,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rot Hide Mystic - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1773;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1773,0,0,"Grrrrr!",12,0,100,0,0,0,1869,0,"Rot Hide Mystic"),
(1773,0,1,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Rot Hide Mystic"),
(1773,0,2,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Rot Hide Mystic");

-- Moss Stalker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1780;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1780 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1780,0,0,0,0,0,100,0,4000,13000,17000,26000,11,13884,32,0,0,0,0,2,0,0,0,0,0,0,0,"Moss Stalker - In Combat - Cast Withering Poison");

-- Krethis Shadowspinner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12433;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12433 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12433,0,0,0,0,0,100,0,7000,11000,13000,19000,11,17439,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krethis Shadowspinner - In Combat - Cast Shadow Shock"),
(12433,0,1,0,2,0,100,0,0,20,32000,38000,11,12040,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krethis Shadowspinner - Between 0-20% Health - Cast Shadow Shield");

-- Moonrage Whitescalp
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1769;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1769 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1769,0,0,0,23,0,100,0,12544,0,1000,2000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonrage Whitescalp - On Has No Aura Frost Armor - Cast Frost Armor");

-- Moonrage Darkrunner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1770;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1770 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1770,0,0,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonrage Darkrunner - Just Summoned - Say Line 0"),
(1770,0,1,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,40,0,0,0,0,0,0,"Moonrage Darkrunner - Just Summoned - Start Attacking");

DELETE FROM `creature_text` WHERE `CreatureID`=1770;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1770,0,0,"The Sons of Arugal will rise against all who challenge the power of the Moonrage!",12,0,100,0,0,0,502,0,"Moonrage Darkrunner");

-- Moonrage Glutton
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1779;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1779 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1779,0,0,0,0,0,100,0,5000,10000,13000,21000,11,6958,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moonrage Glutton - In Combat - Cast Blood Leech");

-- Moonrage Bloodhowler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1924;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1924 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1924,0,0,0,0,0,100,0,6000,11000,16000,21000,11,3264,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonrage Bloodhowler - In Combat - Cast Blood Howl");

-- Moonrage Darksoul
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1782;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1782 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1782,0,0,0,2,0,100,1,0,50,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonrage Darksoul - Between 0-50% Health - Cast Enrage (No Repeat)"),
(1782,0,1,0,2,0,100,1,0,50,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonrage Darksoul - Between 0-50% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=1782;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1782,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Moonrage Darksoul");

-- Ravenclaw Servant
DELETE FROM `smart_scripts` WHERE `entryorguid`=1868 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1868,0,0,0,0,0,100,0,3000,8000,18000,24000,11,980,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravenclaw Servant - In Combat - Cast Curse of Agony"),
(1868,0,1,0,2,0,100,0,0,65,22000,24000,11,7290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravenclaw Servant - Between 0-65% Health - Cast Soul Siphon");

-- Hand of Ravenclaw
DELETE FROM `smart_scripts` WHERE `entryorguid`=1870 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1870,0,0,0,0,0,100,0,7000,12000,13000,18000,11,3263,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hand of Ravenclaw - In Combat - Cast Touch of Ravenclaw");

-- Fenwick Thatros
DELETE FROM `smart_scripts` WHERE `entryorguid`=6570 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6570,0,0,0,0,0,100,0,6000,8000,6000,12000,11,18072,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fenwick Thatros - In Combat - Cast Uppercut");

-- Vile Fin Tidecaller
DELETE FROM `smart_scripts` WHERE `entryorguid`=1958 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1958,0,0,0,0,0,100,0,5000,9000,6000,14000,11,12748,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Tidecaller - In Combat - Cast Frost Nova"),
(1958,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Tidecaller - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Vile Fin Lakestalker
DELETE FROM `smart_scripts` WHERE `entryorguid`=1909 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1909,0,0,0,0,0,100,0,6000,12000,30000,40000,11,5605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Lakestalker - In Combat - Cast Healing Ward"),
(1909,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Lakestalker - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Vile Fin Oracle
DELETE FROM `smart_scripts` WHERE `entryorguid`=1908 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1908,0,0,0,0,0,100,0,3000,5000,6000,9000,11,2606,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Fin Oracle - In Combat - Cast Shock"),
(1908,0,1,0,14,0,100,0,150,40,18000,24000,11,913,0,0,0,0,0,7,0,0,0,0,0,0,0,"Vile Fin Oracle - Friendly At 150 Health - Cast Healing Wave"),
(1908,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Oracle - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Vile Fin Shorecreeper
DELETE FROM `smart_scripts` WHERE `entryorguid`=1957 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1957,0,0,0,0,0,100,0,7000,13000,15000,19000,11,1776,2,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Fin Shorecreeper - In Combat - Cast Gouge"),
(1957,0,1,0,67,0,100,0,6000,8000,0,0,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Fin Shorecreeper - On Behind Target - Cast Backstab"),
(1957,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Fin Shorecreeper - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Elder Lake Creeper
DELETE FROM `smart_scripts` WHERE `entryorguid`=1956 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1956,0,0,0,25,0,100,0,0,0,0,0,11,6871,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Lake Creeper - On Reset - Cast Moss Covered Feet Proc"),
(1956,0,1,0,0,0,100,0,4000,11000,15000,19000,11,11922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Lake Creeper - In Combat - Cast Entangling Roots");

-- Lake Creeper
DELETE FROM `smart_scripts` WHERE `entryorguid`=1955 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1955,0,0,0,25,0,100,0,0,0,0,0,11,6871,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lake Creeper - On Reset - Cast Moss Covered Feet Proc");

-- Elder Lake Skulker
DELETE FROM `smart_scripts` WHERE `entryorguid`=1954 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1954,0,0,0,25,0,100,0,0,0,0,0,11,6867,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Lake Skulker - On Reset - Cast Moss Covered Hands Proc"),
(1954,0,1,0,2,0,100,0,0,60,22000,25000,11,9616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Lake Skulker - Between 0-60% Health - Cast Wild Regeneration");

-- Lake Skulker
DELETE FROM `smart_scripts` WHERE `entryorguid`=1953 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1953,0,0,0,25,0,100,0,0,0,0,0,11,6867,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lake Skulker - On Reset - Cast Moss Covered Hands Proc");

-- Rot Hide Brute
DELETE FROM `smart_scripts` WHERE `entryorguid`=1939 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1939,0,0,0,0,0,100,0,2000,18000,30000,45000,11,3237,2,0,0,0,0,2,0,0,0,0,0,0,0,"Rot Hide Brute - In Combat - Cast Curse of Thule"),
(1939,0,1,0,0,0,100,0,5000,8000,6000,9000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rot Hide Brute - In Combat - Cast Sunder Armor"),
(1939,0,2,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rot Hide Brute - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1939;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1939,0,0,"Grrrrr!",12,0,100,0,0,0,1869,0,"Rot Hide Brute"),
(1939,0,1,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Rot Hide Brute"),
(1939,0,2,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Rot Hide Brute");

-- Rot Hide Plague Weaver
DELETE FROM `smart_scripts` WHERE `entryorguid`=1940 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1940,0,0,0,0,0,100,0,2000,18000,30000,45000,11,3237,2,0,0,0,0,2,0,0,0,0,0,0,0,"Rot Hide Plague Weaver - In Combat - Cast Curse of Thule"),
(1940,0,1,0,0,0,100,0,3000,14000,25000,40000,11,3256,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rot Hide Plague Weaver - In Combat - Cast Plague Cloud"),
(1940,0,2,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rot Hide Plague Weaver - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1940;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1940,0,0,"Grrrrr!",12,0,100,0,0,0,1869,0,"Rot Hide Plague Weaver"),
(1940,0,1,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Rot Hide Plague Weaver"),
(1940,0,2,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Rot Hide Plague Weaver");

-- Rot Hide Savage
DELETE FROM `smart_scripts` WHERE `entryorguid`=1942 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1942,0,0,0,0,0,100,0,2000,18000,30000,45000,11,3237,2,0,0,0,0,2,0,0,0,0,0,0,0,"Rot Hide Savage - In Combat - Cast Curse of Thule"),
(1942,0,1,0,0,0,100,0,3000,8000,7000,14000,11,3258,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rot Hide Savage - In Combat - Cast Savage Rage"),
(1942,0,2,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rot Hide Savage - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1942;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1942,0,0,"Grrrrr!",12,0,100,0,0,0,1869,0,"Rot Hide Savage"),
(1942,0,1,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Rot Hide Savage"),
(1942,0,2,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Rot Hide Savage");

-- Raging Rot Hide
DELETE FROM `smart_scripts` WHERE `entryorguid`=1943 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1943,0,0,0,0,0,100,0,2000,18000,30000,45000,11,3237,2,0,0,0,0,2,0,0,0,0,0,0,0,"Raging Rot Hide - In Combat - Cast Curse of Thule"),
(1943,0,1,0,4,0,15,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Rot Hide - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1943;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1943,0,0,"Grrrrr!",12,0,100,0,0,0,1869,0,"Raging Rot Hide"),
(1943,0,1,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Raging Rot Hide"),
(1943,0,2,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Raging Rot Hide");

-- Snarlmane
DELETE FROM `smart_scripts` WHERE `entryorguid`=1948 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1948,0,0,0,0,0,100,0,4000,8000,12000,16000,11,3387,34,0,0,0,0,2,0,0,0,0,0,0,0,"Snarlmane - In Combat - Cast Rage of Thule");

-- Thule Ravenclaw
DELETE FROM `smart_scripts` WHERE `entryorguid`=1947 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1947,0,0,0,0,0,100,0,6000,8000,20000,30000,11,7655,0,0,0,0,0,5,0,0,0,0,0,0,0,"Thule Ravenclaw - In Combat - Cast Hex of Ravenclaw"),
(1947,0,1,0,0,0,100,0,3000,5000,7000,12000,11,20800,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thule Ravenclaw - In Combat - Cast Immolate"),
(1947,0,2,0,1,0,100,1,1000,1000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thule Ravenclaw - Out of Combat - Cast Summon Imp (No Repeat)"),
(1947,0,3,0,4,0,100,1,0,0,0,0,11,13787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thule Ravenclaw - On Aggro - Cast Demon Armor"),
(1947,0,4,0,1,0,100,0,10000,10000,300000,300000,80,194700,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - Out of Combat - Run Script'),
(1947,0,5,0,11,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Respawn - Set Active');

-- Dalaran Protector
DELETE FROM `smart_scripts` WHERE `entryorguid`=1912 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1912,0,0,0,4,0,100,0,0,0,0,0,11,3615,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Protector - On Aggro - Cast Summon Dalaran Serpent");

-- Dalaran Warder
DELETE FROM `smart_scripts` WHERE `entryorguid`=1913 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1913,0,0,0,4,0,100,0,0,0,0,0,11,3615,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Warder - On Aggro - Cast Summon Dalaran Serpent");

-- Dalaran Apprentice
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=1867 AND `source_type`=0 AND `id`=1;

-- Dalaran Mage
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=1914 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=1914 AND `source_type`=0 AND `id` IN (1,2);

-- Dalaran Wizard
DELETE FROM `smart_scripts` WHERE `entryorguid`=1889 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1889,0,2,0,9,0,100,0,0,8,9000,14000,11,11831,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Wizard - Within 0-8 Range - Cast Frost Nova");

-- Dalaran Watcher
DELETE FROM `smart_scripts` WHERE `entryorguid`=1888 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1888,0,0,0,4,0,100,0,0,0,0,0,11,134,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Watcher - On Aggro - Cast Fire Shield"),
(1888,0,1,0,0,0,100,0,3000,6000,9000,12000,11,11829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Watcher - In Combat - Cast Flamestrike"),
(1888,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Watcher - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Dalaran Apprentice
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=1915 AND `source_type`=0 AND `id`=2;

-- Dalaran Brewmaster
DELETE FROM `smart_scripts` WHERE `entryorguid`=3577 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3577,0,0,0,14,0,150,0,100,40,6000,8000,11,7638,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dalaran Brewmaster - Friendly At 150 Health - Cast Potion Toss");

-- Dalaran Spellscribe
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=1920 AND `source_type`=0 AND `id`=1;

-- Archmage Ataeric
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=2120 AND `source_type`=0 AND `id`=0;

-- Sickly Refugee
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2054;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2054 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2054,0,0,0,0,0,100,0,9000,13000,15000,19000,11,1776,2,0,0,0,0,2,0,0,0,0,0,0,0,"Sickly Refugee - In Combat - Cast Gouge"),
(2054,0,1,0,0,0,100,0,5000,8000,12000,16000,11,101,2,0,0,0,0,2,0,0,0,0,0,0,0,"Sickly Refugee - In Combat - Cast Trip"),
(2054,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sickly Refugee - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Haggard Refugee
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2053;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2053 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2053,0,0,0,0,0,100,0,3000,9000,20000,26000,11,3261,0,0,0,0,0,2,0,0,0,0,0,0,0,"Haggard Refugee - In Combat - Cast Ignite");

-- Valdred Moray
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2332;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2332 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2332,0,0,0,0,0,100,0,6000,11000,9000,14000,11,14873,2,0,0,0,0,2,0,0,0,0,0,0,0,"Valdred Moray - In Combat - Cast Sinister Strike"),
(2332,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valdred Moray - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Moonrage Watcher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1892;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1892 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1892,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonrage Watcher - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Pyrewood Watcher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1891;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1891 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1891,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pyrewood Watcher - Between 0-15% Health - Flee For Assist (No Repeat)"),
(1891,0,1,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Pyrewood Watcher - In Combat - Cast Shoot");

-- Moonrage Sentry
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1893;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1893 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1893,0,0,0,0,0,100,0,8000,12000,31000,36000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonrage Sentry - In Combat - Cast Demoralizing Shout"),
(1893,0,1,0,0,0,100,0,2000,5000,43000,48000,11,6507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonrage Sentry - In Combat - Cast Battle Roar");

-- Pyrewood Sentry
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1894;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1894 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1894,0,0,0,4,0,100,0,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pyrewood Sentry - On Aggro - Cast Defensive Stance"),
(1894,0,1,0,0,0,100,0,6000,8000,12000,16000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pyrewood Sentry - In Combat - Cast Shield Block"),
(1894,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pyrewood Sentry - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Moonrage Tailor
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3531;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3531 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3531,0,0,0,0,0,100,0,10000,13000,19000,22000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moonrage Tailor - In Combat - Cast Disarm"),
(3531,0,1,0,67,0,100,1,0,0,0,0,11,15657,2,0,0,0,0,2,0,0,0,0,0,0,0,"Moonrage Tailor - On Behind Target - Cast Backstab (No Repeat)"),
(3531,0,2,0,9,0,100,0,0,5,17000,23000,11,7140,0,0,0,0,0,2,0,0,0,0,0,0,0,"Moonrage Tailor - Within 0-5 Range - Cast Expose Weakness");

-- Pyrewood Tailor
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3530;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3530 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3530,0,0,0,0,0,100,0,10000,13000,19000,22000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pyrewood Tailor - In Combat - Cast Disarm"),
(3530,0,1,0,67,0,100,1,0,0,0,0,11,15657,2,0,0,0,0,2,0,0,0,0,0,0,0,"Pyrewood Tailor - On Behind Target - Cast Backstab (No Repeat)"),
(3530,0,2,0,9,0,100,0,0,5,17000,23000,11,7140,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pyrewood Tailor - Within 0-5 Range - Cast Expose Weakness");

-- Ravenclaw Drudger
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=1974 AND `source_type`=0;

-- Random movement for some creatures
UPDATE `creature` SET `MovementType`=1, `spawndist`=25 WHERE `id` IN (6033, 2173);
UPDATE `creature` SET `MovementType`=1, `spawndist`=10 WHERE `guid`=26125;

-- Correct spawn position and add random movement for some creatures
UPDATE `creature` SET `position_x`=1228.81, `position_y`=395.465, `position_z`=27.4251, `MovementType`=1, `spawndist`=5 WHERE `guid`=17639;
UPDATE `creature` SET `position_x`=-551.273, `position_y`=1136.9, `position_z`=89.1978, `MovementType`=1, `spawndist`=5 WHERE `guid`=17610;
*/
