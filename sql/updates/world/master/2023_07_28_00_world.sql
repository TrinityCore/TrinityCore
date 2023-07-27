
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 15045;

UPDATE `smart_scripts` SET `action_param1`=290554, `Comment`='After 0 seconds - storedTarget[0]: Cast spell 290554 at storedTarget[0]' WHERE `entryorguid`=14971802 AND `source_type`=9 AND `id`=1;