DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(49191,49554);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 49191, 0, 0, 31, 0, 3, 27712, 0, 0, 0, 0, '', '7th Legion Chain Gun hits Mindless Ghoul'),
(13, 1, 49554, 0, 0, 31, 0, 3, 27795, 0, 0, 0, 0, '', 'Summon injured soldier hits Injured Soldier Summon Point');

UPDATE `creature` SET `spawntimesecs`=120 WHERE  `id`=27712;

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(27712,27795,27788);

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(27712,27788) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2778800 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(27712, 0, 0, 0, 9, 0, 100, 0, 0, 5, 10000, 15000, 11, 50196, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mindless Ghoul - IC - Cast Rotting Touch'),
(27788, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - On Just Summoned - Store Targetlist'),
(27788, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 49774, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - On Just Summoned - Cast cast Cower + Fear Visual'),
(27788, 0, 2, 12, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2778800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - Run Script'),
(27788, 0, 3, 5, 7, 0, 100, 0, 0, 0, 0, 0, 11, 49774, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - On Evade  - cast Cower + Fear Visual'),
(27788, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 64, 2, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - On 7th Legion cannon within 3 yards  - Disable Combat movement'),
(27788, 0, 5, 0, 6, 0, 100, 0, 0, 0, 0, 0, 78, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - On Death  - Reset all scripts'),
(27788, 0, 6, 4, 75, 0, 100, 1, 0, 27714, 10, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - On 7th Legion Cannon within 15 yards  - Remove aura Cower + Fear Visual'),
(27788, 0, 7, 8, 75, 0, 100, 1, 0, 27714, 3, 0, 1, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - On 7th Legion Cannon within 5 yards  - Say'),
(27788, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 33, 27788, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - On 7th Legion Cannon within 5 yards  - Give kill credit to stored target'),
(27788, 0, 9, 13, 61, 0, 100, 0, 0, 0, 0, 0, 28, 49774, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - On 7th Legion Cannon within 5 yards  - Remove aura Cower + Fear Visual'),
(27788, 0, 10, 0, 1, 0, 100, 0, 500, 500, 7500, 7500, 29, 0, 0, 0, 0, 0, 0, 12, 2, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - OOC - Follow stored target 2'),
(27788, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - Just Summoned  - Disable melee combat'),
(27788, 0, 12, 0, 61, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - Just Summoned  - Disable Combat movement'),
(27788, 0, 13, 14, 61, 0, 100, 0, 0, 0, 0, 0, 28, 49775, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier -  On 7th Legion Cannon within 15 yards  - Remove aura Cower + Fear Visual'),
(27788, 0, 14, 15, 61, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier -  On 7th Legion Cannon within 15 yards  - Set Unit Flags'),
(27788, 0, 15, 0, 61, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - On 7th Legion Cannon within 15 yards  - Set Run'),
(27788, 0, 16, 0, 7, 0, 100, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 12, 2, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - On Evade Follow stored targetlist 2'),
(2778800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 64, 2, 0, 0, 0, 0, 0, 19, 27792, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - Script - Store Targetlist 2 closest Injured Soldier Waypoint 01 '),
(2778800, 9, 1, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 64, 2, 0, 0, 0, 0, 0, 19, 27793, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - Script - Store Targetlist 2 closest Injured Soldier Waypoint 02'),
(2778800, 9, 2, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 64, 2, 0, 0, 0, 0, 0, 19, 27794, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - Script - Store Targetlist 2 closest Injured Soldier Waypoint 03'),
(2778800, 9, 3, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 64, 2, 0, 27714, 0, 0, 0, 19, 27714, 0, 0, 0, 0, 0, 0, 'Injured 7th Legion Soldier - Script - Store Targetlist 2  7th legion chain gun');

DELETE FROM `creature_text` WHERE `entry`=27788;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(27788, 0, 0, 'I was almost ghoul bait! Thanks for the rescue!', 12, 0, 100, 0, 0, 0, 'Injured 7th Legion Soldier', 27097),
(27788, 0, 1, 'It''s a good thing you came along, ally! We were done for!', 12, 0, 100, 0, 0, 0, 'Injured 7th Legion Soldier', 27098),
(27788, 0, 2, 'Thanks for the cover fire! It''s a MADHOUSE down there!', 12, 0, 100, 0, 0, 0, 'Injured 7th Legion Soldier', 27095),
(27788, 0, 3, 'Wow, I thought I was a goner! Thanks, friend!', 12, 0, 100, 0, 0, 0, 'Injured 7th Legion Soldier', 27096);
