DELETE FROM `smart_scripts` WHERE `entryorguid` = 25462 AND `source_type` = 0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
('25462','0','0','0','19','0','100','512','12593','0','0','0','','80','2546200','0','0','0','0','0','1','0','0','0','0','0','0','0','The Lich King - On Quest \'In service of The Lich King Taken\' - Run Script');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 2546200 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
('2546200','9','0','0','0','0','100','0','0','0','0','0','','4','14970','1','0','0','0','0','7','0','0','0','0','0','0','0','The Lich King - On Script - Play Sound 14970'),
('2546200','9','1','0','0','0','100','0','21000','21000','0','0','','4','14971','1','0','0','0','0','7','0','0','0','0','0','0','0','The Lich King - On Script - Play Sound 14971'),
('2546200','9','2','0','0','0','100','0','26000','26000','0','0','','4','14972','1','0','0','0','0','7','0','0','0','0','0','0','0','The Lich King - On Script - Play Sound 14972');

UPDATE `creature_addon` SET `path_id`='0', `auras`='29266' WHERE  `guid`=303353;
UPDATE `creature` SET `unit_flags`='33587330', `dynamicflags`='32' WHERE  `guid`=303353;

UPDATE `creature_template` SET `unit_flags`='32768' WHERE  `entry`=28406;

UPDATE `creature_equip_template` SET `ItemID1`='1899', `ItemID2`='12932' WHERE  `CreatureID`=28609 AND `ID`=1;

