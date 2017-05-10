-- An end to the suffering
UPDATE `creature_template` SET `unit_flags`=33536 WHERE  `entry`=28416;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` =28416;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28416 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2841600 AND `source_type`=9;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(-113558,-113482,-113483,-113481) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-113558, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 51607, 0, 0, 0, 0, 0, 10, 95460, 28416, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny (scale x0.01) Large - On Data Set  - Cast \'Rhunok\'s Chains\''),
(-113558, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 92, 0, 51607, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny (scale x0.01) Large - On Data Set - Remove Aura \'Rhunok\'s Chains\''),
(-113558, 0, 2, 0, 1, 0, 100, 1, 5000, 5000, 0, 0, 11, 51607, 0, 0, 0, 0, 0, 10, 95460, 28416, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny (scale x0.01) Large - On Spawn  - Cast \'Rhunok\'s Chains\''),
(-113482, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 51607, 0, 0, 0, 0, 0, 10, 95460, 28416, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny (scale x0.01) Large - On Data Set  - Cast \'Rhunok\'s Chains\''),
(-113482, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 92, 0, 51607, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny (scale x0.01) Large - On Data Set - Remove Aura \'Rhunok\'s Chains\''),
(-113482, 0, 2, 0, 1, 0, 100, 1, 5000, 5000, 0, 0, 11, 51607, 0, 0, 0, 0, 0, 10, 95460, 28416, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny (scale x0.01) Large - On Spawn  - Cast \'Rhunok\'s Chains\''),
(-113483, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 51607, 0, 0, 0, 0, 0, 10, 95460, 28416, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny (scale x0.01) Large - On Data Set  - Cast \'Rhunok\'s Chains\''),
(-113483, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 92, 0, 51607, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny (scale x0.01) Large - On Data Set - Remove Aura \'Rhunok\'s Chains\''),
(-113483, 0, 2, 0, 1, 0, 100, 1, 5000, 5000, 0, 0, 11, 51607, 0, 0, 0, 0, 0, 10, 95460, 28416, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny (scale x0.01) Large - On Spawn  - Cast \'Rhunok\'s Chains\''),
(-113481, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 51607, 0, 0, 0, 0, 0, 10, 95460, 28416, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny (scale x0.01) Large - On Data Set  - Cast \'Rhunok\'s Chains\''),
(-113481, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 92, 0, 51607, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny (scale x0.01) Large - On Data Set - Remove Aura \'Rhunok\'s Chains\''),
(-113481, 0, 2, 0, 1, 0, 100, 1, 5000, 5000, 0, 0, 11, 51607, 0, 0, 0, 0, 0, 10, 95460, 28416, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny (scale x0.01) Large - On Spawn  - Cast \'Rhunok\'s Chains\''),
(28416, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rhunok - On Reset - Set Unit Flags'),
(28416, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 90, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rhunok - On Reset - Set Bytes 1'),
(28416, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 113558, 26298, 0, 0, 0, 0, 0, 'Rhunok - On Reset - Set Data on ELM General Purpose Bunny (scale x0.01) Large'),
(28416, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 113482, 26298, 0, 0, 0, 0, 0, 'Rhunok - On Reset - Set Data on ELM General Purpose Bunny (scale x0.01) Large'),
(28416, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 113481, 26298, 0, 0, 0, 0, 0, 'Rhunok - On Reset - Set Data on ELM General Purpose Bunny (scale x0.01) Large'),
(28416, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 113483, 26298, 0, 0, 0, 0, 0, 'Rhunok - On Reset - Set Data on ELM General Purpose Bunny (scale x0.01) Large'),
(28416, 0, 6, 7,  8, 0, 100, 0, 51964, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 113558, 26298, 0, 0, 0, 0, 0, 'Rhunok - Spellhit - Set Data on ELM General Purpose Bunny (scale x0.01) Large'), -- 17:16:47.641
(28416, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 113481, 26298, 0, 0, 0, 0, 0, 'Rhunok - Spellhit - Set Data on ELM General Purpose Bunny (scale x0.01) Large'),
(28416, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 113482, 26298, 0, 0, 0, 0, 0, 'Rhunok - Spellhit - Set Data on ELM General Purpose Bunny (scale x0.01) Large'),
(28416, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 113483, 26298, 0, 0, 0, 0, 0, 'Rhunok - Spellhit - Set Data on ELM General Purpose Bunny (scale x0.01) Large'),
(28416, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2841600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rhunok - Spellhit - Run Script'),
(28416, 0, 11, 0, 9, 0, 100, 0, 0, 5, 1000, 5000, 11, 34298, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Rhunok - On Range - Cast Maul'),
(28416, 0, 12, 0, 2, 0, 100, 1, 0, 25, 0, 0, 11, 57861, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rhunok - On 25% HP - Cast Roar of Rhunok'),
(28416, 0, 13, 0, 8, 0, 100, 0, 51603, 0, 0, 0, 4, 477, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rhunok - On Spellhit - Play Sound'),
(2841600, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 91, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rhunok - Script - Remove Bytes 1'),
(2841600, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Rhunok - Script - Face Invoker'),
(2841600, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 45111, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rhunok - Script - Cast Enrage'),
(2841600, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rhunok - Script - Say'),
(2841600, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rhunok - Script - Remove Unit Flags'),
(2841600, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Rhunok - Script - Start Attack');

DELETE FROM `creature_text` WHERE `entry`=28416;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(28416, 0, 0, 'I will not simply lay here and allow you to slay me! You will have to earn your right to draw another breath if you want to kill me, mortal!', 14, 0, 100, 0, 0, 478, 28544, 'Rhunok to Player');

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=51964;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES 
(0, 51964, 64, '', '', 'Ignore LOS on Tormentor''s Incense');
-- Catching up with Brann linking
UPDATE quest_template_addon SET PrevQuestID = 12917 WHERE ID = 12920;
-- Valkyrion Must Burn
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30066) AND `source_type`=0 AND `id`=1 ;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30066,0,1,0,28,0,100,0,0,0,0,0,81,16777216,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Valkyrion Harpoon Gun - On Passenger Dismounted - Set NPC Flags');
