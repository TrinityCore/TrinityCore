-- Pilot Stonegear & Pilot Bellowfiz event
DELETE FROM `creature_text` WHERE `CreatureID` IN (1377, 1378);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1378,0,0,'Hey Stone, did you hear about the new steam engine old Tonkrend has been runnin on?',12,7,100,1,0,0,232,0,'Pilot Bellowfiz'),
(1378,1,0,'Do you ever think about anything other than fighting? I could circle you down on the stretch course!',12,7,100,6,0,0,234,0,'Pilot Bellowfiz'),
(1378,2,0,'Argh! You''re hopeless!',12,7,100,5,0,0,236,0,'Pilot Bellowfiz'),
(1378,3,0,'Ah, let me see. Yes probably nearing a hundred times now I''d wager!',12,7,100,273,0,0,238,0,'Pilot Bellowfiz'),
(1378,4,0,'I would have just dropped some Evershine in my tank and been back home before they realized I''d gone!',12,7,100,1,0,0,240,0,'Pilot Bellowfiz'),
(1378,5,0,'Hey Stone, let''s hit the circuit some time. We could run a few laps and see who wins?',12,7,100,1,0,0,242,0,'Pilot Bellowfiz'),
(1378,6,0,'Nothing you can say will ever get me in the arena against that monstrosity of a machine you call a steam tank!',12,7,100,274,0,0,245,0,'Pilot Bellowfiz'),
(1378,7,0,'Ha! I''m more afraid that those old holes and gashes would burst that thing and I would be showered by the shrapnel!',12,7,100,5,0,0,247,0,'Pilot Bellowfiz'),
(1378,8,0,'Nothing beats the sound of a twin-carb, fork-ring steam engine burning pure firestone!',12,7,100,1,0,0,249,0,'Pilot Bellowfiz'),
(1378,9,0,'Bah! You wouldn''t know a great steam engine if it smacked you upside the head!',12,7,100,274,0,0,251,0,'Pilot Bellowfiz'),
(1377,0,0,'Ah yes. I''ve heard all about those new flarged things. Armor was removed from the casing to decrease weight. Bargh! Nonsense!',12,7,100,1,0,0,233,0,'Pilot Stonegear'),
(1377,1,0,'Bah! By the time you got in range of old Trollplow you would be in reduced to rubble!',12,7,100,274,0,0,235,0,'Pilot Stonegear'),
(1377,2,0,'Hey Fizzer, I ever tell you the time I was riding through the canals and some goblins in shredder suits tried to ambush me?',12,7,100,1,0,0,237,0,'Pilot Stonegear'),
(1377,3,0,'Brahaha! Tha look on their faces as old Trollplow''s gun came swiveling around to meet them! Their saws couldn''t even touch me!',12,7,100,11,0,0,239,0,'Pilot Stonegear'),
(1377,4,0,'Bah! That''s no fun!',12,7,100,274,0,0,241,0,'Pilot Stonegear'),
(1377,5,0,'Aye sure, just as long as we get to hit the arena right after!',12,7,100,1,0,0,244,0,'Pilot Stonegear'),
(1377,6,0,'Har! You scared I''ll hurt your little dainty racer?',12,7,100,6,0,0,246,0,'Pilot Stonegear'),
(1377,7,0,'Haha! Sturdy old Trollplow has just a few meager battle scars!',12,7,100,11,0,0,248,0,'Pilot Stonegear'),
(1377,8,0,'Ha! I''d take the sound of a Crater Cannon XT blasting off a shell over that any day!',12,7,100,5,0,0,250,0,'Pilot Stonegear'),
(1377,9,0,'Maybe, but if it did hit me upside the head I''d know exactly which cannon to use to blow it into the smallest bits!',12,7,100,1,0,0,252,0,'Pilot Stonegear');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1377;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1377 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (137700, 137701, 137702, 137703) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1377,0,0,0,1,0,100,0,0,30000,60000,90000,87,137700,137701,137702,137703,0,0,1,0,0,0,0,0,0,0,'Pilot Stonegear - Out Of Combat - Run Random Script'),
(137700,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,1378,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 0 (Pilot Bellowfiz)'),
(137700,9,1,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 0'),
(137700,9,2,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,19,1378,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 1 (Pilot Bellowfiz)'),
(137700,9,3,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 1'),
(137700,9,4,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,19,1378,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 2 (Pilot Bellowfiz)'),
(137701,9,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 2'),
(137701,9,1,0,0,0,100,0,7000,7000,0,0,1,3,0,0,0,0,0,19,1378,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 3 (Pilot Bellowfiz)'),
(137701,9,2,0,0,0,100,0,4500,4500,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 3'),
(137701,9,3,0,0,0,100,0,7000,7000,0,0,1,4,0,0,0,0,0,19,1378,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 4 (Pilot Bellowfiz)'),
(137701,9,4,0,0,0,100,0,6000,6000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 4'),
(137702,9,0,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,19,1378,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 5 (Pilot Bellowfiz)'),
(137702,9,1,0,0,0,100,0,5000,5000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 5'),
(137702,9,2,0,0,0,100,0,4000,4000,0,0,1,6,0,0,0,0,0,19,1378,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 6 (Pilot Bellowfiz)'),
(137702,9,3,0,0,0,100,0,6500,6500,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 6'),
(137702,9,4,0,0,0,100,0,4000,4000,0,0,1,7,0,0,0,0,0,19,1378,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 7 (Pilot Bellowfiz)'),
(137702,9,5,0,0,0,100,0,6500,6500,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 7'),
(137703,9,0,0,0,0,100,0,0,0,0,0,1,8,0,0,0,0,0,19,1378,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 8 (Pilot Bellowfiz)'),
(137703,9,1,0,0,0,100,0,5500,5500,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 8'),
(137703,9,2,0,0,0,100,0,5500,5500,0,0,1,9,0,0,0,0,0,19,1378,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 9 (Pilot Bellowfiz)'),
(137703,9,3,0,0,0,100,0,5000,5000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pilot Stonegear - On Script - Say Line 9');
