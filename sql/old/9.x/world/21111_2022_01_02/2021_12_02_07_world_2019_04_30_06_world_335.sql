-- 
-- Event Script
DELETE FROM `event_scripts` WHERE `id`=9208;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(9208,0,10,14862,9000000,0,-7276.38,852.34,3.64,0.5),
(9208,0,10,15288,9000000,0,-7233.39,906.415,-1.76649,1.81259),
(9208,0,10,15286,9000000,0,-7212.16,911.711,-1.76649,2.58543),
(9208,0,10,15290,9000000,0,-7210.3,895.014,-1.76649,0.544185);

-- Aluntir
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15288;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15288 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15288,0,0,0,0,0,30,0,5000,8000,12000,15000,11,19471,0,0,0,0,0,5,0,0,0,0,0,0,0,"Aluntir - In Combat - Cast 'Cast Berserker Charge'"),
(15288,0,1,0,6,0,100,0,0,0,0,0,63,1,1,0,0,0,0,19,14862,0,0,0,0,0,0,"Aluntir - On Just Died - Set Counter to Emissary Roman'khan");

-- Xil'xix
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15286;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15286 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15286,0,0,0,0,0,30,0,3000,6000,12000,15000,11,19471,0,0,0,0,0,5,0,0,0,0,0,0,0,"Xil'xix - In Combat - Cast 'Cast Berserker Charge'"),
(15286,0,1,0,6,0,100,0,0,0,0,0,63,1,1,0,0,0,0,19,14862,0,0,0,0,0,0,"Xil'xix - On Just Died - Set Counter to Emissary Roman'khan");

-- Arakis
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15290;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15290 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15290,0,0,0,0,0,30,0,7000,10000,12000,15000,11,19471,0,0,0,0,0,5,0,0,0,0,0,0,0,"Arakis - In Combat - Cast 'Cast Berserker Charge'"),
(15290,0,1,0,6,0,100,0,0,0,0,0,63,1,1,0,0,0,0,19,14862,0,0,0,0,0,0,"Arakis - On Just Died - Set Counter to Emissary Roman'khan");

-- Emissary Roman'khan
UPDATE `creature_template` SET `DamageModifier`=3, `AIName`="SmartAI" WHERE `entry`=14862;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14862 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14862,0,0,0,11,0,100,0,0,0,0,0,18,33555200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emissary Roman'khan - On Spawn - Add Unit Flags 'Immune to Player', 'Immune to NPC' & 'Not Selectable'"),
(14862,0,1,0,11,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emissary Roman'khan - On Spawn - Set Visibility Off"),
(14862,0,2,0,77,0,100,0,1,3,0,0,19,33555200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emissary Roman'khan - On 3 Counters Set - Remove Unit Flags 'Immune to Player', 'Immune to NPC' & 'Not Selectable'"),
(14862,0,3,0,77,0,100,0,1,3,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emissary Roman'khan - On 3 Counters Set - Set Visibility On"),
(14862,0,4,0,77,0,100,0,1,3,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emissary Roman'khan - On 3 Counters Set - Say Line 0"),
(14862,0,5,0,4,0,100,0,0,0,0,0,108,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emissary Roman'khan - On Aggro - Set Mana To 0"),
(14862,0,6,0,0,0,100,0,3000,6000,3000,6000,11,23772,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emissary Roman'khan - In Combat - Cast 'Wilt'"),
(14862,0,7,0,0,0,100,0,6000,10000,8000,12000,11,23774,0,0,0,0,0,5,0,0,0,0,0,0,0,"Emissary Roman'khan - In Combat - Cast 'System Shock'"),
(14862,0,8,0,3,0,100,0,99,100,1000,1000,11,23773,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emissary Roman'khan - Between 99-100% Mana - Cast 'Suffering of Sanity'");

DELETE FROM `creature_text` WHERE `CreatureID`=14862;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14862,0,0,"Come, puny mortals. Come and face your end. The secrets of Ahn'Qiraj will die with Roman'khan!",14,0,100,0,0,0,10888,0,"Emissary Roman'khan");
