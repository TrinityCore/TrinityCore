--
UPDATE `smart_scripts` SET `entryorguid`= -69714 WHERE `entryorguid`= -69712;
UPDATE `smart_scripts` SET `entryorguid`= -69715 WHERE `entryorguid`= -69711;
UPDATE `smart_scripts` SET `entryorguid`= -69716 WHERE `entryorguid`= -69710;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-69712, -69711, -69710);
 
DELETE FROM `creature_addon` WHERE `guid` IN (69713);
INSERT INTO `creature_addon` (`guid`,`bytes1`,`bytes2`, `emote`, `auras`) VALUES
(69713,0,4097,0,"37497");
 
UPDATE `creature_template_addon` SET `auras`= "37467" WHERE `entry`=21292;
