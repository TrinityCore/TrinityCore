--
DELETE FROM `creature_text` WHERE `CreatureID` = 11583;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11583, 0, 0, 'Well done, my minions. The mortals\' courage begins to wane! Now, let\'s see how they contend with the true Lord of Blackrock Spire!!!', 14, 0, 100, 0, 0, 8288, 9973, 0, 'Nefarian // nefarian SAY_AGGRO'),
(11583, 1, 0, 'Impossible! Rise my minions!  Serve your master once more!', 14, 0, 100, 0, 0, 8291, 9883, 0, 'Nefarian // nefarian SAY_RAISE_SKELETONS'),
(11583, 2, 0, 'Worthless $n!  Your friends will join you soon enough!', 14, 0, 100, 0, 0, 8293, 9972, 0, 'Nefarian // nefarian SAY_SLAY'),
(11583, 3, 0, 'This cannot be!  I am the master here!  You mortals are nothing to my kind!  Do you hear me? Nothing!', 14, 0, 100, 0, 0, 8292, 9971, 0, 'Nefarian // nefarian SAY_DEATH'),
(11583, 4, 0, 'Mages too? You should be more careful when you play with magic...', 14, 0, 100, 0, 0, 0, 9850, 0, 'Nefarian // nefarian SAY_MAGE'),
(11583, 5, 0, 'Warriors, I know you can hit harder than that! Let\'s see it!', 14, 0, 100, 0, 0, 0, 9855, 0, 'Nefarian // nefarian SAY_WARRIOR'),
(11583, 6, 0, 'Druids and your silly shapeshifting. Lets see it in action!', 14, 0, 100, 0, 0, 0, 9851, 0, 'Nefarian // nefarian SAY_DRUID'),
(11583, 7, 0, 'Priests! If you\'re going to keep healing like that, we might as well make it a little more interesting!', 14, 0, 100, 0, 0, 0, 9848, 0, 'Nefarian // nefarian SAY_PRIEST'),
(11583, 8, 0, 'Paladins... I\'ve heard you have many lives. Show me.', 14, 0, 100, 0, 0, 0, 9853, 0, 'Nefarian // nefarian SAY_PALADIN'),
(11583, 9, 0, 'Shamans, show me what your totems can do!', 14, 0, 100, 0, 0, 0, 9854, 0, 'Nefarian // nefarian SAY_SHAMAN'),
(11583, 10, 0, 'Warlocks, you shouldn\'t be playing with magic you don\'t understand. See what happens?', 14, 0, 100, 0, 0, 0, 9852, 0, 'Nefarian // nefarian SAY_WARLOCK'),
(11583, 11, 0, 'Hunters and your annoying pea-shooters!', 14, 0, 100, 0, 0, 0, 9849, 0, 'Nefarian // nefarian SAY_HUNTER'),
(11583, 12, 0, 'Rogues? Stop hiding and face me!', 14, 0, 100, 0, 0, 0, 9856, 0, 'Nefarian // nefarian SAY_ROGUE'),
(11583, 13, 0, 'Death Knights... get over here!', 14, 0, 100, 0, 0, 0, 30668, 0, 'Nefarian // nefarian SAY_DEATH_KNIGHT'),
(11583, 14, 0, 'Enough! Now you vermin shall feel the force of my birthright, the fury of the earth itself.', 14, 0, 100, 0, 0, 8289, 0, 0, 'Nefarian // nefarian SAY_XHEALTH'),
(11583, 15, 0, 'BURN! You wretches! BURN!', 14, 0, 100, 0, 0, 8290, 9974, 0, 'Nefarian // nefarian SAY_SHADOWFLAME');
