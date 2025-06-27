DELETE FROM `smart_scripts` WHERE `entryorguid`=30922 AND `source_type`=0 AND `id` IN(3,4,5,6);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(30922, 0, 3, 4, 8, 0, 100, 0, 58283, 0, 120000, 120000, 11, 52353, 0, 0, 0, 0, 0, 19, 30895, 0, 0, 0, 0, 0, 0, 'Umbral Brute - On Spellhit (Throw Rock) - Cast Script Effect - Creature Capture GUID to Dot Variable'),
(30922, 0, 4, 5,61, 0, 100, 0, 0, 0, 0, 0, 11, 56685, 0, 0, 0, 0, 0, 19, 30921, 0, 0, 0, 0, 0, 0, 'Umbral Brute - On Spellhit (Throw Rock) - Cast CSA Dummy Effect 1'),
(30922, 0, 5, 6,61, 0, 100, 0, 0, 0, 0, 0, 11, 59120, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Umbral Brute - On Spellhit (Throw Rock) - Cast Scourge Fight Kill Credit'),
(30922, 0, 6, 0,61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 30895, 0, 0, 0, 0, 0, 0, 'Umbral Brute - On Spellhit (Throw Rock) - Set Data 1 1 - Lithe Stalker');

DELETE FROM `smart_scripts` WHERE `entryorguid`=30895 AND `source_type`=0 AND `id` IN(2,3,4,5);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(30895, 0, 2, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 59129, 2, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Data Set 1 1 - Cast Scourge Fight Kill Credit For Real'),
(30895, 0, 3, 4, 38, 0, 100, 0, 2, 2, 0, 0, 11, 59098, 2, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Data Set 2 2 - Cast Scourge Bomb Kill Credit'),
(30895, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 58203, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Data Set 2 2 - Remove Iron chain'),
(30895, 0, 5, 0, 38, 0, 100, 0, 3, 3, 0, 0, 11, 59137, 2, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Data Set 3 3 - Cast Gargoyle Kill Credit');

UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry` =31075;
DELETE FROM `smart_scripts` WHERE `entryorguid` =31075 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =3107500 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(31075, 0, 0, 0, 8, 0, 100, 0, 58203, 0, 30000, 30000, 29, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Scourge Bomb - On Spell Hit (Iron Chain) - Follow Lith Stalker'),
(31075, 0, 1, 0, 34, 0, 100, 0, 0, 0, 0, 0, 11, 58206, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scourge Bomb - On Movement Inform - Cast Scourge Bomb Dragging Aura'),
(31075, 0, 2, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 3107500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scourge Bomb - On Data Set 1 1 - Run Script'),
(31075, 0, 3, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scourge Bomb - OOC - Set Home Position'),
(3107500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 59078, 0, 0, 0, 0, 0, 19, 30920, 0, 0, 0, 0, 0, 0, 'Scourge Bomb - Script - Cast Scourge Bomb Explosion'),
(3107500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scourge Bomb - Script - Despawn');

DELETE FROM `smart_scripts` WHERE `entryorguid`=30920 AND `source_type`=0 AND `id` >0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =3092000 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(30920, 0, 1, 2, 75, 0, 100, 1, 0, 31075, 5, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lumbering Atrocity - On Scourge Bomb within 5 yards - say'),
(30920, 0, 2, 3, 61, 0, 100, 1, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 31075, 0, 0, 0, 0, 0, 0, 'Lumbering Atrocity - On Scourge Bomb within 5 yards -  Set Data 1 1 on Scourge Bomb'),
(30920, 0, 3, 4, 61, 0, 100, 1, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 30895, 0, 0, 0, 0, 0, 0, 'Lumbering Atrocity - On Scourge Bomb within 5 yards -  Set Data 2 2 on Lithstalker'),
(30920, 0, 4, 0, 61, 0, 100, 1, 0, 0, 0, 0, 80, 3092000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lumbering Atrocity - On Scourge Bomb within 5 yards -  Run Script'),

(3092000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 52593, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lumbering Atrocity - Script - Cast Bloated Abomination Feign Death'),
(3092000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 52516, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lumbering Atrocity - Script - Cast Burst at the Seams:Bone'),
(3092000, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 52520, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lumbering Atrocity - Script - Cast Explode Abomination:Meat'),
(3092000, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 52523, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lumbering Atrocity - Script - Cast Explode Abomination:Bloody Meat'),
(3092000, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 58231, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lumbering Atrocity - Script - Cast Exploding Abomination'),
(3092000, 9, 5, 0, 0, 0, 100, 0, 400, 400, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lumbering Atrocity - Script - Despawn');

DELETE FROM `creature_text` WHERE `entry`=30920;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(30920, 0, 0, 'What little geist want?', 12, 0, 100, 0, 0, 0, 'Lumbering Atrocity',31614),
(30920, 0, 1, 'Present?', 12, 0, 100, 0, 0, 0, 'Lumbering Atrocity',31609),
(30920, 0, 2, 'That not nice!', 12, 0, 100, 0, 0, 0, 'Lumbering Atrocity',31615),
(30920, 0, 3, 'What bomb thing for?', 12, 0, 100, 0, 0, 0, 'Lumbering Atrocity',31610),
(30920, 0, 4, 'Want me to deliver somewhere?', 12, 0, 100, 0, 0, 0, 'Lumbering Atrocity',31611),
(30920, 0, 5, 'I not sure this safe, little geist.', 12, 0, 100, 0, 0, 0, 'Lumbering Atrocity',31612),
(30920, 0, 6, 'This no go here.', 12, 0, 100, 0, 0, 0, 'Lumbering Atrocity',31613),
(30920, 0, 7, 'For me?', 12, 0, 100, 0, 0, 0, 'Lumbering Atrocity',31608);

UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry` =31012;
DELETE FROM `smart_scripts` WHERE `entryorguid` =31012 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(31012, 0, 0, 1, 8, 0, 100, 1, 58282, 0, 0, 0, 11, 58285, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Iceskin Sentry - On Spellhiy - Cast Gargoyle Explosion'),
(31012, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 30895, 0, 0, 0, 0, 0, 0, 'Iceskin Sentry - On Spellhiy - Set Data 3 3 on Lithe Stalker');
