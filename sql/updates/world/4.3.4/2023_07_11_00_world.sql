UPDATE `quest_template_addon` SET `SpecialFlags`= `SpecialFlags`&~0x2 WHERE `SpecialFlags` & 0x2 != 0;
DELETE FROM `areatrigger_involvedrelation` WHERE `id` IN (78, 230, 2926, 4300, 4987, 5030, 5703, 5704, 5705, 5706);
DELETE FROM `event_scripts` WHERE `command`= 7 AND `datalong` IN (10923, 5056);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6741, 17612, 17716, 19273, 19851, 20209, 20417, 20418, 20440, 27439, 28105, 30657, 911700, 1030700, 1848201, 2546001);
UPDATE `creature_template` SET `AIName`= '' WHERE `entry` IN (28105, 20209, 20418, 6741, 20417, 20440, 27439);
