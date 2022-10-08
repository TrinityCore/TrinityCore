
ALTER TABLE `creature_template` ADD COLUMN `spell_school_immune_mask` int(3) unsigned NOT NULL DEFAULT '0' AFTER `mechanic_immune_mask`;

UPDATE `gameobject_template` SET `Data10` = 67869 WHERE `entry` = 195327;

-- Merchant Square Door (195327) ***go_merchant_square_door_195327***
UPDATE `gameobject_template` SET `Data0`=1944, `AIName`='SmartGameObjectAI', `VerifiedBuild`=25549 WHERE `entry`=195327;
UPDATE `gameobject_template_addon` SET `flags`=65540 WHERE `entry`=195327;

DELETE FROM `smart_scripts` WHERE `entryorguid`=195327;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(195327, 1, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 85, 67869, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Merchant Square Door - On Target Range - Player Cast on Self Knocking'),
(195327, 1, 1, 0, 64, 0, 100, 0, 0, 0, 0, 0, 33, 35830, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Merchant Square Door - On Gossip Hello - Quest Credit');

UPDATE quest_template SET QuestType = 0 WHERE  ID = 14098;
UPDATE quest_template SET QuestType = 0 WHERE  ID = 14154;

UPDATE quest_template SET QuestType = 0 WHERE  ID = 14293;



