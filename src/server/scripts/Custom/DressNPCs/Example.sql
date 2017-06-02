SET @NPCENTRY := 6;

REPLACE INTO `creature_template_outfits` (`entry`, `race`, `gender`, `skin`, `face`, `hair`, `haircolor`, `facialhair`, `head`, `shoulders`, `body`, `chest`, `waist`, `legs`, `feet`, `wrists`, `hands`, `back`, `tabard`)
VALUES (123, 11, 1, 14, 4, 10, 3, 5, -31286, -43617, 0, -26267, -26270, -26272, 0, 0, -43698, 0, 0);
-- INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`)
-- VALUES (@NPCENTRY, 2, 32946, 32945, 0);
UPDATE `creature_template` SET `modelid2` = -123 WHERE `entry` = @NPCENTRY;
