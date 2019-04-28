SET @NPCENTRY := 6;

INSERT INTO `creature_template_outfits` (`entry`, `race`, `gender`, `skin`, `face`, `hair`, `haircolor`, `facialhair`, `head`, `shoulders`, `body`, `chest`, `waist`, `legs`, `feet`, `wrists`, `hands`, `back`, `tabard`)
VALUES (3000000123, 11, 1, 14, 4, 10, 3, 5, -31286, -43617, 0, -26267, -26270, -26272, 0, 0, -43698, 0, 0);
UPDATE `creature_template` SET `modelid2` = 3000000123 WHERE `entry` = @NPCENTRY;
