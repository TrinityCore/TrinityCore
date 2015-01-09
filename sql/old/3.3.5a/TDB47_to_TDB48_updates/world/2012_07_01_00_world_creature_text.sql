DELETE FROM `script_texts` WHERE entry IN (-1534019, -1534020, -1534021, -1534022, -1534023, -1534024, -1534025, -1534026, -1534027, -1534028, -1534029 , -1534030);

-- Anetheron
DELETE FROM `creature_text` WHERE `entry`=17808;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17808,0,0, 'The clock... is still... ticking.',14,0,100,0,0,10982, 'Anetheron - SAY_ONDEATH'),
(17808,1,0, 'Your hopes are lost!',14,0,100,0,0,10981, 'Anetheron - SAY_ONSLAY1'),
(17808,1,1, 'Scream for me!',14,0,100,0,0,11038, 'Anetheron - SAY_ONSLAY2'),
(17808,1,2, 'Pity, no time for a slow death!',14,0,100,0,0,11039, 'Anetheron - SAY_ONSLAY3'),
(17808,2,0, 'The swarm is eager to feed!',14,0,100,0,0,10979, 'Anetheron - SAY_SWARM1'),
(17808,2,1, 'Pestilence upon you!',14,0,100,0,0,11037, 'Anetheron - SAY_SWARM2'),
(17808,3,0, 'You look tired...',14,0,100,0,0,10978, 'Anetheron - SAY_SLEEP1'),
(17808,3,1, 'Sweet dreams...',14,0,100,0,0,11545, 'Anetheron - SAY_SLEEP2'),
(17808,4,0, 'Let fire rain from above!',14,0,100,0,0,10980, 'Anetheron - SAY_INFERNO1'),
(17808,4,1, 'Earth and sky shall burn!',14,0,100,0,0,11036, 'Anetheron - SAY_INFERNO2'),
(17808,5,0, 'You are defenders of a doomed world! Flee here, and perhaps you will prolong your pathetic lives!',14,0,100,0,0,10977, 'Anetheron - SAY_ONAGGRO');

-- Azgalor
DELETE FROM `creature_text` WHERE `entry`=17842;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17842,0,0, 'Your time is almost... up',14,0,100,0,0,11002, 'Azgalor - SAY_ONDEATH'),
(17842,1,0, 'Reesh, hokta!',14,0,100,0,0,11001, 'Azgalor - SAY_ONSLAY1'),
(17842,1,1, 'Don''t fight it',14,0,100,0,0,11048, 'Azgalor - SAY_ONSLAY2'),
(17842,1,2, 'No one is going to save you',14,0,100,0,0,11047, 'Azgalor - SAY_ONSLAY3'),
(17842,2,0, 'Just a taste... of what awaits you',14,0,100,0,0,11046, 'Azgalor - SAY_DOOM1'),
(17842,2,1, 'Suffer you despicable insect!',14,0,100,0,0,11000, 'Azgalor - SAY_DOOM2'),
(17842,3,0, 'Abandon all hope! The legion has returned to finish what was begun so many years ago. This time there will be no escape!',14,0,100,0,0,10999, 'Azgalor - SAY_ONAGGRO');

-- Kazrogal
DELETE FROM `creature_text` WHERE `entry`=17888;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17888,0,0, 'Shaza-Kiel!',14,0,100,0,0,11017, 'Kazrogal - SAY_ONSLAY1'),
(17888,0,1, 'You... are nothing!',14,0,100,0,0,11053, 'Kazrogal - SAY_ONSLAY2'),
(17888,0,2, 'Miserable nuisance!',14,0,100,0,0,11054, 'Kazrogal - SAY_ONSLAY3'),
(17888,1,0, 'Your death will be a painful one.',14,0,100,0,0,11016, 'Kazrogal - SAY_MARK1'),
(17888,1,1, 'You... are marked.',14,0,100,0,0,11052, 'Kazrogal - SAY_MARK2'),
(17888,2,0, 'Cry for mercy! Your meaningless lives will soon be forfeit.',14,0,100,0,0,11015, 'Kazrogal - SAY_ONAGGRO');

-- Rage Winterchill
DELETE FROM `creature_text` WHERE `entry`=17767;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17767,0,0, 'You have won this battle, but not... the... war',14,0,100,0,0,11026, 'Rage Winterchill - SAY_ONDEATH'),
(17767,1,0, 'All life must perish!',14,0,100,0,0,11025, 'Rage Winterchill - SAY_ONSLAY1'),
(17767,1,1, 'Victory to the Legion!',14,0,100,0,0,11057, 'Rage Winterchill - SAY_ONSLAY2'),
(17767,2,0, 'Crumble and rot!',14,0,100,0,0,11023, 'Rage Winterchill - SAY_DECAY1'),
(17767,2,1, 'Ashes to ashes, dust to dust',14,0,100,0,0,11055, 'Rage Winterchill - SAY_DECAY2'),
(17767,3,0, 'Succumb to the icy chill... of death!',14,0,100,0,0,11024, 'Rage Winterchill - SAY_NOVA1'),
(17767,3,1, 'It will be much colder in your grave',14,0,100,0,0,11058, 'Rage Winterchill - SAY_NOVA2'),
(17767,4,0, 'The Legion''s final conquest has begun! Once again the subjugation of this world is within our grasp. Let none survive!',14,0,100,0,0,11022, 'Rage Winterchill - SAY_ONAGGRO');

-- Archimonde
DELETE FROM `creature_text` WHERE `entry`=17968;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17968,1,0, 'Your resistance is insignificant.',14,0,100,0,0,10987, 'Archimonde - SAY_AGGRO'),
(17968,2,0, 'This world will burn!',14,0,100,0,0,10990, 'Archimonde - SAY_DOOMFIRE1'),
(17968,2,1, 'Manach sheek-thrish!',14,0,100,0,0,11041, 'Archimonde - SAY_DOOMFIRE2'),
(17968,3,0, 'A-kreesh!',14,0,100,0,0,11041, 'Archimonde - SAY_AIR_BURST1'),
(17968,3,1, 'Away vermin!',14,0,100,0,0,10989, 'Archimonde - SAY_AIR_BURST2'),
(17968,4,0, 'All creation will be devoured!',14,0,100,0,0,11044, 'Archimonde - SAY_SLAY1'),
(17968,4,1, 'Your soul will languish for eternity.',14,0,100,0,0,10991, 'Archimonde - SAY_SLAY12'),
(17968,4,2, 'I am the coming of the end!',14,0,100,0,0,11045, 'Archimonde - SAY_SLAY3'),
(17968,5,0, 'At last it is here. Mourn and lament the passing of all you have ever known and all that would have been! Akmin-kurai!',14,0,100,0,0,10993, 'Archimonde - SAY_ENRAGE'),
(17968,6,0, 'No, it cannot be! Nooo!',14,0,100,0,0,10992, 'Archimonde - SAY_DEATH'),
(17968,7,0, 'You are mine now.',14,0,100,0,0,10988, 'Archimonde - SAY_SOUL_CHARGE1'),
(17968,7,1, 'Bow to my will.',14,0,100,0,0,11042, 'Archimonde - SAY_SOUL_CHARGE2');

