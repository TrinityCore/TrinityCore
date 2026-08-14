-- Correct spells order for Broken-down Shredder
DELETE FROM `creature_template_spell` WHERE `CreatureID` = 27354 AND `Index` IN (0,1,2);
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES
(27354, 0, 48548, 54847),
(27354, 1, 48558, 54847),
(27354, 2, 48604, 54847);
UPDATE `creature_template_spell` SET `VerifiedBuild`=54847 WHERE `CreatureID`=27354 AND `Spell`=48610 AND `Index`=4;
