SET @Guid := 84989;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(16514,16516, 17071);

DELETE FROM `smart_scripts` WHERE `entryorguid`=16522 AND `source_type`=0 AND `id` IN(12,13);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(16514,17071) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-@Guid AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16522, 0, 12, 0, 4, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Surveyor Candress - On Agro - Say'),
(16522, 0, 13, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 31515, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Surveyor Candress - On Reset - Cast Red Beam'),
(16514, 0, 0, 0, 20, 0, 100, 0, 9294, 0, 0, 0, 1, 0, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Botanist Taerix - On Quest Reward - Say Line 1'),
(16514, 0, 1, 2, 52, 0, 100, 0, 0, 16514, 0, 0, 1, 0, 5000, 0, 0, 0, 0, 19, 20227, 0, 0, 0, 0, 0, 0, 'Botanist Taerix - On Text Over - Say Line 1 (Apprentice Tedon)'),
(16514, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, 21645, 181370, 0, 0, 0, 0, 0, 'Botanist Taerix - On Text Over - Activate Volatile mutation cage'),
(16514, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @Guid, 16516, 0, 0, 0, 0, 0, 'Botanist Taerix - On Text Over - Set Data on Volatile Mutation'),
(16514, 0, 4, 5, 52, 0, 100, 0, 0, 20227, 0, 0, 1, 1, 5000, 0, 0, 0, 0, 19, 20227, 0, 0, 0, 0, 0, 0, 'Botanist Taerix - On Text Over - Say Line 1 (Apprentice Tedon)'),
(16514, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @Guid, 16516, 0, 0, 0, 0, 0, 'Botanist Taerix - On Text Over - Set Data on Volatile Mutation'),
(16514, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 133, 0, 0, 0, 0, 0, 19, 20227, 0, 0, 0, 0, 0, 0, 'Botanist Taerix - On Text Over - Play emote STATE_USESTANDING_NOSHEATHE(Apprentice Tedon)'),
(16514, 0, 7, 8, 52, 0, 100, 0, 1, 20227, 0, 0, 5, 30, 0, 0, 0, 0, 0, 19, 20227, 0, 0, 0, 0, 0, 0, 'Botanist Taerix - On Text Over - Play emote STATE_NONE (Apprentice Tedon)'),
(16514, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 30000, 0, 0, 0, 0, 19, 20227, 0, 0, 0, 0, 0, 0, 'Botanist Taerix - On Text Over - Say Line 1 (Apprentice Tedon)'),
(17071, 0, 0, 0, 20, 0, 100, 0, 9294, 0, 0, 0, 1, 0, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Botanist Taerix - On Quest Reward - Say Line 1'),
(-@Guid, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 46, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Volatile Mutation - On Data Set - Move out of cage'),
(-@Guid, 0, 1, 2, 38, 0, 100, 0, 2, 2, 0, 0, 11, 35068, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Volatile Mutation - On Data Set - Cast Quest - Volatile Mutation Transformation'),
(-@Guid, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Volatile Mutation - On Data Set - Cast Quest - Set Run'),
(-@Guid, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 46, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Volatile Mutation - On Data Set - Cast Quest - Move'),
(-@Guid, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Volatile Mutation - On Data Set - Despawn');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE`entry`IN(181433);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (181433);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(181433, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,1,0,0,0,0,0,0,19,20239,0,0,0, 0, 0, 0, 'Irradiated Power Crystal - On State Changed - Say Line 1 (Neutralizing Emote Placeholder)');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=31515;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 31515, 0, 0, 31, 0, 3, 17947, 0, 0, 0, 0, '', 'Spell Red Beam targets Red Crystal Bunny');

DELETE FROM `creature_text` WHERE `entry` IN(16522, 20239, 16514,20227);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(16522, 0, 0, 'You''ll not take me alive, scum!', 12, 0, 100, 0, 0, 0, 'Surveyor Candress', 12767),
(20239, 0, 0, 'As the neutralizing agent mixes into the waters of the lake, the water that was irradiated by the crystal seems to clear.', 16, 0, 100, 0, 0, 0, 'Neutralizing Emote Placeholder', 17912),
(16514, 0, 0, 'Tedon, go ahead and try the neutralizing agent on the mutated creature.', 12, 0, 100, 1, 0, 0, 'Botanist Taerix', 17938),
(20227, 0, 0, 'Looks like it''s time to let you out of this cage.', 12, 0, 100, 1, 0, 0, 'Apprentice Tedon', 17925),
(20227, 1, 0, 'Now, to put the neutralizing agent on it...', 12, 0, 100, 0, 0, 0, 'Apprentice Tedon', 17934),
(20227, 2, 0, 'Success!', 12, 0, 100, 71, 0, 0, 'Apprentice Tedon', 17939);

DELETE FROM `creature` WHERE `guid`=@Guid;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@Guid, 16516, 530, 1, 1, -4059.076, -13711.39, 73.58478, 5.88176, 120, 0, 0); -- 16516 (Area: -1)
