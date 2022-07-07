-- Doorway to the Abyss (10392)
UPDATE `gameobject_template_addon` SET `Flags`=4 WHERE `entry`=182935;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE `entry`=182935;
DELETE FROM `smart_scripts` WHERE `entryorguid`=182935 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(182935,1,0,1,8,0,100,0,35739,0,0,0,0,41,0,0,0,0,0,0,20,184656,10,0,0,0,0,0,'Rune of Spite - On Spell Hit - Despawn gob'),
(182935,1,1,0,61,0,100,0,0,0,0,0,0,99,3,0,0,0,0,0,20,185190,10,0,0,0,0,0,'Rune of Spite - On Spell Hit - Set Loot State');
UPDATE `gameobject` SET `spawntimesecs`=30  WHERE `id` IN (184656,185190);

DELETE FROM `gameobject_addon` WHERE `guid` in (24681,24682,32137,32138,32139);
