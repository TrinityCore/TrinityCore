--
SET @LOCALIZED_STRINGS_START = 70012;
SET @LOCALIZED_STRINGS_END   = 70013;

DELETE FROM `npc_text` WHERE ID BETWEEN @LOCALIZED_STRINGS_START and @LOCALIZED_STRINGS_END;
INSERT INTO `npc_text` (`ID`,`text0_0`,`VerifiedBuild`) VALUES
(70012,'<Battle-scarred Crypt Lord stands before you, he is obviously uncontrolled. Without master this mighty undead nerubian lord has lost most of his power>$B$BWhat will it be, tiny creature? Your flesh will do like any other...','-1'),
(70013,'I consume the living and the dead.','-1');

SET @LOCALIZED_STRINGS_START = 70109;
SET @LOCALIZED_STRINGS_END   = 70109;

DELETE FROM `npc_text` WHERE ID BETWEEN @LOCALIZED_STRINGS_START and @LOCALIZED_STRINGS_END;
INSERT INTO `npc_text` (`ID`,`text0_0`,`VerifiedBuild`) VALUES
(70109,'|cff9900ccCrypt Lord|r$b|cffdd6600-=Warcraft III tribute=-|r$B$B\"Ancient behemoth, once one of the kings of Azjol-Nerub, now an undead monster within ranks of Lich King\'s mightiest warriors\".$B$BVery high armor, increased resistances, partially immune to control effects, immune to poison-based effects, mail/plate armor, deals melee/spellshadow damage, spell power bonus: 200% strength. Main attribute: Strength.$B$BImpale. Crypt Lord slams the ground with his massive claws, shooting spikes out in a frontal cone, dealing damage and hurling enemy units into the air in their wake, stunning them. Unlocked at level 20.$B$BSpiked Carapace. Crypt Lord\'s chitinous armor increases damage resistance and returns 15% to 50% damage to enemy melee attackers.$B$BCarrion Beetles. Crypt Lord progenerates a Carrion Beetle from a fresh corpse of an enemy to attack his enemies. Beetles are permanent but do not regenerate health and only 6 can be controlled at a time. Higher levels allow Crypt Lord to summon more powerful beetles. Unlocked at level 10.$B$BLocust Swarm. Crypt Lord releases a swarm of 20-40 (depends on Crypt Lord\'s level) angry locusts that bite and tear at nearby enemy units, reducing their ability to move or attack. As they chew the enemy flesh, they convert it into a substance that restores hit points to the Crypt Lord when they return. Unlocked at level 40.$B$B',-1);

SET @LOCALIZED_STRINGS_START = 70667;
SET @LOCALIZED_STRINGS_END   = 70672;

DELETE FROM `npc_text` WHERE ID BETWEEN @LOCALIZED_STRINGS_START and @LOCALIZED_STRINGS_END;
INSERT INTO `npc_text` (`ID`,`text0_0`,`VerifiedBuild`) VALUES
(70667,'Do you really want to spend all this money to make Crypt Lord move again?','-1'),
(70668,'I doubt your ability to do much harm in your current state, but I am willing to lead you and help you restore your powers.','-1'),
(70669,'Crypt Lords','-1'),
(70670,'Crypt Lord','-1'),
(70671,'Reflect','-1'),
(70672,'Locusts','-1');
