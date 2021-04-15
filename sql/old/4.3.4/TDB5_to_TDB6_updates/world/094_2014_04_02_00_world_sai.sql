--
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry` IN (18162,18161);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18162,18161) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18161,0,0,0,8,0,100,0,32042,0,0,0,33,18161,0,0,0,0,0,7,0,0,0,0,0,0,0,'Underground Well Credit Marker - On Spell Hit ''Violet Scrying Crystal'' - Quest Credit'),
(18162,0,0,0,8,0,100,0,32042,0,0,0,33,18162,0,0,0,0,0,7,0,0,0,0,0,0,0,'Underground Pond Credit Marker - On Spell Hit ''Violet Scrying Crystal'' - Quest Credit');
