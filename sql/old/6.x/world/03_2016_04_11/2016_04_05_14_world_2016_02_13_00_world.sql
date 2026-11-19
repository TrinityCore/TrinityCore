SET @ENTRY:=23258;
SET @AURA:=40670;
DELETE FROM `creature_template_addon` WHERE `entry` = @ENTRY;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES (@ENTRY, @AURA);
