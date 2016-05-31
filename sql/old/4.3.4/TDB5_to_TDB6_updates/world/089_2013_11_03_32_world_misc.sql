-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=26407;
UPDATE `creature_template` SET `ainame`='SmartAI',`scriptname`='' WHERE `entry` IN (26407,27017);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26407,27017) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26407,0,0,0,0,0,100,0,10000,12000,10000,12000,11,52703,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lightning Sentry - IC - Cast Charged Sentry Totem'),
(26407,0,1,0,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,27017,25,0,0,0,0,0,'Lightning Sentry - On Death - Set Data'),
(27017,0,0,0,38,0,100,0,0,1,0,0,11,47797,0,0,0,0,0,23,0,0,0,0,0,0,0,'Depleted War Golem - On Data Set - Give Quest Credit');
