DELETE FROM `creature_questender` WHERE  `id`=37120 AND `quest`=24545;
DELETE FROM `gameobject` WHERE  `guid`=100025;

DELETE FROM `smart_scripts` WHERE `entryorguid`=37120 AND `source_type`=0 AND `id`>1;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(3712000,3780100) AND `source_type`=9;
UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`IN(37702,37801,37814,38191);

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(37702,37801,37814,38191) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(37120, 0, 2, 3, 38, 0, 100, 0, 1, 1, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Data Set - Set NPC Flags'), -- 23:45:40.047
(37120, 0, 3, 7, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3712000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Data Set - Run Script'),
(37120, 0, 4, 5, 40, 0, 100, 0, 1, 37120, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.969026, 'Highlord Darion Mograine - On Reached WP1 - Set Orientation'),
(37120, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 54, 35000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Reached WP1 - Pause WP'),
(37120, 0, 6, 0, 40, 0, 100, 0, 2, 37120, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.448623, 'Highlord Darion Mograine - On Reached WP2 - Set Orientation'),
(38191, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, 37801, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Data Set - Set NPC Flags'), -- 23:45:40.047
(37702, 0, 0, 0, 8, 0, 100, 0, 70471, 0, 0, 0, 11, 70508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Runeforge Bunny - On Spellhit (Mograine Forge Beam) - Cast Summon Shadows Edge Bunny'), 
(37702, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 70367, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Runeforge Bunny - On Data Set 1 1 - Cast Forge Flame Blue'), 
(37814, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 46598, 0, 0, 0, 0, 0, 19, 37801, 0, 0, 0, 0, 0, 0, 'Shadows Edge Axe Bunny - On Spawn - Cast Ride Vehicle Hardcoded'), 
(37801, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, 3780100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - On Spawn - Run Script'), 
(3780100, 9, 0, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 11, 70509, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Blue Explosion'), -- 23:45:56.391
(3780100, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 70509, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Blue Explosion'), -- 23:45:57.610
(3780100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 70509, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Blue Explosion'), -- 23:45:58.813
(3780100, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 70509, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Blue Explosion'), -- 23:46:00.016
(3780100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 70509, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Blue Explosion'), -- 23:46:01.235
(3780100, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 70509, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Blue Explosion'), -- 23:46:02.453
(3780100, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 70504, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Shadows Edge Aura'), -- 23:46:03.656
(3780100, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 38191, 1, 24000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Summon Shadows Edge'), 
(3780100, 9, 8, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 53, 0, 37801, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Start WP'), -- 23:46:06.110
(3780100, 9, 9, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 11, 70529, 0, 0, 0, 0, 0, 19, 38191, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Cast Shadows Edge Axe'), -- 23:46:19.438
(3780100, 9, 10, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadows Edge Bunny - Script - Despawn'), 
(3712000, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Say Line 0'), -- 23:45:42.594
(3712000, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 53, 0, 37120, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Start WP'), -- 23:45:42.594
(3712000, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 11, 70471, 0, 0, 0, 0, 0, 19, 37702, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Cast Mograine Forge Beam'), -- 23:45:49.906
(3712000, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Say Line 1'), -- 23:45:50.125
(3712000, 9, 4, 0, 0, 0, 100, 0, 17000, 17000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Say Line 2'), -- 23:46:07.125
(3712000, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 37702, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Set Data on Runeforge Bunny'), -- 23:46:08.000
(3712000, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Say Line 3'), -- 23:46:13.156
(3712000, 9, 7, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 11, 71310, 0, 0, 0, 0, 0, 19, 38191, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Cast Pull Shadows Edge'), -- 23:46:25.094 
(3712000, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 19, 38191, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Set NPC Flags'), -- 23:46:25.094 
(3712000, 9, 9, 0, 0, 0, 100, 0, 150, 150, 0, 0, 11, 43671, 0, 0, 0, 0, 0, 19, 38191, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Cast Ride Vehicle'), -- 23:46:25.110 
(3712000, 9, 10, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 71385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Cast Mograine Axe Timer Aura'), -- 23:46:26.328 
(3712000, 9, 11, 0, 0, 0, 100, 0, 0, 1000, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - Script - Cast Mograine Axe Timer Aura'); -- 23:46:26.328 


DELETE FROM `creature_text` WHERE `entry`in(37120);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(37120, 0, 0, 'So, it has begun....', 12, 0, 100, 396, 0, 16834, 37248, 'Highlord Darion Mograine to Player'),
(37120, 1, 0, 'Behold! The binding of sacred and corrupt; the forging of Shadow''s Edge, a weapon of untold potential!', 12, 0, 100, 0, 0, 16835, 37249, 'Highlord Darion Mograine to Player'),
(37120, 2, 0, 'Bend it to your will, and you shall wield unspeakable power!', 12, 0, 100, 396, 0, 16836, 37250, 'Highlord Darion Mograine to Player'),
(37120, 3, 0, 'Fail, and your soul shall forever be its slave.', 12, 0, 100, 396, 0, 16837, 37251, 'Highlord Darion Mograine to Player');

DELETE FROM `waypoints` WHERE `entry`IN(37120,37801);
INSERT INTO `waypoints`(`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(37120, 1, -67.52431, 2161.191, 30.65416, 'Highlord Darion Mograine'),
(37120, 2, -69.84028, 2155.585, 30.65416, 'Highlord Darion Mograine'),
(37801, 1, -62.15451, 2157.793, 31.59859, 'Shadows Edge Bunny'),
(37801, 2, -69.53472, 2159.691, 31.79306, 'Shadows Edge Bunny');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`IN(5650);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 5650, 2, 0, 9, 0, 24545, 0, 0, 0, 0, 0, '', 'Trigger only activates if player is on and has not completed The Sacred and the Corrupt'),
(22, 1, 5650, 2, 0, 2, 0, 49869, 1, 0, 1, 0, 0, '', 'Trigger does not activate if player already has lights vengence');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(70529,71310,70471);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 70529, 0, 0, 31, 0, 3, 38191, 0, 0, 0, 0, '', 'Summon Shadows Edge Axe targets Shadows Edge'),
(13, 3, 71310, 0, 0, 31, 0, 3, 38191, 0, 0, 0, 0, '', 'Pull Shadows Edge targets Shadows Edge'),
(13, 3, 70471, 0, 0, 31, 0, 3, 37702, 0, 0, 0, 0, '', ' Mograine Forge Beam targets Runeforge Bunny');

UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE`entry` IN(201742);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(201742) AND `source_type`=1;

INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(201742,1,0,0,20,0,100,0,24545,0,0,0,45,1,1,0,0,0,0,19,37120,0,0,0,0,0,0,"RuneForge - On Quest Reward (the Sacred and the Corrupt) - Set Data 1 1 on Highlord Darion Mograine");
