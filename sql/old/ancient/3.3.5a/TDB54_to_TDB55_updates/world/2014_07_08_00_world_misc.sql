--
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`=24359;

DELETE FROM `smart_scripts` WHERE `entryorguid`=24359 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24359,0,0,0,25,0,100,1,0,0,0,0,11,8722,0,0,0,0,0,1,0,0,0,0,0,0,0,'Apothecary Anastasia <Royal Apothecary Society> - On Spawn Summon Succubus');

DELETE FROM `creature` WHERE `guid` IN (84989,112617,74136,74475,123937,123936,123933,74178);

UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`=35475;

DELETE FROM `smart_scripts` WHERE `entryorguid`=35475 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(-84660,-84661,-84664,-84665) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-84660,0,0,0,25,0,100,1,0,0,0,0,11,8722,0,0,0,0,0,1,0,0,0,0,0,0,0,'Visting Warlock - On Spawn Summon Succubus'),
(-84661,0,0,0,25,0,100,1,0,0,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,'Visting Warlock - On Spawn Summon Voidwalker'),
(-84664,0,0,0,25,0,100,1,0,0,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,'Visting Warlock - On Spawn Summon Voidwalker'),
(-84665,0,0,0,25,0,100,1,0,0,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,'Visting Warlock - On Spawn Summon Voidwalker');

UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`=29614;

DELETE FROM `smart_scripts` WHERE `entryorguid`=29614 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2961400,2961401) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29614,0,0,0,25,0,100,1,0,0,0,0,87,2961400,2961401,2961400,2961401,2961400,2961401,1,0,0,0,0,0,0,0,'Onslaught Darkweaver - On Spawn - Run Random Script'),
(29614,0,1,0,1,0,100,0,0,0,1800000,1800000,11,13787,0,0,0,0,0,1,0,0,0,0,0,0,0,'Onslaught Darkweaver - On Spawn - Cast Demon Armor'),
(29614,0,2,0,0,0,100,0,1000,3000,3000,3500,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,'Onslaught Darkweaver - IC - Cast Shadow Bolt'),
(29614,0,3,4,0,0,100,0,7000,15000,180000,210000,11,54840,0,0,0,0,0,1,0,0,0,0,0,0,0,'Onslaught Darkweaver - IC - Cast Metamorphosis'),
(29614,0,4,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Onslaught Darkweaver - Linked with Previous event -  Say'),
(29614,0,5,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Onslaught Darkweaver - On Agro Say'),
(2961400,9,0,0,0,0,100,0,0,0,0,0,11,8722,2,0,0,0,0,1,0,0,0,0,0,0,0,'Onslaught Darkweaver - Script - Summon Succubus'),
(2961401,9,0,0,0,0,100,0,0,0,0,0,11,11939,2,0,0,0,0,1,0,0,0,0,0,0,0,'Onslaught Darkweaver - Script - Summon Imp');

DELETE FROM `creature_text` WHERE `entry` =29614;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES (29614, 0, 0, 'Even in death there will be no escape for you!', 12, 0, 100, 0, 0, 0, 'Onslaught Darkweaver', 30267),
(29614, 0, 1, 'I shall feast upon your soul!', 12, 0, 100, 0, 0, 0, 'Onslaught Darkweaver', 30268),
(29614, 0, 2, 'Now you know. Now you must die!', 12, 0, 100, 0, 0, 0, 'Onslaught Darkweaver', 30266),
(29614, 0, 3, 'You will not leave this cavern alive!', 12, 0, 100, 0, 0, 0, 'Onslaught Darkweaver', 30269),
(29614, 1, 0, 'The darkweaver pierces you with an evil grin as he shifts into an entirely different form.', 16, 0, 100, 0, 0, 0, 'Onslaught Darkweaver', 30265);
