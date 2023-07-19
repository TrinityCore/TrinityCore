-- reduce greetings range
UPDATE `smart_scripts` SET `event_param2`=9 WHERE `entryorguid` IN(4981,1341,1333,1324,1275,1286,1295,1299,1319) AND `source_type`=0 AND `id`=0 AND `event_type`=10;
-- fix equip
UPDATE `smart_scripts` SET `action_param1`=4 WHERE `entryorguid`=197600 AND `source_type`=9 AND `id`=3;
UPDATE `creature` SET `equipment_id`=4 WHERE `guid`=313937;
