DELETE FROM `phase_area` WHERE `AreaId` IN (4990, 4979, 5020, 4861, 5014);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(4861, 194, 'Mount Hyjal - The Regrowth - Phase 194'),
(5014, 194, 'Mount Hyjal - The Inferno - Phase 194'),
(4990, 194, 'Mount Hyjal - Shrine of Aviana - Phase 194'),
(4979, 195, 'Mount Hyjal - Shrine of Goldrinn - Phase 195'),
(5020, 194, 'Mount Hyjal - The Flamewake - Phase 194');

UPDATE `creature` SET `terrainSwapMap`= 719 WHERE `id` IN (39939, 39974, 39997, 39999, 40336, 39998, 39927);

DELETE FROM `creature` WHERE `guid` IN (386151, 386152, 386154, 386155, 386241, 386247, 386248, 386249, 386250, 386251, 386451, 386468, 386469, 386470, 386472, 386473, 386474, 386475, 386476, 386477, 386478, 386479, 386480, 386481, 386489, 386490, 386491, 386493, 386494, 386495, 386496, 386497, 386498, 386499, 386500, 386501, 386502, 386503, 386504, 386505, 386523, 386524, 386526);

DELETE FROM `creature_addon` WHERE `guid` IN (386151, 386152, 386154, 386155, 386241, 386247, 386248, 386249, 386250, 386251, 386451, 386468, 386469, 386470, 386472, 386473, 386474, 386475, 386476, 386477, 386478, 386479, 386480, 386481, 386489, 386490, 386491, 386493, 386494, 386495, 386496, 386497, 386498, 386499, 386500, 386501, 386502, 386503, 386504, 386505, 386523, 386524, 386526);

UPDATE `creature_template` SET `ScriptName`= 'npc_mh_raging_firestorm', `AIName`= '' WHERE `entry`= 39939;
DELETE FROM `smart_scripts` WHERE `entryorguid`=39939 AND `source_type`=0;

-- Creature Grove Warden 39941 SAI
SET @ENTRY := 39941;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On evade - Self: Despawn instantly // ");
