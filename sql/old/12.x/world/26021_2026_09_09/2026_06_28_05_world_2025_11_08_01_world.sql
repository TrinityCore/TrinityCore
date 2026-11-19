--
DELETE FROM `creature_text` WHERE `CreatureID` = 16118;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16118,0,0,"You think you can summon us? We are the ones that summon, not you! We bash you good for this and suck the marrow from your bones!",14,0,100,0,0,0,11968,0,"Kormok SAY_SPAWN"),
(16118,1,0,"First Kormok crush your bones!  Then Kormok burn your soul!",12,0,100,0,0,0,11958,0,"Kormok SAY_AGGRO"),
(16118,1,1,"You so little and puny... you no make good servants for Kormok!",12,0,100,0,0,0,11959,0,"Kormok SAY_AGGRO"),
(16118,2,0,"We am free! Thank you little, puny ones.",14,0,100,0,0,0,11873,0,"Kormok SAY_DEATH"),
(16118,3,0,"%s goes into a frenzy!",16,0,100,0,0,0,10645,0,"Kormok EMOTE_FRENZY");

DELETE FROM `creature_text` WHERE `CreatureID` = 10432 AND `GroupID` = 0;

DELETE FROM `creature_text` WHERE `CreatureID` = 14516;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14516,0,0,"ENOUGH - this ends now!  You fools will be added to my bone collection!",14,0,100,0,0,0,9784,0,"Death Knight Darkreaver");

DELETE FROM `creature_text` WHERE `CreatureID` = 11261;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11261,0,0,"The doctor is in!",12,0,100,0,0,0,6715,0,"Doctor Theolen Krastinov SAY_AGGRO"),
(11261,1,0,"%s goes into a frenzy!",16,0,100,0,0,0,10645,0,"Doctor Theolen Krastinov EMOTE_FRENZY");

DELETE FROM `creature_text` WHERE `CreatureID` = 10503;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10503,0,0,"%s loosens her grasp on the journal she had been clutching.",16,0,100,0,0,0,11408,0,"Jandice Barov");

DELETE FROM `waypoint_path` WHERE `PathId` = 840488;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(840488, 1, 0, NULL, 'Migrated from refactor');

DELETE FROM `waypoint_path_node` WHERE `PathId` = 840488;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(840488, 1, 316.709, 71.2683, 104.584, NULL, 0),
(840488, 2, 321.16, 72.8097, 104.668, NULL, 0),
(840488, 3, 332.371, 77.9899, 105.862, NULL, 0),
(840488, 4, 333.325, 86.6016, 106.64, NULL, 0),
(840488, 5, 334.126, 101.684, 106.834, NULL, 0),
(840488, 6, 331.046, 114.593, 106.362, NULL, 0),
(840488, 7, 329.544, 126.702, 106.14, NULL, 0),
(840488, 8, 335.247, 136.546, 105.723, NULL, 0),
(840488, 9, 343.21, 139.946, 107.64, NULL, 0),
(840488, 10, 364.329, 140.901, 109.945, NULL, 0),
(840488, 11, 362.676, 115.638, 110.307, NULL, 0),
(840488, 12, 341.79, 91.9439, 107.168, NULL, 0),
(840488, 13, 313.495, 93.4594, 104.057, NULL, 0),
(840488, 14, 306.384, 93.6168, 104.057, NULL, 0);

UPDATE `creature_template` SET `unit_flags` = 832 WHERE `entry` = 10506;
