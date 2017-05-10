UPDATE `creature_text` SET `emote`=5 WHERE  `entry`=19831 AND `groupid`=4 AND `id`=0;
UPDATE `creature_text` SET `emote`=1 WHERE  `entry`=19831 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `emote`=6 WHERE  `entry`=19830 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `emote`=1 WHERE  `entry`=21504 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `emote`=5 WHERE  `entry`=21504 AND `groupid`=1 AND `id`=0;
UPDATE `creature_text` SET `emote`=1 WHERE  `entry`=21504 AND `groupid`=2 AND `id`=0;
UPDATE `creature_text` SET `emote`=1 WHERE  `entry`=21504 AND `groupid`=3 AND `id`=0;
UPDATE `creature_text` SET `emote`=2 WHERE  `entry`=18554 AND `groupid`=3 AND `id`=0;
UPDATE `creature_text` SET `emote`=1 WHERE  `entry`=21504 AND `groupid`=4 AND `id`=0;
UPDATE `creature_text` SET `emote`=1 WHERE  `entry`=21504 AND `groupid`=5 AND `id`=0;
UPDATE `creature_text` SET `emote`=5, `sound`=7274 WHERE  `entry`=21504 AND `groupid`=6 AND `id`=0;
UPDATE `creature_text` SET `emote`=25 WHERE  `entry`=21504 AND `groupid`=7 AND `id`=0;
UPDATE `creature_text` SET `emote`=25 WHERE  `entry`=18385 AND `groupid`=1 AND `id`=0;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(19466);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(19466) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(1946600) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1410 AND `source_type`=0 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5355 AND `source_type`=0 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16769 AND `source_type`=0 AND `id`=17;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21611 AND `source_type`=0 AND `id`=3;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19466, 0, 0, 0, 1, 0, 100, 0, 0, 30000, 180000, 240000, 80, 1946600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Exarch Orelis - OOC - Run Script'),
(1410, 0, 3, 0, 4, 0, 30, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Firewing Bloodwarder - On Agro - Say'),
(5355, 0, 3, 0, 4, 0, 30, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Firewing Defender - On Agro - Say'),
(16769, 0, 17, 0, 4, 0, 30, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Firewing Warlock - On Agro - Say'),
(21611, 0, 3, 0, 4, 0, 30, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Cabal SkirmisheR - On Agro - Say'),
(1946600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 19467, 0, 0, 0, 0, 0, 0, 'Exarch Orelis - Script - Say Line 1 (Anchorite Karja)'),
(1946600, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 19468, 0, 0, 0, 0, 0, 0, 'Exarch Orelis - Script - Say Line 1 (Spymaster Thalodien)'),
(1946600, 9, 2, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Exarch Orelis - Script - Say Line 1'),
(1946600, 9, 3, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 19469, 0, 0, 0, 0, 0, 0, 'Exarch Orelis - Script - Say Line 1 (Magistrix Larynna)'),
(1946600, 9, 4, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 19467, 0, 0, 0, 0, 0, 0, 'Exarch Orelis - Script - Say Line 2 (Anchorite Karja)'),
(1946600, 9, 5, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 19467, 0, 0, 0, 0, 0, 0, 'Exarch Orelis - Script - Say Line 3 (Anchorite Karja)'),
(1946600, 9, 6, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 19469, 0, 0, 0, 0, 0, 0, 'Exarch Orelis - Script - Say Line 2 (Magistrix Larynna)'),
(1946600, 9, 7, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 19468, 0, 0, 0, 0, 0, 0, 'Exarch Orelis - Script - Say Line 2 (Spymaster Thalodien)'),
(1946600, 9, 8, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Exarch Orelis - Script - Say Line 2'),
(1946600, 9, 9, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 19468, 0, 0, 0, 0, 0, 0, 'Exarch Orelis - Script - Say Line 3 (Spymaster Thalodien)');

DELETE FROM `creature_text` WHERE `entry` IN(19466,19468,19541,19467,19469,1410,5355,21661);
DELETE FROM `creature_text` WHERE `entry` =16769 AND `groupid`=1;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(19466, 0, 0, 'Hold your tongue, knave!  Do not dare use that tone with a priestess of the Light!', 12, 0, 100, 25, 0, 0, 'Exarch Orelis',16873),
(19466, 1, 0, 'Even you must admit that your information from defectors is outdated and unreliable.  Let us make calculated attacks on these manaforges and gather what information we can.', 12, 0, 100, 5, 0, 0, 'Exarch Orelis',16890),
(19468, 0, 0, 'Look, sweetheart.  No one''s talking about storming Tempest Keep ourselves, but when we see a target of opportunity we have to take it.', 12, 0, 100, 0, 0, 0, 'Spymaster Thalodien',16872),
(19468, 1, 0, '...and just look at where that got us!', 12, 0, 100, 0, 0, 0, 'Spymaster Thalodien',16889),
(19468, 2, 0, 'Finally some talk of action from the big guy!', 12, 0, 100, 1, 0, 0, 'Spymaster Thalodien',16891),
(19541, 0, 0, 'Good thing that we''re surrounded by neighbors with excess machine parts.', 12, 0, 100, 1, 0, 0, 'Netherstorm Agent',17119),
(19541, 0, 1, 'Maybe I should gather up some other agents and head out there after this shift?', 12, 0, 100, 1, 0, 0, 'Netherstorm Agent',17115),
(19541, 0, 2, 'Hmm, arcane annihilators are pretty tough.  I wonder if Papa Wheeler knows what he''s asking for?', 12, 0, 100, 1, 0, 0, 'Netherstorm Agent',17116),
(19541, 0, 3, 'Last time someone went out to try to collect the bounty on Netherock, all we got back was a compressed layer of foolhardy adventurer!', 12, 0, 100, 1, 0, 0, 'Netherstorm Agent',19660),
(19541, 0, 4, 'Netherock?!  That thing''ll squish you flat with one step of its massive foot!  No thanks!', 12, 0, 100, 1, 0, 0, 'Netherstorm Agent',19659),
(19467, 0, 0, 'With all due respect, A''dal sent us here to investigate Kael''s activities, not mount a full-scaled attack.', 12, 0, 100, 0, 0, 0, 'Anchorite Karja',16870),
(19467, 1, 0, 'The magistrix will be happy to know  I''m  fluent in Thalassian.  Your courtesy is not lost on me.', 12, 0, 100, 0, 0, 0, 'Anchorite Karja',16875),
(19467, 2, 0, 'Back to the topic...  we should focus our attention on these manaforges.  We need to learn what the enemy is doing with them and why.', 12, 0, 100, 0, 0, 0, 'Anchorite Karja',16876),
(19469, 0, 0, 'I''m surrounded by idiots!', 12, 10, 100, 5, 0, 0, 'Magistrix Larynna',16874),
(19469, 1, 0, 'We''ve told you all there is to know!  Do you forget that many of us used to be trusted followers of Kael''thas?', 12, 0, 100, 22, 0, 0, 'Magistrix Larynna',16883),
(1410, 0, 0, 'You won''t escape alive!', 12, 0, 100, 0, 0, 0, 'Firewing Bloodwarder',16249),
(1410, 0, 1, 'I will have your energy and then your life!', 12, 0, 100, 0, 0, 0, 'Firewing Bloodwarder',16254),
(5355, 0, 2, 'You won''t escape alive!', 12, 0, 100, 0, 0, 0, 'Firewing Defender',16249),
(5355, 0, 3, 'You know too much!', 12, 0, 100, 0, 0, 0, 'Firewing Defender',16251),
(16769, 1, 0, 'For Kael''thas!', 12, 0, 100, 0, 0, 0, 'Firewing Warlock',16252),
(16769, 1, 1, 'You won''t escape alive!', 12, 0, 100, 0, 0, 0, 'Firewing Warlock',16249),
(16769, 1, 2, 'Kill them before they get away!', 12, 0, 100, 0, 0, 0, 'Firewing Warlock',16250),
(16769, 1, 3, 'I will have your energy and then your life!', 12, 0, 100, 0, 0, 0, 'Firewing Warlock',16254),
(21661, 0, 0, '%s becomes enraged!', 16, 0, 100, 0, 0, 0, 'Cabal Skirmisher',10677),
(21661, 1, 0, 'The end comes for you!', 12, 0, 100, 0, 0, 0, 'Cabal Skirmisher',16800),
(21661, 1, 1, 'You will not escape us so easily!', 12, 0, 100, 0, 0, 0, 'Cabal Skirmisher',20165),
(21661, 1, 2, 'I shall be rewarded!', 12, 0, 100, 0, 0, 0, 'Cabal Skirmisher',16803);
