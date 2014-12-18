UPDATE `smart_scripts` SET `event_flags`=0 WHERE  `entryorguid` IN(24874,24875,24876,24877) AND `source_type`=0 AND `id`=0 AND `link`=1;
DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=45323;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES(0, 45323, 64, '', '', 'Ignore LOS for Returning Vrykul Artifact');
UPDATE `creature_template` SET `unit_flags`=768 WHERE  `entry`=24889;
UPDATE `spell_area` SET `quest_start_status`=74 WHERE  `spell`=57745 AND `area`=4591 AND `quest_start`=13068 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=24018 AND `SourceEntry` IN(34090,34091);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(1, 24018, 34090, 0, 0, 8, 0, 11236, 0, 0, 0, 0, 0, '', 'Mezhens Writings drops if player is rewarded for Necro Overlord Mezhen'),
(1, 24018, 34091, 0, 0, 8, 0, 11264, 0, 0, 0, 0, 0, '', 'Mezhens Writings drops if player is rewarded for Necro Overlord Mezhen'),
(1, 24018, 34090, 0, 1, 9, 0, 11236, 0, 0, 0, 0, 0, '', 'Mezhens Writings drops if player has taken Necro Overlord Mezhen'),
(1, 24018, 34091, 0, 1, 9, 0, 11264, 0, 0, 0, 0, 0, '', 'Mezhens Writings drops if player has taken Necro Overlord Mezhen'),
(1, 24018, 34090, 0, 2,28, 0, 11236, 0, 0, 0, 0, 0, '', 'Mezhens Writings drops if player has completed Necro Overlord Mezhen'),
(1, 24018, 34091, 0, 2,28, 0, 11264, 0, 0, 0, 0, 0, '', 'Mezhens Writings drops if player has completed Necro Overlord Mezhen');
UPDATE `smart_scripts` SET `action_param4`=1 WHERE  `entryorguid`=21352 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `action_param4`=1 WHERE  `entryorguid`=21498 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `action_param4`=1 WHERE  `entryorguid`=21498 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `gameobject_loot_template` SET `maxcount`=4 WHERE  `entry`=1502 AND `item`=2770;
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`=32239;
