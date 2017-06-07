DELETE FROM `command` WHERE `name`='reload quest_greeting';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('reload quest_greeting', 843, 'Syntax: .reload quest_greeting\nReload quest_greeting table.');

DELETE FROM `command` WHERE `name`='reload quest_greeting';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('reload quest_greeting_locale', 857, 'Syntax: .reload quest_greeting_locale\nReload quest_greeting_locale table.');

DROP TABLE IF EXISTS `quest_greeting`;
CREATE TABLE `quest_greeting` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `Type` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  `GreetEmoteType` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
  `GreetEmoteDelay` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `Greeting` TEXT,
  `VerifiedBuild` SMALLINT(5) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`Type`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `quest_greeting_locale`;
CREATE TABLE `quest_greeting_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `Type` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `Greeting` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0',
  PRIMARY KEY (`ID`,`Type`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

DELETE FROM `quest_greeting` WHERE `ID` IN (234, 235, 237, 238, 241, 261, 714, 823, 2519, 2930, 3391, 3419, 3616, 3649, 4077, 6171);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(234, 0, 1, 0, "A foul corruption has crept into Westfall.  While I was upholding my duty on the battlefields of Lordaeron these honest farms were overrun and made into hide-outs for thugs and murderers. The People's Militia needs your help.", 0),
(235, 0, 0, 0, "Welcome to our humble abode! It's always nice to see a friendly face. And what strong arms you have. My husband and I are always looking for help around the farm. Now that most the good folk have left, it's hard to find an able body to help out.", 0),
(237, 0, 0, 0, "Nothing but trouble in these parts.  I tried to tell that fool Saldean to get out while he still could but he won't hear of it.  But I ain't no fool.  Verna and I are gonna mosey on out as soon as we get this wagon fixed.", 0),
(238, 0, 0, 0, "Sometimes I think there's a big gray cloud in the sky, just raining down bad luck upon us. First, we're driven off our land, and now we can't even get out of Westfall. Everything's a mess. Something needs to be done.", 0),
(241, 0, 0, 0, "Hey there, friend.  My name's Remy.$BI'm from Redridge to the east, and came here looking for business, looking for business.  You got any...got any??", 0),
(261, 0, 0, 0, "Hello, citizen.  You look like a $g man : woman; with a purpose - do you have business with the Stormwind Army?", 0),
(714, 0, 0, 0, "Greetings, $c! Fine day for hunting, wouldn't you say? I've been having more than a little luck with boars, myself. Perhaps you'd like a shot?", 0),
(823, 0, 1, 0, "Hello there, $c.  Normally I'd be out on the beat looking after the folk of Stormwind, but a lot of the Stormwind guards are fighting in the other lands.  So here I am, deputized and offering bounties when I'd rather be on patrol...", 0),
(2519, 0, 0, 0, "Hello! The spirits say you here to aid my chief. Say it loud, they do.", 0),
(2930, 0, 0, 0, "Corruption sneaks into nature's grove. The forest must be protected at all costs.", 0),
(3391, 0, 0, 0, "Thrall paid me and my boys well for helping out with the construction of Orgrimmar, so I decided to set up a port here. We do most of our business through Booty Bay and Baron Revilgaz.", 0),
(3419, 0, 1, 0, "For our people to survive, we must study the ways of nature and learn its secrets.", 0),
(3616, 0, 0, 0, "The wind whispers to those who listen...$B$BDo you hear it?", 0),
(3649, 0, 1, 0, "Dark forces encroach upon our borders, ancient taints resurface, and new evils emerge to topple the delicate balance of the land. In times of such darkness, we all must be vigilant.", 0),
(4077, 0, 0, 0, "If I can get the proper ingredients, we can create some explosives that will not only allow me to damage the Venture's Co.'s operations, but also cause a distraction.$B$BI know you're impressed, but it gets better... I'll tell you more soon enough.", 0),
(6171, 0, 1, 0, "You will be tested many times by the darkness that surrounds our lands, $N. But to ensure you are always prepared, we will often ask tasks of you so you are at the height of your own power.$B$BGo with the Light, and remain virtuous.", 0);
