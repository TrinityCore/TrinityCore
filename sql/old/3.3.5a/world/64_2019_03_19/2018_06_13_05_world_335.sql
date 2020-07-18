-- Great Goretusk
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=547 AND `source_type`=0 AND `id`=0;

-- Tarantula
DELETE FROM `smart_scripts` WHERE `entryorguid`=442 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(442,0,0,0,25,0,100,0,0,0,0,0,0,11,11959,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarantula - On Reset - Cast 'Poison Proc'");

-- Greater Tarantula
DELETE FROM `smart_scripts` WHERE `entryorguid`=505 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(505,0,0,0,25,0,100,0,0,0,0,0,0,11,11959,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greater Tarantula - On Reset - Cast 'Poison Proc'");

-- Chatter
DELETE FROM `smart_scripts` WHERE `entryorguid`=616 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(616,0,0,0,25,0,100,0,0,0,0,0,0,11,11959,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chatter - On Reset - Cast 'Poison Proc'");

-- Redridge Mongrel
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid`=423 AND `source_type`=0 AND `id`=0;

DELETE FROM `creature_text` WHERE `CreatureID`=423 AND `GroupID`=0 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(423,0,2,"Grrrrr!",12,0,100,0,0,0,1869,0,"Redridge Mongrel");

-- Redridge Thrasher
DELETE FROM `smart_scripts` WHERE `entryorguid`=712 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(712,0,1,0,4,0,15,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Thrasher - On Aggro - Say Line 0"),
(712,0,2,0,25,0,100,0,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redridge Thrasher - On Reset - Cast 'Thrash'");

DELETE FROM `creature_text` WHERE `CreatureID`=712;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(712,0,0,"Grrrrr!",12,0,100,0,0,0,1869,0,"Redridge Thrasher"),
(712,0,1,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Redridge Thrasher"),
(712,0,2,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Redridge Thrasher");

-- Redridge Poacher
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid`=424 AND `source_type`=0 AND `id`=0;

DELETE FROM `creature_text` WHERE `CreatureID`=424 AND `GroupID`=0 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(424,0,2,"Grrrrr!",12,0,100,0,0,0,1869,0,"Redridge Poacher");

-- Redridge Brute
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid`=426 AND `source_type`=0 AND `id`=0;

DELETE FROM `creature_text` WHERE `CreatureID`=426 AND `GroupID`=0 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(426,0,2,"Grrrrr!",12,0,100,0,0,0,1869,0,"Redridge Brute");

-- Redridge Mystic
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid`=430 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=430 AND `source_type`=0 AND `id`=1;

DELETE FROM `creature_text` WHERE `CreatureID`=430 AND `GroupID`=0 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(430,0,2,"Grrrrr!",12,0,100,0,0,0,1869,0,"Redridge Mystic");

-- Redridge Basher
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid`=446 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_param1`=5000, `event_param2`=9000, `event_param3`=15000, `event_param4`=19000 WHERE `entryorguid`=446 AND `source_type`=0 AND `id`=1;

DELETE FROM `creature_text` WHERE `CreatureID`=446 AND `GroupID`=0 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(446,0,2,"Grrrrr!",12,0,100,0,0,0,1869,0,"Redridge Basher");

-- Redridge Alpha
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid`=445 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_param1`=5000, `event_param2`=7000, `event_param3`=14000, `event_param4`=18000 WHERE `entryorguid`=445 AND `source_type`=0 AND `id`=1;

DELETE FROM `creature_text` WHERE `CreatureID`=445 AND `GroupID`=0 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(445,0,2,"Grrrrr!",12,0,100,0,0,0,1869,0,"Redridge Alpha");

-- Redridge Drudger
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid`=580 AND `source_type`=0 AND `id`=0;

DELETE FROM `creature_text` WHERE `CreatureID`=580 AND `GroupID`=0 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(580,0,2,"Grrrrr!",12,0,100,0,0,0,1869,0,"Redridge Drudger");

-- Shadowhide Warrior
DELETE FROM `smart_scripts` WHERE `entryorguid`=568 AND `source_type`=0 AND `id` IN (0,1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(568,0,0,0,4,0,15,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Warrior - On Aggro - Say Line 0"),
(568,0,1,0,4,0,100,0,0,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Warrior - On Aggro - Cast 'Defensive Stance'"),
(568,0,2,0,0,0,100,0,5000,9000,11000,17000,0,11,7405,2,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowhide Warrior - In Combat - Cast 'Sunder Armor'");

DELETE FROM `creature_text` WHERE `CreatureID`=568 AND `GroupID`=0 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(568,0,2,"Grrrrr!",12,0,100,0,0,0,1869,0,"Shadowhide Warrior");

-- Shadowhide Slayer
DELETE FROM `smart_scripts` WHERE `entryorguid`=431 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(431,0,2,0,4,0,15,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Slayer - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=431;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(431,0,0,"Grrrrr!",12,0,100,0,0,0,1869,0,"Shadowhide Slayer"),
(431,0,1,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Shadowhide Slayer"),
(431,0,2,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Shadowhide Slayer");

-- Shadowhide Darkweaver
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid`=429 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=429 AND `source_type`=0 AND `id`=1;

DELETE FROM `creature_text` WHERE `CreatureID`=429 AND `GroupID`=0 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(429,0,2,"Grrrrr!",12,0,100,0,0,0,1869,0,"Shadowhide Darkweaver");

-- Shadowhide Brute
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid`=432 AND `source_type`=0 AND `id`=0;

DELETE FROM `creature_text` WHERE `CreatureID`=432 AND `GroupID`=0 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(432,0,2,"Grrrrr!",12,0,100,0,0,0,1869,0,"Shadowhide Brute");

-- Shadowhide Gnoll
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid`=433 AND `source_type`=0 AND `id`=0;

DELETE FROM `creature_text` WHERE `CreatureID`=433 AND `GroupID`=0 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(433,0,2,"Grrrrr!",12,0,100,0,0,0,1869,0,"Shadowhide Gnoll");

-- Rabid Shadowhide Gnoll
DELETE FROM `smart_scripts` WHERE `entryorguid`=434 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(434,0,1,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rabid Shadowhide Gnoll - On Reset - Cast 'Poison Proc'");

DELETE FROM `creature_text` WHERE `CreatureID`=434 AND `GroupID`=0 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(434,0,2,"Grrrrr!",12,0,100,0,0,0,1869,0,"Rabid Shadowhide Gnoll");

-- Shadowhide Assassin
DELETE FROM `smart_scripts` WHERE `entryorguid`=579 AND `source_type`=0 AND `ID` IN (0,2,4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(579,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Assassin - On Reset - Cast 'Poison Proc'"),
(579,0,2,0,25,0,100,0,0,0,0,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Assassin - On Reset - Cast 'Stealth'"),
(579,0,4,0,4,0,15,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhide Assassin - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=579;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(579,0,0,"Grrrrr!",12,0,100,0,0,0,1869,0,"Shadowhide Assassin"),
(579,0,1,"Grrrr... fresh meat!",12,0,100,0,0,0,1870,0,"Shadowhide Assassin"),
(579,0,2,"More bones to gnaw on...",12,0,100,0,0,0,1871,0,"Shadowhide Assassin");

-- Rohh the Silent
DELETE FROM `smart_scripts` WHERE `entryorguid`=947 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(947,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rohh the Silent - On Reset - Cast 'Poison Proc'"),
(947,0,1,0,25,0,100,0,0,0,0,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rohh the Silent - On Reset - Cast 'Stealth'");

-- Murloc Flesheater
DELETE FROM `smart_scripts` WHERE `entryorguid`=422 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(422,0,0,0,25,0,100,0,0,0,0,0,0,11,3394,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Flesheater - On Reset - Cast 'Consume Flesh'");

-- Murloc Minor Tidecaller
DELETE FROM `smart_scripts` WHERE `entryorguid`=548 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(548,0,1,0,14,0,100,0,180,40,25000,35000,0,11,547,0,0,0,0,0,7,0,0,0,0,0,0,0,"Murloc Minor Tidecaller - Friendly At 180 Health - Cast 'Heal'");

-- Murloc Tidecaller
DELETE FROM `smart_scripts` WHERE `entryorguid`=545 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(545,0,1,0,14,0,100,0,200,40,23000,26000,0,11,913,0,0,0,0,0,7,0,0,0,0,0,0,0,"Murloc Tidecaller - Friendly At 200 Health - Cast 'Healing Wave'");

-- Murloc Nightcrawler
DELETE FROM `smart_scripts` WHERE `entryorguid`=544 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(544,0,0,0,25,0,100,0,0,0,0,0,0,11,8601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Nightcrawler - On Reset - Cast 'Slowing Poison'");

-- Murloc Scout
DELETE FROM `smart_scripts` WHERE `entryorguid`=578 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(578,0,0,0,0,0,100,0,5000,7000,13000,15000,0,11,7357,2,0,0,0,0,2,0,0,0,0,0,0,0,"Murloc Scout - In Combat - Cast 'Poisonous Stab'");

-- Blackrock Outrunner / Blackrock Grunt / Blackrock Renegade / Blackrock Sentry / Blackrock Shadowcaster / Blackrock Hunter / Blackrock Tracker / Blackrock Champion
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid` IN (485,440,437,4065,436,4462,615,435) AND `source_type`=0 AND `id`=0;

-- Blackrock Summoner
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid`=4463 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=4463 AND `source_type`=0 AND `id` IN (3,4);

-- Blackrock Scout
DELETE FROM `smart_scripts` WHERE `entryorguid`=4064 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4064,0,4,0,4,0,15,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Scout - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=4064 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4064,1,0,"Feel the power of the Blackrock Orcs!",12,1,100,0,0,0,1874,0,"Blackrock Scout"),
(4064,1,1,"You are no match for the Blackrock Orcs!",12,1,100,0,0,0,1875,0,"Blackrock Scout");

-- Blackrock Shadowcaster
UPDATE `smart_scripts` SET `action_param2`=0 WHERE `entryorguid`=436 AND `source_type`=0 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=436 AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(436,0,5,0,0,0,100,0,4000,8000,18000,24000,0,11,8994,0,0,0,0,0,6,0,0,0,0,0,0,0,"Blackrock Shadowcaster - In Combat - Cast 'Banish'");

-- Blackrock Gladiator
DELETE FROM `smart_scripts` WHERE `entryorguid`=4464 AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4464,0,6,0,4,0,15,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Gladiator - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=4464 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4464,1,0,"Feel the power of the Blackrock Orcs!",12,1,100,0,0,0,1874,0,"Blackrock Gladiator"),
(4464,1,1,"You are no match for the Blackrock Orcs!",12,1,100,0,0,0,1875,0,"Blackrock Gladiator");

-- Blackrock Hunter
UPDATE `smart_scripts` SET `event_param1`=6000, `event_param2`=15000, `event_param3`=19000, `event_param4`=28000 WHERE `entryorguid`=4462 AND `source_type`=0 AND `id`=2;

-- Gath'Ilzogg
DELETE FROM `smart_scripts` WHERE `entryorguid`=334 AND `source_type`=0 AND `ID` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(334,0,1,0,0,0,100,0,7000,9000,32000,39000,0,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gath'Ilzogg - In Combat - Cast 'Infected Wound'"),
(334,0,2,0,0,0,100,0,5000,7000,12000,16000,0,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gath'Ilzogg - In Combat - Cast 'Shield Bash'");

-- Servant of Ilgalar
UPDATE `smart_scripts` SET `event_param1`=1000, `event_param2`=9000, `event_param3`=13000, `event_param4`=21000 WHERE `entryorguid`=819 AND `source_type`=0 AND `id`=0;

-- Morganth
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=397 AND `source_type`=0 AND `id`=1;

-- Minion of Morganth
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2531;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2531 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2531,0,0,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,40,0,0,0,0,0,0,"Minion of Morganth - Just Summoned - Start Attacking");

-- Kazon
UPDATE `smart_scripts` SET `event_param1`=6000, `event_param2`=9000, `event_param3`=11000, `event_param4`=17000 WHERE `entryorguid`=584 AND `source_type`=0 AND `id`=0;

-- Blackrock Champion
DELETE FROM `smart_scripts` WHERE `entryorguid`=435 AND `source_type`=0 AND `id`=5;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=435 AND `source_type`=0 AND `id`=4;

-- Kobold Digger / Kobold Tunneler / Kobold Worker / Kobold Laborer / Kobold Vermin
DELETE FROM `creature_text` WHERE `CreatureID` IN (1236,475,257,80,6) AND `GroupID`=0 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1236,0,2,"No kill me! No kill me!",12,0,100,0,0,0,1863,0,"Kobold Digger"),
(475,0,2,"No kill me! No kill me!",12,0,100,0,0,0,1863,0,"Kobold Tunneler"),
(257,0,2,"No kill me! No kill me!",12,0,100,0,0,0,1863,0,"Kobold Worker"),
(80,0,2,"No kill me! No kill me!",12,0,100,0,0,0,1863,0,"Kobold Laborer"),
(6,0,2,"No kill me! No kill me!",12,0,100,0,0,0,1863,0,"Kobold Vermin");

-- Kobold Geomancer / Kobold Miner / Goldtooth
DELETE FROM `creature_text` WHERE `CreatureID` IN (327,476,40) AND `GroupID`=0 AND `ID` IN (1,2);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(327,0,1,"You no take candle!",12,0,100,0,0,0,1868,0,"Goldtooth"),
(327,0,2,"No kill me! No kill me!",12,0,100,0,0,0,1863,0,"Goldtooth"),
(476,0,1,"Yiieeeee! Me run!",12,0,100,0,0,0,1864,0,"Kobold Geomancer"),
(476,0,2,"No kill me! No kill me!",12,0,100,0,0,0,1863,0,"Kobold Geomancer"),
(40,0,1,"Yiieeeee! Me run!",12,0,100,0,0,0,1864,0,"Kobold Miner"),
(40,0,2,"No kill me! No kill me!",12,0,100,0,0,0,1863,0,"Kobold Miner");

-- Fix spawn position and movement for some creatures
UPDATE `creature` SET `position_x`=-9299.74, `position_y`=-1889.38, `position_z`=76.523 WHERE `guid`=6707; -- inside a tree
UPDATE `creature` SET `position_z`=77.7874 WHERE `guid`=6707;
UPDATE `creature` SET `position_z`=64.0717 WHERE `guid`=6261;
UPDATE `creature` SET `position_x`=-9286.79, `position_y`=-1926.36, `position_z`=72.0246, `spawndist`=10, `MovementType`=1 WHERE `guid`=10105;

-- Fix spawn position for some objects
UPDATE `gameobject` SET `position_x`=-9668.03, `position_y`=-2031.67, `position_z`=60.3287, `orientation`=4.497 WHERE `guid`=5242; -- inside a rock
UPDATE `gameobject` SET `position_x`=-8964.17, `position_y`=-2652.36, `position_z`=154.183, `orientation`=4.79 WHERE `guid`=5637; -- beneath the ground
UPDATE `gameobject` SET `position_x`=-9102.35, `position_y`=-2805.85, `position_z`=118.746, `orientation`=4.97 WHERE `guid`=5632; -- unreachable
UPDATE `gameobject` SET `position_x`=-9047.56, `position_y`=-3322.43, `position_z`=106.844, `orientation`=4.673 WHERE `guid`=5632; -- inside a tree
