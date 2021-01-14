-- Deeprot Stomper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=13141;
DELETE FROM `smart_scripts` WHERE `entryorguid`=13141 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(13141,0,0,0,0,0,100,2,11000,16000,15000,21000,11,11876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deeprot Stomper - In Combat - Cast War Stomp"),
(13141,0,1,0,0,0,100,2,5000,8000,7000,10000,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deeprot Stomper - In Combat - Cast Strike");

-- Deeprot Tangler
DELETE FROM `smart_scripts` WHERE `entryorguid`=13142 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(13142,0,0,0,1,0,100,2,1000,1000,600000,600000,11,21337,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deeprot Tangler - Out of Combat - Cast Thorns"),
(13142,0,1,0,0,0,100,2,3000,5000,17000,21000,11,21331,0,0,0,0,0,5,0,0,0,0,0,0,0,"Deeprot Tangler - In Combat - Cast Entangling Roots");

-- Poison Sprite
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12216;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12216 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12216,0,0,0,0,0,100,2,0,0,3000,4500,11,21067,64,0,0,0,0,2,0,0,0,0,0,0,0,"Poison Sprite - In Combat - Cast Poison Bolt");

-- Corruptor
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12217;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12217 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12217,0,0,0,9,0,100,2,0,5,30000,45000,11,5413,0,0,0,0,0,2,0,0,0,0,0,0,0,"Corruptor - Within 0-5 Range - Cast Noxious Catalyst"),
(12217,0,1,0,0,0,100,2,2000,5000,14000,21000,11,21068,0,0,0,0,0,5,0,0,0,0,0,0,0,"Corruptor - In Combat - Cast Corruption");

-- Putridus Satyr
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11790;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11790 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11790,0,0,0,9,0,100,2,0,5,7000,11000,11,12540,0,0,0,0,0,5,0,0,0,0,0,0,0,"Putridus Satyr - Within 0-5 Range - Cast Gouge"),
(11790,0,1,0,0,0,100,2,6000,8000,22000,25000,11,21062,0,0,0,0,0,5,0,0,0,0,0,0,0,"Putridus Satyr - In Combat - Cast Putrid Breath"),
(11790,0,2,0,0,0,100,2,8000,15000,12000,15000,11,15667,0,0,0,0,0,2,0,0,0,0,0,0,0,"Putridus Satyr - In Combat - Cast Sinister Strike");

