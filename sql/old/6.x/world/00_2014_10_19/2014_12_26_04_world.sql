UPDATE `creature_text` SET `TextRange` = 3 WHERE `entry` = 27656 AND `groupid` = 0;
DELETE FROM `creature_text` WHERE `entry` = 27447 AND `groupid` = 4;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `TextRange`, `comment`) VALUES
(27447, 4, 0, 'Intruders, your victory will be short-lived. I am Commander Varos Cloudstrider. My drakes control the skies and protect this conduit. I will see to it personally that the Oculus does not fall into your hands!', 14, 0, 100, 0, 0, 13648, 31812, 3, 'Varos Cloudstrider SAY_VAROS_INTRO_TEXT');
