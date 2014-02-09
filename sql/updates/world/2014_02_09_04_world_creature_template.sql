-- set trigger flag for NPC_JEDOGA_CONTROLLER
UPDATE `creature_template` SET `flags_extra` = `flags_extra`|128 WHERE `entry` = 30181;
