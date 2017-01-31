SET @CGUID          := 15;
SET @GOGUID         := 5196; -- Set by TDB, these are free guids.
SET @KC_TARGET      := 31773;
SET @KC_TARGET2     := 32442;
SET @PC_BUNNY       := 32445;
SET @SUMM_PC_BUNNY  := 61026;
SET @GREEN_SPLASH   := 60059;
SET @SPELL          := 59655;
SET @SPELL_DOSE     := 59659;
SET @GHOUL          := 32178;
SET @LIVING_PLAGUE  := 32181;
SET @SUMMON_LPLAGUE := 60058;
SET @SUMMON_GHOUL   := 60056;
SET @RADIATION_AURA := 45797;
SET @KILL_CREDIT    := 31767;

UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1, `mindmg`=286, `maxdmg`=322, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0, `Health_mod`=3 WHERE `entry`=32181; -- Living Plague
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction_A`=21, `faction_H`=21, `speed_walk`=1.428571, `speed_run`=4, `mindmg`=98, `maxdmg`=134, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0, `Health_mod`=4 WHERE `entry`=32178; -- Rampaging Ghoul
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=32442; -- Plague Cauldron Target 02
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=31773; -- Plague Cauldron Target
UPDATE `creature_template` SET `modelid1`=21342, `modelid2`=0, `flags_extra`= 128 WHERE  `entry`=@PC_BUNNY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@KC_TARGET,@KC_TARGET2,@PC_BUNNY,@LIVING_PLAGUE,@GHOUL);
UPDATE `gameobject_template` SET `data1`=30 WHERE `entry`=300239;

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@LIVING_PLAGUE,@GHOUL);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@GHOUL, 0, 0, 0, 0, 0, 100,0, 5000, 17000, 29000, 42000, 11, 54475, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Rampaging Ghoul - In Combat - Cast Rampage'),
(@GHOUL, 0, 1, 0, 0, 0, 100,0, 2000, 14000, 25000, 34000, 11, 6016, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Rampaging Ghoul - In Combat - Cast Pierce Armor'),
(@GHOUL, 0, 2, 3, 54, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rampaging Ghoul - Just Summoned - Set React State Aggresive'),
(@GHOUL, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 46, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rampaging Ghoul - On Link - Move Forward'),
(@GHOUL, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Rampaging Ghoul - On Link - Attack Hostile Random'),
-- Living Plague AI
(@LIVING_PLAGUE, 0, 1, 2, 54, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Plague - Just Summoned - Set React State Aggresive'),
(@LIVING_PLAGUE, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 46, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Plague - On Link - Move Forward'),
(@LIVING_PLAGUE, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Living Plague - On Link - Attack Hostile Random');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@KC_TARGET;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@KC_TARGET*100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@KC_TARGET, 0, 0, 1, 8, 0, 100, 0, @SPELL_DOSE, 0, 0, 0, 80, @KC_TARGET*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'KC Bunny - On spell hit - Trigger script'),
(@KC_TARGET, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'KC Target - On Link - Say Text 0'),
(@KC_TARGET, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, @RADIATION_AURA, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'KC Target - On Link - Aura Radiation'),
(@KC_TARGET, 0, 3, 0, 38, 0, 100, 0, 1, 2, 0, 0, 28, @RADIATION_AURA, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'KC Target - On Data Set - Remove Aura'),
(@KC_TARGET*100, 9, 0, 0, 0, 0, 100, 0, 4000, 4000, 4000, 4000, 11, @SUMM_PC_BUNNY, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'KC Target  - Script - Summon Bunny');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@KC_TARGET2;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@KC_TARGET2*100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@KC_TARGET2, 0, 0, 1, 8, 0, 100, 0, @SPELL_DOSE, 0, 0, 0, 80, @KC_TARGET*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'KC Bunny - On spell hit - Trigger script'),
(@KC_TARGET2, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'KC Target - On Link - Say Text 0'),
(@KC_TARGET2, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, @RADIATION_AURA, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'KC Target - On Link - Aura Radiation'),
(@KC_TARGET2, 0, 3, 0, 38, 0, 100, 0, 1, 1, 0, 0, 28, @RADIATION_AURA, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'KC Target - On Data Set - Remove Aura'),
(@KC_TARGET2*100, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 2000, 2000, 11, @SUMM_PC_BUNNY, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'KC Target - Script - Summon Bunny');


DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@PC_BUNNY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@PC_BUNNY*100,@PC_BUNNY*100+1,@PC_BUNNY*100+2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@PC_BUNNY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 87, @PC_BUNNY*100, @PC_BUNNY*100+1, @PC_BUNNY*100+2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'PC Bunny - Just Summoned - Trigger script'),
(@PC_BUNNY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'PC Bunny - On Link - Say Text 0'),
(@PC_BUNNY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, @GREEN_SPLASH, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'PC Bunny - On Link - Cast cosmetic Green Splash'),
-- First Action Event
(@PC_BUNNY*100, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 2000, 2000, 11, @SUMMON_GHOUL, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Summon Ghoul'),
(@PC_BUNNY*100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 11, @SUMMON_LPLAGUE, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Summon Living Plague'),
(@PC_BUNNY*100, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 11, @SUMMON_LPLAGUE, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Summon Living Plague'),
(@PC_BUNNY*100, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, @KC_TARGET2, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Set Data 1 1'),
(@PC_BUNNY*100, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 2, 0, 0, 0, 0, 19, @KC_TARGET, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Set Data 1 2'),
(@PC_BUNNY*100, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Despawn'),
-- Third Action Event
(@PC_BUNNY*100+2, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 11, @SUMMON_LPLAGUE, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Summon Living Plague'),
(@PC_BUNNY*100+2, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 11, @SUMMON_LPLAGUE, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Summon Living Plague'),
(@PC_BUNNY*100+2, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 11, @SUMMON_LPLAGUE, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Summon Living Plague'),
(@PC_BUNNY*100+2, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 11, @SUMMON_LPLAGUE, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Summon Living Plague'),
(@PC_BUNNY*100+2, 9, 5, 0, 0, 0, 100, 1, 10500, 10500, 10500, 10500, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'PC Bunny - On Script - Say 1'),
(@PC_BUNNY*100+2, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 2000, 2000, 11, @SUMMON_GHOUL, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Summon Ghoul'),
(@PC_BUNNY*100+2, 9, 7, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 11, @SUMMON_LPLAGUE, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Summon Living Plague'),
(@PC_BUNNY*100+2, 9, 8, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 11, @SUMMON_LPLAGUE, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Summon Living Plague'),
(@PC_BUNNY*100+2, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, @KC_TARGET2, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Set Data 1 1'),
(@PC_BUNNY*100+2, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 2, 0, 0, 0, 0, 19, @KC_TARGET, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Set Data 1 2'),
(@PC_BUNNY*100+2, 9, 11, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Despawn'),
-- Second Action Event
(@PC_BUNNY*100+1, 9, 0, 0, 0, 0, 100, 0, 7000, 7000, 7000, 7000, 33, @KILL_CREDIT, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'KC Target - On spellhit - Give quest credit'),
(@PC_BUNNY*100+1, 9, 1, 0, 0, 0, 100, 0, 1500, 1500, 1500, 1500, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Say 1'),
(@PC_BUNNY*100+1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, @KC_TARGET2, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Set Data 1 1'),
(@PC_BUNNY*100+1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 2, 0, 0, 0, 0, 19, @KC_TARGET, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Set Data 1 2'),
(@PC_BUNNY*100+1, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'PC Bunny  - On Script - Despawn');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=59655;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 59655, 0, 1, 31, 0, 3, 31773, 0, 0, 0, 0, '', 'Neutralize Plague hits Plague Cauldron Target Bunny'),
(13, 1, 59655, 0, 0, 31, 0, 3, 32442, 0, 0, 0, 0, '', 'Neutralize Plague hits Plague Cauldron Target Bunny');

DELETE FROM `creature` WHERE `id` IN (31773,32442);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 31773, 571, 1, 1, 6776.598, 1628.575, 392.1221, 4.729842, 120, 0, 0),   -- Plague Cauldron Target (Area: Mord'rethar: The Death Gate)
(@CGUID+1, 32442, 571, 1, 1, 6777.509, 1539.352, 392.1735, 1.623156, 120, 0, 0); -- Plague Cauldron Target 02 (Area: Mord'rethar: The Death Gate)

DELETE FROM `gameobject` WHERE `id` IN (300239);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES 
(@GOGUID, 300239, 571, 1, 1, 6776.6, 1628.57, 390.922, 5.39315, 0, 0, 0.430474, -0.902603, 300, 0, 1),
(@GOGUID+1, 300239, 571, 1, 1, 6777.51, 1539.35, 390.874, 1.62316, 0, 0, 0.725376, 0.688353, 300, 0, 1);


DELETE FROM `creature_template_addon` WHERE `entry` IN (31150,32442,@LIVING_PLAGUE,@GHOUL);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(31150, 0, 0x0, 0x1, '50106'), -- 
(32442, 0, 0x0, 0x1, ''),
(32181, 0, 0x0, 0x1, '61587'), -- Living Plague - Living Plague
(32178, 0, 0x0, 0x1, '58812'); -- Rampaging Ghoul - Ghoul Aura

DELETE FROM `creature_text` WHERE `entry` IN (@KC_TARGET,@KC_TARGET2,@PC_BUNNY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@PC_BUNNY, 0, 0, 'Something emerges from the cauldron!', 41, 0, 100, 0, 0, 0, 'Player Bunny'),
(@PC_BUNNY, 1, 0, 'The cauldron continues to boil...', 41, 0, 100, 0, 0, 0, 'Player Bunny'),
(@PC_BUNNY, 2, 0, 'Plague batch neutralized!', 41, 0, 100, 0, 0, 0, 'Player Bunny'),
(@KC_TARGET, 0, 0, 'The plague cauldron begins to boil vigorously!', 41, 0, 100, 0, 0, 0, 'Plague Cauldron Target'),
(@KC_TARGET2, 0, 0, 'The plague cauldron begins to boil vigorously!', 41, 0, 100, 0, 0, 0, 'Plague Cauldron Target 02');
