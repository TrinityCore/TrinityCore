SET @CGUID :=    74506;

UPDATE `creature_template` SET `faction`=1813, `unit_flags`=32768,`flags_extra`=2 WHERE  `entry` IN(21416,21709,21710,21711);
UPDATE `creature_template` SET `gossip_menu_id`=8350, `npcflag`=0, `speed_walk`=1, `speed_run`=1.142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=0, `AIName`='SmartAI' WHERE  `entry`=21685;
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=21052;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(21703,21704,21705,21420);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(21703,21704,21705,21420) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(-75734,-75735,-75736,-75737,-75738,-75739,-75104,-75105,-75106,-@CGUID, -@CGUID-1,-@CGUID-2) AND `source_type`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid` =2847900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-75104, 0, 0, 0, 1, 0, 100, 0, 0, 0, 15000, 15000, 11, 36817, 0, 0, 0, 0, 0, 1, 21416, 0, 0, 0, 0, 0, 0, 'Corrupt Water Totem - OOC - Cast Channel Water shield'), 
(-75104, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 36826, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Water Totem - On Agro - Cast Summon Corrupt Water Elemental'), 
(-75105, 0, 0, 0, 1, 0, 100, 0, 0, 0, 15000, 15000, 11, 38105, 0, 0, 0, 0, 0, 1, 21416, 0, 0, 0, 0, 0, 0, 'Corrupt Water Totem - OOC - Cast Channel Water shield'), 
(-75105, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 36826, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Water Totem - On Agro - Cast Summon Corrupt Water Elemental'), 
(-75106, 0, 0, 0, 1, 0, 100, 0, 0, 0, 15000, 15000, 11, 38106, 0, 0, 0, 0, 0, 1, 21416, 0, 0, 0, 0, 0, 0, 'Corrupt Water Totem - OOC - Cast Channel Water shield'), 
(-75106, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 36826, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Water Totem - On Agro - Cast Summon Corrupt Water Elemental'), 
(-75734, 0, 0, 0, 1, 0, 100, 0, 0, 0, 15000, 15000, 11, 37204, 0, 0, 0, 0, 0, 1, 21709, 0, 0, 0, 0, 0, 0, 'Corrupt Earth Totem - OOC - Cast Channel Earth shield'), 
(-75734, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 37203, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Earth Totem - On Agro - Cast Summon Corrupt Earth Elemental'), 
(-75735, 0, 0, 0, 1, 0, 100, 0, 0, 0, 15000, 15000, 11, 38101, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Earth Totem - OOC - Cast Channel Earth shield'), 
(-75735, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 37203, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Earth Totem - On Agro - Cast Summon Corrupt Earth Elemental'), 
(-75736, 0, 0, 0, 1, 0, 100, 0, 0, 0, 15000, 15000, 11, 38102, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Earth Totem - OOC - Cast Channel Earth shield'), 
(-75736, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 37203, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Earth Totem - On Agro - Cast Summon Corrupt Earth Elemental'), 
(-75737, 0, 0, 0, 1, 0, 100, 0, 0, 0, 15000, 15000, 11, 37205, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Air Totem - OOC - Cast Channel Air shield'), 
(-75737, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 37202, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Air Totem - On Agro - Cast Summon Corrupt Air Elemental'), 
(-75738, 0, 0, 0, 1, 0, 100, 0, 0, 0, 15000, 15000, 11, 38099, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Air Totem - OOC - Cast Channel Air shield'), 
(-75738, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 37202, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Air Totem - On Agro - Cast Summon Corrupt Air Elemental'), 
(-75739, 0, 0, 0, 1, 0, 100, 0, 0, 0, 15000, 15000, 11, 38100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Air Totem - OOC - Cast Channel Air shield'), 
(-75739, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 37202, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Air Totem - On Agro - Cast Summon Corrupt Air Elemental'), 
(-@CGUID, 0, 0, 0, 1, 0, 100, 0, 0, 0, 15000, 15000, 11, 37206, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Fire Totem - OOC - Cast Channel Fire shield'), 
(-@CGUID, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 37201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Fire Totem - On Agro - Cast Summon Corrupt Fire Elemental'), 
(-@CGUID-1, 0, 0, 0, 1, 0, 100, 0, 0, 0, 15000, 15000, 11, 38103, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Fire Totem - OOC - Cast Channel Fire shield'), 
(-@CGUID-1, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 37201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Fire Totem - On Agro - Cast Summon Corrupt Fire Elemental'), 
(-@CGUID-2, 0, 0, 0, 1, 0, 100, 0, 0, 0, 15000, 15000, 11, 38104, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Fire Totem - OOC - Cast Channel Fire shield'), 
(-@CGUID-2, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 37201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corrupt Fire Totem - On Agro - Cast Summon Corrupt Fire Elemental');

UPDATE `creature` SET `position_x`=-3396.211, `position_y`=1568.679, `position_z`=47.82401, `orientation`=6.110603 WHERE  `guid`=86485;

DELETE FROM `creature` WHERE `id`IN(21703,21706,21707,21708,21428);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 21703, 530, 1, 1,  -3392.402, 1566.671, 47.97179, 0.2094395, 120, 0, 0), -- 21703 (Area: 3520)
(@CGUID+1, 21703, 530, 1, 1,  -3404.077, 1566.567, 47.88474, 4.782202, 120, 0, 0), -- 21703 (Area: 3520)
(@CGUID+2, 21703, 530, 1, 1,  -3397.854, 1576.284, 47.14587, 5.532694, 120, 0, 0); -- 21703 (Area: 3520)

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `ConditionTypeOrReference`=31 AND `ConditionValue1`=3 AND `ConditionValue2` IN(21416,21709,21710,21711);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=38722;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 5, 36817, 0, 0, 31, 0, 3, 21416, 0, 0, 0, 0, '', ''),
(13, 5, 38105, 0, 0, 31, 0, 3, 21416, 0, 0, 0, 0, '', ''),
(13, 5, 38106, 0, 0, 31, 0, 3, 21416, 0, 0, 0, 0, '', ''),
(13, 5, 37204, 0, 0, 31, 0, 3, 21709, 0, 0, 0, 0, '', ''),
(13, 5, 38101, 0, 0, 31, 0, 3, 21709, 0, 0, 0, 0, '', ''),
(13, 5, 38102, 0, 0, 31, 0, 3, 21709, 0, 0, 0, 0, '', ''),
(13, 5, 37205, 0, 0, 31, 0, 3, 21711, 0, 0, 0, 0, '', ''),
(13, 5, 38099, 0, 0, 31, 0, 3, 21711, 0, 0, 0, 0, '', ''),
(13, 5, 38100, 0, 0, 31, 0, 3, 21711, 0, 0, 0, 0, '', ''),
(13, 5, 37206, 0, 0, 31, 0, 3, 21710, 0, 0, 0, 0, '', ''),
(13, 5, 38103, 0, 0, 31, 0, 3, 21710, 0, 0, 0, 0, '', ''),
(13, 5, 38104, 0, 0, 31, 0, 3, 21710, 0, 0, 0, 0, '', ''),
(13, 1, 38722, 0, 0, 31, 0, 3, 21506, 0, 0, 0, 0, '', '');

DELETE FROM `creature_template_addon` WHERE `entry`=21506;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(21506, 0, 0x0, 0x1, '37833'); -- 21506 - 37833

UPDATE `creature_template` SET `faction`=954, `unit_flags`=2147779136 WHERE  `entry`=21506;

DELETE FROM `smart_scripts` WHERE `entryorguid`=21506 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21503 AND `source_type`=0 and `id`=6;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(21506, 0, 0, 1, 8, 0, 100, 0, 37834, 0, 0, 0, 33, 21892, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Azaloth - On Spellhit \'Unbanish Azaloth\' - Quest Credit \'A Necessary Distraction\''),
(21506, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 37833, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Azaloth - On Spellhit \'Unbanish Azaloth\' - Remove Banish'),
(21503, 0, 6, 0, 1, 0, 100, 0, 0, 0, 15000, 15000, 11, 38722, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sunfury Warlock - OOC - Cast Spellbind Azaloth');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=21503;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 7, 21503, 0, 0, 29, 1, 21506, 20, 0, 0, 0, 0, '', 'Only run SAI if Azaloth within 20 yards');

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(21024,21129,21130,21131,21132);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(21024,21129,21130,21131,21132) AND `source_type`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2120400) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21024, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - On Spawn - Set Phase 1'), 
(21024, 0, 1, 0, 20, 1, 100, 0, 10481, 0, 0, 0, 80, 2120400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - On Quest Reward - Enraged Spirits of Air - Run Script 1'), 
(21129, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 36206, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scorned Spirit of Earth - On Just Summoned - Cast Call to the Spirits'), 
(21130, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 36206, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scorned Spirit of Fire - On Just Summoned - Cast Call to the Spirits'), 
(21131, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 36206, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scorned Spirit of Water - On Just Summoned - Cast Call to the Spirits'), 
(21132, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 36206, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scorned Spirit of Air - On Quest Reward - On Just Summoned - Cast Call to the Spirits'), 

(2120400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Set Phase 2'), 
(2120400, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say Line 1'), 
(2120400, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 107, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Summon Group'), 
(2120400, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 21071, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Set Orientation'), 
(2120400, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say Line 1'), 
(2120400, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 21129, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say'), 
(2120400, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 21130, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say'), 
(2120400, 9, 7, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say Line 1'), 
(2120400, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 21131, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say'), 
(2120400, 9, 9, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 21132, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say'), 
(2120400, 9, 10, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say Line 1'), 
(2120400, 9, 11, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say Line 1'), 
(2120400, 9, 12, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 21129, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say'), 
(2120400, 9, 13, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say Line 1'), 
(2120400, 9, 14, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 21130, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say'), 
(2120400, 9, 15, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say Line 1'), 
(2120400, 9, 16, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 21131, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say'), 
(2120400, 9, 17, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say Line 1'), 
(2120400, 9, 18, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 21132, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say'), 
(2120400, 9, 19, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 21129, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say'), 
(2120400, 9, 20, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 21130, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say'), 
(2120400, 9, 21, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say Line 1'), 
(2120400, 9, 22, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 21129, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say'), 
(2120400, 9, 23, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say Line 1'), 
(2120400, 9, 24, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Say Line 1'), 
(2120400, 9, 25, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.93928, 'Earthmender Torlok <The Earthen Ring> - Script - Say Line 1'), 
(2120400, 9, 26, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Earthmender Torlok <The Earthen Ring> - Script - Set Phase 1');

DELETE FROM `creature_text` WHERE `entry` IN(21024,21129,21130,21131,21132);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(21024, 0, 0, 'Stand back, $n. The spirits may lash out.', 12, 0, 100, 1, 0, 0, 'Earthmender Torlok',18749),
(21129, 0, 0, 'Why have you captured us?', 12, 0, 100, 0, 0, 0, 'Scorned Spirit of Earth',18750),
(21130, 0, 0, 'What is it that you hope to gain from this?', 12, 0, 100, 0, 0, 0, 'Scorned Spirit of Fire',18751),
(21024, 1, 0, 'We wish to help you, spirit. We seek your wisdom.', 12, 0, 100, 1, 0, 0, 'Earthmender Torlok',18753),
(21131, 0, 0, 'Wisdom? It was your people that caused the insufferable wrath of Cyrukh.', 12, 0, 100, 0, 0, 0, 'Scorned Spirit of Water',18754),
(21132, 0, 0, 'Why should we help you? The world is ruined. Destroyed.', 12, 0, 100, 0, 0, 0, 'Scorned Spirit of Air',18755),
(21024, 2, 0, 'You are right, spirit. It was my people that did this to you. Allow us to make it right.', 12, 0, 100, 1, 0, 0, 'Earthmender Torlok',18757),
(21024, 3, 0, 'Please tell us this: Who or what is Cyrukh?', 12, 0, 100, 1, 0, 0, 'Earthmender Torlok',18758),
(21129, 1, 0, 'Fool! Cyrukh the fire lord! When the tie was severed, Cyrukh awoke. It is the tears of Cyrukh that fill this land with molten rock.', 12, 0, 100, 0, 0, 0, 'Scorned Spirit of Earth',18759),
(21024, 4, 0, 'The... The fire lord? An elemental lord was unearthed? Of course... Gul''dan you were a damned fool!', 12, 0, 100, 6, 0, 0, 'Earthmender Torlok',18760),
(21130, 1, 0, 'He is insane now. Driven mad during the shattering. There is no rest for the elements.', 12, 0, 100, 0, 0, 0, 'Scorned Spirit of Fire',18761),
(21024, 5, 0, 'There must be a way.', 12, 0, 100, 0, 0, 0, 'Earthmender Torlok',18762),
(21131, 1, 0, 'Yes, a way. Destroy Cyrukh. Destroy an elemental lord.', 12, 0, 100, 0, 0, 0, 'Scorned Spirit of Water',18763),
(21024, 6, 0, 'Do not doubt my comrades and I, spirit. Tell us how to conjure the fire lord. My allies will destroy him.', 12, 0, 100, 1, 0, 0, 'Earthmender Torlok',18764),
(21132, 1, 0, 'You must utter the words...', 12, 0, 100, 0, 0, 0, 'Scorned Spirit of Air',18765),
(21129, 2, 0, 'Yes... Yes... the words. The words of damnation. The words spoken by the dark one. Your master.', 12, 0, 100, 0, 0, 0, 'Scorned Spirit of Earth',18766),
(21130, 2, 0, 'Yes... Gul''dan...', 12, 0, 100, 0, 0, 0, 'Scorned Spirit of Fire',18767),
(21024, 7, 0, 'We will find these words. We will summon your master and we will destroy him.', 12, 0, 100, 1, 0, 0, 'Earthmender Torlok',18768),
(21129, 3, 0, 'Talk. More talk... Now release us, mortal.', 12, 0, 100, 0, 0, 0, 'Scorned Spirit of Earth',18769),
(21024, 8, 0, '%s nods.', 16, 0, 100, 273, 0, 0, 'Earthmender Torlok',18756),
(21024, 9, 0, 'Now to recover the lost words!', 12, 0, 100, 5, 0, 0, 'Earthmender Torlok',18778),
(21024, 10, 0, '%s bows.', 16, 0, 100, 2, 0, 0, 'Earthmender Torlok',18752);

DELETE FROM `creature_summon_groups` WHERE `summonerId`IN(21024);
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES 
(21024, 0, 0, 21129, -3604.787, 1913.459, 47.80234, 4.956735, 1, 110000),
(21024, 0, 0, 21130, -3596.973, 1913.545, 47.78812, 4.572762, 1, 110000),
(21024, 0, 0, 21131, -3612.323, 1910.802, 47.62409, 5.550147, 1, 110000),
(21024, 0, 0, 21132, -3590.55, 1911.157, 47.38158, 4.049164, 1, 110000),
(21024, 0, 0, 21071, -3590.55, 1911.157, 47.38158, 4.049164, 1, 110000);

DELETE FROM `creature_template_addon` WHERE `entry`	 BETWEEN 21129 AND 21132;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(21129, 0, 0x0, 0x1, '36113'), -- 21129 - 36113
(21130, 0, 0x0, 0x1, '36114'), -- 21130 - 36114
(21131, 0, 0x0, 0x1, '35923'), -- 21131 - 35923
(21132, 0, 0x0, 0x1, '36178'); -- 21132 - 36178

DELETE FROM `creature_template_addon` WHERE `entry`=21181;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(21181, 0, 0x0, 0x1, '36329'); -- 21181 - 36329

UPDATE `creature_template` SET `gossip_menu_id`=8259, `AIName`= 'SmartAI',`ScriptName`= '' WHERE  `entry`=21183;

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN(8259,8281,8280,8279,8278,8277,8276,8350);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(8259, 0, 1, 'What do you have for sale, Oronok?', 18834, 3, 128, 0, 0, 0, 0, '', 0),
(8259, 1, 0, 'I am ready to hear your story, Oronok.', 18935, 1, 1, 8281, 0, 0, 0, '', 0),
(8281, 0, 0, 'How do I find the cipher?', 18937, 1, 1, 8280, 0, 0, 0, '', 0),
(8280, 0, 0, 'How do you know all of this?', 18939, 1, 1, 8279, 0, 0, 0, '', 0),
(8279, 0, 0, 'Yet what? What is it, Oronok?', 18941, 1, 1, 8278, 0, 0, 0, '', 0),
(8278, 0, 0, 'Continue, please.', 18943, 1, 1, 8277, 0, 0, 0, '', 0),
(8277, 0, 0, 'So what of the cipher now? And your boys?', 18945, 1, 1, 8276, 0, 0, 0, '', 0),
(8276, 0, 0, 'I will find your boys and the cipher, Oronok.', 18947, 1, 1, 0, 0, 0, 0, '', 0),
(8350, 0, 0, 'I am ready, Oronok. Let us destroy Cyrukh and free the elements!', 19307, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `gossip_menu` WHERE `entry` IN(8259,8281,8280,8279,8278,8277,8276,8350);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(8259, 10280), -- 21183
(8259, 10312), -- 21183
(8281, 10313), -- 21183
(8280, 10314), -- 21183
(8279, 10315), -- 21183
(8278, 10316), -- 21183
(8277, 10317), -- 21183
(8276, 10318), -- 21183
(8350, 10421); -- 21685

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(14,15) AND `SourceGroup`IN(8259,8350);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8259, 1, 0, 0, 9, 0, 10519, 0, 0, 0, 0, 0, '', 'Oronok Torn-heart <Hermit & Trader> - Show gossip option only if player has The Cipher of Damnation - Truth and History taken'),
(14, 8259, 10312, 0, 0, 9, 0, 10519, 0, 0, 0, 0, 0, '', 'Oronok Torn-heart <Hermit & Trader> - Show npc text only if player has The Cipher of Damnation - Truth and History taken'),
(14, 8259, 10280, 0, 0, 9, 0, 10519, 0, 0, 1, 0, 0, '', 'Oronok Torn-heart <Hermit & Trader> - Show npc text only if player does not have The Cipher of Damnation - Truth and History taken'),
(15, 8350, 0, 0, 0, 9, 0, 10588, 0, 0, 0, 0, 0, '', 'Oronok Torn-heart - Show gossip option only if player has The Cipher of Damnation Taken');

DELETE FROM `smart_scripts` WHERE `entryorguid` =21183;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21183, 0, 0, 1, 62, 0, 100, 0, 8276, 0, 0, 0, 15, 10519, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Oronok Torn-heart <Hermit & Trader> - On Gossip Option Select - Complete Quest (The Cipher of Damnation - Truth and History)'),
(21183, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Oronok Torn-heart <Hermit & Trader> - On Gossip Option Select - Close Gossip');
