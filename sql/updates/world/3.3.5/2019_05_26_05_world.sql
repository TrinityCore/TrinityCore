-- 
UPDATE `spell_dbc` SET `Effect2` = 28, `EffectMiscValueB2` = 64, `EffectImplicitTargetA1`=48 WHERE `Id`IN (21883);
UPDATE `gameobject_template` SET `AIName`="" WHERE `entry`=178905;
DELETE FROM `smart_scripts` WHERE `entryorguid`=178905 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=13696 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(13696, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 30, 0, 0, 0, 0, 0, 0, 'Noxxious Scion - On Just created - Attack');
