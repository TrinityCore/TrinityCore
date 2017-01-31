-- 12180   The Captive Prospectors
UPDATE `smart_scripts` SET `link`=1 WHERE  `entryorguid`IN(27113,27114,27115) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(27113,27114,27115) AND  `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27113,0,1,0,61,0,100,0,0,0,0,0,33,27113,0,0,0,0,0,7,0,0,0,0,0,0,0,'Prospector Gann - On Spell Hit - Give Kill Credit'),
(27114,0,1,0,61,0,100,0,0,0,0,0,33,27114,0,0,0,0,0,7,0,0,0,0,0,0,0,'Prospector Torgan - On Spell Hit - Give Kill Credit'),
(27115,0,1,0,61,0,100,0,0,0,0,0,33,27115,0,0,0,0,0,7,0,0,0,0,0,0,0,'Prospector Veranna - On Spell Hit - Give Kill Credit');

-- [11150] Raze Direhorn Post!
-- [11205] Raze Direhorn Post!
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(23751,23752,23753);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23751,23752,23753);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23751, 0, 0, 0, 8,  0, 100, 0, 42356, 0, 0, 0, 33, 23751   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'North Tent - On Spellhit - Kill Credit'),
(23752, 0, 0, 0, 8,  0, 100, 0, 42356, 0, 0, 0, 33, 23752   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Northeast Tent - On Spellhit - Kill Credit'),
(23753, 0, 0, 0, 8,  0, 100, 0, 42356, 0, 0, 0, 33, 23753   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'East Tent - On Spellhit - Kill Credit');
-- Know Your Ley Lines [11547]
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (25156,25154,25157);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25156,25154,25157) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25156,0,0,0,8,0,100,0,45191,0,0,0,33,25156,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sunwell - Quest Bunny - Portal - On Spell Hit(Sample Ley Line Field) - Give Quest Credit'),
(25154,0,0,0,8,0,100,0,45191,0,0,0,33,25154,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sunwell - Quest Bunny - Shrine - On Spell Hit(Sample Ley Line Field) - Give Quest Credit'),
(25157,0,0,0,8,0,100,0,45191,0,0,0,33,25157,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sunwell - Quest Bunny - Sunwell - On Spell Hit(Sample Ley Line Field) - Give Quest Credit');
