ALTER TABLE `conditions`   
  ADD COLUMN `ErrorType` MEDIUMINT(8) UNSIGNED DEFAULT 0 NOT NULL AFTER `NegativeCondition`;

/*
 * trinity_string
 * 63    - You can't do that right now.                  -> SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW = 173
 * 64    - You cannot use that item here.                -> SPELL_CUSTOM_ERROR_CANT_USE_THAT_ITEM = 56
 *                                                          SPELL_FAILED_INCORRECT_AREA = 39
 *                                                          SPELL_CUSTOM_ERROR_CANT_CALL_WINTERGARDE_HERE = 26
 *                                                          SPELL_CUSTOM_ERROR_MUST_TARGET_ICE_HEART_JORMUNGAR = 21
 *                                                          SPELL_FAILED_BAD_TARGETS = 12
 * 65    - You must reach level 58 to use this portal.   -> SPELL_CUSTOM_ERROR_REQUIRES_LEVEL_58 = 66
 * 97    - don't exist
 * 1334  - Requires Maiden of Winter's Breath Lake       -> SPELL_CUSTOM_ERROR_MUST_BE_CLOSE_TO_MAIDEN = 61
 * 1335  - You can't use that right now                  -> SPELL_FAILED_INCORRECT_AREA = 39
 *                                                          SPELL_FAILED_TARGET_AURASTATE = 111
 */

UPDATE `conditions` SET `ErrorType`=173, `ErrorTextId`=0 WHERE `ErrorType`=0 AND `ErrorTextId`=63;

UPDATE `conditions` SET `ErrorType`=172, `ErrorTextId`=26 WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=48388;
UPDATE `conditions` SET `ErrorType`= 39, `ErrorTextId`= 0 WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=43209;
UPDATE `conditions` SET `ErrorType`=172, `ErrorTextId`=21 WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=47431;
UPDATE `conditions` SET `ErrorType`= 12, `ErrorTextId`= 0 WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=34367;

UPDATE `conditions` SET `ErrorType`=172, `ErrorTextId`=66 WHERE `ErrorType`=0 AND `ErrorTextId`=65;
UPDATE `conditions` SET `ErrorType`=172, `ErrorTextId`=61 WHERE `ErrorType`=0 AND `ErrorTextId`=1334;
UPDATE `conditions` SET `ErrorType`= 39, `ErrorTextId`=0 WHERE `ErrorType`=0 AND `ErrorTextId`=1335 AND `ConditionTypeOrReference`=23;
UPDATE `conditions` SET `ErrorType`=111, `ErrorTextId`=0 WHERE `ErrorType`=0 AND `ErrorTextId`=1335 AND `ConditionTypeOrReference`=1;

UPDATE `conditions` SET `ErrorTextId`=0 WHERE `ErrorType`=0 AND `ErrorTextId`=97;
UPDATE `conditions` SET `ErrorTextId`=0 WHERE `ErrorType`=0 AND `SourceTypeOrReferenceId`=13;

DELETE FROM `trinity_string` WHERE `entry` IN (63,64,65,97,1334,1335);
