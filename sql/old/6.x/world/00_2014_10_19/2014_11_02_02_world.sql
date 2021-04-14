UPDATE `smart_scripts` SET `action_param2`=0 WHERE `action_type`=28 and `action_param2`>0;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry` IN(30894,31049);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(30894,31049) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30894, 0, 0, 1, 8, 0, 100, 0, 58151, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Spellhit (Subdued Lithe Stalker) - Store Targetlist'),
(30894, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Spellhit (Subdued Lithe Stalker) - Follow Target'),
(30894, 0, 2, 3, 8, 0, 100, 0, 58178, 0, 0, 0, 33, 31049, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Spellhit (CSA Dummy Effect) - Give Kill Credit'),
(30894, 0, 3, 0, 61, 0, 100, 0, 58178, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Spellhit (CSA Dummy Effect) - Despawn'),
(31049, 0, 0, 0, 1, 0, 100, 0, 0, 0, 1000, 1000, 11, 58178, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Geist Return Bunny - OOC - Cast CSA Dummy Effect (25 yards)');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=30894;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 4, 30894, 0, 0, 1, 1, 58151, 0, 0, 0, 0, 0, '', 'Only run AI if Lithe Stalker has Aura (Subdued Lithe Stalker)');
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=193424;
DELETE FROM `smart_scripts` WHERE `entryorguid`=193424 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(193424, 1, 0, 1, 62, 0, 100, 0, 10111, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eye of Dominion - On Gossip Option 0 Selected - Close Gossip'),
(193424, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 85, 58106, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eye of Dominion - On Gossip Option 0 Selected - Invoker Cast Forcecast: Control Lithe Stalker'),
(193424, 1, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 58037, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eye of Dominion - On Gossip Option 0 Selected - Invoker Cast Control Lithe Stalker');
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry` =30895;
DELETE FROM `smart_scripts` WHERE `entryorguid` =30895 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30895, 0, 0, 0, 27, 0, 100, 1, 0, 0, 0, 0, 11, 58117, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Passenger Boarded - Cast Force Reaction: Scourge'),
(30895, 0, 1, 0, 28, 0, 100, 1, 0, 0, 0, 0, 28, 58117, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lithe Stalker - On Passenger Removed - Remove Aura Force Reaction: Scourge');
UPDATE `creature_template` SET `spell1`=57882, `spell2`=58203, `spell3`=58282, `spell4`=58283 WHERE `entry`=30895;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=29717 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(31119,30952,30951,31131,30951);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(31110,31119,30952,3095200,31131,3113100,30951);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31110, 0, 0, 0, 54, 0, 100, 1, 0, 0, 0, 0, 11, 58548, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eidolon Watcher - On Just Summoned - Cast Ethereal'),
(31110, 0, 1, 0, 27, 0, 100, 1, 0, 0, 0, 0, 11, 58548, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eidolon Watcher - On Passenger Boarded - Cast Ethereal'),
(31110, 0, 2, 0, 28, 0, 100, 1, 0, 0, 0, 0, 28, 58548, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eidolon Watcher - On Passenger Removed - Remove Ethereal'),
(31110, 0, 3, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 58548, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eidolon Watcher - On Reset - Cast Ethereal'),
(31119, 0, 0, 1, 54, 0, 100, 1, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bloody Meat - On Just Summoned - Store Targetlist'),
(31119, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 30952, 0, 0, 0, 0, 0, 0, 'Bloody Meat - On Just Summoned - Set Data on Hungering Plaguehound'),
(31119, 0, 2, 3, 38, 0, 100, 1, 1, 1, 0, 0, 11, 58564, 2, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Bloody Meat - On Data Set - Give Kill Credit'),
(31119, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloody Meat - On Data Set - Despawn'),
(30952, 0, 0, 0, 75, 0, 100, 0, 0, 31119, 20, 15000, 80, 3095200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - On Bloody Meat within 20 yards - Run Script'),
(30951, 0, 0, 0, 8, 0, 100, 0, 45254, 0, 0, 0, 33, 30951, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Restless Lookout - On Spellhit - Killcredit'),
(31131, 0, 0, 0, 8, 0, 100, 0, 58662, 0, 300000, 300000, 80, 3113100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Containment Crystal - On Spellhit - Run Script'),
(3113100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 31131, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Containment Crystal - Script - Kill Credit'),
(3113100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Containment Crystal - Script - Set Bytes 1'),
(3113100, 9, 2, 0, 0, 0, 100, 0, 300000, 300000, 0, 0, 91, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Containment Crystal - Script - Remove Bytes 1'),
(3095200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 89, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script - Disable Random Move'),
(3095200, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 19, 31119, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script - Move to Bloodymeat'),
(3095200, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 31119, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script - Move to Bloodymeat'),
(3095200, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script - Evade'),
(3095200, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script - Enable Random Move');
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`IN(-58563);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-58563, 45254, 0,'Assasinate Restless Lookout triggers Suicide');
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
(30920, 0, 2, 3, 61, 0, 100, 1, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 31075, 0, 0, 0, 0, 0, 0, 'Lumbering Atrocity - On Scourge Bomb within 5 yards - Set Data 1 1 on Scourge Bomb'),
(30920, 0, 3, 4, 61, 0, 100, 1, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 30895, 0, 0, 0, 0, 0, 0, 'Lumbering Atrocity - On Scourge Bomb within 5 yards - Set Data 2 2 on Lithstalker'),
(30920, 0, 4, 0, 61, 0, 100, 1, 0, 0, 0, 0, 80, 3092000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lumbering Atrocity - On Scourge Bomb within 5 yards - Run Script'),
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
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN(10111,10028);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 10111, 0, 0, 0, 9, 0, 13145, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken The Vile Hold (13145)'),
(15, 10111, 0, 0, 1, 9, 0, 13146, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken Generosity Abounds (13146)'),
(15, 10111, 0, 0, 2, 9, 0, 13147, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken Matchmaker (13147)'),
(15, 10111, 0, 0, 3, 9, 0, 13147, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken Stunning View (13160)'),
(15, 10028, 0, 0, 0, 9, 0, 13168, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken Parting Gifts (13168)'),
(15, 10028, 0, 0, 1, 9, 0, 13169, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken An Undeads Best Friend (13169)'),
(15, 10028, 0, 0, 2, 9, 0, 13171, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken From Whence They Came (13171)'),
(15, 10028, 0, 0, 3, 9, 0, 13170, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken Honor is for the Weak (13170)');
