-- Move boss_lord_valthalak from EAI to CPP
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'boss_lord_valthalak' WHERE `entry`=16042;
-- DELETE FROM creature_ai_scripts WHERE `creature_id`=16042; 4.x removed
DELETE FROM `creature_text` WHERE `entry`=16042 AND `groupid`=0;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(16042, 0, 0, '%s goes into a frenzy!', 16, 0, 100, 0, 0, 0, 'Lord Valthalak - Cast Frenzy');
