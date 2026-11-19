UPDATE `creature_template_movement` SET `InteractionPauseTimer`=NULL WHERE `InteractionPauseTimer`=0;
UPDATE `creature_template_movement` SET `Chase`=0 WHERE `Chase` IS NULL;
UPDATE `creature_template_movement` SET `Random`=0 WHERE `Random` IS NULL;
DELETE FROM `creature_template_movement` WHERE `HoverInitiallyEnabled` IS NULL AND `Chase`=0 AND `Random`=0 AND `InteractionPauseTimer` IS NULL;