DELETE FROM `smart_scripts` WHERE `entryorguid`=28709;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(28709, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, '', 11, 52206, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Acherus Geist - On Aggro - Cast Leaping Face Maul'),
(28709, 0, 1, 0, 0, 0, 100, 0, 3500, 4000, 8400, 12800, '', 11, 52207, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Acherus Geist - Cast Devour Humanoid');

UPDATE `creature_template` SET `InhabitType`='4' WHERE  `entry`=28804;

UPDATE `creature_template` SET `speed_walk`='3', `speed_run`='3', `InhabitType`='4' WHERE  `entry`=28864;

UPDATE `creature_template` SET `InhabitType`='4' WHERE  `entry`=28906;

UPDATE `creature_template` SET `InhabitType`='4' WHERE  `entry`=28907;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=29030;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29030;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(29030, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 12000, 12800, '', 11, 52373, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Death Knight - Cast Plague Strike');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=29031;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29031;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(29031, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 12000, 12800, '', 11, 52373, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Death Knight - Cast Plague Strike');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=29101;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29101;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(29101, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, '', 11, 49576, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Death Knight Champion - On Aggro - Cast Death Grip'),
(29101, 0, 1, 0, 0, 0, 100, 0, 8000, 8000, 16000, 18800, '', 11, 52372, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Death Knight Champion - Cast Icy Touch'),
(29101, 0, 2, 0, 0, 0, 100, 0, 3500, 4000, 8400, 14800, '', 11, 52374, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Death Knight Champion - Cast Blood Strike'),
(29101, 0, 3, 0, 0, 0, 100, 0, 10000, 10000, 10000, 10500, '', 11, 52375, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Death Knight Champion - Cast Death Coil');

UPDATE `creature_template` SET `DamageModifier`='1', `flags_extra`='2' WHERE  `entry`=29102;
UPDATE `creature_equip_template` SET `ItemID1`='1899', `ItemID2`='12932' WHERE  `CreatureID`=29102 AND `ID`=1;

UPDATE `creature_template` SET `DamageModifier`='1', `flags_extra`='2' WHERE  `entry`=29103;
UPDATE `creature_equip_template` SET `ItemID1`='1899', `ItemID2`='12932' WHERE  `CreatureID`=29103 AND `ID`=1;

UPDATE `creature_template` SET `DamageModifier`='1', `flags_extra`='2' WHERE  `entry`=29104;

DELETE FROM `smart_scripts` WHERE `entryorguid`=29109;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(29109, 0, 0, 0, 0, 0, 100, 0, 5000, 5500, 12000, 13500, '', 11, 15284, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Baron Rivendare - Cast Cleave'),
(29109, 0, 1, 0, 0, 0, 100, 0, 8000, 8000, 15600, 18200, '', 11, 15708, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Baron Rivendare - Cast Mortal Strike'),
(29109, 0, 2, 0, 0, 0, 100, 0, 6000, 6000, 12000, 12800, '', 11, 17393, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Baron Rivendare - Cast Shadow Bolt');

UPDATE `creature_template` SET `InhabitType`='4' WHERE  `entry`=29110;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=29185;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29185;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(29185, 0, 0, 0, 6, 0, 100, 1, 0, 0, 0, 0, '', 11, 53632, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Volatile Ghoul - On Death - Cast Ghoulplosion');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=29202;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29202;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(29202, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, '', 11, 57602, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Knight of the Ebon Blade - On Aggro - Cast Death Grip'),
(29202, 0, 1, 0, 0, 0, 100, 0, 8000, 8000, 16000, 18800, '', 11, 52372, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Knight of the Ebon Blade - Cast Icy Touch'),
(29202, 0, 2, 0, 0, 0, 100, 0, 3500, 4000, 8400, 14800, '', 11, 52374, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Knight of the Ebon Blade - Cast Blood Strike'),
(29202, 0, 3, 0, 0, 0, 100, 0, 10000, 10000, 10000, 10500, '', 11, 52375, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Knight of the Ebon Blade - Cast Death Coil');

UPDATE `creature_template` SET `InhabitType`='4' WHERE  `entry`=29239;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=31094;
DELETE FROM `smart_scripts` WHERE `entryorguid`=31094;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(31094, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, '', 11, 57602, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Knight of the Ebon Blade - On Aggro - Cast Death Grip'),
(31094, 0, 1, 0, 0, 0, 100, 0, 8000, 8000, 16000, 18800, '', 11, 52372, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Knight of the Ebon Blade - Cast Icy Touch'),
(31094, 0, 2, 0, 0, 0, 100, 0, 3500, 4000, 8400, 14800, '', 11, 52374, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Knight of the Ebon Blade - Cast Blood Strike'),
(31094, 0, 3, 0, 0, 0, 100, 0, 10000, 10000, 10000, 10500, '', 11, 52375, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Knight of the Ebon Blade - Cast Death Coil');

UPDATE `creature_template` SET `InhabitType`='4' WHERE  `entry`=31095;

UPDATE `smart_scripts` SET `event_chance`='10' WHERE  `entryorguid`=31098 AND `source_type`=0 AND `id`=0 AND `link`=0;

UPDATE `creature_template` SET `rank`='0' WHERE  `entry`=31099;

UPDATE `gameobject` SET `spawntimesecs`='30' WHERE  `guid`=29713;

UPDATE `gameobject` SET `spawntimesecs`='30' WHERE  `guid`=29714;

UPDATE `creature_template` SET `gossip_menu_id`='0', `npcflag`='4226' WHERE  `entry`=28500;
UPDATE `creature_addon` SET `bytes2`='1', `emote`='234' WHERE  `guid`=96151;

UPDATE `creature_addon` SET `bytes2`='1', `emote`='234' WHERE  `guid`=96148;

UPDATE `creature` SET `spawndist`='5', `MovementType`='1' WHERE  `guid`=96150;
UPDATE `creature_addon` SET `bytes2`='1', `emote`='0' WHERE  `guid`=96150;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=28383;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28383;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(28383, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, '', 11, 43897, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Acherus Necromancer - On Respawn - Add Aura Shadow Channeling');

DELETE FROM `creature_addon` WHERE `guid`=96142;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(96142, 0, 0, 0, 0, 378, 0, 0, 0, NULL);

DELETE FROM `creature_addon` WHERE `guid`=96141;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(96141, 0, 0, 0, 0, 378, 0, 0, 0, NULL);

DELETE FROM `creature_addon` WHERE `guid`=96143;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(96143, 0, 0, 0, 0, 378, 0, 0, 0, NULL);

DELETE FROM `creature_questitem` WHERE `CreatureEntry`=28766;
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES 
(28766, 0, 39160, 25549);

UPDATE `creature` SET `unit_flags`='4' WHERE  `guid`=96296;

