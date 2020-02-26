--
SET @GUID := 8981;
DELETE FROM `gameobject` WHERE `guid`=@GUID AND `id`=182531;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID, 182531, 571, 0, 0, 1, 1, 4413.98, 5368.06, -15.5602, 3.92534, -0, -0, -0.924195, 0.381922, 300, 100, 1, "", 0);

UPDATE `creature` SET `position_x`=4414.223, `position_y`=5367.299, `position_z`=-15.49403, `orientation`=0.3665192, `spawntimesecs`=300 WHERE `id`=25589;

DELETE FROM `creature_text` WHERE `CreatureID`=25589;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25589, 0, 0, "Um, hello? Is there anyone out there?", 12, 7, 100, 0, 0, 0, 24763, 0, "Bonker Togglevolt"),
(25589, 0, 1, "Hey, you! Yes, you! I can hear you! Get over here and get me outa here!", 12, 7, 100, 0, 0, 0, 24764, 0, "Bonker Togglevolt"),
(25589, 0, 2, "I'm beginning to think that they all forgot about me!", 12, 7, 100, 0, 0, 0, 24765, 0, "Bonker Togglevolt"),
(25589, 0, 3, "A gnome tries to make some friends, and then BAMM... the next thing you know, he's in shackles!", 12, 7, 100, 0, 0, 0, 24766, 0, "Bonker Togglevolt"),
(25589, 0, 4, "I'm right here. I know you can hear me. Ya think you could let me out of these chains?", 12, 7, 100, 0, 0, 0, 24767, 0, "Bonker Togglevolt"),
(25589, 0, 5, "I'll make you a deal: if you get me out of here alive, you'll get a reward larger than you can imagine!", 12, 7, 100, 0, 0, 0, 24768, 0, "Bonker Togglevolt"),
(25589, 0, 6, "Hey! Over here in Magmothregar's pit!", 12, 7, 100, 0, 0, 0, 24769, 0, "Bonker Togglevolt"),
(25589, 0, 7, "What? You think I want to be Magmothregar's next appetizer? Get me outa here!", 12, 7, 100, 0, 0, 0, 24770, 0, "Bonker Togglevolt"),
(25589, 1, 0, "Right then, no time to waste. Let's get outa here!", 12, 7, 100, 1, 0, 0, 24772, 0, "Bonker Togglevolt"),
(25589, 2, 0, "Here we go.", 12, 7, 100, 0, 0, 0, 24773, 0, "Bonker Togglevolt"),
(25589, 3, 0, "I think it's up this way to the left.  Let's go!", 12, 7, 100, 0, 0, 0, 24776, 0, "Bonker Togglevolt"),
(25589, 4, 0, "Ah, fresh air! I can get myself back to the airstrip from here. Be sure to tell Fizzcrank I'm back and safe. Thanks so much, $n!", 12, 7, 100, 0, 0, 0, 24774, 0, "Bonker Togglevolt"),
(25589, 5, 0, "Filthy creature!", 12, 7, 100, 0, 0, 0, 24777, 0, "Bonker Togglevolt"),
(25589, 5, 1, "I came here to talk, but you mindless things tried to kill me instead!", 12, 7, 100, 0, 0, 0, 24778, 0, "Bonker Togglevolt"),
(25589, 5, 2, "You won't put me in chains again!", 12, 7, 100, 0, 0, 0, 24779, 0, "Bonker Togglevolt"),
(25589, 5, 3, "I AM NOT AN APPETIZER!", 12, 7, 100, 0, 0, 0, 24780, 0, "Bonker Togglevolt"),
(25589, 5, 4, "The only good vermen is a dead vermen!", 12, 7, 100, 0, 0, 0, 24781, 0, "Bonker Togglevolt"),
(25589, 5, 5, "Enough fighting! Let's finish this and get outa here!", 12, 7, 100, 0, 0, 0, 24782, 0, "Bonker Togglevolt"),
(25589, 5, 6, "Hey! I'm walking here!", 12, 7, 100, 0, 0, 0, 24783, 0, "Bonker Togglevolt"),
(25589, 5, 7, "I can't believe my own people forgot about me. Die!", 12, 7, 100, 0, 0, 0, 24784, 0, "Bonker Togglevolt");

UPDATE `script_waypoint` SET `waittime`=0 WHERE `entry`=25589 AND `pointid` IN (2, 22);
UPDATE `script_waypoint` SET `waittime`=3000 WHERE `entry`=25589 AND `pointid`=29;
