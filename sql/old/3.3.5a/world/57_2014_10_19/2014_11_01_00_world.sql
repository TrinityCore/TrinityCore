UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry` IN(30894,31049);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(30894,31049) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(30894, 0, 0, 1, 8, 0, 100, 0, 58151, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Spellhit (Subdued Lithe Stalker) - Store Targetlist'),
(30894, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Spellhit (Subdued Lithe Stalker) - Follow Target'),
(30894, 0, 2, 3, 8, 0, 100, 0, 58178, 0, 0, 0, 33, 31049, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Spellhit (CSA Dummy Effect) - Give Kill Credit'),
(30894, 0, 3, 0, 61, 0, 100, 0, 58178, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Spellhit (CSA Dummy Effect) - Despawn'),
(31049, 0, 0, 0, 1, 0, 100, 0, 0, 0, 1000, 1000, 11, 58178, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Geist Return Bunny - OOC - Cast CSA Dummy Effect (25 yards)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=30894;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 4, 30894, 0, 0, 1, 1, 58151, 0, 0, 0, 0, 0, '', 'Only run AI if Lithe Stalker has Aura (Subdued Lithe Stalker)');
