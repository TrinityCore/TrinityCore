    UPDATE `creature_template` SET `AIName`='SmartAI',`npcflag`=16777216 WHERE `entry`=28161;

    DELETE FROM `smart_scripts` WHERE `entryorguid`=28161 and `source_type`=0;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2816100 and `source_type`=9;

    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (28161, 0, 0, 4, 8, 0, 100, 0, 51959, 0, 11000, 11000, 28, 51846, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chicken Escapee - On Spellhit (Chicken Net) - Remove Aura Scared Chicken'),
    (28161, 0, 1, 2, 73, 0, 100, 0, 0, 0, 0, 0, 85, 51037, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Chicken Escapee - On Spellclick - Invoker Cast Capture Chicken Escapee '),
    (28161, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chicken Escapee - On Spellclick - Despawn'),
    (28161, 0, 2, 3, 11, 0, 100, 0, 0, 0, 0, 0, 11, 50734, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chicken Escapee - On Reset - Cast Frenzyheart Chicken: Invisibility'),
    (28161, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 51846, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chicken Escapee - On Reset - Cast Scared Chicken'),
    (28161, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2816100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chicken Escapee - Link - Run Script'),
    (2816100, 9, 0, 0, 0, 0, 100, 0, 10, 10, 0, 0, 11, 51959, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chicken Escapee - Script - Cast Chicken Net');

    DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=28161;
    INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
    (28161, 51037, 0, 0);

    DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=28161;
    INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
    (18, 28161, 51037, 0, 0, 9, 0, 12702, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick'),
    (18, 28161, 51037, 0, 1, 9, 0, 12532, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick');

    DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=51959;
    INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
    (13, 1, 51959, 0, 0, 31, 0, 3, 28161, 0, 0, 0, 0, '', 'Chicken Net targets chicken escapee');
