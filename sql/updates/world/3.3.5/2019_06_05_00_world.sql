-- 
UPDATE `creature` SET `position_x`= 215.258, `position_y`= 10.3208, `position_z`=-7.46839, `orientation`= 2.30417 WHERE `guid`= 79427;
UPDATE `creature` SET `position_x`= 211.016, `position_y`= 14.9728, `position_z`=-7.46839, `orientation`= 2.61519 WHERE `guid`= 79432;
UPDATE `creature` SET `position_x`= 217.319, `position_y`= 8.03409, `position_z`=-7.46839, `orientation`= 2.30417 WHERE `guid`= 79434;
UPDATE `creature` SET `position_x`= 207.511, `position_y`= 17.0099, `position_z`=-7.46839, `orientation`= 2.65446 WHERE `guid`= 79444;
UPDATE `creature` SET `position_x`= 213.150, `position_y`= 12.6610, `position_z`=-7.46839, `orientation`= 2.30417 WHERE `guid`= 79445;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry` IN (21186,20857,20859, 20865, 20864);
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=0.857143, `DamageModifier`=6 WHERE `entry`=20857;
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=0.857143, `DamageModifier`=6 WHERE `entry`=21585;
UPDATE `creature_template_addon` SET `auras`="36637 36600 36287" WHERE  `entry`IN (20857);
DELETE FROM `creature_template_addon` WHERE `entry`=21585;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(21585,0,0,4098,333, "38805 38803 40448");
UPDATE `spell_dbc` SET `ProcFlags`=20, `ProcChance`=75, `Effect1`=6, `EffectImplicitTargetA1`=1, `EffectApplyAuraName1`=42, `EffectTriggerSpell1`=40449, `DmgClass`=1, `PreventionType`=1, `DmgMultiplier1`=1 WHERE `id`=40448;
UPDATE `creature_template_addon` SET `auras`="36610" WHERE  `entry`IN (20859);
DELETE FROM `creature_template_addon` WHERE `entry`=21587;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(21587,0,0,4098,376, "36610");
DELETE FROM `creature_addon` WHERE `guid`IN (79393,79400);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(-79409,20865,20864,20857,20859) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2118600,2118601) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-79409, 0, 0, 0, 1,  0, 100, 0, 2000, 2000, 4000, 4000, 87, 2118600, 2118601, 0, 0, 0, 0, 1, 0, 0, 0, 0, 01, 0, 0, 'Arcane Warder Target - OOC - Radom action list'),
(2118600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 20865, 4, 1800000, 0, 0, 0, 8, 0, 0, 0, 191.4933, -2.3331, -10.103, 3.184790, 'Arcane Warder Target - Action list - Summon Protean Horror'),
(2118600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 20865, 4, 1800000, 0, 0, 0, 8, 0, 0, 0, 193.8958, -2.2860, -10.103, 3.161228, 'Arcane Warder Target - Action list - Summon Protean Horror'),
(2118600, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 20865, 4, 1800000, 0, 0, 0, 8, 0, 0, 0, 196.0734, -2.2432, -10.103, 3.161228, 'Arcane Warder Target - Action list - Summon Protean Horror'),
(2118600, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 20865, 4, 1800000, 0, 0, 0, 8, 0, 0, 0, 198.6289, -2.1930, -10.103, 3.161228, 'Arcane Warder Target - Action list - Summon Protean Horror'),
(2118601, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 20864, 4, 1800000, 0, 0, 0, 8, 0, 0, 0, 191.4933, -2.3331, -10.103, 1.771863, 'Arcane Warder Target - Action list - Summon Protean Nightmare'),
(2118601, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 20865, 4, 1800000, 0, 0, 0, 8, 0, 0, 0, 193.8958, -2.2860, -10.103, 3.161228, 'Arcane Warder Target - Action list - Summon Protean Horror'),
(2118601, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 20865, 4, 1800000, 0, 0, 0, 8, 0, 0, 0, 196.0734, -2.2432, -10.103, 3.161228, 'Arcane Warder Target - Action list - Summon Protean Horror'),
(20857, 0, 0, 0, 0, 0, 100, 2, 0, 3000, 6000, 7000, 75, 36621, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Arcatraz Defender - IC - Casts Infected Blood'),
(20857, 0, 1, 0, 0, 0, 100, 4, 0, 3000, 6000, 7000, 75, 38812, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Arcatraz defender - IC - Casts Infected Blood heroic'),
(20859, 0, 0, 0, 0, 0, 100, 2, 5000, 10000, 7000, 10000, 11, 36609, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Arcatraz Warder - In Combat - Cast Spell Arcane Shoot'),
(20859, 0, 1, 0, 0, 0, 100, 4, 5000, 10000, 7000, 10000, 11, 38807, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Arcatraz Warder - In Combat - Cast Spell Arcane Shoot'),
(20859, 0, 2, 0, 0, 0, 100, 2, 3000, 3000, 6000, 8000, 11, 36608, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Arcatraz Warder - In Combat - Charged Arcane Shot'),
(20859, 0, 3, 0, 0, 0, 100, 4, 3000, 3000, 6000, 8000, 11, 38808, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Arcatraz Warder - In Combat - Charged Arcane Shot'),
(20859, 0, 4, 0, 0, 0, 100, 2, 2300, 3900, 2300, 3900, 11, 22907, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Arcatraz Warder - In Combat - Shoot'),
(20859, 0, 5, 0, 0, 0, 100, 4, 2300, 3900, 2300, 3900, 11, 38940, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Arcatraz Warder - In Combat - Shoot'),
(20859, 0, 6, 0, 1, 0, 100, 0, 2000, 3000, 2000, 3000, 11, 36327, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arcatraz Warder - Ooc  - Charged Arcane Shot'),
(20865, 0, 0, 0, 0, 0, 100, 0, 2000, 6000, 4000, 7000, 11, 36612, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Protean Horror - In Combat - Cast Spell Toothy Bite'),
(20865, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 1, 20865, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Protean Horror - On Just Summoned - Start WP.'),
(20865, 0, 2, 0, 40, 0, 100, 0, 4, 20865, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Protean Horror - On Reached WP6 - Set Homeposition'),
(20864, 0, 0, 0, 0, 0, 100, 2, 2000, 2000, 20000, 20000, 11, 36617, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Protean Nightmare - In Combat - Cast Spell Gaping Maw'),
(20864, 0, 1, 0, 0, 0, 100, 4, 2000, 2000, 20000, 20000, 11, 38810, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Protean Nightmare - In Combat - Cast Spell Gaping Maw'),
(20864, 0, 2, 0, 0, 0, 100, 2, 8000, 8000, 20000, 20000, 11, 36619, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Protean Nightmare - In Combat - Cast Spell Infectious Poison'),
(20864, 0, 3, 0, 0, 0, 100, 4, 8000, 8000, 20000, 20000, 11, 38811, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Protean Nightmare - In Combat - Cast Spell Infectious Poison'),
(20864, 0, 4, 0, 0, 0, 100, 0, 1000, 2000, 12000, 15000, 11, 36622, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Protean Nightmare - In Combat - Cast Spell Incubation'),
(20864, 0, 5, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 1, 20865, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Protean Nightmare - On Just Summoned - Start WP'),
(20864, 0, 6, 0, 40, 0, 100, 0, 4, 20865, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Protean Nightmare - On Reached WP6 - Set Homeposition');
DELETE FROM `waypoints` WHERE `entry`=20865;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(20865, 1, 191.493301, -2.333183, -10.103561, 'Protean Horror'),
(20865, 2, 169.366394, 0.093095, -10.101444, 'Protean Horror'),
(20865, 3, 142.782761, 0.447828, -10.101192, 'Protean Horror'),
(20865, 4, 116.365929, 0.441179, -10.131830, 'Protean Horror');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN(-79409,20859);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, -79409, 0, 0, 29, 1, 20857, 20, 0, 0, 0, 0, '', 'Arcane Warder Target - SAI'),
(22, 1, -79409, 0, 0, 29, 1, 20864, 55, 0, 1, 0, 0, '', 'Arcane Warder Target - SAI'),
(22, 1, -79409, 0, 0, 29, 1, 20865, 55, 0, 1, 0, 0, '', 'Arcane Warder Target - SAI'),
(22, 7, 20859, 0, 0, 29, 1, 20864, 48, 0, 0, 0, 0, '', 'Arcane Warder Target - SAI'),
(22, 7, 20859, 0, 1, 29, 1, 20865, 48, 0, 0, 0, 0, '', 'Arcane Warder Target - SAI');
