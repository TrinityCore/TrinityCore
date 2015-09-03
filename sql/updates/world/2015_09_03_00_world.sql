UPDATE `creature_template` SET `npcflag` = `npcflag`|2 WHERE entry IN (82901, 82909, 83869, 84173, 84223, 84473, 84660, 86312, 86315, 86682, 88161, 88448);

DELETE FROM `creature_queststarter` WHERE `id` IN (82901, 82909, 83869, 84173, 84223, 84473, 84660, 86065, 86069, 86312, 86315, 86682, 88161, 88448);
DELETE FROM `creature_questender` WHERE `id` IN (82901, 82909, 83869, 84173, 84223, 84473, 84660, 86065, 86069, 86312, 86315, 86682, 88161, 88448);

INSERT INTO `creature_queststarter` VALUES
(82901, 36127), -- Farseer Kylanda, Survey Ashran
(82909, 35937), -- Chris Clarkie, Blood Elf Ear
(82909, 38926), -- Chris Clarkie, Continue the Domination
(82909, 35927), -- Chris Clarkie, Forsaken Brains
(82909, 35938), -- Chris Clarkie, Goblin Nose
(82909, 36123), -- Chris Clarkie, Into The Wilderness
(82909, 35940), -- Chris Clarkie, Orc Tooth
(82909, 35942), -- Chris Clarkie, Pandaren Hide
(82909, 35939), -- Chris Clarkie, Tauren Hoof
(82909, 36125), -- Chris Clarkie, The Road of Glory
(82909, 35941), -- Chris Clarkie, Troll Feet
(83869, 38924), -- Angry Zurge, Continue the Domination
(83869, 36041), -- Angry Zurge, Draenei Tail
(83869, 36034), -- Angry Zurge, Dwarf Spine
(83869, 36042), -- Angry Zurge, Human Bone Chip
(83869, 36228), -- Angry Zurge, Into The Wilderness
(83869, 36038), -- Angry Zurge, Pandaren Hide
(83869, 36033), -- Angry Zurge, Severed Night Elf Head
(83869, 36227), -- Angry Zurge, The Road of Glory
(83869, 36040), -- Angry Zurge, Tuft of Gnome Hair
(83869, 36884), -- Angry Zurge, Worgen Snout
(84173, 37483), -- Commander Anne Dunworthy, Captian's Whistle
(84173, 36130), -- Commander Anne Dunworthy, Reporting For Duty
(84223, 39217), -- Harrison Jones, Don't Hate, Excavate!
(84223, 36133), -- Harrison Jones, Uncovering the Artifact Fragments
(84473, 37484), -- General Ushet Wolfbarger, Captian's Whistle
(84473, 36197), -- General Ushet Wolfbarger, Reporting For Duty
(84660, 36226), -- Mare Wildrunner, Survey Ashran
(86065, 36626), -- Private Tristan, Host Howell
(86069, 36630), -- Lieutenant Howell, A Surly Dwarf
(86069, 36629), -- Lieutenant Howell, Inspiring Ashran
(86312, 36709), -- Lieutenant Kragil, Burning Beauty
(86312, 36708), -- Lieutenant Kragil, Inspiring Ashran
(86315, 36707), -- Stomphoof, Warspear Welcome
(86682, 37126), -- Retired Gorian Centurion, An Ogre Without His Sword...
(86682, 37180), -- Retired Gorian Centurion, An Ogre Without His Sword...
(86682, 36947), -- Retired Gorian Centurion, New Strength
(88161, 37263), -- Challenger Sunforge, A Worthy Challenge: Ner'zhul
(88448, 39233), -- Belloc Brightblade, Don't Hate, Excavate!
(88448, 36198); -- Belloc Brightblade, Uncovering the Artifact Fragments

INSERT INTO `creature_questender` VALUES
(82901, 36127), -- Farseer Kylanda, Survey Ashran
(82909, 38925), -- Chris Clarkie, Ashran Dominance
(82909, 35937), -- Chris Clarkie, Blood Elf Ear
(82909, 38926), -- Chris Clarkie, Continue the Domination
(82909, 35927), -- Chris Clarkie, Forsaken Brains
(82909, 35938), -- Chris Clarkie, Goblin Nose
(82909, 36123), -- Chris Clarkie, Into The Wilderness
(82909, 35940), -- Chris Clarkie, Orc Tooth
(82909, 35942), -- Chris Clarkie, Pandaren Hide
(82909, 39096), -- Chris Clarkie, Slay Them All!
(82909, 35939), -- Chris Clarkie, Tauren Hoof
(82909, 36125), -- Chris Clarkie, The Road of Glory
(82909, 35941), -- Chris Clarkie, Troll Feet
(83869, 38923), -- Angry Zurge, Ashran Dominance
(83869, 38924), -- Angry Zurge, Continue the Domination
(83869, 36041), -- Angry Zurge, Draenei Tail
(83869, 36034), -- Angry Zurge, Dwarf Spine
(83869, 36042), -- Angry Zurge, Human Bone Chip
(83869, 36228), -- Angry Zurge, Into The Wilderness
(83869, 36038), -- Angry Zurge, Pandaren Hide
(83869, 36033), -- Angry Zurge, Severed Night Elf Head
(83869, 39090), -- Angry Zurge, Slay Them All!
(83869, 36227), -- Angry Zurge, The Road of Glory
(83869, 36040), -- Angry Zurge, Tuft of Gnome Hair
(83869, 36884), -- Angry Zurge, Worgen Snout
(84173, 37483), -- Commander Anne Dunworthy, Captian's Whistle
(84173, 36130), -- Commander Anne Dunworthy, Reporting For Duty
(84173, 36119), -- Commander Anne Dunworthy, Welcome to Ashran
(84223, 39217), -- Harrison Jones, Don't Hate, Excavate!
(84473, 37484), -- General Ushet Wolfbarger, Captian's Whistle
(84473, 36197), -- General Ushet Wolfbarger, Reporting For Duty
(84473, 36196), -- General Ushet Wolfbarger, Welcome to Ashran
(84660, 36226), -- Mare Wildrunner, Survey Ashran
(86065, 36624), -- Private Tristan, Ashran Appearance
(86069, 36626), -- Lieutenant Howell, Host Howell
(86069, 36629), -- Lieutenant Howell, Inspiring Ashran
(86312, 36708), -- Lieutenant Kragil, Inspiring Ashran
(86312, 36707), -- Lieutenant Kragil, Warspear Welcome
(86315, 36706), -- Stomphoof, Ashran Appearance
(86682, 37126), -- Retired Gorian Centurion, An Ogre Without His Sword...
(86682, 37180), -- Retired Gorian Centurion, An Ogre Without His Sword...
(86682, 36947), -- Retired Gorian Centurion, New Strength
(88161, 37263), -- Challenger Sunforge, A Worthy Challenge: Ner'zhul
(88448, 39233); -- Belloc Brightblade, Don't Hate, Excavate!
