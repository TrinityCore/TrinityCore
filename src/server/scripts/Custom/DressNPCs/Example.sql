SET @NPCENTRY := 6;

REPLACE INTO `creature_template_outfits` (`entry`, `race`, `class`, `gender`, `customizations`, `head`, `shoulders`, `body`, `chest`, `waist`, `legs`, `feet`, `wrists`, `hands`, `back`, `tabard`)
VALUES (3000000123, 11, 1, 1, '133 1951 134 1966 135 1993 136 2003 137 2015 619 6978 689 7706 697 7764 699 7791 701 7796 778 8642', -31286, -43617, 0, -26267, -26270, -26272, 0, 0, -43698, 0, 0);
REPLACE INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES (6, 1, 3000000123, 1, 1, 0);
