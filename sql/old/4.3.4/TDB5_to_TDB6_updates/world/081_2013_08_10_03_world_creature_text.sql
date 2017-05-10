SET @NPC := 7271;
-- Move boss_zum_rah from SAI to CPP
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'boss_zum_rah' WHERE `entry`=@NPC;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC;
DELETE FROM `creature_text` WHERE `entry` =@NPC;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@NPC, 0, 0, 'How dare you enter my sanctum!', 12, 0, 100, 0, 0, 0, 'Witch Doctor Zum''rah'),
(@NPC, 1, 1, 'T''eif godehsi wha!', 14, 14, 100, 0, 0, 0, 'Witch Doctor Zum''rah'),
(@NPC, 2, 2, 'Sands consume you!', 14, 0, 100, 0, 0, 0, 'Witch Doctor Zum''rah'),
(@NPC, 2, 3, 'Fall!', 14, 0, 100, 0, 0, 0, 'Witch Doctor Zum''rah');
