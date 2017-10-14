/*
-- Cersei Dusksinger, Lorrin Foxfire, Rogvar, Kartosh & Greshka
DELETE FROM `creature_text` WHERE `CreatureID` IN (17109, 12807, 988, 1386, 27705);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17109,0,0,"Hahaha!  That fool will never find out what I'm up to!  Or, if he does, it'll be too late for the draenei!",12,0,100,11,0,0,14094,0,"Cersei Dusksinger"),
(17109,0,1,"These orcs are fools!  So much power nearby just waiting to be taken, and all they do is sit on their hands and watch while others plunder the riches!",12,0,100,5,0,0,14095,0,"Cersei Dusksinger"),
(17109,0,2,"I cannot wait to see the results of this latest batch!",12,0,100,1,0,0,14096,0,"Cersei Dusksinger"),
(17109,0,3,"Avuun dares to oppose me?!  I will crush him!  When I am done with the draenei, they'll wish that they were Lost Ones!",12,0,100,15,0,0,14097,0,"Cersei Dusksinger"),
(17109,0,4,"Oh, would you please stop checking your nails and spanking yourself, for one moment?  Really, no one cares!",12,0,100,6,0,0,14098,0,"Cersei Dusksinger"),
(17109,0,5,"Are you hungry?  I'm hungry.  I just can't stand the thought of cured ham steak from Thultash again.  If only we could get some of that succulent roasted quail!",12,0,100,6,0,0,14099,0,"Cersei Dusksinger"),
(17109,1,0,"You have something to say to my face?",12,0,100,6,0,0,14106,0,"Cersei Dusksinger"),
(17109,2,0,"I thought not!",12,0,100,11,0,0,14107,0,"Cersei Dusksinger"),
(17109,3,0,"I need some fresh air, not that there's any to be had in this swamp!  I'm going out for a bit.  Tidy up a bit while I'm gone, would you?",12,0,100,1,0,0,14101,0,"Cersei Dusksinger"),
(17109,4,0,"Must you follow me everywhere? <sigh>",12,0,100,6,0,0,14102,0,"Cersei Dusksinger"),
(27705,0,0,"Ah, I love the smell of Stonard! It smells like... like... orc sweat. And rot. Still, combined, the effect can be quite pleasant! It's an acquired scent.",12,0,100,1,0,0,26992,0,"Lorrin Foxfire"),
(27705,0,1,"While visitors complain about the exceptionally humid air, I find it helps my complexion! Dry skin is unflattering.",12,0,100,1,0,0,26993,0,"Lorrin Foxfire"),
(27705,0,2,"It is a shame, a dreadful shame, that my brethren cannot see what benefits come from truly steeping oneself in a culture.",12,0,100,6,0,0,26994,0,"Lorrin Foxfire"),
(27705,0,3,"Here I am, in a rough-hewn stone tower squatting on marshy, muddy ground while clouds of midges fly unchecked through the open doorways, standing amongst hunched, greenskin figures of dubious hygiene and coarse manners. I've never been happier.",12,0,100,1,0,0,26995,0,"Lorrin Foxfire"),
(27705,0,4,"Before I was stationed out here, I'd only heard about the rejuvenating effects a mudbath can have on skin. When I first tripped over a tree root, I was exposed to the full benefits! Amazing what nature can do, even without a bit of magic to help it along.",12,0,100,1,0,0,26996,0,"Lorrin Foxfire"),
(27705,0,5,"To this day, I ponder why I, myself, was chosen for this particular station. I can only imagine my superior felt I was uniquely suited to the task and would quickly become accustomed to the quaint culture of the Horde found herein, but I heard a truly mean-spirited rumor that it may be because I talk too much.",12,0,100,6,0,0,26997,0,"Lorrin Foxfire"),
(27705,1,0,"You need to learn to appreciate your surroundings, Cersei!",12,0,100,5,0,0,27007,0,"Lorrin Foxfire"),
(12807,0,0,"Look at her down there!  Just who does she think she is?",12,0,100,5,0,0,14103,0,"Greshka"),
(988,0,0,"Hmph, no doubt she believes herself to be the new mistress of Stonard.  Perhaps we should offer to help her succubi tidy up her messes?",12,0,100,11,0,0,14104,0,"Kartosh"),
(1386,0,0,"Her methods are cowardly.  She reminds me of the Forsaken apothecaries.",12,0,100,1,0,0,14105,0,"Rogvar"),
(1386,1,0,"Be quiet.",12,0,100,5,0,0,27000,0,"Rogvar"),
(1386,1,1,"Remember how quiet it was before the elves came here? I miss that.",12,0,100,6,0,0,27001,0,"Rogvar"),
(1386,1,2,"Shut up.",12,0,100,5,0,0,27002,0,"Rogvar"),
(1386,1,3,"I'm not sure which one's crazier.",12,0,100,6,0,0,27003,0,"Rogvar"),
(1386,1,4,"I'd give my pestle away for some earplugs.",12,0,100,1,0,0,27004,0,"Rogvar");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17109;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17109 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1710900, 1710901, 1710902, 1710903, 1710904) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17109,0,0,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Reset - Set Event Phase 1"),
(17109,0,1,0,1,1,100,0,5000,5000,100000,100000,80,1710900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - Out of Combat - Run Script 1 (Phase 1)"),
(17109,0,2,0,1,0,100,0,305000,305000,600000,600000,80,1710901,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - Out of Combat - Run Script 2"),
(17109,0,3,0,40,0,100,0,2,1710900,0,0,80,1710902,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Waypoiny 2 Reached (Path 1) - Run Script 3"),
(17109,0,4,0,40,0,100,0,4,1710900,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Waypoiny 4 Reached (Path 1) - Set Event Phase 1"),
(17109,0,5,0,40,0,100,0,4,1710900,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Waypoiny 4 Reached (Path 1) - Set Orientation"),
(17109,0,6,0,1,0,100,0,605000,605000,600000,600000,80,1710903,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - Out of Combat - Run Script 4"),
(17109,0,7,0,40,0,100,0,4,1710901,0,0,80,1710904,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Waypoiny 4 Reached (Path 2) - Run Script 5"),
(17109,0,8,0,40,0,100,0,8,1710901,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Waypoiny 8 Reached (Path 2) - Set Event Phase 1"),
(17109,0,9,0,40,0,100,0,8,1710901,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Waypoiny 8 Reached (Path 2) - Set Orientation"),
(17109,0,10,0,25,0,100,0,0,0,0,0,11,8722,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Reset - Cast Summon Succubus"),
(1710900,9,0,0,0,0,100,0,15000,15000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Script 1 - Say Line 0"),
(1710900,9,1,0,0,0,100,0,15000,15000,0,0,1,0,0,0,0,0,0,19,27705,0,0,0,0,0,0,"Cersei Dusksinger - On Script 1 - Say Line 0 (Lorrin Foxfire)"),
(1710900,9,2,0,0,0,100,0,15000,15000,0,0,1,1,0,0,0,0,0,19,1386,0,0,0,0,0,0,"Cersei Dusksinger - On Script 1 - Say Line 1 (Rogvar)"),
(1710901,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Script 2 - Set Event Phase 0"),
(1710901,9,1,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,19,12807,0,0,0,0,0,0,"Cersei Dusksinger - On Script 2 - Say Line 0 (Greshka)"),
(1710901,9,2,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,19,988,0,0,0,0,0,0,"Cersei Dusksinger - On Script 2 - Say Line 0 (Kartosh)"),
(1710901,9,3,0,0,0,100,0,9000,9000,0,0,1,0,0,0,0,0,0,19,1386,0,0,0,0,0,0,"Cersei Dusksinger - On Script 2 - Say Line 0 (Rogvar)"),
(1710901,9,4,0,0,0,100,0,5000,5000,0,0,53,0,1710900,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Script 2 - Start Waypoint 1"),
(1710902,9,0,0,0,0,100,0,0,0,0,0,54,18000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Script 3 - Pause Waypoint"),
(1710902,9,1,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Script 3 - Say Line 1"),
(1710902,9,2,0,0,0,100,0,14000,14000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Script 3 - Say Line 2"),
(1710902,9,3,0,0,0,100,0,4000,4000,0,0,5,14,0,0,0,0,0,19,12807,0,0,0,0,0,0,"Cersei Dusksinger - On Script 3 - Play Emote Rude (Greshka)"),
(1710902,9,4,0,0,0,100,0,0,0,0,0,5,14,0,0,0,0,0,19,988,0,0,0,0,0,0,"Cersei Dusksinger - On Script 3 - Play Emote Rude (Kartosh)"),
(1710902,9,5,0,0,0,100,0,0,0,0,0,5,14,0,0,0,0,0,19,1386,0,0,0,0,0,0,"Cersei Dusksinger - On Script 3 - Play Emote Rude (Rogvar)"),
(1710903,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Script 4 - Set Event Phase 0"),
(1710903,9,1,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,19,27705,0,0,0,0,0,0,"Cersei Dusksinger - On Script 4 - Set Orientation"),
(1710903,9,2,0,0,0,100,0,1000,1000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Script 4 - Say Line 3"),
(1710903,9,3,0,0,0,100,0,8000,8000,0,0,1,1,0,0,0,0,0,19,27705,0,0,0,0,0,0,"Cersei Dusksinger - On Script 4 - Say Line 1 (Lorrin Foxfire)"),
(1710903,9,4,0,0,0,100,0,5000,5000,0,0,53,0,1710901,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Script 4 - Start Waypoint 2"),
(1710904,9,0,0,0,0,100,0,0,0,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Script 5 - Pause Waypoint"),
(1710904,9,1,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,19,10928,0,0,0,0,0,0,"Cersei Dusksinger - On Script 5 - Set Orientation"),
(1710904,9,2,0,0,0,100,0,1000,1000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cersei Dusksinger - On Script 5 - Say Line 4");

DELETE FROM `waypoints` WHERE `entry` IN (1710900, 1710901);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(1710900,1,-10463.3,-3322.52,20.9924,""),
(1710900,2,-10468.9,-3331.02,25.4713,""),
(1710900,3,-10463.3,-3322.52,20.9924,""),
(1710900,4,-10461.1,-3319.65,20.9641,""),
(1710901,1,-10457.4,-3322.28,20.9642,""),
(1710901,2,-10454.3,-3320.74,20.9642,""),
(1710901,3,-10455.1,-3311.08,21.0004,""),
(1710901,4,-10445.8,-3296.79,20.1784,""),
(1710901,5,-10455.1,-3311.08,21.0004,""),
(1710901,6,-10454.3,-3320.74,20.9642,""),
(1710901,7,-10457.4,-3322.28,20.9642,""),
(1710901,8,-10461.1,-3319.65,20.9641,"");

-- Cersei Dusksinger --> Fix Gossip Text
DELETE FROM `gossip_menu` WHERE `MenuID`=7369 AND `TextID`=8809;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7369,8809,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 7369;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7369,8809,0,0,8,0,9440,0,0,0,0,0,"","Show Gossip Menu Text 8809 if Quest 'Little Morsels' is rewarded");
*/
