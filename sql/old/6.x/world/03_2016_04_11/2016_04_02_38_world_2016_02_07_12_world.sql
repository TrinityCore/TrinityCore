-- DB/Quest: Drop It then Rock It!
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (24640, 24015);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24640, 24015) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2464000, 24015*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24640, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 2464000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alliance Banner - just summoned - Action list'),
(24640, 0, 1, 0, 0, 0, 100, 0, 1000, 1000, 2000, 2000, 19, 2048, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alliance Banner - IC- remove unit flag'),
(24640, 0, 2, 0, 1, 0, 100, 0, 1000, 1000, 2000, 2000, 19, 2048, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alliance Banner - OOC - remove unit flag'),
(2464000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alliance Banner - Action list - Set react passif'),
(2464000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alliance Banner - Action list - Set root'),
(2464000, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alliance Banner - Action list - Set health regen off'),
(2464000, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 12, 24015, 4, 60000, 0, 1, 0, 8, 0, 0, 0, 1483.793091, -5352.790039, 192.023712, 1.431473, 'Alliance Banner - Action list - Summon Winterskorn Defender'), 
(2464000, 9, 4, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 12, 24015, 4, 60000, 0, 1, 0, 8, 0, 0, 0, 1460.096436, -5342.498535, 195.991714, 0.339768, 'Alliance Banner - Action list - Summon Winterskorn Defender'),
(2464000, 9, 5, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 12, 24015, 4, 60000, 0, 1, 0, 8, 0, 0, 0, 1468.549561, -5300.886230, 195.633850, 5.760584, 'Alliance Banner - Action list - Summon Winterskorn Defender'),
(2464000, 9, 6, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 11, 44124, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Alliance Banner - Action list - Quest Credit'),
(2464000, 9, 7, 0, 0, 0, 100, 0, 100, 100, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alliance Banner - Action list - Despawn'),

(24015, 0, 0, 0, 0, 0, 100, 0, 3000, 5000, 5000, 7000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Winterskorn Defender - IC - Cast Cleave'),
(24015, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 10000, 15000, 11, 18812, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Winterskorn Defender - IC - Cast Knockdown'),
(24015, 0, 2, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 24015*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Winterskorn Defender - Just sumoned - Action list'),
(24015*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Winterskorn Defender - Action list - Talk'),
(24015*100, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1499.201538, -5319.049316, 195.300629, 0.451290, 'Winterskorn Defender - Action list - move to pos');

DELETE FROM `creature_text` WHERE `entry` IN (24015);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(24015, 0, 0, 'Your remains will be fed TO the sharks of Daggercap!', 14, 0, 100, 0, 0, 0, 23619, 0, 'Winterskorn Defender'),
(24015, 0, 1, 'The sacrifices NOW bring themselves TO us? Have you NO sense!?', 14, 0, 100, 0, 0, 0, 23618, 0, 'Winterskorn Defender'),
(24015, 0, 2, 'You dare challenge Winterskorn?! I will impale you ON your own puny flag!', 14, 0, 100, 0, 0, 0, 23617, 0, 'Winterskorn Defender');
