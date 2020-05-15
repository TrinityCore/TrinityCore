-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (649200,649201) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6492) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6492, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 9093, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - On Reset - Cast 'Rift Spawn Invisibility'"),
(6492, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - On Reset - Set Invincibility at 1 HP"),
(6492, 0, 2, 3, 8, 0, 100, 1, 9095, 0, 0, 0, 0, 28, 9093, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - On Spellhit 'Cantation of Manifestation' - Remove Aura 'Rift Spawn Invisibility'"),
(6492, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 11, 9096, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - On Spellhit 'Cantation of Manifestation' - Cast 'Rift Spawn Manifestation'"),
(6492, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - On Spellhit 'Cantation of Manifestation' - Start Attacking"),
(6492, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 28, 9095, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - On Spellhit 'Cantation of Manifestation' - Remove Aura 'Cantation of Manifestation'"),
(6492, 0, 6, 0, 8, 1, 100, 1, 9012, 0, 0, 0, 0, 80, 649201, 2, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - On Spell hit - Action list"),
(649201, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 28, 9032, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - Action list - remove aura"),
(649201, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 9010, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - Action list - Cast Create Filled Containment Coffer'"),
(649201, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - Action list - Say text"),
(649201, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - Action list - Despawn"),
(6492, 0, 7, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - On Aggro - Say Line 0"),
(6492, 0, 8, 9, 7, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - On Evade - Say Line 1"),
(6492, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - On Evade - Despawn"),
(6492, 0, 10, 0, 2, 0, 100, 1, 0, 1, 0, 0, 0, 80, 649200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - Between 0-1% Health - Action list"),
(649200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 9032, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - Between 0-1% Health - Cast 'Self Stun - 30 seconds'"),
(649200, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - Between 0-1% Health - Set Event Phase 1"),
(649200, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - Between 0-1% Health - Disable combat movement"),
(649200, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - Between 0-1% Health - Root"),
(649200, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - Between 0-1% Health - Set Non selectable"),
(649200, 9, 5, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - On Script - Say line 1"),
(649200, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rift Spawn - On Script - Despawn");

UPDATE `gameobject_template` SET `displayId`=0 WHERE `entry` IN (103575);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=122088;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (122088, 12208800);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(122088, 1, 0, 0, 63, 0, 100, 1, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Containment Coffer - On Just created - activate self'),
(122088, 1, 1, 0, 60, 0, 100, 1, 2000, 2000, 0, 0, 11, 9012, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Containment Coffer - On Update - Cast 9012'),
(122088, 1, 2, 0, 60, 0, 100, 1, 2500, 2500, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Containment Coffer - On Update - Despawn');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=6492;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23837 AND `source_type`=0 AND `id`=2;

DELETE FROM `creature_text` WHERE `CreatureID`=6492 AND `GroupID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6492, 2, 0, "%s is sucked into the coffer!", 16, 0, 100, 0, 0, 0, 2553, 0, "Rift Spawn");

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=9095;
DELETE FROM `creature` WHERE `guid` IN (85736, 85737, 85738, 85739, 128980, 128981);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `npcflag`, `MovementType`) VALUES
(85736, 6492, 0, 1, 1, 0, 0, -9106.36, 836.526, 105.11, 5.9415, 180, 0, 0, 1, 0, 0, 0),
(85737, 6492, 0, 1, 1, 0, 0, -9082.42, 836.928, 108.42, 3.4361, 180, 0, 0, 1, 0, 0, 0),
(85738, 6492, 0, 1, 1, 0, 0, -9063.59, 837.388, 109.19, 3.9419, 180, 0, 0, 1, 0, 0, 0),
(85739, 6492, 0, 1, 1, 0, 0, -9090.17, 826.045, 115.66, 5.4231, 180, 0, 0, 1, 0, 0, 0),
(128980, 6492, 0, 1, 1, 0, 0, -9104.65, 833.212, 97.628, 3.7165, 180, 0, 0, 1, 0, 0, 0),
(128981, 6492, 0, 1, 1, 0, 0, -9077.57, 824.515, 108.41, 3.8279, 180, 0, 0, 1, 0, 0, 0);
