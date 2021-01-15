UPDATE `creature_template` SET `AIName`='SmartAI',`npcflag`=1,`gossip_menu_id`=10990 WHERE `entry`IN(37671,38065);
UPDATE `creature` SET `npcflag`=3 WHERE `id`=38293;

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN(37172,38066) AND `id`>2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN(37671,38065);

DELETE FROM `smart_scripts` WHERE `source_type`=2 AND `entryorguid` IN(5703,5705) AND `id`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(37671, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Crown Supply Guard - On Data Set - Say'),
(38065, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Crown Supply Guard - On Data Set - Say'),
(37172, 0, 3, 0, 8, 0, 100, 0, 69445, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Detective Snap Snagglebolt - On Spellhit - say'),
(37172, 0, 4, 0, 8, 0, 100, 0, 69563, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Detective Snap Snagglebolt - On Spellhit - say'),
(37172, 0, 5, 0, 8, 0, 100, 0, 69489, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Detective Snap Snagglebolt - On Spellhit - say'),
(38066, 0, 3, 0, 8, 0, 100, 0, 69445, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Inspector Snip Snagglebolt - On Spellhit - say'),
(38066, 0, 4, 0, 8, 0, 100, 0, 69563, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Inspector Snip Snagglebolt - On Spellhit - say'),
(38066, 0, 5, 0, 8, 0, 100, 0, 69489, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Inspector Snip Snagglebolt - On Spellhit - say'),
(5703,2,1,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,208843,38065,0,0,0,0,0,"On Trigger - Set Data"),
(5705,2,1,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,48573,37671,0,0,0,0,0,"On Trigger - Set Data");

UPDATE `smart_scripts` SET `link`=1 WHERE  `entryorguid`IN(5703,5705) AND `source_type`=2 AND `id`=0 AND `link`=0;

DELETE FROM `creature_text` WHERE `entry` IN(37172,38066,37671,38065);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(37671, 0, 0, 'That crate won''t deliver itself, friend. Get a move on!', 12, 0, 100, 1, 0, 0, 38024, 0, 'Crown Supply Guard'),
(38065, 0, 0, 'That crate won''t deliver itself, friend. Get a move on!', 12, 0, 100, 1, 0, 0, 38024, 0, 'Crown Supply Guard'),
(37172, 0, 0, 'You know, that does smell pretty... Hey! Stop spraying that thing at me!', 12, 0, 100, 1, 0, 0, 38296, 0, 'Detective Snap Snagglebolt'),
(37172, 1, 0, 'Don''t tempt me! Do you even know what''s in those things?', 12, 0, 100, 1, 0, 0, 38382, 0, 'Detective Snap Snagglebolt'),
(38066, 0, 0, 'You know, that does smell pretty... Hey! Stop spraying that thing at me!', 12, 0, 100, 1, 0, 0, 38296, 0, 'Inspector Snip Snagglebolt'),
(38066, 1, 0, 'Don''t tempt me! Do you even know what''s in those things?', 12, 0, 100, 1, 0, 0, 38382, 0, 'Inspector Snip Snagglebolt');

DELETE FROM `gossip_menu` WHERE `entry`=10990;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(10990, 15282), 
(10990, 15280);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=10990;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 10990, 15280, 0, 0, 1, 0, 71450, 0, 0, 1, 0, 0, '', 'Crown Guard has different gossip if player has no aura Crown Parcel Service Uniform'),
(14, 10990, 15282, 0, 0, 1, 0, 71450, 0, 0, 0, 0, 0, '', 'Crown Guard has different gossip if player has aura Crown Parcel Service Uniform');
