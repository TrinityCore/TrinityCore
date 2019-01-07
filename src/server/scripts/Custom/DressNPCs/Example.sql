SET @NPCENTRY := 6;

REPLACE INTO `creature_template_outfits` (`entry`, `race`, `gender`, `skin`, `face`, `hair`, `haircolor`, `facialhair`, `head`, `shoulders`, `body`, `chest`, `waist`, `legs`, `feet`, `wrists`, `hands`, `back`, `tabard`)
VALUES (3000000123, 11, 1, 14, 4, 10, 3, 5, -31286, -43617, 0, -26267, -26270, -26272, 0, 0, -43698, 0, 0);
REPLACE INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES (6, 1, 3000000123, 1, 1, 0);
