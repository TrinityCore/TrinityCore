-- 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry` IN (29519, 29520, 29565, 29566, 29567);
DELETE FROM `creature_addon`  WHERE `guid` IN (128740);

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN (54612);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0, 54612, 64, '', '', 'Chained Peasant (Chest) LOS');

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gift_of_the_harvester';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(52479,'spell_gift_of_the_harvester');

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=52479;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0,52479,64,'','','Gift of the Harvester (LOS)');

UPDATE `creature_template_movement` SET `Ground`= 1, `Flight`= 1 WHERE `CreatureId` IN (29047, 28864);

-- Scarlet Ghoul
DELETE FROM `creature_text` WHERE `CreatureID`=28845;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(28845,0,0,'So hungry...',12,0,100,0,0,0,28955,0,'Scarlet Ghoul'),
(28845,0,1,'Must feed...',12,0,100,0,0,0,28956,0,'Scarlet Ghoul'),
(28845,0,2,'GIVE ME BRAINS!',12,0,100,0,0,0,28957,0,'Scarlet Ghoul'),
(28845,0,3,'Smell flesh... close...',12,0,100,0,0,0,28958,0,'Scarlet Ghoul'),
(28845,0,4,'Mommy?',12,0,100,0,0,0,28959,0,'Scarlet Ghoul'),
(28845,0,5,'$g Poppy:Mama;!',12,0,100,0,0,0,28960,0,'Scarlet Ghoul');

-- Scarlet Ghost
DELETE FROM `creature_text` WHERE `CreatureID`=28846;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(28846,0,0,'Vengeance is mine!',12,0,100,0,0,0,28969,0,'Scarlet Ghost'),
(28846,0,1,'I\'ll take you with me!',12,0,100,0,0,0,28964,0,'Scarlet Ghost'),
(28846,0,2,'The grave calls to us all!',12,0,100,0,0,0,28966,0,'Scarlet Ghost'),
(28846,0,3,'Die, Scourge filth!',12,0,100,0,0,0,28968,0,'Scarlet Ghost'),
(28846,0,4,'YOU KILLED ME!',12,0,100,0,0,0,28967,0,'Scarlet Ghost');

UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=28846;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28846 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(28846,0,0,0,54,0,50,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"Scarlet Ghost - On Just Appeared -Say Line 0");


-- Inconspicuous Mine Car
UPDATE `gameobject` SET `position_x`=2391.736,`position_y`=-5898.792,`position_z`=109.3904,`orientation`=0.6981314,`rotation3`=0.9396927 WHERE `guid`=65890 AND `id`=190767;
-- Mine Car
UPDATE `creature_template` SET `minlevel`=56,`maxlevel`=56 WHERE `entry` = 28817;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=28817;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=28817;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28817,0,0,0,54,0,100,0,0,0,0,0,0,3,0,25703,0,0,0,0,1,0,0,0,0,0,0,0,'Mine Car - On spawned - Set model'),
(28817,0,1,0,27,0,100,0,0,0,0,0,0,11,52464,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mine Car - On passenger boarded - Cast spell \'Summon Scarlet Miner\''),
(28817,0,2,0,8,0,100,1,52595,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Mine Car - On spell hit - Set follow'),
(28817,0,3,0,28,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,19,28841,9,0,0,0,0,0,'Mine Car - On passenger removed - Despawn \'Scarlet Miner\'');
-- Summon Scarlet Miner
UPDATE `spell_target_position` SET `PositionX`=2384.13,`PositionY`=-5900.07,`PositionZ`=108.0813 WHERE `ID`=52464;
UPDATE `spell_target_position` SET `PositionX`=2389.58,`PositionY`=-5901.18,`PositionZ`=108.9380 WHERE `ID`=52462;

-- Scarlet Miner
DELETE FROM `waypoints` WHERE `entry` IN (2884100,2884101);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(2884100,1, 2376.892, -5906.246, 108.5153,'Scarlet Miner'),
(2884100,2, 2354.759, -5905.348, 104.9017,'Scarlet Miner'),
(2884100,3, 2331.889, -5903.588, 100.0160,'Scarlet Miner'),
(2884100,4, 2308.977, -5905.764, 90.91159,'Scarlet Miner'),
(2884100,5, 2298.572, -5914.677, 84.70060,'Scarlet Miner'),
(2884100,6, 2291.055, -5934.960, 70.15641,'Scarlet Miner'),
(2884100,7, 2282.350, -5954.375, 57.76657,'Scarlet Miner'),
(2884100,8, 2275.099, -5964.198, 51.61853,'Scarlet Miner'),
(2884100,9, 2260.797, -5972.555, 43.49573,'Scarlet Miner'),
(2884100,10, 2245.771, -5980.806, 34.91277,'Scarlet Miner'),
(2884100,11, 2236.629, -5991.123, 29.03914,'Scarlet Miner'),
(2884100,12, 2197.551, -6068.021, 4.954395,'Scarlet Miner'),
(2884100,13, 2183.802, -6092.537, 1.664639,'Scarlet Miner'),
(2884100,14, 2178.071, -6118.517, 1.298641,'Scarlet Miner'),
(2884100,15, 2173.443, -6140.669, 1.102578,'Scarlet Miner'),
(2884100,16, 2167.344, -6150.516, 1.348482,'Scarlet Miner'),
(2884100,17, 2156.898, -6155.389, 1.925997,'Scarlet Miner'),
(2884100,18, 2141.903, -6161.750, 1.179094,'Scarlet Miner'),
(2884100,19, 2137.161, -6163.067, 1.066367,'Scarlet Miner'),
(2884100,20, 2131.983, -6170.813, 2.067344,'Scarlet Miner'),
(2884100,21, 2126.371, -6179.504, 8.487098,'Scarlet Miner'),
(2884100,22, 2122.159, -6186.258, 13.99542,'Scarlet Miner'),
(2884100,23, 2115.892, -6196.246, 13.67582,'Scarlet Miner'),
(2884101,1, 2376.892, -5906.246, 108.515,'Scarlet Miner'),
(2884101,2, 2354.759, -5905.348, 104.901,'Scarlet Miner'),
(2884101,3, 2331.889, -5903.588, 100.016,'Scarlet Miner'),
(2884101,4, 2308.977, -5905.764, 90.9115,'Scarlet Miner'),
(2884101,5, 2298.572, -5914.677, 84.7006,'Scarlet Miner'),
(2884101,6, 2291.055, -5934.960, 70.1564,'Scarlet Miner'),
(2884101,7, 2282.350, -5954.375, 57.7665,'Scarlet Miner'),
(2884101,8, 2275.099, -5964.198, 51.6185,'Scarlet Miner'),
(2884101,9, 2260.797, -5972.555, 43.4957,'Scarlet Miner'),
(2884101,10, 2245.771, -5980.806, 34.9127,'Scarlet Miner'),
(2884101,11, 2236.629, -5991.123, 29.0391,'Scarlet Miner'),
(2884101,12, 2197.551, -6068.021, 4.95439,'Scarlet Miner'),
(2884101,13, 2183.802, -6092.537, 1.66463,'Scarlet Miner'),
(2884101,14, 2178.071, -6118.517, 1.29864,'Scarlet Miner'),
(2884101,15, 2173.443, -6140.669, 1.10257,'Scarlet Miner'),
(2884101,16, 2176.981, -6153.453, 1.64646,'Scarlet Miner'),
(2884101,17, 2185.705, -6165.262, 1.09934,'Scarlet Miner'),
(2884101,18, 2199.173, -6167.276, 1.05963,'Scarlet Miner'),
(2884101,19, 2220.801, -6165.641, 1.25961,'Scarlet Miner'),
(2884101,20, 2250.129, -6162.287, 0.91468,'Scarlet Miner'),
(2884101,21, 2262.414, -6163.124, 1.49738,'Scarlet Miner'),
(2884101,22, 2268.944, -6167.533, 1.26519,'Scarlet Miner'),
(2884101,23, 2269.859, -6174.558, 5.10841,'Scarlet Miner'),
(2884101,24, 2270.228, -6180.257, 8.81259,'Scarlet Miner'),
(2884101,25, 2270.822, -6184.768, 12.4218,'Scarlet Miner'),
(2884101,26, 2271.095, -6187.314, 13.9912,'Scarlet Miner'),
(2884101,27, 2273.838, -6196.402, 13.65775,'Scarlet Miner');

UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=28841;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=28841;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (2884100,2884101,2884102);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28841,0,0,1,54,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Miner - On just summoned - Set Run off'),
(28841,0,1,0,61,0,100,0,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,2386.673,-5900.587,108.5761,0,'Scarlet Miner - On just summoned - Move'),
(28841,0,2,3,34,0,100,0,8,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,'Scarlet Miner - On movement inform - Set orientation'),
(28841,0,3,4,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Miner - Linked event - Say line 0'),
(28841,0,4,0,61,0,100,0,0,0,0,0,0,87,2884100,2884101,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Miner - Linked event - Random action list'),
(28841,0,5,0,58,0,100,0,0,0,0,0,0,80,2884102,0,1,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Miner - On WP ended - Action list 2'),
(2884100,9,0,0,0,0,100,0,4000,4000,0,0,0,11,52595,0,0,0,0,0,23,0,0,0,0,0,0,0,'Scarlet Miner - Action list 0 - Cast spell \'Drag Mine Cart\''),
(2884100,9,1,0,61,0,100,0,0,0,0,0,0,53,1,2884100,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Miner - Action list 0 - Start WP'),
(2884101,9,0,0,0,0,100,0,4000,4000,0,0,0,11,52595,0,0,0,0,0,23,0,0,0,0,0,0,0,'Scarlet Miner - Action list 1 - Cast spell \'Drag Mine Cart\''),
(2884101,9,1,0,0,0,100,0,0,0,0,0,0,53,1,2884101,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Miner - Action list 1 - Start WP'),
(2884102,9,0,0,0,0,100,0,4000,4000,0,0,0,28,52595,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Miner - Action list 2 - Remove aura'),
(2884102,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,'Scarlet Miner - Action list 2 - Set orientation'),
(2884102,9,2,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Miner - Action list 2 - Say line 1'),
(2884102,9,3,0,0,0,100,0,0,0,0,0,0,41,1000,0,0,0,0,0,23,0,0,0,0,0,0,0,'Scarlet Miner - Action list 2 - Despawn \'Mine Car\''),
(2884102,9,4,0,0,0,100,0,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Miner - Action list 2 - Despawn self');


--
DELETE FROM `creature_text` WHERE `CreatureID` IN (28610,28939,28940,28936);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
-- Players line
(28610,0,0,'What is the \"Crimson Dawn?\"',12,0,100,0,0,0,29133,0,'Scarlet Marksman'),
(28610,0,1,'Tell me what you know about \"Crimson Dawn\" or the beatings will continue!''',12,0,100,0,0,0,29134,0,'Scarlet Marksman'),
(28610,0,2,'I''m through being courteous with your kind, human! What is the \"Crimson Dawn?\"',12,0,100,0,0,0,29135,0,'Scarlet Marksman'),
(28610,0,3,'\"Crimson Dawn!\" What is it! Speak!',12,0,100,0,0,0,29136,0,'Scarlet Marksman'),
(28610,0,4,'I can keep this up for a very long time, Scarlet dog! Tell me about the \"Crimson Dawn!\"',12,0,100,0,0,0,29137,0,'Scarlet Marksman'),
(28610,0,5,'I''ll tear the secrets from your soul! Tell me about the \"Crimson Dawn\" and your life may be spared!',12,0,100,0,0,0,29138,0,'Scarlet Marksman'),
(28610,0,6,'Is your life worth so little? Just tell me what I need to know about \"Crimson Dawn\" and I''ll end your suffering quickly.',12,0,100,0,0,0,29139,0,'Scarlet Marksman'),
(28610,0,7,'I grow tired of these games, human. Tell me of the \"Crimson Dawn\" or I will tear your spine out with my bare hands!',12,0,100,0,0,0,29140,0,'Scarlet Marksman'),
-- npc resist line
(28610,1,0,"I'll tell you nothing, Scourge filth!",12,0,100,0,0,0,29141,0,'Scarlet Marksman'),
(28610,1,1,'You''''ll have to kill me, monster. I will tell you NOTHING!',12,0,100,0,0,0,29142,0,'Scarlet Marksman'),
(28610,1,2,'Argh... The pain... The pain is almost as unbearable as the lashings I received in grammar school when I was but a child.',12,0,100,0,0,0,29143,0,'Scarlet Marksman'),
(28610,1,3,"You... You'll get nothing... And like it...",12,0,100,0,0,0,29144,0,'Scarlet Marksman'),
(28610,1,4,"Do you think this to be pain? To be suffering? HAH! Destroy this mortal shell so that I may ascend to the heavens!",12,0,100,0,0,0,29145,0,'Scarlet Marksman'),
(28610,1,5,'You hit like a girl. Honestly. Is that the best you can do?',12,0,100,0,0,0,29146,0,'Scarlet Marksman'),
(28610,1,6,"The crimson what? Never heard of it...",12,0,100,0,0,0,29147,0,'Scarlet Marksman'),
(28610,1,7,"The pain is momentary. It pales in comparison to what the High General would do to me...",12,0,100,0,0,0,29148,0,'Scarlet Marksman'),
(28610,1,8,"You know nothing of pain, monster!",12,0,100,0,0,0,29155,0,'Scarlet Marksman'),
(28610,1,9,"HAH! I've survived three separate inquisitions! This is nothing in comparison!",12,0,100,0,0,0,29156,0,'Scarlet Marksman'),
(28610,1,10,"Look out! There's a bee loose and it's on a stinging rampage!",12,0,100,0,0,0,29157,0,'Scarlet Marksman'),
(28610,1,11,"That one tickled...",12,0,100,0,0,0,29158,0,'Scarlet Marksman'),
(28610,1,12,"I'm going to send you back to the Lich King in pieces!",12,0,100,0,0,0,29159,0,'Scarlet Marksman'),
(28610,1,13,'You''ll be hanging in the gallows shortly, Scourge fiend!',12,0,100,0,0,0,29160,0,'Scarlet Marksman'),
(28610,1,14,'I used to work for Grand Inquisitor Isillien! Your idea of pain is a normal mid-afternoon for me!',12,0,100,0,0,0,29161,0,'Scarlet Marksman'),
(28610,1,15,'ARGH! You burned my last good tabard!',12,0,100,0,0,0,29162,0,'Scarlet Marksman'),
-- torture success
(28610,2,0,"I'll tell you everything! STOP! PLEASE!",12,0,100,20,0,0,29149,0,'Scarlet Marksman'),
(28610,3,0,'We... We have only been told that the \"Crimson Dawn\" is an awakening. You... You see, the Light speaks to the High General. It is the Light...',12,0,100,1,0,0,29150,0,'Scarlet Marksman'),
(28610,4,0,'The Light that guides us. This movement was set in motion before you came... We... We do as we are told. It is what must be done.',12,0,100,1,0,0,29151,0,'Scarlet Marksman'),
(28610,5,0,'I know very litte else... The High General chooses who may go and who must stay behind. There''''s nothing else... You must believe me!',12,0,100,1,0,0,29152,0,'Scarlet Marksman'),
(28610,6,0,'LIES! The pain you are about to endure will be talked about for years to come!',12,0,100,0,0,0,29163,0,'Scarlet Marksman'),
(28610,7,0,'NO! PLEASE! There is one more thing that I forgot to mention... A courier comes soon... From Hearthglen. It...',12,0,100,431,0,0,29153,0,'Scarlet Marksman'),
(28610,8,0,'%s dies from the torture.',16,0,100,0,0,0,29154,0,'Scarlet Marksman'),
-- aggro
(28610,9,0,"Scourge filth! DIE!, Scourge filth! DIE!",12,0,100,0,0,0,28597,0,'Scarlet Marksman'),
(28610,9,1,"The Crusade will be victorious!, The Crusade will be victorious!",12,0,100,0,0,0,28598,0,'Scarlet Marksman'),
(28610,9,2,"I will present your head to Abbendis myself!",12,0,100,0,0,0,28599,0,'Scarlet Marksman'),
(28610,9,3,"You're not welcome in these lands, monster!",12,0,100,0,0,0,28600,0,'Scarlet Marksman'),
(28610,9,4,"Let the purging begin!, Let the purging begin!",12,0,100,0,0,0,28601,0,'Scarlet Marksman'),
(28610,9,5,"By the Light be cleansed!, By the Light be cleansed!",12,0,100,0,0,0,28602,0,'Scarlet Marksman'),
--
-- Players line
(28939,0,0,'What is the \"Crimson Dawn?\"',12,0,100,0,0,0,29133,0,'Scarlet Preacher'),
(28939,0,1,'Tell me what you know about \"Crimson Dawn\" or the beatings will continue!''',12,0,100,0,0,0,29134,0,'Scarlet Preacher'),
(28939,0,2,'I''m through being courteous with your kind, human! What is the \"Crimson Dawn?\"',12,0,100,0,0,0,29135,0,'Scarlet Preacher'),
(28939,0,3,'\"Crimson Dawn!\" What is it! Speak!',12,0,100,0,0,0,29136,0,'Scarlet Preacher'),
(28939,0,4,'I can keep this up for a very long time, Scarlet dog! Tell me about the \"Crimson Dawn!\"',12,0,100,0,0,0,29137,0,'Scarlet Preacher'),
(28939,0,5,'I''ll tear the secrets from your soul! Tell me about the \"Crimson Dawn\" and your life may be spared!',12,0,100,0,0,0,29138,0,'Scarlet Preacher'),
(28939,0,6,'Is your life worth so little? Just tell me what I need to know about \"Crimson Dawn\" and I''ll end your suffering quickly.',12,0,100,0,0,0,29139,0,'Scarlet Preacher'),
(28939,0,7,'I grow tired of these games, human. Tell me of the \"Crimson Dawn\" or I will tear your spine out with my bare hands!',12,0,100,0,0,0,29140,0,'Scarlet Preacher'),
-- npc resist line
(28939,1,0,"I'll tell you nothing, Scourge filth!",12,0,100,0,0,0,29141,0,'Scarlet Preacher'),
(28939,1,1,'You''''ll have to kill me, monster. I will tell you NOTHING!',12,0,100,0,0,0,29142,0,'Scarlet Preacher'),
(28939,1,2,'Argh... The pain... The pain is almost as unbearable as the lashings I received in grammar school when I was but a child.',12,0,100,0,0,0,29143,0,'Scarlet Preacher'),
(28939,1,3,"You... You'll get nothing... And like it...",12,0,100,0,0,0,29144,0,'Scarlet Preacher'),
(28939,1,4,"Do you think this to be pain? To be suffering? HAH! Destroy this mortal shell so that I may ascend to the heavens!",12,0,100,0,0,0,29145,0,'Scarlet Preacher'),
(28939,1,5,'You hit like a girl. Honestly. Is that the best you can do?',12,0,100,0,0,0,29146,0,'Scarlet Preacher'),
(28939,1,6,"The crimson what? Never heard of it...",12,0,100,0,0,0,29147,0,'Scarlet Preacher'),
(28939,1,7,"The pain is momentary. It pales in comparison to what the High General would do to me...",12,0,100,0,0,0,29148,0,'Scarlet Preacher'),
(28939,1,8,"You know nothing of pain, monster!",12,0,100,0,0,0,29155,0,'Scarlet Preacher'),
(28939,1,9,"HAH! I've survived three separate inquisitions! This is nothing in comparison!",12,0,100,0,0,0,29156,0,'Scarlet Preacher'),
(28939,1,10,"Look out! There's a bee loose and it's on a stinging rampage!",12,0,100,0,0,0,29157,0,'Scarlet Preacher'),
(28939,1,11,"That one tickled...",12,0,100,0,0,0,29158,0,'Scarlet Preacher'),
(28939,1,12,"I'm going to send you back to the Lich King in pieces!",12,0,100,0,0,0,29159,0,'Scarlet Preacher'),
(28939,1,13,'You''ll be hanging in the gallows shortly, Scourge fiend!',12,0,100,0,0,0,29160,0,'Scarlet Preacher'),
(28939,1,14,'I used to work for Grand Inquisitor Isillien! Your idea of pain is a normal mid-afternoon for me!',12,0,100,0,0,0,29161,0,'Scarlet Preacher'),
(28939,1,15,'ARGH! You burned my last good tabard!',12,0,100,0,0,0,29162,0,'Scarlet Preacher'),
-- torture success
(28939,2,0,"I'll tell you everything! STOP! PLEASE!",12,0,100,20,0,0,29149,0,'Scarlet Preacher'),
(28939,3,0,'We... We have only been told that the \"Crimson Dawn\" is an awakening. You... You see, the Light speaks to the High General. It is the Light...',12,0,100,1,0,0,29150,0,'Scarlet Preacher'),
(28939,4,0,'The Light that guides us. This movement was set in motion before you came... We... We do as we are told. It is what must be done.',12,0,100,1,0,0,29151,0,'Scarlet Preacher'),
(28939,5,0,'I know very litte else... The High General chooses who may go and who must stay behind. There''''s nothing else... You must believe me!',12,0,100,1,0,0,29152,0,'Scarlet Preacher'),
(28939,6,0,'LIES! The pain you are about to endure will be talked about for years to come!',12,0,100,0,0,0,29163,0,'Scarlet Preacher'),
(28939,7,0,'NO! PLEASE! There is one more thing that I forgot to mention... A courier comes soon... From Hearthglen. It...',12,0,100,431,0,0,29153,0,'Scarlet Preacher'),
(28939,8,0,'%s dies from the torture.',16,0,100,0,0,0,29154,0,'Scarlet Preacher'),
-- aggro
(28939,9,0,"Scourge filth! DIE!, Scourge filth! DIE!",12,0,100,0,0,0,28597,0,'Scarlet Preacher'),
(28939,9,1,"The Crusade will be victorious!, The Crusade will be victorious!",12,0,100,0,0,0,28598,0,'Scarlet Preacher'),
(28939,9,2,"I will present your head to Abbendis myself!",12,0,100,0,0,0,28599,0,'Scarlet Preacher'),
(28939,9,3,"You're not welcome in these lands, monster!",12,0,100,0,0,0,28600,0,'Scarlet Preacher'),
(28939,9,4,"Let the purging begin!, Let the purging begin!",12,0,100,0,0,0,28601,0,'Scarlet Preacher'),
(28939,9,5,"By the Light be cleansed!, By the Light be cleansed!",12,0,100,0,0,0,28602,0,'Scarlet Preacher'),
--
-- Players line
(28940,0,0,'What is the \"Crimson Dawn?\"',12,0,100,0,0,0,29133,0,'Scarlet Crusader'),
(28940,0,1,'Tell me what you know about \"Crimson Dawn\" or the beatings will continue!''',12,0,100,0,0,0,29134,0,'Scarlet Crusader'),
(28940,0,2,'I''m through being courteous with your kind, human! What is the \"Crimson Dawn?\"',12,0,100,0,0,0,29135,0,'Scarlet Crusader'),
(28940,0,3,'\"Crimson Dawn!\" What is it! Speak!',12,0,100,0,0,0,29136,0,'Scarlet Crusader'),
(28940,0,4,'I can keep this up for a very long time, Scarlet dog! Tell me about the \"Crimson Dawn!\"',12,0,100,0,0,0,29137,0,'Scarlet Crusader'),
(28940,0,5,'I''ll tear the secrets from your soul! Tell me about the \"Crimson Dawn\" and your life may be spared!',12,0,100,0,0,0,29138,0,'Scarlet Crusader'),
(28940,0,6,'Is your life worth so little? Just tell me what I need to know about \"Crimson Dawn\" and I''ll end your suffering quickly.',12,0,100,0,0,0,29139,0,'Scarlet Crusader'),
(28940,0,7,'I grow tired of these games, human. Tell me of the \"Crimson Dawn\" or I will tear your spine out with my bare hands!',12,0,100,0,0,0,29140,0,'Scarlet Crusader'),
-- npc resist line
(28940,1,0,"I'll tell you nothing, Scourge filth!",12,0,100,0,0,0,29141,0,'Scarlet Crusader'),
(28940,1,1,'You''''ll have to kill me, monster. I will tell you NOTHING!',12,0,100,0,0,0,29142,0,'Scarlet Crusader'),
(28940,1,2,'Argh... The pain... The pain is almost as unbearable as the lashings I received in grammar school when I was but a child.',12,0,100,0,0,0,29143,0,'Scarlet Crusader'),
(28940,1,3,"You... You'll get nothing... And like it...",12,0,100,0,0,0,29144,0,'Scarlet Crusader'),
(28940,1,4,"Do you think this to be pain? To be suffering? HAH! Destroy this mortal shell so that I may ascend to the heavens!",12,0,100,0,0,0,29145,0,'Scarlet Crusader'),
(28940,1,5,'You hit like a girl. Honestly. Is that the best you can do?',12,0,100,0,0,0,29146,0,'Scarlet Crusader'),
(28940,1,6,"The crimson what? Never heard of it...",12,0,100,0,0,0,29147,0,'Scarlet Crusader'),
(28940,1,7,"The pain is momentary. It pales in comparison to what the High General would do to me...",12,0,100,0,0,0,29148,0,'Scarlet Crusader'),
(28940,1,8,"You know nothing of pain, monster!",12,0,100,0,0,0,29155,0,'Scarlet Crusader'),
(28940,1,9,"HAH! I've survived three separate inquisitions! This is nothing in comparison!",12,0,100,0,0,0,29156,0,'Scarlet Crusader'),
(28940,1,10,"Look out! There's a bee loose and it's on a stinging rampage!",12,0,100,0,0,0,29157,0,'Scarlet Crusader'),
(28940,1,11,"That one tickled...",12,0,100,0,0,0,29158,0,'Scarlet Crusader'),
(28940,1,12,"I'm going to send you back to the Lich King in pieces!",12,0,100,0,0,0,29159,0,'Scarlet Crusader'),
(28940,1,13,'You''ll be hanging in the gallows shortly, Scourge fiend!',12,0,100,0,0,0,29160,0,'Scarlet Crusader'),
(28940,1,14,'I used to work for Grand Inquisitor Isillien! Your idea of pain is a normal mid-afternoon for me!',12,0,100,0,0,0,29161,0,'Scarlet Crusader'),
(28940,1,15,'ARGH! You burned my last good tabard!',12,0,100,0,0,0,29162,0,'Scarlet Crusader'),
-- torture success
(28940,2,0,"I'll tell you everything! STOP! PLEASE!",12,0,100,20,0,0,29149,0,'Scarlet Crusader'),
(28940,3,0,'We... We have only been told that the \"Crimson Dawn\" is an awakening. You... You see, the Light speaks to the High General. It is the Light...',12,0,100,1,0,0,29150,0,'Scarlet Crusader'),
(28940,4,0,'The Light that guides us. This movement was set in motion before you came... We... We do as we are told. It is what must be done.',12,0,100,1,0,0,29151,0,'Scarlet Crusader'),
(28940,5,0,'I know very litte else... The High General chooses who may go and who must stay behind. There''''s nothing else... You must believe me!',12,0,100,1,0,0,29152,0,'Scarlet Crusader'),
(28940,6,0,'LIES! The pain you are about to endure will be talked about for years to come!',12,0,100,0,0,0,29163,0,'Scarlet Crusader'),
(28940,7,0,'NO! PLEASE! There is one more thing that I forgot to mention... A courier comes soon... From Hearthglen. It...',12,0,100,431,0,0,29153,0,'Scarlet Crusader'),
(28940,8,0,'%s dies from the torture.',16,0,100,0,0,0,29154,0,'Scarlet Crusader'),
-- aggro
(28940,9,0,"Scourge filth! DIE!, Scourge filth! DIE!",12,0,100,0,0,0,28597,0,'Scarlet Crusader'),
(28940,9,1,"The Crusade will be victorious!, The Crusade will be victorious!",12,0,100,0,0,0,28598,0,'Scarlet Crusader'),
(28940,9,2,"I will present your head to Abbendis myself!",12,0,100,0,0,0,28599,0,'Scarlet Crusader'),
(28940,9,3,"You're not welcome in these lands, monster!",12,0,100,0,0,0,28600,0,'Scarlet Crusader'),
(28940,9,4,"Let the purging begin!, Let the purging begin!",12,0,100,0,0,0,28601,0,'Scarlet Crusader'),
(28940,9,5,"By the Light be cleansed!, By the Light be cleansed!",12,0,100,0,0,0,28602,0,'Scarlet Crusader'),
--
-- Players line
(28936,0,0,'What is the \"Crimson Dawn?\"',12,0,100,0,0,0,29133,0,'Scarlet Commander'),
(28936,0,1,'Tell me what you know about \"Crimson Dawn\" or the beatings will continue!''',12,0,100,0,0,0,29134,0,'Scarlet Commander'),
(28936,0,2,'I''m through being courteous with your kind, human! What is the \"Crimson Dawn?\"',12,0,100,0,0,0,29135,0,'Scarlet Commander'),
(28936,0,3,'\"Crimson Dawn!\" What is it! Speak!',12,0,100,0,0,0,29136,0,'Scarlet Commander'),
(28936,0,4,'I can keep this up for a very long time, Scarlet dog! Tell me about the \"Crimson Dawn!\"',12,0,100,0,0,0,29137,0,'Scarlet Commander'),
(28936,0,5,'I''ll tear the secrets from your soul! Tell me about the \"Crimson Dawn\" and your life may be spared!',12,0,100,0,0,0,29138,0,'Scarlet Commander'),
(28936,0,6,'Is your life worth so little? Just tell me what I need to know about \"Crimson Dawn\" and I''ll end your suffering quickly.',12,0,100,0,0,0,29139,0,'Scarlet Commander'),
(28936,0,7,'I grow tired of these games, human. Tell me of the \"Crimson Dawn\" or I will tear your spine out with my bare hands!',12,0,100,0,0,0,29140,0,'Scarlet Commander'),
-- npc resist line
(28936,1,0,"I'll tell you nothing, Scourge filth!",12,0,100,0,0,0,29141,0,'Scarlet Commander'),
(28936,1,1,'You''''ll have to kill me, monster. I will tell you NOTHING!',12,0,100,0,0,0,29142,0,'Scarlet Commander'),
(28936,1,2,'Argh... The pain... The pain is almost as unbearable as the lashings I received in grammar school when I was but a child.',12,0,100,0,0,0,29143,0,'Scarlet Commander'),
(28936,1,3,"You... You'll get nothing... And like it...",12,0,100,0,0,0,29144,0,'Scarlet Commander'),
(28936,1,4,"Do you think this to be pain? To be suffering? HAH! Destroy this mortal shell so that I may ascend to the heavens!",12,0,100,0,0,0,29145,0,'Scarlet Commander'),
(28936,1,5,'You hit like a girl. Honestly. Is that the best you can do?',12,0,100,0,0,0,29146,0,'Scarlet Commander'),
(28936,1,6,"The crimson what? Never heard of it...",12,0,100,0,0,0,29147,0,'Scarlet Commander'),
(28936,1,7,"The pain is momentary. It pales in comparison to what the High General would do to me...",12,0,100,0,0,0,29148,0,'Scarlet Commander'),
(28936,1,8,"You know nothing of pain, monster!",12,0,100,0,0,0,29155,0,'Scarlet Commander'),
(28936,1,9,"HAH! I've survived three separate inquisitions! This is nothing in comparison!",12,0,100,0,0,0,29156,0,'Scarlet Commander'),
(28936,1,10,"Look out! There's a bee loose and it's on a stinging rampage!",12,0,100,0,0,0,29157,0,'Scarlet Commander'),
(28936,1,11,"That one tickled...",12,0,100,0,0,0,29158,0,'Scarlet Commander'),
(28936,1,12,"I'm going to send you back to the Lich King in pieces!",12,0,100,0,0,0,29159,0,'Scarlet Commander'),
(28936,1,13,'You''ll be hanging in the gallows shortly, Scourge fiend!',12,0,100,0,0,0,29160,0,'Scarlet Commander'),
(28936,1,14,'I used to work for Grand Inquisitor Isillien! Your idea of pain is a normal mid-afternoon for me!',12,0,100,0,0,0,29161,0,'Scarlet Commander'),
(28936,1,15,'ARGH! You burned my last good tabard!',12,0,100,0,0,0,29162,0,'Scarlet Commander'),
-- torture success
(28936,2,0,"I'll tell you everything! STOP! PLEASE!",12,0,100,20,0,0,29149,0,'Scarlet Commander'),
(28936,3,0,'We... We have only been told that the \"Crimson Dawn\" is an awakening. You... You see, the Light speaks to the High General. It is the Light...',12,0,100,1,0,0,29150,0,'Scarlet Commander'),
(28936,4,0,'The Light that guides us. This movement was set in motion before you came... We... We do as we are told. It is what must be done.',12,0,100,1,0,0,29151,0,'Scarlet Commander'),
(28936,5,0,'I know very litte else... The High General chooses who may go and who must stay behind. There''''s nothing else... You must believe me!',12,0,100,1,0,0,29152,0,'Scarlet Commander'),
(28936,6,0,'LIES! The pain you are about to endure will be talked about for years to come!',12,0,100,0,0,0,29163,0,'Scarlet Commander'),
(28936,7,0,'NO! PLEASE! There is one more thing that I forgot to mention... A courier comes soon... From Hearthglen. It...',12,0,100,431,0,0,29153,0,'Scarlet Commander'),
(28936,8,0,'%s dies from the torture.',16,0,100,0,0,0,29154,0,'Scarlet Commander'),
-- aggro
(28936,9,0,"Scourge filth! DIE!, Scourge filth! DIE!",12,0,100,0,0,0,28597,0,'Scarlet Commander'),
(28936,9,1,"The Crusade will be victorious!, The Crusade will be victorious!",12,0,100,0,0,0,28598,0,'Scarlet Commander'),
(28936,9,2,"I will present your head to Abbendis myself!",12,0,100,0,0,0,28599,0,'Scarlet Commander'),
(28936,9,3,"You're not welcome in these lands, monster!",12,0,100,0,0,0,28600,0,'Scarlet Commander'),
(28936,9,4,"Let the purging begin!, Let the purging begin!",12,0,100,0,0,0,28601,0,'Scarlet Commander'),
(28936,9,5,"By the Light be cleansed!, By the Light be cleansed!",12,0,100,0,0,0,28602,0,'Scarlet Commander');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=52781;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=52805;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,52781,0,0,31,1,3,28610,0,0,27,0,'','Persuasive Strike - Scarlet Marksman'),
(17,0,52781,0,0,9,0,12720,0,0,0,27,0,'','Persuasive Strike - require quest taken'),
(17,0,52781,0,1,31,1,3,28939,0,0,27,0,'','Persuasive Strike - Scarlet Preacher'),
(17,0,52781,0,1,9,0,12720,0,0,0,27,0,'','Persuasive Strike - require quest taken'),
(17,0,52781,0,2,31,1,3,28940,0,0,27,0,'','Persuasive Strike - Scarlet Crusader'),
(17,0,52781,0,2,9,0,12720,0,0,0,27,0,'','Persuasive Strike - require quest taken'),
(17,0,52781,0,3,31,1,3,28936,0,0,27,0,'','Persuasive Strike - Scarlet Commander'),
(17,0,52781,0,3,9,0,12720,0,0,0,27,0,'','Persuasive Strike - require quest taken'),
(13,1,52805,0,0,31,0,3,28610,0,0,0,0,'','Interrogation - Scarlet Marksman'),
(13,1,52805,0,1,31,0,3,28939,0,0,0,0,'','Interrogation - Scarlet Preacher'),
(13,1,52805,0,2,31,0,3,28940,0,0,0,0,'','Interrogation - Scarlet Crusader'),
(13,1,52805,0,3,31,0,3,28936,0,0,0,0,'','Interrogation - Scarlet Commander');

UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry` IN (28610,28939,28940,28936);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28610,28939,28940,28936) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2861000,2861001,2861002) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28610,0,0,0,0,0,100,0,2000,3900,2500,3900,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Scarlet Marksman - IC CMC - Cast shot'),
(28610,0,1,0,0,0,100,0,4000,8000,4000,8000,0,11,32915,0,0,0,0,0,2,0,0,0,0,0,0,0,'Scarlet Marksman - IC - Cast Raptor Strike'),
(28610,0,2,0,0,0,100,0,8000,10000,8000,10000,0,11,18651,64,0,0,0,0,2,0,0,0,0,0,0,0,'Scarlet Marksman - IC - Cast Multi-Shot'),
(28610,0,3,0,8,0,100,0,52781,0,10000,10000,0,87,2861000,2861001,2861000,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Marksman - On spellhit - Random action list'),
(28610,0,4,0,4,0,10,0,0,0,0,0,0,1,9,0,1,0,0,0,7,0,0,0,0,0,0,0,'Scarlet Marksman - On aggro - say text'),
(28610,0,5,0,7,0,100,0,0,0,0,0,0,80,2861002,2,1,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Marksman - On evade - action list'),
(28939,0,0,0,0,0,100,0,2000,3900,2500,3900,0,11,15498,64,0,0,0,0,2,0,0,0,0,0,0,0,'Scarlet Preacher - IC CMC - Cast Holy Smite'),
(28939,0,1,0,0,0,100,0,4000,6000,60000,60000,0,11,34809,1,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Preacher - IC - Cast Holy Fury'),
(28939,0,2,0,0,0,100,0,8000,10000,25000,30000,0,11,19725,0,0,0,0,0,2,0,0,0,0,0,0,0,'Scarlet Preacher - IC - Cast Turn Undead'),
(28939,0,3,0,8,0,100,0,52781,0,10000,10000,0,87,2861000,2861001,2861000,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Preacher - On spellhit - Random action list'),
(28939,0,4,0,4,0,10,0,0,0,0,0,0,1,9,0,1,0,0,0,7,0,0,0,0,0,0,0,'Scarlet Preacher - On aggro - say text'),
(28939,0,5,0,7,0,100,0,0,0,0,0,0,80,2861002,2,1,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Preacher - On evade - action list'),
(28940,0,0,0,0,0,100,0,2300,3900,2300,3900,0,11,52818,64,0,0,0,0,2,0,0,0,0,0,0,0,'Scarlet Crusader - IC CMC - Cast shot'),
(28940,0,1,0,0,0,100,0,5000,8000,5000,8000,0,11,52221,0,0,0,0,0,2,0,0,0,0,0,0,0,'Scarlet Crusader - IC - Cast Heroic Strike'),
(28940,0,2,0,8,0,100,0,52781,0,10000,10000,0,87,2861000,2861001,2861000,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Crusader - On spellhit - Random action list'),
(28940,0,3,0,4,0,10,0,0,0,0,0,0,1,9,0,1,0,0,0,7,0,0,0,0,0,0,0,'Scarlet Marksman - On aggro - say text'),
(28940,0,4,0,7,0,100,0,0,0,0,0,0,80,2861002,2,1,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Marksman - On evade - action list'),
(28936,0,0,0,0,0,100,0,2300,3900,2300,3900,0,11,52818,64,0,0,0,0,2,0,0,0,0,0,0,0,'Scarlet Commander - IC CMC - Cast shot'),
(28936,0,1,0,0,0,100,0,5000,8000,5000,8000,0,11,52221,0,0,0,0,0,2,0,0,0,0,0,0,0,'Scarlet Commander - IC - Cast Heroic Strike'),
(28936,0,2,0,8,0,100,0,52781,0,10000,10000,0,87,2861000,2861001,2861000,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Commander - On spellhit - Random action list'),
(28936,0,3,0,4,0,10,0,0,0,0,0,0,1,9,0,1,0,0,0,7,0,0,0,0,0,0,0,'Scarlet Commander - On aggro - say text'),
(28936,0,4,0,7,0,100,0,0,0,0,0,0,80,2861002,2,1,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Commander - On evade - action list'),
(2861000,9,0,0,0,0,100,0,0,0,0,0,0,84,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scarlet unit - Action list 0 - Player say line 0'),
(2861000,9,1,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scarlet unit - Action list 0 - Say line 1'),
(2861001,9,0,0,0,0,100,0,0,0,0,0,0,84,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scarlet unit - Action list 0 - Player say line 0'),
(2861001,9,1,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet unit - Action list 1 - Set react state'),
(2861001,9,2,0,0,0,100,0,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet unit - Action list 1 - Disable combat movement'),
(2861001,9,3,0,0,0,100,0,2000,2000,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scarlet unit - Action list 1 - Say line 2'),
(2861001,9,4,0,0,0,100,0,2000,2000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet unit - Action list 1 - Set kneel state'),
(2861001,9,5,0,0,0,100,0,2000,2000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scarlet unit - Action list 1 - Say line 3'),
(2861001,9,6,0,0,0,100,0,5000,5000,0,0,0,1,4,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scarlet unit - Action list 1 - Say line 4'),
(2861001,9,7,0,0,0,100,0,6000,6000,0,0,0,1,5,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scarlet unit - Action list 1 - Say line 5'),
(2861001,9,8,0,0,0,100,0,3000,3000,0,0,0,84,6,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scarlet unit - Action list 1 - Player say line 6'),
(2861001,9,9,0,0,0,100,0,0,0,0,0,0,11,52806,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scarlet unit - Action list 1 - cast Interrogation'),
(2861001,9,10,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet unit - Action list 1 - Remove kneel state'),
(2861001,9,11,0,0,0,100,0,0,0,0,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet unit - Action list 1 - Set state Cower'),
(2861001,9,12,0,0,0,100,0,4000,4000,0,0,0,1,7,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scarlet unit - Action list 1 - Say line 7'),
(2861001,9,13,0,0,0,100,0,2000,2000,0,0,0,11,52794,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scarlet unit - Action list 1 - Cast \'Interrogation Quest Credit\''),
(2861001,9,14,0,0,0,100,0,1000,1000,0,0,0,1,8,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scarlet unit - Action list 1 - Say line 8'),
(2861001,9,15,0,0,0,100,0,0,0,0,0,0,11,3617,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet unit - Action list 1 - Cast kill self'),
(2861002,9,0,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet unit - On action list - Reset emote state'),
(2861002,9,1,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet unit - On action list - Restore state'),
(2861002,9,2,0,0,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet unit - On action list - Restore react state'),
(2861002,9,3,0,0,0,100,0,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet unit - On action list - Enable combat movement');

UPDATE `item_template_addon` SET `SpellPPMChance`= 1.5 WHERE `Id`= 39371;
