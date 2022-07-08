-- 
UPDATE `gameobject_template` SET `AIName`='' WHERE `entry` IN (186470);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (186403);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (186403,186470) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18640300,2397400,2397401,2397402,2397403) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23974) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(186403, 1, 0, 0, 8, 0, 100, 1, 42703, 0, 0, 0, 0, 118, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Whisper Gulch Ore - On Spell hit - Set gob state"),
(186403, 1, 1, 0, 8, 0, 100, 1, 42703, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Whisper Gulch Ore - On Spell hit - Despawn"),
(23974, 0, 0, 0, 8, 0, 100, 0, 42697, 0, 1000, 1000, 0, 87, 2397400, 2397401, 2397402, 2397403, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Whisper Gulch Ore Bunny - On Spellhit 'Danger! Explosive!: Ore Trap' - Run Random Script (No Repeat) (Dungeon)"),
(2397400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 50, 186404, 120, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Whisper Gulch Ore Bunny - On Script - Summon Gameobject 'Whisper Gulch Gem'"),
(2397401, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 50, 186466, 120, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Whisper Gulch Ore Bunny - On Script - Summon Gameobject 'Whisper Gulch Gem'"),
(2397402, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 50, 186467, 120, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Whisper Gulch Ore Bunny - On Script - Summon Gameobject 'Whisper Gulch Gem'"),
(2397403, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 50, 186468, 120, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Whisper Gulch Ore Bunny - On Script - Summon Gameobject 'Whisper Gulch Ore Fragment'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (42703);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,42703,0,0,31,0,5,186403,0,0,0,'','Spell Steelring''s Foolproof Dynamite effect0 targets Whisper Gulch Ore');
