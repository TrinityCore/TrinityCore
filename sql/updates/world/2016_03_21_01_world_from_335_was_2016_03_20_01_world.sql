-- UPDATE `spell_dbc` SET `Effect1`=28, `EffectMiscValueB1`=64 WHERE  `Id`=33903;

DELETE FROM `smart_scripts` WHERE `entryorguid`=19188 AND `source_type`=0 AND `id`>3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21504 AND `source_type`=0 AND `id`>0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19305 AND `source_type`=0 AND `id`>5;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19419 AND `source_type`=0 AND `id`>1;

UPDATE `smart_scripts` SET `event_param2`=1,`target_type`=21, `target_param1`=100 WHERE  `entryorguid`=19294 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `event_param2`=2 WHERE  `entryorguid`=19294 AND `source_type`=0 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `action_param2`=1 WHERE  `entryorguid`=19293 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_param2`=2 WHERE  `entryorguid`=20599 AND `source_type`=0 AND `id`=0 AND `link`=0;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(20781,20617);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(20781,20617) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2078100,2150400) AND `source_type`=9;

DELETE FROM `smart_scripts` WHERE `entryorguid`=1929400 AND `source_type`=9 AND `id`>8;
DELETE FROM `event_scripts` WHERE  `id`=13256;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(19188, 0, 4, 0, 2, 0, 100, 1, 0, 75, 0, 0, 11, 33903, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Raging Colossus - At 75% HP - Cast Summon Crystalhide Rageling (No Repeat)'),
(19188, 0, 5, 0, 2, 0, 100, 1, 0, 50, 0, 0, 11, 33903, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Raging Colossus - At 50% HP - Cast Summon Crystalhide Rageling (No Repeat)'),
(1929400, 9, 9, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 31401, 2, 0, 0, 0, 0, 19, 20599, 0, 0, 0, 0, 0, 0, 'Earthbinder Galandria Nightbreeze - On Script - Cast Moonfire'),
(1929400, 9, 10, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 33844, 2, 0, 0, 0, 0, 19, 20599, 0, 0, 0, 0, 0, 0, 'Earthbinder Galandria Nightbreeze - On Script - Cast Entangling Roots'),
(20781, 0, 0, 0, 8, 0, 100, 0, 35413, 0, 180000, 180000, 80, 2078100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seed of Revitalization Target Trigger - On Spellhit (Seed of Revitalization) - Run Script'), -- 15:12:53.391
(20617, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Red Crystal Trigger - On Data Set - Set Phase 1'), 
(20617, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 11, 35468, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Red Crystal Trigger - On Data Set - Cast Seed of Revitalization Entangling Roots Visual'), 
(20617, 0, 2, 0, 38, 0, 100, 0, 3, 3, 0, 0, 28, 35468, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Red Crystal Trigger - On Data Set - Remove Seed of Revitalization Entangling Roots Visual'), 
(20617, 0, 3, 0, 38, 0, 100, 0, 4, 4, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Red Crystal Trigger - On Data Set - Set Phase 0'), 
(20617, 0, 4, 0, 1, 1, 100, 0, 0, 0, 3000, 3000, 11, 35487, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Red Crystal Trigger - OOC (Phase 1) - Cast Seed of Revitalization Lightning Cloud Visual'), 
(20617, 0, 5, 0, 1, 2, 100, 1, 0, 0, 0, 0, 11, 35471, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Red Crystal Trigger - OOC (Phase 2) - Cast Seed of Revitalization Giant Insect Swarm Visual'), 
(20617, 0, 6, 0, 38, 0, 100, 0, 5, 5, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Red Crystal Trigger - On Data Set - Set Phase 2'), 
(20617, 0, 7, 8, 38, 0, 100, 0, 6, 6, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Red Crystal Trigger - On Data Set - Set Phase 0'), 
(20617, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 28, 35468, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Red Crystal Trigger - On Data Set - Set Phase 0'), 
(20617, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 35471, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Red Crystal Trigger - On Data Set - Set Phase 0'), 
(19305, 0, 6, 7, 54, 0, 100, 0, 0, 0, 0, 0, 11, 7741, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Goliathon - On Just Summoned - Cast Summoned Demon'),
(19305, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Goliathon - On Just Summoned - Start Combat'),
(21504, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 80, 2150400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Pathaleon the Calculator\'s Image - On Data Set 2 2 - Run Script'),
(19419, 0, 2, 3, 54, 0, 100, 0, 0, 0, 0, 0, 11, 24240, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Raging Shardling - On Just Summoned - Cast Spawn - Red Lightning'),
(19419, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Raging Shardling - On Just Summoned - Attack'),
(2150400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 34427, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Pathaleon the Calculator\'s Image - Script - Cast Ethereal Teleport'), -- 15:13:04.266
(2150400, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Pathaleon the Calculator\'s Image - Script - Cast Shroud of Death'), -- 15:13:04.266
(2150400, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Pathaleon the Calculator\'s Image - Script - Say Line 9'), -- 15:13:06.453
(2150400, 9, 3, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Pathaleon the Calculator\'s Image - Script - Say Line 10'), -- 15:13:18.578
(2150400, 9, 4, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 11, 23017, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Pathaleon the Calculator\'s Image - Cast Arcane Channeling'), -- 15:13:30.547
(2150400, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Pathaleon the Calculator\'s Image - Script - Say Line 11'), -- 15:13:30.687
(2150400, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 19305, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 107.4091, 4839.756, 78.9819, 6.118358, 'Pathaleon the Calculator\'s Image - Script - Summon Goliathon'), -- 15:13:30.687
(2150400, 9, 7, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Pathaleon the Calculator\'s Image - Script - Say Line 12'), -- 15:13:42.828
(2150400, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Pathaleon the Calculator\'s Image - Script - Despawn'), -- 15:13:42.828
(2078100, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 20617, 0, 100, 0, 0, 0, 0, 'Seed of Revitalization Target Trigger - Script - Set Data on Red Crystal Trigger'), -- 15:12:56.781
(2078100, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 72893, 20617, 0, 0, 0, 0, 0, 'Seed of Revitalization Target Trigger - Script - Set Data on Red Crystal Trigger'), -- 15:13:04.266
(2078100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 21504, 1, 60000, 0, 0, 0, 8, 0, 0, 0, 129.1348, 4834.785, 76.19424, 0.06981317, 'Seed of Revitalization Target Trigger - Script - Summon Pathaleon the Calculators Image'), -- 15:13:04.266
(2078100, 9, 3, 0, 0, 0, 100, 0, 250, 250, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 21504, 0, 0, 0, 0, 0, 0, 'Seed of Revitalization Target Trigger - Script - Set Data on Pathaleon the Calculators Image'), 
(2078100, 9, 4, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 45, 5, 5, 0, 0, 0, 0, 9, 20617, 0, 100, 0, 0, 0, 0, 'Seed of Revitalization Target Trigger - Script - Set Data on Red Crystal Trigger'), -- 15:12:56.781
(2078100, 9, 5, 0, 0, 0, 100, 0, 26000, 26000, 0, 0, 45, 6, 6, 0, 0, 0, 0, 9, 20617, 0, 100, 0, 0, 0, 0, 'Seed of Revitalization Target Trigger - Script - Set Data on Red Crystal Trigger'); -- 15:12:56.781

DELETE FROM `creature_text` WHERE `entry`=21504 AND `groupid`>8;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(21504, 9, 0, 'And just what do you think you are doing?  You dare to interfere with my master''s experiment?', 12, 0, 100, 25, 0, 0, 18369, 0, 'Pathaleon the Calculators Image'),
(21504, 10, 0, 'Do you like what we''ve done here?  Perhaps we will drop these crystals from the sky all over Outland.', 12, 0, 100, 6, 0, 0, 18370, 0, 'Pathaleon the Calculators Image'),
(21504, 11, 0, 'I grow bored with your attempt to heal the land and quell the energies summoning and driving the colossi mad.  Goliathon, King of the Colossi, Prince Kael''thas and I demand that you defend the crystal!', 12, 0, 100, 0, 0, 0, 18371, 0, 'Pathaleon the Calculators Image'),
(21504, 12, 0, 'We will meet again soon.', 12, 0, 100, 1, 0, 0, 18372, 0, 'Pathaleon the Calculators Image');