-- Putridus Shadowstalker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11792;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11792 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11792,0,0,0,0,0,100,2,8000,16000,21000,30000,11,15087,0,0,0,0,0,1,0,0,0,0,0,0,0,"Putridus Shadowstalker - In Combat - Cast Evasion"),
(11792,0,1,0,9,0,100,2,0,5,12000,15000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Putridus Shadowstalker - Within 0-5 Range - Cast Hamstring"),
(11792,0,2,0,0,0,100,2,6000,8000,22000,25000,11,21062,0,0,0,0,0,5,0,0,0,0,0,0,0,"Putridus Shadowstalker - In Combat - Cast Putrid Breath"),
(11792,0,3,0,25,0,100,2,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Putridus Shadowstalker - On Reset - Cast Sneak");

-- Putridus Trickster
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11791;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11791 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11791,0,0,0,67,0,100,2,5000,8000,0,0,11,15657,0,0,0,0,0,2,0,0,0,0,0,0,0,"Putridus Trickster - On Behind Target - Cast Backstab"),
(11791,0,1,0,0,0,100,2,5000,8000,22000,25000,11,21062,0,0,0,0,0,5,0,0,0,0,0,0,0,"Putridus Trickster - In Combat - Cast Putrid Breath"),
(11791,0,2,0,25,0,100,2,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Putridus Trickster - On Reset - Cast Thrash"),
(11791,0,3,0,0,0,100,2,5000,8000,17000,19000,11,13298,0,0,0,0,0,2,0,0,0,0,0,0,0,"Putridus Trickster - In Combat - Cast Poison");

-- Cavern Shambler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12224;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12224 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12224,0,0,0,0,0,100,2,5000,8000,6000,11000,11,16790,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cavern Shambler - In Combat - Cast Knockdown"),
(12224,0,1,0,2,0,100,2,0,75,21000,26000,11,7948,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cavern Shambler - Between 0-75% Health - Cast Wild Regeneration");

-- Cavern Lurker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12223;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12223 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12223,0,0,0,0,0,100,2,5000,8000,6000,11000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cavern Lurker - In Combat - Cast Knockdown");

-- Noxious Slime
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12221;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12221 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12221,0,0,0,6,0,100,3,0,0,0,0,11,21070,3,0,0,0,0,1,0,0,0,0,0,0,0,"Noxious Slime - On Just Died - Cast Noxious Cloud");

-- Sister of Celebrian
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11794;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11794 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11794,0,0,0,0,0,100,2,0,0,2300,3900,11,15795,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sister of Celebrian - In Combat - Cast Throw"),
(11794,0,1,0,9,0,100,2,0,5,8000,9000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sister of Celebrian - Within 0-5 Range - Cast Strike"),
(11794,0,2,0,4,0,30,2,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sister of Celebrian - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=11794;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11794,0,0,"You do not belong in these gardens.  Your body shall nourish our lovely creations!",12,0,100,0,0,0,8639,0,"Sister of Celebrian"),
(11794,0,1,"Nothing must befoul the gardens! You must be destroyed!",12,0,100,0,0,0,8640,0,"Sister of Celebrian");

-- Celebrian Dryad
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11793;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11793 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11793,0,0,0,0,0,100,2,0,0,2300,3900,11,16000,64,0,0,0,0,2,0,0,0,0,0,0,0,"Celebrian Dryad - In Combat - Cast Throw"),
(11793,0,1,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Celebrian Dryad - Between 0-15% Health - Flee For Assist (No Repeat)"),
(11793,0,2,0,0,0,100,2,8000,16000,12000,16000,11,17201,0,0,0,0,0,1,0,0,0,0,0,0,0,"Celebrian Dryad - In Combat - Cast Dispel Magic"),
(11793,0,3,0,0,0,100,2,5000,7000,12000,13000,11,7992,0,0,0,0,0,5,0,0,0,0,0,0,0,"Celebrian Dryad - In Combat - Slowing Poison"),
(11793,0,4,0,4,0,30,2,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Celebrian Dryad - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=11793;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11793,0,0,"You do not belong in these gardens.  Your body shall nourish our lovely creations!",12,0,100,0,0,0,8639,0,"Celebrian Dryad"),
(11793,0,1,"Nothing must befoul the gardens! You must be destroyed!",12,0,100,0,0,0,8640,0,"Celebrian Dryad");

-- Constrictor Vine
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12220;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12220 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12220,0,0,0,0,0,100,2,3000,5000,9000,17000,11,11922,0,0,0,0,0,5,0,0,0,0,0,0,0,"Constrictor Vine - In Combat - Cast Entangling Roots");

-- Barbed Lasher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12219;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12219 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12219,0,0,0,0,0,100,2,2000,5000,6000,11000,11,21749,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barbed Lasher - In Combat - Cast Thorn Volley");

-- Vile Larva
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12218;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12218 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12218,0,0,0,9,0,100,2,0,10,5000,9000,11,21069,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Larva - Within 0-10 Range - Cast Larva Goo"),
(12218,0,1,0,0,0,100,2,5000,8000,17000,18000,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Larva - In Combat - Cast Poison");

-- Spewed Larva
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=13533;
DELETE FROM `smart_scripts` WHERE `entryorguid`=13533 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(13533,0,0,0,9,0,100,2,6000,9000,30000,45000,11,5413,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spewed Larva - In Combat - Cast Noxious Catalyst");

-- Thessala Hydra
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12207;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12207 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12207,0,0,0,0,0,100,2,10000,13000,12000,18000,11,21790,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thessala Hydra - In Combat - Cast  Aqua Jet"),
(12207,0,1,0,25,0,100,2,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thessala Hydra - On Reset - Cast Thrash"),
(12207,0,2,0,0,0,100,2,6000,10000,17000,18000,11,21787,0,0,0,0,0,5,0,0,0,0,0,0,0,"Thessala Hydra - In Combat - Cast Deadly Poison");

-- Subterranean Diemetradon
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=13323;
DELETE FROM `smart_scripts` WHERE `entryorguid`=13323 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(13323,0,0,0,0,0,100,2,6000,8000,10000,14000,11,8281,0,0,0,0,0,1,0,0,0,0,0,0,0,"Subterranean Diemetradon - In Combat - Cast Sonic Burst");

-- Tinkerer Gizlock
DELETE FROM `smart_scripts` WHERE `entryorguid`=13601 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(13601,0,0,0,0,0,100,2,0,0,2300,3900,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Tinkerer Gizlock - In Combat - Cast Shoot"),
(13601,0,1,0,0,0,100,2,25000,25000,25000,25000,11,29419,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - In Combat - Cast Flash Bomb"),
(13601,0,2,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - On Aggro - Say Line 0"),
(13601,0,3,0,0,0,100,2,6000,9000,16000,19000,11,21833,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tinkerer Gizlock - In Combat - Cast Goblin Dragon Gun"),
(13601,0,4,0,0,0,100,2,4000,4000,12000,12000,11,9143,1,0,0,0,0,5,0,0,0,0,0,0,0,"Tinkerer Gizlock - In Combat - Cast Bomb");

DELETE FROM `creature_text` WHERE `CreatureID`=13601;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(13601,0,0,"Mine! Mine! Mine!  Gizlock is the ruler of this domain!  You shall never reveal my presence!",14,0,100,0,0,0,8852,0,"Tinkerer Gizlock");

-- Primordial Behemoth
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=12206;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12206 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12206,0,0,0,0,0,100,2,0,0,2300,3900,11,21071,64,0,0,0,0,2,0,0,0,0,0,0,0,"Primordial Behemoth - In Combat - Cast Boulder"),
(12206,0,1,0,9,0,100,2,0,8,8000,13000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Primordial Behemoth - Within 0-8 Range - Cast Trample");

-- Rotgrip
DELETE FROM `smart_scripts` WHERE `entryorguid`=13596 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(13596,0,1,0,0,0,100,2,6000,8000,13000,18000,11,15976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rotgrip - In Combat - Cast Puncture");
