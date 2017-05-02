SET @TemplateId := 2475;
DELETE FROM `creature_equip_template` WHERE `entry` BETWEEN 2475 AND 2477;
INSERT INTO `creature_equip_template` VALUES
(@TemplateId, 44244, 0, 0), -- Argent Lightwielder
(@TemplateId+1, 18608, 0, 0), -- Argent Priestess
(@TemplateId+2, 40343, 0, 0); -- The Black Knight

SET @NPC_LIGHTWIELDER   := 35309;
SET @NPC_PRIESTESS      := 35307;
SET @NPC_BLACK_KNIGHT   := 35451;
SET @NPC_LIGHTWIELDER_H := (SELECT `difficulty_entry_1` FROM `creature_template` WHERE `entry` = @NPC_LIGHTWIELDER);
SET @NPC_PRIESTESS_H := (SELECT `difficulty_entry_1` FROM `creature_template` WHERE `entry` = @NPC_PRIESTESS);
SET @NPC_BLACK_KNIGHT_H := (SELECT `difficulty_entry_1` FROM `creature_template` WHERE `entry` = @NPC_BLACK_KNIGHT);

UPDATE `creature_template` SET `equipment_id` = @TemplateId WHERE `entry` IN (@NPC_LIGHTWIELDER, @NPC_LIGHTWIELDER_H);
UPDATE `creature_template` SET `equipment_id` = @TemplateId+1 WHERE `entry` IN (@NPC_PRIESTESS, @NPC_PRIESTESS_H);
UPDATE `creature_template` SET `equipment_id` = @TemplateId+2 WHERE `entry` IN (@NPC_BLACK_KNIGHT, @NPC_BLACK_KNIGHT_H);