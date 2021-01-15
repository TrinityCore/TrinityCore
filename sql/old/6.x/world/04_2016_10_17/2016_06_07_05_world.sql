--
UPDATE `smart_scripts` SET `link`=0, `event_type`=0 WHERE `source_type`=9;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (33419, 35161, 36890, 37212, 37548, 38912, 38942) AND `id`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (2018, 2206, 3502, 3845, 5862, 8338, 12864, 14715, 23636, 24841, 24842, 29647, 34830, 36636, 36708, 36815, 36942, 38070, 39261, 39268, 43325, 47762) AND `id`=1;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (3845, 34309, 36660, 36942, 39261, 39268) AND `id`=2;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (5953, 14753, 39317) AND `id`=3;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=3696 AND `id`=4;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=45438 AND `id`=7;
UPDATE `smart_scripts` SET `link`=0, `event_type`=61, `event_param2`=0 WHERE `entryorguid`=34872 AND `id`=2;
UPDATE `smart_scripts` SET `event_param2`=34872, `action_param2`=0 WHERE `entryorguid`=34872 AND `id`=3;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=45410 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=170 WHERE `entryorguid` IN (18707300, 19055500) AND `id`=0;
UPDATE `smart_scripts` SET `action_param1`=169 WHERE `entryorguid` IN (18707300, 19055500) AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=169 WHERE `entryorguid`=29884 AND `id`=5;
UPDATE `smart_scripts` SET `event_param1`=0, `event_param2`=15 WHERE `entryorguid`=25073 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-3621, -3620, 50897);
