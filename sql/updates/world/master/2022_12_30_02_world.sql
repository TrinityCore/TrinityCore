-- Update SMART_ACTION_JUMP_TO_POS
UPDATE `smart_scripts` SET `target_type`=8 WHERE `action_type`=97 AND `target_type`=1 AND `target_x`!=0;
