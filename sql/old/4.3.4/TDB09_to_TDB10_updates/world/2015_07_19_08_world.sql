--
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=108013, `action_param2`=0, `action_param3`=0 WHERE `entryorguid` IN (-370665,-370584, -370561,-370552) AND `source_Type`=0 AND `id`=0;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `Entry` IN (51717, 51936, 12369, 40503);
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=2287 AND `source_type`=0 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2287 AND `source_type`=0 AND `id`=4;
UPDATE `smart_scripts` SET `event_param3`=3000 WHERE `entryorguid`=5328 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_param2`=20 WHERE `entryorguid`=5328 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=32581, `action_param2`=0, `action_param3`=0  WHERE `entryorguid`=21352 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=36977, `action_param2`=0, `action_param3`=0, `action_param4`=0 WHERE `entryorguid`=21352 AND `source_type`=0 AND `id`=2;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=34631, `action_param2`=0, `action_param3`=0, `action_param4`=0 WHERE `entryorguid`=21498 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=36885, `action_param2`=0, `action_param3`=0, `action_param4`=0 WHERE `entryorguid`=21498 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=95006, `action_param2`=2 WHERE `entryorguid`=30698 AND `source_type`=0 AND `id`=7;
UPDATE `smart_scripts` SET `event_param2`=20 WHERE `entryorguid`=40969 AND `source_type`=0 AND `id`=4;
UPDATE `smart_scripts` SET `action_type`=85 WHERE `entryorguid`=47707 AND `source_type`=0 AND `id`=1;
