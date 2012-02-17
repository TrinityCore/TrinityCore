UPDATE `smart_scripts` SET `action_param1`=1,`event_flags`=1 WHERE `action_type`=25;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND ((`entryorguid`=11360 AND `id`=1) OR (`entryorguid`=27225 AND `id`=20) OR (`entryorguid`=27615 AND `id`=15));
UPDATE `smart_scripts` SET `id`=20 WHERE `entryorguid`=27225 AND `id`=21;
UPDATE `smart_scripts` SET `id`=21 WHERE `entryorguid`=27225 AND `id`=22;
DELETE FROM `creature_text` WHERE `text`='%s attempts to run away in fear!';
