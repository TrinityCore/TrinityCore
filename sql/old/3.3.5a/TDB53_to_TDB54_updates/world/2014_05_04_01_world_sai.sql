--
DELETE FROM `smart_scripts` WHERE `entryorguid`=39712 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39712,0,0,1,38,0,100,0,1,1,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Tinker Mekkatorque - On Data Set 1 1 - Despawn In 1000 ms'),
(39712,0,1,0,61,0,100,0,0,0,0,0,11,74154,0,0,0,0,0,23,0,0,0,0,0,0,0,'High Tinker Mekkatorque - Link With Previous - Cast ''Speech Performed'''),
(39712,0,2,3,38,0,100,0,1,2,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Tinker Mekkatorque - On Data Set 1 2 - Despawn In 1000 ms'),
(39712,0,3,0,61,0,100,0,0,0,0,0,11,74155,0,0,0,0,0,23,0,0,0,0,0,0,0,'High Tinker Mekkatorque - Link With Previous - Cast ''Speech Performed'''),
(39712,0,4,5,38,0,100,0,1,3,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Tinker Mekkatorque - On Data Set 1 3 - Despawn In 1000 ms'),
(39712,0,5,0,61,0,100,0,0,0,0,0,11,74156,0,0,0,0,0,23,0,0,0,0,0,0,0,'High Tinker Mekkatorque - Link With Previous - Cast ''Speech Performed''');

DELETE FROM `smart_scripts` WHERE `entryorguid`=1268 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1268,0,0,0,8,0,100,0,74222,0,0,0,1,2,2000,0,0,0,0,11,39712,10,0,0,0,0,0,'Ozzie Togglevolt - On Spellhit ''Perform Speech'' - Say Line 2'),
(1268,0,1,0,52,0,100,0,2,39712,0,0,1,3,4000,0,0,0,0,11,39712,10,0,0,0,0,0,'Ozzie Togglevolt - On Text 2 Over - Say Line 3'),
(1268,0,2,0,52,0,100,0,3,39712,0,0,1,4,4000,0,0,0,0,11,39712,10,0,0,0,0,0,'Ozzie Togglevolt - On Text 3 Over - Say Line 4'),
(1268,0,3,4,52,0,100,0,4,39712,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ozzie Togglevolt - On Text 4 Over - Say Line 0'),
(1268,0,4,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,39712,10,0,0,0,0,0,'Ozzie Togglevolt - On Text 4 Over - Set Data 1 1');

DELETE FROM `smart_scripts` WHERE `entryorguid`=6119 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6119,0,0,0,8,0,100,0,74222,0,0,0,1,5,2000,0,0,0,0,11,39712,10,0,0,0,0,0,'Tog Rustsprocket - On Spellhit ''Perform Speech'' - Say Line 5'),
(6119,0,1,0,52,0,100,0,5,39712,0,0,1,6,4000,0,0,0,0,11,39712,10,0,0,0,0,0,'Tog Rustsprocket - On Text 5 Over - Say Line 6'),
(6119,0,2,0,52,0,100,0,6,39712,0,0,1,7,4000,0,0,0,0,11,39712,10,0,0,0,0,0,'Tog Rustsprocket - On Text 6 Over - Say Line 7'),
(6119,0,3,4,52,0,100,0,7,39712,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tog Rustsprocket - On Text 7 Over - Say Line 0'),
(6119,0,4,0,61,0,100,0,0,0,0,0,45,1,3,0,0,0,0,11,39712,10,0,0,0,0,0,'Tog Rustsprocket - On Text 7 Over - Set Data 1 3');

DELETE FROM `smart_scripts` WHERE `entryorguid`=7955 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7955,0,0,0,8,0,100,0,74222,0,0,0,1,0,2000,0,0,0,0,11,39712,10,0,0,0,0,0,'Milli Featherwhistle - On Spellhit ''Perform Speech'' - Say Line 0 (Phase 1) (No Repeat)'),
(7955,0,1,0,52,0,100,0,0,39712,0,0,1,1,4000,0,0,0,0,11,39712,10,0,0,0,0,0,'Milli Featherwhistle - On Text 0 Over - Say Line 1 (Phase 1) (No Repeat)'),
(7955,0,2,3,52,0,100,0,1,39712,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Milli Featherwhistle - On Text 1 Over - Say Line 0'),
(7955,0,3,0,61,0,100,0,0,0,0,0,45,1,2,0,0,0,0,11,39712,10,0,0,0,0,0,'Milli Featherwhistle - On Text 1 Over - Set Data 1 2');
