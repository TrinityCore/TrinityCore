/*
-- Azure Templar
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15211;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15211 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15211,0,0,0,0,0,100,0,3000,5000,8000,12000,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Templar - In Combat - Cast Frost Shock"),
(15211,0,1,0,0,0,100,0,7000,9000,11000,15000,11,14907,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Templar - In Combat - Cast Frost Nova");

DELETE FROM `creature_text` WHERE `CreatureID`=15211 AND `ID`>0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15211,0,1,"My lord will be outraged to learn of this ambush.  Let us hope your death will appease him.",12,0,100,0,0,0,10694,0,"Azure Templar"),
(15211,0,2,"It is my duty and honor to die for the Abyssal Council!",12,0,100,0,0,0,10695,0,"Azure Templar"),
(15211,0,3,"Your life is a fitting sacrifice for my master, $c.",12,0,100,0,0,0,10696,0,"Azure Templar");

-- Earthen Templar
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15307;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15307 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15307,0,0,0,0,0,100,0,2000,3000,13000,15000,11,22127,2,0,0,0,0,2,0,0,0,0,0,0,0,"Earthen Templar - In Combat - Cast Entangling Roots"),
(15307,0,1,0,0,0,100,0,7000,9000,12000,16000,11,18813,0,0,0,0,0,2,0,0,0,0,0,0,0,"Earthen Templar - In Combat - Cast Knock Away");

DELETE FROM `creature_text` WHERE `CreatureID`=15307 AND `ID`>0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15307,0,1,"My lord will be outraged to learn of this ambush.  Let us hope your death will appease him.",12,0,100,0,0,0,10694,0,"Earthen Templar"),
(15307,0,2,"It is my duty and honor to die for the Abyssal Council!",12,0,100,0,0,0,10695,0,"Earthen Templar"),
(15307,0,3,"Your life is a fitting sacrifice for my master, $c.",12,0,100,0,0,0,10696,0,"Earthen Templar");

-- Hoary Templar
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15212;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15212 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15212,0,0,0,0,0,100,0,3000,5000,7000,11000,11,2610,2,0,0,0,0,2,0,0,0,0,0,0,0,"Hoary Templar - In Combat - Cast Shock"),
(15212,0,1,0,4,0,100,0,0,0,0,0,11,25020,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hoary Templar - On Aggro - Cast Lightning Shield");

DELETE FROM `creature_text` WHERE `CreatureID`=15212 AND `ID`>0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15212,0,1,"My lord will be outraged to learn of this ambush.  Let us hope your death will appease him.",12,0,100,0,0,0,10694,0,"Hoary Templar"),
(15212,0,2,"It is my duty and honor to die for the Abyssal Council!",12,0,100,0,0,0,10695,0,"Hoary Templar"),
(15212,0,3,"Your life is a fitting sacrifice for my master, $c.",12,0,100,0,0,0,10696,0,"Hoary Templar");

-- Crimson Templar
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15209;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15209 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15209,0,0,0,0,0,100,0,4000,6000,7000,11000,11,11989,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Templar - In Combat - Cast Fireball Volley"),
(15209,0,1,0,0,0,100,0,2000,3000,11000,15000,11,16536,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Templar - In Combat - Cast Flame Buffet");

DELETE FROM `creature_text` WHERE `CreatureID`=15209 AND `ID`>0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15209,0,1,"My lord will be outraged to learn of this ambush.  Let us hope your death will appease him.",12,0,100,0,0,0,10694,0,"Crimson Templar"),
(15209,0,2,"It is my duty and honor to die for the Abyssal Council!",12,0,100,0,0,0,10695,0,"Crimson Templar"),
(15209,0,3,"Your life is a fitting sacrifice for my master, $c.",12,0,100,0,0,0,10696,0,"Crimson Templar");

-- The Duke of Cynders
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15206;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15206 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15206,0,0,0,0,0,100,0,3000,6000,6000,9000,11,25028,0,0,0,0,0,5,0,0,0,0,0,0,0,"The Duke of Cynders - In Combat - Cast Fire Blast"),
(15206,0,1,0,0,0,100,0,8000,14000,12000,17000,11,18399,0,0,0,0,0,5,0,0,0,0,0,0,0,"The Duke of Cynders - In Combat - Cast Flamestrike"),
(15206,0,2,0,0,0,100,0,6000,10000,8000,12000,11,22424,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Duke of Cynders - In Combat - Cast Blast Wave");

DELETE FROM `creature_text` WHERE `CreatureID`=15206 AND `ID`>0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15206,0,1,"You will pay the ultimate price for this insolence, little vermin.  Your soul is mine!",12,0,100,0,0,0,10801,0,"The Duke of Cynders"),
(15206,0,2,"This act of defiance will not go unpunished.  You, and your world, will die!",12,0,100,0,0,0,10802,0,"The Duke of Cynders"),
(15206,0,3,"Imposter!  It is a dishonor without equal to be summoned by a whelp such as you!  DIE!",12,0,100,0,0,0,10804,0,"The Duke of Cynders");

-- The Duke of Fathoms
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15207;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15207 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15207,0,0,0,4,0,100,0,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Duke of Fathoms - On Aggro - Cast Thrash"),
(15207,0,1,0,0,0,100,0,8000,12000,8000,12000,11,16790,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Duke of Fathoms - In Combat - Cast Knockdown"),
(15207,0,2,0,0,0,100,0,3000,6000,10000,15000,11,18670,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Duke of Fathoms - In Combat - Cast Knock Away");

DELETE FROM `creature_text` WHERE `CreatureID`=15207 AND `ID`>0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15207,0,1,"You will pay the ultimate price for this insolence, little vermin.  Your soul is mine!",12,0,100,0,0,0,10801,0,"The Duke of Fathoms"),
(15207,0,2,"This act of defiance will not go unpunished.  You, and your world, will die!",12,0,100,0,0,0,10802,0,"The Duke of Fathoms"),
(15207,0,3,"Imposter!  It is a dishonor without equal to be summoned by a whelp such as you!  DIE!",12,0,100,0,0,0,10804,0,"The Duke of Fathoms");

-- The Duke of Shards
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15208;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15208 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15208,0,0,0,0,0,100,0,4000,6000,4000,6000,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Duke of Shards - In Combat - Cast Strike"),
(15208,0,1,0,0,0,100,0,8000,12000,13000,17000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Duke of Shards - In Combat - Cast Thunderclap"),
(15208,0,2,0,0,0,100,0,6000,10000,10000,15000,11,6524,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Duke of Shards - In Combat - Cast Ground Tremor");

DELETE FROM `creature_text` WHERE `CreatureID`=15208 AND `ID`>0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15208,0,1,"You will pay the ultimate price for this insolence, little vermin.  Your soul is mine!",12,0,100,0,0,0,10801,0,"The Duke of Shards"),
(15208,0,2,"This act of defiance will not go unpunished.  You, and your world, will die!",12,0,100,0,0,0,10802,0,"The Duke of Shards"),
(15208,0,3,"Imposter!  It is a dishonor without equal to be summoned by a whelp such as you!  DIE!",12,0,100,0,0,0,10804,0,"The Duke of Shards");

-- The Duke of Zephyrs
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15220;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15220 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15220,0,0,0,0,0,100,0,5000,8000,14000,18000,11,25034,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Duke of Zephyrs - In Combat - Cast Forked Lightning"),
(15220,0,1,0,0,0,100,0,10000,12000,18000,22000,11,44417,0,0,0,0,0,5,0,0,0,0,0,0,0,"The Duke of Zephyrs - In Combat - Cast Lightning Cloud"),
(15220,0,2,0,0,0,100,0,5000,15000,10000,15000,11,12882,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Duke of Zephyrs - In Combat - Cast Wing Flap"),
(15220,0,3,0,0,0,100,0,8000,20000,8000,20000,11,15535,0,0,0,0,0,5,0,0,0,0,0,0,0,"The Duke of Zephyrs - In Combat - Cast Enveloping Winds");

DELETE FROM `creature_text` WHERE `CreatureID`=15220 AND `ID`>0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15220,0,1,"You will pay the ultimate price for this insolence, little vermin.  Your soul is mine!",12,0,100,0,0,0,10801,0,"The Duke of Zephyrs"),
(15220,0,2,"This act of defiance will not go unpunished.  You, and your world, will die!",12,0,100,0,0,0,10802,0,"The Duke of Zephyrs"),
(15220,0,3,"Imposter!  It is a dishonor without equal to be summoned by a whelp such as you!  DIE!",12,0,100,0,0,0,10804,0,"The Duke of Zephyrs");

-- Prince Skaldrenox
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15203;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15203 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15203,0,0,0,0,0,100,0,4000,6000,20000,30000,11,25050,0,0,0,0,0,4,0,0,0,0,0,0,0,"Prince Skaldrenox - In Combat - Cast Mark of Flames"),
(15203,0,1,0,0,0,100,0,8000,10000,15000,24000,11,25049,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Skaldrenox - In Combat - Cast Blastwave"),
(15203,0,2,0,0,0,100,0,7000,8000,7000,8000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Skaldrenox - In Combat - Cast Cleave");

DELETE FROM `creature_text` WHERE `CreatureID`=15203 AND `ID`>0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15203,0,1,"You dare!  Outrageous!  I curse you, $c.  I curse you with... death!",14,0,100,0,0,0,10806,0,"Prince Skaldrenox"),
(15203,0,2,"What?  Such a small, frail thing beckons me?  I shall add your bones to my throne, $r!!",14,0,100,0,0,0,10807,0,"Prince Skaldrenox"),
(15203,0,3,"Killing you and your cohorts, $c, will amuse me.  I shall make it quick.",14,0,100,0,0,0,10810,0,"Prince Skaldrenox");

-- High Marshal Whirlaxis
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15204;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15204 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15204,0,0,0,0,0,100,0,0,0,5000,5000,11,25020,32,0,0,0,0,1,0,0,0,0,0,0,0,"High Marshal Whirlaxis - In Combat - Cast Lightning Shield"),
(15204,0,1,0,0,0,100,0,9000,11000,21000,26000,11,23103,0,0,0,0,0,5,0,0,0,0,0,0,0,"High Marshal Whirlaxis - In Combat - Cast Enveloping Winds"),
(15204,0,2,0,0,0,100,0,17000,20000,17000,20000,11,25060,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Marshal Whirlaxis - In Combat - Cast Updraft");

DELETE FROM `creature_text` WHERE `CreatureID`=15204 AND `ID`>0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15204,0,1,"You dare!  Outrageous!  I curse you, $c.  I curse you with... death!",14,0,100,0,0,0,10806,0,"High Marshal Whirlaxis"),
(15204,0,2,"What?  Such a small, frail thing beckons me?  I shall add your bones to my throne, $r!!",14,0,100,0,0,0,10807,0,"High Marshal Whirlaxis"),
(15204,0,3,"Killing you and your cohorts, $c, will amuse me.  I shall make it quick.",14,0,100,0,0,0,10810,0,"High Marshal Whirlaxis");

-- Baron Kazum
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15205;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15205 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15205,0,0,0,0,0,100,0,3000,6000,13000,16000,11,25056,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Kazum - In Combat - Cast Stomp"),
(15205,0,1,0,0,0,100,0,7000,10000,15000,28000,11,19129,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Kazum - In Combat - Cast Massive Tremor"),
(15205,0,2,0,0,0,100,0,12000,15000,15000,18000,11,17547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Baron Kazum - In Combat - Cast Mortal Strike");

DELETE FROM `creature_text` WHERE `CreatureID`=15205 AND `ID`>0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15205,0,1,"You dare!  Outrageous!  I curse you, $c.  I curse you with... death!",14,0,100,0,0,0,10806,0,"Baron Kazum"),
(15205,0,2,"What?  Such a small, frail thing beckons me?  I shall add your bones to my throne, $r!!",14,0,100,0,0,0,10807,0,"Baron Kazum"),
(15205,0,3,"Killing you and your cohorts, $c, will amuse me.  I shall make it quick.",14,0,100,0,0,0,10810,0,"Baron Kazum");

-- Lord Skwol
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15305;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15305 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15305,0,0,0,4,0,100,0,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Skwol - On Aggro - Cast Thrash"),
(15305,0,1,0,0,0,100,0,10000,12000,18000,20000,11,25053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Skwol - In Combat - Cast Venom Spit"),
(15305,0,2,0,0,0,100,0,2000,3000,5000,8000,11,25051,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Skwol - In Combat - Cast Sunder Armor");

DELETE FROM `creature_text` WHERE `CreatureID`=15305 AND `ID`>0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15305,0,1,"You dare!  Outrageous!  I curse you, $c.  I curse you with... death!",14,0,100,0,0,0,10806,0,"Lord Skwol"),
(15305,0,2,"What?  Such a small, frail thing beckons me?  I shall add your bones to my throne, $r!!",14,0,100,0,0,0,10807,0,"Lord Skwol"),
(15305,0,3,"Killing you and your cohorts, $c, will amuse me.  I shall make it quick.",14,0,100,0,0,0,10810,0,"Lord Skwol");
*/
