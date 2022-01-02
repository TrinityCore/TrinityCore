-- Baby Blizzard Bear
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=32841;
DELETE FROM `creature_template_addon` WHERE `entry` IN (32841);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES (32841,'61854');
DELETE FROM `smart_scripts` WHERE `entryorguid`=32841 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3284100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(32841,0,0,0,8,0,100,0,61853,0,15000,15000,80,3284100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Baby Blizzard Bear - On Spell Hit - Action list'),
(3284100,9,0,0,0,0,100,0,10000,15000,0,0,28,61853,0,0,0,0,0,1,0,0,0,0,0,0,0,'Baby Blizzard Bear - Action list - Remove Spell');

-- Egbert
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=23258;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23258 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2325800 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23258,0,0,0,8,0,100,0,40669,0,15000,15000,80,2325800,0,0,0,0,0,1,0,0,0,0,0,0,0,'Egbert - On Spell Hit - Action list'),
(2325800,9,0,0,0,0,100,0,5000,15000,0,0,28,40669,0,0,0,0,0,1,0,0,0,0,0,0,0,'Egbert - Action list - Remove Spell');
